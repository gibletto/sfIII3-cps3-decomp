/*
 * VITAL.C  Vitality bars and round timers
 *
 * Draws and runs the vitality bars and the timers. vital_cont_init resets both bars to full,
 * vital_cont_main and vital_control update them each frame and vital_parts_allwrite redraws all 20
 * cells from the yellow and red levels. count_cont_init/reset/main, counter_control and
 * counter_flash run the 99-count round timer, with a tick rate from the game-speed setting and
 * flashing below 30 and 10. bcount_cont_* and bcounter_* run the 50-second bonus-stage timer and
 * count it down for the result tally. The file starts with debug_scrfont_view, a debug viewer for
 * scroll characters and palettes.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLS01.h"
#include "count.h"
#include "VITAL.h"
#include "cps3.h"
/* provisional name */
void debug_scrfont_view(void) {
    s32 i;
    s32 j;
    s32 code = 0;
    if ((p1sw_0 & 0x3F0) == 0xA0) {
        if ((~p1sw_1 & p1sw_0 & 15) == 1) {
            scrfont_view_attr = scrfont_view_attr + 2;
        }
        if ((~p1sw_1 & p1sw_0 & 15) == 2) {
            scrfont_view_attr = scrfont_view_attr - 2;
        }
        scrfont_view_attr = scrfont_view_attr & 62;
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            tilemap_put_cell(j + 8, i + 6, scrfont_view_attr, code++);
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            tilemap_put_cell(j + 24, i + 6, scrfont_view_attr, code++);
        }
    }
    tilemap_put_cell(23, 5, 42, (scrfont_view_attr >> 5) & 15);
    tilemap_put_cell(24, 5, 42, (scrfont_view_attr >> 1) & 15);
}



void vital_cont_init(void) {
    vit_bar[0].cyerw = 160;
    vit_bar[0].cred = 160;
    vit_bar[0].ored = 160;
    vit_bar[0].unused = 0;
    vit_bar[0].colnum = 0;
    vit_bar[0].cell = vital_cell_tbl;
    vit_bar[0].attr = vital_attr_tbl[0];
    vit_bar[1].cyerw = 160;
    vit_bar[1].cred = 160;
    vit_bar[1].ored = 160;
    vit_bar[1].unused = 0;
    vit_bar[1].colnum = 0;
    vit_bar[1].cell = vital_cell_tbl;
    vit_bar[1].attr = vital_attr_tbl[1];
    vit_bar[0].xpos = vital_npos_tbl[0];
    vit_bar[1].xpos = vital_npos_tbl[1];
    sc_ram_to_vram(4, 0, 0);
    sc_ram_to_vram(5, 0, 0);
    gauge_stop_flag[0] = 0;
    gauge_stop_flag[1] = 0;
    vital_stop_flag[0] = 0;
    vital_stop_flag[1] = 0;
}



void vital_cont_main(void) {
    if (!EXE_flag && !Game_pause) {
        if (vital_stop_flag[0] == 0 && ((s16)gauge_stop_flag[0]) == 0) {
            vital_control(0);
        }
        if (vital_stop_flag[1] == 0 && ((s16)gauge_stop_flag[1]) == 0) {
            vital_control(1);
        }
    }
}



/* one word of a vital bar table */
#define BAR_WORD(tbl, ix) (*(s16*)((u32)(tbl) + (ix) * 2))

s32 vital_control(s8 pl) {
    s8 i;
    if (plw[pl].wu.vital_new > 0xA0) {
        return 0;
    }
    if ((vit_bar[pl].cyerw == *(volatile s16*)&plw[pl].wu.vital_new) &&
        (vit_bar[pl].cred == *(volatile s16*)&plw[pl].wu.vital_new) &&
        (vit_bar[pl].ored != (*(volatile s16*)&plw[pl].wu.vital_new + 1))) {
        return 0;
    }
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
    vit_bar[pl].cyerw = plw[pl].wu.vital_new;
    if (plw[pl].wu.vital_new < 0) {
        vit_bar[pl].cyerw = 0;
    }
    vital_dot_pos = 0xA0;
    vital_col_ix = 0;
    if (plw[pl].wu.vital_new <= 0x9F) {
        vit_bar[pl].colnum = 1;
        if (plw[pl].wu.vital_new <= 48) {
            vit_bar[pl].colnum = 2;
        }
    } else {
        vit_bar[pl].colnum = 0;
    }
    for (i = 0; i < 20; i++) {
        vital_dot_pos -= 8;
        if (vital_dot_pos < vit_bar[pl].cred) {
            if (vital_dot_pos < vit_bar[pl].cyerw) {
                if (vital_dot_pos + 8 > vit_bar[pl].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[pl].cred + 8;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + 8 > vit_bar[pl].cyerw) {
                    vital_yel_ofs = vit_bar[pl].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = 8;
                }
                tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum),
                                 BAR_WORD(vit_bar[pl].cell, vital_yel_ofs * 9 + vital_red_ofs));
                vital_col_ix++;
                continue;
            } else {
                if (vit_bar[pl].cred >= vital_dot_pos + 8) {
                    vital_red_ofs = 0;
                } else {
                    vital_red_ofs = 8 + vital_dot_pos - vit_bar[pl].cred;
                }
                vital_yel_ofs = 0;
                tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum),
                                 BAR_WORD(vit_bar[pl].cell, vital_red_ofs));
            }
        } else {
            tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum), 0x122);
        }
        vital_col_ix++;
    }
    vit_bar[pl].ored = vit_bar[pl].cred;
    vit_bar[pl].cred--;
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
    return vit_bar[pl].cred;
}


s32 vital_parts_allwrite(s8 pl) {
    const u16* tbl;
    s8 i;
    const s16* cols;
    const s16* attrs;
    if (vit_bar[1].cyerw < 0) {
        vit_bar[1].cyerw = 0;
    }
    if (pl == 0) {
        ToneDown(3);
        tbl = vital_cell_1p_tbl;
    } else {
        tbl = vital_cell_tbl;
    }
    cols = (*(const s16 **)&(vital_npos_tbl[1]));
    attrs = (const s16*)vital_attr_tbl[2 - pl];
    vital_dot_pos = 160;
    vital_col_ix = 0;
    for (i = 0; i < 20; i++) {
        vital_dot_pos -= 8;
        if (vital_dot_pos < vit_bar[1].cred) {
            if (vit_bar[1].cyerw > vital_dot_pos) {
                if (vital_dot_pos + 8 > vit_bar[1].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[1].cred + 8;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + 8 > vit_bar[1].cyerw) {
                    vital_yel_ofs = vit_bar[1].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = 8;
                }
                tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], tbl[vital_yel_ofs * 9 + vital_red_ofs]);
                vital_col_ix++;
                continue;
            }
            if (vit_bar[1].cred >= vital_dot_pos + 8) {
                vital_red_ofs = 0;
            } else {
                vital_red_ofs = vital_dot_pos - vit_bar[1].cred + 8;
            }
            vital_yel_ofs = 0;
            tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], 0xAC);
            vital_col_ix++;
            continue;
        }
        tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], 0xAC);
        vital_col_ix++;
    }
}

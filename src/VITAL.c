/*
 * VITAL.C  Vitality bars and round timers
 *
 * Draws and runs the vitality bars and the timers. vital_cont_init resets both bars to full,
 * vital_cont_main and vital_control update them each frame and vital_parts_allwrite redraws all 20
 * cells from the yellow and red levels. count_cont_init/reset/main, counter_control and
 * counter_flash run the 99-count round timer, with a tick rate from the game-speed setting and
 * flashing below 30 and 10. bcount_cont_* and bcounter_* run the 50-second bonus-stage timer and
 * count it down for the result tally.
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

#define VITAL_FULL      160     /* full vitality (vital_new) */
#define VITAL_CELLS     20      /* tile cells in a bar */
#define VITAL_CELL_DOTS 8       /* vitality points per cell */

s16 vital_col_ix;  /* 02028638 */
s16 vital_dot_pos;  /* 0202863A */
s16 vital_red_ofs;  /* 0202863C */
s16 vital_yel_ofs;  /* 0202863E */
u16 vital_stop_flag[2];  /* 02028640 */
u16 gauge_stop_flag[2];  /* 02028644 */
/* vit_bar[pl] with pl 1 is the 2P bar, vit_bar_2p, which follows it */
VITAL_BAR vit_bar[1];  /* 02028648 */
VITAL_BAR vit_bar_2p;  /* 02028660 */


/* 020069B4 */
const u16* vital_npos_tbl[2] = {
    vital_npos_0,
    vital_npos_1,
};
/* 020069BC */
const u16* vital_attr_tbl[3] = {
    vital_attr_0,
    vital_attr_1,
    vital_attr_2,
};


void vital_cont_init(void) {
    vit_bar[0].cyerw = VITAL_FULL;
    vit_bar[0].cred = VITAL_FULL;
    vit_bar[0].ored = VITAL_FULL;
    vit_bar[0].unused = 0;
    vit_bar[0].colnum = 0;
    vit_bar[0].cell = vital_cell_tbl;
    vit_bar[0].attr = vital_attr_tbl[0];
    vit_bar_2p.cyerw = VITAL_FULL;
    vit_bar_2p.cred = VITAL_FULL;
    vit_bar_2p.ored = VITAL_FULL;
    vit_bar_2p.unused = 0;
    vit_bar_2p.colnum = 0;
    vit_bar_2p.cell = vital_cell_tbl;
    vit_bar_2p.attr = vital_attr_tbl[1];
    vit_bar[0].xpos = vital_npos_tbl[0];
    vit_bar_2p.xpos = vital_npos_tbl[1];
    sc_ram_to_vram(4, 0, 0);
    sc_ram_to_vram(5, 0, 0);
    gauge_stop_flag[0] = 0;
    gauge_stop_flag[1] = 0;
    vital_stop_flag[0] = 0;
    vital_stop_flag[1] = 0;
}



void vital_cont_main(void) {
    if (!EXE_flag && !Game_pause) {
        if (vital_stop_flag[0] == 0 && (s16)gauge_stop_flag[0] == 0) {
            vital_control(0);
        }
        if (vital_stop_flag[1] == 0 && (s16)gauge_stop_flag[1] == 0) {
            vital_control(1);
        }
    }
}



s32 vital_control(s8 pl) {
    s8 i;
    if (plw[pl].wu.vital_new > VITAL_FULL) {
        return 0;
    }
    if (vit_bar[pl].cyerw == plw[pl].wu.vital_new) {
        if (vit_bar[pl].cred == plw[pl].wu.vital_new) {
            if (vit_bar[pl].ored != plw[pl].wu.vital_new + 1) {
                return 0;
            }
        }
    }
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
    vit_bar[pl].cyerw = plw[pl].wu.vital_new;
    if (plw[pl].wu.vital_new < 0) {
        vit_bar[pl].cyerw = 0;
    }
    vital_dot_pos = VITAL_FULL;
    vital_col_ix = 0;
    if (plw[pl].wu.vital_new <= VITAL_FULL - 1) {
        vit_bar[pl].colnum = 1;
        if (plw[pl].wu.vital_new <= 48) {
            vit_bar[pl].colnum = 2;
        }
    } else {
        vit_bar[pl].colnum = 0;
    }
    for (i = 0; i < VITAL_CELLS; i = i + 1) {
        vital_dot_pos -= VITAL_CELL_DOTS;
        if (vital_dot_pos < vit_bar[pl].cred) {
            if (vit_bar[pl].cyerw > vital_dot_pos) {
                if (vital_dot_pos + VITAL_CELL_DOTS > vit_bar[pl].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[pl].cred + VITAL_CELL_DOTS;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + VITAL_CELL_DOTS > vit_bar[pl].cyerw) {
                    vital_yel_ofs = vit_bar[pl].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = VITAL_CELL_DOTS;
                }
                tilemap_put_cell((s16)vit_bar[pl].xpos[vital_col_ix], 2, vit_bar[pl].attr[vit_bar[pl].colnum],
                                 (s16)vit_bar[pl].cell[vital_yel_ofs * (VITAL_CELL_DOTS + 1) + vital_red_ofs]);
                vital_col_ix++;
                continue;
            } else {
                if (vit_bar[pl].cred >= vital_dot_pos + VITAL_CELL_DOTS) {
                    vital_red_ofs = 0;
                } else {
                    vital_red_ofs = VITAL_CELL_DOTS - (vit_bar[pl].cred - vital_dot_pos);
                }
                vital_yel_ofs = 0;
                tilemap_put_cell((s16)vit_bar[pl].xpos[vital_col_ix], 2, vit_bar[pl].attr[vit_bar[pl].colnum],
                                 (s16)vit_bar[pl].cell[vital_red_ofs]);
            }
        } else {
            tilemap_put_cell((s16)vit_bar[pl].xpos[vital_col_ix], 2, vit_bar[pl].attr[vit_bar[pl].colnum], 0x122);
        }
        vital_col_ix++;
    }
    vit_bar[pl].ored = vit_bar[pl].cred;
    vit_bar[pl].cred--;
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
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
    cols = (const s16*)vital_npos_tbl[1];
    attrs = (const s16*)vital_attr_tbl[2 - pl];
    vital_dot_pos = VITAL_FULL;
    vital_col_ix = 0;
    for (i = 0; i < VITAL_CELLS; i++) {
        vital_dot_pos -= VITAL_CELL_DOTS;
        if (vital_dot_pos < vit_bar[1].cred) {
            if (vit_bar[1].cyerw > vital_dot_pos) {
                if (vital_dot_pos + VITAL_CELL_DOTS > vit_bar[1].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[1].cred + VITAL_CELL_DOTS;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + VITAL_CELL_DOTS > vit_bar[1].cyerw) {
                    vital_yel_ofs = vit_bar[1].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = VITAL_CELL_DOTS;
                }
                tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], tbl[vital_yel_ofs * (VITAL_CELL_DOTS + 1) + vital_red_ofs]);
                vital_col_ix++;
                continue;
            }
            if (vit_bar[1].cred >= vital_dot_pos + VITAL_CELL_DOTS) {
                vital_red_ofs = 0;
            } else {
                vital_red_ofs = VITAL_CELL_DOTS - (vit_bar[1].cred - vital_dot_pos);
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

/*
 * VITAL_2.C  Vitality bars and round timers (part 2)
 *
 * Routines: vital_parts_allwrite, count_cont_init, count_cont_reset.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLS01.h"
#include "vital_2.h"
#include "cps3.h"



s32 vital_parts_allwrite(s8 pl) {
    const u16* tbl;
    const s16* cols;
    const s16* attrs;
    s8 i;
    u16 code;
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
        if (vital_dot_pos >= vit_bar[1].cred) {
            code = 0xAC;
        } else if (vit_bar[1].cyerw > vital_dot_pos) {
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
            code = tbl[vital_yel_ofs * 9 + vital_red_ofs];
        } else {
            if (vit_bar[1].cred >= vital_dot_pos + 8) {
                vital_red_ofs = 0;
            } else {
                vital_red_ofs = vital_dot_pos - vit_bar[1].cred + 8;
            }
            vital_yel_ofs = 0;
            code = 0xAC;
        }
        tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], code);
        vital_col_ix++;
    }
    return i;
}



void count_cont_init(pl)
s8 pl;
{
    count_work.hoji_counter = hoji_counter_tbl[Game_setting.set3];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[Game_setting.set3];
    round_timer.half.h = Counter_hi;
    count_digit_trans(pl, 9, 9);
    if (pl == 0) {
        sc_ram_to_vram(2, 0, 0);
        sc_ram_to_vram(3, 0, 0);
    }
    round_timer.timer = 0x630000;
    Timer_Freeze = 0;
    flash_r_num = 0;
    flash_col = 0;
}



/* provisional name */
void count_cont_reset(void) {
    count_work.hoji_counter = hoji_counter_tbl[(*&Game_setting).set3];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[(*&Game_setting).set3];
    round_timer.half.h = Counter_hi;
    flash_r_num = 0;
    flash_col = 0;
    count_digit_trans(0, 9, 9);
    sc_ram_to_vram(2, 0, 0);
    sc_ram_to_vram(3, 0, 0);
}

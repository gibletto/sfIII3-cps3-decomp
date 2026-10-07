/*
 * EFF95.C  Effect 95: continue screen character
 *
 * Effect 95 is created by effect_95_init from Win for the continue screen, positioned on BG1 and
 * tied to the loser's continue count.
 * effect_95_move changes its pose as the countdown runs (Continue_Count, Continue_Count_Down),
 * reacts to a coin being inserted (Check_Coin_In) or the countdown being cut, and plays its final
 * animation when the continue runs out.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff95.h"



void effect_95_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!Continue_Count_Down[LOSER]) {
            ewk->wu.routine_no[0]++;
        }
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (Check_Coin_In(Loser_id)) {
            ewk->wu.old_rno[5] = 6;
            ewk->wu.old_rno[6] = 6;
            ewk->wu.dir_step = 9;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        } else if (ewk->wu.dmcal_m != (Continue_Count[LOSER])) {
            if (!(ewk->wu.dmcal_m = Continue_Count[LOSER])) {
                if (Continue_Cut[Loser_id]) {
                    ewk->wu.routine_no[0] = 3;
                    ewk->wu.dir_step = 0;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                } else {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.old_rno[6] = 6;
                    ewk->wu.dir_step = 9;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }
            } else if (Continue_Count[LOSER] < 0) {
                ewk->wu.routine_no[0] = 3;
                ewk->wu.dir_step = 0;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            } else {
                ewk->wu.old_rno[5] = 6;
                ewk->wu.old_rno[6] = 6;
                ewk->wu.dir_step = 9;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
        } else {
            switch (ewk->wu.vital_new) {
            case 4:
                ewk->wu.old_rno[5] = ewk->wu.old_rno[5] - 1;
                if (ewk->wu.old_rno[5] <= 0) {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.dir_step = ewk->wu.dir_step - 1;
                    if (ewk->wu.dir_step <= 0) {
                        ewk->wu.dir_step = 0;
                    }
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }
                break;
            case 8:
                ewk->wu.old_rno[6] = ewk->wu.old_rno[6] - 1;
                if (ewk->wu.old_rno[6] <= 0) {
                    ewk->wu.old_rno[6] = 6;
                }
                RND_95 = (random_16_com() >> 1) & 3;
                ewk->wu.dir_step = eff95_data_tbl[ewk->wu.old_rno[6]][RND_95];
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;
            default:
                RND_95 = (random_16_com() >> 1) & 7;
                RND_95 = RND_95 + 3;
                if (RND_95 > 9) {
                    RND_95 = 0;
                }
                ewk->wu.dir_step = RND_95;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;
            }
        }
        if (Break_Into) {
            ewk->wu.routine_no[0] = 2;
        }
        break;
    case 2:
        break;
    case 3:
        if (Ck_Range_Out_S(ewk, 1, 64)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_95_init(s16 kind) {
    WORK_Other* ewk;
    s16 ix;
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 95;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.direction = 3;
    ewk->wu.vital_new = kind;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 85;
    ewk->wu.dmcal_m = Continue_Count[LOSER];
    ewk->wu.xyz[1].disp.pos = ((BGW*)((u8*)bg_w.bgw + 0x90))->wxy[1].disp.pos + 0x98;
    ewk->wu.position_z = 15;
    switch (kind) {
    case 1:
        ewk->wu.xyz[0].disp.pos = ((BGW*)((u8*)bg_w.bgw + 0x90))->wxy[0].disp.pos + 0x252;
        break;
    case 2:
        ewk->wu.xyz[0].disp.pos = ((BGW*)((u8*)bg_w.bgw + 0x90))->wxy[0].disp.pos + 0x23A;
        break;
    case 8:
        ewk->wu.old_rno[6] = 6;
        ewk->wu.xyz[0].disp.pos = ((BGW*)((u8*)bg_w.bgw + 0x90))->wxy[0].disp.pos + 0x21A;
        break;
    case 4:
        END_OF_95 = 10;
        ewk->wu.old_rno[5] = 6;
        ewk->wu.xyz[0].disp.pos = ((BGW*)((u8*)bg_w.bgw + 0x90))->wxy[0].disp.pos + 0x202;
        break;
    default:
        break;
    }
    ewk->wu.dir_step = 9;
    return 0;
}

/*
 * EFFI0.C  Effect I0: small stone debris (move)
 *
 * Each I0 work is one piece of stone kicked up from the floor. effect_I0_move picks one of eight
 * stone patterns (char_of_koishi) at random, flies the piece up under gravity, and when it falls
 * back to its landing height plays the landing part of its pattern and frees itself when the
 * pattern ends. The spawning routines, effect_I0_init and effI0_piece_set, are in EFFI3.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFI0.h"



void effect_I0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        set_char_move_init(&ewk->wu, 0, char_of_koishi[random_16_com() & 7]);
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.mvxy.a[1].sp <= 0) {
                    ewk->wu.routine_no[1]++;
                }
                char_move(&ewk->wu);
                break;
            case 1:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
                    ewk->wu.routine_no[1]++;
                    char_move_wca(&ewk->wu);
                    break;
                }
            default:
                char_move(&ewk->wu);
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

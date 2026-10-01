/*
 * EFFB1.C  Effect B1: bonus-stage result marks (move)
 *
 * Effect B1 is the row of marks shown during the blocking bonus stage; each mark counts one
 * success recorded in Bonus_Game_result. effect_B1_move first builds the row one connected
 * sprite every three frames with sound 167, then follows Bonus_Game_result: new successes play
 * their appear animation (effB1_mark_change, timed by effB1_wait_table) and lost ones play the
 * exchange animation back (effB1_mark_exchange, effB1_wait_tbl_2). The row is drawn with
 * effB1_trans and is freed when the work dies or Suicide[0] is set. The init is in EFFB1_INIT.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "EFFB1.h"



void effect_B1_move(WORK_Other_CONN* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.position_z = ewk->wu.my_priority = 67;
            ewk->wu.next_z = 9;
            ewk->wu.direction = ewk->num_of_conn;
            ewk->num_of_conn = 0;
            ewk->wu.dir_timer = 0;
            ewk->wu.dir_step = Bonus_Game_result;
            break;
        case 1:
            if (--ewk->wu.dir_timer > 0) {
                break;
            }
            sound_effect_request[167](ewk, 167);
            ewk->wu.dir_timer = 3;
            ewk->num_of_conn++;
            if (ewk->num_of_conn >= ewk->wu.direction) {
                ewk->wu.routine_no[0] = 1;
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        effB1_trans(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (ewk->wu.dir_step > Bonus_Game_result) {
            ewk->wu.routine_no[1] = 1;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (Bonus_Game_result != 0) {
                for (i = 0; i < Bonus_Game_result; i++) {
                    if (!ewk->conn[i + 20].nx) {
                        ewk->conn[i + 20].nx = 1;
                    }
                }
                effB1_mark_change(ewk);
            }
            break;
        default:
            if (ewk->wu.dir_step != Bonus_Game_result) {
                for (i = Bonus_Game_result; i < ewk->wu.dir_step; i++) {
                    if (ewk->conn[i + 20].nx != 2) {
                        ewk->conn[i + 20].nx = 2;
                        ewk->conn[i + 20].ny = 0;
                    }
                }
            }
            effB1_mark_exchange(ewk);
            break;
        }
        ewk->wu.dir_step = Bonus_Game_result;
        effB1_trans(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effB1_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    if (ewk->position_z == ewk->next_z) {
        ewk->position_z = ewk->my_priority;
    } else {
        ewk->position_z = ewk->next_z;
    }
    sort_push_request3(ewk);
}



void effB1_mark_change(WORK_Other_CONN* ewk) {
    s16 i;
    for (i = 0; i < Bonus_Game_result; i++) {
        switch (ewk->conn[i + 20].ny) {
        default:
            if (--ewk->conn[i + 20].col > 0) {
                break;
            }
        case 0:
            ewk->conn[i + 20].col = effB1_wait_table[ewk->conn[i + 20].ny];
            ewk->conn[i + 20].ny++;
            ewk->conn[i].chr++;
            break;
        case 4:
            break;
        }
    }
}


void effB1_mark_exchange(WORK_Other_CONN* ewk) {
    s32 i;
    for (i = 0; i < ewk->wu.direction; i++) {
        if (ewk->conn[i + 20].nx == 0 || ewk->conn[i + 20].nx == 1) {
            continue;
        }
        switch (ewk->conn[i + 20].ny) {
        default:
            if (--ewk->conn[i + 20].col > 0) {
                break;
            }
        case 0:
            ewk->conn[i + 20].col = effB1_wait_tbl_2[ewk->conn[i + 20].ny];
            ewk->conn[i + 20].ny++;
            ewk->conn[i].chr--;
            break;
        case 4:
            break;
        }
    }
}

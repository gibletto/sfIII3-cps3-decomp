/*
 * EFFH0.C  Effect H0: bonus-stage level display
 *
 * effect_H0_init is called by the bonus-stage controller (BBBSCOM.c) and creates a two-sprite
 * connected display from bbbs_nando_small, chosen by the player's facing. effect_H0_move sets the
 * digit sprite from Bonus_Stage_Level, waits 60 frames, then shows the display fixed to the BG1
 * screen position (effH0_trans, queued with sort_push_request3) until the work is killed.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "EFFH0.h"

void effH0_trans(WORK* ewk);



void effect_H0_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_cgnum = 0;
            ewk->wu.dir_timer = 60;
            ewk->wu.position_z = ewk->wu.my_priority = 9;
            ewk->conn[0].chr = (Bonus_Stage_Level % 10) + 45874;
            break;
        case 1:
            if (--ewk->wu.dir_timer <= 0) {
                ewk->wu.disp_flag = 1;
                ewk->wu.routine_no[0] = 1;
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        effH0_trans(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        effH0_trans(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back((WORK_Other*)ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effH0_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}



s32 effect_H0_init(WORK* wk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 170;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = wk->rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 92;
    ewk->num_of_conn = 2;
    if (wk->rl_flag) {
        ix = 1;
    } else {
        ix = 0;
    }
    ewk->conn[0] = bbbs_nando_small[ix][0];
    ewk->conn[1] = bbbs_nando_small[ix][1];
    return 0;
}

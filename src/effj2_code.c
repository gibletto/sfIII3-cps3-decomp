/*
 * EFFJ2_CODE.C  Effect J2: bonus-stage level plate
 *
 * Effect J2 is the bonus-stage level plate: effect_J2_init (from Game_Main.c) builds a two-part
 * connected sprite (id 192) from bbbs_nando_large; after its delay it shows its connected sprites
 * with the digit for Bonus_Stage_Level fixed to the BG1 screen position (effJ2_trans) for 60
 * frames, and disappears early on a break-in (Break_Into).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effj2_code.h"



void effect_J2_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_cgnum = 0;
        }
        if (--ewk->wu.dir_timer > 0) {
            break;
        }
        ewk->wu.routine_no[0] = 1;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = 0;
        ewk->wu.dir_timer = 60;
        ewk->wu.position_z = ewk->wu.my_priority = 27;
        ewk->conn[0].chr += Bonus_Stage_Level % 10;
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            goto end;
        }
        if (Break_Into) {
            goto end;
        }
        if (--ewk->wu.dir_timer <= 0) {
        end:
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        effJ2_trans(&ewk->wu);
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



/* provisional name */
void effJ2_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}


s32 effect_J2_init(s16 delay) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 192;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 92;
    ewk->wu.dir_timer = delay;
    ewk->num_of_conn = 2;
    ewk->conn[0] = bbbs_nando_large[0];
    ewk->conn[1] = bbbs_nando_large[1];
    return 0;
}

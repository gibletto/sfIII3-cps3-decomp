/*
 * EFF71.C  Effect 71: timer for an occasional stage animation (bg040)
 *
 * effect_71_init creates the controller. effect_71_move waits a
 * random time from eff71_time_tbl, creates the two effect 72 parts and then starts waiting
 * again.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFF72.h"
#include "EFFECT.h"
#include "ta_sub.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFF71.h"



void effect_71_move(WORK_Other* ewk) {
    s16 work;
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 1;
                ewk->wu.old_rno[1] = 0;
                effect_72_init(ewk, 0);
                effect_72_init(ewk, 1);
            }
        }
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[1] = 0;
            work = random_16_com();
            work &= 7;
            ewk->wu.old_rno[0] = eff71_time_tbl[work];
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_71_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if (EXE_obroll) {
        return;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 71;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.disp_flag = 0;
    ewk->wu.old_rno[0] = 0;
    return 0;
}

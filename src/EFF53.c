/*
 * EFF53.C  Effect 53: blinking stage object (bg040)
 *
 * effect_53_init creates the controller and its two effect 54 parts. effect_53_move waits a
 * random time from eff53_vanish_time, then blinks the object on and off every 30 frames six
 * times before hiding it again.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFF54.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "ta_sub.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFF53.h"



void effect_53_move(WORK_Other* ewk) {
    s32 k;
    if (!obr_disp_off_check() && !EXE_flag && !Game_pause && EXE_obroll) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.old_rno[2]--;
            if (ewk->wu.old_rno[2] <= 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 30;
                ewk->wu.old_rno[1] = 0;
                ewk->wu.disp_flag = 1;
            }
            break;
        case 1:
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.disp_flag ^= 1;
                ewk->wu.old_rno[0] = 30;
                if (!ewk->wu.disp_flag) {
                    ewk->wu.old_rno[1]++;
                    if (ewk->wu.old_rno[1] >= 6) {
                        ewk->wu.routine_no[0] = 0;
                        k = random_16_com();
                        ewk->wu.old_rno[2] = eff53_vanish_time[(s16)(k & 7)];
                        ewk->wu.disp_flag = 0;
                    }
                }
            }
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
        }
    }
}



s32 effect_53_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 53;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.old_rno[2] = 0;
    effect_54_init(ewk);
    return 0;
}

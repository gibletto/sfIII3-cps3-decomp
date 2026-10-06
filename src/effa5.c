/*
 * EFFA5.C  Effect A5: select timer
 *
 * Effect A5 (effect_A5_entry, started by sel_pl.c and next_cpu.c) is the select-screen timer:
 * it counts Select_Timer down in BCD every 50 frames, holds while Time_Stop or Break_Into is set,
 * and sets Time_Over 30 frames after the timer reaches zero.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sc_trans.h"
#include "effa5.h"



void effect_A5_move(WORK_Other* ewk) {
    if (Break_Into) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Time_Stop == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 1:
        if (!Check_Sleep_A5(ewk)) {
            return;
        }
        if (--Unit_Of_Timer) {
            break;
        }
        Unit_Of_Timer = 50;
        bcdext = 0;
        if ((Select_Timer = sbcd(1, Select_Timer)) == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 30;
        }
        break;
    case 2:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }
        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        } else if (--ewk->wu.dir_timer == 0) {
            Time_Over = 1;
            ewk->wu.routine_no[0]++;
        }
        break;
    case 3:
        if (!Check_Sleep_A5(ewk)) {
            return;
        }
        Time_Over = 1;
        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        }
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}


s32 Check_Sleep_A5(WORK_Other* ewk) {
    if (Time_Stop == 2) {
        ewk->wu.routine_no[0] = 0;
    }
    return 1;
}

/* provisional name */
u32 effect_A5_entry(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 105;
    return 0;
}

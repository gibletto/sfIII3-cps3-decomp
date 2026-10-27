/*
 * EFFK0.C  Effect K0: select timer countdown, and effect_A5_init
 *
 * effect_K0_move counts Select_Timer down in BCD every 60 frames while Time_Stop is clear, and
 * sets Time_Over one second after the timer reaches zero. It is a simpler twin of the effect A5
 * select timer in EFFA5.C.
 * effect_A5_init creates a bare effect work with id 200.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "EFFK0.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait for the clock to start */
#define R0_COUNT        1       /* count the timer down */
#define R0_ZERO         2       /* one second at zero, then time over */
#define R0_STOP         3       /* stay until removed */



void effect_K0_move(WORK_Other* ewk) {
    if (Time_Stop) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (Time_Stop == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_COUNT:
        if (--Unit_Of_Timer == 0) {
            Unit_Of_Timer = 60;
            bcdext = 0;
            if ((Select_Timer = sbcd(1, Select_Timer)) == 0) {
                ewk->wu.routine_no[0]++;
            }
        }
        break;
    case R0_ZERO:
        if (--Unit_Of_Timer == 0) {
            Time_Over = 1;
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_STOP:
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

u32 effect_A5_init(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 200;
    return 0;
}

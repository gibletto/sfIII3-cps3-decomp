/*
 * EFFI3.C  Effect I2 (palette cycle) and empty I1
 *
 * Effect I2 cycles a palette: every time its timer from effI2_timer_tbl runs out it moves to the
 * next of ten steps and loads the palette in effI2_col_tbl. It is freed on Suicide[0].
 * effect_I1_move and effect_I1_dummy are empty routines.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFI3.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the cycle */
#define R0_MOVE         1       /* step the colours until told to end */
#define R0_KILL         2       /* put the work back */



/* provisional name */
void effect_I1_move(void)
{
}


/* provisional name */
void effect_I1_dummy(void) {}



s32 effect_I2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 182;
    ewk->wu.operator = 0;
    ewk->wu.type = effI2_timer_tbl[0];
    return 0;
}



void effect_I2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
    case R0_MOVE:
        if (Suicide[0]) {
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
            return;
        }
        ewk->wu.type--;
        if (ewk->wu.type == 0) {
            ewk->wu.operator++;
            if (ewk->wu.operator > 9) {
                ewk->wu.operator = 0;
            }
            ewk->wu.type = effI2_timer_tbl[ewk->wu.operator];
            load_any_color(effI2_col_tbl[ewk->wu.operator]);
            return;
        }
        break;
    case R0_KILL:
    default:
        push_effect_work((WORK*)ewk);
        return;
    }
}

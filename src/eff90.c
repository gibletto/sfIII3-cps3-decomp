/*
 * EFF90.C  Effect 90: BG1 display object
 *
 * effect_90: a debug-toggled or master-following display on BG1.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff90.h"
#include "cps3.h"

/* routine_no[0] (type 0: the switch; others: the row objects) */
#define R0_INIT         0       /* start hidden */
#define R0_MOVE         1       /* show as switched or with the master */



void effect_90_move(WORK_Other* ewk) {
    WORK* mwk;
    s16 sw;
    if (ewk->wu.type == 0) {
        switch (ewk->wu.routine_no[0]) {
        case R0_INIT:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        case R0_MOVE:
            if (exsw_0 & 0x8000) {
                sw = p1sw_0 & ~p1sw_1;
                if (sw & BUTTON_MK) {
                    ewk->wu.disp_flag ^= 1;
                }
            }
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    } else {
        mwk = (WORK*)ewk->my_master;
        switch (ewk->wu.routine_no[0]) {
        case R0_INIT:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;
        case R0_MOVE:
            if (mwk->disp_flag) {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos;
                ewk->wu.disp_flag = 1;
                suzi_sync_pos_set(ewk);
                sort_push_request4(&ewk->wu);
            }
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}


/* provisional name */
s32 effect_90_dummy(void) {
    return 0;
}

/*
 * EFFI3_2.C  Effect I3: stop the background for a while
 *
 * Effect I3 (effect_I3_init, called from player move code) sets bg_stop to hold the background
 * scroll while an action plays; its i3_data entry gives the duration (fixed, the owner's hit
 * stop or frame type) and whether it also ends when the owner's pattern changes. It clears
 * bg_stop and frees itself when the time is up, the owner dies or a Suicide request comes.
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
#define R0_INIT         0       /* stop the background, set the time */
#define R0_HOLD         1       /* hold until the time or action ends */
#define R0_KILL         2       /* restart the background and free */



void effect_I3_move(WORK_Other* ewk) {
    const I3_Data* tp;
    WORK* mwk = (WORK*)ewk->my_master;
    tp = i3_data;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        bg_stop = 1;
        switch (tp[ewk->wu.type].sour) {
        case 1:
            if ((ewk->wu.dir_timer = ewk->wu.hit_stop) < 0) {
                ewk->wu.dir_timer = -ewk->wu.dir_timer;
            }
            break;
        case 2:
            ewk->wu.dir_timer = ewk->wu.cg_type;
            break;
        default:
            ewk->wu.dir_timer = tp[ewk->wu.type].tm;
            break;
        }
    case R0_HOLD:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag != 0 || Game_pause != 0) {
            break;
        }
        if (tp[ewk->wu.type].flag & 1 && --ewk->wu.dir_timer < 0) {
            goto next;
        }
        if (tp[ewk->wu.type].flag & 2) {
            if (ewk->wu.now_koc != mwk->now_koc || ewk->wu.char_index != mwk->char_index) {
                goto next;
            }
        }
        break;
    next:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    case R0_KILL:
    default:
        bg_stop = 0;
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_I3_init(WORK* wk, u8 tix) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 183;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32*)wk;
    ewk->wu.type = tix;
    ewk->wu.cg_type = wk->cg_type;
    ewk->wu.hit_stop = wk->hit_stop;
    ewk->wu.now_koc = wk->now_koc;
    ewk->wu.char_index = wk->char_index;
    return 0;
}

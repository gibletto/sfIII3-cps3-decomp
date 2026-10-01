/*
 * tate00.c  Stage background control task
 *
 * cal_bg_speed_data, cal_bg_speed_data_x and cal_bg_speed_data_y compute the speed and deceleration
 * that bring a BG plane's chase position to the target (chase_x / chase_y) in a given number
 * of frames, spreading the remainder so the plane arrives exactly.
 * TATE00 is the per-frame stage BG entry used during fights (and by
 * the debug fight setups): ta0_init00 sets a random compel_flag and allocates the
 * match scene, ta0_init01 runs akebono_initialize and ta0_init02 loads the stage
 * colours, each running the stage's own handler from ta_move_tbl; ta0_move then calls that
 * handler every frame and counts down the screen quake timers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "PLS02.h"
#include "tate00.h"

/* provisional name */
void cal_bg_speed_data(bg_num, tm)
s16 bg_num;
s16 tm;
{
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[0].disp.low = 0;
    bg_w.bgw[bg_num].chase_xy[1].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = ((ms.timer * (ms.timer - 1)) / 2) + ms.timer;
    ms.x.ps.h = chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    ms.y.ps.h = chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos;
    ms.y.ps.l = 0;
    ms.x.ps.l = 0;
    if (!ms.timer) {
        ms.amy = 0;
        ms.amx = 0;
        ms.dly = 0;
        ms.spy = 0;
        ms.dlx = 0;
        ms.spx = 0;
    } else {
        ms.amx = ms.x.pl % ms.timer2;
        ms.spx = ms.dlx = ms.x.pl / ms.timer2;
        ms.amy = ms.y.pl % ms.timer2;
        ms.spy = ms.dly = ms.y.pl / ms.timer2;
    }
    bg_mvxy.a[0].sp = ms.spx;
    bg_mvxy.d[0].sp = ms.dlx;
    bg_mvxy.a[1].sp = ms.spy;
    bg_mvxy.d[1].sp = ms.dly;
    bg_w.bgw[bg_num].chase_xy[0].cal += ms.amx;
    bg_w.bgw[bg_num].chase_xy[1].cal += ms.amy;
    bg_mvxy.kop[0] = bg_mvxy.kop[1] = 0;
}



void cal_bg_speed_data_x(s16 bg_num, s16 tm, s16 dummy) {
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[0].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = ((ms.timer * (ms.timer - 1)) / 2) + ms.timer;
    ms.x.ps.h = chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    ms.x.ps.l = 0;
    if (!ms.timer) {
        ms.amx = 0;
        ms.dlx = 0;
        ms.spx = 0;
    } else {
        ms.amx = ms.x.pl % ms.timer2;
        ms.spx = ms.dlx = ms.x.pl / ms.timer2;
    }
    bg_mvxy.a[0].sp = ms.spx;
    bg_mvxy.d[0].sp = ms.dlx;
    bg_w.bgw[bg_num].chase_xy[0].cal += ms.amx;
    bg_mvxy.kop[0] = 0;
}



/* provisional name */
void cal_bg_speed_data_y(s16 bg_num, s16 tm, s16 dummy) {
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[1].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = ((ms.timer * (ms.timer - 1)) / 2) + ms.timer;
    ms.y.ps.h = chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos;
    ms.y.ps.l = 0;
    if (!ms.timer) {
        ms.amy = 0;
        ms.dly = 0;
        ms.spy = 0;
    } else {
        ms.amy = ms.y.pl % ms.timer2;
        ms.spy = ms.dly = ms.y.pl / ms.timer2;
    }
    bg_mvxy.a[1].sp = ms.spy;
    bg_mvxy.d[1].sp = ms.dly;
    bg_w.bgw[bg_num].chase_xy[1].cal += ms.amy;
    bg_mvxy.kop[1] = 0;
}



/* provisional name: a human player has just pressed a button, unreferenced */
s32 pl_shot_trg_check(void) {
    if (plw[0].wu.operator && ((u16)(~p1sw_1 & p1sw_0) & 0x3F0)) {
        return 1;
    }
    if (plw[1].wu.operator && ((u16)(~p2sw_1 & p2sw_0) & 0x3F0)) {
        return 1;
    }
    return 0;
}



void TATE00(void) {
    void (*jump_tbl[4])() = { ta0_init00, ta0_init01, ta0_init02, ta0_move };
    jump_tbl[bg_w.bg_routine]();
}



void ta0_init00(void) {
    bg_w.bg_routine++;
    bg_w.compel_flag = random_16_com();
    bg_w.compel_flag &= 3;
    bg_initialize();
}



void ta0_init01(void) {
    bg_w.bg_routine++;
    akebono_initialize();
    ta_move_tbl[bg_w.bg_index]();
}



void ta0_init02(void) {
    bg_w.bg_routine++;
    bg_color_trans();
    ta_move_tbl[bg_w.bg_index]();
}



void ta0_move(void) {
    ta_move_tbl[bg_w.bg_index]();
    if (bg_w.quake_x_index > 0) {
        bg_w.quake_x_index--;
    }
    if (bg_w.quake_y_index > 0) {
        bg_w.quake_y_index--;
    }
}

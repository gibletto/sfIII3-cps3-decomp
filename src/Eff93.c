/*
 * EFF93.C  Effect 93: face-select BG slide
 *
 * effect_93 (from sel_pl): slides BG1 on the face-select screen (Eff93_SLIDE_L/R, SHIFT_L/R),
 * hiding and re-enabling the cursor; Bg_Family_Set_Ex sets up a BG family for sel_pl and Win.
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
#include "eff93.h"
#include "cps3.h"



void effect_93_move(WORK_Other* ewk) {
    Eff93_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
}



void Eff93_SLIDE_L(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.hit_quake = 0x25C;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
            ewk->wu.direction = bg_w.bgw[1].xy[1].disp.pos + 16;
            ewk->wu.mvxy.a[0].sp = 0x90000;
            ewk->wu.mvxy.a[1].sp = 0;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.direction, 1, 1);
            bg_mvxy.a[0].sp = ewk->wu.mvxy.a[0].sp;
            bg_mvxy.a[1].sp = ewk->wu.mvxy.a[1].sp;
            bg_mvxy.d[0].sp = ewk->wu.mvxy.d[0].sp;
            bg_mvxy.d[1].sp = ewk->wu.mvxy.d[1].sp;
            ewk->wu.dir_timer = 10;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        bg_w.bgw[1].wxy[1].cal += bg_mvxy.a[1].sp;
        bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
        bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
        if (--ewk->wu.dir_timer == 0) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].xy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].wxy[1].disp.pos = ewk->wu.direction;
            bg_w.bgw[1].xy[1].disp.pos = ewk->wu.direction;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_R(WORK_Other* ewk) {
    s16 arrived_x;
    s16 arrived_y;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = -0x90000;
            bg_mvxy.d[0].sp = -0x8000;
            ewk->wu.hit_quake = 0x25C;
            bg_mvxy.a[1].sp = -0x10000;
            bg_mvxy.d[1].sp = 0;
            bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
            ewk->wu.direction = bg_w.bgw[1].xy[1].disp.pos - 8;
        }
        break;
    default:
        arrived_x = 0;
        arrived_y = 0;
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].xy[0].disp.pos = ewk->wu.hit_quake;
            arrived_x = 1;
        }
        bg_w.bgw[1].wxy[1].cal += bg_mvxy.a[1].sp;
        bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
        bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
        if (ewk->wu.direction >= bg_w.bgw[1].wxy[1].disp.pos) {
            bg_w.bgw[1].wxy[1].disp.pos = ewk->wu.direction;
            bg_w.bgw[1].xy[1].disp.pos = ewk->wu.direction;
            arrived_y = 1;
        }
        if ((arrived_x != 0) && (arrived_y != 0)) {
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_L_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = 0x80000;
            bg_mvxy.d[0].sp = 0x28000;
            ewk->wu.hit_quake = bg_w.bgw[1].wxy[0].disp.pos + 208;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake <= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_R_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = -0x80000;
            bg_mvxy.d[0].sp = -0x28000;
            ewk->wu.hit_quake = 0x130;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Bg_Family_Set_Ex(s16 xx) {
    s16 pos_work_x;
    s16 pos_work_y;
    bg_w.bgw[xx].position_x = bg_w.bgw[xx].xy[0].disp.pos & 0x3FF;
    pos_work_x = bg_w.bgw[xx].position_x;
    bg_w.bgw[xx].position_y = bg_w.bgw[xx].xy[1].disp.pos & 0x3FF;
    pos_work_y = bg_w.bgw[xx].position_y;
    Scrn_Move_Set(xx, pos_work_x, pos_work_y);
    pos_work_x = -pos_work_x & 0x3FF;
    pos_work_y = (0x300 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(xx + 1, pos_work_x, pos_work_y);
}



s32 effect_93_init(s8 Move_Type, s16 Time) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x5D;
    ewk->wu.dir_timer = Time;
    ewk->wu.routine_no[0] = Move_Type;
    Appear_Cursor = 0;
    return 0;
}

/*
 * EFF81.C  Effect 81: banner sliding across BG2
 *
 * Effect 81 is started by effect_81_init from the game management (Manage) with a start delay;
 * it sets a flag and requests sound 154.
 * effect_81_move waits for the delay, slides the banner in from the left of BG2 with a
 * decelerating speed, holds it for 39 frames, then moves it on until it leaves the BG range and
 * releases itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff81.h"



void effect_81_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.mvxy.a[0].sp = 0xE0000;
        ewk->wu.mvxy.d[0].sp = 0x10000;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos - 416;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos - 24;
        ewk->wu.hit_quake = bg_w.bgw[1].xy[0].disp.pos - 16;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 39;
        }
        break;
    case 2:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 3:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 240)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + base_y_pos + 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_81_init(s16 Time) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 81;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2038;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 16;
    ewk->wu.dir_step = 7;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_timer = Time;
    ewk->wu.position_z = 8;
    Appear_Q = 1;
    load_any_color(154);
    return 0;
}

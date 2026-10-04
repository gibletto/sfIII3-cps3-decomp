/*
 * EFFD2.C  Effect D2: screen wipe panels
 *
 * effect_D2 is one panel of the screen wipe used between scenes: effect_D2_init sets its direction,
 * delay and start point (effD2_pos_set); effD2_wipe_close slides it in and effD2_wipe_open slides it
 * out, both counting Wipe_Panel_Count down (created from SYS_sub).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "aboutspr.h"
#include "eff20.h"
#include "effg8.h"
#include "effect_L9_move.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Manage.h"
#include "manage_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "effd3.h"
#include "effd2.h"



void effect_D2_move(WORK_Other* ewk) {
    EFFD3_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}



/* provisional name */
void effD2_wipe_close(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    case 2:
        if (ewk->wu.vital_new == 4) {
            tilemap_fill_all(62, 0xAF);
        }
        ewk->wu.routine_no[1]++;
        Wipe_Panel_Count--;
        break;
    }
    if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 0x100)) {
        ewk->wu.disp_flag = 0;
    } else {
        ewk->wu.disp_flag = 1;
    }
}



/* provisional name */
void effD2_wipe_open(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dir_timer = 3;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[1]++;
        tilemap_fill_all(0, 32);
        break;
    case 2:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
                Wipe_Panel_Count--;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Wipe_Panel_Count--;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_D2_init(s16 vital, s16 dir, s16 family, s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 132;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x21FF;
    ewk->wu.my_family = family;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = 56;
    if (dir < 2) {
        ewk->wu.dir_step = 0;
    } else {
        ewk->wu.dir_step = 1;
    }
    ewk->wu.dm_vital = 512;
    ewk->wu.vital_new = vital;
    ewk->wu.direction = dir;
    ewk->wu.dir_timer = timer;
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 127;
    ewk->wu.my_mr.size.y = 127;
    effD2_pos_set(ewk);
    return 0;
}



/* provisional name */
void effD2_pos_set(WORK_Other* ewk) {
    if (ewk->wu.vital_new == 0) {
        switch (ewk->wu.direction) {
        case 0:
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 328;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 466;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + 496;
            break;
        case 1:
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 582;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 466;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + 496;
            break;
        case 2:
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 582;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 240;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 512;
            break;
        case 3:
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 328;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 240;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 512;
            break;
        }
    }
    ewk->wu.position_z = 6;
}




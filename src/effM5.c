/*
 * EFFM5.C  Entrance vehicle and helpers (effects M4, M5)
 *
 * effect_M5 is the vehicle a fighter arrives in during the entrance (Appear_06000): it
 * drives in from the screen edge with a computed speed and engine sound, stops
 * (Appear_car_stop), plays its stop animation while raising demo_car_flag, then drives off
 * and frees itself. effect_M5_init also starts its companion part effect_M6.
 * effect_M4 steps a timed palette script from effM4_dir_tbl through load_any_color.
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
#include "EFFM7.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "effM5.h"

/* effect M4 palette script: routine_no[0] */
#define R0_INIT         0       /* first-frame set-up */
#define R0_MOVE         1       /* step the palette script */
#define R0_KILL         2       /* put the work back */

/* effect M5 vehicle: routine_no[0] */
#define R0_DRIVE_IN     1       /* drive in to the stop point */
#define R0_STOP         2       /* stop animation */
#define R0_WAIT         3       /* wait before driving off */
#define R0_DRIVE_OFF    4       /* drive off */
#define R0_HIDE         5       /* hide and clear the car flag */
#define R0_END          6       /* hidden for a frame */



extern const s16 effM4_dir_tbl_0[][2];
extern const s16 effM4_dir_tbl_1[][2];
extern const s16 effM4_dir_tbl_2[][2];
extern const s16 effM4_dir_tbl_3[][2];
extern const s16 effM4_dir_tbl_4[][2];
extern const s16 effM4_dir_tbl_5[][2];
extern const s16 effM4_dir_tbl_6[][2];
extern const s16 effM4_dir_tbl_7[][2];

/* 020074BC */
const s16 (*effM4_dir_tbl[8])[2] = {
    effM4_dir_tbl_0,
    effM4_dir_tbl_1,
    effM4_dir_tbl_2,
    effM4_dir_tbl_3,
    effM4_dir_tbl_4,
    effM4_dir_tbl_5,
    effM4_dir_tbl_6,
    effM4_dir_tbl_7,
};


void effect_M4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.dir_step = 0;
        ewk->wu.dir_timer = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][0];
        ewk->wu.direction = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][1];
        ewk->wu.routine_no[0] = R0_MOVE;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] = R0_KILL;
            break;
        }
        if (--ewk->wu.dir_timer >= 0) {
            break;
        }
        load_any_color(ewk->wu.direction);
        ewk->wu.dir_step++;
        ewk->wu.dir_timer = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][0];
        ewk->wu.direction = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][1];
        if (ewk->wu.dir_timer == -1) {
            ewk->wu.routine_no[0] = R0_KILL;
        }
        break;
    case R0_KILL:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

u32 effect_M4_init(s16 type)
{
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.type = type;
    ewk->wu.id = 224;
    ewk->wu.work_id = 128;
    return 0;
}



void effect_M5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            Sound_SE(ewk->master_id * 0x300 + 0x134);
        }
        break;
    case R0_DRIVE_IN:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                Appear_car_stop[ewk->master_id] = 1;
                set_char_move_init(&ewk->wu, 0, 0x68);
                if (Demo_Sound != 0 || Demo_Flag != 0) {
                    sound_request_pan(0x135, 0x40, 0x40, 0, 2);
                }
            } else {
                add_x_sub(ewk);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_STOP:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 0x14;
            } else if (ewk->wu.cg_type == 2) {
                demo_car_flag[ewk->master_id] = 1;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_WAIT:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 0x30;
                if (ewk->wu.rl_flag != 0) {
                    ewk->wu.mvxy.a[0].sp = -0x20000;
                    ewk->wu.mvxy.d[0].sp = -0x1000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0x20000;
                    ewk->wu.mvxy.d[0].sp = 0x1000;
                }
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_DRIVE_OFF:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
            } else {
                add_x_sub(ewk);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_HIDE:
        ewk->wu.routine_no[0]++;
        demo_car_flag[ewk->master_id] = 0;
        ewk->wu.disp_flag = 0;
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_M5_init(PLW* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 work;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    demo_car_flag[oya->wu.id] = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 225;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 103;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = 57;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code + 4;
    ewk->wu.sync_suzi = 0;
    ewk->master_id = oya->wu.id;
    if (oya->wu.id) {
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.old_rno[0] = 40;
        if (Game_setting.Screen_Mode) {
            work = (bg_w.bgw[1].pos_x_work + 208) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work + 352) & 0x3FF;
        } else {
            work = (bg_w.bgw[1].pos_x_work + 168) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work + 320) & 0x3FF;
        }
    } else {
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.rl_flag = 1;
        ewk->wu.old_rno[0] = 40;
        if (Game_setting.Screen_Mode) {
            work = (bg_w.bgw[1].pos_x_work - 216) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 352) & 0x3FF;
        } else {
            work = (bg_w.bgw[1].pos_x_work - 168) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 320) & 0x3FF;
        }
    }
    cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    suzi_offset_set(&ewk->wu);
    return effect_M6_init(ewk);
}

/*
 * EFFM5.C  Entrance vehicle and helpers (effects M3, M4, M5)
 *
 * effect_M5 is the vehicle a fighter arrives in during his entrance (Appear_06000): it
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
#include "EFFM7.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "textsound.h"
#include "SE.h"
#include "bg_sub.h"
#include "effM5.h"



void effect_M4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.dir_step = 0;
        ewk->wu.dir_timer = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][0];
        ewk->wu.direction = effM4_dir_tbl[ewk->wu.type][ewk->wu.dir_step][1];
        ewk->wu.routine_no[0] = 1;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] = 2;
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
            ewk->wu.routine_no[0] = 2;
        }
        break;
    case 2:
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
    case 0:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            Sound_SE(ewk->master_id * 0x300 + 0x134);
        }
        break;
    case 1:
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
    case 2:
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
    case 3:
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
    case 4:
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
    case 5:
        ewk->wu.routine_no[0]++;
        demo_car_flag[ewk->master_id] = 0;
        ewk->wu.disp_flag = 0;
        break;
    case 6:
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
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code + 4;
    ewk->wu.sync_suzi = 0;
    ewk->master_id = oya->wu.id;
    if (oya->wu.id) {
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.old_rno[0] = 40;
        if (Game_setting.mode) {
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
        if (Game_setting.mode) {
            work = (bg_w.bgw[1].pos_x_work - 216) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 352) & 0x3FF;
        } else {
            work = (bg_w.bgw[1].pos_x_work - 168) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 320) & 0x3FF;
        }
    }
    cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    suzi_offset_set(ewk);
    return effect_M6_init(ewk);
}

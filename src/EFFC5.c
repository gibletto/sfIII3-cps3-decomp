/*
 * EFFC5.C  Effect C4 init and effect C5: the car of the car entrance
 *
 * effect_C4_init creates the bouncing object of EFFC4.C at its master's position with a shadow.
 * Effect C5 is the car used by the entrance routine Appear_06000 (appear.c). effect_C5_init
 * places it off-screen on the chosen side (distance by Game_setting), aims it at a stop point
 * 40 frames away and spawns its C6 child. effect_C5_move drives in with the engine sound,
 * brakes and sets Appear_car_stop for the player (with a demo sound), raises demo_car_flag while
 * its door pattern plays, then drives away over 48 frames and frees itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFC6.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "textsound.h"
#include "SE.h"
#include "bg_sub.h"
#include "EFFC5.h"



s32 effect_C4_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 124;
    ewk->wu.work_id = 16;
    ewk->wu.type = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 6;
    ewk->master_id = wk->id;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->wu.my_priority = ewk->wu.position_z = 16;
    ewk->wu.xyz[0].cal = wk->xyz[0].cal;
    ewk->wu.xyz[1].cal = wk->xyz[1].cal;
    ewk->wu.char_table[0] = direct_03_char_table;
    ewk->wu.kage_flag = 1;
    ewk->wu.kage_hx = -9;
    ewk->wu.kage_hy = -11;
    ewk->wu.kage_char = 11;
    ewk->wu.kage_prio = ewk->wu.position_z + 1;
}



void effect_C5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            Sound_SE(ewk->master_id * 0x300 + 0x134);
        }
        break;
    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                Appear_car_stop[ewk->master_id] = 1;
                set_char_move_init(&ewk->wu, 0, 9);
                if (Demo_Sound || Demo_Flag) {
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
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 20;
            } else if (ewk->wu.cg_type == 2) {
                demo_car_flag[ewk->master_id] = 1;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 48;
                if (ewk->wu.rl_flag) {
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
        if (EXE_flag == 0 && Game_pause == 0) {
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



s32 effect_C5_init(PLW* oya, s16 reverse_f) {
    WORK_Other* ewk;
    s16 ix;
    s16 work;
    s16 id_num;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    demo_car_flag[oya->wu.id] = 0;
    Appear_car_stop[oya->wu.id] = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 125;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 8;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = 57;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code + 6;
    ewk->wu.sync_suzi = 0;
    ewk->master_id = oya->wu.id;
    id_num = oya->wu.id ^ reverse_f;
    if (id_num) {
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.old_rno[0] = 40;
        if (Game_setting.mode) {
            work = (bg_w.bgw[1].pos_x_work + 224) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work + 352) & 0x3FF;
        } else {
            work = (bg_w.bgw[1].pos_x_work + 192) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work + 320) & 0x3FF;
        }
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    } else {
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.rl_flag = 1;
        ewk->wu.old_rno[0] = 40;
        if (Game_setting.mode) {
            work = (bg_w.bgw[1].pos_x_work - 224) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 352) & 0x3FF;
        } else {
            work = (bg_w.bgw[1].pos_x_work - 192) & 0x3FF;
            ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 320) & 0x3FF;
        }
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    }
    suzi_offset_set(ewk);
    return effect_C6_init(ewk);
}

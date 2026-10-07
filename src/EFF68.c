/*
 * EFF68.C  Effects 67 and 68: ranking objects and objects flying between waypoints (bg090)
 *
 * Effect 67 objects slide in and out on the ranking screen (created from RANKING).
 * effect_68_init creates three objects from eff68_data_tbl. effect_68_move flies each one
 * through a series of points using cal_all_speed_data and cal_delta_speed, changing
 * animation at each leg, then starts over.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF68.h"
#include "PLS02.h"
#include "eff64.h"
#include "eff65.h"
#include "eff66.h"



void effect_67_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;
        case 1:
            if (--ewk->wu.dir_timer) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 40;
            break;
        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - 10;
            } else {
                ewk->wu.routine_no[0] = 3;
            }
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;
        case 1:
            if (--ewk->wu.dir_timer) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 39;
            break;
        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + 10;
            } else {
                ewk->wu.routine_no[0] = 3;
            }
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
            break;
        case 1:
            if (--ewk->wu.dir_timer) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 40;
            break;
        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - 10;
            } else {
                ewk->wu.routine_no[0] = 4;
            }
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 3:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 4:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request3(&ewk->wu);
        break;
    case 5:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 6:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    }
}



s32 effect_67_init(s16 id, s16 X, s16 Y, s16 time0, s16 Char_Index, s16 Priority, s16 no, s16 col) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 67;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    if (col) {
        ewk->wu.my_col_code = 0x40;
    } else {
        ewk->wu.my_col_code = 0x180;
    }
    ewk->wu.my_family = 1;
    ewk->wu.position_z = Priority;
    ewk->wu.dir_timer = time0;
    ewk->wu.routine_no[0] = no;
    ewk->wu.routine_no[1] = 0;
    ewk->wu.xyz[0].disp.pos = X;
    ewk->wu.xyz[1].disp.pos = Y;
    if (!id) {
        ewk->num_of_conn = 2;
        ewk->conn[0].col = 0;
        ewk->conn[1].col = 0;
        ewk->conn[0].nx = 0;
        ewk->conn[0].ny = 0;
        ewk->conn[1].nx = 0;
        ewk->conn[1].ny = 0;
        switch (Char_Index) {
        case 0:
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A7;
            break;
        case 1:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A7;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 2:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A7;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 3:
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A6;
            break;
        case 4:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A6;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 5:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A6;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 6:
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A5;
            break;
        case 7:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A5;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 8:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19C;
            ewk->conn[1].chr = 0xA1A5;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 9:
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A4;
            break;
        case 10:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A4;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 11:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A4;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 12:
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A3;
            break;
        case 13:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A3;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 14:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19B;
            ewk->conn[1].chr = 0xA1A3;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 15:
            ewk->conn[0].chr = 0xA19A;
            ewk->conn[1].chr = 0xA1A2;
            break;
        case 16:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19A;
            ewk->conn[1].chr = 0xA1A2;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 17:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA19A;
            ewk->conn[1].chr = 0xA1A2;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 18:
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A1;
            break;
        case 19:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A1;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 20:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A1;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 21:
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A0;
            break;
        case 22:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A0;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A8;
            ewk->conn[2].col = 0;
            break;
        case 23:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA199;
            ewk->conn[1].chr = 0xA1A0;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA1A9;
            ewk->conn[2].col = 0;
            break;
        case 24:
            ewk->conn[0].chr = 0xA198;
            ewk->conn[1].chr = 0xA19F;
            break;
        case 25:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA198;
            ewk->conn[1].chr = 0xA19F;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA146;
            ewk->conn[2].col = 0;
            break;
        case 26:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA198;
            ewk->conn[1].chr = 0xA19F;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA145;
            ewk->conn[2].col = 0;
            break;
        case 27:
            ewk->conn[0].chr = 0xA197;
            ewk->conn[1].chr = 0xA19E;
            break;
        case 28:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA197;
            ewk->conn[1].chr = 0xA19E;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA147;
            ewk->conn[2].col = 0;
            break;
        case 29:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA197;
            ewk->conn[1].chr = 0xA19E;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA148;
            ewk->conn[2].col = 0;
            break;
        case 30:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0xA197;
            ewk->conn[1].chr = 0xA19E;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0xA149;
            ewk->conn[2].col = 0;
            break;
        case 31:
            ewk->conn[0].chr = 0xA196;
            ewk->conn[1].chr = 0xA19D;
        }
    } else {
        *ewk->wu.char_table = sel_pl_char_table;
        ewk->wu.char_index = id;
        ewk->wu.dir_step = Char_Index;
    }
    return 0;
}



void effect_68_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.routine_no[4]--;
        if (ewk->wu.routine_no[4] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[4] = 50;
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], *(s16*)((s8*)ewk->wu.old_rno + 4), ewk->wu.old_rno[3], 1, 1);
            ewk->wu.char_index = ewk->wu.routine_no[6];
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[4]--;
        if (ewk->wu.routine_no[4] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[4] = 50;
            cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], *(s16*)((s8*)ewk->wu.old_rno + 8), ewk->wu.old_rno[5], 2, 2);
            ewk->wu.char_index = ewk->wu.routine_no[6];
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        ewk->wu.routine_no[4]--;
        if (ewk->wu.routine_no[4] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[4] = 40;
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], *(s16*)((s8*)ewk->wu.old_rno + 12), ewk->wu.old_rno[7], 1, 1);
        }
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        ewk->wu.routine_no[4]--;
        if (ewk->wu.routine_no[4] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[4] = 60;
            cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], *(s16*)((s8*)ewk->wu.old_rno + 0), ewk->wu.old_rno[1], 2, 2);
            ewk->wu.char_index = ewk->wu.routine_no[5];
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 5:
        ewk->wu.routine_no[4]--;
        if (ewk->wu.routine_no[4] <= 0) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[4] = 50;
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], *(s16*)((s8*)ewk->wu.old_rno + 4), ewk->wu.old_rno[3], 1, 1);
            ewk->wu.char_index = ewk->wu.routine_no[6];
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_68_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff68_data_tbl;
    for (i = 0; i < 3; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 68;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.dead_f = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.old_rno[4] = *data_ptr++;
        ewk->wu.old_rno[5] = *data_ptr++;
        ewk->wu.old_rno[6] = *data_ptr++;
        ewk->wu.old_rno[7] = *data_ptr++;
        ewk->wu.char_index = ewk->wu.routine_no[5] = *data_ptr++;
        ewk->wu.routine_no[6] = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.routine_no[4] = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = brz_char_table;
        suzi_offset_set(ewk);
    }
    return 0;
}

/*
 * EFF68.C  Effect 68: objects flying between waypoints (bg090)
 *
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
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF68.h"



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
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
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
            cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[4], ewk->wu.old_rno[5], 2, 2);
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
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[6], ewk->wu.old_rno[7], 1, 1);
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
            cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[0], ewk->wu.old_rno[1], 2, 2);
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
            cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
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
        break;
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

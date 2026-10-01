/*
 * EFF67.C  Effects 64-67: stage passers-by, reacting objects and ranking objects
 *
 * Effect 64 is a passer-by that crosses the stage once, repeatedly with fixed or random
 * waits, or after the stage has scrolled (eff64_00..08, eff64_data_set, eff64_goal_check).
 * Effect 65 does nothing. Effect 66 objects react when a player comes near (eff66_00..03).
 * Effect 67 objects slide in and out on the ranking screen (created from RANKING).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF67.h"



void effect_64_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        eff64_jp_tbl[ewk->wu.routine_no[1]](ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void eff64_00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        eff64_data_set(ewk, 0);
    case 1:
        eff64_wait(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.hit_stop) {
                char_move(&ewk->wu);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (eff64_goal_check(ewk)) {
                ewk->wu.routine_no[0] = 2;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



/* provisional name */
void eff64_02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        eff64_data_set(ewk, 0);
        ewk->wu.routine_no[2] = 2;
        break;
    case 1:
        eff64_data_set(ewk, 1);
        break;
    case 2:
        eff64_wait(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.hit_stop) {
                char_move(&ewk->wu);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (eff64_goal_check(ewk)) {
                ewk->wu.routine_no[2] = 1;
                ewk->wu.old_rno[1] = ewk->wu.old_rno[2];
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



/* provisional name */
void eff64_04(WORK_Other* ewk) {
    s32 ix;
    switch (ewk->wu.routine_no[2]) {
    case 0:
        eff64_data_set(ewk, 0);
        ewk->wu.routine_no[2] = 2;
        break;
    case 1:
        eff64_data_set(ewk, 1);
        break;
    case 2:
        eff64_wait(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.hit_stop) {
                char_move(&ewk->wu);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (eff64_goal_check(ewk)) {
                ewk->wu.routine_no[2] = 1;
                ix = random_16_com();
                ewk->wu.old_rno[1] = (ewk->wu.routine_no[1] > 5 ? eff64_move2_tbl : eff64_move_tbl)[ix];
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



/* provisional name */
void eff64_08(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.bgw[1].xy[0].disp.pos < -64) {
            eff64_data_set(ewk, 0);
        }
        ewk->wu.routine_no[2] = 2;
        break;
    case 1:
        if (bg_w.bgw[1].xy[0].disp.pos < -64) {
            eff64_data_set(ewk, 1);
        }
        break;
    case 2:
        eff64_wait(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
            if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[0]) {
                ewk->wu.routine_no[2] = 1;
                ewk->wu.old_rno[1] = eff64_move2_tbl[(s16)random_16_com()];
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



/* provisional name */
void eff64_data_set(WORK_Other* ewk, s16 keep) {
    const s16* data;
    ewk->wu.routine_no[2]++;
    ewk->wu.disp_flag = 1;
    data = &eff64_data_tbl[ewk->wu.type].dead_f;
    ewk->wu.dead_f = *data++;
    ewk->wu.routine_no[1] = *data++;
    ewk->wu.my_family = *data++;
    ewk->wu.my_col_code = *data++;
    ewk->wu.xyz[0].disp.pos = *data++;
    ewk->wu.xyz[1].disp.pos = *data++;
    ewk->wu.my_priority = ewk->wu.position_z = *data++;
    ewk->wu.char_index = *data++;
    ewk->wu.hit_stop = *data++;
    ewk->wu.sync_suzi = *data++;
    ewk->wu.old_rno[0] = *data++;
    if (keep) {
        data++;
    } else {
        ewk->wu.old_rno[1] = *data++;
    }
    ewk->wu.old_rno[2] = *data++;
    ewk->wu.rl_flag = *data;
    data++;
    ewk->wu.mvxy.a[0].real.h = *data++;
    ewk->wu.mvxy.a[0].real.l = *data++;
    ewk->wu.mvxy.d[0].real.h = *data++;
    ewk->wu.mvxy.d[0].real.l = *data++;
    ewk->wu.mvxy.a[1].real.h = *data++;
    ewk->wu.mvxy.a[1].real.l = *data++;
    ewk->wu.mvxy.d[1].real.h = *data++;
    ewk->wu.mvxy.d[1].real.l = *data;
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set((WORK*)ewk);
    set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
}



/* provisional name */
void eff64_wait(WORK_Other* ewk) {
    ewk->wu.old_rno[1]--;
    if (ewk->wu.old_rno[1] < 0) {
        ewk->wu.routine_no[2]++;
    }
}



/* provisional name */
s32 eff64_goal_check(WORK_Other* ewk) {
    if (ewk->wu.routine_no[1] & 1) {
        if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[0]) {
            return 1;
        }
        return 0;
    }
    if (ewk->wu.xyz[0].disp.pos > ewk->wu.old_rno[0]) {
        return 1;
    }
    return 0;
}



s32 effect_64_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 64;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = type;
    ewk->wu.routine_no[1] = eff64_data_tbl[type].dead_f;
    ewk->wu.step_xy_table = eff64_stepxy_table;
    return 0;
}



void effect_65_move(void)
{
  return;
}

u32 effect_65_init(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 65;
    return 0;
}



void effect_66_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff66_jp_tbl[ewk->wu.routine_no[1]](ewk);
        }
        if (!ewk->wu.old_rno[2] || range_x_check(ewk)) {
            disp_pos_trans_entry_s(ewk);
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void eff66_00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;
    case 1:
        if (ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }
        if (range_abs_check(plw[0].wu.position_x, ewk->wu.position_x, 32) ||
            range_abs_check(plw[1].wu.position_x, ewk->wu.position_x, 32)) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



/* provisional name */
void eff66_01(WORK_Other* ewk) {}



void eff66_02(WORK_Other* ewk) {}



void eff66_03(WORK_Other* ewk) {
    s16 bg_x;
    s16 right;
    s16 left;
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;
    case 1:
        char_move(&ewk->wu);
        if (range_abs_check(plw[0].wu.xyz[0].disp.pos, ewk->wu.xyz[0].disp.pos, 16) ||
            range_abs_check(plw[1].wu.xyz[0].disp.pos, ewk->wu.xyz[0].disp.pos, 16)) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case 3:
        bg_x = bg_w.bgw[ewk->wu.my_family - 1].xy[0].disp.pos;
        right = bg_x + 288;
        left = bg_x - 288;
        if (ewk->wu.xyz[0].disp.pos > right || ewk->wu.xyz[0].disp.pos < left) {
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



s32 effect_66_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr = eff66_data_tbl[type];
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 66;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr;
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set(ewk);
    return 0;
}



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
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 40;
            }
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
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 39;
            }
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
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 40;
            }
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
            break;
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
            break;
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

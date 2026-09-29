/*
 * EFF11.C  Effect 11: stage objects that jump when the screen quakes (bg000)
 *
 * Effect 11 objects watch the background quake level. When bg_w.quake_y_index rises they
 * hop (quake_level_middle) or jump and scatter sideways (quake_level_large) with speeds from
 * eff11_quake_speed tables, bounce a few times and settle back to their idle animation.
 * effect_11_init is called from bg000.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF11.h"



void effect_11_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff11_quake_sub(ewk);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff11_quake_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index > 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[1] = eff11_quake_index_tbl[bg_w.quake_y_index];
        }
        break;
    case 1:
        if (ewk->wu.old_rno[1] > 4) {
            quake_level_large(ewk);
            break;
        }
        quake_level_middle(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
        ewk->wu.old_rno[1] = 0;
        break;
    }
}



void quake_level_middle(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
        ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
    case 1:
    case 3:
    case 5:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[6] + 1, 13, 0);
            ewk->wu.old_rno[0] = 0;
        }
        break;
    case 2:
    case 4:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
            ewk->wu.mvxy.a[1].sp >>= ewk->wu.routine_no[2];
            ewk->wu.old_rno[0]++;
            ewk->wu.old_rno[0] &= 3;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
        }
        break;
    case 6:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1] = 2;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6]);
        }
        break;
    }
}



void quake_level_large(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
        ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
        ewk->wu.mvxy.a[0].sp = eff11_quake_speed_x_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        work = random_16_com();
        if (work & 1) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[6] + 1, 13, 0);
            break;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (!(ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2])) {
            break;
        }
        ewk->wu.routine_no[2]++;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        ewk->wu.xyz[1].disp.low = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
        ewk->wu.old_rno[5] = 28;
        ewk->wu.mvxy.d[0].sp = 0;
        if (ewk->wu.old_rno[3]) {
            ewk->wu.mvxy.d[1].sp = -0x6000;
        } else {
            ewk->wu.mvxy.d[1].sp = -0x8000;
        }
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[5], ewk->wu.old_rno[4], ewk->wu.old_rno[2]);
        break;
    case 3:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[5]--;
        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[6] + 3, 7, 0);
        }
        break;
    case 4:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[4];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
            ewk->wu.old_rno[0] = 0;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case 5:
    case 7:
    case 9:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[6] + 3, 7, 0);
        }
        break;
    case 6:
    case 8:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[2]++;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
            ewk->wu.old_rno[0]++;
            ewk->wu.old_rno[0] &= 3;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case 10:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1] = 2;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[6]);
        }
        break;
    }
}



s32 effect_11_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff11_data_tbl;
    for (i = 0; i < 4; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 11;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = usa_char_table;
        ewk->wu.sync_suzi = 0;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.old_rno[6] = ewk->wu.char_index;
        ewk->wu.old_rno[4] = ewk->wu.xyz[0].disp.pos;
        ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos;
        suzi_offset_set(ewk);
    }
    return 0;
}

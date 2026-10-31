/*
 * EFF44.C  Effect 43 (select-screen object) and effect 44 (animated stage objects)
 *
 * Effect 43 appears after a delay on a chosen BG and animates (sel_pl, next_cpu).
 * Effect 44 creates the animated objects of scr_obj_data44 for a stage and animates them
 * until killed; it is used by several stages (bg000, bg040, bg050, bg120, bg130).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
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
#include "EFF44.h"

/* routine_no[0], effect_43_move */
#define R0_WAIT         0       /* count the delay down, then show */
#define R0_ANIM         1       /* animate */

/* routine_no[0], effect_44_move */
#define R0_INIT         0       /* show and start the animation */
#define R0_MOVE         1       /* animate until retired */
#define R0_KILL         2       /* (default) put the work back */



/* 02006CC8 */
const s16* scr_obj_data44[10] = {
    eff44_data_tbl0,
    eff44_data_tbl1,
    eff44_data_tbl2,
    eff44_data_tbl3,
    eff44_data_tbl4,
    eff44_data_tbl5,
    eff44_data_tbl6,
    eff44_data_tbl7,
    eff44_data_tbl8,
    eff44_data_tbl9,
};


void effect_43_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_ANIM:
        char_move(&ewk->wu);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_43_init(s16 Time, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 43;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 128;
    ewk->wu.position_z = 15;
    ewk->wu.char_index = 77;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_timer = Time;
    return 0;
}



void effect_44_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_MOVE:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_44_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num44[type];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_data44[type];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 44;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}

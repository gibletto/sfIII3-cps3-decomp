/*
 * EFFJ6.C  Effect J6: hittable stage object
 *
 * effect_J6 is a stage object that can be hit: eff_hit_check changes its pattern and
 * starts effect 27 (created from EFFI4MV).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFF27.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "effJ6.h"

/* routine_no[0] */
#define R0_INIT         0       /* show whole, or broken if hit before */
#define R0_READY        1       /* wait for the parent to start */
#define R0_HITTABLE     2       /* wait for a hit */
#define R0_BREAK        3       /* change to the broken pattern */
#define R0_BROKEN       4       /* stay broken */



void effect_J6_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr;
    if (obr_no_disp_check()) {
        return;
    }
    oya_ptr = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = R0_BROKEN;
            set_char_move_init(&ewk->wu, 0, 3);
        } else {
            set_char_move_init(&ewk->wu, 0, 4);
        }
        break;
    case R0_READY:
        if (oya_ptr->wu.routine_no[0] >= 2) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case R0_HITTABLE:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            effect_j6_hit_sub(ewk);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case R0_BREAK:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, 3);
    case R0_BROKEN:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effect_j6_hit_sub(WORK_Other* ewk) {
    if (eff_hit_check(ewk, 0)) {
        ewk->wu.routine_no[0]++;
        effect_27_init(ewk, 1);
    }
}



s32 effect_J6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 196;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = 3;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    *ewk->wu.char_table = chn_char_table;
    ewk->wu.xyz[0].disp.pos = 904;
    ewk->wu.xyz[1].disp.pos = 16;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.char_index = 4;
    ewk->wu.routine_no[1] = 0;
    return 0;
}

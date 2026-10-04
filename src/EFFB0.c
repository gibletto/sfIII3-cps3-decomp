/*
 * EFFB0.C  Effect B0: ending scene twinkles
 *
 * effect_B0_init (called from end_7.c) creates eight objects from end_char_table (pattern 29)
 * at the positions in effb0_data_tbl. effect_B0_move waits a random time from effb0_timer_tbl,
 * shows the object and plays its pattern once, then hides it and picks a new random wait and
 * position. All eight free themselves when the ending scene number (end_w.r_no_2) moves on.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFB0.h"



void effect_B0_move(WORK_Other* ewk) {
    s16 work;
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[0] = 99;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[0] = 0;
            ewk->wu.disp_flag = 0;
            work = random_16_com();
            work &= 7;
            ewk->wu.old_rno[5] = effb0_timer_tbl[work];
            work = random_16_com();
            work &= 7;
            ewk->wu.xyz[0].disp.pos = effb0_data_tbl[work][0];
            work = random_16_com();
            work &= 7;
            ewk->wu.xyz[1].disp.pos = effb0_data_tbl[work][1];
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_B0_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 work;
    for (i = 0; i < 8; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 110;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.old_rno[0] = end_w.r_no_2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = (u32*)end_char_table;
        ewk->wu.my_col_code = 32;
        ewk->wu.my_family = 1;
        ewk->wu.old_rno[6] = 0;
        ewk->wu.old_rno[6] += end_w.r_no_2;
        ewk->wu.xyz[0].disp.pos = effb0_data_tbl[i][0];
        ewk->wu.xyz[1].disp.pos = effb0_data_tbl[i][1];
        ewk->wu.my_priority = ewk->wu.position_z = 80;
        ewk->wu.char_index = 29;
        work = random_16_com();
        work &= 7;
        ewk->wu.old_rno[5] = effb0_timer_tbl[work];
    }
    return 0;
}

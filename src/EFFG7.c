/*
 * EFFG7.C  Effect G7: one-shot ending animation
 *
 * effect_G7_init creates an end_char_table object on BG3 at (640, 0) with priority 74 and
 * records the current ending scene. effect_G7_move plays pattern 51 once and frees the work when
 * it ends or when the ending scene (end_w.r_no_2) moves on.
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
#include "aboutspr.h"
#include "EFFG7.h"



void effect_G7_move(WORK_Other* ewk) {
    if (ewk->wu.old_rno[0] < end_w.r_no_2) {
        ewk->wu.routine_no[0] = 99;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 51, 1, 0);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_G7_init(s32 _p0, s32 _p1) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 167;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[0] = end_w.r_no_2;
    ewk->wu.my_col_mode = 0x4200;
    *ewk->wu.char_table = end_char_table;
    ewk->wu.my_family = 3;
    ewk->wu.my_col_code = 0x20;
    ewk->wu.xyz[0].disp.pos = 640;
    ewk->wu.xyz[1].disp.pos = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 74;
    return 0;
}

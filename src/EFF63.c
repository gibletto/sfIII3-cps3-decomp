/*
 * EFF63.C  Effect 63: pair of idle animated objects
 *
 * effect_78_init creates two effect 63 works from eff78_init_tbl (chn_char_table).
 * effect_63_move plays one of three idle animations, switching to the next every 60 frames
 * and waiting for each to finish.
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
#include "EFF63.h"



void effect_63_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 60;
        ewk->wu.old_rno[1] = 0;
        break;
    case 1:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[1]++;
            if (ewk->wu.old_rno[1] > 2) {
                ewk->wu.old_rno[1] = 0;
            }
            if (ewk->wu.type) {
                set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1] + 13);
            } else {
                set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1] + 10);
            }
        }
        disp_pos_trans_entry((WORK_Other*)ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 1;
            ewk->wu.old_rno[0] = 60;
        }
        disp_pos_trans_entry((WORK_Other*)ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_78_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff78_init_tbl[0];
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 63;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = ewk->wu.my_priority = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.char_table[0] = chn_char_table;
        ewk->wu.hit_stop = 0;
    }
    return 0;
}

/*
 * EFF05.C  Stage scenery objects, set 05 (line-scroll synchronised)
 *
 * Places the fixed decorative sprites that belong to the current stage background.
 * effect_05_init reads the per-stage object list scr_obj_num/scr_obj_data (indexed by
 * bg_w.bg_index) and creates one effect work per entry with its family, colour, position,
 * priority, animation index and line-scroll sync value.
 * effect_05_move starts the animation, draws it through disp_pos_trans_entry_s until the
 * object is retired by compel_dead_check, then frees its graphics and work.
 * Every stage BG init routine (BG000-BG190, bonus stages) calls effect_05_init.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff05.h"



void effect_05_move(WORK_Other* ewk) {
    if (obr_disp_off_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;
        case 1:
            if (compel_dead_check(ewk) != 0) {
                ewk->wu.routine_no[0]++;
                break;
            }
            disp_pos_trans_entry_s(ewk);
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}



s32 effect_05_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num[bg_w.bg_index];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_data[bg_w.bg_index];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 5;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        suzi_offset_set(ewk);
    }
    return 0;
}

/*
 * EFF48.C  Effect 48: opening demo objects
 *
 * Effect 48 objects make up scenes of the opening demo (from lose_pl and end_main). They
 * appear as op_obj_disp advances; eff48_1000 drops an object into place over 10 frames,
 * sets op_scrn_end and creates effect 36 objects. effect_48_init creates the objects of
 * eff48_adrs_tbl for a scene.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "eff36.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF48.h"



void effect_48_move(WORK_Other* ewk) {
    void (*eff48_jp[3])(WORK_Other*) = { eff48_0000, eff48_1000, eff48_0000 };
    eff48_jp[ewk->wu.routine_no[0]](ewk);
}



void eff48_0000(WORK_Other* ewk) {
    if (ewk->wu.old_rno[1] <= op_obj_disp) {
        ewk->wu.routine_no[1] = 0x63;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        if (ewk->wu.routine_no[0] == 2) {
            ewk->wu.my_col_code += ewk->wu.old_rno[2];
        }
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
    case 1:
        if (op_obj_disp) {
            ewk->wu.routine_no[1] += 1;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff48_1000(WORK_Other* ewk) {
    if (ewk->wu.old_rno[1] <= op_obj_disp) {
        ewk->wu.routine_no[1] = 0x63;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        op_scrn_end = 0;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.old_rno[3] = 10;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[3], ewk->wu.xyz[0].disp.pos, ewk->wu.old_rno[2], 2, 2);
    case 1:
        ewk->wu.old_rno[3] -= 1;
        if (ewk->wu.old_rno[3] < 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            op_scrn_end = 1;
            switch (ewk->wu.type) {
            case 16:
                effect_36_init(0x18);
                break;
            case 17:
                effect_36_init(0x19);
                break;
            case 20:
                effect_36_init(0x1A);
                break;
            case 21:
                effect_36_init(0x1B);
                break;
            }
        } else {
            add_y_sub(ewk);
        }
    case 2:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}


/* provisional name */
void eff48_dummy_1(void) {}


/* provisional name */
void eff48_dummy_2(void) {}


/* provisional name */
void eff48_dummy_3(void) {}



s32 effect_48_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;
    data_ptr = eff48_adrs_tbl[type];
    for (i = 0; i < eff48_num_tbl[type]; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 0x30;
        ewk->wu.work_id = 0x10;
        ewk->wu.type = type;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0xC0;
        ewk->wu.my_family = 3;
        ewk->wu.char_table[0] = op_char_table;
        ewk->wu.routine_no[0] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
    }
    effect_48_move(ewk);
    return 0;
}

/*
 * EFF72.C  Effect 72: occasional stage animation parts
 *
 * effect_72_init creates one of the two parts (hkg_char_table) for an effect 71 controller,
 * at two different priorities. effect_72_move plays the animation once and
 * ends.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF72.h"



void effect_72_move(WORK_Other* ewk) {
    WORK_Other* oya;
    if (obr_disp_off_check()) {
        return;
    }
    oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
    case 2:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_72_init(WORK_Other* oya, u8 type_id) {
    WORK_Other* ewk;
    s16 ix;
    if (EXE_obroll) {
        return 0;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 72;
    ewk->wu.type = type_id;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->my_master = (u32*)oya;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    ewk->wu.char_table[0] = hkg_char_table;
    ewk->wu.xyz[0].disp.pos = 511;
    ewk->wu.xyz[1].disp.pos = 0;
    if (type_id) {
        ewk->wu.position_z = ewk->wu.my_priority = 10;
        ewk->wu.char_index = 8;
    } else {
        ewk->wu.position_z = ewk->wu.my_priority = 72;
        ewk->wu.char_index = 9;
    }
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    return 0;
}

/*
 * EFF07.C  Effect 07: stage background objects (bg000)
 *
 * effect_07_init creates two animated objects from eff07_data_tbl using usa_char_table and
 * places them in the scene; effect_07_move animates them and draws them through
 * disp_pos_trans_entry_r. Created by the bg000 stage routines.
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
#include "EFF07.h"



void effect_07_move(WORK_Other* ewk) {
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
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_07_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = &eff07_data_tbl[0][0];
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 7;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 3;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.my_priority = ewk->wu.position_z = 98;
        ewk->wu.char_table[1] = (u32*)ewk;
        ewk->wu.char_table[0] = usa_char_table;
        ewk->wu.type = i;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
    }
    return 0;
}

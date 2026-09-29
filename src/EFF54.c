/*
 * EFF54.C  Effect 54: parts of the blinking stage object
 *
 * effect_54_init creates two parts for an effect 53 parent from a position table.
 * effect_54_move animates them and copies the parent's display flag, so they blink with it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF54.h"



void effect_54_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        ewk->wu.disp_flag = oya->wu.disp_flag;
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



s32 effect_54_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff29_data_tbl;
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 54;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->my_master = (u32*)oya;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = eng_char_table;
        suzi_offset_set(ewk);
    }
    return 0;
}

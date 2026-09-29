/*
 * EFF61.C  Effect 60 (flashing stage objects) and effect 61 (another-BG parts)
 *
 * effect_60_init creates a stage object from flash_obj_data61 that blinks with a fixed
 * period and animates (used by bg000 and bg050).
 * Effect 61 is a part of the alternate background (another_bg): hidden normally, it slides
 * into view vertically or horizontally while the another-BG mode is active.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF61.h"



void effect_60_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 1;
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[1]--;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.disp_flag ^= 1;
                ewk->wu.old_rno[1] = ewk->wu.old_rno[0];
                if (ewk->wu.hit_stop) {
                    char_move(&ewk->wu);
                }
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_60_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    data_ptr = flash_obj_data61[type];
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 60;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = type;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set(ewk);
    return 0;
}



void effect_61_move(WORK_Other_CONN* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    if (akebono_flag) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.be_flag = 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].pos_x_work;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
    case 1:
        if (!another_bg[0] && !another_bg[1]) {
            break;
        }
        ewk->wu.routine_no[0]++;
    case 2:
        if (!another_bg[0] && !another_bg[1]) {
            ewk->wu.routine_no[0] = 3;
            break;
        }
        switch (another_bg[mwk->type]) {
        case 1:
            if (ewk->wu.dir_old > 8) {
                break;
            }
            ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
            ((void(*)(WORK_Other* ewk, s16 step))disp_pos_trans_entry_seraph)((WORK_Other*)ewk, ewk->wu.dir_old);
            break;
        case 2:
            if (ewk->wu.dir_old <= 8) {
                break;
            }
            ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
            ewk->wu.cg_number += 32;
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4((WORK_Other*)ewk);
            break;
        case 3:
            if (ewk->wu.dir_old <= 8) {
                break;
            }
            ewk->wu.xyz[0].cal -= ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4((WORK_Other*)ewk);
            break;
        case 4:
            if (ewk->wu.dir_old > 8) {
                break;
            }
            ewk->wu.xyz[1].cal -= ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
            ewk->wu.cg_number += 32;
            ((void(*)(WORK_Other* ewk, s16 step))disp_pos_trans_entry_seraph)((WORK_Other*)ewk, ewk->wu.dir_old);
            break;
        default:
            ewk->wu.disp_flag = 0;
            break;
        }
        break;
    case 3:
        ewk->wu.routine_no[0] = 1;
        break;
    default:
        all_cgps_put_back((WORK_Other*)ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}

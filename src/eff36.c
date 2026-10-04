/*
 * EFF36.C  Opening demo sprites (effect 36)
 *
 * Picture objects used by the attract-mode opening. Each object waits until the opening
 * timeline op_w.index reaches its start index, runs until its end index, then removes
 * itself.
 * effect_36_init(typenum) reads colour, behaviour, position, priority, animation and the
 * start/end indices from eff36_data_tbl and runs the first frame at once. effect_36_move
 * selects one of seven behaviours (eff36_move00-06): slow zoom-in, still image, animated
 * image, image drifting left, pieces switched in time with the sound sequence status
 * gSeqStatus, a one-shot animation, and a stepped zoom-in.
 * Created by the opening scene routines (end_main.c), EFF48 and LOSE_PL.
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
#include "eff36.h"



void effect_36_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (ewk->wu.old_rno[1] <= op_w.index) {
            ewk->wu.routine_no[0]++;
        } else if (ewk->wu.old_rno[2] <= op_w.index) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                eff36_move00(ewk);
                break;
            case 1:
                eff36_move01(ewk);
                break;
            case 2:
                eff36_move02(ewk);
                break;
            case 3:
                eff36_move03(ewk);
                break;
            case 4:
                eff36_move04(ewk);
                break;
            case 5:
                eff36_move05(ewk);
                break;
            case 6:
                eff36_move06(ewk);
                break;
            }
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        return;
    }
}



/* provisional name */
void eff36_move00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    case 1:
        ewk->wu.my_mr.size.x += 1;
        ewk->wu.my_mr.size.y += 1;
        if (ewk->wu.my_mr.size.x >= 88) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.my_mr.size.x = 88;
            ewk->wu.my_mr.size.y = 88;
        }
        disp_pos_trans_entry5(ewk);
        break;
    }
}



/* provisional name */
void eff36_move01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    }
}



/* provisional name */
void eff36_move02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case 1:
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    }
}



/* provisional name */
void eff36_move03(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case 1:
        char_move(&ewk->wu);
        ewk->wu.xyz[0].cal -= 0x10000;
        if (ewk->wu.xyz[0].disp.pos < 288) {
            ewk->wu.routine_no[0] = 99;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



/* provisional name */
void eff36_move04(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[6] = 4;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case 1:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }
        if ((gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) && (gSeqStatus[0] != 0x74)) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x17, 0);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }
        if (gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x18, 0);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }
        if (gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x19, 0);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        disp_pos_trans_entry(ewk);
        break;
    }
}



/* provisional name */
void eff36_move05(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 255) {
            ewk->wu.routine_no[0] += 1;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



/* provisional name */
void eff36_move06(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 66;
        ewk->wu.my_mr.size.y = 66;
        disp_pos_trans_entry5(ewk);
        ewk->wu.old_rno[6] = 2;
        break;
    case 1:
        ewk->wu.old_rno[6] -= 1;
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.old_rno[6] = 2;
            ewk->wu.my_mr.size.x += 1;
            ewk->wu.my_mr.size.y += 1;
            if (ewk->wu.my_mr.size.x >= 127) {
                ewk->wu.routine_no[2] += 1;
                ewk->wu.my_mr.size.x = 127;
                ewk->wu.my_mr.size.y = 127;
            }
        }
    case 2:
        disp_pos_trans_entry5(ewk);
        break;
    }
}



s32 effect_36_init(u8 typenum) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    data_ptr = eff36_data_tbl[0] + typenum * 9;
    ewk->wu.id = 0x24;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 0x10;
    ewk->wu.type = typenum;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0xC0;
    ewk->wu.char_table[0] = op_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0xC0;
    ewk->wu.my_col_code += *data_ptr++;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    effect_36_move(ewk);
    return 0;
}

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

/* routine_no[0] */
#define R0_MOVE         0       /* run the behaviour in its time span */
#define R0_KILL         99      /* (default) put the work back */

/* routine_no[1]: behaviour, from eff36_data_tbl */
#define R1_ZOOM         0       /* slow zoom-in */
#define R1_STILL        1       /* still picture */
#define R1_ANIM         2       /* animated picture */
#define R1_DRIFT        3       /* picture drifting left */
#define R1_CUE          4       /* pieces switched by the music */
#define R1_ONCE         5       /* one-shot animation */
#define R1_STEP_ZOOM    6       /* stepped zoom-in */

/* routine_no[2], eff36_move00 */
#define R2_INIT         0       /* show and start the picture */
#define R2_ZOOM         1       /* zoom in to full size */

/* routine_no[2], eff36_move01 */
#define R2_SHOW         1       /* stay on screen */

/* routine_no[2], eff36_move02 */
#define R2_ANIM         1       /* animate */

/* routine_no[2], eff36_move03 */
#define R2_DRIFT        1       /* drift left, then retire */

/* routine_no[2], eff36_move04 */
#define R2_CUE1         1       /* flash, wait for the first music cue */
#define R2_CUE2         2       /* flash, wait for the second cue */
#define R2_CUE3         3       /* flash, wait for the third cue */
#define R2_LAST         4       /* show the last piece */

/* routine_no[2], eff36_move05 */
#define R2_ONCE         1       /* play once, then retire */

/* routine_no[2], eff36_move06 */
#define R2_GROW         1       /* grow a step every two frames */
#define R2_FULL         2       /* hold at full size */



void effect_36_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_MOVE:
        if (ewk->wu.old_rno[1] <= op_w.index) {
            ewk->wu.routine_no[0]++;
        } else if (ewk->wu.old_rno[2] <= op_w.index) {
            switch (ewk->wu.routine_no[1]) {
            case R1_ZOOM:
                eff36_move00(ewk);
                break;
            case R1_STILL:
                eff36_move01(ewk);
                break;
            case R1_ANIM:
                eff36_move02(ewk);
                break;
            case R1_DRIFT:
                eff36_move03(ewk);
                break;
            case R1_CUE:
                eff36_move04(ewk);
                break;
            case R1_ONCE:
                eff36_move05(ewk);
                break;
            case R1_STEP_ZOOM:
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



void eff36_move00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    case R2_ZOOM:
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



void eff36_move01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case R2_SHOW:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void eff36_move02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case R2_ANIM:
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    }
}



void eff36_move03(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case R2_DRIFT:
        char_move(&ewk->wu);
        ewk->wu.xyz[0].cal -= 0x10000;
        if (ewk->wu.xyz[0].disp.pos < 288) {
            ewk->wu.routine_no[0] = R0_KILL;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void eff36_move04(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[6] = 4;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case R2_CUE1:
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
    case R2_CUE2:
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
    case R2_CUE3:
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
    case R2_LAST:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void eff36_move05(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        break;
    case R2_ONCE:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 255) {
            ewk->wu.routine_no[0] += 1;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void eff36_move06(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 66;
        ewk->wu.my_mr.size.y = 66;
        disp_pos_trans_entry5(ewk);
        ewk->wu.old_rno[6] = 2;
        break;
    case R2_GROW:
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
    case R2_FULL:
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

/*
 * EFFI4MV.C  Effect I4: stage object that reacts to hits
 *
 * effect_I4_init (called from the bg130.c stage set-up) creates a chn_char_table object at
 * (832, 192) with priority 72 and starts its companion effect J6. effect_I4_move checks each
 * frame whether a player's attack touches it (eff_hit_check2): a hit from one side plays the
 * down-to-up reaction (patterns 24 and 26), a hit from the other plays the up-to-down reaction
 * (pattern 25); after the final reaction it stays in place. eff_hit_flag[1] records that it has
 * already been knocked. It is drawn relative to the scroll (disp_pos_trans_entry_r) and is
 * frozen during the obroll replay.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "effj4.h"
#include "effj5.h"
#include "effJ6.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFFI4MV.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the pattern */
#define R0_MOVE         1       /* react to hits and draw */
#define R0_STAY         2       /* knocked down: stay in place */

/* routine_no[1] */
#define R1_WAIT         0       /* wait for a hit */
#define R1_REACT        1       /* play the reaction */
#define R1_DONE         99      /* reaction over */

/* routine_no[2] */
#define R2_DOWN_TO_UP   0       /* down-to-up reaction */
#define R2_UP_TO_DOWN   1       /* up-to-down reaction */

/* routine_no[3] */
#define R3_RISE         0       /* rise; a second hit knocks it down */
#define R3_KNOCK        1       /* wait for the cue of the knock-down */
#define R3_DOWN         2       /* play the knock-down to its end */


void effi4_down_to_up(WORK_Other* ewk);

void effi4_up_to_down(WORK_Other* ewk);



void effect_I4_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        if (eff_hit_flag[1]) {
            ewk->wu.routine_no[0] = R0_STAY;
            break;
        }
        break;
    case R0_MOVE:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            effect_i4_hit_sub(ewk);
        }
    case R0_STAY:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effect_i4_hit_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_WAIT:
        if (eff_hit_check2(ewk, 0, 2)) {
            set_char_move_init(&ewk->wu, 0, 25);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = R2_UP_TO_DOWN;
            ewk->wu.routine_no[3] = R3_RISE;
            break;
        }
        if (eff_hit_check2(ewk, 0, 0)) {
            set_char_move_init(&ewk->wu, 0, 24);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = R2_DOWN_TO_UP;
            ewk->wu.routine_no[3] = R3_RISE;
        }
        break;
    case R1_REACT:
        if (ewk->wu.routine_no[2]) {
            effi4_up_to_down(ewk);
            break;
        }
        effi4_down_to_up(ewk);
        break;
    }
}



/* provisional name */
void effi4_down_to_up(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[3]) {
    case R3_RISE:
        char_move(&ewk->wu);
        if (!ewk->wu.cg_type) {
            break;
        }
        ewk->wu.type = 2;
        if (eff_hit_check2(ewk, 0, 2)) {
            ewk->wu.routine_no[3]++;
            break;
        }
        if (ewk->wu.cg_type == 0xFF) {
            eff_hit_flag[1] = 0;
            ewk->wu.routine_no[1] = R1_WAIT;
            ewk->wu.type = 1;
        }
        break;
    case R3_KNOCK:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[3]++;
            set_char_move_init(&ewk->wu, 0, 26);
        }
        break;
    case R3_DOWN:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = R1_DONE;
            ewk->wu.routine_no[0] = R0_STAY;
        }
        break;
    }
}



/* provisional name */
void effi4_up_to_down(WORK_Other* ewk) {
    char_move(&ewk->wu);
    if (ewk->wu.cg_type == 0xFF) {
        ewk->wu.routine_no[1] = R1_DONE;
        ewk->wu.routine_no[0] = R0_STAY;
    }
}



s32 effect_I4_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 184;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = 1;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    ewk->wu.char_table[0] = chn_char_table;
    ewk->wu.xyz[0].disp.pos = 832;
    ewk->wu.xyz[1].disp.pos = 192;
    ewk->wu.my_priority = ewk->wu.position_z = 72;
    ewk->wu.char_index = 5;
    ewk->wu.routine_no[1] = R1_WAIT;
    effect_J6_init(ewk);
    return 0;
}

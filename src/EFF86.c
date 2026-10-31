/*
 * EFF86.C  Effect 86: one-shot object placed between the players
 *
 * effect_86_init takes a type and reads its parameters from eff86_adrs_tbl (sub-state, family,
 * colour code, position, priority, character index; etc_char_table). It is spawned by appear.c
 * when the player 1 entrance lands. effect_86_move places the object midway between the two
 * players' x positions, plays its pattern once, then releases its graphics and frees the work.
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
#include "EFF86.h"

/* routine_no[0] */
#define R0_MOVE         0       /* run the type's routine and draw */
#define R0_KILL         1       /* (default) put the work back */

/* routine_no[2] */
#define R2_INIT         0       /* place between the players and show */
#define R2_MOVE         1       /* play the pattern once */



/* 02006D88 */
const s16* eff86_adrs_tbl[1] = {
    eff86_data_tbl00,
};


void effect_86_move(WORK_Other* ewk) {
    void (*eff86_jp_tbl[1])(WORK_Other*) = { eff86_0000 };
    switch (ewk->wu.routine_no[0]) {
    case R0_MOVE:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff86_jp_tbl[ewk->wu.routine_no[1]](ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff86_0000(WORK_Other* ewk) {
    s16 mid;
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        mid = plw[0].wu.position_x + plw[1].wu.position_x;
        mid >>= 1;
        ewk->wu.xyz[0].disp.pos = mid;
        mid = plw[1].wu.position_y + plw[1].wu.position_y;
        mid >>= 1;
        ewk->wu.xyz[1].disp.pos = mid + 92;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R2_MOVE:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
        }
        break;
    }
}



s32 effect_86_init(s16 type86) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    data_ptr = eff86_adrs_tbl[type86];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 86;
    ewk->wu.work_id = 16;
    ewk->wu.type = type86;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.dead_f = 1;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.char_table[0] = etc_char_table;
    return 0;
}

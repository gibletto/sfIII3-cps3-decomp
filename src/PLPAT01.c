/*
 * PLPAT01.C  Player 01 (Alex) special attack routines
 *
 * Character-specific attack routines for player number 1. pl01_extra_attack dispatches attack
 * routine numbers 16 and up through pl01_exatt_table.
 * Att_PL01_DDT runs the DDT throw: it lands the player, plays the grab animation, then launches
 * the jump with a height from pl01_ddt_dat chosen by the victim's character and moves the catch
 * rectangle to match.
 * Att_PL01_TOKUSHUKOUDOU is the personal action (taunt): super gauge on cg_type 40, and strike
 * and throw power boosts (tk_dageki/tk_nage, capped 12/16) on cg_type 20/30; the grade system is
 * told of the action on cg_type 64.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLS02.h"
#include "PLPAT01.h"



void pl01_extra_attack(PLW* wk) {
    pl01_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL01_DDT(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->data_ix;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            cal_initial_speed_y(&wk->wu, wk->as->r_no, pl01_ddt_dat[twk->player_number][0]);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] != 3 && wk->wu.cg_ja.caix) {
            wk->wu.cg_ja.caix = pl01_ddt_dat[twk->player_number][1];
            wk->wu.h_cat = wk->wu.cg_ja.caix + wk->wu.catch_adrs;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void Att_PL01_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        switch (wk->wu.cg_type) {
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 3;
            wk->tk_nage += 2;
            break;
        case 30:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 2;
            wk->tk_nage += 2;
            break;
        case 64:
            grade_add_personal_action(wk->wu.id);
            break;
        }
        if (wk->tk_dageki > 12) {
            wk->tk_dageki = 12;
        }
        if (wk->tk_nage > 16) {
            wk->tk_nage = 16;
        }
        break;
    }
}

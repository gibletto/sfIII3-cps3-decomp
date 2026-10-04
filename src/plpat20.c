/*
 * plpat20.c  Character 20 (Remy) special attack routines
 *
 * The entry routine pl20_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl20_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * Att_PL20_AT1..AT3 are moves driven by step-by-step motion data read at each animation marker,
 * and Att_PL20_TOKUSHUKOUDOU is the personal action, which adds super art gauge and raises the
 * stun bonus (tk_kizetsu, capped at 24).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "plpat20.h"


void pl20_extra_attack(PLW* wk) {
    pl20_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL20_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        switch ((u8)wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 25:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 30:
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        case 35:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            goto out;
        }
    out:
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        if ((u8)wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 1;
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_PL20_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        wk->wu.mvxy.index++;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 4);
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        if (wk->wu.routine_no[3] == 4) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = 0;
        }
        break;
    case 4:
        wk->wu.routine_no[3]++;
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
    case 5:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            reset_mvxy_data(&wk->wu);
        }
        break;
    default:
        char_move(&wk->wu);
    }
}



void Att_PL20_AT3(PLW* wk) {
    PLW* emwk;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data((WORK*)wk);
        emwk = (PLW*)wk->wu.target_adrs;
        if (emwk->wu.hit_mark_y < 32) {
            set_char_move_init((WORK*)wk, 5, 55);
            return;
        }
        break;
    case 1:
        char_move((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        cal_mvxy_speed((WORK*)wk);
        switch ((u8)wk->wu.cg_type) {
        case 20:
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 25:
            add_to_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 30:
            setup_mvxy_data((WORK*)wk, wk->as->data_ix);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        case 35:
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            goto out;
        }
    out:
        break;
    case 2:
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        if ((u8)wk->wu.cg_type == 20) {
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 1;
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_PL20_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 64) {
            wk->wu.routine_no[3]++;
            wk->tk_kizetsu += 6;
            if (wk->tk_kizetsu > 24) {
                wk->tk_kizetsu = 24;
            }
            grade_add_personal_action(wk->wu.id);
        }
        break;
    default:
        char_move((WORK*)wk);
        break;
    }
}

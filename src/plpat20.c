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

/* routine_no[3], Att_PL20_AT1 */
#define AT1_MOVE        1       /* move and run the animation */
#define AT1_AIR         2       /* in the air until it lands */
#define AT1_CUE         3       /* run the animation to cue 20 */

/* routine_no[3], Att_PL20_AT2 */
#define AT2_MOVE        1       /* move and run the animation to cue 20 */
#define AT2_AIR         2       /* in the air until it lands */
#define AT2_AIR2        3       /* in the air until it lands */
#define AT2_SET_MOVE    4       /* set up its movement */
#define AT2_MOVE2       5       /* move and run the animation to cue 20 */

/* routine_no[3], Att_PL20_AT3 */
#define AT3_MOVE        1       /* move and run the animation */
#define AT3_AIR         2       /* in the air until it lands */
#define AT3_CUE         3       /* run the animation to cue 20 */

/* routine_no[3], Att_PL20_TOKUSHUKOUDOU */
#define TOKUSHUKOUDOU_ACTION 1  /* the personal action, filling the super art gauge */


void pl20_extra_attack(PLW* wk) {
    pl20_exatt_table[wk->wu.routine_no[2] - ATTACK_SPECIAL](wk);
}



void Att_PL20_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case AT1_MOVE:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        switch (wk->wu.cg_type) {
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
            wk->wu.routine_no[3] = AT1_AIR;
            wk->wu.cg_type = 0;
            /* fall through */
        case 35:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = AT1_AIR;
            wk->wu.cg_type = 0;
            /* fall through */
        default:
            break;
        }
        break;
    case AT1_AIR:
        jumping_union_process(&wk->wu, 3);
        break;
    case AT1_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = AT1_MOVE;
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_PL20_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        wk->wu.mvxy.index++;
        break;
    case AT2_MOVE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case AT2_AIR:
        jumping_union_process(&wk->wu, 4);
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case AT2_AIR2:
        jumping_union_process(&wk->wu, 4);
        if (wk->wu.routine_no[3] == AT2_SET_MOVE) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = 0;
        }
        break;
    case AT2_SET_MOVE:
        wk->wu.routine_no[3]++;
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        /* fall through */
    case AT2_MOVE2:
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
    case RN3_START:
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
    case AT3_MOVE:
        char_move((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        cal_mvxy_speed((WORK*)wk);
        switch (wk->wu.cg_type) {
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
            wk->wu.routine_no[3] = AT3_AIR;
            wk->wu.cg_type = 0;
            /* fall through */
        case 35:
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = AT3_AIR;
            wk->wu.cg_type = 0;
            /* fall through */
        default:
            break;
        }
        break;
    case AT3_AIR:
        jumping_union_process((WORK*)wk, 3);
        break;
    case AT3_CUE:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = AT3_MOVE;
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_PL20_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case TOKUSHUKOUDOU_ACTION:
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

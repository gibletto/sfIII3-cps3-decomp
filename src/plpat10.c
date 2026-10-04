/*
 * plpat10.c  Character 10 (Yang) special attack routines
 *
 * The entry routine pl10_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl10_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * This character has only one: Att_PL10_TOKUSHUKOUDOU, the personal action (taunt). Its animation
 * markers add to the super art gauge, raise the personal-action strike and throw bonuses
 * (tk_dageki, tk_nage, capped at 10 and 2) and score the personal action for grading.
 * Att_PL10_MACH_SLIDE is an earlier, unused slide special; Att_PL10_MACH_SLIDE2 is a second slide
 * special that slides by mvxy speed and reloads or resets the data once the opponent is reached.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "plpat10.h"
#include "PLS02.h"



void pl10_extra_attack(PLW* wk) {
    pl10_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL10_TOKUSHUKOUDOU(PLW* wk) {
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
        switch (wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            wk->tk_nage += 2;
            break;
        case 64:
            grade_add_personal_action(wk->wu.id);
            break;
        }
        if (wk->tk_dageki > 10) {
            wk->tk_dageki = 10;
        }
        if (wk->tk_nage > 2) {
            wk->tk_nage = 2;
        }
        break;
    }
}


/* provisional name */
void Att_PL10_MACH_SLIDE(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->rl_save = wk->wu.rl_flag;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }
        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;
        wk->wu.rl_flag = wk->wu.rl_waza;
        if (wk->wu.mvxy.a[0].sp) {
            if (wk->old_pos_data[0] == wk->old_pos_data[1]) {
                char_move_z(&wk->wu);
            }
        }
        switch (wk->wu.cg_type) {
        case 30:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        }
        break;
    }
}


void Att_PL10_MACH_SLIDE2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->rl_save = wk->wu.rl_flag;
        reset_mvxy_data((WORK*)wk);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] != 1) {
            add_mvxy_speed((WORK*)wk);
        }
        break;
    case 3:
        char_move((WORK*)wk);
        cal_mvxy_speed((WORK*)wk);
        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }
        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;
        if (!wk->micchaku_flag) {
            break;
        }
        char_move_z((WORK*)wk);
        if (wk->wu.cg_type == 21) {
            reset_mvxy_data((WORK*)wk);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 1;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data((WORK*)wk, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    }
}

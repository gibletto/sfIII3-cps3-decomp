/*
 * plpat16.c  Character 16 (Chun-Li) special attack routines
 *
 * The entry routine pl16_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl16_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * This character has only one: Att_PL16_TOKUSHUKOUDOU, the personal action (taunt), which adds to
 * the super art gauge and applies the personal-action bonus at its animation markers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "Grade.h"
#include "PLPAT.h"
#include "CHARSET.h"
#include "plpat16.h"


void pl16_extra_attack(PLW* wk) {
    pl16_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL16_TOKUSHUKOUDOU(PLW* wk) {
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
        case 30:
            wk->wu.cg_type = 0;
            if (wk->tk_konjyou == 0) {
                wk->tk_konjyou = 6;
            }
            break;
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;
        case 50:
            wk->wu.cg_type = 0;
            if (wk->tk_dageki < 10) {
                wk->tk_dageki = 10;
            }
            break;
        case 64:
            grade_add_personal_action(wk->wu.id);
            wk->wu.routine_no[3]++;
            if (wk->tk_success < 3) {
                s32 rc = wk->py->recover;
                wk->tk_success++;
                rc *= 110;
                wk->py->recover = rc / 100;
            }
            break;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}

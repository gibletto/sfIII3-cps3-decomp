/*
 * PLPAT02.C  Player 02 (Ryu) special attack routines
 *
 * Character-specific attack routines for player number 2. pl02_extra_attack dispatches attack
 * routine numbers 16 and up through pl02_exatt_table.
 * Att_DENJINHADOUKEN runs the charged fireball super: while the charge animation is held it
 * skips extra animation frames according to the charge count (cp->lgp, lgix_table).
 * Att_PL02_TOKUSHUKOUDOU is the personal action: super gauge on cg_type 40 and, up to three
 * times, a 10% increase of the stun recovery rate (py->recover) on cg_type 64.
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
#include "PLPAT02.h"


void pl02_extra_attack(PLW* wk) {
    pl02_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_DENJINHADOUKEN(PLW* wk) {
    s16 i;
    s16 lgix;
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.now_koc == 8 && wk->wu.char_index == 13) {
            if (wk->cp->lgp > 13) {
                lgix = 5;
            } else {
                lgix = lgix_table[wk->cp->lgp / 2];
            }
            if (lgix) {
                for (i = 0; i < lgix; i++) {
                    char_move((WORK*)wk);
                }
            }
        }
        break;
    }
}



void Att_PL02_TOKUSHUKOUDOU(PLW* wk) {
    s32 t;
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
            if (wk->tk_success <= 2) {
                wk->tk_success++;
                t = wk->py->recover;
                t *= 110;
                wk->py->recover = t / 100;
                grade_add_personal_action(wk->wu.id);
            }
        }
        break;
    default:
        char_move((WORK*)wk);
        break;
    }
}

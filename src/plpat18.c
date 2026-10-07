/*
 * plpat18.c  Character 18 (Q) special attack routines
 *
 * The entry routine pl18_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl18_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * Att_PL18_NINGENBAKUDAN is the self-damaging move: at its marker it copies the move's own attack
 * data into the player's damage fields and switches him into the damage routine, so he takes the
 * hit himself. Att_PL18_TOKUSHUKOUDOU is the personal action.
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
#include "plpat18.h"


void pl18_extra_attack(PLW* wk) {
    pl18_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL18_NINGENBAKUDAN(PLW* wk) {
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
        if (wk->wu.cg_type == 50) {
            wk->wu.routine_no[1] = 1;
            wk->wu.routine_no[2] = 91;
            wk->wu.routine_no[3] = 0;
            wk->wu.dm_vital = 0;
            wk->sa->gauge.i = wk->sa->dtm * wk->sa->dtm_mul;
            if (Bonus_Game_Flag == 21) {
                wk->wu.dm_rl = (wk->wu.rl_flag + 1) & 1;
            } else {
                wk->wu.dm_rl = ((PLW*)wk->wu.target_adrs)->wu.rl_flag;
            }
            wk->wu.dm_attlv = wk->wu.att.level;
            wk->wu.dm_impact = wk->wu.att.impact;
            wk->wu.dm_dir = wk->wu.dir_atthit;
            wk->wu.dm_stop = 1;
            wk->wu.dm_quake = 1;
            if (wk->wu.dm_quake < 0) {
                wk->wu.dm_quake = -wk->wu.dm_quake;
            }
            wk->wu.dm_weight = wk->wu.weight_level;
            wk->wu.dm_butt_type = wk->wu.att.but_ix;
            wk->wu.dm_zuru = wk->wu.att_zuru;
            wk->wu.dm_attribute = wk->wu.at_attribute;
            wk->wu.dm_ten_ix = wk->wu.at_ten_ix;
            wk->wu.dm_koa = wk->wu.at_koa;
            wk->wu.hm_dm_side = wk->wu.att.dmg_mark;
            wk->wu.dm_work_id = wk->wu.work_id;
            wk->wu.dm_arts_point = 0;
            wk->wu.dm_kind_of_waza = wk->wu.kind_of_waza;
            wk->wu.dm_nodeathattack = wk->wu.no_death_attack;
            wk->wu.dm_jump_att_flag = wk->wu.jump_att_flag;
            wk->wu.dm_exdm_ix = wk->exdm_ix;
            wk->wu.dm_plnum = wk->player_number;
            wk->wu.meoshi_hit_flag = 1;
        }
        break;
    }
}



void Att_PL18_TOKUSHUKOUDOU(PLW* wk) {
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
            wk->tk_konjyou += 4;
            if (wk->tk_konjyou > 12) {
                wk->tk_konjyou = 12;
            }
        }
        if (wk->wu.cg_type == 64) {
            grade_add_personal_action(wk->wu.id);
            wk->wu.routine_no[3]++;
            if (wk->tk_success > 0) {
                break;
            }
            wk->tk_success++;
            wk->py->recover = wk->py->recover * 120 / 100;
        }
        break;
    default:
        char_move((WORK*)wk);
        break;
    }
}

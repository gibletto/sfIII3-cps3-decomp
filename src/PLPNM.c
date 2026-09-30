/*
 * PLPNM.C  Player normal (free movement) process
 *
 * Player_normal runs a player who is not attacking, damaged or throwing: standing, walking,
 * crouching, jumping, dashing, turning and the like. setup_normal_process_flags clears the
 * per-frame guard, throw, parry and cancel flags, the combo power counters are checked, and the
 * routine for routine_no[2] is dispatched through the normal routine table; the draw priority
 * is then set relative to the opponent when the animation asks for it.
 * Normal_00000 is the entry routine that runs appear_player for the round introduction;
 * Normal_01000 is the standing routine.
 * Called from the player main routine (PLMAIN/PLMAIN2).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS01.h"
#include "appear.h"
#include "PLPNM.h"
#include "CHARSET.h"
#include "CHARMOVE.h"



void Player_normal(wk)
PLW* wk;
{
    setup_normal_process_flags(wk);
    check_my_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    check_em_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    plpnm_lv_00[wk->wu.routine_no[2]](wk);
    if (wk->wu.cg_prio) {
        wk->wu.next_z = ((WORK*)wk->wu.target_adrs)->my_priority;
        if (wk->wu.cg_prio == 1) {
            wk->wu.next_z++;
        } else {
            wk->wu.next_z -= 3;
        }
    }
}



void setup_normal_process_flags(PLW* wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->py->flag = 0;
    wk->guard_flag = 0;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 0;
    wk->scr_pos_set_flag = 1;
    wk->dm_hos_flag = 0;
    wk->ukemi_success = 0;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    wk->sa_stop_flag = 0;
    wk->atemi_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->ukemi_success = 0;
    wk->ukemi_ok_timer = 0;
    wk->uot_cd_ok_flag = 0;
    wk->cancel_timer = 0;
    wk->hazusenai_flag = 0;
    wk->cat_break_reserve = 0;
    wk->cmd_request = 0;
    wk->hsjp_ok = 0;
    if (wk->wu.routine_no[2] != 17) {
        wk->high_jump_flag = 0;
    }
}



void Normal_00000(PLW* wk) {
    appear_player(wk);
}


void Normal_01000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 0);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}

/*
 * PLCNT3.C  Player control for the second bonus stage type
 *
 * Player_control_bonus2 is the per-frame player control of the second bonus stage type, called from
 * Game_Main: it runs the bonus control phase (plcnt_b2_move, plcnt_b2_die), touch and push-back
 * checks, stores the afterimage history (zanzou_store) and draws the players.
 * plcnt_b2_move moves the players and switches to the end phase on time up or stage end.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Manage.h"
#include "PLCNTSET.h"
#include "PLS02.h"
#include "PLCNT2.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "bg_sub.h"
#include "PLCNT3.h"

#pragma inline(zanzou_store)

/* provisional name */
static void zanzou_store(ZanzouTableEntry* zt, PLW* wk) {
    zt->pos_x = wk->wu.position_x;
    zt->pos_y = wk->wu.position_y;
    zt->pos_z = wk->wu.position_z;
    zt->cg_num = wk->wu.cg_number;
    zt->renew = wk->wu.renew_attack;
    zt->hit_ix = wk->wu.cg_hit_ix;
    zt->flip = wk->wu.rl_flag;
    zt->cg_flp = wk->wu.cg_flip;
    zt->kowaza = wk->wu.kind_of_waza;
}



/* provisional name */
s32 Player_control_bonus2(void) {
    s16 i;
    pl_eff_disp_stop = 0;
    if (((pcon_rno[0] + pcon_rno[1]) == 0) || (!Game_pause && !EXE_flag)) {
        pcon_timer++;
        pcon_timer &= 0x7FFF;
        player_bonus2_process[pcon_rno[0]]();
        check_body_touch2();
        check_damage_hosei_bonus();
        set_quake(&plw[0]);
        set_quake(&plw[1]);
        if (plw[0].zuru_flag == 0 && plw[0].zettai_muteki_flag == 0) {
            hit_push_request(&plw[0].wu);
        }
        if (plw[1].zuru_flag == 0 && plw[1].zettai_muteki_flag == 0) {
            hit_push_request(&plw[1].wu);
        }
        add_next_position(plw);
        add_next_position(&plw[1]);
        check_cg_zoom();
    }
    for (i = 47; i > 0; i--) {
        zanzou_table[0][i] = zanzou_table[0][i - 1];
        zanzou_table[1][i] = zanzou_table[1][i - 1];
    }
    zanzou_store(zanzou_table[0], &plw[0]);
    zanzou_store(zanzou_table[1], &plw[1]);
    if (pl_eff_disp_stop == 0) {
        sort_push_request((WORK_Other*)&plw[0]);
        sort_push_request((WORK_Other*)&plw[1]);
    }
    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 1;
    }
    return 0;
}



void plcnt_b2_move(void) {
    if (((u8)No_Death)) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    move_player_work_bonus();
    if (Bonus_Stage_RNO[0] == 2) {
        Time_Stop = 1;
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }
    if (Time_Over) {
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }
}



void plcnt_b2_die(void) {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
    case 1:
        if (footwork_check_bns(0) && footwork_check_bns(1)) {
            pcon_rno[2]++;
        }
        break;
    case 2:
        complete_victory_pause();
        if (plw[0].wu.operator) {
            plw[0].wu.routine_no[2] = 40;
            plw[0].wu.routine_no[3] = 0;
        } else {
            plw[0].wu.routine_no[3] = 9;
        }
        if (plw[1].wu.operator) {
            plw[1].wu.routine_no[2] = 40;
            plw[1].wu.routine_no[3] = 0;
        } else {
            plw[1].wu.routine_no[3] = 9;
        }
        plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        pcon_rno[2]++;
        break;
    case 3:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }
        break;
    }
    move_player_work_bonus();
}

/*
 * PLCNT3.C  Player control for the second bonus stage type
 *
 * Player_control_bonus2 is the per-frame player control of the second bonus stage type, called from
 * Game_Main: it runs the bonus control phase (plcnt_b2_move, plcnt_b2_die), touch and push-back
 * checks, stores the afterimage history and draws the players.
 * plcnt_b2_move moves the players and switches to the end phase on time up or stage end.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Manage.h"
#include "manage_2.h"
#include "PLCNTSET.h"
#include "plcntset_2.h"
#include "PLS02.h"
#include "PLCNT2.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "PLCNT3.h"

/* provisional name */
s32 Player_control_bonus2(void) {
    s16 i;
    pl_eff_disp_stop = 0;
    if (((pcon_rno[0] + pcon_rno[1]) == 0) || (!Game_pause && EXE_flag == 0)) {
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
        continue;
    }
    zanzou_table[0]->pos_x = plw[0].wu.position_x;
    zanzou_table[0]->pos_y = plw[0].wu.position_y;
    zanzou_table[0]->pos_z = plw[0].wu.position_z;
    zanzou_table[0]->cg_num = plw[0].wu.cg_number;
    zanzou_table[0]->renew = plw[0].wu.renew_attack;
    zanzou_table[0]->hit_ix = plw[0].wu.cg_hit_ix;
    zanzou_table[0]->flip = plw[0].wu.rl_flag;
    zanzou_table[0]->cg_flp = plw[0].wu.cg_flip;
    zanzou_table[0]->kowaza = plw[0].wu.kind_of_waza;
    zanzou_table[1]->pos_x = plw[1].wu.position_x;
    zanzou_table[1]->pos_y = plw[1].wu.position_y;
    zanzou_table[1]->pos_z = plw[1].wu.position_z;
    zanzou_table[1]->cg_num = plw[1].wu.cg_number;
    zanzou_table[1]->renew = plw[1].wu.renew_attack;
    zanzou_table[1]->hit_ix = plw[1].wu.cg_hit_ix;
    zanzou_table[1]->flip = plw[1].wu.rl_flag;
    zanzou_table[1]->cg_flp = plw[1].wu.cg_flip;
    zanzou_table[1]->kowaza = plw[1].wu.kind_of_waza;
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

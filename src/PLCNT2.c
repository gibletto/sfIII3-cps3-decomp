/*
 * PLCNT2.C  Player control for the bonus stage
 *
 * Player_control_bonus is the per-frame player control during a bonus stage, called from Game_Main.
 * It runs the player_bonus_process phase (plcnt_b_init, plcnt_b_move, plcnt_b_die), body touch and
 * push-back (check_damage_hosei_bonus), quake and hit requests for both players.
 * plcnt_b_init clears and sets up both player works and waits until both are ready and the battle
 * is allowed. move_player_work_bonus and the move_Px_move_Py_bonus helpers run Player_move_bonus
 * for both players in the right order; setup_bs_scrrrl_bs sets their screen facing.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Manage.h"
#include "manage_2.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "PLMAIN2.h"
#include "PLCNTSET.h"
#include "plcntset_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "ta_sub.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "PLS01.h"
#include "PLPDM.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLCNT2.h"

void move_P1_move_P2_bonus(s16* field_work);

void move_P2_move_P1_bonus(s16* field_work);



s32 Player_control_bonus(void) {
    s16 i;
    pl_eff_disp_stop = 0;
    if (pcon_rno[0] + pcon_rno[1] == 0 || (!Game_pause && EXE_flag == 0)) {
        pcon_timer++;
        pcon_timer &= 0x7FFF;
        player_bonus_process[pcon_rno[0]]();
        check_body_touch();
        check_damage_hosei_bonus();
        set_quake(&plw[0]);
        set_quake(&plw[1]);
        if ((plw[0].zuru_flag == 0) && (plw[0].zettai_muteki_flag == 0)) {
            hit_push_request((WORK*)&plw[0]);
        }
        if ((plw[1].zuru_flag == 0) && (plw[1].zettai_muteki_flag == 0)) {
            hit_push_request((WORK*)&plw[1]);
        }
        add_next_position(&plw[0]);
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
        sort_push_request(&plw[0]);
        sort_push_request(&plw[1]);
    }
    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 1;
    }
    return 0;
}



void plcnt_b_init(void) {
    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1] = 2;
        work_init_zero((s32*)&plw[0], sizeof(PLW));
        work_init_zero((s32*)&plw[1], sizeof(PLW));
        setup_base_and_other_data();
        pcon_dp_flag = 0;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;
        clear_super_arts_point(&plw[0]);
        clear_super_arts_point(&plw[1]);
        break;
    case 1:
        if (plw[0].wu.routine_no[0] != 3) {
            break;
        }
        if (plw[1].wu.routine_no[0] != 3) {
            break;
        }
        if (!Allow_a_battle_f) {
            break;
        }
        pcon_rno[0] = 1;
        pcon_rno[1] = 0;
        plw[0].wu.routine_no[0] = 4;
        plw[1].wu.routine_no[0] = 4;
        ca_check_flag = 1;
        break;
    case 2:
        pcon_rno[1] = 3;
        if (Bonus_Game_Flag == 22) {
            setup_bs_scrrrl_bs();
        }
        load_char_gfx(0xB2F8, 1);
        load_any_color(0x83);
        if (Bonus_Game_Flag == 21) {
            load_char_gfx(0xB498, 1);
        }
        if (plw[0].wu.operator) {
            paring_ctr_vs[0][0] = ((s8)paring_ctr_ori[0]);
        } else {
            paring_ctr_vs[0][0] = 0;
        }
        if (plw[1].wu.operator) {
            paring_ctr_vs[0][1] = ((s8)paring_ctr_ori[1]);
        } else {
            paring_ctr_vs[0][1] = 0;
        }
        break;
    case 3:
        pcon_rno[1] = 1;
        pli_3000();
        break;
    }
    move_player_work_bonus();
}



void plcnt_b_move(void) {
    if (No_Death) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    move_player_work_bonus();
    if (aiuchi_flag) {
        subtract_dm_vital_aiuchi(&plw[0]);
        subtract_dm_vital_aiuchi(&plw[1]);
        if ((plw[0].dead_flag != 0) && (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 2;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 4;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        } else if ((plw[0].dead_flag != 0) || (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 4;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 8;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        }
    }
    if (Bonus_Stage_RNO[0] == 2) {
        pcon_rno[0] = 2;
    }
}



void plcnt_b_die(void) {
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
        plw[0].wu.routine_no[2] = 40;
        plw[1].wu.routine_no[2] = 40;
        plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
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

s32 footwork_check_bns(char pl)
{
    s16 result;
    result = 0;
    if (Bonus_Game_Flag == 21 && plw[pl].wu.operator == 0) {
        return 1;
    }
    if (plw[pl].wu.routine_no[1] == 0) {
        if (plw[pl].wu.routine_no[2] == 1) {
            result = 1;
        }
    }
    return result;
}



void setup_bs_scrrrl_bs(void) {
    s16 scrc = 512;
    switch (plw[0].wu.operator + (plw[1].wu.operator * 2)) {
    case 1:
        bs_scrrrl[0][0] = scrc + bsmr_range_table[1][0][0];
        {
            s16* d = &bs_scrrrl[0][1];
            const s16* q = &bsmr_range_table[1][0][1];
            *d = scrc - *q;
        }
        bs_scrrrl[1][0] = scrc + bsmr_range_table[1][1][0];
        bs_scrrrl[1][1] = scrc - bsmr_range_table[1][1][1];
        break;
    case 2:
        bs_scrrrl[0][0] = scrc + bsmr_range_table[2][0][0];
        {
            s16* d = &bs_scrrrl[0][1];
            const s16* q = &bsmr_range_table[2][0][1];
            *d = scrc - *q;
        }
        bs_scrrrl[1][0] = scrc + bsmr_range_table[2][1][0];
        bs_scrrrl[1][1] = scrc - bsmr_range_table[2][1][1];
        break;
    default:
        bs_scrrrl[0][0] = scrc + bsmr_range_table[0][0][0];
        {
            s16* d = &bs_scrrrl[0][1];
            const s16* q = &bsmr_range_table[0][0][1];
            *d = scrc - *q;
        }
        bs_scrrrl[1][0] = scrc + bsmr_range_table[0][1][0];
        bs_scrrrl[1][1] = scrc - bsmr_range_table[0][1][1];
        break;
    }
}



void setup_bs_scrrrl_bs2(void) {
    s16 scrc = get_center_position();
    bs_scrrrl[0][0] = scrc + 192;
    bs_scrrrl[0][1] = scrc - 192;
    bs_scrrrl[1][0] = bs_scrrrl[0][0];
    bs_scrrrl[1][1] = bs_scrrrl[0][1];
}



void move_player_work_bonus(void) {
    ichikannkei = check_work_position(&plw->wu, &plw[1].wu);
    set_rl_waza(&plw[0]);
    set_rl_waza(&plw[1]);
    Timer_Freeze = 0;
    if (Bonus_Game_Flag == 21) {
        setup_bs_scrrrl_bs2();
    }
    switch (plw[0].tsukami_f + (plw[1].tsukami_f * 2)) {
    case 1:
        move_P1_move_P2_bonus(*bs_scrrrl);
        return;
    case 2:
        move_P2_move_P1_bonus(*bs_scrrrl);
        return;
    }
    if (plw->wu.operator) {
        move_P1_move_P2_bonus(*bs_scrrrl);
        return;
    }
    move_P2_move_P1_bonus(*bs_scrrrl);
}



void move_P1_move_P2_bonus(s16* field_work) {
    Player_move_bonus(&plw[0], sw_to_lvbt(p1sw_0));
    if (set_field_hosei_flag(&plw[0], field_work[0], 1) != 0) {
        set_field_hosei_flag(&plw[0], field_work[1], 0);
    }
    Player_move_bonus(&plw[1], sw_to_lvbt(p2sw_0));
    if (set_field_hosei_flag(&plw[1], field_work[2], 1) != 0) {
        set_field_hosei_flag(&plw[1], field_work[3], 0);
    }
    if (Bonus_Game_Flag == 21) {
        plw[1].wu.disp_flag = 0;
    }
}



void move_P2_move_P1_bonus(s16* field_work) {
    Player_move_bonus(&plw[1], sw_to_lvbt(p2sw_0));
    if (set_field_hosei_flag(&plw[1], field_work[2], 1) != 0) {
        set_field_hosei_flag(&plw[1], field_work[3], 0);
    }
    Player_move_bonus(&plw[0], sw_to_lvbt(p1sw_0));
    if (set_field_hosei_flag(&plw[0], field_work[0], 1) != 0) {
        set_field_hosei_flag(&plw[0], field_work[1], 0);
    }
    if (Bonus_Game_Flag == 21) {
        plw[0].wu.disp_flag = 0;
    }
}



void check_damage_hosei_bonus(void) {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;
    switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
    case 1:
        if (plw[0].tsukami_f && plw[0].kind_of_catch == 1) {
        } else if ((plw[0].tsukamare_f | plw[0].dm_hos_flag) == 0) {
            break;
        }
    one:
        plw[1].wu.xyz[0].disp.pos += plw[0].hosei_amari;
        plw[1].muriyari_ugoku += plw[0].hosei_amari;
        break;
    case 2:
        if (plw[1].tsukami_f && plw[1].kind_of_catch == 1) {
        } else if ((plw[1].tsukamare_f | plw[1].dm_hos_flag) == 0) {
            break;
        }
    two:
        plw[0].wu.xyz[0].disp.pos += plw[1].hosei_amari;
        plw[0].muriyari_ugoku += plw[1].hosei_amari;
        break;
    case 3:
        if (plw[0].hos_fi_flag == plw[1].hos_fi_flag) {
            if (plw[0].tsukamare_f) {
                goto one;
            }
            if (plw[1].tsukamare_f) {
                goto two;
            }
        }
        break;
    }
    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}

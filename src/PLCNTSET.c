/*
 * PLCNTSET.C  Player control fight phases, settlement and push-back
 *
 * plcnt_move is the fight phase of player control: it moves both players (move_player_work,
 * calling Player_move in the right order), checks time over and KO (time_over_check, will_die,
 * settle_check) and enters the settle phase with setup_settle_rno.
 * plcnt_die runs the settle types (settle_type_00000 - 60000) that play the KO, double KO or
 * time-over finish, grade the round and set Next_Step.
 * check_damage_hosei resolves the push-back left over between the two players, with separate
 * rules for throws and strikes. check_sa_resurrection / check_sa_type_rebirth handle rebirth-type super
 * arts. set_quake and add_next_position are shared with the bonus control and effects.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SLOWF.h"
#include "Manage.h"
#include "PLMAIN.h"
#include "PLS02.h"
#include "effd3.h"
#include "Grade.h"
#include "ta_sub.h"
#include "PLS01.h"
#include "PLPNM.h"
#include "PLPDM.h"
#include "PLCNTSET.h"
#include "fighter.h"

#pragma inline(move_P1_move_P2, move_P2_move_P1)



void plcnt_move(void) {
    if (time_over_check() != 0) {
        return;
    }
    if (((u8)No_Death)) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    move_player_work();
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
    settle_check();
    if (pcon_rno[0] == 2) {
        if (Round_Result & 0x980) {
            if ((Round_Result & 0x800) && gouki_wins) {
                effect_D3_init(1);
            } else {
                effect_D3_init(0);
            }
        }
        if ((plw[0].kezurijini_flag == 1) || (plw[1].kezurijini_flag == 1)) {
            Round_Result |= 0x200;
        }
        if (Winner_id != Loser_id) {
            grade_store_vitality(Winner_id + 0);
        }
    }
    grade_check_tairyokusa();
}



void plcnt_die(void) {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    settle_process[pcon_rno[1]]();
    move_player_work();
    if (pcon_rno[1] == 3) {
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 0;
    }
}



void settle_type_00000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wu.dir_timer = 60;
        pcon_rno[2]++;
    case 1:
        if (nekorobi_check(Loser_id)) {
            pcon_rno[2]++;
            plw[Winner_id].wkey_flag = 1;
        }
        if (--plw[Winner_id].wu.dir_timer != 0) {
            break;
        }
        plw[Winner_id].wkey_flag = 1;
        break;
    case 2:
        if (footwork_check(Winner_id)) {
            grade_set_round_result(Winner_id);
            if (Special_Settle) {
                pcon_rno[1] = 5;
                pcon_rno[2] = 0;
                break;
            }
            pcon_rno[2]++;
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Winner_id].wu.routine_no[3] = 0;
            plw[Loser_id].wu.routine_no[1] = 0;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[Loser_id].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
            complete_victory_pause();
            if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
            }
        }
        break;
    case 3:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }
        break;
    }
}



void settle_type_10000(void) {
    switch (pcon_rno[2]) {
    case 0:
        if (nekorobi_check(0) && nekorobi_check(1)) {
            pcon_rno[2]++;
        }
        break;
    case 1:
        complete_victory_pause();
        pcon_rno[2]++;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        if (bg_w.stage == 8 && bg_w.area == 0) {
            plw[0].wu.routine_no[1] = 0;
            plw[0].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = 0;
            plw[1].wu.routine_no[1] = 0;
            plw[1].wu.routine_no[2] = 41;
            plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        }
        if (plw[0].wu.operator == 0 && plw[0].player_number == PL_GILL) {
            Gill_Pos_X = plw[0].wu.xyz[0].disp.pos;
        }
        if (plw[1].wu.operator == 0 && plw[1].player_number == PL_GILL) {
            Gill_Pos_X = plw[1].wu.xyz[0].disp.pos;
        }
        break;
    }
}



void settle_type_20000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
    case 1:
        if (footwork_check(0) && footwork_check(1)) {
            pcon_rno[2]++;
            if (plw[0].wu.operator == 0 && plw[0].player_number == PL_GILL) {
                Gill_Pos_X = plw[0].wu.xyz[0].disp.pos;
            }
            if (plw[1].wu.operator == 0 && plw[1].player_number == PL_GILL) {
                Gill_Pos_X = plw[1].wu.xyz[0].disp.pos;
            }
        }
        break;
    case 2:
        complete_victory_pause();
        if (plw[0].wu.vital_new == plw[1].wu.vital_new) {
            pcon_rno[2] = 4;
            return;
        }
        grade_set_round_result(Winner_id);
        plw[Winner_id].wu.routine_no[2] = 40;
        plw[Loser_id].wu.routine_no[2] = 41;
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
}



void settle_type_30000(void) {
    switch (pcon_rno[2]) {
    case 0:
        break;
    case 1:
        if ((Event_Judge_Gals == -1) && Complete_Judgement != 0) {
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            grade_set_round_result(Winner_id + 0);
            complete_victory_pause();
            pcon_rno[2]++;
            if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
            }
        }
        break;
    case 2:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }
        break;
    }
}



void settle_type_40000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wkey_flag = 1;
        pcon_rno[2]++;
    case 1:
        if (nekorobi_check(Loser_id) != 0) {
            pcon_rno[2]++;
        case 2:
            if (footwork_check(Winner_id)) {
                pcon_rno[2]++;
                plw[Winner_id].wu.routine_no[2] = 40;
                plw[Winner_id].wu.routine_no[3] = 0;
                plw[Loser_id].wu.routine_no[1] = 0;
                plw[Loser_id].wu.routine_no[2] = 41;
                plw[Loser_id].wu.routine_no[3] = 0;
                plw[Winner_id].wu.cg_type = 0;
                grade_set_round_result(Winner_id + 0);
                plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
                plw[Winner_id].wu.dir_timer = 60;
                if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                    Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
                }
                set_conclusion_slow();
                return;
            }
        }
        break;
    case 3:
        if (--plw[Winner_id].wu.dir_timer <= 0) {
            if (Special_Settle) {
                pcon_rno[2] = 10;
            } else {
                complete_victory_pause();
                pcon_rno[2]++;
            }
        }
        break;
    case 4:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }
        break;
    case 10:
        complete_victory_pause();
        pcon_rno[2]++;
        break;
    case 11:
        if (Special_Settle & 0x80) {
            pcon_rno[1] = 6;
            pcon_rno[2] = 0;
        }
        break;
    }
}



/* provisional name */
void settle_type_50000(void) {
    switch (pcon_rno[2]) {
    case 0:
        setup_normal_process_flags(&plw[Loser_id]);
        complete_victory_pause();
        pcon_rno[2]++;
        break;
    case 1:
        if (Special_Settle & 0x80) {
            pcon_rno[2]++;
            plw[Loser_id].wu.routine_no[1] = 0;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[Loser_id].wu.routine_no[3] = 0;
            plw[Winner_id].do_not_move = 1;
            grade_set_round_result(Winner_id + 0);
            bg_stop = 1;
        }
        break;
    case 2:
        if (plw[Loser_id].wu.routine_no[3] >= 2) {
            pcon_rno[2]++;
            Next_Step = 1;
        }
        break;
    }
}



/* provisional name */
void settle_type_60000(void) {
    switch (pcon_rno[2]) {
    case 0:
        pcon_rno[2]++;
        plw[Loser_id].wu.routine_no[1] = 0;
        plw[Loser_id].wu.routine_no[2] = 41;
        plw[Loser_id].wu.routine_no[3] = 0;
        plw[Winner_id].do_not_move = 1;
        grade_set_round_result(Winner_id);
        break;
    case 1:
        if (plw[Loser_id].wu.routine_no[3] >= 2) {
            pcon_rno[2]++;
            Next_Step = 1;
            bg_stop = 0;
        }
        break;
    }
}



void move_player_work(void) {
    ichikannkei = check_work_position(&plw[0].wu, &plw[1].wu);
    set_rl_waza(&plw[0]);
    set_rl_waza(&plw[1]);
    Timer_Freeze = 0;
    switch (plw[0].tsukami_f + (plw[1].tsukami_f * 2)) {
    case 1:
        ((void(*)())move_P1_move_P2)();
        break;
    case 2:
        ((void(*)())move_P2_move_P1)();
        break;
    default:
        switch (plw[0].wu.operator + (plw[1].wu.operator * 2)) {
        case 1:
            ((void(*)())move_P1_move_P2)();
            break;
        case 2:
            ((void(*)())move_P2_move_P1)();
            break;
        default:
            switch ((plw[0].wu.routine_no[1] == 4) + ((plw[1].wu.routine_no[1] == 4) * 2)) {
            case 1:
                ((void(*)())move_P1_move_P2)();
                break;
            case 2:
                ((void(*)())move_P2_move_P1)();
                break;
            default:
                if (Game_timer & 1) {
                    ((void(*)())move_P1_move_P2)();
                    break;
                }
                ((void(*)())move_P2_move_P1)();
                break;
            }
            break;
        }
        break;
    }
}



void move_P1_move_P2(void) {
    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], sw_to_lvbt(p1sw_0));
    }
    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }
    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], sw_to_lvbt(p2sw_0));
    }
    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }
}


void move_P2_move_P1(void) {
    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], sw_to_lvbt(p2sw_0));
    }
    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }
    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], sw_to_lvbt(p1sw_0));
    }
    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }
}



void check_damage_hosei(void) {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;
    if (plw[0].tsukami_f && plw[1].tsukamare_f) {
        check_damage_hosei_nage(&plw[0], &plw[1]);
    } else if (plw[1].tsukami_f && plw[0].tsukamare_f) {
        check_damage_hosei_nage(&plw[1], &plw[0]);
    } else {
        switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
        case 1:
            check_damage_hosei_dageki(&plw[0], &plw[1]);
            break;
        case 2:
            check_damage_hosei_dageki(&plw[1], &plw[0]);
            break;
        }
    }
    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}



void check_damage_hosei_nage(PLW* as, PLW* ds) {
    if (as->kind_of_catch) {
        if (ds->hosei_amari != 0) {
            as->wu.xyz[0].disp.pos += ds->hosei_amari;
            as->muriyari_ugoku += ds->hosei_amari;
            return;
        }
        if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(as, scrr, 1) != 0) {
            set_field_hosei_flag(as, scrl, 0);
        }
        if (as->hosei_amari != 0) {
            ds->wu.xyz[0].disp.pos += as->hosei_amari;
            ds->muriyari_ugoku += as->hosei_amari;
        }
    } else if (ds->hosei_amari != 0) {
        as->wu.xyz[0].disp.pos += ds->hosei_amari;
        as->muriyari_ugoku += ds->hosei_amari;
    }
}



void check_damage_hosei_dageki(PLW* w1, PLW* w2) {
    if ((w1->dm_hos_flag != 0) && (w2->wu.hit_stop == 0)) {
        w2->wu.xyz[0].disp.pos += w1->hosei_amari;
        w2->muriyari_ugoku += w1->hosei_amari;
    }
}



s32 time_over_check(void) {
    if ((will_die() != 0) && (round_timer.timer == 0)) {
        Winner_id = 0;
        Loser_id = 1;
        if (plw[0].wu.vital_new < plw[1].wu.vital_new) {
            Winner_id = 1;
            Loser_id = 0;
        }
        setup_gouki_wins();
        Conclusion_Flag = 1;
        Conclusion_Type = 2;
        setup_settle_rno(2);
        if (Demo_Flag) {
            request_center_message(2);
        }
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
        Round_Result |= 1;
        return 1;
    }
    return 0;
}



s32 will_die(void) {
    if (plw[0].wu.dm_vital > plw[0].wu.vital_new) {
        return 0;
    }
    if (plw[1].wu.dm_vital > plw[1].wu.vital_new) {
        return 0;
    }
    return 1;
}



/* provisional name */
void setup_settle_rno(s16 kos) {
    pcon_rno[0] = 2;
    pcon_rno[1] = kos;
    pcon_rno[2] = 0;
    ca_check_flag = 0;
    pcon_dp_flag = 1;
}



void settle_check(void) {
retry:
    switch ((plw[0].dead_flag) + (plw[1].dead_flag * 2)) {
    case 1:
        if (1) {
            Winner_id = 1;
            Loser_id = 0;
        } else {
        case 2:
            Winner_id = 0;
            Loser_id = 1;
        }
        if (check_sa_resurrection(&plw[Loser_id]) == 0) {
            setup_gouki_wins();
            Round_Result |= plw[Loser_id].wu.dm_koa;
            if ((Round_Result & 0x800) && gouki_wins) {
                Shin_Gouki_BGM = 1;
                Control_Music_Fade(150);
                setup_settle_rno(4);
                break;
            }
            setup_settle_rno(0);
            Conclusion_Flag = 1;
            Conclusion_Type = 0;
            if (Demo_Flag) {
                request_center_message(0);
            }
        }
        break;
    case 3:
        if ((check_sa_resurrection(&plw[0]) == 0) && (check_sa_resurrection(&plw[1]) == 0)) {
            Conclusion_Flag = 1;
            Conclusion_Type = 1;
            setup_settle_rno(1);
            if (Demo_Flag) {
                request_center_message(1);
            }
        } else {
            goto retry;
        }
        break;
    default:
        break;
    }
}



/* provisional name */
s32 check_sa_resurrection(PLW* wk) {
    if (check_sa_type_rebirth(wk) == 0) {
        return 0;
    }
    wk->kezurijini_flag = 0;
    wk->dead_flag = 0;
    return 1;
}



s32 check_sa_type_rebirth(PLW* wk) {
    if (wk->sa->gauge_type != 3) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    return 1;
}

s32 nekorobi_check(char pl)
{
    s16 result;
    result = 0;
    if (plw[pl].wu.routine_no[1] == 1 && plw[pl].wu.routine_no[2] == 0 && plw[pl].wu.routine_no[3] > 2) {
        result = 1;
    }
    return result;
}

s32 footwork_check(char pl)
{
    s16 result;
    result = 0;
    if (plw[pl].wu.routine_no[1] == 0 && plw[pl].wu.routine_no[2] == 1) {
        result = 1;
    }
    return result;
}



/* provisional name */
void reset_char_disp_work(WORK* wk) {
    s16 i;
    for (i = 0; i < 4; i++) {
        wk->spr.gfx_blk40[i] = 0;
        wk->spr.gfx_blk10[i] = 0;
    }
    wk->old_cgnum = 0;
    wk->spr.gfx_ofs = 0;
    wk->spr.gfx_cells = 0;
}



void set_quake(PLW* wk) {
    if (wk->wu.hit_quake) {
        wk->wu.hit_quake--;
        wk->wu.next_x = quake_table[wk->wu.hit_quake];
        if (wk->wu.rl_flag) {
            wk->wu.next_x = -wk->wu.next_x;
        }
    } else {
        wk->wu.next_x = 0;
    }
}



void add_next_position(PLW* wk) {
    wk->wu.position_x = wk->wu.xyz[0].disp.pos + wk->wu.next_x;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos + wk->wu.next_y;
    wk->wu.position_z = wk->wu.next_z;
    wk->wu.next_y = 0;
}

/* provisional name */
void setup_gouki_wins(void)
{
    gouki_wins = 0;
    if (plw[Winner_id].player_number == PL_GOUKI1 || plw[Winner_id].player_number == PL_GOUKI2) {
        gouki_wins = 1;
    }
}

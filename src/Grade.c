/*
 * GRADE.C  Player grade judgement
 *
 * Keeps each player's grade work for the grade judgement shown on the result screens.
 * During a fight other modules report events through the grade_add_xxx routines: clean hits,
 * guard successes, blocking (parries), stuns, leap attacks, throw escapes, quick stands, throws,
 * reversals, target combos, command moves, super arts, personal actions, max combo and repeated
 * moves; grade_store_vitality, grade_set_round_result and grade_check_tairyokusa record round
 * results.
 * Manage calls the round, stage and match routines (grade_check_work_stage_init,
 * grade_makeup_stage_parameter, accumulate_match_totals_xxx, grade_makeup_judgement_gals,
 * grade_makeup_bonus_parameter), which total attack, defence, technique and extra points.
 * grade_get_my_grade and the point-percentage getters feed EFFL1, Eff76 and sc_face;
 * grade_final_grade_bonus adds the final grade bonus to the score.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Eff76.h"
#include "Com_Sub.h"
#include "HITCHECK.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Grade.h"
#include "fighter.h"
#include "cmd_data.h"

GradeData judge_item[2][2];  /* 02010C4C */
GradeFinalData judge_final[2][2];  /* 02010D7C */
JudgeGals judge_gals[2];  /* 0201102C */
JudgeCom judge_com[2];  /* 02011040 */
u8 ji_sat[2][384];  /* 02011058 */
s16 last_judge_dada[2][5];



s32 grade_check_work_1st_init(ix, ix2)
s16 ix;
s16 ix2;
{
    s16 i;
    work_init_zero((s32*)&judge_item[ix][ix2], sizeof(GradeData));
    work_init_zero((s32*)&judge_final[ix][ix2], sizeof(GradeFinalData));
    for (i = 0; i < 16; i++) {
        judge_final[ix][ix2].vs_cpu_result[i] = -1;
        judge_final[ix][ix2].vs_cpu_player[i] = -1;
        judge_final[ix][ix2].vs_cpu_grade[i] = -1;
    }
}



void grade_check_work_stage_init(s16 ix) {
    judge_item[ix][Play_Type].offence_total = 0;
    judge_item[ix][Play_Type].defence_total = 0;
    judge_item[ix][Play_Type].tech_pts_total = 0;
    judge_item[ix][Play_Type].ex_point_total = 0;
    judge_item[ix][Play_Type].round = 0;
    judge_item[ix][Play_Type].win_round = 0;
    if (Play_Type == PLAY_VS_PLAYER) {
        judge_item[ix][Play_Type].renshou = Win_Record[ix];
        judge_item[ix][Play_Type].em_renshou = Win_Record[(ix + 1) & 1];
    } else {
        judge_item[ix][Play_Type].renshou = 0;
        judge_item[ix][Play_Type].em_renshou = 0;
    }
}



void grade_check_work_round_init(ix)
s16 ix;
{
    s16 i;
    judge_item[ix][Play_Type].em_stun = 0;
    judge_item[ix][Play_Type].max_combo = 0;
    judge_item[ix][Play_Type].clean_hits = 0;
    judge_item[ix][Play_Type].att_renew = 0;
    judge_item[ix][Play_Type].guard_succ = 0;
    judge_item[ix][Play_Type].vitality = 0;
    judge_item[ix][Play_Type].nml_blocking = 0;
    judge_item[ix][Play_Type].rpd_blocking = 0;
    judge_item[ix][Play_Type].grd_blocking = 0;
    judge_item[ix][Play_Type].first_attack = 0;
    judge_item[ix][Play_Type].leap_attack = 0;
    judge_item[ix][Play_Type].target_combo = 0;
    judge_item[ix][Play_Type].nml_nage = 0;
    judge_item[ix][Play_Type].grap_def = 0;
    judge_item[ix][Play_Type].quick_stand = 0;
    judge_item[ix][Play_Type].personal_act = 0;
    judge_item[ix][Play_Type].reversal = 0;
    judge_item[ix][Play_Type].comwaza = 0;
    judge_item[ix][Play_Type].sa_exec = 0;
    judge_item[ix][Play_Type].tairyokusa = 0;
    judge_item[ix][Play_Type].kimarite = 0;
    judge_item[ix][Play_Type].app_nml_block = -1;
    judge_item[ix][Play_Type].app_rpd_block = -1;
    judge_item[ix][Play_Type].app_grd_block = -1;
    judge_item[ix][Play_Type].onaji_waza = 0;
    if (Round_Operator[ix] == 0) {
        judge_item[ix][Play_Type].grd_miss = ji_grd_init_data[Setup_Lv10(0)];
        judge_item[ix][Play_Type].grd_mcnt = ji_grd_init_data[Setup_Lv10(0)];
    } else {
        judge_item[ix][Play_Type].grd_miss = 0;
        judge_item[ix][Play_Type].grd_mcnt = 0;
    }
    for (i = 0; i < 384; i++) {
        ji_sat[ix][i] = 0;
    }
    judge_gals[ix].grade = 0;
    judge_gals[ix].offence_total = 0;
    judge_gals[ix].defence_total = 0;
    judge_gals[ix].tech_pts_total = 0;
    judge_gals[ix].ex_point_total = 0;
}



void grade_makeup_final_parameter(ix, pt)
s16 ix;
s16 pt;
{
    renew_judge_final_work(ix, pt);
    if (Version_Type == 3) {
        if (VS_Index[WINNER] >= 6) {
            judge_final[ix][pt].all_clear = 1;
        }
        judge_final[ix][pt].keizoku = Continue_Coin[ix];
        makeup_spp_frdat(ix, pt);
        makeup_final_grade(ix, pt);
    } else {
        if (Break_Com[ix][0]) {
            judge_final[ix][pt].all_clear = 1;
        }
        judge_final[ix][pt].keizoku = Continue_Coin[ix];
        makeup_spp_frdat(ix, pt);
        makeup_final_grade(ix, pt);
    }
}



void renew_judge_final_work(ix, pt)
s16 ix;
s16 pt;
{
    s16 i;
    u32* frsd;

    judge_final[ix][pt].all_clear = 0;
    frsd = (u32*)judge_final[ix][pt].fr_sort_data;
    judge_final[ix][pt].keizoku = 0;
    judge_final[ix][pt].sp_point = 0;
    judge_final[ix][pt].fr_ix = 0;
    for (i = 0; i < 16; i++) {
        *frsd++ = 0;
    }
}


void makeup_final_grade(ix, pt)
s16 ix;
s16 pt;
{
    s16 i;
    s16 tt = 0;
    s16 dt;
    if ((dt = judge_final[ix][pt].vcr_ix) == 0) {
        dt = 1;
    }
    for (i = 0; i < judge_final[ix][pt].vcr_ix; i++) {
        tt += judge_final[ix][pt].vs_cpu_result[i];
    }
    if (Version_Type == 3) {
        tt /= 6;
    } else {
        if (judge_final[ix][pt].vs_cpu_result[15] != -1) {
            tt += judge_final[ix][pt].vs_cpu_result[15];
            dt++;
        }
        judge_final[ix][pt].vs_cpu_result[11] = tt / dt;
        judge_final[ix][pt].vs_cpu_grade[11] = get_grade_ix(tt / dt);
        if (judge_final[ix][pt].vs_cpu_result[15] != -1) {
            tt /= 11;
        } else {
            tt /= 10;
        }
    }
    for (i = 0; i < 3; i++) {
        if (judge_final[ix][pt].vcr_ix < grade_t_f_stage[i + 1][0]) {
            break;
        }
    }
    tt += grade_t_f_stage[i][1];
    if (judge_final[ix][pt].all_clear) {
        tt += grade_t_f_all[judge_final[ix][pt].all_clear];
        for (i = 0; i < 10; i++) {
            if (judge_final[ix][pt].keizoku < grade_t_f_continue[i + 1][0]) {
                break;
            }
        }
        tt += grade_t_f_continue[i][1];
        for (i = 0; i < 10; i++) {
            if (judge_final[ix][pt].sp_point < grade_t_f_gradeup[i + 1][0]) {
                break;
            }
        }
        tt += grade_t_f_gradeup[i][1];
        if (judge_final[ix][pt].vs_cpu_grade[13] != -1) {
            for (i = 0; i < 3; i++) {
                if (judge_final[ix][pt].vs_cpu_grade[13] < grade_t_f_bss_ball[i + 1][0]) {
                    break;
                }
            }
            tt += grade_t_f_bss_ball[i][1];
        }
        if (judge_final[ix][pt].vs_cpu_grade[14] != -1) {
            for (i = 0; i < 3; i++) {
                if (judge_final[ix][pt].vs_cpu_grade[14] < grade_t_f_bss_car[i + 1][0]) {
                    break;
                }
            }
            tt += grade_t_f_bss_car[i][1];
        }
    }
    if (tt < 0) {
        tt = 0;
    }
    judge_final[ix][pt].vs_cpu_result[12] = tt;
    judge_final[ix][pt].vs_cpu_grade[12] = judge_final[ix][pt].grade = get_grade_ix(tt);
}



void grade_final_grade_bonus(void) {
    u32 bonus_point = grade_t_table[judge_final[WGJ_Target][Final_Play_Type[WGJ_Target]].grade][1];
    bonus_point *= 100;
    Score[WGJ_Target][Final_Play_Type[WGJ_Target]] += bonus_point;
}

void makeup_spp_frdat(pl, set)
s16 pl;
s16 set;
{
    u8 (*ev)[4];
    s16 i;
    s16 n;

    ev = judge_final[pl][set].fr_sort_data;
    for (i = n = 0; i < judge_final[pl][set].vcr_ix; i++) {
        if (i == judge_final[pl][set].vs_cpu_player[15]) {
            ev[n][0] = 9;
            ev[n][1] = judge_final[pl][set].vs_cpu_grade[15];
            ev[n][2] = 18;
            n++;
        }
        ev[n][0] = i;
        ev[n][1] = judge_final[pl][set].vs_cpu_grade[i];
        ev[n][2] = judge_final[pl][set].vs_cpu_player[i];
        n++;
    }
    judge_final[pl][set].fr_ix = n;
    for (; i < 10; i++) {
        ev[n][0] = i;
        n++;
    }
    judge_final[pl][set].sp_point = 0;
    for (i = 1; i < judge_final[pl][set].fr_ix; i++) {
        if (ev[i][1] > ev[i - 1][1]) {
            judge_final[pl][set].sp_point++;
            ev[i][3] = 1;
        }
    }
}



void grade_makeup_round_parameter(s16 ix) {
    s16 ix2 = (ix + 1) & 1;
    judge_item[ix][Play_Type].offence_total += get_offence_total(ix);
    judge_item[ix2][Play_Type].offence_total += get_offence_total(ix2);
    judge_item[ix][Play_Type].defence_total += get_defence_total(ix, 1);
    judge_item[ix2][Play_Type].defence_total += get_defence_total(ix2, 0);
    judge_item[ix][Play_Type].tech_pts_total += get_tech_pts_total(ix);
    judge_item[ix2][Play_Type].tech_pts_total += get_tech_pts_total(ix2);
    judge_item[ix][Play_Type].ex_point_total += get_ex_point_total(ix, 1);
    judge_item[ix2][Play_Type].ex_point_total += get_ex_point_total(ix2, 0);
    judge_item[ix][Play_Type].round++;
    judge_item[ix2][Play_Type].round++;
    judge_item[ix][Play_Type].win_round++;
    backup_RO_PT();
}



void backup_RO_PT(void) {
    RO_backup[0] = Round_Operator[0];
    RO_backup[1] = Round_Operator[1];
    PT_backup = Play_Type;
}



void grade_makeup_round_para_dko(void) {
    s16 i;
    for (i = 0; i < 2; i++) {
        judge_item[i][Play_Type].offence_total += get_offence_total(i);
        judge_item[i][Play_Type].defence_total += get_defence_total(i, 0);
        judge_item[i][Play_Type].tech_pts_total += get_tech_pts_total(i);
        judge_item[i][Play_Type].ex_point_total += get_ex_point_total(i, 0);
        judge_item[i][Play_Type].round++;
    }
    backup_RO_PT();
}



void grade_makeup_judgement_gals(void) {
    s16 i;
    for (i = 0; i < 2; i++) {
        judge_gals[i].offence_total = get_offence_total(i);
        judge_gals[i].defence_total = get_defence_total(i, 0);
        judge_gals[i].tech_pts_total = get_tech_pts_total(i);
        judge_gals[i].ex_point_total = get_ex_point_total(i, 0);
        judge_gals[i].grade = get_grade_ix(judge_gals[i].offence_total + judge_gals[i].defence_total +
                                             judge_gals[i].tech_pts_total + judge_gals[i].ex_point_total);
    }
}



void grade_makeup_stage_parameter(s16 ix) {
    s16 i;
    s16 grade;
    s16 plnum;
    s16 point = 0;
    s16 bs;
    s16 qc;
    s32 em;
    if (Round_Operator[ix] == 0) {
        grade_makeup_stage_para_com(ix);
        return;
    }
    qc = bs = 0;
    if (judge_item[ix][Play_Type].round == 0) {
        judge_item[ix][Play_Type].round = 1;
    }
    judge_item[ix][Play_Type].offence_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].defence_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].tech_pts_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].ex_point_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].no_lose = 0;
    if (judge_item[ix][Play_Type].round == judge_item[ix][Play_Type].win_round) {
        judge_item[ix][Play_Type].no_lose = Straight_Counter[ix];
    }
    if (ix == WINNER) {
        if (Play_Type == PLAY_VS_CPU) {
            for (i = 0; i < 10; i++) {
                if (judge_item[ix][Play_Type].no_lose < grade_t_straight[i + 1][0]) {
                    break;
                }
            }
            judge_item[ix][Play_Type].ex_point_total += grade_t_straight[i][1];
        } else if (judge_item[ix][Play_Type].renshou) {
            for (i = 0; i < 7; i++) {
                if (judge_item[ix][Play_Type].renshou < grade_t_renshou[i + 1][0]) {
                    break;
                }
            }
            point += grade_t_renshou[i][1];
        } else {
            for (i = 0; i < 7; i++) {
                if (judge_item[ix][Play_Type].em_renshou < grade_t_em_renshou[i + 1][0]) {
                    break;
                }
            }
            point += grade_t_em_renshou[i][1];
        }
    }
    point = judge_item[ix][Play_Type].offence_total + judge_item[ix][Play_Type].defence_total +
            judge_item[ix][Play_Type].tech_pts_total + judge_item[ix][Play_Type].ex_point_total;
    grade = get_grade_ix(point);
    if (Play_Type == PLAY_VS_CPU) {
        switch (bg_w.stage) {
        case BONUS_CAR:
        case BONUS_PARRY:
            bs = 1;
            break;
        default:
            em = (ix + 1) & 1;
            if ((qc = rannyuu_Q_check(em))) {
                judge_final[ix][Play_Type].vs_cpu_result[15] = point;
                judge_final[ix][Play_Type].vs_cpu_grade[15] = grade;
                judge_final[ix][Play_Type].vs_cpu_player[15] = judge_final[ix][Play_Type].vcr_ix;
            } else {
                plnum = My_char[em] + chkNameAkuma(My_char[em]);
                judge_final[ix][Play_Type].vs_cpu_result[judge_final[ix][Play_Type].vcr_ix] = point;
                judge_final[ix][Play_Type].vs_cpu_grade[judge_final[ix][Play_Type].vcr_ix] = grade;
                judge_final[ix][Play_Type].vs_cpu_player[judge_final[ix][Play_Type].vcr_ix] = plnum;
                judge_final[ix][Play_Type].vcr_ix++;
            }
            judge_item[ix][Play_Type].grade = grade;
            break;
        }
        grade_makeup_final_parameter(ix, Play_Type);
        if (ix == WINNER) {
            return;
        }
        if (bs != 0) {
            return;
        }
        if (qc) {
            judge_final[ix][Play_Type].vs_cpu_result[15] = -1;
            judge_final[ix][Play_Type].vs_cpu_grade[15] = -1;
            judge_final[ix][Play_Type].vs_cpu_player[15] = -1;
        } else {
            judge_final[ix][Play_Type].vcr_ix--;
        }
    } else {
        judge_item[ix][Play_Type].grade = grade;
    }
}


u32 rannyuu_Q_check(s16 pl) {
    if (Round_Operator[pl] == 0 && My_char[pl] == PL_Q) {
        return 1;
    }
    return 0;
}



void grade_makeup_stage_para_com(ix)
s16 ix;
{
    judge_com[ix].round = judge_item[ix][Play_Type].round;
    if (judge_com[ix].round == 0) {
        judge_com[ix].round = 1;
    }
    judge_com[ix].offence_total = judge_item[ix][Play_Type].offence_total / judge_com[ix].round;
    judge_com[ix].defence_total = judge_item[ix][Play_Type].defence_total / judge_com[ix].round;
    judge_com[ix].tech_pts_total = judge_item[ix][Play_Type].tech_pts_total / judge_com[ix].round;
    judge_com[ix].ex_point_total = judge_item[ix][Play_Type].ex_point_total / judge_com[ix].round;
    judge_com[ix].grade = get_grade_ix(judge_com[ix].offence_total + judge_com[ix].defence_total +
                                          judge_com[ix].tech_pts_total + judge_com[ix].ex_point_total);
}



void grade_makeup_bonus_parameter(s16 ix) {
    if (Round_Operator[ix] != 0) {
        switch (bg_w.stage) {
        case BONUS_PARRY:
            judge_final[ix][Play_Type].vs_cpu_grade[13] = (Bonus_Game_result == 20) + (Bonus_Game_ex_result == 20) * 2;
            break;
        case BONUS_CAR:
            judge_final[ix][Play_Type].vs_cpu_grade[14] = Bonus_Game_result;
            break;
        }
    }
}



s32 get_offence_total(ix)
s16 ix;
{
    s32 num;
    s32 num2;
    s32 point;
    s32 point2;
    s16 i;
    s16 ix2;
    ix2 = (ix + 1) & 1;
    num2 = judge_item[ix2][Play_Type].guard_succ + judge_item[ix2][Play_Type].nml_blocking +
           judge_item[ix2][Play_Type].rpd_blocking + judge_item[ix2][Play_Type].grd_blocking +
           judge_item[ix][Play_Type].clean_hits;
    num = (judge_item[ix][Play_Type].clean_hits * 100) / num2;

    for (i = 0; i < 23; i++) {
        if (num < grade_t_meichuuritsu2[i + 1][0]) {
            break;
        }
    }
    point2 = grade_t_meichuuritsu2[i][1];
    num = (num2 * 100) / judge_item[ix][Play_Type].att_renew;
    point2 = num * point2 / 100;
    num = (judge_item[ix2][Play_Type].grd_miss * 100) / judge_item[ix2][Play_Type].grd_mcnt;
    for (i = 0; i < 20; i++) {
        if (num < grade_t_meichuuritsu3[i + 1][0]) {
            break;
        }
    }
    point2 *= grade_t_meichuuritsu3[i][1];
    point2 /= 32;
    point = point2;
    for (i = 0; i < 4; i++) {
        if (judge_item[ix][Play_Type].em_stun < grade_t_em_stun[i + 1][0]) {
            break;
        }
    }
    point += grade_t_em_stun[i][1];
    for (i = 0; i < 18; i++) {
        if (judge_item[ix][Play_Type].max_combo < grade_t_max_combo[i + 1][0]) {
            break;
        }
    }
    point += grade_t_max_combo[i][1];
    return (s16)point;
}



s32 get_defence_total(ix, wf)
s16 ix;
s16 wf;
{
    s32 num = 0;
    s16 i;
    s16 ix2;
    s32 point;
    s32 point2;
    ix2 = (ix + 1) & 1;
    point2 = ((judge_item[ix2][Play_Type].att_renew - judge_item[ix2][Play_Type].clean_hits) * 100) /
             judge_item[ix2][Play_Type].att_renew;
    for (i = 0; i < 13; i++) {
        if (point2 < grade_t_bougyoritsu2[i + 1][0]) {
            break;
        }
    }
    num += grade_t_bougyoritsu2[i][1];
    point2 = judge_item[ix][Play_Type].clean_hits + judge_item[ix2][Play_Type].guard_succ;
    point2 = (point2 * 100) / judge_item[ix][Play_Type].att_renew;
    for (i = 0; i < 12; i++) {
        if (point2 < grade_t_bougyoritsu3[i + 1][0]) {
            break;
        }
    }
    point = grade_t_bougyoritsu3[i][1];
    if (judge_item[ix2][Play_Type].att_renew == 0) {
        point = (point * 200) / 100;
    }
    num += point;
    if (wf) {
        for (i = 0; i < 12; i++) {
            if (judge_item[ix][Play_Type].vitality < grade_t_nokori_vital[i + 1][0]) {
                break;
            }
        }
        num += grade_t_nokori_vital[i][1];
    }
    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].nml_blocking < grade_t_def_nmlblock[i + 1][0]) {
            break;
        }
    }
    num += grade_t_def_nmlblock[i][1];
    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].rpd_blocking < grade_t_def_rpdblock[i + 1][0]) {
            break;
        }
    }
    num += grade_t_def_rpdblock[i][1];
    for (i = 0; i < 8; i++) {
        if (judge_item[ix][Play_Type].grd_blocking < grade_t_def_grdblock[i + 1][0]) {
            break;
        }
    }
    num += grade_t_def_grdblock[i][1];
    return (s16)num;
}



s32 get_tech_pts_total(ix)
s16 ix;
{
    s16 i;
    s16 point = 0;
    point += grade_t_first_attack[judge_item[ix][Play_Type].first_attack];
    for (i = 0; i < 9; i++) {
        if (judge_item[ix][Play_Type].leap_attack < grade_t_leap_attack[i + 1][0]) {
            break;
        }
    }
    point += grade_t_leap_attack[i][1];
    for (i = 0; i < 7; i++) {
        if (judge_item[ix][Play_Type].target_combo < grade_t_target_combo[i + 1][0]) {
            break;
        }
    }
    point += grade_t_target_combo[i][1];
    for (i = 0; i < 9; i++) {
        if (judge_item[ix][Play_Type].nml_nage < grade_t_nml_nage[i + 1][0]) {
            break;
        }
    }
    point += grade_t_nml_nage[i][1];
    for (i = 0; i < 5; i++) {
        if (judge_item[ix][Play_Type].grap_def < grade_t_grap_def[i + 1][0]) {
            break;
        }
    }
    point += grade_t_grap_def[i][1];
    for (i = 0; i < 3; i++) {
        if (judge_item[ix][Play_Type].quick_stand < grade_t_quick_stand[i + 1][0]) {
            break;
        }
    }
    point += grade_t_quick_stand[i][1];
    for (i = 0; i < 3; i++) {
        if (judge_item[ix][Play_Type].personal_act < grade_t_personal_act[i + 1][0]) {
            break;
        }
    }
    point += grade_t_personal_act[i][1];
    for (i = 0; i < 7; i++) {
        if (judge_item[ix][Play_Type].reversal < grade_t_reversal[i + 1][0]) {
            break;
        }
    }
    point += grade_t_reversal[i][1];
    for (i = 0; i < 8; i++) {
        if (judge_item[ix][Play_Type].comwaza < grade_t_command_waza[i + 1][0]) {
            break;
        }
    }
    point += grade_t_command_waza[i][1];
    switch (plw[ix].sa->store_max) {
    case 1:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_1[i + 1][0]) {
                break;
            }
        }
        point += grade_t_sa_stock_1[i][1];
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_2[i + 1][0]) {
                break;
            }
        }
        point += grade_t_sa_stock_2[i][1];
        break;
    default:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_3[i + 1][0]) {
                break;
            }
        }
        point += grade_t_sa_stock_3[i][1];
        break;
    }
    return point;
}



s32 get_ex_point_total(ix, wf)
s16 ix;
s16 wf;
{
    s16 i;
    s16 point = 0;

    if (wf != 0) {
        for (i = 0; i < 20; i++) {
            if (judge_item[ix][Play_Type].tairyokusa < grade_t_tairyokusa[i + 1][0]) {
                break;
            }
        }
        point += grade_t_tairyokusa[i][1];
        point += grade_t_round_result[judge_item[ix][Play_Type].kimarite];
    }
    for (i = 0; i < 5; i++) {
        if (judge_item[ix][Play_Type].onaji_waza < grade_t_onaji_waza[i + 1][0]) {
            break;
        }
    }
    point += grade_t_onaji_waza[i][1];
    if (judge_item[ix][Play_Type].app_nml_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_nml_block < grade_t_app_nmlblock[i + 1][0]) {
                break;
            }
        }
        point += grade_t_app_nmlblock[i][1];
    }
    if (judge_item[ix][Play_Type].app_rpd_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_rpd_block < grade_t_app_rpdblock[i + 1][0]) {
                break;
            }
        }
        point += grade_t_app_rpdblock[i][1];
    }
    if (judge_item[ix][Play_Type].app_grd_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_grd_block < grade_t_app_grdblock[i + 1][0]) {
                break;
            }
        }
        point += grade_t_app_grdblock[i][1];
    }
    return point;
}



void grade_add_clean_hits(WORK_Other* wk) {
    WORK* mwk;
    s16 ix;
    if (pcon_rno[0] != PCON_INIT) {
        ix = wk->wu.id;
        if (wk->wu.work_id != 1) {
            mwk = (WORK*)(wk->my_master);
            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].clean_hits++;
    }
}



void grade_add_att_renew(WORK_Other* wk) {
    WORK* mwk;
    s16 ix;
    if (pcon_rno[0] != PCON_INIT) {
        ix = wk->wu.id;
        if (wk->wu.work_id != 1) {
            mwk = (WORK*)(wk->my_master);
            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].att_renew++;
    }
}



void grade_add_guard_success(s16 ix) {
    if ((u16)ix > 1) {
        return;
    }
    judge_item[ix][Play_Type].guard_succ++;
}



void grade_add_em_stun(s16 ix) {
    judge_item[ix][Play_Type].em_stun++;
    if (judge_item[ix][Play_Type].em_stun > 4) {
        judge_item[ix][Play_Type].em_stun = 4;
    }
}



void grade_max_combo_check(ix, num)
s16 ix;
s16 num;
{
    if (judge_item[ix][Play_Type].max_combo < num) {
        judge_item[ix][Play_Type].max_combo = num;
    }
}



void grade_add_leap_attack(s16 ix) {
    judge_item[ix][Play_Type].leap_attack++;
    if (judge_item[ix][Play_Type].leap_attack > 12) {
        judge_item[ix][Play_Type].leap_attack = 12;
    }
}



void grade_add_grap_def(s16 ix) {
    judge_item[ix][Play_Type].grap_def++;
    if (judge_item[ix][Play_Type].grap_def > 16) {
        judge_item[ix][Play_Type].grap_def = 16;
    }
}



void grade_add_quick_stand(s16 ix) {
    judge_item[ix][Play_Type].quick_stand++;
    if (judge_item[ix][Play_Type].quick_stand > 6) {
        judge_item[ix][Play_Type].quick_stand = 6;
    }
}



void grade_add_nml_nage(WORK* wk) {
    s16 ix;
    if (check_normal_attack(wk->kind_of_waza)) {
        ix = wk->id;
        judge_item[ix][Play_Type].nml_nage++;
        if (judge_item[ix][Play_Type].nml_nage > 0xC) {
            judge_item[ix][Play_Type].nml_nage = 0xC;
        }
    }
}



void grade_add_reversal(ix)
s16 ix;
{
    judge_item[ix][Play_Type].reversal++;
    if (judge_item[ix][Play_Type].reversal > 10) {
        judge_item[ix][Play_Type].reversal = 10;
    }
}



void grade_add_target_combo(s16 ix) {
    judge_item[ix][Play_Type].target_combo++;
    if (judge_item[ix][Play_Type].target_combo > 24) {
        judge_item[ix][Play_Type].target_combo = 24;
    }
}



void grade_add_command_waza(s16 ix) {
    judge_item[ix][Play_Type].comwaza++;
    if (judge_item[ix][Play_Type].comwaza > 36) {
        judge_item[ix][Play_Type].comwaza = 36;
    }
}



void grade_add_super_arts(s16 ix, s16 num) {
    judge_item[ix][Play_Type].sa_exec += num;
    if (judge_item[ix][Play_Type].sa_exec > 5) {
        judge_item[ix][Play_Type].sa_exec = 5;
    }
}



void grade_store_vitality(ix)
s16 ix;
{
    judge_item[ix][Play_Type].vitality = plw[ix].wu.vital_new;
}



void grade_add_blocking(PLW* wk) {
    s16 ix = wk->wu.id;
    switch (wk->kind_of_blocking) {
    case 0:
        judge_item[ix][Play_Type].app_nml_block = wk->wu.vital_new;
        if ((judge_item[ix][Play_Type].nml_blocking += 1) > 15) {
            judge_item[ix][Play_Type].nml_blocking = 15;
            break;
        }
        break;
    case 1:
        judge_item[ix][Play_Type].app_rpd_block = wk->wu.vital_new;
        if ((judge_item[ix][Play_Type].rpd_blocking += 1) > 15) {
            judge_item[ix][Play_Type].rpd_blocking = 15;
            return;
        }
        break;
    case 2:
        judge_item[ix][Play_Type].app_grd_block = wk->wu.vital_new;
        if ((judge_item[ix][Play_Type].grd_blocking += 1) > 15) {
            judge_item[ix][Play_Type].grd_blocking = 15;
        }
        break;
    }
}



void grade_get_first_attack(ix)
s16 ix;
{
    judge_item[ix][Play_Type].first_attack = 1;
}



void grade_set_round_result(s16 ix) {
    if (Round_Result & 0x8201) {
        judge_item[ix][Play_Type].kimarite = 0;
        return;
    }
    if (Round_Result & 0x2C) {
        judge_item[ix][Play_Type].kimarite = 1;
        return;
    }
    if (Round_Result & 0x50) {
        judge_item[ix][Play_Type].kimarite = 2;
        return;
    }
    if (Round_Result & 0x980) {
        judge_item[ix][Play_Type].kimarite = 3;
        return;
    }
    judge_item[ix][Play_Type].kimarite = 0;
}



void grade_add_personal_action(s16 ix) {
    if (pcon_dp_flag) {
        return;
    }
    judge_item[ix][Play_Type].personal_act++;
    if (judge_item[ix][Play_Type].personal_act > 3) {
        judge_item[ix][Play_Type].personal_act = 3;
    }
}



void grade_check_tairyokusa(void) {
    s16 vwork = plw[1].wu.vital_new - plw[0].wu.vital_new;
    if (vwork > 0) {
        if (judge_item[0][Play_Type].tairyokusa < vwork) {
            judge_item[0][Play_Type].tairyokusa = vwork;
        }
    }
    vwork = plw[0].wu.vital_new - plw[1].wu.vital_new;
    if (vwork > 0) {
        if (judge_item[1][Play_Type].tairyokusa < vwork) {
            judge_item[1][Play_Type].tairyokusa = vwork;
        }
    }
}



void grade_add_onaji_waza(s16 ix) {
    s16 num;
    num = plw[ix].wu.char_index + ((plw[ix].wu.now_koc == 5) * 0xF0);
    if (num > 0x17F) {
        return;
    }
    if (ji_sat[ix][num] != 0xFF) {
        ji_sat[ix][num]++;
    }
    if (judge_item[ix][Play_Type].onaji_waza < ji_sat[ix][num]) {
        judge_item[ix][Play_Type].onaji_waza = ji_sat[ix][num];
    }
}



/* Returns the grade stored for a player in the current play type. */
s32 grade_get_my_grade(s16 ix) {
    return judge_item[ix][Play_Type].grade;
}



s32 grade_get_my_point_percentage(ix, flag)
s16 ix;
s16 flag;
{
    s32 rnum;
    switch (flag) {
    case 0:
        rnum = judge_item[ix][Play_Type].offence_total * 100;
        rnum /= 500;
        break;
    case 1:
        rnum = judge_item[ix][Play_Type].defence_total * 100;
        rnum /= 500;
        break;
    case 2:
        rnum = judge_item[ix][Play_Type].tech_pts_total * 100;
        rnum /= 500;
        break;
    case 3:
        rnum = judge_item[ix][Play_Type].ex_point_total * 100;
        rnum /= 500;
        break;
    }
    if (rnum > 120) {
        rnum = 120;
    }
    return (s16)rnum;
}



s32 grade_get_cm_point_percentage(ix, flag)
s16 ix;
s16 flag;
{
    s32 rnum;
    switch (flag) {
    case 0:
        rnum = judge_com[ix].offence_total * 100;
        rnum /= 500;
        break;
    case 1:
        rnum = judge_com[ix].defence_total * 100;
        rnum /= 500;
        break;
    case 2:
        rnum = judge_com[ix].tech_pts_total * 100;
        rnum /= 500;
        break;
    case 3:
        rnum = judge_com[ix].ex_point_total * 100;
        rnum /= 500;
        break;
    }
    if (rnum > 120) {
        rnum = 120;
    }
    return (s16)rnum;
}



/* provisional name */
s32 grade_scale_to_percent(s16 value) {
    if (value == 0) {
        return 0;
    }
    value = (value * 100) / 160;
    if (value != 0) {
        return value;
    }
    return 1;
}



s32 get_grade_ix(pts)
s16 pts;
{
    s16 i;
    for (i = 0; i < 31; i++) {
        if (pts < grade_t_table[i + 1][0]) {
            break;
        }
    }
    return i;
}



void check_guard_miss(as, ds, gddir)
WORK* as;
PLW* ds;
char gddir;
{
    register s16* wf;
    if (ds->rp->total) {
        return;
    }
    judge_item[ds->wu.id][Play_Type].grd_mcnt++;
    if (ds->guard_flag == 3) {
    } else if (!(as->att.guard & 0x3F)) {
    } else if (ds->wu.xyz[1].disp.pos > 1) {
    } else if ((as->work_id == 1 && as->jump_att_flag && (ds->cp->sw_new & CMD_LV_MASK)) || (ds->cp->sw_new & CMD_LV_UP)) {
    } else if (!(ds->saishin_lvdir & gddir)) {
        wf = ds->cp->waza_flag;
        if ((wf[3] + wf[4]) == 0) {
            return;
        }
    }
    judge_item[ds->wu.id][Play_Type].grd_miss++;
}

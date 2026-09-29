/*
 * CMB_CONT.C  Combo, reversal and parry bonus control and scoring
 *
 * Watches both players during a round and awards bonus messages and points.
 * combo_cont_main runs each frame (reset by Stop_Combo); combo_control checks for the end
 * of a combo (check_combo_end), reversals (reversal_check), parries (paring_check),
 * first attacks and super art finishes (super_arts_finish_check, arts_finish_check).
 * SCORE_CALCULATION totals the hits by attack kind against the points table and SCORE_PLUS
 * adds points to the round, game (capped at 99999900) or versus score.
 * combo_window_push queues a message for a player's combo window and combo_window_trans
 * draws queued messages with the CMB_WIN routines; grade_* calls feed the grading system.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLCNTDAT.h"
#include "cmb_win.h"
#include "Grade.h"
#include "meta_col.h"
#include "Win.h"
#include "EFFECT.h"
#include "cmb_cont.h"



void combo_cont_init(void) {
    u8 i;
    for (i = 0; i < 2; i++) {
        old_cmb_flag[i] = 0;
        cmb_stock[i] = 0;
        rever_attack[i] = 0;
        paring_attack[i] = 0;
        bonus_pts[i] = 0;
        sarts_finish_flag[i] = 0;
        cmb_calc_now[i] = 0;
        cst_read[i] = 0;
        cst_write[i] = 0;
    }
    first_attack = 0;
    hit_num = 0;
    sa_kind = 0;
    cmb_all_stock[0] = 0;
    last_hit_time = 0;
    for (i = 0; i < 2; i++) {
        work_init_zero((s32*)&combo_type[i], sizeof(ComboType));
    }
    for (i = 0; i < 2; i++) {
        work_init_zero((s32*)&remake_power[i], sizeof(ComboType));
    }
    for (i = 0; i < 2; i++) {
        memset(cmst_buff[i], 0, 64);
    }
    for (i = 0; i < 2; i++) {
        memset(calc_hit[i], 0, sizeof(calc_hit[0]));
    }
    for (i = 0; i < 2; i++) {
        memset(score_calc[i], 0, sizeof(score_calc[0]));
    }
}



void combo_cont_main(void) {

    if (Stop_Combo) {
        if (Demo_Flag) {
            combo_window_all_clear();
        }
        combo_cont_init();
        if (Demo_Flag) {
            Stop_Combo = 0;
        }
        return;
    }
    if (Demo_Flag != 0) {
        if (Game_pause) {
            combo_window_trans(0);
            combo_window_trans(1);
        } else if (Game_timer & 1) {
            combo_control(0);
            combo_window_trans(0);
            combo_control(1);
            combo_window_trans(1);
        } else {
            combo_control(1);
            combo_window_trans(1);
            combo_control(0);
            combo_window_trans(0);
        }
        cmb_all_stock[0] = cmb_stock[0] + cmb_stock[1];
    }
}



void combo_control(s32 pl_arg) {
    s32 PL = (s8)pl_arg;
    PLW* wk;
    s16 cmb_flag;
    s8 PLS;
    cmb_flag = check_combo_end(PL);
    if (cmb_flag) {
        cmb_calc_now[PL] = 1;
    } else {
        cmb_calc_now[PL] = 0;
    }
    if (reversal_check(PL) != 0) {
        return;
    }
    if (rever_attack[PL]) {
        reversal_continue_check(PL);
    }
    if (paring_check(PL) != 0) {
        return;
    }
    wk = (PLW*)((u8*)plw + (s16)(PL * 0x498));
    if (wk->cb->total == 0) {
        return;
    }
    if (first_attack == 0) {
        first_attack = wk->wu.id + 1;
        combo_window_push(PL, 4);
        return;
    }
    if (pcon_dp_flag == 1 && last_hit_time == 0) {
        super_arts_last_check(PL);
    }
    if (cmb_flag != 0) {
        return;
    }
    if ((*(ComboType**)((u8*)((void*)&(*(ComboType **)&(plw[0].cb))) + (s16)((PL) * 0x498)))->total == 1) {
        super_arts_finish_check(PL);
        combo_hensuu_clear(PL);
        first_attack = 3;
        return;
    }
    if (PL == 0) {
        PLS = 1;
    } else {
        PLS = 0;
    }
    hit_num = (*(ComboType**)((u8*)((void*)&(*(ComboType **)&(plw[0].cb))) + (s16)((PL) * 0x498)))->total;
    if (hit_num > 99) {
        hit_num = 99;
    }
    if (first_attack == 1 || first_attack == 2) {
        first_attack_pts_check(PL);
    }
    if (rever_attack[PLS] == 1) {
        bonus_pts[PL]++;
    }
    hit_combo_check(PL);
    combo_hensuu_clear(PL);
}



void combo_hensuu_clear(s8 PL) {
    work_init_zero((s32*)plw[PL].cb, sizeof(ComboType));
    combo_rp_clear_check(PL);
    memset(calc_hit[PL], 0, sizeof(calc_hit[0]));
    memset(score_calc[PL], 0, sizeof(score_calc[0]));
    bonus_pts[PL] = 0;
    plw[PL].cb->total = 0;
    hit_num = 0;
}



void combo_rp_clear_check(s8 PL) {
    if (plw[PL].wu.routine_no[1] != 1 || plw[PL].wu.routine_no[2] != 17 || plw[PL].wu.routine_no[3] == 0 ||
        plw[PL].wu.routine_no[3] == 3) {
        work_init_zero((s32*)plw[PL].rp, sizeof(ComboType));
    }
}



void super_arts_finish_check(s8 PL) {
    if (arts_finish_check2(PL) != 0) {
        if ((plw[PL].cb->new_dm & 0x3F) < 48) {
            sa_kind = 2;
        } else {
            sa_kind = 3;
        }
        combo_window_push(PL, 3);
    }
}



void super_arts_last_check(s8 PL) {
    if ((plw[PL].cb->new_dm & 0x3F) >= 0x20) {
        sarts_finish_flag[PL] = 1;
    } else {
        sarts_finish_flag[PL] = 0;
    }
    last_hit_time = 1;
}



void first_attack_pts_check(s8 PL) {
    if (first_attack - 1 == plw[PL].wu.id) {
        first_attack = 3;
        bonus_pts[PL] += 2;
    }
}



s32 reversal_check(s8 PL) {
    s8 PLS;
    if (rever_attack[PL]) {
        return 0;
    }
    if (plw[PL].wu.routine_no[1] == 4 && plw[PL].wu.old_rno[1] == 1 && pcon_dp_flag == 0 &&
        plw[PL].wu.routine_no[2] >= 0x10) {
        rever_attack[PL] = 1;
        if (PL == 0) {
            PLS = (1);
        } else {
            PLS = 0;
        }
        combo_window_push(PLS, 5);
        grade_add_reversal(PL);
        return 1;
    }
    return 0;
}



void reversal_continue_check(s8 PL) {
    if (plw[PL].wu.routine_no[1] != 4) {
        rever_attack[PL] = 0;
    } else {
        return;
    }
}



s32 paring_check(s8 PL) {
    s8 PLS;
    if (paring_bonus_r[PL]) {
        paring_bonus_r[PL] = 0;
        paring_attack[PL] = 1;
        if (PL == 0) {
            PLS = 1;
        } else {
            PLS = 0;
        }
        combo_window_push(PLS, 6);
        return 1;
    }
    return 0;
}



void hit_combo_check(s8 PL) {
    s32* sa_ptr = (s32*)plw[PL].cb->kind_of[4][0];
    s8 lpx;
    for (lpx = 0; lpx < 20; lpx++) {
        if (!(*sa_ptr++ == 0)) {
            if (arts_finish_check(PL)) {
                if (lpx < 8) {
                    bonus_pts[PL] += 2;
                    sa_kind = 2;
                } else {
                    bonus_pts[PL] += 3;
                    sa_kind = 3;
                }
                combo_window_push(PL, 2);
                return;
            }
            combo_window_push(PL, 1);
            return;
        }
    }
    combo_window_push(PL, 0);
}



s32 arts_finish_check(s8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && sarts_finish_flag[PL]) {
        return 1;
    }
    return 0;
}



s32 arts_finish_check2(s8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && (plw[PL].cb->new_dm & 0x3F) >= 32) {
        return 1;
    }
    return 0;
}



u32 SCORE_CALCULATION(s8 PL) {
    s16* c_ptr;
    s16* s_ptr;
    s16* k_ptr;
    s8 lpx;
    s8 lpy;
    s16 hit;
    s16 h;
    u32 score;
    s8 last;
    k_ptr = plw[PL].cb->kind_of[0][0];
    c_ptr = &calc_hit[PL][1];
    s_ptr = score_calc[PL];
    for (lpx = 0; lpx < 4; lpx++) {
        *s_ptr++ = k_ptr[0] + k_ptr[1];
        k_ptr += 2;
    }
    s_ptr = &score_calc[PL][4];
    for (lpy = 0; lpy < 8; lpy++) {
        *s_ptr++ = *c_ptr++;
    }
    hit = 0;
    score = 0;
    for (lpy = 0; lpy < 12; lpy++) {
        if (score_calc[PL][lpy]) {
            last = lpy;
            h = score_calc[PL][lpy];
            hit += h;
            score += *combo_score_tbl[lpy];
            if (h - 1) {
                score += (hit - 1) * combo_score_tbl[lpy][1];
            }
        }
    }
    if (bonus_pts[PL]) {
        score += bonus_pts[PL] * combo_score_tbl[last][1];
    }
    return score;
}



void SCORE_PLUS(s8 pl, u32 pts) {
    Score[pl][2] += pts;
    if (Play_Type == 0) {
        Score[pl][0] += pts;
        if (Score[pl][0] >= 99999900) {
            Score[pl][0] = 99999900;
        }
    } else {
        Score[pl][1] += pts;
    }
}



void combo_window_push(s8 PL, s8 KIND) {
    u32 score;
    s8 PLS;
    if (KIND < 3) {
        score = SCORE_CALCULATION(PL);
        grade_max_combo_check(PL ^ 1, hit_num);
    }
    if (PL == 0) {
        PLS = 1;
    } else {
        PLS = 0;
    }
    if (cmb_stock[PL] == 4) {
        switch (KIND) {
        case 2:
            if (sa_kind == 2) {
                score += 20000;
            } else {
                score += 30000;
            }
            break;
        case 3:
            if (sa_kind == 2) {
                score = 20000;
            } else {
                score = 30000;
            }
            break;
        case 4:
            score = 1500;
            grade_get_first_attack(PLS);
            break;
        case 6:
            score = paring_counter[PLS];
            score *= 100;
            break;
        }
        if (score >= 1000000) {
            score = 999900;
        }
        SCORE_PLUS(PLS, score);
        if (plw[PLS].wu.operator) {
            Disp_Player_Score(PLS);
        }
        return;
    }
    cmb_stock[PL]++;
    cmst_buff[PL][cst_write[PL]].routine_num = 0;
    cmst_buff[PL][cst_write[PL]].hit = hit_num;
    cmst_buff[PL][cst_write[PL]].kind = KIND;
    if (plw[PLS].wu.operator) {
        cmst_buff[PL][cst_write[PL]].pts_flag = 1;
    } else {
        cmst_buff[PL][cst_write[PL]].pts_flag = 0;
    }
    switch (KIND) {
    case 0:
    case 1:
        break;
    case 2:
        if (sa_kind == 2) {
            score += 20000;
        } else {
            score += 30000;
        }
        break;
    case 3:
        if (sa_kind == 2) {
            score = 20000;
        } else {
            score = 30000;
        }
        break;
    case 4:
        score = 1500;
        grade_get_first_attack(PLS);
        break;
    case 5:
        cmst_buff[PL][cst_write[PL]].pts_flag = 0;
        score = 0;
        break;
    case 6:
        score = paring_counter[PLS];
            score *= 100;
        break;
    }
    if (score >= 1000000) {
        score = 999900;
    }
    cmst_buff[PL][cst_write[PL]].pts = score;
    if (cst_write[PL] == 3) {
        cst_write[PL] = 0;
    } else {
        cst_write[PL]++;
    }
}



void combo_window_trans(s8 PL) {
    s8 PLS;
    if (cmb_stock[PL] != 0) {
        if (CMST(PL, cst_read[PL]).pts_flag) {
            switch (CMST(PL, cst_read[PL]).routine_num) {
            case 0:
                end_flag[PL] = 0;
                combo_message_set(PL, CMST(PL, cst_read[PL]).kind);
                switch (CMST(PL, cst_read[PL]).kind) {
                case 0:
                case 1:
                case 2:
                    combo_hitnum_set(PL, CMST(PL, cst_read[PL]).kind, CMST(PL, cst_read[PL]).hit);
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                    break;
                }
                CMST(PL, cst_read[PL]).move[0] = cmb_window_move_tbl[CMST(PL, cst_read[PL]).kind];
                CMST(PL, cst_read[PL]).x_posnum[0] = 0;
                CMST(PL, cst_read[PL]).timer[0] = 8;
                CMST(PL, cst_read[PL]).move[1] = combo_pts_set(PL, CMST(PL, cst_read[PL]).pts);
                CMST(PL, cst_read[PL]).x_posnum[1] = 0;
                CMST(PL, cst_read[PL]).routine_num++;
                break;
            case 1:
                if (!(end_flag[PL] & 1)) {
                    if (CMST(PL, cst_read[PL]).x_posnum[0] < CMST(PL, cst_read[PL]).move[0]) {
                        combo_window_slide(PL,
                                                CMB_POS(Game_setting.mode, PL, CMST(PL, cst_read[PL]).x_posnum[0]),
                                                0,
                                                CMST(PL, cst_read[PL]).x_posnum[0]);
                        CMST(PL, cst_read[PL]).x_posnum[0]++;
                    } else {
                        end_flag[PL] |= 1;
                    }
                }
                if (!(end_flag[PL] & 2)) {
                    CMST(PL, cst_read[PL]).timer[0]--;
                    if (CMST(PL, cst_read[PL]).timer[0] < 0) {
                        if (CMST(PL, cst_read[PL]).x_posnum[1] < CMST(PL, cst_read[PL]).move[1] + 2) {
                            if (CMST(PL, cst_read[PL]).x_posnum[1] < CMST(PL, cst_read[PL]).move[1]) {
                                combo_window_slide(PL,
                                                        CMB_POS(Game_setting.mode, PL, CMST(PL, cst_read[PL]).x_posnum[1]),
                                                        1,
                                                        CMST(PL, cst_read[PL]).x_posnum[1]);
                            } else {
                                combo_window_slide(PL,
                                                        CMB_POS(Game_setting.mode, PL, CMST(PL, cst_read[PL]).x_posnum[1]),
                                                        1,
                                                        CMST(PL, cst_read[PL]).move[1] - 1);
                            }
                            (*(CMST_WIN_R*)&cmst_buff[PL][cst_read[PL]]).x_posnum[1]++;
                        } else {
                            end_flag[PL] |= 2;
                        }
                    }
                }
                if ((end_flag[PL] & 3) == 3) {
                    CMST(PL, cst_read[PL]).routine_num++;
                    CMST(PL, cst_read[PL]).timer[1] = cmb_window_time_tbl[CMST(PL, cst_read[PL]).kind];
                    if (PL == 0) {
                        PLS = 1;
                    } else {
                        PLS = 0;
                    }
                    SCORE_PLUS(PLS, CMST(PL, cst_read[PL]).pts);
                    if (plw[PLS].wu.operator) {
                        Disp_Player_Score(PLS);
                    }
                }
                break;
            case 2:
                CMST(PL, cst_read[PL]).timer[1]--;
                if (CMST(PL, cst_read[PL]).timer[1] == 0) {
                    combo_window_erase(PL, CMST(PL, cst_read[PL]).kind, 0);
                    combo_window_erase(PL, 7, 1);
                    if (cst_read[PL] == 3) {
                        cst_read[PL] = 0;
                    } else {
                        cst_read[PL]++;
                    }
                    cmb_stock[PL]--;
                }
                break;
            }
        } else {
            switch (CMST(PL, cst_read[PL]).routine_num) {
            case 0:
                combo_message_set(PL, CMST(PL, cst_read[PL]).kind);
                switch (CMST(PL, cst_read[PL]).kind) {
                case 0:
                case 1:
                case 2:
                    combo_hitnum_set(PL, CMST(PL, cst_read[PL]).kind, CMST(PL, cst_read[PL]).hit);
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                    break;
                }
                CMST(PL, cst_read[PL]).move[0] = cmb_window_move_tbl[CMST(PL, cst_read[PL]).kind];
                CMST(PL, cst_read[PL]).x_posnum[0] = 0;
                CMST(PL, cst_read[PL]).routine_num++;
                break;
            case 1:
                if (CMST(PL, cst_read[PL]).x_posnum[0] < CMST(PL, cst_read[PL]).move[0]) {
                    combo_window_slide(PL,
                                            CMB_POS(Game_setting.mode, PL, CMST(PL, cst_read[PL]).x_posnum[0]),
                                            0,
                                            CMST(PL, cst_read[PL]).x_posnum[0]);
                    CMST(PL, cst_read[PL]).x_posnum[0]++;
                } else {
                    CMST(PL, cst_read[PL]).timer[1] = 36;
                    CMST(PL, cst_read[PL]).routine_num++;
                }
                break;
            case 2:
                CMST(PL, cst_read[PL]).timer[1]--;
                if (CMST(PL, cst_read[PL]).timer[1] == 0) {
                    combo_window_erase(PL, CMST(PL, cst_read[PL]).kind, 0);
                    if (CMST(PL, cst_read[PL]).pts_flag) {
                        CMST(PL, cst_read[PL]).routine_num++;
                        return;
                    }
                    if (cst_read[PL] == 3) {
                        cst_read[PL] = 0;
                    } else {
                        cst_read[PL]++;
                    }
                    cmb_stock[PL]--;
                }
                break;
            }
        }
    }
}

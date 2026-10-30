/*
 * MANAGE_2.C  Round and match management (part 2)
 *
 * Game_Management is called every fight frame (Game2_1, Bonus_Sub) and steps through the C_No
 * phases: stage setup, round call and fight start, the fight, KO / time over judgement
 * (Judge_Winner, Check_Perfect, win marks via effect_92_init), winner display and win poses, score
 * pooling and bonuses (Pool_Score, Additional_Bonus), match end, continue and break-in handling
 * (Loser_Sub, Be_Continue, Quick_Entry, Check_Break_Into_CPU), and the bonus stage result tallies
 * (Game_Manage_12_x). It also runs BGM_Fade_Sub and BGM_Control each frame.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "manage_2.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "EM_Cand.h"
#include "demo00.h"
#include "demo01.h"
#include "demo02_code.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "sc_clear.h"
#include "cmb_win.h"
#include "VITAL.h"
#include "count.h"
#include "spgauge.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "EffG0.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "Eff81.h"
#include "effb2.h"
#include "Grade.h"
#include "appear.h"
#include "ta_sub.h"
#include "eff35.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "Eff76.h"
#include "EFF84.h"
#include "bg000.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_main.h"
#include "Entry.h"
#include "entry_2.h"
#include "fighter.h"

/* C_No3, Game_Manage_12_4 */
#define CM12_4_T_BONUS  0       /* count up the bonus */
#define CM12_4_T_BONUS2 1       /* count up the bonus */
#define CM12_4_T_BONUS3 2       /* count up the bonus */

/* C_No3, Game_Manage_12_8 */
#define CM12_8_T_EFFECT 0       /* start effect 35 */
#define CM12_8_T_NEXT_STEP 1       /* until Next_Step */
#define CM12_8_T_WAIT   2       /* count down C_Timer */

/* C_No2, Game_Manage_2_4 */
#define CM2_4_FLASH     0       /* first round: flash the screen white; later rounds skip to the last step */
#define CM2_4_WAIT      1       /* count down C_Timer */
#define CM2_4_INTRO_DONE 2       /* allow breaks again; the stage intro is over */
#define CM2_4_NEXT_STEP 3       /* until Next_Step */

/* C_No2, Game_Manage_12_3 */
#define CM12_3_WAIT     0       /* wait C_Timer; a button cuts it short */
#define CM12_3_MESSAGE  1       /* until the message is gone */
#define CM12_3_WAIT2    2       /* count down C_Timer */
#define CM12_3_WAIT3    3       /* wait C_Timer; a button cuts it short */

/* C_No2, Game_Manage_12_4 */
#define CM12_4_BONUS    0       /* count up the bonus */
#define CM12_4_BONUS2   1       /* count up the bonus */
#define CM12_4_BONUS3   2       /* count up the bonus */
#define CM12_4_BONUS4   3       /* count up the bonus */

/* C_No2, Game_Manage_12_5 */
#define CM12_5_WAIT     0       /* count down C_Timer */
#define CM12_5_WAIT2    1       /* count down C_Timer */

/* C_No2, Game_Manage_12_8 */
#define CM12_8_WAIT     0       /* count down C_Timer */
#define CM12_8_BONUS    1       /* count up the bonus */
#define CM12_8_BONUS2   2       /* count up the bonus */
#define CM12_8_BONUS3   3       /* count up the bonus */
#define CM12_8_WAIT2    4       /* count down C_Timer */

/* C_No2, Check_Time_Over */
#define TIME_OVER_CHECK 0       /* until Time_Over, then show TIME OVER and pause */
#define TIME_OVER_WAIT  1       /* count down C_Timer */

/* C_No1, Game_Manage_6th */
#define CM6_VICTORY     0       /* until the win is shown */
#define CM6_WAIT        1       /* count down C_Timer */

/* C_No1, Game_Manage_9th */
#define CM9_JUDGE       0       /* match won: on to the next scene; otherwise the next round */
#define CM9_WAIT        1       /* count down C_Timer */

/* C_No1, Game_Manage_10th */
#define CM10_WAIT       0       /* wait C_Timer; a button cuts it short */
#define CM10_WIPE_WAIT  1       /* until the wipe is done */

/* C_No1, Game_Manage_11th */
#define CM11_START      0       /* start the screen's effects */
#define CM11_WAIT       1       /* count down C_Timer */
#define CM11_WAIT2      2       /* count down C_Timer */
#define CM11_WIPE_WAIT  3       /* until the wipe is done */
#define CM11_WIPE_WAIT2 4       /* until the wipe is done */

/* BGM_No[0]: the music change (BGM_Control) */
#define BGM_IDLE        0       /* nothing to do */
#define BGM_ROUND_WAIT  1       /* the next round: wait BGM_Timer */
#define BGM_ROUND       2       /* when the music has stopped, the stage music */
#define BGM_JUDGE_WAIT  3       /* the judges' decision: wait BGM_Timer */
#define BGM_JUDGE       4       /* when the music has stopped, bgm_request(6) */

void Scrn_Move_Set(s32 n, s16 x, s16 y);

#pragma inline(request_center_message)

void sound_reg_level_set(s16 pitch, s8 volume);



s32 Game_Management(void) {
    void (*Management_Jmp_Tbl[12])() = { Game_Manage_1st, Game_Manage_2nd, Game_Manage_3rd, Game_Manage_4th, Game_Manage_5th, Game_Manage_6th, Game_Manage_7th, Game_Manage_8th, Game_Manage_9th, Game_Manage_10th, Game_Manage_11th, Game_Manage_12th };
    if (Break_Into) {
        return 0;
    }
    MANAGE_X = 0;
    Management_Jmp_Tbl[C_No0]();
    BGM_Fade_Sub();
    BGM_Control();
    return MANAGE_X;
}



void Game_Manage_1st(void) {
    EXE_obroll = 0;
    if (bg_w.stage == BONUS_PARRY || bg_w.stage == BONUS_CAR) {
        C_No0 = C0_BONUS;
    } else {
        C_No0 = C0_ROUND_START;
    }
    win_pause_go = 0;
    if (bg_w.bgw[1].zuubun) {
        zuubun_base_x = 0x200;
    }
    appear_work_clear();
    win_sp_flag = 0;
    BGM_No[1] = 0;
    BGM_No[0] = 0;
    Shin_Gouki_BGM = 0;
    Special_Settle = 0;
    Appear_Q = 0;
    Clear_1Stage_Work();
    All_Clear_Suicide();
    Round_Operator[0] = 0;
    Round_Operator[1] = 0;
    if (plw[0].wu.operator) {
        Round_Operator[0] = 1;
        Final_Play_Type[0] = Play_Type;
    }
    if (plw[1].wu.operator) {
        Round_Operator[1] = 1;
        Final_Play_Type[1] = Play_Type;
    }
    Battle_Q[0] = 0;
    Battle_Q[1] = 0;
    if (Play_Type == PLAY_VS_CPU) {
        Control_Time = SC_Personal_Time[Player_id];
        paring_ctr_ori[Player_id] = paring_ctr_vs[0][Player_id] = 0;
        Stage_Stock_Score[Player_id] = Score[Player_id][SCORE_CPU];
        Request_Disp_Rank[COM_id][RANK_SCORE] = -1;
        Request_Disp_Rank[COM_id][RANK_WINS] = -1;
        Request_Disp_Rank[COM_id][RANK_CPU_GRADE] = -1;
        Request_Disp_Rank[COM_id][RANK_GRADE] = -1;
        if (EM_id == PL_Q) {
            Break_Into_CPU = 2;
        } else {
            Break_Into_CPU = 0;
        }
    }
    eff_hit_flag_clear();
    Check_Stage_BGM();
    Fade_Flag = 0;
    Clear_Flash_No();
    scfont_page1_fill(0, 32);
    commit_name_entry_row_both_players(32);
    grade_check_work_stage_init(0);
    grade_check_work_stage_init(1);
}



void Clear_1Stage_Work(void) {
    s16 xx;
    xx = 0;
    do {
        Vital_Bonus[xx] = 0;
        Time_Bonus[xx] = 0;
        Perfect_Bonus[xx] = 0;
        Perfect_Counter[xx] = 0;
        Stage_SA_Finish[xx] = 0;
        Stage_Lost_Round[xx] = 0;
        Stage_Perfect_Finish[xx] = 0;
        Stage_Cheap_Finish[xx] = 0;
        Stage_Judge_Finish[xx] = 0;
        Stage_Time_Finish[xx] = 0;
    } while (++xx < 2);
}



void Game_Manage_2nd(void) {
    void (*SC2_Jmp_Tbl[5])() = { Game_Manage_2_0, Game_Manage_2_1, Game_Manage_2_2, Game_Manage_2_3, Game_Manage_2_4 };
    SC2_Jmp_Tbl[C_No1]();
}



void Game_Manage_2_0(void) {
    request_message = 0;
    if (Demo_Flag == 0) {
        C_No1 = 2;
    } else if (--Cover_Timer == 0) {
        C_No1++;
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_2_1(void) {
    if (Switch_Screen_Revival()) {
        C_No1++;
        Stage_Intro_Flag = 0;
    }
}



void Game_Manage_2_2(void) {
    Suicide[0] = 0;
    if (effect_84_init()) {
        return;
    }
    C_No1++;
    Forbid_Break = 0;
    Extra_Break = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    Judge_Round_Flag = 0;
    Stop_Combo = 0;
    if (Demo_Flag) {
        Stop_SG = 0;
    }
    Complete_Judgement = 0;
    judge_flag = 0;
    BGM_Fade_Out_Flag = 0;
    Pause_Hit_Marks = 0;
    CP_No[0][0] = COM_INIT;
    CP_No[1][0] = COM_INIT;
    Stock_Score[0] = Score[0][SCORE_CPU];
    Stock_Score[1] = Score[1][SCORE_CPU];
    grade_check_work_round_init(0);
    grade_check_work_round_init(1);
}



void Game_Manage_2_3(void) {
    if (Appear_end < 2) {
        return;
    }
    if (bg_app) {
        return;
    }
    appear_work_clear();
    win_sp_flag = 0;
    if (pcon_rno[0] != PCON_INIT) {
        return;
    }
    if (pcon_rno[1] != APP_WAIT_READY) {
        return;
    }
    C_No1++;
    effect_B2_init();
}



void Game_Manage_2_4(void) {
    switch (C_No2) {
    case CM2_4_FLASH:
        if (Round_num) {
            C_No2 = CM2_4_NEXT_STEP;
        } else {
            C_No2++;
            C_Timer = 1;
            Forbid_Break = 1;
            /* The white flash before the first round: the intro shows text page 1, and this fills all of it with
               cell 175 in palette 60, a solid white cell over the whole screen. Next frame (case 1) the text layer
               scrolls back to page 0 for the fight HUD; with the scroll applied at the following vblank the screen
               stays white for 3 frames. Filling with (0, 32), blank cells, removes the flash and changes no timing. */
            scfont_page1_fill(60, 175);
        }
        break;
    case CM2_4_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            Text_Page_Y = 0;
            Clear_Flash_No();
            commit_name_entry_row_both_players(0);
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    case CM2_4_INTRO_DONE:
        C_No2++;
        Forbid_Break = 0;
        Stage_Intro_Flag = 0x80;
        break;
    case CM2_4_NEXT_STEP:
        if (Next_Step != 0) {
            C_No0++;
            C_No1 = 0;
            C_No2 = CM2_4_FLASH;
            Allow_a_battle_f = 1;
            if (Play_Type == PLAY_VS_CPU && EM_id == PL_GILL) {
                if (!(Introduce_Boss[Player_id][1] & 0x80)) {
                    Introduce_Boss[Player_id][1] |= 0x80;
                    Check_Stage_BGM();
                }
            }
            load_char_eff_color(My_char[0], 0);
            load_char_eff_color(My_char[1], 1);
            if (Demo_Flag == 0) {
                effect_58_init(10, 60, -1);
            }
        }
        break;
    }
}



void Game_Manage_3rd(void) {
    if (Demo_Flag != 0 && Conclusion_Flag != 0) {
        C_No0++;
        Forbid_Break = -1;
        Allow_a_battle_f = 0;
        counter_color_clear();
        setFinishType();
        G_Timer = 900;
    }
}



void setFinishType(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (Round_Operator[Winner_id] == 0) {
        Lost_Round[Loser_id]++;
        Stage_Lost_Round[Loser_id]++;
        return;
    }
    switch (Conclusion_Type) {
    case CONCLUSION_KO:
        break;
    case CONCLUSION_DOUBLE_KO:
        Lost_Round[Player_id]++;
        Stage_Lost_Round[Player_id]++;
        break;
    case CONCLUSION_TIME_OVER:
        if (plw[0].wu.vital_new != plw[1].wu.vital_new) {
            Stage_Time_Finish[Winner_id]++;
        } else {
            Stage_Judge_Finish[Winner_id]++;
        }
        break;
    }
    Update_BI_Term();
}



void Game_Manage_4th(void) {
    switch (Conclusion_Type) {
    case CONCLUSION_KO:
        C_No0 = C0_ROUND_WIN;
        Setup_Win_Mark();
        Check_Perfect(Winner_id);
        PL_Wins[Winner_id]++;
        Update_VS_Data();
        Ck_Win_Record();
        Update_Level_Control();
        break;
    case CONCLUSION_DOUBLE_KO:
        sound_request(121);
        sound_request(139);
        if (Judge_Next_Disposal()) {
            C_No0 = C0_JUDGE;
            break;
        }
        C_No0 = C0_DRAW;
        Round_Result |= RESULT_DRAW;
        win_type[0][PL_Wins[0]] = WIN_MARK_DRAW;
        win_type[1][PL_Wins[1]] = WIN_MARK_DRAW;
        PL_Wins[0]++;
        PL_Wins[1]++;
        if (PL_Wins[0] >= Battle_Round[Play_Type] + 1) {
            Winner_id = 0;
            Loser_id = 1;
            Update_VS_Data();
            Ck_Win_Record();
            break;
        }
        if (PL_Wins[1] >= Battle_Round[Play_Type] + 1) {
            Winner_id = 1;
            Loser_id = 0;
            Update_VS_Data();
            Ck_Win_Record();
        }
        break;
    default:
        sound_request(143);
        if (plw[0].wu.vital_new != plw[1].wu.vital_new) {
            C_No0 = C0_ROUND_WIN;
            Round_Result |= RESULT_TIME;
            (&win_type[Winner_id][0])[PL_Wins[Winner_id]] = WIN_MARK_NORMAL;
            Check_Perfect(Winner_id);
            PL_Wins[Winner_id]++;
            Update_VS_Data();
            Ck_Win_Record();
            Update_Level_Control();
            break;
        }
        C_No0 = C0_JUDGE;
        break;
    }
}



void Setup_Win_Mark(void) {
    if (Round_Result & RESULT_CHIP) {
        win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_CHIP;
        sound_request(121);
        sound_request(140);
        Finish_SE();
        return;
    }
    if (Round_Result & 0x180) {
        Setup_BGM_Fade_In(150);
        sound_reg_level_set(0, -128);
        (&win_type[Winner_id][0])[PL_Wins[Winner_id]] = WIN_MARK_SA;
        sound_request(140);
        Finish_SE();
        return;
    }
    if (Round_Result & 0x800) {
        if (Shin_Gouki_BGM == 0) {
            Setup_BGM_Fade_In(150);
            sound_reg_level_set(0, -128);
        } else {
            Shin_Gouki_BGM = 0;
        }
        (&win_type[Winner_id][0])[PL_Wins[Winner_id]] = WIN_MARK_SA;
        sound_request(0x8CU);
        Finish_SE();
        return;
    }
    win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_NORMAL;
    sound_request(121);
    sound_request(140);
    Finish_SE();
}

void Update_BI_Term(void)
{
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (plw[Winner_id].sa_healing) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
        return;
    }
    if (plw[Winner_id].wu.vitality == plw[Winner_id].wu.vital_new) {
        Perfect_Finish[Winner_id]++;
        Stage_Perfect_Finish[Winner_id]++;
        if (Round_Result & 0x980) {
            Super_Arts_Finish[Winner_id]++;
            Stage_SA_Finish[Winner_id]++;
        }
        return;
    }
    if (Round_Result & RESULT_CHIP) {
        Cheap_Finish[Winner_id]++;
        Stage_Cheap_Finish[Winner_id]++;
        return;
    }
    if (Round_Result & 0x980) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
    }
}



void Game_Manage_5th(void) {
    void (*SC5_Jmp_Tbl[8])() = { Game_Manage_5_0, Game_Manage_5_1, Game_Manage_5_2, Game_Manage_5_3, Game_Manage_5_4, Game_Manage_5_5, Game_Manage_5_6, Game_Manage_5_7 };
    SC5_Jmp_Tbl[C_No1]();
}



void Game_Manage_5_0(void) {
    if (Complete_Victory != 0 || --G_Timer == 0) {
        C_No1++;
        C_Timer = 30;
        Judge_Round_Flag = 1;
        Event_Judge_Gals = 0;
    }
}



void Game_Manage_5_1(void) {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No1++;
        request_center_message(3);
        sound_request(154);
    }
}



void Game_Manage_5_2(void) {
    if (request_message) {
        return;
    }
    C_No1++;
    C_Timer = 30;
}



void Game_Manage_5_3(void) {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No1++;
        Judge_Winner();
        sc_vram_to_ram();
        Stop_Combo = 1;
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_5_4(void) {
    if (Switch_Screen()) {
        C_No1++;
        Switch_Screen_Init(3, 3);
        Cover_Timer = 5;
        reset_all_char_display_with_backup();
        judge_flag = 1;
        load_bg_color_fade(bg_palette_no_tbl[bg_w.bg_index], 15, 15, 15);
        load_bg_color_fade(bg_color2_tbl[bg_w.bg_index], 15, 15, 15);
        pcon_rno[0] = PCON_INIT;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = APPEAR_JUDGE;
    }
}



void Game_Manage_5_5(void) {
    if (--Cover_Timer == 0) {
        C_No1++;
        pcon_rno[1] = SETTLE_JUDGE;
        pcon_rno[2] = 1;
        Clear_Flash_No();
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_5_6(void) {
    if (Switch_Screen_Revival()) {
        C_No1++;
        C_Timer = 60;
        Stop_SG = 0;
        BGM_No[0] = BGM_JUDGE_WAIT;
        BGM_Timer[0] = 1;
    }
}



void Game_Manage_5_7(void) {
    if (--C_Timer != 0) {
        return;
    }
    C_No0 = C0_ROUND_WIN;
    C_No1 = 7;
    C_Timer = 30;
    Fade_Half_Flag = 1;
    Complete_Judgement = 1;
    Round_Result |= RESULT_JUDGE;
    win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_JUDGE;
    Stage_Judge_Finish[Winner_id]++;
    Check_Perfect(Winner_id);
    PL_Wins[Winner_id]++;
    Update_VS_Data();
    Update_Level_Control();
}



void Game_Manage_6th(void) {
    switch (C_No1) {
    case CM6_VICTORY:
        if (Complete_Victory != 0 || --G_Timer == 0) {
            C_No1++;
            C_Timer = 60;
            pcon_rno[1] = SETTLE_JUDGE;
            pcon_rno[2] = 0;
            grade_makeup_round_para_dko();
            effect_58_init(6, 1, Winner_id + 100);
            effect_92_init(0, win_type[0][PL_Wins[0] - 1]);
            effect_92_init(1, win_type[1][PL_Wins[1] - 1]);
        }
        break;
    case CM6_WAIT:
        if (--C_Timer == 0) {
            C_No0 = C0_ROUND_END;
            C_No1 = CM6_VICTORY;
            Round_num++;
            Quick_Entry();
        }
        break;
    }
}



void Game_Manage_7th(void) {
    void (*SC7_Jmp_Tbl[10])() = { Game_Manage_7_0, Game_Manage_7_1, Game_Manage_7_2, Game_Manage_7_3, Game_Manage_7_4, Game_Manage_7_5, Game_Manage_7_6, Game_Manage_7_7, Game_Manage_7_8, Game_Manage_7_9 };
    SC7_Jmp_Tbl[C_No1]();
}



void Game_Manage_7_0(void) {
    if (Complete_Victory != 0 || --G_Timer == 0) {
        C_No1++;
        C_Timer = 1;
        grade_makeup_round_parameter(Winner_id);
        effect_92_init(Winner_id, win_type[Winner_id][PL_Wins[Winner_id] - 1]);
        effect_58_init(6, 1, Winner_id + 100);
    }
}



void Game_Manage_7_1(void) {
    if (--C_Timer == 0) {
        C_No1++;
        C_Timer = 10;
    }
}



void Game_Manage_7_2(void) {
    if (!Button_Cut_EX(&C_Timer, 0x7FFF)) {
        return;
    }
    if (Check_Disp_Combo()) {
        C_Timer = 1;
        return;
    }
    C_No1++;
    if (Check_Disp_Winner() == 0) {
        C_Timer = 50;
    } else {
        Disp_Winner();
        C_Timer = 90;
    }
    if (Round_Operator[Winner_id] == 0 && Perfect_Flag == 0) {
        Check_Fade_Out_BGM(182);
    }
}



s32 Check_Disp_Combo(void) {
    if (cmb_all_stock != 0 || cmb_calc_now[0] != 0 || cmb_calc_now[1] != 0) {
        return 1;
    }
    if (PL_Wins[Winner_id] < Battle_Round[Play_Type] + 1) {
        return 0;
    }
    return 0;
}



void Game_Manage_7_3(void) {
    if (Play_Type == PLAY_VS_CPU && Perfect_Flag == 0) {
        if (--C_Timer) {
            return;
        }
    } else {
        if (--C_Timer) {
            return;
        }
    }
    tilemap_clear_rect(DE_X[3] + 8, 9, DE_X[1] + 47, 16);
    if (Perfect_Flag) {
        C_No1++;
        C_Timer = 10;
    } else {
        C_No0++;
        C_No1 = 0;
        Event_Judge_Gals = -1;
    }
}



void Game_Manage_7_4(void) {
    if (--C_Timer == 0) {
        C_No1++;
        request_center_message(4);
        effect_58_init(6, 1, 155);
        effect_58_init(6, 60, 156);
    }
}



void Game_Manage_7_5(void) {
    if (request_message) {
        return;
    }
    C_No1++;
    C_Timer = 6;
    Event_Judge_Gals = -1;
}



void Game_Manage_7_6(void) {
    if (Scene_Cut) {
        C_Timer = 1;
    }
    if (--C_Timer == 0) {
        C_No0++;
        C_No1 = 0;
    }
}



void Game_Manage_7_7(void) {
    if (--C_Timer == 0) {
        C_No1++;
        Event_Judge_Gals = 3;
    }
}



void Game_Manage_7_8(void) {
    if (Event_Judge_Gals == 0) {
        C_No1++;
        C_Timer = 30;
        Ck_Win_Record();
    }
}



void Game_Manage_7_9(void) {
    if (--C_Timer == 0) {
        C_No1 = 0;
    }
}



void Game_Manage_8th(void) {
    void (*SC8_Jmp_Tbl[4])() = { Game_Manage_8_0, Game_Manage_8_1, Game_Manage_8_2, Game_Manage_8_3 };
    SC8_Jmp_Tbl[C_No1]();
}



void Game_Manage_8_0(void) {
    Round_num++;
    Quick_Entry();
    if (Round_Operator[Winner_id]) {
        Pool_Score(WINNER);
        if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            C_No1++;
            Additional_Bonus(WINNER);
            grade_makeup_stage_parameter(WINNER);
            grade_makeup_stage_parameter(LOSER);
            Check_Break_Into_CPU(WINNER);
        } else {
            C_No1 = 3;
            C_Timer = 1;
        }
    } else {
        C_No1 = 3;
        C_Timer = 30;
        if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            grade_makeup_stage_parameter(WINNER);
            grade_makeup_stage_parameter(LOSER);
        }
    }
}



void Game_Manage_8_1(void) {
    void (*SC81_Jmp_Tbl[4])() = { Game_Manage_81_0, Game_Manage_81_1, Game_Manage_81_2, Game_Manage_81_3 };
    SC81_Jmp_Tbl[C_No2]();
}



void Game_Manage_81_0(void) {
    s16 time;
    s16 pos_id;
    s16 pos_id2;
    Check_Fade_Out_BGM(546);
    C_No2++;
    C_Timer = 20;
    Forbid_Break = -1;
    load_char_gfx(0xBD28, 1);
    pos_id = 0;
    pos_id2 = 0;
    time = 1;
    Order[74] = 1;
    Order_Timer[74] = time;
    Order_Dir[74] = pos_id++;
    effect_76_init(74);
    time += 5;
    if (Perfect_Flag) {
        Order[76] = 1;
        Order_Timer[76] = time;
        Order_Dir[76] = pos_id++;
        effect_76_init(76);
        Order[81] = 0;
        effect_G0_init(81, time, Perfect_Bonus[Winner_id], pos_id2++);
        time += 5;
    }
    Order[78] = 1;
    Order_Timer[78] = time;
    Order_Dir[78] = pos_id++;
    effect_76_init(78);
    Order[83] = 0;
    effect_G0_init(83, time, Vital_Bonus[Winner_id], pos_id2++);
    time += 5;
    Order[79] = 1;
    Order_Timer[79] = time;
    Order_Dir[79] = pos_id++;
    effect_76_init(79);
    Order[84] = 0;
    effect_G0_init(84, time, Time_Bonus[Winner_id], pos_id2++);
    time += 5;
    Order[75] = 1;
    Order_Timer[75] = time;
    Order_Dir[75] = pos_id++;
    effect_76_init(75);
    Order[80] = 0;
    Order_Dir[80] = 1;
    effect_G0_init(80, time, Complete_Bonus, pos_id2);
}



void Game_Manage_81_1(void) {
    if (Order_Dir[80] == 0) {
        C_No2++;
        C_Timer = 20;
    }
}



void Game_Manage_81_2(void) {
    if (Scene_Cut) {
        C_Timer = 1;
    }
    if (--C_Timer != 0) {
        return;
    }
    C_No2++;
    Disp_Player_Score(Winner_id);
    Order_Dir[80] = 1;
    Order[81] = 1;
    Order[83] = 1;
    Order[84] = 1;
    Order[80] = 1;
    Sound_SE(100);
}



void Game_Manage_81_3(void) {
    if (Order_Dir[80] == 0) {
        C_No1++;
        C_No2 = 0;
        C_Timer = 50;
    }
}



void Game_Manage_8_2(void) {
    if (Request_Break[Winner_id ^ 1]) {
        C_Timer = 1;
    }
    if (Scene_Cut) {
        C_Timer = 1;
    }
    if (--C_Timer != 0) {
        return;
    }
    if (Game_setting.Event) {
        tilemap_clear_rect(0, 0, 47, 31);
    } else {
        if (Winner_id == 0) {
            tilemap_clear_rect(0, 0, 26, 1);
        } else {
            tilemap_clear_rect(21, 0, 47, 1);
        }
        tilemap_clear_rect(0, 1, 47, 31);
    }
    if (Check_Entry_Again()) {
        Forbid_Break = 0;
    }
    Suicide[2] = 1;
    gauge_stop_flag[0] = 1;
    gauge_stop_flag[1] = 1;
    C_No0++;
    C_No1 = 0;
    C_Timer = 30;
}



void Game_Manage_8_3(void) {
    if (Scene_Cut) {
        C_Timer = 1;
    }
    if (--C_Timer == 0) {
        C_No0++;
        C_No1 = 0;
    }
}



void Pool_Score(s16 PL_id) {
    u32 Score_Buff;
    if (Perfect_Flag) {
        Perfect_Bonus[Winner_id] += 50000;
    }
    Score_Buff = plw[PL_id].wu.vital_new * 100 / Max_vitality;
    Score_Buff *= 500;
    Vital_Bonus[Winner_id] += Score_Buff;
    Time_Bonus[Winner_id] += *(s16*)&round_timer * 300;
}



const u32 Comp_Bonus_Data[11] = {
    30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000,
    110000, 120000, 130000,
};


void Additional_Bonus(s16 PL_id) {
    Complete_Bonus = Setup_Comp_Bonus();
    Score[PL_id][Play_Type] += Perfect_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Vital_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Time_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Complete_Bonus;
    if (Score[PL_id][Play_Type] >= 99999900) {
        Score[PL_id][Play_Type] = 99999900;
    }
}



/* provisional name */
u32 Setup_Comp_Bonus(void) {
    u32 xx;
    u16 zz;
    if (Play_Type == PLAY_VS_PLAYER) {
        if (PL_Wins[Loser_id]) {
            return 0;
        }
        return 30000;
    }
    if (PL_Wins[Loser_id]) {
        return Straight_Counter[Winner_id] = 0;
    }
    Straight_Counter[Winner_id]++;
    if (Straight_Counter[Winner_id] >= 12) {
        Straight_Counter[Winner_id] = 11;
    }
    zz = Straight_Counter[Winner_id];
    xx = Comp_Bonus_Data[zz - 1];
    return xx;
}



void Game_Manage_9th(void) {
    switch (C_No1) {
    case CM9_JUDGE:
        if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            C_No0++;
            C_No1 = CM9_JUDGE;
            C_Timer = 75;
            sc_vram_to_ram();
            if (Play_Type != PLAY_VS_PLAYER) {
                if (Round_Operator[WINNER]) {
                    if (Battle_Q[WINNER]) {
                        C_No0 = C0_Q;
                    }
                }
            }
        } else {
            C_No1++;
            C_Timer = 60;
            satime_stock_clear();
            sc_vram_to_ram();
            Stop_Combo = 1;
            BGM_Timer[1] = 1;
        }
        break;
    case CM9_WAIT:
        if (Scene_Cut) {
            C_Timer = 1;
        }
        if (--C_Timer > 0) {
            return;
        }
        C_No1++;
        Game_pause = 1;
        Switch_Screen_Init(3, 3);
    default:
        if (Switch_Screen()) {
            BGM_No[0] = BGM_ROUND_WAIT;
            BGM_Timer[0] = 1;
            G_No2 = G2_ROUND_RESET2;
            G_No3 = 0;
            G_Timer = 4;
            Cover_Timer = 5;
            C_No0 = C0_ROUND_START;
            C_No1 = C_No2 = C_No3 = 0;
            Suicide[0] = 1;
        }
        break;
    }
}



void Game_Manage_10th(void) {
    switch (C_No1) {
    case CM10_WAIT:
        if (Button_Cut_EX(&C_Timer, 0x7FFF)) {
            C_No1++;
            Cover_Timer = 25;
            sc_vram_to_ram();
            Stop_Combo = 1;
            Game_pause = 1;
            Switch_Screen_Init(3, 3);
        }
        break;
    case CM10_WIPE_WAIT:
        if (Switch_Screen()) {
            effect_work_quick_init();
            sound_system_init();
            Check_Naming(0);
            Check_Naming(1);
            pcon_rno[1] = pcon_rno[0] = PCON_INIT;
            pcon_rno[2] = 0;
            pcon_rno[3] = 0;
            appear_type = APPEAR_ENTRY;
            Continue_Coin2[WINNER] = 0;
            if (Round_Operator[WINNER]) {
                G_No1 = G1_WINNER;
                G_No2 = 0;
                G_No3 = 0;
                M_No0 = 0;
                M_No1 = 0;
                M_No2 = 0;
                M_No3 = 0;
                E_No0 = E0_WINNER;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Check_Ending();
                Continue_Coin2[WINNER] = 0;
                Clear_Flash_No();
            } else {
                G_No1 = G1_LOSER;
                G_No2 = 0;
                G_No3 = 0;
                M_No0 = 0;
                M_No1 = 0;
                M_No2 = 0;
                M_No3 = 0;
                E_No0 = E0_LOSER;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                E_07_Flag[0] = 0;
                E_07_Flag[1] = 0;
                Clear_Flash_No();
            }
        }
        break;
    }
}



void Game_Manage_11th(void) {
    switch (C_No1) {
    case CM11_START:
        Forbid_Break = -1;
        C_No1++;
        EM_Rank = 2;
        Q_Country = Battle_Country;
        C_Timer = 90;
        effect_81_init(30);
        break;
    case CM11_WAIT:
        if (--C_Timer == 0) {
            C_No1++;
            C_Timer = 150;
            C_Timer = 60;
        }
        break;
    case CM11_WAIT2:
        if (--C_Timer == 0) {
            C_No1++;
            Switch_Screen_Init(0, 2);
        }
        break;
    case CM11_WIPE_WAIT:
        if (Switch_Screen()) {
            C_No1++;
            tilemap_clear_rect(DE_X[3], Text_Page_Y + 11, DE_X[3] + 47, Text_Page_Y + 13);
            sc_vram_to_ram();
            Switch_Screen_Init(3, 1);
        }
        break;
    case CM11_WIPE_WAIT2:
        if (Switch_Screen()) {
            G_No1 = G1_NEXT_Q;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_NEXT_CPU;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            effect_work_quick_init();
            Cover_Timer = 21;
        }
        break;
    }
}



void Check_Naming(id)
s16 id;
{
    s32 num;
    if (!Game_setting.Event) {
        num = E_Number[id][0];
        if (num != ENTRY_NAME && num != ENTRY_NAME_WAIT) {
            Rank_In[id][RANK_SCORE] = -1;
            Rank_In[id][RANK_WINS] = -1;
            Rank_In[id][RANK_CPU_GRADE] = -1;
            Rank_In[id][RANK_GRADE] = -1;
        }
    }
}



void Game_Manage_12th(void) {
    void (*SC12_Jmp_Tbl[10])() = { Game_Manage_12_0, Game_Manage_12_1, Game_Manage_12_7, Game_Manage_12_3, Game_Manage_12_4, Game_Manage_12_5, Game_Manage_12_1, Game_Manage_12_2, Game_Manage_12_8, Game_Manage_12_5 };
    SC12_Jmp_Tbl[C_No1]();
}



void Game_Manage_12_0(void) {
    Suicide[0] = 0;
    if (effect_84_init()) {
        return;
    }
    C_No1++;
    Extra_Break = 0;
    request_message = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    Judge_Round_Flag = 0;
    Stop_Combo = 0;
    if (Demo_Flag) {
        Stop_SG = 0;
    }
    Complete_Judgement = 0;
    judge_flag = 0;
    BGM_Fade_Out_Flag = 0;
    win_sp_flag = 0;
    Round_Operator[0] = plw[0].wu.operator;
    Round_Operator[1] = plw[1].wu.operator;
    CP_No[0][0] = COM_INIT;
    CP_No[1][0] = COM_INIT;
    Stock_Score[Player_id] = Score[Player_id][SCORE_CPU];
    load_any_color(179);
    if (Bonus_Type == BONUS_CAR) {
        C_No1 = 6;
        Time_Stop = 1;
        Time_Over = 0;
        Exit_No = 0;
        Unit_Of_Timer = 0;
        setup_bonus_car_parts();
        bcount_cont_init(1);
    }
}



void Game_Manage_12_1(void) {
    if (Next_Step == 0) {
        return;
    }
    C_No1++;
    C_No2 = 0;
    C_No3 = 0;
    Allow_a_battle_f = 1;
    load_char_eff_color(My_char[0], 0);
    load_char_eff_color(My_char[1], 1);
}



void Game_Manage_12_7(void) {
    bcount_cont_main();
    if (Bonus_Game_Complete) {
        C_No1++;
        C_No2 = 0;
        C_Timer = 30;
        Forbid_Break = -1;
        Completion_Bonus[Player_id][1] = -128;
        Stock_Bonus_Game_Result = Bonus_Game_result;
        Bonus_Score = 0;
        Final_Bonus_Score = Setup_Final_Score(22);
        ToneDown(8);
        ToneDown(9);
        effect_58_init(6, 10, 169);
        grade_makeup_bonus_parameter(Player_id);
        if (Check_Bonus_Perfect()) {
            C_Timer = 20;
        } else {
            C_No1 = 4;
        }
    }
}



void Game_Manage_12_3(void) {
    switch (C_No2) {
    case CM12_3_WAIT:
        if (Cut_Cut_C_Timer() == 0) {
            C_No2++;
            C_Timer = 10;
            request_center_message(4);
            effect_58_init(6, 1, 155);
            effect_58_init(6, 60, 156);
            return;
        }
        break;
    case CM12_3_MESSAGE:
        if (request_message == 0) {
            C_No2++;
            C_Timer = 6;
        }
        break;
    case CM12_3_WAIT2:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            ToneDown(8);
            ToneDown(9);
            return;
        }
        break;
    case CM12_3_WAIT3:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = CM12_3_WAIT;
            C_No3 = 0;
            C_Timer = 30;
        }
        break;
    }
}



void Game_Manage_12_4(void) {
    switch (C_No2) {
    case CM12_4_BONUS:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            sc_ram_to_vram_opc(27, Game_setting.Screen_Mode * 7, 1, 30);
            Disp_Digit16x24(Bonus_Score, DE_X[3] + 35, 11, 30);
        }
        break;
    case CM12_4_BONUS2:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 1;
            Bonus_Score = 0;
        }
        break;
    case CM12_4_BONUS3:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            if (Bonus_Game_result == 0 && !(PB_Status & 2)) {
                C_No2 = 4;
                C_Timer = 30;
                break;
            }
            if (Bonus_Game_result == 0) {
                Bonus_Game_result = 1;
            } else {
                Bonus_Score += 1000;
                Score[Player_id][SCORE_CPU] += 1000;
                Disp_Digit16x24(Bonus_Score, DE_X[3] + 35, 11, 30);
                Sound_SE(100);
            }
            if (--Bonus_Game_result == 0) {
                C_No2++;
                if (PB_Status) {
                    C_No3 = 1;
                    C_Timer = 10;
                } else {
                    C_No3 = 0;
                    C_Timer = 20;
                }
                break;
            }
            C_Timer = 3;
        }
        break;
    case CM12_4_BONUS4:
        switch (C_No3) {
        case CM12_4_T_BONUS:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No2++;
                C_Timer = 30;
                Bonus_Game_result = Stock_Bonus_Game_Result;
            }
            break;
        case CM12_4_T_BONUS2:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No3++;
                C_Timer = 10;
                Disp_Bonus_Perfect();
            }
            break;
        case CM12_4_T_BONUS3:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No3++;
                C_Timer = 40;
                if (PB_Status & 1) {
                    Score[Player_id][SCORE_CPU] += Ball_Perfect_PTS[0][Bonus_Stage_Level];
                }
                if (PB_Status & 2) {
                    Score[Player_id][SCORE_CPU] += Ball_Perfect_PTS[1][Bonus_Stage_Level];
                }
                if (Score[Player_id][SCORE_CPU] >= 99999900) {
                    Score[Player_id][SCORE_CPU] = 99999900;
                }
                Flash_Bonus_Perfect();
            }
            break;
        default:
            if (--C_Timer == 0) {
                C_No2++;
                C_Timer = 30;
            }
            break;
        }
        break;
    default:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = CM12_4_BONUS;
            C_No3 = 0;
            C_Timer = 10;
            Forbid_Break = 0;
            tilemap_clear_rect(1, 8, DE_X[1] + 47, 21);
            Check_Fade_Out_BGM(0x222);
        }
        break;
    }
}



void Game_Manage_12_5(void) {
    switch (C_No2) {
    case CM12_5_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
        }
        break;
    case CM12_5_WAIT2:
        if (((s8)Scene_Cut)) {
            C_Timer = 1;
        }
        if (--C_Timer == 0) {
            C_No2++;
        }
        break;
    default:
        MANAGE_X = 1;
        break;
    }
}



void Game_Manage_12_2(void) {
    bcount_cont_main();
    if (Check_Time_Over()) {
        return;
    }
    if (Bonus_Game_Complete) {
        C_No1++;
        C_No2 = 0;
        C_No3 = 0;
        C_Timer = 30;
        Forbid_Break = -1;
        Completion_Bonus[Player_id][0] = -128;
        Final_Bonus_Score = Setup_Final_Score(21);
        grade_makeup_bonus_parameter(Player_id);
        ToneDown(8);
        ToneDown(9);
        effect_58_init(6, 10, 169);
    }
}



void Game_Manage_12_8(void) {
    switch (C_No2) {
    case CM12_8_WAIT:
        switch (C_No3) {
        case CM12_8_T_EFFECT:
            Next_Step = 0;
            if (effect_35_init(60, 10) == 0) {
                C_No3++;
            }
            break;
        case CM12_8_T_NEXT_STEP:
            if (Next_Step) {
                C_No3++;
                C_Timer = 20;
            }
            break;
        case CM12_8_T_WAIT:
            if (C_Timer <= 10 && Scene_Cut != 0) {
                C_Timer = 1;
            }
            if (--C_Timer == 0) {
                C_No2++;
                C_No3 = CM12_8_T_EFFECT;
                C_Timer = 30;
            }
            break;
        default:
            break;
        }
        break;
    case CM12_8_BONUS:
        if (Bonus_Cut_Sub() == 0) {
            if (--C_Timer == 0) {
                C_No2++;
                C_Timer = 20;
                Score[Player_id][SCORE_CPU] += Bonus_Score;
                sc_ram_to_vram_opc(27, Game_setting.Screen_Mode * 7, 1, 30);
                Disp_Digit16x24(Bonus_Score, 35, 11, 30);
                if (Bonus_Game_result == 0) {
                    C_No2 = 99;
                    C_Timer = 120;
                }
            }
        }
        break;
    case CM12_8_BONUS2:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 1;
        }
        break;
    case CM12_8_BONUS3:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            if (bcounter_down(0) == 0) {
                C_No2++;
                C_Timer = 30;
                C_Timer = 3;
                Bonus_Score += 1000;
                Score[Player_id][SCORE_CPU] += 1000;
                Disp_Digit16x24(Bonus_Score, 35, 11, 30);
                Sound_SE(100);
            } else {
                C_Timer = 3;
                Bonus_Score += 1000;
                Score[Player_id][SCORE_CPU] += 1000;
                Disp_Digit16x24(Bonus_Score, 35, 11, 30);
                Sound_SE(100);
            }
        }
        break;
    case CM12_8_WAIT2:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 30;
        }
        break;
    default:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = CM12_8_WAIT;
            C_No3 = 0;
            C_Timer = 10;
            Forbid_Break = 0;
            tilemap_clear_rect(1, 8, DE_X[1] + 47, 21);
            Check_Fade_Out_BGM(546);
        }
        break;
    }
}



s32 Check_Bonus_Perfect(void) {
    PB_Status = 0;
    if (Stock_Bonus_Game_Result >= 20) {
        PB_Status |= 1;
    }
    if (Bonus_Game_ex_result >= 20) {
        PB_Status |= 2;
    }
    return PB_Status;
}



void Disp_Bonus_Perfect(void) {
    switch (PB_Status) {
    case 1:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 30);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], DE_X[3] + 35, 15, 30);
        break;
    case 2:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 52);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], DE_X[3] + 35, 15, 52);
        break;
    case 3:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 30);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], DE_X[3] + 35, 15, 30);
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 9, 52);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], DE_X[3] + 35, 19, 52);
        break;
    }
    sound_request(Winner_id + 102);
}



void Flash_Bonus_Perfect(void) {
    s32 (*fp)() = effect_89_init;
    register s16* py = &DE_X[1];
    switch (PB_Status) {
    case 1:
        fp(10, 1, 15, *py + 36, 3);
        break;
    case 2:
        fp(9, 1, 15, *py + 36, 3);
        break;
    case 3:
        fp(10, 1, 15, *py + 36, 3);
        fp(9, 1, 19, *py + 36, 3);
        break;
    }
}



u32 Setup_Final_Score(s16 Type) {
    u32 xx;

    if (Type == 22) {
        xx = Bonus_Game_result * 1000;
        if (Stock_Bonus_Game_Result >= 20) {
            xx += Ball_Perfect_PTS[0][Bonus_Stage_Level];
        }
        if (Bonus_Game_ex_result >= 20) {
            xx += Ball_Perfect_PTS[1][Bonus_Stage_Level];
        }
        xx += Score[Player_id][SCORE_CPU];
        if (xx >= 99999900) {
            xx = 99999900;
        }
        return xx;
    } else {
        switch (Bonus_Game_result) {
        case 2:
            xx = 30000;
            break;
        case 3:
            xx = 50000;
            break;
        default:
            xx = 0;
            break;
        }
        Bonus_Score = xx;
        xx += Counter_hi * 1000;
        Bonus_Score_Plus = xx;
        xx += Score[Player_id][SCORE_CPU];
        if (xx >= 99999900) {
            xx = 99999900;
        }
        return xx;
    }
}



s32 Bonus_Cut_Sub(void) {
    if (Scene_Cut) {
        Sound_SE(100);
        Bonus_Game_result = 0;
        Score[Player_id][SCORE_CPU] = Final_Bonus_Score;
        if (Score[Player_id][SCORE_CPU] >= 99999900) {
            Score[Player_id][SCORE_CPU] = 99999900;
        }
        sc_ram_to_vram_opc(27, Game_setting.Screen_Mode * 7, 1, 30);
        if (Bonus_Type == BONUS_PARRY) {
            Disp_Digit16x24(Stock_Bonus_Game_Result * 1000, 35, 11, 30);
            Disp_Bonus_Perfect();
            Flash_Bonus_Perfect();
            C_No2 = 3;
            C_No3 = 99;
            return C_Timer = 90;
        } else {
            bcounter_down(1);
            Disp_Digit16x24(Bonus_Score_Plus, 35, 11, 30);
            C_No2 = 4;
            C_No3 = 99;
            return C_Timer = 90;
        }
    }
    return 0;
}



s32 Check_Time_Over(void) {
    s16 ret = 0;
    switch (C_No2) {
    case TIME_OVER_CHECK:
        if (Time_Over) {
            C_No2++;
            C_Timer = 60;
            Game_pause = 1;
            sc_picture_put(2, 0, 0);
            sound_request(0x8F);
            ret = 1;
        }
        break;
    case TIME_OVER_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            Game_pause = 0;
            tilemap_clear_rect(DE_X[3] + 8, 9, DE_X[1] + 47, 16);
        }
        break;
    }
    return ret;
}

void Ck_Win_Record(void) {
    if (PL_Wins[Winner_id] < Battle_Round[Play_Type] + 1) {
        return;
    }
    if (Play_Type == PLAY_VS_PLAYER) {
        if (++Win_Record[Winner_id] <= 999) {
            Disp_Win_Record_Sub(Winner_id);
            Erase_Win_Record(Loser_id);
        } else {
            Win_Record[Winner_id] = 999;
        }
        Stock_Win_Record[Winner_id] = Win_Record[Winner_id];
    } else {
        Erase_Win_Record(Loser_id);
    }
}



void Disp_Win_Record_Sub(s16 PL_id) {
    s16 zz;
    s16 xx;
    s16 Wins_Buff;
    s16 First_Digit;
    if (PL_id) {
        zz = 43;
    } else {
        zz = 5;
    }
    switch (Win_Record[PL_id]) {
    case 1:
        tilemap_print_string_attr(zz, Text_Page_Y, 18, Game_Manage_7_2_sub0_table);
        break;
    default:
        tilemap_print_string_attr(zz, Text_Page_Y, 18, Wins_msg);
        break;
    }
    First_Digit = 0;
    Wins_Buff = Win_Record[PL_id];
    xx = Wins_Buff / 100;
    if (xx > 0) {
        First_Digit = 1;
        tilemap_print_hex_block(zz - 4, Text_Page_Y, 18, (s8)xx, 1, 1);
    }
    Wins_Buff -= xx * 100;
    xx = Wins_Buff / 10;
    if (First_Digit != 0 || xx > 0) {
        tilemap_print_hex_block(zz - 3, Text_Page_Y, 18, (s8)xx, 1, 1);
    }
    Wins_Buff -= xx * 10;
    tilemap_print_hex_block(zz - 2, Text_Page_Y, 18, (s8)Wins_Buff, 1, 1);
}



void Disp_Win_Record(void) {
    s16 x;
    s16 pl;
    s16 num;
    s16 digit;
    s16 shown;
    if (Play_Type == PLAY_VS_PLAYER) {
        if (Win_Record[0] == 0 && Win_Record[1] == 0) {
            return;
        }
        if (Win_Record[0]) {
            pl = 0;
            x = 5;
        } else {
            pl = 1;
            x = 43;
        }
    } else {
        if (Win_Record[Player_id] == 0) {
            return;
        }
        pl = Player_id;
        if (Player_id == 0) {
            x = 5;
        } else {
            x = 43;
        }
    }
    switch (Win_Record[pl]) {
    case 1:
        tilemap_print_string_attr(x, 0, 18, Game_Manage_7_2_sub0_table);
        break;
    default:
        tilemap_print_string_attr(x, 0, 18, Wins_msg);
        break;
    }
    shown = 0;
    num = Win_Record[pl];
    digit = num / 100;
    if (digit > 0) {
        shown = 1;
        tilemap_print_hex_block(x - 4, 0, 18, (s8)digit, shown, 1);
    }
    num -= digit * 100;
    digit = num / 10;
    if (shown != 0 || digit > 0) {
        tilemap_print_hex_block(x - 3, 0, 18, (s8)digit, 1, 1);
    }
    num -= digit * 10;
    tilemap_print_hex_block(x - 2, 0, 18, (s8)num, 1, 1);
}



/* provisional name */
void Erase_Win_Record(s16 PL_id) {
    s16 x;
    if (Win_Record[PL_id] != 0) {
        if (PL_id) {
            x = 39;
        } else {
            x = 1;
        }
        tilemap_print_string_attr(x, Text_Page_Y, 18, Win_Record_Erase_msg);
        Win_Record[PL_id] = 0;
    }
}

s32 Check_Disp_Winner(void) {
    if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
        return Disp_Win_Name = 1;
    }
    if (Conclusion_Type == CONCLUSION_KO) {
        return Disp_Win_Name = 0;
    }
    return Disp_Win_Name = 1;
}



void Disp_Winner(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        winner_name_put((s32)My_char[Winner_id]);
        effect_89_init(1, DE_X[3] + 10, 9, 29, 4);
        sound_request(0x8D);
    } else {
        if (Round_Operator[Winner_id] != 0) {
            sc_picture_put(5, 0, 0);
            effect_89_init(1, DE_X[3] + 11, 9, 25, 4);
            sound_request(0x8D);
        } else {
            sc_picture_put(6, 0, 0);
            effect_89_init(2, DE_X[3] + 11, 9, 24, 4);
            sound_request(0x8E);
        }
    }
}



void Update_Level_Control(void) {
    if (Round_Operator[Winner_id]) {
        if (!Round_Operator[Loser_id]) {
            Control_Time += 40;
            if (Control_Time > Limit_Time) {
                Control_Time = Limit_Time;
                return;
            }
        }
    } else {
        if ((Control_Time -= 40) < 0) {
            Control_Time = 0;
        }
    }
}



void request_center_message(s16 Kind_of_Message) {
    request_message = 1;
    message_index = Kind_of_Message;
}



s32 Judge_Next_Disposal(void) {
    s16* p;
    if (*(p = &PL_Wins[0]) != PL_Wins[1]) {
        return 0;
    }
    if (*p >= Battle_Round[Play_Type]) {
        return 1;
    }
    return 0;
}



void Check_Perfect(s16 PL_id) {
    PLW* f = &plw[PL_id];

    if (f->wu.vitality == f->wu.vital_new) {
        Perfect_Flag = 1;
        Perfect_Counter[Winner_id]++;
        Round_Result |= RESULT_PERFECT;
        win_type[PL_id][PL_Wins[PL_id]] = WIN_MARK_PERFECT;
    }
}



void Judge_Winner(void) {
    grade_makeup_judgement_gals();
    if (judge_gals[0].grade == judge_gals[1].grade) {
        if (Play_Type == PLAY_VS_CPU) {
            Winner_id = Player_id;
            Loser_id = COM_id;
        } else {
            Winner_id = Champion;
            Loser_id = Champion ^ 1;
        }
    } else if (judge_gals[0].grade > judge_gals[1].grade) {
        Winner_id = 0;
        Loser_id = 1;
    } else {
        Winner_id = 1;
        Loser_id = 0;
    }
}



s32 Check_Ending(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return 0;
    }
    if (Check_Ending_Sub()) {
        G_No1 = G1_ENDING;
        G_No2 = 0;
        E_No0 = E0_ENDING;
        End_PL = My_char[WINNER];
        plw[WINNER].wu.operator = 0;
        Operator_Status[WINNER] = 0;
        sound_reg_level_set(0, 0);
        Control_Time = 481;
        Ending_init();
        Stock_My_char[WINNER] = My_char[WINNER];
        Stock_Player_Color[WINNER] = Player_Color[WINNER];
        return 1;
    }
    return 0;
}

u32 Check_Ending_Sub(void)
{
    if (VS_Index[WINNER] > 9) {
        return 1;
    }
    return 0;
}



void Quick_Entry(void) {
    s16 grade;
    s8* best;
    if (Check_Entry_Again()) {
        Forbid_Break = 0;
        Extra_Break = 0;
    }
    if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
        if (plw[LOSER].wu.operator) {
            Loser_Sub();
            Be_Continue();
        }
        if (Play_Type == PLAY_VS_PLAYER) {
            grade = judge_item[Winner_id][1].grade;
            best = &Best_Grade[Winner_id];
            if ((s8)grade > *best) {
                *best = grade;
            }
        }
        sc_vram_to_ram();
    }
}



s32 Check_Entry_Again(void) {
    if (Battle_Q[Winner_id]) {
        return 0;
    }
    if (Play_Type == PLAY_VS_PLAYER) {
        return 1;
    }
    if (Version_Type == 3 && VS_Index[WINNER] >= 6) {
        return 0;
    }
    if (VS_Index[WINNER] <= 9) {
        return 1;
    }
    return 0;
}



void Loser_Sub(void) {
    plw[LOSER].wu.operator = 0;
    Operator_Status[LOSER] = 0;
    Sel_PL_Complete[LOSER] = 0;
    Sel_Arts_Complete[LOSER] = 0;
    if (Play_Type == PLAY_VS_CPU) {
        if (--Round_Level < 0) {
            Round_Level = 0;
        }
        Stage_Continue[LOSER]++;
    }
    if (Game_setting.Event == 0) {
        tilemap_clear_rect(Score_X_Pos_Data[LOSER][Game_setting.Screen_Mode] - 7, Text_Page_Y, Score_X_Pos_Data[LOSER][Game_setting.Screen_Mode], Text_Page_Y + 1);
    }
    tilemap_print_string_attr(Loser_X_Pos_Data[LOSER][Game_setting.Screen_Mode] - 2, 0, 18, Loser_Erase_msg);
}



void Be_Continue(void) {
    s8 s = LOSER;
    if (Continue_Flag != 0 && Game_setting.Event == 0) {
        Continue_Count_Down[s] = 0;
        Continue_Count[LOSER] = 9;
        E_Number[LOSER][0] = ENTRY_LOSER;
        E_Number[LOSER][1] = 0;
        E_Number[LOSER][2] = 0;
        E_Number[LOSER][3] = 0;
    } else {
        Setup_Next_Step(s);
    }
}



void Update_VS_Data(void) {
    if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
        WINNER = Winner_id;
        LOSER = Loser_id;
        Stock_My_char[LOSER] = My_char[LOSER];
        Stock_Player_Color[LOSER] = Player_Color[LOSER];
        if (Play_Type == PLAY_VS_CPU) {
            if (Round_Operator[WINNER]) {
                SC_Personal_Time[WINNER] = Control_Time;
                Stage_Continue[WINNER] = 0;
                Request_Disp_Rank[LOSER][RANK_SCORE] = -1;
                Request_Disp_Rank[LOSER][RANK_WINS] = -1;
                Request_Disp_Rank[LOSER][RANK_CPU_GRADE] = -1;
                Request_Disp_Rank[LOSER][RANK_GRADE] = -1;
                Stock_Com_Color[WINNER] = -1;
                Stock_Com_Arts[WINNER] = -1;
                EM_History[WINNER][VS_Index[WINNER]] = EM_id;
                Result_Timer[WINNER] += 30;
                if (EM_id == PL_Q) {
                    Break_Com[WINNER][EM_id] = (s8)VS_Index[WINNER];
                } else {
                    VS_Index[WINNER]++;
                    Break_Com[WINNER][EM_id] = 1;
                }
                if (PL_Wins[LOSER] != 0) {
                    Straight_Counter[WINNER] = 0;
                    Straight_Flag[WINNER] = 1;
                }
                if (++Round_Level > 7) {
                    Round_Level = 7;
                }
            } else {
                Score[LOSER][SCORE_CPU] = Stage_Stock_Score[LOSER];
                Win_Record[LOSER] = 0;
                Straight_Counter[LOSER] = 0;
                Straight_Flag[LOSER] = 1;
            }
        } else {
        }
    } else if (Round_Operator[Winner_id] != 0) {
        Pool_Score(Winner_id);
    } else {
        Score[Loser_id][SCORE_CPU] = Stock_Score[Loser_id];
    }
}


/* provisional name */
void Update_Personal_Time(s16 id) {
    if (Continue_Coin2[id] == 0) {
        SC_Personal_Time[id] = Control_Time;
    }
}



void Check_Fade_Out_BGM(s16 Time) {
    if (!BGM_Fade_Out_Flag) {
        if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            BGM_Fade_Out_Flag = 1;
            bgm_fade_out(Time);
        }
    }
}

void Control_Music_Fade(s16 time)
{
    Setup_BGM_Fade_In(time);
    sound_reg_level_set(0, -128);
}



void BGM_Fade_Sub(void) {
    u8* p;
    s8* v;
    switch (v = &BGM_Fade_Level, p = &BGM_Timer[1], BGM_No[1]) {
    case 1:
        if (--*p == 0) {
            BGM_No[1]++;
            BGM_Timer[1] = 1;
            *v = -128;
        }
        break;
    default:
        if (--*p == 0) {
            BGM_Timer[1] = 2;
            if (++*v == 0) {
                BGM_No[1] = 0;
            }
        }
        sound_reg_level_set(0, *v);
        break;
    case 0:
        break;
    }
}



void BGM_Control(void) {
    switch (BGM_No[0]) {
    case BGM_IDLE:
        return;
    case BGM_ROUND_WAIT:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }
    case BGM_ROUND:
        if (gSeqStatus[0] == 2) {
            BGM_No[0] = 0;
            if (Play_Type == PLAY_VS_CPU && EM_id == PL_Q) {
                Stage_BGM(18, Round_num);
            } else {
                Stage_BGM((u16)bg_w.stage, Round_num);
            }
        }
        break;
    case BGM_JUDGE_WAIT:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }
    case BGM_JUDGE:
        if (gSeqStatus[0] == 2) {
            BGM_No[0] = 0;
            bgm_request(6, 0);
        }
        break;
    }
}

void Setup_BGM_Fade_In(u8 time) {
    if (PB_Music_Off) {
        return;
    }
    BGM_No[1] = 1;
    BGM_Timer[1] = time;
}

void complete_victory_pause(void)
{
    Complete_Victory = 1;
}



s32 Check_Break_Into_CPU(s16 PL_id) {
    Break_Into_CPU = 0;
    Battle_Q[PL_id] = 0;
    if (Version_Type == 3) {
        return 0;
    }
    if (Break_Com[PL_id][18]) {
        return 0;
    }
    if (Continue_Coin[PL_id]) {
        return 0;
    }
    if (VS_Index[PL_id] < 7 || VS_Index[PL_id] >= 9) {
        return 0;
    }
    if (Straight_Flag[PL_id]) {
        return 0;
    }
    if (judge_final[Player_id][0].sp_point < 2) {
        return 0;
    }
    if (Super_Arts_Finish[PL_id] < Break_Into_Level_Data[Battle_Round[Play_Type]]) {
        return 0;
    }
    if (Check_BI_Grade(PL_id)) {
        Break_Into_CPU = 2;
        return Battle_Q[PL_id] = 1;
    }
    return 0;
}



s32 Check_BI_Grade(PL_id)
s16 PL_id;
{
    s16 ix;
    for (ix = 0; ix < VS_Index[PL_id]; ix++) {
        if (judge_final[PL_id][0].vs_cpu_grade[ix] < 9) {
            return 0;
        } else {
            continue;
        }
    }
    return 1;
}



void Check_Stage_BGM(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        Stage_BGM((u16)bg_w.stage, Round_num);
    } else {
        switch (EM_id) {
        case PL_GILL:
            if (Introduce_Boss[Player_id][1] & 0x80) {
                Stage_BGM((u16)bg_w.stage, Round_num);
            }
            break;
        case PL_Q:
            Stage_BGM(18, Round_num);
            break;
        default:
            Stage_BGM((u16)bg_w.stage, Round_num);
            break;
        }
    }
}

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
#include "cmb_win.h"
#include "VITAL.h"
#include "vital_2.h"
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
#include "eff93.h"
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
#include "eff58.h"
#include "Eff76.h"
#include "EFF84.h"
#include "bg000.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "end_main.h"
#include "Entry.h"
#include "entry_2.h"
#include "sc_face.h"



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
    if (bg_w.stage == 22 || bg_w.stage == 21) {
        C_No0 = 11;
    } else {
        C_No0 = 1;
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
    if (Play_Type == 0) {
        Control_Time = SC_Personal_Time[Player_id];
        paring_ctr_ori[Player_id] = paring_ctr_vs[0][Player_id] = 0;
        Stage_Stock_Score[Player_id] = Score[Player_id][0];
        Request_Disp_Rank[COM_id][0] = -1;
        Request_Disp_Rank[COM_id][1] = -1;
        Request_Disp_Rank[COM_id][2] = -1;
        Request_Disp_Rank[COM_id][3] = -1;
        if (EM_id == 18) {
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
    for (xx = 0; xx < 2; xx++) {
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
    }
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
    if (Demo_Flag != 0) {
        Stop_SG = 0;
    }
    Complete_Judgement = 0;
    judge_flag = 0;
    BGM_Fade_Out_Flag = 0;
    Pause_Hit_Marks = 0;
    CP_No[0][0] = 0;
    CP_No[1][0] = 0;
    Stock_Score[0] = Score[0][0];
    Stock_Score[1] = Score[1][0];
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
    if (pcon_rno[0] != 0) {
        return;
    }
    if (pcon_rno[1] != 1) {
        return;
    }
    C_No1++;
    effect_B2_init();
}



void Game_Manage_2_4(void) {
    switch (C_No2) {
    case 0:
        if (Round_num) {
            C_No2 = 3;
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
    case 1:
        if (--C_Timer == 0) {
            C_No2++;
            Text_Page_Y = 0;
            Clear_Flash_No();
            commit_name_entry_row_both_players(0);
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    case 2:
        C_No2++;
        Forbid_Break = 0;
        Stage_Intro_Flag = 0x80;
        break;
    case 3:
        if (!Next_Step) {
            break;
        }
        C_No0++;
        C_No1 = 0;
        C_No2 = 0;
        Allow_a_battle_f = 1;
        if (!Play_Type && !EM_id) {
            u8* boss = Introduce_Boss[Player_id];
            if (!(boss[1] & 0x80)) {
                boss[1] = boss[1] | 0x80;
                Check_Stage_BGM();
            }
        }
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
        if (!Demo_Flag) {
            effect_58_init(10, 60, -1);
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
    if (Play_Type == 1) {
        return;
    }
    if (Round_Operator[Winner_id] == 0) {
        Lost_Round[Loser_id]++;
        Stage_Lost_Round[Loser_id]++;
        return;
    }
    switch (Conclusion_Type) {
    case 0:
        break;
    case 1:
        Lost_Round[Player_id]++;
        Stage_Lost_Round[Player_id]++;
        break;
    case 2:
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
    case 0:
        C_No0 = 6;
        Setup_Win_Mark();
        Check_Perfect(Winner_id);
        PL_Wins[Winner_id]++;
        Update_VS_Data();
        Ck_Win_Record();
        Update_Level_Control();
        break;
    case 1:
        sound_request(121);
        sound_request(139);
        if (Judge_Next_Disposal()) {
            C_No0 = 4;
            break;
        }
        C_No0 = 5;
        Round_Result |= 1024;
        win_type[0][PL_Wins[0]] = 5;
        win_type[1][PL_Wins[1]] = 5;
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
            C_No0 = 6;
            Round_Result |= 1;
            win_type[Winner_id][PL_Wins[Winner_id]] = 1;
            Check_Perfect(Winner_id);
            PL_Wins[Winner_id]++;
            Update_VS_Data();
            Ck_Win_Record();
            Update_Level_Control();
            break;
        }
        C_No0 = 4;
        break;
    }
}



void Setup_Win_Mark(void) {
    if (Round_Result & 0x200) {
        win_type[Winner_id][PL_Wins[Winner_id]] = 7;
        sound_request(121);
        sound_request(140);
        Finish_SE();
        return;
    }
    if (Round_Result & 0x180) {
        Setup_BGM_Fade_In(150);
        sound_reg_level_set(0, -128);
        win_type[Winner_id][PL_Wins[Winner_id]] = 4;
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
        win_type[Winner_id][PL_Wins[Winner_id]] = 4;
        sound_request(0x8CU);
        Finish_SE();
        return;
    }
    win_type[Winner_id][PL_Wins[Winner_id]] = 1;
    sound_request(121);
    sound_request(140);
    Finish_SE();
}

void Update_BI_Term(void)
{
    PLW *wk;
    s16 pl;

    if (Play_Type == 1) {
        return;
    }
    pl = Winner_id;
    wk = &plw[pl];
    if (wk->sa_healing) {
        Super_Arts_Finish[pl]++;
        Stage_SA_Finish[Winner_id]++;
    } else if (wk->wu.vitality == wk->wu.vital_new) {
        Perfect_Finish[pl]++;
        Stage_Perfect_Finish[Winner_id]++;
        if (Round_Result & 0x980) {
            Super_Arts_Finish[Winner_id]++;
            Stage_SA_Finish[Winner_id]++;
        }
    } else if (Round_Result & 0x200) {
        Cheap_Finish[pl]++;
        Stage_Cheap_Finish[Winner_id]++;
    } else if (Round_Result & 0x980) {
        Super_Arts_Finish[pl]++;
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



/* provisional name */
void request_center_message_p2_Manage(s16 Kind_of_Message) {
    request_message = 1;
    message_index = Kind_of_Message;
}



void Game_Manage_5_1(void) {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No1++;
        request_center_message_p2_Manage(3);
        sound_request(154);
    }
}



void Game_Manage_5_2(void) {
    if (!request_message) {
        C_No1++;
        C_Timer = 30;
    }
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
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 3;
    }
}



void Game_Manage_5_5(void) {
    if (--Cover_Timer == 0) {
        C_No1++;
        pcon_rno[1] = 3;
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
        BGM_No[0] = 3;
        BGM_Timer[0] = 1;
    }
}



void Game_Manage_5_7(void) {
    if (--C_Timer != 0) {
        return;
    }
    C_No0 = 6;
    C_No1 = 7;
    C_Timer = 30;
    Fade_Half_Flag = 1;
    Complete_Judgement = 1;
    Round_Result |= 0x8000;
    win_type[Winner_id][PL_Wins[Winner_id]] = 6;
    Stage_Judge_Finish[Winner_id]++;
    Check_Perfect(Winner_id);
    PL_Wins[Winner_id]++;
    Update_VS_Data();
    Update_Level_Control();
}



s32 Game_Manage_6th(void) {
    s32 rc;
    switch (rc = C_No1) {
    case 0:
        if (Complete_Victory == 0) {
            if ((rc = --G_Timer) != 0) {
                break;
            }
        }
        C_No1++;
        C_Timer = 60;
        pcon_rno[1] = 3;
        pcon_rno[2] = 0;
        grade_makeup_round_para_dko();
        effect_58_init(6, 1, Winner_id + 100);
        effect_92_init(0, win_type[0][PL_Wins[0] - 1]);
        return effect_92_init(1, win_type[1][PL_Wins[1] - 1]);
    case 1:
        if (--C_Timer == 0) {
            C_No0 = 7;
            C_No1 = 0;
            Round_num++;
            return ((s32(*)(void))Quick_Entry)();
        }
        break;
    }
    return rc;
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
    if (cmb_all_stock[0] != 0 || cmb_calc_now[0] != 0 || cmb_calc_now[1] != 0) {
        return 1;
    }
    if (PL_Wins[Winner_id] < Battle_Round[Play_Type] + 1) {
        return 0;
    }
    return 0;
}



void Game_Manage_7_3(void) {
    if (Play_Type == 0 && Perfect_Flag == 0) {
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
        request_center_message_p2_Manage(4);
        effect_58_init(6, 1, 155);
        effect_58_init(6, 60, 156);
    }
}



void Game_Manage_7_5(void) {
    if (!request_message) {
        C_No1++;
        C_Timer = 6;
        Event_Judge_Gals = -1;
    }
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
    s16 ix;
    s16 time;
    s16 pos_id;
    s16 pos_id2;
    Check_Fade_Out_BGM(546);
    C_No2++;
    C_Timer = 20;
    Forbid_Break = -1;
    load_char_gfx(0xBD28, 1);
    ix = 0;
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
    if (Game_setting.set5) {
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
    Score_Buff = plw[PL_id].wu.vital_new;
    Score_Buff = (s32)(Score_Buff * 100) / Max_vitality;
    Score_Buff *= 500;
    Vital_Bonus[Winner_id] += Score_Buff;
    Time_Bonus[Winner_id] += (s32)round_timer.half.h * 300;
}



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
    if (Play_Type == 1) {
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
    case 0:
        if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            C_No0++;
            C_No1 = 0;
            C_Timer = 75;
            sc_vram_to_ram();
            if (Play_Type != 1 && Round_Operator[WINNER] && Battle_Q[WINNER]) {
                C_No0 = 10;
            }
            break;
        }
        C_No1++;
        C_Timer = 60;
        satime_stock_clear();
        sc_vram_to_ram();
        Stop_Combo = 1;
        BGM_Timer[1] = 1;
        break;
    case 1:
        if (Scene_Cut) {
            C_Timer = 1;
        }
        if (--C_Timer > 0) {
            break;
        }
        C_No1++;
        Game_pause = 1;
        Switch_Screen_Init(3, 3);
    default:
        if (Switch_Screen()) {
            BGM_No[0] = 1;
            BGM_Timer[0] = 1;
            G_No2 = 5;
            G_No3 = 0;
            G_Timer = 4;
            Cover_Timer = 5;
            C_No0 = 1;
            C_No1 = C_No2 = C_No3 = 0;
            Suicide[0] = 1;
        }
        break;
    }
}



void Game_Manage_10th(void) {
    switch (C_No1) {
    case 0:
        if (Button_Cut_EX(&C_Timer, 0x7FFF)) {
            C_No1++;
            Cover_Timer = 25;
            sc_vram_to_ram();
            Stop_Combo = 1;
            Game_pause = 1;
            Switch_Screen_Init(3, 3);
        }
        break;
    case 1:
        if (Switch_Screen()) {
            effect_work_quick_init();
            sound_system_init();
            Check_Naming(0);
            Check_Naming(1);
            pcon_rno[1] = pcon_rno[0] = 0;
            pcon_rno[2] = 0;
            pcon_rno[3] = 0;
            appear_type = 1;
            Continue_Coin2[WINNER] = 0;
            if (Round_Operator[WINNER]) {
                G_No1 = 3;
                G_No2 = 0;
                G_No3 = 0;
                M_No[0] = 0;
                M_No[1] = 0;
                M_No[2] = 0;
                M_No[3] = 0;
                E_No0 = 5;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Check_Ending();
                Continue_Coin2[WINNER] = 0;
                Clear_Flash_No();
            } else {
                G_No1 = 4;
                G_No2 = 0;
                G_No3 = 0;
                M_No[0] = 0;
                M_No[1] = 0;
                M_No[2] = 0;
                M_No[3] = 0;
                E_No0 = 6;
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
    case 0:
        Forbid_Break = -1;
        C_No1++;
        EM_Rank = 2;
        Q_Country = Battle_Country;
        C_Timer = 90;
        effect_81_init(30);
        break;
    case 1:
        if (--C_Timer == 0) {
            C_No1++;
            C_Timer = 150;
            C_Timer = 60;
        }
        break;
    case 2:
        if (--C_Timer == 0) {
            C_No1++;
            Switch_Screen_Init(0, 2);
        }
        break;
    case 3:
        if (Switch_Screen()) {
            C_No1++;
            tilemap_clear_rect(DE_X[3], (s16)(Text_Page_Y + 11), (*&DE_X)[3] + 47, Text_Page_Y + 13);
            sc_vram_to_ram();
            Switch_Screen_Init(3, 1);
        }
        break;
    case 4:
        if (Switch_Screen()) {
            G_No1 = 11;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = 9;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            effect_work_quick_init();
            Cover_Timer = 21;
        }
        break;
    }
}



void Check_Naming(s16 id) {
    s32 num;
    if (!Game_setting.set5) {
        num = E_Number[id][0];
        if (num != 2 && num != 3) {
            Rank_In[id][0] = -1;
            Rank_In[id][1] = -1;
            Rank_In[id][2] = -1;
            Rank_In[id][3] = -1;
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
    CP_No[0][0] = 0;
    CP_No[1][0] = 0;
    Stock_Score[Player_id] = Score[Player_id][0];
    load_any_color(179);
    if (Bonus_Type == 21) {
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
    if (Next_Step != 0) {
        C_No1++;
        C_No2 = 0;
        C_No3 = 0;
        Allow_a_battle_f = 1;
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
    }
}



s32 Game_Manage_12_7(void) {
    s16 rc;
    bcount_cont_main();
    if (!(rc = ((u8)Bonus_Game_Complete))) {
        return rc;
    }
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
    if ((rc = Check_Bonus_Perfect())) {
        C_Timer = 20;
        return rc;
    }
    C_No1 = 4;
    return 4;
}



s32 Game_Manage_12_3(void) {
    s16 rc;
    switch (rc = C_No2) {
    case 0:
        if ((rc = Cut_Cut_C_Timer()) == 0) {
            C_No2++;
            C_Timer = 10;
            request_message = 1;
            message_index = 4;
            effect_58_init(6, 1, 155);
            return effect_58_init(6, 60, 156);
        }
        break;
    case 1:
        if (request_message == 0) {
            C_No2++;
            C_Timer = 6;
        }
        break;
    case 2:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            ToneDown(8);
            return ToneDown(9);
        }
        break;
    case 3:
        if ((rc = Cut_Cut_C_Timer()) == 0) {
            C_No1++;
            C_No2 = 0;
            C_No3 = 0;
            C_Timer = 30;
        }
        break;
    }
    return rc;
}



void Game_Manage_12_4(void) {
    switch (C_No2) {
    case 0:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            sc_ram_to_vram_opc(27, Game_setting.mode * 7, 1, 30);
            Disp_Digit16x24(Bonus_Score, DE_X[3] + 35, 11, 30);
        }
        break;
    case 1:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No2++;
            C_Timer = 1;
            Bonus_Score = 0;
        }
        break;
    case 2:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            if (Bonus_Game_result == 0 && !(PB_Status & 2)) {
                C_No2 = 4;
                C_Timer = 30;
                break;
            }
            if (Bonus_Game_result == 0) {
                Bonus_Game_result = 1;
            } else {
                Bonus_Score += 1000;
                Score[Player_id][0] += 1000;
                Disp_Digit16x24(Bonus_Score, (*&DE_X)[3] + 35, 11, 30);
                Sound_SE(100);
            }
            if (--Bonus_Game_result == 0) {
                C_No2++;
                if (PB_Status) {
                    C_No3 = 1;
                    C_Timer = 10;
                    break;
                }
                C_No3 = 0;
                C_Timer = 20;
                break;
            }
            C_Timer = 3;
        }
        break;
    case 3:
        switch (C_No3) {
        case 0:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No2++;
                C_Timer = 30;
                Bonus_Game_result = Stock_Bonus_Game_Result;
            }
            break;
        case 1:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No3++;
                C_Timer = 10;
                Disp_Bonus_Perfect();
            }
            break;
        case 2:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No3++;
                C_Timer = 40;
                if (PB_Status & 1) {
                    Score[Player_id][0] += Ball_Perfect_PTS[0][Bonus_Stage_Level];
                }
                if (PB_Status & 2) {
                    Score[Player_id][0] += Ball_Perfect_PTS[1][Bonus_Stage_Level];
                }
                if (Score[Player_id][0] >= 99999900) {
                    Score[Player_id][0] = 99999900;
                }
                Flash_Bonus_Perfect();
                break;
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
            C_No2 = 0;
            C_No3 = 0;
            C_Timer = 10;
            Forbid_Break = 0;
            tilemap_clear_rect(1, 8, (*&DE_X)[1] + 47, 21);
            Check_Fade_Out_BGM(0x222);
        }
        break;
    }
}



void Game_Manage_12_5(void) {
    switch (C_No2) {
    case 0:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
        }
        break;
    case 1:
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
    if (!Bonus_Game_Complete) {
        return;
    }
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



void Game_Manage_12_8(void) {
    switch (C_No2) {
    case 0:
        switch (C_No3) {
        case 0:
            Next_Step = 0;
            if (effect_35_init(60, 10) == 0) {
                C_No3++;
            }
            break;
        case 1:
            if (Next_Step) {
                C_No3++;
                C_Timer = 20;
            }
            break;
        case 2:
            if (C_Timer <= 10 && Scene_Cut != 0) {
                C_Timer = 1;
            }
            if (--C_Timer == 0) {
                C_No2++;
                C_No3 = 0;
                C_Timer = 30;
            }
            break;
        }
        break;
    case 1:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            Score[Player_id][0] += Bonus_Score;
            sc_ram_to_vram_opc(27, Game_setting.mode * 7, 1, 30);
            Disp_Digit16x24(Bonus_Score, 35, 11, 30);
            if (Bonus_Game_result == 0) {
                C_No2 = 99;
                C_Timer = 120;
            }
        }
        break;
    case 2:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No2++;
            C_Timer = 1;
        }
        break;
    case 3:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            if (bcounter_down(0) == 0) {
                C_No2++;
                C_Timer = 3;
                Bonus_Score += 1000;
                Score[Player_id][0] += 1000;
            } else {
                C_Timer = 3;
                Bonus_Score += 1000;
                Score[Player_id][0] += 1000;
            }
            Disp_Digit16x24(Bonus_Score, 35, 11, 30);
            Sound_SE(100);
        }
        break;
    case 4:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 30;
        }
        break;
    default:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = 0;
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
        sc_ram_to_vram_opc(23, Game_setting.mode * 7, 5, 30);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], DE_X[3] + 35, 15, 30);
        break;
    case 2:
        sc_ram_to_vram_opc(23, Game_setting.mode * 7, 5, 52);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], DE_X[3] + 35, 15, 52);
        break;
    case 3:
        sc_ram_to_vram_opc(23, Game_setting.mode * 7, 5, 30);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], (*&DE_X)[3] + 35, 15, 30);
        sc_ram_to_vram_opc(23, Game_setting.mode * 7, 9, 52);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], (*&DE_X)[3] + 35, 19, 52);
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
    s32 t;
    if (Type == 22) {
        t = Bonus_Game_result;
        t *= 1000;
        xx = t;
        if (Stock_Bonus_Game_Result >= 20) {
            xx += Ball_Perfect_PTS[0][Bonus_Stage_Level];
        }
        if (Bonus_Game_ex_result >= 20) {
            xx += Ball_Perfect_PTS[1][Bonus_Stage_Level];
        }
        xx += Score[Player_id][0];
        if (xx >= 99999900) {
            xx = 99999900;
        }
        return xx;
    }
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
    t = Counter_hi;
    t *= 1000;
    xx += t;
    Bonus_Score_Plus = xx;
    xx += Score[Player_id][0];
    if (xx >= 99999900) {
        xx = 99999900;
    }
    return xx;
}



s32 Bonus_Cut_Sub(void) {
    if (Scene_Cut) {
        Sound_SE(100);
        Bonus_Game_result = 0;
        Score[Player_id][0] = Final_Bonus_Score;
        if (Score[Player_id][0] >= 99999900) {
            Score[Player_id][0] = 99999900;
        }
        sc_ram_to_vram_opc(27, Game_setting.mode * 7, 1, 30);
        if (Bonus_Type == 22) {
            Disp_Digit16x24(Stock_Bonus_Game_Result * 1000, 35, 11, 30);
            Disp_Bonus_Perfect();
            Flash_Bonus_Perfect();
            C_No2 = 3;
            C_No3 = 99;
            return C_Timer = 90;
        }
        bcounter_down(1);
        Disp_Digit16x24(Bonus_Score_Plus, 35, 11, 30);
        C_No2 = 4;
        C_No3 = 99;
        return C_Timer = 90;
    }
    return 0;
}



s32 Check_Time_Over(void) {
    s16 ret = 0;
    switch (C_No2) {
    case 0:
        if (Time_Over) {
            C_No2++;
            C_Timer = 60;
            Game_pause = 1;
            sc_picture_put(2, 0, 0);
            sound_request(0x8F);
            ret = 1;
        }
        break;
    case 1:
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
    if (Play_Type == 1) {
        if (++Win_Record[Winner_id] <= 999) {
            Disp_Win_Record_Sub(Winner_id);
            Erase_Win_Record(Loser_id);
        } else {
            Win_Record[Winner_id] = 999;
        }
        {
            u16 t = Win_Record[Winner_id];
            Stock_Win_Record[Winner_id] = t;
        }
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
        tilemap_print_string_attr(zz, Text_Page_Y, 18, "WIN");
        break;
    default:
        tilemap_print_string_attr(zz, Text_Page_Y, 18, "WINS");
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
    s16 pl;
    s32 x;
    s8* str;
    s16 num;
    s16 digit;
    s16 shown;
    if (Play_Type == 1) {
        if (Win_Record[0] == 0 && Win_Record[1] == 0) {
            return;
        }
        if (Win_Record[0] != 0) {
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
        if (pl == 0) {
            x = 5;
        } else {
            x = 43;
        }
    }
    switch (Win_Record[pl]) {
    case 1:
        str = Game_Manage_7_2_sub0_table;
        break;
    default:
        str = Wins_msg;
        break;
    }
    tilemap_print_string_attr(x, 0, 18, str);
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
    tilemap_print_hex_block(x - 2, 0, 18, (s8)(num - digit * 10), 1, 1);
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
    if (Conclusion_Type == 0) {
        return Disp_Win_Name = 0;
    }
    return Disp_Win_Name = 1;
}



void Disp_Winner(void) {
    if (Play_Type == 1) {
        winner_name_put((s32)(s8)My_char[Winner_id]);
        effect_89_init(1, DE_X[3] + 10, 9, 29, 4);
        sound_request(0x8D);
    } else {
        if ((&Round_Operator[0])[Winner_id] != 0) {
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
        Round_Result |= 2;
        win_type[PL_id][PL_Wins[PL_id]] = 3;
    }
}



void Judge_Winner(void) {
    JudgeGals* jg1;
    grade_makeup_judgement_gals();
    jg1 = ((void*)&(*(JudgeGals*)&(judge_gals[1])));
    if (judge_gals[0].grade == jg1->grade) {
        if (Play_Type == 0) {
            Winner_id = Player_id;
            Loser_id = COM_id;
            return;
        }
        Winner_id = Champion;
        Loser_id = Champion ^ 1;
        return;
    }
    if (judge_gals[0].grade > judge_gals[1].grade) {
        Winner_id = 0;
        Loser_id = 1;
        return;
    }
    Winner_id = 1;
    Loser_id = 0;
}



s32 Check_Ending(void) {
    if (Play_Type == 1) {
        return 0;
    }
    if (Check_Ending_Sub()) {
        G_No1 = 8;
        G_No2 = 0;
        E_No0 = 10;
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
        if (Play_Type == 1) {
            grade = ((GradeData*)((u8*)&judge_item[0][1] + (s16)(Winner_id * sizeof(judge_item[0]))))->grade;
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
    if (Play_Type == 1) {
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
    s16 x;
    plw[LOSER].wu.operator = 0;
    Operator_Status[LOSER] = 0;
    Sel_PL_Complete[LOSER] = 0;
    Sel_Arts_Complete[LOSER] = 0;
    if (Play_Type == 0) {
        if (--Round_Level < 0) {
            Round_Level = 0;
        }
        Stage_Continue[LOSER]++;
    }
    if (Game_setting.set5 == 0) {
        x = Score_X_Pos_Data[LOSER][Game_setting.mode];
        tilemap_clear_rect(x - 7, Text_Page_Y, x, Text_Page_Y + 1);
    }
    tilemap_print_string_attr(Loser_X_Pos_Data[LOSER][Game_setting.mode] - 2, 0, 18, Loser_Erase_msg);
}



void Be_Continue(void) {
    s8 s = LOSER;
    if (Continue_Flag != 0 && Game_setting.set5 == 0) {
        Continue_Count_Down[s] = 0;
        Continue_Count[LOSER] = 9;
        E_Number[LOSER][0] = 5;
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
        if (Play_Type != 0) {
            return;
        }
        if (Round_Operator[WINNER] != 0) {
            SC_Personal_Time[WINNER] = Control_Time;
            Stage_Continue[WINNER] = 0;
            Request_Disp_Rank[LOSER][0] = -1;
            Request_Disp_Rank[LOSER][1] = -1;
            Request_Disp_Rank[LOSER][2] = -1;
            Request_Disp_Rank[LOSER][3] = -1;
            Stock_Com_Color[WINNER] = -1;
            Stock_Com_Arts[WINNER] = -1;
            EM_History[WINNER][VS_Index[WINNER]] = EM_id;
            Result_Disp_Timer[WINNER] = Result_Disp_Timer[WINNER] + 30;
            if (EM_id == 18) {
                Break_Com[WINNER][EM_id] = (s8)VS_Index[WINNER];
            } else {
                VS_Index[WINNER]++;
                Break_Com[WINNER][EM_id] = 1;
            }
            if (PL_Wins[LOSER] != 0) {
                Straight_Counter[WINNER] = 0;
                Straight_Flag[WINNER] = 1;
            }
            if (++Round_Level <= 7) {
                return;
            }
            Round_Level = 7;
            return;
        }
        Score[LOSER][0] = Stage_Stock_Score[LOSER];
        Win_Record[LOSER] = 0;
        Straight_Counter[LOSER] = 0;
        Straight_Flag[LOSER] = 1;
        return;
    }
    if (Round_Operator[Winner_id] != 0) {
        Pool_Score(Winner_id);
        return;
    }
    Score[Loser_id][0] = ((s32)Stock_Score[Loser_id]);
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
    s8* v = &BGM_Fade_Level;
    u8* p = &BGM_Timer[1];
    switch (BGM_No[1]) {
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
    case 0:
        return;
    case 1:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }
    case 2:
        if (gSeqStatus[0] == 2) {
            BGM_No[0] = 0;
            if (Play_Type == 0 && EM_id == 18) {
                Stage_BGM(18, Round_num);
            } else {
                Stage_BGM((u16)bg_w.stage, Round_num);
            }
        }
        break;
    case 3:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }
    case 4:
        if (gSeqStatus[0] == 2) {
            BGM_No[0] = 0;
            bgm_request(6, 0);
        }
        break;
    }
}

void Setup_BGM_Fade_In(u8 time) {
    if (Keep_BGM_Flag) {
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
    if ((*(s16(*)[2][0xAC])&(judge_final[0][0].sp_point))[Player_id][0] < 2) {
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



s32 Check_BI_Grade(s16 PL_id) {
    s16 ix;
    for (ix = 0; ix < VS_Index[PL_id]; ix++) {
        if (judge_final[PL_id][0].vs_cpu_grade[ix] < 9) {
            return 0;
        }
        continue;
    }
    return 1;
}



void Check_Stage_BGM(void) {
    u8 kind = Round_num;
    u16 stage = bg_w.stage;
    if (Play_Type == 1) {
        Stage_BGM(stage, kind);
    } else {
        switch (EM_id) {
        case 0:
            if (Introduce_Boss[Player_id][1] & 0x80) {
                Stage_BGM(stage, kind);
            }
            break;
        case 18:
            Stage_BGM(18, kind);
            break;
        default:
            Stage_BGM(stage, kind);
            break;
        }
    }
}

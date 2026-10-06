/*
 * GAME_MAIN.C  Game phase dispatcher: title, select, fight, bonus, continue, ending
 *
 * game_phase_dispatch runs the current game phase from G_No1: Game00 (title / attract entry),
 * Game01 (player select and fight HUD setup via Game01_Sub), Game02 (the fight), Game04 (loser
 * scene), Game05 (next CPU selection), Game06 (game over), Game07 (continue), Game08 (ending and
 * final grade), Game09 (bonus stage), Game10 (after-bonus screen) and Game11 (handicap setting).
 * Game2_1 is the fight frame: round timer (Time_Control), player control
 * (Player_control), vital and combo displays, Game_Management, the seven effect lists and
 * hit_check_main_process. Bonus_Sub does the same for a bonus stage.
 * match_state_0_fight handles a coin during the demo (Ck_Coin sees a coin, service input or free-play
 * start); Loop_Demo_Sub, Before_Select_Sub and
 * Erase_Insert_Coin serve the attract loop; Disp_Ranking and Request_Break_Sub handle the
 * ranking screen and break-in requests. draw_operator_info and Set_Mode_Pos, at the head of the
 * file, place operator text for the current screen mode.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sel_pl.h"
#include "SYS_sub.h"
#include "Entry.h"
#include "entry_2.h"
#include "SYS_sub2.h"
#include "end_main.h"
#include "aboutspr.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "Grade.h"
#include "demo00.h"
#include "demo01.h"
#include "demo02_code.h"
#include "RANKING.h"
#include "Manage.h"
#include "manage_2.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "next_cpu.h"
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
#include "count.h"
#include "spgauge.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effj4.h"
#include "effj5.h"
#include "effj6.h"
#include "EFFJ0.h"
#include "effj1.h"
#include "effj2_code.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "PLCNT3.h"
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
#include "PLCNT2.h"
#include "EFFM7.h"
#include "BBBSCOM.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "eff35.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "SLOWF.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "bg000.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "Game_Main.h"
#include "eeprom.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "EM_Cand.h"
#include "lose_pl.h"
#include "PLS02.h"



/* provisional name */
void Game0_2(void)
{
    G_No2++;
    sc_vram_to_ram();
    Switch_Screen_Init(0, 1);
}



/* provisional name */
void Game0_3(void) {
    if (Switch_Screen()) {
        G_No1++;
        G_No2 = 0;
        G_No3 = 0;
        Cover_Timer = 23;
    }
}



void Game01(void) {
    Basic_Sub();
    Setup_Play_Type();
    switch (G_No2) {
    case 0:
        G_No2 = G_No2 + 1;
        S_No = 0;
        S_Sub_No = 0;
        S_Sub2_No = 0;
        S_Sub3_No = 0;
        Break_Into = 0;
        Stop_Combo = 0;
        load_any_color(5);
        init_slow_flag();
        break;
    case 1:
        if (Select_Player()) {
            G_No2 = G_No2 + 1;
            Bonus_Game_Flag = 0;
            load_any_color(2);
            Game01_Sub();
            sc_vram_to_ram();
            Switch_Screen_Init(3, 3);
        }
        break;
    default:
        Select_Player();
        if (Switch_Screen()) {
            Cover_Timer = 24;
            appear_type = 1;
            if (Demo_Flag != 0) {
                G_No1 = 2;
                G_No2 = 0;
                E_No0 = 4;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Demo_Lever_Play = 0;
            } else {
                Demo_Step_Flag = 1;
                plw[0].wu.operator = 0;
                Operator_Status[0] = 0;
                plw[1].wu.operator = 0;
                Operator_Status[1] = 0;
            }
            purge_char_gfx(0x9060);
            if (plw[0].wu.operator != 0) {
                Sel_Arts_Complete[0] = -1;
            }
            if (plw[1].wu.operator != 0) {
                Sel_Arts_Complete[1] = -1;
            }
            if (plw[0].wu.operator != 0 && plw[1].wu.operator != 0) {
                Play_Type = 1;
            } else {
                Play_Type = 0;
            }
            voice_all_off();
        }
        break;
    }
}



void Game01_Sub(void) {
    tilemap_print_string_attr((*(const s16(*)[2][2])&(Entry_Msg_X_Data[2]))[0][Game_setting.mode], 0, 18, Game01_Erase_msg);
    tilemap_print_string_attr((*(const s16(*)[2][2])&(Entry_Msg_X_Data[2]))[1][Game_setting.mode], 0, 18, Game01_Erase_msg);
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    player_name();
    player_face();
    PL_Wins[0] = 0;
    PL_Wins[1] = 0;
    Score[0][1] = 0;
    Score[0][2] = 0;
    Score[1][1] = 0;
    Score[1][2] = 0;
    Score_Sub();
    Disp_Win_Record();
    Clear_Win_Type();
    Disp_Win_Type();
    win_mark_rno[0] = 0;
    win_mark_control(0);
    win_mark_rno[1] = 0;
    win_mark_control(1);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    if (Demo_Flag) {
        spgauge_cont_init();
    } else {
        spgauge_cont_demo_init();
    }
    spgauge_cont_main();
    stngauge_cont_init();
}



void Game05(void) {
    Basic_Sub();
    Setup_Play_Type();
    switch (G_No2) {
    case 0:
        G_No2++;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        if (Check_Bonus_Stage()) {
            SC_No[0] = 6;
        }
        Stop_Combo = 0;
        init_slow_flag();
        break;
    case 1:
        if (Next_CPU()) {
            G_No2++;
            if (!Bonus_Type) {
                Game01_Sub();
            }
            sc_vram_to_ram();
            Switch_Screen_Init(3, 3);
        }
        break;
    default:
        Next_CPU();
        if (Switch_Screen()) {
            Cover_Timer = 24;
            voice_all_off();
            if (!Bonus_Type) {
                G_No1 = 2;
                G_No2 = 0;
                E_No0 = 4;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Bonus_Game_Flag = 0;
            } else {
                G_No1 = 9;
                G_No2 = 0;
                G_No3 = 0;
                E_No0 = 4;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
            }
        }
        break;
    }
}



void Game11(void) {
    Basic_Sub();
    Setup_Play_Type();
    switch (G_No2) {
    case 0:
        G_No2 += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        Bonus_Type = 0;
        init_slow_flag();
        break;
    case 1:
        if (Next_Q()) {
            G_No2 += 1;
            Game01_Sub();
            sc_vram_to_ram();
            Switch_Screen_Init(3, 3);
        }
        break;
    case 2:
        Next_Q();
        if (Switch_Screen()) {
            Cover_Timer = 24;
            voice_all_off();
            if (Bonus_Type == 0) {
                G_No1 = 2;
                G_No2 = 0;
                E_No0 = 4;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Bonus_Game_Flag = 0;
            } else {
                G_No1 = 9;
                G_No2 = 0;
                G_No3 = 0;
                E_No0 = 4;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
            }
        }
        break;
    case 3:
        G_No2 += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        Bonus_Type = 0;
        init_slow_flag();
        sc_vram_to_ram();
        Switch_Screen_Init(3, 3);
        break;
    case 4:
        if (Switch_Screen()) {
            G_No2 = 1;
            Cover_Timer = 24;
        }
        break;
    }
}



void Game02(void) {
    void (*Game02_Jmp_Tbl[6])() = { Game2_0, Game2_1, Game2_2, Game2_3, Game2_4, Game2_5 };
    Scene_Cut = Cut_Cut_Cut();
    Game02_Jmp_Tbl[G_No2]();
}



void Game2_0(void) {
    System_all_clear_Wait();
    Game_difficulty = 15;
    Game_timer = 0;
    Game_pause = 0;
    Demo_Step_Flag = 0;
    C_No0 = 0;
    C_No1 = 0;
    C_No2 = 0;
    C_No3 = 0;
    G_No2 = 3;
    G_Timer = 10;
    Stage_Intro_Flag = 0x80;
    Round_num = 0;
    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    TATE00();
}



void Game2_1(void) {
    Game_timer += 1;
    set_EXE_flag();
    Time_Control();
    Player_control();
    vital_cont_main();
    combo_cont_main();
    TATE00();
    Game_Management();
    win_mark_control(0);
    win_mark_control(1);
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(5);
    move_effect_work(6);
    hit_check_main_process();
}



void Game2_2(void)
{
  return;
}



void Game2_3(void) {
    Game2_1();
    if (--G_Timer) {
        return;
    }
    G_No2 = 1;
    Clear_Flash_No();
}



void Game2_4(void) {
    if (!G_No3) {
        G_No3++;
        System_all_clear_Wait();
        vital_cont_init();
        stngauge_work_clear();
        combo_cont_init();
        count_cont_init(1);
        Score[0][2] = 0;
        Score[1][2] = 0;
        Score_Sub();
        win_mark_rno[0] = 0;
        win_mark_control(0);
        win_mark_rno[1] = 0;
        win_mark_control(1);
        Game_pause = 0;
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 2;
        erase_extra_plef_work();
        bg_work_clear();
        win_lose_work_clear();
        if (bg_w.area < 2) {
            bg_w.area++;
        }
        TATE00();
    } else {
        Game2_1();
        if (--G_Timer == 0) {
            G_No2 = 1;
            Clear_Flash_No();
        }
    }
}



void Game2_5(void) {
    switch (G_No3) {
    case 0:
        G_No3++;
        vital_cont_init();
        stngauge_work_clear();
        combo_cont_init();
        count_cont_init(1);
        Score[0][2] = 0;
        Score[1][2] = 0;
        Score_Sub();
        win_mark_rno[0] = 0;
        win_mark_control(0);
        win_mark_rno[1] = 0;
        win_mark_control(1);
        Suicide[0] = 1;
        Game_pause = 0;
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 0;
        erase_extra_plef_work();
        reset_all_char_display_with_backup();
        win_lose_work_clear();
        if (bg_w.area < 2) {
            bg_w.area++;
        }
        TATE00();
        if (Judge_Round_Flag) {
            load_bg_color_fade(bg_palette_no_tbl[bg_w.bg_index], 31, 31, 31);
            load_bg_color_fade(bg_color2_tbl[bg_w.bg_index], 31, 31, 31);
        }
        break;
    default:
        Game2_1();
        if (--G_Timer == 0) {
            G_No2 = 1;
            Clear_Flash_No();
        }
        break;
    }
}

char *Game03(void)
{
    char *result;
    s8 event;

    move_effect_work(4);
    move_effect_work(5);
    result = (char *)G_No2;
    if (!result) {
        if (Winner_Scene() == 0) {
            result = 0;
        } else {
            result = (char *)Check_Short_Ending();
            if (!result) {
                event = Game_setting.set5;
                if (!event) {
                    G_No1 = 5;
                    G_No2 = 0;
                    G_No3 = 0;
                    E_No0 = 9;
                    E_No1 = 0;
                    E_No2 = 0;
                    E_No3 = 0;
                    if (Battle_Q[WINNER]) {
                        G_No1 = 11;
                        G_No2 = 3;
                        G_No3 = 0;
                    }
                    result = (char *)&Continue_Flag;
                    Cover_Timer = 24;
                    if (Continue_Flag && (result = (char *)Round_Operator, Round_Operator[LOSER])) {
                        result = 0;
                        E_Number[LOSER][0] = 1;
                        E_Number[LOSER][1] = 0;
                        E_Number[LOSER][2] = 0;
                        E_Number[LOSER][3] = 0;
                    }
                } else {
                    G_No1 = 6;
                    G_No2 = 0;
                    G_No3 = 0;
                    E_No0 = 8;
                    E_No1 = 0;
                    E_No2 = 0;
                    E_No3 = 0;
                    result = (char *)event;
                }
            } else {
                Forbid_Break = 1;
            }
        }
    }
    return result;
}



void Game04(void) {
    move_effect_work(4);
    move_effect_work(5);
    switch (G_No2) {
    case 0:
        if (Loser_Scene()) {
            if (Continue_Flag) {
                G_No1 = 7;
                G_No2 = 0;
                G_No3 = 0;
                E_No0 = 7;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Cont_No = 0;
                Cont_Sub_No = 0;
                Cont_Sub2_No = 0;
                Cont_Sub3_No = 0;
                E_Number[LOSER][0] = 1;
                E_Number[LOSER][1] = 0;
                E_Number[LOSER][2] = 0;
                E_Number[LOSER][3] = 0;
            } else {
                G_No1 = 6;
                G_No2 = 0;
                G_No3 = 0;
                E_No0 = 8;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
            }
        }
        break;
    }
}



void Game09(void) {
    switch (G_No2) {
    case 0:
        System_all_clear_Wait();
        Bonus_Game_Flag = Bonus_Type;
        Game_difficulty = 15;
        Game_timer = 0;
        Game_pause = 0;
        Demo_Step_Flag = 0;
        C_No0 = 0;
        C_No1 = 0;
        C_No2 = 0;
        C_No3 = 0;
        G_No2 += 1;
        Round_num = 0;
        Allow_a_battle_f = 0;
        Time_in_Time = 60;
        init_slow_flag();
        effect_work_quick_init();
        clear_hit_queue();
        {
            s16 t = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
            pcon_rno[0] = t;
        }
        bbbs_com_initialize();
        ca_check_flag = 1;
        Bonus_Game_Work = 20;
        Bonus_Game_result = 0;
        Bonus_Game_ex_result = 0;
        bg_work_clear();
        win_lose_work_clear();
        bg_w.stage = Bonus_Type;
        bg_w.area = 0;
        My_char[COM_id] = (Bonus_Game_Flag == 22) ? 12 : My_char[Player_id];
        Setup_Com_Color();
        Setup_PL_Color(COM_id, Com_Color_Shot);
        TATE00();
        break;
    case 1:
        G_No2 += 1;
        G_Timer = 19;
        if (Bonus_Type == 22) {
            makeup_bonus_game_level(COM_id);
            effect_35_init(60, 5);
            effect_J2_init(120);
            effect_35_init(180, 7);
            effect_58_init(6, 180, 161);
        } else {
            effect_35_init(60, 6);
            effect_35_init(120, 7);
            effect_58_init(6, 120, 161);
        }
        break;
    case 2:
        Bonus_Sub();
        if (--G_Timer == 0) {
            G_No2 += 1;
            Clear_Flash_No();
            Text_Page_Y = 0;
            Scrn_Move_Set(4, 0, 0);
            Switch_Screen_Init(0, 1);
        }
        break;
    case 3:
        Bonus_Sub();
        if (Switch_Screen_Revival()) {
            G_No2 += 1;
            Forbid_Break = 0;
        }
        break;
    case 4:
        if (Bonus_Sub()) {
            G_No2 += 1;
            Cover_Timer = 24;
            sc_vram_to_ram();
            Stop_Combo = 1;
            Switch_Screen_Init(3, 3);
        }
        break;
    case 5:
        Bonus_Sub();
        if (Switch_Screen()) {
            effect_work_quick_init();
            sound_system_init();
            Clear_Flash_No();
            Cover_Timer = 24;
            Suicide[0] = 1;
            System_all_clear_Wait();
            tilemap_fill_all(0, 32);
            G_No1 = 10;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = 9;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            load_any_color(2);
        }
        break;
    }
}



s32 Bonus_Sub(void) {
    s16 result;
    Scene_Cut = Cut_Cut_Cut();
    Bonus_Game_Complete = 0;
    Game_timer++;
    set_EXE_flag();
    Time_Control();
    if (Bonus_Type == 22) {
        Bonus_Game_Complete = Player_control_bonus();
    } else {
        Bonus_Game_Complete = Player_control_bonus2();
    }
    TATE00();
    result = Game_Management();
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(5);
    move_effect_work(6);
    hit_check_main_process();
    return result;
}



void Game10(void) {
    Basic_Sub();
    Setup_Play_Type();
    switch (G_No2) {
    case 0:
        G_No2++;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        init_slow_flag();
        break;
    case 1:
        if (After_Bonus()) {
            G_No2++;
            load_any_color(2);
            Game01_Sub();
            sc_vram_to_ram();
            Switch_Screen_Init(3, 3);
        }
        break;
    default:
        if (After_Bonus() && Switch_Screen()) {
            Cover_Timer = 24;
            voice_all_off();
            G_No1 = 2;
            G_No2 = 0;
            E_No0 = 4;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Bonus_Game_Flag = 0;
        }
        break;
    }
}



void Game08(void) {
    switch (G_No2) {
    case 0:
        G_No2 = 1;
        Final_Result_id = WINNER;
        WGJ_Target = WINNER;
        WGJ_Win = Win_Record[WINNER];
        grade_final_grade_bonus();
        WGJ_Score = Score[WINNER][0] + Continue_Coin[WINNER];
        break;
    case 1:
        if (Ending_main(End_PL) && Request_Fade(107, 0)) {
            G_No2++;
        }
        break;
    case 2:
        if (Check_Fade_Complete_SP()) {
            G_No2++;
            G_Timer = 10;
            Suicide[4] = 1;
        }
        break;
    case 3:
        if (--G_Timer == 0) {
            G_No1 = 6;
            G_No2 = 0;
            E_No0 = 8;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Clear_Personal_Data(0);
            Clear_Personal_Data(1);
            plw[0].wu.operator = 0;
            plw[1].wu.operator = 0;
            Operator_Status[0] = 0;
            Operator_Status[1] = 0;
            Player_Number = -1;
            Last_Player_id = -1;
            load_any_color(2);
            load_any_color(5);
        }
        break;
    case 4:
        if (Short_Ending_Scene()) {
            G_No1 = 6;
            G_No2 = 0;
            E_No0 = 8;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Clear_Personal_Data(WINNER);
            plw[WINNER].wu.operator = 0;
            Operator_Status[WINNER] = 0;
            Player_Number = -1;
            Last_Player_id = -1;
        }
        break;
    }
    move_effect_work(4);
}



void Game06(void) {
    s16 xx;
    Basic_Sub_Ex();
    if (Break_Into) {
        return;
    }
    switch (G_No2) {
    case 0:
        G_No2 += 1;
        Stock_Com_Color[Player_id] = -1;
        Stock_Com_Arts[Player_id] = -1;
        Last_Player_id = -1;
        Control_Time = 481;
        E_No0 = 8;
        E_No1 = 0;
        E_No2 = 0;
        E_No3 = 0;
        for (xx = 0; xx < 4; xx++) {
            GO_No[xx] = 0;
        }
        break;
    case 1:
        if (Game_Over()) {
            G_Timer = 60;
            if (Check_Disp_Ranking() != 0) {
                G_No2 += 1;
            } else {
                G_No2 = 3;
            }
        }
        break;
    case 2:
        if (Disp_Ranking() != 0) {
            G_No2 += 1;
            G_Timer = 1;
        }
        break;
    case 3:
        if (--G_Timer == 0) {
            G_No2 += 1;
            Clear_Disp_Ranking(0);
            Clear_Disp_Ranking(1);
            sc_vram_to_ram();
            Switch_Screen_Init(0, 1);
        }
        break;
    case 4:
        if (Switch_Screen() != 0) {
            Cover_Timer = 24;
            Forbid_Break = 0;
            Clear_Flash_No();
            Clear_Personal_Data(LOSER);
            grade_check_work_1st_init(LOSER, 0);
            grade_check_work_1st_init(LOSER, 1);
            scfont_page0_fill(0, 32);
            if (Request_Break[0] != 0 || Request_Break[1] != 0) {
                Request_Break_Sub(0);
                Request_Break_Sub(1);
                G_No1 = 1;
                G_No2 = 0;
                G_No3 = 0;
                E_No0 = 2;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                break;
            }
            G_No0 = 0;
            G_No1 = 99;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = 0;
            E_No1 = 99;
            E_No2 = 0;
            E_No3 = 0;
            D_No0 = 0;
            D_No1 = 0;
            D_No2 = 0;
            D_No3 = 0;
            Get_Demo_Index = 0;
            Combo_Demo_Flag = 0;
            System_all_clear_Wait();
        }
        break;
    case 5:
        G_No2 += 1;
        Stock_Com_Color[Player_id] = -1;
        Stock_Com_Arts[Player_id] = -1;
        Last_Player_id = -1;
        Clear_Personal_Data(Player_id);
        plw[Player_id].wu.operator = 0;
        Operator_Status[Player_id] = 0;
        grade_check_work_1st_init(Player_id, 0);
        grade_check_work_1st_init(Player_id, 1);
        Control_Time = 481;
        E_No0 = 8;
        E_No1 = 0;
        E_No2 = 0;
        E_No3 = 0;
        GO_No[0] = 2;
        GO_No[1] = 1;
        break;
    case 6:
        if (Game_Over()) {
            G_No2 = 2;
            G_Timer = 60;
        }
        break;
    }
}



/* provisional name */
s32 Check_Disp_Ranking(void) {
    s16 rank_type;
    if (Version_Type == 3) {
        return 0;
    }
    rank_type = Disp_Rank_Sub(0);
    if (rank_type != -1) {
        Rank_Type = rank_type;
        Present_Rank[0] = Rank_In[0][rank_type];
        Present_Rank[1] = Rank_In[1][rank_type];
        return 1;
    }
    rank_type = Disp_Rank_Sub(1);
    if (rank_type != -1) {
        Rank_Type = rank_type;
        Present_Rank[1] = Rank_In[1][rank_type];
        return 1;
    }
    return 0;
}



/* provisional name */
s16 Disp_Rank_Sub(s16 PL_id) {
    if (Request_Disp_Rank[PL_id][3] >= 0) {
        return 15;
    }
    if (Request_Disp_Rank[PL_id][2] >= 0) {
        return 10;
    }
    if (Request_Disp_Rank[PL_id][1] >= 0) {
        return 5;
    }
    if (Request_Disp_Rank[PL_id][0] >= 0) {
        return 0;
    }
    return -1;
}



/* provisional name */
s32 Check_Disp_Rank_Request(void) {
    if (Request_Disp_Rank[0][0] >= 0 || Request_Disp_Rank[0][1] >= 0) {
        return 1;
    }
    if (Request_Disp_Rank[1][0] >= 0 || Request_Disp_Rank[1][1] >= 0) {
        return 1;
    }
    return 0;
}



void Request_Break_Sub(s16 PL_id) {
    if (Request_Break[PL_id]) {
        if (Ck_Break_Into(0, 0, PL_id)) {
            plw[PL_id].wu.operator = 1;
            Operator_Status[PL_id] = 1;
        }
    }
}



s32 Disp_Ranking(void) {
    switch (G_No3) {
    case 0:
        G_No3++;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 0);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            Cover_Timer = 24;
            G_No3++;
            D_No0 = 1;
            D_No1 = 0;
            D_No2 = 0;
            D_No3 = 0;
            Clear_Personal_Data(0);
            grade_check_work_1st_init(0, 0);
            grade_check_work_1st_init(0, 1);
            Clear_Personal_Data(1);
            grade_check_work_1st_init(1, 0);
            grade_check_work_1st_init(1, 1);
        }
        break;
    case 2:
        Ranking_Main();
        if (--Cover_Timer == 0) {
            G_No3++;
            Switch_Screen_Init(0, 0);
        }
        break;
    case 3:
        Ranking_Main();
        if (Switch_Screen_Revival() != 0) {
            G_No3++;
            Forbid_Break = 0;
            bgm_request(7);
        }
        break;
    default:
        if (Ranking_Main() != 0) {
            voice_all_off();
            return 1;
        }
        break;
    }
    return 0;
}



void Game07(void) {
    Basic_Sub();
    switch (G_No2) {
    case 0:
        if (Continue_Scene() != 0) {
            G_No1 = 6;
            G_No2 = 0;
        }
        break;
    }
}



/* provisional name */
void Game_Dummy(void) {
}



void Time_Control(void) {
    if (Allow_a_battle_f != 0 && Demo_Step_Flag == 0 && Bonus_Game_Flag == 0) {
        count_cont_main();
        if (Control_Time >= Limit_Time) {
            Control_Time = Limit_Time;
        } else if (--Time_in_Time == 0) {
            Time_in_Time = 60;
            Control_Time++;
        }
    }
}


s32 Ck_Coin(void) {
    s16 pl = -1;
    if (Free_Play != 0) {
        if (~p1sw_1 & p1sw_0 & 0x1000) {
            pl = 0;
        } else if (~p2sw_1 & p2sw_0 & 0x1000) {
            pl = 1;
        }
        if (pl == -1) {
            return 0;
        }
        bg_vbl_trans_flag = 0;
        bookkeep_freeplay_count();
        if (Game_setting.set5) {
            plw[0].wu.operator = 1;
            plw[1].wu.operator = 1;
            Operator_Status[0] = 1;
            Operator_Status[1] = 1;
            return 1;
        }
        plw[pl].wu.operator = 1;
        Operator_Status[pl] = 1;
        Champion = pl;
        plw[pl ^ 1].wu.operator = 0;
        Operator_Status[pl ^ 1] = 0;
        return 1;
    }
    if (coin_chute1_w[6] | coin_chute2_w[6]) {
        return 1;
    }
    return coin_chute1_w[1] | coin_chute2_w[1] | credit_1p | credit_2p;
}



/* provisional name */
void draw_operator_info(s32 y) {
    s16 y1;
    s16 y2;
    if (Country == 6 || Country == 5) {
        if (p1sw_0 & 0x10) {
            tilemap_print_string_attr(DE_X[18] + 36, y + 20, 18, Game_Data_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y1 = y + 21, 18, Income_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y2 = y + 22, 18, Service_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y + 23, 18, Card_msg);
            tilemap_print_hex_block(DE_X[18] + 41, y1, 18, hex_to_bcd(book_coin_count), 6, 0);
            tilemap_print_hex_block(DE_X[18] + 41, y2, 18, hex_to_bcd(book_service_count), 6, 0);
            tilemap_print_hex_block(DE_X[18] + 41, y + 23, 18, hex_to_bcd(book_card_count), 6, 0);
        } else {
            tilemap_clear_rect(DE_X[18] + 31, y + 20, DE_X[18] + 49, y + 23);
        }
    }
}



/* provisional name */
void Set_Mode_Pos(s16* value, s16 add, s16 init) {
    *value = init;
    if (Game_setting.mode) {
        *value += add;
    }
}




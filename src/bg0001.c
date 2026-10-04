/*
 * BG0001.C  Game task jump
 *
 * bg0001 copies the main game jump table Main_Jmp_Data and calls the routine selected by the
 * current top-level game number G_No0.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg0001.h"
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
#include "sc_trans.h"
#include "sc_face.h"
#include "cmb_win.h"
#include "VITAL.h"
#include "vital_2.h"
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

#pragma noregsave(game_frame_task)
#pragma inline(bg0001)



/* Frame task started by mode_init_task: every frame run the current game routine
   (bg0001), then the colour transfer and the frame render pipeline, and sleep
   until the next frame. */
/* provisional name */
void game_frame_task(void) {
loop:
    bg0001();
    color_trans_dummy();
    sprite_bank_flip();
    task_sleep(1);
    goto loop;
}



void bg0001(void) {
    GAME_TASK_JMP Main_Jmp_Tbl;
    Main_Jmp_Tbl = Main_Jmp_Data;
    Main_Jmp_Tbl.jmp[(*(s16(*)[4])&G_No0)[0]]();
}



void match_state_0_fight(void) {
    if (Ck_Coin()) {
        tilemap_fill_all(0, 32);
        wipe_pattern_set(0, 7, 0);
        if (G_No1 != 99) {
            sound_driver_init();
        }
        sound_reg_level_set(0, 0);
        card_work_clear();
        bg_vbl_trans_flag = 0;
        if (Demo_Flag == 0) {
            sound_request(115);
        }
        G_No0 = 1;
        G_No1 = 0;
        G_No2 = 0;
        G_No3 = 0;
        D_No0 = 0;
        D_No1 = 0;
        D_No2 = 0;
        D_No3 = 0;
        Demo_Flag = 1;
        voice_all_off();
        Before_Select_Sub();
        if (Free_Play) {
            G_No2 = 4;
            entry_to_in_game();
            return;
        }
        E_No0 = 1;
        E_No2 = E_No1 = 0;
        E_No3 = 0;
        return;
    }
    switch (G_No1) {
    case 0:
        G_No1++;
        G_No2 = 0;
        G_No3 = 0;
        D_No0 = 0;
        D_No1 = 0;
        D_No2 = 0;
        D_No3 = 0;
        E_No1 = 99;
        Demo_PL_Index = 0;
        Demo_Stage_Index = 0;
        Select_Demo_Index = 0;
        Text_Page_Y = 0;
        Insert_Y = 23;
        Demo_Flag = 0;
        wipe_pattern_set(0, 7, 0);
        scfont_page0_fill(0, 32);
        break;
    case 1:
        draw_operator_info(Text_Page_Y);
        Basic_Sub();
        if (CAPCOM_Logo()) {
            Loop_Demo_Sub();
            Erase_Insert_Coin();
            Insert_Y = 23;
            E_No1 = 2;
            bg_vbl_trans_flag = 0;
        }
        break;
    case 2:
        draw_operator_info(Text_Page_Y);
        Basic_Sub();
        hit_check_main_process();
        if (Title()) {
            Loop_Demo_Sub();
            Erase_Insert_Coin();
            D_No0 = 1;
            Demo_Lever_Play = 0;
            Insert_Y = 17;
        }
        break;
    case 3:
        draw_operator_info(Text_Page_Y);
        if (Play_Demo()) {
            Loop_Demo_Sub();
            Rank_Type = 0;
            Rank_Demo_Loop = 0;
            Text_Page_Y = 32;
            Scrn_Move_Set(4, 0, 0x100);
            sound_driver_init();
            if (Version_Type == 3) {
                G_No1 = 1;
                E_No1 = 99;
                if (++Select_Demo_Index > 3) {
                    Select_Demo_Index = 0;
                }
            }
        }
        break;
    case 4:
        draw_operator_info(Text_Page_Y);
        Basic_Sub();
        if (Ranking_Main()) {
            Loop_Demo_Sub();
        }
        break;
    case 5:
        draw_operator_info(Text_Page_Y);
        if (Play_Demo()) {
            Loop_Demo_Sub();
            Rank_Demo_Loop = 1;
            Rank_Type = 5;
            Rank_Demo_Loop = 1;
            Text_Page_Y = 32;
            Scrn_Move_Set(4, 0, 0x100);
            sound_driver_init();
            if (Version_Type == 3) {
                G_No1 = 1;
                E_No1 = 99;
            }
        }
        break;
    case 6:
        draw_operator_info(Text_Page_Y);
        Basic_Sub();
        if (Ranking_Main()) {
            Loop_Demo_Sub();
            G_No1 = 1;
            E_No1 = 99;
        }
        break;
    default:
        switch (G_No2) {
        case 0:
            if (--Cover_Timer == 0) {
                G_No2++;
                Switch_Screen_Init(0, 0);
            }
            break;
        default:
            G_No1 = 1;
            G_No2 = 0;
            E_No3 = 0;
            E_No1 = 99;
            Demo_PL_Index = 0;
            Demo_Stage_Index = 0;
            Select_Demo_Index = 0;
            Text_Page_Y = 0;
            Demo_Flag = 0;
            break;
        }
        break;
    }
}



void Loop_Demo_Sub(void) {
    G_No1++;
    G_No2 = 0;
    D_No0 = 0;
    D_No1 = 0;
    D_No2 = 0;
    D_No3 = 0;
    E_No1 = 1;
    Scrn_Move_Set(4, 0, 0);
}



/* provisional name */
void Erase_Insert_Coin(void) {
    tilemap_print_string_attr(DE_X[0] + 14, (s32)Insert_Y, 18, Insert_Coin_Erase_msg);
    tilemap_print_string_attr(DE_X[0] + 14, Insert_Y + 32, 18, Insert_Coin_Erase_msg);
}



void Before_Select_Sub(void) {
    s16 xx;
    Request_G_No = 0;
    Request_E_No = 0;
    Allow_a_battle_f = 0;
    Bonus_Type = 0;
    if (Demo_Flag == 0) {
        Control_Time = 2048;
        Round_Level = 7;
    } else {
        Control_Time = 481;
    }
    Super_Arts[0] = 0;
    Super_Arts[1] = 0;
    Exec_Wipe = 0;
    Fade_Flag = 0;
    Stock_Com_Color[0] = -1;
    Stock_Com_Arts[0] = -1;
    Stock_Com_Color[1] = -1;
    Stock_Com_Arts[1] = -1;
    Bonus_Game_Flag = 0;
    Combo_Demo_Flag = 0;
    paring_counter[0] = 0;
    paring_bonus_r[0] = 0;
    paring_counter[1] = 0;
    paring_bonus_r[1] = 0;
    Gill_Pos_X = 0x200;
    Clear_Disp_Ranking(0);
    Clear_Disp_Ranking(1);
    Clear_Personal_Data(0);
    grade_check_work_1st_init(0, 0);
    grade_check_work_1st_init(0, 1);
    Clear_Personal_Data(1);
    grade_check_work_1st_init(1, 0);
    grade_check_work_1st_init(1, 1);
    Last_Player_id = Player_Number = -1;
    Round_Level = 3;
    Time_in_Time = 60;
    xx = system_timer;
    Random_ix16_com = xx & 0x3F;
    Random_ix32_com = xx & 0x7F;
}



/* provisional name */
void game_phase_dispatch(void) {
    void (*Game_Jmp_Tbl[12])() = { Game00, Game01, Game02, Game03, Game04, Game05, Game06, Game07, Game08, Game09, Game10, Game11 };
    Game_Jmp_Tbl[G_No1]();
}



void Game00(void) {
    GAME00_JMP_TBL Game00_Jmp_Tbl;
    Game00_Jmp_Tbl = Game00_Jmp_Data;
    Game00_Jmp_Tbl.fn[G_No2]();
    Basic_Sub();
}



void Game0_0(void) {
    if (Title_At_a_Dash() != 0) {
        G_No2++;
    }
}



void Game0_1(void) {
    if (Request_G_No) {
        G_No2++;
    }
}



/* Title hand-off: step the game routine, save the screen and start wipe 0. */

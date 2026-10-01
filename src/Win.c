/*
 * WIN.C  Winner, loser, game-over and continue scenes
 *
 * Scene routines called from Game_Main between matches. Winner_Scene and Loser_Scene run the
 * win and lose screens step by step (background, portraits, win records, BGM, button cut);
 * Game_Over runs the game-over and result screens; Continue_Scene the continue countdown;
 * Short_Ending_Scene the short ending used in one region (Check_Short_Ending).
 * Setup_Virtual_BG, Setup_Wins_OBJ, Setup_Result_OBJ and Setup_Continue_OBJ place the
 * background and spawn the scene objects; Check_Exit_Continue and Check_Count_Cut decide when the
 * continue scene ends; Check_Coin_In reads coin input.
 * Also here: cal_damage_vitality and cal_damage_vitality_eff, which turn an attack's power into
 * damage using the round-level rate tables and the players' attack/defence multipliers, and
 * small helpers for win-type marks and player number display.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Eff93.h"
#include "bg_sub.h"
#include "SYS_sub.h"
#include "end_main.h"
#include "PLCNT.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "cmb_win.h"
#include "Eff95.h"
#include "EFFB8.h"
#include "sys_test.h"
#include "SE.h"
#include "EFF49.h"
#include "EFF58.h"
#include "Eff76.h"
#include "EFFA7.h"
#include "EFFL1.h"
#include "aboutspr.h"
#include "bg000.h"
#include "textsound.h"
#include "Win.h"
#include "fighter.h"



/* provisional name */
s32 Check_Short_Ending(void) {
    if (Play_Type == 1) {
        return 0;
    }
    if (Version_Type == 3 && VS_Index[WINNER] >= 6) {
        G_No1 = 8;
        G_No2 = 4;
        E_No0 = 10;
        GO_No[0] = 0;
        GO_No[1] = 0;
        End_PL = My_char[WINNER];
        plw[WINNER].wu.operator = 0;
        Extra_Break = 0;
        sound_reg_level_set(0, 0);
        Control_Time = 481;
        Ending_init();
        Stock_My_char[WINNER] = My_char[WINNER];
        Stock_Player_Color[WINNER] = Player_Color[WINNER];
        Break_Com[WINNER][0] = 1;
        Final_Result_id = WINNER;
        WGJ_Target = WINNER;
        WGJ_Win = Win_Record[WINNER];
        WGJ_Score = Continue_Coin[WINNER] + Score[WINNER][0];
        return 1;
    }
    return 0;
}



s32 Winner_Scene(void) {
    void (*Scene_Tbl[6])() = { Win_1st, Win_2nd, Win_3rd, Win_4th, Win_5th, Win_6th };
    if (Break_Into) {
        return 0;
    }
    WIN_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Scene_Tbl[M_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    return WIN_X;
}



s32 Win_1st(void) {
    s32 ret;
    M_No[0]++;
    M_No[1] = 0;
    Cover_Timer = 23;
    All_Clear_Suicide();
    System_all_clear_Wait();
    base_y_pos = 40;
    bg_etc_write(Win_Intro_Type_Data[My_char[Winner_id]]);
    Setup_Virtual_BG(0, 0x200, 0);
    Setup_Virtual_BG(2, 0x300, 0);
    Setup_Virtual_BG(1, 0x200, 0);
    Setup_Virtual_BG(3, 0x2C0, 0);
    load_any_color(0x86);
    load_any_color(124);
    load_char_gfx(0x9560, 1);
    ret = load_char_gfx(0x95E0, 1);
    if (Play_Type == 0) {
        Last_Selected_EM[Winner_id] = 1;
        return (s32)Last_Selected_EM;
    }
    return ret;
}



void Win_2nd(void) {
    M_No[0]++;
    Order[55] = 1;
    Order_Timer[55] = 1;
    effect_76_init(55);
    Order[53] = 3;
    Order_Timer[53] = 1;
    effect_76_init(53);
    Order[52] = 3;
    Order_Timer[52] = 1;
    effect_76_init(52);
    Order[43] = 3;
    Order_Timer[43] = 1;
    effect_76_init(43);
    Order[58] = 3;
    Order_Timer[58] = 1;
    effect_76_init(58);
    Order[44] = 3;
    Order_Timer[44] = 1;
    effect_76_init(44);
    Order[45] = 1;
    Order_Dir[45] = 4;
    Order_Timer[45] = 30;
    effect_76_init(45);
    Order[56] = 6;
    Order_Timer[56] = 1;
    effect_76_init(56);
    WGJ_Score = Continue_Coin[Winner_id] + Score[Winner_id][Play_Type];
    WGJ_Win = Win_Record[Winner_id];
    effect_L1_init(1);
    effect_L1_init(2);
    effect_L1_init(3);
    effect_L1_init(4);
    effect_L1_init(5);
    effect_L1_init(6);
    Setup_Wins_OBJ();
    effect_B8_init(WINNER, 60);
    load_char_gfx(0xA0F8, 1);
    load_any_color(89);
}



void Win_3rd(void) {
    switch (M_No[1]) {
    case 0:
        if (--Cover_Timer == 0) {
            M_No[1]++;
            tilemap_fill_all(0, 32);
            Clear_Flash_No();
            commit_name_entry_row_both_players(Text_Page_Y);
            if (G_No1 == 3) {
                Scrn_Move_Set(4, 0, 0x100);
            }
            Switch_Screen_Init(0, 1);
        }
        break;
    case 1:
        if (Switch_Screen_Revival()) {
            M_No[0]++;
            M_Timer = 90;
            bgm_request(4);
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
            Target_BG_X[2] = bg_w.bgw[2].wxy[0].disp.pos - 0x180;
            Offset_BG_X[2] = 0;
            Next_Step = 0;
            bg_mvxy.a[0].sp = 0xFFF00000;
            bg_mvxy.d[0].sp = 0x800;
            effect_58_init(14, 20, 2);
        }
        break;
    }
}

void Win_4th(void) {
    if (--M_Timer == 0) {
        M_No[0]++;
        M_Timer = 170;
        Forbid_Break = 0;
    }
}



void Win_5th(void) {
    if (Scene_Cut) {
        M_Timer = 1;
    }
    if (--M_Timer == 0) {
        M_No[0]++;
        WIN_X = 1;
    }
}



void Win_6th(void) {
    WIN_X = 1;
}



s32 Loser_Scene(void) {
    void (*Scene_Tbl[6])() = { Lose_1st, Lose_2nd, Lose_3rd, Lose_4th, Lose_5th, Lose_6th };
    WIN_X = 0;
    Scene_Cut = Cut_Cut_Loser();
    Scene_Tbl[M_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    if (Break_Into) {
        return 0;
    }
    return WIN_X;
}



/* provisional name */
void Lose_1st(void) {
    M_No[0]++;
    M_No[1] = 0;
    Cover_Timer = 23;
    All_Clear_Suicide();
    System_all_clear_Wait();
    base_y_pos = 40;
    bg_etc_write(Win_Intro_Type_Data[My_char[Winner_id]]);
    Setup_Virtual_BG(0, 0x200, 0);
    Setup_Virtual_BG(2, 0x300, 0);
    Setup_Virtual_BG(1, 0x200, 0);
    Setup_Virtual_BG(3, 0x2C0, 0);
    Setup_Virtual_BG(1, 0x200, 0);
    load_any_color(0x86);
    load_any_color(124);
    load_char_gfx(0x9560, 1);
    load_char_gfx(0x95E0, 1);
}



void Lose_2nd(void) {
    M_No[0]++;
    Order[55] = 1;
    Order_Timer[55] = 1;
    effect_76_init(55);
    Order[64] = 3;
    Order_Timer[64] = 1;
    effect_76_init(64);
    Order[54] = 3;
    Order_Timer[54] = 1;
    effect_76_init(54);
    Order[57] = 3;
    Order_Timer[57] = 1;
    effect_76_init(57);
    Order[45] = 1;
    Order_Dir[45] = 4;
    Order_Timer[45] = 30;
    effect_76_init(45);
    effect_B8_init(WINNER, 60);
    load_any_color(89);
}



void Lose_3rd(void) {
    switch (M_No[1]) {
    case 0:
        if (--Cover_Timer == 0) {
            M_No[1]++;
            tilemap_fill_all(0, 32);
            Clear_Flash_No();
            commit_name_entry_row_both_players(Text_Page_Y);
            if (G_No1 == 3) {
                Scrn_Move_Set(4, 0, 0x100);
            }
            Switch_Screen_Init(0, 1);
        }
        break;
    case 1:
        if (Switch_Screen_Revival() != 0) {
            M_No[0]++;
            M_Timer = 90;
            bgm_request(4);
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
        }
        break;
    }
}

/* provisional name */
void Lose_4th(void) {
    if (--M_Timer == 0) {
        M_No[0]++;
        M_Timer = 170;
        Forbid_Break = 0;
    }
}



/* provisional name */
void Lose_5th(void) {
    if (Scene_Cut) {
        M_Timer = 1;
    }
    if (--M_Timer == 0) {
        M_No[0]++;
        WIN_X = 1;
    }
}



/* provisional name */
void Lose_6th(void) {
    WIN_X = 1;
}



void Setup_Virtual_BG(s16 bg, s16 x, s16 y) {
    bg_w.bgw[bg].xy[0].disp.pos = x;
    bg_w.bgw[bg].xy[1].disp.pos = y;
    bg_w.bgw[bg].wxy[0].disp.pos = x;
    bg_w.bgw[bg].wxy[1].disp.pos = y;
    bg_w.bgw[bg].xy[0].disp.low = 0;
    bg_w.bgw[bg].xy[1].disp.low = 0;
    bg_w.bgw[bg].position_x = x;
    bg_w.bgw[bg].position_y = y;
    bg_w.bgw[bg].hos_xy[0].disp.pos = bg_w.bgw[bg].wxy[0].disp.pos = bg_w.bgw[bg].xy[0].disp.pos;
    Bg_Family_Set_Ex(bg);
}



void Setup_Wins_OBJ(void) {
    if (Win_Record[Winner_id] != 0) {
        effect_L1_init(0);
        if (Win_Record[Winner_id] > 1) {
            effect_76_init(47);
            Order[47] = 3;
            Order_Timer[47] = 1;
            effect_76_init(49);
            Order[49] = 3;
            Order_Timer[49] = 1;
        } else {
            effect_76_init(46);
            Order[46] = 3;
            Order_Timer[46] = 1;
            effect_76_init(48);
            Order[48] = 3;
            Order_Timer[48] = 1;
        }
    }
}



s32 Game_Over(void) {
    void (*Scene_Tbl[3])() = { GameOver_1st, GameOver_2nd, GameOver_3rd };
    WIN_X = 0;
    Scene_Cut = Cut_Cut_Loser();
    Scene_Tbl[GO_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    if (Break_Into) {
        return 0;
    }
    return WIN_X;
}



s32 GameOver_1st(void) {
    s32 rc;
    switch (rc = GO_No[1]) {
    case 0:
        GO_No[1]++;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
        Offset_BG_X[3] = 0;
        Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos + 458;
        Offset_BG_X[1] = 0;
        bg_mvxy.a[0].sp = 0xE0000;
        bg_mvxy.d[0].sp = 0;
        effect_A9_init(32, 5, 18, 0);
        bgm_request(9);
        Next_Step = 0;
        effect_58_init(12, 1, 3);
        effect_58_init(12, 1, 1);
        effect_58_init(15, 5, 2);
        effect_58_init(16, 5, 2);
        if (Version_Type != 3 || Break_Com[Player_id][0] == 0) {
            effect_76_init(56);
            Order[56] = 3;
            Order_Timer[56] = 1;
            return;
        }
        return (s32)Break_Com;
    case 1:
        if (Next_Step != 0) {
            GO_No[1]++;
            G_Timer = 240;
        }
        break;
    case 2:
        if ((rc = ((s8)Scene_Cut))) {
            G_Timer = 1;
        }
        if (--G_Timer == 0) {
            GO_No[0]++;
            GO_No[1] = 0;
            return 0;
        }
        break;
    }
    return rc;
}



void GameOver_2nd(void) {
    switch (GO_No[1]) {
    case 0:
        GO_No[1]++;
    case 1:
        if (Version_Type == 3 && Break_Com[Player_id][0]) {
            if (Request_Fade(108, 0) == 0) {
                break;
            }
            GO_No[1]++;
            load_char_gfx(0xA0F8, 1);
            return;
        }
        if (Request_Fade(97, 0) == 0) {
            break;
        }
        GO_No[1]++;
        Forbid_Break = 0;
        load_char_gfx(0xA0F8, 1);
        return;
    case 2:
        if (Check_Fade_Complete_SP() == 0) {
            break;
        }
        if (Game_setting.set5) {
            GO_No[0] = 2;
            break;
        }
        GO_No[1]++;
        Cover_Timer = 5;
        Suicide[3] = 1;
        Suicide[2] = 0;
        if (Version_Type != 3 || Break_Com[Player_id][0] == 0) {
            Setup_Result_OBJ();
            effect_76_init(65);
            Order[65] = 3;
            Order_Timer[65] = 1;
        } else {
            GO_No[1] = 8;
            G_Timer = 5;
        }
        break;
    case 3:
        if (--Cover_Timer == 0) {
            if (Request_Fade(98, 0)) {
                GO_No[1]++;
                Forbid_Break = -1;
            } else {
                Cover_Timer = 1;
            }
        }
        break;
    case 4:
        if (Check_Fade_Complete_SP() == 0) {
            break;
        }
        Forbid_Break = 0;
        bgm_request(47);
        Ignore_Entry[LOSER] = 0;
        if (E_Number[0][0] != 2 && E_Number[1][0] != 2) {
            GO_No[1] += 2;
            G_Timer = 60;
            break;
        }
        GO_No[1]++;
        break;
    case 5:
        if (E_Number[0][0] != 2 && E_Number[1][0] != 2) {
            GO_No[1]++;
            G_Timer = 60;
        }
        break;
    case 6:
        if (--G_Timer == 0) {
            GO_No[1]++;
            G_Timer = Result_Disp_Timer[Player_id];
        }
        break;
    case 7:
        if (Scene_Cut) {
            G_Timer = 1;
        }
        if (--G_Timer == 0) {
            GO_No[0]++;
            bgm_fade_out(0x222);
            WIN_X = 1;
        }
        break;
    case 8:
        if (--G_Timer == 0) {
            Request_Fade(109, 0);
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            GO_No[1] = 3;
            Forbid_Break = 0;
            Setup_Result_OBJ();
            effect_76_init(65);
            Order[65] = 3;
            Order_Timer[65] = 1;
            effect_76_init(56);
            Order[56] = 3;
            Order_Timer[56] = 1;
        }
        break;
    }
}



void GameOver_3rd(void) {
    WIN_X = 1;
}



void Setup_Result_OBJ(void) {
    effect_76_init(0x32);
    Order[0x32] = 3;
    Order_Timer[0x32] = 1;
    effect_76_init(0x33);
    Order[0x33] = 3;
    Order_Timer[0x33] = 1;
    effect_L1_init(7);
    effect_L1_init(8);
    effect_L1_init(9);
    effect_L1_init(0xA);
    effect_L1_init(0xB);
    effect_L1_init(0xC);
    effect_L1_init(0xD);
    effect_L1_init(0xE);
}



/* provisional name */
s32 Short_Ending_Scene(void) {
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    switch (GO_No[0]) {
    case 0:
        GO_No[0]++;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            GO_No[0]++;
            Cover_Timer = 24;
            Order[55] = 4;
            Order_Timer[55] = 1;
            System_all_clear_Wait();
            bg_etc_write(7);
            Setup_Virtual_BG(0, 0x200, 0);
        }
        break;
    case 2:
        if (--Cover_Timer == 0) {
            GO_No[0]++;
            Clear_Flash_No();
            Switch_Screen_Init(0, 1);
        }
        break;
    case 3:
        if (Switch_Screen_Revival() != 0) {
            GO_No[0]++;
            G_Timer = 150;
            Ignore_Entry[LOSER] = 0;
        }
        break;
    case 4:
        if (--G_Timer == 0) {
            GO_No[0]++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}



s16 Continue_Scene(void) {
    void (*Scene_Tbl[5])() = { Continue_1st, Continue_2nd, Continue_3rd, Continue_4th, Continue_5th };
    CONTINUE_X = 0;
    Scene_Tbl[Cont_No]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    bg_pos_hosei_sub3(1);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    Bg_Family_Set_appoint(1);
    return CONTINUE_X;
}



void Continue_1st(void) {
    switch (Cont_Sub_No) {
    case 0:
        Cont_Sub_No++;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
        Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos + 458;
        Offset_BG_X[3] = 0;
        Offset_BG_X[1] = 0;
        bg_mvxy.a[0].sp = 0xE0000;
        bg_mvxy.d[0].sp = 0;
        Next_Step = 0;
        Setup_Continue_OBJ();
        effect_A9_init(55, 0, 19, 0);
        bgm_request(8);
        effect_76_init(56);
        Order[56] = 3;
        Order_Timer[56] = 1;
        effect_58_init(12, 1, 3);
        effect_58_init(12, 1, 1);
        Suicide[2] = 1;
        effect_58_init(16, 5, 2);
        break;
    case 1:
        if (Next_Step) {
            Cont_Sub_No++;
            Cont_Timer = 20;
        }
        break;
    case 2:
        if (((s8)Scene_Cut)) {
            Cont_Timer = 1;
        }
        if (--Cont_Timer == 0) {
            Cont_No++;
            Cont_Sub_No = 0;
            Continue_Count_Down[LOSER] = 0;
        }
        break;
    }
}



void Continue_2nd(void) {
    if (Continue_Count[LOSER] < 0) {
        Cont_No++;
    }
}

s32 Continue_3rd(void) {
    s16 exit;
    exit = Check_Exit_Continue();
    Cont_Timer = exit;
    if (exit) {
        Cont_No++;
    }
    return exit;
}



void Continue_4th(void) {
    if (--Cont_Timer == 0) {
        Cont_No++;
        CONTINUE_X = 1;
    }
}



/* Last step of the continue scene: report the scene as finished. */
void Continue_5th(void) {
    CONTINUE_X = 1;
}



void Setup_Continue_OBJ(void) {
    effect_49_init(4);
    effect_49_init(8);
    effect_95_init(4);
    effect_95_init(8);
    effect_95_init(1);
    effect_95_init(2);
    effect_76_init(59);
    Order[59] = 3;
    Order_Timer[59] = 1;
    effect_76_init(60);
    Order[60] = 3;
    Order_Timer[60] = 1;
    effect_76_init(61);
    Order[61] = 3;
    Order_Timer[61] = 1;
    effect_76_init(62);
    Order[62] = 3;
    Order_Timer[62] = 1;
    effect_76_init(63);
    Order[63] = 3;
    Order_Timer[63] = 1;
}



s32 Check_Exit_Continue(void) {
    if (E_Number[0][0] == 2 || E_Number[1][0] == 2) {
        return 0;
    }
    if (E_Number[LOSER ^ 1][0] == 0) {
        return 60;
    }
    if (E_Number[LOSER ^ 1][0] != 3 && E_Number[LOSER ^ 1][0] != 0) {
        return 0;
    }
    if (E_Number[LOSER][0] != 3 && E_Number[LOSER][0] != 0) {
        return 0;
    }
    return 1;
}

u32 Disp_Personal_Count(s16 id, char count) {
    return ((u32(*)())tilemap_print_hex_block)(DE_X[Entry_Mes_Wide[id]] + Entry_Mes_X[id] + 14, Text_Page_Y, 18, count, 1, 1);
}



s16 Check_Count_Cut(s16 PL_id, s16 Limit) {
    s16 xx;
    Continue_Cut[PL_id] = 0;
    if (Continue_Count[PL_id] >= (Limit)) {
        return 0;
    }
    if (PL_id) {
        xx = p2sw_0 & ~p2sw_1;
    } else {
        xx = p1sw_0 & ~p1sw_1;
    }
    return xx & 0x3F0;
}



/* provisional name */
s32 Clear_Personal_Data(s16 PL_id) {
    s16 xx;
    s32 rc;
    Lost_Round[PL_id] = 0;
    Super_Arts_Finish[PL_id] = 0;
    Perfect_Finish[PL_id] = 0;
    Cheap_Finish[PL_id] = 0;
    Completion_Bonus[PL_id][0] = 0;
    Completion_Bonus[PL_id][1] = 0;
    Stage_Continue[PL_id] = 0;
    Introduce_Boss[PL_id][0] = 0;
    Introduce_Boss[PL_id][1] = 0;
    Introduce_Break_Into[PL_id] = 0;
    Score[PL_id][0] = 0;
    Stock_Score[PL_id] = 0;
    Stage_Stock_Score[PL_id] = 0;
    Continue_Coin[PL_id] = 0;
    Win_Record[PL_id] = 0;
    Stock_Win_Record[PL_id] = 0;
    VS_Index[PL_id] = 0;
    Decided_My_char[PL_id] = 0xFF;
    Arts_Y[PL_id] = 0;
    Continue_Count[PL_id] = 0;
    Continue_Coin2[PL_id] = 0;
    Sel_PL_Complete[PL_id] = 0;
    Sel_Arts_Complete[PL_id] = 0;
    Sel_EM_Complete[PL_id] = 0;
    Personal_Continue_Flag[PL_id] = 0;
    Last_Player_id = -1;
    Last_Super_Arts[PL_id] = 0;
    Last_My_char[PL_id] = -1;
    Last_My_char2[PL_id] = -1;
    Last_Selected_EM[PL_id] = 1;
    Select_Start[PL_id] = 0;
    paring_ctr_vs[0][PL_id] = 0;
    Straight_Counter[PL_id] = 0;
    Straight_Flag[PL_id] = 0;
    SC_Personal_Time[PL_id] = 481;
    card_pl_work_clear(PL_id);
    E_Number[PL_id][0] = 0;
    E_Number[PL_id][1] = 0;
    E_Number[PL_id][2] = 0;
    E_Number[PL_id][3] = 0;
    E_07_Flag[PL_id] = 0;
    if (PL_id == 0) {
        Cursor_X[0] = 1;
        Cursor_Y[0] = 0;
        rc = (s32)E_07_Flag;
    } else {
        Cursor_X[1] = 5;
        Cursor_Y[1] = rc = 2;
    }
    for (xx = 0; xx < 10; xx++) {
        EM_History[PL_id][xx] = 0;
    }
    return rc;
}



void Clear_Win_Type(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        win_type[0][i] = 0;
        win_type[1][i] = 0;
    }
}



/* provisional name */
s32 Check_Coin_In(s16 pl) {
    s32 sw1 = (*(s8*)&(coin_chute1_w[6]));
    s32 sw2 = coin_chute2_w[6];
    switch (Chute_Mode) {
    case 0:
    case 1:
        return sw1 | sw2;
    }
    switch (pl) {
    case 0:
        return sw1;
    default:
        return sw2;
    }
}



void cal_damage_vitality(PLW* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    s32 t;
    if (as->player_number == PL_GOUKI2) {
        yy = Damage_Rate_Data[1][Round_Level];
    } else {
        yy = Damage_Rate_Data[0][Round_Level];
    }
    t = power;
    t *= yy;
    ds->wu.dm_vital = t / 100;
    if (as->wu.work_id == 1) {
        t = ds->wu.dm_vital;
        t *= as->att_plus;
        ds->wu.dm_vital = t / 8;
    }
    if (ds->wu.work_id == 1) {
        t = ds->wu.dm_vital;
        t *= ds->def_plus;
        ds->wu.dm_vital = t / 8;
    }
}



void cal_damage_vitality_eff(WORK_Other* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    s32 t;
    if (((PLW*)as)->player_number == PL_GOUKI2) {
        yy = Damage_Rate_Data[1][Round_Level];
    } else {
        yy = Damage_Rate_Data[0][Round_Level];
    }
    t = power;
    t *= yy;
    ds->wu.dm_vital = t / 100;
    if (as->wu.work_id == 1) {
        t = ds->wu.dm_vital;
        t *= ((PLW*)as)->att_plus;
        ds->wu.dm_vital = t / 8;
    }
    if (ds->wu.work_id == 1) {
        t = ds->wu.dm_vital;
        t *= ds->def_plus;
        ds->wu.dm_vital = t / 8;
    }
}

void Additinal_Score_DM(WORK_Other* wk, u32 ix) {
    u32* score_tbl = Score_Data;
    s16 id;
    s8 pl;
    if (wk->wu.work_id == 1) {
        id = wk->wu.id;
    } else {
        if (((WORK*)wk->my_master)->work_id != 1) {
            return;
        }
        id = wk->master_id;
    }
    pl = id;
    Score[pl][2] += score_tbl[ix & 0xFFFF];
    if (plw[id].wu.operator) {
        if (!Play_Type) {
            Score[pl][0] += score_tbl[ix & 0xFFFF];
            if (Score[pl][0] >= 99999900) {
                Score[pl][0] = 99999900;
            }
        } else {
            Score[pl][1] += score_tbl[ix & 0xFFFF];
        }
    }
    if (plw[id].wu.operator && bg_w.stage != 22 && bg_w.stage != 21) {
        Disp_Player_Score(id);
    }
}



/* provisional name */
void Disp_Player_Score(s16 id) {
    s16 digit[8];
    u32 score = Score[id][Play_Type];
    s32 div = 10000000;
    s16 top = -1;
    s16 x;
    s16 i;
    s32 t;
    for (i = 6; i >= 1; i--) {
        digit[i] = score / div;
        t = digit[i];
        t *= div;
        score -= t;
        if (top < 0 && digit[i]) {
            top = i;
        }
        div /= 10;
    }
    x = Score_X_Pos_Data[id][Game_setting.mode] - top - 1;
    for (i = top; i >= 1; i--) {
        score8x16_put(x, 0, 16, digit[i]);
        x++;
    }
}



/* provisional name */
void Score_Sub(void) {
    u16 num;
    s32 tens;
    if (plw[0].wu.operator != 0 && Demo_Flag != 0) {
        tilemap_clear_rect(Score_X_Pos_Data[0][(*&Game_setting).mode] - 7, 0, Score_X_Pos_Data[0][(*&Game_setting).mode], 1);
        Disp_Player_Score(0);
        num = Continue_Coin[0];
        tens = num / 10;
        score8x16_put(Score_X_Pos_Data[0][(*&Game_setting).mode] - 1, 0, 16, tens);
        score8x16_put(Score_X_Pos_Data[0][(*&Game_setting).mode], 0, 16, num - tens * 10);
    }
    if (plw[1].wu.operator != 0 && Demo_Flag != 0) {
        tilemap_clear_rect(Score_X_Pos_Data[1][(*&Game_setting).mode] - 7, 0, Score_X_Pos_Data[1][(*&Game_setting).mode], 1);
        Disp_Player_Score(1);
        num = Continue_Coin[1];
        tens = num / 10;
        score8x16_put(Score_X_Pos_Data[1][(*&Game_setting).mode] - 1, 0, 16, tens);
        score8x16_put(Score_X_Pos_Data[1][(*&Game_setting).mode], 0, 16, num - tens * 10);
    }
}

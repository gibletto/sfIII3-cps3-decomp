/*
 * WIN_2.C  Winner and loser scenes
 *
 * Scene routines called from Game_Main between matches. Winner_Scene and Loser_Scene run the win and
 * lose screens step by step (background, portraits, win records, BGM, button cut); Setup_Virtual_BG
 * and Setup_Wins_OBJ place the background and spawn the scene objects; Game_Over starts the game-over
 * screens.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "end_main.h"
#include "EM_Cand.h"
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
#include "Eff95.h"
#include "EFFB8.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF49.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "Eff76.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFL1.h"
#include "aboutspr.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "continue.h"
#include "win_2.h"
#include "fighter.h"



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



void Win_1st(void) {
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
    load_char_gfx(0x95E0, 1);
    if (Play_Type == 0) {
        Last_Selected_EM[Winner_id] = 1;
    }
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

/*
 * next_cpu.c  Next opponent selection, bonus stage entry and VS screen setup
 *
 * Screen sequences run between fights of a one-player game. Next_CPU_1st..6th scroll to the
 * opponent select screen, show the history of beaten opponents with their grades
 * (Setup_History_OBJ), build the list of possible next opponents (EM list) and let the player
 * pick one with the lever before the voice call and VS objects. After_Bonus_* returns from a
 * bonus stage, Select_CPU_* handles the first opponent choice, Next_Bonus_* announces a bonus
 * stage, and Next_Q_* runs the sequence for the hidden challenger.
 * Helpers: Check_Bonus_Stage / Check_Bonus_Type decide when the bonus stages (after the 3rd and
 * 6th fights, if enabled in the settings) are played, Setup_Com_Arts / Setup_Com_Color choose the
 * computer's super art and colour, Setup_PL_Color picks the player colour from the buttons,
 * Setup_VS_OBJ builds the VS screen objects, and Check_Auto_Cut skips scenes on a button press.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "EM_Cand.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "cmb_win.h"
#include "Eff39.h"
#include "EFF44.h"
#include "EFF99.h"
#include "effa0.h"
#include "EFFA3.h"
#include "effa5.h"
#include "effa5_input.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sel_pl.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF38.h"
#include "EFF42.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "EFF75_ORDER.h"
#include "Eff76.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EffE0.h"
#include "EffK6.h"
#include "PLS02.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "next_cpu.h"



/* provisional name */
s32 Next_CPU(void) {
    void (*Next_CPU_Tbl[10])() = { Next_CPU_1st, Next_CPU_2nd, Next_CPU_3rd, Next_CPU_4th, Next_CPU_5th, Next_CPU_6th, Next_Bonus_1st, Next_Bonus_2nd, Next_Bonus_3rd, Next_Bonus_End };
    if (Break_Into) {
        return 0;
    }
    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_CPU_Tbl[SC_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    Time_Over = 0;
    return SEL_CPU_X;
}



void Next_CPU_1st(void) {
    u16 Rnd;
    SC_No[0]++;
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    Start_X = bg_w.bgw[3].wxy[0].disp.pos;
    bg_mvxy.a[0].sp = 0x40000;
    bg_mvxy.d[0].sp = 0;
    Sel_EM_Complete[Player_id] = 0;
    Temporary_EM[Player_id] = Last_Selected_EM[Player_id];
    Select_Timer = 32;
    Setup_EM_List();
    if (VS_Index[Player_id] == 0) {
        effect_A9_init(32, 0, 0, 1);
    } else {
        Setup_History_OBJ();
        if (VS_Index[Player_id] < 9) {
            Setup_Next_Stage(58);
        } else {
            Setup_Next_Stage(59);
        }
    }
    Setup_Regular_OBJ(Player_id);
    Moving_Plate[Player_id] = 0;
    bgm_request(7);
    Order[56] = 3;
    Order_Timer[56] = 1;
    Time_Stop = 1;
    Unit_Of_Timer = 50;
    effect_A5_entry();
    Rnd = ((s16)random_16_com()) & 3;
    effect_58_init(6, 10, ((s16)EM_Select_Voice_Data[Rnd]));
    Next_Step = 0;
    Suicide[2] = 1;
    Cut_Scroll = 2;
    effect_58_init(13, 1, 3);
    effect_58_init(16, 5, 2);
}



void Next_CPU_2nd(void) {
    Check_Auto_Cut();
    if (Next_Step) {
        SC_No[0]++;
        SC_No[1] = 0;
        Time_Stop = 0;
    }
}



void Next_CPU_3rd(void) {
    switch (SC_No[1]) {
    case 0:
        if (Player_id) {
            Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
        } else {
            Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
        }
        if (!Sel_EM_Complete[Player_id]) {
            break;
        }
        SC_No[1]++;
        Setup_Next_Fighter();
        if (VS_Index[Player_id] < 8) {
            S_Timer = 50;
            break;
        }
        SC_No[1] = 2;
        S_Timer = 100;
        break;
    case 1:
        if (--S_Timer == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
        }
        break;
    case 2:
        if (--S_Timer <= 70) {
            if (!Check_EM_Speech()) {
                SC_No[1]++;
            } else {
                SC_No[0] = 4;
                SC_No[1] = 0;
            }
        }
        break;
    case 3:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
        }
        break;
    }
}

s32 Next_CPU_4th(void) {
    switch (SC_No[1]) {
    case 0:
        if (Request_Fade(65, 0)) {
            SC_No[1]++;
            Forbid_Break = 0;
            bgm_request(3);
            S_Timer = 0xB2;
            Exit_Timer = 2;
            bg_w.bgw[0].wxy[1].disp.pos = 0x200;
            bg_w.bgw[1].wxy[1].disp.pos = 0x200;
            bg_w.bgw[3].wxy[1].disp.pos += 0x200;
            Setup_VS_OBJ(0);
            effect_58_init(15, 5, 0);
        }
        break;
    case 1:
        Check_Fade_Complete_SP();
        if (--Exit_Timer == 0) {
            SC_No[1]++;
            Setup_Virtual_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
            Setup_Virtual_BG(1, bg_w.bgw[1].wxy[0].disp.pos, bg_w.bgw[1].wxy[1].disp.pos);
            Setup_Virtual_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
        }
        break;
    case 2:
        S_Timer--;
        if (Check_Fade_Complete_SP()) {
            SC_No[1]++;
            if (S_Timer < 0) {
                S_Timer = 1;
            }
        }
        break;
    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0] = 5;
            SEL_CPU_X = 1;
        }
        break;
    }
}



void Next_CPU_5th(void) {
    switch (SC_No[1]) {
    case 0:
        SC_No[1]++;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            SC_No[1]++;
            Cover_Timer = 9;
        }
        break;
    case 2:
        SC_No[1]++;
        bg_w.bgw[0].wxy[1].disp.pos = 512;
        bg_w.bgw[1].wxy[1].disp.pos = 512;
        bg_w.bgw[3].wxy[1].disp.pos += 512;
        Setup_Virtual_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
        Setup_Virtual_BG(1, bg_w.bgw[1].wxy[0].disp.pos, bg_w.bgw[1].wxy[1].disp.pos);
        Setup_Virtual_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
        Setup_VS_OBJ(1);
        Suicide[0] = 1;
        Next_Step = 0;
        Order[67] = 1;
        Order_Timer[67] = 10;
        Order_Dir[67] = 8;
        effect_76_init(67);
        Order[68] = 1;
        Order_Timer[68] = 10;
        Order_Dir[68] = 4;
        effect_76_init(68);
        break;
    case 3:
        if (--Cover_Timer == 0) {
            SC_No[1]++;
            Switch_Screen_Init(0, 1);
        }
        break;
    case 4:
        if (Switch_Screen_Revival() != 0) {
            SC_No[1]++;
            Forbid_Break = 0;
        }
        break;
    case 5:
        if (Next_Step & 0x80) {
            SC_No[1]++;
        }
        break;
    case 6:
        if (Request_Fade(65, 0)) {
            SC_No[1]++;
            Forbid_Break = 0;
            Suicide[3] = 1;
            effect_43_init(1, 0);
            bgm_request(3);
            S_Timer = 0xB2;
        }
        break;
    case 7:
        S_Timer--;
        if (Check_Fade_Complete_SP()) {
            SC_No[1]++;
            if (S_Timer < 0) {
                S_Timer = 1;
            }
            Introduce_Boss[Player_id][VS_Index[Player_id] - 8] |= 1;
        }
        break;
    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0] = 5;
            SEL_CPU_X = 1;
        }
        break;
    }
}



s32 Check_EM_Speech(void) {
    if (Introduce_Boss[Player_id][VS_Index[Player_id] - 8] & 1) {
        return 0;
    }
    return (u8)EM_Speech_Data[My_char[Player_id] - 1][VS_Index[Player_id] - 8];
}



void Next_CPU_6th(void)
{
    SEL_CPU_X = 1;
}



/* provisional name */
s32 After_Bonus(void) {
    void (*After_Bonus_Tbl[7])() = { After_Bonus_1st, After_Bonus_2nd, After_Bonus_3rd, After_Bonus_4th, Next_CPU_3rd, After_Bonus_6th, After_Bonus_End };
    if (Break_Into) {
        return 0;
    }
    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    After_Bonus_Tbl[SC_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    Time_Over = 0;
    return SEL_CPU_X;
}



/* provisional name */
void After_Bonus_1st(void) {
    SC_No[0]++;
    Cover_Timer = 23;
    All_Clear_Suicide();
    System_all_clear_Wait();
    base_y_pos = 40;
    bg_etc_write(6);
    Setup_Virtual_BG(0, 512, 0);
    Setup_Virtual_BG(2, 768, 0);
    Setup_Virtual_BG(1, 512, 0);
    Setup_Virtual_BG(3, 704, 0);
}



void After_Bonus_2nd(void) {
    u8* p = &SC_No[1];
    switch (*p) {
    case 0:
        (*p)++;
        load_any_color(5);
        effect_76_init(55);
        Order[55] = 3;
        Order_Timer[55] = 1;
        effect_76_init(56);
        Order[56] = 3;
        Order_Timer[56] = 1;
    case 1:
        if (--Cover_Timer == 0) {
            SC_No[1]++;
            tilemap_fill_all(0, 32);
            Clear_Flash_No();
            commit_name_entry_row_both_players(Text_Page_Y);
            Scrn_Move_Set(4, 0, 0x100);
            Switch_Screen_Init(0, 1);
        }
        break;
    case 2:
        if (Switch_Screen_Revival()) {
            SC_No[0]++;
            SC_No[1] = 0;
            S_Timer = 30;
            bgm_request(7);
            Forbid_Break = 0;
            Ignore_Entry[LOSER] = 0;
        }
        break;
    }
}



/* provisional name */
void After_Bonus_3rd(void) {
    u16 Rnd;
    SC_No[0]++;
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    Start_X = bg_w.bgw[3].wxy[0].disp.pos;
    bg_mvxy.a[0].sp = 0x40000;
    bg_mvxy.d[0].sp = 0;
    Sel_EM_Complete[Player_id] = 0;
    Temporary_EM[Player_id] = Last_Selected_EM[Player_id];
    Select_Timer = 32;
    Setup_EM_List();
    if (VS_Index[Player_id] == 0) {
        effect_A9_init(32, 0, 0, 1);
    } else {
        Setup_History_OBJ();
        if (VS_Index[Player_id] < 9) {
            Setup_Next_Stage(58);
        } else {
            Setup_Next_Stage(59);
        }
    }
    Setup_Regular_OBJ(Player_id);
    Moving_Plate[Player_id] = 0;
    Time_Stop = 1;
    Unit_Of_Timer = 50;
    effect_A5_entry();
    Rnd = random_16_com() & 3;
    effect_58_init(6, 10, EM_Select_Voice_Data[Rnd]);
    Suicide[2] = 1;
    Next_Step = 0;
    Cut_Scroll = 2;
    effect_58_init(13, 1, 3);
    effect_58_init(16, 5, 2);
}



/* provisional name */
void After_Bonus_4th(void) {
    Check_Auto_Cut();
    if (Next_Step) {
        SC_No[0]++;
        SC_No[1] = 0;
        Time_Stop = 0;
    }
}



/* provisional name */
void After_Bonus_6th(void) {
    switch (SC_No[1]) {
    case 0:
        if (Request_Fade(65, 0)) {
            SC_No[1]++;
            Forbid_Break = 0;
            bgm_request(3);
            S_Timer = 0xB2;
            Exit_Timer = 2;
            bg_w.bgw[0].wxy[1].disp.pos = 0x200;
            bg_w.bgw[1].wxy[1].disp.pos = 0x200;
            bg_w.bgw[3].wxy[1].disp.pos += 0x200;
            Setup_VS_OBJ(0);
            effect_58_init(15, 5, 0);
        }
        break;
    case 1:
        if (--Exit_Timer == 0) {
            SC_No[1]++;
            Setup_Virtual_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
            Setup_Virtual_BG(1, bg_w.bgw[1].wxy[0].disp.pos, bg_w.bgw[1].wxy[1].disp.pos);
            Setup_Virtual_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
        }
        break;
    case 2:
        S_Timer--;
        if (Check_Fade_Complete_SP()) {
            SC_No[1]++;
            if (S_Timer < 0) {
                S_Timer = 1;
            }
        }
        break;
    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SEL_CPU_X = 1;
        }
        break;
    }
}



/* provisional name */
void After_Bonus_End(void) {
    SEL_CPU_X = 1;
}



/* provisional name */
s32 Select_CPU_First(void) {
    void (*SC_Tbl[4])() = { Select_CPU_1st, Select_CPU_2nd, Select_CPU_3rd, Select_CPU_4th };
    if (Break_Into) {
        return 0;
    }
    SEL_CPU_X = 0;
    SC_Tbl[SC_No[0]]();
    Time_Over = 0;
    return SEL_CPU_X;
}



void Select_CPU_1st(void) {
    SC_No[0]++;
    Sel_EM_Complete[Player_id] = 0;
    Temporary_EM[Player_id] = Last_Selected_EM[Player_id];
    Select_Timer = 32;
    Setup_EM_List();
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    if (VS_Index[Player_id] == 0) {
        bg_mvxy.a[0].sp = 0xA0000;
        bg_mvxy.d[0].sp = 0x18000;
        effect_A9_init(32, 0, 0, 1);
    } else {
        Setup_History_OBJ();
        bg_mvxy.a[0].sp = 0x40000;
        bg_mvxy.d[0].sp = 0;
        if (VS_Index[Player_id] < 9) {
            Setup_Next_Stage(58);
        } else {
            Setup_Next_Stage(59);
        }
        effect_76_init(66);
        Order[66] = 3;
        Order_Timer[66] = 1;
    }
    Setup_Regular_OBJ(Player_id);
    Moving_Plate[Player_id] = 0;
}



void Select_CPU_2nd(void) {
    u16 xx;
    switch (SC_No[1]) {
    case 0:
        SC_No[1]++;
        Order[Aborigine + 13] = 5;
        Order_Timer[Aborigine + 13] = 1;
        Order[Aborigine + 31] = 5;
        Order_Timer[Aborigine + 31] = 1;
        Order[Aborigine + 25] = 5;
        Order_Timer[Aborigine + 25] = 1;
        Order[37] = 4;
        Order_Timer[37] = 1;
        xx = random_16_com() & 3;
        effect_58_init(6, 10, EM_Select_Voice_Data[xx]);
        Cut_Scroll = 2;
        Next_Step = 0;
        effect_58_init(12, 1, 3);
    case 1:
        Check_Auto_Cut();
        if (Next_Step) {
            SC_No[0]++;
            SC_No[1] = 0;
            Time_Stop = 0;
        }
        break;
    }
}

void Select_CPU_3rd(void)
{
    s32 sw_on;
    s8 pid;

    switch (SC_No[1]) {
    case 0:
        pid = Player_id;
        if (Demo_Flag == 0) {
            if (pid != 0) {
                Sel_CPU_Sub(1, *Demo_Ptr[1], 0);
            } else {
                Sel_CPU_Sub(0, *Demo_Ptr[0], 0);
            }
            Demo_Ptr[Player_id]++;
        } else {
            if (pid) {
                Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
            } else {
                Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
            }
        }
        if (Sel_EM_Complete[Player_id]) {
            SC_No[1]++;
            Setup_Next_Fighter();
            if (VS_Index[Player_id] < 8) {
                S_Timer = 50;
            } else {
                SC_No[1] = 2;
                S_Timer = 100;
            }
        }
        break;

    case 1:
        if (--S_Timer == 0) {
            SC_No[1] = 4;
        }
        break;

    case 2:
        if (--S_Timer <= 50) {
            SC_No[1]++;
        }
        break;

    case 3:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[1]++;
        }
        break;

    case 4:
        SC_No[1] = 6;
        Order[Player_id + 11] = 4;
        Order_Timer[Player_id + 11] = 5;
        effect_38_init(COM_id, COM_id + 11, My_char[COM_id], 1, 2);
        Order[COM_id + 11] = 1;
        Order_Timer[COM_id + 11] = 1;
        if (EM_id != 0) {
            effect_98_init(COM_id, COM_id + 40, Super_Arts[COM_id], 2);
            Order[COM_id + 40] = 1;
            Order_Timer[COM_id + 40] = 1;
        }
        effect_75_init(42, 3, 2);
        Order[42] = 3;
        Order_Timer[42] = 1;
        Order_Dir[42] = 3;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 480;
        Offset_BG_X[3] = 0;
        if (VS_Index[Player_id] >= 8 && Check_EM_Speech() != 0) {
            SC_No[1] = 5;
            load_any_color(134);
            load_any_color(124);
            Order[67] = 1;
            Order_Timer[67] = 10;
            Order_Dir[67] = 8;
            effect_76_init(67);
            Order[68] = 1;
            Order_Timer[68] = 10;
            Order_Dir[68] = 4;
            effect_76_init(68);
        }
        Next_Step = 0;
        Cut_Scroll = 2;
        bg_mvxy.a[0].sp = 0x200000;
        bg_mvxy.d[0].sp = 0x18000;
        effect_58_init(12, 1, 3);
        break;

    case 5:
        if (Next_Step & 0x80) {
            SC_No[1] = 7;
            S_Timer = 20;
            Introduce_Boss[Player_id][VS_Index[Player_id] - 8] = 1;
        }
        break;

    case 6:
        if (Next_Step & 1) {
            SC_No[1]++;
            S_Timer = 20;
        }
        break;

    case 7:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
        }
        break;
    }
}

void Select_CPU_4th(void)
{
    SEL_CPU_X = 1;
    Next_Step = 1;
}



void Next_Bonus_1st(void) {
    u16 Rnd;
    SC_No[0]++;
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    Start_X = bg_w.bgw[3].wxy[0].disp.pos;
    bg_mvxy.a[0].sp = 0x40000;
    bg_mvxy.d[0].sp = 0;
    Setup_History_OBJ();
    Setup_Next_Stage(60);
    bgm_request(7);
    Order[56] = 3;
    Order_Timer[56] = 1;
    Rnd = random_16_com() & 3;
    effect_58_init(6, 10, EM_Select_Voice_Data[Rnd]);
    Suicide[2] = 1;
    Next_Step = 0;
    Cut_Scroll = 2;
    effect_58_init(13, 1, 3);
    effect_58_init(16, 5, 2);
}

u32 Next_Bonus_2nd(void) {
    switch (SC_No[1]) {
    case 0:
        Check_Auto_Cut();
        if (Next_Step) {
            SC_No[1]++;
            S_Timer = 90;
            effect_58_init(6, 5, 0xA0);
        }
        break;
    case 1:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
        }
        break;
    }
}

void Next_Bonus_3rd(void) {
    switch (SC_No[1]) {
    case 0:
        if (Request_Fade(0x41, 0)) {
            SC_No[1]++;
            Forbid_Break = 0;
            bgm_request(3);
            S_Timer = 178;
            Exit_Timer = 2;
            bg_w.bgw[0].wxy[1].disp.pos = 512;
            bg_w.bgw[1].wxy[1].disp.pos = 512;
            bg_w.bgw[3].wxy[1].disp.pos += 512;
            My_char[COM_id] = Bonus_Type;
            Setup_VS_OBJ(0);
            effect_58_init(15, 5, 0);
        }
        break;
    case 1:
        if (--Exit_Timer == 0) {
            SC_No[1]++;
            Setup_Virtual_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
            Setup_Virtual_BG(1, bg_w.bgw[1].wxy[0].disp.pos, bg_w.bgw[1].wxy[1].disp.pos);
            Setup_Virtual_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
        }
        break;
    case 2:
        S_Timer--;
        if (Check_Fade_Complete_SP()) {
            SC_No[1]++;
            if (S_Timer < 0) {
                S_Timer = 1;
            }
        }
        break;
    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SEL_CPU_X = 2;
        }
        break;
    }
}



void Next_Bonus_End(void) {
    SEL_CPU_X = 2;
}



s32 Next_Q(void) {
    void (*Next_Q_Tbl[4])() = { Next_Q_1st, Next_Q_2nd, Next_Q_3rd, PL_Sel_1st };
    if (Break_Into != 0) {
        return 0;
    }
    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_Q_Tbl[SC_No[0]]();
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    Time_Over = 0;
    return SEL_CPU_X;
}



/* provisional name */
void Next_Q_1st(void) {
    SC_No[0]++;
    Cover_Timer = 23;
    All_Clear_Suicide();
    System_all_clear_Wait();
    base_y_pos = 40;
    Setup_ID();
    bg_etc_write(6);
    EM_id = 18;
    Setup_Virtual_BG(0, 0x200, 0);
    Setup_Virtual_BG(2, 0x300, 0);
    Setup_Virtual_BG(1, 0x200, 0);
    Setup_Virtual_BG(3, 0x2C0, 0);
}



void Next_Q_2nd(void) {
    s8* pb = &Cover_Timer;
    u8* p = &SC_No[1];
    switch (*p) {
    case 0:
        (*p)++;
        load_any_color(5);
    case 1:
        if (--*pb == 5) {
            SC_No[1]++;
            tilemap_fill_all(0, 32);
            Setup_Next_Fighter();
            bg_w.bgw[0].wxy[1].disp.pos = 0x200;
            Setup_Virtual_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
        }
        break;
    case 2:
        if (--*pb == 0) {
            SC_No[1]++;
            Clear_Flash_No();
            commit_name_entry_row_both_players(Text_Page_Y);
            Setup_VS_OBJ(1);
            Scrn_Move_Set(4, 0, 0x100);
            Switch_Screen_Init(0, 1);
        }
        break;
    case 3:
        if (Switch_Screen_Revival()) {
            SC_No[0]++;
            SC_No[1] = 0;
            S_Timer = 10;
            bgm_request(7);
            Forbid_Break = 0;
            Ignore_Entry[LOSER] = 0;
        }
        break;
    }
}



void Next_Q_3rd(void) {
    switch (SC_No[1]) {
    case 0:
        if (--S_Timer == 0) {
            SC_No[1]++;
        }
        break;
    case 1:
        if (Request_Fade(65, 0)) {
            SC_No[1]++;
            Forbid_Break = 0;
            effect_43_init(1, 0);
            bgm_request(3);
            S_Timer = 180;
            effect_58_init(15, 5, 0);
            return;
        }
        break;
    case 2:
        S_Timer--;
        if (Check_Fade_Complete_SP()) {
            SC_No[1]++;
            if (S_Timer < 0) {
                S_Timer = 1;
            }
        }
        break;
    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }
        if (--S_Timer == 0) {
            SC_No[0]++;
            SEL_CPU_X = 1;
        }
        break;
    }
}



/* Last step of the next-opponent scene: report the scene as finished. */
void PL_Sel_1st(void) {
    SEL_CPU_X = 1;
}



/* provisional name */
void Sel_CPU_Sub(PL_id, sw)
s16 PL_id;
u16 sw;
{
    u16 lever_sw;
    if (Sel_EM_Complete[PL_id]) {
        return;
    }
    if (Moving_Plate[PL_id]) {
        return;
    }
    if (Time_Over) {
        sw = 16;
    }
    if (VS_Index[PL_id] >= 8) {
        sw = 16;
    }
    lever_sw = sw & 3;
    if (lever_sw & 2) {
        if (Temporary_EM[Player_id] == 2) {
            return;
        }
        Sound_SE(PL_id + 96);
        Moving_Plate[PL_id] = 2;
        Moving_Plate_Counter[PL_id] = 2;
        Temporary_EM[Player_id] = 2;
    }
    if (lever_sw & 1) {
        if (Temporary_EM[Player_id] == 1) {
            return;
        }
        Sound_SE(PL_id + 96);
        Moving_Plate[PL_id] = 1;
        Moving_Plate_Counter[PL_id] = 2;
        Temporary_EM[Player_id] = 1;
    }
    if (sw & 0x3F0) {
        Sel_EM_Complete[PL_id] = 1;
        EM_id = EM_List[Player_id][Temporary_EM[Player_id] - 1];
        My_char[COM_id] = EM_id;
        Time_Stop = 2;
        if ((&VS_Index[0])[PL_id] < 8) {
            Sound_SE(ID + 98);
            Sound_SE(EM_Select_SE_Data[random_16_com()]);
        }
        Last_Selected_EM[PL_id] = Temporary_EM[PL_id];
    }
}

void Setup_EM_List(void)
{
    EM_List[Player_id][0] = EM_Candidate[Player_id][0][VS_Index[Player_id]];
    EM_List[Player_id][1] = EM_Candidate[Player_id][1][VS_Index[Player_id]];
}



void Setup_Next_Fighter(void) {
    paring_counter[COM_id] = 0;
    paring_bonus_r[COM_id] = 0;
    My_char[COM_id] = EM_id;
    if (EM_id == 18) {
        Battle_Country = Q_Country;
        bg_w.stage = Q_Country;
    } else {
        Battle_Country = EM_id;
        bg_w.stage = Battle_Country;
    }
    bg_w.area = 0;
    Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();
    Setup_Com_Color();
    Setup_PL_Color(COM_id, Com_Color_Shot);
}



s32 Setup_Com_Arts(void) {
    if (EM_id == 0) {
        return 1;
    }
    if (Stock_Com_Arts[Player_id] == -1) {
        return Arts_Rnd_Data[random_16_com() & 7];
    }
    return Stock_Com_Arts[Player_id];
}



void Setup_Com_Color(void) {
    Com_Color_Shot = Stock_Com_Color[Player_id];
    if (Break_Com[Player_id][EM_id]) {
        Com_Color_Shot = 0x200;
    } else {
        Com_Color_Shot = 16;
    }
}



void Setup_PL_Color(s16 PL_id, u16 sw) {
    s8 id_0;
    s8 id_1;
    s8* mine = &Player_Color[PL_id];
    s8* other = &Player_Color[PL_id ^ 1];
    if (plw[PL_id ^ 1].wu.operator == 0) {
        id_0 = -1;
        id_1 = 1;
    } else {
        id_0 = My_char[PL_id];
        id_1 = My_char[PL_id ^ 1];
    }
    if (Sel_PL_Complete[PL_id ^ 1] == 0) {
        id_0 = 127;
    }
    switch (sw) {
    case 336:
        if (Version_Type == 3) {
            if (*other == 0 && id_0 == id_1) {
                *mine = 3;
            } else {
                *mine = 0;
            }
        } else if (*other == 6 && id_0 == id_1) {
            *mine = 0;
        } else {
            *mine = 6;
        }
        break;
    case 16:
        if (*other == 0 && id_0 == id_1) {
            *mine = 3;
        } else {
            *mine = 0;
        }
        break;
    case 32:
        if (*other == 1 && id_0 == id_1) {
            *mine = 4;
        } else {
            *mine = 1;
        }
        break;
    case 64:
        if (*other == 2 && id_0 == id_1) {
            *mine = 5;
        } else {
            *mine = 2;
        }
        break;
    case 128:
        if (*other == 3 && id_0 == id_1) {
            *mine = 0;
        } else {
            *mine = 3;
        }
        break;
    case 256:
        if (*other == 4 && id_0 == id_1) {
            *mine = 1;
        } else {
            *mine = 4;
        }
        break;
    default:
        if (*other == 5 && id_0 == id_1) {
            *mine = 2;
        } else {
            *mine = 5;
        }
        break;
    }
}



void Setup_Regular_OBJ(s16 PL_id) {
    if (VS_Index[Player_id] < 8) {
        Regular_OBJ_Sub(PL_id, 2);
        Regular_OBJ_Sub(PL_id, 1);
        effect_A9_init(16, 5, 10, 0);
        effect_42_init(9);
        effect_42_init(10);
        Order[9] = 0;
        Order[10] = 0;
        Order_Timer[9] = 1;
        Order_Timer[10] = 1;
        return;
    }
    effect_A9_init(33, EM_List[PL_id][1], 5, 0);
    effect_A9_init(34, EM_List[PL_id][1], 20, 0);
    effect_A9_init(12, EM_List[PL_id][1], 21, 0);
    effect_A9_init(57, 0, 22, 0);
}



void Regular_OBJ_Sub(s16 PL_id, s16 Dir) {
    s16 ix = Dir - 1;
    s16 x;
    effect_A9_init(33, EM_List[PL_id][ix], ix + 4, 0);
    x = chkNameAkuma(EM_List[PL_id][ix]);
    effect_A9_init(34, x + EM_List[PL_id][ix], ix + 6, 0);
    effect_A9_init(12, EM_List[PL_id][ix], ix + 8, 0);
    effect_E0_init(Dir, 0, 0);
    effect_E0_init(Dir, 1, 0);
}



void Setup_History_OBJ(void) {
    s16 q_index = (*(s8(*)[])((&Break_Com[0][18])))[(s8)(Player_id * 24)];
    s16 xx;
    s16 ix;
    s16 grade;
    effect_A9_init(79, 12, 11, 0);
    Offset_BG_X[3] = 88;
    effect_A9_init(79, 13, 12, 0);
    Offset_BG_X[3] += 80;
    for (xx = 0; xx < VS_Index[Player_id]; xx++) {
        effect_A9_init(79, 13, 12, 0);
        effect_A9_init(79, xx, 13, 0);
        effect_A9_init(79, 10, 14, 0);
        ix = chkNameAkuma(EM_History[Player_id][xx]);
        effect_A9_init(81, ix + EM_History[Player_id][xx], 15, 0);
        effect_A9_init(12, EM_History[Player_id][xx], 16, 0);
        grade = judge_final[Player_id][0].vs_cpu_grade[xx];
        if (grade == -1) {
            grade = 0;
        }
        effect_A9_init(80, grade, 17, 0);
        Offset_BG_X[3] += 88;
        if (q_index == 0 || (q_index - 1) != xx) {
            continue;
        }
        effect_A9_init(79, 13, 12, 0);
        effect_A9_init(81, 18, 15, 0);
        effect_A9_init(12, 18, 16, 0);
        grade = judge_final[Player_id]->vs_cpu_grade[15];
        if (grade == -1) {
            grade = 0;
        }
        effect_A9_init(80, grade, 17, 0);
        Offset_BG_X[3] += 88;
    }
    Offset_BG_X[3] -= 40;
}



void Setup_VS_OBJ(s16 Option) {
    effect_38_init(0, 11, My_char[0], 1, 0);
    Order[11] = 3;
    Order_Timer[11] = 1;
    effect_38_init(1, 12, My_char[1], 1, 0);
    Order[12] = 3;
    Order_Timer[12] = 1;
    effect_K6_init(0, 35, 35, 0);
    Order[35] = 3;
    Order_Timer[35] = 1;
    effect_K6_init(1, 36, 35, 0);
    Order[36] = 3;
    Order_Timer[36] = 1;
    effect_39_init(0, 17, My_char[0], 0, 0);
    Order[17] = 3;
    Order_Timer[17] = 1;
    effect_39_init(1, 18, My_char[1], 0, 0);
    Order[18] = 3;
    Order_Timer[18] = 1;
    effect_K6_init(0, 29, 29, 0);
    Order[29] = 3;
    Order_Timer[29] = 1;
    effect_K6_init(1, 30, 29, 0);
    Order[30] = 3;
    Order_Timer[30] = 1;
    if (My_char[0] != 21) {
        effect_75_init(42, 3, 0);
    }
    Order[42] = 3;
    Order_Timer[42] = 1;
    Order_Dir[42] = 5;
    if (Option == 0) {
        effect_43_init(1, 0);
    }
}



s32 Check_Bonus_Stage(void) {
    Setup_ID();
    if ((Game_setting.bonus & 1) == 0) {
        return 0;
    }
    Bonus_Type = Check_Bonus_Type();
    if (Bonus_Type == 0) {
        return 0;
    }
    return Completion_Bonus[Player_id][Bonus_Type - 21] = 1;
}



u8 Check_Bonus_Type(void) {
    s32 m = 0x80;
    s16* w;
    s8* p;
    w = &VS_Index[Player_id];
    p = Completion_Bonus[Player_id];
    if (*w >= 6) {
        if (p[1] & m) {
            return 0;
        }
        return 22;
    }
    if (*w >= 3) {
        if (p[0] & m) {
            return 0;
        }
        return 21;
    }
    return 0;
}



void Setup_Next_Stage(s16 dir_step) {
    s16 ix;
    for (ix = 0; ix < 4; ix++) {
        effect_A9_init(dir_step, ix, ix + 23, 0);
    }
}



/* A button press counts Cut_Scroll down (not below 0); returns non-zero when a player pressed one. */
s32 Check_Auto_Cut(void) {
    if (Auto_Cut_Sub() != 0) {
        if (--Cut_Scroll < 0) {
            Cut_Scroll = 0;
        }
    }
}



s32 Auto_Cut_Sub(void) {
    if (plw[0].wu.operator) {
        if (~p1sw_1 & p1sw_0 & 0x3F0) {
            return 1;
        }
    }
    if (plw[1].wu.operator) {
        if (~p2sw_1 & p2sw_0 & 0x3F0) {
            return 1;
        }
    }
    return 0;
}

/*
 * sel_pl.c  Player (character) select screen
 *
 * Select_Player is called each frame while the character select screen is up. Sel_PL_Control runs
 * the screen-wide sequence (Sel_PL_Cont_*: background, face panel and object setup, the face and
 * object controllers) and the exit sequence (Exit_1st..7th) that leads into the next scene; Sel_PL
 * then runs each player's own state machine (Sel_PL_1st..6th). Per player: the lever moves the
 * cursor over the face grid (Sel_PL_Sub and the CR/CL/CU/CD moves, with auto-repeat and diagonal
 * handling), a button confirms the character and colour, and Sel_Arts_Sub picks one of three super
 * arts; each choice plays its sound and the character's voice. Demo lever data drives the screen in
 * attract mode. Correct_Control_Time takes time off the select timer after continues, Check_Boss
 * flags the boss break-in after the ninth opponent, and Setup_Battle_Country picks the stage from
 * the characters in play.
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
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Eff39.h"
#include "EFF44.h"
#include "Eff52.h"
#include "EFF70.h"
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
#include "sc_trans.h"
#include "EffD8.h"
#include "EFF69.h"
#include "next_cpu.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF38.h"
#include "EFF42.h"
#include "Eff50.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "EFF75_ORDER.h"
#include "Eff76.h"
#include "Eff79.h"
#include "EffK6.h"
#include "Grade.h"
#include "aboutspr.h"
#include "PLS02.h"
#include "Com_Pl.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sel_pl.h"
#include "fighter.h"

#pragma inline(Setup_BG)



s16 Select_Player(void) {
    SEL_PL_X = 0;
    if (Break_Into) {
        return 0;
    }
    Scene_Cut = Cut_Cut_Cut();
    Sel_PL_Control();
    ID = 0;
    Sel_PL();
    ID = 1;
    Sel_PL();
    Time_Over = 0;
    return SEL_PL_X;
}



void Sel_PL_Control(void) {
    void (*cont_tbl[4])() = { Sel_PL_Cont_1st, Sel_PL_Cont_2nd, Sel_PL_Cont_3rd, Sel_PL_Cont_4th };
    Setup_Select_Status();
    cont_tbl[S_No]();
    sel_pl_face_control();
    OBJ_Control();
    ID2 = 0;
    Player_Select_Control();
    ID2 = 1;
    Player_Select_Control();
    {
        void (*exit_tbl[7])() = { Exit_1st, Exit_2nd, Exit_3rd, Exit_4th, Exit_5th, Exit_6th, Exit_7th };
        exit_tbl[Exit_No]();
    }
}



void Sel_PL_Cont_1st(void) {
    s16 xx;
    if (Demo_Flag) {
        tilemap_fill_all(0, 32);
    } else {
        tilemap_print_string_attr(DE_X[0] + 14, Text_Page_Y + 23, 18, Sel_PL_Erase_msg);
    }
    S_No++;
    All_Clear_Suicide();
    Face_No[0] = 0;
    Face_No[1] = 0;
    SO_No[0] = 0;
    SO_No[1] = 0;
    Sel_Sub_No[0] = 0;
    Sel_Sub_No[1] = 0;
    Exit_No = 0;
    Fade_Flag = 0;
    for (xx = 0; xx < 4; xx++) {
        SP_No[0][xx] = 0;
        SP_No[1][xx] = 0;
    }
    System_all_clear_Wait();
    effect_work_quick_init();
    Setup_Aborigine();
    Initialize_BG();
    Setup_Cursor_Y();
    Select_Timer = 48;
    Unit_Of_Timer = 50;
    Setup_Face_ID();
    if (Play_Type == 1) {
        Play_Type_1st = 99;
    } else {
        Play_Type_1st = Aborigine;
    }
    Setup_Face_Sub();
    Time_Stop = 1;
    effect_A5_entry();
    Appear_Cursor = 0;
    Face_MV_Request = 0;
    Face_Status = 0;
    Face_Move = 0;
    Break_Into_CPU = 0;
    Explosion = 0;
    Time_Over = 0;
    Move_Super_Arts[0] = 0;
    Move_Super_Arts[1] = 0;
    Flash_Complete[0] = 0;
    Flash_Complete[1] = 0;
    Cursor_Move[0] = 0;
    Cursor_Move[1] = 0;
    effect_58_init(6, 20, 157);
    load_any_color(89);
}



void Sel_PL_Cont_2nd(void) {
    if (--Cover_Timer == 0) {
        S_No++;
        if (G_No1 == 1) {
            Request_E_No = 1;
        }
        Clear_Flash_No();
        commit_name_entry_row_both_players(Text_Page_Y);
        Scrn_Move_Set(4, 0, 0x100);
        Switch_Screen_Init(0, 1);
    }
}



void Sel_PL_Cont_3rd(void) {
    if (Switch_Screen_Revival()) {
        S_No++;
        Forbid_Break = 0;
        if (G_No1 == 1 || !Demo_Flag) {
            bgm_request(2);
            if (E_Number[0][0] != 2 && E_Number[1][0] != 2) {
                Ranking_00_6th(0);
            }
        }
    }
}



void Sel_PL_Cont_4th(void) {}void Initialize_BG(void)
{
    Setup_BG_General();
    Setup_BG_Layer0(0);
    Setup_BG_Layer2();
    Setup_FACE_BG();
    Setup_BG_Layer3();
}



void Setup_FACE_BG(void) {
    s16 face_x;
    s16 face_y;
    face_x = Setup_Face_X();
    face_y = Setup_Face_Y();
    bg_w.bgw[1].xy[0].disp.pos = face_x;
    bg_w.bgw[1].xy[1].disp.pos = face_y;
    bg_w.bgw[1].wxy[0].disp.pos = face_x;
    bg_w.bgw[1].wxy[1].disp.pos = face_y;
    bg_w.bgw[1].xy[0].disp.low = 0;
    bg_w.bgw[1].xy[1].disp.low = 0;
    bg_w.bgw[1].position_x = face_x;
    bg_w.bgw[1].position_y = face_y;
    bg_w.bgw[1].hos_xy[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos;
    Bg_Family_Set_Ex(1);
}



s16 Setup_Face_X(void) {
    if (Play_Type == 1) {
        return 604;
    }
    if (Aborigine == 0) {
        return 512;
    }
    return 696;
}



s16 Setup_Face_Y(void) {
    if (Play_Type == 1) {
        return 0;
    }
    if (Aborigine == 0) {
        return -24;
    }
    return 0;
}



void Setup_EFF69(void) {
    s16 xx;
    for (xx = 0; xx < 5; xx++) {
        Order[xx] = 0;
        effect_69_init(xx);
    }
}



void Setup_Face_Sub(void) {
    s16 i = 0;
    volatile s8* p = Face_Order_Data;

    Complete_Face = 19;
    do {
        effect_70_init(*p);
        i++;
        p++;
    } while (i < 19);
}



void Sel_PL(void) {
    void (*Sel_PL_Jmp_Tbl[6])() = { Sel_PL_1st, Sel_PL_2nd, Sel_PL_3rd, Sel_PL_4th, Sel_PL_5th, Sel_PL_6th };
    if (plw[ID].wu.operator != 0) {
        Sel_PL_Jmp_Tbl[SP_No[ID][0]]();
    }
}



void Sel_PL_1st(void) {
    u16 Rnd;
    if (Exit_No) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 1;
    Auto_No[ID] = 0;
    Auto_Index[ID] = 0;
    Auto_Cursor[ID] = 0;
    Moving_Plate[ID] = 0;
    Moving_Plate_Counter[ID] = 0;
    Select_Start[ID] = 2;
    Select_Arts[ID] = -1;
    if (ID == 1) {
        effect_D8_entry(1, 1);
        effect_D8_entry(1, 3);
        Rnd = random_16_com() & 3;
        Free_Ptr[1] = Voice_Random_Data[1][Rnd];
    } else {
        effect_D8_entry(0, 0);
        effect_D8_entry(0, 2);
        Rnd = random_16_com() & 3;
        Free_Ptr[0] = Voice_Random_Data[1][Rnd];
    }
    if (Sel_PL_Complete[ID]) {
        SP_No[ID][0] = 3;
        Select_Start[ID] = 3;
        Select_Arts[ID] = 3;
        Stop_Cursor[ID] = 1;
        paring_ctr_vs[0][ID] = 0;
        paring_ctr_vs[1][ID] = 0;
        return;
    }
    Arts_Y[ID] = Super_Arts[ID] = Last_Super_Arts[ID];
}



void Sel_PL_2nd(void) {
    if (Select_Start[ID]) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 0;
    Deley_Shot_No[ID] = 0;
    Cursor_Timer[ID] = 1;
    if (Demo_Flag == 0) {
        Demo_Ptr[ID] = (u16*)Demo_Lever_Data[Select_Demo_Index];
    }
}



void Sel_PL_3rd(void) {
    if (Stop_Cursor[ID] != 0 || ((u8)Face_Move) != 0) {
        return;
    }
    if (Demo_Flag == 0) {
        if (ID) {
            Sel_PL_Sub(1, *Demo_Ptr[1]);
        } else {
            Sel_PL_Sub(0, *Demo_Ptr[0]);
        }
        Demo_Ptr[ID]++;
    } else if (ID) {
        Sel_PL_Sub(1, Deley_Shot_Sub(1));
    } else {
        Sel_PL_Sub(0, Deley_Shot_Sub(0));
    }
    if (Sel_PL_Complete[ID] >= 0) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 1;
    Auto_No[ID] = 0;
    paring_ctr_vs[0][ID] = 0;
    paring_ctr_vs[1][ID] = 0;
    if (Continue_Coin[ID] == 0) {
        clear_chainex_check(ID);
        grade_check_work_1st_init(ID, 0);
        grade_check_work_1st_init(ID, 1);
        Initialize_EM_Candidate(ID);
        Best_Grade[ID] = -1;
        Result_Disp_Timer[ID] = 120;
        Request_Disp_Rank[ID][0] = -1;
        Request_Disp_Rank[ID][1] = -1;
        Request_Disp_Rank[ID][2] = -1;
        Request_Disp_Rank[ID][3] = -1;
    } else {
        Check_Same_CPU(ID);
    }
}



u32 Deley_Shot_Sub(s16 PL_id) {
    u16 sw;
    u16 lever;
    if (PL_id == 0) {
        sw = ~p1sw_1 & p1sw_0;
    } else {
        sw = ~p2sw_1 & p2sw_0;
    }
    lever = Disposal_Of_Diagonal(sw);
    sw = sw & 0x3F0;
    switch (Deley_Shot_No[PL_id]) {
    case 0:
        if (!(sw & 0x3F0)) {
            break;
        }
        if (sw == 0x150) {
            return lever | 0x150;
        }
        if (sw & 0x2A0) {
            return sw | lever;
        }
        Color7[PL_id] = sw;
        Deley_Shot_No[PL_id] = 1;
        Deley_Shot_Timer[PL_id] = 3;
        break;
    case 1:
        Color7[PL_id] = Color7[PL_id] | sw;
        if ((Deley_Shot_Timer[PL_id] -= 1) == 0) {
            return lever | Color7[PL_id];
        }
        if (Color7[PL_id] == 0x150) {
            return lever | 0x150;
        }
        break;
    }
    return lever;
}



void Sel_PL_4th(void) {
    if (!Select_Arts[ID]) {
        SP_No[ID][0]++;
        Stop_Cursor[ID] = 0;
        Arts_Cursor_No[ID] = 0;
        Arts_Cursor_Timer[ID] = 0;
    }
}



void Sel_PL_5th(void) {
    if (Stop_Cursor[ID] != 0 || ((u8)Face_Move) != 0) {
        return;
    }
    if (Demo_Flag == 0) {
        if (ID) {
            Sel_Arts_Sub(1, *Demo_Ptr[1], 0);
        } else {
            Sel_Arts_Sub(0, *Demo_Ptr[0], 0);
        }
        Demo_Ptr[ID]++;
    } else if (ID) {
        Sel_Arts_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
    } else {
        Sel_Arts_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
    }
    if (!Sel_Arts_Complete[ID]) {
        return;
    }
    SP_No[ID][0]++;
    if (plw[0].wu.operator == 0 || plw[1].wu.operator == 0) {
        Check_Boss(ID);
    }
}



void Sel_PL_6th(void) {}



s32 Disposal_Of_Diagonal(u32 sw_arg) {
    u16 sw = sw_arg;
    sw = sw & 0xF;
    if (sw == 1) {
        return 1;
    }
    if (sw == 2) {
        return 2;
    }
    if (sw == 9) {
        return 1;
    }
    if (sw == 6) {
        return 2;
    }
    return sw &= 0xC;
}



void Sel_PL_Sub(s32 PL_id_arg, u16 sw) {
    s16 PL_id = (s16)PL_id_arg;
    Cursor_Move[PL_id] = 0;
    if (Sel_PL_Complete[PL_id] != 0) {
        return;
    }
    if (Time_Over != 0) {
        sw = 16;
    }
    if (sw == 0) {
        Auto_Repeat_Sub(PL_id);
    }
    if ((Cursor_Timer[PL_id] -= 1) == 0) {
        Cursor_Timer[PL_id] = 1;
        if (sw & 8) {
            Cursor_Timer[PL_id] = 5;
            Sel_PL_Sub_CR(PL_id);
        } else if (sw & 4) {
            Cursor_Timer[PL_id] = 5;
            Sel_PL_Sub_CL(PL_id);
        } else if (sw & 1) {
            Cursor_Timer[PL_id] = 5;
            Sel_PL_Sub_CU(PL_id);
        } else if (sw & 2) {
            Cursor_Timer[PL_id] = 5;
            Sel_PL_Sub_CD(PL_id);
        }
    }
    if (Cursor_Move[PL_id] != 0) {
        Sound_SE(ID + 96);
    }
    if (!(sw & 0x3F0)) {
        return;
    }
    Sel_PL_Complete[PL_id] = 1;
    My_char[PL_id] = ID_of_Face[*(volatile s16*)&Cursor_Y[PL_id]][Cursor_X[PL_id]];
    if (Last_My_char2[PL_id] != My_char[PL_id]) {
        Arts_Y[ID] = Super_Arts[ID] = Last_Super_Arts[ID] = 0;
        Introduce_Boss[ID][0] = 0;
    }
    {
        s8 t = My_char[PL_id];
        Last_My_char2[PL_id] = t;
    }
    Last_Selected_ID = PL_id;
    Order[1] = 2;
    Order_Timer[1] = 1;
    Order_Dir[1] = 8;
    if (Select_Status[0] != 3) {
        Order[2] = 1;
        Order_Timer[2] = 10;
        Order_Dir[2] = 4;
    }
    Sound_SE(ID + 98);
    Sound_SE(*Free_Ptr[PL_id]++);
    Setup_PL_Color(PL_id, sw);
    Correct_Control_Time(PL_id);
}



void Sel_PL_Sub_CR(s16 PL_id) {
    Cursor_Move[PL_id] = 1;
    Cursor_Y[PL_id]++;
    switch (Cursor_X[PL_id]) {
    case 6:
        if (Cursor_Y[PL_id] > 1) {
            Cursor_Y[PL_id] = 1;
            Cursor_X[PL_id] = 0;
        }
        break;
    default:
        if (Cursor_Y[PL_id] > 2) {
            Cursor_Y[PL_id] = 0;
            Cursor_X[PL_id]++;
        }
        break;
    }
}



void Sel_PL_Sub_CL(s16 PL_id) {
    Cursor_Move[PL_id] = 1;
    Cursor_Y[PL_id]--;
    switch (Cursor_X[PL_id]) {
    case 0:
        if (Cursor_Y[PL_id] < 1) {
            Cursor_Y[PL_id] = 1;
            Cursor_X[PL_id] = 6;
        }
        break;
    case 1:
        if (Cursor_Y[PL_id] < 0) {
            Cursor_Y[PL_id] = 2;
            Cursor_X[PL_id] = 0;
        }
        break;
    default:
        if (Cursor_Y[PL_id] < 0) {
            Cursor_Y[PL_id] = 2;
            Cursor_X[PL_id]--;
        }
        break;
    }
}



void Sel_PL_Sub_CU(s16 PL_id) {
    Cursor_Move[PL_id] = 1;
    Cursor_X[PL_id]++;
    switch (Cursor_Y[PL_id]) {
    case 0:
        if (Cursor_X[PL_id] > 6) {
            Cursor_X[PL_id] = 1;
        }
        break;
    case 1:
        if (Cursor_X[PL_id] > 6) {
            Cursor_X[PL_id] = 0;
        }
        break;
    default:
        if (Cursor_X[PL_id] > 5) {
            Cursor_X[PL_id] = 0;
        }
        break;
    }
}



void Sel_PL_Sub_CD(s16 PL_id) {
    Cursor_Move[PL_id] = 1;
    Cursor_X[PL_id]--;
    switch (Cursor_Y[PL_id]) {
    case 0:
        if (Cursor_X[PL_id] < 1) {
            Cursor_X[PL_id] = 6;
        }
        break;
    case 1:
        if (Cursor_X[PL_id] < 0) {
            Cursor_X[PL_id] = 6;
        }
        break;
    default:
        if (Cursor_X[PL_id] < 0) {
            Cursor_X[PL_id] = 5;
        }
        break;
    }
}



void Auto_Repeat_Sub(s16 PL_id) {
    s32 sw;
    s16 raw;
    if (Demo_Flag == 0) {
        return;
    }
    if (Cursor_Move[PL_id] != 0) {
        return;
    }
    raw = (PL_id == 0) ? p1sw_0 : p2sw_0;
    sw = Disposal_Of_Diagonal(raw);
    switch (Auto_No[PL_id]) {
    case 0:
        if (sw & 8) {
            Auto_No[PL_id] = 1;
            Auto_Cursor[PL_id] = 8;
            Auto_Timer[PL_id] = Auto_Repeat_Data[0];
            Auto_Index[PL_id] = 1;
            break;
        }
        if (sw & 4) {
            Auto_No[PL_id] = 1;
            Auto_Cursor[PL_id] = 4;
            {
                s8 t = Auto_Repeat_Data[0];
                Auto_Timer[PL_id] = t;
            }
            Auto_Index[PL_id] = 1;
            break;
        }
        if (sw & 1) {
            Auto_No[PL_id] = 1;
            Auto_Cursor[PL_id] = 1;
            Auto_Timer[PL_id] = Auto_Repeat_Data[0];
            Auto_Index[PL_id] = 1;
            break;
        }
        if (sw & 2) {
            Auto_No[PL_id] = 1;
            Auto_Cursor[PL_id] = 2;
            Auto_Timer[PL_id] = Auto_Repeat_Data[0];
            Auto_Index[PL_id] = 1;
        }
        break;
    case 1:
        if (sw != Auto_Cursor[PL_id]) {
            Auto_No[PL_id] = 0;
            break;
        }
        if (Auto_Timer[PL_id] -= 1) {
            break;
        }
        {
            s8 t = Auto_Repeat_Data[Auto_Index[PL_id]];
            Auto_Timer[PL_id] = t;
        }
        Auto_Index[PL_id]++;
        if (Auto_Index[PL_id] > 2) {
            Auto_Index[PL_id] = 2;
        }
        if (sw & 8) {
            Sel_PL_Sub_CR(PL_id);
        }
        if (sw & 4) {
            Sel_PL_Sub_CL(PL_id);
        }
        if (sw & 1) {
            Sel_PL_Sub_CU(PL_id);
        }
        if (sw & 2) {
            Sel_PL_Sub_CD(PL_id);
        }
        break;
    }
}



s32 Auto_Repeat_Sub_Wife(s16 pl) {
    u16 sw;
    s8* cnt;
    if (Cursor_Move[pl] || !Demo_Flag) {
        return 0;
    }
    if (pl == 0) {
        sw = p1sw_0;
    } else {
        sw = p2sw_0;
    }
    switch (Auto_No[pl]) {
    case 0:
        if (sw & 1) {
            Auto_No[pl] = 1;
            Auto_Cursor[pl] = 1;
        } else if (sw & 2) {
            Auto_No[pl] = 1;
            Auto_Cursor[pl] = 2;
        } else {
            break;
        }
        Auto_Timer[pl] = Auto_Repeat_Wife_Data[0];
        Auto_Index[pl] = 1;
        break;
    case 1:
        if (sw &= Auto_Cursor[pl]) {
            if (--Auto_Timer[pl] == 0) {
                cnt = &Auto_Index[pl];
                Auto_Timer[pl] = Auto_Repeat_Wife_Data[(*cnt)++];
                if (*cnt > 2) {
                    Auto_Index[pl] = 2;
                }
                if (sw & 1) {
                    return 1;
                }
                if (sw & 2) {
                    return 2;
                }
            }
        } else {
            Auto_No[pl] = 0;
        }
        break;
    }
    return 0;
}



void Sel_Arts_Sub(PL_id, sw)
s16 PL_id;
u16 sw;
{
    u16 lever_sw;
    if (Sel_Arts_Complete[PL_id]) {
        return;
    }
    if (Moving_Plate_Counter[PL_id]) {
        return;
    }
    if (Moving_Plate[PL_id]) {
        return;
    }
    if (Plate_Disposal_No[PL_id][0] != 0 || Plate_Disposal_No[PL_id][1] != 0 || Plate_Disposal_No[PL_id][2] != 0) {
        return;
    }
    if (Time_Over) {
        sw = 16;
    }
    lever_sw = sw & 0xF;
    if (lever_sw == 0) {
        sw = sw | Auto_Repeat_Sub_Wife(PL_id);
    }
    if (sw & 2) {
        Sound_SE(ID + 96);
        Moving_Plate[PL_id] = 2;
        Moving_Plate_Counter[PL_id] = 3;
        OK_Priority[PL_id] = 0;
        if ((Arts_Y[PL_id] += 1) > 2) {
            Arts_Y[PL_id] = 0;
        }
    }
    if (sw & 1) {
        Sound_SE(ID + 96);
        Moving_Plate[PL_id] = 1;
        Moving_Plate_Counter[PL_id] = 3;
        OK_Priority[PL_id] = 0;
        if ((Arts_Y[PL_id] -= 1) < 0) {
            Arts_Y[PL_id] = 2;
        }
    }
    if (sw & 0xFF0) {
        Stop_Cursor[ID] = 1;
        Last_Arts_PL = PL_id;
        Sel_Arts_Complete[PL_id] = 1;
        Last_Super_Arts[PL_id] = Super_Arts[PL_id] = Arts_Y[PL_id];
        Sound_SE(ID + 98);
        Sound_SE(*Free_Ptr[PL_id]++);
        Setup_ID();
        if (Decided_My_char[PL_id] != My_char[PL_id]) {
            Last_Player_id = PL_id;
        }
        Decided_My_char[PL_id] = My_char[PL_id];
    }
}



void OBJ_Control(void) {
    void (*tbl[3])(void) = { OBJ_1st, OBJ_2nd, OBJ_3rd };

    tbl[SO_No[0]]();
}



void OBJ_1st(void) {
    load_char_gfx(0xA0F8, 1);
    Setup_EFF69();
    if (Select_Status[0] != 3) {
        SO_No[0] = 1;
        effect_38_init(Aborigine, Aborigine + 11, 127, 0, 2);
        Order[Aborigine + 11] = 1;
        Order_Timer[Aborigine + 11] = 35;
        effect_52_init(Aborigine, 37);
        Order[37] = 1;
        Order_Timer[37] = 30;
        Order_Dir[37] = 0;
        effect_K6_init(Aborigine, Aborigine + 31, 31, 2);
        Order[Aborigine + 31] = 1;
        Order_Timer[Aborigine + 31] = 35;
        Order_Dir[Aborigine + 31] = 0;
        effect_K6_init(Aborigine, Aborigine + 25, 25, 2);
        Order[Aborigine + 25] = 1;
        Order_Timer[Aborigine + 25] = 35;
        Order_Dir[Aborigine + 25] = 0;
        Order[0] = 1;
        Order_Timer[0] = 40;
        Order_Dir[0] = 4;
        Order[1] = 1;
        Order_Timer[1] = 45;
        Order_Dir[1] = 4;
        Order[3] = 1;
        Order_Timer[3] = 45;
        Order_Dir[3] = 4;
        effect_39_init(Aborigine, Aborigine + 13, 127, 2, 1);
        Order[Aborigine + 13] = 1;
        Order_Timer[Aborigine + 13] = 35;
        Order_Dir[Aborigine + 13] = 0;
        effect_42_init(5);
        Order[5] = 1;
        Order_Timer[5] = 45;
        Order_Dir[5] = 4;
        effect_42_init(6);
        Order[6] = 1;
        Order_Timer[6] = 45;
        Order_Dir[6] = 4;
    } else {
        *SO_No = 2;
        effect_75_init(42, 3, 2);
        Order[42] = 3;
        Order_Timer[42] = 1;
        Order_Dir[42] = 3;
        effect_38_init(0, 11, 127, 1, 2);
        Order[11] = 1;
        Order_Timer[11] = 86;
        effect_38_init(1, 12, 127, 1, 2);
        Order[12] = 1;
        Order_Timer[12] = 86;
        effect_K6_init(0, 33, 31, 2);
        Order[33] = 1;
        Order_Timer[33] = 86;
        Order_Dir[33] = 0;
        effect_52_init(0, 38);
        Order[38] = 3;
        Order_Timer[38] = 30;
        effect_K6_init(0, 27, 25, 2);
        Order[27] = 3;
        Order_Timer[27] = 86;
        effect_K6_init(1, 28, 25, 2);
        Order[28] = 3;
        Order_Timer[28] = 86;
        effect_K6_init(1, 34, 31, 2);
        Order[34] = 1;
        Order_Timer[34] = 86;
        Order_Dir[34] = 0;
        effect_52_init(1, 39);
        Order[39] = 3;
        Order_Timer[39] = 30;
        effect_39_init(0, 15, 127, 2, 0);
        Order[15] = 1;
        Order_Timer[15] = 86;
        Order_Dir[15] = 0;
        effect_39_init(1, 16, 127, 2, 0);
        Order[16] = 1;
        Order_Timer[16] = 86;
        Order_Dir[16] = 0;
        Order[4] = 3;
        Order_Timer[4] = 86;
        Order_Dir[4] = 255;
        effect_42_init(7);
        Order[7] = 0;
        Order_Timer[7] = 86;
        effect_42_init(8);
        Order[8] = 0;
        Order_Timer[8] = 86;
    }
}



void OBJ_2nd(void) {
    if (Select_Status[0] != 3) {
        return;
    }
    SO_No[0]++;
    effect_75_init(42, 3, 2);
    Order[42] = 3;
    Order_Timer[42] = 1;
    Order_Dir[42] = 3;
    Order[Aborigine + 11] = 4;
    Order_Timer[Aborigine + 11] = 1;
    Select_Start[Aborigine] = 2;
    effect_38_init(New_Challenger, New_Challenger + 11, 127, 1, 2);
    Order[New_Challenger + 11] = 1;
    Order_Timer[New_Challenger + 11] = 1;
    Go_Away_Red_Lines();
    Order[Aborigine + 31] = 5;
    Order_Timer[Aborigine + 31] = 1;
    Order[Aborigine + 19] = 5;
    Order_Timer[Aborigine + 19] = 1;
    Order[Aborigine + 25] = 5;
    Order_Timer[Aborigine + 25] = 1;
    Order[Aborigine + 13] = 5;
    Order_Timer[Aborigine + 13] = 1;
    Order[37] = 4;
    Order_Timer[37] = 1;
    effect_K6_init(0, 33, 31, 2);
    Order[33] = 1;
    Order_Timer[33] = 1;
    Order_Dir[33] = 0;
    effect_K6_init(0, 27, 25, 2);
    Order[27] = 1;
    Order_Timer[27] = 1;
    Order_Dir[27] = 0;
    effect_39_init(0, 15, 127, 2, 0);
    Order[15] = 1;
    Order_Timer[15] = 1;
    Order_Dir[15] = 0;
    effect_K6_init(1, 34, 31, 2);
    Order[34] = 1;
    Order_Timer[34] = 1;
    Order_Dir[34] = 0;
    effect_K6_init(1, 28, 25, 2);
    Order[28] = 1;
    Order_Timer[28] = 1;
    Order_Dir[28] = 0;
    effect_39_init(1, 16, 127, 2, 0);
    Order[16] = 1;
    Order_Timer[16] = 1;
    Order_Dir[16] = 0;
    Order[4] = 3;
    Order_Timer[4] = 1;
    Order_Dir[4] = 255;
    effect_42_init(7);
    Order[7] = 0;
    Order_Timer[7] = 1;
    effect_42_init(8);
    Order[8] = 0;
    Order_Timer[8] = 1;
}



void OBJ_3rd(void) {}



void sel_pl_face_control(void) {
    void (*Face_Tbl[4])() = { Face_1st, Face_2nd, Face_3rd, Face_4th };
    Face_Tbl[Face_No[0]]();
    Move_Face_BG();
}



void Face_1st(void) {
    if (Select_Status[0] == 3) {
        Face_No[0] = 3;
    } else {
        Face_No[0] = 1;
    }
    Appear_Cursor = 1;
}



void Face_2nd(void) {
    if (Select_Status[0] == 3 && Face_MV_Request == 0) {
        Face_No[0] = 3;
        Face_MV_Time = 1;
        if (Aborigine == 1) {
            Face_MV_Request = 2;
            bg_mvxy.a[0].sp = -0x90000;
            bg_mvxy.d[0].sp = -0x8000;
        } else {
            Face_MV_Request = 1;
            bg_mvxy.a[0].sp = 0x90000;
            bg_mvxy.d[0].sp = 0x8000;
        }
    } else if (Sel_PL_Complete[Aborigine]) {
        Face_MV_Time = 5;
        Face_No[0]++;
        if (Aborigine == 0) {
            Face_MV_Request = 4;
            bg_mvxy.a[0].sp = -0xC0000;
            bg_mvxy.d[0].sp = -0x8000;
        } else {
            Face_MV_Request = 3;
            bg_mvxy.a[0].sp = 0xC0000;
            bg_mvxy.d[0].sp = 0x8000;
        }
    }
}



void Face_3rd(void) {
    if (Select_Status[0] == 3 && Face_MV_Request == 0) {
        Face_No[0]++;
        Face_MV_Time = 1;
        if (Aborigine == 1) {
            Face_MV_Request = 2;
            bg_mvxy.a[0].sp = -0xC0000;
            bg_mvxy.d[0].sp = -0x8000;
        } else {
            Face_MV_Request = 1;
            bg_mvxy.a[0].sp = 0xC0000;
            bg_mvxy.d[0].sp = 0x8000;
        }
    }
}



void Face_4th(void) {}



void Move_Face_BG(void) {
    switch (Face_No[1]) {
    case 0:
        if (Face_MV_Request) {
            Face_No[1]++;
            Face_Move = Face_MV_Request;
            effect_93_init(((u8)Face_Move) - 1, Face_MV_Time);
        }
        break;
    default:
        if (!(Face_MV_Request = ((u8)Face_Move))) {
            Face_No[1] = 0;
        }
        break;
    }
}



/* provisional name */
void Player_Select_Control(void) {
    void (*Obj_Tbl[5])() = { PL_Sel_Begin, PL_Sel_2nd, PL_Sel_3rd, PL_Sel_4th, PL_Sel_5th };

    if (plw[ID2].wu.operator != 0) {
        Obj_Tbl[SP_No[ID2][1]]();
    }
}



/* provisional name */
void PL_Sel_Begin(void) {
    if (Sel_PL_Complete[ID2] == -0x8000) {
        SP_No[ID2][1] = 2;
        Sel_Arts_Complete[ID2] = 0;
        sel_pl_disp_char_effect_trio(ID2, 0x55);
        effect_50_init(ID2, 1, 0);
        effect_50_init(ID2, 1, 1);
        effect_50_init(ID2, 2, 0);
        effect_50_init(ID2, 2, 1);
        return;
    }
    SP_No[ID2][1]++;
}


/* provisional name */
s32 PL_Sel_Mode_1(void) {
    if (ID2 == 0) {
        return 8;
    }
    return 4;
}


/* provisional name */
s32 PL_Sel_Mode_2(void) {
    if (ID2 == 0) {
        return 4;
    }
    return 8;
}



void PL_Sel_2nd(void) {
    if (Sel_PL_Complete[ID2]) {
        SP_No[ID2][1]++;
        sel_pl_disp_char_effect_trio(ID2, 1);
        effect_50_init(ID2, 1, 0);
        effect_50_init(ID2, 1, 1);
        effect_50_init(ID2, 2, 0);
        effect_50_init(ID2, 2, 1);
    }
}



void PL_Sel_3rd(void) {
    if (Sel_Arts_Complete[ID2] < 0) {
        SP_No[ID2][1]++;
    }
}



void PL_Sel_4th(void) {}



void sel_pl_disp_char_effect_trio(s8 PL_id, s16 Time) {
    Move_Super_Arts[PL_id] = 3;
    Select_Arts[PL_id] = 3;
    effect_79_init(PL_id, 0, Setup_Aborigine_table[Super_Arts[PL_id]][0], Time, 2);
    effect_79_init(PL_id, 1, Setup_Aborigine_table[Super_Arts[PL_id]][1], Time, 2);
    effect_79_init(PL_id, 2, Setup_Aborigine_table[Super_Arts[PL_id]][2], Time, 2);
}



void PL_Sel_5th(void) {}



void Setup_Select_Status(void) {
    if (plw[0].wu.operator) {
        Select_Status[0] = 1;
    } else {
        Select_Status[0] = 0;
    }
    if (plw[1].wu.operator) {
        Select_Status[0] |= 2;
    }
    if (Sel_Arts_Complete[0] != -1 && plw[0].wu.operator != 0) {
        Select_Status[1] = 1;
    } else {
        Select_Status[1] = 0;
    }
    if (Sel_Arts_Complete[1] != -1 && plw[1].wu.operator != 0) {
        Select_Status[1] |= 2;
    }
}



u8 Setup_Aborigine(void) {
    if (Select_Status[0] == 3) {
        return Aborigine = 153;
    }
    if (Select_Status[0] == 1) {
        return Aborigine = 0;
    }
    return Aborigine = 1;
}



void Basic_Sub(void) {
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(3);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(2);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(3);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(2);
}



void Basic_Sub_Ex(void) {
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
}



/* provisional name */
void Setup_BG_General(void) {
    Zoomf_Init();
    bg_etc_write(6);
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void Setup_BG_Layer0(s16 y) {
    bg_w.bgw[0].xy[0].disp.pos = 0x200;
    bg_w.bgw[0].xy[1].disp.pos = y;
    bg_w.bgw[0].wxy[0].disp.pos = 0x200;
    bg_w.bgw[0].wxy[1].disp.pos = y;
    bg_w.bgw[0].xy[0].disp.low = 0;
    bg_w.bgw[0].xy[1].disp.low = 0;
    bg_w.bgw[0].position_x = 0x200;
    bg_w.bgw[0].position_y = y;
    Bg_Family_Set_Ex(0);
}

static void Setup_BG(s16 BG_INDEX, s32 X, s32 Y) {
    bg_w.bgw[BG_INDEX].xy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].xy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].wxy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].wxy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].xy[0].disp.low = 0;
    bg_w.bgw[BG_INDEX].xy[1].disp.low = 0;
    bg_w.bgw[BG_INDEX].position_x = X;
    bg_w.bgw[BG_INDEX].position_y = Y;
}



/* provisional name */
void Setup_BG_Layer2(void) {
    Setup_BG(2, 512, 0);
    Bg_Family_Set_Ex(2);
}



/* provisional name */
void Setup_BG_Layer3(void) {
    Setup_BG(3, 704, 0);
    Bg_Family_Set_Ex(3);
}



void Setup_Cursor_Y(void) {
    s16 i;
    s16 j;
    s32 p;

    p = (s32)Cursor_Y_Pos;
    for (i = 2, j = 0; i >= 0; i--, j++) {
        *(s16*)(p + i * 2) = Cursor_Y_Data[j];
    }
    p = (s32)Cursor_Y_Pos;
    for (i = 2, j = 3; i >= 0; i--, j++) {
        *(s16*)(p + i * 2 + 6) = Cursor_Y_Data[j];
    }
}



void Setup_ID(void) {
    if (Operator_Status[0] == 0) {
        COM_id = 0;
        Player_id = 1;
    } else {
        COM_id = 1;
        Player_id = 0;
    }
}



void Go_Away_Red_Lines(void) {
    Order[0] = 2;
    Order_Timer[0] = 1;
    Order_Dir[0] = 8;
    Order[2] = 2;
    Order_Timer[2] = 1;
    Order_Dir[2] = 8;
    Order[1] = 2;
    Order_Timer[1] = 1;
    Order_Dir[1] = 8;
    Order[3] = 2;
    Order_Timer[3] = 1;
    Order_Dir[3] = 8;
    Order[5] = 2;
    Order[6] = 2;
    Order_Timer[5] = 1;
    Order_Timer[6] = 1;
    Order_Dir[5] = 8;
    Order_Dir[6] = 8;
}



/* provisional name */
void Check_Exit(void) {
    void (*Exit_Tbl[7])(void) = { Exit_1st, Exit_2nd, Exit_3rd, Exit_4th, Exit_5th, Exit_6th, Exit_7th };

    Exit_Tbl[Exit_No]();
}

void Exit_1st(void) {
    if (plw[0].wu.operator && Sel_Arts_Complete[0] >= 0) {
        return;
    }
    if (plw[1].wu.operator != 0 && Sel_Arts_Complete[1] >= 0) {
        return;
    }
    Go_Away_Red_Lines();
    Order[4] = 4;
    Order_Timer[4] = 1;
    Order[7] = 4;
    Order[8] = 4;
    Order_Timer[7] = 1;
    Order_Timer[8] = 1;
    Exit_No++;
    if (Demo_Flag) {
        E_No0 = 3;
        E_No1 = 0;
        E_No2 = 0;
        E_No3 = 0;
    }
}



void Exit_2nd(void) {
    s16 xx;
    Sel_Exit_Flag = 0;
    S_Sub_No = 0;
    if (Select_Status[0] == 3) {
        Exit_No = 3;
        Battle_Country = Setup_Battle_Country();
        bg_w.stage = Battle_Country;
        bg_w.area = 0;
    } else {
        if ((s8)Scene_Cut) {
            Exit_Timer = 1;
        } else {
            Exit_Timer = 60;
        }
        Exit_No++;
        Last_My_char[Player_id] = My_char[Player_id];
        Time_Stop = 2;
        for (xx = 0; xx < 4; xx++) {
            SC_No[xx] = 0;
        }
    }
}



void Exit_3rd(void) {
    if (Select_CPU_First()) {
        Exit_No++;
        S_Sub_No = 0;
        if (VS_Index[Player_id] >= 9) {
            EM_Rank = 1;
        } else {
            EM_Rank = 0;
        }
    }
}



void Exit_4th(void) {
    if (Request_Fade(65, 0)) {
        Exit_No++;
        Forbid_Break = 0;
        Suicide[0] = 1;
        bgm_request(3);
        Exit_Timer = 180;
        effect_58_init(17, 2, 0);
        if (Select_Status[0] != 3) {
            effect_K6_init(0, 35, 35, 2);
            Order[35] = 3;
            Order_Timer[35] = 1;
            effect_K6_init(1, 36, 35, 2);
            Order[36] = 3;
            Order_Timer[36] = 1;
            effect_39_init(0, 17, My_char[0], 2, 0);
            Order[17] = 3;
            Order_Timer[17] = 1;
            effect_39_init(1, 18, My_char[1], 2, 0);
            Order[18] = 3;
            Order_Timer[18] = 1;
            effect_K6_init(0, 29, 29, 2);
            Order[29] = 3;
            Order_Timer[29] = 1;
            effect_K6_init(1, 30, 29, 2);
            Order[30] = 3;
            Order_Timer[30] = 1;
        } else if (Win_Record[Champion]) {
            effect_76_init(72);
            Order[72] = 3;
            Order_Timer[72] = 1;
            effect_76_init(73);
            Order[73] = 3;
            Order_Timer[73] = 1;
        }
        effect_43_init(2, 2);
        Order[42] = 2;
        Order_Timer[42] = 1;
        Order_Dir[42] = 5;
    }
}



void Exit_5th(void) {
    Exit_Timer--;
    if (!Check_Fade_Complete_SP()) {
        return;
    }
    Exit_No++;
    if (Exit_Timer < 0) {
        Exit_Timer = 1;
    }
}

void Exit_6th(void) {
    if (Scene_Cut) {
        Exit_Timer = 1;
    }
    if (--Exit_Timer == 0) {
        Exit_No++;
    }
}



void Exit_7th(void) {
    bg_w.stage = Battle_Country;
    bg_w.area = 0;
    SEL_PL_X = 1;
}



void Setup_Face_ID(void) {
    s16 i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            (&ID_of_Face[i][0])[j] = Face_Cursor_Data[i][j];
        }
    }
}



void Correct_Control_Time(s16 PL_id) {
    u8 xx;
    u8 zz;
    if (Play_Type == 1) {
        return;
    }
    if (Stage_Continue[PL_id] == 0) {
        return;
    }
    xx = Stage_Continue[PL_id];
    if (VS_Index[PL_id] >= 9) {
        zz = 1;
    } else {
        zz = 0;
    }
    if (Stage_Continue[PL_id] >= 16) {
        xx = 16;
    } else {
        xx = Stage_Continue[PL_id];
    }
    Control_Time = SC_Personal_Time[PL_id] - Continue_Time_Data[zz][xx];
    if (Control_Time < 0) {
        Control_Time = 0;
    }
    SC_Personal_Time[PL_id] = Control_Time;
}



s32 Check_Boss(s16 PL_id) {
    if (VS_Index[Player_id] >= 9) {
        if (Introduce_Boss[Player_id][1] == 0) {
            Control_Time = Limit_Time;
            SC_Personal_Time[PL_id] = Control_Time;
            return Break_Into_CPU = 1;
        }
    }
    return Break_Into_CPU = 0;
}


/* provisional name */
void Setup_Play_Type_1st(void) {
    if (Play_Type == 1) {
        Play_Type_1st = 99;
    } else {
        Play_Type_1st = Aborigine;
    }
}



s32 Setup_Battle_Country(void) {
    s16 ix;

    if (My_char[0] == PL_Q && My_char[1] == PL_Q) {
        ix = random_16_com() & 1;
        ix += random_16_com() & 1;
        {
            s16 rnd = random_16_com();
            return Battle_Country_Data[ix + rnd];
        }
    }
    {
        u8* pl = &My_char[New_Challenger];
        if (*pl == PL_Q) {
            return My_char[Champion];
        }
        return *pl;
    }
}

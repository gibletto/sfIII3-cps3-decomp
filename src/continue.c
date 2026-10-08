/*
 * CONTINUE.C  Continue scene
 *
 * Continue_Scene runs the continue countdown, with Setup_Continue_OBJ, Check_Exit_Continue and
 * Check_Count_Cut deciding when it ends and Check_Coin_In reading coin input. Disp_Personal_Count,
 * Clear_Personal_Data and Clear_Win_Type are small helpers for win-type marks and the player
 * number display.
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
#include "win_2.h"
#include "continue.h"
#include "fighter.h"



s32 Continue_Scene(void) {
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
    if (Cont_Timer = Check_Exit_Continue()) {
        Cont_No++;
    }
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
    s16* p;
    s8 id;
    if (E_Number[0][0] == 2 || E_Number[1][0] == 2) {
        return 0;
    }
    id = LOSER;
    p = E_Number[id ^ 1];
    if (p[0] == 0) {
        return 60;
    }
    if (p[0] != 3 && p[0] != 0) {
        return 0;
    }
    if (E_Number[id][0] != 3 && E_Number[id][0] != 0) {
        return 0;
    }
    return 1;
}

void Disp_Personal_Count(s16 id, char count) {
    tilemap_print_hex_block(DE_X[Entry_Mes_Wide[id]] + Entry_Mes_X[id] + 14, Text_Page_Y, 18, count, 1, 1);
}



s32 Check_Count_Cut(s16 PL_id, s16 Limit) {
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
    } else {
        Cursor_X[1] = 5;
        Cursor_Y[1] = 2;
    }
    for (xx = 0; xx < 10; xx++) {
        EM_History[PL_id][xx] = 0;
    }
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
    s32 sw1 = coin_chute1_w.dropped;
    s32 sw2 = coin_chute2_w.dropped;
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

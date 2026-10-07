/*
 * CONTINUE.C  Game-over, continue and short ending scenes
 *
 * Game_Over runs the game-over and result screens (GameOver_2nd, GameOver_3rd, Setup_Result_OBJ);
 * Continue_Scene the continue countdown, with Setup_Continue_OBJ, Check_Exit_Continue and
 * Check_Count_Cut deciding when it ends and Check_Coin_In reading coin input; Short_Ending_Scene the
 * short ending used in one region. cal_damage_vitality and cal_damage_vitality_eff turn an attack's
 * power into damage using the round-level rate tables and the players' attack/defence multipliers;
 * Disp_Personal_Count, Clear_Personal_Data, Clear_Win_Type, Disp_Player_Score and Score_Sub are
 * small helpers for win-type marks and player number and score display.
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
            break;
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
        if (Check_Fade_Complete_SP()) {
            Forbid_Break = 0;
            bgm_request(47);
            Ignore_Entry[LOSER] = 0;
            if (E_Number[0][0] != 2 && E_Number[1][0] != 2) {
                GO_No[1] += 2;
                G_Timer = 60;
                break;
            }
            GO_No[1]++;
        }
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

void Disp_Personal_Count(s16 id, char count) {
    tilemap_print_hex_block(DE_X[Entry_Mes_Wide[id]] + Entry_Mes_X[id] + 14, Text_Page_Y, 18, count, 1, 1);
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



void cal_damage_vitality(PLW* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    s32 d;
    if (as->player_number == PL_GOUKI2) {
        yy = Damage_Rate_Data[1][Round_Level];
    } else {
        yy = Damage_Rate_Data[0][Round_Level];
    }
    ds->wu.dm_vital = power * yy / 100;
    d = 8;
    if (as->wu.work_id == 1) {
        ds->wu.dm_vital = ds->wu.dm_vital * as->att_plus / d;
    }
    if (ds->wu.work_id == 1) {
        ds->wu.dm_vital = ds->wu.dm_vital * ds->def_plus / d;
    }
}



void cal_damage_vitality_eff(WORK_Other* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    s32 d;
    if (((PLW*)as)->player_number == PL_GOUKI2) {
        yy = Damage_Rate_Data[1][Round_Level];
    } else {
        yy = Damage_Rate_Data[0][Round_Level];
    }
    ds->wu.dm_vital = power * yy / 100;
    d = 8;
    if (as->wu.work_id == 1) {
        ds->wu.dm_vital = ds->wu.dm_vital * ((PLW*)as)->att_plus / d;
    }
    if (ds->wu.work_id == 1) {
        ds->wu.dm_vital = ds->wu.dm_vital * ds->def_plus / d;
    }
}

void Additinal_Score_DM(WORK_Other* wk, u32 ix) {
    s16 id;
    u8 pl;
    if (wk->wu.work_id == 1) {
        id = wk->wu.id;
    } else {
        if (((WORK*)wk->my_master)->work_id != 1) {
            return;
        }
        id = wk->master_id;
    }
    pl = id;
    Score[pl][2] += Score_Data[ix & 0xFFFF];
    if (plw[id].wu.operator) {
        if (!Play_Type) {
            Score[pl][0] += Score_Data[ix & 0xFFFF];
            if (Score[pl][0] >= 99999900) {
                Score[pl][0] = 99999900;
            }
        } else {
            Score[pl][1] += Score_Data[ix & 0xFFFF];
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
        if (top < 0) {
            if (digit[i]) {
                top = i;
            }
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
        tilemap_clear_rect(Score_X_Pos_Data[0][Game_setting.mode] - 7, 0, Score_X_Pos_Data[0][Game_setting.mode], 1);
        Disp_Player_Score(0);
        num = Continue_Coin[0];
        tens = num / 10;
        score8x16_put(Score_X_Pos_Data[0][Game_setting.mode] - 1, 0, 16, tens);
        score8x16_put(Score_X_Pos_Data[0][Game_setting.mode], 0, 16, num - tens * 10);
    }
    if (plw[1].wu.operator != 0 && Demo_Flag != 0) {
        tilemap_clear_rect(Score_X_Pos_Data[1][Game_setting.mode] - 7, 0, Score_X_Pos_Data[1][Game_setting.mode], 1);
        Disp_Player_Score(1);
        num = Continue_Coin[1];
        tens = num / 10;
        score8x16_put(Score_X_Pos_Data[1][Game_setting.mode] - 1, 0, 16, tens);
        score8x16_put(Score_X_Pos_Data[1][Game_setting.mode], 0, 16, num - tens * 10);
    }
}

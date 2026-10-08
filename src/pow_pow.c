/*
 * POW_POW.C  Damage and score
 *
 * cal_damage_vitality and cal_damage_vitality_eff turn an attack's power into damage using the
 * round-level rate tables and the players' attack/defence multipliers; Additinal_Score_DM,
 * Disp_Player_Score and Score_Sub add to and display the players' scores.
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
#include "pow_pow.h"
#include "fighter.h"



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
    if (plw[id].wu.operator != 0) {
        if (!Play_Type) {
            Score[pl][0] += Score_Data[ix & 0xFFFF];
            if (Score[pl][0] >= 99999900) {
                Score[pl][0] = 99999900;
            }
        } else {
            Score[pl][1] = Score[pl][1] + Score_Data[ix & 0xFFFF];
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
    if (plw[0].wu.operator != 0) {
        if (Demo_Flag != 0) {
            tilemap_clear_rect(Score_X_Pos_Data[0][Game_setting.mode] - 7, 0, Score_X_Pos_Data[0][Game_setting.mode], 1);
            Disp_Player_Score(0);
            num = Continue_Coin[0];
            tens = num / 10;
            score8x16_put(Score_X_Pos_Data[0][Game_setting.mode] - 1, 0, 16, tens);
            score8x16_put(Score_X_Pos_Data[0][Game_setting.mode], 0, 16, num - tens * 10);
        }
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

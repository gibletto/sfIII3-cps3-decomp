/*
 * COM_SUB.C  Computer player: pattern step library and decision helpers
 *
 * The building blocks used by every CPU pattern. Pattern steps: End_Pattern, Lever_On/Off,
 * Walk, Approach_Walk, Keep_Away, Wait, Look, Forced_Guard, Normal_Attack, Lever_Attack,
 * Jump_Attack, Hi_Jump_Attack, Command_Attack, Rapid_Command_Attack, SA_Term and the other
 * *_Term steps that attack when range and state conditions are met.
 * Checks and helpers: Ck_Distance, Ck_Area and the Check_* tests on the opponent, combo
 * speed and reaction time selection, Select_Active / Select_Passive / Decide_Follow_Menu
 * that pick the next pattern, and projectile handling (Check_Shell, Decide_Shell_Guard,
 * Guard_or_Jump_VS_Shell).
 * Exit_Term_* and ETC_Term_* are the term routines tested by patterns to end or branch.
 * Called from the pattern modules (ACTIVE*, Passive*, FOLLOW*) and Com_Pl.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "Ck_Pass.h"
#include "PLS03ATT.h"
#include "PLS02.h"
#include "CMD_MAIN.h"
#include "HITCHECK.h"
#include "EFFECT.h"
#include "Com_Sub.h"
#include "fighter.h"



void End_Pattern(void) { Next_Be_Free(); }



void Next_Be_Passive(void) { Next_Be_Free(); }



void Turn_Over_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    Turn_Over[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
}



void Only_Shot(wk, Lever_Data)
PLW* wk;
s16 Lever_Data;
{
    Lever_Buff[wk->wu.id] = Lever_Data;
    CP_Index[wk->wu.id][0]++;
}



void Lever_On(wk, LR_Lever, UD_Lever)
PLW* wk;
u16 LR_Lever;
u16 UD_Lever;
{
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    if ((LR_Lever == 0) || (LR_Lever == 1)) {
        Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, LR_Lever);
    } else {
        Lever_LR[wk->wu.id] = 0;
    }
    Lever_LR[wk->wu.id] |= UD_Lever;
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
}



void Lever_Off(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    Lever_LR[wk->wu.id] = 0;
}



void Pierce_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
}



/* provisional name */
void Pierce_Off(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 0;
    Disposal_Again[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* provisional name: a second copy of Pierce_Off */
void Pierce_Off_2(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 0;
    Disposal_Again[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
}



void Setup_DENJIN_LEVEL(PLW* wk) {
    u16 xx;
    Disposal_Again[wk->wu.id] = 1;
    if ((xx = DENJIN_No[wk->wu.id])) {
        Next_Another_Menu(wk, 2, xx);
    } else {
        Next_Another_Menu(wk, 2, Denjin_Data[Area_Number[wk->wu.id]][random_16_com()]);
    }
}



void Push_Shot(wk, Power_Level)
PLW* wk;
s16 Power_Level;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            if ((wk->wu.now_koc == 8) && (wk->wu.char_index == 0xD)) {
                xx = wk->wu.cg_ix / wk->wu.cgd_type;
                if (xx >= Power_Level) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
            if (Check_Exit_DENJIN(wk) != 0) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }
        break;
    case 1:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Exit_DENJIN(wk) != 0) {
            CP_Index[wk->wu.id][1] = 0x63;
        }
    default:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, 8, Power_Level);
        }
        break;
    }
}



s32 Check_Exit_DENJIN(PLW* wk) {
    s16 xx;
    WORK* em;
    if (!(DENJIN_Term[wk->wu.id] & 1)) {
        if (CP_Index[wk->wu.id][1] == 0) {
            return 0;
        }
    }
    if ((DENJIN_Term[wk->wu.id] & 8)) {
        if (Attack_Flag[wk->wu.id]) {
            return 1;
        }
    }
    em = (WORK*)wk->wu.target_adrs;
    xx = 0;
    if ((em->xyz[0].disp.pos) != (em->old_pos[0])) {
        if (Check_Attack_Direction(wk, em) != 0) {
            xx = -1;
        } else {
            xx = 1;
        }
    }
    if ((DENJIN_Term[wk->wu.id] & 1) && (em->xyz[0].disp.pos != 0)) {
        if (CP_Index[wk->wu.id][2] == 0) {
            CP_Index[wk->wu.id][2]++;
            CP_Index[wk->wu.id][3] = Area_Number[wk->wu.id];
        }
        switch (CP_Index[wk->wu.id][3]) {
        case 0:
        case 1:
        case 2:
            if (em->mvxy.a[1].real.h > 0) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos <= 0x28) {
                    return 1;
                }
            }
            break;
        default:
            if ((em->mvxy.a[1].real.h > 0) && (xx == -1)) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos <= 0x28) {
                    return 1;
                }
            }
            break;
        }
    }
    if (xx == 0) {
        return 0;
    }
    if ((DENJIN_Term[wk->wu.id] & 2) && (xx == 1)) {
        return 1;
    }
    if ((DENJIN_Term[wk->wu.id] & 4) && (xx == -1)) {
        return 1;
    }
    if ((DENJIN_Term[wk->wu.id] & 0x20) && (Lie_Flag[wk->wu.id] == 0)) {
        return 1;
    }
    return 0;
}



void Keep_Away(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    switch (CP_Index[wk->wu.id][3]) {
    case 0:
        if (Option == 0) {
            if (random_16_com() < 4) {
                Setup_KA_Jump(wk);
            } else {
                Setup_KA_Walk(wk);
            }
        } else {
            if (Option == 1) {
                Setup_KA_Jump(wk);
            } else {
                CP_Index[wk->wu.id][3] = Option + 1;
            }
        }
    case 1:
    case 2:
        Jump(wk, CP_Index[wk->wu.id][3] - 1);
        break;
    case 3:
    case 4:
        Approach_Walk(wk, Target_Pos, CP_Index[wk->wu.id][3] - 1);
        break;
    }
}



void Setup_KA_Jump(PLW* wk) {
    s16 xx;
    CP_Index[wk->wu.id][3] = 2;
    xx = KA_Jump_Data[wk->player_number];
    if (wk->wu.rl_waza) {
        xx = wk->wu.xyz[0].disp.pos - KA_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    } else {
        xx = wk->wu.xyz[0].disp.pos + KA_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].r_limit2 + bg_w.pos_offset) < xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    }
}



void Setup_KA_Walk(PLW* wk) {
    CP_Index[wk->wu.id][3] = 4;
}



void Search_Back_Term(wk, Move_Value, Next_Action, Next_Menu)
PLW* wk;
s16 Move_Value;
s16 Next_Action;
s16 Next_Menu;
{
    if (wk->wu.rl_waza) {
        Move_Value = wk->wu.xyz[0].disp.pos - Move_Value;
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > Move_Value) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    } else {
        Move_Value = wk->wu.xyz[0].disp.pos + Move_Value;
        if (((bg_w.bgw[1].r_limit2) + (bg_w.pos_offset)) < (Move_Value)) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



void Approach_Walk(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0x78;
    case 1:
        xx = Standing_Timer[wk->wu.id];
        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }
        Standing_Timer[wk->wu.id] = xx;
        if (--Timer_00[wk->wu.id] == 0) {
            Next_Be_Free(wk);
        }
        else if (Check_Arrival(wk, Target_Pos, Option) != 0) {
            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            Ck_Distance_Lv(wk);
            if (Option == 3) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
    }
}



s32 Check_Arrival(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    if (Option == 3) {
        if (Target_Pos <= PL_Distance[wk->wu.id]) {
            return 1;
        }
        return wk->micchaku_flag;
    }
    if (wk->hos_em_flag) {
        return 1;
    }
    if (Target_Pos >= PL_Distance[wk->wu.id]) {
        return 1;
    }
    return 0;
}



/* provisional name */
void Approach_Until_Landed(wk, Target_Pos)
PLW* wk;
s16 Target_Pos;
{
    WORK* em;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 1;
    case 1:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        if (Target_Pos < PL_Distance[wk->wu.id]) {
            Timer_00[wk->wu.id] = 1;
            Ck_Distance_Lv(wk);
            break;
        }
        em = (WORK*)wk->wu.target_adrs;
        if (em->xyz[1].disp.pos + em->cg_jphos > 0) {
            Timer_00[wk->wu.id] = 20;
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Lever_Buff[wk->wu.id] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



void Walk(wk, Lever, Time, unused)
PLW* wk;
u16 Lever;
s16 Time;
s16 unused;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = Time;
        Timer_01[wk->wu.id] = wk->wu.rl_flag;
        Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Lever);
    case 1:
        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (*CP_No[wk->wu.id] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            if ((Timer_01[wk->wu.id] != (s16)wk->wu.rl_flag) || (wk->micchaku_flag != 0) || (wk->hos_em_flag != 0)) {
                Next_Be_Free(wk);
            }
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        }
        break;
    }
}



void Forced_Guard(wk, Guard_Type)
PLW* wk;
s16 Guard_Type;
{
    WORK* em;
    s16 xx;
    em = (WORK*)wk->wu.target_adrs;
    if (Attack_Flag[wk->wu.id] == 0) {
        Next_Be_Free(wk);
    }
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        Next_Be_Free(wk);
    }
    Next_Be_Guard(wk, em, Guard_Type);
    Lever_Buff[wk->wu.id] |= Lever_Squat[wk->wu.id];
}



void Provoke(wk, Lever)
PLW* wk;
s16 Lever;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk)) {
            return;
        }
        CP_Index[wk->wu.id][1]++;
        if (Lever != -1) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, Lever & 1);
            Lever_LR[wk->wu.id] |= Lever & 2;
        }
    case 1:
        if (wk->permited_koa & 0x80) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = 0x240;
        }
        return;
    default:
        {
            s32 j = wk->wu.id;
            Lever_Buff[j] = Lever_LR[j];
        }
        if (wk->wu.routine_no[1] == 4 && wk->wu.routine_no[2] == 0x1E) {
            return;
        }
        Reaction_Exit_Sub(wk);
        return;
    }
}



void Normal_Attack(wk, Reaction, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Lever_Data & 2) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
        Lever_LR[wk->wu.id] |= Lever_Data & 2;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



s32 Small_Jump_Measure(PLW* wk) {
    if (Lever_Squat[wk->wu.id] & 2) {
        return Setup_Guard_Lever(wk, 1);
    }
    return 0;
}



void Normal_Attack_SP(wk, Reaction, Lever_Data, Time)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
s16 Time;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
            CP_Index[wk->wu.id][1]++;
            Timer_00[wk->wu.id]--;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Squat[wk->wu.id];
        }
        break;
    case 2:
        if (--Timer_00[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



void Adjust_Attack(wk, Reaction, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
{
    u16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            xx = (((WORK*)wk->wu.target_adrs)->pat_status == 0x20) ? 0 : 2;
            Lever_Buff[wk->wu.id] = Lever_Data | xx;
            Lever_LR[wk->wu.id] = xx;
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}


/* provisional name */
s32 Check_Target_Pat_Status(WORK* wk) {
    if (((WORK*)wk->target_adrs)->pat_status == 32) {
        return 0;
    }
    return 2;
}



s32 Check_Start_Normal_Attack(wk, Reaction, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
{
    if (((wk->wu.routine_no[1]) != 4) || ((wk->wu.cg_type) == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->permited_koa & 0x10) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }
    return 1;
}



void Lever_Attack(wk, Reaction, Lever, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever;
u16 Lever_Data;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Lever_Attack(wk, Lever, Lever_Data) != 0) {
            break;
        }
        dash_flag_clear(wk->wu.id);
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        xx = Setup_Guard_Lever(wk, Lever);
        Lever_Buff[wk->wu.id] = (Lever_Data | xx);
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        if (wk->wu.routine_no[1] == 2) {
            Be_Catch(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, 0);
        }
        break;
    }
}



void Lever_Attack_SP(wk, Reaction, Lever, Lever_Data, Time)
PLW* wk;
s16 Reaction;
u16 Lever;
u16 Lever_Data;
s16 Time;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Lever_Attack(wk, Lever, Lever_Data) != 0) {
            break;
        }
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = Time;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        xx = Setup_Guard_Lever(wk, Lever);
        Lever_Buff[wk->wu.id] = (Lever_Data | xx);
        Timer_00[wk->wu.id]--;
        CP_Index[wk->wu.id][1]++;
        break;
    case 2:
        if (--Timer_00[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



s32 Setup_Guard_Lever(wk, Lever)
PLW* wk;
u16 Lever;
{
    switch (Lever) {
    case 0:
        if (wk->wu.rl_waza == 0) {
            return 4;
        }
        return 8;
    case 1:
        if (wk->wu.rl_waza == 1) {
            return 4;
        }
        return 8;
    }
    return 0;
}



s32 Check_Start_Lever_Attack(wk, Lever, Lever_Data)
PLW* wk;
u16 Lever;
u16 Lever_Data;
{
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->wu.cg_cancel & 8) {
        return 0;
    }
    return 1;
}



void SA_Term(wk, SA0, SA1, SA2, Term_No)
PLW* wk;
u16 SA0;
u16 SA1;
u16 SA2;
u16 Term_No;
{
    s16 xx[3];
    if (((Passive_Flag[wk->wu.id]) == 0) && (Check_Passive(wk) != 0)) {
        return;
    }
    xx[0] = SA0;
    xx[1] = SA1;
    xx[2] = SA2;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if ((xx[plw[wk->wu.id].sa->kind_of_arts] == -1) || plw[wk->wu.id].metamorphose) {
        CP_Index[wk->wu.id][0]++;
    } else if ((plw[wk->wu.id].sa->ok) || (plw[wk->wu.id].sa->mp)) {
        Disposal_Again[wk->wu.id] = 1;
        if ((Term_No != -1) || (Term_No != 0)) {
            switch (wk->player_number) {
            case PL_RYU:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                DENJIN_Check(wk, xx[2], (u16*)&xx[2], Term_No);
                break;
            case PL_KEN:
            case PL_ALEX:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                break;
            case PL_NECRO:
                if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos >= 0x10) {
                    CP_Index[wk->wu.id][0]++;
                    return;
                }
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                break;
            case PL_HUGO:
                if (SA_Range_Check(wk, 0, Term_No) != 0) {
                    return;
                }
                break;
            case PL_ELENA:
                if ((plw[wk->wu.id].sa->kind_of_arts == 2) && (plw[wk->wu.id].wu.vital_new <= (Max_vitality / 2))) {
                    break;
                }
                CP_Index[wk->wu.id][0]++;
                return;
            case PL_ORO:
                YAGYOU_Check(wk, &xx[1], Term_No);
                break;
            case PL_GOUKI1:
            case PL_GOUKI2:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                if (SA_Range_Check(wk, 2, Term_No) != 0) {
                    return;
                }
                break;
            }
        }
        Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
    } else {
        CP_Index[wk->wu.id][0]++;
    }
}



s32 DENJIN_Check(wk, SA2, xx, Term_No)
PLW* wk;
u16 SA2;
u16* xx;
u16 Term_No;
{
    if (plw[wk->wu.id].sa->kind_of_arts != 2) {
        return 0;
    }
    DENJIN_No[wk->wu.id] = Term_No;
    DENJIN_Term[wk->wu.id] = SA2;
    xx[0] = 0x37;
    return 1;
}



s32 YAGYOU_Check(wk, xx, Term_No)
PLW* wk;
s16* xx;
u16 Term_No;
{
    if (plw[wk->wu.id].sa->kind_of_arts == 1) {
        if (Term_No == 0) {
            Term_No = YAGYOU_Data[random_16_com()];
            Term_No += 0x64;
        }
        xx[0] = Term_No;
        return 1;
    }
}



s32 SA_Range_Check(wk, SA_No, Range)
PLW* wk;
s16 SA_No;
u16 Range;
{
    if (plw[wk->wu.id].sa->kind_of_arts != SA_No) {
        return 0;
    }
    if (Range & 0x8000) {
        if ((PL_Distance[wk->wu.id]) < (Range & 0x7FFF)) {
            CP_Index[wk->wu.id][0]++;
            return 1;
        }
    }
    else if (PL_Distance[wk->wu.id] > Range) {
        CP_Index[wk->wu.id][0]++;
        return 1;
    }
    return 0;
}



s32 Check_SA(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    if (plw[wk->wu.id].sa->ok) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    return (s32)Lever_Buff;
}



void Check_EX(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    if (plw[wk->wu.id].sa->ex) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



void Check_SA_Full(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    Disposal_Again[wk->wu.id] = 1;
    if (!((wk->permited_koa & 0x40) == 0)) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
}



/* provisional name */
void Check_SA_Range(wk, SA_No, Range, Next_Action, Next_Menu)
PLW* wk;
s16 SA_No;
s16 Range;
s16 Next_Action;
s16 Next_Menu;
{
    Disposal_Again[wk->wu.id] = 1;
    if (((PLW*)((s8*)plw + (s16)(wk->wu.id * sizeof(PLW))))->sa->kind_of_arts == SA_No) {
        if (PL_Distance[wk->wu.id] > Range) {
            CP_No[wk->wu.id][0] = Next_Action;
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        }
    }
}



void Branch_Unit_Area(wk, Next_Action, Menu_00, Menu_01, Menu_02, Menu_03)
PLW* wk;
s16 Next_Action;
s16 Menu_00;
s16 Menu_01;
s16 Menu_02;
s16 Menu_03;
{
    s16 xx[4];
    CP_No[wk->wu.id][0] = Next_Action;
    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
    Disposal_Again[wk->wu.id] = 1;
    Next_Another_Menu(wk, Next_Action, xx[Area_Number[wk->wu.id]]);
}



void Com_Random_Select(wk, Next_Action, Menu_00, Menu_01, Menu_02, Menu_03, Rnd_Type)
PLW* wk;
s16 Next_Action;
s16 Menu_00;
s16 Menu_01;
s16 Menu_02;
s16 Menu_03;
s16 Rnd_Type;
{
    s16 xx[4];
    s16 zz;
    zz = Com_Rnd_Select_Data[Rnd_Type][random_16_com()];
    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (xx[zz] == 0xFF) {
        Next_End(wk);
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, xx[zz]);
    }
}



void Branch_Wait_Area(wk, Time_00, Time_01, Time_02, Time_03)
PLW* wk;
s16 Time_00;
s16 Time_01;
s16 Time_02;
s16 Time_03;
{
    s16 xx[4];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        xx[0] = Time_00;
        xx[1] = Time_01;
        xx[2] = Time_02;
        xx[3] = Time_03;
        Timer_00[wk->wu.id] = xx[Area_Number[wk->wu.id]];
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



void Wait(wk, Time)
PLW* wk;
s16 Time;
{
    s32 k;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        if (Time == 0) {
            Timer_00[wk->wu.id] = Setup_WT_Data(wk);
        } else {
            Timer_00[wk->wu.id] = Time;
        }
        break;
    default:
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
    k = wk->wu.id;
    Lever_Buff[k] = Lever_LR[k];
}



void Look(wk, Time)
PLW* wk;
s16 Time;
{
    s16* tm = Timer_00;
    Passive_Flag[wk->wu.id] = 0;
    Lever_Buff[wk->wu.id] = (&Lever_LR[0])[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            if (Time == 0) {
                tm[wk->wu.id] = Setup_LP_Data(wk);
            } else {
                tm[wk->wu.id] = Time;
            }
            if (Lever_LR[wk->wu.id] & 2) {
                tm[wk->wu.id] += 50;
            }
        }
        break;
    default:
        if (Check_Passive(wk) == 0 && --tm[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            Before_Look[wk->wu.id] = 1;
        }
        break;
    }
}



void Keep_Status(wk, Lever_Data, Option_Data)
PLW* wk;
u16 Lever_Data;
s16 Option_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0xA;
        Free_Lever[wk->wu.id] = Lever_Data;
        if (Option_Data != -1) {
            Free_Lever[wk->wu.id] |= Setup_Guard_Lever(wk, Option_Data);
        }
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        break;
    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        if (Attack_Flag[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}



/* No final return: the routine's result is only read when Check_Guard succeeded (return 1). */
s32 VS_Jump_Guard(PLW* wk) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Guard(wk)) {
            return 1;
        }
        dash_flag_clear(wk->wu.id);
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        if (Check_Guard(wk)) {
            return 1;
        }
        if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos <= 0x18) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



void Wait_Lie(wk, Lever_Data)
PLW* wk;
u16 Lever_Data;
{
    WORK* em;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;
        if (Lever_Data != 0) {
            Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Free_Lever[wk->wu.id] |= Lever_Data & 2;
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        em = (WORK*)wk->wu.target_adrs;
        if ((Check_Blow_Off(wk, em, 0) == 0) || (Lie_Flag[wk->wu.id] != 0)) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



void Wait_Get_Up(wk, Lever_Data, Option)
PLW* wk;
u16 Lever_Data;
s16 Option;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;
        if (Lever_Data != 0) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Wait_Term(wk, Option) != 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Disposal_Again[wk->wu.id] = 1;
            Passive_Flag[wk->wu.id] = 1;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



s32 Check_Wait_Term(wk, Option)
PLW* wk;
s16 Option;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    if (em->routine_no[1] == 1 && em->pat_status == 0x18) {
        return 0;
    }
    if (Lie_Flag[wk->wu.id] == 0) {
        return 1;
    }
    if (Option != 0) {
        return 0;
    }
    if (em->cg_type == 0xB) {
        return 1;
    }
    return 0;
}



void Wait_Attack_Complete(wk, Lever_Data, Option)
PLW* wk;
u16 Lever_Data;
s16 Option;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        if (Lever_Data) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
            Guard_Flag[wk->wu.id] = 1;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
    }
    {
        s32 j = wk->wu.id;
        Lever_Buff[j] = Lever_LR[j];
    }
    {
        s32 k = Option;
        if (!Check_Exit_Guard(wk, k)) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Guard_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (!k) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
    }
}



s32 Check_Exit_Guard(wk, Option)
PLW* wk;
s16 Option;
{
    WORK* em;
    if (wk->wu.routine_no[1] == 1) {
        return 1;
    }
    if (Option == 0) {
        em = (WORK*)wk->wu.target_adrs;
        if (em->routine_no[1] != 4) {
            return 0;
        }
        return 1;
    }
    return Attack_Flag[wk->wu.id];
}



void Short_Range_Attack(wk, Reaction, Lever_Data, Next_Action, Next_Menu)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
s16 Next_Action;
s16 Next_Menu;
{
    u16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) == 0) {
            CP_Index[wk->wu.id][1]++;
            Check_First_Menu(wk);
            Ck_Distance_LvJ(wk);
            xx = get_nearing_range(wk->player_number, xx = Lever_Data & 0x3F0);
            if (PL_Distance[wk->wu.id] > xx) {
                Next_Another_Menu(wk, Next_Action, Next_Menu);
            }
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



void EM_Term(wk, Range_X, Range_Y, Exit_Number, Next_Action, Next_Menu)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Exit_Number;
s16 Next_Action;
s16 Next_Menu;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Check_Exit_Term(wk, em, Exit_Number)) {
        case 0:
            if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
                break;
            }
            if (Exit_Number != 8) {
                if (Check_Term_Sub_Y(wk, em->xyz[1].disp.pos, Range_Y) == 0) {
                    break;
                }
            } else {
                if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
                    break;
                }
            }
            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            break;
        case 1:
            Disposal_Again[wk->wu.id] = 1;
            Next_Another_Menu(wk, Next_Action, Next_Menu);
            break;
        case 2:
            break;
        case 3:
            Select_Passive(wk);
            break;
        default:
            Counter_Attack[wk->wu.id] = 1;
            Select_Passive(wk);
            break;
        }
        break;
    }
}



void SHELL_Term(wk, Next_Command, Exit_Number, Next_Action, Next_Menu, unused)
PLW* wk;
s16 Next_Command;
s16 Exit_Number;
s16 Next_Action;
s16 Next_Menu;
s16 unused;
{
    WORK* em;
    WORK_Other* tmw;
    s16 xx;
    em = (WORK*)Shell_Address[wk->wu.id];
    tmw = (WORK_Other*)Shell_Address[wk->wu.id];
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Exit_Term(wk, em, Exit_Number) == -1) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            xx = Compute_Hit_Time(wk, tmw);
            if (xx < Shell_Dodge_Data[Next_Command][wk->player_number]) {
                Disposal_Again[wk->wu.id] = 1;
                CP_Index[wk->wu.id][0]++;
                CP_Index[wk->wu.id][1] = 0;
                CP_Index[wk->wu.id][2] = 0;
                CP_Index[wk->wu.id][3] = 0;
                Flip_Flag[wk->wu.id] = 0;
                Limited_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}



s32 Check_Term_Sub_Air(wk, Distance, Range)
PLW* wk;
s16 Distance;
s16 Range;
{
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        Range += Correct_Unit_PL(wk);
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



s32 Check_Term_Sub(wk, Distance, Range)
PLW* wk;
s16 Distance;
s16 Range;
{
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



/* provisional name */
s32 Correct_Unit_PL(PLW* wk) {
    return Correct_VS_Air_Data[My_char[Player_id]];
}



s32 Check_Term_Sub_Y(wk, Distance, Range)
PLW* wk;
s16 Distance;
s16 Range;
{
    WORK* em;
    if (Range == -1) {
        return 1;
    }
    em = (WORK*)wk->wu.target_adrs;
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (em->mvxy.a[1].real.h > 0) {
            return 0;
        }
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



void Jump(wk, Jump_Dir)
PLW* wk;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            CP_Index[wk->wu.id][1]++;
            hi_jump_flag_clear(wk->wu.id);
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Check_Air_Guard(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}



void Hi_Jump(wk, Pl_Number, Jump_Dir)
PLW* wk;
s16 Pl_Number;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[Pl_Number][2];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        Lever_Buff[wk->wu.id] = 0;
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, -1, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }
        if (!(Lever_Buff[wk->wu.id] & 2)) {
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Check_Air_Guard(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Check_Air_Guard(wk);
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}




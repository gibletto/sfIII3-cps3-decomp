/*
 * CK_PASS.C  Computer player: passive reaction checks
 *
 * Decides how the CPU reacts to what its opponent is doing. KEN_vs, HUGO_vs and GILL_vs
 * are opponent-specific reaction selectors; the Check_* routines test for particular
 * situations (special techniques, attack direction, jump counters, rushes, dashes,
 * super-art punishes, throws, knock-downs, faints, turn-overs) and set VS_Tech and
 * Counter_Attack.
 * Check_PL_Unit_AS and its companions dispatch by the opponent's character to the
 * VS_<name>_ routines, one per opponent and screen area A-D, with and without an attack in
 * progress (the ...S variants); each tests the opponent's special techniques and returns 1
 * when a reaction has been chosen. Called from the passive and guard logic in Com_Pl and
 * Com_Sub.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PLS02.h"
#include "Ck_Pass.h"
#include "fighter.h"
#include "Com_Pl.h"
#include "PLS03ATT.h"
#include "CMD_MAIN.h"
#include "HITCHECK.h"
#include "EFFECT.h"



s32 Check_Start_Hi_Jump(PLW* wk) {
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->wu.cg_cancel & 1) {
        return 0;
    }
    return 1;
}



s32 Check_Air_Guard(PLW* wk) {
    WORK* em;
    s16 xx;
    s16 zz;
    em = (WORK*)wk->wu.target_adrs;
    if (Lever_LR[wk->wu.id]) {
        return Lever_LR[wk->wu.id];
    }
    if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return Lever_LR[wk->wu.id];
    }
    if (Attack_Flag[wk->wu.id] == 0) {
        return Lever_LR[wk->wu.id];
    }
    xx = Hit_Range_Data[em->hit_range] + 0x20;
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        return 0;
    }
    Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Lv = Setup_Lv10(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_16_com();
    Lv += CC_Value[0];
    if (Lv >= 7) {
        Lv = 0xA;
    }
    zz = Setup_EM_Rank_Index(wk);
    if (Guard_Data[zz][Lv][Rnd] == 3) {
        return Lever_LR[wk->wu.id] = 0;
    }
    Guard_Type[wk->wu.id] = Guard_Data[zz][Lv][random_16_ex_com()];
    Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_LR[wk->wu.id] |= 2;
    return Guard_Type[wk->wu.id] |= 0x8000;
}



/* provisional name */
void Jump_Air_Guard(wk, Lever)
PLW* wk;
s16 Lever;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (wk->wu.routine_no[1] == 4 && wk->wu.cg_type != 64) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Lever);
    case 1:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id] | 1;
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    default:
        Check_Air_Guard(wk);
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        Lever_Buff[wk->wu.id] = 0;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}



void Jump_Attack(wk, Reaction, Time_Data, Lever_Data, Jump_Dir)
PLW* wk;
s16 Reaction;
s16 Time_Data;
u16 Lever_Data;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time_Data;
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        hi_jump_flag_clear(wk->wu.id);
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        Timer_00[wk->wu.id] = Time_Data;
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Check_Air_Guard(wk);
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        Check_Air_Guard(wk);
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



void Jump_Attack_Term(wk, Range_X, Range_Y, Reaction, Lever_Data, Jump_Dir, Range_JX, Range_JY, J_Lever_Data)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Reaction;
u16 Lever_Data;
s16 Jump_Dir;
s16 Range_JX;
s16 Range_JY;
s16 J_Lever_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }
        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        Check_Term_ABS_Distance(wk);
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;
    case 4:
        Check_Air_Guard(wk);
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        break;
    case 5:
        if (Check_Landed(wk, Reaction & 0x7F) == 0) {
            switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
            default:
            case 1:
            case 10:
                if (Command_Type_00(wk, 8, -1, -1) == -1) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



s32 Check_SP_Jump_Attack(wk, Lever_Data)
PLW* wk;
s16 Lever_Data;
{
    u16 xx;
    if (!(Lever_Data & 0x8000)) {
        return Lever_Data;
    }
    xx = Setup_Guard_Lever(wk, 0);
    xx |= Lever_Data & 0x7FFF;
    return xx | 2;
}



s32 Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data)
PLW* wk;
s16 Range_JX;
s16 Range_JY;
s16 J_Lever_Data;
{
    WORK* em;
    if ((Range_JX == -1) && (Range_JY == -1)) {
        return 0;
    }
    if (J_Lever_Data == -1) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    if ((em->pat_status != 0xE) && (em->pat_status != 0x14) && (em->pat_status != 0x1A) && (em->xyz[1].disp.pos <= 0)) {
        return 0;
    }
    if (Check_Term_Sub_Air(wk, PL_Distance[wk->wu.id], Range_JX) == 0) {
        return 0;
    }
    if (Check_Term_Sub(wk, Ck_Distance_Height(wk), Range_JY) != 0) {
        switch (CP_Index[wk->wu.id][2]) {
        case 0:
            CP_Index[wk->wu.id][2]++;
            Timer_01[wk->wu.id] = Select_Reflection_Time(wk);
            Timer_01[wk->wu.id]++;
            break;
        default:
            if (--Timer_01[wk->wu.id] != 0) {
                break;
            }
            if (J_Lever_Data & 0x4000) {
                CP_Index[wk->wu.id][1] += 2;
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][J_Lever_Data & 0x3FFF];
                Continue_Menu[wk->wu.id] = 1;
                return -1;
            }
            Lever_Buff[wk->wu.id] = J_Lever_Data;
            CP_Index[wk->wu.id][1]++;
            Continue_Menu[wk->wu.id] = 1;
            return 1;
        }
    }
    return 0;
}



void Hi_Jump_Attack(wk, Reaction, Time_Data, Lever_Data, Jump_Dir)
PLW* wk;
s16 Reaction;
s16 Time_Data;
u16 Lever_Data;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            wk->wu.hf.hit.player = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
            Timer_00[wk->wu.id] = Time_Data;
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
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        Lever_Pool[wk->wu.id] &= 0xC;
        Lever_Buff[wk->wu.id] = 0;
        Check_Air_Guard(wk);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }
        if (Lever_Buff[wk->wu.id] & 2) {
            return;
        }
        Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1] += 2;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 6:
        Check_Air_Guard(wk);
        if (Attack_Flag[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }
        if (!(wk->wu.cg_cancel & 8)) {
            break;
        }
        Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);
        break;
    default:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 4) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



void Hi_Jump_Attack_Term(wk, Range_X, Range_Y, Reaction, Lever_Data, Jump_Dir, Range_JX, Range_JY, J_Lever_Data)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Reaction;
u16 Lever_Data;
s16 Jump_Dir;
s16 Range_JX;
s16 Range_JY;
u16 J_Lever_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) != 0) {
            break;
        }
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
        Check_First_Menu(wk);
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
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        Lever_Pool[wk->wu.id] &= 0xC;
        Lever_Buff[wk->wu.id] = 0;
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        } else {
            if (Lever_Buff[wk->wu.id] & 2) {
                return;
            }
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1] = 8;
        }
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    case 6:
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            Command_Type_00(wk, -1);
            CP_Index[wk->wu.id][1] = 0x63;
        }
        break;
    case 7:
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][8];
        CP_Index[wk->wu.id][1]++;
        break;
    case 8:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    default:
        if (Attack_Flag[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][1] = 8;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }
        if (wk->wu.cg_cancel & 8) {
            Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);
        }
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 4) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



s32 Check_Term_ABS_Distance(PLW* wk) {
    if (Turn_Over[wk->wu.id]) {
        return 1;
    }
    if (My_char[wk->wu.id] == PL_NECRO) {
        return 0;
    }
    if (PL_Distance[wk->wu.id] <= 0x30) {
        return 1;
    }
    if (wk->wu.mvxy.a[1].real.h >= 0) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 0x30) {
        return 1;
    }
    return 0;
}



s32 Check_Com_Add_Y(wk, Pos_Y, Range)
PLW* wk;
s16 Pos_Y;
s16 Range;
{
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Pos_Y >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (wk->wu.mvxy.a[1].real.h >= 0) {
            return 0;
        }
        if (Pos_Y <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}


/* provisional name */
s32 Check_Com_Add_Y_Sub(PLW* wk) {
    if (wk->wu.routine_no[1] == 4 && (u8)wk->wu.cg_type == 64) {
        return 1;
    }
    return 0;
}



void ORO_JA_Term(wk, Reaction, Jump_Dir, JY, Jump_Dir2, RX, RY, Lever_Data, RJX, RJY, JLD)
PLW* wk;
s16 Reaction;
s16 Jump_Dir;
s16 JY;
s16 Jump_Dir2;
s16 RX;
s16 RY;
u16 Lever_Data;
s16 RJX;
s16 RJY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }
        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        Check_Air_Guard(wk);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }
        break;
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;
    case 3:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }
        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id] == 0) {
            if ((Lever_Data) == 0xFFFF) {
                CP_Index[wk->wu.id][1] += 2;
            } else {
                CP_Index[wk->wu.id][1]++;
            }
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        break;
    case 6:
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, 8, -1, -1) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



void ORO_HJA_Term(wk, Reaction, Jump_Dir, JY, Jump_Dir2, RX, RY, Lever_Data, RJX, RJY, JLD)
PLW* wk;
s16 Reaction;
s16 Jump_Dir;
s16 JY;
s16 Jump_Dir2;
s16 RX;
s16 RY;
u16 Lever_Data;
s16 RJX;
s16 RJY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }
        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Lever_Data == 0xFFFF) {
            CP_Index[wk->wu.id][1] += 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 5:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;
    case 6:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;
    case 7:
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}



void Command_Attack(wk, Reaction, Tech_Number, Power_Level, Ex_Shot)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        if (Power_Level & 0x4000) {
            Free_Lever[wk->wu.id] = Free_Lever_Data[(Power_Level & 0xF) - 8];
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
    case 1:
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        if (Hadou_Check(wk, Tech_Number & 0x80FF) != 0) {
            if (Check_Passive(wk) == 0) {
                Combo_Speed[wk->wu.id] = 1;
            }
            break;
        } else {
            CP_Index[wk->wu.id][1]++;
            Check_Rapid(wk, Tech_Number);
        }
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                if ((Tech_Number & 0xF) == 0 || (Tech_Number & 0xF) == 1) {
                    if (Reaction == 0xC) {
                        CP_Index[wk->wu.id][1] = 0x63;
                        Timer_00[wk->wu.id] = Command_Wait_Data[wk->player_number][Tech_Number];
                    } else {
                        CP_Index[wk->wu.id][1] = 4;
                    }
                } else {
                    CP_Index[wk->wu.id][1] = 3;
                }
            }
            break;
        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        case 7:
            if (Command_Type_06(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
            Rapid_Sub(wk);
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, Power_Level);
        }
        break;
    case 4:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (((wk->wu.cg_type) == 0x40) || (wk->running_f == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    case 5:
        if (PL_Distance[wk->wu.id] > 0x70) {
            Lever_Buff[wk->wu.id] = 0x40;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (--Timer_00[wk->wu.id] == 0) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}



s32 Hadou_Check(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    if (Hadou_Check_Data[wk->player_number][0] == 0) {
        return 0;
    }
    if (Hadou_Check_Data[wk->player_number][1] != Tech_Number) {
        return 0;
    }
    return Check_Resume_Lever(wk);
}



s32 Check_Resume_Lever(PLW* wk) {
    u16 Target_Lever;
    s16 xx;
    if (wk->wu.rl_waza) {
        Target_Lever = 8;
    } else {
        Target_Lever = 4;
    }
    for (xx = 0; xx <= 8; xx++) {
        if (Target_Lever == Resume_Lever[wk->wu.id][xx]) {
            return 1;
        }
    }
    return 0;
}



void J_Command_Attack(wk, Reaction, Tech_Number, Power_Level, Ex_Shot)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }
        Continue_Menu[wk->wu.id] = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
            break;
        }
        CP_Index[wk->wu.id][1]++;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    case 3:
        Check_Rapid(wk, Tech_Number);
        CP_Index[wk->wu.id][1]++;
        return;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Rapid_Sub(wk);
            if (Reaction == 0xC) {
                Reaction_Sub(wk, Reaction, Power_Level);
                break;
            }
            Check_Landed(wk, Reaction & 0xFFF);
        }
        break;
    }
}



void Rapid_Command_Attack(wk, Reaction, Tech_Number, Shot, Time)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Shot;
u16 Time;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        Free_Lever[wk->wu.id] = 0;
    case 1:
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Rapid_No[wk->wu.id][0] = 0;
        Rapid_No[wk->wu.id][1] = 0;
        Timer_00[wk->wu.id] = Time;
    case 2:
        switch (Rapid_No[wk->wu.id][0]) {
        case 0:
            Rapid_No[wk->wu.id][0] = 1;
            Lever_Buff[wk->wu.id] = Shot;
            break;
        case 1:
            Rapid_No[wk->wu.id][0] = 0;
            Lever_Buff[wk->wu.id] = 0;
            break;
        }
        if (wk->wu.sp_tech_id == Tech_Number) {
            CP_Index[wk->wu.id][1] = 3;
        }
        break;
    case 3:
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1] = 4;
        }
        else {
            switch (Rapid_No[wk->wu.id][0]) {
            case 0:
                Rapid_No[wk->wu.id][0] = 1;
                Lever_Buff[wk->wu.id] = Shot;
                break;
            case 1:
                Rapid_No[wk->wu.id][0] = 0;
                Lever_Buff[wk->wu.id] = 0;
                break;
            }
            if (wk->wu.sp_tech_id != Tech_Number) {
                CP_Index[wk->wu.id][1] = 4;
            }
        }
        break;
    case 4:
        if (wk->wu.sp_tech_id == Tech_Number) {
            break;
        }
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}



void Check_Rapid(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    if (!(Tech_Number & 0xF00)) {
        Rapid_No[wk->wu.id][0] = 0;
    } else {
        Lv = Setup_Lv08(0);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        Rapid_No[wk->wu.id][0] = Rapid_SA_Data[Lv][random_32_com() & 7];
        Rapid_No[wk->wu.id][1] = 0;
        Setup_Rapid_End_Term(wk, Tech_Number);
        Rapid_Index[wk->wu.id] = 0x3F0;
    }
}



void Setup_Rapid_End_Term(wk, Tech_Number)
PLW* wk;
s16 Tech_Number;
{
    Rapid_No[wk->wu.id][2] = (Tech_Number & 0xF00) >> 8;
    if ((Tech_Number & 0xF00) == 0x400) {
        Rapid_No[wk->wu.id][3] = Setup_Rapid_Time(wk, Tech_Number);
    }
}



/* provisional name */
s32 Setup_Rapid_Time(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    return 60;
}



void Rapid_Sub(PLW* wk) {
    if (Check_Rapid_End(wk) != 0) {
        return;
    }
    switch (Rapid_No[wk->wu.id][0]) {
    case 0:
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 3;
            return;
        case 1:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = 2;
                if (--Timer_01[wk->wu.id] == 0) {
                    Rapid_No[wk->wu.id][1]++;
                    Timer_01[wk->wu.id] = 0x18;
                }
            }
            break;
        case 2:
            if (--Timer_01[wk->wu.id] == 0) {
                Rapid_No[wk->wu.id][1]++;
                Timer_00[wk->wu.id] = 1;
                Timer_01[wk->wu.id] = 2;
            }
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    default:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 2;
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    }
}



s32 Check_Rapid_End(PLW* wk) {
    switch (Rapid_No[wk->wu.id][2]) {
    case 1:
        if (wk->wu.mvxy.a[1].real.h < 0) {
            Rapid_No[wk->wu.id][0] = 0;
            return 1;
        }
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][3]) {
        case 0:
            if (plw[wk->wu.id].caution_flag) {
                Rapid_No[wk->wu.id][3]++;
            }
            break;
        case 1:
            if (plw[wk->wu.id].caution_flag == 0) {
                Rapid_No[wk->wu.id][0] = 0;
                return 1;
            }
            break;
        }
        break;
    case 4:
        switch (Rapid_No[wk->wu.id][3]) {
        case 0:
            if (wk->wu.cg_ja.atix) {
                Rapid_No[wk->wu.id][3]++;
            }
            break;
        case 1:
            if (--Rapid_No[wk->wu.id][3] == 0) {
                Rapid_No[wk->wu.id][0] = 0;
                return 1;
            }
            break;
        }
        break;
    }
    return 0;
}



s32 Check_Start_Command_Attack(wk, Reaction, Tech_Number)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
{
    if (Before_Jump[wk->wu.id]) {
        return Before_Jump[wk->wu.id] = 0;
    }
    if (wk->wu.routine_no[1] == 2) {
        return 1;
    }
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if ((Tech_Number == 0) || (Tech_Number == 1)) {
        if (wk->wu.cg_cancel & 2) {
            return 0;
        }
        return 1;
    }
    if ((Tech_Number & 0x8000) && (wk->wu.cg_cancel & 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 0x20) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }
    return 1;
}



void ORO_JCA_Term(wk, Reaction, Jump_Dir, JY, Jump_Dir2, RX, RY, Tech_Number, Power_Level, Ex_Shot, RJX, RJY, JLD)
PLW* wk;
s16 Reaction;
s16 Jump_Dir;
s16 JY;
s16 Jump_Dir2;
s16 RX;
s16 RY;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RJX;
s16 RJY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            dash_flag_clear(wk->wu.id);
            Jump_Init(wk, Jump_Dir);
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;
    case 3:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }
        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        break;
    case 6:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



void ORO_HJCA_Term(wk, Reaction, Jump_Dir, JY, Jump_Dir2, RX, RY, Tech_Number, Power_Level, Ex_Shot, RJX, RJY, JLD)
PLW* wk;
s16 Reaction;
s16 Jump_Dir;
s16 JY;
s16 Jump_Dir2;
s16 RX;
s16 RY;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RJX;
s16 RJY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) != 0) {
            break;
        }
        Continue_Menu[wk->wu.id] = 0;
        CP_Index[wk->wu.id][1]++;
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0x7FFF];
        Check_First_Menu(wk);
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }
        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 5:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 6:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }
        break;
    case 7:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



void Jump_Command_Attack_Term(wk, Reaction, Tech_Number, Power_Level, Ex_Shot, RX, RY, Jump_Dir, JRX, JRY, JLD)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RX;
s16 RY;
s16 Jump_Dir;
s16 JRX;
s16 JRY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Check_Rapid(wk, Tech_Number);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;
    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 3:
        Check_Air_Guard(wk);
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 4:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    case 5:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



void Hi_Jump_Command_Attack_Term(wk, Reaction, Tech_Number, Power_Level, Ex_Shot, RX, RY, Jump_Dir, JRX, JRY, JLD)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RX;
s16 RY;
s16 Jump_Dir;
s16 JRX;
s16 JRY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0x7FFF];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;
    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    case 6:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



s32 Check_Landed(wk, Reaction)
PLW* wk;
s16 Reaction;
{
    if ((wk->wu.old_pos[1] != 0) && (wk->wu.xyz[1].disp.pos == 0)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
            Check_Guard(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    if ((wk->wu.old_pos[1] == 0) && (wk->wu.xyz[1].disp.pos == 0) && (wk->wu.routine_no[1] != 4)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);
            if (Check_Guard(wk) != 0) {
                return 1;
            }
            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    return 0;
}



s32 Check_Dash_Hit(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    WORK_Other* tmw;
    WORK* em;
    s16 i;
    s16 xx;
    s16 zz;
    if ((Tech_Number != 0) && (Tech_Number != 1)) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs((WORK*)wk, em->id, i, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        xx = wk->wu.xyz[0].disp.pos - tmw->wu.xyz[0].disp.pos;
        zz = Setup_Front_or_Back(wk, xx);
        if (Tech_Number == 0) {
            if (zz != 1) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        } else {
            if (zz != 0) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}



s32 Setup_Front_or_Back(wk, xx)
PLW* wk;
s16 xx;
{
    if (wk->wu.rl_waza == 0) {
        if (xx >= 0) {
            return 0;
        }
        return 1;
    } else {
        if (xx >= 0) {
            return 1;
        }
        return 0;
    }
}



s32 Check_Hit_Shell(wk, tmw, Tech_Number)
PLW* wk;
WORK_Other* tmw;
u16 Tech_Number;
{
    s16 xx;
    if (wk->wu.rl_waza == 1) {
        Tech_Number ^= 1;
    }
    if (Tech_Number == 0) {
        xx = wk->wu.xyz[0].disp.pos - Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx <= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    } else {
        xx = wk->wu.xyz[0].disp.pos + Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx >= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
}



void Jump_Init(wk, Jump_Dir)
PLW* wk;
s16 Jump_Dir;
{
    u16* a;
    u16* b;
    s32 i;

    a = Lever_Buff;
    b = Lever_Pool;
    switch (Jump_Dir) {
    case 0:
        Ck_Distance_LvJ(wk);
        i = wk->wu.id * 2;
        *(u16*)((s32)a + i) = *(u16*)((s32)b + i);
        break;
    case 2:
        b[wk->wu.id] = 1;
        a[wk->wu.id] = 1;
        break;
    default:
        Ck_Distance_LvJ(wk);
        b[wk->wu.id] ^= 0xC;
        i = wk->wu.id * 2;
        *(u16*)((s32)a + i) = *(u16*)((s32)b + i);
        break;
    }
}



s32 Command_Type_00(wk, Power_Level, Tech_Number, Ex_Shot)
PLW* wk;
s16 Power_Level;
u16 Tech_Number;
s16 Ex_Shot;
{
    if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 4] != 0x1C) {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        Lever_Buff[wk->wu.id] = datacmd_conpanecmd(Lever_Buff[wk->wu.id]);
        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        Tech_Index[wk->wu.id] += 4;
        return 1;
    } else {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        if (Tech_Address[wk->wu.id][7] == 0x80) {
            return -1;
        }
        Tech_Index[wk->wu.id] = 7;
        if ((plw[wk->wu.id].sa->ex) && ((Ex_Shot == 0x70) || (Ex_Shot == 0x380))) {
            Lever_Buff[wk->wu.id] |= Ex_Shot;
        } else {
            Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        }
        if ((My_char[wk->wu.id] == PL_RYU) && ((Tech_Number) == 0x8015) && (Power_Level != 8)) {
            CP_Index[wk->wu.id][0]++;
            Lever_LR[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x3F0;
            if (Power_Level == 0xA) {
                CP_Index[wk->wu.id][1] = 1;
            } else {
                CP_Index[wk->wu.id][1] = 0;
            }
        } else {
            if (CP_No[wk->wu.id][0] == 0xA) {
                Rapid_Index[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x3F0;
                Lever_Pool[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x3F0;
            }
            if ((wk->player_number == PL_HUGO) && ((Tech_Number) == 0x8016)) {
                CP_Index[wk->wu.id][1] = 5;
            } else {
                if ((wk->player_number == PL_IBUKI) && ((Tech_Number) == 0x1F)) {
                    Reaction_Exit_Sub(wk);
                } else {
                    CP_Index[wk->wu.id][1]++;
                }
            }
        }
        return 0;
    }
}



s32 Command_Type_06(wk, Power_Level, Tech_Number, Ex_Shot)
PLW* wk;
s16 Power_Level;
u16 Tech_Number;
s16 Ex_Shot;
{
    s16 xx;
    xx = 0;
    if (Tech_Number & 0x8000) {
        if ((My_char[wk->wu.id] == PL_HUGO) && (Super_Arts[wk->wu.id] == 0)) {
            xx = 1;
        }
    }
    Lever_Buff[wk->wu.id] = Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]];
    CP_Index[wk->wu.id][2]++;
    if ((Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]]) == 0xFFFF) {
        Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        return 1;
    }
    return 0;
}



s32 Command_Type_01(wk, Power_Level, Ex_Shot)
PLW* wk;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][2]) {
    case 0:
        CP_Index[wk->wu.id][2]++;
        Timer_01[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 1] + 2;
        Lever_Pool[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3];
        Setup_Command_01(wk);
        if (wk->wu.rl_waza) {
            if (Lever_Pool[wk->wu.id] & 0xC) {
                Lever_Pool[wk->wu.id] ^= 0xC;
            }
        }
    case 1:
        if (wk->permited_koa & 2) {
            CP_Index[wk->wu.id][2]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id]++;
            break;
        }
    default:
        if (++Timer_00[wk->wu.id] < Timer_01[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Tech_Index[wk->wu.id] += 4;
            if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]] == 0x1C) {
                return 1;
            }
        }
        break;
    }
    return 0;
}



void Setup_Command_01(PLW* wk) {
    switch (Lever_Pool[wk->wu.id]) {
    case 2:
        Timer_00[wk->wu.id] = Lever_Store[wk->wu.id][0];
        break;
    default:
        Timer_00[wk->wu.id] = Lever_Store[wk->wu.id][2];
        break;
    }
}



void Check_Store_Lever(wk, Tech_Number, Next_Action, Next_Menu)
PLW* wk;
u16 Tech_Number;
s16 Next_Action;
s16 Next_Menu;
{
    s16 time;
    u16 lever;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
    time = Tech_Address[wk->wu.id][13] + 2;
    lever = Tech_Address[wk->wu.id][15];
    if (Check_Store_Direction(wk, lever, time) != 0) {
        CP_Index[wk->wu.id][0]++;
    } else {
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



s32 Check_Store_Direction(wk, lever, time)
PLW* wk;
u16 lever;
s16 time;
{
    if (wk->wu.rl_waza) {
        if (lever & 0xC) {
            lever ^= 0xC;
        }
    }
    switch (lever) {
    case 2:
        if (time <= Lever_Store[wk->wu.id][0]) {
            return 1;
        }
        break;
    case 8:
        if (time <= Lever_Store[wk->wu.id][1]) {
            return 1;
        }
        break;
    case 4:
        if (time <= Lever_Store[wk->wu.id][2]) {
            return 1;
        }
        break;
    }
    return 0;
}



s32 Select_Combo_Speed(PLW* wk) {
    s8 xx;
    s8 zz;
    xx = (u8)random_32_com();
    Lv = Setup_Lv18(8);
    Lv = Lv + CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Combo_Speed_Unit_Data[18][Lv][xx];
    }
    return zz = Combo_Speed_Unit_Data[wk->player_number][Lv][xx];
}



s32 Select_Reflection_Time(PLW* wk) {
    s8 Lv;
    s8 xx;
    xx = random_32_com();
    Lv = Setup_Lv18(Game_setting.level);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return Reflection_Time_Data[18][Lv][xx];
    }
    return ((const s8(*)[32])((const s8*)Reflection_Time_Data +
                              (s16)(My_char[wk->wu.id] * sizeof(Reflection_Time_Data[0]))))[Lv][xx];
}



s32 Setup_Lv04(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)Lv04_Time_Data[CC_Type][xx];
    for (i = 0; i < 3; i++) {
        if (Control_Time <= zz[i]) {
            return i;
        }
    }
    return 3;
}



s32 Setup_Lv08(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)((s8*)Lv08_Time_Data + (s8)(CC_Type * 42) + (s8)(xx * 14));
    for (i = 0; i < 7; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}



s32 Setup_Lv10(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)Lv10_Time_Data[CC_Type][xx];
    for (i = 0; i < 9; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}



s32 Setup_Lv18(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)Lv18_Time_Data[CC_Type][xx];
    for (i = 0; i < 17; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}



s32 Setup_VS_Catch_Data(PLW* wk) {
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return VS_Catch_Data[Lv];
}



s32 Setup_LP_Data(PLW* wk) {
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return LOOK_POSITION_Data[Lv][random_32_com()];
}



s32 Setup_WT_Data(PLW* wk) {
    Lv = Setup_Lv04(0);
    if (Break_Into_CPU == 2) {
        Lv = 3;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return Wait_Time_Data[Lv][random_16_com() & 7];
}



void Ck_Distance(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] < 0) {
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



s32 Ck_Distance_Height(PLW* wk) {
    s16 xx;
    xx = ((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos - wk->wu.xyz[1].disp.pos;
    if (xx < 0) {
        xx = -xx;
    }
    return xx;
}



s32 Ck_Area(PLW* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }
    return 3;
}



s32 Ck_Area_Shell(PLW* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Shell_Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }
    return 3;
}



void Ck_Distance_Lv(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Buff[wk->wu.id] = 8;
    } else {
        Lever_Buff[wk->wu.id] = 4;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



void Ck_Distance_LvJ(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Pool[wk->wu.id] = 9;
    } else {
        Lever_Pool[wk->wu.id] = 5;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



s32 Next_End(PLW* wk) {
    if (Check_Guard(wk) != 0) {
        return 1;
    }
    CP_Index[wk->wu.id][0] = -1;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
}



void Next_Another_Menu(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    if (Next_Action != 1) {
        CP_No[wk->wu.id][0] = Next_Action;
        Pattern_Index[wk->wu.id] = Next_Menu;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        Next_Be_Free(wk);
    }
}



void Reaction_Sub(wk, Reaction, Power_Level)
PLW* wk;
s16 Reaction;
s16 Power_Level;
{
    switch (Reaction & 0x7F) {
    case 9:
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;
    case 10:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else {
            if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
                Reaction_Exit_Sub(wk);
            }
        }
        break;
    case 11:
        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Setup_Follow(wk, Reaction & 0xFFF);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Setup_Follow(wk, Reaction & 0xFFF);
        }
        break;
    case 12:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;
    case 14:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;
    case 13:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (wk->permited_koa & 0x10) {
            if (Check_Meoshi_Attack(wk, Reaction, Power_Level) != 0) {
                break;
            }
        }
        Last_Eftype[wk->wu.id] = -1;
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            if (Stock_Hit_Flag[wk->wu.id]) {
                if ((CP_No[wk->wu.id][0] == 6) && (Pattern_Index[wk->wu.id] == 0)) {
                    CP_No[wk->wu.id][0] = Return_CP_No[wk->wu.id];
                    CP_Index[wk->wu.id][0] = Return_CP_Index[wk->wu.id];
                    CP_Index[wk->wu.id][1] = 0;
                    CP_Index[wk->wu.id][2] = 0;
                    CP_Index[wk->wu.id][3] = 0;
                    Pattern_Index[wk->wu.id] = Return_Pattern_Index[wk->wu.id];
                } else {
                    Reaction_Exit_Sub(wk);
                }
            } else {
                Next_End(wk);
            }
        }
        break;
    default:
        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        }
        else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}



s32 Check_Meoshi_Attack(wk, Reaction, Power_Level)
PLW* wk;
s16 Reaction;
s16 Power_Level;
{
    if (Last_Eftype[wk->wu.id] == wk->wu.cg_meoshi) {
        return 0;
    }
    if (wk->permited_koa & 0x10) {
        Last_Eftype[wk->wu.id] = wk->wu.cg_meoshi;
        M_Lv[wk->wu.id] = Get_Meoshi_Data(wk);
        if ((s16)Pattern_Index[wk->wu.id] != 0) {
            Return_CP_No[wk->wu.id] = CP_No[wk->wu.id][0];
            Return_CP_Index[wk->wu.id] = CP_Index[wk->wu.id][0] + 1;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Return_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
        }
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Pattern_Index[wk->wu.id] = 0;
        return 1;
    }
    return 0;
}



s32 Get_Meoshi_Data(PLW* wk) {
    u16 lever;
    u16 shot;
    lever = get_meoshi_lever(wk->wu.cg_meoshi);
    shot = get_meoshi_shot(wk->wu.cg_meoshi);
    if (wk->wu.rl_flag) {
        lever ^= 0xC;
    }
    return shot | lever;
}



void Reaction_Exit_Sub(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    if (CP_No[wk->wu.id][0] != 6) {
        Passive_Flag[wk->wu.id] = 0;
    }
}



/* provisional name */
s32 Check_Stock_Hit_Menu(wk, Menu)
PLW* wk;
s16 Menu;
{
    s32 hit;
    switch (Menu) {
    case 8:
        break;
    case 9:
        if (Stock_Hit_Flag[wk->wu.id] == 0) {
            return 1;
        }
        break;
    case 10:
        if (Stock_Hit_Flag[wk->wu.id] >> 2) {
            return 1;
        }
        break;
    case 11:
        if (Stock_Hit_Flag[wk->wu.id] >> 2) {
            return 1;
        }
        if (Stock_Hit_Flag[wk->wu.id] == 0) {
            return 1;
        }
        break;
    default:
        hit = Stock_Hit_Flag[wk->wu.id];
        if (hit == 0 || hit >> 2) {
            Setup_Follow(wk, Menu & 0xFFF);
            return -1;
        }
        break;
    }
    return 0;
}



void Check_First_Menu(PLW* wk) {
    if (CP_Index[wk->wu.id][0] == 0) {
        Combo_Speed[wk->wu.id] = 1;
    } else {
        Combo_Speed[wk->wu.id] = Select_Combo_Speed(wk);
    }
}



void Select_Active(PLW* wk) {
    s16 pl_id;
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = (u8)random_32_ex_com();
    if (Check_SA_Active(wk, &pl_id) != 0) {
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
            Lv = 2;
        }
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = Active_SA_Area0_Data[pl_id - 1][Lv][Rnd];
            break;
        case 1:
            Pattern_Index[wk->wu.id] = Active_SA_Area1_Data[pl_id - 1][Lv][Rnd];
            break;
        case 2:
            Pattern_Index[wk->wu.id] = Active_SA_Area2_Data[pl_id - 1][Lv][Rnd];
            break;
        default:
            Pattern_Index[wk->wu.id] = Active_SA_Area3_Data[pl_id - 1][Lv][Rnd];
            break;
        }
    } else {
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = Active_Area0_Data[wk->player_number][Lv][Rnd];
            break;
        case 1:
            Pattern_Index[wk->wu.id] = Active_Area1_Data[wk->player_number][Lv][Rnd];
            break;
        case 2:
            Pattern_Index[wk->wu.id] = Active_Area2_Data[wk->player_number][Lv][Rnd];
            break;
        default:
            Pattern_Index[wk->wu.id] = Active_Area3_Data[wk->player_number][Lv][Rnd];
            break;
        }
    }
}



/* provisional name */
void Check_Bullet_Counter(PLW* wk) {
    if (Bullet_No[wk->wu.id] != 0) {
        if (plw[wk->wu.id].bullet_hcnt == 0) {
            Bullet_No[wk->wu.id] = 0;
            Setup_Bullet_Counter(wk);
        } else {
            Pattern_Index[wk->wu.id] = 0;
            if (--Bullet_Counter[wk->wu.id] == 0) {
                Bullet_No[wk->wu.id] = 0;
                Setup_Bullet_Counter(wk);
            }
        }
        return;
    }
    if (plw[wk->wu.id].bullet_hcnt >= Bullet_Counter[wk->wu.id]) {
        Bullet_No[wk->wu.id] = 1;
        Bullet_Counter[wk->wu.id] = 5;
        Bullet_Counter[wk->wu.id] += random_32_com() & 3;
        Pattern_Index[wk->wu.id] = 0;
    }
}



s32 Check_SA_Active(wk, pl_id)
PLW* wk;
s16* pl_id;
{
    if (wk->sa->ok != -1) {
        return 0;
    }
    if (My_char[wk->wu.id] == PL_ORO) {
        if (plw[wk->wu.id].sa->kind_of_arts == 0) {
            return *pl_id = 3;
        }
        return *pl_id = 2;
    }
    if (My_char[wk->wu.id] == PL_YUN && plw[wk->wu.id].sa->kind_of_arts == 2) {
        return *pl_id = 1;
    }
    if (My_char[wk->wu.id] == 0xA && plw[wk->wu.id].sa->kind_of_arts == 2) {
        return *pl_id = 1;
    }
    if (My_char[wk->wu.id] == 0x12 && plw[wk->wu.id].sa->kind_of_arts == 2) {
        return *pl_id = 4;
    }
    return 0;
}



void Setup_Follow(wk, Follow_Type)
PLW* wk;
s16 Follow_Type;
{
    CP_No[wk->wu.id][0] = 3;
    CP_No[wk->wu.id][1] = Follow_Type;
    if (wk->wu.hf.hit.player == 0) {
        CP_No[wk->wu.id][2] = 0;
    } else {
        CP_No[wk->wu.id][2] = 1;
    }
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);
    Timer_00[wk->wu.id]++;
}



void Decide_Follow_Menu(PLW* wk) {
    s8 xx;
    const FOLLOW_MENU_1ST* Menu_Add_Ptr0;
    const FOLLOW_MENU_2ND* Menu_Add_Ptr1;
    Menu_Add_Ptr0 = Follow_Menu_1st_Unit_Data[wk->player_number];
    Rnd = (u8)random_32_com();
    xx = Menu_Add_Ptr0->select[CP_No[wk->wu.id][1]][CP_No[wk->wu.id][2]][Rnd];
    Menu_Add_Ptr1 = Follow_Menu_2nd_Unit_Data[wk->player_number];
    Pattern_Index[wk->wu.id] = Menu_Add_Ptr1->pattern[xx][Area_Number[wk->wu.id]];
}



s32 Select_Passive(PLW* wk) {
    u16 xx;
    if (VS_Tech[wk->wu.id] == 0xB) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    if (VS_Tech[wk->wu.id] == 0x1E) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Standing_Timer[wk->wu.id] = 0;
    Devide_Level(VS_Tech[wk->wu.id] >> 0xC);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 1;
    }
    VS_Tech[wk->wu.id] &= 0xFFF;
    Setup_Random(wk);
    switch (Area_Number[wk->wu.id]) {
    case 0:
        xx = Passive_A_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][0] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][0] = 0;
        break;
    case 1:
        xx = Passive_B_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][1] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][1] = 0;
        break;
    case 2:
        xx = Passive_C_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][2] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][2] = 0;
        break;
    default:
        xx = Passive_D_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][3] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][3] = 0;
        break;
    }
    Passive_Flag[wk->wu.id] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);
    if ((VS_Tech[wk->wu.id] == 0x19) || (VS_Tech[wk->wu.id] == 0x13) || (Timer_00[wk->wu.id] == 0)) {
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        CP_No[wk->wu.id][0] = 5;
    }
    return 1;
}



void Devide_Level(xx)
s16 xx;
{
    switch (xx) {
    case 0:
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        break;
    default:
        Lv = Setup_Lv08(2);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        break;
    }
}



void Setup_Random(PLW* wk) {
    if (VS_Tech[wk->wu.id] == 0x20) {
        Rnd = (u8)random_16_com() & 7;
        VS_Tech[wk->wu.id] = 0x1C;
    } else {
        Rnd = (u8)random_16_com();
        Rnd = Check_Dramatic(wk, wk->wu.id);
    }
}



s32 Check_Dramatic(wk, PL_id)
PLW* wk;
s16 PL_id;
{
    if (plw[wk->wu.id].sa->ok) {
        return Rnd | 8;
    }
    if ((plw[PL_id].wu.vital_new <= 0x30) || (plw[PL_id ^ 1].wu.vital_new <= 0x30)) {
        return Rnd | 8;
    }
    return Rnd;
}



s32 Check_Passive(PLW* wk) {
    WORK* em;
    if ((Counter_Attack[wk->wu.id]) || (Pierce_Menu[wk->wu.id])) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    if (Check_Blow_Off(wk, em, 0) != 0) {
        *CP_No[wk->wu.id] = 0xE;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        return -1;
    }
    if (Check_Thrown(wk, em) != 0) {
        if (Select_Passive(wk) != -1) {
            return 1;
        }
    }
    if (Check_Shell(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return Check_Guard(wk);
    }
    if (Check_Lie(wk) == 1) {
        return 1;
    }
    if (PL_Status[em->routine_no[1]] == 0) {
        return Check_Shell(wk);
    }
    Passive_Mode = 4;
    if (Ck_Passive_Term(wk) != 0) {
        if (Select_Passive(wk) != -1) {
            return 1;
        }
    }
    if (Check_Guard(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return 0;
    }
    Passive_Mode = 0;
    if (Ck_Passive_Term(wk) != 0) {
        return Select_Passive(wk);
    }
    return 0;
}



s32 Check_Guard(PLW* wk) {
    WORK* em;
    s16 xx;
    s16 zz;
    em = (WORK*)wk->wu.target_adrs;
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        return 0;
    }
    Lv = Setup_Lv10(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_16_com();
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0xA;
    }
    zz = Setup_EM_Rank_Index(wk);
    if (Guard_Data[zz][Lv][Rnd] == 3) {
        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        return 0;
    }
    if (Check_Flip_Term(wk) != 0) {
        Next_Be_Flip(wk, 0);
    } else {
        Next_Be_Guard(wk, em, Guard_Data[zz][Lv][random_16_ex_com()]);
    }
    return 1;
}



s32 Check_Makoto(PLW* wk) {
    if (wk->player_number != 0x11) {
        return 0;
    }
    if (wk->sa->ok != -1) {
        return 0;
    }
    if (((PLW*)((s8*)plw + (s16)(wk->wu.id * sizeof(PLW))))->sa->kind_of_arts != 2) {
        return 0;
    }
}



s32 Check_Flip_Term(PLW* wk) {
    s16 xx;
    if (Check_Flip_Tech((WORK*)wk->wu.target_adrs) == 0) {
        return 0;
    }
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    xx = Setup_EM_Rank_Index(wk);
    if (Rnd >= (Flip_Data[xx][Lv])) {
        return 0;
    }
    return 1;
}



s32 Setup_EM_Rank_Index(PLW* wk) {
    if (EM_Rank != 0) {
        return 0x12;
    }
    return wk->player_number;
}



s32 Flip_Term_Correct(PLW* wk) {
    s16 xx = 0;
    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        xx++;
    }
    if ((PL_Wins[wk->wu.id]) < (PL_Wins[wk->wu.id ^ 1])) {
        xx += 2;
    }
    if (Counter_hi < 0xF) {
        xx += 1;
    }
    if (Check_Makoto(wk) != 0) {
        xx += 20;
    }
    return xx;
}



void Next_Be_Guard(wk, em, Type_Of_Guard)
PLW* wk;
WORK* em;
s16 Type_Of_Guard;
{
    CP_No[wk->wu.id][0] = 7;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 10;
    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = Type_Of_Guard;
    Check_Guard_Type(wk, em);
}



s32 Check_Flip_Tech(WORK* em) {
    if ((My_char[COM_id] != PL_GOUKI2) && (em->kind_of_waza & 0xF8)) {
        return 0;
    }
    if (em->kind_of_waza == 0) {
        return 0;
    }
    if (em->kind_of_waza == 1) {
        return 0;
    }
    return 1;
}



void Next_Be_Flip(wk, xx)
PLW* wk;
s16 xx;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    CP_No[wk->wu.id][0] = 0xC;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 9;
    Flip_Counter[wk->wu.id] = 0;
    if (xx) {
        if ((em->pat_status == 0x21) || (em->pat_status == 0x20)) {
            Lever_Buff[wk->wu.id] = 2;
        } else {
            Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        }
        CP_No[wk->wu.id][2] = 1;
        Timer_01[wk->wu.id] = xx;
    } else {
        Check_Flip_GO(wk, 0);
    }
}



s32 Check_Diagonal_Shell(PLW* wk) {
    WORK* em;
    s16 i;
    WORK_Other* tmw;
    s32 n;
    s32 (*get_adrs)();
    Lv = Setup_Lv08(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_16_com();
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if (Rnd > VS_Diagonal_Shell_Data[Lv]) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    i = 0;
    get_adrs = (s32 (*)())get_vs_shell_adrs;
    n = 8;
    goto test;
    for (;;) {
        if ((get_adrs(em, em->id, i, &tmw) == 0) && (get_adrs(&wk->wu, em->id, i, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            goto next;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            goto next;
        }
        if (Check_Behind(wk, tmw)) {
            goto next;
        }
        if (tmw->wu.charset_id == 2) {
            goto next;
        }
        if (Check_Ignore_Shell2(tmw)) {
            return 1;
        }
    next:
        i++;
    test:
        if (i >= n) {
            break;
        }
    }
    return 0;
}



s32 Check_Ignore_Shell2(WORK_Other* tmw) {
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type <= 0x27)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type <= 0xF)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type <= 0x50)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type <= 0x7E)) {
        return 1;
    }
    return 0;
}



s32 Check_Shell(PLW* wk) {
    WORK* em;
    WORK_Other* tmw;
    s16 i;
    s32 ix;
    s16 xx;
    if (Shell_Ignore_Timer[wk->wu.id]) {
        Shell_Ignore_Timer[wk->wu.id]--;
        return 0;
    }
    if (CP_No[wk->wu.id][0] == 8) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, ix = i, &tmw) == 0) && (get_vs_shell_adrs(&wk->wu, em->id, ix, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            continue;
        }
        if (tmw->wu.routine_no[0] != 1) {
            continue;
        }
        if (Check_Behind(wk, tmw)) {
            continue;
        }
        if (tmw->wu.charset_id == 2) {
            continue;
        }
        if (Check_Ignore_Shell(tmw)) {
            continue;
        }
        xx = Compute_Hit_Time(wk, tmw);
        if (Decide_Shell_Guard(wk, tmw)) {
            return 0;
        }
        CP_No[wk->wu.id][0] = 8;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Shell_Address[wk->wu.id] = (u32*)tmw;
        Guard_or_Jump_VS_Shell(wk, tmw, xx);
        return 1;
    }
}



s32 Check_Ignore_Shell(WORK_Other* tmw) {
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type <= 0x27)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type <= 0xF)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type <= 0x50)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type <= 0x7E)) {
        return 1;
    }
    return 0;
}



s32 Compute_Hit_Time(PLW* wk, WORK_Other* tmw) {
    s32 lx1;
    s16 x2;
    lx1 = get_att_head_position(&tmw->wu);
    lx1 <<= 16;
    lx1 -= wk->wu.xyz[0].cal;
    x2 = lx1 / tmw->wu.mvxy.a[0].sp;
    if (x2 < 0) {
        return (s16)(x2 * -1);
    }
    return x2;
}



s32 Decide_Shell_Guard(PLW* wk, WORK_Other* tmw) {
    s16 xx;
    Lv = Setup_Lv10(0);
    if (Break_Into_CPU == 2) {
        Lv = 9;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_32_com();
    xx = Setup_EM_Rank_Index(wk);
    if (Shell_Guard_Data[xx][Lv] > Rnd) {
        return 0;
    }
    Shell_Ignore_Timer[wk->wu.id] = 0x3C;
    return 1;
}



void Guard_or_Jump_VS_Shell(wk, tmw, xx)
PLW* wk;
WORK_Other* tmw;
s16 xx;
{
    if (xx <= Shell_Dodge_Data[0][wk->player_number]) {
        if (Check_Flip_Term(wk) != 0) {
            Pattern_Index[wk->wu.id] = 9;
        } else {
            Pattern_Index[wk->wu.id] = 0;
        }
    } else {
        Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, Shell_Reaction_Type_Data[tmw->wu.type]);
    }
    Setup_Shell_Disposal(wk, tmw);
}



void Setup_Shell_Disposal(PLW* wk, WORK_Other* tmw) {
    switch (Pattern_Index[wk->wu.id]) {
    case 0:
        Next_Be_Shell_Guard(wk, &tmw->wu);
        break;
    case 9:
        Passive_Flag[wk->wu.id] = 1;
        break;
    case 10:
        Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, 0);
        if (Pattern_Index[wk->wu.id] == 0) {
            Next_Be_Shell_Guard(wk, &tmw->wu);
        }
        break;
    }
}



void Next_Be_Shell_Guard(PLW* wk, WORK* tmw) {
    CP_No[wk->wu.id][0] = 9;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 0xA;
    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = 0;
    Check_Guard_Type(wk, tmw);
}



s32 Decide_Shell_Reaction(wk, tmw, dir_step)
PLW* wk;
WORK_Other* tmw;
u16 dir_step;
{
    if (dir_step == 0xFF) {
        return 0;
    }
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 4;
    }
    Rnd = random_16_com();
    return VS_Shell_Active_Data[wk->player_number][dir_step][Lv][Rnd];
}


/* provisional name */
s32 calc_abs_diff(s16 a, s16 b) {
    a -= b;
    if (a < 0) {
        a = -a;
    }
    return a;
}



s32 Check_Behind(PLW* wk, WORK_Other* tmw) {
    if (!wk->wu.rl_waza) {
        if (wk->wu.xyz[0].disp.pos < tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
    if (wk->wu.xyz[0].disp.pos > tmw->wu.xyz[0].disp.pos) {
        return 1;
    }
    return 0;
}



s32 Ck_Distance_XX(PLW* wk) {
    if (Ck_Distance_Wall(wk) == 0) {
        return 0;
    }
    if (PL_Distance[wk->wu.id] >= Distance_XX_Data[(s8)wk->player_number][0] &&
        PL_Distance[wk->wu.id] <= Distance_XX_Data[(s8)wk->player_number][1]) {
        Distance_XX_Index[wk->wu.id] = Distance_XX_Data[(s8)wk->player_number][2];
        return 1;
    }
    return 0;
}



/* provisional name */
s32 Ck_Distance_Wall(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    s16 xx;
    if (wk->wu.rl_waza) {
        xx = bg_w.bgw[1].r_limit2 + bg_w.pos_offset - em->xyz[0].disp.pos;
        if (xx > 96) {
            return 1;
        }
        return 0;
    }
    xx = em->xyz[0].disp.pos - bg_w.bgw[1].l_limit2 + bg_w.pos_offset;
    if (xx > 96) {
        return 1;
    }
    return 0;
}



void Setup_Lever_LR(wk, PL_id, Lever)
PLW* wk;
s16 PL_id;
s16 Lever;
{
    if (Lever == 0) {
        Lever_LR[PL_id] = 0;
    } else {
        if (Lever & 0x1000) {
            Lever_LR[PL_id] = 1;
        }
        else if (Lever & 0x2000) {
            Lever_LR[PL_id] |= 2;
        }
        if (Lever & 0x4000) {
            Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 0);
        } else {
            if (Lever & 0x8000) {
                Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 1);
            }
        }
    }
}



s32 Check_Exit_Term(wk, em, Exit_No)
PLW* wk;
WORK* em;
s16 Exit_No;
{
    s16 xx;
    if (VS_Jump_Term(wk, em, &xx) != 0) {
        return xx;
    }
    return Exit_Term_Tbl[Exit_No](wk, em);
}



s32 VS_Jump_Term(wk, em, xx)
PLW* wk;
WORK* em;
s16* xx;
{
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    switch (My_char[em->id]) {
    case PL_ALEX:
        if (Check_F_Cross_Chop(wk, em, 0xF) != 0) {
            return *xx = 3;
        }
        break;
    case PL_YUN:
    case PL_YANG:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2b, -1, -1) != 0) {
            return *xx = 2;
        }
        break;
    case PL_NECRO:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2A, -1, -1) != 0) {
            return *xx = 2;
        }
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 4) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case PL_ELENA:
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 5) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case PL_ORO:
        if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1) != 0) {
            return *xx = 3;
        }
        break;
    }
    return 0;
}



s32 Exit_Term_0000(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}


s32 Exit_Term_0001(PLW* wk, WORK* em) {
    return 1;
}



s32 Exit_Term_0002(PLW* wk, WORK* em) {
    if (em->routine_no[1] == 2) {
        return 1;
    }
    if (em->id != 0xD) {
        return 1;
    }
    return 0;
}



s32 Exit_Term_0003(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0xA;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



s32 Exit_Term_0004(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 1;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



s32 Exit_Term_0005(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 5;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



s32 Exit_Term_0006(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x3C;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



s32 Exit_Term_0007(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
    default:
        if (Check_Drop_Term(em, 0x28) != 0) {
            if (Area_Number[wk->wu.id] >= 3) {
                return 1;
            }
            VS_Tech[wk->wu.id] = 0x1A;
            return -1;
        }
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



s32 Exit_Term_0008(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0xb4;
    default:
        if ((wk->wu.old_pos[1] == 0) && (wk->wu.xyz[1].disp.pos == 0) && (wk->wu.routine_no[1] != 4)) {
            return 1;
        }
        if (--Timer_00[wk->wu.id] == 0) {
            return 1;
        }
    }
    return 0;
}



s32 Check_Drop_Term(em, Y)
WORK* em;
s16 Y;
{
    if (em->mvxy.a[1].real.h >= 0) {
        return 0;
    }
    if (em->xyz[1].disp.pos >= Y) {
        return 0;
    }
    return 1;
}



s32 Check_SHINRYU(PLW* wk) {
    PLW* em;
    em = (PLW*)wk->wu.target_adrs;
    if (em->sa->ok != -1) {
        return 0;
    }
    if (My_char[em->wu.id] != 0xB) {
        return 0;
    }
    if (plw[em->wu.id].sa->kind_of_arts != 1) {
        return 0;
    }
    return 1;
}



void Check_BOSS(wk, Next_Action, Next_Menu)
PLW* wk;
u32 Next_Action;
s16 Next_Menu;
{
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Break_Into_CPU == 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



void Check_BOSS_EX(wk, Next_Action, Next_Menu)
PLW* wk;
u32 Next_Action;
s16 Next_Menu;
{
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Break_Into_CPU != 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



void ETC_Term(wk, Exit_No, Next_Action, Next_Menu)
PLW* wk;
s16 Exit_No;
u32 Next_Action;
s16 Next_Menu;
{
    s16 xx;
    WORK* em = (WORK*)wk->wu.target_adrs;
    xx = ETC_Term_Tbl[Exit_No](wk, em);
    if (xx == -1) {
        return;
    }
    if (xx) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



s32 ETC_Term_0000(PLW* wk, WORK* em) {
    if (Check_VS_Squat(wk, em, 0x1D, 0x21, 0x20) != 0) {
        return 1;
    }
    return 0;
}



s32 ETC_Term_0001(PLW* wk, WORK* em) {
    if (wk->sa->ok != -1) {
        return 1;
    }
    if (My_char[wk->wu.id] != PL_ORO) {
        return 1;
    }
    if (!((PLW*)((s8*)plw + (s16)(wk->wu.id * sizeof(PLW))))->sa->kind_of_arts) {
        return 0;
    }
}



s32 ETC_Term_0002(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        return 1;
    }
    return 0;
}



s32 ETC_Term_0003(PLW* wk, WORK* em) {
    if ((em->pat_status != 0x20) && (em->pat_status != 0x21) && (em->pat_status != 2)) {
        return 1;
    }
    return 0;
}



s32 ETC_Term_0004(PLW* wk, WORK* em) {
    if (em->vital_new >= 0x50) {
        return 0;
    }
    if (plw[wk->wu.id].wu.vital_new < 0x78) {
        return 0;
    }
    return 1;
}



s32 ETC_Term_0005(PLW* wk, WORK* em) {
    if (em->vital_new < plw[wk->wu.id].wu.vital_new) {
        return 1;
    }
    return 0;
}



s32 ETC_Term_0006(PLW* wk, WORK* em) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = 0x78;
        /* fall through */
    case 1:
        if (--Timer_00[wk->wu.id] == 0) {
            return 1;
        }
        if (PL_Distance[wk->wu.id] < 0x70) {
            return 1;
        }
        Lever_Buff[wk->wu.id] = 0x40;
        return -1;
    default:
        break;
    }
}



s32 ETC_Term_0007(PLW* wk, WORK* em) {
    if (((PLW*)((s8*)plw + (s16)(wk->wu.id * sizeof(PLW))))->sa->kind_of_arts != 2) {
        return 0;
    }
}

s32 ETC_Term_0008(PLW* wk) {
    if (((PLW*)((s8*)plw + (s16)(wk->wu.id * sizeof(PLW))))->sa->kind_of_arts != 1) {
        return 0;
    }
}

s32 ETC_Term_0009(PLW* wk)
{
    s16 ofs;

    /* returns the (s16-truncated) byte offset of this player's plw[] entry, or 0 */
    ofs = (s16)(wk->wu.id * sizeof(PLW));
    if (((PLW *)((char *)plw + ofs))->sa->kind_of_arts != 0) {
        ofs = 0;
    }
    return ofs;
}



/* provisional name */
void Setup_Com_Max_Range(void) {
    s16 limit;
    s16 xx;
    u8 type = CC_Type;
    if (type == 2) {
        limit = Lv18_Time_Data[type][Game_setting.level][14];
    } else {
        limit = Lv18_Time_Data[type][Game_setting.level][16];
    }
    limit += 20;
    xx = Lv18_Time_Data[type][8][type == 2 ? 14 : 16] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv10_Time_Data[type][0][type == 2 ? 7 : 8] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv08_Time_Data[type][6] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv08_Time_Data[type][13] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv08_Time_Data[type][20] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv04_Time_Data[type][0][2] + 20;
    if (limit < xx) {
        limit = xx;
    }
    Limit_Time = limit;
}



/* provisional name */
s32 Ck_Passive_Term(PLW* wk) {
    PASSIVE_X = 0;
    Passive_jmp_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
    return PASSIVE_X;
}



s32 KEN_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    switch (Area_Number[wk->wu.id] + Passive_Mode) {
    case 0:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 1:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 2:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 3:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                return 1;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 16)) {
            break;
        }
        if (Check_Personal_Action(wk, em)) {
            break;
        }
        break;
    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                return 1;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 32)) {
            break;
        }
        if (Check_Personal_Action(wk, em)) {
            break;
        }
        break;
    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 64)) {
            break;
        }
        if (Check_Personal_Action(wk, em)) {
            break;
        }
        break;
    default:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_D(wk)) {
                break;
            }
        } else {
            if (Check_PL_Unit_DS(wk)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_Personal_Action(wk, em)) {
            break;
        }
        break;
    }
}



s32 HUGO_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    switch (Passive_Mode + Area_Number[wk->wu.id]) {
    case 0:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 1:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 2:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 3:
        if (Check_Dash(wk, em, 1)) {
            break;
        }
        break;
    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                return 1;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 16)) {
            break;
        }
        break;
    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                return 1;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 32)) {
            break;
        }
        break;
    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        if (Check_VS_Jump(wk, em, 64)) {
            break;
        }
        break;
    default:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_D(wk)) {
                break;
            }
        } else {
            if (Check_PL_Unit_DS(wk)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        break;
    }
}



void GILL_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    switch (Passive_Mode + Area_Number[wk->wu.id]) {
    case 0:
        Check_Dash(wk, em, 1);
        break;
    case 1:
        Check_Dash(wk, em, 1);
        break;
    case 2:
        Check_Dash(wk, em, 1);
        break;
    case 3:
        Check_Dash(wk, em, 1);
        break;
    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        Check_VS_Jump(wk, em, 16);
        break;
    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        Check_VS_Jump(wk, em, 32);
        break;
    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }
            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }
            if (Check_After_Attack(wk, em, 28)) {
                break;
            }
            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }
        Check_VS_Jump(wk, em, 64);
        break;
    default:
        if (Attack_Flag[wk->wu.id]) {
            Check_PL_Unit_D(wk);
            break;
        }
        if (Check_PL_Unit_DS(wk)) {
            break;
        }
        if (Check_Stand(wk, em, 4105)) {
            break;
        }
        Check_VS_Squat(wk, em, 7, 33, 32);
        break;
    }
}



s32 Check_Special_Technique(PLW* wk, WORK* em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option, s16 Option2) {
    u8 xx;
    if (Option == 8 && Attack_Flag[wk->wu.id] != 0) {
        return 0;
    }
    if (VS_Technique != 23 && Check_Attack_Direction(wk, em)) {
        return 0;
    }
    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }
    xx = em->kind_of_waza & 0xF8;
    if (xx == Kind_of_Tech && (em->sp_tech_id == SP_Tech_ID)) {
        if ((Option2 == -1 || !(Option2 & 8))) {
            if (Option2 == (em->kind_of_waza & 6)) {
                Last_Attack_Counter[(wk->wu.id)] = Attack_Counter[(wk->wu.id)];
                return 0;
            }
        } else if (!((Option2 & 6) & (em->kind_of_waza & 6))) {
            return 0;
        }
        if (Option == 8) {
            Counter_Attack[(wk->wu.id)] = 1;
        }
        if (Option == 1) {
            Counter_Attack[(wk->wu.id)] = 1;
        }
        VS_Tech[wk->wu.id] = VS_Technique;
        return PASSIVE_X = 1;
    }
    return 0;
}



s32 Check_Attack_Direction(PLW* wk, WORK* em) {
    if (wk->wu.xyz[0].disp.pos < em->xyz[0].disp.pos) {
        if (em->xyz[0].disp.pos > em->old_pos[0]) {
            return 1;
        }
    } else if (em->xyz[0].disp.pos < em->old_pos[0]) {
        return 1;
    }
    return 0;
}



/* provisional name */
/* provisional name */
s32 Check_Special_Tech_ID(PLW* wk, WORK* em, s16 VS_Technique, u8 SP_Tech_ID, s16 Option) {
    if (Option == 8 && Attack_Flag[wk->wu.id]) {
        return 0;
    }
    if (em->kind_of_waza & 0xF8) {
        return 0;
    }
    if (em->sp_tech_id == SP_Tech_ID) {
        Counter_Attack[wk->wu.id] = 1;
        VS_Tech[wk->wu.id] = VS_Technique;
        return PASSIVE_X = 1;
    }
    return 0;
}



s32 Check_VS_Jump(wk, em, Option, Height)
PLW* wk;
PLW* em;
s16 Option;
s16 Height;
{
    if (em->wu.routine_no[1] == 1) {
        return 0;
    }
    if (em->wu.sp_tech_id == 33) {
        return 0;
    }
    if (Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]) {
        Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]--;
        return 0;
    }
    if (em->wu.mvxy.a[1].real.h < 0 && em->wu.xyz[1].disp.pos <= Height) {
        return 0;
    }
    if (Check_Specific_Term(wk, &em->wu, 4099, 14, 20, 26)) {
        return Counter_Attack[wk->wu.id] = 1;
    }
    if (em->wu.xyz[1].disp.pos == 0) {
        return 0;
    }
    if (em->wu.xyz[1].disp.pos < 32 && em->wu.mvxy.a[1].real.h > 0) {
        return 0;
    }
    if (em->micchaku_flag) {
        VS_Tech[wk->wu.id] = 18;
        return PASSIVE_X = 1;
    }
    if (Check_Specific_Term(wk, &em->wu, 18, 22, 28, 16)) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 Check_Jump_Counter(PLW* wk, PLW* em, s16 Option, s16 Height) {
    if (em->wu.routine_no[1] == 1) {
        return 0;
    }
    if (em->wu.sp_tech_id == 33) {
        return 0;
    }
    if (Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]) {
        Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]--;
        return 0;
    }
    if (em->wu.mvxy.a[1].real.h < 0 && em->wu.xyz[1].disp.pos <= Height) {
        return 0;
    }
    if (Check_Attack_Direction(wk, &em->wu)) {
        return 0;
    }
    if (Check_Specific_Term(wk, &em->wu, 4099, 14, 20, 26)) {
        return Counter_Attack[wk->wu.id] = 1;
    }
    return 0;
}



/* provisional name */
s32 Check_Rolling(PLW* wk, WORK* em) {
    if (em->pat_status != 34) {
        return 0;
    }
    if (Check_Attack_Direction(wk, em)) {
        VS_Tech[wk->wu.id] = 6;
    } else {
        VS_Tech[wk->wu.id] = 5;
    }
    return PASSIVE_X = 1;
}



s32 Check_Personal_Action(PLW* wk, WORK* em) {
    if (em->routine_no[1] != 4) {
        return 0;
    }
    if (em->routine_no[2] != 30) {
        return 0;
    }
    VS_Tech[wk->wu.id] = 4105;
    return PASSIVE_X = 1;
}



s32 Check_Specific_Term(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01, u8 Status_02) {
    VS_Tech[wk->wu.id] = VS_Technique;
    if (em->pat_status == Status_00) {
        return PASSIVE_X = 1;
    }
    if (em->pat_status == Status_01) {
        return PASSIVE_X = 1;
    }
    if (em->pat_status == Status_02) {
        return PASSIVE_X = 1;
    }
    return 0;
}



s32 Check_Dash(PLW* wk, WORK* em, s16 VS_Technique) {
    if ((em->routine_no[1] == 0) && (em->routine_no[2] == 5) && (em->routine_no[3] != 0)) {
        VS_Tech[wk->wu.id] = VS_Technique;
        return PASSIVE_X = 1;
    }
    return 0;
}



s32 Check_Limited_Attack(PLW* wk, WORK* em, s16 VS_Technique, u8 PL_Status, s8 Status_00, s16 Limit_Number) {
    s16 xx;
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }
    if ((em->pat_status != PL_Status) || em->kind_of_waza != Status_00) {
        return 0;
    }
    xx = (em->cg_ix / em->cgd_type);
    if ((((PLW*)em)->player_number == 0x12) && (VS_Technique == 7)) {
        Limit_Number += 1;
    }
    if ((((PLW*)em)->player_number == PL_YANG) && (VS_Technique == 7)) {
        Limit_Number += 1;
    }
    if ((((PLW*)em)->player_number == PL_YUN) && (VS_Technique == 7)) {
        Limit_Number += 2;
    }
    if (xx > Limit_Number) {
        return 0;
    }
    VS_Tech[wk->wu.id] = VS_Technique;
    Limited_Flag[wk->wu.id] = 1;
    Counter_Attack[wk->wu.id] = 1;
    return PASSIVE_X = 1;
}



s32 Check_Limited_Jump_Attack(PLW* wk, WORK* em, u8 PL_Status, s8 Status_00) {
    if ((em->pat_status != PL_Status) || (em->kind_of_waza != Status_00)) {
        return 0;
    }
    return 1;
}



s32 Check_Stand(PLW* wk, WORK* em, s16 VS_Technique) {
    if (Attack_Flag[wk->wu.id]) {
        return 0;
    }
    if (em->routine_no[1] != 0) {
        return 0;
    }
    if ((Standing_Timer[wk->wu.id] += 1) < Standing_Master_Timer[wk->wu.id]) {
        return 0;
    }
    Standing_Master_Timer[wk->wu.id] = Setup_Next_Stand_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;
    return PASSIVE_X = 1;
}



s32 Setup_Next_Stand_Timer(PLW* wk) {
    if (EM_Rank != 0) {
        return Standing_Time_Data[18][Area_Number[wk->wu.id]][(random_16_com() & 7)];
    } else {
        return Standing_Time_Data[wk->player_number][Area_Number[wk->wu.id]][(random_16_com() & 7)];
    }
}



/* provisional name */
s32 Check_Turn_Over(PLW* wk, WORK* em, s16 VS_Technique) {
    if (!Attack_Flag[wk->wu.id]) {
        if (!em->routine_no[1]) {
            if (!em->xyz[1].disp.pos) {
                if (Ck_Distance_XX(wk) != 0) {
                    if (--Turn_Over_Timer[wk->wu.id] != 0) {
                        return 0;
                    }
                    Turn_Over_Timer[wk->wu.id] = 90;
                    Turn_Over[wk->wu.id] = 1;
                    VS_Tech[wk->wu.id] = VS_Technique;
                    return PASSIVE_X = 1;
                }
            }
        }
    }
    Turn_Over_Timer[wk->wu.id] = 1;
    return 0;
}



s32 Check_VS_Squat(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01) {
    if (Attack_Flag[wk->wu.id]) {
        return Squat_Timer[wk->wu.id] = 0;
    }
    if (em->routine_no[1] != 0) {
        return Squat_Timer[wk->wu.id] = 0;
    }
    if (em->xyz[1].disp.pos) {
        return Squat_Timer[wk->wu.id] = 0;
    }
    if (em->pat_status != Status_00 && em->pat_status != Status_01) {
        return Squat_Timer[wk->wu.id] = 0;
    }
    if ((Squat_Timer[wk->wu.id] += 1) < Squat_Master_Timer[wk->wu.id]) {
        return 0;
    }
    Squat_Master_Timer[wk->wu.id] = Setup_Next_Squat_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;
    return PASSIVE_X = 1;
}



s32 Setup_Next_Squat_Timer(PLW* wk) {
    return Squat_Time_Data[Setup_Lv08(0)][(random_16_com() & 7)];
}



s32 Check_Thrown(PLW* wk, WORK* em) {
    s16 Rnd;
    s16 x;
    if (em->xyz[1].disp.pos) {
        return 0;
    }
    x = Setup_VS_Catch_Data(wk);
    Rnd = random_32_com();
    if (x < Rnd) {
        return 0;
    }
    switch (Area_Number[wk->wu.id]) {
    case 0:
        if (Check_Catch(wk, em, 25)) {
            return 1;
        }
        break;
    case 1:
        if (Check_Catch(wk, em, 25)) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}



s32 Check_Catch(PLW* wk, WORK* em, s16 VS_Technique) {
    u16 xx;
    if (Demo_Flag == 0) {
        return 0;
    }
    if (em->routine_no[1] != 0) {
        return 0;
    }
    if (em->xyz[1].disp.pos) {
        return 0;
    }
    if (wk->wu.id == 0) {
        xx = p2sw_0;
    } else {
        xx = p1sw_0;
    }
    if (wk->wu.rl_waza) {
        if (!(xx & 4)) {
            return 0;
        }
    } else if (!(xx & 8)) {
        return 0;
    }
    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;
    return PASSIVE_X = 1;
}



/* provisional name */
s32 Check_Lie_Reset(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Blow_Off(wk, em, 0)) {
        return;
    }
    if (Check_Specific_Term(wk, em, 0, 38, 38, 38)) {
        return;
    }
    return Lie_Flag[wk->wu.id] &= 0x80;
}



/* provisional name */
s32 Check_Down_Term(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Blow_Off(wk, em, 0)) {
        return 1;
    }
    if (Check_Specific_Term(wk, em, 0, 38, 38, 38)) {
        return 1;
    }
    return 0;
}



s32 Check_Lie(PLW* wk) {
    WORK* em;
    PLW* enemy;
    em = (WORK*)wk->wu.target_adrs;
    enemy = (PLW*)wk->wu.target_adrs;
    if (Check_Faint(wk, enemy, 2)) {
        return Select_Passive(wk);
    }
    if (Check_Specific_Term(wk, em, 0, 38, 38, 38)) {
        return Select_Passive(wk);
    }
    return 0;
}



s32 Check_Faint(PLW* wk, PLW* enemy, s16 VS_Technique) {
    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;
    if ((enemy->wu.routine_no[1] == 1) && (enemy->wu.routine_no[2] == 25)) {
        return 1;
    }
    return Counter_Attack[wk->wu.id] = 0;
}



s32 Check_Blow_Off(PLW* wk, WORK* em, s16 VS_Technique) {
    if (em->routine_no[1] != 1) {
        return 0;
    }
    if (PL_Blow_Off_Data[em->routine_no[2]] == 0) {
        return 0;
    }
    if (em->xyz[1].disp.pos == 0) {
        return 0;
    }
    VS_Tech[(wk->wu.id)] = VS_Technique;
    return PASSIVE_X = 1;
}



s32 Check_After_Attack(PLW* wk, WORK* em, s16 VS_Technique) {
    u8 xx;
    if (CP_No[wk->wu.id][0] == 7) {
        return 0;
    }
    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }
    if (em->xyz[1].disp.pos) {
        return 0;
    }
    if (em->routine_no[1] != 4) {
        return 0;
    }
    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    if ((*(volatile u8*)&em->kind_of_waza & 0x20) == 0 && (*(volatile u8*)&em->kind_of_waza & 0x30) == 0 &&
        (*(volatile u8*)&em->kind_of_waza & 0x28) == 0 && (*(volatile u8*)&em->kind_of_waza & 0x38) == 0 &&
        (*(volatile u8*)&em->kind_of_waza & 8) == 0) {
        xx = *(volatile u8*)&em->kind_of_waza & 6;
        if (xx == 0) {
            return 0;
        }
        if (xx == 2) {
            return 0;
        }
    }
    VS_Tech[wk->wu.id] = VS_Technique;
    return PASSIVE_X = 1;
}



s32 Check_F_Cross_Chop(PLW* wk, WORK* em, s16 VS_Technique) {
    if (Last_Attack_Counter[wk->wu.id] == (&Attack_Counter[0])[wk->wu.id]) {
        return 0;
    }
    if (*(volatile u8*)&em->kind_of_waza != 4) {
        return 0;
    }
    if (*(volatile u8*)&em->pat_status != 0x16 && *(volatile u8*)&em->pat_status != 0x14 &&
        *(volatile u8*)&em->pat_status != 0x1A && *(volatile u8*)&em->pat_status != 0x1C) {
        return 0;
    }
    VS_Tech[wk->wu.id] = VS_Technique;
    Counter_Attack[wk->wu.id] = 1;
    return PASSIVE_X = 1;
}



/* Opponent-specific passive check (table AS): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_AS(PLW* wk) {
    Passive_AS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }
    if (Check_Rolling(wk, em)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, 0)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_AS(PLW* wk) {
    return 0;
}



s32 VS_HUGO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 14, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 28, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_AS(PLW* wk) {
    return 0;
}



s32 VS_MAKOTO_AS(PLW* wk) {
    return 0;
}



s32 VS_Q_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NO12_AS(PLW* wk) {
    return 0;
}



s32 VS_REMY_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table A): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_A(PLW* wk) {
    Passive_A_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 25, 24, 22, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }
    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 25, 24, 74, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 40, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 17, 24, 24, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_HUGO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 24, 26, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 18, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 19, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }
    if (Check_Rolling(wk, em)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 13, 64, 47, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_MAKOTO_A(PLW* wk) {
    return 0;
}



s32 VS_Q_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NO12_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_REMY_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table BS): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_BS(PLW* wk) {
    Passive_BS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }
    if (Check_Rolling(wk, em)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_BS(PLW* wk) {
    return 0;
}



s32 VS_HUGO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 28, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 76, -1, 0)) {
        return 1;
    }
    return 0;
}



s32 VS_MAKOTO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 92, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_Q_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NO12_BS(PLW* wk) {
    return 0;
}



s32 VS_REMY_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table B): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_B(PLW* wk) {
    Passive_B_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 25, 24, 22, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }
    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 31, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 25, 24, 74, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 40, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 17, 24, 24, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_HUGO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 24, 26, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 18, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 19, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 20, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }
    if (Check_Rolling(wk, em)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 5, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 13, 64, 47, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 76, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_MAKOTO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 92, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_Q_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 84, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 21, 8, 87, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NO12_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_REMY_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table CS): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_CS(PLW* wk) {
    Passive_CS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_CS(PLW* wk) {
    return 0;
}



s32 VS_HUGO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 76, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_MAKOTO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 92, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_Q_CS(PLW* wk) {
    return 0;
}



s32 VS_NO12_CS(PLW* wk) {
    return 0;
}



s32 VS_REMY_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table C): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_C(PLW* wk) {
    Passive_C_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ALEX_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }
    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }
    return 0;
}



s32 VS_RYU_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 31, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_DUDLEY_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NECRO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 40, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 17, 24, 24, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_HUGO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_IBUKI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 24, 26, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ELENA_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 18, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 19, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_KEN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_SEAN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 20, 1, -1)) {
        return 1;
    }
    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }
    return 0;
}



s32 VS_URIEN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_CHUN_LI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 76, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_MAKOTO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 92, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_Q_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 24, 8, 84, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 21, 8, 87, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_NO12_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_REMY_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }
    return 0;
}

/* Opponent-specific passive check (table DS): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_DS(PLW* wk) {
    Passive_DS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_DS(PLW* wk) {
    return 0;
}



s32 VS_ALEX_DS(PLW* wk) {
    return 0;
}



s32 VS_RYU_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_DS(PLW* wk) {
    return 0;
}



s32 VS_DUDLEY_DS(PLW* wk) {
    return 0;
}



s32 VS_NECRO_DS(PLW* wk) {
    return 0;
}



s32 VS_IBUKI_DS(PLW* wk) {
    return 0;
}



s32 VS_HUGO_DS(PLW* wk) {
    return 0;
}



s32 VS_ELENA_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_DS(PLW* wk) {
    return 0;
}



s32 VS_KEN_DS(PLW* wk) {
    return 0;
}



s32 VS_SEAN_DS(PLW* wk) {
    return 0;
}



s32 VS_URIEN_DS(PLW* wk) {
    return 0;
}



s32 VS_GOUKI_DS(PLW* wk) {
    return 0;
}



s32 VS_CHUN_LI_DS(PLW* wk) {
    return 0;
}



s32 VS_MAKOTO_DS(PLW* wk) {
    return 0;
}



s32 VS_Q_DS(PLW* wk) {
    return 0;
}



s32 VS_NO12_DS(PLW* wk) {
    PLW* em = (PLW*)wk->wu.target_adrs;
    if (Check_VS_Jump(wk, em, 32)) {
        VS_Tech[wk->wu.id] = 15;
        return 1;
    }
    return 0;
}



s32 VS_REMY_DS(PLW* wk) {
    return 0;
}

/* Opponent-specific passive check (table D): returns the chosen response, 0 when none. */
s32 Check_PL_Unit_D(PLW* wk) {
    Passive_D_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}



s32 VS_GILL_D(PLW* wk) {
    return 0;
}



s32 VS_ALEX_D(PLW* wk) {
    return 0;
}



s32 VS_RYU_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_YUN_D(PLW* wk) {
    return 0;
}



s32 VS_DUDLEY_D(PLW* wk) {
    return 0;
}



s32 VS_NECRO_D(PLW* wk) {
    return 0;
}



void VS_HUGO_D(PLW* wk) {
}



s32 VS_IBUKI_D(PLW* wk) {
    return 0;
}



s32 VS_ELENA_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_ORO_D(PLW* wk) {
    return 0;
}



s32 VS_KEN_D(PLW* wk) {
    return 0;
}



s32 VS_SEAN_D(PLW* wk) {
    return 0;
}



s32 VS_URIEN_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 12, 8, 63, 1, 12)) {
        return 1;
    }
    return 0;
}



s32 VS_GOUKI_D(PLW* wk) {
    return 0;
}



s32 VS_CHUN_LI_D(PLW* wk) {
    return 0;
}



s32 VS_MAKOTO_D(PLW* wk) {
    return 0;
}



s32 VS_Q_D(PLW* wk) {
    return 0;
}



s32 VS_NO12_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Special_Technique(wk, em, 8, 8, 105, 1, -1)) {
        return 1;
    }
    if (Check_Special_Technique(wk, em, 15, 8, 107, 1, -1)) {
        return 1;
    }
    return 0;
}



s32 VS_REMY_D(PLW* wk) {
    return 0;
}

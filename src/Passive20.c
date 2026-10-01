/*
 * PASSIVE20.C  CPU passive patterns for player 20 (Remy)
 *
 * Behaviour patterns for the computer-controlled player 20 in passive mode. Com_Passive in
 * Com_Pl calls Passive20, which runs the pattern selected in Pattern_Index through its pattern
 * table. Each Passive20_nnnn routine is a short script stepped by CP_Index: waiting for the
 * opponent to get up, walking in or keeping away, range and area checks with branches to other
 * patterns, normal, command, jump and super art attacks, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "Passive20.h"
#include "ACTIVE00.h"
void Passive20(PLW* wk)
{
    Passive20_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Passive20_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Off(wk);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0002(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 11, none);
        break;
    case 3:
        EM_Term(wk, 0x7FFF, none, 1, 1, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 83);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 11, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 127, 2);
        break;
    case 1:
        EM_Term(wk, 32767, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 11, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, (0x0), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 137, 0);
        break;
    case 3:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    case 4:
        Branch_Unit_Area(wk, 6, 104, 105, 106, 106);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 137, 0);
        break;
    case 3:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x12));
        break;
    case 5:
        Branch_Unit_Area(wk, 6, 104, 105, 106, 106);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, (0x0), 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, (0x0), -1);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8080, 0x8050, 0xB, (0x80), 0, 0x8060, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 32928, 32848, 11, (0x20), 0, 32864, -1, (0x100));
        break;
    case 1:
        Wait_Get_Up(wk, (0x0), -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 137, 0);
        break;
    case 3:
        Wait_Get_Up(wk, (0x0), -1);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x89, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 6:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32848, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xA, (0x200), 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, 32840, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 32, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x12));
        break;
    case 1:
        J_Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 11, 29, 8, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 6, 66, 70, 74, 74, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 157, 158, 159, 159, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x4B, 0x4B, 0x4B, 0x4B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x4D, 0x4D, 0x4D, 0x4D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x4E, 0x4E, 0x4E, 0x4E);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 127, 3);
        break;
    case 1:
        EM_Term(wk, 32896, 32832, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 11, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, (0x200), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, 32896, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 30, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, 32808, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, (0x2), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 11, (0x82));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x120));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, (0x100), 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x20, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, (0x2), 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 46, 47, 48, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 31, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        ETC_Term(wk, 0, 2, 0xD);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x21);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 55, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 10, (-1));
        break;
    case 2:
        Com_Random_Select(wk, 6, 66, 70, 74, 74, 1);
        break;
    case 3:
        Command_Attack(wk, 8, 30, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 75, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 28, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 127, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, (0x100), 0, 0x8060, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 12, 12, (0x200), 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 127, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 12, 0, 11, (-1));
        break;
    case 2:
        J_Command_Attack(wk, 8, 28, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x12));
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 104, 105, 105, 106);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 46, 47, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 31, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 46, -1, -1, 0);
        break;
    case 1:
        Approach_Walk(wk, 147, 2);
        break;
    case 2:
        SA_Term(wk, 46, 47, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 31, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 32928, 32864, 11, (0x40), 0, 32864, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x10, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 32928, 32848, 11, (0x200), 0, 32864, -1, (0x20));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 32928, 32864, 11, (0x100), 0, 32864, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 32928, 32864, 11, (0x10), 0, 32864, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x10));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 32928, 32864, 11, (0x200), 0, 32864, -1, (0x20));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x100), 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 0xC, 0xC, (0x202), 0);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 5, 5, 7, 8, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        SA_Term(wk, 0x2e, -1, -1, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1f, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        SA_Term(wk, 0x2e, -1, -1, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1f, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32864, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 89, 90, 91, 91);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x12));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x12));
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 104, 105, 106, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 127, 3);
        break;
    case 1:
        EM_Term(wk, 32896, 32808, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0098(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 55, 2);
        break;
    case 1:
        EM_Term(wk, none, 0x8040, 6, 1, none);
        break;
    case 2:
        Command_Attack(wk, 8, 29, 10, none);
        break;
    case 3:
        Com_Random_Select(wk, 6, 66, 70, 74, 74, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 32864, 11, (0x100), 0, 32864, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 75, 2);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    case 2:
        SA_Term(wk, 46, 47, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 31, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 1:
        SA_Term(wk, 46, 47, 48, 0);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 104, 105, 106, 106);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Walk(wk, 1, 32, 0);
        break;
    case 2:
        Wait_Get_Up(wk, (0x0), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 10, (-1));
        break;
    case 3:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 108);
        break;
    case 1:
        Walk(wk, 1, 56, 0);
        break;
    case 2:
        Wait_Get_Up(wk, (0x3), -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32848, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 12, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 6, 75, 54, 59, 112, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x200));
        break;
    case 1:
        Com_Random_Select(wk, 6, 75, 54, 59, 112, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x100), 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, (0x80), 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1F, 1, -1);
        break;
    case 3:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x200), 1, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 1, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x200), 2, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 2, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 32, 8, (0x40), 2, -1, 32, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 48, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 54);
        break;
    case 1:
        J_Command_Attack(wk, 8, 31, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x81, 0x82, 0x82, 0x83);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 132);
        break;
    case 1:
        Command_Attack(wk, 8, 30, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 31, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 54);
        break;
    case 1:
        J_Command_Attack(wk, 8, 31, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32896, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 30, 10, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 34);
        break;
    case 1:
        J_Command_Attack(wk, 8, 31, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 12, 13, (0x200), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32848, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 2:
        Approach_Walk(wk, 0x93, 2);
        break;
    case 3:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 12, 0, 11, (-1));
        break;
    case 3:
        J_Command_Attack(wk, 8, 28, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 133);
        break;
    case 1:
        J_Command_Attack(wk, 8, 31, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8050, 8, 0x20, 2, -1, 0x8050, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32912, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32912, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32912, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x10));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x10));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 89, 89, 90, 91);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 155);
        break;
    case 1:
        Wait(wk, 3);
        break;
    case 2:
        J_Command_Attack(wk, 8, 31, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0xF);
        break;
    case 1:
        Walk(wk, 1, 0x20, 0);
        break;
    case 2:
        Wait(wk, 3);
        break;
    case 3:
        Walk(wk, 0, 0x30, 0);
        break;
    case 4:
        Wait(wk, 9);
        break;
    case 5:
        Walk(wk, 0, 0x20, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Passive20_0161(PLW* wk)
{

    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x20, 2, 0x1B);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        Wait(wk, 8);
        break;
    case 3:
        Search_Back_Term(wk, 0x30, 2, 0x1B);
        break;
    case 4:
        Walk(wk, 1, 0x20, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x20, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0x30, 2, 6);
        break;
    case 2:
        Walk(wk, 1, 0x28, 0);
        break;
    case 3:
        Wait(wk, 8);
        break;
    case 4:
        Walk(wk, 0, 0x20, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1d, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 12, 29, 8, (-1));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 30, 8, (-1));
        break;
    case 2:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 10, (-1));
        break;
    case 2:
        Command_Attack(wk, 8, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 8, (0x202), 0, 0x8060, -1, (0x100));
        break;
    case 1:
    case 2:
        Normal_Attack(wk, 0xC, (0x82));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive20_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}




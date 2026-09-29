/*
 * pass19.c  Computer AI passive patterns for character 19 (Twelve)
 *
 * Passive19 is the passive-mode entry for character number 19, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive19_Tbl; this file holds the 204 patterns
 * Passive19_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass19.h"



void Passive19(PLW* wk) {
    Passive19_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Passive19_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0001(PLW* wk) {
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



void Passive19_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x53);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x6F, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0016(PLW* wk) {
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
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0017(PLW* wk) {
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
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0018(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x12);
        break;
    case 5:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8080, 0x8050, 0xB, (0x200), 0, 0x8060, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, (0x100));
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0024(PLW* wk) {
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
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0025(PLW* wk) {
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
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 10, 0x200, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0029(PLW* wk) {
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



void Passive19_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8048, 1, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xB, 0x1C, 10, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0037(PLW* wk) {
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



void Passive19_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x40, 1, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x6F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x35, 0x37, 0xC5, 0x86, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x6F, 2);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8038, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x40, 1, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8040, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x6F, 2);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8040, 6, 1, -1);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x220));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x20, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        ETC_Term(wk, 0, 2, 0xD);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x21);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8048, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, (0x100), 0, 0x8060, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xC, 0x42, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0071(PLW* wk) {
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



void Passive19_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8040, 2, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x68, 0x68, 0x69, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x40, 0, 0x8060, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, (0x80), 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, (0x100), 0, 0x8060, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, (0x80), 0, 0x8060, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0083(PLW* wk) {
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
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 0xC, 0x12, (0x200), 0);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 6);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8048, 2, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x6F, 2);
        break;
    case 1:
        EM_Term(wk, -1, -1, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 3:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 4:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 3:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 3:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x30, 8, -1, -1, 0x8030, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x30, 9, -1, -1, 0x8030, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x30, 0xA, -1, -1, 0x8030, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x5A, 0x5B, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8028, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0097(PLW* wk) {
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



void Passive19_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x42, 0x20, 0xBF, 0x8E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x100), 0, 0x8060, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x20, 0);
        break;
    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x38, 0);
        break;
    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x22);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x80, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1D, 1, -1);
        break;
    case 3:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 1, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 2, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 2, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 2, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 8, -1, -1, 0x8048, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8048, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2f, 0xa, -1, -1, 0x8048, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x81, 0x82, 0x82, 0x83);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x84);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -1, 0x8048, 1, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x22);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xA, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0143(PLW* wk) {
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



void Passive19_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x88, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x73, 0x92, 0x93, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0148(PLW* wk) {
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



void Passive19_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8050, 8, 0x20, 2, -1, 0x8050, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0151(PLW* wk) {
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



void Passive19_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
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



void Passive19_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
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



void Passive19_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x5B, 0x5B, 0x5A, 0x5A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x9B);
        break;
    case 1:
        Wait(wk, 4);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0160(PLW* wk) {
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



void Passive19_0161(PLW* wk) {
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



void Passive19_0162(PLW* wk) {
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



void Passive19_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 6, 0x14, 0x16, 0x17, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 8, (0x200), 0, 0x8060, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x50, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x80));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x50, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x20));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x20));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x10));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x10));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x80));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0184(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x20));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x20));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (0x70));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0190(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 48, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 65, 65, 66, 67);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x11, 0x6B, 0x6C, 0x67, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 9, (-1));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0193(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 28, 9, (-1));
        break;
    case 2:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x20));
        break;
    }
}



void Passive19_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x50, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x35, 0x37, 0xC5, 0x86, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x30, 0xA, -1, -1, 0x8030, 2, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5B, 0xC6, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 46, 47, -1, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 12, 103, 199, 38, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xC3, 0xB1, 0xA7, 0xA7, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 201);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 11, (-1));
        break;
    case 3:
        Com_Random_Select(wk, 6, 74, 196, 104, 132, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive19_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 33024, 32864, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

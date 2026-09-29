/*
 * pass16.c  Computer AI passive patterns for character 16 (Chun-Li)
 *
 * Passive16 is the passive-mode entry for character number 16, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive16_Tbl; this file holds the 164 patterns
 * Passive16_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass16.h"



void Passive16(PLW* wk) {
    Passive16_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Passive16_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0001(PLW* wk) {
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



void Passive16_0002(PLW* wk) {
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
    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0004(PLW* wk) {
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



void Passive16_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0006(PLW* wk) {
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



void Passive16_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0x8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, (0x20), 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0013(PLW* wk) {
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



void Passive16_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0016(PLW* wk) {
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



void Passive16_0017(PLW* wk) {
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



void Passive16_0018(PLW* wk) {
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
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0022(PLW* wk) {
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
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0024(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0025(PLW* wk) {
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
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 10, (0x200), 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x40, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xB, 0x1E, 10, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 1:
        Rapid_Command_Attack(wk, 8, 0x4D, (0x200), 0x78);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x80));
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



void Passive16_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8040, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, (0x102), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1f, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Jump_Attack(wk, 8, 6, (0x102), 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x120);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, (0x102), 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x20, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        ETC_Term(wk, 0, 6, 0x36);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x36);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, 0x8060, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xC, 0x42, 0x0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 3:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 4:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x40, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x80, 0, 0x8060, -1, 0x20);
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



void Passive16_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x80, 0, 0x8060, -1, 0x200);
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



void Passive16_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xC, 0x102, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 3:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 4:
        SA_Term(wk, 0x2E, 0x2F, -1, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 3:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 4:
        SA_Term(wk, 0x2E, 0x2F, -1, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 3:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 4:
        SA_Term(wk, 0x2E, 0x2F, -1, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5B, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0093(PLW* wk) {
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



void Passive16_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8028, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0099(PLW* wk) {
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



void Passive16_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0102(PLW* wk) {
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



void Passive16_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0107(PLW* wk) {
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



void Passive16_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0109(PLW* wk) {
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



void Passive16_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x38, 0);
        break;
    case 2:
        Wait_Get_Up(wk, 0x0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x80, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0119(PLW* wk) {
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



void Passive16_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 1, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 2, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 2, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 2, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x81, 0x82, 0x82, 0x83);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x84);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x22);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xA, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0141(PLW* wk) {
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



void Passive16_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x8A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x8A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 3:
        SA_Term(wk, 0x2E, -1, -1, 0);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x8A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x9D, 0x9D, 0x9E, 0x9E, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x85);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0148(PLW* wk) {
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



void Passive16_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8050, 8, 0x20, 2, -1, 0x8050, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0153(PLW* wk) {
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



void Passive16_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 6);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x9B);
        break;
    case 1:
        Wait(wk, 4);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive16_0160(PLW* wk) {
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



void Passive16_0161(PLW* wk) {
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



void Passive16_0162(PLW* wk) {
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



void Passive16_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 8, (0x200), 2, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

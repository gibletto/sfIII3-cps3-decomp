/*
 * ACTIVE17.C  CPU opponent action patterns, character 17
 *
 * Computer17 is the computer-player routine for character 17, entered from Com_Active in
 * COM_PL through its per-character jump table. It runs the pattern currently selected in
 * Pattern_Index through Pattern17_Tbl.
 * The 70 pattern routines Pattern17_0000-0069 are small scripts stepped by CP_Index: each
 * case issues one command to the CPU control library (Lever_Off, Look, Walk, Approach_Walk,
 * Normal_Attack, Lever_Attack, Command_Attack, Jump_Attack, SA_Term, Wait, Branch_Unit_Area,
 * Com_Random_Select ...) and the last case calls End_Pattern so COM_PL can choose the next.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active17.h"



void Computer17(PLW* wk) {
    Pattern17_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Pattern17_0000(PLW* wk) {
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



void Pattern17_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x3E, 0x3E, 0x3F, 0x43, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x10);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, 0x8060, 0x40, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 0xC, 0, 0x40);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, 0x40);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, 0x40, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x100));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x82);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x82);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x42));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0043(PLW* wk) {
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



void Pattern17_0044(PLW* wk) {
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



void Pattern17_0045(PLW* wk) {
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



void Pattern17_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x10, 2, 0x40);
        break;
    case 1:
        Search_Back_Term(wk, 0x40, 2, 0x41);
        break;
    case 2:
        Search_Back_Term(wk, 0x70, 2, 0x42);
        break;
    case 3:
        Branch_Unit_Area(wk, 2, 0x32, 0x33, 0x33, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 6, 0x11);
        break;
    case 1:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8014, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8014, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    case 3:
        Com_Random_Select(wk, 2, 3, 0x38, 0x44, 0x45, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x4B, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0x41);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    case 4:
        Com_Random_Select(wk, 2, 3, 0x38, 0x44, 0x45, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0055(PLW* wk) {
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



void Pattern17_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, (0x380), 0x8060, 0x40, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 6, 0x31, 0x32, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x31, 0x32, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x90));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern17_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

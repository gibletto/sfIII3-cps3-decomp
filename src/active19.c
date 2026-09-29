/*
 * ACTIVE19.C  CPU opponent action patterns, character 19
 *
 * Computer19 is the computer-player routine for character 19, called from Com_Active in
 * COM_PL. It runs the pattern selected in Pattern_Index through Pattern19_Tbl.
 * The 109 pattern routines are step scripts indexed by CP_Index. Many are single jump or
 * high-jump command attacks at a given power and jump direction; others chain normal,
 * lever and command attacks, walks, Pierce_On, Provoke, area branches and random choices.
 * Each ends with End_Pattern so COM_PL can choose the next pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active19.h"



void Computer19(PLW* wk) {
    Pattern19_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Pattern19_0000(PLW* wk) {
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



void Pattern19_0001(PLW* wk) {
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



void Pattern19_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8058, 1, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x3E, 0x3F, 0x40, 0x40, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0007(PLW* wk) {
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



void Pattern19_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0009(PLW* wk) {
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



void Pattern19_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8058, 1, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8060, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, (0x200), 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0026(PLW* wk) {
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



void Pattern19_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x100);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0034(PLW* wk) {
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



void Pattern19_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0043(PLW* wk) {
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



void Pattern19_0044(PLW* wk) {
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



void Pattern19_0045(PLW* wk) {
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



void Pattern19_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8026, 10, -1, 0x30, 0x8050, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8026, 8, -1, 0x30, 0x8050, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8026, 9, -1, 0x30, 0x8050, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8026, 0xA, -1, 0x30, 0x8050, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;
    case 1:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0055(PLW* wk) {
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



void Pattern19_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x41, 0x41, 0x42, 0x43);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x48, 0x48, 0x49, 0x4A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, (0x380), -1, 0x8058, 1, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x50, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 64, 2, 27);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x10));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    }
}



void Pattern19_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Com_Random_Select(wk, 2, 81, 81, 82, 83, 0);
        break;
    }
}



void Pattern19_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 8, -1, -1, 0x8058, 2, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8058, 2, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -1, 0x8058, 2, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x55, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 8, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x59, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 8, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -1, 0x8058, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0092(PLW* wk) {
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



void Pattern19_0093(PLW* wk) {
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



void Pattern19_0094(PLW* wk) {
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



void Pattern19_0095(PLW* wk) {
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



void Pattern19_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x10));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 12, (0x10));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0098(PLW* wk) {
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



void Pattern19_0099(PLW* wk) {
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



void Pattern19_0100(PLW* wk) {
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



void Pattern19_0101(PLW* wk) {
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



void Pattern19_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
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



void Pattern19_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
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



void Pattern19_0105(PLW* wk) {
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



void Pattern19_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 17, 107, 108, 103, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    case 1:
        Command_Attack(wk, 8, 28, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern19_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    case 2:
        Command_Attack(wk, 8, 28, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

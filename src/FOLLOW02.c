/*
 * FOLLOW02.C  CPU active patterns for character 20 and the shared follow-up table
 *
 * Computer20 is the CPU active routine for character 20 in Com_Active's table: it runs the
 * current pattern selected by Pattern_Index through its pattern table.
 * Pattern20_0000 - Pattern20_0078 are pattern steps: each is a switch on CP_Index calling the
 * Com_Sub building blocks (normal, command and jump attacks, walking, waiting, wall searches)
 * and ending with End_Pattern.
 * Follow02 is the follow-up routine used for every character by Com_Follow; it runs the
 * Follow02_xxxx entries of Follow02_Tbl. Follow01_0000 - 0003 are an older four-entry follow-up
 * table stored just before it and not referenced.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "FOLLOW02.h"



void Computer20(PLW* wk) {
    Pattern20_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Pattern20_0000(PLW* wk) {
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



void Pattern20_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x10));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x10));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 31, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, (0x10));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 55, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 62, 63, 64, 64, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Wait(wk, 30);
        break;
    }
}



void Pattern20_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 48, 2, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 11, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    }
}



void Pattern20_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 96, 6, 16);
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



void Pattern20_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    }
}



void Pattern20_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    }
}



void Pattern20_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x40));
        break;
    }
}



void Pattern20_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    }
}



void Pattern20_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Walk(wk, 0, 48, 0);
        break;
    }
}



void Pattern20_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Walk(wk, 1, 48, 0);
        break;
    }
}



void Pattern20_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 12, (0x200), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    }
}



void Pattern20_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    case 1:
        Command_Attack(wk, 8, 30, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8060, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, 0x40, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Approach_Walk(wk, 127, 2);
        break;
    }
}



void Pattern20_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Walk(wk, 0, 96, 0);
        break;
    }
}



void Pattern20_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Walk(wk, 1, 96, 0);
        break;
    }
}



void Pattern20_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 11, (-1));
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Jump(wk, 0);
        break;
    }
}



void Pattern20_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    }
}



void Pattern20_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x100));
        break;
    case 2:
        Adjust_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 32864, 11, (0x200), 0, 32864, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 29, 10, (-1));
        break;
    case 1:
        Command_Attack(wk, 8, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, (0x10));
        break;
    case 1:
        Command_Attack(wk, 8, 31, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, (0x82));
        break;
    case 1:
        Adjust_Attack(wk, 8, (0x82));
        break;
    case 2:
        Adjust_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x20));
        break;
    }
}



void Pattern20_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x42));
        break;
    }
}



void Pattern20_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 11, (0x10));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 11, (0x42));
        break;
    case 1:
        Normal_Attack(wk, 11, (0x200));
        break;
    case 2:
        Command_Attack(wk, 8, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 29, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0042(PLW* wk) {
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



void Pattern20_0043(PLW* wk) {
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



void Pattern20_0044(PLW* wk) {
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



void Pattern20_0045(PLW* wk) {
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



void Pattern20_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 29, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 46, 47, 48, 0);
        break;
    case 1:
        Com_Random_Select(wk, 2, 62, 63, 64, 64, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0053(PLW* wk) {
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



void Pattern20_0054(PLW* wk) {
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



void Pattern20_0055(PLW* wk) {
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



void Pattern20_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 0, (0x90));
        break;
    }
}



void Pattern20_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 1, (0x90));
        break;
    }
}



void Pattern20_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x90));
        break;
    }
}



void Pattern20_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x33, 0x44, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x38, 0x39, 0x3A, 0x45, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern20_0072(PLW* wk) {
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



void Pattern20_0073(PLW* wk) {
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



void Pattern20_0074(PLW* wk) {
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



void Pattern20_0075(PLW* wk) {
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



void Pattern20_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 8, (0x202), 0, 0x8060, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 0xc, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 0xc, (0x82));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

u32 Pattern20_0077(PLW* wk)
{
    s16 lever;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        lever = 0x82;
        break;
    case 1:
        lever = 0x102;
        break;
    case 2:
        return ((u32 (*)())Command_Attack)(wk, 8, 30, 10, -1);
    default:
        return ((u32 (*)())End_Pattern)();
    }
    return ((u32 (*)())Normal_Attack)(wk, 8, lever);
}



void Pattern20_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Command_Attack(wk, 8, 29, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
void Follow01_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
void Follow01_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
void Follow01_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
void Follow01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Follow02(PLW* wk) {
    Follow02_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Follow02_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Follow02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Follow02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Follow02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

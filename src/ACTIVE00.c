/*
 * ACTIVE00.C  Computer player patterns: end of Passive20 and the Pattern00 active set
 *
 * Step-by-step CPU pattern routines. Each pattern is a switch on CP_Index[id][0]; every case
 * calls one Com_Sub step (Walk, Normal_Attack, Jump_Attack_Term, Command_Attack, Look, ...)
 * and the last case calls End_Pattern.
 * Passive20_0123..0175 are the tail of character 20's passive (reaction) patterns, reached
 * through Passive20_Tbl.
 * Computer00 is character 0's entry in the Char_Jmp_Tbl of Com_Pl; it runs the pattern
 * selected by Pattern_Index[id] from Pattern00_Tbl (Pattern00_0000..0067).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "ACTIVE00.h"



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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x40));
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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Wait(wk, 0);
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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Provoke(wk, -1);
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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 0, (0x90));
        break;
    }
}



void Passive20_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 1, (0x90));
        break;
    }
}



void Passive20_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Normal_Attack(wk, 8, (0x90));
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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
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
    default:
        End_Pattern(wk);
        break;
    case 0:
        Provoke(wk, -1);
        break;
    }
}



void Passive20_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Provoke(wk, -1);
        break;
    }
}



void Passive20_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Provoke(wk, -1);
        break;
    }
}



void Passive20_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    case 0:
        Provoke(wk, -1);
        break;
    }
}



void Computer00(PLW* wk) {
    Pattern00_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}



void Pattern00_0000(PLW* wk) {
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



void Pattern00_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
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



void Pattern00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 2, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x99);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 8, 0x10, 0, 8, 8, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, 0x8070, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 2, 0x12);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0026(PLW* wk) {
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



void Pattern00_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        ETC_Term(wk, 0, 6, 0x99);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
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



void Pattern00_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;
    case 1:
        {
            s16 menu = 49;
            Com_Random_Select(wk, 2, menu, menu, menu, 50, 0);
        }
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x90);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8048, 8, 0x200, 1, 0x8070, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x34);
        break;
    case 1:
        Command_Attack(wk, 8, 0x8018, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x34);
        break;
    case 1:
        Command_Attack(wk, 8, 0x8019, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern00_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 2:
        ETC_Term(wk, 0, 6, 0x9A);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

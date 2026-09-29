/*
 * SEL_PL_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void After_Bonus_2nd();
extern void After_Bonus_3rd();
extern void After_Bonus_4th();
extern void After_Bonus_6th();
extern void After_Bonus_End();
extern void Exit_1st();
extern void Exit_2nd();
extern void Exit_3rd();
extern void Exit_4th();
extern void Exit_5th();
extern void Exit_6th();
extern void Exit_7th();
extern void Face_1st();
extern void Face_2nd();
extern void Face_3rd();
extern void Face_4th();
extern void Next_Bonus_1st();
extern void Next_Bonus_2nd();
extern void Next_Bonus_3rd();
extern void Next_Bonus_End();
extern void Next_CPU_1st();
extern void Next_CPU_2nd();
extern void Next_CPU_3rd();
extern void Next_CPU_4th();
extern void Next_CPU_5th();
extern void Next_CPU_6th();
extern void Next_Q_2nd();
extern void Next_Q_3rd();
extern void OBJ_1st();
extern void OBJ_2nd();
extern void OBJ_3rd();
extern void PL_Sel_1st();
extern void PL_Sel_2nd();
extern void PL_Sel_3rd();
extern void PL_Sel_4th();
extern void PL_Sel_5th();
extern void PL_Sel_Begin();
extern void Sel_PL_1st();
extern void Sel_PL_2nd();
extern void Sel_PL_3rd();
extern void Sel_PL_4th();
extern void Sel_PL_5th();
extern void Sel_PL_6th();
extern void Sel_PL_Cont_1st();
extern void Sel_PL_Cont_2nd();
extern void Sel_PL_Cont_3rd();
extern void Sel_PL_Cont_4th();
extern void Select_CPU_1st();
extern void Select_CPU_2nd();
extern void Select_CPU_3rd();
extern void Select_CPU_4th();
extern void After_Bonus_1st();
extern void Next_Q_1st();

const SEL_PL_CONT_TBL Sel_PL_Cont_Jmp_Data[1] = {
    { { Sel_PL_Cont_1st, Sel_PL_Cont_2nd, Sel_PL_Cont_3rd, Sel_PL_Cont_4th } },
};

const s8 Sel_PL_Erase_msg[1] = {
    32,
};

const u8 Repeat_Time_Data_Wife[20] = "                   ";

const s8 Face_Order_Data[19] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 16, 17,
    18, 19, 20,
};

/* The initial values of Sel_PL_Jmp_Tbl (Sel_PL) in sel_pl.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Sel_PL_Jmp_Tbl_init[6] = {
    (u32)Sel_PL_1st,
    (u32)Sel_PL_2nd,
    (u32)Sel_PL_3rd,
    (u32)Sel_PL_4th,
    (u32)Sel_PL_5th,
    (u32)Sel_PL_6th,
};

const s8 Auto_Repeat_Data[3] = {
    26, 9, 7,
};

const s8 Auto_Repeat_Wife_Data[5] = {
    1, 1, 1, 0, 0,
};

const OBJ_JMP_TBL OBJ_Jmp_Data[4] = {
    { { OBJ_1st, OBJ_2nd, OBJ_3rd } },
    { { Face_1st, Face_2nd, Face_3rd } },
    { { Face_4th, PL_Sel_Begin, PL_Sel_2nd } },
    { { PL_Sel_3rd, PL_Sel_4th, PL_Sel_5th } },
};

const u8 Setup_Aborigine_table[3][3] = {
    { 0, 1, 2 }, { 2, 0, 1 }, { 1, 2, 0 },
};

const s16 Cursor_Y_Data[13] = {
    80, 104, 128, 80, 104, 128, 16, 32,
    64, 128, 256, 512, 0,
};

const SEL_EXIT_TBL Sel_Exit_Jmp_Data[4] = {
    { { Exit_1st, Exit_2nd, Exit_3rd, Exit_4th, Exit_5th, Exit_6th, Exit_7th } },
    { { Next_CPU_1st, Next_CPU_2nd, Next_CPU_3rd, Next_CPU_4th, Next_CPU_5th, Next_CPU_6th, Next_Bonus_1st } },
    { { Next_Bonus_2nd, Next_Bonus_3rd, Next_Bonus_End, After_Bonus_1st, After_Bonus_2nd, After_Bonus_3rd, After_Bonus_4th } },
    { { Next_CPU_3rd, After_Bonus_6th, After_Bonus_End, Select_CPU_1st, Select_CPU_2nd, Select_CPU_3rd, Select_CPU_4th } },
};

/* The initial values of Next_Q_Tbl (Next_Q) in next_cpu.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Next_Q_Tbl_init[4] = {
    (u32)Next_Q_1st,
    (u32)Next_Q_2nd,
    (u32)Next_Q_3rd,
    (u32)PL_Sel_1st,
};

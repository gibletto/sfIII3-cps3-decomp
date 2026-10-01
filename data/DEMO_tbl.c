/*
 * DEMO_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Demo00();
extern void Demo01();
extern void Logo_Capcom();
extern void Logo_Etc();
extern void Logo_Warning();

const s8 Game_Data_msg[12] = "GAME DATA";

const s8 Income_msg[8] = "INCOME";

const s8 Service_msg[8] = "SERVICE";

const s8 Card_msg[8] = "CARD";

/* Initial values of jmp_tbl (CAPCOM_Logo) in DEMO.c. */
const u32 jmp_tbl_init[3] = {
    (u32)Logo_Capcom,
    (u32)Logo_Warning,
    (u32)Logo_Etc,
};

const DEMO_JMP2 Demo_Jmp_Data[1] = {
    { { Demo00, Demo01 } },
};

const s8 Demo_Char_Data[4][2] = {
    { 16, 20 }, { 11, 19 }, { 2, 17 }, { 12, 8 },
};

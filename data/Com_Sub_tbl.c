/*
 * COM_SUB_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void ETC_Term_0000();
extern void ETC_Term_0001();
extern void ETC_Term_0002();
extern void ETC_Term_0003();
extern void ETC_Term_0004();
extern void ETC_Term_0005();
extern void ETC_Term_0006();
extern void ETC_Term_0007();
extern void ETC_Term_0008();
extern void ETC_Term_0009();
extern void Exit_Term_0000();
extern void Exit_Term_0001();
extern void Exit_Term_0002();
extern void Exit_Term_0003();
extern void Exit_Term_0004();
extern void Exit_Term_0005();
extern void Exit_Term_0006();
extern void Exit_Term_0007();
extern void Exit_Term_0008();

const u8 YAGYOU_Data[16] = {
    0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 2, 2, 2, 3, 3, 3,
};

const s16 Correct_VS_Air_Data[24] = {
    0, 32, 0, 0, 0, 32, 32, 0,
    32, 0, 0, 0, 0, 32, 0, 0,
    0, 0, 0, 0,
};

const s32 Hadou_Check_Data[21][2] = {
    { 0, 0 }, { 0, 0 }, { 1, 29 }, { 0, 0 }, { 1, 31 }, { 0, 0 }, { 1, 32 }, { 1, 33 },
    { 0, 0 }, { 0, 0 }, { 1, 31 }, { 1, 29 }, { 0, 0 }, { 0, 0 }, { 1, 31 }, { 1, 31 },
    { 0, 0 }, { 1, 30 }, { 0, 0 }, { 0, 0 },
};

const u16 Rolling_Lv_Data[2][9] = {
    { 4, 1, 8, 2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 4, 2, 8, 1, 4, 2, 8, 1, 0xFFFF },
};

const s8 PL_Status[10] = {
    1, 0, 0, 0, 1, 1, 0, 0,
    0, 0,
};

const Term_Tbl_t Exit_Term_Tbl[9] = {
    Exit_Term_0000,
    Exit_Term_0001,
    Exit_Term_0002,
    Exit_Term_0003,
    Exit_Term_0004,
    Exit_Term_0005,
    Exit_Term_0006,
    Exit_Term_0007,
    Exit_Term_0008,
};

const Term_Tbl_t ETC_Term_Tbl[10] = {
    ETC_Term_0000,
    ETC_Term_0001,
    ETC_Term_0002,
    ETC_Term_0003,
    ETC_Term_0004,
    ETC_Term_0005,
    ETC_Term_0006,
    ETC_Term_0007,
    ETC_Term_0008,
    ETC_Term_0009,
};

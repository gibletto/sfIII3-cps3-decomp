/*
 * COM_SUB_TBL.C  the computer player's step helper tables
 *
 * YAGYOU_Data holds the random term numbers used with the Yagyou super art,
 * Correct_VS_Air_Data a range correction for the air checks by the player's character,
 * Hadou_Check_Data which characters have a fireball move and its technique number,
 * Rolling_Lv_Data the lever sequences of a single and a double rolling command, and PL_Status
 * the opponent states (by routine number) that skip the shell check. Exit_Term_Tbl and
 * ETC_Term_Tbl are the jump tables of the Exit_Term_* and ETC_Term_* routines. Read by
 * COM_SUB.C, the pattern step library.
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
    { 0, 0 },  /* Gill */
    { 0, 0 },  /* Alex */
    { 1, 29 },  /* Ryu */
    { 0, 0 },  /* Yun */
    { 1, 31 },  /* Dudley */
    { 0, 0 },  /* Necro */
    { 1, 32 },  /* Hugo */
    { 1, 33 },  /* Ibuki */
    { 0, 0 },  /* Elena */
    { 0, 0 },  /* Oro */
    { 1, 31 },  /* Yang */
    { 1, 29 },  /* Ken */
    { 0, 0 },  /* Sean */
    { 0, 0 },  /* Urien */
    { 1, 31 },  /* Gouki */
    { 1, 31 },  /* Shin Gouki */
    { 0, 0 },  /* Chun-Li */
    { 1, 30 },  /* Makoto */
    { 0, 0 },  /* Q */
    { 0, 0 },  /* Twelve */
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

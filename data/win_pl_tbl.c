/*
 * WIN_PL_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Win_00000();
extern void Win_01000();
extern void Win_02000();
extern void Win_03000();
extern void Win_04000();
extern void Win_05000();
extern void Win_06000();
extern void Win_07000();
extern void Win_08000();
extern void Win_09000();
extern void Win_10000();
extern void Win_11000();
extern void Win_12000();
extern void Win_13000();
extern void Win_14000();
extern void Win_15000();

const s16 win_type_tbl[24] = {
    6, 0, 0, 6, 2, 7, 9, 3,
    4, 1, 12, 0, 5, 14, 8, 8,
    13, 6, 10, 11,
    15, 0, 0, 0,
};

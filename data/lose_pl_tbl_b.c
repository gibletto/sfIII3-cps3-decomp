/*
 * LOSE_PL_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Lose_00000();
extern void Lose_10000();
extern void Lose_20000();
extern void Lose_30000();

const s16 meta_lose_tbl[21] = {
    24, 24, 24, 24, 24, 24, 24, 24,
    24, 24, 24, 24, 24, 28, 24, 24,
    24, 24, 24, 24,
    24,
};


/*
 * LOSE_PL_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Lose_00000();
extern void Lose_10000();
extern void Lose_20000();
extern void Lose_30000();

const s16 lose_type_tbl[24] = {
    0, 0, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

/* Initial values of lose_jp_tbl (lose_player) in lose_pl.c. */
const u32 lose_jp_tbl_init[4] = {
    (u32)Lose_00000, (u32)Lose_10000, (u32)Lose_20000, (u32)Lose_30000,
};

const s16 meta_lose_tbl[21] = {
    24, 24, 24, 24, 24, 24, 24, 24,
    24, 24, 24, 24, 24, 28, 24, 24,
    24, 24, 24, 24,
    24,
};


/*
 * LOSE_PL_TBL_B.C  metamorphosed loser pose table
 *
 * meta_lose_tbl gives, by character, the pose used when the loser is not in his own
 * character (meta_lose_pause). Read by LOSE_PL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 meta_lose_tbl[21] = {
    24, 24, 24, 24, 24, 24, 24, 24,
    24, 24, 24, 24, 24, 28, 24, 24,
    24, 24, 24, 24,
    24,
};


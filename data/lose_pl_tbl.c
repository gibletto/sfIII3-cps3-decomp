/*
 * LOSE_PL_TBL.C  round loser type table
 *
 * loser_type_tbl selects, by character, which loser routine (Lose_00000 .. Lose_30000) plays
 * at the end of a lost round. Read by LOSE_PL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 loser_type_tbl[24] = {
    0, 0, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

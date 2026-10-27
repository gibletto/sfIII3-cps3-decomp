/*
 * EFF99_TBL.C  Akuma entrance colour swap
 *
 * effA0_swap_tbl gives the colour used by Akuma's entrance for each colour of the opponent, so
 * the two differ. Read by EFFA0.C, the Akuma entrance.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s8 effA0_swap_tbl[7] = {
    3, 4, 5, 0, 1, 2, 0,
};


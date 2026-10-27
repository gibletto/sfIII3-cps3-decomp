/*
 * EFF86_TBL.C  one-shot object settings
 *
 * eff86_data_tbl00 gives the sub-state, family, colour, position, priority and animation of
 * the object, reached through eff86_adrs_tbl. Read by EFF86.C, the one-shot object placed
 * between the players.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 eff86_data_tbl00[7] = {
    0, 2, 8224, 511, 56, 10, 18,
};

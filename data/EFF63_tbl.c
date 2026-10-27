/*
 * EFF63_TBL.C  idle animated object placement
 *
 * eff78_init_tbl gives the position and settings of the two effect 63 objects created by
 * effect_78_init. Read by EFF63.C, the pair of idle animated objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff78_init_tbl[2][4] = {
    { 512, 42, 80, 10 },
    { 560, 18, 10, 13 },
};

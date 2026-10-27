/*
 * EFF35_TBL_B.C  bonus-stage sliding piece delays
 *
 * eff35_03_b and eff35_03_s are the wait times between the repeating sliding pieces of
 * behaviour eff35_0003, one table for each direction. Read by EFF35.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 eff35_03_b[4] = {
    180, 120, 240, 60,
};

const s16 eff35_03_s[4] = {
    190, 130, 220, 60,
};

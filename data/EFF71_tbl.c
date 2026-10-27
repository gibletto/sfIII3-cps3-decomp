/*
 * EFF71_TBL.C  bg040 occasional animation timing
 *
 * eff71_time_tbl holds the random waits between the occasional animations. Read by EFF71.C,
 * the timer for an occasional bg040 stage animation.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff71_time_tbl[8] = {
    2, 8, 12, 9, 4, 6, 50, 3,
};

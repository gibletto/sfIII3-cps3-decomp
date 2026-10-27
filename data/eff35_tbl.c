/*
 * EFF35_TBL.C  bonus-stage presentation object data
 *
 * eff35_data_tbl holds one row per bonus-stage object type: x, y, priority, animation, two
 * parameters and the behaviour (eff35_0000 - 0006) it runs. Read by EFF35.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 eff35_data_tbl[12][7] = {
    { 608, 0, 28, 1, 1, 0, 60 },
    { 432, 0, 28, 1, 2, 0, 60 },
    { 848, 20, 81, 1, 3, 3, 60 },
    { 512, 8, 82, 1, 4, 3, 60 },
    { 512, 0, 75, 7, 1, 4, 60 },
    { 0, 118, 20, 12, 1, 5, 60 },
    { 0, 118, 20, 12, 2, 5, 60 },
    { 0, 112, 20, 12, 3, 6, 60 },
    { 0, 112, 20, 12, 4, 6, 60 },
    { 0, 118, 20, 12, 5, 5, 60 },
    { 0, 118, 20, 12, 6, 6, 60 },
    { 0, 118, 20, 12, 7, 6, 60 },
};

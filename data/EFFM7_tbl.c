/*
 * EFFM7_TBL.C  entrance extras placement
 *
 * effm7_data_tbl gives seven words per object for the six objects of effect M7, placed
 * relative to the opponent. Read by EFFM7.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effm7_data_tbl[42] = {
    48, -8, -1, 0, 18, 30, 90, 64,
    2, 1, 0, 17, 16, 98, -32, -8,
    -1, 1, 18, 4, 92, -64, 2, 1,
    1, 17, 24, 96, -112, -8, -1, 1,
    18, 8, 102, -224, 2, 1, 1, 17,
    10, 106,
};

/*
 * EFF07_TBL.C  bg000 background object placement
 *
 * eff07_data_tbl gives the animation number and x, y position of each of the two background
 * objects. Read by EFF07.C, the bg000 stage background objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff07_data_tbl[2][3] = {
    { 4, 742, 28 },
    { 5, 806, 28 },
};

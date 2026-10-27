/*
 * EFFL4_TBL.C  stage piece placement for effect L4
 *
 * effl4_data_tbl gives the six stage pieces { x, y, priority, pattern }. Read by EFFL4.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effl4_data_tbl[24] = {
    143, 96, 73, 9, 223, 120, 73, 10,
    303, 104, 73, 11, 367, 112, 73, 12,
    399, 144, 73, 13, 487, 120, 73, 14,
};

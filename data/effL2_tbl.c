/*
 * EFFL2_TBL.C  onlooker facing table
 *
 * effl2_dir_tbl gives the onlooker's facing by the followed fighter's x position, one row per
 * side. Read by EFFL2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s8 effl2_dir_tbl[2][16] = {
    { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3 },
};

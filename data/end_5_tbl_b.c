/*
 * END_5_TBL_B.C  Necro's ending scrolling strip tables (ending 5)
 *
 * end_5_bg1_cell_tbl is the cycle of cell numbers and end_5_bg1_ofs_tbl the four map offsets
 * used to rewrite the looping BG1 strip as it wraps (end_5_bg1_cell_sub). Read by END_5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s8 end_5_bg1_cell_tbl[12] = {
    13, 14, 15, 13, 14, 15, 13, 14,
    15, 13, 14, 15,
};

const s32 end_5_bg1_ofs_tbl[4] = {
    0, 64, 128, 192,
};

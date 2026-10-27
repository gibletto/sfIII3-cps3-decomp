/*
 * EFF94_TBL_B.C  falling piece positions
 *
 * eff94_3000_tbl gives the x, y and facing of the extra falling pieces (eff94_3000) a strong
 * quake throws down. Read by EFF94.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 eff94_3000_tbl[4][3] = {
    { 328, 304, 0 },
    { 288, 240, 1 },
    { 280, 320, 0 },
    { 352, 264, 1 },
};

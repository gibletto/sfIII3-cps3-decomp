/*
 * EFFG9_TBL.C  scatter offsets of the trail particle
 *
 * g9_pos_hos is the 16 random offsets added to a G9 particle's x and y when it appears; a y
 * offset above 1 also puts it behind the characters. Read by EFFG9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 g9_pos_hos[16] = {
    0, 1, -1, 2, -2, 0, 3, -3,
    1, -1, 2, -2, 4, 3, 0, 3,
};

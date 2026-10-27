/*
 * EFF79_TBL.C  depth of the super art plates
 *
 * Pos_Z_Data_79 is the depth offset of each of the three plate slots on the super art
 * selection screen. Read by EFF79.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 Pos_Z_Data_79[3] = {
    0, 5, 10,
};

/*
 * EFF10_TBL.C  character scene object placement
 *
 * scr_obj_num10 starts with the number of objects of each of the four types, followed by the
 * rows of each type (x offset from the owner, y position, animation number), reached through
 * scr_obj_data10. Read by EFF10.C, the character scene objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num10[30] = {
    4, 3, 1, 0, -64, 100, 8, -71,
    42, 9, 26, 96, 10, 70, 26, 11,
    16, 100, 10, -80, 48, 9, 70, 26,
    11, -61, 50, 12, 0, 0,
};

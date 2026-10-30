/*
 * EFF10_TBL.C  character scene object placement
 *
 * scr_obj_num10 gives the number of objects of each of the four types, and scr_obj_data10_N the
 * rows of type N (x offset from the owner, y position, animation number), named by
 * scr_obj_data10. Read by EFF10.C, the character scene objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num10[4] = {
    4, 3, 1, 0,
};

/* type 0; provisional name */
const s16 scr_obj_data10_0[12] = {
    -64, 100, 8,
    -71, 42, 9,
    26, 96, 10,
    70, 26, 11,
};

/* type 1; provisional name */
const s16 scr_obj_data10_1[9] = {
    16, 100, 10,
    -80, 48, 9,
    70, 26, 11,
};

/* type 2; provisional name */
const s16 scr_obj_data10_2[3] = {
    -61, 50, 12,
};

/* type 3 with no objects; provisional name */
const s16 scr_obj_data10_3[2] = {
    0, 0,
};

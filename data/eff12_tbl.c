/*
 * EFF12_TBL.C  animated stage prop list, set 12
 *
 * scr_obj_num12 holds the prop count of each prop type, and scr_obj_data12_N the prop rows
 * (family, colour, position, priority, animation) of type N, named by scr_obj_data12. Read by
 * EFF12.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num12[6] = {
    1, 1, 2, 2, 3, 2,
};

/* prop type 0; provisional name */
const s16 scr_obj_data12_0[8] = {
    0, 1, 128, 512, 128, 86, 8, 0,
};

/* prop type 1; provisional name */
const s16 scr_obj_data12_1[8] = {
    0, 2, 8320, 511, 56, 80, 2, 0,
};

/* prop type 2; provisional name */
const s16 scr_obj_data12_2[16] = {
    0, 2, 8320, 559, 64, 72, 2, 0,
    0, 2, 8320, 463, 112, 72, 4, 0,
};

/* prop type 3; provisional name */
const s16 scr_obj_data12_3[16] = {
    0, 1, 128, 496, 64, 86, 2, 0,
    0, 2, 8320, 607, 96, 83, 8, 0,
};

/* prop type 4; provisional name */
const s16 scr_obj_data12_4[24] = {
    0, 2, 128, 511, 0, 11, 5, 0,
    0, 2, 8320, 560, 168, 79, 9, 0,
    0, 2, 128, 512, 0, 76, 10, 0,
};

/* prop type 5; provisional name */
const s16 scr_obj_data12_5[16] = {
    0, 2, 8320, 575, 80, 74, 20, 0,
    0, 2, 8320, 464, 64, 72, 19, 0,
};

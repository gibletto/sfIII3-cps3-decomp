/*
 * EFF59_TBL.C  attached part offsets and flashing stage objects
 *
 * EFF59_Correct_Data gives the { x, y } offset from its master of each effect 59 part ID;
 * flash_obj_data61_0 .. _2 are the records of the three flashing stage objects of effect 60,
 * reached through flash_obj_data61. Read by EFF59.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];
extern const s16 flash_obj_data61_2[];


/* One row per part ID: x, y offset from the master. */
const s16 EFF59_Correct_Data[6][2] = {
    { 0, 0 }, { 4, 0 }, { 0, 0 }, { 0, 0 }, { 0, -128 }, { 0, 0 },
};

const s16 flash_obj_data61_0[10] = {
    0, 2, 128, 431, 80, 82, 1, 0,
    0, 3,
};

const s16 flash_obj_data61_1[10] = {
    0, 2, 128, 511, 184, 82, 2, 0,
    0, 3,
};

const s16 flash_obj_data61_2[10] = {
    0, 2, 128, 431, 64, 83, 2, 0,
    0, 2,
};


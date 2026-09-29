/*
 * EFF59_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];
extern const s16 flash_obj_data61_2[];


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


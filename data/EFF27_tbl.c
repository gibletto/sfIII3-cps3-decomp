/*
 * EFF27_TBL.C  flying piece tables
 *
 * scr_obj_num27 gives the number of pieces thrown out for each type, and scr_obj_data27_0 and
 * scr_obj_data27_1 the rows of each piece (motion, colour, offset, speeds and animation),
 * reached through scr_obj_data27. Read by EFF27.C, the flying pieces of broken stage objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data27_0[][19];
extern const s16 scr_obj_data27_1[][19];


const s16 scr_obj_num27[2] = {
    3, 3,
};

/* scr_obj_data27_N: 19-word records; words 11-18 of each are four 16.16 values, the integer word and then
   the fraction word (11/12 and 15/16 are the mvxy speeds), the fraction words in hex */
const s16 scr_obj_data27_0[3][19] = {
    { 2, 0x2080, -36, 15, 70, 7, 1, 0, 6, 0, -16, 2, 0, 0, 0, 5, 0x8000, -1, 0x8000 },
    { 2, 0x2080, -52, 18, 10, 8, 1, 0, 6, 0, -16, 2, 0, 0, 0, 5, 0x8000, -1, 0x8000 },
    { 2, 0x2080, -40, 22, 70, 9, 1, 0, 2, 120, 0, -2, 0x8000, 0, 0, 6, 0, -1, 0x8000 },
};

const s16 scr_obj_data27_1[3][19] = {
    { 2, 0x2080, 14, 80, 70, 51, 1, 0, 2, 32, 32, 2, 0, 0, 0, 6, 0x8000, -1, 0xA000 },
    { 2, 0x2080, -4, 96, 10, 50, 1, 0, 2, 52, 52, -2, 0, 0, 0, 7, 0x8000, -1, 0xA000 },
    { 2, 0x2080, -26, 88, 10, 49, 1, 0, 7, 16, 16, -3, 0, 0, 0, 6, 0x8000, -1, 0xD000 },
};


/*
 * BG_DATA.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 bg_index_tbl[22][3] = {
    { 0, 0, 0 }, { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }, { 5, 5, 5 }, { 6, 6, 6 }, { 7, 7, 7 },
    { 8, 8, 8 }, { 9, 9, 9 }, { 10, 10, 10 }, { 11, 11, 11 }, { 12, 12, 12 }, { 13, 13, 13 }, { 14, 14, 14 }, { 15, 15, 15 },
    { 16, 16, 16 }, { 17, 17, 17 }, { 4, 4, 4 }, { 19, 19, 19 }, { 20, 20, 20 }, { 21, 21, 21 },
};

/* Stored after bg_index_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of bg_index_tbl. */
const s16 bg_index_tbl_tail[76] = {
    22, 22, 22, 256, 256, 312, 0, 0,
    0, 256, 256, 312, 0, 0, 0, 256,
    256, 312, 0, 0, 0, 256, 256, 312,
    0, 0, 0, 256, 256, 312, 0, 0,
    0, 256, 256, 312, 0, 0, 0, 256,
    256, 312, 0, 0, 0, 256, 256, 312,
    0, 0, 0, 256, 256, 312, 0, 0,
    0, 256, 256, 312, 0, 0, 0, 256,
    256, 312, 0, 0, 0, 256, 256, 312,
    0, 0, 0, 0,
};


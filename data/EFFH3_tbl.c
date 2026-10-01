/*
 * EFFH3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void effH5_0000();
extern void effH5_0001();
extern void effH5_0002();
extern void effH5_0003();
extern void effH5_0004();

const s16 effH3_data_tbl[5][3] = {
    { 512, 0, 0 },
    { 256, 136, 2 },
    { 768, 136, 2 },
    { 256, 280, 2 },
    { 768, 280, 2 },
};

/* Stored after effH3_data_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of effH3_data_tbl. */
const s16 effH3_data_tbl_tail[17] = {
    0, 9, 592, 128, 72, 10, 576, 96,
    70, 12, 432, 128, 72, 11, 448, 96,
    70,
};

const s32 effH4_sp_tbl[4][3] = {
    { 688128, 229376, -65536 },
    { 557056, 229376, -65536 },
    { -688128, -229376, -65536 },
    { -557056, -229376, -65536 },
};

const s16 effH5_data_tbl[11][8] = {
    { 1, 32, 27, 324, 120, 80, 1, 0 },
    { 1, 32, 27, 360, 136, 82, 2, 0 },
    { 1, 32, 27, 616, 80, 82, 3, 0 },
    { 1, 32, 28, 408, 56, 82, 1, 1 },
    { 1, 32, 29, 592, 120, 82, 1, 1 },
    { 1, 32, 27, 624, 56, 82, 4, 0 },
    { 1, 32, 27, 428, 120, 80, 1, 0 },
    { 1, 32, 31, 432, 120, 82, 1, 2 },
    { 1, 32, 30, 464, 136, 82, 1, 4 },
    { 2, 32, 32, 512, 48, 80, 1, 3 },
    { 1, 32, 27, 143, 56, 81, 5, 0 },
};

/* Initial values of H5_Jmp_Tbl (effect_H5_move) in EFFH3.c. */
const u32 H5_Jmp_Tbl_init[5] = {
    (u32)effH5_0000,
    (u32)effH5_0001,
    (u32)effH5_0002,
    (u32)effH5_0003,
    (u32)effH5_0004,
};

/*
 * EFFI8_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effI8_hit_box[2][4] = {
    { -9, 17, -6, 12 },
    { -4, 10, 114, 9 },
};

const s16 bbbs_emtall[24] = {
    84, 76, 68, 58, 76, 64, 92, 60,
    56, 52, 58, 68, 68, 84, 68, 68,
    64, 58, 88, 58, 76, 0, 0, 0,
};

const u16 cbm_table[8][5] = {
    { 0x3FFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF00 },
    { 0x1FFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF00 },
    { 0xFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFE00 },
    { 0x1FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFC00 },
    { 3, 0xFFFF, 0xFFFF, 0xFFFF, 0xF800 },
    { 1, 0xFFFF, 0xFFFF, 0xFFFF, 0xF000 },
    { 0, 0xF, 0xFFFF, 0xFFFF, 0x8000 },
    { 0, 0, 0xFFF, 0xFFFE, 0 },
};

/* Stored after cbm_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of cbm_table. */
const u16 cbm_table_tail[2] = {
    0, 0,
};


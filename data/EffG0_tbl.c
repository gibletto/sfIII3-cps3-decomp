/*
 * EFFG0_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u32 suji_table_G0[6] = {
    1, 0xA, 0x64, 0x3E8, 0x2710, 0x186A0,
};

const u16 suji_numobj_G0[10] = {
    0xBD33, 0xBD34, 0xBD35, 0xBD36, 0xBD37, 0xBD38, 0xBD39, 0xBD3A,
    0xBD3B, 0xBD3C,
};

const CONN Result_Score[6] = {
    { 40, 0, 0, 0xBD33 },
    { 32, 0, 0, 0xBD33 },
    { 24, 0, 0, 0xBD33 },
    { 16, 0, 0, 0xBD33 },
    { 8, 0, 0, 0xBD33 },
    { 0, 0, 0, 0xBD33 },
};

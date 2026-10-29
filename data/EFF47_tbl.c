/*
 * EFF47_TBL.C  scattering piece tables
 *
 * eff47_data_tbl gives the offset from the character and the life time of each of the four
 * pieces, and eff47_sp_tbl their speeds and accelerations. Read by EFF47.C, the four
 * scattering pieces.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s32 eff47_sp_tbl[4][4] = {
    { 0x40000, -0x1000, 0x30000, -0x4000 },
    { -0x20000, 0x800, 0x30000, -0x4000 },
    { 0x10000, 0, 0x20000, -0x4000 },
    { -0x50000, 0x1000, 0x40000, -0x4000 },
};

const s16 eff47_data_tbl[12] = {
    16, 144, 50, -68, 122, 50, 24, 48,
    30, -37, 70, 30,
};

/*
 * EFFD0_TBL.C  bouncing thrown object arcs
 *
 * effd0_data_tbl gives the speeds and accelerations of each arc of the thrown object and
 * effd0_conter the time of each arc. Read by EFFD0.C, the thrown object that bounces along the
 * floor.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 effd0_data_tbl[9][4] = {
    { 0x4000, -0x800, -0x6000, -0x400 },
    { -0x4000, 0x600, -0x4000, -0x600 },
    { 0x4000, -0xC00, -0x3000, -0x400 },
    { 0x800, -0x300, -0x6000, -0x600 },
    { 0, -0x100, -0x5000, -0x500 },
    { 0x6000, -0xA00, -0x3000, -0x600 },
    { 0x6000, 0xA00, -0x2000, -0x500 },
    { -0x6000, 0xA00, -0x1000, -0x500 },
    { -0x4000, 0x600, -0x4000, -0x600 },
};

const s16 effd0_conter[9] = {
    32, 40, 30, 48, 64, 16, 32, 36,
    72,
};


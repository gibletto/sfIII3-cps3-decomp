/*
 * EFFJ8_TBL_B.C  dragonfly flight speeds
 *
 * effj8_sp_tbl is the eight random flight lines, four speed values each, that a dragonfly
 * picks when it enters the screen. Read by EFFJ8.C, the dragonflies of the stage background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s32 effj8_sp_tbl[8][4] = {
    { 0x60000, -0x4000, 0x4000, 0 },
    { 0x60000, -0x4800, -0x4000, 0 },
    { 0x60000, -0x1000, 0x4000, 0 },
    { 0x60000, -0x2000, -0x4000, 0 },
    { 0x80000, -0xA000, 0x4000, 0 },
    { 0x80000, -0x2000, -0x4000, 0 },
    { 0x80000, -0x6000, 0x4000, 0 },
    { 0x80000, -0x4000, -0x4000, 0 },
};

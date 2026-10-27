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
    { 393216, -16384, 16384, 0 },
    { 393216, -18432, -16384, 0 },
    { 393216, -4096, 16384, 0 },
    { 393216, -8192, -16384, 0 },
    { 524288, -40960, 16384, 0 },
    { 524288, -8192, -16384, 0 },
    { 524288, -24576, 16384, 0 },
    { 524288, -16384, -16384, 0 },
};

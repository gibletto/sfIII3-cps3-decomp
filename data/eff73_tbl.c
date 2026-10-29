/*
 * EFF73_TBL.C  scattering creature tables
 *
 * eff73_sp_tbl gives the starting speeds of the four creatures, eff73_vanish_tbl their random
 * vanish times and eff73_survive_tbl the random choice of the one that flies on. Read by
 * EFF73.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 eff73_sp_tbl[4][3] = {
    { 0x28000, -0x18000, -0x800 },
    { 0x10000, 0x8000, 0x20000 },
    { -0x4000, 0, 0 },
    { -0x10000, 0x8000, 0x28000 },
};

const s16 eff73_vanish_tbl[8] = {
    60, 24, 38, 14, 22, 28, 18, 40,
};

const s16 eff73_survive_tbl[8] = {
    0, 1, 2, 3, 3, 2, 1, 0,
};

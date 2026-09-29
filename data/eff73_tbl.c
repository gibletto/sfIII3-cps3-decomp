/*
 * EFF73_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 eff73_sp_tbl[4][3] = {
    { 163840, -98304, -2048 },
    { 65536, 32768, 131072 },
    { -16384, 0, 0 },
    { -65536, 32768, 163840 },
};

const s16 eff73_vanish_tbl[8] = {
    60, 24, 38, 14, 22, 28, 18, 40,
};

const s16 eff73_survive_tbl[8] = {
    0, 1, 2, 3, 3, 2, 1, 0,
};

/*
 * EFF47_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s32 eff47_sp_tbl[4][4] = {
    { 262144, -4096, 196608, -16384 },
    { -131072, 2048, 196608, -16384 },
    { 65536, 0, 131072, -16384 },
    { -327680, 4096, 262144, -16384 },
};

const s16 eff47_data_tbl[12] = {
    16, 144, 50, -68, 122, 50, 24, 48,
    30, -37, 70, 30,
};

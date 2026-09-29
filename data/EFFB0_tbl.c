/*
 * EFFB0_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effb0_timer_tbl[8] = {
    60, 30, 120, 150, 8, 20, 10, 90,
};

const s16 effb0_data_tbl[8][2] = {
    { 656, 112 },
    { 328, 96 },
    { 352, 224 },
    { 688, 144 },
    { 344, 128 },
    { 640, 224 },
    { 336, 176 },
    { 672, 72 },
};

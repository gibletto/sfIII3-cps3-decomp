/*
 * EFFB0_TBL.C  ending scene twinkle tables
 *
 * effb0_data_tbl gives the eight positions the twinkles appear at and effb0_timer_tbl the
 * random waits between them. Read by EFFB0.C, the ending scene twinkles.
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

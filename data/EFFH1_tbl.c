/*
 * EFFH1_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effh1_wait_timer[8] = {
    30, 120, 180, 40, 10, 200, 240, 50,
};

const s16 effh1_data_tbl[8][5] = {
    { -96, 256, 74, 34, 10 },
    { 64, 288, 74, 34, 8 },
    { -64, 256, 78, 35, 4 },
    { 128, 272, 78, 35, 28 },
    { -32, 240, 74, 34, 2 },
    { 96, 240, 74, 34, 2 },
    { -160, 224, 78, 35, 2 },
    { 128, 224, 78, 35, 2 },
};

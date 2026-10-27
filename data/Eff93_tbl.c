/*
 * EFF93_TBL.C  stage background object counts for effects 87 and 88
 *
 * eff87_loop_tbl and eff88_loop_tbl give the number of background objects to spawn by type and
 * compel flag; scr_obj_data87_0 is the empty object list that the effect 87 record table
 * points to. Read by EFF87.C and EFF88.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data87_0[];


const s16 eff87_loop_tbl[1][4] = {
    { 0, 0, 0, 0 },
};

const s16 scr_obj_data87_0[2] = {
    0, 0,
};

const s16 eff88_loop_tbl[4][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 32 },
    { 64, 96, 128, 160 },
    { 192, 224, 256, 0 },
};

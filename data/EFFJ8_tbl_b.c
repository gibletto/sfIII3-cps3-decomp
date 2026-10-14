/*
 * EFFJ8_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void dragonfly_l_move();
extern void dragonfly_move_0000();
extern void dragonfly_move_0001();
extern void dragonfly_move_0004();
extern void dragonfly_move_0005();
extern void dragonfly_r_move();

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

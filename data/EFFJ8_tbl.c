/*
 * EFFJ8_TBL.C  game tables
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

const s16 effj8_timer_tbl[8] = {
    60, 120, 180, 90, 150, 30, 220, 160,
};

const s16 effj8_y_tbl[8] = {
    128, 80, 96, 160, 176, 112, 144, 168,
};

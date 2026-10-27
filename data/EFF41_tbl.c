/*
 * EFF41_TBL.C  super art sign tables and select-screen zoom positions
 *
 * sa_sign_data has one row per super art sign: offset from the player, animation number, gauge
 * used (super art or EX) and the eff41_main_process routine that places it. Read by EFF41.C,
 * the super art sign. eff40_pos_x_tbl gives the x position of the select-screen zoom object
 * for each direction, read by EFF40.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff41_process_00();
extern void eff41_process_01();

const s16 eff40_pos_x_tbl[8] = {
    -109, -83, -54, -24, 24, 48, 72, 96,
};

/*
 * One row per super art sign (effect_41_init's data): x offset from the player
 * (mirrored by rl_flag), y offset, animation number, gauge used (1 super art, 2 EX)
 * and the eff41_main_process routine that places it.
 */
const s16 sa_sign_data[69][5] = {
    { 28, 70, 156, 1, 1 },
    { -41, 37, 156, 1, 1 },
    { 12, 56, 156, 1, 1 },
    { -14, 80, 156, 1, 1 },
    { -14, 48, 156, 1, 1 },
    { -28, 56, 156, 1, 1 },
    { -12, 56, 156, 1, 1 },
    { -20, 84, 156, 1, 1 },
    { -38, 44, 156, 1, 1 },
    { 48, 92, 156, 1, 1 },
    { -44, 51, 156, 1, 1 },
    { -30, 28, 156, 1, 1 },
    { -30, 28, 156, 1, 1 },
    { 28, 70, 156, 1, 1 },
    { -32, 42, 156, 1, 1 },
    { 0, 72, 156, 1, 1 },
    { 14, 65, 156, 1, 1 },
    { -30, 28, 156, 1, 1 },
    { -58, 60, 156, 1, 1 },
    { -20, 64, 156, 1, 1 },
    { -22, 66, 156, 1, 1 },
    { 22, 66, 156, 1, 1 },
    { 0, 48, 156, 1, 1 },
    { -22, 74, 156, 1, 1 },
    { -36, 52, 156, 1, 1 },
    { -32, 48, 156, 1, 1 },
    { -12, 40, 156, 1, 1 },
    { -24, 68, 156, 1, 1 },
    { -3, 72, 156, 1, 1 },
    { 2, 72, 156, 1, 1 },
    { 20, 130, 159, 2, 0 },
    { 0, 72, 156, 1, 1 },
    { 28, 10, 156, 1, 1 },
    { -48, 144, 158, 2, 0 },
    { -16, 88, 156, 1, 1 },
    { -58, 74, 156, 1, 1 },
    { -16, 88, 156, 1, 1 },
    { -9, 100, 158, 2, 0 },
    { -57, 48, 157, 0, 0 },
    { 25, 53, 156, 1, 1 },
    { -28, 44, 156, 1, 1 },
    { -22, 72, 156, 1, 1 },
    { -22, 72, 156, 1, 1 },
    { -21, 123, 156, 1, 1 },
    { -13, 67, 156, 1, 1 },
    { -22, 56, 156, 1, 1 },
    { 32, 24, 156, 1, 1 },
    { -64, 62, 156, 1, 1 },
    { -32, 64, 156, 1, 1 },
    { -17, 52, 156, 1, 1 },
    { 3, 53, 156, 1, 1 },
    { -12, 104, 160, 2, 0 },
    { 14, 56, 158, 2, 0 },
    { 31, 90, 156, 1, 1 },
    { -16, 80, 156, 1, 1 },
    { -2, 58, 156, 1, 1 },
    { 24, 105, 156, 1, 1 },
    { -37, 70, 156, 1, 1 },
    { -21, 87, 156, 1, 1 },
    { -11, 83, 156, 1, 1 },
    { -4, 120, 158, 1, 0 },
    { -36, 76, 156, 1, 1 },
    { 38, 60, 156, 1, 1 },
    { -8, 74, 156, 1, 1 },
    { -5, 52, 158, 1, 0 },
    { -7, 73, 156, 1, 1 },
    { -8, 90, 156, 1, 1 },
    { -18, 16, 156, 1, 1 },
    { 14, 56, 158, 1, 0 },
};

void (*const eff41_main_process[2])() = {
    eff41_process_00,
    eff41_process_01,
};

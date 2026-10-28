/*
 * EFF11_TBL.C  bg000 quake-reacting object tables
 *
 * eff11_data_tbl gives the colour, position, priority, animation and jump type of each of the
 * four objects. eff11_quake_index_tbl turns the background quake index into a jump level, and
 * eff11_quake_speed_y_tbl, eff11_quake_speed_y_tbl2 and eff11_quake_speed_x_tbl give the jump
 * and bounce speeds by jump type and level. Read by EFF11.C, the bg000 stage objects that jump
 * when the screen quakes.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


/* one row per object: { colour code, x, y, priority, char_index, old_rno[3] } */
const s16 eff11_data_tbl[4][6] = {
    { 0x2080, 816, 51, 80, 6, 0 },
    { 0x2080, 176, 51, 80, 6, 0 },
    { 0x2080, 720, 55, 80, 12, 1 },
    { 0x2080, 240, 55, 80, 12, 1 },
};

const s16 eff11_quake_index_tbl[111] = {
    0, 0, 0, 1, 1, 2, 2, 3,
    3, 3, 4, 4, 5, 5, 5, 6,
    6, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7,
};

const s32 eff11_quake_speed_y_tbl[2][8] = {
    { 98304, 147456, 196608, 262144, 327680, 491520, 524288, 622592 },
    { 65536, 131072, 131072, 196608, 262144, 360448, 393216, 491520 },
};

const s32 eff11_quake_speed_y_tbl2[2][4] = {
    { 196608, 131072, 98304, 65536 },
    { 163840, 98304, 49152, 40960 },
};

const s32 eff11_quake_speed_x_tbl[2][8] = {
    { 49152, 49152, 40960, 40960, 32768, 24576, 40960, 49152 },
    { 40960, 40960, 49152, 49152, 65536, 40960, 40960, 32768 },
};

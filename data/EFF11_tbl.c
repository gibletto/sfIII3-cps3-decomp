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
    { 0x18000, 0x24000, 0x30000, 0x40000, 0x50000, 0x78000, 0x80000, 0x98000 },
    { 0x10000, 0x20000, 0x20000, 0x30000, 0x40000, 0x58000, 0x60000, 0x78000 },
};

const s32 eff11_quake_speed_y_tbl2[2][4] = {
    { 0x30000, 0x20000, 0x18000, 0x10000 },
    { 0x28000, 0x18000, 0xC000, 0xA000 },
};

const s32 eff11_quake_speed_x_tbl[2][8] = {
    { 0xC000, 0xC000, 0xA000, 0xA000, 0x8000, 0x6000, 0xA000, 0xC000 },
    { 0xA000, 0xA000, 0xC000, 0xC000, 0x10000, 0xA000, 0xA000, 0x8000 },
};

/*
 * EFF24_TBL.C  bg050 quake-shaken objects and bg130 breakable object tables
 *
 * eff24_data_tbl gives the colour, position, priority, animation and bounce type of each
 * effect 24 object. eff24_quake_index_tbl turns the background quake index into a bounce
 * level, eff24_quake_speed_y_tbl and eff24_quake_speed_x_tbl give the bounce speeds by type
 * and level, and dog24_x_data the distances the dog runs. Read by EFF24.C, the bg050 objects
 * shaken by quakes. scr_obj_data25_0 is the object list of the breakable objects, reached
 * through scr_obj_data25 in EFF25.C, the bg130 breakable stage objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data25_0[];


/* one row per object: { colour code, x, y, priority, char_index, old_rno[3], old_rno[7] } */
const s16 eff24_data_tbl[8][7] = {
    { 0x2080, 480, 6, 10, 12, 2, 0 },
    { 0x80, 224, 43, 81, 3, 1, 1 },
    { 0x80, 288, 44, 80, 4, 2, 1 },
    { 0x80, 512, 48, 80, 5, 1, 0 },
    { 0x2080, 512, 48, 80, 6, 2, 0 },
    { 0x80, 644, 48, 80, 7, 1, 1 },
    { 0x80, 752, 48, 81, 8, 3, 1 },
    { 0x80, 800, 32, 80, 9, 3, 1 },
};

const s16 eff24_quake_index_tbl[111] = {
    0, 0, 0, 1, 1, 1, 2, 2,
    3, 3, 3, 4, 4, 5, 5, 6,
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

const s32 eff24_quake_speed_y_tbl[4][8] = {
    { 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000, 0xC0000 },
    { 0xE000, 0x10000, 0x1C000, 0x24000, 0x30000, 0x48000, 0x60000, 0x80000 },
    { 0xC000, 0xE000, 0x10000, 0x18000, 0x20000, 0x30000, 0x48000, 0x60000 },
    { 0x2000, 0x8000, 0xC000, 0x10000, 0x18000, 0x20000, 0x30000, 0x60000 },
};

const s32 eff24_quake_speed_x_tbl[4][8] = {
    { 0x1200, 0x1200, 0x1400, 0x1400, 0x1000, 0x1200, 0x1200, 0x1400 },
    { 0x1800, 0x1800, 0x1400, 0x1400, 0x1000, 0x1800, 0x1400, 0x1400 },
    { 0x1000, 0x1000, 0x800, 0x800, 0x800, 0x800, 0x400, 0x400 },
    { 0x400, 0x400, 0x800, 0x800, 0x400, 0x400, 0x400, 0x400 },
};

const s16 dog24_x_data[8] = {
    0, 0, 0, 6, 10, 16, 32, 40,
};

const s16 scr_obj_data25_0[16] = {
    0, 2, 128, 160, 32, 71, 6, 0,
    0, 0, 6, 6, 66, 9, 0, -1,
};


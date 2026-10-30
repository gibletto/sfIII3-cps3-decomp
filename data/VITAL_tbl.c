/*
 * VITAL_TBL.C  vitality bar and round timer tables
 *
 * vital_cell_tbl and vital_cell_1p_tbl are the text-layer cells of the vitality bars,
 * vital_npos_0 and vital_npos_1 the cell columns of the 1P and 2P bars and vital_attr_0 ..
 * vital_attr_2 the cell attributes for each bar colour, reached through vital_npos_tbl and
 * vital_attr_tbl; read by VITAL.C. vital_unref_0 is not referred to. hoji_counter_tbl is the
 * round timer tick length for each game-speed setting, read by COUNT.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u16 vital_cell_tbl[81] = {
    0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x80,
    0xAC, 0xAB, 0xAA, 0xA9, 0xA8, 0xA7, 0xA6, 0xA5,
    0x88, 0, 0xA4, 0xA3, 0xA2, 0xA1, 0xA0, 0x9F,
    0x89, 0, 0, 0x9E, 0x9D, 0x9C, 0x9B, 0x9A,
    0x8A, 0, 0, 0, 0x99, 0x98, 0x97, 0x96,
    0x8B, 0, 0, 0, 0, 0x95, 0x94, 0x93,
    0x8C, 0, 0, 0, 0, 0, 0x92, 0x91,
    0x8D, 0, 0, 0, 0, 0, 0, 0x90,
    0x8E, 0, 0, 0, 0, 0, 0, 0,
    0x8F, 0, 0, 0, 0, 0, 0, 0,
    0,
};

const u16 vital_cell_1p_tbl[81] = {
    0x137, 0x136, 0x135, 0x134, 0x133, 0x132, 0x131, 0x130,
    0x15C, 0x15B, 0x15A, 0x159, 0x158, 0x157, 0x156, 0x155,
    0x138, 0, 0x154, 0x153, 0x152, 0x151, 0x150, 0x15F,
    0x139, 0, 0, 0x14E, 0x14D, 0x14C, 0x14B, 0x14A,
    0x13A, 0, 0, 0, 0x149, 0x148, 0x147, 0x146,
    0x13B, 0, 0, 0, 0, 0x145, 0x144, 0x143,
    0x13C, 0, 0, 0, 0, 0, 0x142, 0x141,
    0x13D, 0, 0, 0, 0, 0, 0, 0x140,
    0x13E, 0, 0, 0, 0, 0, 0, 0,
    0x13F, 0, 0, 0, 0, 0, 0, 0,
    0,
};

/* cell columns of the 1P bar, reached through vital_npos_tbl[0]; provisional name */
const u16 vital_npos_0[20] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10,
    0x11, 0x12, 0x13, 0x14,
};

/* cell columns of the 2P bar, reached through vital_npos_tbl[1]; provisional name */
const u16 vital_npos_1[20] = {
    0x2E, 0x2D, 0x2C, 0x2B, 0x2A, 0x29, 0x28, 0x27,
    0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1F,
    0x1E, 0x1D, 0x1C, 0x1B,
};

/* cell attributes for each bar colour, reached through vital_attr_tbl[0]; provisional name */
const u16 vital_attr_0[3] = {
    2, 4, 6,
};

/* cell attributes for each bar colour, reached through vital_attr_tbl[1]; provisional name */
const u16 vital_attr_1[3] = {
    0x82, 0x84, 0x86,
};

/* cell attributes for each bar colour, reached through vital_attr_tbl[2]; provisional name */
const u16 vital_attr_2[3] = {
    2, 4, 6,
};

/* not referred to; provisional name */
const u16 vital_unref_0[1] = {
    0,
};

const s16 hoji_counter_tbl[4] = {
    60, 53, 37, 29,
};

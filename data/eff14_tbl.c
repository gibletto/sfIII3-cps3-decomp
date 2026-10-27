/*
 * EFF14_TBL.C  background colour-cycle scripts
 *
 * eff14_ofs_tbl is the screen offset of each id's cells; eff14_data_tbl points each id at its
 * script (eff14_script_n: timer, column, then steps), its cell pattern (eff14_pattern_n) and
 * its size in columns and rows (eff14_size_n). Read by EFF14.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

/* a script step: the frames it lasts, then the colour, a big-endian word (EFF14.C reads it with *(s16*)) */
#define EFF14_STEP(time, col)   0, (time), (s8)((col) >> 8), (s8)(col)
#define EFF14_END               -1, -1

extern const u16 eff14_ofs_tbl[11];
extern const s8 eff14_script_0[];
extern const s8 eff14_script_1[];
extern const s8 eff14_script_2[];
extern const s8 eff14_script_3[];
extern const s8 eff14_script_4[];
extern const s8 eff14_script_5[];
extern const s8 eff14_script_6[];
extern const s8 eff14_script_8[];
extern const s8 eff14_script_9[];
extern const s8 eff14_script_10[];
extern const s8 eff14_pattern_0[];
extern const s8 eff14_size_0[];
extern const s8 eff14_pattern_1[];
extern const s8 eff14_size_1[];
extern const s8 eff14_pattern_2[];
extern const s8 eff14_size_2[];
extern const s8 eff14_pattern_3[];
extern const s8 eff14_size_3[];
extern const s8 eff14_pattern_4[];
extern const s8 eff14_size_4[];
extern const s8 eff14_pattern_5[];
extern const s8 eff14_size_5[];
extern const s8 eff14_pattern_6[];
extern const s8 eff14_size_6[];
extern const s8 eff14_pattern_7[];
extern const s8 eff14_size_7[];
extern const s8 eff14_pattern_8[];
extern const s8 eff14_size_8[];
extern const s8 eff14_pattern_9[];
extern const s8 eff14_size_9[];
extern const s8 eff14_pattern_10[];
extern const s8 eff14_size_10[];

/* the offset in the screen of each effect id's cells */
const u16 eff14_ofs_tbl[11] = {
    0x10, 0x1160, 0x153c, 0x1440, 0xe10, 0x1b70, 0xd64, 0x12a0, 0x1440, 0x1450, 0x1320,
};

/* each id's script (timer, column, then steps), cell pattern and size (columns, rows); eff14_data_tbl points at them */
const s8 eff14_script_0[76] = {
    EFF14_STEP(3, 0x80), EFF14_STEP(3, 0x9D), EFF14_STEP(3, 0x9E), EFF14_STEP(3, 0x80),
    EFF14_STEP(1, 0x9F), EFF14_STEP(3, 0x9D), EFF14_STEP(3, 0x9E), EFF14_STEP(3, 0x80),
    EFF14_STEP(3, 0x9D), EFF14_STEP(3, 0x9E), EFF14_STEP(3, 0x80), EFF14_STEP(3, 0x9D),
    EFF14_STEP(1, 0x9F), EFF14_STEP(3, 0x9E),
    EFF14_END, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_script_1[76] = {
    EFF14_STEP(3, 0x81), EFF14_STEP(3, 0xA0), EFF14_STEP(3, 0xA1), EFF14_STEP(3, 0x81),
    EFF14_STEP(1, 0xA2), EFF14_STEP(3, 0xA0), EFF14_STEP(3, 0xA1), EFF14_STEP(3, 0x81),
    EFF14_STEP(3, 0xA0), EFF14_STEP(3, 0xA1), EFF14_STEP(3, 0x81), EFF14_STEP(3, 0xA0),
    EFF14_STEP(1, 0xA2), EFF14_STEP(3, 0xA1),
    EFF14_END, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_script_2[76] = {
    EFF14_STEP(3, 0x82), EFF14_STEP(3, 0xA3), EFF14_STEP(3, 0xA4), EFF14_STEP(3, 0x82),
    EFF14_STEP(1, 0xA5), EFF14_STEP(3, 0xA3), EFF14_STEP(3, 0xA4), EFF14_STEP(3, 0x82),
    EFF14_STEP(3, 0xA3), EFF14_STEP(3, 0xA4), EFF14_STEP(3, 0x82), EFF14_STEP(3, 0xA3),
    EFF14_STEP(1, 0xA5), EFF14_STEP(3, 0xA4),
    EFF14_END, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_script_3[76] = {
    EFF14_STEP(3, 0x83), EFF14_STEP(3, 0xA6), EFF14_STEP(3, 0xA7), EFF14_STEP(3, 0x83),
    EFF14_STEP(1, 0xA8), EFF14_STEP(3, 0xA6), EFF14_STEP(3, 0xA7), EFF14_STEP(3, 0x83),
    EFF14_STEP(3, 0xA6), EFF14_STEP(3, 0xA7), EFF14_STEP(3, 0x83), EFF14_STEP(3, 0xA6),
    EFF14_STEP(1, 0xA8), EFF14_STEP(3, 0xA7),
    EFF14_END, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_script_4[76] = {
    EFF14_STEP(3, 0x84), EFF14_STEP(3, 0xA9), EFF14_STEP(3, 0xAA), EFF14_STEP(3, 0x84),
    EFF14_STEP(1, 0xAB), EFF14_STEP(3, 0xA9), EFF14_STEP(3, 0xAA), EFF14_STEP(3, 0x84),
    EFF14_STEP(3, 0xA9), EFF14_STEP(3, 0xAA), EFF14_STEP(3, 0x84), EFF14_STEP(3, 0xA9),
    EFF14_STEP(1, 0xAB), EFF14_STEP(3, 0xAA),
    EFF14_END, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_script_5[28] = {
    EFF14_STEP(6, 0x90), EFF14_STEP(6, 0xAF), EFF14_STEP(6, 0xB0), EFF14_STEP(6, 0xB1),
    EFF14_STEP(6, 0xB0), EFF14_STEP(6, 0xAF),
    EFF14_END, 0, 0,
};
const s8 eff14_script_6[44] = {
    EFF14_STEP(7, 0x91), EFF14_STEP(7, 0x92), EFF14_STEP(7, 0x93), EFF14_STEP(7, 0x94),
    EFF14_STEP(7, 0x95), EFF14_STEP(7, 0x96), EFF14_STEP(7, 0x95), EFF14_STEP(7, 0x94),
    EFF14_STEP(7, 0x93), EFF14_STEP(7, 0x92),
    EFF14_END, 0, 0,
};
const s8 eff14_script_8[20] = {
    EFF14_STEP(4, 0x99), EFF14_STEP(4, 0xF7), EFF14_STEP(4, 0xF9), EFF14_STEP(4, 0xF7),
    EFF14_END, 0, 0,
};
const s8 eff14_script_9[20] = {
    EFF14_STEP(4, 0x9A), EFF14_STEP(4, 0xF8), EFF14_STEP(4, 0xFA), EFF14_STEP(4, 0xF8),
    EFF14_END, 0, 0,
};
const s8 eff14_script_10[12] = {
    EFF14_STEP(2, 0x8C), EFF14_STEP(2, 0x90),
    EFF14_END, 0, 0,
};
const s8 eff14_pattern_0[420] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 2, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
const s8 eff14_size_0[2] = {
    20, 21,
};
const s8 eff14_pattern_1[42] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
};
const s8 eff14_size_1[2] = {
    7, 6,
};
const s8 eff14_pattern_2[91] = {
    0, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const s8 eff14_size_2[2] = {
    13, 7,
};
const s8 eff14_pattern_3[33] = {
    1, 1, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0,
};
const s8 eff14_size_3[2] = {
    11, 3,
};
const s8 eff14_pattern_4[108] = {
    1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1,
    1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
    1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const s8 eff14_size_4[2] = {
    12, 9,
};
const s8 eff14_pattern_5[60] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
const s8 eff14_size_5[2] = {
    30, 2,
};
const s8 eff14_pattern_6[9] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1,
};
const s8 eff14_size_6[2] = {
    3, 3,
};
const s8 eff14_pattern_7[4] = {
    1, 1, 1, 1,
};
const s8 eff14_size_7[2] = {
    2, 2,
};
const s8 eff14_pattern_8[16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
const s8 eff14_size_8[2] = {
    4, 4,
};
const s8 eff14_pattern_9[12] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
const s8 eff14_size_9[2] = {
    3, 4,
};
const s8 eff14_pattern_10[63] = {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
};
const s8 eff14_size_10[4] = {
    9, 7, 0, 0,
};

const u32 eff14_data_tbl[11][5] = {
    { 1, 0, (u32)eff14_script_0, (u32)eff14_pattern_0, (u32)eff14_size_0 },
    { 1, 1, (u32)eff14_script_1, (u32)eff14_pattern_1, (u32)eff14_size_1 },
    { 1, 2, (u32)eff14_script_2, (u32)eff14_pattern_2, (u32)eff14_size_2 },
    { 1, 3, (u32)eff14_script_3, (u32)eff14_pattern_3, (u32)eff14_size_3 },
    { 1, 4, (u32)eff14_script_4, (u32)eff14_pattern_4, (u32)eff14_size_4 },
    { 0, 5, (u32)eff14_script_5, (u32)eff14_pattern_5, (u32)eff14_size_5 },
    { 0, 0, (u32)eff14_script_6, (u32)eff14_pattern_6, (u32)eff14_size_6 },
    { 0, 1, (u32)eff14_script_6, (u32)eff14_pattern_7, (u32)eff14_size_7 },
    { 1, 0, (u32)eff14_script_8, (u32)eff14_pattern_8, (u32)eff14_size_8 },
    { 1, 1, (u32)eff14_script_9, (u32)eff14_pattern_9, (u32)eff14_size_9 },
    { 0, 0, (u32)eff14_script_10, (u32)eff14_pattern_10, (u32)eff14_size_10 },
};

/*
 * REMY_YUCA.C  Remy's animation scripts
 *
 * The animation scripts Remy's moves run, one table per kind of script (yuca),
 * each an index of scripts ending in 0 followed by the scripts. set_char_base_data (CHARID)
 * installs the tables as char_table[]; set_char_move_init2 starts script char_table[kind][index]
 * and char_move steps it: a frame line shows sprite `number` for `ctr` frames with its sound, hit
 * boxes (hit_ix into the hit_ix_table), attack (att into the catt_table) and effect; a command
 * line (CM_ codes) jumps, loops, tests and sets. See charscr.h for the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 remy_yuca_000[], remy_yuca_001[], remy_yuca_004[], remy_yuca_003[], remy_yuca_008[], remy_yuca_012[], remy_yuca_009[], remy_yuca_011[], remy_yuca_016[], remy_yuca_024[], remy_yuca_032[], remy_yuca_033[], remy_yuca_036[], remy_yuca_037[], remy_yuca_038[], remy_yuca_039[], remy_yuca_040[], remy_yuca_041[], remy_yuca_048[], remy_yuca_060[], remy_yuca_061[], remy_yuca_062[], remy_yuca_063[], remy_yuca_068[];
extern const u16 remy_yuca_000_head[];
extern const u16 remy_yuca_001_head[];
extern const u16 remy_yuca_004_head[];
extern const u16 remy_yuca_003_head[];
extern const u16 remy_yuca_008_head[];
extern const u16 remy_yuca_012_head[];
extern const u16 remy_yuca_009_head[];
extern const u16 remy_yuca_011_head[];
extern const u16 remy_yuca_016_head[];
extern const u16 remy_yuca_024_head[];
extern const u16 remy_yuca_032_head[];
extern const u16 remy_yuca_033_head[];
extern const u16 remy_yuca_036_head[];
extern const u16 remy_yuca_037_head[];
extern const u16 remy_yuca_038_head[];
extern const u16 remy_yuca_039_head[];
extern const u16 remy_yuca_040_head[];
extern const u16 remy_yuca_041_head[];
extern const u16 remy_yuca_048_head[];
extern const u16 remy_yuca_060_head[];
extern const u16 remy_yuca_061_head[];
extern const u16 remy_yuca_062_head[];
extern const u16 remy_yuca_063_head[];
extern const u16 remy_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const remy_yuca[92] = {
    remy_yuca_000,  /* 0 APPEAR JUNBI 1 */
    remy_yuca_001,  /* 1 APPEAR JUNBI 2 */
    remy_yuca_000,  /* 2 APPEAR JUNBI 3 */
    remy_yuca_003,  /* 3 APPEAR JUNBI 4 */
    remy_yuca_004,  /* 4 APPEAR JUNBI 5 */
    remy_yuca_001,  /* 5 APPEAR JUNBI 6 */
    remy_yuca_000,  /* 6 APPEAR JUNBI 7 */
    remy_yuca_000,  /* 7 APPEAR JUNBI 8 */
    remy_yuca_008,  /* 8 APPEAR 1 */
    remy_yuca_009,  /* 9 APPEAR 2 */
    remy_yuca_008,  /* 10 APPEAR 3 */
    remy_yuca_011,  /* 11 APPEAR 4 */
    remy_yuca_012,  /* 12 APPEAR 5 */
    remy_yuca_009,  /* 13 APPEAR 6 */
    remy_yuca_008,  /* 14 APPEAR 7 */
    remy_yuca_008,  /* 15 APPEAR 8 */
    remy_yuca_016,  /* 16 SP APPEAR 1 */
    remy_yuca_016,  /* 17 SP APPEAR 2 */
    remy_yuca_016,  /* 18 SP APPEAR 3 */
    remy_yuca_016,  /* 19 SP APPEAR 4 */
    remy_yuca_016,  /* 20 SP APPEAR 5 */
    remy_yuca_016,  /* 21 SP APPEAR 6 */
    remy_yuca_016,  /* 22 SP APPEAR 7 */
    remy_yuca_016,  /* 23 SP APPEAR 8 */
    remy_yuca_024,  /* 24 ZANNEN 1 */
    remy_yuca_024,  /* 25 ZANNEN 2 */
    remy_yuca_024,  /* 26 ZANNEN 3 */
    remy_yuca_024,  /* 27 ZANNEN 4 */
    remy_yuca_024,  /* 28 ZANNEN 5 */
    remy_yuca_024,  /* 29 ZANNEN 6 */
    remy_yuca_024,  /* 30 ZANNEN 7 */
    remy_yuca_024,  /* 31 ZANNEN 8 */
    remy_yuca_032,  /* 32 WIN 1 */
    remy_yuca_033,  /* 33 WIN 2 */
    remy_yuca_032,  /* 34 WIN 3 */
    remy_yuca_033,  /* 35 WIN 4 */
    remy_yuca_036,  /* 36 WIN 5 */
    remy_yuca_037,  /* 37 WIN 6 */
    remy_yuca_038,  /* 38 WIN 7 */
    remy_yuca_039,  /* 39 WIN 8 */
    remy_yuca_040,  /* 40 SP WIN 1 */
    remy_yuca_041,  /* 41 SP WIN 2 */
    remy_yuca_041,  /* 42 SP WIN 3 */
    remy_yuca_041,  /* 43 SP WIN 4 */
    remy_yuca_041,  /* 44 SP WIN 5 */
    remy_yuca_041,  /* 45 SP WIN 6 */
    remy_yuca_041,  /* 46 SP WIN 7 */
    remy_yuca_041,  /* 47 SP WIN 8 */
    remy_yuca_048,  /* 48 JUDGMENT WAIT */
    remy_yuca_048,  /* 49 JUDGMENT WAIT */
    remy_yuca_048,  /* 50 JUDGMENT WAIT */
    remy_yuca_048,  /* 51 JUDGMENT WAIT */
    remy_yuca_032,  /* 52 JUDGMENT WIN */
    remy_yuca_032,  /* 53 JUDGMENT WIN */
    remy_yuca_032,  /* 54 JUDGMENT WIN */
    remy_yuca_032,  /* 55 JUDGMENT WIN */
    remy_yuca_024,  /* 56 JUDGMENT LOSE */
    remy_yuca_024,  /* 57 JUDGMENT LOSE */
    remy_yuca_024,  /* 58 JUDGMENT LOSE */
    remy_yuca_024,  /* 59 JUDGMENT LOSE */
    remy_yuca_060,  /* 60 WAIT */
    remy_yuca_061,  /* 61 AFRICA JUMP */
    remy_yuca_062,  /* 62 AFRICA LAND */
    remy_yuca_063,  /* 63 SEAN BALL HIT */
    remy_yuca_063,  /* 64 no name */
    remy_yuca_032,  /* 65 BONUS WIN 1 */
    remy_yuca_040,  /* 66 BONUS WIN 2 */
    remy_yuca_024,  /* 67 BONUS WIN 3 */
    remy_yuca_068,  /* 68 APPEAR USE */
    remy_yuca_068,  /* 69 APPEAR USE */
    remy_yuca_068,  /* 70 APPEAR USE */
    remy_yuca_068,  /* 71 APPEAR USE */
    remy_yuca_068,  /* 72 APPEAR USE */
    remy_yuca_068,  /* 73 APPEAR USE */
    remy_yuca_068,  /* 74 APPEAR USE */
    remy_yuca_068,  /* 75 APPEAR USE */
    remy_yuca_068,  /* 76 APPEAR USE */
    remy_yuca_068,  /* 77 APPEAR USE */
    remy_yuca_068,  /* 78 APPEAR USE */
    remy_yuca_068,  /* 79 APPEAR USE */
    remy_yuca_068,  /* 80 APPEAR USE */
    remy_yuca_068,  /* 81 APPEAR USE */
    remy_yuca_068,  /* 82 APPEAR USE */
    remy_yuca_068,  /* 83 APPEAR USE */
    remy_yuca_068,  /* 84 APPEAR USE */
    remy_yuca_068,  /* 85 APPEAR USE */
    remy_yuca_068,  /* 86 APPEAR USE */
    remy_yuca_068,  /* 87 APPEAR USE */
    remy_yuca_068,  /* 88 APPEAR USE */
    remy_yuca_068,  /* 89 APPEAR USE */
    remy_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 2 APPEAR JUNBI 3, 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8 */
const u16 remy_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_000[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7210),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7211),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7212),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7213),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7210),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7211),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7212),
    L2(6, 9, 0, 0, 0, 0, 0, 0x7213),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2, 5 APPEAR JUNBI 6 */
const u16 remy_yuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_001[8] = {
    L2(5, 9, 0, 0, 0, 0, 0, 0x75C0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 remy_yuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_004[8] = {
    L2(4, 9, 0, 0, 0, 0, 0, 0x74F8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 remy_yuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_003[8] = {
    L2(10, 9, 554, 0, 0, 0, 0, 0x74FF),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 10 APPEAR 3, 14 APPEAR 7, 15 APPEAR 8 */
const u16 remy_yuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_008[172] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7210),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7211),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7212),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7213),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7214),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7215),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7216),
    CMD(CM_PA_X, 0, 256, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7217),
    L2(5, 0, 561, 0, 0, 0, 0, 0x7218),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7219),
    L2(3, 0, 0, 0, 0, 0, 0, 0x721A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x721B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x721C),
    L2(7, 0, 0, 0, 0, 0, 0, 0x721D),
    L2(9, 0, 0, 0, 0, 0, 0, 0x721E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x721F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7225),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7226),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7227),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7228),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7229),
    L2(28, 0, 0, 0, 0, 0, 0, 0x722A),
    CMD(CM_PA_X, 0, -512, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7220),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7221),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7222),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7223),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7224),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7203),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7204),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7205),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7206),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7207),
    L2(250, 255, 0, 0, 0, 0, 0, 0x7207),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 remy_yuca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_012[276] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 553, 0, 0, 0, 0, 0x73A6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DE, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 APPEAR 2, 13 APPEAR 6 */
const u16 remy_yuca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_009[116] = {
    L4(24, 0, 0, 0, 0, 0, 0, 0x75C0, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 555, 0, 0, 0, 0, 0x75C1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x75C2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x75C3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x75C4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x75C5, 0, 1, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x75C6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 7), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x75C7, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x75C8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x75C9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x75CA, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x75CA, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 remy_yuca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_011[228] = {
    L4(10, 0, 554, 0, 0, 0, 0, 0x74FF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73A9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73AF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74D9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74DE, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 remy_yuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_016[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x7201),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 remy_yuca_024_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 remy_yuca_024[40] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x7479),
    L2(5, 0, 0, 0, 0, 0, 0, 0x747A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x747B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x747C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x747D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x747E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x747F),
    L2(255, 255, 0, 0, 0, 0, 0, 0x747F),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 34 WIN 3, 52 JUDGMENT WIN, 53 JUDGMENT WIN ... */
const u16 remy_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_032[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CD),
    L2(12, 0, 0, 0, 0, 0, 0, 0x75CE),
    L2(4, 0, 564, 0, 0, 0, 0, 0x75CF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x75CF),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 WIN 2, 35 WIN 4 */
const u16 remy_yuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_033[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75CD),
    L2(12, 0, 0, 0, 0, 0, 0, 0x75CE),
    L2(4, 0, 563, 0, 0, 0, 0, 0x75CF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x75CF),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 remy_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_036[112] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x7650),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7651),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7652),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7653),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7654),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7655),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7656),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7657),
    L2(2, 0, 559, 0, 0, 0, 0, 0x7658),
    L2(16, 0, 0, 0, 0, 0, 0, 0x7659),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7660),
    L2(21, 0, 0, 0, 0, 0, 0, 0x7661),
    L2(7, 0, 562, 0, 0, 0, 0, 0x7662),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7663),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7664),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7665),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7666),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7668),
    L2(3, 0, 0, 0, 0, 0, 0, 0x766B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x766B),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 remy_yuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_037[148] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75DE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75DF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75E0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75E7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75E8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75E9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75ED),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75FA),
    L2(18, 0, 0, 0, 0, 0, 0, 0x75FB),
    L2(30, 0, 559, 0, 0, 0, 0, 0x75FE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x75FB),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 remy_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_038[196] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75DE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75DF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75E0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x75E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75E7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75E8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75E9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x75EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75ED),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75EF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x75FA),
    L2(32, 0, 0, 0, 0, 0, 0, 0x75FB),
    L2(6, 0, 558, 0, 0, 0, 0, 0x75FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FE),
    L2(24, 0, 0, 0, 0, 0, 0, 0x75FB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75FB),
    L2(250, 255, 0, 0, 0, 0, 0, 0x75FB),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 remy_yuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_039[124] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x7650),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7651),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7652),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7653),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7654),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7655),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7656),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7657),
    L2(2, 0, 559, 0, 0, 0, 0, 0x7658),
    L2(16, 0, 0, 0, 0, 0, 0, 0x7659),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x765F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7660),
    L2(21, 0, 0, 0, 0, 0, 0, 0x7661),
    L2(7, 0, 563, 0, 0, 0, 0, 0x7662),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7663),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7664),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7665),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7666),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7667),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7668),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7669),
    L2(3, 0, 0, 0, 0, 0, 0, 0x766A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x766B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x766B),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 66 BONUS WIN 2 */
const u16 remy_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_040[88] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D1),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D2),
    CMD(CM_PA_X, 0, 768, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x75D7),
    L2(10, 0, 0, 0, 0, 0, 0, 0x75D8),
    L2(6, 0, 556, 0, 0, 0, 0, 0x75D9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75DA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75D9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x75DA),
    L2(18, 0, 0, 0, 0, 0, 0, 0x75D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75DA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75DA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x75D9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x75D9),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4, 44 SP WIN 5 ... */
const u16 remy_yuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_041[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7201),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 remy_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_048[60] = {
    L2(18, 0, 0, 0, 0, 0, 0, 0x7208),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7209),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x720F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7206),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7207),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7204),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7205),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7206),
    L2(6, 255, 0, 0, 0, 0, 0, 0x7207),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 remy_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_060[116] = {
    L4(18, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7209, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720B, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720E, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x720F, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 remy_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_061[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7231),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7232),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7250),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7251),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7252),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7253),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7254),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7255),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7257),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7258),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7259),
    L2(4, 0, 0, 0, 0, 0, 0, 0x725A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x725B),
    L2(250, 0, 0, 0, 0, 0, 3, 0x725C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 remy_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_062[52] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x7502),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7503),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7504),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7505),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7506),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7507),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7237),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7238),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7239),
    L2(4, 0, 0, 0, 0, 0, 0, 0x723A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x723B),
    L2(4, 255, 0, 0, 0, 0, 0, 0x723B),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 remy_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_063[44] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7201),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7202),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7203),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7204),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7205),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7206),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7207),
    L2(250, 255, 0, 0, 0, 0, 0, 0x7207),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 remy_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x72B4),
    CMD(CM_ROA, 0, 0, 0),
};

/*
 * NO12_YUCA.C  Twelve's animation scripts
 *
 * The animation scripts Twelve's moves run, one table per kind of script (yuca),
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

extern const u16 no12_yuca_000[], no12_yuca_008[], no12_yuca_016[], no12_yuca_024[], no12_yuca_032[], no12_yuca_033[], no12_yuca_034[], no12_yuca_036[], no12_yuca_037[], no12_yuca_038[], no12_yuca_040[], no12_yuca_048[], no12_yuca_052[], no12_yuca_060[], no12_yuca_061[], no12_yuca_062[], no12_yuca_063[], no12_yuca_068[];
extern const u16 no12_yuca_000_head[];
extern const u16 no12_yuca_008_head[];
extern const u16 no12_yuca_016_head[];
extern const u16 no12_yuca_024_head[];
extern const u16 no12_yuca_032_head[];
extern const u16 no12_yuca_033_head[];
extern const u16 no12_yuca_034_head[];
extern const u16 no12_yuca_036_head[];
extern const u16 no12_yuca_037_head[];
extern const u16 no12_yuca_038_head[];
extern const u16 no12_yuca_040_head[];
extern const u16 no12_yuca_048_head[];
extern const u16 no12_yuca_052_head[];
extern const u16 no12_yuca_060_head[];
extern const u16 no12_yuca_061_head[];
extern const u16 no12_yuca_062_head[];
extern const u16 no12_yuca_063_head[];
extern const u16 no12_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const no12_yuca[92] = {
    no12_yuca_000,  /* 0 APPEAR JUNBI 1 */
    no12_yuca_000,  /* 1 APPEAR JUNBI 2 */
    no12_yuca_000,  /* 2 APPEAR JUNBI 3 */
    no12_yuca_000,  /* 3 APPEAR JUNBI 4 */
    no12_yuca_000,  /* 4 APPEAR JUNBI 5 */
    no12_yuca_000,  /* 5 APPEAR JUNBI 6 */
    no12_yuca_000,  /* 6 APPEAR JUNBI 7 */
    no12_yuca_000,  /* 7 APPEAR JUNBI 8 */
    no12_yuca_008,  /* 8 APPEAR 1 */
    no12_yuca_008,  /* 9 APPEAR 2 */
    no12_yuca_008,  /* 10 APPEAR 3 */
    no12_yuca_008,  /* 11 APPEAR 4 */
    no12_yuca_008,  /* 12 APPEAR 5 */
    no12_yuca_008,  /* 13 APPEAR 6 */
    no12_yuca_008,  /* 14 APPEAR 7 */
    no12_yuca_008,  /* 15 APPEAR 8 */
    no12_yuca_016,  /* 16 SP APPEAR 1 */
    no12_yuca_016,  /* 17 SP APPEAR 2 */
    no12_yuca_016,  /* 18 SP APPEAR 3 */
    no12_yuca_016,  /* 19 SP APPEAR 4 */
    no12_yuca_016,  /* 20 SP APPEAR 5 */
    no12_yuca_016,  /* 21 SP APPEAR 6 */
    no12_yuca_016,  /* 22 SP APPEAR 7 */
    no12_yuca_016,  /* 23 SP APPEAR 8 */
    no12_yuca_024,  /* 24 ZANNEN 1 */
    no12_yuca_024,  /* 25 ZANNEN 2 */
    no12_yuca_024,  /* 26 ZANNEN 3 */
    no12_yuca_024,  /* 27 ZANNEN 4 */
    no12_yuca_024,  /* 28 ZANNEN 5 */
    no12_yuca_024,  /* 29 ZANNEN 6 */
    no12_yuca_024,  /* 30 ZANNEN 7 */
    no12_yuca_024,  /* 31 ZANNEN 8 */
    no12_yuca_032,  /* 32 WIN 1 */
    no12_yuca_033,  /* 33 WIN 2 */
    no12_yuca_034,  /* 34 WIN 3 */
    no12_yuca_032,  /* 35 WIN 4 */
    no12_yuca_036,  /* 36 WIN 5 */
    no12_yuca_037,  /* 37 WIN 6 */
    no12_yuca_038,  /* 38 WIN 7 */
    no12_yuca_038,  /* 39 WIN 8 */
    no12_yuca_040,  /* 40 SP WIN 1 */
    no12_yuca_040,  /* 41 SP WIN 2 */
    no12_yuca_040,  /* 42 SP WIN 3 */
    no12_yuca_040,  /* 43 SP WIN 4 */
    no12_yuca_040,  /* 44 SP WIN 5 */
    no12_yuca_040,  /* 45 SP WIN 6 */
    no12_yuca_040,  /* 46 SP WIN 7 */
    no12_yuca_040,  /* 47 SP WIN 8 */
    no12_yuca_048,  /* 48 JUDGMENT WAIT */
    no12_yuca_048,  /* 49 JUDGMENT WAIT */
    no12_yuca_048,  /* 50 JUDGMENT WAIT */
    no12_yuca_048,  /* 51 JUDGMENT WAIT */
    no12_yuca_052,  /* 52 JUDGMENT WIN */
    no12_yuca_052,  /* 53 JUDGMENT WIN */
    no12_yuca_052,  /* 54 JUDGMENT WIN */
    no12_yuca_052,  /* 55 JUDGMENT WIN */
    no12_yuca_024,  /* 56 JUDGMENT LOSE */
    no12_yuca_024,  /* 57 JUDGMENT LOSE */
    no12_yuca_024,  /* 58 JUDGMENT LOSE */
    no12_yuca_024,  /* 59 JUDGMENT LOSE */
    no12_yuca_060,  /* 60 WAIT */
    no12_yuca_061,  /* 61 AFRICA JUMP */
    no12_yuca_062,  /* 62 AFRICA LAND */
    no12_yuca_063,  /* 63 SEAN BALL HIT */
    no12_yuca_063,  /* 64 no name */
    no12_yuca_052,  /* 65 BONUS WIN 1 */
    no12_yuca_052,  /* 66 BONUS WIN 2 */
    no12_yuca_024,  /* 67 BONUS WIN 3 */
    no12_yuca_068,  /* 68 APPEAR USE */
    no12_yuca_068,  /* 69 APPEAR USE */
    no12_yuca_068,  /* 70 APPEAR USE */
    no12_yuca_068,  /* 71 APPEAR USE */
    no12_yuca_068,  /* 72 APPEAR USE */
    no12_yuca_068,  /* 73 APPEAR USE */
    no12_yuca_068,  /* 74 APPEAR USE */
    no12_yuca_068,  /* 75 APPEAR USE */
    no12_yuca_068,  /* 76 APPEAR USE */
    no12_yuca_068,  /* 77 APPEAR USE */
    no12_yuca_068,  /* 78 APPEAR USE */
    no12_yuca_068,  /* 79 APPEAR USE */
    no12_yuca_068,  /* 80 APPEAR USE */
    no12_yuca_068,  /* 81 APPEAR USE */
    no12_yuca_068,  /* 82 APPEAR USE */
    no12_yuca_068,  /* 83 APPEAR USE */
    no12_yuca_068,  /* 84 APPEAR USE */
    no12_yuca_068,  /* 85 APPEAR USE */
    no12_yuca_068,  /* 86 APPEAR USE */
    no12_yuca_068,  /* 87 APPEAR USE */
    no12_yuca_068,  /* 88 APPEAR USE */
    no12_yuca_068,  /* 89 APPEAR USE */
    no12_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 no12_yuca_000_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 no12_yuca_000[16] = {
    CMD(CM_KAGE, 6, 0, 13),
    L2(5, 9, 0, 0, 0, 0, 0, 0x6F80),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 no12_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_008[764] = {
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x6F80, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F81, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F82, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F83, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F84, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F85, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F84, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F83, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 13), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F82, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_KAGE, 6, 0, 10), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x6F80, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_PA_Y, 0, 0, 12288), 0, 0, 0, 0,
    CMD(CM_KAGE, 6, 0, 10), 0, 0, 0, 0,
    L4(10, 1, 0, 0, 0, 0, 0, 0x6F80, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_PA_Y, 0, 0, -12288), 0, 0, 0, 0,
    CMD(CM_KAGE, 6, 0, 15), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F86, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 17), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F87, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F88, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 18), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F89, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F8A, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F8B, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F8C, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F8D, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 7, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F8E, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 976, 0, 0, 0, 0, 0x6F8F, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F90, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 7, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F91, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 8, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F92, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 9, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F93, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 10, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F94, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 11, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F95, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 11, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F96, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 12, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F97, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 12, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F98, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 11, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F99, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 10, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F9A, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 9, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F9B, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 8, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F9C, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 7, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F9D, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 19), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F9E, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA2, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 20), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA3, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA4, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA5, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA6, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA7, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA8, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FA9, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FAA, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FAB, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FAC, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FAD, 0, 7, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x6FAE, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FAF, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C29, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2A, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2B, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 no12_yuca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 no12_yuca_016[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 no12_yuca_024_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_yuca_024[228] = {
    L4(10, 0, 0, 0, 0, 0, 0, 0x6DF5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 961, 0, 0, 0, 0, 0x6DF6, 0, 1, 0, 0, 0, 0, 0),
    L4(14, 1, 0, 0, 0, 0, 0, 0x6DF7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFB, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFC, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFD, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFE, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFF, 0, 0, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x6E00, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E01, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E02, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E08, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 288, 0, 0, 0, 0, 0x6E09, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6DD5, 0, 0, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x6DD6, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DD7, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 35 WIN 4 */
const u16 no12_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_032[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5C),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6E5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E1D),
    L2(3, 0, 975, 0, 0, 0, 0, 0x6E1E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6E1E),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 no12_yuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_033[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5C),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6E5D),
    L2(3, 0, 975, 0, 0, 0, 0, 0x6E1F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E22),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6E22),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 no12_yuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_034[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E5C),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6E5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E93),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E94),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6E95),
    L2(3, 0, 975, 0, 0, 0, 0, 0x6E9D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6E9D),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 no12_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_036[304] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E8E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E91),
    L2(8, 0, 0, 0, 0, 0, 0, 0x6E92),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E91),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E90),
    L2(8, 0, 0, 0, 0, 0, 0, 0x6E8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E91),
    L2(8, 0, 0, 0, 0, 0, 0, 0x6E92),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C22),
    L2(5, 1, 0, 0, 0, 0, 0, 0x6C5E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C5F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C60),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F63),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F60),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F65),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F64),
    L2(3, 2, 0, 0, 0, 0, 0, 0x6F64),
    CMD(CM_KAGE, 6, 0, 17),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F87),
    CMD(CM_KAGE, 6, 0, 19),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F88),
    CMD(CM_KAGE, 6, 0, 18),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F8B),
    CMD(CM_KAGE, 6, 0, 19),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F8C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F8D),
    CMD(CM_KAGE, 7, 0, 19),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F8E),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_KAGE, 6, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F8F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F90),
    CMD(CM_KAGE, 7, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F91),
    CMD(CM_KAGE, 8, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F92),
    CMD(CM_KAGE, 9, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F93),
    CMD(CM_KAGE, 10, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F94),
    CMD(CM_KAGE, 11, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F95),
    CMD(CM_KAGE, 11, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F96),
    CMD(CM_KAGE, 12, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F97),
    CMD(CM_KAGE, 12, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F98),
    CMD(CM_KAGE, 11, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F99),
    CMD(CM_KAGE, 10, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F9A),
    CMD(CM_KAGE, 9, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F9B),
    CMD(CM_KAGE, 8, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F9C),
    CMD(CM_KAGE, 7, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F9D),
    CMD(CM_KAGE, 6, 0, 19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6F9E),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_KAGE, 6, 0, 19),
    L2(2, 0, 972, 0, 0, 0, 0, 0x6F9F),
    L2(24, 9, 0, 0, 0, 0, 0, 0x6FA0),
    L2(24, 0, 0, 0, 0, 0, 0, 0x6FA1),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 no12_yuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_037[104] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6CB6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6CB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6CB8),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6CB2),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB3),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB4),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB5),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB6),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x6CB8),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB2),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB3),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB4),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB5),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB6),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x6CB8),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CB9),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CBA),
    L2(7, 0, 0, 0, 0, 0, 0, 0x6CBC),
    L2(2, 0, 965, 0, 0, 0, 0, 0x6CBD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6CBE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6CBD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6CBE),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7, 39 WIN 8 */
const u16 no12_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_038[80] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E8E),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6E8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6E91),
    L2(12, 0, 0, 0, 0, 0, 0, 0x6E92),
    L2(2, 0, 281, 0, 0, 0, 0, 0x6C20),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C21),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C22),
    L2(4, 1, 0, 0, 0, 0, 0, 0x6C44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C47),
    L2(5, 0, 974, 0, 0, 0, 0, 0x6F50),
    L2(4, 2, 0, 0, 0, 0, 0, 0x6F51),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F52),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F53),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6F54),
    L2(4, 255, 0, 0, 0, 0, 0, 0x6F55),
    CMD(CM_IXBW, 0, 0, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 no12_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_040[8] = {
    L2(4, 255, 0, 0, 0, 0, 0, 0x7024),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 no12_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_048[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C0A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C0D),
    L2(4, 255, 0, 0, 0, 0, 0, 0x6C0E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN, 55 JUDGMENT WIN ... */
const u16 no12_yuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_052[56] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE7),
    L2(3, 0, 965, 0, 0, 0, 0, 0x6EE8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EE9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6EEA),
    L2(3, 255, 0, 0, 0, 0, 0, 0x6EEB),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 no12_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_060[116] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C04, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C05, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C06, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C07, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C08, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C09, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x6C0E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 no12_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_061[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C47),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C48),
    L2(5, 0, 0, 0, 0, 0, 0, 0x6C49),
    L2(6, 0, 0, 0, 0, 0, 0, 0x6C4A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x6C48),
    L2(5, 0, 0, 0, 0, 0, 0, 0x6C47),
    L2(5, 0, 0, 0, 0, 0, 0, 0x6C4B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C4C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 no12_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_062[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C21),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C22),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C3C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C3D),
    L2(3, 255, 0, 0, 0, 0, 0, 0x6C3D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 no12_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_063[24] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x6DC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C2E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C2E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 no12_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6CB4),
    CMD(CM_ROA, 0, 0, 0),
};

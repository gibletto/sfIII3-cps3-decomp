/*
 * CHUN_YUCA.C  Chun-Li's animation scripts
 *
 * The animation scripts Chun-Li's moves run, one table per kind of script (yuca),
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

extern const u16 chun_yuca_000[], chun_yuca_008[], chun_yuca_009[], chun_yuca_014[], chun_yuca_016[], chun_yuca_024[], chun_yuca_032[], chun_yuca_036[], chun_yuca_037[], chun_yuca_039[], chun_yuca_040[], chun_yuca_041[], chun_yuca_048[], chun_yuca_060[], chun_yuca_061[], chun_yuca_062[], chun_yuca_063[], chun_yuca_068[];
extern const u16 chun_yuca_000_head[];
extern const u16 chun_yuca_008_head[];
extern const u16 chun_yuca_009_head[];
extern const u16 chun_yuca_014_head[];
extern const u16 chun_yuca_016_head[];
extern const u16 chun_yuca_024_head[];
extern const u16 chun_yuca_032_head[];
extern const u16 chun_yuca_036_head[];
extern const u16 chun_yuca_037_head[];
extern const u16 chun_yuca_039_head[];
extern const u16 chun_yuca_040_head[];
extern const u16 chun_yuca_041_head[];
extern const u16 chun_yuca_048_head[];
extern const u16 chun_yuca_060_head[];
extern const u16 chun_yuca_061_head[];
extern const u16 chun_yuca_062_head[];
extern const u16 chun_yuca_063_head[];
extern const u16 chun_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const chun_yuca[92] = {
    chun_yuca_000,  /* 0 APPEAR JUNBI 1 */
    chun_yuca_000,  /* 1 APPEAR JUNBI 2 */
    chun_yuca_000,  /* 2 APPEAR JUNBI 3 */
    chun_yuca_000,  /* 3 APPEAR JUNBI 4 */
    chun_yuca_000,  /* 4 APPEAR JUNBI 5 */
    chun_yuca_000,  /* 5 APPEAR JUNBI 6 */
    chun_yuca_000,  /* 6 APPEAR JUNBI 7 */
    chun_yuca_000,  /* 7 APPEAR JUNBI 8 */
    chun_yuca_008,  /* 8 APPEAR 1 */
    chun_yuca_009,  /* 9 APPEAR 2 */
    chun_yuca_008,  /* 10 APPEAR 3 */
    chun_yuca_009,  /* 11 APPEAR 4 */
    chun_yuca_008,  /* 12 APPEAR 5 */
    chun_yuca_009,  /* 13 APPEAR 6 */
    chun_yuca_014,  /* 14 APPEAR 7 */
    chun_yuca_014,  /* 15 APPEAR 8 */
    chun_yuca_016,  /* 16 SP APPEAR 1 */
    chun_yuca_016,  /* 17 SP APPEAR 2 */
    chun_yuca_016,  /* 18 SP APPEAR 3 */
    chun_yuca_016,  /* 19 SP APPEAR 4 */
    chun_yuca_016,  /* 20 SP APPEAR 5 */
    chun_yuca_016,  /* 21 SP APPEAR 6 */
    chun_yuca_016,  /* 22 SP APPEAR 7 */
    chun_yuca_016,  /* 23 SP APPEAR 8 */
    chun_yuca_024,  /* 24 ZANNEN 1 */
    chun_yuca_024,  /* 25 ZANNEN 2 */
    chun_yuca_024,  /* 26 ZANNEN 3 */
    chun_yuca_024,  /* 27 ZANNEN 4 */
    chun_yuca_024,  /* 28 ZANNEN 5 */
    chun_yuca_024,  /* 29 ZANNEN 6 */
    chun_yuca_024,  /* 30 ZANNEN 7 */
    chun_yuca_024,  /* 31 ZANNEN 8 */
    chun_yuca_032,  /* 32 WIN 1 */
    chun_yuca_032,  /* 33 WIN 2 */
    chun_yuca_032,  /* 34 WIN 3 */
    chun_yuca_032,  /* 35 WIN 4 */
    chun_yuca_036,  /* 36 WIN 5 */
    chun_yuca_037,  /* 37 WIN 6 */
    chun_yuca_037,  /* 38 WIN 7 */
    chun_yuca_039,  /* 39 WIN 8 */
    chun_yuca_040,  /* 40 SP WIN 1 */
    chun_yuca_041,  /* 41 SP WIN 2 */
    chun_yuca_041,  /* 42 SP WIN 3 */
    chun_yuca_041,  /* 43 SP WIN 4 */
    chun_yuca_041,  /* 44 SP WIN 5 */
    chun_yuca_041,  /* 45 SP WIN 6 */
    chun_yuca_041,  /* 46 SP WIN 7 */
    chun_yuca_041,  /* 47 SP WIN 8 */
    chun_yuca_048,  /* 48 JUDGMENT WAIT */
    chun_yuca_048,  /* 49 JUDGMENT WAIT */
    chun_yuca_048,  /* 50 JUDGMENT WAIT */
    chun_yuca_048,  /* 51 JUDGMENT WAIT */
    chun_yuca_036,  /* 52 JUDGMENT WIN */
    chun_yuca_036,  /* 53 JUDGMENT WIN */
    chun_yuca_036,  /* 54 JUDGMENT WIN */
    chun_yuca_036,  /* 55 JUDGMENT WIN */
    chun_yuca_024,  /* 56 JUDGMENT LOSE */
    chun_yuca_024,  /* 57 JUDGMENT LOSE */
    chun_yuca_024,  /* 58 JUDGMENT LOSE */
    chun_yuca_024,  /* 59 JUDGMENT LOSE */
    chun_yuca_060,  /* 60 WAIT */
    chun_yuca_061,  /* 61 AFRICA JUMP */
    chun_yuca_062,  /* 62 AFRICA LAND */
    chun_yuca_063,  /* 63 SEAN BALL HIT */
    chun_yuca_063,  /* 64 no name */
    chun_yuca_037,  /* 65 BONUS WIN 1 */
    chun_yuca_036,  /* 66 BONUS WIN 2 */
    chun_yuca_024,  /* 67 BONUS WIN 3 */
    chun_yuca_068,  /* 68 APPEAR USE */
    chun_yuca_068,  /* 69 APPEAR USE */
    chun_yuca_068,  /* 70 APPEAR USE */
    chun_yuca_068,  /* 71 APPEAR USE */
    chun_yuca_068,  /* 72 APPEAR USE */
    chun_yuca_068,  /* 73 APPEAR USE */
    chun_yuca_068,  /* 74 APPEAR USE */
    chun_yuca_068,  /* 75 APPEAR USE */
    chun_yuca_068,  /* 76 APPEAR USE */
    chun_yuca_068,  /* 77 APPEAR USE */
    chun_yuca_068,  /* 78 APPEAR USE */
    chun_yuca_068,  /* 79 APPEAR USE */
    chun_yuca_068,  /* 80 APPEAR USE */
    chun_yuca_068,  /* 81 APPEAR USE */
    chun_yuca_068,  /* 82 APPEAR USE */
    chun_yuca_068,  /* 83 APPEAR USE */
    chun_yuca_068,  /* 84 APPEAR USE */
    chun_yuca_068,  /* 85 APPEAR USE */
    chun_yuca_068,  /* 86 APPEAR USE */
    chun_yuca_068,  /* 87 APPEAR USE */
    chun_yuca_068,  /* 88 APPEAR USE */
    chun_yuca_068,  /* 89 APPEAR USE */
    chun_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 chun_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_000[8] = {
    L2(7, 9, 0, 0, 0, 0, 0, 0x5B5A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 10 APPEAR 3, 12 APPEAR 5 */
const u16 chun_yuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_008[168] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B53),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B54),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B55),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 431, 0, 0, 0, 0, 0x5B56),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B57),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B58),
    CMD(CM_PA_X, 0, 3328, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B59),
    CMD(CM_PA_X, 0, 768, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5A),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5B),
    CMD(CM_PA_X, 0, 3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5F),
    CMD(CM_PA_X, 0, 3584, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B60),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B61),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B62),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B63),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B64),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B65),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B66),
    CMD(CM_PA_X, 0, 4352, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B67),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B68),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B69),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B6A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D59),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D5A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5D5A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 APPEAR 2, 11 APPEAR 4, 13 APPEAR 6 */
const u16 chun_yuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_009[168] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B53),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B54),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B55),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B56),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B57),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B58),
    CMD(CM_PA_X, 0, 3328, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B59),
    CMD(CM_PA_X, 0, 768, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5A),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5B),
    CMD(CM_PA_X, 0, 3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5F),
    CMD(CM_PA_X, 0, 3584, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B60),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B61),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B62),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B63),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B64),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 430, 0, 0, 0, 0, 0x5B65),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B66),
    CMD(CM_PA_X, 0, 4352, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B67),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B68),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B69),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B6A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D59),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D5A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5D5A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 APPEAR 7, 15 APPEAR 8 */
const u16 chun_yuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_014[168] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B53),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B54),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B55),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 438, 0, 0, 0, 0, 0x5B56),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B57),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B58),
    CMD(CM_PA_X, 0, 3328, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B59),
    CMD(CM_PA_X, 0, 768, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5A),
    CMD(CM_PA_X, 0, 2816, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5B),
    CMD(CM_PA_X, 0, 3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B5F),
    CMD(CM_PA_X, 0, 3584, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B60),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B61),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B62),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B63),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B64),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B65),
    CMD(CM_PA_X, 0, 2304, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5B66),
    CMD(CM_PA_X, 0, 4352, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B67),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B68),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B69),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B6A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D59),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5D5A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5D5A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 chun_yuca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 chun_yuca_016[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x5D5A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 chun_yuca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_024[148] = {
    L6(8, 0, 417, 0, 0, 0, 0, 0x5C10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C11, 0, 1, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C12, 0, 1, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x5C13, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C14, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x5C18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5C18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 */
const u16 chun_yuca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_032[188] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A10, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 439, 0, 0, 0, 0, 0x5F22, 0, 0, 0, 0, 0, 32, 109),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F23, 0, 0, 0, 0, 0, 32, 110),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F24, 0, 0, 0, 0, 0, 32, 111),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F25, 0, 0, 0, 0, 0, 32, 112),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F26, 0, 0, 0, 0, 0, 32, 113),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F27, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F28, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F29, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F42, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F43, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F44, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F45, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F46, 0, 0, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x5F47, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x5F47, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN ... */
const u16 chun_yuca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_036[188] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A10, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F22, 0, 0, 0, 0, 0, 32, 109),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F23, 0, 0, 0, 0, 0, 32, 110),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F24, 0, 0, 0, 0, 0, 32, 111),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F25, 0, 0, 0, 0, 0, 32, 112),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F26, 0, 0, 0, 0, 0, 32, 113),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F27, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F28, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F29, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 433, 0, 0, 0, 0, 0x5F2D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F2F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F42, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F43, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F44, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F45, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F46, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F47, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x5F47, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 WIN 6, 38 WIN 7, 65 BONUS WIN 1 */
const u16 chun_yuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_037[160] = {
    L2(3, 0, 440, 0, 0, 0, 0, 0x5A66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6E),
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A75),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A76),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A77),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A78),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A79),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7B),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7C),
    L2(3, 0, 437, 0, 0, 0, 0, 0x5A7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5A8C),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 chun_yuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_039[148] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x5CF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CF3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CF4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CF5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CF6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CF7),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5CF8),
    CMD(CM_PA_X, 0, -256, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5CF9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5CFA),
    CMD(CM_PA_X, 0, 256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5CFB),
    CMD(CM_PA_X, 0, 512, 0),
    L2(2, 0, 268, 0, 0, 0, 0, 0x5CFC),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5CFD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5CFE),
    L2(12, 0, 0, 0, 0, 0, 0, 0x5CFF),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D17),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5D18),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5D19),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5D1A),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5D1B),
    L2(1, 0, 269, 0, 0, 0, 0, 0x5D1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5D1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5D1E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D1F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D32),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D33),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D34),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5D35),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5D35),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 chun_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_040[176] = {
    L2(3, 0, 440, 0, 0, 0, 0, 0x5A66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6E),
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A75),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A76),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A77),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A78),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A79),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7B),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7C),
    L2(3, 0, 437, 0, 0, 0, 0, 0x5A7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8B),
    L2(20, 0, 0, 0, 0, 0, 0, 0x5A8C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A8F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5A8F),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4, 44 SP WIN 5 ... */
const u16 chun_yuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_041[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x5CF2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 chun_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_048[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A11),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A12),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A13),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A14),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A15),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A14),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A13),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A12),
    L2(4, 255, 0, 0, 0, 0, 0, 0x5A11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 chun_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_060[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A10, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A15, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 chun_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_061[76] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A29),
    L2(1, 0, 281, 0, 0, 0, 0, 0x5A40),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5A41),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5A40),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5A41),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A43),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A47),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A48),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A49),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A4A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A6B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 chun_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_062[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x5A2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A4B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5A2F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x5A2F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 chun_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_063[24] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5B73),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 chun_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5AB4),
    CMD(CM_ROA, 0, 0, 0),
};

/*
 * NECRO_YUCA.C  Necro's animation scripts
 *
 * The animation scripts Necro's moves run, one table per kind of script (yuca),
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

extern const u16 necro_yuca_000[], necro_yuca_004[], necro_yuca_008[], necro_yuca_012[], necro_yuca_016[], necro_yuca_024[], necro_yuca_032[], necro_yuca_036[], necro_yuca_040[], necro_yuca_041[], necro_yuca_042[], necro_yuca_048[], necro_yuca_060[], necro_yuca_061[], necro_yuca_062[], necro_yuca_063[], necro_yuca_068[];
extern const u16 necro_yuca_000_head[];
extern const u16 necro_yuca_004_head[];
extern const u16 necro_yuca_008_head[];
extern const u16 necro_yuca_012_head[];
extern const u16 necro_yuca_016_head[];
extern const u16 necro_yuca_024_head[];
extern const u16 necro_yuca_032_head[];
extern const u16 necro_yuca_036_head[];
extern const u16 necro_yuca_040_head[];
extern const u16 necro_yuca_041_head[];
extern const u16 necro_yuca_042_head[];
extern const u16 necro_yuca_048_head[];
extern const u16 necro_yuca_060_head[];
extern const u16 necro_yuca_061_head[];
extern const u16 necro_yuca_062_head[];
extern const u16 necro_yuca_063_head[];
extern const u16 necro_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const necro_yuca[92] = {
    necro_yuca_000,  /* 0 APPEAR JUNBI 1 */
    necro_yuca_000,  /* 1 APPEAR JUNBI 2 */
    necro_yuca_000,  /* 2 APPEAR JUNBI 3 */
    necro_yuca_000,  /* 3 APPEAR JUNBI 4 */
    necro_yuca_004,  /* 4 APPEAR JUNBI 5 */
    necro_yuca_004,  /* 5 APPEAR JUNBI 6 */
    necro_yuca_004,  /* 6 APPEAR JUNBI 7 */
    necro_yuca_004,  /* 7 APPEAR JUNBI 8 */
    necro_yuca_008,  /* 8 APPEAR 1 */
    necro_yuca_008,  /* 9 APPEAR 2 */
    necro_yuca_008,  /* 10 APPEAR 3 */
    necro_yuca_008,  /* 11 APPEAR 4 */
    necro_yuca_012,  /* 12 APPEAR 5 */
    necro_yuca_012,  /* 13 APPEAR 6 */
    necro_yuca_012,  /* 14 APPEAR 7 */
    necro_yuca_012,  /* 15 APPEAR 8 */
    necro_yuca_016,  /* 16 SP APPEAR 1 */
    necro_yuca_016,  /* 17 SP APPEAR 2 */
    necro_yuca_016,  /* 18 SP APPEAR 3 */
    necro_yuca_016,  /* 19 SP APPEAR 4 */
    necro_yuca_016,  /* 20 SP APPEAR 5 */
    necro_yuca_016,  /* 21 SP APPEAR 6 */
    necro_yuca_016,  /* 22 SP APPEAR 7 */
    necro_yuca_016,  /* 23 SP APPEAR 8 */
    necro_yuca_024,  /* 24 ZANNEN 1 */
    necro_yuca_024,  /* 25 ZANNEN 2 */
    necro_yuca_024,  /* 26 ZANNEN 3 */
    necro_yuca_024,  /* 27 ZANNEN 4 */
    necro_yuca_024,  /* 28 ZANNEN 5 */
    necro_yuca_024,  /* 29 ZANNEN 6 */
    necro_yuca_024,  /* 30 ZANNEN 7 */
    necro_yuca_024,  /* 31 ZANNEN 8 */
    necro_yuca_032,  /* 32 WIN 1 */
    necro_yuca_032,  /* 33 WIN 2 */
    necro_yuca_032,  /* 34 WIN 3 */
    necro_yuca_032,  /* 35 WIN 4 */
    necro_yuca_036,  /* 36 WIN 5 */
    necro_yuca_036,  /* 37 WIN 6 */
    necro_yuca_036,  /* 38 WIN 7 */
    necro_yuca_036,  /* 39 WIN 8 */
    necro_yuca_040,  /* 40 SP WIN 1 */
    necro_yuca_041,  /* 41 SP WIN 2 */
    necro_yuca_042,  /* 42 SP WIN 3 */
    necro_yuca_042,  /* 43 SP WIN 4 */
    necro_yuca_042,  /* 44 SP WIN 5 */
    necro_yuca_042,  /* 45 SP WIN 6 */
    necro_yuca_042,  /* 46 SP WIN 7 */
    necro_yuca_042,  /* 47 SP WIN 8 */
    necro_yuca_048,  /* 48 JUDGMENT WAIT */
    necro_yuca_048,  /* 49 JUDGMENT WAIT */
    necro_yuca_048,  /* 50 JUDGMENT WAIT */
    necro_yuca_048,  /* 51 JUDGMENT WAIT */
    necro_yuca_036,  /* 52 JUDGMENT WIN */
    necro_yuca_036,  /* 53 JUDGMENT WIN */
    necro_yuca_036,  /* 54 JUDGMENT WIN */
    necro_yuca_036,  /* 55 JUDGMENT WIN */
    necro_yuca_024,  /* 56 JUDGMENT LOSE */
    necro_yuca_024,  /* 57 JUDGMENT LOSE */
    necro_yuca_024,  /* 58 JUDGMENT LOSE */
    necro_yuca_024,  /* 59 JUDGMENT LOSE */
    necro_yuca_060,  /* 60 WAIT */
    necro_yuca_061,  /* 61 AFRICA JUMP */
    necro_yuca_062,  /* 62 AFRICA LAND */
    necro_yuca_063,  /* 63 SEAN BALL HIT */
    necro_yuca_063,  /* 64 no name */
    necro_yuca_032,  /* 65 BONUS WIN 1 */
    necro_yuca_036,  /* 66 BONUS WIN 2 */
    necro_yuca_024,  /* 67 BONUS WIN 3 */
    necro_yuca_068,  /* 68 APPEAR USE */
    necro_yuca_068,  /* 69 APPEAR USE */
    necro_yuca_068,  /* 70 APPEAR USE */
    necro_yuca_068,  /* 71 APPEAR USE */
    necro_yuca_068,  /* 72 APPEAR USE */
    necro_yuca_068,  /* 73 APPEAR USE */
    necro_yuca_068,  /* 74 APPEAR USE */
    necro_yuca_068,  /* 75 APPEAR USE */
    necro_yuca_068,  /* 76 APPEAR USE */
    necro_yuca_068,  /* 77 APPEAR USE */
    necro_yuca_068,  /* 78 APPEAR USE */
    necro_yuca_068,  /* 79 APPEAR USE */
    necro_yuca_068,  /* 80 APPEAR USE */
    necro_yuca_068,  /* 81 APPEAR USE */
    necro_yuca_068,  /* 82 APPEAR USE */
    necro_yuca_068,  /* 83 APPEAR USE */
    necro_yuca_068,  /* 84 APPEAR USE */
    necro_yuca_068,  /* 85 APPEAR USE */
    necro_yuca_068,  /* 86 APPEAR USE */
    necro_yuca_068,  /* 87 APPEAR USE */
    necro_yuca_068,  /* 88 APPEAR USE */
    necro_yuca_068,  /* 89 APPEAR USE */
    necro_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 */
const u16 necro_yuca_000_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 necro_yuca_000[8] = {
    L2(5, 9, 0, 0, 0, 0, 0, 0x214D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5, 5 APPEAR JUNBI 6, 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8 */
const u16 necro_yuca_004_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 necro_yuca_004[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0F),
    L2(4, 9, 0, 0, 0, 0, 0, 0x1E10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 */
const u16 necro_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_008[132] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x214D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x214E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x214F, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x214C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 811, 0, 0, 0, 0, 0x2150, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2158, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x214C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 218, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2149, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x213C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 220, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x213B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 APPEAR 5, 13 APPEAR 6, 14 APPEAR 7, 15 APPEAR 8 */
const u16 necro_yuca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_012[244] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E57, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E58, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E59, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 2048, 0, 0, 0, 0, 0x212B, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2124, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2125, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2126, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2127, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2128, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 necro_yuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_016[204] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E11),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E12),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E13),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E14),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E15),
    L2(1, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(1, 0, 0, 0, 0, 0, 0, 0x211C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x211D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x211E),
    CMD(CM_ASXY, 124, 0, 0),
    L2(1, 0, 809, 0, 0, 0, 0, 0x211F),
    CMD(CM_ASXY, 126, 0, 0),
    L2(1, 0, 328, 0, 0, 1, 0, 0x2120),
    CMD(CM_ASXY, 128, 0, 0),
    L2(2, 0, 0, 0, 0, 1, 0, 0x2121),
    CMD(CM_FOR, 0, 0, 3),
    L2(3, 0, 0, 0, 0, 1, 0, 0x2122),
    L2(2, 0, 0, 0, 0, 1, 0, 0x2123),
    L2(3, 0, 328, 0, 0, 1, 0, 0x2122),
    L2(2, 0, 0, 0, 0, 1, 0, 0x2123),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_ASXY, 130, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2120),
    CMD(CM_ASXY, 132, 0, 0),
    L2(2, 0, 304, 0, 0, 0, 0, 0x211F),
    CMD(CM_ASXY, 134, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x211E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x211D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x211C),
    L2(3, 64, 0, 0, 0, 0, 0, 0x1E67),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E3B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E3C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E3D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1E3D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 necro_yuca_024_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 necro_yuca_024[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E3B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2051),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2052),
    L2(3, 0, 273, 0, 0, 0, 0, 0x2053),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2054),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2151),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2152),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2153),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2154),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2154),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 ... */
const u16 necro_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_032[104] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(4, 0, 0, 0, 0, 0, 0, 0x211C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x211D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x211E),
    CMD(CM_ASXY, 222, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x211F),
    CMD(CM_ASXY, 224, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2130),
    CMD(CM_ASXY, 226, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2131),
    CMD(CM_ASXY, 228, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2132),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2133),
    L2(4, 0, 815, 0, 0, 0, 0, 0x2134),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2135),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2136),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2137),
    CMD(CM_FOR, 0, 0, 4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2138),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2139),
    L2(4, 0, 0, 0, 0, 0, 0, 0x213A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2139),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2139),
    CMD(CM_END, 0, 0, 24),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 ... */
const u16 necro_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_036[92] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x213B),
    CMD(CM_ASXY, 230, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x213C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x213D),
    CMD(CM_ASXY, 232, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x213E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x213F),
    CMD(CM_ASXY, 234, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x213D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2140),
    CMD(CM_ASXY, 236, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2141),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2142),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2143),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2144),
    L2(2, 0, 269, 0, 0, 0, 0, 0x2144),
    L2(4, 0, 816, 0, 0, 0, 0, 0x2145),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2146),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2147),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2148),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2148),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 necro_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_040[84] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x220A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2210),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2211),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2212),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2213),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2214),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2215),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2216),
    CMD(CM_FOR, 0, 0, 4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2217),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2218),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2219),
    L2(4, 255, 0, 0, 0, 0, 0, 0x2218),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_END, 0, 0, 18),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 necro_yuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_041[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x220A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x220D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x221F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2220),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2221),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2222),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2223),
    L2(4, 255, 0, 0, 0, 0, 0, 0x2224),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 SP WIN 3, 43 SP WIN 4, 44 SP WIN 5, 45 SP WIN 6 ... */
const u16 necro_yuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_042[108] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x220A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2225),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2226),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2227),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2228),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2229),
    L2(3, 0, 0, 0, 0, 0, 0, 0x222A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x222B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x222C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x222D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x222E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x222F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2230),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2231),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2232),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2233),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2234),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2235),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2236),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2237),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2238),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2239),
    L2(8, 0, 0, 0, 0, 0, 0, 0x223A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x223B),
    CMD(CM_END, 0, 0, 24),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 necro_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_048[88] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E0F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E11),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E12),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E13),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E14),
    L2(4, 255, 0, 0, 0, 0, 0, 0x1E15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 necro_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_060[172] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E04, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E05, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E06, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E07, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E08, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E09, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E10, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x1E15, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 necro_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_061[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x1E20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E47),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E48),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1E49),
    L2(6, 0, 0, 0, 0, 0, 0, 0x1E4A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x1E48),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1E47),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1E4B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1E4C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 necro_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_062[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x1E21),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1E22),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1E23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E3C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1E3D),
    L2(3, 255, 0, 0, 0, 0, 0, 0x1E3D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 necro_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_063[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x2074),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2076),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2077),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1E28),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1E28),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 necro_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0CB4),
    CMD(CM_ROA, 0, 0, 0),
};

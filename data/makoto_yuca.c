/*
 * MAKOTO_YUCA.C  Makoto's animation scripts
 *
 * The animation scripts Makoto's moves run, one table per kind of script (yuca),
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

extern const u16 makoto_yuca_000[], makoto_yuca_008[], makoto_yuca_016[], makoto_yuca_017[], makoto_yuca_018[], makoto_yuca_019[], makoto_yuca_020[], makoto_yuca_021[], makoto_yuca_022[], makoto_yuca_023[], makoto_yuca_024[], makoto_yuca_032[], makoto_yuca_036[], makoto_yuca_038[], makoto_yuca_039[], makoto_yuca_040[], makoto_yuca_048[], makoto_yuca_060[], makoto_yuca_061[], makoto_yuca_062[], makoto_yuca_063[], makoto_yuca_068[], makoto_yuca_089[], makoto_yuca_090[];
extern const u16 makoto_yuca_000_head[];
extern const u16 makoto_yuca_008_head[];
extern const u16 makoto_yuca_016_head[];
extern const u16 makoto_yuca_017_head[];
extern const u16 makoto_yuca_018_head[];
extern const u16 makoto_yuca_019_head[];
extern const u16 makoto_yuca_020_head[];
extern const u16 makoto_yuca_021_head[];
extern const u16 makoto_yuca_022_head[];
extern const u16 makoto_yuca_023_head[];
extern const u16 makoto_yuca_024_head[];
extern const u16 makoto_yuca_032_head[];
extern const u16 makoto_yuca_036_head[];
extern const u16 makoto_yuca_038_head[];
extern const u16 makoto_yuca_039_head[];
extern const u16 makoto_yuca_040_head[];
extern const u16 makoto_yuca_048_head[];
extern const u16 makoto_yuca_060_head[];
extern const u16 makoto_yuca_061_head[];
extern const u16 makoto_yuca_062_head[];
extern const u16 makoto_yuca_063_head[];
extern const u16 makoto_yuca_068_head[];
extern const u16 makoto_yuca_089_head[];
extern const u16 makoto_yuca_090_head[];

/* yuca scripts: 91 entries */
const u16* const makoto_yuca[92] = {
    makoto_yuca_000,  /* 0 APPEAR JUNBI 1 */
    makoto_yuca_000,  /* 1 APPEAR JUNBI 2 */
    makoto_yuca_000,  /* 2 APPEAR JUNBI 3 */
    makoto_yuca_000,  /* 3 APPEAR JUNBI 4 */
    makoto_yuca_000,  /* 4 APPEAR JUNBI 5 */
    makoto_yuca_000,  /* 5 APPEAR JUNBI 6 */
    makoto_yuca_000,  /* 6 APPEAR JUNBI 7 */
    makoto_yuca_000,  /* 7 APPEAR JUNBI 8 */
    makoto_yuca_008,  /* 8 APPEAR 1 */
    makoto_yuca_008,  /* 9 APPEAR 2 */
    makoto_yuca_008,  /* 10 APPEAR 3 */
    makoto_yuca_008,  /* 11 APPEAR 4 */
    makoto_yuca_008,  /* 12 APPEAR 5 */
    makoto_yuca_008,  /* 13 APPEAR 6 */
    makoto_yuca_008,  /* 14 APPEAR 7 */
    makoto_yuca_008,  /* 15 APPEAR 8 */
    makoto_yuca_016,  /* 16 SP APPEAR 1 */
    makoto_yuca_017,  /* 17 SP APPEAR 2 */
    makoto_yuca_018,  /* 18 SP APPEAR 3 */
    makoto_yuca_019,  /* 19 SP APPEAR 4 */
    makoto_yuca_020,  /* 20 SP APPEAR 5 */
    makoto_yuca_021,  /* 21 SP APPEAR 6 */
    makoto_yuca_022,  /* 22 SP APPEAR 7 */
    makoto_yuca_023,  /* 23 SP APPEAR 8 */
    makoto_yuca_024,  /* 24 ZANNEN 1 */
    makoto_yuca_024,  /* 25 ZANNEN 2 */
    makoto_yuca_024,  /* 26 ZANNEN 3 */
    makoto_yuca_024,  /* 27 ZANNEN 4 */
    makoto_yuca_024,  /* 28 ZANNEN 5 */
    makoto_yuca_024,  /* 29 ZANNEN 6 */
    makoto_yuca_024,  /* 30 ZANNEN 7 */
    makoto_yuca_024,  /* 31 ZANNEN 8 */
    makoto_yuca_032,  /* 32 WIN 1 */
    makoto_yuca_032,  /* 33 WIN 2 */
    makoto_yuca_032,  /* 34 WIN 3 */
    makoto_yuca_032,  /* 35 WIN 4 */
    makoto_yuca_036,  /* 36 WIN 5 */
    makoto_yuca_036,  /* 37 WIN 6 */
    makoto_yuca_038,  /* 38 WIN 7 */
    makoto_yuca_039,  /* 39 WIN 8 */
    makoto_yuca_040,  /* 40 SP WIN 1 */
    makoto_yuca_040,  /* 41 SP WIN 2 */
    makoto_yuca_040,  /* 42 SP WIN 3 */
    makoto_yuca_040,  /* 43 SP WIN 4 */
    makoto_yuca_040,  /* 44 SP WIN 5 */
    makoto_yuca_040,  /* 45 SP WIN 6 */
    makoto_yuca_040,  /* 46 SP WIN 7 */
    makoto_yuca_040,  /* 47 SP WIN 8 */
    makoto_yuca_048,  /* 48 JUDGMENT WAIT */
    makoto_yuca_048,  /* 49 JUDGMENT WAIT */
    makoto_yuca_048,  /* 50 JUDGMENT WAIT */
    makoto_yuca_048,  /* 51 JUDGMENT WAIT */
    makoto_yuca_032,  /* 52 JUDGMENT WIN */
    makoto_yuca_032,  /* 53 JUDGMENT WIN */
    makoto_yuca_032,  /* 54 JUDGMENT WIN */
    makoto_yuca_032,  /* 55 JUDGMENT WIN */
    makoto_yuca_024,  /* 56 JUDGMENT LOSE */
    makoto_yuca_024,  /* 57 JUDGMENT LOSE */
    makoto_yuca_024,  /* 58 JUDGMENT LOSE */
    makoto_yuca_024,  /* 59 JUDGMENT LOSE */
    makoto_yuca_060,  /* 60 WAIT */
    makoto_yuca_061,  /* 61 AFRICA JUMP */
    makoto_yuca_062,  /* 62 AFRICA LAND */
    makoto_yuca_063,  /* 63 SEAN BALL HIT */
    makoto_yuca_063,  /* 64 no name */
    makoto_yuca_036,  /* 65 BONUS WIN 1 */
    makoto_yuca_032,  /* 66 BONUS WIN 2 */
    makoto_yuca_024,  /* 67 BONUS WIN 3 */
    makoto_yuca_068,  /* 68 APPEAR USE */
    makoto_yuca_068,  /* 69 APPEAR USE */
    makoto_yuca_068,  /* 70 APPEAR USE */
    makoto_yuca_068,  /* 71 APPEAR USE */
    makoto_yuca_068,  /* 72 APPEAR USE */
    makoto_yuca_068,  /* 73 APPEAR USE */
    makoto_yuca_068,  /* 74 APPEAR USE */
    makoto_yuca_068,  /* 75 APPEAR USE */
    makoto_yuca_068,  /* 76 APPEAR USE */
    makoto_yuca_068,  /* 77 APPEAR USE */
    makoto_yuca_068,  /* 78 APPEAR USE */
    makoto_yuca_068,  /* 79 APPEAR USE */
    makoto_yuca_068,  /* 80 APPEAR USE */
    makoto_yuca_068,  /* 81 APPEAR USE */
    makoto_yuca_068,  /* 82 APPEAR USE */
    makoto_yuca_068,  /* 83 APPEAR USE */
    makoto_yuca_068,  /* 84 APPEAR USE */
    makoto_yuca_068,  /* 85 APPEAR USE */
    makoto_yuca_068,  /* 86 APPEAR USE */
    makoto_yuca_068,  /* 87 APPEAR USE */
    makoto_yuca_068,  /* 88 APPEAR USE */
    makoto_yuca_089,  /* 89 APPEAR USE */
    makoto_yuca_090,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 makoto_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_000[8] = {
    L2(4, 9, 0, 0, 0, 0, 0, 0xAC88),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 makoto_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_008[252] = {
    L4(48, 0, 0, 0, 0, 0, 0, 0xAC88, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0xAC89, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC8A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xAC8B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC8D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC8E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC8F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC90, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC91, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xAC92, 0, 1, 0, 0, 0, 0, 0),
    L4(24, 0, 0, 0, 0, 0, 0, 0xAC93, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xAC94, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xAC95, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC96, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xAC97, 0, 1, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0xAC98, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xAC99, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 1536, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0xAC9A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0xAC9B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 1792, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0xAC9C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 512, 0), 0, 0, 0, 0,
    L4(8, 0, 461, 0, 0, 0, 0, 0x6078, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6079, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x607A, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x607B, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x607C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 makoto_yuca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_016[96] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x6393),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6394),
    L2(8, 0, 273, 0, 0, 0, 0, 0x6065),
    L2(3, 9, 0, 0, 0, 0, 0, 0x6090),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6090),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6090),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6090),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6070),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6070),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6071),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6071),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6072),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6072),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6073),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6073),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6073),
    L2(5, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(5, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 makoto_yuca_017_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_017[120] = {
    L2(250, 9, 0, 0, 0, 0, 0, 0xACB8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xACB9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xACBA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xACBB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xACBC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xACBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACB9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACBF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACC1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACC2),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACC3),
    L2(250, 9, 0, 0, 0, 0, 0, 0xACB8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAC99),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAC9A),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9B),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAC9C),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 makoto_yuca_018_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_018[120] = {
    L2(48, 0, 0, 0, 0, 0, 0, 0xACC8),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACC9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xACCA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xACCB),
    L2(24, 0, 0, 0, 0, 0, 0, 0xACCC),
    L2(10, 0, 0, 0, 0, 0, 0, 0xACCD),
    L2(10, 0, 0, 0, 0, 0, 0, 0xACCE),
    L2(10, 0, 0, 0, 0, 0, 0, 0xACCF),
    L2(32, 0, 0, 0, 0, 0, 0, 0xACC8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xACD0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACD1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACD2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACD3),
    L2(48, 0, 0, 0, 0, 0, 0, 0xACA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACD4),
    CMD(CM_PA_X, 0, 1280, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D2),
    CMD(CM_PA_X, 0, -768, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D3),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x62D4),
    CMD(CM_PA_X, 0, -6912, 0),
    L2(4, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 makoto_yuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_019[188] = {
    L2(48, 0, 0, 0, 0, 0, 0, 0xACD8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACD9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACDE),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACDF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE3),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE4),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE5),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE6),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACA5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACEC),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACED),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACF0),
    L2(12, 0, 0, 0, 0, 0, 0, 0xACF1),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D2),
    CMD(CM_PA_X, 0, -768, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D3),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x62D4),
    CMD(CM_PA_X, 0, -6912, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6078),
    L2(2, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 makoto_yuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_020[184] = {
    L2(48, 0, 0, 0, 0, 0, 0, 0xACD8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACD9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACDD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACDE),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACDF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE3),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE4),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE5),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE6),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACA5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACEC),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACED),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACF0),
    L2(12, 0, 0, 0, 0, 0, 0, 0xACF1),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D2),
    CMD(CM_PA_X, 0, -768, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D3),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x62D4),
    CMD(CM_PA_X, 0, -6912, 0),
    L2(4, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 makoto_yuca_021_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_021[104] = {
    L2(86, 0, 0, 0, 0, 0, 0, 0xACE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACEC),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACED),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACF0),
    L2(12, 0, 0, 0, 0, 0, 0, 0xACF1),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D2),
    CMD(CM_PA_X, 0, -768, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D3),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(5, 0, 468, 0, 0, 0, 0, 0x62D4),
    CMD(CM_PA_X, 0, -6912, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 makoto_yuca_022_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_022[104] = {
    L2(62, 0, 0, 0, 0, 0, 0, 0xACE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACEC),
    L2(5, 0, 268, 0, 0, 0, 0, 0xACED),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACF0),
    L2(12, 0, 0, 0, 0, 0, 0, 0xACF1),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D2),
    CMD(CM_PA_X, 0, -768, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x62D3),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x62D4),
    CMD(CM_PA_X, 0, -6912, 0),
    L2(4, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(8, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 makoto_yuca_023_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_023[68] = {
    L2(72, 0, 0, 0, 0, 0, 0, 0xAC98),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAC99),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAC9A),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAC9B),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9C),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 468, 0, 0, 0, 0, 0x6078),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6079),
    L2(4, 0, 0, 0, 0, 0, 0, 0x607A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x607B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x607D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x607D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 makoto_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_024[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6060),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACB4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACB5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACB6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACB7),
    L2(3, 0, 285, 0, 0, 0, 0, 0xACC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACC5),
    L2(4, 0, 452, 0, 0, 0, 0, 0xACC6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACC7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xACD5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACD6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACD7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xACD7),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 ... */
const u16 makoto_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_032[132] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xAC9D),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAC9E),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9F),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACA0),
    CMD(CM_PA_X, 0, 256, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACA1),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACA2),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACA3),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACA4),
    L2(16, 0, 0, 0, 0, 0, 0, 0xACA5),
    CMD(CM_PAXY, 0, 1536, -512),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACA6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xACA7),
    CMD(CM_PA_X, 0, -4352, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACA8),
    CMD(CM_PA_X, 0, 768, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACA9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACAA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACAB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACAC),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACAD),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACAE),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACAF),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACB0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACB1),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACB2),
    L2(6, 0, 0, 0, 0, 0, 0, 0xACB3),
    L2(250, 255, 0, 0, 0, 0, 0, 0xACB3),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 65 BONUS WIN 1 */
const u16 makoto_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_036[92] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xACF8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xACF9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACFA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xACFB),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(2, 0, 467, 0, 0, 117, 0, 0xACFC),
    L2(4, 0, 0, 0, 0, 117, 0, 0xACFD),
    L2(4, 0, 0, 0, 0, 118, 0, 0xACFE),
    L2(2, 0, 0, 0, 0, 118, 0, 0xACFF),
    L2(2, 0, 0, 0, 0, 119, 0, 0xACFF),
    L2(4, 0, 0, 0, 0, 119, 0, 0xAD00),
    L2(4, 0, 0, 0, 0, 120, 0, 0xAD00),
    L2(5, 0, 0, 0, 0, 120, 0, 0xAD01),
    L2(3, 0, 0, 0, 0, 120, 0, 0xAD02),
    L2(2, 0, 0, 0, 0, 121, 0, 0xAD02),
    L2(2, 0, 0, 0, 0, 121, 0, 0xAD03),
    L2(2, 0, 0, 0, 0, 121, 0, 0xAD03),
    L2(6, 0, 0, 0, 0, 122, 0, 0xAD03),
    L2(6, 0, 0, 0, 0, 123, 0, 0xAD03),
    L2(6, 0, 0, 0, 0, 124, 0, 0xAD03),
    L2(250, 255, 0, 0, 0, 125, 0, 0xAD03),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 makoto_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_038[112] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9D),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9E),
    CMD(CM_PA_X, 0, -768, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAD18),
    CMD(CM_PA_X, 0, -768, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD19),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(32, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(6, 0, 477, 0, 0, 126, 0, 0xAD1F),
    L2(4, 0, 0, 0, 0, 127, 0, 0xAD20),
    L2(2, 0, 0, 0, 0, 127, 0, 0xAD21),
    L2(9, 0, 0, 0, 0, 131, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 135, 0, 0xAD21),
    L2(9, 0, 0, 0, 0, 137, 0, 0xAD21),
    L2(250, 255, 0, 0, 0, 138, 0, 0xAD21),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 makoto_yuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_039[144] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9D),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAC9E),
    CMD(CM_PA_X, 0, -768, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAD18),
    CMD(CM_PA_X, 0, -768, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD19),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAD1D),
    L2(32, 0, 0, 0, 0, 0, 0, 0xAD1C),
    L2(5, 0, 465, 0, 0, 126, 0, 0xAD1F),
    L2(3, 0, 0, 0, 0, 126, 0, 0xAD20),
    L2(2, 0, 0, 0, 0, 127, 0, 0xAD20),
    L2(6, 0, 0, 0, 0, 127, 0, 0xAD21),
    L2(6, 0, 0, 0, 0, 128, 0, 0xAD21),
    L2(44, 0, 0, 0, 0, 129, 0, 0xAD21),
    L2(12, 0, 0, 0, 0, 130, 0, 0xAD21),
    L2(12, 0, 0, 0, 0, 131, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 132, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 133, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 134, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 135, 0, 0xAD21),
    L2(8, 0, 0, 0, 0, 136, 0, 0xAD21),
    L2(9, 0, 0, 0, 0, 137, 0, 0xAD21),
    L2(250, 255, 0, 0, 0, 138, 0, 0xAD21),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 makoto_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_040[8] = {
    L2(7, 255, 0, 0, 0, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 makoto_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_048[24] = {
    L2(40, 0, 0, 0, 0, 0, 0, 0x6013),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6014),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6015),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6014),
    L2(6, 255, 0, 0, 0, 0, 0, 0x6014),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 makoto_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_060[36] = {
    L4(60, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 255, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 makoto_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_061[76] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6029),
    L2(1, 0, 281, 0, 0, 0, 0, 0x6040),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6041),
    L2(1, 0, 0, 0, 0, 0, 0, 0x606A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6040),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6041),
    L2(1, 0, 0, 0, 0, 0, 0, 0x606A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6042),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6043),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6044),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6045),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6046),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6047),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6048),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6049),
    L2(3, 0, 0, 0, 0, 0, 0, 0x604A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x606B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 makoto_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_062[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x602A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x604B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x602F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x602F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 makoto_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_063[20] = {
    L2(12, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6027),
    L2(4, 0, 0, 0, 0, 0, 0, 0x6028),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6028),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 makoto_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x60B4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 APPEAR USE */
const u16 makoto_yuca_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_089[40] = {
    L2(6, 0, 467, 0, 0, 0, 0, 0xAD04),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD05),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD06),
    L2(12, 0, 0, 0, 0, 0, 0, 0xAD07),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD08),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD09),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD0A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD0B),
    L2(120, 0, 0, 0, 0, 0, 0, 0xAD0C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 APPEAR USE */
const u16 makoto_yuca_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_yuca_090[56] = {
    L2(8, 0, 465, 0, 0, 0, 0, 0xAD22),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD23),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAD24),
    L2(44, 0, 0, 0, 0, 0, 0, 0xAD25),
    L2(12, 0, 0, 0, 0, 0, 0, 0xAD26),
    L2(12, 0, 0, 0, 0, 0, 0, 0xAD27),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD28),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD29),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD2A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD2B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD2C),
    L2(9, 0, 0, 0, 0, 0, 0, 0xAD2D),
    L2(120, 0, 0, 0, 0, 0, 0, 0xAD2E),
    CMD(CM_ROA, 0, 0, 0),
};

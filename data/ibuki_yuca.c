/*
 * IBUKI_YUCA.C  Ibuki's animation scripts
 *
 * The animation scripts Ibuki's moves run, one table per kind of script (yuca),
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

extern const u16 ibuki_yuca_000[], ibuki_yuca_004[], ibuki_yuca_006[], ibuki_yuca_008[], ibuki_yuca_012[], ibuki_yuca_014[], ibuki_yuca_016[], ibuki_yuca_017[], ibuki_yuca_024[], ibuki_yuca_032[], ibuki_yuca_033[], ibuki_yuca_034[], ibuki_yuca_035[], ibuki_yuca_036[], ibuki_yuca_037[], ibuki_yuca_038[], ibuki_yuca_039[], ibuki_yuca_040[], ibuki_yuca_041[], ibuki_yuca_042[], ibuki_yuca_043[], ibuki_yuca_044[], ibuki_yuca_048[], ibuki_yuca_052[], ibuki_yuca_056[], ibuki_yuca_060[], ibuki_yuca_061[], ibuki_yuca_062[], ibuki_yuca_063[], ibuki_yuca_068[];
extern const u16 ibuki_yuca_000_head[];
extern const u16 ibuki_yuca_004_head[];
extern const u16 ibuki_yuca_006_head[];
extern const u16 ibuki_yuca_008_head[];
extern const u16 ibuki_yuca_012_head[];
extern const u16 ibuki_yuca_014_head[];
extern const u16 ibuki_yuca_016_head[];
extern const u16 ibuki_yuca_017_head[];
extern const u16 ibuki_yuca_024_head[];
extern const u16 ibuki_yuca_032_head[];
extern const u16 ibuki_yuca_033_head[];
extern const u16 ibuki_yuca_034_head[];
extern const u16 ibuki_yuca_035_head[];
extern const u16 ibuki_yuca_036_head[];
extern const u16 ibuki_yuca_037_head[];
extern const u16 ibuki_yuca_038_head[];
extern const u16 ibuki_yuca_039_head[];
extern const u16 ibuki_yuca_040_head[];
extern const u16 ibuki_yuca_041_head[];
extern const u16 ibuki_yuca_042_head[];
extern const u16 ibuki_yuca_043_head[];
extern const u16 ibuki_yuca_044_head[];
extern const u16 ibuki_yuca_048_head[];
extern const u16 ibuki_yuca_052_head[];
extern const u16 ibuki_yuca_056_head[];
extern const u16 ibuki_yuca_060_head[];
extern const u16 ibuki_yuca_061_head[];
extern const u16 ibuki_yuca_062_head[];
extern const u16 ibuki_yuca_063_head[];
extern const u16 ibuki_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const ibuki_yuca[92] = {
    ibuki_yuca_000,  /* 0 APPEAR JUNBI 1 */
    ibuki_yuca_000,  /* 1 APPEAR JUNBI 2 */
    ibuki_yuca_000,  /* 2 APPEAR JUNBI 3 */
    ibuki_yuca_000,  /* 3 APPEAR JUNBI 4 */
    ibuki_yuca_004,  /* 4 APPEAR JUNBI 5 */
    ibuki_yuca_004,  /* 5 APPEAR JUNBI 6 */
    ibuki_yuca_006,  /* 6 APPEAR JUNBI 7 */
    ibuki_yuca_006,  /* 7 APPEAR JUNBI 8 */
    ibuki_yuca_008,  /* 8 APPEAR 1 */
    ibuki_yuca_008,  /* 9 APPEAR 2 */
    ibuki_yuca_008,  /* 10 APPEAR 3 */
    ibuki_yuca_008,  /* 11 APPEAR 4 */
    ibuki_yuca_012,  /* 12 APPEAR 5 */
    ibuki_yuca_012,  /* 13 APPEAR 6 */
    ibuki_yuca_014,  /* 14 APPEAR 7 */
    ibuki_yuca_014,  /* 15 APPEAR 8 */
    ibuki_yuca_016,  /* 16 SP APPEAR 1 */
    ibuki_yuca_017,  /* 17 SP APPEAR 2 */
    ibuki_yuca_017,  /* 18 SP APPEAR 3 */
    ibuki_yuca_017,  /* 19 SP APPEAR 4 */
    ibuki_yuca_017,  /* 20 SP APPEAR 5 */
    ibuki_yuca_017,  /* 21 SP APPEAR 6 */
    ibuki_yuca_017,  /* 22 SP APPEAR 7 */
    ibuki_yuca_017,  /* 23 SP APPEAR 8 */
    ibuki_yuca_024,  /* 24 ZANNEN 1 */
    ibuki_yuca_024,  /* 25 ZANNEN 2 */
    ibuki_yuca_024,  /* 26 ZANNEN 3 */
    ibuki_yuca_024,  /* 27 ZANNEN 4 */
    ibuki_yuca_024,  /* 28 ZANNEN 5 */
    ibuki_yuca_024,  /* 29 ZANNEN 6 */
    ibuki_yuca_024,  /* 30 ZANNEN 7 */
    ibuki_yuca_024,  /* 31 ZANNEN 8 */
    ibuki_yuca_032,  /* 32 WIN 1 */
    ibuki_yuca_033,  /* 33 WIN 2 */
    ibuki_yuca_034,  /* 34 WIN 3 */
    ibuki_yuca_035,  /* 35 WIN 4 */
    ibuki_yuca_036,  /* 36 WIN 5 */
    ibuki_yuca_037,  /* 37 WIN 6 */
    ibuki_yuca_038,  /* 38 WIN 7 */
    ibuki_yuca_039,  /* 39 WIN 8 */
    ibuki_yuca_040,  /* 40 SP WIN 1 */
    ibuki_yuca_041,  /* 41 SP WIN 2 */
    ibuki_yuca_042,  /* 42 SP WIN 3 */
    ibuki_yuca_043,  /* 43 SP WIN 4 */
    ibuki_yuca_044,  /* 44 SP WIN 5 */
    ibuki_yuca_044,  /* 45 SP WIN 6 */
    ibuki_yuca_044,  /* 46 SP WIN 7 */
    ibuki_yuca_044,  /* 47 SP WIN 8 */
    ibuki_yuca_048,  /* 48 JUDGMENT WAIT */
    ibuki_yuca_048,  /* 49 JUDGMENT WAIT */
    ibuki_yuca_048,  /* 50 JUDGMENT WAIT */
    ibuki_yuca_048,  /* 51 JUDGMENT WAIT */
    ibuki_yuca_052,  /* 52 JUDGMENT WIN */
    ibuki_yuca_052,  /* 53 JUDGMENT WIN */
    ibuki_yuca_052,  /* 54 JUDGMENT WIN */
    ibuki_yuca_052,  /* 55 JUDGMENT WIN */
    ibuki_yuca_056,  /* 56 JUDGMENT LOSE */
    ibuki_yuca_056,  /* 57 JUDGMENT LOSE */
    ibuki_yuca_056,  /* 58 JUDGMENT LOSE */
    ibuki_yuca_056,  /* 59 JUDGMENT LOSE */
    ibuki_yuca_060,  /* 60 WAIT */
    ibuki_yuca_061,  /* 61 AFRICA JUMP */
    ibuki_yuca_062,  /* 62 AFRICA LAND */
    ibuki_yuca_063,  /* 63 SEAN BALL HIT */
    ibuki_yuca_063,  /* 64 no name */
    ibuki_yuca_032,  /* 65 BONUS WIN 1 */
    ibuki_yuca_039,  /* 66 BONUS WIN 2 */
    ibuki_yuca_036,  /* 67 BONUS WIN 3 */
    ibuki_yuca_068,  /* 68 APPEAR USE */
    ibuki_yuca_068,  /* 69 APPEAR USE */
    ibuki_yuca_068,  /* 70 APPEAR USE */
    ibuki_yuca_068,  /* 71 APPEAR USE */
    ibuki_yuca_068,  /* 72 APPEAR USE */
    ibuki_yuca_068,  /* 73 APPEAR USE */
    ibuki_yuca_068,  /* 74 APPEAR USE */
    ibuki_yuca_068,  /* 75 APPEAR USE */
    ibuki_yuca_068,  /* 76 APPEAR USE */
    ibuki_yuca_068,  /* 77 APPEAR USE */
    ibuki_yuca_068,  /* 78 APPEAR USE */
    ibuki_yuca_068,  /* 79 APPEAR USE */
    ibuki_yuca_068,  /* 80 APPEAR USE */
    ibuki_yuca_068,  /* 81 APPEAR USE */
    ibuki_yuca_068,  /* 82 APPEAR USE */
    ibuki_yuca_068,  /* 83 APPEAR USE */
    ibuki_yuca_068,  /* 84 APPEAR USE */
    ibuki_yuca_068,  /* 85 APPEAR USE */
    ibuki_yuca_068,  /* 86 APPEAR USE */
    ibuki_yuca_068,  /* 87 APPEAR USE */
    ibuki_yuca_068,  /* 88 APPEAR USE */
    ibuki_yuca_068,  /* 89 APPEAR USE */
    ibuki_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 */
const u16 ibuki_yuca_000_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_000[12] = {
    L2(2, 9, 0, 0, 0, 365, 0, 0x2BB8),
    CMD(CM_DUMMY, 8192, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5, 5 APPEAR JUNBI 6 */
const u16 ibuki_yuca_004_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_004[12] = {
    L4(9, 9, 0, 0, 0, 0, 0, 0x9C52, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8 */
const u16 ibuki_yuca_006_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_006[12] = {
    L4(30, 9, 0, 0, 0, 0, 0, 0x9BDD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 */
const u16 ibuki_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_008[308] = {
    L4(30, 0, 0, 0, 0, 365, 0, 0x2BB8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 4096, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 366, 0, 0x2BB9, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 367, 0, 0x2BBA, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 368, 0, 0x2BBB, -109, 0, 2212, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 369, 0, 0x2BBC, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 1536, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 370, 0, 0x2BBD, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1536, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 371, 0, 0x2B98, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -512, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 372, 0, 0x2B99, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -512, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 373, 0, 0x2B9A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 374, 0, 0x2B9B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 375, 0, 0x2B9C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 376, 0, 0x2B9D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 474, 0, 0x2C1D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 2816, 0), 0, 0, 0, 0,
    L4(4, 0, 269, 0, 0, 475, 0, 0x2C1E, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 4352, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 476, 0, 0x2C18, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 477, 0, 0x2C19, -110, 0, 0, 134, 32, 0, 0),
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 3, 0, 0, 0, 478, 0, 0x2C1A, 0, 0, 0, 0, 32, 0, 0),
    L4(4, 0, 0, 0, 0, 479, 0, 0x2C1B, 0, 0, 0, 0, 32, 0, 0),
    CMD(CM_PA_X, 0, -512, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 480, 0, 0x2C1C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3584, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 481, 0, 0x2C2A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 482, 0, 0x2C2B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 483, 0, 0x2B9A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 484, 0, 0x2B9B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 485, 0, 0x2B9C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 486, 0, 0x2B9D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 255, 0, 0, 0, 486, 0, 0x2B9D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 APPEAR 5, 13 APPEAR 6 */
const u16 ibuki_yuca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_012[228] = {
    L4(8, 0, 0, 0, 0, 1376, 0, 0x9C52, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1377, 0, 0x9C53, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1378, 0, 0x9C54, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1379, 0, 0x9C55, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1380, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1381, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1382, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1383, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1384, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1385, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1386, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1387, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1388, 0, 0x9C58, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1389, 0, 0x9C59, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1390, 0, 0x9C5A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1391, 0, 0x9C5B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1392, 0, 0x9C5C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 1393, 0, 0x9C5D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 361, 0, 0, 1393, 0, 0x9C5E, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C5F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1393, 0, 0x9C60, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C61, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C62, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1393, 0, 0x9C63, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 1393, 0, 0x9C64, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1393, 0, 0x9C65, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C66, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 1393, 0, 0x9C66, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 APPEAR 7, 15 APPEAR 8 */
const u16 ibuki_yuca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_014[284] = {
    CMD(CM_EXEC, 57, 0, 0), 0, 0, 0, 0,
    L4(30, 0, 0, 0, 0, 0, 0, 0x9BDD, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x9BDE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9BDF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 12, 5, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x9BE0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 12, 6, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1376, 0, 0x9C52, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1377, 0, 0x9C53, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1378, 0, 0x9C54, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1379, 0, 0x9C55, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1380, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1381, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1382, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1383, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1384, 0, 0x9C56, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1385, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1386, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1387, 0, 0x9C57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 2215, 0, 0x9C58, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2216, 0, 0x9C59, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1390, 0, 0x9C5A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1391, 0, 0x9C5B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1392, 0, 0x9C5C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 1393, 0, 0x9C5D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 361, 0, 0, 1393, 0, 0x9C5E, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C5F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1393, 0, 0x9C60, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C61, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C62, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1393, 0, 0x9C63, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 1393, 0, 0x9C64, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1393, 0, 0x9C65, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1393, 0, 0x9C66, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 1393, 0, 0x9C66, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 ibuki_yuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_016[96] = {
    L2(6, 0, 0, 0, 0, 926, 0, 0x2CAF),
    L2(250, 0, 0, 0, 0, 927, 0, 0x2CB0),
    L2(8, 0, 273, 0, 0, 2086, 0, 0x2A4A),
    L2(3, 0, 0, 0, 0, 2087, 0, 0x2A52),
    L2(2, 0, 0, 0, 0, 2088, 0, 0x2A53),
    L2(1, 0, 0, 0, 0, 2089, 0, 0x2A54),
    L2(4, 9, 0, 0, 0, 1377, 0, 0x2E11),
    L2(3, 0, 0, 0, 0, 1378, 0, 0x2E12),
    L2(4, 0, 0, 0, 0, 1379, 0, 0x2E13),
    L2(2, 0, 0, 0, 0, 1380, 0, 0x2E14),
    L2(2, 0, 0, 0, 0, 1381, 0, 0x2E14),
    L2(2, 0, 0, 0, 0, 1382, 0, 0x2E14),
    L2(4, 0, 0, 0, 0, 1385, 0, 0x2E15),
    L2(4, 0, 0, 0, 0, 1386, 0, 0x2E15),
    L2(4, 0, 0, 0, 0, 1387, 0, 0x2E15),
    L2(2, 0, 0, 0, 0, 1388, 0, 0x2E15),
    L2(4, 0, 363, 0, 0, 1389, 0, 0x2E16),
    L2(4, 0, 0, 0, 0, 1390, 0, 0x2E17),
    L2(3, 0, 0, 0, 0, 1391, 0, 0x2E18),
    L2(4, 0, 0, 0, 0, 1392, 0, 0x2E19),
    L2(5, 0, 0, 0, 0, 1393, 0, 0x2E1A),
    L2(5, 0, 0, 0, 0, 1393, 0, 0x2E1B),
    L2(250, 255, 0, 0, 0, 1393, 0, 0x2E1B),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4, 20 SP APPEAR 5 ... */
const u16 ibuki_yuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_017[8] = {
    L2(4, 0, 0, 0, 0, 161, 0, 0x2A01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 ibuki_yuca_024_head[4] = { HEAD(2, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_024[72] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x2C49),
    L2(18, 0, 0, 0, 0, 0, 0, 0x2C4A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2C4B),
    L2(2, 0, 0, 0, 0, 1394, 0, 0x2B5C),
    L2(4, 0, 0, 0, 0, 1395, 0, 0x2B5D),
    L2(4, 0, 0, 0, 0, 1396, 0, 0x2B5E),
    L2(2, 0, 0, 0, 0, 1397, 0, 0x2B5F),
    L2(2, 0, 0, 0, 0, 1398, 0, 0x2B5F),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 1399, 0, 0x2B60),
    L2(3, 0, 0, 0, 0, 1400, 0, 0x2B61),
    L2(3, 0, 0, 0, 0, 1401, 0, 0x2B62),
    L2(3, 0, 0, 0, 0, 1402, 0, 0x2B63),
    L2(3, 0, 0, 0, 0, 1403, 0, 0x2B63),
    L2(3, 0, 0, 0, 0, 1404, 0, 0x2B63),
    L2(250, 255, 0, 0, 0, 1404, 0, 0x2B63),
    CMD(CM_END, 0, 0, 16),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 65 BONUS WIN 1 */
const u16 ibuki_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_032[48] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x2D25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D27),
    L2(4, 0, 360, 0, 0, 0, 0, 0x2D28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D2C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D2D),
    L2(4, 255, 0, 0, 0, 0, 0, 0x2D2D),
    CMD(CM_END, 0, 0, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 ibuki_yuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_033[52] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BA9),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAA),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAB),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAC),
    L2(6, 0, 367, 0, 1, 0, 0, 0x9BAD),
    L2(6, 0, 0, 0, 1, 0, 0, 0x9BAF),
    L2(6, 0, 0, 0, 1, 0, 0, 0x9BB0),
    L2(6, 0, 0, 0, 1, 0, 0, 0x9BAD),
    L2(6, 0, 0, 0, 1, 0, 0, 0x9BAE),
    L2(6, 0, 0, 0, 1, 0, 0, 0x9BB1),
    L2(6, 255, 0, 0, 1, 0, 0, 0x9BB3),
    CMD(CM_END, 0, 0, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 ibuki_yuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_034[24] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BAC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BAB),
    L2(4, 255, 0, 0, 0, 0, 0, 0x9BAA),
    CMD(CM_END, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 ibuki_yuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_035[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BCA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BCB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BCC),
    L2(200, 255, 0, 0, 0, 0, 0, 0x9BCD),
    CMD(CM_END, 0, 0, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 67 BONUS WIN 3 */
const u16 ibuki_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_036[100] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BB4),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BB5),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9BB6),
    L2(2, 0, 0, 0, 1, 953, 0, 0x9BB7),
    L2(2, 0, 0, 0, 1, 954, 0, 0x9BB7),
    L2(2, 0, 0, 0, 1, 955, 0, 0x9BB8),
    L2(2, 0, 0, 0, 1, 956, 0, 0x9BB8),
    L2(2, 0, 0, 0, 1, 957, 0, 0x9BB9),
    L2(2, 0, 0, 0, 1, 958, 0, 0x9BB9),
    L2(2, 0, 0, 0, 1, 959, 0, 0x9BBA),
    L2(2, 0, 0, 0, 1, 959, 0, 0x9BBA),
    L2(2, 0, 0, 0, 1, 960, 0, 0x9BBA),
    L2(2, 0, 0, 0, 1, 961, 0, 0x9BBA),
    L2(2, 0, 0, 0, 1, 962, 0, 0x9BBB),
    L2(6, 0, 0, 0, 1, 963, 0, 0x9BBC),
    L2(4, 0, 0, 0, 1, 963, 0, 0x9BBD),
    L2(4, 0, 0, 0, 1, 963, 0, 0x9BBE),
    L2(4, 0, 364, 0, 1, 963, 0, 0x9BBF),
    L2(10, 0, 0, 0, 1, 963, 0, 0x9BC0),
    L2(7, 0, 0, 0, 1, 963, 0, 0x9BC2),
    L2(6, 0, 0, 0, 1, 963, 0, 0x9BC3),
    L2(6, 0, 0, 0, 1, 963, 0, 0x9BC4),
    L2(4, 255, 0, 0, 1, 963, 0, 0x9BC8),
    CMD(CM_END, 0, 0, 23),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 ibuki_yuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_037[60] = {
    CMD(CM_EXEC, 12, 5, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BB4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BE1),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BE2),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BE3),
    L2(12, 0, 364, 0, 0, 0, 0, 0x9BE4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BE5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BE6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BE7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BE8),
    L2(6, 255, 0, 0, 0, 0, 0, 0x9BE3),
    CMD(CM_END, 0, 0, 13),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 ibuki_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_038[76] = {
    CMD(CM_EXEC, 12, 5, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BB4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BE1),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BE2),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BE9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BEA),
    CMD(CM_EXEC, 12, 4, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BEB),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BEC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BED),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BEE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BF0),
    L2(2, 255, 0, 0, 0, 0, 0, 0x9BF1),
    CMD(CM_END, 0, 0, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 WIN 8, 66 BONUS WIN 2 */
const u16 ibuki_yuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_039[156] = {
    CMD(CM_PA_X, 0, -512, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DF7),
    CMD(CM_PA_X, 0, -2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DF8),
    CMD(CM_PA_X, 0, -2560, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DF9),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DFA),
    CMD(CM_PA_X, 0, -256, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DFB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DFC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DFD),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2DFE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2DFF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2E00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2E01),
    L2(10, 0, 0, 0, 0, 0, 0, 0x2E02),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E03),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E04),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E05),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E06),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E07),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E03),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E04),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E05),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E06),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E07),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2E03),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2E04),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2E05),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2E06),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2E07),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E03),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E04),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E05),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E06),
    L2(8, 255, 0, 0, 0, 0, 0, 0x2E07),
    CMD(CM_IXBW, 0, 0, 20),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 ibuki_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_040[92] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E81),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E82),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E83),
    CMD(CM_PA_X, 0, -1280, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E84),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2E85),
    CMD(CM_PA_X, 0, -1536, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E86),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2E87),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2E88),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E89),
    L2(12, 0, 0, 0, 0, 0, 0, 0x2E8A),
    L2(24, 0, 370, 0, 0, 0, 0, 0x2E8B),
    L2(12, 0, 0, 0, 0, 0, 0, 0x2E8C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E8D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E8E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x2E8C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2E8D),
    L2(8, 255, 0, 0, 0, 0, 0, 0x2E8E),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 ibuki_yuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_041[124] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E91),
    CMD(CM_PA_X, 0, -512, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E92),
    CMD(CM_PA_X, 0, -1536, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E93),
    CMD(CM_PA_X, 0, -2816, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E94),
    CMD(CM_PA_X, 0, -4608, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E95),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E96),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E97),
    CMD(CM_PA_X, 0, 512, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E98),
    CMD(CM_PA_X, 0, 256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2E9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9C),
    L2(2, 0, 268, 0, 0, 0, 0, 0x2E9D),
    L2(2, 0, 366, 0, 0, 0, 0, 0x2E9E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2EA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2EA1),
    CMD(CM_EXEC, 12, 5, 0),
    CMD(CM_EXEC, 57, 1, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2EA1),
    L2(4, 255, 0, 0, 0, 0, 0, 0x2EA1),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 ibuki_yuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_042[136] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E91),
    CMD(CM_PA_X, 0, -512, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E92),
    CMD(CM_PA_X, 0, -1536, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E93),
    CMD(CM_PA_X, 0, -2816, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E94),
    CMD(CM_PA_X, 0, -4608, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E95),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E96),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E97),
    CMD(CM_PA_X, 0, 512, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E98),
    CMD(CM_PA_X, 0, 256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2E9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9C),
    L2(2, 0, 268, 0, 0, 0, 0, 0x2E9D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2E9E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2E9F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2EA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2EA1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2EA2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2EA3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2EA4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2EA5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2EA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2EA7),
    L2(4, 255, 0, 0, 0, 0, 0, 0x2EA8),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 ibuki_yuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_043[84] = {
    CMD(CM_EXEC, 12, 5, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BB4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9BE1),
    CMD(CM_EXEC, 12, 28, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9BE1),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BE2),
    CMD(CM_PA_X, 0, -2048, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BE9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BEA),
    CMD(CM_EXEC, 12, 4, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BEB),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BEC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BED),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BEE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9BEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BF0),
    L2(2, 255, 0, 0, 0, 0, 0, 0x9BF1),
    CMD(CM_IXBW, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 SP WIN 5, 45 SP WIN 6, 46 SP WIN 7, 47 SP WIN 8 */
const u16 ibuki_yuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_044[60] = {
    L2(10, 0, 0, 0, 0, 161, 0, 0x2EA9),
    L2(8, 0, 0, 0, 0, 161, 0, 0x2EA9),
    L2(4, 0, 0, 0, 0, 161, 0, 0x2EA9),
    L2(10, 0, 0, 0, 0, 161, 0, 0x2EA9),
    L2(4, 0, 0, 0, 0, 161, 0, 0x2EAA),
    L2(6, 0, 0, 0, 0, 161, 0, 0x2EAB),
    L2(4, 0, 0, 0, 0, 161, 0, 0x2EAC),
    L2(10, 0, 0, 0, 0, 161, 0, 0x2EAD),
    L2(2, 0, 0, 0, 0, 161, 0, 0x2EAD),
    L2(2, 0, 0, 0, 0, 161, 0, 0x2EAE),
    L2(2, 0, 0, 0, 0, 161, 0, 0x2EAF),
    L2(4, 0, 0, 0, 0, 161, 0, 0x2EB0),
    L2(2, 0, 0, 0, 0, 161, 0, 0x2EAD),
    CMD(CM_IXBW, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 ibuki_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_048[68] = {
    L2(6, 0, 0, 0, 0, 161, 0, 0x2A01),
    L2(5, 0, 0, 0, 0, 162, 0, 0x2A02),
    L2(4, 0, 0, 0, 0, 163, 0, 0x2A03),
    CMD(CM_IXFW, 0, 0, 4),
    L2(3, 0, 0, 0, 0, 161, 0, 0x2A01),
    L2(3, 0, 0, 0, 0, 162, 0, 0x2A02),
    L2(3, 0, 0, 0, 0, 163, 0, 0x2A03),
    L2(3, 0, 0, 0, 0, 164, 0, 0x2A04),
    L2(3, 0, 0, 0, 0, 165, 0, 0x2A05),
    L2(3, 0, 0, 0, 0, 166, 0, 0x2A06),
    L2(3, 0, 0, 0, 0, 167, 0, 0x2A07),
    L2(3, 0, 0, 0, 0, 168, 0, 0x2A08),
    L2(3, 0, 0, 0, 0, 169, 0, 0x2A09),
    L2(3, 0, 0, 0, 0, 170, 0, 0x2A0A),
    L2(3, 0, 0, 0, 0, 171, 0, 0x2A0B),
    L2(3, 255, 0, 0, 0, 172, 0, 0x2A0C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN, 55 JUDGMENT WIN */
const u16 ibuki_yuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_052[64] = {
    L2(4, 0, 0, 0, 1, 2, 0, 0x2A15),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BA9),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAA),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAB),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAC),
    L2(4, 0, 364, 0, 1, 0, 0, 0x9BAE),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BB1),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAF),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAE),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAC),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAE),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BAD),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9BB1),
    L2(4, 255, 0, 0, 1, 0, 0, 0x9BB2),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 JUDGMENT LOSE, 57 JUDGMENT LOSE, 58 JUDGMENT LOSE, 59 JUDGMENT LOSE */
const u16 ibuki_yuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_056[72] = {
    L2(8, 0, 0, 0, 0, 1405, 0, 0x2D20),
    L2(3, 0, 0, 0, 0, 1406, 0, 0x2D21),
    CMD(CM_PA_X, 0, 256, 0),
    L2(7, 0, 0, 0, 0, 1407, 0, 0x2D22),
    CMD(CM_PA_X, 0, 256, 0),
    L2(5, 0, 0, 0, 0, 1408, 0, 0x2D23),
    L2(8, 0, 0, 0, 0, 1409, 0, 0x2D24),
    L2(8, 0, 0, 0, 0, 1410, 0, 0x2D24),
    L2(2, 0, 0, 0, 0, 1411, 0, 0x2D22),
    CMD(CM_FOR, 0, 0, 4),
    L2(2, 0, 0, 0, 0, 1412, 0, 0x2D22),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 0, 0, 0, 1408, 0, 0x2D23),
    L2(20, 255, 0, 0, 0, 1409, 0, 0x2D24),
    CMD(CM_NEX, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 1408, 0, 0x2D23),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 ibuki_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_060[340] = {
    L4(6, 0, 0, 0, 0, 161, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 162, 0, 0x2A02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 163, 0, 0x2A03, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 161, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 162, 0, 0x2A02, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 163, 0, 0x2A03, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 164, 0, 0x2A04, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 165, 0, 0x2A05, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 166, 0, 0x2A06, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 167, 0, 0x2A07, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 168, 0, 0x2A08, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 169, 0, 0x2A09, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 170, 0, 0x2A0A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 171, 0, 0x2A0B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 172, 0, 0x2A0C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 173, 0, 0x2A0D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 174, 0, 0x2A0E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 175, 0, 0x2A10, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 176, 0, 0x2A11, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 177, 0, 0x2A12, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 178, 0, 0x2A13, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 179, 0, 0x2A14, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 180, 0, 0x2C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_PJMP, 8, 8194, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 181, 0, 0x2C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 182, 0, 0x2C40, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 183, 0, 0x2C41, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 181, 0, 0x2C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 182, 0, 0x2C40, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 183, 0, 0x2C41, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 183, 0, 0x2C42, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 183, 0, 0x2C44, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 183, 0, 0x2C45, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 183, 0, 0x2C46, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 183, 0, 0x2C47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 183, 0, 0x2C48, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_PJMP, 24, 8194, 8192), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 36), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 ibuki_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_061[80] = {
    L2(3, 0, 0, 0, 0, 199, 0, 0x2A45),
    L2(4, 0, 0, 0, 0, 233, 0, 0x2A59),
    L2(3, 0, 0, 0, 0, 234, 0, 0x2A5A),
    L2(2, 0, 0, 0, 0, 235, 0, 0x2A5B),
    L2(2, 0, 0, 0, 0, 236, 0, 0x2A5C),
    L2(2, 0, 0, 0, 0, 237, 0, 0x2A5D),
    L2(3, 0, 0, 0, 0, 238, 0, 0x2A5E),
    L2(3, 0, 0, 0, 0, 239, 0, 0x2A5F),
    L2(3, 0, 0, 0, 0, 240, 0, 0x2A60),
    L2(2, 0, 0, 0, 0, 241, 0, 0x2A61),
    L2(2, 0, 0, 0, 0, 242, 0, 0x2A62),
    L2(2, 0, 0, 0, 0, 243, 0, 0x2A63),
    L2(2, 0, 0, 0, 0, 244, 0, 0x2A64),
    L2(2, 0, 0, 0, 0, 245, 0, 0x2A65),
    L2(3, 0, 0, 0, 0, 246, 0, 0x2A66),
    L2(2, 0, 0, 0, 0, 247, 0, 0x2A67),
    L2(2, 0, 0, 0, 0, 246, 0, 0x2A67),
    L2(2, 0, 0, 0, 0, 245, 0, 0x2A67),
    CMD(CM_END, 0, 0, 16),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 ibuki_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_062[36] = {
    L2(3, 0, 0, 0, 0, 1116, 0, 0x2A68),
    L2(3, 0, 0, 0, 0, 1117, 0, 0x2A69),
    L2(3, 0, 0, 0, 0, 1118, 0, 0x2A6A),
    L2(3, 0, 0, 0, 0, 1119, 0, 0x2A6B),
    L2(4, 0, 0, 0, 0, 143, 0, 0x2A47),
    L2(4, 0, 0, 0, 0, 123, 0, 0x2A48),
    L2(4, 0, 0, 0, 0, 124, 0, 0x2A49),
    L2(4, 255, 0, 0, 0, 124, 0, 0x2A49),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 ibuki_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_063[36] = {
    L2(4, 0, 0, 0, 0, 610, 0, 0x2B0B),
    L2(1, 0, 354, 0, 0, 611, 0, 0x2B08),
    L2(1, 0, 0, 0, 0, 612, 0, 0x2B07),
    L2(2, 0, 0, 0, 0, 613, 0, 0x2B06),
    L2(4, 0, 0, 0, 0, 614, 0, 0x2B05),
    L2(4, 0, 0, 0, 0, 615, 0, 0x2A48),
    L2(4, 0, 0, 0, 0, 616, 0, 0x2A49),
    L2(250, 255, 0, 0, 0, 617, 0, 0x2A49),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 ibuki_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0CB4),
    CMD(CM_ROA, 0, 0, 0),
};

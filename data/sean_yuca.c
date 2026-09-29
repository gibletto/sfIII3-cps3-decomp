/*
 * SEAN_YUCA.C  Sean's animation scripts
 *
 * The animation scripts Sean's moves run, one table per kind of script (yuca),
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

extern const u16 sean_yuca_000[], sean_yuca_008[], sean_yuca_012[], sean_yuca_016[], sean_yuca_017[], sean_yuca_024[], sean_yuca_032[], sean_yuca_034[], sean_yuca_036[], sean_yuca_040[], sean_yuca_048[], sean_yuca_052[], sean_yuca_060[], sean_yuca_061[], sean_yuca_062[], sean_yuca_063[], sean_yuca_068[];
extern const u16 sean_yuca_000_head[];
extern const u16 sean_yuca_008_head[];
extern const u16 sean_yuca_012_head[];
extern const u16 sean_yuca_016_head[];
extern const u16 sean_yuca_017_head[];
extern const u16 sean_yuca_024_head[];
extern const u16 sean_yuca_032_head[];
extern const u16 sean_yuca_034_head[];
extern const u16 sean_yuca_036_head[];
extern const u16 sean_yuca_040_head[];
extern const u16 sean_yuca_048_head[];
extern const u16 sean_yuca_052_head[];
extern const u16 sean_yuca_060_head[];
extern const u16 sean_yuca_061_head[];
extern const u16 sean_yuca_062_head[];
extern const u16 sean_yuca_063_head[];
extern const u16 sean_yuca_068_head[];

/* yuca scripts: 91 entries */
const u16* const sean_yuca[92] = {
    sean_yuca_000,  /* 0 APPEAR JUNBI 1 */
    sean_yuca_000,  /* 1 APPEAR JUNBI 2 */
    sean_yuca_000,  /* 2 APPEAR JUNBI 3 */
    sean_yuca_000,  /* 3 APPEAR JUNBI 4 */
    sean_yuca_000,  /* 4 APPEAR JUNBI 5 */
    sean_yuca_000,  /* 5 APPEAR JUNBI 6 */
    sean_yuca_000,  /* 6 APPEAR JUNBI 7 */
    sean_yuca_000,  /* 7 APPEAR JUNBI 8 */
    sean_yuca_008,  /* 8 APPEAR 1 */
    sean_yuca_008,  /* 9 APPEAR 2 */
    sean_yuca_008,  /* 10 APPEAR 3 */
    sean_yuca_008,  /* 11 APPEAR 4 */
    sean_yuca_012,  /* 12 APPEAR 5 */
    sean_yuca_012,  /* 13 APPEAR 6 */
    sean_yuca_012,  /* 14 APPEAR 7 */
    sean_yuca_012,  /* 15 APPEAR 8 */
    sean_yuca_016,  /* 16 SP APPEAR 1 */
    sean_yuca_017,  /* 17 SP APPEAR 2 */
    sean_yuca_017,  /* 18 SP APPEAR 3 */
    sean_yuca_017,  /* 19 SP APPEAR 4 */
    sean_yuca_017,  /* 20 SP APPEAR 5 */
    sean_yuca_017,  /* 21 SP APPEAR 6 */
    sean_yuca_017,  /* 22 SP APPEAR 7 */
    sean_yuca_017,  /* 23 SP APPEAR 8 */
    sean_yuca_024,  /* 24 ZANNEN 1 */
    sean_yuca_024,  /* 25 ZANNEN 2 */
    sean_yuca_024,  /* 26 ZANNEN 3 */
    sean_yuca_024,  /* 27 ZANNEN 4 */
    sean_yuca_024,  /* 28 ZANNEN 5 */
    sean_yuca_024,  /* 29 ZANNEN 6 */
    sean_yuca_024,  /* 30 ZANNEN 7 */
    sean_yuca_024,  /* 31 ZANNEN 8 */
    sean_yuca_032,  /* 32 WIN 1 */
    sean_yuca_032,  /* 33 WIN 2 */
    sean_yuca_034,  /* 34 WIN 3 */
    sean_yuca_034,  /* 35 WIN 4 */
    sean_yuca_036,  /* 36 WIN 5 */
    sean_yuca_036,  /* 37 WIN 6 */
    sean_yuca_036,  /* 38 WIN 7 */
    sean_yuca_036,  /* 39 WIN 8 */
    sean_yuca_040,  /* 40 SP WIN 1 */
    sean_yuca_040,  /* 41 SP WIN 2 */
    sean_yuca_040,  /* 42 SP WIN 3 */
    sean_yuca_040,  /* 43 SP WIN 4 */
    sean_yuca_040,  /* 44 SP WIN 5 */
    sean_yuca_040,  /* 45 SP WIN 6 */
    sean_yuca_040,  /* 46 SP WIN 7 */
    sean_yuca_040,  /* 47 SP WIN 8 */
    sean_yuca_048,  /* 48 JUDGMENT WAIT */
    sean_yuca_048,  /* 49 JUDGMENT WAIT */
    sean_yuca_048,  /* 50 JUDGMENT WAIT */
    sean_yuca_048,  /* 51 JUDGMENT WAIT */
    sean_yuca_052,  /* 52 JUDGMENT WIN */
    sean_yuca_052,  /* 53 JUDGMENT WIN */
    sean_yuca_052,  /* 54 JUDGMENT WIN */
    sean_yuca_052,  /* 55 JUDGMENT WIN */
    sean_yuca_024,  /* 56 JUDGMENT LOSE */
    sean_yuca_024,  /* 57 JUDGMENT LOSE */
    sean_yuca_024,  /* 58 JUDGMENT LOSE */
    sean_yuca_024,  /* 59 JUDGMENT LOSE */
    sean_yuca_060,  /* 60 WAIT */
    sean_yuca_061,  /* 61 AFRICA JUMP */
    sean_yuca_062,  /* 62 AFRICA LAND */
    sean_yuca_063,  /* 63 SEAN BALL HIT */
    sean_yuca_063,  /* 64 no name */
    sean_yuca_034,  /* 65 BONUS WIN 1 */
    sean_yuca_032,  /* 66 BONUS WIN 2 */
    sean_yuca_052,  /* 67 BONUS WIN 3 */
    sean_yuca_068,  /* 68 APPEAR USE */
    sean_yuca_068,  /* 69 APPEAR USE */
    sean_yuca_068,  /* 70 APPEAR USE */
    sean_yuca_068,  /* 71 APPEAR USE */
    sean_yuca_068,  /* 72 APPEAR USE */
    sean_yuca_068,  /* 73 APPEAR USE */
    sean_yuca_068,  /* 74 APPEAR USE */
    sean_yuca_068,  /* 75 APPEAR USE */
    sean_yuca_068,  /* 76 APPEAR USE */
    sean_yuca_068,  /* 77 APPEAR USE */
    sean_yuca_068,  /* 78 APPEAR USE */
    sean_yuca_068,  /* 79 APPEAR USE */
    sean_yuca_068,  /* 80 APPEAR USE */
    sean_yuca_068,  /* 81 APPEAR USE */
    sean_yuca_068,  /* 82 APPEAR USE */
    sean_yuca_068,  /* 83 APPEAR USE */
    sean_yuca_068,  /* 84 APPEAR USE */
    sean_yuca_068,  /* 85 APPEAR USE */
    sean_yuca_068,  /* 86 APPEAR USE */
    sean_yuca_068,  /* 87 APPEAR USE */
    sean_yuca_068,  /* 88 APPEAR USE */
    sean_yuca_068,  /* 89 APPEAR USE */
    sean_yuca_068,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 sean_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_000[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 0, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 9, 0, 0, 0, 0, 0, 0x4C09),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 */
const u16 sean_yuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_008[180] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 0, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C09),
    L2(4, 0, 504, 0, 0, 17, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 17, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 18, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 18, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 19, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 20, 0, 0x4C05),
    L2(2, 0, 0, 0, 0, 20, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 21, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 22, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 22, 0, 0x4C09),
    L2(4, 0, 0, 0, 0, 22, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 23, 0, 0x4C01),
    L2(2, 0, 0, 0, 0, 23, 0, 0x4C02),
    L2(2, 0, 0, 0, 0, 24, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 24, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 24, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 24, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 24, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 24, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C0A),
    CMD(CM_EXEC, 12, 36, 0),
    L2(18, 0, 0, 0, 0, 0, 0, 0x4C0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x480A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 APPEAR 5, 13 APPEAR 6, 14 APPEAR 7, 15 APPEAR 8 */
const u16 sean_yuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_012[216] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 0, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C09),
    L2(4, 0, 493, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 0, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C00),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C03),
    L2(4, 0, 343, 0, 0, 0, 0, 0x4C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4C09),
    CMD(CM_EXEC, 12, 37, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4B70),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4B71),
    CMD(CM_PA_Y, 0, 0, 4096),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4B72),
    CMD(CM_PA_Y, 0, 0, 3584),
    L2(3, 0, 492, 0, 0, 0, 0, 0x4B75),
    CMD(CM_PA_Y, 0, 0, 1536),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4B75),
    CMD(CM_PA_Y, 0, 0, -1536),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4B76),
    CMD(CM_PA_Y, 0, 0, -2048),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B77),
    CMD(CM_PA_Y, 0, 0, -1792),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4B78),
    CMD(CM_PA_Y, 0, 0, -1792),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B79),
    CMD(CM_PA_Y, 0, 0, -2048),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4B7A),
    L2(6, 0, 273, 0, 0, 0, 0, 0x4829),
    L2(4, 0, 0, 0, 0, 0, 0, 0x482E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x482F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x482F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 sean_yuca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_016[12] = {
    L4(5, 9, 0, 0, 0, 0, 0, 0x4AD0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4, 20 SP APPEAR 5 ... */
const u16 sean_yuca_017_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_017[232] = {
    L6(5, 0, 0, 0, 0, 0, 0, 0x4AD0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AD1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4AD2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 282, 0, 0, 0, 0, 0x4AD4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AD6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(3, 0, 332, 0, 0, 0, 0, 0x4AD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    CMD(CM_EXEC, 12, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 496, 0, 0, 0, 0, 0x4AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AD9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4ADA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4856, 0, 1, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 1, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(4, 0, 274, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 sean_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_024[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B7),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B6),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 255, 0, 0, 0, 0, 0, 0x48B4),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 66 BONUS WIN 2 */
const u16 sean_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_032[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4AF0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4AF1),
    L2(3, 0, 491, 0, 0, 0, 0, 0x4AF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4AF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4AF4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x4AF5),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4AF5),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3, 35 WIN 4, 65 BONUS WIN 1 */
const u16 sean_yuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_034[72] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B21),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 489, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B30),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B31),
    CMD(CM_END, 0, 0, 16),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 */
const u16 sean_yuca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_036[328] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x4828, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x4B00, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4B01, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4B02, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x4B03, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B04, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4B05, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4870, 0, 1, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4871, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4872, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4873, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4874, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AF0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 491, 0, 0, 0, 0, 0x4AF2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AF3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AF4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x4AF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4AF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 sean_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_040[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 sean_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_048[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4802),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4803),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4804),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4805),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4806),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4807),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4808),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4809),
    L2(4, 255, 0, 0, 0, 0, 0, 0x480A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN, 55 JUDGMENT WIN ... */
const u16 sean_yuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_052[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B21),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2D),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 sean_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_060[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4802, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4803, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4804, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4805, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4806, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4807, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4808, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4809, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 255, 0, 0, 0, 0, 0, 0x480A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 sean_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_061[76] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x4829),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4840),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4841),
    L2(1, 0, 0, 0, 0, 0, 0, 0x486A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4840),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4841),
    L2(1, 0, 0, 0, 0, 0, 0, 0x486A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4842),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4843),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4844),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4845),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4846),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4847),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4848),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4849),
    L2(3, 0, 0, 0, 0, 0, 0, 0x484A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x486B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 sean_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_062[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x482A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x484B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x482F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x482F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 sean_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_063[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4999),
    L2(4, 0, 0, 0, 0, 0, 0, 0x499A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x499A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 APPEAR USE, 69 APPEAR USE, 70 APPEAR USE, 71 APPEAR USE ... */
const u16 sean_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_068[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0CB4),
    CMD(CM_ROA, 0, 0, 0),
};

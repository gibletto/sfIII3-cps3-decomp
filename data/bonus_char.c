/*
 * BONUS_CHAR.C  Bonus stage car scripts
 *
 * Scripts for the car of the car-breaking bonus stage.
 * Each *_char_table is an index of animation scripts ending in 0 followed by the scripts, in the
 * format of the fighters' tables: an effect's work takes the table as its char_table and
 * set_char_move_init starts its scripts. See charscr.h for the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 bonus_char_table_000[], bonus_char_table_001[], bonus_char_table_002[], bonus_char_table_003[], bonus_char_table_004[], bonus_char_table_005[], bonus_char_table_006[], bonus_char_table_007[], bonus_char_table_010[], bonus_char_table_011[], bonus_char_table_012[], bonus_char_table_013[], bonus_char_table_014[], bonus_char_table_015[], bonus_char_table_016[], bonus_char_table_017[], bonus_char_table_020[], bonus_char_table_021[], bonus_char_table_022[], bonus_char_table_023[], bonus_char_table_024[], bonus_char_table_025[], bonus_char_table_026[], bonus_char_table_027[], bonus_char_table_030[], bonus_char_table_031[], bonus_char_table_032[], bonus_char_table_033[], bonus_char_table_034[], bonus_char_table_035[], bonus_char_table_036[], bonus_char_table_037[], bonus_char_table_040[], bonus_char_table_041[], bonus_char_table_042[], bonus_char_table_043[], bonus_char_table_044[], bonus_char_table_045[], bonus_char_table_046[], bonus_char_table_047[], bonus_char_table_050[], bonus_char_table_051[], bonus_char_table_052[], bonus_char_table_053[], bonus_char_table_054[], bonus_char_table_055[], bonus_char_table_056[], bonus_char_table_057[], bonus_char_table_060[], bonus_char_table_061[], bonus_char_table_062[], bonus_char_table_063[], bonus_char_table_064[], bonus_char_table_065[], bonus_char_table_066[], bonus_char_table_067[], bonus_char_table_068[], bonus_char_table_069[], bonus_char_table_070[], bonus_char_table_071[], bonus_char_table_072[], bonus_char_table_076[], bonus_char_table_077[], bonus_char_table_078[], bonus_char_table_079[], bonus_char_table_080[], bonus_char_table_081[], bonus_char_table_082[], bonus_char_table_083[], bonus_char_table_084[], bonus_char_table_085[], bonus_char_table_086[], bonus_char_table_087[], bonus_char_table_088[], bonus_char_table_089[], bonus_char_table_090[], bonus_char_table_091[], bonus_char_table_092[], bonus_char_table_093[], bonus_char_table_094[], bonus_char_table_096[], bonus_char_table_097[], bonus_char_table_098[], bonus_char_table_100[], bonus_char_table_101[], bonus_char_table_102[], bonus_char_table_103[], bonus_char_table_104[], bonus_char_table_105[], bonus_char_table_106[], bonus_char_table_107[], bonus_char_table_108[], bonus_char_table_109[], bonus_char_table_110[], bonus_char_table_111[], bonus_char_table_112[], bonus_char_table_113[], bonus_char_table_114[], bonus_char_table_115[], bonus_char_table_116[], bonus_char_table_117[], bonus_char_table_118[], bonus_char_table_119[], bonus_char_table_120[], bonus_char_table_121[], bonus_char_table_122[], bonus_char_table_123[], bonus_char_table_124[], bonus_char_table_125[], bonus_char_table_126[], bonus_char_table_127[], bonus_char_table_128[], bonus_char_table_129[], bonus_char_table_130[], bonus_char_table_131[], bonus_char_table_132[], bonus_char_table_133[], bonus_char_table_134[], bonus_char_table_135[], bonus_char_table_136[], bonus_char_table_137[], bonus_char_table_138[], bonus_char_table_139[], bonus_char_table_140[], bonus_char_table_141[], bonus_char_table_142[], bonus_char_table_143[], bonus_char_table_144[], bonus_char_table_008[];
extern const u16 bonus_char_table_000_head[];
extern const u16 bonus_char_table_001_head[];
extern const u16 bonus_char_table_002_head[];
extern const u16 bonus_char_table_003_head[];
extern const u16 bonus_char_table_004_head[];
extern const u16 bonus_char_table_005_head[];
extern const u16 bonus_char_table_006_head[];
extern const u16 bonus_char_table_007_head[];
extern const u16 bonus_char_table_010_head[];
extern const u16 bonus_char_table_011_head[];
extern const u16 bonus_char_table_012_head[];
extern const u16 bonus_char_table_013_head[];
extern const u16 bonus_char_table_014_head[];
extern const u16 bonus_char_table_015_head[];
extern const u16 bonus_char_table_016_head[];
extern const u16 bonus_char_table_017_head[];
extern const u16 bonus_char_table_020_head[];
extern const u16 bonus_char_table_021_head[];
extern const u16 bonus_char_table_022_head[];
extern const u16 bonus_char_table_023_head[];
extern const u16 bonus_char_table_024_head[];
extern const u16 bonus_char_table_025_head[];
extern const u16 bonus_char_table_026_head[];
extern const u16 bonus_char_table_027_head[];
extern const u16 bonus_char_table_030_head[];
extern const u16 bonus_char_table_031_head[];
extern const u16 bonus_char_table_032_head[];
extern const u16 bonus_char_table_033_head[];
extern const u16 bonus_char_table_034_head[];
extern const u16 bonus_char_table_035_head[];
extern const u16 bonus_char_table_036_head[];
extern const u16 bonus_char_table_037_head[];
extern const u16 bonus_char_table_040_head[];
extern const u16 bonus_char_table_041_head[];
extern const u16 bonus_char_table_042_head[];
extern const u16 bonus_char_table_043_head[];
extern const u16 bonus_char_table_044_head[];
extern const u16 bonus_char_table_045_head[];
extern const u16 bonus_char_table_046_head[];
extern const u16 bonus_char_table_047_head[];
extern const u16 bonus_char_table_050_head[];
extern const u16 bonus_char_table_051_head[];
extern const u16 bonus_char_table_052_head[];
extern const u16 bonus_char_table_053_head[];
extern const u16 bonus_char_table_054_head[];
extern const u16 bonus_char_table_055_head[];
extern const u16 bonus_char_table_056_head[];
extern const u16 bonus_char_table_057_head[];
extern const u16 bonus_char_table_060_head[];
extern const u16 bonus_char_table_061_head[];
extern const u16 bonus_char_table_062_head[];
extern const u16 bonus_char_table_063_head[];
extern const u16 bonus_char_table_064_head[];
extern const u16 bonus_char_table_065_head[];
extern const u16 bonus_char_table_066_head[];
extern const u16 bonus_char_table_067_head[];
extern const u16 bonus_char_table_068_head[];
extern const u16 bonus_char_table_069_head[];
extern const u16 bonus_char_table_070_head[];
extern const u16 bonus_char_table_071_head[];
extern const u16 bonus_char_table_072_head[];
extern const u16 bonus_char_table_076_head[];
extern const u16 bonus_char_table_077_head[];
extern const u16 bonus_char_table_078_head[];
extern const u16 bonus_char_table_079_head[];
extern const u16 bonus_char_table_080_head[];
extern const u16 bonus_char_table_081_head[];
extern const u16 bonus_char_table_082_head[];
extern const u16 bonus_char_table_083_head[];
extern const u16 bonus_char_table_084_head[];
extern const u16 bonus_char_table_085_head[];
extern const u16 bonus_char_table_086_head[];
extern const u16 bonus_char_table_087_head[];
extern const u16 bonus_char_table_088_head[];
extern const u16 bonus_char_table_089_head[];
extern const u16 bonus_char_table_090_head[];
extern const u16 bonus_char_table_091_head[];
extern const u16 bonus_char_table_092_head[];
extern const u16 bonus_char_table_093_head[];
extern const u16 bonus_char_table_094_head[];
extern const u16 bonus_char_table_096_head[];
extern const u16 bonus_char_table_097_head[];
extern const u16 bonus_char_table_098_head[];
extern const u16 bonus_char_table_100_head[];
extern const u16 bonus_char_table_101_head[];
extern const u16 bonus_char_table_102_head[];
extern const u16 bonus_char_table_103_head[];
extern const u16 bonus_char_table_104_head[];
extern const u16 bonus_char_table_105_head[];
extern const u16 bonus_char_table_106_head[];
extern const u16 bonus_char_table_107_head[];
extern const u16 bonus_char_table_108_head[];
extern const u16 bonus_char_table_109_head[];
extern const u16 bonus_char_table_110_head[];
extern const u16 bonus_char_table_111_head[];
extern const u16 bonus_char_table_112_head[];
extern const u16 bonus_char_table_113_head[];
extern const u16 bonus_char_table_114_head[];
extern const u16 bonus_char_table_115_head[];
extern const u16 bonus_char_table_116_head[];
extern const u16 bonus_char_table_117_head[];
extern const u16 bonus_char_table_118_head[];
extern const u16 bonus_char_table_119_head[];
extern const u16 bonus_char_table_120_head[];
extern const u16 bonus_char_table_121_head[];
extern const u16 bonus_char_table_122_head[];
extern const u16 bonus_char_table_123_head[];
extern const u16 bonus_char_table_124_head[];
extern const u16 bonus_char_table_125_head[];
extern const u16 bonus_char_table_126_head[];
extern const u16 bonus_char_table_127_head[];
extern const u16 bonus_char_table_128_head[];
extern const u16 bonus_char_table_129_head[];
extern const u16 bonus_char_table_130_head[];
extern const u16 bonus_char_table_131_head[];
extern const u16 bonus_char_table_132_head[];
extern const u16 bonus_char_table_133_head[];
extern const u16 bonus_char_table_134_head[];
extern const u16 bonus_char_table_135_head[];
extern const u16 bonus_char_table_136_head[];
extern const u16 bonus_char_table_137_head[];
extern const u16 bonus_char_table_138_head[];
extern const u16 bonus_char_table_139_head[];
extern const u16 bonus_char_table_140_head[];
extern const u16 bonus_char_table_141_head[];
extern const u16 bonus_char_table_142_head[];
extern const u16 bonus_char_table_143_head[];
extern const u16 bonus_char_table_144_head[];
extern const u16 bonus_char_table_008_head[];

/* bonus_char_table scripts: 145 entries */
const u16* const bonus_char_table[146] = {
    bonus_char_table_000, bonus_char_table_001, bonus_char_table_002, bonus_char_table_003, bonus_char_table_004, bonus_char_table_005,
    bonus_char_table_006, bonus_char_table_007, bonus_char_table_008, bonus_char_table_008, bonus_char_table_010, bonus_char_table_011,
    bonus_char_table_012, bonus_char_table_013, bonus_char_table_014, bonus_char_table_015, bonus_char_table_016, bonus_char_table_017,
    bonus_char_table_008, bonus_char_table_008, bonus_char_table_020, bonus_char_table_021, bonus_char_table_022, bonus_char_table_023,
    bonus_char_table_024, bonus_char_table_025, bonus_char_table_026, bonus_char_table_027, bonus_char_table_008, bonus_char_table_008,
    bonus_char_table_030, bonus_char_table_031, bonus_char_table_032, bonus_char_table_033, bonus_char_table_034, bonus_char_table_035,
    bonus_char_table_036, bonus_char_table_037, bonus_char_table_008, bonus_char_table_008, bonus_char_table_040, bonus_char_table_041,
    bonus_char_table_042, bonus_char_table_043, bonus_char_table_044, bonus_char_table_045, bonus_char_table_046, bonus_char_table_047,
    bonus_char_table_008, bonus_char_table_008, bonus_char_table_050, bonus_char_table_051, bonus_char_table_052, bonus_char_table_053,
    bonus_char_table_054, bonus_char_table_055, bonus_char_table_056, bonus_char_table_057, bonus_char_table_008, bonus_char_table_008,
    bonus_char_table_060, bonus_char_table_061, bonus_char_table_062, bonus_char_table_063, bonus_char_table_064, bonus_char_table_065,
    bonus_char_table_066, bonus_char_table_067, bonus_char_table_068, bonus_char_table_069, bonus_char_table_070, bonus_char_table_071,
    bonus_char_table_072, bonus_char_table_008, bonus_char_table_008, bonus_char_table_008, bonus_char_table_076, bonus_char_table_077,
    bonus_char_table_078, bonus_char_table_079, bonus_char_table_080, bonus_char_table_081, bonus_char_table_082, bonus_char_table_083,
    bonus_char_table_084, bonus_char_table_085, bonus_char_table_086, bonus_char_table_087, bonus_char_table_088, bonus_char_table_089,
    bonus_char_table_090, bonus_char_table_091, bonus_char_table_092, bonus_char_table_093, bonus_char_table_094, bonus_char_table_094,
    bonus_char_table_096, bonus_char_table_097, bonus_char_table_098, bonus_char_table_098, bonus_char_table_100, bonus_char_table_101,
    bonus_char_table_102, bonus_char_table_103, bonus_char_table_104, bonus_char_table_105, bonus_char_table_106, bonus_char_table_107,
    bonus_char_table_108, bonus_char_table_109, bonus_char_table_110, bonus_char_table_111, bonus_char_table_112, bonus_char_table_113,
    bonus_char_table_114, bonus_char_table_115, bonus_char_table_116, bonus_char_table_117, bonus_char_table_118, bonus_char_table_119,
    bonus_char_table_120, bonus_char_table_121, bonus_char_table_122, bonus_char_table_123, bonus_char_table_124, bonus_char_table_125,
    bonus_char_table_126, bonus_char_table_127, bonus_char_table_128, bonus_char_table_129, bonus_char_table_130, bonus_char_table_131,
    bonus_char_table_132, bonus_char_table_133, bonus_char_table_134, bonus_char_table_135, bonus_char_table_136, bonus_char_table_137,
    bonus_char_table_138, bonus_char_table_139, bonus_char_table_140, bonus_char_table_141, bonus_char_table_142, bonus_char_table_143,
    bonus_char_table_144,
    0
};

const u16 bonus_char_table_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_000[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB038, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB039, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB03F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB040, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB041, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB042, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB043, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB044, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB045, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB046, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB047, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB048, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB049, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_001[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB04F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB050, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB051, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB052, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB053, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB054, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB055, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB056, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB057, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB058, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB059, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05B, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_002[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB05F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB060, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB061, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB062, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB063, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB064, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB065, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB066, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB067, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB068, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB069, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06D, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_003_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_003[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB06F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB070, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB071, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB072, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB073, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB074, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB075, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB076, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB077, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB078, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB079, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB07F, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_004[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB080, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB081, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB082, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB083, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB084, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB085, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB086, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB087, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB088, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB089, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB08F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB090, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB091, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_005_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_005[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB092, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB093, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB094, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB095, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB096, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB097, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB098, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB099, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09A, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09B, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09C, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09D, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09E, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB09F, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A0, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A1, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A2, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A3, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_006[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A4, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A5, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A6, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A7, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A8, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0A9, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AA, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AB, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AC, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AD, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AE, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0AF, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B0, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B1, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B2, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B3, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B4, 0, 53, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B5, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_007[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B6, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B7, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B8, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0B9, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BA, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BB, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BC, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BD, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BE, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0BF, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C0, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C1, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C2, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C3, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C4, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C5, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C6, 0, 58, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C7, 0, 58, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_010[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xADF8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADF9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFD, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xADFF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE00, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE01, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE02, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE03, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE04, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE05, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE06, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE07, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE08, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE09, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_011[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE0F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE10, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE11, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE12, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE14, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE15, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE16, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE17, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE18, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE19, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1B, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_012[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE1F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE20, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE21, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE22, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE23, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE24, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE25, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE26, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE27, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE28, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE29, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_013[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE2F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE30, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE31, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE32, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE33, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE34, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE35, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE36, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE37, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE38, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE39, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE3F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_014[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE40, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE41, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE42, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE43, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE44, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE45, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE46, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE47, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE48, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE49, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE4F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE50, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE51, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_015[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE52, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE53, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE54, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE55, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE56, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE57, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE58, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE59, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE5F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE60, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE61, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE62, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE63, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_016[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE64, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE65, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE66, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE67, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE68, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE69, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE6F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE70, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE71, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE72, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE73, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE74, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE75, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_017[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE76, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE77, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE78, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE79, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE7F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE80, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE81, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE82, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE83, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE84, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE85, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE86, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE87, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_020[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE88, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE89, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE8F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE90, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE91, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE92, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE93, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE94, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE95, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE96, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE97, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE98, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE99, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_021_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_021[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAE9F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA1, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA3, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEA9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAB, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_022[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAD, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEAF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB1, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB3, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEB9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBD, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_023[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEBF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC1, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC3, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEC9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECD, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAECF, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_024[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED1, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED3, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAED9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDD, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEDF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE1, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_025[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE3, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEE9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEEA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEEB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEEC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEED, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEEE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEEF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF0, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF1, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_026[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF4, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF5, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF7, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEF9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFB, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFC, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFD, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAEFF, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF00, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF01, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF02, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF03, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF04, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF05, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_027[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF06, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF07, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF08, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF09, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0B, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF0F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF10, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF11, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF12, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF14, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF15, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF16, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF17, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_030[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF18, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF19, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF1F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF20, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF21, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF22, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF23, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF24, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF25, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF26, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF27, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF28, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF29, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_031[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF2F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF30, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF31, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF32, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF33, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF34, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF35, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF36, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF37, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF38, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF39, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3B, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_032[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF3F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF40, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF41, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF42, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF43, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF44, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF45, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF46, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF47, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF48, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF49, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4D, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_033[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF4F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF50, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF51, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF52, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF53, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF54, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF55, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF56, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF57, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF58, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF59, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF5F, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_034[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF60, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF61, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF62, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF63, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF64, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF65, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF66, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF67, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF68, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF69, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF6F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF70, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF71, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_035[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF72, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF73, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF74, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF75, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF76, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF77, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF78, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF79, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF7F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF80, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF81, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF82, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF83, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_036[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF84, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF85, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF86, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF87, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF88, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF89, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF8F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF90, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF91, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF92, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF93, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF94, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF95, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_037[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF96, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF97, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF98, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF99, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9A, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9B, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9C, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9D, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9E, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAF9F, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA0, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA1, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA2, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA3, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA4, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA5, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA6, 0, 54, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA7, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_040[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFA9, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAB, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAD, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFAF, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB0, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB1, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB2, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB3, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB4, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB5, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB6, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB7, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFB9, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_041[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBB, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBD, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFBF, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC0, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC1, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC2, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC3, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC4, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC5, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC6, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC7, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFC9, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCB, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_042[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCD, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFCF, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD0, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD1, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD2, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD3, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD4, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD5, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD6, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD7, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFD9, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDB, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDD, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_043[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFDF, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE0, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE1, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE2, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE3, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE4, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE5, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE6, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE7, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFE9, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFEA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFEB, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFEC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFED, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFEE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFEF, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_044[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF0, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF1, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF2, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF3, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF4, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF5, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF6, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF7, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF8, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFF9, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFA, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFB, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFC, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFD, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFE, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xAFFF, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB000, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB001, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_045[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB002, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB003, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB004, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB005, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB006, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB007, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB008, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB009, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00A, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00B, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00C, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00D, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00E, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB00F, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB010, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB011, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB012, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB013, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_046[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB014, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB015, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB016, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB017, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB018, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB019, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01A, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01B, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01C, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01D, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01E, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB01F, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB020, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB021, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB022, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB023, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB024, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB025, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_047[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB026, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB027, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB028, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB029, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02A, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02B, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02C, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02D, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02E, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB02F, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB030, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB031, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB032, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB033, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB034, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB035, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB036, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_050[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C8, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0C9, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CA, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CB, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CC, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CD, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CE, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0CF, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D0, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D1, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D2, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D3, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D4, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D5, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D6, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D7, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D8, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0D9, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_051_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_051[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DA, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DB, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DC, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DD, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DE, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0DF, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E0, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E1, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E2, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E3, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E4, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E5, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E6, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E7, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E8, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0E9, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0EA, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0EB, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_052_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_052[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0EC, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0ED, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0EE, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0EF, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F0, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F1, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F2, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F3, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F4, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F5, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F6, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F7, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F8, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0F9, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FA, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FB, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FC, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FD, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_053[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FE, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB0FF, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB100, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB101, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB102, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB103, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB104, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB105, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB106, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB107, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB108, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB109, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10B, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10C, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10D, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10E, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB10F, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_054_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_054[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB110, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB111, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB112, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB113, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB114, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB115, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB116, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB117, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB118, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB119, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11B, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11C, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11D, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11E, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB11F, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB120, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB121, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_055[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB122, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB123, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB124, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB125, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB126, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB127, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB128, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB129, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12B, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12C, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12D, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12E, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB12F, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB130, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB131, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB132, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB133, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_056_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_056[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB134, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB135, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB136, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB137, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB138, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB139, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13B, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13C, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13D, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13E, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB13F, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB140, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB141, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB142, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB143, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB144, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB145, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_057_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_057[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB146, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB147, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB148, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB149, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14B, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14C, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14D, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14E, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB14F, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB150, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB151, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB152, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB153, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB154, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB155, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB156, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB157, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_060[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB158, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB159, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15A, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15B, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15C, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15D, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15E, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB15F, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB160, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB161, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB162, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB163, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB164, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB165, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB166, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB167, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB168, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB169, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_061_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_061[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16A, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16B, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16C, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16D, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16E, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB16F, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB170, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB171, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB172, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB173, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB174, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB175, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB176, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB177, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB178, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB179, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17A, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17B, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_062[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17C, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17D, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17E, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB17F, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB180, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB181, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB182, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB183, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB184, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB185, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB186, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB187, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB188, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB189, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18A, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18B, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18C, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18D, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_063[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18E, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB18F, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB190, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB191, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB192, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB193, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB194, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB195, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB196, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB197, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB198, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB199, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19A, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19B, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19C, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19D, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19E, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB19F, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_064[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A0, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A1, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A2, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A3, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A4, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A5, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A6, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A7, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A8, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1A9, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AA, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AB, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AC, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AD, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AE, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1AF, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B0, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B1, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_065_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_065[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B2, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B3, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B4, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B5, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B6, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B7, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B8, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1B9, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BA, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BB, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BC, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BD, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BE, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1BF, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C0, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C1, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C2, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C3, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_066_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_066[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C4, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C5, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C6, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C7, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C8, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1C9, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CA, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CB, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CC, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CD, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CE, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1CF, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D0, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D1, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D2, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D3, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D4, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D5, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_067_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_067[148] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D6, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D7, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D8, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1D9, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DA, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DB, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DC, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DD, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DE, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1DF, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E0, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E1, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E2, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E3, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E4, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E5, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E6, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB1E7, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_068[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xB212),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_069[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xB213),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_070[60] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0xB200, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB202, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB203, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB205, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB206, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB207, 0, 59, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0xB207, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_071_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_071[108] = {
    L4(250, 0, 995, 0, 0, 0, 0, 0xB1F8, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 271, 0, 0, 0, 0, 0xB1F9, 0, 0, 0, 0, 0, 39, 16),
    L4(2, 0, 0, 0, 0, 0, 0, 0xB1FA, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0xB1FB, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xB1FC, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0xB1FD, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0xB1FE, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xB1FE, 0, 0, 0, 0, 0, 32, 7),
    L4(1, 0, 0, 0, 0, 0, 0, 0xB1FE, 0, 0, 0, 0, 0, 32, 7),
    L4(1, 0, 0, 0, 0, 0, 0, 0xB1FE, 0, 0, 0, 0, 0, 32, 8),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 271, 0, 0, 0, 0, 0xB1FF, 0, 0, 0, 0, 0, 39, 8),
    L4(250, 255, 0, 0, 0, 0, 0, 0xB200, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_072_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_072[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB210, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_076_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_076[68] = {
    L2(1, 8, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 9, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 10, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 10, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 9, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 11, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 11, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 8, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 8, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 8, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 11, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 11, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0009),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_077[44] = {
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 3, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 3, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 6, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 7, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_078_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_078[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0009),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_079_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_079[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0009),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_080_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_080[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0008),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_081_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_081[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x000A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_082_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_082[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0004),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0005),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0006),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x000A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_083_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_083[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x000E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0008),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_084_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_084[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0003),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0002),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0002),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0003),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0004),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0005),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0006),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(251, 255, 0, 0, 0, 0, 0, 0x0009),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_085_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_085[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x000F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0010),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0011),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0010),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0006),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0005),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0006),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(1, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x000A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0009),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0009),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_086_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_086[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_087[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_088_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_088[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_089[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_090[116] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 3, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 3, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 3, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 2, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 1, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_091_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_091[116] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 6, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 6, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 5, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 4, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0012),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_092_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_092[140] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 271, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 39, 16),
    L4(3, 1, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0xB210, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_Y, 0, 0, 256), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_Y, 0, 0, -256), 0, 0, 0, 0,
    L4(4, 2, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 271, 0, 0, 0, 0, 0xB210, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    L4(20, 0, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0xB211, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_093_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_093[116] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_094_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_094[180] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_096_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_096[52] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_097_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_097[116] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_098_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_098[180] = {
    CMD(CM_RJA, 0, 92, 6), 0, 0, 0, 0,
    L4(6, 0, 336, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20B, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20A, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB209, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB208, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20F, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0xB20E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0xB20D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_100_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_100[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xB214),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB215),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB216),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB217),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB218),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB219),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_101_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_101[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21C),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21D),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB220),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB221),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB222),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB223),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_102_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_102[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xB223),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB222),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB221),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB220),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21D),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB21C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_103_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_103[36] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xB224),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB225),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB226),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB227),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB228),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB229),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22A),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_104_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_104[36] = {
    L2(7, 0, 0, 0, 1, 0, 0, 0xB224),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB225),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB226),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB227),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB228),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB229),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22A),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_105_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_105[36] = {
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22C),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22D),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22E),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB22F),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB230),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB231),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB232),
    L2(7, 0, 0, 0, 1, 0, 0, 0xB233),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_106_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_106[36] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22C),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22D),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22E),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB22F),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB230),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB231),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB232),
    L2(7, 0, 0, 0, 0, 0, 0, 0xB233),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_107_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_107[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xB234),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB235),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB236),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB237),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB238),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB239),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB23A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB23B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_108_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_108[120] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xB23C),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB23C),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB23D),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB23D),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB23E),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 996, 0, 0, 0, 0, 0xB23E),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB23F),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB23F),
    CMD(CM_NEX, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB23F),
    L2(5, 0, 0, 0, 0, 0, 0, 0xB240),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB241),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB242),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_X, 0, -256, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB243),
    CMD(CM_PA_X, 0, 256, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB243),
    CMD(CM_NEX, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB243),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB243),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_109_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_109[96] = {
    CMD(CM_RJA, 0, 109, 3),
    L2(250, 0, 0, 0, 0, 0, 0, 0xB244),
    L2(1, 0, 996, 0, 0, 0, 0, 0xB245),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB245),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB245),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB245),
    L2(5, 0, 0, 0, 0, 0, 0, 0xB246),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB247),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB248),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB249),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB24A),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB24B),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB24B),
    CMD(CM_NEX, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB24B),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB24B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_110_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_110[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB24C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB24D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB24E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_111_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_111[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB252),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB253),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB254),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_112_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_112[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB24F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB250),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB251),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_113_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_113[20] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0xB498),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB499),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB49A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB49B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_114_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_114[20] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0xB49B),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB49A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB499),
    L2(10, 0, 0, 0, 0, 0, 0, 0xB498),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_115_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_115[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_116_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_116[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49F),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB49C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_117_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_117[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB260),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB261),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB262),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB263),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB264),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB265),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB265),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_118_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_118[28] = {
    CMD(CM_RJA, 0, 118, 5),
    L2(20, 0, 0, 0, 0, 0, 0, 0xB266),
    L2(12, 0, 0, 0, 0, 0, 0, 0xB267),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB268),
    L2(250, 0, 996, 0, 0, 0, 0, 0xB269),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB269),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_119_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_119[44] = {
    CMD(CM_RJA, 0, 119, 6),
    L2(12, 0, 0, 0, 0, 0, 0, 0xB26D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB26C),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB26B),
    L2(250, 0, 0, 0, 0, 0, 0, 0xB26A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB26B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB26D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB26C),
    L2(20, 0, 0, 0, 0, 0, 0, 0xB26D),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB26D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_120_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_120[56] = {
    CMD(CM_RJA, 0, 120, 6),
    L2(12, 0, 0, 0, 0, 0, 0, 0xB26E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xB26F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xB270),
    L2(250, 0, 0, 0, 0, 0, 0, 0xB271),
    L2(1, 0, 996, 0, 0, 0, 0, 0xB271),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB26F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB26E),
    L2(3, 0, 996, 0, 0, 0, 0, 0xB270),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB26E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xB26F),
    L2(20, 0, 0, 0, 0, 0, 0, 0xB26E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB26E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_121_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_121[52] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xB273),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB274),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB275),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB273),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB274),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB275),
    L2(20, 0, 0, 0, 0, 0, 0, 0xB274),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB279),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB27C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_122_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_122[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB276),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB277),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB278),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB276),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB277),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB278),
    L2(20, 0, 0, 0, 0, 0, 0, 0xB277),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB279),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB27C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_123_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_123[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB298),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB299),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29D),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB29D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_124_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_124[56] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xB281),
    L2(5, 0, 0, 0, 0, 0, 0, 0xB282),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB283),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB284),
    L2(1, 0, 996, 0, 0, 0, 0, 0xB285),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB285),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB285),
    CMD(CM_NEX, 0, 0, 0),
    L2(40, 0, 0, 0, 0, 0, 0, 0xB285),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB285),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_125_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_125[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB27F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB280),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_126_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_126[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB286),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB287),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB288),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB289),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28B),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB28B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_127_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_127[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB28F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_128_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_128[80] = {
    CMD(CM_RJA, 0, 128, 13),
    L2(4, 0, 995, 0, 0, 0, 0, 0xB29B),
    CMD(CM_PA_Y, 0, 0, 12288),
    L2(4, 1, 0, 0, 0, 0, 0, 0xB290),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB291),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB292),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB293),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB294),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB295),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB296),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB297),
    CMD(CM_IXBW, 0, 0, 8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB298),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB299),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29D),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB29D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_129_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_129[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB29F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_130_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_130[72] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2A9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2AF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2B1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB2B2),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB2B2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_131_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_131[20] = {
    CMD(CM_RJA, 0, 131, 3),
    L2(250, 0, 0, 0, 1, 0, 0, 0xB267),
    L2(250, 0, 996, 0, 1, 0, 0, 0xB269),
    L2(250, 255, 0, 0, 1, 0, 0, 0xB269),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_132_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_132[16] = {
    L2(6, 0, 0, 0, 1, 0, 0, 0xB4A0),
    L2(6, 0, 0, 0, 1, 0, 0, 0xB4A1),
    L2(6, 0, 0, 0, 1, 0, 0, 0xB4A2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_133_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_133[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_134_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_134[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_135_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_135[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_136_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_136[16] = {
    L2(5, 0, 0, 0, 1, 0, 0, 0xB4A3),
    L2(5, 0, 0, 0, 1, 0, 0, 0xB4A4),
    L2(5, 0, 0, 0, 1, 0, 0, 0xB4A5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_137_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_137[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_138_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_138[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_139_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_139[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_140_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_140[16] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xB4A6),
    L2(4, 0, 0, 0, 1, 0, 0, 0xB4A7),
    L2(4, 0, 0, 0, 1, 0, 0, 0xB4A8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_141_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_141[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_142_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_142[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_143_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_143[8] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0xB4A8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_144_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_144[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB255),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB256),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB257),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB258),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB259),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB25B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bonus_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bonus_char_table_008[8] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1AF0),
    CMD(CM_ROA, 0, 0, 0),
};

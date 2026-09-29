/*
 * IBUKI_CHAR.C  Ibuki's animation scripts and sprite part tables
 *
 * The animation scripts Ibuki's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
 * each an index of scripts ending in 0 followed by the scripts. set_char_base_data (CHARID)
 * installs the tables as char_table[]; set_char_move_init2 starts script char_table[kind][index]
 * and char_move steps it: a frame line shows sprite `number` for `ctr` frames with its sound, hit
 * boxes (hit_ix into the hit_ix_table), attack (att into the catt_table) and effect; a command
 * line (CM_ codes) jumps, loops, tests and sets. See charscr.h for the line layouts.
 *
 * olc_ix_table and overlap_char_tbl place the extra sprite parts a frame overlays (cg_olc_ix);
 * rival_catch_tbl positions a caught opponent for each throw frame (cg_rival).
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 ibuki_nmca_000[], ibuki_nmca_001[], ibuki_nmca_002[], ibuki_nmca_003[], ibuki_nmca_004[], ibuki_nmca_005[], ibuki_nmca_006[], ibuki_nmca_007[], ibuki_nmca_008[], ibuki_nmca_011[], ibuki_nmca_012[], ibuki_nmca_013[], ibuki_nmca_014[], ibuki_nmca_015[], ibuki_nmca_016[], ibuki_nmca_017[], ibuki_nmca_020[], ibuki_nmca_021[], ibuki_nmca_022[], ibuki_nmca_023[], ibuki_nmca_024[], ibuki_nmca_026[], ibuki_nmca_027[], ibuki_nmca_029[], ibuki_nmca_030[], ibuki_nmca_031[], ibuki_nmca_032[], ibuki_nmca_038[], ibuki_nmca_040[], ibuki_nmca_041[], ibuki_nmca_043[], ibuki_nmca_044[], ibuki_nmca_045[], ibuki_nmca_046[], ibuki_nmca_047[], ibuki_nmca_048[], ibuki_nmca_049[], ibuki_nmca_050[];
extern const u16 ibuki_nmca_000_head[];
extern const u16 ibuki_nmca_001_head[];
extern const u16 ibuki_nmca_002_head[];
extern const u16 ibuki_nmca_003_head[];
extern const u16 ibuki_nmca_004_head[];
extern const u16 ibuki_nmca_005_head[];
extern const u16 ibuki_nmca_006_head[];
extern const u16 ibuki_nmca_007_head[];
extern const u16 ibuki_nmca_008_head[];
extern const u16 ibuki_nmca_011_head[];
extern const u16 ibuki_nmca_012_head[];
extern const u16 ibuki_nmca_013_head[];
extern const u16 ibuki_nmca_014_head[];
extern const u16 ibuki_nmca_015_head[];
extern const u16 ibuki_nmca_016_head[];
extern const u16 ibuki_nmca_017_head[];
extern const u16 ibuki_nmca_020_head[];
extern const u16 ibuki_nmca_021_head[];
extern const u16 ibuki_nmca_022_head[];
extern const u16 ibuki_nmca_023_head[];
extern const u16 ibuki_nmca_024_head[];
extern const u16 ibuki_nmca_026_head[];
extern const u16 ibuki_nmca_027_head[];
extern const u16 ibuki_nmca_029_head[];
extern const u16 ibuki_nmca_030_head[];
extern const u16 ibuki_nmca_031_head[];
extern const u16 ibuki_nmca_032_head[];
extern const u16 ibuki_nmca_038_head[];
extern const u16 ibuki_nmca_040_head[];
extern const u16 ibuki_nmca_041_head[];
extern const u16 ibuki_nmca_043_head[];
extern const u16 ibuki_nmca_044_head[];
extern const u16 ibuki_nmca_045_head[];
extern const u16 ibuki_nmca_046_head[];
extern const u16 ibuki_nmca_047_head[];
extern const u16 ibuki_nmca_048_head[];
extern const u16 ibuki_nmca_049_head[];
extern const u16 ibuki_nmca_050_head[];
extern const u16 ibuki_dmca_000[], ibuki_dmca_001[], ibuki_dmca_002[], ibuki_dmca_003[], ibuki_dmca_004[], ibuki_dmca_006[], ibuki_dmca_008[], ibuki_dmca_009[], ibuki_dmca_010[], ibuki_dmca_018[], ibuki_dmca_019[], ibuki_dmca_014[], ibuki_dmca_015[], ibuki_dmca_022[], ibuki_dmca_026[], ibuki_dmca_034[], ibuki_dmca_036[], ibuki_dmca_024[], ibuki_dmca_025[], ibuki_dmca_030[], ibuki_dmca_048[], ibuki_dmca_049[], ibuki_dmca_050[], ibuki_dmca_052[], ibuki_dmca_060[], ibuki_dmca_064[], ibuki_dmca_065[], ibuki_dmca_066[], ibuki_dmca_067[], ibuki_dmca_068[], ibuki_dmca_070[], ibuki_dmca_071[], ibuki_dmca_072[], ibuki_dmca_073[], ibuki_dmca_074[], ibuki_dmca_075[], ibuki_dmca_076[], ibuki_dmca_078[], ibuki_dmca_079[], ibuki_dmca_080[], ibuki_dmca_082[], ibuki_dmca_083[], ibuki_dmca_084[], ibuki_dmca_090[], ibuki_dmca_091[], ibuki_dmca_096[], ibuki_dmca_097[];
extern const u16 ibuki_dmca_000_head[];
extern const u16 ibuki_dmca_001_head[];
extern const u16 ibuki_dmca_002_head[];
extern const u16 ibuki_dmca_003_head[];
extern const u16 ibuki_dmca_004_head[];
extern const u16 ibuki_dmca_006_head[];
extern const u16 ibuki_dmca_008_head[];
extern const u16 ibuki_dmca_009_head[];
extern const u16 ibuki_dmca_010_head[];
extern const u16 ibuki_dmca_018_head[];
extern const u16 ibuki_dmca_019_head[];
extern const u16 ibuki_dmca_014_head[];
extern const u16 ibuki_dmca_015_head[];
extern const u16 ibuki_dmca_022_head[];
extern const u16 ibuki_dmca_026_head[];
extern const u16 ibuki_dmca_034_head[];
extern const u16 ibuki_dmca_036_head[];
extern const u16 ibuki_dmca_024_head[];
extern const u16 ibuki_dmca_025_head[];
extern const u16 ibuki_dmca_030_head[];
extern const u16 ibuki_dmca_048_head[];
extern const u16 ibuki_dmca_049_head[];
extern const u16 ibuki_dmca_050_head[];
extern const u16 ibuki_dmca_052_head[];
extern const u16 ibuki_dmca_060_head[];
extern const u16 ibuki_dmca_064_head[];
extern const u16 ibuki_dmca_065_head[];
extern const u16 ibuki_dmca_066_head[];
extern const u16 ibuki_dmca_067_head[];
extern const u16 ibuki_dmca_068_head[];
extern const u16 ibuki_dmca_070_head[];
extern const u16 ibuki_dmca_071_head[];
extern const u16 ibuki_dmca_072_head[];
extern const u16 ibuki_dmca_073_head[];
extern const u16 ibuki_dmca_074_head[];
extern const u16 ibuki_dmca_075_head[];
extern const u16 ibuki_dmca_076_head[];
extern const u16 ibuki_dmca_078_head[];
extern const u16 ibuki_dmca_079_head[];
extern const u16 ibuki_dmca_080_head[];
extern const u16 ibuki_dmca_082_head[];
extern const u16 ibuki_dmca_083_head[];
extern const u16 ibuki_dmca_084_head[];
extern const u16 ibuki_dmca_090_head[];
extern const u16 ibuki_dmca_091_head[];
extern const u16 ibuki_dmca_096_head[];
extern const u16 ibuki_dmca_097_head[];
extern const u16 ibuki_btca_000[], ibuki_btca_001[], ibuki_btca_002[], ibuki_btca_003[], ibuki_btca_004[], ibuki_btca_005[], ibuki_btca_006[], ibuki_btca_007[], ibuki_btca_008[], ibuki_btca_009[], ibuki_btca_010[], ibuki_btca_011[], ibuki_btca_012[], ibuki_btca_013[], ibuki_btca_014[], ibuki_btca_015[], ibuki_btca_016[], ibuki_btca_017[], ibuki_btca_018[], ibuki_btca_019[], ibuki_btca_020[], ibuki_btca_021[], ibuki_btca_022[], ibuki_btca_023[], ibuki_btca_025[], ibuki_btca_026[], ibuki_btca_027[], ibuki_btca_028[], ibuki_btca_029[], ibuki_btca_030[], ibuki_btca_031[], ibuki_btca_032[], ibuki_btca_033[], ibuki_btca_034[], ibuki_btca_035[];
extern const u16 ibuki_btca_000_head[];
extern const u16 ibuki_btca_001_head[];
extern const u16 ibuki_btca_002_head[];
extern const u16 ibuki_btca_003_head[];
extern const u16 ibuki_btca_004_head[];
extern const u16 ibuki_btca_005_head[];
extern const u16 ibuki_btca_006_head[];
extern const u16 ibuki_btca_007_head[];
extern const u16 ibuki_btca_008_head[];
extern const u16 ibuki_btca_009_head[];
extern const u16 ibuki_btca_010_head[];
extern const u16 ibuki_btca_011_head[];
extern const u16 ibuki_btca_012_head[];
extern const u16 ibuki_btca_013_head[];
extern const u16 ibuki_btca_014_head[];
extern const u16 ibuki_btca_015_head[];
extern const u16 ibuki_btca_016_head[];
extern const u16 ibuki_btca_017_head[];
extern const u16 ibuki_btca_018_head[];
extern const u16 ibuki_btca_019_head[];
extern const u16 ibuki_btca_020_head[];
extern const u16 ibuki_btca_021_head[];
extern const u16 ibuki_btca_022_head[];
extern const u16 ibuki_btca_023_head[];
extern const u16 ibuki_btca_025_head[];
extern const u16 ibuki_btca_026_head[];
extern const u16 ibuki_btca_027_head[];
extern const u16 ibuki_btca_028_head[];
extern const u16 ibuki_btca_029_head[];
extern const u16 ibuki_btca_030_head[];
extern const u16 ibuki_btca_031_head[];
extern const u16 ibuki_btca_032_head[];
extern const u16 ibuki_btca_033_head[];
extern const u16 ibuki_btca_034_head[];
extern const u16 ibuki_btca_035_head[];
extern const u16 ibuki_caca_000[], ibuki_caca_004[], ibuki_caca_007[], ibuki_caca_008[], ibuki_caca_009[], ibuki_caca_010[], ibuki_caca_011[], ibuki_caca_015[], ibuki_caca_019[], ibuki_caca_020[], ibuki_caca_021[], ibuki_caca_022[], ibuki_caca_023[];
extern const u16 ibuki_caca_000_head[];
extern const u16 ibuki_caca_004_head[];
extern const u16 ibuki_caca_007_head[];
extern const u16 ibuki_caca_008_head[];
extern const u16 ibuki_caca_009_head[];
extern const u16 ibuki_caca_010_head[];
extern const u16 ibuki_caca_011_head[];
extern const u16 ibuki_caca_015_head[];
extern const u16 ibuki_caca_019_head[];
extern const u16 ibuki_caca_020_head[];
extern const u16 ibuki_caca_021_head[];
extern const u16 ibuki_caca_022_head[];
extern const u16 ibuki_caca_023_head[];
extern const u16 ibuki_cuca_000[], ibuki_cuca_001[], ibuki_cuca_002[], ibuki_cuca_003[], ibuki_cuca_004[], ibuki_cuca_005[], ibuki_cuca_006[], ibuki_cuca_007[], ibuki_cuca_008[], ibuki_cuca_009[], ibuki_cuca_010[], ibuki_cuca_011[], ibuki_cuca_012[], ibuki_cuca_013[], ibuki_cuca_014[], ibuki_cuca_015[], ibuki_cuca_016[], ibuki_cuca_017[], ibuki_cuca_018[], ibuki_cuca_019[], ibuki_cuca_020[], ibuki_cuca_021[], ibuki_cuca_022[], ibuki_cuca_023[], ibuki_cuca_024[], ibuki_cuca_025[], ibuki_cuca_026[], ibuki_cuca_027[], ibuki_cuca_028[], ibuki_cuca_029[], ibuki_cuca_030[], ibuki_cuca_031[], ibuki_cuca_032[], ibuki_cuca_033[], ibuki_cuca_034[], ibuki_cuca_035[], ibuki_cuca_036[], ibuki_cuca_037[], ibuki_cuca_038[], ibuki_cuca_039[], ibuki_cuca_040[], ibuki_cuca_041[], ibuki_cuca_042[], ibuki_cuca_043[], ibuki_cuca_044[], ibuki_cuca_045[], ibuki_cuca_046[], ibuki_cuca_047[], ibuki_cuca_048[], ibuki_cuca_049[], ibuki_cuca_050[], ibuki_cuca_051[], ibuki_cuca_052[], ibuki_cuca_053[], ibuki_cuca_054[], ibuki_cuca_055[], ibuki_cuca_056[], ibuki_cuca_057[], ibuki_cuca_058[], ibuki_cuca_059[], ibuki_cuca_060[], ibuki_cuca_061[], ibuki_cuca_062[], ibuki_cuca_063[], ibuki_cuca_064[], ibuki_cuca_065[], ibuki_cuca_066[], ibuki_cuca_067[];
extern const u16 ibuki_cuca_000_head[];
extern const u16 ibuki_cuca_001_head[];
extern const u16 ibuki_cuca_002_head[];
extern const u16 ibuki_cuca_003_head[];
extern const u16 ibuki_cuca_004_head[];
extern const u16 ibuki_cuca_005_head[];
extern const u16 ibuki_cuca_006_head[];
extern const u16 ibuki_cuca_007_head[];
extern const u16 ibuki_cuca_008_head[];
extern const u16 ibuki_cuca_009_head[];
extern const u16 ibuki_cuca_010_head[];
extern const u16 ibuki_cuca_011_head[];
extern const u16 ibuki_cuca_012_head[];
extern const u16 ibuki_cuca_013_head[];
extern const u16 ibuki_cuca_014_head[];
extern const u16 ibuki_cuca_015_head[];
extern const u16 ibuki_cuca_016_head[];
extern const u16 ibuki_cuca_017_head[];
extern const u16 ibuki_cuca_018_head[];
extern const u16 ibuki_cuca_019_head[];
extern const u16 ibuki_cuca_020_head[];
extern const u16 ibuki_cuca_021_head[];
extern const u16 ibuki_cuca_022_head[];
extern const u16 ibuki_cuca_023_head[];
extern const u16 ibuki_cuca_024_head[];
extern const u16 ibuki_cuca_025_head[];
extern const u16 ibuki_cuca_026_head[];
extern const u16 ibuki_cuca_027_head[];
extern const u16 ibuki_cuca_028_head[];
extern const u16 ibuki_cuca_029_head[];
extern const u16 ibuki_cuca_030_head[];
extern const u16 ibuki_cuca_031_head[];
extern const u16 ibuki_cuca_032_head[];
extern const u16 ibuki_cuca_033_head[];
extern const u16 ibuki_cuca_034_head[];
extern const u16 ibuki_cuca_035_head[];
extern const u16 ibuki_cuca_036_head[];
extern const u16 ibuki_cuca_037_head[];
extern const u16 ibuki_cuca_038_head[];
extern const u16 ibuki_cuca_039_head[];
extern const u16 ibuki_cuca_040_head[];
extern const u16 ibuki_cuca_041_head[];
extern const u16 ibuki_cuca_042_head[];
extern const u16 ibuki_cuca_043_head[];
extern const u16 ibuki_cuca_044_head[];
extern const u16 ibuki_cuca_045_head[];
extern const u16 ibuki_cuca_046_head[];
extern const u16 ibuki_cuca_047_head[];
extern const u16 ibuki_cuca_048_head[];
extern const u16 ibuki_cuca_049_head[];
extern const u16 ibuki_cuca_050_head[];
extern const u16 ibuki_cuca_051_head[];
extern const u16 ibuki_cuca_052_head[];
extern const u16 ibuki_cuca_053_head[];
extern const u16 ibuki_cuca_054_head[];
extern const u16 ibuki_cuca_055_head[];
extern const u16 ibuki_cuca_056_head[];
extern const u16 ibuki_cuca_057_head[];
extern const u16 ibuki_cuca_058_head[];
extern const u16 ibuki_cuca_059_head[];
extern const u16 ibuki_cuca_060_head[];
extern const u16 ibuki_cuca_061_head[];
extern const u16 ibuki_cuca_062_head[];
extern const u16 ibuki_cuca_063_head[];
extern const u16 ibuki_cuca_064_head[];
extern const u16 ibuki_cuca_065_head[];
extern const u16 ibuki_cuca_066_head[];
extern const u16 ibuki_cuca_067_head[];
extern const u16 ibuki_atca_unused[], ibuki_atca_000[], ibuki_atca_001[], ibuki_atca_003[], ibuki_atca_005[], ibuki_atca_006[], ibuki_atca_007[], ibuki_atca_009[], ibuki_atca_010[], ibuki_atca_012[], ibuki_atca_013[], ibuki_atca_014[], ibuki_atca_015[], ibuki_atca_016[], ibuki_atca_017[], ibuki_atca_018[], ibuki_atca_021[], ibuki_atca_024[], ibuki_atca_027[], ibuki_atca_030[], ibuki_atca_032[], ibuki_atca_033[], ibuki_atca_036[], ibuki_atca_038[], ibuki_atca_040[], ibuki_atca_042[], ibuki_atca_044[], ibuki_atca_046[], ibuki_atca_048[], ibuki_atca_050[], ibuki_atca_052[], ibuki_atca_054[], ibuki_atca_056[], ibuki_atca_058[], ibuki_atca_060[], ibuki_atca_062[], ibuki_atca_064[], ibuki_atca_066[], ibuki_atca_068[], ibuki_atca_070[], ibuki_atca_072[], ibuki_atca_074[], ibuki_atca_076[], ibuki_atca_078[], ibuki_atca_080[], ibuki_atca_082[], ibuki_atca_084[], ibuki_atca_086[], ibuki_atca_088[], ibuki_atca_090[], ibuki_atca_092[], ibuki_atca_094[], ibuki_atca_096[], ibuki_atca_098[], ibuki_atca_100[], ibuki_atca_102[], ibuki_atca_104[], ibuki_atca_106[], ibuki_atca_108[], ibuki_atca_110[], ibuki_atca_112[], ibuki_atca_114[], ibuki_atca_116[], ibuki_atca_118[], ibuki_atca_144[], ibuki_atca_146[], ibuki_atca_150[], ibuki_atca_156[], ibuki_atca_157[], ibuki_atca_158[], ibuki_atca_159[], ibuki_atca_160[], ibuki_atca_161[], ibuki_atca_162[], ibuki_atca_163[], ibuki_atca_164[], ibuki_atca_165[], ibuki_atca_166[], ibuki_atca_167[];
extern const u16 ibuki_atca_unused_head[];
extern const u16 ibuki_atca_000_head[];
extern const u16 ibuki_atca_001_head[];
extern const u16 ibuki_atca_003_head[];
extern const u16 ibuki_atca_005_head[];
extern const u16 ibuki_atca_006_head[];
extern const u16 ibuki_atca_007_head[];
extern const u16 ibuki_atca_009_head[];
extern const u16 ibuki_atca_010_head[];
extern const u16 ibuki_atca_012_head[];
extern const u16 ibuki_atca_013_head[];
extern const u16 ibuki_atca_014_head[];
extern const u16 ibuki_atca_015_head[];
extern const u16 ibuki_atca_016_head[];
extern const u16 ibuki_atca_017_head[];
extern const u16 ibuki_atca_018_head[];
extern const u16 ibuki_atca_021_head[];
extern const u16 ibuki_atca_024_head[];
extern const u16 ibuki_atca_027_head[];
extern const u16 ibuki_atca_030_head[];
extern const u16 ibuki_atca_032_head[];
extern const u16 ibuki_atca_033_head[];
extern const u16 ibuki_atca_036_head[];
extern const u16 ibuki_atca_038_head[];
extern const u16 ibuki_atca_040_head[];
extern const u16 ibuki_atca_042_head[];
extern const u16 ibuki_atca_044_head[];
extern const u16 ibuki_atca_046_head[];
extern const u16 ibuki_atca_048_head[];
extern const u16 ibuki_atca_050_head[];
extern const u16 ibuki_atca_052_head[];
extern const u16 ibuki_atca_054_head[];
extern const u16 ibuki_atca_056_head[];
extern const u16 ibuki_atca_058_head[];
extern const u16 ibuki_atca_060_head[];
extern const u16 ibuki_atca_062_head[];
extern const u16 ibuki_atca_064_head[];
extern const u16 ibuki_atca_066_head[];
extern const u16 ibuki_atca_068_head[];
extern const u16 ibuki_atca_070_head[];
extern const u16 ibuki_atca_072_head[];
extern const u16 ibuki_atca_074_head[];
extern const u16 ibuki_atca_076_head[];
extern const u16 ibuki_atca_078_head[];
extern const u16 ibuki_atca_080_head[];
extern const u16 ibuki_atca_082_head[];
extern const u16 ibuki_atca_084_head[];
extern const u16 ibuki_atca_086_head[];
extern const u16 ibuki_atca_088_head[];
extern const u16 ibuki_atca_090_head[];
extern const u16 ibuki_atca_092_head[];
extern const u16 ibuki_atca_094_head[];
extern const u16 ibuki_atca_096_head[];
extern const u16 ibuki_atca_098_head[];
extern const u16 ibuki_atca_100_head[];
extern const u16 ibuki_atca_102_head[];
extern const u16 ibuki_atca_104_head[];
extern const u16 ibuki_atca_106_head[];
extern const u16 ibuki_atca_108_head[];
extern const u16 ibuki_atca_110_head[];
extern const u16 ibuki_atca_112_head[];
extern const u16 ibuki_atca_114_head[];
extern const u16 ibuki_atca_116_head[];
extern const u16 ibuki_atca_118_head[];
extern const u16 ibuki_atca_144_head[];
extern const u16 ibuki_atca_146_head[];
extern const u16 ibuki_atca_150_head[];
extern const u16 ibuki_atca_156_head[];
extern const u16 ibuki_atca_157_head[];
extern const u16 ibuki_atca_158_head[];
extern const u16 ibuki_atca_159_head[];
extern const u16 ibuki_atca_160_head[];
extern const u16 ibuki_atca_161_head[];
extern const u16 ibuki_atca_162_head[];
extern const u16 ibuki_atca_163_head[];
extern const u16 ibuki_atca_164_head[];
extern const u16 ibuki_atca_165_head[];
extern const u16 ibuki_atca_166_head[];
extern const u16 ibuki_atca_167_head[];
extern const u16 ibuki_exca_000[], ibuki_exca_001[], ibuki_exca_003[], ibuki_exca_004[], ibuki_exca_005[], ibuki_exca_007[], ibuki_exca_008[], ibuki_exca_009[], ibuki_exca_010[], ibuki_exca_011[], ibuki_exca_012[], ibuki_exca_015[], ibuki_exca_016[], ibuki_exca_019[], ibuki_exca_020[], ibuki_exca_021[], ibuki_exca_022[], ibuki_exca_024[], ibuki_exca_025[], ibuki_exca_027[], ibuki_exca_028[], ibuki_exca_030[], ibuki_exca_031[], ibuki_exca_032[], ibuki_exca_033[], ibuki_exca_034[], ibuki_exca_035[], ibuki_exca_036[], ibuki_exca_037[], ibuki_exca_038[], ibuki_exca_039[], ibuki_exca_040[], ibuki_exca_041[], ibuki_exca_042[], ibuki_exca_043[], ibuki_exca_044[], ibuki_exca_045[], ibuki_exca_046[], ibuki_exca_047[], ibuki_exca_048[], ibuki_exca_049[], ibuki_exca_050[], ibuki_exca_051[], ibuki_exca_052[], ibuki_exca_053[], ibuki_exca_054[], ibuki_exca_055[], ibuki_exca_056[], ibuki_exca_059[], ibuki_exca_060[], ibuki_exca_061[], ibuki_exca_062[], ibuki_exca_063[], ibuki_exca_064[], ibuki_exca_065[], ibuki_exca_066[], ibuki_exca_067[], ibuki_exca_068[], ibuki_exca_069[], ibuki_exca_070[], ibuki_exca_071[], ibuki_exca_072[], ibuki_exca_073[], ibuki_exca_074[], ibuki_exca_075[], ibuki_exca_076[], ibuki_exca_077[], ibuki_exca_078[];
extern const u16 ibuki_exca_000_head[];
extern const u16 ibuki_exca_001_head[];
extern const u16 ibuki_exca_003_head[];
extern const u16 ibuki_exca_004_head[];
extern const u16 ibuki_exca_005_head[];
extern const u16 ibuki_exca_007_head[];
extern const u16 ibuki_exca_008_head[];
extern const u16 ibuki_exca_009_head[];
extern const u16 ibuki_exca_010_head[];
extern const u16 ibuki_exca_011_head[];
extern const u16 ibuki_exca_012_head[];
extern const u16 ibuki_exca_015_head[];
extern const u16 ibuki_exca_016_head[];
extern const u16 ibuki_exca_019_head[];
extern const u16 ibuki_exca_020_head[];
extern const u16 ibuki_exca_021_head[];
extern const u16 ibuki_exca_022_head[];
extern const u16 ibuki_exca_024_head[];
extern const u16 ibuki_exca_025_head[];
extern const u16 ibuki_exca_027_head[];
extern const u16 ibuki_exca_028_head[];
extern const u16 ibuki_exca_030_head[];
extern const u16 ibuki_exca_031_head[];
extern const u16 ibuki_exca_032_head[];
extern const u16 ibuki_exca_033_head[];
extern const u16 ibuki_exca_034_head[];
extern const u16 ibuki_exca_035_head[];
extern const u16 ibuki_exca_036_head[];
extern const u16 ibuki_exca_037_head[];
extern const u16 ibuki_exca_038_head[];
extern const u16 ibuki_exca_039_head[];
extern const u16 ibuki_exca_040_head[];
extern const u16 ibuki_exca_041_head[];
extern const u16 ibuki_exca_042_head[];
extern const u16 ibuki_exca_043_head[];
extern const u16 ibuki_exca_044_head[];
extern const u16 ibuki_exca_045_head[];
extern const u16 ibuki_exca_046_head[];
extern const u16 ibuki_exca_047_head[];
extern const u16 ibuki_exca_048_head[];
extern const u16 ibuki_exca_049_head[];
extern const u16 ibuki_exca_050_head[];
extern const u16 ibuki_exca_051_head[];
extern const u16 ibuki_exca_052_head[];
extern const u16 ibuki_exca_053_head[];
extern const u16 ibuki_exca_054_head[];
extern const u16 ibuki_exca_055_head[];
extern const u16 ibuki_exca_056_head[];
extern const u16 ibuki_exca_059_head[];
extern const u16 ibuki_exca_060_head[];
extern const u16 ibuki_exca_061_head[];
extern const u16 ibuki_exca_062_head[];
extern const u16 ibuki_exca_063_head[];
extern const u16 ibuki_exca_064_head[];
extern const u16 ibuki_exca_065_head[];
extern const u16 ibuki_exca_066_head[];
extern const u16 ibuki_exca_067_head[];
extern const u16 ibuki_exca_068_head[];
extern const u16 ibuki_exca_069_head[];
extern const u16 ibuki_exca_070_head[];
extern const u16 ibuki_exca_071_head[];
extern const u16 ibuki_exca_072_head[];
extern const u16 ibuki_exca_073_head[];
extern const u16 ibuki_exca_074_head[];
extern const u16 ibuki_exca_075_head[];
extern const u16 ibuki_exca_076_head[];
extern const u16 ibuki_exca_077_head[];
extern const u16 ibuki_exca_078_head[];
extern const u16 ibuki_saca_000[], ibuki_saca_001[], ibuki_saca_002[], ibuki_saca_024[], ibuki_saca_025[], ibuki_saca_026[], ibuki_saca_027[], ibuki_saca_028[], ibuki_saca_029[], ibuki_saca_030[], ibuki_saca_031[], ibuki_saca_032[], ibuki_saca_033[], ibuki_saca_034[], ibuki_saca_036[], ibuki_saca_037[], ibuki_saca_038[], ibuki_saca_039[], ibuki_saca_040[], ibuki_saca_041[], ibuki_saca_042[], ibuki_saca_043[], ibuki_saca_044[], ibuki_saca_048[], ibuki_saca_049[], ibuki_saca_050[], ibuki_saca_051[], ibuki_saca_052[], ibuki_saca_053[], ibuki_saca_054[], ibuki_saca_055[], ibuki_saca_056[], ibuki_saca_060[], ibuki_saca_061[], ibuki_saca_062[], ibuki_saca_064[], ibuki_saca_065[], ibuki_saca_066[], ibuki_saca_067[], ibuki_saca_068[], ibuki_saca_069[], ibuki_saca_070[], ibuki_saca_071[], ibuki_saca_072[], ibuki_saca_073[], ibuki_saca_074[], ibuki_saca_075[], ibuki_saca_076[], ibuki_saca_080[], ibuki_saca_092[], ibuki_saca_096[], ibuki_saca_097[], ibuki_saca_098[], ibuki_saca_099[], ibuki_saca_102[], ibuki_saca_103[], ibuki_saca_104[], ibuki_saca_105[], ibuki_saca_106[], ibuki_saca_107[], ibuki_saca_108[], ibuki_saca_109[], ibuki_saca_111[], ibuki_saca_112[], ibuki_saca_113[], ibuki_saca_115[], ibuki_saca_116[];
extern const u16 ibuki_saca_000_head[];
extern const u16 ibuki_saca_001_head[];
extern const u16 ibuki_saca_002_head[];
extern const u16 ibuki_saca_024_head[];
extern const u16 ibuki_saca_025_head[];
extern const u16 ibuki_saca_026_head[];
extern const u16 ibuki_saca_027_head[];
extern const u16 ibuki_saca_028_head[];
extern const u16 ibuki_saca_029_head[];
extern const u16 ibuki_saca_030_head[];
extern const u16 ibuki_saca_031_head[];
extern const u16 ibuki_saca_032_head[];
extern const u16 ibuki_saca_033_head[];
extern const u16 ibuki_saca_034_head[];
extern const u16 ibuki_saca_036_head[];
extern const u16 ibuki_saca_037_head[];
extern const u16 ibuki_saca_038_head[];
extern const u16 ibuki_saca_039_head[];
extern const u16 ibuki_saca_040_head[];
extern const u16 ibuki_saca_041_head[];
extern const u16 ibuki_saca_042_head[];
extern const u16 ibuki_saca_043_head[];
extern const u16 ibuki_saca_044_head[];
extern const u16 ibuki_saca_048_head[];
extern const u16 ibuki_saca_049_head[];
extern const u16 ibuki_saca_050_head[];
extern const u16 ibuki_saca_051_head[];
extern const u16 ibuki_saca_052_head[];
extern const u16 ibuki_saca_053_head[];
extern const u16 ibuki_saca_054_head[];
extern const u16 ibuki_saca_055_head[];
extern const u16 ibuki_saca_056_head[];
extern const u16 ibuki_saca_060_head[];
extern const u16 ibuki_saca_061_head[];
extern const u16 ibuki_saca_062_head[];
extern const u16 ibuki_saca_064_head[];
extern const u16 ibuki_saca_065_head[];
extern const u16 ibuki_saca_066_head[];
extern const u16 ibuki_saca_067_head[];
extern const u16 ibuki_saca_068_head[];
extern const u16 ibuki_saca_069_head[];
extern const u16 ibuki_saca_070_head[];
extern const u16 ibuki_saca_071_head[];
extern const u16 ibuki_saca_072_head[];
extern const u16 ibuki_saca_073_head[];
extern const u16 ibuki_saca_074_head[];
extern const u16 ibuki_saca_075_head[];
extern const u16 ibuki_saca_076_head[];
extern const u16 ibuki_saca_080_head[];
extern const u16 ibuki_saca_092_head[];
extern const u16 ibuki_saca_096_head[];
extern const u16 ibuki_saca_097_head[];
extern const u16 ibuki_saca_098_head[];
extern const u16 ibuki_saca_099_head[];
extern const u16 ibuki_saca_102_head[];
extern const u16 ibuki_saca_103_head[];
extern const u16 ibuki_saca_104_head[];
extern const u16 ibuki_saca_105_head[];
extern const u16 ibuki_saca_106_head[];
extern const u16 ibuki_saca_107_head[];
extern const u16 ibuki_saca_108_head[];
extern const u16 ibuki_saca_109_head[];
extern const u16 ibuki_saca_111_head[];
extern const u16 ibuki_saca_112_head[];
extern const u16 ibuki_saca_113_head[];
extern const u16 ibuki_saca_115_head[];
extern const u16 ibuki_saca_116_head[];
extern const u16 ibuki_cbca_000[], ibuki_cbca_001[], ibuki_cbca_002[], ibuki_cbca_003[], ibuki_cbca_004[], ibuki_cbca_005[], ibuki_cbca_006[], ibuki_cbca_007[], ibuki_cbca_008[], ibuki_cbca_009[], ibuki_cbca_010[], ibuki_cbca_011[], ibuki_cbca_012[], ibuki_cbca_013[], ibuki_cbca_014[], ibuki_cbca_015[], ibuki_cbca_016[], ibuki_cbca_017[], ibuki_cbca_018[], ibuki_cbca_019[], ibuki_cbca_020[], ibuki_cbca_021[], ibuki_cbca_022[], ibuki_cbca_023[], ibuki_cbca_024[], ibuki_cbca_025[], ibuki_cbca_026[], ibuki_cbca_027[], ibuki_cbca_028[], ibuki_cbca_029[], ibuki_cbca_030[], ibuki_cbca_031[], ibuki_cbca_032[], ibuki_cbca_033[], ibuki_cbca_034[], ibuki_cbca_035[], ibuki_cbca_036[], ibuki_cbca_037[], ibuki_cbca_038[], ibuki_cbca_039[], ibuki_cbca_040[], ibuki_cbca_041[], ibuki_cbca_042[], ibuki_cbca_043[], ibuki_cbca_044[], ibuki_cbca_045[], ibuki_cbca_048[], ibuki_cbca_049[], ibuki_cbca_050[], ibuki_cbca_051[], ibuki_cbca_052[], ibuki_cbca_053[], ibuki_cbca_054[], ibuki_cbca_055[], ibuki_cbca_056[], ibuki_cbca_057[], ibuki_cbca_058[], ibuki_cbca_059[], ibuki_cbca_060[], ibuki_cbca_064[], ibuki_cbca_065[];
extern const u16 ibuki_cbca_000_head[];
extern const u16 ibuki_cbca_001_head[];
extern const u16 ibuki_cbca_002_head[];
extern const u16 ibuki_cbca_003_head[];
extern const u16 ibuki_cbca_004_head[];
extern const u16 ibuki_cbca_005_head[];
extern const u16 ibuki_cbca_006_head[];
extern const u16 ibuki_cbca_007_head[];
extern const u16 ibuki_cbca_008_head[];
extern const u16 ibuki_cbca_009_head[];
extern const u16 ibuki_cbca_010_head[];
extern const u16 ibuki_cbca_011_head[];
extern const u16 ibuki_cbca_012_head[];
extern const u16 ibuki_cbca_013_head[];
extern const u16 ibuki_cbca_014_head[];
extern const u16 ibuki_cbca_015_head[];
extern const u16 ibuki_cbca_016_head[];
extern const u16 ibuki_cbca_017_head[];
extern const u16 ibuki_cbca_018_head[];
extern const u16 ibuki_cbca_019_head[];
extern const u16 ibuki_cbca_020_head[];
extern const u16 ibuki_cbca_021_head[];
extern const u16 ibuki_cbca_022_head[];
extern const u16 ibuki_cbca_023_head[];
extern const u16 ibuki_cbca_024_head[];
extern const u16 ibuki_cbca_025_head[];
extern const u16 ibuki_cbca_026_head[];
extern const u16 ibuki_cbca_027_head[];
extern const u16 ibuki_cbca_028_head[];
extern const u16 ibuki_cbca_029_head[];
extern const u16 ibuki_cbca_030_head[];
extern const u16 ibuki_cbca_031_head[];
extern const u16 ibuki_cbca_032_head[];
extern const u16 ibuki_cbca_033_head[];
extern const u16 ibuki_cbca_034_head[];
extern const u16 ibuki_cbca_035_head[];
extern const u16 ibuki_cbca_036_head[];
extern const u16 ibuki_cbca_037_head[];
extern const u16 ibuki_cbca_038_head[];
extern const u16 ibuki_cbca_039_head[];
extern const u16 ibuki_cbca_040_head[];
extern const u16 ibuki_cbca_041_head[];
extern const u16 ibuki_cbca_042_head[];
extern const u16 ibuki_cbca_043_head[];
extern const u16 ibuki_cbca_044_head[];
extern const u16 ibuki_cbca_045_head[];
extern const u16 ibuki_cbca_048_head[];
extern const u16 ibuki_cbca_049_head[];
extern const u16 ibuki_cbca_050_head[];
extern const u16 ibuki_cbca_051_head[];
extern const u16 ibuki_cbca_052_head[];
extern const u16 ibuki_cbca_053_head[];
extern const u16 ibuki_cbca_054_head[];
extern const u16 ibuki_cbca_055_head[];
extern const u16 ibuki_cbca_056_head[];
extern const u16 ibuki_cbca_057_head[];
extern const u16 ibuki_cbca_058_head[];
extern const u16 ibuki_cbca_059_head[];
extern const u16 ibuki_cbca_060_head[];
extern const u16 ibuki_cbca_064_head[];
extern const u16 ibuki_cbca_065_head[];

/* normal scripts: 51 entries */
const u16* const ibuki_nmca[52] = {
    ibuki_nmca_000,  /* 0 KAMAE */
    ibuki_nmca_001,  /* 1 HURIMUKI */
    ibuki_nmca_002,  /* 2 FRONT WALK */
    ibuki_nmca_003,  /* 3 BACK WALK */
    ibuki_nmca_004,  /* 4 DASH HUMIKOMI */
    ibuki_nmca_005,  /* 5 DASH TOBINOKI */
    ibuki_nmca_006,  /* 6 KAGAMU */
    ibuki_nmca_007,  /* 7 KAGAMI KAMAE */
    ibuki_nmca_008,  /* 8 KAGAMI TURN */
    ibuki_nmca_008,  /* 9 KAGAMI F WALK */
    ibuki_nmca_008,  /* 10 KAGAMI B WALK */
    ibuki_nmca_011,  /* 11 STAND UP */
    ibuki_nmca_012,  /* 12 JUMP JUNBI */
    ibuki_nmca_013,  /* 13 SP JUMP JUNBI */
    ibuki_nmca_014,  /* 14 JUMP FRONT */
    ibuki_nmca_015,  /* 15 JUMP VERTICAL */
    ibuki_nmca_016,  /* 16 JUMP BACK */
    ibuki_nmca_017,  /* 17 S JUMP FRONT */
    ibuki_nmca_017,  /* 18 S JUMP V */
    ibuki_nmca_017,  /* 19 S JUMP BACK */
    ibuki_nmca_020,  /* 20 SP JUMP FRONT */
    ibuki_nmca_021,  /* 21 SP JUMP V */
    ibuki_nmca_022,  /* 22 SP JUMP BACK */
    ibuki_nmca_023,  /* 23 WALK END */
    ibuki_nmca_024,  /* 24 PARING HEAD */
    ibuki_nmca_024,  /* 25 PARING UP */
    ibuki_nmca_026,  /* 26 PARING DOWN */
    ibuki_nmca_027,  /* 27 PARING AIR F */
    ibuki_nmca_027,  /* 28 PARING AIR B */
    ibuki_nmca_029,  /* 29 GUARD HEAD */
    ibuki_nmca_030,  /* 30 GUARD UP */
    ibuki_nmca_031,  /* 31 GUARD DOWN */
    ibuki_nmca_032,  /* 32 GUARD AIR */
    ibuki_nmca_032,  /* 33 no name */
    ibuki_nmca_032,  /* 34 no name */
    ibuki_nmca_032,  /* 35 no name */
    ibuki_nmca_032,  /* 36 no name */
    ibuki_nmca_032,  /* 37 no name */
    ibuki_nmca_038,  /* 38 P BREAK ZUJOU */
    ibuki_nmca_038,  /* 39 P BREAK UP */
    ibuki_nmca_040,  /* 40 P BREAK DOWN */
    ibuki_nmca_041,  /* 41 P BREAK AIR F */
    ibuki_nmca_041,  /* 42 P BREAK AIR R */
    ibuki_nmca_043,  /* 43 TUKAMIHAZUSI */
    ibuki_nmca_044,  /* 44 TUKAMIHAZUSARE */
    ibuki_nmca_045,  /* 45 TUKAMIHAZUSI */
    ibuki_nmca_046,  /* 46 TUKAMIHAZUSARE */
    ibuki_nmca_047,  /* 47 no name */
    ibuki_nmca_048,  /* 48 no name */
    ibuki_nmca_049,  /* 49 no name */
    ibuki_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 ibuki_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_000[388] = {
    L4(6, 0, 0, 0, 0, 2124, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 2125, 0, 0x2A02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 2126, 0, 0x2A03, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 2124, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2125, 0, 0x2A02, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2126, 0, 0x2A03, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2127, 0, 0x2A04, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2128, 0, 0x2A05, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2129, 0, 0x2A06, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2130, 0, 0x2A07, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2131, 0, 0x2A08, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2132, 0, 0x2A09, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2133, 0, 0x2A0A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2134, 0, 0x2A0B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2135, 0, 0x2A0C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2136, 0, 0x2A0D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2137, 0, 0x2A0E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2138, 0, 0x2A10, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2139, 0, 0x2A11, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2140, 0, 0x2A12, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2141, 0, 0x2A13, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2142, 0, 0x2A14, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2143, 0, 0x2C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_PJMP, 8, 8194, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 2144, 0, 0x2C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2145, 0, 0x2C40, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2146, 0, 0x2C41, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 2144, 0, 0x2C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 2145, 0, 0x2C40, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 2146, 0, 0x2C41, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 2147, 0, 0x2C42, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2148, 0, 0x2C44, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2149, 0, 0x2C45, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2150, 0, 0x2C46, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2151, 0, 0x2C47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2152, 0, 0x2C48, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 0, 0, 36), 0, 0, 0, 0,
    CMD(CM_PJMP, 8, 8194, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 2153, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2154, 0, 0x2A02, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2155, 0, 0x2A03, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2156, 0, 0x2A04, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2157, 0, 0x2A05, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 2158, 0, 0x2A06, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 ibuki_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_001[76] = {
    L4(3, 0, 0, 0, 1, 2, 0, 0x2A15, 0, 388, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 3, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 4, 0, 0x2A17, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 5, 0, 0x2A18, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 6, 0, 0x2A19, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 7, 0, 0x2A1A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 8, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0),
    L4(28, 64, 0, 0, 0, 9, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 9, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 ibuki_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_002[140] = {
    L4(2, 0, 0, 0, 0, 73, 0, 0x2A1C, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 74, 0, 0x2A1D, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 75, 0, 0x2A1E, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 76, 0, 0x2A1F, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 77, 0, 0x2A20, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 78, 0, 0x2A21, 0, 386, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 79, 0, 0x2A22, 0, 386, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 80, 0, 0x2A23, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 81, 0, 0x2A24, 0, 386, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 82, 0, 0x2A25, 0, 387, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 83, 0, 0x2A26, 0, 387, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 84, 0, 0x2A27, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 85, 0, 0x2A28, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 0, 0x2A29, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 0, 0x2A2A, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 88, 0, 0x2A2B, 0, 387, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 ibuki_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_003[140] = {
    L4(3, 0, 0, 0, 0, 89, 0, 0x2A2C, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 90, 0, 0x2A2D, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 91, 0, 0x2A2E, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 0, 0x2A2F, 0, 386, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 93, 0, 0x2A30, 0, 386, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 94, 0, 0x2A31, 0, 386, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 95, 0, 0x2A32, 0, 387, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 96, 0, 0x2A33, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 97, 0, 0x2A34, 0, 387, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 98, 0, 0x2A35, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 99, 0, 0x2A36, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 100, 0, 0x2A37, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 101, 0, 0x2A38, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 102, 0, 0x2A39, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 103, 0, 0x2A3A, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 104, 0, 0x2A3B, 0, 387, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 ibuki_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_004[244] = {
    CMD(CM_RJA, 0, 4, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 108, 0, 0x2A46, 0, 394, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(1, 1, 277, 0, 0, 109, 0, 0x2AA9, 0, 395, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 110, 0, 0x2AAA, 0, 395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 111, 0, 0x2AAB, 0, 395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 112, 0, 0x2AAC, 0, 395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 112, 0, 0x2AAC, 0, 396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 113, 0, 0x2AAD, 0, 396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 114, 0, 0x2AAE, 0, 396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 273, 0, 0, 115, 0, 0x2AAF, 0, 397, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 0, 0, 0, 116, 0, 0x2AB0, 0, 397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 117, 0, 0x2AB1, 0, 397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 118, 0, 0x2AB2, 0, 398, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 119, 0, 0x2AB3, 0, 398, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 120, 0, 0x2AB4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 121, 0, 0x2AB5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 122, 0, 0x2AB6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 123, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 124, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 124, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 ibuki_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_005[292] = {
    CMD(CM_JSR, 8, 59, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 108, 0, 0x2A46, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 277, 0, 0, 125, 0, 0x2AB7, 0, 399, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 126, 0, 0x2AB8, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 127, 0, 0x2AB9, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 128, 0, 0x2ABA, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 129, 0, 0x2ABB, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 130, 0, 0x2ABC, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 131, 0, 0x2ABD, 0, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 132, 0, 0x2ABE, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 133, 0, 0x2ABF, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 134, 0, 0x2AC0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 135, 0, 0x2AC1, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 136, 0, 0x2AC2, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 273, 0, 0, 137, 0, 0x2AC3, 0, 401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 138, 0, 0x2A3D, 0, 401, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 64, 0, 0, 0, 139, 0, 0x2A3E, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 140, 0, 0x2A3F, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 141, 0, 0x2A45, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 142, 0, 0x2A46, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 143, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 144, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 145, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 145, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 ibuki_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_006[92] = {
    L4(2, 0, 0, 0, 0, 146, 0, 0x2A3C, 0, 390, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 390, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 155, 0, 0x2A4A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 155, 0, 0x2A4A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 ibuki_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_007[76] = {
    L4(6, 0, 0, 0, 0, 184, 0, 0x2A4A, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 185, 0, 0x2A4B, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 186, 0, 0x2A4C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 187, 0, 0x2A4D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 188, 0, 0x2A4E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 189, 0, 0x2A4F, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 190, 0, 0x2A50, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 191, 0, 0x2A51, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 ibuki_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_008[68] = {
    L4(3, 0, 0, 0, 1, 192, 0, 0x2A52, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 193, 0, 0x2A53, 0, 389, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 194, 0, 0x2A54, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 195, 0, 0x2A55, 0, 389, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 196, 0, 0x2A56, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 197, 0, 0x2A57, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 198, 0, 0x2A58, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 198, 0, 0x2A58, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 ibuki_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_011[52] = {
    L4(1, 0, 0, 0, 0, 156, 0, 0x2A45, 0, 391, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 157, 0, 0x2A46, 0, 391, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 158, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 159, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 160, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 160, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 ibuki_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 199, 0, 0x2A45, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 199, 0, 0x2A45, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 199, 0, 0x2A45, 0, 299, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 ibuki_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_013[20] = {
    L4(4, 0, 0, 0, 0, 200, 0, 0x2A69, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 200, 0, 0x2A69, 0, 299, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 ibuki_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_014[220] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 201, 0, 0x2A6D, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 202, 0, 0x2A6E, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 203, 0, 0x2A6F, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 204, 0, 0x2A70, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 205, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 206, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 207, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 208, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 209, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 210, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 211, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 212, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 213, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 214, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 215, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 216, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 217, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 218, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 219, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 220, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 221, 0, 0x2A81, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 222, 0, 0x2A82, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 ibuki_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_015[164] = {
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 233, 0, 0x2A59, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 234, 0, 0x2A5A, 0, 402, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 235, 0, 0x2A5B, 0, 402, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 236, 0, 0x2A5C, 0, 403, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 237, 0, 0x2A5D, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 238, 0, 0x2A5E, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 239, 0, 0x2A5F, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 240, 0, 0x2A60, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 241, 0, 0x2A61, 0, 403, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 242, 0, 0x2A62, 0, 404, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 243, 0, 0x2A63, 0, 404, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 244, 0, 0x2A64, 0, 404, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 245, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 246, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 247, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 246, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 245, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 16), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 ibuki_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_016[212] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 256, 0, 0x2A59, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 257, 0, 0x2A5A, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 258, 0, 0x2A5B, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 259, 0, 0x2A5C, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 260, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 261, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 262, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 263, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 264, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 265, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 266, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 267, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 268, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 269, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 270, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 271, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 272, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 273, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 274, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 275, 0, 0x2A81, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 276, 0, 0x2A82, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 277, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 278, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 278, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 ibuki_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_017[12] = {
    CMD(CM_JSR, 8, 27, 1),
    CMD(CM_JPSS, 0, 15, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 ibuki_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_020[220] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 201, 0, 0x2A6D, 0, 406, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 202, 0, 0x2A6E, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 203, 0, 0x2A6F, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 204, 0, 0x2A70, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 205, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 206, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 207, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 208, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 209, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 210, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 211, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 212, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 213, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 214, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 215, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 216, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 217, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 218, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 219, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 220, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 221, 0, 0x2A81, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 222, 0, 0x2A82, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 ibuki_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_021[164] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 233, 0, 0x2A59, 0, 402, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 234, 0, 0x2A5A, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 235, 0, 0x2A5B, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 236, 0, 0x2A5C, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 237, 0, 0x2A5D, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 238, 0, 0x2A5E, 0, 403, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 239, 0, 0x2A5F, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 240, 0, 0x2A60, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 241, 0, 0x2A61, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 242, 0, 0x2A62, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 243, 0, 0x2A63, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 244, 0, 0x2A64, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 245, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 246, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 247, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 246, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 245, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 16), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 ibuki_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_022[204] = {
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 256, 0, 0x2A59, 0, 402, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 257, 0, 0x2A5A, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 258, 0, 0x2A5B, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 259, 0, 0x2A5C, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 260, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 261, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 262, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 263, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 264, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 265, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 266, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 267, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 268, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 269, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 270, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 271, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 272, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 273, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 274, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 275, 0, 0x2A81, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 276, 0, 0x2A82, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 277, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 278, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 278, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 ibuki_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_023[36] = {
    L4(1, 0, 0, 0, 0, 105, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 106, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 107, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 107, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 ibuki_nmca_024_head[4] = { HEAD(6, 2, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_024[136] = {
    L6(2, 133, 0, 0, 0, 289, 0, 0x2BB0, 0, 1, 0, 0, 0, 18, 6, 0, 0, 214, 0, 0),
    L6(2, 0, 357, 0, 0, 290, 0, 0x2BB1, 0, 1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 291, 0, 0x2BB2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 292, 0, 0x2BB3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 293, 0, 0x2B89, 0, 1, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(3, 64, 0, 0, 0, 294, 0, 0x2B8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(4, 0, 0, 0, 0, 295, 0, 0x2B8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 296, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 297, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 ibuki_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_026[100] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x2EE1, 0, 2, 0, 0, 0, 18, 6),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2EE2, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 357, 0, 0, 0, 0, 0x2EE3, 0, 2, 0, 0, 0, 6, 1),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2EE4, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2EE5, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2EE6, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2E2E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E2F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E30, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 ibuki_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_027[148] = {
    L4(1, 132, 0, 0, 0, 301, 0, 0x2AA1, 0, 9, 0, 0, 0, 18, 6),
    L4(2, 0, 357, 0, 0, 300, 0, 0x2AA2, 0, 9, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 299, 0, 0x2AA3, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 238, 0, 0x2A5E, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x12B0, 0x2AA1,
    CMD(CM_ROA, 8192, 0, 4614), 0, 0, 0, 0,
    L4(2, 0, 357, 0, 0, 300, 0, 0x2AA2, 0, 9, 0, 0, 0, 6, 2),
    CMD(CM_DUMMY, 0, 0, 0), 0x1200, 0x0000, 0x12D0, 0x2AA3,
    CMD(CM_ROA, 8192, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 302, 0, 0x2AA6, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 10, 0), 0x0200, 0x0000, 0x12F0, 0x2AA7,
    CMD(CM_ROA, 8192, 0, 0), 0x0000, 0x0000, 0x000C, 0x0000,
    L4(2, 64, 0, 0, 0, 304, 0, 0x2AA8, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 12, 0), 0x0003, 0x0000, 0x0010, 0x0007,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 ibuki_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_029[108] = {
    L4(2, 0, 0, 0, 0, 510, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 509, 0, 0x2A85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 505, 0, 0x2A86, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 506, 0, 0x2A87, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 507, 0, 0x2A88, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 508, 0, 0x2A89, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 509, 0, 0x2A85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 510, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 511, 0, 0x2A8C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 512, 0, 0x2A8D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 513, 0, 0x2A8E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 514, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 515, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 ibuki_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_030[108] = {
    L4(2, 0, 0, 0, 0, 524, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 519, 0, 0x2A90, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 520, 0, 0x2A91, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 521, 0, 0x2A92, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 522, 0, 0x2A93, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 523, 0, 0x2A94, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 519, 0, 0x2A90, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 524, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 511, 0, 0x2A8C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 512, 0, 0x2A8D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 513, 0, 0x2A8E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 514, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 515, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 ibuki_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_031[92] = {
    L4(2, 0, 0, 0, 0, 534, 0, 0x2A98, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 533, 0, 0x2A99, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 528, 0, 0x2A9B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 529, 0, 0x2A9C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 530, 0, 0x2A9D, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 531, 0, 0x2A9E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 532, 0, 0x2A9A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 533, 0, 0x2A99, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 534, 0, 0x2A98, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 535, 0, 0x2A97, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 536, 0, 0x2A97, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR, 33 no name, 34 no name, 35 no name ... */
const u16 ibuki_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_032[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2AA1, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2AA2, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2AA3, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2AA4, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2AA5, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x2AA6, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2AA7, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2AA8, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2AA8, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 ibuki_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_038[68] = {
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 291, 0, 0x2BB2, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 305, 0, 0x2AC7, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 306, 0, 0x2AC8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 ibuki_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_040[76] = {
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 528, 0, 0x2A9B, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 315, 0, 0x2AD4, 0, 2, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 316, 0, 0x2AD5, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 ibuki_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 301, 0, 0x2AA3, 0, 9, 0, 0, 0, 18, 8),
    L4(250, 0, 357, 0, 0, 300, 0, 0x2AA2, 0, 9, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 ibuki_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_043[68] = {
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 291, 0, 0x2BB2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 305, 0, 0x2AC7, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 306, 0, 0x2AC8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 ibuki_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_044[76] = {
    L4(250, 130, 0, 0, 0, 380, 0, 0x2B87, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 1, 0, 0, 0, 381, 0, 0x2B88, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 382, 0, 0x2B89, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 383, 0, 0x2B8A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 384, 0, 0x2B8B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 385, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 386, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 387, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 387, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 ibuki_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_045[204] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 301, 0, 0x2AA3, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 0, 357, 0, 0, 300, 0, 0x2AA2, 0, 9, 0, 0, 0, 25, 2),
    L4(2, 1, 0, 0, 0, 259, 0, 0x2A5C, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 260, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 261, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 262, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 263, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 264, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 265, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 266, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 267, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 268, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 269, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 270, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 271, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 272, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 273, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 274, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 275, 0, 0x2A81, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 276, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 277, 0, 0x2A65, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 278, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 278, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 ibuki_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_046[108] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x2E61, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2E62, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2E63, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E64, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E65, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 854, 0, 0x2CA3, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 855, 0, 0x2CA4, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 245, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 246, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 247, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ibuki_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ibuki_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ibuki_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2A01, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ibuki_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_nmca_050[68] = {
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 291, 0, 0x2BB2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 305, 0, 0x2AC7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 306, 0, 0x2AC8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const ibuki_dmca[99] = {
    ibuki_dmca_000,  /* 0 GUARD HEAD */
    ibuki_dmca_001,  /* 1 GUARD UP */
    ibuki_dmca_002,  /* 2 GUARD DOWN */
    ibuki_dmca_003,  /* 3 GUARD AIR */
    ibuki_dmca_004,  /* 4 HUSHIN HEAD */
    ibuki_dmca_004,  /* 5 HUSHIN UP */
    ibuki_dmca_006,  /* 6 HUSHIN DOWN */
    ibuki_dmca_006,  /* 7 HUSHIN AIR */
    ibuki_dmca_008,  /* 8 FACE S */
    ibuki_dmca_009,  /* 9 FACE M */
    ibuki_dmca_010,  /* 10 FACE L */
    ibuki_dmca_010,  /* 11 FACE SP */
    ibuki_dmca_008,  /* 12 FOOK OKU S */
    ibuki_dmca_009,  /* 13 FOOK OKU M */
    ibuki_dmca_014,  /* 14 FOOK OKU L */
    ibuki_dmca_015,  /* 15 FOOK OKU SP */
    ibuki_dmca_008,  /* 16 FOOK TEMAE S */
    ibuki_dmca_009,  /* 17 FOOK TEMAE M */
    ibuki_dmca_018,  /* 18 FOOK TEMAE L */
    ibuki_dmca_019,  /* 19 FOOK TEMAE SP */
    ibuki_dmca_008,  /* 20 UPPER S */
    ibuki_dmca_009,  /* 21 UPPER M */
    ibuki_dmca_022,  /* 22 UPPER L */
    ibuki_dmca_022,  /* 23 UPPER SP */
    ibuki_dmca_024,  /* 24 NOUTEN S */
    ibuki_dmca_025,  /* 25 NOUTEN M */
    ibuki_dmca_026,  /* 26 NOUTEN L */
    ibuki_dmca_026,  /* 27 NOUTEN SP */
    ibuki_dmca_024,  /* 28 BODY BROW S */
    ibuki_dmca_025,  /* 29 BODY BROW M */
    ibuki_dmca_030,  /* 30 BODY BROW L */
    ibuki_dmca_030,  /* 31 BODY BROW SP */
    ibuki_dmca_024,  /* 32 BODY UPPER S */
    ibuki_dmca_025,  /* 33 BODY UPPER M */
    ibuki_dmca_034,  /* 34 BODY UPPER L */
    ibuki_dmca_034,  /* 35 BODY UPPER SP */
    ibuki_dmca_036,  /* 36 TATAKI S */
    ibuki_dmca_036,  /* 37 TATAKI M */
    ibuki_dmca_036,  /* 38 TATAKI L */
    ibuki_dmca_036,  /* 39 TATAKI SP */
    ibuki_dmca_036,  /* 40 TATAKI V. S */
    ibuki_dmca_036,  /* 41 TATAKI V. M */
    ibuki_dmca_036,  /* 42 TATAKI V. L */
    ibuki_dmca_036,  /* 43 TATAKI V. SP */
    ibuki_dmca_008,  /* 44 NOBASITA TE S */
    ibuki_dmca_009,  /* 45 NOBASITA TE M */
    ibuki_dmca_010,  /* 46 NOBASITA TE L */
    ibuki_dmca_010,  /* 47 NOBASITA TE SP */
    ibuki_dmca_048,  /* 48 KAGAMI S */
    ibuki_dmca_049,  /* 49 KAGAMI M */
    ibuki_dmca_050,  /* 50 KAGAMI L */
    ibuki_dmca_050,  /* 51 KAGAMI SP */
    ibuki_dmca_052,  /* 52 KGM TATAKI S */
    ibuki_dmca_052,  /* 53 KGM TATAKI M */
    ibuki_dmca_052,  /* 54 KGM TATAKI L */
    ibuki_dmca_052,  /* 55 KGM TATAKI SP */
    ibuki_dmca_052,  /* 56 KGM TTKI V.S */
    ibuki_dmca_052,  /* 57 KGM TTKI V.M */
    ibuki_dmca_052,  /* 58 KGM TTKI V.L */
    ibuki_dmca_052,  /* 59 KGM TTKI V.SP */
    ibuki_dmca_060,  /* 60 NEKOROBI S */
    ibuki_dmca_060,  /* 61 NEKOROBI M */
    ibuki_dmca_060,  /* 62 NEKOROBI L */
    ibuki_dmca_060,  /* 63 NEKOROBI SP */
    ibuki_dmca_064,  /* 64 OKIAGARI */
    ibuki_dmca_065,  /* 65 OKIAGARI F */
    ibuki_dmca_066,  /* 66 OKIAGARI B */
    ibuki_dmca_067,  /* 67 LOSE NO STAND */
    ibuki_dmca_068,  /* 68 LOSE SONABA */
    ibuki_dmca_068,  /* 69 LOSE KAGAMI */
    ibuki_dmca_070,  /* 70 PIYO */
    ibuki_dmca_071,  /* 71 UKEMI MOVE F */
    ibuki_dmca_072,  /* 72 UKEMI MOVE R */
    ibuki_dmca_073,  /* 73 SHIMEOTASARE */
    ibuki_dmca_074,  /* 74 TATI TOUKETU S */
    ibuki_dmca_075,  /* 75 TATI TOUKETU M */
    ibuki_dmca_076,  /* 76 TATI TOUKETU L */
    ibuki_dmca_076,  /* 77 TATI TOUKETU P */
    ibuki_dmca_078,  /* 78 KGM TOUKETU S */
    ibuki_dmca_079,  /* 79 KGM TOUKETU M */
    ibuki_dmca_080,  /* 80 KGM TOUKETU L */
    ibuki_dmca_080,  /* 81 KGM TOUKETU P */
    ibuki_dmca_082,  /* 82 TATI DENGEKI S */
    ibuki_dmca_083,  /* 83 TATI DENGEKI M */
    ibuki_dmca_084,  /* 84 TATI DENGEKI L */
    ibuki_dmca_084,  /* 85 TATI DENGEKI P */
    ibuki_dmca_082,  /* 86 KGM DENGEKI S */
    ibuki_dmca_083,  /* 87 KGM DENGEKI M */
    ibuki_dmca_084,  /* 88 KGM DENGEKI L */
    ibuki_dmca_084,  /* 89 KGM DENGEKI P */
    ibuki_dmca_090,  /* 90 OKIAGARI FRONT */
    ibuki_dmca_091,  /* 91 OKIAGARI REAR */
    ibuki_dmca_008,  /* 92 TATI MOE S */
    ibuki_dmca_009,  /* 93 TATI MOE M */
    ibuki_dmca_010,  /* 94 TATI MOE L */
    ibuki_dmca_010,  /* 95 TATI MOE SP */
    ibuki_dmca_096,  /* 96 no name */
    ibuki_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 ibuki_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_000[116] = {
    L4(1, 132, 0, 0, 0, 502, 0, 0x2A89, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 503, 0, 0x2A8A, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 504, 0, 0x2A8B, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 136, 0, 0, 0, 505, 0, 0x2A86, 0, 12, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 506, 0, 0x2A87, 0, 12, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 507, 0, 0x2A88, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 508, 0, 0x2A89, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 509, 0, 0x2A85, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 510, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 511, 0, 0x2A8C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 512, 0, 0x2A8D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 513, 0, 0x2A8E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 514, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 515, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 ibuki_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_001[116] = {
    L4(1, 132, 0, 0, 0, 516, 0, 0x2A94, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 517, 0, 0x2A95, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 518, 0, 0x2A96, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 136, 0, 0, 0, 520, 0, 0x2A91, 0, 12, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 521, 0, 0x2A92, 0, 12, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 522, 0, 0x2A93, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 523, 0, 0x2A94, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 519, 0, 0x2A90, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 524, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 511, 0, 0x2A8C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 512, 0, 0x2A8D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 513, 0, 0x2A8E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 514, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 515, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 ibuki_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_002[100] = {
    L4(1, 132, 0, 0, 0, 525, 0, 0x2A9E, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 526, 0, 0x2A9F, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 527, 0, 0x2AA0, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 136, 0, 0, 0, 528, 0, 0x2A9B, 0, 13, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 529, 0, 0x2A9C, 0, 13, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 530, 0, 0x2A9D, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 531, 0, 0x2A9E, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 532, 0, 0x2A9A, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 533, 0, 0x2A99, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 534, 0, 0x2A98, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 535, 0, 0x2A97, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 536, 0, 0x2A97, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 ibuki_dmca_003_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_003[220] = {
    L6(4, 131, 0, 0, 0, 0, 0, 0x2AA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2AA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 145, 0, 0, 0, 0, 0, 0x2AA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2AA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
    L6(4, 138, 0, 0, 0, 0, 0, 0x2A91, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A92, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2A94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2A90, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A84, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2A8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 ibuki_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_004[92] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 305, 0, 0x2AC7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 306, 0, 0x2AC8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 307, 0, 0x2AC9, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 308, 0, 0x2ACA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 310, 0, 0x2ACC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 312, 0, 0x2ACE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 313, 0, 0x2ACF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 314, 0, 0x2AD0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 ibuki_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_006[92] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 315, 0, 0x2AD4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 316, 0, 0x2AD5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 307, 0, 0x2AC9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 308, 0, 0x2ACA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 309, 0, 0x2ACB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 310, 0, 0x2ACC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 311, 0, 0x2ACD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 312, 0, 0x2ACE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 313, 0, 0x2ACF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 314, 0, 0x2AD0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 ibuki_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_008[84] = {
    L4(250, 130, 0, 0, 0, 537, 0, 0x2AE3, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 135, 354, 0, 0, 538, 0, 0x2AD7, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 539, 0, 0x2AD7, 0, 287, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 539, 0, 0x2AD7, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 540, 0, 0x2AD6, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 541, 0, 0x2AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 542, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 543, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 544, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 ibuki_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_009[92] = {
    L4(250, 130, 0, 0, 0, 545, 0, 0x2AD8, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 136, 354, 0, 0, 546, 0, 0x2ADA, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 547, 0, 0x2AD9, 0, 288, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 548, 0, 0x2AD8, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 549, 0, 0x2AD7, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 550, 0, 0x2AD6, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 551, 0, 0x2AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 552, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 553, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 554, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 ibuki_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_010[124] = {
    L4(250, 130, 0, 0, 0, 555, 0, 0x2ADB, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 140, 355, 0, 0, 556, 0, 0x2ADB, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 557, 0, 0x2ADC, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 558, 0, 0x2ADD, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 559, 0, 0x2AE7, 0, 290, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 560, 0, 0x2AE6, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 561, 0, 0x2ADE, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 562, 0, 0x2ADF, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 563, 0, 0x2AE0, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 564, 0, 0x2AE1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 565, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 566, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 567, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 568, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 ibuki_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_018[124] = {
    L4(250, 130, 0, 0, 0, 586, 0, 0x2ADB, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 139, 355, 0, 0, 586, 0, 0x2ADB, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 587, 0, 0x2ADC, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 588, 0, 0x2ADD, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 589, 0, 0x2AE8, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 590, 0, 0x2AE9, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 591, 0, 0x2AEA, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 592, 0, 0x2AEC, 0, 289, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 593, 0, 0x2AED, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 594, 0, 0x2AEE, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 595, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 596, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 597, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 598, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 ibuki_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_019[124] = {
    L4(250, 130, 0, 0, 0, 585, 0, 0x2AE5, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 139, 355, 0, 0, 586, 0, 0x2ADB, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 587, 0, 0x2ADC, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 588, 0, 0x2ADD, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 589, 0, 0x2AE8, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 590, 0, 0x2AE9, 0, 290, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 591, 0, 0x2AEA, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 592, 0, 0x2AEC, 0, 289, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 593, 0, 0x2AED, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 594, 0, 0x2AEE, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 595, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 596, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 597, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 598, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 ibuki_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_014[140] = {
    L4(250, 130, 0, 0, 0, 571, 0, 0x2AD8, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 141, 355, 0, 0, 572, 0, 0x2AD9, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 572, 0, 0x2AD9, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 572, 0, 0x2AD9, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 573, 0, 0x2ADA, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 574, 0, 0x2AEB, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 575, 0, 0x2AEF, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 576, 0, 0x2AE9, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 577, 0, 0x2AEA, 0, 288, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 578, 0, 0x2AEC, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 579, 0, 0x2AED, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 580, 0, 0x2AEE, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 581, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 582, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 583, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 584, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 ibuki_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_015[140] = {
    L4(250, 130, 0, 0, 0, 569, 0, 0x2AD6, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 141, 355, 0, 0, 570, 0, 0x2AD7, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 571, 0, 0x2AD8, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 572, 0, 0x2AD9, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 573, 0, 0x2ADA, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 574, 0, 0x2AEB, 0, 290, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 575, 0, 0x2AEF, 0, 290, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 576, 0, 0x2AE9, 0, 290, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 577, 0, 0x2AEA, 0, 290, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 578, 0, 0x2AEC, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 579, 0, 0x2AED, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 580, 0, 0x2AEE, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 581, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 582, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 583, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 584, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 ibuki_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_022[100] = {
    L4(250, 130, 0, 0, 0, 599, 0, 0x2B48, 0, 283, 0, 0, 0, 0, 0),
    L4(2, 137, 355, 0, 0, 600, 0, 0x2AF9, 0, 284, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 601, 0, 0x2AFA, 0, 284, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 602, 0, 0x2AFB, 0, 285, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 603, 0, 0x2AFC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 604, 0, 0x2AFD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 605, 0, 0x2A45, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 606, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 607, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 608, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 609, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 ibuki_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_026[148] = {
    L4(250, 130, 0, 0, 0, 629, 0, 0x2AF2, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 143, 354, 0, 0, 630, 0, 0x2AF1, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 631, 0, 0x2AF2, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 632, 0, 0x2AF3, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 633, 0, 0x2AF2, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 634, 0, 0x2AF3, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 635, 0, 0x2AF2, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 636, 0, 0x2AF3, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 637, 0, 0x2AF4, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 638, 0, 0x2AF5, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 639, 0, 0x2AF6, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 640, 0, 0x2AF7, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 641, 0, 0x2A46, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 642, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 643, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 644, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 645, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 ibuki_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_034[140] = {
    L4(250, 130, 0, 0, 0, 664, 0, 0x2AFE, 0, 291, 0, 0, 0, 0, 0),
    L4(6, 142, 355, 0, 0, 665, 0, 0x2AFF, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 666, 0, 0x2B10, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 667, 0, 0x2B11, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 668, 0, 0x2B12, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 669, 0, 0x2B13, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 670, 0, 0x2B14, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 671, 0, 0x2B15, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 672, 0, 0x2B16, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 673, 0, 0x2A3E, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 674, 0, 0x2A45, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 675, 0, 0x2A46, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 676, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 677, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 678, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 679, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 ibuki_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_036[44] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 680, 0, 0x2B3B, 0, 294, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 681, 0, 0x2B3B, 0, 294, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 682, 0, 0x2B3C, 0, 294, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 ibuki_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_024[84] = {
    L4(250, 130, 0, 0, 0, 610, 0, 0x2B0B, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 135, 354, 0, 0, 611, 0, 0x2B08, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 611, 0, 0x2B08, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 612, 0, 0x2B07, 0, 291, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 613, 0, 0x2B06, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 614, 0, 0x2B05, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 615, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 616, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 617, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M, 29 BODY BROW M, 33 BODY UPPER M */
const u16 ibuki_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_025[100] = {
    L4(250, 130, 0, 0, 0, 618, 0, 0x2B0C, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 137, 354, 0, 0, 619, 0, 0x2B09, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 620, 0, 0x2B0A, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 621, 0, 0x2B09, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 622, 0, 0x2B08, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 623, 0, 0x2B07, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 624, 0, 0x2B06, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 625, 0, 0x2B05, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 626, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 627, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 628, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 ibuki_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_030[156] = {
    L4(250, 130, 0, 0, 0, 646, 0, 0x2B0D, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 144, 355, 0, 0, 647, 0, 0x2B0E, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 648, 0, 0x2B0F, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 649, 0, 0x2B0E, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 650, 0, 0x2B10, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 651, 0, 0x2B11, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 652, 0, 0x2B12, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 653, 0, 0x2B13, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 654, 0, 0x2B14, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 655, 0, 0x2B15, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 656, 0, 0x2B16, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 657, 0, 0x2A3E, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 658, 0, 0x2A45, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 659, 0, 0x2A46, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 660, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 661, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 662, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 663, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 ibuki_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_048[108] = {
    L4(250, 130, 0, 0, 0, 694, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(1, 135, 354, 0, 0, 695, 0, 0x2CDC, 0, 295, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 695, 0, 0x2CDC, 0, 295, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 696, 0, 0x2CDD, 0, 295, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 697, 0, 0x2CDE, 0, 295, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 698, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 699, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 700, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 701, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 702, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 703, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 704, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 ibuki_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_049[108] = {
    L4(250, 130, 0, 0, 0, 694, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(1, 136, 354, 0, 0, 695, 0, 0x2CDC, 0, 295, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 695, 0, 0x2CDC, 0, 296, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 696, 0, 0x2CDD, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 697, 0, 0x2CDE, 0, 295, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 698, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 699, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 700, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 701, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 702, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 703, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 704, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 ibuki_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_050[140] = {
    L4(250, 130, 0, 0, 0, 705, 0, 0x2CDC, 0, 295, 0, 0, 0, 0, 0),
    L4(1, 141, 355, 0, 0, 706, 0, 0x2CDC, 0, 296, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 706, 0, 0x2CDC, 0, 297, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 12, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 707, 0, 0x2B11, 0, 297, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 708, 0, 0x2B12, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 709, 0, 0x2B13, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 710, 0, 0x2B14, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 711, 0, 0x2B15, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 712, 0, 0x2B16, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 713, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 714, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 715, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 716, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 717, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 718, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 719, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 ibuki_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_052[36] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 681, 0, 0x2B3B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 682, 0, 0x2B3C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 ibuki_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_060[76] = {
    L4(250, 130, 0, 0, 0, 720, 0, 0x2B02, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 2, 355, 0, 0, 721, 0, 0x2B03, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 722, 0, 0x2B04, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 723, 0, 0x2B2B, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 724, 0, 0x2B2C, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 725, 0, 0x2CD8, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 725, 0, 0x2CD9, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 ibuki_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_064[172] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 978, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 978, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 982, 0, 0x2B6A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 983, 0, 0x2B6B, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 984, 0, 0x2B6C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 985, 0, 0x2B6D, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 986, 0, 0x2B6E, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 987, 0, 0x2B6F, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 988, 0, 0x2B70, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 989, 0, 0x2A45, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 990, 0, 0x2A46, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 991, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 992, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 993, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 993, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 ibuki_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_065[268] = {
    CMD(CM_RJA, 1, 65, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1818, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1819, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1820, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1821, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1822, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1823, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1824, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1825, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1826, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1827, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1828, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1829, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1830, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1831, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1832, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 111, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 111, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 227, 0, 0x2A6A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 ibuki_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_066[268] = {
    CMD(CM_RJA, 1, 66, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1836, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1837, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1838, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1839, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1840, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1841, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1842, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1843, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1844, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1845, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1846, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1847, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1848, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1833, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1834, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 111, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 111, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 227, 0, 0x2A6A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 ibuki_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_067[36] = {
    L4(3, 0, 0, 0, 0, 725, 0, 0x2CD8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 725, 0, 0x2CD9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 725, 0, 0x2CDA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 725, 0, 0x2CDA, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 ibuki_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_068[244] = {
    L6(250, 130, 0, 0, 0, 726, 0, 0x2B5C, 0, 245, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(250, 131, 0, 0, 0, 727, 0, 0x2B5D, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 728, 0, 0x2B5E, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 729, 0, 0x2B5F, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 730, 0, 0x2B60, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 731, 0, 0x2B61, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 732, 0, 0x2B62, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 733, 0, 0x2B63, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 734, 0, 0x2B64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 735, 0, 0x2B65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 736, 0, 0x2B66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 737, 0, 0x2B67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 288, 0, 0, 738, 0, 0x2B2B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 739, 0, 0x2B27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 740, 0, 0x2B28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 741, 0, 0x2B29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 742, 0, 0x2B2A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 743, 0, 0x2B2B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 744, 0, 0x2B2C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 67, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 ibuki_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_070[100] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 745, 0, 0x2B3D, 0, 201, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 746, 0, 0x2B3E, 0, 201, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 747, 0, 0x2B3F, 0, 201, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 748, 0, 0x2B40, 0, 392, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 749, 0, 0x2B41, 0, 392, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 750, 0, 0x2B42, 0, 392, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 751, 0, 0x2B43, 0, 209, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 752, 0, 0x2B44, 0, 393, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 753, 0, 0x2B45, 0, 393, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 754, 0, 0x2B46, 0, 393, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 ibuki_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_071[276] = {
    L4(1, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 71, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 358, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1818, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1819, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1820, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1821, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1822, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1823, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1824, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1825, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1826, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1827, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1828, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1829, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1830, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1831, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1832, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(3, 12, 0, 0, 0, 225, 0, 0x2A68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 227, 0, 0x2A6A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 ibuki_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_072[276] = {
    L4(1, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 72, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 358, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(1, 1, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1836, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1837, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1838, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1839, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1840, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1841, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1842, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1843, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1844, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1845, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1846, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1847, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1848, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1833, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1834, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(3, 12, 0, 0, 0, 225, 0, 0x2A68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 227, 0, 0x2A6A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 ibuki_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_073[196] = {
    L4(3, 0, 353, 0, 0, 755, 0, 0x2B5C, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 756, 0, 0x2B5D, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 757, 0, 0x2B5E, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 758, 0, 0x2B5F, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 759, 0, 0x2B60, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 289, 0, 0, 760, 0, 0x2B61, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 761, 0, 0x2B62, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 762, 0, 0x2B63, 0, 245, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 763, 0, 0x2B64, 0, 245, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 763, 0, 0x2B64, 0, 0, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 764, 0, 0x2B65, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 765, 0, 0x2B66, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 766, 0, 0x2B67, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 288, 0, 0, 767, 0, 0x2B2B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 768, 0, 0x2B27, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 769, 0, 0x2B28, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 770, 0, 0x2B29, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 771, 0, 0x2B2A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 772, 0, 0x2B2B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 773, 0, 0x2B2C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 774, 0, 0x2CD8, 0, 0, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 774, 0, 0x2CD9, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 774, 0, 0x2CDA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 774, 0, 0x2CDA, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 ibuki_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_074[52] = {
    L4(250, 130, 0, 0, 0, 537, 0, 0x2AE3, 0, 287, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 537, 0, 0x2AE3, 0, 287, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 541, 0, 0x2AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 542, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 543, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 544, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 ibuki_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_075[52] = {
    L4(250, 130, 0, 0, 0, 545, 0, 0x2AE4, 0, 287, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 545, 0, 0x2AE4, 0, 288, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 551, 0, 0x2AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 552, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 553, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 554, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 ibuki_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_076[52] = {
    L4(250, 130, 0, 0, 0, 585, 0, 0x2AE5, 0, 287, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 585, 0, 0x2AE5, 0, 288, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 565, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 566, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 567, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 568, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 ibuki_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_078[76] = {
    L4(250, 130, 0, 0, 0, 694, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 694, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 698, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 699, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 700, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 701, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 702, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 703, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 704, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 ibuki_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_079[68] = {
    L4(250, 130, 0, 0, 0, 694, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 694, 0, 0x2CDB, 0, 296, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 699, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 700, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 701, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 702, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 703, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 704, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 ibuki_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_080[60] = {
    L4(250, 130, 0, 0, 0, 705, 0, 0x2CDB, 0, 295, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 705, 0, 0x2CDB, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 715, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 716, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 717, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 718, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 719, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 ibuki_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 ibuki_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 ibuki_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 ibuki_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_090[268] = {
    CMD(CM_RJA, 1, 65, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1818, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1819, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1820, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1821, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1822, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1823, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1824, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1825, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1826, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1827, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1828, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1829, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1830, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1831, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1832, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1817, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 225, 0, 0x2A68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 226, 0, 0x2A69, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 ibuki_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_091[268] = {
    CMD(CM_RJA, 1, 66, 25), 0, 0, 0, 0,
    CMD(CM_SETR, 3, 2, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 979, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 980, 0, 0x2B68, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 981, 0, 0x2B69, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1836, 0, 0x2D65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1837, 0, 0x2D64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1838, 0, 0x2D63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1839, 0, 0x2D62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1840, 0, 0x2D61, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1841, 0, 0x2D60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1842, 0, 0x2D5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1843, 0, 0x2D5E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1844, 0, 0x2D5D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1845, 0, 0x2D5C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1846, 0, 0x2D5B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1847, 0, 0x2D5A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1848, 0, 0x2D59, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1833, 0, 0x2D58, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1834, 0, 0x2D57, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1835, 0, 0x2D56, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 16), 0, 0, 0, 0,
    L4(1, 111, 0, 0, 0, 225, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 111, 0, 0, 0, 226, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 111, 0, 0, 0, 227, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 ibuki_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_096[44] = {
    L4(3, 2, 355, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 725, 0, 0x2CDA, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 ibuki_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_dmca_097[44] = {
    L4(3, 2, 355, 0, 0, 725, 0, 0x2CDA, 0, 250, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 725, 0, 0x2CDA, 0, 250, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 725, 0, 0x2CDA, 0, 250, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 725, 0, 0x2CDA, 0, 250, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 725, 0, 0x2CDA, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const ibuki_btca[37] = {
    ibuki_btca_000,  /* 0 AIR NORMAL */
    ibuki_btca_001,  /* 1 ASIBARAI SIRI */
    ibuki_btca_002,  /* 2 ASIB TUNNOMERI */
    ibuki_btca_003,  /* 3 NOKEZORI */
    ibuki_btca_004,  /* 4 KUNOJI */
    ibuki_btca_005,  /* 5 KIRIMOMI */
    ibuki_btca_006,  /* 6 UPPER */
    ibuki_btca_007,  /* 7 BODY UPPER */
    ibuki_btca_008,  /* 8 HARAYARARE */
    ibuki_btca_009,  /* 9 TATAKI AIR */
    ibuki_btca_010,  /* 10 TTKI V. AIR */
    ibuki_btca_011,  /* 11 HUMI ASIB */
    ibuki_btca_012,  /* 12 FACE */
    ibuki_btca_013,  /* 13 ASIB SIRI LOSE */
    ibuki_btca_014,  /* 14 ASIB TUN LOSE */
    ibuki_btca_015,  /* 15 DENKI */
    ibuki_btca_016,  /* 16 KUNOJI NOKE */
    ibuki_btca_017,  /* 17 BODY UPPER SP */
    ibuki_btca_018,  /* 18 HANEAGARI */
    ibuki_btca_019,  /* 19 TOUKETSU A */
    ibuki_btca_020,  /* 20 BODY SLAM */
    ibuki_btca_021,  /* 21 IPPONZEOI */
    ibuki_btca_022,  /* 22 TOMOE RYU */
    ibuki_btca_023,  /* 23 MONKEY FLIP */
    ibuki_btca_023,  /* 24 TOMOE ORO */
    ibuki_btca_025,  /* 25 SNAKE FANG */
    ibuki_btca_026,  /* 26 FLANKEN.S */
    ibuki_btca_027,  /* 27 KISHINRIKI */
    ibuki_btca_028,  /* 28 SPLASH.M */
    ibuki_btca_029,  /* 29 HARAIGOSHI */
    ibuki_btca_030,  /* 30 ALEX B.D */
    ibuki_btca_031,  /* 31 GILL */
    ibuki_btca_032,  /* 32 HANEKAERI HARA */
    ibuki_btca_033,  /* 33 S HANEAGARI */
    ibuki_btca_034,  /* 34 TATUMAKIZANKU */
    ibuki_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 ibuki_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_000[68] = {
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1020, 0, 0x2AF8, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 354, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 1020, 0, 0x2AF8, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 1020, 0, 0x2AF8, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 ibuki_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 964, 0, 0x2B32, 0, 344, 0, 0, 0, 0, 0),
    L4(5, 0, 355, 0, 0, 965, 13, 0x2B33, 0, 345, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 966, 13, 0x2B34, 0, 346, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 967, 9, 0x2B35, 0, 347, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 ibuki_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_002[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 964, 0, 0x2B32, 0, 344, 0, 0, 0, 0, 0),
    L4(6, 0, 354, 0, 0, 965, 0, 0x2B33, 0, 345, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 966, 0, 0x2B34, 0, 346, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 967, 0, 0x2B35, 0, 347, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 ibuki_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_003[116] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 ibuki_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_004[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1006, 0, 0x2B0D, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 1007, 0, 0x2B0E, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1008, 0, 0x2B0F, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1553, 0, 0x2B0F, 0, 360, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 ibuki_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_005[148] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1281, 0, 0x2B47, 0, 361, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 1282, 0, 0x2B48, 0, 362, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1283, 0, 0x2B49, 0, 363, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1284, 0, 0x2B4A, 0, 364, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1285, 0, 0x2B4B, 0, 365, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1286, 0, 0x2B4C, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1287, 0, 0x2B4D, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1288, 0, 0x2B4E, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1289, 0, 0x2B4F, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1290, 0, 0x2B50, 0, 370, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1291, 0, 0x2B51, 0, 371, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1292, 0, 0x2B52, 0, 372, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1293, 0, 0x2B53, 0, 373, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1294, 0, 0x2B54, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1295, 0, 0x2B55, 0, 375, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1296, 0, 0x2B56, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 ibuki_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_006[124] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 ibuki_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_007[124] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 ibuki_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_008[124] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 ibuki_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_009[44] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1266, 0, 0x2B3A, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 681, 0, 0x2B3B, 0, 378, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 682, 0, 0x2B3C, 0, 379, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 ibuki_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_010[44] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1266, 0, 0x2B3A, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 355, 0, 0, 681, 0, 0x2B3B, 0, 378, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 682, 0, 0x2B3C, 0, 379, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 ibuki_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_011[52] = {
    CMD(CM_RJA, 7, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1306, 0, 0x2B37, 0, 380, 0, 0, 0, 0, 0),
    L4(6, 0, 354, 0, 0, 1306, 0, 0x2B37, 0, 380, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1307, 0, 0x2B38, 0, 381, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1308, 0, 0x2B39, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 ibuki_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_012[124] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 ibuki_btca_013_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_013[52] = {
    CMD(CM_RJA, 7, 25, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 964, 0, 0x2B32, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 965, 0, 0x2B33, 0, 345, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 966, 0, 0x2B34, 0, 346, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 967, 0, 0x2B35, 0, 347, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 ibuki_btca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_014[52] = {
    CMD(CM_RJA, 7, 25, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 964, 0, 0x2B32, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 354, 0, 0, 965, 0, 0x2B33, 0, 345, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 966, 0, 0x2B34, 0, 346, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 967, 0, 0x2B35, 0, 347, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 ibuki_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_015[76] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x2D4A, 0, 383, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2D4A, 0, 383, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4B, 0, 383, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2D4A, 0, 383, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2D4C, 0, 383, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 355, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 ibuki_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_016[84] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 1006, 0, 0x2B0D, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 1007, 0, 0x2B0E, 0, 360, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1008, 0, 0x2B0F, 0, 360, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 ibuki_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_017[172] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 355, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 ibuki_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_018[140] = {
    CMD(CM_RJA, 6, 18, 6), 0, 0, 0, 0,
    L4(4, 0, 355, 0, 0, 1271, 0, 0x2B24, 0, 111, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 1272, 0, 0x2B25, 0, 111, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1003, 10, 0x2B1F, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1002, 15, 0x2B1E, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 1273, 0, 0x2B26, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1275, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1276, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1277, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1278, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1279, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1280, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1018, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 ibuki_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_019[28] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 545, 0, 0x2AE4, 0, 384, 0, 0, 0, 0, 0),
    L4(250, 0, 355, 0, 0, 545, 0, 0x2AE4, 0, 384, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 ibuki_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_020[20] = {
    L4(4, 0, 0, 0, 0, 683, 0, 0x2CCE, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 ibuki_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_021[20] = {
    L4(4, 0, 0, 0, 0, 1797, 0, 0x2B2A, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 ibuki_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_022[60] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1776, 0, 0x2B38, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1777, 0, 0x2B6C, 0, 137, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1778, 0, 0x2B6B, 0, 137, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1779, 0, 0x2B20, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1779, 0, 0x2B20, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP, 24 TOMOE ORO */
const u16 ibuki_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_023[60] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 2120, 0, 0x2B6B, 0, 137, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 2121, 0, 0x2B20, 0, 137, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 2122, 0, 0x2B26, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 2123, 0, 0x2B57, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 2123, 0, 0x2B57, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 ibuki_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_025[60] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 137, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 ibuki_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_026[52] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 1785, 0, 0x2B6B, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1786, 0, 0x2B20, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1787, 0, 0x2B26, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1788, 0, 0x2B57, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1796, 0, 0x2B57, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 ibuki_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_027[76] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1000, 15, 0x2B1C, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1001, 15, 0x2B1D, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1002, 15, 0x2B1E, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1003, 15, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 ibuki_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_028[52] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 ibuki_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_029[36] = {
    CMD(CM_RJA, 7, 24, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 ibuki_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_030[92] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1001, 15, 0x2B1D, 0, 137, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 1002, 15, 0x2B1E, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1003, 10, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 ibuki_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 964, 0, 0x2B32, 0, 137, 0, 0, 0, 0, 0),
    L4(7, 0, 355, 0, 0, 965, 0, 0x2B33, 0, 137, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 966, 0, 0x2B34, 0, 137, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 967, 0, 0x2B35, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 ibuki_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_032[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 ibuki_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_033[124] = {
    L4(250, 130, 0, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 355, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1275, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1275, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1276, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1277, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1278, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1279, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1280, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1018, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 ibuki_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_034[124] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 994, 0, 0x2AE5, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 355, 0, 0, 995, 0, 0x2B17, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 996, 0, 0x2B18, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 997, 0, 0x2B19, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 998, 0, 0x2B1A, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 999, 0, 0x2B1B, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1000, 0, 0x2B1C, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 ibuki_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_btca_035[76] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1000, 15, 0x2B1C, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1001, 15, 0x2B1D, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1002, 15, 0x2B1E, 0, 137, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1003, 15, 0x2B1F, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 24 entries */
const u16* const ibuki_caca[25] = {
    ibuki_caca_000,  /* 0 CATCH 1 */
    ibuki_caca_000,  /* 1 CATCH 2 */
    ibuki_caca_000,  /* 2 CATCH 3 */
    ibuki_caca_000,  /* 3 CATCH 4 */
    ibuki_caca_004,  /* 4 CATCH 5 */
    ibuki_caca_004,  /* 5 CATCH 6 */
    ibuki_caca_004,  /* 6 CATCH 7 */
    ibuki_caca_007,  /* 7 CATCH 8 */
    ibuki_caca_008,  /* 8 CATCH 9 */
    ibuki_caca_009,  /* 9 CATCH 10 */
    ibuki_caca_010,  /* 10 CATCH 11 */
    ibuki_caca_011,  /* 11 CATCH 12 */
    ibuki_caca_011,  /* 12 CATCH 13 */
    ibuki_caca_011,  /* 13 CATCH 14 */
    ibuki_caca_011,  /* 14 CATCH 15 */
    ibuki_caca_015,  /* 15 CATCH 16 */
    ibuki_caca_015,  /* 16 CATCH 17 */
    ibuki_caca_015,  /* 17 CATCH 18 */
    ibuki_caca_015,  /* 18 CATCH 19 */
    ibuki_caca_019,  /* 19 CATCH 20 */
    ibuki_caca_020,  /* 20 CATCH 21 */
    ibuki_caca_021,  /* 21 CATCH 22 */
    ibuki_caca_022,  /* 22 CATCH 23 */
    ibuki_caca_023,  /* 23 CATCH 24 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 ibuki_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 ibuki_caca_000[220] = {
    CMD(CM_NGDA, 1542, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 317, 0, 0x2D3D, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 318, 0, 0x2D3E, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 319, 0, 0x2D3F, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 320, 0, 0x2D40, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 357, 0, 0, 321, 0, 0x2D41, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 322, 0, 0x2D42, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 323, 0, 0x2D43, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 324, 0, 0x2D44, -69, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 325, 0, 0x2D45, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 326, 0, 0x2D46, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 327, 0, 0x2D47, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 328, 0, 0x2D48, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 329, 0, 0x2D49, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 6, 0, 0, 0, 330, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 331, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 332, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 333, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7 */
const u16 ibuki_caca_004_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 1) };
const u16 ibuki_caca_004[496] = {
    CMD(CM_NGDA, 6, 8, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 264, 0, 0, 334, 0, 0x2CF4, 0, 0, 0, 0, 0, 1, 47, 0, 312, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 335, 0, 0x2CF6, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 336, 0, 0x2CF7, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 337, 0, 0x2CF8, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 338, 0, 0x2CF9, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 339, 0, 0x2CFA, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 340, 0, 0x2CFB, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 341, 0, 0x2CFD, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(2, 0, 264, 0, 0, 342, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 343, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 344, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 0, 259, 0, 0, 345, 0, 0x2D03, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 345, 0, 0x2D03, -54, 0, 0, 128, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 3, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 1, 11, 0, 576, 0, 0, 0),
    L6(1, 4, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 9, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    CMD(CM_MXYT, 53, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 4, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 6, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 1, 348, 0, 0x2D06, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 1, 349, 0, 0x2D07, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 1, 350, 0, 0x2D08, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 1, 351, 0, 0x2D09, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 1, 352, 0, 0x2D0A, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 353, 0, 0x2A65, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 354, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 1, 0, 355, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 273, 0, 0, 356, 0, 0x2A3D, 0, 17, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(4, 2, 0, 0, 0, 357, 0, 0x2A3E, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 358, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 359, 0, 0x2A45, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 360, 0, 0x2A45, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 361, 0, 0x2A46, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 362, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 363, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 364, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 364, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 ibuki_caca_007_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 ibuki_caca_007[556] = {
    CMD(CM_NGDA, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 21, 264, 0, 0, 1315, 0, 0x2D9A, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9B, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9C, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9D, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9E, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9F, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 0, 357, 0, 0, 18, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 259, 0, 0, 19, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 21, 0, 0x2DA1, -51, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    CMD(CM_QUAX, 6, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 3, 0, 0, 0, 22, 0, 0x2DA2, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 22, 0, 0x2DA2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_S123, 4, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 279, 0, 0, 23, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 24, 0, 0x2DA4, 0, 1, 0, 0, 0, 30, 33, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 24, 0, 0x2DA4, 0, 1, 0, 0, 0, 30, 34, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 25, 0, 0x2DA2, 0, 1, 0, 0, 0, 30, 35, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 22, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 23, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 24, 0, 0x2DA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 25, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 26, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 27, 0, 0x2DA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 30, 0, 0x2DA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 31, 0, 0x2DA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 32, 0, 0x2DA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 33, 0, 0x2DA7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 34, 0, 0x2DA8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 35, 0, 0x2DA9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 36, 0, 0x2DAA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 37, 0, 0x2DAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 38, 0, 0x2DAC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 294, 0, 0x2B8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 295, 0, 0x2B8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 296, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 297, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 ibuki_caca_008_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 ibuki_caca_008[196] = {
    CMD(CM_NGDA, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 21, 264, 0, 0, 1315, 0, 0x2D9A, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9B, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9C, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9D, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9E, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9F, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 0, 357, 0, 0, 18, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 259, 0, 0, 19, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 21, 0, 0x2DA1, -91, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    CMD(CM_JPSS, 2, 7, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 ibuki_caca_009_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 ibuki_caca_009[196] = {
    CMD(CM_NGDA, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 21, 264, 0, 0, 1315, 0, 0x2D9A, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9B, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9C, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D9D, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9E, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9F, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 0, 357, 0, 0, 18, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 259, 0, 0, 19, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 21, 0, 0x2DA1, -92, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    CMD(CM_JPSS, 2, 7, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11 */
const u16 ibuki_caca_010_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 ibuki_caca_010[676] = {
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 20, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NGDA, 0, 35, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 1315, 0, 0x2D9A, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2D9B, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2D9C, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2D9D, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2D9E, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2D9F, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 319, 0, 0, 18, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 19, 0, 0x2DA0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 259, 0, 0, 20, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 21, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 21, 0, 0x2DA1, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 39, 0, 0x2DA2, 0, 0, 0, 0, 0, 1, 57, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x2DA3, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA3, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x2DA4, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA4, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 42, 0, 0x2DA2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2DA2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 43, 0, 0x2DA3, -53, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x2DA3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x2DA4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_S123, 4, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 279, 0, 0, 44, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA4, 0, 1, 0, 0, 0, 30, 33, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 45, 0, 0x2DA2, 0, 1, 0, 0, 0, 30, 34, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA2, 0, 1, 0, 0, 0, 30, 35, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 46, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 47, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 48, 0, 0x2DA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 28, 0, 0x2DA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x2DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 30, 0, 0x2DA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 88, 0, 0, 0, 31, 0, 0x2DA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 32, 0, 0x2DA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 9, 0, 0, 0, 33, 0, 0x2DA7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 34, 0, 0x2DA8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 35, 0, 0x2DA9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 36, 0, 0x2DAA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 37, 0, 0x2DAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 38, 0, 0x2DAC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 294, 0, 0x2B8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 295, 0, 0x2B8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 296, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 297, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 298, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 CATCH 12, 12 CATCH 13, 13 CATCH 14, 14 CATCH 15 */
const u16 ibuki_caca_011_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 ibuki_caca_011[52] = {
    CMD(CM_NGDA, 1542, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 317, 0, 0x2D3D, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(8, 6, 0, 0, 0, 318, 0, 0x2D3E, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 CATCH 16, 16 CATCH 17, 17 CATCH 18, 18 CATCH 19 */
const u16 ibuki_caca_015_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 ibuki_caca_015[388] = {
    CMD(CM_NGDA, 1542, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 1849, 0, 0x2D6A, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(5, 2, 0, 0, 0, 1850, 0, 0x2D6A, -105, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 1851, 0, 0x2D6B, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(6, 4, 0, 0, 0, 1852, 0, 0x2D6C, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 1853, 0, 0x2D6D, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 1854, 0, 0x2D6E, -129, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(8, 3, 0, 0, 0, 1855, 0, 0x2D6F, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 1856, 0, 0x2D70, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 1857, 0, 0x2D71, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 104, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 1, 0, 0, 0, 209, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 210, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 211, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 212, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 213, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 214, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 215, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 216, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 217, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 218, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 219, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 220, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 221, 0, 0x2A81, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 222, 0, 0x2A82, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 CATCH 20 */
const u16 ibuki_caca_019_head[4] = { HEAD(6, 20, 16, 0, 0, 0, 0) };
const u16 ibuki_caca_019[112] = {
    CMD(CM_NGDA, 1536, 45, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 1, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 22, 0, 0, 0, 1946, 0, 0x2DED, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(4, 2, 0, 0, 0, 1946, 0, 0x2DED, -159, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 3, 0, 2, 0, 0, 0, 0x2DEF, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(1, 9, 369, 2, 0, 0, 0, 0x2DEF, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(3, 1, 0, 2, 0, 0, 0, 0x2DF0, 0, 249, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_S123, 4, 30, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 20, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 CATCH 21 */
const u16 ibuki_caca_020_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_caca_020[148] = {
    L4(3, 0, 0, 2, 0, 0, 0, 0x2DF1, 0, 249, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 2, 0, 0, 0, 0x2DF2, 0, 249, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 2, 0, 0, 0, 0x2DF3, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x2DF4, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2DF4, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2DF5, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2DF6, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E08, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E09, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0A, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0B, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0C, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0D, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0E, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E0F, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E10, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 CATCH 22 */
const u16 ibuki_caca_021_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 1) };
const u16 ibuki_caca_021[388] = {
    CMD(CM_NGDA, 6, 8, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 264, 0, 0, 334, 0, 0x2CF4, 0, 0, 0, 0, 0, 1, 47, 0, 312, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 335, 0, 0x2CF6, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 336, 0, 0x2CF7, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 337, 0, 0x2CF8, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 338, 0, 0x2CF9, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 339, 0, 0x2CFA, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 340, 0, 0x2CFB, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 341, 0, 0x2CFD, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(2, 0, 264, 0, 0, 342, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 343, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 344, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 0, 259, 0, 0, 345, 0, 0x2D03, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 345, 0, 0x2D03, -162, 0, 0, 128, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(1, 3, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 1, 11, 256, 576, 0, 0, 0),
    L6(1, 4, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_STOP, 2, 2, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 9, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_MXYT, 62, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 23, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 6, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 1, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 348, 0, 0x2D06, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 349, 0, 0x2D07, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 1, 350, 0, 0x2D08, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 1, 351, 0, 0x2D09, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2217, 0, 0x2C8C, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2218, 0, 0x2C8D, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2219, 0, 0x2C8E, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 1, 2220, 0, 0x2C98, -164, 255, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 CATCH 23 */
const u16 ibuki_caca_022_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 1) };
const u16 ibuki_caca_022[304] = {
    CMD(CM_NGDA, 6, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 341, 0, 0x2CFD, 0, 0, 0, 0, 0, 0, 0, 256, 456, 0, 0, 0),
    L6(1, 0, 264, 0, 0, 342, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 343, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 504, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 344, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 528, 0, 0, 0),
    L6(1, 0, 259, 0, 0, 345, 0, 0x2D03, 0, 0, 0, 0, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 345, 0, 0x2D03, -165, 0, 0, 128, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(1, 3, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 1, 11, 256, 576, 0, 0, 0),
    L6(1, 4, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_STOP, 2, 2, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 9, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_MXYT, 62, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 23, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 58, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 6, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 1, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 348, 0, 0x2D06, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 349, 0, 0x2D07, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 1, 350, 0, 0x2D08, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 1, 351, 0, 0x2D09, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2217, 0, 0x2C8C, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2218, 0, 0x2C8D, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 2219, 0, 0x2C8E, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 1, 2220, 0, 0x2C98, -164, 255, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 CATCH 24 */
const u16 ibuki_caca_023_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 1) };
const u16 ibuki_caca_023[424] = {
    CMD(CM_NGDA, 6, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 341, 0, 0x2CFD, 0, 0, 0, 0, 0, 0, 0, 256, 456, 0, 0, 0),
    L6(1, 0, 264, 0, 0, 342, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 343, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 504, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 344, 0, 0x2D01, 0, 0, 0, 0, 0, 0, 0, 256, 528, 0, 0, 0),
    L6(1, 0, 259, 0, 0, 345, 0, 0x2D03, 0, 0, 0, 0, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 345, 0, 0x2D03, -166, 0, 0, 128, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(1, 3, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 1, 11, 256, 576, 0, 0, 0),
    L6(1, 4, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_STOP, 2, 2, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 9, 0, 1, 0, 346, 0, 0x2D04, 0, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    CMD(CM_MXYT, 127, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 23, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 6, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 1, 0, 1, 1, 347, 0, 0x2D05, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 348, 0, 0x2D06, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 1, 349, 0, 0x2D07, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 1, 350, 0, 0x2D08, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 1, 351, 0, 0x2D09, 0, 202, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 1, 352, 0, 0x2D0A, 0, 10, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 353, 0, 0x2A65, 0, 10, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 354, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 0, 0, 1, 0, 355, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 273, 0, 0, 356, 0, 0x2A3D, 0, 17, 0, 0, 0, 0, 0, 256, 0, 8, 0, 0),
    L6(4, 2, 0, 0, 0, 357, 0, 0x2A3E, 0, 17, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 358, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 359, 0, 0x2A45, 0, 2, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 360, 0, 0x2A45, 0, 2, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 361, 0, 0x2A46, 0, 17, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 362, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 363, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 364, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 364, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const ibuki_cuca[69] = {
    ibuki_cuca_000,  /* 0 ALEX ZUTUKI */
    ibuki_cuca_001,  /* 1 ALEX BODY S */
    ibuki_cuca_002,  /* 2 ALEX BACK D */
    ibuki_cuca_003,  /* 3 ALEX POWER B */
    ibuki_cuca_004,  /* 4 ALEX SLEEPER */
    ibuki_cuca_005,  /* 5 RYU SEOINAGE */
    ibuki_cuca_006,  /* 6 IBUKI */
    ibuki_cuca_007,  /* 7 DADLEY L B */
    ibuki_cuca_008,  /* 8 IBUKI KUBIORI */
    ibuki_cuca_009,  /* 9 NECRO S T */
    ibuki_cuca_010,  /* 10 RYU TOMOENAGE */
    ibuki_cuca_011,  /* 11 YUN HIZAGERI */
    ibuki_cuca_012,  /* 12 ORO KUBISIME */
    ibuki_cuca_013,  /* 13 NECRO G S */
    ibuki_cuca_014,  /* 14 DUDDLEY D S */
    ibuki_cuca_015,  /* 15 YUN MONKEY F */
    ibuki_cuca_016,  /* 16 ORO TOMOENAGE */
    ibuki_cuca_017,  /* 17 ORO NIOURIKI */
    ibuki_cuca_018,  /* 18 ORO GIGOKU G */
    ibuki_cuca_019,  /* 19 YUN */
    ibuki_cuca_020,  /* 20 NECRO SNAKE F */
    ibuki_cuca_021,  /* 21 NECRO F S */
    ibuki_cuca_022,  /* 22 IBUKI HARAIG */
    ibuki_cuca_023,  /* 23 GILL SPLASH M */
    ibuki_cuca_024,  /* 24 KEN HIZAGERI */
    ibuki_cuca_025,  /* 25 ORO KISINRIKI */
    ibuki_cuca_026,  /* 26 SEAN TACKLE */
    ibuki_cuca_027,  /* 27 ALEX HYPER B */
    ibuki_cuca_028,  /* 28 NECRO SLAM D */
    ibuki_cuca_029,  /* 29 ELENA ASINAGE */
    ibuki_cuca_030,  /* 30 GILL IMPACT C */
    ibuki_cuca_031,  /* 31 ALEX S H B */
    ibuki_cuca_032,  /* 32 ALEX F N D */
    ibuki_cuca_033,  /* 33 no name */
    ibuki_cuca_034,  /* 34 IBUKI */
    ibuki_cuca_035,  /* 35 IBUKI YOROI D */
    ibuki_cuca_036,  /* 36 no name */
    ibuki_cuca_037,  /* 37 MAWARIKOMI M F */
    ibuki_cuca_038,  /* 38 HUGO BODY S */
    ibuki_cuca_039,  /* 39 HUGO N G T */
    ibuki_cuca_040,  /* 40 HUGO M S P */
    ibuki_cuca_041,  /* 41 HUGO S D B B */
    ibuki_cuca_042,  /* 42 no name */
    ibuki_cuca_043,  /* 43 no name */
    ibuki_cuca_044,  /* 44 no name */
    ibuki_cuca_045,  /* 45 no name */
    ibuki_cuca_046,  /* 46 no name */
    ibuki_cuca_047,  /* 47 no name */
    ibuki_cuca_048,  /* 48 no name */
    ibuki_cuca_049,  /* 49 no name */
    ibuki_cuca_050,  /* 50 no name */
    ibuki_cuca_051,  /* 51 no name */
    ibuki_cuca_052,  /* 52 no name */
    ibuki_cuca_053,  /* 53 no name */
    ibuki_cuca_054,  /* 54 no name */
    ibuki_cuca_055,  /* 55 no name */
    ibuki_cuca_056,  /* 56 no name */
    ibuki_cuca_057,  /* 57 no name */
    ibuki_cuca_058,  /* 58 no name */
    ibuki_cuca_059,  /* 59 no name */
    ibuki_cuca_060,  /* 60 no name */
    ibuki_cuca_061,  /* 61 no name */
    ibuki_cuca_062,  /* 62 no name */
    ibuki_cuca_063,  /* 63 no name */
    ibuki_cuca_064,  /* 64 no name */
    ibuki_cuca_065,  /* 65 no name */
    ibuki_cuca_066,  /* 66 no name */
    ibuki_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 ibuki_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 537, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 537, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1862, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1862, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1862, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1413, 0, 0x2AF0),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 630, 0, 0x2AF1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 ibuki_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 1863, 0, 0x2AF8),
    L2(250, 0, 0, 0, 0, 2079, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 2080, 0, 0x2B09),
    L2(250, 0, 0, 0, 3, 1414, 0, 0x2B26),
    L2(250, 0, 0, 0, 3, 1415, 0, 0x2CD2),
    L2(250, 0, 0, 0, 3, 1416, 0, 0x2B2F),
    L2(250, 0, 0, 0, 3, 1417, 0, 0x2B50),
    L2(250, 0, 0, 0, 3, 1418, 0, 0x2ADB),
    L2(250, 0, 0, 0, 3, 1419, 0, 0x2B2D),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 1420, 0, 0x2B20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 ibuki_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 590, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1421, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1422, 0, 0x2AEA),
    L2(250, 0, 0, 0, 0, 1423, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 1424, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1425, 0, 0x2B08),
    L2(250, 0, 0, 0, 1, 1426, 0, 0x2AF2),
    L2(250, 0, 0, 0, 1, 1427, 0, 0x2AFF),
    L2(250, 0, 0, 0, 1, 1428, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1429, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1430, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1431, 0, 0x2B1E),
    L2(250, 0, 0, 0, 1, 1432, 0, 0x2B20),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 1433, 0, 0x2B20),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 ibuki_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 1434, 0, 0x2AB4),
    L2(250, 0, 0, 0, 0, 1435, 0, 0x2AB3),
    L2(250, 0, 0, 0, 0, 1436, 0, 0x2AB2),
    L2(250, 0, 0, 0, 0, 1437, 0, 0x2AB1),
    L2(250, 0, 0, 0, 1, 1438, 0, 0x2AEC),
    L2(250, 0, 0, 0, 1, 1439, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 1440, 0, 0x2AEB),
    L2(250, 0, 0, 0, 3, 1441, 0, 0x2B36),
    L2(250, 0, 0, 0, 3, 1442, 0, 0x2B33),
    L2(250, 0, 0, 0, 0, 1443, 0, 0x2B26),
    L2(250, 0, 0, 0, 0, 1444, 0, 0x2B1C),
    L2(250, 0, 0, 0, 0, 1445, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 1446, 0, 0x2B35),
    L2(250, 0, 0, 0, 0, 1447, 0, 0x2B36),
    L2(250, 0, 0, 0, 0, 1448, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1449, 0, 0x2B22),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 1450, 0, 0x2B22),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 ibuki_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 1451, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 1452, 0, 0x2B0D),
    L2(250, 0, 0, 0, 1, 1453, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1454, 0, 0x2ACE),
    L2(250, 0, 0, 0, 1, 1455, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1456, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1457, 0, 0x2AF0),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 0, 1458, 0, 0x2AF0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 ibuki_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 1459, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1460, 0, 0x2AD1),
    L2(250, 0, 0, 0, 0, 1461, 0, 0x2AE3),
    L2(250, 0, 0, 0, 1, 1462, 0, 0x2ACB),
    L2(250, 0, 0, 0, 0, 1463, 0, 0x2ACB),
    L2(250, 0, 0, 0, 1, 1464, 0, 0x2B2D),
    L2(250, 0, 0, 0, 1, 1465, 0, 0x2AF8),
    L2(250, 0, 0, 0, 2, 1466, 0, 0x2B03),
    L2(250, 0, 0, 0, 2, 1467, 0, 0x2AF8),
    L2(250, 0, 0, 0, 1, 1468, 0, 0x2B26),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 1469, 0, 0x2B2A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 ibuki_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 1470, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1471, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1472, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1473, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1474, 0, 0x2B9D),
    L2(250, 0, 0, 0, 0, 1475, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1476, 0, 0x2BCA),
    L2(250, 0, 0, 0, 0, 1477, 0, 0x2BC9),
    L2(250, 0, 0, 0, 0, 1478, 0, 0x2BC7),
    L2(250, 0, 0, 0, 0, 1479, 0, 0x2BC6),
    L2(250, 0, 0, 0, 0, 1480, 0, 0x2BC5),
    L2(250, 0, 0, 0, 0, 1481, 0, 0x2B0C),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 1482, 0, 0x2B2E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 ibuki_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_007[36] = {
    L2(250, 0, 0, 0, 0, 1483, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1484, 0, 0x2AF8),
    L2(250, 0, 0, 0, 0, 1485, 0, 0x2B00),
    CMD(CM_RMJA, 3, 7, 6),
    L2(250, 9, 0, 0, 0, 1486, 0, 0x2B00),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 3),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 ibuki_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 1487, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1488, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1489, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1490, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1491, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1492, 0, 0x2B06),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 1493, 0, 0x2B4A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 ibuki_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 1494, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1495, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1496, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1497, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1498, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1499, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1500, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1501, 0, 0x2AE4),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 1502, 0, 0x2B17),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 ibuki_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 1503, 0, 0x2A08),
    L2(250, 0, 0, 0, 0, 1504, 0, 0x2A8A),
    L2(250, 0, 0, 0, 0, 1505, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 1506, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 1507, 0, 0x2AFB),
    L2(250, 0, 0, 0, 3, 1508, 0, 0x2B1D),
    L2(250, 0, 0, 0, 3, 1509, 0, 0x2B35),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 1510, 0, 0x2B34),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 ibuki_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 1511, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1512, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1513, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1514, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1515, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1516, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1517, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 1518, 0, 0x2AFF),
    L2(250, 0, 0, 0, 0, 1519, 0, 0x2AFF),
    L2(250, 0, 0, 0, 0, 1520, 0, 0x2B00),
    L2(250, 0, 0, 0, 0, 1521, 0, 0x2AF7),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 1522, 0, 0x2AFF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 ibuki_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 1523, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1524, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1525, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1526, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1527, 0, 0x2AD7),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 1528, 0, 0x2B17),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 ibuki_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 1529, 0, 0x2A46),
    L2(250, 0, 0, 0, 1, 1530, 0, 0x2A46),
    L2(250, 0, 0, 0, 1, 1531, 0, 0x2B3F),
    L2(250, 0, 0, 0, 1, 1532, 0, 0x2B40),
    L2(250, 0, 0, 0, 1, 1533, 0, 0x2B42),
    L2(250, 0, 0, 0, 1, 1534, 0, 0x2B44),
    L2(250, 0, 0, 0, 1, 1535, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1536, 0, 0x2B1A),
    L2(250, 0, 0, 0, 1, 1537, 0, 0x2B1D),
    L2(250, 0, 0, 0, 1, 1538, 0, 0x2B1F),
    L2(250, 0, 0, 0, 1, 1539, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1540, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1541, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1542, 0, 0x2B22),
    L2(250, 0, 0, 0, 1, 1542, 0, 0x2B22),
    L2(250, 0, 0, 0, 1, 1543, 0, 0x2B22),
    L2(250, 0, 0, 0, 1, 1543, 0, 0x2B22),
    L2(250, 0, 0, 0, 1, 1544, 0, 0x2B23),
    L2(250, 0, 0, 0, 1, 1545, 0, 0x2B23),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 1546, 0, 0x2B23),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 ibuki_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 1548, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1547, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1548, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1549, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1550, 0, 0x2ADA),
    L2(250, 0, 0, 0, 1, 1551, 0, 0x2AFE),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 1552, 0, 0x2B00),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 ibuki_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_015[64] = {
    L2(250, 0, 0, 0, 1, 1554, 0, 0x2AEE),
    L2(250, 0, 0, 0, 0, 1555, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1556, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1557, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1558, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1559, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1560, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1561, 0, 0x2AD3),
    L2(250, 0, 0, 0, 1, 1562, 0, 0x2AEB),
    L2(250, 0, 0, 0, 3, 1563, 0, 0x2CD2),
    L2(250, 0, 0, 0, 3, 1564, 0, 0x2CCE),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 1565, 0, 0x2B6B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 ibuki_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 1566, 0, 0x2ADB),
    L2(250, 0, 0, 0, 0, 1567, 0, 0x2BAB),
    L2(250, 0, 0, 0, 0, 1568, 0, 0x2B07),
    L2(250, 0, 0, 0, 3, 1569, 0, 0x2B03),
    L2(250, 0, 0, 0, 3, 1570, 0, 0x2B01),
    L2(250, 0, 0, 0, 3, 1571, 0, 0x2B33),
    L2(250, 0, 0, 0, 3, 1572, 0, 0x2B34),
    L2(250, 0, 0, 0, 3, 1573, 0, 0x2B2E),
    L2(250, 0, 0, 0, 3, 1574, 0, 0x2B2F),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 1575, 0, 0x2AFF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 ibuki_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 1576, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1577, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1578, 0, 0x2B17),
    L2(250, 0, 0, 0, 1, 1579, 0, 0x2B1B),
    L2(250, 0, 0, 0, 1, 1580, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1581, 0, 0x2B21),
    L2(250, 0, 0, 0, 1, 1582, 0, 0x2B22),
    L2(250, 0, 0, 0, 0, 1583, 0, 0x2B67),
    L2(250, 0, 0, 0, 0, 1584, 0, 0x2B17),
    L2(250, 0, 0, 0, 0, 1585, 0, 0x2B19),
    L2(250, 0, 0, 0, 0, 1586, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 1587, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 1588, 0, 0x2B21),
    L2(250, 0, 0, 0, 1, 1589, 0, 0x2B67),
    L2(250, 0, 0, 0, 1, 1578, 0, 0x2B17),
    L2(250, 0, 0, 0, 1, 1579, 0, 0x2B1B),
    L2(250, 0, 0, 0, 1, 1580, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1581, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1590, 0, 0x2B22),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 1590, 0, 0x2B22),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 11, 8),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 ibuki_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 1591, 0, 0x2A7E),
    L2(250, 0, 0, 0, 0, 1592, 0, 0x2A7D),
    L2(250, 0, 0, 0, 0, 1593, 0, 0x2A7C),
    L2(250, 0, 0, 0, 0, 1594, 0, 0x2A79),
    L2(250, 0, 0, 0, 0, 1595, 0, 0x2A77),
    L2(250, 0, 0, 0, 0, 1596, 0, 0x2A76),
    L2(250, 0, 0, 0, 0, 1597, 0, 0x2A73),
    L2(250, 0, 0, 0, 0, 1598, 0, 0x2A72),
    L2(250, 0, 0, 0, 0, 1599, 0, 0x2B02),
    L2(250, 3, 0, 0, 0, 1600, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1601, 0, 0x2B03),
    L2(250, 0, 0, 0, 0, 1602, 0, 0x2B03),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 1602, 0, 0x2B03),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 ibuki_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 1603, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1604, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 585, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 586, 0, 0x2ADB),
    L2(250, 0, 0, 0, 0, 587, 0, 0x2ADC),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 1603, 0, 0x2A01),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 ibuki_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 1605, 0, 0x2A84),
    L2(250, 0, 0, 0, 1, 1606, 0, 0x2A85),
    L2(250, 0, 0, 0, 1, 1607, 0, 0x2A86),
    L2(250, 0, 0, 0, 1, 1606, 0, 0x2A85),
    L2(250, 0, 0, 0, 1, 1605, 0, 0x2A84),
    L2(250, 0, 0, 0, 1, 1608, 0, 0x2A91),
    L2(250, 0, 0, 0, 1, 1609, 0, 0x2AC7),
    L2(250, 0, 0, 0, 1, 1610, 0, 0x2AC8),
    L2(250, 0, 0, 0, 1, 1611, 0, 0x2ACB),
    L2(250, 0, 0, 0, 1, 1612, 0, 0x2B19),
    L2(250, 0, 0, 0, 1, 1613, 0, 0x2B1A),
    L2(250, 0, 0, 0, 1, 1614, 0, 0x2B1C),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 1615, 0, 0x2B1D),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 ibuki_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 511, 0, 0x2A8C),
    L2(250, 0, 0, 0, 0, 1616, 0, 0x2AD1),
    L2(250, 0, 0, 0, 0, 1617, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1618, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 1619, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 1620, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 1621, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 1622, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 1623, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 1624, 0, 0x2B09),
    L2(250, 0, 0, 0, 0, 1625, 0, 0x2B09),
    L2(250, 0, 0, 0, 0, 1626, 0, 0x2B3A),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 1627, 0, 0x2B3A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 ibuki_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 1577, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1578, 0, 0x2B17),
    L2(250, 0, 0, 0, 1, 1628, 0, 0x2B18),
    L2(250, 0, 0, 0, 1, 1613, 0, 0x2B1A),
    L2(250, 0, 0, 0, 1, 1614, 0, 0x2B1C),
    L2(250, 0, 0, 0, 1, 1629, 0, 0x2B1D),
    L2(250, 0, 0, 0, 1, 1431, 0, 0x2B1E),
    L2(250, 0, 0, 0, 1, 1630, 0, 0x2B1F),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 1630, 0, 0x2B1F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 ibuki_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 1631, 0, 0x2AD7),
    L2(250, 0, 0, 0, 1, 1438, 0, 0x2AEC),
    L2(250, 0, 0, 0, 0, 1632, 0, 0x2B3B),
    L2(250, 0, 0, 0, 0, 1633, 0, 0x2B6D),
    L2(250, 0, 0, 0, 0, 1634, 0, 0x2B6C),
    L2(250, 0, 0, 0, 3, 1635, 0, 0x2B35),
    L2(250, 0, 0, 0, 3, 1636, 0, 0x2B2E),
    L2(250, 0, 0, 0, 0, 1637, 0, 0x2B25),
    L2(250, 0, 0, 0, 0, 1638, 0, 0x2B1C),
    L2(250, 0, 0, 0, 0, 1639, 0, 0x2B1B),
    L2(250, 0, 0, 0, 0, 1640, 0, 0x2B1A),
    L2(250, 0, 0, 0, 0, 1641, 0, 0x2B1A),
    L2(250, 0, 0, 0, 0, 1642, 0, 0x2B19),
    L2(250, 0, 0, 0, 0, 1643, 0, 0x2B1B),
    L2(250, 0, 0, 0, 0, 1644, 0, 0x2B57),
    L2(250, 0, 0, 0, 0, 1645, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1646, 0, 0x2B20),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 1647, 0, 0x2B1E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 ibuki_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 1648, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1649, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1650, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1651, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 1652, 0, 0x2AFE),
    L2(250, 0, 0, 0, 0, 1653, 0, 0x2B00),
    L2(250, 0, 0, 0, 0, 1654, 0, 0x2AFF),
    L2(250, 0, 0, 0, 0, 1655, 0, 0x2B00),
    L2(250, 0, 0, 0, 0, 1656, 0, 0x2AFE),
    L2(250, 0, 0, 0, 0, 1657, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1658, 0, 0x2B06),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 1654, 0, 0x2AFF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 ibuki_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 1576, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1577, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1578, 0, 0x2B17),
    L2(250, 0, 0, 0, 1, 1579, 0, 0x2B1B),
    L2(250, 0, 0, 0, 1, 1580, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1581, 0, 0x2B21),
    L2(250, 0, 0, 0, 1, 1582, 0, 0x2B22),
    L2(250, 0, 0, 0, 0, 1583, 0, 0x2B67),
    L2(250, 0, 0, 0, 0, 1584, 0, 0x2B17),
    L2(250, 0, 0, 0, 0, 1585, 0, 0x2B19),
    L2(250, 0, 0, 0, 0, 1586, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 1587, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 1588, 0, 0x2B21),
    L2(250, 0, 0, 0, 1, 1589, 0, 0x2B67),
    L2(250, 0, 0, 0, 1, 1578, 0, 0x2B17),
    L2(250, 0, 0, 0, 1, 1579, 0, 0x2B1B),
    L2(250, 0, 0, 0, 1, 1580, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1581, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1590, 0, 0x2B22),
    L2(250, 0, 0, 0, 0, 1659, 0, 0x2B22),
    L2(250, 0, 0, 0, 0, 1660, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 1661, 0, 0x2B1B),
    L2(250, 0, 0, 0, 0, 1662, 0, 0x2B1C),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 1663, 0, 0x2B1C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 ibuki_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 1664, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1665, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1666, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 1667, 0, 0x2B31),
    L2(250, 0, 0, 0, 0, 967, 0, 0x2B35),
    L2(250, 3, 0, 0, 0, 1300, 0, 0x2B5A),
    L2(250, 0, 0, 0, 0, 972, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1275, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1276, 0, 0x2B29),
    L2(250, 0, 0, 0, 0, 1277, 0, 0x2B2A),
    L2(250, 0, 0, 0, 0, 1278, 0, 0x2B2B),
    L2(250, 0, 0, 0, 0, 1278, 0, 0x2B2B),
    L2(250, 3, 0, 0, 0, 970, 0, 0x2B03),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 974, 0, 0x2B2B),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 ibuki_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_027[136] = {
    L2(250, 0, 0, 0, 0, 1668, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1669, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1670, 0, 0x2AE8),
    L2(250, 0, 0, 0, 1, 1671, 0, 0x2B07),
    L2(250, 0, 0, 0, 1, 1672, 0, 0x2B08),
    L2(250, 0, 0, 0, 1, 1673, 0, 0x2B0A),
    L2(250, 0, 0, 0, 1, 1674, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1675, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1676, 0, 0x2B2F),
    L2(250, 0, 0, 0, 1, 1677, 0, 0x2B22),
    L2(250, 0, 0, 0, 2, 1678, 0, 0x2B2E),
    L2(250, 0, 0, 0, 2, 1679, 0, 0x2B2F),
    L2(250, 0, 0, 0, 2, 1680, 0, 0x2B30),
    L2(250, 0, 0, 0, 2, 1681, 0, 0x2B31),
    L2(250, 0, 0, 0, 0, 1682, 0, 0x2B24),
    L2(250, 0, 0, 0, 3, 1683, 0, 0x2B2E),
    L2(250, 0, 0, 0, 3, 1684, 0, 0x2B2F),
    L2(250, 0, 0, 0, 3, 1685, 0, 0x2B30),
    L2(250, 0, 0, 0, 3, 1686, 0, 0x2B35),
    L2(250, 0, 0, 0, 3, 1687, 0, 0x2B36),
    L2(250, 0, 0, 0, 3, 1688, 0, 0x2B35),
    L2(250, 0, 0, 0, 3, 1689, 0, 0x2B33),
    L2(250, 0, 0, 0, 0, 1690, 0, 0x2B26),
    L2(250, 0, 0, 0, 0, 1691, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 1692, 0, 0x2B35),
    L2(250, 0, 0, 0, 0, 1693, 0, 0x2B36),
    L2(250, 0, 0, 0, 0, 1694, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 1695, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1696, 0, 0x2B22),
    CMD(CM_RMJA, 3, 27, 32),
    L2(250, 9, 0, 0, 0, 1697, 0, 0x2B22),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 ibuki_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_028[124] = {
    L2(250, 0, 0, 0, 1, 1698, 0, 0x2A46),
    L2(250, 0, 0, 0, 1, 1699, 0, 0x2A46),
    L2(250, 0, 0, 0, 1, 1700, 0, 0x2B3F),
    L2(250, 0, 0, 0, 1, 1701, 0, 0x2B40),
    L2(250, 0, 0, 0, 1, 1702, 0, 0x2B42),
    L2(250, 0, 0, 0, 1, 1703, 0, 0x2B44),
    L2(250, 0, 0, 0, 1, 1704, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1705, 0, 0x2B1A),
    L2(250, 0, 0, 0, 1, 1706, 0, 0x2B1D),
    L2(250, 0, 0, 0, 1, 1707, 0, 0x2B1F),
    L2(250, 0, 0, 0, 1, 1708, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1709, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1710, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 1711, 0, 0x2B22),
    L2(250, 0, 0, 0, 2, 1712, 0, 0x2B57),
    L2(250, 0, 0, 0, 2, 1713, 0, 0x2B58),
    L2(250, 0, 0, 0, 2, 1714, 0, 0x2B02),
    L2(250, 0, 0, 0, 2, 1715, 0, 0x2B04),
    L2(250, 0, 0, 0, 2, 1716, 0, 0x2B34),
    L2(250, 0, 0, 0, 1, 1717, 0, 0x2B38),
    L2(250, 0, 0, 0, 1, 1718, 0, 0x2B38),
    L2(250, 0, 0, 0, 1, 1719, 0, 0x2B38),
    L2(250, 0, 0, 0, 1, 1720, 0, 0x2B38),
    L2(250, 0, 0, 0, 1, 1721, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1722, 0, 0x2B49),
    L2(250, 0, 0, 0, 1, 1723, 0, 0x2B1B),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 1724, 0, 0x2B1B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 ibuki_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 1725, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1726, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1727, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 1728, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1729, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 1730, 0, 0x2AFF),
    L2(250, 0, 0, 0, 3, 1731, 0, 0x2B35),
    L2(250, 0, 0, 0, 3, 1732, 0, 0x2B2E),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 1733, 0, 0x2B34),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 ibuki_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 1734, 0, 0x2A04),
    L2(250, 0, 0, 0, 0, 1735, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1736, 0, 0x2AE0),
    L2(250, 0, 0, 0, 0, 1737, 0, 0x2ADE),
    L2(250, 0, 0, 0, 0, 1738, 0, 0x2ADB),
    L2(250, 0, 0, 0, 0, 1739, 0, 0x2B48),
    L2(250, 0, 0, 0, 1, 1740, 0, 0x2A81),
    L2(250, 0, 0, 0, 1, 1741, 0, 0x2B2D),
    L2(250, 0, 0, 0, 1, 1742, 0, 0x2B2D),
    L2(250, 0, 0, 0, 1, 1743, 0, 0x2A81),
    L2(250, 0, 0, 0, 1, 1744, 0, 0x2B2D),
    L2(250, 0, 0, 0, 1, 1745, 0, 0x2B2D),
    L2(250, 0, 0, 0, 1, 1744, 0, 0x2B2D),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 1742, 0, 0x2B2D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 25, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 ibuki_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 1746, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1747, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 1748, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1749, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1748, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1750, 0, 0x2AF0),
    L2(250, 0, 0, 0, 0, 1751, 0, 0x2AF1),
    L2(250, 0, 0, 0, 0, 1752, 0, 0x2AF1),
    L2(250, 0, 0, 0, 0, 1753, 0, 0x2AF1),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 1754, 0, 0x2AF1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 ibuki_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 1755, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 1756, 0, 0x2B0E),
    L2(250, 0, 0, 0, 0, 1757, 0, 0x2B0F),
    L2(250, 0, 0, 0, 0, 1758, 0, 0x2B0F),
    L2(250, 0, 0, 0, 0, 1759, 0, 0x2B2E),
    L2(250, 0, 0, 0, 0, 1760, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 1761, 0, 0x2B30),
    L2(250, 0, 0, 0, 0, 1762, 0, 0x2B57),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 1763, 0, 0x2B57),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 ibuki_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 590, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1421, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1422, 0, 0x2AEA),
    L2(250, 0, 0, 0, 0, 1423, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 1424, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1425, 0, 0x2B08),
    L2(250, 0, 0, 0, 1, 1426, 0, 0x2AF2),
    L2(250, 0, 0, 0, 1, 1427, 0, 0x2AFF),
    L2(250, 0, 0, 0, 1, 1428, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1429, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1430, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1431, 0, 0x2B1E),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 1432, 0, 0x2B20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 30, 9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 30, 9),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 ibuki_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 1764, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1765, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1766, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 1767, 0, 0x2B10),
    L2(250, 0, 0, 0, 0, 1768, 0, 0x2B11),
    L2(250, 0, 0, 0, 0, 1769, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 1770, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1771, 0, 0x2AF9),
    L2(250, 0, 0, 0, 0, 1772, 0, 0x2AFA),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 1773, 0, 0x2AFA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 7, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 ibuki_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 1470, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1471, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1472, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1473, 0, 0x2AE2),
    L2(250, 0, 0, 0, 0, 1474, 0, 0x2B9D),
    L2(250, 0, 0, 0, 0, 1475, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1476, 0, 0x2BCA),
    L2(250, 0, 0, 0, 0, 1477, 0, 0x2BC9),
    L2(250, 0, 0, 0, 0, 1478, 0, 0x2BC7),
    L2(250, 0, 0, 0, 0, 1479, 0, 0x2BC6),
    L2(250, 0, 0, 0, 0, 1480, 0, 0x2BC5),
    L2(250, 0, 0, 0, 0, 1481, 0, 0x2B0C),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 1482, 0, 0x2B2E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 ibuki_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 1950, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1951, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1952, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 1953, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1954, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1955, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 1956, 0, 0x2B0B),
    L2(250, 0, 0, 0, 0, 1957, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 1958, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1959, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 1960, 0, 0x2AE4),
    L2(250, 2, 0, 0, 0, 1961, 0, 0x2AFA),
    L2(250, 0, 0, 0, 0, 1962, 0, 0x2AF9),
    L2(250, 0, 0, 0, 0, 1963, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1964, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1965, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1966, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1967, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1968, 0, 0x2B32),
    L2(250, 2, 0, 0, 0, 1969, 0, 0x2B35),
    L2(250, 0, 0, 0, 0, 1970, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 1971, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 1972, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1973, 0, 0x2B22),
    L2(250, 0, 0, 0, 0, 1974, 0, 0x2B23),
    L2(250, 0, 0, 0, 0, 1975, 0, 0x2B24),
    L2(250, 0, 0, 0, 0, 1976, 0, 0x2B25),
    L2(250, 0, 0, 0, 0, 1977, 0, 0x2B26),
    L2(250, 0, 0, 0, 0, 1978, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1979, 0, 0x2B28),
    L2(250, 2, 0, 0, 0, 1980, 0, 0x2B03),
    L2(250, 0, 0, 0, 0, 1981, 0, 0x2B04),
    L2(250, 0, 0, 0, 0, 1982, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1983, 0, 0x2B5B),
    L2(250, 0, 0, 0, 0, 1984, 0, 0x2B2B),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 1985, 0, 0x2B2C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 ibuki_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 1603, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 1604, 0, 0x2A01),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 625, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 624, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 585, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 586, 0, 0x2ADB),
    L2(250, 0, 0, 0, 0, 1555, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1556, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1557, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1558, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1517, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 646, 0, 0x2B0D),
    L2(250, 0, 0, 0, 3, 1569, 0, 0x2B03),
    L2(250, 0, 0, 0, 2, 1774, 0, 0x2B35),
    L2(250, 0, 0, 0, 2, 1775, 0, 0x2B34),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 2277, 0, 0x2B0E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 ibuki_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 1864, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 1865, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 1866, 0, 0x2AF8),
    L2(250, 0, 0, 0, 1, 1867, 0, 0x2B4C),
    L2(250, 0, 0, 0, 0, 1868, 0, 0x2C7F),
    L2(250, 0, 0, 0, 0, 1869, 0, 0x2B38),
    L2(250, 0, 0, 0, 1, 1870, 0, 0x2B4A),
    L2(250, 0, 0, 0, 2, 1871, 0, 0x2B26),
    L2(250, 0, 0, 0, 2, 1872, 0, 0x2B27),
    L2(250, 0, 0, 0, 2, 1873, 0, 0x2B28),
    L2(250, 0, 0, 0, 2, 1874, 0, 0x2B29),
    L2(250, 0, 0, 0, 2, 1875, 0, 0x2B28),
    L2(250, 0, 0, 0, 2, 1876, 0, 0x2B1C),
    L2(250, 0, 0, 0, 2, 1877, 0, 0x2B17),
    L2(250, 0, 0, 0, 2, 1878, 0, 0x2B38),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 1879, 0, 0x2B25),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 ibuki_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 1880, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 1881, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1882, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1883, 0, 0x2ACC),
    L2(250, 0, 0, 0, 0, 1884, 0, 0x2AC9),
    L2(250, 0, 0, 0, 0, 1885, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1886, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1887, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1888, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1889, 0, 0x2ACF),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 1654, 0, 0x2AFF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 ibuki_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 1890, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1891, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1892, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1893, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1894, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1895, 0, 0x2ADA),
    L2(250, 0, 0, 0, 1, 1896, 0, 0x2B48),
    L2(250, 0, 0, 0, 1, 1897, 0, 0x2AE7),
    L2(250, 0, 0, 0, 0, 1898, 0, 0x2B49),
    L2(250, 0, 0, 0, 0, 1899, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1900, 0, 0x2AFB),
    L2(250, 0, 0, 0, 1, 1901, 0, 0x2AFB),
    L2(250, 0, 0, 0, 1, 1902, 0, 0x2B48),
    L2(250, 0, 0, 0, 0, 1903, 0, 0x2B47),
    L2(250, 0, 0, 0, 0, 1904, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1905, 0, 0x2AF9),
    L2(250, 0, 0, 0, 0, 1906, 0, 0x2B37),
    L2(250, 0, 0, 0, 1, 1907, 0, 0x2B52),
    L2(250, 0, 0, 0, 3, 1908, 0, 0x2CD1),
    L2(250, 0, 0, 0, 3, 1909, 0, 0x2B17),
    L2(250, 0, 0, 0, 3, 1910, 0, 0x2A82),
    L2(250, 0, 0, 0, 3, 1911, 0, 0x2AAF),
    L2(250, 0, 0, 0, 3, 1912, 0, 0x2C73),
    L2(250, 0, 0, 0, 0, 1913, 0, 0x2B1D),
    L2(250, 0, 0, 0, 0, 1914, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1915, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1916, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1917, 0, 0x2B03),
    L2(250, 0, 0, 0, 0, 1918, 0, 0x2B04),
    L2(250, 0, 0, 0, 0, 1919, 0, 0x2B2A),
    L2(250, 0, 0, 0, 0, 1920, 0, 0x2B2B),
    L2(250, 0, 0, 0, 0, 1921, 0, 0x2B2C),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 1921, 0, 0x2B2C),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 ibuki_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 1922, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1923, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 1924, 0, 0x2B34),
    L2(250, 0, 0, 0, 0, 1925, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1926, 0, 0x2B31),
    L2(250, 0, 0, 0, 0, 1927, 0, 0x2B30),
    L2(250, 0, 0, 0, 0, 1928, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1929, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1930, 0, 0x2B59),
    L2(250, 0, 0, 0, 0, 1931, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1932, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1933, 0, 0x2B5A),
    L2(250, 0, 0, 0, 0, 1934, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1935, 0, 0x2B1B),
    L2(250, 0, 0, 0, 0, 1936, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1937, 0, 0x2B28),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 1938, 0, 0x2B1E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 ibuki_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 1939, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 1940, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 1941, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1942, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1943, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 1944, 0, 0x2B10),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 1007, 0, 0x2B0E),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 ibuki_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 613, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1018, 0, 0x2CD9),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 1018, 0, 0x2CD9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 ibuki_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 1890, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 1891, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 1892, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1893, 0, 0x2AD9),
    L2(250, 0, 0, 0, 1, 1894, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1895, 0, 0x2ADA),
    L2(250, 0, 0, 0, 1, 1896, 0, 0x2B48),
    L2(250, 0, 0, 0, 1, 1897, 0, 0x2AE7),
    L2(250, 0, 0, 0, 0, 1898, 0, 0x2B49),
    L2(250, 0, 0, 0, 0, 1899, 0, 0x2AD8),
    L2(250, 0, 0, 0, 1, 1900, 0, 0x2AFB),
    L2(250, 0, 0, 0, 1, 1901, 0, 0x2AFB),
    L2(250, 0, 0, 0, 1, 1902, 0, 0x2B48),
    L2(250, 0, 0, 0, 0, 1903, 0, 0x2B47),
    L2(250, 0, 0, 0, 0, 1904, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1905, 0, 0x2AF9),
    L2(250, 0, 0, 0, 0, 1906, 0, 0x2B37),
    L2(250, 0, 0, 0, 1, 1907, 0, 0x2B52),
    L2(250, 0, 0, 0, 3, 1908, 0, 0x2CD1),
    L2(250, 0, 0, 0, 3, 1909, 0, 0x2B17),
    L2(250, 0, 0, 0, 3, 1910, 0, 0x2A82),
    L2(250, 0, 0, 0, 3, 1911, 0, 0x2AAF),
    L2(250, 0, 0, 0, 3, 1912, 0, 0x2C73),
    L2(250, 0, 0, 0, 0, 1913, 0, 0x2B1D),
    L2(250, 0, 0, 0, 0, 1914, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1915, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1916, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1917, 0, 0x2B03),
    L2(250, 0, 0, 0, 0, 1918, 0, 0x2B04),
    L2(250, 0, 0, 0, 0, 1919, 0, 0x2B2A),
    L2(250, 0, 0, 0, 0, 1920, 0, 0x2B2B),
    L2(250, 0, 0, 0, 0, 1921, 0, 0x2B2C),
    L2(250, 0, 0, 0, 0, 1924, 0, 0x2B34),
    L2(250, 0, 0, 0, 0, 1925, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1926, 0, 0x2B31),
    L2(250, 0, 0, 0, 0, 1927, 0, 0x2B30),
    L2(250, 0, 0, 0, 0, 1928, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 1929, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1930, 0, 0x2B59),
    L2(250, 0, 0, 0, 0, 1931, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1932, 0, 0x2B27),
    L2(250, 0, 0, 0, 0, 1933, 0, 0x2B5A),
    L2(250, 0, 0, 0, 0, 1934, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1935, 0, 0x2B1B),
    L2(250, 0, 0, 0, 0, 1936, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1937, 0, 0x2B28),
    L2(250, 0, 0, 0, 0, 1947, 0, 0x2B38),
    L2(250, 0, 0, 0, 0, 1948, 0, 0x2B6D),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 1921, 0, 0x2B2C),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 ibuki_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 1949, 0, 0x2AF6),
    L2(250, 0, 0, 0, 0, 629, 0, 0x2AF2),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 631, 0, 0x2AF2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 ibuki_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 1904, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1905, 0, 0x2AF9),
    L2(250, 0, 0, 0, 0, 1906, 0, 0x2B37),
    L2(250, 0, 0, 0, 1, 1907, 0, 0x2B52),
    L2(250, 0, 0, 0, 3, 1908, 0, 0x2CD1),
    L2(250, 0, 0, 0, 3, 1909, 0, 0x2B17),
    L2(250, 0, 0, 0, 2, 2210, 0, 0x2B52),
    L2(250, 0, 0, 0, 0, 2211, 0, 0x2CD1),
    L2(250, 0, 0, 0, 0, 2212, 0, 0x2B17),
    L2(250, 0, 0, 0, 0, 2213, 0, 0x2A82),
    L2(250, 0, 0, 0, 0, 2214, 0, 0x2AAF),
    L2(250, 0, 0, 0, 3, 1910, 0, 0x2A82),
    L2(250, 0, 0, 0, 3, 1911, 0, 0x2AAF),
    L2(250, 0, 0, 0, 3, 1912, 0, 0x2C73),
    L2(250, 0, 0, 0, 0, 1913, 0, 0x2B1D),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 1914, 0, 0x2B28),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ibuki_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_047[108] = {
    L2(250, 0, 0, 0, 0, 1668, 0, 0x2AE9),
    L2(250, 0, 0, 0, 0, 1669, 0, 0x2AE5),
    L2(250, 0, 0, 0, 0, 1670, 0, 0x2AE8),
    L2(250, 0, 0, 0, 1, 1671, 0, 0x2B07),
    L2(250, 0, 0, 0, 1, 1672, 0, 0x2B08),
    L2(250, 0, 0, 0, 1, 1673, 0, 0x2B0A),
    L2(250, 0, 0, 0, 1, 1674, 0, 0x2B00),
    L2(250, 0, 0, 0, 1, 1675, 0, 0x2B01),
    L2(250, 0, 0, 0, 1, 1676, 0, 0x2B2F),
    L2(250, 0, 0, 0, 1, 1677, 0, 0x2B22),
    L2(250, 0, 0, 0, 2, 1678, 0, 0x2B2E),
    L2(250, 0, 0, 0, 2, 1679, 0, 0x2B2F),
    L2(250, 0, 0, 0, 2, 1680, 0, 0x2B30),
    L2(250, 0, 0, 0, 2, 1681, 0, 0x2B31),
    L2(250, 0, 0, 0, 0, 1682, 0, 0x2B24),
    L2(250, 0, 0, 0, 3, 1683, 0, 0x2B2E),
    L2(250, 0, 0, 0, 3, 1684, 0, 0x2B2F),
    L2(250, 0, 0, 0, 3, 1685, 0, 0x2B30),
    L2(250, 0, 0, 0, 1, 1431, 0, 0x2B1E),
    L2(250, 0, 0, 0, 1, 1432, 0, 0x2B20),
    CMD(CM_RMJA, 3, 47, 25),
    L2(250, 9, 0, 0, 1, 1433, 0, 0x2B20),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ibuki_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 2090, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 2091, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2092, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2093, 0, 0x2AE4),
    L2(250, 0, 0, 0, 0, 2094, 0, 0x2ADA),
    L2(250, 0, 0, 0, 0, 2095, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 2096, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 2097, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 1413, 0, 0x2AF0),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 630, 0, 0x2AF1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ibuki_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 1986, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1987, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 611, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 1989, 0, 0x2B37),
    L2(250, 0, 0, 0, 1, 1990, 0, 0x2AC8),
    L2(250, 0, 0, 0, 1, 1991, 0, 0x2B0D),
    L2(250, 0, 0, 0, 1, 1992, 0, 0x2B10),
    L2(250, 0, 0, 0, 1, 1993, 0, 0x2B0A),
    L2(250, 0, 0, 0, 2, 1994, 0, 0x2B34),
    L2(250, 0, 0, 0, 1, 1995, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 1996, 0, 0x2B21),
    L2(250, 0, 0, 0, 0, 1997, 0, 0x2B22),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 1998, 0, 0x2B23),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ibuki_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 1999, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2000, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 2001, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2002, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2003, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 2004, 0, 0x2B10),
    L2(250, 0, 0, 0, 0, 2005, 0, 0x2B0A),
    L2(250, 0, 0, 0, 0, 2006, 0, 0x2AF8),
    L2(250, 0, 0, 0, 0, 2007, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 2008, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2009, 0, 0x2B38),
    L2(250, 0, 0, 0, 0, 2010, 0, 0x2B6C),
    L2(250, 0, 0, 0, 0, 2011, 0, 0x2B3C),
    L2(250, 0, 0, 0, 0, 2012, 0, 0x2D1D),
    L2(250, 0, 0, 0, 0, 2013, 0, 0x2B39),
    L2(250, 0, 0, 0, 0, 2014, 0, 0x2B3C),
    L2(250, 0, 0, 0, 0, 2015, 0, 0x2B38),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 2016, 0, 0x2B24),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 ibuki_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 2159, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2160, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 2161, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 2162, 0, 0x2B0D),
    L2(250, 0, 0, 0, 1, 2163, 0, 0x2AED),
    L2(250, 0, 0, 0, 1, 2164, 0, 0x2AEB),
    L2(250, 0, 0, 0, 0, 2165, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 2166, 0, 0x2AD3),
    L2(250, 0, 0, 0, 0, 2167, 0, 0x2AF0),
    L2(250, 0, 0, 0, 0, 2168, 0, 0x2AF0),
    L2(250, 0, 0, 0, 0, 2169, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 2170, 0, 0x2AD1),
    L2(250, 0, 0, 0, 0, 2171, 0, 0x2AF8),
    L2(250, 0, 0, 0, 0, 2172, 0, 0x2AF8),
    L2(250, 2, 0, 0, 0, 2173, 0, 0x2AFE),
    L2(250, 0, 0, 0, 0, 2174, 0, 0x2B00),
    L2(250, 0, 0, 0, 0, 2175, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 2176, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 2177, 0, 0x2B47),
    L2(250, 0, 0, 0, 0, 2178, 0, 0x2B40),
    L2(250, 0, 0, 0, 0, 2179, 0, 0x2B3A),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 2180, 0, 0x2B08),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 ibuki_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 1503, 0, 0x2A08),
    L2(250, 0, 0, 0, 0, 1504, 0, 0x2A8A),
    L2(250, 0, 0, 0, 0, 1505, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 2202, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 2203, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2204, 0, 0x2CF3),
    L2(250, 0, 0, 0, 3, 2205, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 2206, 0, 0x2B20),
    L2(250, 0, 0, 0, 0, 2207, 0, 0x2CCE),
    L2(250, 0, 0, 0, 0, 2208, 0, 0x2B33),
    L2(250, 0, 0, 0, 0, 2209, 0, 0x2B00),
    L2(250, 0, 0, 0, 3, 1508, 0, 0x2B1D),
    L2(250, 0, 0, 0, 3, 1509, 0, 0x2B35),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 1510, 0, 0x2B34),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 ibuki_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 2017, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2018, 0, 0x2AC8),
    L2(250, 0, 0, 0, 0, 2019, 0, 0x2AC9),
    L2(250, 0, 0, 0, 0, 2020, 0, 0x2AC8),
    L2(250, 0, 0, 0, 0, 2021, 0, 0x2A92),
    L2(250, 0, 0, 0, 0, 2022, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2023, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2024, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2025, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 2026, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 2027, 0, 0x2ADA),
    L2(250, 0, 0, 0, 0, 2028, 0, 0x2ADA),
    L2(250, 0, 0, 0, 0, 2029, 0, 0x2C16),
    L2(250, 0, 0, 0, 0, 2030, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 2031, 0, 0x2B1D),
    L2(250, 0, 0, 0, 0, 2032, 0, 0x2B18),
    L2(250, 0, 0, 0, 3, 2033, 0, 0x2B1F),
    L2(250, 0, 0, 0, 3, 2034, 0, 0x2AFA),
    L2(250, 0, 0, 0, 3, 2035, 0, 0x2B01),
    L2(250, 0, 0, 0, 3, 2036, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 2037, 0, 0x2B00),
    L2(250, 0, 0, 0, 0, 2038, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 2039, 0, 0x2B26),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 2039, 0, 0x2B26),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 ibuki_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 2040, 0, 0x2B47),
    L2(250, 0, 0, 0, 0, 2041, 0, 0x2B48),
    L2(250, 0, 0, 0, 0, 2042, 0, 0x2B49),
    L2(250, 0, 0, 0, 0, 2043, 0, 0x2B4A),
    L2(250, 0, 0, 0, 0, 2044, 0, 0x2B4B),
    L2(250, 0, 0, 0, 0, 2045, 0, 0x2B4C),
    L2(250, 0, 0, 0, 0, 2046, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 2047, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 2048, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 2049, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 2050, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 2051, 0, 0x2AFA),
    L2(250, 0, 0, 0, 0, 2052, 0, 0x2AFA),
    L2(250, 0, 0, 0, 0, 2053, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 2054, 0, 0x2B2D),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 2055, 0, 0x2B2D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 25, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 ibuki_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 2017, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2018, 0, 0x2AC8),
    L2(250, 0, 0, 0, 0, 2019, 0, 0x2AC9),
    L2(250, 0, 0, 0, 0, 2020, 0, 0x2AC8),
    L2(250, 0, 0, 0, 0, 2021, 0, 0x2A92),
    L2(250, 0, 0, 0, 0, 2022, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2023, 0, 0x2AC7),
    L2(250, 0, 0, 0, 0, 2024, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2025, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 2026, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 2027, 0, 0x2ADA),
    L2(250, 0, 0, 0, 0, 2028, 0, 0x2ADA),
    L2(250, 0, 0, 0, 0, 2029, 0, 0x2C16),
    L2(250, 0, 0, 0, 0, 2030, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 2031, 0, 0x2B1D),
    L2(250, 0, 0, 0, 0, 2032, 0, 0x2B18),
    L2(250, 0, 0, 0, 3, 2033, 0, 0x2B1F),
    L2(250, 0, 0, 0, 3, 2034, 0, 0x2AFA),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 2056, 0, 0x2AE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 ibuki_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 2057, 0, 0x2AB4),
    L2(250, 0, 0, 0, 0, 2058, 0, 0x2AB2),
    L2(250, 0, 0, 0, 0, 2059, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 2060, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2061, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 2062, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 2063, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 2064, 0, 0x2B07),
    L2(250, 2, 0, 0, 0, 2065, 0, 0x2B0B),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 2066, 13, 0x2B33),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 ibuki_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 2067, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 2068, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 2069, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2070, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 2071, 0, 0x2B0B),
    L2(250, 0, 0, 0, 0, 2072, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2073, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2074, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2075, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 2076, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 2077, 0, 0x2B0D),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 2078, 0, 0x2B0E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 ibuki_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 1880, 0, 0x2AD2),
    L2(250, 0, 0, 0, 0, 1881, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1882, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1883, 0, 0x2ACC),
    L2(250, 0, 0, 0, 0, 1884, 0, 0x2AC9),
    L2(250, 0, 0, 0, 0, 1885, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1886, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1887, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1888, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1889, 0, 0x2ACF),
    L2(250, 0, 0, 0, 0, 995, 0, 0x2B17),
    L2(250, 0, 0, 0, 0, 970, 0, 0x2B03),
    L2(250, 0, 0, 0, 0, 1006, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 1888, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1886, 0, 0x2ACD),
    L2(250, 0, 0, 0, 0, 1887, 0, 0x2ACE),
    L2(250, 0, 0, 0, 0, 1888, 0, 0x2B2D),
    L2(250, 0, 0, 0, 0, 1885, 0, 0x2AFB),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 994, 0, 0x2AE5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 ibuki_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 2098, 0, 0x2A8E),
    L2(250, 0, 0, 0, 0, 2099, 0, 0x2A8F),
    L2(250, 0, 0, 0, 0, 2100, 0, 0x2A90),
    L2(250, 0, 0, 0, 0, 2101, 0, 0x2A91),
    L2(250, 0, 0, 0, 0, 2102, 0, 0x2A92),
    L2(250, 0, 0, 0, 0, 2103, 0, 0x2A93),
    L2(250, 0, 0, 0, 0, 2104, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2105, 0, 0x2B5D),
    L2(250, 0, 0, 0, 0, 2106, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 2107, 0, 0x2AFE),
    L2(250, 0, 0, 0, 0, 2108, 0, 0x2B31),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 2109, 0, 0x2B1C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 ibuki_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 2057, 0, 0x2AB4),
    L2(250, 0, 0, 0, 0, 2058, 0, 0x2AB2),
    L2(250, 0, 0, 0, 0, 2059, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 2060, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 2061, 0, 0x2B2D),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 2062, 0, 0x2B32),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 ibuki_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 2110, 0, 0x2C8E),
    L2(250, 0, 0, 0, 0, 2111, 0, 0x2C8E),
    L2(250, 0, 0, 0, 0, 2112, 0, 0x2C8D),
    L2(250, 0, 0, 0, 0, 2113, 0, 0x2C8C),
    L2(250, 0, 0, 0, 0, 2114, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2115, 0, 0x2B32),
    L2(250, 0, 0, 0, 0, 2116, 0, 0x2B01),
    L2(250, 0, 0, 0, 0, 2117, 0, 0x2B2F),
    L2(250, 0, 0, 0, 0, 2118, 0, 0x2B31),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 2119, 0, 0x2B1C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 ibuki_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 585, 0, 0x2AE5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 586, 0, 0x2ADB),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 587, 0, 0x2ADC),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 588, 0, 0x2ADD),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 589, 0, 0x2AE8),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 579, 0, 0x2AED),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 580, 0, 0x2AEE),
    CMD(CM_PA_X, 0, 4096, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 2196, 0, 0x2B08),
    CMD(CM_PA_X, 0, -4096, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 2197, 0, 0x2B3A),
    CMD(CM_PA_X, 0, -3072, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 2198, 0, 0x2B38),
    CMD(CM_PA_X, 0, -13568, 0),
    CMD(CM_PS_Y, 0, 0, 24),
    L2(250, 0, 0, 0, 1, 2199, 0, 0x2B20),
    L2(250, 0, 0, 0, 1, 2200, 0, 0x2B25),
    L2(250, 0, 0, 0, 1, 2201, 0, 0x2B21),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 1271, 0, 0x2B24),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 ibuki_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 1511, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1512, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1512, 0, 0x2B06),
    L2(250, 0, 0, 0, 0, 1514, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1515, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1516, 0, 0x2AF7),
    L2(250, 0, 0, 0, 0, 1006, 0, 0x2B0D),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 355, 0, 0, 1007, 0, 0x2B0E),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 ibuki_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 1986, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 1987, 0, 0x2B37),
    L2(250, 0, 0, 0, 3, 1988, 0, 0x2B1F),
    L2(250, 0, 0, 0, 0, 1989, 0, 0x2B37),
    L2(250, 0, 0, 0, 0, 2222, 0, 0x2AC8),
    L2(250, 0, 0, 0, 0, 2223, 0, 0x2B0D),
    L2(250, 0, 0, 0, 0, 2224, 0, 0x2B10),
    L2(250, 0, 0, 0, 0, 2225, 0, 0x2B0A),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 2005, 0, 0x2B0A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 3),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 ibuki_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 569, 0, 0x2AD6),
    L2(250, 0, 0, 0, 0, 570, 0, 0x2AD7),
    L2(250, 0, 0, 0, 0, 571, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 572, 0, 0x2AD9),
    L2(250, 0, 0, 0, 0, 573, 0, 0x2ADA),
    L2(250, 0, 0, 0, 1, 2226, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 2227, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 2228, 0, 0x2AEB),
    L2(250, 0, 0, 0, 1, 2229, 0, 0x2AEF),
    L2(250, 0, 0, 0, 3, 1563, 0, 0x2CD2),
    L2(250, 0, 0, 0, 3, 1564, 0, 0x2CCE),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 1565, 0, 0x2B6B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 ibuki_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 537, 0, 0x2AE3),
    L2(250, 0, 0, 0, 0, 614, 0, 0x2B05),
    L2(250, 0, 0, 0, 0, 602, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 618, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 618, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 967, 0, 0x2B35),
    L2(250, 0, 0, 0, 0, 720, 0, 0x2B02),
    L2(250, 0, 0, 0, 0, 721, 0, 0x2B03),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 721, 0, 0x2B03),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 ibuki_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 618, 0, 0x2B0C),
    L2(250, 0, 0, 0, 0, 619, 0, 0x2B09),
    L2(250, 0, 0, 0, 0, 620, 0, 0x2B0A),
    L2(250, 0, 0, 0, 0, 621, 0, 0x2B09),
    L2(250, 0, 0, 0, 0, 622, 0, 0x2B08),
    L2(250, 0, 0, 0, 0, 623, 0, 0x2B07),
    L2(250, 0, 0, 0, 0, 545, 0, 0x2AD8),
    L2(250, 0, 0, 0, 0, 602, 0, 0x2AFB),
    L2(250, 0, 0, 0, 0, 600, 0, 0x2AF9),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 2119, 0, 0x2B1C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 168 entries */
const u16* const ibuki_atca[169] = {
    ibuki_atca_000,  /* 0 S PUNCH A */
    ibuki_atca_001,  /* 1 S PUNCH B */
    ibuki_atca_001,  /* 2 S PUNCH C */
    ibuki_atca_003,  /* 3 M PUNCH A */
    ibuki_atca_003,  /* 4 M PUNCH B */
    ibuki_atca_005,  /* 5 M PUNCH C */
    ibuki_atca_006,  /* 6 L PUNCH A */
    ibuki_atca_007,  /* 7 L PUNCH B */
    ibuki_atca_007,  /* 8 L PUNCH C */
    ibuki_atca_009,  /* 9 S KICK A */
    ibuki_atca_010,  /* 10 S KICK B */
    ibuki_atca_010,  /* 11 S KICK C */
    ibuki_atca_012,  /* 12 M KICK A */
    ibuki_atca_013,  /* 13 M KICK B */
    ibuki_atca_014,  /* 14 M KICK C */
    ibuki_atca_015,  /* 15 L KICK A */
    ibuki_atca_016,  /* 16 L KICK B */
    ibuki_atca_017,  /* 17 L KICK C */
    ibuki_atca_018,  /* 18 KAGAMI P A */
    ibuki_atca_018,  /* 19 KAGAMI P B */
    ibuki_atca_018,  /* 20 KAGAMI P C */
    ibuki_atca_021,  /* 21 KAGAMI P A */
    ibuki_atca_021,  /* 22 KAGAMI P B */
    ibuki_atca_021,  /* 23 KAGAMI P C */
    ibuki_atca_024,  /* 24 KAGAMI P A */
    ibuki_atca_024,  /* 25 KAGAMI P B */
    ibuki_atca_024,  /* 26 KAGAMI P C */
    ibuki_atca_027,  /* 27 KAGAMI K A */
    ibuki_atca_027,  /* 28 KAGAMI K B */
    ibuki_atca_027,  /* 29 KAGAMI K C */
    ibuki_atca_030,  /* 30 KAGAMI K A */
    ibuki_atca_030,  /* 31 KAGAMI K B */
    ibuki_atca_032,  /* 32 KAGAMI K C */
    ibuki_atca_033,  /* 33 KAGAMI K A */
    ibuki_atca_033,  /* 34 KAGAMI K B */
    ibuki_atca_033,  /* 35 KAGAMI K C */
    ibuki_atca_036,  /* 36 V JUMP P S A */
    ibuki_atca_036,  /* 37 V JUMP P S B */
    ibuki_atca_038,  /* 38 V JUMP P M A */
    ibuki_atca_038,  /* 39 V JUMP P M B */
    ibuki_atca_040,  /* 40 V JUMP P L A */
    ibuki_atca_040,  /* 41 V JUMP P L B */
    ibuki_atca_042,  /* 42 V JUMP K S A */
    ibuki_atca_042,  /* 43 V JUMP K S B */
    ibuki_atca_044,  /* 44 V JUMP K M A */
    ibuki_atca_044,  /* 45 V JUMP K M B */
    ibuki_atca_046,  /* 46 V JUMP K L A */
    ibuki_atca_046,  /* 47 V JUMP K L B */
    ibuki_atca_048,  /* 48 F JUMP P S A */
    ibuki_atca_048,  /* 49 F JUMP P S B */
    ibuki_atca_050,  /* 50 F JUMP P M A */
    ibuki_atca_050,  /* 51 F JUMP P M B */
    ibuki_atca_052,  /* 52 F JUMP P L A */
    ibuki_atca_052,  /* 53 F JUMP P L B */
    ibuki_atca_054,  /* 54 F JUMP K S A */
    ibuki_atca_054,  /* 55 F JUMP K S B */
    ibuki_atca_056,  /* 56 F JUMP K M A */
    ibuki_atca_056,  /* 57 F JUMP K M B */
    ibuki_atca_058,  /* 58 F JUMP K L A */
    ibuki_atca_058,  /* 59 F JUMP K L B */
    ibuki_atca_060,  /* 60 B JUMP P S A */
    ibuki_atca_060,  /* 61 B JUMP P S B */
    ibuki_atca_062,  /* 62 B JUMP P M A */
    ibuki_atca_062,  /* 63 B JUMP P M B */
    ibuki_atca_064,  /* 64 B JUMP P L A */
    ibuki_atca_064,  /* 65 B JUMP P L B */
    ibuki_atca_066,  /* 66 B JUMP K S A */
    ibuki_atca_066,  /* 67 B JUMP K S B */
    ibuki_atca_068,  /* 68 B JUMP K M A */
    ibuki_atca_068,  /* 69 B JUMP K M B */
    ibuki_atca_070,  /* 70 B JUMP K L A */
    ibuki_atca_070,  /* 71 B JUMP K L B */
    ibuki_atca_072,  /* 72 SP V JP S P A */
    ibuki_atca_072,  /* 73 SP V JP S P B */
    ibuki_atca_074,  /* 74 SP V JP M P A */
    ibuki_atca_074,  /* 75 SP V JP M P B */
    ibuki_atca_076,  /* 76 SP V JP L P A */
    ibuki_atca_076,  /* 77 SP V JP L P B */
    ibuki_atca_078,  /* 78 SP V JP S K A */
    ibuki_atca_078,  /* 79 SP V JP S K B */
    ibuki_atca_080,  /* 80 SP V JP M K A */
    ibuki_atca_080,  /* 81 SP V JP M K B */
    ibuki_atca_082,  /* 82 SP V JP L K A */
    ibuki_atca_082,  /* 83 SP V JP L K B */
    ibuki_atca_084,  /* 84 SP F JP S P A */
    ibuki_atca_084,  /* 85 SP F JP S P B */
    ibuki_atca_086,  /* 86 SP F JP M P A */
    ibuki_atca_086,  /* 87 SP F JP M P B */
    ibuki_atca_088,  /* 88 SP F JP L P A */
    ibuki_atca_088,  /* 89 SP F JP L P B */
    ibuki_atca_090,  /* 90 SP F JP S K A */
    ibuki_atca_090,  /* 91 SP F JP S K B */
    ibuki_atca_092,  /* 92 SP F JP M K A */
    ibuki_atca_092,  /* 93 SP F JP M K B */
    ibuki_atca_094,  /* 94 SP F JP L K A */
    ibuki_atca_094,  /* 95 SP F JP L K B */
    ibuki_atca_096,  /* 96 SP B JP S P A */
    ibuki_atca_096,  /* 97 SP B JP S P B */
    ibuki_atca_098,  /* 98 SP B JP M P A */
    ibuki_atca_098,  /* 99 SP B JP M P B */
    ibuki_atca_100,  /* 100 SP B JP L P A */
    ibuki_atca_100,  /* 101 SP B JP L P B */
    ibuki_atca_102,  /* 102 SP B JP S K A */
    ibuki_atca_102,  /* 103 SP B JP S K B */
    ibuki_atca_104,  /* 104 SP B JP M K A */
    ibuki_atca_104,  /* 105 SP B JP M K B */
    ibuki_atca_106,  /* 106 SP B JP L K A */
    ibuki_atca_106,  /* 107 SP B JP L K B */
    ibuki_atca_108,  /* 108 S V JP S P A */
    ibuki_atca_108,  /* 109 S V JP S P B */
    ibuki_atca_110,  /* 110 S V JP M P A */
    ibuki_atca_110,  /* 111 S V JP M P B */
    ibuki_atca_112,  /* 112 S V JP L P A */
    ibuki_atca_112,  /* 113 S V JP L P B */
    ibuki_atca_114,  /* 114 S V JP S K A */
    ibuki_atca_114,  /* 115 S V JP S K B */
    ibuki_atca_116,  /* 116 S V JP M K A */
    ibuki_atca_116,  /* 117 S V JP M K B */
    ibuki_atca_118,  /* 118 S V JP L K A */
    ibuki_atca_118,  /* 119 S V JP L K B */
    ibuki_atca_108,  /* 120 S F JP S P A */
    ibuki_atca_108,  /* 121 S F JP S P B */
    ibuki_atca_110,  /* 122 S F JP M P A */
    ibuki_atca_110,  /* 123 S F JP M P B */
    ibuki_atca_112,  /* 124 S F JP L P A */
    ibuki_atca_112,  /* 125 S F JP L P B */
    ibuki_atca_114,  /* 126 S F JP S K A */
    ibuki_atca_114,  /* 127 S F JP S K B */
    ibuki_atca_116,  /* 128 S F JP M K A */
    ibuki_atca_116,  /* 129 S F JP M K B */
    ibuki_atca_118,  /* 130 S F JP L K A */
    ibuki_atca_118,  /* 131 S F JP L K B */
    ibuki_atca_108,  /* 132 S B JP S P A */
    ibuki_atca_108,  /* 133 S B JP S P B */
    ibuki_atca_110,  /* 134 S B JP M P A */
    ibuki_atca_110,  /* 135 S B JP M P B */
    ibuki_atca_112,  /* 136 S B JP L P A */
    ibuki_atca_112,  /* 137 S B JP L P B */
    ibuki_atca_114,  /* 138 S B JP S K A */
    ibuki_atca_114,  /* 139 S B JP S K B */
    ibuki_atca_116,  /* 140 S B JP M K A */
    ibuki_atca_116,  /* 141 S B JP M K B */
    ibuki_atca_118,  /* 142 S B JP L K A */
    ibuki_atca_118,  /* 143 S B JP L K B */
    ibuki_atca_144,  /* 144 TUKAMIKAKARI A */
    ibuki_atca_144,  /* 145 TUKAMIKAKARI B */
    ibuki_atca_146,  /* 146 TUKAMIKAKARI C */
    ibuki_atca_144,  /* 147 TUKAMIKAKARI D */
    ibuki_atca_144,  /* 148 TUKAMIKAKARI E */
    ibuki_atca_144,  /* 149 TUKAMIKAKARI F */
    ibuki_atca_150,  /* 150 TUKAMI AIR A */
    ibuki_atca_150,  /* 151 TUKAMI AIR B */
    ibuki_atca_150,  /* 152 TUKAMI AIR C */
    ibuki_atca_150,  /* 153 TUKAMI AIR D */
    ibuki_atca_150,  /* 154 TUKAMI AIR E */
    ibuki_atca_150,  /* 155 TUKAMI AIR F */
    ibuki_atca_156,  /* 156 follow-up of M KICK A */
    ibuki_atca_157,  /* 157 follow-up of M PUNCH C, L PUNCH A */
    ibuki_atca_158,  /* 158 follow-up of V JUMP P L A, F JUMP K S A */
    ibuki_atca_159,  /* 159 follow-up of F JUMP P S A */
    ibuki_atca_160,  /* 160 follow-up of S KICK A */
    ibuki_atca_161,  /* 161 follow-up of M KICK B */
    ibuki_atca_162,  /* 162 follow-up of S PUNCH A */
    ibuki_atca_163,  /* 163 no name */
    ibuki_atca_164,  /* 164 no name */
    ibuki_atca_165,  /* 165 follow-up of M PUNCH C */
    ibuki_atca_166,  /* 166 no name */
    ibuki_atca_167,  /* 167 follow-up of follow-up of M PUNCH C, L PUNCH A */
    0
};

/* script: not in the index */
const u16 ibuki_atca_unused_head[4] = { HEAD(6, 0, 0, 8, 0, 1, 0) };
const u16 ibuki_atca_unused[184] = {
    CMD(CM_RMJA, 4, 3, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 366, 0, 0x2BB9, 0, 3, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 268, 0, 0, 367, 0, 0x2BBA, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 368, 0, 0x2BBB, -1, 4, 0, 143, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 369, 0, 0x2BBC, 0, 11, 2223, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 370, 0, 0x2BBD, 0, 11, 2223, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 371, 0, 0x2B98, 0, 11, 0, 0, 4, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 372, 0, 0x2B99, 0, 11, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 0, 0, 0, 373, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 374, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 387, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 376, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 376, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 368, 0, 0x2BBC, 0, 3, 0, 0, 112, 0, 16, 0, 0, 0, 6, 0),
    L6(1, 0, 0, 0, 0, 369, 0, 0x2BBC, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 0 S PUNCH A */
const u16 ibuki_atca_000_head[4] = { HEAD(6, 0, 0, 8, 0, 1, 0) };
const u16 ibuki_atca_000[160] = {
    CMD(CM_RMJA, 4, 162, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 366, 0, 0x2BB9, 0, 3, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 268, 0, 0, 367, 0, 0x2BBA, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 368, 0, 0x2BBB, -1, 4, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 369, 0, 0x2BBC, 0, 11, 2223, 0, 104, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 370, 0, 0x2BBD, 0, 11, 2223, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 371, 0, 0x2B98, 0, 11, 0, 0, 4, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 372, 0, 0x2B99, 0, 11, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 0, 0, 0, 373, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 374, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 387, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 376, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 376, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 ibuki_atca_001_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 0) };
const u16 ibuki_atca_001[108] = {
    CMD(CM_RMJA, 4, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 377, 0, 0x2B84, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 378, 0, 0x2B85, 0, 5, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 379, 0, 0x2B86, -2, 6, 2080, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 380, 0, 0x2B87, 0, 7, 2080, 0, 8, 21, 0),
    L4(1, 64, 0, 0, 0, 381, 0, 0x2B88, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 382, 0, 0x2B89, 0, 5, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 383, 0, 0x2B8A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 384, 0, 0x2B8B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 385, 0, 0x2B8C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 386, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 387, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 387, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 ibuki_atca_003_head[4] = { HEAD(6, 0, 2, 12, 0, 1, 0) };
const u16 ibuki_atca_003[208] = {
    CMD(CM_RMJA, 4, 10, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 404, 0, 0x2B8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 405, 0, 0x2B90, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 406, 0, 0x2B91, 0, 1, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 0, 269, 0, 0, 407, 0, 0x2B92, 0, 48, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 0, 0, 0, 408, 0, 0x2B93, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 409, 0, 0x2B94, -16, 49, 4, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 410, 0, 0x2B95, 17, 50, 2436, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 411, 0, 0x2B96, 0, 51, 2436, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 412, 0, 0x2B97, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 413, 0, 0x2B98, 0, 48, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(2, 0, 0, 0, 0, 414, 0, 0x2B99, 0, 48, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 0, 0, 0, 0, 415, 0, 0x2B9A, 0, 48, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 0, 0, 0, 0, 416, 0, 0x2B9B, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 417, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 418, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 418, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 ibuki_atca_005_head[4] = { HEAD(6, 0, 2, 9, 0, 2, 0) };
const u16 ibuki_atca_005[232] = {
    CMD(CM_RMJA, 4, 165, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 388, 0, 0x2BBE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 389, 0, 0x2BBF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 390, 0, 0x2BC0, 0, 43, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 391, 0, 0x2BC1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 269, 0, 0, 392, 0, 0x2BC2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 393, 0, 0x2BC3, -13, 44, 2255, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 394, 0, 0x2BC4, -14, 45, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 395, 0, 0x2BC5, 15, 46, 3074, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 396, 0, 0x2BC6, 0, 47, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 397, 0, 0x2BC7, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 398, 0, 0x2BC8, 0, 43, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(4, 64, 0, 0, 0, 399, 0, 0x2BC9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(4, 0, 0, 0, 0, 400, 0, 0x2BCA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(4, 0, 0, 0, 0, 401, 0, 0x2BCB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(4, 0, 0, 0, 0, 402, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(3, 0, 0, 0, 0, 403, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 403, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 ibuki_atca_006_head[4] = { HEAD(6, 0, 4, 8, 0, 2, 0) };
const u16 ibuki_atca_006[280] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 419, 0, 0x2BCC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 420, 0, 0x2BCD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 421, 0, 0x2BCE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 357, 0, 0, 422, 0, 0x2BCF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 423, 0, 0x2BD0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 424, 0, 0x2BD1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 425, 0, 0x2BD2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 426, 0, 0x2BD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(1, 0, 0, 0, 0, 427, 0, 0x2BD4, -18, 52, 0, 0, 96, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 428, 0, 0x2BD5, -19, 53, 3074, 0, 8, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 429, 0, 0x2BD6, 20, 54, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 430, 0, 0x2BD7, 0, 55, 0, 0, 0, 21, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 0, 0, 0, 431, 0, 0x2BD8, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 432, 0, 0x2BD9, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 433, 0, 0x2BDA, 0, 55, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(2, 0, 0, 0, 0, 434, 0, 0x2BDB, 0, 55, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 64, 0, 0, 0, 435, 0, 0x2BDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(2, 0, 0, 0, 0, 436, 0, 0x2BDD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 0, 0, 0, 0, 437, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 438, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 439, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 439, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 ibuki_atca_007_head[4] = { HEAD(6, 0, 4, 12, 0, 2, 0) };
const u16 ibuki_atca_007[484] = {
    CMD(CM_RMJA, 4, 7, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 440, 0, 0x2B9E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 441, 0, 0x2B9F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 442, 0, 0x2BA0, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 443, 0, 0x2BA1, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 444, 0, 0x2BA2, 0, 73, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(3, 0, 0, 0, 0, 445, 0, 0x2BA3, 0, 73, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(3, 0, 0, 0, 0, 446, 0, 0x2BA4, 0, 74, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 270, 0, 0, 447, 0, 0x2BA5, 0, 74, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 448, 0, 0x2BA6, -29, 75, 0, 128, 96, 0, 0, 0, 0, 66, 0, 0),
    L6(1, 0, 0, 0, 0, 449, 0, 0x2BA7, 30, 76, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 450, 0, 0x2BA8, 0, 76, 2112, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 451, 0, 0x2BA9, 0, 77, 2112, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 452, 0, 0x2BAA, 0, 77, 0, 0, 0, 21, 0, 0, 0, 68, 0, 0),
    L6(2, 0, 0, 0, 0, 453, 0, 0x2BAB, 0, 77, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 454, 0, 0x2BAC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 455, 0, 0x2BAD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 456, 0, 0x2BAE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 64, 0, 0, 0, 457, 0, 0x2BAF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 458, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 459, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 460, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 460, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 487, 0, 0x2D66, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 359, 0, 0, 488, 0, 0x2D67, -75, 129, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 489, 0, 0x2D68, 0, 77, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 490, 0, 0x2D69, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 491, 0, 0x2D68, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 491, 0, 0x2D68, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 492, 0, 0x2D69, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 493, 0, 0x2D68, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 494, 0, 0x2BAB, 0, 77, 0, 0, 0, 0, 0, 0, 0, 278, 0, 0),
    L6(3, 0, 0, 0, 0, 495, 0, 0x2BAC, 0, 77, 0, 0, 0, 0, 0, 0, 0, 278, 0, 0),
    L6(2, 0, 0, 0, 0, 496, 0, 0x2BAD, 0, 77, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 497, 0, 0x2BAE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 64, 0, 0, 0, 498, 0, 0x2BAF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 499, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 500, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 501, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 501, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A */
const u16 ibuki_atca_009_head[4] = { HEAD(6, 0, 1, 10, 0, 1, 0) };
const u16 ibuki_atca_009[196] = {
    CMD(CM_RMJA, 4, 160, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1042, 0, 0x2C0D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1043, 0, 0x2C0E, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 1044, 0, 0x2C0F, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1045, 0, 0x2C10, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1046, 0, 0x2C11, -21, 58, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1047, 0, 0x2C12, 22, 184, 2703, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1048, 0, 0x2C13, 0, 59, 2703, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1049, 0, 0x2C14, 0, 59, 2703, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1050, 0, 0x2C15, 0, 56, 2703, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 1051, 0, 0x2C16, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1052, 0, 0x2C17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1053, 0, 0x2A3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1054, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1055, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1055, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 S KICK B, 11 S KICK C */
const u16 ibuki_atca_010_head[4] = { HEAD(6, 0, 1, 12, 0, 1, 0) };
const u16 ibuki_atca_010[244] = {
    L6(1, 0, 0, 0, 0, 461, 0, 0x2BDE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 462, 0, 0x2BDF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 268, 0, 0, 463, 0, 0x2BE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(1, 0, 0, 0, 0, 464, 0, 0x2BE1, -23, 60, 0, 128, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 0, 0, 0, 465, 0, 0x2BE2, 24, 61, 0, 0, 16, 0, 19, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 466, 0, 0x2BE3, 0, 62, 0, 0, 16, 21, 20, 0, 0, 0, 12, 0),
    L6(1, 0, 0, 0, 0, 462, 0, 0x2BDF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 268, 0, 0, 463, 0, 0x2BE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(1, 0, 0, 0, 0, 464, 0, 0x2BE1, -113, 60, 0, 128, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 0, 0, 0, 465, 0, 0x2BE2, 114, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 466, 0, 0x2BE3, 0, 62, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 467, 0, 0x2BE4, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 468, 0, 0x2BE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 469, 0, 0x2BE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(2, 64, 0, 0, 0, 470, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(3, 0, 0, 0, 0, 471, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 472, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 473, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 466, 0, 0x2BE3, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 268, 0, 0, 463, 0, 0x2BE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 4, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 ibuki_atca_012_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_012[280] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1057, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1058, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 1059, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(2, 0, 269, 0, 0, 1060, 0, 0x2BE9, 0, 65, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(2, 1, 0, 0, 0, 1061, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(2, 0, 0, 0, 0, 1062, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1063, 0, 0x2BEC, 0, 66, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 0, 0, 0, 1064, 0, 0x2BED, -26, 67, 2692, 0, 8, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 1065, 0, 0x2BEE, 0, 66, 0, 0, 0, 21, 0, 0, 0, 122, 0, 0),
    L6(1, 1, 0, 0, 0, 1066, 0, 0x2BEF, 0, 66, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 0, 0, 0, 1067, 0, 0x2BF0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1068, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1069, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 1070, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 1071, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    L6(1, 0, 0, 0, 0, 1072, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(1, 0, 0, 0, 0, 1073, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(2, 64, 0, 0, 0, 1074, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1075, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1076, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1077, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1077, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 ibuki_atca_013_head[4] = { HEAD(6, 0, 3, 7, 0, 1, 0) };
const u16 ibuki_atca_013[184] = {
    CMD(CM_RMJA, 4, 161, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 474, 0, 0x2C1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 269, 0, 0, 475, 0, 0x2C1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 476, 0, 0x2C18, 0, 63, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 477, 0, 0x2C19, -25, 64, 0, 135, 96, 0, 0, 0, 0, 106, 0, 0),
    L6(3, 0, 0, 0, 0, 478, 0, 0x2C1A, 0, 78, 3215, 0, 104, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 479, 0, 0x2C1B, 0, 79, 3215, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 480, 0, 0x2C1C, 0, 79, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(2, 0, 0, 0, 0, 481, 0, 0x2C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 482, 0, 0x2C2B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(2, 0, 0, 0, 0, 483, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(3, 64, 0, 0, 0, 484, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 485, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 486, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 486, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 ibuki_atca_014_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_014[232] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1124, 0, 0x2C34, 0, 20, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1125, 0, 0x2BF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1126, 0, 0x2BF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1127, 0, 0x2BFA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1128, 0, 0x2BFB, 0, 21, 0, 0, 0, 30, 41, 0, 0, 0, 0, 0),
    L6(1, 0, 356, 0, 0, 1128, 0, 0x2BFB, 0, 21, 0, 0, 0, 30, 42, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 1129, 0, 0x2BFC, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1130, 0, 0x2BFD, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1131, 0, 0x2BFE, 0, 22, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 1132, 0, 0x2C2C, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1133, 0, 0x2C2D, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1134, 0, 0x2C2E, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 1135, 0, 0x2C2F, 0, 22, 0, 0, 0, 33, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 1136, 0, 0x2C30, 0, 181, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 1137, 0, 0x2C31, -3, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1138, 0, 0x2C32, 4, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1139, 0, 0x2C33, 0, 25, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A */
const u16 ibuki_atca_015_head[4] = { HEAD(6, 0, 5, 9, 0, 2, 0) };
const u16 ibuki_atca_015[244] = {
    L6(2, 0, 0, 0, 0, 1078, 0, 0x2C1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(1, 0, 0, 0, 0, 1079, 0, 0x2C1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 270, 0, 0, 1080, 0, 0x2C1F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 359, 0, 0, 1081, 0, 0x2C20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1082, 0, 0x2C21, -49, 113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1083, 0, 0x2C22, 0, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1084, 0, 0x2C23, -27, 69, 0, 128, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1085, 0, 0x2C24, 28, 70, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 1086, 0, 0x2C25, 0, 71, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1087, 0, 0x2C26, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1088, 0, 0x2C27, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1089, 0, 0x2C28, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1090, 0, 0x2C29, 0, 72, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(3, 64, 0, 0, 0, 1091, 0, 0x2C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 0, 0, 0, 1092, 0, 0x2C2B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(3, 0, 0, 0, 0, 1093, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(3, 0, 0, 0, 0, 1094, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1095, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1096, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1096, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 L KICK B */
const u16 ibuki_atca_016_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 ibuki_atca_016[316] = {
    L6(1, 0, 0, 0, 0, 1124, 0, 0x2C34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1142, 0, 0x2B74, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 1143, 0, 0x2B75, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 357, 0, 0, 1144, 0, 0x2B76, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 270, 0, 0, 1145, 0, 0x2B82, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 1146, 0, 0x2B77, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1147, 0, 0x2B78, -72, 125, 0, 136, 0, 0, 0, 0, 0, 0, 11, 0),
    CMD(CM_HJMP, 8192, 16387, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1147, 0, 0x2B78, 0, 125, 0, 0, 1, 0, 0, 0, 0, 0, 11, 0),
    L6(1, 0, 0, 0, 0, 1147, 0, 0x2B78, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1148, 0, 0x2B79, 72, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1149, 0, 0x2B7A, 0, 178, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1150, 0, 0x2B7B, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1151, 0, 0x2B7C, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1152, 0, 0x2B7D, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 1153, 0, 0x2B7E, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 1154, 0, 0x2B7F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1155, 0, 0x2B80, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1156, 0, 0x2B81, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 1, 1157, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 1, 1158, 0, 0x2A17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 1159, 0, 0x2A18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1160, 0, 0x2A19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1161, 0, 0x2A1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 ibuki_atca_017_head[4] = { HEAD(6, 0, 5, 15, 0, 1, 0) };
const u16 ibuki_atca_017[352] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1097, 0, 0x2BF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1098, 0, 0x2BF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1099, 0, 0x2BFA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 1100, 0, 0x2BFB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 0, 0, 0, 0, 1101, 0, 0x2BFC, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1102, 0, 0x2BFD, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1103, 0, 0x2BFE, 0, 33, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 270, 0, 0, 1104, 0, 0x2BFF, 0, 33, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 1105, 0, 0x2C00, 0, 33, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 1106, 0, 0x2C0B, -9, 34, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1107, 0, 0x2C0C, 0, 35, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1108, 0, 0x2C02, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1109, 0, 0x2C03, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1110, 0, 0x2C04, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1111, 0, 0x2C05, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1112, 0, 0x2C06, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1113, 0, 0x2C07, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1114, 0, 0x2C08, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 2, 273, 0, 0, 1115, 0, 0x2C09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 1116, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 1117, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 1118, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1119, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1120, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1121, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1122, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1123, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1123, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 ibuki_atca_018_head[4] = { HEAD(4, 32, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_018[92] = {
    L4(3, 0, 268, 0, 0, 779, 0, 0x2C36, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 780, 0, 0x2D36, -32, 80, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 781, 0, 0x2D37, 0, 239, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 782, 0, 0x2D38, 0, 240, 0, 0, 96, 0, 0),
    L4(3, 64, 0, 0, 0, 783, 0, 0x2C3C, 0, 2, 0, 0, 4, 0, 0),
    L4(3, 0, 0, 0, 0, 784, 0, 0x2C3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 ibuki_atca_021_head[4] = { HEAD(4, 32, 2, 15, 0, 1, 0) };
const u16 ibuki_atca_021[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E1C, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E1D, 0, 263, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E1E, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E1F, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E20, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x2E21, 0, 265, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E22, 0, 266, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E23, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E24, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E25, -108, 268, 0, 140, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E26, 0, 269, 0, 0, 96, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E27, 0, 269, 0, 0, 96, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E28, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E29, 0, 271, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E2A, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2E2B, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E2C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E2D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E2E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E2F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E30, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 ibuki_atca_024_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 ibuki_atca_024[280] = {
    L6(1, 0, 0, 0, 0, 794, 0, 0x2C4F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 795, 0, 0x2C50, 0, 2, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(3, 0, 0, 0, 0, 796, 0, 0x2C51, 0, 83, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(1, 0, 270, 0, 0, 797, 0, 0x2C52, 0, 83, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 798, 0, 0x2C53, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 799, 0, 0x2C54, -33, 84, 0, 128, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 800, 0, 0x2C55, 34, 85, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 801, 0, 0x2C56, 0, 86, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 802, 0, 0x2C55, 0, 86, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 803, 0, 0x2C56, 0, 86, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 804, 0, 0x2C55, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 805, 0, 0x2C56, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 806, 0, 0x2C57, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 807, 0, 0x2C59, 0, 83, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 808, 0, 0x2C5A, 0, 83, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 809, 0, 0x2C5C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 64, 0, 0, 0, 810, 0, 0x2C5E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 811, 0, 0x2C5F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 ibuki_atca_027_head[4] = { HEAD(4, 32, 1, 12, 0, 1, 0) };
const u16 ibuki_atca_027[132] = {
    L4(2, 0, 0, 0, 0, 812, 0, 0x2C60, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 813, 0, 0x2C61, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 814, 0, 0x2C62, -35, 87, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 815, 0, 0x2C63, 0, 88, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 816, 0, 0x2C64, 0, 89, 0, 0, 112, 0, 0),
    L4(2, 0, 0, 0, 0, 817, 0, 0x2C65, 0, 2, 0, 0, 4, 0, 0),
    L4(2, 64, 0, 0, 0, 818, 0, 0x2C66, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 819, 0, 0x2C67, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 820, 0, 0x2C68, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 821, 0, 0x2C69, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 822, 0, 0x2C6A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B */
const u16 ibuki_atca_030_head[4] = { HEAD(4, 32, 3, 14, 0, 1, 0) };
const u16 ibuki_atca_030[164] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E31, 0, 273, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E32, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x2E33, 0, 275, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E34, 0, 276, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E35, -178, 277, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E36, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E37, 0, 279, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E38, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E39, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E3A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E3B, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2E3C, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E42, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2E43, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 KAGAMI K C */
const u16 ibuki_atca_032_head[4] = { HEAD(6, 32, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_032[316] = {
    CMD(CM_RJA6, 4, 32, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 4, 32, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 1163, 0, 0x2DDC, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 279, 0, 0, 1164, 0, 0x2DDE, -103, 155, 0, 0, 0, 30, 9, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDE, 0, 155, 0, 0, 0, 30, 10, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDE, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDE, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8199, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1165, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1165, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 ibuki_atca_033_head[4] = { HEAD(6, 32, 5, 13, 1, 9, 0) };
const u16 ibuki_atca_033[292] = {
    L6(1, 0, 0, 0, 0, 823, 0, 0x2A52, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 824, 0, 0x2A53, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 825, 0, 0x2A54, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 826, 0, 0x2A55, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 827, 0, 0x2C6B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 270, 0, 0, 828, 0, 0x2C6C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(1, 0, 0, 0, 0, 829, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(1, 0, 0, 0, 0, 830, 0, 0x2C6E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 831, 0, 0x2C6F, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 831, 0, 0x2C6F, -5, 26, 1157, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 832, 0, 0x2C70, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 833, 0, 0x2C71, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 834, 0, 0x2C72, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 835, 0, 0x2C73, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 836, 0, 0x2C74, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 837, 0, 0x2C75, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 838, 0, 0x2C76, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 839, 0, 0x2C77, 0, 2, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 840, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 841, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 842, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 843, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 844, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 844, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 ibuki_atca_036_head[4] = { HEAD(4, 22, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_036[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 845, 6, 0x2C90, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 846, 6, 0x2C91, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 847, 6, 0x2C92, -36, 93, 0, 73, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 848, 6, 0x2C93, 0, 91, 0, 73, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 849, 6, 0x2C94, 0, 91, 0, 73, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 850, 6, 0x2C95, 0, 91, 0, 73, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 851, 6, 0x2C96, 0, 92, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 852, 6, 0x2C97, 0, 92, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 853, 6, 0x2C98, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 855, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 856, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 857, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 ibuki_atca_038_head[4] = { HEAD(6, 22, 2, 12, 0, 1, 0) };
const u16 ibuki_atca_038[232] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 269, 0, 0, 845, 6, 0x2C90, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 846, 6, 0x2C91, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 847, 6, 0x2C92, -37, 175, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 848, 6, 0x2C93, 38, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 849, 6, 0x2C94, 0, 176, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 850, 6, 0x2C95, 0, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 851, 6, 0x2C96, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 852, 6, 0x2C97, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 853, 5, 0x2C98, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 854, 0, 0x2CA3, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 855, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 856, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 857, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1861, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 17), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 ibuki_atca_040_head[4] = { HEAD(6, 22, 4, 11, 0, 1, 0) };
const u16 ibuki_atca_040[256] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 858, 5, 0x2C80, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 859, 5, 0x2C81, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 860, 6, 0x2C82, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 861, 6, 0x2C84, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 862, 6, 0x2C85, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 863, 6, 0x2C87, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 864, 6, 0x2C89, -39, 96, 0, 140, 0, 0, 0, 0, 0, 0, 13, 0),
    L6(1, 0, 0, 0, 0, 865, 6, 0x2C8A, 0, 97, 2692, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 866, 6, 0x2C8B, 0, 97, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 867, 5, 0x2C8C, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 868, 0, 0x2C8D, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 869, 0, 0x2C8E, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 870, 0, 0x2C8F, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 871, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 872, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1861, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 19), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 ibuki_atca_042_head[4] = { HEAD(4, 22, 1, 12, 0, 1, 0) };
const u16 ibuki_atca_042[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 873, 5, 0x2CC3, 0, 98, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 874, 5, 0x2CC4, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 875, 5, 0x2CC5, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 876, 5, 0x2CC6, -43, 99, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 877, 5, 0x2CC7, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 878, 5, 0x2CC8, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 879, 5, 0x2CC9, 0, 100, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 880, 5, 0x2CC7, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 881, 5, 0x2CC8, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 882, 5, 0x2CC9, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 883, 5, 0x2CC7, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 884, 5, 0x2CC8, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 885, 5, 0x2CC9, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 886, 5, 0x2CC7, 0, 100, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 ibuki_atca_044_head[4] = { HEAD(4, 22, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_044[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 873, 5, 0x2CC3, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 874, 5, 0x2CC4, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 875, 5, 0x2CC5, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 876, 5, 0x2CC6, -106, 174, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 877, 5, 0x2CC7, 107, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 878, 5, 0x2CC8, 107, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 879, 5, 0x2CC9, 0, 101, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 880, 5, 0x2CCA, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 881, 5, 0x2CCB, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 882, 5, 0x2CCC, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 883, 0, 0x2CCD, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 855, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 856, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 857, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1861, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 15), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 ibuki_atca_046_head[4] = { HEAD(4, 22, 5, 12, 0, 1, 0) };
const u16 ibuki_atca_046[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 887, 5, 0x2CB7, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 888, 5, 0x2CB8, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 889, 5, 0x2CB9, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 890, 5, 0x2CBA, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 891, 5, 0x2CBB, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 892, 5, 0x2CBC, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 893, 5, 0x2CBD, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 894, 5, 0x2CBE, -6, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 895, 5, 0x2CBF, 7, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 896, 5, 0x2CC0, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 897, 5, 0x2CC1, 0, 10, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 898, 0, 0x2CC2, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 899, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 900, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1861, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 15), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 ibuki_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_048[172] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 901, 5, 0x2C79, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 902, 5, 0x2C9A, 0, 103, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 903, 5, 0x2C7A, -40, 104, 2244, 79, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 904, 5, 0x2C7B, 0, 105, 2244, 79, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 905, 5, 0x2C7C, 0, 105, 2244, 79, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 906, 5, 0x2C7D, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 904, 5, 0x2C7B, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 905, 5, 0x2C7C, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 906, 5, 0x2C7D, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 904, 5, 0x2C7B, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 905, 5, 0x2C7C, 0, 105, 0, 79, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 906, 5, 0x2C7D, 0, 105, 0, 79, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 907, 5, 0x2C7E, 0, 103, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 908, 5, 0x2C7F, 0, 103, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 909, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 910, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 911, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1860, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 19), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 ibuki_atca_050_head[4] = { HEAD(4, 20, 2, 11, 0, 1, 0) };
const u16 ibuki_atca_050[188] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 5, 0x2E44, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x2E45, 0, 300, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x2E46, 0, 301, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x2E47, -37, 302, 0, 140, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E48, 38, 303, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E49, 38, 303, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E4A, 38, 303, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 4, 50, 15), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E48, 0, 304, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E49, 0, 304, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E4A, 0, 304, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E4B, 0, 305, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E4C, 0, 305, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x2E4D, 0, 306, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E4E, 0, 307, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E4F, 0, 308, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 922, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 923, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1860, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 21), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 ibuki_atca_052_head[4] = { HEAD(2, 20, 4, 12, 0, 1, 0) };
const u16 ibuki_atca_052[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 ibuki_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 ibuki_atca_054[148] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 912, 5, 0x2CA5, 0, 36, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 913, 5, 0x2CA6, 0, 36, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 914, 5, 0x2CA7, -10, 37, 0, 138, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 915, 5, 0x2CA8, 0, 38, 0, 139, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 916, 5, 0x2CA9, 0, 38, 0, 139, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 917, 5, 0x2CAA, 0, 38, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 918, 5, 0x2CA8, 0, 38, 2692, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 918, 5, 0x2CA8, 0, 38, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 919, 5, 0x2CAB, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 920, 5, 0x2CAC, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 921, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 922, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 923, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1860, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 16), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 ibuki_atca_056_head[4] = { HEAD(4, 20, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_056[148] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 924, 5, 0x2CAD, 0, 39, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 925, 5, 0x2CAE, 0, 39, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 926, 5, 0x2CAF, -11, 40, 0, 136, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 927, 5, 0x2CB0, 12, 41, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 928, 5, 0x2CB1, 12, 41, 0, 138, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 929, 5, 0x2CB2, 12, 41, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 927, 5, 0x2CB0, 12, 41, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 928, 5, 0x2CB1, 12, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 929, 5, 0x2CB2, 12, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 930, 5, 0x2CB3, 0, 39, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 931, 5, 0x2CB4, 0, 39, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 932, 5, 0x2CB5, 0, 39, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 933, 0, 0x2CB6, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 934, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 935, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1860, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 16), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 ibuki_atca_058_head[4] = { HEAD(4, 20, 5, 13, 0, 1, 0) };
const u16 ibuki_atca_058[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 936, 5, 0x2CB7, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 937, 5, 0x2CB8, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 938, 5, 0x2CB9, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 939, 5, 0x2CBA, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 940, 5, 0x2CBB, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 941, 5, 0x2CBC, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 942, 5, 0x2CBD, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 943, 5, 0x2CBE, -6, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 944, 5, 0x2CBF, 7, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 945, 5, 0x2CC0, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 946, 5, 0x2CC1, 0, 10, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 947, 0, 0x2CC2, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 948, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 949, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1860, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 15), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 ibuki_atca_060_head[4] = { HEAD(2, 24, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 ibuki_atca_062_head[4] = { HEAD(2, 24, 2, 11, 0, 1, 0) };
const u16 ibuki_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 ibuki_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 ibuki_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 ibuki_atca_066_head[4] = { HEAD(2, 24, 1, 8, 0, 1, 0) };
const u16 ibuki_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 ibuki_atca_068_head[4] = { HEAD(2, 24, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 ibuki_atca_070_head[4] = { HEAD(2, 24, 5, 13, 0, 1, 0) };
const u16 ibuki_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 ibuki_atca_072_head[4] = { HEAD(2, 28, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 ibuki_atca_074_head[4] = { HEAD(2, 28, 2, 12, 0, 1, 0) };
const u16 ibuki_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 ibuki_atca_076_head[4] = { HEAD(2, 28, 4, 11, 0, 1, 0) };
const u16 ibuki_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 ibuki_atca_078_head[4] = { HEAD(2, 28, 1, 12, 0, 1, 0) };
const u16 ibuki_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 ibuki_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 ibuki_atca_082_head[4] = { HEAD(2, 28, 5, 12, 0, 1, 0) };
const u16 ibuki_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 ibuki_atca_084_head[4] = { HEAD(2, 26, 0, 12, 0, 1, 0) };
const u16 ibuki_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 ibuki_atca_086_head[4] = { HEAD(2, 26, 2, 12, 0, 1, 0) };
const u16 ibuki_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 ibuki_atca_088_head[4] = { HEAD(2, 26, 4, 13, 0, 1, 0) };
const u16 ibuki_atca_088[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 ibuki_atca_090_head[4] = { HEAD(2, 26, 1, 9, 0, 1, 0) };
const u16 ibuki_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 ibuki_atca_092_head[4] = { HEAD(2, 26, 3, 14, 0, 1, 0) };
const u16 ibuki_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 ibuki_atca_094_head[4] = { HEAD(2, 26, 5, 14, 0, 1, 0) };
const u16 ibuki_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 ibuki_atca_096_head[4] = { HEAD(2, 30, 0, 11, 0, 1, 0) };
const u16 ibuki_atca_096[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 ibuki_atca_098_head[4] = { HEAD(2, 30, 2, 11, 0, 1, 0) };
const u16 ibuki_atca_098[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 ibuki_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 ibuki_atca_100[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 ibuki_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 ibuki_atca_102[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 ibuki_atca_104_head[4] = { HEAD(2, 30, 3, 12, 0, 1, 0) };
const u16 ibuki_atca_104[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 ibuki_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 ibuki_atca_106[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 ibuki_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 1, 0) };
const u16 ibuki_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 ibuki_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 1, 0) };
const u16 ibuki_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 ibuki_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 1, 0) };
const u16 ibuki_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 ibuki_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 1, 0) };
const u16 ibuki_atca_114[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 ibuki_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 1, 0) };
const u16 ibuki_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 ibuki_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 1, 0) };
const u16 ibuki_atca_118[152] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3584, 0, 256),
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3586, 0, 256),
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3588, 0, 256),
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3585, 0, 256),
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3587, 0, 256),
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3589, 0, 256),
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4608, 0, 256),
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4610, 0, 256),
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4612, 0, 256),
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4609, 0, 256),
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4611, 0, 256),
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4613, 0, 256),
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 ibuki_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_atca_144[100] = {
    CMD(CM_CAFR, 2, 2, 11), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 11), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E57, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2E57, -70, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x2E58, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E51, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2E52, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2E53, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E54, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E55, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2E56, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2E56, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 ibuki_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 150 TUKAMI AIR A, 151 TUKAMI AIR B, 152 TUKAMI AIR C, 153 TUKAMI AIR D ... */
const u16 ibuki_atca_150_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 ibuki_atca_150[116] = {
    CMD(CM_CAFR, 2, 5, 15), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 15), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x2E61, 0, 90, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 6, 0x2E62, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x2E63, -70, 199, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2E63, 0, 90, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2E64, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x2E65, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 854, 0, 0x2CA3, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 855, 0, 0x2CA4, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 856, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 857, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1861, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of M KICK A */
const u16 ibuki_atca_156_head[4] = { HEAD(6, 0, 5, 13, 0, 1, 0) };
const u16 ibuki_atca_156[244] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 32, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 4, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1124, 0, 0x2C34, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1125, 0, 0x2BF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1126, 0, 0x2BF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1127, 0, 0x2BFA, 0, 1, 0, 0, 0, 30, 41, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1128, 0, 0x2BFB, 0, 1, 0, 0, 0, 30, 42, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 1129, 0, 0x2BFC, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1130, 0, 0x2BFD, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1131, 0, 0x2BFE, 0, 21, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 1132, 0, 0x2C2C, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1133, 0, 0x2C2D, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1134, 0, 0x2C2E, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 1135, 0, 0x2C2F, 0, 22, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 1136, 0, 0x2C30, 0, 22, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 1137, 0, 0x2C31, -174, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1138, 0, 0x2C32, 174, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1139, 0, 0x2C33, 0, 25, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of M PUNCH C, L PUNCH A */
const u16 ibuki_atca_157_head[4] = { HEAD(6, 32, 5, 13, 0, 1, 0) };
const u16 ibuki_atca_157[244] = {
    CMD(CM_RMJA, 4, 167, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 270, 0, 0, 828, 0, 0x2C6C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(1, 0, 0, 0, 0, 829, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(1, 0, 0, 0, 0, 830, 0, 0x2C6E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 831, 0, 0x2C6F, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 831, 0, 0x2C6F, -126, 26, 3205, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 832, 0, 0x2C70, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 833, 0, 0x2C71, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 834, 0, 0x2C72, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 835, 0, 0x2C73, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 836, 0, 0x2C74, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 837, 0, 0x2C75, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 838, 0, 0x2C76, 0, 2, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 839, 0, 0x2C77, 0, 2, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 840, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 841, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 842, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 843, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 844, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 844, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of V JUMP P L A, F JUMP K S A */
const u16 ibuki_atca_158_head[4] = { HEAD(4, 20, 3, 13, 0, 1, 0) };
const u16 ibuki_atca_158[124] = {
    L4(3, 0, 269, 0, 0, 925, 8, 0x2CAE, 0, 39, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 926, 8, 0x2CAF, -127, 40, 0, 136, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 927, 8, 0x2CB0, 128, 41, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 928, 8, 0x2CB1, 128, 41, 0, 138, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 929, 8, 0x2CB2, 128, 41, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 927, 8, 0x2CB0, 128, 41, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 928, 8, 0x2CB1, 128, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 929, 8, 0x2CB2, 128, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 930, 8, 0x2CB3, 0, 39, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 931, 8, 0x2CB4, 0, 39, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 932, 6, 0x2CB5, 0, 39, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 933, 0, 0x2CB6, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 934, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 935, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of F JUMP P S A */
const u16 ibuki_atca_159_head[4] = { HEAD(6, 22, 4, 12, 0, 1, 0) };
const u16 ibuki_atca_159[160] = {
    L6(2, 0, 0, 0, 0, 861, 8, 0x2C84, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 862, 8, 0x2C85, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 863, 8, 0x2C87, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 864, 8, 0x2C89, -133, 96, 0, 133, 0, 0, 0, 0, 0, 0, 6, 0),
    L6(1, 0, 0, 0, 0, 865, 8, 0x2C8A, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 866, 8, 0x2C8B, 0, 97, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 867, 6, 0x2C8C, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 868, 0, 0x2C8D, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 869, 0, 0x2C8E, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 870, 0, 0x2C8F, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 871, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 872, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of S KICK A */
const u16 ibuki_atca_160_head[4] = { HEAD(6, 0, 3, 7, 0, 1, 0) };
const u16 ibuki_atca_160[172] = {
    CMD(CM_RMJA, 4, 161, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 269, 0, 0, 475, 0, 0x2C1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 476, 0, 0x2C18, 0, 63, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 477, 0, 0x2C19, -140, 64, 0, 128, 96, 0, 0, 0, 0, 106, 0, 0),
    L6(3, 0, 0, 0, 0, 478, 0, 0x2C1A, 0, 78, 3215, 0, 104, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 479, 0, 0x2C1B, 0, 79, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 480, 0, 0x2C1C, 0, 79, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(2, 64, 0, 0, 0, 481, 0, 0x2C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 482, 0, 0x2C2B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(3, 0, 0, 0, 0, 483, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(3, 0, 0, 0, 0, 484, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 485, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 486, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 486, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 161 follow-up of M KICK B */
const u16 ibuki_atca_161_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 ibuki_atca_161[268] = {
    L6(2, 0, 0, 0, 0, 1142, 0, 0x2B74, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 1143, 0, 0x2B75, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 358, 0, 0, 1144, 0, 0x2B76, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 270, 0, 0, 1145, 0, 0x2B82, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 1146, 0, 0x2B77, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1147, 0, 0x2B78, -141, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1148, 0, 0x2B79, 141, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1149, 0, 0x2B7A, 0, 178, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1150, 0, 0x2B7B, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1151, 0, 0x2B7C, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1152, 0, 0x2B7D, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 1153, 0, 0x2B7E, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 1154, 0, 0x2B7F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1155, 0, 0x2B80, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1156, 0, 0x2B81, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 1, 1157, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(3, 0, 0, 0, 1, 1158, 0, 0x2A17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 1159, 0, 0x2A18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1160, 0, 0x2A19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1161, 0, 0x2A1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 162 follow-up of S PUNCH A */
const u16 ibuki_atca_162_head[4] = { HEAD(6, 0, 2, 9, 0, 2, 0) };
const u16 ibuki_atca_162[232] = {
    CMD(CM_RMJA, 4, 165, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 388, 0, 0x2BBE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 389, 0, 0x2BBF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 390, 0, 0x2BC0, 0, 43, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 391, 0, 0x2BC1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 269, 0, 0, 392, 0, 0x2BC2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 393, 0, 0x2BC3, -13, 44, 2255, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 394, 0, 0x2BC4, -14, 45, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 395, 0, 0x2BC5, 15, 46, 3074, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 396, 0, 0x2BC6, 0, 47, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 397, 0, 0x2BC7, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 398, 0, 0x2BC8, 0, 43, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(4, 64, 0, 0, 0, 399, 0, 0x2BC9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(4, 0, 0, 0, 0, 400, 0, 0x2BCA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(4, 0, 0, 0, 0, 401, 0, 0x2BCB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(4, 0, 0, 0, 0, 402, 0, 0x2B8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(3, 0, 0, 0, 0, 403, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 403, 0, 0x2B8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 163 no name */
const u16 ibuki_atca_163_head[4] = { HEAD(4, 32, 2, 12, 0, 1, 0) };
const u16 ibuki_atca_163[124] = {
    CMD(CM_RMJA, 4, 164, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 785, 0, 0x2C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 786, 0, 0x2C36, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 787, 0, 0x2C37, -171, 167, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 788, 0, 0x2C38, 0, 81, 2114, 0, 104, 21, 0),
    L4(3, 0, 0, 0, 0, 789, 0, 0x2C39, 0, 82, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 790, 0, 0x2C3A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 791, 0, 0x2C3B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 792, 0, 0x2C3C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 793, 0, 0x2C3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 164 no name */
const u16 ibuki_atca_164_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 ibuki_atca_164[256] = {
    L6(2, 0, 0, 0, 0, 796, 0, 0x2C51, 0, 83, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(1, 0, 270, 0, 0, 797, 0, 0x2C52, 0, 83, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 798, 0, 0x2C53, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 799, 0, 0x2C54, -172, 84, 0, 128, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 800, 0, 0x2C55, 172, 85, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 801, 0, 0x2C56, 0, 86, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 802, 0, 0x2C55, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 803, 0, 0x2C56, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 804, 0, 0x2C55, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 805, 0, 0x2C56, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 806, 0, 0x2C57, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 807, 0, 0x2C59, 0, 83, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 808, 0, 0x2C5A, 0, 83, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 809, 0, 0x2C5C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 64, 0, 0, 0, 810, 0, 0x2C5E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 811, 0, 0x2C5F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 165 follow-up of M PUNCH C */
const u16 ibuki_atca_165_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 ibuki_atca_165[148] = {
    L6(2, 1, 270, 0, 0, 1247, 0, 0x2BB5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(2, 1, 357, 0, 0, 1247, 0, 0x2BB5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 1248, 0, 0x2BB6, -48, 110, 0, 128, 96, 0, 0, 0, 0, 222, 0, 0),
    L6(5, 0, 0, 0, 0, 1249, 0, 0x2BB7, 48, 110, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1250, 0, 0x2B98, 0, 1, 0, 0, 0, 21, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 1251, 0, 0x2B99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(2, 0, 0, 0, 0, 1252, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(2, 64, 0, 0, 0, 1252, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1253, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1254, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1255, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1255, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 166 no name */
const u16 ibuki_atca_166_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 ibuki_atca_166[280] = {
    L6(3, 0, 0, 0, 0, 794, 0, 0x2C4F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(4, 0, 0, 0, 0, 795, 0, 0x2C50, 0, 2, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 796, 0, 0x2C51, 0, 83, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(1, 0, 270, 0, 0, 797, 0, 0x2C52, 0, 83, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 798, 0, 0x2C53, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 799, 0, 0x2C54, -175, 84, 0, 128, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 800, 0, 0x2C55, -176, 85, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 801, 0, 0x2C56, 0, 86, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 802, 0, 0x2C55, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 803, 0, 0x2C56, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 804, 0, 0x2C55, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 805, 0, 0x2C56, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 806, 0, 0x2C57, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 807, 0, 0x2C59, 0, 83, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 808, 0, 0x2C5A, 0, 83, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 809, 0, 0x2C5C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 64, 0, 0, 0, 810, 0, 0x2C5E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 811, 0, 0x2C5F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 775, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 776, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 777, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 778, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 167 follow-up of follow-up of M PUNCH C, L PUNCH A */
const u16 ibuki_atca_167_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 ibuki_atca_167[316] = {
    L6(1, 0, 0, 0, 0, 1124, 0, 0x2C34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1142, 0, 0x2B74, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 1143, 0, 0x2B75, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 358, 0, 0, 1144, 0, 0x2B76, 0, 178, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 270, 0, 0, 1145, 0, 0x2B82, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 1146, 0, 0x2B77, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1147, 0, 0x2B78, -177, 125, 0, 136, 0, 0, 0, 0, 0, 0, 11, 0),
    CMD(CM_HJMP, 8192, 16387, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1147, 0, 0x2B78, 0, 125, 0, 0, 1, 0, 0, 0, 0, 0, 11, 0),
    L6(1, 0, 0, 0, 0, 1147, 0, 0x2B78, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1148, 0, 0x2B79, 72, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1149, 0, 0x2B7A, 0, 178, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1150, 0, 0x2B7B, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1151, 0, 0x2B7C, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1152, 0, 0x2B7D, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 1153, 0, 0x2B7E, 0, 178, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 1154, 0, 0x2B7F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1155, 0, 0x2B80, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1156, 0, 0x2B81, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 1, 1157, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 1, 1158, 0, 0x2A17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 1159, 0, 0x2A18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1160, 0, 0x2A19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1161, 0, 0x2A1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 1162, 0, 0x2A1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX ibuki_olc_ix_table[2230] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 2, 0, 0, 0 } },
    { { 4, 0, 0, 0 } },
    { { 6, 0, 0, 0 } },
    { { 8, 0, 0, 0 } },
    { { 10, 0, 0, 0 } },
    { { 12, 0, 0, 0 } },
    { { 14, 0, 0, 0 } },
    { { 16, 0, 0, 0 } },
    { { 23, 0, 0, 0 } },
    { { 24, 0, 0, 0 } },
    { { 25, 0, 0, 0 } },
    { { 26, 0, 0, 0 } },
    { { 27, 0, 0, 0 } },
    { { 28, 0, 0, 0 } },
    { { 29, 0, 0, 0 } },
    { { 30, 0, 0, 0 } },
    { { 31, 0, 0, 0 } },
    { { 32, 0, 0, 0 } },
    { { 33, 0, 0, 0 } },
    { { 34, 0, 0, 0 } },
    { { 35, 0, 0, 0 } },
    { { 36, 0, 0, 0 } },
    { { 37, 0, 0, 0 } },
    { { 38, 0, 0, 0 } },
    { { 39, 0, 0, 0 } },
    { { 40, 0, 0, 0 } },
    { { 41, 0, 0, 0 } },
    { { 42, 0, 0, 0 } },
    { { 43, 0, 0, 0 } },
    { { 44, 0, 0, 0 } },
    { { 45, 0, 0, 0 } },
    { { 46, 0, 0, 0 } },
    { { 47, 0, 0, 0 } },
    { { 48, 0, 0, 0 } },
    { { 49, 0, 0, 0 } },
    { { 50, 0, 0, 0 } },
    { { 51, 0, 0, 0 } },
    { { 52, 35, 0, 0 } },
    { { 53, 36, 0, 0 } },
    { { 54, 37, 0, 0 } },
    { { 55, 38, 0, 0 } },
    { { 56, 39, 0, 0 } },
    { { 57, 40, 0, 0 } },
    { { 58, 41, 0, 0 } },
    { { 59, 42, 0, 0 } },
    { { 60, 43, 0, 0 } },
    { { 61, 44, 0, 0 } },
    { { 62, 0, 0, 0 } },
    { { 71, 0, 0, 0 } },
    { { 80, 0, 0, 0 } },
    { { 81, 0, 0, 0 } },
    { { 82, 0, 0, 0 } },
    { { 83, 0, 0, 0 } },
    { { 84, 0, 0, 0 } },
    { { 85, 0, 0, 0 } },
    { { 86, 0, 0, 0 } },
    { { 87, 0, 0, 0 } },
    { { 88, 0, 0, 0 } },
    { { 89, 0, 0, 0 } },
    { { 90, 0, 0, 0 } },
    { { 91, 0, 0, 0 } },
    { { 92, 0, 0, 0 } },
    { { 93, 0, 0, 0 } },
    { { 94, 0, 0, 0 } },
    { { 95, 0, 0, 0 } },
    { { 96, 0, 0, 0 } },
    { { 97, 0, 0, 0 } },
    { { 98, 0, 0, 0 } },
    { { 99, 0, 0, 0 } },
    { { 100, 0, 0, 0 } },
    { { 101, 0, 0, 0 } },
    { { 102, 0, 0, 0 } },
    { { 103, 0, 0, 0 } },
    { { 104, 0, 0, 0 } },
    { { 105, 0, 0, 0 } },
    { { 106, 0, 0, 0 } },
    { { 107, 0, 0, 0 } },
    { { 108, 0, 0, 0 } },
    { { 109, 0, 0, 0 } },
    { { 110, 0, 0, 0 } },
    { { 111, 0, 0, 0 } },
    { { 112, 0, 0, 0 } },
    { { 113, 0, 0, 0 } },
    { { 114, 0, 0, 0 } },
    { { 115, 0, 0, 0 } },
    { { 116, 0, 0, 0 } },
    { { 117, 0, 0, 0 } },
    { { 118, 0, 0, 0 } },
    { { 119, 0, 0, 0 } },
    { { 120, 0, 0, 0 } },
    { { 121, 0, 0, 0 } },
    { { 122, 0, 0, 0 } },
    { { 123, 0, 0, 0 } },
    { { 124, 0, 0, 0 } },
    { { 125, 0, 0, 0 } },
    { { 126, 0, 0, 0 } },
    { { 127, 0, 0, 0 } },
    { { 128, 0, 0, 0 } },
    { { 129, 0, 0, 0 } },
    { { 130, 0, 0, 0 } },
    { { 131, 0, 0, 0 } },
    { { 132, 0, 0, 0 } },
    { { 133, 0, 0, 0 } },
    { { 134, 0, 0, 0 } },
    { { 135, 0, 0, 0 } },
    { { 136, 0, 0, 0 } },
    { { 137, 0, 0, 0 } },
    { { 138, 0, 0, 0 } },
    { { 139, 0, 0, 0 } },
    { { 140, 0, 0, 0 } },
    { { 141, 0, 0, 0 } },
    { { 142, 0, 0, 0 } },
    { { 143, 0, 0, 0 } },
    { { 144, 0, 0, 0 } },
    { { 145, 0, 0, 0 } },
    { { 146, 0, 0, 0 } },
    { { 147, 0, 0, 0 } },
    { { 148, 0, 0, 0 } },
    { { 149, 0, 0, 0 } },
    { { 150, 0, 0, 0 } },
    { { 151, 0, 0, 0 } },
    { { 152, 0, 0, 0 } },
    { { 153, 0, 0, 0 } },
    { { 155, 0, 0, 0 } },
    { { 156, 0, 0, 0 } },
    { { 157, 0, 0, 0 } },
    { { 158, 0, 0, 0 } },
    { { 159, 0, 0, 0 } },
    { { 160, 0, 0, 0 } },
    { { 161, 0, 0, 0 } },
    { { 162, 0, 0, 0 } },
    { { 163, 0, 0, 0 } },
    { { 164, 0, 0, 0 } },
    { { 165, 0, 0, 0 } },
    { { 166, 0, 0, 0 } },
    { { 167, 0, 0, 0 } },
    { { 168, 0, 0, 0 } },
    { { 169, 0, 0, 0 } },
    { { 170, 0, 0, 0 } },
    { { 171, 0, 0, 0 } },
    { { 172, 0, 0, 0 } },
    { { 173, 0, 0, 0 } },
    { { 174, 0, 0, 0 } },
    { { 175, 0, 0, 0 } },
    { { 176, 0, 0, 0 } },
    { { 177, 0, 0, 0 } },
    { { 178, 0, 0, 0 } },
    { { 179, 0, 0, 0 } },
    { { 180, 0, 0, 0 } },
    { { 181, 0, 0, 0 } },
    { { 182, 0, 0, 0 } },
    { { 183, 0, 0, 0 } },
    { { 184, 0, 0, 0 } },
    { { 185, 0, 0, 0 } },
    { { 188, 0, 0, 0 } },
    { { 189, 0, 0, 0 } },
    { { 190, 0, 0, 0 } },
    { { 191, 0, 0, 0 } },
    { { 192, 0, 0, 0 } },
    { { 193, 0, 0, 0 } },
    { { 194, 0, 0, 0 } },
    { { 195, 0, 0, 0 } },
    { { 196, 0, 0, 0 } },
    { { 197, 0, 0, 0 } },
    { { 198, 0, 0, 0 } },
    { { 199, 0, 0, 0 } },
    { { 200, 0, 0, 0 } },
    { { 201, 0, 0, 0 } },
    { { 202, 0, 0, 0 } },
    { { 203, 0, 0, 0 } },
    { { 204, 0, 0, 0 } },
    { { 205, 0, 0, 0 } },
    { { 206, 0, 0, 0 } },
    { { 207, 0, 0, 0 } },
    { { 208, 0, 0, 0 } },
    { { 209, 0, 0, 0 } },
    { { 210, 0, 0, 0 } },
    { { 211, 0, 0, 0 } },
    { { 212, 0, 0, 0 } },
    { { 213, 0, 0, 0 } },
    { { 214, 0, 0, 0 } },
    { { 215, 0, 0, 0 } },
    { { 216, 0, 0, 0 } },
    { { 217, 0, 0, 0 } },
    { { 218, 0, 0, 0 } },
    { { 219, 0, 0, 0 } },
    { { 220, 0, 0, 0 } },
    { { 221, 0, 0, 0 } },
    { { 222, 0, 0, 0 } },
    { { 223, 0, 0, 0 } },
    { { 224, 0, 0, 0 } },
    { { 225, 0, 0, 0 } },
    { { 226, 0, 0, 0 } },
    { { 227, 0, 0, 0 } },
    { { 228, 0, 0, 0 } },
    { { 229, 0, 0, 0 } },
    { { 230, 0, 0, 0 } },
    { { 231, 0, 0, 0 } },
    { { 232, 0, 0, 0 } },
    { { 233, 0, 0, 0 } },
    { { 234, 0, 0, 0 } },
    { { 235, 0, 0, 0 } },
    { { 236, 0, 0, 0 } },
    { { 237, 0, 0, 0 } },
    { { 238, 0, 0, 0 } },
    { { 239, 0, 0, 0 } },
    { { 240, 0, 0, 0 } },
    { { 241, 0, 0, 0 } },
    { { 242, 0, 0, 0 } },
    { { 243, 0, 0, 0 } },
    { { 244, 0, 0, 0 } },
    { { 245, 0, 0, 0 } },
    { { 246, 0, 0, 0 } },
    { { 247, 0, 0, 0 } },
    { { 248, 0, 0, 0 } },
    { { 249, 0, 0, 0 } },
    { { 250, 0, 0, 0 } },
    { { 251, 0, 0, 0 } },
    { { 252, 0, 0, 0 } },
    { { 253, 0, 0, 0 } },
    { { 254, 0, 0, 0 } },
    { { 255, 0, 0, 0 } },
    { { 256, 0, 0, 0 } },
    { { 257, 0, 0, 0 } },
    { { 258, 0, 0, 0 } },
    { { 259, 0, 0, 0 } },
    { { 260, 0, 0, 0 } },
    { { 261, 0, 0, 0 } },
    { { 262, 0, 0, 0 } },
    { { 263, 0, 0, 0 } },
    { { 264, 0, 0, 0 } },
    { { 265, 0, 0, 0 } },
    { { 266, 0, 0, 0 } },
    { { 267, 0, 0, 0 } },
    { { 268, 0, 0, 0 } },
    { { 269, 0, 0, 0 } },
    { { 270, 0, 0, 0 } },
    { { 271, 0, 0, 0 } },
    { { 272, 0, 0, 0 } },
    { { 273, 0, 0, 0 } },
    { { 274, 0, 0, 0 } },
    { { 275, 0, 0, 0 } },
    { { 276, 0, 0, 0 } },
    { { 277, 0, 0, 0 } },
    { { 278, 0, 0, 0 } },
    { { 279, 0, 0, 0 } },
    { { 280, 0, 0, 0 } },
    { { 281, 0, 0, 0 } },
    { { 282, 0, 0, 0 } },
    { { 283, 0, 0, 0 } },
    { { 284, 0, 0, 0 } },
    { { 285, 0, 0, 0 } },
    { { 286, 0, 0, 0 } },
    { { 287, 0, 0, 0 } },
    { { 288, 0, 0, 0 } },
    { { 289, 0, 0, 0 } },
    { { 290, 0, 0, 0 } },
    { { 291, 0, 0, 0 } },
    { { 292, 0, 0, 0 } },
    { { 293, 0, 0, 0 } },
    { { 294, 0, 0, 0 } },
    { { 295, 0, 0, 0 } },
    { { 296, 0, 0, 0 } },
    { { 297, 0, 0, 0 } },
    { { 298, 0, 0, 0 } },
    { { 299, 0, 0, 0 } },
    { { 300, 0, 0, 0 } },
    { { 301, 0, 0, 0 } },
    { { 302, 0, 0, 0 } },
    { { 303, 0, 0, 0 } },
    { { 304, 0, 0, 0 } },
    { { 305, 0, 0, 0 } },
    { { 306, 0, 0, 0 } },
    { { 307, 0, 0, 0 } },
    { { 308, 0, 0, 0 } },
    { { 309, 0, 0, 0 } },
    { { 310, 0, 0, 0 } },
    { { 311, 0, 0, 0 } },
    { { 312, 0, 0, 0 } },
    { { 313, 0, 0, 0 } },
    { { 314, 0, 0, 0 } },
    { { 315, 0, 0, 0 } },
    { { 316, 0, 0, 0 } },
    { { 317, 0, 0, 0 } },
    { { 318, 0, 0, 0 } },
    { { 319, 0, 0, 0 } },
    { { 320, 0, 0, 0 } },
    { { 321, 0, 0, 0 } },
    { { 322, 0, 0, 0 } },
    { { 323, 0, 0, 0 } },
    { { 324, 0, 0, 0 } },
    { { 325, 0, 0, 0 } },
    { { 326, 0, 0, 0 } },
    { { 327, 0, 0, 0 } },
    { { 328, 0, 0, 0 } },
    { { 329, 0, 0, 0 } },
    { { 330, 0, 0, 0 } },
    { { 331, 0, 0, 0 } },
    { { 332, 0, 0, 0 } },
    { { 333, 0, 0, 0 } },
    { { 334, 0, 0, 0 } },
    { { 335, 0, 0, 0 } },
    { { 336, 0, 0, 0 } },
    { { 337, 0, 0, 0 } },
    { { 338, 0, 0, 0 } },
    { { 339, 0, 0, 0 } },
    { { 340, 0, 0, 0 } },
    { { 341, 0, 0, 0 } },
    { { 342, 0, 0, 0 } },
    { { 343, 0, 0, 0 } },
    { { 344, 0, 0, 0 } },
    { { 345, 0, 0, 0 } },
    { { 346, 0, 0, 0 } },
    { { 347, 0, 0, 0 } },
    { { 348, 0, 0, 0 } },
    { { 349, 0, 0, 0 } },
    { { 350, 0, 0, 0 } },
    { { 351, 0, 0, 0 } },
    { { 352, 0, 0, 0 } },
    { { 353, 0, 0, 0 } },
    { { 354, 0, 0, 0 } },
    { { 355, 0, 0, 0 } },
    { { 356, 0, 0, 0 } },
    { { 357, 0, 0, 0 } },
    { { 359, 0, 0, 0 } },
    { { 360, 0, 0, 0 } },
    { { 361, 0, 0, 0 } },
    { { 362, 0, 0, 0 } },
    { { 363, 0, 0, 0 } },
    { { 364, 0, 0, 0 } },
    { { 365, 0, 0, 0 } },
    { { 366, 0, 0, 0 } },
    { { 367, 0, 0, 0 } },
    { { 368, 0, 0, 0 } },
    { { 369, 0, 0, 0 } },
    { { 370, 0, 0, 0 } },
    { { 371, 0, 0, 0 } },
    { { 372, 0, 0, 0 } },
    { { 373, 0, 0, 0 } },
    { { 23, 374, 0, 0 } },
    { { 24, 375, 0, 0 } },
    { { 25, 376, 0, 0 } },
    { { 26, 380, 0, 0 } },
    { { 27, 383, 0, 0 } },
    { { 384, 0, 0, 0 } },
    { { 385, 0, 0, 0 } },
    { { 386, 0, 0, 0 } },
    { { 387, 0, 0, 0 } },
    { { 388, 0, 0, 0 } },
    { { 389, 0, 0, 0 } },
    { { 390, 0, 0, 0 } },
    { { 391, 0, 0, 0 } },
    { { 392, 0, 0, 0 } },
    { { 393, 0, 0, 0 } },
    { { 397, 0, 0, 0 } },
    { { 398, 0, 0, 0 } },
    { { 399, 0, 0, 0 } },
    { { 400, 0, 0, 0 } },
    { { 401, 0, 0, 0 } },
    { { 402, 0, 0, 0 } },
    { { 403, 0, 0, 0 } },
    { { 404, 0, 0, 0 } },
    { { 405, 0, 0, 0 } },
    { { 406, 0, 0, 0 } },
    { { 407, 0, 0, 0 } },
    { { 408, 0, 0, 0 } },
    { { 409, 0, 0, 0 } },
    { { 410, 0, 0, 0 } },
    { { 412, 0, 0, 0 } },
    { { 413, 0, 0, 0 } },
    { { 414, 0, 0, 0 } },
    { { 415, 0, 0, 0 } },
    { { 416, 0, 0, 0 } },
    { { 417, 0, 0, 0 } },
    { { 418, 0, 0, 0 } },
    { { 419, 0, 0, 0 } },
    { { 420, 0, 0, 0 } },
    { { 421, 0, 0, 0 } },
    { { 422, 0, 0, 0 } },
    { { 424, 0, 0, 0 } },
    { { 425, 0, 0, 0 } },
    { { 426, 0, 0, 0 } },
    { { 427, 0, 0, 0 } },
    { { 428, 0, 0, 0 } },
    { { 429, 0, 0, 0 } },
    { { 430, 0, 0, 0 } },
    { { 431, 0, 0, 0 } },
    { { 432, 0, 0, 0 } },
    { { 433, 0, 0, 0 } },
    { { 434, 0, 0, 0 } },
    { { 435, 0, 0, 0 } },
    { { 436, 0, 0, 0 } },
    { { 437, 0, 0, 0 } },
    { { 438, 0, 0, 0 } },
    { { 440, 0, 0, 0 } },
    { { 442, 0, 0, 0 } },
    { { 443, 0, 0, 0 } },
    { { 444, 0, 0, 0 } },
    { { 445, 0, 0, 0 } },
    { { 446, 0, 0, 0 } },
    { { 447, 0, 0, 0 } },
    { { 448, 0, 0, 0 } },
    { { 449, 0, 0, 0 } },
    { { 450, 0, 0, 0 } },
    { { 451, 0, 0, 0 } },
    { { 452, 0, 0, 0 } },
    { { 453, 0, 0, 0 } },
    { { 454, 0, 0, 0 } },
    { { 456, 0, 0, 0 } },
    { { 458, 0, 0, 0 } },
    { { 459, 0, 0, 0 } },
    { { 460, 0, 0, 0 } },
    { { 461, 0, 0, 0 } },
    { { 462, 0, 0, 0 } },
    { { 463, 0, 0, 0 } },
    { { 464, 0, 0, 0 } },
    { { 465, 0, 0, 0 } },
    { { 466, 0, 0, 0 } },
    { { 467, 0, 0, 0 } },
    { { 468, 0, 0, 0 } },
    { { 469, 0, 0, 0 } },
    { { 470, 0, 0, 0 } },
    { { 471, 0, 0, 0 } },
    { { 472, 0, 0, 0 } },
    { { 473, 0, 0, 0 } },
    { { 474, 0, 0, 0 } },
    { { 475, 0, 0, 0 } },
    { { 476, 0, 0, 0 } },
    { { 477, 0, 0, 0 } },
    { { 478, 0, 0, 0 } },
    { { 480, 0, 0, 0 } },
    { { 482, 0, 0, 0 } },
    { { 483, 0, 0, 0 } },
    { { 484, 0, 0, 0 } },
    { { 485, 0, 0, 0 } },
    { { 486, 0, 0, 0 } },
    { { 487, 0, 0, 0 } },
    { { 488, 0, 0, 0 } },
    { { 489, 0, 0, 0 } },
    { { 490, 0, 0, 0 } },
    { { 491, 0, 0, 0 } },
    { { 492, 0, 0, 0 } },
    { { 493, 0, 0, 0 } },
    { { 494, 0, 0, 0 } },
    { { 495, 0, 0, 0 } },
    { { 496, 0, 0, 0 } },
    { { 497, 0, 0, 0 } },
    { { 498, 0, 0, 0 } },
    { { 499, 0, 0, 0 } },
    { { 500, 0, 0, 0 } },
    { { 502, 0, 0, 0 } },
    { { 504, 0, 0, 0 } },
    { { 505, 0, 0, 0 } },
    { { 506, 0, 0, 0 } },
    { { 507, 0, 0, 0 } },
    { { 508, 0, 0, 0 } },
    { { 509, 0, 0, 0 } },
    { { 510, 0, 0, 0 } },
    { { 511, 0, 0, 0 } },
    { { 512, 0, 0, 0 } },
    { { 513, 0, 0, 0 } },
    { { 514, 0, 0, 0 } },
    { { 515, 0, 0, 0 } },
    { { 516, 0, 0, 0 } },
    { { 518, 0, 0, 0 } },
    { { 520, 0, 0, 0 } },
    { { 522, 0, 0, 0 } },
    { { 524, 0, 0, 0 } },
    { { 526, 0, 0, 0 } },
    { { 528, 0, 0, 0 } },
    { { 530, 0, 0, 0 } },
    { { 531, 0, 0, 0 } },
    { { 532, 0, 0, 0 } },
    { { 533, 0, 0, 0 } },
    { { 534, 0, 0, 0 } },
    { { 535, 0, 0, 0 } },
    { { 536, 0, 0, 0 } },
    { { 537, 0, 0, 0 } },
    { { 539, 0, 0, 0 } },
    { { 540, 0, 0, 0 } },
    { { 541, 0, 0, 0 } },
    { { 542, 0, 0, 0 } },
    { { 543, 0, 0, 0 } },
    { { 544, 0, 0, 0 } },
    { { 545, 0, 0, 0 } },
    { { 546, 0, 0, 0 } },
    { { 547, 0, 0, 0 } },
    { { 548, 0, 0, 0 } },
    { { 549, 0, 0, 0 } },
    { { 550, 0, 0, 0 } },
    { { 551, 0, 0, 0 } },
    { { 552, 0, 0, 0 } },
    { { 553, 0, 0, 0 } },
    { { 554, 0, 0, 0 } },
    { { 555, 0, 0, 0 } },
    { { 556, 0, 0, 0 } },
    { { 557, 0, 0, 0 } },
    { { 558, 0, 0, 0 } },
    { { 559, 0, 0, 0 } },
    { { 560, 0, 0, 0 } },
    { { 561, 0, 0, 0 } },
    { { 562, 0, 0, 0 } },
    { { 563, 0, 0, 0 } },
    { { 564, 0, 0, 0 } },
    { { 565, 0, 0, 0 } },
    { { 566, 0, 0, 0 } },
    { { 567, 0, 0, 0 } },
    { { 568, 0, 0, 0 } },
    { { 569, 0, 0, 0 } },
    { { 570, 0, 0, 0 } },
    { { 571, 0, 0, 0 } },
    { { 572, 0, 0, 0 } },
    { { 573, 0, 0, 0 } },
    { { 574, 0, 0, 0 } },
    { { 575, 0, 0, 0 } },
    { { 576, 0, 0, 0 } },
    { { 577, 0, 0, 0 } },
    { { 578, 0, 0, 0 } },
    { { 579, 0, 0, 0 } },
    { { 580, 0, 0, 0 } },
    { { 581, 0, 0, 0 } },
    { { 582, 0, 0, 0 } },
    { { 583, 0, 0, 0 } },
    { { 584, 0, 0, 0 } },
    { { 585, 0, 0, 0 } },
    { { 586, 0, 0, 0 } },
    { { 587, 0, 0, 0 } },
    { { 588, 0, 0, 0 } },
    { { 589, 0, 0, 0 } },
    { { 590, 0, 0, 0 } },
    { { 591, 0, 0, 0 } },
    { { 592, 0, 0, 0 } },
    { { 593, 0, 0, 0 } },
    { { 594, 0, 0, 0 } },
    { { 595, 0, 0, 0 } },
    { { 596, 0, 0, 0 } },
    { { 597, 0, 0, 0 } },
    { { 598, 0, 0, 0 } },
    { { 599, 0, 0, 0 } },
    { { 600, 0, 0, 0 } },
    { { 601, 0, 0, 0 } },
    { { 602, 0, 0, 0 } },
    { { 603, 0, 0, 0 } },
    { { 604, 0, 0, 0 } },
    { { 605, 0, 0, 0 } },
    { { 606, 0, 0, 0 } },
    { { 607, 0, 0, 0 } },
    { { 608, 0, 0, 0 } },
    { { 609, 0, 0, 0 } },
    { { 610, 0, 0, 0 } },
    { { 611, 0, 0, 0 } },
    { { 612, 0, 0, 0 } },
    { { 613, 0, 0, 0 } },
    { { 614, 0, 0, 0 } },
    { { 615, 0, 0, 0 } },
    { { 616, 0, 0, 0 } },
    { { 617, 0, 0, 0 } },
    { { 618, 0, 0, 0 } },
    { { 619, 0, 0, 0 } },
    { { 620, 0, 0, 0 } },
    { { 621, 0, 0, 0 } },
    { { 622, 0, 0, 0 } },
    { { 623, 0, 0, 0 } },
    { { 624, 0, 0, 0 } },
    { { 625, 0, 0, 0 } },
    { { 626, 0, 0, 0 } },
    { { 627, 0, 0, 0 } },
    { { 628, 0, 0, 0 } },
    { { 629, 0, 0, 0 } },
    { { 630, 0, 0, 0 } },
    { { 631, 0, 0, 0 } },
    { { 632, 0, 0, 0 } },
    { { 633, 0, 0, 0 } },
    { { 634, 0, 0, 0 } },
    { { 635, 0, 0, 0 } },
    { { 636, 0, 0, 0 } },
    { { 637, 0, 0, 0 } },
    { { 638, 0, 0, 0 } },
    { { 639, 0, 0, 0 } },
    { { 640, 0, 0, 0 } },
    { { 641, 0, 0, 0 } },
    { { 642, 0, 0, 0 } },
    { { 643, 0, 0, 0 } },
    { { 644, 0, 0, 0 } },
    { { 645, 0, 0, 0 } },
    { { 646, 0, 0, 0 } },
    { { 647, 0, 0, 0 } },
    { { 648, 0, 0, 0 } },
    { { 649, 0, 0, 0 } },
    { { 650, 0, 0, 0 } },
    { { 651, 0, 0, 0 } },
    { { 652, 0, 0, 0 } },
    { { 653, 0, 0, 0 } },
    { { 654, 0, 0, 0 } },
    { { 655, 0, 0, 0 } },
    { { 656, 0, 0, 0 } },
    { { 657, 0, 0, 0 } },
    { { 658, 0, 0, 0 } },
    { { 659, 0, 0, 0 } },
    { { 660, 0, 0, 0 } },
    { { 661, 0, 0, 0 } },
    { { 662, 0, 0, 0 } },
    { { 663, 0, 0, 0 } },
    { { 664, 0, 0, 0 } },
    { { 665, 0, 0, 0 } },
    { { 666, 0, 0, 0 } },
    { { 667, 0, 0, 0 } },
    { { 668, 0, 0, 0 } },
    { { 669, 0, 0, 0 } },
    { { 670, 0, 0, 0 } },
    { { 671, 0, 0, 0 } },
    { { 672, 0, 0, 0 } },
    { { 673, 0, 0, 0 } },
    { { 674, 0, 0, 0 } },
    { { 675, 0, 0, 0 } },
    { { 676, 0, 0, 0 } },
    { { 677, 0, 0, 0 } },
    { { 678, 0, 0, 0 } },
    { { 679, 0, 0, 0 } },
    { { 680, 0, 0, 0 } },
    { { 681, 0, 0, 0 } },
    { { 682, 0, 0, 0 } },
    { { 683, 0, 0, 0 } },
    { { 684, 0, 0, 0 } },
    { { 685, 0, 0, 0 } },
    { { 686, 0, 0, 0 } },
    { { 687, 0, 0, 0 } },
    { { 688, 0, 0, 0 } },
    { { 689, 0, 0, 0 } },
    { { 690, 0, 0, 0 } },
    { { 691, 0, 0, 0 } },
    { { 692, 0, 0, 0 } },
    { { 693, 0, 0, 0 } },
    { { 694, 0, 0, 0 } },
    { { 695, 0, 0, 0 } },
    { { 696, 0, 0, 0 } },
    { { 697, 0, 0, 0 } },
    { { 698, 0, 0, 0 } },
    { { 699, 0, 0, 0 } },
    { { 700, 0, 0, 0 } },
    { { 701, 0, 0, 0 } },
    { { 702, 0, 0, 0 } },
    { { 703, 0, 0, 0 } },
    { { 704, 0, 0, 0 } },
    { { 705, 0, 0, 0 } },
    { { 706, 0, 0, 0 } },
    { { 707, 0, 0, 0 } },
    { { 708, 0, 0, 0 } },
    { { 709, 0, 0, 0 } },
    { { 710, 0, 0, 0 } },
    { { 711, 0, 0, 0 } },
    { { 712, 0, 0, 0 } },
    { { 713, 0, 0, 0 } },
    { { 714, 0, 0, 0 } },
    { { 715, 0, 0, 0 } },
    { { 716, 0, 0, 0 } },
    { { 717, 0, 0, 0 } },
    { { 718, 0, 0, 0 } },
    { { 719, 0, 0, 0 } },
    { { 720, 0, 0, 0 } },
    { { 721, 0, 0, 0 } },
    { { 722, 0, 0, 0 } },
    { { 723, 0, 0, 0 } },
    { { 724, 0, 0, 0 } },
    { { 725, 0, 0, 0 } },
    { { 726, 0, 0, 0 } },
    { { 727, 0, 0, 0 } },
    { { 728, 0, 0, 0 } },
    { { 729, 0, 0, 0 } },
    { { 730, 0, 0, 0 } },
    { { 731, 0, 0, 0 } },
    { { 732, 0, 0, 0 } },
    { { 733, 0, 0, 0 } },
    { { 734, 0, 0, 0 } },
    { { 735, 0, 0, 0 } },
    { { 736, 0, 0, 0 } },
    { { 737, 0, 0, 0 } },
    { { 738, 0, 0, 0 } },
    { { 739, 0, 0, 0 } },
    { { 740, 0, 0, 0 } },
    { { 741, 0, 0, 0 } },
    { { 742, 0, 0, 0 } },
    { { 743, 0, 0, 0 } },
    { { 744, 0, 0, 0 } },
    { { 745, 0, 0, 0 } },
    { { 746, 0, 0, 0 } },
    { { 747, 0, 0, 0 } },
    { { 748, 0, 0, 0 } },
    { { 749, 0, 0, 0 } },
    { { 750, 0, 0, 0 } },
    { { 751, 0, 0, 0 } },
    { { 752, 0, 0, 0 } },
    { { 753, 0, 0, 0 } },
    { { 754, 0, 0, 0 } },
    { { 755, 0, 0, 0 } },
    { { 756, 0, 0, 0 } },
    { { 757, 0, 0, 0 } },
    { { 758, 0, 0, 0 } },
    { { 759, 0, 0, 0 } },
    { { 760, 0, 0, 0 } },
    { { 761, 0, 0, 0 } },
    { { 762, 0, 0, 0 } },
    { { 763, 0, 0, 0 } },
    { { 764, 0, 0, 0 } },
    { { 765, 0, 0, 0 } },
    { { 766, 0, 0, 0 } },
    { { 767, 0, 0, 0 } },
    { { 768, 0, 0, 0 } },
    { { 769, 0, 0, 0 } },
    { { 770, 0, 0, 0 } },
    { { 771, 0, 0, 0 } },
    { { 772, 0, 0, 0 } },
    { { 773, 0, 0, 0 } },
    { { 774, 0, 0, 0 } },
    { { 775, 0, 0, 0 } },
    { { 776, 0, 0, 0 } },
    { { 777, 0, 0, 0 } },
    { { 778, 0, 0, 0 } },
    { { 779, 0, 0, 0 } },
    { { 780, 0, 0, 0 } },
    { { 781, 0, 0, 0 } },
    { { 782, 0, 0, 0 } },
    { { 783, 0, 0, 0 } },
    { { 784, 0, 0, 0 } },
    { { 785, 0, 0, 0 } },
    { { 786, 0, 0, 0 } },
    { { 787, 0, 0, 0 } },
    { { 788, 0, 0, 0 } },
    { { 789, 0, 0, 0 } },
    { { 790, 0, 0, 0 } },
    { { 791, 0, 0, 0 } },
    { { 792, 0, 0, 0 } },
    { { 793, 0, 0, 0 } },
    { { 794, 0, 0, 0 } },
    { { 795, 0, 0, 0 } },
    { { 796, 0, 0, 0 } },
    { { 797, 0, 0, 0 } },
    { { 798, 0, 0, 0 } },
    { { 799, 0, 0, 0 } },
    { { 800, 0, 0, 0 } },
    { { 801, 0, 0, 0 } },
    { { 802, 0, 0, 0 } },
    { { 803, 0, 0, 0 } },
    { { 804, 0, 0, 0 } },
    { { 805, 0, 0, 0 } },
    { { 806, 0, 0, 0 } },
    { { 807, 0, 0, 0 } },
    { { 808, 0, 0, 0 } },
    { { 809, 0, 0, 0 } },
    { { 810, 0, 0, 0 } },
    { { 811, 0, 0, 0 } },
    { { 812, 0, 0, 0 } },
    { { 813, 0, 0, 0 } },
    { { 814, 0, 0, 0 } },
    { { 815, 0, 0, 0 } },
    { { 816, 0, 0, 0 } },
    { { 817, 0, 0, 0 } },
    { { 818, 0, 0, 0 } },
    { { 819, 0, 0, 0 } },
    { { 820, 0, 0, 0 } },
    { { 821, 0, 0, 0 } },
    { { 822, 0, 0, 0 } },
    { { 823, 0, 0, 0 } },
    { { 824, 0, 0, 0 } },
    { { 825, 0, 0, 0 } },
    { { 826, 0, 0, 0 } },
    { { 827, 0, 0, 0 } },
    { { 828, 0, 0, 0 } },
    { { 829, 0, 0, 0 } },
    { { 830, 0, 0, 0 } },
    { { 831, 0, 0, 0 } },
    { { 832, 0, 0, 0 } },
    { { 833, 0, 0, 0 } },
    { { 834, 0, 0, 0 } },
    { { 835, 0, 0, 0 } },
    { { 836, 0, 0, 0 } },
    { { 837, 0, 0, 0 } },
    { { 838, 0, 0, 0 } },
    { { 839, 0, 0, 0 } },
    { { 840, 0, 0, 0 } },
    { { 841, 0, 0, 0 } },
    { { 842, 0, 0, 0 } },
    { { 843, 0, 0, 0 } },
    { { 844, 0, 0, 0 } },
    { { 845, 0, 0, 0 } },
    { { 846, 0, 0, 0 } },
    { { 847, 0, 0, 0 } },
    { { 848, 0, 0, 0 } },
    { { 849, 0, 0, 0 } },
    { { 850, 0, 0, 0 } },
    { { 851, 0, 0, 0 } },
    { { 852, 0, 0, 0 } },
    { { 853, 0, 0, 0 } },
    { { 854, 0, 0, 0 } },
    { { 855, 0, 0, 0 } },
    { { 856, 0, 0, 0 } },
    { { 857, 0, 0, 0 } },
    { { 858, 0, 0, 0 } },
    { { 859, 0, 0, 0 } },
    { { 860, 0, 0, 0 } },
    { { 861, 0, 0, 0 } },
    { { 862, 0, 0, 0 } },
    { { 863, 0, 0, 0 } },
    { { 864, 0, 0, 0 } },
    { { 865, 0, 0, 0 } },
    { { 866, 0, 0, 0 } },
    { { 867, 0, 0, 0 } },
    { { 868, 0, 0, 0 } },
    { { 869, 0, 0, 0 } },
    { { 870, 0, 0, 0 } },
    { { 871, 0, 0, 0 } },
    { { 872, 0, 0, 0 } },
    { { 873, 0, 0, 0 } },
    { { 874, 0, 0, 0 } },
    { { 875, 0, 0, 0 } },
    { { 876, 0, 0, 0 } },
    { { 877, 0, 0, 0 } },
    { { 878, 0, 0, 0 } },
    { { 879, 0, 0, 0 } },
    { { 880, 0, 0, 0 } },
    { { 881, 0, 0, 0 } },
    { { 882, 0, 0, 0 } },
    { { 883, 0, 0, 0 } },
    { { 884, 0, 0, 0 } },
    { { 885, 0, 0, 0 } },
    { { 886, 0, 0, 0 } },
    { { 887, 0, 0, 0 } },
    { { 888, 0, 0, 0 } },
    { { 889, 0, 0, 0 } },
    { { 890, 0, 0, 0 } },
    { { 891, 0, 0, 0 } },
    { { 892, 0, 0, 0 } },
    { { 893, 0, 0, 0 } },
    { { 894, 0, 0, 0 } },
    { { 895, 0, 0, 0 } },
    { { 896, 0, 0, 0 } },
    { { 897, 0, 0, 0 } },
    { { 898, 0, 0, 0 } },
    { { 899, 0, 0, 0 } },
    { { 900, 0, 0, 0 } },
    { { 901, 0, 0, 0 } },
    { { 902, 0, 0, 0 } },
    { { 903, 0, 0, 0 } },
    { { 904, 0, 0, 0 } },
    { { 905, 0, 0, 0 } },
    { { 906, 0, 0, 0 } },
    { { 907, 0, 0, 0 } },
    { { 908, 0, 0, 0 } },
    { { 909, 0, 0, 0 } },
    { { 910, 0, 0, 0 } },
    { { 911, 0, 0, 0 } },
    { { 912, 0, 0, 0 } },
    { { 913, 0, 0, 0 } },
    { { 914, 0, 0, 0 } },
    { { 915, 0, 0, 0 } },
    { { 916, 0, 0, 0 } },
    { { 917, 0, 0, 0 } },
    { { 918, 0, 0, 0 } },
    { { 919, 0, 0, 0 } },
    { { 920, 0, 0, 0 } },
    { { 921, 0, 0, 0 } },
    { { 922, 0, 0, 0 } },
    { { 923, 0, 0, 0 } },
    { { 924, 0, 0, 0 } },
    { { 925, 0, 0, 0 } },
    { { 926, 0, 0, 0 } },
    { { 927, 0, 0, 0 } },
    { { 928, 0, 0, 0 } },
    { { 929, 0, 0, 0 } },
    { { 930, 0, 0, 0 } },
    { { 931, 0, 0, 0 } },
    { { 932, 0, 0, 0 } },
    { { 933, 0, 0, 0 } },
    { { 934, 0, 0, 0 } },
    { { 935, 0, 0, 0 } },
    { { 936, 0, 0, 0 } },
    { { 937, 0, 0, 0 } },
    { { 938, 0, 0, 0 } },
    { { 939, 0, 0, 0 } },
    { { 940, 0, 0, 0 } },
    { { 941, 0, 0, 0 } },
    { { 942, 0, 0, 0 } },
    { { 943, 0, 0, 0 } },
    { { 944, 0, 0, 0 } },
    { { 945, 0, 0, 0 } },
    { { 946, 0, 0, 0 } },
    { { 947, 0, 0, 0 } },
    { { 948, 0, 0, 0 } },
    { { 949, 0, 0, 0 } },
    { { 950, 0, 0, 0 } },
    { { 951, 0, 0, 0 } },
    { { 952, 0, 0, 0 } },
    { { 953, 0, 0, 0 } },
    { { 954, 0, 0, 0 } },
    { { 955, 0, 0, 0 } },
    { { 956, 0, 0, 0 } },
    { { 957, 0, 0, 0 } },
    { { 958, 0, 0, 0 } },
    { { 959, 0, 0, 0 } },
    { { 960, 0, 0, 0 } },
    { { 961, 0, 0, 0 } },
    { { 962, 0, 0, 0 } },
    { { 963, 0, 0, 0 } },
    { { 964, 0, 0, 0 } },
    { { 965, 0, 0, 0 } },
    { { 966, 0, 0, 0 } },
    { { 967, 0, 0, 0 } },
    { { 968, 0, 0, 0 } },
    { { 969, 0, 0, 0 } },
    { { 970, 0, 0, 0 } },
    { { 971, 0, 0, 0 } },
    { { 972, 0, 0, 0 } },
    { { 973, 0, 0, 0 } },
    { { 974, 0, 0, 0 } },
    { { 975, 0, 0, 0 } },
    { { 976, 0, 0, 0 } },
    { { 977, 0, 0, 0 } },
    { { 978, 0, 0, 0 } },
    { { 979, 0, 0, 0 } },
    { { 980, 0, 0, 0 } },
    { { 981, 0, 0, 0 } },
    { { 982, 0, 0, 0 } },
    { { 983, 0, 0, 0 } },
    { { 984, 0, 0, 0 } },
    { { 985, 0, 0, 0 } },
    { { 986, 0, 0, 0 } },
    { { 987, 0, 0, 0 } },
    { { 988, 0, 0, 0 } },
    { { 989, 0, 0, 0 } },
    { { 990, 0, 0, 0 } },
    { { 991, 0, 0, 0 } },
    { { 992, 0, 0, 0 } },
    { { 993, 0, 0, 0 } },
    { { 994, 0, 0, 0 } },
    { { 995, 0, 0, 0 } },
    { { 996, 0, 0, 0 } },
    { { 997, 0, 0, 0 } },
    { { 998, 0, 0, 0 } },
    { { 999, 0, 0, 0 } },
    { { 1000, 0, 0, 0 } },
    { { 1001, 0, 0, 0 } },
    { { 1002, 0, 0, 0 } },
    { { 1003, 0, 0, 0 } },
    { { 1004, 0, 0, 0 } },
    { { 1005, 0, 0, 0 } },
    { { 1006, 0, 0, 0 } },
    { { 1007, 0, 0, 0 } },
    { { 1008, 0, 0, 0 } },
    { { 1009, 0, 0, 0 } },
    { { 1010, 0, 0, 0 } },
    { { 1011, 0, 0, 0 } },
    { { 1012, 0, 0, 0 } },
    { { 1013, 0, 0, 0 } },
    { { 1014, 0, 0, 0 } },
    { { 1015, 0, 0, 0 } },
    { { 1016, 0, 0, 0 } },
    { { 1017, 0, 0, 0 } },
    { { 1018, 0, 0, 0 } },
    { { 1019, 0, 0, 0 } },
    { { 1020, 0, 0, 0 } },
    { { 1021, 0, 0, 0 } },
    { { 1022, 0, 0, 0 } },
    { { 1023, 0, 0, 0 } },
    { { 1024, 0, 0, 0 } },
    { { 1025, 0, 0, 0 } },
    { { 1026, 0, 0, 0 } },
    { { 1027, 0, 0, 0 } },
    { { 1028, 0, 0, 0 } },
    { { 1029, 0, 0, 0 } },
    { { 1030, 0, 0, 0 } },
    { { 1031, 0, 0, 0 } },
    { { 1032, 0, 0, 0 } },
    { { 1033, 0, 0, 0 } },
    { { 1034, 0, 0, 0 } },
    { { 1035, 0, 0, 0 } },
    { { 1036, 0, 0, 0 } },
    { { 1037, 0, 0, 0 } },
    { { 1038, 0, 0, 0 } },
    { { 1039, 0, 0, 0 } },
    { { 1040, 0, 0, 0 } },
    { { 1041, 0, 0, 0 } },
    { { 1042, 0, 0, 0 } },
    { { 1043, 0, 0, 0 } },
    { { 1044, 0, 0, 0 } },
    { { 1045, 0, 0, 0 } },
    { { 1046, 0, 0, 0 } },
    { { 1047, 0, 0, 0 } },
    { { 1048, 0, 0, 0 } },
    { { 1049, 0, 0, 0 } },
    { { 1050, 0, 0, 0 } },
    { { 1051, 0, 0, 0 } },
    { { 1052, 0, 0, 0 } },
    { { 1053, 0, 0, 0 } },
    { { 1054, 0, 0, 0 } },
    { { 1055, 0, 0, 0 } },
    { { 1056, 0, 0, 0 } },
    { { 1057, 0, 0, 0 } },
    { { 1058, 0, 0, 0 } },
    { { 1059, 0, 0, 0 } },
    { { 1060, 0, 0, 0 } },
    { { 1061, 0, 0, 0 } },
    { { 1062, 0, 0, 0 } },
    { { 1063, 0, 0, 0 } },
    { { 1064, 0, 0, 0 } },
    { { 1065, 0, 0, 0 } },
    { { 1066, 0, 0, 0 } },
    { { 1067, 0, 0, 0 } },
    { { 1068, 0, 0, 0 } },
    { { 1069, 0, 0, 0 } },
    { { 1070, 0, 0, 0 } },
    { { 1071, 0, 0, 0 } },
    { { 1072, 0, 0, 0 } },
    { { 1073, 0, 0, 0 } },
    { { 1074, 0, 0, 0 } },
    { { 1075, 0, 0, 0 } },
    { { 1076, 0, 0, 0 } },
    { { 1077, 0, 0, 0 } },
    { { 1078, 0, 0, 0 } },
    { { 1079, 0, 0, 0 } },
    { { 1080, 0, 0, 0 } },
    { { 1081, 0, 0, 0 } },
    { { 1082, 0, 0, 0 } },
    { { 1083, 0, 0, 0 } },
    { { 1084, 0, 0, 0 } },
    { { 1085, 0, 0, 0 } },
    { { 1086, 0, 0, 0 } },
    { { 1087, 0, 0, 0 } },
    { { 1088, 0, 0, 0 } },
    { { 1089, 0, 0, 0 } },
    { { 1090, 0, 0, 0 } },
    { { 1091, 0, 0, 0 } },
    { { 1092, 0, 0, 0 } },
    { { 1093, 0, 0, 0 } },
    { { 1094, 0, 0, 0 } },
    { { 1095, 0, 0, 0 } },
    { { 1096, 0, 0, 0 } },
    { { 1097, 0, 0, 0 } },
    { { 1098, 0, 0, 0 } },
    { { 1099, 0, 0, 0 } },
    { { 1100, 0, 0, 0 } },
    { { 1101, 0, 0, 0 } },
    { { 1102, 0, 0, 0 } },
    { { 1103, 0, 0, 0 } },
    { { 1104, 0, 0, 0 } },
    { { 1105, 0, 0, 0 } },
    { { 1106, 0, 0, 0 } },
    { { 1107, 0, 0, 0 } },
    { { 1108, 0, 0, 0 } },
    { { 1109, 0, 0, 0 } },
    { { 1110, 0, 0, 0 } },
    { { 1111, 0, 0, 0 } },
    { { 1112, 0, 0, 0 } },
    { { 1113, 0, 0, 0 } },
    { { 1114, 0, 0, 0 } },
    { { 1115, 0, 0, 0 } },
    { { 1116, 0, 0, 0 } },
    { { 1117, 0, 0, 0 } },
    { { 1118, 0, 0, 0 } },
    { { 1119, 0, 0, 0 } },
    { { 1120, 0, 0, 0 } },
    { { 1121, 0, 0, 0 } },
    { { 1122, 0, 0, 0 } },
    { { 1123, 0, 0, 0 } },
    { { 1124, 0, 0, 0 } },
    { { 1125, 0, 0, 0 } },
    { { 1126, 0, 0, 0 } },
    { { 1127, 0, 0, 0 } },
    { { 1128, 0, 0, 0 } },
    { { 1129, 0, 0, 0 } },
    { { 1130, 0, 0, 0 } },
    { { 1131, 0, 0, 0 } },
    { { 1132, 0, 0, 0 } },
    { { 1133, 0, 0, 0 } },
    { { 1134, 0, 0, 0 } },
    { { 1135, 0, 0, 0 } },
    { { 1136, 0, 0, 0 } },
    { { 1137, 0, 0, 0 } },
    { { 1138, 0, 0, 0 } },
    { { 1139, 0, 0, 0 } },
    { { 1140, 0, 0, 0 } },
    { { 1141, 0, 0, 0 } },
    { { 1142, 0, 0, 0 } },
    { { 1143, 0, 0, 0 } },
    { { 1144, 0, 0, 0 } },
    { { 1145, 0, 0, 0 } },
    { { 1146, 0, 0, 0 } },
    { { 1147, 0, 0, 0 } },
    { { 1148, 0, 0, 0 } },
    { { 1149, 0, 0, 0 } },
    { { 1150, 0, 0, 0 } },
    { { 1151, 0, 0, 0 } },
    { { 1152, 0, 0, 0 } },
    { { 1153, 0, 0, 0 } },
    { { 1154, 0, 0, 0 } },
    { { 1155, 0, 0, 0 } },
    { { 1156, 0, 0, 0 } },
    { { 1157, 0, 0, 0 } },
    { { 1158, 0, 0, 0 } },
    { { 1159, 0, 0, 0 } },
    { { 1160, 0, 0, 0 } },
    { { 1161, 0, 0, 0 } },
    { { 1162, 0, 0, 0 } },
    { { 1163, 0, 0, 0 } },
    { { 1164, 0, 0, 0 } },
    { { 1165, 0, 0, 0 } },
    { { 1166, 0, 0, 0 } },
    { { 1167, 0, 0, 0 } },
    { { 1168, 0, 0, 0 } },
    { { 1169, 0, 0, 0 } },
    { { 1170, 0, 0, 0 } },
    { { 1171, 0, 0, 0 } },
    { { 1172, 0, 0, 0 } },
    { { 1173, 0, 0, 0 } },
    { { 1174, 0, 0, 0 } },
    { { 1175, 0, 0, 0 } },
    { { 1176, 0, 0, 0 } },
    { { 1177, 0, 0, 0 } },
    { { 1178, 0, 0, 0 } },
    { { 1179, 0, 0, 0 } },
    { { 1180, 0, 0, 0 } },
    { { 1181, 0, 0, 0 } },
    { { 1182, 0, 0, 0 } },
    { { 1183, 0, 0, 0 } },
    { { 1184, 0, 0, 0 } },
    { { 1185, 0, 0, 0 } },
    { { 1186, 0, 0, 0 } },
    { { 1187, 0, 0, 0 } },
    { { 1188, 0, 0, 0 } },
    { { 1189, 0, 0, 0 } },
    { { 1190, 0, 0, 0 } },
    { { 1191, 0, 0, 0 } },
    { { 1192, 0, 0, 0 } },
    { { 1193, 0, 0, 0 } },
    { { 1194, 0, 0, 0 } },
    { { 1195, 0, 0, 0 } },
    { { 1196, 0, 0, 0 } },
    { { 1197, 0, 0, 0 } },
    { { 1198, 0, 0, 0 } },
    { { 1199, 0, 0, 0 } },
    { { 1200, 0, 0, 0 } },
    { { 1201, 0, 0, 0 } },
    { { 1202, 0, 0, 0 } },
    { { 1203, 0, 0, 0 } },
    { { 1204, 0, 0, 0 } },
    { { 1205, 0, 0, 0 } },
    { { 1206, 0, 0, 0 } },
    { { 1207, 0, 0, 0 } },
    { { 1208, 0, 0, 0 } },
    { { 1209, 0, 0, 0 } },
    { { 1210, 0, 0, 0 } },
    { { 1211, 0, 0, 0 } },
    { { 1212, 0, 0, 0 } },
    { { 1213, 0, 0, 0 } },
    { { 1214, 0, 0, 0 } },
    { { 1215, 0, 0, 0 } },
    { { 1216, 0, 0, 0 } },
    { { 1217, 0, 0, 0 } },
    { { 1218, 0, 0, 0 } },
    { { 1219, 0, 0, 0 } },
    { { 1220, 0, 0, 0 } },
    { { 1221, 0, 0, 0 } },
    { { 1222, 0, 0, 0 } },
    { { 1223, 0, 0, 0 } },
    { { 1224, 0, 0, 0 } },
    { { 1225, 0, 0, 0 } },
    { { 1226, 0, 0, 0 } },
    { { 1227, 0, 0, 0 } },
    { { 1228, 0, 0, 0 } },
    { { 1229, 0, 0, 0 } },
    { { 1230, 0, 0, 0 } },
    { { 1231, 0, 0, 0 } },
    { { 1232, 0, 0, 0 } },
    { { 1233, 0, 0, 0 } },
    { { 1234, 0, 0, 0 } },
    { { 1235, 0, 0, 0 } },
    { { 1236, 0, 0, 0 } },
    { { 1237, 0, 0, 0 } },
    { { 1238, 0, 0, 0 } },
    { { 1239, 0, 0, 0 } },
    { { 1240, 0, 0, 0 } },
    { { 1241, 0, 0, 0 } },
    { { 1242, 0, 0, 0 } },
    { { 1243, 0, 0, 0 } },
    { { 1244, 0, 0, 0 } },
    { { 1245, 0, 0, 0 } },
    { { 1246, 0, 0, 0 } },
    { { 1247, 0, 0, 0 } },
    { { 1248, 0, 0, 0 } },
    { { 1249, 0, 0, 0 } },
    { { 1250, 0, 0, 0 } },
    { { 1251, 0, 0, 0 } },
    { { 1252, 0, 0, 0 } },
    { { 1253, 0, 0, 0 } },
    { { 1254, 0, 0, 0 } },
    { { 1255, 0, 0, 0 } },
    { { 1256, 0, 0, 0 } },
    { { 1257, 0, 0, 0 } },
    { { 1258, 0, 0, 0 } },
    { { 1259, 0, 0, 0 } },
    { { 1260, 0, 0, 0 } },
    { { 1261, 0, 0, 0 } },
    { { 1262, 0, 0, 0 } },
    { { 1263, 0, 0, 0 } },
    { { 1264, 0, 0, 0 } },
    { { 1265, 0, 0, 0 } },
    { { 1266, 0, 0, 0 } },
    { { 1267, 0, 0, 0 } },
    { { 1268, 0, 0, 0 } },
    { { 1269, 0, 0, 0 } },
    { { 1270, 0, 0, 0 } },
    { { 1271, 0, 0, 0 } },
    { { 1272, 0, 0, 0 } },
    { { 1273, 0, 0, 0 } },
    { { 1274, 0, 0, 0 } },
    { { 1275, 0, 0, 0 } },
    { { 1276, 0, 0, 0 } },
    { { 1277, 0, 0, 0 } },
    { { 1278, 0, 0, 0 } },
    { { 1279, 0, 0, 0 } },
    { { 1280, 0, 0, 0 } },
    { { 1281, 0, 0, 0 } },
    { { 1282, 0, 0, 0 } },
    { { 1283, 0, 0, 0 } },
    { { 1284, 0, 0, 0 } },
    { { 1285, 0, 0, 0 } },
    { { 1286, 0, 0, 0 } },
    { { 1287, 0, 0, 0 } },
    { { 1288, 0, 0, 0 } },
    { { 1289, 0, 0, 0 } },
    { { 1290, 0, 0, 0 } },
    { { 1291, 0, 0, 0 } },
    { { 1292, 0, 0, 0 } },
    { { 1293, 0, 0, 0 } },
    { { 1294, 0, 0, 0 } },
    { { 1295, 0, 0, 0 } },
    { { 1296, 0, 0, 0 } },
    { { 1297, 0, 0, 0 } },
    { { 1298, 0, 0, 0 } },
    { { 1299, 0, 0, 0 } },
    { { 1300, 0, 0, 0 } },
    { { 1301, 0, 0, 0 } },
    { { 1302, 0, 0, 0 } },
    { { 1303, 0, 0, 0 } },
    { { 1304, 0, 0, 0 } },
    { { 1305, 0, 0, 0 } },
    { { 1306, 0, 0, 0 } },
    { { 1307, 0, 0, 0 } },
    { { 1308, 0, 0, 0 } },
    { { 1309, 0, 0, 0 } },
    { { 1310, 0, 0, 0 } },
    { { 1311, 0, 0, 0 } },
    { { 1312, 0, 0, 0 } },
    { { 1313, 0, 0, 0 } },
    { { 1314, 0, 0, 0 } },
    { { 1315, 0, 0, 0 } },
    { { 1316, 0, 0, 0 } },
    { { 1317, 0, 0, 0 } },
    { { 1318, 0, 0, 0 } },
    { { 1319, 0, 0, 0 } },
    { { 1320, 0, 0, 0 } },
    { { 1321, 0, 0, 0 } },
    { { 1322, 0, 0, 0 } },
    { { 1323, 0, 0, 0 } },
    { { 1324, 0, 0, 0 } },
    { { 1325, 0, 0, 0 } },
    { { 1326, 0, 0, 0 } },
    { { 1327, 0, 0, 0 } },
    { { 1328, 0, 0, 0 } },
    { { 1329, 0, 0, 0 } },
    { { 1330, 0, 0, 0 } },
    { { 1331, 0, 0, 0 } },
    { { 1332, 0, 0, 0 } },
    { { 1333, 0, 0, 0 } },
    { { 1334, 0, 0, 0 } },
    { { 1335, 0, 0, 0 } },
    { { 1336, 0, 0, 0 } },
    { { 1337, 0, 0, 0 } },
    { { 1338, 0, 0, 0 } },
    { { 1339, 0, 0, 0 } },
    { { 1340, 0, 0, 0 } },
    { { 1341, 0, 0, 0 } },
    { { 1342, 0, 0, 0 } },
    { { 1343, 0, 0, 0 } },
    { { 1344, 0, 0, 0 } },
    { { 1345, 0, 0, 0 } },
    { { 1346, 0, 0, 0 } },
    { { 1347, 0, 0, 0 } },
    { { 1348, 0, 0, 0 } },
    { { 1349, 0, 0, 0 } },
    { { 1350, 0, 0, 0 } },
    { { 1351, 0, 0, 0 } },
    { { 1352, 0, 0, 0 } },
    { { 1353, 0, 0, 0 } },
    { { 1354, 0, 0, 0 } },
    { { 1355, 0, 0, 0 } },
    { { 1356, 0, 0, 0 } },
    { { 1357, 0, 0, 0 } },
    { { 1358, 0, 0, 0 } },
    { { 1359, 0, 0, 0 } },
    { { 1360, 0, 0, 0 } },
    { { 1361, 0, 0, 0 } },
    { { 1362, 0, 0, 0 } },
    { { 1363, 0, 0, 0 } },
    { { 1364, 0, 0, 0 } },
    { { 1365, 0, 0, 0 } },
    { { 1366, 0, 0, 0 } },
    { { 1367, 0, 0, 0 } },
    { { 1368, 0, 0, 0 } },
    { { 1369, 0, 0, 0 } },
    { { 1370, 0, 0, 0 } },
    { { 1371, 0, 0, 0 } },
    { { 1372, 0, 0, 0 } },
    { { 1373, 0, 0, 0 } },
    { { 1374, 0, 0, 0 } },
    { { 1375, 0, 0, 0 } },
    { { 1376, 0, 0, 0 } },
    { { 1377, 0, 0, 0 } },
    { { 1378, 0, 0, 0 } },
    { { 1379, 0, 0, 0 } },
    { { 1380, 0, 0, 0 } },
    { { 1381, 0, 0, 0 } },
    { { 1382, 0, 0, 0 } },
    { { 1383, 0, 0, 0 } },
    { { 1384, 0, 0, 0 } },
    { { 1385, 0, 0, 0 } },
    { { 1386, 0, 0, 0 } },
    { { 1387, 0, 0, 0 } },
    { { 1388, 0, 0, 0 } },
    { { 1389, 0, 0, 0 } },
    { { 0, 1390, 0, 0 } },
    { { 0, 1391, 0, 0 } },
    { { 0, 1392, 0, 0 } },
    { { 0, 1393, 0, 0 } },
    { { 0, 1394, 0, 0 } },
    { { 0, 1395, 0, 0 } },
    { { 0, 1396, 0, 0 } },
    { { 62, 1397, 0, 0 } },
    { { 62, 1398, 0, 0 } },
    { { 62, 1399, 0, 0 } },
    { { 62, 1400, 0, 0 } },
    { { 62, 1401, 0, 0 } },
    { { 62, 1402, 0, 0 } },
    { { 62, 1403, 0, 0 } },
    { { 62, 1404, 0, 0 } },
    { { 62, 1405, 0, 0 } },
    { { 62, 1406, 0, 0 } },
    { { 62, 1407, 0, 0 } },
    { { 0, 1408, 0, 0 } },
    { { 0, 1409, 0, 0 } },
    { { 0, 1410, 0, 0 } },
    { { 0, 1411, 0, 0 } },
    { { 0, 1412, 0, 0 } },
    { { 0, 1413, 0, 0 } },
    { { 0, 1414, 0, 0 } },
    { { 0, 1415, 0, 0 } },
    { { 0, 1416, 0, 0 } },
    { { 0, 1417, 0, 0 } },
    { { 0, 1418, 0, 0 } },
    { { 71, 1419, 0, 0 } },
    { { 71, 1420, 0, 0 } },
    { { 71, 1421, 0, 0 } },
    { { 71, 1422, 0, 0 } },
    { { 71, 1423, 0, 0 } },
    { { 71, 1424, 0, 0 } },
    { { 71, 1425, 0, 0 } },
    { { 71, 1426, 0, 0 } },
    { { 71, 1427, 0, 0 } },
    { { 71, 1428, 0, 0 } },
    { { 0, 1429, 0, 0 } },
    { { 0, 1430, 0, 0 } },
    { { 0, 1431, 0, 0 } },
    { { 0, 1432, 0, 0 } },
    { { 0, 1433, 0, 0 } },
    { { 62, 1393, 0, 0 } },
    { { 1434, 0, 0, 0 } },
    { { 1435, 0, 0, 0 } },
    { { 1436, 0, 0, 0 } },
    { { 1437, 0, 0, 0 } },
    { { 1438, 0, 0, 0 } },
    { { 1439, 0, 0, 0 } },
    { { 1440, 0, 0, 0 } },
    { { 1441, 0, 0, 0 } },
    { { 1442, 0, 0, 0 } },
    { { 1443, 0, 0, 0 } },
    { { 1444, 0, 0, 0 } },
    { { 1445, 0, 0, 0 } },
    { { 1446, 0, 0, 0 } },
    { { 1447, 0, 0, 0 } },
    { { 1448, 0, 0, 0 } },
    { { 1449, 0, 0, 0 } },
    { { 1450, 0, 0, 0 } },
    { { 1451, 0, 0, 0 } },
    { { 1452, 0, 0, 0 } },
    { { 1453, 0, 0, 0 } },
    { { 1454, 0, 0, 0 } },
    { { 1455, 0, 0, 0 } },
    { { 1456, 0, 0, 0 } },
    { { 1457, 0, 0, 0 } },
    { { 1458, 0, 0, 0 } },
    { { 1459, 0, 0, 0 } },
    { { 1460, 0, 0, 0 } },
    { { 1461, 0, 0, 0 } },
    { { 1462, 0, 0, 0 } },
    { { 1463, 1009, 0, 0 } },
    { { 1464, 1010, 0, 0 } },
    { { 1465, 1011, 0, 0 } },
    { { 1466, 1011, 0, 0 } },
    { { 1467, 1010, 0, 0 } },
    { { 1467, 1011, 0, 0 } },
    { { 1468, 1010, 0, 0 } },
    { { 1468, 1011, 0, 0 } },
    { { 1469, 0, 0, 0 } },
    { { 1470, 0, 0, 0 } },
    { { 1471, 0, 0, 0 } },
    { { 1472, 0, 0, 0 } },
    { { 1473, 0, 0, 0 } },
    { { 1474, 0, 0, 0 } },
    { { 1475, 0, 0, 0 } },
    { { 1476, 0, 0, 0 } },
    { { 1477, 0, 0, 0 } },
    { { 1478, 0, 0, 0 } },
    { { 1479, 0, 0, 0 } },
    { { 1480, 0, 0, 0 } },
    { { 1481, 0, 0, 0 } },
    { { 1482, 0, 0, 0 } },
    { { 1483, 0, 0, 0 } },
    { { 1484, 0, 0, 0 } },
    { { 1485, 0, 0, 0 } },
    { { 1486, 0, 0, 0 } },
    { { 1487, 0, 0, 0 } },
    { { 1488, 0, 0, 0 } },
    { { 1489, 0, 0, 0 } },
    { { 1490, 0, 0, 0 } },
    { { 1491, 0, 0, 0 } },
    { { 1492, 0, 0, 0 } },
    { { 1493, 0, 0, 0 } },
    { { 1494, 0, 0, 0 } },
    { { 1495, 0, 0, 0 } },
    { { 1496, 0, 0, 0 } },
    { { 1497, 0, 0, 0 } },
    { { 1498, 0, 0, 0 } },
    { { 1499, 0, 0, 0 } },
    { { 1500, 0, 0, 0 } },
    { { 1501, 0, 0, 0 } },
    { { 1502, 0, 0, 0 } },
    { { 1503, 0, 0, 0 } },
    { { 1504, 0, 0, 0 } },
    { { 1505, 0, 0, 0 } },
    { { 1506, 0, 0, 0 } },
    { { 1507, 0, 0, 0 } },
    { { 1508, 0, 0, 0 } },
    { { 1509, 0, 0, 0 } },
    { { 1510, 0, 0, 0 } },
    { { 1511, 0, 0, 0 } },
    { { 1512, 0, 0, 0 } },
    { { 1513, 0, 0, 0 } },
    { { 1514, 0, 0, 0 } },
    { { 1515, 0, 0, 0 } },
    { { 1516, 0, 0, 0 } },
    { { 1517, 0, 0, 0 } },
    { { 1518, 0, 0, 0 } },
    { { 1519, 0, 0, 0 } },
    { { 1520, 0, 0, 0 } },
    { { 1521, 0, 0, 0 } },
    { { 1522, 0, 0, 0 } },
    { { 1523, 0, 0, 0 } },
    { { 1524, 0, 0, 0 } },
    { { 1525, 0, 0, 0 } },
    { { 1526, 0, 0, 0 } },
    { { 1527, 0, 0, 0 } },
    { { 1528, 0, 0, 0 } },
    { { 1529, 0, 0, 0 } },
    { { 1530, 0, 0, 0 } },
    { { 1531, 0, 0, 0 } },
    { { 1532, 0, 0, 0 } },
    { { 1533, 0, 0, 0 } },
    { { 1534, 0, 0, 0 } },
    { { 1535, 0, 0, 0 } },
    { { 1536, 0, 0, 0 } },
    { { 1537, 0, 0, 0 } },
    { { 1538, 0, 0, 0 } },
    { { 1539, 0, 0, 0 } },
    { { 1540, 0, 0, 0 } },
    { { 1541, 0, 0, 0 } },
    { { 1542, 0, 0, 0 } },
    { { 1543, 0, 0, 0 } },
    { { 1544, 0, 0, 0 } },
    { { 1545, 0, 0, 0 } },
    { { 1546, 0, 0, 0 } },
    { { 1547, 0, 0, 0 } },
    { { 1548, 0, 0, 0 } },
    { { 1549, 0, 0, 0 } },
    { { 1550, 0, 0, 0 } },
    { { 1551, 0, 0, 0 } },
    { { 1552, 0, 0, 0 } },
    { { 1553, 0, 0, 0 } },
    { { 1554, 0, 0, 0 } },
    { { 1555, 0, 0, 0 } },
    { { 1556, 0, 0, 0 } },
    { { 1557, 0, 0, 0 } },
    { { 1558, 0, 0, 0 } },
    { { 1559, 0, 0, 0 } },
    { { 1560, 0, 0, 0 } },
    { { 1561, 0, 0, 0 } },
    { { 1562, 0, 0, 0 } },
    { { 1563, 0, 0, 0 } },
    { { 1564, 0, 0, 0 } },
    { { 1565, 0, 0, 0 } },
    { { 1566, 0, 0, 0 } },
    { { 1567, 0, 0, 0 } },
    { { 1568, 0, 0, 0 } },
    { { 1569, 0, 0, 0 } },
    { { 1570, 0, 0, 0 } },
    { { 1571, 0, 0, 0 } },
    { { 1572, 0, 0, 0 } },
    { { 1573, 0, 0, 0 } },
    { { 1574, 0, 0, 0 } },
    { { 1575, 0, 0, 0 } },
    { { 1576, 0, 0, 0 } },
    { { 1577, 0, 0, 0 } },
    { { 1578, 0, 0, 0 } },
    { { 1579, 0, 0, 0 } },
    { { 1580, 0, 0, 0 } },
    { { 1581, 0, 0, 0 } },
    { { 1582, 0, 0, 0 } },
    { { 1583, 0, 0, 0 } },
    { { 1584, 0, 0, 0 } },
    { { 1585, 0, 0, 0 } },
    { { 1586, 0, 0, 0 } },
    { { 1587, 0, 0, 0 } },
    { { 1588, 0, 0, 0 } },
    { { 1589, 0, 0, 0 } },
    { { 1590, 0, 0, 0 } },
    { { 1591, 0, 0, 0 } },
    { { 1592, 0, 0, 0 } },
    { { 1593, 0, 0, 0 } },
    { { 1594, 0, 0, 0 } },
    { { 1595, 0, 0, 0 } },
    { { 1596, 0, 0, 0 } },
    { { 1597, 0, 0, 0 } },
    { { 1598, 0, 0, 0 } },
    { { 1599, 0, 0, 0 } },
    { { 1600, 0, 0, 0 } },
    { { 1601, 0, 0, 0 } },
    { { 1602, 0, 0, 0 } },
    { { 1603, 0, 0, 0 } },
    { { 1604, 0, 0, 0 } },
    { { 1605, 0, 0, 0 } },
    { { 1606, 0, 0, 0 } },
    { { 1607, 0, 0, 0 } },
    { { 1608, 0, 0, 0 } },
    { { 1609, 0, 0, 0 } },
    { { 1610, 0, 0, 0 } },
    { { 1611, 0, 0, 0 } },
    { { 1612, 0, 0, 0 } },
    { { 1613, 0, 0, 0 } },
    { { 1614, 0, 0, 0 } },
    { { 1615, 0, 0, 0 } },
    { { 1616, 0, 0, 0 } },
    { { 1617, 0, 0, 0 } },
    { { 1618, 0, 0, 0 } },
    { { 1619, 0, 0, 0 } },
    { { 1620, 0, 0, 0 } },
    { { 1621, 0, 0, 0 } },
    { { 1622, 0, 0, 0 } },
    { { 1623, 0, 0, 0 } },
    { { 1624, 0, 0, 0 } },
    { { 1625, 0, 0, 0 } },
    { { 1626, 0, 0, 0 } },
    { { 1627, 0, 0, 0 } },
    { { 1628, 0, 0, 0 } },
    { { 1629, 0, 0, 0 } },
    { { 1630, 0, 0, 0 } },
    { { 1631, 0, 0, 0 } },
    { { 1632, 0, 0, 0 } },
    { { 1633, 0, 0, 0 } },
    { { 1634, 0, 0, 0 } },
    { { 1635, 0, 0, 0 } },
    { { 1636, 0, 0, 0 } },
    { { 1637, 0, 0, 0 } },
    { { 1638, 0, 0, 0 } },
    { { 1639, 0, 0, 0 } },
    { { 1640, 0, 0, 0 } },
    { { 1641, 0, 0, 0 } },
    { { 1642, 0, 0, 0 } },
    { { 1643, 0, 0, 0 } },
    { { 1644, 0, 0, 0 } },
    { { 1645, 0, 0, 0 } },
    { { 1646, 0, 0, 0 } },
    { { 1647, 0, 0, 0 } },
    { { 1648, 0, 0, 0 } },
    { { 1649, 0, 0, 0 } },
    { { 1650, 0, 0, 0 } },
    { { 1651, 0, 0, 0 } },
    { { 1652, 0, 0, 0 } },
    { { 1653, 0, 0, 0 } },
    { { 1654, 0, 0, 0 } },
    { { 1655, 0, 0, 0 } },
    { { 1656, 0, 0, 0 } },
    { { 1657, 0, 0, 0 } },
    { { 1658, 0, 0, 0 } },
    { { 1659, 0, 0, 0 } },
    { { 1660, 0, 0, 0 } },
    { { 1661, 0, 0, 0 } },
    { { 1662, 0, 0, 0 } },
    { { 1663, 0, 0, 0 } },
    { { 1664, 0, 0, 0 } },
    { { 1665, 0, 0, 0 } },
    { { 1666, 0, 0, 0 } },
    { { 1667, 0, 0, 0 } },
    { { 1668, 0, 0, 0 } },
    { { 1669, 0, 0, 0 } },
    { { 1670, 0, 0, 0 } },
    { { 1671, 0, 0, 0 } },
    { { 1672, 0, 0, 0 } },
    { { 1673, 0, 0, 0 } },
    { { 1674, 0, 0, 0 } },
    { { 1675, 0, 0, 0 } },
    { { 1676, 0, 0, 0 } },
    { { 1677, 0, 0, 0 } },
    { { 1678, 0, 0, 0 } },
    { { 1679, 0, 0, 0 } },
    { { 1680, 0, 0, 0 } },
    { { 1681, 0, 0, 0 } },
    { { 1682, 0, 0, 0 } },
    { { 1683, 0, 0, 0 } },
    { { 1684, 0, 0, 0 } },
    { { 1685, 0, 0, 0 } },
    { { 1686, 0, 0, 0 } },
    { { 1687, 0, 0, 0 } },
    { { 1688, 0, 0, 0 } },
    { { 1689, 0, 0, 0 } },
    { { 1690, 0, 0, 0 } },
    { { 1691, 0, 0, 0 } },
    { { 1692, 0, 0, 0 } },
    { { 1693, 0, 0, 0 } },
    { { 1694, 0, 0, 0 } },
    { { 1695, 0, 0, 0 } },
    { { 1696, 0, 0, 0 } },
    { { 1697, 0, 0, 0 } },
    { { 1698, 0, 0, 0 } },
    { { 1699, 0, 0, 0 } },
    { { 1700, 0, 0, 0 } },
    { { 1701, 0, 0, 0 } },
    { { 1702, 0, 0, 0 } },
    { { 1703, 0, 0, 0 } },
    { { 1704, 0, 0, 0 } },
    { { 1705, 0, 0, 0 } },
    { { 1706, 0, 0, 0 } },
    { { 1707, 0, 0, 0 } },
    { { 1708, 0, 0, 0 } },
    { { 1709, 0, 0, 0 } },
    { { 1710, 0, 0, 0 } },
    { { 1711, 0, 0, 0 } },
    { { 1712, 0, 0, 0 } },
    { { 1713, 0, 0, 0 } },
    { { 1714, 0, 0, 0 } },
    { { 1715, 0, 0, 0 } },
    { { 1716, 0, 0, 0 } },
    { { 1717, 0, 0, 0 } },
    { { 1718, 0, 0, 0 } },
    { { 1719, 0, 0, 0 } },
    { { 1720, 0, 0, 0 } },
    { { 1721, 0, 0, 0 } },
    { { 1722, 0, 0, 0 } },
    { { 1723, 0, 0, 0 } },
    { { 1724, 0, 0, 0 } },
    { { 1725, 0, 0, 0 } },
    { { 1726, 0, 0, 0 } },
    { { 1727, 0, 0, 0 } },
    { { 1728, 0, 0, 0 } },
    { { 1729, 0, 0, 0 } },
    { { 1730, 0, 0, 0 } },
    { { 1731, 0, 0, 0 } },
    { { 1732, 0, 0, 0 } },
    { { 1733, 0, 0, 0 } },
    { { 1734, 0, 0, 0 } },
    { { 1735, 0, 0, 0 } },
    { { 1736, 0, 0, 0 } },
    { { 1737, 0, 0, 0 } },
    { { 1738, 0, 0, 0 } },
    { { 1739, 0, 0, 0 } },
    { { 1740, 0, 0, 0 } },
    { { 1741, 0, 0, 0 } },
    { { 1742, 0, 0, 0 } },
    { { 1743, 0, 0, 0 } },
    { { 1744, 0, 0, 0 } },
    { { 1745, 0, 0, 0 } },
    { { 1746, 0, 0, 0 } },
    { { 1747, 0, 0, 0 } },
    { { 1748, 0, 0, 0 } },
    { { 1749, 0, 0, 0 } },
    { { 1750, 0, 0, 0 } },
    { { 1751, 0, 0, 0 } },
    { { 1752, 0, 0, 0 } },
    { { 1753, 0, 0, 0 } },
    { { 1754, 0, 0, 0 } },
    { { 1755, 0, 0, 0 } },
    { { 1756, 0, 0, 0 } },
    { { 1757, 0, 0, 0 } },
    { { 1758, 0, 0, 0 } },
    { { 1759, 0, 0, 0 } },
    { { 1760, 0, 0, 0 } },
    { { 1761, 0, 0, 0 } },
    { { 1762, 0, 0, 0 } },
    { { 1763, 0, 0, 0 } },
    { { 1764, 0, 0, 0 } },
    { { 1765, 0, 0, 0 } },
    { { 1766, 0, 0, 0 } },
    { { 1767, 0, 0, 0 } },
    { { 1768, 0, 0, 0 } },
    { { 1769, 0, 0, 0 } },
    { { 1770, 0, 0, 0 } },
    { { 1771, 0, 0, 0 } },
    { { 1772, 0, 0, 0 } },
    { { 1773, 0, 0, 0 } },
    { { 1774, 0, 0, 0 } },
    { { 1775, 0, 0, 0 } },
    { { 1776, 0, 0, 0 } },
    { { 1777, 0, 0, 0 } },
    { { 1778, 0, 0, 0 } },
    { { 1779, 0, 0, 0 } },
    { { 1780, 0, 0, 0 } },
    { { 1781, 0, 0, 0 } },
    { { 1782, 0, 0, 0 } },
    { { 1783, 0, 0, 0 } },
    { { 1784, 0, 0, 0 } },
    { { 1785, 0, 0, 0 } },
    { { 1786, 0, 0, 0 } },
    { { 1787, 0, 0, 0 } },
    { { 1788, 0, 0, 0 } },
    { { 1789, 0, 0, 0 } },
    { { 1790, 0, 0, 0 } },
    { { 1791, 0, 0, 0 } },
    { { 1792, 0, 0, 0 } },
    { { 1793, 0, 0, 0 } },
    { { 1794, 0, 0, 0 } },
    { { 1795, 0, 0, 0 } },
    { { 1796, 0, 0, 0 } },
    { { 1797, 0, 0, 0 } },
    { { 1798, 0, 0, 0 } },
    { { 1799, 0, 0, 0 } },
    { { 1800, 0, 0, 0 } },
    { { 1801, 0, 0, 0 } },
    { { 1802, 0, 0, 0 } },
    { { 1803, 0, 0, 0 } },
    { { 1804, 0, 0, 0 } },
    { { 1805, 0, 0, 0 } },
    { { 1806, 0, 0, 0 } },
    { { 1807, 0, 0, 0 } },
    { { 1808, 0, 0, 0 } },
    { { 1809, 0, 0, 0 } },
    { { 1810, 0, 0, 0 } },
    { { 1811, 0, 0, 0 } },
    { { 1812, 0, 0, 0 } },
    { { 1813, 0, 0, 0 } },
    { { 1814, 0, 0, 0 } },
    { { 1815, 0, 0, 0 } },
    { { 1816, 0, 0, 0 } },
    { { 1817, 0, 0, 0 } },
    { { 1818, 0, 0, 0 } },
    { { 1819, 0, 0, 0 } },
    { { 1820, 0, 0, 0 } },
    { { 1821, 0, 0, 0 } },
    { { 1822, 0, 0, 0 } },
    { { 1823, 0, 0, 0 } },
    { { 1824, 0, 0, 0 } },
    { { 1825, 0, 0, 0 } },
    { { 1826, 0, 0, 0 } },
    { { 1827, 0, 0, 0 } },
    { { 1828, 0, 0, 0 } },
    { { 1829, 0, 0, 0 } },
    { { 1830, 0, 0, 0 } },
    { { 1831, 0, 0, 0 } },
    { { 1832, 0, 0, 0 } },
    { { 1833, 0, 0, 0 } },
    { { 1834, 0, 0, 0 } },
    { { 1835, 0, 0, 0 } },
    { { 1836, 0, 0, 0 } },
    { { 1837, 0, 0, 0 } },
    { { 1838, 0, 0, 0 } },
    { { 1839, 0, 0, 0 } },
    { { 1840, 0, 0, 0 } },
    { { 1841, 0, 0, 0 } },
    { { 1842, 0, 0, 0 } },
    { { 1843, 0, 0, 0 } },
    { { 1844, 0, 0, 0 } },
    { { 1845, 0, 0, 0 } },
    { { 1846, 0, 0, 0 } },
    { { 1847, 0, 0, 0 } },
    { { 1848, 0, 0, 0 } },
    { { 1849, 0, 0, 0 } },
    { { 1850, 0, 0, 0 } },
    { { 1851, 0, 0, 0 } },
    { { 1852, 0, 0, 0 } },
    { { 1853, 0, 0, 0 } },
    { { 1854, 0, 0, 0 } },
    { { 1855, 0, 0, 0 } },
    { { 1856, 0, 0, 0 } },
    { { 1857, 0, 0, 0 } },
    { { 1858, 0, 0, 0 } },
    { { 1859, 0, 0, 0 } },
    { { 1860, 0, 0, 0 } },
    { { 1861, 0, 0, 0 } },
    { { 1862, 0, 0, 0 } },
    { { 1863, 0, 0, 0 } },
    { { 1864, 0, 0, 0 } },
    { { 1865, 0, 0, 0 } },
    { { 1866, 0, 0, 0 } },
    { { 1867, 0, 0, 0 } },
    { { 1868, 0, 0, 0 } },
    { { 1869, 0, 0, 0 } },
    { { 1870, 0, 0, 0 } },
    { { 1871, 0, 0, 0 } },
    { { 1872, 0, 0, 0 } },
    { { 1873, 0, 0, 0 } },
    { { 1874, 0, 0, 0 } },
    { { 1875, 0, 0, 0 } },
    { { 1876, 0, 0, 0 } },
    { { 1877, 0, 0, 0 } },
    { { 1878, 0, 0, 0 } },
    { { 1879, 0, 0, 0 } },
    { { 1880, 0, 0, 0 } },
    { { 1881, 0, 0, 0 } },
    { { 1882, 0, 0, 0 } },
    { { 1883, 0, 0, 0 } },
    { { 1884, 0, 0, 0 } },
    { { 1885, 0, 0, 0 } },
    { { 1886, 0, 0, 0 } },
    { { 1887, 0, 0, 0 } },
    { { 1888, 0, 0, 0 } },
    { { 1889, 0, 0, 0 } },
    { { 1890, 0, 0, 0 } },
    { { 1891, 0, 0, 0 } },
    { { 1892, 0, 0, 0 } },
    { { 1893, 0, 0, 0 } },
    { { 1894, 0, 0, 0 } },
    { { 1895, 0, 0, 0 } },
    { { 1896, 0, 0, 0 } },
    { { 1897, 0, 0, 0 } },
    { { 1898, 0, 0, 0 } },
    { { 1899, 0, 0, 0 } },
    { { 1900, 0, 0, 0 } },
    { { 1901, 0, 0, 0 } },
    { { 1902, 0, 0, 0 } },
    { { 1903, 0, 0, 0 } },
    { { 1904, 0, 0, 0 } },
    { { 1905, 0, 0, 0 } },
    { { 1906, 0, 0, 0 } },
    { { 1907, 0, 0, 0 } },
    { { 1908, 0, 0, 0 } },
    { { 1909, 0, 0, 0 } },
    { { 1910, 0, 0, 0 } },
    { { 1911, 0, 0, 0 } },
    { { 1912, 0, 0, 0 } },
    { { 1913, 0, 0, 0 } },
    { { 1914, 0, 0, 0 } },
    { { 1915, 0, 0, 0 } },
    { { 1916, 0, 0, 0 } },
    { { 1917, 0, 0, 0 } },
    { { 1918, 0, 0, 0 } },
    { { 1919, 0, 0, 0 } },
    { { 1920, 0, 0, 0 } },
    { { 1921, 0, 0, 0 } },
    { { 1922, 0, 0, 0 } },
    { { 1923, 0, 0, 0 } },
    { { 1924, 0, 0, 0 } },
    { { 1925, 0, 0, 0 } },
    { { 1926, 0, 0, 0 } },
    { { 1927, 0, 0, 0 } },
    { { 1928, 0, 0, 0 } },
    { { 1929, 0, 0, 0 } },
    { { 1930, 0, 0, 0 } },
    { { 1931, 0, 0, 0 } },
    { { 1932, 0, 0, 0 } },
    { { 1933, 0, 0, 0 } },
    { { 1934, 0, 0, 0 } },
    { { 1935, 0, 0, 0 } },
    { { 1936, 0, 0, 0 } },
    { { 1937, 0, 0, 0 } },
    { { 1938, 0, 0, 0 } },
    { { 1939, 0, 0, 0 } },
    { { 1940, 0, 0, 0 } },
    { { 1941, 0, 0, 0 } },
    { { 1942, 0, 0, 0 } },
    { { 1943, 0, 0, 0 } },
    { { 1944, 0, 0, 0 } },
    { { 1945, 0, 0, 0 } },
    { { 1946, 0, 0, 0 } },
    { { 1947, 0, 0, 0 } },
    { { 1948, 0, 0, 0 } },
    { { 1949, 0, 0, 0 } },
    { { 1950, 0, 0, 0 } },
    { { 1951, 0, 0, 0 } },
    { { 1952, 0, 0, 0 } },
    { { 1953, 0, 0, 0 } },
    { { 1954, 0, 0, 0 } },
    { { 1955, 0, 0, 0 } },
    { { 1956, 0, 0, 0 } },
    { { 1957, 0, 0, 0 } },
    { { 1958, 0, 0, 0 } },
    { { 1959, 0, 0, 0 } },
    { { 1960, 0, 0, 0 } },
    { { 1961, 0, 0, 0 } },
    { { 1962, 0, 0, 0 } },
    { { 1963, 0, 0, 0 } },
    { { 1964, 0, 0, 0 } },
    { { 1965, 0, 0, 0 } },
    { { 1966, 0, 0, 0 } },
    { { 1967, 0, 0, 0 } },
    { { 1968, 0, 0, 0 } },
    { { 1969, 0, 0, 0 } },
    { { 1970, 0, 0, 0 } },
    { { 1971, 0, 0, 0 } },
    { { 1972, 0, 0, 0 } },
    { { 1973, 0, 0, 0 } },
    { { 1974, 0, 0, 0 } },
    { { 1975, 0, 0, 0 } },
    { { 1976, 0, 0, 0 } },
    { { 1977, 0, 0, 0 } },
    { { 1978, 0, 0, 0 } },
    { { 1979, 0, 0, 0 } },
    { { 1980, 0, 0, 0 } },
    { { 1981, 0, 0, 0 } },
    { { 1982, 0, 0, 0 } },
    { { 1983, 0, 0, 0 } },
    { { 1984, 0, 0, 0 } },
    { { 1985, 0, 0, 0 } },
    { { 1986, 0, 0, 0 } },
    { { 1987, 0, 0, 0 } },
    { { 1988, 0, 0, 0 } },
    { { 1989, 0, 0, 0 } },
    { { 1990, 0, 0, 0 } },
    { { 1991, 0, 0, 0 } },
    { { 1992, 0, 0, 0 } },
    { { 1993, 0, 0, 0 } },
    { { 1994, 0, 0, 0 } },
    { { 1995, 0, 0, 0 } },
    { { 1996, 0, 0, 0 } },
    { { 1997, 0, 0, 0 } },
    { { 1998, 0, 0, 0 } },
    { { 1999, 0, 0, 0 } },
    { { 2000, 0, 0, 0 } },
    { { 2001, 0, 0, 0 } },
    { { 2002, 0, 0, 0 } },
    { { 2003, 0, 0, 0 } },
    { { 2004, 0, 0, 0 } },
    { { 2005, 0, 0, 0 } },
    { { 2006, 0, 0, 0 } },
    { { 2007, 0, 0, 0 } },
    { { 2008, 0, 0, 0 } },
    { { 2009, 0, 0, 0 } },
    { { 2010, 0, 0, 0 } },
    { { 2011, 0, 0, 0 } },
    { { 2012, 0, 0, 0 } },
    { { 2013, 0, 0, 0 } },
    { { 2014, 0, 0, 0 } },
    { { 2015, 0, 0, 0 } },
    { { 2016, 0, 0, 0 } },
    { { 2017, 0, 0, 0 } },
    { { 2018, 0, 0, 0 } },
    { { 2019, 0, 0, 0 } },
    { { 2020, 0, 0, 0 } },
    { { 2021, 0, 0, 0 } },
    { { 2022, 0, 0, 0 } },
    { { 2023, 0, 0, 0 } },
    { { 2024, 0, 0, 0 } },
    { { 2025, 0, 0, 0 } },
    { { 2026, 0, 0, 0 } },
    { { 2027, 0, 0, 0 } },
    { { 2028, 0, 0, 0 } },
    { { 2029, 0, 0, 0 } },
    { { 2030, 0, 0, 0 } },
    { { 2031, 0, 0, 0 } },
    { { 2032, 0, 0, 0 } },
    { { 2033, 0, 0, 0 } },
    { { 2034, 0, 0, 0 } },
    { { 2035, 0, 0, 0 } },
    { { 2036, 0, 0, 0 } },
    { { 2037, 0, 0, 0 } },
    { { 2038, 0, 0, 0 } },
    { { 2039, 0, 0, 0 } },
    { { 2040, 0, 0, 0 } },
    { { 2041, 0, 0, 0 } },
    { { 2042, 0, 0, 0 } },
    { { 2043, 0, 0, 0 } },
    { { 2044, 0, 0, 0 } },
    { { 2045, 0, 0, 0 } },
    { { 2046, 0, 0, 0 } },
    { { 2047, 0, 0, 0 } },
    { { 2048, 0, 0, 0 } },
    { { 2049, 0, 0, 0 } },
    { { 2050, 0, 0, 0 } },
    { { 2051, 0, 0, 0 } },
    { { 2052, 0, 0, 0 } },
    { { 2053, 0, 0, 0 } },
    { { 2054, 0, 0, 0 } },
    { { 2055, 0, 0, 0 } },
    { { 2056, 0, 0, 0 } },
    { { 2057, 0, 0, 0 } },
    { { 2058, 0, 0, 0 } },
    { { 2059, 0, 0, 0 } },
    { { 2060, 0, 0, 0 } },
    { { 2061, 0, 0, 0 } },
    { { 2062, 0, 0, 0 } },
    { { 2063, 0, 0, 0 } },
    { { 2064, 0, 0, 0 } },
    { { 2065, 0, 0, 0 } },
    { { 2066, 0, 0, 0 } },
    { { 2067, 0, 0, 0 } },
    { { 2068, 0, 0, 0 } },
    { { 2069, 0, 0, 0 } },
    { { 2070, 0, 0, 0 } },
    { { 2071, 0, 0, 0 } },
    { { 2072, 0, 0, 0 } },
    { { 2073, 0, 0, 0 } },
    { { 2074, 0, 0, 0 } },
    { { 2075, 0, 0, 0 } },
    { { 2076, 0, 0, 0 } },
    { { 2077, 0, 0, 0 } },
    { { 2078, 0, 0, 0 } },
    { { 2079, 0, 0, 0 } },
    { { 2080, 0, 0, 0 } },
    { { 2081, 0, 0, 0 } },
    { { 2082, 0, 0, 0 } },
    { { 2083, 0, 0, 0 } },
    { { 2084, 0, 0, 0 } },
    { { 2085, 0, 0, 0 } },
    { { 2086, 0, 0, 0 } },
    { { 2087, 0, 0, 0 } },
    { { 2088, 0, 0, 0 } },
    { { 2089, 0, 0, 0 } },
    { { 2090, 0, 0, 0 } },
    { { 2091, 0, 0, 0 } },
    { { 2092, 0, 0, 0 } },
    { { 2093, 0, 0, 0 } },
    { { 2094, 0, 0, 0 } },
    { { 2095, 0, 0, 0 } },
    { { 2096, 0, 0, 0 } },
    { { 2097, 0, 0, 0 } },
    { { 2098, 0, 0, 0 } },
    { { 2099, 0, 0, 0 } },
    { { 2100, 0, 0, 0 } },
    { { 2101, 0, 0, 0 } },
    { { 2102, 0, 0, 0 } },
    { { 2103, 0, 0, 0 } },
    { { 2104, 0, 0, 0 } },
    { { 2105, 0, 0, 0 } },
    { { 2106, 0, 0, 0 } },
    { { 2107, 0, 0, 0 } },
    { { 2108, 0, 0, 0 } },
    { { 2109, 0, 0, 0 } },
    { { 2110, 0, 0, 0 } },
    { { 2111, 0, 0, 0 } },
    { { 2112, 0, 0, 0 } },
    { { 2113, 0, 0, 0 } },
    { { 2114, 0, 0, 0 } },
    { { 2115, 0, 0, 0 } },
    { { 2116, 0, 0, 0 } },
    { { 2117, 0, 0, 0 } },
    { { 2118, 0, 0, 0 } },
    { { 2119, 0, 0, 0 } },
    { { 2120, 0, 0, 0 } },
    { { 2121, 0, 0, 0 } },
    { { 2122, 0, 0, 0 } },
    { { 2123, 0, 0, 0 } },
    { { 2124, 0, 0, 0 } },
    { { 2125, 0, 0, 0 } },
    { { 2126, 0, 0, 0 } },
    { { 2127, 0, 0, 0 } },
    { { 2128, 0, 0, 0 } },
    { { 2129, 0, 0, 0 } },
    { { 2130, 0, 0, 0 } },
    { { 2131, 0, 0, 0 } },
    { { 2132, 0, 0, 0 } },
    { { 2133, 0, 0, 0 } },
    { { 2134, 0, 0, 0 } },
    { { 2135, 0, 0, 0 } },
    { { 2136, 0, 0, 0 } },
    { { 2137, 0, 0, 0 } },
    { { 2138, 0, 0, 0 } },
    { { 2139, 0, 0, 0 } },
    { { 2140, 0, 0, 0 } },
    { { 2141, 0, 0, 0 } },
    { { 2142, 0, 0, 0 } },
    { { 2143, 0, 0, 0 } },
    { { 2144, 0, 0, 0 } },
    { { 2145, 0, 0, 0 } },
    { { 2146, 0, 0, 0 } },
    { { 2147, 0, 0, 0 } },
    { { 2148, 0, 0, 0 } },
    { { 2149, 0, 0, 0 } },
    { { 2150, 0, 0, 0 } },
    { { 2151, 0, 0, 0 } },
    { { 2152, 0, 0, 0 } },
    { { 2153, 0, 0, 0 } },
    { { 2154, 0, 0, 0 } },
    { { 2155, 0, 0, 0 } },
    { { 2156, 0, 0, 0 } },
    { { 2157, 0, 0, 0 } },
    { { 2158, 0, 0, 0 } },
    { { 2159, 0, 0, 0 } },
    { { 2160, 0, 0, 0 } },
    { { 2161, 0, 0, 0 } },
    { { 2162, 0, 0, 0 } },
    { { 2163, 0, 0, 0 } },
    { { 2164, 0, 0, 0 } },
    { { 2165, 0, 0, 0 } },
    { { 2166, 0, 0, 0 } },
    { { 2167, 0, 0, 0 } },
    { { 2168, 0, 0, 0 } },
    { { 2169, 0, 0, 0 } },
    { { 2170, 0, 0, 0 } },
    { { 2171, 0, 0, 0 } },
    { { 2172, 0, 0, 0 } },
    { { 2173, 0, 0, 0 } },
    { { 2174, 0, 0, 0 } },
    { { 2175, 0, 0, 0 } },
    { { 2176, 0, 0, 0 } },
    { { 2177, 0, 0, 0 } },
    { { 2178, 0, 0, 0 } },
    { { 2179, 0, 0, 0 } },
    { { 2180, 0, 0, 0 } },
    { { 2181, 0, 0, 0 } },
    { { 2182, 0, 0, 0 } },
    { { 2183, 0, 0, 0 } },
    { { 2184, 0, 0, 0 } },
    { { 2185, 0, 0, 0 } },
    { { 2186, 0, 0, 0 } },
    { { 2187, 0, 0, 0 } },
    { { 2188, 0, 0, 0 } },
    { { 2189, 0, 0, 0 } },
    { { 2190, 0, 0, 0 } },
    { { 2191, 0, 0, 0 } },
    { { 2192, 0, 0, 0 } },
    { { 2193, 0, 0, 0 } },
    { { 2194, 0, 0, 0 } },
    { { 2195, 0, 0, 0 } },
    { { 2196, 0, 0, 0 } },
    { { 2197, 0, 0, 0 } },
    { { 2198, 0, 0, 0 } },
    { { 2199, 0, 0, 0 } },
    { { 2200, 0, 0, 0 } },
    { { 2201, 0, 0, 0 } },
    { { 2202, 0, 0, 0 } },
    { { 2203, 0, 0, 0 } },
    { { 2204, 0, 0, 0 } },
    { { 2205, 0, 0, 0 } },
    { { 2206, 0, 0, 0 } },
    { { 2207, 0, 0, 0 } },
    { { 2208, 0, 0, 0 } },
    { { 2209, 0, 0, 0 } },
    { { 2210, 0, 0, 0 } },
    { { 2211, 0, 0, 0 } },
    { { 2212, 0, 0, 0 } },
    { { 2213, 0, 0, 0 } },
    { { 2214, 0, 0, 0 } },
    { { 2215, 0, 0, 0 } },
    { { 2216, 0, 0, 0 } },
    { { 2217, 0, 0, 0 } },
    { { 2218, 0, 0, 0 } },
    { { 2219, 0, 0, 0 } },
    { { 2220, 0, 0, 0 } },
    { { 2221, 0, 0, 0 } },
    { { 2222, 0, 0, 0 } },
    { { 2223, 0, 0, 0 } },
    { { 2224, 0, 0, 0 } },
    { { 2225, 0, 0, 0 } },
    { { 2226, 0, 0, 0 } },
    { { 2227, 0, 0, 0 } },
    { { 2228, 0, 0, 0 } },
    { { 2229, 0, 0, 0 } },
    { { 2230, 0, 0, 0 } },
    { { 2231, 0, 0, 0 } },
    { { 2232, 0, 0, 0 } },
    { { 2233, 0, 0, 0 } },
    { { 2234, 0, 0, 0 } },
    { { 2235, 0, 0, 0 } },
    { { 2236, 0, 0, 0 } },
    { { 2237, 0, 0, 0 } },
    { { 2238, 0, 0, 0 } },
    { { 2239, 0, 0, 0 } },
    { { 2240, 0, 0, 0 } },
    { { 2241, 0, 0, 0 } },
    { { 2242, 0, 0, 0 } },
    { { 2243, 0, 0, 0 } },
    { { 2244, 0, 0, 0 } },
    { { 2245, 0, 0, 0 } },
    { { 2246, 0, 0, 0 } },
    { { 2247, 0, 0, 0 } },
    { { 2248, 0, 0, 0 } },
    { { 2249, 0, 0, 0 } },
    { { 2250, 0, 0, 0 } },
    { { 2251, 0, 0, 0 } },
    { { 2252, 0, 0, 0 } },
    { { 2253, 0, 0, 0 } },
    { { 2254, 0, 0, 0 } },
    { { 2255, 0, 0, 0 } },
    { { 2256, 0, 0, 0 } },
    { { 2257, 0, 0, 0 } },
    { { 2258, 0, 0, 0 } },
    { { 2259, 0, 0, 0 } },
    { { 2260, 0, 0, 0 } },
    { { 2261, 0, 0, 0 } },
    { { 2262, 0, 0, 0 } },
    { { 2263, 0, 0, 0 } },
    { { 2264, 0, 0, 0 } },
    { { 2265, 0, 0, 0 } },
    { { 2266, 0, 0, 0 } },
    { { 2267, 0, 0, 0 } },
    { { 2268, 0, 0, 0 } },
    { { 2269, 0, 0, 0 } },
    { { 2270, 0, 0, 0 } },
    { { 2271, 0, 0, 0 } },
    { { 2272, 0, 0, 0 } },
    { { 2273, 0, 0, 0 } },
    { { 2274, 0, 0, 0 } },
    { { 2275, 0, 0, 0 } },
    { { 2276, 0, 0, 0 } },
    { { 2277, 0, 0, 0 } },
    { { 2278, 0, 0, 0 } },
    { { 2279, 0, 0, 0 } },
    { { 2280, 0, 0, 0 } },
    { { 2281, 0, 0, 0 } },
    { { 2282, 0, 0, 0 } },
    { { 2283, 0, 0, 0 } },
    { { 2284, 0, 0, 0 } },
    { { 2285, 0, 0, 0 } },
};

const OVERLAP_PARTS ibuki_overlap_char_tbl[2286] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1, 38512 },
    { 7, 94, 0, 0, 1, 0, 1, 0, 0, 0, 38559 },
    { -1, 93, 0, 0, 1, 0, 2, 0, 0, 3, 38560 },
    { 0, 93, 0, 0, 1, 0, 2, 0, 0, 0, 38562 },
    { 0, 93, 0, 0, 1, 0, 2, 0, 0, 5, 38563 },
    { 1, 92, 0, 0, 1, 0, 2, 0, 0, 0, 38543 },
    { 0, 92, 0, 0, 1, 0, 2, 0, 0, 7, 38545 },
    { 1, 91, 0, 0, 1, 0, 3, 0, 0, 0, 38546 },
    { -3, 91, 0, 0, 1, 0, 3, 0, 0, 9, 38515 },
    { -5, 92, 0, 0, 1, 0, 2, 0, 0, 0, 38516 },
    { -5, 92, 0, 0, 1, 0, 2, 0, 0, 11, 38517 },
    { -3, 91, 0, 0, 1, 0, 2, 0, 0, 0, 38518 },
    { -3, 91, 0, 0, 1, 0, 2, 0, 0, 13, 38520 },
    { -4, 91, 0, 0, 1, 0, 2, 0, 0, 0, 38522 },
    { -4, 91, 0, 0, 1, 0, 2, 0, 0, 15, 38538 },
    { -4, 91, 0, 0, 1, 0, 2, 0, 0, 0, 38539 },
    { -4, 91, 0, 0, 1, 0, 3, 0, 0, 0, 38540 },
    { -4, 91, 0, 0, 1, 0, 3, 0, 0, 0, 38508 },
    { -4, 91, 0, 0, 1, 0, 4, 0, 0, 0, 38509 },
    { -4, 91, 0, 0, 1, 0, 4, 0, 0, 0, 38510 },
    { -4, 91, 0, 0, 1, 0, 5, 0, 0, 0, 38511 },
    { -4, 91, 0, 0, 1, 0, 6, 0, 0, 22, 38512 },
    { 20, -8, 0, 0, 2, 0, 255, 0, 0, 23, 11516 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 11518 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 11519 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 11520 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 11522 },
    { -98, 70, 0, 3, 2, 0, 255, 0, 0, 28, 11693 },
    { -98, 70, 0, 3, 2, 0, 255, 0, 0, 29, 11694 },
    { -98, 70, 0, 3, 2, 0, 255, 0, 0, 30, 11695 },
    { -98, 70, 0, 3, 2, 0, 255, 0, 0, 31, 11696 },
    { -98, 70, 0, 3, 2, 0, 255, 0, 0, 32, 11697 },
    { 0, 3, 0, 3, 1, 0, 255, 0, 0, 33, 11715 },
    { 0, 3, 0, 3, 2, 0, 255, 0, 0, 34, 11716 },
    { -97, 66, 0, 3, 2, 0, 255, 0, 0, 35, 11698 },
    { -97, 66, 0, 3, 2, 0, 255, 0, 0, 36, 11699 },
    { -97, 66, 0, 3, 2, 0, 255, 0, 0, 37, 11700 },
    { -97, 66, 0, 3, 2, 0, 255, 0, 0, 38, 11701 },
    { -96, 82, 0, 3, 2, 0, 255, 0, 0, 39, 11702 },
    { -96, 82, 0, 3, 2, 0, 255, 0, 0, 40, 11703 },
    { -96, 82, 0, 3, 2, 0, 255, 0, 0, 41, 11704 },
    { -96, 82, 0, 3, 2, 0, 255, 0, 0, 42, 11705 },
    { -96, 82, 0, 3, 2, 0, 255, 0, 0, 43, 11706 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 44, 11707 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 45, 11708 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 46, 11709 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 47, 11710 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 48, 11711 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 49, 11712 },
    { -80, 75, 0, 3, 2, 0, 255, 0, 0, 50, 11713 },
    { -80, 91, 0, 3, 2, 0, 255, 0, 0, 51, 11714 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 52, 11719 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 53, 11720 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 54, 11721 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 55, 11722 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 56, 11723 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 57, 11724 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 58, 11725 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 59, 11726 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 60, 11727 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 61, 11728 },
    { -96, 68, 0, 3, 1, 0, 1, 0, 0, 0, 11743 },
    { -98, 68, 0, 3, 2, 0, 1, 0, 0, 0, 11744 },
    { -100, 68, 0, 3, 2, 0, 2, 0, 0, 0, 11745 },
    { -104, 68, 0, 3, 2, 0, 2, 0, 0, 0, 11746 },
    { -108, 68, 0, 3, 2, 0, 3, 0, 0, 0, 11747 },
    { -114, 68, 0, 3, 2, 0, 4, 0, 0, 0, 11748 },
    { -122, 68, 0, 3, 2, 0, 4, 0, 0, 0, 11749 },
    { -134, 68, 0, 3, 2, 0, 5, 0, 0, 0, 11750 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 70, 0 },
    { -102, -5, 0, 3, 1, 0, 1, 0, 0, 0, 11743 },
    { -102, -5, 0, 3, 1, 0, 1, 0, 0, 0, 11744 },
    { -102, -5, 0, 3, 2, 0, 2, 0, 0, 0, 11745 },
    { -102, -5, 0, 3, 2, 0, 2, 0, 0, 0, 11746 },
    { -102, -5, 0, 3, 2, 0, 3, 0, 0, 0, 11747 },
    { -102, -5, 0, 3, 2, 0, 4, 0, 0, 0, 11748 },
    { -102, -5, 0, 3, 2, 0, 4, 0, 0, 0, 11749 },
    { -102, -5, 0, 3, 2, 0, 5, 0, 0, 0, 11750 },
    { 0, 0, 0, 3, 2, 0, 255, 0, 0, 70, 0 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 80, 40048 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 81, 40049 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 82, 40050 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 83, 40051 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 84, 40052 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 85, 40053 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 86, 40054 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 87, 40055 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 88, 40056 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 89, 40057 },
    { -126, 60, 0, 3, 2, 0, 255, 0, 0, 90, 40058 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 91, 40048 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 92, 40049 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 93, 40050 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 94, 40051 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 95, 40052 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 96, 40053 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 97, 40054 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 98, 40055 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 99, 40056 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 100, 40057 },
    { -126, 60, 0, 3, 1, 0, 255, 0, 0, 101, 40058 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 102, 38579 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 103, 38580 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 104, 38581 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 105, 38582 },
    { -2, 87, 0, 0, 1, 0, 255, 0, 0, 106, 38581 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 107, 38578 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 108, 38579 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 109, 38581 },
    { -2, 91, 0, 0, 1, 0, 255, 0, 0, 110, 38582 },
    { -2, 92, 0, 0, 1, 0, 255, 0, 0, 111, 38583 },
    { -2, 91, 0, 0, 1, 0, 255, 0, 0, 112, 38584 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 113, 38576 },
    { -2, 87, 0, 0, 1, 0, 255, 0, 0, 114, 38577 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 115, 38578 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 116, 38581 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 117, 38581 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 118, 38580 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 119, 38579 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 120, 38579 },
    { -2, 87, 0, 0, 1, 0, 255, 0, 0, 121, 38579 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 122, 38578 },
    { -2, 91, 0, 0, 1, 0, 255, 0, 0, 123, 38577 },
    { -2, 92, 0, 0, 1, 0, 255, 0, 0, 124, 38583 },
    { -2, 91, 0, 0, 1, 0, 255, 0, 0, 125, 38584 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 126, 38584 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 127, 38565 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 128, 38512 },
    { -2, 87, 0, 0, 1, 0, 255, 0, 0, 129, 38583 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 130, 38582 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 131, 38581 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 132, 38580 },
    { -2, 86, 0, 0, 1, 0, 255, 0, 0, 133, 38580 },
    { -6, 91, 0, 0, 1, 0, 255, 0, 0, 134, 38509 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 135, 38510 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 136, 38511 },
    { -11, 77, 0, 0, 1, 0, 255, 0, 0, 137, 38578 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 138, 38513 },
    { -9, 89, 0, 0, 1, 0, 255, 0, 0, 139, 38603 },
    { -8, 91, 0, 0, 1, 0, 255, 0, 0, 140, 38602 },
    { -7, 90, 0, 0, 1, 0, 255, 0, 0, 141, 38601 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 142, 38600 },
    { 0, 86, 0, 0, 1, 0, 255, 0, 0, 143, 38569 },
    { -1, 76, 0, 0, 1, 0, 255, 0, 0, 144, 38568 },
    { -10, 74, 0, 0, 1, 0, 255, 0, 0, 145, 38569 },
    { -11, 75, 0, 0, 1, 0, 255, 0, 0, 146, 38570 },
    { -8, 78, 0, 0, 1, 0, 255, 0, 0, 147, 38571 },
    { -5, 81, 0, 0, 1, 0, 255, 0, 0, 148, 38572 },
    { -4, 83, 0, 0, 1, 0, 255, 0, 0, 149, 38573 },
    { -4, 86, 0, 0, 1, 0, 255, 0, 0, 150, 38574 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 151, 38575 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 152, 38576 },
    { -2, 89, 0, 0, 1, 0, 2, 0, 0, 0, 38577 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 154, 38578 },
    { 0, 103, 0, 0, 1, 0, 255, 0, 0, 155, 38523 },
    { -8, 105, 0, 0, 1, 0, 255, 0, 0, 156, 38524 },
    { -10, 107, 0, 0, 1, 0, 255, 0, 0, 157, 38525 },
    { -10, 107, 0, 0, 1, 0, 255, 0, 0, 158, 38526 },
    { -10, 104, 0, 0, 1, 0, 255, 0, 0, 159, 38527 },
    { -10, 102, 0, 0, 1, 0, 255, 0, 0, 160, 38528 },
    { -10, 101, 0, 0, 1, 0, 255, 0, 0, 161, 38529 },
    { -10, 99, 0, 0, 1, 0, 255, 0, 0, 162, 38530 },
    { -13, 98, 0, 0, 1, 0, 255, 0, 0, 163, 38535 },
    { -15, 97, 0, 0, 1, 0, 255, 0, 0, 164, 38536 },
    { -18, 97, 0, 0, 1, 0, 255, 0, 0, 165, 38537 },
    { -19, 97, 0, 0, 1, 0, 255, 0, 0, 166, 38538 },
    { -19, 97, 0, 0, 1, 0, 255, 0, 0, 167, 38539 },
    { -8, 75, 0, 0, 1, 0, 255, 0, 0, 168, 38536 },
    { -11, 55, 0, 0, 1, 0, 255, 0, 0, 169, 38537 },
    { -11, 56, 0, 0, 1, 0, 255, 0, 0, 170, 38538 },
    { -13, 59, 0, 0, 1, 0, 255, 0, 0, 171, 38540 },
    { -13, 80, 0, 0, 1, 0, 255, 0, 0, 172, 38508 },
    { -9, 93, 0, 0, 1, 0, 255, 0, 0, 173, 38507 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 174, 38506 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 175, 38505 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 176, 38565 },
    { -7, 73, 0, 0, 1, 0, 255, 0, 0, 177, 38566 },
    { -11, 52, 0, 0, 1, 0, 255, 0, 0, 178, 38567 },
    { -8, 53, 0, 0, 1, 0, 255, 0, 0, 179, 38568 },
    { -6, 56, 0, 0, 1, 0, 255, 0, 0, 180, 38569 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 181, 38570 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 182, 38571 },
    { -9, 56, 0, 0, 1, 0, 255, 0, 0, 183, 38572 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 184, 38573 },
    { -6, 56, 0, 0, 1, 0, 1, 0, 0, 0, 38574 },
    { -6, 56, 0, 0, 1, 0, 1, 0, 0, 0, 38575 },
    { -6, 56, 0, 0, 1, 0, 255, 0, 0, 187, 38577 },
    { -12, 56, 0, 0, 1, 0, 255, 0, 0, 188, 38580 },
    { -11, 77, 0, 0, 1, 0, 255, 0, 0, 189, 38581 },
    { -6, 91, 0, 0, 1, 0, 255, 0, 0, 190, 38582 },
    { 0, 93, 0, 0, 1, 0, 255, 0, 0, 191, 38564 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 192, 38576 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 193, 38512 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 194, 38512 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 195, 38512 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 196, 38512 },
    { -4, 90, 0, 0, 1, 0, 255, 0, 0, 197, 38565 },
    { -5, 92, 0, 0, 1, 0, 255, 0, 0, 198, 38512 },
    { -1, 92, 0, 0, 1, 0, 255, 0, 0, 199, 38564 },
    { -4, 89, 0, 0, 1, 0, 255, 0, 0, 200, 38565 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 201, 38512 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 202, 38512 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 203, 38511 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 204, 38511 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 205, 38511 },
    { -1, 91, 0, 0, 1, 0, 255, 0, 0, 206, 38564 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 207, 38512 },
    { -4, 89, 0, 0, 1, 0, 255, 0, 0, 208, 38565 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 209, 38565 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 210, 38565 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 211, 38512 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 212, 38512 },
    { 0, 91, 0, 0, 1, 0, 255, 0, 0, 213, 38564 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 214, 38584 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 215, 38512 },
    { -8, 57, 0, 0, 1, 0, 255, 0, 0, 216, 38565 },
    { -9, 57, 0, 0, 1, 0, 255, 0, 0, 217, 38565 },
    { -10, 55, 0, 0, 1, 0, 255, 0, 0, 218, 38565 },
    { -10, 56, 0, 0, 1, 0, 255, 0, 0, 219, 38565 },
    { -10, 57, 0, 0, 1, 0, 255, 0, 0, 220, 38565 },
    { -9, 57, 0, 0, 1, 0, 255, 0, 0, 221, 38565 },
    { -8, 55, 0, 0, 1, 0, 255, 0, 0, 222, 38565 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 223, 38565 },
    { 0, 61, 0, 0, 1, 0, 255, 0, 0, 224, 38558 },
    { -6, 62, 0, 0, 1, 0, 255, 0, 0, 225, 38560 },
    { -8, 60, 0, 0, 1, 0, 255, 0, 0, 226, 38561 },
    { -9, 60, 0, 0, 1, 0, 255, 0, 0, 227, 38562 },
    { -7, 60, 0, 0, 1, 0, 255, 0, 0, 228, 38564 },
    { -8, 58, 0, 0, 1, 0, 255, 0, 0, 229, 38565 },
    { -9, 57, 0, 0, 1, 0, 255, 0, 0, 230, 38565 },
    { -12, 57, 0, 0, 1, 0, 255, 0, 0, 231, 38566 },
    { -15, 37, 0, 0, 1, 0, 255, 0, 0, 232, 38567 },
    { 4, 99, 0, 0, 1, 2, 255, 0, 0, 233, 38586 },
    { 2, 101, 0, 0, 1, 0, 255, 0, 0, 234, 38584 },
    { 0, 104, 0, 0, 1, 0, 255, 0, 0, 235, 38565 },
    { 0, 106, 0, 0, 1, 0, 255, 0, 0, 236, 38522 },
    { -5, 100, 0, 0, 1, 0, 255, 0, 0, 237, 38521 },
    { 5, 97, 0, 0, 1, 0, 255, 0, 0, 238, 38520 },
    { 15, 95, 0, 0, 1, 0, 255, 0, 0, 239, 38519 },
    { 23, 84, 0, 0, 1, 0, 255, 0, 0, 240, 38517 },
    { 31, 64, 0, 0, 1, 2, 255, 0, 0, 241, 38560 },
    { 23, 59, 0, 0, 1, 2, 255, 0, 0, 242, 38537 },
    { 25, 55, 0, 0, 1, 2, 255, 0, 0, 243, 38575 },
    { 10, 45, 0, 0, 1, 2, 255, 0, 0, 244, 38566 },
    { -7, 44, 0, 0, 1, 2, 255, 0, 0, 245, 38566 },
    { -11, 40, 0, 0, 1, 1, 255, 0, 0, 246, 38541 },
    { -22, 46, 0, 0, 1, 1, 255, 0, 0, 247, 38538 },
    { -31, 53, 0, 0, 1, 1, 255, 0, 0, 248, 38563 },
    { -41, 65, 0, 0, 1, 3, 255, 0, 0, 249, 38586 },
    { -33, 79, 0, 0, 1, 3, 255, 0, 0, 250, 38587 },
    { -28, 84, 0, 0, 1, 3, 255, 0, 0, 251, 38588 },
    { -8, 98, 0, 0, 2, 1, 255, 0, 0, 252, 38566 },
    { 5, 102, 0, 0, 1, 1, 255, 0, 0, 253, 38567 },
    { -1, 105, 0, 0, 1, 0, 255, 0, 0, 254, 38585 },
    { -3, 100, 0, 0, 1, 0, 255, 0, 0, 255, 38586 },
    { 4, 97, 0, 0, 1, 0, 255, 0, 0, 256, 38614 },
    { -20, 43, 0, 0, 1, 0, 255, 0, 0, 257, 38586 },
    { -16, 39, 0, 0, 1, 0, 255, 0, 0, 258, 38591 },
    { -19, 57, 0, 0, 1, 0, 255, 0, 0, 259, 38592 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 260, 38595 },
    { -6, 88, 0, 0, 1, 0, 255, 0, 0, 261, 38597 },
    { -8, 94, 0, 0, 1, 0, 255, 0, 0, 262, 38599 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 263, 38580 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 264, 38582 },
    { -2, 101, 0, 0, 1, 2, 255, 0, 0, 265, 38590 },
    { 0, 102, 0, 0, 1, 0, 255, 0, 0, 266, 38508 },
    { -5, 100, 0, 0, 1, 0, 255, 0, 0, 267, 38508 },
    { -9, 96, 0, 0, 1, 0, 255, 0, 0, 268, 38508 },
    { -10, 96, 0, 0, 1, 0, 255, 0, 0, 269, 38507 },
    { -13, 93, 0, 0, 1, 0, 255, 0, 0, 270, 38507 },
    { -12, 95, 0, 0, 1, 0, 255, 0, 0, 271, 38506 },
    { -11, 92, 0, 0, 1, 2, 255, 0, 0, 272, 38588 },
    { -12, 94, 0, 0, 1, 0, 255, 0, 0, 273, 38566 },
    { -5, 96, 0, 0, 1, 0, 255, 0, 0, 274, 38568 },
    { -7, 99, 0, 0, 1, 0, 255, 0, 0, 275, 38586 },
    { -5, 101, 0, 0, 1, 0, 255, 0, 0, 276, 38590 },
    { 2, 98, 0, 0, 1, 0, 255, 0, 0, 277, 38612 },
    { 2, 98, 0, 0, 1, 0, 255, 0, 0, 278, 38613 },
    { 2, 98, 0, 0, 1, 0, 255, 0, 0, 279, 38614 },
    { -18, 43, 0, 0, 1, 0, 255, 0, 0, 280, 38590 },
    { -17, 39, 0, 0, 1, 0, 255, 0, 0, 281, 38591 },
    { -20, 57, 0, 0, 1, 0, 255, 0, 0, 282, 38593 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 283, 38597 },
    { -6, 88, 0, 0, 2, 0, 255, 0, 0, 284, 38599 },
    { -8, 93, 0, 0, 1, 0, 255, 0, 0, 285, 38508 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 286, 38507 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 287, 38506 },
    { -3, 102, 0, 0, 1, 0, 255, 0, 0, 288, 38508 },
    { -2, 101, 0, 0, 1, 0, 255, 0, 0, 289, 38507 },
    { -5, 101, 0, 0, 1, 0, 255, 0, 0, 290, 38506 },
    { -9, 96, 0, 0, 1, 0, 255, 0, 0, 291, 38505 },
    { 5, 97, 0, 0, 1, 0, 255, 0, 0, 292, 38503 },
    { 15, 94, 0, 0, 1, 0, 255, 0, 0, 293, 38501 },
    { 24, 84, 0, 0, 1, 0, 255, 0, 0, 294, 38500 },
    { 21, 66, 0, 0, 1, 0, 255, 0, 0, 295, 38514 },
    { 29, 61, 0, 0, 1, 2, 255, 0, 0, 296, 38566 },
    { 20, 56, 0, 0, 1, 2, 255, 0, 0, 297, 38566 },
    { 9, 45, 0, 0, 1, 2, 255, 0, 0, 298, 38566 },
    { -3, 43, 0, 0, 1, 2, 255, 0, 0, 299, 38566 },
    { -15, 41, 0, 0, 1, 2, 255, 0, 0, 300, 38567 },
    { -25, 45, 0, 0, 1, 1, 255, 0, 0, 301, 38562 },
    { -30, 53, 0, 0, 1, 1, 255, 0, 0, 302, 38538 },
    { -39, 69, 0, 0, 1, 1, 255, 0, 0, 303, 38540 },
    { -37, 82, 0, 0, 1, 1, 255, 0, 0, 304, 38564 },
    { -31, 86, 0, 0, 1, 1, 255, 0, 0, 305, 38565 },
    { -10, 102, 0, 0, 1, 1, 255, 0, 0, 306, 38548 },
    { -4, 101, 0, 0, 1, 2, 255, 0, 0, 307, 38540 },
    { -1, 101, 0, 0, 1, 2, 255, 0, 0, 308, 38599 },
    { 2, 100, 0, 0, 1, 0, 255, 0, 0, 309, 38612 },
    { 5, 99, 0, 0, 1, 0, 255, 0, 0, 310, 38613 },
    { -17, 44, 0, 0, 1, 0, 255, 0, 0, 311, 38590 },
    { -17, 44, 0, 0, 1, 0, 255, 0, 0, 312, 38591 },
    { -17, 39, 0, 0, 1, 0, 255, 0, 0, 313, 38592 },
    { -16, 39, 0, 0, 1, 0, 255, 0, 0, 314, 38594 },
    { -19, 57, 0, 0, 1, 0, 255, 0, 0, 315, 38596 },
    { -8, 82, 0, 0, 1, 0, 255, 0, 0, 316, 38597 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 317, 38598 },
    { -7, 94, 0, 0, 1, 0, 255, 0, 0, 318, 38599 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 319, 38508 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 320, 38506 },
    { -3, 85, 0, 0, 1, 0, 255, 0, 0, 321, 38507 },
    { 0, 84, 0, 0, 1, 0, 255, 0, 0, 322, 38508 },
    { 0, 84, 0, 0, 1, 0, 255, 0, 0, 323, 38509 },
    { 0, 84, 0, 0, 1, 0, 255, 0, 0, 324, 38510 },
    { -14, 90, 0, 0, 1, 0, 255, 0, 0, 325, 38504 },
    { -11, 91, 0, 0, 1, 0, 255, 0, 0, 326, 38505 },
    { -9, 91, 0, 0, 1, 0, 255, 0, 0, 327, 38506 },
    { -6, 91, 0, 0, 1, 0, 255, 0, 0, 328, 38507 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 329, 38506 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 330, 38511 },
    { -19, 98, 0, 0, 1, 0, 255, 0, 0, 331, 38508 },
    { -19, 99, 0, 0, 1, 0, 255, 0, 0, 332, 38540 },
    { -18, 99, 0, 0, 1, 0, 255, 0, 0, 333, 38539 },
    { -21, 95, 0, 0, 1, 0, 255, 0, 0, 334, 38539 },
    { -7, 104, 0, 0, 1, 0, 255, 0, 0, 335, 38560 },
    { 5, 100, 0, 0, 1, 0, 255, 0, 0, 336, 38526 },
    { 10, 87, 0, 0, 1, 0, 255, 0, 0, 337, 38525 },
    { 10, 91, 0, 0, 1, 0, 255, 0, 0, 338, 38541 },
    { -17, 93, 0, 0, 1, 0, 255, 0, 0, 339, 38529 },
    { -16, 95, 0, 0, 1, 0, 255, 0, 0, 340, 38530 },
    { -17, 99, 0, 0, 1, 0, 255, 0, 0, 341, 38531 },
    { -13, 100, 0, 0, 1, 0, 255, 0, 0, 342, 38532 },
    { -12, 98, 0, 0, 1, 0, 255, 0, 0, 343, 38533 },
    { -8, 100, 0, 0, 1, 0, 255, 0, 0, 344, 38534 },
    { -7, 100, 0, 0, 1, 0, 255, 0, 0, 345, 38535 },
    { -7, 98, 0, 0, 1, 0, 255, 0, 0, 346, 38536 },
    { -1, 60, 0, 0, 1, 0, 255, 0, 0, 347, 38539 },
    { -3, 63, 0, 0, 1, 3, 255, 0, 0, 348, 38549 },
    { -6, 87, 0, 0, 1, 0, 255, 0, 0, 349, 38584 },
    { 2, 86, 0, 0, 1, 0, 255, 0, 0, 350, 38504 },
    { 9, 86, 0, 0, 1, 0, 255, 0, 0, 351, 38503 },
    { 28, 77, 0, 0, 1, 1, 255, 0, 0, 352, 38560 },
    { 39, 76, 0, 0, 1, 1, 255, 0, 0, 353, 38545 },
    { 38, 61, 0, 0, 1, 2, 255, 0, 0, 354, 38562 },
    { 35, 55, 0, 0, 1, 0, 255, 0, 0, 355, 38590 },
    { 32, 48, 0, 0, 1, 0, 255, 0, 0, 356, 38586 },
    { 31, 47, 0, 0, 1, 0, 2, 0, 0, 357, 38496 },
    { 31, 47, 0, 0, 1, 0, 255, 0, 0, 358, 38503 },
    { 33, 44, 0, 0, 1, 0, 255, 0, 0, 359, 38538 },
    { 40, 53, 0, 0, 1, 0, 255, 0, 0, 360, 38540 },
    { 20, 86, 0, 0, 1, 0, 255, 0, 0, 361, 38512 },
    { 5, 94, 0, 0, 1, 1, 255, 0, 0, 362, 38529 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 363, 38508 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 364, 38509 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 365, 38510 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 366, 38511 },
    { -5, 101, 0, 0, 2, 1, 255, 0, 0, 367, 38560 },
    { -12, 103, 0, 0, 2, 1, 255, 0, 0, 368, 38560 },
    { 0, 89, 0, 0, 1, 1, 255, 0, 0, 369, 38566 },
    { 10, 94, 0, 0, 1, 2, 255, 0, 0, 370, 38557 },
    { 16, 95, 0, 0, 1, 1, 255, 0, 0, 371, 38548 },
    { 17, 91, 0, 0, 1, 1, 255, 0, 0, 372, 38567 },
    { 4, 102, 0, 0, 1, 1, 255, 0, 0, 373, 38568 },
    { 7, 100, 0, 0, 1, 1, 255, 0, 0, 374, 38569 },
    { 18, 98, 0, 0, 1, 1, 255, 0, 0, 375, 38571 },
    { 19, 98, 0, 0, 1, 1, 1, 0, 0, 376, 38572 },
    { -18, 96, 0, 0, 1, 1, 1, 0, 0, 377, 38574 },
    { 17, 97, 0, 0, 1, 1, 1, 0, 0, 378, 38575 },
    { -17, 97, 0, 0, 1, 1, 255, 0, 0, 379, 38576 },
    { 18, 97, 0, 0, 1, 1, 2, 0, 0, 380, 38578 },
    { 18, 97, 0, 0, 1, 1, 2, 0, 0, 381, 38577 },
    { -18, 97, 0, 0, 1, 1, 255, 0, 0, 382, 38578 },
    { 14, 102, 0, 0, 1, 0, 255, 0, 0, 383, 38560 },
    { 14, 101, 0, 0, 1, 0, 255, 0, 0, 384, 38560 },
    { -18, 95, 0, 0, 1, 1, 255, 0, 0, 385, 38563 },
    { -20, 92, 0, 0, 1, 3, 255, 0, 0, 386, 38545 },
    { -10, 102, 0, 0, 2, 0, 255, 0, 0, 387, 38541 },
    { -10, 101, 0, 0, 2, 0, 255, 0, 0, 388, 38542 },
    { -6, 104, 0, 0, 1, 0, 255, 0, 0, 389, 38546 },
    { -1, 101, 0, 0, 1, 3, 255, 0, 0, 390, 38557 },
    { 0, 99, 0, 0, 1, 0, 255, 0, 0, 391, 38566 },
    { 1, 97, 0, 0, 1, 0, 255, 0, 0, 392, 38567 },
    { 6, 97, 0, 0, 1, 0, 2, 0, 0, 393, 38612 },
    { 6, 97, 0, 0, 1, 0, 2, 0, 0, 394, 38613 },
    { 6, 97, 0, 0, 1, 0, 2, 0, 0, 395, 38614 },
    { 6, 97, 0, 0, 1, 0, 255, 0, 0, 396, 38615 },
    { -9, 74, 0, 0, 1, 0, 255, 0, 0, 397, 38590 },
    { -12, 55, 0, 0, 1, 0, 255, 0, 0, 398, 38591 },
    { -10, 55, 0, 0, 1, 0, 255, 0, 0, 399, 38592 },
    { -13, 58, 0, 0, 1, 0, 255, 0, 0, 400, 38593 },
    { -13, 58, 0, 0, 1, 0, 255, 0, 0, 401, 38594 },
    { -12, 80, 0, 0, 1, 0, 255, 0, 0, 402, 38596 },
    { -7, 94, 0, 0, 1, 0, 255, 0, 0, 403, 38599 },
    { -2, 91, 0, 0, 1, 0, 255, 0, 0, 404, 38580 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 405, 38581 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 406, 38512 },
    { -14, 85, 0, 0, 1, 0, 255, 0, 0, 407, 38575 },
    { -17, 87, 0, 0, 2, 0, 255, 0, 0, 408, 38519 },
    { -17, 87, 0, 0, 2, 0, 255, 0, 0, 409, 38520 },
    { -19, 86, 0, 0, 2, 0, 1, 0, 0, 410, 38522 },
    { -19, 86, 0, 0, 2, 0, 255, 0, 0, 411, 38540 },
    { -13, 86, 0, 0, 2, 0, 255, 0, 0, 412, 38539 },
    { -13, 87, 0, 0, 2, 0, 255, 0, 0, 413, 38540 },
    { -8, 89, 0, 0, 2, 0, 255, 0, 0, 414, 38508 },
    { -7, 90, 0, 0, 2, 0, 255, 0, 0, 415, 38509 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 416, 38506 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 417, 38510 },
    { -3, 91, 0, 0, 1, 0, 255, 0, 0, 418, 38511 },
    { -14, 86, 0, 0, 1, 0, 255, 0, 0, 419, 38565 },
    { -11, 89, 0, 0, 1, 0, 255, 0, 0, 420, 38564 },
    { -15, 86, 0, 0, 1, 0, 255, 0, 0, 421, 38576 },
    { -18, 89, 0, 0, 1, 0, 1, 0, 0, 422, 38522 },
    { -18, 89, 0, 0, 1, 0, 255, 0, 0, 423, 38523 },
    { -18, 89, 0, 0, 1, 0, 255, 0, 0, 424, 38524 },
    { -14, 90, 0, 0, 1, 0, 255, 0, 0, 425, 38540 },
    { -11, 91, 0, 0, 1, 0, 255, 0, 0, 426, 38540 },
    { -9, 91, 0, 0, 1, 0, 255, 0, 0, 427, 38540 },
    { -6, 91, 0, 0, 1, 0, 255, 0, 0, 428, 38508 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 429, 38509 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 430, 38510 },
    { -6, 87, 0, 0, 1, 0, 255, 0, 0, 431, 38577 },
    { -8, 82, 0, 0, 1, 0, 255, 0, 0, 432, 38576 },
    { -19, 78, 0, 0, 1, 0, 255, 0, 0, 433, 38575 },
    { -12, 84, 0, 0, 1, 0, 255, 0, 0, 434, 38576 },
    { -17, 83, 0, 0, 1, 0, 255, 0, 0, 435, 38578 },
    { -5, 79, 0, 0, 1, 0, 255, 0, 0, 436, 38560 },
    { -12, 82, 0, 0, 1, 0, 255, 0, 0, 437, 38564 },
    { -10, 82, 0, 0, 1, 0, 2, 0, 0, 438, 38539 },
    { -10, 82, 0, 0, 1, 0, 255, 0, 0, 439, 38540 },
    { -10, 82, 0, 0, 1, 0, 1, 0, 0, 440, 38504 },
    { -22, 83, 0, 0, 1, 0, 255, 0, 0, 441, 38580 },
    { -16, 83, 0, 0, 1, 0, 255, 0, 0, 442, 38508 },
    { -8, 83, 0, 0, 1, 0, 255, 0, 0, 443, 38508 },
    { -3, 91, 0, 0, 1, 0, 255, 0, 0, 444, 38508 },
    { 0, 90, 0, 0, 1, 0, 255, 0, 0, 445, 38508 },
    { -3, 89, 0, 0, 1, 0, 255, 0, 0, 446, 38508 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 447, 38509 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 448, 38510 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 449, 38506 },
    { -4, 89, 0, 0, 1, 0, 255, 0, 0, 450, 38565 },
    { -7, 88, 0, 0, 1, 0, 255, 0, 0, 451, 38514 },
    { -16, 88, 0, 0, 1, 0, 255, 0, 0, 452, 38513 },
    { -17, 87, 0, 0, 2, 0, 255, 0, 0, 453, 38516 },
    { -17, 87, 0, 0, 2, 0, 255, 0, 0, 454, 38517 },
    { -18, 86, 0, 0, 2, 0, 1, 0, 0, 455, 38518 },
    { -18, 86, 0, 0, 2, 0, 255, 0, 0, 456, 38519 },
    { -17, 86, 0, 0, 2, 0, 1, 0, 0, 457, 38520 },
    { -17, 86, 0, 0, 2, 0, 255, 0, 0, 458, 38521 },
    { -16, 86, 0, 0, 2, 0, 255, 0, 0, 459, 38522 },
    { -13, 87, 0, 0, 2, 0, 255, 0, 0, 460, 38523 },
    { -6, 86, 0, 0, 2, 0, 255, 0, 0, 461, 38580 },
    { -5, 87, 0, 0, 2, 0, 255, 0, 0, 462, 38579 },
    { -3, 88, 0, 0, 2, 0, 255, 0, 0, 463, 38578 },
    { -4, 91, 0, 0, 2, 0, 255, 0, 0, 464, 38509 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 465, 38510 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 466, 38505 },
    { 3, 90, 0, 0, 1, 1, 255, 0, 0, 467, 38560 },
    { -3, 91, 0, 0, 1, 1, 255, 0, 0, 468, 38559 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 469, 38578 },
    { -6, 93, 0, 0, 1, 0, 255, 0, 0, 470, 38540 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 471, 38508 },
    { -13, 88, 0, 0, 1, 0, 255, 0, 0, 472, 38506 },
    { -15, 85, 0, 0, 1, 0, 255, 0, 0, 473, 38539 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 474, 38512 },
    { -8, 85, 0, 0, 1, 0, 255, 0, 0, 475, 38565 },
    { -8, 82, 0, 0, 1, 0, 255, 0, 0, 476, 38566 },
    { -18, 79, 0, 0, 1, 0, 255, 0, 0, 477, 38497 },
    { -21, 77, 0, 0, 2, 0, 1, 0, 0, 478, 38498 },
    { -21, 77, 0, 0, 2, 0, 255, 0, 0, 479, 38499 },
    { -20, 76, 0, 0, 2, 0, 2, 0, 0, 480, 38500 },
    { -20, 76, 0, 0, 2, 0, 255, 0, 0, 481, 38501 },
    { -21, 78, 0, 0, 2, 0, 255, 0, 0, 482, 38502 },
    { -18, 84, 0, 0, 2, 0, 255, 0, 0, 483, 38503 },
    { -17, 86, 0, 0, 2, 0, 255, 0, 0, 484, 38504 },
    { -7, 91, 0, 0, 1, 0, 255, 0, 0, 485, 38508 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 486, 38509 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 487, 38510 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 488, 38511 },
    { -1, 93, 0, 0, 1, 1, 255, 0, 0, 489, 38561 },
    { -8, 91, 0, 0, 1, 1, 255, 0, 0, 490, 38562 },
    { -10, 87, 0, 0, 1, 1, 255, 0, 0, 491, 38580 },
    { -13, 86, 0, 0, 1, 1, 255, 0, 0, 492, 38581 },
    { -7, 89, 0, 0, 2, 0, 255, 0, 0, 493, 38559 },
    { -9, 91, 0, 0, 2, 0, 255, 0, 0, 494, 38560 },
    { -9, 86, 0, 0, 2, 0, 255, 0, 0, 495, 38561 },
    { 5, 85, 0, 0, 2, 1, 255, 0, 0, 496, 38560 },
    { -11, 75, 0, 0, 2, 0, 255, 0, 0, 497, 38575 },
    { -10, 77, 0, 0, 2, 0, 255, 0, 0, 498, 38566 },
    { -9, 76, 0, 0, 2, 0, 255, 0, 0, 499, 38568 },
    { -9, 76, 0, 0, 2, 0, 2, 0, 0, 500, 38569 },
    { -7, 76, 0, 0, 2, 0, 255, 0, 0, 501, 38570 },
    { -10, 76, 0, 0, 2, 0, 2, 0, 0, 502, 38571 },
    { -9, 76, 0, 0, 2, 0, 255, 0, 0, 503, 38572 },
    { -12, 76, 0, 0, 2, 0, 255, 0, 0, 504, 38573 },
    { -9, 84, 0, 0, 2, 0, 255, 0, 0, 505, 38575 },
    { -4, 86, 0, 0, 2, 0, 255, 0, 0, 506, 38576 },
    { -10, 86, 0, 0, 1, 0, 255, 0, 0, 507, 38577 },
    { -1, 86, 0, 0, 1, 0, 255, 0, 0, 508, 38578 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 509, 38579 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 510, 38580 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 511, 38578 },
    { -12, 87, 0, 0, 1, 0, 255, 0, 0, 512, 38565 },
    { -24, 82, 0, 0, 1, 0, 255, 0, 0, 513, 38566 },
    { -12, 85, 0, 0, 1, 0, 255, 0, 0, 514, 38570 },
    { -12, 83, 0, 0, 1, 0, 255, 0, 0, 515, 38571 },
    { -12, 82, 0, 0, 1, 0, 2, 0, 0, 516, 38572 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 517, 38573 },
    { -9, 83, 0, 0, 1, 0, 2, 0, 0, 518, 38574 },
    { -9, 83, 0, 0, 1, 0, 255, 0, 0, 519, 38575 },
    { -4, 85, 0, 0, 1, 0, 2, 0, 0, 520, 38576 },
    { -4, 85, 0, 0, 1, 0, 255, 0, 0, 521, 38577 },
    { -6, 86, 0, 0, 1, 0, 1, 0, 0, 522, 38578 },
    { -6, 86, 0, 0, 1, 0, 255, 0, 0, 523, 38579 },
    { -9, 88, 0, 0, 1, 0, 1, 0, 0, 524, 38580 },
    { -9, 88, 0, 0, 1, 0, 255, 0, 0, 525, 38580 },
    { -3, 88, 0, 0, 1, 0, 1, 0, 0, 526, 38580 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 527, 38580 },
    { -2, 88, 0, 0, 1, 0, 1, 0, 0, 528, 38580 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 529, 38581 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 530, 38583 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 531, 38584 },
    { -8, 89, 0, 0, 1, 0, 255, 0, 0, 532, 38565 },
    { 0, 95, 0, 0, 1, 0, 255, 0, 0, 533, 38576 },
    { -1, 96, 0, 0, 1, 0, 255, 0, 0, 534, 38566 },
    { 0, 92, 0, 0, 1, 0, 255, 0, 0, 535, 38569 },
    { 0, 93, 0, 0, 1, 0, 255, 0, 0, 536, 38570 },
    { 0, 93, 0, 0, 1, 0, 2, 0, 0, 537, 38571 },
    { 0, 93, 0, 0, 1, 0, 255, 0, 0, 538, 38572 },
    { 1, 90, 0, 0, 1, 0, 255, 0, 0, 539, 38573 },
    { 0, 83, 0, 0, 1, 0, 255, 0, 0, 540, 38575 },
    { -10, 83, 0, 0, 1, 0, 255, 0, 0, 541, 38576 },
    { -5, 87, 0, 0, 1, 0, 255, 0, 0, 542, 38577 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 543, 38578 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 544, 38579 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 545, 38580 },
    { -32, 75, 0, 0, 2, 0, 255, 0, 0, 546, 38578 },
    { -33, 75, 0, 0, 2, 0, 255, 0, 0, 547, 38579 },
    { -23, 73, 0, 0, 2, 0, 255, 0, 0, 548, 38578 },
    { -22, 73, 0, 0, 2, 0, 255, 0, 0, 549, 38578 },
    { -22, 74, 0, 0, 2, 0, 255, 0, 0, 550, 38578 },
    { -22, 73, 0, 0, 2, 0, 255, 0, 0, 551, 38578 },
    { -22, 74, 0, 0, 2, 0, 255, 0, 0, 552, 38578 },
    { -13, 76, 0, 0, 1, 0, 255, 0, 0, 553, 38580 },
    { -9, 84, 0, 0, 1, 0, 255, 0, 0, 554, 38580 },
    { -4, 86, 0, 0, 1, 0, 255, 0, 0, 555, 38580 },
    { -10, 86, 0, 0, 1, 0, 255, 0, 0, 556, 38580 },
    { -1, 86, 0, 0, 1, 0, 255, 0, 0, 557, 38580 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 558, 38580 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 559, 38581 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 560, 38583 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 561, 38539 },
    { 9, 86, 0, 0, 1, 0, 255, 0, 0, 562, 38538 },
    { 7, 84, 0, 0, 1, 0, 255, 0, 0, 563, 38539 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 564, 38540 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 565, 38508 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 566, 38507 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 567, 38509 },
    { 5, 87, 0, 0, 1, 0, 255, 0, 0, 568, 38510 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 569, 38504 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 570, 38505 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 571, 38506 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 572, 38509 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 573, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 574, 38512 },
    { 5, 84, 0, 0, 1, 0, 255, 0, 0, 575, 38539 },
    { 9, 85, 0, 0, 1, 0, 255, 0, 0, 576, 38538 },
    { 7, 83, 0, 0, 1, 0, 255, 0, 0, 577, 38539 },
    { 6, 88, 0, 0, 1, 0, 255, 0, 0, 578, 38540 },
    { 4, 84, 0, 0, 1, 0, 255, 0, 0, 579, 38508 },
    { 5, 84, 0, 0, 1, 0, 255, 0, 0, 580, 38507 },
    { 5, 84, 0, 0, 1, 0, 255, 0, 0, 581, 38509 },
    { 5, 84, 0, 0, 1, 0, 255, 0, 0, 582, 38510 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 583, 38504 },
    { -1, 57, 0, 0, 1, 0, 255, 0, 0, 584, 38508 },
    { 2, 61, 0, 0, 1, 1, 255, 0, 0, 585, 38559 },
    { 4, 59, 0, 0, 1, 0, 255, 0, 0, 586, 38560 },
    { 3, 56, 0, 0, 1, 0, 255, 0, 0, 587, 38561 },
    { -1, 57, 0, 0, 1, 0, 255, 0, 0, 588, 38539 },
    { -1, 57, 0, 0, 1, 0, 255, 0, 0, 589, 38540 },
    { -1, 57, 0, 0, 1, 0, 255, 0, 0, 590, 38508 },
    { -4, 59, 0, 0, 1, 0, 255, 0, 0, 591, 38504 },
    { -6, 59, 0, 0, 1, 0, 255, 0, 0, 592, 38505 },
    { -10, 58, 0, 0, 1, 0, 255, 0, 0, 593, 38507 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 594, 38511 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 595, 38512 },
    { 5, 92, 0, 0, 1, 0, 255, 0, 0, 596, 38508 },
    { 22, 89, 0, 0, 1, 0, 255, 0, 0, 597, 38562 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 598, 38537 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 599, 38538 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 600, 38507 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 601, 38505 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 602, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 603, 38512 },
    { 23, 88, 0, 0, 1, 1, 255, 0, 0, 604, 38562 },
    { 38, 71, 0, 0, 1, 1, 255, 0, 0, 605, 38570 },
    { 31, 78, 0, 0, 1, 1, 255, 0, 0, 606, 38572 },
    { 20, 80, 0, 0, 1, 1, 255, 0, 0, 607, 38574 },
    { 22, 87, 0, 0, 1, 0, 255, 0, 0, 608, 38560 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 609, 38540 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 610, 38509 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 611, 38504 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 612, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 613, 38512 },
    { 31, 81, 0, 0, 2, 1, 255, 0, 0, 614, 38540 },
    { 25, 81, 0, 0, 2, 0, 255, 0, 0, 615, 38558 },
    { 36, 75, 0, 0, 2, 1, 255, 0, 0, 616, 38566 },
    { 37, 70, 0, 0, 2, 1, 255, 0, 0, 617, 38567 },
    { 41, 68, 0, 0, 2, 1, 255, 0, 0, 618, 38571 },
    { 20, 79, 0, 0, 2, 0, 255, 0, 0, 619, 38535 },
    { 18, 80, 0, 0, 2, 0, 255, 0, 0, 620, 38544 },
    { 12, 78, 0, 0, 2, 0, 255, 0, 0, 621, 38515 },
    { -4, 84, 0, 0, 2, 0, 255, 0, 0, 622, 38501 },
    { -10, 82, 0, 0, 2, 0, 255, 0, 0, 623, 38502 },
    { -9, 93, 0, 0, 1, 0, 255, 0, 0, 624, 38508 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 625, 38509 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 626, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 627, 38512 },
    { 9, 87, 0, 0, 1, 0, 255, 0, 0, 628, 38508 },
    { 11, 86, 0, 0, 1, 0, 255, 0, 0, 629, 38540 },
    { 23, 85, 0, 0, 1, 1, 255, 0, 0, 630, 38508 },
    { 31, 78, 0, 0, 1, 3, 255, 0, 0, 631, 38587 },
    { 38, 70, 0, 0, 1, 1, 255, 0, 0, 632, 38568 },
    { 43, 67, 0, 0, 1, 1, 255, 0, 0, 633, 38570 },
    { 49, 62, 0, 0, 2, 1, 255, 0, 0, 634, 38500 },
    { 52, 53, 0, 0, 2, 1, 255, 0, 0, 635, 38502 },
    { 52, 63, 0, 0, 2, 1, 255, 0, 0, 636, 38598 },
    { 47, 63, 0, 0, 2, 1, 255, 0, 0, 637, 38561 },
    { 25, 79, 0, 0, 2, 1, 255, 0, 0, 638, 38580 },
    { 13, 89, 0, 0, 2, 1, 255, 0, 0, 639, 38507 },
    { -7, 94, 0, 0, 1, 0, 255, 0, 0, 640, 38536 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 641, 38539 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 642, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 643, 38512 },
    { 4, 86, 0, 0, 1, 0, 255, 0, 0, 644, 38540 },
    { 25, 81, 0, 0, 2, 0, 255, 0, 0, 645, 38558 },
    { 36, 75, 0, 0, 2, 1, 255, 0, 0, 646, 38566 },
    { 37, 69, 0, 0, 2, 1, 255, 0, 0, 647, 38567 },
    { 47, 66, 0, 0, 2, 1, 255, 0, 0, 648, 38571 },
    { 50, 49, 0, 0, 2, 1, 255, 0, 0, 649, 38573 },
    { 50, 60, 0, 0, 2, 1, 255, 0, 0, 650, 38576 },
    { 51, 63, 0, 0, 2, 1, 255, 0, 0, 651, 38540 },
    { 22, 84, 0, 0, 2, 1, 255, 0, 0, 652, 38561 },
    { 12, 90, 0, 0, 2, 1, 255, 0, 0, 653, 38540 },
    { -7, 94, 0, 0, 1, 0, 255, 0, 0, 654, 38537 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 655, 38521 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 656, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 657, 38512 },
    { 25, 95, 0, 0, 2, 0, 255, 0, 0, 658, 38524 },
    { 28, 72, 0, 0, 1, 1, 255, 0, 0, 659, 38504 },
    { 29, 69, 0, 0, 1, 1, 255, 0, 0, 660, 38522 },
    { 27, 78, 0, 0, 1, 3, 255, 0, 0, 661, 38590 },
    { -32, 61, 0, 0, 2, 0, 255, 0, 0, 662, 38566 },
    { -23, 70, 0, 0, 1, 0, 255, 0, 0, 663, 38569 },
    { -12, 56, 0, 0, 1, 0, 255, 0, 0, 664, 38567 },
    { -7, 89, 0, 0, 1, 0, 255, 0, 0, 665, 38572 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 666, 38575 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 667, 38510 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 668, 38512 },
    { -10, 85, 0, 0, 1, 0, 255, 0, 0, 669, 38566 },
    { -16, 80, 0, 0, 1, 0, 255, 0, 0, 670, 38571 },
    { -12, 87, 0, 0, 1, 0, 255, 0, 0, 671, 38503 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 672, 38505 },
    { 3, 90, 0, 0, 1, 0, 255, 0, 0, 673, 38508 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 674, 38509 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 675, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 676, 38512 },
    { -26, 80, 0, 0, 1, 0, 255, 0, 0, 677, 38566 },
    { -23, 75, 0, 0, 1, 0, 255, 0, 0, 678, 38567 },
    { -29, 71, 0, 0, 1, 0, 255, 0, 0, 679, 38569 },
    { -23, 75, 0, 0, 1, 0, 255, 0, 0, 680, 38571 },
    { -15, 80, 0, 0, 1, 0, 255, 0, 0, 681, 38574 },
    { -10, 84, 0, 0, 1, 0, 255, 0, 0, 682, 38575 },
    { -3, 85, 0, 0, 1, 0, 255, 0, 0, 683, 38577 },
    { 5, 87, 0, 0, 1, 0, 255, 0, 0, 684, 38579 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 685, 38510 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 686, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 687, 38512 },
    { -18, 45, 0, 0, 2, 1, 255, 0, 0, 688, 38585 },
    { -27, 54, 0, 0, 2, 0, 255, 0, 0, 689, 38590 },
    { -18, 45, 0, 0, 2, 1, 255, 0, 0, 690, 38591 },
    { -19, 48, 0, 0, 2, 1, 255, 0, 0, 691, 38592 },
    { -18, 45, 0, 0, 2, 1, 255, 0, 0, 692, 38593 },
    { -19, 48, 0, 0, 2, 1, 255, 0, 0, 693, 38594 },
    { -18, 45, 0, 0, 2, 1, 255, 0, 0, 694, 38595 },
    { -19, 48, 0, 0, 2, 1, 255, 0, 0, 695, 38596 },
    { -12, 47, 0, 0, 2, 1, 255, 0, 0, 696, 38597 },
    { -2, 53, 0, 0, 2, 1, 255, 0, 0, 697, 38580 },
    { 1, 75, 0, 0, 2, 1, 255, 0, 0, 698, 38561 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 699, 38528 },
    { -9, 80, 0, 0, 1, 0, 255, 0, 0, 700, 38545 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 701, 38501 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 702, 38503 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 703, 38508 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 704, 38512 },
    { -28, 77, 0, 0, 1, 0, 255, 0, 0, 705, 38566 },
    { -17, 67, 0, 0, 1, 0, 255, 0, 0, 706, 38550 },
    { -21, 64, 0, 0, 1, 0, 255, 0, 0, 707, 38555 },
    { -13, 65, 0, 0, 1, 1, 255, 0, 0, 708, 38600 },
    { -17, 65, 0, 0, 1, 1, 255, 0, 0, 709, 38601 },
    { -15, 67, 0, 0, 1, 1, 255, 0, 0, 710, 38603 },
    { -19, 45, 0, 0, 1, 1, 255, 0, 0, 711, 38567 },
    { -15, 47, 0, 0, 1, 1, 255, 0, 0, 712, 38571 },
    { -19, 50, 0, 0, 1, 0, 255, 0, 0, 713, 38562 },
    { -18, 51, 0, 0, 1, 0, 255, 0, 0, 714, 38539 },
    { -13, 52, 0, 0, 1, 0, 255, 0, 0, 715, 38508 },
    { -12, 55, 0, 0, 1, 0, 255, 0, 0, 716, 38523 },
    { -13, 59, 0, 0, 1, 0, 255, 0, 0, 717, 38521 },
    { -13, 80, 0, 0, 1, 0, 255, 0, 0, 718, 38599 },
    { -6, 94, 0, 0, 1, 0, 255, 0, 0, 719, 38598 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 720, 38506 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 721, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 722, 38512 },
    { -9, 80, 0, 0, 1, 0, 255, 0, 0, 723, 38566 },
    { -21, 63, 0, 0, 2, 3, 255, 0, 0, 724, 38562 },
    { -14, 66, 0, 0, 1, 1, 255, 0, 0, 725, 38589 },
    { -14, 64, 0, 0, 1, 1, 255, 0, 0, 726, 38571 },
    { -19, 45, 0, 0, 1, 1, 255, 0, 0, 727, 38567 },
    { -15, 47, 0, 0, 1, 1, 255, 0, 0, 728, 38571 },
    { -19, 49, 0, 0, 1, 0, 255, 0, 0, 729, 38562 },
    { -18, 52, 0, 0, 1, 0, 255, 0, 0, 730, 38539 },
    { -13, 52, 0, 0, 1, 0, 255, 0, 0, 731, 38508 },
    { -12, 55, 0, 0, 1, 0, 255, 0, 0, 732, 38523 },
    { -13, 59, 0, 0, 1, 0, 255, 0, 0, 733, 38521 },
    { -13, 80, 0, 0, 1, 0, 255, 0, 0, 734, 38599 },
    { -8, 93, 0, 0, 1, 0, 255, 0, 0, 735, 38505 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 736, 38506 },
    { -4, 92, 0, 0, 1, 0, 2, 0, 0, 737, 38511 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 738, 38512 },
    { -21, 25, 0, 0, 2, 1, 255, 0, 0, 739, 38585 },
    { -20, 22, 0, 0, 2, 3, 255, 0, 0, 740, 38540 },
    { 9, 5, 0, 0, 2, 3, 255, 0, 0, 741, 38565 },
    { 40, 21, 0, 0, 1, 0, 255, 0, 0, 742, 38537 },
    { 35, 19, 0, 0, 1, 3, 255, 0, 0, 743, 38567 },
    { 52, 13, 0, 0, 1, 3, 255, 0, 0, 744, 38571 },
    { 51, 12, 0, 0, 1, 3, 255, 0, 0, 745, 38573 },
    { 57, 1, 0, 0, 1, 3, 255, 0, 0, 746, 38502 },
    { 48, -4, 0, 0, 1, 3, 255, 0, 0, 747, 38520 },
    { 41, -3, 0, 0, 1, 1, 255, 0, 0, 748, 38569 },
    { 51, -2, 0, 0, 1, 1, 255, 0, 0, 749, 38547 },
    { 49, -2, 0, 0, 1, 1, 255, 0, 0, 750, 38548 },
    { 53, -1, 0, 0, 1, 1, 255, 0, 0, 751, 38549 },
    { 47, 1, 0, 0, 1, 1, 255, 0, 0, 752, 38549 },
    { 12, 65, 0, 0, 1, 0, 255, 0, 0, 753, 38540 },
    { 25, 62, 0, 0, 1, 1, 255, 0, 0, 754, 38539 },
    { 26, 67, 0, 0, 1, 0, 255, 0, 0, 755, 38541 },
    { 11, 67, 0, 0, 1, 0, 255, 0, 0, 756, 38537 },
    { -9, 56, 0, 0, 1, 0, 255, 0, 0, 757, 38540 },
    { -8, 59, 0, 0, 1, 0, 255, 0, 0, 758, 38520 },
    { -6, 57, 0, 0, 1, 0, 255, 0, 0, 759, 38576 },
    { -9, 60, 0, 0, 1, 0, 255, 0, 0, 760, 38508 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 761, 38509 },
    { -9, 59, 0, 0, 1, 0, 2, 0, 0, 762, 38511 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 763, 38512 },
    { 20, 63, 0, 0, 1, 0, 255, 0, 0, 764, 38537 },
    { 25, 64, 0, 0, 1, 0, 255, 0, 0, 765, 38545 },
    { -14, 64, 0, 0, 1, 1, 255, 0, 0, 766, 38571 },
    { -19, 45, 0, 0, 1, 1, 255, 0, 0, 767, 38567 },
    { -15, 47, 0, 0, 1, 1, 255, 0, 0, 768, 38571 },
    { -19, 50, 0, 0, 1, 0, 255, 0, 0, 769, 38562 },
    { -19, 52, 0, 0, 1, 0, 255, 0, 0, 770, 38539 },
    { -14, 52, 0, 0, 1, 0, 255, 0, 0, 771, 38508 },
    { -12, 55, 0, 0, 1, 0, 255, 0, 0, 772, 38509 },
    { -8, 59, 0, 0, 1, 0, 255, 0, 0, 773, 38503 },
    { -8, 60, 0, 0, 1, 0, 255, 0, 0, 774, 38505 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 775, 38507 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 776, 38510 },
    { -9, 59, 0, 0, 1, 0, 2, 0, 0, 777, 38511 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 778, 38512 },
    { 44, 8, 0, 0, 1, 3, 255, 0, 0, 779, 38569 },
    { 49, 13, 0, 0, 1, 3, 255, 0, 0, 780, 38549 },
    { 54, 15, 0, 0, 1, 3, 255, 0, 0, 781, 38550 },
    { -3, -7, 0, 0, 1, 1, 255, 0, 0, 782, 38556 },
    { 52, -3, 0, 0, 1, 3, 255, 0, 0, 783, 38549 },
    { 49, 1, 0, 0, 1, 3, 255, 0, 0, 784, 38549 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 785, 38564 },
    { 4, 79, 0, 0, 1, 0, 255, 0, 0, 786, 38565 },
    { 1, 70, 0, 0, 1, 2, 255, 0, 0, 787, 38588 },
    { 4, 66, 0, 0, 1, 0, 255, 0, 0, 788, 38566 },
    { -18, 46, 0, 0, 1, 0, 255, 0, 0, 789, 38567 },
    { -31, 40, 0, 0, 1, 0, 255, 0, 0, 790, 38568 },
    { -31, 39, 0, 0, 1, 0, 255, 0, 0, 791, 38571 },
    { -27, 39, 0, 0, 1, 0, 255, 0, 0, 792, 38573 },
    { -30, 39, 0, 0, 1, 0, 255, 0, 0, 793, 38575 },
    { -14, 49, 0, 0, 1, 0, 255, 0, 0, 794, 38539 },
    { -7, 52, 0, 0, 1, 0, 255, 0, 0, 795, 38538 },
    { 20, 47, 0, 0, 1, 0, 255, 0, 0, 796, 38533 },
    { 51, -1, 0, 0, 1, 3, 255, 0, 0, 797, 38575 },
    { 47, -1, 0, 0, 1, 3, 255, 0, 0, 798, 38572 },
    { 39, -3, 0, 0, 1, 3, 255, 0, 0, 799, 38547 },
    { 45, 1, 0, 0, 1, 3, 255, 0, 0, 800, 38570 },
    { 52, -1, 0, 0, 1, 3, 255, 0, 0, 801, 38569 },
    { 46, -1, 0, 0, 1, 0, 255, 0, 0, 802, 38556 },
    { 52, -3, 0, 0, 1, 3, 255, 0, 0, 803, 38549 },
    { -39, 61, 0, 0, 1, 1, 255, 0, 0, 804, 38508 },
    { -40, 60, 0, 0, 1, 1, 255, 0, 0, 805, 38509 },
    { -40, 61, 0, 0, 1, 1, 255, 0, 0, 806, 38506 },
    { -36, 61, 0, 0, 1, 1, 255, 0, 0, 807, 38505 },
    { -32, 61, 0, 0, 1, 1, 255, 0, 0, 808, 38504 },
    { -24, 65, 0, 0, 1, 1, 255, 0, 0, 809, 38521 },
    { -23, 65, 0, 0, 1, 1, 255, 0, 0, 810, 38505 },
    { -23, 64, 0, 0, 1, 1, 255, 0, 0, 811, 38506 },
    { -30, 62, 0, 0, 1, 1, 255, 0, 0, 812, 38508 },
    { -35, 62, 0, 0, 1, 1, 255, 0, 0, 813, 38540 },
    { 3, 87, 0, 0, 1, 0, 255, 0, 0, 814, 38564 },
    { 4, 79, 0, 0, 1, 0, 255, 0, 0, 815, 38565 },
    { 2, 69, 0, 0, 1, 2, 255, 0, 0, 816, 38588 },
    { 4, 66, 0, 0, 1, 0, 255, 0, 0, 817, 38566 },
    { -17, 46, 0, 0, 1, 0, 255, 0, 0, 818, 38567 },
    { -31, 40, 0, 0, 1, 0, 255, 0, 0, 819, 38568 },
    { -31, 39, 0, 0, 1, 0, 255, 0, 0, 820, 38571 },
    { -27, 39, 0, 0, 1, 0, 255, 0, 0, 821, 38573 },
    { -29, 37, 0, 0, 1, 0, 255, 0, 0, 822, 38575 },
    { -15, 48, 0, 0, 1, 0, 255, 0, 0, 823, 38539 },
    { -6, 53, 0, 0, 1, 0, 255, 0, 0, 824, 38538 },
    { 21, 47, 0, 0, 1, 0, 255, 0, 0, 825, 38533 },
    { 51, -1, 0, 0, 1, 3, 255, 0, 0, 826, 38575 },
    { 47, -1, 0, 0, 1, 3, 255, 0, 0, 827, 38572 },
    { 39, -3, 0, 0, 1, 3, 255, 0, 0, 828, 38547 },
    { 45, 1, 0, 0, 1, 3, 255, 0, 0, 829, 38570 },
    { 52, -1, 0, 0, 1, 3, 255, 0, 0, 830, 38569 },
    { 47, -1, 0, 0, 1, 0, 255, 0, 0, 831, 38556 },
    { 52, -3, 0, 0, 1, 3, 255, 0, 0, 832, 38549 },
    { 48, 1, 0, 0, 1, 3, 255, 0, 0, 833, 38549 },
    { -7, 58, 0, 0, 1, 0, 255, 0, 0, 834, 38565 },
    { -8, 57, 0, 0, 1, 0, 255, 0, 0, 835, 38565 },
    { -8, 57, 0, 0, 1, 0, 255, 0, 0, 836, 38565 },
    { -8, 57, 0, 0, 1, 0, 255, 0, 0, 837, 38565 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 838, 38565 },
    { -7, 58, 0, 0, 1, 0, 255, 0, 0, 839, 38565 },
    { -8, 58, 0, 0, 1, 0, 255, 0, 0, 840, 38565 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 841, 38565 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 842, 38565 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 843, 38565 },
    { -8, 55, 0, 0, 1, 0, 255, 0, 0, 844, 38565 },
    { -10, 55, 0, 0, 1, 0, 255, 0, 0, 845, 38565 },
    { -7, 58, 0, 0, 1, 0, 255, 0, 0, 846, 38565 },
    { -8, 58, 0, 0, 1, 0, 255, 0, 0, 847, 38565 },
    { -9, 56, 0, 0, 1, 0, 255, 0, 0, 848, 38565 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 849, 38565 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 850, 38565 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 851, 38565 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 852, 38565 },
    { -11, 61, 0, 0, 1, 0, 255, 0, 0, 853, 38575 },
    { -11, 64, 0, 0, 1, 0, 255, 0, 0, 854, 38576 },
    { -12, 72, 0, 0, 1, 0, 255, 0, 0, 855, 38576 },
    { -10, 79, 0, 0, 1, 0, 255, 0, 0, 856, 38576 },
    { -11, 80, 0, 0, 1, 0, 255, 0, 0, 857, 38576 },
    { -11, 81, 0, 0, 1, 0, 255, 0, 0, 858, 38576 },
    { -12, 83, 0, 0, 1, 0, 255, 0, 0, 859, 38565 },
    { -10, 82, 0, 0, 1, 0, 255, 0, 0, 860, 38584 },
    { -12, 83, 0, 0, 1, 0, 255, 0, 0, 861, 38565 },
    { -10, 82, 0, 0, 1, 0, 255, 0, 0, 862, 38584 },
    { -12, 83, 0, 0, 1, 0, 255, 0, 0, 863, 38565 },
    { -10, 82, 0, 0, 1, 0, 255, 0, 0, 864, 38584 },
    { -6, 83, 0, 0, 1, 0, 255, 0, 0, 865, 38565 },
    { -4, 77, 0, 0, 1, 0, 255, 0, 0, 866, 38565 },
    { -4, 72, 0, 0, 1, 0, 255, 0, 0, 867, 38584 },
    { -8, 67, 0, 0, 1, 0, 255, 0, 0, 868, 38584 },
    { -7, 57, 0, 0, 1, 0, 255, 0, 0, 869, 38565 },
    { -7, 57, 0, 0, 1, 0, 255, 0, 0, 870, 38565 },
    { -4, 53, 0, 0, 1, 0, 255, 0, 0, 871, 38565 },
    { 5, 47, 0, 0, 1, 0, 255, 0, 0, 872, 38575 },
    { 19, 48, 0, 0, 1, 1, 255, 0, 0, 873, 38560 },
    { 16, 48, 0, 0, 1, 0, 255, 0, 0, 874, 38560 },
    { 14, 48, 0, 0, 1, 0, 255, 0, 0, 875, 38560 },
    { 5, 48, 0, 0, 1, 0, 255, 0, 0, 876, 38527 },
    { 2, 48, 0, 0, 1, 0, 255, 0, 0, 877, 38565 },
    { -1, 55, 0, 0, 1, 0, 255, 0, 0, 878, 38565 },
    { -7, 55, 0, 0, 1, 0, 255, 0, 0, 879, 38565 },
    { -9, 56, 0, 0, 1, 0, 255, 0, 0, 880, 38565 },
    { -8, 56, 0, 0, 1, 0, 255, 0, 0, 881, 38565 },
    { 0, 61, 0, 0, 1, 1, 255, 0, 0, 882, 38561 },
    { 5, 61, 0, 0, 1, 1, 255, 0, 0, 883, 38562 },
    { 10, 60, 0, 0, 1, 1, 255, 0, 0, 884, 38563 },
    { 11, 60, 0, 0, 1, 1, 255, 0, 0, 885, 38537 },
    { 8, 60, 0, 0, 1, 1, 255, 0, 0, 886, 38536 },
    { 8, 58, 0, 0, 1, 1, 255, 0, 0, 887, 38534 },
    { 1, 56, 0, 0, 1, 1, 255, 0, 0, 888, 38533 },
    { -1, 52, 0, 0, 1, 1, 255, 0, 0, 889, 38543 },
    { -2, 49, 0, 0, 1, 2, 255, 0, 0, 890, 38552 },
    { -1, 49, 0, 0, 1, 2, 255, 0, 0, 891, 38553 },
    { 0, 48, 0, 0, 2, 2, 255, 0, 0, 892, 38554 },
    { -7, 55, 0, 0, 2, 1, 255, 0, 0, 893, 38545 },
    { -5, 52, 0, 0, 2, 3, 255, 0, 0, 894, 38549 },
    { -8, 56, 0, 0, 2, 0, 255, 0, 0, 895, 38562 },
    { -6, 56, 0, 0, 1, 0, 255, 0, 0, 896, 38570 },
    { -6, 55, 0, 0, 1, 0, 255, 0, 0, 897, 38572 },
    { -6, 55, 0, 0, 1, 0, 255, 0, 0, 898, 38573 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 899, 38574 },
    { -6, 56, 0, 0, 1, 0, 255, 0, 0, 900, 38575 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 901, 38576 },
    { -7, 56, 0, 0, 1, 0, 255, 0, 0, 902, 38583 },
    { -8, 57, 0, 0, 1, 0, 255, 0, 0, 903, 38565 },
    { 12, 100, 0, 0, 1, 0, 255, 0, 0, 904, 38574 },
    { 0, 101, 0, 0, 1, 0, 255, 0, 0, 905, 38572 },
    { 0, 97, 0, 0, 1, 0, 255, 0, 0, 906, 38567 },
    { 4, 99, 0, 0, 1, 0, 255, 0, 0, 907, 38609 },
    { 4, 99, 0, 0, 1, 0, 255, 0, 0, 908, 38610 },
    { 4, 99, 0, 0, 1, 0, 255, 0, 0, 909, 38611 },
    { 3, 102, 0, 0, 1, 0, 255, 0, 0, 910, 38608 },
    { -3, 104, 0, 0, 1, 0, 255, 0, 0, 911, 38586 },
    { -2, 103, 0, 0, 1, 0, 255, 0, 0, 912, 38585 },
    { -14, 95, 0, 0, 1, 0, 255, 0, 0, 913, 38612 },
    { -3, 96, 0, 0, 1, 0, 255, 0, 0, 914, 38613 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 915, 38614 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 916, 38615 },
    { -10, 99, 0, 0, 1, 0, 255, 0, 0, 917, 38566 },
    { -12, 102, 0, 0, 2, 0, 255, 0, 0, 918, 38517 },
    { -3, 101, 0, 0, 2, 1, 255, 0, 0, 919, 38532 },
    { 4, 99, 0, 0, 2, 1, 255, 0, 0, 920, 38533 },
    { 3, 98, 0, 0, 2, 1, 255, 0, 0, 921, 38531 },
    { -10, 100, 0, 0, 1, 0, 255, 0, 0, 922, 38562 },
    { -13, 99, 0, 0, 1, 0, 255, 0, 0, 923, 38535 },
    { -9, 97, 0, 0, 1, 0, 255, 0, 0, 924, 38569 },
    { -10, 97, 0, 0, 1, 0, 255, 0, 0, 925, 38568 },
    { -13, 97, 0, 0, 1, 0, 255, 0, 0, 926, 38567 },
    { -10, 101, 0, 0, 1, 0, 255, 0, 0, 927, 38588 },
    { -10, 98, 0, 0, 1, 0, 255, 0, 0, 928, 38586 },
    { -11, 97, 0, 0, 1, 0, 255, 0, 0, 929, 38585 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 930, 38614 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 931, 38615 },
    { -7, 96, 0, 0, 1, 0, 255, 0, 0, 932, 38575 },
    { -4, 96, 0, 0, 1, 0, 255, 0, 0, 933, 38571 },
    { -5, 96, 0, 0, 1, 0, 255, 0, 0, 934, 38570 },
    { -5, 96, 0, 0, 1, 0, 255, 0, 0, 935, 38569 },
    { -5, 96, 0, 0, 1, 0, 255, 0, 0, 936, 38568 },
    { -5, 96, 0, 0, 1, 0, 255, 0, 0, 937, 38567 },
    { -7, 99, 0, 0, 1, 0, 255, 0, 0, 938, 38587 },
    { -7, 99, 0, 0, 1, 0, 255, 0, 0, 939, 38586 },
    { -7, 99, 0, 0, 1, 0, 255, 0, 0, 940, 38585 },
    { 1, 99, 0, 0, 1, 0, 255, 0, 0, 941, 38609 },
    { 1, 99, 0, 0, 1, 0, 255, 0, 0, 942, 38610 },
    { 1, 99, 0, 0, 1, 0, 255, 0, 0, 943, 38613 },
    { -2, 98, 0, 0, 1, 0, 255, 0, 0, 944, 38614 },
    { -2, 98, 0, 0, 1, 0, 255, 0, 0, 945, 38615 },
    { 0, 97, 0, 0, 2, 1, 255, 0, 0, 946, 38531 },
    { -2, 96, 0, 0, 2, 1, 255, 0, 0, 947, 38533 },
    { 7, 98, 0, 0, 2, 1, 255, 0, 0, 948, 38528 },
    { 0, 96, 0, 0, 2, 1, 255, 0, 0, 949, 38536 },
    { -4, 97, 0, 0, 1, 0, 255, 0, 0, 950, 38534 },
    { -6, 96, 0, 0, 1, 0, 255, 0, 0, 951, 38536 },
    { 2, 95, 0, 0, 1, 0, 255, 0, 0, 952, 38536 },
    { -2, 98, 0, 0, 1, 0, 255, 0, 0, 953, 38563 },
    { 4, 94, 0, 0, 1, 0, 255, 0, 0, 954, 38572 },
    { 4, 93, 0, 0, 1, 0, 255, 0, 0, 955, 38569 },
    { 1, 96, 0, 0, 1, 0, 255, 0, 0, 956, 38567 },
    { 2, 98, 0, 0, 1, 0, 255, 0, 0, 957, 38586 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 958, 38614 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 959, 38615 },
    { -36, 92, 0, 0, 1, 0, 255, 0, 0, 960, 38515 },
    { -35, 92, 0, 0, 1, 0, 255, 0, 0, 961, 38514 },
    { -32, 91, 0, 0, 1, 0, 255, 0, 0, 962, 38604 },
    { -32, 91, 0, 0, 1, 0, 255, 0, 0, 963, 38605 },
    { -32, 91, 0, 0, 1, 0, 255, 0, 0, 964, 38606 },
    { -32, 91, 0, 0, 1, 0, 255, 0, 0, 965, 38607 },
    { -34, 92, 0, 0, 1, 0, 255, 0, 0, 966, 38569 },
    { -30, 92, 0, 0, 1, 0, 255, 0, 0, 967, 38567 },
    { -13, 97, 0, 0, 1, 0, 255, 0, 0, 968, 38586 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 969, 38610 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 970, 38611 },
    { -12, 94, 0, 0, 1, 0, 255, 0, 0, 971, 38566 },
    { -13, 94, 0, 0, 1, 0, 255, 0, 0, 972, 38567 },
    { -12, 94, 0, 0, 1, 0, 255, 0, 0, 973, 38568 },
    { -15, 94, 0, 0, 1, 0, 255, 0, 0, 974, 38569 },
    { -15, 94, 0, 0, 1, 0, 255, 0, 0, 975, 38571 },
    { -16, 96, 0, 0, 2, 2, 255, 0, 0, 976, 38571 },
    { -14, 95, 0, 0, 1, 0, 255, 0, 0, 977, 38569 },
    { -12, 94, 0, 0, 2, 0, 255, 0, 0, 978, 38568 },
    { -7, 101, 0, 0, 1, 0, 255, 0, 0, 979, 38587 },
    { -8, 96, 0, 0, 1, 0, 255, 0, 0, 980, 38586 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 981, 38610 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 982, 38611 },
    { -1, 100, 0, 0, 1, 2, 255, 0, 0, 983, 38572 },
    { 2, 98, 0, 0, 1, 0, 255, 0, 0, 984, 38567 },
    { 6, 102, 0, 0, 1, 0, 255, 0, 0, 985, 38604 },
    { 5, 102, 0, 0, 1, 0, 255, 0, 0, 986, 38605 },
    { 5, 102, 0, 0, 1, 0, 255, 0, 0, 987, 38606 },
    { 5, 102, 0, 0, 1, 0, 255, 0, 0, 988, 38607 },
    { 5, 101, 0, 0, 1, 0, 255, 0, 0, 989, 38567 },
    { -1, 101, 0, 0, 1, 0, 255, 0, 0, 990, 38586 },
    { -2, 102, 0, 0, 1, 0, 255, 0, 0, 991, 38588 },
    { -2, 100, 0, 0, 1, 0, 255, 0, 0, 992, 38586 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 993, 38610 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 994, 38611 },
    { -8, 96, 0, 0, 2, 0, 255, 0, 0, 995, 38602 },
    { -9, 95, 0, 0, 2, 0, 255, 0, 0, 996, 38603 },
    { 7, 98, 0, 0, 2, 1, 255, 0, 0, 997, 38534 },
    { 0, 96, 0, 0, 2, 1, 255, 0, 0, 998, 38536 },
    { -8, 94, 0, 0, 1, 0, 255, 0, 0, 999, 38532 },
    { 1, 95, 0, 0, 1, 0, 255, 0, 0, 1000, 38532 },
    { 1, 96, 0, 0, 1, 0, 255, 0, 0, 1001, 38534 },
    { 1, 98, 0, 0, 1, 0, 255, 0, 0, 1002, 38534 },
    { 4, 97, 0, 0, 1, 0, 255, 0, 0, 1003, 38563 },
    { 3, 94, 0, 0, 1, 0, 255, 0, 0, 1004, 38566 },
    { 1, 97, 0, 0, 1, 0, 255, 0, 0, 1005, 38567 },
    { 1, 97, 0, 0, 1, 0, 255, 0, 0, 1006, 38586 },
    { 3, 99, 0, 0, 1, 0, 255, 0, 0, 1007, 38610 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 1008, 38611 },
    { 32, -4, 0, 0, 2, 0, 255, 0, 0, 1009, 40003 },
    { 32, -4, 0, 0, 2, 0, 255, 0, 0, 1010, 40004 },
    { 32, -4, 0, 0, 2, 0, 255, 0, 0, 1011, 40005 },
    { 12, 72, 0, 0, 2, 0, 255, 0, 0, 1012, 39886 },
    { 12, 72, 0, 0, 2, 0, 255, 0, 0, 1013, 39887 },
    { -14, 100, 0, 0, 2, 0, 255, 0, 0, 1014, 39887 },
    { -16, 100, 0, 0, 2, 0, 255, 0, 0, 1015, 39888 },
    { -37, 100, 0, 0, 2, 0, 255, 0, 0, 1016, 39889 },
    { -37, 100, 0, 0, 2, 0, 255, 0, 0, 1017, 39887 },
    { -2, 92, 0, 0, 2, 0, 255, 0, 0, 1018, 39888 },
    { -2, 92, 0, 0, 2, 0, 255, 0, 0, 1019, 39889 },
    { -2, 92, 0, 0, 2, 0, 255, 0, 0, 1020, 39890 },
    { -30, 50, 0, 0, 1, 1, 255, 0, 0, 1021, 39891 },
    { -29, 50, 0, 0, 1, 1, 255, 0, 0, 1022, 39892 },
    { 1, 90, 0, 0, 1, 0, 255, 0, 0, 1023, 38540 },
    { 23, 88, 0, 0, 1, 0, 255, 0, 0, 1024, 38534 },
    { 24, 83, 0, 0, 1, 0, 255, 0, 0, 1025, 38533 },
    { 34, 65, 0, 0, 1, 0, 255, 0, 0, 1026, 38536 },
    { 27, 47, 0, 0, 1, 2, 255, 0, 0, 1027, 38541 },
    { 39, 5, 0, 0, 1, 2, 255, 0, 0, 1028, 38561 },
    { 43, 14, 0, 0, 1, 2, 255, 0, 0, 1029, 38524 },
    { 47, 14, 0, 0, 1, 2, 255, 0, 0, 1030, 38528 },
    { 37, -4, 0, 0, 1, 2, 255, 0, 0, 1031, 38538 },
    { 43, -4, 0, 0, 1, 2, 255, 0, 0, 1032, 38535 },
    { 42, -4, 0, 0, 1, 2, 255, 0, 0, 1033, 38534 },
    { 54, -1, 0, 0, 1, 3, 255, 0, 0, 1034, 38571 },
    { 54, -1, 0, 0, 1, 1, 255, 0, 0, 1035, 38547 },
    { 49, 4, 0, 0, 1, 1, 255, 0, 0, 1036, 38548 },
    { 49, 4, 0, 0, 1, 1, 255, 0, 0, 1037, 38548 },
    { 53, -1, 0, 0, 1, 3, 255, 0, 0, 1038, 38569 },
    { 55, 2, 0, 0, 1, 3, 255, 0, 0, 1039, 38500 },
    { 51, 9, 0, 0, 1, 0, 255, 0, 0, 1040, 38541 },
    { 38, -1, 0, 0, 1, 0, 255, 0, 0, 1041, 38555 },
    { 4, -1, 0, 0, 1, 0, 255, 0, 0, 1042, 38569 },
    { -16, 20, 0, 0, 1, 1, 255, 0, 0, 1043, 38541 },
    { -19, 31, 0, 0, 1, 1, 255, 0, 0, 1044, 38527 },
    { -6, 52, 0, 0, 1, 1, 255, 0, 0, 1045, 38565 },
    { -6, 53, 0, 0, 1, 1, 255, 0, 0, 1046, 38575 },
    { -18, 55, 0, 0, 1, 0, 255, 0, 0, 1047, 38560 },
    { -11, 56, 0, 0, 1, 0, 255, 0, 0, 1048, 38580 },
    { -13, 80, 0, 0, 1, 0, 255, 0, 0, 1049, 38523 },
    { -9, 93, 0, 0, 1, 0, 255, 0, 0, 1050, 38599 },
    { -3, 90, 0, 0, 1, 0, 255, 0, 0, 1051, 38580 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 1052, 38583 },
    { 13, 87, 0, 0, 1, 3, 255, 0, 0, 1053, 38567 },
    { 47, 81, 0, 0, 1, 1, 255, 0, 0, 1054, 38600 },
    { 54, 84, 0, 0, 1, 1, 255, 0, 0, 1055, 38515 },
    { 57, 79, 0, 0, 1, 1, 255, 0, 0, 1056, 38572 },
    { 63, 73, 0, 0, 1, 1, 255, 0, 0, 1057, 38570 },
    { 57, 72, 0, 0, 1, 1, 255, 0, 0, 1058, 38569 },
    { 50, 66, 0, 0, 1, 3, 255, 0, 0, 1059, 38573 },
    { 60, 55, 0, 0, 1, 3, 255, 0, 0, 1060, 38574 },
    { 56, 43, 0, 0, 1, 3, 255, 0, 0, 1061, 38575 },
    { 40, 23, 0, 0, 1, 3, 255, 0, 0, 1062, 38564 },
    { 19, 2, 0, 0, 2, 1, 255, 0, 0, 1063, 38591 },
    { 19, 2, 0, 0, 2, 1, 255, 0, 0, 1064, 38590 },
    { -31, 79, 0, 0, 1, 0, 255, 0, 0, 1065, 38527 },
    { -12, 63, 0, 0, 1, 1, 255, 0, 0, 1066, 38567 },
    { -14, 61, 0, 0, 1, 1, 255, 0, 0, 1067, 38569 },
    { -24, 42, 0, 0, 1, 1, 255, 0, 0, 1068, 38568 },
    { -1, 51, 0, 0, 1, 1, 255, 0, 0, 1069, 38600 },
    { 20, 53, 0, 0, 1, 1, 255, 0, 0, 1070, 38513 },
    { 23, 45, 0, 0, 1, 1, 255, 0, 0, 1071, 38602 },
    { 37, -3, 0, 0, 1, 2, 255, 0, 0, 1072, 38526 },
    { 55, -4, 0, 0, 1, 3, 255, 0, 0, 1073, 38504 },
    { 53, -4, 0, 0, 1, 3, 255, 0, 0, 1074, 38502 },
    { 54, -3, 0, 0, 1, 1, 255, 0, 0, 1075, 38567 },
    { 49, 2, 0, 0, 1, 1, 255, 0, 0, 1076, 38568 },
    { 49, 4, 0, 0, 1, 1, 255, 0, 0, 1077, 38549 },
    { 50, 3, 0, 0, 1, 1, 255, 0, 0, 1078, 38549 },
    { -15, 93, 0, 0, 1, 0, 255, 0, 0, 1079, 38564 },
    { 6, 97, 0, 0, 1, 0, 255, 0, 0, 1080, 38563 },
    { 21, 95, 0, 0, 1, 0, 255, 0, 0, 1081, 38559 },
    { 29, 81, 0, 0, 1, 2, 255, 0, 0, 1082, 38541 },
    { 25, 64, 0, 0, 1, 2, 255, 0, 0, 1083, 38563 },
    { 31, 60, 0, 0, 1, 2, 255, 0, 0, 1084, 38542 },
    { 21, 52, 0, 0, 1, 2, 255, 0, 0, 1085, 38562 },
    { 8, 43, 0, 0, 1, 2, 255, 0, 0, 1086, 38539 },
    { -1, 39, 0, 0, 1, 2, 255, 0, 0, 1087, 38508 },
    { -15, 41, 0, 0, 1, 2, 255, 0, 0, 1088, 38578 },
    { -28, 40, 0, 0, 1, 2, 255, 0, 0, 1089, 38546 },
    { -38, 52, 0, 0, 1, 2, 255, 0, 0, 1090, 38566 },
    { -43, 69, 0, 0, 1, 1, 255, 0, 0, 1091, 38561 },
    { -33, 83, 0, 0, 1, 1, 255, 0, 0, 1092, 38539 },
    { -29, 88, 0, 0, 1, 1, 255, 0, 0, 1093, 38540 },
    { -8, 99, 0, 0, 1, 1, 255, 0, 0, 1094, 38565 },
    { 5, 103, 0, 0, 1, 1, 255, 0, 0, 1095, 38566 },
    { 9, 103, 0, 0, 1, 1, 255, 0, 0, 1096, 38567 },
    { 1, 96, 0, 0, 1, 2, 255, 0, 0, 1097, 38561 },
    { 3, 100, 0, 0, 1, 2, 255, 0, 0, 1098, 38561 },
    { -5, 99, 0, 0, 1, 0, 255, 0, 0, 1099, 38590 },
    { -1, 96, 0, 0, 1, 0, 255, 0, 0, 1100, 38586 },
    { 2, 89, 0, 0, 1, 0, 255, 0, 0, 1101, 38580 },
    { 21, 97, 0, 0, 1, 0, 255, 0, 0, 1102, 38540 },
    { 24, 95, 0, 0, 1, 0, 255, 0, 0, 1103, 38539 },
    { 29, 93, 0, 0, 1, 0, 255, 0, 0, 1104, 38540 },
    { 33, 85, 0, 0, 1, 0, 255, 0, 0, 1105, 38575 },
    { 32, 88, 0, 0, 1, 0, 255, 0, 0, 1106, 38573 },
    { 31, 89, 0, 0, 1, 0, 255, 0, 0, 1107, 38574 },
    { 28, 90, 0, 0, 1, 0, 255, 0, 0, 1108, 38575 },
    { 21, 90, 0, 0, 1, 0, 255, 0, 0, 1109, 38576 },
    { 14, 90, 0, 0, 1, 0, 255, 0, 0, 1110, 38577 },
    { 3, 88, 0, 0, 1, 0, 255, 0, 0, 1111, 38578 },
    { -4, 90, 0, 0, 1, 0, 255, 0, 0, 1112, 38508 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1113, 38565 },
    { 0, 92, 0, 0, 1, 0, 255, 0, 0, 1114, 38564 },
    { -6, 92, 0, 0, 1, 1, 255, 0, 0, 1115, 38564 },
    { 1, 92, 0, 0, 1, 1, 255, 0, 0, 1116, 38562 },
    { 4, 93, 0, 0, 1, 1, 255, 0, 0, 1117, 38520 },
    { 11, 97, 0, 0, 2, 0, 255, 0, 0, 1118, 38541 },
    { 12, 94, 0, 0, 2, 0, 255, 0, 0, 1119, 38532 },
    { 7, 96, 0, 0, 2, 0, 255, 0, 0, 1120, 38534 },
    { 9, 96, 0, 0, 2, 0, 255, 0, 0, 1121, 38536 },
    { 22, 81, 0, 0, 2, 0, 255, 0, 0, 1122, 38534 },
    { 23, 78, 0, 0, 2, 0, 255, 0, 0, 1123, 38537 },
    { 21, 77, 0, 0, 2, 0, 255, 0, 0, 1124, 38565 },
    { 16, 79, 0, 0, 2, 0, 255, 0, 0, 1125, 38515 },
    { 14, 79, 0, 0, 2, 0, 255, 0, 0, 1126, 38518 },
    { 17, 81, 0, 0, 2, 0, 255, 0, 0, 1127, 38520 },
    { 12, 83, 0, 0, 2, 0, 255, 0, 0, 1128, 38522 },
    { 9, 84, 0, 0, 2, 0, 255, 0, 0, 1129, 38540 },
    { 2, 89, 0, 0, 1, 0, 255, 0, 0, 1130, 38522 },
    { -5, 87, 0, 0, 1, 0, 255, 0, 0, 1131, 38523 },
    { -11, 87, 0, 0, 1, 0, 255, 0, 0, 1132, 38580 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 1133, 38580 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 1134, 38578 },
    { -3, 89, 0, 0, 1, 0, 255, 0, 0, 1135, 38565 },
    { 0, 91, 0, 0, 1, 0, 255, 0, 0, 1136, 38564 },
    { -8, 89, 0, 0, 1, 0, 255, 0, 0, 1137, 38565 },
    { -2, 98, 0, 0, 1, 0, 255, 0, 0, 1138, 38598 },
    { -7, 96, 0, 0, 1, 0, 255, 0, 0, 1139, 38576 },
    { -6, 97, 0, 0, 1, 0, 255, 0, 0, 1140, 38599 },
    { -6, 96, 0, 0, 1, 0, 255, 0, 0, 1141, 38599 },
    { -6, 96, 0, 0, 1, 0, 255, 0, 0, 1142, 38599 },
    { -8, 98, 0, 0, 1, 0, 255, 0, 0, 1143, 38565 },
    { -6, 95, 0, 0, 1, 0, 255, 0, 0, 1144, 38566 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 1145, 38567 },
    { -4, 96, 0, 0, 1, 0, 255, 0, 0, 1146, 38589 },
    { 1, 88, 0, 0, 1, 0, 255, 0, 0, 1147, 38574 },
    { 1, 88, 0, 0, 1, 0, 255, 0, 0, 1148, 38575 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 1149, 38597 },
    { -3, 86, 0, 0, 1, 0, 255, 0, 0, 1150, 38598 },
    { -10, 83, 0, 0, 1, 0, 255, 0, 0, 1151, 38580 },
    { -5, 87, 0, 0, 1, 0, 255, 0, 0, 1152, 38581 },
    { -1, 91, 0, 0, 1, 0, 255, 0, 0, 1153, 38564 },
    { -3, 89, 0, 0, 1, 0, 255, 0, 0, 1154, 38565 },
    { 0, 91, 0, 0, 1, 0, 255, 0, 0, 1155, 38564 },
    { -2, 81, 0, 0, 2, 0, 255, 0, 0, 1156, 38566 },
    { -9, 88, 0, 0, 2, 0, 255, 0, 0, 1157, 38576 },
    { 4, 92, 0, 0, 2, 1, 255, 0, 0, 1158, 38526 },
    { 4, 96, 0, 0, 2, 1, 255, 0, 0, 1159, 38539 },
    { -11, 102, 0, 0, 1, 1, 255, 0, 0, 1160, 38562 },
    { -7, 110, 0, 0, 1, 0, 255, 0, 0, 1161, 38561 },
    { -9, 111, 0, 0, 1, 0, 255, 0, 0, 1162, 38562 },
    { -9, 114, 0, 0, 1, 0, 255, 0, 0, 1163, 38563 },
    { -7, 115, 0, 0, 1, 0, 255, 0, 0, 1164, 38563 },
    { -2, 115, 0, 0, 1, 0, 255, 0, 0, 1165, 38566 },
    { -2, 118, 0, 0, 1, 0, 255, 0, 0, 1166, 38513 },
    { -7, 119, 0, 0, 1, 0, 255, 0, 0, 1167, 38514 },
    { -5, 116, 0, 0, 1, 0, 255, 0, 0, 1168, 38515 },
    { -5, 115, 0, 0, 1, 0, 255, 0, 0, 1169, 38517 },
    { -5, 114, 0, 0, 1, 0, 255, 0, 0, 1170, 38589 },
    { -6, 109, 0, 0, 1, 0, 255, 0, 0, 1171, 38568 },
    { -7, 108, 0, 0, 1, 0, 255, 0, 0, 1172, 38567 },
    { -7, 105, 0, 0, 1, 0, 255, 0, 0, 1173, 38587 },
    { -6, 85, 0, 0, 1, 0, 255, 0, 0, 1174, 38586 },
    { -18, 43, 0, 0, 1, 0, 255, 0, 0, 1175, 38587 },
    { -17, 40, 0, 0, 1, 0, 255, 0, 0, 1176, 38589 },
    { -20, 55, 0, 0, 1, 0, 255, 0, 0, 1177, 38565 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 1178, 38598 },
    { -6, 88, 0, 0, 1, 0, 255, 0, 0, 1179, 38598 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 1180, 38599 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1181, 38565 },
    { 0, 92, 0, 0, 1, 0, 255, 0, 0, 1182, 38564 },
    { -15, 73, 0, 0, 1, 2, 255, 0, 0, 1183, 38589 },
    { -5, 79, 0, 0, 1, 0, 255, 0, 0, 1184, 38566 },
    { -9, 88, 0, 0, 2, 0, 255, 0, 0, 1185, 38576 },
    { 4, 93, 0, 0, 2, 1, 255, 0, 0, 1186, 38526 },
    { 3, 96, 0, 0, 2, 1, 255, 0, 0, 1187, 38539 },
    { -16, 101, 0, 0, 1, 0, 255, 0, 0, 1188, 38562 },
    { -6, 110, 0, 0, 1, 0, 255, 0, 0, 1189, 38561 },
    { -9, 111, 0, 0, 1, 0, 255, 0, 0, 1190, 38562 },
    { -7, 112, 0, 0, 1, 0, 255, 0, 0, 1191, 38563 },
    { -6, 114, 0, 0, 1, 0, 255, 0, 0, 1192, 38563 },
    { -3, 113, 0, 0, 1, 0, 255, 0, 0, 1193, 38561 },
    { -5, 110, 0, 0, 1, 0, 255, 0, 0, 1194, 38565 },
    { 4, 105, 0, 0, 1, 0, 255, 0, 0, 1195, 38566 },
    { 8, 102, 0, 0, 1, 0, 255, 0, 0, 1196, 38586 },
    { 15, 98, 0, 0, 1, 0, 255, 0, 0, 1197, 38587 },
    { 9, 97, 0, 0, 1, 0, 255, 0, 0, 1198, 38588 },
    { 46, 9, 0, 0, 2, 3, 255, 0, 0, 1199, 38550 },
    { 42, 26, 0, 0, 2, 1, 255, 0, 0, 1200, 38563 },
    { 36, 30, 0, 0, 2, 1, 255, 0, 0, 1201, 38562 },
    { 37, 40, 0, 0, 2, 1, 255, 0, 0, 1202, 38561 },
    { 35, 48, 0, 0, 2, 1, 255, 0, 0, 1203, 38560 },
    { 41, 43, 0, 0, 2, 1, 255, 0, 0, 1204, 38560 },
    { 42, 44, 0, 0, 2, 1, 255, 0, 0, 1205, 38560 },
    { 41, 49, 0, 0, 2, 1, 255, 0, 0, 1206, 38560 },
    { 39, 47, 0, 0, 2, 1, 255, 0, 0, 1207, 38565 },
    { 39, 47, 0, 0, 2, 1, 255, 0, 0, 1208, 38566 },
    { 32, 43, 0, 0, 2, 2, 255, 0, 0, 1209, 38561 },
    { 14, 47, 0, 0, 2, 0, 255, 0, 0, 1210, 38586 },
    { -13, 64, 0, 0, 2, 2, 255, 0, 0, 1211, 38566 },
    { -11, 77, 0, 0, 2, 1, 255, 0, 0, 1212, 38539 },
    { -5, 90, 0, 0, 2, 1, 255, 0, 0, 1213, 38538 },
    { -3, 89, 0, 0, 2, 1, 255, 0, 0, 1214, 38580 },
    { -5, 92, 0, 0, 1, 0, 255, 0, 0, 1215, 38538 },
    { -2, 93, 0, 0, 1, 0, 255, 0, 0, 1216, 38539 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 1217, 38540 },
    { -3, 92, 0, 0, 1, 0, 255, 0, 0, 1218, 38501 },
    { -3, 92, 0, 0, 1, 0, 255, 0, 0, 1219, 38503 },
    { -3, 91, 0, 0, 1, 0, 255, 0, 0, 1220, 38505 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1221, 38509 },
    { 17, 47, 0, 0, 1, 0, 255, 0, 0, 1222, 38571 },
    { 11, 47, 0, 0, 1, 0, 255, 0, 0, 1223, 38570 },
    { 22, 45, 0, 0, 1, 0, 255, 0, 0, 1224, 38572 },
    { 24, 45, 0, 0, 1, 0, 255, 0, 0, 1225, 38573 },
    { -5, 48, 0, 0, 1, 0, 255, 0, 0, 1226, 38575 },
    { -21, 91, 0, 0, 1, 0, 255, 0, 0, 1227, 38566 },
    { -4, 85, 0, 0, 1, 0, 255, 0, 0, 1228, 38568 },
    { -11, 83, 0, 0, 1, 0, 255, 0, 0, 1229, 38569 },
    { -10, 84, 0, 0, 1, 0, 255, 0, 0, 1230, 38573 },
    { -6, 86, 0, 0, 1, 0, 255, 0, 0, 1231, 38575 },
    { -5, 87, 0, 0, 1, 0, 255, 0, 0, 1232, 38576 },
    { -3, 88, 0, 0, 1, 0, 255, 0, 0, 1233, 38578 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 1234, 38579 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 1235, 38582 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 1236, 38584 },
    { 26, 84, 0, 0, 1, 1, 255, 0, 0, 1237, 38497 },
    { -9, 91, 0, 0, 1, 0, 255, 0, 0, 1238, 38599 },
    { -1, 91, 0, 0, 1, 0, 255, 0, 0, 1239, 38581 },
    { -7, 96, 0, 0, 1, 0, 255, 0, 0, 1240, 38581 },
    { -4, 94, 0, 0, 1, 0, 255, 0, 0, 1241, 38581 },
    { -4, 93, 0, 0, 1, 0, 255, 0, 0, 1242, 38578 },
    { -7, 97, 0, 0, 1, 0, 255, 0, 0, 1243, 38578 },
    { -5, 92, 0, 0, 1, 0, 255, 0, 0, 1244, 38573 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 1245, 38566 },
    { -6, 93, 0, 0, 1, 0, 255, 0, 0, 1246, 38580 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 1247, 38581 },
    { -7, 95, 0, 0, 1, 0, 255, 0, 0, 1248, 38590 },
    { -1, 92, 0, 0, 1, 0, 255, 0, 0, 1249, 38591 },
    { -1, 91, 0, 0, 1, 0, 255, 0, 0, 1250, 38592 },
    { -1, 88, 0, 0, 1, 0, 255, 0, 0, 1251, 38593 },
    { -10, 90, 0, 0, 1, 0, 255, 0, 0, 1252, 38594 },
    { -3, 86, 0, 0, 1, 0, 255, 0, 0, 1253, 38595 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 1254, 38596 },
    { -6, 88, 0, 0, 1, 0, 255, 0, 0, 1255, 38597 },
    { -8, 94, 0, 0, 1, 0, 255, 0, 0, 1256, 38599 },
    { -2, 90, 0, 0, 1, 0, 255, 0, 0, 1257, 38581 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 1258, 38582 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 1259, 38583 },
    { -19, 58, 0, 0, 1, 0, 255, 0, 0, 1260, 38589 },
    { -17, 44, 0, 0, 1, 0, 255, 0, 0, 1261, 38588 },
    { -17, 40, 0, 0, 1, 0, 255, 0, 0, 1262, 38589 },
    { 16, 75, 0, 0, 1, 2, 255, 0, 0, 1263, 38614 },
    { 3, 92, 0, 0, 1, 2, 255, 0, 0, 1264, 38590 },
    { 0, 93, 0, 0, 1, 2, 255, 0, 0, 1265, 38585 },
    { -5, 94, 0, 0, 1, 2, 255, 0, 0, 1266, 38587 },
    { -20, 90, 0, 0, 1, 2, 255, 0, 0, 1267, 38519 },
    { -16, 90, 0, 0, 1, 2, 255, 0, 0, 1268, 38520 },
    { -17, 89, 0, 0, 1, 2, 255, 0, 0, 1269, 38521 },
    { -15, 95, 0, 0, 1, 0, 255, 0, 0, 1270, 38586 },
    { -13, 92, 0, 0, 1, 0, 255, 0, 0, 1271, 38567 },
    { -12, 92, 0, 0, 1, 0, 255, 0, 0, 1272, 38567 },
    { -11, 93, 0, 0, 1, 0, 255, 0, 0, 1273, 38568 },
    { -8, 96, 0, 0, 1, 0, 255, 0, 0, 1274, 38569 },
    { -8, 98, 0, 0, 1, 0, 255, 0, 0, 1275, 38571 },
    { -8, 99, 0, 0, 1, 0, 255, 0, 0, 1276, 38570 },
    { -8, 101, 0, 0, 1, 0, 255, 0, 0, 1277, 38571 },
    { -8, 104, 0, 0, 1, 0, 255, 0, 0, 1278, 38569 },
    { -8, 104, 0, 0, 1, 0, 255, 0, 0, 1279, 38571 },
    { -6, 102, 0, 0, 1, 0, 255, 0, 0, 1280, 38569 },
    { -11, 95, 0, 0, 1, 0, 255, 0, 0, 1281, 38567 },
    { -16, 96, 0, 0, 1, 0, 255, 0, 0, 1282, 38567 },
    { -15, 97, 0, 0, 1, 0, 255, 0, 0, 1283, 38586 },
    { -5, 100, 0, 0, 1, 0, 255, 0, 0, 1284, 38585 },
    { 28, 56, 0, 0, 1, 2, 255, 0, 0, 1285, 38564 },
    { 0, 101, 0, 0, 1, 2, 255, 0, 0, 1286, 38561 },
    { 0, 106, 0, 0, 1, 0, 255, 0, 0, 1287, 38585 },
    { -5, 100, 0, 0, 1, 0, 255, 0, 0, 1288, 38586 },
    { 6, 98, 0, 0, 1, 1, 255, 0, 0, 1289, 38565 },
    { 16, 97, 0, 0, 1, 1, 255, 0, 0, 1290, 38540 },
    { 26, 95, 0, 0, 1, 1, 255, 0, 0, 1291, 38503 },
    { 30, 81, 0, 0, 1, 2, 255, 0, 0, 1292, 38541 },
    { 22, 65, 0, 0, 1, 2, 255, 0, 0, 1293, 38563 },
    { 26, 62, 0, 0, 1, 0, 255, 0, 0, 1294, 38585 },
    { 22, 55, 0, 0, 1, 0, 255, 0, 0, 1295, 38585 },
    { 10, 46, 0, 0, 1, 0, 255, 0, 0, 1296, 38585 },
    { 0, 43, 0, 0, 1, 0, 255, 0, 0, 1297, 38586 },
    { -17, 42, 0, 0, 1, 0, 255, 0, 0, 1298, 38586 },
    { -31, 45, 0, 0, 1, 0, 255, 0, 0, 1299, 38587 },
    { -38, 52, 0, 0, 1, 2, 255, 0, 0, 1300, 38566 },
    { -43, 69, 0, 0, 1, 1, 255, 0, 0, 1301, 38561 },
    { -38, 83, 0, 0, 1, 1, 255, 0, 0, 1302, 38564 },
    { -30, 86, 0, 0, 1, 1, 255, 0, 0, 1303, 38565 },
    { -9, 98, 0, 0, 1, 1, 255, 0, 0, 1304, 38566 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 1305, 38520 },
    { -12, 85, 0, 0, 1, 0, 255, 0, 0, 1306, 38516 },
    { -12, 84, 0, 0, 1, 0, 255, 0, 0, 1307, 38513 },
    { -13, 84, 0, 0, 1, 0, 255, 0, 0, 1308, 38515 },
    { -13, 87, 0, 0, 1, 0, 255, 0, 0, 1309, 38518 },
    { -8, 89, 0, 0, 1, 0, 255, 0, 0, 1310, 38519 },
    { -7, 90, 0, 0, 1, 0, 255, 0, 0, 1311, 38520 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 1312, 38521 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1313, 38505 },
    { 0, 91, 0, 0, 1, 0, 255, 0, 0, 1314, 38564 },
    { 2, 101, 0, 0, 1, 0, 255, 0, 0, 1315, 38562 },
    { 3, 100, 0, 0, 1, 0, 255, 0, 0, 1316, 38561 },
    { 5, 103, 0, 0, 1, 0, 255, 0, 0, 1317, 38562 },
    { 1, 103, 0, 0, 1, 0, 255, 0, 0, 1318, 38536 },
    { 1, 103, 0, 0, 1, 0, 255, 0, 0, 1319, 38535 },
    { -1, 104, 0, 0, 1, 0, 255, 0, 0, 1320, 38538 },
    { 0, 101, 0, 0, 1, 0, 255, 0, 0, 1321, 38540 },
    { -1, 100, 0, 0, 1, 0, 255, 0, 0, 1322, 38565 },
    { 0, 98, 0, 0, 1, 0, 255, 0, 0, 1323, 38566 },
    { 4, 99, 0, 0, 1, 0, 255, 0, 0, 1324, 38586 },
    { -22, 78, 0, 0, 1, 0, 255, 0, 0, 1325, 38568 },
    { 50, 0, 0, 0, 1, 1, 255, 0, 0, 1326, 38585 },
    { 56, 0, 0, 0, 1, 1, 255, 0, 0, 1327, 38591 },
    { 57, -4, 0, 0, 1, 3, 255, 0, 0, 1328, 38596 },
    { 54, -1, 0, 0, 1, 3, 255, 0, 0, 1329, 38574 },
    { 55, -1, 0, 0, 1, 3, 255, 0, 0, 1330, 38573 },
    { 57, -3, 0, 0, 1, 3, 255, 0, 0, 1331, 38572 },
    { 55, 0, 0, 0, 1, 3, 255, 0, 0, 1332, 38571 },
    { 41, -2, 0, 0, 1, 0, 255, 0, 0, 1333, 38556 },
    { 35, -1, 0, 0, 1, 0, 255, 0, 0, 1334, 38555 },
    { 35, -1, 0, 0, 1, 0, 255, 0, 0, 1335, 38554 },
    { 47, -2, 0, 0, 1, 0, 255, 0, 0, 1336, 38553 },
    { 45, -2, 0, 0, 1, 0, 255, 0, 0, 1337, 38552 },
    { 53, 0, 0, 0, 1, 1, 255, 0, 0, 1338, 38549 },
    { 40, 4, 0, 0, 1, 1, 255, 0, 0, 1339, 38550 },
    { 12, 91, 0, 0, 2, 1, 255, 0, 0, 1340, 38559 },
    { 35, 95, 0, 0, 2, 1, 255, 0, 0, 1341, 38526 },
    { 26, 101, 0, 0, 2, 1, 255, 0, 0, 1342, 38560 },
    { 27, 105, 0, 0, 2, 1, 255, 0, 0, 1343, 38561 },
    { 38, 102, 0, 0, 2, 1, 255, 0, 0, 1344, 38563 },
    { 34, 102, 0, 0, 1, 1, 255, 0, 0, 1345, 38546 },
    { 38, 94, 0, 0, 1, 1, 255, 0, 0, 1346, 38548 },
    { 35, 91, 0, 0, 1, 1, 255, 0, 0, 1347, 38497 },
    { 30, 83, 0, 0, 2, 3, 255, 0, 0, 1348, 38600 },
    { 32, 76, 0, 0, 2, 1, 255, 0, 0, 1349, 38604 },
    { 31, 73, 0, 0, 1, 1, 255, 0, 0, 1350, 38605 },
    { 32, 66, 0, 0, 1, 1, 255, 0, 0, 1351, 38606 },
    { 38, 55, 0, 0, 1, 1, 255, 0, 0, 1352, 38608 },
    { 40, 41, 0, 0, 1, 1, 255, 0, 0, 1353, 38609 },
    { 43, 31, 0, 0, 1, 1, 255, 0, 0, 1354, 38610 },
    { 44, 31, 0, 0, 1, 1, 255, 0, 0, 1355, 38611 },
    { 42, 21, 0, 0, 1, 1, 255, 0, 0, 1356, 38590 },
    { 37, 19, 0, 0, 1, 1, 255, 0, 0, 1357, 38594 },
    { 54, 13, 0, 0, 1, 1, 255, 0, 0, 1358, 38592 },
    { 54, 12, 0, 0, 1, 1, 255, 0, 0, 1359, 38591 },
    { 43, -1, 0, 0, 1, 1, 255, 0, 0, 1360, 38591 },
    { 40, 0, 0, 0, 1, 3, 255, 0, 0, 1361, 38576 },
    { 49, -1, 0, 0, 1, 3, 255, 0, 0, 1362, 38574 },
    { 49, -1, 0, 0, 1, 3, 255, 0, 0, 1363, 38571 },
    { 50, -1, 0, 0, 1, 1, 255, 0, 0, 1364, 38549 },
    { 9, 95, 0, 0, 1, 0, 255, 0, 0, 1365, 38503 },
    { -34, 66, 0, 0, 1, 0, 255, 0, 0, 1366, 38566 },
    { 17, 26, 0, 0, 1, 3, 255, 0, 0, 1367, 38565 },
    { -15, 51, 0, 0, 1, 0, 255, 0, 0, 1368, 38566 },
    { -23, 29, 0, 0, 1, 3, 255, 0, 0, 1369, 38560 },
    { -12, 16, 0, 0, 1, 3, 255, 0, 0, 1370, 38539 },
    { 13, -2, 0, 0, 1, 3, 255, 0, 0, 1371, 38503 },
    { 44, -4, 0, 0, 1, 3, 255, 0, 0, 1372, 38515 },
    { 51, 9, 0, 0, 1, 0, 255, 0, 0, 1373, 38541 },
    { -51, 81, 0, 0, 2, 0, 255, 0, 0, 1374, 38499 },
    { 0, 102, 0, 0, 1, 0, 255, 0, 0, 1375, 38523 },
    { 2, 106, 0, 0, 1, 0, 255, 0, 0, 1376, 38526 },
    { 2, 102, 0, 0, 1, 0, 255, 0, 0, 1377, 38536 },
    { -5, 97, 0, 0, 1, 0, 255, 0, 0, 1378, 38538 },
    { -6, 93, 0, 0, 1, 0, 255, 0, 0, 1379, 38539 },
    { -5, 93, 0, 0, 1, 0, 255, 0, 0, 1380, 38540 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 1381, 38509 },
    { -3, 92, 0, 0, 1, 0, 255, 0, 0, 1382, 38510 },
    { -9, 88, 0, 0, 2, 2, 255, 0, 0, 1383, 38560 },
    { -14, 85, 0, 0, 2, 0, 255, 0, 0, 1384, 38585 },
    { -23, 86, 0, 0, 2, 0, 255, 0, 0, 1385, 38586 },
    { -27, 82, 0, 0, 2, 0, 255, 0, 0, 1386, 38567 },
    { -26, 82, 0, 0, 2, 0, 255, 0, 0, 1387, 38568 },
    { -26, 82, 0, 0, 2, 0, 255, 0, 0, 1388, 38569 },
    { -27, 82, 0, 0, 2, 0, 255, 0, 0, 1389, 38570 },
    { -2, 93, 0, 0, 1, 1, 255, 0, 0, 1390, 38524 },
    { 3, 92, 0, 0, 1, 1, 255, 0, 0, 1391, 38525 },
    { 4, 93, 0, 0, 1, 1, 255, 0, 0, 1392, 38528 },
    { 7, 96, 0, 0, 2, 0, 255, 0, 0, 1393, 38531 },
    { 13, 94, 0, 0, 2, 0, 255, 0, 0, 1394, 38533 },
    { 9, 97, 0, 0, 2, 0, 255, 0, 0, 1395, 38535 },
    { 11, 97, 0, 0, 2, 0, 255, 0, 0, 1396, 38536 },
    { 22, 81, 0, 0, 2, 0, 255, 0, 0, 1397, 38528 },
    { 24, 78, 0, 0, 2, 0, 255, 0, 0, 1398, 38527 },
    { 19, 79, 0, 0, 2, 0, 255, 0, 0, 1399, 38526 },
    { 15, 79, 0, 0, 2, 0, 255, 0, 0, 1400, 38525 },
    { 17, 81, 0, 0, 2, 0, 255, 0, 0, 1401, 38524 },
    { 13, 83, 0, 0, 1, 0, 255, 0, 0, 1402, 38523 },
    { 10, 84, 0, 0, 1, 0, 255, 0, 0, 1403, 38521 },
    { 2, 89, 0, 0, 1, 0, 255, 0, 0, 1404, 38505 },
    { -5, 87, 0, 0, 1, 0, 255, 0, 0, 1405, 38506 },
    { -12, 90, 0, 0, 1, 0, 255, 0, 0, 1406, 38507 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 1407, 38508 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 1408, 38509 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1409, 38510 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1410, 38511 },
    { -7, 60, 0, 0, 1, 0, 255, 0, 0, 1411, 38502 },
    { 5, 62, 0, 0, 1, 1, 255, 0, 0, 1412, 38561 },
    { 7, 61, 0, 0, 1, 1, 255, 0, 0, 1413, 38562 },
    { 11, 60, 0, 0, 1, 1, 255, 0, 0, 1414, 38535 },
    { 1, 57, 0, 0, 1, 2, 255, 0, 0, 1415, 38549 },
    { 8, 58, 0, 0, 1, 1, 255, 0, 0, 1416, 38535 },
    { -5, 56, 0, 0, 1, 1, 255, 0, 0, 1417, 38541 },
    { -8, 52, 0, 0, 1, 0, 255, 0, 0, 1418, 38514 },
    { -7, 51, 0, 0, 1, 0, 255, 0, 0, 1419, 38515 },
    { -6, 51, 0, 0, 1, 0, 255, 0, 0, 1420, 38516 },
    { -3, 51, 0, 0, 1, 0, 255, 0, 0, 1421, 38517 },
    { -14, 55, 0, 0, 1, 0, 255, 0, 0, 1422, 38518 },
    { -14, 55, 0, 0, 1, 0, 255, 0, 0, 1423, 38519 },
    { -11, 56, 0, 0, 1, 0, 255, 0, 0, 1424, 38503 },
    { -8, 59, 0, 0, 1, 0, 255, 0, 0, 1425, 38520 },
    { -7, 58, 0, 0, 1, 0, 255, 0, 0, 1426, 38504 },
    { -9, 58, 0, 0, 1, 0, 255, 0, 0, 1427, 38521 },
    { -10, 59, 0, 0, 1, 0, 255, 0, 0, 1428, 38506 },
    { -10, 59, 0, 0, 1, 0, 255, 0, 0, 1429, 38507 },
    { -8, 59, 0, 0, 1, 0, 255, 0, 0, 1430, 38508 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 1431, 38509 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 1432, 38510 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 1433, 38511 },
    { -6, 56, 0, 0, 1, 0, 255, 0, 0, 1434, 38520 },
    { -9, 61, 0, 0, 1, 0, 255, 0, 0, 1435, 38521 },
    { -10, 79, 0, 0, 1, 0, 255, 0, 0, 1436, 38522 },
    { -7, 93, 0, 0, 1, 0, 255, 0, 0, 1437, 38523 },
    { 3, 105, 0, 0, 1, 0, 255, 0, 0, 1438, 38565 },
    { 3, 105, 0, 0, 1, 0, 255, 0, 0, 1439, 38566 },
    { 4, 104, 0, 0, 1, 0, 255, 0, 0, 1440, 38567 },
    { 7, 105, 0, 0, 1, 0, 255, 0, 0, 1441, 38608 },
    { 2, 107, 0, 0, 1, 0, 255, 0, 0, 1442, 38585 },
    { 2, 103, 0, 0, 1, 0, 255, 0, 0, 1443, 38591 },
    { 2, 103, 0, 0, 1, 0, 255, 0, 0, 1444, 38592 },
    { 2, 103, 0, 0, 1, 0, 255, 0, 0, 1445, 38593 },
    { 2, 103, 0, 0, 1, 0, 255, 0, 0, 1446, 38594 },
    { 2, 96, 0, 0, 1, 0, 255, 0, 0, 1447, 38595 },
    { -3, 92, 0, 0, 1, 0, 255, 0, 0, 1448, 38596 },
    { -3, 91, 0, 0, 1, 0, 255, 0, 0, 1449, 38597 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1450, 38598 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1451, 38599 },
    { -1, 87, 0, 0, 1, 0, 255, 0, 0, 1452, 38589 },
    { 2, 80, 0, 0, 1, 0, 255, 0, 0, 1453, 38587 },
    { 7, 73, 0, 0, 1, 0, 255, 0, 0, 1454, 38591 },
    { 2, 68, 0, 0, 1, 0, 255, 0, 0, 1455, 38592 },
    { 2, 68, 0, 0, 1, 0, 255, 0, 0, 1456, 38593 },
    { -18, 46, 0, 0, 1, 0, 255, 0, 0, 1457, 38567 },
    { -31, 39, 0, 0, 1, 0, 255, 0, 0, 1458, 38568 },
    { -31, 38, 0, 0, 1, 0, 255, 0, 0, 1459, 38571 },
    { -27, 39, 0, 0, 1, 0, 255, 0, 0, 1460, 38573 },
    { -27, 39, 0, 0, 1, 0, 255, 0, 0, 1461, 38574 },
    { -28, 39, 0, 0, 1, 0, 255, 0, 0, 1462, 38575 },
    { -15, 88, 0, 0, 1, 0, 255, 0, 0, 1463, 38505 },
    { -15, 90, 0, 0, 1, 0, 255, 0, 0, 1464, 38504 },
    { -20, 92, 0, 0, 1, 0, 255, 0, 0, 1465, 38503 },
    { -21, 92, 0, 0, 1, 0, 255, 0, 0, 1466, 38504 },
    { -21, 91, 0, 0, 1, 0, 255, 0, 0, 1467, 38505 },
    { -20, 92, 0, 0, 1, 0, 255, 0, 0, 1468, 38504 },
    { -18, 73, 0, 0, 1, 0, 255, 0, 0, 1469, 38567 },
    { -56, 0, 0, 0, 1, 0, 255, 0, 0, 1470, 38576 },
    { -48, -1, 0, 0, 1, 0, 255, 0, 0, 1471, 38577 },
    { 2, -50, 0, 0, 1, 2, 255, 0, 0, 1472, 38612 },
    { -38, -73, 0, 0, 2, 0, 255, 0, 0, 1473, 38502 },
    { -29, -82, 0, 0, 2, 2, 255, 0, 0, 1474, 38518 },
    { -17, -83, 0, 0, 1, 2, 255, 0, 0, 1475, 38560 },
    { 39, -4, 0, 0, 1, 2, 255, 0, 0, 1476, 38525 },
    { 53, 52, 0, 0, 2, 1, 255, 0, 0, 1477, 38502 },
    { 52, 63, 0, 0, 2, 1, 255, 0, 0, 1478, 38522 },
    { 45, 70, 0, 0, 2, 1, 255, 0, 0, 1479, 38523 },
    { 25, 84, 0, 0, 2, 1, 255, 0, 0, 1480, 38524 },
    { 18, 84, 0, 0, 2, 1, 255, 0, 0, 1481, 38524 },
    { 27, 42, 0, 0, 2, 1, 255, 0, 0, 1482, 38575 },
    { 26, 64, 0, 0, 2, 1, 255, 0, 0, 1483, 38577 },
    { 25, 84, 0, 0, 2, 1, 255, 0, 0, 1484, 38523 },
    { 24, 66, 0, 0, 2, 1, 255, 0, 0, 1485, 38525 },
    { -4, 104, 0, 0, 2, 1, 255, 0, 0, 1486, 38526 },
    { -52, 42, 0, 0, 2, 0, 255, 0, 0, 1487, 38608 },
    { -39, 1, 0, 0, 2, 1, 255, 0, 0, 1488, 38590 },
    { -39, 1, 0, 0, 2, 1, 255, 0, 0, 1489, 38591 },
    { -7, 86, 0, 0, 1, 0, 255, 0, 0, 1490, 38504 },
    { -6, 84, 0, 0, 1, 0, 255, 0, 0, 1491, 38505 },
    { -10, 81, 0, 0, 1, 0, 255, 0, 0, 1492, 38506 },
    { -12, 78, 0, 0, 1, 0, 255, 0, 0, 1493, 38507 },
    { -49, 60, 0, 0, 1, 0, 255, 0, 0, 1494, 38566 },
    { -44, 67, 0, 0, 1, 0, 255, 0, 0, 1495, 38568 },
    { -44, 67, 0, 0, 1, 0, 255, 0, 0, 1496, 38569 },
    { -31, -51, 0, 0, 1, 0, 255, 0, 0, 1497, 38574 },
    { -24, -85, 0, 0, 1, 1, 255, 0, 0, 1498, 38524 },
    { 55, 1, 0, 0, 1, 3, 255, 0, 0, 1499, 38568 },
    { 53, 63, 0, 0, 1, 3, 255, 0, 0, 1500, 38515 },
    { -7, 53, 0, 0, 1, 0, 255, 0, 0, 1501, 38539 },
    { 34, 65, 0, 0, 1, 0, 255, 0, 0, 1502, 38536 },
    { 33, 46, 0, 0, 1, 3, 255, 0, 0, 1503, 38522 },
    { 49, -4, 0, 0, 1, 2, 255, 0, 0, 1504, 38561 },
    { 47, -4, 0, 0, 1, 2, 255, 0, 0, 1505, 38563 },
    { 46, -4, 0, 0, 1, 2, 255, 0, 0, 1506, 38532 },
    { 44, 70, 0, 0, 1, 1, 255, 0, 0, 1507, 38522 },
    { 30, 79, 0, 0, 1, 1, 255, 0, 0, 1508, 38523 },
    { 25, 67, 0, 0, 1, 1, 255, 0, 0, 1509, 38524 },
    { 5, 98, 0, 0, 1, 1, 255, 0, 0, 1510, 38579 },
    { -5, 105, 0, 0, 1, 1, 255, 0, 0, 1511, 38523 },
    { -5, 105, 0, 0, 1, 1, 255, 0, 0, 1512, 38522 },
    { 20, 77, 0, 0, 1, 1, 255, 0, 0, 1513, 38518 },
    { -20, 77, 0, 0, 1, 0, 255, 0, 0, 1514, 38517 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1515, 38520 },
    { -13, 93, 0, 0, 1, 0, 255, 0, 0, 1516, 38519 },
    { 7, 93, 0, 0, 1, 0, 255, 0, 0, 1517, 38523 },
    { 15, 99, 0, 0, 1, 1, 255, 0, 0, 1518, 38526 },
    { -4, 99, 0, 0, 1, 1, 255, 0, 0, 1519, 38520 },
    { -16, 85, 0, 0, 1, 3, 255, 0, 0, 1520, 38590 },
    { 17, 91, 0, 0, 1, 1, 255, 0, 0, 1521, 38568 },
    { 42, -17, 0, 0, 1, 2, 255, 0, 0, 1522, 38526 },
    { -17, -90, 0, 0, 1, 2, 255, 0, 0, 1523, 38572 },
    { -56, -2, 0, 0, 1, 2, 255, 0, 0, 1524, 38565 },
    { 52, -2, 0, 0, 1, 3, 255, 0, 0, 1525, 38573 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1526, 38524 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1527, 38523 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1528, 38522 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 1529, 38521 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1530, 38520 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1531, 38521 },
    { 0, 90, 0, 0, 1, 0, 255, 0, 0, 1532, 38522 },
    { -2, 92, 0, 0, 1, 0, 255, 0, 0, 1533, 38523 },
    { -12, 87, 0, 0, 1, 0, 255, 0, 0, 1534, 38524 },
    { -13, 87, 0, 0, 1, 0, 255, 0, 0, 1535, 38525 },
    { -13, 86, 0, 0, 1, 0, 255, 0, 0, 1536, 38526 },
    { -28, 83, 0, 0, 1, 0, 255, 0, 0, 1537, 38539 },
    { -32, 46, 0, 0, 1, 0, 255, 0, 0, 1538, 38533 },
    { -11, 99, 0, 0, 2, 0, 255, 0, 0, 1539, 38524 },
    { -18, 94, 0, 0, 2, 0, 255, 0, 0, 1540, 38525 },
    { -25, 84, 0, 0, 2, 0, 255, 0, 0, 1541, 38526 },
    { -25, 84, 0, 0, 2, 0, 255, 0, 0, 1542, 38528 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1543, 38540 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1544, 38539 },
    { 24, 87, 0, 0, 1, 0, 255, 0, 0, 1545, 38538 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1546, 38537 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1547, 38538 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 1548, 38539 },
    { 25, 105, 0, 0, 2, 0, 255, 0, 0, 1549, 38558 },
    { 0, 86, 0, 0, 1, 0, 255, 0, 0, 1550, 38583 },
    { 0, 86, 0, 0, 1, 0, 255, 0, 0, 1551, 38582 },
    { 0, 86, 0, 0, 1, 0, 255, 0, 0, 1552, 38581 },
    { 0, 86, 0, 0, 1, 0, 255, 0, 0, 1553, 38580 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1554, 38526 },
    { 7, 93, 0, 0, 1, 0, 255, 0, 0, 1555, 38523 },
    { 7, 93, 0, 0, 1, 0, 255, 0, 0, 1556, 38522 },
    { 14, 86, 0, 0, 1, 0, 255, 0, 0, 1557, 38535 },
    { 47, 81, 0, 0, 1, 1, 255, 0, 0, 1558, 38603 },
    { -5, 91, 0, 0, 1, 0, 255, 0, 0, 1559, 38520 },
    { 10, 86, 0, 0, 1, 0, 255, 0, 0, 1560, 38521 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 1561, 38522 },
    { 10, 95, 0, 0, 1, 0, 255, 0, 0, 1562, 38589 },
    { 27, 82, 0, 0, 1, 1, 255, 0, 0, 1563, 38525 },
    { -63, -51, 0, 0, 1, 0, 255, 0, 0, 1564, 38592 },
    { -34, -65, 0, 0, 1, 3, 255, 0, 0, 1565, 38524 },
    { 28, 84, 0, 0, 1, 0, 255, 0, 0, 1566, 38562 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 1567, 38510 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 1568, 38509 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1569, 38508 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1570, 38507 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1571, 38506 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1572, 38505 },
    { -26, 79, 0, 0, 2, 0, 255, 0, 0, 1573, 38566 },
    { -26, 64, 0, 0, 2, 0, 255, 0, 0, 1574, 38567 },
    { -26, 64, 0, 0, 2, 0, 255, 0, 0, 1575, 38568 },
    { -22, 81, 0, 0, 2, 0, 255, 0, 0, 1576, 38573 },
    { -2, 82, 0, 0, 2, 0, 255, 0, 0, 1577, 38574 },
    { -26, 64, 0, 0, 2, 0, 255, 0, 0, 1578, 38575 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1579, 38504 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1580, 38503 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1581, 38508 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1582, 38523 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1583, 38537 },
    { -51, 82, 0, 0, 1, 0, 255, 0, 0, 1584, 38596 },
    { 11, 78, 0, 0, 1, 1, 255, 0, 0, 1585, 38565 },
    { 8, 80, 0, 0, 1, 1, 255, 0, 0, 1586, 38564 },
    { 40, 61, 0, 0, 1, 0, 255, 0, 0, 1587, 38525 },
    { 36, 61, 0, 0, 1, 0, 255, 0, 0, 1588, 38524 },
    { 28, 65, 0, 0, 1, 0, 255, 0, 0, 1589, 38561 },
    { 29, 65, 0, 0, 1, 1, 255, 0, 0, 1590, 38558 },
    { 25, 67, 0, 0, 1, 1, 255, 0, 0, 1591, 38538 },
    { -63, 76, 0, 0, 1, 2, 255, 0, 0, 1592, 38570 },
    { -61, 54, 0, 0, 1, 2, 255, 0, 0, 1593, 38571 },
    { -41, 26, 0, 0, 1, 2, 255, 0, 0, 1594, 38574 },
    { -51, -4, 0, 0, 1, 2, 255, 0, 0, 1595, 38508 },
    { -40, 0, 0, 0, 1, 2, 255, 0, 0, 1596, 38561 },
    { -40, 0, 0, 0, 1, 2, 255, 0, 0, 1597, 38560 },
    { -50, 0, 0, 0, 1, 3, 255, 0, 0, 1598, 38559 },
    { -49, 0, 0, 0, 1, 3, 255, 0, 0, 1599, 38558 },
    { -57, -4, 0, 0, 1, 2, 255, 0, 0, 1600, 38520 },
    { -57, -4, 0, 0, 1, 2, 255, 0, 0, 1601, 38519 },
    { -57, -4, 0, 0, 1, 2, 255, 0, 0, 1602, 38518 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1603, 38522 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1604, 38521 },
    { 17, 86, 0, 0, 1, 0, 255, 0, 0, 1605, 38520 },
    { 31, 70, 0, 0, 1, 0, 255, 0, 0, 1606, 38519 },
    { 3, 83, 0, 0, 1, 0, 255, 0, 0, 1607, 38562 },
    { 17, 81, 0, 0, 1, 0, 255, 0, 0, 1608, 38568 },
    { -14, 61, 0, 0, 1, 1, 255, 0, 0, 1609, 38570 },
    { -12, 90, 0, 0, 1, 0, 255, 0, 0, 1610, 38503 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1611, 38504 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1612, 38505 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1613, 38506 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1614, 38507 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1615, 38508 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1616, 38509 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 1617, 38510 },
    { -44, 71, 0, 0, 1, 0, 255, 0, 0, 1618, 38501 },
    { -55, -4, 0, 0, 1, 0, 255, 0, 0, 1619, 38568 },
    { -45, -21, 0, 0, 1, 3, 255, 0, 0, 1620, 38562 },
    { 13, 2, 0, 0, 1, 1, 255, 0, 0, 1621, 38537 },
    { 20, 82, 0, 0, 2, 0, 255, 0, 0, 1622, 38504 },
    { -15, 79, 0, 0, 2, 0, 255, 0, 0, 1623, 38505 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 1624, 38506 },
    { -49, -14, 0, 0, 1, 0, 255, 0, 0, 1625, 38606 },
    { -5, -101, 0, 0, 1, 1, 255, 0, 0, 1626, 38587 },
    { -24, -85, 0, 0, 1, 1, 255, 0, 0, 1627, 38588 },
    { -24, -80, 0, 0, 1, 1, 255, 0, 0, 1628, 38589 },
    { 32, -43, 0, 0, 1, 1, 255, 0, 0, 1629, 38513 },
    { 7, -48, 0, 0, 1, 1, 255, 0, 0, 1630, 38515 },
    { -26, 66, 0, 0, 2, 2, 255, 0, 0, 1631, 38567 },
    { -34, 84, 0, 0, 1, 0, 255, 0, 0, 1632, 38539 },
    { -38, 83, 0, 0, 1, 0, 255, 0, 0, 1633, 38540 },
    { -40, 82, 0, 0, 1, 1, 255, 0, 0, 1634, 38524 },
    { -57, 75, 0, 0, 1, 2, 255, 0, 0, 1635, 38569 },
    { -49, -2, 0, 0, 1, 2, 255, 0, 0, 1636, 38565 },
    { -55, -1, 0, 0, 1, 2, 255, 0, 0, 1637, 38572 },
    { -55, -1, 0, 0, 1, 2, 255, 0, 0, 1638, 38571 },
    { 23, 45, 0, 0, 1, 0, 255, 0, 0, 1639, 38575 },
    { 40, 82, 0, 0, 1, 0, 255, 0, 0, 1640, 38524 },
    { 53, 80, 0, 0, 1, 3, 255, 0, 0, 1641, 38608 },
    { 43, 27, 0, 0, 2, 3, 255, 0, 0, 1642, 38575 },
    { 49, -2, 0, 0, 1, 3, 255, 0, 0, 1643, 38565 },
    { 55, -1, 0, 0, 1, 3, 255, 0, 0, 1644, 38572 },
    { -23, 45, 0, 0, 1, 1, 255, 0, 0, 1645, 38575 },
    { 56, 1, 0, 0, 1, 3, 255, 0, 0, 1646, 38571 },
    { -45, 83, 0, 0, 1, 0, 255, 0, 0, 1647, 38520 },
    { -42, 76, 0, 0, 1, 0, 255, 0, 0, 1648, 38516 },
    { -34, 49, 0, 0, 2, 3, 255, 0, 0, 1649, 38561 },
    { 8, 42, 0, 0, 2, 3, 255, 0, 0, 1650, 38580 },
    { 31, 53, 0, 0, 1, 3, 255, 0, 0, 1651, 38566 },
    { 38, 62, 0, 0, 1, 3, 255, 0, 0, 1652, 38568 },
    { 17, 96, 0, 0, 1, 0, 255, 0, 0, 1653, 38540 },
    { 9, 94, 0, 0, 1, 0, 255, 0, 0, 1654, 38579 },
    { 46, 5, 0, 0, 1, 3, 255, 0, 0, 1655, 38517 },
    { 46, 5, 0, 0, 1, 3, 255, 0, 0, 1656, 38515 },
    { 52, 15, 0, 0, 1, 3, 255, 0, 0, 1657, 38514 },
    { 52, 15, 0, 0, 1, 3, 255, 0, 0, 1658, 38513 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1659, 38506 },
    { -4, 91, 0, 0, 1, 0, 255, 0, 0, 1660, 38505 },
    { 2, 90, 0, 0, 1, 1, 255, 0, 0, 1661, 38504 },
    { -5, 87, 0, 0, 1, 1, 255, 0, 0, 1662, 38505 },
    { -5, 86, 0, 0, 1, 1, 255, 0, 0, 1663, 38506 },
    { -3, 84, 0, 0, 1, 1, 255, 0, 0, 1664, 38508 },
    { -10, 87, 0, 0, 1, 1, 255, 0, 0, 1665, 38509 },
    { -7, 92, 0, 0, 1, 1, 255, 0, 0, 1666, 38510 },
    { 15, 100, 0, 0, 1, 1, 255, 0, 0, 1667, 38511 },
    { -57, 79, 0, 0, 1, 0, 255, 0, 0, 1668, 38572 },
    { -63, 73, 0, 0, 1, 0, 255, 0, 0, 1669, 38571 },
    { -51, 63, 0, 0, 2, 0, 255, 0, 0, 1670, 38569 },
    { -61, 52, 0, 0, 2, 0, 255, 0, 0, 1671, 38568 },
    { -13, 93, 0, 0, 1, 0, 255, 0, 0, 1672, 38507 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 1673, 38508 },
    { -12, 88, 0, 0, 1, 0, 255, 0, 0, 1674, 38507 },
    { -12, 88, 0, 0, 1, 0, 255, 0, 0, 1675, 38506 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 1676, 38505 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 1677, 38504 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 1678, 38503 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 1679, 38502 },
    { -25, 77, 0, 0, 1, 0, 255, 0, 0, 1680, 38501 },
    { -25, 77, 0, 0, 1, 0, 255, 0, 0, 1681, 38502 },
    { -23, 81, 0, 0, 1, 0, 255, 0, 0, 1682, 38503 },
    { -23, 81, 0, 0, 1, 0, 255, 0, 0, 1683, 38505 },
    { -44, 83, 0, 0, 1, 1, 255, 0, 0, 1684, 38525 },
    { -59, 53, 0, 0, 2, 0, 255, 0, 0, 1685, 38604 },
    { -42, 26, 0, 0, 2, 2, 255, 0, 0, 1686, 38575 },
    { 19, 86, 0, 0, 1, 0, 255, 0, 0, 1687, 38565 },
    { -31, 25, 0, 0, 2, 0, 255, 0, 0, 1688, 38590 },
    { -23, 30, 0, 0, 2, 3, 255, 0, 0, 1689, 38560 },
    { -17, 19, 0, 0, 1, 0, 255, 0, 0, 1690, 38614 },
    { -34, -65, 0, 0, 1, 3, 255, 0, 0, 1691, 38522 },
    { 32, -45, 0, 0, 2, 3, 255, 0, 0, 1692, 38524 },
    { 47, -6, 0, 0, 1, 3, 255, 0, 0, 1693, 38526 },
    { 54, 63, 0, 0, 1, 3, 255, 0, 0, 1694, 38528 },
    { 59, 75, 0, 0, 1, 1, 255, 0, 0, 1695, 38593 },
    { 65, 76, 0, 0, 1, 1, 255, 0, 0, 1696, 38597 },
    { 66, 76, 0, 0, 1, 1, 255, 0, 0, 1697, 38599 },
    { 59, 78, 0, 0, 1, 3, 255, 0, 0, 1698, 38585 },
    { 60, 76, 0, 0, 1, 1, 255, 0, 0, 1699, 38533 },
    { 32, 20, 0, 0, 1, 2, 255, 0, 0, 1700, 38579 },
    { 50, -2, 0, 0, 1, 2, 255, 0, 0, 1701, 38560 },
    { 45, -4, 0, 0, 1, 2, 255, 0, 0, 1702, 38558 },
    { 54, 42, 0, 0, 2, 3, 255, 0, 0, 1703, 38574 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 1704, 38540 },
    { 19, 87, 0, 0, 1, 0, 255, 0, 0, 1705, 38537 },
    { -5, 85, 0, 0, 1, 0, 255, 0, 0, 1706, 38522 },
    { -10, 86, 0, 0, 1, 0, 255, 0, 0, 1707, 38565 },
    { -9, 80, 0, 0, 1, 0, 255, 0, 0, 1708, 38575 },
    { -23, 81, 0, 0, 2, 0, 255, 0, 0, 1709, 38570 },
    { -26, 64, 0, 0, 2, 0, 255, 0, 0, 1710, 38567 },
    { -23, 81, 0, 0, 2, 0, 255, 0, 0, 1711, 38568 },
    { -9, 80, 0, 0, 1, 0, 255, 0, 0, 1712, 38571 },
    { -2, 82, 0, 0, 1, 0, 255, 0, 0, 1713, 38574 },
    { -3, 85, 0, 0, 1, 0, 255, 0, 0, 1714, 38576 },
    { 57, -1, 0, 0, 1, 3, 255, 0, 0, 1715, 38572 },
    { 5, 105, 0, 0, 1, 0, 255, 0, 0, 1716, 38540 },
    { 60, 72, 0, 0, 2, 1, 255, 0, 0, 1717, 38570 },
    { 51, 63, 0, 0, 2, 1, 255, 0, 0, 1718, 38569 },
    { 51, 63, 0, 0, 2, 1, 255, 0, 0, 1719, 38568 },
    { 7, 93, 0, 0, 1, 0, 255, 0, 0, 1720, 38540 },
    { 10, 87, 0, 0, 1, 0, 255, 0, 0, 1721, 38537 },
    { -7, 53, 0, 0, 1, 0, 255, 0, 0, 1722, 38534 },
    { 16, 47, 0, 0, 1, 0, 255, 0, 0, 1723, 38533 },
    { 51, 52, 0, 0, 1, 1, 255, 0, 0, 1724, 38565 },
    { 15, 87, 0, 0, 1, 1, 255, 0, 0, 1725, 38537 },
    { 44, 70, 0, 0, 1, 1, 255, 0, 0, 1726, 38548 },
    { 11, 85, 0, 0, 1, 1, 255, 0, 0, 1727, 38565 },
    { 18, 84, 0, 0, 2, 1, 255, 0, 0, 1728, 38522 },
    { 31, 73, 0, 0, 2, 1, 255, 0, 0, 1729, 38523 },
    { 25, 84, 0, 0, 2, 1, 255, 0, 0, 1730, 38524 },
    { -6, 105, 0, 0, 2, 1, 255, 0, 0, 1731, 38525 },
    { 7, 52, 0, 0, 2, 1, 255, 0, 0, 1732, 38532 },
    { -45, 0, 0, 0, 2, 1, 255, 0, 0, 1733, 38591 },
    { -23, -41, 0, 0, 2, 1, 255, 0, 0, 1734, 38587 },
    { 2, -48, 0, 0, 2, 1, 255, 0, 0, 1735, 38589 },
    { 20, -52, 0, 0, 2, 3, 255, 0, 0, 1736, 38566 },
    { 24, -44, 0, 0, 2, 3, 255, 0, 0, 1737, 38567 },
    { 46, 0, 0, 0, 1, 0, 255, 0, 0, 1738, 38534 },
    { 30, -43, 0, 0, 1, 3, 255, 0, 0, 1739, 38571 },
    { 5, -48, 0, 0, 1, 3, 255, 0, 0, 1740, 38574 },
    { -13, -51, 0, 0, 1, 3, 255, 0, 0, 1741, 38575 },
    { -34, -61, 0, 0, 1, 1, 255, 0, 0, 1742, 38522 },
    { -23, -51, 0, 0, 1, 3, 255, 0, 0, 1743, 38523 },
    { -34, -61, 0, 0, 1, 1, 255, 0, 0, 1744, 38524 },
    { -25, -89, 0, 0, 1, 3, 255, 0, 0, 1745, 38525 },
    { 57, 0, 0, 0, 1, 1, 255, 0, 0, 1746, 38527 },
    { -7, 53, 0, 0, 1, 0, 255, 0, 0, 1747, 38589 },
    { 34, 65, 0, 0, 1, 0, 255, 0, 0, 1748, 38586 },
    { 24, 51, 0, 0, 1, 0, 255, 0, 0, 1749, 38585 },
    { 39, 0, 0, 0, 1, 0, 255, 0, 0, 1750, 38591 },
    { 45, -4, 0, 0, 1, 2, 255, 0, 0, 1751, 38538 },
    { 46, -4, 0, 0, 1, 2, 255, 0, 0, 1752, 38535 },
    { 46, -4, 0, 0, 1, 2, 255, 0, 0, 1753, 38533 },
    { 10, 77, 0, 0, 1, 1, 255, 0, 0, 1754, 38581 },
    { 10, 77, 0, 0, 1, 1, 255, 0, 0, 1755, 38582 },
    { 49, 58, 0, 0, 1, 1, 255, 0, 0, 1756, 38567 },
    { 45, 58, 0, 0, 1, 1, 255, 0, 0, 1757, 38568 },
    { 33, 62, 0, 0, 1, 1, 255, 0, 0, 1758, 38569 },
    { 32, 62, 0, 0, 1, 1, 255, 0, 0, 1759, 38570 },
    { 25, 67, 0, 0, 1, 1, 255, 0, 0, 1760, 38539 },
    { -64, 76, 0, 0, 1, 2, 255, 0, 0, 1761, 38569 },
    { -61, 54, 0, 0, 1, 2, 255, 0, 0, 1762, 38570 },
    { -43, 26, 0, 0, 1, 2, 255, 0, 0, 1763, 38572 },
    { -49, -1, 0, 0, 1, 2, 255, 0, 0, 1764, 38576 },
    { -49, -1, 0, 0, 1, 2, 255, 0, 0, 1765, 38577 },
    { -49, -1, 0, 0, 1, 2, 255, 0, 0, 1766, 38579 },
    { -55, -1, 0, 0, 1, 2, 255, 0, 0, 1767, 38580 },
    { 31, -21, 0, 0, 1, 2, 255, 0, 0, 1768, 38526 },
    { 29, -16, 0, 0, 1, 2, 255, 0, 0, 1769, 38568 },
    { 37, -6, 0, 0, 1, 2, 255, 0, 0, 1770, 38567 },
    { 47, -14, 0, 0, 1, 0, 255, 0, 0, 1771, 38497 },
    { 24, -80, 0, 0, 1, 0, 255, 0, 0, 1772, 38499 },
    { 24, 68, 0, 0, 1, 0, 255, 0, 0, 1773, 38521 },
    { 24, 68, 0, 0, 1, 0, 255, 0, 0, 1774, 38522 },
    { 24, 68, 0, 0, 1, 0, 255, 0, 0, 1775, 38523 },
    { 24, 68, 0, 0, 1, 0, 255, 0, 0, 1776, 38524 },
    { -5, 105, 0, 0, 1, 1, 255, 0, 0, 1777, 38524 },
    { -21, 101, 0, 0, 2, 1, 255, 0, 0, 1778, 38560 },
    { -57, 75, 0, 0, 1, 0, 255, 0, 0, 1779, 38603 },
    { -56, 74, 0, 0, 1, 0, 255, 0, 0, 1780, 38600 },
    { -2, 89, 0, 0, 1, 0, 255, 0, 0, 1781, 38505 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 1782, 38504 },
    { 3, 90, 0, 0, 1, 0, 255, 0, 0, 1783, 38505 },
    { -5, 88, 0, 0, 1, 0, 255, 0, 0, 1784, 38504 },
    { -26, 79, 0, 0, 1, 0, 255, 0, 0, 1785, 38569 },
    { -26, 64, 0, 0, 2, 0, 255, 0, 0, 1786, 38567 },
    { -34, -65, 0, 0, 1, 3, 255, 0, 0, 1787, 38590 },
    { 32, -46, 0, 0, 1, 3, 255, 0, 0, 1788, 38588 },
    { 24, 84, 0, 0, 1, 0, 255, 0, 0, 1789, 38589 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 1790, 38576 },
    { 24, 87, 0, 0, 2, 0, 255, 0, 0, 1791, 38541 },
    { 3, 83, 0, 0, 2, 0, 255, 0, 0, 1792, 38542 },
    { 18, 80, 0, 0, 2, 0, 255, 0, 0, 1793, 38543 },
    { 22, 82, 0, 0, 2, 0, 255, 0, 0, 1794, 38544 },
    { 34, 92, 0, 0, 2, 1, 255, 0, 0, 1795, 38575 },
    { 2, 101, 0, 0, 1, 1, 255, 0, 0, 1796, 38576 },
    { -20, 86, 0, 0, 1, 2, 255, 0, 0, 1797, 38615 },
    { -20, 86, 0, 0, 1, 2, 255, 0, 0, 1798, 38612 },
    { 3, 101, 0, 0, 1, 1, 255, 0, 0, 1799, 38577 },
    { -20, 86, 0, 0, 1, 2, 255, 0, 0, 1800, 38614 },
    { -20, 86, 0, 0, 1, 2, 255, 0, 0, 1801, 38613 },
    { 6, 93, 0, 0, 1, 0, 255, 0, 0, 1802, 38521 },
    { 6, 93, 0, 0, 1, 0, 255, 0, 0, 1803, 38522 },
    { 10, 84, 0, 0, 1, 0, 255, 0, 0, 1804, 38520 },
    { 10, 84, 0, 0, 1, 0, 255, 0, 0, 1805, 38519 },
    { -18, 75, 0, 0, 1, 0, 255, 0, 0, 1806, 38566 },
    { -22, 54, 0, 0, 1, 0, 255, 0, 0, 1807, 38567 },
    { -22, 53, 0, 0, 2, 0, 255, 0, 0, 1808, 38568 },
    { -22, 53, 0, 0, 2, 0, 255, 0, 0, 1809, 38569 },
    { -22, 53, 0, 0, 2, 0, 255, 0, 0, 1810, 38570 },
    { -30, 79, 0, 0, 1, 0, 255, 0, 0, 1811, 38538 },
    { -21, 66, 0, 0, 1, 0, 255, 0, 0, 1812, 38537 },
    { -23, 64, 0, 0, 1, 0, 255, 0, 0, 1813, 38536 },
    { -23, 64, 0, 0, 1, 0, 255, 0, 0, 1814, 38535 },
    { -32, 46, 0, 0, 1, 0, 255, 0, 0, 1815, 38534 },
    { -7, 53, 0, 0, 1, 0, 255, 0, 0, 1816, 38533 },
    { 11, 54, 0, 0, 1, 0, 255, 0, 0, 1817, 38532 },
    { 31, 21, 0, 0, 1, 0, 255, 0, 0, 1818, 38536 },
    { 31, 21, 0, 0, 1, 0, 255, 0, 0, 1819, 38537 },
    { 14, 88, 0, 0, 1, 0, 255, 0, 0, 1820, 38503 },
    { 15, 81, 0, 0, 1, 0, 255, 0, 0, 1821, 38502 },
    { -28, 76, 0, 0, 1, 0, 255, 0, 0, 1822, 38575 },
    { -24, 65, 0, 0, 1, 0, 255, 0, 0, 1823, 38565 },
    { -21, 66, 0, 0, 1, 0, 255, 0, 0, 1824, 38575 },
    { 7, 101, 0, 0, 1, 0, 255, 0, 0, 1825, 38577 },
    { 16, 81, 0, 0, 1, 0, 255, 0, 0, 1826, 38597 },
    { 18, 72, 0, 0, 1, 0, 255, 0, 0, 1827, 38523 },
    { 18, 70, 0, 0, 1, 0, 255, 0, 0, 1828, 38524 },
    { 18, 70, 0, 0, 1, 0, 255, 0, 0, 1829, 38525 },
    { 34, -64, 0, 0, 1, 2, 255, 0, 0, 1830, 38525 },
    { 24, -82, 0, 0, 1, 2, 255, 0, 0, 1831, 38523 },
    { -34, 66, 0, 0, 1, 0, 255, 0, 0, 1832, 38566 },
    { -20, 19, 0, 0, 1, 0, 255, 0, 0, 1833, 38603 },
    { 2, 12, 0, 0, 1, 0, 255, 0, 0, 1834, 38607 },
    { 45, -1, 0, 0, 1, 0, 255, 0, 0, 1835, 38611 },
    { -17, -51, 0, 0, 1, 0, 255, 0, 0, 1836, 38604 },
    { 14, -63, 0, 0, 1, 0, 255, 0, 0, 1837, 38605 },
    { 14, -63, 0, 0, 1, 0, 255, 0, 0, 1838, 38607 },
    { 20, -81, 0, 0, 1, 0, 255, 0, 0, 1839, 38611 },
    { 20, -81, 0, 0, 1, 0, 255, 0, 0, 1840, 38611 },
    { 7, 3, 0, 0, 1, 0, 255, 0, 0, 1841, 38607 },
    { 44, -1, 0, 0, 1, 0, 255, 0, 0, 1842, 38610 },
    { 52, -1, 0, 0, 1, 0, 255, 0, 0, 1843, 38609 },
    { 36, 19, 0, 0, 1, 0, 255, 0, 0, 1844, 38611 },
    { 33, -101, 0, 0, 1, 2, 255, 0, 0, 1845, 38559 },
    { 31, -100, 0, 0, 1, 2, 255, 0, 0, 1846, 38560 },
    { 33, -94, 0, 0, 1, 2, 255, 0, 0, 1847, 38561 },
    { 25, -85, 0, 0, 1, 2, 255, 0, 0, 1848, 38560 },
    { 27, -72, 0, 0, 1, 0, 255, 0, 0, 1849, 38585 },
    { 30, -63, 0, 0, 1, 0, 255, 0, 0, 1850, 38613 },
    { 38, -51, 0, 0, 1, 0, 255, 0, 0, 1851, 38614 },
    { 36, 19, 0, 0, 1, 0, 255, 0, 0, 1852, 38611 },
    { 52, -2, 0, 0, 1, 3, 255, 0, 0, 1853, 38573 },
    { -50, 0, 0, 0, 1, 0, 255, 0, 0, 1854, 38585 },
    { -56, 0, 0, 0, 1, 0, 255, 0, 0, 1855, 38591 },
    { -57, -4, 0, 0, 1, 2, 255, 0, 0, 1856, 38596 },
    { -54, -1, 0, 0, 1, 2, 255, 0, 0, 1857, 38574 },
    { -54, -1, 0, 0, 1, 2, 255, 0, 0, 1858, 38573 },
    { -56, -2, 0, 0, 1, 2, 255, 0, 0, 1859, 38572 },
    { -55, 0, 0, 0, 1, 2, 255, 0, 0, 1860, 38571 },
    { -39, 0, 0, 0, 1, 1, 255, 0, 0, 1861, 38556 },
    { -33, 1, 0, 0, 1, 1, 255, 0, 0, 1862, 38555 },
    { -35, 1, 0, 0, 1, 1, 255, 0, 0, 1863, 38554 },
    { -48, -1, 0, 0, 1, 1, 255, 0, 0, 1864, 38553 },
    { -47, -1, 0, 0, 1, 1, 255, 0, 0, 1865, 38552 },
    { -53, -1, 0, 0, 1, 0, 255, 0, 0, 1866, 38549 },
    { -51, 3, 0, 0, 1, 0, 255, 0, 0, 1867, 38548 },
    { -49, 2, 0, 0, 1, 0, 255, 0, 0, 1868, 38549 },
    { -50, 1, 0, 0, 1, 0, 255, 0, 0, 1869, 38549 },
    { -13, 93, 0, 0, 1, 0, 255, 0, 0, 1870, 38539 },
    { -13, 89, 0, 0, 1, 0, 255, 0, 0, 1871, 38540 },
    { -13, 81, 0, 0, 1, 0, 255, 0, 0, 1872, 38578 },
    { 15, 56, 0, 0, 1, 0, 255, 0, 0, 1873, 38539 },
    { 5, 58, 0, 0, 1, 0, 255, 0, 0, 1874, 38540 },
    { -4, 61, 0, 0, 1, 0, 255, 0, 0, 1875, 38510 },
    { -17, 59, 0, 0, 1, 0, 255, 0, 0, 1876, 38565 },
    { -37, 46, 0, 0, 1, 0, 255, 0, 0, 1877, 38569 },
    { -41, 40, 0, 0, 1, 0, 255, 0, 0, 1878, 38568 },
    { -48, 27, 0, 0, 1, 0, 255, 0, 0, 1879, 38567 },
    { -30, 11, 0, 0, 2, 3, 255, 0, 0, 1880, 38539 },
    { -22, 3, 0, 0, 2, 3, 255, 0, 0, 1881, 38540 },
    { -6, -1, 0, 0, 2, 3, 255, 0, 0, 1882, 38509 },
    { 8, 1, 0, 0, 2, 3, 255, 0, 0, 1883, 38565 },
    { 19, 6, 0, 0, 1, 3, 255, 0, 0, 1884, 38571 },
    { 32, 14, 0, 0, 1, 3, 255, 0, 0, 1885, 38566 },
    { 38, 23, 0, 0, 1, 3, 255, 0, 0, 1886, 38567 },
    { 29, 28, 0, 0, 1, 0, 255, 0, 0, 1887, 38562 },
    { 28, 46, 0, 0, 1, 0, 255, 0, 0, 1888, 38561 },
    { 6, 59, 0, 0, 1, 1, 255, 0, 0, 1889, 38565 },
    { 16, 58, 0, 0, 1, 1, 255, 0, 0, 1890, 38540 },
    { 26, 56, 0, 0, 1, 1, 255, 0, 0, 1891, 38503 },
    { 29, 42, 0, 0, 1, 2, 255, 0, 0, 1892, 38541 },
    { 24, 25, 0, 0, 1, 2, 255, 0, 0, 1893, 38563 },
    { 26, 21, 0, 0, 1, 0, 255, 0, 0, 1894, 38585 },
    { 22, 16, 0, 0, 1, 0, 255, 0, 0, 1895, 38585 },
    { 10, 7, 0, 0, 1, 0, 255, 0, 0, 1896, 38585 },
    { 0, 4, 0, 0, 1, 0, 255, 0, 0, 1897, 38586 },
    { -17, 3, 0, 0, 1, 0, 255, 0, 0, 1898, 38586 },
    { -32, 6, 0, 0, 1, 0, 255, 0, 0, 1899, 38587 },
    { -38, 13, 0, 0, 1, 2, 255, 0, 0, 1900, 38566 },
    { -43, 30, 0, 0, 1, 1, 255, 0, 0, 1901, 38561 },
    { -38, 44, 0, 0, 1, 1, 255, 0, 0, 1902, 38564 },
    { -29, 47, 0, 0, 1, 1, 255, 0, 0, 1903, 38565 },
    { -8, 59, 0, 0, 1, 1, 255, 0, 0, 1904, 38566 },
    { -6, 97, 0, 0, 1, 0, 255, 0, 0, 1905, 38501 },
    { -6, 97, 0, 0, 1, 0, 255, 0, 0, 1906, 38502 },
    { -10, 100, 0, 0, 1, 0, 255, 0, 0, 1907, 38520 },
    { -10, 100, 0, 0, 1, 0, 255, 0, 0, 1908, 38521 },
    { -9, 103, 0, 0, 1, 0, 255, 0, 0, 1909, 38506 },
    { -10, 105, 0, 0, 1, 0, 255, 0, 0, 1910, 38540 },
    { -6, 103, 0, 0, 1, 0, 255, 0, 0, 1911, 38539 },
    { -2, 106, 0, 0, 1, 0, 255, 0, 0, 1912, 38538 },
    { 21, 61, 0, 0, 1, 2, 255, 0, 0, 1913, 38539 },
    { 11, 47, 0, 0, 1, 0, 255, 0, 0, 1914, 38569 },
    { 50, 2, 0, 0, 1, 1, 255, 0, 0, 1915, 38549 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 1916, 38610 },
    { 3, 93, 0, 0, 1, 0, 255, 0, 0, 1917, 38614 },
    { 19, 88, 0, 0, 1, 0, 255, 0, 0, 1918, 38562 },
    { -18, 94, 0, 0, 1, 0, 255, 0, 0, 1919, 38520 },
    { -9, 90, 0, 0, 1, 0, 255, 0, 0, 1920, 38520 },
    { -14, 82, 0, 0, 1, 0, 255, 0, 0, 1921, 38566 },
    { -19, 94, 0, 0, 1, 0, 255, 0, 0, 1922, 38523 },
    { -26, 98, 0, 0, 1, 2, 255, 0, 0, 1923, 38585 },
    { -31, 93, 0, 0, 1, 0, 255, 0, 0, 1924, 38565 },
    { -35, 66, 0, 0, 1, 0, 255, 0, 0, 1925, 38565 },
    { -21, 101, 0, 0, 2, 3, 255, 0, 0, 1926, 38590 },
    { 47, 3, 0, 0, 2, 0, 255, 0, 0, 1927, 38511 },
    { 36, 4, 0, 0, 2, 0, 255, 0, 0, 1928, 38510 },
    { 31, 2, 0, 0, 2, 0, 255, 0, 0, 1929, 38511 },
    { 33, 2, 0, 0, 2, 0, 255, 0, 0, 1930, 38510 },
    { 31, 2, 0, 0, 2, 0, 255, 0, 0, 1931, 38511 },
    { 53, -63, 0, 0, 1, 1, 255, 0, 0, 1932, 38521 },
    { 49, -81, 0, 0, 1, 1, 255, 0, 0, 1933, 38567 },
    { -34, -65, 0, 0, 1, 2, 255, 0, 0, 1934, 38576 },
    { 47, -2, 0, 0, 1, 0, 255, 0, 0, 1935, 38592 },
    { -10, 90, 0, 0, 1, 0, 255, 0, 0, 1936, 38520 },
    { -7, 101, 0, 0, 1, 0, 255, 0, 0, 1937, 38540 },
    { -12, 99, 0, 0, 1, 0, 255, 0, 0, 1938, 38521 },
    { -13, 100, 0, 0, 1, 0, 255, 0, 0, 1939, 38507 },
    { -13, 88, 0, 0, 1, 0, 255, 0, 0, 1940, 38520 },
    { 14, 77, 0, 0, 1, 2, 255, 0, 0, 1941, 38585 },
    { -10, 96, 0, 0, 1, 0, 255, 0, 0, 1942, 38579 },
    { -5, 98, 0, 0, 1, 0, 255, 0, 0, 1943, 38578 },
    { 15, 84, 0, 0, 1, 2, 255, 0, 0, 1944, 38590 },
    { -4, 98, 0, 0, 1, 0, 255, 0, 0, 1945, 38576 },
    { 17, 80, 0, 0, 1, 0, 255, 0, 0, 1946, 38579 },
    { 20, 85, 0, 0, 1, 0, 255, 0, 0, 1947, 38576 },
    { 23, 78, 0, 0, 1, 0, 255, 0, 0, 1948, 38521 },
    { -32, 81, 0, 0, 1, 1, 255, 0, 0, 1949, 38520 },
    { -17, 83, 0, 0, 1, 1, 255, 0, 0, 1950, 38562 },
    { -32, 73, 0, 0, 1, 1, 255, 0, 0, 1951, 38504 },
    { -28, 92, 0, 0, 1, 1, 255, 0, 0, 1952, 38573 },
    { -32, 69, 0, 0, 1, 1, 255, 0, 0, 1953, 38571 },
    { 27, 98, 0, 0, 1, 1, 255, 0, 0, 1954, 38574 },
    { 13, 82, 0, 0, 1, 0, 255, 0, 0, 1955, 38535 },
    { -25, 81, 0, 0, 1, 2, 255, 0, 0, 1956, 38571 },
    { -19, 81, 0, 0, 1, 1, 255, 0, 0, 1957, 38562 },
    { -27, 94, 0, 0, 1, 3, 255, 0, 0, 1958, 38568 },
    { 18, 91, 0, 0, 1, 3, 255, 0, 0, 1959, 38569 },
    { 5, 87, 0, 0, 1, 0, 255, 0, 0, 1960, 38536 },
    { 18, 72, 0, 0, 1, 0, 255, 0, 0, 1961, 38589 },
    { 12, 92, 0, 0, 1, 0, 255, 0, 0, 1962, 38575 },
    { -35, 67, 0, 0, 1, 0, 255, 0, 0, 1963, 38588 },
    { -54, -9, 0, 0, 1, 0, 255, 0, 0, 1964, 38586 },
    { -56, -82, 0, 0, 1, 0, 255, 0, 0, 1965, 38585 },
    { -1, -101, 0, 0, 1, 1, 255, 0, 0, 1966, 38590 },
    { 3, -75, 0, 0, 1, 1, 255, 0, 0, 1967, 38585 },
    { 15, -51, 0, 0, 1, 1, 255, 0, 0, 1968, 38590 },
    { 52, 55, 0, 0, 1, 0, 255, 0, 0, 1969, 38585 },
    { 31, 1, 0, 0, 1, 0, 255, 0, 0, 1970, 38590 },
    { 48, 0, 0, 0, 1, 1, 255, 0, 0, 1971, 38591 },
    { 48, 0, 0, 0, 1, 1, 255, 0, 0, 1972, 38592 },
    { 51, 15, 0, 0, 1, 1, 255, 0, 0, 1973, 38568 },
    { 56, 15, 0, 0, 1, 1, 255, 0, 0, 1974, 38567 },
    { 52, -4, 0, 0, 1, 1, 255, 0, 0, 1975, 38569 },
    { 49, -5, 0, 0, 1, 3, 255, 0, 0, 1976, 38546 },
    { 53, -4, 0, 0, 1, 3, 255, 0, 0, 1977, 38547 },
    { -11, 99, 0, 0, 1, 0, 255, 0, 0, 1978, 38512 },
    { 1, 91, 0, 0, 1, 0, 255, 0, 0, 1979, 38521 },
    { 25, 84, 0, 0, 1, 0, 255, 0, 0, 1980, 38520 },
    { 35, 5, 0, 0, 1, 2, 255, 0, 0, 1981, 38585 },
    { 17, 44, 0, 0, 1, 0, 255, 0, 0, 1982, 38572 },
    { 13, 51, 0, 0, 1, 0, 255, 0, 0, 1983, 38569 },
    { 36, 7, 0, 0, 1, 2, 255, 0, 0, 1984, 38565 },
    { 40, -4, 0, 0, 1, 2, 255, 0, 0, 1985, 38564 },
    { 43, 13, 0, 0, 1, 0, 255, 0, 0, 1986, 38590 },
    { 31, 0, 0, 0, 1, 0, 255, 0, 0, 1987, 38593 },
    { 37, -1, 0, 0, 1, 0, 255, 0, 0, 1988, 38595 },
    { 43, 8, 0, 0, 1, 2, 255, 0, 0, 1989, 38591 },
    { 42, -3, 0, 0, 1, 3, 255, 0, 0, 1990, 38590 },
    { 61, 72, 0, 0, 1, 3, 255, 0, 0, 1991, 38586 },
    { 42, -3, 0, 0, 1, 3, 255, 0, 0, 1992, 38585 },
    { 41, -3, 0, 0, 1, 3, 255, 0, 0, 1993, 38587 },
    { 55, 43, 0, 0, 1, 1, 255, 0, 0, 1994, 38601 },
    { 13, 82, 0, 0, 1, 0, 255, 0, 0, 1978, 38512 },
    { 23, 80, 0, 0, 1, 0, 255, 0, 0, 1979, 38505 },
    { 14, 81, 0, 0, 1, 0, 255, 0, 0, 1980, 38507 },
    { 5, 87, 0, 0, 1, 0, 255, 0, 0, 1981, 38506 },
    { 5, 105, 0, 0, 1, 0, 255, 0, 0, 1982, 38539 },
    { -25, 67, 0, 0, 1, 0, 255, 0, 0, 1983, 38537 },
    { 13, 64, 0, 0, 1, 1, 255, 0, 0, 1984, 38569 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 2002, 11758 },
    { -35, 67, 0, 0, 1, 2, 255, 0, 0, 2003, 38560 },
    { -17, 27, 0, 0, 1, 3, 255, 0, 0, 2004, 38524 },
    { 3, 74, 0, 0, 1, 1, 255, 0, 0, 2005, 38593 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 2006, 38510 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 2007, 38508 },
    { -9, 90, 0, 0, 1, 0, 255, 0, 0, 2008, 38518 },
    { -15, 85, 0, 0, 1, 0, 255, 0, 0, 2009, 38519 },
    { -15, 85, 0, 0, 1, 0, 255, 0, 0, 2010, 38520 },
    { -9, 90, 0, 0, 1, 0, 255, 0, 0, 2011, 38540 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 2012, 38537 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 2013, 38538 },
    { 21, 82, 0, 0, 1, 1, 255, 0, 0, 2014, 38537 },
    { 34, 81, 0, 0, 1, 1, 255, 0, 0, 2015, 38539 },
    { 20, 80, 0, 0, 1, 0, 255, 0, 0, 2016, 38541 },
    { 24, 68, 0, 0, 1, 3, 255, 0, 0, 2017, 38610 },
    { 23, 70, 0, 0, 1, 3, 255, 0, 0, 2018, 38609 },
    { 21, 80, 0, 0, 1, 3, 255, 0, 0, 2019, 38612 },
    { 19, 85, 0, 0, 1, 3, 255, 0, 0, 2020, 38613 },
    { 21, 82, 0, 0, 1, 1, 255, 0, 0, 2021, 38560 },
    { -2, 101, 0, 0, 1, 0, 255, 0, 0, 2022, 38561 },
    { -2, 88, 0, 0, 1, 0, 255, 0, 0, 2023, 38562 },
    { 2, 91, 0, 0, 1, 0, 255, 0, 0, 2024, 38540 },
    { 35, 65, 0, 0, 1, 0, 255, 0, 0, 2025, 38563 },
    { 42, 27, 0, 0, 1, 3, 255, 0, 0, 2026, 38575 },
    { 48, -1, 0, 0, 1, 3, 255, 0, 0, 2027, 38576 },
    { 54, -1, 0, 0, 1, 3, 255, 0, 0, 2028, 38575 },
    { 54, -1, 0, 0, 1, 3, 255, 0, 0, 2029, 38574 },
    { 56, -1, 0, 0, 1, 3, 255, 0, 0, 2030, 38572 },
    { 56, -1, 0, 0, 1, 3, 255, 0, 0, 2031, 38572 },
    { 56, -3, 0, 0, 1, 3, 255, 0, 0, 2032, 38571 },
    { 55, 0, 0, 0, 1, 3, 255, 0, 0, 2033, 38570 },
    { 48, -4, 0, 0, 1, 3, 255, 0, 0, 2034, 38496 },
    { 42, -3, 0, 0, 1, 3, 255, 0, 0, 2035, 38498 },
    { 49, 15, 0, 0, 1, 3, 255, 0, 0, 2036, 38606 },
    { 41, 18, 0, 0, 1, 0, 255, 0, 0, 2037, 38537 },
    { 42, 4, 0, 0, 1, 3, 255, 0, 0, 2038, 38548 },
    { 54, 1, 0, 0, 1, 3, 255, 0, 0, 2039, 38549 },
    { 48, -1, 0, 0, 1, 0, 255, 0, 0, 2040, 38557 },
    { 51, 0, 0, 0, 1, 0, 255, 0, 0, 2041, 38541 },
    { 28, 77, 0, 0, 1, 3, 255, 0, 0, 2042, 38590 },
    { 9, 95, 0, 0, 1, 0, 255, 0, 0, 2043, 38503 },
    { -44, -24, 0, 0, 1, 0, 255, 0, 0, 2044, 38502 },
    { 10, 95, 0, 0, 1, 0, 255, 0, 0, 2045, 38501 },
    { 10, 91, 0, 0, 1, 0, 255, 0, 0, 2046, 38541 },
    { 25, 76, 0, 0, 1, 1, 255, 0, 0, 2047, 38604 },
    { 15, 64, 0, 0, 1, 0, 255, 0, 0, 2048, 38565 },
    { 29, 73, 0, 0, 1, 3, 255, 0, 0, 2049, 38567 },
    { 32, -80, 0, 0, 1, 3, 255, 0, 0, 2050, 38569 },
    { -51, 0, 0, 0, 1, 0, 255, 0, 0, 2051, 38585 },
    { 56, 0, 0, 0, 1, 1, 255, 0, 0, 2052, 38591 },
    { 57, -4, 0, 0, 1, 3, 255, 0, 0, 2053, 38596 },
    { 54, -1, 0, 0, 1, 3, 255, 0, 0, 2054, 38574 },
    { 5, 92, 0, 0, 1, 0, 255, 0, 0, 2055, 38508 },
    { 1, 90, 0, 0, 1, 0, 255, 0, 0, 2056, 38521 },
    { 9, 95, 0, 0, 1, 0, 255, 0, 0, 2057, 38522 },
    { 9, 95, 0, 0, 1, 0, 255, 0, 0, 2058, 38508 },
    { -30, 79, 0, 0, 1, 1, 255, 0, 0, 2059, 38521 },
    { -25, 66, 0, 0, 1, 0, 255, 0, 0, 2060, 38506 },
    { -21, 74, 0, 0, 1, 1, 255, 0, 0, 2061, 38523 },
    { -15, 93, 0, 0, 1, 0, 255, 0, 0, 2062, 38564 },
    { -29, 77, 0, 0, 1, 0, 255, 0, 0, 2063, 38565 },
    { 11, 92, 0, 0, 1, 0, 255, 0, 0, 2064, 38566 },
    { -34, 65, 0, 0, 1, 0, 255, 0, 0, 2065, 38567 },
    { -22, 18, 0, 0, 1, 2, 255, 0, 0, 2066, 38565 },
    { 0, 6, 0, 0, 2, 0, 255, 0, 0, 2067, 38585 },
    { 19, 2, 0, 0, 2, 1, 255, 0, 0, 2068, 38590 },
    { 5, 27, 0, 0, 1, 0, 255, 0, 0, 2069, 38586 },
    { 0, 7, 0, 0, 1, 1, 255, 0, 0, 2070, 38591 },
    { 36, 68, 0, 0, 1, 1, 255, 0, 0, 2071, 38593 },
    { 58, -4, 0, 0, 1, 3, 255, 0, 0, 2072, 38519 },
    { 9, 87, 0, 0, 1, 0, 255, 0, 0, 2073, 38509 },
    { 7, 87, 0, 0, 1, 2, 255, 0, 0, 2074, 38585 },
    { -13, 93, 0, 0, 1, 0, 255, 0, 0, 2075, 38539 },
    { 6, 87, 0, 0, 1, 2, 255, 0, 0, 2076, 38590 },
    { 8, 85, 0, 0, 1, 0, 255, 0, 0, 2077, 38539 },
    { 10, 87, 0, 0, 1, 0, 255, 0, 0, 2078, 38525 },
    { 10, 87, 0, 0, 1, 0, 255, 0, 0, 2079, 38525 },
    { 21, 88, 0, 0, 1, 0, 255, 0, 0, 2080, 38561 },
    { 17, 83, 0, 0, 1, 0, 255, 0, 0, 2081, 38558 },
    { 29, 80, 0, 0, 1, 1, 255, 0, 0, 2082, 38578 },
    { 37, 72, 0, 0, 1, 1, 255, 0, 0, 2083, 38540 },
    { 33, 72, 0, 0, 1, 1, 255, 0, 0, 2084, 38564 },
    { 24, 93, 0, 0, 1, 1, 255, 0, 0, 2085, 38521 },
    { 35, 25, 0, 0, 1, 0, 255, 0, 0, 2086, 38560 },
    { 54, 51, 0, 0, 1, 0, 255, 0, 0, 2087, 38575 },
    { 47, 83, 0, 0, 1, 0, 255, 0, 0, 2088, 38600 },
    { -44, -24, 0, 0, 1, 0, 255, 0, 0, 2089, 38514 },
    { -29, -67, 0, 0, 1, 0, 255, 0, 0, 2090, 38520 },
    { -11, -101, 0, 0, 1, 1, 255, 0, 0, 2091, 38559 },
    { 8, -52, 0, 0, 1, 3, 255, 0, 0, 2092, 38590 },
    { -16, 83, 0, 0, 1, 3, 255, 0, 0, 2093, 38568 },
    { 39, 7, 0, 0, 1, 2, 255, 0, 0, 2094, 38561 },
    { 59, 0, 0, 0, 1, 1, 255, 0, 0, 2095, 38585 },
    { 12, 91, 0, 0, 2, 1, 255, 0, 0, 2096, 38559 },
    { 35, 95, 0, 0, 2, 1, 255, 0, 0, 2097, 38526 },
    { 26, 101, 0, 0, 2, 1, 255, 0, 0, 2098, 38560 },
    { 27, 105, 0, 0, 2, 1, 255, 0, 0, 2099, 38561 },
    { 38, 102, 0, 0, 2, 1, 255, 0, 0, 2100, 38563 },
    { 34, 102, 0, 0, 1, 1, 255, 0, 0, 2101, 38546 },
    { 15, 105, 0, 0, 1, 1, 255, 0, 0, 2102, 38526 },
    { 20, 86, 0, 0, 1, 2, 255, 0, 0, 2103, 38615 },
    { 20, 86, 0, 0, 1, 2, 255, 0, 0, 2104, 38612 },
    { 28, 77, 0, 0, 1, 3, 255, 0, 0, 2105, 38590 },
    { 28, 77, 0, 0, 1, 3, 255, 0, 0, 2106, 38591 },
    { 29, 69, 0, 0, 1, 1, 255, 0, 0, 2107, 38522 },
    { 29, 69, 0, 0, 1, 1, 255, 0, 0, 2108, 38523 },
    { 28, 77, 0, 0, 1, 3, 255, 0, 0, 2109, 38590 },
    { 20, 86, 0, 0, 1, 2, 255, 0, 0, 2110, 38615 },
    { 20, 86, 0, 0, 1, 2, 255, 0, 0, 2111, 38612 },
    { -17, 87, 0, 0, 1, 0, 255, 0, 0, 2112, 38540 },
    { -8, 86, 0, 0, 1, 0, 255, 0, 0, 2113, 38504 },
    { -10, 81, 0, 0, 1, 0, 255, 0, 0, 2114, 38506 },
    { 8, 88, 0, 0, 1, 0, 255, 0, 0, 2115, 38508 },
    { 7, 93, 0, 0, 1, 0, 255, 0, 0, 2116, 38540 },
    { 20, 86, 0, 0, 1, 2, 255, 0, 0, 2117, 38615 },
    { 1, 91, 0, 0, 1, 0, 255, 0, 0, 2118, 38505 },
    { 1, 91, 0, 0, 1, 0, 255, 0, 0, 2119, 38507 },
    { -12, 88, 0, 0, 1, 0, 255, 0, 0, 2120, 38510 },
    { -11, 88, 0, 0, 1, 0, 255, 0, 0, 2121, 38540 },
    { 8, 89, 0, 0, 1, 0, 255, 0, 0, 2122, 38538 },
    { 31, 80, 0, 0, 1, 1, 255, 0, 0, 2123, 38572 },
    { 19, 81, 0, 0, 1, 1, 255, 0, 0, 2124, 38574 },
    { 23, 88, 0, 0, 1, 0, 255, 0, 0, 2125, 38560 },
    { 9, 88, 0, 0, 1, 0, 255, 0, 0, 2126, 38540 },
    { -10, 85, 0, 0, 1, 0, 255, 0, 0, 2127, 38576 },
    { 17, 84, 0, 0, 1, 2, 255, 0, 0, 2128, 38585 },
    { 6, 93, 0, 0, 1, 0, 255, 0, 0, 2129, 38540 },
    { 9, 90, 0, 0, 1, 0, 255, 0, 0, 2130, 38575 },
    { 21, 85, 0, 0, 1, 0, 255, 0, 0, 2131, 38574 },
    { -27, 79, 0, 0, 1, 0, 255, 0, 0, 2132, 38577 },
    { -19, 75, 0, 0, 1, 3, 255, 0, 0, 2133, 38585 },
    { -9, 62, 0, 0, 1, 3, 255, 0, 0, 2134, 38586 },
    { -31, 78, 0, 0, 1, 0, 255, 0, 0, 2135, 38521 },
    { -25, 77, 0, 0, 1, 0, 255, 0, 0, 2136, 38523 },
    { -9, 60, 0, 0, 1, 0, 255, 0, 0, 2137, 38500 },
    { -10, 59, 0, 0, 1, 0, 255, 0, 0, 2138, 38502 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 2139, 38504 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 2140, 38508 },
    { -9, 59, 0, 0, 1, 0, 255, 0, 0, 2141, 38510 },
    { -3, 59, 0, 0, 1, 1, 255, 0, 0, 2142, 38558 },
    { 0, 61, 0, 0, 1, 1, 255, 0, 0, 2143, 38558 },
    { 6, 61, 0, 0, 1, 1, 255, 0, 0, 2144, 38560 },
    { 6, 61, 0, 0, 1, 1, 255, 0, 0, 2145, 38561 },
    { 11, 85, 0, 0, 1, 0, 255, 0, 0, 2146, 38583 },
    { 18, 85, 0, 0, 1, 0, 255, 0, 0, 2147, 38581 },
    { 5, 92, 0, 0, 1, 0, 255, 0, 0, 2148, 38508 },
    { 10, 86, 0, 0, 1, 0, 255, 0, 0, 2149, 38521 },
    { 29, 68, 0, 0, 1, 0, 255, 0, 0, 2150, 38516 },
    { 23, 80, 0, 0, 1, 0, 255, 0, 0, 2151, 38502 },
    { 24, 84, 0, 0, 1, 1, 255, 0, 0, 2152, 38539 },
    { 1, 91, 0, 0, 1, 0, 255, 0, 0, 2153, 38503 },
    { -5, 92, 0, 0, 1, 0, 255, 0, 0, 2154, 38509 },
    { -4, 92, 0, 0, 1, 0, 255, 0, 0, 2155, 38511 },
    { 5, 88, 0, 0, 1, 0, 255, 0, 0, 2156, 38540 },
    { 4, 84, 0, 0, 1, 0, 255, 0, 0, 2157, 38508 },
    { 6, 84, 0, 0, 1, 0, 255, 0, 0, 2158, 38507 },
    { 6, 84, 0, 0, 1, 0, 255, 0, 0, 2159, 38506 },
    { 6, 93, 0, 0, 1, 0, 255, 0, 0, 2160, 38509 },
    { 2, 81, 0, 0, 1, 0, 255, 0, 0, 2161, 38504 },
    { -27, 79, 0, 0, 1, 0, 255, 0, 0, 2162, 38564 },
    { -9, 82, 0, 0, 1, 0, 255, 0, 0, 2163, 38562 },
    { 23, 45, 0, 0, 1, 1, 255, 0, 0, 2164, 38602 },
    { 52, 63, 0, 0, 1, 1, 255, 0, 0, 2165, 38569 },
    { -10, 95, 0, 0, 1, 2, 255, 0, 0, 2166, 38585 },
    { -10, 95, 0, 0, 1, 2, 255, 0, 0, 2167, 38586 },
    { -10, 97, 0, 0, 1, 2, 255, 0, 0, 2168, 38588 },
    { -13, 100, 0, 0, 1, 2, 255, 0, 0, 2169, 38567 },
    { 9, 95, 0, 0, 1, 0, 255, 0, 0, 2170, 38503 },
    { 1, 90, 0, 0, 1, 0, 255, 0, 0, 2171, 38540 },
    { 4, 104, 0, 0, 1, 0, 255, 0, 0, 2172, 38526 },
    { 0, 52, 0, 0, 1, 1, 255, 0, 0, 2173, 38600 },
    { 23, 45, 0, 0, 1, 1, 255, 0, 0, 2174, 38602 },
    { 50, 63, 0, 0, 1, 1, 255, 0, 0, 2175, 38569 },
    { 6, -1, 0, 0, 1, 2, 255, 0, 0, 2176, 38604 },
    { 43, -1, 0, 0, 1, 0, 255, 0, 0, 2177, 38605 },
    { 51, -1, 0, 0, 1, 0, 255, 0, 0, 2178, 38607 },
    { 37, 19, 0, 0, 1, 0, 255, 0, 0, 2179, 38611 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2180, 11953 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2181, 11954 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2182, 11955 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2183, 11956 },
    { -1, 90, 0, 0, 1, 0, 255, 0, 0, 2184, 11957 },
    { -1, 90, 0, 0, 1, 0, 255, 0, 0, 2185, 11958 },
    { -1, 90, 0, 0, 1, 0, 255, 0, 0, 2186, 11959 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2187, 11960 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2188, 11961 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2189, 11962 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2190, 11963 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2191, 11964 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2192, 11965 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2193, 11966 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2194, 11967 },
    { -1, 89, 0, 0, 1, 0, 255, 0, 0, 2195, 11968 },
    { 0, 90, 0, 0, 1, 0, 255, 0, 0, 2196, 11969 },
    { 0, 90, 0, 0, 1, 0, 255, 0, 0, 2197, 11970 },
    { 0, 90, 0, 0, 1, 0, 255, 0, 0, 2198, 11971 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2199, 11972 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2200, 11973 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2201, 11974 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2202, 11975 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2203, 11976 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2204, 11977 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2205, 11978 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2206, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2207, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2208, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2209, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2210, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2211, 11979 },
    { 0, 89, 0, 0, 1, 0, 255, 0, 0, 2212, 11979 },
    { -1, 90, 0, 0, 1, 0, 255, 0, 0, 2213, 11980 },
    { -1, 90, 0, 0, 1, 0, 255, 0, 0, 2214, 11981 },
    { 18, 88, 0, 0, 1, 0, 255, 0, 0, 2215, 38507 },
    { -6, 84, 0, 0, 1, 0, 255, 0, 0, 2216, 38504 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 2217, 38518 },
    { -31, 78, 0, 0, 1, 0, 255, 0, 0, 2218, 38514 },
    { -26, 82, 0, 0, 1, 0, 255, 0, 0, 2219, 38517 },
    { -44, 70, 0, 0, 1, 0, 255, 0, 0, 2220, 38499 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 2221, 38503 },
    { -15, 84, 0, 0, 1, 0, 255, 0, 0, 2222, 38504 },
    { -19, 75, 0, 0, 1, 0, 255, 0, 0, 2223, 38565 },
    { -16, 77, 0, 0, 1, 0, 255, 0, 0, 2224, 38564 },
    { -8, 86, 0, 0, 1, 0, 255, 0, 0, 2225, 38579 },
    { -12, 89, 0, 0, 1, 0, 255, 0, 0, 2226, 38580 },
    { -16, 92, 0, 0, 1, 0, 255, 0, 0, 2227, 38582 },
    { -16, 92, 0, 0, 1, 0, 255, 0, 0, 2228, 38583 },
    { -12, 82, 0, 0, 1, 0, 255, 0, 0, 2229, 38592 },
    { -21, 84, 0, 0, 1, 0, 255, 0, 0, 2230, 38561 },
    { -18, 83, 0, 0, 1, 0, 255, 0, 0, 2231, 38594 },
    { -28, 82, 0, 0, 1, 0, 255, 0, 0, 2232, 38596 },
    { -9, 92, 0, 0, 1, 0, 255, 0, 0, 2233, 38598 },
    { -42, 61, 0, 0, 1, 0, 255, 0, 0, 2234, 38558 },
    { -23, 82, 0, 0, 1, 0, 255, 0, 0, 2235, 38539 },
    { -17, 84, 0, 0, 1, 0, 255, 0, 0, 2236, 38507 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2237, 12177 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12178 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2239, 12179 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12180 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12181 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12182 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12183 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2238, 12184 },
    { -72, 58, 0, 0, 2, 0, 255, 0, 0, 2245, 12161 },
    { -67, 58, 0, 0, 2, 0, 255, 0, 0, 2246, 12162 },
    { -34, 57, 0, 0, 2, 0, 255, 0, 0, 2247, 12163 },
    { -34, 57, 0, 0, 2, 0, 255, 0, 0, 2248, 12185 },
    { -34, 57, 0, 0, 2, 0, 255, 0, 0, 2249, 12186 },
    { -34, 57, 0, 0, 2, 0, 255, 0, 0, 2250, 12187 },
    { -34, 57, 0, 0, 2, 0, 255, 0, 0, 2251, 12188 },
    { 16, 80, 0, 0, 1, 1, 255, 0, 0, 2252, 38571 },
    { 22, 78, 0, 0, 1, 1, 255, 0, 0, 2253, 38568 },
    { 34, 66, 0, 0, 1, 1, 255, 0, 0, 2254, 38566 },
    { -50, 0, 0, 0, 1, 0, 255, 0, 0, 2255, 38585 },
    { -57, -3, 0, 0, 1, 2, 255, 0, 0, 2256, 38572 },
    { -56, 0, 0, 0, 1, 0, 255, 0, 0, 2257, 38591 },
    { -11, 99, 0, 0, 1, 0, 255, 0, 0, 2258, 38521 },
    { 10, 95, 0, 0, 1, 0, 255, 0, 0, 2259, 38516 },
    { -26, 83, 0, 0, 1, 0, 255, 0, 0, 2260, 38568 },
    { -5, -104, 0, 0, 1, 3, 255, 0, 0, 2261, 38507 },
    { 49, -4, 0, 0, 2, 3, 255, 0, 0, 2262, 38512 },
    { 52, 21, 0, 0, 1, 1, 255, 0, 0, 2263, 38513 },
    { 28, 89, 0, 0, 1, 0, 255, 0, 0, 2264, 38562 },
    { -21, 84, 0, 0, 2, 0, 255, 0, 0, 2265, 38564 },
    { 35, -67, 0, 0, 1, 3, 255, 0, 0, 2266, 38588 },
    { 54, 9, 0, 0, 1, 3, 255, 0, 0, 2267, 38586 },
    { 56, 82, 0, 0, 1, 3, 255, 0, 0, 2268, 38585 },
    { 1, 101, 0, 0, 1, 2, 255, 0, 0, 2269, 38590 },
    { -3, 75, 0, 0, 1, 2, 255, 0, 0, 2270, 38585 },
    { -2, 98, 0, 0, 1, 0, 255, 0, 0, 2271, 38594 },
    { -2, 93, 0, 0, 1, 0, 255, 0, 0, 2272, 38595 },
    { 13, 97, 0, 0, 1, 1, 255, 0, 0, 2273, 38567 },
    { 10, 101, 0, 0, 1, 1, 255, 0, 0, 2274, 38588 },
    { 10, 99, 0, 0, 1, 1, 255, 0, 0, 2275, 38586 },
    { 2, 103, 0, 0, 1, 1, 255, 0, 0, 2276, 38585 },
    { 21, -63, 0, 0, 2, 1, 255, 0, 0, 2277, 38537 },
    { 10, 91, 0, 0, 1, 1, 255, 0, 0, 2278, 38541 },
    { -25, 76, 0, 0, 1, 0, 255, 0, 0, 2279, 38604 },
    { -15, 64, 0, 0, 1, 1, 255, 0, 0, 2280, 38565 },
    { -23, 73, 0, 0, 1, 3, 255, 0, 0, 2281, 38567 },
    { -43, 67, 0, 0, 2, 0, 255, 0, 0, 2282, 38570 },
    { -43, 67, 0, 0, 2, 0, 255, 0, 0, 2283, 38571 },
    { -43, 67, 0, 0, 2, 0, 255, 0, 0, 2284, 38572 },
    { -46, 59, 0, 0, 2, 0, 255, 0, 0, 2285, 38573 },
};

const CatchTable ibuki_rival_catch_tbl[1104] = {
    { -96, 0, 2, 1, 1 },
    { -98, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -93, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -101, 0, 2, 1, 1 },
    { -93, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -78, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 2 },
    { -98, 0, 2, 1, 2 },
    { -89, 0, 2, 1, 2 },
    { -93, 0, 2, 1, 2 },
    { -92, 0, 2, 1, 2 },
    { -80, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -80, 0, 2, 1, 2 },
    { -92, 0, 2, 1, 2 },
    { -101, 0, 2, 1, 2 },
    { -93, 0, 2, 1, 2 },
    { -89, 0, 2, 1, 2 },
    { -89, 0, 2, 1, 2 },
    { -88, 0, 2, 1, 2 },
    { -89, 0, 2, 1, 2 },
    { -89, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -78, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -88, 0, 2, 1, 3 },
    { -98, 0, 2, 1, 3 },
    { -89, 0, 2, 1, 3 },
    { -93, 0, 2, 1, 3 },
    { -92, 0, 2, 1, 3 },
    { -80, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -80, 0, 2, 1, 3 },
    { -92, 0, 2, 1, 3 },
    { -101, 0, 2, 1, 3 },
    { -93, 0, 2, 1, 3 },
    { -89, 0, 2, 1, 3 },
    { -89, 0, 2, 1, 3 },
    { -88, 0, 2, 1, 3 },
    { -89, 0, 2, 1, 3 },
    { -89, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -78, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -106, 0, 2, 1, 4 },
    { -98, 0, 2, 1, 4 },
    { -89, 0, 2, 1, 4 },
    { -93, 0, 2, 1, 4 },
    { -92, 0, 2, 1, 4 },
    { -80, 0, 2, 1, 4 },
    { -107, 0, 1, 1, 4 },
    { -80, 0, 2, 1, 4 },
    { -92, 0, 2, 1, 4 },
    { -101, 0, 2, 1, 4 },
    { -93, 0, 2, 1, 4 },
    { -89, 0, 2, 1, 4 },
    { -89, 0, 2, 1, 4 },
    { -106, 0, 2, 1, 4 },
    { -89, 0, 2, 1, 4 },
    { -89, 0, 2, 1, 4 },
    { -78, 0, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { -69, 0, 1, 1, 4 },
    { -89, 0, 1, 1, 4 },
    { -78, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -88, 0, 2, 1, 5 },
    { -98, 0, 2, 1, 5 },
    { -89, 0, 2, 1, 5 },
    { -93, 0, 2, 1, 5 },
    { -92, 0, 2, 1, 5 },
    { -80, 0, 2, 1, 5 },
    { -107, 0, 1, 1, 5 },
    { -80, 0, 2, 1, 5 },
    { -92, 0, 2, 1, 5 },
    { -101, 0, 2, 1, 5 },
    { -93, 0, 2, 1, 5 },
    { -89, 0, 2, 1, 5 },
    { -89, 0, 2, 1, 5 },
    { -88, 0, 2, 1, 5 },
    { -89, 0, 2, 1, 5 },
    { -89, 0, 2, 1, 5 },
    { -65, 0, 1, 1, 5 },
    { -58, 0, 1, 1, 5 },
    { -69, 0, 1, 1, 5 },
    { -73, 0, 1, 1, 5 },
    { -78, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -88, 0, 2, 1, 6 },
    { -98, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -93, 0, 2, 1, 6 },
    { -92, 0, 2, 1, 6 },
    { -80, 0, 2, 1, 6 },
    { -107, 0, 1, 1, 6 },
    { -80, 0, 2, 1, 6 },
    { -88, 0, 2, 1, 6 },
    { -101, 0, 2, 1, 6 },
    { -93, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -88, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -65, 0, 1, 1, 6 },
    { -58, 0, 1, 1, 6 },
    { -69, 0, 1, 1, 6 },
    { -77, 0, 1, 1, 6 },
    { -78, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -88, 0, 2, 1, 7 },
    { -98, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -93, 0, 2, 1, 7 },
    { -92, 0, 2, 1, 7 },
    { -80, 0, 2, 1, 7 },
    { -107, 0, 1, 1, 7 },
    { -80, 0, 2, 1, 7 },
    { -84, 0, 2, 1, 7 },
    { -101, 0, 2, 1, 7 },
    { -93, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -88, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -65, 0, 1, 1, 7 },
    { -66, 0, 1, 1, 7 },
    { -69, 0, 1, 1, 7 },
    { -64, 0, 1, 1, 7 },
    { -78, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -88, 0, 2, 1, 8 },
    { -98, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -93, 0, 2, 1, 8 },
    { -92, 0, 2, 1, 8 },
    { -80, 0, 2, 1, 8 },
    { -107, 0, 1, 1, 8 },
    { -80, 0, 2, 1, 8 },
    { -76, 0, 2, 1, 8 },
    { -101, 0, 2, 1, 8 },
    { -93, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -88, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -73, 0, 2, 1, 8 },
    { -66, 0, 2, 1, 8 },
    { -69, 0, 1, 1, 8 },
    { -76, 0, 2, 1, 8 },
    { -78, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -88, 0, 2, 1, 9 },
    { -98, 0, 2, 1, 9 },
    { -89, 0, 2, 1, 9 },
    { -93, 0, 2, 1, 9 },
    { -92, 0, 2, 1, 9 },
    { -80, 0, 2, 1, 9 },
    { -88, 0, 1, 1, 9 },
    { -80, 0, 2, 1, 9 },
    { -72, 0, 2, 1, 9 },
    { -101, 0, 2, 1, 9 },
    { -93, 0, 2, 1, 9 },
    { -89, 0, 2, 1, 9 },
    { -89, 0, 2, 1, 9 },
    { -88, 0, 2, 1, 9 },
    { -89, 0, 2, 1, 9 },
    { -89, 0, 2, 1, 9 },
    { -100, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -103, 0, 1, 1, 9 },
    { -76, 0, 2, 1, 9 },
    { -78, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -88, 0, 2, 1, 10 },
    { -98, 0, 2, 1, 10 },
    { -89, 0, 2, 1, 10 },
    { -93, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 10 },
    { -80, 0, 2, 1, 10 },
    { -88, 0, 1, 1, 10 },
    { -80, 0, 2, 1, 10 },
    { -72, 0, 2, 1, 10 },
    { -101, 0, 2, 1, 10 },
    { -93, 0, 2, 1, 10 },
    { -89, 0, 2, 1, 10 },
    { -89, 0, 2, 1, 10 },
    { -88, 0, 2, 1, 10 },
    { -89, 0, 2, 1, 10 },
    { -89, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -103, 0, 1, 1, 10 },
    { -76, 0, 2, 1, 10 },
    { -78, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -88, 0, 2, 1, 11 },
    { -98, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -93, 0, 2, 1, 11 },
    { -92, 0, 2, 1, 11 },
    { -80, 0, 2, 1, 11 },
    { -88, 0, 1, 1, 11 },
    { -80, 0, 2, 1, 11 },
    { -72, 0, 2, 1, 11 },
    { -101, 0, 2, 1, 11 },
    { -93, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -88, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -92, 0, 2, 1, 11 },
    { -71, 0, 2, 1, 11 },
    { -118, 0, 1, 1, 11 },
    { -76, 0, 2, 1, 11 },
    { -78, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -88, 0, 2, 1, 12 },
    { -98, 0, 2, 1, 12 },
    { -89, 0, 2, 1, 12 },
    { -93, 0, 2, 1, 12 },
    { -92, 0, 2, 1, 12 },
    { -80, 0, 2, 1, 12 },
    { -88, 0, 1, 1, 12 },
    { -80, 0, 2, 1, 12 },
    { -72, 0, 2, 1, 12 },
    { -101, 0, 2, 1, 12 },
    { -93, 0, 2, 1, 12 },
    { -89, 0, 2, 1, 12 },
    { -89, 0, 2, 1, 12 },
    { -88, 0, 2, 1, 12 },
    { -89, 0, 2, 1, 12 },
    { -89, 0, 2, 1, 12 },
    { -92, 0, 2, 1, 12 },
    { -71, 0, 2, 1, 12 },
    { -118, 0, 2, 1, 12 },
    { -64, 0, 2, 1, 12 },
    { -78, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -11, -5, 1, 1, 1 },
    { 4, -9, 1, 1, 1 },
    { 14, -6, 1, 1, 1 },
    { 25, 8, 1, 1, 1 },
    { 13, -11, 1, 1, 1 },
    { -16, 4, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 20, 4, 1, 1, 1 },
    { 8, 4, 1, 1, 1 },
    { 18, 4, 1, 1, 1 },
    { 25, 8, 1, 1, 1 },
    { 14, -6, 1, 1, 1 },
    { 14, -6, 1, 1, 1 },
    { -11, -5, 1, 1, 1 },
    { 14, -6, 1, 1, 1 },
    { 14, -6, 1, 1, 1 },
    { -11, -4, 1, 1, 1 },
    { -8, 3, 1, 1, 1 },
    { -11, -14, 1, 1, 1 },
    { -12, -4, 1, 1, 1 },
    { 8, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 6, -16, 1, 1, 2 },
    { 10, -27, 1, 1, 2 },
    { 27, -21, 1, 1, 2 },
    { 37, -10, 1, 1, 2 },
    { 33, -30, 1, 1, 2 },
    { 12, -21, 1, 1, 2 },
    { 11, -47, 1, 1, 2 },
    { 33, -19, 1, 1, 2 },
    { 8, -18, 1, 1, 2 },
    { 24, -13, 1, 1, 2 },
    { 37, -10, 1, 1, 2 },
    { 27, -21, 1, 1, 2 },
    { 27, -21, 1, 1, 2 },
    { 6, -16, 1, 1, 2 },
    { 27, -21, 1, 1, 2 },
    { 27, -21, 1, 1, 2 },
    { 26, -18, 1, 1, 2 },
    { 27, -15, 1, 1, 2 },
    { 24, -50, 1, 1, 2 },
    { 13, -21, 1, 1, 2 },
    { 18, -8, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 28, -35, 1, 1, 3 },
    { 46, -33, 1, 1, 3 },
    { 60, -29, 1, 1, 3 },
    { 63, -23, 1, 1, 3 },
    { 73, -42, 1, 1, 3 },
    { 71, -29, 1, 1, 3 },
    { 35, -53, 1, 1, 3 },
    { 57, -25, 1, 1, 3 },
    { 26, -26, 1, 1, 3 },
    { 58, -22, 1, 1, 3 },
    { 63, -23, 1, 1, 3 },
    { 60, -29, 1, 1, 3 },
    { 60, -29, 1, 1, 3 },
    { 28, -35, 1, 1, 3 },
    { 60, -29, 1, 1, 3 },
    { 60, -29, 1, 1, 3 },
    { 66, -26, 1, 1, 3 },
    { 54, -21, 1, 1, 3 },
    { 75, -42, 1, 1, 3 },
    { 72, -24, 1, 1, 3 },
    { 28, -32, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 49, -45, 1, 1, 4 },
    { 84, -37, 1, 1, 4 },
    { 64, -33, 1, 1, 3 },
    { 68, -26, 1, 1, 3 },
    { 81, -47, 1, 1, 3 },
    { 78, -32, 1, 1, 3 },
    { 26, -51, 1, 1, 4 },
    { 64, -32, 1, 1, 3 },
    { 88, -32, 1, 1, 4 },
    { 65, -26, 1, 1, 3 },
    { 68, -26, 1, 1, 3 },
    { 64, -33, 1, 1, 3 },
    { 64, -33, 1, 1, 3 },
    { 49, -45, 1, 1, 4 },
    { 64, -33, 1, 1, 3 },
    { 64, -33, 1, 1, 3 },
    { 66, -26, 1, 1, 4 },
    { 63, -20, 1, 1, 4 },
    { 74, -38, 1, 1, 4 },
    { 74, -29, 1, 1, 4 },
    { 64, -36, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 86, -51, 1, 1, 5 },
    { 55, -42, 1, 1, 5 },
    { 55, -33, 1, 1, 3 },
    { 48, -24, 1, 1, 2 },
    { 46, -48, 1, 1, 2 },
    { 26, -40, 1, 1, 2 },
    { 21, -54, 1, 1, 5 },
    { 44, -30, 1, 1, 2 },
    { 74, -30, 1, 1, 5 },
    { 38, -25, 1, 1, 2 },
    { 48, -24, 1, 1, 2 },
    { 55, -33, 1, 1, 3 },
    { 55, -33, 1, 1, 3 },
    { 86, -51, 1, 1, 5 },
    { 55, -33, 1, 1, 3 },
    { 55, -33, 1, 1, 3 },
    { 50, -28, 1, 1, 5 },
    { 50, -16, 1, 1, 5 },
    { 67, -46, 1, 1, 5 },
    { 53, -25, 1, 1, 5 },
    { 52, -36, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 45, -49, 2, 1, 6 },
    { -3, -32, 2, 1, 6 },
    { 8, -42, 2, 1, 2 },
    { 12, -17, 2, 1, 3 },
    { 0, -47, 2, 1, 1 },
    { -18, -34, 2, 1, 1 },
    { 3, -35, 2, 1, 6 },
    { 4, -22, 2, 1, 1 },
    { 6, -22, 2, 1, 6 },
    { 4, -17, 2, 1, 4 },
    { 12, -17, 2, 1, 3 },
    { 8, -42, 2, 1, 2 },
    { 8, -42, 2, 1, 2 },
    { 45, -49, 2, 1, 6 },
    { 8, -42, 2, 1, 2 },
    { 8, -42, 2, 1, 2 },
    { 14, -21, 2, 1, 6 },
    { 11, -10, 2, 1, 6 },
    { 22, -47, 2, 1, 6 },
    { 15, -22, 2, 1, 6 },
    { 20, -42, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 13, -51, 2, 1, 7 },
    { -1, -32, 2, 1, 7 },
    { 0, -35, 2, 1, 1 },
    { 12, -15, 2, 1, 4 },
    { 0, -41, 2, 1, 4 },
    { -18, -32, 2, 1, 4 },
    { -12, -38, 2, 1, 7 },
    { 4, -18, 2, 1, 4 },
    { 2, -16, 2, 1, 7 },
    { 4, -12, 2, 1, 5 },
    { 12, -15, 2, 1, 4 },
    { 0, -35, 2, 1, 1 },
    { 0, -35, 2, 1, 1 },
    { 13, -51, 2, 1, 7 },
    { 0, -35, 2, 1, 1 },
    { 0, -35, 2, 1, 1 },
    { 6, -16, 2, 1, 7 },
    { 4, -9, 2, 1, 7 },
    { 11, -45, 2, 1, 7 },
    { 10, -18, 2, 1, 7 },
    { -8, -28, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 14, -41, 2, 1, 8 },
    { -7, -28, 2, 1, 7 },
    { 4, -23, 2, 1, 2 },
    { 11, -12, 2, 1, 5 },
    { 0, -37, 2, 1, 5 },
    { -6, -28, 2, 1, 5 },
    { -15, -32, 2, 1, 7 },
    { 4, -14, 2, 1, 5 },
    { 2, -16, 2, 1, 8 },
    { 4, -8, 2, 1, 6 },
    { 11, -12, 2, 1, 5 },
    { 4, -23, 2, 1, 2 },
    { 4, -23, 2, 1, 2 },
    { 14, -41, 2, 1, 8 },
    { 4, -23, 2, 1, 2 },
    { 4, -23, 2, 1, 2 },
    { -4, -7, 2, 1, 8 },
    { 3, -7, 2, 1, 8 },
    { 7, -44, 2, 1, 8 },
    { 8, -17, 2, 1, 8 },
    { -12, -26, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 9, -33, 2, 1, 9 },
    { -7, -27, 2, 1, 7 },
    { 3, -18, 2, 1, 4 },
    { 11, -11, 2, 1, 5 },
    { 0, -35, 2, 1, 5 },
    { -6, -26, 2, 1, 5 },
    { -15, -32, 2, 1, 7 },
    { 4, -12, 2, 1, 5 },
    { 2, -16, 2, 1, 9 },
    { 4, -5, 2, 1, 6 },
    { 11, -11, 2, 1, 5 },
    { 3, -18, 2, 1, 4 },
    { 3, -18, 2, 1, 4 },
    { 9, -33, 2, 1, 9 },
    { 3, -18, 2, 1, 4 },
    { 3, -18, 2, 1, 4 },
    { 1, -12, 2, 1, 9 },
    { 5, -5, 2, 1, 9 },
    { -21, -44, 2, 1, 9 },
    { -4, -23, 2, 1, 9 },
    { 4, -24, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 12, -38, 2, 1, 10 },
    { -7, -26, 2, 1, 7 },
    { 9, -20, 2, 1, 5 },
    { 11, -10, 2, 1, 5 },
    { 0, -33, 2, 1, 5 },
    { -6, -24, 2, 1, 5 },
    { -15, -32, 2, 1, 7 },
    { 4, -10, 2, 1, 5 },
    { 2, -16, 2, 1, 10 },
    { 4, -3, 2, 1, 6 },
    { 11, -10, 2, 1, 5 },
    { 9, -20, 2, 1, 5 },
    { 9, -20, 2, 1, 5 },
    { 12, -38, 2, 1, 10 },
    { 9, -20, 2, 1, 5 },
    { 9, -20, 2, 1, 5 },
    { -7, -12, 2, 1, 10 },
    { -1, -5, 2, 1, 10 },
    { -39, -35, 2, 1, 10 },
    { -6, -23, 2, 1, 10 },
    { 18, -24, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 12, -38, 2, 1, 11 },
    { -7, -26, 2, 1, 8 },
    { 12, -21, 2, 1, 6 },
    { 11, -9, 2, 1, 6 },
    { 25, -35, 2, 1, 6 },
    { 6, -25, 2, 1, 6 },
    { -15, -32, 2, 1, 8 },
    { 4, -10, 2, 1, 6 },
    { 2, -16, 2, 1, 11 },
    { 13, -17, 2, 1, 7 },
    { 11, -9, 2, 1, 6 },
    { 12, -21, 2, 1, 6 },
    { 12, -21, 2, 1, 6 },
    { 12, -38, 2, 1, 11 },
    { 12, -21, 2, 1, 6 },
    { 12, -21, 2, 1, 6 },
    { 3, -14, 2, 1, 11 },
    { -9, -4, 2, 1, 11 },
    { -22, -34, 2, 1, 11 },
    { 9, -24, 2, 1, 11 },
    { 18, -24, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -10, -50, 2, 0, 12 },
    { -9, -50, 2, 0, 9 },
    { 12, -59, 2, 0, 7 },
    { 11, -41, 2, 0, 7 },
    { 25, -67, 2, 0, 7 },
    { 6, -57, 2, 0, 7 },
    { -36, -23, 2, 0, 9 },
    { 4, -42, 2, 0, 7 },
    { 2, -16, 2, 0, 12 },
    { 13, -49, 2, 0, 8 },
    { 11, -41, 2, 0, 7 },
    { 12, -59, 2, 0, 7 },
    { 12, -59, 2, 0, 7 },
    { -10, -50, 2, 0, 12 },
    { 12, -59, 2, 0, 7 },
    { 12, -59, 2, 0, 7 },
    { 1, -16, 2, 0, 12 },
    { -5, -10, 2, 0, 12 },
    { 4, -43, 2, 0, 12 },
    { -8, -26, 2, 0, 12 },
    { 14, -22, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { -80, -4, 2, 1, 1 },
    { -101, 0, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -81, 0, 2, 1, 1 },
    { -109, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -81, 0, 2, 1, 1 },
    { -79, 0, 2, 1, 1 },
    { -81, 0, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -80, -4, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -33, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -45, -8, 2, 1, 2 },
    { -61, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -68, -5, 2, 1, 2 },
    { -54, -11, 2, 1, 2 },
    { -71, 0, 2, 1, 2 },
    { -58, 0, 2, 1, 2 },
    { -56, -5, 2, 1, 2 },
    { -38, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -68, -5, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -45, -8, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -25, 0, 2, 1, 2 },
    { -33, 1, 2, 1, 2 },
    { -37, 0, 2, 1, 2 },
    { -32, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -29, -15, 2, 1, 3 },
    { -51, 5, 2, 1, 3 },
    { -29, 3, 2, 1, 3 },
    { -35, 2, 2, 1, 3 },
    { -33, -9, 2, 1, 3 },
    { -41, -11, 2, 1, 3 },
    { -33, 0, 2, 1, 3 },
    { -38, -9, 2, 1, 3 },
    { -43, 0, 2, 1, 3 },
    { -23, 11, 2, 1, 3 },
    { -35, 2, 2, 1, 3 },
    { -29, 3, 2, 1, 3 },
    { -29, 3, 2, 1, 3 },
    { -29, -15, 2, 1, 3 },
    { -29, 3, 2, 1, 3 },
    { -29, 3, 2, 1, 3 },
    { -17, -1, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -26, 3, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -20, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -16, -4, 2, 1, 4 },
    { -29, 8, 2, 1, 4 },
    { -13, 10, 2, 1, 4 },
    { -15, 9, 2, 1, 4 },
    { -15, -3, 2, 1, 4 },
    { -16, 4, 2, 1, 4 },
    { -3, -10, 2, 1, 4 },
    { -22, -6, 2, 1, 4 },
    { -14, 8, 2, 1, 4 },
    { 0, 20, 2, 1, 4 },
    { -15, 9, 2, 1, 4 },
    { -13, 10, 2, 1, 4 },
    { -13, 10, 2, 1, 4 },
    { -16, -4, 2, 1, 4 },
    { -13, 10, 2, 1, 4 },
    { -13, 10, 2, 1, 4 },
    { -9, -4, 2, 1, 4 },
    { -1, -2, 2, 1, 4 },
    { -1, 7, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -10, -6, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -9, -8, 2, 1, 5 },
    { -19, -1, 2, 1, 5 },
    { 3, 5, 2, 1, 5 },
    { -1, 9, 2, 1, 5 },
    { 2, -14, 2, 1, 5 },
    { -3, -2, 2, 1, 5 },
    { 9, 5, 2, 1, 5 },
    { -8, -9, 2, 1, 5 },
    { 16, 25, 2, 1, 5 },
    { 9, 13, 2, 1, 5 },
    { -1, 9, 2, 1, 5 },
    { 3, 5, 2, 1, 5 },
    { 3, 5, 2, 1, 5 },
    { -9, -8, 2, 1, 5 },
    { 3, 5, 2, 1, 5 },
    { 3, 5, 2, 1, 5 },
    { 10, 2, 2, 1, 5 },
    { 10, 3, 2, 1, 5 },
    { 21, 0, 2, 1, 5 },
    { -14, -10, 2, 1, 5 },
    { -6, -6, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -10, -6, 2, 1, 6 },
    { -16, 1, 2, 1, 6 },
    { 2, 10, 2, 1, 6 },
    { -5, 10, 2, 1, 6 },
    { 5, -13, 2, 1, 6 },
    { 5, -2, 2, 1, 6 },
    { 19, 3, 2, 1, 6 },
    { -4, -5, 2, 1, 6 },
    { 16, 29, 2, 1, 6 },
    { 10, 24, 2, 1, 6 },
    { -5, 10, 2, 1, 6 },
    { 2, 10, 2, 1, 6 },
    { 2, 10, 2, 1, 6 },
    { -10, -6, 2, 1, 6 },
    { 2, 10, 2, 1, 6 },
    { 2, 10, 2, 1, 6 },
    { 18, -6, 2, 1, 6 },
    { 16, 4, 2, 1, 6 },
    { 23, 1, 2, 1, 6 },
    { -13, -10, 2, 1, 6 },
    { -4, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 10, 8, 2, 1, 7 },
    { 0, 40, 2, 1, 7 },
    { 16, 28, 2, 1, 7 },
    { 6, 24, 2, 1, 7 },
    { 16, 8, 2, 1, 7 },
    { 24, 16, 2, 1, 7 },
    { 35, -5, 2, 1, 7 },
    { 8, 16, 2, 1, 7 },
    { 19, 102, 2, 1, 7 },
    { 32, 32, 2, 1, 7 },
    { 6, 24, 2, 1, 7 },
    { 16, 28, 2, 1, 7 },
    { 16, 28, 2, 1, 7 },
    { 10, 8, 2, 1, 7 },
    { 16, 28, 2, 1, 7 },
    { 16, 28, 2, 1, 7 },
    { 29, 6, 2, 1, 7 },
    { 22, 8, 2, 1, 7 },
    { 27, 4, 2, 1, 7 },
    { 6, 2, 2, 1, 7 },
    { 18, 20, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 33, 8, 2, 1, 8 },
    { 24, 32, 2, 1, 8 },
    { 32, 20, 2, 1, 8 },
    { 22, 16, 2, 1, 8 },
    { 32, 8, 2, 1, 8 },
    { 40, 16, 2, 1, 8 },
    { 51, -4, 2, 1, 8 },
    { 32, 12, 2, 1, 8 },
    { 41, 56, 2, 1, 8 },
    { 44, 24, 2, 1, 8 },
    { 22, 16, 2, 1, 8 },
    { 32, 20, 2, 1, 8 },
    { 32, 20, 2, 1, 8 },
    { 33, 8, 2, 1, 8 },
    { 32, 20, 2, 1, 8 },
    { 32, 20, 2, 1, 8 },
    { 51, 2, 2, 1, 8 },
    { 61, 4, 2, 1, 8 },
    { 55, 5, 2, 1, 8 },
    { 27, 2, 2, 1, 8 },
    { 40, 20, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 49, 8, 2, 0, 9 },
    { 48, 24, 2, 0, 9 },
    { 48, 12, 2, 0, 9 },
    { 38, 8, 2, 0, 9 },
    { 48, 8, 2, 0, 9 },
    { 56, 16, 2, 0, 9 },
    { 58, -17, 2, 0, 9 },
    { 48, 8, 2, 0, 9 },
    { 53, 32, 2, 0, 9 },
    { 60, 16, 2, 0, 9 },
    { 6, 24, 2, 0, 9 },
    { 48, 12, 2, 0, 9 },
    { 48, 12, 2, 0, 9 },
    { 49, 8, 2, 0, 9 },
    { 48, 12, 2, 0, 9 },
    { 48, 12, 2, 0, 9 },
    { 57, 6, 2, 0, 9 },
    { 74, 5, 2, 0, 9 },
    { 102, 6, 2, 0, 9 },
    { 42, 4, 2, 0, 9 },
    { 50, 12, 2, 0, 9 },
    { 0, 0, 2, 0, 9 },
    { 0, 0, 2, 0, 9 },
    { 0, 0, 2, 0, 9 },
    { -48, -40, 1, 1, 1 },
    { -21, -23, 1, 1, 1 },
    { -33, -18, 1, 1, 1 },
    { -25, -25, 1, 1, 1 },
    { -34, -25, 1, 1, 1 },
    { -39, -39, 1, 1, 1 },
    { -53, -15, 1, 1, 1 },
    { -35, -13, 1, 1, 1 },
    { -40, -18, 1, 1, 1 },
    { -32, 7, 1, 1, 1 },
    { -25, -25, 1, 1, 1 },
    { -33, -18, 1, 1, 1 },
    { -33, -18, 1, 1, 1 },
    { -48, -40, 1, 1, 1 },
    { -33, -18, 1, 1, 1 },
    { -33, -18, 1, 1, 1 },
    { -24, -12, 1, 1, 1 },
    { -43, -7, 1, 1, 1 },
    { -60, -28, 1, 1, 1 },
    { -35, -12, 1, 1, 1 },
    { -38, -28, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -50, -39, 1, 1, 2 },
    { -33, -33, 1, 1, 2 },
    { -23, -18, 1, 1, 2 },
    { -20, -21, 1, 1, 2 },
    { -19, -27, 1, 1, 2 },
    { -50, -10, 1, 1, 2 },
    { -51, -14, 1, 1, 2 },
    { -37, -14, 1, 1, 2 },
    { -32, -22, 1, 1, 2 },
    { -39, 3, 1, 1, 2 },
    { -20, -21, 1, 1, 2 },
    { -23, -18, 1, 1, 2 },
    { -23, -18, 1, 1, 2 },
    { -50, -39, 1, 1, 2 },
    { -23, -18, 1, 1, 2 },
    { -23, -18, 1, 1, 2 },
    { -7, -22, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -45, -32, 1, 1, 2 },
    { -18, -29, 1, 1, 2 },
    { -46, -16, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -73, -31, 2, 1, 3 },
    { -78, -45, 2, 1, 3 },
    { -58, -10, 2, 1, 3 },
    { -63, 21, 2, 1, 3 },
    { -43, -21, 2, 1, 3 },
    { -22, -31, 2, 1, 3 },
    { -62, -13, 2, 1, 3 },
    { -80, -14, 2, 1, 3 },
    { -50, -12, 2, 1, 3 },
    { -48, -8, 2, 1, 3 },
    { -63, 21, 2, 1, 3 },
    { -58, -10, 2, 1, 3 },
    { -58, -10, 2, 1, 3 },
    { -73, -31, 2, 1, 3 },
    { -58, -10, 2, 1, 3 },
    { -58, -10, 2, 1, 3 },
    { -55, -4, 2, 1, 3 },
    { -75, -9, 2, 1, 3 },
    { -81, -23, 2, 1, 3 },
    { -50, -31, 2, 1, 3 },
    { -60, -26, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -68, -32, 2, 1, 4 },
    { -56, -49, 2, 1, 4 },
    { -58, -6, 2, 1, 4 },
    { -57, 0, 2, 1, 4 },
    { -43, -21, 2, 1, 4 },
    { -18, -31, 2, 1, 4 },
    { -63, -16, 2, 1, 4 },
    { -65, -6, 2, 1, 4 },
    { -50, -12, 2, 1, 4 },
    { -50, -7, 2, 1, 4 },
    { -57, 0, 2, 1, 4 },
    { -58, -6, 2, 1, 4 },
    { -58, -6, 2, 1, 4 },
    { -68, -32, 2, 1, 4 },
    { -58, -6, 2, 1, 4 },
    { -58, -6, 2, 1, 4 },
    { -55, -10, 2, 1, 4 },
    { -70, -9, 2, 1, 4 },
    { -80, -22, 2, 1, 4 },
    { -41, -35, 2, 1, 4 },
    { -60, -26, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -66, -47, 1, 1, 5 },
    { -62, -38, 1, 1, 5 },
    { -53, -35, 1, 1, 5 },
    { -16, -11, 1, 1, 5 },
    { -46, -25, 2, 1, 5 },
    { -14, -27, 1, 1, 5 },
    { -60, -23, 1, 1, 5 },
    { -64, -2, 1, 1, 5 },
    { -61, -29, 1, 1, 5 },
    { -57, 0, 1, 1, 5 },
    { -16, -11, 1, 1, 5 },
    { -53, -35, 1, 1, 5 },
    { -53, -35, 1, 1, 5 },
    { -66, -47, 1, 1, 5 },
    { -53, -35, 1, 1, 5 },
    { -53, -35, 1, 1, 5 },
    { -69, -29, 1, 1, 5 },
    { -64, -6, 1, 1, 5 },
    { -61, -40, 1, 1, 5 },
    { -50, -33, 1, 1, 5 },
    { -48, -40, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -42, -40, 1, 1, 6 },
    { -60, -42, 1, 1, 6 },
    { -49, -28, 1, 1, 6 },
    { -18, -9, 1, 1, 6 },
    { -50, -28, 1, 1, 6 },
    { -21, -15, 1, 1, 6 },
    { -59, -20, 1, 1, 6 },
    { -47, -35, 1, 1, 6 },
    { -28, -27, 1, 1, 6 },
    { -54, -11, 1, 1, 6 },
    { -18, -9, 1, 1, 6 },
    { -49, -28, 1, 1, 6 },
    { -49, -28, 1, 1, 6 },
    { -42, -40, 1, 1, 6 },
    { -49, -28, 1, 1, 6 },
    { -49, -28, 1, 1, 6 },
    { -62, -15, 1, 1, 6 },
    { -64, -12, 1, 1, 6 },
    { -67, -37, 1, 1, 6 },
    { -54, -28, 1, 1, 6 },
    { -48, -40, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -77, -60, 1, 1, 7 },
    { -52, -51, 1, 1, 7 },
    { -47, -41, 1, 1, 7 },
    { -59, -34, 1, 1, 7 },
    { -47, -48, 1, 1, 7 },
    { -31, -39, 1, 1, 7 },
    { -39, -91, 1, 1, 7 },
    { -55, -38, 1, 1, 7 },
    { -80, -35, 1, 1, 7 },
    { -58, -30, 1, 1, 7 },
    { -59, -34, 1, 1, 7 },
    { -47, -41, 1, 1, 7 },
    { -47, -41, 1, 1, 7 },
    { -77, -60, 1, 1, 7 },
    { -47, -41, 1, 1, 7 },
    { -47, -41, 1, 1, 7 },
    { -72, -37, 1, 1, 7 },
    { -79, -30, 1, 1, 7 },
    { -72, -51, 1, 1, 7 },
    { -49, -33, 1, 1, 7 },
    { -42, -50, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -85, -61, 1, 1, 8 },
    { -54, -58, 1, 1, 8 },
    { -55, -56, 1, 1, 8 },
    { -62, -46, 1, 1, 8 },
    { -52, -55, 1, 1, 8 },
    { -35, -43, 1, 1, 8 },
    { -43, -83, 1, 1, 8 },
    { -51, -45, 1, 1, 8 },
    { -85, -49, 1, 1, 8 },
    { -58, -51, 1, 1, 8 },
    { -62, -46, 1, 1, 8 },
    { -55, -56, 1, 1, 8 },
    { -55, -56, 1, 1, 8 },
    { -85, -61, 1, 1, 8 },
    { -55, -56, 1, 1, 8 },
    { -55, -56, 1, 1, 8 },
    { -78, -38, 1, 1, 8 },
    { -57, -39, 1, 1, 8 },
    { -69, -45, 1, 1, 8 },
    { -44, -36, 1, 1, 8 },
    { -42, -50, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -80, -66, 1, 1, 9 },
    { -32, -48, 1, 1, 9 },
    { -61, -59, 1, 1, 9 },
    { -68, -59, 1, 1, 9 },
    { -54, -57, 1, 1, 9 },
    { -40, -48, 1, 1, 9 },
    { -50, -86, 1, 1, 9 },
    { -52, -45, 1, 1, 9 },
    { -97, -33, 1, 1, 9 },
    { -57, -53, 1, 1, 9 },
    { -68, -59, 1, 1, 9 },
    { -61, -59, 1, 1, 9 },
    { -61, -59, 1, 1, 9 },
    { -80, -66, 1, 1, 9 },
    { -61, -59, 1, 1, 9 },
    { -61, -59, 1, 1, 9 },
    { -90, -41, 1, 1, 9 },
    { -63, -41, 1, 1, 9 },
    { -72, -52, 1, 1, 9 },
    { -40, -48, 1, 1, 9 },
    { -68, -42, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -54, 0, 2, 1, 13 },
    { -98, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -93, 0, 2, 1, 13 },
    { -104, 0, 2, 1, 13 },
    { -80, 0, 2, 1, 13 },
    { -88, 0, 2, 1, 13 },
    { -80, 0, 2, 1, 13 },
    { -72, 0, 2, 1, 13 },
    { -101, 0, 2, 1, 13 },
    { -93, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -54, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -90, 0, 1, 1, 13 },
    { -104, 0, 2, 1, 13 },
    { -118, 0, 2, 1, 13 },
    { -63, 0, 2, 1, 13 },
    { -78, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 3, -66, 1, 1, 1 },
    { -18, -55, 1, 1, 1 },
    { -17, -40, 1, 1, 1 },
    { -10, -34, 1, 1, 1 },
    { -16, -52, 1, 1, 1 },
    { -16, -46, 1, 1, 1 },
    { -21, -62, 1, 1, 1 },
    { -18, -29, 1, 1, 1 },
    { -37, -39, 1, 1, 1 },
    { -6, -31, 1, 1, 1 },
    { -10, -34, 1, 1, 1 },
    { -17, -40, 1, 1, 1 },
    { -17, -40, 1, 1, 1 },
    { 3, -66, 1, 1, 1 },
    { -17, -40, 1, 1, 1 },
    { -17, -40, 1, 1, 1 },
    { -31, -40, 1, 1, 1 },
    { -18, -19, 1, 1, 1 },
    { -27, -31, 1, 1, 1 },
    { -25, -26, 1, 1, 1 },
    { -28, -44, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 26, -52, 1, 1, 2 },
    { 11, -45, 1, 1, 2 },
    { 5, -39, 1, 1, 2 },
    { 18, -28, 1, 1, 2 },
    { 21, -40, 1, 1, 2 },
    { 32, -39, 1, 1, 2 },
    { 21, -40, 1, 1, 2 },
    { 8, -18, 1, 1, 2 },
    { 3, -29, 1, 1, 2 },
    { 18, -31, 1, 1, 2 },
    { 18, -28, 1, 1, 2 },
    { 5, -39, 1, 1, 2 },
    { 5, -39, 1, 1, 2 },
    { 26, -52, 1, 1, 2 },
    { 5, -39, 1, 1, 2 },
    { 5, -39, 1, 1, 2 },
    { 10, -46, 1, 1, 2 },
    { 15, -24, 1, 1, 2 },
    { 11, -42, 1, 1, 2 },
    { 13, -36, 1, 1, 2 },
    { 4, -48, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 26, -52, 1, 1, 3 },
    { 11, -45, 1, 1, 3 },
    { 5, -39, 1, 1, 3 },
    { 18, -28, 1, 1, 3 },
    { 21, -40, 1, 1, 3 },
    { 32, -39, 1, 1, 3 },
    { 21, -40, 1, 1, 3 },
    { 8, -18, 1, 1, 3 },
    { 3, -29, 1, 1, 3 },
    { 18, -31, 1, 1, 3 },
    { 18, -28, 1, 1, 3 },
    { 5, -39, 1, 1, 3 },
    { 5, -39, 1, 1, 3 },
    { 26, -52, 1, 1, 3 },
    { 5, -39, 1, 1, 3 },
    { 5, -39, 1, 1, 3 },
    { 10, -46, 1, 1, 3 },
    { 15, -24, 1, 1, 3 },
    { 11, -42, 1, 1, 3 },
    { 13, -36, 1, 1, 3 },
    { 4, -48, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
};

/* extra scripts: 79 entries */
const u16* const ibuki_exca[80] = {
    ibuki_exca_000,  /* 0 follow-up of AIR NORMAL */
    ibuki_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    ibuki_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    ibuki_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    ibuki_exca_004,  /* 4 follow-up of APPEAR JUNBI 4, WIN 3 */
    ibuki_exca_005,  /* 5 follow-up of APPEAR JUNBI 2, ZANNEN 4 +1 */
    ibuki_exca_005,  /* 6 follow-up of APPEAR JUNBI 3, ZANNEN 6 +1 */
    ibuki_exca_007,  /* 7 follow-up of APPEAR JUNBI 4, APPEAR JUNBI 5 +2 */
    ibuki_exca_008,  /* 8 follow-up of NOKEZORI, UPPER +18 */
    ibuki_exca_009,  /* 9 follow-up of KUNOJI, SNAKE FANG +4 */
    ibuki_exca_010,  /* 10 follow-up of KIRIMOMI, SPLASH.M +1 */
    ibuki_exca_011,  /* 11 follow-up of TATAKI S, KGM TATAKI S +9 */
    ibuki_exca_012,  /* 12 no name */
    ibuki_exca_012,  /* 13 no name */
    ibuki_exca_012,  /* 14 no name */
    ibuki_exca_015,  /* 15 no name */
    ibuki_exca_016,  /* 16 no name */
    ibuki_exca_012,  /* 17 no name */
    ibuki_exca_012,  /* 18 no name */
    ibuki_exca_019,  /* 19 follow-up of APPEAR JUNBI 8 */
    ibuki_exca_020,  /* 20 follow-up of APPEAR 1 */
    ibuki_exca_021,  /* 21 follow-up of APPEAR 2 */
    ibuki_exca_022,  /* 22 follow-up of APPEAR JUNBI 8 */
    ibuki_exca_012,  /* 23 no name */
    ibuki_exca_024,  /* 24 follow-up of HARAIGOSHI */
    ibuki_exca_025,  /* 25 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1 */
    ibuki_exca_012,  /* 26 no name */
    ibuki_exca_027,  /* 27 follow-up of ZANNEN 2 */
    ibuki_exca_028,  /* 28 follow-up of ZANNEN 2 */
    ibuki_exca_012,  /* 29 follow-up of IBUKI */
    ibuki_exca_030,  /* 30 follow-up of ATTACK 4 S */
    ibuki_exca_031,  /* 31 follow-up of ZANNEN 4 */
    ibuki_exca_032,  /* 32 follow-up of ZANNEN 5 */
    ibuki_exca_033,  /* 33 follow-up of ZANNEN 6 */
    ibuki_exca_034,  /* 34 follow-up of ZANNEN 7 */
    ibuki_exca_035,  /* 35 follow-up of SP WIN 3 */
    ibuki_exca_036,  /* 36 follow-up of SP WIN 3 */
    ibuki_exca_037,  /* 37 follow-up of WIN 2 */
    ibuki_exca_038,  /* 38 follow-up of WIN 2 */
    ibuki_exca_039,  /* 39 follow-up of SP WIN 2 */
    ibuki_exca_040,  /* 40 follow-up of SP WIN 2 */
    ibuki_exca_041,  /* 41 follow-up of HUMI ASIB */
    ibuki_exca_042,  /* 42 follow-up of GILL IMPACT C */
    ibuki_exca_043,  /* 43 follow-up of SP WIN 4 */
    ibuki_exca_044,  /* 44 follow-up of SP WIN 4 */
    ibuki_exca_045,  /* 45 follow-up of SP WIN 5 */
    ibuki_exca_046,  /* 46 follow-up of SP WIN 5 */
    ibuki_exca_047,  /* 47 follow-up of WIN 1 */
    ibuki_exca_048,  /* 48 follow-up of WIN 1 */
    ibuki_exca_049,  /* 49 follow-up of follow-up of ATTACK 10 M */
    ibuki_exca_050,  /* 50 follow-up of follow-up of ATTACK 10 M */
    ibuki_exca_051,  /* 51 follow-up of BONUS WIN 1 */
    ibuki_exca_052,  /* 52 follow-up of BONUS WIN 1 */
    ibuki_exca_053,  /* 53 follow-up of JUDGMENT WAIT */
    ibuki_exca_054,  /* 54 follow-up of JUDGMENT WAIT */
    ibuki_exca_055,  /* 55 follow-up of JUDGMENT WAIT */
    ibuki_exca_056,  /* 56 follow-up of JUDGMENT WAIT */
    ibuki_exca_055,  /* 57 follow-up of JUDGMENT WAIT */
    ibuki_exca_056,  /* 58 follow-up of JUDGMENT WAIT */
    ibuki_exca_059,  /* 59 follow-up of JUDGMENT WAIT */
    ibuki_exca_060,  /* 60 follow-up of JUDGMENT WAIT */
    ibuki_exca_061,  /* 61 follow-up of JUDGMENT WIN */
    ibuki_exca_062,  /* 62 follow-up of JUDGMENT WIN */
    ibuki_exca_063,  /* 63 follow-up of JUDGMENT WIN */
    ibuki_exca_064,  /* 64 follow-up of JUDGMENT WIN */
    ibuki_exca_065,  /* 65 follow-up of JUDGMENT WIN */
    ibuki_exca_066,  /* 66 follow-up of JUDGMENT WIN */
    ibuki_exca_067,  /* 67 follow-up of ATTACK 4 SP */
    ibuki_exca_068,  /* 68 follow-up of JUDGMENT LOSE */
    ibuki_exca_069,  /* 69 follow-up of JUDGMENT LOSE */
    ibuki_exca_070,  /* 70 follow-up of WAIT */
    ibuki_exca_071,  /* 71 follow-up of WAIT */
    ibuki_exca_072,  /* 72 follow-up of APPEAR 1 */
    ibuki_exca_073,  /* 73 follow-up of APPEAR 2 */
    ibuki_exca_074,  /* 74 follow-up of ATTACK 1 SP */
    ibuki_exca_075,  /* 75 follow-up of ATTACK 1 SP */
    ibuki_exca_076,  /* 76 follow-up of ATTACK 4 M */
    ibuki_exca_077,  /* 77 follow-up of ATTACK 4 L */
    ibuki_exca_078,  /* 78 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 ibuki_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_000[180] = {
    L4(2, 0, 0, 0, 0, 1021, 0, 0x2A72, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1022, 0, 0x2A73, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1023, 0, 0x2A74, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1024, 0, 0x2A75, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1025, 0, 0x2A76, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1032, 0, 0x2A7D, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1036, 0, 0x2A81, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1037, 0, 0x2A82, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1039, 0, 0x2A65, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1040, 0, 0x2A66, 0, 154, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1041, 0, 0x2A67, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3 */
const u16 ibuki_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_001[84] = {
    L4(1, 0, 273, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 ibuki_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_003[76] = {
    L4(3, 1, 0, 0, 0, 968, 0, 0x2B36, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 969, 0, 0x2B02, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 970, 0, 0x2B03, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 971, 0, 0x2B04, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 972, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 973, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 974, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 975, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4, WIN 3 */
const u16 ibuki_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_004[84] = {
    L4(1, 0, 273, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of APPEAR JUNBI 2, ZANNEN 4 +1, 6 follow-up of APPEAR JUNBI 3, ZANNEN 6 +1 */
const u16 ibuki_exca_005_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_005[84] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of APPEAR JUNBI 4, APPEAR JUNBI 5 +2 */
const u16 ibuki_exca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_007[84] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of NOKEZORI, UPPER +18 */
const u16 ibuki_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_008[140] = {
    L4(3, 0, 0, 0, 0, 1267, 0, 0x2B20, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 1268, 0, 0x2B21, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 1269, 0, 0x2B22, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 1270, 0, 0x2B23, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 1271, 0, 0x2B24, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 1272, 0, 0x2B25, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 1273, 0, 0x2B26, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1275, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 1276, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 1277, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1278, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1279, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1280, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1018, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KUNOJI, SNAKE FANG +4 */
const u16 ibuki_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_009[100] = {
    L4(4, 2, 0, 0, 0, 1009, 0, 0x2B2E, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1010, 0, 0x2B2F, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1011, 0, 0x2B30, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1012, 0, 0x2B31, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1013, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 1014, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 1015, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1016, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1017, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1018, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, SPLASH.M +1 */
const u16 ibuki_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_010[84] = {
    L4(4, 2, 0, 0, 0, 1297, 0, 0x2B57, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 1298, 0, 0x2B58, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1299, 0, 0x2B59, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1300, 0, 0x2B5A, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 1301, 0, 0x2CD3, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1302, 0, 0x2CD4, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1303, 0, 0x2CD5, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1304, 0, 0x2CD6, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1305, 0, 0x2CD7, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1305, 0, 0x2CD7, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of TATAKI S, KGM TATAKI S +9 */
const u16 ibuki_exca_011_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_011[116] = {
    L4(4, 2, 0, 0, 0, 683, 0, 0x2CCE, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 684, 0, 0x2CCF, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 685, 0, 0x2CD0, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 686, 0, 0x2CD1, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 687, 0, 0x2CD2, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 688, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 689, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 690, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 691, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 692, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 693, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 693, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 693, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 693, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 no name, 13 no name, 14 no name, 17 no name ... */
const u16 ibuki_exca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_012[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 ibuki_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_015[60] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 1001, 0, 0x2B1D, 0, 0, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 1002, 0, 0x2B1E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1003, 0, 0x2B1F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1004, 0, 0x2D1D, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1005, 0, 0x2D1E, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 ibuki_exca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_016[60] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 3, 1780, 0, 0x2B30, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 3, 1781, 0, 0x2B0E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 3, 1782, 0, 0x2B0E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 1783, 0, 0x2B00, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 3, 1784, 0, 0x2B00, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 follow-up of APPEAR JUNBI 8 */
const u16 ibuki_exca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_019[84] = {
    L4(2, 0, 274, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 follow-up of APPEAR 1 */
const u16 ibuki_exca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_020[68] = {
    L4(2, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of APPEAR 2 */
const u16 ibuki_exca_021_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_021[60] = {
    L4(2, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 1195, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 1196, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 1197, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1198, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1199, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1200, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of APPEAR JUNBI 8 */
const u16 ibuki_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_022[92] = {
    L4(3, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of HARAIGOSHI */
const u16 ibuki_exca_024_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_024[140] = {
    L4(2, 0, 0, 0, 1, 1798, 0, 0x2B20, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 1799, 0, 0x2B21, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 1800, 0, 0x2B22, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1801, 0, 0x2B23, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1802, 0, 0x2B24, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1803, 0, 0x2B25, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 1804, 0, 0x2B26, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1805, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1806, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 1807, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 1808, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 1809, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 1810, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 1811, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 1812, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 1813, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 1813, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1 */
const u16 ibuki_exca_025_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_025[108] = {
    L4(2, 1, 0, 0, 0, 968, 0, 0x2B36, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 969, 0, 0x2B02, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 970, 0, 0x2B03, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 971, 0, 0x2B04, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 972, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 973, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 973, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 974, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 975, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 976, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 977, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 978, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 978, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of ZANNEN 2 */
const u16 ibuki_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_027[60] = {
    L4(2, 0, 273, 0, 0, 1814, 0, 0x2AD1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of ZANNEN 2 */
const u16 ibuki_exca_028_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_028[76] = {
    L4(1, 64, 273, 0, 0, 1814, 0, 0x2AD1, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1816, 0, 0x2AD3, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of ATTACK 4 S */
const u16 ibuki_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_030[76] = {
    L4(3, 0, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of ZANNEN 4 */
const u16 ibuki_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_031[84] = {
    L4(1, 0, 273, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of ZANNEN 5 */
const u16 ibuki_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_032[100] = {
    L4(1, 0, 273, 0, 0, 279, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 279, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 280, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 281, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 282, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 283, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 284, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 285, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 286, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 287, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 288, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 288, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of ZANNEN 6 */
const u16 ibuki_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_033[44] = {
    L4(1, 0, 273, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 31, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of ZANNEN 7 */
const u16 ibuki_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_034[60] = {
    L4(1, 0, 273, 0, 0, 279, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 279, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 280, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 281, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 282, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 283, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 32, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP WIN 3 */
const u16 ibuki_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_035[100] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of SP WIN 3 */
const u16 ibuki_exca_036_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_036[76] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of WIN 2 */
const u16 ibuki_exca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_037[100] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of WIN 2 */
const u16 ibuki_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_038[76] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of SP WIN 2 */
const u16 ibuki_exca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_039[76] = {
    L4(3, 0, 273, 0, 0, 225, 0, 0x2A68, 0, 241, 0, 0, 0, 21, 0),
    L4(4, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP WIN 2 */
const u16 ibuki_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_040[76] = {
    L4(3, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 242, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of HUMI ASIB */
const u16 ibuki_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_041[108] = {
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 1272, 0, 0x2B25, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 1273, 0, 0x2B26, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 1274, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1275, 0, 0x2B28, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 1276, 0, 0x2B29, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 1277, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 1278, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1279, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1280, 0, 0x2CD8, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1018, 0, 0x2CD9, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1019, 0, 0x2CDA, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 ibuki_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_042[76] = {
    L4(3, 1, 0, 0, 0, 968, 0, 0x2B36, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 969, 0, 0x2B02, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 970, 0, 0x2B03, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 971, 0, 0x2B04, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 972, 0, 0x2B27, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 973, 0, 0x2B2A, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 974, 0, 0x2B2B, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 975, 0, 0x2B2C, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of SP WIN 4 */
const u16 ibuki_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_043[100] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of SP WIN 4 */
const u16 ibuki_exca_044_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_044[76] = {
    L4(3, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP WIN 5 */
const u16 ibuki_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_045[100] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 5 */
const u16 ibuki_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_046[76] = {
    L4(4, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of WIN 1 */
const u16 ibuki_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_047[100] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of WIN 1 */
const u16 ibuki_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_048[76] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of follow-up of ATTACK 10 M */
const u16 ibuki_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_049[100] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of follow-up of ATTACK 10 M */
const u16 ibuki_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_050[76] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 follow-up of BONUS WIN 1 */
const u16 ibuki_exca_051_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_051[100] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 follow-up of BONUS WIN 1 */
const u16 ibuki_exca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_052[76] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_053[76] = {
    L4(2, 3, 273, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_054[76] = {
    L4(2, 3, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of JUDGMENT WAIT, 57 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_055[60] = {
    L4(2, 0, 273, 0, 0, 1814, 0, 0x2AD1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of JUDGMENT WAIT, 58 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_056[76] = {
    L4(1, 0, 273, 0, 0, 1814, 0, 0x2AD1, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1816, 0, 0x2AD3, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_059_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_059[60] = {
    L4(2, 0, 273, 0, 0, 1814, 0, 0x2AD1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 follow-up of JUDGMENT WAIT */
const u16 ibuki_exca_060_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_060[76] = {
    L4(1, 0, 273, 0, 0, 1814, 0, 0x2AD1, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1815, 0, 0x2AD2, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1816, 0, 0x2AD3, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_061_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_061[100] = {
    L4(3, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_062_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_062[76] = {
    L4(4, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_063[100] = {
    L4(2, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_064_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_064[76] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_065_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_065[60] = {
    L4(2, 0, 274, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 1195, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1196, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 1197, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1198, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1199, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1200, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 follow-up of JUDGMENT WIN */
const u16 ibuki_exca_066_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_066[92] = {
    L4(2, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 follow-up of ATTACK 4 SP */
const u16 ibuki_exca_067_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_067[76] = {
    L4(4, 0, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 follow-up of JUDGMENT LOSE */
const u16 ibuki_exca_068_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_068[124] = {
    L6(2, 0, 273, 0, 0, 137, 0, 0x2AC3, 0, 401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 138, 0, 0x2A3D, 0, 401, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 64, 0, 0, 0, 139, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 140, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 141, 0, 0x2A45, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 142, 0, 0x2A46, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 143, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 144, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 145, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 145, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 follow-up of JUDGMENT LOSE */
const u16 ibuki_exca_069_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_069[136] = {
    L6(2, 0, 273, 0, 0, 137, 0, 0x2AC3, 0, 401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 138, 0, 0x2A3D, 0, 401, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 64, 0, 0, 0, 139, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 140, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 155, 0, 0x2A4A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 155, 0, 0x2A4A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 follow-up of WAIT */
const u16 ibuki_exca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_070[76] = {
    L4(1, 0, 273, 0, 0, 225, 0, 0x2A68, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 226, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 227, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 228, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 229, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 230, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 231, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 232, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 follow-up of WAIT */
const u16 ibuki_exca_071_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_071[76] = {
    L4(1, 0, 273, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 follow-up of APPEAR 1 */
const u16 ibuki_exca_072_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_072[92] = {
    L4(2, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 follow-up of APPEAR 2 */
const u16 ibuki_exca_073_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_073[92] = {
    L4(1, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 follow-up of ATTACK 1 SP */
const u16 ibuki_exca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_074[60] = {
    L4(3, 0, 274, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 1195, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1196, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 1197, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1198, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1199, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 1200, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 follow-up of ATTACK 1 SP */
const u16 ibuki_exca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_075[92] = {
    L4(3, 0, 273, 0, 0, 1194, 0, 0x2C2A, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 147, 0, 0x2A3D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 148, 0, 0x2A3E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 149, 0, 0x2A3F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 150, 0, 0x2A40, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 151, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 152, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 153, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 154, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 follow-up of ATTACK 4 M */
const u16 ibuki_exca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_076[76] = {
    L4(4, 0, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 follow-up of ATTACK 4 L */
const u16 ibuki_exca_077_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_077[76] = {
    L4(4, 0, 0, 0, 0, 248, 0, 0x2A68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 249, 0, 0x2A69, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 250, 0, 0x2A6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 251, 0, 0x2A6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 252, 0, 0x2A6C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 253, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 254, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 255, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 no name */
const u16 ibuki_exca_078_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ibuki_exca_078[180] = {
    L4(2, 0, 0, 0, 0, 1021, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1022, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1023, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1024, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 1025, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1036, 0, 0x2A81, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1037, 0, 0x2A82, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1039, 0, 0x2A65, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 1040, 0, 0x2A66, 0, 405, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 1041, 0, 0x2A67, 0, 405, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 117 entries */
const u16* const ibuki_saca[118] = {
    ibuki_saca_000,  /* 0 UP P GUARD P S */
    ibuki_saca_001,  /* 1 UP P GUARD P M */
    ibuki_saca_002,  /* 2 UP P GUARD P L */
    ibuki_saca_002,  /* 3 UP P GUARD K S */
    ibuki_saca_002,  /* 4 UP P GUARD K M */
    ibuki_saca_002,  /* 5 UP P GUARD K L */
    ibuki_saca_000,  /* 6 D P GUARD P S */
    ibuki_saca_001,  /* 7 D P GUARD P M */
    ibuki_saca_002,  /* 8 D P GUARD P L */
    ibuki_saca_002,  /* 9 D P GUARD K S */
    ibuki_saca_002,  /* 10 D P GUARD K M */
    ibuki_saca_002,  /* 11 D P GUARD K L */
    ibuki_saca_002,  /* 12 FUSHIN P S */
    ibuki_saca_002,  /* 13 FUSHIN P M */
    ibuki_saca_002,  /* 14 FUSHIN P L */
    ibuki_saca_002,  /* 15 FUSHIN K S */
    ibuki_saca_002,  /* 16 FUSHIN K M */
    ibuki_saca_002,  /* 17 FUSHIN K L */
    ibuki_saca_002,  /* 18 OKIAGARI P S */
    ibuki_saca_002,  /* 19 OKIAGARI P M */
    ibuki_saca_002,  /* 20 OKIAGARI P L */
    ibuki_saca_002,  /* 21 OKIAGARI K S */
    ibuki_saca_002,  /* 22 OKIAGARI K M */
    ibuki_saca_002,  /* 23 OKIAGARI K L */
    ibuki_saca_024,  /* 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    ibuki_saca_025,  /* 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ibuki_saca_026,  /* 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ibuki_saca_027,  /* 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ibuki_saca_028,  /* 28 ATTACK 2 S: 421+K light (routine Att_PL07_AT2) */
    ibuki_saca_029,  /* 29 ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) */
    ibuki_saca_030,  /* 30 ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) */
    ibuki_saca_031,  /* 31 ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    ibuki_saca_032,  /* 32 ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_033,  /* 33 ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_034,  /* 34 ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_034,  /* 35 ATTACK 3 SP: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_036,  /* 36 ATTACK 4 S: 236+P light (routine Att_PL07_AT1) */
    ibuki_saca_037,  /* 37 ATTACK 4 M: 236+P medium (routine Att_PL07_AT1) */
    ibuki_saca_038,  /* 38 ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) */
    ibuki_saca_039,  /* 39 ATTACK 4 SP: EX 236+PP (routine Att_PL07_AT1) */
    ibuki_saca_040,  /* 40 ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_041,  /* 41 ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_042,  /* 42 ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_043,  /* 43 ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_044,  /* 44 ATTACK 6 S: not started by a command */
    ibuki_saca_044,  /* 45 ATTACK 6 M: not started by a command */
    ibuki_saca_044,  /* 46 ATTACK 6 L: not started by a command */
    ibuki_saca_044,  /* 47 ATTACK 6 SP: not started by a command */
    ibuki_saca_048,  /* 48 ATTACK 7 S: air 236+P light (routine Att_PL07_AT3) */
    ibuki_saca_049,  /* 49 ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3) */
    ibuki_saca_050,  /* 50 ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) */
    ibuki_saca_051,  /* 51 ATTACK 7 SP: air EX 236+PP (routine Att_PL07_AT3) */
    ibuki_saca_052,  /* 52 ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_053,  /* 53 ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_054,  /* 54 ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_055,  /* 55 ATTACK 8 SP: not started by a command */
    ibuki_saca_056,  /* 56 ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ibuki_saca_056,  /* 57 ATTACK 9 M: SA II 23623+P (routine Att_PL07_SA2) */
    ibuki_saca_056,  /* 58 ATTACK 9 L: SA II 23623+P (routine Att_PL07_SA2) */
    ibuki_saca_056,  /* 59 ATTACK 9 SP: SA II 23623+P (routine Att_PL07_SA2) */
    ibuki_saca_060,  /* 60 ATTACK 10 S: SA I air 23623+P light (routine Att_PL07_SA3) */
    ibuki_saca_061,  /* 61 ATTACK 10 M: SA I air 23623+P medium (routine Att_PL07_SA3) */
    ibuki_saca_062,  /* 62 ATTACK 10 L: SA I air 23623+P heavy/EX (routine Att_PL07_SA3) */
    ibuki_saca_062,  /* 63 ATTACK 10 SP: SA I air 23623+P heavy/EX (routine Att_PL07_SA3) */
    ibuki_saca_064,  /* 64 ATTACK 11 S: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_065,  /* 65 ATTACK 11 M: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_066,  /* 66 ATTACK 11 L: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_067,  /* 67 ATTACK 11 SP: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_068,  /* 68 ATTACK 12 S: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_069,  /* 69 ATTACK 12 M: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_070,  /* 70 ATTACK 12 L: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_071,  /* 71 ATTACK 12 SP: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_072,  /* 72 ATTACK 13 S: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_073,  /* 73 ATTACK 13 M: after SA I air 23623+P (routine Att_PL07_SA3) */
    ibuki_saca_074,  /* 74 ATTACK 13 L: not started by a command */
    ibuki_saca_075,  /* 75 ATTACK 13 SP: not started by a command */
    ibuki_saca_076,  /* 76 not started by a command */
    ibuki_saca_076,  /* 77 not started by a command */
    ibuki_saca_076,  /* 78 not started by a command */
    ibuki_saca_076,  /* 79 not started by a command */
    ibuki_saca_080,  /* 80 not started by a command */
    ibuki_saca_080,  /* 81 not started by a command */
    ibuki_saca_080,  /* 82 not started by a command */
    ibuki_saca_080,  /* 83 not started by a command */
    ibuki_saca_080,  /* 84 not started by a command */
    ibuki_saca_080,  /* 85 not started by a command */
    ibuki_saca_080,  /* 86 not started by a command */
    ibuki_saca_080,  /* 87 not started by a command */
    ibuki_saca_080,  /* 88 not started by a command */
    ibuki_saca_080,  /* 89 not started by a command */
    ibuki_saca_080,  /* 90 not started by a command */
    ibuki_saca_080,  /* 91 not started by a command */
    ibuki_saca_092,  /* 92 not started by a command */
    ibuki_saca_092,  /* 93 not started by a command */
    ibuki_saca_092,  /* 94 not started by a command */
    ibuki_saca_092,  /* 95 not started by a command */
    ibuki_saca_096,  /* 96 not started by a command */
    ibuki_saca_097,  /* 97 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_098,  /* 98 not started by a command */
    ibuki_saca_099,  /* 99 not started by a command */
    ibuki_saca_099,  /* 100 not started by a command */
    ibuki_saca_099,  /* 101 not started by a command */
    ibuki_saca_102,  /* 102 EX 214+KK (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_103,  /* 103 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_104,  /* 104 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_105,  /* 105 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_106,  /* 106 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_107,  /* 107 623+P light (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_108,  /* 108 623+P medium (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_109,  /* 109 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_109,  /* 110 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_111,  /* 111 236+K light (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_112,  /* 112 236+K medium (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_113,  /* 113 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_113,  /* 114 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    ibuki_saca_115,  /* 115 after 214+K (routine Att_CHOUCHUURENGEKI) */
    ibuki_saca_116,  /* 116 after 214+K (routine Att_CHOUCHUURENGEKI) */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 ibuki_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BD, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BE, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BF, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C0, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C1, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C2, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C3, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70C7, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1536, 8960), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 ibuki_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70C7, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70C6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70C6, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C3, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C2, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BE, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BD, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 ibuki_saca_002_head[4] = { HEAD(4, 0, 0, 12, 0, 0, 0) };
const u16 ibuki_saca_002[12] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2A01, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
const u16 ibuki_saca_024_head[4] = { HEAD(6, 22, 9, 10, 0, 3, 28) };
const u16 ibuki_saca_024[292] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1179, 0, 0x2C1D, 0, 117, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(1, 0, 358, 0, 0, 1180, 0, 0x2C1E, 0, 117, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 1181, 0, 0x2C1F, 0, 117, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 268, 0, 0, 1182, 0, 0x2C20, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2C21, -58, 118, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2D4D, -59, 119, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 1184, 0, 0x2D4E, -61, 120, 0, 128, 65, 1, 14, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 1185, 0, 0x2D4F, 61, 121, 0, 0, 65, 1, 15, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1186, 0, 0x2D50, 62, 160, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 62, 161, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 62, 186, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 62, 187, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 62, 188, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 62, 189, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 62, 189, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 62, 189, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 1188, 0, 0x2D50, 0, 190, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 191, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
const u16 ibuki_saca_025_head[4] = { HEAD(6, 22, 11, 10, 0, 3, 28) };
const u16 ibuki_saca_025[316] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1179, 0, 0x2C1D, 0, 192, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 358, 0, 0, 1180, 0, 0x2C1E, 0, 192, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 1181, 0, 0x2C1F, 0, 192, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 269, 0, 0, 1182, 0, 0x2C20, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2C21, -63, 193, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2D4D, -59, 194, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 1184, 0, 0x2D4E, -64, 195, 0, 128, 65, 1, 12, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 1185, 0, 0x2D4F, 64, 196, 0, 0, 65, 1, 15, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1186, 0, 0x2D50, 65, 197, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 65, 198, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 65, 213, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 65, 214, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 65, 220, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 65, 221, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 65, 222, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 222, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1188, 0, 0x2D50, 0, 222, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1188, 0, 0x2D50, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 223, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
const u16 ibuki_saca_026_head[4] = { HEAD(6, 22, 13, 11, 0, 4, 28) };
const u16 ibuki_saca_026[328] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1179, 0, 0x2C1D, 0, 224, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 358, 0, 0, 1180, 0, 0x2C1E, 0, 224, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 0, 0, 0, 1181, 0, 0x2C1F, 0, 224, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 270, 0, 0, 1182, 0, 0x2C20, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2C21, -66, 225, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2D4D, -173, 226, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 1184, 0, 0x2D4E, -60, 227, 0, 128, 65, 1, 12, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 1185, 0, 0x2D4F, -67, 228, 0, 0, 65, 1, 15, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1186, 0, 0x2D50, 68, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 68, 230, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 68, 231, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 68, 232, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 68, 233, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 68, 234, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 68, 234, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 235, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1188, 0, 0x2D55, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 236, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
const u16 ibuki_saca_027_head[4] = { HEAD(6, 20, 15, 11, 0, 4, 28) };
const u16 ibuki_saca_027[520] = {
    CMD(CM_JSR, 8, 54, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 27, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1179, 0, 0x2C1D, 0, 237, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(1, 0, 358, 0, 0, 1180, 0, 0x2C1E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 1181, 0, 0x2C1F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 270, 0, 0, 1182, 0, 0x2C20, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2C21, -149, 251, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2D4D, -150, 226, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 1184, 0, 0x2D4E, -151, 227, 0, 128, 65, 1, 12, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 1185, 0, 0x2D4F, -152, 228, 0, 0, 65, 1, 15, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1186, 0, 0x2D50, 153, 229, 0, 0, 64, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 153, 230, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 153, 231, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 153, 232, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 153, 233, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D50, 153, 234, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D55, 153, 234, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 74, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA3, 7, 75, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 235, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1188, 0, 0x2D55, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 236, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1188, 0, 0x2D50, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 1904, 0, 104, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1188, 0, 0x2D55, 0, 235, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D50, 0, 235, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 235, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 236, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 236, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 236, 1904, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 236, 1904, 0, 104, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 421+K light (routine Att_PL07_AT2) */
const u16 ibuki_saca_028_head[4] = { HEAD(6, 20, 9, 13, 2, 0, 27) };
const u16 ibuki_saca_028[556] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 28, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1201, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1202, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 358, 0, 0, 1203, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 281, 0, 0, 1204, 0, 0x2CEC, 0, 139, 0, 0, 0, 1, 51, 0, 0, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 1205, 0, 0x2CDF, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1206, 0, 0x2CE0, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1207, 0, 0x2CE1, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1208, 0, 0x2CE2, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1209, 0, 0x2CE3, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1210, 0, 0x2CE4, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1211, 0, 0x2CE5, -81, 140, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1212, 0, 0x2CE6, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 77, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1213, 0, 0x2CE6, 0, 139, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1214, 0, 0x2CA5, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1215, 0, 0x2ABE, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1216, 0, 0x2ABD, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1217, 0, 0x2ABC, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1218, 0, 0x2ABB, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1219, 0, 0x2ABA, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1220, 0, 0x2AB9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1221, 0, 0x2AB8, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 100, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1222, 0, 0x2CE7, 0, 141, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(2, 0, 0, 0, 0, 1223, 0, 0x2CE8, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1224, 0, 0x2CE9, -82, 142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 78, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 1225, 0, 0x2CEA, 0, 141, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1226, 0, 0x2CEB, 0, 141, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1238, 0, 0x2A79, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1239, 0, 0x2A7A, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1240, 0, 0x2A7B, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1241, 0, 0x2A7C, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1242, 0, 0x2A7D, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1243, 0, 0x2A7E, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1227, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1228, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1229, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) */
const u16 ibuki_saca_029_head[4] = { HEAD(6, 20, 11, 13, 0, 2, 27) };
const u16 ibuki_saca_029[556] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 29, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1201, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1202, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 358, 0, 0, 1203, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 281, 0, 0, 1204, 0, 0x2CEC, 0, 179, 0, 0, 0, 1, 51, 0, 0, 204, 0, 0),
    L6(4, 0, 0, 0, 0, 1205, 0, 0x2CDF, 0, 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1206, 0, 0x2CE0, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1207, 0, 0x2CE1, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1208, 0, 0x2CE2, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1209, 0, 0x2CE3, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1210, 0, 0x2CE4, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1211, 0, 0x2CE5, -81, 140, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1212, 0, 0x2CE6, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 80, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1213, 0, 0x2CE6, 0, 139, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1214, 0, 0x2CA5, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1215, 0, 0x2ABE, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1216, 0, 0x2ABD, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1217, 0, 0x2ABC, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1218, 0, 0x2ABB, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1219, 0, 0x2ABA, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1220, 0, 0x2AB9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1221, 0, 0x2AB8, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 100, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1222, 0, 0x2CE7, 0, 141, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 1223, 0, 0x2CE8, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1224, 0, 0x2CE9, -89, 142, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 81, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 1225, 0, 0x2CEA, 0, 141, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1226, 0, 0x2CEB, 0, 141, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1238, 0, 0x2A79, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1239, 0, 0x2A7A, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1240, 0, 0x2A7B, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1241, 0, 0x2A7C, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1242, 0, 0x2A7D, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1243, 0, 0x2A7E, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1227, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1228, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1229, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) */
const u16 ibuki_saca_030_head[4] = { HEAD(6, 20, 13, 14, 0, 2, 27) };
const u16 ibuki_saca_030[556] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 30, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1201, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1202, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 358, 0, 0, 1203, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 281, 0, 0, 1204, 0, 0x2CEC, 0, 179, 0, 0, 0, 1, 51, 0, 0, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 1205, 0, 0x2CDF, 0, 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1206, 0, 0x2CE0, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1207, 0, 0x2CE1, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1208, 0, 0x2CE2, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1209, 0, 0x2CE3, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1210, 0, 0x2CE4, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1211, 0, 0x2CE5, -81, 140, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1212, 0, 0x2CE6, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 83, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1213, 0, 0x2CE6, 0, 139, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1214, 0, 0x2CA5, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1215, 0, 0x2ABE, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1216, 0, 0x2ABD, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1217, 0, 0x2ABC, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1218, 0, 0x2ABB, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1219, 0, 0x2ABA, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1220, 0, 0x2AB9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1221, 0, 0x2AB8, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 100, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1222, 0, 0x2CE7, 0, 141, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 1223, 0, 0x2CE8, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1224, 0, 0x2CE9, -90, 142, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 84, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 1225, 0, 0x2CEA, 0, 141, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1226, 0, 0x2CEB, 0, 141, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1238, 0, 0x2A79, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1239, 0, 0x2A7A, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1240, 0, 0x2A7B, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1241, 0, 0x2A7C, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1242, 0, 0x2A7D, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1243, 0, 0x2A7E, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1227, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1228, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1229, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
const u16 ibuki_saca_031_head[4] = { HEAD(6, 20, 15, 15, 0, 2, 27) };
const u16 ibuki_saca_031[556] = {
    CMD(CM_JSR, 8, 53, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 31, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1201, 0, 0x2A6A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1202, 0, 0x2A68, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1203, 0, 0x2A69, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 281, 0, 0, 1204, 0, 0x2CEC, 0, 179, 0, 0, 0, 1, 51, 0, 0, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 1205, 0, 0x2CDF, 0, 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1206, 0, 0x2CE0, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1207, 0, 0x2CE1, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1208, 0, 0x2CE2, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1209, 0, 0x2CE3, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1210, 0, 0x2CE4, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1211, 0, 0x2CE5, -147, 140, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1212, 0, 0x2CE6, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1213, 0, 0x2CE6, 0, 139, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1214, 0, 0x2CA5, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1215, 0, 0x2ABE, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1216, 0, 0x2ABD, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1217, 0, 0x2ABC, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1218, 0, 0x2ABB, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1219, 0, 0x2ABA, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1220, 0, 0x2AB9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1221, 0, 0x2AB8, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 100, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 1222, 0, 0x2CE7, 0, 141, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 1223, 0, 0x2CE8, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1224, 0, 0x2CE9, -148, 142, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 120, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 1225, 0, 0x2CEA, 0, 141, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1226, 0, 0x2CEB, 0, 141, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1238, 0, 0x2A79, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1239, 0, 0x2A7A, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1240, 0, 0x2A7B, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1241, 0, 0x2A7C, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1242, 0, 0x2A7D, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1243, 0, 0x2A7E, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1227, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1228, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1229, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_032_head[4] = { HEAD(6, 0, 24, 8, 0, 1, 0) };
const u16 ibuki_saca_032[160] = {
    CMD(CM_CAFR, 2, 1, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 279, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 11, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 12, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1169, 0, 0x2A6C, -50, 131, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 1170, 0, 0x2BBD, 0, 3, 0, 0, 0, 21, 0, 0, 0, 232, 0, 0),
    L6(6, 21, 0, 0, 0, 1171, 0, 0x2B98, 0, 3, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(4, 0, 0, 0, 0, 1172, 0, 0x2B99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(3, 0, 0, 0, 0, 1173, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 1174, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 1175, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1176, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1177, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_033_head[4] = { HEAD(6, 0, 26, 9, 0, 1, 0) };
const u16 ibuki_saca_033[160] = {
    CMD(CM_CAFR, 2, 1, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 279, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 11, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 12, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1169, 0, 0x2A6C, -50, 243, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 1170, 0, 0x2BBD, 0, 3, 0, 0, 0, 21, 0, 0, 0, 232, 0, 0),
    L6(6, 21, 0, 0, 0, 1171, 0, 0x2B98, 0, 3, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(4, 0, 0, 0, 0, 1172, 0, 0x2B99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(4, 0, 0, 0, 0, 1173, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 1174, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 1175, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1176, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1177, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI), 35 ATTACK 3 SP: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_034_head[4] = { HEAD(6, 0, 28, 10, 0, 1, 0) };
const u16 ibuki_saca_034[160] = {
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 279, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 11, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1168, 0, 0x2D97, 0, 130, 0, 0, 0, 30, 12, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 1169, 0, 0x2A6C, -50, 244, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(13, 0, 0, 0, 0, 1170, 0, 0x2BBD, 0, 3, 0, 0, 0, 21, 0, 0, 0, 232, 0, 0),
    L6(6, 21, 0, 0, 0, 1171, 0, 0x2B98, 0, 3, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(5, 0, 0, 0, 0, 1172, 0, 0x2B99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(4, 0, 0, 0, 0, 1173, 0, 0x2B9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 1174, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 1175, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1176, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1177, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 236+P light (routine Att_PL07_AT1) */
const u16 ibuki_saca_036_head[4] = { HEAD(6, 32, 25, 7, 0, 1, 26) };
const u16 ibuki_saca_036[220] = {
    CMD(CM_CAFR, 2, 1, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1309, 0, 0x2B6E, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1310, 0, 0x2B6D, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1311, 0, 0x2B6C, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 279, 0, 0, 1312, 0, 0x2B6B, 0, 208, 0, 0, 0, 1, 39, 0, 0, 0, 0, 0),
    L6(2, 0, 360, 0, 0, 1313, 0, 0x2B6A, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1314, 0, 0x2B69, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1163, 0, 0x2DDC, 0, 151, 0, 0, 0, 1, 48, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1164, 0, 0x2DDD, -98, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 236+P medium (routine Att_PL07_AT1) */
const u16 ibuki_saca_037_head[4] = { HEAD(6, 32, 27, 8, 0, 1, 26) };
const u16 ibuki_saca_037[220] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1309, 0, 0x2B6E, 0, 208, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1310, 0, 0x2B6D, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1311, 0, 0x2B6C, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 279, 0, 0, 1312, 0, 0x2B6B, 0, 208, 0, 0, 0, 1, 39, 0, 0, 0, 0, 0),
    L6(2, 0, 360, 0, 0, 1313, 0, 0x2B6A, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1314, 0, 0x2B69, 0, 151, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1163, 0, 0x2DDC, 0, 151, 0, 0, 0, 1, 49, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, -99, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 76, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) */
const u16 ibuki_saca_038_head[4] = { HEAD(6, 32, 29, 9, 0, 1, 26) };
const u16 ibuki_saca_038[232] = {
    CMD(CM_CAFR, 2, 1, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1309, 0, 0x2B6E, 0, 208, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1310, 0, 0x2B6D, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1311, 0, 0x2B6C, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 279, 0, 0, 1312, 0, 0x2B6B, 0, 208, 0, 0, 0, 1, 39, 0, 0, 0, 0, 0),
    L6(2, 0, 360, 0, 0, 1313, 0, 0x2B6A, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1314, 0, 0x2B69, 0, 151, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1163, 0, 0x2DDC, 0, 151, 0, 0, 0, 1, 50, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, -101, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 77, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 236+PP (routine Att_PL07_AT1) */
const u16 ibuki_saca_039_head[4] = { HEAD(6, 32, 31, 10, 0, 1, 26) };
const u16 ibuki_saca_039[220] = {
    CMD(CM_JSR, 8, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1309, 0, 0x2B6E, 0, 256, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1310, 0, 0x2B6D, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1311, 0, 0x2B6C, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 279, 0, 0, 1312, 0, 0x2B6B, 0, 256, 0, 0, 0, 1, 39, 0, 0, 0, 0, 0),
    L6(2, 0, 360, 0, 0, 1313, 0, 0x2B6A, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1314, 0, 0x2B69, 0, 151, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1163, 0, 0x2DDC, 0, 151, 0, 0, 0, 1, 50, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, -101, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1858, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1164, 0, 0x2DDD, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 1166, 0, 0x2B67, 0, 2, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 1167, 0, 0x2B66, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 67, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_040_head[4] = { HEAD(6, 0, 9, 13, 0, 3, 0) };
const u16 ibuki_saca_040[616] = {
    CMD(CM_RMJA, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1331, 0, 0x2A15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1332, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 410, 0, 0),
    L6(1, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 414, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -77, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 6656, 0, 8, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1375, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 414, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -78, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16395, 16386, 16395), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 257, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 257, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_041_head[4] = { HEAD(6, 0, 11, 13, 0, 3, 0) };
const u16 ibuki_saca_041[796] = {
    CMD(CM_RJA, 5, 97, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1331, 0, 0x2A15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1332, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 410, 0, 0),
    L6(2, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(2, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 414, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 269, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -80, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1375, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 414, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 269, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -142, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 6656, 0, 8, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 6656, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1375, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 414, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 269, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -143, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16394, 16386, 16394), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 258, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 258, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_042_head[4] = { HEAD(6, 0, 13, 13, 0, 3, 0) };
const u16 ibuki_saca_042[412] = {
    L6(2, 0, 0, 0, 0, 1331, 0, 0x2A15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1332, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(2, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(2, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 398, 0, 0),
    L6(2, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 270, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -144, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 398, 0, 0),
    L6(1, 20, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 270, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -145, 262, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 259, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 1341, 0, 0x2BEF, 0, 259, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 115, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 5, 116, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8195, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_043_head[4] = { HEAD(6, 32, 9, 15, 0, 1, 0) };
const u16 ibuki_saca_043[292] = {
    L6(1, 0, 0, 0, 0, 1352, 0, 0x2A52, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1353, 0, 0x2A53, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1354, 0, 0x2A54, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1355, 0, 0x2A55, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1356, 0, 0x2C6B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 418, 0, 0),
    L6(1, 0, 270, 0, 0, 1357, 0, 0x2C6C, 0, 2, 0, 0, 0, 30, 13, 0, 0, 420, 0, 0),
    L6(2, 0, 0, 0, 0, 1358, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 422, 0, 0),
    L6(2, 0, 0, 0, 0, 1359, 0, 0x2C6E, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1360, 0, 0x2C6F, -112, 169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1361, 0, 0x2C70, 0, 42, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 1362, 0, 0x2C71, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1363, 0, 0x2C72, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1364, 0, 0x2C73, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1365, 0, 0x2C74, 0, 42, 0, 0, 0, 0, 0, 0, 0, 424, 0, 0),
    L6(2, 0, 0, 0, 0, 1366, 0, 0x2C75, 0, 42, 0, 0, 0, 0, 0, 0, 0, 424, 0, 0),
    L6(2, 0, 0, 0, 0, 1367, 0, 0x2C76, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1368, 0, 0x2C77, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1369, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1370, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1371, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1372, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1373, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: not started by a command, 45 ATTACK 6 M: not started by a command, 46 ATTACK 6 L: not started by a command, 47 ATTACK 6 SP: not started by a command */
const u16 ibuki_saca_044_head[4] = { HEAD(6, 0, 9, 8, 0, 4, 0) };
const u16 ibuki_saca_044[280] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1179, 0, 0x2C1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 356, 0, 0, 1180, 0, 0x2C1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 0, 0, 0, 1181, 0, 0x2C1F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 270, 0, 0, 1182, 0, 0x2C20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2C21, -93, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1183, 0, 0x2D4D, -94, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 1184, 0, 0x2D4E, -95, 119, 0, 128, 1, 1, 13, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 1185, 0, 0x2D4F, -96, 120, 0, 0, 1, 1, 15, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1186, 0, 0x2D50, 97, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1185, 0, 0x2D55, 97, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1186, 0, 0x2D50, 68, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 1185, 0, 0x2D50, 0, 71, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1187, 0, 0x2D55, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1188, 0, 0x2D50, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1189, 0, 0x2D51, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1190, 0, 0x2D52, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1191, 0, 0x2D53, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1192, 0, 0x2D54, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1193, 0, 0x2D72, 0, 72, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: air 236+P light (routine Att_PL07_AT3) */
const u16 ibuki_saca_048_head[4] = { HEAD(6, 22, 8, 0, 0, 0, 0) };
const u16 ibuki_saca_048[340] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 64, 2, 48, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1025, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 1242, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3) */
const u16 ibuki_saca_049_head[4] = { HEAD(6, 22, 10, 0, 0, 0, 0) };
const u16 ibuki_saca_049[340] = {
    CMD(CM_JSR, 8, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(9, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 64, 2, 49, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1025, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) */
const u16 ibuki_saca_050_head[4] = { HEAD(6, 22, 12, 0, 0, 0, 0) };
const u16 ibuki_saca_050[340] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(10, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 64, 2, 50, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1025, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: air EX 236+PP (routine Att_PL07_AT3) */
const u16 ibuki_saca_051_head[4] = { HEAD(6, 22, 14, 0, 0, 0, 0) };
const u16 ibuki_saca_051[412] = {
    CMD(CM_JSR, 8, 52, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 4, 8197, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 0, 2, 51, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 64, 2, 82, 0, 0, 0, 10, 0),
    L6(4, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 0, 2, 133, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, 0, 157, 0, 0, 64, 2, 134, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1025, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1026, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1027, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1028, 0, 0x2A79, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1029, 0, 0x2A7A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_052_head[4] = { HEAD(6, 0, 32, 22, 0, 1, 112) };
const u16 ibuki_saca_052[400] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EF1, 0, 237, 0, 0, 0, 13, 62, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF2, 0, 237, 0, 0, 0, 31, 1, 0, 0, 306, 0, 0),
    L6(2, 0, 362, 0, 0, 0, 0, 0x2EF3, 0, 237, 0, 0, 0, 0, 0, 0, 0, 308, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF4, 0, 237, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF5, 0, 237, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF6, 0, 237, 0, 0, 0, 0, 0, 0, 0, 314, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF7, 0, 237, 0, 0, 0, 0, 0, 0, 0, 316, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF8, 0, 237, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(32, 0, 0, 0, 0, 0, 0, 0x2EF9, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EFA, 0, 237, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EFB, 0, 237, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0),
    L6(1, 0, 330, 0, 0, 2181, 0, 0x2EFC, 0, 332, 0, 0, 0, 2, 213, 0, 0, 324, 0, 0),
    L6(3, 0, 0, 0, 0, 2182, 0, 0x2EFD, 0, 333, 0, 0, 0, 2, 214, 0, 0, 326, 0, 0),
    L6(3, 0, 0, 0, 0, 2183, 0, 0x2EFE, 0, 334, 0, 0, 0, 2, 215, 0, 0, 328, 0, 0),
    L6(3, 0, 0, 0, 0, 2184, 0, 0x2EFF, 0, 335, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(2, 0, 0, 0, 0, 2185, 0, 0x2F00, 0, 336, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(2, 0, 0, 0, 0, 2186, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 2187, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2188, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F02, 0, 337, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F03, 0, 338, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F04, 0, 339, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F05, 0, 340, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F06, 0, 341, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F07, 0, 1, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_053_head[4] = { HEAD(6, 0, 32, 26, 0, 1, 112) };
const u16 ibuki_saca_053[400] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EF1, 0, 237, 0, 0, 0, 13, 62, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF2, 0, 237, 0, 0, 0, 31, 1, 0, 0, 306, 0, 0),
    L6(2, 0, 362, 0, 0, 0, 0, 0x2EF3, 0, 237, 0, 0, 0, 0, 0, 0, 0, 308, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF4, 0, 237, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF5, 0, 237, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF6, 0, 237, 0, 0, 0, 0, 0, 0, 0, 314, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF7, 0, 237, 0, 0, 0, 0, 0, 0, 0, 316, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF8, 0, 237, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(33, 0, 0, 0, 0, 0, 0, 0x2EF9, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EFA, 0, 237, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EFB, 0, 237, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0),
    L6(1, 0, 330, 0, 0, 2181, 0, 0x2EFC, 0, 332, 0, 0, 0, 2, 216, 0, 0, 324, 0, 0),
    L6(3, 0, 0, 0, 0, 2182, 0, 0x2EFD, 0, 333, 0, 0, 0, 2, 217, 0, 0, 326, 0, 0),
    L6(3, 0, 0, 0, 0, 2183, 0, 0x2EFE, 0, 334, 0, 0, 0, 2, 218, 0, 0, 328, 0, 0),
    L6(3, 0, 0, 0, 0, 2184, 0, 0x2EFF, 0, 335, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(2, 0, 0, 0, 0, 2185, 0, 0x2F00, 0, 336, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(2, 0, 0, 0, 0, 2186, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 2187, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2188, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F02, 0, 337, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F03, 0, 338, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F04, 0, 339, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F05, 0, 340, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F06, 0, 341, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F07, 0, 1, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_054_head[4] = { HEAD(6, 0, 32, 30, 0, 1, 112) };
const u16 ibuki_saca_054[400] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EF1, 0, 237, 0, 0, 0, 13, 62, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF2, 0, 237, 0, 0, 0, 31, 1, 0, 0, 306, 0, 0),
    L6(2, 0, 362, 0, 0, 0, 0, 0x2EF3, 0, 237, 0, 0, 0, 0, 0, 0, 0, 308, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF4, 0, 237, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF5, 0, 237, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF6, 0, 237, 0, 0, 0, 0, 0, 0, 0, 314, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF7, 0, 237, 0, 0, 0, 0, 0, 0, 0, 316, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EF8, 0, 237, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(34, 0, 0, 0, 0, 0, 0, 0x2EF9, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2EFA, 0, 237, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2EFB, 0, 237, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0),
    L6(1, 0, 330, 0, 0, 2181, 0, 0x2EFC, 0, 332, 0, 0, 0, 2, 219, 0, 0, 324, 0, 0),
    L6(3, 0, 0, 0, 0, 2182, 0, 0x2EFD, 0, 333, 0, 0, 0, 2, 220, 0, 0, 326, 0, 0),
    L6(3, 0, 0, 0, 0, 2183, 0, 0x2EFE, 0, 334, 0, 0, 0, 2, 221, 0, 0, 328, 0, 0),
    L6(3, 0, 0, 0, 0, 2184, 0, 0x2EFF, 0, 335, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(2, 0, 0, 0, 0, 2185, 0, 0x2F00, 0, 336, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(2, 0, 0, 0, 0, 2186, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 2187, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2188, 0, 0x2F01, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F02, 0, 337, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F03, 0, 338, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F04, 0, 339, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F05, 0, 340, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F06, 0, 341, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F07, 0, 1, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F0B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: not started by a command */
const u16 ibuki_saca_055_head[4] = { HEAD(6, 0, 32, 15, 0, 3, 112) };
const u16 ibuki_saca_055[928] = {
    CMD(CM_STOP, 0, 24, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 2, 0, 0, 0, 0x2F0C, 0, 202, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0),
    L6(6, 0, 0, 2, 0, 0, 0, 0x2F0D, 0, 202, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(9, 0, 0, 2, 0, 0, 0, 0x2F0E, 0, 202, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0),
    L6(10, 30, 0, 2, 0, 0, 0, 0x2F0F, -179, 343, 0, 135, 0, 0, 0, 0, 0, 354, 0, 0),
    CMD(CM_JMP, 5, 55, 54), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 2, 0, 2189, 0, 0x2F10, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 2190, 0, 0x2F11, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 2191, 0, 0x2F21, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F1F, 0, 202, 0, 0, 0, 0, 0, 768, 0, 356, 0, 0),
    L6(1, 21, 0, 2, 0, 0, 0, 0x2F20, 0, 202, 0, 0, 0, 0, 0, 768, 0, 358, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0C, 0, 202, 0, 0, 0, 0, 0, 768, 0, 360, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0D, 0, 202, 0, 0, 0, 0, 0, 768, 0, 362, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0E, 0, 202, 0, 0, 0, 0, 0, 768, 0, 364, 0, 0),
    L6(10, 30, 0, 1, 0, 0, 0, 0x2F0F, -180, 343, 0, 147, 0, 0, 0, 768, 0, 366, 0, 0),
    CMD(CM_JMP, 5, 55, 54), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 2189, 0, 0x2F10, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 2190, 0, 0x2F11, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 2191, 0, 0x2F21, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F1F, 0, 202, 0, 0, 0, 0, 0, 768, 0, 368, 0, 0),
    L6(1, 21, 0, 1, 0, 0, 0, 0x2F20, 0, 202, 0, 0, 0, 0, 0, 768, 0, 370, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0C, 0, 202, 0, 0, 0, 0, 0, 768, 0, 348, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0D, 0, 202, 0, 0, 0, 0, 0, 768, 0, 350, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0E, 0, 202, 0, 0, 0, 0, 0, 768, 0, 352, 0, 0),
    L6(10, 30, 0, 2, 0, 0, 0, 0x2F0F, -179, 343, 0, 159, 0, 0, 0, 768, 0, 354, 0, 0),
    CMD(CM_JMP, 5, 55, 54), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 2, 0, 2189, 0, 0x2F10, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 2190, 0, 0x2F11, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 2191, 0, 0x2F21, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F1F, 0, 202, 0, 0, 0, 0, 0, 768, 0, 356, 0, 0),
    L6(1, 21, 0, 2, 0, 0, 0, 0x2F20, 0, 202, 0, 0, 0, 0, 0, 768, 0, 358, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0C, 0, 202, 0, 0, 0, 0, 0, 768, 0, 360, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0D, 0, 202, 0, 0, 0, 0, 0, 768, 0, 362, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F0E, 0, 202, 0, 0, 0, 0, 0, 768, 0, 364, 0, 0),
    L6(10, 30, 0, 1, 0, 0, 0, 0x2F0F, -180, 343, 0, 171, 0, 0, 0, 768, 0, 366, 0, 0),
    CMD(CM_JMP, 5, 55, 54), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 2189, 0, 0x2F10, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 2190, 0, 0x2F11, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 2191, 0, 0x2F21, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2F1F, 0, 202, 0, 0, 0, 0, 0, 768, 0, 368, 0, 0),
    L6(1, 21, 0, 1, 0, 0, 0, 0x2F20, 0, 202, 0, 0, 0, 0, 0, 768, 0, 370, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0C, 0, 202, 0, 0, 0, 0, 0, 768, 0, 372, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0D, 0, 202, 0, 0, 0, 0, 0, 768, 0, 374, 0, 0),
    L6(1, 0, 0, 2, 0, 0, 0, 0x2F0E, 0, 202, 0, 0, 0, 0, 0, 768, 0, 376, 0, 0),
    L6(10, 30, 0, 2, 0, 0, 0, 0x2F0F, -181, 343, 0, 128, 0, 0, 0, 768, 0, 378, 0, 0),
    L6(2, 0, 0, 2, 0, 2189, 0, 0x2F10, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 2190, 0, 0x2F11, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 2191, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 2192, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 2193, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 2194, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 2, 0, 2195, 0, 0x2F12, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 173, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 174, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 175, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 176, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 2, 0, 0, 0, 0x2F13, 0, 342, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(6, 21, 0, 2, 0, 0, 0, 0x2F14, 0, 342, 0, 0, 0, 0, 0, 0, 0, 382, 0, 0),
    L6(6, 0, 0, 2, 0, 0, 0, 0x2F15, 0, 342, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0),
    L6(5, 0, 0, 2, 0, 0, 0, 0x2F16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 386, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2F17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2F18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F1C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2), 57 ATTACK 9 M: SA II 23623+P (routine Att_PL07_SA2), 58 ATTACK 9 L: SA II 23623+P (routine Att_PL07_SA2), 59 ATTACK 9 SP: SA II 23623+P (routine Att_PL07_SA2) */
const u16 ibuki_saca_056_head[4] = { HEAD(6, 0, 33, 24, 0, 13, 35) };
const u16 ibuki_saca_056[1036] = {
    CMD(CM_JSR, 8, 35, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1168, 0, 0x2D97, 0, 163, 0, 0, 0, 13, 18, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D98, 0, 163, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(27, 0, 0, 0, 0, 0, 0, 0x2D99, 0, 163, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(21, 0, 363, 0, 0, 0, 0, 0x2D99, 0, 163, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2D99, -52, 173, 0, 128, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1315, 0, 0x2D9A, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9B, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9C, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2D9D, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 318, 0, 0, 0, 0, 0x2D9E, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RNGC, 136, 8192, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 51, 0, 0x9C68, -83, 143, 0, 0, 0, 1, 56, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 62, 0, 0x9C69, -84, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 52, 0, 0x9C68, -87, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 63, 0, 0x9C69, -86, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 53, 0, 0x9C68, -130, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 64, 0, 0x9C69, -85, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 54, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 65, 0, 0x9C69, -132, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 55, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 66, 0, 0x9C69, -131, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 56, 44), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 51, 0, 0x9C68, -135, 143, 0, 0, 0, 1, 56, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 62, 0, 0x9C69, -136, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 52, 0, 0x9C68, -139, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 63, 0, 0x9C69, -138, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 53, 0, 0x9C68, -135, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 64, 0, 0x9C69, -137, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 54, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 65, 0, 0x9C69, -139, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 55, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 66, 0, 0x9C69, -138, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 56, 0, 0x9C68, -88, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 67, 0, 0x9C69, -167, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 57, 0, 0x9C68, -168, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 68, 0, 0x9C69, -169, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 58, 0, 0x9C68, 170, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 69, 0, 0x9C69, 170, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 59, 0, 0x9C68, 0, 145, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 70, 0, 0x9C69, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 60, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 71, 0, 0x9C69, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 61, 0, 0x9C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C67, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 72, 0, 0x9C69, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C6A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C6B, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x9C6C, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x9C6A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x9C6B, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x9C6C, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2DA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2DA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2DA7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 281, 0, 0, 1316, 0, 0x2A5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1317, 0, 0x9C6D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1318, 0, 0x9C6E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1319, 0, 0x9C6F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 274, 0, 0, 668, 0, 0x2B12, 0, 1, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0),
    L6(2, 0, 279, 0, 0, 669, 0, 0x2B13, 0, 1, 0, 0, 0, 30, 32, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 670, 0, 0x2B14, 0, 1, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 671, 0, 0x2B15, 0, 1, 0, 0, 0, 30, 32, 0, 0, 0, 0, 0),
    L6(10, 88, 0, 0, 0, 672, 0, 0x2B16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 156, 0, 0x2A45, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 157, 0, 0x2A46, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 158, 0, 0x2A47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 159, 0, 0x2A48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 160, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 160, 0, 0x2A49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: SA I air 23623+P light (routine Att_PL07_SA3) */
const u16 ibuki_saca_060_head[4] = { HEAD(6, 22, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_060[316] = {
    CMD(CM_JSR, 8, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 13, 28, 0, 0, 0, 0, 0),
    L6(50, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 20, 365, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 65, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 67, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT2, 16384, 16385, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 60, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 60, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 101, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1036, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1037, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1038, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: SA I air 23623+P medium (routine Att_PL07_SA3) */
const u16 ibuki_saca_061_head[4] = { HEAD(6, 22, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_061[316] = {
    CMD(CM_JSR, 8, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 13, 28, 0, 0, 0, 0, 0),
    L6(50, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 20, 365, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 68, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 69, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 70, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT2, 16384, 16385, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 61, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 61, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 114, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1036, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1037, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1038, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: SA I air 23623+P heavy/EX (routine Att_PL07_SA3), 63 ATTACK 10 SP: SA I air 23623+P heavy/EX (routine Att_PL07_SA3) */
const u16 ibuki_saca_062_head[4] = { HEAD(6, 22, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_062[316] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 65, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 13, 28, 0, 0, 0, 0, 0),
    L6(50, 0, 0, 0, 0, 1324, 0, 0x2CED, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(11, 20, 365, 0, 0, 1324, 0, 0x2CED, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 71, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 72, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 73, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT2, 16384, 16385, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 62, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 62, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 116, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 0, 0, 1030, 0, 0x2A7B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1031, 0, 0x2A7C, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1032, 0, 0x2A7D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1033, 0, 0x2A7E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1034, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1035, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1036, 0, 0x2A81, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1037, 0, 0x2A82, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 1038, 0, 0x2A83, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_064_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_064[124] = {
    L6(1, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_065_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_065[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 57, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 58, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_066_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_066[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 59, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 60, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_067_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_067[52] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 61, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 62, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_068_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_068[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 63, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 64, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_069_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_069[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 65, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 66, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_070_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_070[52] = {
    L6(2, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 67, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 68, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_071_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_071[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 69, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 70, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 72 ATTACK 13 S: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_072_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_072[40] = {
    L6(1, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 71, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 72, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: after SA I air 23623+P (routine Att_PL07_SA3) */
const u16 ibuki_saca_073_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_073[52] = {
    L6(3, 0, 330, 0, 0, 1325, 0, 0x2CEE, -104, 157, 0, 0, 0, 2, 73, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 330, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 2, 74, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1326, 0, 0x2CEF, 0, 158, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: not started by a command */
const u16 ibuki_saca_074_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_074[172] = {
    L6(1, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 75 ATTACK 13 SP: not started by a command */
const u16 ibuki_saca_075_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 25) };
const u16 ibuki_saca_075[172] = {
    L6(1, 0, 0, 0, 0, 1327, 0, 0x2CF0, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1328, 0, 0x2CF1, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1329, 0, 0x2CF2, 0, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1330, 0, 0x2CF3, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1244, 0, 0x2A7F, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1245, 0, 0x2A80, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1230, 0, 0x2A71, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1231, 0, 0x2A72, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1232, 0, 0x2A73, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 1233, 0, 0x2A74, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1234, 0, 0x2A75, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1235, 0, 0x2A76, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1236, 0, 0x2A77, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1237, 0, 0x2A78, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 76 not started by a command, 77 not started by a command, 78 not started by a command, 79 not started by a command */
const u16 ibuki_saca_076_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 33) };
const u16 ibuki_saca_076[108] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 141, 0, 0x2A45, 0, 385, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 236, 0, 0x2A5D, 0, 8, 0, 0, 0, 22, 20),
    L4(3, 0, 0, 0, 0, 238, 0, 0x2A5E, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 901, 0, 0x2C79, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 902, 0, 0x2C9A, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 903, 0, 0x2C7A, -115, 203, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 904, 0, 0x2C7B, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 905, 0, 0x2C7C, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 906, 0, 0x2C7D, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 907, 0, 0x2C7E, 0, 103, 0, 0, 0, 21, 0),
    L4(250, 0, 0, 0, 0, 908, 0, 0x2C7F, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 not started by a command, 81 not started by a command, 82 not started by a command, 83 not started by a command ... */
const u16 ibuki_saca_080_head[4] = { HEAD(2, 0, 0, 10, 0, 1, 33) };
const u16 ibuki_saca_080[12] = {
    L2(4, 0, 0, 0, 0, 1, 0, 0x2A01),
    L2(4, 0, 0, 0, 0, 1, 0, 0x2A01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 not started by a command, 93 not started by a command, 94 not started by a command, 95 not started by a command */
const u16 ibuki_saca_092_head[4] = { HEAD(4, 0, 3, 11, 0, 1, 0) };
const u16 ibuki_saca_092[164] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 236, 0, 0x2A5C, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 237, 0, 0x2A5D, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 238, 0, 0x2A5E, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 239, 0, 0x2A5F, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 887, 0, 0x2CB7, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 888, 0, 0x2CB8, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 889, 0, 0x2CB9, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 890, 0, 0x2CBA, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 891, 0, 0x2CBB, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 892, 0, 0x2CBC, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 893, 0, 0x2CBD, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 894, 0, 0x2CBE, -117, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 895, 0, 0x2CBF, 118, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 896, 0, 0x2CC0, 119, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 897, 0, 0x2CC1, 0, 10, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 898, 0, 0x2CC2, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 899, 0, 0x2A66, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 900, 0, 0x2A67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 not started by a command */
const u16 ibuki_saca_096_head[4] = { HEAD(6, 0, 9, 0, 0, 0, 0) };
const u16 ibuki_saca_096[76] = {
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_097_head[4] = { HEAD(6, 0, 11, 0, 0, 0, 0) };
const u16 ibuki_saca_097[76] = {
    L6(2, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 not started by a command */
const u16 ibuki_saca_098_head[4] = { HEAD(6, 0, 13, 0, 0, 0, 0) };
const u16 ibuki_saca_098[76] = {
    L6(3, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 99 not started by a command, 100 not started by a command, 101 not started by a command */
const u16 ibuki_saca_099_head[4] = { HEAD(4, 20, 0, 7, 0, 1, 0) };
const u16 ibuki_saca_099[204] = {
    CMD(CM_JSR, 8, 34, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 108, 0, 0x2A46, 0, 18, 0, 0, 0, 21, 0),
    L4(3, 20, 281, 0, 0, 201, 0, 0x2A6D, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 368, 0, 0, 202, 0, 0x2A6E, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 203, 0, 0x2A6F, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 40, 0, 0, 0, 204, 0, 0x2A70, 0, 8, 0, 0, 0, 33, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2DEB, -157, 248, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2DEC, 0, 248, 0, 138, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 239, 0, 0x2A5F, 0, 8, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 240, 0, 0x2A60, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_S123, 0, 50, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 46, 6), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 234, 0, 0x2A5A, 0, 8, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 235, 0, 0x2A5B, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 236, 0, 0x2A5C, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 237, 0, 0x2A5D, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 238, 0, 0x2A5E, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 239, 0, 0x2A5F, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 240, 0, 0x2A60, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 241, 0, 0x2A61, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 242, 0, 0x2A62, 0, 252, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 243, 0, 0x2A63, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 EX 214+KK (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_102_head[4] = { HEAD(6, 0, 15, 15, 0, 4, 0) };
const u16 ibuki_saca_102[304] = {
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1332, 0, 0x2A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 258, 0, 0),
    L6(1, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -154, 254, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 260, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1341, 0, 0x2BEF, 0, 260, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 103, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 5, 104, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA3, 5, 102, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8195, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 103, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 5, 104, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA3, 5, 102, 23), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8195, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 105, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 5, 106, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_L, 2, 8195, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 103 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_103_head[4] = { HEAD(6, 0, 15, 15, 0, 4, 0) };
const u16 ibuki_saca_103[136] = {
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -155, 254, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 260, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1341, 0, 0x2BEF, 0, 260, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA3, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_104_head[4] = { HEAD(6, 32, 15, 15, 0, 4, 0) };
const u16 ibuki_saca_104[184] = {
    L6(1, 0, 0, 0, 0, 1353, 0, 0x2A53, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1354, 0, 0x2A54, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1355, 0, 0x2A55, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1356, 0, 0x2C6B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(1, 0, 270, 0, 0, 1357, 0, 0x2C6C, 0, 2, 0, 0, 0, 30, 13, 0, 0, 282, 0, 0),
    L6(2, 0, 0, 0, 0, 1358, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 1359, 0, 0x2C6E, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1360, 0, 0x2C6F, -160, 169, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1361, 0, 0x2C70, 0, 42, 0, 0, 64, 21, 0, 0, 0, 186, 0, 0),
    L6(1, 0, 0, 0, 0, 1362, 0, 0x2C71, 0, 42, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1363, 0, 0x2C72, 0, 42, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1364, 0, 0x2C73, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1365, 0, 0x2C74, 0, 42, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(1, 0, 0, 0, 0, 1366, 0, 0x2C75, 0, 42, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    CMD(CM_UJA3, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 105 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_105_head[4] = { HEAD(6, 0, 15, 15, 0, 4, 0) };
const u16 ibuki_saca_105[232] = {
    L6(1, 0, 0, 0, 0, 1375, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -156, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 260, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1341, 0, 0x2BEF, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_106_head[4] = { HEAD(6, 0, 15, 15, 0, 4, 0) };
const u16 ibuki_saca_106[292] = {
    L6(1, 0, 0, 0, 0, 1352, 0, 0x2A52, 0, 2, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1353, 0, 0x2A53, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1354, 0, 0x2A54, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1355, 0, 0x2A55, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1356, 0, 0x2C6B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(1, 0, 270, 0, 0, 1357, 0, 0x2C6C, 0, 2, 0, 0, 0, 30, 13, 0, 0, 282, 0, 0),
    L6(1, 0, 0, 0, 0, 1358, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 1359, 0, 0x2C6E, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1360, 0, 0x2C6F, -161, 169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1361, 0, 0x2C70, 0, 42, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 1362, 0, 0x2C71, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1363, 0, 0x2C72, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1364, 0, 0x2C73, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1365, 0, 0x2C74, 0, 42, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 1366, 0, 0x2C75, 0, 42, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 1367, 0, 0x2C76, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1368, 0, 0x2C77, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1369, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1370, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1371, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1372, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1373, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 107 623+P light (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_107_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_107[228] = {
    CMD(CM_JSR, 8, 60, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2ED1, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2ED2, 0, 2, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2ED3, 0, 2, 0, 0, 0, 1, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 277, 0, 1, 0, 0, 0x2E6E, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E71, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 358, 0, 1, 0, 0, 0x2E72, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E73, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E74, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E75, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E76, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E77, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E78, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E79, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7A, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7B, 0, 319, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7C, 0, 320, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7D, 0, 321, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7E, 0, 322, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7F, 0, 323, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E80, 0, 324, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E6F, 0, 10, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2E70, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 10, 0, 0, 96, 0, 0),
    L4(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 10, 0, 0, 96, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 623+P medium (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_108_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_108[228] = {
    CMD(CM_JSR, 8, 60, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2ED1, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2ED2, 0, 2, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2ED3, 0, 2, 0, 0, 0, 1, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 277, 0, 1, 0, 0, 0x2E6E, 0, 10, 0, 0, 0, 21, 0),
    L4(2, 0, 358, 0, 1, 0, 0, 0x2E71, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E72, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E73, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E74, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E75, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E76, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E77, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E78, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E79, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7A, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7B, 0, 319, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7C, 0, 320, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7D, 0, 321, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7E, 0, 322, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7F, 0, 323, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E80, 0, 324, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E6F, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E70, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 10, 0, 0, 96, 0, 0),
    L4(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 10, 0, 0, 96, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 109 623+P heavy/EX (routine Att_SLIDE_and_JUMP), 110 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_109_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_109[228] = {
    CMD(CM_JSR, 8, 60, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2ED1, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2ED2, 0, 2, 0, 0, 0, 31, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2ED3, 0, 2, 0, 0, 0, 1, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 277, 0, 1, 0, 0, 0x2E6E, 0, 10, 0, 0, 0, 21, 0),
    L4(2, 0, 358, 0, 1, 0, 0, 0x2E71, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E72, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E73, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E74, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E75, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E76, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E77, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E78, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E79, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7A, 0, 318, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7B, 0, 319, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7C, 0, 320, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x2E7D, 0, 321, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7E, 0, 322, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E7F, 0, 323, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x2E80, 0, 324, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E6F, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2E70, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 223, 0, 0x2A65, 0, 10, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 224, 0, 0x2A66, 0, 10, 0, 0, 96, 0, 0),
    L4(250, 0, 0, 0, 0, 224, 0, 0x2A67, 0, 10, 0, 0, 96, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 111 236+K light (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_111_head[4] = { HEAD(6, 7, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_111[268] = {
    L6(2, 30, 0, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 1, 0, 0, 0, 286, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 3, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 169, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 170, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 171, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 172, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F12, 0, 326, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F13, 0, 327, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F14, 0, 328, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F15, 0, 329, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F16, 0, 330, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F17, 0, 331, 0, 0, 0, 0, 0, 0, 0, 298, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 236+K medium (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_112_head[4] = { HEAD(6, 7, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_112[268] = {
    L6(2, 30, 0, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 1, 0, 0, 0, 286, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 3, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 169, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 170, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 171, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 172, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F12, 0, 326, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F13, 0, 327, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F14, 0, 328, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F15, 0, 329, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F16, 0, 330, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F17, 0, 331, 0, 0, 0, 0, 0, 0, 0, 298, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 113 236+K heavy/EX (routine Att_SLIDE_and_JUMP), 114 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
const u16 ibuki_saca_113_head[4] = { HEAD(6, 7, 0, 0, 0, 0, 0) };
const u16 ibuki_saca_113[268] = {
    L6(2, 30, 0, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 1, 0, 0, 0, 286, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x2F21, 0, 325, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 3, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 169, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 170, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 171, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 172, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2F12, 0, 326, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2F13, 0, 327, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F14, 0, 328, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F15, 0, 329, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F16, 0, 330, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F17, 0, 331, 0, 0, 0, 0, 0, 0, 0, 298, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2F18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2F1E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 115 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_115_head[4] = { HEAD(6, 0, 13, 15, 0, 1, 0) };
const u16 ibuki_saca_115[364] = {
    L6(1, 0, 0, 0, 0, 1333, 0, 0x2BE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 0, 0, 0, 1334, 0, 0x2BE8, 0, 65, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(1, 0, 358, 0, 0, 1335, 0, 0x2BE9, 0, 65, 0, 0, 0, 30, 13, 0, 0, 398, 0, 0),
    L6(1, 0, 0, 0, 0, 1336, 0, 0x2BEA, 0, 65, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 268, 0, 0, 1337, 0, 0x2BEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1338, 0, 0x2BEC, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1339, 0, 0x2BED, -146, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16394, 16386, 16394), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 260, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1341, 0, 0x2BEF, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1340, 0, 0x2BEE, 0, 260, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1341, 0, 0x2BEF, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1342, 0, 0x2BF1, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1343, 0, 0x2BF2, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1348, 0, 0x2BF7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1349, 0, 0x2B9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1350, 0, 0x2B9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1351, 0, 0x2B9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 after 214+K (routine Att_CHOUCHUURENGEKI) */
const u16 ibuki_saca_116_head[4] = { HEAD(6, 0, 13, 15, 0, 1, 0) };
const u16 ibuki_saca_116[292] = {
    L6(1, 0, 0, 0, 0, 1352, 0, 0x2A52, 0, 2, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(1, 0, 358, 0, 0, 1353, 0, 0x2A53, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1354, 0, 0x2A54, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1355, 0, 0x2A55, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1356, 0, 0x2C6B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(1, 0, 270, 0, 0, 1357, 0, 0x2C6C, 0, 2, 0, 0, 0, 30, 13, 0, 0, 404, 0, 0),
    L6(1, 0, 0, 0, 0, 1358, 0, 0x2C6D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0),
    L6(2, 0, 0, 0, 0, 1359, 0, 0x2C6E, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1360, 0, 0x2C6F, -182, 169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1361, 0, 0x2C70, 0, 42, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 1362, 0, 0x2C71, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1363, 0, 0x2C72, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1364, 0, 0x2C73, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1365, 0, 0x2C74, 0, 42, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(2, 0, 0, 0, 0, 1366, 0, 0x2C75, 0, 42, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(2, 0, 0, 0, 0, 1367, 0, 0x2C76, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 1368, 0, 0x2C77, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1369, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1370, 0, 0x2C78, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1371, 0, 0x2A41, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 1372, 0, 0x2A42, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1373, 0, 0x2A43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 1374, 0, 0x2A44, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 66 entries */
const u16* const ibuki_cbca[67] = {
    ibuki_cbca_000,  /* 0 APPEAR JUNBI 1 */
    ibuki_cbca_001,  /* 1 APPEAR JUNBI 2 */
    ibuki_cbca_002,  /* 2 APPEAR JUNBI 3 */
    ibuki_cbca_003,  /* 3 APPEAR JUNBI 4 */
    ibuki_cbca_004,  /* 4 APPEAR JUNBI 5 */
    ibuki_cbca_005,  /* 5 APPEAR JUNBI 6 */
    ibuki_cbca_006,  /* 6 APPEAR JUNBI 7 */
    ibuki_cbca_007,  /* 7 APPEAR JUNBI 8 */
    ibuki_cbca_008,  /* 8 APPEAR 1 */
    ibuki_cbca_009,  /* 9 APPEAR 2 */
    ibuki_cbca_010,  /* 10 APPEAR 3 */
    ibuki_cbca_011,  /* 11 APPEAR 4 */
    ibuki_cbca_012,  /* 12 APPEAR 5 */
    ibuki_cbca_013,  /* 13 APPEAR 6 */
    ibuki_cbca_014,  /* 14 APPEAR 7 */
    ibuki_cbca_015,  /* 15 APPEAR 8 */
    ibuki_cbca_016,  /* 16 SP APPEAR 1 */
    ibuki_cbca_017,  /* 17 SP APPEAR 2 */
    ibuki_cbca_018,  /* 18 SP APPEAR 3 */
    ibuki_cbca_019,  /* 19 SP APPEAR 4 */
    ibuki_cbca_020,  /* 20 SP APPEAR 5 */
    ibuki_cbca_021,  /* 21 SP APPEAR 6 */
    ibuki_cbca_022,  /* 22 SP APPEAR 7 */
    ibuki_cbca_023,  /* 23 SP APPEAR 8 */
    ibuki_cbca_024,  /* 24 ZANNEN 1 */
    ibuki_cbca_025,  /* 25 ZANNEN 2 */
    ibuki_cbca_026,  /* 26 ZANNEN 3 */
    ibuki_cbca_027,  /* 27 ZANNEN 4 */
    ibuki_cbca_028,  /* 28 ZANNEN 5 */
    ibuki_cbca_029,  /* 29 ZANNEN 6 */
    ibuki_cbca_030,  /* 30 ZANNEN 7 */
    ibuki_cbca_031,  /* 31 ZANNEN 8 */
    ibuki_cbca_032,  /* 32 WIN 1 */
    ibuki_cbca_033,  /* 33 WIN 2 */
    ibuki_cbca_034,  /* 34 WIN 3 */
    ibuki_cbca_035,  /* 35 WIN 4 */
    ibuki_cbca_036,  /* 36 WIN 5 */
    ibuki_cbca_037,  /* 37 WIN 6 */
    ibuki_cbca_038,  /* 38 WIN 7 */
    ibuki_cbca_039,  /* 39 WIN 8 */
    ibuki_cbca_040,  /* 40 SP WIN 1 */
    ibuki_cbca_041,  /* 41 SP WIN 2 */
    ibuki_cbca_042,  /* 42 SP WIN 3 */
    ibuki_cbca_043,  /* 43 SP WIN 4 */
    ibuki_cbca_044,  /* 44 SP WIN 5 */
    ibuki_cbca_045,  /* 45 SP WIN 6 */
    ibuki_cbca_045,  /* 46 SP WIN 7 */
    ibuki_cbca_045,  /* 47 SP WIN 8 */
    ibuki_cbca_048,  /* 48 JUDGMENT WAIT */
    ibuki_cbca_049,  /* 49 JUDGMENT WAIT */
    ibuki_cbca_050,  /* 50 JUDGMENT WAIT */
    ibuki_cbca_051,  /* 51 JUDGMENT WAIT */
    ibuki_cbca_052,  /* 52 JUDGMENT WIN */
    ibuki_cbca_053,  /* 53 JUDGMENT WIN */
    ibuki_cbca_054,  /* 54 JUDGMENT WIN */
    ibuki_cbca_055,  /* 55 JUDGMENT WIN */
    ibuki_cbca_056,  /* 56 JUDGMENT LOSE */
    ibuki_cbca_057,  /* 57 JUDGMENT LOSE */
    ibuki_cbca_058,  /* 58 JUDGMENT LOSE */
    ibuki_cbca_059,  /* 59 JUDGMENT LOSE */
    ibuki_cbca_060,  /* 60 WAIT */
    ibuki_cbca_060,  /* 61 AFRICA JUMP */
    ibuki_cbca_060,  /* 62 AFRICA LAND */
    ibuki_cbca_060,  /* 63 SEAN BALL HIT */
    ibuki_cbca_064,  /* 64 follow-up of ATTACK 10 M */
    ibuki_cbca_065,  /* 65 BONUS WIN 1 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 ibuki_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 ibuki_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 5, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 ibuki_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 6, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 ibuki_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 7, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 ibuki_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 4, 16, 22),
    CMD(CM_RJA3, 7, 7, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 ibuki_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 4, 17, 20),
    CMD(CM_RJA3, 7, 7, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 ibuki_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_006[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 ibuki_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_007[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 19, 1),
    CMD(CM_RJA3, 7, 22, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 ibuki_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_008[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 20, 1),
    CMD(CM_RJA3, 7, 72, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 ibuki_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_009[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 21, 1),
    CMD(CM_RJA3, 7, 73, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 ibuki_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_010[8] = {
    CMD(CM_RJA, 5, 40, 19),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 ibuki_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_011[8] = {
    CMD(CM_RJA, 5, 41, 36),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 ibuki_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_012[8] = {
    CMD(CM_RJA, 5, 42, 36),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 ibuki_cbca_013_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_013[16] = {
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 2304, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 ibuki_cbca_014_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_014[16] = {
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 2304, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 ibuki_cbca_015_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_015[16] = {
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 2304, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 ibuki_cbca_016_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_016[52] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 2304, 0, 8, 0, 0, 0, 0, 0, 4, 0),
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 ibuki_cbca_017_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_017[16] = {
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 2560, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 ibuki_cbca_018_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_018[16] = {
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 2560, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 ibuki_cbca_019_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_019[52] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 2560, 0, 8, 0, 0, 0, 0, 0, 4, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 ibuki_cbca_020_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_020[52] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 2560, 0, 8, 0, 0, 0, 0, 0, 4, 0),
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 ibuki_cbca_021_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_021[16] = {
    L6(1, 0, 0, 0, 0, 1344, 0, 0x2BF3, 0, 68, 3072, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 ibuki_cbca_022_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_022[16] = {
    L6(1, 0, 0, 0, 0, 1345, 0, 0x2BF4, 0, 68, 3072, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 ibuki_cbca_023_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_023[52] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 3072, 0, 8, 0, 0, 0, 0, 0, 4, 0),
    L6(1, 0, 0, 0, 0, 1346, 0, 0x2BF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 ibuki_cbca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_024[52] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 3072, 0, 8, 0, 0, 0, 0, 0, 4, 0),
    L6(1, 0, 0, 0, 0, 1347, 0, 0x2BF6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 ibuki_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_025[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 ibuki_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_026[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 11),
    CMD(CM_CARE, 2, 2, 11),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 ibuki_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_027[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 5, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 ibuki_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_028[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 5, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 ibuki_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_029[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 6, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 ibuki_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_030[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 6, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 ibuki_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_031[28] = {
    CMD(CM_CAFR, 2, 5, 15),
    CMD(CM_CARE, 2, 5, 15),
    CMD(CM_MPCY, 64, 2, 8202),
    CMD(CM_EPCY, 0, 0, 8202),
    CMD(CM_IF_L, 0, 8202, 8192),
    CMD(CM_IF_L, 2, 8202, 8192),
    CMD(CM_JMP, 4, 40, 5),
};

/* script: 32 WIN 1 */
const u16 ibuki_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_032[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 ibuki_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_033[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 ibuki_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_034[24] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 7, 1),
    CMD(CM_CAFR, 2, 5, 19),
    CMD(CM_CARE, 2, 5, 19),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 ibuki_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_035[28] = {
    CMD(CM_CAFR, 2, 1, 10),
    CMD(CM_CARE, 2, 1, 10),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_RJA7, 5, 56, 30),
    CMD(CM_STOP, -50, 51, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 ibuki_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_036[32] = {
    CMD(CM_MXYT, 103, 0, 0),
    CMD(CM_RJA4, 5, 60, 9),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_WSET, 16385, 0, 2),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 ibuki_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_037[32] = {
    CMD(CM_MXYT, 103, 0, 0),
    CMD(CM_RJA4, 5, 61, 9),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_WSET, 16385, 0, 2),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 ibuki_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_038[32] = {
    CMD(CM_MXYT, 103, 0, 0),
    CMD(CM_RJA4, 5, 62, 9),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_WSET, 16385, 0, 2),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 ibuki_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_039[28] = {
    CMD(CM_CAFR, 2, 5, 15),
    CMD(CM_CARE, 2, 5, 15),
    CMD(CM_MPCY, 64, 2, 8202),
    CMD(CM_EPCY, 0, 0, 8202),
    CMD(CM_IF_L, 0, 8202, 8192),
    CMD(CM_IF_L, 2, 8202, 8192),
    CMD(CM_JMP, 4, 38, 4),
};

/* script: 40 SP WIN 1 */
const u16 ibuki_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_040[28] = {
    CMD(CM_CAFR, 2, 5, 15),
    CMD(CM_CARE, 2, 5, 15),
    CMD(CM_MPCY, 64, 2, 8202),
    CMD(CM_EPCY, 0, 0, 8202),
    CMD(CM_IF_L, 0, 8202, 8192),
    CMD(CM_IF_L, 2, 8202, 8192),
    CMD(CM_JMP, 4, 50, 4),
};

/* script: 41 SP WIN 2 */
const u16 ibuki_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_041[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 ibuki_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_042[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 36, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 ibuki_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_043[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 ibuki_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6, 46 SP WIN 7, 47 SP WIN 8 */
const u16 ibuki_cbca_045_head[4] = { HEAD(2, 0, 32, 0, 0, 0, 0) };
const u16 ibuki_cbca_045[20] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 30, 0),
    CMD(CM_RJA7, 5, 55, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 ibuki_cbca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_048[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 ibuki_cbca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_049[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 56, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 ibuki_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_050[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 57, 1),
    CMD(CM_RJA3, 7, 58, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 ibuki_cbca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_051[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 59, 1),
    CMD(CM_RJA3, 7, 60, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN */
const u16 ibuki_cbca_052_head[4] = { HEAD(2, 22, 14, 0, 0, 0, 0) };
const u16 ibuki_cbca_052[32] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 61, 1),
    CMD(CM_RJA3, 7, 62, 1),
    CMD(CM_RJA4, 5, 51, 7),
    CMD(CM_EXEC, 49, 23, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 53 JUDGMENT WIN */
const u16 ibuki_cbca_053_head[4] = { HEAD(2, 20, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_053[28] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 63, 1),
    CMD(CM_RJA3, 7, 64, 1),
    CMD(CM_EXEC, 49, 20, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 54 JUDGMENT WIN */
const u16 ibuki_cbca_054_head[4] = { HEAD(2, 20, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_054[28] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 65, 1),
    CMD(CM_RJA3, 7, 66, 1),
    CMD(CM_EXEC, 49, 21, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 55 JUDGMENT WIN */
const u16 ibuki_cbca_055_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_055[16] = {
    CMD(CM_EXEC, 49, 22, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 56 JUDGMENT LOSE */
const u16 ibuki_cbca_056_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_056[24] = {
    CMD(CM_EXEC, 49, 24, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_CAFR, 2, 1, 21),
    CMD(CM_CARE, 2, 1, 21),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 57 JUDGMENT LOSE */
const u16 ibuki_cbca_057_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_057[12] = {
    CMD(CM_CAFR, 2, 1, 22),
    CMD(CM_CARE, 2, 1, 22),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 58 JUDGMENT LOSE */
const u16 ibuki_cbca_058_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 ibuki_cbca_058[12] = {
    CMD(CM_CAFR, 2, 1, 23),
    CMD(CM_CARE, 2, 1, 23),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 59 JUDGMENT LOSE */
const u16 ibuki_cbca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_059[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 68, 1),
    CMD(CM_RJA3, 7, 69, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 60 WAIT, 61 AFRICA JUMP, 62 AFRICA LAND, 63 SEAN BALL HIT */
const u16 ibuki_cbca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_060[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 70, 1),
    CMD(CM_RJA3, 7, 71, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 64 follow-up of ATTACK 10 M */
const u16 ibuki_cbca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_064[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 65 BONUS WIN 1 */
const u16 ibuki_cbca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ibuki_cbca_065[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

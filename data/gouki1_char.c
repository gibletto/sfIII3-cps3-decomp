/*
 * GOUKI1_CHAR.C  Gouki's animation scripts and sprite part tables
 *
 * The animation scripts Gouki's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 gouki1_nmca_000[], gouki1_nmca_001[], gouki1_nmca_002[], gouki1_nmca_003[], gouki1_nmca_004[], gouki1_nmca_005[], gouki1_nmca_006[], gouki1_nmca_007[], gouki1_nmca_008[], gouki1_nmca_011[], gouki1_nmca_012[], gouki1_nmca_013[], gouki1_nmca_014[], gouki1_nmca_015[], gouki1_nmca_016[], gouki1_nmca_017[], gouki1_nmca_020[], gouki1_nmca_021[], gouki1_nmca_022[], gouki1_nmca_023[], gouki1_nmca_024[], gouki1_nmca_026[], gouki1_nmca_027[], gouki1_nmca_029[], gouki1_nmca_030[], gouki1_nmca_031[], gouki1_nmca_032[], gouki1_nmca_033[], gouki1_nmca_038[], gouki1_nmca_040[], gouki1_nmca_041[], gouki1_nmca_043[], gouki1_nmca_044[], gouki1_nmca_045[], gouki1_nmca_046[], gouki1_nmca_047[], gouki1_nmca_048[], gouki1_nmca_049[], gouki1_nmca_050[];
extern const u16 gouki1_nmca_000_head[];
extern const u16 gouki1_nmca_001_head[];
extern const u16 gouki1_nmca_002_head[];
extern const u16 gouki1_nmca_003_head[];
extern const u16 gouki1_nmca_004_head[];
extern const u16 gouki1_nmca_005_head[];
extern const u16 gouki1_nmca_006_head[];
extern const u16 gouki1_nmca_007_head[];
extern const u16 gouki1_nmca_008_head[];
extern const u16 gouki1_nmca_011_head[];
extern const u16 gouki1_nmca_012_head[];
extern const u16 gouki1_nmca_013_head[];
extern const u16 gouki1_nmca_014_head[];
extern const u16 gouki1_nmca_015_head[];
extern const u16 gouki1_nmca_016_head[];
extern const u16 gouki1_nmca_017_head[];
extern const u16 gouki1_nmca_020_head[];
extern const u16 gouki1_nmca_021_head[];
extern const u16 gouki1_nmca_022_head[];
extern const u16 gouki1_nmca_023_head[];
extern const u16 gouki1_nmca_024_head[];
extern const u16 gouki1_nmca_026_head[];
extern const u16 gouki1_nmca_027_head[];
extern const u16 gouki1_nmca_029_head[];
extern const u16 gouki1_nmca_030_head[];
extern const u16 gouki1_nmca_031_head[];
extern const u16 gouki1_nmca_032_head[];
extern const u16 gouki1_nmca_033_head[];
extern const u16 gouki1_nmca_038_head[];
extern const u16 gouki1_nmca_040_head[];
extern const u16 gouki1_nmca_041_head[];
extern const u16 gouki1_nmca_043_head[];
extern const u16 gouki1_nmca_044_head[];
extern const u16 gouki1_nmca_045_head[];
extern const u16 gouki1_nmca_046_head[];
extern const u16 gouki1_nmca_047_head[];
extern const u16 gouki1_nmca_048_head[];
extern const u16 gouki1_nmca_049_head[];
extern const u16 gouki1_nmca_050_head[];
extern const u16 gouki1_dmca_000[], gouki1_dmca_001[], gouki1_dmca_002[], gouki1_dmca_003[], gouki1_dmca_004[], gouki1_dmca_006[], gouki1_dmca_008[], gouki1_dmca_009[], gouki1_dmca_010[], gouki1_dmca_014[], gouki1_dmca_015[], gouki1_dmca_018[], gouki1_dmca_019[], gouki1_dmca_022[], gouki1_dmca_025[], gouki1_dmca_026[], gouki1_dmca_024[], gouki1_dmca_029[], gouki1_dmca_030[], gouki1_dmca_034[], gouki1_dmca_036[], gouki1_dmca_048[], gouki1_dmca_049[], gouki1_dmca_050[], gouki1_dmca_052[], gouki1_dmca_060[], gouki1_dmca_064[], gouki1_dmca_065[], gouki1_dmca_066[], gouki1_dmca_067[], gouki1_dmca_068[], gouki1_dmca_070[], gouki1_dmca_071[], gouki1_dmca_072[], gouki1_dmca_073[], gouki1_dmca_074[], gouki1_dmca_075[], gouki1_dmca_076[], gouki1_dmca_078[], gouki1_dmca_079[], gouki1_dmca_080[], gouki1_dmca_082[], gouki1_dmca_083[], gouki1_dmca_084[], gouki1_dmca_090[], gouki1_dmca_091[], gouki1_dmca_096[], gouki1_dmca_097[];
extern const u16 gouki1_dmca_000_head[];
extern const u16 gouki1_dmca_001_head[];
extern const u16 gouki1_dmca_002_head[];
extern const u16 gouki1_dmca_003_head[];
extern const u16 gouki1_dmca_004_head[];
extern const u16 gouki1_dmca_006_head[];
extern const u16 gouki1_dmca_008_head[];
extern const u16 gouki1_dmca_009_head[];
extern const u16 gouki1_dmca_010_head[];
extern const u16 gouki1_dmca_014_head[];
extern const u16 gouki1_dmca_015_head[];
extern const u16 gouki1_dmca_018_head[];
extern const u16 gouki1_dmca_019_head[];
extern const u16 gouki1_dmca_022_head[];
extern const u16 gouki1_dmca_025_head[];
extern const u16 gouki1_dmca_026_head[];
extern const u16 gouki1_dmca_024_head[];
extern const u16 gouki1_dmca_029_head[];
extern const u16 gouki1_dmca_030_head[];
extern const u16 gouki1_dmca_034_head[];
extern const u16 gouki1_dmca_036_head[];
extern const u16 gouki1_dmca_048_head[];
extern const u16 gouki1_dmca_049_head[];
extern const u16 gouki1_dmca_050_head[];
extern const u16 gouki1_dmca_052_head[];
extern const u16 gouki1_dmca_060_head[];
extern const u16 gouki1_dmca_064_head[];
extern const u16 gouki1_dmca_065_head[];
extern const u16 gouki1_dmca_066_head[];
extern const u16 gouki1_dmca_067_head[];
extern const u16 gouki1_dmca_068_head[];
extern const u16 gouki1_dmca_070_head[];
extern const u16 gouki1_dmca_071_head[];
extern const u16 gouki1_dmca_072_head[];
extern const u16 gouki1_dmca_073_head[];
extern const u16 gouki1_dmca_074_head[];
extern const u16 gouki1_dmca_075_head[];
extern const u16 gouki1_dmca_076_head[];
extern const u16 gouki1_dmca_078_head[];
extern const u16 gouki1_dmca_079_head[];
extern const u16 gouki1_dmca_080_head[];
extern const u16 gouki1_dmca_082_head[];
extern const u16 gouki1_dmca_083_head[];
extern const u16 gouki1_dmca_084_head[];
extern const u16 gouki1_dmca_090_head[];
extern const u16 gouki1_dmca_091_head[];
extern const u16 gouki1_dmca_096_head[];
extern const u16 gouki1_dmca_097_head[];
extern const u16 gouki1_btca_000[], gouki1_btca_001[], gouki1_btca_002[], gouki1_btca_003[], gouki1_btca_004[], gouki1_btca_005[], gouki1_btca_006[], gouki1_btca_007[], gouki1_btca_008[], gouki1_btca_009[], gouki1_btca_010[], gouki1_btca_011[], gouki1_btca_012[], gouki1_btca_013[], gouki1_btca_014[], gouki1_btca_015[], gouki1_btca_016[], gouki1_btca_017[], gouki1_btca_018[], gouki1_btca_019[], gouki1_btca_020[], gouki1_btca_021[], gouki1_btca_022[], gouki1_btca_023[], gouki1_btca_024[], gouki1_btca_025[], gouki1_btca_026[], gouki1_btca_027[], gouki1_btca_028[], gouki1_btca_029[], gouki1_btca_030[], gouki1_btca_031[], gouki1_btca_032[], gouki1_btca_033[], gouki1_btca_034[], gouki1_btca_035[];
extern const u16 gouki1_btca_000_head[];
extern const u16 gouki1_btca_001_head[];
extern const u16 gouki1_btca_002_head[];
extern const u16 gouki1_btca_003_head[];
extern const u16 gouki1_btca_004_head[];
extern const u16 gouki1_btca_005_head[];
extern const u16 gouki1_btca_006_head[];
extern const u16 gouki1_btca_007_head[];
extern const u16 gouki1_btca_008_head[];
extern const u16 gouki1_btca_009_head[];
extern const u16 gouki1_btca_010_head[];
extern const u16 gouki1_btca_011_head[];
extern const u16 gouki1_btca_012_head[];
extern const u16 gouki1_btca_013_head[];
extern const u16 gouki1_btca_014_head[];
extern const u16 gouki1_btca_015_head[];
extern const u16 gouki1_btca_016_head[];
extern const u16 gouki1_btca_017_head[];
extern const u16 gouki1_btca_018_head[];
extern const u16 gouki1_btca_019_head[];
extern const u16 gouki1_btca_020_head[];
extern const u16 gouki1_btca_021_head[];
extern const u16 gouki1_btca_022_head[];
extern const u16 gouki1_btca_023_head[];
extern const u16 gouki1_btca_024_head[];
extern const u16 gouki1_btca_025_head[];
extern const u16 gouki1_btca_026_head[];
extern const u16 gouki1_btca_027_head[];
extern const u16 gouki1_btca_028_head[];
extern const u16 gouki1_btca_029_head[];
extern const u16 gouki1_btca_030_head[];
extern const u16 gouki1_btca_031_head[];
extern const u16 gouki1_btca_032_head[];
extern const u16 gouki1_btca_033_head[];
extern const u16 gouki1_btca_034_head[];
extern const u16 gouki1_btca_035_head[];
extern const u16 gouki1_caca_000[], gouki1_caca_002[], gouki1_caca_004[], gouki1_caca_008[], gouki1_caca_010[], gouki1_caca_012[], gouki1_caca_014[], gouki1_caca_018[], gouki1_caca_019[];
extern const u16 gouki1_caca_000_head[];
extern const u16 gouki1_caca_002_head[];
extern const u16 gouki1_caca_004_head[];
extern const u16 gouki1_caca_008_head[];
extern const u16 gouki1_caca_010_head[];
extern const u16 gouki1_caca_012_head[];
extern const u16 gouki1_caca_014_head[];
extern const u16 gouki1_caca_018_head[];
extern const u16 gouki1_caca_019_head[];
extern const u16 gouki1_cuca_000[], gouki1_cuca_001[], gouki1_cuca_002[], gouki1_cuca_003[], gouki1_cuca_004[], gouki1_cuca_005[], gouki1_cuca_006[], gouki1_cuca_007[], gouki1_cuca_008[], gouki1_cuca_009[], gouki1_cuca_010[], gouki1_cuca_011[], gouki1_cuca_012[], gouki1_cuca_013[], gouki1_cuca_014[], gouki1_cuca_015[], gouki1_cuca_016[], gouki1_cuca_017[], gouki1_cuca_018[], gouki1_cuca_019[], gouki1_cuca_020[], gouki1_cuca_021[], gouki1_cuca_022[], gouki1_cuca_023[], gouki1_cuca_024[], gouki1_cuca_025[], gouki1_cuca_026[], gouki1_cuca_027[], gouki1_cuca_028[], gouki1_cuca_029[], gouki1_cuca_030[], gouki1_cuca_031[], gouki1_cuca_032[], gouki1_cuca_033[], gouki1_cuca_034[], gouki1_cuca_035[], gouki1_cuca_036[], gouki1_cuca_037[], gouki1_cuca_038[], gouki1_cuca_039[], gouki1_cuca_040[], gouki1_cuca_041[], gouki1_cuca_042[], gouki1_cuca_043[], gouki1_cuca_044[], gouki1_cuca_045[], gouki1_cuca_046[], gouki1_cuca_047[], gouki1_cuca_048[], gouki1_cuca_049[], gouki1_cuca_050[], gouki1_cuca_051[], gouki1_cuca_052[], gouki1_cuca_053[], gouki1_cuca_054[], gouki1_cuca_055[], gouki1_cuca_056[], gouki1_cuca_057[], gouki1_cuca_058[], gouki1_cuca_059[], gouki1_cuca_060[], gouki1_cuca_061[], gouki1_cuca_062[], gouki1_cuca_063[], gouki1_cuca_064[], gouki1_cuca_065[], gouki1_cuca_066[], gouki1_cuca_067[];
extern const u16 gouki1_cuca_000_head[];
extern const u16 gouki1_cuca_001_head[];
extern const u16 gouki1_cuca_002_head[];
extern const u16 gouki1_cuca_003_head[];
extern const u16 gouki1_cuca_004_head[];
extern const u16 gouki1_cuca_005_head[];
extern const u16 gouki1_cuca_006_head[];
extern const u16 gouki1_cuca_007_head[];
extern const u16 gouki1_cuca_008_head[];
extern const u16 gouki1_cuca_009_head[];
extern const u16 gouki1_cuca_010_head[];
extern const u16 gouki1_cuca_011_head[];
extern const u16 gouki1_cuca_012_head[];
extern const u16 gouki1_cuca_013_head[];
extern const u16 gouki1_cuca_014_head[];
extern const u16 gouki1_cuca_015_head[];
extern const u16 gouki1_cuca_016_head[];
extern const u16 gouki1_cuca_017_head[];
extern const u16 gouki1_cuca_018_head[];
extern const u16 gouki1_cuca_019_head[];
extern const u16 gouki1_cuca_020_head[];
extern const u16 gouki1_cuca_021_head[];
extern const u16 gouki1_cuca_022_head[];
extern const u16 gouki1_cuca_023_head[];
extern const u16 gouki1_cuca_024_head[];
extern const u16 gouki1_cuca_025_head[];
extern const u16 gouki1_cuca_026_head[];
extern const u16 gouki1_cuca_027_head[];
extern const u16 gouki1_cuca_028_head[];
extern const u16 gouki1_cuca_029_head[];
extern const u16 gouki1_cuca_030_head[];
extern const u16 gouki1_cuca_031_head[];
extern const u16 gouki1_cuca_032_head[];
extern const u16 gouki1_cuca_033_head[];
extern const u16 gouki1_cuca_034_head[];
extern const u16 gouki1_cuca_035_head[];
extern const u16 gouki1_cuca_036_head[];
extern const u16 gouki1_cuca_037_head[];
extern const u16 gouki1_cuca_038_head[];
extern const u16 gouki1_cuca_039_head[];
extern const u16 gouki1_cuca_040_head[];
extern const u16 gouki1_cuca_041_head[];
extern const u16 gouki1_cuca_042_head[];
extern const u16 gouki1_cuca_043_head[];
extern const u16 gouki1_cuca_044_head[];
extern const u16 gouki1_cuca_045_head[];
extern const u16 gouki1_cuca_046_head[];
extern const u16 gouki1_cuca_047_head[];
extern const u16 gouki1_cuca_048_head[];
extern const u16 gouki1_cuca_049_head[];
extern const u16 gouki1_cuca_050_head[];
extern const u16 gouki1_cuca_051_head[];
extern const u16 gouki1_cuca_052_head[];
extern const u16 gouki1_cuca_053_head[];
extern const u16 gouki1_cuca_054_head[];
extern const u16 gouki1_cuca_055_head[];
extern const u16 gouki1_cuca_056_head[];
extern const u16 gouki1_cuca_057_head[];
extern const u16 gouki1_cuca_058_head[];
extern const u16 gouki1_cuca_059_head[];
extern const u16 gouki1_cuca_060_head[];
extern const u16 gouki1_cuca_061_head[];
extern const u16 gouki1_cuca_062_head[];
extern const u16 gouki1_cuca_063_head[];
extern const u16 gouki1_cuca_064_head[];
extern const u16 gouki1_cuca_065_head[];
extern const u16 gouki1_cuca_066_head[];
extern const u16 gouki1_cuca_067_head[];
extern const u16 gouki1_atca_000[], gouki1_atca_001[], gouki1_atca_003[], gouki1_atca_004[], gouki1_atca_005[], gouki1_atca_006[], gouki1_atca_007[], gouki1_atca_009[], gouki1_atca_012[], gouki1_atca_013[], gouki1_atca_015[], gouki1_atca_016[], gouki1_atca_018[], gouki1_atca_021[], gouki1_atca_024[], gouki1_atca_027[], gouki1_atca_030[], gouki1_atca_033[], gouki1_atca_036[], gouki1_atca_038[], gouki1_atca_040[], gouki1_atca_042[], gouki1_atca_044[], gouki1_atca_046[], gouki1_atca_048[], gouki1_atca_050[], gouki1_atca_052[], gouki1_atca_054[], gouki1_atca_056[], gouki1_atca_057[], gouki1_atca_058[], gouki1_atca_060[], gouki1_atca_062[], gouki1_atca_064[], gouki1_atca_066[], gouki1_atca_068[], gouki1_atca_070[], gouki1_atca_072[], gouki1_atca_074[], gouki1_atca_076[], gouki1_atca_078[], gouki1_atca_080[], gouki1_atca_082[], gouki1_atca_084[], gouki1_atca_086[], gouki1_atca_088[], gouki1_atca_090[], gouki1_atca_092[], gouki1_atca_093[], gouki1_atca_094[], gouki1_atca_096[], gouki1_atca_098[], gouki1_atca_100[], gouki1_atca_102[], gouki1_atca_104[], gouki1_atca_106[], gouki1_atca_108[], gouki1_atca_110[], gouki1_atca_112[], gouki1_atca_114[], gouki1_atca_116[], gouki1_atca_118[], gouki1_atca_144[], gouki1_atca_146[], gouki1_atca_156[];
extern const u16 gouki1_atca_000_head[];
extern const u16 gouki1_atca_001_head[];
extern const u16 gouki1_atca_003_head[];
extern const u16 gouki1_atca_004_head[];
extern const u16 gouki1_atca_005_head[];
extern const u16 gouki1_atca_006_head[];
extern const u16 gouki1_atca_007_head[];
extern const u16 gouki1_atca_009_head[];
extern const u16 gouki1_atca_012_head[];
extern const u16 gouki1_atca_013_head[];
extern const u16 gouki1_atca_015_head[];
extern const u16 gouki1_atca_016_head[];
extern const u16 gouki1_atca_018_head[];
extern const u16 gouki1_atca_021_head[];
extern const u16 gouki1_atca_024_head[];
extern const u16 gouki1_atca_027_head[];
extern const u16 gouki1_atca_030_head[];
extern const u16 gouki1_atca_033_head[];
extern const u16 gouki1_atca_036_head[];
extern const u16 gouki1_atca_038_head[];
extern const u16 gouki1_atca_040_head[];
extern const u16 gouki1_atca_042_head[];
extern const u16 gouki1_atca_044_head[];
extern const u16 gouki1_atca_046_head[];
extern const u16 gouki1_atca_048_head[];
extern const u16 gouki1_atca_050_head[];
extern const u16 gouki1_atca_052_head[];
extern const u16 gouki1_atca_054_head[];
extern const u16 gouki1_atca_056_head[];
extern const u16 gouki1_atca_057_head[];
extern const u16 gouki1_atca_058_head[];
extern const u16 gouki1_atca_060_head[];
extern const u16 gouki1_atca_062_head[];
extern const u16 gouki1_atca_064_head[];
extern const u16 gouki1_atca_066_head[];
extern const u16 gouki1_atca_068_head[];
extern const u16 gouki1_atca_070_head[];
extern const u16 gouki1_atca_072_head[];
extern const u16 gouki1_atca_074_head[];
extern const u16 gouki1_atca_076_head[];
extern const u16 gouki1_atca_078_head[];
extern const u16 gouki1_atca_080_head[];
extern const u16 gouki1_atca_082_head[];
extern const u16 gouki1_atca_084_head[];
extern const u16 gouki1_atca_086_head[];
extern const u16 gouki1_atca_088_head[];
extern const u16 gouki1_atca_090_head[];
extern const u16 gouki1_atca_092_head[];
extern const u16 gouki1_atca_093_head[];
extern const u16 gouki1_atca_094_head[];
extern const u16 gouki1_atca_096_head[];
extern const u16 gouki1_atca_098_head[];
extern const u16 gouki1_atca_100_head[];
extern const u16 gouki1_atca_102_head[];
extern const u16 gouki1_atca_104_head[];
extern const u16 gouki1_atca_106_head[];
extern const u16 gouki1_atca_108_head[];
extern const u16 gouki1_atca_110_head[];
extern const u16 gouki1_atca_112_head[];
extern const u16 gouki1_atca_114_head[];
extern const u16 gouki1_atca_116_head[];
extern const u16 gouki1_atca_118_head[];
extern const u16 gouki1_atca_144_head[];
extern const u16 gouki1_atca_146_head[];
extern const u16 gouki1_atca_156_head[];
extern const u16 gouki1_exca_000[], gouki1_exca_001[], gouki1_exca_003[], gouki1_exca_004[], gouki1_exca_005[], gouki1_exca_006[], gouki1_exca_007[], gouki1_exca_008[], gouki1_exca_009[], gouki1_exca_010[], gouki1_exca_011[], gouki1_exca_013[], gouki1_exca_014[], gouki1_exca_015[], gouki1_exca_016[], gouki1_exca_017[], gouki1_exca_018[], gouki1_exca_019[], gouki1_exca_020[], gouki1_exca_021[], gouki1_exca_022[], gouki1_exca_023[], gouki1_exca_024[], gouki1_exca_025[], gouki1_exca_026[], gouki1_exca_027[], gouki1_exca_028[], gouki1_exca_029[], gouki1_exca_030[], gouki1_exca_032[], gouki1_exca_033[], gouki1_exca_034[], gouki1_exca_035[], gouki1_exca_036[], gouki1_exca_037[], gouki1_exca_038[], gouki1_exca_039[], gouki1_exca_040[], gouki1_exca_041[], gouki1_exca_042[], gouki1_exca_043[], gouki1_exca_044[], gouki1_exca_045[], gouki1_exca_046[], gouki1_exca_047[], gouki1_exca_048[], gouki1_exca_049[], gouki1_exca_050[], gouki1_exca_053[], gouki1_exca_054[], gouki1_exca_055[], gouki1_exca_056[], gouki1_exca_061[], gouki1_exca_062[], gouki1_exca_063[], gouki1_exca_064[], gouki1_exca_065[], gouki1_exca_066[], gouki1_exca_067[], gouki1_exca_068[], gouki1_exca_069[];
extern const u16 gouki1_exca_000_head[];
extern const u16 gouki1_exca_001_head[];
extern const u16 gouki1_exca_003_head[];
extern const u16 gouki1_exca_004_head[];
extern const u16 gouki1_exca_005_head[];
extern const u16 gouki1_exca_006_head[];
extern const u16 gouki1_exca_007_head[];
extern const u16 gouki1_exca_008_head[];
extern const u16 gouki1_exca_009_head[];
extern const u16 gouki1_exca_010_head[];
extern const u16 gouki1_exca_011_head[];
extern const u16 gouki1_exca_013_head[];
extern const u16 gouki1_exca_014_head[];
extern const u16 gouki1_exca_015_head[];
extern const u16 gouki1_exca_016_head[];
extern const u16 gouki1_exca_017_head[];
extern const u16 gouki1_exca_018_head[];
extern const u16 gouki1_exca_019_head[];
extern const u16 gouki1_exca_020_head[];
extern const u16 gouki1_exca_021_head[];
extern const u16 gouki1_exca_022_head[];
extern const u16 gouki1_exca_023_head[];
extern const u16 gouki1_exca_024_head[];
extern const u16 gouki1_exca_025_head[];
extern const u16 gouki1_exca_026_head[];
extern const u16 gouki1_exca_027_head[];
extern const u16 gouki1_exca_028_head[];
extern const u16 gouki1_exca_029_head[];
extern const u16 gouki1_exca_030_head[];
extern const u16 gouki1_exca_032_head[];
extern const u16 gouki1_exca_033_head[];
extern const u16 gouki1_exca_034_head[];
extern const u16 gouki1_exca_035_head[];
extern const u16 gouki1_exca_036_head[];
extern const u16 gouki1_exca_037_head[];
extern const u16 gouki1_exca_038_head[];
extern const u16 gouki1_exca_039_head[];
extern const u16 gouki1_exca_040_head[];
extern const u16 gouki1_exca_041_head[];
extern const u16 gouki1_exca_042_head[];
extern const u16 gouki1_exca_043_head[];
extern const u16 gouki1_exca_044_head[];
extern const u16 gouki1_exca_045_head[];
extern const u16 gouki1_exca_046_head[];
extern const u16 gouki1_exca_047_head[];
extern const u16 gouki1_exca_048_head[];
extern const u16 gouki1_exca_049_head[];
extern const u16 gouki1_exca_050_head[];
extern const u16 gouki1_exca_053_head[];
extern const u16 gouki1_exca_054_head[];
extern const u16 gouki1_exca_055_head[];
extern const u16 gouki1_exca_056_head[];
extern const u16 gouki1_exca_061_head[];
extern const u16 gouki1_exca_062_head[];
extern const u16 gouki1_exca_063_head[];
extern const u16 gouki1_exca_064_head[];
extern const u16 gouki1_exca_065_head[];
extern const u16 gouki1_exca_066_head[];
extern const u16 gouki1_exca_067_head[];
extern const u16 gouki1_exca_068_head[];
extern const u16 gouki1_exca_069_head[];
extern const u16 gouki1_saca_000[], gouki1_saca_001[], gouki1_saca_002[], gouki1_saca_024[], gouki1_saca_025[], gouki1_saca_026[], gouki1_saca_028[], gouki1_saca_029[], gouki1_saca_030[], gouki1_saca_032[], gouki1_saca_033[], gouki1_saca_034[], gouki1_saca_036[], gouki1_saca_040[], gouki1_saca_044[], gouki1_saca_048[], gouki1_saca_052[], gouki1_saca_053[], gouki1_saca_054[], gouki1_saca_056[], gouki1_saca_060[], gouki1_saca_061[], gouki1_saca_062[], gouki1_saca_063[], gouki1_saca_064[], gouki1_saca_067[], gouki1_saca_068[], gouki1_saca_069[], gouki1_saca_070[], gouki1_saca_072[], gouki1_saca_073[], gouki1_saca_074[], gouki1_saca_076[], gouki1_saca_080[], gouki1_saca_081[], gouki1_saca_082[], gouki1_saca_084[], gouki1_saca_085[], gouki1_saca_086[], gouki1_saca_087[];
extern const u16 gouki1_saca_000_head[];
extern const u16 gouki1_saca_001_head[];
extern const u16 gouki1_saca_002_head[];
extern const u16 gouki1_saca_024_head[];
extern const u16 gouki1_saca_025_head[];
extern const u16 gouki1_saca_026_head[];
extern const u16 gouki1_saca_028_head[];
extern const u16 gouki1_saca_029_head[];
extern const u16 gouki1_saca_030_head[];
extern const u16 gouki1_saca_032_head[];
extern const u16 gouki1_saca_033_head[];
extern const u16 gouki1_saca_034_head[];
extern const u16 gouki1_saca_036_head[];
extern const u16 gouki1_saca_040_head[];
extern const u16 gouki1_saca_044_head[];
extern const u16 gouki1_saca_048_head[];
extern const u16 gouki1_saca_052_head[];
extern const u16 gouki1_saca_053_head[];
extern const u16 gouki1_saca_054_head[];
extern const u16 gouki1_saca_056_head[];
extern const u16 gouki1_saca_060_head[];
extern const u16 gouki1_saca_061_head[];
extern const u16 gouki1_saca_062_head[];
extern const u16 gouki1_saca_063_head[];
extern const u16 gouki1_saca_064_head[];
extern const u16 gouki1_saca_067_head[];
extern const u16 gouki1_saca_068_head[];
extern const u16 gouki1_saca_069_head[];
extern const u16 gouki1_saca_070_head[];
extern const u16 gouki1_saca_072_head[];
extern const u16 gouki1_saca_073_head[];
extern const u16 gouki1_saca_074_head[];
extern const u16 gouki1_saca_076_head[];
extern const u16 gouki1_saca_080_head[];
extern const u16 gouki1_saca_081_head[];
extern const u16 gouki1_saca_082_head[];
extern const u16 gouki1_saca_084_head[];
extern const u16 gouki1_saca_085_head[];
extern const u16 gouki1_saca_086_head[];
extern const u16 gouki1_saca_087_head[];
extern const u16 gouki1_cbca_000[], gouki1_cbca_001[], gouki1_cbca_002[], gouki1_cbca_003[], gouki1_cbca_004[], gouki1_cbca_005[], gouki1_cbca_006[], gouki1_cbca_007[], gouki1_cbca_008[], gouki1_cbca_009[], gouki1_cbca_010[], gouki1_cbca_011[], gouki1_cbca_012[], gouki1_cbca_013[], gouki1_cbca_014[], gouki1_cbca_015[], gouki1_cbca_016[], gouki1_cbca_017[], gouki1_cbca_018[], gouki1_cbca_019[], gouki1_cbca_020[], gouki1_cbca_021[], gouki1_cbca_022[], gouki1_cbca_023[], gouki1_cbca_024[], gouki1_cbca_025[], gouki1_cbca_026[], gouki1_cbca_028[], gouki1_cbca_029[], gouki1_cbca_030[], gouki1_cbca_031[], gouki1_cbca_032[], gouki1_cbca_033[], gouki1_cbca_034[], gouki1_cbca_035[], gouki1_cbca_036[], gouki1_cbca_037[], gouki1_cbca_038[], gouki1_cbca_039[], gouki1_cbca_040[], gouki1_cbca_041[], gouki1_cbca_042[], gouki1_cbca_043[], gouki1_cbca_044[];
extern const u16 gouki1_cbca_000_head[];
extern const u16 gouki1_cbca_001_head[];
extern const u16 gouki1_cbca_002_head[];
extern const u16 gouki1_cbca_003_head[];
extern const u16 gouki1_cbca_004_head[];
extern const u16 gouki1_cbca_005_head[];
extern const u16 gouki1_cbca_006_head[];
extern const u16 gouki1_cbca_007_head[];
extern const u16 gouki1_cbca_008_head[];
extern const u16 gouki1_cbca_009_head[];
extern const u16 gouki1_cbca_010_head[];
extern const u16 gouki1_cbca_011_head[];
extern const u16 gouki1_cbca_012_head[];
extern const u16 gouki1_cbca_013_head[];
extern const u16 gouki1_cbca_014_head[];
extern const u16 gouki1_cbca_015_head[];
extern const u16 gouki1_cbca_016_head[];
extern const u16 gouki1_cbca_017_head[];
extern const u16 gouki1_cbca_018_head[];
extern const u16 gouki1_cbca_019_head[];
extern const u16 gouki1_cbca_020_head[];
extern const u16 gouki1_cbca_021_head[];
extern const u16 gouki1_cbca_022_head[];
extern const u16 gouki1_cbca_023_head[];
extern const u16 gouki1_cbca_024_head[];
extern const u16 gouki1_cbca_025_head[];
extern const u16 gouki1_cbca_026_head[];
extern const u16 gouki1_cbca_028_head[];
extern const u16 gouki1_cbca_029_head[];
extern const u16 gouki1_cbca_030_head[];
extern const u16 gouki1_cbca_031_head[];
extern const u16 gouki1_cbca_032_head[];
extern const u16 gouki1_cbca_033_head[];
extern const u16 gouki1_cbca_034_head[];
extern const u16 gouki1_cbca_035_head[];
extern const u16 gouki1_cbca_036_head[];
extern const u16 gouki1_cbca_037_head[];
extern const u16 gouki1_cbca_038_head[];
extern const u16 gouki1_cbca_039_head[];
extern const u16 gouki1_cbca_040_head[];
extern const u16 gouki1_cbca_041_head[];
extern const u16 gouki1_cbca_042_head[];
extern const u16 gouki1_cbca_043_head[];
extern const u16 gouki1_cbca_044_head[];

/* normal scripts: 51 entries */
const u16* const gouki1_nmca[52] = {
    gouki1_nmca_000,  /* 0 KAMAE */
    gouki1_nmca_001,  /* 1 HURIMUKI */
    gouki1_nmca_002,  /* 2 FRONT WALK */
    gouki1_nmca_003,  /* 3 BACK WALK */
    gouki1_nmca_004,  /* 4 DASH HUMIKOMI */
    gouki1_nmca_005,  /* 5 DASH TOBINOKI */
    gouki1_nmca_006,  /* 6 KAGAMU */
    gouki1_nmca_007,  /* 7 KAGAMI KAMAE */
    gouki1_nmca_008,  /* 8 KAGAMI TURN */
    gouki1_nmca_008,  /* 9 KAGAMI F WALK */
    gouki1_nmca_008,  /* 10 KAGAMI B WALK */
    gouki1_nmca_011,  /* 11 STAND UP */
    gouki1_nmca_012,  /* 12 JUMP JUNBI */
    gouki1_nmca_013,  /* 13 SP JUMP JUNBI */
    gouki1_nmca_014,  /* 14 JUMP FRONT */
    gouki1_nmca_015,  /* 15 JUMP VERTICAL */
    gouki1_nmca_016,  /* 16 JUMP BACK */
    gouki1_nmca_017,  /* 17 S JUMP FRONT */
    gouki1_nmca_017,  /* 18 S JUMP V */
    gouki1_nmca_017,  /* 19 S JUMP BACK */
    gouki1_nmca_020,  /* 20 SP JUMP FRONT */
    gouki1_nmca_021,  /* 21 SP JUMP V */
    gouki1_nmca_022,  /* 22 SP JUMP BACK */
    gouki1_nmca_023,  /* 23 WALK END */
    gouki1_nmca_024,  /* 24 PARING HEAD */
    gouki1_nmca_024,  /* 25 PARING UP */
    gouki1_nmca_026,  /* 26 PARING DOWN */
    gouki1_nmca_027,  /* 27 PARING AIR F */
    gouki1_nmca_027,  /* 28 PARING AIR B */
    gouki1_nmca_029,  /* 29 GUARD HEAD */
    gouki1_nmca_030,  /* 30 GUARD UP */
    gouki1_nmca_031,  /* 31 GUARD DOWN */
    gouki1_nmca_032,  /* 32 GUARD AIR */
    gouki1_nmca_033,  /* 33 no name */
    gouki1_nmca_033,  /* 34 no name */
    gouki1_nmca_033,  /* 35 no name */
    gouki1_nmca_033,  /* 36 no name */
    gouki1_nmca_033,  /* 37 no name */
    gouki1_nmca_038,  /* 38 P BREAK ZUJOU */
    gouki1_nmca_038,  /* 39 P BREAK UP */
    gouki1_nmca_040,  /* 40 P BREAK DOWN */
    gouki1_nmca_041,  /* 41 P BREAK AIR F */
    gouki1_nmca_041,  /* 42 P BREAK AIR R */
    gouki1_nmca_043,  /* 43 TUKAMIHAZUSI */
    gouki1_nmca_044,  /* 44 TUKAMIHAZUSARE */
    gouki1_nmca_045,  /* 45 TUKAMIHAZUSI */
    gouki1_nmca_046,  /* 46 TUKAMIHAZUSARE */
    gouki1_nmca_047,  /* 47 no name */
    gouki1_nmca_048,  /* 48 no name */
    gouki1_nmca_049,  /* 49 no name */
    gouki1_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 gouki1_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_000[92] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x5402, 0, 157, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5403, 0, 157, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5404, 0, 157, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5405, 0, 157, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5406, 0, 156, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5407, 0, 156, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5408, 0, 156, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5409, 0, 156, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x540A, 0, 156, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5401, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 gouki1_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_001[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x540B, 0, 258, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x540C, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 gouki1_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_002[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5410, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5411, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5412, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5413, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5414, 0, 159, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5415, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5416, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5417, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5418, 0, 158, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5419, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x541A, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 gouki1_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_003[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x541C, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x541D, 0, 161, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x541E, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x541F, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5420, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5421, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5422, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5423, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5424, 0, 160, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5425, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5426, 0, 160, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 gouki1_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_004[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 273, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(4, 1, 277, 0, 0, 0, 0, 0x5470, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5471, 0, 274, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x5472, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x5473, 0, 276, 0, 0, 33, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5474, 0, 276, 0, 0, 33, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5475, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5475, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 gouki1_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_005[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 10, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5476, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x5477, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5478, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5479, 0, 280, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x547A, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x547A, 0, 280, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x547B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x547B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 gouki1_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_006[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5428, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542A, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542B, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 gouki1_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_007[52] = {
    L4(12, 0, 0, 0, 0, 0, 0, 0x542C, 0, 164, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x5430, 0, 164, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x5431, 0, 165, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5432, 0, 165, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x5433, 0, 165, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 gouki1_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_008[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x543A, 0, 259, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x543B, 0, 259, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x543C, 0, 259, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 gouki1_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_011[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x542D, 0, 163, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 gouki1_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x5429, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5429, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5429, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 gouki1_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x5429, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5429, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 gouki1_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_014[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x544C, 0, 260, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x5453, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5454, 0, 262, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5455, 0, 262, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 gouki1_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_015[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x5440, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5441, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5440, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5441, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5442, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5443, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5444, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5445, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5446, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5447, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 gouki1_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x5454, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5453, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544C, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5458, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 gouki1_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 gouki1_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x544C, 0, 260, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 6, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x5453, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5454, 0, 262, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5455, 0, 262, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 gouki1_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_021[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x5440, 0, 4, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5441, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x546A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5440, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5441, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x546A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5442, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5443, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5444, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5445, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5446, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5447, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5448, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x546B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 gouki1_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_022[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x5454, 0, 263, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 8, 0x5453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 11, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544C, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5458, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 gouki1_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 gouki1_nmca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_024[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x5577, 0, 9, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 711, 0, 0, 0, 0, 0x5578, 0, 10, 0, 0, 0, 6, 0, 0, 0, 14, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x5579, 0, 10, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x557A, 0, 10, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5549, 0, 9, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 gouki1_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_026[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x57B3, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 711, 0, 0, 0, 0, 0x57B4, 0, 2, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x57B5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x57B6, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 gouki1_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_027[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x5468, 0, 4, 0, 0, 0, 18, 6),
    L4(250, 0, 711, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x546C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5446, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5447, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x546B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 gouki1_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x545A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x545B, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x545C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x545A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 gouki1_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x545F, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 gouki1_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_031[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5464, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x5465, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 gouki1_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5468, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5469, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5469, 0, 16, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5469, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 gouki1_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x5469, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 gouki1_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_038[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5461, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 gouki1_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_040[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5465, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5466, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 gouki1_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5468, 0, 4, 0, 0, 0, 18, 8),
    L4(250, 0, 711, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 gouki1_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_043[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5461, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 gouki1_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_044[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5680, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x5681, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5681, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 gouki1_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_045[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5468, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 709, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5453, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5458, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 gouki1_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x5444, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5445, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5446, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5447, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x546B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 gouki1_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 gouki1_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 gouki1_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 gouki1_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_nmca_050[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5461, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const gouki1_dmca[99] = {
    gouki1_dmca_000,  /* 0 GUARD HEAD */
    gouki1_dmca_001,  /* 1 GUARD UP */
    gouki1_dmca_002,  /* 2 GUARD DOWN */
    gouki1_dmca_003,  /* 3 GUARD AIR */
    gouki1_dmca_004,  /* 4 HUSHIN HEAD */
    gouki1_dmca_004,  /* 5 HUSHIN UP */
    gouki1_dmca_006,  /* 6 HUSHIN DOWN */
    gouki1_dmca_006,  /* 7 HUSHIN AIR */
    gouki1_dmca_008,  /* 8 FACE S */
    gouki1_dmca_009,  /* 9 FACE M */
    gouki1_dmca_010,  /* 10 FACE L */
    gouki1_dmca_010,  /* 11 FACE SP */
    gouki1_dmca_008,  /* 12 FOOK OKU S */
    gouki1_dmca_009,  /* 13 FOOK OKU M */
    gouki1_dmca_014,  /* 14 FOOK OKU L */
    gouki1_dmca_015,  /* 15 FOOK OKU SP */
    gouki1_dmca_008,  /* 16 FOOK TEMAE S */
    gouki1_dmca_009,  /* 17 FOOK TEMAE M */
    gouki1_dmca_018,  /* 18 FOOK TEMAE L */
    gouki1_dmca_019,  /* 19 FOOK TEMAE SP */
    gouki1_dmca_008,  /* 20 UPPER S */
    gouki1_dmca_009,  /* 21 UPPER M */
    gouki1_dmca_022,  /* 22 UPPER L */
    gouki1_dmca_022,  /* 23 UPPER SP */
    gouki1_dmca_024,  /* 24 NOUTEN S */
    gouki1_dmca_025,  /* 25 NOUTEN M */
    gouki1_dmca_026,  /* 26 NOUTEN L */
    gouki1_dmca_026,  /* 27 NOUTEN SP */
    gouki1_dmca_024,  /* 28 BODY BROW S */
    gouki1_dmca_029,  /* 29 BODY BROW M */
    gouki1_dmca_030,  /* 30 BODY BROW L */
    gouki1_dmca_030,  /* 31 BODY BROW SP */
    gouki1_dmca_024,  /* 32 BODY UPPER S */
    gouki1_dmca_029,  /* 33 BODY UPPER M */
    gouki1_dmca_034,  /* 34 BODY UPPER L */
    gouki1_dmca_034,  /* 35 BODY UPPER SP */
    gouki1_dmca_036,  /* 36 TATAKI S */
    gouki1_dmca_036,  /* 37 TATAKI M */
    gouki1_dmca_036,  /* 38 TATAKI L */
    gouki1_dmca_036,  /* 39 TATAKI SP */
    gouki1_dmca_036,  /* 40 TATAKI V. S */
    gouki1_dmca_036,  /* 41 TATAKI V. M */
    gouki1_dmca_036,  /* 42 TATAKI V. L */
    gouki1_dmca_036,  /* 43 TATAKI V. SP */
    gouki1_dmca_008,  /* 44 NOBASITA TE S */
    gouki1_dmca_009,  /* 45 NOBASITA TE M */
    gouki1_dmca_010,  /* 46 NOBASITA TE L */
    gouki1_dmca_010,  /* 47 NOBASITA TE SP */
    gouki1_dmca_048,  /* 48 KAGAMI S */
    gouki1_dmca_049,  /* 49 KAGAMI M */
    gouki1_dmca_050,  /* 50 KAGAMI L */
    gouki1_dmca_050,  /* 51 KAGAMI SP */
    gouki1_dmca_052,  /* 52 KGM TATAKI S */
    gouki1_dmca_052,  /* 53 KGM TATAKI M */
    gouki1_dmca_052,  /* 54 KGM TATAKI L */
    gouki1_dmca_052,  /* 55 KGM TATAKI SP */
    gouki1_dmca_052,  /* 56 KGM TTKI V.S */
    gouki1_dmca_052,  /* 57 KGM TTKI V.M */
    gouki1_dmca_052,  /* 58 KGM TTKI V.L */
    gouki1_dmca_052,  /* 59 KGM TTKI V.SP */
    gouki1_dmca_060,  /* 60 NEKOROBI S */
    gouki1_dmca_060,  /* 61 NEKOROBI M */
    gouki1_dmca_060,  /* 62 NEKOROBI L */
    gouki1_dmca_060,  /* 63 NEKOROBI SP */
    gouki1_dmca_064,  /* 64 OKIAGARI */
    gouki1_dmca_065,  /* 65 OKIAGARI F */
    gouki1_dmca_066,  /* 66 OKIAGARI B */
    gouki1_dmca_067,  /* 67 LOSE NO STAND */
    gouki1_dmca_068,  /* 68 LOSE SONABA */
    gouki1_dmca_068,  /* 69 LOSE KAGAMI */
    gouki1_dmca_070,  /* 70 PIYO */
    gouki1_dmca_071,  /* 71 UKEMI MOVE F */
    gouki1_dmca_072,  /* 72 UKEMI MOVE R */
    gouki1_dmca_073,  /* 73 SHIMEOTASARE */
    gouki1_dmca_074,  /* 74 TATI TOUKETU S */
    gouki1_dmca_075,  /* 75 TATI TOUKETU M */
    gouki1_dmca_076,  /* 76 TATI TOUKETU L */
    gouki1_dmca_076,  /* 77 TATI TOUKETU P */
    gouki1_dmca_078,  /* 78 KGM TOUKETU S */
    gouki1_dmca_079,  /* 79 KGM TOUKETU M */
    gouki1_dmca_080,  /* 80 KGM TOUKETU L */
    gouki1_dmca_080,  /* 81 KGM TOUKETU P */
    gouki1_dmca_082,  /* 82 TATI DENGEKI S */
    gouki1_dmca_083,  /* 83 TATI DENGEKI M */
    gouki1_dmca_084,  /* 84 TATI DENGEKI L */
    gouki1_dmca_084,  /* 85 TATI DENGEKI P */
    gouki1_dmca_082,  /* 86 KGM DENGEKI S */
    gouki1_dmca_083,  /* 87 KGM DENGEKI M */
    gouki1_dmca_084,  /* 88 KGM DENGEKI L */
    gouki1_dmca_084,  /* 89 KGM DENGEKI P */
    gouki1_dmca_090,  /* 90 OKIAGARI FRONT */
    gouki1_dmca_091,  /* 91 OKIAGARI REAR */
    gouki1_dmca_008,  /* 92 TATI MOE S */
    gouki1_dmca_009,  /* 93 TATI MOE M */
    gouki1_dmca_010,  /* 94 TATI MOE L */
    gouki1_dmca_010,  /* 95 TATI MOE SP */
    gouki1_dmca_096,  /* 96 no name */
    gouki1_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 gouki1_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_000[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x545C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x545D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x545E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x545C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x545A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 gouki1_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_001[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5461, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x5462, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5460, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5459, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 gouki1_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x5465, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5466, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x5467, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5465, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5463, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 gouki1_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x5468, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x5469, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x5469, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5469, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5469, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5469, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 gouki1_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_004[44] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5483, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 gouki1_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_006[52] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5488, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5480, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5481, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5482, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5483, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 gouki1_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5490, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 133, 706, 0, 0, 0, 0, 0x5490, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5492, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 gouki1_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5491, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 134, 706, 0, 0, 0, 0, 0x5491, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5495, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5496, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5492, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 gouki1_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_010[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5499, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 135, 707, 0, 0, 0, 0, 0x5499, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x549A, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x549B, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x549C, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 gouki1_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_014[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5499, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 136, 707, 0, 0, 0, 0, 0x5499, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x549A, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x54A7, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x54A8, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x54A6, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 gouki1_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_015[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5497, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 137, 707, 0, 0, 0, 0, 0x5498, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5499, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x549A, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x54A7, 0, 173, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x54A8, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x54A6, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 gouki1_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_018[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54A0, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 137, 707, 0, 0, 0, 0, 0x54A0, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x54A2, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x54A3, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x54A4, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x54A5, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x54A6, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 gouki1_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_019[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5494, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 138, 707, 0, 0, 0, 0, 0x54A0, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x54A1, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x54A2, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x54A3, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x54A4, 0, 173, 0, 0, 0, 0, 0),
    L4(7, 10, 0, 0, 0, 0, 0, 0x54A5, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x54A6, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 gouki1_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5520, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 135, 707, 0, 0, 0, 0, 0x54AF, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54B0, 0, 168, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54B1, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x549C, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x549D, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 gouki1_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_025[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54AA, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 134, 706, 0, 0, 0, 0, 0x54AB, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54AC, 0, 175, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54AD, 0, 176, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 gouki1_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54AB, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 135, 706, 0, 0, 0, 0, 0x54AB, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54AB, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54AC, 0, 177, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54AD, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 gouki1_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54B3, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 134, 706, 0, 0, 0, 0, 0x54B4, 0, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54B5, 0, 175, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54B6, 0, 175, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x54B7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5599, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 gouki1_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54BC, 0, 174, 0, 0, 0, 0, 0),
    L4(1, 136, 706, 0, 0, 0, 0, 0x54BC, 0, 175, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54BC, 0, 176, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54B4, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54B5, 0, 174, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54B6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x54B7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5599, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 gouki1_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54BB, 0, 174, 0, 0, 0, 0, 0),
    L4(1, 139, 707, 0, 0, 0, 0, 0x54BE, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54BF, 0, 176, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54C0, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x54C1, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54C2, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54C3, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54C4, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54C5, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5599, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x559A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 gouki1_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54AD, 0, 177, 0, 0, 0, 0, 0),
    L4(4, 135, 707, 0, 0, 0, 0, 0x54AE, 0, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54AF, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54B0, 0, 169, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x54B1, 0, 167, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x549C, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x549D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x549E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 gouki1_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x550C, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x550D, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 gouki1_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_048[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54C6, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 133, 706, 0, 0, 0, 0, 0x54C7, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54C7, 0, 179, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 gouki1_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_049[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54CA, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 133, 706, 0, 0, 0, 0, 0x54CB, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54C7, 0, 180, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 gouki1_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_050[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x54CD, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54CE, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 135, 707, 0, 0, 0, 0, 0x54CA, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54CF, 0, 180, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54D0, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x543A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x543B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x543C, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 gouki1_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 132, 0, 0, 0, 0, 0, 0x54CD, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 0, 707, 0, 0, 0, 0, 0x54CA, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 gouki1_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_060[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54F9, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 707, 0, 0, 0, 0, 0x54FA, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54FB, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F5, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 gouki1_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 gouki1_dmca_064[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5540, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5541, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5542, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5543, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5544, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5545, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(6, 12, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5547, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5548, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 gouki1_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 gouki1_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5690, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5550, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5551, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5552, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5553, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5548, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 gouki1_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 gouki1_dmca_066[156] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5540, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5541, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5552, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5551, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5550, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5548, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 gouki1_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 gouki1_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_068[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5490, 0, 202, 0, 0, 0, 32, 86),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5490, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5530, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5531, 0, 204, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5532, 0, 205, 0, 0, 0, 0, 0),
    L4(6, 0, 289, 0, 0, 0, 0, 0x5533, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x5534, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5535, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5536, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5537, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5538, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x5539, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x553E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x553F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 gouki1_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x5511, 0, 267, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5512, 0, 268, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5513, 0, 269, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5514, 0, 269, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x550E, 0, 270, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x550F, 0, 270, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5510, 0, 271, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 gouki1_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5552, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 709, 0, 0, 0, 0, 0x554B, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554C, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554D, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554E, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554F, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5550, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5551, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 gouki1_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_072[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5540, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -11776, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 709, 0, 0, 0, 0, 0x554E, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x554D, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x554C, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x554B, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5548, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5548, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 gouki1_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_073[148] = {
    L4(2, 0, 707, 0, 0, 0, 0, 0x5490, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5530, 0, 203, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5531, 0, 204, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5532, 0, 205, 0, 0, 0, 0, 0),
    L4(3, 0, 289, 0, 0, 0, 0, 0x5533, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x5534, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5535, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5536, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5537, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5538, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x5539, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x553A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x553B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x553D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x553E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x553F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x553F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 gouki1_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5490, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5490, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 gouki1_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5494, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5494, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 gouki1_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5497, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5497, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 gouki1_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54C6, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x54C6, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 gouki1_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54C9, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x54C9, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54C8, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 gouki1_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54CC, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x54CC, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x543B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x543C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x543D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 gouki1_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5718, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5719, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 gouki1_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5718, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5719, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 gouki1_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5718, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5717, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5719, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 gouki1_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 gouki1_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5690, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x554B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5550, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5551, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5552, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5553, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5548, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 gouki1_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 gouki1_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5540, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5541, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5552, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5551, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5550, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x554C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x554B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5546, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5547, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5548, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 gouki1_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_096[44] = {
    L4(3, 2, 707, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 gouki1_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_dmca_097[44] = {
    L4(3, 2, 707, 0, 0, 0, 0, 0x54F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F8, 0, 17, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 17, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 17, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const gouki1_btca[37] = {
    gouki1_btca_000,  /* 0 AIR NORMAL */
    gouki1_btca_001,  /* 1 ASIBARAI SIRI */
    gouki1_btca_002,  /* 2 ASIB TUNNOMERI */
    gouki1_btca_003,  /* 3 NOKEZORI */
    gouki1_btca_004,  /* 4 KUNOJI */
    gouki1_btca_005,  /* 5 KIRIMOMI */
    gouki1_btca_006,  /* 6 UPPER */
    gouki1_btca_007,  /* 7 BODY UPPER */
    gouki1_btca_008,  /* 8 HARAYARARE */
    gouki1_btca_009,  /* 9 TATAKI AIR */
    gouki1_btca_010,  /* 10 TTKI V. AIR */
    gouki1_btca_011,  /* 11 HUMI ASIB */
    gouki1_btca_012,  /* 12 FACE */
    gouki1_btca_013,  /* 13 ASIB SIRI LOSE */
    gouki1_btca_014,  /* 14 ASIB TUN LOSE */
    gouki1_btca_015,  /* 15 DENKI */
    gouki1_btca_016,  /* 16 KUNOJI NOKE */
    gouki1_btca_017,  /* 17 BODY UPPER SP */
    gouki1_btca_018,  /* 18 HANEAGARI */
    gouki1_btca_019,  /* 19 TOUKETSU A */
    gouki1_btca_020,  /* 20 BODY SLAM */
    gouki1_btca_021,  /* 21 IPPONZEOI */
    gouki1_btca_022,  /* 22 TOMOE RYU */
    gouki1_btca_023,  /* 23 MONKEY FLIP */
    gouki1_btca_024,  /* 24 TOMOE ORO */
    gouki1_btca_025,  /* 25 SNAKE FANG */
    gouki1_btca_026,  /* 26 FLANKEN.S */
    gouki1_btca_027,  /* 27 KISHINRIKI */
    gouki1_btca_028,  /* 28 SPLASH.M */
    gouki1_btca_029,  /* 29 HARAIGOSHI */
    gouki1_btca_030,  /* 30 ALEX B.D */
    gouki1_btca_031,  /* 31 GILL */
    gouki1_btca_032,  /* 32 HANEKAERI HARA */
    gouki1_btca_033,  /* 33 S HANEAGARI */
    gouki1_btca_034,  /* 34 TATUMAKIZANKU */
    gouki1_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 gouki1_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_000[68] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 706, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x54BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x5453, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 gouki1_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5504, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 7, 0x5505, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x5506, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5507, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x5508, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 gouki1_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_002[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5504, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 706, 0, 0, 0, 0, 0x5505, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5506, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5507, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5508, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 gouki1_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_003[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 gouki1_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_004[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 706, 0, 0, 0, 0, 0x54BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54BF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54FF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 gouki1_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_005[156] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5520, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 707, 0, 0, 0, 0, 0x5521, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5522, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5523, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5524, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5525, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5526, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5527, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5528, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5529, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552A, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552B, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552C, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552D, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552E, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x552F, 0, 224, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x552F, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 gouki1_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_006[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x5710, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5711, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 gouki1_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_007[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5712, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x5713, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5714, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5715, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 gouki1_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_008[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54BD, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x5711, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 gouki1_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_009[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 707, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 gouki1_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_010[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x550B, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 707, 0, 0, 0, 0, 0x550C, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x550D, 0, 235, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 gouki1_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_011[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5509, 0, 233, 0, 0, 0, 0, 0),
    L4(250, 0, 706, 0, 0, 0, 0, 0x550A, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 gouki1_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_012[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5491, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 706, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 gouki1_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 gouki1_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 gouki1_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_015[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x5717, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5717, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5718, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5717, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5719, 0, 231, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 707, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 gouki1_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_016[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 706, 0, 0, 0, 0, 0x54BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54BF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54FF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 gouki1_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_017[148] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x5710, 0, 226, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 707, 0, 0, 0, 0, 0x5711, 0, 227, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 gouki1_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_018[156] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 706, 0, 0, 0, 0, 0x54EC, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x54E8, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x54E7, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x54E6, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x54E5, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x54E3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x54EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x54F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 gouki1_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5495, 0, 232, 0, 0, 0, 0, 0),
    L4(250, 0, 706, 0, 0, 0, 0, 0x5495, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 gouki1_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FA, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 gouki1_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 gouki1_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_022[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x552C, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5537, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 236, 0, 0, 0, 32, 105),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 gouki1_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x552C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5537, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 236, 0, 0, 0, 32, 105),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 gouki1_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x552C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5537, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 236, 0, 0, 0, 32, 105),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 gouki1_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 236, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 gouki1_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5537, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54E8, 0, 236, 0, 0, 0, 32, 105),
    L4(6, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FB, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 gouki1_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_027[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x54E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x54E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x54E5, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x54E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 gouki1_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_028[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54EC, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 gouki1_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E8, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E8, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 gouki1_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_030[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5712, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x5713, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5714, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5715, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x54E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x54E5, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x54E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x54E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 gouki1_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_031[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5504, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 707, 0, 0, 0, 0, 0x5505, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5506, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5507, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5508, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 gouki1_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x54BD, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5711, 0, 236, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 gouki1_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_033[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x54EF, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 706, 0, 0, 0, 0, 0x54EF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F0, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x54EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x54F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 gouki1_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_034[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x54AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 707, 0, 0, 0, 0, 0x5710, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5711, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 gouki1_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_btca_035[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x54E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x54E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x54E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x54E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 20 entries */
const u16* const gouki1_caca[21] = {
    gouki1_caca_000,  /* 0 CATCH 1 */
    gouki1_caca_000,  /* 1 CATCH 2 */
    gouki1_caca_002,  /* 2 CATCH 3 */
    gouki1_caca_002,  /* 3 CATCH 4 */
    gouki1_caca_004,  /* 4 CATCH 5 */
    gouki1_caca_004,  /* 5 CATCH 6 */
    gouki1_caca_004,  /* 6 CATCH 7 */
    gouki1_caca_004,  /* 7 CATCH 8 */
    gouki1_caca_008,  /* 8 CATCH 9 */
    gouki1_caca_008,  /* 9 CATCH 10 */
    gouki1_caca_010,  /* 10 CATCH 11 */
    gouki1_caca_010,  /* 11 CATCH 12 */
    gouki1_caca_012,  /* 12 CATCH 13 */
    gouki1_caca_012,  /* 13 CATCH 14 */
    gouki1_caca_014,  /* 14 CATCH 15 */
    gouki1_caca_014,  /* 15 CATCH 16 */
    gouki1_caca_014,  /* 16 CATCH 17 */
    gouki1_caca_014,  /* 17 CATCH 18 */
    gouki1_caca_018,  /* 18 CATCH 19 */
    gouki1_caca_019,  /* 19 CATCH 20 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2 */
const u16 gouki1_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 gouki1_caca_000[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 256, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 256, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 256, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5682, 0, 0, 0, 0, 0, 0, 0, 256, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5683, 0, 0, 0, 0, 0, 0, 0, 256, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x5684, 0, 0, 0, 0, 0, 0, 0, 256, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5685, 0, 0, 0, 0, 0, 0, 0, 256, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5686, 0, 0, 0, 0, 0, 0, 0, 256, 192, 0, 0, 0),
    L6(2, 0, 711, 0, 0, 0, 0, 0x5687, 0, 0, 0, 0, 0, 0, 0, 256, 216, 0, 0, 0),
    L6(2, 2, 270, 0, 0, 0, 0, 0x5688, -47, 0, 0, 0, 0, 0, 0, 256, 240, 0, 0, 0),
    L6(10, 9, 0, 0, 0, 0, 0, 0x5689, 0, 0, 0, 0, 0, 0, 0, 256, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x568A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x568B, 0, 1, 0, 0, 0, 0, 0, 256, 0, 170, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x568C, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x568D, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3, 3 CATCH 4 */
const u16 gouki1_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 gouki1_caca_002[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5682, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5683, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x5684, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5685, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5686, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5687, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 2, 711, 0, 0, 0, 0, 0x5688, -47, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(10, 9, 270, 0, 0, 0, 0, 0x5689, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x568A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x568B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x568C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x568D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 gouki1_caca_004_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 gouki1_caca_004[196] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 256, 288, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x568E, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 0),
    L6(7, 0, 710, 0, 0, 0, 0, 0x568F, 0, 0, 0, 0, 0, 0, 0, 256, 384, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x5690, 0, 0, 0, 0, 0, 0, 0, 256, 408, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x5691, -49, 0, 0, 0, 0, 0, 0, 256, 432, 0, 0, 0),
    L6(7, 9, 0, 0, 0, 0, 0, 0x5692, 0, 0, 0, 0, 0, 0, 0, 256, 456, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x5693, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5694, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5695, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x5696, 0, 1, 0, 0, 0, 24, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9, 9 CATCH 10 */
const u16 gouki1_caca_008_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 gouki1_caca_008[196] = {
    L6(4, 0, 264, 0, 0, 0, 0, 0x56B0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56B1, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56B2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56B3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5716, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5717, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5718, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5719, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x571A, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x571B, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5719, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5718, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5717, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5716, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56B3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x56B3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11, 11 CATCH 12 */
const u16 gouki1_caca_010_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 gouki1_caca_010[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x5683, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14 */
const u16 gouki1_caca_012_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 gouki1_caca_012[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x5683, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16, 16 CATCH 17, 17 CATCH 18 */
const u16 gouki1_caca_014_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 gouki1_caca_014[76] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x5560, 0, 0, 0, 0, 0, 0, 0, 256, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5680, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x568E, 0, 0, 0, 0, 0, 24, 0, 256, 360, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 CATCH 19 */
const u16 gouki1_caca_018_head[4] = { HEAD(6, 0, 64, 10, 0, 0, 0) };
const u16 gouki1_caca_018[508] = {
    CMD(CM_NGDA, 0, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(15, 0, 264, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 19, 6, 780, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 42, 0, 780, 480, 0, 0, 0),
    L6(5, 0, 256, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 88, 780, 480, 0, 0, 0),
    L6(5, 0, 260, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 89, 0, 480, 0, 0, 0),
    L6(5, 0, 257, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 90, 0, 480, 0, 0, 0),
    L6(5, 0, 261, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 91, 0, 480, 0, 0, 0),
    L6(5, 0, 258, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 92, 0, 480, 0, 0, 0),
    L6(4, 0, 262, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 93, 0, 480, 0, 0, 0),
    L6(4, 0, 257, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 94, 0, 480, 0, 0, 0),
    L6(4, 0, 258, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 95, 0, 480, 0, 0, 0),
    L6(4, 0, 261, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 96, 0, 480, 0, 0, 0),
    L6(4, 0, 262, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 97, 0, 480, 0, 0, 0),
    L6(3, 0, 256, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 98, 0, 480, 0, 0, 0),
    L6(3, 0, 261, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 99, 0, 480, 0, 0, 0),
    L6(3, 0, 262, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 100, 0, 480, 0, 0, 0),
    L6(3, 0, 258, 0, 0, 0, 0, 0x5681, 0, 0, 0, 0, 0, 1, 101, 0, 480, 0, 0, 0),
    L6(2, 2, 301, 0, 0, 0, 0, 0x5681, -76, 0, 0, 0, 0, 1, 102, 0, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    CMD(CM_EXEC, 12, 12, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 0, 0, 0, 0, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EMHP, 1, 0, 16396), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RLJMP, 0, 8192, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 7, 0, 0x56F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 7, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 7, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 8, 0, 0x56F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 8, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 8, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x56F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x56F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x56F1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x56F1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 CATCH 20 */
const u16 gouki1_caca_019_head[4] = { HEAD(6, 0, 28, 10, 0, 0, 0) };
const u16 gouki1_caca_019[280] = {
    CMD(CM_NGDA, 6, 67, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x57DD, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57DE, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57DF, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57E0, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57E1, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57E2, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x57E3, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x57E4, 0, 0, 0, 0, 0, 0, 0, 0, 720, 266, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x57E5, -88, 0, 0, 0, 0, 0, 0, 0, 744, 268, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x57E6, 0, 0, 0, 0, 0, 0, 0, 0, 768, 270, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x57E7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x57E8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x57E9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 276, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x57EA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 278, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x57EB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x57EC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x57ED, 0, 0, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x57EE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 286, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x57EF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const gouki1_cuca[69] = {
    gouki1_cuca_000,  /* 0 ALEX ZUTUKI */
    gouki1_cuca_001,  /* 1 ALEX BODY S */
    gouki1_cuca_002,  /* 2 ALEX BACK D */
    gouki1_cuca_003,  /* 3 ALEX POWER B */
    gouki1_cuca_004,  /* 4 ALEX SLEEPER */
    gouki1_cuca_005,  /* 5 RYU SEOINAGE */
    gouki1_cuca_006,  /* 6 IBUKI */
    gouki1_cuca_007,  /* 7 DADLEY L B */
    gouki1_cuca_008,  /* 8 IBUKI KUBIORI */
    gouki1_cuca_009,  /* 9 NECRO S T */
    gouki1_cuca_010,  /* 10 RYU TOMOENAGE */
    gouki1_cuca_011,  /* 11 YUN HIZAGERI */
    gouki1_cuca_012,  /* 12 ORO KUBISIME */
    gouki1_cuca_013,  /* 13 NECRO G S */
    gouki1_cuca_014,  /* 14 DUDDLEY D S */
    gouki1_cuca_015,  /* 15 YUN MONKEY F */
    gouki1_cuca_016,  /* 16 ORO TOMOENAGE */
    gouki1_cuca_017,  /* 17 ORO NIOURIKI */
    gouki1_cuca_018,  /* 18 ORO GIGOKU G */
    gouki1_cuca_019,  /* 19 YUN */
    gouki1_cuca_020,  /* 20 NECRO SNAKE F */
    gouki1_cuca_021,  /* 21 NECRO F S */
    gouki1_cuca_022,  /* 22 IBUKI HARAIG */
    gouki1_cuca_023,  /* 23 GILL SPLASH M */
    gouki1_cuca_024,  /* 24 KEN HIZAGERI */
    gouki1_cuca_025,  /* 25 ORO KISINRIKI */
    gouki1_cuca_026,  /* 26 SEAN TACKLE */
    gouki1_cuca_027,  /* 27 ALEX HYPER B */
    gouki1_cuca_028,  /* 28 NECRO SLAM D */
    gouki1_cuca_029,  /* 29 ELENA ASINAGE */
    gouki1_cuca_030,  /* 30 GILL IMPACT C */
    gouki1_cuca_031,  /* 31 ALEX S H B */
    gouki1_cuca_032,  /* 32 ALEX F N D */
    gouki1_cuca_033,  /* 33 no name */
    gouki1_cuca_034,  /* 34 IBUKI */
    gouki1_cuca_035,  /* 35 IBUKI YOROI D */
    gouki1_cuca_036,  /* 36 no name */
    gouki1_cuca_037,  /* 37 MAWARIKOMI M F */
    gouki1_cuca_038,  /* 38 HUGO BODY S */
    gouki1_cuca_039,  /* 39 HUGO N G T */
    gouki1_cuca_040,  /* 40 HUGO M S P */
    gouki1_cuca_041,  /* 41 HUGO S D B B */
    gouki1_cuca_042,  /* 42 no name */
    gouki1_cuca_043,  /* 43 no name */
    gouki1_cuca_044,  /* 44 no name */
    gouki1_cuca_045,  /* 45 no name */
    gouki1_cuca_046,  /* 46 no name */
    gouki1_cuca_047,  /* 47 no name */
    gouki1_cuca_048,  /* 48 no name */
    gouki1_cuca_049,  /* 49 no name */
    gouki1_cuca_050,  /* 50 no name */
    gouki1_cuca_051,  /* 51 no name */
    gouki1_cuca_052,  /* 52 no name */
    gouki1_cuca_053,  /* 53 no name */
    gouki1_cuca_054,  /* 54 no name */
    gouki1_cuca_055,  /* 55 no name */
    gouki1_cuca_056,  /* 56 no name */
    gouki1_cuca_057,  /* 57 no name */
    gouki1_cuca_058,  /* 58 no name */
    gouki1_cuca_059,  /* 59 no name */
    gouki1_cuca_060,  /* 60 no name */
    gouki1_cuca_061,  /* 61 no name */
    gouki1_cuca_062,  /* 62 no name */
    gouki1_cuca_063,  /* 63 no name */
    gouki1_cuca_064,  /* 64 no name */
    gouki1_cuca_065,  /* 65 no name */
    gouki1_cuca_066,  /* 66 no name */
    gouki1_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 gouki1_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AA),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 gouki1_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5537),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5503),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5501),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54ED),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 gouki1_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 gouki1_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x549A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5508),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EB),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 gouki1_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54AA),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54AA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 gouki1_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5509),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E7),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54EE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 gouki1_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5479),
    L2(250, 0, 0, 0, 0, 0, 0, 0x547A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5474),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5474),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5560),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5563),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5584),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5582),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5583),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 gouki1_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 gouki1_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5520),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 gouki1_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 gouki1_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 1, 0, 0, 0x552C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 gouki1_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 gouki1_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x544B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 gouki1_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EB),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54EB),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 gouki1_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BF),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54FF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 gouki1_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5501),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x552C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 gouki1_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x552C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 gouki1_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x549A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x549B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E2),
    L2(250, 2, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 gouki1_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x554B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x554C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x554D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x554E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5550),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5551),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5552),
    L2(250, 0, 0, 0, 0, 0, 0, 0x554B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 gouki1_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5401),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 gouki1_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 1, 0, 0, 0x545A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x545B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x545C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5476),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5487),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5486),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5485),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E4),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 gouki1_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5476),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5475),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54B3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 gouki1_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E7),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 gouki1_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54EB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 gouki1_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 gouki1_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x549A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x549B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E2),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 gouki1_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 3, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F7),
    L2(250, 3, 0, 0, 0, 0, 0, 0x54FA),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54F7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 gouki1_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_027[152] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EB),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 gouki1_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54F3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 gouki1_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5500),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5501),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 gouki1_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5711),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5711),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5710),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5710),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 gouki1_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AB),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 gouki1_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5501),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5503),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 gouki1_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54EA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 gouki1_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B0),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54B0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 gouki1_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5479),
    L2(250, 0, 0, 0, 0, 0, 0, 0x547A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5474),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5474),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5560),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5563),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5584),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5582),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5583),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 gouki1_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 2, 0, 0, 0, 0, 0, 0x54B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 2, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 2, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F3),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54F2),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 gouki1_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54BE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54BF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x54C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 gouki1_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x549C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5537),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5538),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54FC),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 gouki1_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FC),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 gouki1_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x552B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5503),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F5),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 gouki1_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x552F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 gouki1_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BE),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 gouki1_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F8),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54F8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 gouki1_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x552B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5503),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x552F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x550A),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 gouki1_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 gouki1_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x552B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x552B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54EF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5503),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 gouki1_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EA),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 gouki1_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 gouki1_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x544D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 2, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5500),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 3, 0, 0, 0x5500),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 gouki1_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x544C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x544C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5712),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5712),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54EE),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E8),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 gouki1_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5479),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A7),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54B4),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 gouki1_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x56AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x550A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5715),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5543),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5536),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FB),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 1, 0, 0, 0x552C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 gouki1_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_053[116] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5506),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E9),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 gouki1_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5521),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5711),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5711),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5711),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5710),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5710),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 gouki1_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54AF),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x54E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 gouki1_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5490),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 10, 0x5506),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 gouki1_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BE),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 gouki1_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5502),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5715),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 gouki1_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5459),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5475),
    L2(250, 0, 0, 0, 0, 0, 0, 0x545A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x545F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5461),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5462),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5505),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 gouki1_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x549E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5492),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 gouki1_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5504),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5500),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5506),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 gouki1_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5494),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A6),
    CMD(CM_PA_X, 0, -8192, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54C4),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 120),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5506),
    CMD(CM_PA_X, 0, 1536, 0),
    CMD(CM_PS_Y, 0, 0, 86),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5507),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54EC),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54ED),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 gouki1_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BD),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 706, 0, 0, 0, 0, 0x54BE),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 gouki1_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54BB),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 gouki1_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5499),
    L2(250, 0, 0, 0, 0, 0, 0, 0x549A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x54A6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x54EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5501),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x552C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 gouki1_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 gouki1_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x54AF),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x54E3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 157 entries */
const u16* const gouki1_atca[158] = {
    gouki1_atca_000,  /* 0 S PUNCH A */
    gouki1_atca_001,  /* 1 S PUNCH B */
    gouki1_atca_001,  /* 2 S PUNCH C */
    gouki1_atca_003,  /* 3 M PUNCH A */
    gouki1_atca_004,  /* 4 M PUNCH B */
    gouki1_atca_005,  /* 5 M PUNCH C */
    gouki1_atca_006,  /* 6 L PUNCH A */
    gouki1_atca_007,  /* 7 L PUNCH B */
    gouki1_atca_007,  /* 8 L PUNCH C */
    gouki1_atca_009,  /* 9 S KICK A */
    gouki1_atca_009,  /* 10 S KICK B */
    gouki1_atca_009,  /* 11 S KICK C */
    gouki1_atca_012,  /* 12 M KICK A */
    gouki1_atca_013,  /* 13 M KICK B */
    gouki1_atca_013,  /* 14 M KICK C */
    gouki1_atca_015,  /* 15 L KICK A */
    gouki1_atca_016,  /* 16 L KICK B */
    gouki1_atca_016,  /* 17 L KICK C */
    gouki1_atca_018,  /* 18 KAGAMI P A */
    gouki1_atca_018,  /* 19 KAGAMI P B */
    gouki1_atca_018,  /* 20 KAGAMI P C */
    gouki1_atca_021,  /* 21 KAGAMI P A */
    gouki1_atca_021,  /* 22 KAGAMI P B */
    gouki1_atca_021,  /* 23 KAGAMI P C */
    gouki1_atca_024,  /* 24 KAGAMI P A */
    gouki1_atca_024,  /* 25 KAGAMI P B */
    gouki1_atca_024,  /* 26 KAGAMI P C */
    gouki1_atca_027,  /* 27 KAGAMI K A */
    gouki1_atca_027,  /* 28 KAGAMI K B */
    gouki1_atca_027,  /* 29 KAGAMI K C */
    gouki1_atca_030,  /* 30 KAGAMI K A */
    gouki1_atca_030,  /* 31 KAGAMI K B */
    gouki1_atca_030,  /* 32 KAGAMI K C */
    gouki1_atca_033,  /* 33 KAGAMI K A */
    gouki1_atca_033,  /* 34 KAGAMI K B */
    gouki1_atca_033,  /* 35 KAGAMI K C */
    gouki1_atca_036,  /* 36 V JUMP P S A */
    gouki1_atca_036,  /* 37 V JUMP P S B */
    gouki1_atca_038,  /* 38 V JUMP P M A */
    gouki1_atca_038,  /* 39 V JUMP P M B */
    gouki1_atca_040,  /* 40 V JUMP P L A */
    gouki1_atca_040,  /* 41 V JUMP P L B */
    gouki1_atca_042,  /* 42 V JUMP K S A */
    gouki1_atca_042,  /* 43 V JUMP K S B */
    gouki1_atca_044,  /* 44 V JUMP K M A */
    gouki1_atca_044,  /* 45 V JUMP K M B */
    gouki1_atca_046,  /* 46 V JUMP K L A */
    gouki1_atca_046,  /* 47 V JUMP K L B */
    gouki1_atca_048,  /* 48 F JUMP P S A */
    gouki1_atca_048,  /* 49 F JUMP P S B */
    gouki1_atca_050,  /* 50 F JUMP P M A */
    gouki1_atca_050,  /* 51 F JUMP P M B */
    gouki1_atca_052,  /* 52 F JUMP P L A */
    gouki1_atca_052,  /* 53 F JUMP P L B */
    gouki1_atca_054,  /* 54 F JUMP K S A */
    gouki1_atca_054,  /* 55 F JUMP K S B */
    gouki1_atca_056,  /* 56 F JUMP K M A */
    gouki1_atca_057,  /* 57 F JUMP K M B */
    gouki1_atca_058,  /* 58 F JUMP K L A */
    gouki1_atca_058,  /* 59 F JUMP K L B */
    gouki1_atca_060,  /* 60 B JUMP P S A */
    gouki1_atca_060,  /* 61 B JUMP P S B */
    gouki1_atca_062,  /* 62 B JUMP P M A */
    gouki1_atca_062,  /* 63 B JUMP P M B */
    gouki1_atca_064,  /* 64 B JUMP P L A */
    gouki1_atca_064,  /* 65 B JUMP P L B */
    gouki1_atca_066,  /* 66 B JUMP K S A */
    gouki1_atca_066,  /* 67 B JUMP K S B */
    gouki1_atca_068,  /* 68 B JUMP K M A */
    gouki1_atca_068,  /* 69 B JUMP K M B */
    gouki1_atca_070,  /* 70 B JUMP K L A */
    gouki1_atca_070,  /* 71 B JUMP K L B */
    gouki1_atca_072,  /* 72 SP V JP S P A */
    gouki1_atca_072,  /* 73 SP V JP S P B */
    gouki1_atca_074,  /* 74 SP V JP M P A */
    gouki1_atca_074,  /* 75 SP V JP M P B */
    gouki1_atca_076,  /* 76 SP V JP L P A */
    gouki1_atca_076,  /* 77 SP V JP L P B */
    gouki1_atca_078,  /* 78 SP V JP S K A */
    gouki1_atca_078,  /* 79 SP V JP S K B */
    gouki1_atca_080,  /* 80 SP V JP M K A */
    gouki1_atca_080,  /* 81 SP V JP M K B */
    gouki1_atca_082,  /* 82 SP V JP L K A */
    gouki1_atca_082,  /* 83 SP V JP L K B */
    gouki1_atca_084,  /* 84 SP F JP S P A */
    gouki1_atca_084,  /* 85 SP F JP S P B */
    gouki1_atca_086,  /* 86 SP F JP M P A */
    gouki1_atca_086,  /* 87 SP F JP M P B */
    gouki1_atca_088,  /* 88 SP F JP L P A */
    gouki1_atca_088,  /* 89 SP F JP L P B */
    gouki1_atca_090,  /* 90 SP F JP S K A */
    gouki1_atca_090,  /* 91 SP F JP S K B */
    gouki1_atca_092,  /* 92 SP F JP M K A */
    gouki1_atca_093,  /* 93 SP F JP M K B */
    gouki1_atca_094,  /* 94 SP F JP L K A */
    gouki1_atca_094,  /* 95 SP F JP L K B */
    gouki1_atca_096,  /* 96 SP B JP S P A */
    gouki1_atca_096,  /* 97 SP B JP S P B */
    gouki1_atca_098,  /* 98 SP B JP M P A */
    gouki1_atca_098,  /* 99 SP B JP M P B */
    gouki1_atca_100,  /* 100 SP B JP L P A */
    gouki1_atca_100,  /* 101 SP B JP L P B */
    gouki1_atca_102,  /* 102 SP B JP S K A */
    gouki1_atca_102,  /* 103 SP B JP S K B */
    gouki1_atca_104,  /* 104 SP B JP M K A */
    gouki1_atca_104,  /* 105 SP B JP M K B */
    gouki1_atca_106,  /* 106 SP B JP L K A */
    gouki1_atca_106,  /* 107 SP B JP L K B */
    gouki1_atca_108,  /* 108 S V JP S P A */
    gouki1_atca_108,  /* 109 S V JP S P B */
    gouki1_atca_110,  /* 110 S V JP M P A */
    gouki1_atca_110,  /* 111 S V JP M P B */
    gouki1_atca_112,  /* 112 S V JP L P A */
    gouki1_atca_112,  /* 113 S V JP L P B */
    gouki1_atca_114,  /* 114 S V JP S K A */
    gouki1_atca_114,  /* 115 S V JP S K B */
    gouki1_atca_116,  /* 116 S V JP M K A */
    gouki1_atca_116,  /* 117 S V JP M K B */
    gouki1_atca_118,  /* 118 S V JP L K A */
    gouki1_atca_118,  /* 119 S V JP L K B */
    gouki1_atca_108,  /* 120 S F JP S P A */
    gouki1_atca_108,  /* 121 S F JP S P B */
    gouki1_atca_110,  /* 122 S F JP M P A */
    gouki1_atca_110,  /* 123 S F JP M P B */
    gouki1_atca_112,  /* 124 S F JP L P A */
    gouki1_atca_112,  /* 125 S F JP L P B */
    gouki1_atca_114,  /* 126 S F JP S K A */
    gouki1_atca_114,  /* 127 S F JP S K B */
    gouki1_atca_116,  /* 128 S F JP M K A */
    gouki1_atca_116,  /* 129 S F JP M K B */
    gouki1_atca_118,  /* 130 S F JP L K A */
    gouki1_atca_118,  /* 131 S F JP L K B */
    gouki1_atca_108,  /* 132 S B JP S P A */
    gouki1_atca_108,  /* 133 S B JP S P B */
    gouki1_atca_110,  /* 134 S B JP M P A */
    gouki1_atca_110,  /* 135 S B JP M P B */
    gouki1_atca_112,  /* 136 S B JP L P A */
    gouki1_atca_112,  /* 137 S B JP L P B */
    gouki1_atca_114,  /* 138 S B JP S K A */
    gouki1_atca_114,  /* 139 S B JP S K B */
    gouki1_atca_116,  /* 140 S B JP M K A */
    gouki1_atca_116,  /* 141 S B JP M K B */
    gouki1_atca_118,  /* 142 S B JP L K A */
    gouki1_atca_118,  /* 143 S B JP L K B */
    gouki1_atca_144,  /* 144 TUKAMIKAKARI A */
    gouki1_atca_144,  /* 145 TUKAMIKAKARI B */
    gouki1_atca_146,  /* 146 TUKAMIKAKARI C */
    gouki1_atca_144,  /* 147 TUKAMIKAKARI D */
    gouki1_atca_144,  /* 148 TUKAMIKAKARI E */
    gouki1_atca_144,  /* 149 TUKAMIKAKARI F */
    gouki1_atca_144,  /* 150 TUKAMI AIR A */
    gouki1_atca_144,  /* 151 TUKAMI AIR B */
    gouki1_atca_144,  /* 152 TUKAMI AIR C */
    gouki1_atca_144,  /* 153 TUKAMI AIR D */
    gouki1_atca_144,  /* 154 TUKAMI AIR E */
    gouki1_atca_144,  /* 155 TUKAMI AIR F */
    gouki1_atca_156,  /* 156 follow-up of M PUNCH A */
    0
};

/* script: 0 S PUNCH A */
const u16 gouki1_atca_000_head[4] = { HEAD(4, 0, 0, 7, 0, 1, 0) };
const u16 gouki1_atca_000[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5580, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x5581, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5582, -3, 19, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5583, 0, 20, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5583, 0, 21, 272, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5584, 0, 1, 272, 0, 8, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5586, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5586, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 gouki1_atca_001_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 0) };
const u16 gouki1_atca_001[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5560, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5563, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5560, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x5561, -4, 22, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5562, 0, 22, 272, 0, 120, 0, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5562, 0, 23, 272, 0, 120, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5563, 0, 1, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5564, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5564, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 gouki1_atca_003_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 gouki1_atca_003[84] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5587, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5588, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5589, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x558A, -5, 24, 2245, 128, 104, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x558B, 0, 24, 2245, 0, 104, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x559B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x558C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5475, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5475, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B */
const u16 gouki1_atca_004_head[4] = { HEAD(4, 0, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_004[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5566, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5567, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5568, -6, 25, 0, 133, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5569, 0, 26, 0, 128, 96, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x557B, 0, 27, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x556A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x556B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 gouki1_atca_005_head[4] = { HEAD(4, 0, 2, 11, 0, 2, 1) };
const u16 gouki1_atca_005[116] = {
    L4(3, 0, 711, 0, 0, 0, 0, 0x5726, 0, 1, 0, 0, 0, 32, 77),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5727, 0, 90, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5728, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 708, 0, 0, 0, 0, 0x5729, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x572A, -50, 91, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x572B, -51, 92, 0, 136, 0, 32, 78),
    L4(2, 0, 0, 0, 0, 0, 0, 0x572C, 0, 93, 0, 136, 0, 32, 78),
    L4(3, 0, 0, 0, 0, 0, 0, 0x572B, 0, 93, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x572C, 0, 93, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x572C, 0, 93, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x572D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x572E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 gouki1_atca_006_head[4] = { HEAD(4, 0, 4, 10, 0, 1, 0) };
const u16 gouki1_atca_006[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x558D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x558E, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 711, 0, 0, 0, 0, 0x558F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5590, -7, 32, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5591, 0, 32, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5592, 8, 33, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5593, 0, 34, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5594, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5595, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5596, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5597, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5598, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5599, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5599, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 gouki1_atca_007_head[4] = { HEAD(4, 0, 4, 13, 0, 1, 0) };
const u16 gouki1_atca_007[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 30, 82),
    L4(2, 0, 0, 0, 0, 0, 0, 0x556D, 0, 76, 0, 0, 0, 32, 96),
    L4(3, 0, 0, 0, 0, 0, 0, 0x556E, 0, 76, 0, 0, 0, 32, 93),
    L4(2, 0, 270, 1, 0, 0, 0, 0x556F, 0, 76, 0, 0, 0, 32, 92),
    L4(1, 0, 709, 1, 0, 0, 0, 0x5570, -9, 77, 0, 128, 0, 32, 93),
    L4(2, 0, 0, 1, 0, 0, 0, 0x5571, 0, 77, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x5572, 0, 77, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x5571, 0, 78, 0, 0, 0, 21, 0),
    L4(8, 0, 0, 1, 0, 0, 0, 0x5572, 0, 78, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5573, 0, 78, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5574, 0, 1, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5575, 0, 1, 0, 0, 0, 32, 95),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 gouki1_atca_009_head[4] = { HEAD(4, 0, 1, 10, 0, 1, 0) };
const u16 gouki1_atca_009[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x55C0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x55C1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x55C2, -10, 37, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55C3, 0, 38, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55C4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 gouki1_atca_012_head[4] = { HEAD(4, 0, 3, 10, 0, 1, 0) };
const u16 gouki1_atca_012[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x55C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x55C8, 0, 191, 0, 0, 0, 32, 87),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55C9, 0, 192, 0, 0, 0, 32, 87),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55CA, -12, 193, 0, 128, 96, 32, 87),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55CB, 0, 194, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x55CC, 0, 195, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55CD, 0, 196, 0, 0, 0, 32, 88),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55C5, 0, 196, 0, 0, 0, 32, 88),
    L4(3, 64, 0, 0, 0, 0, 0, 0x55C6, 0, 1, 0, 0, 0, 32, 88),
    L4(250, 255, 0, 0, 0, 0, 0, 0x55C6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B, 14 M KICK C */
const u16 gouki1_atca_013_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_013[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x55A8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55A9, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x55A9, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55AA, -13, 43, 0, 128, 0, 32, 23),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55AB, 0, 44, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x55BD, 0, 45, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55AC, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x55AF, 0, 42, 0, 0, 0, 32, 24),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55AD, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55AE, 0, 1, 0, 0, 16, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A */
const u16 gouki1_atca_015_head[4] = { HEAD(4, 0, 5, 11, 6, 1, 0) };
const u16 gouki1_atca_015[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x57A7, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57A8, 0, 150, 0, 0, 0, 32, 106),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57A9, -14, 151, 0, 128, 0, 32, 107),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57AA, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57AB, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57AC, -15, 153, 0, 64, 0, 32, 108),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57AD, 16, 154, 0, 64, 0, 0, 0),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x57AE, 0, 155, 0, 0, 0, 32, 109),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57AF, 0, 155, 0, 0, 0, 32, 110),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57B0, 0, 155, 0, 0, 0, 32, 111),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57B1, 0, 1, 0, 0, 0, 32, 112),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57B2, 0, 1, 0, 0, 0, 32, 113),
    L4(250, 255, 0, 0, 0, 0, 0, 0x57B2, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 L KICK B, 17 L KICK C */
const u16 gouki1_atca_016_head[4] = { HEAD(4, 0, 5, 12, 6, 1, 0) };
const u16 gouki1_atca_016[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x55B0, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55B1, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 709, 0, 0, 0, 0, 0x55B2, 0, 46, 0, 0, 0, 32, 25),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55B3, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 270, 1, 0, 0, 0, 0x55B4, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 0, 1, 0, 0, 0, 0x55B5, 0, 48, 0, 0, 0, 32, 25),
    L4(2, 0, 0, 1, 0, 0, 0, 0x55B6, -17, 47, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x55B7, 0, 47, 0, 0, 0, 32, 27),
    CMD(CM_ASXY, 56, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x55B8, 0, 48, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55BE, 0, 48, 0, 0, 0, 32, 29),
    L4(4, 0, 0, 0, 0, 0, 0, 0x55B9, 0, 46, 0, 0, 0, 32, 30),
    L4(4, 0, 0, 0, 0, 0, 0, 0x55BA, 0, 1, 0, 0, 0, 32, 28),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55BB, 0, 1, 0, 0, 0, 32, 28),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55BC, 0, 1, 0, 0, 0, 32, 29),
    L4(2, 64, 0, 0, 0, 0, 0, 0x55BC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 gouki1_atca_018_head[4] = { HEAD(4, 32, 0, 10, 0, 1, 0) };
const u16 gouki1_atca_018[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x55F0, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x55F1, -19, 51, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F2, 0, 51, 272, 0, 120, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F4, 0, 52, 272, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F3, 0, 2, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 gouki1_atca_021_head[4] = { HEAD(4, 32, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_021[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x55F0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x55F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55F1, -20, 53, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55F2, 0, 51, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F2, 0, 52, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55F3, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x55F0, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 gouki1_atca_024_head[4] = { HEAD(4, 32, 4, 9, 0, 1, 0) };
const u16 gouki1_atca_024[108] = {
    L4(3, 0, 711, 0, 0, 0, 0, 0x55FC, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x55FD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55FE, -21, 54, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x55FF, 22, 55, 0, 128, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5600, 0, 56, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5600, 0, 57, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5601, 0, 57, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5602, 0, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5603, 0, 59, 0, 0, 0, 22, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5604, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 gouki1_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 gouki1_atca_027[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5611, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5611, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5612, -23, 60, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5613, 0, 60, 272, 0, 120, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5614, 0, 2, 272, 0, 24, 21, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5611, 0, 2, 272, 0, 24, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5610, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5610, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5615, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 gouki1_atca_030_head[4] = { HEAD(4, 32, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_030[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5616, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5624, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5617, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5618, -24, 61, 0, 135, 96, 32, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5619, 0, 62, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x561A, 0, 62, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x561A, 0, 63, 0, 0, 96, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x561B, 0, 2, 0, 0, 0, 32, 33),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5624, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5625, 0, 2, 0, 0, 0, 32, 34),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 32, 34),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 gouki1_atca_033_head[4] = { HEAD(4, 32, 5, 13, 0, 1, 0) };
const u16 gouki1_atca_033[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5616, 0, 2, 0, 0, 0, 32, 35),
    L4(2, 0, 709, 0, 0, 0, 0, 0x561C, 0, 2, 0, 0, 0, 32, 36),
    L4(2, 0, 270, 0, 0, 0, 0, 0x561D, 0, 2, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x561E, -25, 64, 0, 64, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x561F, 0, 64, 0, 64, 0, 0, 0),
    CMD(CM_ASXY, 74, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5620, 0, 65, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5621, 0, 65, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5622, 0, 2, 0, 0, 0, 32, 39),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5623, 0, 2, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5624, 0, 2, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5625, 0, 2, 0, 0, 0, 32, 42),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 32, 42),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 gouki1_atca_036_head[4] = { HEAD(4, 22, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_036[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5630, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5631, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5632, -26, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5633, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5634, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5635, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5633, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5634, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5635, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 gouki1_atca_038_head[4] = { HEAD(4, 22, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_038[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5642, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5643, -27, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5644, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5648, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5645, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5646, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5647, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 gouki1_atca_040_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 0) };
const u16 gouki1_atca_040[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x564E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x564F, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5650, -28, 104, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5651, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5653, 0, 106, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5654, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 gouki1_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_042[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5665, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x5660, -29, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5661, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5662, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5663, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5661, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5662, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5663, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5664, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x566C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 gouki1_atca_044_head[4] = { HEAD(4, 22, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_044[100] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 269, 0, 0, 0, 0, 0x566D, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x566E, -30, 109, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x566F, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5670, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5670, 0, 111, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5671, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5672, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 gouki1_atca_046_head[4] = { HEAD(4, 22, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_046[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5673, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x5674, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5675, -31, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5676, 0, 113, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5677, 0, 114, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5678, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5447, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 gouki1_atca_048_head[4] = { HEAD(4, 20, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_048[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5630, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5631, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5632, -32, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5633, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5634, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5635, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5633, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5634, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5635, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 gouki1_atca_050_head[4] = { HEAD(2, 20, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_050[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 gouki1_atca_052_head[4] = { HEAD(4, 20, 4, 11, 0, 1, 0) };
const u16 gouki1_atca_052[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x5642, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5643, -34, 98, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5644, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5648, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5645, 0, 73, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5646, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5647, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 gouki1_atca_054_head[4] = { HEAD(4, 20, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_054[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5665, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x5660, -35, 107, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5661, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5662, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5663, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5664, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x566C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A */
const u16 gouki1_atca_056_head[4] = { HEAD(4, 20, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_056[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5665, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5667, -36, 115, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5668, 0, 116, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5669, 0, 116, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x566A, 0, 117, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x566B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x566C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 F JUMP K M B */
const u16 gouki1_atca_057_head[4] = { HEAD(4, 20, 3, 9, 0, 1, 0) };
const u16 gouki1_atca_057[68] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(3, 20, 708, 0, 0, 0, 0, 0x5665, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 8, 0x5705, -11, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5706, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x5707, 0, 36, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 gouki1_atca_058_head[4] = { HEAD(4, 20, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_058[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5665, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x5666, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5667, -37, 118, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5668, 0, 119, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5669, 0, 119, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x566A, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x566B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x566C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 gouki1_atca_060_head[4] = { HEAD(2, 24, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 gouki1_atca_062_head[4] = { HEAD(2, 24, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_062[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 gouki1_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 gouki1_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 gouki1_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 gouki1_atca_068_head[4] = { HEAD(2, 24, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 gouki1_atca_070_head[4] = { HEAD(2, 24, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 gouki1_atca_072_head[4] = { HEAD(2, 28, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 gouki1_atca_074_head[4] = { HEAD(2, 28, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 gouki1_atca_076_head[4] = { HEAD(2, 28, 4, 12, 0, 1, 0) };
const u16 gouki1_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 gouki1_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 gouki1_atca_080_head[4] = { HEAD(2, 28, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 gouki1_atca_082_head[4] = { HEAD(2, 28, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 gouki1_atca_084_head[4] = { HEAD(2, 26, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 gouki1_atca_086_head[4] = { HEAD(2, 26, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_086[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 gouki1_atca_088_head[4] = { HEAD(2, 26, 4, 11, 0, 1, 0) };
const u16 gouki1_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 gouki1_atca_090_head[4] = { HEAD(2, 26, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A */
const u16 gouki1_atca_092_head[4] = { HEAD(2, 26, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 93 SP F JP M K B */
const u16 gouki1_atca_093_head[4] = { HEAD(2, 26, 3, 9, 0, 1, 0) };
const u16 gouki1_atca_093[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 gouki1_atca_094_head[4] = { HEAD(2, 26, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 gouki1_atca_096_head[4] = { HEAD(2, 30, 0, 8, 0, 1, 0) };
const u16 gouki1_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 gouki1_atca_098_head[4] = { HEAD(2, 30, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 gouki1_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 gouki1_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 gouki1_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 gouki1_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 gouki1_atca_104_head[4] = { HEAD(2, 30, 3, 12, 0, 1, 0) };
const u16 gouki1_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 gouki1_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 gouki1_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 gouki1_atca_108_head[4] = { HEAD(6, 16, 0, 10, 0, 1, 0) };
const u16 gouki1_atca_108[184] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5630, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x5631, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5632, -26, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5633, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5634, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5635, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5633, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5634, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5635, 0, 99, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5636, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5449, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0),
    L6(250, 2, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 gouki1_atca_110_head[4] = { HEAD(6, 16, 2, 11, 0, 1, 0) };
const u16 gouki1_atca_110[196] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(7, 0, 269, 0, 0, 0, 6, 0x5637, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 6, 0x5638, -52, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 6, 0x5639, -33, 113, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 6, 0x563A, 33, 113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x563F, 0, 101, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x563B, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x563F, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x563B, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x563C, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x563D, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x563E, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0),
    L6(250, 2, 0, 0, 0, 0, 0, 0x544B, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 gouki1_atca_112_head[4] = { HEAD(6, 16, 4, 0, 0, 1, 0) };
const u16 gouki1_atca_112[208] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x564E, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x564F, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x5650, -28, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5651, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5652, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5656, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5652, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5656, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5652, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x5656, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5653, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5654, 0, 15, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0),
    L6(250, 2, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 gouki1_atca_114_head[4] = { HEAD(6, 16, 1, 0, 0, 1, 0) };
const u16 gouki1_atca_114[196] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5665, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5666, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5660, -35, 108, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5661, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5662, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5663, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5661, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5662, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5663, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5664, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x566C, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 11, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 gouki1_atca_116_head[4] = { HEAD(6, 16, 3, 0, 0, 1, 0) };
const u16 gouki1_atca_116[184] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(7, 0, 269, 0, 0, 0, 0, 0x566D, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566E, -30, 161, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566F, 30, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5670, 30, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566F, 30, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5670, 30, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566F, 0, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5670, 0, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5671, 0, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5672, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 15, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0),
    L6(250, 2, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 gouki1_atca_118_head[4] = { HEAD(6, 16, 5, 0, 0, 1, 0) };
const u16 gouki1_atca_118[160] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5665, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x5666, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5667, -37, 145, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5668, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5669, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566A, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566B, 0, 11, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566C, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5456, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5457, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0),
    L6(250, 2, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 gouki1_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_atca_144[92] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x57A1, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x57A1, -48, 97, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x57A2, 0, 1, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x57A3, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x57A4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57A5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x57A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x57A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 gouki1_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of M PUNCH A */
const u16 gouki1_atca_156_head[4] = { HEAD(4, 0, 4, 14, 0, 1, 0) };
const u16 gouki1_atca_156[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x558B, 0, 76, 0, 0, 0, 30, 82),
    L4(3, 0, 0, 0, 0, 0, 0, 0x556E, 0, 76, 0, 0, 0, 32, 91),
    L4(2, 0, 0, 0, 0, 0, 0, 0x556E, 0, 76, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x556F, 0, 76, 0, 0, 0, 32, 92),
    L4(1, 0, 709, 0, 0, 0, 0, 0x5570, -8, 77, 0, 128, 0, 32, 93),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5571, 0, 77, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5572, 0, 77, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5571, 0, 78, 0, 0, 0, 21, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x5572, 0, 78, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5573, 0, 78, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5574, 0, 1, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5575, 0, 1, 0, 0, 0, 32, 95),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX gouki1_olc_ix_table[34] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
    { { 5, 8, 0, 0 } },
    { { 10, 0, 0, 0 } },
    { { 27, 0, 0, 0 } },
    { { 44, 0, 0, 0 } },
    { { 45, 0, 0, 0 } },
    { { 46, 0, 0, 0 } },
    { { 47, 0, 0, 0 } },
    { { 48, 0, 0, 0 } },
    { { 49, 0, 0, 0 } },
    { { 50, 0, 0, 0 } },
    { { 51, 0, 0, 0 } },
    { { 52, 0, 0, 0 } },
    { { 53, 0, 0, 0 } },
    { { 54, 0, 0, 0 } },
    { { 55, 0, 0, 0 } },
    { { 56, 0, 0, 0 } },
    { { 57, 0, 0, 0 } },
    { { 58, 0, 0, 0 } },
    { { 59, 0, 0, 0 } },
    { { 60, 0, 0, 0 } },
    { { 61, 0, 0, 0 } },
    { { 62, 0, 0, 0 } },
    { { 63, 0, 0, 0 } },
    { { 64, 0, 0, 0 } },
    { { 65, 0, 0, 0 } },
    { { 66, 0, 0, 0 } },
    { { 67, 0, 0, 0 } },
    { { 68, 0, 0, 0 } },
    { { 69, 0, 0, 0 } },
    { { 70, 71, 0, 0 } },
};

const OVERLAP_PARTS gouki1_overlap_char_tbl[115] = {
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 0, 0 },
    { 30, 70, 0, 0, 2, 0, 1, 1, 0, 0, 38769 },
    { 30, 70, 0, 0, 1, 0, 1, 1, 0, 1, 38769 },
    { 24, 66, 0, 0, 2, 0, 1, 1, 0, 0, 38769 },
    { 24, 66, 0, 0, 1, 0, 1, 1, 0, 3, 38769 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 0, 22388 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 0, 22389 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 5, 22390 },
    { 29, 101, 0, 0, 2, 0, 1, 1, 0, 0, 38769 },
    { 29, 101, 0, 0, 1, 0, 1, 1, 0, 8, 38769 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22328 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22329 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22330 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22331 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22332 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22333 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22334 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22335 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22336 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22337 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22338 },
    { 0, 0, 0, 0, 2, 0, 3, 1, 0, 0, 22339 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22340 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22341 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22342 },
    { 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 22343 },
    { 0, 0, 0, 0, 2, 0, 250, 1, 0, 26, 0 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22328 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22329 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22330 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22331 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22332 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22333 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22334 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22335 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22336 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22337 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22338 },
    { -4, 0, 0, 0, 2, 1, 3, 1, 0, 0, 22339 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22340 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22341 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22342 },
    { -4, 0, 0, 0, 2, 1, 2, 1, 0, 0, 22343 },
    { -4, 0, 0, 0, 2, 0, 250, 1, 0, 43, 0 },
    { -2, 0, 0, 0, 2, 0, 250, 0, 0, 44, 22265 },
    { 5, 0, 0, 0, 2, 1, 250, 0, 0, 45, 22265 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 46, 22592 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 47, 22593 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 48, 22594 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 49, 22595 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 50, 22596 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 51, 22597 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 52, 22598 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 53, 22599 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 54, 22600 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 55, 22601 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 56, 22602 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 57, 22603 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 58, 22604 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 59, 22605 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 60, 22606 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 61, 22607 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 62, 22608 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 63, 22609 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 64, 22610 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 65, 22611 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 66, 22612 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 67, 22613 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 68, 22614 },
    { 0, 0, 0, 7, 2, 0, 250, 1, 0, 69, 22615 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 72, 22616 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 73, 22638 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 74, 22617 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 75, 22639 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 76, 22618 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 77, 22640 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 78, 22619 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 79, 22641 },
    { 0, 0, 0, 7, 2, 0, 2, 1, 0, 80, 22620 },
    { 0, 0, 0, 7, 1, 0, 2, 1, 0, 81, 22642 },
    { 0, 0, 0, 7, 2, 0, 2, 1, 0, 82, 22621 },
    { 0, 0, 0, 7, 1, 0, 2, 1, 0, 83, 22643 },
    { 0, 0, 0, 7, 2, 0, 2, 1, 0, 84, 22622 },
    { 0, 0, 0, 7, 1, 0, 2, 1, 0, 85, 22644 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 86, 22623 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 87, 22645 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 88, 22624 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 89, 22646 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 90, 22625 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 91, 22647 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 92, 22626 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 93, 22648 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 94, 22627 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 95, 22649 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 96, 22628 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 97, 22650 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 98, 22629 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 99, 22651 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 100, 22630 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 101, 22652 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 102, 22631 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 103, 22653 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 104, 22632 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 105, 22654 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 106, 22633 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 107, 22655 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 108, 22634 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 109, 22656 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 110, 22635 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 111, 22657 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 112, 22636 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 113, 22658 },
    { 0, 0, 0, 7, 2, 0, 1, 1, 0, 114, 22637 },
    { 0, 0, 0, 7, 1, 0, 1, 1, 0, 114, 22659 },
    { 0, 0, 0, 7, 1, 0, 250, 1, 0, 114, 0 },
};

const CatchTable gouki1_rival_catch_tbl[768] = {
    { -93, 0, 1, 1, 1 },
    { -93, 0, 1, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -85, 0, 1, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -61, 0, 2, 1, 1 },
    { -85, 0, 2, 1, 1 },
    { -87, 0, 2, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -93, 0, 1, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -71, 0, 2, 1, 1 },
    { -62, 0, 2, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -74, 0, 2, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -77, 0, 2, 1, 2 },
    { -79, 0, 2, 1, 2 },
    { -97, 0, 1, 1, 2 },
    { -59, 0, 2, 1, 2 },
    { -44, 0, 2, 1, 2 },
    { -75, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -74, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -69, 0, 2, 1, 2 },
    { -73, 0, 2, 1, 2 },
    { -67, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 3 },
    { -50, 0, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -39, 3, 2, 1, 3 },
    { -26, 0, 2, 1, 3 },
    { -48, 0, 2, 1, 3 },
    { -47, 0, 2, 1, 3 },
    { -52, 1, 2, 1, 3 },
    { -58, 6, 2, 1, 3 },
    { -61, 0, 2, 1, 3 },
    { -39, 3, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -62, 0, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -25, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 22, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { -5, 3, 1, 1, 4 },
    { -20, 19, 1, 1, 4 },
    { 12, 0, 1, 1, 4 },
    { -24, 3, 1, 1, 4 },
    { -3, 9, 1, 1, 4 },
    { -13, 1, 1, 1, 4 },
    { -24, 0, 1, 1, 4 },
    { 26, 94, 1, 1, 4 },
    { -20, 19, 1, 1, 4 },
    { -5, 3, 1, 1, 4 },
    { -5, 3, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { -5, 3, 1, 1, 4 },
    { -5, 3, 1, 1, 4 },
    { -4, 0, 1, 1, 4 },
    { -15, 0, 1, 1, 4 },
    { 5, 0, 1, 1, 4 },
    { 3, 5, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 24, 0, 1, 1, 5 },
    { 16, 0, 1, 1, 5 },
    { 7, 8, 1, 1, 5 },
    { 2, 14, 1, 1, 5 },
    { -18, 0, 1, 1, 5 },
    { -6, 0, 1, 1, 5 },
    { 78, 0, 1, 1, 5 },
    { 19, 6, 1, 1, 5 },
    { 48, 7, 1, 1, 5 },
    { 0, 104, 1, 1, 5 },
    { 2, 14, 1, 1, 5 },
    { 7, 8, 1, 1, 5 },
    { 7, 8, 1, 1, 5 },
    { 24, 0, 1, 1, 5 },
    { 7, 8, 1, 1, 5 },
    { 7, 8, 1, 1, 5 },
    { 5, 0, 1, 1, 5 },
    { 27, 8, 1, 1, 5 },
    { 6, 0, 1, 1, 5 },
    { 24, 3, 1, 1, 5 },
    { 34, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 50, 0, 1, 1, 6 },
    { 44, 0, 1, 1, 6 },
    { 34, 0, 1, 1, 6 },
    { 37, 6, 1, 1, 6 },
    { 35, 0, 1, 1, 6 },
    { 54, 0, 1, 1, 6 },
    { 41, 13, 1, 1, 6 },
    { 28, 8, 1, 1, 6 },
    { 49, 0, 1, 1, 6 },
    { 16, 106, 1, 1, 6 },
    { 37, 6, 1, 1, 6 },
    { 34, 0, 1, 1, 6 },
    { 34, 0, 1, 1, 6 },
    { 50, 0, 1, 1, 6 },
    { 34, 0, 1, 1, 6 },
    { 34, 0, 1, 1, 6 },
    { 28, 0, 1, 1, 6 },
    { 46, 8, 1, 1, 6 },
    { 40, 0, 1, 1, 6 },
    { 48, 5, 1, 1, 6 },
    { 48, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 36, -10, 1, 1, 7 },
    { 75, 0, 1, 1, 7 },
    { 47, 5, 1, 1, 7 },
    { 34, 3, 1, 1, 7 },
    { 25, 0, 1, 1, 7 },
    { 50, 0, 1, 1, 7 },
    { 51, 10, 1, 1, 7 },
    { 37, 21, 1, 1, 7 },
    { 51, 7, 1, 1, 7 },
    { 77, 104, 1, 1, 7 },
    { 34, 3, 1, 1, 7 },
    { 47, 5, 1, 1, 7 },
    { 47, 5, 1, 1, 7 },
    { 36, -10, 1, 1, 7 },
    { 47, 5, 1, 1, 7 },
    { 47, 5, 1, 1, 7 },
    { 45, 5, 1, 1, 7 },
    { 52, 5, 1, 1, 7 },
    { 68, 0, 1, 1, 7 },
    { 47, 8, 1, 1, 7 },
    { 36, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -2, 174, 1, 1, 8 },
    { 21, 102, 1, 1, 8 },
    { 35, 94, 1, 1, 8 },
    { 47, 18, 1, 1, 8 },
    { 47, 110, 1, 1, 8 },
    { 41, 168, 1, 1, 8 },
    { 39, 20, 1, 1, 8 },
    { 29, 100, 1, 1, 8 },
    { 42, 96, 1, 1, 8 },
    { 32, 142, 1, 1, 8 },
    { 47, 18, 1, 1, 8 },
    { 35, 94, 1, 1, 8 },
    { 35, 94, 1, 1, 8 },
    { -2, 174, 1, 1, 8 },
    { 35, 94, 1, 1, 8 },
    { 35, 94, 1, 1, 8 },
    { 40, 11, 1, 1, 8 },
    { 48, 13, 1, 1, 8 },
    { 45, 3, 1, 1, 8 },
    { 52, 142, 1, 1, 8 },
    { 30, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -30, -2, 1, 1, 9 },
    { -19, 144, 1, 1, 9 },
    { -10, 140, 1, 1, 9 },
    { -10, 126, 1, 1, 9 },
    { -13, 124, 1, 1, 9 },
    { -31, 15, 1, 1, 9 },
    { 11, 49, 1, 1, 9 },
    { -20, 128, 1, 1, 9 },
    { -9, 120, 1, 1, 9 },
    { -51, 32, 1, 1, 9 },
    { -10, 126, 1, 1, 9 },
    { -10, 140, 1, 1, 9 },
    { -10, 140, 1, 1, 9 },
    { -30, -2, 1, 1, 9 },
    { -10, 140, 1, 1, 9 },
    { -10, 140, 1, 1, 9 },
    { -19, 123, 1, 1, 9 },
    { 13, 13, 1, 1, 9 },
    { -22, 148, 1, 1, 9 },
    { -32, -1, 1, 1, 9 },
    { -42, 36, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -48, -11, 1, 1, 10 },
    { -63, 18, 1, 1, 10 },
    { -41, 14, 1, 1, 10 },
    { -62, 15, 1, 1, 10 },
    { -43, 0, 1, 1, 10 },
    { -45, -4, 1, 1, 10 },
    { 0, 38, 1, 1, 10 },
    { -50, 34, 1, 1, 10 },
    { -14, 110, 1, 1, 10 },
    { -51, 0, 1, 1, 10 },
    { -62, 15, 1, 1, 10 },
    { -41, 14, 1, 1, 10 },
    { -41, 14, 1, 1, 10 },
    { -48, -11, 1, 1, 10 },
    { -41, 14, 1, 1, 10 },
    { -41, 14, 1, 1, 10 },
    { -32, 113, 1, 1, 10 },
    { -13, 7, 1, 1, 10 },
    { -18, 149, 1, 1, 10 },
    { -42, -24, 1, 1, 10 },
    { -62, 32, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -68, 36, 1, 0, 11 },
    { -96, 35, 1, 0, 11 },
    { -86, 32, 1, 0, 11 },
    { -79, 33, 1, 0, 11 },
    { -93, 32, 1, 0, 11 },
    { -83, 37, 1, 0, 11 },
    { -20, 8, 2, 0, 11 },
    { -76, 32, 1, 0, 11 },
    { -64, 20, 1, 0, 11 },
    { -93, 32, 1, 0, 11 },
    { -79, 33, 1, 0, 11 },
    { -86, 32, 1, 0, 11 },
    { -86, 32, 1, 0, 11 },
    { -68, 36, 1, 0, 11 },
    { -86, 32, 1, 0, 11 },
    { -86, 32, 1, 0, 11 },
    { -46, 6, 1, 0, 11 },
    { -36, 30, 1, 0, 11 },
    { -32, 13, 1, 0, 11 },
    { -66, 11, 1, 0, 11 },
    { -78, 22, 1, 0, 11 },
    { 0, 0, 1, 0, 11 },
    { 0, 0, 1, 0, 11 },
    { 0, 0, 1, 0, 11 },
    { -96, 0, 2, 1, 1 },
    { -97, 0, 1, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -71, 0, 2, 1, 1 },
    { -83, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -82, 0, 2, 1, 1 },
    { -49, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -77, 0, 1, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -90, 0, 1, 1, 2 },
    { -97, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -83, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -102, 0, 1, 1, 2 },
    { -63, 0, 2, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -90, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 2 },
    { -66, 0, 1, 1, 2 },
    { -82, 0, 1, 1, 2 },
    { -82, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -60, 0, 1, 1, 3 },
    { -33, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -45, 0, 2, 1, 3 },
    { -55, 1, 1, 1, 3 },
    { -71, 0, 1, 1, 3 },
    { -77, 0, 1, 1, 3 },
    { -46, 1, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -60, 2, 2, 1, 3 },
    { -45, 0, 2, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { -50, 0, 2, 1, 3 },
    { -35, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 4 },
    { -48, 4, 1, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -78, 92, 2, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -47, 2, 1, 1, 4 },
    { -63, -5, 1, 1, 4 },
    { -35, 5, 1, 1, 4 },
    { -34, 0, 1, 1, 4 },
    { -41, 104, 2, 1, 4 },
    { -78, 92, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -32, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -49, 5, 1, 1, 4 },
    { -41, 7, 2, 1, 4 },
    { -37, 0, 2, 1, 4 },
    { -45, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -28, -14, 2, 1, 5 },
    { -58, 5, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -73, 94, 2, 1, 5 },
    { -35, 0, 1, 1, 5 },
    { -47, 0, 1, 1, 5 },
    { -38, 7, 1, 1, 5 },
    { -41, 6, 1, 1, 5 },
    { -36, 0, 1, 1, 5 },
    { -60, 104, 1, 1, 5 },
    { -73, 94, 2, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -28, -14, 2, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -27, 8, 1, 1, 5 },
    { -35, 7, 1, 1, 5 },
    { -55, 0, 1, 1, 5 },
    { -45, 0, 1, 1, 5 },
    { -36, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 16, 34, 2, 1, 6 },
    { 22, 134, 2, 1, 6 },
    { 24, 70, 2, 1, 6 },
    { 11, 68, 2, 1, 6 },
    { 17, 144, 2, 1, 6 },
    { 15, 68, 2, 1, 6 },
    { 7, 15, 2, 1, 6 },
    { 4, 134, 2, 1, 6 },
    { 6, 26, 2, 1, 6 },
    { -20, 44, 2, 1, 6 },
    { 11, 68, 2, 1, 6 },
    { 24, 70, 2, 1, 6 },
    { 24, 70, 2, 1, 6 },
    { 9, 146, 2, 1, 6 },
    { 24, 70, 2, 1, 6 },
    { 24, 70, 2, 1, 6 },
    { 13, 71, 2, 1, 6 },
    { 24, 61, 1, 1, 6 },
    { 36, 79, 2, 1, 6 },
    { 7, 1, 2, 1, 6 },
    { 14, 4, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 56, 13, 2, 1, 7 },
    { 66, 38, 1, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 24, 116, 1, 1, 7 },
    { 57, 152, 2, 1, 7 },
    { 54, 24, 1, 1, 7 },
    { 44, 51, 2, 1, 7 },
    { 44, 108, 1, 1, 7 },
    { 53, 90, 1, 1, 7 },
    { 65, 124, 1, 1, 7 },
    { 24, 116, 1, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 56, 13, 2, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 51, 123, 1, 1, 7 },
    { 52, -5, 1, 1, 7 },
    { 50, -4, 1, 1, 7 },
    { 52, 9, 1, 1, 7 },
    { 64, 122, 1, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 92, 24, 2, 1, 8 },
    { 92, 52, 1, 1, 8 },
    { 85, 52, 2, 1, 8 },
    { 86, 58, 1, 1, 8 },
    { 94, 50, 2, 1, 8 },
    { 118, 98, 2, 1, 8 },
    { 72, 12, 2, 1, 8 },
    { 72, 44, 1, 1, 8 },
    { 69, 62, 1, 1, 8 },
    { 91, 122, 1, 1, 8 },
    { 86, 58, 1, 1, 8 },
    { 85, 52, 2, 1, 8 },
    { 85, 52, 2, 1, 8 },
    { 92, 24, 2, 1, 8 },
    { 85, 52, 2, 1, 8 },
    { 85, 52, 2, 1, 8 },
    { 81, 44, 2, 1, 8 },
    { 83, 68, 1, 1, 8 },
    { 81, 18, 1, 1, 8 },
    { 81, 13, 1, 1, 8 },
    { 110, 4, 1, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -47, 0, 2, 1, 1 },
    { -8, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -26, 0, 2, 1, 1 },
    { -34, 0, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 1 },
    { -35, 0, 2, 1, 1 },
    { -32, 0, 2, 1, 1 },
    { -31, 0, 2, 1, 1 },
    { -26, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -47, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -31, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -27, -50, 1, 1, 2 },
    { -34, -39, 1, 1, 2 },
    { -18, -31, 1, 1, 2 },
    { -16, -17, 1, 1, 2 },
    { -21, -40, 1, 1, 2 },
    { -30, -32, 1, 1, 2 },
    { -23, -49, 1, 1, 2 },
    { -35, -25, 1, 1, 2 },
    { -32, -25, 1, 1, 2 },
    { -38, -9, 1, 1, 2 },
    { -16, -17, 1, 1, 2 },
    { -18, -31, 1, 1, 2 },
    { -18, -31, 1, 1, 2 },
    { -27, -50, 1, 1, 2 },
    { -18, -31, 1, 1, 2 },
    { -18, -31, 1, 1, 2 },
    { -28, -26, 1, 1, 2 },
    { -28, -23, 1, 1, 2 },
    { -27, -57, 1, 1, 2 },
    { -29, -26, 1, 1, 2 },
    { -30, -36, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -1, -65, 1, 1, 3 },
    { -19, -44, 1, 1, 3 },
    { -2, -37, 1, 1, 3 },
    { -7, -22, 1, 1, 3 },
    { -11, -39, 1, 1, 3 },
    { -19, -32, 1, 1, 3 },
    { -11, -49, 1, 1, 3 },
    { -24, -25, 1, 1, 3 },
    { -18, -29, 1, 1, 3 },
    { -31, -9, 1, 1, 3 },
    { -7, -22, 1, 1, 3 },
    { -2, -37, 1, 1, 3 },
    { -2, -37, 1, 1, 3 },
    { -1, -65, 1, 1, 3 },
    { -2, -37, 1, 1, 3 },
    { -2, -37, 1, 1, 3 },
    { -14, -26, 1, 1, 3 },
    { -14, -15, 1, 1, 3 },
    { -12, -38, 1, 1, 3 },
    { -20, -9, 1, 1, 3 },
    { -29, -28, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 14, -66, 1, 1, 4 },
    { 9, -43, 1, 1, 4 },
    { 8, -40, 1, 1, 4 },
    { 8, -26, 1, 1, 4 },
    { 2, -39, 1, 1, 4 },
    { -2, -31, 1, 1, 4 },
    { 5, -48, 1, 1, 4 },
    { -10, -25, 1, 1, 4 },
    { 6, -28, 1, 1, 4 },
    { -11, -9, 1, 1, 4 },
    { 8, -26, 1, 1, 4 },
    { 8, -40, 1, 1, 4 },
    { 8, -40, 1, 1, 4 },
    { 14, -66, 1, 1, 4 },
    { 8, -40, 1, 1, 4 },
    { 8, -40, 1, 1, 4 },
    { 6, -24, 1, 1, 4 },
    { 3, -15, 1, 1, 4 },
    { 4, -34, 1, 1, 4 },
    { -1, -15, 1, 1, 4 },
    { -9, -26, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 26, -64, 1, 1, 5 },
    { 22, -40, 1, 1, 5 },
    { 28, -39, 1, 1, 5 },
    { 18, -27, 1, 1, 5 },
    { 21, -39, 1, 1, 5 },
    { 12, -31, 1, 1, 5 },
    { 19, -48, 1, 1, 5 },
    { 8, -25, 1, 1, 5 },
    { 21, -26, 1, 1, 5 },
    { 2, -9, 1, 1, 5 },
    { 18, -27, 1, 1, 5 },
    { 28, -39, 1, 1, 5 },
    { 28, -39, 1, 1, 5 },
    { 26, -64, 1, 1, 5 },
    { 28, -39, 1, 1, 5 },
    { 28, -39, 1, 1, 5 },
    { 20, -23, 1, 1, 5 },
    { 16, -15, 1, 1, 5 },
    { 20, -42, 1, 1, 5 },
    { 14, -21, 1, 1, 5 },
    { 3, -27, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 45, -60, 1, 1, 6 },
    { 27, -41, 1, 1, 6 },
    { 65, -40, 1, 1, 6 },
    { 39, -27, 1, 1, 6 },
    { 36, -39, 1, 1, 6 },
    { 26, -30, 1, 1, 6 },
    { 27, -48, 1, 1, 6 },
    { 27, -25, 1, 1, 6 },
    { 34, -35, 1, 1, 6 },
    { 19, -6, 1, 1, 6 },
    { 39, -27, 1, 1, 6 },
    { 65, -40, 1, 1, 6 },
    { 65, -40, 1, 1, 6 },
    { 45, -60, 1, 1, 6 },
    { 65, -40, 1, 1, 6 },
    { 65, -40, 1, 1, 6 },
    { 35, -21, 1, 1, 6 },
    { 36, -12, 1, 1, 6 },
    { 40, -53, 1, 1, 6 },
    { 31, -28, 1, 1, 6 },
    { 19, -23, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 66, -44, 1, 1, 7 },
    { 49, -28, 1, 1, 7 },
    { 72, -20, 1, 1, 7 },
    { 63, -14, 1, 1, 7 },
    { 73, -27, 1, 1, 7 },
    { 28, -26, 1, 1, 7 },
    { 39, -36, 1, 1, 7 },
    { 34, -13, 1, 1, 7 },
    { 77, -19, 1, 1, 7 },
    { 29, 2, 1, 1, 7 },
    { 63, -14, 1, 1, 7 },
    { 72, -20, 1, 1, 7 },
    { 72, -20, 1, 1, 7 },
    { 66, -44, 1, 1, 7 },
    { 72, -20, 1, 1, 7 },
    { 72, -20, 1, 1, 7 },
    { 38, -10, 1, 1, 7 },
    { 42, 1, 1, 1, 7 },
    { 78, -27, 1, 1, 7 },
    { 44, -13, 1, 1, 7 },
    { 25, -16, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 81, -32, 1, 1, 8 },
    { 42, -12, 1, 1, 8 },
    { 69, -5, 1, 1, 8 },
    { 74, 5, 1, 1, 8 },
    { 77, -12, 1, 1, 8 },
    { 47, -13, 1, 1, 8 },
    { 43, -24, 1, 1, 8 },
    { 59, -2, 1, 1, 8 },
    { 80, 0, 1, 1, 8 },
    { 62, 0, 1, 1, 8 },
    { 74, 5, 1, 1, 8 },
    { 69, -5, 1, 1, 8 },
    { 69, -5, 1, 1, 8 },
    { 81, -32, 1, 1, 8 },
    { 69, -5, 1, 1, 8 },
    { 69, -5, 1, 1, 8 },
    { 53, -2, 1, 1, 8 },
    { 54, 2, 1, 1, 8 },
    { 84, -6, 1, 1, 8 },
    { 71, -9, 1, 1, 8 },
    { 34, -4, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 57, -9, 1, 1, 9 },
    { 75, -6, 1, 1, 9 },
    { 70, 0, 1, 1, 9 },
    { 65, 3, 1, 1, 9 },
    { 64, 0, 1, 1, 9 },
    { 61, 0, 1, 1, 9 },
    { 80, 0, 1, 1, 9 },
    { 55, 4, 1, 1, 9 },
    { 67, 18, 1, 1, 9 },
    { 63, 4, 1, 1, 9 },
    { 65, 3, 1, 1, 9 },
    { 70, 0, 1, 1, 9 },
    { 70, 0, 1, 1, 9 },
    { 57, -9, 1, 1, 9 },
    { 70, 0, 1, 1, 9 },
    { 70, 0, 1, 1, 9 },
    { 67, 6, 1, 1, 9 },
    { 60, 11, 1, 1, 9 },
    { 75, 0, 1, 1, 9 },
    { 82, 0, 1, 1, 9 },
    { 63, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 65, 8, 1, 1, 10 },
    { 70, 28, 1, 1, 10 },
    { 62, 17, 1, 1, 10 },
    { 61, 16, 1, 1, 10 },
    { 65, 13, 1, 1, 10 },
    { 57, 24, 1, 1, 10 },
    { 63, 0, 1, 1, 10 },
    { 55, 20, 1, 1, 10 },
    { 60, 45, 1, 1, 10 },
    { 56, 23, 1, 1, 10 },
    { 61, 16, 1, 1, 10 },
    { 62, 17, 1, 1, 10 },
    { 62, 17, 1, 1, 10 },
    { 65, 8, 1, 1, 10 },
    { 62, 17, 1, 1, 10 },
    { 62, 17, 1, 1, 10 },
    { 49, 18, 1, 1, 10 },
    { 54, 31, 1, 1, 10 },
    { 44, 21, 1, 1, 10 },
    { 74, 19, 1, 1, 10 },
    { 58, 14, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -88, 22, 1, 1, 11 },
    { -72, 37, 1, 1, 11 },
    { -82, 42, 1, 1, 11 },
    { -65, 48, 1, 1, 11 },
    { -70, 25, 1, 1, 11 },
    { -68, 34, 1, 1, 11 },
    { -67, 56, 1, 1, 11 },
    { -50, 22, 1, 1, 11 },
    { -71, 70, 1, 1, 11 },
    { -73, 38, 1, 1, 11 },
    { -65, 48, 1, 1, 11 },
    { -82, 42, 1, 1, 11 },
    { -82, 42, 1, 1, 11 },
    { -88, 22, 1, 1, 11 },
    { -82, 42, 1, 1, 11 },
    { -82, 42, 1, 1, 11 },
    { -72, 53, 1, 1, 11 },
    { -99, 54, 1, 1, 11 },
    { -119, 55, 1, 1, 11 },
    { -85, 32, 1, 1, 11 },
    { -72, 37, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
};

/* extra scripts: 70 entries */
const u16* const gouki1_exca[71] = {
    gouki1_exca_000,  /* 0 follow-up of AIR NORMAL */
    gouki1_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    gouki1_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    gouki1_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    gouki1_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    gouki1_exca_005,  /* 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
    gouki1_exca_006,  /* 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
    gouki1_exca_007,  /* 7 no name */
    gouki1_exca_008,  /* 8 follow-up of KUNOJI, IBUKI +2 */
    gouki1_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +2 */
    gouki1_exca_010,  /* 10 follow-up of KIRIMOMI, SPLASH.M +1 */
    gouki1_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    gouki1_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    gouki1_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    gouki1_exca_014,  /* 14 no name */
    gouki1_exca_015,  /* 15 no name */
    gouki1_exca_016,  /* 16 no name */
    gouki1_exca_017,  /* 17 follow-up of APPEAR JUNBI 1 */
    gouki1_exca_018,  /* 18 no name */
    gouki1_exca_019,  /* 19 no name */
    gouki1_exca_020,  /* 20 no name */
    gouki1_exca_021,  /* 21 no name */
    gouki1_exca_022,  /* 22 no name */
    gouki1_exca_023,  /* 23 follow-up of HARAIGOSHI */
    gouki1_exca_024,  /* 24 follow-up of ATTACK 4 S */
    gouki1_exca_025,  /* 25 follow-up of APPEAR JUNBI 7 */
    gouki1_exca_026,  /* 26 follow-up of APPEAR JUNBI 7 */
    gouki1_exca_027,  /* 27 follow-up of APPEAR JUNBI 8 */
    gouki1_exca_028,  /* 28 follow-up of APPEAR JUNBI 8 */
    gouki1_exca_029,  /* 29 no name */
    gouki1_exca_030,  /* 30 follow-up of APPEAR 1 */
    gouki1_exca_030,  /* 31 follow-up of APPEAR 1 */
    gouki1_exca_032,  /* 32 no name */
    gouki1_exca_033,  /* 33 follow-up of APPEAR 5 */
    gouki1_exca_034,  /* 34 follow-up of APPEAR 5 */
    gouki1_exca_035,  /* 35 follow-up of SP APPEAR 2, SP APPEAR 4 */
    gouki1_exca_036,  /* 36 no name */
    gouki1_exca_037,  /* 37 follow-up of WIN 6 */
    gouki1_exca_038,  /* 38 follow-up of WIN 6 */
    gouki1_exca_039,  /* 39 follow-up of WIN 7 */
    gouki1_exca_040,  /* 40 follow-up of WIN 7 */
    gouki1_exca_041,  /* 41 follow-up of GILL IMPACT C */
    gouki1_exca_042,  /* 42 follow-up of GILL IMPACT C */
    gouki1_exca_043,  /* 43 follow-up of WIN 8 */
    gouki1_exca_044,  /* 44 follow-up of WIN 8 */
    gouki1_exca_045,  /* 45 follow-up of SP WIN 1 */
    gouki1_exca_046,  /* 46 follow-up of SP WIN 1 */
    gouki1_exca_047,  /* 47 follow-up of SP WIN 2 */
    gouki1_exca_048,  /* 48 follow-up of SP WIN 2 */
    gouki1_exca_049,  /* 49 follow-up of SP WIN 3 */
    gouki1_exca_050,  /* 50 follow-up of SP WIN 3 */
    gouki1_exca_049,  /* 51 follow-up of SP WIN 4 */
    gouki1_exca_050,  /* 52 follow-up of SP WIN 4 */
    gouki1_exca_053,  /* 53 follow-up of SP WIN 5 */
    gouki1_exca_054,  /* 54 follow-up of SP WIN 5 */
    gouki1_exca_055,  /* 55 follow-up of APPEAR 7 */
    gouki1_exca_056,  /* 56 follow-up of APPEAR 7 */
    gouki1_exca_055,  /* 57 follow-up of APPEAR 8 */
    gouki1_exca_056,  /* 58 follow-up of APPEAR 8 */
    gouki1_exca_055,  /* 59 follow-up of SP APPEAR 1 */
    gouki1_exca_056,  /* 60 follow-up of SP APPEAR 1 */
    gouki1_exca_061,  /* 61 follow-up of ATTACK 4 S */
    gouki1_exca_062,  /* 62 follow-up of ATTACK 11 S */
    gouki1_exca_063,  /* 63 follow-up of SP APPEAR 3 */
    gouki1_exca_064,  /* 64 follow-up of SP APPEAR 3 */
    gouki1_exca_065,  /* 65 follow-up of SP APPEAR 6 */
    gouki1_exca_066,  /* 66 follow-up of SP APPEAR 6 */
    gouki1_exca_067,  /* 67 follow-up of SP APPEAR 7 */
    gouki1_exca_068,  /* 68 follow-up of SP APPEAR 7 */
    gouki1_exca_069,  /* 69 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 gouki1_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_000[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5452, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5451, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5450, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x544F, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544E, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544D, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x544D, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x544C, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5458, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 gouki1_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_001[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 gouki1_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_003[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x54FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 gouki1_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_004[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
const u16 gouki1_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_005[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x54E8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54E9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
const u16 gouki1_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_006[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 no name */
const u16 gouki1_exca_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_007[124] = {
    CMD(CM_PA_X, 0, 10240, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x54EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, IBUKI +2 */
const u16 gouki1_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_008[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5500, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5501, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5502, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5503, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +2 */
const u16 gouki1_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_009[124] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x5500, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5501, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5502, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5503, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, SPLASH.M +1 */
const u16 gouki1_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_010[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x54FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 gouki1_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_011[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 gouki1_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_013[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 gouki1_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FA, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 gouki1_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_015[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 gouki1_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x5502, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x5501, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x54FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of APPEAR JUNBI 1 */
const u16 gouki1_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_017[108] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 30, 273, 0, 0, 0, 0, 0x56C9, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56CA, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 gouki1_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 18, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 gouki1_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x5502, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x5501, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x54FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x54E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x54E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 gouki1_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_020[84] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x54E0, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x5525, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x5527, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x5528, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x5529, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x552A, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x552C, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54FA, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FA, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 gouki1_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x5506, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x5500, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x54FF, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x5713, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x54FB, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54FB, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 gouki1_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_022[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x54E8, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x54E8, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI */
const u16 gouki1_exca_023_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_023[148] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x54E8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x54E9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x54EA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x54EB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x54EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x54ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x54EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x54F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x54F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x54F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x54F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of ATTACK 4 S */
const u16 gouki1_exca_024_head[4] = { HEAD(6, 0, 32, 10, 0, 0, 4) };
const u16 gouki1_exca_024[172] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 0, 21, 0, 0, 0, 94, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x56A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x56AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR JUNBI 7 */
const u16 gouki1_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_025[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55E7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR JUNBI 7 */
const u16 gouki1_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_026[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5428, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR JUNBI 8 */
const u16 gouki1_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_027[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 25, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR JUNBI 8 */
const u16 gouki1_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_028[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5428, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 26, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 gouki1_exca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_029[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x54EC, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54ED, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1, 31 follow-up of APPEAR 1 */
const u16 gouki1_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_030[52] = {
    L4(4, 64, 0, 0, 0, 0, 0, 0x5484, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5485, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5486, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5487, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 no name */
const u16 gouki1_exca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_032[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x54E3, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54E4, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E5, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x54E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x54E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR 5 */
const u16 gouki1_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_033[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5484, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5485, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5486, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5487, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 5 */
const u16 gouki1_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_034[44] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 2, SP APPEAR 4 */
const u16 gouki1_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_035[108] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 30, 273, 0, 0, 0, 0, 0x56C9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56CA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 gouki1_exca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_036[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5401),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of WIN 6 */
const u16 gouki1_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_037[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of WIN 6 */
const u16 gouki1_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_038[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of WIN 7 */
const u16 gouki1_exca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_039[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of WIN 7 */
const u16 gouki1_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_040[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of GILL IMPACT C */
const u16 gouki1_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_041[64] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x54FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 gouki1_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_042[56] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x54FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x54F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x54F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x54F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x54F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x54EE, 0, 12, 0, 0, 0, 0, 0),
};

/* script: 43 follow-up of WIN 8 */
const u16 gouki1_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_043[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x55E6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55E7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of WIN 8 */
const u16 gouki1_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_044[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 273, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5428, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP WIN 1 */
const u16 gouki1_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_045[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 1 */
const u16 gouki1_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_046[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of SP WIN 2 */
const u16 gouki1_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_047[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of SP WIN 2 */
const u16 gouki1_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_048[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SP WIN 3, 51 follow-up of SP WIN 4 */
const u16 gouki1_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_049[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x5483, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x5484, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5485, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5486, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5487, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of SP WIN 3, 52 follow-up of SP WIN 4 */
const u16 gouki1_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_050[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5483, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5488, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of SP WIN 5 */
const u16 gouki1_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_053[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x548C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5484, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5485, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5486, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5487, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x540D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of SP WIN 5 */
const u16 gouki1_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_054[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5483, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5488, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of APPEAR 7, 57 follow-up of APPEAR 8, 59 follow-up of SP APPEAR 1 */
const u16 gouki1_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_055[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of APPEAR 7, 58 follow-up of APPEAR 8, 60 follow-up of SP APPEAR 1 */
const u16 gouki1_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_056[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of ATTACK 4 S */
const u16 gouki1_exca_061_head[4] = { HEAD(4, 0, 32, 10, 0, 0, 4) };
const u16 gouki1_exca_061[220] = {
    CMD(CM_RLJMP, 0, 8192, 16398), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 5, 0, 0x5730, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5731, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5732, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5733, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5734, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5735, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5736, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5737, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 5, 0, 0x5730, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 5, 0, 0x5731, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 6, 0, 0x5730, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5731, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5732, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5733, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5734, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5735, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5736, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5737, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 6, 0, 0x5730, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 6, 0, 0x5731, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of ATTACK 11 S */
const u16 gouki1_exca_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_062[236] = {
    CMD(CM_RLJMP, 0, 8192, 16400), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 5, 0, 0x5730, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5734, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5735, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5736, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5737, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5730, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x5734, 0, 29, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 6, 0, 0x5730, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5734, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5735, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5736, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5737, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5730, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 6, 0, 0x5734, 0, 29, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of SP APPEAR 3 */
const u16 gouki1_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_063[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of SP APPEAR 3 */
const u16 gouki1_exca_064_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_064[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 follow-up of SP APPEAR 6 */
const u16 gouki1_exca_065_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_065[68] = {
    CMD(CM_PA_X, 0, 6144, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_PA_X, 0, 512, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 follow-up of SP APPEAR 6 */
const u16 gouki1_exca_066_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_066[76] = {
    CMD(CM_PA_X, 0, 6144, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 21, 0),
    CMD(CM_PA_X, 0, 512, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 follow-up of SP APPEAR 7 */
const u16 gouki1_exca_067_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_067[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5429, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x542A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x544B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x542E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 follow-up of SP APPEAR 7 */
const u16 gouki1_exca_068_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_068[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x542A, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x542B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x542C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 no name */
const u16 gouki1_exca_069_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gouki1_exca_069[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5452, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5451, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5450, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x544F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x544D, 0, 261, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x544C, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5458, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 88 entries */
const u16* const gouki1_saca[89] = {
    gouki1_saca_000,  /* 0 UP P GUARD P S */
    gouki1_saca_001,  /* 1 UP P GUARD P M */
    gouki1_saca_002,  /* 2 UP P GUARD P L */
    gouki1_saca_002,  /* 3 UP P GUARD K S */
    gouki1_saca_002,  /* 4 UP P GUARD K M */
    gouki1_saca_002,  /* 5 UP P GUARD K L */
    gouki1_saca_000,  /* 6 D P GUARD P S */
    gouki1_saca_001,  /* 7 D P GUARD P M */
    gouki1_saca_002,  /* 8 D P GUARD P L */
    gouki1_saca_002,  /* 9 D P GUARD K S */
    gouki1_saca_002,  /* 10 D P GUARD K M */
    gouki1_saca_002,  /* 11 D P GUARD K L */
    gouki1_saca_002,  /* 12 FUSHIN P S */
    gouki1_saca_002,  /* 13 FUSHIN P M */
    gouki1_saca_002,  /* 14 FUSHIN P L */
    gouki1_saca_002,  /* 15 FUSHIN K S */
    gouki1_saca_002,  /* 16 FUSHIN K M */
    gouki1_saca_002,  /* 17 FUSHIN K L */
    gouki1_saca_002,  /* 18 OKIAGARI P S */
    gouki1_saca_002,  /* 19 OKIAGARI P M */
    gouki1_saca_002,  /* 20 OKIAGARI P L */
    gouki1_saca_002,  /* 21 OKIAGARI K S */
    gouki1_saca_002,  /* 22 OKIAGARI K M */
    gouki1_saca_002,  /* 23 OKIAGARI K L */
    gouki1_saca_024,  /* 24 ATTACK 1 S: 236+P light (plain script) */
    gouki1_saca_025,  /* 25 ATTACK 1 M: 236+P medium (plain script) */
    gouki1_saca_026,  /* 26 ATTACK 1 L: 236+P heavy/EX (plain script) */
    gouki1_saca_026,  /* 27 ATTACK 1 SP: 236+P heavy/EX (plain script) */
    gouki1_saca_028,  /* 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    gouki1_saca_029,  /* 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    gouki1_saca_030,  /* 30 ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    gouki1_saca_030,  /* 31 ATTACK 2 SP: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    gouki1_saca_032,  /* 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    gouki1_saca_033,  /* 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    gouki1_saca_034,  /* 34 ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    gouki1_saca_034,  /* 35 ATTACK 3 SP: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    gouki1_saca_036,  /* 36 ATTACK 4 S: SA I 23623+P (plain script) */
    gouki1_saca_036,  /* 37 ATTACK 4 M: SA I 23623+P (plain script) */
    gouki1_saca_036,  /* 38 ATTACK 4 L: SA I 23623+P (plain script) */
    gouki1_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+P (plain script) */
    gouki1_saca_040,  /* 40 ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    gouki1_saca_040,  /* 41 ATTACK 5 M: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    gouki1_saca_040,  /* 42 ATTACK 5 L: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    gouki1_saca_040,  /* 43 ATTACK 5 SP: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    gouki1_saca_044,  /* 44 ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN) */
    gouki1_saca_044,  /* 45 ATTACK 6 M: SA III 23623+K (routine Att_SHOURYUUKEN) */
    gouki1_saca_044,  /* 46 ATTACK 6 L: SA III 23623+K (routine Att_SHOURYUUKEN) */
    gouki1_saca_044,  /* 47 ATTACK 6 SP: SA III 23623+K (routine Att_SHOURYUUKEN) */
    gouki1_saca_048,  /* 48 ATTACK 7 S: SA I air 23623+P (routine Att_PL14_AT2) */
    gouki1_saca_048,  /* 49 ATTACK 7 M: SA I air 23623+P (routine Att_PL14_AT2) */
    gouki1_saca_048,  /* 50 ATTACK 7 L: SA I air 23623+P (routine Att_PL14_AT2) */
    gouki1_saca_048,  /* 51 ATTACK 7 SP: SA I air 23623+P (routine Att_PL14_AT2) */
    gouki1_saca_052,  /* 52 ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
    gouki1_saca_053,  /* 53 ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
    gouki1_saca_054,  /* 54 ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
    gouki1_saca_054,  /* 55 ATTACK 8 SP: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
    gouki1_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    gouki1_saca_056,  /* 57 ATTACK 9 M: not started by a command */
    gouki1_saca_056,  /* 58 ATTACK 9 L: not started by a command */
    gouki1_saca_056,  /* 59 ATTACK 9 SP: not started by a command */
    gouki1_saca_060,  /* 60 ATTACK 10 S: 623+PP/KK (routine Att_PL14_AT1); 421+PP/KK (routine Att_PL14_AT1) */
    gouki1_saca_061,  /* 61 ATTACK 10 M: 623+PP/KK (routine Att_PL14_AT1); 421+PP/KK (routine Att_PL14_AT1) */
    gouki1_saca_062,  /* 62 ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    gouki1_saca_063,  /* 63 ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    gouki1_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    gouki1_saca_064,  /* 65 ATTACK 11 M: not started by a command */
    gouki1_saca_064,  /* 66 ATTACK 11 L: not started by a command */
    gouki1_saca_067,  /* 67 ATTACK 11 SP: not started by a command */
    gouki1_saca_068,  /* 68 ATTACK 12 S: air 236+P light (routine Att_PL14_AT2) */
    gouki1_saca_069,  /* 69 ATTACK 12 M: air 236+P medium (routine Att_PL14_AT2) */
    gouki1_saca_070,  /* 70 ATTACK 12 L: air 236+P heavy/EX (routine Att_PL14_AT2) */
    gouki1_saca_070,  /* 71 ATTACK 12 SP: air 236+P heavy/EX (routine Att_PL14_AT2) */
    gouki1_saca_072,  /* 72 ATTACK 13 S: 3214+P light (plain script) */
    gouki1_saca_073,  /* 73 ATTACK 13 M: 3214+P medium (plain script) */
    gouki1_saca_074,  /* 74 ATTACK 13 L: 3214+P heavy/EX (plain script) */
    gouki1_saca_074,  /* 75 ATTACK 13 SP: 3214+P heavy/EX (plain script) */
    gouki1_saca_076,  /* 76 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    gouki1_saca_076,  /* 77 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    gouki1_saca_076,  /* 78 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    gouki1_saca_076,  /* 79 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    gouki1_saca_080,  /* 80 (never)+K light (routine Att_SLIDE_and_JUMP) */
    gouki1_saca_081,  /* 81 (never)+K medium (routine Att_SLIDE_and_JUMP) */
    gouki1_saca_082,  /* 82 (never)+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    gouki1_saca_082,  /* 83 (never)+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    gouki1_saca_084,  /* 84 623+K (routine Att_PL14_AT3) */
    gouki1_saca_085,  /* 85 not started by a command */
    gouki1_saca_086,  /* 86 not started by a command */
    gouki1_saca_087,  /* 87 not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 gouki1_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x710A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7110, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7111, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7112, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7113, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x7114, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1280, 7680), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 gouki1_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7114, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x7113, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x7113, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7112, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7111, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7110, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710F, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710B, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x710A, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 gouki1_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 gouki1_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5401),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 236+P light (plain script) */
const u16 gouki1_saca_024_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 0) };
const u16 gouki1_saca_024[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x56A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 709, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 90, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 128, 0, 0, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 94, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x56AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 236+P medium (plain script) */
const u16 gouki1_saca_025_head[4] = { HEAD(6, 0, 10, 10, 0, 1, 0) };
const u16 gouki1_saca_025[76] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x56A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 709, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 90, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 129, 0, 0, 92, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 236+P heavy/EX (plain script), 27 ATTACK 1 SP: 236+P heavy/EX (plain script) */
const u16 gouki1_saca_026_head[4] = { HEAD(6, 0, 12, 10, 0, 1, 0) };
const u16 gouki1_saca_026[76] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x56A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 709, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 90, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 130, 0, 0, 92, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
const u16 gouki1_saca_028_head[4] = { HEAD(4, 0, 8, 8, 0, 1, 1) };
const u16 gouki1_saca_028[100] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 708, 0, 0, 0, 0, 0x56B1, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B2, -1, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 268, 0, 0, 0, 0, 0x56B4, 2, 83, 0, 0, 0, 32, 3),
    L4(10, 0, 0, 0, 0, 0, 0, 0x56B5, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x56B6, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56B7, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56B9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56BA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56CB, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
const u16 gouki1_saca_029_head[4] = { HEAD(4, 0, 10, 8, 0, 2, 1) };
const u16 gouki1_saca_029[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 708, 0, 0, 0, 0, 0x56B1, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B2, -53, 82, 0, 64, 64, 0, 0),
    L4(1, 20, 269, 0, 0, 0, 0, 0x56B4, -61, 83, 0, 0, 0, 32, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B4, 61, 84, 0, 0, 0, 32, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B5, 0, 85, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x56B5, 0, 86, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 28, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN), 31 ATTACK 2 SP: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
const u16 gouki1_saca_030_head[4] = { HEAD(4, 0, 12, 8, 0, 3, 1) };
const u16 gouki1_saca_030[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(1, 0, 708, 0, 0, 0, 0, 0x56B0, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B1, -54, 80, 0, 64, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x56B2, -55, 82, 0, 64, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x56B3, -62, 83, 0, 128, 0, 32, 4),
    L4(5, 0, 0, 0, 0, 0, 0, 0x56B4, 62, 84, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x56B5, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 28, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
const u16 gouki1_saca_032_head[4] = { HEAD(4, 0, 13, 12, 0, 1, 2) };
const u16 gouki1_saca_032[132] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5577, 0, 6, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BC, 0, 1, 0, 0, 0, 32, 51),
    L4(2, 0, 709, 0, 0, 0, 0, 0x56BD, 0, 1, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 64, 32, 52),
    L4(3, 20, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 0, 32, 52),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56BF, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -39, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5724, -39, 123, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 125, 0, 0, 0, 32, 76),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
const u16 gouki1_saca_033_head[4] = { HEAD(4, 0, 13, 12, 0, 4, 2) };
const u16 gouki1_saca_033[180] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5577, 0, 6, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BC, 0, 1, 0, 0, 0, 32, 51),
    L4(2, 0, 709, 0, 0, 0, 0, 0x56BD, -38, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 64, 32, 52),
    L4(3, 20, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 0, 32, 52),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56BF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 0, 16390), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -64, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5724, -64, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -65, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5724, -65, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 125, 0, 0, 0, 32, 76),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU), 35 ATTACK 3 SP: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
const u16 gouki1_saca_034_head[4] = { HEAD(4, 0, 13, 13, 0, 7, 2) };
const u16 gouki1_saca_034[196] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5577, 0, 6, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BC, 0, 1, 0, 0, 0, 32, 51),
    L4(2, 0, 709, 0, 0, 0, 0, 0x56BD, -38, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 64, 32, 52),
    L4(3, 20, 0, 0, 0, 0, 0, 0x56BE, 0, 120, 0, 0, 0, 32, 52),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56BF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -64, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5724, -64, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 1, 16386), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -66, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5724, -66, 123, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 125, 0, 0, 0, 32, 76),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x56C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+P (plain script), 37 ATTACK 4 M: SA I 23623+P (plain script), 38 ATTACK 4 L: SA I 23623+P (plain script), 39 ATTACK 4 SP: SA I 23623+P (plain script) */
const u16 gouki1_saca_036_head[4] = { HEAD(6, 0, 32, 12, 0, 6, 4) };
const u16 gouki1_saca_036[148] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 13, 38, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x55C0, 0, 134, 0, 0, 0, 13, 39, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x55C8, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56FA, 0, 134, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56FB, 0, 134, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    L6(3, 0, 715, 0, 0, 0, 0, 0x56FC, 0, 134, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    CMD(CM_JSR, 7, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x56A1, 0, 134, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0),
    L6(2, 0, 710, 0, 0, 2, 0, 0x56A2, 0, 74, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(3, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 0, 2, 105, 0, 0, 236, 0, 0),
    CMD(CM_JMP, 7, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA), 41 ATTACK 5 M: SA II 23623+P (routine Att_SHOURYUUREPPA), 42 ATTACK 5 L: SA II 23623+P (routine Att_SHOURYUUREPPA), 43 ATTACK 5 SP: SA II 23623+P (routine Att_SHOURYUUREPPA) */
const u16 gouki1_saca_040_head[4] = { HEAD(6, 0, 32, 11, 0, 11, 8) };
const u16 gouki1_saca_040[472] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 715, 0, 0, 0, 0, 0x56AE, 0, 134, 0, 0, 0, 13, 17, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56AF, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(42, 0, 0, 0, 0, 0, 0, 0x56B0, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B1, -89, 135, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 709, 0, 0, 0, 0, 0x56B2, -90, 136, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x56B5, 0, 137, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B6, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x56B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_RJA, 5, 40, 23), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B0, 0, 138, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B1, -91, 139, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 709, 0, 0, 0, 0, 0x56B2, -92, 140, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x56B5, 0, 141, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B6, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x56B9, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 710, 0, 0, 0, 0, 0x56B1, -93, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B2, -94, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x56B3, -95, 141, 0, 128, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56B4, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56B4, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56B5, 0, 87, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56B6, 0, 87, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(5, 30, 0, 0, 0, 0, 0, 0x56B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56B9, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56BA, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56CB, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), 45 ATTACK 6 M: SA III 23623+K (routine Att_SHOURYUUKEN), 46 ATTACK 6 L: SA III 23623+K (routine Att_SHOURYUUKEN), 47 ATTACK 6 SP: SA III 23623+K (routine Att_SHOURYUUKEN) */
const u16 gouki1_saca_044_head[4] = { HEAD(6, 0, 33, 12, 0, 12, 46) };
const u16 gouki1_saca_044[520] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 715, 0, 0, 0, 0, 0x55C0, 0, 134, 0, 0, 0, 13, 46, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x55C8, 0, 134, 0, 0, 0, 32, 97, 780, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56FA, 0, 134, 0, 0, 0, 32, 98, 780, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56FB, 0, 134, 0, 0, 0, 32, 99, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x56FC, 0, 134, 0, 0, 0, 32, 100, 780, 0, 0, 0, 0),
    L6(26, 0, 0, 0, 0, 0, 0, 0x5488, 0, 134, 0, 0, 0, 32, 101, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5577, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x56BC, 0, 134, 0, 0, 0, 32, 102, 0, 0, 0, 0, 0),
    L6(2, 0, 710, 0, 0, 0, 0, 0x56BD, -77, 143, 0, 0, 0, 32, 103, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 85, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 86, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x56BE, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 87, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 88, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 0, 0, 0x56BF, 0, 144, 0, 0, 0, 22, 22, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -79, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -80, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -67, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -68, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -79, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -80, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 714, 0, 0, 0, 0, 0x566D, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566F, -79, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5673, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5674, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5675, -81, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5676, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5677, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5678, 0, 146, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 146, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x56C7, 0, 146, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA I air 23623+P (routine Att_PL14_AT2), 49 ATTACK 7 M: SA I air 23623+P (routine Att_PL14_AT2), 50 ATTACK 7 L: SA I air 23623+P (routine Att_PL14_AT2), 51 ATTACK 7 SP: SA I air 23623+P (routine Att_PL14_AT2) */
const u16 gouki1_saca_048_head[4] = { HEAD(6, 22, 32, 13, 0, 6, 49) };
const u16 gouki1_saca_048[268] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5702, 0, 134, 0, 0, 0, 13, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 715, 0, 0, 0, 0, 0x5703, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x5704, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5702, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5700, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 3, 0, 0x5701, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x5702, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x5703, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(14, 0, 0, 0, 0, 3, 0, 0x5704, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 20, 716, 0, 0, 4, 0, 0x5641, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x5700, 0, 4, 0, 0, 0, 2, 118, 4096, 0, 0, 0, 0),
    L6(8, 10, 0, 0, 0, 0, 0, 0x5701, 0, 4, 0, 0, 0, 21, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5702, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5444, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5445, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5446, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5447, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 gouki1_saca_052_head[4] = { HEAD(4, 22, 9, 11, 0, 1, 70) };
const u16 gouki1_saca_052[140] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 709, 0, 0, 0, 0, 0x5790, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5791, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5792, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -82, 121, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5722, 0, 122, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5724, -83, 123, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 64, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 125, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5446, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5447, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5448, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 gouki1_saca_053_head[4] = { HEAD(4, 22, 11, 11, 0, 2, 70) };
const u16 gouki1_saca_053[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 709, 0, 0, 0, 0, 0x5790, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5791, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5792, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -82, 121, 0, 0, 64, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5722, 0, 122, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5724, -83, 123, 0, 0, 64, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 64, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 52, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU), 55 ATTACK 8 SP: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 gouki1_saca_054_head[4] = { HEAD(4, 22, 13, 11, 0, 4, 70) };
const u16 gouki1_saca_054[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 709, 0, 0, 0, 0, 0x5790, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5791, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5792, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 120, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5721, -82, 121, 0, 0, 64, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5722, 0, 122, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 120, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5724, -83, 123, 0, 0, 64, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5725, 0, 124, 0, 0, 64, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 52, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 gouki1_saca_056_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 33) };
const u16 gouki1_saca_056[108] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5429, 0, 49, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 22, 20),
    L4(4, 0, 269, 0, 0, 0, 0, 0x5642, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5644, -69, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5648, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5645, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5646, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5647, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: 623+PP/KK (routine Att_PL14_AT1); 421+PP/KK (routine Att_PL14_AT1) */
const u16 gouki1_saca_060_head[4] = { HEAD(4, 0, 8, 0, 0, 0, 48) };
const u16 gouki1_saca_060[140] = {
    L4(2, 20, 0, 0, 0, 0, 0, 0x5730, 0, 0, 0, 0, 0, 18, 10),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 0, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5732, 0, 0, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5733, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5734, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 20, 735, 0, 0, 0, 0, 0x5735, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5736, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5737, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5730, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 0, 0, 0, 0, 0, 0),
    L4(46, 10, 0, 0, 0, 0, 0, 0x56F0, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x56F0, 0, 0, 0, 0, 0, 19, 10),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5428, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: 623+PP/KK (routine Att_PL14_AT1); 421+PP/KK (routine Att_PL14_AT1) */
const u16 gouki1_saca_061_head[4] = { HEAD(4, 0, 9, 0, 0, 0, 48) };
const u16 gouki1_saca_061[140] = {
    L4(2, 20, 0, 0, 0, 0, 0, 0x5730, 0, 0, 0, 0, 0, 18, 10),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 0, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5732, 0, 0, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5733, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5734, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 20, 735, 0, 0, 0, 0, 0x5735, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5736, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5737, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5730, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 0, 0, 0, 0, 0, 0),
    L4(30, 10, 0, 0, 0, 0, 0, 0x56F0, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x56F0, 0, 0, 0, 0, 0, 19, 10),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5429, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5428, 0, 1, 0, 0, 0, 0, 10),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 96, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
const u16 gouki1_saca_062_head[4] = { HEAD(4, 0, 64, 4, 0, 15, 47) };
const u16 gouki1_saca_062[60] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x56F0, 0, 134, 0, 0, 0, 13, 37),
    L4(4, 20, 735, 0, 0, 0, 0, 0x56F0, -71, 95, 0, 0, 0, 0, 0),
    L4(34, 0, 0, 0, 0, 0, 0, 0x56F0, 0, 94, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x56F0, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
const u16 gouki1_saca_063_head[4] = { HEAD(4, 0, 32, 4, 0, 15, 8) };
const u16 gouki1_saca_063[356] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x5820, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5821, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5822, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5823, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 713, 0, 0, 0, 0, 0x5824, 0, 133, 0, 0, 0, 13, 30),
    L4(4, 0, 0, 0, 0, 9, 0, 0x5824, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 10, 0, 0x5825, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 11, 0, 0x5826, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 12, 0, 0x5827, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 13, 0, 0x5828, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 14, 0, 0x5829, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 15, 0, 0x582A, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 16, 0, 0x582C, 0, 133, 0, 0, 0, 32, 123),
    L4(3, 0, 0, 0, 0, 17, 0, 0x582D, 0, 133, 0, 0, 0, 32, 124),
    L4(2, 0, 0, 0, 0, 18, 0, 0x582E, 0, 133, 0, 0, 0, 32, 124),
    L4(3, 0, 0, 0, 0, 19, 0, 0x582F, 0, 133, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 20, 0, 0x5830, 0, 133, 0, 0, 0, 32, 124),
    L4(5, 0, 0, 0, 0, 21, 0, 0x5831, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 22, 0, 0x5832, 0, 133, 0, 0, 0, 32, 125),
    L4(2, 0, 720, 0, 0, 23, 0, 0x5833, 0, 133, 0, 0, 0, 32, 126),
    L4(2, 0, 0, 0, 0, 24, 0, 0x5834, 0, 133, 0, 0, 0, 32, 124),
    L4(2, 0, 734, 0, 0, 25, 0, 0x5835, -56, 182, 0, 0, 0, 32, 124),
    L4(2, 0, 0, 0, 0, 26, 0, 0x5836, 57, 183, 0, 0, 0, 39, 4),
    L4(2, 0, 0, 0, 0, 27, 0, 0x5837, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x5838, 0, 185, 0, 0, 0, 39, 12),
    L4(3, 0, 0, 0, 0, 29, 0, 0x5839, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 2, 222, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 147, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 30, 0, 0x5838, 0, 185, 0, 0, 0, 39, 20),
    L4(4, 0, 0, 0, 0, 31, 0, 0x5839, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 32, 0, 0x5839, 0, 185, 0, 0, 0, 39, 28),
    L4(4, 0, 0, 0, 0, 0, 0, 0x583A, 0, 185, 0, 0, 0, 0, 0),
    L4(20, 0, 0, 0, 0, 0, 0, 0x583B, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x583C, 0, 185, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x583D, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 894, 0, 0, 0, 0, 0x583E, 0, 186, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x583F, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57EB, 0, 188, 0, 0, 0, 32, 120),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57EC, 0, 189, 0, 0, 0, 32, 121),
    L4(4, 64, 0, 0, 0, 0, 0, 0x57ED, 0, 190, 0, 0, 0, 32, 122),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57EE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x57EF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x57EF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command, 66 ATTACK 11 L: not started by a command */
const u16 gouki1_saca_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_064[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x55C0, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x55C8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56FA, 0, 1, 0, 0, 0, 32, 18),
    L4(4, 0, 0, 0, 0, 0, 0, 0x56FB, 0, 1, 0, 0, 0, 32, 19),
    L4(3, 0, 0, 0, 0, 0, 0, 0x56FC, 0, 1, 0, 0, 0, 32, 20),
    CMD(CM_PA_X, 0, -512, 0), 0, 0, 0, 0,
    L4(2, 40, 351, 0, 0, 0, 0, 0x56FD, 0, 29, 0, 0, 0, 39, 24),
    L4(2, 0, 720, 0, 0, 0, 0, 0x56FD, 0, 29, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 62, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: not started by a command */
const u16 gouki1_saca_067_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_067[112] = {
    L6(5, 0, 0, 0, 0, 0, 0, 0x56FA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4608, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(7, 0, 0, 0, 0, 0, 0, 0x56FB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x56FC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 12, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x56FD, 0, 1, 0, 0, 0, 39, 10, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x56FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x56FF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: air 236+P light (routine Att_PL14_AT2) */
const u16 gouki1_saca_068_head[4] = { HEAD(4, 22, 8, 10, 0, 1, 50) };
const u16 gouki1_saca_068[108] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5642, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5700, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5701, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 40, 716, 0, 0, 0, 0, 0x5702, 0, 4, 0, 0, 0, 31, 1),
    L4(1, 30, 320, 0, 0, 0, 0, 0x5703, 0, 4, 0, 0, 64, 2, 114),
    CMD(CM_SCHX, 0, 3, 4), 0, 0, 0, 0,
    L4(6, 10, 0, 0, 0, 0, 0, 0x5704, 0, 4, 0, 0, 64, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5702, 0, 4, 0, 0, 64, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: air 236+P medium (routine Att_PL14_AT2) */
const u16 gouki1_saca_069_head[4] = { HEAD(4, 22, 10, 10, 0, 1, 50) };
const u16 gouki1_saca_069[68] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5642, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5700, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5701, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 40, 716, 0, 0, 0, 0, 0x5702, 0, 4, 0, 0, 0, 31, 1),
    L4(1, 30, 320, 0, 0, 0, 0, 0x5703, 0, 4, 0, 0, 64, 2, 115),
    CMD(CM_JPSS, 5, 68, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: air 236+P heavy/EX (routine Att_PL14_AT2), 71 ATTACK 12 SP: air 236+P heavy/EX (routine Att_PL14_AT2) */
const u16 gouki1_saca_070_head[4] = { HEAD(4, 22, 12, 10, 0, 1, 50) };
const u16 gouki1_saca_070[68] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5641, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5642, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5700, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5701, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 40, 716, 0, 0, 0, 0, 0x5702, 0, 4, 0, 0, 0, 31, 1),
    L4(1, 30, 320, 0, 0, 0, 0, 0x5703, 0, 4, 0, 0, 64, 2, 116),
    CMD(CM_JPSS, 5, 68, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 ATTACK 13 S: 3214+P light (plain script) */
const u16 gouki1_saca_072_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 0) };
const u16 gouki1_saca_072[232] = {
    L6(2, 0, 713, 0, 0, 0, 0, 0x5730, 0, 29, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5733, 0, 29, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 711, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 162, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 110, 0, 0, 158, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 122, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: 3214+P medium (plain script) */
const u16 gouki1_saca_073_head[4] = { HEAD(6, 0, 10, 10, 0, 2, 0) };
const u16 gouki1_saca_073[232] = {
    L6(2, 0, 713, 0, 0, 0, 0, 0x5730, 0, 29, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 33, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 711, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 162, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 111, 0, 0, 158, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 122, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: 3214+P heavy/EX (plain script), 75 ATTACK 13 SP: 3214+P heavy/EX (plain script) */
const u16 gouki1_saca_074_head[4] = { HEAD(6, 0, 12, 10, 0, 3, 0) };
const u16 gouki1_saca_074[232] = {
    L6(3, 0, 713, 0, 0, 0, 0, 0x5730, 0, 29, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5731, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5732, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5733, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A1, 0, 74, 0, 0, 0, 33, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 711, 0, 0, 0, 0, 0x56A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 162, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x56A3, 0, 75, 0, 0, 64, 2, 112, 0, 0, 158, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x56A4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 122, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x56A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x56A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x56AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x542F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI), 77 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI), 78 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI), 79 SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 gouki1_saca_076_head[4] = { HEAD(6, 22, 33, 12, 0, 10, 69) };
const u16 gouki1_saca_076[484] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 715, 0, 0, 0, 0, 0x5654, 0, 96, 0, 0, 0, 13, 48, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x564F, 0, 96, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(43, 0, 0, 0, 0, 0, 0, 0x564E, 0, 96, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x5790, -72, 147, 0, 0, 0, 32, 31, 780, 0, 0, 0, 0),
    L6(2, 1, 710, 0, 0, 0, 0, 0x5791, 0, 147, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5792, 0, 147, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -73, 145, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -72, 147, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -77, 145, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -80, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -79, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -80, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5721, -67, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5723, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5724, -68, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5720, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 714, 0, 0, 0, 0, 0x566D, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x566F, -79, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5673, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5674, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5675, -81, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5676, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5677, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5678, 0, 146, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x56C7, 0, 146, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x56C7, 0, 4, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5449, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x544A, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 (never)+K light (routine Att_SLIDE_and_JUMP) */
const u16 gouki1_saca_080_head[4] = { HEAD(4, 14, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_080[204] = {
    CMD(CM_RJA, 5, 80, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5429, 0, 127, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x57B8, 0, 128, 0, 0, 0, 32, 16),
    L4(250, 0, 0, 0, 0, 0, 6, 0x57B9, 0, 129, 0, 0, 0, 32, 17),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x554D, 0, 130, 0, 0, 0, 22, 34),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x554E, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x554F, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5550, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5551, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5552, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x554B, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x554C, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x554D, 0, 130, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x554E, 0, 130, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x554F, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5550, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5551, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5552, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x5546, 0, 130, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5548, 0, 1, 0, 0, 0, 22, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 81 (never)+K medium (routine Att_SLIDE_and_JUMP) */
const u16 gouki1_saca_081_head[4] = { HEAD(4, 14, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_081[52] = {
    CMD(CM_RJA, 5, 81, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 80, 2), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x554D, 0, 130, 0, 0, 0, 22, 34),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 80, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 (never)+K heavy/EX (routine Att_SLIDE_and_JUMP), 83 (never)+K heavy/EX (routine Att_SLIDE_and_JUMP) */
const u16 gouki1_saca_082_head[4] = { HEAD(4, 14, 0, 0, 0, 0, 0) };
const u16 gouki1_saca_082[52] = {
    CMD(CM_RJA, 5, 82, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 80, 2), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x554D, 0, 130, 0, 0, 0, 22, 34),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 80, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 623+K (routine Att_PL14_AT3) */
const u16 gouki1_saca_084_head[4] = { HEAD(4, 20, 12, 10, 0, 1, 118) };
const u16 gouki1_saca_084[260] = {
    CMD(CM_RJA, 5, 84, 19), 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 23, 1), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x544C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544D, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544E, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x544F, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5450, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5451, 0, 239, 8048, 0, 136, 31, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5452, 0, 239, 8048, 0, 136, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5453, 0, 240, 8048, 0, 136, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57BC, 0, 241, 8048, 0, 136, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57BD, 0, 241, 8048, 0, 136, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57BE, 0, 241, 8048, 0, 136, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C0, 0, 4, 8048, 0, 136, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C1, 0, 4, 8048, 0, 136, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C2, 0, 4, 8048, 0, 136, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C3, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x57C4, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 0, 0x57C5, 0, 242, 0, 0, 0, 22, 0),
    CMD(CM_ASXY, 254, 0, 0), 0, 0, 0, 0,
    L4(1, 30, 709, 0, 0, 0, 0, 0x57C6, -84, 243, 0, 128, 0, 30, 209),
    CMD(CM_ASXY, 256, 0, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x57C7, 0, 244, 0, 128, 0, 30, 210),
    L4(6, 21, 0, 0, 0, 0, 0, 0x57C8, 0, 245, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57C9, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57CA, 0, 247, 0, 0, 0, 32, 129),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57CB, 0, 248, 0, 0, 0, 32, 130),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57B0, 0, 248, 0, 0, 0, 32, 131),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57B1, 0, 248, 0, 0, 0, 32, 132),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57B2, 0, 1, 0, 0, 0, 32, 132),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 85 not started by a command */
const u16 gouki1_saca_085_head[4] = { HEAD(4, 20, 12, 10, 0, 1, 119) };
const u16 gouki1_saca_085[124] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    CMD(CM_SCHX, 2, 4, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x57BC, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BD, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BE, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x57CD, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 1, 711, 0, 0, 0, 0, 0x57CE, 0, 250, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x57CF, 0, 250, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57D0, -85, 251, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57D1, 0, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57D2, 0, 253, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57D3, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x57D4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 not started by a command */
const u16 gouki1_saca_086_head[4] = { HEAD(4, 20, 12, 10, 0, 1, 120) };
const u16 gouki1_saca_086[116] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    CMD(CM_MVIX, 94, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x57BC, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BD, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BE, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x57C0, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C1, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57C2, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 708, 0, 0, 0, 0, 0x57C3, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 20, 269, 0, 0, 0, 0, 0x57C4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x57D6, -86, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57D7, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57D8, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 not started by a command */
const u16 gouki1_saca_087_head[4] = { HEAD(4, 20, 28, 10, 0, 1, 121) };
const u16 gouki1_saca_087[124] = {
    CMD(CM_CAFR, 2, 1, 19), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 19), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BC, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x57BD, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x57BE, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_EPCY, 0, 0, 16387), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x57DC, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x57DC, -87, 257, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57DC, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x57D3, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x57D4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5456, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5457, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 45 entries */
const u16* const gouki1_cbca[46] = {
    gouki1_cbca_000,  /* 0 APPEAR JUNBI 1 */
    gouki1_cbca_001,  /* 1 APPEAR JUNBI 2 */
    gouki1_cbca_002,  /* 2 APPEAR JUNBI 3 */
    gouki1_cbca_003,  /* 3 APPEAR JUNBI 4 */
    gouki1_cbca_004,  /* 4 APPEAR JUNBI 5 */
    gouki1_cbca_005,  /* 5 APPEAR JUNBI 6 */
    gouki1_cbca_006,  /* 6 APPEAR JUNBI 7 */
    gouki1_cbca_007,  /* 7 APPEAR JUNBI 8 */
    gouki1_cbca_008,  /* 8 APPEAR 1 */
    gouki1_cbca_009,  /* 9 APPEAR 2 */
    gouki1_cbca_010,  /* 10 APPEAR 3 */
    gouki1_cbca_011,  /* 11 APPEAR 4 */
    gouki1_cbca_012,  /* 12 APPEAR 5 */
    gouki1_cbca_013,  /* 13 APPEAR 6 */
    gouki1_cbca_014,  /* 14 APPEAR 7 */
    gouki1_cbca_015,  /* 15 APPEAR 8 */
    gouki1_cbca_016,  /* 16 SP APPEAR 1 */
    gouki1_cbca_017,  /* 17 SP APPEAR 2 */
    gouki1_cbca_018,  /* 18 SP APPEAR 3 */
    gouki1_cbca_019,  /* 19 SP APPEAR 4 */
    gouki1_cbca_020,  /* 20 SP APPEAR 5 */
    gouki1_cbca_021,  /* 21 SP APPEAR 6 */
    gouki1_cbca_022,  /* 22 SP APPEAR 7 */
    gouki1_cbca_023,  /* 23 SP APPEAR 8 */
    gouki1_cbca_024,  /* 24 ZANNEN 1 */
    gouki1_cbca_025,  /* 25 ZANNEN 2 */
    gouki1_cbca_026,  /* 26 ZANNEN 3 */
    gouki1_cbca_026,  /* 27 ZANNEN 4 */
    gouki1_cbca_028,  /* 28 ZANNEN 5 */
    gouki1_cbca_029,  /* 29 ZANNEN 6 */
    gouki1_cbca_030,  /* 30 ZANNEN 7 */
    gouki1_cbca_031,  /* 31 ZANNEN 8 */
    gouki1_cbca_032,  /* 32 WIN 1 */
    gouki1_cbca_033,  /* 33 WIN 2 */
    gouki1_cbca_034,  /* 34 WIN 3 */
    gouki1_cbca_035,  /* 35 WIN 4 */
    gouki1_cbca_036,  /* 36 WIN 5 */
    gouki1_cbca_037,  /* 37 WIN 6 */
    gouki1_cbca_038,  /* 38 WIN 7 */
    gouki1_cbca_039,  /* 39 WIN 8 */
    gouki1_cbca_040,  /* 40 SP WIN 1 */
    gouki1_cbca_041,  /* 41 SP WIN 2 */
    gouki1_cbca_042,  /* 42 SP WIN 3 */
    gouki1_cbca_043,  /* 43 SP WIN 4 */
    gouki1_cbca_044,  /* 44 SP WIN 5 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 gouki1_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 17, 8),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 gouki1_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 gouki1_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 gouki1_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 gouki1_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 gouki1_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 gouki1_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 gouki1_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_007[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 gouki1_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_008[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 gouki1_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_009[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 gouki1_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 gouki1_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_011[20] = {
    CMD(CM_RJA, 5, 40, 12),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 gouki1_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_012[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 gouki1_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_013[24] = {
    CMD(CM_CAFR, 2, 6, 18),
    CMD(CM_CARE, 2, 6, 18),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 38, 0),
    CMD(CM_STOP, 50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 gouki1_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_014[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 56, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 gouki1_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_015[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 57, 1),
    CMD(CM_RJA3, 7, 58, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 gouki1_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_016[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 59, 1),
    CMD(CM_RJA3, 7, 60, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 gouki1_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_017[28] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 35, 8),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 gouki1_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_018[28] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 63, 1),
    CMD(CM_RJA3, 7, 64, 1),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 gouki1_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_019[28] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 35, 8),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 gouki1_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_020[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 58, 0),
    CMD(CM_STOP, -50, 58, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 gouki1_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_021[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 65, 1),
    CMD(CM_RJA3, 7, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 gouki1_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_022[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 67, 1),
    CMD(CM_RJA3, 7, 68, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 gouki1_cbca_023_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_023[44] = {
    CMD(CM_RJA7, 5, 85, 1),
    CMD(CM_IFS3, 16, 16392, 8192),
    CMD(CM_IFS3, 32, 8200, 8192),
    CMD(CM_IFS3, 64, 8200, 8192),
    CMD(CM_RJA7, 5, 86, 1),
    CMD(CM_IFS3, 256, 8200, 8192),
    CMD(CM_IFS3, 512, 8200, 8192),
    CMD(CM_IFS3, 1024, 8200, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_IFS3, 256, 8192, 8200),
    CMD(CM_JMP, 5, 87, 1),
};

/* script: 24 ZANNEN 1 */
const u16 gouki1_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_024[4] = {
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 gouki1_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_025[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 56, 0),
    CMD(CM_STOP, -56, 56, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3, 27 ZANNEN 4 */
const u16 gouki1_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_026[4] = {
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 gouki1_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_028[8] = {
    CMD(CM_RJA6, 4, 3, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 29 ZANNEN 6 */
const u16 gouki1_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_029[8] = {
    CMD(CM_RJA6, 4, 4, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 30 ZANNEN 7 */
const u16 gouki1_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_030[8] = {
    CMD(CM_RJA6, 4, 5, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 31 ZANNEN 8 */
const u16 gouki1_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_031[8] = {
    CMD(CM_RJA6, 4, 12, 4),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 32 WIN 1 */
const u16 gouki1_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_032[8] = {
    CMD(CM_RJA6, 4, 13, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 33 WIN 2 */
const u16 gouki1_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_033[8] = {
    CMD(CM_RJA6, 4, 6, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 34 WIN 3 */
const u16 gouki1_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_034[8] = {
    CMD(CM_RJA6, 4, 7, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 35 WIN 4 */
const u16 gouki1_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_035[8] = {
    CMD(CM_RJA6, 4, 15, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 36 WIN 5 */
const u16 gouki1_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_036[8] = {
    CMD(CM_RJA6, 4, 17, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 37 WIN 6 */
const u16 gouki1_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_037[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 gouki1_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_038[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 gouki1_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_039[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 gouki1_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_040[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 gouki1_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_041[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 gouki1_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_042[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 gouki1_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_043[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 gouki1_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_cbca_044[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

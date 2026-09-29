/*
 * ALEX_CHAR.C  Alex's animation scripts and sprite part tables
 *
 * The animation scripts Alex's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 alex_nmca_000[], alex_nmca_001[], alex_nmca_002[], alex_nmca_003[], alex_nmca_004[], alex_nmca_005[], alex_nmca_006[], alex_nmca_007[], alex_nmca_008[], alex_nmca_011[], alex_nmca_012[], alex_nmca_013[], alex_nmca_014[], alex_nmca_015[], alex_nmca_016[], alex_nmca_017[], alex_nmca_020[], alex_nmca_021[], alex_nmca_022[], alex_nmca_023[], alex_nmca_024[], alex_nmca_026[], alex_nmca_027[], alex_nmca_029[], alex_nmca_030[], alex_nmca_031[], alex_nmca_032[], alex_nmca_033[], alex_nmca_038[], alex_nmca_040[], alex_nmca_041[], alex_nmca_043[], alex_nmca_044[], alex_nmca_045[], alex_nmca_046[], alex_nmca_047[], alex_nmca_048[], alex_nmca_049[], alex_nmca_050[];
extern const u16 alex_nmca_000_head[];
extern const u16 alex_nmca_001_head[];
extern const u16 alex_nmca_002_head[];
extern const u16 alex_nmca_003_head[];
extern const u16 alex_nmca_004_head[];
extern const u16 alex_nmca_005_head[];
extern const u16 alex_nmca_006_head[];
extern const u16 alex_nmca_007_head[];
extern const u16 alex_nmca_008_head[];
extern const u16 alex_nmca_011_head[];
extern const u16 alex_nmca_012_head[];
extern const u16 alex_nmca_013_head[];
extern const u16 alex_nmca_014_head[];
extern const u16 alex_nmca_015_head[];
extern const u16 alex_nmca_016_head[];
extern const u16 alex_nmca_017_head[];
extern const u16 alex_nmca_020_head[];
extern const u16 alex_nmca_021_head[];
extern const u16 alex_nmca_022_head[];
extern const u16 alex_nmca_023_head[];
extern const u16 alex_nmca_024_head[];
extern const u16 alex_nmca_026_head[];
extern const u16 alex_nmca_027_head[];
extern const u16 alex_nmca_029_head[];
extern const u16 alex_nmca_030_head[];
extern const u16 alex_nmca_031_head[];
extern const u16 alex_nmca_032_head[];
extern const u16 alex_nmca_033_head[];
extern const u16 alex_nmca_038_head[];
extern const u16 alex_nmca_040_head[];
extern const u16 alex_nmca_041_head[];
extern const u16 alex_nmca_043_head[];
extern const u16 alex_nmca_044_head[];
extern const u16 alex_nmca_045_head[];
extern const u16 alex_nmca_046_head[];
extern const u16 alex_nmca_047_head[];
extern const u16 alex_nmca_048_head[];
extern const u16 alex_nmca_049_head[];
extern const u16 alex_nmca_050_head[];
extern const u16 alex_dmca_000[], alex_dmca_001[], alex_dmca_002[], alex_dmca_003[], alex_dmca_004[], alex_dmca_006[], alex_dmca_008[], alex_dmca_009[], alex_dmca_010[], alex_dmca_014[], alex_dmca_018[], alex_dmca_022[], alex_dmca_025[], alex_dmca_026[], alex_dmca_024[], alex_dmca_029[], alex_dmca_030[], alex_dmca_034[], alex_dmca_036[], alex_dmca_037[], alex_dmca_038[], alex_dmca_039[], alex_dmca_040[], alex_dmca_041[], alex_dmca_042[], alex_dmca_043[], alex_dmca_048[], alex_dmca_049[], alex_dmca_050[], alex_dmca_052[], alex_dmca_053[], alex_dmca_054[], alex_dmca_055[], alex_dmca_056[], alex_dmca_057[], alex_dmca_058[], alex_dmca_059[], alex_dmca_060[], alex_dmca_064[], alex_dmca_065[], alex_dmca_066[], alex_dmca_067[], alex_dmca_068[], alex_dmca_069[], alex_dmca_070[], alex_dmca_071[], alex_dmca_072[], alex_dmca_073[], alex_dmca_074[], alex_dmca_075[], alex_dmca_076[], alex_dmca_078[], alex_dmca_079[], alex_dmca_080[], alex_dmca_082[], alex_dmca_083[], alex_dmca_084[], alex_dmca_090[], alex_dmca_091[], alex_dmca_096[], alex_dmca_097[];
extern const u16 alex_dmca_000_head[];
extern const u16 alex_dmca_001_head[];
extern const u16 alex_dmca_002_head[];
extern const u16 alex_dmca_003_head[];
extern const u16 alex_dmca_004_head[];
extern const u16 alex_dmca_006_head[];
extern const u16 alex_dmca_008_head[];
extern const u16 alex_dmca_009_head[];
extern const u16 alex_dmca_010_head[];
extern const u16 alex_dmca_014_head[];
extern const u16 alex_dmca_018_head[];
extern const u16 alex_dmca_022_head[];
extern const u16 alex_dmca_025_head[];
extern const u16 alex_dmca_026_head[];
extern const u16 alex_dmca_024_head[];
extern const u16 alex_dmca_029_head[];
extern const u16 alex_dmca_030_head[];
extern const u16 alex_dmca_034_head[];
extern const u16 alex_dmca_036_head[];
extern const u16 alex_dmca_037_head[];
extern const u16 alex_dmca_038_head[];
extern const u16 alex_dmca_039_head[];
extern const u16 alex_dmca_040_head[];
extern const u16 alex_dmca_041_head[];
extern const u16 alex_dmca_042_head[];
extern const u16 alex_dmca_043_head[];
extern const u16 alex_dmca_048_head[];
extern const u16 alex_dmca_049_head[];
extern const u16 alex_dmca_050_head[];
extern const u16 alex_dmca_052_head[];
extern const u16 alex_dmca_053_head[];
extern const u16 alex_dmca_054_head[];
extern const u16 alex_dmca_055_head[];
extern const u16 alex_dmca_056_head[];
extern const u16 alex_dmca_057_head[];
extern const u16 alex_dmca_058_head[];
extern const u16 alex_dmca_059_head[];
extern const u16 alex_dmca_060_head[];
extern const u16 alex_dmca_064_head[];
extern const u16 alex_dmca_065_head[];
extern const u16 alex_dmca_066_head[];
extern const u16 alex_dmca_067_head[];
extern const u16 alex_dmca_068_head[];
extern const u16 alex_dmca_069_head[];
extern const u16 alex_dmca_070_head[];
extern const u16 alex_dmca_071_head[];
extern const u16 alex_dmca_072_head[];
extern const u16 alex_dmca_073_head[];
extern const u16 alex_dmca_074_head[];
extern const u16 alex_dmca_075_head[];
extern const u16 alex_dmca_076_head[];
extern const u16 alex_dmca_078_head[];
extern const u16 alex_dmca_079_head[];
extern const u16 alex_dmca_080_head[];
extern const u16 alex_dmca_082_head[];
extern const u16 alex_dmca_083_head[];
extern const u16 alex_dmca_084_head[];
extern const u16 alex_dmca_090_head[];
extern const u16 alex_dmca_091_head[];
extern const u16 alex_dmca_096_head[];
extern const u16 alex_dmca_097_head[];
extern const u16 alex_btca_000[], alex_btca_001[], alex_btca_002[], alex_btca_003[], alex_btca_004[], alex_btca_005[], alex_btca_006[], alex_btca_007[], alex_btca_008[], alex_btca_009[], alex_btca_010[], alex_btca_011[], alex_btca_012[], alex_btca_013[], alex_btca_014[], alex_btca_015[], alex_btca_016[], alex_btca_017[], alex_btca_018[], alex_btca_019[], alex_btca_020[], alex_btca_021[], alex_btca_022[], alex_btca_023[], alex_btca_024[], alex_btca_025[], alex_btca_026[], alex_btca_027[], alex_btca_028[], alex_btca_029[], alex_btca_030[], alex_btca_031[], alex_btca_032[], alex_btca_033[], alex_btca_034[];
extern const u16 alex_btca_000_head[];
extern const u16 alex_btca_001_head[];
extern const u16 alex_btca_002_head[];
extern const u16 alex_btca_003_head[];
extern const u16 alex_btca_004_head[];
extern const u16 alex_btca_005_head[];
extern const u16 alex_btca_006_head[];
extern const u16 alex_btca_007_head[];
extern const u16 alex_btca_008_head[];
extern const u16 alex_btca_009_head[];
extern const u16 alex_btca_010_head[];
extern const u16 alex_btca_011_head[];
extern const u16 alex_btca_012_head[];
extern const u16 alex_btca_013_head[];
extern const u16 alex_btca_014_head[];
extern const u16 alex_btca_015_head[];
extern const u16 alex_btca_016_head[];
extern const u16 alex_btca_017_head[];
extern const u16 alex_btca_018_head[];
extern const u16 alex_btca_019_head[];
extern const u16 alex_btca_020_head[];
extern const u16 alex_btca_021_head[];
extern const u16 alex_btca_022_head[];
extern const u16 alex_btca_023_head[];
extern const u16 alex_btca_024_head[];
extern const u16 alex_btca_025_head[];
extern const u16 alex_btca_026_head[];
extern const u16 alex_btca_027_head[];
extern const u16 alex_btca_028_head[];
extern const u16 alex_btca_029_head[];
extern const u16 alex_btca_030_head[];
extern const u16 alex_btca_031_head[];
extern const u16 alex_btca_032_head[];
extern const u16 alex_btca_033_head[];
extern const u16 alex_btca_034_head[];
extern const u16 alex_caca_000[], alex_caca_001[], alex_caca_002[], alex_caca_006[], alex_caca_007[], alex_caca_008[], alex_caca_010[], alex_caca_011[], alex_caca_012[], alex_caca_014[], alex_caca_018[], alex_caca_019[], alex_caca_020[], alex_caca_021[], alex_caca_022[], alex_caca_023[], alex_caca_027[], alex_caca_028[], alex_caca_029[], alex_caca_030[], alex_caca_031[], alex_caca_032[], alex_caca_033[];
extern const u16 alex_caca_000_head[];
extern const u16 alex_caca_001_head[];
extern const u16 alex_caca_002_head[];
extern const u16 alex_caca_006_head[];
extern const u16 alex_caca_007_head[];
extern const u16 alex_caca_008_head[];
extern const u16 alex_caca_010_head[];
extern const u16 alex_caca_011_head[];
extern const u16 alex_caca_012_head[];
extern const u16 alex_caca_014_head[];
extern const u16 alex_caca_018_head[];
extern const u16 alex_caca_019_head[];
extern const u16 alex_caca_020_head[];
extern const u16 alex_caca_021_head[];
extern const u16 alex_caca_022_head[];
extern const u16 alex_caca_023_head[];
extern const u16 alex_caca_027_head[];
extern const u16 alex_caca_028_head[];
extern const u16 alex_caca_029_head[];
extern const u16 alex_caca_030_head[];
extern const u16 alex_caca_031_head[];
extern const u16 alex_caca_032_head[];
extern const u16 alex_caca_033_head[];
extern const u16 alex_cuca_000[], alex_cuca_001[], alex_cuca_002[], alex_cuca_003[], alex_cuca_004[], alex_cuca_005[], alex_cuca_006[], alex_cuca_007[], alex_cuca_008[], alex_cuca_009[], alex_cuca_010[], alex_cuca_011[], alex_cuca_012[], alex_cuca_013[], alex_cuca_014[], alex_cuca_015[], alex_cuca_016[], alex_cuca_017[], alex_cuca_018[], alex_cuca_019[], alex_cuca_020[], alex_cuca_021[], alex_cuca_022[], alex_cuca_023[], alex_cuca_024[], alex_cuca_025[], alex_cuca_026[], alex_cuca_027[], alex_cuca_028[], alex_cuca_029[], alex_cuca_030[], alex_cuca_031[], alex_cuca_032[], alex_cuca_033[], alex_cuca_034[], alex_cuca_035[], alex_cuca_036[], alex_cuca_037[], alex_cuca_038[], alex_cuca_039[], alex_cuca_040[], alex_cuca_041[], alex_cuca_042[], alex_cuca_043[], alex_cuca_044[], alex_cuca_045[], alex_cuca_046[], alex_cuca_047[], alex_cuca_048[], alex_cuca_049[], alex_cuca_050[], alex_cuca_051[], alex_cuca_052[], alex_cuca_053[], alex_cuca_054[], alex_cuca_055[], alex_cuca_056[], alex_cuca_057[], alex_cuca_058[], alex_cuca_059[], alex_cuca_060[], alex_cuca_061[], alex_cuca_062[], alex_cuca_063[], alex_cuca_064[], alex_cuca_065[], alex_cuca_066[], alex_cuca_067[];
extern const u16 alex_cuca_000_head[];
extern const u16 alex_cuca_001_head[];
extern const u16 alex_cuca_002_head[];
extern const u16 alex_cuca_003_head[];
extern const u16 alex_cuca_004_head[];
extern const u16 alex_cuca_005_head[];
extern const u16 alex_cuca_006_head[];
extern const u16 alex_cuca_007_head[];
extern const u16 alex_cuca_008_head[];
extern const u16 alex_cuca_009_head[];
extern const u16 alex_cuca_010_head[];
extern const u16 alex_cuca_011_head[];
extern const u16 alex_cuca_012_head[];
extern const u16 alex_cuca_013_head[];
extern const u16 alex_cuca_014_head[];
extern const u16 alex_cuca_015_head[];
extern const u16 alex_cuca_016_head[];
extern const u16 alex_cuca_017_head[];
extern const u16 alex_cuca_018_head[];
extern const u16 alex_cuca_019_head[];
extern const u16 alex_cuca_020_head[];
extern const u16 alex_cuca_021_head[];
extern const u16 alex_cuca_022_head[];
extern const u16 alex_cuca_023_head[];
extern const u16 alex_cuca_024_head[];
extern const u16 alex_cuca_025_head[];
extern const u16 alex_cuca_026_head[];
extern const u16 alex_cuca_027_head[];
extern const u16 alex_cuca_028_head[];
extern const u16 alex_cuca_029_head[];
extern const u16 alex_cuca_030_head[];
extern const u16 alex_cuca_031_head[];
extern const u16 alex_cuca_032_head[];
extern const u16 alex_cuca_033_head[];
extern const u16 alex_cuca_034_head[];
extern const u16 alex_cuca_035_head[];
extern const u16 alex_cuca_036_head[];
extern const u16 alex_cuca_037_head[];
extern const u16 alex_cuca_038_head[];
extern const u16 alex_cuca_039_head[];
extern const u16 alex_cuca_040_head[];
extern const u16 alex_cuca_041_head[];
extern const u16 alex_cuca_042_head[];
extern const u16 alex_cuca_043_head[];
extern const u16 alex_cuca_044_head[];
extern const u16 alex_cuca_045_head[];
extern const u16 alex_cuca_046_head[];
extern const u16 alex_cuca_047_head[];
extern const u16 alex_cuca_048_head[];
extern const u16 alex_cuca_049_head[];
extern const u16 alex_cuca_050_head[];
extern const u16 alex_cuca_051_head[];
extern const u16 alex_cuca_052_head[];
extern const u16 alex_cuca_053_head[];
extern const u16 alex_cuca_054_head[];
extern const u16 alex_cuca_055_head[];
extern const u16 alex_cuca_056_head[];
extern const u16 alex_cuca_057_head[];
extern const u16 alex_cuca_058_head[];
extern const u16 alex_cuca_059_head[];
extern const u16 alex_cuca_060_head[];
extern const u16 alex_cuca_061_head[];
extern const u16 alex_cuca_062_head[];
extern const u16 alex_cuca_063_head[];
extern const u16 alex_cuca_064_head[];
extern const u16 alex_cuca_065_head[];
extern const u16 alex_cuca_066_head[];
extern const u16 alex_cuca_067_head[];
extern const u16 alex_atca_000[], alex_atca_001[], alex_atca_003[], alex_atca_005[], alex_atca_006[], alex_atca_007[], alex_atca_008[], alex_atca_009[], alex_atca_012[], alex_atca_013[], alex_atca_015[], alex_atca_018[], alex_atca_021[], alex_atca_024[], alex_atca_027[], alex_atca_030[], alex_atca_033[], alex_atca_036[], alex_atca_038[], alex_atca_040[], alex_atca_041[], alex_atca_042[], alex_atca_044[], alex_atca_046[], alex_atca_048[], alex_atca_050[], alex_atca_052[], alex_atca_053[], alex_atca_054[], alex_atca_056[], alex_atca_058[], alex_atca_060[], alex_atca_062[], alex_atca_064[], alex_atca_066[], alex_atca_068[], alex_atca_070[], alex_atca_072[], alex_atca_074[], alex_atca_076[], alex_atca_077[], alex_atca_078[], alex_atca_080[], alex_atca_082[], alex_atca_084[], alex_atca_086[], alex_atca_088[], alex_atca_089[], alex_atca_090[], alex_atca_092[], alex_atca_094[], alex_atca_096[], alex_atca_098[], alex_atca_100[], alex_atca_102[], alex_atca_104[], alex_atca_106[], alex_atca_108[], alex_atca_110[], alex_atca_112[], alex_atca_114[], alex_atca_116[], alex_atca_118[], alex_atca_144[], alex_atca_146[];
extern const u16 alex_atca_000_head[];
extern const u16 alex_atca_001_head[];
extern const u16 alex_atca_003_head[];
extern const u16 alex_atca_005_head[];
extern const u16 alex_atca_006_head[];
extern const u16 alex_atca_007_head[];
extern const u16 alex_atca_008_head[];
extern const u16 alex_atca_009_head[];
extern const u16 alex_atca_012_head[];
extern const u16 alex_atca_013_head[];
extern const u16 alex_atca_015_head[];
extern const u16 alex_atca_018_head[];
extern const u16 alex_atca_021_head[];
extern const u16 alex_atca_024_head[];
extern const u16 alex_atca_027_head[];
extern const u16 alex_atca_030_head[];
extern const u16 alex_atca_033_head[];
extern const u16 alex_atca_036_head[];
extern const u16 alex_atca_038_head[];
extern const u16 alex_atca_040_head[];
extern const u16 alex_atca_041_head[];
extern const u16 alex_atca_042_head[];
extern const u16 alex_atca_044_head[];
extern const u16 alex_atca_046_head[];
extern const u16 alex_atca_048_head[];
extern const u16 alex_atca_050_head[];
extern const u16 alex_atca_052_head[];
extern const u16 alex_atca_053_head[];
extern const u16 alex_atca_054_head[];
extern const u16 alex_atca_056_head[];
extern const u16 alex_atca_058_head[];
extern const u16 alex_atca_060_head[];
extern const u16 alex_atca_062_head[];
extern const u16 alex_atca_064_head[];
extern const u16 alex_atca_066_head[];
extern const u16 alex_atca_068_head[];
extern const u16 alex_atca_070_head[];
extern const u16 alex_atca_072_head[];
extern const u16 alex_atca_074_head[];
extern const u16 alex_atca_076_head[];
extern const u16 alex_atca_077_head[];
extern const u16 alex_atca_078_head[];
extern const u16 alex_atca_080_head[];
extern const u16 alex_atca_082_head[];
extern const u16 alex_atca_084_head[];
extern const u16 alex_atca_086_head[];
extern const u16 alex_atca_088_head[];
extern const u16 alex_atca_089_head[];
extern const u16 alex_atca_090_head[];
extern const u16 alex_atca_092_head[];
extern const u16 alex_atca_094_head[];
extern const u16 alex_atca_096_head[];
extern const u16 alex_atca_098_head[];
extern const u16 alex_atca_100_head[];
extern const u16 alex_atca_102_head[];
extern const u16 alex_atca_104_head[];
extern const u16 alex_atca_106_head[];
extern const u16 alex_atca_108_head[];
extern const u16 alex_atca_110_head[];
extern const u16 alex_atca_112_head[];
extern const u16 alex_atca_114_head[];
extern const u16 alex_atca_116_head[];
extern const u16 alex_atca_118_head[];
extern const u16 alex_atca_144_head[];
extern const u16 alex_atca_146_head[];
extern const u16 alex_exca_000[], alex_exca_001[], alex_exca_003[], alex_exca_004[], alex_exca_005[], alex_exca_006[], alex_exca_007[], alex_exca_008[], alex_exca_009[], alex_exca_010[], alex_exca_012[], alex_exca_013[], alex_exca_014[], alex_exca_015[], alex_exca_016[], alex_exca_017[], alex_exca_018[], alex_exca_022[], alex_exca_023[], alex_exca_024[], alex_exca_027[], alex_exca_028[], alex_exca_029[], alex_exca_030[], alex_exca_031[], alex_exca_032[], alex_exca_033[], alex_exca_034[], alex_exca_035[], alex_exca_036[], alex_exca_037[], alex_exca_038[], alex_exca_039[], alex_exca_040[], alex_exca_041[], alex_exca_042[], alex_exca_043[], alex_exca_044[], alex_exca_045[], alex_exca_048[], alex_exca_049[], alex_exca_050[];
extern const u16 alex_exca_000_head[];
extern const u16 alex_exca_001_head[];
extern const u16 alex_exca_003_head[];
extern const u16 alex_exca_004_head[];
extern const u16 alex_exca_005_head[];
extern const u16 alex_exca_006_head[];
extern const u16 alex_exca_007_head[];
extern const u16 alex_exca_008_head[];
extern const u16 alex_exca_009_head[];
extern const u16 alex_exca_010_head[];
extern const u16 alex_exca_012_head[];
extern const u16 alex_exca_013_head[];
extern const u16 alex_exca_014_head[];
extern const u16 alex_exca_015_head[];
extern const u16 alex_exca_016_head[];
extern const u16 alex_exca_017_head[];
extern const u16 alex_exca_018_head[];
extern const u16 alex_exca_022_head[];
extern const u16 alex_exca_023_head[];
extern const u16 alex_exca_024_head[];
extern const u16 alex_exca_027_head[];
extern const u16 alex_exca_028_head[];
extern const u16 alex_exca_029_head[];
extern const u16 alex_exca_030_head[];
extern const u16 alex_exca_031_head[];
extern const u16 alex_exca_032_head[];
extern const u16 alex_exca_033_head[];
extern const u16 alex_exca_034_head[];
extern const u16 alex_exca_035_head[];
extern const u16 alex_exca_036_head[];
extern const u16 alex_exca_037_head[];
extern const u16 alex_exca_038_head[];
extern const u16 alex_exca_039_head[];
extern const u16 alex_exca_040_head[];
extern const u16 alex_exca_041_head[];
extern const u16 alex_exca_042_head[];
extern const u16 alex_exca_043_head[];
extern const u16 alex_exca_044_head[];
extern const u16 alex_exca_045_head[];
extern const u16 alex_exca_048_head[];
extern const u16 alex_exca_049_head[];
extern const u16 alex_exca_050_head[];
extern const u16 alex_saca_000[], alex_saca_001[], alex_saca_002[], alex_saca_024[], alex_saca_025[], alex_saca_026[], alex_saca_027[], alex_saca_028[], alex_saca_029[], alex_saca_030[], alex_saca_031[], alex_saca_032[], alex_saca_033[], alex_saca_034[], alex_saca_036[], alex_saca_040[], alex_saca_043[], alex_saca_044[], alex_saca_048[], alex_saca_049[], alex_saca_050[], alex_saca_051[], alex_saca_052[], alex_saca_053[], alex_saca_054[], alex_saca_055[], alex_saca_056[], alex_saca_060[], alex_saca_063[], alex_saca_064[], alex_saca_065[], alex_saca_066[], alex_saca_067[], alex_saca_068[], alex_saca_069[];
extern const u16 alex_saca_000_head[];
extern const u16 alex_saca_001_head[];
extern const u16 alex_saca_002_head[];
extern const u16 alex_saca_024_head[];
extern const u16 alex_saca_025_head[];
extern const u16 alex_saca_026_head[];
extern const u16 alex_saca_027_head[];
extern const u16 alex_saca_028_head[];
extern const u16 alex_saca_029_head[];
extern const u16 alex_saca_030_head[];
extern const u16 alex_saca_031_head[];
extern const u16 alex_saca_032_head[];
extern const u16 alex_saca_033_head[];
extern const u16 alex_saca_034_head[];
extern const u16 alex_saca_036_head[];
extern const u16 alex_saca_040_head[];
extern const u16 alex_saca_043_head[];
extern const u16 alex_saca_044_head[];
extern const u16 alex_saca_048_head[];
extern const u16 alex_saca_049_head[];
extern const u16 alex_saca_050_head[];
extern const u16 alex_saca_051_head[];
extern const u16 alex_saca_052_head[];
extern const u16 alex_saca_053_head[];
extern const u16 alex_saca_054_head[];
extern const u16 alex_saca_055_head[];
extern const u16 alex_saca_056_head[];
extern const u16 alex_saca_060_head[];
extern const u16 alex_saca_063_head[];
extern const u16 alex_saca_064_head[];
extern const u16 alex_saca_065_head[];
extern const u16 alex_saca_066_head[];
extern const u16 alex_saca_067_head[];
extern const u16 alex_saca_068_head[];
extern const u16 alex_saca_069_head[];
extern const u16 alex_cbca_000[], alex_cbca_001[], alex_cbca_002[], alex_cbca_003[], alex_cbca_004[], alex_cbca_005[], alex_cbca_006[], alex_cbca_007[], alex_cbca_008[], alex_cbca_009[], alex_cbca_010[], alex_cbca_011[], alex_cbca_012[], alex_cbca_013[], alex_cbca_014[], alex_cbca_015[], alex_cbca_016[], alex_cbca_017[], alex_cbca_018[], alex_cbca_019[], alex_cbca_020[], alex_cbca_021[], alex_cbca_022[], alex_cbca_023[], alex_cbca_024[], alex_cbca_025[];
extern const u16 alex_cbca_000_head[];
extern const u16 alex_cbca_001_head[];
extern const u16 alex_cbca_002_head[];
extern const u16 alex_cbca_003_head[];
extern const u16 alex_cbca_004_head[];
extern const u16 alex_cbca_005_head[];
extern const u16 alex_cbca_006_head[];
extern const u16 alex_cbca_007_head[];
extern const u16 alex_cbca_008_head[];
extern const u16 alex_cbca_009_head[];
extern const u16 alex_cbca_010_head[];
extern const u16 alex_cbca_011_head[];
extern const u16 alex_cbca_012_head[];
extern const u16 alex_cbca_013_head[];
extern const u16 alex_cbca_014_head[];
extern const u16 alex_cbca_015_head[];
extern const u16 alex_cbca_016_head[];
extern const u16 alex_cbca_017_head[];
extern const u16 alex_cbca_018_head[];
extern const u16 alex_cbca_019_head[];
extern const u16 alex_cbca_020_head[];
extern const u16 alex_cbca_021_head[];
extern const u16 alex_cbca_022_head[];
extern const u16 alex_cbca_023_head[];
extern const u16 alex_cbca_024_head[];
extern const u16 alex_cbca_025_head[];

/* normal scripts: 51 entries */
const u16* const alex_nmca[52] = {
    alex_nmca_000,  /* 0 KAMAE */
    alex_nmca_001,  /* 1 HURIMUKI */
    alex_nmca_002,  /* 2 FRONT WALK */
    alex_nmca_003,  /* 3 BACK WALK */
    alex_nmca_004,  /* 4 DASH HUMIKOMI */
    alex_nmca_005,  /* 5 DASH TOBINOKI */
    alex_nmca_006,  /* 6 KAGAMU */
    alex_nmca_007,  /* 7 KAGAMI KAMAE */
    alex_nmca_008,  /* 8 KAGAMI TURN */
    alex_nmca_008,  /* 9 KAGAMI F WALK */
    alex_nmca_008,  /* 10 KAGAMI B WALK */
    alex_nmca_011,  /* 11 STAND UP */
    alex_nmca_012,  /* 12 JUMP JUNBI */
    alex_nmca_013,  /* 13 SP JUMP JUNBI */
    alex_nmca_014,  /* 14 JUMP FRONT */
    alex_nmca_015,  /* 15 JUMP VERTICAL */
    alex_nmca_016,  /* 16 JUMP BACK */
    alex_nmca_017,  /* 17 S JUMP FRONT */
    alex_nmca_017,  /* 18 S JUMP V */
    alex_nmca_017,  /* 19 S JUMP BACK */
    alex_nmca_020,  /* 20 SP JUMP FRONT */
    alex_nmca_021,  /* 21 SP JUMP V */
    alex_nmca_022,  /* 22 SP JUMP BACK */
    alex_nmca_023,  /* 23 WALK END */
    alex_nmca_024,  /* 24 PARING HEAD */
    alex_nmca_024,  /* 25 PARING UP */
    alex_nmca_026,  /* 26 PARING DOWN */
    alex_nmca_027,  /* 27 PARING AIR F */
    alex_nmca_027,  /* 28 PARING AIR B */
    alex_nmca_029,  /* 29 GUARD HEAD */
    alex_nmca_030,  /* 30 GUARD UP */
    alex_nmca_031,  /* 31 GUARD DOWN */
    alex_nmca_032,  /* 32 GUARD AIR */
    alex_nmca_033,  /* 33 no name */
    alex_nmca_033,  /* 34 no name */
    alex_nmca_033,  /* 35 no name */
    alex_nmca_033,  /* 36 no name */
    alex_nmca_033,  /* 37 no name */
    alex_nmca_038,  /* 38 P BREAK ZUJOU */
    alex_nmca_038,  /* 39 P BREAK UP */
    alex_nmca_040,  /* 40 P BREAK DOWN */
    alex_nmca_041,  /* 41 P BREAK AIR F */
    alex_nmca_041,  /* 42 P BREAK AIR R */
    alex_nmca_043,  /* 43 TUKAMIHAZUSI */
    alex_nmca_044,  /* 44 TUKAMIHAZUSARE */
    alex_nmca_045,  /* 45 TUKAMIHAZUSI */
    alex_nmca_046,  /* 46 TUKAMIHAZUSARE */
    alex_nmca_047,  /* 47 no name */
    alex_nmca_048,  /* 48 no name */
    alex_nmca_049,  /* 49 no name */
    alex_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 alex_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_000[108] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0602, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0603, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0604, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0605, 0, 210, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0606, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0607, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0608, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0609, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060A, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060B, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 alex_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_001[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x060D, 0, 212, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060E, 0, 212, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060F, 0, 212, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 alex_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 alex_nmca_002[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x09C3, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09C4, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09C5, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0614, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0615, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0616, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0617, 0, 215, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0618, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0619, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x061A, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x061B, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x061C, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x061D, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0610, 0, 217, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0611, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0612, 0, 218, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0613, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 alex_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 alex_nmca_003[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x09C6, 0, 219, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09C7, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09C8, 0, 220, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x061F, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0620, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0621, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0622, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0623, 0, 222, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0624, 0, 222, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0625, 0, 222, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0626, 0, 222, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0627, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0628, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0629, 0, 223, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x062A, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x062B, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x061E, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 alex_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 alex_nmca_004[148] = {
    CMD(CM_RJA, 0, 4, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 277, 0, 0, 0, 0, 0x068D, 0, 225, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x0686, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0687, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0688, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0689, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 273, 0, 0, 0, 0, 0x068A, 0, 226, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x068B, 0, 227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x068C, 0, 227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x068D, 0, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 alex_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 alex_nmca_005[148] = {
    CMD(CM_RJA, 0, 5, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 277, 0, 0, 0, 0, 0x069F, 0, 228, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x06A0, 0, 229, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0692, 0, 229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0693, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0694, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0695, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0698, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0699, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 alex_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_nmca_006[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0630, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0631, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 alex_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_nmca_007[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x063C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063D, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063E, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063F, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0640, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0641, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0642, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0643, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0644, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0649, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 alex_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_nmca_008[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0645, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0646, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0647, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0648, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 alex_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_011[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0636, 0, 235, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0637, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 alex_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x0631, 0, 5, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0631, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0631, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 alex_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_013[28] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0631, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0632, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0632, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 alex_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 alex_nmca_014[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 0, 0x0650, 0, 237, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0651, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0652, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0653, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0654, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 alex_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 alex_nmca_015[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 0, 0x0650, 0, 237, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0651, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0652, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0653, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0654, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 alex_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_nmca_016[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 0, 0x065D, 0, 237, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x065E, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x065F, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0660, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0661, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0662, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0663, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0664, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0665, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0666, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0667, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0668, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x0669, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 alex_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 alex_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 alex_nmca_020_head[4] = { HEAD(6, 26, 0, 0, 0, 0, 0) };
const u16 alex_nmca_020[184] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 282, 0, 0, 0, 0, 0x0650, 0, 237, 0, 0, 0, 18, 2, 0, 0, 304, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0651, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0652, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0653, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0654, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 alex_nmca_021_head[4] = { HEAD(6, 28, 0, 0, 0, 0, 0) };
const u16 alex_nmca_021[184] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 282, 0, 0, 0, 0, 0x0650, 0, 237, 0, 0, 0, 18, 2, 0, 0, 304, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0651, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0652, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0653, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0654, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 alex_nmca_022_head[4] = { HEAD(6, 30, 0, 0, 0, 0, 0) };
const u16 alex_nmca_022[184] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 282, 0, 0, 0, 0, 0x065D, 0, 237, 0, 0, 0, 18, 2, 0, 0, 304, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065E, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065F, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0660, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0661, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0662, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0663, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0664, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0665, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0666, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0667, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0668, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x0669, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 alex_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_023[20] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 alex_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 alex_nmca_024[76] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x0766, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 935, 0, 0, 0, 0, 0x0767, 0, 1, 0, 0, 0, 6, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0768, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0769, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x078E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x078F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x074A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 alex_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 alex_nmca_026[60] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x09D0, 0, 4, 0, 0, 0, 18, 6),
    L4(1, 0, 935, 0, 0, 0, 0, 0x09D0, 0, 4, 0, 0, 0, 6, 1),
    L4(250, 0, 0, 0, 0, 0, 0, 0x09D1, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0646, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0647, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0648, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0648, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 alex_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 alex_nmca_027[220] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x0683, 0, 61, 0, 0, 0, 18, 6),
    L4(2, 0, 935, 0, 0, 0, 0, 0x0684, 0, 61, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0685, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0654, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1400, 0x0000, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0683, 0, 13, 0, 0, 0, 18, 6),
    L4(3, 0, 935, 0, 0, 0, 0, 0x0684, 0, 13, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0685, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0682, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0681, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0654, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0655, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 alex_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 alex_nmca_029[52] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0670, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0671, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0672, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0673, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0674, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0674, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 alex_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 alex_nmca_030[52] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0675, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0679, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 alex_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 alex_nmca_031[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x067B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x067C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x067D, 0, 4, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x067E, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x067F, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0680, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 alex_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 alex_nmca_032[148] = {
    L4(3, 4, 0, 0, 0, 0, 0, 0x0681, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0682, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0683, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0684, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x0685, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 alex_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 alex_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0669, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 alex_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_038[76] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 alex_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_nmca_040[76] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x067D, 0, 4, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x067C, 0, 4, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 alex_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0683, 0, 61, 0, 0, 0, 18, 8),
    L4(250, 0, 516, 0, 0, 0, 0, 0x0684, 0, 61, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 alex_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_043[76] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 alex_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_044[60] = {
    L4(4, 131, 0, 0, 0, 0, 0, 0x0866, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0867, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 1, 0, 0, 0, 0, 0, 0x0868, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 alex_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_nmca_045[100] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0683, 0, 61, 0, 0, 0, 0, 0),
    L4(250, 0, 935, 0, 0, 0, 0, 0x0684, 0, 61, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0653, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0663, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0664, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0665, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0666, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0667, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0668, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x0669, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 alex_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_nmca_046[84] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 132, 0, 0, 0, 0, 0, 0x0655, 0, 61, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0656, 0, 61, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 240, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 alex_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 alex_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 alex_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 alex_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 alex_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 alex_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_nmca_050[76] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const alex_dmca[99] = {
    alex_dmca_000,  /* 0 GUARD HEAD */
    alex_dmca_001,  /* 1 GUARD UP */
    alex_dmca_002,  /* 2 GUARD DOWN */
    alex_dmca_003,  /* 3 GUARD AIR */
    alex_dmca_004,  /* 4 HUSHIN HEAD */
    alex_dmca_004,  /* 5 HUSHIN UP */
    alex_dmca_006,  /* 6 HUSHIN DOWN */
    alex_dmca_006,  /* 7 HUSHIN AIR */
    alex_dmca_008,  /* 8 FACE S */
    alex_dmca_009,  /* 9 FACE M */
    alex_dmca_010,  /* 10 FACE L */
    alex_dmca_010,  /* 11 FACE SP */
    alex_dmca_008,  /* 12 FOOK OKU S */
    alex_dmca_009,  /* 13 FOOK OKU M */
    alex_dmca_014,  /* 14 FOOK OKU L */
    alex_dmca_014,  /* 15 FOOK OKU SP */
    alex_dmca_008,  /* 16 FOOK TEMAE S */
    alex_dmca_009,  /* 17 FOOK TEMAE M */
    alex_dmca_018,  /* 18 FOOK TEMAE L */
    alex_dmca_018,  /* 19 FOOK TEMAE SP */
    alex_dmca_008,  /* 20 UPPER S */
    alex_dmca_009,  /* 21 UPPER M */
    alex_dmca_022,  /* 22 UPPER L */
    alex_dmca_022,  /* 23 UPPER SP */
    alex_dmca_024,  /* 24 NOUTEN S */
    alex_dmca_025,  /* 25 NOUTEN M */
    alex_dmca_026,  /* 26 NOUTEN L */
    alex_dmca_026,  /* 27 NOUTEN SP */
    alex_dmca_024,  /* 28 BODY BROW S */
    alex_dmca_029,  /* 29 BODY BROW M */
    alex_dmca_030,  /* 30 BODY BROW L */
    alex_dmca_030,  /* 31 BODY BROW SP */
    alex_dmca_024,  /* 32 BODY UPPER S */
    alex_dmca_029,  /* 33 BODY UPPER M */
    alex_dmca_034,  /* 34 BODY UPPER L */
    alex_dmca_034,  /* 35 BODY UPPER SP */
    alex_dmca_036,  /* 36 TATAKI S */
    alex_dmca_037,  /* 37 TATAKI M */
    alex_dmca_038,  /* 38 TATAKI L */
    alex_dmca_039,  /* 39 TATAKI SP */
    alex_dmca_040,  /* 40 TATAKI V. S */
    alex_dmca_041,  /* 41 TATAKI V. M */
    alex_dmca_042,  /* 42 TATAKI V. L */
    alex_dmca_043,  /* 43 TATAKI V. SP */
    alex_dmca_008,  /* 44 NOBASITA TE S */
    alex_dmca_009,  /* 45 NOBASITA TE M */
    alex_dmca_010,  /* 46 NOBASITA TE L */
    alex_dmca_010,  /* 47 NOBASITA TE SP */
    alex_dmca_048,  /* 48 KAGAMI S */
    alex_dmca_049,  /* 49 KAGAMI M */
    alex_dmca_050,  /* 50 KAGAMI L */
    alex_dmca_050,  /* 51 KAGAMI SP */
    alex_dmca_052,  /* 52 KGM TATAKI S */
    alex_dmca_053,  /* 53 KGM TATAKI M */
    alex_dmca_054,  /* 54 KGM TATAKI L */
    alex_dmca_055,  /* 55 KGM TATAKI SP */
    alex_dmca_056,  /* 56 KGM TTKI V.S */
    alex_dmca_057,  /* 57 KGM TTKI V.M */
    alex_dmca_058,  /* 58 KGM TTKI V.L */
    alex_dmca_059,  /* 59 KGM TTKI V.SP */
    alex_dmca_060,  /* 60 NEKOROBI S */
    alex_dmca_060,  /* 61 NEKOROBI M */
    alex_dmca_060,  /* 62 NEKOROBI L */
    alex_dmca_060,  /* 63 NEKOROBI SP */
    alex_dmca_064,  /* 64 OKIAGARI */
    alex_dmca_065,  /* 65 OKIAGARI F */
    alex_dmca_066,  /* 66 OKIAGARI B */
    alex_dmca_067,  /* 67 LOSE NO STAND */
    alex_dmca_068,  /* 68 LOSE SONABA */
    alex_dmca_069,  /* 69 LOSE KAGAMI */
    alex_dmca_070,  /* 70 PIYO */
    alex_dmca_071,  /* 71 UKEMI MOVE F */
    alex_dmca_072,  /* 72 UKEMI MOVE R */
    alex_dmca_073,  /* 73 SHIMEOTASARE */
    alex_dmca_074,  /* 74 TATI TOUKETU S */
    alex_dmca_075,  /* 75 TATI TOUKETU M */
    alex_dmca_076,  /* 76 TATI TOUKETU L */
    alex_dmca_076,  /* 77 TATI TOUKETU P */
    alex_dmca_078,  /* 78 KGM TOUKETU S */
    alex_dmca_079,  /* 79 KGM TOUKETU M */
    alex_dmca_080,  /* 80 KGM TOUKETU L */
    alex_dmca_080,  /* 81 KGM TOUKETU P */
    alex_dmca_082,  /* 82 TATI DENGEKI S */
    alex_dmca_083,  /* 83 TATI DENGEKI M */
    alex_dmca_084,  /* 84 TATI DENGEKI L */
    alex_dmca_084,  /* 85 TATI DENGEKI P */
    alex_dmca_082,  /* 86 KGM DENGEKI S */
    alex_dmca_083,  /* 87 KGM DENGEKI M */
    alex_dmca_084,  /* 88 KGM DENGEKI L */
    alex_dmca_084,  /* 89 KGM DENGEKI P */
    alex_dmca_090,  /* 90 OKIAGARI FRONT */
    alex_dmca_091,  /* 91 OKIAGARI REAR */
    alex_dmca_008,  /* 92 TATI MOE S */
    alex_dmca_009,  /* 93 TATI MOE M */
    alex_dmca_010,  /* 94 TATI MOE L */
    alex_dmca_010,  /* 95 TATI MOE SP */
    alex_dmca_096,  /* 96 no name */
    alex_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 alex_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_000[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0671, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 132, 0, 0, 0, 0, 0, 0x0672, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0673, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0674, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0674, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0674, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 alex_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_001[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0679, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 alex_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_002[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x067D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x067C, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x067D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x067E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x067F, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0680, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0680, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 alex_dmca_003_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_003[136] = {
    L6(1, 131, 0, 0, 0, 0, 0, 0x0683, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0683, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 138, 0, 0, 0, 0, 0, 0x0684, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0685, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
    L6(250, 135, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0679, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 alex_dmca_004_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_004[76] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0676, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0693, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 alex_dmca_006_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_006[88] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x067C, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0693, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 alex_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 133, 0, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06A4, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x060F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 alex_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_009[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06A7, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x06A8, 0, 180, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x06A9, 0, 180, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06AA, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06A3, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06A4, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x060F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 alex_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_010[116] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x06AB, 0, 179, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06AC, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 136, 930, 0, 0, 0, 0, 0x06AC, 0, 180, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06AD, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x06AE, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06AF, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06B1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 alex_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_014[140] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x06AB, 0, 179, 0, 0, 0, 0, 0),
    L4(250, 0, 930, 0, 0, 0, 0, 0x06AC, 0, 180, 0, 0, 0, 0, 0),
    L4(1, 139, 0, 0, 0, 0, 0, 0x06AD, 0, 180, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x06AE, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 11, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x06BB, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x06BC, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x06B8, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x06B9, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x06BA, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06B1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 alex_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_018[148] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x06B2, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 930, 0, 0, 0, 0, 0x06B3, 0, 180, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06B4, 0, 181, 0, 0, 0, 0, 0),
    L4(1, 140, 0, 0, 0, 0, 0, 0x06B5, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x06B5, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x06B6, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x06B7, 0, 182, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x06B8, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x06B9, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x06BA, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06B1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 alex_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_022[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06E2, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 135, 930, 0, 0, 0, 0, 0x06E3, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E4, 0, 176, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F8, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x06F9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06B1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 alex_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_025[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 136, 0, 0, 0, 0, 0, 0x06F1, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F3, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F4, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F5, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F6, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06F7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 alex_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06F1, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 137, 930, 0, 0, 0, 0, 0x06F1, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F2, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06F3, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F4, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F5, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F6, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 25, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 alex_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_024[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06FA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 133, 0, 0, 0, 0, 0, 0x06FF, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F6, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x06F7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 alex_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_029[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 137, 0, 0, 0, 0, 0, 0x06FB, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06FC, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x06FD, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06FE, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06FF, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F6, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x06F7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 alex_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_030[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0700, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 138, 930, 0, 0, 0, 0, 0x0701, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0702, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0703, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0704, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0705, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0706, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0707, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0708, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06F7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 alex_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_034[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06E1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 136, 930, 0, 0, 0, 0, 0x06E2, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06E3, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E4, 0, 176, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x06F8, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x06F9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 22, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S */
const u16 alex_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_036[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 6, 0x08F5, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x08F7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 TATAKI M */
const u16 alex_dmca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_037[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 6, 0x08F5, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x08F7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 TATAKI L */
const u16 alex_dmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_038[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 6, 0x08F5, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x08F7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 TATAKI SP */
const u16 alex_dmca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_039[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 931, 0, 0, 0, 6, 0x08F5, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x08F7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 TATAKI V. S */
const u16 alex_dmca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_040[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 0, 931, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x08A6, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 TATAKI V. M */
const u16 alex_dmca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_041[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x08A6, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 TATAKI V. L */
const u16 alex_dmca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_042[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x08A6, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TATAKI V. SP */
const u16 alex_dmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_043[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x06F1, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x08A6, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 alex_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_048[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 133, 0, 0, 0, 0, 0, 0x0711, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0712, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0713, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 alex_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_049[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0715, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x0716, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0717, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0718, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0712, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0713, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 alex_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_050[100] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x0719, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x071A, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 136, 930, 0, 0, 0, 0, 0x071B, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x071C, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x071D, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0645, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0646, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0647, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0648, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S */
const u16 alex_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_052[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x08F9, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08FA, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 KGM TATAKI M */
const u16 alex_dmca_053_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_053[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08F9, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08FA, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 KGM TATAKI L */
const u16 alex_dmca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_054[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08F9, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08FA, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 KGM TATAKI SP */
const u16 alex_dmca_055_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_055[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 931, 0, 0, 0, 0, 0x08F9, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08FA, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 KGM TTKI V.S */
const u16 alex_dmca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_056[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x08A6, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 KGM TTKI V.M */
const u16 alex_dmca_057_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_057[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08A6, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 KGM TTKI V.L */
const u16 alex_dmca_058_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_058[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 931, 0, 0, 0, 0, 0x08A6, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 KGM TTKI V.SP */
const u16 alex_dmca_059_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_059[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(5, 0, 931, 0, 0, 0, 0, 0x08A6, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 alex_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_060[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x08A7, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 2, 930, 0, 0, 0, 0, 0x08A8, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x08A9, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D4, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D5, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x06D6, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x06D7, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 alex_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_064[180] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08D7, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DA, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DB, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DC, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x08DF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08E0, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0637, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 alex_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_065[100] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D7, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0828, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0829, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x082D, 0, 60, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x08E0, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 alex_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_066[92] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0827, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0832, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0833, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0834, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0830, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0831, 0, 60, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0636, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 alex_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 alex_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_068[220] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x06A1, 0, 156, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x06A1, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x0730, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0731, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x0732, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0733, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0734, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0735, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0737, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x0738, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0739, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x073E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 alex_dmca_069_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_069[36] = {
    CMD(CM_ASXY, 210, 0, 0), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06FA, 0, 156, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x06FA, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 68, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 alex_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0709, 0, 146, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x070A, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x070B, 0, 147, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x070C, 0, 148, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x070D, 0, 148, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x070E, 0, 146, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x070F, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 alex_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_071[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0827, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 4096, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 935, 0, 0, 0, 0, 0x0828, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x082E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0829, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x082A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x082B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x082C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x082D, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x08E0, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 alex_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_072[124] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0827, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -5120, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(4, 1, 935, 0, 0, 0, 0, 0x0834, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x082F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0830, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x0636, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0637, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 alex_dmca_073_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_073[196] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0730, 0, 156, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0731, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x0732, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0733, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0734, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0735, 0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0737, 0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x0738, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0739, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x073C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x073D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x073E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x073E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 alex_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_074[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x06A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 alex_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_075[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x06A1, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x06A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 alex_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_076[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06A1, 0, 179, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x06A1, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x06A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x060F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06A6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 alex_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_078[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x0710, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0713, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 alex_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_079[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0715, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x0715, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0713, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 alex_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0719, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 131, 930, 0, 0, 0, 0, 0x0719, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0713, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 alex_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_082[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0938, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0939, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 930, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 alex_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_083[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0938, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0939, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 930, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 alex_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_dmca_084[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0938, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0937, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0939, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 930, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 alex_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_090[92] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D7, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0828, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0829, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x082D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 alex_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_091[92] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0827, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0832, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0833, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0834, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x082F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0830, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0831, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0636, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 alex_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_096[44] = {
    L4(3, 2, 930, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 62, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 alex_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_dmca_097[44] = {
    L4(3, 2, 930, 0, 0, 0, 0, 0x06D9, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D9, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x06D9, 0, 170, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const alex_btca[37] = {
    alex_btca_000,  /* 0 AIR NORMAL */
    alex_btca_001,  /* 1 ASIBARAI SIRI */
    alex_btca_002,  /* 2 ASIB TUNNOMERI */
    alex_btca_003,  /* 3 NOKEZORI */
    alex_btca_004,  /* 4 KUNOJI */
    alex_btca_005,  /* 5 KIRIMOMI */
    alex_btca_006,  /* 6 UPPER */
    alex_btca_007,  /* 7 BODY UPPER */
    alex_btca_008,  /* 8 HARAYARARE */
    alex_btca_009,  /* 9 TATAKI AIR */
    alex_btca_010,  /* 10 TTKI V. AIR */
    alex_btca_011,  /* 11 HUMI ASIB */
    alex_btca_012,  /* 12 FACE */
    alex_btca_013,  /* 13 ASIB SIRI LOSE */
    alex_btca_014,  /* 14 ASIB TUN LOSE */
    alex_btca_015,  /* 15 DENKI */
    alex_btca_016,  /* 16 KUNOJI NOKE */
    alex_btca_017,  /* 17 BODY UPPER SP */
    alex_btca_018,  /* 18 HANEAGARI */
    alex_btca_019,  /* 19 TOUKETSU A */
    alex_btca_020,  /* 20 BODY SLAM */
    alex_btca_021,  /* 21 IPPONZEOI */
    alex_btca_022,  /* 22 TOMOE RYU */
    alex_btca_023,  /* 23 MONKEY FLIP */
    alex_btca_024,  /* 24 TOMOE ORO */
    alex_btca_025,  /* 25 SNAKE FANG */
    alex_btca_026,  /* 26 FLANKEN.S */
    alex_btca_027,  /* 27 KISHINRIKI */
    alex_btca_028,  /* 28 SPLASH.M */
    alex_btca_029,  /* 29 HARAIGOSHI */
    alex_btca_030,  /* 30 ALEX B.D */
    alex_btca_031,  /* 31 GILL */
    alex_btca_032,  /* 32 HANEKAERI HARA */
    alex_btca_033,  /* 33 S HANEAGARI */
    alex_btca_034,  /* 34 TATUMAKIZANKU */
    alex_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 alex_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_000[68] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x08EE, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 930, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x08EE, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x08EF, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 alex_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_001[76] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x08CC, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x08CD, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x08CE, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x08CF, 0, 257, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x08D0, 0, 258, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D1, 0, 259, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x08D2, 0, 260, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 alex_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 alex_btca_002[44] = {
    CMD(CM_RJA, 7, 33, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06EE, 0, 261, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x06EF, 0, 262, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06EF, 0, 262, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 alex_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_003[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06C0, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06C1, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C2, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C3, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 269, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0926, 0, 272, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 alex_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_004[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06DA, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 5, 0x06DB, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x06DC, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x06DD, 0, 276, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 10, 0x06DE, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 alex_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_005[140] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06B2, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06B3, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0720, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0721, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0722, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0723, 0, 283, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0724, 0, 284, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0725, 0, 285, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0726, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0727, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0728, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0729, 0, 289, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x072A, 0, 290, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x072B, 0, 291, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x072C, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 alex_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_006[140] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06E1, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06E2, 0, 294, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E3, 0, 295, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E4, 0, 296, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C1, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C2, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C3, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 269, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0926, 0, 272, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 alex_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_007[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x08C0, 0, 297, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08C1, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C2, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C3, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C4, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C5, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C6, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C7, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C8, 0, 305, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C9, 0, 306, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CA, 0, 307, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D9, 0, 308, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 alex_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_008[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06E1, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08C4, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C5, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C6, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C7, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C8, 0, 305, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CA, 0, 307, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D9, 0, 308, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 alex_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_009[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06E1, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x08F5, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F6, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F7, 0, 312, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x08F8, 0, 313, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 alex_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_010[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06F0, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x06F1, 0, 315, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x08A6, 0, 316, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 alex_btca_011_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_011[44] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06EE, 0, 261, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06EE, 0, 261, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06EF, 0, 262, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 alex_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_012[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06A1, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06C1, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C5, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C6, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C7, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C8, 0, 305, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CA, 0, 307, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D9, 0, 308, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 alex_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 alex_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 alex_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 alex_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_015[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 135, 0, 0, 0, 0, 0, 0x0937, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0938, 0, 318, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0937, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0939, 0, 318, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 alex_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_016[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06DA, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06DB, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06DC, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06DD, 0, 276, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06DE, 0, 277, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 269, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 271, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0926, 0, 272, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 alex_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_017[172] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x06C0, 0, 263, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 931, 0, 0, 0, 0, 0x06C1, 0, 264, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x06C2, 0, 265, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x06C3, 0, 266, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 267, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 268, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 269, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 270, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 271, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 272, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0926, 0, 272, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 alex_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(3, 0, 931, 0, 0, 0, 5, 0x06C9, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x06C8, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 7, 0x06C7, 0, 60, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 9, 0x06C6, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x06C5, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 alex_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06A1, 0, 317, 0, 0, 0, 0, 0),
    L4(250, 0, 931, 0, 0, 0, 0, 0x06A1, 0, 317, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 alex_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x08F7, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 alex_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_021[12] = {
    L4(250, 0, 0, 0, 1, 0, 0, 0x0739, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 alex_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_022[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x06EF, 0, 74, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x088C, 0, 74, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x088B, 0, 74, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 74, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 74, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 alex_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0816, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0926, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08CA, 0, 74, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x08F7, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 alex_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D2, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D1, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08C9, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08C9, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 alex_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 74, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 74, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 alex_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x088B, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06D3, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06D6, 0, 74, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06D6, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 alex_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_027[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x06C4, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x06C5, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x06C6, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x06C7, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x06C8, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0926, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 alex_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_028[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 alex_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_029[108] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06C0, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06C1, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C2, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C3, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0926, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 alex_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_030[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x08C0, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x08C1, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C2, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C3, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C4, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C5, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C6, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C7, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C8, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C9, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CA, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08CB, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D9, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 alex_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_031[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x08CC, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x08CD, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08CE, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08CF, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D0, 0, 74, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x08D1, 0, 74, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x08D2, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 alex_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x06E1, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08C4, 0, 301, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 alex_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_033[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 931, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 285, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 22, 38),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 alex_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_btca_034[140] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x06E1, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 931, 0, 0, 0, 0, 0x06E2, 0, 294, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E3, 0, 295, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06E4, 0, 296, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C1, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C2, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C3, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C4, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C5, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C6, 0, 269, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C7, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C8, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x06C9, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0926, 0, 272, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 37 entries */
const u16* const alex_caca[38] = {
    alex_caca_000,  /* 0 CATCH 1 */
    alex_caca_001,  /* 1 CATCH 2 */
    alex_caca_002,  /* 2 CATCH 3 */
    alex_caca_002,  /* 3 CATCH 4 */
    alex_caca_002,  /* 4 CATCH 5 */
    alex_caca_002,  /* 5 CATCH 6 */
    alex_caca_006,  /* 6 CATCH 7 */
    alex_caca_007,  /* 7 CATCH 8 */
    alex_caca_008,  /* 8 CATCH 9 */
    alex_caca_008,  /* 9 CATCH 10 */
    alex_caca_010,  /* 10 CATCH 11 */
    alex_caca_011,  /* 11 CATCH 12 */
    alex_caca_012,  /* 12 CATCH 13 */
    alex_caca_012,  /* 13 CATCH 14 */
    alex_caca_014,  /* 14 CATCH 15 */
    alex_caca_014,  /* 15 CATCH 16 */
    alex_caca_014,  /* 16 CATCH 17 */
    alex_caca_014,  /* 17 CATCH 18 */
    alex_caca_018,  /* 18 CATCH 19 */
    alex_caca_019,  /* 19 CATCH 20 */
    alex_caca_020,  /* 20 CATCH 21 */
    alex_caca_021,  /* 21 CATCH 22 */
    alex_caca_022,  /* 22 CATCH 23 */
    alex_caca_023,  /* 23 CATCH 24 */
    alex_caca_023,  /* 24 CATCH 25 */
    alex_caca_023,  /* 25 CATCH 26 */
    alex_caca_023,  /* 26 CATCH 27 */
    alex_caca_027,  /* 27 CATCH 28 */
    alex_caca_028,  /* 28 CATCH 29 */
    alex_caca_029,  /* 29 CATCH 30 */
    alex_caca_030,  /* 30 CATCH 31 */
    alex_caca_031,  /* 31 CATCH 32 */
    alex_caca_032,  /* 32 CATCH 33 */
    alex_caca_033,  /* 33 CATCH 34 */
    alex_caca_033,  /* 34 CATCH 35 */
    alex_caca_033,  /* 35 CATCH 36 */
    alex_caca_033,  /* 36 CATCH 37 */
    0
};

/* script: 0 CATCH 1 */
const u16 alex_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 alex_caca_000[172] = {
    CMD(CM_NGDA, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 0, 0, 0, 0, 0, 0, 0x077F, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0784, 0, 0, 0, 0, 0, 0, 0, 0, 48, 164, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0785, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(5, 0, 934, 0, 0, 0, 0, 0x0786, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 2, 0, 0, 0, 0, 0, 0x0787, -34, 0, 0, 0, 0, 0, 0, 0, 120, 166, 0, 0),
    L6(16, 3, 0, 0, 0, 0, 0, 0x0789, 0, 0, 0, 0, 0, 0, 0, 0, 144, 168, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x078A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x078B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x078C, 0, 1, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x078D, 0, 1, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x068F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 alex_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 alex_caca_001[268] = {
    CMD(CM_NGDA, 0, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 1128, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 1152, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x089C, 0, 0, 0, 0, 0, 0, 0, 0, 1176, 0, 0, 0),
    L6(3, 0, 936, 0, 0, 0, 0, 0x089D, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 29, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 30, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 31, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 74, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 4, 0, 0x08A1, 0, 0, 0, 0, 0, 0, 0, 0, 1296, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 4, 0, 0x08A1, 0, 0, 0, 0, 0, 0, 0, 0, 1320, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 4, 0, 0x08A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0675, 0, 1, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0675, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3, 3 CATCH 4, 4 CATCH 5, 5 CATCH 6 */
const u16 alex_caca_002_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 alex_caca_002[244] = {
    CMD(CM_NGDA, 1542, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x0869, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x086A, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x086B, 0, 0, 0, 0, 0, 0, 0, 0, 240, 104, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x086C, 0, 0, 0, 0, 0, 0, 0, 0, 264, 104, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x086D, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x086E, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 933, 0, 0, 0, 0, 0x086F, 0, 0, 0, 0, 0, 0, 0, 0, 336, 106, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0870, 0, 0, 0, 0, 0, 0, 0, 0, 360, 108, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x0871, -40, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x0872, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0873, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0874, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0875, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0876, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0877, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 6, 0, 0, 1, 0, 0, 0x0879, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x087A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x087B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x087B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 alex_caca_006_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 alex_caca_006[304] = {
    CMD(CM_NGDA, 6, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 6, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 792, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 840, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 864, 292, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 888, 294, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0890, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0891, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(3, 20, 937, 0, 0, 0, 0, 0x0892, 0, 0, 0, 0, 0, 30, 99, 0, 984, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0893, 0, 0, 0, 0, 0, 30, 100, 0, 1008, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0894, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0895, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0896, -37, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 2112, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0898, 0, 0, 0, 0, 0, 0, 0, 0, 2136, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 68, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 1, 0, 0, 0, 0, 0, 0x065D, 0, 13, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    CMD(CM_JMP, 0, 16, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 alex_caca_007_head[4] = { HEAD(6, 0, 26, 0, 0, 0, 0) };
const u16 alex_caca_007[268] = {
    CMD(CM_NGDA, 6, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 7, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 792, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 840, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 864, 292, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 888, 294, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0890, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0891, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(4, 20, 937, 0, 0, 0, 0, 0x0892, 0, 0, 0, 0, 0, 30, 101, 0, 984, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0893, 0, 0, 0, 0, 0, 30, 102, 0, 1008, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0894, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0895, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0896, -54, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(14, 4, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 2112, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0898, 0, 0, 0, 0, 0, 0, 0, 0, 2136, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 69, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 6, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9, 9 CATCH 10 */
const u16 alex_caca_008_head[4] = { HEAD(6, 0, 28, 0, 0, 0, 0) };
const u16 alex_caca_008[268] = {
    CMD(CM_NGDA, 6, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 8, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 792, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 840, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 864, 292, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 888, 294, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 296, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0890, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0891, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x0892, 0, 0, 0, 0, 0, 30, 103, 0, 984, 0, 0, 0),
    L6(6, 0, 937, 0, 0, 0, 0, 0x0893, 0, 0, 0, 0, 0, 30, 104, 0, 1008, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0894, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0895, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0896, -55, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(16, 4, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 2112, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0898, 0, 0, 0, 0, 0, 0, 0, 0, 2136, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 70, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 6, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11 */
const u16 alex_caca_010_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 alex_caca_010[352] = {
    CMD(CM_NGDA, 6, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 504, 354, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 528, 356, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 552, 358, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 600, 360, 0, 0),
    L6(3, 0, 932, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 624, 362, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 648, 364, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 672, 366, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0883, -36, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x0884, 0, 0, 0, 0, 0, 0, 0, 0, 720, 368, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 744, 370, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 CATCH 12 */
const u16 alex_caca_011_head[4] = { HEAD(6, 0, 26, 0, 0, 0, 0) };
const u16 alex_caca_011[352] = {
    CMD(CM_NGDA, 6, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 504, 354, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 528, 356, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 552, 358, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 600, 360, 0, 0),
    L6(3, 0, 932, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 624, 362, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 648, 364, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 672, 366, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0883, -82, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x0884, 0, 0, 0, 0, 0, 0, 0, 0, 720, 368, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 744, 370, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14 */
const u16 alex_caca_012_head[4] = { HEAD(6, 0, 28, 0, 0, 0, 0) };
const u16 alex_caca_012[352] = {
    CMD(CM_NGDA, 6, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 504, 354, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 528, 356, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 552, 358, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 600, 360, 0, 0),
    L6(3, 0, 932, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 624, 362, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 648, 364, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 672, 366, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0883, -83, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x0884, 0, 0, 0, 0, 0, 0, 0, 0, 720, 368, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 744, 370, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16, 16 CATCH 17, 17 CATCH 18 */
const u16 alex_caca_014_head[4] = { HEAD(6, 0, 40, 0, 0, 0, 0) };
const u16 alex_caca_014[256] = {
    CMD(CM_NGDA, 0, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x077F, 0, 0, 0, 0, 0, 18, 5, 0, 2208, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0784, 0, 0, 0, 0, 0, 0, 0, 0, 2232, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0785, 0, 0, 0, 0, 0, 0, 0, 0, 2256, 0, 0, 0),
    L6(2, 2, 936, 0, 0, 0, 0, 0x0787, -56, 0, 0, 0, 0, 0, 0, 0, 2304, 166, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0789, 0, 0, 0, 0, 0, 0, 0, 0, 2328, 384, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x078A, 0, 0, 0, 0, 0, 0, 0, 0, 2352, 386, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0784, 0, 0, 0, 0, 0, 0, 0, 0, 2232, 382, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0785, 0, 0, 0, 0, 0, 0, 0, 0, 2256, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0786, 0, 0, 0, 0, 0, 0, 0, 0, 2280, 0, 0, 0),
    L6(10, 2, 0, 0, 0, 0, 0, 0x0787, -57, 0, 0, 0, 0, 0, 0, 0, 2304, 166, 0, 0),
    L6(12, 3, 936, 0, 0, 0, 0, 0x0789, 0, 0, 0, 0, 0, 0, 0, 0, 2328, 384, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x078A, 0, 0, 0, 0, 0, 0, 0, 0, 2424, 386, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x078B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x078C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x078D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x068F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 CATCH 19 */
const u16 alex_caca_018_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 alex_caca_018[640] = {
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NGDA, 0, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 18, 43), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 1368, 218, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 30, 25, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 222, 0, 0),
    L6(3, 0, 932, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 1440, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 1464, 226, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 230, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 232, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 234, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 236, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0883, -46, 0, 0, 0, 0, 0, 0, 0, 1608, 238, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 30, 24, 0, 1632, 242, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 244, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 246, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 0, 0, 0, 0, 0, 0, 0, 1680, 248, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 0, 0, 0, 0, 0, 0, 0, 1704, 250, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 0, 0, 0, 0, 0, 0, 0, 1728, 252, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 0, 0, 0, 0, 0, 0, 0, 1752, 254, 0, 0),
    L6(3, 0, 933, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 30, 26, 0, 1464, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 258, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 260, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 262, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 264, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 266, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0883, -47, 0, 0, 0, 0, 0, 0, 0, 1608, 268, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 30, 24, 0, 1632, 272, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 274, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 276, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 0, 0, 0, 0, 0, 0, 0, 1776, 278, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 0, 0, 0, 0, 0, 0, 0, 1800, 280, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 282, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 0, 0, 0, 0, 0, 0, 0, 1848, 284, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 30, 26, 256, 1872, 286, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0890, 0, 0, 0, 0, 0, 0, 0, 256, 1896, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0891, 0, 0, 0, 0, 0, 0, 0, 256, 1920, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x0892, 0, 0, 0, 0, 0, 30, 103, 256, 1944, 0, 0, 0),
    L6(7, 0, 934, 0, 0, 0, 0, 0x0893, 0, 0, 0, 0, 0, 30, 104, 256, 1968, 0, 0, 0),
    L6(250, 0, 940, 0, 0, 0, 0, 0x0894, 0, 0, 0, 0, 0, 0, 0, 256, 1992, 0, 0, 0),
    CMD(CM_QUAY, 32, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0895, 0, 0, 0, 0, 0, 30, 27, 256, 2016, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x0896, -48, 0, 0, 0, 0, 0, 0, 256, 2040, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 256, 2064, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x0898, 0, 0, 0, 0, 0, 0, 0, 256, 2088, 0, 0, 0),
    L6(16, 4, 0, 0, 0, 0, 0, 0x0899, 0, 0, 0, 0, 0, 0, 0, 256, 2160, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x089A, 0, 0, 0, 0, 0, 0, 0, 0, 2184, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 72, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 6, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 CATCH 20 */
const u16 alex_caca_019_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 alex_caca_019[388] = {
    CMD(CM_NGDA, 6, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 19, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0843, 0, 0, 0, 0, 0, 0, 0, 0, 2568, 0, 0, 0),
    L6(3, 0, 933, 0, 0, 0, 0, 0x0844, 0, 0, 0, 0, 0, 0, 0, 0, 2592, 0, 0, 0),
    CMD(CM_MXYT, 65, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 1, 0, 0, 0, 0, 0, 0x0845, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0847, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 9, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x0847, -60, 0, 0, 0, 0, 0, 0, 0, 2664, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0848, 0, 0, 0, 0, 0, 0, 0, 0, 2688, 426, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0849, 0, 0, 0, 0, 0, 0, 0, 0, 2712, 426, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x084A, 0, 0, 0, 0, 0, 0, 0, 0, 2736, 426, 0, 0),
    L6(8, 4, 0, 0, 0, 0, 0, 0x084B, 0, 0, 0, 0, 0, 0, 0, 0, 2736, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x084C, 0, 0, 0, 0, 0, 0, 0, 0, 2736, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x084D, 0, 0, 0, 0, 0, 0, 0, 0, 2736, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x084E, 0, 0, 0, 0, 0, 0, 0, 0, 2760, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x084F, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0850, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 410, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0832, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 412, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0833, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 414, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0834, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 416, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x082F, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 418, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0830, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 420, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0636, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 422, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 CATCH 21 */
const u16 alex_caca_020_head[4] = { HEAD(6, 0, 27, 0, 0, 0, 0) };
const u16 alex_caca_020[148] = {
    CMD(CM_NGDA, 6, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 20, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0843, 0, 0, 0, 0, 0, 0, 0, 0, 2568, 0, 0, 0),
    L6(4, 0, 933, 0, 0, 0, 0, 0x0844, 0, 0, 0, 0, 0, 0, 0, 0, 2592, 0, 0, 0),
    CMD(CM_MXYT, 66, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 1, 0, 0, 0, 0, 0, 0x0845, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0847, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 9, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x0847, -62, 0, 0, 0, 0, 0, 0, 0, 2664, 0, 0, 0),
    CMD(CM_JPSS, 2, 19, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 CATCH 22 */
const u16 alex_caca_021_head[4] = { HEAD(6, 0, 29, 0, 0, 0, 0) };
const u16 alex_caca_021[148] = {
    CMD(CM_NGDA, 6, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 21, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0843, 0, 0, 0, 0, 0, 0, 0, 0, 2568, 0, 0, 0),
    L6(5, 0, 933, 0, 0, 0, 0, 0x0844, 0, 0, 0, 0, 0, 0, 0, 0, 2592, 0, 0, 0),
    CMD(CM_MXYT, 67, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 1, 0, 0, 0, 0, 0, 0x0845, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0847, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 256, 2640, 0, 9, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x0847, -63, 0, 0, 0, 0, 0, 0, 0, 2664, 0, 0, 0),
    CMD(CM_JPSS, 2, 19, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 CATCH 23 */
const u16 alex_caca_022_head[4] = { HEAD(6, 0, 31, 0, 0, 0, 0) };
const u16 alex_caca_022[148] = {
    CMD(CM_NGDA, 6, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 21, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0843, 0, 0, 0, 0, 0, 0, 0, 0, 2568, 0, 0, 0),
    L6(5, 0, 933, 0, 0, 0, 0, 0x0844, 0, 0, 0, 0, 0, 0, 0, 0, 2592, 0, 0, 0),
    CMD(CM_MXYT, 80, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 1, 0, 0, 0, 0, 0, 0x0845, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 0, 2640, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0847, 0, 0, 0, 0, 0, 0, 0, 0, 2616, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 0, 0, 0, 0, 0, 0, 256, 2640, 0, 9, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x0847, -86, 0, 0, 0, 0, 0, 0, 0, 2664, 0, 0, 0),
    CMD(CM_JPSS, 2, 19, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 CATCH 24, 24 CATCH 25, 25 CATCH 26, 26 CATCH 27 */
const u16 alex_caca_023_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 alex_caca_023[88] = {
    CMD(CM_NGDA, 1542, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x0869, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x086A, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x086B, 0, 0, 0, 0, 0, 0, 0, 0, 240, 104, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x086C, 0, 0, 0, 0, 0, 0, 0, 0, 264, 104, 0, 0),
    L6(6, 6, 0, 0, 0, 0, 0, 0x086D, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 CATCH 28 */
const u16 alex_caca_027_head[4] = { HEAD(6, 0, 48, 0, 0, 0, 0) };
const u16 alex_caca_027[268] = {
    CMD(CM_NGDA, 0, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 27, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 18, 5, 0, 792, 288, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 840, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 864, 292, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 888, 294, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 296, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0890, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0891, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(4, 20, 937, 0, 0, 0, 0, 0x0892, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0893, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0894, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0895, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0896, -54, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(14, 4, 0, 0, 0, 0, 0, 0x0897, 0, 0, 0, 0, 0, 0, 0, 0, 2112, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x0898, 0, 0, 0, 0, 0, 0, 0, 0, 2136, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 70, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 6, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 CATCH 29 */
const u16 alex_caca_028_head[4] = { HEAD(6, 0, 48, 0, 0, 0, 0) };
const u16 alex_caca_028[352] = {
    CMD(CM_NGDA, 0, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 18, 5, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 504, 354, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 528, 356, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 552, 358, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 600, 360, 0, 0),
    L6(3, 0, 932, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 624, 362, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 648, 364, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0882, -76, 0, 0, 0, 0, 0, 0, 0, 672, 366, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0883, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x0884, 0, 0, 0, 0, 0, 0, 0, 0, 2784, 368, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0886, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0887, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0888, 0, 1, 0, 0, 0, 0, 0, 0, 0, 370, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x088C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x088E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x088F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 CATCH 30 */
const u16 alex_caca_029_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 alex_caca_029[112] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x0601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 2, 0, 0x089F, -41, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 2, 0, 0x089F, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(6, 4, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 CATCH 31 */
const u16 alex_caca_030_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 alex_caca_030[112] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x0601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 2, 0, 0x089F, -41, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 2, 0, 0x089F, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 CATCH 32 */
const u16 alex_caca_031_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 alex_caca_031[112] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x0601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x089E, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 2, 0, 0x089F, -41, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x089F, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 3, 0, 0x08A0, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 32 CATCH 33 */
const u16 alex_caca_032_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 alex_caca_032[748] = {
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NGDA, 0, 47, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0862, 0, 0, 0, 0, 0, 0, 0, 0, 1368, 218, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0863, 0, 0, 0, 0, 0, 30, 25, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0864, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0865, 0, 0, 0, 0, 0, 0, 0, 0, 1440, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 0, 0, 0, 1464, 226, 0, 0),
    L6(3, 0, 935, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 228, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 230, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 232, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 234, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 236, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0883, -95, 0, 0, 0, 0, 0, 0, 0, 1608, 238, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 30, 24, 0, 1632, 242, 0, 0),
    L6(8, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 244, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 246, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x088A, 0, 0, 0, 0, 0, 0, 0, 0, 1680, 248, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088B, 0, 0, 0, 0, 0, 0, 0, 0, 1704, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088C, 0, 0, 0, 0, 0, 0, 0, 0, 1728, 252, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088D, 0, 0, 0, 0, 0, 0, 0, 0, 1752, 254, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 935, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 30, 26, 0, 1464, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 258, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 260, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 266, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x0883, -96, 0, 0, 0, 0, 0, 0, 0, 1608, 268, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 30, 24, 0, 1632, 272, 0, 0),
    L6(6, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 274, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 276, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088A, 0, 0, 0, 0, 0, 0, 0, 0, 1776, 278, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088B, 0, 0, 0, 0, 0, 0, 0, 0, 1800, 280, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088C, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 282, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x088D, 0, 0, 0, 0, 0, 0, 0, 0, 1848, 284, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 937, 0, 0, 0, 0, 0x087C, 0, 0, 0, 0, 0, 30, 26, 0, 1464, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087E, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 258, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x087F, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 260, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0880, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 262, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0881, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 264, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x0882, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 266, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0883, -97, 0, 0, 0, 0, 0, 0, 0, 2808, 0, 0, 0),
    CMD(CM_QUAY, 32, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 3, 0, 0, 0, 0, 0, 0x0884, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 368, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x0886, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 0, 0, 0),
    L6(18, 4, 0, 0, 0, 0, 0, 0x0887, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 0, 0, 0x0888, 0, 0, 0, 0, 0, 0, 0, 0, 2856, 370, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x088F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 CATCH 34, 34 CATCH 35, 35 CATCH 36, 36 CATCH 37 */
const u16 alex_caca_033_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 alex_caca_033[376] = {
    CMD(CM_NGDA, 6, 62, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 47, 0, 0x0997, 0, 0, 0, 0, 0, 0, 0, 0, 2880, 0, 0, 0),
    L6(3, 0, 932, 0, 0, 48, 0, 0x0999, 0, 0, 0, 0, 0, 0, 0, 0, 2904, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 49, 0, 0x099B, 0, 0, 0, 0, 0, 0, 0, 0, 2928, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 50, 0, 0x099D, 0, 0, 0, 0, 0, 0, 0, 0, 2952, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 51, 0, 0x099F, 0, 0, 0, 0, 0, 0, 0, 0, 2976, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x09A1, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x09A2, 0, 0, 0, 0, 0, 0, 0, 0, 3024, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x09A3, 0, 0, 0, 0, 0, 0, 0, 0, 3048, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 52, 0, 0x09A5, 0, 0, 0, 0, 0, 0, 0, 0, 3072, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x09C9, 0, 0, 0, 0, 0, 0, 0, 0, 3096, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x09A6, -99, 0, 0, 0, 0, 0, 0, 0, 3120, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 3, 0, 2, 0, 0, 0, 0x09A7, 0, 0, 0, 0, 0, 0, 0, 0, 3144, 0, 0, 0),
    L6(5, 4, 0, 2, 0, 0, 0, 0x09A8, 0, 0, 0, 0, 0, 0, 0, 0, 3168, 0, 0, 0),
    L6(5, 4, 0, 2, 0, 0, 0, 0x09A9, 0, 0, 0, 0, 0, 0, 0, 0, 3192, 0, 0, 0),
    L6(7, 9, 0, 2, 0, 0, 0, 0x09AA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 2, 0, 0, 0, 0x09AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 1, 0, 0, 0x08DA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 1, 0, 0, 0x08DB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 1, 0, 0, 0x08DC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 1, 0, 0, 0x08DD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 1, 0, 0, 0x08DE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x08E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 2, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 2, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const alex_cuca[69] = {
    alex_cuca_000,  /* 0 ALEX ZUTUKI */
    alex_cuca_001,  /* 1 ALEX BODY S */
    alex_cuca_002,  /* 2 ALEX BACK D */
    alex_cuca_003,  /* 3 ALEX POWER B */
    alex_cuca_004,  /* 4 ALEX SLEEPER */
    alex_cuca_005,  /* 5 RYU SEOINAGE */
    alex_cuca_006,  /* 6 IBUKI */
    alex_cuca_007,  /* 7 DADLEY L B */
    alex_cuca_008,  /* 8 IBUKI KUBIORI */
    alex_cuca_009,  /* 9 NECRO S T */
    alex_cuca_010,  /* 10 RYU TOMOENAGE */
    alex_cuca_011,  /* 11 YUN HIZAGERI */
    alex_cuca_012,  /* 12 ORO KUBISIME */
    alex_cuca_013,  /* 13 NECRO G S */
    alex_cuca_014,  /* 14 DUDDLEY D S */
    alex_cuca_015,  /* 15 YUN MONKEY F */
    alex_cuca_016,  /* 16 ORO TOMOENAGE */
    alex_cuca_017,  /* 17 ORO NIOURIKI */
    alex_cuca_018,  /* 18 ORO GIGOKU G */
    alex_cuca_019,  /* 19 YUN */
    alex_cuca_020,  /* 20 NECRO SNAKE F */
    alex_cuca_021,  /* 21 NECRO F S */
    alex_cuca_022,  /* 22 IBUKI HARAIG */
    alex_cuca_023,  /* 23 GILL SPLASH M */
    alex_cuca_024,  /* 24 KEN HIZAGERI */
    alex_cuca_025,  /* 25 ORO KISINRIKI */
    alex_cuca_026,  /* 26 SEAN TACKLE */
    alex_cuca_027,  /* 27 ALEX HYPER B */
    alex_cuca_028,  /* 28 NECRO SLAM D */
    alex_cuca_029,  /* 29 ELENA ASINAGE */
    alex_cuca_030,  /* 30 GILL IMPACT C */
    alex_cuca_031,  /* 31 ALEX S H B */
    alex_cuca_032,  /* 32 ALEX F N D */
    alex_cuca_033,  /* 33 no name */
    alex_cuca_034,  /* 34 IBUKI */
    alex_cuca_035,  /* 35 IBUKI YOROI D */
    alex_cuca_036,  /* 36 no name */
    alex_cuca_037,  /* 37 MAWARIKOMI M F */
    alex_cuca_038,  /* 38 HUGO BODY S */
    alex_cuca_039,  /* 39 HUGO N G T */
    alex_cuca_040,  /* 40 HUGO M S P */
    alex_cuca_041,  /* 41 HUGO S D B B */
    alex_cuca_042,  /* 42 no name */
    alex_cuca_043,  /* 43 no name */
    alex_cuca_044,  /* 44 no name */
    alex_cuca_045,  /* 45 no name */
    alex_cuca_046,  /* 46 no name */
    alex_cuca_047,  /* 47 no name */
    alex_cuca_048,  /* 48 no name */
    alex_cuca_049,  /* 49 no name */
    alex_cuca_050,  /* 50 no name */
    alex_cuca_051,  /* 51 no name */
    alex_cuca_052,  /* 52 no name */
    alex_cuca_053,  /* 53 no name */
    alex_cuca_054,  /* 54 no name */
    alex_cuca_055,  /* 55 no name */
    alex_cuca_056,  /* 56 no name */
    alex_cuca_057,  /* 57 no name */
    alex_cuca_058,  /* 58 no name */
    alex_cuca_059,  /* 59 no name */
    alex_cuca_060,  /* 60 no name */
    alex_cuca_061,  /* 61 no name */
    alex_cuca_062,  /* 62 no name */
    alex_cuca_063,  /* 63 no name */
    alex_cuca_064,  /* 64 no name */
    alex_cuca_065,  /* 65 no name */
    alex_cuca_066,  /* 66 no name */
    alex_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 alex_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 alex_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x08F8),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 alex_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 alex_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x089A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x082F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 alex_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F5),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06F5),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 alex_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C8),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0739),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 alex_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0608),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0606),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0747),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0746),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0744),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 alex_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06FF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 alex_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_008[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x060E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x060D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x060F),
    CMD(CM_RMJA, 3, 8, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0720),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 alex_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x069A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0699),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0699),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0697),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 alex_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0630),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0916),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088D),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06EF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 alex_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0702),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 alex_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x063B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x060E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x060D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 alex_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 2),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 alex_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0703),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 alex_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x078D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0789),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0816),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 alex_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_016[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0704),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088C),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x088B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 alex_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_017[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0736),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0736),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_RMJA, 3, 17, 25),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 11),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 11),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 alex_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x082D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x082E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0829),
    L2(250, 0, 0, 0, 0, 0, 0, 0x082A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0831),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0834),
    L2(250, 0, 0, 0, 0, 0, 0, 0x082C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0831),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0810),
    L2(250, 3, 0, 0, 0, 0, 0, 0x08A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08A9),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x08A7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 alex_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AD),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0601),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 alex_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0675),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0674),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0673),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0672),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0674),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0675),
    L2(250, 0, 0, 0, 1, 0, 0, 0x069F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06C7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 alex_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0676),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0675),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06FF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 alex_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C8),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 alex_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CD),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06CE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 alex_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0702),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 alex_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0736),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0736),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 alex_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x08C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 3, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x06D4),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D9),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 alex_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_027[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0702),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0818),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06CC),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 alex_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x073A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x073A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x073B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0703),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06C4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 alex_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 3, 0, 0, 0x08F6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DE),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 alex_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0606),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E4),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 alex_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 alex_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D4),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 alex_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 alex_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 alex_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0608),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0606),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0747),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0746),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0744),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 alex_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0699),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A8),
    L2(250, 2, 0, 0, 0, 0, 0, 0x06F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E9),
    L2(250, 2, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 2, 0, 0, 0, 0, 0, 0x06C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D8),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D6),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 alex_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x078A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06E0),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x06DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 alex_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0690),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0682),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x07E2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x088D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0726),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0880),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06E2),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x08A8),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 alex_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0690),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 25, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 alex_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0720),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x083A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0788),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0794),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0729),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0738),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D7),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D8),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 alex_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 alex_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E7),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DD),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 alex_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D9),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 alex_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0720),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x083A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0788),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0794),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0729),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0738),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0705),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D8),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 alex_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06F0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 alex_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0729),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0729),
    L2(250, 0, 0, 0, 3, 0, 0, 0x088D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D3),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 alex_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0701),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0702),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06CC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0818),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06CA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 alex_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 alex_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0690),
    L2(250, 0, 0, 0, 1, 0, 0, 0x08CC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x08C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06EF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x08D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08D4),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x08D5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 alex_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0691),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0926),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06CF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06D1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06D2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06D3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E0),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x072A),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 alex_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0699),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x06E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 alex_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0630),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0916),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0862),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0682),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x088D),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06EF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 alex_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06DD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x08D0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DF),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 alex_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 alex_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E5),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 alex_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0700),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 14, 0x08CE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 alex_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0707),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0707),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DB),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06DC),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 alex_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0690),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06C9),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 alex_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0637),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0637),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0697),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0699),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DF),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 alex_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0700),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06F6),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 alex_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08CE),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 alex_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B6),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B7),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B8),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0701),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 14),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06EF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06CE),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 1, 0, 0, 0x06CD),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 alex_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06DA),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 931, 0, 0, 0, 0, 0x06DB),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 alex_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F1),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06FB),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 alex_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x06B8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x06E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06EF),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0816),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 alex_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x08F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06D5),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06D5),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 alex_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x06C1),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x06C4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 156 entries */
const u16* const alex_atca[157] = {
    alex_atca_000,  /* 0 S PUNCH A */
    alex_atca_001,  /* 1 S PUNCH B */
    alex_atca_001,  /* 2 S PUNCH C */
    alex_atca_003,  /* 3 M PUNCH A */
    alex_atca_003,  /* 4 M PUNCH B */
    alex_atca_005,  /* 5 M PUNCH C */
    alex_atca_006,  /* 6 L PUNCH A */
    alex_atca_007,  /* 7 L PUNCH B */
    alex_atca_008,  /* 8 L PUNCH C */
    alex_atca_009,  /* 9 S KICK A */
    alex_atca_009,  /* 10 S KICK B */
    alex_atca_009,  /* 11 S KICK C */
    alex_atca_012,  /* 12 M KICK A */
    alex_atca_013,  /* 13 M KICK B */
    alex_atca_013,  /* 14 M KICK C */
    alex_atca_015,  /* 15 L KICK A */
    alex_atca_015,  /* 16 L KICK B */
    alex_atca_015,  /* 17 L KICK C */
    alex_atca_018,  /* 18 KAGAMI P A */
    alex_atca_018,  /* 19 KAGAMI P B */
    alex_atca_018,  /* 20 KAGAMI P C */
    alex_atca_021,  /* 21 KAGAMI P A */
    alex_atca_021,  /* 22 KAGAMI P B */
    alex_atca_021,  /* 23 KAGAMI P C */
    alex_atca_024,  /* 24 KAGAMI P A */
    alex_atca_024,  /* 25 KAGAMI P B */
    alex_atca_024,  /* 26 KAGAMI P C */
    alex_atca_027,  /* 27 KAGAMI K A */
    alex_atca_027,  /* 28 KAGAMI K B */
    alex_atca_027,  /* 29 KAGAMI K C */
    alex_atca_030,  /* 30 KAGAMI K A */
    alex_atca_030,  /* 31 KAGAMI K B */
    alex_atca_030,  /* 32 KAGAMI K C */
    alex_atca_033,  /* 33 KAGAMI K A */
    alex_atca_033,  /* 34 KAGAMI K B */
    alex_atca_033,  /* 35 KAGAMI K C */
    alex_atca_036,  /* 36 V JUMP P S A */
    alex_atca_036,  /* 37 V JUMP P S B */
    alex_atca_038,  /* 38 V JUMP P M A */
    alex_atca_038,  /* 39 V JUMP P M B */
    alex_atca_040,  /* 40 V JUMP P L A */
    alex_atca_041,  /* 41 V JUMP P L B */
    alex_atca_042,  /* 42 V JUMP K S A */
    alex_atca_042,  /* 43 V JUMP K S B */
    alex_atca_044,  /* 44 V JUMP K M A */
    alex_atca_044,  /* 45 V JUMP K M B */
    alex_atca_046,  /* 46 V JUMP K L A */
    alex_atca_046,  /* 47 V JUMP K L B */
    alex_atca_048,  /* 48 F JUMP P S A */
    alex_atca_048,  /* 49 F JUMP P S B */
    alex_atca_050,  /* 50 F JUMP P M A */
    alex_atca_050,  /* 51 F JUMP P M B */
    alex_atca_052,  /* 52 F JUMP P L A */
    alex_atca_053,  /* 53 F JUMP P L B */
    alex_atca_054,  /* 54 F JUMP K S A */
    alex_atca_054,  /* 55 F JUMP K S B */
    alex_atca_056,  /* 56 F JUMP K M A */
    alex_atca_056,  /* 57 F JUMP K M B */
    alex_atca_058,  /* 58 F JUMP K L A */
    alex_atca_058,  /* 59 F JUMP K L B */
    alex_atca_060,  /* 60 B JUMP P S A */
    alex_atca_060,  /* 61 B JUMP P S B */
    alex_atca_062,  /* 62 B JUMP P M A */
    alex_atca_062,  /* 63 B JUMP P M B */
    alex_atca_064,  /* 64 B JUMP P L A */
    alex_atca_064,  /* 65 B JUMP P L B */
    alex_atca_066,  /* 66 B JUMP K S A */
    alex_atca_066,  /* 67 B JUMP K S B */
    alex_atca_068,  /* 68 B JUMP K M A */
    alex_atca_068,  /* 69 B JUMP K M B */
    alex_atca_070,  /* 70 B JUMP K L A */
    alex_atca_070,  /* 71 B JUMP K L B */
    alex_atca_072,  /* 72 SP V JP S P A */
    alex_atca_072,  /* 73 SP V JP S P B */
    alex_atca_074,  /* 74 SP V JP M P A */
    alex_atca_074,  /* 75 SP V JP M P B */
    alex_atca_076,  /* 76 SP V JP L P A */
    alex_atca_077,  /* 77 SP V JP L P B */
    alex_atca_078,  /* 78 SP V JP S K A */
    alex_atca_078,  /* 79 SP V JP S K B */
    alex_atca_080,  /* 80 SP V JP M K A */
    alex_atca_080,  /* 81 SP V JP M K B */
    alex_atca_082,  /* 82 SP V JP L K A */
    alex_atca_082,  /* 83 SP V JP L K B */
    alex_atca_084,  /* 84 SP F JP S P A */
    alex_atca_084,  /* 85 SP F JP S P B */
    alex_atca_086,  /* 86 SP F JP M P A */
    alex_atca_086,  /* 87 SP F JP M P B */
    alex_atca_088,  /* 88 SP F JP L P A */
    alex_atca_089,  /* 89 SP F JP L P B */
    alex_atca_090,  /* 90 SP F JP S K A */
    alex_atca_090,  /* 91 SP F JP S K B */
    alex_atca_092,  /* 92 SP F JP M K A */
    alex_atca_092,  /* 93 SP F JP M K B */
    alex_atca_094,  /* 94 SP F JP L K A */
    alex_atca_094,  /* 95 SP F JP L K B */
    alex_atca_096,  /* 96 SP B JP S P A */
    alex_atca_096,  /* 97 SP B JP S P B */
    alex_atca_098,  /* 98 SP B JP M P A */
    alex_atca_098,  /* 99 SP B JP M P B */
    alex_atca_100,  /* 100 SP B JP L P A */
    alex_atca_100,  /* 101 SP B JP L P B */
    alex_atca_102,  /* 102 SP B JP S K A */
    alex_atca_102,  /* 103 SP B JP S K B */
    alex_atca_104,  /* 104 SP B JP M K A */
    alex_atca_104,  /* 105 SP B JP M K B */
    alex_atca_106,  /* 106 SP B JP L K A */
    alex_atca_106,  /* 107 SP B JP L K B */
    alex_atca_108,  /* 108 S V JP S P A */
    alex_atca_108,  /* 109 S V JP S P B */
    alex_atca_110,  /* 110 S V JP M P A */
    alex_atca_110,  /* 111 S V JP M P B */
    alex_atca_112,  /* 112 S V JP L P A */
    alex_atca_112,  /* 113 S V JP L P B */
    alex_atca_114,  /* 114 S V JP S K A */
    alex_atca_114,  /* 115 S V JP S K B */
    alex_atca_116,  /* 116 S V JP M K A */
    alex_atca_116,  /* 117 S V JP M K B */
    alex_atca_118,  /* 118 S V JP L K A */
    alex_atca_118,  /* 119 S V JP L K B */
    alex_atca_108,  /* 120 S F JP S P A */
    alex_atca_108,  /* 121 S F JP S P B */
    alex_atca_110,  /* 122 S F JP M P A */
    alex_atca_110,  /* 123 S F JP M P B */
    alex_atca_112,  /* 124 S F JP L P A */
    alex_atca_112,  /* 125 S F JP L P B */
    alex_atca_114,  /* 126 S F JP S K A */
    alex_atca_114,  /* 127 S F JP S K B */
    alex_atca_116,  /* 128 S F JP M K A */
    alex_atca_116,  /* 129 S F JP M K B */
    alex_atca_118,  /* 130 S F JP L K A */
    alex_atca_118,  /* 131 S F JP L K B */
    alex_atca_108,  /* 132 S B JP S P A */
    alex_atca_108,  /* 133 S B JP S P B */
    alex_atca_110,  /* 134 S B JP M P A */
    alex_atca_110,  /* 135 S B JP M P B */
    alex_atca_112,  /* 136 S B JP L P A */
    alex_atca_112,  /* 137 S B JP L P B */
    alex_atca_114,  /* 138 S B JP S K A */
    alex_atca_114,  /* 139 S B JP S K B */
    alex_atca_116,  /* 140 S B JP M K A */
    alex_atca_116,  /* 141 S B JP M K B */
    alex_atca_118,  /* 142 S B JP L K A */
    alex_atca_118,  /* 143 S B JP L K B */
    alex_atca_144,  /* 144 TUKAMIKAKARI A */
    alex_atca_144,  /* 145 TUKAMIKAKARI B */
    alex_atca_146,  /* 146 TUKAMIKAKARI C */
    alex_atca_144,  /* 147 TUKAMIKAKARI D */
    alex_atca_144,  /* 148 TUKAMIKAKARI E */
    alex_atca_144,  /* 149 TUKAMIKAKARI F */
    alex_atca_144,  /* 150 TUKAMI AIR A */
    alex_atca_144,  /* 151 TUKAMI AIR B */
    alex_atca_144,  /* 152 TUKAMI AIR C */
    alex_atca_144,  /* 153 TUKAMI AIR D */
    alex_atca_144,  /* 154 TUKAMI AIR E */
    alex_atca_144,  /* 155 TUKAMI AIR F */
    0
};

/* script: 0 S PUNCH A */
const u16 alex_atca_000_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 0) };
const u16 alex_atca_000[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x076A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x076A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x076B, -1, 8, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x076C, 0, 9, 155, 0, 104, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x076D, 0, 9, 155, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x076E, 0, 1, 155, 0, 12, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x076F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 alex_atca_001_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 0) };
const u16 alex_atca_001[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0740, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0740, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0744, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 268, 0, 0, 0, 0, 0x0749, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0741, -2, 11, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0742, 0, 11, 155, 0, 120, 0, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0743, 0, 12, 155, 0, 24, 21, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0744, 0, 12, 155, 0, 24, 0, 4),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0745, 0, 1, 0, 0, 20, 0, 4),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0746, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 alex_atca_003_head[4] = { HEAD(6, 0, 2, 11, 0, 1, 0) };
const u16 alex_atca_003[172] = {
    L6(3, 0, 269, 0, 0, 0, 0, 0x0770, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0771, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0772, -3, 16, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0773, 0, 1, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0774, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0776, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0777, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0778, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0779, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x077A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 alex_atca_005_head[4] = { HEAD(6, 0, 2, 12, 0, 1, 0) };
const u16 alex_atca_005[160] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x074B, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x074C, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x074D, 0, 35, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x074E, -5, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x074F, 0, 23, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0750, 8, 24, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0752, 0, 25, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0753, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0754, 0, 25, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 alex_atca_006_head[4] = { HEAD(6, 0, 4, 11, 0, 1, 0) };
const u16 alex_atca_006[268] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0756, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0757, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0758, 0, 1, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(3, 0, 935, 0, 0, 0, 0, 0x0759, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x075A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075C, -7, 19, 0, 148, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075D, 9, 20, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075E, 0, 21, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075F, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0760, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0761, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0762, 0, 21, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0763, 0, 21, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0764, 0, 1, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0765, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x074A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075C, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075D, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075E, 0, 21, 0, 0, 0, 21, 0, 0, 0, 0, 10, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B */
const u16 alex_atca_007_head[4] = { HEAD(6, 0, 4, 13, 0, 1, 0) };
const u16 alex_atca_007[384] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0835, 0, 246, 0, 0, 0, 0, 0, 0, 0, 472, 0, 0),
    L6(2, 0, 932, 0, 0, 0, 0, 0x0835, 0, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x0836, 0, 247, 0, 0, 0, 0, 0, 0, 0, 474, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0837, -100, 248, 0, 0, 0, 0, 0, 0, 0, 476, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0838, 0, 249, 0, 0, 0, 0, 0, 0, 0, 478, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0839, 0, 250, 0, 0, 0, 21, 0, 0, 0, 480, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x083A, 0, 251, 0, 0, 0, 0, 0, 0, 0, 482, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x083B, 0, 252, 0, 0, 0, 0, 0, 0, 0, 484, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 486, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0698, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0004, 0x0B00, 0x0700, 0x001C, 0x0004, 0x0007, 0x0004,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0005, 0x0008, 0x0007, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x0601,
    L6(247, 75, 1024, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 7, 165),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x07A6,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0000, 0x0000, 0x0835,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x10E0, 0x0000, 0x0836,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x0837,
    L6(245, 148, 3584, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 8, 56),
    CMD(CM_UJA3, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x0839,
    CMD(CM_UJA3, 0, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x083A,
    L6(2, 85, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1280, 0, 0, 8, 59),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0000, 0x0000, 0x0697,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x0698,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0699,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x069A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x069A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 8 L PUNCH C */
const u16 alex_atca_008_head[4] = { HEAD(6, 0, 4, 14, 0, 1, 0) };
const u16 alex_atca_008[172] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0751, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 935, 0, 0, 0, 0, 0x077B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 270, 0, 0, 0, 0, 0x077C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x077D, -28, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x077E, 0, 76, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x077F, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0780, 0, 76, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0781, 0, 1, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0782, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0783, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 alex_atca_009_head[4] = { HEAD(6, 0, 1, 12, 0, 1, 0) };
const u16 alex_atca_009[136] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0790, 0, 1, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x0791, 0, 1, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0792, -10, 26, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0793, 0, 27, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0794, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0795, 0, 1, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0796, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0797, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0798, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 alex_atca_012_head[4] = { HEAD(6, 0, 3, 9, 0, 1, 0) };
const u16 alex_atca_012[136] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0790, 0, 1, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x07B4, 0, 28, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07B5, -11, 29, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07B6, 0, 30, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07B7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0795, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0796, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0797, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0798, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B, 14 M KICK C */
const u16 alex_atca_013_head[4] = { HEAD(6, 0, 3, 17, 0, 1, 0) };
const u16 alex_atca_013[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x079A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x079B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x079C, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x079D, 0, 31, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x079E, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x079F, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07A0, -13, 32, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x07A1, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07A2, 0, 33, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x07A6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 alex_atca_015_head[4] = { HEAD(6, 0, 5, 13, 0, 1, 0) };
const u16 alex_atca_015[328] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x07A8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07AA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 941, 0, 0, 0, 0, 0x07AC, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x07AC, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07AD, 0, 39, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07AD, -14, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07AE, 42, 38, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x07AE, 0, 39, 0, 0, 0, 21, 0, 0, 0, 16, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07AF, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07B0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07B1, 0, 40, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x07B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x07AE, 0, 39, 0, 0, 0, 21, 0, 0, 0, 16, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07AF, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07B0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07B1, 0, 40, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0797, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0798, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 alex_atca_018_head[4] = { HEAD(6, 32, 0, 12, 0, 1, 0) };
const u16 alex_atca_018[184] = {
    L6(4, 0, 268, 0, 0, 0, 0, 0x09CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 466, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x09CE, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x09CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x09CB, -15, 207, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x09CC, 0, 208, 16, 0, 120, 0, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x09CD, 0, 209, 16, 0, 120, 21, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x09CE, 0, 153, 16, 0, 120, 0, 3, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x07C5, 0, 153, 0, 0, 0, 0, 0, 0, 0, 468, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0, 0, 0, 470, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 alex_atca_021_head[4] = { HEAD(4, 32, 2, 15, 0, 1, 0) };
const u16 alex_atca_021[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 0, 0x07C0, 0, 4, 0, 0, 0, 32, 106),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07C1, -16, 43, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07C2, 0, 42, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C3, 0, 42, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07C4, 0, 101, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07C5, 0, 101, 0, 0, 0, 32, 107),
    L4(3, 64, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 32, 107),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 alex_atca_024_head[4] = { HEAD(6, 32, 4, 8, 0, 2, 0) };
const u16 alex_atca_024[112] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x07CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 935, 0, 0, 0, 0, 0x07CB, 0, 4, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(6, 0, 270, 0, 0, 0, 0, 0x07CC, 0, 4, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07CD, -17, 44, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    CMD(CM_EXEC, 30, 58, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 1, 0, 0, 0, 0, 0, 0x07CE, -18, 45, 0, 0, 0, 30, 59, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CF, 0, 46, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x07CF, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 alex_atca_027_head[4] = { HEAD(4, 32, 1, 12, 0, 1, 0) };
const u16 alex_atca_027[204] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x07D4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D7, 0, 49, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D6, -19, 48, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D6, 0, 49, 0, 0, 96, 21, 0),
    CMD(CM_RMJA, 4, 27, 18), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D8, 0, 4, 2562, 0, 8, 0, 0),
    CMD(CM_RMJA, 4, 27, 20), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D9, 0, 4, 3074, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07DA, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D4, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 30, 5), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x07DB, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x07DC, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x07DC, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 33, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 alex_atca_030_head[4] = { HEAD(4, 32, 3, 14, 0, 1, 0) };
const u16 alex_atca_030[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D4, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x07D4, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D5, 0, 54, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D5, -20, 50, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D6, 0, 50, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07D7, 0, 54, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07D8, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D9, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07DA, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C7, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 alex_atca_033_head[4] = { HEAD(4, 32, 5, 15, 0, 1, 0) };
const u16 alex_atca_033[164] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x07E8, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07DB, 0, 4, 0, 0, 0, 32, 200),
    L4(3, 0, 270, 0, 0, 0, 0, 0x07DC, 0, 4, 0, 0, 0, 32, 201),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07DD, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07DE, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07DE, -21, 51, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07DF, 22, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E0, 0, 53, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E1, 0, 53, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E2, 0, 4, 0, 0, 0, 32, 202),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E3, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E4, 0, 4, 0, 0, 0, 32, 203),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07E5, 0, 4, 0, 0, 0, 32, 204),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07E6, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07E7, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x07C6, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07E8, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07C8, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x064A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 alex_atca_036_head[4] = { HEAD(4, 22, 0, 11, 0, 1, 0) };
const u16 alex_atca_036[172] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x07F0, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x07F1, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07F2, -23, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07F3, 24, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07F4, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07F5, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x080D, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x080E, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07F5, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x080D, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x080E, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0655, 0, 13, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 alex_atca_038_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 alex_atca_038[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x09B9, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x09BA, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x09BB, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 6, 0x09BC, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x09BD, -25, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x09BE, 0, 193, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x09BF, 0, 194, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x09C0, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x09C1, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x09CF, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x09C2, 0, 191, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x09C2, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A */
const u16 alex_atca_040_head[4] = { HEAD(4, 22, 4, 13, 0, 1, 0) };
const u16 alex_atca_040[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x0803, 0, 78, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x0804, 0, 78, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0805, 0, 79, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 5, 0x0806, 0, 79, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x0807, -29, 80, 0, 136, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x080C, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0808, 30, 81, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 5, 0x0809, 0, 82, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x080A, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x080B, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x065A, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x065B, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x065C, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 V JUMP P L B */
const u16 alex_atca_041_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 45) };
const u16 alex_atca_041[8] = {
    CMD(CM_JPSS, 4, 53, 1), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 alex_atca_042_head[4] = { HEAD(4, 22, 1, 8, 0, 1, 0) };
const u16 alex_atca_042[164] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x0840, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 5, 0x0841, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0843, -31, 83, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x0844, 0, 83, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x0845, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x0846, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x0847, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x0840, 0, 13, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0654, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0655, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0656, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0657, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0658, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0659, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x065A, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x065B, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 4, 0x065C, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 alex_atca_044_head[4] = { HEAD(4, 22, 3, 13, 0, 1, 0) };
const u16 alex_atca_044[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x09AF, 0, 195, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x09B0, 0, 195, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x09B1, 0, 195, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x09B2, 0, 196, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x09B3, -32, 197, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x09B4, 0, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x09B5, 0, 199, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x09B6, 0, 200, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x09B7, 0, 201, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09B8, 0, 202, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x09B8, 0, 202, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 alex_atca_046_head[4] = { HEAD(4, 22, 5, 14, 0, 1, 0) };
const u16 alex_atca_046[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x0850, 0, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x0851, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0852, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x0853, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0853, -33, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0854, 0, 123, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 6, 0x0855, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0856, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0858, 0, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0859, 0, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 alex_atca_048_head[4] = { HEAD(2, 20, 0, 12, 0, 1, 0) };
const u16 alex_atca_048[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 36, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 alex_atca_050_head[4] = { HEAD(2, 20, 2, 14, 0, 1, 0) };
const u16 alex_atca_050[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 38, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A */
const u16 alex_atca_052_head[4] = { HEAD(2, 20, 4, 14, 0, 1, 0) };
const u16 alex_atca_052[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 40, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 F JUMP P L B */
const u16 alex_atca_053_head[4] = { HEAD(4, 20, 4, 13, 0, 1, 45) };
const u16 alex_atca_053[92] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(2, 20, 932, 0, 0, 0, 6, 0x0682, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 1, 270, 0, 0, 0, 6, 0x07F8, 0, 92, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 6, 0x07F9, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x07FA, 0, 92, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x07FB, -38, 93, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x07FC, 0, 150, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x07FD, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x07FE, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x07FF, 0, 94, 0, 0, 0, 21, 0),
    L4(250, 1, 0, 0, 0, 0, 5, 0x0800, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 alex_atca_054_head[4] = { HEAD(2, 20, 1, 9, 0, 1, 0) };
const u16 alex_atca_054[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 42, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 alex_atca_056_head[4] = { HEAD(2, 20, 3, 14, 0, 1, 0) };
const u16 alex_atca_056[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 44, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 alex_atca_058_head[4] = { HEAD(2, 20, 5, 15, 0, 1, 0) };
const u16 alex_atca_058[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 46, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 alex_atca_060_head[4] = { HEAD(2, 24, 0, 11, 0, 1, 0) };
const u16 alex_atca_060[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 48, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 alex_atca_062_head[4] = { HEAD(2, 24, 2, 13, 0, 1, 0) };
const u16 alex_atca_062[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 50, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 alex_atca_064_head[4] = { HEAD(2, 24, 4, 13, 0, 1, 0) };
const u16 alex_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 alex_atca_066_head[4] = { HEAD(2, 24, 1, 8, 0, 1, 0) };
const u16 alex_atca_066[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 54, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 alex_atca_068_head[4] = { HEAD(2, 24, 3, 13, 0, 1, 0) };
const u16 alex_atca_068[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 56, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 alex_atca_070_head[4] = { HEAD(2, 24, 5, 14, 0, 1, 0) };
const u16 alex_atca_070[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 58, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 alex_atca_072_head[4] = { HEAD(2, 28, 0, 11, 0, 1, 0) };
const u16 alex_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 alex_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 alex_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A */
const u16 alex_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 alex_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 SP V JP L P B */
const u16 alex_atca_077_head[4] = { HEAD(4, 28, 4, 12, 0, 1, 45) };
const u16 alex_atca_077[8] = {
    CMD(CM_JPSS, 4, 89, 1), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 alex_atca_078_head[4] = { HEAD(2, 28, 1, 8, 0, 1, 0) };
const u16 alex_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 alex_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 alex_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 alex_atca_082_head[4] = { HEAD(2, 28, 5, 14, 0, 1, 0) };
const u16 alex_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 alex_atca_084_head[4] = { HEAD(2, 26, 0, 12, 0, 1, 0) };
const u16 alex_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 alex_atca_086_head[4] = { HEAD(2, 26, 2, 14, 0, 1, 0) };
const u16 alex_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A */
const u16 alex_atca_088_head[4] = { HEAD(2, 26, 4, 14, 0, 1, 0) };
const u16 alex_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 SP F JP L P B */
const u16 alex_atca_089_head[4] = { HEAD(6, 26, 4, 13, 0, 1, 45) };
const u16 alex_atca_089[328] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 932, 0, 0, 0, 6, 0x0682, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 270, 0, 0, 0, 6, 0x07F8, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 6, 0x07F9, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 6, 0x07FA, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 6, 0x07FB, -38, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 6, 0x07FC, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 6, 0x07FD, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 6, 0x07FE, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 6, 0x07FF, 0, 94, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 1, 0, 0, 0, 0, 5, 0x0800, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0829, 0, 58, 0, 0, 0, 21, 0, 0, 0, 0, 0, 162),
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0829, 0, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 162),
    L6(2, 0, 0, 0, 0, 0, 0, 0x082A, 0, 58, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x082B, 0, 58, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x082C, 0, 58, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x082D, 0, 58, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 64, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 alex_atca_090_head[4] = { HEAD(2, 26, 1, 9, 0, 1, 0) };
const u16 alex_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 alex_atca_092_head[4] = { HEAD(2, 26, 3, 14, 0, 1, 0) };
const u16 alex_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 alex_atca_094_head[4] = { HEAD(2, 26, 5, 15, 0, 1, 0) };
const u16 alex_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 alex_atca_096_head[4] = { HEAD(2, 30, 0, 11, 0, 1, 0) };
const u16 alex_atca_096[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 alex_atca_098_head[4] = { HEAD(2, 30, 2, 13, 0, 1, 0) };
const u16 alex_atca_098[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 alex_atca_100_head[4] = { HEAD(2, 30, 4, 13, 0, 1, 0) };
const u16 alex_atca_100[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 alex_atca_102_head[4] = { HEAD(2, 30, 1, 8, 0, 1, 0) };
const u16 alex_atca_102[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 alex_atca_104_head[4] = { HEAD(2, 30, 3, 13, 0, 1, 0) };
const u16 alex_atca_104[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 alex_atca_106_head[4] = { HEAD(2, 30, 5, 14, 0, 1, 0) };
const u16 alex_atca_106[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 alex_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 alex_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 alex_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 alex_atca_110[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 alex_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 alex_atca_112[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 alex_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 alex_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 alex_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 alex_atca_116[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 alex_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 alex_atca_118[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 alex_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_atca_144[76] = {
    CMD(CM_CAFR, 2, 2, 23), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 23), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x0745, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0745, -35, 90, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0745, 0, 1, 0, 0, 0, 21, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0746, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 alex_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 2),
    CMD(CM_CARE, 2, 2, 2),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX alex_olc_ix_table[53] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 2, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 4, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
    { { 6, 0, 0, 0 } },
    { { 7, 0, 0, 0 } },
    { { 8, 0, 0, 0 } },
    { { 9, 0, 0, 0 } },
    { { 10, 0, 0, 0 } },
    { { 11, 0, 0, 0 } },
    { { 12, 0, 0, 0 } },
    { { 13, 0, 0, 0 } },
    { { 14, 0, 0, 0 } },
    { { 15, 0, 0, 0 } },
    { { 16, 0, 0, 0 } },
    { { 17, 0, 0, 0 } },
    { { 21, 0, 0, 0 } },
    { { 22, 0, 0, 0 } },
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
    { { 51, 0, 0, 0 } },
    { { 52, 0, 0, 0 } },
    { { 53, 0, 0, 0 } },
    { { 54, 0, 0, 0 } },
    { { 55, 0, 0, 0 } },
    { { 56, 0, 0, 0 } },
};

const OVERLAP_PARTS alex_overlap_char_tbl[57] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 2210 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 2211 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 2212 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 2213 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 5, 2333 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 6, 2334 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 7, 2335 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 8, 2336 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 9, 2337 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 10, 2338 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 11, 2339 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 12, 2340 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 13, 2341 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 14, 2398 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 15, 2399 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 16, 2400 },
    { 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 2401 },
    { 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 2402 },
    { 0, 0, 0, 2, 2, 0, 2, 0, 0, 0, 2403 },
    { 0, 0, 0, 2, 2, 0, 2, 0, 0, 50, 2404 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 2422 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 2423 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 2424 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 2425 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 2426 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 2427 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 2428 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 28, 2429 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 29, 2430 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 30, 2431 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 31, 2432 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 32, 2433 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 33, 2434 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 34, 2435 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 35, 2436 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 36, 2437 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 37, 2438 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 38, 2439 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 39, 2440 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 40, 2441 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 41, 2442 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 42, 2443 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 2444 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 2445 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 2446 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 2447 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 47, 2448 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 48, 2449 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 49, 2450 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 50, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 51, 2456 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 52, 2458 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 53, 2460 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 54, 2462 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 55, 2464 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 56, 2468 },
};

const CatchTable alex_rival_catch_tbl[3192] = {
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { -90, 0, 2, 1, 1 },
    { -109, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -84, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -94, 0, 2, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -71, 0, 2, 1, 2 },
    { -35, 0, 2, 1, 2 },
    { -46, 0, 2, 1, 2 },
    { -84, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -50, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -56, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -59, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 3 },
    { -38, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { -74, 0, 2, 1, 3 },
    { -43, 0, 2, 1, 3 },
    { -41, 0, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -33, 0, 2, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { -54, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -69, 0, 2, 1, 4 },
    { -52, 0, 2, 1, 4 },
    { -74, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -41, 0, 2, 1, 4 },
    { -23, 0, 2, 1, 4 },
    { -17, 0, 2, 1, 4 },
    { -69, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -40, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -44, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -60, 0, 2, 1, 4 },
    { -63, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 5 },
    { -42, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -69, 0, 2, 1, 5 },
    { -52, 0, 2, 1, 5 },
    { -74, 0, 2, 1, 5 },
    { -46, 0, 2, 1, 5 },
    { -41, 0, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -24, 0, 2, 1, 5 },
    { -69, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -34, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -67, 0, 2, 1, 5 },
    { -61, 0, 2, 1, 5 },
    { -42, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -46, 0, 2, 1, 6 },
    { -76, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -54, 0, 2, 1, 6 },
    { -104, 0, 2, 1, 6 },
    { -81, 0, 2, 1, 6 },
    { -65, -8, 2, 1, 6 },
    { -64, 0, 2, 1, 6 },
    { -56, 0, 2, 1, 6 },
    { -58, 0, 2, 1, 6 },
    { -54, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -46, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -66, 0, 2, 1, 6 },
    { -81, -6, 2, 1, 6 },
    { -88, 0, 2, 1, 6 },
    { -68, 0, 2, 1, 6 },
    { -84, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -60, 0, 2, 1, 7 },
    { -78, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -54, 0, 2, 1, 7 },
    { -105, 0, 2, 1, 7 },
    { -83, 0, 2, 1, 7 },
    { -94, 0, 2, 1, 7 },
    { -62, 0, 2, 1, 7 },
    { -56, 0, 2, 1, 7 },
    { -81, 0, 2, 1, 7 },
    { -54, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -60, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -78, 0, 2, 1, 7 },
    { -76, 0, 2, 1, 7 },
    { -88, 0, 2, 1, 7 },
    { -90, 0, 2, 1, 7 },
    { -80, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -96, 0, 2, 1, 1 },
    { -93, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -86, 0, 2, 1, 1 },
    { -106, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -93, 0, 2, 1, 1 },
    { -74, -15, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -71, 0, 2, 1, 1 },
    { -86, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -75, 0, 2, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -74, -8, 2, 1, 1 },
    { -88, -6, 2, 1, 1 },
    { -84, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -94, 0, 2, 1, 2 },
    { -99, -12, 2, 1, 2 },
    { -76, 12, 2, 1, 2 },
    { -83, 13, 2, 1, 2 },
    { -79, 2, 2, 1, 2 },
    { -96, 0, 2, 1, 2 },
    { -90, -9, 2, 1, 2 },
    { -101, 22, 2, 1, 2 },
    { -91, 1, 2, 1, 2 },
    { -94, 16, 2, 1, 2 },
    { -83, 13, 2, 1, 2 },
    { -76, 12, 2, 1, 2 },
    { -76, 12, 2, 1, 2 },
    { -94, 0, 2, 1, 2 },
    { -76, 12, 2, 1, 2 },
    { -76, 12, 2, 1, 2 },
    { -92, 11, 2, 1, 2 },
    { -104, 15, 2, 1, 2 },
    { -89, -1, 2, 1, 2 },
    { -80, -4, 2, 1, 2 },
    { -92, 2, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 3 },
    { -104, 112, 2, 1, 3 },
    { -72, 6, 2, 1, 3 },
    { -92, 32, 2, 1, 3 },
    { -63, 9, 2, 1, 3 },
    { -80, 8, 2, 1, 3 },
    { -71, -3, 2, 1, 3 },
    { -81, 29, 2, 1, 3 },
    { -83, 17, 2, 1, 3 },
    { -76, 19, 2, 1, 3 },
    { -92, 32, 2, 1, 3 },
    { -72, 6, 2, 1, 3 },
    { -72, 6, 2, 1, 3 },
    { -76, 0, 2, 1, 3 },
    { -72, 6, 2, 1, 3 },
    { -72, 6, 2, 1, 3 },
    { -83, 26, 2, 1, 3 },
    { -86, 16, 2, 1, 3 },
    { -76, 6, 2, 1, 3 },
    { -71, 4, 2, 1, 3 },
    { -72, 10, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -71, 148, 2, 1, 4 },
    { -68, 136, 2, 1, 4 },
    { -66, 62, 2, 1, 4 },
    { -72, 49, 2, 1, 4 },
    { -76, 153, 2, 1, 4 },
    { -64, 144, 2, 1, 4 },
    { -50, 43, 2, 1, 4 },
    { -63, 119, 2, 1, 4 },
    { -75, 41, 2, 1, 4 },
    { -55, 156, 2, 1, 4 },
    { -84, 49, 2, 1, 4 },
    { -66, 62, 2, 1, 4 },
    { -66, 62, 2, 1, 4 },
    { -71, 148, 2, 1, 4 },
    { -66, 62, 2, 1, 4 },
    { -66, 62, 2, 1, 4 },
    { -79, 38, 2, 1, 4 },
    { -53, 32, 2, 1, 4 },
    { -82, 38, 2, 1, 4 },
    { -71, 28, 2, 1, 4 },
    { -52, 118, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -29, 208, 2, 1, 5 },
    { -39, 171, 2, 1, 5 },
    { -27, 143, 2, 1, 5 },
    { -53, 183, 2, 1, 5 },
    { -50, 138, 2, 1, 5 },
    { -45, 198, 2, 1, 5 },
    { -39, 47, 2, 1, 5 },
    { -38, 133, 2, 1, 5 },
    { -51, 132, 2, 1, 5 },
    { -32, 178, 2, 1, 5 },
    { -53, 183, 2, 1, 5 },
    { -27, 143, 2, 1, 5 },
    { -27, 143, 2, 1, 5 },
    { -29, 208, 2, 1, 5 },
    { -27, 143, 2, 1, 5 },
    { -27, 143, 2, 1, 5 },
    { -28, 197, 2, 1, 5 },
    { -39, 120, 2, 1, 5 },
    { -56, 92, 2, 1, 5 },
    { -46, 170, 2, 1, 5 },
    { -28, 188, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -12, 210, 2, 1, 6 },
    { -23, 199, 2, 1, 6 },
    { -14, 150, 2, 1, 6 },
    { -38, 185, 2, 1, 6 },
    { -20, 201, 2, 1, 6 },
    { -23, 198, 2, 1, 6 },
    { -12, 55, 2, 1, 6 },
    { 2, 152, 2, 1, 6 },
    { -43, 103, 2, 1, 6 },
    { -25, 183, 2, 1, 6 },
    { -38, 185, 2, 1, 6 },
    { -14, 150, 2, 1, 6 },
    { -14, 150, 2, 1, 6 },
    { -12, 210, 2, 1, 6 },
    { -14, 150, 2, 1, 6 },
    { -14, 150, 2, 1, 6 },
    { -24, 201, 2, 1, 6 },
    { -29, 50, 2, 1, 6 },
    { -43, 88, 2, 1, 6 },
    { -31, 193, 2, 1, 6 },
    { -22, 192, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 19, 195, 2, 1, 7 },
    { 2, 182, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { -1, 173, 2, 1, 7 },
    { 4, 198, 2, 1, 7 },
    { 12, 207, 2, 1, 7 },
    { 5, 51, 2, 1, 7 },
    { 13, 172, 2, 1, 7 },
    { -17, 176, 2, 1, 7 },
    { 2, 177, 2, 1, 7 },
    { -1, 173, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { 19, 195, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { 8, 197, 2, 1, 7 },
    { 6, 170, 2, 1, 7 },
    { -17, 83, 2, 1, 7 },
    { -3, 180, 2, 1, 7 },
    { -4, 188, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 41, 202, 2, 1, 8 },
    { 35, 183, 2, 1, 8 },
    { 45, 163, 2, 1, 8 },
    { 23, 171, 2, 1, 8 },
    { 36, 196, 2, 1, 8 },
    { 39, 179, 2, 1, 8 },
    { 37, 44, 2, 1, 8 },
    { 28, 162, 2, 1, 8 },
    { 25, 164, 2, 1, 8 },
    { 24, 88, 2, 1, 8 },
    { 23, 171, 2, 1, 8 },
    { 45, 163, 2, 1, 8 },
    { 45, 163, 2, 1, 8 },
    { 41, 202, 2, 1, 8 },
    { 45, 163, 2, 1, 8 },
    { 45, 163, 2, 1, 8 },
    { 57, 180, 2, 1, 8 },
    { 31, 83, 2, 1, 8 },
    { 25, 75, 2, 1, 8 },
    { 18, 194, 2, 1, 8 },
    { 68, 68, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 88, 181, 2, 1, 9 },
    { 64, 164, 2, 1, 9 },
    { 95, 42, 2, 1, 9 },
    { 60, 149, 2, 1, 9 },
    { 79, 159, 2, 1, 9 },
    { 81, 35, 2, 1, 9 },
    { 52, 23, 2, 1, 9 },
    { 59, 155, 2, 1, 9 },
    { 65, 150, 2, 1, 9 },
    { 42, 49, 2, 1, 9 },
    { 60, 149, 2, 1, 9 },
    { 95, 42, 2, 1, 9 },
    { 95, 42, 2, 1, 9 },
    { 88, 181, 2, 1, 9 },
    { 95, 42, 2, 1, 9 },
    { 95, 42, 2, 1, 9 },
    { 71, 145, 2, 1, 9 },
    { 69, 139, 2, 1, 9 },
    { 82, 170, 2, 1, 9 },
    { 63, 191, 2, 1, 9 },
    { 92, 48, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 107, 32, 2, 1, 10 },
    { 129, 32, 2, 1, 10 },
    { 116, 32, 2, 1, 10 },
    { 118, 32, 1, 1, 10 },
    { 117, 32, 2, 1, 10 },
    { 102, 32, 2, 1, 10 },
    { 67, 1, 2, 1, 10 },
    { 118, 32, 2, 1, 10 },
    { 115, 32, 2, 1, 10 },
    { 131, 32, 2, 1, 10 },
    { 118, 32, 1, 1, 10 },
    { 116, 32, 2, 1, 10 },
    { 116, 32, 2, 1, 10 },
    { 107, 32, 2, 1, 10 },
    { 116, 32, 2, 1, 10 },
    { 116, 32, 2, 1, 10 },
    { 128, 26, 2, 1, 10 },
    { 100, 3, 2, 1, 10 },
    { 108, 29, 1, 1, 10 },
    { 131, -17, 2, 1, 10 },
    { 112, 32, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -97, 0, 1, 1, 1 },
    { -98, 0, 1, 1, 1 },
    { -103, 0, 1, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -105, 0, 2, 1, 1 },
    { -98, 0, 1, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -96, 0, 1, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -108, 0, 1, 1, 2 },
    { -97, 0, 1, 1, 1 },
    { -98, 0, 1, 1, 2 },
    { -92, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -101, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -108, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -96, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -90, 1, 1, 1, 1 },
    { -86, 7, 1, 1, 1 },
    { -100, -2, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -96, 0, 1, 1, 3 },
    { -78, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -108, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 2 },
    { -101, 0, 1, 1, 3 },
    { -98, 0, 1, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -100, 0, 1, 1, 3 },
    { -104, 0, 1, 1, 3 },
    { -108, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -88, 1, 1, 1, 2 },
    { -89, 4, 1, 1, 2 },
    { -99, -2, 1, 1, 2 },
    { -95, 0, 1, 1, 2 },
    { -92, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -93, 0, 1, 1, 4 },
    { -84, 0, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -108, 0, 1, 1, 4 },
    { -88, 0, 1, 1, 1 },
    { -99, 0, 1, 1, 4 },
    { -81, -1, 1, 1, 4 },
    { -88, 0, 1, 1, 4 },
    { -94, 0, 1, 1, 4 },
    { -132, 0, 1, 1, 4 },
    { -108, 0, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -93, 0, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -85, -5, 1, 1, 3 },
    { -93, 1, 1, 1, 3 },
    { -102, -2, 1, 1, 3 },
    { -99, 0, 1, 1, 3 },
    { -94, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -82, 0, 1, 1, 5 },
    { -117, 0, 1, 1, 5 },
    { -113, 0, 1, 1, 5 },
    { -100, 0, 1, 1, 5 },
    { -97, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 5 },
    { -57, 3, 1, 1, 5 },
    { -100, -12, 1, 1, 5 },
    { -74, 0, 1, 1, 5 },
    { -108, 0, 1, 1, 5 },
    { -100, 0, 1, 1, 5 },
    { -113, 0, 1, 1, 5 },
    { -113, 0, 1, 1, 5 },
    { -82, 0, 1, 1, 5 },
    { -113, 0, 1, 1, 5 },
    { -113, 0, 1, 1, 5 },
    { -94, -5, 1, 1, 4 },
    { -78, 5, 1, 1, 4 },
    { -67, -3, 1, 1, 4 },
    { -109, 0, 1, 1, 4 },
    { -80, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -46, -18, 1, 1, 6 },
    { -48, -9, 1, 1, 6 },
    { -68, 0, 1, 1, 6 },
    { -74, 2, 1, 1, 6 },
    { -79, 1, 1, 1, 4 },
    { -73, 0, 1, 1, 6 },
    { -36, 6, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -75, 0, 1, 1, 6 },
    { -74, 0, 1, 1, 6 },
    { -74, 2, 1, 1, 6 },
    { -68, 0, 1, 1, 6 },
    { -68, 0, 1, 1, 6 },
    { -46, -18, 1, 1, 6 },
    { -68, 0, 1, 1, 6 },
    { -68, 0, 1, 1, 6 },
    { -75, 6, 1, 1, 5 },
    { -53, 8, 1, 1, 5 },
    { -69, -3, 1, 1, 5 },
    { -80, 0, 1, 1, 5 },
    { -56, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -35, -22, 1, 1, 7 },
    { -75, 0, 1, 1, 7 },
    { -76, 0, 1, 1, 7 },
    { -54, 4, 1, 1, 7 },
    { -63, -6, 1, 1, 3 },
    { -62, -1, 1, 1, 7 },
    { -22, 8, 1, 1, 7 },
    { -57, 0, 1, 1, 7 },
    { -63, 0, 1, 1, 7 },
    { -66, 0, 1, 1, 7 },
    { -54, 4, 1, 1, 7 },
    { -76, 0, 1, 1, 7 },
    { -76, 0, 1, 1, 7 },
    { -35, -22, 1, 1, 7 },
    { -76, 0, 1, 1, 7 },
    { -76, 0, 1, 1, 7 },
    { -59, -2, 1, 1, 6 },
    { -37, 0, 1, 1, 6 },
    { -21, -7, 1, 1, 6 },
    { -74, -2, 1, 1, 6 },
    { -38, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -41, -11, 1, 1, 8 },
    { -36, -12, 1, 1, 8 },
    { -60, 4, 1, 1, 8 },
    { -56, -2, 1, 1, 8 },
    { -65, -2, 1, 1, 5 },
    { -63, 2, 1, 1, 8 },
    { -30, 19, 1, 1, 8 },
    { -58, -4, 1, 1, 8 },
    { -53, -1, 1, 1, 8 },
    { -56, 16, 1, 1, 8 },
    { -56, -2, 1, 1, 8 },
    { -60, 4, 1, 1, 8 },
    { -60, 4, 1, 1, 8 },
    { -41, -11, 1, 1, 8 },
    { -60, 4, 1, 1, 8 },
    { -60, 4, 1, 1, 8 },
    { -63, 6, 1, 1, 7 },
    { -40, 6, 1, 1, 7 },
    { -44, -5, 1, 1, 7 },
    { -73, -14, 1, 1, 7 },
    { -40, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -33, -10, 1, 1, 9 },
    { -67, -18, 1, 1, 9 },
    { -67, 18, 1, 1, 9 },
    { -52, 21, 1, 1, 9 },
    { -63, -1, 1, 1, 6 },
    { -52, -15, 1, 1, 9 },
    { -19, 23, 1, 1, 9 },
    { -59, -3, 1, 1, 9 },
    { -63, 7, 1, 1, 9 },
    { -58, 18, 1, 1, 9 },
    { -52, 21, 1, 1, 9 },
    { -67, 18, 1, 1, 9 },
    { -67, 18, 1, 1, 9 },
    { -33, -10, 1, 1, 9 },
    { -67, 18, 1, 1, 9 },
    { -67, 18, 1, 1, 9 },
    { -64, 9, 1, 1, 8 },
    { -38, 11, 1, 1, 8 },
    { -44, -13, 1, 1, 8 },
    { -71, -13, 1, 1, 8 },
    { -52, 4, 1, 1, 8 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -34, -9, 1, 1, 10 },
    { -41, 1, 1, 1, 10 },
    { -64, 24, 1, 1, 10 },
    { -52, 28, 1, 1, 10 },
    { -59, 3, 1, 1, 7 },
    { -54, -10, 1, 1, 10 },
    { 0, 30, 1, 1, 10 },
    { -59, 27, 1, 1, 10 },
    { -66, 37, 1, 1, 10 },
    { -59, 23, 1, 1, 10 },
    { -52, 28, 1, 1, 10 },
    { -64, 24, 1, 1, 10 },
    { -64, 24, 1, 1, 10 },
    { -34, -9, 1, 1, 10 },
    { -64, 24, 1, 1, 10 },
    { -64, 24, 1, 1, 10 },
    { -60, 15, 1, 1, 9 },
    { -38, 16, 1, 1, 9 },
    { -47, 0, 1, 1, 9 },
    { -67, -6, 1, 1, 9 },
    { -42, 6, 1, 1, 9 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -24, 8, 1, 1, 11 },
    { -23, 17, 1, 1, 11 },
    { -49, 38, 1, 1, 11 },
    { -46, 49, 1, 1, 11 },
    { -48, 18, 1, 1, 8 },
    { -29, 84, 1, 1, 11 },
    { 29, 17, 1, 1, 11 },
    { -51, 18, 1, 1, 11 },
    { -45, 69, 1, 1, 11 },
    { -29, 61, 1, 1, 11 },
    { -46, 49, 1, 1, 11 },
    { -49, 38, 1, 1, 11 },
    { -49, 38, 1, 1, 11 },
    { -24, 8, 1, 1, 11 },
    { -49, 38, 1, 1, 11 },
    { -49, 38, 1, 1, 11 },
    { -47, 32, 1, 1, 10 },
    { -28, 38, 1, 1, 10 },
    { -26, 9, 1, 1, 10 },
    { -59, 17, 1, 1, 10 },
    { -26, 19, 1, 1, 10 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 49, 20, 1, 1, 12 },
    { 35, 52, 1, 1, 12 },
    { 39, 34, 1, 1, 12 },
    { 13, 56, 1, 1, 12 },
    { 39, 84, 1, 1, 9 },
    { 53, 32, 1, 1, 12 },
    { 74, -12, 1, 1, 12 },
    { 24, 18, 1, 1, 12 },
    { 35, 86, 1, 1, 12 },
    { 44, 44, 1, 1, 12 },
    { 13, 56, 1, 1, 12 },
    { 39, 22, 1, 1, 12 },
    { 39, 22, 1, 1, 12 },
    { 49, 20, 1, 1, 12 },
    { 39, 34, 1, 1, 12 },
    { 39, 34, 1, 1, 12 },
    { 42, 60, 1, 1, 11 },
    { 50, 87, 1, 1, 11 },
    { 56, 70, 1, 1, 11 },
    { 35, 27, 1, 1, 11 },
    { 42, 88, 1, 1, 11 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 80, 0, 1, 1, 13 },
    { 86, 13, 1, 1, 13 },
    { 82, 6, 1, 1, 13 },
    { 82, -1, 1, 1, 13 },
    { 72, 0, 1, 1, 10 },
    { 86, -20, 1, 1, 13 },
    { 60, 0, 1, 1, 13 },
    { 70, 0, 1, 1, 13 },
    { 115, 74, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 82, -1, 1, 1, 13 },
    { 82, 6, 1, 1, 13 },
    { 82, 6, 1, 1, 13 },
    { 80, 0, 1, 1, 13 },
    { 82, 6, 1, 1, 13 },
    { 82, 6, 1, 1, 13 },
    { 80, 6, 1, 1, 12 },
    { 81, 28, 1, 1, 12 },
    { 71, 0, 1, 1, 12 },
    { 87, 8, 1, 1, 12 },
    { 80, 4, 1, 1, 12 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 96, 0, 1, 0, 14 },
    { 86, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 72, 0, 1, 0, 11 },
    { 86, -20, 2, 0, 14 },
    { 60, 0, 1, 0, 14 },
    { 70, 0, 1, 0, 14 },
    { 115, 0, 2, 0, 14 },
    { 56, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 96, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 82, 0, 1, 0, 14 },
    { 76, 0, 1, 0, 13 },
    { 75, 0, 1, 0, 13 },
    { 67, 0, 1, 0, 13 },
    { 87, 0, 1, 0, 13 },
    { 72, 0, 1, 0, 13 },
    { 0, 0, 1, 0, 14 },
    { 0, 0, 1, 0, 14 },
    { 0, 0, 1, 0, 14 },
    { -79, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -89, 0, 1, 1, 1 },
    { -104, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -97, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { -91, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -104, 0, 1, 1, 1 },
    { -82, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -120, 0, 1, 1, 2 },
    { -84, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -104, 0, 1, 1, 2 },
    { -89, 0, 1, 1, 2 },
    { -97, 0, 1, 1, 2 },
    { -63, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -84, 0, 1, 1, 2 },
    { -120, 0, 1, 1, 2 },
    { -120, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -120, 0, 1, 1, 2 },
    { -120, 0, 1, 1, 2 },
    { -81, -2, 1, 1, 1 },
    { -82, 0, 1, 1, 2 },
    { -73, -14, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 3 },
    { -79, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 3 },
    { -89, 0, 1, 1, 3 },
    { -83, 0, 1, 1, 3 },
    { -94, 0, 1, 1, 3 },
    { -87, -4, 1, 1, 3 },
    { -97, 0, 1, 1, 3 },
    { -76, 0, 1, 1, 3 },
    { -82, 0, 1, 1, 3 },
    { -89, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 3 },
    { -72, -2, 1, 1, 2 },
    { -80, 0, 1, 1, 3 },
    { -85, -2, 1, 1, 2 },
    { -85, 0, 1, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -103, -9, 1, 1, 4 },
    { -79, 0, 1, 1, 4 },
    { -110, 1, 1, 1, 4 },
    { -89, 0, 1, 1, 4 },
    { -76, 0, 1, 1, 4 },
    { -99, 0, 1, 1, 4 },
    { -78, -2, 1, 1, 4 },
    { -97, 0, 1, 1, 4 },
    { -79, 0, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { -89, 0, 1, 1, 4 },
    { -110, 1, 1, 1, 4 },
    { -110, 1, 1, 1, 4 },
    { -103, -9, 1, 1, 4 },
    { -110, 1, 1, 1, 4 },
    { -110, 1, 1, 1, 4 },
    { -70, -5, 1, 1, 3 },
    { -89, 0, 1, 1, 4 },
    { -89, -2, 1, 1, 3 },
    { -89, -2, 1, 1, 3 },
    { -88, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -87, -11, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -103, 1, 1, 1, 5 },
    { -77, 0, 1, 1, 5 },
    { -74, 0, 1, 1, 5 },
    { -101, 80, 1, 1, 5 },
    { -71, -23, 1, 1, 5 },
    { -90, 0, 1, 1, 5 },
    { -53, 0, 1, 1, 5 },
    { -76, 0, 1, 1, 5 },
    { -77, 0, 1, 1, 5 },
    { -103, 1, 1, 1, 5 },
    { -103, 1, 1, 1, 5 },
    { -87, -11, 1, 1, 5 },
    { -103, 1, 1, 1, 5 },
    { -103, 1, 1, 1, 5 },
    { -95, -7, 1, 1, 4 },
    { -74, 0, 1, 1, 5 },
    { -84, 0, 1, 1, 4 },
    { -99, 88, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -52, 134, 1, 1, 6 },
    { -79, 2, 1, 1, 6 },
    { -80, 4, 1, 1, 6 },
    { -74, 0, 1, 1, 6 },
    { -66, 71, 1, 1, 6 },
    { -70, 87, 1, 1, 6 },
    { -34, -1, 1, 1, 6 },
    { -58, 0, 1, 1, 6 },
    { -52, 20, 1, 1, 6 },
    { -64, 0, 1, 1, 6 },
    { -74, 0, 1, 1, 6 },
    { -80, 4, 1, 1, 6 },
    { -80, 4, 1, 1, 6 },
    { -52, 134, 1, 1, 6 },
    { -80, 4, 1, 1, 6 },
    { -80, 4, 1, 1, 6 },
    { -46, 6, 1, 1, 5 },
    { -48, -5, 1, 1, 6 },
    { -46, -6, 1, 1, 5 },
    { -71, 93, 1, 1, 5 },
    { -42, 68, 1, 1, 5 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -46, 124, 1, 1, 7 },
    { -47, 17, 1, 1, 7 },
    { -53, 76, 1, 1, 7 },
    { -69, -16, 1, 1, 7 },
    { -73, 70, 1, 1, 7 },
    { -53, 77, 1, 1, 7 },
    { -45, -11, 1, 1, 7 },
    { -44, 0, 1, 1, 7 },
    { -55, 77, 1, 1, 7 },
    { -64, 0, 1, 1, 7 },
    { -69, -16, 1, 1, 7 },
    { -53, 76, 1, 1, 7 },
    { -53, 76, 1, 1, 7 },
    { -46, 124, 1, 1, 7 },
    { -53, 76, 1, 1, 7 },
    { -53, 76, 1, 1, 7 },
    { -29, 5, 1, 1, 6 },
    { -31, -27, 1, 1, 7 },
    { -22, -6, 1, 1, 6 },
    { -55, 83, 1, 1, 6 },
    { -36, 94, 1, 1, 6 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -32, 39, 1, 1, 8 },
    { -50, -19, 1, 1, 8 },
    { -69, 101, 1, 1, 8 },
    { -66, 78, 1, 1, 8 },
    { -58, 78, 1, 1, 8 },
    { -39, 47, 1, 1, 8 },
    { -50, 13, 1, 1, 8 },
    { -62, 89, 1, 1, 8 },
    { -71, 101, 1, 1, 8 },
    { -62, 112, 1, 1, 8 },
    { -66, 78, 1, 1, 8 },
    { -69, 101, 1, 1, 8 },
    { -69, 101, 1, 1, 8 },
    { -32, 39, 1, 1, 8 },
    { -69, 101, 1, 1, 8 },
    { -69, 101, 1, 1, 8 },
    { -48, 32, 1, 1, 7 },
    { -47, -13, 1, 1, 8 },
    { -34, -15, 1, 1, 7 },
    { -37, 53, 1, 1, 7 },
    { -48, 70, 1, 1, 7 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -31, 212, 1, 1, 9 },
    { -44, 60, 1, 1, 9 },
    { -48, 188, 1, 1, 9 },
    { -38, 166, 1, 1, 9 },
    { -38, 214, 1, 1, 9 },
    { -14, 119, 1, 1, 9 },
    { -7, 213, 1, 1, 9 },
    { -45, 200, 1, 1, 9 },
    { -39, 207, 1, 1, 9 },
    { -38, 173, 1, 1, 9 },
    { -38, 166, 1, 1, 9 },
    { -48, 188, 1, 1, 9 },
    { -48, 188, 1, 1, 9 },
    { -31, 212, 1, 1, 9 },
    { -48, 188, 1, 1, 9 },
    { -48, 188, 1, 1, 9 },
    { -47, 180, 1, 1, 8 },
    { -30, 57, 1, 1, 9 },
    { -24, 207, 1, 1, 8 },
    { -10, 119, 1, 1, 8 },
    { -26, 184, 1, 1, 8 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -10, 64, 1, 1, 10 },
    { -5, 100, 1, 1, 10 },
    { -10, 142, 1, 1, 10 },
    { -9, 208, 1, 1, 10 },
    { 6, 129, 1, 1, 10 },
    { -3, 106, 1, 1, 10 },
    { 30, 173, 1, 1, 10 },
    { -13, 133, 1, 1, 10 },
    { -32, 202, 1, 1, 10 },
    { -25, 197, 1, 1, 10 },
    { -9, 208, 1, 1, 10 },
    { -10, 142, 1, 1, 10 },
    { -10, 142, 1, 1, 10 },
    { -10, 173, 1, 1, 10 },
    { -10, 142, 1, 1, 10 },
    { -10, 142, 1, 1, 10 },
    { -8, 144, 1, 1, 9 },
    { -11, 200, 1, 1, 10 },
    { -19, 129, 1, 1, 9 },
    { 6, 96, 1, 1, 9 },
    { -18, 205, 1, 1, 9 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -1, 70, 1, 1, 11 },
    { 15, 82, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { 34, 117, 1, 1, 11 },
    { 31, 137, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { 9, 47, 1, 1, 11 },
    { 24, 64, 1, 1, 11 },
    { 21, 180, 1, 1, 11 },
    { -5, 91, 1, 1, 11 },
    { 34, 117, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { -1, 70, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { 1, 88, 1, 1, 11 },
    { 13, 144, 1, 1, 10 },
    { 3, 147, 1, 1, 11 },
    { -4, 109, 1, 1, 10 },
    { 11, 88, 1, 1, 10 },
    { 6, 110, 1, 1, 10 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 12 },
    { 1, 74, 1, 1, 12 },
    { -3, 71, 1, 1, 12 },
    { 7, 119, 1, 1, 12 },
    { 35, 97, 1, 1, 12 },
    { 14, 75, 1, 1, 12 },
    { 8, 84, 1, 1, 12 },
    { -7, 221, 1, 1, 12 },
    { -1, 117, 1, 1, 12 },
    { 18, 119, 1, 1, 12 },
    { 17, 99, 1, 1, 12 },
    { 35, 97, 1, 1, 12 },
    { 7, 119, 1, 1, 12 },
    { 7, 119, 1, 1, 12 },
    { 1, 74, 1, 1, 12 },
    { 7, 119, 1, 1, 12 },
    { 7, 119, 1, 1, 12 },
    { 7, 133, 1, 1, 11 },
    { 2, 136, 1, 1, 12 },
    { 7, 79, 1, 1, 11 },
    { 15, 76, 1, 1, 11 },
    { -6, 136, 1, 1, 11 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -76, 64, 1, 1, 13 },
    { -81, 123, 1, 1, 13 },
    { -57, 118, 1, 1, 13 },
    { -40, 81, 1, 1, 13 },
    { -64, 54, 1, 1, 13 },
    { -67, 103, 1, 1, 13 },
    { -62, 201, 1, 1, 13 },
    { -56, 88, 1, 1, 13 },
    { -76, 188, 1, 1, 13 },
    { -80, 76, 1, 1, 13 },
    { -40, 81, 1, 1, 13 },
    { -57, 118, 1, 1, 13 },
    { -57, 118, 1, 1, 13 },
    { -76, 64, 1, 1, 13 },
    { -57, 118, 1, 1, 13 },
    { -57, 118, 1, 1, 13 },
    { -88, 176, 1, 1, 12 },
    { -76, 119, 1, 1, 13 },
    { -83, 112, 1, 1, 12 },
    { -67, 63, 1, 1, 12 },
    { -70, 104, 1, 1, 12 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { -77, 31, 1, 1, 14 },
    { -73, 15, 1, 1, 14 },
    { -63, 20, 1, 1, 14 },
    { -121, 103, 1, 1, 14 },
    { -77, 5, 1, 1, 14 },
    { -84, 3, 1, 1, 14 },
    { -106, 0, 1, 1, 14 },
    { -64, 28, 1, 1, 14 },
    { -90, 123, 1, 1, 14 },
    { -72, -2, 1, 1, 14 },
    { -121, 103, 1, 1, 14 },
    { -63, 20, 1, 1, 14 },
    { -63, 20, 1, 1, 14 },
    { -77, 31, 1, 1, 14 },
    { -63, 20, 1, 1, 14 },
    { -63, 20, 1, 1, 14 },
    { -104, 96, 1, 1, 13 },
    { -89, 30, 1, 1, 14 },
    { -90, 37, 1, 1, 13 },
    { -83, -12, 1, 1, 13 },
    { -86, 38, 1, 1, 13 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { -76, 0, 1, 1, 15 },
    { -61, 0, 1, 1, 15 },
    { -59, 0, 1, 1, 15 },
    { -61, 0, 1, 1, 15 },
    { -52, -2, 1, 1, 15 },
    { -83, 0, 1, 1, 15 },
    { -112, 0, 1, 1, 15 },
    { -52, 0, 1, 1, 15 },
    { -104, 65, 1, 1, 15 },
    { -55, 0, 1, 1, 15 },
    { -61, 0, 1, 1, 15 },
    { -59, 0, 1, 1, 15 },
    { -59, 0, 1, 1, 15 },
    { -76, 0, 1, 1, 15 },
    { -59, 0, 1, 1, 15 },
    { -59, 0, 1, 1, 15 },
    { -88, -1, 1, 1, 14 },
    { -82, 23, 1, 1, 15 },
    { -104, -5, 1, 1, 14 },
    { -83, 0, 1, 1, 14 },
    { -80, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { -88, 0, 1, 1, 1 },
    { -66, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -108, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -69, 0, 1, 1, 1 },
    { -105, 0, 2, 1, 1 },
    { -76, 0, 1, 1, 1 },
    { -108, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -93, 0, 1, 1, 1 },
    { -86, 0, 1, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -100, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -106, 0, 1, 1, 1 },
    { -86, 0, 1, 1, 1 },
    { -93, 0, 1, 1, 1 },
    { -75, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 2 },
    { -75, 0, 1, 1, 1 },
    { -106, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 2 },
    { -90, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -93, 0, 1, 1, 2 },
    { -100, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 1, 1, 3 },
    { -99, 0, 1, 1, 2 },
    { -99, 0, 1, 1, 2 },
    { -95, 0, 1, 1, 2 },
    { -86, 0, 1, 1, 2 },
    { -106, 0, 1, 1, 2 },
    { -62, 0, 1, 1, 3 },
    { -88, 0, 1, 1, 2 },
    { -111, 0, 1, 1, 3 },
    { -76, 5, 1, 1, 2 },
    { -95, 0, 1, 1, 2 },
    { -99, 0, 1, 1, 2 },
    { -99, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 3 },
    { -99, 0, 1, 1, 2 },
    { -99, 0, 1, 1, 2 },
    { -87, 0, 1, 1, 3 },
    { -82, 0, 1, 1, 2 },
    { -79, -6, 1, 1, 2 },
    { -119, 2, 1, 1, 3 },
    { -98, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 4 },
    { -73, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -49, 3, 1, 1, 4 },
    { -69, 4, 1, 1, 3 },
    { -43, 2, 1, 1, 4 },
    { -47, 21, 1, 1, 3 },
    { -63, 0, 1, 1, 4 },
    { -48, 8, 1, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -60, 5, 1, 1, 4 },
    { -37, 10, 1, 1, 3 },
    { -41, -1, 1, 1, 3 },
    { -64, 2, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, 0, 2, 1, 5 },
    { -29, 0, 2, 1, 4 },
    { -36, 6, 2, 1, 4 },
    { -23, 23, 2, 1, 4 },
    { -10, -8, 2, 1, 4 },
    { -12, -2, 2, 1, 4 },
    { -24, 0, 2, 1, 5 },
    { -10, 9, 2, 1, 4 },
    { -45, 0, 2, 1, 5 },
    { -34, 8, 2, 1, 4 },
    { -23, 23, 2, 1, 4 },
    { -36, 6, 2, 1, 4 },
    { -36, 6, 2, 1, 4 },
    { -16, 0, 2, 1, 5 },
    { -36, 6, 2, 1, 4 },
    { -36, 6, 2, 1, 4 },
    { -24, 6, 2, 1, 5 },
    { -20, 18, 2, 1, 4 },
    { -58, -8, 2, 1, 4 },
    { -31, -3, 2, 1, 5 },
    { -16, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 6 },
    { -28, 0, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -23, 18, 2, 1, 5 },
    { -17, -8, 2, 1, 5 },
    { -19, -2, 2, 1, 5 },
    { -35, 0, 2, 1, 6 },
    { -21, 6, 2, 1, 5 },
    { -43, 0, 2, 1, 5 },
    { -34, 8, 2, 1, 5 },
    { -23, 18, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -18, 0, 2, 1, 6 },
    { -33, 0, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -18, 12, 2, 1, 6 },
    { -20, 18, 2, 1, 5 },
    { -46, -8, 2, 1, 5 },
    { -27, -4, 2, 1, 6 },
    { -16, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 7 },
    { -28, 0, 2, 1, 6 },
    { -31, 0, 2, 1, 6 },
    { -23, 18, 2, 1, 6 },
    { -25, -6, 2, 1, 6 },
    { -14, -2, 2, 1, 6 },
    { -31, 0, 2, 1, 7 },
    { -16, 6, 2, 1, 6 },
    { -48, 0, 2, 1, 6 },
    { -35, 8, 2, 1, 6 },
    { -23, 18, 2, 1, 6 },
    { -31, 0, 2, 1, 6 },
    { -31, 0, 2, 1, 6 },
    { -18, 0, 2, 1, 7 },
    { -31, 0, 2, 1, 6 },
    { -31, 0, 2, 1, 6 },
    { -16, 4, 2, 1, 7 },
    { -21, 15, 2, 1, 6 },
    { -48, -13, 2, 1, 6 },
    { -27, -4, 2, 1, 7 },
    { -16, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 7 },
    { -41, 0, 2, 1, 7 },
    { -34, 0, 2, 1, 7 },
    { -24, 6, 2, 1, 7 },
    { -24, -6, 2, 1, 7 },
    { -66, 0, 2, 1, 7 },
    { -31, 0, 2, 1, 7 },
    { -54, 0, 2, 1, 7 },
    { -48, 0, 2, 1, 7 },
    { -26, 13, 2, 1, 7 },
    { -24, 6, 2, 1, 7 },
    { -34, 0, 2, 1, 7 },
    { -34, 0, 2, 1, 7 },
    { -18, 0, 2, 1, 7 },
    { -34, 0, 2, 1, 7 },
    { -34, 0, 2, 1, 7 },
    { -30, 0, 2, 1, 8 },
    { -18, 0, 2, 1, 7 },
    { -41, 0, 2, 1, 7 },
    { -38, -4, 2, 1, 8 },
    { -24, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -44, 0, 2, 0, 8 },
    { -50, 0, 2, 0, 8 },
    { -66, 0, 2, 0, 8 },
    { -40, 0, 2, 0, 8 },
    { -54, 0, 2, 0, 8 },
    { -48, 0, 2, 0, 8 },
    { -50, 0, 2, 0, 8 },
    { -44, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -18, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -34, 0, 2, 0, 8 },
    { -31, 0, 2, 0, 9 },
    { -24, 0, 2, 0, 8 },
    { -41, 0, 2, 0, 8 },
    { -38, -4, 2, 0, 9 },
    { -24, 0, 2, 0, 9 },
    { 0, 0, 2, 0, 1 },
    { 0, 0, 2, 0, 1 },
    { 0, 0, 2, 0, 1 },
    { -96, 0, 1, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -98, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -105, 0, 2, 1, 1 },
    { -92, 0, 1, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -98, 0, 1, 1, 1 },
    { -92, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 2 },
    { -71, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -108, 0, 1, 1, 2 },
    { -94, 0, 1, 1, 1 },
    { -103, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 2 },
    { -73, 0, 1, 1, 2 },
    { -104, 0, 1, 1, 2 },
    { -108, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -96, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -90, 1, 1, 1, 1 },
    { -86, 7, 1, 1, 1 },
    { -100, -2, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -96, 0, 1, 1, 3 },
    { -77, 0, 1, 1, 3 },
    { -105, 0, 1, 1, 3 },
    { -108, 0, 1, 1, 3 },
    { -92, 0, 1, 1, 2 },
    { -101, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -83, 0, 1, 1, 3 },
    { -69, 0, 1, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -108, 0, 1, 1, 3 },
    { -105, 0, 1, 1, 3 },
    { -105, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -105, 0, 1, 1, 3 },
    { -105, 0, 1, 1, 3 },
    { -88, 1, 1, 1, 2 },
    { -89, 4, 1, 1, 2 },
    { -99, -2, 1, 1, 2 },
    { -95, 0, 1, 1, 2 },
    { -92, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -93, 0, 1, 1, 4 },
    { -89, -21, 1, 1, 4 },
    { -105, 0, 1, 1, 4 },
    { -113, 0, 1, 1, 4 },
    { -95, 0, 1, 1, 1 },
    { -105, 0, 1, 1, 4 },
    { -99, 0, 1, 1, 4 },
    { -103, 0, 1, 1, 4 },
    { -85, 0, 1, 1, 4 },
    { -80, 0, 1, 1, 4 },
    { -113, 0, 1, 1, 4 },
    { -105, 0, 1, 1, 4 },
    { -105, 0, 1, 1, 4 },
    { -93, 0, 1, 1, 4 },
    { -105, 0, 1, 1, 4 },
    { -105, 0, 1, 1, 4 },
    { -85, -5, 1, 1, 3 },
    { -93, 1, 1, 1, 3 },
    { -102, -2, 1, 1, 3 },
    { -99, 0, 1, 1, 3 },
    { -94, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -82, 0, 1, 1, 5 },
    { -87, -21, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -100, 0, 1, 1, 5 },
    { -97, 0, 1, 1, 3 },
    { -97, 0, 1, 1, 5 },
    { -71, 0, 1, 1, 5 },
    { -90, 0, 1, 1, 5 },
    { -87, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { -100, 0, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -82, 0, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -94, -5, 1, 1, 4 },
    { -78, 5, 1, 1, 4 },
    { -67, -3, 1, 1, 4 },
    { -109, 0, 1, 1, 4 },
    { -80, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -46, -18, 1, 1, 6 },
    { -56, -16, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { -70, 2, 1, 1, 6 },
    { -83, 1, 1, 1, 4 },
    { -66, 0, 1, 1, 6 },
    { -51, 11, 1, 1, 6 },
    { -57, 0, 1, 1, 5 },
    { -76, 0, 1, 1, 6 },
    { -58, 0, 1, 1, 6 },
    { -70, 2, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { -46, -18, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { -75, 6, 1, 1, 5 },
    { -53, 8, 1, 1, 5 },
    { -69, -3, 1, 1, 5 },
    { -80, 0, 1, 1, 5 },
    { -42, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -35, -22, 1, 1, 7 },
    { -38, -24, 1, 1, 7 },
    { -21, 0, 1, 1, 7 },
    { -54, 4, 1, 1, 7 },
    { -62, -4, 1, 1, 3 },
    { -67, 0, 1, 1, 7 },
    { -18, -17, 1, 1, 7 },
    { -44, 0, 1, 1, 6 },
    { -61, 0, 1, 1, 7 },
    { -45, 0, 1, 1, 7 },
    { -54, 4, 1, 1, 7 },
    { -21, 0, 1, 1, 7 },
    { -21, 0, 1, 1, 7 },
    { -35, -22, 1, 1, 7 },
    { -21, 0, 1, 1, 7 },
    { -21, 0, 1, 1, 7 },
    { -59, -2, 1, 1, 6 },
    { -37, 0, 1, 1, 6 },
    { -21, -7, 1, 1, 6 },
    { -74, -2, 1, 1, 6 },
    { -24, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -41, -11, 2, 1, 8 },
    { -39, 0, 1, 1, 8 },
    { -20, 88, 1, 1, 8 },
    { -57, -2, 1, 1, 8 },
    { -69, -2, 1, 1, 5 },
    { -72, 2, 1, 1, 8 },
    { -52, -1, 1, 1, 8 },
    { -50, 10, 1, 1, 6 },
    { -55, 0, 1, 1, 8 },
    { -59, 12, 1, 1, 8 },
    { -57, -2, 1, 1, 8 },
    { -20, 88, 1, 1, 8 },
    { -20, 88, 1, 1, 8 },
    { -41, -11, 2, 1, 8 },
    { -20, 88, 1, 1, 8 },
    { -20, 88, 1, 1, 8 },
    { -63, 6, 1, 1, 7 },
    { -40, 6, 1, 1, 7 },
    { -44, -5, 1, 1, 7 },
    { -73, -14, 1, 1, 7 },
    { -40, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -33, -10, 2, 1, 9 },
    { -32, -8, 1, 1, 9 },
    { -49, 4, 1, 1, 9 },
    { -57, -3, 1, 1, 9 },
    { -64, -1, 1, 1, 6 },
    { -53, -15, 1, 1, 9 },
    { -53, 10, 1, 1, 9 },
    { -60, 0, 1, 1, 7 },
    { -63, 7, 1, 1, 9 },
    { -23, 106, 1, 1, 9 },
    { -57, -3, 1, 1, 9 },
    { -49, 4, 1, 1, 9 },
    { -49, 4, 1, 1, 9 },
    { -33, -10, 2, 1, 9 },
    { -49, 4, 1, 1, 9 },
    { -49, 4, 1, 1, 9 },
    { -64, 9, 1, 1, 8 },
    { -38, 11, 1, 1, 8 },
    { -44, -13, 1, 1, 8 },
    { -71, -13, 1, 1, 8 },
    { -52, 4, 1, 1, 8 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -34, -9, 2, 1, 10 },
    { -32, 2, 1, 1, 10 },
    { -48, 22, 1, 1, 10 },
    { -49, 6, 1, 1, 10 },
    { -59, 3, 1, 1, 7 },
    { -55, -10, 1, 1, 10 },
    { -50, 14, 1, 1, 10 },
    { -56, 12, 1, 1, 7 },
    { -66, 37, 1, 1, 10 },
    { -42, 16, 1, 1, 10 },
    { -49, 6, 1, 1, 10 },
    { -48, 22, 1, 1, 10 },
    { -48, 22, 1, 1, 10 },
    { -34, -9, 2, 1, 10 },
    { -48, 22, 1, 1, 10 },
    { -48, 22, 1, 1, 10 },
    { -60, 15, 1, 1, 9 },
    { -38, 16, 1, 1, 9 },
    { -47, 0, 1, 1, 9 },
    { -67, -6, 1, 1, 9 },
    { -42, 6, 1, 1, 9 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -24, 8, 2, 1, 11 },
    { -30, 14, 1, 1, 11 },
    { -43, 50, 1, 1, 11 },
    { -34, 26, 1, 1, 11 },
    { -48, 18, 1, 1, 8 },
    { -36, 84, 1, 1, 11 },
    { -34, 38, 1, 1, 11 },
    { -49, 20, 1, 1, 8 },
    { -45, 69, 1, 1, 11 },
    { -27, 32, 1, 1, 11 },
    { -34, 26, 1, 1, 11 },
    { -43, 50, 1, 1, 11 },
    { -43, 50, 1, 1, 11 },
    { -24, 8, 2, 1, 11 },
    { -43, 50, 1, 1, 11 },
    { -43, 50, 1, 1, 11 },
    { -47, 32, 1, 1, 10 },
    { -28, 38, 1, 1, 10 },
    { -26, 9, 1, 1, 10 },
    { -59, 17, 1, 1, 10 },
    { -26, 19, 1, 1, 10 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 49, 20, 1, 1, 12 },
    { 37, 50, 1, 1, 12 },
    { 40, 73, 1, 1, 12 },
    { 26, 34, 1, 1, 12 },
    { 39, 84, 1, 1, 9 },
    { 47, 40, 1, 1, 12 },
    { 46, 122, 1, 1, 12 },
    { 48, 74, 1, 1, 9 },
    { 36, 86, 1, 1, 12 },
    { 57, 28, 1, 1, 12 },
    { 26, 34, 1, 1, 12 },
    { 40, 73, 1, 1, 12 },
    { 40, 73, 1, 1, 12 },
    { 49, 20, 1, 1, 12 },
    { 40, 73, 1, 1, 12 },
    { 40, 73, 1, 1, 12 },
    { 42, 60, 1, 1, 11 },
    { 50, 87, 1, 1, 11 },
    { 56, 70, 1, 1, 11 },
    { 35, 27, 1, 1, 11 },
    { 42, 88, 1, 1, 11 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 72, 0, 1, 1, 13 },
    { 56, 8, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 64, 0, 1, 1, 13 },
    { 48, 0, 1, 1, 10 },
    { 72, 0, 1, 1, 13 },
    { 69, 114, 1, 1, 13 },
    { 48, 0, 1, 1, 10 },
    { 96, 62, 1, 1, 13 },
    { 48, 0, 1, 1, 13 },
    { 64, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 72, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 74, 6, 1, 1, 12 },
    { 69, 54, 1, 1, 12 },
    { 63, 0, 1, 1, 12 },
    { 71, 8, 1, 1, 12 },
    { 80, 4, 1, 1, 12 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 64, 0, 1, 1, 13 },
    { 56, 8, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 64, 0, 1, 1, 13 },
    { 48, 0, 1, 1, 10 },
    { 72, 0, 1, 1, 13 },
    { 69, 118, 1, 1, 13 },
    { 48, 0, 1, 1, 10 },
    { 72, 74, 1, 1, 14 },
    { 48, 0, 1, 1, 14 },
    { 64, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 64, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 56, 0, 1, 1, 13 },
    { 60, 2, 1, 0, 13 },
    { 63, 28, 1, 0, 13 },
    { 54, 0, 1, 0, 13 },
    { 64, 0, 1, 0, 13 },
    { 64, 0, 1, 0, 13 },
    { 0, 0, 1, 0, 14 },
    { 0, 0, 1, 0, 14 },
    { 0, 0, 1, 0, 14 },
    { 36, 76, 1, 1, 14 },
    { 62, 72, 1, 1, 14 },
    { 55, 52, 1, 1, 14 },
    { 76, 56, 1, 1, 14 },
    { 53, 76, 1, 1, 11 },
    { 40, -17, 1, 1, 14 },
    { 41, 80, 1, 1, 14 },
    { 33, 19, 1, 1, 11 },
    { 61, 42, 1, 1, 15 },
    { 47, 18, 1, 1, 15 },
    { 76, 56, 1, 1, 14 },
    { 55, 52, 1, 1, 14 },
    { 55, 52, 1, 1, 14 },
    { 36, 76, 1, 1, 14 },
    { 55, 52, 1, 1, 14 },
    { 55, 52, 1, 1, 14 },
    { 39, -28, 1, 1, 14 },
    { 40, 16, 1, 1, 14 },
    { 21, 40, 1, 1, 14 },
    { 50, 81, 1, 1, 14 },
    { 44, 18, 1, 1, 14 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 24, 76, 1, 1, 15 },
    { 52, 72, 1, 1, 15 },
    { 44, 12, 1, 1, 15 },
    { 62, 42, 1, 1, 15 },
    { 39, 78, 1, 1, 12 },
    { 55, 58, 1, 1, 15 },
    { 25, 67, 1, 1, 15 },
    { 22, 20, 1, 1, 12 },
    { 35, 21, 1, 1, 16 },
    { 32, 24, 1, 1, 16 },
    { 62, 42, 1, 1, 15 },
    { 44, 12, 1, 1, 15 },
    { 44, 12, 1, 1, 15 },
    { 24, 76, 1, 1, 15 },
    { 44, 12, 1, 1, 15 },
    { 44, 12, 1, 1, 15 },
    { 19, -46, 1, 1, 15 },
    { 27, -20, 1, 1, 15 },
    { 31, -45, 1, 1, 15 },
    { 32, 51, 1, 1, 15 },
    { 28, -42, 1, 1, 15 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 4, -56, 1, 1, 16 },
    { 20, 42, 1, 1, 16 },
    { 17, 48, 1, 1, 16 },
    { 44, 38, 1, 1, 16 },
    { 18, 60, 1, 1, 13 },
    { 23, 62, 1, 1, 16 },
    { 22, 6, 1, 1, 16 },
    { -5, 23, 1, 1, 13 },
    { 18, 8, 1, 1, 17 },
    { 7, 42, 1, 1, 17 },
    { 44, 38, 1, 1, 16 },
    { 17, 48, 1, 1, 16 },
    { 17, 48, 1, 1, 16 },
    { 4, -56, 1, 1, 16 },
    { 17, 48, 1, 1, 16 },
    { 17, 48, 1, 1, 16 },
    { 8, -48, 1, 1, 16 },
    { 14, -48, 1, 1, 16 },
    { 4, -52, 1, 1, 16 },
    { 6, -48, 1, 1, 16 },
    { -2, -56, 1, 1, 16 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -12, -48, 1, 1, 17 },
    { -5, 46, 1, 1, 17 },
    { -3, 10, 1, 1, 17 },
    { -10, 6, 1, 1, 17 },
    { 0, 18, 1, 1, 14 },
    { -10, 12, 1, 1, 17 },
    { -28, -78, 1, 1, 17 },
    { -21, 15, 1, 1, 14 },
    { 2, 6, 1, 1, 17 },
    { -9, 37, 1, 1, 18 },
    { -10, 6, 1, 1, 17 },
    { -3, 10, 1, 1, 17 },
    { -3, 10, 1, 1, 17 },
    { -12, -48, 1, 1, 17 },
    { -3, 10, 1, 1, 17 },
    { -3, 10, 1, 1, 17 },
    { -11, -49, 1, 1, 17 },
    { -4, -48, 1, 1, 17 },
    { -16, -50, 1, 1, 17 },
    { -10, -48, 1, 1, 17 },
    { -20, -52, 1, 1, 17 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 36, 76, 1, 1, 18 },
    { 72, -24, 1, 1, 18 },
    { 49, -24, 1, 1, 18 },
    { 51, -32, 1, 1, 18 },
    { 70, -28, 1, 1, 15 },
    { 41, -32, 1, 1, 18 },
    { 36, -33, 1, 1, 18 },
    { 56, -32, 1, 1, 15 },
    { 11, 42, 1, 1, 18 },
    { 72, -31, 1, 1, 19 },
    { 51, -32, 1, 1, 18 },
    { 49, -24, 1, 1, 18 },
    { 49, -24, 1, 1, 18 },
    { 36, 76, 1, 1, 18 },
    { 49, -24, 1, 1, 18 },
    { 49, -24, 1, 1, 18 },
    { 39, -28, 1, 1, 18 },
    { 40, 16, 1, 1, 18 },
    { 21, 40, 1, 1, 18 },
    { 50, 81, 1, 1, 18 },
    { 40, 18, 1, 1, 18 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 20, 76, 1, 1, 19 },
    { 9, 12, 1, 1, 19 },
    { 10, 46, 1, 1, 19 },
    { 12, 0, 1, 1, 19 },
    { 12, 74, 1, 1, 16 },
    { 12, -91, 1, 1, 19 },
    { 37, -40, 1, 1, 19 },
    { 28, 9, 1, 1, 16 },
    { 2, 29, 1, 1, 19 },
    { 23, 47, 1, 1, 20 },
    { 12, 0, 1, 1, 19 },
    { 10, 46, 1, 1, 19 },
    { 10, 46, 1, 1, 19 },
    { 20, 76, 1, 1, 19 },
    { 10, 46, 1, 1, 19 },
    { 10, 46, 1, 1, 19 },
    { 19, -46, 1, 1, 19 },
    { 27, -20, 1, 1, 19 },
    { 31, -45, 1, 1, 19 },
    { 32, 51, 1, 1, 19 },
    { 22, -42, 1, 1, 19 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 4, -56, 1, 1, 20 },
    { -3, 52, 1, 1, 20 },
    { -2, 12, 1, 1, 20 },
    { 4, 8, 1, 1, 20 },
    { -7, 72, 1, 1, 17 },
    { 3, 62, 1, 1, 20 },
    { 1, -46, 1, 1, 20 },
    { 6, 15, 1, 1, 17 },
    { -8, 21, 1, 1, 20 },
    { 1, 43, 1, 1, 21 },
    { 4, 8, 1, 1, 20 },
    { -2, 12, 1, 1, 20 },
    { -2, 12, 1, 1, 20 },
    { 4, -56, 1, 1, 20 },
    { -2, 12, 1, 1, 20 },
    { -2, 12, 1, 1, 20 },
    { 8, -48, 1, 1, 20 },
    { 14, -48, 1, 1, 20 },
    { 4, -52, 1, 1, 20 },
    { 6, -48, 1, 1, 20 },
    { 2, -50, 1, 1, 20 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -12, -48, 1, 1, 21 },
    { -27, 42, 1, 1, 21 },
    { -16, 14, 1, 1, 21 },
    { -21, 8, 1, 1, 21 },
    { -23, 72, 1, 1, 18 },
    { -25, 26, 1, 1, 21 },
    { -29, -49, 1, 1, 21 },
    { -7, 25, 1, 1, 18 },
    { -23, 3, 1, 1, 21 },
    { -17, 38, 1, 1, 22 },
    { -21, 8, 1, 1, 21 },
    { -16, 14, 1, 1, 21 },
    { -16, 14, 1, 1, 21 },
    { -12, -48, 1, 1, 21 },
    { -16, 14, 1, 1, 21 },
    { -16, 14, 1, 1, 21 },
    { -11, -49, 1, 1, 21 },
    { -4, -48, 1, 1, 21 },
    { -16, -50, 1, 1, 21 },
    { -10, -48, 1, 1, 21 },
    { -8, -52, 1, 1, 21 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -40, 132, 1, 1, 22 },
    { -53, 72, 1, 1, 22 },
    { -70, 102, 1, 1, 22 },
    { -74, 76, 1, 1, 22 },
    { -68, 136, 1, 1, 19 },
    { -64, 84, 1, 1, 22 },
    { -54, 3, 1, 1, 22 },
    { -69, 93, 1, 1, 19 },
    { -62, 19, 1, 1, 22 },
    { -58, 102, 1, 1, 23 },
    { -74, 76, 1, 1, 22 },
    { -70, 102, 1, 1, 22 },
    { -70, 102, 1, 1, 22 },
    { -40, 132, 1, 1, 22 },
    { -70, 102, 1, 1, 22 },
    { -70, 102, 1, 1, 22 },
    { -46, 6, 1, 1, 22 },
    { -48, -5, 1, 1, 22 },
    { -46, -6, 1, 1, 22 },
    { -71, 93, 1, 1, 22 },
    { -42, 68, 1, 1, 22 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -32, 134, 1, 1, 23 },
    { -55, -20, 1, 1, 23 },
    { -63, 104, 1, 1, 23 },
    { -66, 76, 1, 1, 23 },
    { -60, 116, 1, 1, 20 },
    { -52, 74, 1, 1, 23 },
    { -54, 3, 1, 1, 23 },
    { -62, 86, 1, 1, 20 },
    { -71, 101, 1, 1, 23 },
    { -55, 106, 1, 1, 24 },
    { -66, 76, 1, 1, 23 },
    { -63, 104, 1, 1, 23 },
    { -63, 104, 1, 1, 23 },
    { -32, 134, 1, 1, 23 },
    { -63, 104, 1, 1, 23 },
    { -63, 104, 1, 1, 23 },
    { -48, 32, 1, 1, 23 },
    { -47, -13, 1, 1, 23 },
    { -34, -15, 1, 1, 23 },
    { -37, 53, 1, 1, 23 },
    { -48, 70, 1, 1, 23 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -4, 116, 1, 1, 24 },
    { -47, 59, 1, 1, 24 },
    { -50, 188, 1, 1, 24 },
    { -48, 162, 1, 1, 24 },
    { -45, 216, 1, 1, 21 },
    { -31, 118, 1, 1, 24 },
    { -24, 71, 1, 1, 24 },
    { -53, 171, 1, 1, 21 },
    { -33, 203, 1, 1, 24 },
    { -37, 165, 1, 1, 25 },
    { -48, 162, 1, 1, 24 },
    { -48, 188, 1, 1, 24 },
    { -48, 188, 1, 1, 24 },
    { -4, 116, 1, 1, 24 },
    { -50, 188, 1, 1, 24 },
    { -50, 188, 1, 1, 24 },
    { -47, 180, 1, 1, 24 },
    { -30, 57, 1, 1, 24 },
    { -24, 207, 1, 1, 24 },
    { -10, 119, 1, 1, 24 },
    { -26, 184, 1, 1, 24 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 4, 64, 1, 1, 25 },
    { -5, 103, 1, 1, 25 },
    { 4, 133, 1, 1, 25 },
    { -19, 202, 1, 1, 25 },
    { 4, 129, 1, 1, 22 },
    { -12, 115, 1, 1, 25 },
    { 22, 46, 1, 1, 25 },
    { -29, 198, 1, 1, 22 },
    { -30, 208, 1, 1, 25 },
    { -25, 182, 1, 1, 26 },
    { -19, 202, 1, 1, 25 },
    { 4, 133, 1, 1, 25 },
    { 4, 133, 1, 1, 25 },
    { 4, 64, 1, 1, 25 },
    { 4, 133, 1, 1, 25 },
    { 4, 133, 1, 1, 25 },
    { -8, 144, 1, 1, 25 },
    { -11, 200, 1, 1, 25 },
    { -19, 129, 1, 1, 25 },
    { 6, 96, 1, 1, 25 },
    { -18, 205, 1, 1, 25 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 4, 84, 1, 1, 26 },
    { 9, 85, 1, 1, 26 },
    { 17, 147, 1, 1, 26 },
    { 39, 115, 1, 1, 26 },
    { 19, 146, 1, 1, 23 },
    { 1, 88, 1, 1, 26 },
    { 29, 84, 1, 1, 26 },
    { 4, 142, 1, 1, 23 },
    { 25, 185, 1, 1, 26 },
    { -4, 90, 1, 1, 27 },
    { 39, 115, 1, 1, 26 },
    { 17, 147, 1, 1, 26 },
    { 17, 147, 1, 1, 26 },
    { 4, 84, 1, 1, 26 },
    { 17, 147, 1, 1, 26 },
    { 17, 147, 1, 1, 26 },
    { 13, 144, 1, 1, 26 },
    { 3, 147, 1, 1, 26 },
    { -4, 109, 1, 1, 26 },
    { 11, 88, 1, 1, 26 },
    { 6, 110, 1, 1, 26 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -4, 72, 1, 1, 27 },
    { 3, 72, 1, 1, 27 },
    { 11, 125, 1, 1, 27 },
    { 37, 96, 1, 1, 27 },
    { 14, 75, 1, 1, 24 },
    { 4, 93, 1, 1, 27 },
    { -7, 66, 1, 1, 27 },
    { 5, 123, 1, 1, 24 },
    { 18, 119, 1, 1, 27 },
    { 19, 101, 1, 1, 28 },
    { 37, 96, 1, 1, 27 },
    { 11, 125, 1, 1, 27 },
    { 11, 125, 1, 1, 27 },
    { -4, 72, 1, 1, 27 },
    { 11, 125, 1, 1, 27 },
    { 11, 125, 1, 1, 27 },
    { 7, 133, 1, 1, 27 },
    { 2, 136, 1, 1, 27 },
    { 7, 79, 1, 1, 27 },
    { 15, 76, 1, 1, 27 },
    { -6, 136, 1, 1, 27 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -68, 56, 1, 1, 28 },
    { -79, 126, 1, 1, 28 },
    { -55, 71, 1, 1, 28 },
    { -46, 80, 1, 1, 28 },
    { -69, 76, 1, 1, 25 },
    { -71, 98, 1, 1, 28 },
    { -51, 180, 1, 1, 28 },
    { -56, 90, 1, 1, 25 },
    { -78, 185, 1, 1, 28 },
    { -80, 76, 1, 1, 29 },
    { -46, 80, 1, 1, 28 },
    { -68, 60, 1, 1, 28 },
    { -68, 60, 1, 1, 28 },
    { -68, 56, 1, 1, 28 },
    { -55, 71, 1, 1, 28 },
    { -55, 71, 1, 1, 28 },
    { -88, 176, 1, 1, 28 },
    { -76, 119, 1, 1, 28 },
    { -83, 112, 1, 1, 28 },
    { -67, 63, 1, 1, 28 },
    { -70, 104, 1, 1, 28 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -80, -8, 1, 1, 29 },
    { -56, 26, 1, 1, 29 },
    { -60, 20, 1, 1, 29 },
    { -122, 104, 1, 1, 29 },
    { -77, 35, 1, 1, 26 },
    { -84, 3, 1, 1, 29 },
    { -59, 0, 1, 1, 29 },
    { -72, 32, 1, 1, 26 },
    { -90, 124, 1, 1, 29 },
    { -71, 3, 1, 1, 30 },
    { -126, 104, 1, 1, 29 },
    { -68, 32, 1, 1, 29 },
    { -68, 32, 1, 1, 29 },
    { -80, -8, 1, 1, 29 },
    { -60, 20, 1, 1, 29 },
    { -60, 20, 1, 1, 29 },
    { -104, 96, 1, 1, 29 },
    { -89, 30, 1, 1, 29 },
    { -90, 37, 1, 1, 29 },
    { -83, -12, 1, 1, 29 },
    { -86, 38, 1, 1, 29 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 30 },
    { -64, 0, 1, 1, 30 },
    { -61, 0, 1, 1, 30 },
    { -68, 0, 1, 1, 30 },
    { -55, 0, 1, 1, 27 },
    { -83, 0, 1, 1, 30 },
    { -59, 0, 1, 1, 30 },
    { -64, 0, 1, 1, 27 },
    { -105, 64, 1, 1, 30 },
    { -64, 0, 1, 1, 31 },
    { -68, 0, 1, 1, 30 },
    { -61, 0, 1, 1, 30 },
    { -61, 0, 1, 1, 30 },
    { -60, 0, 1, 1, 30 },
    { -61, 0, 1, 1, 30 },
    { -61, 0, 1, 1, 30 },
    { -88, -1, 1, 1, 30 },
    { -82, 23, 1, 1, 30 },
    { -104, -5, 1, 1, 30 },
    { -83, 0, 1, 1, 30 },
    { -80, -3, 1, 1, 30 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 31 },
    { -64, 0, 1, 1, 31 },
    { -61, 0, 1, 1, 31 },
    { -68, 0, 1, 1, 31 },
    { -55, 0, 1, 1, 28 },
    { -83, 0, 1, 1, 31 },
    { -59, 0, 1, 1, 31 },
    { -64, 0, 1, 1, 28 },
    { -88, 71, 1, 1, 31 },
    { -64, 0, 1, 1, 32 },
    { -68, 0, 1, 1, 31 },
    { -61, 0, 1, 1, 31 },
    { -61, 0, 1, 1, 31 },
    { -60, 0, 1, 1, 31 },
    { -61, 0, 1, 1, 31 },
    { -61, 0, 1, 1, 31 },
    { -88, -1, 1, 1, 31 },
    { -81, 67, 1, 1, 31 },
    { -101, -6, 1, 1, 31 },
    { -73, 0, 1, 1, 31 },
    { -80, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -76, 0, 1, 1, 16 },
    { -50, 0, 1, 1, 16 },
    { -59, 0, 1, 1, 16 },
    { -61, 0, 1, 1, 16 },
    { -52, -2, 1, 1, 16 },
    { -83, 0, 1, 1, 16 },
    { -112, 0, 1, 1, 16 },
    { -52, 0, 1, 1, 16 },
    { -104, 67, 1, 1, 16 },
    { -55, 0, 1, 1, 16 },
    { -61, 0, 1, 1, 16 },
    { -59, 0, 1, 1, 16 },
    { -59, 0, 1, 1, 16 },
    { -76, 0, 1, 1, 16 },
    { -59, 0, 1, 1, 16 },
    { -59, 0, 1, 1, 16 },
    { -88, -1, 1, 1, 15 },
    { -81, 67, 1, 1, 16 },
    { -101, -6, 1, 1, 15 },
    { -73, 0, 1, 1, 15 },
    { -80, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { -76, 0, 1, 1, 17 },
    { -50, 0, 1, 1, 17 },
    { -59, 0, 1, 1, 17 },
    { -61, 0, 1, 1, 17 },
    { -52, -2, 1, 1, 17 },
    { -83, 0, 1, 1, 17 },
    { -112, 0, 1, 1, 17 },
    { -52, 0, 1, 1, 17 },
    { -104, 74, 1, 1, 17 },
    { -55, 0, 1, 1, 17 },
    { -61, 0, 1, 1, 17 },
    { -59, 0, 1, 1, 17 },
    { -59, 0, 1, 1, 17 },
    { -76, 0, 1, 1, 17 },
    { -59, 0, 1, 1, 17 },
    { -59, 0, 1, 1, 17 },
    { -78, 1, 1, 1, 16 },
    { -84, -2, 1, 1, 17 },
    { -121, 0, 1, 1, 16 },
    { -83, 0, 1, 1, 16 },
    { -80, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 17 },
    { 0, 0, 1, 1, 17 },
    { 0, 0, 1, 1, 17 },
    { -62, 0, 1, 1, 32 },
    { -64, 0, 1, 1, 32 },
    { -61, 0, 1, 1, 32 },
    { -68, 0, 1, 1, 32 },
    { -55, 0, 1, 1, 29 },
    { -83, 0, 1, 1, 32 },
    { -59, 0, 1, 1, 32 },
    { -64, 0, 1, 1, 29 },
    { -88, 71, 1, 1, 32 },
    { -64, 0, 1, 1, 32 },
    { -68, 0, 1, 1, 32 },
    { -61, 0, 1, 1, 32 },
    { -61, 0, 1, 1, 32 },
    { -62, 0, 1, 1, 32 },
    { -61, 0, 1, 1, 32 },
    { -61, 0, 1, 1, 32 },
    { -78, 1, 1, 1, 32 },
    { -84, -2, 1, 1, 32 },
    { -103, 0, 1, 1, 32 },
    { -83, 0, 1, 1, 32 },
    { -80, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 33 },
    { -64, 0, 1, 1, 33 },
    { -61, 0, 1, 1, 33 },
    { -68, 0, 1, 1, 33 },
    { -55, 0, 1, 1, 30 },
    { -83, 0, 1, 1, 33 },
    { -59, 0, 1, 1, 33 },
    { -64, 0, 1, 1, 30 },
    { -88, 74, 1, 1, 33 },
    { -64, 0, 1, 1, 33 },
    { -68, 0, 1, 1, 33 },
    { -61, 0, 1, 1, 33 },
    { -61, 0, 1, 1, 33 },
    { -62, 0, 1, 1, 33 },
    { -61, 0, 1, 1, 33 },
    { -61, 0, 1, 1, 33 },
    { -78, 1, 1, 1, 33 },
    { -84, -2, 1, 1, 33 },
    { -121, 1, 1, 1, 33 },
    { -83, 0, 1, 1, 33 },
    { -80, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -83, 0, 2, 1, 1 },
    { -90, 0, 2, 1, 1 },
    { -109, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -84, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -94, 0, 2, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -67, 0, 1, 1, 2 },
    { -35, 0, 2, 1, 2 },
    { -46, 0, 2, 1, 2 },
    { -84, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -50, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -56, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -59, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { -74, 0, 2, 1, 3 },
    { -43, 0, 2, 1, 3 },
    { -33, 0, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -51, 0, 2, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { -54, 0, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 4 },
    { -48, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -69, 0, 2, 1, 4 },
    { -52, 0, 2, 1, 4 },
    { -74, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -33, 0, 2, 1, 4 },
    { -23, 0, 2, 1, 4 },
    { -17, 0, 2, 1, 4 },
    { -69, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -40, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { -44, 0, 2, 1, 4 },
    { -57, 0, 2, 1, 4 },
    { -60, 0, 2, 1, 4 },
    { -63, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 5 },
    { -48, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -69, 0, 2, 1, 5 },
    { -52, 0, 2, 1, 5 },
    { -74, 0, 2, 1, 5 },
    { -42, 0, 2, 1, 5 },
    { -41, 0, 2, 1, 5 },
    { -33, 0, 2, 1, 5 },
    { -27, 0, 2, 1, 5 },
    { -69, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -36, 0, 2, 1, 5 },
    { -34, 0, 2, 1, 5 },
    { -51, 0, 2, 1, 5 },
    { -67, 0, 2, 1, 5 },
    { -61, 0, 2, 1, 5 },
    { -42, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -92, 0, 2, 1, 6 },
    { -76, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -54, 0, 2, 1, 6 },
    { -104, 0, 2, 1, 6 },
    { -81, 0, 2, 1, 6 },
    { -46, 0, 2, 1, 6 },
    { -64, 0, 2, 1, 6 },
    { -56, 0, 2, 1, 6 },
    { -58, 0, 2, 1, 6 },
    { -54, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -92, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -72, 0, 2, 1, 6 },
    { -66, 0, 2, 1, 6 },
    { -77, -6, 2, 1, 6 },
    { -88, 0, 2, 1, 6 },
    { -68, 0, 2, 1, 6 },
    { -84, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -88, 0, 2, 1, 7 },
    { -78, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -54, 0, 2, 1, 7 },
    { -105, 0, 2, 1, 7 },
    { -83, 0, 2, 1, 7 },
    { -65, -8, 2, 1, 7 },
    { -62, 0, 2, 1, 7 },
    { -56, 0, 2, 1, 7 },
    { -58, 0, 2, 1, 7 },
    { -54, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -88, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -72, -4, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -82, 0, 2, 1, 7 },
    { -84, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -88, 0, 2, 1, 8 },
    { -78, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { -54, 0, 2, 1, 8 },
    { -105, 0, 2, 1, 8 },
    { -83, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -62, 0, 2, 1, 8 },
    { -56, 0, 2, 1, 8 },
    { -81, 0, 2, 1, 8 },
    { -54, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { -88, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -84, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 9 },
    { -78, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -54, 0, 2, 1, 9 },
    { -105, 0, 2, 1, 9 },
    { -83, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -62, 0, 2, 1, 9 },
    { -56, 0, 2, 1, 9 },
    { -81, 0, 2, 1, 9 },
    { -54, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -88, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -84, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 10 },
    { -78, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -54, 0, 2, 1, 10 },
    { -105, 0, 2, 1, 10 },
    { -83, 0, 2, 1, 10 },
    { -94, 0, 2, 1, 10 },
    { -62, 0, 2, 1, 10 },
    { -56, 0, 2, 1, 10 },
    { -81, 0, 2, 1, 10 },
    { -54, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -88, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -77, 0, 2, 1, 10 },
    { -72, 0, 2, 1, 10 },
    { -76, 0, 2, 1, 10 },
    { -88, 0, 2, 1, 10 },
    { -90, 0, 2, 1, 10 },
    { -80, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -86, 0, 1, 1, 1 },
    { -104, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -97, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -91, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -93, 0, 1, 1, 2 },
    { -89, 0, 1, 1, 2 },
    { -83, 0, 1, 1, 2 },
    { -94, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -97, 0, 1, 1, 2 },
    { -76, 0, 1, 1, 2 },
    { -91, 0, 1, 1, 2 },
    { -89, 0, 1, 1, 2 },
    { -93, 0, 1, 1, 2 },
    { -93, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -93, 0, 1, 1, 2 },
    { -93, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 3 },
    { -79, 0, 1, 1, 3 },
    { -114, 1, 1, 1, 3 },
    { -89, 0, 1, 1, 3 },
    { -76, 0, 1, 1, 3 },
    { -99, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -97, 0, 1, 1, 3 },
    { -79, 0, 1, 1, 3 },
    { -78, 0, 1, 1, 3 },
    { -89, 0, 1, 1, 3 },
    { -114, 1, 1, 1, 3 },
    { -114, 1, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -114, 1, 1, 1, 3 },
    { -114, 1, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 4 },
    { -96, 2, 1, 1, 4 },
    { -47, 1, 1, 1, 4 },
    { -77, 0, 1, 1, 4 },
    { -74, 0, 1, 1, 4 },
    { -101, 13, 1, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -138, 0, 1, 1, 4 },
    { -53, 0, 1, 1, 4 },
    { -84, 0, 1, 1, 4 },
    { -77, 0, 1, 1, 4 },
    { -47, 1, 1, 1, 4 },
    { -47, 1, 1, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -47, 1, 1, 1, 4 },
    { -47, 1, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 5 },
    { -79, -10, 1, 1, 5 },
    { -44, 1, 1, 1, 5 },
    { -74, 0, 1, 1, 5 },
    { -66, -6, 1, 1, 5 },
    { -70, 15, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -84, 0, 1, 1, 5 },
    { -52, 20, 1, 1, 5 },
    { -73, 0, 1, 1, 5 },
    { -74, 0, 1, 1, 5 },
    { -44, -1, 1, 1, 5 },
    { -44, -1, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -44, 1, 1, 1, 5 },
    { -44, 1, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, -6, 2, 1, 1 },
    { -40, 3, 2, 1, 1 },
    { -53, 16, 1, 1, 1 },
    { -29, 20, 2, 1, 1 },
    { -46, 11, 2, 1, 1 },
    { 2, 0, 2, 1, 1 },
    { -58, -9, 2, 1, 1 },
    { -64, 16, 2, 1, 1 },
    { -40, 16, 2, 1, 1 },
    { -48, 22, 1, 1, 1 },
    { -29, 20, 2, 1, 1 },
    { -53, 16, 1, 1, 1 },
    { -53, 16, 1, 1, 1 },
    { -50, -6, 2, 1, 1 },
    { -53, 16, 1, 1, 1 },
    { -53, 16, 1, 1, 1 },
    { -36, 18, 1, 1, 1 },
    { -60, 7, 2, 1, 1 },
    { -70, 1, 2, 1, 1 },
    { -14, 5, 2, 1, 1 },
    { -52, 8, 2, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -52, -8, 2, 1, 2 },
    { -36, -6, 2, 1, 2 },
    { -48, 12, 1, 1, 2 },
    { -24, 12, 2, 1, 2 },
    { -33, -1, 2, 1, 2 },
    { 3, 0, 2, 1, 2 },
    { -52, -11, 2, 1, 2 },
    { -44, 8, 2, 1, 2 },
    { -29, 20, 2, 1, 2 },
    { -47, 16, 1, 1, 2 },
    { -24, 12, 2, 1, 2 },
    { -48, 12, 1, 1, 2 },
    { -48, 12, 1, 1, 2 },
    { -52, -8, 2, 1, 2 },
    { -48, 12, 1, 1, 2 },
    { -48, 12, 1, 1, 2 },
    { -33, 11, 1, 1, 2 },
    { -52, 4, 2, 1, 2 },
    { -66, -8, 2, 1, 2 },
    { -11, -1, 2, 1, 2 },
    { -50, 2, 2, 1, 2 },
    { -50, 2, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -34, -13, 2, 1, 3 },
    { -36, -10, 2, 1, 3 },
    { -33, 41, 1, 1, 3 },
    { -22, 8, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -18, 0, 2, 1, 3 },
    { -52, -9, 2, 1, 3 },
    { -44, 8, 2, 1, 3 },
    { -28, 16, 2, 1, 3 },
    { -48, 4, 2, 1, 3 },
    { -22, 8, 2, 1, 3 },
    { -33, 41, 1, 1, 3 },
    { -33, 41, 1, 1, 3 },
    { -34, -13, 2, 1, 3 },
    { -33, 41, 1, 1, 3 },
    { -33, 41, 1, 1, 3 },
    { -47, 18, 1, 1, 3 },
    { -51, -2, 2, 1, 3 },
    { -63, -9, 2, 1, 3 },
    { -18, 0, 2, 1, 3 },
    { -50, 2, 2, 1, 3 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -34, -13, 2, 1, 4 },
    { -37, -11, 2, 1, 4 },
    { -34, 40, 1, 1, 4 },
    { -23, 7, 2, 1, 4 },
    { -33, -1, 2, 1, 4 },
    { -19, -1, 2, 1, 4 },
    { -57, -6, 2, 1, 4 },
    { -45, 7, 2, 1, 4 },
    { -29, 15, 2, 1, 4 },
    { -49, 3, 2, 1, 4 },
    { -23, 7, 2, 1, 4 },
    { -34, 40, 1, 1, 4 },
    { -34, 40, 1, 1, 4 },
    { -34, -13, 2, 1, 4 },
    { -34, 40, 1, 1, 4 },
    { -34, 40, 1, 1, 4 },
    { -46, 19, 1, 1, 4 },
    { -50, -1, 2, 1, 4 },
    { -62, -8, 2, 1, 4 },
    { -19, -1, 2, 1, 4 },
    { -50, 2, 2, 1, 4 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -34, -13, 2, 1, 5 },
    { -32, 2, 2, 1, 5 },
    { -41, 21, 1, 1, 5 },
    { -15, -1, 1, 1, 5 },
    { -56, -16, 2, 1, 5 },
    { -42, -9, 2, 1, 5 },
    { -41, -22, 2, 1, 5 },
    { -72, 40, 2, 1, 5 },
    { -34, 21, 2, 1, 5 },
    { -46, 7, 2, 1, 5 },
    { -15, -1, 1, 1, 5 },
    { -41, 21, 1, 1, 5 },
    { -41, 21, 1, 1, 5 },
    { -34, -13, 2, 1, 5 },
    { -41, 21, 1, 1, 5 },
    { -41, 21, 1, 1, 5 },
    { -45, 33, 1, 1, 5 },
    { -47, 2, 2, 1, 5 },
    { -67, 3, 2, 1, 5 },
    { -28, -15, 2, 1, 5 },
    { -50, 2, 2, 1, 5 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -34, -13, 2, 1, 6 },
    { -24, 2, 2, 1, 6 },
    { -32, 8, 1, 1, 6 },
    { -6, -4, 2, 1, 6 },
    { -35, -36, 2, 1, 6 },
    { -37, -15, 2, 1, 6 },
    { -37, -38, 2, 1, 6 },
    { -48, 16, 2, 1, 6 },
    { -31, 27, 2, 1, 6 },
    { -37, -4, 2, 1, 6 },
    { -6, -4, 2, 1, 6 },
    { -32, 8, 1, 1, 6 },
    { -32, 8, 1, 1, 6 },
    { -34, -13, 2, 1, 6 },
    { -32, 8, 1, 1, 6 },
    { -32, 8, 1, 1, 6 },
    { -41, 21, 1, 1, 6 },
    { -43, 26, 2, 1, 6 },
    { -26, 10, 2, 1, 6 },
    { -23, -23, 2, 1, 6 },
    { -42, -32, 2, 1, 6 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -43, -18, 2, 1, 7 },
    { -16, 0, 2, 1, 7 },
    { -23, -6, 2, 1, 7 },
    { 3, 8, 2, 1, 7 },
    { -25, -26, 2, 1, 7 },
    { -19, -12, 2, 1, 7 },
    { 6, -31, 2, 1, 7 },
    { -40, 0, 2, 1, 7 },
    { -17, 15, 2, 1, 7 },
    { -17, -12, 2, 1, 7 },
    { 3, 8, 2, 1, 7 },
    { -23, -6, 2, 1, 7 },
    { -23, -6, 2, 1, 7 },
    { -43, -18, 2, 1, 7 },
    { -23, -6, 2, 1, 7 },
    { -23, -6, 2, 1, 7 },
    { -19, 7, 2, 1, 7 },
    { -24, 8, 2, 1, 7 },
    { -15, 1, 2, 1, 7 },
    { -20, -27, 2, 1, 7 },
    { -22, -22, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, -6, 2, 1, 8 },
    { -8, 0, 1, 1, 8 },
    { -16, 0, 2, 1, 8 },
    { 8, 0, 1, 1, 8 },
    { 8, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 16, 0, 2, 1, 8 },
    { -8, 0, 1, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -8, 0, 2, 1, 8 },
    { 8, 0, 1, 1, 8 },
    { -16, 0, 2, 1, 8 },
    { -16, 0, 2, 1, 8 },
    { -18, -6, 2, 1, 8 },
    { -16, 0, 2, 1, 8 },
    { -16, 0, 2, 1, 8 },
    { -15, 0, 2, 1, 8 },
    { -5, 0, 2, 1, 8 },
    { -7, 0, 2, 1, 8 },
    { -6, 0, 1, 1, 8 },
    { -6, 0, 1, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -14, 0, 2, 1, 9 },
    { -8, 0, 1, 1, 9 },
    { -16, 0, 2, 1, 9 },
    { 8, 0, 1, 1, 9 },
    { 8, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -28, -8, 2, 1, 9 },
    { -8, 0, 1, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -8, 0, 2, 1, 9 },
    { 8, 0, 1, 1, 9 },
    { -16, 0, 2, 1, 9 },
    { -16, 0, 2, 1, 9 },
    { -14, 0, 2, 1, 9 },
    { -16, 0, 2, 1, 9 },
    { -16, 0, 2, 1, 9 },
    { -15, 0, 2, 1, 9 },
    { -5, 0, 2, 1, 9 },
    { -7, 0, 2, 1, 9 },
    { -6, 0, 1, 1, 9 },
    { -6, 0, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 49, 16, 1, 0, 13 },
    { 35, 52, 1, 0, 13 },
    { 71, 32, 1, 0, 13 },
    { 71, 56, 1, 0, 13 },
    { 71, 24, 1, 0, 10 },
    { 71, 32, 1, 0, 13 },
    { 71, 1, 2, 0, 13 },
    { 71, 24, 1, 0, 13 },
    { 71, 56, 1, 0, 13 },
    { 71, 56, 1, 0, 13 },
    { 71, 56, 1, 0, 13 },
    { 71, 32, 1, 0, 13 },
    { 71, 32, 1, 0, 13 },
    { 49, 16, 1, 0, 13 },
    { 71, 32, 1, 0, 13 },
    { 71, 32, 1, 0, 13 },
    { 94, 30, 1, 0, 12 },
    { 110, 31, 1, 0, 12 },
    { 107, 53, 1, 0, 12 },
    { 82, 0, 1, 0, 12 },
    { 71, 32, 2, 0, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 49, 20, 1, 1, 23 },
    { 35, 52, 1, 1, 23 },
    { 39, 34, 1, 1, 23 },
    { 13, 56, 1, 1, 23 },
    { 39, 84, 1, 1, 19 },
    { 53, 32, 1, 1, 23 },
    { 74, -12, 1, 1, 23 },
    { 24, 18, 1, 1, 19 },
    { 35, 86, 1, 1, 23 },
    { 44, 44, 1, 1, 23 },
    { 13, 56, 1, 1, 23 },
    { 39, 22, 1, 1, 23 },
    { 39, 22, 1, 1, 23 },
    { 49, 20, 1, 1, 23 },
    { 39, 34, 1, 1, 23 },
    { 39, 34, 1, 1, 23 },
    { 42, 60, 1, 1, 22 },
    { 50, 87, 1, 1, 22 },
    { 56, 70, 1, 1, 22 },
    { 35, 27, 1, 1, 22 },
    { 42, 90, 1, 1, 22 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 80, 0, 1, 1, 24 },
    { 86, 13, 1, 1, 24 },
    { 82, 6, 1, 1, 24 },
    { 82, -1, 1, 1, 24 },
    { 72, 0, 1, 1, 20 },
    { 86, -20, 1, 1, 24 },
    { 60, 0, 1, 1, 24 },
    { 70, 0, 1, 1, 20 },
    { 115, 66, 1, 1, 24 },
    { 56, 0, 1, 1, 24 },
    { 82, -1, 1, 1, 24 },
    { 82, 6, 1, 1, 24 },
    { 82, 6, 1, 1, 24 },
    { 80, 0, 1, 1, 24 },
    { 82, 6, 1, 1, 24 },
    { 82, 6, 1, 1, 24 },
    { 80, 6, 1, 1, 23 },
    { 81, 28, 1, 1, 23 },
    { 71, 0, 1, 1, 23 },
    { 87, 8, 1, 1, 23 },
    { 96, 4, 1, 1, 23 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 96, 0, 1, 0, 25 },
    { 86, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 72, 0, 1, 0, 21 },
    { 86, -20, 2, 0, 25 },
    { 60, 0, 1, 0, 25 },
    { 70, 0, 1, 0, 21 },
    { 89, 0, 1, 0, 25 },
    { 56, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 96, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 82, 0, 1, 0, 25 },
    { 76, 0, 1, 0, 24 },
    { 75, 0, 1, 0, 24 },
    { 67, 0, 1, 0, 24 },
    { 87, 0, 1, 0, 24 },
    { 80, 0, 1, 0, 24 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1 },
    { -24, -50, 2, 1, 1 },
    { -48, -34, 2, 1, 1 },
    { -31, -28, 2, 1, 1 },
    { -31, -22, 2, 1, 1 },
    { -25, -35, 2, 1, 1 },
    { -41, -27, 2, 1, 1 },
    { -23, -47, 2, 1, 1 },
    { -35, -20, 2, 1, 1 },
    { -37, -23, 2, 1, 1 },
    { -19, -19, 2, 1, 1 },
    { -31, -22, 2, 1, 1 },
    { -31, -28, 2, 1, 1 },
    { -31, -28, 2, 1, 1 },
    { -24, -50, 2, 1, 1 },
    { -31, -28, 2, 1, 1 },
    { -31, -28, 2, 1, 1 },
    { -31, -31, 2, 1, 1 },
    { -40, -23, 2, 1, 1 },
    { -35, -59, 2, 1, 1 },
    { -47, -29, 2, 1, 1 },
    { -25, -44, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -9, -57, 2, 1, 4 },
    { 1, -47, 2, 1, 4 },
    { 6, -39, 2, 1, 4 },
    { 17, -29, 2, 1, 4 },
    { 24, -43, 2, 1, 4 },
    { -1, -41, 2, 1, 4 },
    { 37, -49, 2, 1, 4 },
    { 4, -25, 2, 1, 4 },
    { -2, -31, 2, 1, 4 },
    { 9, -28, 2, 1, 4 },
    { 17, -29, 2, 1, 4 },
    { 6, -39, 2, 1, 4 },
    { 6, -39, 2, 1, 4 },
    { -9, -57, 2, 1, 4 },
    { 6, -39, 2, 1, 4 },
    { 6, -39, 2, 1, 4 },
    { 5, -36, 2, 1, 4 },
    { 1, -32, 2, 1, 4 },
    { -3, -65, 2, 1, 4 },
    { 0, -35, 2, 1, 4 },
    { 4, -44, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 55, -36, 2, 1, 7 },
    { 75, -30, 2, 1, 7 },
    { 70, -21, 2, 1, 7 },
    { 75, -11, 2, 1, 7 },
    { 81, -21, 2, 1, 7 },
    { 69, -22, 2, 1, 7 },
    { 98, -26, 2, 1, 7 },
    { 75, -4, 2, 1, 7 },
    { 62, -20, 2, 1, 7 },
    { 79, -12, 2, 1, 7 },
    { 75, -11, 2, 1, 7 },
    { 70, -21, 2, 1, 7 },
    { 70, -21, 2, 1, 7 },
    { 55, -36, 2, 1, 7 },
    { 70, -21, 2, 1, 7 },
    { 70, -21, 2, 1, 7 },
    { 67, -20, 2, 1, 7 },
    { 51, -16, 2, 1, 7 },
    { 59, -35, 2, 1, 7 },
    { 80, -21, 2, 1, 7 },
    { 74, -21, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 60, -27, 2, 1, 10 },
    { 81, -26, 2, 1, 10 },
    { 71, -19, 2, 1, 10 },
    { 64, -9, 2, 1, 10 },
    { 79, -15, 2, 1, 10 },
    { 57, -18, 2, 1, 10 },
    { 106, -6, 2, 1, 10 },
    { 69, 0, 2, 1, 10 },
    { 81, -17, 2, 1, 10 },
    { 62, -4, 2, 1, 10 },
    { 64, -9, 2, 1, 10 },
    { 71, -19, 2, 1, 10 },
    { 71, -19, 2, 1, 10 },
    { 60, -27, 2, 1, 10 },
    { 71, -19, 2, 1, 10 },
    { 71, -19, 2, 1, 10 },
    { 76, -17, 2, 1, 10 },
    { 55, -13, 2, 1, 10 },
    { 59, -19, 2, 1, 10 },
    { 74, -9, 2, 1, 10 },
    { 63, -15, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 65, -12, 2, 1, 13 },
    { 94, -14, 2, 1, 13 },
    { 78, -10, 2, 1, 13 },
    { 61, 1, 2, 1, 13 },
    { 82, -6, 2, 1, 13 },
    { 47, -4, 2, 1, 13 },
    { 91, -1, 2, 1, 13 },
    { 61, 3, 2, 1, 13 },
    { 81, -5, 2, 1, 13 },
    { 68, 2, 2, 1, 13 },
    { 61, 1, 2, 1, 13 },
    { 78, -10, 2, 1, 13 },
    { 78, -10, 2, 1, 13 },
    { 65, -12, 2, 1, 13 },
    { 78, -10, 2, 1, 13 },
    { 78, -10, 2, 1, 13 },
    { 68, -7, 2, 1, 13 },
    { 68, 4, 2, 1, 13 },
    { 50, -13, 2, 1, 13 },
    { 68, -6, 2, 1, 13 },
    { 58, -8, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 15, -19, 1, 1, 16 },
    { 73, -7, 1, 1, 16 },
    { 59, -5, 1, 1, 16 },
    { 30, 4, 1, 1, 16 },
    { 51, 4, 1, 1, 16 },
    { 34, 8, 1, 1, 16 },
    { 43, 0, 1, 1, 16 },
    { 39, 3, 1, 1, 16 },
    { 29, 0, 1, 1, 16 },
    { 49, 11, 1, 1, 16 },
    { 30, 4, 1, 1, 16 },
    { 59, -5, 1, 1, 16 },
    { 59, -5, 1, 1, 16 },
    { 15, -19, 1, 1, 16 },
    { 59, -5, 1, 1, 16 },
    { 59, -5, 1, 1, 16 },
    { 32, -1, 1, 1, 16 },
    { 42, 11, 1, 1, 16 },
    { 40, -4, 1, 1, 16 },
    { 46, 2, 1, 1, 16 },
    { 39, 2, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { -11, -10, 1, 1, 19 },
    { 49, 1, 1, 1, 19 },
    { 38, 1, 1, 1, 19 },
    { 20, 10, 1, 1, 19 },
    { 26, 10, 1, 1, 19 },
    { 5, 9, 1, 1, 19 },
    { -2, -4, 1, 1, 19 },
    { 4, 5, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 13, 13, 1, 1, 19 },
    { 20, 10, 1, 1, 19 },
    { 38, 1, 1, 1, 19 },
    { 38, 1, 1, 1, 19 },
    { -11, -10, 1, 1, 19 },
    { 38, 1, 1, 1, 19 },
    { 38, 1, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 4, 1, 1, 19 },
    { 4, -19, 1, 1, 19 },
    { -6, -7, 1, 1, 19 },
    { 0, -2, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 17, -15, 1, 1, 22 },
    { 44, 7, 1, 1, 22 },
    { 39, 3, 1, 1, 22 },
    { -13, 6, 1, 1, 22 },
    { -4, 5, 1, 1, 22 },
    { 5, 1, 1, 1, 22 },
    { -1, -5, 1, 1, 22 },
    { 2, 2, 1, 1, 22 },
    { 5, 0, 1, 1, 22 },
    { -8, 7, 1, 1, 22 },
    { -13, 6, 1, 1, 22 },
    { 39, 3, 1, 1, 22 },
    { 39, 3, 1, 1, 22 },
    { 17, -15, 1, 1, 22 },
    { 39, 3, 1, 1, 22 },
    { 39, 3, 1, 1, 22 },
    { -4, 1, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 7, -16, 1, 1, 22 },
    { 0, -13, 1, 1, 22 },
    { 7, -6, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 9, 16, 1, 1, 25 },
    { 11, -4, 1, 1, 25 },
    { -34, 0, 1, 1, 25 },
    { -4, 4, 1, 1, 25 },
    { -13, -10, 1, 1, 25 },
    { -24, -22, 1, 1, 25 },
    { 11, -11, 1, 1, 25 },
    { -12, -8, 1, 1, 25 },
    { -21, -4, 1, 1, 25 },
    { -13, -16, 1, 1, 25 },
    { -4, 4, 1, 1, 25 },
    { -34, 0, 1, 1, 25 },
    { -34, 0, 1, 1, 25 },
    { 9, 16, 1, 1, 25 },
    { -34, 0, 1, 1, 25 },
    { -34, 0, 1, 1, 25 },
    { -44, 51, 1, 1, 25 },
    { 8, -2, 1, 1, 25 },
    { 12, -14, 1, 1, 25 },
    { -18, -10, 1, 1, 25 },
    { -5, -8, 1, 1, 25 },
    { 0, 0, 1, 1, 25 },
    { 0, 0, 1, 1, 25 },
    { 0, 0, 1, 1, 25 },
    { 6, 6, 1, 1, 28 },
    { -7, 10, 1, 1, 28 },
    { -16, 120, 1, 1, 28 },
    { -18, 32, 1, 1, 28 },
    { 12, 76, 1, 1, 28 },
    { -14, -8, 1, 1, 28 },
    { -6, -14, 1, 1, 28 },
    { -9, -4, 1, 1, 28 },
    { -9, 97, 1, 1, 28 },
    { -32, 131, 1, 1, 28 },
    { -18, 32, 1, 1, 28 },
    { -16, 120, 1, 1, 28 },
    { -16, 120, 1, 1, 28 },
    { 6, 6, 1, 1, 28 },
    { -16, 120, 1, 1, 28 },
    { -16, 120, 1, 1, 28 },
    { -44, 114, 1, 1, 28 },
    { -1, -14, 1, 1, 28 },
    { -8, 80, 1, 1, 28 },
    { -18, 21, 1, 1, 28 },
    { -34, 33, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { -24, -11, 1, 1, 31 },
    { 23, 14, 1, 1, 31 },
    { -10, 86, 1, 1, 31 },
    { -4, 123, 1, 1, 31 },
    { -17, 124, 1, 1, 31 },
    { -10, 116, 1, 1, 31 },
    { 32, 10, 1, 1, 31 },
    { -65, 24, 1, 1, 31 },
    { -6, 70, 1, 1, 31 },
    { -27, 99, 1, 1, 31 },
    { -4, 123, 1, 1, 31 },
    { -10, 86, 1, 1, 31 },
    { -10, 86, 1, 1, 31 },
    { -24, -11, 1, 1, 31 },
    { -10, 86, 1, 1, 31 },
    { -10, 86, 1, 1, 31 },
    { -35, 112, 1, 1, 31 },
    { -18, 21, 1, 1, 31 },
    { -34, -4, 1, 1, 31 },
    { -44, 12, 1, 1, 31 },
    { -43, 114, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { -52, 0, 1, 1, 34 },
    { -80, -2, 1, 1, 34 },
    { -80, 0, 1, 1, 34 },
    { -89, 0, 1, 1, 34 },
    { -67, 0, 1, 1, 34 },
    { -51, 0, 1, 1, 34 },
    { 8, 0, 1, 1, 34 },
    { -72, 0, 1, 1, 34 },
    { -31, 71, 1, 1, 34 },
    { -64, 0, 1, 1, 34 },
    { -89, 0, 1, 1, 34 },
    { -80, 0, 1, 1, 34 },
    { -80, 0, 1, 1, 34 },
    { -52, 0, 1, 1, 34 },
    { -80, 0, 1, 1, 34 },
    { -80, 0, 1, 1, 34 },
    { -34, 0, 1, 1, 34 },
    { -28, 0, 1, 1, 34 },
    { -64, 0, 1, 1, 34 },
    { -84, 0, 1, 1, 34 },
    { -64, 0, 1, 1, 34 },
    { 0, 0, 1, 1, 34 },
    { 0, 0, 1, 1, 34 },
    { 0, 0, 1, 1, 34 },
    { -65, 0, 1, 1, 35 },
    { -95, -8, 1, 1, 35 },
    { -80, 0, 1, 1, 35 },
    { -89, 0, 1, 1, 35 },
    { -87, 0, 1, 1, 35 },
    { -60, 0, 1, 1, 35 },
    { 13, 0, 1, 1, 35 },
    { -76, 0, 1, 1, 35 },
    { -51, 69, 1, 1, 35 },
    { -64, 0, 1, 1, 35 },
    { -89, 0, 1, 1, 35 },
    { -80, 0, 1, 1, 35 },
    { -80, 0, 1, 1, 35 },
    { -65, 0, 1, 1, 35 },
    { -80, 0, 1, 1, 35 },
    { -80, 0, 1, 1, 35 },
    { -62, 0, 1, 1, 35 },
    { -36, 0, 1, 1, 35 },
    { -64, 0, 1, 1, 35 },
    { -84, 0, 1, 1, 35 },
    { -64, 0, 1, 1, 35 },
    { 0, 0, 1, 1, 35 },
    { 0, 0, 1, 1, 35 },
    { 0, 0, 1, 1, 35 },
    { -66, 0, 1, 0, 36 },
    { -98, 0, 1, 0, 36 },
    { -80, 0, 1, 0, 36 },
    { -89, 0, 1, 0, 36 },
    { -87, 0, 1, 0, 36 },
    { -64, 0, 1, 0, 36 },
    { 13, 0, 1, 1, 36 },
    { -76, 0, 1, 0, 36 },
    { -76, 0, 1, 0, 36 },
    { -64, 0, 1, 0, 36 },
    { -89, 0, 1, 0, 36 },
    { -80, 0, 1, 0, 36 },
    { -80, 0, 1, 0, 36 },
    { -66, 0, 1, 0, 36 },
    { -80, 0, 1, 0, 36 },
    { -80, 0, 1, 0, 36 },
    { -62, 0, 1, 0, 36 },
    { -36, 0, 1, 0, 36 },
    { -64, 0, 1, 0, 36 },
    { -84, 0, 1, 0, 36 },
    { -64, 0, 1, 0, 36 },
    { 0, 0, 1, 0, 36 },
    { 0, 0, 1, 0, 36 },
    { 0, 0, 1, 0, 36 },
};

/* extra scripts: 51 entries */
const u16* const alex_exca[52] = {
    alex_exca_000,  /* 0 follow-up of AIR NORMAL */
    alex_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    alex_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    alex_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    alex_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    alex_exca_005,  /* 5 follow-up of TATAKI S, TATAKI M +18 */
    alex_exca_006,  /* 6 follow-up of NOKEZORI, UPPER +20 */
    alex_exca_007,  /* 7 follow-up of KUNOJI, DUDDLEY D S */
    alex_exca_008,  /* 8 follow-up of TATAKI V. S, TATAKI V. M +9 */
    alex_exca_009,  /* 9 follow-up of KIRIMOMI, SPLASH.M +1 */
    alex_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    alex_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    alex_exca_012,  /* 12 follow-up of APPEAR JUNBI 4 */
    alex_exca_013,  /* 13 no name */
    alex_exca_014,  /* 14 follow-up of HUMI ASIB */
    alex_exca_015,  /* 15 follow-up of ZANNEN 2 */
    alex_exca_016,  /* 16 follow-up of ZANNEN 2 */
    alex_exca_017,  /* 17 no name */
    alex_exca_018,  /* 18 no name */
    alex_exca_017,  /* 19 no name */
    alex_exca_017,  /* 20 no name */
    alex_exca_017,  /* 21 no name */
    alex_exca_022,  /* 22 no name */
    alex_exca_023,  /* 23 no name */
    alex_exca_024,  /* 24 follow-up of APPEAR JUNBI 6 */
    alex_exca_024,  /* 25 follow-up of APPEAR JUNBI 6 */
    alex_exca_017,  /* 26 no name */
    alex_exca_027,  /* 27 follow-up of APPEAR JUNBI 7 */
    alex_exca_028,  /* 28 follow-up of APPEAR JUNBI 7 */
    alex_exca_029,  /* 29 follow-up of APPEAR 1 */
    alex_exca_030,  /* 30 follow-up of APPEAR 1 */
    alex_exca_031,  /* 31 follow-up of APPEAR 3 */
    alex_exca_032,  /* 32 follow-up of APPEAR 3 */
    alex_exca_033,  /* 33 follow-up of ASIB TUNNOMERI */
    alex_exca_034,  /* 34 follow-up of APPEAR 4 */
    alex_exca_035,  /* 35 follow-up of APPEAR 4 */
    alex_exca_036,  /* 36 follow-up of GILL IMPACT C */
    alex_exca_037,  /* 37 follow-up of APPEAR 8 */
    alex_exca_038,  /* 38 follow-up of APPEAR 8 */
    alex_exca_039,  /* 39 follow-up of GILL IMPACT C */
    alex_exca_040,  /* 40 follow-up of APPEAR 6 */
    alex_exca_041,  /* 41 follow-up of APPEAR 6 */
    alex_exca_042,  /* 42 follow-up of SP APPEAR 2 */
    alex_exca_043,  /* 43 follow-up of SP APPEAR 2 */
    alex_exca_044,  /* 44 follow-up of SP APPEAR 3 */
    alex_exca_045,  /* 45 follow-up of SP APPEAR 3 */
    alex_exca_044,  /* 46 follow-up of SP APPEAR 4 */
    alex_exca_045,  /* 47 follow-up of SP APPEAR 4 */
    alex_exca_048,  /* 48 follow-up of SP APPEAR 5 */
    alex_exca_049,  /* 49 follow-up of SP APPEAR 5 */
    alex_exca_050,  /* 50 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 alex_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_exca_000[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F0, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08F1, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08F2, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x08F3, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F4, 0, 7, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08F4, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3 */
const u16 alex_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_001[92] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 alex_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_003[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x08D5, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 alex_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_004[100] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, TATAKI M +18 */
const u16 alex_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_005[132] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CB, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x06CC, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, UPPER +20 */
const u16 alex_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_006[140] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CA, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CB, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x06CC, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, DUDDLEY D S */
const u16 alex_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_007[28] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06DF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06E0, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 6, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI V. S, TATAKI V. M +9 */
const u16 alex_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_008[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, SPLASH.M +1 */
const u16 alex_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_009[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3 */
const u16 alex_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_010[60] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4 */
const u16 alex_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_012[60] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 alex_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_013[52] = {
    L4(2, 2, 274, 0, 0, 0, 0, 0x0630, 0, 4, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of HUMI ASIB */
const u16 alex_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_014[132] = {
    CMD(CM_PA_X, 0, 16384, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CC, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of ZANNEN 2 */
const u16 alex_exca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_015[84] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x0630, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of ZANNEN 2 */
const u16 alex_exca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_016[52] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x0630, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name, 19 no name, 20 no name, 21 no name ... */
const u16 alex_exca_017_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_exca_017[12] = {
    L4(250, 0, 0, 0, 1, 0, 0, 0x0601, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 alex_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_exca_018[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x06DF, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x06DE, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x06DD, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x06DC, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x06DC, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 alex_exca_022_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_022[132] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x06CB, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 1, 0, 0, 0x06CC, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 no name */
const u16 alex_exca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_exca_023[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CD, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 6, 25 follow-up of APPEAR JUNBI 6 */
const u16 alex_exca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_024[88] = {
    L6(2, 0, 274, 0, 0, 0, 0, 0x0694, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0695, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR JUNBI 7 */
const u16 alex_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_027[60] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x07D0, 0, 47, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x07D1, 0, 47, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 32, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR JUNBI 7 */
const u16 alex_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_028[84] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x07D0, 0, 47, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x07D1, 0, 47, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x07D3, 0, 47, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0630, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR 1 */
const u16 alex_exca_029_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_029[64] = {
    L6(3, 0, 274, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1 */
const u16 alex_exca_030_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_030[76] = {
    L6(1, 64, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR 3 */
const u16 alex_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_031[60] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 3 */
const u16 alex_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_032[52] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 1, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of ASIB TUNNOMERI */
const u16 alex_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_033[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CA, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x06CB, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x06CE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06CF, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D0, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D1, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D5, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x06D6, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D8, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x06D9, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 4 */
const u16 alex_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_034[52] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of APPEAR 4 */
const u16 alex_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_035[60] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0904, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0905, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0906, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0907, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 1, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of GILL IMPACT C */
const u16 alex_exca_036_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_036[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x08D5, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of APPEAR 8 */
const u16 alex_exca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_037[92] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x0631, 0, 154, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of APPEAR 8 */
const u16 alex_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_038[52] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x0631, 0, 155, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of GILL IMPACT C */
const u16 alex_exca_039_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 alex_exca_039[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D3, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x08D4, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x08D5, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D2, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x06D3, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x06D4, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of APPEAR 6 */
const u16 alex_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_040[92] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0636, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of APPEAR 6 */
const u16 alex_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_041[52] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of SP APPEAR 2 */
const u16 alex_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_042[84] = {
    L4(2, 3, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of SP APPEAR 2 */
const u16 alex_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_043[52] = {
    L4(2, 3, 274, 0, 0, 0, 0, 0x0631, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0633, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0634, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of SP APPEAR 3, 46 follow-up of SP APPEAR 4 */
const u16 alex_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_044[92] = {
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x0693, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x0694, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x0695, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP APPEAR 3, 47 follow-up of SP APPEAR 4 */
const u16 alex_exca_045_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_045[52] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of SP APPEAR 5 */
const u16 alex_exca_048_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_exca_048[92] = {
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0693, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0694, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0695, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0697, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0698, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SP APPEAR 5 */
const u16 alex_exca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 alex_exca_049[52] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0635, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 alex_exca_050_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 alex_exca_050[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F0, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08F1, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08F2, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x08F3, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08F4, 0, 240, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08F4, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0656, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0657, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 241, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x065C, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 71 entries */
const u16* const alex_saca[72] = {
    alex_saca_000,  /* 0 UP P GUARD P S */
    alex_saca_001,  /* 1 UP P GUARD P M */
    alex_saca_002,  /* 2 UP P GUARD P L */
    alex_saca_002,  /* 3 UP P GUARD K S */
    alex_saca_002,  /* 4 UP P GUARD K M */
    alex_saca_002,  /* 5 UP P GUARD K L */
    alex_saca_000,  /* 6 D P GUARD P S */
    alex_saca_001,  /* 7 D P GUARD P M */
    alex_saca_002,  /* 8 D P GUARD P L */
    alex_saca_002,  /* 9 D P GUARD K S */
    alex_saca_002,  /* 10 D P GUARD K M */
    alex_saca_002,  /* 11 D P GUARD K L */
    alex_saca_002,  /* 12 FUSHIN P S */
    alex_saca_002,  /* 13 FUSHIN P M */
    alex_saca_002,  /* 14 FUSHIN P L */
    alex_saca_002,  /* 15 FUSHIN K S */
    alex_saca_002,  /* 16 FUSHIN K M */
    alex_saca_002,  /* 17 FUSHIN K L */
    alex_saca_002,  /* 18 OKIAGARI P S */
    alex_saca_002,  /* 19 OKIAGARI P M */
    alex_saca_002,  /* 20 OKIAGARI P L */
    alex_saca_002,  /* 21 OKIAGARI K S */
    alex_saca_002,  /* 22 OKIAGARI K M */
    alex_saca_002,  /* 23 OKIAGARI K L */
    alex_saca_024,  /* 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    alex_saca_025,  /* 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    alex_saca_026,  /* 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    alex_saca_027,  /* 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    alex_saca_028,  /* 28 ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    alex_saca_029,  /* 29 ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    alex_saca_030,  /* 30 ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    alex_saca_031,  /* 31 ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    alex_saca_032,  /* 32 ATTACK 3 S: 6(123)4+P light (plain script) */
    alex_saca_033,  /* 33 ATTACK 3 M: 6(123)4+P medium (plain script) */
    alex_saca_034,  /* 34 ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    alex_saca_034,  /* 35 ATTACK 3 SP: 6(123)4+P heavy/EX (plain script) */
    alex_saca_036,  /* 36 ATTACK 4 S: SA I 360+P (plain script) */
    alex_saca_036,  /* 37 ATTACK 4 M: SA I 360+P (plain script) */
    alex_saca_036,  /* 38 ATTACK 4 L: SA I 360+P (plain script) */
    alex_saca_036,  /* 39 ATTACK 4 SP: SA I 360+P (plain script) */
    alex_saca_040,  /* 40 ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    alex_saca_040,  /* 41 ATTACK 5 M: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    alex_saca_040,  /* 42 ATTACK 5 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    alex_saca_043,  /* 43 ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    alex_saca_044,  /* 44 ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    alex_saca_044,  /* 45 ATTACK 6 M: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    alex_saca_044,  /* 46 ATTACK 6 L: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    alex_saca_044,  /* 47 ATTACK 6 SP: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    alex_saca_048,  /* 48 ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
    alex_saca_049,  /* 49 ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
    alex_saca_050,  /* 50 ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    alex_saca_051,  /* 51 ATTACK 7 SP: EX [2](789)+KK (routine Att_HOMING_JUMP) */
    alex_saca_052,  /* 52 ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU) */
    alex_saca_053,  /* 53 ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU) */
    alex_saca_054,  /* 54 ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) */
    alex_saca_055,  /* 55 ATTACK 8 SP: after [2](789)+K (routine Att_HOMING_JUMP) */
    alex_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    alex_saca_056,  /* 57 ATTACK 9 M: not started by a command */
    alex_saca_056,  /* 58 ATTACK 9 L: not started by a command */
    alex_saca_056,  /* 59 ATTACK 9 SP: not started by a command */
    alex_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    alex_saca_060,  /* 61 ATTACK 10 M: not started by a command */
    alex_saca_060,  /* 62 ATTACK 10 L: not started by a command */
    alex_saca_063,  /* 63 ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP) */
    alex_saca_064,  /* 64 ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
    alex_saca_065,  /* 65 ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    alex_saca_066,  /* 66 ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    alex_saca_067,  /* 67 ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    alex_saca_068,  /* 68 ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT) */
    alex_saca_069,  /* 69 ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    alex_saca_069,  /* 70 ATTACK 12 L: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 alex_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x707B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7080, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7081, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7082, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7083, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7084, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x7085, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -3584, 4864), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 alex_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 alex_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7085, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x7084, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x7084, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7083, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7082, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7081, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7080, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707F, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x707B, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 alex_saca_002_head[4] = { HEAD(4, 0, 8, 13, 0, 5, 0) };
const u16 alex_saca_002[172] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x08D7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08D8, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08DA, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08DB, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x08DC, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x08DD, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0835, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0836, 0, 70, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0837, -27, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0838, 0, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0839, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x083A, 0, 72, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x083B, 0, 73, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0639, 0, 73, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0697, 0, 73, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0698, 0, 73, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0699, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x069A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
const u16 alex_saca_024_head[4] = { HEAD(6, 0, 25, 8, 0, 1, 23) };
const u16 alex_saca_024[196] = {
    CMD(CM_CAFR, 2, 5, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 935, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CC, 0, 4, 0, 0, 0, 1, 24, 0, 0, 430, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x0840, -61, 13, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0840, 0, 13, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0944, 0, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 21, 0, 0, 0, 428, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
const u16 alex_saca_025_head[4] = { HEAD(6, 0, 27, 8, 0, 1, 23) };
const u16 alex_saca_025[184] = {
    CMD(CM_CAFR, 2, 5, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 935, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CC, 0, 4, 0, 0, 0, 1, 24, 0, 0, 430, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x0840, 0, 13, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x0944, -61, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 21, 0, 0, 0, 428, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
const u16 alex_saca_026_head[4] = { HEAD(6, 0, 29, 9, 0, 1, 23) };
const u16 alex_saca_026[184] = {
    CMD(CM_CAFR, 2, 5, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 935, 0, 0, 0, 0, 0x0632, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CA, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CC, 0, 4, 0, 0, 0, 1, 24, 0, 0, 430, 0, 0),
    L6(5, 20, 0, 0, 0, 0, 0, 0x0840, 0, 13, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0944, -61, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 21, 0, 0, 0, 428, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
const u16 alex_saca_027_head[4] = { HEAD(6, 0, 31, 9, 0, 1, 23) };
const u16 alex_saca_027[208] = {
    CMD(CM_CAFR, 2, 5, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 935, 0, 0, 0, 0, 0x0632, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CA, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07CC, 0, 3, 0, 0, 0, 1, 24, 0, 0, 430, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x0840, -94, 103, 0, 138, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0840, 0, 104, 0, 128, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0944, 0, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x0657, 0, 13, 0, 0, 0, 21, 0, 0, 0, 428, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x065B, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_028_head[4] = { HEAD(6, 0, 8, 13, 0, 1, 0) };
const u16 alex_saca_028[208] = {
    L6(3, 0, 939, 0, 0, 0, 0, 0x08B1, 0, 134, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x08B2, 0, 134, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x08B3, 0, 134, 0, 0, 0, 33, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 0, 0, 0, 6, 0, 0x08B4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(1, 0, 270, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(1, 20, 0, 0, 0, 8, 0, 0x08B7, -39, 135, 0, 128, 0, 30, 7, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x08B8, 0, 136, 0, 0, 0, 30, 8, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 10, 0, 0x08B9, 0, 137, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 12, 0, 0x08BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 13, 0, 0x08BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_029_head[4] = { HEAD(6, 0, 10, 13, 0, 1, 0) };
const u16 alex_saca_029[220] = {
    L6(4, 0, 939, 0, 0, 0, 0, 0x08B1, 0, 138, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08B2, 0, 138, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x08B3, 0, 138, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 6, 0, 0x08B4, 0, 1, 0, 0, 0, 33, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 270, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 8, 0, 0x08B7, -52, 139, 0, 128, 64, 30, 7, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x08B8, 0, 140, 0, 0, 64, 30, 8, 0, 0, 184, 0, 0),
    L6(2, 21, 0, 0, 0, 10, 0, 0x08B9, 0, 141, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 12, 0, 0x08BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 13, 0, 0x08BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_030_head[4] = { HEAD(6, 0, 12, 14, 0, 1, 0) };
const u16 alex_saca_030[208] = {
    L6(5, 0, 939, 0, 0, 0, 0, 0x08B1, 0, 142, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x08B2, 0, 142, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 5, 0, 0x08B3, 0, 142, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 6, 0, 0x08B4, 0, 1, 0, 0, 0, 33, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 270, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 8, 0, 0x08B7, -53, 143, 0, 128, 64, 30, 7, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 9, 0, 0x08B8, 0, 144, 0, 0, 64, 30, 8, 0, 0, 184, 0, 0),
    L6(2, 21, 0, 0, 0, 10, 0, 0x08B9, 0, 145, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 12, 0, 0x08BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 13, 0, 0x08BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_031_head[4] = { HEAD(6, 0, 14, 14, 0, 2, 0) };
const u16 alex_saca_031[220] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 939, 0, 0, 0, 0, 0x08B1, 0, 142, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08B2, 0, 142, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 0, 0, 0, 0, 5, 0, 0x08B3, 0, 142, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 0, 0, 0, 6, 0, 0x08B4, 0, 1, 0, 0, 0, 33, 0, 0, 0, 178, 0, 0),
    L6(1, 0, 0, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 270, 0, 0, 7, 0, 0x08B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 8, 0, 0x08B7, -84, 171, 0, 0, 64, 30, 7, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 9, 0, 0x08B8, -90, 172, 0, 0, 64, 30, 8, 0, 0, 184, 0, 0),
    L6(2, 21, 0, 0, 0, 10, 0, 0x08B9, 0, 145, 0, 0, 0, 21, 0, 0, 0, 186, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 12, 0, 0x08BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 13, 0, 0x08BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 6(123)4+P light (plain script) */
const u16 alex_saca_032_head[4] = { HEAD(6, 0, 24, 12, 0, 0, 22) };
const u16 alex_saca_032[148] = {
    CMD(CM_CAFR, 2, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 935, 0, 0, 0, 0, 0x0860, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0862, 0, 99, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0863, -43, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0866, 0, 99, 0, 0, 0, 21, 0, 0, 0, 202, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0867, 0, 99, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0868, 0, 99, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 6(123)4+P medium (plain script) */
const u16 alex_saca_033_head[4] = { HEAD(6, 0, 26, 11, 0, 0, 22) };
const u16 alex_saca_033[148] = {
    CMD(CM_CAFR, 2, 4, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 935, 0, 0, 0, 0, 0x0860, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0862, 0, 99, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0863, -43, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0866, 0, 99, 0, 0, 0, 21, 0, 0, 0, 202, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x0867, 0, 99, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0868, 0, 99, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 6(123)4+P heavy/EX (plain script), 35 ATTACK 3 SP: 6(123)4+P heavy/EX (plain script) */
const u16 alex_saca_034_head[4] = { HEAD(6, 0, 28, 10, 0, 0, 22) };
const u16 alex_saca_034[148] = {
    CMD(CM_CAFR, 2, 4, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 935, 0, 0, 0, 0, 0x0860, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0862, 0, 99, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0863, -43, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0866, 0, 99, 0, 0, 0, 21, 0, 0, 0, 202, 0, 0),
    L6(18, 0, 0, 0, 0, 0, 0, 0x0867, 0, 99, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0868, 0, 99, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 360+P (plain script), 37 ATTACK 4 M: SA I 360+P (plain script), 38 ATTACK 4 L: SA I 360+P (plain script), 39 ATTACK 4 SP: SA I 360+P (plain script) */
const u16 alex_saca_036_head[4] = { HEAD(6, 0, 56, 13, 0, 0, 37) };
const u16 alex_saca_036[160] = {
    CMD(CM_CAFR, 2, 4, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 938, 0, 0, 0, 0, 0x0860, 0, 117, 0, 0, 0, 13, 27, 780, 0, 216, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0862, 0, 117, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0863, -79, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0866, 0, 99, 0, 0, 0, 21, 0, 0, 0, 202, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0867, 0, 99, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0868, 0, 99, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI), 41 ATTACK 5 M: SA II 23623+P (routine Att_CHOUCHUURENGEKI), 42 ATTACK 5 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_040_head[4] = { HEAD(6, 0, 48, 14, 0, 4, 37) };
const u16 alex_saca_040[460] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 938, 0, 0, 0, 0, 0x0675, 0, 117, 0, 0, 0, 13, 23, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BC, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0759, 0, 117, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x075A, 0, 117, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075B, 0, 117, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075C, -64, 125, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075D, 65, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075E, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075F, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0760, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x08B5, 0, 133, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08B7, -66, 127, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x08B8, 67, 128, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x08B9, 0, 133, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BB, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BC, 0, 149, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0759, 0, 149, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x075A, 0, 149, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075B, 0, 149, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075C, -68, 129, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075D, 69, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x075E, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x075F, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0760, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x08B5, 0, 133, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08B7, -70, 131, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x08B8, 71, 132, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x08B9, 0, 133, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BA, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x08BB, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BC, 0, 149, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08BD, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 44, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
const u16 alex_saca_043_head[4] = { HEAD(6, 0, 48, 13, 0, 0, 37) };
const u16 alex_saca_043[160] = {
    CMD(CM_CAFR, 2, 4, 27), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 935, 0, 0, 0, 0, 0x0860, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0862, 0, 99, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0863, -78, 157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0866, 0, 99, 0, 0, 0, 21, 0, 0, 0, 202, 0, 0),
    L6(18, 0, 0, 0, 0, 0, 0, 0x0867, 0, 99, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0868, 0, 99, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0755, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2), 45 ATTACK 6 M: SA III 23623+P (routine Att_SENPUUKYAKU2), 46 ATTACK 6 L: SA III 23623+P (routine Att_SENPUUKYAKU2), 47 ATTACK 6 SP: SA III 23623+P (routine Att_SENPUUKYAKU2) */
const u16 alex_saca_044_head[4] = { HEAD(6, 0, 40, 15, 0, 1, 72) };
const u16 alex_saca_044[420] = {
    CMD(CM_CAFR, 2, 5, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0904, 0, 117, 0, 0, 0, 13, 24, 0, 0, 0, 0, 0),
    L6(4, 0, 938, 0, 0, 0, 0, 0x0905, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0906, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(40, 0, 0, 0, 0, 0, 0, 0x0907, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0903, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0902, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x0651, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0652, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0653, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0654, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0655, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08F4, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08F3, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x08F2, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08F1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x08F0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07F0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x07F1, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x07F2, -59, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x07F3, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000F, 0x0600, 0x001E, 0x0010, 0x0005, 0x0034, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x068E,
    CMD(CM_DJMP, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x11A0, 0x0000, 0x068D,
    CMD(CM_DJMP, 24576, 0, 0), 0x0000, 0x0000, 0x0132, 0x0000, 0x0200, 0x0000, 0x0000, 0x0755,
    CMD(CM_DJMP, 24576, 0, 0), 0x0000, 0x0000, 0x0134, 0x0000, 0x0414, 0x3A50, 0x0000, 0x093B,
    CMD(CM_NEX, 8192, 0, 0), 0x0000, 0x0000, 0x0136, 0x0000, 0x0400, 0x0000, 0x0000, 0x093B,
    CMD(CM_NEX, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x093C,
    CMD(CM_NEX, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x041E, 0x0000, 0x0000, 0x093D,
    CMD(CM_NEX, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFA00, 0x0000, 0x0000, 0x093E,
    CMD(CM_NEX, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 48 ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
const u16 alex_saca_048_head[4] = { HEAD(4, 0, 9, 6, 0, 1, 30) };
const u16 alex_saca_048[100] = {
    CMD(CM_RJA, 5, 52, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 306, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x068D, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 308, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0755, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 310, 0, 0), 0, 0, 0, 0,
    L4(4, 20, 933, 0, 0, 0, 0, 0x093B, 0, 105, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093B, 0, 106, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093C, 0, 107, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093D, 0, 107, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x093E, 0, 107, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
const u16 alex_saca_049_head[4] = { HEAD(4, 0, 11, 6, 0, 1, 30) };
const u16 alex_saca_049[100] = {
    CMD(CM_RJA, 5, 53, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 306, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x068D, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 308, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0755, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 310, 0, 0), 0, 0, 0, 0,
    L4(4, 20, 933, 0, 0, 0, 0, 0x093B, 0, 105, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093B, 0, 106, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093C, 0, 107, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093D, 0, 107, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x093E, 0, 107, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
const u16 alex_saca_050_head[4] = { HEAD(4, 0, 13, 6, 0, 1, 30) };
const u16 alex_saca_050[100] = {
    CMD(CM_RJA, 5, 54, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 306, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x068D, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 308, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0755, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 310, 0, 0), 0, 0, 0, 0,
    L4(4, 20, 933, 0, 0, 0, 0, 0x093B, 0, 105, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093B, 0, 106, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093C, 0, 107, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x093D, 0, 107, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x093E, 0, 107, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: EX [2](789)+KK (routine Att_HOMING_JUMP) */
const u16 alex_saca_051_head[4] = { HEAD(4, 0, 15, 6, 0, 1, 30) };
const u16 alex_saca_051[84] = {
    CMD(CM_RJA, 5, 55, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 0, 282, 0, 0, 0, 0, 0x068D, 0, 91, 0, 0, 0, 32, 153),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0755, 0, 91, 0, 0, 0, 32, 154),
    L4(4, 30, 933, 0, 0, 0, 0, 0x093B, 0, 105, 0, 0, 0, 32, 155),
    L4(5, 0, 0, 0, 0, 0, 0, 0x093B, 0, 106, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x093C, 0, 107, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x093D, 0, 107, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x093E, 0, 107, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU) */
const u16 alex_saca_052_head[4] = { HEAD(4, 0, 9, 6, 0, 1, 30) };
const u16 alex_saca_052[36] = {
    CMD(CM_EXEC, 1, 43, 0), 0, 0, 0, 0,
    L4(2, 0, 285, 0, 0, 0, 0, 0x093F, -73, 118, 0, 132, 0, 1, 44),
    CMD(CM_JPSS, 5, 54, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 54, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU) */
const u16 alex_saca_053_head[4] = { HEAD(4, 0, 11, 6, 0, 1, 30) };
const u16 alex_saca_053[36] = {
    CMD(CM_EXEC, 1, 43, 0), 0, 0, 0, 0,
    L4(2, 0, 285, 0, 0, 0, 0, 0x093F, -74, 118, 0, 132, 0, 1, 44),
    CMD(CM_JPSS, 5, 54, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 54, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) */
const u16 alex_saca_054_head[4] = { HEAD(4, 0, 13, 6, 1, 0, 30) };
const u16 alex_saca_054[204] = {
    CMD(CM_EXEC, 1, 43, 0), 0, 0, 0, 0,
    L4(2, 0, 285, 0, 0, 0, 0, 0x093F, -75, 118, 0, 146, 0, 1, 44),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0941, 0, 119, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0904, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0905, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0906, 0, 1, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0907, 0, 1, 0, 0, 96, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0908, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0909, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x090A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x090B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x090C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0927, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 32, 58),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0941, 0, 119, 0, 0, 0, 32, 156),
    L4(2, 0, 274, 0, 0, 0, 0, 0x0902, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0903, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0904, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0905, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0906, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0907, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: after [2](789)+K (routine Att_HOMING_JUMP) */
const u16 alex_saca_055_head[4] = { HEAD(4, 0, 15, 6, 0, 1, 30) };
const u16 alex_saca_055[36] = {
    CMD(CM_EXEC, 1, 43, 0), 0, 0, 0, 0,
    L4(2, 0, 285, 0, 0, 0, 0, 0x093F, -85, 118, 0, 132, 0, 1, 44),
    CMD(CM_JPSS, 5, 54, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 54, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 alex_saca_056_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 33) };
const u16 alex_saca_056[1788] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0631, 0, 63, 0, 0, 0, 0, 0),
    L4(7, 20, 0, 0, 0, 0, 0, 0x0840, 0, 13, 0, 0, 0, 22, 20),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0841, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x0843, -81, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0844, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0845, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0846, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0847, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_JPSS, 48, 0, 0), 0x0400, 0x0000, 0x0000, 0x0756,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0757,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0758,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0759,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x075A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x075B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x075C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x075D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x075E,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B4,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B4,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B7,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08B9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08BA,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08BB,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08BC,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08BD,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x08BF,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0860,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0862,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0863,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0864,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0865,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x087C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x087E,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x087F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0880,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0881,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0882,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0883,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0884,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0886,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0887,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0888,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088E,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x088F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0636,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0637,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0638,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x0639,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x063A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x063B,
    CMD(CM_DUMMY, 8192, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x063B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0002, 0x0000, 0x0000, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 8, 3584, 3584), 0x0010, 0x0005, 0x0018, 0x0014,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x068D,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0755, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0214, 0x0000, 0x0000, 0x0944,
    L4(11, 12, 3584, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0945, -45, 104, 0, 71, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 2048), 0x0600, 0x0000, 0x0000, 0x0945,
    CMD(CM_ADDR, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0900,
    L4(4, 20, 0, 0, 0, 0, 0, 0x0681, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0682,
    CMD(CM_ROA, -8192, 0, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x07F8, 0, 92, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x07F9,
    CMD(CM_DJMP, -32768, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x07FA, 0, 92, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x000A, 0x07FB,
    L4(246, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x07FC, 38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x000A, 0x07FD,
    L4(9, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x07FE, 38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x000A, 0x07FF,
    CMD(CM_DJMP, -16384, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 12, 0x0800, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0829, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x082A,
    CMD(CM_DJMP, 0, 0, 0), 0x0000, 0x0000, 0x0146, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x082B, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 326, 0), 0x0200, 0x0000, 0x0000, 0x082C,
    CMD(CM_DJMP, 0, 0, 0), 0x0000, 0x0000, 0x0146, 0x0000,
    L4(3, 0, 0, 0, 0, 0, 0, 0x082D, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 326, 0), 0x0300, 0x0000, 0x0000, 0x082D,
    CMD(CM_DJMP, 0, 0, 0), 0x0000, 0x0000, 0x0146, 0x0000,
    L4(4, 64, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0638,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x063A,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x063B,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0008, 0x0E00, 0x0E00,
    CMD(CM_RJA, 5, 24, 20), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x068E,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x0755,
    CMD(CM_ADDR, 16384, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x0944, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x0945,
    L4(244, 205, 0, 0, 0, 1136, 0, 0x0000, 0, 0, 0, 0, 0, 8, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0945, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 2304), 0x0614, 0x0000, 0x0000, 0x0681,
    CMD(CM_ADDR, 16384, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0682, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x041E, 0x0000, 0x0000, 0x07F8,
    CMD(CM_DJMP, -32768, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x07F9, 0, 92, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x07FA,
    CMD(CM_DJMP, -32768, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 8, 0x07FB, -38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0008, 0x07FC,
    L4(9, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x07FD, 38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0008, 0x07FE,
    L4(9, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x07FF, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x0800,
    CMD(CM_DJMP, -16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x0630,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0440, 0x0000, 0x0000, 0x0632,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0636,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0638,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x063A,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x063B,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0008, 0x0E00, 0x0E00,
    CMD(CM_RJA, 5, 24, 20), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x068E,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x068D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x0755,
    CMD(CM_ADDR, 16384, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x0944, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x0945,
    L4(244, 205, 0, 0, 0, 1136, 0, 0x0000, 0, 0, 0, 0, 0, 8, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0945, 0, 74, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 2304), 0x0814, 0x0000, 0x0000, 0x0681,
    CMD(CM_ADDR, 16384, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0682, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x021E, 0x0000, 0x0000, 0x07F8,
    CMD(CM_DJMP, -32768, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x07F9, 0, 92, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x07FA,
    CMD(CM_DJMP, -32768, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 8, 0x07FB, -38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0008, 0x07FC,
    L4(9, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x07FD, 38, 93, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0008, 0x07FE,
    L4(9, 139, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x07FF, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x0800,
    CMD(CM_DJMP, -16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x0630,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0440, 0x0000, 0x0000, 0x0632,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0633, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0636,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0637, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x0638,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x063A,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x063B,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000B, 0x0000, 0x0000,
    CMD(CM_EXEC, 1, 43, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x11D0, 0x0000, 0x093F,
    L4(237, 206, 3072, 0, 0, 2224, 0, 0x012C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0941, 0, 119, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 312, 0), 0x0340, 0x0000, 0x0000, 0x0942,
    CMD(CM_NEX2, 0, 0, 0), 0x0000, 0x0000, 0x013A, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0943, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 316, 0), 0x0300, 0x0000, 0x0000, 0x090A,
    CMD(CM_NEX, -8192, 0, 0), 0x0000, 0x0000, 0x013E, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x090B, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 320, 0), 0x0200, 0x0000, 0x0000, 0x090C,
    CMD(CM_NEX, -8192, 0, 0), 0x0000, 0x0000, 0x0142, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0927, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 324, 0), 0xFAFF, 0x0000, 0x0000, 0x0927,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0941, 0, 119, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 312, 0), 0x0300, 0x0000, 0x0000, 0x0942,
    CMD(CM_NEX2, 0, 0, 0), 0x0000, 0x0000, 0x013A, 0x0500,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command, 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command */
const u16 alex_saca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 alex_saca_060[220] = {
    CMD(CM_ASXY, 388, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0947, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0948, 0, 1, 0, 0, 0, 32, 195),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0949, 0, 158, 0, 0, 0, 32, 196),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094E, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 40, 0, 0, 0, 0, 0, 0x094F, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0950, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x0951, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0952, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094A, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094B, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094C, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094D, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094E, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094F, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0950, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 0, 0, 0x0951, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0952, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, -32759, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x094A, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x094B, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0953, 0, 158, 0, 0, 0, 32, 197),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0954, 0, 158, 0, 0, 0, 32, 198),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0638, 0, 1, 0, 0, 0, 32, 199),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x063A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x063B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP) */
const u16 alex_saca_063_head[4] = { HEAD(6, 0, 8, 11, 0, 1, 73) };
const u16 alex_saca_063[256] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0955, 0, 159, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0956, 0, 160, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(1, 30, 935, 0, 0, 0, 0, 0x0957, 0, 161, 0, 0, 0, 30, 76, 0, 0, 440, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0958, 0, 162, 0, 0, 0, 30, 77, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0959, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x095A, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 279, 0, 0, 0, 0, 0x095B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x0770, 0, 1, 0, 0, 0, 30, 78, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x0771, 0, 1, 0, 0, 0, 30, 79, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x0772, -87, 164, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 17, 0, 0x0776, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0777, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0778, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0779, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x077A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
const u16 alex_saca_064_head[4] = { HEAD(6, 0, 10, 13, 0, 1, 73) };
const u16 alex_saca_064[316] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0955, 0, 159, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0956, 0, 160, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(2, 30, 935, 0, 0, 0, 0, 0x0957, 0, 161, 0, 0, 0, 30, 76, 0, 0, 440, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0958, 0, 162, 0, 0, 0, 30, 77, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0959, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x095A, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 279, 0, 0, 0, 0, 0x095B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x0770, 0, 1, 0, 0, 0, 30, 78, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x0771, 0, 1, 0, 0, 0, 30, 79, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x0772, -88, 164, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 16389), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 17, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 17, 0, 0x0776, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0777, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0778, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0779, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x077A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
const u16 alex_saca_065_head[4] = { HEAD(6, 0, 12, 15, 0, 1, 73) };
const u16 alex_saca_065[316] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0955, 0, 159, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0956, 0, 160, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(2, 30, 935, 0, 0, 0, 0, 0x0957, 0, 161, 0, 0, 0, 30, 76, 0, 0, 440, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0958, 0, 162, 0, 0, 0, 30, 77, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0959, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x095A, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 279, 0, 0, 0, 0, 0x095B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x0770, 0, 1, 0, 0, 0, 30, 78, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x0771, 0, 1, 0, 0, 0, 30, 79, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x0772, -89, 164, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 16389), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 17, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 17, 0, 0x0776, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0777, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0778, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0779, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x077A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
const u16 alex_saca_066_head[4] = { HEAD(6, 0, 14, 17, 0, 2, 73) };
const u16 alex_saca_066[280] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0955, 0, 159, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0956, 0, 160, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(2, 30, 935, 0, 0, 0, 0, 0x0957, 0, 161, 0, 0, 0, 30, 76, 0, 0, 440, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0958, 0, 162, 0, 0, 0, 30, 77, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0959, -91, 165, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x095A, 91, 165, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 279, 0, 0, 0, 0, 0x095B, 0, 163, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x095C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0770, 0, 1, 0, 0, 0, 30, 78, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x0771, 0, 1, 0, 0, 0, 30, 79, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x0772, -92, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 16, 0, 0x0773, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 17, 0, 0x0774, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0775, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 0, 0, 0x0776, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0777, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0778, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0779, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x077A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
const u16 alex_saca_067_head[4] = { HEAD(4, 0, 24, 7, 0, 0, 115) };
const u16 alex_saca_067[108] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x068B, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 20, 934, 0, 0, 0, 0, 0x0654, 0, 204, 0, 0, 0, 30, 202),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D3, 0, 242, 0, 0, 0, 30, 203),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09D4, 0, 205, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09D5, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09D6, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09D7, -98, 206, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D5, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D4, 0, 205, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D3, 0, 242, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D2, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT) */
const u16 alex_saca_068_head[4] = { HEAD(4, 0, 26, 9, 0, 0, 115) };
const u16 alex_saca_068[60] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x068B, 0, 203, 0, 0, 0, 0, 0),
    L4(5, 20, 934, 0, 0, 0, 0, 0x0654, 0, 204, 0, 0, 0, 30, 202),
    L4(4, 0, 0, 0, 0, 0, 0, 0x09D3, 0, 242, 0, 0, 0, 30, 203),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09D4, 0, 205, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09D5, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 67, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT), 70 ATTACK 12 L: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
const u16 alex_saca_069_head[4] = { HEAD(4, 0, 28, 10, 0, 0, 115) };
const u16 alex_saca_069[60] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x068B, 0, 203, 0, 0, 0, 0, 0),
    L4(7, 20, 934, 0, 0, 0, 0, 0x0654, 0, 204, 0, 0, 0, 30, 202),
    L4(5, 0, 0, 0, 0, 0, 0, 0x09D3, 0, 242, 0, 0, 0, 30, 203),
    L4(3, 0, 0, 0, 0, 0, 0, 0x09D4, 0, 205, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x09D5, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 67, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 26 entries */
const u16* const alex_cbca[27] = {
    alex_cbca_000,  /* 0 APPEAR JUNBI 1 */
    alex_cbca_001,  /* 1 APPEAR JUNBI 2 */
    alex_cbca_002,  /* 2 APPEAR JUNBI 3 */
    alex_cbca_003,  /* 3 APPEAR JUNBI 4 */
    alex_cbca_004,  /* 4 APPEAR JUNBI 5 */
    alex_cbca_005,  /* 5 APPEAR JUNBI 6 */
    alex_cbca_006,  /* 6 APPEAR JUNBI 7 */
    alex_cbca_007,  /* 7 APPEAR JUNBI 8 */
    alex_cbca_008,  /* 8 APPEAR 1 */
    alex_cbca_009,  /* 9 APPEAR 2 */
    alex_cbca_010,  /* 10 APPEAR 3 */
    alex_cbca_011,  /* 11 APPEAR 4 */
    alex_cbca_012,  /* 12 APPEAR 5 */
    alex_cbca_013,  /* 13 APPEAR 6 */
    alex_cbca_014,  /* 14 APPEAR 7 */
    alex_cbca_015,  /* 15 APPEAR 8 */
    alex_cbca_016,  /* 16 SP APPEAR 1 */
    alex_cbca_017,  /* 17 SP APPEAR 2 */
    alex_cbca_018,  /* 18 SP APPEAR 3 */
    alex_cbca_019,  /* 19 SP APPEAR 4 */
    alex_cbca_020,  /* 20 SP APPEAR 5 */
    alex_cbca_021,  /* 21 SP APPEAR 6 */
    alex_cbca_022,  /* 22 SP APPEAR 7 */
    alex_cbca_023,  /* 23 SP APPEAR 8 */
    alex_cbca_024,  /* 24 ZANNEN 1 */
    alex_cbca_025,  /* 25 ZANNEN 2 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 alex_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 alex_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 alex_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 alex_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 alex_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_004[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 alex_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 alex_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 alex_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_007[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 23),
    CMD(CM_CARE, 2, 2, 23),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 2),
    CMD(CM_CARE, 2, 2, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 alex_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_008[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 30, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 alex_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_009[32] = {
    CMD(CM_RJA7, 8, 9, 6),
    CMD(CM_DJMP, 8202, 8192, 8200),
    CMD(CM_CAFR, 2, 2, 23),
    CMD(CM_CARE, 2, 2, 23),
    CMD(CM_JMP, 4, 8, 3),
    CMD(CM_CAFR, 2, 2, 2),
    CMD(CM_CARE, 2, 2, 2),
    CMD(CM_JMP, 4, 8, 3),
};

/* script: 10 APPEAR 3 */
const u16 alex_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_010[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 alex_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 alex_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_012[16] = {
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 alex_cbca_013_head[4] = { HEAD(2, 0, 41, 0, 0, 0, 0) };
const u16 alex_cbca_013[28] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 alex_cbca_014_head[4] = { HEAD(2, 0, 48, 0, 0, 0, 0) };
const u16 alex_cbca_014[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 58, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 alex_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_015[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 alex_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_016[12] = {
    CMD(CM_RJA, 4, 89, 12),
    CMD(CM_WSET, 16384, 0, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 alex_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_017[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 alex_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_018[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 alex_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_019[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 46, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 alex_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_020[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 48, 1),
    CMD(CM_RJA3, 7, 49, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 alex_cbca_021_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 alex_cbca_021[16] = {
    CMD(CM_EXEC, 49, 9, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 alex_cbca_022_head[4] = { HEAD(2, 0, 31, 0, 0, 0, 0) };
const u16 alex_cbca_022[16] = {
    CMD(CM_EXEC, 49, 10, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 alex_cbca_023_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 alex_cbca_023[16] = {
    CMD(CM_EXEC, 49, 11, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 alex_cbca_024_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 alex_cbca_024[16] = {
    CMD(CM_EXEC, 49, 12, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 alex_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 alex_cbca_025[24] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 15, 1),
    CMD(CM_RJA3, 7, 16, 1),
    CMD(CM_CAFR, 2, 1, 33),
    CMD(CM_CARE, 2, 1, 33),
    CMD(CM_RET, 0, 0, 0),
};

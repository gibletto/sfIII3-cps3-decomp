/*
 * GILL_CHAR.C  Gill's animation scripts and sprite part tables
 *
 * The animation scripts Gill's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 gill_nmca_051[], gill_nmca_052[], gill_nmca_053[], gill_nmca_054[], gill_nmca_055[], gill_nmca_056[], gill_nmca_057[], gill_nmca_058[], gill_nmca_059[], gill_nmca_060[], gill_nmca_061[], gill_nmca_062[], gill_nmca_000[], gill_nmca_001[], gill_nmca_002[], gill_nmca_003[], gill_nmca_004[], gill_nmca_005[], gill_nmca_006[], gill_nmca_007[], gill_nmca_008[], gill_nmca_011[], gill_nmca_012[], gill_nmca_013[], gill_nmca_014[], gill_nmca_015[], gill_nmca_016[], gill_nmca_017[], gill_nmca_020[], gill_nmca_021[], gill_nmca_022[], gill_nmca_023[], gill_nmca_024[], gill_nmca_026[], gill_nmca_027[], gill_nmca_029[], gill_nmca_031[], gill_nmca_032[], gill_nmca_033[], gill_nmca_038[], gill_nmca_040[], gill_nmca_041[], gill_nmca_043[], gill_nmca_044[], gill_nmca_045[], gill_nmca_046[], gill_nmca_047[], gill_nmca_048[], gill_nmca_049[], gill_nmca_050[];
extern const u16 gill_nmca_051_head[];
extern const u16 gill_nmca_052_head[];
extern const u16 gill_nmca_053_head[];
extern const u16 gill_nmca_054_head[];
extern const u16 gill_nmca_055_head[];
extern const u16 gill_nmca_056_head[];
extern const u16 gill_nmca_057_head[];
extern const u16 gill_nmca_058_head[];
extern const u16 gill_nmca_059_head[];
extern const u16 gill_nmca_060_head[];
extern const u16 gill_nmca_061_head[];
extern const u16 gill_nmca_062_head[];
extern const u16 gill_nmca_000_head[];
extern const u16 gill_nmca_001_head[];
extern const u16 gill_nmca_002_head[];
extern const u16 gill_nmca_003_head[];
extern const u16 gill_nmca_004_head[];
extern const u16 gill_nmca_005_head[];
extern const u16 gill_nmca_006_head[];
extern const u16 gill_nmca_007_head[];
extern const u16 gill_nmca_008_head[];
extern const u16 gill_nmca_011_head[];
extern const u16 gill_nmca_012_head[];
extern const u16 gill_nmca_013_head[];
extern const u16 gill_nmca_014_head[];
extern const u16 gill_nmca_015_head[];
extern const u16 gill_nmca_016_head[];
extern const u16 gill_nmca_017_head[];
extern const u16 gill_nmca_020_head[];
extern const u16 gill_nmca_021_head[];
extern const u16 gill_nmca_022_head[];
extern const u16 gill_nmca_023_head[];
extern const u16 gill_nmca_024_head[];
extern const u16 gill_nmca_026_head[];
extern const u16 gill_nmca_027_head[];
extern const u16 gill_nmca_029_head[];
extern const u16 gill_nmca_031_head[];
extern const u16 gill_nmca_032_head[];
extern const u16 gill_nmca_033_head[];
extern const u16 gill_nmca_038_head[];
extern const u16 gill_nmca_040_head[];
extern const u16 gill_nmca_041_head[];
extern const u16 gill_nmca_043_head[];
extern const u16 gill_nmca_044_head[];
extern const u16 gill_nmca_045_head[];
extern const u16 gill_nmca_046_head[];
extern const u16 gill_nmca_047_head[];
extern const u16 gill_nmca_048_head[];
extern const u16 gill_nmca_049_head[];
extern const u16 gill_nmca_050_head[];
extern const u16 gill_dmca_000[], gill_dmca_002[], gill_dmca_003[], gill_dmca_004[], gill_dmca_006[], gill_dmca_008[], gill_dmca_009[], gill_dmca_010[], gill_dmca_014[], gill_dmca_015[], gill_dmca_019[], gill_dmca_022[], gill_dmca_024[], gill_dmca_029[], gill_dmca_030[], gill_dmca_036[], gill_dmca_037[], gill_dmca_038[], gill_dmca_039[], gill_dmca_040[], gill_dmca_041[], gill_dmca_042[], gill_dmca_043[], gill_dmca_048[], gill_dmca_049[], gill_dmca_050[], gill_dmca_052[], gill_dmca_053[], gill_dmca_054[], gill_dmca_055[], gill_dmca_056[], gill_dmca_057[], gill_dmca_058[], gill_dmca_059[], gill_dmca_060[], gill_dmca_064[], gill_dmca_065[], gill_dmca_066[], gill_dmca_067[], gill_dmca_068[], gill_dmca_069[], gill_dmca_070[], gill_dmca_071[], gill_dmca_072[], gill_dmca_073[], gill_dmca_074[], gill_dmca_075[], gill_dmca_076[], gill_dmca_078[], gill_dmca_079[], gill_dmca_080[], gill_dmca_082[], gill_dmca_083[], gill_dmca_084[], gill_dmca_096[], gill_dmca_097[];
extern const u16 gill_dmca_000_head[];
extern const u16 gill_dmca_002_head[];
extern const u16 gill_dmca_003_head[];
extern const u16 gill_dmca_004_head[];
extern const u16 gill_dmca_006_head[];
extern const u16 gill_dmca_008_head[];
extern const u16 gill_dmca_009_head[];
extern const u16 gill_dmca_010_head[];
extern const u16 gill_dmca_014_head[];
extern const u16 gill_dmca_015_head[];
extern const u16 gill_dmca_019_head[];
extern const u16 gill_dmca_022_head[];
extern const u16 gill_dmca_024_head[];
extern const u16 gill_dmca_029_head[];
extern const u16 gill_dmca_030_head[];
extern const u16 gill_dmca_036_head[];
extern const u16 gill_dmca_037_head[];
extern const u16 gill_dmca_038_head[];
extern const u16 gill_dmca_039_head[];
extern const u16 gill_dmca_040_head[];
extern const u16 gill_dmca_041_head[];
extern const u16 gill_dmca_042_head[];
extern const u16 gill_dmca_043_head[];
extern const u16 gill_dmca_048_head[];
extern const u16 gill_dmca_049_head[];
extern const u16 gill_dmca_050_head[];
extern const u16 gill_dmca_052_head[];
extern const u16 gill_dmca_053_head[];
extern const u16 gill_dmca_054_head[];
extern const u16 gill_dmca_055_head[];
extern const u16 gill_dmca_056_head[];
extern const u16 gill_dmca_057_head[];
extern const u16 gill_dmca_058_head[];
extern const u16 gill_dmca_059_head[];
extern const u16 gill_dmca_060_head[];
extern const u16 gill_dmca_064_head[];
extern const u16 gill_dmca_065_head[];
extern const u16 gill_dmca_066_head[];
extern const u16 gill_dmca_067_head[];
extern const u16 gill_dmca_068_head[];
extern const u16 gill_dmca_069_head[];
extern const u16 gill_dmca_070_head[];
extern const u16 gill_dmca_071_head[];
extern const u16 gill_dmca_072_head[];
extern const u16 gill_dmca_073_head[];
extern const u16 gill_dmca_074_head[];
extern const u16 gill_dmca_075_head[];
extern const u16 gill_dmca_076_head[];
extern const u16 gill_dmca_078_head[];
extern const u16 gill_dmca_079_head[];
extern const u16 gill_dmca_080_head[];
extern const u16 gill_dmca_082_head[];
extern const u16 gill_dmca_083_head[];
extern const u16 gill_dmca_084_head[];
extern const u16 gill_dmca_096_head[];
extern const u16 gill_dmca_097_head[];
extern const u16 gill_btca_000[], gill_btca_001[], gill_btca_002[], gill_btca_003[], gill_btca_004[], gill_btca_005[], gill_btca_006[], gill_btca_007[], gill_btca_008[], gill_btca_009[], gill_btca_010[], gill_btca_011[], gill_btca_012[], gill_btca_013[], gill_btca_014[], gill_btca_015[], gill_btca_016[], gill_btca_017[], gill_btca_018[], gill_btca_019[], gill_btca_020[], gill_btca_022[], gill_btca_023[], gill_btca_025[], gill_btca_026[], gill_btca_027[], gill_btca_028[], gill_btca_029[], gill_btca_030[], gill_btca_031[], gill_btca_032[], gill_btca_033[], gill_btca_034[];
extern const u16 gill_btca_000_head[];
extern const u16 gill_btca_001_head[];
extern const u16 gill_btca_002_head[];
extern const u16 gill_btca_003_head[];
extern const u16 gill_btca_004_head[];
extern const u16 gill_btca_005_head[];
extern const u16 gill_btca_006_head[];
extern const u16 gill_btca_007_head[];
extern const u16 gill_btca_008_head[];
extern const u16 gill_btca_009_head[];
extern const u16 gill_btca_010_head[];
extern const u16 gill_btca_011_head[];
extern const u16 gill_btca_012_head[];
extern const u16 gill_btca_013_head[];
extern const u16 gill_btca_014_head[];
extern const u16 gill_btca_015_head[];
extern const u16 gill_btca_016_head[];
extern const u16 gill_btca_017_head[];
extern const u16 gill_btca_018_head[];
extern const u16 gill_btca_019_head[];
extern const u16 gill_btca_020_head[];
extern const u16 gill_btca_022_head[];
extern const u16 gill_btca_023_head[];
extern const u16 gill_btca_025_head[];
extern const u16 gill_btca_026_head[];
extern const u16 gill_btca_027_head[];
extern const u16 gill_btca_028_head[];
extern const u16 gill_btca_029_head[];
extern const u16 gill_btca_030_head[];
extern const u16 gill_btca_031_head[];
extern const u16 gill_btca_032_head[];
extern const u16 gill_btca_033_head[];
extern const u16 gill_btca_034_head[];
extern const u16 gill_caca_000[], gill_caca_001[], gill_caca_002[];
extern const u16 gill_caca_000_head[];
extern const u16 gill_caca_001_head[];
extern const u16 gill_caca_002_head[];
extern const u16 gill_cuca_000[], gill_cuca_001[], gill_cuca_002[], gill_cuca_003[], gill_cuca_004[], gill_cuca_005[], gill_cuca_006[], gill_cuca_007[], gill_cuca_008[], gill_cuca_009[], gill_cuca_010[], gill_cuca_011[], gill_cuca_012[], gill_cuca_013[], gill_cuca_014[], gill_cuca_015[], gill_cuca_016[], gill_cuca_017[], gill_cuca_018[], gill_cuca_019[], gill_cuca_020[], gill_cuca_021[], gill_cuca_022[], gill_cuca_023[], gill_cuca_024[], gill_cuca_025[], gill_cuca_026[], gill_cuca_027[], gill_cuca_028[], gill_cuca_029[], gill_cuca_030[], gill_cuca_031[], gill_cuca_032[], gill_cuca_033[], gill_cuca_034[], gill_cuca_035[], gill_cuca_036[], gill_cuca_037[], gill_cuca_038[], gill_cuca_039[], gill_cuca_040[], gill_cuca_041[], gill_cuca_042[], gill_cuca_043[], gill_cuca_044[], gill_cuca_045[], gill_cuca_046[], gill_cuca_047[], gill_cuca_048[], gill_cuca_049[], gill_cuca_050[], gill_cuca_051[], gill_cuca_052[], gill_cuca_053[], gill_cuca_054[], gill_cuca_055[], gill_cuca_056[], gill_cuca_057[], gill_cuca_058[], gill_cuca_059[], gill_cuca_060[], gill_cuca_061[], gill_cuca_062[], gill_cuca_063[], gill_cuca_064[], gill_cuca_065[], gill_cuca_066[], gill_cuca_067[];
extern const u16 gill_cuca_000_head[];
extern const u16 gill_cuca_001_head[];
extern const u16 gill_cuca_002_head[];
extern const u16 gill_cuca_003_head[];
extern const u16 gill_cuca_004_head[];
extern const u16 gill_cuca_005_head[];
extern const u16 gill_cuca_006_head[];
extern const u16 gill_cuca_007_head[];
extern const u16 gill_cuca_008_head[];
extern const u16 gill_cuca_009_head[];
extern const u16 gill_cuca_010_head[];
extern const u16 gill_cuca_011_head[];
extern const u16 gill_cuca_012_head[];
extern const u16 gill_cuca_013_head[];
extern const u16 gill_cuca_014_head[];
extern const u16 gill_cuca_015_head[];
extern const u16 gill_cuca_016_head[];
extern const u16 gill_cuca_017_head[];
extern const u16 gill_cuca_018_head[];
extern const u16 gill_cuca_019_head[];
extern const u16 gill_cuca_020_head[];
extern const u16 gill_cuca_021_head[];
extern const u16 gill_cuca_022_head[];
extern const u16 gill_cuca_023_head[];
extern const u16 gill_cuca_024_head[];
extern const u16 gill_cuca_025_head[];
extern const u16 gill_cuca_026_head[];
extern const u16 gill_cuca_027_head[];
extern const u16 gill_cuca_028_head[];
extern const u16 gill_cuca_029_head[];
extern const u16 gill_cuca_030_head[];
extern const u16 gill_cuca_031_head[];
extern const u16 gill_cuca_032_head[];
extern const u16 gill_cuca_033_head[];
extern const u16 gill_cuca_034_head[];
extern const u16 gill_cuca_035_head[];
extern const u16 gill_cuca_036_head[];
extern const u16 gill_cuca_037_head[];
extern const u16 gill_cuca_038_head[];
extern const u16 gill_cuca_039_head[];
extern const u16 gill_cuca_040_head[];
extern const u16 gill_cuca_041_head[];
extern const u16 gill_cuca_042_head[];
extern const u16 gill_cuca_043_head[];
extern const u16 gill_cuca_044_head[];
extern const u16 gill_cuca_045_head[];
extern const u16 gill_cuca_046_head[];
extern const u16 gill_cuca_047_head[];
extern const u16 gill_cuca_048_head[];
extern const u16 gill_cuca_049_head[];
extern const u16 gill_cuca_050_head[];
extern const u16 gill_cuca_051_head[];
extern const u16 gill_cuca_052_head[];
extern const u16 gill_cuca_053_head[];
extern const u16 gill_cuca_054_head[];
extern const u16 gill_cuca_055_head[];
extern const u16 gill_cuca_056_head[];
extern const u16 gill_cuca_057_head[];
extern const u16 gill_cuca_058_head[];
extern const u16 gill_cuca_059_head[];
extern const u16 gill_cuca_060_head[];
extern const u16 gill_cuca_061_head[];
extern const u16 gill_cuca_062_head[];
extern const u16 gill_cuca_063_head[];
extern const u16 gill_cuca_064_head[];
extern const u16 gill_cuca_065_head[];
extern const u16 gill_cuca_066_head[];
extern const u16 gill_cuca_067_head[];
extern const u16 gill_atca_000[], gill_atca_003[], gill_atca_005[], gill_atca_006[], gill_atca_009[], gill_atca_012[], gill_atca_014[], gill_atca_015[], gill_atca_018[], gill_atca_021[], gill_atca_024[], gill_atca_027[], gill_atca_030[], gill_atca_033[], gill_atca_036[], gill_atca_038[], gill_atca_040[], gill_atca_042[], gill_atca_044[], gill_atca_046[], gill_atca_048[], gill_atca_050[], gill_atca_052[], gill_atca_054[], gill_atca_056[], gill_atca_058[], gill_atca_060[], gill_atca_062[], gill_atca_064[], gill_atca_066[], gill_atca_068[], gill_atca_070[], gill_atca_072[], gill_atca_074[], gill_atca_076[], gill_atca_078[], gill_atca_080[], gill_atca_082[], gill_atca_084[], gill_atca_086[], gill_atca_088[], gill_atca_090[], gill_atca_092[], gill_atca_094[], gill_atca_096[], gill_atca_098[], gill_atca_100[], gill_atca_102[], gill_atca_104[], gill_atca_106[], gill_atca_108[], gill_atca_110[], gill_atca_112[], gill_atca_114[], gill_atca_116[], gill_atca_118[], gill_atca_144[], gill_atca_145[], gill_atca_146[], gill_atca_156[];
extern const u16 gill_atca_000_head[];
extern const u16 gill_atca_003_head[];
extern const u16 gill_atca_005_head[];
extern const u16 gill_atca_006_head[];
extern const u16 gill_atca_009_head[];
extern const u16 gill_atca_012_head[];
extern const u16 gill_atca_014_head[];
extern const u16 gill_atca_015_head[];
extern const u16 gill_atca_018_head[];
extern const u16 gill_atca_021_head[];
extern const u16 gill_atca_024_head[];
extern const u16 gill_atca_027_head[];
extern const u16 gill_atca_030_head[];
extern const u16 gill_atca_033_head[];
extern const u16 gill_atca_036_head[];
extern const u16 gill_atca_038_head[];
extern const u16 gill_atca_040_head[];
extern const u16 gill_atca_042_head[];
extern const u16 gill_atca_044_head[];
extern const u16 gill_atca_046_head[];
extern const u16 gill_atca_048_head[];
extern const u16 gill_atca_050_head[];
extern const u16 gill_atca_052_head[];
extern const u16 gill_atca_054_head[];
extern const u16 gill_atca_056_head[];
extern const u16 gill_atca_058_head[];
extern const u16 gill_atca_060_head[];
extern const u16 gill_atca_062_head[];
extern const u16 gill_atca_064_head[];
extern const u16 gill_atca_066_head[];
extern const u16 gill_atca_068_head[];
extern const u16 gill_atca_070_head[];
extern const u16 gill_atca_072_head[];
extern const u16 gill_atca_074_head[];
extern const u16 gill_atca_076_head[];
extern const u16 gill_atca_078_head[];
extern const u16 gill_atca_080_head[];
extern const u16 gill_atca_082_head[];
extern const u16 gill_atca_084_head[];
extern const u16 gill_atca_086_head[];
extern const u16 gill_atca_088_head[];
extern const u16 gill_atca_090_head[];
extern const u16 gill_atca_092_head[];
extern const u16 gill_atca_094_head[];
extern const u16 gill_atca_096_head[];
extern const u16 gill_atca_098_head[];
extern const u16 gill_atca_100_head[];
extern const u16 gill_atca_102_head[];
extern const u16 gill_atca_104_head[];
extern const u16 gill_atca_106_head[];
extern const u16 gill_atca_108_head[];
extern const u16 gill_atca_110_head[];
extern const u16 gill_atca_112_head[];
extern const u16 gill_atca_114_head[];
extern const u16 gill_atca_116_head[];
extern const u16 gill_atca_118_head[];
extern const u16 gill_atca_144_head[];
extern const u16 gill_atca_145_head[];
extern const u16 gill_atca_146_head[];
extern const u16 gill_atca_156_head[];
extern const u16 gill_exca_000[], gill_exca_001[], gill_exca_003[], gill_exca_004[], gill_exca_005[], gill_exca_006[], gill_exca_007[], gill_exca_008[], gill_exca_009[], gill_exca_010[], gill_exca_012[], gill_exca_013[], gill_exca_014[], gill_exca_015[], gill_exca_016[], gill_exca_017[], gill_exca_018[], gill_exca_019[], gill_exca_020[], gill_exca_021[], gill_exca_022[], gill_exca_023[], gill_exca_024[], gill_exca_025[], gill_exca_026[], gill_exca_027[], gill_exca_028[], gill_exca_029[], gill_exca_030[], gill_exca_031[], gill_exca_032[], gill_exca_035[], gill_exca_036[], gill_exca_037[], gill_exca_038[], gill_exca_039[], gill_exca_041[], gill_exca_042[], gill_exca_043[], gill_exca_044[], gill_exca_045[], gill_exca_046[], gill_exca_047[], gill_exca_048[], gill_exca_049[], gill_exca_050[], gill_exca_051[], gill_exca_052[], gill_exca_053[], gill_exca_054[], gill_exca_055[], gill_exca_056[], gill_exca_057[];
extern const u16 gill_exca_000_head[];
extern const u16 gill_exca_001_head[];
extern const u16 gill_exca_003_head[];
extern const u16 gill_exca_004_head[];
extern const u16 gill_exca_005_head[];
extern const u16 gill_exca_006_head[];
extern const u16 gill_exca_007_head[];
extern const u16 gill_exca_008_head[];
extern const u16 gill_exca_009_head[];
extern const u16 gill_exca_010_head[];
extern const u16 gill_exca_012_head[];
extern const u16 gill_exca_013_head[];
extern const u16 gill_exca_014_head[];
extern const u16 gill_exca_015_head[];
extern const u16 gill_exca_016_head[];
extern const u16 gill_exca_017_head[];
extern const u16 gill_exca_018_head[];
extern const u16 gill_exca_019_head[];
extern const u16 gill_exca_020_head[];
extern const u16 gill_exca_021_head[];
extern const u16 gill_exca_022_head[];
extern const u16 gill_exca_023_head[];
extern const u16 gill_exca_024_head[];
extern const u16 gill_exca_025_head[];
extern const u16 gill_exca_026_head[];
extern const u16 gill_exca_027_head[];
extern const u16 gill_exca_028_head[];
extern const u16 gill_exca_029_head[];
extern const u16 gill_exca_030_head[];
extern const u16 gill_exca_031_head[];
extern const u16 gill_exca_032_head[];
extern const u16 gill_exca_035_head[];
extern const u16 gill_exca_036_head[];
extern const u16 gill_exca_037_head[];
extern const u16 gill_exca_038_head[];
extern const u16 gill_exca_039_head[];
extern const u16 gill_exca_041_head[];
extern const u16 gill_exca_042_head[];
extern const u16 gill_exca_043_head[];
extern const u16 gill_exca_044_head[];
extern const u16 gill_exca_045_head[];
extern const u16 gill_exca_046_head[];
extern const u16 gill_exca_047_head[];
extern const u16 gill_exca_048_head[];
extern const u16 gill_exca_049_head[];
extern const u16 gill_exca_050_head[];
extern const u16 gill_exca_051_head[];
extern const u16 gill_exca_052_head[];
extern const u16 gill_exca_053_head[];
extern const u16 gill_exca_054_head[];
extern const u16 gill_exca_055_head[];
extern const u16 gill_exca_056_head[];
extern const u16 gill_exca_057_head[];
extern const u16 gill_saca_000[], gill_saca_001[], gill_saca_002[], gill_saca_024[], gill_saca_025[], gill_saca_029[], gill_saca_033[], gill_saca_034[], gill_saca_035[], gill_saca_037[], gill_saca_041[], gill_saca_045[], gill_saca_049[], gill_saca_053[], gill_saca_054[], gill_saca_055[], gill_saca_058[], gill_saca_059[], gill_saca_060[], gill_saca_061[], gill_saca_062[], gill_saca_063[], gill_saca_064[], gill_saca_065[], gill_saca_066[], gill_saca_067[], gill_saca_068[], gill_saca_069[], gill_saca_070[], gill_saca_071[];
extern const u16 gill_saca_000_head[];
extern const u16 gill_saca_001_head[];
extern const u16 gill_saca_002_head[];
extern const u16 gill_saca_024_head[];
extern const u16 gill_saca_025_head[];
extern const u16 gill_saca_029_head[];
extern const u16 gill_saca_033_head[];
extern const u16 gill_saca_034_head[];
extern const u16 gill_saca_035_head[];
extern const u16 gill_saca_037_head[];
extern const u16 gill_saca_041_head[];
extern const u16 gill_saca_045_head[];
extern const u16 gill_saca_049_head[];
extern const u16 gill_saca_053_head[];
extern const u16 gill_saca_054_head[];
extern const u16 gill_saca_055_head[];
extern const u16 gill_saca_058_head[];
extern const u16 gill_saca_059_head[];
extern const u16 gill_saca_060_head[];
extern const u16 gill_saca_061_head[];
extern const u16 gill_saca_062_head[];
extern const u16 gill_saca_063_head[];
extern const u16 gill_saca_064_head[];
extern const u16 gill_saca_065_head[];
extern const u16 gill_saca_066_head[];
extern const u16 gill_saca_067_head[];
extern const u16 gill_saca_068_head[];
extern const u16 gill_saca_069_head[];
extern const u16 gill_saca_070_head[];
extern const u16 gill_saca_071_head[];
extern const u16 gill_cbca_000[], gill_cbca_001[], gill_cbca_002[], gill_cbca_003[], gill_cbca_004[], gill_cbca_005[], gill_cbca_006[], gill_cbca_007[], gill_cbca_008[], gill_cbca_009[], gill_cbca_010[], gill_cbca_011[], gill_cbca_012[], gill_cbca_013[], gill_cbca_014[], gill_cbca_015[], gill_cbca_016[];
extern const u16 gill_cbca_000_head[];
extern const u16 gill_cbca_001_head[];
extern const u16 gill_cbca_002_head[];
extern const u16 gill_cbca_003_head[];
extern const u16 gill_cbca_004_head[];
extern const u16 gill_cbca_005_head[];
extern const u16 gill_cbca_006_head[];
extern const u16 gill_cbca_007_head[];
extern const u16 gill_cbca_008_head[];
extern const u16 gill_cbca_009_head[];
extern const u16 gill_cbca_010_head[];
extern const u16 gill_cbca_011_head[];
extern const u16 gill_cbca_012_head[];
extern const u16 gill_cbca_013_head[];
extern const u16 gill_cbca_014_head[];
extern const u16 gill_cbca_015_head[];
extern const u16 gill_cbca_016_head[];

/* normal scripts: 63 entries */
const u16* const gill_nmca[64] = {
    gill_nmca_000,  /* 0 KAMAE */
    gill_nmca_001,  /* 1 HURIMUKI */
    gill_nmca_002,  /* 2 FRONT WALK */
    gill_nmca_003,  /* 3 BACK WALK */
    gill_nmca_004,  /* 4 DASH HUMIKOMI */
    gill_nmca_005,  /* 5 DASH TOBINOKI */
    gill_nmca_006,  /* 6 KAGAMU */
    gill_nmca_007,  /* 7 KAGAMI KAMAE */
    gill_nmca_008,  /* 8 KAGAMI TURN */
    gill_nmca_008,  /* 9 KAGAMI F WALK */
    gill_nmca_008,  /* 10 KAGAMI B WALK */
    gill_nmca_011,  /* 11 STAND UP */
    gill_nmca_012,  /* 12 JUMP JUNBI */
    gill_nmca_013,  /* 13 SP JUMP JUNBI */
    gill_nmca_014,  /* 14 JUMP FRONT */
    gill_nmca_015,  /* 15 JUMP VERTICAL */
    gill_nmca_016,  /* 16 JUMP BACK */
    gill_nmca_017,  /* 17 S JUMP FRONT */
    gill_nmca_017,  /* 18 S JUMP V */
    gill_nmca_017,  /* 19 S JUMP BACK */
    gill_nmca_020,  /* 20 SP JUMP FRONT */
    gill_nmca_021,  /* 21 SP JUMP V */
    gill_nmca_022,  /* 22 SP JUMP BACK */
    gill_nmca_023,  /* 23 WALK END */
    gill_nmca_024,  /* 24 PARING HEAD */
    gill_nmca_024,  /* 25 PARING UP */
    gill_nmca_026,  /* 26 PARING DOWN */
    gill_nmca_027,  /* 27 PARING AIR F */
    gill_nmca_027,  /* 28 PARING AIR B */
    gill_nmca_029,  /* 29 GUARD HEAD */
    gill_nmca_029,  /* 30 GUARD UP */
    gill_nmca_031,  /* 31 GUARD DOWN */
    gill_nmca_032,  /* 32 GUARD AIR */
    gill_nmca_033,  /* 33 no name */
    gill_nmca_033,  /* 34 no name */
    gill_nmca_033,  /* 35 no name */
    gill_nmca_033,  /* 36 no name */
    gill_nmca_033,  /* 37 no name */
    gill_nmca_038,  /* 38 P BREAK ZUJOU */
    gill_nmca_038,  /* 39 P BREAK UP */
    gill_nmca_040,  /* 40 P BREAK DOWN */
    gill_nmca_041,  /* 41 P BREAK AIR F */
    gill_nmca_041,  /* 42 P BREAK AIR R */
    gill_nmca_043,  /* 43 TUKAMIHAZUSI */
    gill_nmca_044,  /* 44 TUKAMIHAZUSARE */
    gill_nmca_045,  /* 45 TUKAMIHAZUSI */
    gill_nmca_046,  /* 46 TUKAMIHAZUSARE */
    gill_nmca_047,  /* 47 no name */
    gill_nmca_048,  /* 48 no name */
    gill_nmca_049,  /* 49 no name */
    gill_nmca_050,  /* 50 no name */
    gill_nmca_051,  /* 51 no name */
    gill_nmca_052,  /* 52 no name */
    gill_nmca_053,  /* 53 no name */
    gill_nmca_054,  /* 54 no name */
    gill_nmca_055,  /* 55 no name */
    gill_nmca_056,  /* 56 no name */
    gill_nmca_057,  /* 57 no name */
    gill_nmca_058,  /* 58 no name */
    gill_nmca_059,  /* 59 no name */
    gill_nmca_060,  /* 60 no name */
    gill_nmca_061,  /* 61 no name */
    gill_nmca_062,  /* 62 no name */
    0
};

/* script: 51 no name */
const u16 gill_nmca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_051[132] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0320),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0321),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0322),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0323),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0324),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0325),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0326),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0327),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0328),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0329),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x032F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0330),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0331),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0332),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0333),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0334),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0335),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0336),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0337),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0338),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0339),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x033F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 gill_nmca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_052[132] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0340),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0341),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0342),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0343),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0344),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0345),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0346),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0347),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0348),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0349),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0350),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0351),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0352),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0353),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0354),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0355),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0356),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0357),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0358),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0359),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 gill_nmca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_053[104] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02FA),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 gill_nmca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_054[52] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0300),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0301),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0302),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0303),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0304),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0305),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0306),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0307),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0308),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0309),
    L2(1, 0, 0, 0, 0, 0, 0, 0x030A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x030A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 gill_nmca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_055[68] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x030C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x030D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x030E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x030F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0310),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0311),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0312),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0313),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0314),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0315),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0316),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0317),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0318),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0319),
    L2(1, 0, 0, 0, 0, 0, 0, 0x031A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x031B),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 gill_nmca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_056[68] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0360),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0361),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0362),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0363),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0364),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0365),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0366),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0367),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0368),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0369),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x036F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 gill_nmca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_057[68] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0370),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0371),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0372),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0373),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0374),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0375),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0376),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0377),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0378),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0379),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x037F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 gill_nmca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_058[72] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0380),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0381),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0382),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0383),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0384),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0388),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0389),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x038F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0390),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 gill_nmca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_059[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0391),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0392),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0393),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0394),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0395),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0396),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0397),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0398),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0399),
    L2(1, 0, 0, 0, 0, 0, 0, 0x039A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x039B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x039C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x039D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x039E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 gill_nmca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_060[64] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03A9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03AA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03AB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03AC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03AD),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03AE),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 gill_nmca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_061[64] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03BE),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 gill_nmca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_062[72] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03ED),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03ED),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 0 KAMAE */
const u16 gill_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_000[468] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0270, 0, 177, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0271, 0, 177, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0272, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 12, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 14, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0273, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0274, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0275, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0276, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0277, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0278, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0279, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x027A, 0, 179, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x027B, 0, 179, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x027C, 0, 179, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 18, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 22, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x027D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x027E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x027F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 12, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 24, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0280, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0281, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0282, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0283, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0284, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0001, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0285, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0286, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0287, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0288, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0289, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x028F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0290, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0291, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0292, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0293, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0294, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0295, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0296, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0297, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0298, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0299, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x029A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x029B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x029C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 16, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 16, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x029D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x029E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x029F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 gill_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_001[44] = {
    L4(2, 0, 0, 0, 1, 0, 0, 0x0002, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0003, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0004, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0005, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x0005, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 gill_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 gill_nmca_002[156] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x047F, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0480, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0046, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0047, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0038, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0039, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003A, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003B, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003C, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003D, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003E, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x003F, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0040, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0041, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0042, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0043, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0044, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0045, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 gill_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 gill_nmca_003[156] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0482, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0483, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004B, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004C, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004D, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004E, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004F, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0050, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0051, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0052, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0053, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0054, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0055, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0056, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0057, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0048, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0049, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x004A, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 gill_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 gill_nmca_004[124] = {
    CMD(CM_RJA, 0, 4, 6), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0010, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x001D, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x001E, 0, 192, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x001F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0020, 0, 193, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0021, 0, 193, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x000F, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0010, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 195, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 gill_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 gill_nmca_005[208] = {
    CMD(CM_RJA, 0, 5, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0007, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x0022, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0023, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0024, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0025, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0026, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0027, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0028, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x000F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0010, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0011, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0012, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0013, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 gill_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_nmca_006[60] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0007, 0, 196, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0008, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 gill_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_nmca_007[388] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0250, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0251, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0252, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0253, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0254, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0255, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0256, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0257, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0258, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 12, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 18, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0259, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0250, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0251, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0252, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0253, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 8, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 18, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0254, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0255, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0256, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0257, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x025C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x025D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x025E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x000D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0260, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0261, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0262, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0263, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0264, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0265, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x025D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x025C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 8, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 20, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0259, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0250, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0251, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0252, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0253, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x025A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 12, 8192, 16386), 0, 0, 0, 0,
    CMD(CM_EXEC, 28, 20, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x025B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0258, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0259, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 gill_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_nmca_008[60] = {
    L4(2, 0, 0, 0, 1, 0, 0, 0x0016, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0017, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0018, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0019, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x001A, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 gill_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_nmca_011[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x000E, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x000F, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0010, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 194, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0013, 0, 195, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 gill_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x0011, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0011, 0, 205, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0011, 0, 205, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 gill_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x0010, 0, 206, 0, 0, 0, 18, 2),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0010, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 gill_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_nmca_014[140] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 12, 282, 0, 0, 0, 0, 0x0029, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002A, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002B, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002C, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002D, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002E, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002F, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0030, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0031, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0032, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0033, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 gill_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 gill_nmca_015[140] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 12, 282, 0, 0, 0, 0, 0x0029, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002A, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002B, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002C, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002D, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002E, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002F, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0030, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0031, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0032, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0033, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 gill_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_nmca_016[140] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 12, 282, 0, 0, 0, 0, 0x0029, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002A, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002B, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002C, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002D, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002E, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002F, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0030, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0031, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0032, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0033, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 gill_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 gill_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 gill_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 gill_nmca_020[140] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(5, 12, 282, 0, 0, 0, 0, 0x0029, 0, 55, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x002A, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002B, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002C, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x002D, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002E, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x002F, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0030, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0031, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0032, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0033, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0034, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0035, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 gill_nmca_021_head[4] = { HEAD(2, 28, 0, 0, 0, 0, 0) };
const u16 gill_nmca_021[8] = {
    CMD(CM_JPSS, 0, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 gill_nmca_022_head[4] = { HEAD(2, 30, 0, 0, 0, 0, 0) };
const u16 gill_nmca_022[8] = {
    CMD(CM_JPSS, 0, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 gill_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 gill_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 gill_nmca_024_head[4] = { HEAD(6, 2, 0, 0, 0, 0, 0) };
const u16 gill_nmca_024[88] = {
    L6(2, 133, 0, 0, 0, 0, 0, 0x01CA, 0, 1, 0, 0, 0, 18, 6, 0, 0, 132, 0, 0),
    L6(2, 0, 870, 0, 0, 0, 0, 0x01CB, 0, 1, 0, 0, 0, 6, 0, 0, 0, 30, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x01CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x01CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x01CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x01CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x01CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 gill_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gill_nmca_026[108] = {
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(2, 134, 0, 0, 0, 0, 0, 0x0407, 0, 2, 0, 0, 0, 18, 6),
    L4(2, 0, 870, 0, 0, 0, 0, 0x0408, 0, 2, 0, 0, 0, 6, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0409, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x040A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x040B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x040C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x040D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x040E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x040F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0410, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0410, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 gill_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_nmca_027[108] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0190, 0, 122, 0, 0, 0, 18, 6),
    L4(250, 0, 870, 0, 0, 0, 0, 0x0191, 0, 122, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0193, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0194, 0, 122, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1400, 0x0000, 0x0000,
    L4(2, 133, 0, 0, 0, 0, 0, 0x0190, 0, 122, 0, 0, 0, 18, 6),
    L4(3, 0, 870, 0, 0, 0, 0, 0x0191, 0, 122, 0, 0, 0, 6, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0193, 0, 122, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0194, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0195, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0196, 0, 122, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0196, 0, 122, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD, 30 GUARD UP */
const u16 gill_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 gill_nmca_029[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0180, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x017F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x017E, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x017F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0180, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0181, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0182, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0183, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0184, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 gill_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gill_nmca_031[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0186, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0187, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0188, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0189, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x018A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 gill_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 gill_nmca_032[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x018E, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x018F, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0190, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0191, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0192, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0193, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0194, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0195, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x0196, 0, 122, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0196, 0, 122, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 gill_nmca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_033[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0270),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 gill_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_038[84] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x017F, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x017E, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0197, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 22, 24),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 gill_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_nmca_040[84] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0189, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0188, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x019D, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 22, 24),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 gill_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0190, 0, 14, 0, 0, 0, 18, 8),
    L4(250, 0, 870, 0, 0, 0, 0, 0x0191, 0, 14, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 gill_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_043[84] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x017F, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x017E, 0, 124, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0197, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 22, 24),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 gill_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_044[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01D3, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x01D4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 gill_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_nmca_045[92] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0190, 0, 14, 0, 0, 0, 0, 0),
    L4(250, 0, 870, 0, 0, 0, 0, 0x0191, 0, 14, 0, 0, 0, 25, 2),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0031, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0032, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0033, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 gill_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_nmca_046[76] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0031, 0, 57, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0032, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0033, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 gill_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0270, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 gill_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 gill_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 gill_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_nmca_050[84] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x017F, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x017E, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0197, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 22, 24),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const gill_dmca[99] = {
    gill_dmca_000,  /* 0 GUARD HEAD */
    gill_dmca_000,  /* 1 GUARD UP */
    gill_dmca_002,  /* 2 GUARD DOWN */
    gill_dmca_003,  /* 3 GUARD AIR */
    gill_dmca_004,  /* 4 HUSHIN HEAD */
    gill_dmca_004,  /* 5 HUSHIN UP */
    gill_dmca_006,  /* 6 HUSHIN DOWN */
    gill_dmca_006,  /* 7 HUSHIN AIR */
    gill_dmca_008,  /* 8 FACE S */
    gill_dmca_009,  /* 9 FACE M */
    gill_dmca_010,  /* 10 FACE L */
    gill_dmca_010,  /* 11 FACE SP */
    gill_dmca_008,  /* 12 FOOK OKU S */
    gill_dmca_009,  /* 13 FOOK OKU M */
    gill_dmca_014,  /* 14 FOOK OKU L */
    gill_dmca_015,  /* 15 FOOK OKU SP */
    gill_dmca_008,  /* 16 FOOK TEMAE S */
    gill_dmca_009,  /* 17 FOOK TEMAE M */
    gill_dmca_014,  /* 18 FOOK TEMAE L */
    gill_dmca_019,  /* 19 FOOK TEMAE SP */
    gill_dmca_008,  /* 20 UPPER S */
    gill_dmca_009,  /* 21 UPPER M */
    gill_dmca_022,  /* 22 UPPER L */
    gill_dmca_022,  /* 23 UPPER SP */
    gill_dmca_024,  /* 24 NOUTEN S */
    gill_dmca_009,  /* 25 NOUTEN M */
    gill_dmca_010,  /* 26 NOUTEN L */
    gill_dmca_010,  /* 27 NOUTEN SP */
    gill_dmca_024,  /* 28 BODY BROW S */
    gill_dmca_029,  /* 29 BODY BROW M */
    gill_dmca_030,  /* 30 BODY BROW L */
    gill_dmca_030,  /* 31 BODY BROW SP */
    gill_dmca_024,  /* 32 BODY UPPER S */
    gill_dmca_029,  /* 33 BODY UPPER M */
    gill_dmca_030,  /* 34 BODY UPPER L */
    gill_dmca_030,  /* 35 BODY UPPER SP */
    gill_dmca_036,  /* 36 TATAKI S */
    gill_dmca_037,  /* 37 TATAKI M */
    gill_dmca_038,  /* 38 TATAKI L */
    gill_dmca_039,  /* 39 TATAKI SP */
    gill_dmca_040,  /* 40 TATAKI V. S */
    gill_dmca_041,  /* 41 TATAKI V. M */
    gill_dmca_042,  /* 42 TATAKI V. L */
    gill_dmca_043,  /* 43 TATAKI V. SP */
    gill_dmca_008,  /* 44 NOBASITA TE S */
    gill_dmca_009,  /* 45 NOBASITA TE M */
    gill_dmca_010,  /* 46 NOBASITA TE L */
    gill_dmca_010,  /* 47 NOBASITA TE SP */
    gill_dmca_048,  /* 48 KAGAMI S */
    gill_dmca_049,  /* 49 KAGAMI M */
    gill_dmca_050,  /* 50 KAGAMI L */
    gill_dmca_050,  /* 51 KAGAMI SP */
    gill_dmca_052,  /* 52 KGM TATAKI S */
    gill_dmca_053,  /* 53 KGM TATAKI M */
    gill_dmca_054,  /* 54 KGM TATAKI L */
    gill_dmca_055,  /* 55 KGM TATAKI SP */
    gill_dmca_056,  /* 56 KGM TTKI V.S */
    gill_dmca_057,  /* 57 KGM TTKI V.M */
    gill_dmca_058,  /* 58 KGM TTKI V.L */
    gill_dmca_059,  /* 59 KGM TTKI V.SP */
    gill_dmca_060,  /* 60 NEKOROBI S */
    gill_dmca_060,  /* 61 NEKOROBI M */
    gill_dmca_060,  /* 62 NEKOROBI L */
    gill_dmca_060,  /* 63 NEKOROBI SP */
    gill_dmca_064,  /* 64 OKIAGARI */
    gill_dmca_065,  /* 65 OKIAGARI F */
    gill_dmca_066,  /* 66 OKIAGARI B */
    gill_dmca_067,  /* 67 LOSE NO STAND */
    gill_dmca_068,  /* 68 LOSE SONABA */
    gill_dmca_069,  /* 69 LOSE KAGAMI */
    gill_dmca_070,  /* 70 PIYO */
    gill_dmca_071,  /* 71 UKEMI MOVE F */
    gill_dmca_072,  /* 72 UKEMI MOVE R */
    gill_dmca_073,  /* 73 SHIMEOTASARE */
    gill_dmca_074,  /* 74 TATI TOUKETU S */
    gill_dmca_075,  /* 75 TATI TOUKETU M */
    gill_dmca_076,  /* 76 TATI TOUKETU L */
    gill_dmca_076,  /* 77 TATI TOUKETU P */
    gill_dmca_078,  /* 78 KGM TOUKETU S */
    gill_dmca_079,  /* 79 KGM TOUKETU M */
    gill_dmca_080,  /* 80 KGM TOUKETU L */
    gill_dmca_080,  /* 81 KGM TOUKETU P */
    gill_dmca_082,  /* 82 TATI DENGEKI S */
    gill_dmca_083,  /* 83 TATI DENGEKI M */
    gill_dmca_084,  /* 84 TATI DENGEKI L */
    gill_dmca_084,  /* 85 TATI DENGEKI P */
    gill_dmca_082,  /* 86 KGM DENGEKI S */
    gill_dmca_083,  /* 87 KGM DENGEKI M */
    gill_dmca_084,  /* 88 KGM DENGEKI L */
    gill_dmca_084,  /* 89 KGM DENGEKI P */
    gill_dmca_071,  /* 90 OKIAGARI FRONT */
    gill_dmca_072,  /* 91 OKIAGARI REAR */
    gill_dmca_008,  /* 92 TATI MOE S */
    gill_dmca_009,  /* 93 TATI MOE M */
    gill_dmca_010,  /* 94 TATI MOE L */
    gill_dmca_010,  /* 95 TATI MOE SP */
    gill_dmca_096,  /* 96 no name */
    gill_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD, 1 GUARD UP */
const u16 gill_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_000[68] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x017E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x017F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x0180, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0181, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0182, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0183, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0184, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 gill_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_002[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0189, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0188, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x0189, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x018A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x018D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 gill_dmca_003_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_003[172] = {
    L6(1, 131, 0, 0, 0, 0, 0, 0x0190, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0191, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 141, 0, 0, 0, 0, 0, 0x0192, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0193, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0194, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0195, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0196, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 138, 0, 0, 0, 0, 0, 0x017F, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0180, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0181, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0182, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 gill_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_004[68] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x017F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0197, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x019C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 gill_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_006[100] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0186, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0187, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0188, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0189, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x019D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0197, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0198, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0199, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x019A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x019B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 1, 0, 0, 0, 0, 0, 0x019C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 gill_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_008[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x015F, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 134, 866, 0, 0, 0, 0, 0x015F, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x015F, 0, 132, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0161, 0, 132, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0162, 0, 132, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 gill_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_009[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0160, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 135, 866, 0, 0, 0, 0, 0x0164, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0164, 0, 133, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0165, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0160, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0161, 0, 132, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0162, 0, 132, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 26 NOUTEN L, 27 NOUTEN SP ... */
const u16 gill_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_010[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0164, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 136, 866, 0, 0, 0, 0, 0x0168, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0169, 0, 135, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x016A, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x016B, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x016C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x00E0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00E1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00E2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 18 FOOK TEMAE L */
const u16 gill_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_014[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0168, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 136, 866, 0, 0, 0, 0, 0x0168, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0169, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x016A, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x016B, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x016C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x00E0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00E1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00E2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 gill_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_015[148] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0166, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 137, 866, 0, 0, 0, 0, 0x0166, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0168, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0169, 0, 135, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x016A, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x016B, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x016C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x00E0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00E1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00E2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 gill_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_019[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0076, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 139, 866, 0, 0, 0, 0, 0x0076, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x00D7, 0, 133, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x00D6, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 1, 0, 0, 0x01D0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 1, 0, 0, 0x01D4, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 1, 0, 0, 0x01D0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 1, 0, 0, 0x01CF, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0163, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0162, 0, 132, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 gill_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_022[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0139, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 866, 0, 0, 0, 0, 0x013A, 0, 128, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x013B, 0, 129, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0154, 0, 130, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0159, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 gill_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_024[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x016D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 0, 0, 0, 0, 0, 0x016E, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x016E, 0, 136, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x016F, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0170, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 gill_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0171, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x0172, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0172, 0, 136, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x016E, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x016F, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0170, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP, 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 gill_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_030[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0173, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 136, 866, 0, 0, 0, 0, 0x0174, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0175, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0176, 0, 137, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0177, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0178, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S */
const u16 gill_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_036[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 TATAKI M */
const u16 gill_dmca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_037[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 TATAKI L */
const u16 gill_dmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_038[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 TATAKI SP */
const u16 gill_dmca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_039[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 TATAKI V. S */
const u16 gill_dmca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_040[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 TATAKI V. M */
const u16 gill_dmca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_041[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 TATAKI V. L */
const u16 gill_dmca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_042[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TATAKI V. SP */
const u16 gill_dmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_043[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0158, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x015E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 gill_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_048[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B2, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 134, 866, 0, 0, 0, 0, 0x01B3, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x01B3, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 gill_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_049[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B4, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 136, 866, 0, 0, 0, 0, 0x01B4, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x01B4, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x01B5, 0, 141, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01B6, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01B7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 gill_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_050[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B9, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 136, 866, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 142, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x01BB, 0, 143, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BC, 0, 142, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01BD, 0, 142, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S */
const u16 gill_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_052[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 KGM TATAKI M */
const u16 gill_dmca_053_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_053[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 3, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 KGM TATAKI L */
const u16 gill_dmca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_054[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 KGM TATAKI SP */
const u16 gill_dmca_055_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_055[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 KGM TTKI V.S */
const u16 gill_dmca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_056[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 KGM TTKI V.M */
const u16 gill_dmca_057_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_057[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 KGM TTKI V.L */
const u16 gill_dmca_058_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_058[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 KGM TTKI V.SP */
const u16 gill_dmca_059_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_059[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x01B8, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x01B9, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BA, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 gill_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_060[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 866, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 gill_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_064[148] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 11, 0, 0, 0, 0, 0, 0x0498, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0499, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0135, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0136, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x0137, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000F, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0010, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0010, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 gill_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_065[116] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BE, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01BF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C3, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01BE, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01BF, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01C3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 gill_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_066[116] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x01C4, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01C5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C8, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C9, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C4, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C8, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01C9, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 gill_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x0150, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 gill_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_068[220] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x015F, 0, 215, 0, 0, 0, 32, 92, 0, 0, 194, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x015F, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 1, 0, 0, 0, 0, 0, 0x0158, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0159, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x015A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x015B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x015C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x015D, 0, 0, 0, 0, 0, 32, 94, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x015E, 0, 0, 0, 0, 0, 32, 95, 0, 0, 0, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x014A, 0, 0, 0, 0, 0, 32, 96, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x014B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x014C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x014D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x014E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x014F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 gill_dmca_069_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_069[40] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x0173, 0, 215, 0, 0, 0, 32, 92, 0, 0, 194, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x0173, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 68, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 gill_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_070[84] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0223, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0224, 0, 211, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0225, 0, 211, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0226, 0, 212, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0227, 0, 212, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0228, 0, 213, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0229, 0, 213, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x022A, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F, 90 OKIAGARI FRONT */
const u16 gill_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_071[76] = {
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C3, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01BE, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01BF, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R, 91 OKIAGARI REAR */
const u16 gill_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_072[68] = {
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C8, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C4, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x01C8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 gill_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_073[28] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x015F, 0, 215, 0, 0, 0, 32, 92),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0158, 0, 215, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 68, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 gill_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_074[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x015F, 0, 133, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x015F, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0162, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 gill_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_075[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0163, 0, 133, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x0163, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0162, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 gill_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_076[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0166, 0, 133, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x0166, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x00E0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00E1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00E2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 gill_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_078[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B2, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x01B2, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 gill_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_079[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B3, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x01B3, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x01B7, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 gill_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_dmca_080[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x01B3, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 131, 866, 0, 0, 0, 0, 0x01B3, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 1, 0, 0, 0x0016, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0017, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0018, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0019, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x001C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 gill_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_082[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 866, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 gill_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_083[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 866, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 gill_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_dmca_084[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x022B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 866, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 gill_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_096[44] = {
    L4(3, 2, 866, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 gill_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_dmca_097[44] = {
    L4(3, 2, 866, 0, 0, 0, 0, 0x0150, 0, 127, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0150, 0, 127, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0150, 0, 127, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x0150, 0, 127, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 127, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const gill_btca[37] = {
    gill_btca_000,  /* 0 AIR NORMAL */
    gill_btca_001,  /* 1 ASIBARAI SIRI */
    gill_btca_002,  /* 2 ASIB TUNNOMERI */
    gill_btca_003,  /* 3 NOKEZORI */
    gill_btca_004,  /* 4 KUNOJI */
    gill_btca_005,  /* 5 KIRIMOMI */
    gill_btca_006,  /* 6 UPPER */
    gill_btca_007,  /* 7 BODY UPPER */
    gill_btca_008,  /* 8 HARAYARARE */
    gill_btca_009,  /* 9 TATAKI AIR */
    gill_btca_010,  /* 10 TTKI V. AIR */
    gill_btca_011,  /* 11 HUMI ASIB */
    gill_btca_012,  /* 12 FACE */
    gill_btca_013,  /* 13 ASIB SIRI LOSE */
    gill_btca_014,  /* 14 ASIB TUN LOSE */
    gill_btca_015,  /* 15 DENKI */
    gill_btca_016,  /* 16 KUNOJI NOKE */
    gill_btca_017,  /* 17 BODY UPPER SP */
    gill_btca_018,  /* 18 HANEAGARI */
    gill_btca_019,  /* 19 TOUKETSU A */
    gill_btca_020,  /* 20 BODY SLAM */
    gill_btca_020,  /* 21 IPPONZEOI */
    gill_btca_022,  /* 22 TOMOE RYU */
    gill_btca_023,  /* 23 MONKEY FLIP */
    gill_btca_023,  /* 24 TOMOE ORO */
    gill_btca_025,  /* 25 SNAKE FANG */
    gill_btca_026,  /* 26 FLANKEN.S */
    gill_btca_027,  /* 27 KISHINRIKI */
    gill_btca_028,  /* 28 SPLASH.M */
    gill_btca_029,  /* 29 HARAIGOSHI */
    gill_btca_030,  /* 30 ALEX B.D */
    gill_btca_031,  /* 31 GILL */
    gill_btca_032,  /* 32 HANEKAERI HARA */
    gill_btca_033,  /* 33 S HANEAGARI */
    gill_btca_034,  /* 34 TATUMAKIZANKU */
    gill_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 gill_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_000[68] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0154, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 866, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x0154, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 gill_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_001[76] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0173, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 12, 0x0174, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x0175, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x0176, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x0179, 0, 157, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x017A, 0, 158, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x017A, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 gill_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_btca_002[68] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0154, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0155, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x0156, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0157, 0, 161, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0149, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 gill_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_003[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 gill_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_004[92] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0173, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 12, 0x0174, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x0175, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x0176, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x0179, 0, 157, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x017A, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 gill_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_005[132] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 gill_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_006[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 gill_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_007[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 gill_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_008[92] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0173, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0174, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0175, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0176, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0179, 0, 157, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x017A, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 gill_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_009[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 10, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 867, 0, 0, 0, 14, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 gill_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_010[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x0179, 0, 157, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 gill_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 gill_btca_011[68] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0154, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0155, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x0156, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0157, 0, 161, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0149, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 gill_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_012[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 gill_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 gill_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 gill_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 gill_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_015[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 135, 0, 0, 0, 0, 0, 0x022B, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022C, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x022B, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x022D, 0, 172, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 gill_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_016[12] = {
    CMD(CM_JMP, 6, 5, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 gill_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_017[148] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 867, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 gill_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_018[132] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 867, 0, 0, 0, 0, 0x0147, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0148, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0157, 0, 82, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x0142, 0, 82, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 13, 0x0140, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x013F, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 gill_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0166, 0, 175, 0, 0, 0, 0, 0),
    L4(250, 0, 867, 0, 0, 0, 0, 0x0166, 0, 175, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM, 21 IPPONZEOI */
const u16 gill_btca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_btca_020[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x014C, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 gill_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_022[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 6, 0x0156, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0157, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP, 24 TOMOE ORO */
const u16 gill_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_023[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0156, 0, 124, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0157, 0, 124, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x02D1, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 gill_btca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_btca_025[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 gill_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_026[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x0156, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x0157, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 gill_btca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_btca_027[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x02D1, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 gill_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_028[28] = {
    CMD(CM_RJA, 7, 6, 2), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0143, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 gill_btca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_btca_029[28] = {
    L4(2, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x02D1, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 gill_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_030[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0151, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0152, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0153, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x013E, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x02D1, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 gill_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_031[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x013C, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 931, 0, 0, 0, 0, 0x013D, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0142, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 gill_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_032[36] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x0173, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0174, 0, 156, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 gill_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_033[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 867, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 gill_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_btca_034[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 867, 0, 0, 0, 0, 0x0138, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0139, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013A, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013B, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 170, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0142, 0, 171, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 3 entries */
const u16* const gill_caca[4] = {
    gill_caca_000,  /* 0 CATCH 1 */
    gill_caca_001,  /* 1 CATCH 2 */
    gill_caca_002,  /* 2 CATCH 3 */
    0
};

/* script: 0 CATCH 1 */
const u16 gill_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 gill_caca_000[292] = {
    CMD(CM_NGDA, 1542, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 3, 0, 0x01D2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 4, 0, 0x01D3, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 870, 0, 0, 5, 0, 0x01D4, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 6, 0, 0x01D5, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 7, 0, 0x01D6, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 8, 0, 0x01D7, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 9, 0, 0x01D8, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 10, 0, 0x01D9, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 11, 0, 0x01DA, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 12, 0, 0x01DB, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 13, 0, 0x01DC, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 14, 0, 0x01DD, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 15, 0, 0x01DE, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(4, 0, 871, 0, 0, 16, 0, 0x01DF, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(4, 2, 0, 0, 0, 17, 0, 0x01E0, -22, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 18, 0, 0x01E1, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 19, 0, 0x01E2, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(6, 9, 0, 0, 0, 20, 0, 0x01E3, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x01E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 22, 0, 0x01E5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 23, 0, 0x01E6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 24, 0, 0x01E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 gill_caca_001_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 gill_caca_001[316] = {
    CMD(CM_NGDA, 1542, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 2, 1, 23), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 3, 0, 0x01D2, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 4, 0, 0x01D3, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 870, 0, 0, 5, 0, 0x01D4, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 6, 0, 0x01D5, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 7, 0, 0x01D6, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x00A2, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x021A, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 2, 1, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x021B, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(1, 0, 869, 0, 0, 0, 0, 0x021B, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x0221, -23, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0220, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    CMD(CM_RAPP2, 2, 1, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x021F, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x021E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x021D, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    CMD(CM_IFLG, 1, 128, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 9, 0, 0, 0, 0, 0, 0x021C, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 gill_caca_002_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 gill_caca_002[72] = {
    CMD(CM_NGDA, 1542, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 3, 0, 0x01D2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 4, 0, 0x01D3, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 870, 0, 0, 5, 0, 0x01D4, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 6, 0, 0x01D5, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
};

/* caught scripts: 68 entries */
const u16* const gill_cuca[69] = {
    gill_cuca_000,  /* 0 ALEX ZUTUKI */
    gill_cuca_001,  /* 1 ALEX BODY S */
    gill_cuca_002,  /* 2 ALEX BACK D */
    gill_cuca_003,  /* 3 ALEX POWER B */
    gill_cuca_004,  /* 4 ALEX SLEEPER */
    gill_cuca_005,  /* 5 RYU SEOINAGE */
    gill_cuca_006,  /* 6 IBUKI */
    gill_cuca_007,  /* 7 DADLEY L B */
    gill_cuca_008,  /* 8 IBUKI KUBIORI */
    gill_cuca_009,  /* 9 NECRO S T */
    gill_cuca_010,  /* 10 RYU TOMOENAGE */
    gill_cuca_011,  /* 11 YUN HIZAGERI */
    gill_cuca_012,  /* 12 ORO KUBISIME */
    gill_cuca_013,  /* 13 NECRO G S */
    gill_cuca_014,  /* 14 DUDDLEY D S */
    gill_cuca_015,  /* 15 YUN MONKEY F */
    gill_cuca_016,  /* 16 ORO TOMOENAGE */
    gill_cuca_017,  /* 17 ORO NIOURIKI */
    gill_cuca_018,  /* 18 ORO GIGOKU G */
    gill_cuca_019,  /* 19 YUN */
    gill_cuca_020,  /* 20 NECRO SNAKE F */
    gill_cuca_021,  /* 21 NECRO F S */
    gill_cuca_022,  /* 22 IBUKI HARAIG */
    gill_cuca_023,  /* 23 GILL SPLASH M */
    gill_cuca_024,  /* 24 KEN HIZAGERI */
    gill_cuca_025,  /* 25 ORO KISINRIKI */
    gill_cuca_026,  /* 26 SEAN TACKLE */
    gill_cuca_027,  /* 27 ALEX HYPER B */
    gill_cuca_028,  /* 28 NECRO SLAM D */
    gill_cuca_029,  /* 29 ELENA ASINAGE */
    gill_cuca_030,  /* 30 GILL IMPACT C */
    gill_cuca_031,  /* 31 ALEX S H B */
    gill_cuca_032,  /* 32 ALEX F N D */
    gill_cuca_033,  /* 33 no name */
    gill_cuca_034,  /* 34 IBUKI */
    gill_cuca_035,  /* 35 IBUKI YOROI D */
    gill_cuca_036,  /* 36 no name */
    gill_cuca_037,  /* 37 MAWARIKOMI M F */
    gill_cuca_038,  /* 38 HUGO BODY S */
    gill_cuca_039,  /* 39 HUGO N G T */
    gill_cuca_040,  /* 40 HUGO M S P */
    gill_cuca_041,  /* 41 HUGO S D B B */
    gill_cuca_042,  /* 42 no name */
    gill_cuca_043,  /* 43 no name */
    gill_cuca_044,  /* 44 no name */
    gill_cuca_045,  /* 45 no name */
    gill_cuca_046,  /* 46 no name */
    gill_cuca_047,  /* 47 no name */
    gill_cuca_048,  /* 48 no name */
    gill_cuca_049,  /* 49 no name */
    gill_cuca_050,  /* 50 no name */
    gill_cuca_051,  /* 51 no name */
    gill_cuca_052,  /* 52 no name */
    gill_cuca_053,  /* 53 no name */
    gill_cuca_054,  /* 54 no name */
    gill_cuca_055,  /* 55 no name */
    gill_cuca_056,  /* 56 no name */
    gill_cuca_057,  /* 57 no name */
    gill_cuca_058,  /* 58 no name */
    gill_cuca_059,  /* 59 no name */
    gill_cuca_060,  /* 60 no name */
    gill_cuca_061,  /* 61 no name */
    gill_cuca_062,  /* 62 no name */
    gill_cuca_063,  /* 63 no name */
    gill_cuca_064,  /* 64 no name */
    gill_cuca_065,  /* 65 no name */
    gill_cuca_066,  /* 66 no name */
    gill_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 gill_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015A),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x015B),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 gill_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0139),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014C),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 gill_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0144),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 gill_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0146),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 gill_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 1, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0158),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0025),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0026),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0025),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0158),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 gill_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 1, 0, 0, 0x016C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x014A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 gill_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0094),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0095),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0096),
    L2(250, 0, 0, 0, 0, 0, 0, 0x007E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0058),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005B),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0173),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 gill_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_007[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    CMD(CM_RMJA, 3, 7, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x00E1),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 gill_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0288),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 gill_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0174),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 gill_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0131),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 gill_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_011[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0151),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 gill_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x027E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x027F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0280),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0154),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 gill_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01D5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0145),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0146),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 gill_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0174),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 gill_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x017A),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 gill_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_016[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0076),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 gill_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_017[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0135),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0135),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0146),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 gill_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 3, 0, 0, 0, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014E),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 gill_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_019[100] = {
    L2(250, 2, 0, 0, 0, 0, 0, 0x0288),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0289),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x016A),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 gill_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_020[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0174),
    L2(250, 0, 0, 0, 1, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 gill_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 gill_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0142),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 21, 1),
    CMD(CM_JMP, 6, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 gill_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0141),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0142),
    L2(250, 3, 0, 0, 0, 0, 0, 0x0143),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0144),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 gill_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0131),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0021),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0130),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0174),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0175),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0175),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 gill_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0135),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0135),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0147),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013D),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 gill_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    L2(250, 3, 0, 0, 0, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 3, 0, 0, 0, 0, 0, 0x014E),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0150),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 gill_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_027[152] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0147),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 gill_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01D5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0142),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013D),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 gill_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0175),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0176),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 gill_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0076),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00D6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x013B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 gill_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0151),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 gill_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0175),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0174),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014B),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 gill_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0144),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 gill_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013C),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 7, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 gill_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0094),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0095),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0096),
    L2(250, 0, 0, 0, 0, 0, 0, 0x007E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0058),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x005B),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0173),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 gill_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 2, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0147),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0148),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0149),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 2, 0, 0, 0, 0, 0, 0x01B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014F),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014E),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 gill_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_037[132] = {
    L2(250, 2, 0, 0, 0, 0, 0, 0x0288),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0289),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0214),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0213),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0212),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0211),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x017A),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 gill_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0119),
    L2(250, 0, 0, 0, 2, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x013D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0148),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014A),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 gill_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_039[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0175),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 gill_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0165),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0218),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0108),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0106),
    L2(250, 0, 0, 0, 0, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0150),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0175),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 gill_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0140),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 gill_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0176),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 gill_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0150),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0150),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 gill_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0165),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0218),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0108),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0106),
    L2(250, 0, 0, 0, 0, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0175),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 gill_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0154),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 gill_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x01AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0218),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0108),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0106),
    L2(250, 0, 0, 0, 0, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0106),
    L2(250, 0, 0, 0, 3, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 gill_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x00C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0153),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0144),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0144),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 gill_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016C),
    L2(250, 2, 0, 0, 0, 0, 0, 0x015A),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x015B),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 gill_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0159),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 2, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0145),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0146),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 gill_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0010),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x02D5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x02D1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0148),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0146),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0147),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0149),
    L2(250, 0, 0, 0, 3, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x013D),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0155),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 gill_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0159),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0159),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0158),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 2, 0, 0, 0, 0, 0, 0x016E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0159),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0158),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0173),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 gill_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0131),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0149),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x011D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 gill_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 3, 0, 0, 0x01B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0143),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0143),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 gill_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0152),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0139),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 gill_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0151),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x00E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 gill_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0178),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0177),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 gill_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0176),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 gill_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0177),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x017A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0138),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 gill_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0026),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0025),
    L2(250, 0, 0, 0, 1, 0, 0, 0x00D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0158),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0159),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 gill_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0161),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 gill_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x002D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x002C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x002B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x002A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0154),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0138),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0176),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0179),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 gill_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0076),
    CMD(CM_PA_X, 0, -3584, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00D7),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00D6),
    CMD(CM_PA_X, 0, -5888, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01D0),
    CMD(CM_PA_X, 0, 768, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01D4),
    CMD(CM_PA_X, 0, -2304, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0173),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0173),
    CMD(CM_PA_X, 0, 6144, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0138),
    CMD(CM_PA_X, 0, -5632, 0),
    CMD(CM_PS_Y, 0, 0, 16),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    CMD(CM_PA_X, 0, -768, 0),
    CMD(CM_PS_Y, 0, 0, 6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0155),
    CMD(CM_PA_X, 0, -8192, 0),
    CMD(CM_PS_Y, 0, 0, -11),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0156),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0157),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0143),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0144),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 gill_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0173),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 867, 0, 0, 0, 0, 0x0174),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 gill_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0010),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0158),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0008),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0159),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0138),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 gill_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0168),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x00D6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x01D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x01D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0155),
    L2(250, 0, 0, 0, 3, 0, 0, 0x017A),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0156),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 gill_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0139),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x014C),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x014C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 gill_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x016F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x015F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0164),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x013D),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x013F),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 157 entries */
const u16* const gill_atca[158] = {
    gill_atca_000,  /* 0 S PUNCH A */
    gill_atca_000,  /* 1 S PUNCH B */
    gill_atca_000,  /* 2 S PUNCH C */
    gill_atca_003,  /* 3 M PUNCH A */
    gill_atca_003,  /* 4 M PUNCH B */
    gill_atca_005,  /* 5 M PUNCH C */
    gill_atca_006,  /* 6 L PUNCH A */
    gill_atca_006,  /* 7 L PUNCH B */
    gill_atca_006,  /* 8 L PUNCH C */
    gill_atca_009,  /* 9 S KICK A */
    gill_atca_009,  /* 10 S KICK B */
    gill_atca_009,  /* 11 S KICK C */
    gill_atca_012,  /* 12 M KICK A */
    gill_atca_012,  /* 13 M KICK B */
    gill_atca_014,  /* 14 M KICK C */
    gill_atca_015,  /* 15 L KICK A */
    gill_atca_015,  /* 16 L KICK B */
    gill_atca_015,  /* 17 L KICK C */
    gill_atca_018,  /* 18 KAGAMI P A */
    gill_atca_018,  /* 19 KAGAMI P B */
    gill_atca_018,  /* 20 KAGAMI P C */
    gill_atca_021,  /* 21 KAGAMI P A */
    gill_atca_021,  /* 22 KAGAMI P B */
    gill_atca_021,  /* 23 KAGAMI P C */
    gill_atca_024,  /* 24 KAGAMI P A */
    gill_atca_024,  /* 25 KAGAMI P B */
    gill_atca_024,  /* 26 KAGAMI P C */
    gill_atca_027,  /* 27 KAGAMI K A */
    gill_atca_027,  /* 28 KAGAMI K B */
    gill_atca_027,  /* 29 KAGAMI K C */
    gill_atca_030,  /* 30 KAGAMI K A */
    gill_atca_030,  /* 31 KAGAMI K B */
    gill_atca_030,  /* 32 KAGAMI K C */
    gill_atca_033,  /* 33 KAGAMI K A */
    gill_atca_033,  /* 34 KAGAMI K B */
    gill_atca_033,  /* 35 KAGAMI K C */
    gill_atca_036,  /* 36 V JUMP P S A */
    gill_atca_036,  /* 37 V JUMP P S B */
    gill_atca_038,  /* 38 V JUMP P M A */
    gill_atca_038,  /* 39 V JUMP P M B */
    gill_atca_040,  /* 40 V JUMP P L A */
    gill_atca_040,  /* 41 V JUMP P L B */
    gill_atca_042,  /* 42 V JUMP K S A */
    gill_atca_042,  /* 43 V JUMP K S B */
    gill_atca_044,  /* 44 V JUMP K M A */
    gill_atca_044,  /* 45 V JUMP K M B */
    gill_atca_046,  /* 46 V JUMP K L A */
    gill_atca_046,  /* 47 V JUMP K L B */
    gill_atca_048,  /* 48 F JUMP P S A */
    gill_atca_048,  /* 49 F JUMP P S B */
    gill_atca_050,  /* 50 F JUMP P M A */
    gill_atca_050,  /* 51 F JUMP P M B */
    gill_atca_052,  /* 52 F JUMP P L A */
    gill_atca_052,  /* 53 F JUMP P L B */
    gill_atca_054,  /* 54 F JUMP K S A */
    gill_atca_054,  /* 55 F JUMP K S B */
    gill_atca_056,  /* 56 F JUMP K M A */
    gill_atca_056,  /* 57 F JUMP K M B */
    gill_atca_058,  /* 58 F JUMP K L A */
    gill_atca_058,  /* 59 F JUMP K L B */
    gill_atca_060,  /* 60 B JUMP P S A */
    gill_atca_060,  /* 61 B JUMP P S B */
    gill_atca_062,  /* 62 B JUMP P M A */
    gill_atca_062,  /* 63 B JUMP P M B */
    gill_atca_064,  /* 64 B JUMP P L A */
    gill_atca_064,  /* 65 B JUMP P L B */
    gill_atca_066,  /* 66 B JUMP K S A */
    gill_atca_066,  /* 67 B JUMP K S B */
    gill_atca_068,  /* 68 B JUMP K M A */
    gill_atca_068,  /* 69 B JUMP K M B */
    gill_atca_070,  /* 70 B JUMP K L A */
    gill_atca_070,  /* 71 B JUMP K L B */
    gill_atca_072,  /* 72 SP V JP S P A */
    gill_atca_072,  /* 73 SP V JP S P B */
    gill_atca_074,  /* 74 SP V JP M P A */
    gill_atca_074,  /* 75 SP V JP M P B */
    gill_atca_076,  /* 76 SP V JP L P A */
    gill_atca_076,  /* 77 SP V JP L P B */
    gill_atca_078,  /* 78 SP V JP S K A */
    gill_atca_078,  /* 79 SP V JP S K B */
    gill_atca_080,  /* 80 SP V JP M K A */
    gill_atca_080,  /* 81 SP V JP M K B */
    gill_atca_082,  /* 82 SP V JP L K A */
    gill_atca_082,  /* 83 SP V JP L K B */
    gill_atca_084,  /* 84 SP F JP S P A */
    gill_atca_084,  /* 85 SP F JP S P B */
    gill_atca_086,  /* 86 SP F JP M P A */
    gill_atca_086,  /* 87 SP F JP M P B */
    gill_atca_088,  /* 88 SP F JP L P A */
    gill_atca_088,  /* 89 SP F JP L P B */
    gill_atca_090,  /* 90 SP F JP S K A */
    gill_atca_090,  /* 91 SP F JP S K B */
    gill_atca_092,  /* 92 SP F JP M K A */
    gill_atca_092,  /* 93 SP F JP M K B */
    gill_atca_094,  /* 94 SP F JP L K A */
    gill_atca_094,  /* 95 SP F JP L K B */
    gill_atca_096,  /* 96 SP B JP S P A */
    gill_atca_096,  /* 97 SP B JP S P B */
    gill_atca_098,  /* 98 SP B JP M P A */
    gill_atca_098,  /* 99 SP B JP M P B */
    gill_atca_100,  /* 100 SP B JP L P A */
    gill_atca_100,  /* 101 SP B JP L P B */
    gill_atca_102,  /* 102 SP B JP S K A */
    gill_atca_102,  /* 103 SP B JP S K B */
    gill_atca_104,  /* 104 SP B JP M K A */
    gill_atca_104,  /* 105 SP B JP M K B */
    gill_atca_106,  /* 106 SP B JP L K A */
    gill_atca_106,  /* 107 SP B JP L K B */
    gill_atca_108,  /* 108 S V JP S P A */
    gill_atca_108,  /* 109 S V JP S P B */
    gill_atca_110,  /* 110 S V JP M P A */
    gill_atca_110,  /* 111 S V JP M P B */
    gill_atca_112,  /* 112 S V JP L P A */
    gill_atca_112,  /* 113 S V JP L P B */
    gill_atca_114,  /* 114 S V JP S K A */
    gill_atca_114,  /* 115 S V JP S K B */
    gill_atca_116,  /* 116 S V JP M K A */
    gill_atca_116,  /* 117 S V JP M K B */
    gill_atca_118,  /* 118 S V JP L K A */
    gill_atca_118,  /* 119 S V JP L K B */
    gill_atca_108,  /* 120 S F JP S P A */
    gill_atca_108,  /* 121 S F JP S P B */
    gill_atca_110,  /* 122 S F JP M P A */
    gill_atca_110,  /* 123 S F JP M P B */
    gill_atca_112,  /* 124 S F JP L P A */
    gill_atca_112,  /* 125 S F JP L P B */
    gill_atca_114,  /* 126 S F JP S K A */
    gill_atca_114,  /* 127 S F JP S K B */
    gill_atca_116,  /* 128 S F JP M K A */
    gill_atca_116,  /* 129 S F JP M K B */
    gill_atca_118,  /* 130 S F JP L K A */
    gill_atca_118,  /* 131 S F JP L K B */
    gill_atca_108,  /* 132 S B JP S P A */
    gill_atca_108,  /* 133 S B JP S P B */
    gill_atca_110,  /* 134 S B JP M P A */
    gill_atca_110,  /* 135 S B JP M P B */
    gill_atca_112,  /* 136 S B JP L P A */
    gill_atca_112,  /* 137 S B JP L P B */
    gill_atca_114,  /* 138 S B JP S K A */
    gill_atca_114,  /* 139 S B JP S K B */
    gill_atca_116,  /* 140 S B JP M K A */
    gill_atca_116,  /* 141 S B JP M K B */
    gill_atca_118,  /* 142 S B JP L K A */
    gill_atca_118,  /* 143 S B JP L K B */
    gill_atca_144,  /* 144 TUKAMIKAKARI A */
    gill_atca_145,  /* 145 TUKAMIKAKARI B */
    gill_atca_146,  /* 146 TUKAMIKAKARI C */
    gill_atca_144,  /* 147 TUKAMIKAKARI D */
    gill_atca_144,  /* 148 TUKAMIKAKARI E */
    gill_atca_144,  /* 149 TUKAMIKAKARI F */
    gill_atca_144,  /* 150 TUKAMI AIR A */
    gill_atca_144,  /* 151 TUKAMI AIR B */
    gill_atca_144,  /* 152 TUKAMI AIR C */
    gill_atca_144,  /* 153 TUKAMI AIR D */
    gill_atca_144,  /* 154 TUKAMI AIR E */
    gill_atca_144,  /* 155 TUKAMI AIR F */
    gill_atca_156,  /* 156 no name */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B, 2 S PUNCH C */
const u16 gill_atca_000_head[4] = { HEAD(4, 0, 0, 12, 0, 4, 0) };
const u16 gill_atca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0058, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0059, -1, 11, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x005A, 1, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x005B, 0, 12, 0, 0, 4, 21, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x005C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x005D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x005E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x005F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0060, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0061, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0062, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0062, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 gill_atca_003_head[4] = { HEAD(6, 0, 2, 13, 0, 5, 0) };
const u16 gill_atca_003[232] = {
    CMD(CM_RJA7, 4, 3, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0063, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x0064, 0, 106, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0065, -3, 107, 0, 128, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0066, 3, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0067, 0, 106, 0, 0, 0, 21, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0068, 0, 106, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0069, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x006A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x006B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x006C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x006D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x006E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x006F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0070, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0071, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0072, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0073, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0073, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 gill_atca_005_head[4] = { HEAD(6, 0, 2, 7, 0, 9, 0) };
const u16 gill_atca_005[244] = {
    CMD(CM_RJA7, 4, 5, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x008B, 0, 13, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x008C, 0, 13, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x008D, 0, 13, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x008E, -2, 14, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x008F, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0090, 0, 16, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0091, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0092, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0093, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0094, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0095, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0096, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0097, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0098, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0099, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x009A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x009B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x009C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x009C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B, 8 L PUNCH C */
const u16 gill_atca_006_head[4] = { HEAD(6, 0, 4, 13, 0, 10, 0) };
const u16 gill_atca_006[292] = {
    CMD(CM_RJA7, 4, 6, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0075, 0, 109, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0076, 0, 109, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0077, 0, 109, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 47, 0, 0x0078, 0, 109, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 270, 0, 0, 48, 0, 0x0079, 0, 109, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 870, 0, 0, 49, 0, 0x007A, 0, 110, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 50, 0, 0x007B, -5, 111, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 51, 0, 0x007C, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 52, 0, 0x007D, 0, 113, 0, 0, 0, 21, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x007E, 0, 13, 0, 0, 0, 28, 0, 0, 0, 56, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x007F, 0, 13, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0080, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0081, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0082, 0, 1, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0083, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0084, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0085, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0086, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0087, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0088, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0089, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x008A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x008A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 gill_atca_009_head[4] = { HEAD(4, 0, 1, 10, 0, 4, 0) };
const u16 gill_atca_009[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x009D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x009E, 0, 17, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x009F, -6, 18, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00A0, 0, 17, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00A1, 0, 17, 0, 0, 16, 0, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00A2, 0, 1, 0, 0, 20, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 gill_atca_012_head[4] = { HEAD(6, 0, 3, 16, 0, 7, 0) };
const u16 gill_atca_012[172] = {
    CMD(CM_RJA7, 4, 12, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x009D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x00A6, 0, 19, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00A7, -8, 20, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00A8, 8, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00AC, 8, 22, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00AD, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00A2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x00A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x00A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 gill_atca_014_head[4] = { HEAD(6, 0, 3, 16, 0, 7, 0) };
const u16 gill_atca_014[172] = {
    CMD(CM_RJA7, 4, 14, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0414, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0415, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0416, 0, 19, 0, 0, 0, 30, 49, 0, 0, 0, 0, 0),
    L6(3, 1, 269, 0, 0, 0, 0, 0x0417, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0418, -8, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0419, 8, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x041A, 0, 22, 0, 0, 0, 21, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x041B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x041C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x041D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x00F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 gill_atca_015_head[4] = { HEAD(6, 0, 5, 15, 0, 10, 0) };
const u16 gill_atca_015[528] = {
    CMD(CM_RJA7, 4, 15, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x00E3, 0, 23, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x00E4, 0, 23, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00E5, 0, 24, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00E6, 0, 24, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(3, 0, 0, 0, 0, 57, 0, 0x00E7, 0, 24, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(3, 0, 0, 0, 0, 58, 0, 0x00E8, 0, 24, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 270, 0, 0, 59, 0, 0x00E9, 0, 24, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(3, 0, 868, 0, 0, 59, 0, 0x00E9, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 60, 0, 0x00EA, -9, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 61, 0, 0x00EB, -10, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 62, 0, 0x00EC, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 63, 0, 0x00ED, 0, 28, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00EE, 0, 28, 0, 0, 0, 28, 2, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00EF, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F1, 0, 28, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x00F4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x00F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0005, 0x1100, 0x0800, 0x001C, 0x0004, 0x0011, 0x0004,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x00D6,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x00D7,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0086, 0x0000, 0x0200, 0x0000, 0x0000, 0x00D8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x10E0, 0x0430, 0x00D9,
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x0088, 0x0000, 0x0200, 0x0000, 0x0440, 0x00DA,
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x008A, 0x0000, 0x0200, 0x0000, 0x0450, 0x00DB,
    L6(253, 73, 0, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 140, 0, 0, 512, 0, 1120, 0, 220),
    L6(2, 196, 1536, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 138, 0, 0, 512, 0, 1136, 1, 174),
    CMD(CM_IF_L, -32768, 0, 0), 0x0000, 0x0000, 0x008A, 0x0000, 0x0200, 0x0000, 0x0000, 0x01AF,
    CMD(CM_IF_L, -32768, 0, 7172), 0x0000, 0x0000, 0x008A, 0x0000, 0x0300, 0x0000, 0x0000, 0x00DF,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0086, 0x0000, 0x0300, 0x0000, 0x0000, 0x00E0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x008E, 0x0000, 0x0300, 0x0000, 0x0000, 0x00E1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x00E2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0010,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0340, 0x0000, 0x0000, 0x0011,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0012,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0013,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0014,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x0015,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x0015,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 gill_atca_018_head[4] = { HEAD(4, 32, 0, 12, 0, 5, 0) };
const u16 gill_atca_018[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x00AF, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x00B0, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x00B3, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x00B1, -12, 29, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00B2, 0, 30, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00B3, 0, 2, 0, 0, 16, 0, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00B4, 0, 2, 0, 0, 16, 0, 4),
    L4(3, 64, 0, 0, 0, 0, 0, 0x00B5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00B6, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00B7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00B8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00B9, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00BA, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00BB, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00BB, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 gill_atca_021_head[4] = { HEAD(4, 32, 2, 12, 0, 5, 0) };
const u16 gill_atca_021[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0402, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x03EF, 0, 2, 0, 0, 0, 32, 104),
    L4(1, 0, 0, 0, 0, 0, 0, 0x03EF, 0, 2, 0, 0, 0, 32, 105),
    L4(1, 0, 0, 0, 0, 0, 0, 0x03EF, 0, 2, 0, 0, 0, 32, 106),
    L4(2, 0, 0, 0, 0, 0, 0, 0x03F0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x03F1, -13, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x03F2, 0, 29, 0, 0, 0, 32, 109),
    L4(6, 0, 0, 0, 0, 0, 0, 0x03F3, 0, 30, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x03F4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x03F5, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00D3, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00D4, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 gill_atca_024_head[4] = { HEAD(6, 32, 4, 8, 0, 7, 0) };
const u16 gill_atca_024[196] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x00BC, 0, 2, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 76, 0, 0x00BD, 0, 38, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 869, 0, 0, 77, 0, 0x00BE, -28, 39, 0, 0, 96, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 270, 0, 0, 78, 0, 0x00BF, -14, 40, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x00C0, 0, 40, 0, 0, 0, 28, 6, 0, 0, 160, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x00C1, 0, 31, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x00C2, 0, 31, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C3, 0, 38, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x00C5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C6, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C7, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00C9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00CA, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x00CA, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 gill_atca_027_head[4] = { HEAD(4, 32, 1, 15, 0, 5, 0) };
const u16 gill_atca_027[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x00D1, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x00D1, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00CF, -15, 32, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00D0, 0, 41, 0, 0, 16, 21, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x00D1, 0, 2, 0, 0, 20, 0, 2),
    L4(3, 64, 0, 0, 0, 0, 0, 0x00D2, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00D3, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00D4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 gill_atca_030_head[4] = { HEAD(4, 32, 3, 15, 0, 5, 0) };
const u16 gill_atca_030[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x03FB, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x03FC, -16, 32, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x03FD, 0, 41, 0, 128, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x03FE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x03FF, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0400, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0401, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0402, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0403, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0404, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0404, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 gill_atca_033_head[4] = { HEAD(6, 32, 5, 15, 0, 5, 0) };
const u16 gill_atca_033[172] = {
    L6(4, 0, 0, 0, 0, 84, 0, 0x00CB, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 85, 0, 0x00CC, 0, 2, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 868, 0, 0, 85, 0, 0x00CC, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 86, 0, 0x00CD, -17, 42, 0, 64, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 87, 0, 0x00CE, 0, 42, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 88, 0, 0x00CF, 0, 43, 0, 0, 0, 21, 0, 0, 0, 176, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00D0, 0, 41, 0, 0, 0, 28, 8, 0, 0, 178, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00D1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00D2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x00D3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00D4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x000E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x000E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 gill_atca_036_head[4] = { HEAD(4, 22, 0, 15, 0, 6, 0) };
const u16 gill_atca_036[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x00F6, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x00F7, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 5, 0x00F8, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00F9, -18, 61, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00FA, 0, 61, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00FB, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00FC, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00FD, 0, 61, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 gill_atca_038_head[4] = { HEAD(4, 22, 2, 15, 0, 6, 0) };
const u16 gill_atca_038[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x010A, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x010B, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x010C, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x010D, -19, 49, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x010E, 0, 47, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x010F, 0, 50, 0, 137, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0110, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0111, 0, 48, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0112, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 gill_atca_040_head[4] = { HEAD(4, 22, 4, 15, 0, 6, 0) };
const u16 gill_atca_040[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x00FE, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 93, 0, 0x00FF, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 94, 0, 0x0100, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 95, 0, 0x0101, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 96, 0, 0x0102, -20, 44, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 97, 0, 0x0103, 0, 46, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0104, 0, 45, 0, 0, 0, 28, 10),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0105, 0, 45, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0111, 0, 48, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0112, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 gill_atca_042_head[4] = { HEAD(4, 22, 1, 9, 0, 6, 0) };
const u16 gill_atca_042[76] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x019E, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 6, 0x019F, 0, 51, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x01A0, -29, 52, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x01A1, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x01A2, 0, 51, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01A3, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 gill_atca_044_head[4] = { HEAD(4, 22, 3, 18, 0, 6, 0) };
const u16 gill_atca_044[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x019E, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x019F, 0, 51, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 5, 0x01A4, -30, 53, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x01A5, 0, 54, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x01A6, 0, 51, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x01A2, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x01A3, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 gill_atca_046_head[4] = { HEAD(4, 22, 5, 17, 0, 8, 0) };
const u16 gill_atca_046[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 11, 0, 0, 0, 0, 5, 0x01A7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x01A8, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 99, 5, 0x01A9, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 100, 5, 0x01AA, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 101, 5, 0x01AB, -31, 116, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 102, 5, 0x01AC, 0, 117, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 103, 5, 0x00DD, 0, 118, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x00DE, 0, 119, 0, 0, 0, 28, 12),
    L4(3, 0, 0, 0, 0, 0, 5, 0x01AD, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 gill_atca_048_head[4] = { HEAD(2, 20, 0, 9, 0, 11, 0) };
const u16 gill_atca_048[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 gill_atca_050_head[4] = { HEAD(2, 20, 2, 12, 0, 7, 0) };
const u16 gill_atca_050[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 gill_atca_052_head[4] = { HEAD(2, 20, 4, 12, 0, 7, 0) };
const u16 gill_atca_052[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 gill_atca_054_head[4] = { HEAD(2, 20, 1, 9, 0, 6, 0) };
const u16 gill_atca_054[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 gill_atca_056_head[4] = { HEAD(2, 20, 3, 18, 0, 6, 0) };
const u16 gill_atca_056[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 gill_atca_058_head[4] = { HEAD(2, 20, 5, 17, 0, 8, 0) };
const u16 gill_atca_058[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 gill_atca_060_head[4] = { HEAD(2, 24, 0, 9, 0, 11, 0) };
const u16 gill_atca_060[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 gill_atca_062_head[4] = { HEAD(2, 24, 2, 12, 0, 7, 0) };
const u16 gill_atca_062[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 gill_atca_064_head[4] = { HEAD(2, 24, 4, 12, 0, 7, 0) };
const u16 gill_atca_064[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 gill_atca_066_head[4] = { HEAD(2, 24, 1, 9, 0, 6, 0) };
const u16 gill_atca_066[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 gill_atca_068_head[4] = { HEAD(2, 24, 3, 18, 0, 6, 0) };
const u16 gill_atca_068[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 gill_atca_070_head[4] = { HEAD(2, 24, 5, 17, 0, 8, 0) };
const u16 gill_atca_070[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 gill_atca_072_head[4] = { HEAD(2, 28, 0, 15, 0, 6, 0) };
const u16 gill_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 gill_atca_074_head[4] = { HEAD(2, 28, 2, 15, 0, 6, 0) };
const u16 gill_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 gill_atca_076_head[4] = { HEAD(2, 28, 4, 15, 0, 6, 0) };
const u16 gill_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 gill_atca_078_head[4] = { HEAD(2, 28, 1, 9, 0, 6, 0) };
const u16 gill_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 gill_atca_080_head[4] = { HEAD(2, 28, 3, 18, 0, 6, 0) };
const u16 gill_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 gill_atca_082_head[4] = { HEAD(2, 28, 5, 17, 0, 8, 0) };
const u16 gill_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 gill_atca_084_head[4] = { HEAD(2, 26, 0, 9, 0, 11, 0) };
const u16 gill_atca_084[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 gill_atca_086_head[4] = { HEAD(2, 26, 2, 12, 0, 7, 0) };
const u16 gill_atca_086[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 gill_atca_088_head[4] = { HEAD(2, 26, 4, 12, 0, 7, 0) };
const u16 gill_atca_088[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 gill_atca_090_head[4] = { HEAD(2, 26, 1, 9, 0, 6, 0) };
const u16 gill_atca_090[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 gill_atca_092_head[4] = { HEAD(2, 26, 3, 18, 0, 6, 0) };
const u16 gill_atca_092[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 gill_atca_094_head[4] = { HEAD(2, 26, 5, 17, 0, 8, 0) };
const u16 gill_atca_094[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 gill_atca_096_head[4] = { HEAD(2, 30, 0, 9, 0, 11, 0) };
const u16 gill_atca_096[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 gill_atca_098_head[4] = { HEAD(2, 30, 2, 12, 0, 7, 0) };
const u16 gill_atca_098[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 gill_atca_100_head[4] = { HEAD(2, 30, 4, 12, 0, 7, 0) };
const u16 gill_atca_100[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 gill_atca_102_head[4] = { HEAD(2, 30, 1, 9, 0, 6, 0) };
const u16 gill_atca_102[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 gill_atca_104_head[4] = { HEAD(2, 30, 3, 18, 0, 6, 0) };
const u16 gill_atca_104[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 gill_atca_106_head[4] = { HEAD(2, 30, 5, 17, 0, 8, 0) };
const u16 gill_atca_106[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 gill_atca_108_head[4] = { HEAD(2, 16, 0, 15, 0, 6, 0) };
const u16 gill_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 gill_atca_110_head[4] = { HEAD(2, 16, 2, 15, 0, 6, 0) };
const u16 gill_atca_110[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 gill_atca_112_head[4] = { HEAD(2, 16, 4, 15, 0, 6, 0) };
const u16 gill_atca_112[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 gill_atca_114_head[4] = { HEAD(2, 16, 1, 9, 0, 6, 0) };
const u16 gill_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 gill_atca_116_head[4] = { HEAD(2, 16, 3, 18, 0, 6, 0) };
const u16 gill_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 gill_atca_118_head[4] = { HEAD(2, 16, 5, 17, 0, 8, 0) };
const u16 gill_atca_118[152] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3584, 2304, 2816),
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3586, 3072, 1792),
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3588, 3072, 1792),
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3585, 2304, 1536),
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3587, 4608, 1536),
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3589, 4352, 2048),
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4608, 2304, 2816),
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4610, 3072, 1792),
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4612, 3072, 1792),
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4609, 2304, 1536),
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4611, 4608, 1536),
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4613, 4352, 2048),
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 gill_atca_144_head[4] = { HEAD(4, 0, 16, 1, 0, 1, 0) };
const u16 gill_atca_144[140] = {
    CMD(CM_CAFR, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 1, 0, 0x01D0, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 1, 0, 0x01D0, -21, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 2, 0, 0x01D1, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0478, 0, 1, 0, 0, 0, 32, 110),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0479, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x047A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x047B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x047C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x047D, 0, 1, 0, 0, 0, 32, 111),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 32, 112),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 gill_atca_145_head[4] = { HEAD(2, 0, 16, 5, 0, 1, 0) };
const u16 gill_atca_145[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 gill_atca_146_head[4] = { HEAD(2, 0, 16, 5, 0, 1, 0) };
const u16 gill_atca_146[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 no name */
const u16 gill_atca_156_head[4] = { HEAD(4, 0, 0, 12, 0, 4, 0) };
const u16 gill_atca_156[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x01CF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x01CF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2002, 0x0C00, 0x0500,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0250, 0, 123, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 208, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x03EF, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x03F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x03F1, -13, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x03F2, 0, 29, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x03F3, 0, 30, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x03F4, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x03F5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x00D3, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x00D4, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x00D5, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX gill_olc_ix_table[146] = {
    { { 0, 0, 0, 0 } },
    { { 0, 1, 0, 0 } },
    { { 0, 2, 0, 0 } },
    { { 0, 3, 0, 0 } },
    { { 0, 4, 0, 0 } },
    { { 0, 5, 0, 0 } },
    { { 0, 6, 0, 0 } },
    { { 0, 7, 0, 0 } },
    { { 0, 8, 0, 0 } },
    { { 0, 9, 0, 0 } },
    { { 0, 10, 0, 0 } },
    { { 0, 11, 0, 0 } },
    { { 0, 12, 0, 0 } },
    { { 0, 13, 0, 0 } },
    { { 0, 14, 0, 0 } },
    { { 0, 15, 0, 0 } },
    { { 0, 16, 0, 0 } },
    { { 0, 17, 0, 0 } },
    { { 0, 18, 0, 0 } },
    { { 0, 19, 0, 0 } },
    { { 0, 20, 0, 0 } },
    { { 0, 21, 0, 0 } },
    { { 0, 22, 0, 0 } },
    { { 0, 23, 0, 0 } },
    { { 0, 24, 0, 0 } },
    { { 0, 25, 0, 0 } },
    { { 0, 26, 0, 0 } },
    { { 0, 27, 0, 0 } },
    { { 0, 28, 0, 0 } },
    { { 0, 29, 0, 0 } },
    { { 0, 30, 0, 0 } },
    { { 0, 31, 0, 0 } },
    { { 0, 32, 0, 0 } },
    { { 0, 33, 0, 0 } },
    { { 0, 34, 0, 0 } },
    { { 0, 35, 0, 0 } },
    { { 0, 44, 0, 0 } },
    { { 0, 45, 0, 0 } },
    { { 0, 46, 0, 0 } },
    { { 0, 47, 0, 0 } },
    { { 0, 0, 62, 0 } },
    { { 0, 63, 64, 0 } },
    { { 0, 65, 66, 0 } },
    { { 0, 67, 68, 0 } },
    { { 0, 69, 70, 0 } },
    { { 0, 71, 72, 0 } },
    { { 0, 73, 0, 0 } },
    { { 74, 0, 0, 0 } },
    { { 76, 0, 0, 0 } },
    { { 78, 0, 0, 0 } },
    { { 80, 0, 0, 0 } },
    { { 82, 0, 0, 0 } },
    { { 84, 0, 0, 0 } },
    { { 86, 0, 0, 0 } },
    { { 88, 0, 0, 0 } },
    { { 90, 0, 0, 0 } },
    { { 92, 0, 0, 0 } },
    { { 94, 0, 0, 0 } },
    { { 96, 0, 0, 0 } },
    { { 98, 0, 0, 0 } },
    { { 100, 0, 0, 0 } },
    { { 102, 0, 0, 0 } },
    { { 104, 0, 0, 0 } },
    { { 106, 0, 0, 0 } },
    { { 108, 0, 0, 0 } },
    { { 110, 0, 0, 0 } },
    { { 112, 0, 0, 0 } },
    { { 114, 0, 0, 0 } },
    { { 116, 0, 0, 0 } },
    { { 118, 0, 0, 0 } },
    { { 120, 0, 0, 0 } },
    { { 122, 0, 0, 0 } },
    { { 124, 0, 0, 0 } },
    { { 126, 0, 0, 0 } },
    { { 128, 0, 0, 0 } },
    { { 130, 0, 0, 0 } },
    { { 132, 0, 0, 0 } },
    { { 134, 0, 0, 0 } },
    { { 136, 0, 0, 0 } },
    { { 138, 0, 0, 0 } },
    { { 140, 0, 0, 0 } },
    { { 142, 0, 0, 0 } },
    { { 144, 0, 0, 0 } },
    { { 146, 0, 0, 0 } },
    { { 148, 0, 0, 0 } },
    { { 150, 0, 0, 0 } },
    { { 152, 0, 0, 0 } },
    { { 154, 0, 0, 0 } },
    { { 156, 0, 0, 0 } },
    { { 158, 0, 0, 0 } },
    { { 160, 0, 0, 0 } },
    { { 162, 0, 0, 0 } },
    { { 164, 0, 0, 0 } },
    { { 166, 0, 0, 0 } },
    { { 168, 0, 0, 0 } },
    { { 170, 0, 0, 0 } },
    { { 172, 0, 0, 0 } },
    { { 174, 0, 0, 0 } },
    { { 176, 0, 0, 0 } },
    { { 186, 0, 0, 0 } },
    { { 188, 0, 0, 0 } },
    { { 190, 0, 0, 0 } },
    { { 192, 0, 0, 0 } },
    { { 194, 0, 0, 0 } },
    { { 196, 0, 0, 0 } },
    { { 206, 0, 0, 0 } },
    { { 208, 0, 0, 0 } },
    { { 210, 0, 0, 0 } },
    { { 212, 0, 0, 0 } },
    { { 214, 0, 0, 0 } },
    { { 216, 0, 0, 0 } },
    { { 218, 0, 0, 0 } },
    { { 220, 0, 0, 0 } },
    { { 222, 0, 0, 0 } },
    { { 224, 0, 0, 0 } },
    { { 0, 255, 0, 0 } },
    { { 0, 256, 0, 0 } },
    { { 0, 257, 0, 0 } },
    { { 0, 258, 0, 0 } },
    { { 0, 259, 0, 0 } },
    { { 0, 260, 0, 0 } },
    { { 0, 261, 0, 0 } },
    { { 0, 262, 0, 0 } },
    { { 0, 263, 0, 0 } },
    { { 0, 264, 0, 0 } },
    { { 0, 265, 0, 0 } },
    { { 0, 266, 0, 0 } },
    { { 0, 267, 0, 0 } },
    { { 0, 268, 0, 0 } },
    { { 0, 269, 0, 0 } },
    { { 0, 270, 0, 0 } },
    { { 0, 271, 0, 0 } },
    { { 0, 272, 0, 0 } },
    { { 0, 273, 0, 0 } },
    { { 0, 274, 0, 0 } },
    { { 0, 275, 0, 0 } },
    { { 0, 276, 0, 0 } },
    { { 0, 277, 0, 0 } },
    { { 0, 278, 0, 0 } },
    { { 0, 279, 0, 0 } },
    { { 0, 283, 0, 0 } },
    { { 0, 287, 0, 0 } },
    { { 0, 291, 292, 0 } },
    { { 0, 315, 316, 0 } },
    { { 0, 343, 344, 0 } },
    { { 0, 349, 350, 0 } },
};

const OVERLAP_PARTS gill_overlap_char_tbl[392] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 496 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 497 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 498 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 499 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 500 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 6, 501 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 7, 502 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 8, 503 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 9, 504 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 10, 505 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 11, 506 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 12, 507 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 13, 508 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 14, 509 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 15, 510 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 16, 511 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 512 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 18, 513 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 19, 514 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 515 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 516 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 517 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 518 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 519 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 614 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 615 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 616 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 28, 617 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 29, 618 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 30, 960 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 31, 961 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 32, 962 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 33, 963 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 34, 964 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 965 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 966 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 967 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 968 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 969 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 970 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 971 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 972 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 61 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 974 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 975 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 976 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 977 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 978 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 979 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 980 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 981 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 982 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 983 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 984 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 985 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 986 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 987 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 988 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 988 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 989 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 61, 989 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 62, 768 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 63, 769 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 64, 770 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 65, 771 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 66, 772 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 67, 773 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 68, 774 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 69, 775 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 70, 776 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 71, 777 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 72, 778 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 73, 779 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 74, 864 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 75, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 76, 865 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 77, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 78, 866 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 79, 0 },
    { 1, 0, 0, 0, 2, 0, 255, 0, 0, 80, 867 },
    { 1, 0, 0, 0, 2, 0, 255, 0, 0, 81, 874 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 82, 868 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 83, 875 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 84, 869 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 85, 876 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 88, 870 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 89, 877 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 90, 871 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 91, 878 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 92, 872 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 93, 879 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 204, 873 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 205, 0 },
    { -10, 0, 0, 0, 2, 0, 255, 0, 0, 94, 880 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 95, 0 },
    { -8, 0, 0, 0, 2, 0, 255, 0, 0, 96, 881 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 97, 0 },
    { -3, 0, 0, 0, 2, 0, 255, 0, 0, 98, 882 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 99, 0 },
    { -7, 0, 0, 0, 2, 0, 255, 0, 0, 100, 883 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 101, 0 },
    { -6, 0, 0, 0, 2, 0, 255, 0, 0, 102, 884 },
    { -7, -7, 0, 0, 2, 0, 255, 0, 0, 103, 890 },
    { -5, 0, 0, 0, 2, 0, 255, 0, 0, 104, 885 },
    { -11, 2, 0, 0, 2, 0, 255, 0, 0, 105, 891 },
    { -6, 0, 0, 0, 2, 0, 255, 0, 0, 106, 886 },
    { -10, 1, 0, 0, 2, 0, 255, 0, 0, 107, 892 },
    { -6, -10, 0, 0, 2, 0, 4, 0, 0, 110, 887 },
    { -12, -1, 0, 0, 2, 0, 4, 0, 0, 111, 893 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 112, 888 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 113, 894 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 204, 889 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 205, 895 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 114, 0 },
    { -16, 0, 0, 0, 2, 0, 255, 0, 0, 115, 896 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 116, 0 },
    { -17, -8, 0, 0, 2, 0, 255, 0, 0, 117, 897 },
    { -6, -5, 0, 0, 2, 0, 255, 0, 0, 118, 905 },
    { -25, -8, 0, 0, 2, 0, 255, 0, 0, 119, 898 },
    { 6, -4, 0, 0, 2, 0, 255, 0, 0, 120, 906 },
    { -30, -8, 0, 0, 2, 0, 255, 0, 0, 121, 899 },
    { 0, -1, 0, 0, 2, 0, 255, 0, 0, 122, 907 },
    { -39, -1, 0, 0, 2, 0, 255, 0, 0, 123, 900 },
    { 6, -1, 0, 0, 2, 0, 4, 0, 0, 126, 908 },
    { -42, 10, 0, 0, 2, 0, 4, 0, 0, 127, 901 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 128, 909 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 129, 902 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 130, 910 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 131, 903 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 204, 0 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 205, 904 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 132, 0 },
    { 12, 16, 0, 0, 2, 0, 255, 0, 0, 133, 913 },
    { 24, 0, 0, 0, 2, 0, 255, 0, 0, 134, 920 },
    { 24, 16, 0, 0, 2, 0, 255, 0, 0, 135, 914 },
    { 24, 0, 0, 0, 2, 0, 255, 0, 0, 136, 921 },
    { 28, 16, 0, 0, 2, 0, 255, 0, 0, 137, 915 },
    { 24, 0, 0, 0, 2, 0, 4, 0, 0, 140, 922 },
    { 28, 16, 0, 0, 2, 0, 4, 0, 0, 141, 916 },
    { 24, 0, 0, 0, 2, 0, 4, 0, 0, 142, 923 },
    { 28, 16, 0, 0, 2, 0, 4, 0, 0, 143, 917 },
    { 24, 0, 0, 0, 2, 0, 4, 0, 0, 144, 924 },
    { 28, 16, 0, 0, 2, 0, 4, 0, 0, 145, 918 },
    { 24, 0, 0, 0, 2, 0, 4, 0, 0, 146, 925 },
    { 28, 16, 0, 0, 2, 0, 4, 0, 0, 147, 919 },
    { 24, 0, 0, 0, 2, 0, 4, 0, 0, 204, 926 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 205, 0 },
    { -28, 0, 0, 0, 2, 0, 255, 0, 0, 148, 928 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 149, 0 },
    { -18, 0, 0, 0, 2, 0, 255, 0, 0, 150, 929 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 151, 0 },
    { -12, -2, 0, 0, 2, 0, 255, 0, 0, 152, 930 },
    { 17, -2, 0, 0, 2, 0, 255, 0, 0, 153, 937 },
    { -8, 0, 0, 0, 2, 0, 255, 0, 0, 154, 931 },
    { 14, -2, 0, 0, 2, 0, 255, 0, 0, 155, 938 },
    { -1, -3, 0, 0, 2, 0, 255, 0, 0, 156, 932 },
    { 0, -4, 0, 0, 2, 0, 255, 0, 0, 157, 939 },
    { -19, -2, 0, 0, 2, 0, 4, 0, 0, 160, 933 },
    { -12, 0, 0, 0, 2, 0, 4, 0, 0, 161, 940 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 162, 934 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 163, 941 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 164, 935 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 165, 942 },
    { -16, 0, 0, 0, 2, 0, 4, 0, 0, 204, 936 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 205, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 166, 0 },
    { 5, 6, 0, 0, 2, 0, 255, 0, 0, 167, 944 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 168, 0 },
    { 7, 7, 0, 0, 2, 0, 255, 0, 0, 169, 945 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 170, 0 },
    { 10, 8, 0, 0, 2, 0, 255, 0, 0, 171, 946 },
    { 1, 3, 0, 0, 2, 0, 255, 0, 0, 172, 953 },
    { 4, 7, 0, 0, 2, 0, 255, 0, 0, 173, 947 },
    { 2, 14, 0, 0, 2, 0, 255, 0, 0, 174, 954 },
    { 5, 8, 0, 0, 2, 0, 255, 0, 0, 175, 948 },
    { 1, 18, 0, 0, 2, 0, 4, 0, 0, 178, 955 },
    { 9, 7, 0, 0, 2, 0, 4, 0, 0, 179, 949 },
    { 14, -8, 0, 0, 2, 0, 4, 0, 0, 180, 956 },
    { 16, -4, 0, 0, 2, 0, 4, 0, 0, 181, 950 },
    { 14, -8, 0, 0, 2, 0, 4, 0, 0, 182, 957 },
    { 16, -4, 0, 0, 2, 0, 4, 0, 0, 183, 951 },
    { 14, -8, 0, 0, 2, 0, 4, 0, 0, 184, 958 },
    { 16, -4, 0, 0, 2, 0, 4, 0, 0, 185, 952 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 184, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 185, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 186, 0 },
    { -28, 15, 0, 0, 1, 0, 255, 0, 0, 187, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 188, 0 },
    { -16, 0, 0, 0, 2, 0, 255, 0, 0, 189, 897 },
    { -2, 3, 0, 0, 2, 0, 255, 0, 0, 190, 905 },
    { -25, -1, 0, 0, 2, 0, 255, 0, 0, 191, 898 },
    { 8, 7, 0, 0, 2, 0, 255, 0, 0, 192, 906 },
    { -31, 4, 0, 0, 2, 0, 255, 0, 0, 193, 899 },
    { -5, 14, 0, 0, 2, 0, 255, 0, 0, 194, 907 },
    { -40, 14, 0, 0, 2, 0, 255, 0, 0, 195, 900 },
    { -5, 14, 0, 0, 2, 0, 4, 0, 0, 198, 908 },
    { -47, 28, 0, 0, 2, 0, 4, 0, 0, 199, 901 },
    { -4, 4, 0, 0, 2, 0, 4, 0, 0, 200, 909 },
    { -24, 8, 0, 0, 2, 0, 4, 0, 0, 201, 902 },
    { -8, 4, 0, 0, 2, 0, 4, 0, 0, 202, 910 },
    { -24, 8, 0, 0, 2, 0, 4, 0, 0, 203, 903 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 204, 0 },
    { -24, 8, 0, 0, 2, 0, 4, 0, 0, 205, 904 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 204, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 205, 0 },
    { -55, 0, 0, 0, 2, 0, 255, 0, 0, 206, 780 },
    { -61, 0, 0, 0, 2, 0, 255, 0, 0, 207, 0 },
    { -55, 0, 0, 0, 2, 0, 255, 0, 0, 208, 781 },
    { -61, 0, 0, 0, 2, 0, 255, 0, 0, 209, 0 },
    { -3, 0, 0, 0, 2, 0, 255, 0, 0, 210, 782 },
    { -3, 0, 0, 0, 2, 0, 255, 0, 0, 211, 789 },
    { -14, 6, 0, 0, 2, 0, 255, 0, 0, 212, 783 },
    { -3, 0, 0, 0, 2, 0, 255, 0, 0, 213, 790 },
    { -8, 2, 0, 0, 2, 0, 255, 0, 0, 214, 784 },
    { -32, -8, 0, 0, 2, 0, 255, 0, 0, 215, 791 },
    { -24, -2, 0, 0, 2, 0, 255, 0, 0, 216, 785 },
    { -32, -8, 0, 0, 2, 0, 255, 0, 0, 217, 792 },
    { -37, -7, 0, 0, 2, 0, 255, 0, 0, 218, 786 },
    { -32, -8, 0, 0, 2, 0, 255, 0, 0, 219, 793 },
    { -40, -8, 0, 0, 2, 0, 255, 0, 0, 220, 787 },
    { -32, -8, 0, 0, 2, 0, 255, 0, 0, 221, 794 },
    { -61, -21, 0, 0, 2, 0, 255, 0, 0, 222, 788 },
    { -32, -8, 0, 0, 2, 0, 255, 0, 0, 223, 795 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 225, 960 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 226, 961 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 227, 962 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 228, 963 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 229, 964 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 230, 965 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 231, 966 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 232, 967 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 233, 968 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 234, 969 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 235, 970 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 236, 971 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 237, 972 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 238, 973 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 239, 974 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 240, 975 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 241, 976 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 242, 977 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 243, 978 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 244, 979 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 245, 980 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 246, 981 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 247, 982 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 248, 983 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 249, 984 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 250, 985 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 251, 986 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 252, 987 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 253, 988 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 254, 989 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 254, 0 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 255, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 256, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 257, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 258, 1077 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 259, 1077 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 260, 1078 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 261, 1078 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 262, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 263, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 264, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 265, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 266, 1077 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 267, 1077 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 268, 1078 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 269, 1078 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 270, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 271, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 272, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 273, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 274, 1077 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 275, 1078 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 276, 1075 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 277, 1076 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 278, 1077 },
    { 0, 0, 0, 0, 2, 1, 4, 0, 0, 280, 1075 },
    { 0, 0, 0, 0, 2, 1, 4, 0, 0, 281, 1076 },
    { 0, 0, 0, 0, 2, 1, 4, 0, 0, 282, 1077 },
    { 0, 0, 0, 0, 2, 1, 4, 0, 0, 279, 1078 },
    { 0, 0, 0, 0, 2, 1, 5, 0, 0, 284, 1075 },
    { 0, 0, 0, 0, 2, 1, 5, 0, 0, 285, 1076 },
    { 0, 0, 0, 0, 2, 1, 5, 0, 0, 286, 1077 },
    { 0, 0, 0, 0, 2, 1, 5, 0, 0, 283, 1078 },
    { 0, 0, 0, 0, 2, 1, 6, 0, 0, 288, 1075 },
    { 0, 0, 0, 0, 2, 1, 6, 0, 0, 289, 1076 },
    { 0, 0, 0, 0, 2, 1, 6, 0, 0, 290, 1077 },
    { 0, 0, 0, 0, 2, 1, 6, 0, 0, 287, 1078 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 293, 1181 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 294, 1193 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 295, 1182 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 296, 1194 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 297, 1183 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 298, 1195 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 299, 1184 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 300, 1196 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 301, 1185 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 302, 1197 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 303, 1186 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 304, 1198 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 305, 1187 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 306, 1199 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 307, 1188 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 308, 1200 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 309, 1189 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 310, 1201 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 311, 1190 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 312, 1202 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 313, 1191 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 314, 1203 },
    { 0, 0, 0, 12, 1, 0, 250, 0, 0, 313, 1192 },
    { 0, 0, 0, 12, 2, 0, 250, 0, 0, 314, 1204 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 317, 1207 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 318, 1221 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 319, 1208 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 320, 1222 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 321, 1209 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 322, 1223 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 323, 1210 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 324, 1224 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 325, 1211 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 326, 1225 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 327, 1212 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 328, 1226 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 329, 1213 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 330, 1227 },
    { 0, 0, 0, 12, 1, 0, 4, 0, 0, 331, 1214 },
    { 0, 0, 0, 12, 2, 0, 4, 0, 0, 332, 1228 },
    { 0, 0, 0, 12, 1, 0, 4, 0, 0, 333, 1215 },
    { 0, 0, 0, 12, 2, 0, 4, 0, 0, 334, 1229 },
    { 0, 0, 0, 12, 1, 0, 4, 0, 0, 335, 1216 },
    { 0, 0, 0, 12, 2, 0, 4, 0, 0, 336, 1230 },
    { 0, 0, 0, 12, 1, 0, 5, 0, 0, 337, 1217 },
    { 0, 0, 0, 12, 2, 0, 5, 0, 0, 338, 1231 },
    { 0, 0, 0, 12, 1, 0, 5, 0, 0, 339, 1218 },
    { 0, 0, 0, 12, 2, 0, 5, 0, 0, 340, 1232 },
    { 0, 0, 0, 12, 1, 0, 5, 0, 0, 341, 1219 },
    { 0, 0, 0, 12, 2, 0, 5, 0, 0, 342, 1233 },
    { 0, 0, 0, 12, 1, 0, 250, 0, 0, 341, 1220 },
    { 0, 0, 0, 12, 2, 0, 250, 0, 0, 342, 1234 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 345, 1235 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 346, 1238 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 347, 1236 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 348, 1239 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 343, 1237 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 344, 1240 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 351, 1241 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 352, 1262 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 353, 1242 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 354, 1263 },
    { 0, 0, 0, 12, 1, 0, 3, 0, 0, 355, 1243 },
    { 0, 0, 0, 12, 2, 0, 3, 0, 0, 356, 1264 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 357, 1244 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 358, 1265 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 359, 1245 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 360, 1266 },
    { 0, 0, 0, 12, 1, 0, 2, 0, 0, 361, 1246 },
    { 0, 0, 0, 12, 2, 0, 2, 0, 0, 362, 1267 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 363, 1247 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 364, 1268 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 365, 1248 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 366, 1269 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 367, 1249 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 368, 1270 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 369, 1250 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 370, 1271 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 371, 1251 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 372, 1272 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 373, 1252 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 374, 1273 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 375, 1253 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 376, 1274 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 377, 1254 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 378, 1275 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 379, 1255 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 380, 1276 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 381, 1256 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 382, 1277 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 383, 1257 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 384, 1278 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 385, 1258 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 386, 1279 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 387, 1259 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 388, 1280 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 389, 1260 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 390, 1281 },
    { 0, 0, 0, 12, 1, 0, 1, 0, 0, 391, 1261 },
    { 0, 0, 0, 12, 2, 0, 1, 0, 0, 391, 1282 },
    { 0, 0, 0, 0, 1, 0, 250, 0, 0, 391, 0 },
};

const CatchTable gill_rival_catch_tbl[768] = {
    { -100, 0, 2, 1, 1 },
    { -107, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -81, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -111, 0, 2, 1, 1 },
    { -129, 0, 2, 1, 1 },
    { -104, 0, 2, 1, 1 },
    { -104, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -81, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -105, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -94, 0, 2, 1, 1 },
    { -102, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 2 },
    { -66, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -61, 0, 2, 1, 2 },
    { -81, 0, 2, 1, 2 },
    { -82, 0, 2, 1, 2 },
    { -98, 0, 2, 1, 2 },
    { -82, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -102, 0, 2, 1, 2 },
    { -61, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -75, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -74, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -61, 1, 2, 1, 3 },
    { -45, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -45, 0, 2, 1, 3 },
    { -46, 0, 2, 1, 3 },
    { -33, 0, 2, 1, 3 },
    { -27, -18, 2, 1, 3 },
    { -43, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -51, 0, 2, 1, 3 },
    { -45, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -61, 1, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -56, 4, 2, 1, 3 },
    { -42, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -30, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -38, 0, 2, 1, 4 },
    { -31, 68, 2, 1, 4 },
    { -51, 96, 2, 1, 4 },
    { -63, 72, 2, 1, 4 },
    { -41, 116, 2, 1, 4 },
    { -41, 84, 2, 1, 4 },
    { -25, -3, 2, 1, 4 },
    { -12, 20, 2, 1, 4 },
    { -24, 12, 2, 1, 4 },
    { -38, 102, 2, 1, 4 },
    { -63, 72, 2, 1, 4 },
    { -51, 96, 2, 1, 4 },
    { -51, 96, 2, 1, 4 },
    { -38, 0, 2, 1, 4 },
    { -51, 96, 2, 1, 4 },
    { -51, 96, 2, 1, 4 },
    { -42, 2, 2, 1, 4 },
    { -26, 5, 2, 1, 4 },
    { -26, 5, 2, 1, 4 },
    { -40, 92, 2, 1, 4 },
    { -28, 62, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -37, 18, 2, 1, 5 },
    { -33, 158, 2, 1, 5 },
    { -52, 94, 2, 1, 5 },
    { -74, 118, 2, 1, 5 },
    { -48, 154, 2, 1, 5 },
    { -38, 90, 2, 1, 5 },
    { -41, 44, 2, 1, 5 },
    { -30, 39, 2, 1, 5 },
    { -28, 4, 2, 1, 5 },
    { -34, 124, 2, 1, 5 },
    { -74, 118, 2, 1, 5 },
    { -52, 94, 2, 1, 5 },
    { -52, 94, 2, 1, 5 },
    { -37, 18, 2, 1, 5 },
    { -52, 94, 2, 1, 5 },
    { -52, 94, 2, 1, 5 },
    { -36, 48, 2, 1, 5 },
    { -25, 49, 2, 1, 5 },
    { -11, 97, 2, 1, 5 },
    { -38, 90, 2, 1, 5 },
    { -28, 104, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -12, 98, 2, 1, 6 },
    { -10, 198, 2, 1, 6 },
    { -35, 172, 2, 1, 6 },
    { -36, 132, 2, 1, 6 },
    { -42, 182, 2, 1, 6 },
    { -22, 103, 2, 1, 6 },
    { -4, 204, 2, 1, 6 },
    { -36, 148, 2, 1, 6 },
    { -30, 138, 2, 1, 6 },
    { -22, 170, 2, 1, 6 },
    { -36, 132, 2, 1, 6 },
    { -35, 172, 2, 1, 6 },
    { -35, 172, 2, 1, 6 },
    { -12, 98, 2, 1, 6 },
    { -35, 172, 2, 1, 6 },
    { -35, 172, 2, 1, 6 },
    { -34, 164, 2, 1, 6 },
    { -16, 171, 2, 1, 6 },
    { -17, 87, 2, 1, 6 },
    { -8, 104, 2, 1, 6 },
    { -26, 184, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 117, 2, 1, 7 },
    { 23, 118, 2, 1, 7 },
    { -16, 184, 2, 1, 7 },
    { -13, 170, 2, 1, 7 },
    { 37, 121, 2, 1, 7 },
    { -24, 196, 2, 1, 7 },
    { 2, 202, 2, 1, 7 },
    { 7, 142, 2, 1, 7 },
    { -24, 182, 2, 1, 7 },
    { -9, 186, 2, 1, 7 },
    { -13, 170, 2, 1, 7 },
    { -16, 184, 2, 1, 7 },
    { -16, 184, 2, 1, 7 },
    { 9, 117, 2, 1, 7 },
    { -16, 184, 2, 1, 7 },
    { -16, 184, 2, 1, 7 },
    { -2, 186, 2, 1, 7 },
    { 5, 188, 2, 1, 7 },
    { -16, 118, 2, 1, 7 },
    { -24, 206, 2, 1, 7 },
    { 10, 98, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 15, 69, 2, 1, 8 },
    { 18, 97, 2, 1, 8 },
    { 8, 124, 2, 1, 8 },
    { 22, 127, 2, 1, 8 },
    { 29, 123, 2, 1, 8 },
    { 4, 71, 2, 1, 8 },
    { 17, 196, 2, 1, 8 },
    { 14, 118, 2, 1, 8 },
    { -2, 188, 2, 1, 8 },
    { -15, 188, 2, 1, 8 },
    { 22, 127, 2, 1, 8 },
    { 8, 124, 2, 1, 8 },
    { 8, 124, 2, 1, 8 },
    { 15, 69, 2, 1, 8 },
    { 8, 124, 2, 1, 8 },
    { 8, 124, 2, 1, 8 },
    { 6, 110, 2, 1, 8 },
    { 6, 125, 2, 1, 8 },
    { -10, 116, 2, 1, 8 },
    { 12, 60, 2, 1, 8 },
    { 2, 84, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 10, 47, 2, 1, 9 },
    { 25, 81, 2, 1, 9 },
    { 10, 105, 2, 1, 9 },
    { 26, 72, 2, 1, 9 },
    { 15, 49, 2, 1, 9 },
    { 4, 54, 2, 1, 9 },
    { 13, 180, 2, 1, 9 },
    { 26, 38, 2, 1, 9 },
    { 16, 124, 2, 1, 9 },
    { 1, 63, 2, 1, 9 },
    { 26, 72, 2, 1, 9 },
    { 10, 105, 2, 1, 9 },
    { 10, 105, 2, 1, 9 },
    { 10, 47, 2, 1, 9 },
    { 10, 105, 2, 1, 9 },
    { 10, 105, 2, 1, 9 },
    { 12, 108, 2, 1, 9 },
    { 12, 136, 2, 1, 9 },
    { -3, 84, 2, 1, 9 },
    { 6, 54, 2, 1, 9 },
    { 10, 60, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 6, 46, 2, 1, 10 },
    { 14, 73, 2, 1, 10 },
    { 11, 61, 2, 1, 10 },
    { 21, 69, 2, 1, 10 },
    { 8, 46, 2, 1, 10 },
    { 12, 52, 2, 1, 10 },
    { 14, 184, 2, 1, 10 },
    { 30, 40, 2, 1, 10 },
    { 4, 88, 1, 1, 10 },
    { -4, 65, 2, 1, 10 },
    { 21, 69, 2, 1, 10 },
    { 11, 61, 2, 1, 10 },
    { 11, 61, 2, 1, 10 },
    { 6, 46, 2, 1, 10 },
    { 11, 61, 2, 1, 10 },
    { 11, 61, 2, 1, 10 },
    { 12, 58, 2, 1, 10 },
    { 12, 138, 2, 1, 9 },
    { -10, 59, 2, 1, 10 },
    { 8, 58, 2, 1, 10 },
    { 10, 60, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 7, 50, 2, 1, 11 },
    { 19, 63, 2, 1, 11 },
    { 11, 66, 2, 1, 11 },
    { 20, 72, 2, 1, 11 },
    { 10, 52, 2, 1, 11 },
    { 15, 54, 2, 1, 11 },
    { 28, 134, 2, 1, 11 },
    { 30, 48, 2, 1, 11 },
    { 10, 82, 1, 1, 11 },
    { -1, 70, 2, 1, 11 },
    { 20, 72, 2, 1, 11 },
    { 11, 66, 2, 1, 11 },
    { 11, 66, 2, 1, 11 },
    { 7, 50, 2, 1, 11 },
    { 11, 66, 2, 1, 11 },
    { 11, 66, 2, 1, 11 },
    { 12, 64, 2, 1, 11 },
    { 13, 142, 2, 1, 9 },
    { -7, 58, 2, 1, 11 },
    { 14, 60, 2, 1, 11 },
    { 14, 64, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 8, 52, 2, 1, 12 },
    { 17, 61, 2, 1, 12 },
    { 12, 61, 2, 1, 12 },
    { 28, 67, 2, 1, 12 },
    { 21, 51, 2, 1, 12 },
    { 14, 40, 2, 1, 12 },
    { 28, 134, 2, 1, 12 },
    { 30, 48, 2, 1, 12 },
    { 14, 76, 1, 1, 12 },
    { 18, 69, 2, 1, 12 },
    { 28, 67, 2, 1, 12 },
    { 12, 61, 2, 1, 12 },
    { 12, 61, 2, 1, 12 },
    { 8, 52, 2, 1, 12 },
    { 12, 61, 2, 1, 12 },
    { 12, 61, 2, 1, 12 },
    { 12, 64, 2, 1, 12 },
    { 12, 142, 2, 1, 9 },
    { -7, 63, 2, 1, 12 },
    { 8, 62, 2, 1, 12 },
    { 14, 64, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 17, 68, 2, 1, 13 },
    { 16, 75, 2, 1, 13 },
    { 9, 78, 2, 1, 13 },
    { 26, 86, 2, 1, 13 },
    { 20, 130, 2, 1, 13 },
    { 20, 72, 2, 1, 13 },
    { 31, 204, 2, 1, 13 },
    { 30, 62, 2, 1, 13 },
    { 8, 94, 1, 1, 13 },
    { -1, 84, 2, 1, 13 },
    { 26, 86, 2, 1, 13 },
    { 9, 78, 2, 1, 13 },
    { 9, 78, 2, 1, 13 },
    { 17, 68, 2, 1, 13 },
    { 9, 78, 2, 1, 13 },
    { 9, 78, 2, 1, 13 },
    { 8, 76, 2, 1, 13 },
    { 15, 154, 2, 1, 9 },
    { -4, 72, 2, 1, 13 },
    { 22, 74, 2, 1, 13 },
    { 16, 74, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 15, 83, 2, 1, 14 },
    { 13, 78, 2, 1, 14 },
    { 4, 124, 2, 1, 14 },
    { 7, 125, 2, 1, 14 },
    { 16, 125, 2, 1, 14 },
    { 16, 103, 2, 1, 14 },
    { 24, 204, 2, 1, 14 },
    { 26, 58, 2, 1, 14 },
    { 22, 180, 2, 1, 14 },
    { 8, 130, 2, 1, 14 },
    { 7, 125, 2, 1, 14 },
    { 4, 124, 2, 1, 14 },
    { 4, 124, 2, 1, 14 },
    { 15, 83, 2, 1, 14 },
    { 4, 124, 2, 1, 14 },
    { 4, 124, 2, 1, 14 },
    { 10, 110, 2, 1, 14 },
    { 3, 80, 2, 1, 12 },
    { -6, 95, 2, 1, 14 },
    { 6, 144, 2, 1, 14 },
    { -4, 134, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 11, 73, 2, 1, 15 },
    { 7, 91, 2, 1, 15 },
    { 9, 122, 2, 1, 15 },
    { 11, 128, 2, 1, 15 },
    { 24, 111, 2, 1, 15 },
    { 9, 121, 2, 1, 15 },
    { -22, 222, 2, 1, 15 },
    { 6, 132, 2, 1, 15 },
    { 20, 108, 2, 1, 15 },
    { 9, 74, 2, 1, 15 },
    { 11, 128, 2, 1, 15 },
    { 9, 122, 2, 1, 15 },
    { 9, 122, 2, 1, 15 },
    { 11, 73, 2, 1, 15 },
    { 9, 122, 2, 1, 15 },
    { 9, 122, 2, 1, 15 },
    { 6, 196, 2, 1, 15 },
    { 5, 69, 2, 1, 13 },
    { -1, 214, 2, 1, 15 },
    { 2, 90, 2, 1, 15 },
    { 2, 132, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -39, -34, 2, 1, 16 },
    { -11, 14, 2, 1, 16 },
    { -20, 9, 2, 1, 16 },
    { -14, 3, 2, 1, 16 },
    { -11, 2, 2, 1, 16 },
    { -29, 2, 2, 1, 16 },
    { -74, 13, 2, 1, 16 },
    { 12, 2, 2, 1, 16 },
    { -28, 70, 2, 1, 16 },
    { -12, 2, 2, 1, 16 },
    { -14, 3, 2, 1, 16 },
    { -20, 9, 2, 1, 16 },
    { -20, 9, 2, 1, 16 },
    { -39, -34, 2, 1, 16 },
    { -20, 9, 2, 1, 16 },
    { -20, 9, 2, 1, 16 },
    { -40, 6, 2, 1, 16 },
    { -37, 17, 2, 1, 14 },
    { -36, 96, 2, 1, 16 },
    { -22, 4, 2, 1, 16 },
    { -36, 8, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -21, 4, 2, 1, 17 },
    { -16, 23, 2, 1, 17 },
    { -23, 5, 2, 1, 17 },
    { -18, 14, 2, 1, 17 },
    { -14, 11, 2, 1, 17 },
    { -25, 13, 2, 1, 17 },
    { -74, 13, 2, 1, 17 },
    { -12, 13, 2, 1, 17 },
    { -28, 84, 2, 1, 17 },
    { -15, 13, 2, 1, 17 },
    { -18, 14, 2, 1, 17 },
    { -23, 5, 2, 1, 17 },
    { -23, 5, 2, 1, 17 },
    { -21, 4, 2, 1, 17 },
    { -23, 5, 2, 1, 17 },
    { -23, 5, 2, 1, 17 },
    { -38, 10, 2, 1, 17 },
    { -30, 19, 2, 1, 15 },
    { -20, 97, 2, 1, 17 },
    { -20, 12, 2, 1, 17 },
    { -32, 8, 2, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -30, 2, 2, 1, 18 },
    { -18, 33, 2, 1, 18 },
    { -26, 26, 2, 1, 18 },
    { -21, 23, 2, 1, 18 },
    { -17, 20, 2, 1, 18 },
    { -34, 19, 2, 1, 18 },
    { -74, 13, 2, 1, 18 },
    { -16, 2, 2, 1, 18 },
    { -30, 34, 2, 1, 18 },
    { -19, 19, 2, 1, 18 },
    { -21, 23, 2, 1, 18 },
    { -26, 26, 2, 1, 18 },
    { -26, 26, 2, 1, 18 },
    { -30, 2, 2, 1, 18 },
    { -26, 26, 2, 1, 18 },
    { -26, 26, 2, 1, 18 },
    { -28, 16, 2, 1, 18 },
    { -32, 12, 2, 1, 16 },
    { -60, 16, 2, 1, 18 },
    { -34, 19, 2, 1, 18 },
    { -26, 18, 2, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -107, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -104, 0, 2, 1, 1 },
    { -104, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { -112, 0, 2, 1, 1 },
    { -112, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -100, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -107, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -105, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -94, 0, 2, 1, 1 },
    { -108, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -56, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -56, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -88, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -75, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -80, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -28, 0, 2, 1, 3 },
    { -28, 0, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -32, 2, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -41, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -22, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { -38, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -34, 10, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -13, 14, 2, 1, 4 },
    { -22, 2, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -18, 12, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -34, 10, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -12, 0, 2, 1, 4 },
    { -22, 0, 2, 1, 4 },
    { -19, 0, 2, 1, 4 },
    { -38, 0, 2, 1, 4 },
    { -30, 0, 2, 1, 4 },
    { -26, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -39, 15, 2, 1, 5 },
    { -22, 18, 2, 1, 5 },
    { -8, 24, 2, 1, 5 },
    { -24, 38, 2, 1, 5 },
    { -16, 16, 2, 1, 5 },
    { -16, 22, 2, 1, 5 },
    { -39, 35, 2, 1, 5 },
    { -28, 30, 2, 1, 5 },
    { -12, 28, 2, 1, 5 },
    { -12, 34, 2, 1, 5 },
    { -24, 38, 2, 1, 5 },
    { -8, 24, 2, 1, 5 },
    { -8, 24, 2, 1, 5 },
    { -39, 15, 2, 1, 5 },
    { -8, 24, 2, 1, 5 },
    { -8, 24, 2, 1, 5 },
    { -20, 22, 2, 1, 5 },
    { -25, 21, 2, 1, 5 },
    { -38, 12, 2, 1, 5 },
    { -20, 22, 2, 1, 5 },
    { -28, 24, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -37, 1, 1, 1, 6 },
    { -64, 16, 1, 1, 6 },
    { -68, 26, 1, 1, 6 },
    { -64, 28, 1, 1, 6 },
    { -64, 28, 1, 1, 6 },
    { -54, 20, 1, 1, 6 },
    { -68, 27, 1, 1, 6 },
    { -56, 24, 1, 1, 6 },
    { -66, 28, 1, 1, 6 },
    { -60, 30, 1, 1, 6 },
    { -64, 28, 1, 1, 6 },
    { -68, 20, 1, 1, 6 },
    { -68, 20, 1, 1, 6 },
    { -37, 1, 1, 1, 6 },
    { -68, 26, 1, 1, 6 },
    { -68, 26, 1, 1, 6 },
    { -32, 24, 1, 1, 6 },
    { -58, 35, 1, 1, 6 },
    { -46, 18, 1, 1, 6 },
    { -58, 10, 1, 1, 6 },
    { -50, 26, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -55, 12, 1, 1, 7 },
    { -80, 20, 1, 1, 7 },
    { -74, 38, 1, 1, 7 },
    { -86, 36, 1, 1, 7 },
    { -70, 38, 1, 1, 7 },
    { -60, 22, 1, 1, 7 },
    { -36, 33, 1, 1, 7 },
    { -64, 36, 1, 1, 7 },
    { -80, 36, 1, 1, 7 },
    { -66, 50, 1, 1, 7 },
    { -86, 36, 1, 1, 7 },
    { -72, 38, 1, 1, 7 },
    { -72, 38, 1, 1, 7 },
    { -55, 12, 1, 1, 7 },
    { -74, 38, 1, 1, 7 },
    { -74, 38, 1, 1, 7 },
    { -76, 54, 1, 1, 7 },
    { -80, 58, 1, 1, 7 },
    { -72, 26, 2, 1, 7 },
    { -54, 46, 1, 1, 7 },
    { -74, 32, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -41, 22, 2, 1, 8 },
    { -68, 18, 2, 1, 8 },
    { -72, 50, 2, 1, 8 },
    { -58, 54, 2, 1, 8 },
    { -62, 42, 2, 1, 8 },
    { -56, 48, 2, 1, 8 },
    { -57, 22, 2, 1, 8 },
    { -62, 52, 2, 1, 8 },
    { -78, 50, 2, 1, 8 },
    { -72, 48, 2, 1, 8 },
    { -58, 54, 2, 1, 8 },
    { -72, 50, 2, 1, 8 },
    { -72, 50, 2, 1, 8 },
    { -41, 22, 2, 1, 8 },
    { -72, 50, 2, 1, 8 },
    { -72, 50, 2, 1, 8 },
    { -54, 58, 2, 1, 8 },
    { -70, 62, 2, 1, 8 },
    { -74, 30, 2, 1, 8 },
    { -54, 17, 2, 1, 8 },
    { -60, 32, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 37, 2, 1, 9 },
    { -91, 32, 2, 1, 9 },
    { -74, 40, 2, 1, 9 },
    { -72, 60, 2, 1, 9 },
    { -62, 48, 2, 1, 9 },
    { -98, 72, 2, 1, 9 },
    { -72, 24, 2, 1, 9 },
    { -78, 54, 2, 1, 9 },
    { -96, 54, 2, 1, 9 },
    { -72, 52, 2, 1, 9 },
    { -72, 60, 2, 1, 9 },
    { -74, 40, 2, 1, 9 },
    { -74, 40, 2, 1, 9 },
    { -68, 37, 2, 1, 9 },
    { -74, 40, 2, 1, 9 },
    { -74, 40, 2, 1, 9 },
    { -57, 60, 2, 1, 9 },
    { -88, 61, 2, 1, 9 },
    { -74, 30, 2, 1, 9 },
    { -46, 34, 2, 1, 9 },
    { -84, 40, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -71, 34, 2, 1, 10 },
    { -76, 16, 2, 1, 10 },
    { -82, 50, 2, 1, 10 },
    { -76, 44, 2, 1, 10 },
    { -74, 42, 2, 1, 10 },
    { -84, 72, 2, 1, 10 },
    { -83, 19, 2, 1, 10 },
    { -74, 48, 2, 1, 10 },
    { -82, 52, 2, 1, 10 },
    { -74, 44, 2, 1, 10 },
    { -76, 44, 2, 1, 10 },
    { -82, 50, 2, 1, 10 },
    { -82, 50, 2, 1, 10 },
    { -71, 34, 2, 1, 10 },
    { -82, 50, 2, 1, 10 },
    { -82, 50, 2, 1, 10 },
    { -58, 60, 2, 1, 10 },
    { -79, 61, 2, 1, 10 },
    { -94, 34, 2, 1, 10 },
    { -72, 54, 2, 1, 10 },
    { -66, 32, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -51, 28, 2, 1, 11 },
    { -84, 32, 2, 1, 11 },
    { -66, 34, 2, 1, 11 },
    { -64, 56, 2, 1, 11 },
    { -56, 44, 2, 1, 11 },
    { -90, 70, 2, 1, 11 },
    { -82, 24, 2, 1, 11 },
    { -70, 54, 2, 1, 11 },
    { -88, 48, 2, 1, 11 },
    { -64, 48, 2, 1, 11 },
    { -64, 56, 2, 1, 11 },
    { -66, 34, 2, 1, 11 },
    { -66, 34, 2, 1, 11 },
    { -51, 28, 2, 1, 11 },
    { -66, 34, 2, 1, 11 },
    { -66, 34, 2, 1, 11 },
    { -53, 58, 2, 1, 11 },
    { -76, 60, 2, 1, 11 },
    { -94, 34, 2, 1, 11 },
    { -80, 48, 2, 1, 11 },
    { -65, 32, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -70, 31, 2, 1, 12 },
    { -84, 28, 2, 1, 12 },
    { -66, 36, 2, 1, 12 },
    { -63, 55, 2, 1, 12 },
    { -54, 45, 2, 1, 12 },
    { -88, 66, 2, 1, 12 },
    { -115, 144, 2, 1, 12 },
    { -72, 54, 2, 1, 12 },
    { -86, 50, 2, 1, 12 },
    { -64, 50, 2, 1, 12 },
    { -63, 55, 2, 1, 12 },
    { -66, 36, 2, 1, 12 },
    { -66, 36, 2, 1, 12 },
    { -70, 31, 2, 1, 12 },
    { -66, 36, 2, 1, 12 },
    { -66, 36, 2, 1, 12 },
    { -50, 56, 2, 1, 12 },
    { -76, 60, 2, 1, 12 },
    { -84, 30, 2, 1, 12 },
    { -54, 46, 2, 1, 12 },
    { -66, 32, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -69, 34, 2, 1, 13 },
    { -78, 32, 2, 1, 13 },
    { -68, 36, 2, 1, 13 },
    { -66, 56, 2, 1, 13 },
    { -58, 44, 2, 1, 13 },
    { -88, 68, 2, 1, 13 },
    { -115, 144, 2, 1, 13 },
    { -70, 52, 2, 1, 13 },
    { -86, 52, 2, 1, 13 },
    { -64, 52, 2, 1, 13 },
    { -66, 56, 2, 1, 13 },
    { -68, 36, 2, 1, 13 },
    { -68, 36, 2, 1, 13 },
    { -69, 34, 2, 1, 13 },
    { -68, 36, 2, 1, 13 },
    { -68, 36, 2, 1, 13 },
    { -50, 56, 2, 1, 13 },
    { -81, 60, 2, 1, 13 },
    { -82, 30, 2, 1, 13 },
    { -53, 45, 2, 1, 13 },
    { -66, 32, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -69, 34, 1, 0, 14 },
    { -70, 16, 1, 0, 14 },
    { -70, 36, 1, 0, 14 },
    { -68, 58, 1, 0, 14 },
    { -60, 46, 1, 0, 14 },
    { -90, 70, 1, 0, 14 },
    { -110, 11, 1, 0, 14 },
    { -72, 54, 1, 0, 14 },
    { -88, 54, 1, 0, 14 },
    { -66, 54, 1, 0, 14 },
    { -68, 58, 1, 0, 14 },
    { -70, 36, 1, 0, 14 },
    { -70, 36, 1, 0, 14 },
    { -69, 34, 1, 0, 14 },
    { -70, 36, 1, 0, 14 },
    { -70, 36, 1, 0, 14 },
    { -52, 56, 2, 0, 14 },
    { -70, 46, 1, 0, 14 },
    { -84, 30, 2, 0, 14 },
    { -90, 70, 1, 0, 14 },
    { -72, 34, 2, 0, 14 },
    { 0, 0, 2, 0, 1 },
    { 0, 0, 2, 0, 1 },
    { 0, 0, 2, 0, 1 },
};

/* extra scripts: 58 entries */
const u16* const gill_exca[59] = {
    gill_exca_000,  /* 0 follow-up of AIR NORMAL */
    gill_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    gill_exca_001,  /* 2 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 7 */
    gill_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    gill_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    gill_exca_005,  /* 5 follow-up of TATAKI S, TATAKI M +22 */
    gill_exca_006,  /* 6 follow-up of NOKEZORI, UPPER +16 */
    gill_exca_007,  /* 7 follow-up of KUNOJI, HARAYARARE +4 */
    gill_exca_008,  /* 8 follow-up of TATAKI V. S, TATAKI V. M +3 */
    gill_exca_009,  /* 9 follow-up of KIRIMOMI, IBUKI KUBIORI +1 */
    gill_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    gill_exca_010,  /* 11 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 7 */
    gill_exca_012,  /* 12 follow-up of APPEAR JUNBI 4 */
    gill_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    gill_exca_014,  /* 14 no name */
    gill_exca_015,  /* 15 no name */
    gill_exca_016,  /* 16 no name */
    gill_exca_017,  /* 17 no name */
    gill_exca_018,  /* 18 no name */
    gill_exca_019,  /* 19 no name */
    gill_exca_020,  /* 20 no name */
    gill_exca_021,  /* 21 follow-up of IBUKI HARAIG */
    gill_exca_022,  /* 22 follow-up of IBUKI */
    gill_exca_023,  /* 23 follow-up of APPEAR JUNBI 6 */
    gill_exca_024,  /* 24 no name */
    gill_exca_025,  /* 25 follow-up of APPEAR 2 */
    gill_exca_026,  /* 26 follow-up of APPEAR 2 */
    gill_exca_027,  /* 27 follow-up of APPEAR 4 */
    gill_exca_028,  /* 28 follow-up of APPEAR 4 */
    gill_exca_029,  /* 29 no name */
    gill_exca_030,  /* 30 no name */
    gill_exca_031,  /* 31 follow-up of APPEAR 5 */
    gill_exca_032,  /* 32 follow-up of APPEAR 5 */
    gill_exca_031,  /* 33 follow-up of APPEAR 6 */
    gill_exca_032,  /* 34 follow-up of APPEAR 6 */
    gill_exca_035,  /* 35 follow-up of APPEAR 7 */
    gill_exca_036,  /* 36 follow-up of APPEAR 7 */
    gill_exca_037,  /* 37 no name */
    gill_exca_038,  /* 38 no name */
    gill_exca_039,  /* 39 no name */
    gill_exca_039,  /* 40 no name */
    gill_exca_041,  /* 41 no name */
    gill_exca_042,  /* 42 no name */
    gill_exca_043,  /* 43 no name */
    gill_exca_044,  /* 44 no name */
    gill_exca_045,  /* 45 no name */
    gill_exca_046,  /* 46 no name */
    gill_exca_047,  /* 47 no name */
    gill_exca_048,  /* 48 no name */
    gill_exca_049,  /* 49 no name */
    gill_exca_050,  /* 50 no name */
    gill_exca_051,  /* 51 no name */
    gill_exca_052,  /* 52 no name */
    gill_exca_053,  /* 53 no name */
    gill_exca_054,  /* 54 no name */
    gill_exca_055,  /* 55 no name */
    gill_exca_056,  /* 56 no name */
    gill_exca_057,  /* 57 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 gill_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_exca_000[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0115, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0117, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0118, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0119, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011A, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011B, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011D, 0, 83, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x011E, 0, 83, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x011E, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0121, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0122, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0123, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0124, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0125, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0035, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0036, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 7 */
const u16 gill_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_001[68] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 gill_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_003[52] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 gill_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_004[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 1, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, TATAKI M +22 */
const u16 gill_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_005[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, UPPER +16 */
const u16 gill_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_006[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0143, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0144, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0145, 0, 82, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x0146, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0147, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0148, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0149, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, HARAYARARE +4 */
const u16 gill_exca_007_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_007[8] = {
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI V. S, TATAKI V. M +3 */
const u16 gill_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_008[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 32, 93),
    L4(3, 2, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, IBUKI KUBIORI +1 */
const u16 gill_exca_009_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_009[8] = {
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 7 */
const u16 gill_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_010[60] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4 */
const u16 gill_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_012[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 gill_exca_013_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_013[136] = {
    L6(6, 0, 273, 0, 0, 0, 0, 0x0025, 0, 67, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0026, 0, 67, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0027, 0, 67, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0028, 0, 62, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x0010, 0, 63, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0011, 0, 67, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0012, 0, 67, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 gill_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_014[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x013C, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013D, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0117, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0118, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0119, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x011A, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x011B, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x011C, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x011D, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x011E, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 gill_exca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_015[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x014C, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 gill_exca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_016[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0140, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0141, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 gill_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_017[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x0156, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0157, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0141, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0140, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 gill_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_exca_018[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0156, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0157, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0141, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0140, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 gill_exca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 3, 0, 0, 0x0151, 0, 8, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x0153, 0, 8, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 gill_exca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_020[28] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of IBUKI HARAIG */
const u16 gill_exca_021_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_021[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0143, 0, 82, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x0144, 0, 82, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x0145, 0, 82, 0, 0, 0, 0, 0),
    L4(5, 1, 0, 0, 0, 0, 0, 0x0146, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0147, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0148, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0149, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x014A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014B, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014C, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x014D, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x014E, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x014F, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0150, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of IBUKI */
const u16 gill_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_022[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x013F, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0140, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0141, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0142, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02D1, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 6 */
const u16 gill_exca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_023[136] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x0025, 0, 67, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 88, 0), 0x0400, 0x0000, 0x0000, 0x0026,
    CMD(CM_SETR, 24576, 0, 0), 0x0000, 0x0000, 0x0058, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0027, 0, 67, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 88, 0), 0x0200, 0x0000, 0x0000, 0x0028,
    CMD(CM_SPS, -16384, 0, 0), 0x0000, 0x0000, 0x0054, 0x0000,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x0008,
    CMD(CM_DUMMY, 16384, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0240, 0x0000, 0x0000, 0x000A,
    CMD(CM_DUMMY, 16384, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x000C,
    CMD(CM_DUMMY, 16384, 0, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 24 no name */
const u16 gill_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_024[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0145, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0146, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0147, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0148, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0149, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0149, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR 2 */
const u16 gill_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_025[68] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x0007, 0, 104, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 2 */
const u16 gill_exca_026_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_026[60] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x0007, 0, 105, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR 4 */
const u16 gill_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_027[68] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR 4 */
const u16 gill_exca_028_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_028[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 gill_exca_029_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_029[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0146, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0147, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0148, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0149, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x014A, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x014B, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x014D, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 no name */
const u16 gill_exca_030_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 gill_exca_030[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0146, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0147, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0148, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0149, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x014A, 0, 60, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x014B, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x014D, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR 5, 33 follow-up of APPEAR 6 */
const u16 gill_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_031[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x019C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0025, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0026, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0027, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0028, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 5, 34 follow-up of APPEAR 6 */
const u16 gill_exca_032_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_032[88] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of APPEAR 7 */
const u16 gill_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_035[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x019C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0025, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0026, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0027, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0028, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of APPEAR 7 */
const u16 gill_exca_036_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 gill_exca_036[88] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x0007, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0008, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0009, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x000A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x000B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x000C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 no name */
const u16 gill_exca_037_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 gill_exca_037[284] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0115, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0117, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0118, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0119, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011A, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011B, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x011D, 0, 89, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x011E, 0, 89, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x011E, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0121, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0122, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0123, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0124, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0125, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0035, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0036, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0000, 0x0000, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, 8, 0, 0, 0, 0, 3, 33),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, 8, 0, 0, 0, 0, 3, 35),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, 8, 0, 0, 0, 0, 3, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, 8, 0, 0, 0, 0, 3, 39),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, 8, 0, 0, 0, 0, 3, 41),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, 8, 0, 0, 0, 0, 3, 43),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, 8, 0, 0, 0, 0, 3, 45),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, 8, 0, 0, 0, 0, 3, 47),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, 8, 0, 0, 0, 0, 3, 49),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, 8, 0, 0, 0, 0, 3, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, 8, 0, 0, 0, 0, 3, 53),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, 8, 0, 0, 0, 0, 3, 55),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, 8, 0, 0, 0, 0, 3, 57),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, 8, 0, 0, 0, 0, 3, 59),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, 8, 0, 0, 0, 0, 3, 61),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, 8, 0, 0, 0, 0, 3, 63),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 no name */
const u16 gill_exca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_038[132] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0340),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0341),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0342),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0343),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0344),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0345),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0346),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0347),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0348),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0349),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x034F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0350),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0351),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0352),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0353),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0354),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0355),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0356),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0357),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0358),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0359),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x035F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 no name, 40 no name */
const u16 gill_exca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_039[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 no name */
const u16 gill_exca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_041[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02FA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02FB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02FC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02FD),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 gill_exca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_042[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x030C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x030D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x030E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x030F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0310),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0311),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0312),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0313),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0314),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 gill_exca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_043[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x030E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x030F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0310),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0311),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0312),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0313),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0314),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 gill_exca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_044[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0360),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0361),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0362),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0363),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0364),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0365),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0366),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0367),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0368),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0369),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 gill_exca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_045[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x036A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x036B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x036C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x036D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x036E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x036F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 gill_exca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_046[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0370),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0371),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0372),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0373),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0374),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0375),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0376),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0377),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0378),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0379),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 gill_exca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_047[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x037A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x037B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x037C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x037D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x037E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x037F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 gill_exca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_048[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0380),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0381),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0382),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0383),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0384),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0388),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 gill_exca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_049[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0389),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 gill_exca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_050[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x038F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0390),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0384),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0387),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 gill_exca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_051[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0389),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 gill_exca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_052[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0391),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0392),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0393),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0394),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0395),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0396),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0397),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 gill_exca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_053[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0398),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0399),
    L2(4, 0, 0, 0, 0, 0, 0, 0x039A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x039B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x039C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x039D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x039E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 gill_exca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_054[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 gill_exca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_055[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x03A9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03AA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03AB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03AC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03AD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03AE),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 gill_exca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_056[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 gill_exca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_exca_057[24] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x03B9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03BA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03BC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03BD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x03BE),
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 72 entries */
const u16* const gill_saca[73] = {
    gill_saca_000,  /* 0 UP P GUARD P S */
    gill_saca_001,  /* 1 UP P GUARD P M */
    gill_saca_002,  /* 2 UP P GUARD P L */
    gill_saca_002,  /* 3 UP P GUARD K S */
    gill_saca_002,  /* 4 UP P GUARD K M */
    gill_saca_002,  /* 5 UP P GUARD K L */
    gill_saca_000,  /* 6 D P GUARD P S */
    gill_saca_001,  /* 7 D P GUARD P M */
    gill_saca_002,  /* 8 D P GUARD P L */
    gill_saca_002,  /* 9 D P GUARD K S */
    gill_saca_002,  /* 10 D P GUARD K M */
    gill_saca_002,  /* 11 D P GUARD K L */
    gill_saca_002,  /* 12 FUSHIN P S */
    gill_saca_002,  /* 13 FUSHIN P M */
    gill_saca_002,  /* 14 FUSHIN P L */
    gill_saca_002,  /* 15 FUSHIN K S */
    gill_saca_002,  /* 16 FUSHIN K M */
    gill_saca_002,  /* 17 FUSHIN K L */
    gill_saca_002,  /* 18 OKIAGARI P S */
    gill_saca_002,  /* 19 OKIAGARI P M */
    gill_saca_002,  /* 20 OKIAGARI P L */
    gill_saca_002,  /* 21 OKIAGARI K S */
    gill_saca_002,  /* 22 OKIAGARI K M */
    gill_saca_002,  /* 23 OKIAGARI K L */
    gill_saca_024,  /* 24 ATTACK 1 S: not started by a command */
    gill_saca_025,  /* 25 ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    gill_saca_025,  /* 26 ATTACK 1 L: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    gill_saca_025,  /* 27 ATTACK 1 SP: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    gill_saca_025,  /* 28 ATTACK 2 S: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    gill_saca_029,  /* 29 ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    gill_saca_029,  /* 30 ATTACK 2 L: 623+P (routine Att_SLIDE_and_JUMP) */
    gill_saca_029,  /* 31 ATTACK 2 SP: 623+P (routine Att_SLIDE_and_JUMP) */
    gill_saca_029,  /* 32 ATTACK 3 S: 623+P (routine Att_SLIDE_and_JUMP) */
    gill_saca_033,  /* 33 ATTACK 3 M: 236+P light (plain script) */
    gill_saca_034,  /* 34 ATTACK 3 L: 236+P medium (plain script) */
    gill_saca_035,  /* 35 ATTACK 3 SP: 236+P heavy/EX (plain script) */
    gill_saca_035,  /* 36 ATTACK 4 S: 236+P heavy/EX (plain script) */
    gill_saca_037,  /* 37 ATTACK 4 M: not started by a command */
    gill_saca_037,  /* 38 ATTACK 4 L: not started by a command */
    gill_saca_037,  /* 39 ATTACK 4 SP: not started by a command */
    gill_saca_037,  /* 40 ATTACK 5 S: not started by a command */
    gill_saca_041,  /* 41 ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    gill_saca_041,  /* 42 ATTACK 5 L: 214+P (routine Att_SENPUUKYAKU) */
    gill_saca_041,  /* 43 ATTACK 5 SP: 214+P (routine Att_SENPUUKYAKU) */
    gill_saca_041,  /* 44 ATTACK 6 S: 214+P (routine Att_SENPUUKYAKU) */
    gill_saca_045,  /* 45 ATTACK 6 M: not started by a command */
    gill_saca_045,  /* 46 ATTACK 6 L: not started by a command */
    gill_saca_045,  /* 47 ATTACK 6 SP: not started by a command */
    gill_saca_045,  /* 48 ATTACK 7 S: not started by a command */
    gill_saca_049,  /* 49 ATTACK 7 M: not started by a command */
    gill_saca_049,  /* 50 ATTACK 7 L: not started by a command */
    gill_saca_049,  /* 51 ATTACK 7 SP: not started by a command */
    gill_saca_049,  /* 52 ATTACK 8 S: not started by a command */
    gill_saca_053,  /* 53 ATTACK 8 M: SA I (never)+P (routine Att_RESURRECTION); SA II (never)+P (routine Att_RESURRECTION); SA III (never)+P (routine Att_RESURRECTION) */
    gill_saca_054,  /* 54 ATTACK 8 L: not started by a command */
    gill_saca_055,  /* 55 ATTACK 8 SP: not started by a command */
    gill_saca_055,  /* 56 ATTACK 9 S: not started by a command */
    gill_saca_055,  /* 57 ATTACK 9 M: not started by a command */
    gill_saca_058,  /* 58 ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    gill_saca_059,  /* 59 ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    gill_saca_060,  /* 60 ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    gill_saca_061,  /* 61 ATTACK 10 M: not started by a command */
    gill_saca_062,  /* 62 ATTACK 10 L: not started by a command */
    gill_saca_063,  /* 63 ATTACK 10 SP: not started by a command */
    gill_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    gill_saca_065,  /* 65 ATTACK 11 M: not started by a command */
    gill_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    gill_saca_067,  /* 67 ATTACK 11 SP: not started by a command */
    gill_saca_068,  /* 68 ATTACK 12 S: not started by a command */
    gill_saca_069,  /* 69 ATTACK 12 M: not started by a command */
    gill_saca_070,  /* 70 ATTACK 12 L: not started by a command */
    gill_saca_071,  /* 71 ATTACK 12 SP: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 gill_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7070, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7071, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7072, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7073, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7074, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7075, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7076, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7077, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7078, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7079, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x707A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -256, 2304), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 gill_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 gill_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x707A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x7079, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x7079, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7078, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7077, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7076, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7075, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7074, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7073, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7072, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7071, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7070, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 gill_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 gill_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: not started by a command */
const u16 gill_saca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_saca_024[164] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0131, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0211, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0212, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0213, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0214, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 40, 0, 0x0215, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 41, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 42, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 43, 0, 0x0217, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 44, 0, 0x0217, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 45, 0, 0x0218, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 46, 0, 0x0218, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), 26 ATTACK 1 L: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), 27 ATTACK 1 SP: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), 28 ATTACK 2 S: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
const u16 gill_saca_025_head[4] = { HEAD(4, 0, 9, 6, 0, 22, 63) };
const u16 gill_saca_025[260] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 282, 0, 0, 0, 0, 0x0021, 0, 87, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 10, 0x0113, 0, 88, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x0114, 0, 89, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x0115, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x0116, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x0117, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x0118, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x0119, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x011A, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x011B, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x011C, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x011D, 0, 89, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x011E, 0, 89, 0, 0, 0, 0, 0),
    L4(1, 0, 868, 0, 0, 0, 10, 0x011F, 0, 90, 0, 0, 0, 0, 0),
    CMD(CM_SCHY, 0, 4, 1), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 10, 0x0120, -24, 91, 0, 64, 0, 0, 0),
    CMD(CM_SCHY, 0, 1, 12), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x0121, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x0122, -25, 92, 0, 87, 0, 0, 0),
    CMD(CM_SCHY, 0, 8, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_MXYT, 47, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 9, 0x0123, 0, 93, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x0124, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x0125, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0126, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0127, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0035, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0036, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), 30 ATTACK 2 L: 623+P (routine Att_SLIDE_and_JUMP), 31 ATTACK 2 SP: 623+P (routine Att_SLIDE_and_JUMP), 32 ATTACK 3 S: 623+P (routine Att_SLIDE_and_JUMP) */
const u16 gill_saca_029_head[4] = { HEAD(4, 0, 8, 11, 0, 10, 61) };
const u16 gill_saca_029[252] = {
    CMD(CM_RJA, 5, 29, 8), 0, 0, 0, 0,
    L4(4, 0, 278, 0, 0, 0, 0, 0x0021, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 30, 871, 2, 0, 105, 0, 0x0128, -32, 95, 0, 71, 0, 0, 0),
    L4(3, 0, 0, 2, 0, 106, 0, 0x0129, 0, 95, 0, 71, 0, 0, 0),
    L4(1, 0, 0, 2, 0, 106, 0, 0x0129, 0, 121, 0, 64, 0, 0, 0),
    CMD(CM_SSTX, 3, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 107, 0, 0x012A, 0, 96, 0, 0, 0, 30, 22),
    L4(3, 0, 325, 0, 0, 108, 0, 0x012B, -33, 97, 0, 128, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16393, 16386), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 108, 0, 0x012B, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 109, 0, 0x012C, 0, 98, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 110, 0, 0x012D, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 111, 0, 0x012E, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 112, 0, 0x012F, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 113, 0, 0x0130, 0, 98, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 108, 0, 0x012B, 0, 98, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 109, 0, 0x012C, 0, 98, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x012D, 0, 98, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 111, 0, 0x012E, 0, 98, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 112, 0, 0x012F, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 113, 0, 0x0130, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0131, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 236+P light (plain script) */
const u16 gill_saca_033_head[4] = { HEAD(4, 0, 8, 16, 0, 11, 0) };
const u16 gill_saca_033[212] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0230, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0231, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0232, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0233, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0234, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0235, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0236, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0237, 0, 76, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0238, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0239, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0239, 0, 76, 0, 0, 0, 2, 75),
    L4(4, 0, 0, 0, 0, 0, 0, 0x023A, 0, 77, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x023B, 0, 77, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x023C, 0, 77, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x023D, 0, 77, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x023E, 0, 77, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x023F, 0, 78, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0240, 0, 78, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0241, 0, 78, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0242, 0, 79, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0243, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 236+P medium (plain script) */
const u16 gill_saca_034_head[4] = { HEAD(4, 0, 8, 16, 0, 11, 122) };
const u16 gill_saca_034[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0230, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0231, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0232, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0233, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0234, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0244, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0245, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0246, 0, 80, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0247, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0248, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0248, 0, 80, 0, 0, 0, 2, 77),
    CMD(CM_JPSS, 5, 33, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: 236+P heavy/EX (plain script), 36 ATTACK 4 S: 236+P heavy/EX (plain script) */
const u16 gill_saca_035_head[4] = { HEAD(4, 0, 8, 16, 0, 11, 122) };
const u16 gill_saca_035[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0230, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0231, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0232, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0233, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0234, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0249, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x024A, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x024B, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x024C, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x024D, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x024D, 0, 81, 0, 0, 0, 2, 79),
    CMD(CM_JPSS, 5, 33, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: not started by a command, 38 ATTACK 4 L: not started by a command, 39 ATTACK 4 SP: not started by a command, 40 ATTACK 5 S: not started by a command */
const u16 gill_saca_037_head[4] = { HEAD(4, 20, 3, 18, 0, 6, 0) };
const u16 gill_saca_037[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0030, 0, 57, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0031, 0, 57, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 0, 0x0032, -20, 57, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02D2, 20, 54, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02D3, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02D4, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0031, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0032, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0033, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0034, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0036, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU), 42 ATTACK 5 L: 214+P (routine Att_SENPUUKYAKU), 43 ATTACK 5 SP: 214+P (routine Att_SENPUUKYAKU), 44 ATTACK 6 S: 214+P (routine Att_SENPUUKYAKU) */
const u16 gill_saca_041_head[4] = { HEAD(4, 20, 8, 11, 0, 6, 64) };
const u16 gill_saca_041[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0021, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x02D5, 0, 99, 0, 0, 0, 0, 0),
    L4(4, 0, 868, 0, 0, 0, 0, 0x02D6, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02D7, -26, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02D8, 0, 100, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02D9, 0, 101, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0035, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0036, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: not started by a command, 46 ATTACK 6 L: not started by a command, 47 ATTACK 6 SP: not started by a command, 48 ATTACK 7 S: not started by a command */
const u16 gill_saca_045_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 gill_saca_045[280] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0131, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0211, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0212, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0213, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0214, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x0215, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 42, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 42, 0, 0x0216, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 43, 0, 0x0217, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(4, 0, 0, 0, 0, 44, 0, 0x0217, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 45, 0, 0x0218, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0218, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: not started by a command, 50 ATTACK 7 L: not started by a command, 51 ATTACK 7 SP: not started by a command, 52 ATTACK 8 S: not started by a command */
const u16 gill_saca_049_head[4] = { HEAD(4, 0, 0, 11, 0, 9, 33) };
const u16 gill_saca_049[92] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x000F, 0, 176, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x00F6, 0, 60, 0, 0, 0, 22, 20),
    L4(5, 0, 0, 0, 0, 0, 0, 0x00F7, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x00F8, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00F9, -34, 58, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00FA, 0, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00FB, 0, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00FC, 0, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x00FD, 0, 58, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: SA I (never)+P (routine Att_RESURRECTION); SA II (never)+P (routine Att_RESURRECTION); SA III (never)+P (routine Att_RESURRECTION) */
const u16 gill_saca_053_head[4] = { HEAD(6, 0, 48, 0, 0, 0, 0) };
const u16 gill_saca_053[232] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 0, 0, 0, 0, 0, 0x0132, 0, 9, 0, 0, 0, 13, 32, 0, 0, 0, 0, 0),
    L6(6, 0, 874, 0, 0, 0, 0, 0x0133, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0134, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 324, 0, 0, 0, 0, 0x0135, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 326, 0, 0, 0, 0, 0x0211, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0212, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0213, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0214, 0, 9, 0, 0, 0, 14, 1, 0, 0, 0, 0, 0),
    L6(1, 26, 0, 0, 0, 40, 0, 0x0215, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x0216, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 42, 0, 0x0216, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x0216, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 42, 0, 0x0216, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 24, 0, 0, 0, 43, 0, 0x0217, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 44, 0, 0x0217, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 22, 0, 0, 0, 45, 0, 0x0217, 0, 9, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0217, 0, 55, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: not started by a command */
const u16 gill_saca_054_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_saca_054[84] = {
    CMD(CM_RJA, 5, 54, 3), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0218, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 274, 0, 0, 0, 0, 0x0007, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command */
const u16 gill_saca_055_head[4] = { HEAD(4, 1, 0, 0, 0, 0, 0) };
const u16 gill_saca_055[228] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x017B, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02AF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 40, 881, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x02B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x02B1, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B3, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B3, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B2, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x02B3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x02AF, 0, 1, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x017B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x017B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: SA (all arts) 23623+P (plain script) */
const u16 gill_saca_058_head[4] = { HEAD(4, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_058[604] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(4, 0, 879, 0, 1, 0, 0, 0x041E, 0, 125, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x041F, 0, 125, 0, 0, 0, 32, 107),
    L4(1, 0, 0, 0, 1, 0, 0, 0x041F, 0, 126, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x0420, 0, 125, 0, 0, 0, 32, 108),
    CMD(CM_EXEC, 13, 33, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 1, 0, 0, 0x0421, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0422, 0, 125, 0, 0, 0, 0, 0),
    L4(6, 0, 324, 0, 1, 0, 0, 0x0423, 0, 125, 0, 0, 0, 0, 0),
    L4(4, 0, 326, 0, 1, 0, 0, 0x0424, 0, 125, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0425, 0, 125, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x0426, 0, 125, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 140, 0, 0x0427, 0, 125, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 1, 140, 0, 0x0428, 0, 125, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x0429, 0, 125, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 1, 140, 0, 0x0428, 0, 125, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x0429, 0, 1, 0, 0, 0, 2, 87),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042A, 0, 1, 0, 0, 0, 2, 88),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 89),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 90),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 91),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 92),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 93),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 94),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 95),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 96),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 97),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 98),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 99),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 100),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042E, 0, 1, 0, 0, 0, 2, 101),
    L4(3, 0, 0, 0, 1, 139, 0, 0x042F, 0, 1, 0, 0, 0, 2, 102),
    L4(3, 0, 0, 0, 1, 140, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x042E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x042F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 140, 0, 0x0430, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 140, 0, 0x0431, 0, 1, 0, 0, 0, 19, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 141, 0, 0x0432, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 141, 0, 0x0432, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 141, 0, 0x0432, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 141, 0, 0x0432, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0095, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0096, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0097, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0098, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0099, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x009A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x009B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x009C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x009C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
const u16 gill_saca_059_head[4] = { HEAD(6, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_059[352] = {
    CMD(CM_RJA, 5, 60, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x0007, 0, 6, 0, 0, 0, 21, 0, 256, 0, 0, 0, 0),
    L6(5, 20, 0, 0, 0, 0, 0, 0x0484, 0, 145, 0, 0, 0, 22, 20, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0485, 0, 146, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0486, 0, 147, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0487, 0, 148, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(10, 30, 875, 0, 0, 142, 0, 0x0488, 0, 148, 0, 0, 0, 22, 23, 256, 0, 0, 0, 0),
    L6(14, 0, 0, 0, 0, 142, 0, 0x0489, 0, 148, 0, 0, 0, 33, 0, 256, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 895, 1, 0, 143, 0, 0x048A, 0, 0, 0, 0, 0, 13, 51, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 143, 0, 0x048B, 0, 0, 0, 0, 0, 22, 20, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 143, 0, 0x048C, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 143, 0, 0x048D, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 143, 0, 0x048E, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 143, 0, 0x048F, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(20, 0, 0, 1, 0, 143, 0, 0x0490, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_EXEC, 53, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 54, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 2, 155, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 144, 0, 0x0491, 0, 0, 0, 0, 0, 2, 157, 256, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 1, 0, 144, 0, 0x0491, 0, 0, 0, 0, 0, 39, 8, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 144, 0, 0x0492, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 144, 0, 0x0493, 0, 0, 0, 0, 0, 39, 8, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 144, 0, 0x0494, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 144, 0, 0x0495, 0, 0, 0, 0, 0, 39, 8, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 144, 0, 0x0496, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 60, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
const u16 gill_saca_060_head[4] = { HEAD(6, 20, 0, 0, 0, 0, 0) };
const u16 gill_saca_060[256] = {
    L6(1, 0, 894, 1, 0, 145, 0, 0x0496, 0, 0, 0, 0, 0, 21, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 145, 0, 0x0491, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 145, 0, 0x0492, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 145, 0, 0x0493, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 145, 0, 0x0494, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 145, 0, 0x0495, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 145, 0, 0x0496, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x0036, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0037, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 274, 0, 0, 0, 0, 0x0131, 0, 149, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0211, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0212, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0213, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0214, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0010, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: not started by a command */
const u16 gill_saca_061_head[4] = { HEAD(6, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_061[232] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0211, 0, 125, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0212, 0, 125, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0213, 0, 125, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0214, 0, 125, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 20, 0, 0, 0, 0, 8, 0x0215, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 8, 0x0216, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 8, 0x0217, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(32, 30, 0, 0, 0, 0, 8, 0x0218, 0, 0, 0, 0, 0, 13, 51, 256, 0, 0, 0, 0),
    CMD(CM_EXEC, 53, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 54, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 2, 155, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 8, 0x0215, 0, 83, 0, 0, 0, 2, 157, 256, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 8, 0x0216, 0, 83, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 8, 0x0217, 0, 83, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 8, 0x0215, 0, 83, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 60, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: not started by a command */
const u16 gill_saca_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gill_saca_062[116] = {
    CMD(CM_RJA, 5, 60, 3), 0, 0, 0, 0,
    L4(250, 20, 0, 0, 0, 0, 8, 0x0218, 0, 8, 0, 0, 0, 21, 0),
    L4(3, 0, 274, 0, 0, 0, 0, 0x0131, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0211, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0212, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0213, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0214, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0015, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: not started by a command */
const u16 gill_saca_063_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_063[108] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0007),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0484),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0485),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0486),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0487),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0488),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0489),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x048F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0490),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0491),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0492),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0493),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0494),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0495),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0496),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0491),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0492),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0493),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0494),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0495),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0496),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command */
const u16 gill_saca_064_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_064[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x049D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x049E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x049F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: not started by a command */
const u16 gill_saca_065_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_065[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04A9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04AF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command */
const u16 gill_saca_066_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_066[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04B9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04BF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: not started by a command */
const u16 gill_saca_067_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_067[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04C9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04CF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: not started by a command */
const u16 gill_saca_068_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_068[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: not started by a command */
const u16 gill_saca_069_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_069[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: not started by a command */
const u16 gill_saca_070_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_070[88] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04DF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04E9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04ED),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: not started by a command */
const u16 gill_saca_071_head[4] = { HEAD(2, 0, 64, 0, 0, 0, 0) };
const u16 gill_saca_071[88] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x04EE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04EF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04F9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x04FF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0500),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0501),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0502),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 17 entries */
const u16* const gill_cbca[18] = {
    gill_cbca_000,  /* 0 APPEAR JUNBI 1 */
    gill_cbca_001,  /* 1 APPEAR JUNBI 2 */
    gill_cbca_002,  /* 2 APPEAR JUNBI 3 */
    gill_cbca_003,  /* 3 APPEAR JUNBI 4 */
    gill_cbca_004,  /* 4 APPEAR JUNBI 5 */
    gill_cbca_005,  /* 5 APPEAR JUNBI 6 */
    gill_cbca_006,  /* 6 APPEAR JUNBI 7 */
    gill_cbca_007,  /* 7 APPEAR JUNBI 8 */
    gill_cbca_008,  /* 8 APPEAR 1 */
    gill_cbca_009,  /* 9 APPEAR 2 */
    gill_cbca_010,  /* 10 APPEAR 3 */
    gill_cbca_011,  /* 11 APPEAR 4 */
    gill_cbca_012,  /* 12 APPEAR 5 */
    gill_cbca_013,  /* 13 APPEAR 6 */
    gill_cbca_014,  /* 14 APPEAR 7 */
    gill_cbca_015,  /* 15 APPEAR 8 */
    gill_cbca_016,  /* 16 SP APPEAR 1 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 gill_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 gill_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 gill_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 gill_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 gill_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_004[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 gill_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 13, 1),
    CMD(CM_RJA3, 7, 23, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 gill_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 gill_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_007[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 gill_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_008[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 gill_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_009[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 gill_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_010[20] = {
    CMD(CM_RJA, 5, 54, 1),
    CMD(CM_IMGS, 0, 10, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 gill_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 gill_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_012[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 32, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 gill_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_013[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 gill_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_014[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 36, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 gill_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_015[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -60, 60, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 gill_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gill_cbca_016[12] = {
    CMD(CM_EXEC, 51, 52, 0),
    CMD(CM_STOP, -1, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

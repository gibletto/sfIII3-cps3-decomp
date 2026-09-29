/*
 * SEAN_CHAR.C  Sean's animation scripts and sprite part tables
 *
 * The animation scripts Sean's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 sean_nmca_000[], sean_nmca_001[], sean_nmca_002[], sean_nmca_003[], sean_nmca_004[], sean_nmca_005[], sean_nmca_006[], sean_nmca_007[], sean_nmca_008[], sean_nmca_011[], sean_nmca_012[], sean_nmca_013[], sean_nmca_014[], sean_nmca_015[], sean_nmca_016[], sean_nmca_017[], sean_nmca_020[], sean_nmca_021[], sean_nmca_022[], sean_nmca_023[], sean_nmca_024[], sean_nmca_026[], sean_nmca_027[], sean_nmca_029[], sean_nmca_030[], sean_nmca_031[], sean_nmca_032[], sean_nmca_033[], sean_nmca_038[], sean_nmca_040[], sean_nmca_041[], sean_nmca_043[], sean_nmca_044[], sean_nmca_045[], sean_nmca_046[], sean_nmca_047[], sean_nmca_048[], sean_nmca_049[], sean_nmca_050[];
extern const u16 sean_nmca_000_head[];
extern const u16 sean_nmca_001_head[];
extern const u16 sean_nmca_002_head[];
extern const u16 sean_nmca_003_head[];
extern const u16 sean_nmca_004_head[];
extern const u16 sean_nmca_005_head[];
extern const u16 sean_nmca_006_head[];
extern const u16 sean_nmca_007_head[];
extern const u16 sean_nmca_008_head[];
extern const u16 sean_nmca_011_head[];
extern const u16 sean_nmca_012_head[];
extern const u16 sean_nmca_013_head[];
extern const u16 sean_nmca_014_head[];
extern const u16 sean_nmca_015_head[];
extern const u16 sean_nmca_016_head[];
extern const u16 sean_nmca_017_head[];
extern const u16 sean_nmca_020_head[];
extern const u16 sean_nmca_021_head[];
extern const u16 sean_nmca_022_head[];
extern const u16 sean_nmca_023_head[];
extern const u16 sean_nmca_024_head[];
extern const u16 sean_nmca_026_head[];
extern const u16 sean_nmca_027_head[];
extern const u16 sean_nmca_029_head[];
extern const u16 sean_nmca_030_head[];
extern const u16 sean_nmca_031_head[];
extern const u16 sean_nmca_032_head[];
extern const u16 sean_nmca_033_head[];
extern const u16 sean_nmca_038_head[];
extern const u16 sean_nmca_040_head[];
extern const u16 sean_nmca_041_head[];
extern const u16 sean_nmca_043_head[];
extern const u16 sean_nmca_044_head[];
extern const u16 sean_nmca_045_head[];
extern const u16 sean_nmca_046_head[];
extern const u16 sean_nmca_047_head[];
extern const u16 sean_nmca_048_head[];
extern const u16 sean_nmca_049_head[];
extern const u16 sean_nmca_050_head[];
extern const u16 sean_dmca_000[], sean_dmca_001[], sean_dmca_002[], sean_dmca_003[], sean_dmca_004[], sean_dmca_006[], sean_dmca_008[], sean_dmca_009[], sean_dmca_010[], sean_dmca_014[], sean_dmca_015[], sean_dmca_018[], sean_dmca_019[], sean_dmca_022[], sean_dmca_025[], sean_dmca_026[], sean_dmca_024[], sean_dmca_029[], sean_dmca_030[], sean_dmca_034[], sean_dmca_036[], sean_dmca_048[], sean_dmca_049[], sean_dmca_050[], sean_dmca_052[], sean_dmca_060[], sean_dmca_064[], sean_dmca_065[], sean_dmca_066[], sean_dmca_067[], sean_dmca_068[], sean_dmca_070[], sean_dmca_071[], sean_dmca_072[], sean_dmca_073[], sean_dmca_074[], sean_dmca_075[], sean_dmca_076[], sean_dmca_078[], sean_dmca_079[], sean_dmca_080[], sean_dmca_082[], sean_dmca_083[], sean_dmca_084[], sean_dmca_090[], sean_dmca_091[], sean_dmca_096[], sean_dmca_097[];
extern const u16 sean_dmca_000_head[];
extern const u16 sean_dmca_001_head[];
extern const u16 sean_dmca_002_head[];
extern const u16 sean_dmca_003_head[];
extern const u16 sean_dmca_004_head[];
extern const u16 sean_dmca_006_head[];
extern const u16 sean_dmca_008_head[];
extern const u16 sean_dmca_009_head[];
extern const u16 sean_dmca_010_head[];
extern const u16 sean_dmca_014_head[];
extern const u16 sean_dmca_015_head[];
extern const u16 sean_dmca_018_head[];
extern const u16 sean_dmca_019_head[];
extern const u16 sean_dmca_022_head[];
extern const u16 sean_dmca_025_head[];
extern const u16 sean_dmca_026_head[];
extern const u16 sean_dmca_024_head[];
extern const u16 sean_dmca_029_head[];
extern const u16 sean_dmca_030_head[];
extern const u16 sean_dmca_034_head[];
extern const u16 sean_dmca_036_head[];
extern const u16 sean_dmca_048_head[];
extern const u16 sean_dmca_049_head[];
extern const u16 sean_dmca_050_head[];
extern const u16 sean_dmca_052_head[];
extern const u16 sean_dmca_060_head[];
extern const u16 sean_dmca_064_head[];
extern const u16 sean_dmca_065_head[];
extern const u16 sean_dmca_066_head[];
extern const u16 sean_dmca_067_head[];
extern const u16 sean_dmca_068_head[];
extern const u16 sean_dmca_070_head[];
extern const u16 sean_dmca_071_head[];
extern const u16 sean_dmca_072_head[];
extern const u16 sean_dmca_073_head[];
extern const u16 sean_dmca_074_head[];
extern const u16 sean_dmca_075_head[];
extern const u16 sean_dmca_076_head[];
extern const u16 sean_dmca_078_head[];
extern const u16 sean_dmca_079_head[];
extern const u16 sean_dmca_080_head[];
extern const u16 sean_dmca_082_head[];
extern const u16 sean_dmca_083_head[];
extern const u16 sean_dmca_084_head[];
extern const u16 sean_dmca_090_head[];
extern const u16 sean_dmca_091_head[];
extern const u16 sean_dmca_096_head[];
extern const u16 sean_dmca_097_head[];
extern const u16 sean_btca_000[], sean_btca_001[], sean_btca_002[], sean_btca_003[], sean_btca_004[], sean_btca_005[], sean_btca_006[], sean_btca_007[], sean_btca_008[], sean_btca_009[], sean_btca_010[], sean_btca_011[], sean_btca_012[], sean_btca_013[], sean_btca_014[], sean_btca_015[], sean_btca_016[], sean_btca_017[], sean_btca_018[], sean_btca_019[], sean_btca_020[], sean_btca_021[], sean_btca_022[], sean_btca_023[], sean_btca_024[], sean_btca_025[], sean_btca_026[], sean_btca_027[], sean_btca_028[], sean_btca_029[], sean_btca_030[], sean_btca_031[], sean_btca_032[], sean_btca_033[], sean_btca_034[], sean_btca_035[];
extern const u16 sean_btca_000_head[];
extern const u16 sean_btca_001_head[];
extern const u16 sean_btca_002_head[];
extern const u16 sean_btca_003_head[];
extern const u16 sean_btca_004_head[];
extern const u16 sean_btca_005_head[];
extern const u16 sean_btca_006_head[];
extern const u16 sean_btca_007_head[];
extern const u16 sean_btca_008_head[];
extern const u16 sean_btca_009_head[];
extern const u16 sean_btca_010_head[];
extern const u16 sean_btca_011_head[];
extern const u16 sean_btca_012_head[];
extern const u16 sean_btca_013_head[];
extern const u16 sean_btca_014_head[];
extern const u16 sean_btca_015_head[];
extern const u16 sean_btca_016_head[];
extern const u16 sean_btca_017_head[];
extern const u16 sean_btca_018_head[];
extern const u16 sean_btca_019_head[];
extern const u16 sean_btca_020_head[];
extern const u16 sean_btca_021_head[];
extern const u16 sean_btca_022_head[];
extern const u16 sean_btca_023_head[];
extern const u16 sean_btca_024_head[];
extern const u16 sean_btca_025_head[];
extern const u16 sean_btca_026_head[];
extern const u16 sean_btca_027_head[];
extern const u16 sean_btca_028_head[];
extern const u16 sean_btca_029_head[];
extern const u16 sean_btca_030_head[];
extern const u16 sean_btca_031_head[];
extern const u16 sean_btca_032_head[];
extern const u16 sean_btca_033_head[];
extern const u16 sean_btca_034_head[];
extern const u16 sean_btca_035_head[];
extern const u16 sean_caca_000[], sean_caca_002[], sean_caca_004[], sean_caca_008[], sean_caca_009[], sean_caca_010[], sean_caca_012[], sean_caca_014[], sean_caca_018[];
extern const u16 sean_caca_000_head[];
extern const u16 sean_caca_002_head[];
extern const u16 sean_caca_004_head[];
extern const u16 sean_caca_008_head[];
extern const u16 sean_caca_009_head[];
extern const u16 sean_caca_010_head[];
extern const u16 sean_caca_012_head[];
extern const u16 sean_caca_014_head[];
extern const u16 sean_caca_018_head[];
extern const u16 sean_cuca_000[], sean_cuca_001[], sean_cuca_002[], sean_cuca_003[], sean_cuca_004[], sean_cuca_005[], sean_cuca_006[], sean_cuca_007[], sean_cuca_008[], sean_cuca_009[], sean_cuca_010[], sean_cuca_011[], sean_cuca_012[], sean_cuca_013[], sean_cuca_014[], sean_cuca_015[], sean_cuca_016[], sean_cuca_017[], sean_cuca_018[], sean_cuca_019[], sean_cuca_020[], sean_cuca_021[], sean_cuca_022[], sean_cuca_023[], sean_cuca_024[], sean_cuca_025[], sean_cuca_026[], sean_cuca_027[], sean_cuca_028[], sean_cuca_029[], sean_cuca_030[], sean_cuca_031[], sean_cuca_032[], sean_cuca_033[], sean_cuca_034[], sean_cuca_035[], sean_cuca_036[], sean_cuca_037[], sean_cuca_038[], sean_cuca_039[], sean_cuca_040[], sean_cuca_041[], sean_cuca_042[], sean_cuca_043[], sean_cuca_044[], sean_cuca_045[], sean_cuca_046[], sean_cuca_047[], sean_cuca_048[], sean_cuca_049[], sean_cuca_050[], sean_cuca_051[], sean_cuca_052[], sean_cuca_053[], sean_cuca_054[], sean_cuca_055[], sean_cuca_056[], sean_cuca_057[], sean_cuca_058[], sean_cuca_059[], sean_cuca_060[], sean_cuca_061[], sean_cuca_062[], sean_cuca_063[], sean_cuca_064[], sean_cuca_065[], sean_cuca_066[], sean_cuca_067[];
extern const u16 sean_cuca_000_head[];
extern const u16 sean_cuca_001_head[];
extern const u16 sean_cuca_002_head[];
extern const u16 sean_cuca_003_head[];
extern const u16 sean_cuca_004_head[];
extern const u16 sean_cuca_005_head[];
extern const u16 sean_cuca_006_head[];
extern const u16 sean_cuca_007_head[];
extern const u16 sean_cuca_008_head[];
extern const u16 sean_cuca_009_head[];
extern const u16 sean_cuca_010_head[];
extern const u16 sean_cuca_011_head[];
extern const u16 sean_cuca_012_head[];
extern const u16 sean_cuca_013_head[];
extern const u16 sean_cuca_014_head[];
extern const u16 sean_cuca_015_head[];
extern const u16 sean_cuca_016_head[];
extern const u16 sean_cuca_017_head[];
extern const u16 sean_cuca_018_head[];
extern const u16 sean_cuca_019_head[];
extern const u16 sean_cuca_020_head[];
extern const u16 sean_cuca_021_head[];
extern const u16 sean_cuca_022_head[];
extern const u16 sean_cuca_023_head[];
extern const u16 sean_cuca_024_head[];
extern const u16 sean_cuca_025_head[];
extern const u16 sean_cuca_026_head[];
extern const u16 sean_cuca_027_head[];
extern const u16 sean_cuca_028_head[];
extern const u16 sean_cuca_029_head[];
extern const u16 sean_cuca_030_head[];
extern const u16 sean_cuca_031_head[];
extern const u16 sean_cuca_032_head[];
extern const u16 sean_cuca_033_head[];
extern const u16 sean_cuca_034_head[];
extern const u16 sean_cuca_035_head[];
extern const u16 sean_cuca_036_head[];
extern const u16 sean_cuca_037_head[];
extern const u16 sean_cuca_038_head[];
extern const u16 sean_cuca_039_head[];
extern const u16 sean_cuca_040_head[];
extern const u16 sean_cuca_041_head[];
extern const u16 sean_cuca_042_head[];
extern const u16 sean_cuca_043_head[];
extern const u16 sean_cuca_044_head[];
extern const u16 sean_cuca_045_head[];
extern const u16 sean_cuca_046_head[];
extern const u16 sean_cuca_047_head[];
extern const u16 sean_cuca_048_head[];
extern const u16 sean_cuca_049_head[];
extern const u16 sean_cuca_050_head[];
extern const u16 sean_cuca_051_head[];
extern const u16 sean_cuca_052_head[];
extern const u16 sean_cuca_053_head[];
extern const u16 sean_cuca_054_head[];
extern const u16 sean_cuca_055_head[];
extern const u16 sean_cuca_056_head[];
extern const u16 sean_cuca_057_head[];
extern const u16 sean_cuca_058_head[];
extern const u16 sean_cuca_059_head[];
extern const u16 sean_cuca_060_head[];
extern const u16 sean_cuca_061_head[];
extern const u16 sean_cuca_062_head[];
extern const u16 sean_cuca_063_head[];
extern const u16 sean_cuca_064_head[];
extern const u16 sean_cuca_065_head[];
extern const u16 sean_cuca_066_head[];
extern const u16 sean_cuca_067_head[];
extern const u16 sean_atca_000[], sean_atca_003[], sean_atca_004[], sean_atca_006[], sean_atca_007[], sean_atca_008[], sean_atca_009[], sean_atca_012[], sean_atca_015[], sean_atca_016[], sean_atca_017[], sean_atca_018[], sean_atca_021[], sean_atca_024[], sean_atca_027[], sean_atca_030[], sean_atca_033[], sean_atca_036[], sean_atca_038[], sean_atca_040[], sean_atca_042[], sean_atca_044[], sean_atca_046[], sean_atca_048[], sean_atca_050[], sean_atca_052[], sean_atca_054[], sean_atca_056[], sean_atca_058[], sean_atca_060[], sean_atca_062[], sean_atca_064[], sean_atca_066[], sean_atca_068[], sean_atca_070[], sean_atca_072[], sean_atca_074[], sean_atca_076[], sean_atca_078[], sean_atca_080[], sean_atca_082[], sean_atca_084[], sean_atca_086[], sean_atca_088[], sean_atca_090[], sean_atca_092[], sean_atca_094[], sean_atca_096[], sean_atca_098[], sean_atca_100[], sean_atca_102[], sean_atca_104[], sean_atca_106[], sean_atca_108[], sean_atca_110[], sean_atca_112[], sean_atca_114[], sean_atca_116[], sean_atca_118[], sean_atca_144[], sean_atca_146[], sean_atca_156[], sean_atca_157[];
extern const u16 sean_atca_000_head[];
extern const u16 sean_atca_003_head[];
extern const u16 sean_atca_004_head[];
extern const u16 sean_atca_006_head[];
extern const u16 sean_atca_007_head[];
extern const u16 sean_atca_008_head[];
extern const u16 sean_atca_009_head[];
extern const u16 sean_atca_012_head[];
extern const u16 sean_atca_015_head[];
extern const u16 sean_atca_016_head[];
extern const u16 sean_atca_017_head[];
extern const u16 sean_atca_018_head[];
extern const u16 sean_atca_021_head[];
extern const u16 sean_atca_024_head[];
extern const u16 sean_atca_027_head[];
extern const u16 sean_atca_030_head[];
extern const u16 sean_atca_033_head[];
extern const u16 sean_atca_036_head[];
extern const u16 sean_atca_038_head[];
extern const u16 sean_atca_040_head[];
extern const u16 sean_atca_042_head[];
extern const u16 sean_atca_044_head[];
extern const u16 sean_atca_046_head[];
extern const u16 sean_atca_048_head[];
extern const u16 sean_atca_050_head[];
extern const u16 sean_atca_052_head[];
extern const u16 sean_atca_054_head[];
extern const u16 sean_atca_056_head[];
extern const u16 sean_atca_058_head[];
extern const u16 sean_atca_060_head[];
extern const u16 sean_atca_062_head[];
extern const u16 sean_atca_064_head[];
extern const u16 sean_atca_066_head[];
extern const u16 sean_atca_068_head[];
extern const u16 sean_atca_070_head[];
extern const u16 sean_atca_072_head[];
extern const u16 sean_atca_074_head[];
extern const u16 sean_atca_076_head[];
extern const u16 sean_atca_078_head[];
extern const u16 sean_atca_080_head[];
extern const u16 sean_atca_082_head[];
extern const u16 sean_atca_084_head[];
extern const u16 sean_atca_086_head[];
extern const u16 sean_atca_088_head[];
extern const u16 sean_atca_090_head[];
extern const u16 sean_atca_092_head[];
extern const u16 sean_atca_094_head[];
extern const u16 sean_atca_096_head[];
extern const u16 sean_atca_098_head[];
extern const u16 sean_atca_100_head[];
extern const u16 sean_atca_102_head[];
extern const u16 sean_atca_104_head[];
extern const u16 sean_atca_106_head[];
extern const u16 sean_atca_108_head[];
extern const u16 sean_atca_110_head[];
extern const u16 sean_atca_112_head[];
extern const u16 sean_atca_114_head[];
extern const u16 sean_atca_116_head[];
extern const u16 sean_atca_118_head[];
extern const u16 sean_atca_144_head[];
extern const u16 sean_atca_146_head[];
extern const u16 sean_atca_156_head[];
extern const u16 sean_atca_157_head[];
extern const u16 sean_exca_000[], sean_exca_001[], sean_exca_003[], sean_exca_004[], sean_exca_005[], sean_exca_006[], sean_exca_007[], sean_exca_008[], sean_exca_009[], sean_exca_010[], sean_exca_011[], sean_exca_013[], sean_exca_014[], sean_exca_015[], sean_exca_016[], sean_exca_017[], sean_exca_018[], sean_exca_019[], sean_exca_020[], sean_exca_021[], sean_exca_022[], sean_exca_023[], sean_exca_024[], sean_exca_025[], sean_exca_026[], sean_exca_028[], sean_exca_029[], sean_exca_030[], sean_exca_031[], sean_exca_032[], sean_exca_033[], sean_exca_034[], sean_exca_035[], sean_exca_036[], sean_exca_037[], sean_exca_038[], sean_exca_039[], sean_exca_040[], sean_exca_041[], sean_exca_042[], sean_exca_043[], sean_exca_044[], sean_exca_047[], sean_exca_048[], sean_exca_049[], sean_exca_050[], sean_exca_051[];
extern const u16 sean_exca_000_head[];
extern const u16 sean_exca_001_head[];
extern const u16 sean_exca_003_head[];
extern const u16 sean_exca_004_head[];
extern const u16 sean_exca_005_head[];
extern const u16 sean_exca_006_head[];
extern const u16 sean_exca_007_head[];
extern const u16 sean_exca_008_head[];
extern const u16 sean_exca_009_head[];
extern const u16 sean_exca_010_head[];
extern const u16 sean_exca_011_head[];
extern const u16 sean_exca_013_head[];
extern const u16 sean_exca_014_head[];
extern const u16 sean_exca_015_head[];
extern const u16 sean_exca_016_head[];
extern const u16 sean_exca_017_head[];
extern const u16 sean_exca_018_head[];
extern const u16 sean_exca_019_head[];
extern const u16 sean_exca_020_head[];
extern const u16 sean_exca_021_head[];
extern const u16 sean_exca_022_head[];
extern const u16 sean_exca_023_head[];
extern const u16 sean_exca_024_head[];
extern const u16 sean_exca_025_head[];
extern const u16 sean_exca_026_head[];
extern const u16 sean_exca_028_head[];
extern const u16 sean_exca_029_head[];
extern const u16 sean_exca_030_head[];
extern const u16 sean_exca_031_head[];
extern const u16 sean_exca_032_head[];
extern const u16 sean_exca_033_head[];
extern const u16 sean_exca_034_head[];
extern const u16 sean_exca_035_head[];
extern const u16 sean_exca_036_head[];
extern const u16 sean_exca_037_head[];
extern const u16 sean_exca_038_head[];
extern const u16 sean_exca_039_head[];
extern const u16 sean_exca_040_head[];
extern const u16 sean_exca_041_head[];
extern const u16 sean_exca_042_head[];
extern const u16 sean_exca_043_head[];
extern const u16 sean_exca_044_head[];
extern const u16 sean_exca_047_head[];
extern const u16 sean_exca_048_head[];
extern const u16 sean_exca_049_head[];
extern const u16 sean_exca_050_head[];
extern const u16 sean_exca_051_head[];
extern const u16 sean_saca_000[], sean_saca_001[], sean_saca_002[], sean_saca_024[], sean_saca_025[], sean_saca_026[], sean_saca_027[], sean_saca_028[], sean_saca_029[], sean_saca_030[], sean_saca_031[], sean_saca_032[], sean_saca_035[], sean_saca_036[], sean_saca_040[], sean_saca_044[], sean_saca_048[], sean_saca_049[], sean_saca_050[], sean_saca_052[], sean_saca_056[], sean_saca_060[], sean_saca_064[], sean_saca_065[], sean_saca_066[], sean_saca_067[], sean_saca_068[], sean_saca_069[], sean_saca_071[];
extern const u16 sean_saca_000_head[];
extern const u16 sean_saca_001_head[];
extern const u16 sean_saca_002_head[];
extern const u16 sean_saca_024_head[];
extern const u16 sean_saca_025_head[];
extern const u16 sean_saca_026_head[];
extern const u16 sean_saca_027_head[];
extern const u16 sean_saca_028_head[];
extern const u16 sean_saca_029_head[];
extern const u16 sean_saca_030_head[];
extern const u16 sean_saca_031_head[];
extern const u16 sean_saca_032_head[];
extern const u16 sean_saca_035_head[];
extern const u16 sean_saca_036_head[];
extern const u16 sean_saca_040_head[];
extern const u16 sean_saca_044_head[];
extern const u16 sean_saca_048_head[];
extern const u16 sean_saca_049_head[];
extern const u16 sean_saca_050_head[];
extern const u16 sean_saca_052_head[];
extern const u16 sean_saca_056_head[];
extern const u16 sean_saca_060_head[];
extern const u16 sean_saca_064_head[];
extern const u16 sean_saca_065_head[];
extern const u16 sean_saca_066_head[];
extern const u16 sean_saca_067_head[];
extern const u16 sean_saca_068_head[];
extern const u16 sean_saca_069_head[];
extern const u16 sean_saca_071_head[];
extern const u16 sean_cbca_000[], sean_cbca_001[], sean_cbca_002[], sean_cbca_003[], sean_cbca_004[], sean_cbca_005[], sean_cbca_006[], sean_cbca_007[], sean_cbca_008[], sean_cbca_009[], sean_cbca_010[], sean_cbca_011[], sean_cbca_012[], sean_cbca_013[], sean_cbca_014[], sean_cbca_015[], sean_cbca_016[], sean_cbca_017[], sean_cbca_018[], sean_cbca_019[], sean_cbca_020[], sean_cbca_021[], sean_cbca_022[], sean_cbca_023[], sean_cbca_024[], sean_cbca_025[], sean_cbca_026[], sean_cbca_027[], sean_cbca_028[], sean_cbca_029[], sean_cbca_030[], sean_cbca_031[], sean_cbca_032[], sean_cbca_033[];
extern const u16 sean_cbca_000_head[];
extern const u16 sean_cbca_001_head[];
extern const u16 sean_cbca_002_head[];
extern const u16 sean_cbca_003_head[];
extern const u16 sean_cbca_004_head[];
extern const u16 sean_cbca_005_head[];
extern const u16 sean_cbca_006_head[];
extern const u16 sean_cbca_007_head[];
extern const u16 sean_cbca_008_head[];
extern const u16 sean_cbca_009_head[];
extern const u16 sean_cbca_010_head[];
extern const u16 sean_cbca_011_head[];
extern const u16 sean_cbca_012_head[];
extern const u16 sean_cbca_013_head[];
extern const u16 sean_cbca_014_head[];
extern const u16 sean_cbca_015_head[];
extern const u16 sean_cbca_016_head[];
extern const u16 sean_cbca_017_head[];
extern const u16 sean_cbca_018_head[];
extern const u16 sean_cbca_019_head[];
extern const u16 sean_cbca_020_head[];
extern const u16 sean_cbca_021_head[];
extern const u16 sean_cbca_022_head[];
extern const u16 sean_cbca_023_head[];
extern const u16 sean_cbca_024_head[];
extern const u16 sean_cbca_025_head[];
extern const u16 sean_cbca_026_head[];
extern const u16 sean_cbca_027_head[];
extern const u16 sean_cbca_028_head[];
extern const u16 sean_cbca_029_head[];
extern const u16 sean_cbca_030_head[];
extern const u16 sean_cbca_031_head[];
extern const u16 sean_cbca_032_head[];
extern const u16 sean_cbca_033_head[];

/* normal scripts: 51 entries */
const u16* const sean_nmca[52] = {
    sean_nmca_000,  /* 0 KAMAE */
    sean_nmca_001,  /* 1 HURIMUKI */
    sean_nmca_002,  /* 2 FRONT WALK */
    sean_nmca_003,  /* 3 BACK WALK */
    sean_nmca_004,  /* 4 DASH HUMIKOMI */
    sean_nmca_005,  /* 5 DASH TOBINOKI */
    sean_nmca_006,  /* 6 KAGAMU */
    sean_nmca_007,  /* 7 KAGAMI KAMAE */
    sean_nmca_008,  /* 8 KAGAMI TURN */
    sean_nmca_008,  /* 9 KAGAMI F WALK */
    sean_nmca_008,  /* 10 KAGAMI B WALK */
    sean_nmca_011,  /* 11 STAND UP */
    sean_nmca_012,  /* 12 JUMP JUNBI */
    sean_nmca_013,  /* 13 SP JUMP JUNBI */
    sean_nmca_014,  /* 14 JUMP FRONT */
    sean_nmca_015,  /* 15 JUMP VERTICAL */
    sean_nmca_016,  /* 16 JUMP BACK */
    sean_nmca_017,  /* 17 S JUMP FRONT */
    sean_nmca_017,  /* 18 S JUMP V */
    sean_nmca_017,  /* 19 S JUMP BACK */
    sean_nmca_020,  /* 20 SP JUMP FRONT */
    sean_nmca_021,  /* 21 SP JUMP V */
    sean_nmca_022,  /* 22 SP JUMP BACK */
    sean_nmca_023,  /* 23 WALK END */
    sean_nmca_024,  /* 24 PARING HEAD */
    sean_nmca_024,  /* 25 PARING UP */
    sean_nmca_026,  /* 26 PARING DOWN */
    sean_nmca_027,  /* 27 PARING AIR F */
    sean_nmca_027,  /* 28 PARING AIR B */
    sean_nmca_029,  /* 29 GUARD HEAD */
    sean_nmca_030,  /* 30 GUARD UP */
    sean_nmca_031,  /* 31 GUARD DOWN */
    sean_nmca_032,  /* 32 GUARD AIR */
    sean_nmca_033,  /* 33 no name */
    sean_nmca_033,  /* 34 no name */
    sean_nmca_033,  /* 35 no name */
    sean_nmca_033,  /* 36 no name */
    sean_nmca_033,  /* 37 no name */
    sean_nmca_038,  /* 38 P BREAK ZUJOU */
    sean_nmca_038,  /* 39 P BREAK UP */
    sean_nmca_040,  /* 40 P BREAK DOWN */
    sean_nmca_041,  /* 41 P BREAK AIR F */
    sean_nmca_041,  /* 42 P BREAK AIR R */
    sean_nmca_043,  /* 43 TUKAMIHAZUSI */
    sean_nmca_044,  /* 44 TUKAMIHAZUSARE */
    sean_nmca_045,  /* 45 TUKAMIHAZUSI */
    sean_nmca_046,  /* 46 TUKAMIHAZUSARE */
    sean_nmca_047,  /* 47 no name */
    sean_nmca_048,  /* 48 no name */
    sean_nmca_049,  /* 49 no name */
    sean_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 sean_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_000[92] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4802, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4803, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4804, 0, 237, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4805, 0, 237, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4806, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4807, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4808, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4809, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x480A, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4801, 0, 238, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 sean_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_001[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x480B, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x480C, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 sean_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 sean_nmca_002[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4810, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4811, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4812, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4813, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4814, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4815, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4816, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4817, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4818, 0, 242, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4819, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x481A, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 sean_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 sean_nmca_003[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x481C, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x481D, 0, 244, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x481E, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x481F, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4820, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4821, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4822, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4823, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4824, 0, 246, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4825, 0, 247, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4826, 0, 247, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 sean_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 sean_nmca_004[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(4, 1, 277, 0, 0, 0, 0, 0x4870, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4871, 0, 258, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x4872, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x4873, 0, 260, 0, 0, 33, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4874, 0, 260, 0, 0, 33, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4875, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4875, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 sean_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 sean_nmca_005[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 10, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4876, 0, 261, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x4877, 0, 262, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4878, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4879, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x487A, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x487A, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x487B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x487B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 sean_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_nmca_006[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4828, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x482A, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x482B, 0, 248, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 sean_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_nmca_007[52] = {
    L4(12, 0, 0, 0, 0, 0, 0, 0x482C, 0, 270, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x4830, 0, 270, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x4831, 0, 271, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4832, 0, 271, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x4833, 0, 271, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 sean_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_nmca_008[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x483A, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x483B, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x483C, 0, 249, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 sean_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_nmca_011[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x482D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 sean_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x4829, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4829, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4829, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 sean_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_013[20] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x4829, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4829, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 sean_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_nmca_014[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x484C, 0, 250, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x484D, 0, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x4853, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4854, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4855, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 sean_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 sean_nmca_015[156] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x4840, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4841, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x486A, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4840, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4841, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x486A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x4842, 0, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x4843, 0, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4844, 0, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4845, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4846, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x4847, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4848, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x486B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 sean_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x4854, 0, 253, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4853, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x484D, 0, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484C, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4858, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 sean_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 sean_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 9),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 sean_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 sean_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(14, 0, 282, 0, 0, 0, 0, 0x484C, 0, 250, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 6, 0x484D, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x4853, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4854, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4855, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 sean_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 sean_nmca_021[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x4840, 0, 4, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4841, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x486A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4840, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4841, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x486A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x4842, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4843, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4844, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4845, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4846, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4847, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4848, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x486B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 sean_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 sean_nmca_022[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(14, 0, 282, 0, 0, 0, 0, 0x4854, 0, 253, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4853, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x484D, 0, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484C, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4858, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 sean_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 sean_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 sean_nmca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_024[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x4977, 0, 9, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 485, 0, 0, 0, 0, 0x4978, 0, 10, 0, 0, 0, 6, 0, 0, 0, 14, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4979, 0, 10, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x497A, 0, 10, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x4949, 0, 9, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 sean_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 sean_nmca_026[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x4BE0, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 485, 0, 0, 0, 0, 0x4BE1, 0, 2, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4BE2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4BE3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 sean_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_nmca_027[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x4868, 0, 4, 0, 0, 0, 18, 6),
    L4(250, 0, 485, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x486C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4846, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4847, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4848, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x486B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 sean_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 sean_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x485A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x485B, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x485C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x485A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 sean_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 sean_nmca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x485F, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 sean_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 sean_nmca_031[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4864, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x4865, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 sean_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 sean_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4868, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4869, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x4869, 0, 16, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4869, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 sean_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_033[12] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 sean_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_038[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4861, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 sean_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_nmca_040[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4865, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4866, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 sean_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4868, 0, 4, 0, 0, 0, 18, 8),
    L4(250, 0, 484, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 sean_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_043[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4861, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 sean_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_044[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4A80, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x4A81, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4A81, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 sean_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_nmca_045[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4868, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 484, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4853, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4858, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 sean_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x4844, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4845, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4846, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4847, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4848, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x486B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 sean_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 sean_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 sean_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4801, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 sean_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_nmca_050[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4861, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const sean_dmca[99] = {
    sean_dmca_000,  /* 0 GUARD HEAD */
    sean_dmca_001,  /* 1 GUARD UP */
    sean_dmca_002,  /* 2 GUARD DOWN */
    sean_dmca_003,  /* 3 GUARD AIR */
    sean_dmca_004,  /* 4 HUSHIN HEAD */
    sean_dmca_004,  /* 5 HUSHIN UP */
    sean_dmca_006,  /* 6 HUSHIN DOWN */
    sean_dmca_006,  /* 7 HUSHIN AIR */
    sean_dmca_008,  /* 8 FACE S */
    sean_dmca_009,  /* 9 FACE M */
    sean_dmca_010,  /* 10 FACE L */
    sean_dmca_010,  /* 11 FACE SP */
    sean_dmca_008,  /* 12 FOOK OKU S */
    sean_dmca_009,  /* 13 FOOK OKU M */
    sean_dmca_014,  /* 14 FOOK OKU L */
    sean_dmca_015,  /* 15 FOOK OKU SP */
    sean_dmca_008,  /* 16 FOOK TEMAE S */
    sean_dmca_009,  /* 17 FOOK TEMAE M */
    sean_dmca_018,  /* 18 FOOK TEMAE L */
    sean_dmca_019,  /* 19 FOOK TEMAE SP */
    sean_dmca_008,  /* 20 UPPER S */
    sean_dmca_009,  /* 21 UPPER M */
    sean_dmca_022,  /* 22 UPPER L */
    sean_dmca_022,  /* 23 UPPER SP */
    sean_dmca_024,  /* 24 NOUTEN S */
    sean_dmca_025,  /* 25 NOUTEN M */
    sean_dmca_026,  /* 26 NOUTEN L */
    sean_dmca_026,  /* 27 NOUTEN SP */
    sean_dmca_024,  /* 28 BODY BROW S */
    sean_dmca_029,  /* 29 BODY BROW M */
    sean_dmca_030,  /* 30 BODY BROW L */
    sean_dmca_030,  /* 31 BODY BROW SP */
    sean_dmca_024,  /* 32 BODY UPPER S */
    sean_dmca_029,  /* 33 BODY UPPER M */
    sean_dmca_034,  /* 34 BODY UPPER L */
    sean_dmca_034,  /* 35 BODY UPPER SP */
    sean_dmca_036,  /* 36 TATAKI S */
    sean_dmca_036,  /* 37 TATAKI M */
    sean_dmca_036,  /* 38 TATAKI L */
    sean_dmca_036,  /* 39 TATAKI SP */
    sean_dmca_036,  /* 40 TATAKI V. S */
    sean_dmca_036,  /* 41 TATAKI V. M */
    sean_dmca_036,  /* 42 TATAKI V. L */
    sean_dmca_036,  /* 43 TATAKI V. SP */
    sean_dmca_008,  /* 44 NOBASITA TE S */
    sean_dmca_009,  /* 45 NOBASITA TE M */
    sean_dmca_010,  /* 46 NOBASITA TE L */
    sean_dmca_010,  /* 47 NOBASITA TE SP */
    sean_dmca_048,  /* 48 KAGAMI S */
    sean_dmca_049,  /* 49 KAGAMI M */
    sean_dmca_050,  /* 50 KAGAMI L */
    sean_dmca_050,  /* 51 KAGAMI SP */
    sean_dmca_052,  /* 52 KGM TATAKI S */
    sean_dmca_052,  /* 53 KGM TATAKI M */
    sean_dmca_052,  /* 54 KGM TATAKI L */
    sean_dmca_052,  /* 55 KGM TATAKI SP */
    sean_dmca_052,  /* 56 KGM TTKI V.S */
    sean_dmca_052,  /* 57 KGM TTKI V.M */
    sean_dmca_052,  /* 58 KGM TTKI V.L */
    sean_dmca_052,  /* 59 KGM TTKI V.SP */
    sean_dmca_060,  /* 60 NEKOROBI S */
    sean_dmca_060,  /* 61 NEKOROBI M */
    sean_dmca_060,  /* 62 NEKOROBI L */
    sean_dmca_060,  /* 63 NEKOROBI SP */
    sean_dmca_064,  /* 64 OKIAGARI */
    sean_dmca_065,  /* 65 OKIAGARI F */
    sean_dmca_066,  /* 66 OKIAGARI B */
    sean_dmca_067,  /* 67 LOSE NO STAND */
    sean_dmca_068,  /* 68 LOSE SONABA */
    sean_dmca_068,  /* 69 LOSE KAGAMI */
    sean_dmca_070,  /* 70 PIYO */
    sean_dmca_071,  /* 71 UKEMI MOVE F */
    sean_dmca_072,  /* 72 UKEMI MOVE R */
    sean_dmca_073,  /* 73 SHIMEOTASARE */
    sean_dmca_074,  /* 74 TATI TOUKETU S */
    sean_dmca_075,  /* 75 TATI TOUKETU M */
    sean_dmca_076,  /* 76 TATI TOUKETU L */
    sean_dmca_076,  /* 77 TATI TOUKETU P */
    sean_dmca_078,  /* 78 KGM TOUKETU S */
    sean_dmca_079,  /* 79 KGM TOUKETU M */
    sean_dmca_080,  /* 80 KGM TOUKETU L */
    sean_dmca_080,  /* 81 KGM TOUKETU P */
    sean_dmca_082,  /* 82 TATI DENGEKI S */
    sean_dmca_083,  /* 83 TATI DENGEKI M */
    sean_dmca_084,  /* 84 TATI DENGEKI L */
    sean_dmca_084,  /* 85 TATI DENGEKI P */
    sean_dmca_082,  /* 86 KGM DENGEKI S */
    sean_dmca_083,  /* 87 KGM DENGEKI M */
    sean_dmca_084,  /* 88 KGM DENGEKI L */
    sean_dmca_084,  /* 89 KGM DENGEKI P */
    sean_dmca_090,  /* 90 OKIAGARI FRONT */
    sean_dmca_091,  /* 91 OKIAGARI REAR */
    sean_dmca_008,  /* 92 TATI MOE S */
    sean_dmca_009,  /* 93 TATI MOE M */
    sean_dmca_010,  /* 94 TATI MOE L */
    sean_dmca_010,  /* 95 TATI MOE SP */
    sean_dmca_096,  /* 96 no name */
    sean_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 sean_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_000[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x485C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x485D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x485E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x485C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x485A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 sean_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_001[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4861, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x4862, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4860, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 sean_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x4865, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4866, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x4867, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4865, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4863, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 sean_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x4868, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x4869, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x4869, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4869, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4869, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4869, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 sean_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_004[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4883, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 sean_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_006[44] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4888, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4880, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4881, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4882, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4883, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 sean_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4890, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 133, 482, 0, 0, 0, 0, 0x4890, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4892, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 sean_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4891, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 134, 482, 0, 0, 0, 0, 0x4891, 0, 151, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x4895, 0, 152, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4896, 0, 152, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x4892, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 sean_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_010[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4899, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 135, 483, 0, 0, 0, 0, 0x4899, 0, 152, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x489A, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x489B, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x489C, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x489D, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x489E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 sean_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_014[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4899, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 136, 483, 0, 0, 0, 0, 0x4899, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x489A, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x48A7, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x48A8, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x48A6, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x489D, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x489E, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 sean_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_015[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4897, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 137, 483, 0, 0, 0, 0, 0x4898, 0, 152, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x4899, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x489A, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x48A7, 0, 154, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x48A8, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x48A6, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x489D, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x489E, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 sean_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_018[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48A0, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 137, 483, 0, 0, 0, 0, 0x48A0, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x48A2, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x48A3, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x48A4, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x48A5, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x48A6, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x489D, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x489E, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 sean_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_019[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4894, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 138, 483, 0, 0, 0, 0, 0x48A0, 0, 152, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x48A1, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x48A2, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x48A3, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x48A4, 0, 153, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x48A5, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x48A6, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x489D, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x489E, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 sean_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4920, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 135, 483, 0, 0, 0, 0, 0x48AF, 0, 148, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48B0, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48B1, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x489C, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x489D, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x489E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 sean_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_025[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48AA, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 134, 482, 0, 0, 0, 0, 0x48AB, 0, 155, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48AC, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48AD, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 sean_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48AB, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 135, 482, 0, 0, 0, 0, 0x48AB, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48AB, 0, 157, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48AC, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48AD, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 sean_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48B3, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 134, 482, 0, 0, 0, 0, 0x48B4, 0, 155, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48B5, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48B6, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x48B7, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4999, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 sean_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48BC, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 136, 482, 0, 0, 0, 0, 0x48BC, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48BC, 0, 157, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48B4, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48B5, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48B6, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x48B7, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4999, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 sean_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48BB, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 139, 483, 0, 0, 0, 0, 0x48BE, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48BF, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48C0, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x48C1, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48C2, 0, 157, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48C3, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48C4, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48C5, 0, 155, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4999, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x499A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 sean_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48AD, 0, 158, 0, 0, 0, 0, 0),
    L4(6, 135, 483, 0, 0, 0, 0, 0x48AE, 0, 155, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48AF, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48B0, 0, 150, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x48B1, 0, 148, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x489C, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x489D, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x489E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 sean_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x490C, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x490D, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 sean_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_048[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48C6, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 133, 482, 0, 0, 0, 0, 0x48C7, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48C7, 0, 160, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x48C8, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 sean_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_049[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48CA, 0, 159, 0, 0, 0, 0, 0),
    L4(5, 133, 482, 0, 0, 0, 0, 0x48CB, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48C7, 0, 161, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x48C8, 0, 160, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 sean_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_050[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x48CD, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48CE, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 135, 483, 0, 0, 0, 0, 0x48CA, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48CF, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48D0, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x483A, 0, 159, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x483B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x483C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 sean_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 132, 483, 0, 0, 0, 0, 0x48CD, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48CA, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 sean_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_060[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48F9, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 483, 0, 0, 0, 0, 0x48FA, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48FB, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F5, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 sean_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 sean_dmca_064[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4940, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4941, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4942, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4943, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4944, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4945, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(6, 12, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4947, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4948, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 sean_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 sean_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A90, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4952, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4953, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4948, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 sean_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 sean_dmca_066[156] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4940, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4941, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4952, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4948, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 sean_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 sean_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_068[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4890, 0, 202, 0, 0, 0, 32, 127),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4890, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4930, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4931, 0, 204, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4932, 0, 205, 0, 0, 0, 0, 0),
    L4(6, 0, 289, 0, 0, 0, 0, 0x4933, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x4934, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4935, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4936, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4937, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4938, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 288, 0, 0, 0, 0, 0x4939, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x493E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x493F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 sean_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x4911, 0, 265, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4912, 0, 266, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4913, 0, 267, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4914, 0, 267, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x490E, 0, 268, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x490F, 0, 268, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4910, 0, 269, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 sean_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4952, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 484, 0, 0, 0, 0, 0x494B, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494C, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494D, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494E, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4950, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4951, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 sean_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_072[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4940, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -11776, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 484, 0, 0, 0, 0, 0x494E, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x494D, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x494C, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x494B, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4948, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4948, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 sean_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_073[148] = {
    L4(2, 0, 483, 0, 0, 0, 0, 0x4890, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4930, 0, 203, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4931, 0, 204, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4932, 0, 205, 0, 0, 0, 0, 0),
    L4(3, 0, 289, 0, 0, 0, 0, 0x4933, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x4934, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4935, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4936, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4937, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4938, 0, 0, 0, 0, 0, 32, 135),
    L4(4, 0, 288, 0, 0, 0, 0, 0x4939, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x493A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x493B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x493D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x493E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x493F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x493F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 sean_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4890, 0, 151, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4890, 0, 151, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 sean_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4894, 0, 151, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4894, 0, 151, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 sean_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4897, 0, 151, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4897, 0, 151, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 sean_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48C6, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x48C6, 0, 159, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x48C8, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 sean_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48C9, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x48C9, 0, 159, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x48C8, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 sean_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48CC, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x48CC, 0, 159, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x483B, 0, 159, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x483C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x483D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 sean_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 sean_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 sean_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 sean_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 sean_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A90, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x494B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4952, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4953, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4948, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 sean_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 sean_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4940, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4941, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4952, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x494B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4947, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4948, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 sean_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_096[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 sean_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_dmca_097[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x48F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F8, 0, 17, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 17, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 17, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const sean_btca[37] = {
    sean_btca_000,  /* 0 AIR NORMAL */
    sean_btca_001,  /* 1 ASIBARAI SIRI */
    sean_btca_002,  /* 2 ASIB TUNNOMERI */
    sean_btca_003,  /* 3 NOKEZORI */
    sean_btca_004,  /* 4 KUNOJI */
    sean_btca_005,  /* 5 KIRIMOMI */
    sean_btca_006,  /* 6 UPPER */
    sean_btca_007,  /* 7 BODY UPPER */
    sean_btca_008,  /* 8 HARAYARARE */
    sean_btca_009,  /* 9 TATAKI AIR */
    sean_btca_010,  /* 10 TTKI V. AIR */
    sean_btca_011,  /* 11 HUMI ASIB */
    sean_btca_012,  /* 12 FACE */
    sean_btca_013,  /* 13 ASIB SIRI LOSE */
    sean_btca_014,  /* 14 ASIB TUN LOSE */
    sean_btca_015,  /* 15 DENKI */
    sean_btca_016,  /* 16 KUNOJI NOKE */
    sean_btca_017,  /* 17 BODY UPPER SP */
    sean_btca_018,  /* 18 HANEAGARI */
    sean_btca_019,  /* 19 TOUKETSU A */
    sean_btca_020,  /* 20 BODY SLAM */
    sean_btca_021,  /* 21 IPPONZEOI */
    sean_btca_022,  /* 22 TOMOE RYU */
    sean_btca_023,  /* 23 MONKEY FLIP */
    sean_btca_024,  /* 24 TOMOE ORO */
    sean_btca_025,  /* 25 SNAKE FANG */
    sean_btca_026,  /* 26 FLANKEN.S */
    sean_btca_027,  /* 27 KISHINRIKI */
    sean_btca_028,  /* 28 SPLASH.M */
    sean_btca_029,  /* 29 HARAIGOSHI */
    sean_btca_030,  /* 30 ALEX B.D */
    sean_btca_031,  /* 31 GILL */
    sean_btca_032,  /* 32 HANEKAERI HARA */
    sean_btca_033,  /* 33 S HANEAGARI */
    sean_btca_034,  /* 34 TATUMAKIZANKU */
    sean_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 sean_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_000[68] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 482, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x48BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x4853, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 sean_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4904, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 7, 0x4905, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x4906, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4907, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x4908, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 sean_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_btca_002[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4904, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 482, 0, 0, 0, 0, 0x4905, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4906, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4907, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4908, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 sean_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_003[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 sean_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_004[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 482, 0, 0, 0, 0, 0x48BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48BF, 0, 219, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 sean_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_005[156] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4920, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 483, 0, 0, 0, 0, 0x4921, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4922, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4923, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4924, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4925, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4926, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4927, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4928, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4929, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492A, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492B, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492C, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492D, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492E, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x492F, 0, 224, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x492F, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 sean_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_006[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x4B10, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 sean_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_007[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4B12, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x4B13, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B14, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B15, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 sean_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_008[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48BD, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x4B11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 sean_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_009[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 483, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 sean_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_010[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x490B, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 483, 0, 0, 0, 0, 0x490C, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x490D, 0, 235, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 sean_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 sean_btca_011[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4909, 0, 233, 0, 0, 0, 0, 0),
    L4(250, 0, 482, 0, 0, 0, 0, 0x490A, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 sean_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_012[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4891, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 482, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 sean_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 sean_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 sean_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_015[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x4B17, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B17, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B18, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B17, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B19, 0, 231, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 483, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 sean_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_016[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 482, 0, 0, 0, 0, 0x48BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48BF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48FF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 sean_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_017[148] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x4B10, 0, 226, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 483, 0, 0, 0, 0, 0x4B11, 0, 227, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 sean_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_018[156] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 482, 0, 0, 0, 0, 0x48EC, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x48E8, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x48E7, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x48E6, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x48E5, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x48E3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x48EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x48F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 sean_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4895, 0, 232, 0, 0, 0, 0, 0),
    L4(250, 0, 482, 0, 0, 0, 0, 0x4895, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 sean_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FA, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 sean_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 sean_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_022[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x492C, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4937, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 236, 0, 0, 0, 32, 99),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 sean_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x492C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4937, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 236, 0, 0, 0, 32, 99),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 sean_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x492C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4937, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 236, 0, 0, 0, 32, 99),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 sean_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 236, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 sean_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4937, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48E8, 0, 236, 0, 0, 0, 32, 99),
    L4(6, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FB, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 sean_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_027[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x48E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x48E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x48E5, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x48E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 sean_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_028[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48EC, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48ED, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 sean_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E8, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E8, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 sean_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_030[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4B12, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x4B13, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B14, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B15, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x48E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x48E5, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x48E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x48E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 sean_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_031[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4904, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 483, 0, 0, 0, 0, 0x4905, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4906, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4907, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4908, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 sean_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x48BD, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B11, 0, 236, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 sean_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_033[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x48EF, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 482, 0, 0, 0, 0, 0x48EF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F0, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x48EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x48F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 sean_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_034[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x48AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 483, 0, 0, 0, 0, 0x4B10, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 sean_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_btca_035[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x48E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x48E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x48E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x48E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 19 entries */
const u16* const sean_caca[20] = {
    sean_caca_000,  /* 0 CATCH 1 */
    sean_caca_000,  /* 1 CATCH 2 */
    sean_caca_002,  /* 2 CATCH 3 */
    sean_caca_002,  /* 3 CATCH 4 */
    sean_caca_004,  /* 4 CATCH 5 */
    sean_caca_004,  /* 5 CATCH 6 */
    sean_caca_004,  /* 6 CATCH 7 */
    sean_caca_004,  /* 7 CATCH 8 */
    sean_caca_008,  /* 8 CATCH 9 */
    sean_caca_009,  /* 9 CATCH 10 */
    sean_caca_010,  /* 10 CATCH 11 */
    sean_caca_010,  /* 11 CATCH 12 */
    sean_caca_012,  /* 12 CATCH 13 */
    sean_caca_012,  /* 13 CATCH 14 */
    sean_caca_014,  /* 14 CATCH 15 */
    sean_caca_014,  /* 15 CATCH 16 */
    sean_caca_014,  /* 16 CATCH 17 */
    sean_caca_014,  /* 17 CATCH 18 */
    sean_caca_018,  /* 18 CATCH 19 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2 */
const u16 sean_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 sean_caca_000[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A82, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A83, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4A84, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A85, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4A86, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4A87, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 2, 486, 0, 0, 0, 0, 0x4A88, -47, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(10, 9, 270, 0, 0, 0, 0, 0x4A89, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4A8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4A8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3, 3 CATCH 4 */
const u16 sean_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 sean_caca_002[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A82, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A83, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4A84, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A85, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4A86, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4A87, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 2, 486, 0, 0, 0, 0, 0x4A88, -47, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(10, 9, 270, 0, 0, 0, 0, 0x4A89, 0, 1, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4A8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4A8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 sean_caca_004_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 sean_caca_004[196] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4A8E, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4A8F, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(4, 0, 486, 0, 0, 0, 0, 0x4A90, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x4A91, -51, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x4A92, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4A93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A95, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x4A96, 0, 1, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 sean_caca_008_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 sean_caca_008[208] = {
    CMD(CM_NGDA, 1542, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x49C0, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x49C8, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x49C9, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 0, 485, 0, 0, 0, 0, 0x49CA, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 2, 270, 0, 0, 0, 0, 0x49CB, -55, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(7, 3, 0, 0, 0, 0, 0, 0x49CC, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x49CD, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x49C5, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49C6, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 9, 0, 0, 0, 0, 0, 0x482F, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 sean_caca_009_head[4] = { HEAD(6, 0, 28, 0, 0, 0, 0) };
const u16 sean_caca_009[472] = {
    CMD(CM_NGDA, 6, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 2, 0, 0x4B38, 0, 0, 0, 0, 0, 0, 0, 0, 792, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x4B39, 0, 0, 0, 0, 0, 0, 0, 0, 816, 230, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x4B3A, 0, 0, 0, 0, 0, 0, 0, 0, 840, 232, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0, 0, 864, 234, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0, 0, 888, 236, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0, 0, 936, 240, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0, 0, 960, 242, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0, 0, 984, 244, 0, 0),
    L6(6, 0, 485, 0, 0, 6, 0, 0x4B80, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 246, 0, 0),
    L6(2, 2, 0, 0, 0, 5, 0, 0x4B81, -53, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B82, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 7, 0, 0x4B83, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 8, 0, 0x4B84, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 485, 0, 0, 6, 0, 0x4B85, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 5, 0, 0x4B86, -54, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B87, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 7, 0, 0x4B88, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 8, 0, 0x4B89, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    CMD(CM_MXYT, 66, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 4, 21, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 6, 0, 0x4B42, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x4854, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4853, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4852, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4851, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4850, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x484F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x484E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x484D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x484C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11, 11 CATCH 12 */
const u16 sean_caca_010_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 sean_caca_010[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x4A83, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14 */
const u16 sean_caca_012_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 sean_caca_012[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x4A83, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16, 16 CATCH 17, 17 CATCH 18 */
const u16 sean_caca_014_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 sean_caca_014[76] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4960, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4A80, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4A81, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4A8E, 0, 0, 0, 0, 0, 24, 0, 0, 360, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 CATCH 19 */
const u16 sean_caca_018_head[4] = { HEAD(6, 0, 30, 0, 0, 0, 0) };
const u16 sean_caca_018[756] = {
    CMD(CM_NGDA, 6, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 2, 0, 0x4B38, 0, 0, 0, 0, 0, 0, 0, 0, 792, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x4B39, 0, 0, 0, 0, 0, 0, 0, 0, 816, 230, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x4B3A, 0, 0, 0, 0, 0, 0, 0, 0, 840, 232, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494C, 0, 0, 0, 0, 0, 0, 0, 0, 864, 234, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494D, 0, 0, 0, 0, 0, 0, 0, 0, 888, 236, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494F, 0, 0, 0, 0, 0, 0, 0, 0, 936, 240, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4950, 0, 0, 0, 0, 0, 0, 0, 0, 960, 242, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4951, 0, 0, 0, 0, 0, 0, 0, 0, 984, 244, 0, 0),
    L6(5, 0, 485, 0, 0, 6, 0, 0x4B80, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 246, 0, 0),
    L6(1, 2, 0, 0, 0, 5, 0, 0x4B81, -89, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B82, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 7, 0, 0x4B83, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 8, 0, 0x4B84, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(5, 0, 485, 0, 0, 6, 0, 0x4B85, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 5, 0, 0x4B86, -89, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B87, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 7, 0, 0x4B88, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 8, 0, 0x4B89, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 485, 0, 0, 6, 0, 0x4B80, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 5, 0, 0x4B81, -89, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B82, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 7, 0, 0x4B83, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 8, 0, 0x4B84, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(6, 0, 485, 0, 0, 6, 0, 0x4B85, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 5, 0, 0x4B86, -89, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 7, 0, 0x4B87, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 7, 0, 0x4B88, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 8, 0, 0x4B89, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 6, 0, 0x4B3F, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(12, 2, 0, 0, 0, 5, 0, 0x4B3E, -95, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 3, 485, 0, 0, 7, 0, 0x4B40, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 7, 0, 0x4B40, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 8, 0, 0x4B41, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    CMD(CM_JMP, 2, 9, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x001E, 0x0000, 0x0000, 0x0069, 0x0006, 0x001A, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0010, 0x4B37,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0300, 0x0000, 0x0000, 0x0300, 0x0000, 0x0020, 0x4B38,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0318, 0x00E4, 0x0000, 0x0300, 0x0000, 0x0030, 0x4B39,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0330, 0x00E6, 0x0000, 0x0300, 0x0000, 0x0040, 0x4B3A,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0348, 0x00E8, 0x0000, 0x0300, 0x0000, 0x0000, 0x494C,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0360, 0x00EA, 0x0000, 0x0300, 0x0000, 0x0000, 0x494D,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0378, 0x00EC, 0x0000, 0x0300, 0x0000, 0x0000, 0x494E,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0390, 0x00EE, 0x0000, 0x0300, 0x0000, 0x0000, 0x494F,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03A8, 0x00F0, 0x0000, 0x0400, 0x0000, 0x0000, 0x4950,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03C0, 0x00F2, 0x0000, 0x0400, 0x0000, 0x0000, 0x4951,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03D8, 0x00F4, 0x0000, 0x0042, 0x00F6, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x000C, 0x0000, 0x0000, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x1E50, 0x0060, 0x4B3F,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03F0, 0x0000, 0x0000, 0x0302, 0x0000, 0x0050, 0x4B3E,
    L6(233, 192, 0, 0, 0, 0, 0, 0x0000, 0, 0, 1032, 0, 0, 0, 0, 515, 0, 112, 75, 64),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0420, 0x0000, 0x0000, 0x0600, 0x0000, 0x0070, 0x4B40,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0420, 0x0000, 0x0000, 0x0400, 0x0000, 0x0080, 0x4B41,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0420, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0000, 0x0060, 0x4B3F,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03F0, 0x0000, 0x0000, 0x0C02, 0x0000, 0x0050, 0x4B3E,
    L6(232, 64, 0, 0, 0, 0, 0, 0x0000, 0, 0, 1032, 0, 0, 0, 0, 515, 7760, 112, 75, 64),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0420, 0x0000, 0x0000, 0x0C00, 0x0000, 0x0070, 0x4B40,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0420, 0x0000, 0x0000, 0x0800, 0x0000, 0x0080, 0x4B41,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0438, 0x0000, 0x0000, 0x0003, 0x0002, 0x0009, 0x0016,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* caught scripts: 68 entries */
const u16* const sean_cuca[69] = {
    sean_cuca_000,  /* 0 ALEX ZUTUKI */
    sean_cuca_001,  /* 1 ALEX BODY S */
    sean_cuca_002,  /* 2 ALEX BACK D */
    sean_cuca_003,  /* 3 ALEX POWER B */
    sean_cuca_004,  /* 4 ALEX SLEEPER */
    sean_cuca_005,  /* 5 RYU SEOINAGE */
    sean_cuca_006,  /* 6 IBUKI */
    sean_cuca_007,  /* 7 DADLEY L B */
    sean_cuca_008,  /* 8 IBUKI KUBIORI */
    sean_cuca_009,  /* 9 NECRO S T */
    sean_cuca_010,  /* 10 RYU TOMOENAGE */
    sean_cuca_011,  /* 11 YUN HIZAGERI */
    sean_cuca_012,  /* 12 ORO KUBISIME */
    sean_cuca_013,  /* 13 NECRO G S */
    sean_cuca_014,  /* 14 DUDDLEY D S */
    sean_cuca_015,  /* 15 YUN MONKEY F */
    sean_cuca_016,  /* 16 ORO TOMOENAGE */
    sean_cuca_017,  /* 17 ORO NIOURIKI */
    sean_cuca_018,  /* 18 ORO GIGOKU G */
    sean_cuca_019,  /* 19 YUN */
    sean_cuca_020,  /* 20 NECRO SNAKE F */
    sean_cuca_021,  /* 21 NECRO F S */
    sean_cuca_022,  /* 22 IBUKI HARAIG */
    sean_cuca_023,  /* 23 GILL SPLASH M */
    sean_cuca_024,  /* 24 KEN HIZAGERI */
    sean_cuca_025,  /* 25 ORO KISINRIKI */
    sean_cuca_026,  /* 26 SEAN TACKLE */
    sean_cuca_027,  /* 27 ALEX HYPER B */
    sean_cuca_028,  /* 28 NECRO SLAM D */
    sean_cuca_029,  /* 29 ELENA ASINAGE */
    sean_cuca_030,  /* 30 GILL IMPACT C */
    sean_cuca_031,  /* 31 ALEX S H B */
    sean_cuca_032,  /* 32 ALEX F N D */
    sean_cuca_033,  /* 33 no name */
    sean_cuca_034,  /* 34 IBUKI */
    sean_cuca_035,  /* 35 IBUKI YOROI D */
    sean_cuca_036,  /* 36 no name */
    sean_cuca_037,  /* 37 MAWARIKOMI M F */
    sean_cuca_038,  /* 38 HUGO BODY S */
    sean_cuca_039,  /* 39 HUGO N G T */
    sean_cuca_040,  /* 40 HUGO M S P */
    sean_cuca_041,  /* 41 HUGO S D B B */
    sean_cuca_042,  /* 42 no name */
    sean_cuca_043,  /* 43 no name */
    sean_cuca_044,  /* 44 no name */
    sean_cuca_045,  /* 45 no name */
    sean_cuca_046,  /* 46 no name */
    sean_cuca_047,  /* 47 no name */
    sean_cuca_048,  /* 48 no name */
    sean_cuca_049,  /* 49 no name */
    sean_cuca_050,  /* 50 no name */
    sean_cuca_051,  /* 51 no name */
    sean_cuca_052,  /* 52 no name */
    sean_cuca_053,  /* 53 no name */
    sean_cuca_054,  /* 54 no name */
    sean_cuca_055,  /* 55 no name */
    sean_cuca_056,  /* 56 no name */
    sean_cuca_057,  /* 57 no name */
    sean_cuca_058,  /* 58 no name */
    sean_cuca_059,  /* 59 no name */
    sean_cuca_060,  /* 60 no name */
    sean_cuca_061,  /* 61 no name */
    sean_cuca_062,  /* 62 no name */
    sean_cuca_063,  /* 63 no name */
    sean_cuca_064,  /* 64 no name */
    sean_cuca_065,  /* 65 no name */
    sean_cuca_066,  /* 66 no name */
    sean_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 sean_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AA),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 sean_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4937),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4903),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4901),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48ED),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 sean_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 sean_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x489A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4908),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EB),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 sean_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48AA),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48AA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 sean_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4909),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E7),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48EE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 sean_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4879),
    L2(250, 0, 0, 0, 0, 0, 0, 0x487A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4874),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4874),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4960),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4963),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 sean_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 sean_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4920),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 sean_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 sean_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 1, 0, 0, 0x492C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 sean_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C5),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 sean_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x484B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 sean_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EB),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48EB),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 sean_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BF),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48FF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 sean_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4901),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x492C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 sean_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x492C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 sean_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x489A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x489B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E2),
    L2(250, 2, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 sean_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x494B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x494C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x494D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x494E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4950),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4951),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4952),
    L2(250, 0, 0, 0, 0, 0, 0, 0x494B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 sean_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 sean_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 1, 0, 0, 0x485A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x485B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x485C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4876),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4887),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4886),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4885),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E4),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 sean_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4876),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4875),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48B3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 sean_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E7),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 sean_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48EB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 sean_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C5),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 sean_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x489A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x489B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E2),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 sean_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 3, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F7),
    L2(250, 3, 0, 0, 0, 0, 0, 0x48FA),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48F7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 sean_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_027[152] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EB),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 sean_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48F3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 sean_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4900),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4901),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 sean_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B11),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B11),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4B10),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x4B10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 34, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 sean_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AB),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 sean_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4901),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4903),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 sean_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48EA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 12),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 sean_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4909),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4909),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B0),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48B0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 sean_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4879),
    L2(250, 0, 0, 0, 0, 0, 0, 0x487A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4874),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4874),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4960),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4963),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4992),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 sean_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 2, 0, 0, 0, 0, 0, 0x48B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 2, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 2, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F3),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48F2),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 sean_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48BE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48BF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x48C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 sean_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x489C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4937),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4938),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48FC),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 sean_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FC),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 sean_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x492B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4903),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F5),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 sean_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x492F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 sean_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BE),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 sean_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F8),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48F8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 sean_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x492B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4903),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x492F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x490A),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 sean_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 sean_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x492B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x492B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48EF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4903),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 sean_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EA),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 sean_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 sean_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x484D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 2, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4900),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 3, 0, 0, 0x4900),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 sean_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x484C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x484C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B12),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B12),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48EE),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E8),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 sean_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4879),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A7),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48B4),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 sean_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4AAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x490A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4B15),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4943),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4936),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FB),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 1, 0, 0, 0x492C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 sean_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_053[116] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4906),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E9),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 sean_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4921),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B10),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4B10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 34, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 sean_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48AF),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x48E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 sean_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x4890),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 10, 0x4906),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 sean_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BE),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 sean_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4902),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4B15),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4920),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 sean_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4859),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4875),
    L2(250, 0, 0, 0, 0, 0, 0, 0x485A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x485F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4861),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4862),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4905),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 sean_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x489E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4892),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 sean_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4904),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4900),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4906),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 sean_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4894),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A6),
    CMD(CM_PA_X, 0, -8192, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48C4),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 120),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4906),
    CMD(CM_PA_X, 0, 1536, 0),
    CMD(CM_PS_Y, 0, 0, 86),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4907),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48EC),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48ED),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 sean_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48BD),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 482, 0, 0, 0, 0, 0x48BE),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 sean_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 sean_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x489A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x48A6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x48EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4901),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x492C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 sean_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 sean_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x48AF),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x48E3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 158 entries */
const u16* const sean_atca[159] = {
    sean_atca_000,  /* 0 S PUNCH A */
    sean_atca_000,  /* 1 S PUNCH B */
    sean_atca_000,  /* 2 S PUNCH C */
    sean_atca_003,  /* 3 M PUNCH A */
    sean_atca_004,  /* 4 M PUNCH B */
    sean_atca_004,  /* 5 M PUNCH C */
    sean_atca_006,  /* 6 L PUNCH A */
    sean_atca_007,  /* 7 L PUNCH B */
    sean_atca_008,  /* 8 L PUNCH C */
    sean_atca_009,  /* 9 S KICK A */
    sean_atca_009,  /* 10 S KICK B */
    sean_atca_009,  /* 11 S KICK C */
    sean_atca_012,  /* 12 M KICK A */
    sean_atca_012,  /* 13 M KICK B */
    sean_atca_012,  /* 14 M KICK C */
    sean_atca_015,  /* 15 L KICK A */
    sean_atca_016,  /* 16 L KICK B */
    sean_atca_017,  /* 17 L KICK C */
    sean_atca_018,  /* 18 KAGAMI P A */
    sean_atca_018,  /* 19 KAGAMI P B */
    sean_atca_018,  /* 20 KAGAMI P C */
    sean_atca_021,  /* 21 KAGAMI P A */
    sean_atca_021,  /* 22 KAGAMI P B */
    sean_atca_021,  /* 23 KAGAMI P C */
    sean_atca_024,  /* 24 KAGAMI P A */
    sean_atca_024,  /* 25 KAGAMI P B */
    sean_atca_024,  /* 26 KAGAMI P C */
    sean_atca_027,  /* 27 KAGAMI K A */
    sean_atca_027,  /* 28 KAGAMI K B */
    sean_atca_027,  /* 29 KAGAMI K C */
    sean_atca_030,  /* 30 KAGAMI K A */
    sean_atca_030,  /* 31 KAGAMI K B */
    sean_atca_030,  /* 32 KAGAMI K C */
    sean_atca_033,  /* 33 KAGAMI K A */
    sean_atca_033,  /* 34 KAGAMI K B */
    sean_atca_033,  /* 35 KAGAMI K C */
    sean_atca_036,  /* 36 V JUMP P S A */
    sean_atca_036,  /* 37 V JUMP P S B */
    sean_atca_038,  /* 38 V JUMP P M A */
    sean_atca_038,  /* 39 V JUMP P M B */
    sean_atca_040,  /* 40 V JUMP P L A */
    sean_atca_040,  /* 41 V JUMP P L B */
    sean_atca_042,  /* 42 V JUMP K S A */
    sean_atca_042,  /* 43 V JUMP K S B */
    sean_atca_044,  /* 44 V JUMP K M A */
    sean_atca_044,  /* 45 V JUMP K M B */
    sean_atca_046,  /* 46 V JUMP K L A */
    sean_atca_046,  /* 47 V JUMP K L B */
    sean_atca_048,  /* 48 F JUMP P S A */
    sean_atca_048,  /* 49 F JUMP P S B */
    sean_atca_050,  /* 50 F JUMP P M A */
    sean_atca_050,  /* 51 F JUMP P M B */
    sean_atca_052,  /* 52 F JUMP P L A */
    sean_atca_052,  /* 53 F JUMP P L B */
    sean_atca_054,  /* 54 F JUMP K S A */
    sean_atca_054,  /* 55 F JUMP K S B */
    sean_atca_056,  /* 56 F JUMP K M A */
    sean_atca_056,  /* 57 F JUMP K M B */
    sean_atca_058,  /* 58 F JUMP K L A */
    sean_atca_058,  /* 59 F JUMP K L B */
    sean_atca_060,  /* 60 B JUMP P S A */
    sean_atca_060,  /* 61 B JUMP P S B */
    sean_atca_062,  /* 62 B JUMP P M A */
    sean_atca_062,  /* 63 B JUMP P M B */
    sean_atca_064,  /* 64 B JUMP P L A */
    sean_atca_064,  /* 65 B JUMP P L B */
    sean_atca_066,  /* 66 B JUMP K S A */
    sean_atca_066,  /* 67 B JUMP K S B */
    sean_atca_068,  /* 68 B JUMP K M A */
    sean_atca_068,  /* 69 B JUMP K M B */
    sean_atca_070,  /* 70 B JUMP K L A */
    sean_atca_070,  /* 71 B JUMP K L B */
    sean_atca_072,  /* 72 SP V JP S P A */
    sean_atca_072,  /* 73 SP V JP S P B */
    sean_atca_074,  /* 74 SP V JP M P A */
    sean_atca_074,  /* 75 SP V JP M P B */
    sean_atca_076,  /* 76 SP V JP L P A */
    sean_atca_076,  /* 77 SP V JP L P B */
    sean_atca_078,  /* 78 SP V JP S K A */
    sean_atca_078,  /* 79 SP V JP S K B */
    sean_atca_080,  /* 80 SP V JP M K A */
    sean_atca_080,  /* 81 SP V JP M K B */
    sean_atca_082,  /* 82 SP V JP L K A */
    sean_atca_082,  /* 83 SP V JP L K B */
    sean_atca_084,  /* 84 SP F JP S P A */
    sean_atca_084,  /* 85 SP F JP S P B */
    sean_atca_086,  /* 86 SP F JP M P A */
    sean_atca_086,  /* 87 SP F JP M P B */
    sean_atca_088,  /* 88 SP F JP L P A */
    sean_atca_088,  /* 89 SP F JP L P B */
    sean_atca_090,  /* 90 SP F JP S K A */
    sean_atca_090,  /* 91 SP F JP S K B */
    sean_atca_092,  /* 92 SP F JP M K A */
    sean_atca_092,  /* 93 SP F JP M K B */
    sean_atca_094,  /* 94 SP F JP L K A */
    sean_atca_094,  /* 95 SP F JP L K B */
    sean_atca_096,  /* 96 SP B JP S P A */
    sean_atca_096,  /* 97 SP B JP S P B */
    sean_atca_098,  /* 98 SP B JP M P A */
    sean_atca_098,  /* 99 SP B JP M P B */
    sean_atca_100,  /* 100 SP B JP L P A */
    sean_atca_100,  /* 101 SP B JP L P B */
    sean_atca_102,  /* 102 SP B JP S K A */
    sean_atca_102,  /* 103 SP B JP S K B */
    sean_atca_104,  /* 104 SP B JP M K A */
    sean_atca_104,  /* 105 SP B JP M K B */
    sean_atca_106,  /* 106 SP B JP L K A */
    sean_atca_106,  /* 107 SP B JP L K B */
    sean_atca_108,  /* 108 S V JP S P A */
    sean_atca_108,  /* 109 S V JP S P B */
    sean_atca_110,  /* 110 S V JP M P A */
    sean_atca_110,  /* 111 S V JP M P B */
    sean_atca_112,  /* 112 S V JP L P A */
    sean_atca_112,  /* 113 S V JP L P B */
    sean_atca_114,  /* 114 S V JP S K A */
    sean_atca_114,  /* 115 S V JP S K B */
    sean_atca_116,  /* 116 S V JP M K A */
    sean_atca_116,  /* 117 S V JP M K B */
    sean_atca_118,  /* 118 S V JP L K A */
    sean_atca_118,  /* 119 S V JP L K B */
    sean_atca_108,  /* 120 S F JP S P A */
    sean_atca_108,  /* 121 S F JP S P B */
    sean_atca_110,  /* 122 S F JP M P A */
    sean_atca_110,  /* 123 S F JP M P B */
    sean_atca_112,  /* 124 S F JP L P A */
    sean_atca_112,  /* 125 S F JP L P B */
    sean_atca_114,  /* 126 S F JP S K A */
    sean_atca_114,  /* 127 S F JP S K B */
    sean_atca_116,  /* 128 S F JP M K A */
    sean_atca_116,  /* 129 S F JP M K B */
    sean_atca_118,  /* 130 S F JP L K A */
    sean_atca_118,  /* 131 S F JP L K B */
    sean_atca_108,  /* 132 S B JP S P A */
    sean_atca_108,  /* 133 S B JP S P B */
    sean_atca_110,  /* 134 S B JP M P A */
    sean_atca_110,  /* 135 S B JP M P B */
    sean_atca_112,  /* 136 S B JP L P A */
    sean_atca_112,  /* 137 S B JP L P B */
    sean_atca_114,  /* 138 S B JP S K A */
    sean_atca_114,  /* 139 S B JP S K B */
    sean_atca_116,  /* 140 S B JP M K A */
    sean_atca_116,  /* 141 S B JP M K B */
    sean_atca_118,  /* 142 S B JP L K A */
    sean_atca_118,  /* 143 S B JP L K B */
    sean_atca_144,  /* 144 TUKAMIKAKARI A */
    sean_atca_144,  /* 145 TUKAMIKAKARI B */
    sean_atca_146,  /* 146 TUKAMIKAKARI C */
    sean_atca_144,  /* 147 TUKAMIKAKARI D */
    sean_atca_144,  /* 148 TUKAMIKAKARI E */
    sean_atca_144,  /* 149 TUKAMIKAKARI F */
    sean_atca_144,  /* 150 TUKAMI AIR A */
    sean_atca_144,  /* 151 TUKAMI AIR B */
    sean_atca_144,  /* 152 TUKAMI AIR C */
    sean_atca_144,  /* 153 TUKAMI AIR D */
    sean_atca_144,  /* 154 TUKAMI AIR E */
    sean_atca_144,  /* 155 TUKAMI AIR F */
    sean_atca_156,  /* 156 follow-up of M PUNCH A */
    sean_atca_157,  /* 157 follow-up of L PUNCH A */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B, 2 S PUNCH C */
const u16 sean_atca_000_head[4] = { HEAD(4, 0, 0, 9, 0, 1, 0) };
const u16 sean_atca_000[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4960, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4963, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4960, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x4961, -4, 22, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4962, 0, 23, 272, 0, 120, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4963, 0, 1, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4964, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 sean_atca_003_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 sean_atca_003[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4987, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4988, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4989, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x498A, -5, 24, 3205, 128, 104, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x498B, 0, 24, 3205, 0, 104, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x499B, 0, 1, 3205, 0, 8, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x498C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4875, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4875, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 sean_atca_004_head[4] = { HEAD(4, 0, 2, 11, 0, 1, 0) };
const u16 sean_atca_004[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4965, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4966, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4967, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4968, -6, 25, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4969, 0, 26, 0, 128, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x497B, 0, 27, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x496A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x496B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 sean_atca_006_head[4] = { HEAD(4, 0, 4, 9, 0, 1, 0) };
const u16 sean_atca_006[108] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x498D, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x498E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x498F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 485, 0, 0, 0, 0, 0x4990, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4991, -7, 32, 2244, 0, 104, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4992, 0, 33, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4993, 0, 34, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4994, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4995, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4996, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4997, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4999, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B */
const u16 sean_atca_007_head[4] = { HEAD(4, 0, 4, 9, 0, 1, 0) };
const u16 sean_atca_007[132] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BA0, 0, 163, 0, 0, 0, 32, 172),
    L4(3, 0, 484, 0, 0, 0, 0, 0x4BA1, 0, 163, 0, 0, 0, 32, 173),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4BA2, 0, 164, 0, 0, 0, 32, 174),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BA3, -69, 165, 0, 0, 0, 32, 175),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BA4, 70, 166, 0, 0, 0, 32, 176),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BA5, 0, 167, 0, 0, 0, 32, 177),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BA6, 0, 167, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BA7, 0, 167, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BA8, 0, 168, 0, 0, 0, 32, 178),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BA9, 0, 169, 0, 0, 0, 32, 177),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4BAA, 0, 170, 0, 0, 0, 32, 179),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BAB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 sean_atca_008_head[4] = { HEAD(4, 0, 4, 9, 0, 2, 0) };
const u16 sean_atca_008[180] = {
    CMD(CM_ASXY, 292, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B58, 0, 139, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B59, 0, 140, 0, 0, 0, 32, 147),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B5A, 0, 140, 0, 0, 0, 32, 148),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B5B, 0, 139, 0, 0, 0, 32, 149),
    CMD(CM_SETR, 2, 4, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 300, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x4B5C, 0, 141, 0, 0, 0, 33, 0),
    L4(2, 0, 485, 0, 0, 0, 0, 0x4B5D, 0, 141, 0, 0, 0, 32, 151),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B5E, -86, 142, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B5F, -87, 143, 0, 143, 0, 32, 152),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B60, 0, 144, 0, 143, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B61, 0, 145, 0, 0, 0, 21, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B60, 7, 145, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B62, 0, 146, 0, 0, 0, 32, 153),
    L4(10, 0, 0, 0, 0, 0, 0, 0x4B63, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B64, 0, 6, 0, 0, 0, 32, 154),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4B65, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 sean_atca_009_head[4] = { HEAD(4, 0, 1, 8, 0, 1, 0) };
const u16 sean_atca_009[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x49C0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x49C1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x49C2, -10, 37, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49C3, 0, 38, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49C4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B, 14 M KICK C */
const u16 sean_atca_012_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 sean_atca_012[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B50, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B51, 0, 43, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4B52, 0, 43, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B53, -12, 44, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B54, 0, 45, 0, 0, 0, 30, 89),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B54, 0, 43, 0, 0, 0, 21, 0),
    L4(5, 1, 0, 0, 0, 0, 0, 0x4B55, 0, 1, 0, 0, 0, 30, 90),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B56, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4B57, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A */
const u16 sean_atca_015_head[4] = { HEAD(4, 0, 5, 10, 0, 1, 0) };
const u16 sean_atca_015[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x49C0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x49C8, 0, 186, 0, 0, 0, 32, 29),
    L4(1, 0, 0, 0, 0, 0, 0, 0x49C9, 0, 187, 0, 0, 0, 32, 29),
    L4(1, 0, 0, 0, 0, 0, 0, 0x49CA, -13, 188, 0, 128, 96, 32, 29),
    L4(4, 0, 0, 0, 0, 0, 0, 0x49CB, 0, 189, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49CC, 0, 190, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49CD, 0, 191, 0, 0, 0, 32, 30),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49C5, 0, 191, 0, 0, 0, 32, 30),
    L4(3, 64, 0, 0, 0, 0, 0, 0x49C6, 0, 1, 0, 0, 0, 32, 30),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 L KICK B */
const u16 sean_atca_016_head[4] = { HEAD(4, 0, 5, 11, 0, 1, 0) };
const u16 sean_atca_016[132] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BB0, 0, 171, 0, 0, 0, 32, 190),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4BB1, 0, 172, 0, 0, 0, 32, 191),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BB2, -82, 173, 0, 135, 0, 32, 192),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BB3, 83, 174, 0, 135, 0, 32, 193),
    L4(7, 0, 0, 0, 0, 0, 0, 0x4BB3, 0, 175, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x4BB3, 0, 175, 0, 0, 0, 32, 193),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BB4, 0, 176, 0, 0, 0, 32, 193),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BB5, 0, 177, 0, 0, 0, 32, 194),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BB6, 0, 178, 0, 0, 0, 32, 193),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BB7, 0, 179, 0, 0, 0, 32, 193),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BB8, 0, 180, 0, 0, 0, 32, 196),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4B9E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 sean_atca_017_head[4] = { HEAD(4, 0, 5, 12, 0, 1, 0) };
const u16 sean_atca_017[124] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 360, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 281, 0, 0, 0, 0, 0x4B90, 0, 131, 0, 0, 0, 22, 20),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B91, 0, 131, 0, 0, 0, 32, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B92, 0, 132, 0, 0, 0, 32, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4B93, 0, 132, 0, 0, 0, 32, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B94, -78, 133, 0, 0, 0, 32, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B95, 79, 134, 0, 0, 0, 32, 0),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B96, 0, 135, 0, 0, 0, 32, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B97, 0, 136, 0, 0, 0, 32, 0),
    CMD(CM_SCHY, 1, 2, 1), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x4B97, 0, 136, 0, 0, 0, 32, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 sean_atca_018_head[4] = { HEAD(4, 32, 0, 10, 0, 1, 0) };
const u16 sean_atca_018[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x49F0, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x49F1, -19, 51, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F2, 0, 51, 272, 0, 120, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F4, 0, 52, 272, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F3, 0, 2, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 sean_atca_021_head[4] = { HEAD(4, 32, 2, 10, 0, 1, 0) };
const u16 sean_atca_021[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x49F0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x49F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x49F1, -20, 53, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49F2, 0, 51, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F2, 0, 52, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49F3, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x49F0, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 sean_atca_024_head[4] = { HEAD(4, 32, 4, 9, 0, 1, 0) };
const u16 sean_atca_024[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x49FC, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 485, 0, 0, 0, 0, 0x49FC, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x49FD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x49FE, -21, 54, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49FF, 22, 55, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A00, 0, 56, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4A00, 0, 57, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A01, 0, 57, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A02, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A03, 0, 59, 0, 0, 0, 22, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A04, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 sean_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 sean_atca_027[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A11, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x4A11, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A12, -23, 60, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A13, 0, 60, 272, 0, 120, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A14, 0, 2, 272, 0, 24, 21, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A11, 0, 2, 272, 0, 24, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4A10, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A10, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4A15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 sean_atca_030_head[4] = { HEAD(4, 32, 3, 13, 0, 1, 0) };
const u16 sean_atca_030[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A16, 0, 2, 0, 0, 0, 32, 31),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A24, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4A17, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A18, -24, 61, 0, 135, 96, 32, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A19, 0, 62, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A1A, 0, 62, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A1A, 0, 63, 0, 0, 96, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A1B, 0, 2, 0, 0, 0, 32, 33),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A24, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A25, 0, 2, 0, 0, 0, 32, 34),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 32, 34),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 sean_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 1, 0) };
const u16 sean_atca_033[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A16, 0, 2, 0, 0, 0, 32, 35),
    L4(3, 0, 484, 0, 0, 0, 0, 0x4A1C, 0, 2, 0, 0, 0, 32, 36),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4A1D, 0, 2, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A1E, -25, 64, 0, 64, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A1F, 0, 64, 0, 64, 0, 0, 0),
    CMD(CM_ASXY, 74, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4A20, 0, 65, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A21, 0, 65, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A22, 0, 2, 0, 0, 0, 32, 39),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A23, 0, 2, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A24, 0, 2, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A25, 0, 2, 0, 0, 0, 32, 42),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 32, 42),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 sean_atca_036_head[4] = { HEAD(4, 22, 0, 7, 0, 1, 0) };
const u16 sean_atca_036[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x4A30, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x4A31, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x4A32, -26, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A33, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A34, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A35, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A33, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A34, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A35, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 sean_atca_038_head[4] = { HEAD(4, 22, 2, 10, 0, 1, 0) };
const u16 sean_atca_038[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A41, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x4A42, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A43, -27, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A44, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A48, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A45, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A46, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 sean_atca_040_head[4] = { HEAD(4, 22, 4, 13, 0, 1, 0) };
const u16 sean_atca_040[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A4E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4A4F, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A50, -28, 104, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A51, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A53, 0, 106, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A54, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 sean_atca_042_head[4] = { HEAD(4, 22, 1, 6, 0, 1, 0) };
const u16 sean_atca_042[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4A60, -29, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A64, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A6C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 sean_atca_044_head[4] = { HEAD(4, 22, 3, 12, 0, 1, 0) };
const u16 sean_atca_044[100] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 269, 0, 0, 0, 0, 0x4A6D, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A6E, -30, 109, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A6F, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A70, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A70, 0, 111, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A71, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A72, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 sean_atca_046_head[4] = { HEAD(4, 22, 5, 12, 0, 1, 0) };
const u16 sean_atca_046[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A73, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4A74, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A75, -31, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A76, 0, 113, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4A77, 0, 114, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A78, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4847, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4848, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 sean_atca_048_head[4] = { HEAD(4, 20, 0, 9, 0, 1, 0) };
const u16 sean_atca_048[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x4A30, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x4A31, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x4A32, -32, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A33, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A34, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4A35, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A33, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A34, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A35, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 sean_atca_050_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 sean_atca_050[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A41, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4A42, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A43, -33, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A44, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A48, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A45, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A46, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 sean_atca_052_head[4] = { HEAD(4, 20, 4, 13, 0, 1, 0) };
const u16 sean_atca_052[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A41, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4A42, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A43, -34, 98, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A44, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A48, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A45, 0, 73, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A46, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 sean_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 sean_atca_054[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4A60, -35, 107, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A64, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A6C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 sean_atca_056_head[4] = { HEAD(4, 20, 3, 13, 0, 1, 0) };
const u16 sean_atca_056[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4A66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A67, -36, 115, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A68, 0, 116, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A69, 0, 116, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A6A, 0, 117, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A6B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A6C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 sean_atca_058_head[4] = { HEAD(4, 20, 5, 14, 0, 1, 0) };
const u16 sean_atca_058[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A65, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4A66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A67, -37, 118, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4A68, 0, 119, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A69, 0, 119, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A6A, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A6B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A6C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 sean_atca_060_head[4] = { HEAD(2, 24, 0, 6, 0, 1, 0) };
const u16 sean_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 sean_atca_062_head[4] = { HEAD(2, 24, 2, 9, 0, 1, 0) };
const u16 sean_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 sean_atca_064_head[4] = { HEAD(2, 24, 4, 10, 0, 1, 0) };
const u16 sean_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 sean_atca_066_head[4] = { HEAD(2, 24, 1, 5, 0, 1, 0) };
const u16 sean_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 sean_atca_068_head[4] = { HEAD(2, 24, 3, 10, 0, 1, 0) };
const u16 sean_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 sean_atca_070_head[4] = { HEAD(2, 24, 5, 11, 0, 1, 0) };
const u16 sean_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 sean_atca_072_head[4] = { HEAD(2, 28, 0, 6, 0, 1, 0) };
const u16 sean_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 sean_atca_074_head[4] = { HEAD(2, 28, 2, 9, 0, 1, 0) };
const u16 sean_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 sean_atca_076_head[4] = { HEAD(2, 28, 4, 12, 0, 1, 0) };
const u16 sean_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 sean_atca_078_head[4] = { HEAD(2, 28, 1, 5, 0, 1, 0) };
const u16 sean_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 sean_atca_080_head[4] = { HEAD(2, 28, 3, 11, 0, 1, 0) };
const u16 sean_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 sean_atca_082_head[4] = { HEAD(2, 28, 5, 9, 0, 1, 0) };
const u16 sean_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 sean_atca_084_head[4] = { HEAD(2, 26, 0, 8, 0, 1, 0) };
const u16 sean_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 sean_atca_086_head[4] = { HEAD(2, 26, 2, 11, 0, 1, 0) };
const u16 sean_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 sean_atca_088_head[4] = { HEAD(2, 26, 4, 12, 0, 1, 0) };
const u16 sean_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 sean_atca_090_head[4] = { HEAD(2, 26, 1, 7, 0, 1, 0) };
const u16 sean_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 sean_atca_092_head[4] = { HEAD(2, 26, 3, 12, 0, 1, 0) };
const u16 sean_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 sean_atca_094_head[4] = { HEAD(2, 26, 5, 13, 0, 1, 0) };
const u16 sean_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 sean_atca_096_head[4] = { HEAD(2, 30, 0, 6, 0, 1, 0) };
const u16 sean_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 sean_atca_098_head[4] = { HEAD(2, 30, 2, 9, 0, 1, 0) };
const u16 sean_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 sean_atca_100_head[4] = { HEAD(2, 30, 4, 10, 0, 1, 0) };
const u16 sean_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 sean_atca_102_head[4] = { HEAD(2, 30, 1, 5, 0, 1, 0) };
const u16 sean_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 sean_atca_104_head[4] = { HEAD(2, 30, 3, 10, 0, 1, 0) };
const u16 sean_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 sean_atca_106_head[4] = { HEAD(2, 30, 5, 11, 0, 1, 0) };
const u16 sean_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 sean_atca_108_head[4] = { HEAD(2, 16, 0, 6, 0, 1, 0) };
const u16 sean_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 sean_atca_110_head[4] = { HEAD(2, 16, 2, 9, 0, 1, 0) };
const u16 sean_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 sean_atca_112_head[4] = { HEAD(2, 16, 4, 10, 0, 1, 0) };
const u16 sean_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 sean_atca_114_head[4] = { HEAD(2, 16, 1, 5, 0, 1, 0) };
const u16 sean_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 sean_atca_116_head[4] = { HEAD(2, 16, 3, 11, 0, 1, 0) };
const u16 sean_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 sean_atca_118_head[4] = { HEAD(2, 16, 5, 11, 0, 1, 0) };
const u16 sean_atca_118[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 sean_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_atca_144[92] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BF0, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4BF0, -48, 97, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BF1, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BF2, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4BF3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BF4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BF4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4BF5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4BF5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 sean_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of M PUNCH A */
const u16 sean_atca_156_head[4] = { HEAD(6, 0, 5, 11, 0, 1, 0) };
const u16 sean_atca_156[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x49B3, 0, 46, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B4, -9, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B4, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B4, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x49B5, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49B6, 0, 46, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49B7, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49B8, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49B9, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x49BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x49BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x49BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of L PUNCH A */
const u16 sean_atca_157_head[4] = { HEAD(4, 0, 4, 6, 0, 2, 0) };
const u16 sean_atca_157[148] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x4B5A, 0, 140, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B5B, 0, 139, 0, 0, 0, 32, 149),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4B5C, 0, 141, 0, 0, 0, 32, 150),
    CMD(CM_SETR, 2, 4, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B5D, 0, 141, 0, 0, 0, 32, 151),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B5E, -97, 142, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B5F, -98, 143, 0, 139, 0, 32, 152),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B60, 7, 144, 0, 139, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B61, 0, 145, 0, 0, 0, 21, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B60, 7, 145, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B62, 0, 146, 0, 0, 0, 32, 153),
    L4(10, 0, 0, 0, 0, 0, 0, 0x4B63, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B64, 0, 6, 0, 0, 0, 32, 154),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4B65, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX sean_olc_ix_table[25] = {
    { { 0, 0, 0, 0 } },
    { { 0, 0, 1, 0 } },
    { { 0, 0, 2, 0 } },
    { { 0, 3, 0, 0 } },
    { { 0, 4, 0, 0 } },
    { { 0, 0, 5, 0 } },
    { { 0, 0, 6, 0 } },
    { { 0, 0, 7, 0 } },
    { { 0, 0, 8, 0 } },
    { { 0, 0, 9, 0 } },
    { { 0, 0, 10, 0 } },
    { { 0, 0, 11, 0 } },
    { { 0, 0, 12, 0 } },
    { { 0, 0, 13, 0 } },
    { { 0, 0, 14, 0 } },
    { { 0, 0, 15, 0 } },
    { { 0, 0, 16, 0 } },
    { { 17, 0, 0, 0 } },
    { { 18, 0, 0, 0 } },
    { { 19, 0, 0, 0 } },
    { { 20, 0, 0, 0 } },
    { { 21, 0, 0, 0 } },
    { { 22, 0, 0, 0 } },
    { { 23, 0, 0, 0 } },
    { { 24, 0, 0, 0 } },
};

const OVERLAP_PARTS sean_overlap_char_tbl[25] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19267 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19268 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 19269 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 19270 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19271 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19272 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19273 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19274 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 1, 19275 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 1, 39336 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 2, 39337 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 3, 39338 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 4, 39339 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 5, 39340 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 6, 39341 },
    { 0, 0, 0, 6, 2, 0, 255, 0, 0, 7, 39342 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 19471 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 18, 19472 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 19, 19471 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 19475 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 19472 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 19473 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 19475 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 19474 },
};

const CatchTable sean_rival_catch_tbl[1080] = {
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
    { 16, -34, 2, 1, 6 },
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
    { 44, 51, 1, 1, 7 },
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
    { -40, 0, 1, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -46, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -86, 0, 1, 1, 1 },
    { -50, 0, 2, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -67, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -46, 0, 1, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -94, 0, 1, 1, 2 },
    { -52, 0, 2, 1, 2 },
    { -46, 0, 2, 1, 2 },
    { -46, 0, 2, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -76, 0, 1, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -40, 0, 1, 1, 3 },
    { -49, 0, 2, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -20, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 3 },
    { -49, 0, 1, 1, 3 },
    { -39, 2, 1, 1, 3 },
    { -44, 0, 2, 1, 3 },
    { -44, 0, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { -39, 0, 2, 1, 3 },
    { -53, 0, 1, 1, 3 },
    { -54, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -43, 1, 1, 1, 4 },
    { -48, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -30, 0, 2, 1, 4 },
    { -41, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -60, 1, 1, 1, 4 },
    { -50, 3, 1, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -30, 0, 2, 1, 4 },
    { -33, 0, 2, 1, 4 },
    { -33, 0, 2, 1, 4 },
    { -43, 1, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -32, 0, 2, 1, 4 },
    { -57, 2, 1, 1, 4 },
    { -51, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { -48, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -42, 0, 1, 1, 5 },
    { -32, 1, 1, 1, 5 },
    { -35, 2, 1, 1, 5 },
    { -25, 4, 1, 1, 5 },
    { -37, 1, 1, 1, 5 },
    { -60, 2, 1, 1, 5 },
    { -59, -1, 1, 1, 5 },
    { -51, 2, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -52, 3, 1, 1, 5 },
    { -32, 4, 1, 1, 5 },
    { -34, 2, 1, 1, 5 },
    { -34, 2, 1, 1, 5 },
    { -42, 0, 1, 1, 5 },
    { -35, 2, 1, 1, 5 },
    { -35, 2, 1, 1, 5 },
    { -48, 11, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -46, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 6 },
    { -32, 2, 1, 1, 6 },
    { -36, 18, 1, 1, 6 },
    { -52, 17, 1, 1, 6 },
    { -43, 4, 1, 1, 6 },
    { -40, 4, 1, 1, 6 },
    { -59, 8, 1, 1, 6 },
    { -58, 8, 1, 1, 6 },
    { -50, 17, 1, 1, 6 },
    { -50, 17, 1, 1, 6 },
    { -50, 17, 1, 1, 6 },
    { -38, 9, 1, 1, 6 },
    { -38, 9, 1, 1, 6 },
    { -40, 0, 1, 1, 6 },
    { -36, 18, 1, 1, 6 },
    { -36, 18, 1, 1, 6 },
    { -49, 18, 1, 1, 6 },
    { -79, 30, 1, 1, 6 },
    { -65, 0, 1, 1, 6 },
    { -43, 1, 1, 1, 6 },
    { -68, 10, 1, 1, 7 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -65, -6, 1, 1, 7 },
    { -32, 4, 1, 1, 7 },
    { -64, 24, 1, 1, 7 },
    { -43, 25, 1, 1, 7 },
    { -61, 11, 1, 1, 7 },
    { -50, 16, 1, 1, 7 },
    { -63, 4, 1, 1, 7 },
    { -63, 22, 1, 1, 7 },
    { -52, 28, 1, 1, 7 },
    { -52, 28, 1, 1, 7 },
    { -38, 18, 1, 1, 7 },
    { -35, 18, 1, 1, 7 },
    { -35, 18, 1, 1, 7 },
    { -65, -6, 1, 1, 7 },
    { -64, 24, 1, 1, 7 },
    { -64, 24, 1, 1, 7 },
    { -55, 18, 1, 1, 7 },
    { -81, 29, 1, 1, 7 },
    { -64, 8, 1, 1, 7 },
    { -50, 3, 1, 1, 7 },
    { -68, 10, 1, 1, 8 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -71, -5, 1, 1, 8 },
    { -65, 17, 1, 1, 8 },
    { -58, 28, 1, 1, 8 },
    { -40, 29, 1, 1, 8 },
    { -58, 6, 1, 1, 8 },
    { -48, 19, 1, 1, 8 },
    { -63, 9, 1, 1, 8 },
    { -62, 12, 1, 1, 8 },
    { -64, 26, 1, 1, 8 },
    { -64, 26, 1, 1, 8 },
    { -34, 20, 1, 1, 8 },
    { -58, 26, 1, 1, 8 },
    { -58, 26, 1, 1, 8 },
    { -71, -5, 1, 1, 8 },
    { -58, 28, 1, 1, 8 },
    { -58, 28, 1, 1, 8 },
    { -50, 10, 1, 1, 8 },
    { -80, 20, 1, 1, 8 },
    { -67, 1, 1, 1, 8 },
    { -52, 18, 1, 1, 8 },
    { -70, 4, 1, 1, 9 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -60, -10, 1, 1, 9 },
    { -61, 13, 1, 1, 9 },
    { -48, 20, 1, 1, 9 },
    { -42, 12, 1, 1, 9 },
    { -55, 5, 1, 1, 9 },
    { -32, 8, 1, 1, 9 },
    { -47, 0, 1, 1, 9 },
    { -50, 4, 1, 1, 9 },
    { -64, 20, 1, 1, 9 },
    { -64, 20, 1, 1, 9 },
    { -36, 6, 1, 1, 9 },
    { -49, 22, 1, 1, 9 },
    { -49, 22, 1, 1, 9 },
    { -60, -10, 1, 1, 9 },
    { -48, 20, 1, 1, 9 },
    { -48, 20, 1, 1, 9 },
    { -39, 0, 2, 1, 3 },
    { -53, 0, 1, 1, 3 },
    { -54, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -50, -9, 1, 1, 10 },
    { -22, 4, 1, 1, 10 },
    { -44, 16, 1, 1, 10 },
    { -24, 2, 2, 1, 10 },
    { -32, 0, 2, 1, 10 },
    { -28, 0, 1, 1, 10 },
    { -51, 0, 1, 1, 10 },
    { -43, 3, 1, 1, 10 },
    { -34, 5, 1, 1, 10 },
    { -34, 5, 1, 1, 10 },
    { -26, 2, 1, 1, 10 },
    { -43, 13, 1, 1, 10 },
    { -43, 13, 1, 1, 10 },
    { -50, -9, 1, 1, 10 },
    { -44, 16, 1, 1, 10 },
    { -44, 16, 1, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -40, 0, 1, 1, 11 },
    { -28, 2, 1, 1, 11 },
    { -30, 0, 2, 1, 11 },
    { -20, 0, 2, 1, 11 },
    { -32, 0, 1, 1, 11 },
    { -44, 0, 2, 1, 11 },
    { -34, 0, 2, 1, 11 },
    { -42, 1, 1, 1, 11 },
    { -32, 0, 2, 1, 11 },
    { -32, 0, 2, 1, 11 },
    { -25, 1, 1, 1, 11 },
    { -30, 0, 2, 1, 11 },
    { -30, 0, 2, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -30, 0, 2, 1, 11 },
    { -30, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -71, 2, 2, 1, 12 },
    { -65, 17, 2, 1, 12 },
    { -58, 28, 2, 1, 12 },
    { -43, 25, 1, 1, 12 },
    { -58, 6, 1, 1, 12 },
    { -48, 19, 1, 1, 12 },
    { -34, 16, 2, 1, 12 },
    { -27, 8, 2, 1, 12 },
    { -28, 5, 2, 1, 12 },
    { -28, 5, 2, 1, 12 },
    { -13, 8, 2, 1, 12 },
    { -60, 28, 2, 1, 12 },
    { -60, 28, 2, 1, 12 },
    { -71, 2, 2, 1, 12 },
    { -58, 28, 2, 1, 12 },
    { -58, 28, 2, 1, 12 },
    { -57, 0, 1, 1, 9 },
    { -74, 5, 1, 1, 9 },
    { -95, 7, 1, 1, 9 },
    { -68, 12, 1, 1, 9 },
    { -70, 2, 1, 1, 12 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -80, 0, 1, 1, 1 },
    { -86, -2, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -78, -25, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -104, 0, 1, 1, 1 },
    { -66, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -39, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 1 },
    { -100, 0, 1, 1, 1 },
    { -102, 0, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -78, -5, 1, 1, 2 },
    { -78, -5, 1, 1, 2 },
    { -35, 0, 1, 1, 2 },
    { -35, -5, 1, 1, 2 },
    { -68, -11, 1, 1, 2 },
    { -63, 0, 1, 1, 2 },
    { -105, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -57, 0, 1, 1, 2 },
    { -35, -5, 1, 1, 2 },
    { -35, 0, 1, 1, 2 },
    { -35, 0, 1, 1, 2 },
    { -78, -5, 1, 1, 2 },
    { -35, 0, 1, 1, 2 },
    { -35, 0, 1, 1, 2 },
    { -86, -37, 1, 1, 2 },
    { -102, 10, 1, 1, 2 },
    { -131, 0, 1, 1, 2 },
    { -63, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -108, -28, 2, 1, 3 },
    { -120, -30, 2, 1, 3 },
    { -76, -1, 2, 1, 3 },
    { -54, 23, 2, 1, 3 },
    { -74, -11, 2, 1, 3 },
    { -90, -25, 2, 1, 3 },
    { -123, -20, 2, 1, 3 },
    { -91, 29, 2, 1, 3 },
    { -88, 28, 2, 1, 3 },
    { -86, -2, 2, 1, 3 },
    { -54, 23, 2, 1, 3 },
    { -76, -1, 2, 1, 3 },
    { -76, -1, 2, 1, 3 },
    { -108, -28, 2, 1, 3 },
    { -76, -1, 2, 1, 3 },
    { -76, -1, 2, 1, 3 },
    { -117, -24, 2, 1, 3 },
    { -125, 3, 2, 1, 3 },
    { -139, 0, 2, 1, 3 },
    { -90, -25, 2, 1, 3 },
    { -94, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -88, -32, 2, 1, 4 },
    { -105, 41, 2, 1, 4 },
    { -91, 2, 2, 1, 4 },
    { -62, 16, 2, 1, 4 },
    { -74, 22, 2, 1, 4 },
    { -95, -28, 2, 1, 4 },
    { -129, -23, 2, 1, 4 },
    { -102, 27, 2, 1, 4 },
    { -94, 35, 2, 1, 4 },
    { -102, -8, 2, 1, 4 },
    { -62, 16, 2, 1, 4 },
    { -91, 2, 2, 1, 4 },
    { -91, 2, 2, 1, 4 },
    { -88, -32, 2, 1, 4 },
    { -91, 2, 2, 1, 4 },
    { -91, 2, 2, 1, 4 },
    { -126, -25, 2, 1, 4 },
    { -145, 6, 2, 1, 4 },
    { -166, -22, 2, 1, 4 },
    { -95, -28, 2, 1, 4 },
    { -106, -6, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -60, -60, 1, 1, 5 },
    { -62, -31, 1, 1, 5 },
    { -64, -9, 1, 1, 5 },
    { -40, -17, 1, 1, 5 },
    { -37, -7, 1, 1, 5 },
    { -69, -70, 1, 1, 5 },
    { -90, -76, 2, 1, 5 },
    { -57, -39, 1, 1, 5 },
    { -57, -10, 1, 1, 5 },
    { -67, -49, 1, 1, 5 },
    { -40, -17, 1, 1, 5 },
    { -64, -9, 1, 1, 5 },
    { -64, -9, 1, 1, 5 },
    { -60, -60, 1, 1, 5 },
    { -64, -9, 1, 1, 5 },
    { -64, -9, 1, 1, 5 },
    { -89, -34, 1, 1, 5 },
    { -97, -35, 1, 1, 5 },
    { -71, -34, 1, 1, 5 },
    { -69, -79, 1, 1, 5 },
    { -68, -48, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, -22, 1, 1, 6 },
    { -64, -20, 1, 1, 6 },
    { -69, -25, 1, 1, 6 },
    { -28, -37, 1, 1, 6 },
    { -42, -25, 1, 1, 6 },
    { -65, -64, 1, 1, 6 },
    { -81, -16, 1, 1, 6 },
    { -56, -38, 1, 1, 6 },
    { -63, -28, 1, 1, 6 },
    { -58, -25, 1, 1, 6 },
    { -28, -37, 1, 1, 6 },
    { -69, -25, 1, 1, 6 },
    { -69, -25, 1, 1, 6 },
    { -64, -22, 1, 1, 6 },
    { -69, -25, 1, 1, 6 },
    { -69, -25, 1, 1, 6 },
    { -81, -24, 1, 1, 6 },
    { -86, -25, 1, 1, 6 },
    { -80, -24, 1, 1, 6 },
    { -65, -64, 1, 1, 6 },
    { -72, -20, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -70, -16, 1, 1, 7 },
    { -78, -12, 1, 1, 7 },
    { -74, -16, 1, 1, 7 },
    { -52, -20, 1, 1, 7 },
    { -61, -15, 1, 1, 7 },
    { -93, -30, 1, 1, 7 },
    { -67, -19, 1, 1, 7 },
    { -66, -13, 1, 1, 7 },
    { -56, -25, 1, 1, 7 },
    { -54, -20, 1, 1, 7 },
    { -52, -20, 1, 1, 7 },
    { -74, -16, 1, 1, 7 },
    { -74, -16, 1, 1, 7 },
    { -70, -16, 1, 1, 7 },
    { -74, -16, 1, 1, 7 },
    { -74, -16, 1, 1, 7 },
    { -68, -19, 1, 1, 7 },
    { -77, -20, 1, 1, 7 },
    { -62, -19, 1, 1, 7 },
    { -73, -20, 1, 1, 7 },
    { -68, -16, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -72, -24, 1, 1, 8 },
    { -73, -10, 1, 1, 8 },
    { -73, -14, 1, 1, 8 },
    { -70, -18, 1, 1, 8 },
    { -56, -9, 1, 1, 8 },
    { -69, -20, 1, 1, 8 },
    { -58, -16, 1, 1, 8 },
    { -69, -14, 1, 1, 8 },
    { -52, -24, 1, 1, 8 },
    { -46, -15, 1, 1, 8 },
    { -70, -18, 1, 1, 8 },
    { -73, -14, 1, 1, 8 },
    { -73, -14, 1, 1, 8 },
    { -72, -24, 1, 1, 8 },
    { -73, -14, 1, 1, 8 },
    { -73, -14, 1, 1, 8 },
    { -60, -14, 1, 1, 8 },
    { -75, -15, 1, 1, 8 },
    { -56, -14, 1, 1, 8 },
    { -69, -20, 1, 1, 8 },
    { -54, -11, 1, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, -16, 1, 1, 9 },
    { -65, -5, 1, 1, 9 },
    { -72, -9, 1, 1, 9 },
    { -66, -10, 1, 1, 9 },
    { -51, -10, 1, 1, 9 },
    { -63, -10, 1, 1, 9 },
    { -50, -11, 1, 1, 9 },
    { -69, -9, 1, 1, 9 },
    { -50, -17, 1, 1, 9 },
    { -32, -10, 1, 1, 9 },
    { -66, -10, 1, 1, 9 },
    { -72, -9, 1, 1, 9 },
    { -72, -9, 1, 1, 9 },
    { -68, -16, 1, 1, 9 },
    { -72, -9, 1, 1, 9 },
    { -72, -9, 1, 1, 9 },
    { -50, -9, 1, 1, 9 },
    { -68, -10, 1, 1, 9 },
    { -47, -9, 1, 1, 9 },
    { -63, -10, 1, 1, 9 },
    { -60, 6, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 2, 1, 1, 10 },
    { -50, 0, 1, 1, 10 },
    { -57, -4, 1, 1, 10 },
    { -62, -4, 1, 1, 10 },
    { -44, -5, 1, 1, 10 },
    { -60, -5, 1, 1, 10 },
    { -33, -5, 1, 1, 10 },
    { -59, -5, 1, 1, 10 },
    { -45, -14, 1, 1, 10 },
    { -8, -5, 1, 1, 10 },
    { -62, -4, 1, 1, 10 },
    { -57, -4, 1, 1, 10 },
    { -57, -4, 1, 1, 10 },
    { -48, 2, 1, 1, 10 },
    { -57, -4, 1, 1, 10 },
    { -57, -4, 1, 1, 10 },
    { -35, -4, 1, 1, 10 },
    { -53, -5, 1, 1, 10 },
    { -31, -4, 1, 1, 10 },
    { -60, -5, 1, 1, 10 },
    { -44, 1, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, 0, 1, 1, 11 },
    { -47, 5, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -56, 0, 1, 1, 11 },
    { -44, 0, 1, 1, 11 },
    { -57, 0, 1, 1, 11 },
    { -30, 0, 1, 1, 11 },
    { -58, 0, 1, 1, 11 },
    { -46, -4, 1, 1, 11 },
    { -4, 0, 1, 1, 11 },
    { -56, 0, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -54, 0, 1, 1, 11 },
    { -30, 1, 1, 1, 11 },
    { -50, 0, 1, 1, 11 },
    { -30, 1, 1, 1, 11 },
    { -57, 0, 1, 1, 11 },
    { -48, 4, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, -6, 1, 1, 12 },
    { -47, 5, 1, 1, 12 },
    { -54, 0, 1, 1, 12 },
    { -56, 0, 1, 1, 12 },
    { -44, 0, 1, 1, 12 },
    { -57, 0, 1, 1, 12 },
    { -30, 0, 1, 1, 12 },
    { -58, 0, 1, 1, 12 },
    { -46, -4, 1, 1, 12 },
    { -5, 0, 1, 1, 12 },
    { -56, 0, 1, 1, 12 },
    { -54, 0, 1, 1, 12 },
    { -54, 0, 1, 1, 12 },
    { -54, -6, 1, 1, 12 },
    { -54, 0, 1, 1, 12 },
    { -54, 0, 1, 1, 12 },
    { -30, 1, 1, 1, 12 },
    { -50, 0, 1, 1, 12 },
    { -30, 1, 1, 1, 12 },
    { -57, 0, 1, 1, 12 },
    { -48, 4, 1, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, -2, 1, 1, 13 },
    { -47, -1, 1, 1, 13 },
    { -48, 0, 1, 1, 13 },
    { -51, 0, 1, 1, 13 },
    { -40, -10, 1, 1, 13 },
    { -57, 0, 1, 1, 13 },
    { -39, 0, 1, 1, 13 },
    { -62, 0, 1, 1, 13 },
    { -51, -6, 1, 1, 13 },
    { -8, 0, 1, 1, 13 },
    { -51, 0, 1, 1, 13 },
    { -48, 0, 1, 1, 13 },
    { -48, 0, 1, 1, 13 },
    { -54, -2, 1, 1, 13 },
    { -48, 0, 1, 1, 13 },
    { -48, 0, 1, 1, 13 },
    { -30, -25, 1, 1, 13 },
    { -53, 0, 1, 1, 13 },
    { -30, 1, 1, 1, 13 },
    { -57, 0, 1, 1, 13 },
    { -48, 4, 1, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 14 },
    { -47, -1, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -51, 0, 1, 1, 14 },
    { -40, -10, 1, 1, 14 },
    { -57, 0, 1, 1, 14 },
    { -34, 0, 1, 1, 14 },
    { -62, 0, 1, 1, 14 },
    { -51, -6, 1, 1, 14 },
    { -8, 0, 1, 1, 14 },
    { -51, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { -30, 0, 1, 1, 14 },
    { -53, 0, 1, 1, 14 },
    { -30, 0, 1, 1, 14 },
    { -57, 0, 1, 1, 14 },
    { -48, 0, 1, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 52 entries */
const u16* const sean_exca[53] = {
    sean_exca_000,  /* 0 follow-up of AIR NORMAL */
    sean_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    sean_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    sean_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    sean_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    sean_exca_005,  /* 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
    sean_exca_006,  /* 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
    sean_exca_007,  /* 7 no name */
    sean_exca_008,  /* 8 follow-up of KUNOJI, IBUKI +2 */
    sean_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +2 */
    sean_exca_010,  /* 10 follow-up of KIRIMOMI, SPLASH.M +1 */
    sean_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    sean_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    sean_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    sean_exca_014,  /* 14 no name */
    sean_exca_015,  /* 15 no name */
    sean_exca_016,  /* 16 no name */
    sean_exca_017,  /* 17 no name */
    sean_exca_018,  /* 18 no name */
    sean_exca_019,  /* 19 no name */
    sean_exca_020,  /* 20 no name */
    sean_exca_021,  /* 21 no name */
    sean_exca_022,  /* 22 follow-up of APPEAR 5 */
    sean_exca_023,  /* 23 follow-up of HARAIGOSHI, APPEAR 5 */
    sean_exca_024,  /* 24 no name */
    sean_exca_025,  /* 25 no name */
    sean_exca_026,  /* 26 follow-up of APPEAR JUNBI 7 */
    sean_exca_026,  /* 27 follow-up of APPEAR JUNBI 7 */
    sean_exca_028,  /* 28 no name */
    sean_exca_029,  /* 29 follow-up of APPEAR JUNBI 1 */
    sean_exca_030,  /* 30 follow-up of APPEAR JUNBI 1 */
    sean_exca_031,  /* 31 follow-up of APPEAR 3 */
    sean_exca_032,  /* 32 follow-up of APPEAR 3 */
    sean_exca_033,  /* 33 follow-up of GILL IMPACT C, APPEAR 4 */
    sean_exca_034,  /* 34 follow-up of GILL IMPACT C, APPEAR 4 */
    sean_exca_035,  /* 35 follow-up of SP APPEAR 7 */
    sean_exca_036,  /* 36 follow-up of SP APPEAR 7 */
    sean_exca_037,  /* 37 follow-up of SP APPEAR 8 */
    sean_exca_038,  /* 38 follow-up of SP APPEAR 8 */
    sean_exca_039,  /* 39 follow-up of ZANNEN 1 */
    sean_exca_040,  /* 40 follow-up of ZANNEN 1 */
    sean_exca_041,  /* 41 follow-up of APPEAR 2 */
    sean_exca_042,  /* 42 follow-up of APPEAR 2 */
    sean_exca_043,  /* 43 follow-up of ZANNEN 2 */
    sean_exca_044,  /* 44 follow-up of ZANNEN 2 */
    sean_exca_043,  /* 45 follow-up of ZANNEN 3 */
    sean_exca_044,  /* 46 follow-up of ZANNEN 3 */
    sean_exca_047,  /* 47 follow-up of ZANNEN 4 */
    sean_exca_048,  /* 48 follow-up of ZANNEN 4 */
    sean_exca_049,  /* 49 follow-up of WIN 2 */
    sean_exca_050,  /* 50 follow-up of WIN 2 */
    sean_exca_051,  /* 51 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 sean_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_000[100] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4852, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4851, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4850, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x484F, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484E, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484D, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x484C, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4858, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 sean_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_001[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 sean_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_003[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x48FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 sean_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_004[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
const u16 sean_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_005[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x48E8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48E9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
const u16 sean_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_006[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 no name */
const u16 sean_exca_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_007[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B2B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4B2C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, IBUKI +2 */
const u16 sean_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_008[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4900, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4901, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4902, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4903, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +2 */
const u16 sean_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_009[124] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x4900, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4901, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4902, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4903, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, SPLASH.M +1 */
const u16 sean_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_010[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x48FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x48EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 sean_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_011[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 sean_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_013[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 sean_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FA, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 sean_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_015[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 sean_exca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x4902, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x4901, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x48FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 sean_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_017[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 30, 274, 0, 0, 0, 0, 0x4AC9, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4ACA, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x482A, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 sean_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 18, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 sean_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x4902, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x4901, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x48FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x48E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x48E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 sean_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_020[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 3, 0, 0, 0x48E0, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x4925, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x490A, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4903, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4903, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 sean_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 3, 0, 0, 0x4906, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4900, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x48FF, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4B13, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x48FB, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48FB, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of APPEAR 5 */
const u16 sean_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_022[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49BC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x49C6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI, APPEAR 5 */
const u16 sean_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_023[84] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4828, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 no name */
const u16 sean_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_024[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 274, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B2B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4B2B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 22, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 no name */
const u16 sean_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_025[52] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 274, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4828, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 23, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR JUNBI 7, 27 follow-up of APPEAR JUNBI 7 */
const u16 sean_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_026[52] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4884, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4885, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4886, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4887, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 no name */
const u16 sean_exca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_028[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x48E3, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48E4, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E5, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x48E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x48E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR JUNBI 1 */
const u16 sean_exca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_029[76] = {
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR JUNBI 1 */
const u16 sean_exca_030_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_030[52] = {
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR 3 */
const u16 sean_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_031[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC9, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x4ACA, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4949, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x494A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 3 */
const u16 sean_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_032[60] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(5, 64, 0, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x482B, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x482C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of GILL IMPACT C, APPEAR 4 */
const u16 sean_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_033[68] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x48FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of GILL IMPACT C, APPEAR 4 */
const u16 sean_exca_034_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 sean_exca_034[60] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x48FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x48F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x48F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x48F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x48F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x48F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 7 */
const u16 sean_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_035[76] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x4BCF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BD0, 0, 2, 0, 0, 0, 22, 32),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BD1, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BD2, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4BD3, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BD4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of SP APPEAR 7 */
const u16 sean_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_036[52] = {
    L4(2, 0, 274, 0, 0, 0, 0, 0x4BCF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 22, 32),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of SP APPEAR 8 */
const u16 sean_exca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_037[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of SP APPEAR 8 */
const u16 sean_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_038[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of ZANNEN 1 */
const u16 sean_exca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_039[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x482A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of ZANNEN 1 */
const u16 sean_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_040[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of APPEAR 2 */
const u16 sean_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_041[68] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of APPEAR 2 */
const u16 sean_exca_042_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_042[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of ZANNEN 2, 45 follow-up of ZANNEN 3 */
const u16 sean_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_043[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x4883, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x4884, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4885, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4886, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4887, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of ZANNEN 2, 46 follow-up of ZANNEN 3 */
const u16 sean_exca_044_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_044[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4883, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4888, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of ZANNEN 4 */
const u16 sean_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_047[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x488C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4884, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4885, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4886, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4887, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x480D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of ZANNEN 4 */
const u16 sean_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 sean_exca_048[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4883, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4888, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4829, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of WIN 2 */
const u16 sean_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_049[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B98, 0, 1, 0, 0, 0, 32, 188),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B99, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9A, 0, 1, 0, 0, 0, 32, 189),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4B9B, 0, 1, 0, 0, 0, 32, 189),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B9C, 0, 1, 0, 0, 0, 32, 188),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B9D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of WIN 2 */
const u16 sean_exca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_exca_050[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4B98, 0, 1, 0, 0, 0, 32, 188),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B99, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9A, 0, 1, 0, 0, 0, 32, 189),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4B9B, 0, 1, 0, 0, 0, 32, 189),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B9C, 0, 1, 0, 0, 0, 32, 188),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4B9F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 sean_exca_051_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 sean_exca_051[100] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4852, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4851, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4850, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x484F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x484D, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x484C, 0, 254, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4858, 0, 254, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 75 entries */
const u16* const sean_saca[76] = {
    sean_saca_000,  /* 0 UP P GUARD P S */
    sean_saca_001,  /* 1 UP P GUARD P M */
    sean_saca_002,  /* 2 UP P GUARD P L */
    sean_saca_002,  /* 3 UP P GUARD K S */
    sean_saca_002,  /* 4 UP P GUARD K M */
    sean_saca_002,  /* 5 UP P GUARD K L */
    sean_saca_000,  /* 6 D P GUARD P S */
    sean_saca_001,  /* 7 D P GUARD P M */
    sean_saca_002,  /* 8 D P GUARD P L */
    sean_saca_002,  /* 9 D P GUARD K S */
    sean_saca_002,  /* 10 D P GUARD K M */
    sean_saca_002,  /* 11 D P GUARD K L */
    sean_saca_002,  /* 12 FUSHIN P S */
    sean_saca_002,  /* 13 FUSHIN P M */
    sean_saca_002,  /* 14 FUSHIN P L */
    sean_saca_002,  /* 15 FUSHIN K S */
    sean_saca_002,  /* 16 FUSHIN K M */
    sean_saca_002,  /* 17 FUSHIN K L */
    sean_saca_002,  /* 18 OKIAGARI P S */
    sean_saca_002,  /* 19 OKIAGARI P M */
    sean_saca_002,  /* 20 OKIAGARI P L */
    sean_saca_002,  /* 21 OKIAGARI K S */
    sean_saca_002,  /* 22 OKIAGARI K M */
    sean_saca_002,  /* 23 OKIAGARI K L */
    sean_saca_024,  /* 24 ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI) */
    sean_saca_025,  /* 25 ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI) */
    sean_saca_026,  /* 26 ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) */
    sean_saca_027,  /* 27 ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
    sean_saca_028,  /* 28 ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN) */
    sean_saca_029,  /* 29 ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) */
    sean_saca_030,  /* 30 ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    sean_saca_031,  /* 31 ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    sean_saca_032,  /* 32 ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    sean_saca_032,  /* 33 ATTACK 3 M: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    sean_saca_032,  /* 34 ATTACK 3 L: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    sean_saca_035,  /* 35 ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    sean_saca_036,  /* 36 ATTACK 4 S: SA I 23623+P (plain script) */
    sean_saca_036,  /* 37 ATTACK 4 M: SA I 23623+P (plain script) */
    sean_saca_036,  /* 38 ATTACK 4 L: SA I 23623+P (plain script) */
    sean_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+P (plain script) */
    sean_saca_040,  /* 40 ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    sean_saca_040,  /* 41 ATTACK 5 M: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    sean_saca_040,  /* 42 ATTACK 5 L: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    sean_saca_040,  /* 43 ATTACK 5 SP: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    sean_saca_044,  /* 44 ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    sean_saca_044,  /* 45 ATTACK 6 M: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    sean_saca_044,  /* 46 ATTACK 6 L: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    sean_saca_044,  /* 47 ATTACK 6 SP: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    sean_saca_048,  /* 48 ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI) */
    sean_saca_049,  /* 49 ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI) */
    sean_saca_050,  /* 50 ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    sean_saca_050,  /* 51 ATTACK 7 SP: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    sean_saca_052,  /* 52 ATTACK 8 S: not started by a command */
    sean_saca_052,  /* 53 ATTACK 8 M: not started by a command */
    sean_saca_052,  /* 54 ATTACK 8 L: not started by a command */
    sean_saca_052,  /* 55 ATTACK 8 SP: not started by a command */
    sean_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    sean_saca_056,  /* 57 ATTACK 9 M: not started by a command */
    sean_saca_056,  /* 58 ATTACK 9 L: not started by a command */
    sean_saca_056,  /* 59 ATTACK 9 SP: not started by a command */
    sean_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    sean_saca_060,  /* 61 ATTACK 10 M: not started by a command */
    sean_saca_060,  /* 62 ATTACK 10 L: not started by a command */
    sean_saca_060,  /* 63 ATTACK 10 SP: not started by a command */
    sean_saca_064,  /* 64 ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU) */
    sean_saca_065,  /* 65 ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) */
    sean_saca_066,  /* 66 ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    sean_saca_067,  /* 67 ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    sean_saca_068,  /* 68 ATTACK 12 S: not started by a command */
    sean_saca_069,  /* 69 ATTACK 12 M: not started by a command */
    sean_saca_069,  /* 70 ATTACK 12 L: not started by a command */
    sean_saca_071,  /* 71 ATTACK 12 SP: not started by a command */
    sean_saca_071,  /* 72 ATTACK 13 S: not started by a command */
    sean_saca_071,  /* 73 ATTACK 13 M: not started by a command */
    sean_saca_071,  /* 74 ATTACK 13 L: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 sean_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F6, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F7, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FC, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FD, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70FE, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1024, 8192), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 sean_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 sean_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70FE, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70FD, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70FD, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70FA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F8, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F7, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F6, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F4, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 sean_saca_002_head[4] = { HEAD(2, 0, 0, 11, 0, 1, 0) };
const u16 sean_saca_002[8] = {
    L2(20, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_024_head[4] = { HEAD(4, 32, 8, 12, 0, 1, 21) };
const u16 sean_saca_024[180] = {
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(1, 20, 503, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(2, 0, 279, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4B33, 0, 77, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B34, 0, 77, 0, 0, 0, 30, 15),
    CMD(CM_IF_S, 16, 16389, 8192), 0, 0, 0, 0,
    L4(6, 21, 0, 0, 0, 0, 0, 0x4B35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 21, 269, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x4B37, -52, 79, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 78, 0, 0, 0, 21, 0),
    L4(5, 0, 502, 0, 0, 2, 0, 0x4B38, 0, 78, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x4B3B, 0, 80, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B3C, 0, 80, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4B35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_025_head[4] = { HEAD(4, 32, 8, 12, 0, 1, 21) };
const u16 sean_saca_025[100] = {
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(1, 20, 503, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(4, 0, 279, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B33, 0, 77, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x4B34, 0, 77, 0, 0, 0, 30, 15),
    CMD(CM_IF_S, 32, 8192, 8194), 0, 0, 0, 0,
    L4(1, 21, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x4B37, -52, 79, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 78, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 24, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_026_head[4] = { HEAD(4, 32, 8, 12, 0, 1, 21) };
const u16 sean_saca_026[100] = {
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(2, 20, 503, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(4, 0, 279, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(8, 0, 0, 0, 0, 0, 0, 0x4B33, 0, 77, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x4B34, 0, 77, 0, 0, 0, 30, 15),
    CMD(CM_IF_S, 64, 8192, 8194), 0, 0, 0, 0,
    L4(1, 21, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x4B37, -52, 79, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 78, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 24, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_027_head[4] = { HEAD(4, 32, 14, 12, 0, 1, 21) };
const u16 sean_saca_027[132] = {
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 20, 503, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(4, 0, 279, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 1, 37),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4B33, 0, 77, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4B34, 0, 77, 0, 0, 0, 30, 15),
    CMD(CM_WSET, 16385, 0, 112), 0, 0, 0, 0,
    CMD(CM_WSWK, 16385, 1, 16396), 0, 0, 0, 0,
    CMD(CM_WCEQ2, 16384, 16385, 16386), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 21, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4B36, 0, 78, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x4B37, -88, 79, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 1, 0, 0x4B37, 0, 78, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 24, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN) */
const u16 sean_saca_028_head[4] = { HEAD(4, 0, 9, 12, 0, 2, 20) };
const u16 sean_saca_028[172] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4977, 0, 6, 0, 0, 0, 1, 26),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4ABC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4ABD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 20, 499, 0, 0, 0, 0, 0x4ABE, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC1, -56, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC2, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4AC3, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC4, -58, 121, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 0, 0, 0x4AC5, 0, 122, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC6, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC7, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4846, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4846, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4847, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4848, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) */
const u16 sean_saca_029_head[4] = { HEAD(4, 0, 11, 12, 0, 3, 20) };
const u16 sean_saca_029[156] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4977, 0, 6, 0, 0, 0, 1, 26),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4ABC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4ABD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 499, 0, 0, 0, 0, 0x4ABE, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AC1, -56, 121, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4AC2, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4AC3, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC4, -58, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC5, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC6, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 12, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC1, -57, 121, 0, 64, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 12, 0x4A71, 0, 120, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A71, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A72, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 28, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
const u16 sean_saca_030_head[4] = { HEAD(4, 0, 13, 12, 0, 4, 20) };
const u16 sean_saca_030[196] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4977, 0, 6, 0, 0, 0, 1, 26),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49B0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 12, 0x4ABC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x4A73, 0, 120, 0, 0, 0, 32, 140),
    L4(3, 0, 499, 0, 0, 0, 12, 0x4A74, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 12, 0x4A75, -59, 123, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A76, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A77, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4AC6, 0, 120, 0, 0, 0, 32, 64),
    L4(1, 0, 0, 0, 0, 0, 12, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 12, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AC1, -85, 121, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4AC2, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4AC3, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AC4, -84, 121, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC5, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC6, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 12, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC1, -85, 121, 0, 64, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 12, 0x4A71, 0, 122, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A72, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 28, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
const u16 sean_saca_031_head[4] = { HEAD(4, 0, 15, 12, 0, 4, 20) };
const u16 sean_saca_031[188] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4977, 0, 6, 0, 0, 0, 1, 26),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49B0, 0, 1, 0, 0, 0, 32, 210),
    L4(2, 20, 499, 0, 0, 0, 12, 0x4A74, 0, 120, 0, 0, 0, 32, 211),
    L4(2, 0, 270, 0, 0, 0, 12, 0x4A75, -90, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A76, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4A77, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4AC6, 0, 120, 0, 0, 0, 32, 64),
    L4(1, 0, 0, 0, 0, 0, 12, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 12, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4AC1, -92, 121, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4AC2, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4AC3, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AC4, -91, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC5, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4AC6, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x4ABF, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 12, 0x4AC0, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AC1, -92, 121, 0, 0, 0, 0, 0),
    L4(3, 30, 270, 0, 0, 0, 12, 0x4A71, 0, 122, 0, 0, 0, 21, 0),
    L4(3, 0, 270, 0, 0, 0, 12, 0x4A72, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 28, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), 33 ATTACK 3 M: 236+K light/medium/heavy (routine Att_ABISEGERI), 34 ATTACK 3 L: 236+K light/medium/heavy (routine Att_ABISEGERI) */
const u16 sean_saca_032_head[4] = { HEAD(4, 0, 9, 11, 0, 1, 32) };
const u16 sean_saca_032[164] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x49C0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x49D9, 0, 1, 0, 0, 0, 32, 27),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DA, 0, 1, 0, 0, 0, 32, 28),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DB, 0, 1, 0, 0, 0, 32, 25),
    L4(2, 0, 496, 0, 0, 0, 0, 0x49DC, 0, 81, 0, 0, 0, 32, 27),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DD, 0, 82, 0, 0, 0, 32, 27),
    L4(8, 20, 0, 0, 0, 0, 0, 0x49E4, 0, 83, 0, 0, 0, 32, 27),
    L4(3, 0, 268, 0, 0, 0, 0, 0x49DE, 0, 83, 0, 0, 0, 32, 25),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DF, -100, 85, 0, 140, 0, 32, 26),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E0, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E5, 101, 86, 0, 143, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E6, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E1, 102, 87, 0, 146, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E2, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E3, 0, 88, 0, 0, 0, 32, 28),
    L4(250, 0, 0, 0, 0, 0, 0, 0x49E3, 0, 84, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
const u16 sean_saca_035_head[4] = { HEAD(4, 0, 15, 11, 0, 3, 32) };
const u16 sean_saca_035[164] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x49C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x49DA, 0, 1, 0, 0, 0, 32, 101),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DB, 0, 1, 0, 0, 0, 32, 102),
    L4(1, 0, 496, 0, 0, 0, 0, 0x49DC, 0, 81, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x49DD, 0, 82, 0, 0, 0, 32, 89),
    L4(12, 30, 0, 0, 0, 0, 0, 0x49E4, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x49DE, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49DF, 0, 85, 0, 140, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E0, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E5, -93, 86, 0, 143, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E6, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E1, -94, 87, 0, 146, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E2, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x49E3, -99, 88, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x49E3, 0, 84, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+P (plain script), 37 ATTACK 4 M: SA I 23623+P (plain script), 38 ATTACK 4 L: SA I 23623+P (plain script), 39 ATTACK 4 SP: SA I 23623+P (plain script) */
const u16 sean_saca_036_head[4] = { HEAD(6, 0, 48, 13, 0, 1, 0) };
const u16 sean_saca_036[304] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 500, 0, 0, 0, 0, 0x4AA0, 0, 74, 0, 0, 0, 13, 13, 0, 0, 210, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AAC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 10, 0, 0x4AA1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(40, 0, 0, 0, 0, 11, 0, 0x4AA2, 0, 74, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(1, 0, 0, 0, 0, 12, 0, 0x4AA3, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 13, 0, 0x4AA4, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x4AA4, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x4AA4, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 501, 0, 0, 16, 0, 0x4AA4, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AA5, 0, 76, 0, 0, 0, 2, 56, 0, 0, 0, 0, 0),
    L6(3, 0, 320, 0, 0, 0, 0, 0x4AA5, 0, 76, 0, 0, 0, 30, 14, 0, 0, 62, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AA8, 0, 76, 0, 0, 0, 30, 15, 0, 0, 222, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AA9, 0, 76, 0, 0, 0, 21, 0, 0, 0, 222, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AA8, 0, 76, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4AA9, 0, 76, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4AA8, 0, 76, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4AA9, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4AA8, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4AA9, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4AAA, 0, 75, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x4AAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4893, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), 41 ATTACK 5 M: SA III 23623+P (routine Att_SLIDE_and_JUMP), 42 ATTACK 5 L: SA III 23623+P (routine Att_SLIDE_and_JUMP), 43 ATTACK 5 SP: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 sean_saca_040_head[4] = { HEAD(6, 0, 32, 12, 0, 11, 8) };
const u16 sean_saca_040[904] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 0, 0, 0, 0, 0, 0x4B34, 0, 30, 0, 0, 0, 13, 14, 776, 0, 0, 0, 0),
    L6(2, 30, 498, 0, 0, 0, 0, 0x4B34, 0, 30, 0, 0, 0, 1, 25, 776, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4870, -64, 125, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4871, 0, 126, 0, 141, 0, 0, 0, 0, 192, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4B39, 0, 127, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4B3A, 0, 127, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 40, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 30, 0, 0, 0, 0, 0, 0x4B3A, 0, 128, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 502, 0, 0, 2, 0, 0x4B38, 0, 78, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(24, 0, 0, 0, 0, 0, 0, 0x4B3B, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x4B39, -73, 127, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_RVXY, 1, 16384, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B39, 0, 127, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_RVXY, 1, 16384, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4B3A, 0, 127, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49FC, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49FD, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49FE, -72, 129, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49FF, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4A00, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4A01, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x498C, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4990, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4991, -71, 129, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4992, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4993, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4996, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B0, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B1, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B2, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B3, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x49B4, -96, 129, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B5, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B6, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B7, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B8, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49B9, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49BA, 0, 1, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 20, 499, 0, 0, 0, 0, 0x4ABC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4ABC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4ABD, -60, 130, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4ABE, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AC0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AC1, -61, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x4AC2, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AC3, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AC4, -62, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x4AC5, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AC6, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 496, 0, 0, 0, 0, 0x49DD, 0, 83, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x49E4, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x49DE, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49DF, -67, 39, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49E0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49E5, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49E6, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49E1, -68, 41, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x49E2, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x49E3, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4848, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4849, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x484A, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), 45 ATTACK 6 M: SA II 23623+P (routine Att_SHOURYUUREPPA), 46 ATTACK 6 L: SA II 23623+P (routine Att_SHOURYUUREPPA), 47 ATTACK 6 SP: SA II 23623+P (routine Att_SHOURYUUREPPA) */
const u16 sean_saca_044_head[4] = { HEAD(6, 0, 32, 9, 0, 16, 8) };
const u16 sean_saca_044[448] = {
    CMD(CM_RJA, 5, 44, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 490, 0, 0, 0, 0, 0x4AAE, 0, 74, 0, 0, 0, 13, 1, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AAF, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AB0, 0, 74, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(40, 0, 0, 0, 0, 0, 0, 0x4AB1, 0, 74, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 494, 0, 0, 0, 0, 0x4AB2, -41, 89, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x4AB5, -42, 90, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AB5, 42, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AB5, 42, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AB6, 42, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AB7, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4AB8, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4ABB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AB0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AB0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 495, 0, 0, 0, 0, 0x4AB1, -43, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AB2, -43, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x4AB3, -46, 93, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 44, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AB4, 0, 93, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AB5, -46, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AB5, -46, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AB5, -46, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AB5, -46, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AB5, -46, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 30, 0, 0, 0, 0, 0, 0x4AB6, 0, 91, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AB7, 0, 91, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AB8, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AB9, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4ABA, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4ACB, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_048_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 sean_saca_048[160] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x494C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x494D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x494E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x494F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4950, 0, 29, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4951, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_049_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 sean_saca_049[280] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x494C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4950, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 8, 0, 0, 0, 0, 0, 0x4951, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4952, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494B, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 8, 0, 0, 0, 0, 0, 0x494E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x494F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4950, 0, 29, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4951, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI), 51 ATTACK 7 SP: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
const u16 sean_saca_050_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 sean_saca_050[280] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x494C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x494F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4950, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 8, 0, 0, 0, 0, 0, 0x4951, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4952, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494B, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 8, 0, 0, 0, 0, 0, 0x494E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x494F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4950, 0, 29, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4951, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4946, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x482C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: not started by a command, 53 ATTACK 8 M: not started by a command, 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command */
const u16 sean_saca_052_head[4] = { HEAD(2, 0, 32, 12, 0, 2, 8) };
const u16 sean_saca_052[8] = {
    L2(4, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 sean_saca_056_head[4] = { HEAD(2, 0, 8, 9, 0, 1, 1) };
const u16 sean_saca_056[8] = {
    L2(4, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command, 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command, 63 ATTACK 10 SP: not started by a command */
const u16 sean_saca_060_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 sean_saca_060[108] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4829, 0, 50, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x4A41, 0, 4, 0, 0, 0, 22, 20),
    L4(4, 0, 269, 0, 0, 0, 0, 0x4A42, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A44, -77, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4A48, 0, 138, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A45, 0, 138, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4A46, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4A47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4856, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU) */
const u16 sean_saca_064_head[4] = { HEAD(4, 0, 8, 11, 0, 1, 1) };
const u16 sean_saca_064[100] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(3, 0, 485, 0, 0, 0, 0, 0x4BC2, 0, 2, 0, 0, 0, 32, 197),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC3, 0, 2, 0, 0, 64, 32, 198),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BC6, -74, 95, 0, 64, 64, 32, 198),
    L4(1, 20, 0, 0, 0, 0, 0, 0x4BC7, 75, 182, 0, 0, 0, 32, 199),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC8, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BCA, 0, 184, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BCB, 0, 184, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BCC, 0, 184, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCD, 0, 185, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4BCE, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) */
const u16 sean_saca_065_head[4] = { HEAD(4, 0, 10, 11, 0, 1, 1) };
const u16 sean_saca_065[108] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BC1, 0, 2, 0, 0, 0, 32, 200),
    L4(2, 0, 485, 0, 0, 0, 0, 0x4BC2, 0, 2, 0, 0, 0, 32, 200),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC3, 0, 2, 0, 0, 0, 32, 200),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC5, -74, 95, 0, 64, 64, 32, 201),
    L4(1, 20, 0, 0, 0, 0, 0, 0x4BC7, 75, 181, 0, 0, 0, 32, 202),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC8, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4BCA, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BCB, 0, 184, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCC, 0, 184, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCD, 0, 185, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4BCE, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) */
const u16 sean_saca_066_head[4] = { HEAD(4, 0, 12, 11, 0, 1, 1) };
const u16 sean_saca_066[124] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4BC0, 0, 2, 0, 0, 0, 32, 203),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC1, 0, 2, 0, 0, 0, 32, 204),
    L4(2, 0, 485, 0, 0, 0, 0, 0x4BC2, 0, 2, 0, 0, 0, 32, 205),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC3, 0, 2, 0, 0, 64, 32, 206),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4BC4, 0, 2, 0, 0, 0, 32, 207),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC5, -74, 95, 0, 64, 64, 32, 208),
    L4(1, 20, 0, 0, 0, 0, 0, 0x4BC7, 75, 181, 0, 0, 0, 32, 209),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC8, 0, 182, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BCA, 0, 183, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCB, 0, 184, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCC, 0, 184, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4BCD, 0, 185, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4BCE, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
const u16 sean_saca_067_head[4] = { HEAD(4, 0, 14, 11, 0, 2, 1) };
const u16 sean_saca_067[148] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC0, 0, 30, 0, 0, 0, 32, 164),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4BC1, 0, 30, 0, 0, 0, 32, 165),
    L4(2, 0, 485, 0, 0, 0, 0, 0x4BC2, 0, 30, 0, 0, 0, 32, 166),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4BC3, 0, 30, 0, 0, 0, 32, 167),
    L4(1, 0, 270, 0, 0, 0, 0, 0x4BC4, 0, 30, 0, 0, 0, 32, 168),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4BC5, -103, 94, 0, 138, 64, 32, 169),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4BC6, 0, 94, 0, 0, 64, 32, 170),
    L4(2, 20, 0, 0, 0, 0, 0, 0x4BC7, -104, 181, 0, 0, 0, 32, 171),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4BC8, 105, 182, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCA, 0, 183, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCB, 0, 184, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4BCC, 0, 184, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4BCD, 0, 185, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4BCE, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: not started by a command */
const u16 sean_saca_068_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_saca_068[172] = {
    CMD(CM_RJA, 5, 68, 14), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 68, 8), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4B70, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 20, 281, 0, 0, 0, 0, 0x4B71, 0, 28, 0, 0, 0, 22, 22),
    L4(13, 40, 0, 0, 0, 0, 0, 0x4B72, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x4B72, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4B71, 0, 28, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x4AD6, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4AD7, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16390, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 497, 0, 0, 0, 0, 0x4AD8, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 30, 0, 0, 0, 0, 0, 0x4AD9, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4ADA, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_IF_L, 2, 16388, 8192), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x482A, 0, 2, 0, 0, 0, 22, 32),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: not started by a command, 70 ATTACK 12 L: not started by a command */
const u16 sean_saca_069_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_saca_069[84] = {
    CMD(CM_RJA, 5, 68, 14), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4B70, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 20, 281, 0, 0, 0, 0, 0x4B71, 0, 28, 0, 0, 0, 22, 22),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B72, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 492, 0, 0, 0, 0, 0x4B75, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4B76, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4B77, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4B78, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x4B79, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4B7A, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: not started by a command, 72 ATTACK 13 S: not started by a command, 73 ATTACK 13 M: not started by a command, 74 ATTACK 13 L: not started by a command */
const u16 sean_saca_071_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_saca_071[156] = {
    CMD(CM_RJA, 5, 71, 16), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 71, 9), 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4B70, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 20, 281, 0, 0, 0, 0, 0x4B71, 0, 28, 0, 0, 0, 22, 22),
    L4(14, 40, 0, 0, 0, 0, 0, 0x4B72, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4B72, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4B71, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AD6, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 497, 0, 0, 0, 0, 0x4AD7, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16390, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AD9, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_WADD, 16384, 1, 32767), 0, 0, 0, 0,
    CMD(CM_WCLT2, 16384, 16389, -32760), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x4ADA, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 34 entries */
const u16* const sean_cbca[35] = {
    sean_cbca_000,  /* 0 APPEAR JUNBI 1 */
    sean_cbca_001,  /* 1 APPEAR JUNBI 2 */
    sean_cbca_002,  /* 2 APPEAR JUNBI 3 */
    sean_cbca_003,  /* 3 APPEAR JUNBI 4 */
    sean_cbca_004,  /* 4 APPEAR JUNBI 5 */
    sean_cbca_005,  /* 5 APPEAR JUNBI 6 */
    sean_cbca_006,  /* 6 APPEAR JUNBI 7 */
    sean_cbca_007,  /* 7 APPEAR JUNBI 8 */
    sean_cbca_008,  /* 8 APPEAR 1 */
    sean_cbca_009,  /* 9 APPEAR 2 */
    sean_cbca_010,  /* 10 APPEAR 3 */
    sean_cbca_011,  /* 11 APPEAR 4 */
    sean_cbca_012,  /* 12 APPEAR 5 */
    sean_cbca_013,  /* 13 APPEAR 6 */
    sean_cbca_014,  /* 14 APPEAR 7 */
    sean_cbca_015,  /* 15 APPEAR 8 */
    sean_cbca_016,  /* 16 SP APPEAR 1 */
    sean_cbca_017,  /* 17 SP APPEAR 2 */
    sean_cbca_018,  /* 18 SP APPEAR 3 */
    sean_cbca_019,  /* 19 SP APPEAR 4 */
    sean_cbca_020,  /* 20 SP APPEAR 5 */
    sean_cbca_021,  /* 21 SP APPEAR 6 */
    sean_cbca_022,  /* 22 SP APPEAR 7 */
    sean_cbca_023,  /* 23 SP APPEAR 8 */
    sean_cbca_024,  /* 24 ZANNEN 1 */
    sean_cbca_025,  /* 25 ZANNEN 2 */
    sean_cbca_026,  /* 26 ZANNEN 3 */
    sean_cbca_027,  /* 27 ZANNEN 4 */
    sean_cbca_028,  /* 28 ZANNEN 5 */
    sean_cbca_029,  /* 29 ZANNEN 6 */
    sean_cbca_030,  /* 30 ZANNEN 7 */
    sean_cbca_031,  /* 31 ZANNEN 8 */
    sean_cbca_032,  /* 32 WIN 1 */
    sean_cbca_033,  /* 33 WIN 2 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 sean_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 30, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 sean_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 sean_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 sean_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 sean_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 sean_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 sean_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 sean_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_007[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 sean_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_008[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 sean_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_009[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 41, 1),
    CMD(CM_RJA3, 7, 42, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 sean_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_010[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 32, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 sean_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_011[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 sean_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_012[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 22, 1),
    CMD(CM_RJA3, 7, 23, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 sean_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_013[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 sean_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_014[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 sean_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_015[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 sean_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_016[40] = {
    CMD(CM_RJA6, 8, 16, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RJA7, 4, 3, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RJA7, 4, 3, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 17 SP APPEAR 2 */
const u16 sean_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_017[40] = {
    CMD(CM_RJA6, 8, 17, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RJA7, 4, 4, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RJA7, 4, 4, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 18 SP APPEAR 3 */
const u16 sean_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_018[40] = {
    CMD(CM_RJA6, 8, 18, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RJA7, 4, 12, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RJA7, 4, 12, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 19 SP APPEAR 4 */
const u16 sean_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_019[40] = {
    CMD(CM_RJA6, 8, 19, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RJA7, 4, 7, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RJA7, 4, 7, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 20 SP APPEAR 5 */
const u16 sean_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_020[40] = {
    CMD(CM_RJA6, 8, 20, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 21 SP APPEAR 6 */
const u16 sean_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_021[40] = {
    CMD(CM_RJA6, 8, 21, 7),
    CMD(CM_DJMP, 8192, 8199, 8192),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RJA7, 4, 17, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RJA7, 4, 17, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 22 SP APPEAR 7 */
const u16 sean_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_022[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 36, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 sean_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_023[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 sean_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_024[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 sean_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_025[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 sean_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_026[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 sean_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_027[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 sean_cbca_028_head[4] = { HEAD(2, 0, 15, 12, 0, 0, 32) };
const u16 sean_cbca_028[16] = {
    CMD(CM_EXEC, 49, 28, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 sean_cbca_029_head[4] = { HEAD(2, 0, 15, 12, 0, 0, 20) };
const u16 sean_cbca_029[16] = {
    CMD(CM_EXEC, 49, 29, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 sean_cbca_030_head[4] = { HEAD(2, 32, 14, 14, 0, 0, 21) };
const u16 sean_cbca_030[36] = {
    CMD(CM_EXEC, 49, 30, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_WSET, 16384, 0, 112),
    CMD(CM_WSWK, 16384, 1, 16396),
    CMD(CM_CAFR, 2, 1, 18),
    CMD(CM_CARE, 2, 1, 18),
    CMD(CM_RJA, 5, 24, 8),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 sean_cbca_031_head[4] = { HEAD(2, 0, 14, 9, 0, 0, 1) };
const u16 sean_cbca_031[16] = {
    CMD(CM_EXEC, 49, 31, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 sean_cbca_032_head[4] = { HEAD(2, 32, 8, 12, 0, 0, 21) };
const u16 sean_cbca_032[16] = {
    CMD(CM_CAFR, 2, 1, 9),
    CMD(CM_CARE, 2, 1, 9),
    CMD(CM_RJA, 5, 24, 8),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 sean_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_cbca_033[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

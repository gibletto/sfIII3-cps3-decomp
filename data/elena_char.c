/*
 * ELENA_CHAR.C  Elena's animation scripts and sprite part tables
 *
 * The animation scripts Elena's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 elena_nmca_000[], elena_nmca_001[], elena_nmca_002[], elena_nmca_003[], elena_nmca_004[], elena_nmca_005[], elena_nmca_006[], elena_nmca_007[], elena_nmca_008[], elena_nmca_011[], elena_nmca_012[], elena_nmca_013[], elena_nmca_014[], elena_nmca_015[], elena_nmca_016[], elena_nmca_017[], elena_nmca_020[], elena_nmca_021[], elena_nmca_022[], elena_nmca_023[], elena_nmca_024[], elena_nmca_026[], elena_nmca_027[], elena_nmca_029[], elena_nmca_030[], elena_nmca_031[], elena_nmca_032[], elena_nmca_033[], elena_nmca_034[], elena_nmca_035[], elena_nmca_036[], elena_nmca_037[], elena_nmca_038[], elena_nmca_040[], elena_nmca_041[], elena_nmca_043[], elena_nmca_044[], elena_nmca_045[], elena_nmca_046[], elena_nmca_047[], elena_nmca_048[], elena_nmca_049[], elena_nmca_050[];
extern const u16 elena_nmca_000_head[];
extern const u16 elena_nmca_001_head[];
extern const u16 elena_nmca_002_head[];
extern const u16 elena_nmca_003_head[];
extern const u16 elena_nmca_004_head[];
extern const u16 elena_nmca_005_head[];
extern const u16 elena_nmca_006_head[];
extern const u16 elena_nmca_007_head[];
extern const u16 elena_nmca_008_head[];
extern const u16 elena_nmca_011_head[];
extern const u16 elena_nmca_012_head[];
extern const u16 elena_nmca_013_head[];
extern const u16 elena_nmca_014_head[];
extern const u16 elena_nmca_015_head[];
extern const u16 elena_nmca_016_head[];
extern const u16 elena_nmca_017_head[];
extern const u16 elena_nmca_020_head[];
extern const u16 elena_nmca_021_head[];
extern const u16 elena_nmca_022_head[];
extern const u16 elena_nmca_023_head[];
extern const u16 elena_nmca_024_head[];
extern const u16 elena_nmca_026_head[];
extern const u16 elena_nmca_027_head[];
extern const u16 elena_nmca_029_head[];
extern const u16 elena_nmca_030_head[];
extern const u16 elena_nmca_031_head[];
extern const u16 elena_nmca_032_head[];
extern const u16 elena_nmca_033_head[];
extern const u16 elena_nmca_034_head[];
extern const u16 elena_nmca_035_head[];
extern const u16 elena_nmca_036_head[];
extern const u16 elena_nmca_037_head[];
extern const u16 elena_nmca_038_head[];
extern const u16 elena_nmca_040_head[];
extern const u16 elena_nmca_041_head[];
extern const u16 elena_nmca_043_head[];
extern const u16 elena_nmca_044_head[];
extern const u16 elena_nmca_045_head[];
extern const u16 elena_nmca_046_head[];
extern const u16 elena_nmca_047_head[];
extern const u16 elena_nmca_048_head[];
extern const u16 elena_nmca_049_head[];
extern const u16 elena_nmca_050_head[];
extern const u16 elena_dmca_000[], elena_dmca_001[], elena_dmca_002[], elena_dmca_003[], elena_dmca_004[], elena_dmca_006[], elena_dmca_008[], elena_dmca_009[], elena_dmca_010[], elena_dmca_018[], elena_dmca_019[], elena_dmca_014[], elena_dmca_015[], elena_dmca_022[], elena_dmca_028[], elena_dmca_025[], elena_dmca_026[], elena_dmca_036[], elena_dmca_040[], elena_dmca_048[], elena_dmca_049[], elena_dmca_050[], elena_dmca_052[], elena_dmca_056[], elena_dmca_060[], elena_dmca_064[], elena_dmca_065[], elena_dmca_066[], elena_dmca_067[], elena_dmca_068[], elena_dmca_070[], elena_dmca_071[], elena_dmca_072[], elena_dmca_073[], elena_dmca_074[], elena_dmca_075[], elena_dmca_076[], elena_dmca_078[], elena_dmca_079[], elena_dmca_080[], elena_dmca_082[], elena_dmca_083[], elena_dmca_084[], elena_dmca_090[], elena_dmca_091[], elena_dmca_096[], elena_dmca_097[];
extern const u16 elena_dmca_000_head[];
extern const u16 elena_dmca_001_head[];
extern const u16 elena_dmca_002_head[];
extern const u16 elena_dmca_003_head[];
extern const u16 elena_dmca_004_head[];
extern const u16 elena_dmca_006_head[];
extern const u16 elena_dmca_008_head[];
extern const u16 elena_dmca_009_head[];
extern const u16 elena_dmca_010_head[];
extern const u16 elena_dmca_018_head[];
extern const u16 elena_dmca_019_head[];
extern const u16 elena_dmca_014_head[];
extern const u16 elena_dmca_015_head[];
extern const u16 elena_dmca_022_head[];
extern const u16 elena_dmca_028_head[];
extern const u16 elena_dmca_025_head[];
extern const u16 elena_dmca_026_head[];
extern const u16 elena_dmca_036_head[];
extern const u16 elena_dmca_040_head[];
extern const u16 elena_dmca_048_head[];
extern const u16 elena_dmca_049_head[];
extern const u16 elena_dmca_050_head[];
extern const u16 elena_dmca_052_head[];
extern const u16 elena_dmca_056_head[];
extern const u16 elena_dmca_060_head[];
extern const u16 elena_dmca_064_head[];
extern const u16 elena_dmca_065_head[];
extern const u16 elena_dmca_066_head[];
extern const u16 elena_dmca_067_head[];
extern const u16 elena_dmca_068_head[];
extern const u16 elena_dmca_070_head[];
extern const u16 elena_dmca_071_head[];
extern const u16 elena_dmca_072_head[];
extern const u16 elena_dmca_073_head[];
extern const u16 elena_dmca_074_head[];
extern const u16 elena_dmca_075_head[];
extern const u16 elena_dmca_076_head[];
extern const u16 elena_dmca_078_head[];
extern const u16 elena_dmca_079_head[];
extern const u16 elena_dmca_080_head[];
extern const u16 elena_dmca_082_head[];
extern const u16 elena_dmca_083_head[];
extern const u16 elena_dmca_084_head[];
extern const u16 elena_dmca_090_head[];
extern const u16 elena_dmca_091_head[];
extern const u16 elena_dmca_096_head[];
extern const u16 elena_dmca_097_head[];
extern const u16 elena_btca_000[], elena_btca_001[], elena_btca_002[], elena_btca_003[], elena_btca_004[], elena_btca_005[], elena_btca_010[], elena_btca_011[], elena_btca_013[], elena_btca_014[], elena_btca_015[], elena_btca_016[], elena_btca_017[], elena_btca_018[], elena_btca_009[], elena_btca_020[], elena_btca_022[], elena_btca_024[], elena_btca_025[], elena_btca_026[], elena_btca_027[], elena_btca_028[], elena_btca_029[], elena_btca_030[], elena_btca_031[], elena_btca_032[], elena_btca_033[], elena_btca_034[];
extern const u16 elena_btca_000_head[];
extern const u16 elena_btca_001_head[];
extern const u16 elena_btca_002_head[];
extern const u16 elena_btca_003_head[];
extern const u16 elena_btca_004_head[];
extern const u16 elena_btca_005_head[];
extern const u16 elena_btca_010_head[];
extern const u16 elena_btca_011_head[];
extern const u16 elena_btca_013_head[];
extern const u16 elena_btca_014_head[];
extern const u16 elena_btca_015_head[];
extern const u16 elena_btca_016_head[];
extern const u16 elena_btca_017_head[];
extern const u16 elena_btca_018_head[];
extern const u16 elena_btca_009_head[];
extern const u16 elena_btca_020_head[];
extern const u16 elena_btca_022_head[];
extern const u16 elena_btca_024_head[];
extern const u16 elena_btca_025_head[];
extern const u16 elena_btca_026_head[];
extern const u16 elena_btca_027_head[];
extern const u16 elena_btca_028_head[];
extern const u16 elena_btca_029_head[];
extern const u16 elena_btca_030_head[];
extern const u16 elena_btca_031_head[];
extern const u16 elena_btca_032_head[];
extern const u16 elena_btca_033_head[];
extern const u16 elena_btca_034_head[];
extern const u16 elena_caca_000[], elena_caca_001[];
extern const u16 elena_caca_000_head[];
extern const u16 elena_caca_001_head[];
extern const u16 elena_cuca_000[], elena_cuca_001[], elena_cuca_002[], elena_cuca_003[], elena_cuca_004[], elena_cuca_005[], elena_cuca_006[], elena_cuca_007[], elena_cuca_008[], elena_cuca_009[], elena_cuca_010[], elena_cuca_011[], elena_cuca_012[], elena_cuca_013[], elena_cuca_014[], elena_cuca_015[], elena_cuca_016[], elena_cuca_017[], elena_cuca_018[], elena_cuca_019[], elena_cuca_020[], elena_cuca_021[], elena_cuca_022[], elena_cuca_023[], elena_cuca_024[], elena_cuca_025[], elena_cuca_026[], elena_cuca_027[], elena_cuca_028[], elena_cuca_029[], elena_cuca_030[], elena_cuca_031[], elena_cuca_032[], elena_cuca_033[], elena_cuca_034[], elena_cuca_035[], elena_cuca_036[], elena_cuca_037[], elena_cuca_038[], elena_cuca_039[], elena_cuca_040[], elena_cuca_041[], elena_cuca_042[], elena_cuca_043[], elena_cuca_044[], elena_cuca_045[], elena_cuca_046[], elena_cuca_047[], elena_cuca_048[], elena_cuca_049[], elena_cuca_050[], elena_cuca_051[], elena_cuca_052[], elena_cuca_053[], elena_cuca_054[], elena_cuca_055[], elena_cuca_056[], elena_cuca_057[], elena_cuca_058[], elena_cuca_059[], elena_cuca_060[], elena_cuca_061[], elena_cuca_062[], elena_cuca_063[], elena_cuca_064[], elena_cuca_065[], elena_cuca_066[], elena_cuca_067[];
extern const u16 elena_cuca_000_head[];
extern const u16 elena_cuca_001_head[];
extern const u16 elena_cuca_002_head[];
extern const u16 elena_cuca_003_head[];
extern const u16 elena_cuca_004_head[];
extern const u16 elena_cuca_005_head[];
extern const u16 elena_cuca_006_head[];
extern const u16 elena_cuca_007_head[];
extern const u16 elena_cuca_008_head[];
extern const u16 elena_cuca_009_head[];
extern const u16 elena_cuca_010_head[];
extern const u16 elena_cuca_011_head[];
extern const u16 elena_cuca_012_head[];
extern const u16 elena_cuca_013_head[];
extern const u16 elena_cuca_014_head[];
extern const u16 elena_cuca_015_head[];
extern const u16 elena_cuca_016_head[];
extern const u16 elena_cuca_017_head[];
extern const u16 elena_cuca_018_head[];
extern const u16 elena_cuca_019_head[];
extern const u16 elena_cuca_020_head[];
extern const u16 elena_cuca_021_head[];
extern const u16 elena_cuca_022_head[];
extern const u16 elena_cuca_023_head[];
extern const u16 elena_cuca_024_head[];
extern const u16 elena_cuca_025_head[];
extern const u16 elena_cuca_026_head[];
extern const u16 elena_cuca_027_head[];
extern const u16 elena_cuca_028_head[];
extern const u16 elena_cuca_029_head[];
extern const u16 elena_cuca_030_head[];
extern const u16 elena_cuca_031_head[];
extern const u16 elena_cuca_032_head[];
extern const u16 elena_cuca_033_head[];
extern const u16 elena_cuca_034_head[];
extern const u16 elena_cuca_035_head[];
extern const u16 elena_cuca_036_head[];
extern const u16 elena_cuca_037_head[];
extern const u16 elena_cuca_038_head[];
extern const u16 elena_cuca_039_head[];
extern const u16 elena_cuca_040_head[];
extern const u16 elena_cuca_041_head[];
extern const u16 elena_cuca_042_head[];
extern const u16 elena_cuca_043_head[];
extern const u16 elena_cuca_044_head[];
extern const u16 elena_cuca_045_head[];
extern const u16 elena_cuca_046_head[];
extern const u16 elena_cuca_047_head[];
extern const u16 elena_cuca_048_head[];
extern const u16 elena_cuca_049_head[];
extern const u16 elena_cuca_050_head[];
extern const u16 elena_cuca_051_head[];
extern const u16 elena_cuca_052_head[];
extern const u16 elena_cuca_053_head[];
extern const u16 elena_cuca_054_head[];
extern const u16 elena_cuca_055_head[];
extern const u16 elena_cuca_056_head[];
extern const u16 elena_cuca_057_head[];
extern const u16 elena_cuca_058_head[];
extern const u16 elena_cuca_059_head[];
extern const u16 elena_cuca_060_head[];
extern const u16 elena_cuca_061_head[];
extern const u16 elena_cuca_062_head[];
extern const u16 elena_cuca_063_head[];
extern const u16 elena_cuca_064_head[];
extern const u16 elena_cuca_065_head[];
extern const u16 elena_cuca_066_head[];
extern const u16 elena_cuca_067_head[];
extern const u16 elena_atca_000[], elena_atca_002[], elena_atca_003[], elena_atca_005[], elena_atca_006[], elena_atca_009[], elena_atca_012[], elena_atca_014[], elena_atca_015[], elena_atca_017[], elena_atca_018[], elena_atca_021[], elena_atca_024[], elena_atca_027[], elena_atca_030[], elena_atca_033[], elena_atca_035[], elena_atca_036[], elena_atca_038[], elena_atca_040[], elena_atca_042[], elena_atca_044[], elena_atca_046[], elena_atca_048[], elena_atca_050[], elena_atca_052[], elena_atca_054[], elena_atca_056[], elena_atca_058[], elena_atca_060[], elena_atca_062[], elena_atca_064[], elena_atca_066[], elena_atca_068[], elena_atca_070[], elena_atca_072[], elena_atca_074[], elena_atca_076[], elena_atca_078[], elena_atca_080[], elena_atca_082[], elena_atca_084[], elena_atca_086[], elena_atca_088[], elena_atca_090[], elena_atca_092[], elena_atca_094[], elena_atca_096[], elena_atca_098[], elena_atca_100[], elena_atca_102[], elena_atca_104[], elena_atca_106[], elena_atca_108[], elena_atca_110[], elena_atca_112[], elena_atca_114[], elena_atca_116[], elena_atca_118[], elena_atca_145[], elena_atca_144[], elena_atca_156[], elena_atca_157[], elena_atca_158[], elena_atca_159[];
extern const u16 elena_atca_000_head[];
extern const u16 elena_atca_002_head[];
extern const u16 elena_atca_003_head[];
extern const u16 elena_atca_005_head[];
extern const u16 elena_atca_006_head[];
extern const u16 elena_atca_009_head[];
extern const u16 elena_atca_012_head[];
extern const u16 elena_atca_014_head[];
extern const u16 elena_atca_015_head[];
extern const u16 elena_atca_017_head[];
extern const u16 elena_atca_018_head[];
extern const u16 elena_atca_021_head[];
extern const u16 elena_atca_024_head[];
extern const u16 elena_atca_027_head[];
extern const u16 elena_atca_030_head[];
extern const u16 elena_atca_033_head[];
extern const u16 elena_atca_035_head[];
extern const u16 elena_atca_036_head[];
extern const u16 elena_atca_038_head[];
extern const u16 elena_atca_040_head[];
extern const u16 elena_atca_042_head[];
extern const u16 elena_atca_044_head[];
extern const u16 elena_atca_046_head[];
extern const u16 elena_atca_048_head[];
extern const u16 elena_atca_050_head[];
extern const u16 elena_atca_052_head[];
extern const u16 elena_atca_054_head[];
extern const u16 elena_atca_056_head[];
extern const u16 elena_atca_058_head[];
extern const u16 elena_atca_060_head[];
extern const u16 elena_atca_062_head[];
extern const u16 elena_atca_064_head[];
extern const u16 elena_atca_066_head[];
extern const u16 elena_atca_068_head[];
extern const u16 elena_atca_070_head[];
extern const u16 elena_atca_072_head[];
extern const u16 elena_atca_074_head[];
extern const u16 elena_atca_076_head[];
extern const u16 elena_atca_078_head[];
extern const u16 elena_atca_080_head[];
extern const u16 elena_atca_082_head[];
extern const u16 elena_atca_084_head[];
extern const u16 elena_atca_086_head[];
extern const u16 elena_atca_088_head[];
extern const u16 elena_atca_090_head[];
extern const u16 elena_atca_092_head[];
extern const u16 elena_atca_094_head[];
extern const u16 elena_atca_096_head[];
extern const u16 elena_atca_098_head[];
extern const u16 elena_atca_100_head[];
extern const u16 elena_atca_102_head[];
extern const u16 elena_atca_104_head[];
extern const u16 elena_atca_106_head[];
extern const u16 elena_atca_108_head[];
extern const u16 elena_atca_110_head[];
extern const u16 elena_atca_112_head[];
extern const u16 elena_atca_114_head[];
extern const u16 elena_atca_116_head[];
extern const u16 elena_atca_118_head[];
extern const u16 elena_atca_145_head[];
extern const u16 elena_atca_144_head[];
extern const u16 elena_atca_156_head[];
extern const u16 elena_atca_157_head[];
extern const u16 elena_atca_158_head[];
extern const u16 elena_atca_159_head[];
extern const u16 elena_exca_000[], elena_exca_001[], elena_exca_004[], elena_exca_005[], elena_exca_006[], elena_exca_007[], elena_exca_008[], elena_exca_009[], elena_exca_010[], elena_exca_011[], elena_exca_014[], elena_exca_015[], elena_exca_016[], elena_exca_017[], elena_exca_018[], elena_exca_019[], elena_exca_020[], elena_exca_023[], elena_exca_024[], elena_exca_025[], elena_exca_026[], elena_exca_027[], elena_exca_028[], elena_exca_029[], elena_exca_031[], elena_exca_032[], elena_exca_033[], elena_exca_034[], elena_exca_035[], elena_exca_036[], elena_exca_037[], elena_exca_038[], elena_exca_039[], elena_exca_040[], elena_exca_041[], elena_exca_042[], elena_exca_043[], elena_exca_044[], elena_exca_045[], elena_exca_046[], elena_exca_047[], elena_exca_048[], elena_exca_049[], elena_exca_050[], elena_exca_053[], elena_exca_054[], elena_exca_055[], elena_exca_056[], elena_exca_057[], elena_exca_058[], elena_exca_059[], elena_exca_060[], elena_exca_061[], elena_exca_062[], elena_exca_063[], elena_exca_064[], elena_exca_065[], elena_exca_066[], elena_exca_067[];
extern const u16 elena_exca_000_head[];
extern const u16 elena_exca_001_head[];
extern const u16 elena_exca_004_head[];
extern const u16 elena_exca_005_head[];
extern const u16 elena_exca_006_head[];
extern const u16 elena_exca_007_head[];
extern const u16 elena_exca_008_head[];
extern const u16 elena_exca_009_head[];
extern const u16 elena_exca_010_head[];
extern const u16 elena_exca_011_head[];
extern const u16 elena_exca_014_head[];
extern const u16 elena_exca_015_head[];
extern const u16 elena_exca_016_head[];
extern const u16 elena_exca_017_head[];
extern const u16 elena_exca_018_head[];
extern const u16 elena_exca_019_head[];
extern const u16 elena_exca_020_head[];
extern const u16 elena_exca_023_head[];
extern const u16 elena_exca_024_head[];
extern const u16 elena_exca_025_head[];
extern const u16 elena_exca_026_head[];
extern const u16 elena_exca_027_head[];
extern const u16 elena_exca_028_head[];
extern const u16 elena_exca_029_head[];
extern const u16 elena_exca_031_head[];
extern const u16 elena_exca_032_head[];
extern const u16 elena_exca_033_head[];
extern const u16 elena_exca_034_head[];
extern const u16 elena_exca_035_head[];
extern const u16 elena_exca_036_head[];
extern const u16 elena_exca_037_head[];
extern const u16 elena_exca_038_head[];
extern const u16 elena_exca_039_head[];
extern const u16 elena_exca_040_head[];
extern const u16 elena_exca_041_head[];
extern const u16 elena_exca_042_head[];
extern const u16 elena_exca_043_head[];
extern const u16 elena_exca_044_head[];
extern const u16 elena_exca_045_head[];
extern const u16 elena_exca_046_head[];
extern const u16 elena_exca_047_head[];
extern const u16 elena_exca_048_head[];
extern const u16 elena_exca_049_head[];
extern const u16 elena_exca_050_head[];
extern const u16 elena_exca_053_head[];
extern const u16 elena_exca_054_head[];
extern const u16 elena_exca_055_head[];
extern const u16 elena_exca_056_head[];
extern const u16 elena_exca_057_head[];
extern const u16 elena_exca_058_head[];
extern const u16 elena_exca_059_head[];
extern const u16 elena_exca_060_head[];
extern const u16 elena_exca_061_head[];
extern const u16 elena_exca_062_head[];
extern const u16 elena_exca_063_head[];
extern const u16 elena_exca_064_head[];
extern const u16 elena_exca_065_head[];
extern const u16 elena_exca_066_head[];
extern const u16 elena_exca_067_head[];
extern const u16 elena_saca_000[], elena_saca_001[], elena_saca_002[], elena_saca_024[], elena_saca_025[], elena_saca_026[], elena_saca_027[], elena_saca_028[], elena_saca_029[], elena_saca_030[], elena_saca_031[], elena_saca_032[], elena_saca_033[], elena_saca_034[], elena_saca_035[], elena_saca_036[], elena_saca_040[], elena_saca_044[], elena_saca_046[], elena_saca_047[], elena_saca_048[], elena_saca_049[], elena_saca_050[], elena_saca_054[], elena_saca_057[], elena_saca_058[], elena_saca_059[], elena_saca_060[], elena_saca_061[], elena_saca_062[], elena_saca_063[], elena_saca_064[], elena_saca_065[], elena_saca_066[], elena_saca_067[], elena_saca_068[], elena_saca_069[], elena_saca_070[];
extern const u16 elena_saca_000_head[];
extern const u16 elena_saca_001_head[];
extern const u16 elena_saca_002_head[];
extern const u16 elena_saca_024_head[];
extern const u16 elena_saca_025_head[];
extern const u16 elena_saca_026_head[];
extern const u16 elena_saca_027_head[];
extern const u16 elena_saca_028_head[];
extern const u16 elena_saca_029_head[];
extern const u16 elena_saca_030_head[];
extern const u16 elena_saca_031_head[];
extern const u16 elena_saca_032_head[];
extern const u16 elena_saca_033_head[];
extern const u16 elena_saca_034_head[];
extern const u16 elena_saca_035_head[];
extern const u16 elena_saca_036_head[];
extern const u16 elena_saca_040_head[];
extern const u16 elena_saca_044_head[];
extern const u16 elena_saca_046_head[];
extern const u16 elena_saca_047_head[];
extern const u16 elena_saca_048_head[];
extern const u16 elena_saca_049_head[];
extern const u16 elena_saca_050_head[];
extern const u16 elena_saca_054_head[];
extern const u16 elena_saca_057_head[];
extern const u16 elena_saca_058_head[];
extern const u16 elena_saca_059_head[];
extern const u16 elena_saca_060_head[];
extern const u16 elena_saca_061_head[];
extern const u16 elena_saca_062_head[];
extern const u16 elena_saca_063_head[];
extern const u16 elena_saca_064_head[];
extern const u16 elena_saca_065_head[];
extern const u16 elena_saca_066_head[];
extern const u16 elena_saca_067_head[];
extern const u16 elena_saca_068_head[];
extern const u16 elena_saca_069_head[];
extern const u16 elena_saca_070_head[];
extern const u16 elena_cbca_000[], elena_cbca_001[], elena_cbca_002[], elena_cbca_003[], elena_cbca_004[], elena_cbca_005[], elena_cbca_006[], elena_cbca_007[], elena_cbca_008[], elena_cbca_009[], elena_cbca_010[], elena_cbca_011[], elena_cbca_012[], elena_cbca_013[], elena_cbca_014[], elena_cbca_015[], elena_cbca_016[], elena_cbca_017[], elena_cbca_018[], elena_cbca_019[], elena_cbca_020[], elena_cbca_021[], elena_cbca_022[], elena_cbca_023[], elena_cbca_024[], elena_cbca_025[], elena_cbca_026[], elena_cbca_027[], elena_cbca_028[], elena_cbca_029[], elena_cbca_030[], elena_cbca_031[], elena_cbca_032[], elena_cbca_033[], elena_cbca_034[], elena_cbca_035[], elena_cbca_036[], elena_cbca_037[], elena_cbca_038[], elena_cbca_039[], elena_cbca_040[], elena_cbca_041[], elena_cbca_042[], elena_cbca_043[], elena_cbca_044[], elena_cbca_045[], elena_cbca_046[], elena_cbca_047[], elena_cbca_048[], elena_cbca_049[], elena_cbca_050[], elena_cbca_051[], elena_cbca_052[], elena_cbca_053[], elena_cbca_054[], elena_cbca_055[], elena_cbca_056[], elena_cbca_057[], elena_cbca_058[], elena_cbca_059[], elena_cbca_060[], elena_cbca_061[], elena_cbca_062[], elena_cbca_063[], elena_cbca_064[], elena_cbca_065[], elena_cbca_066[], elena_cbca_067[], elena_cbca_068[], elena_cbca_069[], elena_cbca_070[], elena_cbca_071[], elena_cbca_072[];
extern const u16 elena_cbca_000_head[];
extern const u16 elena_cbca_001_head[];
extern const u16 elena_cbca_002_head[];
extern const u16 elena_cbca_003_head[];
extern const u16 elena_cbca_004_head[];
extern const u16 elena_cbca_005_head[];
extern const u16 elena_cbca_006_head[];
extern const u16 elena_cbca_007_head[];
extern const u16 elena_cbca_008_head[];
extern const u16 elena_cbca_009_head[];
extern const u16 elena_cbca_010_head[];
extern const u16 elena_cbca_011_head[];
extern const u16 elena_cbca_012_head[];
extern const u16 elena_cbca_013_head[];
extern const u16 elena_cbca_014_head[];
extern const u16 elena_cbca_015_head[];
extern const u16 elena_cbca_016_head[];
extern const u16 elena_cbca_017_head[];
extern const u16 elena_cbca_018_head[];
extern const u16 elena_cbca_019_head[];
extern const u16 elena_cbca_020_head[];
extern const u16 elena_cbca_021_head[];
extern const u16 elena_cbca_022_head[];
extern const u16 elena_cbca_023_head[];
extern const u16 elena_cbca_024_head[];
extern const u16 elena_cbca_025_head[];
extern const u16 elena_cbca_026_head[];
extern const u16 elena_cbca_027_head[];
extern const u16 elena_cbca_028_head[];
extern const u16 elena_cbca_029_head[];
extern const u16 elena_cbca_030_head[];
extern const u16 elena_cbca_031_head[];
extern const u16 elena_cbca_032_head[];
extern const u16 elena_cbca_033_head[];
extern const u16 elena_cbca_034_head[];
extern const u16 elena_cbca_035_head[];
extern const u16 elena_cbca_036_head[];
extern const u16 elena_cbca_037_head[];
extern const u16 elena_cbca_038_head[];
extern const u16 elena_cbca_039_head[];
extern const u16 elena_cbca_040_head[];
extern const u16 elena_cbca_041_head[];
extern const u16 elena_cbca_042_head[];
extern const u16 elena_cbca_043_head[];
extern const u16 elena_cbca_044_head[];
extern const u16 elena_cbca_045_head[];
extern const u16 elena_cbca_046_head[];
extern const u16 elena_cbca_047_head[];
extern const u16 elena_cbca_048_head[];
extern const u16 elena_cbca_049_head[];
extern const u16 elena_cbca_050_head[];
extern const u16 elena_cbca_051_head[];
extern const u16 elena_cbca_052_head[];
extern const u16 elena_cbca_053_head[];
extern const u16 elena_cbca_054_head[];
extern const u16 elena_cbca_055_head[];
extern const u16 elena_cbca_056_head[];
extern const u16 elena_cbca_057_head[];
extern const u16 elena_cbca_058_head[];
extern const u16 elena_cbca_059_head[];
extern const u16 elena_cbca_060_head[];
extern const u16 elena_cbca_061_head[];
extern const u16 elena_cbca_062_head[];
extern const u16 elena_cbca_063_head[];
extern const u16 elena_cbca_064_head[];
extern const u16 elena_cbca_065_head[];
extern const u16 elena_cbca_066_head[];
extern const u16 elena_cbca_067_head[];
extern const u16 elena_cbca_068_head[];
extern const u16 elena_cbca_069_head[];
extern const u16 elena_cbca_070_head[];
extern const u16 elena_cbca_071_head[];
extern const u16 elena_cbca_072_head[];

/* normal scripts: 51 entries */
const u16* const elena_nmca[52] = {
    elena_nmca_000,  /* 0 KAMAE */
    elena_nmca_001,  /* 1 HURIMUKI */
    elena_nmca_002,  /* 2 FRONT WALK */
    elena_nmca_003,  /* 3 BACK WALK */
    elena_nmca_004,  /* 4 DASH HUMIKOMI */
    elena_nmca_005,  /* 5 DASH TOBINOKI */
    elena_nmca_006,  /* 6 KAGAMU */
    elena_nmca_007,  /* 7 KAGAMI KAMAE */
    elena_nmca_008,  /* 8 KAGAMI TURN */
    elena_nmca_008,  /* 9 KAGAMI F WALK */
    elena_nmca_008,  /* 10 KAGAMI B WALK */
    elena_nmca_011,  /* 11 STAND UP */
    elena_nmca_012,  /* 12 JUMP JUNBI */
    elena_nmca_013,  /* 13 SP JUMP JUNBI */
    elena_nmca_014,  /* 14 JUMP FRONT */
    elena_nmca_015,  /* 15 JUMP VERTICAL */
    elena_nmca_016,  /* 16 JUMP BACK */
    elena_nmca_017,  /* 17 S JUMP FRONT */
    elena_nmca_017,  /* 18 S JUMP V */
    elena_nmca_017,  /* 19 S JUMP BACK */
    elena_nmca_020,  /* 20 SP JUMP FRONT */
    elena_nmca_021,  /* 21 SP JUMP V */
    elena_nmca_022,  /* 22 SP JUMP BACK */
    elena_nmca_023,  /* 23 WALK END */
    elena_nmca_024,  /* 24 PARING HEAD */
    elena_nmca_024,  /* 25 PARING UP */
    elena_nmca_026,  /* 26 PARING DOWN */
    elena_nmca_027,  /* 27 PARING AIR F */
    elena_nmca_027,  /* 28 PARING AIR B */
    elena_nmca_029,  /* 29 GUARD HEAD */
    elena_nmca_030,  /* 30 GUARD UP */
    elena_nmca_031,  /* 31 GUARD DOWN */
    elena_nmca_032,  /* 32 GUARD AIR */
    elena_nmca_033,  /* 33 follow-up of S PUNCH A, S PUNCH C +14 */
    elena_nmca_034,  /* 34 follow-up of KAGAMI P A, KAGAMI K A +2 */
    elena_nmca_035,  /* 35 no name */
    elena_nmca_036,  /* 36 follow-up of HURIMUKI, DASH HUMIKOMI +71 */
    elena_nmca_037,  /* 37 follow-up of KAGAMI P A, KAGAMI K A +4 */
    elena_nmca_038,  /* 38 P BREAK ZUJOU */
    elena_nmca_038,  /* 39 P BREAK UP */
    elena_nmca_040,  /* 40 P BREAK DOWN */
    elena_nmca_041,  /* 41 P BREAK AIR F */
    elena_nmca_041,  /* 42 P BREAK AIR R */
    elena_nmca_043,  /* 43 TUKAMIHAZUSI */
    elena_nmca_044,  /* 44 TUKAMIHAZUSARE */
    elena_nmca_045,  /* 45 TUKAMIHAZUSI */
    elena_nmca_046,  /* 46 TUKAMIHAZUSARE */
    elena_nmca_047,  /* 47 no name */
    elena_nmca_048,  /* 48 no name */
    elena_nmca_049,  /* 49 no name */
    elena_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 elena_nmca_000_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_000[712] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3000, 0, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3001, 0, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3002, 0, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3003, 0, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3004, 0, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3005, 0, 313, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3006, 0, 313, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3007, 0, 313, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3008, 0, 313, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3009, 0, 313, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300A, 0, 314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300B, 0, 314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300C, 0, 314, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300D, 0, 314, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300E, 0, 314, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300F, 0, 314, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3010, 0, 314, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3011, 0, 314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3012, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3013, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3014, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3015, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3016, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3017, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3018, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3019, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301A, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301B, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301C, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301E, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301F, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3020, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3021, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3022, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3023, 0, 317, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3024, 0, 317, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3025, 0, 317, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3026, 0, 317, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3027, 0, 317, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3028, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3029, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302A, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302B, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302C, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302D, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302E, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302F, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3030, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3031, 0, 319, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3032, 0, 319, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3033, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3034, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3035, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3036, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3037, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3038, 0, 319, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3039, 0, 319, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 elena_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_001[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x304F, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3050, 0, 17, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3051, 0, 17, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3052, 0, 17, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3053, 0, 19, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3054, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3055, 0, 19, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3055, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 48), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 elena_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 elena_nmca_002[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x351B, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x351C, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3059, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305A, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305B, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305C, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305D, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305E, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305F, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3060, 0, 320, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 elena_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 elena_nmca_003[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3060, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305F, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305E, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305D, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305C, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305B, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x305A, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3059, 0, 322, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 elena_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 elena_nmca_004[100] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3061, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 1, 277, 0, 0, 0, 0, 0x3062, 0, 9, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3063, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x3064, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3065, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3066, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3067, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 35), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 elena_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 elena_nmca_005[188] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3068, 0, 163, 0, 0, 0, 32, 57),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3069, 0, 163, 0, 0, 0, 32, 58),
    L4(1, 0, 0, 0, 0, 0, 0, 0x306A, 0, 163, 0, 0, 0, 32, 59),
    L4(1, 0, 273, 0, 0, 0, 0, 0x306B, 0, 164, 0, 0, 0, 32, 60),
    L4(2, 0, 0, 0, 0, 0, 0, 0x306C, 0, 164, 0, 0, 0, 32, 61),
    L4(1, 0, 0, 0, 0, 0, 0, 0x306D, 0, 165, 0, 0, 0, 32, 62),
    L4(1, 0, 0, 0, 0, 0, 0, 0x306E, 0, 165, 0, 0, 0, 32, 63),
    L4(1, 0, 0, 0, 0, 0, 0, 0x306F, 0, 165, 0, 0, 0, 32, 64),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3070, 0, 165, 0, 0, 0, 32, 65),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3071, 0, 166, 0, 0, 0, 32, 66),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3072, 0, 166, 0, 0, 0, 32, 67),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3073, 0, 166, 0, 0, 0, 32, 68),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3074, 0, 167, 0, 0, 0, 32, 69),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3075, 0, 167, 0, 0, 0, 32, 70),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3076, 0, 167, 0, 0, 0, 32, 71),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3077, 0, 167, 0, 0, 0, 32, 72),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3078, 0, 167, 0, 0, 0, 32, 73),
    L4(1, 0, 273, 0, 0, 0, 0, 0x3079, 0, 167, 0, 0, 0, 32, 74),
    L4(2, 0, 0, 0, 0, 0, 0, 0x307A, 0, 168, 0, 0, 0, 32, 75),
    L4(1, 0, 0, 0, 0, 0, 0, 0x307B, 0, 169, 0, 0, 0, 32, 76),
    L4(1, 0, 0, 0, 0, 0, 0, 0x307C, 0, 170, 0, 0, 0, 32, 77),
    L4(1, 64, 0, 0, 0, 0, 0, 0x307C, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 31), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 elena_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_006[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 323, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 323, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 323, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 elena_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_007[172] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x33F6, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x33F5, 0, 328, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3598, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3597, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0x000D, 0x0000, 0x0000, 0x0000,
    L4(7, 0, 0, 0, 0, 0, 0, 0x359A, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359B, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359C, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359D, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359E, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359F, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3598, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3599, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 8, 8192, 8203), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x359A, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359B, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359C, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359D, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359E, 0, 3, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x359F, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 elena_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_008[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3056, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3057, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3058, 0, 15, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3058, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 elena_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_011[44] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3041, 0, 324, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3042, 0, 324, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3043, 0, 324, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 elena_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x3053, 0, 325, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x308D, 0, 326, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x308D, 0, 326, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 elena_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_013[28] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3054, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x308D, 0, 326, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x308D, 0, 326, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 elena_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 elena_nmca_014[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x308E, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x308F, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3090, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3091, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3092, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3093, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3094, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 elena_nmca_015_head[4] = { HEAD(2, 22, 0, 0, 0, 0, 0) };
const u16 elena_nmca_015[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 14, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 elena_nmca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 elena_nmca_016[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 14, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 elena_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 elena_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 14, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 elena_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 elena_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x308E, 0, 5, 0, 0, 0, 18, 2),
    L4(5, 0, 281, 0, 0, 0, 0, 0x308E, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x308F, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3090, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3091, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3092, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3093, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 697, 0, 0, 0, 10, 0x3094, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 elena_nmca_021_head[4] = { HEAD(2, 28, 0, 0, 0, 0, 0) };
const u16 elena_nmca_021[12] = {
    CMD(CM_JSR, 8, 4, 1),
    CMD(CM_JPSS, 0, 20, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 elena_nmca_022_head[4] = { HEAD(2, 30, 0, 0, 0, 0, 0) };
const u16 elena_nmca_022[12] = {
    CMD(CM_JSR, 8, 4, 1),
    CMD(CM_JPSS, 0, 20, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 elena_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3000, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 elena_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 elena_nmca_024[84] = {
    L4(1, 134, 0, 0, 0, 0, 0, 0x320D, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x320E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 677, 0, 0, 0, 0, 0x320F, 0, 1, 0, 0, 0, 6, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3210, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3211, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3212, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3213, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3217, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3218, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 elena_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 elena_nmca_026[68] = {
    L4(1, 134, 0, 0, 0, 0, 0, 0x3590, 0, 3, 0, 0, 0, 18, 6),
    L4(1, 0, 677, 0, 0, 0, 0, 0x3591, 0, 3, 0, 0, 0, 6, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3592, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3593, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3594, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3595, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 elena_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 elena_nmca_027[164] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x320E, 0, 69, 0, 0, 0, 18, 6),
    L4(2, 0, 677, 0, 0, 0, 0, 0x320F, 0, 69, 0, 0, 0, 6, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3210, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3211, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x320E, 0, 69, 0, 0, 0, 18, 6),
    L4(2, 0, 677, 0, 0, 0, 0, 0x320F, 0, 69, 0, 0, 0, 6, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3210, 0, 69, 0, 0, 0, 0, 0),
    L4(17, 0, 0, 0, 0, 0, 0, 0x3211, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3095, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 elena_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 elena_nmca_029[52] = {
    L4(3, 1, 0, 0, 0, 0, 0, 0x307D, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x307F, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3080, 0, 61, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x307E, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3017, 0, 61, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 elena_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 elena_nmca_030[52] = {
    L4(3, 1, 0, 0, 0, 0, 0, 0x3081, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3083, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3084, 0, 62, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3082, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3017, 0, 61, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 elena_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 elena_nmca_031[52] = {
    L4(3, 1, 0, 0, 0, 0, 0, 0x3087, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3088, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3085, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3086, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 elena_nmca_032_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 elena_nmca_032[44] = {
    L4(2, 4, 0, 0, 0, 0, 0, 0x3089, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x308A, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x308B, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x308C, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x308C, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of S PUNCH A, S PUNCH C +14 */
const u16 elena_nmca_033_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_033[1060] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C89, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C8F, 0, 4, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C90, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C91, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C92, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C95, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C96, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C98, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9C9F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CA9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CAF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CB9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_JSR, 8, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    CMD(CM_JSR, 8, 35, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    CMD(CM_JSR, 8, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CBF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    CMD(CM_JSR, 8, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CC0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x9CC1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of KAGAMI P A, KAGAMI K A +2 */
const u16 elena_nmca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_034[108] = {
    L4(12, 0, 0, 0, 0, 0, 0, 0x33FA, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 54, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F9, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x33F8, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 56, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x33F7, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 57, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F8, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 58, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F9, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 59, 1), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 elena_nmca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_035[300] = {
    CMD(CM_PS_Y, 0, 0, 6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x33AB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x33AC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33AD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33AE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33AF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33B9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33BA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33BB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33BC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33BD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33BE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33BF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33C0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33C1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33C2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33C3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33C4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33C5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33C6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33C7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33C8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33C9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33CF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33D0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33D1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x33D2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33D4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33D5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x33D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33D7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33D8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33D9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33DA),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33DB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33DC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33DD),
    L2(5, 0, 0, 0, 0, 0, 0, 0x33DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33DF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33E9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33ED),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33EE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33EF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33F0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33F1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x33F2),
    L2(250, 255, 0, 0, 0, 0, 0, 0x33F2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of HURIMUKI, DASH HUMIKOMI +71 */
const u16 elena_nmca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_036[712] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3001, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3002, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3003, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3004, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3005, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3006, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3007, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3008, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3009, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x300F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3010, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3011, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3012, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3013, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3014, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3015, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3016, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3017, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3018, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3019, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x301F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3020, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3021, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3022, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3023, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3024, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3025, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3026, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3027, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3028, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3029, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x302F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3030, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3031, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3032, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3033, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3034, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3035, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3036, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3037, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3038, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3039, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3039, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of KAGAMI P A, KAGAMI K A +4 */
const u16 elena_nmca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_037[76] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x33F6, 0, 3, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F5, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x33F4, 0, 3, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x33F3, 0, 3, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F4, 0, 3, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x33F5, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x33F5, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3120, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 elena_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_038[76] = {
    CMD(CM_JSR, 8, 63, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x320F, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x320E, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3182, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x3183, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x3184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 elena_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_nmca_040[76] = {
    CMD(CM_JSR, 8, 63, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3087, 0, 3, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3086, 0, 3, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3182, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x3183, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x3184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 elena_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x320E, 0, 69, 0, 0, 0, 18, 8),
    L4(250, 0, 677, 0, 0, 0, 0, 0x320F, 0, 69, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 elena_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_043[76] = {
    CMD(CM_JSR, 8, 63, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x320F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x320E, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3182, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x3183, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x3184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 elena_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_044[52] = {
    L4(250, 130, 0, 0, 1, 0, 0, 0x352E, 0, 458, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 1, 0, 0, 0x352F, 0, 459, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x3530, 0, 460, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x3531, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 1, 0, 0, 0x3532, 0, 462, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x3532, 0, 462, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 elena_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_nmca_045[84] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x320E, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 0, 677, 0, 0, 0, 0, 0x320F, 0, 69, 0, 0, 0, 25, 2),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 elena_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_nmca_046[76] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 132, 0, 0, 0, 0, 0, 0x3093, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 elena_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3000, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 elena_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 elena_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 elena_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 elena_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 elena_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_nmca_050[76] = {
    CMD(CM_JSR, 8, 63, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x320F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x320E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3182, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x3183, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x3184, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const elena_dmca[99] = {
    elena_dmca_000,  /* 0 GUARD HEAD */
    elena_dmca_001,  /* 1 GUARD UP */
    elena_dmca_002,  /* 2 GUARD DOWN */
    elena_dmca_003,  /* 3 GUARD AIR */
    elena_dmca_004,  /* 4 HUSHIN HEAD */
    elena_dmca_004,  /* 5 HUSHIN UP */
    elena_dmca_006,  /* 6 HUSHIN DOWN */
    elena_dmca_006,  /* 7 HUSHIN AIR */
    elena_dmca_008,  /* 8 FACE S */
    elena_dmca_009,  /* 9 FACE M */
    elena_dmca_010,  /* 10 FACE L */
    elena_dmca_010,  /* 11 FACE SP */
    elena_dmca_008,  /* 12 FOOK OKU S */
    elena_dmca_009,  /* 13 FOOK OKU M */
    elena_dmca_014,  /* 14 FOOK OKU L */
    elena_dmca_015,  /* 15 FOOK OKU SP */
    elena_dmca_008,  /* 16 FOOK TEMAE S */
    elena_dmca_009,  /* 17 FOOK TEMAE M */
    elena_dmca_018,  /* 18 FOOK TEMAE L */
    elena_dmca_019,  /* 19 FOOK TEMAE SP */
    elena_dmca_008,  /* 20 UPPER S */
    elena_dmca_009,  /* 21 UPPER M */
    elena_dmca_022,  /* 22 UPPER L */
    elena_dmca_022,  /* 23 UPPER SP */
    elena_dmca_008,  /* 24 NOUTEN S */
    elena_dmca_025,  /* 25 NOUTEN M */
    elena_dmca_026,  /* 26 NOUTEN L */
    elena_dmca_026,  /* 27 NOUTEN SP */
    elena_dmca_028,  /* 28 BODY BROW S */
    elena_dmca_025,  /* 29 BODY BROW M */
    elena_dmca_026,  /* 30 BODY BROW L */
    elena_dmca_026,  /* 31 BODY BROW SP */
    elena_dmca_028,  /* 32 BODY UPPER S */
    elena_dmca_025,  /* 33 BODY UPPER M */
    elena_dmca_026,  /* 34 BODY UPPER L */
    elena_dmca_026,  /* 35 BODY UPPER SP */
    elena_dmca_036,  /* 36 TATAKI S */
    elena_dmca_036,  /* 37 TATAKI M */
    elena_dmca_036,  /* 38 TATAKI L */
    elena_dmca_036,  /* 39 TATAKI SP */
    elena_dmca_040,  /* 40 TATAKI V. S */
    elena_dmca_040,  /* 41 TATAKI V. M */
    elena_dmca_040,  /* 42 TATAKI V. L */
    elena_dmca_040,  /* 43 TATAKI V. SP */
    elena_dmca_008,  /* 44 NOBASITA TE S */
    elena_dmca_009,  /* 45 NOBASITA TE M */
    elena_dmca_010,  /* 46 NOBASITA TE L */
    elena_dmca_010,  /* 47 NOBASITA TE SP */
    elena_dmca_048,  /* 48 KAGAMI S */
    elena_dmca_049,  /* 49 KAGAMI M */
    elena_dmca_050,  /* 50 KAGAMI L */
    elena_dmca_050,  /* 51 KAGAMI SP */
    elena_dmca_052,  /* 52 KGM TATAKI S */
    elena_dmca_052,  /* 53 KGM TATAKI M */
    elena_dmca_052,  /* 54 KGM TATAKI L */
    elena_dmca_052,  /* 55 KGM TATAKI SP */
    elena_dmca_056,  /* 56 KGM TTKI V.S */
    elena_dmca_056,  /* 57 KGM TTKI V.M */
    elena_dmca_056,  /* 58 KGM TTKI V.L */
    elena_dmca_056,  /* 59 KGM TTKI V.SP */
    elena_dmca_060,  /* 60 NEKOROBI S */
    elena_dmca_060,  /* 61 NEKOROBI M */
    elena_dmca_060,  /* 62 NEKOROBI L */
    elena_dmca_060,  /* 63 NEKOROBI SP */
    elena_dmca_064,  /* 64 OKIAGARI */
    elena_dmca_065,  /* 65 OKIAGARI F */
    elena_dmca_066,  /* 66 OKIAGARI B */
    elena_dmca_067,  /* 67 LOSE NO STAND */
    elena_dmca_068,  /* 68 LOSE SONABA */
    elena_dmca_068,  /* 69 LOSE KAGAMI */
    elena_dmca_070,  /* 70 PIYO */
    elena_dmca_071,  /* 71 UKEMI MOVE F */
    elena_dmca_072,  /* 72 UKEMI MOVE R */
    elena_dmca_073,  /* 73 SHIMEOTASARE */
    elena_dmca_074,  /* 74 TATI TOUKETU S */
    elena_dmca_075,  /* 75 TATI TOUKETU M */
    elena_dmca_076,  /* 76 TATI TOUKETU L */
    elena_dmca_076,  /* 77 TATI TOUKETU P */
    elena_dmca_078,  /* 78 KGM TOUKETU S */
    elena_dmca_079,  /* 79 KGM TOUKETU M */
    elena_dmca_080,  /* 80 KGM TOUKETU L */
    elena_dmca_080,  /* 81 KGM TOUKETU P */
    elena_dmca_082,  /* 82 TATI DENGEKI S */
    elena_dmca_083,  /* 83 TATI DENGEKI M */
    elena_dmca_084,  /* 84 TATI DENGEKI L */
    elena_dmca_084,  /* 85 TATI DENGEKI P */
    elena_dmca_082,  /* 86 KGM DENGEKI S */
    elena_dmca_083,  /* 87 KGM DENGEKI M */
    elena_dmca_084,  /* 88 KGM DENGEKI L */
    elena_dmca_084,  /* 89 KGM DENGEKI P */
    elena_dmca_090,  /* 90 OKIAGARI FRONT */
    elena_dmca_091,  /* 91 OKIAGARI REAR */
    elena_dmca_008,  /* 92 TATI MOE S */
    elena_dmca_009,  /* 93 TATI MOE M */
    elena_dmca_010,  /* 94 TATI MOE L */
    elena_dmca_010,  /* 95 TATI MOE SP */
    elena_dmca_096,  /* 96 no name */
    elena_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 elena_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_000[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x307D, 0, 61, 0, 0, 0, 0, 0),
    L4(6, 132, 0, 0, 0, 0, 0, 0x307E, 0, 61, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x307F, 0, 61, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x307E, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x307D, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3017, 0, 61, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 elena_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_001[68] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x3081, 0, 62, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3082, 0, 62, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x3083, 0, 62, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3084, 0, 62, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3083, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3082, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3017, 0, 61, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 elena_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_002[68] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x3085, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3086, 0, 3, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x3087, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3088, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3087, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3086, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 elena_dmca_003_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_003[148] = {
    L6(1, 131, 0, 0, 0, 0, 0, 0x3089, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x308A, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 138, 0, 0, 0, 0, 0, 0x308B, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x308C, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
    L6(250, 135, 0, 0, 0, 0, 0, 0x309B, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x309C, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x309D, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x309D, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 7, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 elena_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_004[52] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3182, 0, 62, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3183, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3184, 0, 62, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3185, 0, 68, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3186, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 elena_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_006[52] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3179, 0, 62, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x317A, 0, 62, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x317B, 0, 62, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x317C, 0, 68, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x317D, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 elena_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30AE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 675, 0, 0, 0, 0, 0x30AF, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30AF, 0, 335, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x30B0, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x30B1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 elena_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_009[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30B6, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 135, 675, 0, 0, 0, 0, 0x30B6, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30B4, 0, 336, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B5, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30B6, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x30B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 elena_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_010[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30BA, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 138, 674, 0, 0, 0, 0, 0x30BA, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30BB, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30BC, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30BD, 0, 338, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30BE, 0, 338, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x30BF, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x30C0, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x30C1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 elena_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_018[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x318D, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x318E, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 140, 674, 0, 0, 0, 0, 0x318E, 0, 336, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x318F, 0, 336, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3190, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3191, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3192, 0, 337, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3193, 0, 337, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3194, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3195, 0, 337, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3196, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3197, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 elena_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_019[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x318C, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 139, 674, 0, 0, 0, 0, 0x318D, 0, 336, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x318D, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x318E, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x318F, 0, 338, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 1, 0, 0, 0x321A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 1, 0, 0, 0x3219, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 10, 0, 0, 1, 0, 0, 0x30D7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 1, 0, 0, 0x30D6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x30D5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30D4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30D3, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30D7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30D8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 elena_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_014[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x319A, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 135, 674, 0, 0, 0, 0, 0x319A, 0, 336, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x319B, 0, 337, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x319C, 0, 336, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x319D, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x319E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x319F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A3, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A4, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 elena_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_015[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3198, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 135, 674, 0, 0, 0, 0, 0x3199, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x319A, 0, 337, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 1, 0, 0, 0x3219, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 12, -32767), 0, 0, 0, 0,
    L4(12, 10, 0, 0, 0, 0, 0, 0x319D, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x319E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x319F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31A0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31A1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31A2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31A3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31A4, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 elena_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_022[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31A8, 0, 331, 0, 0, 0, 0, 0),
    L4(1, 136, 674, 0, 0, 0, 0, 0x31A8, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31A8, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x322F, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3230, 0, 334, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3231, 0, 331, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3232, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 BODY BROW S, 32 BODY UPPER S */
const u16 elena_dmca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_028[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30C2, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 135, 675, 0, 0, 0, 0, 0x30C3, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30C3, 0, 339, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x30C4, 0, 339, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x30C5, 0, 339, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x30C6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M, 29 BODY BROW M, 33 BODY UPPER M */
const u16 elena_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_025[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30C7, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 136, 675, 0, 0, 0, 0, 0x30C8, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30C9, 0, 340, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x30CA, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30CB, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x30CC, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x30CD, 0, 339, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP, 30 BODY BROW L, 31 BODY BROW SP ... */
const u16 elena_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_026[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31F1, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 135, 674, 0, 0, 0, 0, 0x31F1, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31F1, 0, 341, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x31F2, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31F3, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31F4, 0, 339, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP */
const u16 elena_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_036[60] = {
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x321A, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x321B, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321C, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321D, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321E, 0, 342, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 TATAKI V. S, 41 TATAKI V. M, 42 TATAKI V. L, 43 TATAKI V. SP */
const u16 elena_dmca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_040[52] = {
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x321A, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x321B, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321D, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321E, 0, 342, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 elena_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_048[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 134, 675, 0, 0, 0, 0, 0x31DF, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31DF, 0, 343, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 elena_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_049[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E2, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 134, 675, 0, 0, 0, 0, 0x31E3, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31E3, 0, 344, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x31E4, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31E5, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31E5, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 elena_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_050[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E8, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 136, 674, 0, 0, 0, 0, 0x31E8, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31E8, 0, 345, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31E9, 0, 346, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x31EA, 0, 343, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31EB, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31EC, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31ED, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31EE, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP */
const u16 elena_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_052[60] = {
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31E6, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x31EA, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31EC, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321D, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321E, 0, 344, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 KGM TTKI V.S, 57 KGM TTKI V.M, 58 KGM TTKI V.L, 59 KGM TTKI V.SP */
const u16 elena_dmca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_056[60] = {
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31E6, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x31EA, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31EC, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321D, 0, 344, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321E, 0, 344, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 elena_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_060[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31D9, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x31DA, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x31DB, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x31DA, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x31DB, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x31DC, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x31DD, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31DE, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31DE, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 elena_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_064[140] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x31DE, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x31DE, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C3, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C4, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31C5, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31C6, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31C7, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x31C8, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31C9, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CA, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31CB, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31CB, 0, 0, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 31), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 elena_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_065[172] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3317, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3318, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 1, 678, 0, 0, 0, 0, 0x3319, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3326, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3327, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3328, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 elena_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_066[188] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3332, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3331, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 1, 678, 0, 0, 0, 0, 0x3330, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3328, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3327, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3326, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3322, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 elena_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x31DE, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31DE, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 elena_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_068[280] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x31AE, 0, 262, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(250, 133, 0, 0, 0, 0, 0, 0x31AE, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31AF, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B0, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 1, 0, 0, 0, 0, 0, 0x31B1, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B2, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x31B3, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x31B4, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x31B5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x31B6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31BA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31BB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31BC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x31BD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31BE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31BF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31C0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31C1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31C2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x31C2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 elena_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_070[84] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x31A9, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AA, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AB, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AC, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AD, 0, 330, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AC, 0, 330, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AB, 0, 330, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x31AA, 0, 330, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 elena_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_071[220] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C3, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(1, 1, 678, 0, 0, 0, 0, 0x3319, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3326, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3328, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 12, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31C5, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C6, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31C7, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C8, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31C9, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CA, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31CB, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x31CB, 0, 0, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 31), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 elena_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_072[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C3, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(1, 1, 678, 0, 0, 0, 0, 0x3330, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3327, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 71, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 elena_dmca_073_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_073[268] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x31AE, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31AF, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B0, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 1, 0, 0, 0, 0, 0, 0x31B1, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B2, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 289, 0, 0, 0, 0, 0x31B3, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x31B4, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x31B5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x31B6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x31B7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31B8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x31B9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x31BA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x31BB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 288, 0, 0, 0, 0, 0x31BC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x31BD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x31BE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x31BF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x31C0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x31C1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x31C2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x31C2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 elena_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_074[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30AE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x30AE, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x30AF, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B0, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 elena_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_075[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30B2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x30B2, 0, 335, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x30AF, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B0, 0, 336, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 elena_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_076[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x30B8, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x30B8, 0, 335, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x30AF, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B0, 0, 336, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x30B1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 elena_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_078[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x31DF, 0, 343, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 elena_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_079[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E2, 0, 343, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x31E2, 0, 344, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x31DF, 0, 344, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 elena_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x31E6, 0, 343, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x31E6, 0, 344, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x31DF, 0, 344, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31E0, 0, 343, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x31E1, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 elena_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_082[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x9D22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9D23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x9D24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 elena_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_083[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x9D22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9D23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x9D24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 elena_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_dmca_084[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x9D22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9D23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x9D24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 elena_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_090[324] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3317, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3318, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3319, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3322, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3326, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3327, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3328, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3330, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3331, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3332, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31C4, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C5, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C6, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C7, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31C8, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C9, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CA, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x31CB, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31CC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 31), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 elena_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_091[324] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3332, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3331, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3330, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x332A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3329, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3328, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3327, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3326, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3325, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3324, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3323, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3322, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3321, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3320, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x331A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3319, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3318, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3317, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x31C4, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C5, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C6, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C7, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31C8, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31C9, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31CA, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x31CB, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x31CC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 31), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 elena_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_096[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3291, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3291, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3291, 0, 256, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x3291, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 elena_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_dmca_097[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3291, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3291, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3291, 0, 304, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x3291, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 304, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const elena_btca[37] = {
    elena_btca_000,  /* 0 AIR NORMAL */
    elena_btca_001,  /* 1 ASIBARAI SIRI */
    elena_btca_002,  /* 2 ASIB TUNNOMERI */
    elena_btca_003,  /* 3 NOKEZORI */
    elena_btca_004,  /* 4 KUNOJI */
    elena_btca_005,  /* 5 KIRIMOMI */
    elena_btca_003,  /* 6 UPPER */
    elena_btca_004,  /* 7 BODY UPPER */
    elena_btca_004,  /* 8 HARAYARARE */
    elena_btca_009,  /* 9 TATAKI AIR */
    elena_btca_010,  /* 10 TTKI V. AIR */
    elena_btca_011,  /* 11 HUMI ASIB */
    elena_btca_004,  /* 12 FACE */
    elena_btca_013,  /* 13 ASIB SIRI LOSE */
    elena_btca_014,  /* 14 ASIB TUN LOSE */
    elena_btca_015,  /* 15 DENKI */
    elena_btca_016,  /* 16 KUNOJI NOKE */
    elena_btca_017,  /* 17 BODY UPPER SP */
    elena_btca_018,  /* 18 HANEAGARI */
    elena_btca_009,  /* 19 TOUKETSU A */
    elena_btca_020,  /* 20 BODY SLAM */
    elena_btca_020,  /* 21 IPPONZEOI */
    elena_btca_022,  /* 22 TOMOE RYU */
    elena_btca_022,  /* 23 MONKEY FLIP */
    elena_btca_024,  /* 24 TOMOE ORO */
    elena_btca_025,  /* 25 SNAKE FANG */
    elena_btca_026,  /* 26 FLANKEN.S */
    elena_btca_027,  /* 27 KISHINRIKI */
    elena_btca_028,  /* 28 SPLASH.M */
    elena_btca_029,  /* 29 HARAIGOSHI */
    elena_btca_030,  /* 30 ALEX B.D */
    elena_btca_031,  /* 31 GILL */
    elena_btca_032,  /* 32 HANEKAERI HARA */
    elena_btca_033,  /* 33 S HANEAGARI */
    elena_btca_034,  /* 34 TATUMAKIZANKU */
    elena_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 elena_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_000[68] = {
    CMD(CM_JSR, 8, 61, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x30B6, 0, 408, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 675, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x3560, 0, 409, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x3561, 0, 410, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 19, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 elena_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_001[68] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3219, 0, 411, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x321A, 0, 411, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321B, 0, 412, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321C, 0, 412, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321D, 0, 413, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x321E, 0, 414, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 elena_btca_002_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_002[60] = {
    CMD(CM_RJA, 7, 15, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3292, 0, 415, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x3292, 0, 415, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3293, 0, 416, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3294, 0, 417, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3295, 0, 418, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI, 6 UPPER */
const u16 elena_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_003[172] = {
    CMD(CM_RJA, 7, 16, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31A5, 0, 419, 0, 0, 0, 0, 0),
    L4(3, 0, 674, 0, 0, 0, 0, 0x31A5, 0, 419, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A6, 0, 419, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31A7, 0, 420, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A8, 0, 421, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI, 7 BODY UPPER, 8 HARAYARARE, 12 FACE */
const u16 elena_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_004[148] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31AF, 0, 436, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x318F, 0, 437, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 elena_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_005[292] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x32A3, 0, 438, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x32A3, 0, 438, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32A4, 0, 439, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32A5, 0, 440, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32A6, 0, 441, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32A7, 0, 442, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32A8, 0, 443, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32A9, 0, 444, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AA, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AB, 0, 446, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AC, 0, 447, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AD, 0, 448, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AE, 0, 449, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32AF, 0, 450, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B0, 0, 451, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 elena_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_010[60] = {
    CMD(CM_RJA, 7, 18, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31F0, 0, 452, 0, 0, 0, 0, 0),
    L4(1, 0, 674, 0, 0, 0, 0, 0x31F1, 0, 412, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x31F2, 0, 412, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x321D, 0, 413, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x321E, 0, 414, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 elena_btca_011_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_011[60] = {
    CMD(CM_RJA, 7, 15, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3292, 0, 415, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3292, 0, 415, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3293, 0, 416, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3294, 0, 417, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3295, 0, 418, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 elena_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_013[12] = {
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 elena_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_014[12] = {
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 elena_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_015[60] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(1, 135, 0, 0, 0, 0, 0, 0x9D22, 0, 453, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x9D22, 0, 453, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9D23, 0, 453, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x9D24, 0, 453, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 elena_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_016[136] = {
    CMD(CM_RJA, 7, 16, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31A5, 0, 419, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x321A, 0, 411, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A7, 0, 420, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A8, 0, 421, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3285, 0, 454, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 17 BODY UPPER SP */
const u16 elena_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_017[196] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 674, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 elena_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_018[132] = {
    CMD(CM_RJA, 6, 18, 10), 0, 0, 0, 0,
    L4(2, 0, 674, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR, 19 TOUKETSU A */
const u16 elena_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_009[28] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31A8, 0, 421, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x31A8, 0, 421, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM, 21 IPPONZEOI */
const u16 elena_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_020[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3285, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU, 23 MONKEY FLIP */
const u16 elena_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_022[60] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 1, 0, 0, 0x314C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x34B1, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x34AA, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3284, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x3296, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 elena_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_024[60] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 1, 0, 0, 0x314A, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x34B1, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x34AA, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3284, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x3296, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 elena_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_025[52] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 elena_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_026[68] = {
    CMD(CM_RJA, 7, 48, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x34AA, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x34AD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x34B0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3284, 0, 2, 0, 0, 0, 32, 106),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3285, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3285, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 elena_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_027[84] = {
    CMD(CM_RJA, 7, 16, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 elena_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_028[68] = {
    CMD(CM_RJA, 7, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3221, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3223, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3224, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3284, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 elena_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_029[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x321E, 0, 414, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x321E, 0, 414, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 elena_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_030[148] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31AF, 0, 436, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x318F, 0, 437, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 elena_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_031[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3219, 0, 411, 0, 0, 0, 0, 0),
    L4(2, 0, 674, 0, 0, 0, 0, 0x321A, 0, 411, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321B, 0, 412, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321C, 0, 412, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x321D, 0, 413, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x321E, 0, 414, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 elena_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_032[36] = {
    CMD(CM_RJA, 7, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x31AF, 0, 436, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x318F, 0, 437, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 elena_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_033[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 674, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 elena_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_btca_034[172] = {
    CMD(CM_RJA, 7, 16, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x31A5, 0, 419, 0, 0, 0, 0, 0),
    L4(3, 0, 674, 0, 0, 0, 0, 0x31A5, 0, 419, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A6, 0, 419, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x31A7, 0, 420, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x31A8, 0, 421, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3277, 0, 422, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3278, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3279, 0, 424, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327A, 0, 425, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327B, 0, 426, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327C, 0, 427, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327D, 0, 428, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327E, 0, 429, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x327F, 0, 430, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3280, 0, 431, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3281, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3282, 0, 433, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3283, 0, 434, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3284, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 2 entries */
const u16* const elena_caca[3] = {
    elena_caca_000,  /* 0 CATCH 1 */
    elena_caca_001,  /* 1 CATCH 2 */
    0
};

/* script: 0 CATCH 1 */
const u16 elena_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 elena_caca_000[52] = {
    CMD(CM_NGDA, 1542, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 1, 0, 0, 0x326A, 0, 0, 0, 0, 0, 0, 0, 256, 96, 0, 0, 0),
    L6(3, 6, 264, 0, 1, 0, 0, 0x326B, 0, 0, 0, 0, 0, 0, 0, 256, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 elena_caca_001_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 elena_caca_001[172] = {
    CMD(CM_NGDA, 1542, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 1, 0, 0, 0x326B, 0, 0, 0, 0, 0, 0, 0, 256, 120, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x326C, 0, 0, 0, 0, 0, 0, 0, 256, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x326D, 0, 0, 0, 0, 0, 0, 0, 256, 168, 0, 0, 0),
    L6(2, 2, 678, 0, 1, 0, 0, 0x326E, -11, 0, 0, 0, 0, 0, 0, 256, 192, 0, 0, 0),
    L6(5, 9, 0, 0, 1, 0, 0, 0x326F, 0, 0, 0, 0, 0, 0, 0, 256, 216, 0, 0, 0),
    L6(2, 6, 0, 0, 0, 0, 0, 0x3270, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3271, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3272, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3273, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3274, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3275, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3276, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3276, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const elena_cuca[69] = {
    elena_cuca_000,  /* 0 ALEX ZUTUKI */
    elena_cuca_001,  /* 1 ALEX BODY S */
    elena_cuca_002,  /* 2 ALEX BACK D */
    elena_cuca_003,  /* 3 ALEX POWER B */
    elena_cuca_004,  /* 4 ALEX SLEEPER */
    elena_cuca_005,  /* 5 RYU SEOINAGE */
    elena_cuca_006,  /* 6 IBUKI */
    elena_cuca_007,  /* 7 DADLEY L B */
    elena_cuca_008,  /* 8 IBUKI KUBIORI */
    elena_cuca_009,  /* 9 NECRO S T */
    elena_cuca_010,  /* 10 RYU TOMOENAGE */
    elena_cuca_011,  /* 11 YUN HIZAGERI */
    elena_cuca_012,  /* 12 ORO KUBISIME */
    elena_cuca_013,  /* 13 NECRO G S */
    elena_cuca_014,  /* 14 DUDDLEY D S */
    elena_cuca_015,  /* 15 YUN MONKEY F */
    elena_cuca_016,  /* 16 ORO TOMOENAGE */
    elena_cuca_017,  /* 17 ORO NIOURIKI */
    elena_cuca_018,  /* 18 ORO GIGOKU G */
    elena_cuca_019,  /* 19 YUN */
    elena_cuca_020,  /* 20 NECRO SNAKE F */
    elena_cuca_021,  /* 21 NECRO F S */
    elena_cuca_022,  /* 22 IBUKI HARAIG */
    elena_cuca_023,  /* 23 GILL SPLASH M */
    elena_cuca_024,  /* 24 KEN HIZAGERI */
    elena_cuca_025,  /* 25 ORO KISINRIKI */
    elena_cuca_026,  /* 26 SEAN TACKLE */
    elena_cuca_027,  /* 27 ALEX HYPER B */
    elena_cuca_028,  /* 28 NECRO SLAM D */
    elena_cuca_029,  /* 29 ELENA ASINAGE */
    elena_cuca_030,  /* 30 GILL IMPACT C */
    elena_cuca_031,  /* 31 ALEX S H B */
    elena_cuca_032,  /* 32 ALEX F N D */
    elena_cuca_033,  /* 33 no name */
    elena_cuca_034,  /* 34 IBUKI */
    elena_cuca_035,  /* 35 IBUKI YOROI D */
    elena_cuca_036,  /* 36 no name */
    elena_cuca_037,  /* 37 MAWARIKOMI M F */
    elena_cuca_038,  /* 38 HUGO BODY S */
    elena_cuca_039,  /* 39 HUGO N G T */
    elena_cuca_040,  /* 40 HUGO M S P */
    elena_cuca_041,  /* 41 HUGO S D B B */
    elena_cuca_042,  /* 42 no name */
    elena_cuca_043,  /* 43 no name */
    elena_cuca_044,  /* 44 no name */
    elena_cuca_045,  /* 45 no name */
    elena_cuca_046,  /* 46 no name */
    elena_cuca_047,  /* 47 no name */
    elena_cuca_048,  /* 48 no name */
    elena_cuca_049,  /* 49 no name */
    elena_cuca_050,  /* 50 no name */
    elena_cuca_051,  /* 51 no name */
    elena_cuca_052,  /* 52 no name */
    elena_cuca_053,  /* 53 no name */
    elena_cuca_054,  /* 54 no name */
    elena_cuca_055,  /* 55 no name */
    elena_cuca_056,  /* 56 no name */
    elena_cuca_057,  /* 57 no name */
    elena_cuca_058,  /* 58 no name */
    elena_cuca_059,  /* 59 no name */
    elena_cuca_060,  /* 60 no name */
    elena_cuca_061,  /* 61 no name */
    elena_cuca_062,  /* 62 no name */
    elena_cuca_063,  /* 63 no name */
    elena_cuca_064,  /* 64 no name */
    elena_cuca_065,  /* 65 no name */
    elena_cuca_066,  /* 66 no name */
    elena_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 elena_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F2),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 elena_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3185),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x317A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3223),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3191),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31A8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321F),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 elena_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3218),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3217),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321B),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 elena_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3196),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3185),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3186),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x320D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3176),
    L2(250, 0, 0, 0, 2, 0, 0, 0x328A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321B),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 3, 0, 0, 0x321B),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 elena_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x319E),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 elena_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3009),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3178),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31A6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x31D9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3184),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3176),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 elena_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3020),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3021),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3022),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3023),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3024),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3025),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3026),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30C9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 elena_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_007[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    CMD(CM_RMJA, 3, 7, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30B0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 elena_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B8),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30B9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 6, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 elena_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B9),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30BA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 elena_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_010[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x300E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x329A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 elena_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CA),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30D0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 elena_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3006),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3007),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3008),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3009),
    L2(250, 0, 0, 0, 0, 0, 0, 0x300A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B3),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x30B0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 elena_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3219),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3219),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3221),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x321F),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 16, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 16, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 elena_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 elena_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x326A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x312E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 elena_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_016[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x310B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3289),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 elena_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_017[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3278),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3220),
    CMD(CM_RMJA, 3, 17, 25),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3220),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 6, 2, 8),
    CMD(CM_JMP, 7, 16, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 6, 2, 8),
    CMD(CM_JMP, 7, 16, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 elena_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x308B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x308C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3133),
    L2(250, 0, 0, 0, 3, 0, 0, 0x308C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x308B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3134),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3133),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3132),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31DE),
    L2(250, 3, 0, 0, 0, 0, 0, 0x31DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31DC),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31DD),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 elena_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30BF),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30C0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 elena_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3185),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3186),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3187),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3188),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3190),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3278),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3279),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x327A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 elena_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31BC),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 elena_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31DA),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 31, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 elena_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x307B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3133),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3289),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30CF),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 elena_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CA),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30D0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 elena_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3278),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327B),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 elena_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    L2(250, 3, 0, 0, 0, 0, 0, 0x3286),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328F),
    L2(250, 3, 0, 0, 0, 0, 0, 0x31DA),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x328F),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 elena_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_027[148] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3218),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x31F7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x320D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3176),
    L2(250, 0, 0, 0, 2, 0, 0, 0x328A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31F7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x31F7),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 3, 0, 0, 0x31F7),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 elena_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3219),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3219),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x329D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3286),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3293),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3293),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31D4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x31D4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 elena_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_029[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 elena_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3342),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x32B0),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x31A8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 44, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 45, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 elena_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 elena_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3220),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 elena_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3218),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3217),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 2, 0, 0, 0x321B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 30, 13),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 30, 13),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 elena_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31CA),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31CA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 elena_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x301F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3020),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3021),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3022),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3023),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3024),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3025),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3026),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30C9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 elena_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3198),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3199),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3230),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 2, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3223),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3224),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3225),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3227),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3286),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322A),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31DC),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 elena_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x326A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x326A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3295),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x321D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 elena_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x310B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3133),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3134),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3135),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3221),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3223),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3223),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321C),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321F),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 elena_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3277),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 elena_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3230),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3297),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3286),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3290),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3291),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 elena_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3228),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31DC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x328D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C4),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 elena_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3199),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 elena_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3290),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3290),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 elena_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3230),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3297),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3286),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3228),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31DC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x328B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x316C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3211),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3291),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 elena_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D1),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30D1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 elena_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3269),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x330D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3224),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3230),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3230),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3297),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3295),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 elena_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3218),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x31F7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x330F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321B),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3299),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 elena_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3196),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F2),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 elena_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3293),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3281),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3282),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3283),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3284),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 elena_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3278),
    L2(250, 0, 0, 0, 3, 0, 0, 0x327A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x327B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x327C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x327E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x327F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3285),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3294),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 elena_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CF),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30C7),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 elena_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_052[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x300E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x307B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x329A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x321E),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x321E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 11, 1),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 elena_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x318A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3191),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3192),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3193),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3194),
    L2(250, 0, 0, 0, 1, 0, 0, 0x312A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x312B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x32A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 elena_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3184),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3182),
    L2(250, 0, 0, 0, 0, 0, 0, 0x320D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3091),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3278),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3277),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 44, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 45, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 elena_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x318A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3191),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3192),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3193),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3194),
    L2(250, 0, 0, 0, 1, 0, 0, 0x312A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x312B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32AB),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x30E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 elena_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x318B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CA),
    L2(250, 2, 0, 0, 0, 0, 0, 0x30D0),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 elena_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3196),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31F2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 16, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 elena_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x322E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x32B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3277),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 17, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 elena_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x307D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x307D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x307F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327A),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 elena_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x318B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x30CA),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 elena_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x308F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3090),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3091),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3092),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x327A),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 elena_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318C),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318D),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318E),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x318F),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x321A),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30D7),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x30B7),
    CMD(CM_PA_X, 0, -3072, 0),
    CMD(CM_PS_Y, 0, 0, 6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x31F1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 103),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3295),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 70),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3295),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x321C),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3285),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 11, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 elena_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31AF),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 674, 0, 0, 0, 0, 0x318F),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 elena_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x319B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3231),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3183),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x317B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31F1),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x31F0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 elena_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3198),
    L2(250, 0, 0, 0, 0, 0, 0, 0x319A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3219),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x319E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x326A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3295),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x312E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 elena_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x31A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3284),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3285),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3286),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3286),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 elena_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x30B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3279),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x327C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 160 entries */
const u16* const elena_atca[161] = {
    elena_atca_000,  /* 0 S PUNCH A */
    elena_atca_000,  /* 1 S PUNCH B */
    elena_atca_002,  /* 2 S PUNCH C */
    elena_atca_003,  /* 3 M PUNCH A */
    elena_atca_003,  /* 4 M PUNCH B */
    elena_atca_005,  /* 5 M PUNCH C */
    elena_atca_006,  /* 6 L PUNCH A */
    elena_atca_006,  /* 7 L PUNCH B */
    elena_atca_006,  /* 8 L PUNCH C */
    elena_atca_009,  /* 9 S KICK A */
    elena_atca_009,  /* 10 S KICK B */
    elena_atca_009,  /* 11 S KICK C */
    elena_atca_012,  /* 12 M KICK A */
    elena_atca_012,  /* 13 M KICK B */
    elena_atca_014,  /* 14 M KICK C */
    elena_atca_015,  /* 15 L KICK A */
    elena_atca_015,  /* 16 L KICK B */
    elena_atca_017,  /* 17 L KICK C */
    elena_atca_018,  /* 18 KAGAMI P A */
    elena_atca_018,  /* 19 KAGAMI P B */
    elena_atca_018,  /* 20 KAGAMI P C */
    elena_atca_021,  /* 21 KAGAMI P A */
    elena_atca_021,  /* 22 KAGAMI P B */
    elena_atca_021,  /* 23 KAGAMI P C */
    elena_atca_024,  /* 24 KAGAMI P A */
    elena_atca_024,  /* 25 KAGAMI P B */
    elena_atca_024,  /* 26 KAGAMI P C */
    elena_atca_027,  /* 27 KAGAMI K A */
    elena_atca_027,  /* 28 KAGAMI K B */
    elena_atca_027,  /* 29 KAGAMI K C */
    elena_atca_030,  /* 30 KAGAMI K A */
    elena_atca_030,  /* 31 KAGAMI K B */
    elena_atca_030,  /* 32 KAGAMI K C */
    elena_atca_033,  /* 33 KAGAMI K A */
    elena_atca_033,  /* 34 KAGAMI K B */
    elena_atca_035,  /* 35 KAGAMI K C */
    elena_atca_036,  /* 36 V JUMP P S A */
    elena_atca_036,  /* 37 V JUMP P S B */
    elena_atca_038,  /* 38 V JUMP P M A */
    elena_atca_038,  /* 39 V JUMP P M B */
    elena_atca_040,  /* 40 V JUMP P L A */
    elena_atca_040,  /* 41 V JUMP P L B */
    elena_atca_042,  /* 42 V JUMP K S A */
    elena_atca_042,  /* 43 V JUMP K S B */
    elena_atca_044,  /* 44 V JUMP K M A */
    elena_atca_044,  /* 45 V JUMP K M B */
    elena_atca_046,  /* 46 V JUMP K L A */
    elena_atca_046,  /* 47 V JUMP K L B */
    elena_atca_048,  /* 48 F JUMP P S A */
    elena_atca_048,  /* 49 F JUMP P S B */
    elena_atca_050,  /* 50 F JUMP P M A */
    elena_atca_050,  /* 51 F JUMP P M B */
    elena_atca_052,  /* 52 F JUMP P L A */
    elena_atca_052,  /* 53 F JUMP P L B */
    elena_atca_054,  /* 54 F JUMP K S A */
    elena_atca_054,  /* 55 F JUMP K S B */
    elena_atca_056,  /* 56 F JUMP K M A */
    elena_atca_056,  /* 57 F JUMP K M B */
    elena_atca_058,  /* 58 F JUMP K L A */
    elena_atca_058,  /* 59 F JUMP K L B */
    elena_atca_060,  /* 60 B JUMP P S A */
    elena_atca_060,  /* 61 B JUMP P S B */
    elena_atca_062,  /* 62 B JUMP P M A */
    elena_atca_062,  /* 63 B JUMP P M B */
    elena_atca_064,  /* 64 B JUMP P L A */
    elena_atca_064,  /* 65 B JUMP P L B */
    elena_atca_066,  /* 66 B JUMP K S A */
    elena_atca_066,  /* 67 B JUMP K S B */
    elena_atca_068,  /* 68 B JUMP K M A */
    elena_atca_068,  /* 69 B JUMP K M B */
    elena_atca_070,  /* 70 B JUMP K L A */
    elena_atca_070,  /* 71 B JUMP K L B */
    elena_atca_072,  /* 72 SP V JP S P A */
    elena_atca_072,  /* 73 SP V JP S P B */
    elena_atca_074,  /* 74 SP V JP M P A */
    elena_atca_074,  /* 75 SP V JP M P B */
    elena_atca_076,  /* 76 SP V JP L P A */
    elena_atca_076,  /* 77 SP V JP L P B */
    elena_atca_078,  /* 78 SP V JP S K A */
    elena_atca_078,  /* 79 SP V JP S K B */
    elena_atca_080,  /* 80 SP V JP M K A */
    elena_atca_080,  /* 81 SP V JP M K B */
    elena_atca_082,  /* 82 SP V JP L K A */
    elena_atca_082,  /* 83 SP V JP L K B */
    elena_atca_084,  /* 84 SP F JP S P A */
    elena_atca_084,  /* 85 SP F JP S P B */
    elena_atca_086,  /* 86 SP F JP M P A */
    elena_atca_086,  /* 87 SP F JP M P B */
    elena_atca_088,  /* 88 SP F JP L P A */
    elena_atca_088,  /* 89 SP F JP L P B */
    elena_atca_090,  /* 90 SP F JP S K A */
    elena_atca_090,  /* 91 SP F JP S K B */
    elena_atca_092,  /* 92 SP F JP M K A */
    elena_atca_092,  /* 93 SP F JP M K B */
    elena_atca_094,  /* 94 SP F JP L K A */
    elena_atca_094,  /* 95 SP F JP L K B */
    elena_atca_096,  /* 96 SP B JP S P A */
    elena_atca_096,  /* 97 SP B JP S P B */
    elena_atca_098,  /* 98 SP B JP M P A */
    elena_atca_098,  /* 99 SP B JP M P B */
    elena_atca_100,  /* 100 SP B JP L P A */
    elena_atca_100,  /* 101 SP B JP L P B */
    elena_atca_102,  /* 102 SP B JP S K A */
    elena_atca_102,  /* 103 SP B JP S K B */
    elena_atca_104,  /* 104 SP B JP M K A */
    elena_atca_104,  /* 105 SP B JP M K B */
    elena_atca_106,  /* 106 SP B JP L K A */
    elena_atca_106,  /* 107 SP B JP L K B */
    elena_atca_108,  /* 108 S V JP S P A */
    elena_atca_108,  /* 109 S V JP S P B */
    elena_atca_110,  /* 110 S V JP M P A */
    elena_atca_110,  /* 111 S V JP M P B */
    elena_atca_112,  /* 112 S V JP L P A */
    elena_atca_112,  /* 113 S V JP L P B */
    elena_atca_114,  /* 114 S V JP S K A */
    elena_atca_114,  /* 115 S V JP S K B */
    elena_atca_116,  /* 116 S V JP M K A */
    elena_atca_116,  /* 117 S V JP M K B */
    elena_atca_118,  /* 118 S V JP L K A */
    elena_atca_118,  /* 119 S V JP L K B */
    elena_atca_108,  /* 120 S F JP S P A */
    elena_atca_108,  /* 121 S F JP S P B */
    elena_atca_110,  /* 122 S F JP M P A */
    elena_atca_110,  /* 123 S F JP M P B */
    elena_atca_112,  /* 124 S F JP L P A */
    elena_atca_112,  /* 125 S F JP L P B */
    elena_atca_114,  /* 126 S F JP S K A */
    elena_atca_114,  /* 127 S F JP S K B */
    elena_atca_116,  /* 128 S F JP M K A */
    elena_atca_116,  /* 129 S F JP M K B */
    elena_atca_118,  /* 130 S F JP L K A */
    elena_atca_118,  /* 131 S F JP L K B */
    elena_atca_108,  /* 132 S B JP S P A */
    elena_atca_108,  /* 133 S B JP S P B */
    elena_atca_110,  /* 134 S B JP M P A */
    elena_atca_110,  /* 135 S B JP M P B */
    elena_atca_112,  /* 136 S B JP L P A */
    elena_atca_112,  /* 137 S B JP L P B */
    elena_atca_114,  /* 138 S B JP S K A */
    elena_atca_114,  /* 139 S B JP S K B */
    elena_atca_116,  /* 140 S B JP M K A */
    elena_atca_116,  /* 141 S B JP M K B */
    elena_atca_118,  /* 142 S B JP L K A */
    elena_atca_118,  /* 143 S B JP L K B */
    elena_atca_144,  /* 144 TUKAMIKAKARI A */
    elena_atca_145,  /* 145 TUKAMIKAKARI B */
    elena_atca_144,  /* 146 TUKAMIKAKARI C */
    elena_atca_145,  /* 147 TUKAMIKAKARI D */
    elena_atca_145,  /* 148 TUKAMIKAKARI E */
    elena_atca_145,  /* 149 TUKAMIKAKARI F */
    elena_atca_145,  /* 150 TUKAMI AIR A */
    elena_atca_145,  /* 151 TUKAMI AIR B */
    elena_atca_145,  /* 152 TUKAMI AIR C */
    elena_atca_145,  /* 153 TUKAMI AIR D */
    elena_atca_145,  /* 154 TUKAMI AIR E */
    elena_atca_145,  /* 155 TUKAMI AIR F */
    elena_atca_156,  /* 156 follow-up of V JUMP P S A, F JUMP P S A */
    elena_atca_157,  /* 157 follow-up of V JUMP P M A, F JUMP P M A */
    elena_atca_158,  /* 158 follow-up of L PUNCH A */
    elena_atca_159,  /* 159 follow-up of M KICK A */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B */
const u16 elena_atca_000_head[4] = { HEAD(6, 0, 0, 10, 0, 1, 0) };
const u16 elena_atca_000[220] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3100, 0, 97, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3101, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3102, 0, 97, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3103, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3104, -5, 98, 0, 135, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3105, 0, 98, 0, 0, 96, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3106, 0, 99, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3107, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3108, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3109, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310A, 0, 102, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x310B, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3027, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 41), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 62), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 S PUNCH C */
const u16 elena_atca_002_head[4] = { HEAD(6, 0, 0, 14, 0, 13, 0) };
const u16 elena_atca_002[328] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x3333, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3334, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3335, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3336, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3337, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3338, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3339, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333A, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333B, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333D, 0, 190, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333E, 0, 191, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x333F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3340, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3341, 0, 192, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3342, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x3155, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3154, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x3351, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3352, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3353, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x301E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 46), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 elena_atca_003_head[4] = { HEAD(6, 0, 2, 10, 0, 2, 0) };
const u16 elena_atca_003[268] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x309E, 0, 76, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x309F, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A0, 0, 77, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A1, 0, 77, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A2, 0, 77, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x30A3, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30A4, -68, 78, 0, 0, 96, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30A5, -2, 79, 0, 128, 64, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30A6, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30A7, 0, 242, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30A8, 0, 81, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30A9, 0, 81, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30AA, 0, 81, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30AB, 0, 82, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30AC, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30AD, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3028, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 42), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 62), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 elena_atca_005_head[4] = { HEAD(6, 0, 2, 12, 0, 1, 0) };
const u16 elena_atca_005[316] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3144, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3143, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3136, 0, 71, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3137, 0, 71, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3138, 0, 71, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3139, 0, 72, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3139, 0, 74, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x313A, -1, 73, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x313A, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x313A, 0, 74, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x313B, 0, 74, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x313C, 0, 72, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x313D, 0, 72, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x313E, 0, 72, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x313F, 0, 72, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3140, 0, 71, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3141, 0, 71, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3142, 0, 71, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3143, 0, 75, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3144, 0, 75, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x301E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 46), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B, 8 L PUNCH C */
const u16 elena_atca_006_head[4] = { HEAD(6, 0, 4, 14, 0, 1, 0) };
const u16 elena_atca_006[364] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 1, 0, 0, 0, 0x30D9, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DA, 0, 83, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DB, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DC, 0, 83, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DD, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30DE, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DF, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30E0, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30E1, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 678, 1, 0, 0, 0, 0x30E2, 0, 85, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x30E3, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30E4, -3, 238, 3205, 0, 8, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30E5, 0, 87, 3205, 0, 8, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E5, 0, 239, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E6, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E7, 0, 240, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E8, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E9, 0, 84, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EA, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EB, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EC, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30ED, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30EE, 0, 160, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3022, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 36), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 52), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 elena_atca_009_head[4] = { HEAD(6, 0, 1, 9, 0, 1, 0) };
const u16 elena_atca_009[148] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3154, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3155, 0, 103, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3156, -7, 104, 0, 133, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3157, 0, 104, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3157, 0, 105, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3158, 0, 106, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3014, 0, 106, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 elena_atca_012_head[4] = { HEAD(6, 0, 3, 14, 0, 1, 0) };
const u16 elena_atca_012[256] = {
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3159, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315A, 0, 127, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315B, 0, 128, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315C, 0, 128, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315D, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x315E, 0, 228, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x315F, -9, 129, 2114, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315F, 0, 228, 2114, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3160, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3161, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3162, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3163, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3164, 0, 132, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3165, 0, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x301E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 47), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 elena_atca_014_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 elena_atca_014[148] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3550, 0, 366, 0, 0, 0, 32, 141),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3551, 0, 367, 0, 0, 0, 32, 142),
    L4(3, 0, 269, 0, 0, 0, 0, 0x3552, 0, 368, 0, 0, 0, 32, 143),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3553, -113, 369, 0, 0, 0, 32, 144),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3554, 0, 370, 0, 0, 0, 32, 145),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3555, 0, 371, 0, 0, 0, 32, 146),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3556, 0, 372, 0, 0, 0, 32, 147),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3557, 0, 361, 0, 0, 0, 32, 148),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3558, 0, 362, 0, 0, 0, 32, 122),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3559, 0, 363, 0, 0, 0, 32, 123),
    L4(3, 64, 0, 0, 0, 0, 0, 0x355A, 0, 364, 0, 0, 0, 32, 124),
    L4(3, 0, 0, 0, 0, 0, 0, 0x355B, 0, 365, 0, 0, 0, 32, 125),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 83), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 elena_atca_015_head[4] = { HEAD(6, 0, 5, 11, 0, 1, 0) };
const u16 elena_atca_015[316] = {
    L6(1, 0, 0, 1, 0, 0, 0, 0x30EF, 0, 89, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F0, 0, 89, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F1, 0, 90, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30F2, 0, 90, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30F3, 0, 90, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F4, 0, 91, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 677, 1, 0, 0, 0, 0x30F5, 0, 91, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x30F5, 0, 91, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F6, -4, 92, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F6, 0, 93, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F7, 0, 93, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x30F7, 0, 94, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30F8, 0, 94, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30F9, 4, 243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FA, 4, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FB, 0, 95, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FC, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x30FD, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FE, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FF, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3039, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 elena_atca_017_head[4] = { HEAD(4, 0, 5, 13, 0, 0, 0) };
const u16 elena_atca_017[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3540, 0, 393, 0, 0, 0, 32, 171),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3541, 0, 394, 0, 0, 0, 32, 171),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3542, 0, 395, 0, 0, 0, 32, 171),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3543, 0, 396, 0, 0, 0, 32, 171),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3544, -114, 397, 0, 0, 0, 32, 172),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3545, 0, 398, 0, 0, 0, 32, 172),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3546, 0, 399, 0, 0, 0, 32, 172),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3547, 0, 400, 0, 0, 0, 32, 172),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3548, 0, 401, 0, 0, 0, 32, 172),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3549, 0, 402, 0, 0, 0, 32, 172),
    L4(3, 0, 0, 0, 0, 0, 0, 0x354A, 0, 403, 0, 0, 0, 32, 172),
    L4(3, 0, 0, 0, 0, 0, 0, 0x354B, 0, 404, 0, 0, 0, 32, 172),
    L4(3, 0, 0, 0, 0, 0, 0, 0x354C, 0, 405, 0, 0, 0, 32, 172),
    L4(2, 0, 0, 0, 0, 0, 0, 0x354D, 0, 406, 0, 0, 0, 32, 172),
    L4(1, 64, 0, 0, 0, 0, 0, 0x354E, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 elena_atca_018_head[4] = { HEAD(4, 32, 0, 13, 0, 1, 0) };
const u16 elena_atca_018[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x32C0, 0, 20, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x32C1, 0, 20, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x32C2, -13, 230, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32C4, 0, 257, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32C5, 0, 21, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32C6, 0, 21, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32C7, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32C8, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x32CA, 0, 20, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 5), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 elena_atca_021_head[4] = { HEAD(4, 32, 2, 14, 0, 1, 0) };
const u16 elena_atca_021[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x32CB, 0, 20, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32D4, 0, 20, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x32CC, 0, 20, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x32CD, -14, 231, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32CD, 0, 31, 0, 0, 64, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32CE, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32CF, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32D0, 0, 23, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32D1, 0, 23, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32D2, 0, 24, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32D3, 0, 24, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32D4, 0, 20, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x32D5, 0, 20, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 elena_atca_024_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 elena_atca_024[316] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D6, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D7, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D8, 0, 33, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D9, 0, 34, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 1, 270, 0, 0, 0, 0, 0x32DA, 0, 35, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DB, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DC, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DC, -15, 36, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DE, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DF, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E2, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E4, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E5, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E6, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 elena_atca_027_head[4] = { HEAD(6, 32, 1, 12, 0, 1, 0) };
const u16 elena_atca_027[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E9, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x32EA, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32EB, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32EB, -16, 26, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32EC, 0, 26, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32ED, 0, 27, 0, 0, 0, 21, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32EE, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32EF, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F1, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x32F2, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 elena_atca_030_head[4] = { HEAD(6, 32, 3, 14, 0, 1, 0) };
const u16 elena_atca_030[292] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F4, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F5, 0, 39, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32F6, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32F7, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x355C, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x355D, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x355E, 0, 233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x355E, -17, 234, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x355E, 0, 233, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32FB, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32FC, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32FD, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32FE, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32FF, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3300, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3301, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3302, 0, 39, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3303, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3304, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B */
const u16 elena_atca_033_head[4] = { HEAD(6, 32, 5, 13, 0, 1, 0) };
const u16 elena_atca_033[304] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3305, 0, 141, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3306, 0, 142, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3307, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3308, 0, 146, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3309, 0, 235, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3309, -18, 143, 0, 136, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3309, 0, 235, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x330A, 0, 144, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x330B, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x330C, 0, 144, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x330D, 0, 144, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x330E, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x330F, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3310, 0, 142, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3311, 0, 147, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3312, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3313, 0, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3314, 0, 148, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3315, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3316, 0, 32, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 KAGAMI K C */
const u16 elena_atca_035_head[4] = { HEAD(6, 32, 5, 13, 0, 1, 0) };
const u16 elena_atca_035[292] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3145, 0, 107, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3146, 0, 107, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x3147, 0, 108, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3148, 0, 111, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x3149, -8, 110, 0, 0, 0, 30, 16, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3149, 0, 110, 0, 0, 0, 30, 17, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3149, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3149, 0, 111, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314A, 0, 111, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314B, 0, 111, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314C, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314D, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314E, 0, 113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x314F, 0, 113, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3150, 0, 114, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3151, 0, 114, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3152, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3153, 0, 115, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x301E, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 elena_atca_036_head[4] = { HEAD(6, 22, 0, 6, 0, 1, 0) };
const u16 elena_atca_036[196] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x310C, 0, 44, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 5, 0x310D, 0, 45, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 5, 0x310E, -19, 46, 2572, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x310D, 19, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x310C, 0, 44, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 elena_atca_038_head[4] = { HEAD(6, 22, 2, 13, 0, 1, 0) };
const u16 elena_atca_038[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3113, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 5, 0x3113, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x3115, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 5, 0x3116, -20, 49, 2124, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3116, 0, 50, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3117, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3118, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3119, 0, 47, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 elena_atca_040_head[4] = { HEAD(6, 22, 4, 13, 0, 1, 0) };
const u16 elena_atca_040[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3122, 0, 51, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3123, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3124, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3125, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3125, -21, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3126, 21, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3126, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3127, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3128, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3129, 0, 47, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 elena_atca_042_head[4] = { HEAD(6, 22, 1, 12, 0, 1, 0) };
const u16 elena_atca_042[196] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3110, 0, 55, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3110, -22, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3111, 22, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3111, 0, 55, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 elena_atca_044_head[4] = { HEAD(6, 22, 3, 13, 0, 1, 0) };
const u16 elena_atca_044[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x311A, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311B, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 5, 0x311C, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x311D, 0, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311D, -23, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 5, 0x311E, 23, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311E, 0, 58, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3120, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 5, 0x3121, 0, 47, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 elena_atca_046_head[4] = { HEAD(6, 22, 5, 12, 0, 2, 0) };
const u16 elena_atca_046[256] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x312A, 0, 134, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x312B, 0, 135, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x312C, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x312D, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x312E, -24, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x312F, -25, 137, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3130, 0, 137, 0, 137, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3130, 0, 226, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3131, 0, 138, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3132, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3133, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3134, 0, 140, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3135, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 elena_atca_048_head[4] = { HEAD(6, 20, 0, 7, 0, 1, 0) };
const u16 elena_atca_048[196] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x310C, 0, 44, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 5, 0x310D, 0, 45, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 5, 0x310E, -19, 46, 2572, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x310D, 19, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x310C, 0, 44, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 elena_atca_050_head[4] = { HEAD(6, 20, 2, 14, 0, 1, 0) };
const u16 elena_atca_050[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3113, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 5, 0x3113, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x3115, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 5, 0x3116, -20, 49, 2124, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3116, 0, 50, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3117, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3118, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3119, 0, 47, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 elena_atca_052_head[4] = { HEAD(6, 20, 4, 14, 0, 1, 0) };
const u16 elena_atca_052[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3122, 0, 51, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3123, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3124, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3125, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3125, -21, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3126, 21, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3126, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3127, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3128, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3129, 0, 47, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 elena_atca_054_head[4] = { HEAD(6, 20, 1, 13, 0, 1, 0) };
const u16 elena_atca_054[196] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3110, 0, 55, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3110, -22, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3111, 22, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3111, 0, 55, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 elena_atca_056_head[4] = { HEAD(6, 20, 3, 14, 0, 1, 0) };
const u16 elena_atca_056[220] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x311A, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311B, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 5, 0x311C, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 5, 0x311D, 0, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311D, -23, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 5, 0x311E, 23, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311E, 0, 58, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x311F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3120, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 5, 0x3121, 0, 47, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 elena_atca_058_head[4] = { HEAD(6, 20, 5, 13, 0, 1, 0) };
const u16 elena_atca_058[256] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x312A, 0, 134, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x312B, 0, 135, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x312C, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x312D, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x312E, -24, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x312F, -25, 137, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3130, 0, 137, 0, 137, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3130, 0, 226, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3131, 0, 138, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3132, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3133, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3134, 0, 140, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3135, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 elena_atca_060_head[4] = { HEAD(2, 24, 0, 6, 0, 1, 0) };
const u16 elena_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 elena_atca_062_head[4] = { HEAD(2, 24, 2, 13, 0, 1, 0) };
const u16 elena_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 elena_atca_064_head[4] = { HEAD(2, 24, 4, 13, 0, 1, 0) };
const u16 elena_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 elena_atca_066_head[4] = { HEAD(2, 24, 1, 12, 0, 1, 0) };
const u16 elena_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 elena_atca_068_head[4] = { HEAD(2, 24, 3, 13, 0, 1, 0) };
const u16 elena_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 elena_atca_070_head[4] = { HEAD(2, 24, 5, 12, 0, 2, 0) };
const u16 elena_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 elena_atca_072_head[4] = { HEAD(2, 28, 0, 6, 0, 1, 0) };
const u16 elena_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 elena_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 elena_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 elena_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 elena_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 elena_atca_078_head[4] = { HEAD(2, 28, 1, 12, 0, 1, 0) };
const u16 elena_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 elena_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 elena_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 elena_atca_082_head[4] = { HEAD(2, 28, 5, 12, 0, 2, 0) };
const u16 elena_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 elena_atca_084_head[4] = { HEAD(2, 26, 0, 7, 0, 1, 0) };
const u16 elena_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 elena_atca_086_head[4] = { HEAD(2, 26, 2, 14, 0, 1, 0) };
const u16 elena_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 elena_atca_088_head[4] = { HEAD(2, 26, 4, 14, 0, 1, 0) };
const u16 elena_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 elena_atca_090_head[4] = { HEAD(2, 26, 1, 13, 0, 1, 0) };
const u16 elena_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 elena_atca_092_head[4] = { HEAD(2, 26, 3, 14, 0, 1, 0) };
const u16 elena_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 elena_atca_094_head[4] = { HEAD(2, 26, 5, 13, 0, 2, 0) };
const u16 elena_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 elena_atca_096_head[4] = { HEAD(2, 30, 0, 6, 0, 1, 0) };
const u16 elena_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 elena_atca_098_head[4] = { HEAD(2, 30, 2, 13, 0, 1, 0) };
const u16 elena_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 elena_atca_100_head[4] = { HEAD(2, 30, 4, 13, 0, 1, 0) };
const u16 elena_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 elena_atca_102_head[4] = { HEAD(2, 30, 1, 12, 0, 1, 0) };
const u16 elena_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 elena_atca_104_head[4] = { HEAD(2, 30, 3, 13, 0, 1, 0) };
const u16 elena_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 elena_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 2, 0) };
const u16 elena_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 elena_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 elena_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 elena_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 elena_atca_110[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 elena_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 elena_atca_112[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 elena_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 elena_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 elena_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 elena_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 elena_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 elena_atca_118[152] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3584, 0, 0),
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3586, 0, 0),
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3588, 0, 0),
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3585, 0, 0),
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3587, 0, 0),
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3589, 0, 0),
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4608, 0, 0),
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4610, 0, 0),
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4612, 0, 0),
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4609, 0, 0),
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4611, 0, 0),
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4613, 0, 0),
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 elena_atca_145_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_atca_145[116] = {
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x352B, 0, 455, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x352B, -10, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 1, 0, 0, 0x352C, 0, 456, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x352D, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x352E, 0, 458, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x352F, 0, 459, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3530, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3531, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3532, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 1, 0, 0, 0x3533, 0, 462, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 44), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 146 TUKAMIKAKARI C */
const u16 elena_atca_144_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_atca_144[16] = {
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_JPSS, 4, 145, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of V JUMP P S A, F JUMP P S A */
const u16 elena_atca_156_head[4] = { HEAD(6, 20, 3, 14, 0, 1, 0) };
const u16 elena_atca_156[196] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x311A, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x311B, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x311C, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x311D, -72, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x311E, 0, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x311F, 0, 58, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3120, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3121, 0, 47, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of V JUMP P M A, F JUMP P M A */
const u16 elena_atca_157_head[4] = { HEAD(6, 22, 4, 13, 0, 1, 0) };
const u16 elena_atca_157[184] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3123, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3124, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3125, -98, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3126, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3126, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310D, 0, 48, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3113, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3095, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3096, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3097, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of L PUNCH A */
const u16 elena_atca_158_head[4] = { HEAD(6, 0, 5, 11, 0, 1, 0) };
const u16 elena_atca_158[340] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E6, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E8, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E9, 0, 84, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EA, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EB, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30F2, 0, 90, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30F3, 0, 90, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x30F4, 0, 91, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 677, 1, 0, 0, 0, 0x30F5, 0, 91, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x30F5, 0, 91, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F6, -115, 92, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F6, 0, 93, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30F7, 0, 93, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x30F7, 0, 94, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30F8, 0, 94, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30F9, 4, 243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FA, 4, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FB, 0, 95, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FC, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x30FD, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FE, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30FF, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3039, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of M KICK A */
const u16 elena_atca_159_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 elena_atca_159[304] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x315F, 0, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3161, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D7, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D9, 0, 34, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 1, 270, 0, 0, 0, 0, 0x32DA, 0, 35, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DB, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DC, -116, 64, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32DE, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DF, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E2, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E4, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E5, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E6, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX elena_olc_ix_table[91] = {
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
    { { 18, 0, 0, 0 } },
    { { 19, 0, 0, 0 } },
    { { 20, 0, 0, 0 } },
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
    { { 70, 0, 0, 0 } },
    { { 71, 0, 0, 0 } },
    { { 72, 0, 0, 0 } },
    { { 73, 0, 0, 0 } },
    { { 74, 0, 0, 0 } },
    { { 75, 0, 0, 0 } },
    { { 76, 0, 0, 0 } },
    { { 77, 0, 0, 0 } },
    { { 78, 0, 0, 0 } },
    { { 79, 0, 0, 0 } },
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
};

const OVERLAP_PARTS elena_overlap_char_tbl[91] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 40210 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 40211 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 40212 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 40213 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 40214 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 6, 40215 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 7, 40216 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 8, 40217 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 9, 40218 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 10, 40219 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 11, 40220 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 12, 40221 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 13, 40222 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 14, 40223 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 15, 40224 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 16, 40225 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 40188 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 18, 40189 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 19, 40190 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 40191 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 40192 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 40193 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 40194 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 40195 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 40196 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 40197 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 40198 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 28, 40199 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 29, 40200 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 30, 40201 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 31, 40202 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 32, 40203 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 33, 40130 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 34, 40131 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 35, 40132 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 36, 40133 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 37, 40134 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 38, 40135 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 39, 40136 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 40, 40137 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 41, 40138 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 42, 40139 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 40140 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 40141 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 40142 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 40143 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 47, 40144 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 48, 40145 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 49, 40146 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 50, 40147 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 51, 40148 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 52, 40149 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 53, 40150 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 54, 40151 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 55, 40152 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 56, 40153 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 57, 40154 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 58, 40155 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 59, 40156 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 60, 40157 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 61, 40158 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 62, 40159 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 63, 40160 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 64, 40161 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 65, 40162 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 66, 40163 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 67, 40164 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 68, 40165 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 69, 40166 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 70, 40167 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 71, 40168 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 72, 40169 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 73, 40170 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 74, 40171 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 75, 40172 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 76, 40173 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 77, 40174 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 78, 40175 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 79, 40176 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 80, 40177 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 81, 40178 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 82, 40179 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 83, 40180 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 84, 40181 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 85, 40182 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 86, 40183 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 87, 40184 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 88, 40185 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 89, 40186 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 90, 40187 },
};

const CatchTable elena_rival_catch_tbl[264] = {
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -70, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -84, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -70, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 3 },
    { -68, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -68, 0, 1, 1, 3 },
    { -70, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -68, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -68, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -58, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -90, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { -70, 0, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { -58, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 5 },
    { -68, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -60, 0, 1, 1, 5 },
    { -60, 0, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -68, 0, 1, 1, 5 },
    { -70, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -68, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -64, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { -60, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 22, 2, 1, 6 },
    { -70, 42, 2, 1, 6 },
    { -70, 58, 1, 1, 6 },
    { -52, 59, 1, 1, 6 },
    { -70, 32, 2, 1, 6 },
    { -64, 48, 1, 1, 6 },
    { -74, 49, 2, 1, 6 },
    { -66, 46, 1, 1, 6 },
    { -86, 54, 1, 1, 6 },
    { -72, 58, 1, 1, 6 },
    { -52, 59, 1, 1, 6 },
    { -70, 58, 1, 1, 6 },
    { -70, 58, 1, 1, 6 },
    { -80, 22, 2, 1, 6 },
    { -70, 58, 1, 1, 6 },
    { -70, 58, 1, 1, 6 },
    { -70, 42, 1, 1, 6 },
    { -82, 54, 1, 1, 6 },
    { -80, 22, 2, 1, 6 },
    { -62, 34, 2, 1, 6 },
    { -80, 31, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, 154, 2, 1, 7 },
    { -52, 186, 2, 1, 7 },
    { -52, 180, 2, 1, 7 },
    { -88, 86, 2, 1, 7 },
    { -58, 204, 1, 1, 7 },
    { -60, 184, 1, 1, 7 },
    { -51, 53, 2, 1, 7 },
    { -70, 166, 1, 1, 7 },
    { -66, 158, 2, 1, 7 },
    { -60, 180, 1, 1, 7 },
    { -88, 86, 2, 1, 7 },
    { -52, 180, 2, 1, 7 },
    { -52, 180, 2, 1, 7 },
    { -64, 154, 2, 1, 7 },
    { -52, 180, 2, 1, 7 },
    { -52, 180, 2, 1, 7 },
    { -44, 186, 2, 1, 7 },
    { -69, 76, 2, 1, 7 },
    { -54, 48, 2, 1, 7 },
    { -62, 192, 2, 1, 7 },
    { -64, 74, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -25, 212, 2, 1, 8 },
    { -6, 224, 2, 1, 8 },
    { -26, 164, 2, 1, 8 },
    { -44, 192, 2, 1, 8 },
    { -30, 202, 2, 1, 8 },
    { -36, 208, 1, 1, 8 },
    { -8, 78, 2, 1, 8 },
    { -6, 158, 1, 1, 8 },
    { -40, 182, 2, 1, 8 },
    { -22, 188, 1, 1, 8 },
    { -44, 192, 2, 1, 8 },
    { -26, 164, 2, 1, 8 },
    { -26, 164, 2, 1, 8 },
    { -25, 212, 2, 1, 8 },
    { -26, 164, 2, 1, 8 },
    { -26, 164, 2, 1, 8 },
    { -24, 182, 2, 1, 8 },
    { -8, 168, 2, 1, 8 },
    { -8, 164, 2, 1, 8 },
    { -36, 208, 2, 1, 8 },
    { -20, 204, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 32, 104, 1, 1, 9 },
    { 32, 108, 1, 1, 9 },
    { 32, 116, 1, 1, 9 },
    { 32, 124, 1, 1, 9 },
    { 32, 98, 1, 1, 9 },
    { 32, 124, 1, 1, 9 },
    { 36, 89, 2, 1, 9 },
    { 32, 100, 1, 1, 9 },
    { 32, 118, 1, 1, 9 },
    { 40, 132, 1, 1, 9 },
    { 32, 124, 1, 1, 9 },
    { 32, 116, 1, 1, 9 },
    { 32, 116, 1, 1, 9 },
    { 32, 104, 1, 1, 9 },
    { 32, 116, 1, 1, 9 },
    { 32, 116, 1, 1, 9 },
    { 32, 108, 1, 1, 9 },
    { 28, 132, 1, 1, 9 },
    { 40, 72, 1, 1, 9 },
    { 32, 76, 1, 1, 9 },
    { 32, 108, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 68 entries */
const u16* const elena_exca[69] = {
    elena_exca_000,  /* 0 follow-up of APPEAR JUNBI 2 */
    elena_exca_001,  /* 1 follow-up of GUARD AIR, APPEAR JUNBI 2 */
    elena_exca_000,  /* 2 follow-up of APPEAR JUNBI 5 */
    elena_exca_001,  /* 3 follow-up of APPEAR JUNBI 5 */
    elena_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    elena_exca_005,  /* 5 follow-up of APPEAR JUNBI 4 */
    elena_exca_006,  /* 6 follow-up of JUDGMENT WIN */
    elena_exca_007,  /* 7 follow-up of JUDGMENT WIN */
    elena_exca_008,  /* 8 follow-up of SP WIN 1 */
    elena_exca_009,  /* 9 follow-up of SP WIN 1 */
    elena_exca_010,  /* 10 follow-up of GUARD AIR */
    elena_exca_011,  /* 11 follow-up of TOMOE RYU, TOMOE ORO +8 */
    elena_exca_010,  /* 12 no name */
    elena_exca_010,  /* 13 no name */
    elena_exca_014,  /* 14 follow-up of ASIBARAI SIRI */
    elena_exca_015,  /* 15 follow-up of ASIB TUNNOMERI, HUMI ASIB */
    elena_exca_016,  /* 16 follow-up of NOKEZORI, KUNOJI NOKE +9 */
    elena_exca_017,  /* 17 follow-up of KUNOJI, KIRIMOMI +13 */
    elena_exca_018,  /* 18 follow-up of TATAKI S, TATAKI V. S +4 */
    elena_exca_019,  /* 19 follow-up of AIR NORMAL */
    elena_exca_020,  /* 20 follow-up of APPEAR JUNBI 6 */
    elena_exca_020,  /* 21 follow-up of APPEAR JUNBI 6 */
    elena_exca_010,  /* 22 no name */
    elena_exca_023,  /* 23 follow-up of APPEAR JUNBI 7 */
    elena_exca_024,  /* 24 follow-up of APPEAR JUNBI 7 */
    elena_exca_025,  /* 25 follow-up of APPEAR JUNBI 8 */
    elena_exca_026,  /* 26 follow-up of APPEAR JUNBI 8 */
    elena_exca_027,  /* 27 follow-up of APPEAR 1 */
    elena_exca_028,  /* 28 follow-up of APPEAR 1 */
    elena_exca_029,  /* 29 follow-up of SP WIN 2 */
    elena_exca_029,  /* 30 follow-up of SP WIN 2 */
    elena_exca_031,  /* 31 follow-up of IBUKI HARAIG */
    elena_exca_032,  /* 32 follow-up of SP WIN 3 */
    elena_exca_033,  /* 33 follow-up of SP WIN 3 */
    elena_exca_034,  /* 34 follow-up of SP WIN 4 */
    elena_exca_035,  /* 35 follow-up of SP WIN 4 */
    elena_exca_036,  /* 36 follow-up of SP WIN 6 */
    elena_exca_037,  /* 37 follow-up of SP WIN 6 */
    elena_exca_038,  /* 38 follow-up of SP WIN 7 */
    elena_exca_039,  /* 39 follow-up of SP WIN 7 */
    elena_exca_040,  /* 40 follow-up of SP WIN 8 */
    elena_exca_041,  /* 41 follow-up of SP WIN 8 */
    elena_exca_042,  /* 42 follow-up of JUDGMENT WAIT */
    elena_exca_043,  /* 43 follow-up of JUDGMENT WAIT */
    elena_exca_044,  /* 44 follow-up of GILL IMPACT C */
    elena_exca_045,  /* 45 follow-up of GILL IMPACT C */
    elena_exca_046,  /* 46 follow-up of AFRICA JUMP */
    elena_exca_047,  /* 47 follow-up of AFRICA JUMP */
    elena_exca_048,  /* 48 follow-up of FLANKEN.S */
    elena_exca_049,  /* 49 follow-up of SEAN BALL HIT */
    elena_exca_050,  /* 50 follow-up of SEAN BALL HIT */
    elena_exca_049,  /* 51 no name */
    elena_exca_050,  /* 52 no name */
    elena_exca_053,  /* 53 follow-up of BONUS WIN 1 */
    elena_exca_054,  /* 54 follow-up of BONUS WIN 1 */
    elena_exca_055,  /* 55 follow-up of APPEAR USE */
    elena_exca_056,  /* 56 follow-up of APPEAR USE */
    elena_exca_057,  /* 57 no name */
    elena_exca_058,  /* 58 no name */
    elena_exca_059,  /* 59 no name */
    elena_exca_060,  /* 60 no name */
    elena_exca_061,  /* 61 no name */
    elena_exca_062,  /* 62 no name */
    elena_exca_063,  /* 63 no name */
    elena_exca_064,  /* 64 no name */
    elena_exca_065,  /* 65 no name */
    elena_exca_066,  /* 66 no name */
    elena_exca_067,  /* 67 no name */
    0
};

/* script: 0 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 5 */
const u16 elena_exca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_000[68] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x309A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x309B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3043, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of GUARD AIR, APPEAR JUNBI 2, 3 follow-up of APPEAR JUNBI 5 */
const u16 elena_exca_001_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_001[84] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x309A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x309B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 elena_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_004[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x309A, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x309B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3043, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of APPEAR JUNBI 4 */
const u16 elena_exca_005_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_005[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x309A, 0, 3, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x309B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of JUDGMENT WIN */
const u16 elena_exca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_006[52] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x303A, 0, 258, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3043, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of JUDGMENT WIN */
const u16 elena_exca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_007[68] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x303A, 0, 259, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of SP WIN 1 */
const u16 elena_exca_008_head[4] = { HEAD(4, 0, 15, 15, 0, 2, 19) };
const u16 elena_exca_008[76] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3173, -91, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, -92, 123, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of SP WIN 1 */
const u16 elena_exca_009_head[4] = { HEAD(4, 0, 15, 15, 0, 2, 19) };
const u16 elena_exca_009[124] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3173, -91, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, -92, 123, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 22, 32),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of GUARD AIR, 12 no name, 13 no name, 22 no name */
const u16 elena_exca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_010[8] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of TOMOE RYU, TOMOE ORO +8 */
const u16 elena_exca_011_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_011[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of ASIBARAI SIRI */
const u16 elena_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_014[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x321F, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3220, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3221, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3222, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3223, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3224, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3225, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3226, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3227, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3228, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3229, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x322A, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 9, 0, 0, 0, 0, 0, 0x322B, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of ASIB TUNNOMERI, HUMI ASIB */
const u16 elena_exca_015_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_015[116] = {
    L4(2, 2, 0, 0, 1, 0, 0, 0x3296, 0, 149, 0, 0, 0, 24, 0),
    L4(3, 2, 0, 0, 1, 0, 0, 0x3297, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3298, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3299, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x329E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x329F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x32A0, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x32A1, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x32A2, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x32A2, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of NOKEZORI, KUNOJI NOKE +9 */
const u16 elena_exca_016_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_016[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of KUNOJI, KIRIMOMI +13 */
const u16 elena_exca_017_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_017[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 follow-up of TATAKI S, TATAKI V. S +4 */
const u16 elena_exca_018_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_018[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 follow-up of AIR NORMAL */
const u16 elena_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_exca_019[140] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3562, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3563, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3564, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3565, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3566, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3567, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3568, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3091, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3092, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3093, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3094, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x3095, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3096, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3097, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 60, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 follow-up of APPEAR JUNBI 6, 21 follow-up of APPEAR JUNBI 6 */
const u16 elena_exca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_020[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x317E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x317F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3180, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 7 */
const u16 elena_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_023[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3055, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 48), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 7 */
const u16 elena_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_024[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 22, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR JUNBI 8 */
const u16 elena_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_025[68] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3358, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3359, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x335A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 27), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR JUNBI 8 */
const u16 elena_exca_026_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_026[100] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR 1 */
const u16 elena_exca_027_head[4] = { HEAD(4, 0, 9, 15, 0, 2, 19) };
const u16 elena_exca_027[84] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3173, -53, 122, 0, 0, 0, 1, 40),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3174, 56, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR 1 */
const u16 elena_exca_028_head[4] = { HEAD(4, 32, 9, 15, 0, 2, 19) };
const u16 elena_exca_028[132] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3173, -53, 122, 0, 0, 0, 1, 40),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3174, 56, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of SP WIN 2, 30 follow-up of SP WIN 2 */
const u16 elena_exca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_029[76] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x3212, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3213, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3214, 0, 67, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3215, 0, 67, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3216, 0, 68, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3217, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3218, 0, 68, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3218, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of IBUKI HARAIG */
const u16 elena_exca_031_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_031[156] = {
    L4(2, 1, 285, 0, 0, 0, 0, 0x3280, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3281, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3282, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3283, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3284, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3285, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3286, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3287, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3288, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3289, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x328C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x328F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3290, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3291, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of SP WIN 3 */
const u16 elena_exca_032_head[4] = { HEAD(4, 0, 11, 15, 0, 2, 19) };
const u16 elena_exca_032[84] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3173, -54, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, 57, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of SP WIN 3 */
const u16 elena_exca_033_head[4] = { HEAD(4, 32, 11, 15, 0, 2, 19) };
const u16 elena_exca_033[132] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3173, -54, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, 57, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP WIN 4 */
const u16 elena_exca_034_head[4] = { HEAD(4, 0, 13, 15, 0, 2, 19) };
const u16 elena_exca_034[84] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3173, -55, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, 58, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP WIN 4 */
const u16 elena_exca_035_head[4] = { HEAD(4, 32, 13, 15, 0, 2, 19) };
const u16 elena_exca_035[132] = {
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 1, 0, 0, 0x3172, 0, 121, 0, 0, 0, 24, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3173, -55, 122, 0, 0, 0, 1, 40),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3174, 58, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3175, -65, 174, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3175, 0, 124, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3176, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of SP WIN 6 */
const u16 elena_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_036[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3042, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 11, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of SP WIN 6 */
const u16 elena_exca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_037[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 22, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of SP WIN 7 */
const u16 elena_exca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_038[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3042, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 11, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of SP WIN 7 */
const u16 elena_exca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_039[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x32BE, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BF, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 22, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP WIN 8 */
const u16 elena_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_040[68] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3358, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3359, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x335A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 27), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of SP WIN 8 */
const u16 elena_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_041[100] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of JUDGMENT WAIT */
const u16 elena_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_042[68] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3358, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3359, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x335A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 27), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of JUDGMENT WAIT */
const u16 elena_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_043[100] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3354, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3355, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3356, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3357, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of GILL IMPACT C */
const u16 elena_exca_044_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_044[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x321F, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3220, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3221, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3222, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3223, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3224, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3225, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3226, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3227, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3228, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3229, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x322A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x322B, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of GILL IMPACT C */
const u16 elena_exca_045_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_045[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x321F, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3220, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3221, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3222, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3223, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3224, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3225, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3226, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3227, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x3228, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3229, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x322A, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x322B, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of AFRICA JUMP */
const u16 elena_exca_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_046[68] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x309A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x309B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3043, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of AFRICA JUMP */
const u16 elena_exca_047_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_047[84] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x309A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x309B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of FLANKEN.S */
const u16 elena_exca_048_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 elena_exca_048[116] = {
    L4(2, 2, 0, 0, 1, 0, 0, 0x3296, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 1, 0, 0, 0x3297, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3298, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3299, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329A, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329B, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329C, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x329D, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x329E, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x329F, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x32A0, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x32A1, 0, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x32A2, 0, 149, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x32A2, 0, 149, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SEAN BALL HIT, 51 no name */
const u16 elena_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_049[76] = {
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x317D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x317E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x317F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3180, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of SEAN BALL HIT, 52 no name */
const u16 elena_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_050[76] = {
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of BONUS WIN 1 */
const u16 elena_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_053[76] = {
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x317D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x317E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x317F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3180, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3181, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of BONUS WIN 1 */
const u16 elena_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_054[76] = {
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of APPEAR USE */
const u16 elena_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_055[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x309A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x309B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3043, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3044, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 53), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of APPEAR USE */
const u16 elena_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_exca_056[84] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x309A, 0, 3, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x309B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 elena_exca_057_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 elena_exca_057[140] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3562, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3563, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3564, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3565, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3566, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3567, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3568, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3091, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3092, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3093, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3094, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x3095, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3096, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3097, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3098, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3099, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 elena_exca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_058[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D15),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D16),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D17),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D18),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D1F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D21),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 elena_exca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_059[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9CFC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9CFD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9CFE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9CFF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D00),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D01),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D02),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D03),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D04),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D05),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D06),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D07),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D08),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D09),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0B),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 elena_exca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_060[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 elena_exca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_061[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0D),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 elena_exca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_062[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0E),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 elena_exca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_063[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D0F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 elena_exca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_064[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 elena_exca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_065[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 elena_exca_066_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_066[976] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x335B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x335C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x335D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x335E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x335F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3360, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3361, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3362, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3363, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3364, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3365, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3366, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3367, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3368, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3369, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x336F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3370, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3371, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3372, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3373, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3374, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3375, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3376, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3377, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3378, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3379, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x337F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3380, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3381, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3382, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3383, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3384, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3385, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3386, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3387, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3388, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3389, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x338F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3390, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3391, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3392, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3393, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3394, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3395, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3396, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3397, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3398, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3399, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x339F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x33A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x33AA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 255, 0, 0, 0, 0, 0, 0x33AA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 elena_exca_067_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 elena_exca_067[976] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x33AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33AC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33B9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33DF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x33E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x33F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x33F9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x33FA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 255, 0, 0, 0, 0, 0, 0x33FA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 71 entries */
const u16* const elena_saca[72] = {
    elena_saca_000,  /* 0 UP P GUARD P S */
    elena_saca_001,  /* 1 UP P GUARD P M */
    elena_saca_002,  /* 2 UP P GUARD P L */
    elena_saca_002,  /* 3 UP P GUARD K S */
    elena_saca_002,  /* 4 UP P GUARD K M */
    elena_saca_002,  /* 5 UP P GUARD K L */
    elena_saca_002,  /* 6 D P GUARD P S */
    elena_saca_002,  /* 7 D P GUARD P M */
    elena_saca_002,  /* 8 D P GUARD P L */
    elena_saca_002,  /* 9 D P GUARD K S */
    elena_saca_002,  /* 10 D P GUARD K M */
    elena_saca_002,  /* 11 D P GUARD K L */
    elena_saca_002,  /* 12 FUSHIN P S */
    elena_saca_002,  /* 13 FUSHIN P M */
    elena_saca_002,  /* 14 FUSHIN P L */
    elena_saca_002,  /* 15 FUSHIN K S */
    elena_saca_002,  /* 16 FUSHIN K M */
    elena_saca_002,  /* 17 FUSHIN K L */
    elena_saca_002,  /* 18 OKIAGARI P S */
    elena_saca_002,  /* 19 OKIAGARI P M */
    elena_saca_002,  /* 20 OKIAGARI P L */
    elena_saca_002,  /* 21 OKIAGARI K S */
    elena_saca_002,  /* 22 OKIAGARI K M */
    elena_saca_002,  /* 23 OKIAGARI K L */
    elena_saca_024,  /* 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    elena_saca_025,  /* 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    elena_saca_026,  /* 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    elena_saca_027,  /* 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    elena_saca_028,  /* 28 ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    elena_saca_029,  /* 29 ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) */
    elena_saca_030,  /* 30 ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    elena_saca_031,  /* 31 ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    elena_saca_032,  /* 32 ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU) */
    elena_saca_033,  /* 33 ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU) */
    elena_saca_034,  /* 34 ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
    elena_saca_035,  /* 35 ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
    elena_saca_036,  /* 36 ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_036,  /* 37 ATTACK 4 M: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_036,  /* 38 ATTACK 4 L: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_040,  /* 40 ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_040,  /* 41 ATTACK 5 M: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_040,  /* 42 ATTACK 5 L: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_040,  /* 43 ATTACK 5 SP: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_044,  /* 44 ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_044,  /* 45 ATTACK 6 M: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_046,  /* 46 ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_047,  /* 47 ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    elena_saca_048,  /* 48 ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    elena_saca_049,  /* 49 ATTACK 7 M: not started by a command */
    elena_saca_050,  /* 50 ATTACK 7 L: not started by a command */
    elena_saca_050,  /* 51 ATTACK 7 SP: not started by a command */
    elena_saca_050,  /* 52 ATTACK 8 S: not started by a command */
    elena_saca_050,  /* 53 ATTACK 8 M: not started by a command */
    elena_saca_054,  /* 54 ATTACK 8 L: not started by a command */
    elena_saca_054,  /* 55 ATTACK 8 SP: not started by a command */
    elena_saca_054,  /* 56 ATTACK 9 S: not started by a command */
    elena_saca_057,  /* 57 ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
    elena_saca_058,  /* 58 ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
    elena_saca_059,  /* 59 ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) */
    elena_saca_060,  /* 60 ATTACK 10 S: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    elena_saca_061,  /* 61 ATTACK 10 M: after 214+K (routine Att_SLIDE_and_JUMP) */
    elena_saca_062,  /* 62 ATTACK 10 L: after 214+K (routine Att_SLIDE_and_JUMP) */
    elena_saca_063,  /* 63 ATTACK 10 SP: after 214+K (routine Att_SLIDE_and_JUMP) */
    elena_saca_064,  /* 64 ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    elena_saca_065,  /* 65 ATTACK 11 M: 421+K light (plain script) */
    elena_saca_066,  /* 66 ATTACK 11 L: 421+K medium (plain script) */
    elena_saca_067,  /* 67 ATTACK 11 SP: 421+K heavy (plain script) */
    elena_saca_068,  /* 68 ATTACK 12 S: EX 421+KK (plain script) */
    elena_saca_069,  /* 69 ATTACK 12 M: not started by a command */
    elena_saca_070,  /* 70 ATTACK 12 L: not started by a command */
    0
};

/* script: 0 UP P GUARD P S */
const u16 elena_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 elena_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CC, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CD, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CE, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CF, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D0, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70D2, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -3840, 6144), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 14, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M */
const u16 elena_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 elena_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70D2, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70D1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70D1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CE, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CD, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70CA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70C8, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 elena_saca_002_head[4] = { HEAD(6, 0, 0, 11, 0, 7, 0) };
const u16 elena_saca_002[12] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3001, 0, 149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
const u16 elena_saca_024_head[4] = { HEAD(4, 0, 9, 12, 0, 1, 17) };
const u16 elena_saca_024[140] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B1, 0, 246, 0, 0, 0, 32, 83),
    L4(2, 0, 679, 0, 0, 0, 0, 0x32B2, 0, 246, 0, 0, 0, 32, 84),
    CMD(CM_EXEC, 1, 82, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B3, 0, 247, 0, 0, 0, 32, 85),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32B4, -27, 248, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x32B4, 0, 248, 0, 0, 0, 1, 46),
    L4(5, 30, 0, 0, 0, 0, 0, 0x32B5, 0, 181, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B6, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B7, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B8, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B9, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BA, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BB, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BC, 0, 184, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x32BD, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
const u16 elena_saca_025_head[4] = { HEAD(4, 0, 11, 12, 0, 2, 17) };
const u16 elena_saca_025[140] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B1, 0, 178, 0, 0, 0, 32, 83),
    L4(2, 0, 679, 0, 0, 0, 0, 0x32B2, 0, 178, 0, 0, 0, 32, 84),
    CMD(CM_EXEC, 1, 83, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x32B3, -28, 179, 0, 0, 64, 32, 85),
    L4(2, 20, 0, 0, 0, 0, 0, 0x32B3, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x32B4, -29, 180, 0, 0, 0, 1, 53),
    L4(5, 30, 0, 0, 0, 0, 0, 0x32B5, 0, 181, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B6, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B7, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B8, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B9, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BA, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BB, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BC, 0, 184, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x32BD, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
const u16 elena_saca_026_head[4] = { HEAD(4, 0, 13, 13, 0, 3, 17) };
const u16 elena_saca_026[148] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B1, 0, 249, 0, 0, 0, 32, 83),
    L4(1, 0, 679, 0, 0, 0, 0, 0x32B2, 0, 249, 0, 0, 0, 32, 84),
    CMD(CM_EXEC, 1, 84, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x32B2, -69, 250, 0, 0, 64, 32, 85),
    L4(1, 0, 0, 0, 0, 0, 0, 0x32B2, 0, 250, 0, 0, 64, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x32B3, -30, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B4, -31, 252, 0, 0, 0, 1, 55),
    L4(6, 30, 0, 0, 0, 0, 0, 0x32B5, 0, 181, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B6, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B7, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B8, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B9, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BA, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BB, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BC, 0, 184, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x32BD, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
const u16 elena_saca_027_head[4] = { HEAD(4, 0, 15, 12, 0, 4, 17) };
const u16 elena_saca_027[156] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 67, 1), 0, 0, 0, 0,
    L4(1, 0, 679, 0, 0, 0, 0, 0x303A, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B2, -87, 297, 0, 0, 64, 32, 48),
    CMD(CM_ASXY, 98, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B3, -88, 298, 0, 0, 64, 1, 84),
    L4(2, 20, 0, 0, 0, 0, 0, 0x32B4, -89, 299, 0, 0, 0, 1, 55),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B5, -90, 300, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32B5, 0, 301, 0, 0, 0, 0, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x32B6, 0, 182, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B7, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B8, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32B9, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BA, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x32BB, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x32BC, 0, 184, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x32BD, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
const u16 elena_saca_028_head[4] = { HEAD(6, 0, 9, 16, 0, 2, 18) };
const u16 elena_saca_028[448] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x333A, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333B, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333D, 0, 190, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333E, 0, 191, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3340, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3341, 0, 192, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3342, 0, 192, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3343, 0, 193, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3344, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 687, 0, 0, 0, 0, 0x3345, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3346, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3347, -32, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3348, 33, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3349, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x334A, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x334B, -35, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334C, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334D, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334F, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3350, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3351, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3351, -36, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3352, 0, 203, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) */
const u16 elena_saca_029_head[4] = { HEAD(6, 0, 11, 16, 0, 2, 18) };
const u16 elena_saca_029[436] = {
    CMD(CM_JSR, 8, 47, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3336, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3337, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3338, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3339, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333A, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333B, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333D, 0, 190, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333E, 0, 191, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3340, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3341, 0, 192, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3342, 0, 192, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3343, 0, 193, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3344, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 687, 0, 0, 0, 0, 0x3345, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3346, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3347, -32, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3348, 33, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3349, 34, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x334A, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x334B, -35, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334C, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334D, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334F, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3350, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3351, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3351, -37, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3352, 0, 203, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
const u16 elena_saca_030_head[4] = { HEAD(6, 0, 13, 16, 0, 2, 18) };
const u16 elena_saca_030[436] = {
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3333, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3334, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3335, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3336, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3337, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3338, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3339, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333A, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333B, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333D, 0, 190, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333E, 0, 191, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3340, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3341, 0, 192, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3342, 0, 192, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3343, 0, 193, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3344, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 687, 0, 0, 0, 0, 0x3345, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3346, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3347, -32, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3348, 33, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3349, 34, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x334A, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x334B, -35, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334C, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334D, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334F, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3350, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3351, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3351, -38, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3352, 0, 203, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
const u16 elena_saca_031_head[4] = { HEAD(6, 0, 15, 16, 0, 3, 18) };
const u16 elena_saca_031[424] = {
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 68, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3337, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3339, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333A, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x333B, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x333D, 0, 190, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x333F, 0, 191, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3342, 0, 192, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3343, 0, 193, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 687, 0, 0, 0, 0, 0x3345, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3346, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3347, -99, 308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3348, 100, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3349, 101, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x334A, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x334B, -102, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334C, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334D, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x334F, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3350, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 270, 0, 0, 0, 0, 0x3351, -93, 312, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3352, -94, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3353, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU) */
const u16 elena_saca_032_head[4] = { HEAD(4, 0, 9, 15, 0, 2, 19) };
const u16 elena_saca_032[116] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3166, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3167, 0, 116, 0, 0, 0, 1, 71),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3168, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 686, 0, 0, 0, 0, 0x3169, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x316A, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x316B, 0, 118, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x316C, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316D, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316E, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x316F, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3170, 0, 120, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3171, 0, 121, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU) */
const u16 elena_saca_033_head[4] = { HEAD(4, 0, 11, 15, 0, 2, 19) };
const u16 elena_saca_033[116] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3166, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3167, 0, 116, 0, 0, 0, 1, 71),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3168, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 686, 0, 0, 0, 0, 0x3169, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x316A, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316B, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316C, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316D, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316E, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x316F, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3170, 0, 120, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3171, 0, 121, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
const u16 elena_saca_034_head[4] = { HEAD(4, 0, 13, 15, 0, 2, 19) };
const u16 elena_saca_034[116] = {
    CMD(CM_JSR, 8, 43, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3166, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3167, 0, 116, 0, 0, 0, 1, 72),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3168, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 686, 0, 0, 0, 0, 0x3169, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x316A, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316B, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316C, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316D, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316E, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x316F, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3170, 0, 120, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3171, 0, 121, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
const u16 elena_saca_035_head[4] = { HEAD(4, 0, 15, 15, 0, 2, 19) };
const u16 elena_saca_035[124] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 69, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3166, 0, 303, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3167, 0, 303, 0, 0, 0, 1, 72),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3168, 0, 303, 0, 0, 0, 0, 0),
    L4(2, 0, 686, 0, 0, 0, 0, 0x3169, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x316A, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x316B, 0, 118, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x316C, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316D, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x316E, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x316F, 0, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3170, 0, 120, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3171, 0, 121, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), 37 ATTACK 4 M: SA I 23623+K (routine Att_SHOURYUUREPPA), 38 ATTACK 4 L: SA I 23623+K (routine Att_SHOURYUUREPPA), 39 ATTACK 4 SP: SA I 23623+K (routine Att_SHOURYUUREPPA) */
const u16 elena_saca_036_head[4] = { HEAD(6, 0, 33, 13, 0, 7, 14) };
const u16 elena_saca_036[688] = {
    CMD(CM_JSR, 8, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x303A, 0, 63, 0, 0, 0, 13, 25, 771, 0, 0, 0, 0),
    L6(48, 0, 0, 0, 0, 0, 0, 0x303B, 0, 63, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 36, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 682, 0, 1, 0, 0, 0x3166, 0, 63, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3167, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3168, -70, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3169, 0, 305, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 1, 0, 0, 0x316A, -50, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316B, 0, 307, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316C, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316D, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316E, 0, 213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316F, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3170, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 1, 0, 0, 0x3171, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3172, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3173, 0, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3174, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3175, 0, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3176, 0, 221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3177, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3178, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 36, 37), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 683, 0, 1, 0, 0, 0x3166, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3167, -70, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3168, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3169, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 1, 0, 0, 0x316A, -50, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316B, 0, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316C, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316D, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316E, 0, 213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x316F, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3170, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 1, 0, 0, 0x3171, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3172, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3173, 0, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3174, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x3175, 0, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x303A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 679, 0, 0, 0, 0, 0x303B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 270, 0, 0, 0, 0, 0x32B2, -51, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32B3, 0, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32B4, -52, 175, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x32B5, -52, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32B6, 0, 182, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32B7, 0, 183, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32B8, 0, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32B9, 0, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32BA, 0, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32BB, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32BC, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x32BD, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA), 41 ATTACK 5 M: SA II 23623+K (routine Att_SHOURYUUREPPA), 42 ATTACK 5 L: SA II 23623+K (routine Att_SHOURYUUREPPA), 43 ATTACK 5 SP: SA II 23623+K (routine Att_SHOURYUUREPPA) */
const u16 elena_saca_040_head[4] = { HEAD(6, 0, 33, 10, 0, 10, 15) };
const u16 elena_saca_040[340] = {
    CMD(CM_JSR, 8, 51, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(43, 0, 698, 0, 0, 0, 0, 0x303A, 0, 63, 0, 0, 0, 13, 26, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x303B, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3061, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 277, 0, 0, 0, 0, 0x310C, 0, 59, 0, 0, 0, 1, 41, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 71, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 0, 0, 0x310C, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 148),
    L6(1, 0, 268, 0, 0, 0, 0, 0x310D, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x310D, -39, 227, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 54, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 60, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x310E, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310D, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x310C, 0, 44, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3094, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 0, 0, 0x3063, 0, 10, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(3, 0, 676, 0, 0, 0, 0, 0x3154, 0, 103, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x3155, 0, 103, 0, 0, 0, 0, 0, 776, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3156, -40, 104, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3100, 0, 97, 0, 0, 0, 0, 0, 776, 0, 82, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3101, 0, 97, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3102, 0, 97, 0, 0, 0, 0, 0, 776, 0, 10, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3103, 0, 97, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x3104, -97, 225, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), 45 ATTACK 6 M: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
const u16 elena_saca_044_head[4] = { HEAD(6, 0, 33, 14, 0, 10, 0) };
const u16 elena_saca_044[736] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3159, 0, 126, 0, 0, 0, 0, 0, 776, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315A, 0, 127, 0, 0, 0, 0, 0, 776, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315B, 0, 127, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315C, 0, 128, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x315D, 0, 128, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x315E, 0, 128, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 678, 0, 0, 0, 0, 0x315F, -41, 129, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x309E, 0, 75, 0, 0, 0, 0, 0, 776, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x309F, 0, 75, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A0, 0, 76, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A1, 0, 76, 0, 0, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A2, 0, 76, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x30A3, 0, 77, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30A4, 0, 77, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(2, 0, 676, 0, 0, 0, 0, 0x30A5, -42, 79, 0, 0, 0, 0, 0, 776, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3136, 0, 71, 0, 0, 0, 0, 0, 776, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3137, 0, 71, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3138, 0, 71, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3139, 0, 72, 0, 0, 0, 0, 0, 776, 0, 36, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x313A, -44, 73, 0, 0, 0, 0, 0, 776, 0, 38, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E6, 0, 33, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3305, 0, 141, 0, 0, 0, 0, 0, 776, 0, 90, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3306, 0, 142, 0, 0, 0, 0, 0, 776, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3307, 0, 142, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3308, 0, 142, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(2, 0, 678, 0, 0, 0, 0, 0x3309, -45, 143, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32D6, 0, 32, 0, 0, 0, 0, 0, 776, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D7, 0, 32, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D8, 0, 33, 0, 0, 0, 0, 0, 776, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D9, 0, 34, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x32DA, 0, 34, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DB, 0, 35, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 676, 0, 0, 0, 0, 0x32DC, -46, 36, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E0, 0, 38, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30EF, 0, 89, 0, 0, 0, 0, 0, 776, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F0, 0, 89, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F1, 0, 90, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F2, 0, 90, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F3, 0, 90, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F4, 0, 91, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x30F5, 0, 91, 0, 0, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x30F6, -47, 92, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30F9, 0, 243, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x30FB, 0, 91, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30D9, 0, 83, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DA, 0, 83, 0, 0, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DB, 0, 83, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DC, 0, 83, 0, 0, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DD, 0, 85, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DE, 0, 85, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30DF, 0, 85, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30E1, 0, 85, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x30E2, 0, 85, 0, 0, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x30E3, 0, 85, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 679, 1, 0, 0, 0, 0x30E4, -67, 261, 0, 128, 0, 0, 0, 776, 0, 8, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x30E5, 0, 87, 0, 0, 0, 0, 0, 776, 0, 12, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 47, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
const u16 elena_saca_046_head[4] = { HEAD(6, 0, 0, 14, 0, 0, 0) };
const u16 elena_saca_046[148] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E5, 0, 239, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E6, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30E7, 0, 240, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E8, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E9, 0, 84, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EA, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EB, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30EC, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30ED, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x30EE, 0, 160, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3022, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 36), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
const u16 elena_saca_047_head[4] = { HEAD(6, 0, 0, 14, 0, 0, 0) };
const u16 elena_saca_047[148] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E5, 0, 239, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x30E6, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30E7, 0, 240, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30E8, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30E9, 0, 84, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30EA, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30EB, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30EC, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30ED, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x30EE, 0, 160, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3022, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 36, 36), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
const u16 elena_saca_048_head[4] = { HEAD(6, 32, 48, 0, 0, 0, 16) };
const u16 elena_saca_048[1072] = {
    CMD(CM_JSR, 8, 52, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 338, 0, 0, 0, 0, 0x303A, 0, 63, 0, 0, 0, 13, 22, 780, 0, 0, 0, 0),
    L6(15, 0, 0, 0, 0, 0, 0, 0x303B, 0, 63, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3234, 0, 63, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3235, 0, 63, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3236, 0, 63, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 2, 0, 0x3237, 0, 63, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2, 0, 0x3238, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 2, 0, 0x3239, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x323A, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 3, 0, 0x323B, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x323C, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 4, 0, 0x323D, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 4, 0, 0x323E, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 4, 0, 0x323F, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 5, 0, 0x3240, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 5, 0, 0x3241, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 5, 0, 0x3242, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 6, 0, 0x3243, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 6, 0, 0x3244, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 6, 0, 0x3245, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 7, 0, 0x3246, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 7, 0, 0x3247, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 7, 0, 0x3248, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 684, 0, 0, 8, 0, 0x3249, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 8, 0, 0x324A, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 8, 0, 0x324B, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x324C, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 9, 0, 0x324D, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x324E, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 10, 0, 0x324F, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 10, 0, 0x3250, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 10, 0, 0x3251, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 11, 0, 0x3252, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 11, 0, 0x3253, 0, 63, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 11, 0, 0x3254, 0, 63, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 12, 0, 0x3255, 0, 63, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 12, 0, 0x3256, 0, 63, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 12, 0, 0x3257, 0, 63, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 13, 0, 0x3258, 0, 63, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 13, 0, 0x3259, 0, 63, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 13, 0, 0x325A, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 14, 0, 0x325B, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x325C, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 14, 0, 0x325D, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 15, 0, 0x325E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 15, 0, 0x325E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x325E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 15, 0, 0x325E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x325E, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 16, 0, 0x325F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 16, 0, 0x325F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 16, 0, 0x325F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 16, 0, 0x325F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 16, 0, 0x325F, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3260, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3260, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3260, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3260, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3260, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3261, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3261, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3261, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3261, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3261, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3262, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3262, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3262, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3262, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3262, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3263, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3263, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3263, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3263, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3263, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 0, 0x3264, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3265, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 1, 0, 0, 0x3313, 0, 237, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(6, 0, 0, 0, 1, 0, 0, 0x3314, 0, 237, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 64, 0, 0, 0, 0, 0, 0x33F6, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: not started by a command */
const u16 elena_saca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 elena_saca_049[292] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x303A, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303B, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x3317, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3318, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3319, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331A, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331B, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331C, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331D, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331E, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x331F, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3320, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3321, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3322, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3323, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3324, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3325, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3326, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3327, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3328, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3329, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332A, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332B, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332C, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332D, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332E, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x332F, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3330, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3331, 0, 13, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x3332, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x303F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3040, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: not started by a command, 51 ATTACK 7 SP: not started by a command, 52 ATTACK 8 S: not started by a command, 53 ATTACK 8 M: not started by a command */
const u16 elena_saca_050_head[4] = { HEAD(4, 0, 1, 8, 0, 1, 33) };
const u16 elena_saca_050[60] = {
    CMD(CM_JSR, 8, 53, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3054, 0, 254, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x3112, 0, 47, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x310C, 0, 44, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x310D, -71, 260, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x310E, 0, 260, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command */
const u16 elena_saca_054_head[4] = { HEAD(6, 0, 0, 13, 0, 2, 0) };
const u16 elena_saca_054[544] = {
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3452, 0, 1, 0, 0, 0, 21, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3453, 0, 1, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3454, 0, 1, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3455, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3456, 0, 1, 0, 0, 0, 33, 0, 0, 0, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3457, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3458, -85, 294, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3459, 0, 1, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x345A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x345B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x345C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x345D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(4, 40, 0, 0, 0, 0, 0, 0x345E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x345F, -86, 295, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3460, 0, 1, 0, 0, 0, 21, 0, 0, 0, 194, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3461, 0, 1, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(4, 0, 2048, 0, 0, 0, 0, 0x3462, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3463, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3464, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3465, 0, 1, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3466, 0, 1, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3467, 0, 1, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3468, 0, 1, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3469, 0, 1, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x346A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x346B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x346C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x346D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x346E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x346F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3470, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    CMD(CM_IF_L, 2, 16390, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3471, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3472, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x303C, 0, 3, 0, 0, 0, 22, 32, 0, 0, 194, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x303D, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x303E, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_057_head[4] = { HEAD(6, 0, 9, 19, 0, 4, 71) };
const u16 elena_saca_057[760] = {
    CMD(CM_RJA, 5, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 685, 0, 0, 0, 0, 0x33FD, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FE, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FF, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3400, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3401, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 0, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -73, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340F, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 136, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -74, 463, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 66, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3412, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3413, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x3414, 0, 280, 0, 0, 0, 30, 48, 0, 0, 0, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x3415, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3416, -75, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3417, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3418, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 678, 0, 0, 0, 0, 0x3419, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x341A, -76, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341B, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341C, 0, 286, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341D, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x341F, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3420, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3421, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3422, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3423, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3424, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3425, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3426, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3427, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3428, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_058_head[4] = { HEAD(6, 0, 11, 19, 0, 4, 71) };
const u16 elena_saca_058[760] = {
    CMD(CM_RJA, 5, 62, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 685, 0, 0, 0, 0, 0x33FD, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FE, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FF, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3400, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3401, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 0, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -77, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340F, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 136, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -78, 463, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 69, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3412, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3413, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x3414, 0, 280, 0, 0, 0, 30, 48, 0, 0, 0, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x3415, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3416, -79, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3417, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3418, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 678, 0, 0, 0, 0, 0x3419, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x341A, -80, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341B, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341C, 0, 286, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341D, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x341F, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3420, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3421, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3422, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3423, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3424, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3425, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3426, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3427, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3428, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_059_head[4] = { HEAD(6, 0, 13, 19, 0, 4, 71) };
const u16 elena_saca_059[760] = {
    CMD(CM_RJA, 5, 63, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 685, 0, 0, 0, 0, 0x33FD, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FE, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FF, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3400, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3401, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 0, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -81, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340F, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 136, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -82, 463, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 72, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3412, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3413, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x3414, 0, 280, 0, 0, 0, 30, 48, 0, 0, 0, 0, 0),
    L6(2, 0, 677, 0, 0, 0, 0, 0x3415, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3416, -83, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3417, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3418, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 678, 0, 0, 0, 0, 0x3419, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x341A, -84, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341B, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341C, 0, 286, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341D, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x341F, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3420, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3421, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3422, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3423, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3424, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3425, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3426, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3427, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3428, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: EX 214+KK (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_060_head[4] = { HEAD(6, 0, 15, 17, 0, 4, 71) };
const u16 elena_saca_060[580] = {
    CMD(CM_RJA, 5, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 70, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 685, 0, 0, 0, 0, 0x33FD, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FE, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FF, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3400, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3401, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 0, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -95, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 136, 30, 47, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -95, 463, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 136, 30, 47, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 677, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3407, -95, 463, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: after 214+K (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_061_head[4] = { HEAD(6, 0, 9, 12, 0, 0, 71) };
const u16 elena_saca_061[76] = {
    CMD(CM_RJA, 5, 61, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3450, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3451, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 0, 0, 0x3451, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: after 214+K (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_062_head[4] = { HEAD(6, 0, 11, 12, 0, 0, 71) };
const u16 elena_saca_062[76] = {
    CMD(CM_RJA, 5, 62, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x3450, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3451, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 0, 0, 0x3451, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: after 214+K (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_063_head[4] = { HEAD(6, 0, 13, 12, 0, 0, 71) };
const u16 elena_saca_063[76] = {
    CMD(CM_RJA, 5, 63, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x3450, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3451, 0, 274, 7936, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 0, 0, 0x3451, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
const u16 elena_saca_064_head[4] = { HEAD(6, 0, 15, 9, 0, 1, 71) };
const u16 elena_saca_064[424] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32D9, 0, 34, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 1, 270, 0, 0, 0, 0, 0x32DA, 0, 35, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DC, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DC, -96, 36, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16399, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DE, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32DF, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32E0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32E1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E2, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E4, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32E5, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x32E6, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DD, 0, 37, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32DE, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32DF, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E2, 0, 35, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E3, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E4, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E5, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x32E6, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x32E7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x32E8, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: 421+K light (plain script) */
const u16 elena_saca_065_head[4] = { HEAD(4, 0, 9, 17, 0, 4, 71) };
const u16 elena_saca_065[220] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3570, 0, 347, 0, 0, 0, 32, 151),
    L4(4, 0, 678, 0, 0, 0, 0, 0x3571, 0, 348, 0, 0, 0, 32, 152),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 153),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3573, -103, 350, 0, 134, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3573, 0, 389, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3577, -104, 354, 0, 139, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3577, 0, 391, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3557, 0, 361, 0, 0, 0, 32, 121),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3558, 0, 362, 0, 0, 0, 32, 122),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3559, 0, 363, 0, 0, 0, 32, 123),
    L4(3, 0, 0, 0, 0, 0, 0, 0x355A, 0, 364, 0, 0, 0, 32, 124),
    L4(3, 64, 0, 0, 0, 0, 0, 0x355B, 0, 365, 0, 0, 0, 32, 125),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 83), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: 421+K medium (plain script) */
const u16 elena_saca_066_head[4] = { HEAD(4, 0, 11, 17, 0, 4, 71) };
const u16 elena_saca_066[220] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x3570, 0, 347, 0, 0, 0, 32, 173),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3571, 0, 348, 0, 0, 0, 32, 152),
    L4(2, 0, 678, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 153),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3573, -105, 350, 0, 134, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3573, 0, 389, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3577, -106, 354, 0, 139, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3577, 0, 391, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3557, 0, 361, 0, 0, 0, 32, 121),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3558, 0, 362, 0, 0, 0, 32, 122),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3559, 0, 363, 0, 0, 0, 32, 123),
    L4(3, 0, 0, 0, 0, 0, 0, 0x355A, 0, 364, 0, 0, 0, 32, 124),
    L4(3, 64, 0, 0, 0, 0, 0, 0x355B, 0, 365, 0, 0, 0, 32, 125),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 83), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: 421+K heavy (plain script) */
const u16 elena_saca_067_head[4] = { HEAD(4, 0, 13, 17, 0, 4, 71) };
const u16 elena_saca_067[340] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x3570, 0, 347, 0, 0, 0, 32, 174),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3571, 0, 348, 0, 0, 0, 32, 152),
    L4(3, 0, 678, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 153),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3573, -107, 350, 0, 134, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3573, 0, 389, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3577, -108, 354, 0, 139, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3577, 0, 391, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x358D, 0, 373, 0, 0, 0, 32, 165),
    L4(2, 0, 677, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 166),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3573, -108, 350, 0, 149, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3573, 0, 389, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3577, -109, 354, 0, 154, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3577, 0, 391, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3557, 0, 361, 0, 0, 0, 32, 121),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3558, 0, 362, 0, 0, 0, 32, 122),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3559, 0, 363, 0, 0, 0, 32, 123),
    L4(3, 0, 0, 0, 0, 0, 0, 0x355A, 0, 364, 0, 0, 0, 32, 124),
    L4(3, 64, 0, 0, 0, 0, 0, 0x355B, 0, 365, 0, 0, 0, 32, 125),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 83), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: EX 421+KK (plain script) */
const u16 elena_saca_068_head[4] = { HEAD(4, 0, 15, 17, 0, 4, 71) };
const u16 elena_saca_068[396] = {
    CMD(CM_JSR, 8, 72, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3570, 0, 347, 0, 0, 0, 32, 175),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3571, 0, 348, 0, 0, 0, 32, 152),
    L4(2, 0, 677, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 153),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3573, -110, 350, 0, 128, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 351, 0, 0, 0, 32, 155),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3577, -111, 354, 0, 128, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 355, 0, 0, 0, 32, 159),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(2, 0, 0, 0, 0, 0, 0, 0x358D, 0, 373, 0, 0, 0, 32, 165),
    L4(2, 0, 677, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 166),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3573, -111, 350, 0, 128, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 351, 0, 0, 0, 32, 155),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3577, -111, 354, 0, 128, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 355, 0, 0, 0, 32, 159),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(2, 0, 680, 0, 0, 0, 0, 0x357E, 0, 374, 0, 0, 0, 32, 126),
    L4(2, 0, 0, 0, 0, 0, 0, 0x357F, 0, 375, 0, 0, 0, 32, 127),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3580, 0, 376, 0, 0, 0, 32, 128),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3581, 0, 377, 0, 0, 0, 32, 129),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3582, -112, 378, 0, 0, 0, 32, 130),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3583, 0, 379, 0, 0, 0, 32, 131),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3584, 0, 380, 0, 0, 0, 32, 132),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3585, 0, 381, 0, 0, 0, 32, 133),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3586, 0, 382, 0, 0, 0, 32, 134),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3587, 0, 383, 0, 0, 0, 32, 135),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3588, 0, 384, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3589, 0, 385, 0, 0, 0, 32, 137),
    L4(3, 0, 0, 0, 0, 0, 0, 0x358A, 0, 386, 0, 0, 0, 32, 138),
    L4(3, 0, 0, 0, 0, 0, 0, 0x358B, 0, 387, 0, 0, 0, 32, 139),
    L4(3, 64, 0, 0, 0, 0, 0, 0x358C, 0, 388, 0, 0, 0, 32, 140),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 46), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 68), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: not started by a command */
const u16 elena_saca_069_head[4] = { HEAD(4, 0, 13, 19, 0, 4, 71) };
const u16 elena_saca_069[300] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3570, 0, 347, 0, 0, 0, 32, 151),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3571, 0, 348, 0, 0, 0, 32, 152),
    L4(2, 0, 678, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 153),
    L4(3, 0, 270, 0, 0, 0, 0, 0x3573, -107, 350, 0, 134, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(3, 0, 270, 0, 0, 0, 0, 0x3577, -108, 354, 0, 139, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x358D, 0, 373, 0, 0, 0, 32, 165),
    L4(2, 0, 677, 0, 0, 0, 0, 0x3572, 0, 349, 0, 0, 0, 32, 166),
    L4(3, 0, 270, 0, 0, 0, 0, 0x3573, -108, 350, 0, 149, 0, 32, 154),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3574, 0, 390, 0, 0, 0, 32, 155),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3575, 0, 352, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3576, 0, 353, 0, 0, 0, 32, 157),
    L4(3, 0, 270, 0, 0, 0, 0, 0x3577, -109, 354, 0, 154, 0, 32, 158),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3578, 0, 392, 0, 0, 0, 32, 159),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3579, 0, 356, 0, 0, 0, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x357A, 0, 357, 0, 0, 0, 32, 161),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357B, 0, 358, 0, 0, 0, 32, 162),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357C, 0, 359, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x357D, 0, 360, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3557, 0, 361, 0, 0, 0, 32, 167),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3558, 0, 362, 0, 0, 0, 32, 168),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3559, 0, 363, 0, 0, 0, 32, 159),
    L4(3, 0, 0, 0, 0, 0, 0, 0x355A, 0, 364, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x355B, 0, 365, 0, 0, 0, 32, 169),
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_WSET, 16385, 0, 10), 0, 0, 0, 0,
    CMD(CM_WCNE, 16399, 0, 16386), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 36, 56), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 33, 83), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: not started by a command */
const u16 elena_saca_070_head[4] = { HEAD(6, 0, 15, 12, 0, 0, 0) };
const u16 elena_saca_070[736] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FD, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FE, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x33FF, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3400, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3401, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 0, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x3406, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3407, -81, 463, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340F, 0, 274, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3410, 0, 275, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3411, 0, 265, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3402, 0, 266, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3403, 0, 267, 7936, 0, 0, 30, 47, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3404, 0, 268, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3405, 0, 268, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x3406, 0, 268, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3407, -82, 463, 7936, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3408, 0, 464, 7936, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3409, 0, 270, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x340A, 0, 271, 7936, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340B, 0, 272, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340C, 0, 273, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340D, 0, 274, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x340E, 0, 274, 7936, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 72, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x3412, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3413, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x3414, 0, 280, 0, 0, 0, 30, 48, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3415, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3416, -83, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3417, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3418, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3419, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341A, -84, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341B, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341C, 0, 286, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341D, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x341E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x341F, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3420, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3421, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3422, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3423, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3424, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3425, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3426, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3427, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3428, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3429, 0, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 73 entries */
const u16* const elena_cbca[74] = {
    elena_cbca_000,  /* 0 APPEAR JUNBI 1 */
    elena_cbca_001,  /* 1 APPEAR JUNBI 2 */
    elena_cbca_002,  /* 2 APPEAR JUNBI 3 */
    elena_cbca_003,  /* 3 APPEAR JUNBI 4 */
    elena_cbca_004,  /* 4 APPEAR JUNBI 5 */
    elena_cbca_005,  /* 5 APPEAR JUNBI 6 */
    elena_cbca_006,  /* 6 APPEAR JUNBI 7 */
    elena_cbca_007,  /* 7 APPEAR JUNBI 8 */
    elena_cbca_008,  /* 8 APPEAR 1 */
    elena_cbca_009,  /* 9 APPEAR 2 */
    elena_cbca_010,  /* 10 APPEAR 3 */
    elena_cbca_011,  /* 11 APPEAR 4 */
    elena_cbca_012,  /* 12 APPEAR 5 */
    elena_cbca_013,  /* 13 APPEAR 6 */
    elena_cbca_014,  /* 14 APPEAR 7 */
    elena_cbca_015,  /* 15 APPEAR 8 */
    elena_cbca_016,  /* 16 SP APPEAR 1 */
    elena_cbca_017,  /* 17 SP APPEAR 2 */
    elena_cbca_018,  /* 18 SP APPEAR 3 */
    elena_cbca_019,  /* 19 SP APPEAR 4 */
    elena_cbca_020,  /* 20 SP APPEAR 5 */
    elena_cbca_021,  /* 21 SP APPEAR 6 */
    elena_cbca_022,  /* 22 SP APPEAR 7 */
    elena_cbca_023,  /* 23 SP APPEAR 8 */
    elena_cbca_024,  /* 24 ZANNEN 1 */
    elena_cbca_025,  /* 25 ZANNEN 2 */
    elena_cbca_026,  /* 26 ZANNEN 3 */
    elena_cbca_027,  /* 27 ZANNEN 4 */
    elena_cbca_028,  /* 28 ZANNEN 5 */
    elena_cbca_029,  /* 29 ZANNEN 6 */
    elena_cbca_030,  /* 30 ZANNEN 7 */
    elena_cbca_031,  /* 31 ZANNEN 8 */
    elena_cbca_032,  /* 32 WIN 1 */
    elena_cbca_033,  /* 33 WIN 2 */
    elena_cbca_034,  /* 34 WIN 3 */
    elena_cbca_035,  /* 35 WIN 4 */
    elena_cbca_036,  /* 36 WIN 5 */
    elena_cbca_037,  /* 37 WIN 6 */
    elena_cbca_038,  /* 38 WIN 7 */
    elena_cbca_039,  /* 39 WIN 8 */
    elena_cbca_040,  /* 40 SP WIN 1 */
    elena_cbca_041,  /* 41 SP WIN 2 */
    elena_cbca_042,  /* 42 SP WIN 3 */
    elena_cbca_043,  /* 43 SP WIN 4 */
    elena_cbca_044,  /* 44 SP WIN 5 */
    elena_cbca_045,  /* 45 SP WIN 6 */
    elena_cbca_046,  /* 46 SP WIN 7 */
    elena_cbca_047,  /* 47 SP WIN 8 */
    elena_cbca_048,  /* 48 JUDGMENT WAIT */
    elena_cbca_049,  /* 49 JUDGMENT WAIT */
    elena_cbca_050,  /* 50 JUDGMENT WAIT */
    elena_cbca_051,  /* 51 JUDGMENT WAIT */
    elena_cbca_052,  /* 52 JUDGMENT WIN */
    elena_cbca_053,  /* 53 JUDGMENT WIN */
    elena_cbca_054,  /* 54 JUDGMENT WIN */
    elena_cbca_055,  /* 55 JUDGMENT WIN */
    elena_cbca_056,  /* 56 JUDGMENT LOSE */
    elena_cbca_057,  /* 57 JUDGMENT LOSE */
    elena_cbca_058,  /* 58 JUDGMENT LOSE */
    elena_cbca_059,  /* 59 JUDGMENT LOSE */
    elena_cbca_060,  /* 60 WAIT */
    elena_cbca_061,  /* 61 AFRICA JUMP */
    elena_cbca_062,  /* 62 AFRICA LAND */
    elena_cbca_063,  /* 63 SEAN BALL HIT */
    elena_cbca_064,  /* 64 no name */
    elena_cbca_065,  /* 65 BONUS WIN 1 */
    elena_cbca_066,  /* 66 BONUS WIN 2 */
    elena_cbca_067,  /* 67 BONUS WIN 3 */
    elena_cbca_068,  /* 68 APPEAR USE */
    elena_cbca_069,  /* 69 APPEAR USE */
    elena_cbca_070,  /* 70 APPEAR USE */
    elena_cbca_071,  /* 71 APPEAR USE */
    elena_cbca_072,  /* 72 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 elena_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 elena_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 0, 1),
    CMD(CM_RJA3, 7, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 elena_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_002[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 elena_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 5, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 elena_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 3, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 elena_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 20, 1),
    CMD(CM_RJA3, 7, 21, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 elena_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 elena_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_007[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 elena_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_008[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 elena_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_009[12] = {
    CMD(CM_WADD, 16384, 1, 63),
    CMD(CM_WCGT2, 16384, 16385, 8194),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 elena_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_010[8] = {
    CMD(CM_RJA, 0, 36, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 11 APPEAR 4 */
const u16 elena_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_011[8] = {
    CMD(CM_RJA, 0, 36, 5),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 12 APPEAR 5 */
const u16 elena_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_012[8] = {
    CMD(CM_RJA, 0, 36, 7),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 13 APPEAR 6 */
const u16 elena_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_013[8] = {
    CMD(CM_RJA, 0, 36, 9),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 14 APPEAR 7 */
const u16 elena_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_014[8] = {
    CMD(CM_RJA, 0, 36, 11),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 15 APPEAR 8 */
const u16 elena_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_015[8] = {
    CMD(CM_RJA, 0, 36, 13),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 16 SP APPEAR 1 */
const u16 elena_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_016[8] = {
    CMD(CM_RJA, 0, 36, 15),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 17 SP APPEAR 2 */
const u16 elena_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_017[8] = {
    CMD(CM_RJA, 0, 36, 17),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 18 SP APPEAR 3 */
const u16 elena_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_018[8] = {
    CMD(CM_RJA, 0, 36, 19),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 19 SP APPEAR 4 */
const u16 elena_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_019[8] = {
    CMD(CM_RJA, 0, 36, 21),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 20 SP APPEAR 5 */
const u16 elena_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_020[8] = {
    CMD(CM_RJA, 0, 36, 23),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 21 SP APPEAR 6 */
const u16 elena_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_021[8] = {
    CMD(CM_RJA, 0, 36, 25),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 22 SP APPEAR 7 */
const u16 elena_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_022[8] = {
    CMD(CM_RJA, 0, 36, 27),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 23 SP APPEAR 8 */
const u16 elena_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_023[8] = {
    CMD(CM_RJA, 0, 36, 29),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 24 ZANNEN 1 */
const u16 elena_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_024[8] = {
    CMD(CM_RJA, 0, 36, 31),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 25 ZANNEN 2 */
const u16 elena_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_025[8] = {
    CMD(CM_RJA, 0, 36, 33),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 26 ZANNEN 3 */
const u16 elena_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_026[8] = {
    CMD(CM_RJA, 0, 36, 35),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 27 ZANNEN 4 */
const u16 elena_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_027[8] = {
    CMD(CM_RJA, 0, 36, 37),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 28 ZANNEN 5 */
const u16 elena_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_028[8] = {
    CMD(CM_RJA, 0, 36, 39),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 29 ZANNEN 6 */
const u16 elena_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_029[8] = {
    CMD(CM_RJA, 0, 36, 41),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 30 ZANNEN 7 */
const u16 elena_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_030[8] = {
    CMD(CM_RJA, 0, 36, 43),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 31 ZANNEN 8 */
const u16 elena_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_031[8] = {
    CMD(CM_RJA, 0, 36, 45),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 32 WIN 1 */
const u16 elena_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_032[8] = {
    CMD(CM_RJA, 0, 36, 47),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 33 WIN 2 */
const u16 elena_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_033[8] = {
    CMD(CM_RJA, 0, 36, 49),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 34 WIN 3 */
const u16 elena_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_034[8] = {
    CMD(CM_RJA, 0, 36, 51),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 35 WIN 4 */
const u16 elena_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_035[8] = {
    CMD(CM_RJA, 0, 36, 53),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 36 WIN 5 */
const u16 elena_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_036[8] = {
    CMD(CM_RJA, 0, 36, 55),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 37 WIN 6 */
const u16 elena_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_037[8] = {
    CMD(CM_RJA, 0, 36, 57),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 38 WIN 7 */
const u16 elena_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_038[8] = {
    CMD(CM_RJA, 0, 36, 1),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 39 WIN 8 */
const u16 elena_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_039[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 elena_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_040[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 8, 1),
    CMD(CM_RJA3, 7, 9, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 elena_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_041[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 30, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 elena_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_042[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 33, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 elena_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_043[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 elena_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 0, 11, 1),
    CMD(CM_RJA3, 0, 7, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 elena_cbca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_045[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 elena_cbca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_046[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 elena_cbca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_047[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 elena_cbca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_048[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 elena_cbca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_049[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 5, 42, 11),
    CMD(CM_RJA3, 5, 42, 11),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 elena_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_050[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 53, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 elena_cbca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_051[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 53, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN */
const u16 elena_cbca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_052[24] = {
    CMD(CM_RMJA, 5, 48, 84),
    CMD(CM_WSET, 16384, 0, 0),
    CMD(CM_IMGS, 0, 9, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -15, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 53 JUDGMENT WIN */
const u16 elena_cbca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_053[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 6, 1),
    CMD(CM_RJA3, 7, 7, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 54 JUDGMENT WIN */
const u16 elena_cbca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_054[8] = {
    CMD(CM_RJA, 0, 37, 2),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 55 JUDGMENT WIN */
const u16 elena_cbca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_055[8] = {
    CMD(CM_RJA, 0, 37, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 56 JUDGMENT LOSE */
const u16 elena_cbca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_056[8] = {
    CMD(CM_RJA, 0, 37, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 57 JUDGMENT LOSE */
const u16 elena_cbca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_057[8] = {
    CMD(CM_RJA, 0, 37, 5),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 58 JUDGMENT LOSE */
const u16 elena_cbca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_058[8] = {
    CMD(CM_RJA, 0, 37, 6),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 59 JUDGMENT LOSE */
const u16 elena_cbca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_059[8] = {
    CMD(CM_RJA, 0, 37, 1),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 60 WAIT */
const u16 elena_cbca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_060[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 5, 42, 18),
    CMD(CM_RJA3, 5, 42, 18),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 elena_cbca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_061[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 46, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 elena_cbca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_062[4] = {
    CMD(CM_RET, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT */
const u16 elena_cbca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_063[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 64 no name */
const u16 elena_cbca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_064[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 65 BONUS WIN 1 */
const u16 elena_cbca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_065[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 66 BONUS WIN 2 */
const u16 elena_cbca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_066[36] = {
    CMD(CM_CHKWF, 32, 8192, 8206),
    CMD(CM_S_CHG, 256, 16388, 8192),
    CMD(CM_S_CHG, 512, 16389, 8192),
    CMD(CM_RJA, 5, 59, 38),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA, 5, 57, 38),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA, 5, 58, 38),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 67 BONUS WIN 3 */
const u16 elena_cbca_067_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 elena_cbca_067[16] = {
    CMD(CM_EXEC, 49, 36, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 68 APPEAR USE */
const u16 elena_cbca_068_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 elena_cbca_068[16] = {
    CMD(CM_EXEC, 49, 37, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 69 APPEAR USE */
const u16 elena_cbca_069_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 elena_cbca_069[16] = {
    CMD(CM_EXEC, 49, 38, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 70 APPEAR USE */
const u16 elena_cbca_070_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 elena_cbca_070[20] = {
    CMD(CM_EXEC, 49, 39, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RMJA, 8, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 71 APPEAR USE */
const u16 elena_cbca_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 elena_cbca_071[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 56, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 72 APPEAR USE */
const u16 elena_cbca_072_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 elena_cbca_072[16] = {
    CMD(CM_EXEC, 49, 65, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

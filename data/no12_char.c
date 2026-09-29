/*
 * NO12_CHAR.C  Twelve's animation scripts and sprite part tables
 *
 * The animation scripts Twelve's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 no12_nmca_000[], no12_nmca_001[], no12_nmca_002[], no12_nmca_003[], no12_nmca_004[], no12_nmca_005[], no12_nmca_006[], no12_nmca_007[], no12_nmca_008[], no12_nmca_011[], no12_nmca_012[], no12_nmca_013[], no12_nmca_014[], no12_nmca_015[], no12_nmca_016[], no12_nmca_017[], no12_nmca_020[], no12_nmca_021[], no12_nmca_022[], no12_nmca_023[], no12_nmca_024[], no12_nmca_026[], no12_nmca_027[], no12_nmca_028[], no12_nmca_029[], no12_nmca_030[], no12_nmca_031[], no12_nmca_032[], no12_nmca_033[], no12_nmca_038[], no12_nmca_040[], no12_nmca_041[], no12_nmca_043[], no12_nmca_044[], no12_nmca_045[], no12_nmca_046[], no12_nmca_047[], no12_nmca_048[], no12_nmca_049[], no12_nmca_050[];
extern const u16 no12_nmca_000_head[];
extern const u16 no12_nmca_001_head[];
extern const u16 no12_nmca_002_head[];
extern const u16 no12_nmca_003_head[];
extern const u16 no12_nmca_004_head[];
extern const u16 no12_nmca_005_head[];
extern const u16 no12_nmca_006_head[];
extern const u16 no12_nmca_007_head[];
extern const u16 no12_nmca_008_head[];
extern const u16 no12_nmca_011_head[];
extern const u16 no12_nmca_012_head[];
extern const u16 no12_nmca_013_head[];
extern const u16 no12_nmca_014_head[];
extern const u16 no12_nmca_015_head[];
extern const u16 no12_nmca_016_head[];
extern const u16 no12_nmca_017_head[];
extern const u16 no12_nmca_020_head[];
extern const u16 no12_nmca_021_head[];
extern const u16 no12_nmca_022_head[];
extern const u16 no12_nmca_023_head[];
extern const u16 no12_nmca_024_head[];
extern const u16 no12_nmca_026_head[];
extern const u16 no12_nmca_027_head[];
extern const u16 no12_nmca_028_head[];
extern const u16 no12_nmca_029_head[];
extern const u16 no12_nmca_030_head[];
extern const u16 no12_nmca_031_head[];
extern const u16 no12_nmca_032_head[];
extern const u16 no12_nmca_033_head[];
extern const u16 no12_nmca_038_head[];
extern const u16 no12_nmca_040_head[];
extern const u16 no12_nmca_041_head[];
extern const u16 no12_nmca_043_head[];
extern const u16 no12_nmca_044_head[];
extern const u16 no12_nmca_045_head[];
extern const u16 no12_nmca_046_head[];
extern const u16 no12_nmca_047_head[];
extern const u16 no12_nmca_048_head[];
extern const u16 no12_nmca_049_head[];
extern const u16 no12_nmca_050_head[];
extern const u16 no12_dmca_000[], no12_dmca_001[], no12_dmca_002[], no12_dmca_003[], no12_dmca_004[], no12_dmca_006[], no12_dmca_008[], no12_dmca_009[], no12_dmca_010[], no12_dmca_014[], no12_dmca_018[], no12_dmca_034[], no12_dmca_022[], no12_dmca_024[], no12_dmca_025[], no12_dmca_026[], no12_dmca_028[], no12_dmca_029[], no12_dmca_030[], no12_dmca_036[], no12_dmca_048[], no12_dmca_049[], no12_dmca_050[], no12_dmca_052[], no12_dmca_060[], no12_dmca_064[], no12_dmca_065[], no12_dmca_066[], no12_dmca_067[], no12_dmca_068[], no12_dmca_070[], no12_dmca_071[], no12_dmca_072[], no12_dmca_073[], no12_dmca_074[], no12_dmca_075[], no12_dmca_076[], no12_dmca_078[], no12_dmca_079[], no12_dmca_080[], no12_dmca_082[], no12_dmca_083[], no12_dmca_084[], no12_dmca_090[], no12_dmca_091[], no12_dmca_096[], no12_dmca_097[];
extern const u16 no12_dmca_000_head[];
extern const u16 no12_dmca_001_head[];
extern const u16 no12_dmca_002_head[];
extern const u16 no12_dmca_003_head[];
extern const u16 no12_dmca_004_head[];
extern const u16 no12_dmca_006_head[];
extern const u16 no12_dmca_008_head[];
extern const u16 no12_dmca_009_head[];
extern const u16 no12_dmca_010_head[];
extern const u16 no12_dmca_014_head[];
extern const u16 no12_dmca_018_head[];
extern const u16 no12_dmca_034_head[];
extern const u16 no12_dmca_022_head[];
extern const u16 no12_dmca_024_head[];
extern const u16 no12_dmca_025_head[];
extern const u16 no12_dmca_026_head[];
extern const u16 no12_dmca_028_head[];
extern const u16 no12_dmca_029_head[];
extern const u16 no12_dmca_030_head[];
extern const u16 no12_dmca_036_head[];
extern const u16 no12_dmca_048_head[];
extern const u16 no12_dmca_049_head[];
extern const u16 no12_dmca_050_head[];
extern const u16 no12_dmca_052_head[];
extern const u16 no12_dmca_060_head[];
extern const u16 no12_dmca_064_head[];
extern const u16 no12_dmca_065_head[];
extern const u16 no12_dmca_066_head[];
extern const u16 no12_dmca_067_head[];
extern const u16 no12_dmca_068_head[];
extern const u16 no12_dmca_070_head[];
extern const u16 no12_dmca_071_head[];
extern const u16 no12_dmca_072_head[];
extern const u16 no12_dmca_073_head[];
extern const u16 no12_dmca_074_head[];
extern const u16 no12_dmca_075_head[];
extern const u16 no12_dmca_076_head[];
extern const u16 no12_dmca_078_head[];
extern const u16 no12_dmca_079_head[];
extern const u16 no12_dmca_080_head[];
extern const u16 no12_dmca_082_head[];
extern const u16 no12_dmca_083_head[];
extern const u16 no12_dmca_084_head[];
extern const u16 no12_dmca_090_head[];
extern const u16 no12_dmca_091_head[];
extern const u16 no12_dmca_096_head[];
extern const u16 no12_dmca_097_head[];
extern const u16 no12_btca_000[], no12_btca_001[], no12_btca_002[], no12_btca_003[], no12_btca_004[], no12_btca_005[], no12_btca_006[], no12_btca_007[], no12_btca_008[], no12_btca_009[], no12_btca_010[], no12_btca_011[], no12_btca_012[], no12_btca_013[], no12_btca_014[], no12_btca_015[], no12_btca_016[], no12_btca_017[], no12_btca_018[], no12_btca_019[], no12_btca_020[], no12_btca_021[], no12_btca_022[], no12_btca_023[], no12_btca_024[], no12_btca_025[], no12_btca_026[], no12_btca_027[], no12_btca_028[], no12_btca_029[], no12_btca_030[], no12_btca_031[], no12_btca_032[], no12_btca_033[], no12_btca_034[];
extern const u16 no12_btca_000_head[];
extern const u16 no12_btca_001_head[];
extern const u16 no12_btca_002_head[];
extern const u16 no12_btca_003_head[];
extern const u16 no12_btca_004_head[];
extern const u16 no12_btca_005_head[];
extern const u16 no12_btca_006_head[];
extern const u16 no12_btca_007_head[];
extern const u16 no12_btca_008_head[];
extern const u16 no12_btca_009_head[];
extern const u16 no12_btca_010_head[];
extern const u16 no12_btca_011_head[];
extern const u16 no12_btca_012_head[];
extern const u16 no12_btca_013_head[];
extern const u16 no12_btca_014_head[];
extern const u16 no12_btca_015_head[];
extern const u16 no12_btca_016_head[];
extern const u16 no12_btca_017_head[];
extern const u16 no12_btca_018_head[];
extern const u16 no12_btca_019_head[];
extern const u16 no12_btca_020_head[];
extern const u16 no12_btca_021_head[];
extern const u16 no12_btca_022_head[];
extern const u16 no12_btca_023_head[];
extern const u16 no12_btca_024_head[];
extern const u16 no12_btca_025_head[];
extern const u16 no12_btca_026_head[];
extern const u16 no12_btca_027_head[];
extern const u16 no12_btca_028_head[];
extern const u16 no12_btca_029_head[];
extern const u16 no12_btca_030_head[];
extern const u16 no12_btca_031_head[];
extern const u16 no12_btca_032_head[];
extern const u16 no12_btca_033_head[];
extern const u16 no12_btca_034_head[];
extern const u16 no12_caca_000[], no12_caca_004[], no12_caca_008[], no12_caca_012[];
extern const u16 no12_caca_000_head[];
extern const u16 no12_caca_004_head[];
extern const u16 no12_caca_008_head[];
extern const u16 no12_caca_012_head[];
extern const u16 no12_cuca_000[], no12_cuca_001[], no12_cuca_002[], no12_cuca_003[], no12_cuca_004[], no12_cuca_005[], no12_cuca_006[], no12_cuca_007[], no12_cuca_008[], no12_cuca_009[], no12_cuca_010[], no12_cuca_011[], no12_cuca_012[], no12_cuca_013[], no12_cuca_014[], no12_cuca_015[], no12_cuca_016[], no12_cuca_017[], no12_cuca_018[], no12_cuca_019[], no12_cuca_020[], no12_cuca_021[], no12_cuca_022[], no12_cuca_023[], no12_cuca_024[], no12_cuca_025[], no12_cuca_026[], no12_cuca_027[], no12_cuca_028[], no12_cuca_029[], no12_cuca_030[], no12_cuca_031[], no12_cuca_032[], no12_cuca_033[], no12_cuca_034[], no12_cuca_035[], no12_cuca_036[], no12_cuca_037[], no12_cuca_038[], no12_cuca_039[], no12_cuca_040[], no12_cuca_041[], no12_cuca_042[], no12_cuca_043[], no12_cuca_044[], no12_cuca_045[], no12_cuca_046[], no12_cuca_047[], no12_cuca_048[], no12_cuca_049[], no12_cuca_050[], no12_cuca_051[], no12_cuca_052[], no12_cuca_053[], no12_cuca_054[], no12_cuca_055[], no12_cuca_056[], no12_cuca_057[], no12_cuca_058[], no12_cuca_059[], no12_cuca_060[], no12_cuca_062[], no12_cuca_061[], no12_cuca_063[], no12_cuca_064[], no12_cuca_065[], no12_cuca_066[], no12_cuca_067[];
extern const u16 no12_cuca_000_head[];
extern const u16 no12_cuca_001_head[];
extern const u16 no12_cuca_002_head[];
extern const u16 no12_cuca_003_head[];
extern const u16 no12_cuca_004_head[];
extern const u16 no12_cuca_005_head[];
extern const u16 no12_cuca_006_head[];
extern const u16 no12_cuca_007_head[];
extern const u16 no12_cuca_008_head[];
extern const u16 no12_cuca_009_head[];
extern const u16 no12_cuca_010_head[];
extern const u16 no12_cuca_011_head[];
extern const u16 no12_cuca_012_head[];
extern const u16 no12_cuca_013_head[];
extern const u16 no12_cuca_014_head[];
extern const u16 no12_cuca_015_head[];
extern const u16 no12_cuca_016_head[];
extern const u16 no12_cuca_017_head[];
extern const u16 no12_cuca_018_head[];
extern const u16 no12_cuca_019_head[];
extern const u16 no12_cuca_020_head[];
extern const u16 no12_cuca_021_head[];
extern const u16 no12_cuca_022_head[];
extern const u16 no12_cuca_023_head[];
extern const u16 no12_cuca_024_head[];
extern const u16 no12_cuca_025_head[];
extern const u16 no12_cuca_026_head[];
extern const u16 no12_cuca_027_head[];
extern const u16 no12_cuca_028_head[];
extern const u16 no12_cuca_029_head[];
extern const u16 no12_cuca_030_head[];
extern const u16 no12_cuca_031_head[];
extern const u16 no12_cuca_032_head[];
extern const u16 no12_cuca_033_head[];
extern const u16 no12_cuca_034_head[];
extern const u16 no12_cuca_035_head[];
extern const u16 no12_cuca_036_head[];
extern const u16 no12_cuca_037_head[];
extern const u16 no12_cuca_038_head[];
extern const u16 no12_cuca_039_head[];
extern const u16 no12_cuca_040_head[];
extern const u16 no12_cuca_041_head[];
extern const u16 no12_cuca_042_head[];
extern const u16 no12_cuca_043_head[];
extern const u16 no12_cuca_044_head[];
extern const u16 no12_cuca_045_head[];
extern const u16 no12_cuca_046_head[];
extern const u16 no12_cuca_047_head[];
extern const u16 no12_cuca_048_head[];
extern const u16 no12_cuca_049_head[];
extern const u16 no12_cuca_050_head[];
extern const u16 no12_cuca_051_head[];
extern const u16 no12_cuca_052_head[];
extern const u16 no12_cuca_053_head[];
extern const u16 no12_cuca_054_head[];
extern const u16 no12_cuca_055_head[];
extern const u16 no12_cuca_056_head[];
extern const u16 no12_cuca_057_head[];
extern const u16 no12_cuca_058_head[];
extern const u16 no12_cuca_059_head[];
extern const u16 no12_cuca_060_head[];
extern const u16 no12_cuca_062_head[];
extern const u16 no12_cuca_061_head[];
extern const u16 no12_cuca_063_head[];
extern const u16 no12_cuca_064_head[];
extern const u16 no12_cuca_065_head[];
extern const u16 no12_cuca_066_head[];
extern const u16 no12_cuca_067_head[];
extern const u16 no12_atca_000[], no12_atca_003[], no12_atca_004[], no12_atca_006[], no12_atca_009[], no12_atca_012[], no12_atca_014[], no12_atca_015[], no12_atca_018[], no12_atca_021[], no12_atca_024[], no12_atca_027[], no12_atca_030[], no12_atca_033[], no12_atca_036[], no12_atca_038[], no12_atca_040[], no12_atca_042[], no12_atca_044[], no12_atca_046[], no12_atca_048[], no12_atca_050[], no12_atca_052[], no12_atca_054[], no12_atca_056[], no12_atca_058[], no12_atca_060[], no12_atca_062[], no12_atca_064[], no12_atca_066[], no12_atca_068[], no12_atca_070[], no12_atca_072[], no12_atca_074[], no12_atca_076[], no12_atca_078[], no12_atca_080[], no12_atca_082[], no12_atca_084[], no12_atca_086[], no12_atca_088[], no12_atca_090[], no12_atca_092[], no12_atca_094[], no12_atca_096[], no12_atca_098[], no12_atca_100[], no12_atca_102[], no12_atca_104[], no12_atca_106[], no12_atca_108[], no12_atca_110[], no12_atca_112[], no12_atca_114[], no12_atca_116[], no12_atca_118[], no12_atca_144[], no12_atca_145[], no12_atca_146[], no12_atca_156[], no12_atca_157[], no12_atca_158[], no12_atca_159[], no12_atca_160[], no12_atca_161[];
extern const u16 no12_atca_000_head[];
extern const u16 no12_atca_003_head[];
extern const u16 no12_atca_004_head[];
extern const u16 no12_atca_006_head[];
extern const u16 no12_atca_009_head[];
extern const u16 no12_atca_012_head[];
extern const u16 no12_atca_014_head[];
extern const u16 no12_atca_015_head[];
extern const u16 no12_atca_018_head[];
extern const u16 no12_atca_021_head[];
extern const u16 no12_atca_024_head[];
extern const u16 no12_atca_027_head[];
extern const u16 no12_atca_030_head[];
extern const u16 no12_atca_033_head[];
extern const u16 no12_atca_036_head[];
extern const u16 no12_atca_038_head[];
extern const u16 no12_atca_040_head[];
extern const u16 no12_atca_042_head[];
extern const u16 no12_atca_044_head[];
extern const u16 no12_atca_046_head[];
extern const u16 no12_atca_048_head[];
extern const u16 no12_atca_050_head[];
extern const u16 no12_atca_052_head[];
extern const u16 no12_atca_054_head[];
extern const u16 no12_atca_056_head[];
extern const u16 no12_atca_058_head[];
extern const u16 no12_atca_060_head[];
extern const u16 no12_atca_062_head[];
extern const u16 no12_atca_064_head[];
extern const u16 no12_atca_066_head[];
extern const u16 no12_atca_068_head[];
extern const u16 no12_atca_070_head[];
extern const u16 no12_atca_072_head[];
extern const u16 no12_atca_074_head[];
extern const u16 no12_atca_076_head[];
extern const u16 no12_atca_078_head[];
extern const u16 no12_atca_080_head[];
extern const u16 no12_atca_082_head[];
extern const u16 no12_atca_084_head[];
extern const u16 no12_atca_086_head[];
extern const u16 no12_atca_088_head[];
extern const u16 no12_atca_090_head[];
extern const u16 no12_atca_092_head[];
extern const u16 no12_atca_094_head[];
extern const u16 no12_atca_096_head[];
extern const u16 no12_atca_098_head[];
extern const u16 no12_atca_100_head[];
extern const u16 no12_atca_102_head[];
extern const u16 no12_atca_104_head[];
extern const u16 no12_atca_106_head[];
extern const u16 no12_atca_108_head[];
extern const u16 no12_atca_110_head[];
extern const u16 no12_atca_112_head[];
extern const u16 no12_atca_114_head[];
extern const u16 no12_atca_116_head[];
extern const u16 no12_atca_118_head[];
extern const u16 no12_atca_144_head[];
extern const u16 no12_atca_145_head[];
extern const u16 no12_atca_146_head[];
extern const u16 no12_atca_156_head[];
extern const u16 no12_atca_157_head[];
extern const u16 no12_atca_158_head[];
extern const u16 no12_atca_159_head[];
extern const u16 no12_atca_160_head[];
extern const u16 no12_atca_161_head[];
extern const u16 no12_exca_000[], no12_exca_001[], no12_exca_003[], no12_exca_004[], no12_exca_005[], no12_exca_006[], no12_exca_007[], no12_exca_008[], no12_exca_009[], no12_exca_010[], no12_exca_012[], no12_exca_013[], no12_exca_014[], no12_exca_016[], no12_exca_017[], no12_exca_018[], no12_exca_019[], no12_exca_020[], no12_exca_021[], no12_exca_023[], no12_exca_024[], no12_exca_026[], no12_exca_027[], no12_exca_028[], no12_exca_029[], no12_exca_030[], no12_exca_031[], no12_exca_032[], no12_exca_033[], no12_exca_034[], no12_exca_035[], no12_exca_036[], no12_exca_037[], no12_exca_040[], no12_exca_041[], no12_exca_042[], no12_exca_044[], no12_exca_045[], no12_exca_046[];
extern const u16 no12_exca_000_head[];
extern const u16 no12_exca_001_head[];
extern const u16 no12_exca_003_head[];
extern const u16 no12_exca_004_head[];
extern const u16 no12_exca_005_head[];
extern const u16 no12_exca_006_head[];
extern const u16 no12_exca_007_head[];
extern const u16 no12_exca_008_head[];
extern const u16 no12_exca_009_head[];
extern const u16 no12_exca_010_head[];
extern const u16 no12_exca_012_head[];
extern const u16 no12_exca_013_head[];
extern const u16 no12_exca_014_head[];
extern const u16 no12_exca_016_head[];
extern const u16 no12_exca_017_head[];
extern const u16 no12_exca_018_head[];
extern const u16 no12_exca_019_head[];
extern const u16 no12_exca_020_head[];
extern const u16 no12_exca_021_head[];
extern const u16 no12_exca_023_head[];
extern const u16 no12_exca_024_head[];
extern const u16 no12_exca_026_head[];
extern const u16 no12_exca_027_head[];
extern const u16 no12_exca_028_head[];
extern const u16 no12_exca_029_head[];
extern const u16 no12_exca_030_head[];
extern const u16 no12_exca_031_head[];
extern const u16 no12_exca_032_head[];
extern const u16 no12_exca_033_head[];
extern const u16 no12_exca_034_head[];
extern const u16 no12_exca_035_head[];
extern const u16 no12_exca_036_head[];
extern const u16 no12_exca_037_head[];
extern const u16 no12_exca_040_head[];
extern const u16 no12_exca_041_head[];
extern const u16 no12_exca_042_head[];
extern const u16 no12_exca_044_head[];
extern const u16 no12_exca_045_head[];
extern const u16 no12_exca_046_head[];
extern const u16 no12_saca_000[], no12_saca_001[], no12_saca_002[], no12_saca_012[], no12_saca_018[], no12_saca_024[], no12_saca_025[], no12_saca_026[], no12_saca_027[], no12_saca_028[], no12_saca_029[], no12_saca_032[], no12_saca_033[], no12_saca_034[], no12_saca_035[], no12_saca_036[], no12_saca_037[], no12_saca_038[], no12_saca_039[], no12_saca_040[], no12_saca_045[], no12_saca_046[], no12_saca_047[], no12_saca_048[], no12_saca_049[], no12_saca_050[], no12_saca_051[], no12_saca_052[], no12_saca_053[], no12_saca_054[], no12_saca_058[], no12_saca_059[], no12_saca_060[], no12_saca_061[], no12_saca_062[], no12_saca_063[], no12_saca_064[], no12_saca_065[], no12_saca_067[], no12_saca_068[], no12_saca_069[], no12_saca_071[], no12_saca_072[], no12_saca_073[], no12_saca_074[];
extern const u16 no12_saca_000_head[];
extern const u16 no12_saca_001_head[];
extern const u16 no12_saca_002_head[];
extern const u16 no12_saca_012_head[];
extern const u16 no12_saca_018_head[];
extern const u16 no12_saca_024_head[];
extern const u16 no12_saca_025_head[];
extern const u16 no12_saca_026_head[];
extern const u16 no12_saca_027_head[];
extern const u16 no12_saca_028_head[];
extern const u16 no12_saca_029_head[];
extern const u16 no12_saca_032_head[];
extern const u16 no12_saca_033_head[];
extern const u16 no12_saca_034_head[];
extern const u16 no12_saca_035_head[];
extern const u16 no12_saca_036_head[];
extern const u16 no12_saca_037_head[];
extern const u16 no12_saca_038_head[];
extern const u16 no12_saca_039_head[];
extern const u16 no12_saca_040_head[];
extern const u16 no12_saca_045_head[];
extern const u16 no12_saca_046_head[];
extern const u16 no12_saca_047_head[];
extern const u16 no12_saca_048_head[];
extern const u16 no12_saca_049_head[];
extern const u16 no12_saca_050_head[];
extern const u16 no12_saca_051_head[];
extern const u16 no12_saca_052_head[];
extern const u16 no12_saca_053_head[];
extern const u16 no12_saca_054_head[];
extern const u16 no12_saca_058_head[];
extern const u16 no12_saca_059_head[];
extern const u16 no12_saca_060_head[];
extern const u16 no12_saca_061_head[];
extern const u16 no12_saca_062_head[];
extern const u16 no12_saca_063_head[];
extern const u16 no12_saca_064_head[];
extern const u16 no12_saca_065_head[];
extern const u16 no12_saca_067_head[];
extern const u16 no12_saca_068_head[];
extern const u16 no12_saca_069_head[];
extern const u16 no12_saca_071_head[];
extern const u16 no12_saca_072_head[];
extern const u16 no12_saca_073_head[];
extern const u16 no12_saca_074_head[];
extern const u16 no12_cbca_000[], no12_cbca_001[], no12_cbca_002[], no12_cbca_003[], no12_cbca_004[], no12_cbca_005[], no12_cbca_006[], no12_cbca_007[], no12_cbca_008[], no12_cbca_009[], no12_cbca_010[], no12_cbca_011[], no12_cbca_012[], no12_cbca_013[], no12_cbca_014[], no12_cbca_015[], no12_cbca_016[], no12_cbca_017[], no12_cbca_018[], no12_cbca_019[], no12_cbca_020[], no12_cbca_021[], no12_cbca_022[], no12_cbca_023[], no12_cbca_024[], no12_cbca_025[], no12_cbca_026[], no12_cbca_027[], no12_cbca_028[], no12_cbca_029[];
extern const u16 no12_cbca_000_head[];
extern const u16 no12_cbca_001_head[];
extern const u16 no12_cbca_002_head[];
extern const u16 no12_cbca_003_head[];
extern const u16 no12_cbca_004_head[];
extern const u16 no12_cbca_005_head[];
extern const u16 no12_cbca_006_head[];
extern const u16 no12_cbca_007_head[];
extern const u16 no12_cbca_008_head[];
extern const u16 no12_cbca_009_head[];
extern const u16 no12_cbca_010_head[];
extern const u16 no12_cbca_011_head[];
extern const u16 no12_cbca_012_head[];
extern const u16 no12_cbca_013_head[];
extern const u16 no12_cbca_014_head[];
extern const u16 no12_cbca_015_head[];
extern const u16 no12_cbca_016_head[];
extern const u16 no12_cbca_017_head[];
extern const u16 no12_cbca_018_head[];
extern const u16 no12_cbca_019_head[];
extern const u16 no12_cbca_020_head[];
extern const u16 no12_cbca_021_head[];
extern const u16 no12_cbca_022_head[];
extern const u16 no12_cbca_023_head[];
extern const u16 no12_cbca_024_head[];
extern const u16 no12_cbca_025_head[];
extern const u16 no12_cbca_026_head[];
extern const u16 no12_cbca_027_head[];
extern const u16 no12_cbca_028_head[];
extern const u16 no12_cbca_029_head[];

/* normal scripts: 51 entries */
const u16* const no12_nmca[52] = {
    no12_nmca_000,  /* 0 KAMAE */
    no12_nmca_001,  /* 1 HURIMUKI */
    no12_nmca_002,  /* 2 FRONT WALK */
    no12_nmca_003,  /* 3 BACK WALK */
    no12_nmca_004,  /* 4 DASH HUMIKOMI */
    no12_nmca_005,  /* 5 DASH TOBINOKI */
    no12_nmca_006,  /* 6 KAGAMU */
    no12_nmca_007,  /* 7 KAGAMI KAMAE */
    no12_nmca_008,  /* 8 KAGAMI TURN */
    no12_nmca_008,  /* 9 KAGAMI F WALK */
    no12_nmca_008,  /* 10 KAGAMI B WALK */
    no12_nmca_011,  /* 11 STAND UP */
    no12_nmca_012,  /* 12 JUMP JUNBI */
    no12_nmca_013,  /* 13 SP JUMP JUNBI */
    no12_nmca_014,  /* 14 JUMP FRONT */
    no12_nmca_015,  /* 15 JUMP VERTICAL */
    no12_nmca_016,  /* 16 JUMP BACK */
    no12_nmca_017,  /* 17 S JUMP FRONT */
    no12_nmca_017,  /* 18 S JUMP V */
    no12_nmca_017,  /* 19 S JUMP BACK */
    no12_nmca_020,  /* 20 SP JUMP FRONT */
    no12_nmca_021,  /* 21 SP JUMP V */
    no12_nmca_022,  /* 22 SP JUMP BACK */
    no12_nmca_023,  /* 23 WALK END */
    no12_nmca_024,  /* 24 PARING HEAD */
    no12_nmca_024,  /* 25 PARING UP */
    no12_nmca_026,  /* 26 PARING DOWN */
    no12_nmca_027,  /* 27 PARING AIR F */
    no12_nmca_028,  /* 28 PARING AIR B */
    no12_nmca_029,  /* 29 GUARD HEAD */
    no12_nmca_030,  /* 30 GUARD UP */
    no12_nmca_031,  /* 31 GUARD DOWN */
    no12_nmca_032,  /* 32 GUARD AIR */
    no12_nmca_033,  /* 33 no name */
    no12_nmca_033,  /* 34 no name */
    no12_nmca_033,  /* 35 no name */
    no12_nmca_033,  /* 36 no name */
    no12_nmca_033,  /* 37 no name */
    no12_nmca_038,  /* 38 P BREAK ZUJOU */
    no12_nmca_038,  /* 39 P BREAK UP */
    no12_nmca_040,  /* 40 P BREAK DOWN */
    no12_nmca_041,  /* 41 P BREAK AIR F */
    no12_nmca_041,  /* 42 P BREAK AIR R */
    no12_nmca_043,  /* 43 TUKAMIHAZUSI */
    no12_nmca_044,  /* 44 TUKAMIHAZUSARE */
    no12_nmca_045,  /* 45 TUKAMIHAZUSI */
    no12_nmca_046,  /* 46 TUKAMIHAZUSARE */
    no12_nmca_047,  /* 47 no name */
    no12_nmca_048,  /* 48 no name */
    no12_nmca_049,  /* 49 no name */
    no12_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 no12_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_000[124] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C01, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C02, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C03, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C04, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C05, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C06, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C07, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C08, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C09, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0A, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0B, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0C, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0D, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C0E, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 no12_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_001[60] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C29, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2A, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2B, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 no12_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 no12_nmca_002[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB4, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB5, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB6, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA0, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA1, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA2, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DA9, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAA, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAB, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAC, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAD, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAE, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DAF, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB0, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB1, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB2, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB3, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 no12_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 no12_nmca_003[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB4, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB5, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB6, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DB3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DB2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DB1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DB0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAF, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAE, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAD, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAC, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAB, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DAA, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA9, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA8, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA7, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA6, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA5, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA4, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA3, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA2, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA1, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DA0, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 no12_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 no12_nmca_004[76] = {
    CMD(CM_RJA, 0, 4, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C38, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 1, 277, 0, 0, 0, 0, 0x6C39, 0, 15, 0, 0, 0, 32, 1),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C3A, 0, 16, 0, 0, 0, 32, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C3B, 0, 17, 0, 0, 0, 32, 3),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 32, 3),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 no12_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 no12_nmca_005[76] = {
    CMD(CM_RJA, 0, 5, 4), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x6C40, 0, 19, 0, 0, 0, 32, 4),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C41, 0, 20, 0, 0, 0, 32, 5),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C42, 0, 21, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C43, 0, 22, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 no12_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_nmca_006[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C20, 0, 23, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C21, 0, 23, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 no12_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_nmca_007[60] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C16, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C17, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C18, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C19, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C1A, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C1B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 no12_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_nmca_008[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C31, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C32, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C33, 0, 25, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 no12_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_nmca_011[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C26, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 41, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 41, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 no12_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_012[36] = {
    L4(1, 1, 281, 0, 0, 0, 0, 0x6C20, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6C21, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6C22, 0, 27, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C22, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 no12_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_013[36] = {
    L4(2, 0, 281, 0, 0, 0, 0, 0x6C20, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C21, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 27, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C22, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 no12_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_nmca_014[156] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C4D, 0, 29, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x6C4E, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x6C4F, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C56, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C57, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6C58, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x6C59, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x6C5A, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 no12_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 no12_nmca_015[108] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C44, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C45, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6C46, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C49, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C4A, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x6C47, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 no12_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_nmca_016[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 5, 0x6C5E, 0, 29, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x6C5F, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C60, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 no12_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 no12_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 no12_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 no12_nmca_020[156] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C4D, 0, 29, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 6, 0x6C4E, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 11, 0x6C4F, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6C56, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C57, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x6C58, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x6C59, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x6C5A, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 no12_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 no12_nmca_021[108] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x6C44, 0, 29, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C45, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6C46, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C49, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C4A, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C47, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 no12_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 no12_nmca_022[116] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 5, 0x6C5E, 0, 29, 0, 0, 0, 18, 2),
    L4(6, 0, 0, 0, 0, 0, 12, 0x6C5F, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C60, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 no12_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_023[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB7, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB8, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DB9, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 no12_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 no12_nmca_024[124] = {
    L4(1, 136, 0, 0, 0, 0, 0, 0x6ED7, 0, 1, 0, 0, 0, 18, 6),
    L4(1, 0, 966, 0, 0, 0, 0, 0x6ED8, 0, 1, 0, 0, 0, 6, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6ED9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6EDB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6EDA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6EDB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6EDC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6EDD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6EDE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6EDF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 no12_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 no12_nmca_026[116] = {
    L4(1, 136, 0, 0, 0, 0, 0, 0x6F07, 0, 2, 0, 0, 0, 18, 6),
    L4(1, 0, 966, 0, 0, 0, 0, 0x6F08, 0, 2, 0, 0, 0, 6, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F09, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F0B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F0A, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F0B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F0C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F0D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F0E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F0F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D1E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F */
const u16 no12_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_nmca_027[60] = {
    L4(2, 132, 0, 0, 0, 0, 9, 0x6C77, 0, 31, 0, 0, 0, 18, 6),
    L4(2, 0, 966, 0, 0, 0, 9, 0x6C78, 0, 31, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 9, 0x6C79, 0, 31, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 9, 0x6C7B, 0, 31, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x6C7C, 0, 31, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 9, 0x6C7D, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 PARING AIR B */
const u16 no12_nmca_028_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_nmca_028[52] = {
    L4(2, 132, 0, 0, 0, 0, 9, 0x6C77, 0, 31, 0, 0, 0, 18, 6),
    L4(3, 0, 966, 0, 0, 0, 9, 0x6C78, 0, 31, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 9, 0x6C79, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x6C7B, 0, 31, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 9, 0x6C7C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 16, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 no12_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 no12_nmca_029[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C61, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6C62, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6C63, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C66, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 no12_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 no12_nmca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C67, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6C68, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6C69, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C6C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 29, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 no12_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 no12_nmca_031[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C70, 0, 496, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6C71, 0, 496, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6C72, 0, 496, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C75, 0, 496, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C76, 0, 496, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 no12_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 no12_nmca_032[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E79, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1E7A, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7C, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E77, 0, 29, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 no12_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 no12_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E69, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 no12_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_038[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E69, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 20, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 no12_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_nmca_040[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E71, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E72, 0, 2, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x2095, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x2090, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 no12_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E78, 0, 31, 0, 0, 0, 18, 8),
    L4(250, 0, 966, 0, 0, 0, 0, 0x1E79, 0, 31, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 no12_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_043[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x6C69, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C68, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C40, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x6C41, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 no12_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_044[92] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x6E97, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E97, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E98, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E99, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6E9A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E9B, 0, 1, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x6E9C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 no12_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_nmca_045[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 11, 0x6C78, 0, 31, 0, 0, 0, 0, 0),
    L4(250, 0, 966, 0, 0, 0, 11, 0x6C79, 0, 31, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 15, 0x6C60, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 32, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 no12_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_nmca_046[432] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x6C49, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 15, 0x6C4A, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 15, 0x6C48, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6C47, 0, 30, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 31, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0000, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2096, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x2097,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2098, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x2099,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x209A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E85,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E87,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000,
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_JPSS, 6144, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F20,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F21,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F22,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F23,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F24,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F25,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC4,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC5,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC6,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC7,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECA,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECB,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECC,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E41,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E40,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x1E3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 47 no name */
const u16 no12_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_047[60] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F4D, 0, 38, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F4E, 0, 39, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 no12_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 no12_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 no12_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_nmca_050[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E69, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const no12_dmca[99] = {
    no12_dmca_000,  /* 0 GUARD HEAD */
    no12_dmca_001,  /* 1 GUARD UP */
    no12_dmca_002,  /* 2 GUARD DOWN */
    no12_dmca_003,  /* 3 GUARD AIR */
    no12_dmca_004,  /* 4 HUSHIN HEAD */
    no12_dmca_004,  /* 5 HUSHIN UP */
    no12_dmca_006,  /* 6 HUSHIN DOWN */
    no12_dmca_006,  /* 7 HUSHIN AIR */
    no12_dmca_008,  /* 8 FACE S */
    no12_dmca_009,  /* 9 FACE M */
    no12_dmca_010,  /* 10 FACE L */
    no12_dmca_010,  /* 11 FACE SP */
    no12_dmca_008,  /* 12 FOOK OKU S */
    no12_dmca_009,  /* 13 FOOK OKU M */
    no12_dmca_014,  /* 14 FOOK OKU L */
    no12_dmca_014,  /* 15 FOOK OKU SP */
    no12_dmca_008,  /* 16 FOOK TEMAE S */
    no12_dmca_009,  /* 17 FOOK TEMAE M */
    no12_dmca_018,  /* 18 FOOK TEMAE L */
    no12_dmca_018,  /* 19 FOOK TEMAE SP */
    no12_dmca_008,  /* 20 UPPER S */
    no12_dmca_009,  /* 21 UPPER M */
    no12_dmca_022,  /* 22 UPPER L */
    no12_dmca_022,  /* 23 UPPER SP */
    no12_dmca_024,  /* 24 NOUTEN S */
    no12_dmca_025,  /* 25 NOUTEN M */
    no12_dmca_026,  /* 26 NOUTEN L */
    no12_dmca_026,  /* 27 NOUTEN SP */
    no12_dmca_028,  /* 28 BODY BROW S */
    no12_dmca_029,  /* 29 BODY BROW M */
    no12_dmca_030,  /* 30 BODY BROW L */
    no12_dmca_030,  /* 31 BODY BROW SP */
    no12_dmca_028,  /* 32 BODY UPPER S */
    no12_dmca_029,  /* 33 BODY UPPER M */
    no12_dmca_034,  /* 34 BODY UPPER L */
    no12_dmca_034,  /* 35 BODY UPPER SP */
    no12_dmca_036,  /* 36 TATAKI S */
    no12_dmca_036,  /* 37 TATAKI M */
    no12_dmca_036,  /* 38 TATAKI L */
    no12_dmca_036,  /* 39 TATAKI SP */
    no12_dmca_036,  /* 40 TATAKI V. S */
    no12_dmca_036,  /* 41 TATAKI V. M */
    no12_dmca_036,  /* 42 TATAKI V. L */
    no12_dmca_036,  /* 43 TATAKI V. SP */
    no12_dmca_008,  /* 44 NOBASITA TE S */
    no12_dmca_009,  /* 45 NOBASITA TE M */
    no12_dmca_010,  /* 46 NOBASITA TE L */
    no12_dmca_010,  /* 47 NOBASITA TE SP */
    no12_dmca_048,  /* 48 KAGAMI S */
    no12_dmca_049,  /* 49 KAGAMI M */
    no12_dmca_050,  /* 50 KAGAMI L */
    no12_dmca_050,  /* 51 KAGAMI SP */
    no12_dmca_052,  /* 52 KGM TATAKI S */
    no12_dmca_052,  /* 53 KGM TATAKI M */
    no12_dmca_052,  /* 54 KGM TATAKI L */
    no12_dmca_052,  /* 55 KGM TATAKI SP */
    no12_dmca_052,  /* 56 KGM TTKI V.S */
    no12_dmca_052,  /* 57 KGM TTKI V.M */
    no12_dmca_052,  /* 58 KGM TTKI V.L */
    no12_dmca_052,  /* 59 KGM TTKI V.SP */
    no12_dmca_060,  /* 60 NEKOROBI S */
    no12_dmca_060,  /* 61 NEKOROBI M */
    no12_dmca_060,  /* 62 NEKOROBI L */
    no12_dmca_060,  /* 63 NEKOROBI SP */
    no12_dmca_064,  /* 64 OKIAGARI */
    no12_dmca_065,  /* 65 OKIAGARI F */
    no12_dmca_066,  /* 66 OKIAGARI B */
    no12_dmca_067,  /* 67 LOSE NO STAND */
    no12_dmca_068,  /* 68 LOSE SONABA */
    no12_dmca_068,  /* 69 LOSE KAGAMI */
    no12_dmca_070,  /* 70 PIYO */
    no12_dmca_071,  /* 71 UKEMI MOVE F */
    no12_dmca_072,  /* 72 UKEMI MOVE R */
    no12_dmca_073,  /* 73 SHIMEOTASARE */
    no12_dmca_074,  /* 74 TATI TOUKETU S */
    no12_dmca_075,  /* 75 TATI TOUKETU M */
    no12_dmca_076,  /* 76 TATI TOUKETU L */
    no12_dmca_076,  /* 77 TATI TOUKETU P */
    no12_dmca_078,  /* 78 KGM TOUKETU S */
    no12_dmca_079,  /* 79 KGM TOUKETU M */
    no12_dmca_080,  /* 80 KGM TOUKETU L */
    no12_dmca_080,  /* 81 KGM TOUKETU P */
    no12_dmca_082,  /* 82 TATI DENGEKI S */
    no12_dmca_083,  /* 83 TATI DENGEKI M */
    no12_dmca_084,  /* 84 TATI DENGEKI L */
    no12_dmca_084,  /* 85 TATI DENGEKI P */
    no12_dmca_082,  /* 86 KGM DENGEKI S */
    no12_dmca_083,  /* 87 KGM DENGEKI M */
    no12_dmca_084,  /* 88 KGM DENGEKI L */
    no12_dmca_084,  /* 89 KGM DENGEKI P */
    no12_dmca_090,  /* 90 OKIAGARI FRONT */
    no12_dmca_091,  /* 91 OKIAGARI REAR */
    no12_dmca_008,  /* 92 TATI MOE S */
    no12_dmca_009,  /* 93 TATI MOE M */
    no12_dmca_010,  /* 94 TATI MOE L */
    no12_dmca_010,  /* 95 TATI MOE SP */
    no12_dmca_096,  /* 96 no name */
    no12_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 no12_dmca_000_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 no12_dmca_000[76] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x6C63, 0, 103, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C64, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 133, 0, 0, 0, 0, 0, 0x6C65, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C66, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 103, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 no12_dmca_001_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 no12_dmca_001[76] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x6C69, 0, 103, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C6A, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 133, 0, 0, 0, 0, 0, 0x6C6B, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C6C, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 103, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 no12_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_002[84] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x6C72, 0, 104, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C73, 0, 104, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 133, 0, 0, 0, 0, 0, 0x6C74, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C75, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C76, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 104, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 104, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 no12_dmca_003_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 no12_dmca_003[124] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x1E79, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E79, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 7), 0, 0, 0, 0,
    L4(1, 3, 0, 0, 0, 0, 0, 0x1E7A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 139, 0, 0, 0, 0, 0, 0x1E7B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(250, 136, 0, 0, 0, 0, 0, 0x1E6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 15, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 no12_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_004[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E86, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E87, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E88, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E89, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E8A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E8B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 no12_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_006[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E86, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E87, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E88, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E89, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E8A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E8B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 no12_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_008[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC0, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 134, 962, 0, 0, 0, 0, 0x6DC1, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC1, 0, 366, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DC2, 0, 366, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6DC3, 0, 366, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 no12_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_009[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC4, 0, 366, 0, 0, 0, 0, 0),
    L4(3, 137, 962, 0, 0, 0, 0, 0x6DC5, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC6, 0, 367, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC7, 0, 367, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC8, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DC9, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 no12_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_010[148] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DCA, 0, 366, 0, 0, 0, 0, 0),
    L4(4, 139, 962, 0, 0, 0, 0, 0x6DCB, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DCC, 0, 367, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DCD, 0, 368, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DCE, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DCF, 0, 368, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DD0, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DD1, 0, 368, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DD2, 0, 367, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x6DD3, 0, 367, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DD4, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC8, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DC9, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 no12_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_014[164] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC0, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 139, 962, 0, 0, 0, 0, 0x6E68, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E69, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E62, 0, 368, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6E63, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E64, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E65, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E66, 0, 368, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6E67, 0, 368, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x6E50, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E51, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E52, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E53, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E54, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E55, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 no12_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_018[164] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DCA, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 139, 962, 0, 0, 0, 0, 0x6E60, 0, 366, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6E61, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E62, 0, 368, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6E63, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E64, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E65, 0, 368, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6E66, 0, 368, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6E67, 0, 368, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x6E50, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E51, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E52, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E53, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E54, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E55, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 no12_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_034[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC8, 0, 369, 0, 0, 0, 0, 0),
    L4(8, 137, 962, 0, 0, 0, 0, 0x6E81, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E82, 0, 371, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E83, 0, 371, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 372, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 371, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6DE9, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 no12_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_022[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E80, 0, 361, 0, 0, 0, 0, 0),
    L4(2, 137, 962, 0, 0, 0, 0, 0x6E81, 0, 362, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E82, 0, 363, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 13, -32767), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x6E83, 0, 363, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 364, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 363, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 361, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6DE9, 0, 361, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S */
const u16 no12_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_024[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E74, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 135, 962, 0, 0, 0, 0, 0x6E75, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E76, 0, 369, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E77, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E78, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 no12_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_025[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E74, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 135, 962, 0, 0, 0, 0, 0x6E75, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E76, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E77, 0, 370, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E78, 0, 370, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 no12_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_026[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E74, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 135, 962, 0, 0, 0, 0, 0x6E75, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E76, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E77, 0, 371, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E78, 0, 370, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 BODY BROW S, 32 BODY UPPER S */
const u16 no12_dmca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_028[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DD9, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 135, 962, 0, 0, 0, 0, 0x6DDA, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DDA, 0, 369, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DDB, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DDC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 no12_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_029[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DDD, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 136, 962, 0, 0, 0, 0, 0x6DDE, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DDF, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE0, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 no12_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_030[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DE1, 0, 369, 0, 0, 0, 0, 0),
    L4(2, 139, 962, 0, 0, 0, 0, 0x6DE2, 0, 370, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE3, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE4, 0, 371, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE5, 0, 371, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 372, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 371, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE9, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 no12_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_036[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E8C, 0, 372, 0, 0, 0, 0, 0),
    L4(3, 0, 962, 0, 0, 0, 0, 0x6E8D, 0, 372, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 no12_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_048[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEB, 0, 373, 0, 0, 0, 0, 0),
    L4(1, 134, 962, 0, 0, 0, 0, 0x6DEE, 0, 373, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DEC, 0, 373, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DED, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 no12_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_049[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEB, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 135, 962, 0, 0, 0, 0, 0x6DEE, 0, 374, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DEC, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6DED, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 no12_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_050[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEF, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 139, 962, 0, 0, 0, 0, 0x6DF0, 0, 374, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DF1, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DF2, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DF3, 0, 374, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DF4, 0, 373, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 no12_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_052[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DEB, 0, 373, 0, 0, 0, 0, 0),
    L4(3, 0, 962, 0, 0, 0, 0, 0x6E8D, 0, 373, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 no12_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_060[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E27, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 2, 962, 0, 0, 0, 0, 0x6E6C, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E03, 0, 100, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E03, 0, 100, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 no12_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_064[148] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x6E03, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x6E03, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E04, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E05, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E06, 0, 99, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E07, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6DE6, 0, 99, 0, 0, 0, 31, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE9, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 0, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 no12_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_065[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E10, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 966, 0, 0, 0, 0, 0x6E11, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E15, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E16, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E17, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E18, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6C26, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 no12_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_066[132] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E04, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 966, 0, 0, 0, 0, 0x6E1A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E18, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E17, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E16, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E15, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 65, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 no12_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_067[28] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x6E03, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E03, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 no12_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_068[236] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DF5, 0, 501, 0, 0, 0, 32, 40),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DF5, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF6, 0, 501, 0, 0, 0, 0, 0),
    L4(14, 1, 0, 0, 0, 0, 0, 0x6DF7, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF8, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF9, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFA, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFB, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFC, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFD, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFE, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFF, 0, 0, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x6E00, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E01, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E02, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E08, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 288, 0, 0, 0, 0, 0x6E09, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6DD5, 0, 0, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x6DD6, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DD7, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 no12_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_070[268] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F30, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F31, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F32, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F33, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F34, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F35, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F36, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F37, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F38, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F39, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3A, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3B, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3C, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3D, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3E, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F3F, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F40, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F41, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F42, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F43, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F44, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F45, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F46, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F47, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F48, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F49, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F4A, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F4B, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F4C, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F4B, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F4A, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 28), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 no12_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_071[156] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E10, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 966, 0, 0, 0, 0, 0x6E11, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E15, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E16, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E17, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E18, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6C26, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 no12_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_072[132] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E05, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 966, 0, 0, 0, 0, 0x6E1A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E18, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E17, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E16, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E15, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6E14, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E13, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E19, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 71, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 no12_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_073[236] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF5, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF5, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF6, 0, 501, 0, 0, 0, 0, 0),
    L4(14, 1, 0, 0, 0, 0, 0, 0x6DF7, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF8, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF9, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFA, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFB, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFC, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFD, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFE, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DFF, 0, 0, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x6E00, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E01, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E02, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E08, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 288, 0, 0, 0, 0, 0x6E09, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E0F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DD5, 0, 0, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x6DD6, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6DD7, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6DD8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 no12_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_074[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC0, 0, 365, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DC0, 0, 365, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6DC3, 0, 365, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 no12_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_075[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DC4, 0, 365, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DC4, 0, 365, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6DC9, 0, 365, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 no12_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_076[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DCC, 0, 365, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DCC, 0, 366, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6DD2, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DD4, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DC9, 0, 365, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 no12_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_078[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEB, 0, 373, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DEB, 0, 373, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6DEC, 0, 373, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DED, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 no12_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_079[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEC, 0, 373, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DEC, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6DED, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 no12_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_dmca_080[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6DEF, 0, 373, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DF0, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6DF1, 0, 375, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF2, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF3, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DF4, 0, 373, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 no12_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E57, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E58, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 28, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 no12_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E57, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E58, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 29, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 no12_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E57, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E56, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E58, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 30, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 no12_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_090[212] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2010, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2011, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 no12_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_091[196] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 no12_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_096[44] = {
    L4(3, 2, 962, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 100, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 no12_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_dmca_097[44] = {
    L4(3, 2, 962, 0, 0, 0, 0, 0x6E03, 0, 101, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E03, 0, 101, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E03, 0, 101, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x6E03, 0, 101, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E03, 0, 101, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const no12_btca[37] = {
    no12_btca_000,  /* 0 AIR NORMAL */
    no12_btca_001,  /* 1 ASIBARAI SIRI */
    no12_btca_002,  /* 2 ASIB TUNNOMERI */
    no12_btca_003,  /* 3 NOKEZORI */
    no12_btca_004,  /* 4 KUNOJI */
    no12_btca_005,  /* 5 KIRIMOMI */
    no12_btca_006,  /* 6 UPPER */
    no12_btca_007,  /* 7 BODY UPPER */
    no12_btca_008,  /* 8 HARAYARARE */
    no12_btca_009,  /* 9 TATAKI AIR */
    no12_btca_010,  /* 10 TTKI V. AIR */
    no12_btca_011,  /* 11 HUMI ASIB */
    no12_btca_012,  /* 12 FACE */
    no12_btca_013,  /* 13 ASIB SIRI LOSE */
    no12_btca_014,  /* 14 ASIB TUN LOSE */
    no12_btca_015,  /* 15 DENKI */
    no12_btca_016,  /* 16 KUNOJI NOKE */
    no12_btca_017,  /* 17 BODY UPPER SP */
    no12_btca_018,  /* 18 HANEAGARI */
    no12_btca_019,  /* 19 TOUKETSU A */
    no12_btca_020,  /* 20 BODY SLAM */
    no12_btca_021,  /* 21 IPPONZEOI */
    no12_btca_022,  /* 22 TOMOE RYU */
    no12_btca_023,  /* 23 MONKEY FLIP */
    no12_btca_024,  /* 24 TOMOE ORO */
    no12_btca_025,  /* 25 SNAKE FANG */
    no12_btca_026,  /* 26 FLANKEN.S */
    no12_btca_027,  /* 27 KISHINRIKI */
    no12_btca_028,  /* 28 SPLASH.M */
    no12_btca_029,  /* 29 HARAIGOSHI */
    no12_btca_030,  /* 30 ALEX B.D */
    no12_btca_031,  /* 31 GILL */
    no12_btca_032,  /* 32 HANEKAERI HARA */
    no12_btca_033,  /* 33 S HANEAGARI */
    no12_btca_034,  /* 34 TATUMAKIZANKU */
    no12_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 no12_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_000[76] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E79, 0, 454, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 963, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 137, 0, 0, 0, 0, 0, 0x6E79, 0, 454, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 137, 0, 0, 0, 0, 0, 0x6E7D, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E7E, 0, 456, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 no12_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E6D, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 13, 0x6E6E, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6E6F, 0, 459, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E70, 0, 460, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 no12_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_btca_002[44] = {
    CMD(CM_RJA, 7, 3, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E72, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E73, 0, 462, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E6B, 0, 463, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 no12_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_003[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E31, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 no12_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_004[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DE2, 0, 471, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6DE3, 0, 471, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6DE4, 0, 472, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 no12_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_005[148] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E40, 0, 473, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E41, 0, 474, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E42, 0, 475, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E43, 0, 476, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E44, 0, 477, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E45, 0, 478, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E46, 0, 478, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E47, 0, 478, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E48, 0, 479, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E49, 0, 480, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E4A, 0, 481, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E4B, 0, 481, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E4C, 0, 482, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E4D, 0, 482, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E4E, 0, 482, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E4F, 0, 483, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 no12_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_006[108] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E80, 0, 484, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E81, 0, 485, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E82, 0, 486, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E83, 0, 486, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E33, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 no12_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_007[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E79, 0, 454, 0, 0, 0, 0, 0),
    L4(4, 0, 963, 0, 0, 0, 0, 0x6E7A, 0, 487, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E7B, 0, 488, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E7C, 0, 489, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E33, 0, 466, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 no12_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_008[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E31, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E33, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 no12_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_009[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E31, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 no12_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_010[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E8C, 0, 490, 0, 0, 0, 0, 0),
    L4(250, 0, 963, 0, 0, 0, 9, 0x6E8D, 0, 491, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 no12_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 no12_btca_011[36] = {
    CMD(CM_RJA, 7, 28, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E72, 0, 461, 0, 0, 0, 0, 0),
    L4(250, 0, 963, 0, 0, 0, 9, 0x6E73, 0, 462, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 no12_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_012[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DC4, 0, 492, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E31, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 no12_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 no12_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 no12_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 no12_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_015[76] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x6E56, 0, 493, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E56, 0, 493, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E57, 0, 493, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E56, 0, 493, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E58, 0, 493, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 963, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 no12_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_016[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DE2, 0, 471, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6DE3, 0, 471, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DE4, 0, 471, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 no12_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_017[136] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 963, 0, 0, 0, 0, 0x6E31, 0, 465, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6E33, 0, 466, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 no12_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E3B, 0, 99, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 99, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 13, 0x6E37, 0, 99, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x6E35, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x6E3E, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E3F, 0, 99, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 no12_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6DCA, 0, 494, 0, 0, 0, 0, 0),
    L4(250, 0, 963, 0, 0, 0, 0, 0x6DCA, 0, 494, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 no12_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 no12_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E2A, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 no12_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_022[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E3A, 0, 94, 0, 0, 0, 32, 39),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E3B, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 no12_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_023[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E3A, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E3B, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E3E, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E27, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E3C, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E3C, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 no12_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_024[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(4, 0, 963, 0, 0, 0, 0, 0x6E30, 0, 94, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E31, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E35, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 no12_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(9, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 14, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 no12_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_026[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E73, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x6E38, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x6E35, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x6E35, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 no12_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_027[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E32, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E33, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E34, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 no12_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_028[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 99, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 no12_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_029[36] = {
    CMD(CM_RJA, 7, 21, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 no12_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_030[36] = {
    L4(3, 0, 0, 0, 0, 0, 15, 0x6E36, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6E37, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x6E38, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 no12_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E6E, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E6F, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E70, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 no12_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x6E80, 0, 484, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E30, 0, 464, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 no12_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_033[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 963, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 no12_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_btca_034[108] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6E80, 0, 484, 0, 0, 0, 0, 0),
    L4(3, 0, 963, 0, 0, 0, 0, 0x6E81, 0, 485, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E82, 0, 486, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E83, 0, 486, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E32, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E33, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E34, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E35, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E36, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E37, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6E38, 0, 470, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 13 entries */
const u16* const no12_caca[14] = {
    no12_caca_000,  /* 0 CATCH 1 */
    no12_caca_000,  /* 1 CATCH 2 */
    no12_caca_000,  /* 2 CATCH 3 */
    no12_caca_000,  /* 3 CATCH 4 */
    no12_caca_004,  /* 4 CATCH 5 */
    no12_caca_004,  /* 5 CATCH 6 */
    no12_caca_004,  /* 6 CATCH 7 */
    no12_caca_004,  /* 7 CATCH 8 */
    no12_caca_008,  /* 8 CATCH 9 */
    no12_caca_008,  /* 9 CATCH 10 */
    no12_caca_008,  /* 10 CATCH 11 */
    no12_caca_008,  /* 11 CATCH 12 */
    no12_caca_012,  /* 12 CATCH 13 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 no12_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 no12_caca_000[460] = {
    CMD(CM_NGDA, 1542, 53, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 965, 0, 0, 0, 0, 0x6EA0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 16, 0, 0x6EA1, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 17, 0, 0x6EA2, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 18, 0, 0x6EA3, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 19, 0, 0x6EA4, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 20, 0, 0x6EA5, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x6EA6, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 22, 0, 0x6EA7, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 23, 0, 0x6EA8, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 24, 0, 0x6EA9, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 25, 0, 0x6EAA, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 26, 0, 0x6EAB, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 27, 0, 0x6EAC, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 28, 0, 0x6EAD, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 29, 0, 0x6EAE, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 30, 0, 0x6EAF, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 31, 0, 0x6EB0, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 32, 0, 0x6EB1, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 33, 0, 0x6EB2, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 34, 0, 0x6EB3, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 35, 0, 0x6EB4, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 36, 0, 0x6EB5, -34, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 37, 0, 0x6EB6, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 38, 0, 0x6EB7, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x6EB8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EB9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EBA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6EBB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EBC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6EBD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EBE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6EBF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 no12_caca_004_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 no12_caca_004[520] = {
    CMD(CM_NGDA, 1542, 54, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 2, 4, 23), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 969, 0, 0, 0, 0, 0x6EE0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EE1, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EE2, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 39, 0, 0x6EE3, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 40, 0, 0x6EE4, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 41, 0, 0x6EE5, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 42, 0, 0x6EE6, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 43, 0, 0x6EE7, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 2, 4, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 44, 0, 0x6EEA, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 45, 0, 0x6EEB, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    CMD(CM_RAPP2, 2, 4, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 46, 0, 0x6EEC, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 47, 0, 0x6EED, -35, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 48, 0, 0x6EE8, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 49, 0, 0x6EE9, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    CMD(CM_IFLG, 1, 128, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 50, 0, 0x6EEA, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 51, 0, 0x6EEE, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 4, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 36, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 1, 0, 0, 0, 52, 0, 0x6EEF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 53, 0, 0x6EF0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 54, 0, 0x6EF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 55, 0, 0x6EF2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 56, 0, 0x6EF3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6EF4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6EF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6C4C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9, 9 CATCH 10, 10 CATCH 11, 11 CATCH 12 */
const u16 no12_caca_008_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 no12_caca_008[364] = {
    CMD(CM_NGDA, 1542, 55, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 965, 0, 0, 0, 0, 0x6EA0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 16, 0, 0x6EA1, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 17, 0, 0x6EA2, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 18, 0, 0x6EA3, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 19, 0, 0x6EA4, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 20, 0, 0x6EA5, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x6EA6, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 22, 0, 0x6EA7, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 23, 0, 0x6EA8, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 24, 0, 0x6EA9, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 25, 0, 0x6EAA, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 26, 0, 0x6EAB, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 27, 0, 0x6EAC, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 28, 0, 0x6EAD, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 29, 0, 0x6EAE, -36, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 30, 0, 0x6EAF, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 31, 0, 0x6EB0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 32, 0, 0x6EB1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 33, 0, 0x6EB2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EBB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6EBC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6EBD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6EBE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6EBF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13 */
const u16 no12_caca_012_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 no12_caca_012[400] = {
    CMD(CM_NGDA, 1542, 54, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EE0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EE1, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6EE2, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 39, 0, 0x6EE3, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 40, 0, 0x6EE4, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 41, 0, 0x6EE5, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 42, 0, 0x6EE6, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 43, 0, 0x6EE7, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 44, 0, 0x6EEA, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 45, 0, 0x6EEB, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 46, 0, 0x6EEC, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 47, 0, 0x6EED, -35, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 48, 0, 0x6EE8, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 49, 0, 0x6EE9, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 50, 0, 0x6EEA, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 51, 0, 0x6EEE, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 52, 0, 0x6EEF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 53, 0, 0x6EF0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 54, 0, 0x6EF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 55, 0, 0x6EF2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 56, 0, 0x6EF3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6EF4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6EF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C48, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C47, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6C4C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const no12_cuca[69] = {
    no12_cuca_000,  /* 0 ALEX ZUTUKI */
    no12_cuca_001,  /* 1 ALEX BODY S */
    no12_cuca_002,  /* 2 ALEX BACK D */
    no12_cuca_003,  /* 3 ALEX POWER B */
    no12_cuca_004,  /* 4 ALEX SLEEPER */
    no12_cuca_005,  /* 5 RYU SEOINAGE */
    no12_cuca_006,  /* 6 IBUKI */
    no12_cuca_007,  /* 7 DADLEY L B */
    no12_cuca_008,  /* 8 IBUKI KUBIORI */
    no12_cuca_009,  /* 9 NECRO S T */
    no12_cuca_010,  /* 10 RYU TOMOENAGE */
    no12_cuca_011,  /* 11 YUN HIZAGERI */
    no12_cuca_012,  /* 12 ORO KUBISIME */
    no12_cuca_013,  /* 13 NECRO G S */
    no12_cuca_014,  /* 14 DUDDLEY D S */
    no12_cuca_015,  /* 15 YUN MONKEY F */
    no12_cuca_016,  /* 16 ORO TOMOENAGE */
    no12_cuca_017,  /* 17 ORO NIOURIKI */
    no12_cuca_018,  /* 18 ORO GIGOKU G */
    no12_cuca_019,  /* 19 YUN */
    no12_cuca_020,  /* 20 NECRO SNAKE F */
    no12_cuca_021,  /* 21 NECRO F S */
    no12_cuca_022,  /* 22 IBUKI HARAIG */
    no12_cuca_023,  /* 23 GILL SPLASH M */
    no12_cuca_024,  /* 24 KEN HIZAGERI */
    no12_cuca_025,  /* 25 ORO KISINRIKI */
    no12_cuca_026,  /* 26 SEAN TACKLE */
    no12_cuca_027,  /* 27 ALEX HYPER B */
    no12_cuca_028,  /* 28 NECRO SLAM D */
    no12_cuca_029,  /* 29 ELENA ASINAGE */
    no12_cuca_030,  /* 30 GILL IMPACT C */
    no12_cuca_031,  /* 31 ALEX S H B */
    no12_cuca_032,  /* 32 ALEX F N D */
    no12_cuca_033,  /* 33 no name */
    no12_cuca_034,  /* 34 IBUKI */
    no12_cuca_035,  /* 35 IBUKI YOROI D */
    no12_cuca_036,  /* 36 no name */
    no12_cuca_037,  /* 37 MAWARIKOMI M F */
    no12_cuca_038,  /* 38 HUGO BODY S */
    no12_cuca_039,  /* 39 HUGO N G T */
    no12_cuca_040,  /* 40 HUGO M S P */
    no12_cuca_041,  /* 41 HUGO S D B B */
    no12_cuca_042,  /* 42 no name */
    no12_cuca_043,  /* 43 no name */
    no12_cuca_044,  /* 44 no name */
    no12_cuca_045,  /* 45 no name */
    no12_cuca_046,  /* 46 no name */
    no12_cuca_047,  /* 47 no name */
    no12_cuca_048,  /* 48 no name */
    no12_cuca_049,  /* 49 no name */
    no12_cuca_050,  /* 50 no name */
    no12_cuca_051,  /* 51 no name */
    no12_cuca_052,  /* 52 no name */
    no12_cuca_053,  /* 53 no name */
    no12_cuca_054,  /* 54 no name */
    no12_cuca_055,  /* 55 no name */
    no12_cuca_056,  /* 56 no name */
    no12_cuca_057,  /* 57 no name */
    no12_cuca_058,  /* 58 no name */
    no12_cuca_059,  /* 59 no name */
    no12_cuca_060,  /* 60 no name */
    no12_cuca_061,  /* 61 no name */
    no12_cuca_062,  /* 62 no name */
    no12_cuca_063,  /* 63 no name */
    no12_cuca_064,  /* 64 no name */
    no12_cuca_065,  /* 65 no name */
    no12_cuca_066,  /* 66 no name */
    no12_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 no12_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC0),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E74),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 no12_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E45),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E4F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E49),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E4A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E81),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 12, 0x6E38),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 no12_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_002[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DD9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    CMD(CM_RMJA, 3, 2, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E3A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 no12_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_003[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    CMD(CM_RMJA, 3, 3, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E39),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 no12_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_004[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E78),
    CMD(CM_RMJA, 3, 4, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E78),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 no12_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E36),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 7, 0x6E2A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 6),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 no12_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6CFE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C86),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE1),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 no12_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 no12_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DE8),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 no12_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E30),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 no12_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 no12_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE5),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DC2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 no12_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6DE7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 no12_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3F),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E27),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 no12_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE3),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6DE4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 no12_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E71),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E27),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 no12_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E73),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6D),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E30),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 no12_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E3C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 10),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 no12_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E17),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E19),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E12),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E14),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E15),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E16),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E17),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E19),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E11),
    L2(250, 3, 0, 0, 0, 0, 0, 0x6E10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E71),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E71),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 no12_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E78),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC5),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DC5),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 no12_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C38),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E34),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E36),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 no12_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 no12_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E83),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E36),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E37),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 no12_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E3B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 no12_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_024[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    CMD(CM_RMJA, 3, 24, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E30),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 no12_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E32),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 no12_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 3, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2C),
    L2(250, 3, 0, 0, 0, 0, 0, 0x6E27),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E2C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 no12_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DD9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E39),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 no12_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E34),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E34),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 no12_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E7B),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E7C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 no12_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE8),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6DE6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 32, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 no12_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2074),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 no12_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E27),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E27),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 no12_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_033[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DD9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    CMD(CM_RMJA, 3, 33, 14),
    L2(250, 9, 0, 0, 1, 0, 14, 0x6E36),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 no12_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E48),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E7C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 no12_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6CFE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C86),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C85),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE1),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 no12_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6DE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E28),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E2C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 no12_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 no12_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E47),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E69),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6CF6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6CF5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E7A),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E2A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 no12_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E31),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 no12_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E68),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E86),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E8A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E45),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2D),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E2E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 no12_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E36),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 no12_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DE4),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 no12_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2E),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E2E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 no12_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E68),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E86),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E8A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E45),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E2E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 no12_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E77),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E78),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E78),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 no12_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E4D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E04),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E28),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 no12_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_047[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DD9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    CMD(CM_RMJA, 3, 47, 26),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6E3A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 no12_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E75),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 no12_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DDE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E3B),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E3B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 no12_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E6F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E2B),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 no12_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E69),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6E79),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6F30),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DD9),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 no12_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E73),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 no12_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E86),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E89),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E05),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E83),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E35),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E39),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E39),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 no12_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E47),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E46),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E45),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DD3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 32, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 no12_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E86),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E89),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E05),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E83),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E36),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 no12_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6DE0),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 13, 0x6E6E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 no12_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDE),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E79),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 no12_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E37),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E40),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E30),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 no12_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C68),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C6A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C6B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E32),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E33),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 no12_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6DDC),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 no12_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DCA),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E60),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E61),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E63),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E64),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DC9),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, -5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6DE8),
    CMD(CM_PA_X, 0, -4608, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E7A),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E73),
    CMD(CM_PA_X, 0, -6656, 0),
    CMD(CM_PS_Y, 0, 0, 12),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E6B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E3A),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E3B),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 no12_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C7D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C7B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6C7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E6E),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E33),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 no12_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE2),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 963, 0, 0, 0, 0, 0x6DE3),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 no12_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DDF),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E79),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 no12_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E68),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E69),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E63),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6E65),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6E27),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E73),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 no12_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E27),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E27),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 no12_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E75),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E76),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E77),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E78),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6DC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6E31),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6E32),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 162 entries */
const u16* const no12_atca[163] = {
    no12_atca_000,  /* 0 S PUNCH A */
    no12_atca_000,  /* 1 S PUNCH B */
    no12_atca_000,  /* 2 S PUNCH C */
    no12_atca_003,  /* 3 M PUNCH A */
    no12_atca_004,  /* 4 M PUNCH B */
    no12_atca_004,  /* 5 M PUNCH C */
    no12_atca_006,  /* 6 L PUNCH A */
    no12_atca_006,  /* 7 L PUNCH B */
    no12_atca_006,  /* 8 L PUNCH C */
    no12_atca_009,  /* 9 S KICK A */
    no12_atca_009,  /* 10 S KICK B */
    no12_atca_009,  /* 11 S KICK C */
    no12_atca_012,  /* 12 M KICK A */
    no12_atca_012,  /* 13 M KICK B */
    no12_atca_014,  /* 14 M KICK C */
    no12_atca_015,  /* 15 L KICK A */
    no12_atca_015,  /* 16 L KICK B */
    no12_atca_015,  /* 17 L KICK C */
    no12_atca_018,  /* 18 KAGAMI P A */
    no12_atca_018,  /* 19 KAGAMI P B */
    no12_atca_018,  /* 20 KAGAMI P C */
    no12_atca_021,  /* 21 KAGAMI P A */
    no12_atca_021,  /* 22 KAGAMI P B */
    no12_atca_021,  /* 23 KAGAMI P C */
    no12_atca_024,  /* 24 KAGAMI P A */
    no12_atca_024,  /* 25 KAGAMI P B */
    no12_atca_024,  /* 26 KAGAMI P C */
    no12_atca_027,  /* 27 KAGAMI K A */
    no12_atca_027,  /* 28 KAGAMI K B */
    no12_atca_027,  /* 29 KAGAMI K C */
    no12_atca_030,  /* 30 KAGAMI K A */
    no12_atca_030,  /* 31 KAGAMI K B */
    no12_atca_030,  /* 32 KAGAMI K C */
    no12_atca_033,  /* 33 KAGAMI K A */
    no12_atca_033,  /* 34 KAGAMI K B */
    no12_atca_033,  /* 35 KAGAMI K C */
    no12_atca_036,  /* 36 V JUMP P S A */
    no12_atca_036,  /* 37 V JUMP P S B */
    no12_atca_038,  /* 38 V JUMP P M A */
    no12_atca_038,  /* 39 V JUMP P M B */
    no12_atca_040,  /* 40 V JUMP P L A */
    no12_atca_040,  /* 41 V JUMP P L B */
    no12_atca_042,  /* 42 V JUMP K S A */
    no12_atca_042,  /* 43 V JUMP K S B */
    no12_atca_044,  /* 44 V JUMP K M A */
    no12_atca_044,  /* 45 V JUMP K M B */
    no12_atca_046,  /* 46 V JUMP K L A */
    no12_atca_046,  /* 47 V JUMP K L B */
    no12_atca_048,  /* 48 F JUMP P S A */
    no12_atca_048,  /* 49 F JUMP P S B */
    no12_atca_050,  /* 50 F JUMP P M A */
    no12_atca_050,  /* 51 F JUMP P M B */
    no12_atca_052,  /* 52 F JUMP P L A */
    no12_atca_052,  /* 53 F JUMP P L B */
    no12_atca_054,  /* 54 F JUMP K S A */
    no12_atca_054,  /* 55 F JUMP K S B */
    no12_atca_056,  /* 56 F JUMP K M A */
    no12_atca_056,  /* 57 F JUMP K M B */
    no12_atca_058,  /* 58 F JUMP K L A */
    no12_atca_058,  /* 59 F JUMP K L B */
    no12_atca_060,  /* 60 B JUMP P S A */
    no12_atca_060,  /* 61 B JUMP P S B */
    no12_atca_062,  /* 62 B JUMP P M A */
    no12_atca_062,  /* 63 B JUMP P M B */
    no12_atca_064,  /* 64 B JUMP P L A */
    no12_atca_064,  /* 65 B JUMP P L B */
    no12_atca_066,  /* 66 B JUMP K S A */
    no12_atca_066,  /* 67 B JUMP K S B */
    no12_atca_068,  /* 68 B JUMP K M A */
    no12_atca_068,  /* 69 B JUMP K M B */
    no12_atca_070,  /* 70 B JUMP K L A */
    no12_atca_070,  /* 71 B JUMP K L B */
    no12_atca_072,  /* 72 SP V JP S P A */
    no12_atca_072,  /* 73 SP V JP S P B */
    no12_atca_074,  /* 74 SP V JP M P A */
    no12_atca_074,  /* 75 SP V JP M P B */
    no12_atca_076,  /* 76 SP V JP L P A */
    no12_atca_076,  /* 77 SP V JP L P B */
    no12_atca_078,  /* 78 SP V JP S K A */
    no12_atca_078,  /* 79 SP V JP S K B */
    no12_atca_080,  /* 80 SP V JP M K A */
    no12_atca_080,  /* 81 SP V JP M K B */
    no12_atca_082,  /* 82 SP V JP L K A */
    no12_atca_082,  /* 83 SP V JP L K B */
    no12_atca_084,  /* 84 SP F JP S P A */
    no12_atca_084,  /* 85 SP F JP S P B */
    no12_atca_086,  /* 86 SP F JP M P A */
    no12_atca_086,  /* 87 SP F JP M P B */
    no12_atca_088,  /* 88 SP F JP L P A */
    no12_atca_088,  /* 89 SP F JP L P B */
    no12_atca_090,  /* 90 SP F JP S K A */
    no12_atca_090,  /* 91 SP F JP S K B */
    no12_atca_092,  /* 92 SP F JP M K A */
    no12_atca_092,  /* 93 SP F JP M K B */
    no12_atca_094,  /* 94 SP F JP L K A */
    no12_atca_094,  /* 95 SP F JP L K B */
    no12_atca_096,  /* 96 SP B JP S P A */
    no12_atca_096,  /* 97 SP B JP S P B */
    no12_atca_098,  /* 98 SP B JP M P A */
    no12_atca_098,  /* 99 SP B JP M P B */
    no12_atca_100,  /* 100 SP B JP L P A */
    no12_atca_100,  /* 101 SP B JP L P B */
    no12_atca_102,  /* 102 SP B JP S K A */
    no12_atca_102,  /* 103 SP B JP S K B */
    no12_atca_104,  /* 104 SP B JP M K A */
    no12_atca_104,  /* 105 SP B JP M K B */
    no12_atca_106,  /* 106 SP B JP L K A */
    no12_atca_106,  /* 107 SP B JP L K B */
    no12_atca_108,  /* 108 S V JP S P A */
    no12_atca_108,  /* 109 S V JP S P B */
    no12_atca_110,  /* 110 S V JP M P A */
    no12_atca_110,  /* 111 S V JP M P B */
    no12_atca_112,  /* 112 S V JP L P A */
    no12_atca_112,  /* 113 S V JP L P B */
    no12_atca_114,  /* 114 S V JP S K A */
    no12_atca_114,  /* 115 S V JP S K B */
    no12_atca_116,  /* 116 S V JP M K A */
    no12_atca_116,  /* 117 S V JP M K B */
    no12_atca_118,  /* 118 S V JP L K A */
    no12_atca_118,  /* 119 S V JP L K B */
    no12_atca_108,  /* 120 S F JP S P A */
    no12_atca_108,  /* 121 S F JP S P B */
    no12_atca_110,  /* 122 S F JP M P A */
    no12_atca_110,  /* 123 S F JP M P B */
    no12_atca_112,  /* 124 S F JP L P A */
    no12_atca_112,  /* 125 S F JP L P B */
    no12_atca_114,  /* 126 S F JP S K A */
    no12_atca_114,  /* 127 S F JP S K B */
    no12_atca_116,  /* 128 S F JP M K A */
    no12_atca_116,  /* 129 S F JP M K B */
    no12_atca_118,  /* 130 S F JP L K A */
    no12_atca_118,  /* 131 S F JP L K B */
    no12_atca_108,  /* 132 S B JP S P A */
    no12_atca_108,  /* 133 S B JP S P B */
    no12_atca_110,  /* 134 S B JP M P A */
    no12_atca_110,  /* 135 S B JP M P B */
    no12_atca_112,  /* 136 S B JP L P A */
    no12_atca_112,  /* 137 S B JP L P B */
    no12_atca_114,  /* 138 S B JP S K A */
    no12_atca_114,  /* 139 S B JP S K B */
    no12_atca_116,  /* 140 S B JP M K A */
    no12_atca_116,  /* 141 S B JP M K B */
    no12_atca_118,  /* 142 S B JP L K A */
    no12_atca_118,  /* 143 S B JP L K B */
    no12_atca_144,  /* 144 TUKAMIKAKARI A */
    no12_atca_145,  /* 145 TUKAMIKAKARI B */
    no12_atca_146,  /* 146 TUKAMIKAKARI C */
    no12_atca_144,  /* 147 TUKAMIKAKARI D */
    no12_atca_144,  /* 148 TUKAMIKAKARI E */
    no12_atca_144,  /* 149 TUKAMIKAKARI F */
    no12_atca_048,  /* 150 TUKAMI AIR A */
    no12_atca_048,  /* 151 TUKAMI AIR B */
    no12_atca_048,  /* 152 TUKAMI AIR C */
    no12_atca_048,  /* 153 TUKAMI AIR D */
    no12_atca_048,  /* 154 TUKAMI AIR E */
    no12_atca_048,  /* 155 TUKAMI AIR F */
    no12_atca_156,  /* 156 follow-up of APPEAR JUNBI 8 */
    no12_atca_157,  /* 157 follow-up of APPEAR JUNBI 8 */
    no12_atca_158,  /* 158 follow-up of APPEAR JUNBI 8 */
    no12_atca_159,  /* 159 follow-up of APPEAR JUNBI 8 */
    no12_atca_160,  /* 160 follow-up of APPEAR JUNBI 8 */
    no12_atca_161,  /* 161 follow-up of APPEAR JUNBI 8 */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B, 2 S PUNCH C */
const u16 no12_atca_000_head[4] = { HEAD(4, 0, 0, 15, 0, 1, 0) };
const u16 no12_atca_000[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C80, 0, 43, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6C81, -2, 44, 0, 128, 96, 32, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C82, 0, 45, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C83, 0, 46, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C84, 0, 47, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C85, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C86, 0, 49, 0, 0, 0, 32, 7),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C87, 0, 50, 0, 0, 0, 32, 8),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 no12_atca_003_head[4] = { HEAD(4, 0, 2, 10, 0, 1, 0) };
const u16 no12_atca_003[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CA7, 0, 51, 0, 0, 0, 32, 24),
    L4(3, 0, 269, 0, 0, 0, 0, 0x6CA8, 0, 52, 0, 0, 0, 32, 25),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CA9, -1, 53, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CAA, 0, 54, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CAB, 0, 55, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CAC, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CAD, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CAE, 0, 58, 0, 0, 0, 32, 26),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CAF, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6CB0, 0, 60, 0, 0, 0, 32, 27),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CB1, 0, 61, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 no12_atca_004_head[4] = { HEAD(4, 0, 2, 16, 0, 1, 0) };
const u16 no12_atca_004[124] = {
    L4(3, 0, 969, 0, 0, 0, 0, 0x6C88, 0, 62, 0, 0, 0, 32, 9),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C89, 0, 63, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x6C8A, 0, 64, 0, 0, 0, 32, 10),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C8B, -3, 65, 0, 128, 0, 32, 11),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C8C, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C8D, 0, 67, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C8E, 0, 68, 0, 0, 0, 32, 12),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C8F, 0, 69, 0, 0, 0, 32, 13),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C90, 0, 70, 0, 0, 0, 32, 14),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C91, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C92, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 32, 15),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B, 8 L PUNCH C */
const u16 no12_atca_006_head[4] = { HEAD(4, 0, 4, 17, 0, 1, 0) };
const u16 no12_atca_006[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C93, 0, 73, 0, 0, 0, 32, 16),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C94, 0, 74, 0, 0, 0, 32, 17),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6C95, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C96, 0, 76, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C97, 0, 77, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C98, 0, 78, 0, 0, 0, 32, 18),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6C99, -5, 79, 0, 128, 0, 32, 19),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C9A, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C9B, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C9C, 0, 82, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C9D, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C9E, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C9F, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA0, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA1, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA2, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA3, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA4, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6CA5, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CA6, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 no12_atca_009_head[4] = { HEAD(4, 0, 1, 15, 0, 1, 0) };
const u16 no12_atca_009[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CD0, 0, 105, 0, 0, 0, 32, 20),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CD1, 0, 106, 0, 0, 0, 32, 21),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6CD2, -7, 107, 0, 128, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CD3, 0, 108, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CD4, 0, 109, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CD5, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CD6, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CD7, 0, 112, 0, 0, 0, 32, 22),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CD8, 0, 113, 0, 0, 0, 32, 23),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 no12_atca_012_head[4] = { HEAD(4, 0, 3, 11, 0, 1, 0) };
const u16 no12_atca_012[164] = {
    L4(3, 0, 966, 0, 0, 0, 0, 0x6CF7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x6CF8, 0, 115, 0, 0, 0, 32, 135),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CF9, -9, 116, 0, 133, 65, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CFA, 0, 117, 0, 128, 65, 0, 0),
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6CFB, 0, 118, 0, 0, 65, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFC, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFD, 0, 120, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFE, 0, 121, 0, 0, 0, 32, 137),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFF, 0, 122, 0, 0, 0, 32, 138),
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFB, 0, 118, 0, 0, 65, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFC, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFD, 0, 120, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CFE, 0, 121, 0, 0, 0, 32, 137),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CFF, 0, 122, 0, 0, 0, 32, 138),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6D00, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 no12_atca_014_head[4] = { HEAD(4, 0, 3, 11, 0, 1, 0) };
const u16 no12_atca_014[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CD9, 0, 123, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6CDA, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 967, 0, 0, 0, 0, 0x6CDB, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6CDC, -8, 126, 0, 128, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CDD, 0, 127, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CDE, 0, 128, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CDF, 0, 129, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CE0, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CE1, 0, 131, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CE2, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CE3, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6CE4, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CE5, 0, 135, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CE6, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 no12_atca_015_head[4] = { HEAD(4, 0, 5, 25, 0, 1, 0) };
const u16 no12_atca_015[268] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6CE7, 0, 137, 0, 0, 0, 32, 34),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6CE8, 0, 138, 0, 0, 0, 32, 35),
    L4(4, 0, 968, 0, 0, 0, 0, 0x6CE9, 0, 139, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x6CEA, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CEB, -11, 141, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CEC, 0, 142, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CED, 0, 143, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16396, 8192, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CEE, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CEF, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF0, 0, 146, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF1, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF2, 0, 148, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CF3, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF4, 0, 150, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CF5, 0, 151, 0, 0, 0, 32, 36),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CF6, 0, 152, 0, 0, 0, 32, 37),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 41, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 11), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CEE, 0, 144, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CEF, 0, 145, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CF0, 0, 146, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CF1, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF2, 0, 148, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF3, 0, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF4, 0, 150, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF5, 0, 151, 0, 0, 0, 32, 36),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CF6, 0, 152, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 41, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 no12_atca_018_head[4] = { HEAD(4, 32, 0, 15, 0, 1, 0) };
const u16 no12_atca_018[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D17, 0, 153, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6D18, -12, 154, 0, 128, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D19, 0, 155, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1A, 0, 156, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1C, 0, 157, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6D1D, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1E, 0, 159, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D1E, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 no12_atca_021_head[4] = { HEAD(4, 32, 2, 12, 0, 1, 0) };
const u16 no12_atca_021[180] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D20, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D21, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x6D22, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D23, -13, 163, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D24, 0, 164, 0, 128, 0, 0, 0),
    CMD(CM_HJMP, 8192, 16392, 16392), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D25, 0, 165, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D26, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D27, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D28, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D1C, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D29, 0, 169, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D25, 0, 165, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D26, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D27, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D28, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1C, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D29, 0, 169, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6D2A, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D1E, 0, 171, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D1E, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 no12_atca_024_head[4] = { HEAD(4, 32, 4, 10, 0, 3, 0) };
const u16 no12_atca_024[976] = {
    L4(2, 0, 970, 0, 0, 0, 0, 0x7057, 0, 427, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7058, 0, 427, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7059, 0, 428, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x705A, 0, 429, 0, 0, 0, 32, 49),
    L4(1, 0, 0, 0, 0, 0, 0, 0x705B, -48, 430, 0, 0, 0, 32, 50),
    L4(1, 0, 0, 0, 0, 0, 0, 0x705C, 0, 431, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x705D, 0, 432, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x705E, 0, 433, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x705F, 0, 434, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7060, 0, 435, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7061, -48, 436, 0, 79, 0, 32, 51),
    CMD(CM_IXFW, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7061, -49, 436, 0, 0, 0, 32, 51),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7062, 0, 437, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7063, 0, 438, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7064, 0, 439, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7065, 0, 440, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7066, 0, 441, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7067, -50, 442, 0, 0, 0, 32, 52),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7068, 0, 443, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7069, 0, 444, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x706A, 0, 445, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x706B, 0, 446, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x706C, 0, 447, 0, 0, 0, 0, 0),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x706D, 0, 448, 0, 0, 0, 32, 53),
    L4(3, 0, 0, 0, 0, 0, 0, 0x706E, 0, 449, 0, 0, 0, 32, 54),
    L4(3, 0, 0, 0, 0, 0, 0, 0x706F, 0, 450, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x703E, 0, 451, 0, 0, 0, 32, 55),
    L4(3, 0, 0, 0, 0, 0, 0, 0x703F, 0, 451, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x706D, 0, 448, 0, 0, 0, 32, 53),
    L4(2, 0, 0, 0, 0, 0, 0, 0x706E, 0, 449, 0, 0, 0, 32, 54),
    L4(2, 0, 0, 0, 0, 0, 0, 0x706F, 0, 450, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x703E, 0, 451, 0, 0, 0, 32, 55),
    L4(2, 0, 0, 0, 0, 0, 0, 0x703F, 0, 451, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2004, 0x1000, 0x0200,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 118, 0, 0x6D30, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 119, 0, 0x6D31, 0, 351, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 120, 0, 0x6D32, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 121, 0, 0x6D33, -37, 320, 0, 140, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 122, 0, 0x6D33, 0, 321, 0, 140, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 123, 0, 0x6D33, 0, 322, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 124, 0, 0x6D33, 0, 323, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 125, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 126, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 127, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 128, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 129, 0, 0x6D34, 0, 325, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 130, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 131, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 132, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2004, 0x1000, 0x0200,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D20, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D21, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x6D22, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D23, -16, 163, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D24, 0, 164, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D25, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D26, 0, 166, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D27, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D28, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D20, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D21, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x6D22, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D23, -13, 163, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D24, 0, 164, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D25, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D26, 0, 166, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D27, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D28, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1C, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D29, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6D2A, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D1E, 0, 171, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D1E, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2004, 0x1000, 0x0200,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 1, 0, 0x6D30, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 2, 0, 0x6D31, 0, 351, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 3, 0, 0x6D32, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 4, 0, 0x6D33, -37, 320, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 5, 0, 0x6D33, 0, 321, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 6, 0, 0x6D33, 0, 322, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 7, 0, 0x6D33, 0, 323, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 8, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 9, 0, 0x6D34, 0, 325, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 10, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 11, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 12, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 13, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 14, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 15, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 no12_atca_027_head[4] = { HEAD(4, 32, 1, 14, 0, 1, 0) };
const u16 no12_atca_027[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D42, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 0, 0x6D43, -15, 173, 0, 128, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D44, 0, 174, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D45, 0, 175, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D46, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D47, 0, 176, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D48, 0, 176, 0, 0, 16, 0, 2),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6D49, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 no12_atca_030_head[4] = { HEAD(4, 32, 3, 17, 0, 1, 0) };
const u16 no12_atca_030[132] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CC0, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6CC1, 0, 178, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6CC2, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CC3, -53, 180, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6CC4, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CC5, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6CC6, 0, 183, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CC7, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CC8, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CC9, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6CCA, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 no12_atca_033_head[4] = { HEAD(4, 32, 5, 15, 0, 3, 0) };
const u16 no12_atca_033[268] = {
    L4(3, 0, 0, 1, 0, 0, 0, 0x6D4A, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D4B, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 968, 1, 0, 0, 0, 0x6D4C, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D4D, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D4E, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 1, 0, 0, 0, 0x6D4F, 0, 193, 0, 0, 0, 30, 181),
    L4(1, 0, 0, 1, 0, 0, 0, 0x6D50, -17, 194, 0, 0, 0, 32, 38),
    L4(1, 0, 0, 1, 0, 0, 0, 0x6D51, 0, 194, 0, 0, 0, 30, 182),
    CMD(CM_HJMP, 16391, 8192, 16391), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x6D52, -100, 194, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x6D53, 0, 194, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 16390), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x6D54, -100, 194, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D55, 0, 194, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D52, 0, 194, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D53, 0, 194, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6D54, 0, 194, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D55, 0, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D56, 0, 195, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D57, 0, 196, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D58, 0, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D59, 0, 198, 0, 0, 0, 32, 42),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D5A, 0, 199, 0, 0, 0, 32, 43),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D5B, 0, 200, 0, 0, 0, 32, 44),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6D5C, 0, 201, 0, 0, 0, 32, 45),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 32, 46),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 no12_atca_036_head[4] = { HEAD(4, 22, 0, 10, 0, 1, 0) };
const u16 no12_atca_036[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D60, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6D61, 0, 203, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 5, 0x6D62, -19, 204, 0, 128, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 5, 0x6D63, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D64, 0, 206, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D65, 0, 207, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 no12_atca_038_head[4] = { HEAD(4, 22, 2, 14, 0, 1, 0) };
const u16 no12_atca_038[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6D66, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D67, 0, 212, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 5, 0x6D68, -20, 213, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D69, 0, 214, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 5, 0x6D6A, 0, 215, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6B, 0, 216, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 no12_atca_040_head[4] = { HEAD(4, 22, 4, 18, 0, 1, 0) };
const u16 no12_atca_040[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D88, 0, 217, 0, 0, 0, 21, 0),
    L4(3, 0, 964, 0, 0, 0, 0, 0x6D89, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D8A, 0, 219, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D8B, 0, 220, 0, 0, 0, 33, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6D8C, 0, 221, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D8D, -21, 222, 0, 137, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D8E, 0, 223, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D8F, 0, 224, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D90, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D91, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D92, 0, 227, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D93, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D94, 0, 229, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 no12_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 no12_atca_042[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D77, 0, 230, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D78, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6D79, -22, 232, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D7A, 0, 233, 0, 128, 0, 0, 0),
    L4(18, 0, 0, 0, 0, 0, 0, 0x6D7A, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D7B, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D7C, 0, 235, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 no12_atca_044_head[4] = { HEAD(4, 22, 3, 13, 0, 1, 0) };
const u16 no12_atca_044[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6F, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D70, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6D96, 0, 238, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D71, -23, 239, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D72, 0, 240, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D73, 0, 240, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D74, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D75, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D76, 0, 244, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D95, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 no12_atca_046_head[4] = { HEAD(4, 22, 5, 6, 0, 1, 0) };
const u16 no12_atca_046[116] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D7D, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 966, 0, 0, 0, 5, 0x6D7E, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D7F, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D80, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D81, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D82, -24, 250, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D83, 0, 251, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D84, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D85, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D86, 0, 253, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B, 150 TUKAMI AIR A, 151 TUKAMI AIR B ... */
const u16 no12_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 no12_atca_048[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6D60, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6D61, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 5, 0x6D62, -25, 204, 0, 128, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 5, 0x6D63, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D64, 0, 206, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D65, 0, 207, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 no12_atca_050_head[4] = { HEAD(4, 20, 2, 15, 0, 1, 0) };
const u16 no12_atca_050[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6D66, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D67, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6D68, -26, 213, 0, 128, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 5, 0x6D69, 0, 214, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 5, 0x6D6A, 0, 215, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x6D6B, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 no12_atca_052_head[4] = { HEAD(4, 20, 4, 19, 0, 1, 0) };
const u16 no12_atca_052[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D88, 0, 217, 0, 0, 0, 21, 0),
    L4(3, 0, 964, 0, 0, 0, 0, 0x6D89, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D8A, 0, 219, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D8B, 0, 220, 0, 0, 0, 33, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6D8C, 0, 221, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D8D, -21, 222, 0, 137, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D8E, 0, 223, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D8F, 0, 224, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D90, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D91, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D92, 0, 227, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D93, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D94, 0, 229, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 no12_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 no12_atca_054[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D77, 0, 230, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D78, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6D79, -22, 232, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D7A, 0, 233, 0, 128, 0, 0, 0),
    L4(18, 0, 0, 0, 0, 0, 0, 0x6D7A, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D7B, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D7C, 0, 235, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 no12_atca_056_head[4] = { HEAD(4, 20, 3, 14, 0, 1, 0) };
const u16 no12_atca_056[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6F, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D70, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6D96, 0, 238, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D71, -23, 239, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D72, 0, 240, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D73, 0, 240, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6D74, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D75, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D76, 0, 244, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D95, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 no12_atca_058_head[4] = { HEAD(4, 20, 5, 7, 0, 1, 0) };
const u16 no12_atca_058[116] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D7D, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 966, 0, 0, 0, 5, 0x6D7E, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6D7F, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x6D80, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 5, 0x6D81, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D82, -24, 250, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D83, 0, 251, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D84, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D85, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D86, 0, 254, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 no12_atca_060_head[4] = { HEAD(2, 24, 0, 10, 0, 1, 0) };
const u16 no12_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 no12_atca_062_head[4] = { HEAD(2, 24, 2, 14, 0, 1, 0) };
const u16 no12_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 no12_atca_064_head[4] = { HEAD(2, 24, 4, 18, 0, 1, 0) };
const u16 no12_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 no12_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 no12_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 no12_atca_068_head[4] = { HEAD(2, 24, 3, 13, 0, 1, 0) };
const u16 no12_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 no12_atca_070_head[4] = { HEAD(2, 24, 5, 6, 0, 1, 0) };
const u16 no12_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 no12_atca_072_head[4] = { HEAD(2, 28, 0, 10, 0, 1, 0) };
const u16 no12_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 no12_atca_074_head[4] = { HEAD(2, 28, 2, 14, 0, 1, 0) };
const u16 no12_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 no12_atca_076_head[4] = { HEAD(2, 28, 4, 18, 0, 1, 0) };
const u16 no12_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 no12_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 no12_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 no12_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 no12_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 no12_atca_082_head[4] = { HEAD(2, 28, 5, 6, 0, 1, 0) };
const u16 no12_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 no12_atca_084_head[4] = { HEAD(2, 26, 0, 11, 0, 1, 0) };
const u16 no12_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 no12_atca_086_head[4] = { HEAD(2, 26, 2, 15, 0, 1, 0) };
const u16 no12_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 no12_atca_088_head[4] = { HEAD(2, 26, 4, 19, 0, 1, 0) };
const u16 no12_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 no12_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 no12_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 no12_atca_092_head[4] = { HEAD(2, 26, 3, 14, 0, 1, 0) };
const u16 no12_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 no12_atca_094_head[4] = { HEAD(2, 26, 5, 7, 0, 1, 0) };
const u16 no12_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 no12_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 no12_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 no12_atca_098_head[4] = { HEAD(2, 30, 2, 14, 0, 1, 0) };
const u16 no12_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 no12_atca_100_head[4] = { HEAD(2, 30, 4, 18, 0, 1, 0) };
const u16 no12_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 no12_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 no12_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 no12_atca_104_head[4] = { HEAD(2, 30, 3, 13, 0, 1, 0) };
const u16 no12_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 no12_atca_106_head[4] = { HEAD(2, 30, 5, 6, 0, 1, 0) };
const u16 no12_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 no12_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 no12_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 no12_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 no12_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 no12_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 no12_atca_112[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 no12_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 no12_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 no12_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 no12_atca_116[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 no12_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 no12_atca_118[152] = {
    CMD(CM_JPSS, 4, 56, 1),
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

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F */
const u16 no12_atca_144_head[4] = { HEAD(4, 0, 16, 0, 0, 0, 0) };
const u16 no12_atca_144[132] = {
    CMD(CM_CAFR, 2, 1, 4), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 4), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E96, 0, 1, 0, 0, 0, 32, 28),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E96, -33, 93, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 58, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x6E97, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E98, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E99, 0, 1, 0, 0, 0, 32, 30),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E9A, 0, 1, 0, 0, 0, 32, 31),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6E9B, 0, 1, 0, 0, 0, 32, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E9C, 0, 1, 0, 0, 0, 32, 33),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 no12_atca_145_head[4] = { HEAD(4, 0, 16, 0, 0, 0, 0) };
const u16 no12_atca_145[28] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 4, 144, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 no12_atca_146_head[4] = { HEAD(4, 0, 16, 0, 0, 0, 0) };
const u16 no12_atca_146[28] = {
    CMD(CM_CAFR, 2, 2, 8), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 8), 0, 0, 0, 0,
    CMD(CM_JMP, 4, 144, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_156_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 no12_atca_156[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 9, 0x6D60, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x6D61, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x6D62, -25, 204, 0, 128, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 6, 0x6D63, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D64, 0, 206, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D65, 0, 207, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_157_head[4] = { HEAD(4, 20, 2, 11, 0, 1, 0) };
const u16 no12_atca_157[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 12, 0x6D66, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D67, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 12, 0x6D68, -26, 213, 0, 128, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 12, 0x6D69, 0, 214, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 12, 0x6D6A, 0, 215, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x6D6B, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_158_head[4] = { HEAD(4, 20, 4, 19, 0, 1, 0) };
const u16 no12_atca_158[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x6D88, 0, 217, 0, 0, 0, 21, 0),
    L4(3, 0, 964, 0, 0, 0, 7, 0x6D89, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x6D8A, 0, 219, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x6D8B, 0, 220, 0, 0, 0, 33, 0),
    L4(2, 0, 270, 0, 0, 0, 9, 0x6D8C, 0, 221, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x6D8D, -21, 222, 0, 137, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x6D8E, 0, 223, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x6D8F, 0, 224, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x6D90, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6D91, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D92, 0, 227, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D93, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D94, 0, 229, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_159_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 no12_atca_159[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6D77, 0, 230, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x6D78, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 13, 0x6D79, -22, 232, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 13, 0x6D7A, 0, 233, 0, 128, 0, 0, 0),
    L4(18, 0, 0, 0, 0, 0, 13, 0x6D7A, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D7B, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6D7C, 0, 235, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_160_head[4] = { HEAD(4, 20, 3, 9, 0, 1, 0) };
const u16 no12_atca_160[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D6F, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D70, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 12, 0x6D96, 0, 238, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6D71, -23, 239, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6D72, 0, 240, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6D73, 0, 240, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6D74, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D75, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D76, 0, 244, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x6D95, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x6D6C, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D6D, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6D6E, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 161 follow-up of APPEAR JUNBI 8 */
const u16 no12_atca_161_head[4] = { HEAD(4, 20, 5, 9, 0, 1, 0) };
const u16 no12_atca_161[116] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x6D7D, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 966, 0, 0, 0, 10, 0x6D7E, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x6D7F, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x6D80, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 10, 0x6D81, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D82, -24, 250, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D83, 0, 251, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D84, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D85, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D86, 0, 254, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX no12_olc_ix_table[133] = {
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
    { { 0, 57, 0, 0 } },
    { { 0, 58, 0, 0 } },
    { { 0, 59, 0, 0 } },
    { { 0, 60, 0, 0 } },
    { { 0, 61, 0, 0 } },
    { { 0, 62, 0, 0 } },
    { { 0, 63, 0, 0 } },
    { { 0, 64, 0, 0 } },
    { { 0, 65, 0, 0 } },
    { { 0, 66, 0, 0 } },
    { { 0, 67, 0, 0 } },
    { { 0, 68, 0, 0 } },
    { { 0, 69, 0, 0 } },
    { { 0, 70, 0, 0 } },
    { { 0, 71, 0, 0 } },
    { { 0, 72, 0, 0 } },
    { { 0, 73, 0, 0 } },
    { { 0, 74, 0, 0 } },
    { { 0, 75, 0, 0 } },
    { { 0, 76, 0, 0 } },
    { { 0, 77, 0, 0 } },
    { { 0, 78, 0, 0 } },
    { { 0, 79, 0, 0 } },
    { { 0, 80, 0, 0 } },
    { { 0, 81, 0, 0 } },
    { { 0, 82, 0, 0 } },
    { { 0, 83, 0, 0 } },
    { { 0, 84, 0, 0 } },
    { { 0, 85, 0, 0 } },
    { { 0, 86, 0, 0 } },
    { { 0, 87, 0, 0 } },
    { { 0, 88, 0, 0 } },
    { { 0, 89, 0, 0 } },
    { { 0, 90, 0, 0 } },
    { { 0, 91, 0, 0 } },
    { { 0, 92, 0, 0 } },
    { { 0, 93, 0, 0 } },
    { { 0, 94, 0, 0 } },
    { { 0, 95, 0, 0 } },
    { { 0, 96, 0, 0 } },
    { { 0, 97, 0, 0 } },
    { { 0, 98, 0, 0 } },
    { { 0, 99, 0, 0 } },
    { { 0, 100, 0, 0 } },
    { { 0, 101, 0, 0 } },
    { { 0, 102, 0, 0 } },
    { { 0, 103, 0, 0 } },
    { { 0, 104, 0, 0 } },
    { { 0, 105, 0, 0 } },
    { { 0, 106, 0, 0 } },
    { { 0, 107, 0, 0 } },
    { { 0, 108, 0, 0 } },
    { { 0, 109, 0, 0 } },
    { { 0, 110, 0, 0 } },
    { { 0, 111, 0, 0 } },
    { { 0, 112, 0, 0 } },
    { { 0, 113, 0, 0 } },
    { { 0, 114, 0, 0 } },
    { { 0, 115, 0, 0 } },
    { { 0, 116, 0, 0 } },
    { { 0, 117, 0, 0 } },
    { { 0, 118, 0, 0 } },
    { { 0, 119, 0, 0 } },
    { { 0, 120, 0, 0 } },
    { { 0, 121, 0, 0 } },
    { { 0, 122, 0, 0 } },
    { { 0, 123, 0, 0 } },
    { { 0, 124, 0, 0 } },
    { { 0, 125, 0, 0 } },
    { { 0, 126, 0, 0 } },
    { { 0, 127, 0, 0 } },
    { { 0, 128, 0, 0 } },
    { { 0, 129, 0, 0 } },
    { { 0, 130, 0, 0 } },
    { { 0, 131, 0, 0 } },
    { { 0, 132, 0, 0 } },
};

const OVERLAP_PARTS no12_overlap_char_tbl[133] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 1, 27905 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 2, 27906 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 3, 27907 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 4, 27908 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 5, 27909 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 6, 27910 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 7, 27911 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 8, 27912 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 9, 27913 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 10, 27914 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 11, 27915 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 12, 27916 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 13, 27917 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 14, 27918 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 15, 27919 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 16, 28352 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 28353 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 18, 28354 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 19, 28355 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 28356 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 28357 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 28358 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 28359 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 28360 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 28361 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 28362 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 28363 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 28, 28364 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 29, 28365 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 30, 28366 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 31, 28367 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 32, 28368 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 33, 28369 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 34, 28370 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 35, 28371 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 36, 28372 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 37, 28373 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 38, 28374 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 39, 28406 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 40, 28407 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 41, 28408 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 42, 28409 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 28410 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 28413 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 28414 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 28415 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 47, 28416 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 48, 28411 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 49, 28412 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 50, 28413 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 51, 28417 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 52, 28418 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 53, 28419 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 54, 28420 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 55, 28421 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 56, 28422 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 57, 27905 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 58, 27906 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 59, 27907 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 60, 27908 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 61, 27909 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 62, 27910 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 63, 27911 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 64, 27912 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 65, 27913 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 66, 27914 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 67, 27915 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 68, 27916 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 69, 27917 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 70, 27918 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 71, 27919 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 72, 27905 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 73, 27906 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 74, 27907 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 75, 27908 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 76, 27909 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 77, 27910 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 78, 27911 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 79, 27912 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 80, 27913 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 81, 27914 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 82, 27915 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 83, 27916 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 84, 27917 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 85, 27918 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 86, 27919 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 87, 27920 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 88, 27921 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 89, 27922 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 90, 27923 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 91, 27920 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 92, 27921 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 93, 27922 },
    { -176, 0, 0, 0, 2, 0, 255, 0, 0, 94, 27923 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 95, 27920 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 96, 27921 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 97, 27922 },
    { -256, 0, 0, 0, 2, 0, 255, 0, 0, 98, 27923 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 99, 27905 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 100, 27906 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 101, 27907 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 102, 27908 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 103, 27909 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 104, 27910 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 105, 27911 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 106, 27912 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 107, 27913 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 108, 27914 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 109, 27915 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 110, 27916 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 111, 27917 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 112, 27918 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 113, 27919 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 114, 27920 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 115, 27921 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 116, 27922 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 117, 27923 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 118, 28663 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 119, 28664 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 120, 28665 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 121, 28666 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 122, 28667 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 123, 28668 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 124, 28669 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 125, 28670 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 126, 28671 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 127, 28672 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 128, 28673 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 129, 28674 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 130, 28675 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 131, 28676 },
    { -96, 0, 0, 0, 2, 0, 255, 0, 0, 132, 28677 },
};

const CatchTable no12_rival_catch_tbl[984] = {
    { -108, 0, 2, 1, 1 },
    { -106, 0, 2, 1, 1 },
    { -114, 0, 2, 1, 1 },
    { -94, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -71, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -93, 0, 2, 1, 1 },
    { -103, 0, 2, 1, 1 },
    { -94, 0, 2, 1, 1 },
    { -114, 0, 2, 1, 1 },
    { -114, 0, 2, 1, 1 },
    { -108, 0, 2, 1, 1 },
    { -114, 0, 2, 1, 1 },
    { -114, 0, 2, 1, 1 },
    { -95, 0, 2, 1, 1 },
    { -95, 0, 2, 1, 1 },
    { -77, 0, 2, 1, 1 },
    { -71, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -110, 0, 2, 1, 2 },
    { -106, 0, 2, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -94, 0, 2, 1, 2 },
    { -91, 0, 2, 1, 2 },
    { -73, 0, 2, 1, 2 },
    { -96, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -93, 0, 2, 1, 2 },
    { -85, 0, 2, 1, 2 },
    { -94, 0, 2, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -110, 0, 2, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -101, 0, 2, 1, 2 },
    { -95, 0, 2, 1, 2 },
    { -77, 0, 2, 1, 2 },
    { -75, 0, 2, 1, 2 },
    { -88, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -115, 0, 2, 1, 3 },
    { -90, 0, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -94, 0, 2, 1, 3 },
    { -90, 0, 2, 1, 3 },
    { -70, 0, 2, 1, 3 },
    { -92, 0, 2, 1, 3 },
    { -96, -10, 2, 1, 3 },
    { -93, 0, 2, 1, 3 },
    { -85, 0, 2, 1, 3 },
    { -94, 0, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -115, 0, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -107, 0, 2, 1, 3 },
    { -95, 0, 2, 1, 3 },
    { -77, 0, 2, 1, 3 },
    { -74, 0, 2, 1, 3 },
    { -88, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -109, 0, 2, 1, 4 },
    { -90, 0, 2, 1, 4 },
    { -95, 0, 2, 1, 4 },
    { -86, 0, 2, 1, 4 },
    { -88, 0, 2, 1, 4 },
    { -74, 0, 2, 1, 4 },
    { -96, 0, 2, 1, 4 },
    { -75, -1, 2, 1, 4 },
    { -93, 0, 2, 1, 4 },
    { -84, 0, 2, 1, 4 },
    { -86, 0, 2, 1, 4 },
    { -95, 0, 2, 1, 4 },
    { -95, 0, 2, 1, 4 },
    { -109, 0, 2, 1, 4 },
    { -95, 0, 2, 1, 4 },
    { -95, 0, 2, 1, 4 },
    { -107, 0, 2, 1, 4 },
    { -99, 0, 2, 1, 4 },
    { -77, 0, 2, 1, 4 },
    { -79, 0, 2, 1, 4 },
    { -88, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -100, 0, 2, 1, 5 },
    { -90, 0, 2, 1, 5 },
    { -95, 0, 2, 1, 5 },
    { -83, 0, 2, 1, 5 },
    { -88, 0, 2, 1, 5 },
    { -84, -5, 2, 1, 5 },
    { -91, 0, 2, 1, 5 },
    { -88, -3, 2, 1, 5 },
    { -93, 0, 2, 1, 5 },
    { -90, 0, 2, 1, 5 },
    { -83, 0, 2, 1, 5 },
    { -95, 0, 2, 1, 5 },
    { -95, 0, 2, 1, 5 },
    { -100, 0, 2, 1, 5 },
    { -95, 0, 2, 1, 5 },
    { -95, 0, 2, 1, 5 },
    { -104, 0, 2, 1, 5 },
    { -113, 0, 2, 1, 5 },
    { -76, 0, 2, 1, 5 },
    { -93, -5, 2, 1, 5 },
    { -96, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -101, 0, 2, 1, 6 },
    { -90, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -83, 0, 2, 1, 6 },
    { -88, 0, 2, 1, 6 },
    { -80, 0, 2, 1, 6 },
    { -92, 0, 2, 1, 6 },
    { -88, -3, 2, 1, 6 },
    { -93, 0, 2, 1, 6 },
    { -91, 0, 2, 1, 6 },
    { -83, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -101, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -89, 0, 2, 1, 6 },
    { -103, 0, 2, 1, 6 },
    { -102, 0, 2, 1, 6 },
    { -77, 0, 2, 1, 6 },
    { -98, 0, 2, 1, 6 },
    { -96, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -86, 0, 2, 1, 7 },
    { -90, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -86, 0, 2, 1, 7 },
    { -86, 0, 2, 1, 7 },
    { -80, 0, 2, 1, 7 },
    { -90, 0, 2, 1, 7 },
    { -88, -3, 2, 1, 7 },
    { -93, 0, 2, 1, 7 },
    { -97, 0, 2, 1, 7 },
    { -86, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -86, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -89, 0, 2, 1, 7 },
    { -105, 0, 2, 1, 7 },
    { -103, 0, 2, 1, 7 },
    { -77, 0, 2, 1, 7 },
    { -99, 0, 2, 1, 7 },
    { -92, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -82, 0, 2, 1, 8 },
    { -102, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -86, 0, 2, 1, 8 },
    { -88, 0, 2, 1, 8 },
    { -85, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -94, 0, 2, 1, 8 },
    { -93, 0, 2, 1, 8 },
    { -89, 0, 2, 1, 8 },
    { -86, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -82, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -91, 0, 2, 1, 8 },
    { -105, 0, 2, 1, 8 },
    { -111, 0, 2, 1, 8 },
    { -77, 0, 2, 1, 8 },
    { -100, 0, 2, 1, 8 },
    { -92, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -82, 0, 2, 1, 9 },
    { -102, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 9 },
    { -90, 0, 2, 1, 9 },
    { -88, 0, 2, 1, 9 },
    { -85, 0, 2, 1, 9 },
    { -90, 0, 2, 1, 9 },
    { -93, 0, 2, 1, 9 },
    { -93, 0, 2, 1, 9 },
    { -92, 0, 2, 1, 9 },
    { -90, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 9 },
    { -82, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 9 },
    { -107, 0, 2, 1, 9 },
    { -115, 0, 2, 1, 9 },
    { -77, 0, 2, 1, 9 },
    { -108, 0, 2, 1, 9 },
    { -92, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -87, 0, 2, 1, 10 },
    { -95, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -94, 0, 2, 1, 10 },
    { -84, 0, 2, 1, 10 },
    { -85, 0, 2, 1, 10 },
    { -100, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 10 },
    { -93, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 10 },
    { -94, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -87, 0, 2, 1, 10 },
    { -102, 0, 2, 1, 10 },
    { -115, 0, 2, 1, 10 },
    { -74, 0, 2, 1, 10 },
    { -108, 0, 2, 1, 10 },
    { -100, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 11 },
    { -111, 0, 2, 1, 11 },
    { -85, 0, 2, 1, 11 },
    { -94, 0, 2, 1, 11 },
    { -83, 0, 2, 1, 11 },
    { -84, 0, 2, 1, 11 },
    { -99, 0, 2, 1, 11 },
    { -96, 0, 2, 1, 11 },
    { -93, 0, 2, 1, 11 },
    { -89, 0, 2, 1, 11 },
    { -94, 0, 2, 1, 11 },
    { -85, 0, 2, 1, 11 },
    { -85, 0, 2, 1, 11 },
    { -92, 0, 2, 1, 11 },
    { -85, 0, 2, 1, 11 },
    { -85, 0, 2, 1, 11 },
    { -104, 0, 2, 1, 11 },
    { -121, 0, 2, 1, 11 },
    { -83, 0, 2, 1, 11 },
    { -108, 0, 2, 1, 11 },
    { -112, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -83, 0, 2, 1, 12 },
    { -102, 0, 2, 1, 12 },
    { -82, 0, 2, 1, 12 },
    { -91, 0, 2, 1, 12 },
    { -88, 0, 2, 1, 12 },
    { -84, 0, 2, 1, 12 },
    { -95, 0, 2, 1, 12 },
    { -96, 0, 2, 1, 12 },
    { -93, 0, 2, 1, 12 },
    { -92, 0, 2, 1, 12 },
    { -91, 0, 2, 1, 12 },
    { -82, 0, 2, 1, 12 },
    { -82, 0, 2, 1, 12 },
    { -83, 0, 2, 1, 12 },
    { -82, 0, 2, 1, 12 },
    { -82, 0, 2, 1, 12 },
    { -107, 0, 2, 1, 12 },
    { -123, 0, 2, 1, 12 },
    { -99, 0, 2, 1, 12 },
    { -106, 0, 2, 1, 12 },
    { -104, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -101, -16, 2, 1, 13 },
    { -95, 0, 2, 1, 13 },
    { -100, 14, 2, 1, 13 },
    { -73, 2, 2, 1, 13 },
    { -109, -11, 2, 1, 13 },
    { -112, -15, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -79, 0, 2, 1, 13 },
    { -91, -22, 2, 1, 13 },
    { -87, 0, 2, 1, 13 },
    { -73, 2, 2, 1, 13 },
    { -100, 14, 2, 1, 13 },
    { -100, 14, 2, 1, 13 },
    { -101, -16, 2, 1, 13 },
    { -100, 14, 2, 1, 13 },
    { -100, 14, 2, 1, 13 },
    { -88, 6, 2, 1, 13 },
    { -90, 0, 2, 1, 13 },
    { -121, 0, 2, 1, 13 },
    { -111, -13, 2, 1, 13 },
    { -106, -8, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { -101, 40, 2, 1, 14 },
    { -92, 73, 2, 1, 14 },
    { -88, 36, 2, 1, 14 },
    { -53, 67, 2, 1, 14 },
    { -101, 31, 2, 1, 14 },
    { -106, 32, 2, 1, 14 },
    { -106, 174, 2, 1, 14 },
    { -85, 46, 2, 1, 14 },
    { -69, 114, 2, 1, 14 },
    { -103, 72, 2, 1, 14 },
    { -53, 67, 2, 1, 14 },
    { -88, 36, 2, 1, 14 },
    { -88, 36, 2, 1, 14 },
    { -101, 40, 2, 1, 14 },
    { -88, 36, 2, 1, 14 },
    { -88, 36, 2, 1, 14 },
    { -95, 50, 2, 1, 14 },
    { -95, 29, 2, 1, 14 },
    { -107, 51, 2, 1, 14 },
    { -106, 24, 2, 1, 14 },
    { -112, 38, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { -59, 81, 2, 1, 15 },
    { -68, 107, 2, 1, 15 },
    { -38, 138, 2, 1, 15 },
    { -45, 103, 2, 1, 15 },
    { -69, 95, 2, 1, 15 },
    { -77, 145, 2, 1, 15 },
    { -86, 213, 2, 1, 15 },
    { -28, 100, 2, 1, 15 },
    { -57, 96, 2, 1, 15 },
    { -49, 108, 2, 1, 15 },
    { -45, 103, 2, 1, 15 },
    { -38, 138, 2, 1, 15 },
    { -38, 138, 2, 1, 15 },
    { -59, 81, 2, 1, 15 },
    { -38, 138, 2, 1, 15 },
    { -38, 138, 2, 1, 15 },
    { -74, 98, 2, 1, 15 },
    { -60, 105, 2, 1, 15 },
    { -104, 132, 2, 1, 15 },
    { -77, 145, 2, 1, 15 },
    { -62, 192, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 46, 164, 2, 1, 16 },
    { 68, 173, 2, 1, 16 },
    { 71, 264, 2, 1, 16 },
    { 55, 262, 2, 1, 16 },
    { 88, 277, 2, 1, 16 },
    { 51, 160, 2, 1, 16 },
    { 52, 167, 2, 1, 16 },
    { 23, 151, 2, 1, 16 },
    { 20, 141, 2, 1, 16 },
    { 63, 273, 2, 1, 16 },
    { 55, 262, 2, 1, 16 },
    { 71, 264, 2, 1, 16 },
    { 71, 264, 2, 1, 16 },
    { 46, 164, 2, 1, 16 },
    { 71, 264, 2, 1, 16 },
    { 71, 264, 2, 1, 16 },
    { 89, 255, 2, 1, 16 },
    { 88, 279, 2, 1, 16 },
    { -32, 156, 2, 1, 16 },
    { 56, 176, 2, 1, 16 },
    { 62, 166, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 101, 127, 2, 1, 17 },
    { 112, 237, 2, 1, 17 },
    { 117, 234, 2, 1, 17 },
    { 99, 224, 2, 1, 17 },
    { 89, 186, 2, 1, 17 },
    { 117, 197, 2, 1, 17 },
    { 109, 199, 2, 1, 17 },
    { 95, 261, 2, 1, 17 },
    { 106, 112, 2, 1, 17 },
    { 71, 136, 2, 1, 17 },
    { 99, 224, 2, 1, 17 },
    { 117, 234, 2, 1, 17 },
    { 117, 234, 2, 1, 17 },
    { 101, 127, 2, 1, 17 },
    { 117, 234, 2, 1, 17 },
    { 117, 234, 2, 1, 17 },
    { 128, 224, 2, 1, 17 },
    { 125, 172, 2, 1, 17 },
    { 108, 251, 2, 1, 17 },
    { 69, 197, 2, 1, 17 },
    { 94, 202, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 97, 211, 2, 1, 18 },
    { 81, 220, 2, 1, 18 },
    { 89, 203, 2, 1, 18 },
    { 61, 188, 2, 1, 18 },
    { 79, 193, 2, 1, 18 },
    { 36, 194, 2, 1, 18 },
    { 51, 209, 2, 1, 18 },
    { 82, 199, 2, 1, 18 },
    { 92, 80, 2, 1, 18 },
    { 69, 120, 2, 1, 18 },
    { 61, 188, 2, 1, 18 },
    { 89, 203, 2, 1, 18 },
    { 89, 203, 2, 1, 18 },
    { 97, 211, 2, 1, 18 },
    { 89, 203, 2, 1, 18 },
    { 89, 203, 2, 1, 18 },
    { 93, 189, 2, 1, 18 },
    { 91, 112, 2, 1, 18 },
    { 127, 106, 2, 1, 18 },
    { 85, 210, 2, 1, 18 },
    { 110, 204, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 95, 213, 2, 1, 19 },
    { 131, 237, 2, 1, 19 },
    { 71, 196, 2, 1, 19 },
    { 80, 204, 2, 1, 19 },
    { 61, 194, 2, 1, 19 },
    { 77, 185, 2, 1, 19 },
    { 54, 216, 2, 1, 19 },
    { 80, 212, 2, 1, 19 },
    { 96, 83, 2, 1, 19 },
    { 127, 105, 2, 1, 19 },
    { 80, 204, 2, 1, 19 },
    { 71, 196, 2, 1, 19 },
    { 71, 196, 2, 1, 19 },
    { 95, 213, 2, 1, 19 },
    { 71, 196, 2, 1, 19 },
    { 71, 196, 2, 1, 19 },
    { 99, 204, 2, 1, 19 },
    { 78, 96, 2, 1, 19 },
    { 67, 112, 2, 1, 19 },
    { 95, 190, 2, 1, 19 },
    { 88, 206, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 33, 177, 2, 1, 20 },
    { 45, 221, 2, 1, 20 },
    { 35, 194, 2, 1, 20 },
    { -8, 192, 2, 1, 20 },
    { 36, 228, 2, 1, 20 },
    { 40, 211, 2, 1, 20 },
    { 45, 214, 2, 1, 20 },
    { 61, 159, 2, 1, 20 },
    { -17, 218, 2, 1, 20 },
    { 34, 156, 2, 1, 20 },
    { -8, 192, 2, 1, 20 },
    { 35, 194, 2, 1, 20 },
    { 35, 194, 2, 1, 20 },
    { 33, 177, 2, 1, 20 },
    { 35, 194, 2, 1, 20 },
    { 35, 194, 2, 1, 20 },
    { 42, 177, 2, 1, 20 },
    { 24, 158, 2, 1, 20 },
    { 75, 175, 2, 1, 20 },
    { 40, 205, 2, 1, 20 },
    { 40, 192, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { -141, 81, 2, 1, 21 },
    { -121, 207, 2, 1, 21 },
    { -156, 191, 2, 1, 21 },
    { -98, 105, 2, 1, 21 },
    { -172, 166, 2, 1, 21 },
    { -108, 221, 2, 1, 21 },
    { -114, 59, 2, 1, 21 },
    { -140, 81, 2, 1, 21 },
    { -107, 88, 2, 1, 21 },
    { -155, 178, 2, 1, 21 },
    { -98, 105, 2, 1, 21 },
    { -156, 191, 2, 1, 21 },
    { -156, 191, 2, 1, 21 },
    { -141, 81, 2, 1, 21 },
    { -156, 191, 2, 1, 21 },
    { -156, 191, 2, 1, 21 },
    { -160, 90, 2, 1, 21 },
    { -149, 100, 2, 1, 21 },
    { -187, 87, 2, 1, 21 },
    { -108, 236, 2, 1, 21 },
    { -146, 86, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { -165, -60, 2, 1, 22 },
    { -179, -17, 2, 1, 22 },
    { -177, -9, 2, 1, 22 },
    { -167, -2, 2, 1, 22 },
    { -182, -28, 2, 1, 22 },
    { -174, -31, 2, 1, 22 },
    { -155, -43, 2, 1, 22 },
    { -168, 0, 2, 1, 22 },
    { -157, -17, 2, 1, 22 },
    { -157, 0, 2, 1, 22 },
    { -167, -2, 2, 1, 22 },
    { -177, -9, 2, 1, 22 },
    { -177, -9, 2, 1, 22 },
    { -165, -60, 2, 1, 22 },
    { -177, -9, 2, 1, 22 },
    { -177, -9, 2, 1, 22 },
    { -180, -40, 2, 1, 22 },
    { -157, 0, 2, 1, 22 },
    { -220, -16, 2, 1, 22 },
    { -168, -40, 2, 1, 22 },
    { -170, -14, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { -159, 0, 2, 1, 23 },
    { -180, 0, 2, 1, 23 },
    { -141, 0, 2, 1, 23 },
    { -134, 0, 2, 1, 23 },
    { -131, 0, 2, 1, 23 },
    { -158, 0, 2, 1, 23 },
    { -134, 0, 2, 1, 23 },
    { -173, 0, 2, 1, 23 },
    { -151, 2, 2, 1, 23 },
    { -150, -29, 2, 1, 23 },
    { -134, 0, 2, 1, 23 },
    { -141, 0, 2, 1, 23 },
    { -141, 0, 2, 1, 23 },
    { -159, 0, 2, 1, 23 },
    { -141, 0, 2, 1, 23 },
    { -141, 0, 2, 1, 23 },
    { -173, 0, 2, 1, 23 },
    { -154, 0, 2, 1, 23 },
    { -194, -5, 2, 1, 23 },
    { -136, 0, 2, 1, 23 },
    { -136, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { -159, 0, 2, 1, 24 },
    { -180, 0, 2, 1, 24 },
    { -141, 0, 2, 1, 24 },
    { -134, 0, 2, 1, 24 },
    { -131, 0, 2, 1, 24 },
    { -158, 0, 2, 1, 24 },
    { -134, 0, 2, 1, 24 },
    { -173, 0, 2, 1, 24 },
    { -151, 2, 2, 1, 24 },
    { -150, -29, 2, 1, 24 },
    { -134, 0, 2, 1, 24 },
    { -141, 0, 2, 1, 24 },
    { -141, 0, 2, 1, 24 },
    { -159, 0, 2, 1, 24 },
    { -141, 0, 2, 1, 24 },
    { -141, 0, 2, 1, 24 },
    { -173, 0, 2, 1, 24 },
    { -154, 0, 2, 1, 24 },
    { -194, -5, 2, 1, 24 },
    { -158, 0, 2, 1, 24 },
    { -158, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { -26, 0, 2, 1, 1 },
    { -21, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -42, 0, 2, 1, 1 },
    { -18, 0, 2, 1, 1 },
    { -34, 0, 2, 1, 1 },
    { -32, 0, 1, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -44, 0, 2, 1, 1 },
    { -28, 0, 2, 1, 1 },
    { -42, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -26, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { -43, 0, 2, 1, 1 },
    { -54, 0, 2, 1, 1 },
    { -10, 0, 2, 1, 1 },
    { -48, -7, 2, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -24, 0, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -29, 0, 2, 1, 2 },
    { -17, 0, 2, 1, 2 },
    { -34, 0, 2, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -20, 0, 2, 1, 2 },
    { -27, 0, 2, 1, 2 },
    { -26, 2, 2, 1, 2 },
    { -29, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 2 },
    { -32, 5, 2, 1, 2 },
    { -10, 0, 2, 1, 2 },
    { -32, 1, 2, 1, 2 },
    { -34, 4, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -21, 0, 2, 1, 3 },
    { -10, 0, 2, 1, 3 },
    { -14, 0, 2, 1, 3 },
    { -20, 0, 2, 1, 3 },
    { -8, 0, 2, 1, 3 },
    { -20, -1, 2, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -15, 3, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -20, 6, 2, 1, 3 },
    { -20, 0, 2, 1, 3 },
    { -14, 0, 2, 1, 3 },
    { -14, 0, 2, 1, 3 },
    { -21, 0, 2, 1, 3 },
    { -14, 0, 2, 1, 3 },
    { -14, 0, 2, 1, 3 },
    { -34, 0, 2, 1, 3 },
    { -24, 9, 2, 1, 3 },
    { -7, 0, 2, 1, 3 },
    { -23, 6, 2, 1, 3 },
    { -24, 6, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -27, -7, 2, 1, 4 },
    { -10, 0, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -8, 2, 2, 1, 4 },
    { -6, 0, 2, 1, 4 },
    { -19, 15, 2, 1, 4 },
    { -11, 0, 2, 1, 4 },
    { -9, 10, 2, 1, 4 },
    { -17, 0, 2, 1, 4 },
    { -8, 13, 2, 1, 4 },
    { -8, 2, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -27, -7, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -31, 0, 2, 1, 4 },
    { -17, 16, 2, 1, 4 },
    { -15, 0, 2, 1, 4 },
    { -15, 10, 2, 1, 4 },
    { -10, 8, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -26, -4, 2, 1, 5 },
    { -4, 0, 2, 1, 5 },
    { -14, 6, 2, 1, 5 },
    { -5, 10, 2, 1, 5 },
    { 3, 11, 2, 1, 5 },
    { -20, 19, 2, 1, 5 },
    { -3, 3, 2, 1, 5 },
    { -12, 13, 2, 1, 5 },
    { -17, 3, 2, 1, 5 },
    { -1, 17, 2, 1, 5 },
    { -5, 10, 2, 1, 5 },
    { -14, 6, 2, 1, 5 },
    { -14, 6, 2, 1, 5 },
    { -26, -4, 2, 1, 5 },
    { -14, 6, 2, 1, 5 },
    { -14, 6, 2, 1, 5 },
    { -23, 9, 2, 1, 5 },
    { -11, 20, 2, 1, 5 },
    { -10, 1, 2, 1, 5 },
    { -3, 12, 2, 1, 5 },
    { -4, 10, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -18, 4, 2, 1, 6 },
    { -13, -2, 2, 1, 6 },
    { -11, 14, 2, 1, 6 },
    { -3, 13, 2, 1, 6 },
    { 1, 16, 2, 1, 6 },
    { -18, 31, 2, 1, 6 },
    { -6, 4, 2, 1, 6 },
    { -12, 13, 2, 1, 6 },
    { -20, -12, 2, 1, 6 },
    { -6, 19, 2, 1, 6 },
    { -3, 13, 2, 1, 6 },
    { -11, 14, 2, 1, 6 },
    { -11, 14, 2, 1, 6 },
    { -18, 4, 2, 1, 6 },
    { -11, 14, 2, 1, 6 },
    { -11, 14, 2, 1, 6 },
    { -21, 13, 2, 1, 6 },
    { -10, 23, 2, 1, 6 },
    { -10, 1, 2, 1, 6 },
    { -1, 15, 2, 1, 6 },
    { -17, 12, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -11, 14, 2, 1, 7 },
    { -10, 8, 2, 1, 7 },
    { -4, 22, 2, 1, 7 },
    { -2, 19, 2, 1, 7 },
    { 1, 20, 2, 1, 7 },
    { -21, 27, 2, 1, 7 },
    { -1, 10, 2, 1, 7 },
    { -1, 9, 2, 1, 7 },
    { -20, 18, 2, 1, 7 },
    { -2, 25, 2, 1, 7 },
    { -2, 19, 2, 1, 7 },
    { -4, 22, 2, 1, 7 },
    { -4, 22, 2, 1, 7 },
    { -11, 14, 2, 1, 7 },
    { -4, 22, 2, 1, 7 },
    { -4, 22, 2, 1, 7 },
    { -37, 29, 2, 1, 7 },
    { -6, 27, 2, 1, 7 },
    { -10, 1, 2, 1, 7 },
    { -7, 16, 2, 1, 7 },
    { -9, 14, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -13, 9, 2, 1, 8 },
    { -17, -2, 2, 1, 8 },
    { -5, 20, 2, 1, 8 },
    { 5, 31, 2, 1, 8 },
    { -5, 14, 2, 1, 8 },
    { -19, 29, 2, 1, 8 },
    { 0, 15, 2, 1, 8 },
    { -8, 16, 2, 1, 8 },
    { -17, 21, 2, 1, 8 },
    { -8, 25, 2, 1, 8 },
    { 5, 31, 2, 1, 8 },
    { -5, 20, 2, 1, 8 },
    { -5, 20, 2, 1, 8 },
    { -13, 9, 2, 1, 8 },
    { -5, 20, 2, 1, 8 },
    { -5, 20, 2, 1, 8 },
    { -35, 23, 2, 1, 8 },
    { -3, 32, 2, 1, 8 },
    { -9, 1, 2, 1, 8 },
    { -9, 19, 2, 1, 8 },
    { -12, 16, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -13, 5, 2, 1, 9 },
    { -15, -3, 2, 1, 9 },
    { -14, 19, 2, 1, 9 },
    { -11, 27, 2, 1, 9 },
    { -26, 26, 2, 1, 9 },
    { -10, 26, 2, 1, 9 },
    { -6, 24, 2, 1, 9 },
    { -8, 18, 2, 1, 9 },
    { -13, 28, 2, 1, 9 },
    { -19, 35, 2, 1, 9 },
    { -11, 27, 2, 1, 9 },
    { -14, 19, 2, 1, 9 },
    { -14, 19, 2, 1, 9 },
    { -13, 5, 2, 1, 9 },
    { -14, 19, 2, 1, 9 },
    { -14, 19, 2, 1, 9 },
    { -28, 23, 2, 1, 9 },
    { -3, 31, 2, 1, 9 },
    { -9, 10, 2, 1, 9 },
    { -10, 20, 2, 1, 9 },
    { -2, 10, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -19, 7, 2, 1, 10 },
    { -17, -5, 2, 1, 10 },
    { -14, 18, 2, 1, 10 },
    { -11, 26, 2, 1, 10 },
    { -26, 26, 2, 1, 10 },
    { -7, 26, 2, 1, 10 },
    { -6, 23, 2, 1, 10 },
    { -13, 18, 2, 1, 10 },
    { -13, 27, 2, 1, 10 },
    { -19, 33, 2, 1, 10 },
    { -11, 26, 2, 1, 10 },
    { -14, 18, 2, 1, 10 },
    { -14, 18, 2, 1, 10 },
    { -19, 7, 2, 1, 10 },
    { -14, 18, 2, 1, 10 },
    { -14, 18, 2, 1, 10 },
    { -13, 21, 2, 1, 10 },
    { -3, 29, 2, 1, 10 },
    { -9, 9, 2, 1, 10 },
    { -10, 18, 2, 1, 10 },
    { -2, 10, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -19, 5, 2, 1, 11 },
    { -17, 1, 2, 1, 11 },
    { -13, 17, 2, 1, 11 },
    { -16, 13, 2, 1, 11 },
    { -27, 22, 2, 1, 11 },
    { -11, 25, 2, 1, 11 },
    { -6, 20, 2, 1, 11 },
    { -16, 14, 2, 1, 11 },
    { -14, 23, 2, 1, 11 },
    { -22, 28, 2, 1, 11 },
    { -16, 13, 2, 1, 11 },
    { -13, 17, 2, 1, 11 },
    { -13, 17, 2, 1, 11 },
    { -19, 5, 2, 1, 11 },
    { -13, 17, 2, 1, 11 },
    { -13, 17, 2, 1, 11 },
    { -14, 20, 2, 1, 11 },
    { -2, 26, 2, 1, 11 },
    { -10, 5, 2, 1, 11 },
    { -10, 18, 2, 1, 11 },
    { -4, 10, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -18, 11, 2, 1, 12 },
    { -19, 8, 2, 1, 12 },
    { -18, 16, 2, 1, 12 },
    { -11, 17, 2, 1, 12 },
    { -18, 9, 2, 1, 12 },
    { -30, 19, 2, 1, 12 },
    { -9, 24, 2, 1, 12 },
    { -19, 19, 2, 1, 12 },
    { -22, 38, 2, 1, 12 },
    { -11, 15, 2, 1, 12 },
    { -11, 17, 2, 1, 12 },
    { -18, 16, 2, 1, 12 },
    { -18, 16, 2, 1, 12 },
    { -18, 11, 2, 1, 12 },
    { -18, 16, 2, 1, 12 },
    { -18, 16, 2, 1, 12 },
    { -8, 18, 2, 1, 12 },
    { -4, 27, 2, 1, 12 },
    { -12, 7, 2, 1, 12 },
    { -10, 23, 2, 1, 12 },
    { -2, 22, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -18, 8, 2, 1, 13 },
    { -35, 21, 2, 1, 13 },
    { -21, 17, 2, 1, 13 },
    { -11, 16, 2, 1, 13 },
    { -22, 12, 2, 1, 13 },
    { -28, 17, 2, 1, 13 },
    { -9, 22, 2, 1, 13 },
    { -20, 15, 2, 1, 13 },
    { -18, 29, 2, 1, 13 },
    { -11, 12, 2, 1, 13 },
    { -11, 16, 2, 1, 13 },
    { -21, 17, 2, 1, 13 },
    { -21, 17, 2, 1, 13 },
    { -18, 8, 2, 1, 13 },
    { -21, 17, 2, 1, 13 },
    { -21, 17, 2, 1, 13 },
    { -10, 17, 2, 1, 13 },
    { -5, 25, 2, 1, 13 },
    { -13, 4, 2, 1, 13 },
    { -10, 19, 2, 1, 13 },
    { -2, 10, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { -21, 8, 2, 1, 14 },
    { -14, 3, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -14, 16, 2, 1, 14 },
    { -19, 20, 2, 1, 14 },
    { -6, 25, 2, 1, 14 },
    { -5, 23, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -18, 31, 2, 1, 14 },
    { -12, 14, 2, 1, 14 },
    { -14, 16, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -21, 8, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -20, 21, 2, 1, 14 },
    { -12, 19, 2, 1, 14 },
    { 1, 28, 2, 1, 14 },
    { -11, 6, 2, 1, 14 },
    { -10, 20, 2, 1, 14 },
    { -4, 10, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { -13, 5, 2, 1, 15 },
    { -17, -3, 2, 1, 15 },
    { -14, 19, 2, 1, 15 },
    { -11, 27, 2, 1, 15 },
    { -26, 26, 2, 1, 15 },
    { -9, 26, 2, 1, 15 },
    { -4, 24, 2, 1, 15 },
    { -8, 18, 2, 1, 15 },
    { -13, 28, 2, 1, 15 },
    { -19, 35, 2, 1, 15 },
    { -11, 27, 2, 1, 15 },
    { -14, 19, 2, 1, 15 },
    { -14, 19, 2, 1, 15 },
    { -13, 5, 2, 1, 15 },
    { -14, 19, 2, 1, 15 },
    { -14, 19, 2, 1, 15 },
    { -28, 23, 2, 1, 15 },
    { -3, 31, 2, 1, 15 },
    { -9, 10, 2, 1, 15 },
    { -10, 20, 2, 1, 15 },
    { -2, 10, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { -13, 5, 2, 1, 16 },
    { -17, 0, 2, 1, 16 },
    { -14, 20, 2, 1, 16 },
    { -11, 27, 2, 1, 16 },
    { -26, 26, 2, 1, 16 },
    { -9, 26, 2, 1, 16 },
    { -4, 24, 2, 1, 16 },
    { -8, 18, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -19, 35, 2, 1, 16 },
    { -11, 27, 2, 1, 16 },
    { -14, 20, 2, 1, 16 },
    { -14, 20, 2, 1, 16 },
    { -13, 5, 2, 1, 16 },
    { -14, 20, 2, 1, 16 },
    { -14, 20, 2, 1, 16 },
    { -28, 23, 2, 1, 16 },
    { -3, 31, 2, 1, 16 },
    { -9, 10, 2, 1, 16 },
    { -10, 20, 2, 1, 16 },
    { -2, 10, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 18, 110, 2, 1, 19 },
    { 18, 115, 2, 1, 19 },
    { 14, 122, 2, 1, 19 },
    { 3, 116, 2, 1, 19 },
    { 14, 96, 2, 1, 19 },
    { 19, 104, 2, 1, 19 },
    { 23, 91, 2, 1, 19 },
    { 2, 107, 2, 1, 19 },
    { 4, 154, 2, 1, 19 },
    { 27, 112, 2, 1, 19 },
    { 3, 116, 2, 1, 19 },
    { 14, 122, 2, 1, 19 },
    { 14, 122, 2, 1, 19 },
    { 18, 110, 2, 1, 19 },
    { 14, 122, 2, 1, 19 },
    { 14, 122, 2, 1, 19 },
    { -13, 120, 2, 1, 19 },
    { 3, 128, 2, 1, 19 },
    { -34, 128, 2, 1, 19 },
    { -32, 92, 2, 1, 19 },
    { -30, 124, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
};

/* extra scripts: 47 entries */
const u16* const no12_exca[48] = {
    no12_exca_000,  /* 0 follow-up of AIR NORMAL */
    no12_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    no12_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    no12_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    no12_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    no12_exca_005,  /* 5 follow-up of MONKEY FLIP, SNAKE FANG +3 */
    no12_exca_006,  /* 6 follow-up of NOKEZORI, UPPER +22 */
    no12_exca_007,  /* 7 follow-up of KUNOJI, DUDDLEY D S */
    no12_exca_008,  /* 8 follow-up of TATAKI S, KGM TATAKI S +1 */
    no12_exca_009,  /* 9 follow-up of KIRIMOMI, FLANKEN.S +4 */
    no12_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    no12_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    no12_exca_012,  /* 12 follow-up of APPEAR JUNBI 4, APPEAR JUNBI 5 */
    no12_exca_013,  /* 13 follow-up of APPEAR JUNBI 5 */
    no12_exca_014,  /* 14 follow-up of ATTACK 1 S, ATTACK 1 M +3 */
    no12_exca_014,  /* 15 follow-up of APPEAR 8 */
    no12_exca_016,  /* 16 follow-up of SP APPEAR 1 */
    no12_exca_017,  /* 17 follow-up of SP APPEAR 1 */
    no12_exca_018,  /* 18 follow-up of APPEAR 7 */
    no12_exca_019,  /* 19 follow-up of APPEAR 7 */
    no12_exca_020,  /* 20 no name */
    no12_exca_021,  /* 21 follow-up of HARAIGOSHI */
    no12_exca_020,  /* 22 no name */
    no12_exca_023,  /* 23 follow-up of APPEAR JUNBI 7 */
    no12_exca_024,  /* 24 follow-up of APPEAR JUNBI 7 */
    no12_exca_020,  /* 25 no name */
    no12_exca_026,  /* 26 no name */
    no12_exca_027,  /* 27 no name */
    no12_exca_028,  /* 28 follow-up of HUMI ASIB */
    no12_exca_029,  /* 29 no name */
    no12_exca_030,  /* 30 follow-up of SP APPEAR 6 */
    no12_exca_031,  /* 31 follow-up of SP APPEAR 6 */
    no12_exca_032,  /* 32 follow-up of GILL IMPACT C */
    no12_exca_033,  /* 33 follow-up of GILL IMPACT C */
    no12_exca_034,  /* 34 follow-up of SP APPEAR 7 */
    no12_exca_035,  /* 35 follow-up of SP APPEAR 7 */
    no12_exca_036,  /* 36 follow-up of ZANNEN 1 */
    no12_exca_037,  /* 37 follow-up of ZANNEN 1 */
    no12_exca_036,  /* 38 follow-up of ZANNEN 2 */
    no12_exca_037,  /* 39 follow-up of ZANNEN 2 */
    no12_exca_040,  /* 40 follow-up of ZANNEN 3 */
    no12_exca_041,  /* 41 follow-up of ZANNEN 3 */
    no12_exca_042,  /* 42 follow-up of ATTACK 11 SP */
    no12_exca_042,  /* 43 no name */
    no12_exca_044,  /* 44 follow-up of SP APPEAR 3 */
    no12_exca_045,  /* 45 follow-up of SP APPEAR 3 */
    no12_exca_046,  /* 46 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 no12_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_exca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C60, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C55, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C54, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C53, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C52, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C51, 0, 495, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C50, 0, 495, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C50, 0, 495, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C5B, 0, 495, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 495, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 495, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3 */
const u16 no12_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_001[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 no12_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_003[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E71, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 9, 0, 0, 0, 0, 0, 0x6E03, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 no12_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_004[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of MONKEY FLIP, SNAKE FANG +3 */
const u16 no12_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_005[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E25, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E26, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, UPPER +22 */
const u16 no12_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_006[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E39, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E3A, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E3B, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E3C, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E3D, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E3E, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E3F, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, DUDDLEY D S */
const u16 no12_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_007[76] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI S, KGM TATAKI S +1 */
const u16 no12_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_008[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E25, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E26, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, FLANKEN.S +4 */
const u16 no12_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_009[76] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3 */
const u16 no12_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_010[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4, APPEAR JUNBI 5 */
const u16 no12_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_012[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 5 */
const u16 no12_exca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_013[20] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 4, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of ATTACK 1 S, ATTACK 1 M +3, 15 follow-up of APPEAR 8 */
const u16 no12_exca_014_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_014[508] = {
    CMD(CM_MVIX, 51, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 14, 27), 0, 0, 0, 0,
    CMD(CM_MVIX, 52, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 14, 27), 0, 0, 0, 0,
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 14, 27), 0, 0, 0, 0,
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 14, 27), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E15, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E16, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E17, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E18, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E19, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E12, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E15, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E16, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E17, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E18, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E19, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E12, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x6E1A, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E05, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E06, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E07, 0, 497, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 498, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 499, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 500, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6DE9, 0, 500, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2000, 0x0000, 0x0000,
    CMD(CM_MVIX, 51, 0, 0), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_MVIX, 52, 0, 0), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6F74, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 268, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x6F76, 0, 269, 0, 0, 0, 0, 0),
    L4(1, 20, 273, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of SP APPEAR 1 */
const u16 no12_exca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_016[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of SP APPEAR 1 */
const u16 no12_exca_017_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_017[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 follow-up of APPEAR 7 */
const u16 no12_exca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_018[84] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 follow-up of APPEAR 7 */
const u16 no12_exca_019_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_019[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name, 22 no name, 25 no name */
const u16 no12_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_exca_020[20] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of HARAIGOSHI */
const u16 no12_exca_021_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_021[92] = {
    L4(2, 2, 0, 0, 1, 0, 0, 0x6E25, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x6E26, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 1, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 7 */
const u16 no12_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_023[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E8B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 7 */
const u16 no12_exca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_024[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E8B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 no name */
const u16 no12_exca_026_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_026[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E8B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 no name */
const u16 no12_exca_027_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_027[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E8B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of HUMI ASIB */
const u16 no12_exca_028_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_028[100] = {
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E3B, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E3C, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E3D, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E3E, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E3F, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 no12_exca_029_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_029[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of SP APPEAR 6 */
const u16 no12_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_030[52] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x6C2C, 0, 96, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of SP APPEAR 6 */
const u16 no12_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_031[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 97, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of GILL IMPACT C */
const u16 no12_exca_032_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_032[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E71, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E04, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of GILL IMPACT C */
const u16 no12_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 no12_exca_033[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6E71, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E27, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E28, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6E29, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6E2A, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2B, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2C, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6E2D, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6E2E, 0, 99, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6E04, 0, 99, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP APPEAR 7 */
const u16 no12_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_034[92] = {
    L4(1, 3, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 7 */
const u16 no12_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_035[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of ZANNEN 1, 38 follow-up of ZANNEN 2 */
const u16 no12_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_036[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of ZANNEN 1, 39 follow-up of ZANNEN 2 */
const u16 no12_exca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_037[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of ZANNEN 3 */
const u16 no12_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_040[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of ZANNEN 3 */
const u16 no12_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_041[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of ATTACK 11 SP, 43 no name */
const u16 no12_exca_042_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_042[196] = {
    CMD(CM_MVIX, 61, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 32, 57),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E15, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E16, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E17, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E18, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E19, 0, 425, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6E12, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E13, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6E14, 0, 425, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6E1A, 0, 425, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E05, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E06, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6E07, 0, 497, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6DE6, 0, 498, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6DE7, 0, 499, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DE8, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6DE9, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of SP APPEAR 3 */
const u16 no12_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_exca_044[84] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6C34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C26, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C27, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C28, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP APPEAR 3 */
const u16 no12_exca_045_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 no12_exca_045[44] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x6C22, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 no12_exca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 no12_exca_046[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C60, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 75 entries */
const u16* const no12_saca[76] = {
    no12_saca_000,  /* 0 UP P GUARD P S: after SA III 23623+P (routine Att_METAMORPHOSE) */
    no12_saca_001,  /* 1 UP P GUARD P M */
    no12_saca_002,  /* 2 UP P GUARD P L */
    no12_saca_002,  /* 3 UP P GUARD K S */
    no12_saca_002,  /* 4 UP P GUARD K M */
    no12_saca_002,  /* 5 UP P GUARD K L */
    no12_saca_000,  /* 6 D P GUARD P S: after SA III 23623+P (routine Att_METAMORPHOSE) */
    no12_saca_001,  /* 7 D P GUARD P M */
    no12_saca_002,  /* 8 D P GUARD P L */
    no12_saca_002,  /* 9 D P GUARD K S */
    no12_saca_002,  /* 10 D P GUARD K M */
    no12_saca_002,  /* 11 D P GUARD K L */
    no12_saca_012,  /* 12 FUSHIN P S */
    no12_saca_012,  /* 13 FUSHIN P M */
    no12_saca_012,  /* 14 FUSHIN P L */
    no12_saca_012,  /* 15 FUSHIN K S */
    no12_saca_012,  /* 16 FUSHIN K M */
    no12_saca_012,  /* 17 FUSHIN K L */
    no12_saca_018,  /* 18 OKIAGARI P S */
    no12_saca_018,  /* 19 OKIAGARI P M */
    no12_saca_018,  /* 20 OKIAGARI P L */
    no12_saca_018,  /* 21 OKIAGARI K S */
    no12_saca_018,  /* 22 OKIAGARI K M */
    no12_saca_018,  /* 23 OKIAGARI K L */
    no12_saca_024,  /* 24 ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU) */
    no12_saca_025,  /* 25 ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) */
    no12_saca_026,  /* 26 ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    no12_saca_027,  /* 27 ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    no12_saca_028,  /* 28 ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    no12_saca_029,  /* 29 ATTACK 2 M: air (147)544... (routine Att_AIRDASH) */
    no12_saca_028,  /* 30 ATTACK 2 L: air (369)566... (routine Att_AIRDASH) */
    no12_saca_028,  /* 31 ATTACK 2 SP: air (369)566... (routine Att_AIRDASH) */
    no12_saca_032,  /* 32 ATTACK 3 S: 214+P light (plain script) */
    no12_saca_033,  /* 33 ATTACK 3 M: 214+P medium (plain script) */
    no12_saca_034,  /* 34 ATTACK 3 L: 214+P heavy (plain script) */
    no12_saca_035,  /* 35 ATTACK 3 SP: EX 214+PP (plain script) */
    no12_saca_036,  /* 36 ATTACK 4 S: 236+P light (plain script) */
    no12_saca_037,  /* 37 ATTACK 4 M: 236+P medium (plain script) */
    no12_saca_038,  /* 38 ATTACK 4 L: 236+P heavy (plain script) */
    no12_saca_039,  /* 39 ATTACK 4 SP: EX 236+PP (plain script) */
    no12_saca_040,  /* 40 ATTACK 5 S: SA I 23623+P (plain script) */
    no12_saca_040,  /* 41 ATTACK 5 M: SA I 23623+P (plain script) */
    no12_saca_040,  /* 42 ATTACK 5 L: SA I 23623+P (plain script) */
    no12_saca_040,  /* 43 ATTACK 5 SP: SA I 23623+P (plain script) */
    no12_saca_000,  /* 44 ATTACK 6 S: after SA III 23623+P (routine Att_METAMORPHOSE) */
    no12_saca_045,  /* 45 ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E) */
    no12_saca_046,  /* 46 ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E) */
    no12_saca_047,  /* 47 ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) */
    no12_saca_048,  /* 48 ATTACK 7 S: air EX 214+PP (routine Att_AIR_A_X_E) */
    no12_saca_049,  /* 49 ATTACK 7 M: not started by a command */
    no12_saca_050,  /* 50 ATTACK 7 L: SA III 23623+P (routine Att_METAMORPHOSE) */
    no12_saca_051,  /* 51 ATTACK 7 SP: not started by a command */
    no12_saca_052,  /* 52 ATTACK 8 S: started by routine Att_METAMORPHOSE */
    no12_saca_053,  /* 53 ATTACK 8 M: not started by a command */
    no12_saca_054,  /* 54 ATTACK 8 L: not started by a command */
    no12_saca_054,  /* 55 ATTACK 8 SP: not started by a command */
    no12_saca_054,  /* 56 ATTACK 9 S: not started by a command */
    no12_saca_054,  /* 57 ATTACK 9 M: not started by a command */
    no12_saca_058,  /* 58 ATTACK 9 L: 236+K light (plain script) */
    no12_saca_059,  /* 59 ATTACK 9 SP: 236+K medium (plain script) */
    no12_saca_060,  /* 60 ATTACK 10 S: 236+K heavy (plain script) */
    no12_saca_061,  /* 61 ATTACK 10 M: EX 236+KK (plain script) */
    no12_saca_062,  /* 62 ATTACK 10 L: started by routine Att_pl19_TOKUSHUKOUDOU */
    no12_saca_063,  /* 63 ATTACK 10 SP: started by routine Att_pl19_TOKUSHUKOUDOU */
    no12_saca_064,  /* 64 ATTACK 11 S: started by routine Att_pl19_TOKUSHUKOUDOU */
    no12_saca_065,  /* 65 ATTACK 11 M: started by routine Att_AIRDASH */
    no12_saca_065,  /* 66 ATTACK 11 L: started by routine Att_AIRDASH */
    no12_saca_067,  /* 67 ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A) */
    no12_saca_068,  /* 68 ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A) */
    no12_saca_069,  /* 69 ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    no12_saca_069,  /* 70 ATTACK 12 L: after SA II air 23623+K (routine Att_SA__D_R_A) */
    no12_saca_071,  /* 71 ATTACK 12 SP: not started by a command */
    no12_saca_072,  /* 72 ATTACK 13 S: not started by a command */
    no12_saca_073,  /* 73 ATTACK 13 M: not started by a command */
    no12_saca_074,  /* 74 ATTACK 13 L: not started by a command */
    0
};

/* script: 0 UP P GUARD P S: after SA III 23623+P (routine Att_METAMORPHOSE), 6 D P GUARD P S: after SA III 23623+P (routine Att_METAMORPHOSE), 44 ATTACK 6 S: after SA III 23623+P (routine Att_METAMORPHOSE) */
const u16 no12_saca_000_head[4] = { HEAD(4, 22, 32, 0, 0, 0, 0) };
const u16 no12_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7136, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7137, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7138, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7139, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x7140, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, 1024, 5632), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 no12_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 no12_saca_001[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE4, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE8, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x6FE9, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x6FE9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FED, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEE, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF2, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF3, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF6, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 no12_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 no12_saca_002[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FUSHIN P S, 13 FUSHIN P M, 14 FUSHIN P L, 15 FUSHIN K S ... */
const u16 no12_saca_012_head[4] = { HEAD(2, 0, 0, 14, 0, 5, 0) };
const u16 no12_saca_012[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x6C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 OKIAGARI P S, 19 OKIAGARI P M, 20 OKIAGARI P L, 21 OKIAGARI K S ... */
const u16 no12_saca_018_head[4] = { HEAD(2, 0, 12, 8, 0, 7, 1) };
const u16 no12_saca_018[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU) */
const u16 no12_saca_024_head[4] = { HEAD(4, 22, 9, 13, 0, 1, 107) };
const u16 no12_saca_024[424] = {
    CMD(CM_JSR, 5, 24, 38), 0, 0, 0, 0,
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    CMD(CM_MVIX, 38, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 14, 0x6F71, -27, 255, 0, 71, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6F72, 0, 256, 0, 71, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 14, 0x6F73, 0, 257, 0, 64, 0, 0, 0),
    CMD(CM_HJMP, 16392, 16395, 16395), 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_MVIX, 39, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 267, 0, 0, 0, 21, 0),
    CMD(CM_MVIX, 51, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 268, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 7, 0x6F76, 0, 269, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 40, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_MVIX, 50, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    CMD(CM_MPCY, 0, 1, 16386), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 15, 0x6F77, 0, 270, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 13, 0x6F78, 0, 271, 0, 0, 0, 22, 24),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F79, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C58, 0, 273, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C57, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C56, 0, 275, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 15, 0x6F60, 0, 30, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F60, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F61, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F62, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F63, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F64, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F65, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F66, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F67, 0, 30, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 966, 0, 0, 0, 15, 0x6F68, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6F69, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6F6A, 0, 30, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
};

/* script: 25 ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) */
const u16 no12_saca_025_head[4] = { HEAD(4, 22, 11, 15, 0, 1, 107) };
const u16 no12_saca_025[300] = {
    CMD(CM_JSR, 5, 24, 38), 0, 0, 0, 0,
    CMD(CM_RJA, 7, 14, 5), 0, 0, 0, 0,
    CMD(CM_MVIX, 41, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 14, 0x6F6E, -28, 258, 0, 71, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6F6F, 0, 259, 0, 71, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 14, 0x6F70, 0, 260, 0, 64, 0, 0, 0),
    CMD(CM_HJMP, 16392, 16395, 16395), 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_MVIX, 42, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6F74, 0, 267, 0, 0, 0, 21, 0),
    CMD(CM_MVIX, 52, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 268, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 7, 0x6F76, 0, 269, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 43, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_MVIX, 50, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    CMD(CM_MPCY, 0, 1, 16386), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 15, 0x6F77, 0, 270, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 13, 0x6F78, 0, 271, 0, 0, 0, 22, 24),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F79, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C58, 0, 273, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C57, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C56, 0, 275, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
const u16 no12_saca_026_head[4] = { HEAD(4, 22, 12, 16, 0, 1, 107) };
const u16 no12_saca_026[300] = {
    CMD(CM_JSR, 5, 24, 38), 0, 0, 0, 0,
    CMD(CM_RJA, 7, 14, 9), 0, 0, 0, 0,
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 14, 0x6F6B, -29, 261, 0, 71, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x6F6C, 0, 262, 0, 71, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 14, 0x6F6D, 0, 263, 0, 64, 0, 0, 0),
    CMD(CM_HJMP, 16392, 16395, 16395), 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_MVIX, 48, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6F74, 0, 267, 0, 0, 0, 21, 0),
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 268, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 7, 0x6F76, 0, 269, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 49, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_MVIX, 50, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    CMD(CM_MPCY, 0, 1, 16386), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 15, 0x6F77, 0, 270, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 13, 0x6F78, 0, 271, 0, 0, 0, 22, 24),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F79, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C58, 0, 273, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C57, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C56, 0, 275, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C55, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C54, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6C53, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6C52, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x6C51, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x6C50, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x6C5B, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C5C, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C5D, 0, 32, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
const u16 no12_saca_027_head[4] = { HEAD(4, 22, 14, 16, 0, 2, 107) };
const u16 no12_saca_027[204] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 7, 14, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F60, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F61, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F63, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F65, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 966, 0, 0, 0, 15, 0x6F67, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F69, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F6A, 0, 30, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 15, 0x6F6B, -30, 264, 0, 144, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6F6C, -30, 265, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F6D, -30, 266, 0, 144, 0, 0, 0),
    CMD(CM_MPCY, 0, 1, -32767), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 15, 0x6F6D, 0, 266, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F6D, -31, 266, 0, 83, 0, 0, 0),
    CMD(CM_MPCY, 0, 1, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F6D, 0, 266, 0, 0, 0, 0, 0),
    CMD(CM_MPCY, 0, 1, -32767), 0, 0, 0, 0,
    CMD(CM_MVIX, 48, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6F74, 0, 267, 0, 0, 0, 21, 0),
    CMD(CM_MVIX, 53, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x6F75, 0, 268, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 7, 0x6F76, 0, 269, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: air (369)566... (routine Att_AIRDASH), 30 ATTACK 2 L: air (369)566... (routine Att_AIRDASH), 31 ATTACK 2 SP: air (369)566... (routine Att_AIRDASH) */
const u16 no12_saca_028_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 108) };
const u16 no12_saca_028[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 7, 1), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 28, 1), 0, 0, 0, 0,
    L4(4, 0, 964, 0, 0, 0, 0, 0x6F50, 0, 276, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F51, 0, 277, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x6F52, 0, 278, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F53, 0, 278, 8048, 0, 136, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F54, 0, 278, 8048, 0, 136, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F55, 0, 278, 8048, 0, 136, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 30, 0, 0, 0, 0, 0, 0x6F56, 0, 279, 8048, 0, 136, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F57, 0, 280, 8048, 0, 136, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F58, 0, 281, 8048, 0, 136, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6F59, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: air (147)544... (routine Att_AIRDASH) */
const u16 no12_saca_029_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 108) };
const u16 no12_saca_029[108] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 7, 1), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 28, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F67, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F66, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F65, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F64, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F63, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F62, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F61, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F60, 0, 30, 0, 0, 0, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 28, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 214+P light (plain script) */
const u16 no12_saca_032_head[4] = { HEAD(4, 0, 8, 13, 0, 3, 106) };
const u16 no12_saca_032[548] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F11, 0, 284, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F15, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F16, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F17, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F18, 0, 290, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F19, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -90, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -43, 293, 0, 142, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 1, 41), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 32, 20), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 32, 41), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -43, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 1, 41), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -43, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 1, 41), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -43, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 1, 41), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 32, 40), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F25, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16398, 8192, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F26, 0, 304, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F27, 0, 305, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F28, 0, 306, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F29, 0, 307, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2A, 0, 308, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2B, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2C, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F2F, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F26, 0, 304, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F27, 0, 305, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F28, 0, 306, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F29, 0, 307, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F2A, 0, 308, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F2B, 0, 309, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F2C, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F2F, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 214+P medium (plain script) */
const u16 no12_saca_033_head[4] = { HEAD(4, 0, 10, 13, 0, 4, 106) };
const u16 no12_saca_033[484] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F11, 0, 284, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F12, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F13, 0, 286, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F14, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F15, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F16, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F17, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F18, 0, 290, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F19, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F1A, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -91, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -44, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -44, 293, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 45), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 33, 24), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 33, 45), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -44, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 45), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -44, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 45), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -44, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 45), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 33, 44), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F25, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_RJA7, 5, 32, 56), 0, 0, 0, 0,
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F26, 0, 304, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F27, 0, 305, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F28, 0, 306, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F29, 0, 307, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2A, 0, 308, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2B, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2C, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F2F, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 214+P heavy (plain script) */
const u16 no12_saca_034_head[4] = { HEAD(4, 0, 12, 13, 0, 5, 106) };
const u16 no12_saca_034[492] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F10, 0, 283, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F11, 0, 284, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F12, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F13, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F14, 0, 287, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F15, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F16, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F17, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F18, 0, 290, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F19, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F1A, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -92, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -45, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -45, 293, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 4, 46), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 34, 25), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 34, 46), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -45, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 4, 46), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -45, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 4, 46), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -45, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 4, 46), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 34, 45), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F25, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_RJA7, 5, 32, 56), 0, 0, 0, 0,
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F26, 0, 304, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F27, 0, 305, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F28, 0, 306, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F29, 0, 307, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2A, 0, 308, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2B, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2C, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F2F, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 214+PP (plain script) */
const u16 no12_saca_035_head[4] = { HEAD(4, 0, 14, 13, 0, 7, 106) };
const u16 no12_saca_035[476] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F11, 0, 284, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F14, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F15, 0, 287, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F16, 0, 288, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F17, 0, 289, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F18, 0, 290, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F19, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F1A, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -93, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -46, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -46, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 6, 44), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 35, 23), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 35, 44), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x6F1B, -46, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1C, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1D, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 6, 44), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, -46, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1E, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F1F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F20, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 6, 44), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, -46, 293, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F21, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F22, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F23, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x6F24, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 6, 44), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 35, 43), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F25, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_RJA7, 5, 32, 56), 0, 0, 0, 0,
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F26, 0, 304, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F27, 0, 305, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F28, 0, 306, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F29, 0, 307, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F2A, 0, 308, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2B, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2C, 0, 309, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 311, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6F2F, 0, 312, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 236+P light (plain script) */
const u16 no12_saca_036_head[4] = { HEAD(4, 32, 8, 14, 0, 1, 105) };
const u16 no12_saca_036[164] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 223),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 318, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 318, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 236+P medium (plain script) */
const u16 no12_saca_037_head[4] = { HEAD(4, 32, 10, 24, 0, 1, 105) };
const u16 no12_saca_037[164] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 224),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 318, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 318, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 236+P heavy (plain script) */
const u16 no12_saca_038_head[4] = { HEAD(4, 32, 12, 33, 0, 1, 105) };
const u16 no12_saca_038[164] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 970, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 225),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 318, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 318, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 236+PP (plain script) */
const u16 no12_saca_039_head[4] = { HEAD(4, 32, 14, 0, 0, 2, 105) };
const u16 no12_saca_039[172] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 212),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 358, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 345, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 350, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA I 23623+P (plain script), 41 ATTACK 5 M: SA I 23623+P (plain script), 42 ATTACK 5 L: SA I 23623+P (plain script), 43 ATTACK 5 SP: SA I 23623+P (plain script) */
const u16 no12_saca_040_head[4] = { HEAD(4, 0, 32, 10, 0, 8, 109) };
const u16 no12_saca_040[388] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB0, 0, 426, 0, 0, 0, 13, 54),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB1, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 971, 0, 0, 0, 0, 0x6FB2, 0, 102, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB3, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB4, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB5, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB6, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB7, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FB8, 0, 102, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FB9, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FBA, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FBB, 0, 102, 0, 0, 0, 22, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 168),
    CMD(CM_EXEC, 2, 169, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 170),
    CMD(CM_EXEC, 2, 171, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 172),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 174),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 176),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 178),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 180),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 182),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 184),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 186),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 188),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 190),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 192),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 194),
    CMD(CM_EXEC, 2, 195, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 319, 0, 0, 0, 2, 196),
    CMD(CM_EXEC, 2, 197, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 319, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 319, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 319, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E) */
const u16 no12_saca_045_head[4] = { HEAD(4, 22, 8, 12, 0, 3, 106) };
const u16 no12_saca_045[444] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x7024, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7025, 0, 378, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7026, 0, 379, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7027, 0, 380, 0, 0, 0, 0, 0),
    L4(1, 1, 969, 0, 0, 0, 5, 0x7028, 0, 381, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, 2, 5), 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -56, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -60, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -60, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 2, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 45, 22), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 45, 43), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -60, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 2, 29), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -60, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 2, 35), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -60, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 2, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 45, 42), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 5, 0x7033, 0, 383, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7034, 0, 384, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7035, 0, 385, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7036, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7037, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7038, 0, 388, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7039, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703A, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703B, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703C, 0, 390, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703D, 0, 390, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E) */
const u16 no12_saca_046_head[4] = { HEAD(4, 22, 10, 12, 0, 4, 106) };
const u16 no12_saca_046[444] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x7024, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7025, 0, 378, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7026, 0, 379, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7027, 0, 380, 0, 0, 0, 0, 0),
    L4(2, 1, 969, 0, 0, 0, 5, 0x7028, 0, 381, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, 2, 5), 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -57, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -61, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -61, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 46, 22), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 46, 43), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -61, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 29), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -61, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 35), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -61, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 46, 42), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 5, 0x7033, 0, 383, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7034, 0, 384, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7035, 0, 385, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7036, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7037, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7038, 0, 388, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7039, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703A, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703B, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703C, 0, 390, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703D, 0, 390, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) */
const u16 no12_saca_047_head[4] = { HEAD(4, 22, 12, 12, 0, 5, 106) };
const u16 no12_saca_047[444] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x7024, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x7025, 0, 378, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x7026, 0, 379, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7027, 0, 380, 0, 0, 0, 0, 0),
    L4(2, 1, 969, 0, 0, 0, 5, 0x7028, 0, 381, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, 2, 5), 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -58, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -62, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -62, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 47, 22), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 47, 43), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -62, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 29), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -62, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 35), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -62, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 43), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 47, 42), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 5, 0x7033, 0, 383, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7034, 0, 384, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7035, 0, 385, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7036, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7037, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7038, 0, 388, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7039, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703A, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703B, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703C, 0, 390, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703D, 0, 390, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: air EX 214+PP (routine Att_AIR_A_X_E) */
const u16 no12_saca_048_head[4] = { HEAD(4, 22, 14, 12, 0, 7, 106) };
const u16 no12_saca_048[452] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x7024, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x7025, 0, 378, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x7026, 0, 379, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x7027, 0, 380, 0, 0, 0, 0, 0),
    L4(1, 1, 969, 0, 0, 0, 5, 0x7028, 0, 381, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, 2, 5), 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 256), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -59, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -63, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -63, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 6, 44), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 48, 23), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 48, 44), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 990, 0, 0, 0, 0, 0x7029, -63, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702A, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702B, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 6, 30), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, -63, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702C, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702D, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x702E, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 6, 36), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, -63, 382, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x702F, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7030, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7031, 0, 382, 0, 0, 0, 0, 0),
    L4(1, 0, 969, 0, 0, 0, 0, 0x7032, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 6, 44), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 48, 43), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 5, 0x7033, 0, 383, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7034, 0, 384, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7035, 0, 385, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7036, 0, 386, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7037, 0, 387, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7038, 0, 388, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x7039, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703A, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703B, 0, 389, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703C, 0, 390, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x703D, 0, 390, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: not started by a command */
const u16 no12_saca_049_head[4] = { HEAD(4, 0, 2, 11, 0, 12, 0) };
const u16 no12_saca_049[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: SA III 23623+P (routine Att_METAMORPHOSE) */
const u16 no12_saca_050_head[4] = { HEAD(4, 0, 32, 0, 0, 0, 111) };
const u16 no12_saca_050[180] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FE4, 0, 0, 0, 0, 0, 13, 60),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FE5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FE6, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FE7, 0, 0, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6FE8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FE9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FEB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 985, 0, 0, 0, 0, 0x6FEC, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FED, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FEE, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FEF, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF3, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF4, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF5, 0, 0, 0, 0, 0, 19, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FF6, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x6FF6, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: not started by a command */
const u16 no12_saca_051_head[4] = { HEAD(4, 0, 32, 0, 0, 0, 111) };
const u16 no12_saca_051[228] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FE4, 0, 404, 0, 0, 0, 13, 60),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE5, 0, 404, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE6, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FE7, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FE8, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7010, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7011, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7012, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7013, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7014, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7015, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7016, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7017, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7018, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7019, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x701A, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x701B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x701C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x701D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x701E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x701F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7020, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7021, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7022, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x7022, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7023, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7023, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: started by routine Att_METAMORPHOSE */
const u16 no12_saca_052_head[4] = { HEAD(4, 22, 32, 0, 0, 0, 111) };
const u16 no12_saca_052[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F31, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F32, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 963, 0, 0, 0, 0, 0x6F33, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F34, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F33, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F34, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F33, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F32, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F31, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: not started by a command */
const u16 no12_saca_053_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 no12_saca_053[228] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7136, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7137, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7138, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7139, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713A, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713B, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713F, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, 1024, 5632), 0, 0, 0, 0,
    L4(6, 40, 0, 0, 0, 0, 0, 0x6C4B, 0, 453, 0, 0, 0, 22, 22),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 453, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1600, 0x0000, 0x0000,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7136, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7137, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7138, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7139, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x713F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7140, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7140, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command */
const u16 no12_saca_054_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 33) };
const u16 no12_saca_054[84] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C22, 0, 359, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x6C47, 0, 360, 0, 0, 0, 22, 20),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C48, 0, 360, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6C49, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D60, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x6D61, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D62, -102, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6D63, 0, 95, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: 236+K light (plain script) */
const u16 no12_saca_058_head[4] = { HEAD(4, 32, 8, 11, 0, 1, 105) };
const u16 no12_saca_058[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 223),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 351, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 320, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 321, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 322, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 323, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 324, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 325, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: 236+K medium (plain script) */
const u16 no12_saca_059_head[4] = { HEAD(4, 32, 10, 11, 0, 14, 105) };
const u16 no12_saca_059[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 224),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 353, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 354, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 333, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 334, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 336, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: 236+K heavy (plain script) */
const u16 no12_saca_060_head[4] = { HEAD(4, 32, 12, 11, 0, 14, 105) };
const u16 no12_saca_060[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 2, 225),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D31, 0, 355, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 356, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 339, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 341, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 343, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: EX 236+KK (plain script) */
const u16 no12_saca_061_head[4] = { HEAD(4, 32, 14, 11, 0, 14, 105) };
const u16 no12_saca_061[204] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D2B, 0, 313, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D2C, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 970, 0, 0, 0, 0, 0x6D2D, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D2E, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D2F, 0, 317, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D30, 0, 318, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x6D31, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D32, 0, 358, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 345, 0, 0, 0, 2, 212),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 346, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 348, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D33, 0, 349, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D34, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D35, 0, 326, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6D36, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6D37, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6D38, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D39, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D3A, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6C35, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C36, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: started by routine Att_pl19_TOKUSHUKOUDOU */
const u16 no12_saca_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_saca_062[148] = {
    CMD(CM_ASXY, 116, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F5A, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5B, 0, 1, 0, 0, 0, 32, 59),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F5C, 0, 1, 0, 0, 0, 32, 60),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F5D, 0, 1, 0, 0, 0, 32, 61),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5E, 0, 1, 0, 0, 0, 32, 59),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F5F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FF7, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6FF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6FF7, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 0, 970, 0, 0, 0, 0, 0x6F5F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F2D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F2E, 0, 1, 0, 0, 0, 32, 61),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6F2F, 0, 1, 0, 0, 0, 32, 61),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6C2D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6C2E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: started by routine Att_pl19_TOKUSHUKOUDOU */
const u16 no12_saca_063_head[4] = { HEAD(4, 0, 0, 13, 0, 3, 0) };
const u16 no12_saca_063[228] = {
    CMD(CM_ASXY, 116, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5A, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5B, 0, 1, 0, 0, 0, 32, 59),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5C, 0, 1, 0, 0, 0, 32, 60),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5D, 0, 1, 0, 0, 0, 32, 61),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F5E, 0, 1, 0, 0, 0, 32, 59),
    L4(3, 40, 0, 0, 0, 0, 0, 0x6F5F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 986, 0, 0, 0, 0, 0x6FF7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF9, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7000, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7001, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7002, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7003, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7004, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7005, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7006, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7007, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7008, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7009, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x700A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x700A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: started by routine Att_pl19_TOKUSHUKOUDOU */
const u16 no12_saca_064_head[4] = { HEAD(4, 0, 0, 13, 0, 3, 0) };
const u16 no12_saca_064[172] = {
    L4(3, 0, 987, 0, 0, 0, 0, 0x700A, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7009, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7008, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7007, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7006, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7005, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7004, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7003, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7002, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7001, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7000, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FFA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF9, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6FF7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 62, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: started by routine Att_AIRDASH, 66 ATTACK 11 L: started by routine Att_AIRDASH */
const u16 no12_saca_065_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 no12_saca_065[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F7A, 0, 391, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F7B, 0, 391, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F7C, 0, 391, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F7D, 0, 391, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6F7A, 0, 391, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6F7A, 0, 391, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A) */
const u16 no12_saca_067_head[4] = { HEAD(6, 22, 36, 16, 0, 6, 110) };
const u16 no12_saca_067[556] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 7, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F60, 0, 392, 0, 0, 0, 13, 66, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F61, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F62, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F63, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F64, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F65, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F66, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F67, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F68, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F69, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F6A, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F6B, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x6F6C, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 973, 0, 0, 0, 15, 0x6F6D, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7040, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7041, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7042, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7043, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7044, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7045, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7046, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7047, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7048, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x7049, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 15, 0x704C, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EPCY, 0, 1, 16394), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 0, 15, 0x704C, -94, 395, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x704C, 0, 395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 68, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 2, 227, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 15, 0x704C, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 0, 15, 0x704C, -94, 395, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x704C, 0, 395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 69, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 2, 227, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 15, 0x704C, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A) */
const u16 no12_saca_068_head[4] = { HEAD(6, 22, 36, 13, 0, 6, 110) };
const u16 no12_saca_068[508] = {
    L6(22, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 239, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 232, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 237, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 230, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 235, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 229, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 234, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 238, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 231, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 236, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 228, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 233, 12288, 0, 0, 0, 0),
    CMD(CM_MVIX, 59, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 991, 0, 0, 0, 15, 0x7050, -95, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7051, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7052, -95, 400, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7053, 0, 401, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7054, -95, 402, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7055, 0, 403, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7056, -96, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 15, 0x7050, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7051, -96, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7052, 0, 400, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7053, 0, 401, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7054, 0, 402, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7055, 0, 403, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7056, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 60, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 20, 0, 0, 0, 0, 0, 0x6C44, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C45, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x6C46, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 15, 0x6C49, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 15, 0x6C4A, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A), 70 ATTACK 12 L: after SA II air 23623+K (routine Att_SA__D_R_A) */
const u16 no12_saca_069_head[4] = { HEAD(6, 22, 36, 13, 0, 6, 110) };
const u16 no12_saca_069[412] = {
    L6(22, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 229, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 236, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 228, 12288, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 15, 0x0000, 0, 0, 0, 0, 0, 2, 233, 12288, 0, 0, 0, 0),
    CMD(CM_MVIX, 59, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 991, 0, 0, 0, 15, 0x7050, -103, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7051, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7052, -103, 400, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7053, 0, 401, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7054, -103, 402, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7055, 0, 403, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7056, -96, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 15, 0x7050, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7051, -96, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7052, 0, 400, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7053, 0, 401, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7054, 0, 402, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7055, 0, 403, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 15, 0x7056, 0, 399, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 60, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 20, 0, 0, 0, 0, 0, 0x6C44, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6C45, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 5, 0x6C46, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 15, 0x6C49, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 15, 0x6C4A, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 14, 0x6C48, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 13, 0x6C47, 0, 30, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6C4B, 0, 29, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x6C4C, 0, 31, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: not started by a command */
const u16 no12_saca_071_head[4] = { HEAD(4, 0, 8, 0, 0, 3, 107) };
const u16 no12_saca_071[100] = {
    L4(1, 20, 0, 0, 0, 0, 15, 0x6F60, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F60, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F61, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F62, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F63, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F64, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F65, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F66, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F67, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 966, 0, 0, 0, 15, 0x6F68, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6F69, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6F6A, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 ATTACK 13 S: not started by a command */
const u16 no12_saca_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_saca_072[80] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D01),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D02),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D03),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D04),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D05),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D06),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D07),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D08),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D09),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D0F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D10),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D11),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D12),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D13),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: not started by a command */
const u16 no12_saca_073_head[4] = { HEAD(4, 0, 8, 0, 0, 3, 107) };
const u16 no12_saca_073[76] = {
    L4(3, 20, 0, 0, 0, 0, 15, 0x6F71, -27, 255, 0, 70, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6F72, 0, 256, 0, 70, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x6F73, 0, 257, 0, 64, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x6F6E, -28, 258, 0, 70, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F6F, 0, 259, 0, 70, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F70, 0, 260, 0, 64, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x6F6B, -29, 261, 0, 70, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6F6C, 0, 262, 0, 70, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6F6D, 0, 263, 0, 64, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: not started by a command */
const u16 no12_saca_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_saca_074[1168] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7057),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7058),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7059),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x705F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7060),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7061),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7062),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7063),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7064),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7065),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 0, 3328, 768),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE4),
    CMD(CM_DUMMY, 8192, 0, 5376),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE5),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE6),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE7),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE8),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 40, 0, 0, 0, 0, 0, 0x7010),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7011),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7012),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7013),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7014),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7015),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7016),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7017),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7018),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7019),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701A),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701B),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701C),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701D),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701E),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701F),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7020),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7021),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7022),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7023),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x7023),
    CMD(CM_DUMMY, 8192, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 0, 3328, 768),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7023),
    CMD(CM_DUMMY, 8192, 0, 5376),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7022),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7021),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7020),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701F),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701E),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701D),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701C),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701B),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x701A),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7019),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7018),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7017),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7016),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7015),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7014),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7013),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7012),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7011),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7010),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE8),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE7),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE6),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE5),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x6FE4),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6FE4),
    CMD(CM_DUMMY, 8192, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 8200, 2816, 617),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2B),
    CMD(CM_PS_Y, 8192, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2C),
    CMD(CM_PS_Y, 16384, 0, 0),
    L2(2, 0, 970, 0, 0, 0, 0, 0x6D2D),
    CMD(CM_PS_Y, 24576, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2E),
    CMD(CM_PS_Y, -32768, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6D2F),
    CMD(CM_PS_Y, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 1, 0, 0x6D30),
    CMD(CM_PS_Y, -16384, 0, 0),
    L2(1, 0, 268, 0, 0, 2, 0, 0x6D31),
    L2(246, 242, 2560, 0, 0, 2192, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 3, 0, 0x6D32),
    CMD(CM_IXBW, -24576, -32768, 0),
    L2(1, 0, 0, 0, 0, 4, 0, 0x6D33),
    CMD(CM_IXBW, -16384, 0, 0),
    L2(1, 0, 0, 0, 0, 5, 0, 0x6D33),
    CMD(CM_IXBW, -16384, 0, 0),
    L2(1, 0, 0, 0, 0, 6, 0, 0x6D33),
    CMD(CM_IXBW, -16384, 0, 0),
    L2(1, 0, 0, 0, 0, 7, 0, 0x6D33),
    L2(246, 242, 3072, 0, 0, 2288, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 8, 0, 0x6D33),
    CMD(CM_IXBW, -8192, -28928, 0),
    L2(1, 0, 0, 0, 0, 9, 0, 0x6D33),
    CMD(CM_QUAX, 0, -32768, 0),
    L2(1, 0, 0, 0, 0, 10, 0, 0x6D33),
    CMD(CM_QUAX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 11, 0, 0x6D33),
    CMD(CM_QUAX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 12, 0, 0x6D34),
    CMD(CM_QUAX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 13, 0, 0x6D35),
    CMD(CM_QUAX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 14, 0, 0x6D36),
    CMD(CM_QUAX, 8192, 0, 0),
    L2(4, 0, 0, 0, 0, 15, 0, 0x6D37),
    CMD(CM_PA_X, 0, 0, 5376),
    L2(3, 0, 0, 0, 0, 87, 0, 0x6D38),
    CMD(CM_PA_X, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 88, 0, 0x6D39),
    CMD(CM_PA_X, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 89, 0, 0x6D3A),
    CMD(CM_PA_X, 24576, 0, 0),
    L2(2, 64, 0, 0, 0, 90, 0, 0x6C34),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C35),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 8202, 2816, 617),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2B),
    CMD(CM_PS_Y, 8192, 0, 0),
    L2(2, 0, 970, 0, 0, 0, 0, 0x6D2C),
    CMD(CM_PS_Y, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2D),
    CMD(CM_PS_Y, 24576, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2E),
    CMD(CM_PS_Y, -32768, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2F),
    CMD(CM_PS_Y, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 57, 0, 0x6D30),
    CMD(CM_PS_Y, -16384, 0, 0),
    L2(1, 0, 269, 0, 0, 58, 0, 0x6D31),
    L2(246, 179, 1024, 0, 0, 2192, 0, 0x0000),
    L2(2, 0, 0, 0, 0, 59, 0, 0x6D32),
    CMD(CM_QUAX, 16384, -32768, 0),
    L2(1, 0, 0, 0, 0, 60, 0, 0x6D33),
    CMD(CM_QUAX, 24576, 0, 0),
    L2(1, 0, 0, 0, 0, 61, 0, 0x6D33),
    CMD(CM_QUAX, 24576, 0, 0),
    L2(1, 0, 0, 0, 0, 62, 0, 0x6D33),
    CMD(CM_QUAX, 24576, 0, 0),
    L2(1, 0, 0, 0, 0, 63, 0, 0x6D33),
    L2(246, 179, 1536, 0, 0, 2288, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 64, 0, 0x6D33),
    CMD(CM_QUAX, -32768, -28928, 0),
    L2(1, 0, 0, 0, 0, 65, 0, 0x6D33),
    CMD(CM_QUAX, -24576, -32768, 0),
    L2(1, 0, 0, 0, 0, 66, 0, 0x6D33),
    CMD(CM_QUAX, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 67, 0, 0x6D33),
    CMD(CM_QUAX, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 68, 0, 0x6D34),
    CMD(CM_QUAX, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 69, 0, 0x6D35),
    CMD(CM_QUAX, -24576, 0, 0),
    L2(1, 0, 0, 0, 0, 70, 0, 0x6D36),
    CMD(CM_QUAX, -16384, 0, 0),
    L2(4, 0, 0, 0, 0, 71, 0, 0x6D37),
    CMD(CM_PA_X, 0, 0, 5376),
    L2(3, 0, 0, 0, 0, 91, 0, 0x6D38),
    CMD(CM_PA_X, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 92, 0, 0x6D39),
    CMD(CM_PA_X, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 93, 0, 0x6D3A),
    CMD(CM_PA_X, 24576, 0, 0),
    L2(2, 64, 0, 0, 0, 94, 0, 0x6C34),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C35),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 8204, 2816, 617),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2B),
    CMD(CM_PS_Y, 8192, 0, 0),
    L2(2, 0, 970, 0, 0, 0, 0, 0x6D2C),
    CMD(CM_PS_Y, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2D),
    CMD(CM_PS_Y, 24576, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2E),
    CMD(CM_PS_Y, -32768, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6D2F),
    CMD(CM_PS_Y, -24576, 0, 0),
    L2(2, 0, 0, 0, 0, 72, 0, 0x6D30),
    CMD(CM_PS_Y, -16384, 0, 0),
    L2(1, 0, 270, 0, 0, 73, 0, 0x6D31),
    L2(246, 115, 3584, 0, 0, 2192, 0, 0x0000),
    L2(2, 0, 0, 0, 0, 74, 0, 0x6D32),
    CMD(CM_QUAX, -8192, -32768, 0),
    L2(1, 0, 0, 0, 0, 75, 0, 0x6D33),
    CMD(CM_QUAY, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 76, 0, 0x6D33),
    CMD(CM_QUAY, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 77, 0, 0x6D33),
    CMD(CM_QUAY, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 78, 0, 0x6D33),
    L2(246, 116, 0, 0, 0, 2288, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 79, 0, 0x6D33),
    CMD(CM_QUAY, 8192, -28928, 0),
    L2(1, 0, 0, 0, 0, 80, 0, 0x6D33),
    CMD(CM_QUAY, 16384, -32768, 0),
    L2(1, 0, 0, 0, 0, 81, 0, 0x6D33),
    CMD(CM_QUAY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 82, 0, 0x6D33),
    CMD(CM_QUAY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 83, 0, 0x6D34),
    CMD(CM_QUAY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 84, 0, 0x6D35),
    CMD(CM_QUAY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 85, 0, 0x6D36),
    CMD(CM_QUAY, 24576, 0, 0),
    L2(4, 0, 0, 0, 0, 86, 0, 0x6D37),
    CMD(CM_PA_X, 0, 0, 5376),
    L2(3, 0, 0, 0, 0, 95, 0, 0x6D38),
    CMD(CM_PA_X, 8192, 0, 0),
    L2(3, 0, 0, 0, 0, 96, 0, 0x6D39),
    CMD(CM_PA_X, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 97, 0, 0x6D3A),
    CMD(CM_PA_X, 24576, 0, 0),
    L2(2, 64, 0, 0, 0, 98, 0, 0x6C34),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x6C35),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x6C36),
    CMD(CM_DUMMY, 16384, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 30 entries */
const u16* const no12_cbca[31] = {
    no12_cbca_000,  /* 0 APPEAR JUNBI 1 */
    no12_cbca_001,  /* 1 APPEAR JUNBI 2 */
    no12_cbca_002,  /* 2 APPEAR JUNBI 3 */
    no12_cbca_003,  /* 3 APPEAR JUNBI 4 */
    no12_cbca_004,  /* 4 APPEAR JUNBI 5 */
    no12_cbca_005,  /* 5 APPEAR JUNBI 6 */
    no12_cbca_006,  /* 6 APPEAR JUNBI 7 */
    no12_cbca_007,  /* 7 APPEAR JUNBI 8 */
    no12_cbca_008,  /* 8 APPEAR 1 */
    no12_cbca_009,  /* 9 APPEAR 2 */
    no12_cbca_010,  /* 10 APPEAR 3 */
    no12_cbca_011,  /* 11 APPEAR 4 */
    no12_cbca_012,  /* 12 APPEAR 5 */
    no12_cbca_013,  /* 13 APPEAR 6 */
    no12_cbca_014,  /* 14 APPEAR 7 */
    no12_cbca_015,  /* 15 APPEAR 8 */
    no12_cbca_016,  /* 16 SP APPEAR 1 */
    no12_cbca_017,  /* 17 SP APPEAR 2 */
    no12_cbca_018,  /* 18 SP APPEAR 3 */
    no12_cbca_019,  /* 19 SP APPEAR 4 */
    no12_cbca_020,  /* 20 SP APPEAR 5 */
    no12_cbca_021,  /* 21 SP APPEAR 6 */
    no12_cbca_022,  /* 22 SP APPEAR 7 */
    no12_cbca_023,  /* 23 SP APPEAR 8 */
    no12_cbca_024,  /* 24 ZANNEN 1 */
    no12_cbca_025,  /* 25 ZANNEN 2 */
    no12_cbca_026,  /* 26 ZANNEN 3 */
    no12_cbca_027,  /* 27 ZANNEN 4 */
    no12_cbca_028,  /* 28 ZANNEN 5 */
    no12_cbca_029,  /* 29 ZANNEN 6 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 no12_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 no12_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 no12_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 no12_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 no12_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 13, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 no12_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_005[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 no12_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 no12_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_007[236] = {
    CMD(CM_CHKWF, 47, 16417, 8192),
    CMD(CM_CHKWF, 48, 16429, 8192),
    CMD(CM_IFS3, 16, 16391, 8192),
    CMD(CM_IFS3, 32, 16394, 8192),
    CMD(CM_IFS3, 64, 16397, 8192),
    CMD(CM_IFS3, 256, 16400, 8192),
    CMD(CM_IFS3, 512, 16403, 8192),
    CMD(CM_IFS3, 1024, 16406, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 156, 1),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 157, 1),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 158, 1),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 159, 1),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 160, 1),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_SCHX, 0, 3, 4),
    CMD(CM_SSTY, 2, 0, -96),
    CMD(CM_JMP, 4, 161, 1),
    CMD(CM_S_CHG, 256, 16388, 8192),
    CMD(CM_S_CHG, 512, 16390, 8192),
    CMD(CM_S_CHG, 1024, 16392, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 24, 1),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 25, 1),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 26, 1),
    CMD(CM_S_CHG, 16, 16388, 8192),
    CMD(CM_S_CHG, 32, 16390, 8192),
    CMD(CM_S_CHG, 64, 16392, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 54, 0, 0),
    CMD(CM_JMP, 5, 45, 1),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 55, 0, 0),
    CMD(CM_JMP, 5, 46, 1),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 56, 0, 0),
    CMD(CM_JMP, 5, 47, 1),
};

/* script: 8 APPEAR 1 */
const u16 no12_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_008[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 no12_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_009[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 no12_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_010[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 85, 0),
    CMD(CM_STOP, -1, 85, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 no12_cbca_011_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 no12_cbca_011[16] = {
    CMD(CM_EXEC, 49, 62, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 no12_cbca_012_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 no12_cbca_012[16] = {
    CMD(CM_EXEC, 49, 63, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 no12_cbca_013_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 no12_cbca_013[16] = {
    CMD(CM_EXEC, 49, 64, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 no12_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_014[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 18, 1),
    CMD(CM_RJA3, 7, 19, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 no12_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_015[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 14, 1),
    CMD(CM_RJA3, 7, 15, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 no12_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_016[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 16, 1),
    CMD(CM_RJA3, 7, 17, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 no12_cbca_017_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 no12_cbca_017[16] = {
    CMD(CM_EXEC, 49, 68, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 no12_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_018[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 no12_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_019[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 7, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 20 SP APPEAR 5 */
const u16 no12_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_020[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 21 SP APPEAR 6 */
const u16 no12_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_021[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 no12_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_022[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 no12_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_023[8] = {
    CMD(CM_RJA4, 5, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 no12_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 no12_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_025[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 no12_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 no12_cbca_026[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 no12_cbca_027_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 no12_cbca_027[16] = {
    CMD(CM_EXEC, 49, 25, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 no12_cbca_028_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 no12_cbca_028[16] = {
    CMD(CM_EXEC, 49, 26, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 no12_cbca_029_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 no12_cbca_029[256] = {
    CMD(CM_EXEC, 49, 27, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    CMD(CM_CHKWF, 47, 16417, 8192),
    CMD(CM_CHKWF, 48, 16429, 8192),
    CMD(CM_IFS3, 16, 16391, 8192),
    CMD(CM_IFS3, 32, 16394, 8192),
    CMD(CM_IFS3, 64, 16397, 8192),
    CMD(CM_IFS3, 256, 16400, 8192),
    CMD(CM_IFS3, 512, 16403, 8192),
    CMD(CM_IFS3, 1024, 16406, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 48, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 50, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 52, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 54, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 56, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S123, 4, 3, 1),
    CMD(CM_MXYT, 35, 0, 0),
    CMD(CM_JMP, 4, 58, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_S_CHG, 256, 16388, 8192),
    CMD(CM_S_CHG, 512, 16390, 8192),
    CMD(CM_S_CHG, 1024, 16392, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 24, 1),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 25, 1),
    CMD(CM_S123, 4, 18, 1),
    CMD(CM_MXYT, 37, 0, 0),
    CMD(CM_JMP, 5, 26, 1),
    CMD(CM_S_CHG, 16, 16388, 8192),
    CMD(CM_S_CHG, 32, 16390, 8192),
    CMD(CM_S_CHG, 64, 16392, 8192),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 54, 0, 0),
    CMD(CM_JMP, 5, 45, 1),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 55, 0, 0),
    CMD(CM_JMP, 5, 46, 1),
    CMD(CM_S123, 4, 23, 1),
    CMD(CM_MXYT, 56, 0, 0),
    CMD(CM_JMP, 5, 47, 1),
};

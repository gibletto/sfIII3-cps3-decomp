/*
 * REMY_CHAR.C  Remy's animation scripts and sprite part tables
 *
 * The animation scripts Remy's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 remy_nmca_000[], remy_nmca_001[], remy_nmca_002[], remy_nmca_003[], remy_nmca_004[], remy_nmca_005[], remy_nmca_006[], remy_nmca_007[], remy_nmca_008[], remy_nmca_011[], remy_nmca_012[], remy_nmca_013[], remy_nmca_014[], remy_nmca_015[], remy_nmca_016[], remy_nmca_017[], remy_nmca_020[], remy_nmca_021[], remy_nmca_022[], remy_nmca_023[], remy_nmca_024[], remy_nmca_026[], remy_nmca_027[], remy_nmca_029[], remy_nmca_030[], remy_nmca_031[], remy_nmca_032[], remy_nmca_033[], remy_nmca_038[], remy_nmca_040[], remy_nmca_041[], remy_nmca_043[], remy_nmca_044[], remy_nmca_045[], remy_nmca_046[], remy_nmca_047[], remy_nmca_048[], remy_nmca_049[], remy_nmca_050[];
extern const u16 remy_nmca_000_head[];
extern const u16 remy_nmca_001_head[];
extern const u16 remy_nmca_002_head[];
extern const u16 remy_nmca_003_head[];
extern const u16 remy_nmca_004_head[];
extern const u16 remy_nmca_005_head[];
extern const u16 remy_nmca_006_head[];
extern const u16 remy_nmca_007_head[];
extern const u16 remy_nmca_008_head[];
extern const u16 remy_nmca_011_head[];
extern const u16 remy_nmca_012_head[];
extern const u16 remy_nmca_013_head[];
extern const u16 remy_nmca_014_head[];
extern const u16 remy_nmca_015_head[];
extern const u16 remy_nmca_016_head[];
extern const u16 remy_nmca_017_head[];
extern const u16 remy_nmca_020_head[];
extern const u16 remy_nmca_021_head[];
extern const u16 remy_nmca_022_head[];
extern const u16 remy_nmca_023_head[];
extern const u16 remy_nmca_024_head[];
extern const u16 remy_nmca_026_head[];
extern const u16 remy_nmca_027_head[];
extern const u16 remy_nmca_029_head[];
extern const u16 remy_nmca_030_head[];
extern const u16 remy_nmca_031_head[];
extern const u16 remy_nmca_032_head[];
extern const u16 remy_nmca_033_head[];
extern const u16 remy_nmca_038_head[];
extern const u16 remy_nmca_040_head[];
extern const u16 remy_nmca_041_head[];
extern const u16 remy_nmca_043_head[];
extern const u16 remy_nmca_044_head[];
extern const u16 remy_nmca_045_head[];
extern const u16 remy_nmca_046_head[];
extern const u16 remy_nmca_047_head[];
extern const u16 remy_nmca_048_head[];
extern const u16 remy_nmca_049_head[];
extern const u16 remy_nmca_050_head[];
extern const u16 remy_dmca_000[], remy_dmca_001[], remy_dmca_002[], remy_dmca_003[], remy_dmca_004[], remy_dmca_006[], remy_dmca_008[], remy_dmca_009[], remy_dmca_010[], remy_dmca_014[], remy_dmca_018[], remy_dmca_022[], remy_dmca_025[], remy_dmca_026[], remy_dmca_024[], remy_dmca_029[], remy_dmca_030[], remy_dmca_034[], remy_dmca_036[], remy_dmca_037[], remy_dmca_038[], remy_dmca_039[], remy_dmca_040[], remy_dmca_041[], remy_dmca_042[], remy_dmca_043[], remy_dmca_048[], remy_dmca_049[], remy_dmca_050[], remy_dmca_052[], remy_dmca_053[], remy_dmca_054[], remy_dmca_055[], remy_dmca_056[], remy_dmca_057[], remy_dmca_058[], remy_dmca_059[], remy_dmca_060[], remy_dmca_064[], remy_dmca_065[], remy_dmca_066[], remy_dmca_067[], remy_dmca_068[], remy_dmca_069[], remy_dmca_070[], remy_dmca_071[], remy_dmca_072[], remy_dmca_073[], remy_dmca_074[], remy_dmca_078[], remy_dmca_079[], remy_dmca_080[], remy_dmca_082[], remy_dmca_083[], remy_dmca_084[], remy_dmca_090[], remy_dmca_091[], remy_dmca_096[], remy_dmca_097[];
extern const u16 remy_dmca_000_head[];
extern const u16 remy_dmca_001_head[];
extern const u16 remy_dmca_002_head[];
extern const u16 remy_dmca_003_head[];
extern const u16 remy_dmca_004_head[];
extern const u16 remy_dmca_006_head[];
extern const u16 remy_dmca_008_head[];
extern const u16 remy_dmca_009_head[];
extern const u16 remy_dmca_010_head[];
extern const u16 remy_dmca_014_head[];
extern const u16 remy_dmca_018_head[];
extern const u16 remy_dmca_022_head[];
extern const u16 remy_dmca_025_head[];
extern const u16 remy_dmca_026_head[];
extern const u16 remy_dmca_024_head[];
extern const u16 remy_dmca_029_head[];
extern const u16 remy_dmca_030_head[];
extern const u16 remy_dmca_034_head[];
extern const u16 remy_dmca_036_head[];
extern const u16 remy_dmca_037_head[];
extern const u16 remy_dmca_038_head[];
extern const u16 remy_dmca_039_head[];
extern const u16 remy_dmca_040_head[];
extern const u16 remy_dmca_041_head[];
extern const u16 remy_dmca_042_head[];
extern const u16 remy_dmca_043_head[];
extern const u16 remy_dmca_048_head[];
extern const u16 remy_dmca_049_head[];
extern const u16 remy_dmca_050_head[];
extern const u16 remy_dmca_052_head[];
extern const u16 remy_dmca_053_head[];
extern const u16 remy_dmca_054_head[];
extern const u16 remy_dmca_055_head[];
extern const u16 remy_dmca_056_head[];
extern const u16 remy_dmca_057_head[];
extern const u16 remy_dmca_058_head[];
extern const u16 remy_dmca_059_head[];
extern const u16 remy_dmca_060_head[];
extern const u16 remy_dmca_064_head[];
extern const u16 remy_dmca_065_head[];
extern const u16 remy_dmca_066_head[];
extern const u16 remy_dmca_067_head[];
extern const u16 remy_dmca_068_head[];
extern const u16 remy_dmca_069_head[];
extern const u16 remy_dmca_070_head[];
extern const u16 remy_dmca_071_head[];
extern const u16 remy_dmca_072_head[];
extern const u16 remy_dmca_073_head[];
extern const u16 remy_dmca_074_head[];
extern const u16 remy_dmca_078_head[];
extern const u16 remy_dmca_079_head[];
extern const u16 remy_dmca_080_head[];
extern const u16 remy_dmca_082_head[];
extern const u16 remy_dmca_083_head[];
extern const u16 remy_dmca_084_head[];
extern const u16 remy_dmca_090_head[];
extern const u16 remy_dmca_091_head[];
extern const u16 remy_dmca_096_head[];
extern const u16 remy_dmca_097_head[];
extern const u16 remy_btca_000[], remy_btca_001[], remy_btca_002[], remy_btca_003[], remy_btca_004[], remy_btca_005[], remy_btca_006[], remy_btca_007[], remy_btca_008[], remy_btca_009[], remy_btca_010[], remy_btca_011[], remy_btca_012[], remy_btca_013[], remy_btca_014[], remy_btca_015[], remy_btca_016[], remy_btca_017[], remy_btca_018[], remy_btca_019[], remy_btca_020[], remy_btca_021[], remy_btca_022[], remy_btca_023[], remy_btca_024[], remy_btca_025[], remy_btca_026[], remy_btca_027[], remy_btca_028[], remy_btca_029[], remy_btca_030[], remy_btca_031[], remy_btca_032[], remy_btca_033[], remy_btca_034[];
extern const u16 remy_btca_000_head[];
extern const u16 remy_btca_001_head[];
extern const u16 remy_btca_002_head[];
extern const u16 remy_btca_003_head[];
extern const u16 remy_btca_004_head[];
extern const u16 remy_btca_005_head[];
extern const u16 remy_btca_006_head[];
extern const u16 remy_btca_007_head[];
extern const u16 remy_btca_008_head[];
extern const u16 remy_btca_009_head[];
extern const u16 remy_btca_010_head[];
extern const u16 remy_btca_011_head[];
extern const u16 remy_btca_012_head[];
extern const u16 remy_btca_013_head[];
extern const u16 remy_btca_014_head[];
extern const u16 remy_btca_015_head[];
extern const u16 remy_btca_016_head[];
extern const u16 remy_btca_017_head[];
extern const u16 remy_btca_018_head[];
extern const u16 remy_btca_019_head[];
extern const u16 remy_btca_020_head[];
extern const u16 remy_btca_021_head[];
extern const u16 remy_btca_022_head[];
extern const u16 remy_btca_023_head[];
extern const u16 remy_btca_024_head[];
extern const u16 remy_btca_025_head[];
extern const u16 remy_btca_026_head[];
extern const u16 remy_btca_027_head[];
extern const u16 remy_btca_028_head[];
extern const u16 remy_btca_029_head[];
extern const u16 remy_btca_030_head[];
extern const u16 remy_btca_031_head[];
extern const u16 remy_btca_032_head[];
extern const u16 remy_btca_033_head[];
extern const u16 remy_btca_034_head[];
extern const u16 remy_caca_000[], remy_caca_001[], remy_caca_002[];
extern const u16 remy_caca_000_head[];
extern const u16 remy_caca_001_head[];
extern const u16 remy_caca_002_head[];
extern const u16 remy_cuca_000[], remy_cuca_001[], remy_cuca_002[], remy_cuca_003[], remy_cuca_004[], remy_cuca_005[], remy_cuca_006[], remy_cuca_007[], remy_cuca_008[], remy_cuca_009[], remy_cuca_010[], remy_cuca_011[], remy_cuca_012[], remy_cuca_013[], remy_cuca_014[], remy_cuca_015[], remy_cuca_016[], remy_cuca_017[], remy_cuca_018[], remy_cuca_019[], remy_cuca_020[], remy_cuca_021[], remy_cuca_022[], remy_cuca_023[], remy_cuca_024[], remy_cuca_025[], remy_cuca_026[], remy_cuca_027[], remy_cuca_028[], remy_cuca_029[], remy_cuca_030[], remy_cuca_031[], remy_cuca_032[], remy_cuca_033[], remy_cuca_034[], remy_cuca_035[], remy_cuca_036[], remy_cuca_037[], remy_cuca_038[], remy_cuca_039[], remy_cuca_040[], remy_cuca_041[], remy_cuca_042[], remy_cuca_043[], remy_cuca_044[], remy_cuca_045[], remy_cuca_046[], remy_cuca_047[], remy_cuca_048[], remy_cuca_049[], remy_cuca_050[], remy_cuca_051[], remy_cuca_052[], remy_cuca_053[], remy_cuca_054[], remy_cuca_055[], remy_cuca_056[], remy_cuca_057[], remy_cuca_058[], remy_cuca_059[], remy_cuca_060[], remy_cuca_061[], remy_cuca_062[], remy_cuca_063[], remy_cuca_064[], remy_cuca_065[], remy_cuca_066[], remy_cuca_067[];
extern const u16 remy_cuca_000_head[];
extern const u16 remy_cuca_001_head[];
extern const u16 remy_cuca_002_head[];
extern const u16 remy_cuca_003_head[];
extern const u16 remy_cuca_004_head[];
extern const u16 remy_cuca_005_head[];
extern const u16 remy_cuca_006_head[];
extern const u16 remy_cuca_007_head[];
extern const u16 remy_cuca_008_head[];
extern const u16 remy_cuca_009_head[];
extern const u16 remy_cuca_010_head[];
extern const u16 remy_cuca_011_head[];
extern const u16 remy_cuca_012_head[];
extern const u16 remy_cuca_013_head[];
extern const u16 remy_cuca_014_head[];
extern const u16 remy_cuca_015_head[];
extern const u16 remy_cuca_016_head[];
extern const u16 remy_cuca_017_head[];
extern const u16 remy_cuca_018_head[];
extern const u16 remy_cuca_019_head[];
extern const u16 remy_cuca_020_head[];
extern const u16 remy_cuca_021_head[];
extern const u16 remy_cuca_022_head[];
extern const u16 remy_cuca_023_head[];
extern const u16 remy_cuca_024_head[];
extern const u16 remy_cuca_025_head[];
extern const u16 remy_cuca_026_head[];
extern const u16 remy_cuca_027_head[];
extern const u16 remy_cuca_028_head[];
extern const u16 remy_cuca_029_head[];
extern const u16 remy_cuca_030_head[];
extern const u16 remy_cuca_031_head[];
extern const u16 remy_cuca_032_head[];
extern const u16 remy_cuca_033_head[];
extern const u16 remy_cuca_034_head[];
extern const u16 remy_cuca_035_head[];
extern const u16 remy_cuca_036_head[];
extern const u16 remy_cuca_037_head[];
extern const u16 remy_cuca_038_head[];
extern const u16 remy_cuca_039_head[];
extern const u16 remy_cuca_040_head[];
extern const u16 remy_cuca_041_head[];
extern const u16 remy_cuca_042_head[];
extern const u16 remy_cuca_043_head[];
extern const u16 remy_cuca_044_head[];
extern const u16 remy_cuca_045_head[];
extern const u16 remy_cuca_046_head[];
extern const u16 remy_cuca_047_head[];
extern const u16 remy_cuca_048_head[];
extern const u16 remy_cuca_049_head[];
extern const u16 remy_cuca_050_head[];
extern const u16 remy_cuca_051_head[];
extern const u16 remy_cuca_052_head[];
extern const u16 remy_cuca_053_head[];
extern const u16 remy_cuca_054_head[];
extern const u16 remy_cuca_055_head[];
extern const u16 remy_cuca_056_head[];
extern const u16 remy_cuca_057_head[];
extern const u16 remy_cuca_058_head[];
extern const u16 remy_cuca_059_head[];
extern const u16 remy_cuca_060_head[];
extern const u16 remy_cuca_061_head[];
extern const u16 remy_cuca_062_head[];
extern const u16 remy_cuca_063_head[];
extern const u16 remy_cuca_064_head[];
extern const u16 remy_cuca_065_head[];
extern const u16 remy_cuca_066_head[];
extern const u16 remy_cuca_067_head[];
extern const u16 remy_atca_000[], remy_atca_001[], remy_atca_003[], remy_atca_004[], remy_atca_006[], remy_atca_007[], remy_atca_009[], remy_atca_010[], remy_atca_012[], remy_atca_013[], remy_atca_014[], remy_atca_015[], remy_atca_016[], remy_atca_018[], remy_atca_021[], remy_atca_024[], remy_atca_027[], remy_atca_030[], remy_atca_033[], remy_atca_036[], remy_atca_038[], remy_atca_040[], remy_atca_042[], remy_atca_044[], remy_atca_046[], remy_atca_048[], remy_atca_050[], remy_atca_052[], remy_atca_054[], remy_atca_056[], remy_atca_058[], remy_atca_060[], remy_atca_062[], remy_atca_064[], remy_atca_066[], remy_atca_068[], remy_atca_070[], remy_atca_072[], remy_atca_074[], remy_atca_076[], remy_atca_078[], remy_atca_080[], remy_atca_082[], remy_atca_084[], remy_atca_086[], remy_atca_088[], remy_atca_090[], remy_atca_092[], remy_atca_094[], remy_atca_096[], remy_atca_098[], remy_atca_100[], remy_atca_102[], remy_atca_104[], remy_atca_106[], remy_atca_108[], remy_atca_110[], remy_atca_112[], remy_atca_114[], remy_atca_116[], remy_atca_118[], remy_atca_144[], remy_atca_145[], remy_atca_146[], remy_atca_156[], remy_atca_157[];
extern const u16 remy_atca_000_head[];
extern const u16 remy_atca_001_head[];
extern const u16 remy_atca_003_head[];
extern const u16 remy_atca_004_head[];
extern const u16 remy_atca_006_head[];
extern const u16 remy_atca_007_head[];
extern const u16 remy_atca_009_head[];
extern const u16 remy_atca_010_head[];
extern const u16 remy_atca_012_head[];
extern const u16 remy_atca_013_head[];
extern const u16 remy_atca_014_head[];
extern const u16 remy_atca_015_head[];
extern const u16 remy_atca_016_head[];
extern const u16 remy_atca_018_head[];
extern const u16 remy_atca_021_head[];
extern const u16 remy_atca_024_head[];
extern const u16 remy_atca_027_head[];
extern const u16 remy_atca_030_head[];
extern const u16 remy_atca_033_head[];
extern const u16 remy_atca_036_head[];
extern const u16 remy_atca_038_head[];
extern const u16 remy_atca_040_head[];
extern const u16 remy_atca_042_head[];
extern const u16 remy_atca_044_head[];
extern const u16 remy_atca_046_head[];
extern const u16 remy_atca_048_head[];
extern const u16 remy_atca_050_head[];
extern const u16 remy_atca_052_head[];
extern const u16 remy_atca_054_head[];
extern const u16 remy_atca_056_head[];
extern const u16 remy_atca_058_head[];
extern const u16 remy_atca_060_head[];
extern const u16 remy_atca_062_head[];
extern const u16 remy_atca_064_head[];
extern const u16 remy_atca_066_head[];
extern const u16 remy_atca_068_head[];
extern const u16 remy_atca_070_head[];
extern const u16 remy_atca_072_head[];
extern const u16 remy_atca_074_head[];
extern const u16 remy_atca_076_head[];
extern const u16 remy_atca_078_head[];
extern const u16 remy_atca_080_head[];
extern const u16 remy_atca_082_head[];
extern const u16 remy_atca_084_head[];
extern const u16 remy_atca_086_head[];
extern const u16 remy_atca_088_head[];
extern const u16 remy_atca_090_head[];
extern const u16 remy_atca_092_head[];
extern const u16 remy_atca_094_head[];
extern const u16 remy_atca_096_head[];
extern const u16 remy_atca_098_head[];
extern const u16 remy_atca_100_head[];
extern const u16 remy_atca_102_head[];
extern const u16 remy_atca_104_head[];
extern const u16 remy_atca_106_head[];
extern const u16 remy_atca_108_head[];
extern const u16 remy_atca_110_head[];
extern const u16 remy_atca_112_head[];
extern const u16 remy_atca_114_head[];
extern const u16 remy_atca_116_head[];
extern const u16 remy_atca_118_head[];
extern const u16 remy_atca_144_head[];
extern const u16 remy_atca_145_head[];
extern const u16 remy_atca_146_head[];
extern const u16 remy_atca_156_head[];
extern const u16 remy_atca_157_head[];
extern const u16 remy_exca_000[], remy_exca_001[], remy_exca_003[], remy_exca_004[], remy_exca_005[], remy_exca_006[], remy_exca_007[], remy_exca_008[], remy_exca_009[], remy_exca_010[], remy_exca_012[], remy_exca_013[], remy_exca_014[], remy_exca_015[], remy_exca_016[], remy_exca_017[], remy_exca_018[], remy_exca_019[], remy_exca_020[], remy_exca_021[], remy_exca_022[], remy_exca_023[], remy_exca_024[], remy_exca_025[], remy_exca_026[], remy_exca_027[], remy_exca_028[], remy_exca_029[], remy_exca_030[], remy_exca_031[], remy_exca_032[], remy_exca_033[], remy_exca_034[], remy_exca_035[], remy_exca_036[], remy_exca_037[], remy_exca_039[], remy_exca_040[], remy_exca_041[], remy_exca_042[], remy_exca_043[], remy_exca_044[], remy_exca_045[], remy_exca_046[], remy_exca_047[], remy_exca_048[], remy_exca_049[], remy_exca_050[], remy_exca_051[];
extern const u16 remy_exca_000_head[];
extern const u16 remy_exca_001_head[];
extern const u16 remy_exca_003_head[];
extern const u16 remy_exca_004_head[];
extern const u16 remy_exca_005_head[];
extern const u16 remy_exca_006_head[];
extern const u16 remy_exca_007_head[];
extern const u16 remy_exca_008_head[];
extern const u16 remy_exca_009_head[];
extern const u16 remy_exca_010_head[];
extern const u16 remy_exca_012_head[];
extern const u16 remy_exca_013_head[];
extern const u16 remy_exca_014_head[];
extern const u16 remy_exca_015_head[];
extern const u16 remy_exca_016_head[];
extern const u16 remy_exca_017_head[];
extern const u16 remy_exca_018_head[];
extern const u16 remy_exca_019_head[];
extern const u16 remy_exca_020_head[];
extern const u16 remy_exca_021_head[];
extern const u16 remy_exca_022_head[];
extern const u16 remy_exca_023_head[];
extern const u16 remy_exca_024_head[];
extern const u16 remy_exca_025_head[];
extern const u16 remy_exca_026_head[];
extern const u16 remy_exca_027_head[];
extern const u16 remy_exca_028_head[];
extern const u16 remy_exca_029_head[];
extern const u16 remy_exca_030_head[];
extern const u16 remy_exca_031_head[];
extern const u16 remy_exca_032_head[];
extern const u16 remy_exca_033_head[];
extern const u16 remy_exca_034_head[];
extern const u16 remy_exca_035_head[];
extern const u16 remy_exca_036_head[];
extern const u16 remy_exca_037_head[];
extern const u16 remy_exca_039_head[];
extern const u16 remy_exca_040_head[];
extern const u16 remy_exca_041_head[];
extern const u16 remy_exca_042_head[];
extern const u16 remy_exca_043_head[];
extern const u16 remy_exca_044_head[];
extern const u16 remy_exca_045_head[];
extern const u16 remy_exca_046_head[];
extern const u16 remy_exca_047_head[];
extern const u16 remy_exca_048_head[];
extern const u16 remy_exca_049_head[];
extern const u16 remy_exca_050_head[];
extern const u16 remy_exca_051_head[];
extern const u16 remy_saca_000[], remy_saca_001[], remy_saca_002[], remy_saca_024[], remy_saca_028[], remy_saca_029[], remy_saca_030[], remy_saca_031[], remy_saca_032[], remy_saca_036[], remy_saca_037[], remy_saca_038[], remy_saca_039[], remy_saca_040[], remy_saca_041[], remy_saca_042[], remy_saca_043[], remy_saca_044[], remy_saca_045[], remy_saca_046[], remy_saca_047[], remy_saca_048[], remy_saca_049[], remy_saca_050[], remy_saca_054[], remy_saca_055[], remy_saca_056[], remy_saca_057[], remy_saca_062[], remy_saca_063[], remy_saca_058[];
extern const u16 remy_saca_000_head[];
extern const u16 remy_saca_001_head[];
extern const u16 remy_saca_002_head[];
extern const u16 remy_saca_024_head[];
extern const u16 remy_saca_028_head[];
extern const u16 remy_saca_029_head[];
extern const u16 remy_saca_030_head[];
extern const u16 remy_saca_031_head[];
extern const u16 remy_saca_032_head[];
extern const u16 remy_saca_036_head[];
extern const u16 remy_saca_037_head[];
extern const u16 remy_saca_038_head[];
extern const u16 remy_saca_039_head[];
extern const u16 remy_saca_040_head[];
extern const u16 remy_saca_041_head[];
extern const u16 remy_saca_042_head[];
extern const u16 remy_saca_043_head[];
extern const u16 remy_saca_044_head[];
extern const u16 remy_saca_045_head[];
extern const u16 remy_saca_046_head[];
extern const u16 remy_saca_047_head[];
extern const u16 remy_saca_048_head[];
extern const u16 remy_saca_049_head[];
extern const u16 remy_saca_050_head[];
extern const u16 remy_saca_054_head[];
extern const u16 remy_saca_055_head[];
extern const u16 remy_saca_056_head[];
extern const u16 remy_saca_057_head[];
extern const u16 remy_saca_062_head[];
extern const u16 remy_saca_063_head[];
extern const u16 remy_saca_058_head[];
extern const u16 remy_cbca_000[], remy_cbca_001[], remy_cbca_002[], remy_cbca_003[], remy_cbca_004[], remy_cbca_005[], remy_cbca_006[], remy_cbca_007[], remy_cbca_008[], remy_cbca_009[], remy_cbca_010[], remy_cbca_011[], remy_cbca_012[], remy_cbca_013[], remy_cbca_014[], remy_cbca_015[], remy_cbca_016[], remy_cbca_017[], remy_cbca_018[], remy_cbca_019[], remy_cbca_020[], remy_cbca_021[], remy_cbca_022[], remy_cbca_023[];
extern const u16 remy_cbca_000_head[];
extern const u16 remy_cbca_001_head[];
extern const u16 remy_cbca_002_head[];
extern const u16 remy_cbca_003_head[];
extern const u16 remy_cbca_004_head[];
extern const u16 remy_cbca_005_head[];
extern const u16 remy_cbca_006_head[];
extern const u16 remy_cbca_007_head[];
extern const u16 remy_cbca_008_head[];
extern const u16 remy_cbca_009_head[];
extern const u16 remy_cbca_010_head[];
extern const u16 remy_cbca_011_head[];
extern const u16 remy_cbca_012_head[];
extern const u16 remy_cbca_013_head[];
extern const u16 remy_cbca_014_head[];
extern const u16 remy_cbca_015_head[];
extern const u16 remy_cbca_016_head[];
extern const u16 remy_cbca_017_head[];
extern const u16 remy_cbca_018_head[];
extern const u16 remy_cbca_019_head[];
extern const u16 remy_cbca_020_head[];
extern const u16 remy_cbca_021_head[];
extern const u16 remy_cbca_022_head[];
extern const u16 remy_cbca_023_head[];

/* normal scripts: 51 entries */
const u16* const remy_nmca[52] = {
    remy_nmca_000,  /* 0 KAMAE */
    remy_nmca_001,  /* 1 HURIMUKI */
    remy_nmca_002,  /* 2 FRONT WALK */
    remy_nmca_003,  /* 3 BACK WALK */
    remy_nmca_004,  /* 4 DASH HUMIKOMI */
    remy_nmca_005,  /* 5 DASH TOBINOKI */
    remy_nmca_006,  /* 6 KAGAMU */
    remy_nmca_007,  /* 7 KAGAMI KAMAE */
    remy_nmca_008,  /* 8 KAGAMI TURN */
    remy_nmca_008,  /* 9 KAGAMI F WALK */
    remy_nmca_008,  /* 10 KAGAMI B WALK */
    remy_nmca_011,  /* 11 STAND UP */
    remy_nmca_012,  /* 12 JUMP JUNBI */
    remy_nmca_013,  /* 13 SP JUMP JUNBI */
    remy_nmca_014,  /* 14 JUMP FRONT */
    remy_nmca_015,  /* 15 JUMP VERTICAL */
    remy_nmca_016,  /* 16 JUMP BACK */
    remy_nmca_017,  /* 17 S JUMP FRONT */
    remy_nmca_017,  /* 18 S JUMP V */
    remy_nmca_017,  /* 19 S JUMP BACK */
    remy_nmca_020,  /* 20 SP JUMP FRONT */
    remy_nmca_021,  /* 21 SP JUMP V */
    remy_nmca_022,  /* 22 SP JUMP BACK */
    remy_nmca_023,  /* 23 WALK END */
    remy_nmca_024,  /* 24 PARING HEAD */
    remy_nmca_024,  /* 25 PARING UP */
    remy_nmca_026,  /* 26 PARING DOWN */
    remy_nmca_027,  /* 27 PARING AIR F */
    remy_nmca_027,  /* 28 PARING AIR B */
    remy_nmca_029,  /* 29 GUARD HEAD */
    remy_nmca_030,  /* 30 GUARD UP */
    remy_nmca_031,  /* 31 GUARD DOWN */
    remy_nmca_032,  /* 32 GUARD AIR */
    remy_nmca_033,  /* 33 no name */
    remy_nmca_033,  /* 34 no name */
    remy_nmca_033,  /* 35 no name */
    remy_nmca_033,  /* 36 no name */
    remy_nmca_033,  /* 37 no name */
    remy_nmca_038,  /* 38 P BREAK ZUJOU */
    remy_nmca_038,  /* 39 P BREAK UP */
    remy_nmca_040,  /* 40 P BREAK DOWN */
    remy_nmca_041,  /* 41 P BREAK AIR F */
    remy_nmca_041,  /* 42 P BREAK AIR R */
    remy_nmca_043,  /* 43 TUKAMIHAZUSI */
    remy_nmca_044,  /* 44 TUKAMIHAZUSARE */
    remy_nmca_045,  /* 45 TUKAMIHAZUSI */
    remy_nmca_046,  /* 46 TUKAMIHAZUSARE */
    remy_nmca_047,  /* 47 no name */
    remy_nmca_048,  /* 48 no name */
    remy_nmca_049,  /* 49 no name */
    remy_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 remy_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_000[300] = {
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 48, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 49, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 46, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 47, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 50, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 45, 1), 0, 0, 0, 0,
    L4(64, 0, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 7, 44, 1), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 remy_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_001[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7220, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7221, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7222, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7223, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7224, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 remy_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 remy_nmca_002[124] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7231, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7232, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7233, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7234, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7235, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7236, 0, 8, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7237, 0, 8, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7238, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7239, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x723A, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x723B, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x723C, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x723D, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x723E, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 remy_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 remy_nmca_003[124] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7241, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7242, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7243, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7244, 0, 12, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7245, 0, 12, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7246, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7247, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7248, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7249, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x724A, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x724B, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x724C, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x724D, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x724E, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 remy_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 remy_nmca_004[92] = {
    CMD(CM_RJA, 0, 4, 7), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x72C1, 0, 13, 0, 0, 0, 32, 86),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C2, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C3, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C1, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x72C4, 0, 14, 0, 0, 0, 32, 87),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C5, 0, 15, 0, 0, 0, 32, 88),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C6, 0, 1, 0, 0, 0, 32, 89),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72C7, 0, 1, 0, 0, 0, 32, 90),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 remy_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 remy_nmca_005[92] = {
    CMD(CM_RJA, 0, 5, 7), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x72C8, 0, 16, 0, 0, 0, 32, 82),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C9, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72CA, 0, 16, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72C8, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x72CB, 0, 17, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72CC, 0, 1, 0, 0, 0, 32, 83),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72CD, 0, 1, 0, 0, 0, 32, 84),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72CE, 0, 1, 0, 0, 0, 32, 85),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 remy_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_nmca_006[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x725F, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7260, 0, 26, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 19, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7262, 0, 19, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7263, 0, 19, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 remy_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_nmca_007[756] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x7265, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7266, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7267, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7268, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7269, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726A, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726B, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726C, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726D, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726E, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x726F, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7270, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7271, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7272, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7273, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7274, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7275, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7276, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7277, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7278, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7279, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727A, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727B, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x727C, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727D, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727E, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727F, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D0, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D1, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D2, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D3, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D4, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D5, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D6, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D7, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D8, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73D9, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DA, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7274, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7275, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7276, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7277, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7278, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7279, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727A, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727B, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DB, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DC, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DD, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DE, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73DF, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E0, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E1, 0, 20, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E2, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E3, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E4, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E5, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E6, 0, 21, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E7, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E8, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73E9, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73EA, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7275, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7276, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7277, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7278, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7279, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727A, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x727B, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x73EB, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73EC, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73ED, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73EE, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73EF, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 559, 0, 0, 0, 0, 0x73F0, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F1, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F2, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F3, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F4, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F5, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F6, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F7, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F8, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73F9, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73FA, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73FB, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 remy_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_nmca_008[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7250, 0, 22, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7251, 0, 22, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7252, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7253, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7254, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7255, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 remy_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_011[92] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x725C, 0, 24, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725D, 0, 25, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 remy_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 remy_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_013[28] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 remy_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 remy_nmca_014[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7284, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7285, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7286, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x7287, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7288, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7289, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x728A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x728B, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x728C, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 remy_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 remy_nmca_015[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7284, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7285, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7286, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x7287, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7288, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7289, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x728A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x728B, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x728C, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 remy_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_nmca_016[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x7291, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7292, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7293, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7291, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7292, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7293, 0, 32, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7294, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7295, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7296, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x7297, 0, 32, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7298, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7299, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x729A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x729B, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x729C, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729D, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729E, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 remy_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 remy_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 remy_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 remy_nmca_020[164] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 18, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7284, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7285, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7286, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7287, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7288, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7289, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x728A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x728B, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x728C, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 remy_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 remy_nmca_021[164] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 18, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7281, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7282, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7283, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7284, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7285, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7286, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7287, 0, 29, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7288, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7289, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x728A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x728B, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x728C, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 remy_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 remy_nmca_022[164] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(1, 0, 282, 0, 0, 0, 0, 0x7291, 0, 31, 0, 0, 0, 18, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7292, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7293, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7291, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7292, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7293, 0, 32, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x7294, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x7295, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x7296, 0, 32, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7297, 0, 32, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7298, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x7299, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x729A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x729B, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x729C, 0, 30, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x729D, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x729E, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x729F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 remy_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x7208, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 remy_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 remy_nmca_024[68] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x72D9, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 548, 0, 0, 0, 0, 0x72DA, 0, 1, 0, 0, 0, 6, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72DB, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72DC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72DD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72DE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x72DF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 remy_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 remy_nmca_026[116] = {
    L4(3, 135, 0, 0, 0, 0, 0, 0x72B4, 0, 2, 0, 0, 0, 18, 6),
    L4(2, 0, 548, 0, 0, 0, 0, 0x741B, 0, 2, 0, 0, 0, 6, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x741C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x741D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x741E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x741F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7315, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7316, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 remy_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 remy_nmca_027[68] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x72BE, 0, 28, 0, 0, 0, 18, 6),
    L4(2, 0, 548, 0, 0, 0, 0, 0x72BF, 0, 28, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72BF, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72C0, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 remy_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 remy_nmca_029[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72A1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72A3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72A4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72A6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72A7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72A6, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x72A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72A8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 remy_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 remy_nmca_030[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72AC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72B1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72B1, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x72B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72B3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 29, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 remy_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 remy_nmca_031[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B4, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72B5, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72BB, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72BA, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72B9, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x72B8, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72B7, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x72B8, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x72B9, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72BD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7315, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7316, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 remy_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 remy_nmca_032[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BE, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 548, 0, 0, 0, 0, 0x72BE, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BF, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72C0, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 remy_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 remy_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0669, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 remy_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_038[76] = {
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
const u16 remy_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_nmca_040[76] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x067D, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x067C, 0, 2, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0690, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x0691, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0692, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 remy_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0683, 0, 28, 0, 0, 0, 18, 8),
    L4(250, 0, 548, 0, 0, 0, 0, 0x0684, 0, 28, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 remy_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_043[60] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x72D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 549, 0, 0, 0, 0, 0x72D0, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x72D2, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72D3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 remy_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_044[124] = {
    L4(3, 132, 0, 0, 0, 0, 0, 0x7501, 0, 397, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7502, 0, 400, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7507, 0, 398, 0, 0, 0, 0, 0),
    L4(10, 1, 0, 0, 0, 0, 0, 0x7508, 0, 398, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x7509, 0, 399, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x750A, 0, 395, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x750B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 remy_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_nmca_045[68] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x72BE, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 549, 0, 0, 0, 0, 0x72BF, 0, 28, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x72C0, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729D, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729E, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 remy_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_nmca_046[84] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 132, 0, 0, 0, 0, 0, 0x0655, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0656, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0657, 0, 28, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0658, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0659, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x065A, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x065B, 0, 28, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 3, 0x065C, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 remy_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 remy_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 remy_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 remy_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 remy_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 remy_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_nmca_050[76] = {
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
const u16* const remy_dmca[99] = {
    remy_dmca_000,  /* 0 GUARD HEAD */
    remy_dmca_001,  /* 1 GUARD UP */
    remy_dmca_002,  /* 2 GUARD DOWN */
    remy_dmca_003,  /* 3 GUARD AIR */
    remy_dmca_004,  /* 4 HUSHIN HEAD */
    remy_dmca_004,  /* 5 HUSHIN UP */
    remy_dmca_006,  /* 6 HUSHIN DOWN */
    remy_dmca_006,  /* 7 HUSHIN AIR */
    remy_dmca_008,  /* 8 FACE S */
    remy_dmca_009,  /* 9 FACE M */
    remy_dmca_010,  /* 10 FACE L */
    remy_dmca_010,  /* 11 FACE SP */
    remy_dmca_008,  /* 12 FOOK OKU S */
    remy_dmca_009,  /* 13 FOOK OKU M */
    remy_dmca_014,  /* 14 FOOK OKU L */
    remy_dmca_014,  /* 15 FOOK OKU SP */
    remy_dmca_008,  /* 16 FOOK TEMAE S */
    remy_dmca_009,  /* 17 FOOK TEMAE M */
    remy_dmca_018,  /* 18 FOOK TEMAE L */
    remy_dmca_018,  /* 19 FOOK TEMAE SP */
    remy_dmca_008,  /* 20 UPPER S */
    remy_dmca_009,  /* 21 UPPER M */
    remy_dmca_022,  /* 22 UPPER L */
    remy_dmca_022,  /* 23 UPPER SP */
    remy_dmca_024,  /* 24 NOUTEN S */
    remy_dmca_025,  /* 25 NOUTEN M */
    remy_dmca_026,  /* 26 NOUTEN L */
    remy_dmca_026,  /* 27 NOUTEN SP */
    remy_dmca_024,  /* 28 BODY BROW S */
    remy_dmca_029,  /* 29 BODY BROW M */
    remy_dmca_030,  /* 30 BODY BROW L */
    remy_dmca_030,  /* 31 BODY BROW SP */
    remy_dmca_024,  /* 32 BODY UPPER S */
    remy_dmca_029,  /* 33 BODY UPPER M */
    remy_dmca_034,  /* 34 BODY UPPER L */
    remy_dmca_034,  /* 35 BODY UPPER SP */
    remy_dmca_036,  /* 36 TATAKI S */
    remy_dmca_037,  /* 37 TATAKI M */
    remy_dmca_038,  /* 38 TATAKI L */
    remy_dmca_039,  /* 39 TATAKI SP */
    remy_dmca_040,  /* 40 TATAKI V. S */
    remy_dmca_041,  /* 41 TATAKI V. M */
    remy_dmca_042,  /* 42 TATAKI V. L */
    remy_dmca_043,  /* 43 TATAKI V. SP */
    remy_dmca_008,  /* 44 NOBASITA TE S */
    remy_dmca_009,  /* 45 NOBASITA TE M */
    remy_dmca_010,  /* 46 NOBASITA TE L */
    remy_dmca_010,  /* 47 NOBASITA TE SP */
    remy_dmca_048,  /* 48 KAGAMI S */
    remy_dmca_049,  /* 49 KAGAMI M */
    remy_dmca_050,  /* 50 KAGAMI L */
    remy_dmca_050,  /* 51 KAGAMI SP */
    remy_dmca_052,  /* 52 KGM TATAKI S */
    remy_dmca_053,  /* 53 KGM TATAKI M */
    remy_dmca_054,  /* 54 KGM TATAKI L */
    remy_dmca_055,  /* 55 KGM TATAKI SP */
    remy_dmca_056,  /* 56 KGM TTKI V.S */
    remy_dmca_057,  /* 57 KGM TTKI V.M */
    remy_dmca_058,  /* 58 KGM TTKI V.L */
    remy_dmca_059,  /* 59 KGM TTKI V.SP */
    remy_dmca_060,  /* 60 NEKOROBI S */
    remy_dmca_060,  /* 61 NEKOROBI M */
    remy_dmca_060,  /* 62 NEKOROBI L */
    remy_dmca_060,  /* 63 NEKOROBI SP */
    remy_dmca_064,  /* 64 OKIAGARI */
    remy_dmca_065,  /* 65 OKIAGARI F */
    remy_dmca_066,  /* 66 OKIAGARI B */
    remy_dmca_067,  /* 67 LOSE NO STAND */
    remy_dmca_068,  /* 68 LOSE SONABA */
    remy_dmca_069,  /* 69 LOSE KAGAMI */
    remy_dmca_070,  /* 70 PIYO */
    remy_dmca_071,  /* 71 UKEMI MOVE F */
    remy_dmca_072,  /* 72 UKEMI MOVE R */
    remy_dmca_073,  /* 73 SHIMEOTASARE */
    remy_dmca_074,  /* 74 TATI TOUKETU S */
    remy_dmca_074,  /* 75 TATI TOUKETU M */
    remy_dmca_074,  /* 76 TATI TOUKETU L */
    remy_dmca_074,  /* 77 TATI TOUKETU P */
    remy_dmca_078,  /* 78 KGM TOUKETU S */
    remy_dmca_079,  /* 79 KGM TOUKETU M */
    remy_dmca_080,  /* 80 KGM TOUKETU L */
    remy_dmca_080,  /* 81 KGM TOUKETU P */
    remy_dmca_082,  /* 82 TATI DENGEKI S */
    remy_dmca_083,  /* 83 TATI DENGEKI M */
    remy_dmca_084,  /* 84 TATI DENGEKI L */
    remy_dmca_084,  /* 85 TATI DENGEKI P */
    remy_dmca_082,  /* 86 KGM DENGEKI S */
    remy_dmca_083,  /* 87 KGM DENGEKI M */
    remy_dmca_084,  /* 88 KGM DENGEKI L */
    remy_dmca_084,  /* 89 KGM DENGEKI P */
    remy_dmca_090,  /* 90 OKIAGARI FRONT */
    remy_dmca_091,  /* 91 OKIAGARI REAR */
    remy_dmca_008,  /* 92 TATI MOE S */
    remy_dmca_009,  /* 93 TATI MOE M */
    remy_dmca_010,  /* 94 TATI MOE L */
    remy_dmca_010,  /* 95 TATI MOE SP */
    remy_dmca_096,  /* 96 no name */
    remy_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 remy_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_000[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72A2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 137, 0, 0, 0, 0, 0, 0x72A3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72A8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 remy_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_001[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72AD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 137, 0, 0, 0, 0, 0, 0x72AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B1, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72B3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72A9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72AB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 remy_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_002[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72BC, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 137, 0, 0, 0, 0, 0, 0x72B6, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B7, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72B9, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BA, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BB, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72BA, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72B9, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72BD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7315, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7316, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 remy_dmca_003_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_003[136] = {
    L6(1, 131, 0, 0, 0, 0, 0, 0x0683, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0683, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 138, 0, 0, 0, 0, 0, 0x0684, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0685, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
    L6(250, 135, 0, 0, 0, 0, 0, 0x0678, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0679, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x067A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 remy_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_004[44] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x72D0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x72D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x72D2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72D3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 remy_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_006[44] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x72D8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x72D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x72D2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x72D3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 remy_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_008[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72F0, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 133, 0, 0, 0, 0, 0, 0x72F0, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x72F0, 0, 48, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x72F1, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7317, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7318, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 remy_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_009[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72F2, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 134, 0, 0, 0, 0, 0, 0x72F3, 0, 49, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x72F4, 0, 49, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72F5, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x72F6, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7318, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 remy_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_010[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72F7, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 136, 546, 0, 0, 0, 0, 0x72F8, 0, 49, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x72F9, 0, 50, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FA, 0, 51, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FB, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FC, 0, 49, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72FD, 0, 48, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 remy_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_014[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72FF, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 139, 546, 0, 0, 0, 0, 0x7300, 0, 49, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x7301, 0, 50, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x7302, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x7303, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x7304, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x7305, 0, 51, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x7306, 0, 51, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x7307, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7308, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 remy_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_018[100] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x7309, 0, 48, 0, 0, 0, 0, 0),
    L4(250, 0, 546, 0, 0, 0, 0, 0x730A, 0, 49, 0, 0, 0, 0, 0),
    L4(1, 139, 0, 0, 0, 0, 0, 0x730B, 0, 50, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x730C, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x7303, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x7304, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x7305, 0, 51, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x7306, 0, 51, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x7307, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7308, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 remy_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_022[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7338, 0, 44, 0, 0, 0, 0, 0),
    L4(2, 138, 546, 0, 0, 0, 0, 0x7339, 0, 45, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x733A, 0, 45, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733A, 0, 46, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x733B, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FA, 0, 47, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FB, 0, 47, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FC, 0, 45, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72FD, 0, 44, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 remy_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_025[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x730D, 0, 52, 0, 0, 0, 0, 0),
    L4(1, 137, 0, 0, 0, 0, 0, 0x730E, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x730F, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7310, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7311, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7312, 0, 53, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7313, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7314, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 remy_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x730E, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 136, 546, 0, 0, 0, 0, 0x730F, 0, 53, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7310, 0, 54, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7311, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7312, 0, 54, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7313, 0, 53, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7314, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 remy_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_024[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7340, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 133, 0, 0, 0, 0, 0, 0x7341, 0, 52, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7341, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x7342, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7343, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 remy_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_029[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7344, 0, 52, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x7345, 0, 53, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7346, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7347, 0, 53, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7341, 0, 53, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7342, 0, 53, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7343, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 remy_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_030[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x734B, 0, 52, 0, 0, 0, 0, 0),
    L4(1, 143, 546, 0, 0, 0, 0, 0x734C, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x734D, 0, 54, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x734E, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x734F, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7350, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7351, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7352, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7353, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7354, 0, 55, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7355, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7356, 0, 54, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7357, 0, 54, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7358, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 remy_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7359, 0, 52, 0, 0, 0, 0, 0),
    L4(1, 138, 546, 0, 0, 0, 0, 0x735A, 0, 53, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7339, 0, 53, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733A, 0, 54, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x733B, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FA, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x72FB, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FC, 0, 53, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x72FD, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x72FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S */
const u16 remy_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_036[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 TATAKI M */
const u16 remy_dmca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_037[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 TATAKI L */
const u16 remy_dmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_038[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 TATAKI SP */
const u16 remy_dmca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_039[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(4, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 TATAKI V. S */
const u16 remy_dmca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_040[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 TATAKI V. M */
const u16 remy_dmca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_041[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 TATAKI V. L */
const u16 remy_dmca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_042[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TATAKI V. SP */
const u16 remy_dmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_043[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 55, 0, 0, 0, 0, 0),
    L4(4, 0, 547, 0, 0, 0, 0, 0x7381, 0, 55, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 remy_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_048[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7360, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 133, 0, 0, 0, 0, 0, 0x7360, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7361, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7362, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 remy_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_049[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7363, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x7364, 0, 57, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7365, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7366, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7367, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7368, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 remy_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_050[92] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x736A, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 138, 546, 0, 0, 0, 0, 0x736B, 0, 58, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x736C, 0, 59, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x736D, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x736E, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x736F, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7370, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7371, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S */
const u16 remy_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_052[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 KGM TATAKI M */
const u16 remy_dmca_053_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_053[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 KGM TATAKI L */
const u16 remy_dmca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_054[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 KGM TATAKI SP */
const u16 remy_dmca_055_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_055[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(4, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735D, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 KGM TTKI V.S */
const u16 remy_dmca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_056[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 KGM TTKI V.M */
const u16 remy_dmca_057_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_057[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 KGM TTKI V.L */
const u16 remy_dmca_058_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_058[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(4, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 KGM TTKI V.SP */
const u16 remy_dmca_059_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_059[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7369, 0, 56, 0, 0, 0, 0, 0),
    L4(5, 0, 547, 0, 0, 0, 0, 0x735C, 0, 56, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 remy_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_060[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x73A4, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 2, 546, 0, 0, 0, 0, 0x73A1, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73A0, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7330, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7331, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7332, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7333, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7334, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7335, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7336, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 remy_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_064[92] = {
    L4(12, 9, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B1, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B2, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B3, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B4, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x725C, 0, 35, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x725D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x725E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x725E, 0, 0, 0, 0, 0, 22, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 remy_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_065[84] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B1, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B2, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B5, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B6, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B7, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B8, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B9, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73BA, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 remy_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_066[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B1, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x73B2, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B9, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B8, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B7, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B6, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B5, 0, 35, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x73BA, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 remy_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 remy_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_068[204] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7387, 0, 42, 0, 0, 0, 32, 145),
    L4(250, 131, 0, 0, 0, 0, 0, 0x7387, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x7383, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7382, 0, 42, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7386, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7388, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7389, 0, 42, 0, 0, 0, 32, 121),
    L4(6, 0, 289, 0, 0, 0, 0, 0x735C, 0, 0, 0, 0, 0, 32, 122),
    L4(5, 0, 0, 0, 0, 0, 0, 0x735D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7329, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7330, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 288, 0, 0, 0, 0, 0x7331, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7332, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7333, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7334, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7335, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7336, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 remy_dmca_069_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_069[36] = {
    CMD(CM_ASXY, 210, 0, 0), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7389, 0, 42, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x7389, 0, 42, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 68, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 remy_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_070[60] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x7382, 0, 33, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7383, 0, 33, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7384, 0, 33, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7385, 0, 33, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7386, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 remy_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B1, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B2, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 551, 0, 0, 0, 0, 0x73B5, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73B6, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73B7, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73B8, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73B9, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73BA, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 remy_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_072[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B1, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73B2, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 551, 0, 0, 0, 0, 0x73B8, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B8, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B7, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73B6, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x73B4, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x725C, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x725D, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 remy_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_073[196] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x7387, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7383, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7382, 0, 42, 0, 0, 0, 0, 0),
    L4(10, 0, 289, 0, 0, 0, 0, 0x7386, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7388, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7389, 0, 42, 0, 0, 0, 32, 121),
    L4(6, 0, 0, 0, 0, 0, 0, 0x735C, 0, 0, 0, 0, 0, 32, 122),
    L4(5, 0, 0, 0, 0, 0, 0, 0x735D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 288, 0, 0, 0, 0, 0x7329, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x732F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7330, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7331, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7332, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7333, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7334, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7335, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7336, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S, 75 TATI TOUKETU M, 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 remy_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_074[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x72F0, 0, 48, 0, 0, 0, 0, 0),
    L4(250, 131, 546, 0, 0, 0, 0, 0x72F0, 0, 48, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x72F1, 0, 48, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 15, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 remy_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7360, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x7360, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7362, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 remy_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_079[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x7364, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x7364, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7367, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7368, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 remy_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x736A, 0, 56, 0, 0, 0, 0, 0),
    L4(250, 131, 546, 0, 0, 0, 0, 0x736A, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x736F, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7370, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7371, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 17, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 remy_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_082[52] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x738A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x738B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x738C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSE, 546, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 remy_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_083[52] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x738A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x738B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x738C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSE, 546, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 remy_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_dmca_084[52] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x738A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x738B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x738C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSE, 546, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 remy_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_090[92] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D7, 0, 35, 0, 0, 0, 0, 0),
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
const u16 remy_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_091[92] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x08D6, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0827, 0, 35, 0, 0, 0, 0, 0),
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
const u16 remy_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_096[44] = {
    L4(3, 2, 546, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 36, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 remy_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_dmca_097[44] = {
    L4(3, 2, 546, 0, 0, 0, 0, 0x7337, 0, 43, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7337, 0, 43, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x7337, 0, 43, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x7337, 0, 43, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 43, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const remy_btca[37] = {
    remy_btca_000,  /* 0 AIR NORMAL */
    remy_btca_001,  /* 1 ASIBARAI SIRI */
    remy_btca_002,  /* 2 ASIB TUNNOMERI */
    remy_btca_003,  /* 3 NOKEZORI */
    remy_btca_004,  /* 4 KUNOJI */
    remy_btca_005,  /* 5 KIRIMOMI */
    remy_btca_006,  /* 6 UPPER */
    remy_btca_007,  /* 7 BODY UPPER */
    remy_btca_008,  /* 8 HARAYARARE */
    remy_btca_009,  /* 9 TATAKI AIR */
    remy_btca_010,  /* 10 TTKI V. AIR */
    remy_btca_011,  /* 11 HUMI ASIB */
    remy_btca_012,  /* 12 FACE */
    remy_btca_013,  /* 13 ASIB SIRI LOSE */
    remy_btca_014,  /* 14 ASIB TUN LOSE */
    remy_btca_015,  /* 15 DENKI */
    remy_btca_016,  /* 16 KUNOJI NOKE */
    remy_btca_017,  /* 17 BODY UPPER SP */
    remy_btca_018,  /* 18 HANEAGARI */
    remy_btca_019,  /* 19 TOUKETSU A */
    remy_btca_020,  /* 20 BODY SLAM */
    remy_btca_021,  /* 21 IPPONZEOI */
    remy_btca_022,  /* 22 TOMOE RYU */
    remy_btca_023,  /* 23 MONKEY FLIP */
    remy_btca_024,  /* 24 TOMOE ORO */
    remy_btca_025,  /* 25 SNAKE FANG */
    remy_btca_026,  /* 26 FLANKEN.S */
    remy_btca_027,  /* 27 KISHINRIKI */
    remy_btca_028,  /* 28 SPLASH.M */
    remy_btca_029,  /* 29 HARAIGOSHI */
    remy_btca_030,  /* 30 ALEX B.D */
    remy_btca_031,  /* 31 GILL */
    remy_btca_032,  /* 32 HANEKAERI HARA */
    remy_btca_033,  /* 33 S HANEAGARI */
    remy_btca_034,  /* 34 TATUMAKIZANKU */
    remy_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 remy_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_000[68] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7340, 0, 338, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 546, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x7340, 0, 338, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x735A, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 remy_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7372, 0, 339, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x7373, 0, 340, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7374, 0, 341, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7375, 0, 342, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7376, 0, 343, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 remy_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 remy_btca_002[44] = {
    CMD(CM_RJA, 7, 33, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x737A, 0, 344, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x737B, 0, 345, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x737C, 0, 346, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 remy_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_003[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7320, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7321, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 remy_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_004[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x734B, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x734C, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x734D, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x734E, 0, 356, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x734F, 0, 356, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 remy_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_005[156] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7390, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7391, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7392, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7393, 0, 359, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7394, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7395, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7396, 0, 360, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7397, 0, 361, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7398, 0, 362, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7399, 0, 363, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739A, 0, 364, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739B, 0, 365, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739C, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739D, 0, 366, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739E, 0, 367, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x739F, 0, 368, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x739F, 0, 368, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 remy_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_006[140] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7338, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 547, 0, 0, 0, 0, 0x733C, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733D, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x733C, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733D, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x733E, 0, 371, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7321, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 remy_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_007[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x734B, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7359, 0, 372, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735A, 0, 373, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735B, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 remy_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_008[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7340, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x735A, 0, 373, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 6, 7, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 remy_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_009[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x7381, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735C, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x735D, 0, 378, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 remy_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_010[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7380, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 547, 0, 0, 0, 0, 0x7381, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x735C, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x735D, 0, 378, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 remy_btca_011_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_011[44] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x737A, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x737B, 0, 345, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x737C, 0, 346, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 remy_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_012[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x72F2, 0, 379, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7320, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7321, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 remy_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 remy_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 remy_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 remy_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_015[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 134, 0, 0, 0, 0, 0, 0x738A, 0, 380, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x738B, 0, 380, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x738C, 0, 380, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 remy_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_016[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x734B, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x734C, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x734D, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x734E, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x734F, 0, 356, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 remy_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_017[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x7320, 0, 347, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 547, 0, 0, 0, 0, 0x7321, 0, 348, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 remy_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_018[188] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(3, 0, 547, 0, 0, 0, 0, 0x732A, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7329, 0, 35, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7328, 0, 35, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7327, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7328, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x7329, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x732A, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x732B, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x732F, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 remy_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x72F2, 0, 379, 0, 0, 0, 0, 0),
    L4(250, 0, 547, 0, 0, 0, 0, 0x72F2, 0, 379, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 remy_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x739F, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 remy_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x739F, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 remy_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_022[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x7373, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7324, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7323, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x7322, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 remy_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_btca_023[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x735D, 0, 37, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 8, 0x7329, 0, 37, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 8, 0x7328, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 remy_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_024[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x735D, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7329, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7328, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 remy_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x7325, 0, 37, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7326, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 remy_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_026[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x735D, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7329, 0, 37, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x7328, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 remy_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_027[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 remy_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_028[44] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7327, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7328, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7329, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 remy_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_029[20] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 8, 0x7329, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 remy_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_030[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7320, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 547, 0, 0, 0, 0, 0x7321, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 37, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 37, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 remy_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_031[44] = {
    L4(2, 0, 547, 0, 0, 0, 0, 0x7373, 0, 37, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7374, 0, 37, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7375, 0, 37, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x7376, 0, 37, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 remy_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x7359, 0, 372, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x735A, 0, 373, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 remy_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_033[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x73A5, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 547, 0, 0, 0, 0, 0x73A4, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73A1, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x73A2, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 285, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 22, 38),
    L4(2, 2, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 remy_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_btca_034[140] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x7338, 0, 369, 0, 0, 0, 0, 0),
    L4(1, 0, 547, 0, 0, 0, 0, 0x733C, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733D, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x733C, 0, 370, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x733D, 0, 370, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x733E, 0, 371, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7321, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7322, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7323, 0, 350, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7324, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7325, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7326, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7327, 0, 354, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 3 entries */
const u16* const remy_caca[4] = {
    remy_caca_000,  /* 0 CATCH 1 */
    remy_caca_001,  /* 1 CATCH 2 */
    remy_caca_002,  /* 2 CATCH 3 */
    0
};

/* script: 0 CATCH 1 */
const u16 remy_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 remy_caca_000[244] = {
    CMD(CM_NGDA, 1542, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x7500, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7501, 0, 0, 0, 0, 0, 0, 0, 0, 48, 124, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7502, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7503, 0, 0, 0, 0, 0, 0, 0, 0, 96, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7504, 0, 0, 0, 0, 0, 0, 0, 0, 120, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7505, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7506, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x750C, 0, 0, 0, 0, 0, 0, 0, 0, 192, 128, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x750D, 0, 0, 0, 0, 0, 0, 0, 0, 216, 130, 0, 0),
    L6(3, 0, 549, 0, 0, 0, 0, 0x750E, 0, 0, 0, 0, 0, 0, 0, 0, 240, 132, 0, 0),
    L6(2, 2, 262, 0, 0, 0, 0, 0x750F, -2, 0, 0, 0, 0, 1, 140, 0, 264, 134, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x7510, 0, 0, 0, 0, 0, 0, 0, 0, 288, 136, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7511, 0, 0, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x7512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x7513, 0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7514, 0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7515, 0, 0, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x7516, 0, 0, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 remy_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 remy_caca_001[124] = {
    CMD(CM_NGDA, 1542, 60, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x7500, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7501, 0, 0, 0, 0, 0, 0, 0, 0, 48, 124, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7502, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x7503, 0, 0, 0, 0, 0, 0, 0, 0, 96, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7504, 0, 0, 0, 0, 0, 0, 0, 0, 120, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7505, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x7506, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    CMD(CM_PS_Y, 1, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 4, 156, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 remy_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 remy_caca_002[112] = {
    CMD(CM_NGDA, 1542, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x7500, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7501, 0, 0, 0, 0, 0, 0, 0, 0, 48, 124, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x7502, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7503, 0, 0, 0, 0, 0, 0, 0, 0, 96, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x73C0, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x73C0, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 6, 0, 0, 0, 0, 0, 0x7504, 0, 0, 0, 0, 0, 0, 0, 0, 120, 126, 0, 0),
    CMD(CM_JMP, 2, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const remy_cuca[69] = {
    remy_cuca_000,  /* 0 ALEX ZUTUKI */
    remy_cuca_001,  /* 1 ALEX BODY S */
    remy_cuca_002,  /* 2 ALEX BACK D */
    remy_cuca_003,  /* 3 ALEX POWER B */
    remy_cuca_004,  /* 4 ALEX SLEEPER */
    remy_cuca_005,  /* 5 RYU SEOINAGE */
    remy_cuca_006,  /* 6 IBUKI */
    remy_cuca_007,  /* 7 DADLEY L B */
    remy_cuca_008,  /* 8 IBUKI KUBIORI */
    remy_cuca_009,  /* 9 NECRO S T */
    remy_cuca_010,  /* 10 RYU TOMOENAGE */
    remy_cuca_011,  /* 11 YUN HIZAGERI */
    remy_cuca_012,  /* 12 ORO KUBISIME */
    remy_cuca_013,  /* 13 NECRO G S */
    remy_cuca_014,  /* 14 DUDDLEY D S */
    remy_cuca_015,  /* 15 YUN MONKEY F */
    remy_cuca_016,  /* 16 ORO TOMOENAGE */
    remy_cuca_017,  /* 17 ORO NIOURIKI */
    remy_cuca_018,  /* 18 ORO GIGOKU G */
    remy_cuca_019,  /* 19 YUN */
    remy_cuca_020,  /* 20 NECRO SNAKE F */
    remy_cuca_021,  /* 21 NECRO F S */
    remy_cuca_022,  /* 22 IBUKI HARAIG */
    remy_cuca_023,  /* 23 GILL SPLASH M */
    remy_cuca_024,  /* 24 KEN HIZAGERI */
    remy_cuca_025,  /* 25 ORO KISINRIKI */
    remy_cuca_026,  /* 26 SEAN TACKLE */
    remy_cuca_027,  /* 27 ALEX HYPER B */
    remy_cuca_028,  /* 28 NECRO SLAM D */
    remy_cuca_029,  /* 29 ELENA ASINAGE */
    remy_cuca_030,  /* 30 GILL IMPACT C */
    remy_cuca_031,  /* 31 ALEX S H B */
    remy_cuca_032,  /* 32 ALEX F N D */
    remy_cuca_033,  /* 33 no name */
    remy_cuca_034,  /* 34 IBUKI */
    remy_cuca_035,  /* 35 IBUKI YOROI D */
    remy_cuca_036,  /* 36 no name */
    remy_cuca_037,  /* 37 MAWARIKOMI M F */
    remy_cuca_038,  /* 38 HUGO BODY S */
    remy_cuca_039,  /* 39 HUGO N G T */
    remy_cuca_040,  /* 40 HUGO M S P */
    remy_cuca_041,  /* 41 HUGO S D B B */
    remy_cuca_042,  /* 42 no name */
    remy_cuca_043,  /* 43 no name */
    remy_cuca_044,  /* 44 no name */
    remy_cuca_045,  /* 45 no name */
    remy_cuca_046,  /* 46 no name */
    remy_cuca_047,  /* 47 no name */
    remy_cuca_048,  /* 48 no name */
    remy_cuca_049,  /* 49 no name */
    remy_cuca_050,  /* 50 no name */
    remy_cuca_051,  /* 51 no name */
    remy_cuca_052,  /* 52 no name */
    remy_cuca_053,  /* 53 no name */
    remy_cuca_054,  /* 54 no name */
    remy_cuca_055,  /* 55 no name */
    remy_cuca_056,  /* 56 no name */
    remy_cuca_057,  /* 57 no name */
    remy_cuca_058,  /* 58 no name */
    remy_cuca_059,  /* 59 no name */
    remy_cuca_060,  /* 60 no name */
    remy_cuca_061,  /* 61 no name */
    remy_cuca_062,  /* 62 no name */
    remy_cuca_063,  /* 63 no name */
    remy_cuca_064,  /* 64 no name */
    remy_cuca_065,  /* 65 no name */
    remy_cuca_066,  /* 66 no name */
    remy_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 remy_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x730F),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 remy_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7358),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 remy_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_002[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    CMD(CM_RMJA, 3, 2, 17),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 remy_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_003[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7374),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    CMD(CM_RMJA, 3, 3, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 remy_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_004[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7306),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7358),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7338),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x730D),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 remy_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7208),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 remy_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7403),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7403),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7404),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7404),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7423),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7420),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7409),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7408),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7408),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7314),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 remy_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734C),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x734D),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 remy_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7391),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 remy_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7345),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 remy_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7391),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7395),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 remy_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7345),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7346),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7347),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x734F),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 remy_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x72FF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 remy_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7326),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732A),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 2),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 remy_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7345),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x734C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 remy_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737C),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7373),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 remy_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7523),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7524),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7394),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7350),
    CMD(CM_RMJA, 3, 10, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 remy_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_017[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732D),
    CMD(CM_RMJA, 3, 17, 25),
    L2(250, 9, 0, 0, 0, 0, 0, 0x732C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 11),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 11),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 remy_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7389),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x73B5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x73B9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 3, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A3),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A4),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 remy_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7209),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7260),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7314),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x72F8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 remy_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x72E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72D8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x725D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7323),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7324),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 remy_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7314),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737A),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x737B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 remy_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_022[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7328),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 remy_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7375),
    L2(250, 0, 0, 0, 3, 0, 0, 0x734C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7374),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x732A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 remy_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7345),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7346),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7347),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 remy_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_025[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 remy_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7374),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7374),
    L2(250, 3, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7332),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7337),
    L2(250, 3, 0, 0, 0, 0, 0, 0x73A1),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7337),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 remy_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_027[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x732C),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 remy_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7326),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7322),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 remy_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7202),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7203),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 3, 0, 0, 0x734D),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7373),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 remy_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733D),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x733D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 remy_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x730F),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 remy_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7326),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A0),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 remy_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7321),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 remy_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_034[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    CMD(CM_RMJA, 3, 34, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7321),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 remy_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7403),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7403),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7404),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7404),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7423),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7420),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x740B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7409),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7408),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7408),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0744),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 remy_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FC),
    L2(250, 2, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7326),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A3),
    L2(250, 2, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A4),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A2),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 remy_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7209),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7260),
    L2(250, 0, 0, 0, 0, 0, 0, 0x725D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7314),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737C),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x7373),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 remy_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7358),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7398),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7395),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A0),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 remy_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 25, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 remy_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x744E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x738A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 3, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 2, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A5),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7337),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 remy_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7325),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 remy_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7345),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734E),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x734F),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 remy_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7337),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7337),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 remy_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x744E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x738A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 3, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 2, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x739F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7325),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 remy_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7347),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7344),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 remy_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 3, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7395),
    L2(250, 0, 0, 0, 2, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72D3),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 remy_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_047[120] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7351),
    L2(250, 0, 0, 0, 1, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    CMD(CM_RMJA, 3, 47, 28),
    L2(250, 9, 0, 0, 1, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 remy_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7317),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x730F),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 remy_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7356),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732A),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 remy_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7329),
    L2(250, 0, 0, 0, 3, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7324),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7323),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 remy_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7380),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7356),
    L2(250, 0, 0, 0, 1, 0, 0, 0x730C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7385),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7387),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7372),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 2, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7346),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7372),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7380),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7388),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x730D),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 remy_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7391),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 3, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7373),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735D),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7329),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 remy_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7317),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 2, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x73B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x732B),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x732C),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 remy_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7397),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7396),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7395),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7394),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7393),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7392),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7391),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7390),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7320),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 remy_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72CE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7317),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7325),
    L2(250, 0, 0, 0, 2, 0, 0, 0x739C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x73B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x7321),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7324),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 remy_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_056[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7317),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x730D),
    CMD(CM_RMJA, 3, 56, 14),
    L2(250, 9, 0, 0, 0, 0, 13, 0x7373),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 remy_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7359),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x735A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 remy_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x733D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 remy_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735C),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 remy_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_060[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7318),
    CMD(CM_RMJA, 3, 60, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7318),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 remy_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x728C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x735C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7322),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 remy_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730A),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730B),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730C),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7304),
    CMD(CM_PA_X, 0, -1536, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7307),
    CMD(CM_PA_X, 0, 6144, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7340),
    CMD(CM_PA_X, 0, -7168, 0),
    CMD(CM_PS_Y, 0, 0, 2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737B),
    CMD(CM_PA_X, 0, -6144, 0),
    CMD(CM_PS_Y, 0, 0, 39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x737C),
    CMD(CM_PA_X, 0, -2304, 0),
    CMD(CM_PS_Y, 0, 0, 114),
    L2(250, 0, 0, 0, 2, 0, 0, 0x735A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x732B),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x732C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 remy_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7357),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7347),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x734B),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 547, 0, 0, 0, 0, 0x734C),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 remy_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7356),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x735A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 remy_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7303),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x7305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x737C),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7373),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 remy_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x72FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7376),
    L2(250, 0, 0, 0, 0, 0, 0, 0x73A4),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x73A4),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 remy_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x730F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7310),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7311),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7312),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7313),
    L2(250, 0, 0, 0, 0, 0, 0, 0x72F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x7321),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x7323),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 158 entries */
const u16* const remy_atca[159] = {
    remy_atca_000,  /* 0 S PUNCH A */
    remy_atca_001,  /* 1 S PUNCH B */
    remy_atca_001,  /* 2 S PUNCH C */
    remy_atca_003,  /* 3 M PUNCH A */
    remy_atca_004,  /* 4 M PUNCH B */
    remy_atca_004,  /* 5 M PUNCH C */
    remy_atca_006,  /* 6 L PUNCH A */
    remy_atca_007,  /* 7 L PUNCH B */
    remy_atca_007,  /* 8 L PUNCH C */
    remy_atca_009,  /* 9 S KICK A */
    remy_atca_010,  /* 10 S KICK B */
    remy_atca_010,  /* 11 S KICK C */
    remy_atca_012,  /* 12 M KICK A */
    remy_atca_013,  /* 13 M KICK B */
    remy_atca_014,  /* 14 M KICK C */
    remy_atca_015,  /* 15 L KICK A */
    remy_atca_016,  /* 16 L KICK B */
    remy_atca_016,  /* 17 L KICK C */
    remy_atca_018,  /* 18 KAGAMI P A */
    remy_atca_018,  /* 19 KAGAMI P B */
    remy_atca_018,  /* 20 KAGAMI P C */
    remy_atca_021,  /* 21 KAGAMI P A */
    remy_atca_021,  /* 22 KAGAMI P B */
    remy_atca_021,  /* 23 KAGAMI P C */
    remy_atca_024,  /* 24 KAGAMI P A */
    remy_atca_024,  /* 25 KAGAMI P B */
    remy_atca_024,  /* 26 KAGAMI P C */
    remy_atca_027,  /* 27 KAGAMI K A */
    remy_atca_027,  /* 28 KAGAMI K B */
    remy_atca_027,  /* 29 KAGAMI K C */
    remy_atca_030,  /* 30 KAGAMI K A */
    remy_atca_030,  /* 31 KAGAMI K B */
    remy_atca_030,  /* 32 KAGAMI K C */
    remy_atca_033,  /* 33 KAGAMI K A */
    remy_atca_033,  /* 34 KAGAMI K B */
    remy_atca_033,  /* 35 KAGAMI K C */
    remy_atca_036,  /* 36 V JUMP P S A */
    remy_atca_036,  /* 37 V JUMP P S B */
    remy_atca_038,  /* 38 V JUMP P M A */
    remy_atca_038,  /* 39 V JUMP P M B */
    remy_atca_040,  /* 40 V JUMP P L A */
    remy_atca_040,  /* 41 V JUMP P L B */
    remy_atca_042,  /* 42 V JUMP K S A */
    remy_atca_042,  /* 43 V JUMP K S B */
    remy_atca_044,  /* 44 V JUMP K M A */
    remy_atca_044,  /* 45 V JUMP K M B */
    remy_atca_046,  /* 46 V JUMP K L A */
    remy_atca_046,  /* 47 V JUMP K L B */
    remy_atca_048,  /* 48 F JUMP P S A */
    remy_atca_048,  /* 49 F JUMP P S B */
    remy_atca_050,  /* 50 F JUMP P M A */
    remy_atca_050,  /* 51 F JUMP P M B */
    remy_atca_052,  /* 52 F JUMP P L A */
    remy_atca_052,  /* 53 F JUMP P L B */
    remy_atca_054,  /* 54 F JUMP K S A */
    remy_atca_054,  /* 55 F JUMP K S B */
    remy_atca_056,  /* 56 F JUMP K M A */
    remy_atca_056,  /* 57 F JUMP K M B */
    remy_atca_058,  /* 58 F JUMP K L A */
    remy_atca_058,  /* 59 F JUMP K L B */
    remy_atca_060,  /* 60 B JUMP P S A */
    remy_atca_060,  /* 61 B JUMP P S B */
    remy_atca_062,  /* 62 B JUMP P M A */
    remy_atca_062,  /* 63 B JUMP P M B */
    remy_atca_064,  /* 64 B JUMP P L A */
    remy_atca_064,  /* 65 B JUMP P L B */
    remy_atca_066,  /* 66 B JUMP K S A */
    remy_atca_066,  /* 67 B JUMP K S B */
    remy_atca_068,  /* 68 B JUMP K M A */
    remy_atca_068,  /* 69 B JUMP K M B */
    remy_atca_070,  /* 70 B JUMP K L A */
    remy_atca_070,  /* 71 B JUMP K L B */
    remy_atca_072,  /* 72 SP V JP S P A */
    remy_atca_072,  /* 73 SP V JP S P B */
    remy_atca_074,  /* 74 SP V JP M P A */
    remy_atca_074,  /* 75 SP V JP M P B */
    remy_atca_076,  /* 76 SP V JP L P A */
    remy_atca_076,  /* 77 SP V JP L P B */
    remy_atca_078,  /* 78 SP V JP S K A */
    remy_atca_078,  /* 79 SP V JP S K B */
    remy_atca_080,  /* 80 SP V JP M K A */
    remy_atca_080,  /* 81 SP V JP M K B */
    remy_atca_082,  /* 82 SP V JP L K A */
    remy_atca_082,  /* 83 SP V JP L K B */
    remy_atca_084,  /* 84 SP F JP S P A */
    remy_atca_084,  /* 85 SP F JP S P B */
    remy_atca_086,  /* 86 SP F JP M P A */
    remy_atca_086,  /* 87 SP F JP M P B */
    remy_atca_088,  /* 88 SP F JP L P A */
    remy_atca_088,  /* 89 SP F JP L P B */
    remy_atca_090,  /* 90 SP F JP S K A */
    remy_atca_090,  /* 91 SP F JP S K B */
    remy_atca_092,  /* 92 SP F JP M K A */
    remy_atca_092,  /* 93 SP F JP M K B */
    remy_atca_094,  /* 94 SP F JP L K A */
    remy_atca_094,  /* 95 SP F JP L K B */
    remy_atca_096,  /* 96 SP B JP S P A */
    remy_atca_096,  /* 97 SP B JP S P B */
    remy_atca_098,  /* 98 SP B JP M P A */
    remy_atca_098,  /* 99 SP B JP M P B */
    remy_atca_100,  /* 100 SP B JP L P A */
    remy_atca_100,  /* 101 SP B JP L P B */
    remy_atca_102,  /* 102 SP B JP S K A */
    remy_atca_102,  /* 103 SP B JP S K B */
    remy_atca_104,  /* 104 SP B JP M K A */
    remy_atca_104,  /* 105 SP B JP M K B */
    remy_atca_106,  /* 106 SP B JP L K A */
    remy_atca_106,  /* 107 SP B JP L K B */
    remy_atca_108,  /* 108 S V JP S P A */
    remy_atca_108,  /* 109 S V JP S P B */
    remy_atca_110,  /* 110 S V JP M P A */
    remy_atca_110,  /* 111 S V JP M P B */
    remy_atca_112,  /* 112 S V JP L P A */
    remy_atca_112,  /* 113 S V JP L P B */
    remy_atca_114,  /* 114 S V JP S K A */
    remy_atca_114,  /* 115 S V JP S K B */
    remy_atca_116,  /* 116 S V JP M K A */
    remy_atca_116,  /* 117 S V JP M K B */
    remy_atca_118,  /* 118 S V JP L K A */
    remy_atca_118,  /* 119 S V JP L K B */
    remy_atca_108,  /* 120 S F JP S P A */
    remy_atca_108,  /* 121 S F JP S P B */
    remy_atca_110,  /* 122 S F JP M P A */
    remy_atca_110,  /* 123 S F JP M P B */
    remy_atca_112,  /* 124 S F JP L P A */
    remy_atca_112,  /* 125 S F JP L P B */
    remy_atca_114,  /* 126 S F JP S K A */
    remy_atca_114,  /* 127 S F JP S K B */
    remy_atca_116,  /* 128 S F JP M K A */
    remy_atca_116,  /* 129 S F JP M K B */
    remy_atca_118,  /* 130 S F JP L K A */
    remy_atca_118,  /* 131 S F JP L K B */
    remy_atca_108,  /* 132 S B JP S P A */
    remy_atca_108,  /* 133 S B JP S P B */
    remy_atca_110,  /* 134 S B JP M P A */
    remy_atca_110,  /* 135 S B JP M P B */
    remy_atca_112,  /* 136 S B JP L P A */
    remy_atca_112,  /* 137 S B JP L P B */
    remy_atca_114,  /* 138 S B JP S K A */
    remy_atca_114,  /* 139 S B JP S K B */
    remy_atca_116,  /* 140 S B JP M K A */
    remy_atca_116,  /* 141 S B JP M K B */
    remy_atca_118,  /* 142 S B JP L K A */
    remy_atca_118,  /* 143 S B JP L K B */
    remy_atca_144,  /* 144 TUKAMIKAKARI A */
    remy_atca_145,  /* 145 TUKAMIKAKARI B */
    remy_atca_146,  /* 146 TUKAMIKAKARI C */
    remy_atca_144,  /* 147 TUKAMIKAKARI D */
    remy_atca_144,  /* 148 TUKAMIKAKARI E */
    remy_atca_144,  /* 149 TUKAMIKAKARI F */
    remy_atca_144,  /* 150 TUKAMI AIR A */
    remy_atca_144,  /* 151 TUKAMI AIR B */
    remy_atca_144,  /* 152 TUKAMI AIR C */
    remy_atca_144,  /* 153 TUKAMI AIR D */
    remy_atca_144,  /* 154 TUKAMI AIR E */
    remy_atca_144,  /* 155 TUKAMI AIR F */
    remy_atca_156,  /* 156 follow-up of CATCH 2 */
    remy_atca_157,  /* 157 follow-up of M KICK A */
    0
};

/* script: 0 S PUNCH A */
const u16 remy_atca_000_head[4] = { HEAD(4, 0, 0, 9, 0, 1, 0) };
const u16 remy_atca_000[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x73BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x73BC, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x73BD, -7, 61, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73BE, 0, 62, 405, 0, 104, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73BF, 0, 63, 405, 0, 8, 21, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x73C0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 remy_atca_001_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 remy_atca_001[92] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7400, 0, 64, 0, 0, 0, 32, 92),
    L4(1, 0, 268, 0, 0, 0, 0, 0x7400, 0, 64, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(5, 0, 268, 0, 0, 0, 0, 0x7400, 0, 64, 0, 0, 0, 32, 95),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7401, -8, 65, 0, 128, 0, 32, 93),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7402, 0, 66, 149, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7403, 0, 67, 149, 0, 24, 21, 4),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7404, 0, 68, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 remy_atca_003_head[4] = { HEAD(4, 0, 2, 9, 0, 1, 0) };
const u16 remy_atca_003[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7433, 0, 69, 0, 0, 0, 32, 53),
    L4(3, 0, 269, 0, 0, 0, 0, 0x7434, 0, 70, 0, 0, 0, 32, 54),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7435, -9, 71, 0, 134, 96, 32, 55),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7436, 0, 72, 0, 134, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7437, 0, 73, 0, 128, 96, 32, 56),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7438, 0, 74, 0, 0, 96, 32, 57),
    CMD(CM_ASXY, 116, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7439, 0, 75, 0, 0, 96, 21, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x743A, 0, 76, 0, 0, 0, 32, 59),
    L4(3, 0, 0, 0, 0, 0, 0, 0x743B, 0, 1, 0, 0, 0, 32, 60),
    CMD(CM_ASXY, 122, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 remy_atca_004_head[4] = { HEAD(4, 0, 2, 12, 0, 1, 0) };
const u16 remy_atca_004[100] = {
    CMD(CM_EXEC, 30, 152, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x7405, 0, 77, 0, 0, 0, 32, 1),
    L4(3, 0, 269, 0, 0, 0, 0, 0x7406, 0, 78, 0, 0, 0, 32, 2),
    L4(1, 0, 548, 0, 0, 0, 0, 0x7407, -10, 79, 0, 134, 0, 32, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7408, 0, 80, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7409, 0, 81, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x740A, 0, 81, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 8, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x740B, 0, 82, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x740C, 0, 83, 0, 0, 0, 32, 5),
    L4(3, 64, 0, 0, 0, 0, 0, 0x740D, 0, 84, 0, 0, 0, 32, 6),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 remy_atca_006_head[4] = { HEAD(4, 0, 4, 6, 0, 1, 0) };
const u16 remy_atca_006[132] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x7425, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7426, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7427, 0, 86, 0, 0, 0, 32, 8),
    L4(1, 0, 270, 0, 0, 0, 0, 0x7428, 0, 86, 0, 0, 0, 32, 9),
    L4(1, 0, 552, 0, 0, 0, 0, 0x7429, -11, 87, 0, 64, 96, 32, 10),
    L4(1, 0, 0, 0, 0, 0, 0, 0x742A, 12, 88, 0, 128, 0, 32, 11),
    L4(5, 0, 0, 0, 0, 0, 0, 0x742B, 0, 89, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x742C, 0, 90, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x742D, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x742E, 0, 91, 0, 0, 0, 32, 12),
    L4(2, 64, 0, 0, 0, 0, 0, 0x742F, 0, 92, 0, 0, 0, 32, 13),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7430, 0, 92, 0, 0, 0, 32, 14),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7431, 0, 92, 0, 0, 0, 32, 15),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7432, 0, 92, 0, 0, 0, 32, 91),
    L4(3, 0, 0, 0, 0, 0, 0, 0x743C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 remy_atca_007_head[4] = { HEAD(4, 0, 4, 10, 0, 1, 0) };
const u16 remy_atca_007[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x740E, 0, 93, 0, 0, 0, 32, 16),
    L4(4, 0, 0, 0, 0, 0, 0, 0x740F, 0, 94, 0, 0, 0, 32, 17),
    L4(2, 0, 270, 0, 0, 0, 0, 0x740F, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7410, 0, 95, 0, 0, 0, 32, 18),
    CMD(CM_EXEC, 30, 153, 0), 0, 0, 0, 0,
    L4(2, 0, 549, 0, 0, 0, 0, 0x7411, -13, 96, 0, 136, 0, 32, 19),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7412, 0, 97, 0, 128, 0, 32, 20),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7413, 0, 98, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7414, 0, 98, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7415, 0, 99, 0, 0, 0, 32, 21),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7416, 0, 100, 0, 0, 0, 32, 22),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7417, 0, 101, 0, 0, 0, 32, 23),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7418, 0, 101, 0, 0, 0, 32, 24),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A */
const u16 remy_atca_009_head[4] = { HEAD(4, 0, 1, 6, 0, 1, 0) };
const u16 remy_atca_009[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x746F, 0, 102, 0, 0, 0, 32, 96),
    L4(1, 0, 268, 0, 0, 0, 0, 0x7470, 0, 103, 0, 0, 0, 32, 97),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7471, -14, 104, 0, 128, 96, 32, 98),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7472, 0, 104, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7473, 0, 105, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7475, 0, 105, 0, 0, 0, 32, 99),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7476, 0, 105, 0, 0, 0, 32, 100),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7477, 0, 106, 0, 0, 0, 32, 101),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7478, 0, 106, 0, 0, 0, 32, 102),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 S KICK B, 11 S KICK C */
const u16 remy_atca_010_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 0) };
const u16 remy_atca_010[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x7440, 0, 107, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x7440, 0, 107, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7441, -15, 108, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7442, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7443, 0, 109, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7444, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7445, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 remy_atca_012_head[4] = { HEAD(4, 0, 3, 6, 0, 1, 0) };
const u16 remy_atca_012[100] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x746F, 0, 112, 0, 0, 0, 32, 96),
    L4(1, 0, 269, 0, 0, 0, 0, 0x7470, 0, 113, 0, 0, 0, 32, 97),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7471, -16, 114, 3072, 128, 104, 32, 98),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7472, 0, 114, 3072, 0, 104, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7473, 0, 115, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7474, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7475, 0, 115, 0, 0, 0, 32, 99),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7476, 0, 115, 0, 0, 0, 32, 100),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7477, 0, 116, 0, 0, 0, 32, 101),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7478, 0, 116, 0, 0, 0, 32, 102),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 remy_atca_013_head[4] = { HEAD(4, 0, 3, 14, 0, 1, 0) };
const u16 remy_atca_013[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x7446, 0, 117, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 0, 0x7447, 0, 118, 0, 0, 0, 32, 25),
    L4(1, 0, 549, 0, 0, 0, 0, 0x7448, -17, 119, 0, 133, 0, 32, 26),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7449, 0, 120, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x744A, 0, 120, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x744A, 0, 121, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x744B, 0, 122, 0, 0, 0, 32, 27),
    L4(4, 0, 0, 0, 0, 0, 0, 0x744C, 0, 123, 0, 0, 0, 32, 28),
    L4(4, 64, 0, 0, 0, 0, 0, 0x744D, 0, 117, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 remy_atca_014_head[4] = { HEAD(4, 0, 3, 10, 0, 1, 0) };
const u16 remy_atca_014[124] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x7580, 0, 319, 0, 0, 0, 32, 114),
    L4(3, 0, 552, 0, 0, 0, 0, 0x7581, 0, 320, 0, 0, 0, 32, 115),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7582, 0, 321, 0, 0, 0, 32, 116),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7583, 0, 322, 0, 0, 0, 32, 117),
    L4(1, 0, 269, 0, 0, 0, 0, 0x7584, 0, 323, 0, 0, 0, 32, 118),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7585, -52, 324, 0, 136, 0, 32, 119),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7586, 0, 325, 0, 128, 0, 0, 0),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x7587, 0, 326, 0, 0, 0, 32, 120),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7588, 0, 327, 0, 0, 0, 32, 119),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7589, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x758A, 0, 329, 0, 0, 0, 32, 119),
    L4(3, 0, 0, 0, 0, 0, 0, 0x758B, 0, 330, 0, 0, 0, 32, 119),
    L4(3, 64, 0, 0, 0, 0, 0, 0x758C, 0, 331, 0, 0, 0, 32, 117),
    CMD(CM_JPSS, 7, 16, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A */
const u16 remy_atca_015_head[4] = { HEAD(4, 0, 5, 9, 0, 2, 0) };
const u16 remy_atca_015[132] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x7460, 0, 1, 0, 0, 0, 32, 29),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7461, 0, 124, 0, 0, 0, 32, 30),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7462, 0, 124, 0, 0, 0, 32, 31),
    L4(2, 0, 270, 0, 0, 0, 0, 0x7463, 0, 124, 0, 0, 0, 32, 32),
    L4(2, 0, 549, 0, 0, 0, 0, 0x7464, -18, 125, 0, 64, 96, 0, 0),
    L4(1, 0, 551, 0, 0, 0, 0, 0x7465, -19, 126, 0, 137, 0, 32, 33),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7466, 0, 127, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7467, 0, 127, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7468, 0, 128, 0, 64, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7469, 0, 129, 0, 0, 0, 32, 34),
    L4(3, 0, 0, 0, 0, 0, 0, 0x746A, 0, 130, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x746B, 0, 130, 0, 0, 0, 32, 35),
    L4(4, 64, 0, 0, 0, 0, 0, 0x746C, 0, 131, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x746D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x746E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 L KICK B, 17 L KICK C */
const u16 remy_atca_016_head[4] = { HEAD(4, 0, 5, 11, 0, 1, 0) };
const u16 remy_atca_016[132] = {
    CMD(CM_EXEC, 30, 155, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x744E, 0, 132, 0, 0, 0, 32, 103),
    L4(4, 0, 270, 1, 0, 0, 0, 0x744F, 0, 133, 0, 0, 0, 32, 104),
    L4(2, 0, 550, 1, 0, 0, 0, 0x7450, 0, 134, 0, 0, 0, 32, 105),
    L4(1, 0, 0, 1, 0, 0, 0, 0x7451, -20, 135, 0, 128, 0, 32, 106),
    L4(2, 0, 0, 1, 0, 0, 0, 0x7452, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x7452, 0, 137, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7453, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7454, 0, 138, 0, 0, 0, 32, 107),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7455, 0, 139, 0, 0, 0, 32, 108),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7456, 0, 140, 0, 0, 0, 32, 109),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7457, 0, 140, 0, 0, 0, 32, 110),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7458, 0, 141, 0, 0, 0, 32, 111),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7459, 0, 141, 0, 0, 0, 32, 112),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7201, 0, 141, 0, 0, 0, 32, 113),
    CMD(CM_JPSS, 7, 16, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 remy_atca_018_head[4] = { HEAD(4, 32, 0, 12, 0, 1, 0) };
const u16 remy_atca_018[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7480, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x7480, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7484, 0, 142, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x74BD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7481, -44, 143, 0, 137, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7481, -21, 143, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7482, 0, 143, 18, 64, 104, 0, 4),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7483, 0, 142, 18, 0, 120, 21, 4),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7484, 0, 142, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7485, 0, 144, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7486, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7265, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 remy_atca_021_head[4] = { HEAD(4, 32, 2, 12, 0, 1, 0) };
const u16 remy_atca_021[124] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7487, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7488, 0, 145, 0, 0, 0, 32, 36),
    L4(1, 0, 269, 0, 0, 0, 0, 0x7489, 0, 146, 0, 0, 0, 32, 37),
    L4(1, 0, 548, 0, 0, 0, 0, 0x748A, -22, 147, 0, 128, 0, 32, 38),
    L4(2, 0, 0, 0, 0, 0, 0, 0x748B, 0, 148, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x748C, 0, 148, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x748D, 0, 149, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x748E, 0, 150, 0, 0, 0, 32, 39),
    L4(3, 0, 0, 0, 0, 0, 0, 0x748F, 0, 2, 0, 0, 0, 32, 40),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7490, 0, 2, 0, 0, 0, 32, 41),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7265, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 remy_atca_024_head[4] = { HEAD(4, 32, 4, 7, 0, 1, 0) };
const u16 remy_atca_024[140] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7492, 0, 151, 0, 0, 0, 32, 44),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7493, 0, 152, 0, 0, 0, 32, 45),
    L4(3, 0, 270, 0, 0, 0, 0, 0x7493, 0, 152, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7494, 0, 153, 0, 0, 0, 32, 46),
    L4(1, 0, 552, 0, 0, 0, 0, 0x7495, 0, 154, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7496, -23, 155, 0, 0, 0, 32, 47),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7497, 0, 156, 0, 0, 0, 32, 48),
    L4(6, 0, 0, 0, 0, 0, 0, 0x7498, 0, 157, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7499, 0, 158, 0, 0, 0, 32, 49),
    L4(4, 0, 0, 0, 0, 0, 0, 0x749A, 0, 159, 0, 0, 0, 32, 50),
    L4(3, 0, 0, 0, 0, 0, 0, 0x749B, 0, 2, 0, 0, 0, 32, 51),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 32, 52),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7265, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 remy_atca_027_head[4] = { HEAD(4, 32, 1, 12, 0, 1, 0) };
const u16 remy_atca_027[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x749C, 0, 200, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x749C, 0, 200, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x749C, 0, 200, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x749D, -24, 201, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x749E, 0, 201, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x749F, 0, 202, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74A0, 0, 200, 0, 0, 0, 0, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74A1, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x74A2, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7256, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 18, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 remy_atca_030_head[4] = { HEAD(4, 32, 3, 13, 0, 1, 0) };
const u16 remy_atca_030[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x74A3, 0, 205, 0, 0, 0, 32, 127),
    L4(4, 0, 269, 0, 0, 0, 0, 0x74A4, 0, 206, 0, 0, 0, 32, 128),
    L4(1, 0, 549, 0, 0, 0, 0, 0x74A5, -25, 207, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74A6, 0, 208, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x74A7, 0, 209, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74A8, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74A9, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74AA, 0, 212, 0, 0, 0, 32, 129),
    L4(3, 64, 0, 0, 0, 0, 0, 0x74AB, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7419, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x741A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 18, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 remy_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 2, 0) };
const u16 remy_atca_033[172] = {
    L4(4, 0, 549, 0, 0, 0, 0, 0x74AD, 0, 214, 0, 0, 0, 32, 131),
    L4(2, 0, 270, 0, 0, 0, 0, 0x74AE, 0, 215, 0, 0, 0, 32, 132),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74AF, 0, 216, 0, 0, 0, 32, 133),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74B0, -26, 217, 0, 64, 0, 32, 134),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74B1, 0, 218, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74B2, 0, 219, 0, 0, 0, 32, 135),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74B3, 0, 220, 0, 0, 0, 32, 136),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74B4, 0, 221, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74B5, 0, 222, 0, 0, 0, 32, 137),
    L4(2, 0, 551, 0, 0, 0, 0, 0x74B6, 0, 223, 0, 0, 0, 32, 138),
    L4(2, 0, 270, 0, 0, 0, 0, 0x74B7, 0, 224, 0, 0, 0, 32, 138),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74B8, -27, 225, 0, 128, 0, 32, 139),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74B9, 0, 226, 0, 64, 0, 0, 0),
    CMD(CM_ASXY, 280, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x74BA, 0, 227, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74BB, 0, 228, 0, 0, 0, 32, 141),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74BC, 0, 2, 0, 0, 0, 32, 142),
    L4(4, 0, 0, 0, 0, 0, 0, 0x74AB, 0, 2, 0, 0, 0, 32, 143),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7419, 0, 2, 0, 0, 0, 32, 144),
    L4(3, 64, 0, 0, 0, 0, 0, 0x741A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 18, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 remy_atca_036_head[4] = { HEAD(4, 22, 0, 11, 0, 1, 0) };
const u16 remy_atca_036[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 48, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 remy_atca_038_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 remy_atca_038[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 50, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 remy_atca_040_head[4] = { HEAD(4, 22, 4, 13, 0, 1, 0) };
const u16 remy_atca_040[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 52, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 remy_atca_042_head[4] = { HEAD(4, 22, 1, 8, 0, 1, 0) };
const u16 remy_atca_042[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 54, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 remy_atca_044_head[4] = { HEAD(4, 22, 3, 13, 0, 1, 0) };
const u16 remy_atca_044[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 56, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 remy_atca_046_head[4] = { HEAD(4, 22, 5, 14, 0, 1, 0) };
const u16 remy_atca_046[20] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 4, 58, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 remy_atca_048_head[4] = { HEAD(4, 20, 0, 10, 0, 1, 0) };
const u16 remy_atca_048[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 7, 0x74C0, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 7, 0x74C1, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74C2, -28, 162, 0, 128, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x74C3, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74C4, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74C5, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x74C6, 0, 163, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74C7, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 remy_atca_050_head[4] = { HEAD(4, 20, 2, 11, 0, 1, 0) };
const u16 remy_atca_050[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 6, 0x74C0, 0, 165, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 6, 0x74C1, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 548, 0, 0, 0, 6, 0x74C2, -29, 167, 0, 128, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0x000D, 0x0000, 0x0000, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 6, 0x74C3, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x74C4, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x74C5, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x74C6, 0, 168, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74C7, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 remy_atca_052_head[4] = { HEAD(4, 20, 4, 9, 0, 1, 0) };
const u16 remy_atca_052[148] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 8, 0x74C8, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74C9, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74CA, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 8, 0x74CB, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 549, 0, 0, 0, 6, 0x74CC, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x74CD, -30, 174, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74CE, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74CF, 0, 175, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74D0, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x74D1, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74D2, 0, 177, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x74D3, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74D4, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 remy_atca_054_head[4] = { HEAD(4, 20, 1, 7, 0, 1, 0) };
const u16 remy_atca_054[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x74E0, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x74E1, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74E2, -31, 182, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x74E3, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74E4, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x74E5, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x74E6, 0, 183, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74E7, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 remy_atca_056_head[4] = { HEAD(4, 20, 3, 14, 0, 1, 0) };
const u16 remy_atca_056[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x74E0, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 6, 0x74E1, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 0, 551, 0, 0, 0, 6, 0x74E8, -32, 187, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x74E9, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x74EA, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x74EB, 0, 189, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x74EC, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x74ED, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 remy_atca_058_head[4] = { HEAD(4, 20, 5, 11, 0, 1, 0) };
const u16 remy_atca_058[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x74EE, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x74EF, 0, 193, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 5, 0x74F0, 0, 193, 0, 0, 0, 0, 0),
    L4(1, 0, 552, 0, 0, 0, 5, 0x74F1, -33, 194, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74F2, 0, 195, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x74F3, 0, 195, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74F4, 0, 196, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x74F5, 0, 196, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 6, 0x74F5, 0, 197, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x74F6, 0, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x74F7, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728E, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x728F, 0, 31, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 remy_atca_060_head[4] = { HEAD(2, 24, 0, 11, 0, 1, 0) };
const u16 remy_atca_060[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 48, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 remy_atca_062_head[4] = { HEAD(2, 24, 2, 13, 0, 1, 0) };
const u16 remy_atca_062[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 50, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 remy_atca_064_head[4] = { HEAD(2, 24, 4, 13, 0, 1, 0) };
const u16 remy_atca_064[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 52, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 remy_atca_066_head[4] = { HEAD(2, 24, 1, 8, 0, 1, 0) };
const u16 remy_atca_066[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 54, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 remy_atca_068_head[4] = { HEAD(2, 24, 3, 13, 0, 1, 0) };
const u16 remy_atca_068[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 56, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 remy_atca_070_head[4] = { HEAD(2, 24, 5, 14, 0, 1, 0) };
const u16 remy_atca_070[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 4, 58, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 remy_atca_072_head[4] = { HEAD(2, 28, 0, 11, 0, 1, 0) };
const u16 remy_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 remy_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 remy_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 remy_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 remy_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 remy_atca_078_head[4] = { HEAD(2, 28, 1, 8, 0, 1, 0) };
const u16 remy_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 remy_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 remy_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 remy_atca_082_head[4] = { HEAD(2, 28, 5, 14, 0, 1, 0) };
const u16 remy_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 remy_atca_084_head[4] = { HEAD(2, 26, 0, 12, 0, 1, 0) };
const u16 remy_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 remy_atca_086_head[4] = { HEAD(2, 26, 2, 14, 0, 1, 0) };
const u16 remy_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 remy_atca_088_head[4] = { HEAD(2, 26, 4, 14, 0, 1, 0) };
const u16 remy_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 remy_atca_090_head[4] = { HEAD(2, 26, 1, 9, 0, 1, 0) };
const u16 remy_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 remy_atca_092_head[4] = { HEAD(2, 26, 3, 14, 0, 1, 0) };
const u16 remy_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 remy_atca_094_head[4] = { HEAD(2, 26, 5, 15, 0, 1, 0) };
const u16 remy_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 remy_atca_096_head[4] = { HEAD(2, 30, 0, 11, 0, 1, 0) };
const u16 remy_atca_096[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 remy_atca_098_head[4] = { HEAD(2, 30, 2, 13, 0, 1, 0) };
const u16 remy_atca_098[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 remy_atca_100_head[4] = { HEAD(2, 30, 4, 13, 0, 1, 0) };
const u16 remy_atca_100[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 remy_atca_102_head[4] = { HEAD(2, 30, 1, 8, 0, 1, 0) };
const u16 remy_atca_102[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 remy_atca_104_head[4] = { HEAD(2, 30, 3, 13, 0, 1, 0) };
const u16 remy_atca_104[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 remy_atca_106_head[4] = { HEAD(2, 30, 5, 14, 0, 1, 0) };
const u16 remy_atca_106[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 remy_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 remy_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 remy_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 remy_atca_110[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 remy_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 remy_atca_112[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 remy_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 remy_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 remy_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 remy_atca_116[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 remy_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 remy_atca_118[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 remy_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_atca_144[108] = {
    CMD(CM_CAFR, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7433, 0, 395, 0, 0, 0, 32, 75),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7433, -6, 38, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 152, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 268, 0, 0, 0, 0, 0x7500, 0, 396, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7501, 0, 397, 0, 0, 0, 32, 76),
    L4(7, 0, 0, 0, 0, 0, 0, 0x7508, 0, 398, 0, 0, 0, 32, 77),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7509, 0, 399, 0, 0, 0, 32, 78),
    L4(4, 0, 0, 0, 0, 0, 0, 0x750A, 0, 395, 0, 0, 0, 32, 79),
    L4(3, 64, 0, 0, 0, 0, 0, 0x750B, 0, 1, 0, 0, 0, 32, 80),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 remy_atca_145_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_atca_145[52] = {
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7433, 0, 395, 0, 0, 0, 32, 75),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7433, -1, 38, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 4, 144, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 remy_atca_146_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_atca_146[52] = {
    CMD(CM_CAFR, 2, 1, 2), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 2), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7433, 0, 395, 0, 0, 0, 32, 75),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7433, -1, 38, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 4, 144, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of CATCH 2 */
const u16 remy_atca_156_head[4] = { HEAD(4, 0, 4, 10, 0, 1, 0) };
const u16 remy_atca_156[228] = {
    CMD(CM_RVXY, 0, -8192, 0), 0, 0, 0, 0,
    L4(2, 0, 548, 2, 0, 0, 0, 0x7420, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 2, 0, 0, 0, 0x7421, -3, 39, 0, 0, 0, 32, 165),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7422, 0, 39, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7423, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7424, 0, 291, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x746F, 0, 291, 0, 0, 0, 32, 96),
    L4(2, 0, 551, 0, 0, 0, 0, 0x7470, 0, 291, 0, 0, 0, 32, 97),
    L4(2, 0, 269, 0, 0, 0, 0, 0x7471, -4, 40, 0, 128, 0, 32, 98),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7472, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7473, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7474, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7477, 0, 291, 0, 0, 0, 32, 166),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7478, 0, 291, 0, 0, 0, 32, 102),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7426, 0, 291, 0, 0, 0, 32, 235),
    L4(1, 0, 0, 0, 0, 0, 0, 0x7427, 0, 291, 0, 0, 0, 32, 146),
    L4(1, 0, 552, 0, 0, 0, 0, 0x7428, 0, 291, 0, 0, 0, 32, 147),
    L4(1, 0, 270, 0, 0, 0, 0, 0x7429, -5, 41, 0, 64, 0, 32, 148),
    L4(2, 0, 0, 0, 0, 0, 0, 0x758D, 0, 41, 0, 128, 0, 32, 236),
    L4(8, 0, 0, 0, 0, 0, 0, 0x758E, 0, 41, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x758F, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7590, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x742E, 0, 1, 0, 0, 0, 32, 150),
    L4(3, 0, 0, 0, 0, 0, 0, 0x742F, 0, 1, 0, 0, 0, 32, 151),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7430, 0, 1, 0, 0, 0, 32, 152),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7431, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x7432, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of M KICK A */
const u16 remy_atca_157_head[4] = { HEAD(4, 0, 5, 11, 0, 1, 0) };
const u16 remy_atca_157[132] = {
    CMD(CM_EXEC, 30, 155, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x744E, 0, 132, 0, 0, 0, 0, 103),
    L4(4, 0, 270, 1, 0, 0, 0, 0x744F, 0, 133, 0, 0, 0, 32, 104),
    L4(2, 0, 550, 1, 0, 0, 0, 0x7450, 0, 134, 0, 0, 0, 32, 105),
    L4(1, 0, 0, 1, 0, 0, 0, 0x7451, -78, 135, 0, 128, 0, 32, 106),
    L4(2, 0, 0, 1, 0, 0, 0, 0x7452, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x7452, 0, 137, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7453, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7454, 0, 138, 0, 0, 0, 32, 107),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7455, 0, 139, 0, 0, 0, 32, 108),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7456, 0, 140, 0, 0, 0, 32, 109),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7457, 0, 140, 0, 0, 0, 32, 110),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7458, 0, 141, 0, 0, 0, 32, 111),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7459, 0, 141, 0, 0, 0, 32, 112),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7201, 0, 141, 0, 0, 0, 32, 113),
    CMD(CM_JPSS, 7, 16, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX remy_olc_ix_table[31] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 2, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 4, 0, 0, 0 } },
    { { 6, 0, 0, 0 } },
    { { 7, 0, 0, 0 } },
    { { 8, 0, 0, 0 } },
    { { 9, 0, 0, 0 } },
    { { 10, 0, 0, 0 } },
    { { 11, 0, 0, 0 } },
    { { 12, 0, 0, 0 } },
    { { 13, 0, 0, 0 } },
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
    { { 34, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
    { { 14, 0, 0, 0 } },
};

const OVERLAP_PARTS remy_overlap_char_tbl[42] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 1, 29639 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 2, 29640 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 3, 29641 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 4, 29642 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 5, 29643 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 6, 30230 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 7, 29644 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 8, 29645 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 9, 30231 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 10, 29646 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 11, 29647 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 12, 29786 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 13, 29787 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 14, 29788 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 15, 30232 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 16, 29789 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 17, 29790 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 18, 29791 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 19, 30224 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 20, 30225 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 21, 30226 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 22, 30227 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 23, 30228 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 24, 30229 },
    { 0, 0, 0, 11, 2, 0, 1, 0, 0, 0, 30128 },
    { 0, 0, 0, 11, 2, 0, 255, 0, 0, 26, 30129 },
    { 0, 0, 0, 11, 2, 0, 255, 0, 0, 27, 30130 },
    { 0, 0, 0, 11, 2, 0, 255, 0, 0, 28, 30131 },
    { 0, 0, 0, 11, 2, 0, 3, 0, 0, 0, 30132 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30133 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30134 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30135 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 33, 0 },
    { 0, 0, 0, 11, 2, 0, 6, 0, 0, 0, 30129 },
    { 0, 0, 0, 11, 2, 0, 3, 0, 0, 0, 30130 },
    { 0, 0, 0, 11, 2, 0, 3, 0, 0, 0, 30131 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30132 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30133 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30134 },
    { 0, 0, 0, 11, 2, 0, 2, 0, 0, 0, 30135 },
    { 0, 0, 0, 11, 2, 0, 250, 0, 0, 41, 0 },
};

const CatchTable remy_rival_catch_tbl[336] = {
    { -47, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -55, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -69, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -47, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -62, 0, 2, 1, 1 },
    { -69, 0, 1, 1, 1 },
    { -67, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -43, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -71, 0, 1, 1, 2 },
    { -47, 0, 1, 1, 2 },
    { -41, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -61, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -71, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -57, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 2 },
    { -62, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -81, 0, 1, 1, 3 },
    { -67, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -77, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -71, 0, 1, 1, 3 },
    { -81, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -65, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -69, 0, 1, 1, 3 },
    { -74, 0, 1, 1, 3 },
    { -69, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -63, 0, 1, 1, 4 },
    { -65, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -69, 6, 1, 1, 4 },
    { -73, -2, 1, 1, 4 },
    { -84, 0, 1, 1, 4 },
    { -84, 0, 1, 1, 4 },
    { -68, 6, 1, 1, 4 },
    { -82, 5, 1, 1, 4 },
    { -67, 0, 1, 1, 4 },
    { -69, 6, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -63, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -65, 1, 1, 1, 4 },
    { -84, 4, 1, 1, 4 },
    { -79, 0, 1, 1, 4 },
    { -74, 0, 1, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -57, 0, 1, 1, 5 },
    { -75, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -62, 0, 1, 1, 5 },
    { -70, 0, 1, 1, 5 },
    { -74, 2, 1, 1, 5 },
    { -61, 1, 1, 1, 5 },
    { -63, 3, 1, 1, 5 },
    { -69, 17, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -57, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -66, 7, 1, 1, 5 },
    { -71, 8, 1, 1, 4 },
    { -70, 0, 1, 1, 5 },
    { -72, 2, 1, 1, 5 },
    { -56, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -57, 0, 1, 1, 5 },
    { -75, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -62, 0, 1, 1, 5 },
    { -70, 0, 1, 1, 5 },
    { -74, 2, 1, 1, 5 },
    { -61, 1, 1, 1, 5 },
    { -63, 3, 1, 1, 5 },
    { -69, 17, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -57, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -66, 7, 1, 1, 5 },
    { -71, 8, 1, 1, 4 },
    { -70, 0, 1, 1, 5 },
    { -72, 2, 1, 1, 5 },
    { -56, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -57, 0, 1, 1, 5 },
    { -75, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -62, 0, 1, 1, 5 },
    { -70, 0, 1, 1, 5 },
    { -74, 2, 1, 1, 5 },
    { -61, 1, 1, 1, 5 },
    { -63, 3, 1, 1, 5 },
    { -69, 17, 1, 1, 5 },
    { -56, 5, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -57, 0, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -59, 4, 1, 1, 5 },
    { -66, 7, 1, 1, 5 },
    { -71, 8, 1, 1, 4 },
    { -70, 0, 1, 1, 5 },
    { -72, 2, 1, 1, 5 },
    { -56, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -50, 0, 1, 1, 6 },
    { -65, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -52, 0, 1, 1, 6 },
    { -60, 0, 1, 1, 6 },
    { -64, 0, 1, 1, 6 },
    { -60, 0, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -57, 0, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -50, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -78, 0, 1, 1, 5 },
    { -64, 0, 1, 1, 6 },
    { -53, 0, 1, 1, 6 },
    { -46, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -50, 0, 1, 1, 7 },
    { -57, 0, 1, 1, 7 },
    { -52, 0, 1, 1, 7 },
    { -56, 0, 1, 1, 7 },
    { -45, 0, 1, 1, 7 },
    { -53, 0, 1, 1, 7 },
    { -57, 0, 1, 1, 7 },
    { -53, 0, 1, 1, 7 },
    { -54, 0, 1, 1, 7 },
    { -65, 0, 1, 1, 7 },
    { -56, 0, 1, 1, 7 },
    { -52, 0, 1, 1, 7 },
    { -52, 0, 1, 1, 7 },
    { -50, 0, 1, 1, 7 },
    { -52, 0, 1, 1, 7 },
    { -52, 0, 1, 1, 7 },
    { -49, 0, 1, 1, 7 },
    { -59, 0, 1, 1, 6 },
    { -57, 0, 1, 1, 6 },
    { -50, 0, 1, 1, 7 },
    { -38, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -37, 0, 2, 1, 8 },
    { -44, 0, 2, 1, 8 },
    { -42, 0, 2, 1, 8 },
    { -43, 0, 2, 1, 8 },
    { -32, 0, 2, 1, 8 },
    { -40, 0, 2, 1, 8 },
    { -50, 0, 2, 1, 8 },
    { -44, 0, 2, 1, 8 },
    { -41, 0, 2, 1, 8 },
    { -52, 0, 2, 1, 8 },
    { -43, 0, 2, 1, 8 },
    { -42, 0, 2, 1, 8 },
    { -42, 0, 2, 1, 8 },
    { -37, 0, 2, 1, 8 },
    { -42, 0, 2, 1, 8 },
    { -42, 0, 2, 1, 8 },
    { -36, 0, 2, 1, 8 },
    { -46, 0, 2, 1, 6 },
    { -43, 0, 2, 1, 7 },
    { -37, 0, 2, 1, 8 },
    { -30, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -37, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -46, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -43, 0, 2, 1, 9 },
    { -43, 0, 2, 1, 9 },
    { -31, 0, 2, 1, 9 },
    { -48, 0, 2, 1, 9 },
    { -54, 0, 2, 1, 9 },
    { -46, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -37, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -40, 0, 2, 1, 9 },
    { -44, 0, 2, 1, 7 },
    { -36, 0, 2, 1, 8 },
    { -28, 0, 2, 1, 9 },
    { -26, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -74, 0, 2, 1, 10 },
    { -43, 0, 2, 1, 10 },
    { -50, 12, 2, 1, 10 },
    { -32, 17, 2, 1, 10 },
    { -40, 4, 2, 1, 10 },
    { -67, 25, 2, 1, 10 },
    { -42, 2, 2, 1, 10 },
    { -43, 5, 2, 1, 10 },
    { -50, 26, 2, 1, 10 },
    { -64, 8, 2, 1, 10 },
    { -32, 17, 2, 1, 10 },
    { -50, 12, 2, 1, 10 },
    { -50, 12, 2, 1, 10 },
    { -74, 0, 2, 1, 10 },
    { -50, 12, 2, 1, 10 },
    { -50, 12, 2, 1, 10 },
    { -47, 0, 2, 1, 10 },
    { -50, 22, 2, 1, 8 },
    { -79, 16, 2, 1, 9 },
    { -47, 8, 2, 1, 10 },
    { -54, 8, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -11, 0, 2, 1, 6 },
    { -28, 0, 2, 1, 1 },
    { -3, 0, 2, 1, 4 },
    { -25, 14, 2, 1, 2 },
    { -17, 0, 2, 1, 6 },
    { -18, 0, 2, 1, 4 },
    { -24, 0, 2, 1, 4 },
    { -14, 8, 2, 1, 4 },
    { -10, 4, 2, 1, 5 },
    { 6, 9, 2, 1, 3 },
    { -25, 14, 2, 1, 2 },
    { -3, 0, 2, 1, 4 },
    { -3, 0, 2, 1, 4 },
    { -11, 0, 2, 1, 6 },
    { -3, 0, 2, 1, 4 },
    { -3, 0, 2, 1, 4 },
    { -12, 2, 2, 1, 4 },
    { -14, 8, 2, 1, 4 },
    { -10, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 2 },
    { -6, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 32, 0, 2, 1, 4 },
    { 21, 0, 2, 1, 5 },
    { 26, 0, 2, 1, 5 },
    { 14, 14, 2, 1, 3 },
    { 21, 0, 2, 1, 8 },
    { 15, 0, 2, 1, 4 },
    { 31, 0, 2, 1, 5 },
    { 11, 10, 2, 1, 6 },
    { 22, 5, 2, 1, 3 },
    { 20, 4, 2, 1, 4 },
    { 14, 14, 2, 1, 3 },
    { 26, 0, 2, 1, 5 },
    { 26, 0, 2, 1, 5 },
    { 32, 0, 2, 1, 4 },
    { 26, 0, 2, 1, 5 },
    { 26, 0, 2, 1, 5 },
    { 22, 6, 2, 1, 6 },
    { 13, 8, 2, 1, 4 },
    { 19, 0, 2, 1, 5 },
    { 24, 0, 2, 1, 1 },
    { 24, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 52 entries */
const u16* const remy_exca[53] = {
    remy_exca_000,  /* 0 follow-up of AIR NORMAL */
    remy_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    remy_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    remy_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    remy_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    remy_exca_005,  /* 5 follow-up of TATAKI S, TATAKI M +15 */
    remy_exca_006,  /* 6 follow-up of NOKEZORI, UPPER +22 */
    remy_exca_007,  /* 7 follow-up of KUNOJI, IBUKI +2 */
    remy_exca_008,  /* 8 follow-up of TATAKI V. S, TATAKI V. M +9 */
    remy_exca_009,  /* 9 follow-up of KIRIMOMI, TOMOE RYU +1 */
    remy_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    remy_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    remy_exca_012,  /* 12 follow-up of APPEAR JUNBI 4 */
    remy_exca_013,  /* 13 no name */
    remy_exca_014,  /* 14 follow-up of HUMI ASIB */
    remy_exca_015,  /* 15 follow-up of DASH HUMIKOMI, DASH TOBINOKI +16 */
    remy_exca_016,  /* 16 follow-up of CATCH 1, S PUNCH A +15 */
    remy_exca_017,  /* 17 follow-up of KAGAMI S, KAGAMI M +4 */
    remy_exca_018,  /* 18 follow-up of KAGAMI K A */
    remy_exca_019,  /* 19 no name */
    remy_exca_020,  /* 20 follow-up of APPEAR 2 */
    remy_exca_021,  /* 21 follow-up of APPEAR 2 */
    remy_exca_022,  /* 22 follow-up of SP APPEAR 2 */
    remy_exca_023,  /* 23 follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    remy_exca_024,  /* 24 follow-up of SP APPEAR 1 */
    remy_exca_025,  /* 25 follow-up of SP APPEAR 1 */
    remy_exca_026,  /* 26 follow-up of APPEAR 3 */
    remy_exca_027,  /* 27 follow-up of APPEAR 3 */
    remy_exca_028,  /* 28 follow-up of SP APPEAR 5 */
    remy_exca_029,  /* 29 follow-up of SP APPEAR 5 */
    remy_exca_030,  /* 30 no name */
    remy_exca_031,  /* 31 follow-up of SP APPEAR 6 */
    remy_exca_032,  /* 32 follow-up of SP APPEAR 6 */
    remy_exca_033,  /* 33 follow-up of ASIB TUNNOMERI */
    remy_exca_034,  /* 34 follow-up of SP APPEAR 7 */
    remy_exca_035,  /* 35 follow-up of SP APPEAR 7 */
    remy_exca_036,  /* 36 follow-up of GILL IMPACT C */
    remy_exca_037,  /* 37 no name */
    remy_exca_037,  /* 38 no name */
    remy_exca_039,  /* 39 follow-up of GILL IMPACT C */
    remy_exca_040,  /* 40 follow-up of SP APPEAR 8 */
    remy_exca_041,  /* 41 follow-up of SP APPEAR 8 */
    remy_exca_042,  /* 42 follow-up of APPEAR 4 */
    remy_exca_043,  /* 43 follow-up of APPEAR 4 */
    remy_exca_044,  /* 44 follow-up of KAMAE */
    remy_exca_045,  /* 45 follow-up of KAMAE */
    remy_exca_046,  /* 46 follow-up of KAMAE */
    remy_exca_047,  /* 47 follow-up of KAMAE */
    remy_exca_048,  /* 48 follow-up of KAMAE */
    remy_exca_049,  /* 49 follow-up of KAMAE */
    remy_exca_050,  /* 50 follow-up of KAMAE */
    remy_exca_051,  /* 51 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 remy_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_exca_000[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x735B, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73FC, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73FD, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73FE, 0, 34, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x73FF, 0, 34, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7299, 0, 34, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729A, 0, 34, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729B, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x729C, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x729D, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x729E, 0, 34, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x729F, 0, 34, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3 */
const u16 remy_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_001[100] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x725D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 remy_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_003[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A4, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A1, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73A0, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 remy_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_004[100] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x725D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, TATAKI M +15 */
const u16 remy_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_005[132] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x7329, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x732A, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x732B, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x732F, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, UPPER +22 */
const u16 remy_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_006[140] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x7328, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x7329, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x732A, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x732B, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x732F, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, IBUKI +2 */
const u16 remy_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_007[28] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x735C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x735D, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 6, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI V. S, TATAKI V. M +9 */
const u16 remy_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_008[76] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, TOMOE RYU +1 */
const u16 remy_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_009[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x73A0, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x73A1, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73A2, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73A3, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73A4, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x73A5, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3 */
const u16 remy_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_010[60] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4 */
const u16 remy_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_012[60] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 remy_exca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_013[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of HUMI ASIB */
const u16 remy_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_014[116] = {
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x732C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x732F, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of DASH HUMIKOMI, DASH TOBINOKI +16 */
const u16 remy_exca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_015[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of CATCH 1, S PUNCH A +15 */
const u16 remy_exca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_016[68] = {
    L4(3, 64, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of KAGAMI S, KAGAMI M +4 */
const u16 remy_exca_017_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_017[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7254, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7255, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 follow-up of KAGAMI K A */
const u16 remy_exca_018_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_018[68] = {
    L4(3, 64, 0, 0, 0, 0, 0, 0x7254, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7255, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7256, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7257, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 remy_exca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_019[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 follow-up of APPEAR 2 */
const u16 remy_exca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_020[116] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x753E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7540, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7541, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7542, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of APPEAR 2 */
const u16 remy_exca_021_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_021[100] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of SP APPEAR 2 */
const u16 remy_exca_022_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_022[52] = {
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 274, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 32, 247),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
const u16 remy_exca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_023[68] = {
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 274, 0, 0, 0, 0, 0x74A8, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x74A9, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74AA, 0, 212, 0, 0, 0, 32, 129),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74AB, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7419, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x741A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 18, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of SP APPEAR 1 */
const u16 remy_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_024[92] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x72D4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x72D5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x72D6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of SP APPEAR 1 */
const u16 remy_exca_025_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_025[68] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x72D4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 3 */
const u16 remy_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_026[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x725D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR 3 */
const u16 remy_exca_027_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_027[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of SP APPEAR 5 */
const u16 remy_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_028[116] = {
    L4(4, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x753E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7540, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7541, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7542, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of SP APPEAR 5 */
const u16 remy_exca_029_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_029[100] = {
    L4(4, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7258, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7259, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x725A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 no name */
const u16 remy_exca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_exca_030[12] = {
    L4(250, 0, 0, 0, 1, 0, 0, 0x0601, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of SP APPEAR 6 */
const u16 remy_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_031[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x753E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 20, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of SP APPEAR 6 */
const u16 remy_exca_032_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_032[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 21, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of ASIB TUNNOMERI */
const u16 remy_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_033[124] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x732A, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x732B, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732C, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732D, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x732E, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x732F, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP APPEAR 7 */
const u16 remy_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_034[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x753E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 20, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 7 */
const u16 remy_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_035[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 21, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of GILL IMPACT C */
const u16 remy_exca_036_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_036[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A4, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A1, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73A0, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 no name, 38 no name */
const u16 remy_exca_037_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_exca_037[12] = {
    L4(250, 0, 0, 0, 1, 0, 0, 0x0601, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of GILL IMPACT C */
const u16 remy_exca_039_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 remy_exca_039[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A4, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x73A1, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x73A0, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x7330, 0, 35, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x7331, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7332, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7333, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x7334, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x7335, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7336, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7337, 0, 35, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP APPEAR 8 */
const u16 remy_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_040[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x753E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 20, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of SP APPEAR 8 */
const u16 remy_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_041[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x753B, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 21, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of APPEAR 4 */
const u16 remy_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_042[92] = {
    L4(3, 3, 274, 0, 0, 0, 0, 0x7260, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x725D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x725E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of APPEAR 4 */
const u16 remy_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 remy_exca_043[52] = {
    L4(2, 3, 274, 0, 0, 0, 0, 0x7260, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7261, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x7262, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x7263, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7264, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7265, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of KAMAE */
const u16 remy_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_044[284] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 382, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A6, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A7, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A8, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A9, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AA, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AB, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AC, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AD, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AE, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73AF, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74D5, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74D6, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74D7, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74D8, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74D9, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74DA, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74DB, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74DC, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74DD, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x74DE, 0, 382, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of KAMAE */
const u16 remy_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_045[116] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x7209, 0, 3, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x720A, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x720B, 0, 3, 0, 0, 0, 0, 0),
    L4(15, 0, 0, 0, 0, 0, 0, 0x720C, 0, 4, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x720D, 0, 4, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x720E, 0, 4, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x720F, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of KAMAE */
const u16 remy_exca_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_046[244] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x7479, 0, 382, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x747A, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x747B, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x747C, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x747D, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x747E, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x747F, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E0, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E1, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E2, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E3, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E4, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E5, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E6, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x72E7, 0, 382, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x72E8, 0, 382, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x72E9, 0, 382, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x72EA, 0, 382, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x72EB, 0, 382, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x72EC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x72ED, 0, 382, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x72EE, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x72EF, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of KAMAE */
const u16 remy_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_047[220] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 382, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A6, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A7, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7630, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7631, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7632, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7633, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7634, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7635, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7636, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7637, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7638, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7634, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7639, 0, 382, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of KAMAE */
const u16 remy_exca_048_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_048[172] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 382, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A6, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x73A7, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7630, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7631, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7632, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x7633, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of KAMAE */
const u16 remy_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_049[276] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 382, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763A, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763B, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763C, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763D, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763E, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763F, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7640, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7641, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7642, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7643, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7644, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7645, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7643, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7642, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7641, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7646, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7640, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7647, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7648, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7649, 0, 382, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of KAMAE */
const u16 remy_exca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_exca_050[172] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 3, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x74F9, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FA, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FB, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FC, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FD, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74FE, 0, 382, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x763A, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763B, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763C, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763D, 0, 382, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x763E, 0, 382, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(50, 0, 0, 0, 0, 0, 0, 0x74FF, 0, 382, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x74F8, 0, 383, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 remy_exca_051_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 remy_exca_051[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x735B, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73FC, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x73FD, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x73FE, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x73FF, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7299, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729A, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x729B, 0, 30, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x729C, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x729D, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x729E, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x729F, 0, 28, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 64 entries */
const u16* const remy_saca[65] = {
    remy_saca_000,  /* 0 UP P GUARD P S */
    remy_saca_001,  /* 1 UP P GUARD P M */
    remy_saca_002,  /* 2 UP P GUARD P L */
    remy_saca_002,  /* 3 UP P GUARD K S */
    remy_saca_002,  /* 4 UP P GUARD K M */
    remy_saca_002,  /* 5 UP P GUARD K L */
    remy_saca_000,  /* 6 D P GUARD P S */
    remy_saca_001,  /* 7 D P GUARD P M */
    remy_saca_002,  /* 8 D P GUARD P L */
    remy_saca_002,  /* 9 D P GUARD K S */
    remy_saca_002,  /* 10 D P GUARD K M */
    remy_saca_002,  /* 11 D P GUARD K L */
    remy_saca_002,  /* 12 FUSHIN P S */
    remy_saca_002,  /* 13 FUSHIN P M */
    remy_saca_002,  /* 14 FUSHIN P L */
    remy_saca_002,  /* 15 FUSHIN K S */
    remy_saca_002,  /* 16 FUSHIN K M */
    remy_saca_002,  /* 17 FUSHIN K L */
    remy_saca_002,  /* 18 OKIAGARI P S */
    remy_saca_002,  /* 19 OKIAGARI P M */
    remy_saca_002,  /* 20 OKIAGARI P L */
    remy_saca_002,  /* 21 OKIAGARI K S */
    remy_saca_002,  /* 22 OKIAGARI K M */
    remy_saca_002,  /* 23 OKIAGARI K L */
    remy_saca_024,  /* 24 ATTACK 1 S: SA I 23623+P (plain script) */
    remy_saca_024,  /* 25 ATTACK 1 M: SA I 23623+P (plain script) */
    remy_saca_024,  /* 26 ATTACK 1 L: SA I 23623+P (plain script) */
    remy_saca_024,  /* 27 ATTACK 1 SP: SA I 23623+P (plain script) */
    remy_saca_028,  /* 28 ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1) */
    remy_saca_029,  /* 29 ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    remy_saca_030,  /* 30 ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    remy_saca_031,  /* 31 ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) */
    remy_saca_032,  /* 32 ATTACK 3 S: not started by a command */
    remy_saca_032,  /* 33 ATTACK 3 M: not started by a command */
    remy_saca_032,  /* 34 ATTACK 3 L: not started by a command */
    remy_saca_032,  /* 35 ATTACK 3 SP: not started by a command */
    remy_saca_036,  /* 36 ATTACK 4 S: not started by a command */
    remy_saca_037,  /* 37 ATTACK 4 M: [4]6+P light (plain script) */
    remy_saca_038,  /* 38 ATTACK 4 L: [4]6+P medium (plain script) */
    remy_saca_039,  /* 39 ATTACK 4 SP: [4]6+P heavy (plain script) */
    remy_saca_040,  /* 40 ATTACK 5 S: EX [4]6+PP (plain script) */
    remy_saca_041,  /* 41 ATTACK 5 M: [4]6+K light (plain script) */
    remy_saca_042,  /* 42 ATTACK 5 L: [4]6+K medium (plain script) */
    remy_saca_043,  /* 43 ATTACK 5 SP: [4]6+K heavy (plain script) */
    remy_saca_044,  /* 44 ATTACK 6 S: EX [4]6+KK (plain script) */
    remy_saca_045,  /* 45 ATTACK 6 M: not started by a command */
    remy_saca_046,  /* 46 ATTACK 6 L: 214+K light (routine Att_PL20_AT2) */
    remy_saca_047,  /* 47 ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2) */
    remy_saca_048,  /* 48 ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) */
    remy_saca_049,  /* 49 ATTACK 7 M: EX 214+KK (routine Att_PL20_AT2) */
    remy_saca_050,  /* 50 ATTACK 7 L: SA III 23623+K (plain script) */
    remy_saca_050,  /* 51 ATTACK 7 SP: SA III 23623+K (plain script) */
    remy_saca_050,  /* 52 ATTACK 8 S: SA III 23623+K (plain script) */
    remy_saca_050,  /* 53 ATTACK 8 M: SA III 23623+K (plain script) */
    remy_saca_054,  /* 54 ATTACK 8 L: after SA III 23623+K (plain script) */
    remy_saca_055,  /* 55 ATTACK 8 SP: started by routine Att_PL20_AT3 */
    remy_saca_056,  /* 56 ATTACK 9 S: after SA III 23623+K (plain script) */
    remy_saca_057,  /* 57 ATTACK 9 M: after SA III 23623+K (plain script) */
    remy_saca_058,  /* 58 ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    remy_saca_058,  /* 59 ATTACK 9 SP: SA II 23623+K (routine Att_PL20_AT1) */
    remy_saca_058,  /* 60 ATTACK 10 S: SA II 23623+K (routine Att_PL20_AT1) */
    remy_saca_058,  /* 61 ATTACK 10 M: SA II 23623+K (routine Att_PL20_AT1) */
    remy_saca_062,  /* 62 ATTACK 10 L: not started by a command */
    remy_saca_063,  /* 63 ATTACK 10 SP: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 remy_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7141, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7142, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7143, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7144, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7145, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7146, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7147, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7148, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7149, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x714A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x714B, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, 0, 4352), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 remy_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 remy_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x714B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x714A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x714A, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7149, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7148, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7147, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7146, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7145, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7144, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7143, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7142, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7141, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 remy_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 0, 0) };
const u16 remy_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7201),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: SA I 23623+P (plain script), 25 ATTACK 1 M: SA I 23623+P (plain script), 26 ATTACK 1 L: SA I 23623+P (plain script), 27 ATTACK 1 SP: SA I 23623+P (plain script) */
const u16 remy_saca_024_head[4] = { HEAD(4, 0, 32, 10, 0, 7, 102) };
const u16 remy_saca_024[428] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 306, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 560, 0, 0, 0, 0, 0x7550, 0, 291, 0, 0, 0, 13, 53),
    L4(43, 0, 0, 0, 0, 1, 0, 0x7551, 0, 291, 0, 0, 0, 32, 154),
    L4(2, 0, 575, 0, 0, 2, 0, 0x7552, 0, 291, 0, 0, 0, 32, 155),
    L4(2, 0, 549, 0, 0, 3, 0, 0x7553, 0, 291, 0, 0, 0, 32, 156),
    CMD(CM_ASXY, 314, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 4, 0, 0x7554, 0, 233, 0, 0, 0, 2, 160),
    L4(1, 0, 575, 0, 0, 29, 0, 0x7555, 0, 234, 0, 0, 0, 32, 158),
    L4(1, 0, 0, 0, 0, 6, 0, 0x755D, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 2, 161, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 7, 0, 0x755E, 0, 238, 0, 0, 0, 32, 159),
    L4(2, 0, 0, 0, 0, 8, 0, 0x755F, 0, 239, 0, 0, 0, 32, 167),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7560, 0, 240, 0, 0, 0, 32, 168),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7561, 0, 1, 0, 0, 0, 32, 162),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7562, 0, 241, 0, 0, 0, 32, 184),
    L4(3, 0, 0, 0, 0, 9, 0, 0x7563, 0, 242, 0, 0, 0, 32, 169),
    L4(2, 0, 575, 0, 0, 10, 0, 0x7564, 0, 243, 0, 0, 0, 32, 170),
    L4(1, 0, 549, 0, 0, 11, 0, 0x7565, 0, 244, 0, 0, 0, 32, 171),
    CMD(CM_ASXY, 344, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 12, 0, 0x7566, 0, 245, 0, 0, 0, 2, 162),
    L4(2, 0, 0, 0, 0, 30, 0, 0x7567, 0, 246, 0, 0, 0, 32, 173),
    L4(2, 0, 575, 0, 0, 14, 0, 0x7568, 0, 247, 0, 0, 0, 32, 174),
    CMD(CM_EXEC, 2, 163, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 15, 0, 0x756D, 0, 252, 0, 0, 0, 32, 175),
    L4(2, 0, 0, 0, 0, 0, 0, 0x756E, 0, 253, 0, 0, 0, 32, 181),
    L4(2, 0, 0, 0, 0, 0, 0, 0x756F, 0, 254, 0, 0, 0, 32, 182),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7570, 0, 255, 0, 0, 0, 32, 185),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7571, 0, 256, 0, 0, 0, 32, 186),
    L4(2, 0, 0, 0, 0, 17, 0, 0x7572, 0, 257, 0, 0, 0, 32, 187),
    L4(2, 0, 575, 0, 0, 18, 0, 0x7573, 0, 258, 0, 0, 0, 32, 188),
    L4(1, 0, 575, 0, 0, 19, 0, 0x7574, 0, 259, 0, 0, 0, 32, 189),
    CMD(CM_EXEC, 2, 164, 0), 0, 0, 0, 0,
    L4(1, 0, 551, 0, 0, 20, 0, 0x7575, 0, 260, 0, 0, 0, 32, 190),
    CMD(CM_ASXY, 382, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 575, 0, 0, 21, 0, 0x7576, 0, 261, 0, 0, 0, 2, 165),
    CMD(CM_ASXY, 384, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 22, 0, 0x7577, 0, 262, 0, 0, 0, 2, 166),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7578, 0, 263, 0, 0, 0, 32, 193),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7579, 0, 264, 0, 0, 0, 32, 194),
    L4(3, 0, 0, 0, 0, 0, 0, 0x757A, 0, 265, 0, 0, 0, 32, 194),
    L4(3, 0, 0, 0, 0, 0, 0, 0x757B, 0, 266, 0, 0, 0, 32, 195),
    L4(3, 0, 0, 0, 0, 0, 0, 0x757C, 0, 1, 0, 0, 0, 32, 196),
    L4(3, 0, 0, 0, 0, 0, 0, 0x757D, 0, 1, 0, 0, 0, 32, 197),
    L4(3, 0, 0, 0, 0, 0, 0, 0x757E, 0, 1, 0, 0, 0, 32, 198),
    L4(3, 64, 0, 0, 0, 0, 0, 0x757F, 0, 1, 0, 0, 0, 32, 199),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1) */
const u16 remy_saca_028_head[4] = { HEAD(4, 0, 9, 14, 0, 1, 101) };
const u16 remy_saca_028[204] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 548, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 30, 151),
    L4(1, 0, 0, 0, 0, 23, 0, 0x7531, -34, 275, 0, 143, 0, 32, 145),
    L4(2, 20, 0, 0, 0, 24, 0, 0x7532, 35, 276, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(2, 30, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 28, 0, 0x7532, 0, 276, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 28, 0, 0x7532, 0, 276, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 28, 0, 0x7532, 0, 276, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 28, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(2, 30, 0, 0, 0, 28, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
const u16 remy_saca_029_head[4] = { HEAD(4, 0, 11, 14, 0, 1, 101) };
const u16 remy_saca_029[188] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 549, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 30, 151),
    L4(1, 20, 0, 0, 0, 0, 0, 0x7531, 0, 283, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 23, 0, 0x7531, -37, 283, 0, 144, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 24, 0, 0x7532, 0, 284, 0, 144, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 28, 0, 0x7532, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 28, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 28, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(3, 30, 0, 0, 0, 28, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 28, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
const u16 remy_saca_030_head[4] = { HEAD(4, 0, 13, 15, 0, 1, 101) };
const u16 remy_saca_030[236] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x725B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 551, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x7530, 0, 285, 0, 0, 0, 30, 151),
    L4(2, 20, 0, 0, 0, 0, 0, 0x7531, 0, 286, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 23, 0, 0x7531, -40, 286, 0, 147, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 24, 0, 0x7532, 0, 287, 0, 147, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 28, 0, 0x7532, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 28, 0, 0x7533, 0, 277, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 28, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(3, 30, 0, 0, 0, 28, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 28, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 28, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) */
const u16 remy_saca_031_head[4] = { HEAD(4, 0, 15, 14, 0, 2, 101) };
const u16 remy_saca_031[156] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x725B, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 552, 0, 0, 0, 0, 0x7530, 0, 291, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x7530, 0, 291, 0, 0, 0, 30, 151),
    L4(1, 0, 0, 0, 0, 23, 0, 0x7531, -41, 289, 0, 82, 64, 0, 0),
    L4(4, 20, 0, 0, 0, 24, 0, 0x7532, -43, 290, 0, 64, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 64, 0, 0),
    L4(2, 30, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 24, 0, 0x7532, -42, 290, 0, 64, 0, 0, 0),
    CMD(CM_END, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: not started by a command, 33 ATTACK 3 M: not started by a command, 34 ATTACK 3 L: not started by a command, 35 ATTACK 3 SP: not started by a command */
const u16 remy_saca_032_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 33) };
const u16 remy_saca_032[108] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x7260, 0, 267, 0, 0, 0, 0, 0),
    L4(8, 20, 548, 0, 0, 0, 0, 0x74E0, 0, 268, 0, 0, 0, 22, 20),
    L4(4, 0, 268, 0, 0, 0, 0, 0x74E1, 0, 269, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x74E2, -77, 270, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x74E3, 0, 270, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74E4, 0, 270, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x74E5, 0, 270, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x74E6, 0, 271, 0, 0, 0, 21, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x74E7, 0, 272, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: not started by a command */
const u16 remy_saca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 remy_saca_036[172] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x766C, 0, 1, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x766D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x766E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x766F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7670, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7671, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7672, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 2048, 0, 0, 0, 0, 0x7673, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 40, 0, 0, 0, 0, 0, 0x7674, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7675, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7676, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7677, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7678, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x7679, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x767A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x767B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x767C, 0, 1, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x767D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x767E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x767F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: [4]6+P light (plain script) */
const u16 remy_saca_037_head[4] = { HEAD(4, 0, 8, 10, 0, 1, 0) };
const u16 remy_saca_037[188] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7550, 0, 229, 0, 0, 0, 32, 153),
    L4(3, 0, 0, 0, 0, 1, 0, 0x7551, 0, 230, 0, 0, 0, 32, 154),
    L4(2, 0, 575, 0, 0, 2, 0, 0x7552, 0, 231, 0, 0, 0, 32, 155),
    CMD(CM_ASXY, 312, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 3, 0, 0x7553, 0, 232, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 314, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 4, 0, 0x7554, 0, 233, 0, 0, 64, 2, 198),
    CMD(CM_ASXY, 316, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7555, 0, 234, 0, 0, 64, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x755D, 0, 235, 0, 0, 64, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7556, 0, 236, 0, 0, 64, 32, 159),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7557, 0, 237, 0, 0, 64, 32, 160),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7558, 0, 237, 0, 0, 64, 32, 161),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7559, 0, 1, 0, 0, 64, 32, 162),
    L4(2, 0, 0, 0, 0, 0, 0, 0x755A, 0, 1, 0, 0, 0, 32, 163),
    L4(2, 0, 0, 0, 0, 0, 0, 0x755B, 0, 1, 0, 0, 0, 32, 164),
    L4(3, 64, 0, 0, 0, 0, 0, 0x755C, 0, 1, 0, 0, 0, 32, 164),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: [4]6+P medium (plain script) */
const u16 remy_saca_038_head[4] = { HEAD(4, 0, 10, 10, 0, 1, 0) };
const u16 remy_saca_038[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7550, 0, 229, 0, 0, 0, 32, 153),
    L4(4, 0, 0, 0, 0, 1, 0, 0x7551, 0, 230, 0, 0, 0, 32, 154),
    L4(2, 0, 575, 0, 0, 2, 0, 0x7552, 0, 231, 0, 0, 0, 32, 155),
    CMD(CM_ASXY, 312, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 3, 0, 0x7553, 0, 232, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 314, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 4, 0, 0x7554, 0, 233, 0, 0, 64, 2, 199),
    CMD(CM_JPSS, 5, 37, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: [4]6+P heavy (plain script) */
const u16 remy_saca_039_head[4] = { HEAD(4, 0, 12, 10, 0, 1, 0) };
const u16 remy_saca_039[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7550, 0, 229, 0, 0, 0, 32, 153),
    L4(5, 0, 0, 0, 0, 1, 0, 0x7551, 0, 230, 0, 0, 0, 32, 154),
    L4(2, 0, 575, 0, 0, 2, 0, 0x7552, 0, 231, 0, 0, 0, 32, 155),
    CMD(CM_ASXY, 312, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 3, 0, 0x7553, 0, 232, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 314, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 4, 0, 0x7554, 0, 233, 0, 0, 64, 2, 200),
    CMD(CM_JPSS, 5, 37, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: EX [4]6+PP (plain script) */
const u16 remy_saca_040_head[4] = { HEAD(4, 0, 14, 10, 0, 2, 0) };
const u16 remy_saca_040[132] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7550, 0, 229, 0, 0, 0, 32, 153),
    L4(3, 0, 0, 0, 0, 1, 0, 0x7551, 0, 230, 0, 0, 0, 32, 154),
    L4(2, 0, 575, 0, 0, 2, 0, 0x7552, 0, 231, 0, 0, 0, 32, 155),
    CMD(CM_ASXY, 312, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 3, 0, 0x7553, 0, 232, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 314, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 575, 0, 0, 4, 0, 0x7554, 0, 233, 0, 0, 64, 2, 201),
    CMD(CM_ASXY, 316, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 549, 0, 0, 29, 0, 0x7555, 0, 234, 0, 0, 64, 2, 202),
    L4(2, 0, 0, 0, 0, 6, 0, 0x755D, 0, 234, 0, 0, 64, 21, 0),
    L4(3, 0, 0, 0, 0, 7, 0, 0x755E, 0, 238, 0, 0, 64, 32, 159),
    L4(4, 0, 0, 0, 0, 8, 0, 0x755F, 0, 239, 0, 0, 64, 32, 167),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7560, 0, 240, 0, 0, 64, 32, 168),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7561, 0, 1, 0, 0, 64, 32, 162),
    CMD(CM_JPSS, 5, 37, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: [4]6+K light (plain script) */
const u16 remy_saca_041_head[4] = { HEAD(4, 0, 9, 10, 0, 1, 0) };
const u16 remy_saca_041[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7562, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 154, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 9, 0, 0x7563, 0, 242, 0, 0, 0, 32, 169),
    L4(2, 0, 575, 0, 0, 10, 0, 0x7564, 0, 243, 0, 0, 0, 32, 170),
    CMD(CM_ASXY, 342, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 11, 0, 0x7565, 0, 244, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 344, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 12, 0, 0x7566, 0, 245, 0, 0, 64, 2, 203),
    CMD(CM_ASXY, 346, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x7567, 0, 246, 0, 0, 64, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7568, 0, 247, 0, 0, 64, 32, 174),
    L4(4, 0, 0, 0, 0, 0, 0, 0x7569, 0, 248, 0, 0, 64, 32, 175),
    L4(4, 0, 0, 0, 0, 0, 0, 0x756A, 0, 249, 0, 0, 64, 32, 176),
    L4(3, 0, 0, 0, 0, 0, 0, 0x756B, 0, 250, 0, 0, 64, 32, 177),
    L4(3, 0, 0, 0, 0, 0, 0, 0x756C, 0, 251, 0, 0, 64, 32, 178),
    L4(3, 0, 0, 0, 0, 0, 0, 0x755A, 0, 1, 0, 0, 0, 32, 179),
    L4(3, 0, 0, 0, 0, 0, 0, 0x755B, 0, 1, 0, 0, 0, 32, 180),
    L4(3, 64, 0, 0, 0, 0, 0, 0x755C, 0, 1, 0, 0, 0, 32, 180),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7204, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7205, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7206, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x7207, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: [4]6+K medium (plain script) */
const u16 remy_saca_042_head[4] = { HEAD(4, 0, 11, 10, 0, 1, 0) };
const u16 remy_saca_042[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7562, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 154, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 9, 0, 0x7563, 0, 242, 0, 0, 0, 32, 169),
    L4(2, 0, 575, 0, 0, 10, 0, 0x7564, 0, 243, 0, 0, 0, 32, 170),
    CMD(CM_ASXY, 342, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 11, 0, 0x7565, 0, 244, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 344, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 12, 0, 0x7566, 0, 245, 0, 0, 64, 2, 204),
    CMD(CM_JPSS, 5, 41, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: [4]6+K heavy (plain script) */
const u16 remy_saca_043_head[4] = { HEAD(4, 0, 13, 10, 0, 1, 0) };
const u16 remy_saca_043[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7562, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 154, 0), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 9, 0, 0x7563, 0, 242, 0, 0, 0, 32, 169),
    L4(2, 0, 575, 0, 0, 10, 0, 0x7564, 0, 243, 0, 0, 0, 32, 170),
    CMD(CM_ASXY, 342, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 11, 0, 0x7565, 0, 244, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 344, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 549, 0, 0, 12, 0, 0x7566, 0, 245, 0, 0, 64, 2, 205),
    CMD(CM_JPSS, 5, 41, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: EX [4]6+KK (plain script) */
const u16 remy_saca_044_head[4] = { HEAD(4, 0, 15, 10, 0, 2, 0) };
const u16 remy_saca_044[148] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7562, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 154, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 9, 0, 0x7563, 0, 242, 0, 0, 0, 32, 169),
    L4(2, 0, 575, 0, 0, 10, 0, 0x7564, 0, 243, 0, 0, 0, 32, 170),
    CMD(CM_ASXY, 342, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 11, 0, 0x7565, 0, 244, 0, 0, 0, 31, 1),
    CMD(CM_ASXY, 344, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 575, 0, 0, 12, 0, 0x7566, 0, 245, 0, 0, 64, 2, 206),
    CMD(CM_ASXY, 346, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 549, 0, 0, 30, 0, 0x7567, 0, 246, 0, 0, 64, 2, 207),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 14, 0, 0x7568, 0, 247, 0, 0, 64, 32, 174),
    L4(4, 0, 0, 0, 0, 15, 0, 0x756D, 0, 252, 0, 0, 64, 32, 175),
    L4(5, 0, 0, 0, 0, 0, 0, 0x756E, 0, 253, 0, 0, 64, 32, 181),
    L4(4, 0, 0, 0, 0, 0, 0, 0x756F, 0, 254, 0, 0, 64, 32, 182),
    CMD(CM_ASXY, 366, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 41, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: not started by a command */
const u16 remy_saca_045_head[4] = { HEAD(4, 0, 9, 10, 0, 0, 101) };
const u16 remy_saca_045[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B1, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B3, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B4, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B6, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B8, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75B9, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x75BA, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: 214+K light (routine Att_PL20_AT2) */
const u16 remy_saca_046_head[4] = { HEAD(4, 0, 9, 13, 0, 1, 32) };
const u16 remy_saca_046[124] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 282, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7521, 0, 294, 0, 0, 0, 32, 200),
    L4(2, 20, 0, 0, 0, 0, 7, 0x7522, 0, 295, 0, 0, 0, 1, 153),
    L4(3, 0, 0, 0, 0, 0, 8, 0x7523, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x7524, 0, 297, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7525, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7526, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 30, 552, 0, 0, 0, 10, 0x7528, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 12, 0x7529, -45, 300, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x752A, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x752B, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x752C, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x752A, 0, 302, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2) */
const u16 remy_saca_047_head[4] = { HEAD(4, 0, 11, 13, 0, 1, 32) };
const u16 remy_saca_047[132] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 282, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7521, 0, 294, 0, 0, 0, 32, 200),
    L4(2, 20, 0, 0, 0, 0, 7, 0x7522, 0, 295, 0, 0, 0, 1, 153),
    L4(3, 0, 0, 0, 0, 0, 8, 0x7523, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x7524, 0, 297, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7525, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7526, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7527, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 30, 552, 0, 0, 0, 8, 0x7528, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x7529, -73, 300, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x752A, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x752B, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x752C, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x752A, 0, 302, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) */
const u16 remy_saca_048_head[4] = { HEAD(4, 0, 13, 13, 0, 1, 32) };
const u16 remy_saca_048[132] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 282, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7521, 0, 294, 0, 0, 0, 32, 200),
    L4(2, 20, 0, 0, 0, 0, 7, 0x7522, 0, 295, 0, 0, 0, 1, 153),
    L4(3, 0, 0, 0, 0, 0, 8, 0x7523, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x7524, 0, 297, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x7525, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7526, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7527, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 30, 552, 0, 0, 0, 6, 0x7528, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 6, 0x7529, -74, 300, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x752A, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752B, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752C, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752A, 0, 302, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: EX 214+KK (routine Att_PL20_AT2) */
const u16 remy_saca_049_head[4] = { HEAD(4, 0, 15, 13, 0, 2, 32) };
const u16 remy_saca_049[188] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 282, 0, 0, 0, 0, 0x7260, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7521, 0, 294, 0, 0, 0, 32, 200),
    L4(2, 20, 0, 0, 0, 0, 7, 0x7522, 0, 295, 0, 0, 0, 1, 153),
    L4(3, 0, 0, 0, 0, 0, 8, 0x7523, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x7524, 0, 297, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7525, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7526, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x7527, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 30, 552, 0, 0, 0, 6, 0x7528, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 6, 0x7529, -75, 300, 0, 146, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x752A, 0, 301, 0, 146, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752B, 0, 302, 0, 146, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752C, 0, 302, 0, 146, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752A, 0, 302, 0, 146, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x752A, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752B, -76, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752C, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752D, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x752B, 0, 302, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: SA III 23623+K (plain script), 51 ATTACK 7 SP: SA III 23623+K (plain script), 52 ATTACK 8 S: SA III 23623+K (plain script), 53 ATTACK 8 M: SA III 23623+K (plain script) */
const u16 remy_saca_050_head[4] = { HEAD(4, 0, 32, 0, 0, 0, 104) };
const u16 remy_saca_050[172] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 5, 54, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x7619, 0, 291, 0, 0, 0, 13, 61),
    L4(3, 0, 0, 0, 0, 0, 0, 0x761A, 0, 291, 0, 0, 0, 0, 0),
    L4(45, 0, 0, 0, 0, 0, 0, 0x761B, -47, 291, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 4, 21, 0), 0, 0, 0, 0,
    CMD(CM_ATMF, 2, 1, 0), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 0, 0x761B, 0, 303, 0, 0, 0, 21, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0,
    L4(5, 20, 0, 0, 0, 0, 0, 0x761C, 0, 303, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x761D, 0, 303, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x761E, 0, 303, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x761F, 0, 303, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ATMF, 0, 1, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x7620, 0, 304, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x762B, 0, 304, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x762C, 0, 304, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x762D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x7203, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 16, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: after SA III 23623+K (plain script) */
const u16 remy_saca_054_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 104) };
const u16 remy_saca_054[88] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x761B, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7621, 0, 291, 0, 0, 0, 1, 145, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7622, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7623, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7624, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7625, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: started by routine Att_PL20_AT3 */
const u16 remy_saca_055_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 104) };
const u16 remy_saca_055[76] = {
    L6(4, 0, 0, 2, 0, 0, 0, 0x7626, 0, 291, 0, 0, 0, 1, 154, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7627, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7628, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x7629, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x762A, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: after SA III 23623+K (plain script) */
const u16 remy_saca_056_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 104) };
const u16 remy_saca_056[676] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x7464, 0, 291, 0, 0, 0, 32, 201, 0, 0, 0, 0, 0),
    L6(1, 0, 551, 0, 0, 0, 0, 0x7465, -56, 394, 0, 133, 0, 32, 201, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7466, 0, 127, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7467, 0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7469, 0, 129, 0, 0, 0, 32, 202, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x746A, 0, 130, 0, 0, 0, 32, 203, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x746B, 0, 130, 0, 0, 0, 32, 204, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x746C, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x7433, 0, 69, 0, 0, 0, 32, 205, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x7434, 0, 70, 0, 0, 0, 32, 206, 0, 0, 0, 0, 0),
    L6(2, 0, 548, 0, 0, 0, 0, 0x7435, -57, 71, 0, 143, 0, 32, 207, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7436, 0, 72, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7437, 0, 73, 0, 128, 0, 32, 208, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7438, 0, 74, 0, 0, 0, 32, 209, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x7439, 0, 75, 0, 0, 0, 32, 210, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 152, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x7405, 0, 77, 0, 0, 0, 32, 211, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x7406, 0, 78, 0, 0, 0, 32, 212, 0, 0, 0, 0, 0),
    L6(2, 0, 551, 0, 0, 0, 0, 0x7407, -58, 318, 0, 150, 0, 32, 213, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7408, 0, 80, 0, 128, 0, 32, 214, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7409, 0, 81, 0, 0, 0, 32, 215, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740A, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740B, 0, 82, 0, 0, 0, 32, 216, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740C, 0, 83, 0, 0, 0, 32, 217, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740D, 0, 84, 0, 0, 0, 32, 218, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740E, 0, 93, 0, 0, 0, 32, 219, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x740F, 0, 94, 0, 0, 0, 32, 220, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x7410, 0, 95, 0, 0, 0, 32, 221, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 153, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 551, 0, 0, 0, 0, 0x7411, -59, 96, 0, 161, 0, 32, 222, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7412, 0, 97, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7413, 0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7414, 0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 155, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x744E, 0, 132, 0, 0, 0, 32, 226, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x744F, 0, 133, 0, 0, 0, 32, 227, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x7450, 0, 134, 0, 0, 0, 32, 228, 0, 0, 0, 0, 0),
    L6(1, 0, 548, 1, 0, 0, 0, 0x7451, -60, 135, 0, 128, 0, 32, 229, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x7452, 0, 381, 0, 0, 0, 32, 230, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7453, 0, 137, 0, 0, 0, 32, 231, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7454, 0, 138, 0, 0, 0, 32, 232, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7455, 0, 139, 0, 0, 0, 32, 233, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7456, 0, 140, 0, 0, 0, 32, 245, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x7596, 0, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 551, 0, 0, 0, 0, 0x7597, -51, 307, 0, 176, 0, 32, 240, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7598, 0, 308, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7599, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759A, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759B, 0, 311, 0, 0, 0, 32, 241, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759C, 0, 312, 0, 0, 0, 32, 242, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759D, 0, 313, 0, 0, 0, 32, 243, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x725D, 0, 1, 0, 0, 0, 32, 234, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: after SA III 23623+K (plain script) */
const u16 remy_saca_057_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 104) };
const u16 remy_saca_057[400] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 61, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 552, 0, 0, 0, 0, 0x7530, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x7530, 0, 384, 0, 0, 0, 30, 151, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 23, 0, 0x7531, -61, 386, 0, 147, 0, 32, 145, 0, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 24, 0, 0x7532, 62, 387, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 25, 0, 0x7533, 0, 388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 35, 0, 0, 0, 27, 0, 0x7534, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 27, 0, 0x7535, 0, 390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 27, 0, 0x7536, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722C, 0, 393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 28, 0, 0x7532, 0, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 28, 0, 0x7532, 0, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 28, 0, 0x7532, 0, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 28, 0, 0x7533, 0, 388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 28, 0, 0x7534, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 35, 0, 0, 0, 28, 0, 0x7534, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 28, 0, 0x7535, 0, 390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 28, 0, 0x7536, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x7537, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722C, 0, 393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: not started by a command */
const u16 remy_saca_062_head[4] = { HEAD(6, 0, 32, 11, 0, 1, 104) };
const u16 remy_saca_062[136] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x7595, 0, 305, 0, 0, 0, 32, 238, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x7596, 0, 306, 0, 0, 0, 32, 239, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7597, -51, 307, 0, 0, 0, 32, 240, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x7598, 0, 308, 0, 128, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x7599, 0, 309, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x759A, 0, 310, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x759B, 0, 311, 0, 0, 0, 32, 241, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x759C, 0, 312, 0, 0, 0, 32, 242, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x759D, 0, 313, 0, 0, 0, 32, 243, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x759E, 0, 314, 0, 0, 0, 32, 244, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: not started by a command */
const u16 remy_saca_063_head[4] = { HEAD(6, 0, 32, 11, 0, 1, 104) };
const u16 remy_saca_063[1412] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x759A, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759B, 0, 311, 0, 0, 0, 32, 241, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759C, 0, 312, 0, 0, 0, 32, 242, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759D, 0, 313, 0, 0, 0, 32, 243, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x759E, 0, 314, 0, 0, 0, 32, 244, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x7570, 0, 1, 0, 0, 0, 32, 234, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x753A, 0, 2, 0, 0, 0, 32, 235, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x7538, 0, 2, 0, 0, 0, 32, 236, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 50, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 20, 0, 0, 0, 0, 7, 0x7522, -61, 316, 0, 64, 0, 32, 237, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x7523, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x7524, 0, 297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x7525, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 552, 0, 0, 0, 8, 0x7528, 0, 299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 7, 0x7529, -62, 300, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 7, 0x752A, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 6, 0x74CC, 0, 173, 0, 0, 0, 32, 237, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x74CB, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x74CA, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 8, 0x74C9, 0, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0020, 0x0B00, 0x0168, 0x0900, 0x0008, 0x0000, 0x7594,
    CMD(CM_PS_X, 0, 0, 401), 0x0308, 0x0000, 0x0000, 0x0000, 0x0900, 0x0008, 0x0000, 0x7445,
    CMD(CM_PS_X, 0, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0300, 0x10C8, 0x0000, 0x7440,
    CMD(CM_NEX, 24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7441,
    L6(244, 13, 2048, 0, 0, 2048, 0, 0x0000, 12, 64, 0, 0, 0, 0, 0, 768, 0, 0, 116, 66),
    CMD(CM_NEX, -32768, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7443,
    CMD(CM_NEX, -24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7444,
    CMD(CM_NEX, -16384, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x746F,
    CMD(CM_FOR2, 0, 0, 8393), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x10D0, 0x0000, 0x7470,
    CMD(CM_FOR2, 8192, 0, 8394), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7471,
    L6(242, 206, 1024, 0, 0, 2048, 0, 0x20CB, 12, 64, 0, 0, 0, 0, 0, 768, 0, 0, 116, 114),
    CMD(CM_FOR2, 16384, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7473,
    CMD(CM_FOR2, 24576, 0, 5376), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7474,
    CMD(CM_FOR2, 24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7475,
    CMD(CM_FOR2, 24576, 0, 8396), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7476,
    CMD(CM_FOR2, 24576, 0, 8397), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7477,
    CMD(CM_FOR2, -32768, 0, 8398), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7478,
    CMD(CM_FOR2, -32768, 0, 8399), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7460,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7461,
    CMD(CM_NEX2, -32768, 0, 8400), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7462,
    CMD(CM_NEX2, -32768, 0, 8401), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x10E0, 0x0000, 0x7463,
    CMD(CM_NEX2, -32768, 0, 8402), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7464,
    CMD(CM_PS_Y, 24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x2270, 0x0000, 0x7465,
    L6(242, 143, 3072, 0, 0, 2464, 0, 0x20D3, 12, 64, 0, 0, 0, 0, 0, 256, 0, 0, 116, 102),
    CMD(CM_NEX2, -8192, -26112, 8404), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7467,
    CMD(CM_NEX2, -8192, -32768, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7468,
    CMD(CM_RJA, 0, 16384, 5376), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7469,
    CMD(CM_RJA, 8192, 0, 8405), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x746A,
    CMD(CM_RJA, 16384, 0, 8406), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x746B,
    CMD(CM_RJA, 16384, 0, 8407), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x746C,
    CMD(CM_RJA, 24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7446,
    CMD(CM_FOR2, -24576, 0, 8408), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x10D0, 0x0000, 0x7447,
    CMD(CM_FOR2, -16384, 0, 8409), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x2250, 0x0000, 0x7448,
    L6(243, 206, 3584, 0, 0, 2608, 0, 0x20DA, 12, 64, 0, 0, 0, 0, 0, 256, 0, 0, 116, 73),
    CMD(CM_NEX2, 0, -32768, 8411), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x744A,
    CMD(CM_NEX2, 0, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x744B,
    CMD(CM_NEX2, 16384, 0, 8412), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x744C,
    CMD(CM_NEX2, 24576, 0, 8413), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x744D,
    CMD(CM_FOR2, -24576, 0, 8414), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x744E,
    CMD(CM_RJA, -32768, 0, 8415), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x10E4, 0x0000, 0x744F,
    CMD(CM_RJA, -24576, 0, 8416), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x2264, 0x0000, 0x7450,
    CMD(CM_RJA, -16384, 0, 8417), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0004, 0x0000, 0x7451,
    L6(243, 144, 3584, 0, 0, 2048, 0, 0x20E2, 12, 64, 0, 0, 0, 0, 0, 512, 4, 0, 116, 82),
    CMD(CM_UJA, 0, 0, 8419), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7453,
    CMD(CM_UJA, 8192, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7454,
    CMD(CM_UJA, 16384, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7455,
    CMD(CM_UJA, 24576, 0, 8420), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7456,
    CMD(CM_UJA, -32768, 0, 8421), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7457,
    CMD(CM_UJA, -32768, 0, 8422), 0x0308, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x7458,
    CMD(CM_UJA, -24576, 0, 8423), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7595,
    CMD(CM_PS_X, 8192, 0, 8424), 0x0308, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x7596,
    CMD(CM_PS_X, 16384, 0, 8425), 0x0308, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x7597,
    L6(243, 102, 1536, 0, 0, 0, 0, 0x20EA, 12, 64, 0, 0, 0, 0, 0, 512, 0, 0, 117, 152),
    CMD(CM_PS_X, -32768, -32768, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0600, 0x0000, 0x0000, 0x7599,
    CMD(CM_PS_X, -24576, 0, 0), 0x0308, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x759A,
    CMD(CM_PS_X, -16384, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x759B,
    CMD(CM_PS_X, -8192, 0, 8427), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x759C,
    CMD(CM_PS_Y, 0, 0, 8428), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x759D,
    CMD(CM_PS_Y, 8192, 0, 8429), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x759E,
    CMD(CM_PS_Y, 16384, 0, 8430), 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0007, 0x0010, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 32, 2816, 360), 0x0100, 0x10C0, 0x0000, 0x7440, 0x000D, 0x6000, 0x0000, 0x0000,
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 65, 62477, 32768, 32768, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 12, 0, 0, 0, 0, 116, 66, 13, 32768, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 67, 13, 40960, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 68, 13, 49152, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 70, 14, 40960, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 4304, 0, 0, 116, 71, 14, 49152, 0, 32, 25),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 1, 592, 0, 0, 116, 72, 62414, 57344, 35328, 32, 26),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 73, 15, 0, 32768, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 74, 15, 0, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 12, 0, 0, 0, 0, 116, 75, 15, 16384, 0, 32, 27),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 76, 15, 24576, 0, 32, 28),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 12, 0, 0, 0, 0, 116, 77, 14, 40960, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 12, 0, 0, 0, 0, 116, 78, 16, 32768, 0, 32, 103),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 4324, 0, 0, 116, 79, 16, 40960, 0, 32, 104),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 1, 612, 0, 0, 116, 80, 16, 49152, 0, 32, 105),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 4, 0, 0, 116, 81, 62352, 57344, 32768, 32, 106),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 4, 0, 0, 116, 82, 17, 0, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 83, 17, 8192, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 84, 17, 16384, 0, 32, 107),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 85, 17, 24576, 0, 32, 108),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 86, 17, 32768, 0, 32, 109),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 116, 87, 17, 32768, 0, 32, 110),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 88, 17, 40960, 0, 32, 111),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 116, 89, 17, 40960, 0, 32, 112),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 117, 149, 38, 8192, 0, 32, 201),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 117, 150, 38, 16384, 0, 32, 202),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 4, 0, 0, 0, 0, 117, 151, 62310, 24576, 0, 32, 203),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 117, 152, 38, 32768, 32768, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 16, 0, 0, 0, 0, 117, 153, 38, 40960, 0, 0, 0),
    L6(3, 8, 0, 0, 0, 0, 0, 0x0000, 16, 0, 0, 0, 0, 117, 154, 38, 49152, 0, 21, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x759B, 0x0026, 0xE000, 0x0000, 0x20CC,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x759C, 0x0027, 0x0000, 0x0000, 0x20CD,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x759D, 0x0027, 0x2000, 0x0000, 0x20CE,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x759E, 0x0027, 0x4000, 0x0000, 0x20CF,
    CMD(CM_DUMMY, 0, 0, 0), 0x0004, 0x0007, 0x0010, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 58 ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1), 59 ATTACK 9 SP: SA II 23623+K (routine Att_PL20_AT1), 60 ATTACK 10 S: SA II 23623+K (routine Att_PL20_AT1), 61 ATTACK 10 M: SA II 23623+K (routine Att_PL20_AT1) */
const u16 remy_saca_058_head[4] = { HEAD(4, 0, 33, 15, 0, 10, 103) };
const u16 remy_saca_058[444] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 58, 24), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x753E, 0, 291, 0, 0, 0, 13, 67),
    L4(2, 0, 564, 0, 0, 0, 0, 0x753D, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7608, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7609, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x760A, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x760B, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x760C, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x760D, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x760E, 0, 293, 0, 0, 0, 0, 0),
    L4(32, 0, 0, 0, 0, 0, 0, 0x760F, 0, 293, 0, 0, 0, 0, 0),
    L4(1, 0, 548, 0, 0, 0, 0, 0x7530, 0, 291, 0, 0, 0, 30, 151),
    L4(1, 0, 270, 0, 0, 23, 0, 0x7530, -63, 334, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 24, 0, 0x7531, -64, 336, 0, 64, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 24, 0, 0x7532, -65, 337, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 35, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 58, 37), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 30, 151),
    L4(1, 0, 270, 0, 0, 23, 0, 0x7530, -66, 335, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 24, 0, 0x7531, -67, 336, 0, 64, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 24, 0, 0x7532, -68, 337, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 35, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x722C, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7538, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x7539, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x753A, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(2, 0, 551, 0, 0, 0, 0, 0x7530, 0, 273, 0, 0, 0, 30, 151),
    L4(2, 0, 270, 0, 0, 23, 0, 0x7530, -69, 335, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 24, 0, 0x7531, -70, 336, 0, 64, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 24, 0, 0x7532, -71, 336, 0, 64, 0, 1, 149),
    L4(4, 0, 0, 0, 0, 24, 0, 0x7532, -72, 337, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 25, 0, 0x7533, 0, 277, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 26, 0, 0x7534, 0, 278, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7534, 0, 278, 0, 0, 0, 21, 0),
    L4(3, 35, 0, 0, 0, 27, 0, 0x7535, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 27, 0, 0x7536, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 27, 0, 0x7537, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722D, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722E, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x722F, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 41 entries */
const u16* const remy_cbca[42] = {
    remy_cbca_000,  /* 0 APPEAR JUNBI 1 */
    remy_cbca_001,  /* 1 APPEAR JUNBI 2 */
    remy_cbca_002,  /* 2 APPEAR JUNBI 3 */
    remy_cbca_003,  /* 3 APPEAR JUNBI 4 */
    remy_cbca_004,  /* 4 APPEAR JUNBI 5 */
    remy_cbca_005,  /* 5 APPEAR JUNBI 6 */
    remy_cbca_006,  /* 6 APPEAR JUNBI 7 */
    remy_cbca_007,  /* 7 APPEAR JUNBI 8 */
    remy_cbca_008,  /* 8 APPEAR 1 */
    remy_cbca_009,  /* 9 APPEAR 2 */
    remy_cbca_010,  /* 10 APPEAR 3 */
    remy_cbca_011,  /* 11 APPEAR 4 */
    remy_cbca_012,  /* 12 APPEAR 5 */
    remy_cbca_013,  /* 13 APPEAR 6 */
    remy_cbca_014,  /* 14 APPEAR 7 */
    remy_cbca_015,  /* 15 APPEAR 8 */
    remy_cbca_016,  /* 16 SP APPEAR 1 */
    remy_cbca_017,  /* 17 SP APPEAR 2 */
    remy_cbca_018,  /* 18 SP APPEAR 3 */
    remy_cbca_019,  /* 19 SP APPEAR 4 */
    remy_cbca_020,  /* 20 SP APPEAR 5 */
    remy_cbca_021,  /* 21 SP APPEAR 6 */
    remy_cbca_022,  /* 22 SP APPEAR 7 */
    remy_cbca_023,  /* 23 SP APPEAR 8 */
    remy_cbca_000,  /* 24 ZANNEN 1 */
    remy_cbca_000,  /* 25 ZANNEN 2 */
    remy_cbca_000,  /* 26 ZANNEN 3 */
    remy_cbca_000,  /* 27 ZANNEN 4 */
    remy_cbca_000,  /* 28 ZANNEN 5 */
    remy_cbca_000,  /* 29 ZANNEN 6 */
    remy_cbca_000,  /* 30 ZANNEN 7 */
    remy_cbca_000,  /* 31 ZANNEN 8 */
    remy_cbca_000,  /* 32 WIN 1 */
    remy_cbca_000,  /* 33 WIN 2 */
    remy_cbca_000,  /* 34 WIN 3 */
    remy_cbca_000,  /* 35 WIN 4 */
    remy_cbca_000,  /* 36 WIN 5 */
    remy_cbca_000,  /* 37 WIN 6 */
    remy_cbca_000,  /* 38 WIN 7 */
    remy_cbca_000,  /* 39 WIN 8 */
    remy_cbca_000,  /* 40 SP WIN 1 */
    0
};

/* script: 0 APPEAR JUNBI 1, 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3 ... */
const u16 remy_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_000[8] = {
    CMD(CM_IF_L, 2, 8196, 8195),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 remy_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 remy_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 remy_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 remy_cbca_004_head[4] = { HEAD(2, 32, 0, 0, 0, 0, 0) };
const u16 remy_cbca_004[24] = {
    CMD(CM_RJA, 0, 7, 3),
    CMD(CM_RJA2, 0, 7, 53),
    CMD(CM_RJA3, 0, 7, 78),
    CMD(CM_PJMP, 22, 8194, 8192),
    CMD(CM_PJMP, 10, 8195, 8192),
    CMD(CM_PJMP, 8, 8196, 8193),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 remy_cbca_005_head[4] = { HEAD(2, 32, 0, 0, 0, 0, 0) };
const u16 remy_cbca_005[24] = {
    CMD(CM_RJA, 0, 7, 28),
    CMD(CM_RJA2, 0, 7, 78),
    CMD(CM_RJA3, 0, 7, 3),
    CMD(CM_PJMP, 10, 8194, 8192),
    CMD(CM_PJMP, 10, 8195, 8192),
    CMD(CM_PJMP, 24, 8196, 8193),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 remy_cbca_006_head[4] = { HEAD(2, 32, 0, 0, 0, 0, 0) };
const u16 remy_cbca_006[24] = {
    CMD(CM_RJA, 0, 7, 53),
    CMD(CM_RJA2, 0, 7, 3),
    CMD(CM_RJA3, 0, 7, 28),
    CMD(CM_PJMP, 4, 8194, 8192),
    CMD(CM_PJMP, 22, 8195, 8192),
    CMD(CM_PJMP, 16, 8196, 8193),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 remy_cbca_007_head[4] = { HEAD(2, 32, 0, 0, 0, 0, 0) };
const u16 remy_cbca_007[24] = {
    CMD(CM_RJA, 0, 7, 78),
    CMD(CM_RJA2, 0, 7, 28),
    CMD(CM_RJA3, 0, 7, 53),
    CMD(CM_PJMP, 4, 8194, 8192),
    CMD(CM_PJMP, 16, 8195, 8192),
    CMD(CM_PJMP, 8, 8196, 8193),
};

/* script: 8 APPEAR 1 */
const u16 remy_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_008[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 remy_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_009[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 20, 1),
    CMD(CM_RJA3, 7, 21, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 remy_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_010[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 remy_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 remy_cbca_012_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 remy_cbca_012[16] = {
    CMD(CM_EXEC, 49, 52, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 remy_cbca_013_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 remy_cbca_013[16] = {
    CMD(CM_EXEC, 49, 53, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 remy_cbca_014_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 remy_cbca_014[16] = {
    CMD(CM_EXEC, 49, 54, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 remy_cbca_015_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 remy_cbca_015[16] = {
    CMD(CM_EXEC, 49, 55, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 remy_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_016[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 remy_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_017[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 22, 1),
    CMD(CM_RJA3, 7, 23, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 remy_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_018[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 remy_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_019[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 remy_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_020[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 28, 1),
    CMD(CM_RJA3, 7, 29, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 remy_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_021[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 32, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 remy_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_022[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 remy_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 remy_cbca_023[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

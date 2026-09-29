/*
 * NECRO_CHAR.C  Necro's animation scripts and sprite part tables
 *
 * The animation scripts Necro's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 necro_nmca_000[], necro_nmca_001[], necro_nmca_002[], necro_nmca_003[], necro_nmca_004[], necro_nmca_005[], necro_nmca_006[], necro_nmca_007[], necro_nmca_008[], necro_nmca_011[], necro_nmca_012[], necro_nmca_013[], necro_nmca_014[], necro_nmca_015[], necro_nmca_016[], necro_nmca_017[], necro_nmca_020[], necro_nmca_021[], necro_nmca_022[], necro_nmca_023[], necro_nmca_024[], necro_nmca_026[], necro_nmca_027[], necro_nmca_028[], necro_nmca_029[], necro_nmca_030[], necro_nmca_031[], necro_nmca_032[], necro_nmca_033[], necro_nmca_038[], necro_nmca_040[], necro_nmca_041[], necro_nmca_043[], necro_nmca_044[], necro_nmca_045[], necro_nmca_046[], necro_nmca_047[], necro_nmca_048[], necro_nmca_049[], necro_nmca_050[];
extern const u16 necro_nmca_000_head[];
extern const u16 necro_nmca_001_head[];
extern const u16 necro_nmca_002_head[];
extern const u16 necro_nmca_003_head[];
extern const u16 necro_nmca_004_head[];
extern const u16 necro_nmca_005_head[];
extern const u16 necro_nmca_006_head[];
extern const u16 necro_nmca_007_head[];
extern const u16 necro_nmca_008_head[];
extern const u16 necro_nmca_011_head[];
extern const u16 necro_nmca_012_head[];
extern const u16 necro_nmca_013_head[];
extern const u16 necro_nmca_014_head[];
extern const u16 necro_nmca_015_head[];
extern const u16 necro_nmca_016_head[];
extern const u16 necro_nmca_017_head[];
extern const u16 necro_nmca_020_head[];
extern const u16 necro_nmca_021_head[];
extern const u16 necro_nmca_022_head[];
extern const u16 necro_nmca_023_head[];
extern const u16 necro_nmca_024_head[];
extern const u16 necro_nmca_026_head[];
extern const u16 necro_nmca_027_head[];
extern const u16 necro_nmca_028_head[];
extern const u16 necro_nmca_029_head[];
extern const u16 necro_nmca_030_head[];
extern const u16 necro_nmca_031_head[];
extern const u16 necro_nmca_032_head[];
extern const u16 necro_nmca_033_head[];
extern const u16 necro_nmca_038_head[];
extern const u16 necro_nmca_040_head[];
extern const u16 necro_nmca_041_head[];
extern const u16 necro_nmca_043_head[];
extern const u16 necro_nmca_044_head[];
extern const u16 necro_nmca_045_head[];
extern const u16 necro_nmca_046_head[];
extern const u16 necro_nmca_047_head[];
extern const u16 necro_nmca_048_head[];
extern const u16 necro_nmca_049_head[];
extern const u16 necro_nmca_050_head[];
extern const u16 necro_dmca_000[], necro_dmca_001[], necro_dmca_002[], necro_dmca_003[], necro_dmca_004[], necro_dmca_006[], necro_dmca_008[], necro_dmca_009[], necro_dmca_010[], necro_dmca_018[], necro_dmca_019[], necro_dmca_014[], necro_dmca_015[], necro_dmca_034[], necro_dmca_022[], necro_dmca_024[], necro_dmca_025[], necro_dmca_026[], necro_dmca_028[], necro_dmca_029[], necro_dmca_030[], necro_dmca_036[], necro_dmca_048[], necro_dmca_049[], necro_dmca_050[], necro_dmca_052[], necro_dmca_060[], necro_dmca_064[], necro_dmca_065[], necro_dmca_066[], necro_dmca_067[], necro_dmca_068[], necro_dmca_069[], necro_dmca_070[], necro_dmca_071[], necro_dmca_072[], necro_dmca_073[], necro_dmca_074[], necro_dmca_075[], necro_dmca_076[], necro_dmca_078[], necro_dmca_079[], necro_dmca_080[], necro_dmca_082[], necro_dmca_083[], necro_dmca_084[], necro_dmca_090[], necro_dmca_091[], necro_dmca_096[], necro_dmca_097[];
extern const u16 necro_dmca_000_head[];
extern const u16 necro_dmca_001_head[];
extern const u16 necro_dmca_002_head[];
extern const u16 necro_dmca_003_head[];
extern const u16 necro_dmca_004_head[];
extern const u16 necro_dmca_006_head[];
extern const u16 necro_dmca_008_head[];
extern const u16 necro_dmca_009_head[];
extern const u16 necro_dmca_010_head[];
extern const u16 necro_dmca_018_head[];
extern const u16 necro_dmca_019_head[];
extern const u16 necro_dmca_014_head[];
extern const u16 necro_dmca_015_head[];
extern const u16 necro_dmca_034_head[];
extern const u16 necro_dmca_022_head[];
extern const u16 necro_dmca_024_head[];
extern const u16 necro_dmca_025_head[];
extern const u16 necro_dmca_026_head[];
extern const u16 necro_dmca_028_head[];
extern const u16 necro_dmca_029_head[];
extern const u16 necro_dmca_030_head[];
extern const u16 necro_dmca_036_head[];
extern const u16 necro_dmca_048_head[];
extern const u16 necro_dmca_049_head[];
extern const u16 necro_dmca_050_head[];
extern const u16 necro_dmca_052_head[];
extern const u16 necro_dmca_060_head[];
extern const u16 necro_dmca_064_head[];
extern const u16 necro_dmca_065_head[];
extern const u16 necro_dmca_066_head[];
extern const u16 necro_dmca_067_head[];
extern const u16 necro_dmca_068_head[];
extern const u16 necro_dmca_069_head[];
extern const u16 necro_dmca_070_head[];
extern const u16 necro_dmca_071_head[];
extern const u16 necro_dmca_072_head[];
extern const u16 necro_dmca_073_head[];
extern const u16 necro_dmca_074_head[];
extern const u16 necro_dmca_075_head[];
extern const u16 necro_dmca_076_head[];
extern const u16 necro_dmca_078_head[];
extern const u16 necro_dmca_079_head[];
extern const u16 necro_dmca_080_head[];
extern const u16 necro_dmca_082_head[];
extern const u16 necro_dmca_083_head[];
extern const u16 necro_dmca_084_head[];
extern const u16 necro_dmca_090_head[];
extern const u16 necro_dmca_091_head[];
extern const u16 necro_dmca_096_head[];
extern const u16 necro_dmca_097_head[];
extern const u16 necro_btca_000[], necro_btca_001[], necro_btca_002[], necro_btca_003[], necro_btca_004[], necro_btca_005[], necro_btca_006[], necro_btca_007[], necro_btca_008[], necro_btca_009[], necro_btca_010[], necro_btca_011[], necro_btca_012[], necro_btca_013[], necro_btca_014[], necro_btca_015[], necro_btca_016[], necro_btca_017[], necro_btca_018[], necro_btca_019[], necro_btca_020[], necro_btca_022[], necro_btca_023[], necro_btca_025[], necro_btca_026[], necro_btca_027[], necro_btca_028[], necro_btca_029[], necro_btca_030[], necro_btca_031[], necro_btca_032[], necro_btca_033[], necro_btca_034[];
extern const u16 necro_btca_000_head[];
extern const u16 necro_btca_001_head[];
extern const u16 necro_btca_002_head[];
extern const u16 necro_btca_003_head[];
extern const u16 necro_btca_004_head[];
extern const u16 necro_btca_005_head[];
extern const u16 necro_btca_006_head[];
extern const u16 necro_btca_007_head[];
extern const u16 necro_btca_008_head[];
extern const u16 necro_btca_009_head[];
extern const u16 necro_btca_010_head[];
extern const u16 necro_btca_011_head[];
extern const u16 necro_btca_012_head[];
extern const u16 necro_btca_013_head[];
extern const u16 necro_btca_014_head[];
extern const u16 necro_btca_015_head[];
extern const u16 necro_btca_016_head[];
extern const u16 necro_btca_017_head[];
extern const u16 necro_btca_018_head[];
extern const u16 necro_btca_019_head[];
extern const u16 necro_btca_020_head[];
extern const u16 necro_btca_022_head[];
extern const u16 necro_btca_023_head[];
extern const u16 necro_btca_025_head[];
extern const u16 necro_btca_026_head[];
extern const u16 necro_btca_027_head[];
extern const u16 necro_btca_028_head[];
extern const u16 necro_btca_029_head[];
extern const u16 necro_btca_030_head[];
extern const u16 necro_btca_031_head[];
extern const u16 necro_btca_032_head[];
extern const u16 necro_btca_033_head[];
extern const u16 necro_btca_034_head[];
extern const u16 necro_caca_000[], necro_caca_001[], necro_caca_002[], necro_caca_003[], necro_caca_004[], necro_caca_005[], necro_caca_006[], necro_caca_007[], necro_caca_008[], necro_caca_009[], necro_caca_010[], necro_caca_011[];
extern const u16 necro_caca_000_head[];
extern const u16 necro_caca_001_head[];
extern const u16 necro_caca_002_head[];
extern const u16 necro_caca_003_head[];
extern const u16 necro_caca_004_head[];
extern const u16 necro_caca_005_head[];
extern const u16 necro_caca_006_head[];
extern const u16 necro_caca_007_head[];
extern const u16 necro_caca_008_head[];
extern const u16 necro_caca_009_head[];
extern const u16 necro_caca_010_head[];
extern const u16 necro_caca_011_head[];
extern const u16 necro_cuca_000[], necro_cuca_001[], necro_cuca_002[], necro_cuca_003[], necro_cuca_004[], necro_cuca_005[], necro_cuca_006[], necro_cuca_007[], necro_cuca_008[], necro_cuca_009[], necro_cuca_010[], necro_cuca_011[], necro_cuca_012[], necro_cuca_013[], necro_cuca_014[], necro_cuca_015[], necro_cuca_016[], necro_cuca_017[], necro_cuca_018[], necro_cuca_019[], necro_cuca_020[], necro_cuca_021[], necro_cuca_022[], necro_cuca_023[], necro_cuca_024[], necro_cuca_025[], necro_cuca_026[], necro_cuca_027[], necro_cuca_028[], necro_cuca_029[], necro_cuca_030[], necro_cuca_031[], necro_cuca_032[], necro_cuca_033[], necro_cuca_034[], necro_cuca_035[], necro_cuca_036[], necro_cuca_037[], necro_cuca_038[], necro_cuca_039[], necro_cuca_040[], necro_cuca_041[], necro_cuca_042[], necro_cuca_043[], necro_cuca_044[], necro_cuca_045[], necro_cuca_046[], necro_cuca_047[], necro_cuca_048[], necro_cuca_049[], necro_cuca_050[], necro_cuca_051[], necro_cuca_052[], necro_cuca_053[], necro_cuca_054[], necro_cuca_055[], necro_cuca_056[], necro_cuca_057[], necro_cuca_058[], necro_cuca_059[], necro_cuca_060[], necro_cuca_061[], necro_cuca_062[], necro_cuca_063[], necro_cuca_064[], necro_cuca_065[], necro_cuca_066[], necro_cuca_067[];
extern const u16 necro_cuca_000_head[];
extern const u16 necro_cuca_001_head[];
extern const u16 necro_cuca_002_head[];
extern const u16 necro_cuca_003_head[];
extern const u16 necro_cuca_004_head[];
extern const u16 necro_cuca_005_head[];
extern const u16 necro_cuca_006_head[];
extern const u16 necro_cuca_007_head[];
extern const u16 necro_cuca_008_head[];
extern const u16 necro_cuca_009_head[];
extern const u16 necro_cuca_010_head[];
extern const u16 necro_cuca_011_head[];
extern const u16 necro_cuca_012_head[];
extern const u16 necro_cuca_013_head[];
extern const u16 necro_cuca_014_head[];
extern const u16 necro_cuca_015_head[];
extern const u16 necro_cuca_016_head[];
extern const u16 necro_cuca_017_head[];
extern const u16 necro_cuca_018_head[];
extern const u16 necro_cuca_019_head[];
extern const u16 necro_cuca_020_head[];
extern const u16 necro_cuca_021_head[];
extern const u16 necro_cuca_022_head[];
extern const u16 necro_cuca_023_head[];
extern const u16 necro_cuca_024_head[];
extern const u16 necro_cuca_025_head[];
extern const u16 necro_cuca_026_head[];
extern const u16 necro_cuca_027_head[];
extern const u16 necro_cuca_028_head[];
extern const u16 necro_cuca_029_head[];
extern const u16 necro_cuca_030_head[];
extern const u16 necro_cuca_031_head[];
extern const u16 necro_cuca_032_head[];
extern const u16 necro_cuca_033_head[];
extern const u16 necro_cuca_034_head[];
extern const u16 necro_cuca_035_head[];
extern const u16 necro_cuca_036_head[];
extern const u16 necro_cuca_037_head[];
extern const u16 necro_cuca_038_head[];
extern const u16 necro_cuca_039_head[];
extern const u16 necro_cuca_040_head[];
extern const u16 necro_cuca_041_head[];
extern const u16 necro_cuca_042_head[];
extern const u16 necro_cuca_043_head[];
extern const u16 necro_cuca_044_head[];
extern const u16 necro_cuca_045_head[];
extern const u16 necro_cuca_046_head[];
extern const u16 necro_cuca_047_head[];
extern const u16 necro_cuca_048_head[];
extern const u16 necro_cuca_049_head[];
extern const u16 necro_cuca_050_head[];
extern const u16 necro_cuca_051_head[];
extern const u16 necro_cuca_052_head[];
extern const u16 necro_cuca_053_head[];
extern const u16 necro_cuca_054_head[];
extern const u16 necro_cuca_055_head[];
extern const u16 necro_cuca_056_head[];
extern const u16 necro_cuca_057_head[];
extern const u16 necro_cuca_058_head[];
extern const u16 necro_cuca_059_head[];
extern const u16 necro_cuca_060_head[];
extern const u16 necro_cuca_061_head[];
extern const u16 necro_cuca_062_head[];
extern const u16 necro_cuca_063_head[];
extern const u16 necro_cuca_064_head[];
extern const u16 necro_cuca_065_head[];
extern const u16 necro_cuca_066_head[];
extern const u16 necro_cuca_067_head[];
extern const u16 necro_atca_000[], necro_atca_002[], necro_atca_003[], necro_atca_005[], necro_atca_006[], necro_atca_008[], necro_atca_009[], necro_atca_011[], necro_atca_012[], necro_atca_014[], necro_atca_015[], necro_atca_017[], necro_atca_018[], necro_atca_021[], necro_atca_024[], necro_atca_026[], necro_atca_027[], necro_atca_030[], necro_atca_033[], necro_atca_036[], necro_atca_038[], necro_atca_040[], necro_atca_042[], necro_atca_043[], necro_atca_044[], necro_atca_046[], necro_atca_048[], necro_atca_050[], necro_atca_052[], necro_atca_054[], necro_atca_055[], necro_atca_056[], necro_atca_058[], necro_atca_060[], necro_atca_062[], necro_atca_064[], necro_atca_066[], necro_atca_067[], necro_atca_068[], necro_atca_070[], necro_atca_072[], necro_atca_074[], necro_atca_076[], necro_atca_078[], necro_atca_079[], necro_atca_080[], necro_atca_082[], necro_atca_084[], necro_atca_086[], necro_atca_088[], necro_atca_090[], necro_atca_091[], necro_atca_092[], necro_atca_094[], necro_atca_096[], necro_atca_098[], necro_atca_100[], necro_atca_102[], necro_atca_103[], necro_atca_104[], necro_atca_106[], necro_atca_108[], necro_atca_110[], necro_atca_112[], necro_atca_114[], necro_atca_116[], necro_atca_118[], necro_atca_144[], necro_atca_146[], necro_atca_156[], necro_atca_157[];
extern const u16 necro_atca_000_head[];
extern const u16 necro_atca_002_head[];
extern const u16 necro_atca_003_head[];
extern const u16 necro_atca_005_head[];
extern const u16 necro_atca_006_head[];
extern const u16 necro_atca_008_head[];
extern const u16 necro_atca_009_head[];
extern const u16 necro_atca_011_head[];
extern const u16 necro_atca_012_head[];
extern const u16 necro_atca_014_head[];
extern const u16 necro_atca_015_head[];
extern const u16 necro_atca_017_head[];
extern const u16 necro_atca_018_head[];
extern const u16 necro_atca_021_head[];
extern const u16 necro_atca_024_head[];
extern const u16 necro_atca_026_head[];
extern const u16 necro_atca_027_head[];
extern const u16 necro_atca_030_head[];
extern const u16 necro_atca_033_head[];
extern const u16 necro_atca_036_head[];
extern const u16 necro_atca_038_head[];
extern const u16 necro_atca_040_head[];
extern const u16 necro_atca_042_head[];
extern const u16 necro_atca_043_head[];
extern const u16 necro_atca_044_head[];
extern const u16 necro_atca_046_head[];
extern const u16 necro_atca_048_head[];
extern const u16 necro_atca_050_head[];
extern const u16 necro_atca_052_head[];
extern const u16 necro_atca_054_head[];
extern const u16 necro_atca_055_head[];
extern const u16 necro_atca_056_head[];
extern const u16 necro_atca_058_head[];
extern const u16 necro_atca_060_head[];
extern const u16 necro_atca_062_head[];
extern const u16 necro_atca_064_head[];
extern const u16 necro_atca_066_head[];
extern const u16 necro_atca_067_head[];
extern const u16 necro_atca_068_head[];
extern const u16 necro_atca_070_head[];
extern const u16 necro_atca_072_head[];
extern const u16 necro_atca_074_head[];
extern const u16 necro_atca_076_head[];
extern const u16 necro_atca_078_head[];
extern const u16 necro_atca_079_head[];
extern const u16 necro_atca_080_head[];
extern const u16 necro_atca_082_head[];
extern const u16 necro_atca_084_head[];
extern const u16 necro_atca_086_head[];
extern const u16 necro_atca_088_head[];
extern const u16 necro_atca_090_head[];
extern const u16 necro_atca_091_head[];
extern const u16 necro_atca_092_head[];
extern const u16 necro_atca_094_head[];
extern const u16 necro_atca_096_head[];
extern const u16 necro_atca_098_head[];
extern const u16 necro_atca_100_head[];
extern const u16 necro_atca_102_head[];
extern const u16 necro_atca_103_head[];
extern const u16 necro_atca_104_head[];
extern const u16 necro_atca_106_head[];
extern const u16 necro_atca_108_head[];
extern const u16 necro_atca_110_head[];
extern const u16 necro_atca_112_head[];
extern const u16 necro_atca_114_head[];
extern const u16 necro_atca_116_head[];
extern const u16 necro_atca_118_head[];
extern const u16 necro_atca_144_head[];
extern const u16 necro_atca_146_head[];
extern const u16 necro_atca_156_head[];
extern const u16 necro_atca_157_head[];
extern const u16 necro_exca_000[], necro_exca_001[], necro_exca_003[], necro_exca_004[], necro_exca_005[], necro_exca_006[], necro_exca_007[], necro_exca_008[], necro_exca_009[], necro_exca_010[], necro_exca_012[], necro_exca_013[], necro_exca_014[], necro_exca_017[], necro_exca_021[], necro_exca_023[], necro_exca_024[], necro_exca_026[], necro_exca_027[], necro_exca_028[], necro_exca_029[], necro_exca_030[], necro_exca_031[], necro_exca_032[], necro_exca_033[], necro_exca_034[], necro_exca_035[], necro_exca_036[], necro_exca_037[], necro_exca_040[], necro_exca_041[], necro_exca_042[];
extern const u16 necro_exca_000_head[];
extern const u16 necro_exca_001_head[];
extern const u16 necro_exca_003_head[];
extern const u16 necro_exca_004_head[];
extern const u16 necro_exca_005_head[];
extern const u16 necro_exca_006_head[];
extern const u16 necro_exca_007_head[];
extern const u16 necro_exca_008_head[];
extern const u16 necro_exca_009_head[];
extern const u16 necro_exca_010_head[];
extern const u16 necro_exca_012_head[];
extern const u16 necro_exca_013_head[];
extern const u16 necro_exca_014_head[];
extern const u16 necro_exca_017_head[];
extern const u16 necro_exca_021_head[];
extern const u16 necro_exca_023_head[];
extern const u16 necro_exca_024_head[];
extern const u16 necro_exca_026_head[];
extern const u16 necro_exca_027_head[];
extern const u16 necro_exca_028_head[];
extern const u16 necro_exca_029_head[];
extern const u16 necro_exca_030_head[];
extern const u16 necro_exca_031_head[];
extern const u16 necro_exca_032_head[];
extern const u16 necro_exca_033_head[];
extern const u16 necro_exca_034_head[];
extern const u16 necro_exca_035_head[];
extern const u16 necro_exca_036_head[];
extern const u16 necro_exca_037_head[];
extern const u16 necro_exca_040_head[];
extern const u16 necro_exca_041_head[];
extern const u16 necro_exca_042_head[];
extern const u16 necro_saca_000[], necro_saca_001[], necro_saca_002[], necro_saca_024[], necro_saca_028[], necro_saca_029[], necro_saca_030[], necro_saca_031[], necro_saca_032[], necro_saca_033[], necro_saca_034[], necro_saca_036[], necro_saca_040[], necro_saca_041[], necro_saca_042[], necro_saca_044[], necro_saca_045[], necro_saca_046[], necro_saca_047[], necro_saca_048[], necro_saca_054[], necro_saca_058[], necro_saca_059[], necro_saca_060[], necro_saca_061[], necro_saca_062[], necro_saca_063[], necro_saca_066[];
extern const u16 necro_saca_000_head[];
extern const u16 necro_saca_001_head[];
extern const u16 necro_saca_002_head[];
extern const u16 necro_saca_024_head[];
extern const u16 necro_saca_028_head[];
extern const u16 necro_saca_029_head[];
extern const u16 necro_saca_030_head[];
extern const u16 necro_saca_031_head[];
extern const u16 necro_saca_032_head[];
extern const u16 necro_saca_033_head[];
extern const u16 necro_saca_034_head[];
extern const u16 necro_saca_036_head[];
extern const u16 necro_saca_040_head[];
extern const u16 necro_saca_041_head[];
extern const u16 necro_saca_042_head[];
extern const u16 necro_saca_044_head[];
extern const u16 necro_saca_045_head[];
extern const u16 necro_saca_046_head[];
extern const u16 necro_saca_047_head[];
extern const u16 necro_saca_048_head[];
extern const u16 necro_saca_054_head[];
extern const u16 necro_saca_058_head[];
extern const u16 necro_saca_059_head[];
extern const u16 necro_saca_060_head[];
extern const u16 necro_saca_061_head[];
extern const u16 necro_saca_062_head[];
extern const u16 necro_saca_063_head[];
extern const u16 necro_saca_066_head[];
extern const u16 necro_cbca_000[], necro_cbca_001[], necro_cbca_002[], necro_cbca_003[], necro_cbca_004[], necro_cbca_005[], necro_cbca_006[], necro_cbca_007[], necro_cbca_008[], necro_cbca_009[], necro_cbca_010[], necro_cbca_011[], necro_cbca_012[], necro_cbca_013[], necro_cbca_014[], necro_cbca_015[], necro_cbca_016[], necro_cbca_017[], necro_cbca_018[], necro_cbca_019[], necro_cbca_020[], necro_cbca_021[], necro_cbca_022[], necro_cbca_023[], necro_cbca_024[], necro_cbca_025[], necro_cbca_026[], necro_cbca_027[], necro_cbca_028[], necro_cbca_029[];
extern const u16 necro_cbca_000_head[];
extern const u16 necro_cbca_001_head[];
extern const u16 necro_cbca_002_head[];
extern const u16 necro_cbca_003_head[];
extern const u16 necro_cbca_004_head[];
extern const u16 necro_cbca_005_head[];
extern const u16 necro_cbca_006_head[];
extern const u16 necro_cbca_007_head[];
extern const u16 necro_cbca_008_head[];
extern const u16 necro_cbca_009_head[];
extern const u16 necro_cbca_010_head[];
extern const u16 necro_cbca_011_head[];
extern const u16 necro_cbca_012_head[];
extern const u16 necro_cbca_013_head[];
extern const u16 necro_cbca_014_head[];
extern const u16 necro_cbca_015_head[];
extern const u16 necro_cbca_016_head[];
extern const u16 necro_cbca_017_head[];
extern const u16 necro_cbca_018_head[];
extern const u16 necro_cbca_019_head[];
extern const u16 necro_cbca_020_head[];
extern const u16 necro_cbca_021_head[];
extern const u16 necro_cbca_022_head[];
extern const u16 necro_cbca_023_head[];
extern const u16 necro_cbca_024_head[];
extern const u16 necro_cbca_025_head[];
extern const u16 necro_cbca_026_head[];
extern const u16 necro_cbca_027_head[];
extern const u16 necro_cbca_028_head[];
extern const u16 necro_cbca_029_head[];

/* normal scripts: 51 entries */
const u16* const necro_nmca[52] = {
    necro_nmca_000,  /* 0 KAMAE */
    necro_nmca_001,  /* 1 HURIMUKI */
    necro_nmca_002,  /* 2 FRONT WALK */
    necro_nmca_003,  /* 3 BACK WALK */
    necro_nmca_004,  /* 4 DASH HUMIKOMI */
    necro_nmca_005,  /* 5 DASH TOBINOKI */
    necro_nmca_006,  /* 6 KAGAMU */
    necro_nmca_007,  /* 7 KAGAMI KAMAE */
    necro_nmca_008,  /* 8 KAGAMI TURN */
    necro_nmca_008,  /* 9 KAGAMI F WALK */
    necro_nmca_008,  /* 10 KAGAMI B WALK */
    necro_nmca_011,  /* 11 STAND UP */
    necro_nmca_012,  /* 12 JUMP JUNBI */
    necro_nmca_013,  /* 13 SP JUMP JUNBI */
    necro_nmca_014,  /* 14 JUMP FRONT */
    necro_nmca_015,  /* 15 JUMP VERTICAL */
    necro_nmca_016,  /* 16 JUMP BACK */
    necro_nmca_017,  /* 17 S JUMP FRONT */
    necro_nmca_017,  /* 18 S JUMP V */
    necro_nmca_017,  /* 19 S JUMP BACK */
    necro_nmca_020,  /* 20 SP JUMP FRONT */
    necro_nmca_021,  /* 21 SP JUMP V */
    necro_nmca_022,  /* 22 SP JUMP BACK */
    necro_nmca_023,  /* 23 WALK END */
    necro_nmca_024,  /* 24 PARING HEAD */
    necro_nmca_024,  /* 25 PARING UP */
    necro_nmca_026,  /* 26 PARING DOWN */
    necro_nmca_027,  /* 27 PARING AIR F */
    necro_nmca_028,  /* 28 PARING AIR B */
    necro_nmca_029,  /* 29 GUARD HEAD */
    necro_nmca_030,  /* 30 GUARD UP */
    necro_nmca_031,  /* 31 GUARD DOWN */
    necro_nmca_032,  /* 32 GUARD AIR */
    necro_nmca_033,  /* 33 no name */
    necro_nmca_033,  /* 34 no name */
    necro_nmca_033,  /* 35 no name */
    necro_nmca_033,  /* 36 no name */
    necro_nmca_033,  /* 37 no name */
    necro_nmca_038,  /* 38 P BREAK ZUJOU */
    necro_nmca_038,  /* 39 P BREAK UP */
    necro_nmca_040,  /* 40 P BREAK DOWN */
    necro_nmca_041,  /* 41 P BREAK AIR F */
    necro_nmca_041,  /* 42 P BREAK AIR R */
    necro_nmca_043,  /* 43 TUKAMIHAZUSI */
    necro_nmca_044,  /* 44 TUKAMIHAZUSARE */
    necro_nmca_045,  /* 45 TUKAMIHAZUSI */
    necro_nmca_046,  /* 46 TUKAMIHAZUSARE */
    necro_nmca_047,  /* 47 no name */
    necro_nmca_048,  /* 48 no name */
    necro_nmca_049,  /* 49 no name */
    necro_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 necro_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_000[180] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E02, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E03, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E04, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E05, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E06, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E07, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E08, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E09, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0A, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0B, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0C, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0D, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0E, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0F, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E10, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E11, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E12, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E13, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E14, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E15, 0, 263, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 necro_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_001[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E29, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E2A, 0, 268, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2B, 0, 269, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2C, 0, 276, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2D, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 necro_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 necro_nmca_002[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A7, 0, 283, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA0, 0, 283, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA1, 0, 283, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FA2, 0, 283, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA3, 0, 284, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA4, 0, 284, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA5, 0, 284, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FA6, 0, 285, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA7, 0, 285, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA8, 0, 285, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA9, 0, 285, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAA, 0, 286, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAB, 0, 286, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAC, 0, 286, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAD, 0, 286, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAE, 0, 287, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAF, 0, 287, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 necro_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 necro_nmca_003[156] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A8, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A9, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22AA, 0, 288, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x22AB, 0, 289, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB0, 0, 289, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB1, 0, 289, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1FB2, 0, 290, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB3, 0, 290, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB4, 0, 291, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB5, 0, 291, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1FB6, 0, 291, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB7, 0, 291, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB8, 0, 292, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB9, 0, 292, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBA, 0, 292, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBB, 0, 293, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBC, 0, 293, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBD, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 necro_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 necro_nmca_004[136] = {
    CMD(CM_RJA, 0, 4, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 1, 277, 0, 0, 0, 0, 0x1E38, 0, 273, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1E3E, 0, 274, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E39, 0, 275, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3A, 0, 275, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 necro_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 necro_nmca_005[136] = {
    CMD(CM_RJA, 0, 5, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 277, 0, 0, 0, 0, 0x1E40, 0, 279, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1E41, 0, 279, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 280, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E43, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 necro_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_006[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 294, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 294, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 necro_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_007[92] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E16, 0, 295, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E17, 0, 295, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E18, 0, 295, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E19, 0, 295, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1A, 0, 296, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1B, 0, 296, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1C, 0, 296, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1D, 0, 297, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1E, 0, 297, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1F, 0, 297, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 necro_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_008[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E31, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E32, 0, 303, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E33, 0, 304, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E36, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 necro_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_011[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 270, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 310, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 272, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 necro_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_012[28] = {
    L4(2, 1, 281, 0, 0, 0, 0, 0x1E20, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1E20, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E20, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 necro_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_013[20] = {
    L4(5, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 necro_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_014[156] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E4D, 0, 299, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x1E4E, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1E4F, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E50, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E51, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E52, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E53, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E54, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E55, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E56, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E57, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x1E58, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1E59, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5A, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 301, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 necro_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 necro_nmca_015[108] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E44, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E45, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E46, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x1E47, 0, 300, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E48, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E49, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 14, 0x1E4A, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 14, 0x1E48, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x1E47, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x1E4B, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 299, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 necro_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_016[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E5E, 0, 299, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x1E5F, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E60, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E55, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E54, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E53, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E52, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E51, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x1E50, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x1E5B, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 299, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 necro_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 necro_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 necro_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 necro_nmca_020[148] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E4D, 0, 299, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 6, 0x1E4E, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x1E4F, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E50, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E51, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E52, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E53, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E54, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E55, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E56, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E57, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E58, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x1E59, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5A, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 301, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 necro_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 necro_nmca_021[108] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x1E44, 0, 301, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E45, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E46, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x1E47, 0, 300, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x1E48, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E49, 0, 300, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 14, 0x1E4A, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 14, 0x1E48, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x1E47, 0, 300, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x1E4B, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 301, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 necro_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 necro_nmca_022[108] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x1E5E, 0, 299, 0, 0, 0, 18, 2),
    L4(6, 0, 0, 0, 0, 0, 12, 0x1E5F, 0, 299, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E60, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E55, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E54, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E53, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x1E52, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x1E51, 0, 298, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 6, 0x1E50, 0, 300, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 301, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 necro_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 necro_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_024[68] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x20CB, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 806, 0, 0, 0, 0, 0x20CD, 0, 1, 0, 0, 0, 6, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x20CC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x20CB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 necro_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_026[60] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 18, 6),
    L4(1, 0, 806, 0, 0, 0, 0, 0x229C, 0, 114, 0, 0, 0, 6, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x229D, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x229E, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x229F, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F */
const u16 necro_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_027[52] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 6),
    L4(2, 0, 806, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 6, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7A, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 PARING AIR B */
const u16 necro_nmca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_028[60] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 6),
    L4(3, 0, 806, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 6, 2),
    L4(17, 0, 0, 0, 0, 0, 0, 0x1E7A, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E5F, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 16, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 necro_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E61, 0, 113, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1E62, 0, 113, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1E63, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E66, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 necro_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_030[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 necro_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_031[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1E71, 0, 114, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E75, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E76, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 necro_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_032[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1E7A, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7C, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E77, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 necro_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E69, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 necro_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_038[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 necro_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_040[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E71, 0, 114, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x2095, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x2090, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 necro_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 8),
    L4(250, 0, 806, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 necro_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_043[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 necro_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_044[108] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x2097, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2097, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2098, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2099, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x209A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 1, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 necro_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_045[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 806, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E60, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 necro_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_046[76] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x1E4A, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 necro_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 necro_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 necro_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_049[384] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 4, 0, 0, 0, 0, 0),
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

/* script: 50 no name */
const u16 necro_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_050[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const necro_dmca[99] = {
    necro_dmca_000,  /* 0 GUARD HEAD */
    necro_dmca_001,  /* 1 GUARD UP */
    necro_dmca_002,  /* 2 GUARD DOWN */
    necro_dmca_003,  /* 3 GUARD AIR */
    necro_dmca_004,  /* 4 HUSHIN HEAD */
    necro_dmca_004,  /* 5 HUSHIN UP */
    necro_dmca_006,  /* 6 HUSHIN DOWN */
    necro_dmca_006,  /* 7 HUSHIN AIR */
    necro_dmca_008,  /* 8 FACE S */
    necro_dmca_009,  /* 9 FACE M */
    necro_dmca_010,  /* 10 FACE L */
    necro_dmca_010,  /* 11 FACE SP */
    necro_dmca_008,  /* 12 FOOK OKU S */
    necro_dmca_009,  /* 13 FOOK OKU M */
    necro_dmca_014,  /* 14 FOOK OKU L */
    necro_dmca_015,  /* 15 FOOK OKU SP */
    necro_dmca_008,  /* 16 FOOK TEMAE S */
    necro_dmca_009,  /* 17 FOOK TEMAE M */
    necro_dmca_018,  /* 18 FOOK TEMAE L */
    necro_dmca_019,  /* 19 FOOK TEMAE SP */
    necro_dmca_008,  /* 20 UPPER S */
    necro_dmca_009,  /* 21 UPPER M */
    necro_dmca_022,  /* 22 UPPER L */
    necro_dmca_022,  /* 23 UPPER SP */
    necro_dmca_024,  /* 24 NOUTEN S */
    necro_dmca_025,  /* 25 NOUTEN M */
    necro_dmca_026,  /* 26 NOUTEN L */
    necro_dmca_026,  /* 27 NOUTEN SP */
    necro_dmca_028,  /* 28 BODY BROW S */
    necro_dmca_029,  /* 29 BODY BROW M */
    necro_dmca_030,  /* 30 BODY BROW L */
    necro_dmca_030,  /* 31 BODY BROW SP */
    necro_dmca_028,  /* 32 BODY UPPER S */
    necro_dmca_029,  /* 33 BODY UPPER M */
    necro_dmca_034,  /* 34 BODY UPPER L */
    necro_dmca_034,  /* 35 BODY UPPER SP */
    necro_dmca_036,  /* 36 TATAKI S */
    necro_dmca_036,  /* 37 TATAKI M */
    necro_dmca_036,  /* 38 TATAKI L */
    necro_dmca_036,  /* 39 TATAKI SP */
    necro_dmca_036,  /* 40 TATAKI V. S */
    necro_dmca_036,  /* 41 TATAKI V. M */
    necro_dmca_036,  /* 42 TATAKI V. L */
    necro_dmca_036,  /* 43 TATAKI V. SP */
    necro_dmca_008,  /* 44 NOBASITA TE S */
    necro_dmca_009,  /* 45 NOBASITA TE M */
    necro_dmca_010,  /* 46 NOBASITA TE L */
    necro_dmca_010,  /* 47 NOBASITA TE SP */
    necro_dmca_048,  /* 48 KAGAMI S */
    necro_dmca_049,  /* 49 KAGAMI M */
    necro_dmca_050,  /* 50 KAGAMI L */
    necro_dmca_050,  /* 51 KAGAMI SP */
    necro_dmca_052,  /* 52 KGM TATAKI S */
    necro_dmca_052,  /* 53 KGM TATAKI M */
    necro_dmca_052,  /* 54 KGM TATAKI L */
    necro_dmca_052,  /* 55 KGM TATAKI SP */
    necro_dmca_052,  /* 56 KGM TTKI V.S */
    necro_dmca_052,  /* 57 KGM TTKI V.M */
    necro_dmca_052,  /* 58 KGM TTKI V.L */
    necro_dmca_052,  /* 59 KGM TTKI V.SP */
    necro_dmca_060,  /* 60 NEKOROBI S */
    necro_dmca_060,  /* 61 NEKOROBI M */
    necro_dmca_060,  /* 62 NEKOROBI L */
    necro_dmca_060,  /* 63 NEKOROBI SP */
    necro_dmca_064,  /* 64 OKIAGARI */
    necro_dmca_065,  /* 65 OKIAGARI F */
    necro_dmca_066,  /* 66 OKIAGARI B */
    necro_dmca_067,  /* 67 LOSE NO STAND */
    necro_dmca_068,  /* 68 LOSE SONABA */
    necro_dmca_069,  /* 69 LOSE KAGAMI */
    necro_dmca_070,  /* 70 PIYO */
    necro_dmca_071,  /* 71 UKEMI MOVE F */
    necro_dmca_072,  /* 72 UKEMI MOVE R */
    necro_dmca_073,  /* 73 SHIMEOTASARE */
    necro_dmca_074,  /* 74 TATI TOUKETU S */
    necro_dmca_075,  /* 75 TATI TOUKETU M */
    necro_dmca_076,  /* 76 TATI TOUKETU L */
    necro_dmca_076,  /* 77 TATI TOUKETU P */
    necro_dmca_078,  /* 78 KGM TOUKETU S */
    necro_dmca_079,  /* 79 KGM TOUKETU M */
    necro_dmca_080,  /* 80 KGM TOUKETU L */
    necro_dmca_080,  /* 81 KGM TOUKETU P */
    necro_dmca_082,  /* 82 TATI DENGEKI S */
    necro_dmca_083,  /* 83 TATI DENGEKI M */
    necro_dmca_084,  /* 84 TATI DENGEKI L */
    necro_dmca_084,  /* 85 TATI DENGEKI P */
    necro_dmca_082,  /* 86 KGM DENGEKI S */
    necro_dmca_083,  /* 87 KGM DENGEKI M */
    necro_dmca_084,  /* 88 KGM DENGEKI L */
    necro_dmca_084,  /* 89 KGM DENGEKI P */
    necro_dmca_090,  /* 90 OKIAGARI FRONT */
    necro_dmca_091,  /* 91 OKIAGARI REAR */
    necro_dmca_008,  /* 92 TATI MOE S */
    necro_dmca_009,  /* 93 TATI MOE M */
    necro_dmca_010,  /* 94 TATI MOE L */
    necro_dmca_010,  /* 95 TATI MOE SP */
    necro_dmca_096,  /* 96 no name */
    necro_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 necro_dmca_000_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_dmca_000[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E63, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E64, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E65, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E66, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 necro_dmca_001_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_dmca_001[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E6A, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E6B, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 necro_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_002[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E73, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E74, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E75, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 necro_dmca_003_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_dmca_003[124] = {
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
const u16 necro_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_004[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2085, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2086, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2087, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2089, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2088, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x208B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 necro_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_006[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x208D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2089, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2088, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x208B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 necro_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_008[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 802, 0, 0, 0, 0, 0x1FC1, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC1, 0, 208, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FC2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FC3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 necro_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_009[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC1, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 137, 802, 0, 0, 0, 0, 0x1FC5, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC6, 0, 209, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC7, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FC9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FCB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 necro_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_010[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC6, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 139, 802, 0, 0, 0, 0, 0x1FCD, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCE, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FCF, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD0, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCF, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD0, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FD1, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD2, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 necro_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_018[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2061, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 138, 802, 0, 0, 0, 0, 0x2061, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2062, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2063, 0, 210, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x2064, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 209, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x2066, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x209B, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 necro_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_019[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2060, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 802, 0, 0, 0, 0, 0x2061, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2062, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2063, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2064, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 10, 0, 0, 0, 0, 0, 0x2066, 0, 210, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x209B, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 necro_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_014[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 139, 802, 0, 0, 0, 0, 0x1FCF, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x1FD1, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2067, 0, 209, 0, 0, 0, 0, 0),
    L4(5, 10, 0, 0, 0, 0, 0, 0x2068, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x2069, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 209, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2066, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x209B, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 necro_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_015[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 139, 802, 0, 0, 0, 0, 0x1FCF, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD1, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2067, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2068, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2069, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 209, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2066, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x209B, 0, 209, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 necro_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 137, 802, 0, 0, 0, 0, 0x2080, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2081, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2082, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 necro_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_022[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FE8, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 137, 802, 0, 0, 0, 0, 0x2081, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2081, 0, 205, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 13, -32767), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x2082, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S */
const u16 necro_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_024[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 212, 0, 0, 0, 0, 0),
    L4(2, 135, 802, 0, 0, 0, 0, 0x2075, 0, 212, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 212, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2077, 0, 212, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 necro_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_025[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 212, 0, 0, 0, 0, 0),
    L4(2, 135, 802, 0, 0, 0, 0, 0x2075, 0, 213, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 213, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2077, 0, 212, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 necro_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_026[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2075, 0, 212, 0, 0, 0, 0, 0),
    L4(2, 135, 802, 0, 0, 0, 0, 0x2075, 0, 213, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 215, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2077, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 BODY BROW S, 32 BODY UPPER S */
const u16 necro_dmca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_028[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FD9, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 135, 802, 0, 0, 0, 0, 0x1FDA, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDA, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FDB, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FDC, 0, 204, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 necro_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_029[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FDD, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 136, 802, 0, 0, 0, 0, 0x1FDE, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDF, 0, 205, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE0, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDA, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDB, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FDC, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 necro_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_030[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FE1, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 139, 802, 0, 0, 0, 0, 0x1FE2, 0, 205, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE3, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE0, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE5, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 necro_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_036[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 802, 0, 0, 0, 0, 0x2084, 0, 215, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 necro_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_048[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEB, 0, 216, 0, 0, 0, 0, 0),
    L4(1, 134, 802, 0, 0, 0, 0, 0x1FEC, 0, 216, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEC, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FED, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FEE, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 necro_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_049[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF9, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 136, 802, 0, 0, 0, 0, 0x1FF0, 0, 217, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF1, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF2, 0, 216, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF3, 0, 216, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF4, 0, 216, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FF5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 necro_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_050[164] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF1, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 143, 802, 0, 0, 0, 0, 0x1FF7, 0, 217, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF8, 0, 217, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF9, 0, 219, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFA, 0, 218, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF9, 0, 219, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFA, 0, 218, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFB, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFC, 0, 216, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFF, 0, 217, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2000, 0, 217, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2001, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2002, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 necro_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_052[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEB, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 802, 0, 0, 0, 0, 0x2084, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 necro_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_060[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x206A, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 2, 802, 0, 0, 0, 0, 0x206B, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206C, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202A, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202B, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202C, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202D, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 necro_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_064[156] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x2003, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x2003, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2006, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2007, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x2008, 0, 115, 0, 0, 0, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 0, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 necro_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2011, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 806, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 necro_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_066[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 806, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 necro_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_067[28] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x2003, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2003, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 necro_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_068[148] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x2051, 0, 177, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x2052, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x2053, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x2054, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2055, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 necro_dmca_069_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_069[148] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x2051, 0, 177, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x2052, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x2053, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x2054, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 necro_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_070[84] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x2124, 0, 306, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2125, 0, 306, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2126, 0, 306, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2127, 0, 307, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2128, 0, 307, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2129, 0, 308, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x212A, 0, 309, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x212B, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 necro_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_071[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 65, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 necro_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_072[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 66, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 necro_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_073[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2051, 0, 177, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2052, 0, 177, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2053, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2054, 0, 177, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x2054, 0, 177, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2055, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 necro_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_074[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC0, 0, 208, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC0, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FC3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 necro_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_075[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC4, 0, 208, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC4, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FCB, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 necro_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_076[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 208, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FCC, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 necro_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_078[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEB, 0, 216, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEB, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FEE, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 necro_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_079[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEF, 0, 216, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEF, 0, 217, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FF5, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 necro_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_080[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF6, 0, 216, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FF6, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2001, 0, 217, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2002, 0, 218, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 necro_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 necro_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 necro_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 necro_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_090[212] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2011, 0, 115, 0, 0, 0, 0, 0),
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
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 necro_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_091[196] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201A, 0, 115, 0, 0, 0, 0, 0),
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
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 necro_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_096[44] = {
    L4(3, 2, 802, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 necro_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_097[44] = {
    L4(3, 2, 802, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const necro_btca[37] = {
    necro_btca_000,  /* 0 AIR NORMAL */
    necro_btca_001,  /* 1 ASIBARAI SIRI */
    necro_btca_002,  /* 2 ASIB TUNNOMERI */
    necro_btca_003,  /* 3 NOKEZORI */
    necro_btca_004,  /* 4 KUNOJI */
    necro_btca_005,  /* 5 KIRIMOMI */
    necro_btca_006,  /* 6 UPPER */
    necro_btca_007,  /* 7 BODY UPPER */
    necro_btca_008,  /* 8 HARAYARARE */
    necro_btca_009,  /* 9 TATAKI AIR */
    necro_btca_010,  /* 10 TTKI V. AIR */
    necro_btca_011,  /* 11 HUMI ASIB */
    necro_btca_012,  /* 12 FACE */
    necro_btca_013,  /* 13 ASIB SIRI LOSE */
    necro_btca_014,  /* 14 ASIB TUN LOSE */
    necro_btca_015,  /* 15 DENKI */
    necro_btca_016,  /* 16 KUNOJI NOKE */
    necro_btca_017,  /* 17 BODY UPPER SP */
    necro_btca_018,  /* 18 HANEAGARI */
    necro_btca_019,  /* 19 TOUKETSU A */
    necro_btca_020,  /* 20 BODY SLAM */
    necro_btca_020,  /* 21 IPPONZEOI */
    necro_btca_022,  /* 22 TOMOE RYU */
    necro_btca_023,  /* 23 MONKEY FLIP */
    necro_btca_023,  /* 24 TOMOE ORO */
    necro_btca_025,  /* 25 SNAKE FANG */
    necro_btca_026,  /* 26 FLANKEN.S */
    necro_btca_027,  /* 27 KISHINRIKI */
    necro_btca_028,  /* 28 SPLASH.M */
    necro_btca_029,  /* 29 HARAIGOSHI */
    necro_btca_030,  /* 30 ALEX B.D */
    necro_btca_031,  /* 31 GILL */
    necro_btca_032,  /* 32 HANEKAERI HARA */
    necro_btca_033,  /* 33 S HANEAGARI */
    necro_btca_034,  /* 34 TATUMAKIZANKU */
    necro_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 necro_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_000[76] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 803, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 137, 0, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 137, 0, 0, 0, 0, 0, 0x207B, 0, 227, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x207C, 0, 227, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 necro_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 9, 0x206E, 0, 230, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x206F, 0, 231, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 necro_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_002[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x206E, 0, 230, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 231, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 necro_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_003[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 necro_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_004[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FE2, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x1FE3, 0, 240, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 240, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 necro_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_005[148] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2040, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x2041, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2042, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2043, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2044, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2045, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2046, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2047, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2048, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2049, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204A, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204B, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204C, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204D, 0, 250, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204E, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x204F, 0, 251, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 necro_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_006[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 803, 0, 0, 0, 0, 0x2081, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2082, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 necro_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_007[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2079, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x207A, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2033, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 necro_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_008[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 necro_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_009[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 necro_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_010[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 255, 0, 0, 0, 0, 0),
    L4(250, 0, 803, 0, 0, 0, 0, 0x2084, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 necro_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_011[36] = {
    CMD(CM_RJA, 7, 28, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2072, 0, 257, 0, 0, 0, 0, 0),
    L4(250, 0, 803, 0, 0, 0, 0, 0x2073, 0, 258, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 necro_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_012[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC4, 0, 259, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 necro_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 necro_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 necro_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_015[76] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x2155, 0, 260, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 260, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 260, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 260, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 260, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 803, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 necro_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_016[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FE2, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x1FE3, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 necro_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_017[136] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 803, 0, 0, 0, 0, 0x2031, 0, 234, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2033, 0, 235, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 necro_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(3, 0, 803, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x2037, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x2036, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x2035, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 necro_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FCC, 0, 261, 0, 0, 0, 0, 0),
    L4(250, 0, 803, 0, 0, 0, 0, 0x1FCC, 0, 261, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM, 21 IPPONZEOI */
const u16 necro_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_020[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x202A, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 necro_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_022[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x203B, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x203A, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x203B, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x203B, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP, 24 TOMOE ORO */
const u16 necro_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_023[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x20DE, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x20DC, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 necro_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 necro_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_026[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x20DC, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x20DC, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 necro_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_027[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 necro_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_028[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2036, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2037, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 necro_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_029[36] = {
    CMD(CM_RJA, 7, 21, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 necro_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_030[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2079, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x207A, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2033, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 necro_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 803, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 necro_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2030, 0, 233, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 necro_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_033[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 803, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 necro_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_034[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 803, 0, 0, 0, 0, 0x2081, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2082, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 12 entries */
const u16* const necro_caca[13] = {
    necro_caca_000,  /* 0 CATCH 1 */
    necro_caca_001,  /* 1 CATCH 2 */
    necro_caca_002,  /* 2 CATCH 3 */
    necro_caca_003,  /* 3 CATCH 4 */
    necro_caca_004,  /* 4 CATCH 5 */
    necro_caca_005,  /* 5 CATCH 6 */
    necro_caca_006,  /* 6 CATCH 7 */
    necro_caca_007,  /* 7 CATCH 8 */
    necro_caca_008,  /* 8 CATCH 9 */
    necro_caca_009,  /* 9 CATCH 10 */
    necro_caca_010,  /* 10 CATCH 11 */
    necro_caca_011,  /* 11 CATCH 12 */
    0
};

/* script: 0 CATCH 1 */
const u16 necro_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 necro_caca_000[292] = {
    CMD(CM_NGDA, 1542, 9, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20A0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(3, 0, 805, 0, 0, 0, 0, 0x20A1, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20A2, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20A3, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(5, 2, 270, 0, 0, 0, 0, 0x20A4, -34, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x20A5, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(8, 4, 0, 0, 0, 0, 0, 0x20A5, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x20A6, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20A8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 necro_caca_001_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_001[436] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, -35, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20C1, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x20C2, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x20CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 necro_caca_002_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 necro_caca_002[316] = {
    CMD(CM_NGDA, 1542, 21, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20A0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(2, 0, 264, 0, 0, 0, 0, 0x20D0, 0, 0, 0, 0, 0, 0, 0, 4096, 1032, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 4096, 1056, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20D2, 0, 0, 0, 0, 0, 0, 0, 4096, 1080, 0, 0, 0),
    L6(1, 0, 805, 0, 0, 0, 0, 0x20D3, 0, 0, 0, 0, 0, 0, 0, 4096, 1104, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D4, 0, 0, 0, 0, 0, 0, 0, 4096, 1128, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D5, 0, 0, 0, 0, 0, 0, 0, 4096, 1152, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D6, 0, 0, 0, 0, 0, 0, 0, 4096, 1176, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D7, 0, 0, 0, 0, 0, 0, 0, 4096, 1200, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D8, 0, 0, 0, 0, 0, 0, 0, 4096, 1224, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20D9, 0, 0, 0, 0, 0, 0, 0, 4096, 1248, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20DA, 0, 0, 0, 0, 0, 0, 0, 4096, 1272, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 270, 0, 0, 0, 0, 0x20DB, -46, 0, 0, 0, 0, 0, 0, 256, 1296, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x20DC, 0, 0, 0, 0, 0, 0, 0, 256, 1320, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20DD, 0, 1, 0, 0, 0, 0, 0, 256, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20DE, 0, 1, 0, 0, 0, 0, 0, 256, 24, 8, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 necro_caca_003_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_003[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 768, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 792, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 816, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 840, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 864, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 888, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 912, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 936, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 960, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -38, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 necro_caca_004_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_004[400] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x20EF, 0, 318, 0, 0, 0, 21, 0, 0, 24, 194, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20F0, 0, 319, 0, 0, 0, 0, 0, 0, 24, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20F1, 0, 320, 0, 0, 0, 0, 0, 0, 24, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20EF, 0, 318, 0, 0, 0, 21, 0, 0, 24, 194, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F0, 0, 319, 0, 0, 0, 0, 0, 0, 24, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20F1, 0, 320, 0, 0, 0, 0, 0, 0, 24, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20EF, 0, 318, 0, 0, 0, 21, 0, 0, 24, 194, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20F0, 0, 319, 0, 0, 0, 0, 0, 0, 24, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20F1, 0, 320, 0, 0, 0, 0, 0, 0, 24, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 122, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 necro_caca_005_head[4] = { HEAD(6, 0, 57, 0, 0, 0, 0) };
const u16 necro_caca_005[1224] = {
    CMD(CM_NGDA, 0, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 780, 240, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 780, 264, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 780, 288, 0, 0, 0),
    L6(4, 0, 805, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 780, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x20BB, -51, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 0, 1344, 238, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 312, 262, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x20BB, -51, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 0, 1344, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D2, 0, 0, 0, 0, 0, 0, 0, 0, 1368, 240, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D3, 0, 0, 0, 0, 0, 0, 0, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D4, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 242, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D5, 0, 0, 0, 0, 0, 0, 0, 0, 1440, 244, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D6, 0, 0, 0, 0, 0, 0, 0, 0, 1464, 246, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D7, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 248, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D8, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 250, 0, 0),
    L6(3, 0, 818, 0, 0, 0, 0, 0x20D9, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 252, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DA, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 254, 0, 0),
    L6(3, 2, 270, 0, 0, 0, 0, 0x20DB, -50, 0, 0, 0, 0, 0, 0, 0, 1584, 256, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20DC, 0, 0, 0, 0, 0, 0, 0, 0, 1608, 258, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DD, 0, 1, 0, 0, 0, 0, 0, 0, 1632, 260, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DE, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2018, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2017, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2016, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2015, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2014, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2013, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2012, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2012, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0038, 0x0000, 0x0000, 0x0069, 0x0000, 0x001C, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x005A, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x002B, 0x0014, 0x0001, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00F0, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B1,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0108, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0120, 0x0000, 0x0000, 0x0400, 0x3250, 0x0000, 0x20B3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0138, 0x0000, 0x0000, 0x0600, 0x0000, 0x0000, 0x20B4,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0150, 0x0000, 0x0000, 0x0500, 0x0000, 0x0000, 0x20B5,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0168, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B6,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0180, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0198, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x01B0, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x20B8,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x01C8, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x20B9,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x01E0, 0x0000, 0x0000, 0x0100, 0x10E0, 0x0000, 0x20BA,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x01F8, 0x0000, 0x0000, 0x0302, 0x0000, 0x0000, 0x20BB,
    L6(243, 64, 0, 0, 0, 0, 0, 0x0000, 0, 0, 528, 0, 0, 0, 0, 1027, 0, 0, 32, 188),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0228, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D1,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0540, 0x00EE, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0558, 0x00F0, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0570, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D4,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0588, 0x00F2, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D5,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x05A0, 0x00F4, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D6,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x05B8, 0x00F6, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x05D0, 0x00F8, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D8,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x05E8, 0x00FA, 0x0000, 0x0300, 0x3320, 0x0000, 0x20D9,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0600, 0x00FC, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DA,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0618, 0x00FE, 0x0000, 0x0302, 0x10E0, 0x0000, 0x20DB,
    L6(243, 128, 0, 0, 0, 0, 0, 0x0000, 0, 0, 1584, 1, 0, 0, 0, 777, 0, 0, 32, 220),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0648, 0x0102, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DD,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0660, 0x0104, 0x0000, 0x0027, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DE,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2019,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2018,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2017,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2016,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2015,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2014,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2013,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2012,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x2012,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 6 CATCH 7 */
const u16 necro_caca_006_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 necro_caca_006[64] = {
    CMD(CM_NGDA, 1542, 9, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 6, 264, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 necro_caca_007_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 necro_caca_007[52] = {
    CMD(CM_NGDA, 1542, 21, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x20D0, 0, 0, 0, 0, 0, 0, 0, 4096, 1032, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 4096, 1056, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 necro_caca_008_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_008[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 768, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 792, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 816, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 840, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 864, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 888, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 912, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 936, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 960, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -68, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 necro_caca_009_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_009[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 768, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 792, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 816, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 840, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 864, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 888, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 912, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 936, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 960, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -69, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11 */
const u16 necro_caca_010_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_010[184] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, -74, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 CATCH 12 */
const u16 necro_caca_011_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_011[324] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, -75, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0019, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20EF,
    CMD(CM_RJA4, 16384, 0, 5376), 0x0000, 0x0018, 0x00C2, 0x0000, 0x0900, 0x0000, 0x0000, 0x20F0,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0018, 0x00C4, 0x0000, 0x0300, 0x0000, 0x0000, 0x20F1,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0018, 0x00C6, 0x0000, 0x0300, 0x0000, 0x0000, 0x1F3E,
    CMD(CM_NEX2, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1F3F,
    CMD(CM_NEX2, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1F40,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1F41,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1E22,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1E23,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1E24,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1E24,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* caught scripts: 68 entries */
const u16* const necro_cuca[69] = {
    necro_cuca_000,  /* 0 ALEX ZUTUKI */
    necro_cuca_001,  /* 1 ALEX BODY S */
    necro_cuca_002,  /* 2 ALEX BACK D */
    necro_cuca_003,  /* 3 ALEX POWER B */
    necro_cuca_004,  /* 4 ALEX SLEEPER */
    necro_cuca_005,  /* 5 RYU SEOINAGE */
    necro_cuca_006,  /* 6 IBUKI */
    necro_cuca_007,  /* 7 DADLEY L B */
    necro_cuca_008,  /* 8 IBUKI KUBIORI */
    necro_cuca_009,  /* 9 NECRO S T */
    necro_cuca_010,  /* 10 RYU TOMOENAGE */
    necro_cuca_011,  /* 11 YUN HIZAGERI */
    necro_cuca_012,  /* 12 ORO KUBISIME */
    necro_cuca_013,  /* 13 NECRO G S */
    necro_cuca_014,  /* 14 DUDDLEY D S */
    necro_cuca_015,  /* 15 YUN MONKEY F */
    necro_cuca_016,  /* 16 ORO TOMOENAGE */
    necro_cuca_017,  /* 17 ORO NIOURIKI */
    necro_cuca_018,  /* 18 ORO GIGOKU G */
    necro_cuca_019,  /* 19 YUN */
    necro_cuca_020,  /* 20 NECRO SNAKE F */
    necro_cuca_021,  /* 21 NECRO F S */
    necro_cuca_022,  /* 22 IBUKI HARAIG */
    necro_cuca_023,  /* 23 GILL SPLASH M */
    necro_cuca_024,  /* 24 KEN HIZAGERI */
    necro_cuca_025,  /* 25 ORO KISINRIKI */
    necro_cuca_026,  /* 26 SEAN TACKLE */
    necro_cuca_027,  /* 27 ALEX HYPER B */
    necro_cuca_028,  /* 28 NECRO SLAM D */
    necro_cuca_029,  /* 29 ELENA ASINAGE */
    necro_cuca_030,  /* 30 GILL IMPACT C */
    necro_cuca_031,  /* 31 ALEX S H B */
    necro_cuca_032,  /* 32 ALEX F N D */
    necro_cuca_033,  /* 33 no name */
    necro_cuca_034,  /* 34 IBUKI */
    necro_cuca_035,  /* 35 IBUKI YOROI D */
    necro_cuca_036,  /* 36 no name */
    necro_cuca_037,  /* 37 MAWARIKOMI M F */
    necro_cuca_038,  /* 38 HUGO BODY S */
    necro_cuca_039,  /* 39 HUGO N G T */
    necro_cuca_040,  /* 40 HUGO M S P */
    necro_cuca_041,  /* 41 HUGO S D B B */
    necro_cuca_042,  /* 42 no name */
    necro_cuca_043,  /* 43 no name */
    necro_cuca_044,  /* 44 no name */
    necro_cuca_045,  /* 45 no name */
    necro_cuca_046,  /* 46 no name */
    necro_cuca_047,  /* 47 no name */
    necro_cuca_048,  /* 48 no name */
    necro_cuca_049,  /* 49 no name */
    necro_cuca_050,  /* 50 no name */
    necro_cuca_051,  /* 51 no name */
    necro_cuca_052,  /* 52 no name */
    necro_cuca_053,  /* 53 no name */
    necro_cuca_054,  /* 54 no name */
    necro_cuca_055,  /* 55 no name */
    necro_cuca_056,  /* 56 no name */
    necro_cuca_057,  /* 57 no name */
    necro_cuca_058,  /* 58 no name */
    necro_cuca_059,  /* 59 no name */
    necro_cuca_060,  /* 60 no name */
    necro_cuca_061,  /* 61 no name */
    necro_cuca_062,  /* 62 no name */
    necro_cuca_063,  /* 63 no name */
    necro_cuca_064,  /* 64 no name */
    necro_cuca_065,  /* 65 no name */
    necro_cuca_066,  /* 66 no name */
    necro_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 necro_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 necro_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 necro_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 necro_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 necro_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2067),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 necro_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FAE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1EB1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x20C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 necro_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 necro_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2079),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FC3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 necro_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2044),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 necro_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_009[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCD),
    CMD(CM_RMJA, 3, 9, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 necro_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 necro_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD9),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1EE0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 necro_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 necro_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2127),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2128),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 necro_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2066),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE3),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1FE4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 necro_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2064),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 necro_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2069),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 necro_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 10),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 necro_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2019),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2012),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2013),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2014),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2015),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2016),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2017),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2018),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 3, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2035),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 necro_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_019[100] = {
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
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1E01),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 necro_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E38),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 necro_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 necro_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2037),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 necro_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2064),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2070),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 necro_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FDE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 necro_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_025[116] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 necro_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 3, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x21B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 3, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 necro_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x217B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2178),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2070),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 necro_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2127),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2128),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 necro_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207B),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x207C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 necro_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2041),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2044),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F89),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E5C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F6C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2079),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x207A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 32, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 necro_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 necro_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 necro_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 30, 8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 30, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 necro_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2072),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2081),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2081),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2081),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 necro_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 necro_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 2, 0, 0, 0, 0, 0, 0x2081),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 2, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202B),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 necro_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_037[132] = {
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
const u16 necro_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x20C4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x202E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207A),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 necro_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 necro_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2042),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 necro_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2036),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 necro_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE4),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 necro_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 necro_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2042),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 necro_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 necro_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2028),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 necro_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x217B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2178),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 necro_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 necro_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2050),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 necro_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E44),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2081),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207C),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2027),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 necro_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2069),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 2, 0, 0, 0, 0, 0, 0x2079),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2066),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FDD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 necro_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20DC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2050),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2073),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 necro_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2086),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2088),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2089),
    L2(250, 0, 0, 0, 0, 0, 0, 0x208A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x208C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2072),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2005),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2083),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1EE9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 necro_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2081),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FC7),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 32, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 necro_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2086),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2088),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2089),
    L2(250, 0, 0, 0, 0, 0, 0, 0x208A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x208C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2072),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2005),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2083),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1EE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 necro_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 2, 0, 0, 0, 0, 0, 0x1FDE),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 9, 0x206E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 necro_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2078),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x207B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 necro_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 necro_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E66),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E65),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2010),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 necro_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FEA),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 necro_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_061[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F8D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F8D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F8E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F8E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2072),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 necro_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2060),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2061),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2062),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2063),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2064),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2065),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2066),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x209B),
    CMD(CM_PA_X, 0, -2048, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2079),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 116),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203B),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 necro_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 803, 0, 0, 0, 0, 0x1FE3),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 necro_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 necro_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2068),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2069),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2069),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2069),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x20DE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 necro_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206A),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x206B),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 necro_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2076),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2077),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2078),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2082),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 158 entries */
const u16* const necro_atca[159] = {
    necro_atca_000,  /* 0 S PUNCH A */
    necro_atca_000,  /* 1 S PUNCH B */
    necro_atca_002,  /* 2 S PUNCH C */
    necro_atca_003,  /* 3 M PUNCH A */
    necro_atca_003,  /* 4 M PUNCH B */
    necro_atca_005,  /* 5 M PUNCH C */
    necro_atca_006,  /* 6 L PUNCH A */
    necro_atca_006,  /* 7 L PUNCH B */
    necro_atca_008,  /* 8 L PUNCH C */
    necro_atca_009,  /* 9 S KICK A */
    necro_atca_009,  /* 10 S KICK B */
    necro_atca_011,  /* 11 S KICK C */
    necro_atca_012,  /* 12 M KICK A */
    necro_atca_012,  /* 13 M KICK B */
    necro_atca_014,  /* 14 M KICK C */
    necro_atca_015,  /* 15 L KICK A */
    necro_atca_015,  /* 16 L KICK B */
    necro_atca_017,  /* 17 L KICK C */
    necro_atca_018,  /* 18 KAGAMI P A */
    necro_atca_018,  /* 19 KAGAMI P B */
    necro_atca_018,  /* 20 KAGAMI P C */
    necro_atca_021,  /* 21 KAGAMI P A */
    necro_atca_021,  /* 22 KAGAMI P B */
    necro_atca_021,  /* 23 KAGAMI P C */
    necro_atca_024,  /* 24 KAGAMI P A */
    necro_atca_024,  /* 25 KAGAMI P B */
    necro_atca_026,  /* 26 KAGAMI P C */
    necro_atca_027,  /* 27 KAGAMI K A */
    necro_atca_027,  /* 28 KAGAMI K B */
    necro_atca_027,  /* 29 KAGAMI K C */
    necro_atca_030,  /* 30 KAGAMI K A */
    necro_atca_030,  /* 31 KAGAMI K B */
    necro_atca_030,  /* 32 KAGAMI K C */
    necro_atca_033,  /* 33 KAGAMI K A */
    necro_atca_033,  /* 34 KAGAMI K B */
    necro_atca_033,  /* 35 KAGAMI K C */
    necro_atca_036,  /* 36 V JUMP P S A */
    necro_atca_036,  /* 37 V JUMP P S B */
    necro_atca_038,  /* 38 V JUMP P M A */
    necro_atca_038,  /* 39 V JUMP P M B */
    necro_atca_040,  /* 40 V JUMP P L A */
    necro_atca_040,  /* 41 V JUMP P L B */
    necro_atca_042,  /* 42 V JUMP K S A */
    necro_atca_043,  /* 43 V JUMP K S B */
    necro_atca_044,  /* 44 V JUMP K M A */
    necro_atca_044,  /* 45 V JUMP K M B */
    necro_atca_046,  /* 46 V JUMP K L A */
    necro_atca_046,  /* 47 V JUMP K L B */
    necro_atca_048,  /* 48 F JUMP P S A */
    necro_atca_048,  /* 49 F JUMP P S B */
    necro_atca_050,  /* 50 F JUMP P M A */
    necro_atca_050,  /* 51 F JUMP P M B */
    necro_atca_052,  /* 52 F JUMP P L A */
    necro_atca_052,  /* 53 F JUMP P L B */
    necro_atca_054,  /* 54 F JUMP K S A */
    necro_atca_055,  /* 55 F JUMP K S B */
    necro_atca_056,  /* 56 F JUMP K M A */
    necro_atca_056,  /* 57 F JUMP K M B */
    necro_atca_058,  /* 58 F JUMP K L A */
    necro_atca_058,  /* 59 F JUMP K L B */
    necro_atca_060,  /* 60 B JUMP P S A */
    necro_atca_060,  /* 61 B JUMP P S B */
    necro_atca_062,  /* 62 B JUMP P M A */
    necro_atca_062,  /* 63 B JUMP P M B */
    necro_atca_064,  /* 64 B JUMP P L A */
    necro_atca_064,  /* 65 B JUMP P L B */
    necro_atca_066,  /* 66 B JUMP K S A */
    necro_atca_067,  /* 67 B JUMP K S B */
    necro_atca_068,  /* 68 B JUMP K M A */
    necro_atca_068,  /* 69 B JUMP K M B */
    necro_atca_070,  /* 70 B JUMP K L A */
    necro_atca_070,  /* 71 B JUMP K L B */
    necro_atca_072,  /* 72 SP V JP S P A */
    necro_atca_072,  /* 73 SP V JP S P B */
    necro_atca_074,  /* 74 SP V JP M P A */
    necro_atca_074,  /* 75 SP V JP M P B */
    necro_atca_076,  /* 76 SP V JP L P A */
    necro_atca_076,  /* 77 SP V JP L P B */
    necro_atca_078,  /* 78 SP V JP S K A */
    necro_atca_079,  /* 79 SP V JP S K B */
    necro_atca_080,  /* 80 SP V JP M K A */
    necro_atca_080,  /* 81 SP V JP M K B */
    necro_atca_082,  /* 82 SP V JP L K A */
    necro_atca_082,  /* 83 SP V JP L K B */
    necro_atca_084,  /* 84 SP F JP S P A */
    necro_atca_084,  /* 85 SP F JP S P B */
    necro_atca_086,  /* 86 SP F JP M P A */
    necro_atca_086,  /* 87 SP F JP M P B */
    necro_atca_088,  /* 88 SP F JP L P A */
    necro_atca_088,  /* 89 SP F JP L P B */
    necro_atca_090,  /* 90 SP F JP S K A */
    necro_atca_091,  /* 91 SP F JP S K B */
    necro_atca_092,  /* 92 SP F JP M K A */
    necro_atca_092,  /* 93 SP F JP M K B */
    necro_atca_094,  /* 94 SP F JP L K A */
    necro_atca_094,  /* 95 SP F JP L K B */
    necro_atca_096,  /* 96 SP B JP S P A */
    necro_atca_096,  /* 97 SP B JP S P B */
    necro_atca_098,  /* 98 SP B JP M P A */
    necro_atca_098,  /* 99 SP B JP M P B */
    necro_atca_100,  /* 100 SP B JP L P A */
    necro_atca_100,  /* 101 SP B JP L P B */
    necro_atca_102,  /* 102 SP B JP S K A */
    necro_atca_103,  /* 103 SP B JP S K B */
    necro_atca_104,  /* 104 SP B JP M K A */
    necro_atca_104,  /* 105 SP B JP M K B */
    necro_atca_106,  /* 106 SP B JP L K A */
    necro_atca_106,  /* 107 SP B JP L K B */
    necro_atca_108,  /* 108 S V JP S P A */
    necro_atca_108,  /* 109 S V JP S P B */
    necro_atca_110,  /* 110 S V JP M P A */
    necro_atca_110,  /* 111 S V JP M P B */
    necro_atca_112,  /* 112 S V JP L P A */
    necro_atca_112,  /* 113 S V JP L P B */
    necro_atca_114,  /* 114 S V JP S K A */
    necro_atca_114,  /* 115 S V JP S K B */
    necro_atca_116,  /* 116 S V JP M K A */
    necro_atca_116,  /* 117 S V JP M K B */
    necro_atca_118,  /* 118 S V JP L K A */
    necro_atca_118,  /* 119 S V JP L K B */
    necro_atca_108,  /* 120 S F JP S P A */
    necro_atca_108,  /* 121 S F JP S P B */
    necro_atca_110,  /* 122 S F JP M P A */
    necro_atca_110,  /* 123 S F JP M P B */
    necro_atca_112,  /* 124 S F JP L P A */
    necro_atca_112,  /* 125 S F JP L P B */
    necro_atca_114,  /* 126 S F JP S K A */
    necro_atca_114,  /* 127 S F JP S K B */
    necro_atca_116,  /* 128 S F JP M K A */
    necro_atca_116,  /* 129 S F JP M K B */
    necro_atca_118,  /* 130 S F JP L K A */
    necro_atca_118,  /* 131 S F JP L K B */
    necro_atca_108,  /* 132 S B JP S P A */
    necro_atca_108,  /* 133 S B JP S P B */
    necro_atca_110,  /* 134 S B JP M P A */
    necro_atca_110,  /* 135 S B JP M P B */
    necro_atca_112,  /* 136 S B JP L P A */
    necro_atca_112,  /* 137 S B JP L P B */
    necro_atca_114,  /* 138 S B JP S K A */
    necro_atca_114,  /* 139 S B JP S K B */
    necro_atca_116,  /* 140 S B JP M K A */
    necro_atca_116,  /* 141 S B JP M K B */
    necro_atca_118,  /* 142 S B JP L K A */
    necro_atca_118,  /* 143 S B JP L K B */
    necro_atca_144,  /* 144 TUKAMIKAKARI A */
    necro_atca_144,  /* 145 TUKAMIKAKARI B */
    necro_atca_146,  /* 146 TUKAMIKAKARI C */
    necro_atca_144,  /* 147 TUKAMIKAKARI D */
    necro_atca_144,  /* 148 TUKAMIKAKARI E */
    necro_atca_144,  /* 149 TUKAMIKAKARI F */
    necro_atca_144,  /* 150 TUKAMI AIR A */
    necro_atca_144,  /* 151 TUKAMI AIR B */
    necro_atca_144,  /* 152 TUKAMI AIR C */
    necro_atca_144,  /* 153 TUKAMI AIR D */
    necro_atca_144,  /* 154 TUKAMI AIR E */
    necro_atca_144,  /* 155 TUKAMI AIR F */
    necro_atca_156,  /* 156 follow-up of S KICK C */
    necro_atca_157,  /* 157 follow-up of follow-up of S KICK C */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B */
const u16 necro_atca_000_head[4] = { HEAD(6, 0, 0, 16, 0, 1, 0) };
const u16 necro_atca_000[172] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E80, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x1E81, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E82, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E82, -2, 17, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E83, 0, 18, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E84, 0, 131, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 S PUNCH C */
const u16 necro_atca_002_head[4] = { HEAD(6, 0, 0, 11, 0, 1, 0) };
const u16 necro_atca_002[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA7, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x1EA8, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAA, -1, 13, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 14, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAB, 0, 15, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAC, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1EAD, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAE, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAF, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB1, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 necro_atca_003_head[4] = { HEAD(6, 0, 2, 14, 0, 1, 0) };
const u16 necro_atca_003[208] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E89, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8A, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 32, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8C, 0, 165, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, -3, 20, 0, 0, 64, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8D, 0, 165, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 necro_atca_005_head[4] = { HEAD(6, 0, 2, 13, 0, 1, 0) };
const u16 necro_atca_005[220] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA7, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA8, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1EA8, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA9, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA9, -54, 127, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 128, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAB, 0, 129, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAC, 3, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAD, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1EAE, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAF, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB0, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB1, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B */
const u16 necro_atca_006_head[4] = { HEAD(6, 0, 4, 27, 0, 1, 0) };
const u16 necro_atca_006[268] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E96, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E97, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 809, 0, 0, 0, 0, 0x1E98, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E99, 0, 30, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9A, 0, 31, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9B, 0, 32, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9C, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1E9D, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9E, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9E, -5, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E9F, 0, 35, 0, 0, 0, 21, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EA1, 0, 222, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EA2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EA3, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1EA4, 0, 32, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 necro_atca_008_head[4] = { HEAD(6, 0, 4, 8, 0, 1, 0) };
const u16 necro_atca_008[304] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB2, 0, 22, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB3, 0, 22, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB4, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB5, 0, 23, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 806, 0, 0, 0, 0, 0x1EB6, 0, 24, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1EB7, 0, 25, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB8, 0, 25, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB8, -4, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB9, 0, 186, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EBA, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1EBA, 0, 156, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBB, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBC, 0, 27, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBD, 0, 28, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1EBE, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EBF, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1ECF, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC1, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC2, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B */
const u16 necro_atca_009_head[4] = { HEAD(4, 0, 1, 12, 0, 1, 0) };
const u16 necro_atca_009[108] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED2, 0, 38, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1ED3, 0, 38, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED4, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED4, -7, 39, 0, 135, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ED5, 0, 40, 0, 0, 96, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ED6, 0, 38, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 S KICK C */
const u16 necro_atca_011_head[4] = { HEAD(4, 0, 1, 10, 0, 1, 0) };
const u16 necro_atca_011[108] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x21C1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C2, -6, 36, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C3, 0, 37, 2213, 0, 104, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21C4, 0, 1, 2213, 0, 120, 0, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C5, 0, 1, 0, 0, 16, 0, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21C6, 0, 1, 0, 0, 16, 0, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x21C7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 necro_atca_012_head[4] = { HEAD(6, 0, 3, 17, 0, 1, 0) };
const u16 necro_atca_012[148] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x1ED7, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ED8, 0, 187, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x1ED9, 0, 187, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDA, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EDA, -9, 44, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EDB, 0, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EDC, 0, 45, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDD, 0, 45, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 necro_atca_014_head[4] = { HEAD(6, 0, 3, 10, 0, 1, 0) };
const u16 necro_atca_014[172] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1EFB, 0, 41, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFC, 0, 43, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EFC, -8, 42, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EFD, 0, 43, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFE, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EFF, 0, 41, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F00, 0, 41, 0, 0, 96, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F01, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 necro_atca_015_head[4] = { HEAD(6, 0, 5, 23, 0, 1, 0) };
const u16 necro_atca_015[316] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EE1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EE2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EE3, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EE4, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(2, 0, 806, 0, 0, 0, 0, 0x1EE5, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE6, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE7, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE8, 0, 51, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1EE9, 0, 52, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2277, 0, 223, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2278, -11, 53, 0, 128, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2278, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2279, 0, 224, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x227A, 0, 55, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EED, 0, 225, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EEE, 0, 225, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EEF, 0, 225, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x227B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x227C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 necro_atca_017_head[4] = { HEAD(6, 0, 5, 10, 0, 1, 0) };
const u16 necro_atca_017[244] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F03, 0, 1, 0, 0, 0, 21, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F04, 0, 46, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F05, 0, 46, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 804, 0, 0, 0, 0, 0x1F06, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F07, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0A, 0, 47, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1F0B, 0, 47, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0C, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F0C, -10, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1F0C, 0, 49, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1F0E, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0F, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F11, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F12, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F13, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 necro_atca_018_head[4] = { HEAD(4, 32, 0, 15, 0, 1, 0) };
const u16 necro_atca_018[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F18, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F19, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F1A, 0, 58, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1A, -12, 57, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1B, 0, 58, 0, 0, 64, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1C, 0, 132, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1D, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 necro_atca_021_head[4] = { HEAD(4, 32, 2, 15, 0, 1, 0) };
const u16 necro_atca_021[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F21, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F22, 0, 311, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F23, 0, 311, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F24, 0, 311, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1F25, 0, 312, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F26, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F27, -13, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F27, 0, 60, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F28, 0, 313, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F29, 0, 313, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2A, 0, 313, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2B, 0, 313, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2C, 0, 312, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2D, 0, 311, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2E, 0, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1F30, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B */
const u16 necro_atca_024_head[4] = { HEAD(4, 32, 4, 27, 0, 1, 0) };
const u16 necro_atca_024[140] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2290, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2291, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2292, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2293, 0, 314, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x2294, 0, 201, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2294, -14, 200, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2295, 0, 201, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2296, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2297, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2298, 0, 203, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2299, 0, 315, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x229A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x229B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 KAGAMI P C */
const u16 necro_atca_026_head[4] = { HEAD(4, 32, 4, 16, 0, 1, 0) };
const u16 necro_atca_026[180] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 62, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 62, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F34, 0, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F35, 0, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F36, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x1F37, 0, 65, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F38, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F38, -90, 66, 0, 138, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1F39, 0, 67, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3A, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3B, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3C, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3D, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 necro_atca_027_head[4] = { HEAD(4, 32, 1, 14, 0, 1, 0) };
const u16 necro_atca_027[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F42, 0, 2, 0, 0, 96, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F43, 0, 2, 0, 0, 96, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 268, 0, 0, 0, 0, 0x1F43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F44, 0, 70, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F44, -15, 69, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F45, 0, 70, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F46, 0, 133, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F47, 0, 2, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F48, 0, 2, 0, 0, 112, 0, 4),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1F49, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F4A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 necro_atca_030_head[4] = { HEAD(6, 32, 3, 23, 0, 1, 0) };
const u16 necro_atca_030[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x21C8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21C9, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x21CA, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x21CB, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21CD, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x21CD, -53, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x21CD, 0, 135, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x21CE, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x21CF, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x21D0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21D1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21D3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E25, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 necro_atca_033_head[4] = { HEAD(4, 32, 5, 21, 0, 1, 0) };
const u16 necro_atca_033[204] = {
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4B, 0, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4C, 0, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4D, 0, 72, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4E, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x1F4F, 0, 73, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x1F50, 0, 74, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F51, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F52, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 1, 0, 0, 0, 0x1F53, 0, 77, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x1F54, 0, 78, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F55, -17, 79, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F56, 0, 80, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F57, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F58, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F59, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5B, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5C, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 necro_atca_036_head[4] = { HEAD(4, 22, 0, 17, 0, 1, 0) };
const u16 necro_atca_036[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F66, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 5, 0x1F67, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F68, 0, 91, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 5, 0x1F69, -19, 92, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x1F6A, 0, 198, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 5, 0x1F6B, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x1F6C, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F6D, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 necro_atca_038_head[4] = { HEAD(4, 22, 2, 22, 0, 1, 0) };
const u16 necro_atca_038[116] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x227D, 0, 88, 0, 0, 0, 0, 0),
    L4(4, 0, 268, 0, 0, 0, 6, 0x227E, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x227F, 0, 89, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x227F, -20, 90, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x2280, 0, 89, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2280, 0, 89, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 6, 0x2281, 0, 196, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x2282, 0, 197, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x2283, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x2284, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x2285, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x2285, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 necro_atca_040_head[4] = { HEAD(4, 22, 4, 18, 0, 1, 0) };
const u16 necro_atca_040[212] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F6F, 0, 88, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F70, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 809, 0, 0, 0, 5, 0x1F71, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 5, 0x1F8A, 0, 100, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F72, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, -21, 93, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F72, 0, 94, 0, 149, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 151, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 5, 0x1F75, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1ECA, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1ECB, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1ECC, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F76, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 17), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 40, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A */
const u16 necro_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 necro_atca_042[68] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F77, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F78, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F79, -22, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F7A, 0, 96, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 5, 0x1F7B, 0, 96, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1F7C, 0, 88, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 V JUMP K S B */
const u16 necro_atca_043_head[4] = { HEAD(4, 20, 1, 12, 0, 3, 42) };
const u16 necro_atca_043[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 809, 0, 0, 0, 10, 0x21F0, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 10, 0x21F1, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x21F2, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x21F3, -79, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 184, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, -80, 184, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, -80, 184, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, 0, 185, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 necro_atca_044_head[4] = { HEAD(4, 22, 3, 19, 0, 1, 0) };
const u16 necro_atca_044[156] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x21E4, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x21E5, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21E6, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21E7, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x21E8, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21E9, -23, 180, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x21E9, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21EA, 0, 182, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21EB, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21EC, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21ED, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21EE, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21EF, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 necro_atca_046_head[4] = { HEAD(4, 22, 5, 18, 0, 1, 0) };
const u16 necro_atca_046[188] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F8C, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F8D, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F8E, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F8F, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F90, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 806, 0, 0, 0, 0, 0x1F91, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F92, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F93, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F94, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F95, 0, 97, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 5, 0x1F96, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F97, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F97, -24, 98, 0, 143, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F98, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F99, 0, 138, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F9A, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F9B, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F9C, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F9D, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 necro_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 necro_atca_048[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F60, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F61, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F62, -25, 101, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x1F63, 0, 101, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1F64, 0, 102, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1F65, 0, 95, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 necro_atca_050_head[4] = { HEAD(4, 20, 2, 21, 0, 1, 0) };
const u16 necro_atca_050[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2286, 0, 95, 0, 0, 0, 0, 0),
    L4(5, 0, 269, 0, 0, 0, 5, 0x2287, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x2288, 0, 109, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x2289, -26, 103, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 5, 0x2289, 0, 109, 0, 0, 0, 21, 0),
    L4(8, 0, 0, 0, 0, 0, 5, 0x228A, 0, 104, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x228B, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x228C, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x228D, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 necro_atca_052_head[4] = { HEAD(4, 20, 4, 19, 0, 1, 0) };
const u16 necro_atca_052[204] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F6F, 0, 88, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F70, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 809, 0, 0, 0, 5, 0x1F71, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 5, 0x1F8A, 0, 100, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F72, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, -21, 93, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F72, 0, 94, 0, 149, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 151, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 5, 0x1F75, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1ECA, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1ECB, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1F76, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 17), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 52, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A */
const u16 necro_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 necro_atca_054[68] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F77, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F78, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F79, -22, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1F7A, 22, 96, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 5, 0x1F7B, 22, 96, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x1F7C, 0, 88, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 F JUMP K S B */
const u16 necro_atca_055_head[4] = { HEAD(2, 20, 1, 12, 0, 3, 42) };
const u16 necro_atca_055[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 necro_atca_056_head[4] = { HEAD(4, 20, 3, 9, 0, 3, 42) };
const u16 necro_atca_056[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 809, 0, 0, 0, 0, 0x1F7D, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1F7E, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F7F, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F80, -27, 106, 0, 81, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, 0, 106, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 106, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 107, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 107, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 106, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, -28, 106, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, -28, 107, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 108, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, 0, 108, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 108, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 necro_atca_058_head[4] = { HEAD(4, 20, 5, 9, 0, 3, 42) };
const u16 necro_atca_058[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 809, 0, 0, 0, 3, 0x21FD, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 3, 0x21FE, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 3, 0x21FF, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 3, 0x2200, -29, 110, 0, 81, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 111, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, -30, 111, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, -30, 111, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 1, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, 0, 112, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 necro_atca_060_head[4] = { HEAD(2, 24, 0, 10, 0, 1, 0) };
const u16 necro_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 necro_atca_062_head[4] = { HEAD(2, 24, 2, 20, 0, 1, 0) };
const u16 necro_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 necro_atca_064_head[4] = { HEAD(2, 24, 4, 18, 0, 1, 0) };
const u16 necro_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A */
const u16 necro_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 necro_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 B JUMP K S B */
const u16 necro_atca_067_head[4] = { HEAD(2, 24, 1, 12, 0, 3, 42) };
const u16 necro_atca_067[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 necro_atca_068_head[4] = { HEAD(2, 24, 3, 8, 0, 3, 42) };
const u16 necro_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 necro_atca_070_head[4] = { HEAD(2, 24, 5, 8, 0, 3, 42) };
const u16 necro_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 necro_atca_072_head[4] = { HEAD(2, 28, 0, 17, 0, 1, 0) };
const u16 necro_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 necro_atca_074_head[4] = { HEAD(2, 28, 2, 22, 0, 1, 0) };
const u16 necro_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 necro_atca_076_head[4] = { HEAD(2, 28, 4, 18, 0, 1, 0) };
const u16 necro_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A */
const u16 necro_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 necro_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 SP V JP S K B */
const u16 necro_atca_079_head[4] = { HEAD(2, 28, 1, 12, 0, 3, 42) };
const u16 necro_atca_079[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 necro_atca_080_head[4] = { HEAD(2, 28, 3, 19, 0, 1, 0) };
const u16 necro_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 necro_atca_082_head[4] = { HEAD(2, 28, 5, 18, 0, 1, 0) };
const u16 necro_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 necro_atca_084_head[4] = { HEAD(2, 26, 0, 11, 0, 1, 0) };
const u16 necro_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 necro_atca_086_head[4] = { HEAD(2, 26, 2, 21, 0, 1, 0) };
const u16 necro_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 necro_atca_088_head[4] = { HEAD(2, 26, 4, 19, 0, 1, 0) };
const u16 necro_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A */
const u16 necro_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 necro_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 SP F JP S K B */
const u16 necro_atca_091_head[4] = { HEAD(2, 26, 1, 12, 0, 3, 42) };
const u16 necro_atca_091[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 necro_atca_092_head[4] = { HEAD(2, 26, 3, 9, 0, 3, 42) };
const u16 necro_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 necro_atca_094_head[4] = { HEAD(2, 26, 5, 9, 0, 3, 42) };
const u16 necro_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 necro_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 necro_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 necro_atca_098_head[4] = { HEAD(2, 30, 2, 20, 0, 1, 0) };
const u16 necro_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 necro_atca_100_head[4] = { HEAD(2, 30, 4, 18, 0, 1, 0) };
const u16 necro_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A */
const u16 necro_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 necro_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 103 SP B JP S K B */
const u16 necro_atca_103_head[4] = { HEAD(2, 30, 1, 12, 0, 3, 42) };
const u16 necro_atca_103[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 necro_atca_104_head[4] = { HEAD(2, 30, 3, 8, 0, 3, 42) };
const u16 necro_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 necro_atca_106_head[4] = { HEAD(2, 30, 5, 8, 0, 3, 42) };
const u16 necro_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 necro_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 necro_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 necro_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 necro_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 necro_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 necro_atca_112[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 necro_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 necro_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 necro_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 necro_atca_116[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 necro_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 necro_atca_118[152] = {
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

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 necro_atca_144_head[4] = { HEAD(4, 0, 16, 0, 0, 0, 0) };
const u16 necro_atca_144[140] = {
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x22A0, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x22A0, -33, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x22A1, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x22A2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x22A3, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2099, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x209A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 necro_atca_146_head[4] = { HEAD(2, 0, 18, 0, 0, 0, 0) };
const u16 necro_atca_146[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of S KICK C */
const u16 necro_atca_156_head[4] = { HEAD(6, 0, 2, 14, 0, 1, 0) };
const u16 necro_atca_156[232] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E89, 0, 1, 0, 0, 96, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8A, 0, 19, 0, 0, 96, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8C, 0, 165, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, -76, 20, 0, 0, 64, 0, 0, 0, 0, 30, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, 0, 165, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, 0, 165, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of follow-up of S KICK C */
const u16 necro_atca_157_head[4] = { HEAD(6, 0, 4, 20, 0, 1, 0) };
const u16 necro_atca_157[220] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9A, 0, 31, 0, 0, 96, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9B, 0, 32, 0, 0, 96, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9C, 0, 30, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1E9D, 0, 30, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9E, 0, 35, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E9E, -77, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9F, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 21, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA3, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1EA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX necro_olc_ix_table[10] = {
    { { 0, 0, 0, 0 } },
    { { 0, 1, 0, 0 } },
    { { 0, 13, 0, 0 } },
    { { 0, 0, 21, 0 } },
    { { 0, 0, 33, 0 } },
    { { 41, 0, 0, 0 } },
    { { 42, 0, 0, 0 } },
    { { 43, 0, 0, 0 } },
    { { 44, 0, 0, 0 } },
    { { 45, 0, 0, 0 } },
};

const OVERLAP_PARTS necro_overlap_char_tbl[46] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8544 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8545 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8546 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8547 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8548 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8549 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8550 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8551 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8552 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8553 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8554 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 1, 8555 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8575 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8576 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8577 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8578 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8579 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8580 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8581 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 0 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8556 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8557 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8558 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8559 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8560 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8561 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8562 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8563 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8564 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8565 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8566 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 21, 8567 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8582 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8583 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8584 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8585 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8586 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8587 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8588 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 40, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 41, 8608 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 42, 8609 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 8610 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 8611 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 8612 },
};

const CatchTable necro_rival_catch_tbl[1632] = {
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -74, 0, 1, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 1 },
    { -75, 0, 1, 1, 1 },
    { -84, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -75, 0, 1, 1, 1 },
    { -85, 0, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 3 },
    { -76, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -68, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -85, 0, 1, 1, 2 },
    { -75, 0, 1, 1, 2 },
    { -73, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -66, 0, 1, 1, 3 },
    { -70, 0, 1, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -89, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -81, 0, 1, 1, 3 },
    { -85, 0, 1, 1, 3 },
    { -71, 0, 1, 1, 3 },
    { -74, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 5 },
    { -62, 0, 1, 1, 5 },
    { -82, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { -78, 0, 1, 1, 4 },
    { -88, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -81, 0, 1, 1, 4 },
    { -81, 0, 1, 1, 4 },
    { -78, 0, 1, 1, 4 },
    { -73, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -60, 0, 1, 1, 5 },
    { -62, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -51, 0, 1, 1, 6 },
    { -56, 0, 1, 1, 6 },
    { -82, 0, 1, 1, 5 },
    { -55, 0, 1, 1, 5 },
    { -74, 0, 1, 1, 5 },
    { -77, 0, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -60, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -81, 0, 1, 1, 5 },
    { -76, 0, 1, 1, 5 },
    { -79, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { -72, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -62, 0, 1, 1, 6 },
    { -60, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -48, 0, 1, 1, 6 },
    { -46, 0, 1, 1, 7 },
    { -54, 0, 1, 1, 7 },
    { -82, 0, 1, 1, 6 },
    { -57, 0, 1, 1, 6 },
    { -72, 0, 1, 1, 6 },
    { -76, 0, 1, 1, 6 },
    { -48, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -62, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -78, 0, 1, 1, 6 },
    { -72, 0, 1, 1, 6 },
    { -78, 0, 1, 1, 6 },
    { -71, 0, 1, 1, 6 },
    { -72, 0, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -72, 0, 1, 1, 7 },
    { -72, 0, 1, 1, 7 },
    { -80, 0, 1, 1, 7 },
    { -75, 0, 1, 1, 7 },
    { -86, 0, 1, 1, 8 },
    { -94, 0, 1, 1, 8 },
    { -104, 0, 1, 1, 7 },
    { -86, 0, 1, 1, 7 },
    { -82, 0, 1, 1, 7 },
    { -86, 0, 1, 1, 7 },
    { -75, 0, 1, 1, 7 },
    { -80, 0, 1, 1, 7 },
    { -80, 0, 1, 1, 7 },
    { -72, 0, 1, 1, 7 },
    { -80, 0, 1, 1, 7 },
    { -80, 0, 1, 1, 7 },
    { -85, 0, 1, 1, 7 },
    { -81, 0, 1, 1, 7 },
    { -96, 0, 1, 1, 7 },
    { -102, 0, 1, 1, 7 },
    { -96, 0, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 8 },
    { -64, 0, 1, 1, 8 },
    { -80, 0, 1, 1, 8 },
    { -75, 0, 1, 1, 8 },
    { -86, 0, 1, 1, 9 },
    { -88, 0, 1, 1, 9 },
    { -104, 0, 1, 1, 8 },
    { -86, 0, 1, 1, 8 },
    { -86, 0, 1, 1, 8 },
    { -83, 0, 1, 1, 8 },
    { -75, 0, 1, 1, 8 },
    { -80, 0, 1, 1, 8 },
    { -80, 0, 1, 1, 8 },
    { -68, 0, 1, 1, 8 },
    { -80, 0, 1, 1, 8 },
    { -80, 0, 1, 1, 8 },
    { -85, 0, 1, 1, 8 },
    { -81, 0, 1, 1, 8 },
    { -96, 0, 1, 1, 8 },
    { -106, 0, 1, 1, 8 },
    { -106, 0, 1, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 10 },
    { -112, 0, 1, 1, 10 },
    { -137, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -86, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -112, 0, 1, 1, 9 },
    { -114, 0, 1, 1, 9 },
    { -104, 0, 1, 1, 9 },
    { -128, 0, 1, 1, 9 },
    { -80, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -94, -3, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -106, 0, 1, 1, 1 },
    { -69, 0, 1, 1, 1 },
    { -94, 0, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -85, 1, 1, 1, 1 },
    { -110, 0, 1, 1, 1 },
    { -100, 0, 1, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -129, 0, 1, 1, 1 },
    { -92, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -85, 0, 1, 1, 2 },
    { -84, -1, 1, 1, 2 },
    { -84, 2, 1, 1, 2 },
    { -94, 0, 1, 1, 2 },
    { -98, -3, 1, 1, 2 },
    { -96, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -95, -1, 1, 1, 2 },
    { -94, 0, 1, 1, 2 },
    { -69, 0, 1, 1, 2 },
    { -94, 0, 1, 1, 2 },
    { -84, 2, 1, 1, 2 },
    { -84, 2, 1, 1, 2 },
    { -85, 0, 1, 1, 2 },
    { -84, 2, 1, 1, 2 },
    { -84, 2, 1, 1, 2 },
    { -108, 0, 1, 1, 2 },
    { -100, 0, 1, 1, 2 },
    { -96, 0, 1, 1, 2 },
    { -129, 0, 1, 1, 2 },
    { -92, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -90, 0, 1, 1, 3 },
    { -90, 0, 1, 1, 3 },
    { -84, 1, 1, 1, 3 },
    { -94, 0, 1, 1, 3 },
    { -100, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -79, 0, 1, 1, 3 },
    { -91, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -69, 0, 1, 1, 3 },
    { -94, 0, 1, 1, 3 },
    { -84, 1, 1, 1, 3 },
    { -84, 1, 1, 1, 3 },
    { -90, 0, 1, 1, 3 },
    { -84, 1, 1, 1, 3 },
    { -84, 1, 1, 1, 3 },
    { -103, 0, 1, 1, 3 },
    { -85, 0, 1, 1, 3 },
    { -96, 0, 1, 1, 3 },
    { -129, 0, 1, 1, 3 },
    { -88, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -83, 0, 1, 1, 4 },
    { -90, 0, 1, 1, 4 },
    { -84, 2, 1, 1, 4 },
    { -94, -1, 1, 1, 4 },
    { -99, -1, 1, 1, 4 },
    { -96, 0, 1, 1, 4 },
    { -79, 0, 1, 1, 4 },
    { -90, 0, 1, 1, 4 },
    { -102, 0, 1, 1, 4 },
    { -71, -2, 1, 1, 4 },
    { -94, -1, 1, 1, 4 },
    { -84, 2, 1, 1, 4 },
    { -84, 2, 1, 1, 4 },
    { -83, 0, 1, 1, 4 },
    { -84, 2, 1, 1, 4 },
    { -84, 2, 1, 1, 4 },
    { -99, 0, 1, 1, 4 },
    { -93, 0, 1, 1, 4 },
    { -96, 0, 1, 1, 4 },
    { -129, 0, 1, 1, 4 },
    { -88, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -83, 0, 1, 1, 5 },
    { -90, 0, 1, 1, 5 },
    { -84, 2, 1, 1, 5 },
    { -94, -2, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -96, 0, 1, 1, 5 },
    { -80, 0, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -102, 0, 1, 1, 5 },
    { -71, -2, 1, 1, 5 },
    { -94, -2, 1, 1, 5 },
    { -84, 2, 1, 1, 5 },
    { -84, 2, 1, 1, 5 },
    { -83, 0, 1, 1, 5 },
    { -84, 2, 1, 1, 5 },
    { -84, 2, 1, 1, 5 },
    { -104, 0, 1, 1, 5 },
    { -93, 0, 1, 1, 5 },
    { -96, 0, 1, 1, 5 },
    { -129, 0, 1, 1, 5 },
    { -88, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -83, 0, 1, 1, 6 },
    { -90, 0, 1, 1, 6 },
    { -83, 2, 1, 1, 6 },
    { -94, -7, 1, 1, 6 },
    { -90, -1, 1, 1, 6 },
    { -96, 0, 1, 1, 6 },
    { -86, 2, 1, 1, 6 },
    { -89, 1, 1, 1, 6 },
    { -96, 2, 1, 1, 6 },
    { -115, 4, 1, 1, 6 },
    { -94, -7, 1, 1, 6 },
    { -83, 2, 1, 1, 6 },
    { -83, 2, 1, 1, 6 },
    { -83, 0, 1, 1, 6 },
    { -83, 2, 1, 1, 6 },
    { -83, 2, 1, 1, 6 },
    { -109, 0, 1, 1, 6 },
    { -91, 0, 1, 1, 6 },
    { -96, 0, 1, 1, 6 },
    { -129, 0, 1, 1, 6 },
    { -88, 0, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -83, 0, 1, 1, 7 },
    { -44, -6, 1, 1, 7 },
    { -61, 28, 1, 1, 7 },
    { -69, 29, 1, 1, 7 },
    { -81, 16, 1, 1, 7 },
    { -92, 17, 1, 1, 7 },
    { -79, -1, 1, 1, 7 },
    { -78, 36, 1, 1, 7 },
    { -78, 26, 1, 1, 7 },
    { -69, 39, 1, 1, 7 },
    { -69, 29, 1, 1, 7 },
    { -61, 28, 1, 1, 7 },
    { -61, 28, 1, 1, 7 },
    { -83, 0, 1, 1, 7 },
    { -61, 28, 1, 1, 7 },
    { -61, 28, 1, 1, 7 },
    { -88, 22, 1, 1, 7 },
    { -70, 20, 1, 1, 7 },
    { -90, 2, 1, 1, 7 },
    { -78, 21, 1, 1, 7 },
    { -66, 10, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -18, 63, 1, 1, 8 },
    { -31, 65, 1, 1, 8 },
    { -19, 74, 1, 1, 8 },
    { -24, 82, 1, 1, 8 },
    { -18, 66, 1, 1, 8 },
    { -18, 55, 1, 1, 8 },
    { -20, 72, 1, 1, 8 },
    { -34, 57, 1, 1, 8 },
    { -42, 106, 1, 1, 8 },
    { -7, 84, 1, 1, 8 },
    { -24, 82, 1, 1, 8 },
    { -19, 74, 1, 1, 8 },
    { -19, 74, 1, 1, 8 },
    { -18, 63, 1, 1, 8 },
    { -19, 74, 1, 1, 8 },
    { -19, 74, 1, 1, 8 },
    { -8, 78, 1, 1, 8 },
    { -21, 78, 1, 1, 8 },
    { -21, 79, 1, 1, 8 },
    { -44, 76, 1, 1, 8 },
    { -18, 72, 1, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -11, 60, 1, 1, 9 },
    { -13, 80, 1, 1, 9 },
    { -17, 75, 1, 1, 9 },
    { -11, 85, 1, 1, 9 },
    { -18, 62, 1, 1, 9 },
    { -16, 64, 1, 1, 9 },
    { -12, 69, 1, 1, 9 },
    { -31, 63, 1, 1, 9 },
    { -32, 122, 1, 1, 9 },
    { 0, 84, 1, 1, 9 },
    { -11, 85, 1, 1, 9 },
    { -17, 75, 1, 1, 9 },
    { -17, 75, 1, 1, 9 },
    { -11, 60, 1, 1, 9 },
    { -17, 75, 1, 1, 9 },
    { -17, 75, 1, 1, 9 },
    { -31, 74, 1, 1, 9 },
    { -14, 77, 1, 1, 9 },
    { -6, 91, 1, 1, 9 },
    { -46, 75, 1, 1, 9 },
    { -18, 72, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 43, 64, 1, 1, 10 },
    { 42, 103, 1, 1, 10 },
    { 33, 88, 1, 1, 10 },
    { 24, 102, 1, 1, 10 },
    { 33, 80, 1, 1, 10 },
    { 46, 108, 1, 1, 10 },
    { 43, 61, 1, 1, 10 },
    { 24, 86, 1, 1, 10 },
    { 30, 120, 1, 1, 10 },
    { 40, 95, 1, 1, 10 },
    { 24, 102, 1, 1, 10 },
    { 33, 88, 1, 1, 10 },
    { 33, 88, 1, 1, 10 },
    { 43, 64, 1, 1, 10 },
    { 33, 88, 1, 1, 10 },
    { 33, 88, 1, 1, 10 },
    { 38, 82, 1, 1, 10 },
    { 54, 72, 1, 1, 10 },
    { 55, 96, 1, 1, 10 },
    { 36, 79, 1, 1, 10 },
    { 44, 76, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 75, 72, 1, 1, 11 },
    { 70, 109, 1, 1, 11 },
    { 63, 111, 1, 1, 11 },
    { 58, 122, 1, 1, 11 },
    { 64, 116, 1, 1, 11 },
    { 84, 96, 1, 1, 11 },
    { 75, 71, 1, 1, 11 },
    { 55, 120, 1, 1, 11 },
    { 80, 174, 1, 1, 11 },
    { 62, 117, 1, 1, 11 },
    { 58, 122, 1, 1, 11 },
    { 63, 111, 1, 1, 11 },
    { 63, 111, 1, 1, 11 },
    { 75, 72, 1, 1, 11 },
    { 63, 111, 1, 1, 11 },
    { 63, 111, 1, 1, 11 },
    { 71, 91, 1, 1, 11 },
    { 76, 70, 1, 1, 11 },
    { 78, 89, 1, 1, 11 },
    { 56, 71, 1, 1, 11 },
    { 72, 72, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 78, 72, 1, 1, 12 },
    { 72, 105, 1, 1, 12 },
    { 62, 108, 1, 1, 12 },
    { 100, 194, 1, 1, 12 },
    { 66, 114, 1, 1, 12 },
    { 85, 91, 1, 1, 12 },
    { 69, 73, 1, 1, 12 },
    { 63, 113, 1, 1, 12 },
    { 114, 178, 1, 1, 12 },
    { 66, 116, 1, 1, 12 },
    { 100, 194, 1, 1, 12 },
    { 62, 108, 1, 1, 12 },
    { 62, 108, 1, 1, 12 },
    { 78, 72, 1, 1, 12 },
    { 62, 108, 1, 1, 12 },
    { 62, 108, 1, 1, 12 },
    { 75, 105, 1, 1, 12 },
    { 79, 68, 1, 1, 12 },
    { 91, 106, 1, 1, 12 },
    { 72, 68, 1, 1, 12 },
    { 64, 94, 1, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 69, 32, 1, 1, 13 },
    { 56, 68, 1, 1, 13 },
    { 49, 67, 1, 1, 13 },
    { 87, 152, 1, 1, 13 },
    { 52, 72, 1, 1, 13 },
    { 73, 52, 1, 1, 13 },
    { 58, 30, 1, 1, 13 },
    { 46, 76, 1, 1, 13 },
    { 100, 134, 1, 1, 13 },
    { 54, 69, 1, 1, 13 },
    { 87, 152, 1, 1, 13 },
    { 49, 67, 1, 1, 13 },
    { 49, 67, 1, 1, 13 },
    { 69, 32, 1, 1, 13 },
    { 49, 67, 1, 1, 13 },
    { 49, 67, 1, 1, 13 },
    { 81, 163, 1, 1, 13 },
    { 79, 38, 1, 1, 13 },
    { 93, 81, 1, 1, 13 },
    { 70, 37, 1, 1, 13 },
    { 68, 72, 1, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 75, -7, 1, 1, 14 },
    { 65, -11, 1, 1, 14 },
    { 49, -4, 1, 1, 14 },
    { 54, -5, 1, 1, 14 },
    { 64, -3, 1, 1, 14 },
    { 84, -6, 1, 1, 14 },
    { 67, -13, 1, 1, 14 },
    { 57, -3, 1, 1, 14 },
    { 100, 58, 1, 1, 14 },
    { 53, -11, 1, 1, 14 },
    { 54, -5, 1, 1, 14 },
    { 49, -4, 1, 1, 14 },
    { 49, -4, 1, 1, 14 },
    { 75, -7, 1, 1, 14 },
    { 49, -4, 1, 1, 14 },
    { 49, -4, 1, 1, 14 },
    { 76, -2, 1, 1, 14 },
    { 86, -2, 1, 1, 14 },
    { 104, -4, 1, 1, 14 },
    { 70, -2, 1, 1, 14 },
    { 72, -8, 1, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 71, 16, 1, 1, 15 },
    { 65, 16, 1, 1, 15 },
    { 49, 14, 1, 1, 15 },
    { 54, 10, 1, 1, 15 },
    { 64, 16, 1, 1, 15 },
    { 84, -3, 1, 1, 15 },
    { 63, -8, 1, 1, 15 },
    { 57, 10, 1, 1, 15 },
    { 88, 2, 1, 1, 15 },
    { 53, -6, 1, 1, 15 },
    { 54, 10, 1, 1, 15 },
    { 49, 14, 1, 1, 15 },
    { 49, 14, 1, 1, 15 },
    { 71, 16, 1, 1, 15 },
    { 49, 14, 1, 1, 15 },
    { 49, 14, 1, 1, 15 },
    { 76, 0, 1, 1, 15 },
    { 90, 0, 1, 1, 15 },
    { 104, 0, 1, 1, 15 },
    { 70, 0, 1, 1, 15 },
    { 72, 0, 1, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 69, 16, 1, 1, 16 },
    { 65, 16, 1, 1, 16 },
    { 49, 14, 1, 1, 16 },
    { 54, 10, 1, 1, 16 },
    { 64, 14, 1, 1, 16 },
    { 84, -3, 1, 1, 16 },
    { 61, -6, 1, 1, 16 },
    { 57, 22, 1, 1, 16 },
    { 80, -16, 1, 1, 16 },
    { 53, -6, 1, 1, 16 },
    { 54, 10, 1, 1, 16 },
    { 49, 14, 1, 1, 16 },
    { 49, 14, 1, 1, 16 },
    { 69, 16, 1, 1, 16 },
    { 49, 14, 1, 1, 16 },
    { 49, 14, 1, 1, 16 },
    { 76, -1, 1, 1, 16 },
    { 90, 0, 1, 1, 16 },
    { 104, 0, 1, 1, 16 },
    { 70, 0, 1, 1, 16 },
    { 72, -2, 1, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 73, 16, 1, 1, 17 },
    { 65, 16, 1, 1, 17 },
    { 49, 18, 1, 1, 17 },
    { 54, 18, 1, 1, 17 },
    { 64, 16, 1, 1, 17 },
    { 84, -2, 1, 1, 17 },
    { 56, -6, 1, 1, 17 },
    { 57, 16, 1, 1, 17 },
    { 78, -4, 1, 1, 17 },
    { 53, -5, 1, 1, 17 },
    { 54, 18, 1, 1, 17 },
    { 49, 18, 1, 1, 17 },
    { 49, 18, 1, 1, 17 },
    { 73, 16, 1, 1, 17 },
    { 49, 18, 1, 1, 17 },
    { 49, 18, 1, 1, 17 },
    { 76, 0, 1, 1, 17 },
    { 90, 0, 1, 1, 17 },
    { 104, 0, 1, 1, 17 },
    { 70, 0, 1, 1, 17 },
    { 72, 2, 1, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 68, 16, 1, 1, 18 },
    { 65, 16, 1, 1, 18 },
    { 49, 26, 1, 1, 18 },
    { 35, 18, 1, 1, 18 },
    { 64, 10, 1, 1, 18 },
    { 84, -2, 1, 1, 18 },
    { 67, 0, 1, 1, 18 },
    { 57, 8, 1, 1, 18 },
    { 70, 8, 1, 1, 18 },
    { 53, -4, 1, 1, 18 },
    { 35, 18, 1, 1, 18 },
    { 49, 26, 1, 1, 18 },
    { 49, 26, 1, 1, 18 },
    { 68, 16, 1, 1, 18 },
    { 49, 26, 1, 1, 18 },
    { 49, 26, 1, 1, 18 },
    { 76, 0, 1, 1, 18 },
    { 90, 0, 1, 1, 18 },
    { 112, 0, 1, 1, 18 },
    { 70, 0, 1, 1, 18 },
    { 72, 0, 1, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 72, 4, 1, 1, 19 },
    { 65, 0, 1, 1, 19 },
    { 49, -2, 1, 1, 19 },
    { 35, -5, 1, 1, 19 },
    { 64, 0, 1, 1, 19 },
    { 84, -2, 1, 1, 19 },
    { 66, 0, 1, 1, 19 },
    { 57, -4, 1, 1, 19 },
    { 72, 14, 1, 1, 19 },
    { 53, -4, 1, 1, 19 },
    { 35, -5, 1, 1, 19 },
    { 49, -2, 1, 1, 19 },
    { 49, -2, 1, 1, 19 },
    { 72, 4, 1, 1, 19 },
    { 49, -2, 1, 1, 19 },
    { 49, -2, 1, 1, 19 },
    { 76, 0, 1, 1, 19 },
    { 111, 0, 1, 1, 19 },
    { 145, 0, 1, 1, 19 },
    { 70, 0, 1, 1, 19 },
    { 72, 0, 1, 1, 19 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 72, 0, 1, 0, 20 },
    { 65, 0, 1, 0, 20 },
    { 49, -2, 1, 0, 20 },
    { 35, 0, 1, 0, 20 },
    { 64, 0, 1, 0, 20 },
    { 84, -2, 1, 0, 20 },
    { 70, 0, 1, 0, 20 },
    { 57, -4, 1, 0, 20 },
    { 74, 0, 1, 0, 20 },
    { 53, -4, 1, 0, 20 },
    { 35, 0, 1, 0, 20 },
    { 49, -2, 1, 0, 20 },
    { 49, -2, 1, 0, 20 },
    { 72, 0, 1, 0, 20 },
    { 49, -2, 1, 0, 20 },
    { 49, -2, 1, 0, 20 },
    { 76, 0, 1, 0, 20 },
    { 113, 0, 1, 0, 20 },
    { 169, 0, 1, 0, 20 },
    { 99, 0, 1, 0, 20 },
    { 72, 0, 1, 0, 20 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -130, 0, 1, 0, 1 },
    { -152, 0, 1, 0, 1 },
    { -136, 0, 1, 0, 1 },
    { -132, 0, 1, 0, 1 },
    { -128, 0, 1, 0, 1 },
    { -106, 0, 1, 0, 1 },
    { -133, 0, 1, 0, 1 },
    { -130, 0, 1, 0, 1 },
    { -112, 0, 1, 0, 1 },
    { -130, 0, 1, 0, 1 },
    { -132, 0, 1, 0, 1 },
    { -136, 0, 1, 0, 1 },
    { -136, 0, 1, 0, 1 },
    { -130, 0, 1, 0, 1 },
    { -136, 0, 1, 0, 1 },
    { -136, 0, 1, 0, 1 },
    { -159, 0, 1, 0, 1 },
    { -155, 0, 1, 0, 1 },
    { -129, 0, 1, 0, 1 },
    { -138, 0, 1, 0, 1 },
    { -138, 0, 1, 0, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -132, 0, 1, 0, 2 },
    { -136, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -110, 0, 1, 0, 2 },
    { -119, 0, 1, 0, 2 },
    { -107, 0, 1, 0, 2 },
    { -126, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -90, 0, 1, 0, 2 },
    { -119, 0, 1, 0, 2 },
    { -110, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -132, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -118, 0, 1, 0, 2 },
    { -138, 0, 1, 0, 2 },
    { -135, 0, 1, 0, 2 },
    { -108, 0, 1, 0, 2 },
    { -123, 0, 1, 0, 2 },
    { -134, 0, 1, 0, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -134, 0, 1, 0, 3 },
    { -134, 0, 1, 0, 3 },
    { -118, 0, 1, 0, 3 },
    { -108, 0, 1, 0, 3 },
    { -123, 0, 1, 0, 3 },
    { -112, 0, 1, 0, 3 },
    { -129, 0, 1, 0, 3 },
    { -106, 0, 1, 0, 3 },
    { -96, 0, 1, 0, 3 },
    { -116, 0, 1, 0, 3 },
    { -108, 0, 1, 0, 3 },
    { -118, 0, 1, 0, 3 },
    { -118, 0, 1, 0, 3 },
    { -134, 0, 1, 0, 3 },
    { -118, 0, 1, 0, 3 },
    { -118, 0, 1, 0, 3 },
    { -136, 0, 1, 0, 3 },
    { -135, 0, 1, 0, 3 },
    { -111, 0, 1, 0, 3 },
    { -127, 0, 1, 0, 3 },
    { -134, 0, 1, 0, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -130, 0, 1, 0, 4 },
    { -134, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -117, 0, 1, 0, 4 },
    { -124, 0, 1, 0, 4 },
    { -114, 0, 1, 0, 4 },
    { -133, 0, 1, 0, 4 },
    { -114, 0, 1, 0, 4 },
    { -92, 0, 1, 0, 4 },
    { -113, 0, 1, 0, 4 },
    { -117, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -130, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -139, 0, 1, 0, 4 },
    { -140, 0, 1, 0, 4 },
    { -116, 0, 1, 0, 4 },
    { -130, 0, 1, 0, 4 },
    { -128, 0, 1, 0, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -126, 0, 1, 0, 5 },
    { -129, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -116, 0, 1, 0, 5 },
    { -120, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -130, 0, 1, 0, 5 },
    { -117, 0, 1, 0, 5 },
    { -92, 0, 1, 0, 5 },
    { -103, 0, 1, 0, 5 },
    { -116, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -126, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -115, 0, 1, 0, 5 },
    { -133, 0, 1, 0, 5 },
    { -135, 0, 1, 0, 5 },
    { -114, 0, 1, 0, 5 },
    { -128, 0, 1, 0, 5 },
    { -128, 0, 1, 0, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -124, 0, 1, 0, 6 },
    { -124, 0, 1, 0, 6 },
    { -110, 0, 1, 0, 6 },
    { -128, 0, 1, 0, 6 },
    { -111, 0, 1, 0, 6 },
    { -111, 0, 1, 0, 6 },
    { -133, 2, 1, 0, 6 },
    { -100, 0, 1, 0, 6 },
    { -86, 0, 1, 0, 6 },
    { -100, 0, 1, 0, 6 },
    { -128, 0, 1, 0, 6 },
    { -110, 0, 1, 0, 6 },
    { -110, 0, 1, 0, 6 },
    { -124, 0, 1, 0, 6 },
    { -110, 0, 1, 0, 6 },
    { -110, 0, 1, 0, 6 },
    { -133, 0, 1, 0, 6 },
    { -129, 0, 1, 0, 6 },
    { -111, 0, 1, 0, 6 },
    { -124, 0, 1, 0, 6 },
    { -128, 0, 1, 0, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -136, 0, 1, 0, 7 },
    { -130, 0, 1, 0, 7 },
    { -99, 0, 1, 0, 7 },
    { -127, 0, 1, 0, 7 },
    { -108, 0, 1, 0, 7 },
    { -108, 0, 1, 0, 7 },
    { -127, 0, 1, 0, 7 },
    { -95, 0, 1, 0, 7 },
    { -92, 0, 1, 0, 7 },
    { -122, 0, 1, 0, 7 },
    { -127, 0, 1, 0, 7 },
    { -99, 0, 1, 0, 7 },
    { -99, 0, 1, 0, 7 },
    { -136, 0, 1, 0, 7 },
    { -99, 0, 1, 0, 7 },
    { -99, 0, 1, 0, 7 },
    { -126, 0, 1, 0, 7 },
    { -137, 0, 1, 0, 7 },
    { -110, 0, 1, 0, 7 },
    { -121, 0, 1, 0, 7 },
    { -138, 0, 1, 0, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -140, -29, 1, 0, 8 },
    { -139, -11, 1, 0, 8 },
    { -93, 0, 1, 0, 8 },
    { -116, 0, 1, 0, 8 },
    { -99, -3, 1, 0, 8 },
    { -106, -3, 1, 0, 8 },
    { -139, -16, 1, 0, 8 },
    { -83, -3, 1, 0, 8 },
    { -90, 0, 1, 0, 8 },
    { -110, 4, 1, 0, 8 },
    { -116, 0, 1, 0, 8 },
    { -93, 0, 1, 0, 8 },
    { -93, 0, 1, 0, 8 },
    { -140, -29, 1, 0, 8 },
    { -93, 0, 1, 0, 8 },
    { -93, 0, 1, 0, 8 },
    { -123, 0, 1, 0, 8 },
    { -140, 0, 1, 0, 8 },
    { -138, 0, 1, 0, 8 },
    { -106, -3, 1, 0, 8 },
    { -128, 0, 1, 0, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -130, -31, 1, 0, 9 },
    { -119, -16, 1, 0, 9 },
    { -109, 16, 1, 0, 9 },
    { -109, 10, 1, 0, 9 },
    { -108, 1, 1, 0, 9 },
    { -76, 20, 1, 0, 9 },
    { -130, 2, 1, 0, 9 },
    { -92, 8, 1, 0, 9 },
    { -88, 16, 1, 0, 9 },
    { -104, -4, 1, 0, 9 },
    { -109, 10, 1, 0, 9 },
    { -109, 16, 1, 0, 9 },
    { -109, 16, 1, 0, 9 },
    { -130, -31, 1, 0, 9 },
    { -109, 16, 1, 0, 9 },
    { -109, 16, 1, 0, 9 },
    { -112, 0, 1, 0, 9 },
    { -127, 15, 1, 0, 9 },
    { -143, 0, 1, 0, 9 },
    { -100, 20, 1, 0, 9 },
    { -114, 16, 1, 0, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -106, -11, 1, 0, 10 },
    { -104, 12, 1, 0, 10 },
    { -95, 5, 1, 0, 10 },
    { -97, 24, 1, 0, 10 },
    { -99, 3, 1, 0, 10 },
    { -88, 7, 1, 0, 10 },
    { -117, 138, 1, 0, 10 },
    { -75, -1, 1, 0, 10 },
    { -56, 32, 1, 0, 10 },
    { -97, 20, 1, 0, 10 },
    { -97, 24, 1, 0, 10 },
    { -95, 5, 1, 0, 10 },
    { -95, 5, 1, 0, 10 },
    { -106, -11, 1, 0, 10 },
    { -95, 5, 1, 0, 10 },
    { -95, 5, 1, 0, 10 },
    { -115, 5, 1, 0, 10 },
    { -101, 26, 1, 0, 10 },
    { -182, 0, 1, 0, 10 },
    { -93, 35, 1, 0, 10 },
    { -100, 24, 1, 0, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -62, 38, 1, 0, 11 },
    { -62, 67, 1, 0, 11 },
    { -52, 42, 1, 0, 11 },
    { -60, 51, 1, 0, 11 },
    { -69, 29, 1, 0, 11 },
    { -51, 46, 1, 0, 11 },
    { -97, 128, 1, 0, 11 },
    { -38, 34, 1, 0, 11 },
    { -46, 76, 1, 0, 11 },
    { -60, 50, 1, 0, 11 },
    { -60, 51, 1, 0, 11 },
    { -52, 42, 1, 0, 11 },
    { -52, 42, 1, 0, 11 },
    { -62, 38, 1, 0, 11 },
    { -52, 42, 1, 0, 11 },
    { -52, 42, 1, 0, 11 },
    { -83, 42, 1, 0, 11 },
    { -73, 61, 1, 0, 11 },
    { -133, 42, 1, 0, 11 },
    { -73, 60, 1, 0, 11 },
    { -64, 64, 1, 0, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -3, 80, 1, 0, 12 },
    { -3, 80, 1, 0, 12 },
    { 10, 71, 1, 0, 12 },
    { 18, 81, 1, 0, 12 },
    { -6, 56, 1, 0, 12 },
    { -2, 64, 1, 0, 12 },
    { -21, 216, 1, 0, 12 },
    { 8, 67, 1, 0, 12 },
    { 6, 92, 1, 0, 12 },
    { -9, 73, 1, 0, 12 },
    { 18, 81, 1, 0, 12 },
    { 10, 71, 1, 0, 12 },
    { 10, 71, 1, 0, 12 },
    { -3, 80, 1, 0, 12 },
    { 10, 71, 1, 0, 12 },
    { 10, 71, 1, 0, 12 },
    { -67, 72, 1, 0, 12 },
    { -46, 67, 1, 0, 12 },
    { -97, 70, 1, 0, 12 },
    { -55, 52, 1, 0, 12 },
    { -20, 68, 1, 0, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 41, 115, 1, 1, 13 },
    { 41, 115, 1, 1, 13 },
    { 48, 115, 1, 1, 13 },
    { 48, 112, 1, 1, 13 },
    { 32, 98, 1, 1, 13 },
    { 36, 106, 1, 1, 13 },
    { 68, 65, 1, 1, 13 },
    { 47, 106, 1, 1, 13 },
    { 52, 118, 1, 1, 13 },
    { 37, 117, 1, 1, 13 },
    { 48, 112, 1, 1, 13 },
    { 48, 115, 1, 1, 13 },
    { 48, 115, 1, 1, 13 },
    { 41, 115, 1, 1, 13 },
    { 48, 115, 1, 1, 13 },
    { 48, 115, 1, 1, 13 },
    { 12, 86, 1, 1, 13 },
    { 24, 76, 1, 1, 13 },
    { -6, 97, 1, 1, 13 },
    { 36, 78, 1, 1, 13 },
    { 50, 88, 1, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -19, -73, 1, 1, 1 },
    { -10, -56, 1, 1, 1 },
    { -18, -48, 1, 1, 1 },
    { -6, -33, 1, 1, 1 },
    { -13, -54, 1, 1, 1 },
    { -19, -36, 1, 1, 1 },
    { -20, -76, 1, 1, 1 },
    { -33, -39, 1, 1, 1 },
    { -32, -42, 1, 1, 1 },
    { -21, -30, 1, 1, 1 },
    { -6, -33, 1, 1, 1 },
    { -18, -48, 1, 1, 1 },
    { -18, -48, 1, 1, 1 },
    { -19, -73, 1, 1, 1 },
    { -18, -48, 1, 1, 1 },
    { -18, -48, 1, 1, 1 },
    { -32, -61, 1, 1, 1 },
    { -40, -50, 1, 1, 1 },
    { -8, -74, 1, 1, 1 },
    { -19, -36, 1, 1, 1 },
    { -18, -66, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -22, -61, 1, 1, 2 },
    { -21, -51, 1, 1, 2 },
    { -23, -47, 1, 1, 2 },
    { -13, -32, 1, 1, 2 },
    { -11, -54, 1, 1, 2 },
    { -26, -36, 1, 1, 2 },
    { -27, -80, 1, 1, 2 },
    { -33, -38, 1, 1, 2 },
    { -33, -38, 1, 1, 2 },
    { -16, -30, 1, 1, 2 },
    { -13, -32, 1, 1, 2 },
    { -23, -47, 1, 1, 2 },
    { -23, -47, 1, 1, 2 },
    { -22, -61, 1, 1, 2 },
    { -23, -47, 1, 1, 2 },
    { -23, -47, 1, 1, 2 },
    { -28, -60, 1, 1, 2 },
    { -35, -48, 1, 1, 2 },
    { -8, -74, 1, 1, 2 },
    { -26, -36, 1, 1, 2 },
    { -14, -64, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -59, -58, 1, 1, 3 },
    { -23, -57, 1, 1, 3 },
    { -27, -47, 1, 1, 3 },
    { -10, -44, 1, 1, 3 },
    { -21, -68, 1, 1, 3 },
    { -44, -44, 1, 1, 3 },
    { -30, -91, 1, 1, 3 },
    { -22, -51, 1, 1, 3 },
    { -30, -57, 1, 1, 3 },
    { -16, -48, 1, 1, 3 },
    { -10, -44, 1, 1, 3 },
    { -27, -47, 1, 1, 3 },
    { -27, -47, 1, 1, 3 },
    { -59, -58, 1, 1, 3 },
    { -27, -47, 1, 1, 3 },
    { -27, -47, 1, 1, 3 },
    { -47, -55, 1, 1, 3 },
    { -51, -48, 1, 1, 3 },
    { -28, -77, 1, 1, 3 },
    { -44, -44, 1, 1, 3 },
    { -46, -66, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -53, -49, 1, 1, 4 },
    { -14, -49, 1, 1, 4 },
    { -24, -49, 1, 1, 4 },
    { -10, -43, 1, 1, 4 },
    { -16, -58, 1, 1, 4 },
    { -37, -45, 1, 1, 4 },
    { -23, -88, 1, 1, 4 },
    { -19, -49, 1, 1, 4 },
    { -29, -58, 1, 1, 4 },
    { -15, -50, 1, 1, 4 },
    { -10, -43, 1, 1, 4 },
    { -24, -49, 1, 1, 4 },
    { -24, -49, 1, 1, 4 },
    { -53, -49, 1, 1, 4 },
    { -24, -49, 1, 1, 4 },
    { -24, -49, 1, 1, 4 },
    { -34, -56, 1, 1, 4 },
    { -28, -57, 1, 1, 4 },
    { -21, -89, 1, 1, 4 },
    { -37, -45, 1, 1, 4 },
    { 2, -64, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -45, -50, 1, 1, 5 },
    { -13, -50, 1, 1, 5 },
    { -20, -50, 1, 1, 5 },
    { -9, -44, 1, 1, 5 },
    { -13, -60, 1, 1, 5 },
    { -36, -46, 1, 1, 5 },
    { -25, -96, 1, 1, 5 },
    { -19, -54, 1, 1, 5 },
    { -27, -62, 1, 1, 5 },
    { -14, -51, 1, 1, 5 },
    { -9, -44, 1, 1, 5 },
    { -20, -50, 1, 1, 5 },
    { -20, -50, 1, 1, 5 },
    { -45, -50, 1, 1, 5 },
    { -20, -50, 1, 1, 5 },
    { -20, -50, 1, 1, 5 },
    { -28, -61, 1, 1, 5 },
    { -23, -56, 1, 1, 5 },
    { -12, -90, 1, 1, 5 },
    { -36, -46, 1, 1, 5 },
    { 4, -72, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -51, -44, 1, 1, 6 },
    { -22, -46, 1, 1, 6 },
    { -27, -48, 1, 1, 6 },
    { -17, -40, 1, 1, 6 },
    { -26, -57, 1, 1, 6 },
    { -42, -39, 1, 1, 6 },
    { -18, -90, 1, 1, 6 },
    { -31, -56, 1, 1, 6 },
    { -32, -57, 1, 1, 6 },
    { -23, -42, 1, 1, 6 },
    { -17, -40, 1, 1, 6 },
    { -27, -48, 1, 1, 6 },
    { -27, -48, 1, 1, 6 },
    { -51, -44, 1, 1, 6 },
    { -27, -48, 1, 1, 6 },
    { -27, -48, 1, 1, 6 },
    { -34, -53, 1, 1, 6 },
    { -23, -55, 1, 1, 6 },
    { -17, -82, 1, 1, 6 },
    { -42, -39, 1, 1, 6 },
    { -8, -66, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -66, -20, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -37, -29, 1, 1, 7 },
    { -46, -47, 1, 1, 7 },
    { -62, -27, 1, 1, 7 },
    { -46, -75, 1, 1, 7 },
    { -54, -36, 1, 1, 7 },
    { -56, -41, 1, 1, 7 },
    { -43, -24, 1, 1, 7 },
    { -37, -29, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -66, -20, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -43, -34, 1, 1, 7 },
    { -52, -46, 1, 1, 7 },
    { -45, -34, 1, 1, 7 },
    { -41, -73, 1, 1, 7 },
    { -62, -27, 1, 1, 7 },
    { -28, -50, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -68, -34, 1, 1, 8 },
    { -43, -34, 1, 1, 8 },
    { -47, -38, 1, 1, 8 },
    { -40, -32, 1, 1, 8 },
    { -45, -48, 1, 1, 8 },
    { -63, -29, 1, 1, 8 },
    { -24, -82, 1, 1, 8 },
    { -57, -41, 1, 1, 8 },
    { -57, -38, 1, 1, 8 },
    { -60, -29, 1, 1, 8 },
    { -40, -32, 1, 1, 8 },
    { -47, -38, 1, 1, 8 },
    { -47, -38, 1, 1, 8 },
    { -68, -34, 1, 1, 8 },
    { -47, -38, 1, 1, 8 },
    { -47, -38, 1, 1, 8 },
    { -42, -53, 1, 1, 8 },
    { -40, -50, 1, 1, 8 },
    { -29, -83, 1, 1, 8 },
    { -63, -29, 1, 1, 8 },
    { -30, -56, 1, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -76, -21, 1, 1, 9 },
    { -54, -21, 1, 1, 9 },
    { -55, -28, 1, 1, 9 },
    { -47, -18, 1, 1, 9 },
    { -55, -37, 1, 1, 9 },
    { -68, -15, 1, 1, 9 },
    { -39, -68, 1, 1, 9 },
    { -63, -23, 1, 1, 9 },
    { -63, -21, 1, 1, 9 },
    { -64, -15, 1, 1, 9 },
    { -47, -18, 1, 1, 9 },
    { -55, -28, 1, 1, 9 },
    { -55, -28, 1, 1, 9 },
    { -76, -21, 1, 1, 9 },
    { -55, -28, 1, 1, 9 },
    { -55, -28, 1, 1, 9 },
    { -55, -32, 1, 1, 9 },
    { -46, -29, 1, 1, 9 },
    { -46, -65, 1, 1, 9 },
    { -68, -15, 1, 1, 9 },
    { -54, -42, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, -29, 1, 1, 10 },
    { -56, -11, 1, 1, 10 },
    { -55, -20, 1, 1, 10 },
    { -48, -11, 1, 1, 10 },
    { -56, -28, 1, 1, 10 },
    { -72, -6, 1, 1, 10 },
    { -56, -57, 1, 1, 10 },
    { -66, -6, 1, 1, 10 },
    { -65, -16, 1, 1, 10 },
    { -63, -9, 1, 1, 10 },
    { -48, -11, 1, 1, 10 },
    { -55, -20, 1, 1, 10 },
    { -55, -20, 1, 1, 10 },
    { -64, -29, 1, 1, 10 },
    { -55, -20, 1, 1, 10 },
    { -55, -20, 1, 1, 10 },
    { -57, -19, 1, 1, 10 },
    { -49, -21, 1, 1, 10 },
    { -64, -55, 1, 1, 10 },
    { -72, -6, 1, 1, 10 },
    { -60, -20, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -66, -17, 1, 1, 11 },
    { -56, -3, 1, 1, 11 },
    { -51, -4, 1, 1, 11 },
    { -51, 2, 1, 1, 11 },
    { -63, -17, 1, 1, 11 },
    { -73, 7, 1, 1, 11 },
    { -75, -40, 1, 1, 11 },
    { -69, 6, 1, 1, 11 },
    { -75, -4, 1, 1, 11 },
    { -76, 1, 1, 1, 11 },
    { -51, 2, 1, 1, 11 },
    { -51, -4, 1, 1, 11 },
    { -51, -4, 1, 1, 11 },
    { -66, -17, 1, 1, 11 },
    { -51, -4, 1, 1, 11 },
    { -51, -4, 1, 1, 11 },
    { -65, -9, 1, 1, 11 },
    { -65, -10, 1, 1, 11 },
    { -62, -30, 1, 1, 11 },
    { -73, 7, 1, 1, 11 },
    { -72, 10, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -70, -2, 1, 1, 12 },
    { -65, -5, 1, 1, 12 },
    { -50, 10, 1, 1, 12 },
    { -77, 13, 1, 1, 12 },
    { -62, 0, 1, 1, 12 },
    { -71, 8, 1, 1, 12 },
    { -80, -15, 1, 1, 12 },
    { -69, 18, 1, 1, 12 },
    { -69, 13, 1, 1, 12 },
    { -69, 20, 1, 1, 12 },
    { -77, 13, 1, 1, 12 },
    { -50, 10, 1, 1, 12 },
    { -50, 10, 1, 1, 12 },
    { -70, -2, 1, 1, 12 },
    { -50, 10, 1, 1, 12 },
    { -50, 10, 1, 1, 12 },
    { -59, 16, 1, 1, 12 },
    { -60, 13, 1, 1, 12 },
    { -71, -3, 1, 1, 12 },
    { -71, 8, 1, 1, 12 },
    { -40, 8, 1, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 48, 88, 1, 1, 13 },
    { 48, 88, 1, 1, 13 },
    { 71, 103, 1, 1, 13 },
    { 48, 104, 1, 1, 13 },
    { 100, 112, 1, 1, 13 },
    { 98, 96, 1, 1, 13 },
    { 93, 53, 1, 1, 13 },
    { 48, 104, 1, 1, 13 },
    { 41, 108, 1, 1, 13 },
    { 104, 106, 1, 1, 13 },
    { 48, 104, 1, 1, 13 },
    { 71, 103, 1, 1, 13 },
    { 71, 103, 1, 1, 13 },
    { 48, 104, 1, 1, 13 },
    { 71, 103, 1, 1, 13 },
    { 71, 103, 1, 1, 13 },
    { 54, 76, 1, 1, 13 },
    { 80, 96, 1, 1, 13 },
    { 68, 55, 1, 1, 13 },
    { 68, 80, 1, 1, 13 },
    { 58, 86, 1, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -10, 26, 1, 1, 15 },
    { 10, 16, 1, 1, 15 },
    { 3, 16, 1, 1, 15 },
    { 5, 29, 1, 1, 15 },
    { 0, 28, 1, 1, 15 },
    { -3, -1, 1, 1, 15 },
    { -9, 0, 1, 1, 15 },
    { -24, 26, 1, 1, 15 },
    { 12, -1, 1, 1, 15 },
    { 7, 0, 1, 1, 15 },
    { 5, 29, 1, 1, 15 },
    { 3, 16, 1, 1, 15 },
    { 3, 16, 1, 1, 15 },
    { -10, 26, 1, 1, 15 },
    { 3, 16, 1, 1, 15 },
    { 3, 16, 1, 1, 15 },
    { 4, 0, 1, 1, 15 },
    { 4, 0, 1, 1, 15 },
    { 4, 0, 1, 1, 15 },
    { -3, -1, 1, 1, 15 },
    { -4, 4, 1, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, 26, 1, 1, 16 },
    { -16, 16, 1, 1, 16 },
    { -18, 20, 1, 1, 16 },
    { -29, 29, 1, 1, 16 },
    { -22, 37, 1, 1, 16 },
    { -23, 0, 1, 1, 16 },
    { -32, 3, 1, 1, 16 },
    { -35, 44, 1, 1, 16 },
    { -19, -8, 1, 1, 16 },
    { -30, 0, 1, 1, 16 },
    { -29, 29, 1, 1, 16 },
    { -18, 20, 1, 1, 16 },
    { -18, 20, 1, 1, 16 },
    { -36, 26, 1, 1, 16 },
    { -18, 20, 1, 1, 16 },
    { -18, 20, 1, 1, 16 },
    { -21, 0, 1, 1, 16 },
    { -21, 0, 1, 1, 16 },
    { -21, 0, 1, 1, 16 },
    { -23, 0, 1, 1, 16 },
    { -28, 0, 1, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, 26, 1, 1, 17 },
    { -18, 16, 1, 1, 17 },
    { -18, 26, 1, 1, 17 },
    { -19, 32, 1, 1, 17 },
    { -17, 39, 1, 1, 17 },
    { -30, 5, 1, 1, 17 },
    { -34, 2, 1, 1, 17 },
    { -28, 22, 1, 1, 17 },
    { -8, -4, 1, 1, 17 },
    { -28, 1, 1, 1, 17 },
    { -19, 32, 1, 1, 17 },
    { -18, 26, 1, 1, 17 },
    { -18, 26, 1, 1, 17 },
    { -36, 26, 1, 1, 17 },
    { -18, 26, 1, 1, 17 },
    { -18, 26, 1, 1, 17 },
    { -21, 0, 1, 1, 17 },
    { -21, 0, 1, 1, 17 },
    { -21, 0, 1, 1, 17 },
    { -30, 5, 1, 1, 17 },
    { -28, 0, 1, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -30, 16, 1, 1, 18 },
    { -20, 16, 1, 1, 18 },
    { -15, 28, 1, 1, 18 },
    { -16, 32, 1, 1, 18 },
    { -21, 42, 1, 1, 18 },
    { -18, 13, 1, 1, 18 },
    { -17, -20, 1, 1, 18 },
    { -21, 23, 1, 1, 18 },
    { -13, 24, 1, 1, 18 },
    { -13, -4, 1, 1, 18 },
    { -16, 32, 1, 1, 18 },
    { -15, 28, 1, 1, 18 },
    { -15, 28, 1, 1, 18 },
    { -30, 16, 1, 1, 18 },
    { -15, 28, 1, 1, 18 },
    { -15, 28, 1, 1, 18 },
    { -21, 0, 1, 1, 18 },
    { -21, 0, 1, 1, 18 },
    { -21, 0, 1, 1, 18 },
    { -18, 13, 1, 1, 18 },
    { -14, 0, 1, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, 100, 1, 1, 19 },
    { -23, 96, 1, 1, 19 },
    { -14, 62, 1, 1, 19 },
    { -4, -24, 1, 1, 19 },
    { -11, 48, 1, 1, 19 },
    { -26, 29, 1, 1, 19 },
    { -41, -30, 1, 1, 19 },
    { -14, 68, 1, 1, 19 },
    { -19, 38, 1, 1, 19 },
    { -23, -23, 1, 1, 19 },
    { -4, -24, 1, 1, 19 },
    { -14, 62, 1, 1, 19 },
    { -14, 62, 1, 1, 19 },
    { -16, 100, 1, 1, 19 },
    { -14, 62, 1, 1, 19 },
    { -14, 62, 1, 1, 19 },
    { -25, -37, 1, 1, 19 },
    { -32, -7, 1, 1, 19 },
    { -40, 68, 1, 1, 19 },
    { -26, 86, 1, 1, 19 },
    { -24, 28, 1, 1, 19 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -38, 96, 1, 1, 20 },
    { -38, 84, 1, 1, 20 },
    { -34, 74, 1, 1, 20 },
    { -31, -9, 1, 1, 20 },
    { -39, 96, 1, 1, 20 },
    { -45, 98, 1, 1, 20 },
    { -50, -33, 1, 1, 20 },
    { -49, -14, 1, 1, 20 },
    { -37, 42, 1, 1, 20 },
    { -43, -12, 1, 1, 20 },
    { -31, -9, 1, 1, 20 },
    { -34, 74, 1, 1, 20 },
    { -34, 74, 1, 1, 20 },
    { -38, 96, 1, 1, 20 },
    { -34, 74, 1, 1, 20 },
    { -34, 74, 1, 1, 20 },
    { -66, -12, 1, 1, 20 },
    { -40, 14, 1, 1, 20 },
    { -68, 61, 1, 1, 20 },
    { -45, 106, 1, 1, 20 },
    { -44, 44, 1, 1, 20 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, 80, 1, 1, 21 },
    { -37, 64, 1, 1, 21 },
    { -31, 60, 1, 1, 21 },
    { -21, -18, 1, 1, 21 },
    { -39, 100, 1, 1, 21 },
    { -45, 72, 1, 1, 21 },
    { -62, -39, 1, 1, 21 },
    { -50, -24, 1, 1, 21 },
    { -36, 35, 1, 1, 21 },
    { -38, -27, 1, 1, 21 },
    { -21, -18, 1, 1, 21 },
    { -31, 60, 1, 1, 21 },
    { -31, 60, 1, 1, 21 },
    { -36, 80, 1, 1, 21 },
    { -31, 60, 1, 1, 21 },
    { -31, 60, 1, 1, 21 },
    { -59, -32, 1, 1, 21 },
    { -43, -57, 1, 1, 21 },
    { -62, 50, 1, 1, 21 },
    { -45, 89, 1, 1, 21 },
    { -48, -44, 1, 1, 21 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 92, 1, 1, 22 },
    { -51, 78, 1, 1, 22 },
    { -46, 76, 1, 1, 22 },
    { -31, -2, 1, 1, 22 },
    { -47, 110, 1, 1, 22 },
    { -57, 95, 1, 1, 22 },
    { -80, -8, 1, 1, 22 },
    { -56, -9, 1, 1, 22 },
    { -47, 46, 1, 1, 22 },
    { -54, -6, 1, 1, 22 },
    { -31, -2, 1, 1, 22 },
    { -46, 76, 1, 1, 22 },
    { -46, 76, 1, 1, 22 },
    { -48, 92, 1, 1, 22 },
    { -46, 76, 1, 1, 22 },
    { -46, 76, 1, 1, 22 },
    { -69, -14, 1, 1, 22 },
    { -58, -36, 1, 1, 22 },
    { -69, 63, 1, 1, 22 },
    { -57, 108, 1, 1, 22 },
    { -56, -28, 1, 1, 22 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -46, -28, 1, 1, 23 },
    { -53, 80, 1, 1, 23 },
    { -48, 88, 1, 1, 23 },
    { -39, 9, 1, 1, 23 },
    { -45, 134, 1, 1, 23 },
    { -64, 106, 1, 1, 23 },
    { -73, -4, 1, 1, 23 },
    { -57, -3, 1, 1, 23 },
    { -65, 20, 1, 1, 23 },
    { -27, 73, 1, 1, 23 },
    { -48, 19, 1, 1, 23 },
    { -48, 88, 1, 1, 23 },
    { -48, 88, 1, 1, 23 },
    { -46, -28, 1, 1, 23 },
    { -48, 88, 1, 1, 23 },
    { -48, 88, 1, 1, 23 },
    { -66, -10, 1, 1, 23 },
    { -64, -8, 1, 1, 23 },
    { -76, 73, 1, 1, 23 },
    { -64, 125, 1, 1, 23 },
    { -58, -16, 1, 1, 23 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -46, -8, 1, 1, 24 },
    { -51, 94, 1, 1, 24 },
    { -43, 100, 1, 1, 24 },
    { -43, 20, 1, 1, 24 },
    { -71, 1, 1, 1, 24 },
    { -59, 107, 1, 1, 24 },
    { -78, 11, 1, 1, 24 },
    { -77, 8, 1, 1, 24 },
    { -67, 32, 1, 1, 24 },
    { -34, 88, 1, 1, 24 },
    { -43, 20, 1, 1, 24 },
    { -43, 100, 1, 1, 24 },
    { -43, 100, 1, 1, 24 },
    { -46, -8, 1, 1, 24 },
    { -43, 100, 1, 1, 24 },
    { -43, 100, 1, 1, 24 },
    { -58, 9, 1, 1, 24 },
    { -63, 13, 1, 1, 24 },
    { -81, 84, 1, 1, 24 },
    { -59, 128, 1, 1, 24 },
    { -78, -16, 1, 1, 24 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, -2, 1, 1, 25 },
    { -79, 33, 1, 1, 25 },
    { -56, 52, 1, 1, 25 },
    { -75, 31, 1, 1, 25 },
    { -58, 27, 1, 1, 25 },
    { -44, 125, 1, 1, 25 },
    { -66, 34, 1, 1, 25 },
    { -56, 29, 1, 1, 25 },
    { -75, 32, 1, 1, 25 },
    { -54, 64, 1, 1, 25 },
    { -75, 31, 1, 1, 25 },
    { -56, 52, 1, 1, 25 },
    { -56, 52, 1, 1, 25 },
    { -40, -2, 1, 1, 25 },
    { -56, 52, 1, 1, 25 },
    { -56, 52, 1, 1, 25 },
    { -52, 25, 1, 1, 25 },
    { -59, 56, 1, 1, 25 },
    { -77, 106, 1, 1, 25 },
    { -44, 146, 1, 1, 25 },
    { -72, 12, 1, 1, 25 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 72, 24, 1, 1, 26 },
    { 67, 23, 1, 1, 26 },
    { 68, 44, 1, 1, 26 },
    { 57, 56, 1, 1, 26 },
    { 72, 27, 1, 1, 26 },
    { 76, 40, 1, 1, 26 },
    { 74, 34, 1, 1, 26 },
    { 49, 29, 1, 1, 26 },
    { 66, 82, 1, 1, 26 },
    { 75, 57, 1, 1, 26 },
    { 57, 56, 1, 1, 26 },
    { 68, 44, 1, 1, 26 },
    { 68, 44, 1, 1, 26 },
    { 72, 24, 1, 1, 26 },
    { 68, 44, 1, 1, 26 },
    { 68, 44, 1, 1, 26 },
    { 70, 57, 1, 1, 26 },
    { 102, 75, 1, 1, 26 },
    { 103, 44, 1, 1, 26 },
    { 76, 40, 1, 1, 26 },
    { 30, 56, 1, 1, 26 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 96, 24, 1, 0, 27 },
    { 67, 39, 1, 0, 27 },
    { 68, 44, 1, 0, 27 },
    { 57, 56, 1, 0, 27 },
    { 72, 27, 1, 0, 27 },
    { 76, 40, 1, 0, 27 },
    { 100, 34, 1, 0, 27 },
    { 49, 29, 1, 0, 27 },
    { 66, 82, 1, 0, 27 },
    { 75, 57, 1, 0, 27 },
    { 57, 56, 1, 0, 27 },
    { 68, 44, 1, 0, 27 },
    { 68, 44, 1, 0, 27 },
    { 96, 24, 1, 0, 27 },
    { 68, 44, 1, 0, 27 },
    { 68, 44, 1, 0, 27 },
    { 71, 86, 1, 0, 27 },
    { 188, 34, 1, 0, 27 },
    { 134, 36, 1, 0, 27 },
    { 76, 40, 1, 0, 27 },
    { 88, 72, 1, 0, 27 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 43 entries */
const u16* const necro_exca[44] = {
    necro_exca_000,  /* 0 follow-up of AIR NORMAL */
    necro_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    necro_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    necro_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    necro_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    necro_exca_005,  /* 5 follow-up of TOMOE RYU, MONKEY FLIP +6 */
    necro_exca_006,  /* 6 follow-up of NOKEZORI, UPPER +20 */
    necro_exca_007,  /* 7 follow-up of KUNOJI, DUDDLEY D S */
    necro_exca_008,  /* 8 follow-up of TATAKI S, KGM TATAKI S +1 */
    necro_exca_009,  /* 9 follow-up of KIRIMOMI, FLANKEN.S +4 */
    necro_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    necro_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    necro_exca_012,  /* 12 follow-up of APPEAR JUNBI 4 */
    necro_exca_013,  /* 13 follow-up of APPEAR JUNBI 5 */
    necro_exca_014,  /* 14 no name */
    necro_exca_014,  /* 15 no name */
    necro_exca_014,  /* 16 no name */
    necro_exca_017,  /* 17 no name */
    necro_exca_014,  /* 18 no name */
    necro_exca_014,  /* 19 no name */
    necro_exca_014,  /* 20 no name */
    necro_exca_021,  /* 21 follow-up of HARAIGOSHI */
    necro_exca_014,  /* 22 no name */
    necro_exca_023,  /* 23 follow-up of APPEAR JUNBI 7 */
    necro_exca_024,  /* 24 follow-up of APPEAR JUNBI 7 */
    necro_exca_014,  /* 25 no name */
    necro_exca_026,  /* 26 follow-up of APPEAR 2 */
    necro_exca_027,  /* 27 follow-up of APPEAR 2 */
    necro_exca_028,  /* 28 follow-up of HUMI ASIB */
    necro_exca_029,  /* 29 follow-up of APPEAR JUNBI 5 */
    necro_exca_030,  /* 30 follow-up of SP APPEAR 6 */
    necro_exca_031,  /* 31 follow-up of SP APPEAR 6 */
    necro_exca_032,  /* 32 follow-up of GILL IMPACT C */
    necro_exca_033,  /* 33 follow-up of GILL IMPACT C */
    necro_exca_034,  /* 34 follow-up of SP APPEAR 7 */
    necro_exca_035,  /* 35 follow-up of SP APPEAR 7 */
    necro_exca_036,  /* 36 follow-up of ZANNEN 1 */
    necro_exca_037,  /* 37 follow-up of ZANNEN 1 */
    necro_exca_036,  /* 38 follow-up of ZANNEN 2 */
    necro_exca_037,  /* 39 follow-up of ZANNEN 2 */
    necro_exca_040,  /* 40 follow-up of ZANNEN 3 */
    necro_exca_041,  /* 41 follow-up of ZANNEN 3 */
    necro_exca_042,  /* 42 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 necro_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2178, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2179, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217A, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217B, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x217C, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217D, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217E, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x217E, 0, 158, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 158, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 158, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3 */
const u16 necro_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_001[60] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 necro_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_003[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 9, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 necro_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_004[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TOMOE RYU, MONKEY FLIP +6 */
const u16 necro_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_005[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, UPPER +20 */
const u16 necro_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_006[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, DUDDLEY D S */
const u16 necro_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_007[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2025, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2026, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI S, KGM TATAKI S +1 */
const u16 necro_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_008[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2025, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2026, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, FLANKEN.S +4 */
const u16 necro_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_009[84] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2050, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3 */
const u16 necro_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_010[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4 */
const u16 necro_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_012[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 5 */
const u16 necro_exca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_013[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name, 15 no name, 16 no name, 18 no name ... */
const u16 necro_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_014[20] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 necro_exca_017_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_017[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x2031, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x207C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x207B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x20D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x20D0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of HARAIGOSHI */
const u16 necro_exca_021_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_021[108] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 7 */
const u16 necro_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_023[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 7 */
const u16 necro_exca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_024[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 2 */
const u16 necro_exca_026_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_026[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR 2 */
const u16 necro_exca_027_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_027[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of HUMI ASIB */
const u16 necro_exca_028_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_028[100] = {
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR JUNBI 5 */
const u16 necro_exca_029_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_029[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of SP APPEAR 6 */
const u16 necro_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_030[60] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 174, 0, 0, 0, 21, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of SP APPEAR 6 */
const u16 necro_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_031[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 175, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of GILL IMPACT C */
const u16 necro_exca_032_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_032[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of GILL IMPACT C */
const u16 necro_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_033[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP APPEAR 7 */
const u16 necro_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_034[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 7 */
const u16 necro_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_035[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of ZANNEN 1, 38 follow-up of ZANNEN 2 */
const u16 necro_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_036[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of ZANNEN 1, 39 follow-up of ZANNEN 2 */
const u16 necro_exca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_037[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of ZANNEN 3 */
const u16 necro_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_040[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of ZANNEN 3 */
const u16 necro_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_041[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 necro_exca_042_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_042[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2178, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2179, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217A, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217B, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x217C, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217D, 0, 298, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217E, 0, 298, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x217E, 0, 298, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 300, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 299, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 299, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 67 entries */
const u16* const necro_saca[68] = {
    necro_saca_000,  /* 0 UP P GUARD P S */
    necro_saca_001,  /* 1 UP P GUARD P M */
    necro_saca_002,  /* 2 UP P GUARD P L */
    necro_saca_002,  /* 3 UP P GUARD K S */
    necro_saca_002,  /* 4 UP P GUARD K M */
    necro_saca_002,  /* 5 UP P GUARD K L */
    necro_saca_002,  /* 6 D P GUARD P S */
    necro_saca_002,  /* 7 D P GUARD P M */
    necro_saca_002,  /* 8 D P GUARD P L */
    necro_saca_002,  /* 9 D P GUARD K S */
    necro_saca_002,  /* 10 D P GUARD K M */
    necro_saca_002,  /* 11 D P GUARD K L */
    necro_saca_002,  /* 12 FUSHIN P S */
    necro_saca_002,  /* 13 FUSHIN P M */
    necro_saca_002,  /* 14 FUSHIN P L */
    necro_saca_002,  /* 15 FUSHIN K S */
    necro_saca_002,  /* 16 FUSHIN K M */
    necro_saca_002,  /* 17 FUSHIN K L */
    necro_saca_002,  /* 18 OKIAGARI P S */
    necro_saca_002,  /* 19 OKIAGARI P M */
    necro_saca_002,  /* 20 OKIAGARI P L */
    necro_saca_002,  /* 21 OKIAGARI K S */
    necro_saca_002,  /* 22 OKIAGARI K M */
    necro_saca_002,  /* 23 OKIAGARI K L */
    necro_saca_024,  /* 24 ATTACK 1 S: SA III 23623+P (plain script) */
    necro_saca_024,  /* 25 ATTACK 1 M: SA III 23623+P (plain script) */
    necro_saca_024,  /* 26 ATTACK 1 L: SA III 23623+P (plain script) */
    necro_saca_024,  /* 27 ATTACK 1 SP: SA III 23623+P (plain script) */
    necro_saca_028,  /* 28 ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI) */
    necro_saca_029,  /* 29 ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI) */
    necro_saca_030,  /* 30 ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
    necro_saca_031,  /* 31 ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    necro_saca_032,  /* 32 ATTACK 3 S: 623+P light (plain script) */
    necro_saca_033,  /* 33 ATTACK 3 M: 623+P medium (plain script) */
    necro_saca_034,  /* 34 ATTACK 3 L: 623+P heavy/EX (plain script) */
    necro_saca_034,  /* 35 ATTACK 3 SP: 623+P heavy/EX (plain script) */
    necro_saca_036,  /* 36 ATTACK 4 S: SA I 23623+P (plain script) */
    necro_saca_036,  /* 37 ATTACK 4 M: SA I 23623+P (plain script) */
    necro_saca_036,  /* 38 ATTACK 4 L: SA I 23623+P (plain script) */
    necro_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+P (plain script) */
    necro_saca_040,  /* 40 ATTACK 5 S: 1236+K light (plain script) */
    necro_saca_041,  /* 41 ATTACK 5 M: 1236+K medium (plain script) */
    necro_saca_042,  /* 42 ATTACK 5 L: 1236+K heavy/EX (plain script) */
    necro_saca_042,  /* 43 ATTACK 5 SP: 1236+K heavy/EX (plain script) */
    necro_saca_044,  /* 44 ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU) */
    necro_saca_045,  /* 45 ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU) */
    necro_saca_046,  /* 46 ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) */
    necro_saca_047,  /* 47 ATTACK 6 SP: EX 214+PP (routine Att_JINNCHUUWATARI) */
    necro_saca_048,  /* 48 ATTACK 7 S: SA II 23623+P (plain script) */
    necro_saca_048,  /* 49 ATTACK 7 M: SA II 23623+P (plain script) */
    necro_saca_000,  /* 50 ATTACK 7 L: not started by a command */
    necro_saca_000,  /* 51 ATTACK 7 SP: not started by a command */
    necro_saca_000,  /* 52 ATTACK 8 S: not started by a command */
    necro_saca_000,  /* 53 ATTACK 8 M: not started by a command */
    necro_saca_054,  /* 54 ATTACK 8 L: not started by a command */
    necro_saca_054,  /* 55 ATTACK 8 SP: not started by a command */
    necro_saca_054,  /* 56 ATTACK 9 S: not started by a command */
    necro_saca_054,  /* 57 ATTACK 9 M: not started by a command */
    necro_saca_058,  /* 58 ATTACK 9 L: 214+K light (plain script) */
    necro_saca_059,  /* 59 ATTACK 9 SP: 214+K medium (plain script) */
    necro_saca_060,  /* 60 ATTACK 10 S: 214+K heavy (plain script) */
    necro_saca_061,  /* 61 ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    necro_saca_062,  /* 62 ATTACK 10 L: not started by a command */
    necro_saca_063,  /* 63 ATTACK 10 SP: not started by a command */
    necro_saca_063,  /* 64 ATTACK 11 S: not started by a command */
    necro_saca_063,  /* 65 ATTACK 11 M: not started by a command */
    necro_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 50 ATTACK 7 L: not started by a command, 51 ATTACK 7 SP: not started by a command, 52 ATTACK 8 S: not started by a command ... */
const u16 necro_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A7, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AC, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AD, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AE, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AF, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70B1, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1024, 5632), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M */
const u16 necro_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 necro_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70B1, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70B0, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70B0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AE, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AD, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70AA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A8, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A7, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 necro_saca_002_head[4] = { HEAD(4, 0, 2, 13, 0, 3, 0) };
const u16 necro_saca_002[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E00, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: SA III 23623+P (plain script), 25 ATTACK 1 M: SA III 23623+P (plain script), 26 ATTACK 1 L: SA III 23623+P (plain script), 27 ATTACK 1 SP: SA III 23623+P (plain script) */
const u16 necro_saca_024_head[4] = { HEAD(6, 0, 32, 0, 0, 3, 41) };
const u16 necro_saca_024[244] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 810, 0, 0, 5, 0, 0x20F2, 0, 154, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 6, 0, 0x20F3, 0, 154, 0, 0, 0, 13, 9, 0, 0, 112, 0, 0),
    L6(48, 0, 0, 0, 0, 7, 0, 0x20F4, 0, 154, 0, 0, 0, 22, 32, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20F5, 0, 154, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(3, 0, 327, 0, 0, 8, 0, 0x20F5, 0, 161, 0, 0, 0, 2, 20, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 9, 0, 0x20F6, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F6, 0, 161, 0, 0, 0, 2, 20, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F7, 0, 161, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F8, 0, 161, 0, 0, 0, 2, 21, 0, 0, 120, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F9, 0, 161, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20FA, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FB, 0, 161, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FC, 0, 161, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FD, 0, 161, 0, 0, 0, 0, 0, 0, 0, 138, 0, 128),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI) */
const u16 necro_saca_028_head[4] = { HEAD(6, 0, 8, 12, 0, 2, 38) };
const u16 necro_saca_028[508] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -39, 140, 0, 160, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 161, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -40, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 39, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -41, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_END, 0, 0, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 necro_saca_029_head[4] = { HEAD(6, 0, 8, 12, 0, 2, 38) };
const u16 necro_saca_029[544] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -57, 140, 0, 162, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 163, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -58, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 57, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -59, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_END, 0, 0, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
const u16 necro_saca_030_head[4] = { HEAD(6, 0, 8, 12, 0, 3, 38) };
const u16 necro_saca_030[808] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 21, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 33, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -60, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -65, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    CMD(CM_HJMP, 16388, 16388, 16388), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -61, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -62, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_HJMP, 16401, 8197, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
const u16 necro_saca_031_head[4] = { HEAD(6, 0, 14, 12, 0, 5, 38) };
const u16 necro_saca_031[844] = {
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 21, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 33, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -86, 194, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -87, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    CMD(CM_MVIX, 49, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -87, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -88, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -89, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_HJMP, 16394, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 623+P light (plain script) */
const u16 necro_saca_032_head[4] = { HEAD(4, 0, 8, 6, 0, 3, 0) };
const u16 necro_saca_032[372] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 124, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 809, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 126, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 128, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 169, 0, 0, 64, 0, 0),
    CMD(CM_HJMP, 16388, 16388, 16388), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 169, 0, 0, 64, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, 0, 169, 0, 0, 64, 0, 0),
    CMD(CM_IXFW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 10), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 169, 0, 0, 64, 0, 0),
    CMD(CM_WCGT, 16392, 0, 16391), 0, 0, 0, 0,
    L4(3, 0, 328, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 169, 0, 0, 64, 0, 0),
    CMD(CM_WCGT, 16392, 0, 16388), 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 32, 20), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 32, 65),
    L4(2, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 32, 66),
    L4(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 32, 67),
    L4(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 32, 65),
    L4(1, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 32, 66),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 32, 67),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 623+P medium (plain script) */
const u16 necro_saca_033_head[4] = { HEAD(6, 0, 8, 7, 0, 3, 0) };
const u16 necro_saca_033[388] = {
    CMD(CM_RJA, 5, 33, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 809, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 171, 0, 0, 64, 0, 0, 0, 0, 128, 11, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 1, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 171, 0, 0, 64, 0, 0, 0, 0, 0, 14, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 1, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 171, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPP, 5, 33, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, 1, 32767), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16384, 10, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(14, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 623+P heavy/EX (plain script), 35 ATTACK 3 SP: 623+P heavy/EX (plain script) */
const u16 necro_saca_034_head[4] = { HEAD(6, 0, 8, 7, 0, 3, 0) };
const u16 necro_saca_034[436] = {
    CMD(CM_RJA, 5, 34, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 809, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 142, 0, 0, 64, 0, 0, 0, 0, 128, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, -67, 143, 0, 0, 64, 0, 0, 0, 0, 0, 13, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, -43, 143, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 142, 0, 0, 64, 0, 0, 0, 0, 0, 16, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 142, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, -67, 143, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0),
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, -43, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 142, 0, 0, 0, 0, 0, 0, 0, 0, 22, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPP, 5, 34, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, 1, 32767), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16384, 10, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(14, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+P (plain script), 37 ATTACK 4 M: SA I 23623+P (plain script), 38 ATTACK 4 L: SA I 23623+P (plain script), 39 ATTACK 4 SP: SA I 23623+P (plain script) */
const u16 necro_saca_036_head[4] = { HEAD(6, 0, 32, 11, 0, 14, 0) };
const u16 necro_saca_036[496] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 154, 0, 0, 0, 13, 6, 785, 0, 0, 0, 0),
    L6(49, 0, 0, 0, 0, 0, 0, 0x211C, 0, 154, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 154, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 814, 0, 0, 0, 0, 0x211F, 0, 154, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x2120, 0, 154, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x2159, -56, 144, 0, 128, 0, 0, 0, 0, 0, 128, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x215C, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -45, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 36, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 36, 31), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 21, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x215C, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 25, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -45, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 29, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x215B, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 0, 0, 0, 0, 4, 0, 0x2122, -78, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 21, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: 1236+K light (plain script) */
const u16 necro_saca_040_head[4] = { HEAD(6, 0, 25, 17, 0, 1, 24) };
const u16 necro_saca_040[124] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 806, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 1236+K medium (plain script) */
const u16 necro_saca_041_head[4] = { HEAD(6, 0, 25, 18, 0, 1, 24) };
const u16 necro_saca_041[124] = {
    CMD(CM_CAFR, 2, 1, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 806, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 1236+K heavy/EX (plain script), 43 ATTACK 5 SP: 1236+K heavy/EX (plain script) */
const u16 necro_saca_042_head[4] = { HEAD(6, 0, 25, 19, 0, 1, 24) };
const u16 necro_saca_042[124] = {
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 806, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 23), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU) */
const u16 necro_saca_044_head[4] = { HEAD(4, 22, 8, 13, 0, 1, 40) };
const u16 necro_saca_044[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 807, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 7, 0x1EC8, -18, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU) */
const u16 necro_saca_045_head[4] = { HEAD(4, 22, 10, 13, 0, 1, 40) };
const u16 necro_saca_045[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 807, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(5, 0, 269, 0, 0, 0, 7, 0x1EC8, -63, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) */
const u16 necro_saca_046_head[4] = { HEAD(4, 22, 12, 13, 0, 1, 40) };
const u16 necro_saca_046[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 807, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 269, 0, 0, 0, 7, 0x1EC8, -64, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: EX 214+PP (routine Att_JINNCHUUWATARI) */
const u16 necro_saca_047_head[4] = { HEAD(4, 22, 14, 13, 0, 2, 40) };
const u16 necro_saca_047[204] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 807, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(3, 1, 269, 0, 0, 0, 7, 0x1EC8, -81, 191, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    L4(1, 1, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 8), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(1, 0, 807, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 1, 269, 0, 0, 0, 7, 0x1EC8, -82, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA II 23623+P (plain script), 49 ATTACK 7 M: SA II 23623+P (plain script) */
const u16 necro_saca_048_head[4] = { HEAD(6, 0, 57, 12, 0, 0, 37) };
const u16 necro_saca_048[364] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 0, 0, 0, 0, 0, 0x2096, 0, 154, 0, 0, 0, 13, 20, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2097, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2098, -52, 148, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 131, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0002, 0x0B00, 0x0C00, 0x0300, 0x0000, 0x0000, 0x2003,
    CMD(CM_UJA2, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x2005, 0x0013, 0x0000, 0x0000, 0x0000,
    L6(3, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0, 768, 0, 0, 32, 28),
    CMD(CM_UJA2, 8192, 0, 0), 0x0300, 0x0000, 0x0000, 0x201D, 0x0013, 0x2000, 0x0000, 0x0000,
    L6(4, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 0, 0, 512, 0, 0, 32, 31),
    CMD(CM_FOR2, -24576, 0, 0), 0x0200, 0x0000, 0x0000, 0x2020, 0x000E, 0xA000, 0x0000, 0x0000,
    L6(1, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0, 512, 0, 0, 32, 34),
    L6(248, 14, 3584, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 32, 35, 63503, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0, 1024, 0, 0, 31, 216),
    CMD(CM_DUMMY, 16384, 0, 0), 0x000A, 0x0002, 0x4005, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000,
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 1024, 0, 0, 30, 60),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3D, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 32),
    CMD(CM_DUMMY, 0, 0, 0), 0x0440, 0x0000, 0x0000, 0x1E22, 0x0000, 0x4000, 0x0000, 0x0000,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 1024, 0, 0, 30, 36),
    CMD(CM_DUMMY, 16384, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x1E24, 0x0000, 0x4000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command */
const u16 necro_saca_054_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 33) };
const u16 necro_saca_054[76] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 262, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F60, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F61, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F62, -91, 162, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1F63, 0, 162, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: 214+K light (plain script) */
const u16 necro_saca_058_head[4] = { HEAD(4, 0, 9, 13, 0, 1, 0) };
const u16 necro_saca_058[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 809, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -70, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: 214+K medium (plain script) */
const u16 necro_saca_059_head[4] = { HEAD(4, 0, 11, 13, 0, 1, 0) };
const u16 necro_saca_059[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(1, 0, 809, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -71, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: 214+K heavy (plain script) */
const u16 necro_saca_060_head[4] = { HEAD(4, 0, 13, 13, 0, 1, 0) };
const u16 necro_saca_060[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(2, 0, 809, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -72, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
const u16 necro_saca_061_head[4] = { HEAD(4, 0, 15, 13, 0, 2, 0) };
const u16 necro_saca_061[204] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 30, 809, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -83, 192, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x2023, -84, 193, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: not started by a command */
const u16 necro_saca_062_head[4] = { HEAD(6, 0, 8, 12, 0, 0, 38) };
const u16 necro_saca_062[196] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: not started by a command, 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command */
const u16 necro_saca_063_head[4] = { HEAD(4, 0, 0, 13, 0, 3, 0) };
const u16 necro_saca_063[188] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x225C, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x225D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x225E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x225F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2260, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 40, 817, 0, 0, 0, 0, 0x2261, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2262, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x2263, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2264, -31, 188, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2265, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x2266, -31, 188, 0, 0, 0, 21, 0),
    CMD(CM_IF_S, 1088, -32763, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2267, 0, 26, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2268, 0, 26, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2269, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x226A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command */
const u16 necro_saca_066_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_saca_066[500] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0019, 0x1100, 0x0118,
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0024, 0x0002, 0x0001, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x1F32,
    CMD(CM_NEX2, 24576, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x3260, 0x0000, 0x20DF,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00BC, 0x0000,
    L4(1, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 190, 0), 0x0100, 0x0000, 0x0000, 0x20E1,
    CMD(CM_RJA4, 16384, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 192, 0), 0x0500, 0x0000, 0x0000, 0x20E1,
    CMD(CM_RJA4, 16384, 0, 5376), 0, 0, 0, 0,
    CMD(CM_JMP, 2, 4, 1), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 25, 4352, 280), 0x0023, 0x0002, 0x0001, 0x0008,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 10), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x1F31,
    CMD(CM_NEX2, 16384, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x1F33,
    CMD(CM_NEX2, 24576, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 806, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 188, 0), 0x0300, 0x0000, 0x0000, 0x20E0,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00BE, 0x0000,
    L4(1, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 192, 0), 0x0200, 0x0000, 0x0000, 0x20E1,
    L4(246, 207, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 21, 0),
    CMD(CM_DUMMY, 0, 192, 0), 0x0003, 0x0002, 0x0004, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0019, 0x1000, 0x0118,
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0024, 0x0002, 0x0001, 0x000B,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x1F32,
    CMD(CM_NEX2, 24576, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x3260, 0x0000, 0x20DF,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00BC, 0x0000,
    L4(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 190, 0), 0x0300, 0x0000, 0x0000, 0x20E1,
    CMD(CM_RJA4, 16384, 0, 0), 0x0000, 0x0000, 0x00C0, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0003, 0x0002, 0x0004, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 30 entries */
const u16* const necro_cbca[31] = {
    necro_cbca_000,  /* 0 APPEAR JUNBI 1 */
    necro_cbca_001,  /* 1 APPEAR JUNBI 2 */
    necro_cbca_002,  /* 2 APPEAR JUNBI 3 */
    necro_cbca_003,  /* 3 APPEAR JUNBI 4 */
    necro_cbca_004,  /* 4 APPEAR JUNBI 5 */
    necro_cbca_005,  /* 5 APPEAR JUNBI 6 */
    necro_cbca_006,  /* 6 APPEAR JUNBI 7 */
    necro_cbca_007,  /* 7 APPEAR JUNBI 8 */
    necro_cbca_008,  /* 8 APPEAR 1 */
    necro_cbca_009,  /* 9 APPEAR 2 */
    necro_cbca_010,  /* 10 APPEAR 3 */
    necro_cbca_011,  /* 11 APPEAR 4 */
    necro_cbca_012,  /* 12 APPEAR 5 */
    necro_cbca_013,  /* 13 APPEAR 6 */
    necro_cbca_014,  /* 14 APPEAR 7 */
    necro_cbca_015,  /* 15 APPEAR 8 */
    necro_cbca_016,  /* 16 SP APPEAR 1 */
    necro_cbca_017,  /* 17 SP APPEAR 2 */
    necro_cbca_018,  /* 18 SP APPEAR 3 */
    necro_cbca_019,  /* 19 SP APPEAR 4 */
    necro_cbca_020,  /* 20 SP APPEAR 5 */
    necro_cbca_021,  /* 21 SP APPEAR 6 */
    necro_cbca_022,  /* 22 SP APPEAR 7 */
    necro_cbca_023,  /* 23 SP APPEAR 8 */
    necro_cbca_024,  /* 24 ZANNEN 1 */
    necro_cbca_025,  /* 25 ZANNEN 2 */
    necro_cbca_026,  /* 26 ZANNEN 3 */
    necro_cbca_027,  /* 27 ZANNEN 4 */
    necro_cbca_028,  /* 28 ZANNEN 5 */
    necro_cbca_029,  /* 29 ZANNEN 6 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 necro_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 necro_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 necro_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 necro_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 necro_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 13, 1),
    CMD(CM_RJA3, 7, 29, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 necro_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_005[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 necro_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 necro_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_007[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 8, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 8 APPEAR 1 */
const u16 necro_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_008[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 17, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 9 APPEAR 2 */
const u16 necro_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_009[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 necro_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 6),
    CMD(CM_CARE, 2, 1, 6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 necro_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_011[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 7),
    CMD(CM_CARE, 2, 1, 7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 necro_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_012[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 necro_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_013[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 56, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 necro_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_014[16] = {
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 necro_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_015[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 5, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 16 SP APPEAR 1 */
const u16 necro_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_016[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 3, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 17 SP APPEAR 2 */
const u16 necro_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_017[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 14, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 18 SP APPEAR 3 */
const u16 necro_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_018[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 12, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 19 SP APPEAR 4 */
const u16 necro_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_019[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 7, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 20 SP APPEAR 5 */
const u16 necro_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_020[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 21 SP APPEAR 6 */
const u16 necro_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_021[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 necro_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_022[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 necro_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_023[8] = {
    CMD(CM_RJA4, 5, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 necro_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 necro_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_025[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 necro_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_026[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 necro_cbca_027_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 necro_cbca_027[16] = {
    CMD(CM_EXEC, 49, 25, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 necro_cbca_028_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 necro_cbca_028[16] = {
    CMD(CM_EXEC, 49, 26, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 necro_cbca_029_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 necro_cbca_029[16] = {
    CMD(CM_EXEC, 49, 27, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

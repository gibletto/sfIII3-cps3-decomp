/*
 * KEN_CHAR.C  Ken's animation scripts and sprite part tables
 *
 * The animation scripts Ken's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 ken_nmca_000[], ken_nmca_001[], ken_nmca_002[], ken_nmca_003[], ken_nmca_004[], ken_nmca_005[], ken_nmca_006[], ken_nmca_007[], ken_nmca_008[], ken_nmca_011[], ken_nmca_012[], ken_nmca_013[], ken_nmca_014[], ken_nmca_015[], ken_nmca_016[], ken_nmca_017[], ken_nmca_020[], ken_nmca_021[], ken_nmca_022[], ken_nmca_023[], ken_nmca_024[], ken_nmca_026[], ken_nmca_027[], ken_nmca_029[], ken_nmca_030[], ken_nmca_031[], ken_nmca_032[], ken_nmca_033[], ken_nmca_038[], ken_nmca_040[], ken_nmca_041[], ken_nmca_043[], ken_nmca_044[], ken_nmca_045[], ken_nmca_046[], ken_nmca_047[], ken_nmca_048[], ken_nmca_049[], ken_nmca_050[];
extern const u16 ken_nmca_000_head[];
extern const u16 ken_nmca_001_head[];
extern const u16 ken_nmca_002_head[];
extern const u16 ken_nmca_003_head[];
extern const u16 ken_nmca_004_head[];
extern const u16 ken_nmca_005_head[];
extern const u16 ken_nmca_006_head[];
extern const u16 ken_nmca_007_head[];
extern const u16 ken_nmca_008_head[];
extern const u16 ken_nmca_011_head[];
extern const u16 ken_nmca_012_head[];
extern const u16 ken_nmca_013_head[];
extern const u16 ken_nmca_014_head[];
extern const u16 ken_nmca_015_head[];
extern const u16 ken_nmca_016_head[];
extern const u16 ken_nmca_017_head[];
extern const u16 ken_nmca_020_head[];
extern const u16 ken_nmca_021_head[];
extern const u16 ken_nmca_022_head[];
extern const u16 ken_nmca_023_head[];
extern const u16 ken_nmca_024_head[];
extern const u16 ken_nmca_026_head[];
extern const u16 ken_nmca_027_head[];
extern const u16 ken_nmca_029_head[];
extern const u16 ken_nmca_030_head[];
extern const u16 ken_nmca_031_head[];
extern const u16 ken_nmca_032_head[];
extern const u16 ken_nmca_033_head[];
extern const u16 ken_nmca_038_head[];
extern const u16 ken_nmca_040_head[];
extern const u16 ken_nmca_041_head[];
extern const u16 ken_nmca_043_head[];
extern const u16 ken_nmca_044_head[];
extern const u16 ken_nmca_045_head[];
extern const u16 ken_nmca_046_head[];
extern const u16 ken_nmca_047_head[];
extern const u16 ken_nmca_048_head[];
extern const u16 ken_nmca_049_head[];
extern const u16 ken_nmca_050_head[];
extern const u16 ken_dmca_000[], ken_dmca_001[], ken_dmca_002[], ken_dmca_003[], ken_dmca_004[], ken_dmca_006[], ken_dmca_008[], ken_dmca_009[], ken_dmca_010[], ken_dmca_014[], ken_dmca_015[], ken_dmca_018[], ken_dmca_019[], ken_dmca_022[], ken_dmca_025[], ken_dmca_026[], ken_dmca_024[], ken_dmca_029[], ken_dmca_030[], ken_dmca_034[], ken_dmca_036[], ken_dmca_048[], ken_dmca_049[], ken_dmca_050[], ken_dmca_052[], ken_dmca_060[], ken_dmca_064[], ken_dmca_065[], ken_dmca_066[], ken_dmca_067[], ken_dmca_068[], ken_dmca_070[], ken_dmca_071[], ken_dmca_072[], ken_dmca_073[], ken_dmca_074[], ken_dmca_075[], ken_dmca_076[], ken_dmca_078[], ken_dmca_079[], ken_dmca_080[], ken_dmca_082[], ken_dmca_083[], ken_dmca_084[], ken_dmca_090[], ken_dmca_091[], ken_dmca_096[], ken_dmca_097[];
extern const u16 ken_dmca_000_head[];
extern const u16 ken_dmca_001_head[];
extern const u16 ken_dmca_002_head[];
extern const u16 ken_dmca_003_head[];
extern const u16 ken_dmca_004_head[];
extern const u16 ken_dmca_006_head[];
extern const u16 ken_dmca_008_head[];
extern const u16 ken_dmca_009_head[];
extern const u16 ken_dmca_010_head[];
extern const u16 ken_dmca_014_head[];
extern const u16 ken_dmca_015_head[];
extern const u16 ken_dmca_018_head[];
extern const u16 ken_dmca_019_head[];
extern const u16 ken_dmca_022_head[];
extern const u16 ken_dmca_025_head[];
extern const u16 ken_dmca_026_head[];
extern const u16 ken_dmca_024_head[];
extern const u16 ken_dmca_029_head[];
extern const u16 ken_dmca_030_head[];
extern const u16 ken_dmca_034_head[];
extern const u16 ken_dmca_036_head[];
extern const u16 ken_dmca_048_head[];
extern const u16 ken_dmca_049_head[];
extern const u16 ken_dmca_050_head[];
extern const u16 ken_dmca_052_head[];
extern const u16 ken_dmca_060_head[];
extern const u16 ken_dmca_064_head[];
extern const u16 ken_dmca_065_head[];
extern const u16 ken_dmca_066_head[];
extern const u16 ken_dmca_067_head[];
extern const u16 ken_dmca_068_head[];
extern const u16 ken_dmca_070_head[];
extern const u16 ken_dmca_071_head[];
extern const u16 ken_dmca_072_head[];
extern const u16 ken_dmca_073_head[];
extern const u16 ken_dmca_074_head[];
extern const u16 ken_dmca_075_head[];
extern const u16 ken_dmca_076_head[];
extern const u16 ken_dmca_078_head[];
extern const u16 ken_dmca_079_head[];
extern const u16 ken_dmca_080_head[];
extern const u16 ken_dmca_082_head[];
extern const u16 ken_dmca_083_head[];
extern const u16 ken_dmca_084_head[];
extern const u16 ken_dmca_090_head[];
extern const u16 ken_dmca_091_head[];
extern const u16 ken_dmca_096_head[];
extern const u16 ken_dmca_097_head[];
extern const u16 ken_btca_000[], ken_btca_001[], ken_btca_002[], ken_btca_003[], ken_btca_004[], ken_btca_005[], ken_btca_006[], ken_btca_007[], ken_btca_008[], ken_btca_009[], ken_btca_010[], ken_btca_011[], ken_btca_012[], ken_btca_013[], ken_btca_014[], ken_btca_015[], ken_btca_016[], ken_btca_017[], ken_btca_018[], ken_btca_019[], ken_btca_020[], ken_btca_021[], ken_btca_022[], ken_btca_023[], ken_btca_024[], ken_btca_025[], ken_btca_026[], ken_btca_027[], ken_btca_028[], ken_btca_029[], ken_btca_030[], ken_btca_031[], ken_btca_032[], ken_btca_033[], ken_btca_034[], ken_btca_035[];
extern const u16 ken_btca_000_head[];
extern const u16 ken_btca_001_head[];
extern const u16 ken_btca_002_head[];
extern const u16 ken_btca_003_head[];
extern const u16 ken_btca_004_head[];
extern const u16 ken_btca_005_head[];
extern const u16 ken_btca_006_head[];
extern const u16 ken_btca_007_head[];
extern const u16 ken_btca_008_head[];
extern const u16 ken_btca_009_head[];
extern const u16 ken_btca_010_head[];
extern const u16 ken_btca_011_head[];
extern const u16 ken_btca_012_head[];
extern const u16 ken_btca_013_head[];
extern const u16 ken_btca_014_head[];
extern const u16 ken_btca_015_head[];
extern const u16 ken_btca_016_head[];
extern const u16 ken_btca_017_head[];
extern const u16 ken_btca_018_head[];
extern const u16 ken_btca_019_head[];
extern const u16 ken_btca_020_head[];
extern const u16 ken_btca_021_head[];
extern const u16 ken_btca_022_head[];
extern const u16 ken_btca_023_head[];
extern const u16 ken_btca_024_head[];
extern const u16 ken_btca_025_head[];
extern const u16 ken_btca_026_head[];
extern const u16 ken_btca_027_head[];
extern const u16 ken_btca_028_head[];
extern const u16 ken_btca_029_head[];
extern const u16 ken_btca_030_head[];
extern const u16 ken_btca_031_head[];
extern const u16 ken_btca_032_head[];
extern const u16 ken_btca_033_head[];
extern const u16 ken_btca_034_head[];
extern const u16 ken_btca_035_head[];
extern const u16 ken_caca_000[], ken_caca_002[], ken_caca_004[], ken_caca_008[], ken_caca_010[], ken_caca_012[], ken_caca_014[], ken_caca_018[], ken_caca_019[], ken_caca_020[], ken_caca_021[];
extern const u16 ken_caca_000_head[];
extern const u16 ken_caca_002_head[];
extern const u16 ken_caca_004_head[];
extern const u16 ken_caca_008_head[];
extern const u16 ken_caca_010_head[];
extern const u16 ken_caca_012_head[];
extern const u16 ken_caca_014_head[];
extern const u16 ken_caca_018_head[];
extern const u16 ken_caca_019_head[];
extern const u16 ken_caca_020_head[];
extern const u16 ken_caca_021_head[];
extern const u16 ken_cuca_000[], ken_cuca_001[], ken_cuca_002[], ken_cuca_003[], ken_cuca_004[], ken_cuca_005[], ken_cuca_006[], ken_cuca_007[], ken_cuca_008[], ken_cuca_009[], ken_cuca_010[], ken_cuca_011[], ken_cuca_012[], ken_cuca_013[], ken_cuca_014[], ken_cuca_015[], ken_cuca_016[], ken_cuca_017[], ken_cuca_018[], ken_cuca_019[], ken_cuca_020[], ken_cuca_021[], ken_cuca_022[], ken_cuca_023[], ken_cuca_024[], ken_cuca_025[], ken_cuca_026[], ken_cuca_027[], ken_cuca_028[], ken_cuca_029[], ken_cuca_030[], ken_cuca_031[], ken_cuca_032[], ken_cuca_033[], ken_cuca_034[], ken_cuca_035[], ken_cuca_036[], ken_cuca_037[], ken_cuca_038[], ken_cuca_039[], ken_cuca_040[], ken_cuca_041[], ken_cuca_042[], ken_cuca_043[], ken_cuca_044[], ken_cuca_045[], ken_cuca_046[], ken_cuca_047[], ken_cuca_048[], ken_cuca_049[], ken_cuca_050[], ken_cuca_051[], ken_cuca_052[], ken_cuca_053[], ken_cuca_054[], ken_cuca_055[], ken_cuca_056[], ken_cuca_057[], ken_cuca_058[], ken_cuca_059[], ken_cuca_060[], ken_cuca_061[], ken_cuca_062[], ken_cuca_063[], ken_cuca_064[], ken_cuca_065[], ken_cuca_066[], ken_cuca_067[];
extern const u16 ken_cuca_000_head[];
extern const u16 ken_cuca_001_head[];
extern const u16 ken_cuca_002_head[];
extern const u16 ken_cuca_003_head[];
extern const u16 ken_cuca_004_head[];
extern const u16 ken_cuca_005_head[];
extern const u16 ken_cuca_006_head[];
extern const u16 ken_cuca_007_head[];
extern const u16 ken_cuca_008_head[];
extern const u16 ken_cuca_009_head[];
extern const u16 ken_cuca_010_head[];
extern const u16 ken_cuca_011_head[];
extern const u16 ken_cuca_012_head[];
extern const u16 ken_cuca_013_head[];
extern const u16 ken_cuca_014_head[];
extern const u16 ken_cuca_015_head[];
extern const u16 ken_cuca_016_head[];
extern const u16 ken_cuca_017_head[];
extern const u16 ken_cuca_018_head[];
extern const u16 ken_cuca_019_head[];
extern const u16 ken_cuca_020_head[];
extern const u16 ken_cuca_021_head[];
extern const u16 ken_cuca_022_head[];
extern const u16 ken_cuca_023_head[];
extern const u16 ken_cuca_024_head[];
extern const u16 ken_cuca_025_head[];
extern const u16 ken_cuca_026_head[];
extern const u16 ken_cuca_027_head[];
extern const u16 ken_cuca_028_head[];
extern const u16 ken_cuca_029_head[];
extern const u16 ken_cuca_030_head[];
extern const u16 ken_cuca_031_head[];
extern const u16 ken_cuca_032_head[];
extern const u16 ken_cuca_033_head[];
extern const u16 ken_cuca_034_head[];
extern const u16 ken_cuca_035_head[];
extern const u16 ken_cuca_036_head[];
extern const u16 ken_cuca_037_head[];
extern const u16 ken_cuca_038_head[];
extern const u16 ken_cuca_039_head[];
extern const u16 ken_cuca_040_head[];
extern const u16 ken_cuca_041_head[];
extern const u16 ken_cuca_042_head[];
extern const u16 ken_cuca_043_head[];
extern const u16 ken_cuca_044_head[];
extern const u16 ken_cuca_045_head[];
extern const u16 ken_cuca_046_head[];
extern const u16 ken_cuca_047_head[];
extern const u16 ken_cuca_048_head[];
extern const u16 ken_cuca_049_head[];
extern const u16 ken_cuca_050_head[];
extern const u16 ken_cuca_051_head[];
extern const u16 ken_cuca_052_head[];
extern const u16 ken_cuca_053_head[];
extern const u16 ken_cuca_054_head[];
extern const u16 ken_cuca_055_head[];
extern const u16 ken_cuca_056_head[];
extern const u16 ken_cuca_057_head[];
extern const u16 ken_cuca_058_head[];
extern const u16 ken_cuca_059_head[];
extern const u16 ken_cuca_060_head[];
extern const u16 ken_cuca_061_head[];
extern const u16 ken_cuca_062_head[];
extern const u16 ken_cuca_063_head[];
extern const u16 ken_cuca_064_head[];
extern const u16 ken_cuca_065_head[];
extern const u16 ken_cuca_066_head[];
extern const u16 ken_cuca_067_head[];
extern const u16 ken_atca_161[], ken_atca_162[], ken_atca_163[], ken_atca_164[], ken_atca_165[], ken_atca_166[], ken_atca_167[], ken_atca_168[], ken_atca_169[], ken_atca_000[], ken_atca_001[], ken_atca_003[], ken_atca_004[], ken_atca_006[], ken_atca_007[], ken_atca_009[], ken_atca_012[], ken_atca_013[], ken_atca_014[], ken_atca_015[], ken_atca_017[], ken_atca_018[], ken_atca_021[], ken_atca_024[], ken_atca_027[], ken_atca_030[], ken_atca_033[], ken_atca_036[], ken_atca_038[], ken_atca_040[], ken_atca_042[], ken_atca_044[], ken_atca_046[], ken_atca_048[], ken_atca_050[], ken_atca_052[], ken_atca_054[], ken_atca_056[], ken_atca_058[], ken_atca_060[], ken_atca_062[], ken_atca_064[], ken_atca_066[], ken_atca_068[], ken_atca_070[], ken_atca_072[], ken_atca_074[], ken_atca_076[], ken_atca_078[], ken_atca_080[], ken_atca_082[], ken_atca_084[], ken_atca_086[], ken_atca_088[], ken_atca_090[], ken_atca_092[], ken_atca_094[], ken_atca_096[], ken_atca_098[], ken_atca_100[], ken_atca_102[], ken_atca_104[], ken_atca_106[], ken_atca_108[], ken_atca_110[], ken_atca_112[], ken_atca_114[], ken_atca_116[], ken_atca_118[], ken_atca_144[], ken_atca_145[], ken_atca_146[], ken_atca_156[], ken_atca_157[], ken_atca_158[], ken_atca_159[], ken_atca_160[];
extern const u16 ken_atca_161_head[];
extern const u16 ken_atca_162_head[];
extern const u16 ken_atca_163_head[];
extern const u16 ken_atca_164_head[];
extern const u16 ken_atca_165_head[];
extern const u16 ken_atca_166_head[];
extern const u16 ken_atca_167_head[];
extern const u16 ken_atca_168_head[];
extern const u16 ken_atca_169_head[];
extern const u16 ken_atca_000_head[];
extern const u16 ken_atca_001_head[];
extern const u16 ken_atca_003_head[];
extern const u16 ken_atca_004_head[];
extern const u16 ken_atca_006_head[];
extern const u16 ken_atca_007_head[];
extern const u16 ken_atca_009_head[];
extern const u16 ken_atca_012_head[];
extern const u16 ken_atca_013_head[];
extern const u16 ken_atca_014_head[];
extern const u16 ken_atca_015_head[];
extern const u16 ken_atca_017_head[];
extern const u16 ken_atca_018_head[];
extern const u16 ken_atca_021_head[];
extern const u16 ken_atca_024_head[];
extern const u16 ken_atca_027_head[];
extern const u16 ken_atca_030_head[];
extern const u16 ken_atca_033_head[];
extern const u16 ken_atca_036_head[];
extern const u16 ken_atca_038_head[];
extern const u16 ken_atca_040_head[];
extern const u16 ken_atca_042_head[];
extern const u16 ken_atca_044_head[];
extern const u16 ken_atca_046_head[];
extern const u16 ken_atca_048_head[];
extern const u16 ken_atca_050_head[];
extern const u16 ken_atca_052_head[];
extern const u16 ken_atca_054_head[];
extern const u16 ken_atca_056_head[];
extern const u16 ken_atca_058_head[];
extern const u16 ken_atca_060_head[];
extern const u16 ken_atca_062_head[];
extern const u16 ken_atca_064_head[];
extern const u16 ken_atca_066_head[];
extern const u16 ken_atca_068_head[];
extern const u16 ken_atca_070_head[];
extern const u16 ken_atca_072_head[];
extern const u16 ken_atca_074_head[];
extern const u16 ken_atca_076_head[];
extern const u16 ken_atca_078_head[];
extern const u16 ken_atca_080_head[];
extern const u16 ken_atca_082_head[];
extern const u16 ken_atca_084_head[];
extern const u16 ken_atca_086_head[];
extern const u16 ken_atca_088_head[];
extern const u16 ken_atca_090_head[];
extern const u16 ken_atca_092_head[];
extern const u16 ken_atca_094_head[];
extern const u16 ken_atca_096_head[];
extern const u16 ken_atca_098_head[];
extern const u16 ken_atca_100_head[];
extern const u16 ken_atca_102_head[];
extern const u16 ken_atca_104_head[];
extern const u16 ken_atca_106_head[];
extern const u16 ken_atca_108_head[];
extern const u16 ken_atca_110_head[];
extern const u16 ken_atca_112_head[];
extern const u16 ken_atca_114_head[];
extern const u16 ken_atca_116_head[];
extern const u16 ken_atca_118_head[];
extern const u16 ken_atca_144_head[];
extern const u16 ken_atca_145_head[];
extern const u16 ken_atca_146_head[];
extern const u16 ken_atca_156_head[];
extern const u16 ken_atca_157_head[];
extern const u16 ken_atca_158_head[];
extern const u16 ken_atca_159_head[];
extern const u16 ken_atca_160_head[];
extern const u16 ken_exca_000[], ken_exca_001[], ken_exca_003[], ken_exca_004[], ken_exca_005[], ken_exca_006[], ken_exca_007[], ken_exca_008[], ken_exca_009[], ken_exca_010[], ken_exca_011[], ken_exca_013[], ken_exca_014[], ken_exca_015[], ken_exca_016[], ken_exca_017[], ken_exca_018[], ken_exca_019[], ken_exca_020[], ken_exca_021[], ken_exca_022[], ken_exca_023[], ken_exca_024[], ken_exca_025[], ken_exca_026[], ken_exca_028[], ken_exca_029[], ken_exca_030[], ken_exca_031[], ken_exca_032[], ken_exca_033[], ken_exca_034[], ken_exca_035[], ken_exca_036[], ken_exca_037[], ken_exca_038[], ken_exca_039[], ken_exca_042[], ken_exca_043[], ken_exca_044[], ken_exca_045[];
extern const u16 ken_exca_000_head[];
extern const u16 ken_exca_001_head[];
extern const u16 ken_exca_003_head[];
extern const u16 ken_exca_004_head[];
extern const u16 ken_exca_005_head[];
extern const u16 ken_exca_006_head[];
extern const u16 ken_exca_007_head[];
extern const u16 ken_exca_008_head[];
extern const u16 ken_exca_009_head[];
extern const u16 ken_exca_010_head[];
extern const u16 ken_exca_011_head[];
extern const u16 ken_exca_013_head[];
extern const u16 ken_exca_014_head[];
extern const u16 ken_exca_015_head[];
extern const u16 ken_exca_016_head[];
extern const u16 ken_exca_017_head[];
extern const u16 ken_exca_018_head[];
extern const u16 ken_exca_019_head[];
extern const u16 ken_exca_020_head[];
extern const u16 ken_exca_021_head[];
extern const u16 ken_exca_022_head[];
extern const u16 ken_exca_023_head[];
extern const u16 ken_exca_024_head[];
extern const u16 ken_exca_025_head[];
extern const u16 ken_exca_026_head[];
extern const u16 ken_exca_028_head[];
extern const u16 ken_exca_029_head[];
extern const u16 ken_exca_030_head[];
extern const u16 ken_exca_031_head[];
extern const u16 ken_exca_032_head[];
extern const u16 ken_exca_033_head[];
extern const u16 ken_exca_034_head[];
extern const u16 ken_exca_035_head[];
extern const u16 ken_exca_036_head[];
extern const u16 ken_exca_037_head[];
extern const u16 ken_exca_038_head[];
extern const u16 ken_exca_039_head[];
extern const u16 ken_exca_042_head[];
extern const u16 ken_exca_043_head[];
extern const u16 ken_exca_044_head[];
extern const u16 ken_exca_045_head[];
extern const u16 ken_saca_000[], ken_saca_001[], ken_saca_002[], ken_saca_024[], ken_saca_025[], ken_saca_026[], ken_saca_027[], ken_saca_028[], ken_saca_029[], ken_saca_030[], ken_saca_031[], ken_saca_032[], ken_saca_033[], ken_saca_034[], ken_saca_035[], ken_saca_036[], ken_saca_040[], ken_saca_044[], ken_saca_052[], ken_saca_048[], ken_saca_049[], ken_saca_050[], ken_saca_051[], ken_saca_053[], ken_saca_057[], ken_saca_061[], ken_saca_064[];
extern const u16 ken_saca_000_head[];
extern const u16 ken_saca_001_head[];
extern const u16 ken_saca_002_head[];
extern const u16 ken_saca_024_head[];
extern const u16 ken_saca_025_head[];
extern const u16 ken_saca_026_head[];
extern const u16 ken_saca_027_head[];
extern const u16 ken_saca_028_head[];
extern const u16 ken_saca_029_head[];
extern const u16 ken_saca_030_head[];
extern const u16 ken_saca_031_head[];
extern const u16 ken_saca_032_head[];
extern const u16 ken_saca_033_head[];
extern const u16 ken_saca_034_head[];
extern const u16 ken_saca_035_head[];
extern const u16 ken_saca_036_head[];
extern const u16 ken_saca_040_head[];
extern const u16 ken_saca_044_head[];
extern const u16 ken_saca_052_head[];
extern const u16 ken_saca_048_head[];
extern const u16 ken_saca_049_head[];
extern const u16 ken_saca_050_head[];
extern const u16 ken_saca_051_head[];
extern const u16 ken_saca_053_head[];
extern const u16 ken_saca_057_head[];
extern const u16 ken_saca_061_head[];
extern const u16 ken_saca_064_head[];
extern const u16 ken_cbca_000[], ken_cbca_001[], ken_cbca_002[], ken_cbca_003[], ken_cbca_004[], ken_cbca_005[], ken_cbca_006[], ken_cbca_007[], ken_cbca_008[], ken_cbca_009[], ken_cbca_010[], ken_cbca_011[], ken_cbca_012[], ken_cbca_013[], ken_cbca_014[], ken_cbca_015[], ken_cbca_016[], ken_cbca_017[], ken_cbca_018[], ken_cbca_019[], ken_cbca_020[], ken_cbca_021[], ken_cbca_022[], ken_cbca_023[], ken_cbca_024[], ken_cbca_025[], ken_cbca_026[], ken_cbca_027[], ken_cbca_028[], ken_cbca_029[], ken_cbca_030[], ken_cbca_031[], ken_cbca_032[];
extern const u16 ken_cbca_000_head[];
extern const u16 ken_cbca_001_head[];
extern const u16 ken_cbca_002_head[];
extern const u16 ken_cbca_003_head[];
extern const u16 ken_cbca_004_head[];
extern const u16 ken_cbca_005_head[];
extern const u16 ken_cbca_006_head[];
extern const u16 ken_cbca_007_head[];
extern const u16 ken_cbca_008_head[];
extern const u16 ken_cbca_009_head[];
extern const u16 ken_cbca_010_head[];
extern const u16 ken_cbca_011_head[];
extern const u16 ken_cbca_012_head[];
extern const u16 ken_cbca_013_head[];
extern const u16 ken_cbca_014_head[];
extern const u16 ken_cbca_015_head[];
extern const u16 ken_cbca_016_head[];
extern const u16 ken_cbca_017_head[];
extern const u16 ken_cbca_018_head[];
extern const u16 ken_cbca_019_head[];
extern const u16 ken_cbca_020_head[];
extern const u16 ken_cbca_021_head[];
extern const u16 ken_cbca_022_head[];
extern const u16 ken_cbca_023_head[];
extern const u16 ken_cbca_024_head[];
extern const u16 ken_cbca_025_head[];
extern const u16 ken_cbca_026_head[];
extern const u16 ken_cbca_027_head[];
extern const u16 ken_cbca_028_head[];
extern const u16 ken_cbca_029_head[];
extern const u16 ken_cbca_030_head[];
extern const u16 ken_cbca_031_head[];
extern const u16 ken_cbca_032_head[];

/* normal scripts: 51 entries */
const u16* const ken_nmca[52] = {
    ken_nmca_000,  /* 0 KAMAE */
    ken_nmca_001,  /* 1 HURIMUKI */
    ken_nmca_002,  /* 2 FRONT WALK */
    ken_nmca_003,  /* 3 BACK WALK */
    ken_nmca_004,  /* 4 DASH HUMIKOMI */
    ken_nmca_005,  /* 5 DASH TOBINOKI */
    ken_nmca_006,  /* 6 KAGAMU */
    ken_nmca_007,  /* 7 KAGAMI KAMAE */
    ken_nmca_008,  /* 8 KAGAMI TURN */
    ken_nmca_008,  /* 9 KAGAMI F WALK */
    ken_nmca_008,  /* 10 KAGAMI B WALK */
    ken_nmca_011,  /* 11 STAND UP */
    ken_nmca_012,  /* 12 JUMP JUNBI */
    ken_nmca_013,  /* 13 SP JUMP JUNBI */
    ken_nmca_014,  /* 14 JUMP FRONT */
    ken_nmca_015,  /* 15 JUMP VERTICAL */
    ken_nmca_016,  /* 16 JUMP BACK */
    ken_nmca_017,  /* 17 S JUMP FRONT */
    ken_nmca_017,  /* 18 S JUMP V */
    ken_nmca_017,  /* 19 S JUMP BACK */
    ken_nmca_020,  /* 20 SP JUMP FRONT */
    ken_nmca_021,  /* 21 SP JUMP V */
    ken_nmca_022,  /* 22 SP JUMP BACK */
    ken_nmca_023,  /* 23 WALK END */
    ken_nmca_024,  /* 24 PARING HEAD */
    ken_nmca_024,  /* 25 PARING UP */
    ken_nmca_026,  /* 26 PARING DOWN */
    ken_nmca_027,  /* 27 PARING AIR F */
    ken_nmca_027,  /* 28 PARING AIR B */
    ken_nmca_029,  /* 29 GUARD HEAD */
    ken_nmca_030,  /* 30 GUARD UP */
    ken_nmca_031,  /* 31 GUARD DOWN */
    ken_nmca_032,  /* 32 GUARD AIR */
    ken_nmca_033,  /* 33 no name */
    ken_nmca_033,  /* 34 no name */
    ken_nmca_033,  /* 35 no name */
    ken_nmca_033,  /* 36 no name */
    ken_nmca_033,  /* 37 no name */
    ken_nmca_038,  /* 38 P BREAK ZUJOU */
    ken_nmca_038,  /* 39 P BREAK UP */
    ken_nmca_040,  /* 40 P BREAK DOWN */
    ken_nmca_041,  /* 41 P BREAK AIR F */
    ken_nmca_041,  /* 42 P BREAK AIR R */
    ken_nmca_043,  /* 43 TUKAMIHAZUSI */
    ken_nmca_044,  /* 44 TUKAMIHAZUSARE */
    ken_nmca_045,  /* 45 TUKAMIHAZUSI */
    ken_nmca_046,  /* 46 TUKAMIHAZUSARE */
    ken_nmca_047,  /* 47 no name */
    ken_nmca_048,  /* 48 no name */
    ken_nmca_049,  /* 49 no name */
    ken_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 ken_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_000[92] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4202, 0, 150, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4203, 0, 150, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4204, 0, 150, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4205, 0, 150, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4206, 0, 150, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4207, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4208, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4209, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x420A, 0, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4201, 0, 150, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 ken_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_001[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x420B, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x420C, 0, 237, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 ken_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ken_nmca_002[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4210, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4211, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4212, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4213, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4214, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4215, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4216, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4217, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4218, 0, 153, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4219, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x421A, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 ken_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 ken_nmca_003[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x421C, 0, 155, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x421D, 0, 154, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x421E, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x421F, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4220, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4221, 0, 155, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4222, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4223, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4224, 0, 155, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4225, 0, 155, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4226, 0, 155, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 ken_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 ken_nmca_004[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4229, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(4, 1, 277, 0, 0, 0, 0, 0x4270, 0, 253, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4271, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x4272, 0, 254, 0, 0, 0, 0, 0),
    L4(4, 7, 0, 0, 0, 0, 0, 0x4273, 0, 255, 0, 0, 33, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4274, 0, 255, 0, 0, 33, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 ken_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 ken_nmca_005[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 10, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4276, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x4277, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4278, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4279, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x427A, 0, 259, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x427A, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x427B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x427B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 ken_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_nmca_006[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4228, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4229, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x422A, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x422B, 0, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 ken_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_nmca_007[52] = {
    L4(12, 0, 0, 0, 0, 0, 0, 0x422C, 0, 158, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x4230, 0, 158, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x4231, 0, 159, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4232, 0, 159, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x4233, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 ken_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_nmca_008[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x423A, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x423B, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x423C, 0, 238, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 ken_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_nmca_011[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x422D, 0, 157, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 ken_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x4229, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4229, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4229, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 ken_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x4229, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4229, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 ken_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_nmca_014[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x424C, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x424D, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x4253, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4254, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4255, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 ken_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 ken_nmca_015[156] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x4240, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4241, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x426A, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4240, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4241, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x426A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x4242, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x4243, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4244, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4245, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4246, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x4247, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x426B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 ken_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x4254, 0, 242, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4253, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x424D, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424C, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4258, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 ken_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 ken_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 9),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 ken_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 ken_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x424C, 0, 239, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 6, 0x424D, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x4253, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4254, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4255, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 ken_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 ken_nmca_021[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x4240, 0, 4, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4241, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x426A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4240, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4241, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x426A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x4242, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4243, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4244, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4245, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4246, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4247, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4248, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x426B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 ken_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 ken_nmca_022[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x4254, 0, 242, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4253, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x424D, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424C, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4258, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 ken_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ken_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 ken_nmca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_024[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x4377, 0, 9, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 389, 0, 0, 0, 0, 0x4378, 0, 10, 0, 0, 0, 6, 0, 0, 0, 14, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4379, 0, 10, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x437A, 0, 10, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x4349, 0, 9, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 ken_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 ken_nmca_026[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x45D0, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 389, 0, 0, 0, 0, 0x45D1, 0, 2, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x45D2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x45D3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 ken_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_nmca_027[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x4268, 0, 4, 0, 0, 0, 18, 6),
    L4(250, 0, 389, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x426C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4246, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4247, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x426B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 ken_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ken_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x425A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x425B, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x425C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x425A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 ken_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ken_nmca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x425F, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 ken_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ken_nmca_031[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4264, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x4265, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 ken_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ken_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4268, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 17001), 0x0000, 0x8000, 0x0000, 0x0000,
    L4(2, 3, 0, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 ken_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_033[12] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 ken_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_038[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4261, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 ken_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_nmca_040[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4265, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4266, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 ken_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4268, 0, 4, 0, 0, 0, 18, 8),
    L4(250, 0, 389, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 ken_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_043[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4261, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 ken_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_044[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4480, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x4481, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4481, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 ken_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_nmca_045[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x4268, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 389, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4253, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4258, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 ken_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x4244, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4245, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4246, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4247, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x426B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ken_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ken_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ken_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ken_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_nmca_050[68] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4261, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const ken_dmca[99] = {
    ken_dmca_000,  /* 0 GUARD HEAD */
    ken_dmca_001,  /* 1 GUARD UP */
    ken_dmca_002,  /* 2 GUARD DOWN */
    ken_dmca_003,  /* 3 GUARD AIR */
    ken_dmca_004,  /* 4 HUSHIN HEAD */
    ken_dmca_004,  /* 5 HUSHIN UP */
    ken_dmca_006,  /* 6 HUSHIN DOWN */
    ken_dmca_006,  /* 7 HUSHIN AIR */
    ken_dmca_008,  /* 8 FACE S */
    ken_dmca_009,  /* 9 FACE M */
    ken_dmca_010,  /* 10 FACE L */
    ken_dmca_010,  /* 11 FACE SP */
    ken_dmca_008,  /* 12 FOOK OKU S */
    ken_dmca_009,  /* 13 FOOK OKU M */
    ken_dmca_014,  /* 14 FOOK OKU L */
    ken_dmca_015,  /* 15 FOOK OKU SP */
    ken_dmca_008,  /* 16 FOOK TEMAE S */
    ken_dmca_009,  /* 17 FOOK TEMAE M */
    ken_dmca_018,  /* 18 FOOK TEMAE L */
    ken_dmca_019,  /* 19 FOOK TEMAE SP */
    ken_dmca_008,  /* 20 UPPER S */
    ken_dmca_009,  /* 21 UPPER M */
    ken_dmca_022,  /* 22 UPPER L */
    ken_dmca_022,  /* 23 UPPER SP */
    ken_dmca_024,  /* 24 NOUTEN S */
    ken_dmca_025,  /* 25 NOUTEN M */
    ken_dmca_026,  /* 26 NOUTEN L */
    ken_dmca_026,  /* 27 NOUTEN SP */
    ken_dmca_024,  /* 28 BODY BROW S */
    ken_dmca_029,  /* 29 BODY BROW M */
    ken_dmca_030,  /* 30 BODY BROW L */
    ken_dmca_030,  /* 31 BODY BROW SP */
    ken_dmca_024,  /* 32 BODY UPPER S */
    ken_dmca_029,  /* 33 BODY UPPER M */
    ken_dmca_034,  /* 34 BODY UPPER L */
    ken_dmca_034,  /* 35 BODY UPPER SP */
    ken_dmca_036,  /* 36 TATAKI S */
    ken_dmca_036,  /* 37 TATAKI M */
    ken_dmca_036,  /* 38 TATAKI L */
    ken_dmca_036,  /* 39 TATAKI SP */
    ken_dmca_036,  /* 40 TATAKI V. S */
    ken_dmca_036,  /* 41 TATAKI V. M */
    ken_dmca_036,  /* 42 TATAKI V. L */
    ken_dmca_036,  /* 43 TATAKI V. SP */
    ken_dmca_008,  /* 44 NOBASITA TE S */
    ken_dmca_009,  /* 45 NOBASITA TE M */
    ken_dmca_010,  /* 46 NOBASITA TE L */
    ken_dmca_010,  /* 47 NOBASITA TE SP */
    ken_dmca_048,  /* 48 KAGAMI S */
    ken_dmca_049,  /* 49 KAGAMI M */
    ken_dmca_050,  /* 50 KAGAMI L */
    ken_dmca_050,  /* 51 KAGAMI SP */
    ken_dmca_052,  /* 52 KGM TATAKI S */
    ken_dmca_052,  /* 53 KGM TATAKI M */
    ken_dmca_052,  /* 54 KGM TATAKI L */
    ken_dmca_052,  /* 55 KGM TATAKI SP */
    ken_dmca_052,  /* 56 KGM TTKI V.S */
    ken_dmca_052,  /* 57 KGM TTKI V.M */
    ken_dmca_052,  /* 58 KGM TTKI V.L */
    ken_dmca_052,  /* 59 KGM TTKI V.SP */
    ken_dmca_060,  /* 60 NEKOROBI S */
    ken_dmca_060,  /* 61 NEKOROBI M */
    ken_dmca_060,  /* 62 NEKOROBI L */
    ken_dmca_060,  /* 63 NEKOROBI SP */
    ken_dmca_064,  /* 64 OKIAGARI */
    ken_dmca_065,  /* 65 OKIAGARI F */
    ken_dmca_066,  /* 66 OKIAGARI B */
    ken_dmca_067,  /* 67 LOSE NO STAND */
    ken_dmca_068,  /* 68 LOSE SONABA */
    ken_dmca_068,  /* 69 LOSE KAGAMI */
    ken_dmca_070,  /* 70 PIYO */
    ken_dmca_071,  /* 71 UKEMI MOVE F */
    ken_dmca_072,  /* 72 UKEMI MOVE R */
    ken_dmca_073,  /* 73 SHIMEOTASARE */
    ken_dmca_074,  /* 74 TATI TOUKETU S */
    ken_dmca_075,  /* 75 TATI TOUKETU M */
    ken_dmca_076,  /* 76 TATI TOUKETU L */
    ken_dmca_076,  /* 77 TATI TOUKETU P */
    ken_dmca_078,  /* 78 KGM TOUKETU S */
    ken_dmca_079,  /* 79 KGM TOUKETU M */
    ken_dmca_080,  /* 80 KGM TOUKETU L */
    ken_dmca_080,  /* 81 KGM TOUKETU P */
    ken_dmca_082,  /* 82 TATI DENGEKI S */
    ken_dmca_083,  /* 83 TATI DENGEKI M */
    ken_dmca_084,  /* 84 TATI DENGEKI L */
    ken_dmca_084,  /* 85 TATI DENGEKI P */
    ken_dmca_082,  /* 86 KGM DENGEKI S */
    ken_dmca_083,  /* 87 KGM DENGEKI M */
    ken_dmca_084,  /* 88 KGM DENGEKI L */
    ken_dmca_084,  /* 89 KGM DENGEKI P */
    ken_dmca_090,  /* 90 OKIAGARI FRONT */
    ken_dmca_091,  /* 91 OKIAGARI REAR */
    ken_dmca_008,  /* 92 TATI MOE S */
    ken_dmca_009,  /* 93 TATI MOE M */
    ken_dmca_010,  /* 94 TATI MOE L */
    ken_dmca_010,  /* 95 TATI MOE SP */
    ken_dmca_096,  /* 96 no name */
    ken_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 ken_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_000[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x425C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x425D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x425E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x425C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x425A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 ken_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_001[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4261, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x4262, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4260, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4259, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 ken_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x4265, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4266, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x4267, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4265, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4263, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 ken_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x4268, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x4269, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x4269, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4269, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4269, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4269, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 ken_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_004[44] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4283, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 ken_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_006[52] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4288, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4280, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x4281, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4282, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4283, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 ken_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4290, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 133, 386, 0, 0, 0, 0, 0x4290, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4292, 0, 164, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 ken_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4291, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 134, 386, 0, 0, 0, 0, 0x4291, 0, 164, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x4295, 0, 165, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4296, 0, 165, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x4292, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 ken_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_010[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4299, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 135, 387, 0, 0, 0, 0, 0x4299, 0, 165, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x429A, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x429B, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x429C, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x429D, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x429E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 ken_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_014[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4299, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 136, 387, 0, 0, 0, 0, 0x4299, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x429A, 0, 165, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x42A7, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x42A8, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x42A6, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x429D, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x429E, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 ken_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_015[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4297, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 137, 387, 0, 0, 0, 0, 0x4298, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4299, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x429A, 0, 165, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x42A7, 0, 166, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x42A8, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x42A6, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x429D, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x429E, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 ken_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_018[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42A0, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 137, 387, 0, 0, 0, 0, 0x42A0, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42A2, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x42A3, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x42A4, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x42A5, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x42A6, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x429D, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x429E, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 ken_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_019[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4294, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 138, 387, 0, 0, 0, 0, 0x42A0, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42A1, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x42A2, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x42A3, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x42A4, 0, 166, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x42A5, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x42A6, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x429D, 0, 165, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x429E, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 ken_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4320, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 135, 387, 0, 0, 0, 0, 0x42AF, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42B0, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42B1, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x429C, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x429D, 0, 164, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x429E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 ken_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_025[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42AA, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 134, 386, 0, 0, 0, 0, 0x42AB, 0, 168, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42AC, 0, 169, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42AD, 0, 169, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 ken_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42AB, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 135, 386, 0, 0, 0, 0, 0x42AB, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42AB, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42AC, 0, 169, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42AD, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 ken_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42B3, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 134, 386, 0, 0, 0, 0, 0x42B4, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42B5, 0, 169, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42B6, 0, 169, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x42B7, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 ken_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42BC, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 136, 386, 0, 0, 0, 0, 0x42BC, 0, 169, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42BC, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42B4, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42B5, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42B6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x42B7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 ken_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42BB, 0, 168, 0, 0, 0, 0, 0),
    L4(1, 139, 387, 0, 0, 0, 0, 0x42BE, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42BF, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42C0, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x42C1, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42C2, 0, 170, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42C3, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42C4, 0, 165, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42C5, 0, 164, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 ken_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42AD, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 135, 387, 0, 0, 0, 0, 0x42AE, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42AF, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42B0, 0, 163, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x42B1, 0, 165, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x429C, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x429D, 0, 164, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x429E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 ken_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x430C, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x430D, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 ken_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_048[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42C6, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 133, 386, 0, 0, 0, 0, 0x42C7, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42C7, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x42C8, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 ken_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_049[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42CA, 0, 172, 0, 0, 0, 0, 0),
    L4(6, 133, 386, 0, 0, 0, 0, 0x42CB, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42C7, 0, 174, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x42C8, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 ken_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_050[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x42CD, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42CE, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 135, 387, 0, 0, 0, 0, 0x42CA, 0, 174, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42CF, 0, 175, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42D0, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x423A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x423B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x423C, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 ken_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 132, 387, 0, 0, 0, 0, 0x42CD, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42CA, 0, 172, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 ken_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_060[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42F9, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 387, 0, 0, 0, 0, 0x42FA, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42FB, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F5, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 ken_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 ken_dmca_064[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4340, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4341, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4342, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4343, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4344, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4345, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(6, 12, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4347, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4348, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 ken_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 ken_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4490, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4350, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4351, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4352, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4353, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4348, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 ken_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 ken_dmca_066[156] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4340, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4341, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4352, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4351, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4350, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4348, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 ken_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 ken_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_068[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4290, 0, 202, 0, 0, 0, 32, 91),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4290, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4330, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4331, 0, 204, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4332, 0, 205, 0, 0, 0, 0, 0),
    L4(6, 0, 289, 0, 0, 0, 0, 0x4333, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x4334, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4335, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4336, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4337, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4338, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x4339, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x433E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x433F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 ken_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x4311, 0, 246, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4312, 0, 247, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4313, 0, 248, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4314, 0, 248, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x430E, 0, 249, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x430F, 0, 249, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4310, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 ken_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4352, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 388, 0, 0, 0, 0, 0x434B, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434C, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434D, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434E, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434F, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4350, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4351, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 ken_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_072[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4340, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -11776, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 388, 0, 0, 0, 0, 0x434E, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x434D, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x434C, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x434B, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4348, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x4348, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 ken_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_073[148] = {
    L4(2, 0, 387, 0, 0, 0, 0, 0x4290, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4330, 0, 203, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4331, 0, 204, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4332, 0, 205, 0, 0, 0, 0, 0),
    L4(3, 0, 289, 0, 0, 0, 0, 0x4333, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x4334, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4335, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4336, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4337, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4338, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x4339, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x433A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x433B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x433D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x433E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x433F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x433F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 ken_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4290, 0, 164, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4290, 0, 164, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 ken_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4294, 0, 164, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4294, 0, 164, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 ken_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x4297, 0, 164, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x4297, 0, 164, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 ken_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42C6, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x42C6, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 ken_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42C9, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x42C9, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42C8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 ken_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42CC, 0, 172, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x42CC, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x423B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x423C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x423D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 ken_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4518, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4519, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 ken_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4518, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4519, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 ken_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4518, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4517, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4519, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 ken_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 ken_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4490, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x434B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4350, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4351, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4352, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4353, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4348, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 ken_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 ken_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4340, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x4341, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4352, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4351, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x4350, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x434C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x434B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4346, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4347, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4348, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 ken_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_096[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 ken_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_dmca_097[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x42F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F8, 0, 17, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 17, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 17, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const ken_btca[37] = {
    ken_btca_000,  /* 0 AIR NORMAL */
    ken_btca_001,  /* 1 ASIBARAI SIRI */
    ken_btca_002,  /* 2 ASIB TUNNOMERI */
    ken_btca_003,  /* 3 NOKEZORI */
    ken_btca_004,  /* 4 KUNOJI */
    ken_btca_005,  /* 5 KIRIMOMI */
    ken_btca_006,  /* 6 UPPER */
    ken_btca_007,  /* 7 BODY UPPER */
    ken_btca_008,  /* 8 HARAYARARE */
    ken_btca_009,  /* 9 TATAKI AIR */
    ken_btca_010,  /* 10 TTKI V. AIR */
    ken_btca_011,  /* 11 HUMI ASIB */
    ken_btca_012,  /* 12 FACE */
    ken_btca_013,  /* 13 ASIB SIRI LOSE */
    ken_btca_014,  /* 14 ASIB TUN LOSE */
    ken_btca_015,  /* 15 DENKI */
    ken_btca_016,  /* 16 KUNOJI NOKE */
    ken_btca_017,  /* 17 BODY UPPER SP */
    ken_btca_018,  /* 18 HANEAGARI */
    ken_btca_019,  /* 19 TOUKETSU A */
    ken_btca_020,  /* 20 BODY SLAM */
    ken_btca_021,  /* 21 IPPONZEOI */
    ken_btca_022,  /* 22 TOMOE RYU */
    ken_btca_023,  /* 23 MONKEY FLIP */
    ken_btca_024,  /* 24 TOMOE ORO */
    ken_btca_025,  /* 25 SNAKE FANG */
    ken_btca_026,  /* 26 FLANKEN.S */
    ken_btca_027,  /* 27 KISHINRIKI */
    ken_btca_028,  /* 28 SPLASH.M */
    ken_btca_029,  /* 29 HARAIGOSHI */
    ken_btca_030,  /* 30 ALEX B.D */
    ken_btca_031,  /* 31 GILL */
    ken_btca_032,  /* 32 HANEKAERI HARA */
    ken_btca_033,  /* 33 S HANEAGARI */
    ken_btca_034,  /* 34 TATUMAKIZANKU */
    ken_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 ken_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_000[68] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 386, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x42BD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x4253, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 ken_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4304, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 387, 0, 0, 0, 7, 0x4305, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x4306, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x4307, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x4308, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 ken_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_btca_002[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4304, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 386, 0, 0, 0, 0, 0x4305, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4306, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4307, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4308, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 ken_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_003[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 ken_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_004[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 386, 0, 0, 0, 0, 0x42BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42BF, 0, 219, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 ken_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_005[156] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4320, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 387, 0, 0, 0, 0, 0x4321, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4322, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4323, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4324, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4325, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4326, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4327, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4328, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4329, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432A, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432B, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432C, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432D, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432E, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x432F, 0, 224, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x432F, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 ken_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_006[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x4510, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4511, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 ken_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_007[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4512, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x4513, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4514, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4515, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 ken_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_008[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42BD, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x4511, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 ken_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_009[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 387, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 ken_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_010[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x430B, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 387, 0, 0, 0, 0, 0x430C, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x430D, 0, 235, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x430D, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 ken_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ken_btca_011[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4309, 0, 233, 0, 0, 0, 0, 0),
    L4(250, 0, 386, 0, 0, 0, 0, 0x430A, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 ken_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_012[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4291, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 386, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 ken_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 ken_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 ken_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_015[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x4517, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4517, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4518, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4517, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4519, 0, 231, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 387, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 ken_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_016[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42BD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 386, 0, 0, 0, 0, 0x42BE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42BF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42FF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 ken_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_017[148] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x4510, 0, 226, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 387, 0, 0, 0, 0, 0x4511, 0, 227, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 ken_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_018[156] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 386, 0, 0, 0, 0, 0x42EC, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x42E8, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x42E7, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x42E6, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x42E5, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x42E3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x42EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x42F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 ken_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4295, 0, 232, 0, 0, 0, 0, 0),
    L4(250, 0, 386, 0, 0, 0, 0, 0x4295, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 ken_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FA, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 ken_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 ken_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_022[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x432C, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4337, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 236, 0, 0, 0, 32, 106),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 ken_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x432C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4337, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 236, 0, 0, 0, 32, 106),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 ken_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x432C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4337, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 236, 0, 0, 0, 32, 106),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 ken_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 236, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 ken_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4337, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42E8, 0, 236, 0, 0, 0, 32, 106),
    L4(6, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FB, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 ken_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_027[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x42E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x42E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x42E5, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x42E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 ken_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_028[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42EC, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42ED, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 ken_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E8, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E8, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 ken_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_030[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x4512, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x4513, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4514, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4515, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x42E4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x42E5, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x42E6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x42E7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 ken_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_031[52] = {
    L4(250, 131, 0, 0, 0, 0, 0, 0x4304, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 387, 0, 0, 0, 0, 0x4305, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4306, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4307, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x4308, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 ken_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x42BD, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4511, 0, 236, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 ken_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_033[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x42EF, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 386, 0, 0, 0, 0, 0x42EF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F0, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42F1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x42EE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x42F2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 ken_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_034[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x42AE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 387, 0, 0, 0, 0, 0x4510, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4511, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 ken_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_btca_035[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x42E3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x42E4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x42E5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x42E6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 25 entries */
const u16* const ken_caca[26] = {
    ken_caca_000,  /* 0 CATCH 1 */
    ken_caca_000,  /* 1 CATCH 2 */
    ken_caca_002,  /* 2 CATCH 3 */
    ken_caca_002,  /* 3 CATCH 4 */
    ken_caca_004,  /* 4 CATCH 5 */
    ken_caca_004,  /* 5 CATCH 6 */
    ken_caca_004,  /* 6 CATCH 7 */
    ken_caca_004,  /* 7 CATCH 8 */
    ken_caca_008,  /* 8 CATCH 9 */
    ken_caca_008,  /* 9 CATCH 10 */
    ken_caca_010,  /* 10 CATCH 11 */
    ken_caca_010,  /* 11 CATCH 12 */
    ken_caca_012,  /* 12 CATCH 13 */
    ken_caca_012,  /* 13 CATCH 14 */
    ken_caca_014,  /* 14 CATCH 15 */
    ken_caca_014,  /* 15 CATCH 16 */
    ken_caca_014,  /* 16 CATCH 17 */
    ken_caca_014,  /* 17 CATCH 18 */
    ken_caca_018,  /* 18 CATCH 19 */
    ken_caca_019,  /* 19 CATCH 20 */
    ken_caca_020,  /* 20 CATCH 21 */
    ken_caca_021,  /* 21 CATCH 22 */
    ken_caca_021,  /* 22 CATCH 23 */
    ken_caca_021,  /* 23 CATCH 24 */
    ken_caca_021,  /* 24 CATCH 25 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2 */
const u16 ken_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ken_caca_000[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4482, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4483, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4484, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4485, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4486, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4487, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 2, 390, 0, 0, 0, 0, 0x4488, -47, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(10, 9, 270, 0, 0, 0, 0, 0x4489, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x448A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x448B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x448C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x448D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3, 3 CATCH 4 */
const u16 ken_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ken_caca_002[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4482, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4483, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4484, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4485, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4486, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4487, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 2, 390, 0, 0, 0, 0, 0x4488, -47, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(10, 9, 270, 0, 0, 0, 0, 0x4489, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x448A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x448B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x448C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x448D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 ken_caca_004_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 ken_caca_004[196] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x448E, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x448F, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(4, 0, 390, 0, 0, 0, 0, 0x4490, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x4491, -49, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x4492, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4494, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4495, 0, 1, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x4496, 0, 1, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9, 9 CATCH 10 */
const u16 ken_caca_008_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 ken_caca_008[268] = {
    CMD(CM_NGDA, 1542, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 6, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x43CD, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 18, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 19, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 20, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 64, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 9, 0, 0, 0, 0, 0, 0x43CD, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x43C5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x43C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11, 11 CATCH 12 */
const u16 ken_caca_010_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ken_caca_010[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x4483, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14 */
const u16 ken_caca_012_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ken_caca_012[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x4483, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16, 16 CATCH 17, 17 CATCH 18 */
const u16 ken_caca_014_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 ken_caca_014[76] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x448E, 0, 0, 0, 0, 0, 24, 0, 0, 360, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 CATCH 19 */
const u16 ken_caca_018_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 ken_caca_018[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x43C8, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43C9, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 2, 388, 0, 0, 0, 0, 0x43CA, -55, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x43CB, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(6, 4, 0, 0, 0, 0, 0, 0x43CC, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 CATCH 20 */
const u16 ken_caca_019_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 ken_caca_019[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x43C8, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43C9, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 2, 388, 0, 0, 0, 0, 0x43CA, -55, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x43CB, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x43CC, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 CATCH 21 */
const u16 ken_caca_020_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 ken_caca_020[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x43C8, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43C9, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 2, 388, 0, 0, 0, 0, 0x43CA, -55, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x43CB, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 0, 0, 0x43CC, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 CATCH 22, 22 CATCH 23, 23 CATCH 24, 24 CATCH 25 */
const u16 ken_caca_021_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 ken_caca_021[268] = {
    CMD(CM_NGDA, 1542, 52, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 264, 0, 0, 0, 0, 0x4360, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4480, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4481, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x448E, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x45D8, 0, 0, 0, 0, 0, 0, 0, 0, 864, 264, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x45D9, 0, 0, 0, 0, 0, 0, 0, 0, 888, 266, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x45DA, 0, 0, 0, 0, 0, 0, 0, 0, 912, 268, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x45DB, 0, 0, 0, 0, 0, 0, 0, 0, 936, 270, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x45DC, 0, 0, 0, 0, 0, 0, 0, 0, 960, 288, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x45DD, 0, 0, 0, 0, 0, 0, 0, 0, 984, 290, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x45DE, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 292, 0, 0),
    L6(3, 0, 390, 0, 0, 0, 0, 0x4490, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 294, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x4491, -49, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x4492, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x4493, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4494, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4495, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x4496, 0, 1, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const ken_cuca[69] = {
    ken_cuca_000,  /* 0 ALEX ZUTUKI */
    ken_cuca_001,  /* 1 ALEX BODY S */
    ken_cuca_002,  /* 2 ALEX BACK D */
    ken_cuca_003,  /* 3 ALEX POWER B */
    ken_cuca_004,  /* 4 ALEX SLEEPER */
    ken_cuca_005,  /* 5 RYU SEOINAGE */
    ken_cuca_006,  /* 6 IBUKI */
    ken_cuca_007,  /* 7 DADLEY L B */
    ken_cuca_008,  /* 8 IBUKI KUBIORI */
    ken_cuca_009,  /* 9 NECRO S T */
    ken_cuca_010,  /* 10 RYU TOMOENAGE */
    ken_cuca_011,  /* 11 YUN HIZAGERI */
    ken_cuca_012,  /* 12 ORO KUBISIME */
    ken_cuca_013,  /* 13 NECRO G S */
    ken_cuca_014,  /* 14 DUDDLEY D S */
    ken_cuca_015,  /* 15 YUN MONKEY F */
    ken_cuca_016,  /* 16 ORO TOMOENAGE */
    ken_cuca_017,  /* 17 ORO NIOURIKI */
    ken_cuca_018,  /* 18 ORO GIGOKU G */
    ken_cuca_019,  /* 19 YUN */
    ken_cuca_020,  /* 20 NECRO SNAKE F */
    ken_cuca_021,  /* 21 NECRO F S */
    ken_cuca_022,  /* 22 IBUKI HARAIG */
    ken_cuca_023,  /* 23 GILL SPLASH M */
    ken_cuca_024,  /* 24 KEN HIZAGERI */
    ken_cuca_025,  /* 25 ORO KISINRIKI */
    ken_cuca_026,  /* 26 SEAN TACKLE */
    ken_cuca_027,  /* 27 ALEX HYPER B */
    ken_cuca_028,  /* 28 NECRO SLAM D */
    ken_cuca_029,  /* 29 ELENA ASINAGE */
    ken_cuca_030,  /* 30 GILL IMPACT C */
    ken_cuca_031,  /* 31 ALEX S H B */
    ken_cuca_032,  /* 32 ALEX F N D */
    ken_cuca_033,  /* 33 no name */
    ken_cuca_034,  /* 34 IBUKI */
    ken_cuca_035,  /* 35 IBUKI YOROI D */
    ken_cuca_036,  /* 36 no name */
    ken_cuca_037,  /* 37 MAWARIKOMI M F */
    ken_cuca_038,  /* 38 HUGO BODY S */
    ken_cuca_039,  /* 39 HUGO N G T */
    ken_cuca_040,  /* 40 HUGO M S P */
    ken_cuca_041,  /* 41 HUGO S D B B */
    ken_cuca_042,  /* 42 no name */
    ken_cuca_043,  /* 43 no name */
    ken_cuca_044,  /* 44 no name */
    ken_cuca_045,  /* 45 no name */
    ken_cuca_046,  /* 46 no name */
    ken_cuca_047,  /* 47 no name */
    ken_cuca_048,  /* 48 no name */
    ken_cuca_049,  /* 49 no name */
    ken_cuca_050,  /* 50 no name */
    ken_cuca_051,  /* 51 no name */
    ken_cuca_052,  /* 52 no name */
    ken_cuca_053,  /* 53 no name */
    ken_cuca_054,  /* 54 no name */
    ken_cuca_055,  /* 55 no name */
    ken_cuca_056,  /* 56 no name */
    ken_cuca_057,  /* 57 no name */
    ken_cuca_058,  /* 58 no name */
    ken_cuca_059,  /* 59 no name */
    ken_cuca_060,  /* 60 no name */
    ken_cuca_061,  /* 61 no name */
    ken_cuca_062,  /* 62 no name */
    ken_cuca_063,  /* 63 no name */
    ken_cuca_064,  /* 64 no name */
    ken_cuca_065,  /* 65 no name */
    ken_cuca_066,  /* 66 no name */
    ken_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 ken_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AA),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 ken_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4337),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4303),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4301),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42ED),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 ken_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 ken_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x429A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4308),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EB),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 ken_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42AA),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42AA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 ken_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4309),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E7),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42EE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 ken_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x427A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4274),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4274),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4360),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4363),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4384),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4382),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4383),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 ken_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 ken_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4293),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4320),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 ken_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 ken_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 1, 0, 0, 0x432C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 ken_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 ken_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x424B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 ken_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EB),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42EB),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 ken_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BF),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42FF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 ken_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4301),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x432C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 ken_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x432C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 ken_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x429A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x429B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E2),
    L2(250, 2, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 ken_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x434B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x434C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x434D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x434E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4351),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4352),
    L2(250, 0, 0, 0, 0, 0, 0, 0x434B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 ken_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4201),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 ken_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 1, 0, 0, 0x425A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x425B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x425C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4276),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4287),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4286),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4285),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E4),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 ken_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4276),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4275),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42B3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 ken_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E7),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 ken_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42EB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 ken_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 ken_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x429A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x429B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E2),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 ken_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 3, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F7),
    L2(250, 3, 0, 0, 0, 0, 0, 0x42FA),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42F7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 ken_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_027[152] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EB),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42EB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 ken_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42F3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 ken_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4293),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4300),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4301),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 ken_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4511),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4511),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4510),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x4510),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 29, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 30, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 ken_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AB),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 ken_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 ken_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42EA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 12),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 ken_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B0),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42B0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 ken_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4279),
    L2(250, 0, 0, 0, 0, 0, 0, 0x427A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4274),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4274),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4360),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4363),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4384),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4382),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4383),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 ken_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4293),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 2, 0, 0, 0, 0, 0, 0x42B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 2, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 2, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F3),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42F2),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 ken_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42BE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42BF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x42C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 ken_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x429C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4337),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4338),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42FC),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 ken_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FC),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 ken_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x432B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F5),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 ken_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x432F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 ken_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BE),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 ken_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F8),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42F8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 ken_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x432B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x432F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x430A),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 ken_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 ken_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x432B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x432B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42EF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4303),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ken_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EA),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42EA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ken_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4293),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42AB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ken_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x424D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 2, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4300),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 3, 0, 0, 0x4300),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ken_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x424C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x424C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4512),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4512),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42EE),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E8),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 ken_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4279),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A7),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42B4),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 ken_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x44AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x430A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4515),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4336),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FB),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 1, 0, 0, 0x432C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 ken_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_053[116] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4306),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E9),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 ken_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4511),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4511),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4511),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4510),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4510),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 29, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 30, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 ken_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42AF),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x42E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 ken_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x4290),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 10, 0x4306),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 ken_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BE),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 ken_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4515),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 ken_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4259),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4275),
    L2(250, 0, 0, 0, 0, 0, 0, 0x425A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x425F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4261),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4262),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4305),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 ken_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x429E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x4292),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 ken_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4306),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 ken_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4294),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A6),
    CMD(CM_PA_X, 0, -8192, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42C4),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 120),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4306),
    CMD(CM_PA_X, 0, 1536, 0),
    CMD(CM_PS_Y, 0, 0, 86),
    L2(250, 0, 0, 0, 2, 0, 0, 0x4307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42EC),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42ED),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 ken_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BD),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 386, 0, 0, 0, 0, 0x42BE),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 ken_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4292),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42BB),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42BE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 ken_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x4297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4299),
    L2(250, 0, 0, 0, 0, 0, 0, 0x429A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x42A6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x42EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x4301),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x432C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 ken_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42FB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 ken_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4295),
    L2(250, 0, 0, 0, 0, 0, 0, 0x4296),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x42AF),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x42E3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 170 entries */
const u16* const ken_atca[171] = {
    ken_atca_000,  /* 0 S PUNCH A */
    ken_atca_001,  /* 1 S PUNCH B */
    ken_atca_001,  /* 2 S PUNCH C */
    ken_atca_003,  /* 3 M PUNCH A */
    ken_atca_004,  /* 4 M PUNCH B */
    ken_atca_004,  /* 5 M PUNCH C */
    ken_atca_006,  /* 6 L PUNCH A */
    ken_atca_007,  /* 7 L PUNCH B */
    ken_atca_007,  /* 8 L PUNCH C */
    ken_atca_009,  /* 9 S KICK A */
    ken_atca_009,  /* 10 S KICK B */
    ken_atca_009,  /* 11 S KICK C */
    ken_atca_012,  /* 12 M KICK A */
    ken_atca_013,  /* 13 M KICK B */
    ken_atca_014,  /* 14 M KICK C */
    ken_atca_015,  /* 15 L KICK A */
    ken_atca_015,  /* 16 L KICK B */
    ken_atca_017,  /* 17 L KICK C */
    ken_atca_018,  /* 18 KAGAMI P A */
    ken_atca_018,  /* 19 KAGAMI P B */
    ken_atca_018,  /* 20 KAGAMI P C */
    ken_atca_021,  /* 21 KAGAMI P A */
    ken_atca_021,  /* 22 KAGAMI P B */
    ken_atca_021,  /* 23 KAGAMI P C */
    ken_atca_024,  /* 24 KAGAMI P A */
    ken_atca_024,  /* 25 KAGAMI P B */
    ken_atca_024,  /* 26 KAGAMI P C */
    ken_atca_027,  /* 27 KAGAMI K A */
    ken_atca_027,  /* 28 KAGAMI K B */
    ken_atca_027,  /* 29 KAGAMI K C */
    ken_atca_030,  /* 30 KAGAMI K A */
    ken_atca_030,  /* 31 KAGAMI K B */
    ken_atca_030,  /* 32 KAGAMI K C */
    ken_atca_033,  /* 33 KAGAMI K A */
    ken_atca_033,  /* 34 KAGAMI K B */
    ken_atca_033,  /* 35 KAGAMI K C */
    ken_atca_036,  /* 36 V JUMP P S A */
    ken_atca_036,  /* 37 V JUMP P S B */
    ken_atca_038,  /* 38 V JUMP P M A */
    ken_atca_038,  /* 39 V JUMP P M B */
    ken_atca_040,  /* 40 V JUMP P L A */
    ken_atca_040,  /* 41 V JUMP P L B */
    ken_atca_042,  /* 42 V JUMP K S A */
    ken_atca_042,  /* 43 V JUMP K S B */
    ken_atca_044,  /* 44 V JUMP K M A */
    ken_atca_044,  /* 45 V JUMP K M B */
    ken_atca_046,  /* 46 V JUMP K L A */
    ken_atca_046,  /* 47 V JUMP K L B */
    ken_atca_048,  /* 48 F JUMP P S A */
    ken_atca_048,  /* 49 F JUMP P S B */
    ken_atca_050,  /* 50 F JUMP P M A */
    ken_atca_050,  /* 51 F JUMP P M B */
    ken_atca_052,  /* 52 F JUMP P L A */
    ken_atca_052,  /* 53 F JUMP P L B */
    ken_atca_054,  /* 54 F JUMP K S A */
    ken_atca_054,  /* 55 F JUMP K S B */
    ken_atca_056,  /* 56 F JUMP K M A */
    ken_atca_056,  /* 57 F JUMP K M B */
    ken_atca_058,  /* 58 F JUMP K L A */
    ken_atca_058,  /* 59 F JUMP K L B */
    ken_atca_060,  /* 60 B JUMP P S A */
    ken_atca_060,  /* 61 B JUMP P S B */
    ken_atca_062,  /* 62 B JUMP P M A */
    ken_atca_062,  /* 63 B JUMP P M B */
    ken_atca_064,  /* 64 B JUMP P L A */
    ken_atca_064,  /* 65 B JUMP P L B */
    ken_atca_066,  /* 66 B JUMP K S A */
    ken_atca_066,  /* 67 B JUMP K S B */
    ken_atca_068,  /* 68 B JUMP K M A */
    ken_atca_068,  /* 69 B JUMP K M B */
    ken_atca_070,  /* 70 B JUMP K L A */
    ken_atca_070,  /* 71 B JUMP K L B */
    ken_atca_072,  /* 72 SP V JP S P A */
    ken_atca_072,  /* 73 SP V JP S P B */
    ken_atca_074,  /* 74 SP V JP M P A */
    ken_atca_074,  /* 75 SP V JP M P B */
    ken_atca_076,  /* 76 SP V JP L P A */
    ken_atca_076,  /* 77 SP V JP L P B */
    ken_atca_078,  /* 78 SP V JP S K A */
    ken_atca_078,  /* 79 SP V JP S K B */
    ken_atca_080,  /* 80 SP V JP M K A */
    ken_atca_080,  /* 81 SP V JP M K B */
    ken_atca_082,  /* 82 SP V JP L K A */
    ken_atca_082,  /* 83 SP V JP L K B */
    ken_atca_084,  /* 84 SP F JP S P A */
    ken_atca_084,  /* 85 SP F JP S P B */
    ken_atca_086,  /* 86 SP F JP M P A */
    ken_atca_086,  /* 87 SP F JP M P B */
    ken_atca_088,  /* 88 SP F JP L P A */
    ken_atca_088,  /* 89 SP F JP L P B */
    ken_atca_090,  /* 90 SP F JP S K A */
    ken_atca_090,  /* 91 SP F JP S K B */
    ken_atca_092,  /* 92 SP F JP M K A */
    ken_atca_092,  /* 93 SP F JP M K B */
    ken_atca_094,  /* 94 SP F JP L K A */
    ken_atca_094,  /* 95 SP F JP L K B */
    ken_atca_096,  /* 96 SP B JP S P A */
    ken_atca_096,  /* 97 SP B JP S P B */
    ken_atca_098,  /* 98 SP B JP M P A */
    ken_atca_098,  /* 99 SP B JP M P B */
    ken_atca_100,  /* 100 SP B JP L P A */
    ken_atca_100,  /* 101 SP B JP L P B */
    ken_atca_102,  /* 102 SP B JP S K A */
    ken_atca_102,  /* 103 SP B JP S K B */
    ken_atca_104,  /* 104 SP B JP M K A */
    ken_atca_104,  /* 105 SP B JP M K B */
    ken_atca_106,  /* 106 SP B JP L K A */
    ken_atca_106,  /* 107 SP B JP L K B */
    ken_atca_108,  /* 108 S V JP S P A */
    ken_atca_108,  /* 109 S V JP S P B */
    ken_atca_110,  /* 110 S V JP M P A */
    ken_atca_110,  /* 111 S V JP M P B */
    ken_atca_112,  /* 112 S V JP L P A */
    ken_atca_112,  /* 113 S V JP L P B */
    ken_atca_114,  /* 114 S V JP S K A */
    ken_atca_114,  /* 115 S V JP S K B */
    ken_atca_116,  /* 116 S V JP M K A */
    ken_atca_116,  /* 117 S V JP M K B */
    ken_atca_118,  /* 118 S V JP L K A */
    ken_atca_118,  /* 119 S V JP L K B */
    ken_atca_108,  /* 120 S F JP S P A */
    ken_atca_108,  /* 121 S F JP S P B */
    ken_atca_110,  /* 122 S F JP M P A */
    ken_atca_110,  /* 123 S F JP M P B */
    ken_atca_112,  /* 124 S F JP L P A */
    ken_atca_112,  /* 125 S F JP L P B */
    ken_atca_114,  /* 126 S F JP S K A */
    ken_atca_114,  /* 127 S F JP S K B */
    ken_atca_116,  /* 128 S F JP M K A */
    ken_atca_116,  /* 129 S F JP M K B */
    ken_atca_118,  /* 130 S F JP L K A */
    ken_atca_118,  /* 131 S F JP L K B */
    ken_atca_108,  /* 132 S B JP S P A */
    ken_atca_108,  /* 133 S B JP S P B */
    ken_atca_110,  /* 134 S B JP M P A */
    ken_atca_110,  /* 135 S B JP M P B */
    ken_atca_112,  /* 136 S B JP L P A */
    ken_atca_112,  /* 137 S B JP L P B */
    ken_atca_114,  /* 138 S B JP S K A */
    ken_atca_114,  /* 139 S B JP S K B */
    ken_atca_116,  /* 140 S B JP M K A */
    ken_atca_116,  /* 141 S B JP M K B */
    ken_atca_118,  /* 142 S B JP L K A */
    ken_atca_118,  /* 143 S B JP L K B */
    ken_atca_144,  /* 144 TUKAMIKAKARI A */
    ken_atca_145,  /* 145 TUKAMIKAKARI B */
    ken_atca_146,  /* 146 TUKAMIKAKARI C */
    ken_atca_144,  /* 147 TUKAMIKAKARI D */
    ken_atca_144,  /* 148 TUKAMIKAKARI E */
    ken_atca_144,  /* 149 TUKAMIKAKARI F */
    ken_atca_144,  /* 150 TUKAMI AIR A */
    ken_atca_144,  /* 151 TUKAMI AIR B */
    ken_atca_144,  /* 152 TUKAMI AIR C */
    ken_atca_144,  /* 153 TUKAMI AIR D */
    ken_atca_144,  /* 154 TUKAMI AIR E */
    ken_atca_144,  /* 155 TUKAMI AIR F */
    ken_atca_156,  /* 156 follow-up of M KICK A */
    ken_atca_157,  /* 157 follow-up of M PUNCH A */
    ken_atca_158,  /* 158 no name */
    ken_atca_159,  /* 159 no name */
    ken_atca_160,  /* 160 no name */
    ken_atca_161,  /* 161 no name */
    ken_atca_162,  /* 162 no name */
    ken_atca_163,  /* 163 no name */
    ken_atca_164,  /* 164 no name */
    ken_atca_165,  /* 165 no name */
    ken_atca_166,  /* 166 no name */
    ken_atca_167,  /* 167 no name */
    ken_atca_168,  /* 168 no name */
    ken_atca_169,  /* 169 no name */
    0
};

/* script: 161 no name */
const u16 ken_atca_161_head[4] = { HEAD(4, 0, 0, 8, 0, 0, 0) };
const u16 ken_atca_161[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4228, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4229, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4590, 0, 1, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4591, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4592, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4593, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4594, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 162 no name */
const u16 ken_atca_162_head[4] = { HEAD(4, 0, 0, 8, 0, 0, 0) };
const u16 ken_atca_162[60] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4596, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4597, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4598, 0, 1, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4599, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4202, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4202, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 163 no name */
const u16 ken_atca_163_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_163[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x459A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x459B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x459C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x459D, 0, 1, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x459E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x459F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 164 no name */
const u16 ken_atca_164_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_164[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45A0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 388, 0, 0, 0, 0, 0x45A1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x45A2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45A3, 0, 1, 0, 128, 96, 32, 43),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45A4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45A5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45A6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45A7, 0, 1, 0, 0, 0, 32, 44),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45A8, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45A9, 0, 1, 0, 0, 0, 32, 45),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 165 no name */
const u16 ken_atca_165_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_165[68] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x45AA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45AC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45AD, 0, 1, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45AF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 166 no name */
const u16 ken_atca_166_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_166[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 1, 0, 0, 0, 32, 46),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B2, 0, 1, 0, 0, 0, 32, 47),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B3, 0, 1, 0, 128, 96, 32, 48),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B4, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45B5, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45B6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 167 no name */
const u16 ken_atca_167_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_167[140] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 1, 0, 0, 0, 32, 128),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B9, 0, 1, 0, 0, 0, 32, 129),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BA, 0, 1, 0, 128, 96, 32, 130),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45BB, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x45BC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C0, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x45C1, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C2, 0, 1, 0, 0, 0, 32, 131),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C4, 0, 1, 0, 0, 0, 32, 131),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4202, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4202, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 168 no name */
const u16 ken_atca_168_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_168[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 1, 0, 0, 0, 32, 46),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B2, 0, 1, 0, 0, 0, 32, 47),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C5, 0, 1, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C4, 0, 1, 0, 0, 0, 32, 47),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 169 no name */
const u16 ken_atca_169_head[4] = { HEAD(6, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_169[160] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(2, 0, 388, 0, 0, 0, 0, 0x43E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E3, 0, 46, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x43E4, 0, 47, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E5, -14, 48, 0, 72, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E6, 0, 48, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x43E7, 0, 47, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x45C8, 0, 1, 0, 128, 96, 0, 0, 0, 0, 24, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x45C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x4594, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4595, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 0 S PUNCH A */
const u16 ken_atca_000_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ken_atca_000[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4380, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4381, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4382, -3, 19, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4383, 0, 20, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4383, 0, 21, 272, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4384, 0, 1, 272, 0, 8, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4386, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4386, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 ken_atca_001_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 ken_atca_001[84] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x4360, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4363, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4360, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4361, -4, 22, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4362, 0, 22, 272, 0, 120, 0, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4362, 0, 23, 272, 0, 120, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4363, 0, 1, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4364, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4364, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 ken_atca_003_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 ken_atca_003[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4387, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4388, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4389, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x438A, -5, 24, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x438B, 0, 24, 2255, 0, 104, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x439B, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x438C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 ken_atca_004_head[4] = { HEAD(4, 0, 2, 12, 0, 1, 0) };
const u16 ken_atca_004[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4365, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x4366, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4367, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4368, -6, 25, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4369, 0, 26, 0, 128, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x437B, 0, 27, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x436A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x436B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 ken_atca_006_head[4] = { HEAD(4, 0, 4, 10, 0, 1, 0) };
const u16 ken_atca_006[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x438D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 388, 0, 0, 0, 0, 0x438E, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x438F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4390, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4391, -7, 32, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4392, 0, 33, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4393, 0, 34, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4394, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4395, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4396, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4397, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4398, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 ken_atca_007_head[4] = { HEAD(4, 0, 4, 11, 0, 1, 0) };
const u16 ken_atca_007[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x436C, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x436D, 0, 35, 0, 0, 0, 32, 16),
    L4(3, 0, 388, 1, 0, 0, 0, 0x436E, 0, 35, 0, 0, 0, 32, 17),
    L4(2, 0, 270, 1, 0, 0, 0, 0x436F, 0, 35, 0, 0, 0, 32, 18),
    L4(2, 0, 0, 1, 0, 0, 0, 0x4370, -9, 36, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x4371, 0, 36, 0, 0, 0, 32, 18),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4372, 0, 35, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4373, 0, 35, 0, 0, 0, 32, 19),
    L4(5, 0, 0, 0, 0, 0, 0, 0x437D, 0, 35, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4374, 0, 35, 0, 0, 0, 32, 20),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4375, 0, 35, 0, 0, 0, 32, 21),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 ken_atca_009_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 0) };
const u16 ken_atca_009[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x43C0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x43C1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x43C2, -10, 37, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43C3, 0, 38, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43C4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 ken_atca_012_head[4] = { HEAD(4, 0, 3, 11, 0, 1, 0) };
const u16 ken_atca_012[220] = {
    CMD(CM_RJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 1, 0, 0, 0, 32, 98),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43E1, 0, 1, 0, 0, 0, 32, 99),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43E2, 0, 1, 0, 0, 0, 32, 98),
    L4(1, 0, 269, 0, 0, 0, 0, 0x43A0, 0, 39, 0, 0, 0, 32, 100),
    L4(4, 0, 0, 0, 0, 0, 0, 0x43A1, -13, 40, 0, 136, 0, 32, 101),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x43A1, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x43A1, 0, 40, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 512, 8194, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x43A2, 0, 40, 0, 64, 0, 0, 0),
    CMD(CM_IF_S, 512, 8194, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x43A3, 0, 39, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43A4, 0, 41, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43A5, 0, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43A6, 0, 41, 0, 0, 0, 32, 99),
    CMD(CM_RMJA, 4, 12, 25), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x43EA, 0, 1, 3213, 0, 8, 31, 1),
    CMD(CM_RMJA, 4, 12, 26), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x43EB, 0, 1, 3213, 0, 8, 32, 102),
    L4(3, 64, 0, 0, 0, 0, 0, 0x43EC, 0, 1, 0, 0, 0, 32, 102),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4275, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 208, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 1, 0, 0, 0, 32, 103),
    CMD(CM_JMP, 4, 15, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 ken_atca_013_head[4] = { HEAD(4, 0, 3, 14, 0, 1, 0) };
const u16 ken_atca_013[132] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CA, 0, 176, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CB, 0, 177, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CC, 0, 177, 0, 0, 0, 32, 137),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 178, 0, 0, 0, 32, 138),
    CMD(CM_ASXY, 278, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 269, 0, 0, 0, 0, 0x45B2, 0, 178, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B3, -43, 179, 0, 128, 0, 32, 137),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B4, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B4, 0, 181, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B5, 0, 181, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B6, 0, 182, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B7, 0, 183, 0, 0, 0, 32, 140),
    L4(3, 64, 0, 0, 0, 0, 0, 0x45B8, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 ken_atca_014_head[4] = { HEAD(4, 0, 3, 14, 0, 2, 3) };
const u16 ken_atca_014[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x43CE, 0, 1, 0, 0, 0, 32, 58),
    L4(3, 0, 388, 0, 0, 0, 0, 0x43CF, 0, 42, 0, 0, 0, 32, 59),
    L4(4, 0, 0, 0, 0, 0, 0, 0x43D1, 0, 42, 0, 0, 0, 32, 59),
    L4(6, 0, 0, 0, 0, 0, 0, 0x43D2, 0, 42, 0, 0, 0, 32, 60),
    L4(3, 0, 269, 0, 0, 0, 0, 0x43D3, 0, 42, 0, 0, 0, 32, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43D4, -11, 43, 0, 0, 0, 32, 60),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43D5, -12, 44, 0, 0, 0, 32, 61),
    CMD(CM_ASXY, 124, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x43D6, 0, 45, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43D7, 0, 42, 0, 0, 0, 32, 62),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43D8, 0, 1, 0, 0, 0, 32, 61),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 32, 60),
    L4(4, 0, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x439A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 ken_atca_015_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 ken_atca_015[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(2, 0, 388, 0, 0, 0, 0, 0x43E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E3, 0, 46, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x43E4, 0, 47, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E5, -14, 48, 0, 72, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E6, 0, 48, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E7, 0, 47, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E9, 0, 49, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 ken_atca_017_head[4] = { HEAD(4, 0, 5, 14, 0, 1, 0) };
const u16 ken_atca_017[268] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CA, 0, 176, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CB, 0, 177, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CC, 0, 177, 0, 0, 0, 32, 137),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 178, 0, 0, 0, 32, 138),
    CMD(CM_IFS2, 1024, 8192, 16394), 0, 0, 0, 0,
    CMD(CM_ASXY, 278, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B2, 0, 178, 0, 0, 0, 33, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C5, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C6, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C7, 0, 188, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C4, 0, 188, 0, 0, 0, 32, 143),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B9, 0, 178, 0, 0, 0, 32, 139),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BA, 0, 184, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x45BC, 0, 184, 0, 0, 0, 33, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x45BD, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BE, -41, 185, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45BF, 42, 186, 0, 128, 0, 0, 0),
    CMD(CM_HJMP, 16390, 16390, 16390), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C0, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C1, 0, 187, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C2, 0, 187, 0, 0, 0, 32, 141),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C3, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x45C0, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C1, 0, 187, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C2, 0, 187, 0, 0, 0, 32, 141),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C3, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x45C4, 0, 188, 0, 0, 0, 32, 142),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 ken_atca_018_head[4] = { HEAD(4, 32, 0, 10, 0, 1, 0) };
const u16 ken_atca_018[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x43F0, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x43F1, -19, 51, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F2, 0, 51, 272, 0, 120, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F4, 0, 52, 272, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F3, 0, 2, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 ken_atca_021_head[4] = { HEAD(4, 32, 2, 10, 0, 1, 0) };
const u16 ken_atca_021[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x43F0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x43F0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x43F1, -20, 53, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43F2, 0, 51, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F2, 0, 52, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43F3, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x43F0, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 ken_atca_024_head[4] = { HEAD(4, 32, 4, 9, 0, 1, 0) };
const u16 ken_atca_024[108] = {
    L4(4, 0, 389, 0, 0, 0, 0, 0x43FC, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x43FD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x43FE, -21, 54, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43FF, 22, 55, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4400, 0, 56, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x4400, 0, 57, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4401, 0, 57, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4402, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4403, 0, 59, 0, 0, 0, 22, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4404, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 ken_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 ken_atca_027[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4411, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x4411, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4412, -23, 60, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4413, 0, 60, 272, 0, 120, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4414, 0, 2, 272, 0, 24, 21, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4411, 0, 2, 272, 0, 24, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4410, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4410, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4415, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 ken_atca_030_head[4] = { HEAD(4, 32, 3, 13, 0, 1, 0) };
const u16 ken_atca_030[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4416, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4424, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4417, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4418, -24, 61, 0, 135, 96, 32, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4419, 0, 62, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x441A, 0, 62, 0, 128, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x441A, 0, 63, 0, 0, 96, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x441B, 0, 2, 0, 0, 0, 32, 33),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4424, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4425, 0, 2, 0, 0, 0, 32, 34),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 32, 34),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 ken_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 1, 0) };
const u16 ken_atca_033[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4416, 0, 2, 0, 0, 0, 32, 35),
    L4(2, 0, 388, 0, 0, 0, 0, 0x441C, 0, 2, 0, 0, 0, 32, 36),
    L4(2, 0, 270, 0, 0, 0, 0, 0x441D, 0, 2, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x441E, -25, 64, 0, 64, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x441F, 0, 64, 0, 64, 0, 0, 0),
    CMD(CM_ASXY, 74, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4420, 0, 65, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4421, 0, 65, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4422, 0, 2, 0, 0, 0, 32, 39),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4423, 0, 2, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4424, 0, 2, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4425, 0, 2, 0, 0, 0, 32, 42),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 32, 42),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 ken_atca_036_head[4] = { HEAD(4, 22, 0, 7, 0, 1, 0) };
const u16 ken_atca_036[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x4430, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x4431, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x4432, -26, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4433, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4434, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4435, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4433, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4434, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4435, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 ken_atca_038_head[4] = { HEAD(4, 22, 2, 10, 0, 1, 0) };
const u16 ken_atca_038[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4441, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x4442, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4443, -27, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4444, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4448, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4445, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4446, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4447, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 ken_atca_040_head[4] = { HEAD(4, 22, 4, 13, 0, 1, 0) };
const u16 ken_atca_040[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x444E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x444F, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4450, -28, 104, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4451, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4453, 0, 106, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4454, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 ken_atca_042_head[4] = { HEAD(4, 22, 1, 6, 0, 1, 0) };
const u16 ken_atca_042[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4465, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4466, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4460, -29, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4461, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4462, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4463, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4461, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4462, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4463, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4464, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 ken_atca_044_head[4] = { HEAD(4, 22, 3, 12, 0, 1, 0) };
const u16 ken_atca_044[100] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 269, 0, 0, 0, 0, 0x446D, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x446E, -30, 109, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x446F, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4470, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4470, 0, 111, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4471, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4472, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 ken_atca_046_head[4] = { HEAD(4, 22, 5, 12, 0, 1, 0) };
const u16 ken_atca_046[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4473, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4474, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4475, -31, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4476, 0, 113, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4477, 0, 114, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4478, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4247, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 ken_atca_048_head[4] = { HEAD(4, 20, 0, 9, 0, 1, 0) };
const u16 ken_atca_048[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x4430, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x4431, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x4432, -32, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4433, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4434, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x4435, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4433, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4434, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4435, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 ken_atca_050_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 ken_atca_050[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4441, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4442, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4443, -33, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4444, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4448, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4445, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4446, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4447, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 ken_atca_052_head[4] = { HEAD(4, 20, 4, 13, 0, 1, 0) };
const u16 ken_atca_052[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4441, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x4442, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4443, -34, 98, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4444, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4448, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4445, 0, 73, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4446, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4447, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 ken_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 ken_atca_054[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4465, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4466, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4460, -35, 107, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4461, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4462, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4463, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4464, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 ken_atca_056_head[4] = { HEAD(4, 20, 3, 13, 0, 1, 0) };
const u16 ken_atca_056[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4465, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4466, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4573, -36, 115, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4574, 0, 116, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4575, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4576, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 ken_atca_058_head[4] = { HEAD(4, 20, 5, 14, 0, 1, 0) };
const u16 ken_atca_058[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4465, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4466, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4467, -37, 118, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4468, 0, 119, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4469, 0, 119, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x446A, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x446C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 ken_atca_060_head[4] = { HEAD(2, 24, 0, 9, 0, 1, 0) };
const u16 ken_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 ken_atca_062_head[4] = { HEAD(2, 24, 2, 10, 0, 1, 0) };
const u16 ken_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 ken_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 ken_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 ken_atca_066_head[4] = { HEAD(2, 24, 1, 6, 0, 1, 0) };
const u16 ken_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 ken_atca_068_head[4] = { HEAD(2, 24, 3, 12, 0, 1, 0) };
const u16 ken_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 ken_atca_070_head[4] = { HEAD(2, 24, 5, 12, 0, 1, 0) };
const u16 ken_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 ken_atca_072_head[4] = { HEAD(2, 28, 0, 8, 0, 1, 0) };
const u16 ken_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 ken_atca_074_head[4] = { HEAD(2, 28, 2, 11, 0, 1, 0) };
const u16 ken_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 ken_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 ken_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 ken_atca_078_head[4] = { HEAD(2, 28, 1, 6, 0, 1, 0) };
const u16 ken_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 ken_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 ken_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 ken_atca_082_head[4] = { HEAD(2, 28, 5, 12, 0, 1, 0) };
const u16 ken_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 ken_atca_084_head[4] = { HEAD(2, 26, 0, 9, 0, 1, 0) };
const u16 ken_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 ken_atca_086_head[4] = { HEAD(2, 26, 2, 13, 0, 1, 0) };
const u16 ken_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 ken_atca_088_head[4] = { HEAD(2, 26, 4, 13, 0, 1, 0) };
const u16 ken_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 ken_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 ken_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 ken_atca_092_head[4] = { HEAD(2, 26, 3, 13, 0, 1, 0) };
const u16 ken_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 ken_atca_094_head[4] = { HEAD(2, 26, 5, 14, 0, 1, 0) };
const u16 ken_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 ken_atca_096_head[4] = { HEAD(2, 30, 0, 9, 0, 1, 0) };
const u16 ken_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 ken_atca_098_head[4] = { HEAD(2, 30, 2, 10, 0, 1, 0) };
const u16 ken_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 ken_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 ken_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 ken_atca_102_head[4] = { HEAD(2, 30, 1, 6, 0, 1, 0) };
const u16 ken_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 ken_atca_104_head[4] = { HEAD(2, 30, 3, 12, 0, 1, 0) };
const u16 ken_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 ken_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 ken_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 ken_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 1, 0) };
const u16 ken_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 ken_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 1, 0) };
const u16 ken_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 ken_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 1, 0) };
const u16 ken_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 ken_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 1, 0) };
const u16 ken_atca_114[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 ken_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 1, 0) };
const u16 ken_atca_116[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 ken_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 1, 0) };
const u16 ken_atca_118[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 ken_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_atca_144[92] = {
    CMD(CM_CAFR, 2, 1, 8), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 8), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4360, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x4360, -48, 97, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4480, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45D4, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x45D5, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45D6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45D7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x45D7, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x45D7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 ken_atca_145_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_atca_145[16] = {
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 ken_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 21),
    CMD(CM_CARE, 2, 2, 21),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of M KICK A */
const u16 ken_atca_156_head[4] = { HEAD(4, 0, 5, 14, 0, 2, 0) };
const u16 ken_atca_156[60] = {
    L4(1, 0, 388, 0, 0, 0, 0, 0x43A2, 0, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x43DA, 0, 39, 0, 0, 0, 32, 60),
    L4(2, 0, 0, 0, 0, 0, 0, 0x43DB, 0, 42, 0, 0, 0, 32, 61),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43DC, 0, 42, 0, 0, 0, 32, 61),
    L4(3, 0, 0, 0, 0, 0, 0, 0x43D0, 0, 42, 0, 0, 0, 32, 61),
    L4(5, 0, 0, 0, 0, 0, 0, 0x43D1, 0, 42, 0, 0, 0, 32, 62),
    CMD(CM_JMP, 4, 14, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of M PUNCH A */
const u16 ken_atca_157_head[4] = { HEAD(4, 0, 4, 10, 0, 1, 0) };
const u16 ken_atca_157[108] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x438F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 388, 0, 0, 0, 0, 0x438F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4390, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4391, -8, 32, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4392, 0, 33, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4393, 0, 34, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x4394, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4395, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4396, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4397, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4398, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4399, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 no name */
const u16 ken_atca_158_head[4] = { HEAD(4, 0, 5, 14, 0, 2, 0) };
const u16 ken_atca_158[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CA, 0, 176, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CB, 0, 177, 0, 0, 0, 32, 136),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CC, 0, 177, 0, 0, 0, 32, 137),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 178, 0, 0, 0, 32, 138),
    L4(4, 0, 269, 0, 0, 0, 0, 0x45B2, 0, 178, 0, 0, 0, 32, 139),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B3, -43, 179, 0, 128, 0, 32, 137),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45B4, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B5, 0, 181, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B6, 0, 182, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45B7, 0, 183, 0, 0, 0, 32, 140),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B8, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 no name */
const u16 ken_atca_159_head[4] = { HEAD(4, 0, 5, 14, 0, 2, 0) };
const u16 ken_atca_159[140] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CA, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CB, 0, 177, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CC, 0, 177, 0, 0, 0, 32, 137),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 178, 0, 0, 0, 32, 138),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B9, 0, 178, 0, 0, 0, 32, 139),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BA, 0, 184, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x45BC, 0, 184, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x45BD, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45BE, -41, 185, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x45BF, 42, 186, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C0, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C1, 0, 187, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C2, 0, 187, 0, 0, 0, 32, 141),
    L4(5, 0, 0, 0, 0, 0, 0, 0x45C3, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C4, 0, 188, 0, 0, 0, 32, 142),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 no name */
const u16 ken_atca_160_head[4] = { HEAD(4, 0, 5, 14, 0, 2, 0) };
const u16 ken_atca_160[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x45CA, 0, 176, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CB, 0, 177, 0, 0, 0, 32, 136),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45CC, 0, 177, 0, 0, 0, 32, 137),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B1, 0, 178, 0, 0, 0, 32, 138),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45B2, 0, 178, 0, 0, 0, 32, 139),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C5, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45C6, 0, 178, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C7, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x45C4, 0, 188, 0, 0, 0, 32, 143),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX ken_olc_ix_table[24] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
    { { 7, 0, 0, 0 } },
    { { 9, 21, 0, 0 } },
    { { 11, 21, 0, 0 } },
    { { 13, 0, 0, 0 } },
    { { 13, 27, 0, 0 } },
    { { 17, 0, 0, 0 } },
    { { 19, 0, 0, 0 } },
    { { 21, 0, 0, 0 } },
    { { 23, 0, 0, 0 } },
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
};

const OVERLAP_PARTS ken_overlap_char_tbl[42] = {
    { 0, 0, 0, 8, 2, 0, 255, 0, 0, 0, 0 },
    { 26, 52, 0, 8, 2, 0, 1, 0, 0, 0, 741 },
    { 26, 52, 0, 8, 1, 0, 1, 0, 0, 1, 741 },
    { -2, -38, 0, 8, 2, 1, 1, 0, 0, 0, 784 },
    { -2, -38, 0, 8, 1, 1, 1, 0, 0, 3, 784 },
    { 48, 104, 0, 8, 2, 2, 1, 0, 0, 0, 947 },
    { 48, 104, 0, 8, 1, 2, 1, 0, 0, 5, 947 },
    { 13, 124, 0, 8, 2, 2, 1, 0, 0, 0, 948 },
    { 13, 124, 0, 8, 1, 2, 1, 0, 0, 7, 948 },
    { 62, 170, 0, 8, 2, 2, 1, 0, 0, 0, 885 },
    { 62, 170, 0, 8, 1, 2, 1, 0, 0, 9, 885 },
    { 62, 154, 0, 8, 2, 2, 1, 0, 0, 0, 885 },
    { 62, 154, 0, 8, 1, 2, 1, 0, 0, 11, 885 },
    { 40, 196, 0, 8, 2, 2, 1, 0, 0, 0, 948 },
    { 40, 196, 0, 8, 1, 2, 1, 0, 0, 13, 948 },
    { -41, 69, 0, 8, 2, 2, 1, 0, 0, 0, 949 },
    { -41, 69, 0, 8, 1, 2, 1, 0, 0, 15, 949 },
    { 86, 186, 0, 8, 2, 2, 1, 0, 0, 0, 869 },
    { 86, 186, 0, 8, 1, 2, 1, 0, 0, 17, 869 },
    { 58, 6, 0, 8, 2, 0, 1, 0, 0, 0, 917 },
    { 58, 6, 0, 8, 1, 0, 1, 0, 0, 19, 917 },
    { 64, 208, 0, 8, 2, 2, 1, 0, 0, 0, 884 },
    { 64, 208, 0, 8, 1, 2, 1, 0, 0, 21, 884 },
    { 54, 56, 0, 8, 2, 2, 1, 0, 0, 0, 867 },
    { 54, 56, 0, 8, 1, 2, 1, 0, 0, 23, 867 },
    { 63, 19, 0, 8, 2, 2, 1, 0, 0, 0, 884 },
    { 63, 19, 0, 8, 1, 2, 1, 0, 0, 25, 884 },
    { 35, 26, 0, 8, 2, 0, 1, 0, 0, 0, 915 },
    { 35, 26, 0, 8, 1, 0, 1, 0, 0, 27, 915 },
    { 58, 53, 0, 8, 2, 2, 1, 0, 0, 0, 870 },
    { 58, 53, 0, 8, 1, 2, 1, 0, 0, 29, 870 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 31, 17888 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 32, 17889 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 33, 17890 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 34, 17891 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 35, 17892 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 36, 17893 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 37, 17894 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 38, 17895 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 39, 17896 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 40, 17897 },
    { 0, 0, 0, 8, 2, 0, 250, 1, 0, 41, 17898 },
};

const CatchTable ken_rival_catch_tbl[1080] = {
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
    { -2, 64, 1, 1, 8 },
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
    { -96, 0, 1, 1, 1 },
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
    { -96, 0, 1, 1, 1 },
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
    { -90, 0, 2, 1, 2 },
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
    { -90, 0, 2, 1, 2 },
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
    { -60, 0, 2, 1, 3 },
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
    { -60, 0, 2, 1, 3 },
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
    { -32, 0, 1, 1, 4 },
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
    { -32, 0, 1, 1, 4 },
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
    { -28, -14, 1, 1, 5 },
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
    { -28, -14, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -27, 8, 1, 1, 5 },
    { -35, 7, 1, 1, 5 },
    { -55, 0, 1, 1, 5 },
    { -45, 0, 1, 1, 5 },
    { -36, 0, 2, 1, 5 },
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
    { 57, 152, 1, 1, 7 },
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
    { 69, 62, 2, 1, 8 },
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
    { -80, 0, 2, 1, 1 },
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
    { -80, 0, 1, 1, 2 },
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
    { -40, 0, 2, 1, 3 },
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
    { -59, 8, 2, 1, 4 },
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
    { -59, 8, 1, 1, 5 },
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
    { -56, 16, 1, 1, 6 },
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
    { -76, 16, 1, 1, 7 },
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
    { -72, 30, 1, 1, 8 },
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
    { -48, 4, 1, 1, 9 },
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
    { -66, 26, 2, 1, 12 },
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
    { -96, 0, 1, 1, 1 },
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
    { -96, 0, 1, 1, 1 },
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
    { -90, 0, 2, 1, 2 },
    { -97, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -83, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -102, 0, 1, 1, 2 },
    { -63, 0, 2, 1, 2 },
    { -44, 2, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -79, 0, 1, 1, 2 },
    { -90, 0, 2, 1, 2 },
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
    { -60, 0, 2, 1, 3 },
    { -33, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -45, 0, 1, 1, 3 },
    { -55, 1, 1, 1, 3 },
    { -71, 0, 1, 1, 3 },
    { -77, 0, 1, 1, 3 },
    { -46, 1, 2, 1, 3 },
    { -24, 4, 2, 1, 3 },
    { -58, 4, 2, 1, 3 },
    { -45, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -60, 0, 2, 1, 3 },
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
    { -32, 0, 1, 1, 4 },
    { -48, 4, 1, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -52, 20, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -47, 2, 1, 1, 4 },
    { -63, -5, 1, 1, 4 },
    { -35, 5, 1, 1, 4 },
    { -34, 4, 1, 1, 4 },
    { -42, -2, 2, 1, 4 },
    { -52, 20, 1, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -32, 0, 1, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -49, -5, 1, 1, 4 },
    { -39, 7, 2, 1, 4 },
    { -37, 0, 2, 1, 4 },
    { -45, 0, 2, 1, 4 },
    { -36, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -72, -32, 1, 1, 5 },
    { -58, -40, 1, 1, 5 },
    { -21, -39, 1, 1, 5 },
    { -44, -34, 1, 1, 5 },
    { -36, -24, 1, 1, 5 },
    { -56, -36, 1, 1, 5 },
    { -46, -50, 1, 1, 5 },
    { -18, -52, 1, 1, 5 },
    { -40, -20, 2, 1, 5 },
    { -42, -26, 1, 1, 5 },
    { -44, -34, 1, 1, 5 },
    { -21, -39, 1, 1, 5 },
    { -21, -39, 1, 1, 5 },
    { -72, -32, 1, 1, 5 },
    { -21, -39, 1, 1, 5 },
    { -22, 2, 1, 1, 5 },
    { -44, -38, 1, 1, 5 },
    { -42, -34, 1, 1, 5 },
    { -36, -60, 1, 1, 5 },
    { -42, 96, 1, 1, 5 },
    { -32, -36, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -14, -30, 1, 1, 6 },
    { -10, -42, 1, 1, 6 },
    { 0, -34, 2, 1, 6 },
    { -18, -34, 1, 1, 6 },
    { 10, -28, 2, 1, 6 },
    { -18, -22, 1, 1, 6 },
    { -28, -62, 1, 1, 6 },
    { 4, -54, 1, 1, 6 },
    { -18, -24, 1, 1, 6 },
    { -54, -2, 1, 1, 6 },
    { -18, -34, 1, 1, 6 },
    { 0, -34, 2, 1, 6 },
    { 0, -34, 2, 1, 6 },
    { -14, -30, 1, 1, 6 },
    { 0, -34, 2, 1, 6 },
    { -22, 2, 1, 1, 6 },
    { -4, 88, 1, 1, 6 },
    { -8, -46, 1, 1, 6 },
    { -20, -20, 1, 1, 6 },
    { -6, -22, 1, 1, 6 },
    { -14, 30, 1, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 26, -46, 1, 1, 7 },
    { 16, -18, 1, 1, 7 },
    { 12, 78, 1, 1, 7 },
    { 6, -18, 1, 1, 7 },
    { 16, 84, 1, 1, 7 },
    { 24, -36, 1, 1, 7 },
    { -10, -48, 1, 1, 7 },
    { 14, 84, 1, 1, 7 },
    { 4, 44, 2, 1, 7 },
    { -14, -40, 1, 1, 7 },
    { 6, -18, 1, 1, 7 },
    { 6, 78, 1, 1, 7 },
    { 6, 78, 1, 1, 7 },
    { 6, -46, 1, 1, 7 },
    { 20, 72, 1, 1, 7 },
    { -22, 2, 1, 1, 7 },
    { -2, 82, 1, 1, 7 },
    { 14, 2, 1, 1, 7 },
    { -4, -18, 1, 1, 7 },
    { 30, 84, 1, 1, 7 },
    { 12, 92, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 26, -34, 1, 1, 8 },
    { 54, -26, 2, 1, 8 },
    { 54, -18, 1, 1, 8 },
    { 60, -18, 1, 1, 8 },
    { 46, -24, 2, 1, 8 },
    { 32, -44, 2, 1, 8 },
    { 30, 108, 1, 1, 8 },
    { 42, -22, 1, 1, 8 },
    { -4, 46, 2, 1, 8 },
    { 40, -20, 2, 1, 8 },
    { 60, -18, 1, 1, 8 },
    { 54, -18, 1, 1, 8 },
    { 54, -18, 1, 1, 8 },
    { 26, -34, 1, 1, 8 },
    { 54, -18, 1, 1, 8 },
    { -22, 2, 1, 1, 8 },
    { 16, -22, 2, 1, 8 },
    { 28, -20, 1, 1, 8 },
    { 6, -30, 1, 1, 8 },
    { 42, -58, 1, 1, 8 },
    { 34, -18, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 14, -14, 1, 1, 9 },
    { 30, -36, 1, 1, 9 },
    { 18, -26, 1, 1, 9 },
    { 30, -24, 1, 1, 9 },
    { 42, -20, 1, 1, 9 },
    { 20, -64, 2, 1, 9 },
    { 16, 70, 1, 1, 9 },
    { 14, -20, 1, 1, 9 },
    { 20, -18, 1, 1, 9 },
    { 36, 56, 2, 1, 9 },
    { 30, -24, 1, 1, 9 },
    { 18, -26, 1, 1, 9 },
    { 18, -26, 1, 1, 9 },
    { 14, -14, 1, 1, 9 },
    { 18, -26, 1, 1, 9 },
    { -22, 2, 1, 1, 9 },
    { 18, -32, 1, 1, 9 },
    { 4, -18, 1, 1, 9 },
    { 6, -40, 1, 1, 9 },
    { 32, -72, 1, 1, 9 },
    { 16, -26, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 12, -80, 1, 1, 10 },
    { 2, -26, 1, 1, 10 },
    { 4, -68, 1, 1, 10 },
    { 0, -42, 1, 1, 10 },
    { 28, -38, 1, 1, 10 },
    { 22, -14, 1, 1, 10 },
    { -4, -104, 1, 1, 10 },
    { 8, -72, 1, 1, 10 },
    { 12, -38, 2, 1, 10 },
    { -10, -56, 2, 1, 10 },
    { 0, -42, 1, 1, 10 },
    { 4, -68, 1, 1, 10 },
    { 4, -68, 1, 1, 10 },
    { 12, -80, 1, 1, 10 },
    { 4, -68, 1, 1, 10 },
    { -22, 2, 1, 1, 10 },
    { 8, -78, 1, 1, 10 },
    { -26, -24, 1, 1, 10 },
    { -32, -62, 1, 1, 10 },
    { -8, -90, 1, 1, 10 },
    { 6, -68, 1, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -24, -60, 1, 1, 11 },
    { -20, -54, 1, 1, 11 },
    { -26, -32, 1, 1, 11 },
    { 28, -40, 1, 1, 11 },
    { -16, -44, 2, 1, 11 },
    { 0, -52, 1, 1, 11 },
    { -32, -38, 1, 1, 11 },
    { -12, -46, 1, 1, 11 },
    { 10, -32, 2, 1, 11 },
    { 0, -46, 1, 1, 11 },
    { 28, -40, 1, 1, 11 },
    { -26, -32, 1, 1, 11 },
    { -26, -32, 1, 1, 11 },
    { -24, -60, 1, 1, 11 },
    { -26, -32, 1, 1, 11 },
    { -22, 2, 1, 1, 11 },
    { -8, -30, 2, 1, 11 },
    { -40, -26, 1, 1, 11 },
    { -42, -48, 1, 1, 11 },
    { -4, -32, 1, 1, 11 },
    { -28, 38, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 16, -34, 2, 1, 12 },
    { 22, 134, 2, 1, 12 },
    { 24, 70, 2, 1, 12 },
    { 11, 68, 2, 1, 12 },
    { 17, 144, 2, 1, 12 },
    { 8, 0, 1, 1, 12 },
    { 7, 15, 2, 1, 12 },
    { 4, 134, 2, 1, 12 },
    { 6, 26, 2, 1, 12 },
    { -20, 44, 2, 1, 12 },
    { 11, 68, 2, 1, 12 },
    { 24, 70, 2, 1, 12 },
    { 24, 70, 2, 1, 12 },
    { 9, 146, 2, 1, 12 },
    { 24, 70, 2, 1, 12 },
    { 24, 70, 2, 1, 12 },
    { 10, 134, 2, 1, 12 },
    { 24, 61, 1, 1, 12 },
    { 36, 79, 2, 1, 12 },
    { 8, 0, 2, 1, 12 },
    { 14, 4, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 56, 13, 2, 1, 13 },
    { 66, 38, 1, 1, 13 },
    { 59, 88, 2, 1, 13 },
    { 24, 116, 1, 1, 13 },
    { 57, 152, 1, 1, 13 },
    { 54, 24, 1, 1, 13 },
    { 44, 51, 1, 1, 13 },
    { 44, 108, 1, 1, 13 },
    { 53, 90, 1, 1, 13 },
    { 65, 124, 1, 1, 13 },
    { 24, 116, 1, 1, 13 },
    { 59, 88, 2, 1, 13 },
    { 59, 88, 2, 1, 13 },
    { 56, 13, 2, 1, 13 },
    { 59, 88, 2, 1, 13 },
    { 59, 88, 2, 1, 13 },
    { 51, 123, 1, 1, 13 },
    { 52, -5, 1, 1, 13 },
    { 50, -4, 1, 1, 13 },
    { 52, 9, 1, 1, 13 },
    { 64, 122, 1, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 92, 24, 2, 1, 14 },
    { 92, 52, 1, 1, 14 },
    { 85, 52, 2, 1, 14 },
    { 86, 58, 1, 1, 14 },
    { 94, 50, 2, 1, 14 },
    { 118, 98, 2, 1, 14 },
    { 72, 12, 2, 1, 14 },
    { 72, 44, 1, 1, 14 },
    { 69, 62, 1, 1, 14 },
    { 91, 66, 1, 1, 14 },
    { 86, 58, 1, 1, 14 },
    { 85, 52, 2, 1, 14 },
    { 85, 52, 2, 1, 14 },
    { 92, 24, 2, 1, 14 },
    { 85, 52, 2, 1, 14 },
    { 85, 52, 2, 1, 14 },
    { 81, 44, 2, 1, 14 },
    { 83, 68, 1, 1, 14 },
    { 81, 18, 1, 1, 14 },
    { 81, 13, 1, 1, 14 },
    { 110, 4, 1, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
};

/* extra scripts: 46 entries */
const u16* const ken_exca[47] = {
    ken_exca_000,  /* 0 follow-up of AIR NORMAL */
    ken_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    ken_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    ken_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    ken_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    ken_exca_005,  /* 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
    ken_exca_006,  /* 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
    ken_exca_007,  /* 7 no name */
    ken_exca_008,  /* 8 follow-up of KUNOJI, SPLASH.M +3 */
    ken_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +2 */
    ken_exca_010,  /* 10 follow-up of KIRIMOMI, IBUKI KUBIORI */
    ken_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    ken_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    ken_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    ken_exca_014,  /* 14 no name */
    ken_exca_015,  /* 15 no name */
    ken_exca_016,  /* 16 no name */
    ken_exca_017,  /* 17 follow-up of APPEAR JUNBI 1 */
    ken_exca_018,  /* 18 no name */
    ken_exca_019,  /* 19 no name */
    ken_exca_020,  /* 20 no name */
    ken_exca_021,  /* 21 no name */
    ken_exca_022,  /* 22 follow-up of APPEAR JUNBI 7 */
    ken_exca_023,  /* 23 follow-up of HARAIGOSHI, APPEAR JUNBI 7 */
    ken_exca_024,  /* 24 follow-up of APPEAR JUNBI 8, SP APPEAR 1 */
    ken_exca_025,  /* 25 follow-up of APPEAR JUNBI 8, SP APPEAR 1 */
    ken_exca_026,  /* 26 follow-up of APPEAR 1, APPEAR 4 */
    ken_exca_026,  /* 27 follow-up of APPEAR 1, APPEAR 4 */
    ken_exca_028,  /* 28 no name */
    ken_exca_029,  /* 29 follow-up of GILL IMPACT C */
    ken_exca_030,  /* 30 follow-up of GILL IMPACT C */
    ken_exca_031,  /* 31 follow-up of SP APPEAR 7 */
    ken_exca_032,  /* 32 follow-up of SP APPEAR 7 */
    ken_exca_033,  /* 33 follow-up of APPEAR 8 */
    ken_exca_034,  /* 34 follow-up of SP APPEAR 8 */
    ken_exca_035,  /* 35 follow-up of SP APPEAR 8 */
    ken_exca_036,  /* 36 follow-up of ZANNEN 1 */
    ken_exca_037,  /* 37 follow-up of ZANNEN 1 */
    ken_exca_038,  /* 38 follow-up of ZANNEN 2 */
    ken_exca_039,  /* 39 follow-up of ZANNEN 2 */
    ken_exca_038,  /* 40 follow-up of ZANNEN 3 */
    ken_exca_039,  /* 41 follow-up of ZANNEN 3 */
    ken_exca_042,  /* 42 follow-up of ZANNEN 4 */
    ken_exca_043,  /* 43 follow-up of ZANNEN 4 */
    ken_exca_044,  /* 44 follow-up of ZANNEN 5 */
    ken_exca_045,  /* 45 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 ken_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_000[100] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4252, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4251, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4250, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x424F, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424E, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424D, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424C, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4258, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 96, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x4257, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 ken_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_001[52] = {
    L4(1, 2, 273, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x424B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 ken_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_003[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x42FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 ken_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_004[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x424B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
const u16 ken_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_005[140] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x42E9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
const u16 ken_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_006[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x42ED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42F1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 no name */
const u16 ken_exca_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_007[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x452B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x452C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, SPLASH.M +3 */
const u16 ken_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_008[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4300, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4301, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4302, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x4303, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +2 */
const u16 ken_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_009[124] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x4300, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4301, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4302, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x4303, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, IBUKI KUBIORI */
const u16 ken_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_010[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x42FB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x42EF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 ken_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_011[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 ken_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_013[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 ken_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FA, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 ken_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_015[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 ken_exca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x4302, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x4301, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x42FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of APPEAR JUNBI 1 */
const u16 ken_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_017[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 273, 0, 0, 0, 0, 0x44C9, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44CA, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 ken_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 18, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 ken_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x4302, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x4301, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x42FF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x42E9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x42E9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 ken_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_020[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x4306, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4300, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x42FF, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4513, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x42FB, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FB, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 ken_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 3, 0, 0, 0x4306, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4300, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x42FF, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x4513, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x42FB, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42FB, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of APPEAR JUNBI 7 */
const u16 ken_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_022[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI, APPEAR JUNBI 7 */
const u16 ken_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_023[84] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(1, 0, 273, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4228, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 8, SP APPEAR 1 */
const u16 ken_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_024[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 274, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 22, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR JUNBI 8, SP APPEAR 1 */
const u16 ken_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_025[52] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 274, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4228, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4229, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 23, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 1, APPEAR 4, 27 follow-up of APPEAR 1, APPEAR 4 */
const u16 ken_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_026[52] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4284, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4285, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4286, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4287, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 no name */
const u16 ken_exca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_028[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x42E3, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42E4, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E5, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x42E6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x42E7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of GILL IMPACT C */
const u16 ken_exca_029_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_029[68] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x42FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of GILL IMPACT C */
const u16 ken_exca_030_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ken_exca_030[60] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x42FA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x42F4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x42F5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x42F6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x42F8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x42EE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of SP APPEAR 7 */
const u16 ken_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_031[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x452C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of SP APPEAR 7 */
const u16 ken_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_032[84] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4228, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR 8 */
const u16 ken_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_033[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x44C9, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44CA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x422A, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP APPEAR 8 */
const u16 ken_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_034[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x424B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 8 */
const u16 ken_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_035[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of ZANNEN 1 */
const u16 ken_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_036[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x422A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x424B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of ZANNEN 1 */
const u16 ken_exca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_037[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of ZANNEN 2, 40 follow-up of ZANNEN 3 */
const u16 ken_exca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_038[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x4283, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x4284, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4285, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4286, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4287, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of ZANNEN 2, 41 follow-up of ZANNEN 3 */
const u16 ken_exca_039_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_039[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4283, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4288, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of ZANNEN 4 */
const u16 ken_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_042[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x428C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4284, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4285, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4286, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4287, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x420D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of ZANNEN 4 */
const u16 ken_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ken_exca_043[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x4283, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x4288, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x4229, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of ZANNEN 5 */
const u16 ken_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_exca_044[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x44C9, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44CA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4349, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x434A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4229, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x422A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x422B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 ken_exca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_exca_045[100] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x4252, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4251, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4250, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x424F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x424D, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424C, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4258, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(50, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 65 entries */
const u16* const ken_saca[66] = {
    ken_saca_000,  /* 0 UP P GUARD P S */
    ken_saca_001,  /* 1 UP P GUARD P M */
    ken_saca_002,  /* 2 UP P GUARD P L */
    ken_saca_002,  /* 3 UP P GUARD K S */
    ken_saca_002,  /* 4 UP P GUARD K M */
    ken_saca_002,  /* 5 UP P GUARD K L */
    ken_saca_000,  /* 6 D P GUARD P S */
    ken_saca_001,  /* 7 D P GUARD P M */
    ken_saca_002,  /* 8 D P GUARD P L */
    ken_saca_002,  /* 9 D P GUARD K S */
    ken_saca_002,  /* 10 D P GUARD K M */
    ken_saca_002,  /* 11 D P GUARD K L */
    ken_saca_002,  /* 12 FUSHIN P S */
    ken_saca_002,  /* 13 FUSHIN P M */
    ken_saca_002,  /* 14 FUSHIN P L */
    ken_saca_002,  /* 15 FUSHIN K S */
    ken_saca_002,  /* 16 FUSHIN K M */
    ken_saca_002,  /* 17 FUSHIN K L */
    ken_saca_002,  /* 18 OKIAGARI P S */
    ken_saca_002,  /* 19 OKIAGARI P M */
    ken_saca_002,  /* 20 OKIAGARI P L */
    ken_saca_002,  /* 21 OKIAGARI K S */
    ken_saca_002,  /* 22 OKIAGARI K M */
    ken_saca_002,  /* 23 OKIAGARI K L */
    ken_saca_024,  /* 24 ATTACK 1 S: 236+P light (plain script) */
    ken_saca_025,  /* 25 ATTACK 1 M: 236+P medium (plain script) */
    ken_saca_026,  /* 26 ATTACK 1 L: 236+P heavy (plain script) */
    ken_saca_027,  /* 27 ATTACK 1 SP: EX 236+PP (plain script) */
    ken_saca_028,  /* 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ken_saca_029,  /* 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ken_saca_030,  /* 30 ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    ken_saca_031,  /* 31 ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ken_saca_032,  /* 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    ken_saca_033,  /* 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    ken_saca_034,  /* 34 ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ken_saca_035,  /* 35 ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ken_saca_036,  /* 36 ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ken_saca_036,  /* 37 ATTACK 4 M: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ken_saca_036,  /* 38 ATTACK 4 L: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ken_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ken_saca_040,  /* 40 ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ken_saca_040,  /* 41 ATTACK 5 M: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ken_saca_040,  /* 42 ATTACK 5 L: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ken_saca_040,  /* 43 ATTACK 5 SP: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ken_saca_044,  /* 44 ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ken_saca_044,  /* 45 ATTACK 6 M: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ken_saca_044,  /* 46 ATTACK 6 L: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ken_saca_044,  /* 47 ATTACK 6 SP: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ken_saca_048,  /* 48 ATTACK 7 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
    ken_saca_049,  /* 49 ATTACK 7 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
    ken_saca_050,  /* 50 ATTACK 7 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
    ken_saca_051,  /* 51 ATTACK 7 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ken_saca_052,  /* 52 ATTACK 8 S: not started by a command */
    ken_saca_053,  /* 53 ATTACK 8 M: not started by a command */
    ken_saca_053,  /* 54 ATTACK 8 L: not started by a command */
    ken_saca_053,  /* 55 ATTACK 8 SP: not started by a command */
    ken_saca_053,  /* 56 ATTACK 9 S: not started by a command */
    ken_saca_057,  /* 57 ATTACK 9 M: not started by a command */
    ken_saca_057,  /* 58 ATTACK 9 L: not started by a command */
    ken_saca_057,  /* 59 ATTACK 9 SP: not started by a command */
    ken_saca_057,  /* 60 ATTACK 10 S: not started by a command */
    ken_saca_061,  /* 61 ATTACK 10 M: not started by a command */
    ken_saca_061,  /* 62 ATTACK 10 L: not started by a command */
    ken_saca_061,  /* 63 ATTACK 10 SP: not started by a command */
    ken_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 ken_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EC, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70ED, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EE, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EF, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F0, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F1, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70F3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1280, 7936), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 ken_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 ken_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70F3, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70F2, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70F2, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70F0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EE, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70ED, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70EA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E9, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 ken_saca_002_head[4] = { HEAD(2, 0, 0, 12, 0, 1, 0) };
const u16 ken_saca_002[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4201),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 236+P light (plain script) */
const u16 ken_saca_024_head[4] = { HEAD(6, 0, 8, 10, 0, 0, 0) };
const u16 ken_saca_024[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(2, 0, 393, 0, 0, 0, 0, 0x44A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x44A3, 0, 75, 0, 0, 64, 2, 40, 0, 0, 52, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x44A4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 54, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44A6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x44A7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x44A8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x44A9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x44AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 236+P medium (plain script) */
const u16 ken_saca_025_head[4] = { HEAD(6, 0, 10, 10, 0, 0, 0) };
const u16 ken_saca_025[76] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(2, 0, 393, 0, 0, 0, 0, 0x44A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x44A3, 0, 75, 0, 0, 64, 2, 41, 0, 0, 52, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 236+P heavy (plain script) */
const u16 ken_saca_026_head[4] = { HEAD(6, 0, 12, 10, 0, 0, 0) };
const u16 ken_saca_026[76] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 393, 0, 0, 0, 0, 0x44A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x44A3, 0, 75, 0, 0, 64, 2, 42, 0, 0, 52, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 236+PP (plain script) */
const u16 ken_saca_027_head[4] = { HEAD(6, 0, 14, 10, 0, 0, 0) };
const u16 ken_saca_027[88] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44AC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44A1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(4, 0, 393, 0, 0, 0, 0, 0x44A2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x44A3, 0, 75, 0, 0, 64, 2, 43, 0, 0, 52, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
const u16 ken_saca_028_head[4] = { HEAD(4, 0, 8, 12, 1, 1, 1) };
const u16 ken_saca_028[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(1, 0, 394, 0, 0, 0, 0, 0x44B0, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44B1, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B2, -50, 82, 0, 64, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x44B4, 51, 83, 0, 0, 0, 32, 68),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B5, 52, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x44B6, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
const u16 ken_saca_029_head[4] = { HEAD(4, 0, 10, 12, 2, 2, 1) };
const u16 ken_saca_029[76] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 394, 0, 0, 0, 0, 0x44B0, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44B1, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B2, -76, 82, 0, 64, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x44B4, -77, 83, 0, 0, 0, 32, 69),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B4, 78, 84, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 28, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
const u16 ken_saca_030_head[4] = { HEAD(4, 0, 12, 12, 3, 3, 1) };
const u16 ken_saca_030[156] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 13, 0, 0x44AF, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 394, 0, 0, 14, 0, 0x44B0, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 15, 0, 0x44B1, -15, 79, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 16, 0, 0x44B2, -16, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 17, 0, 0x44B3, -17, 83, 0, 128, 0, 32, 70),
    L4(3, 0, 0, 0, 0, 18, 0, 0x44B4, 18, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 18, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 19, 0, 0x44B5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 19, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 30, 0, 0, 0, 20, 0, 0x44B6, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 21, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 22, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 23, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
const u16 ken_saca_031_head[4] = { HEAD(4, 0, 14, 12, 4, 4, 1) };
const u16 ken_saca_031[108] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0,
    L4(1, 0, 394, 0, 0, 14, 0, 0x44B0, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 15, 0, 0x44B1, -83, 80, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 16, 0, 0x44B2, -84, 89, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 17, 0, 0x44B3, -85, 83, 0, 0, 0, 32, 71),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B4, -86, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B4, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 19, 0, 0x44B5, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 19, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 30, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
const u16 ken_saca_032_head[4] = { HEAD(4, 0, 13, 13, 2, 3, 2) };
const u16 ken_saca_032[132] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 402, 0, 0, 0, 0, 0x4377, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BD, -75, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 64, 32, 51),
    L4(3, 20, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 0, 32, 51),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44BF, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4521, -40, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, -40, 123, 0, 64, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44C7, 0, 125, 0, 0, 0, 32, 76),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
const u16 ken_saca_033_head[4] = { HEAD(4, 0, 13, 13, 4, 6, 2) };
const u16 ken_saca_033[196] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 402, 0, 0, 0, 0, 0x4377, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BD, -38, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 64, 32, 51),
    L4(1, 20, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4521, -39, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, -39, 123, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x4521, -81, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, 0, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44C7, 0, 125, 0, 0, 0, 32, 76),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
const u16 ken_saca_034_head[4] = { HEAD(4, 0, 13, 13, 6, 8, 2) };
const u16 ken_saca_034[196] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 402, 0, 0, 0, 0, 0x4377, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BD, -38, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 64, 32, 51),
    L4(2, 20, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4521, -39, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, -39, 123, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x4521, -82, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44C7, 0, 125, 0, 0, 0, 32, 76),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
const u16 ken_saca_035_head[4] = { HEAD(4, 0, 15, 13, 6, 10, 2) };
const u16 ken_saca_035[204] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0,
    L4(3, 0, 402, 0, 0, 0, 0, 0x4377, 0, 6, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BD, -87, 50, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 64, 32, 51),
    L4(2, 20, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4521, -88, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, -88, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 0, 0, 0, 0x4521, -89, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44C7, 0, 125, 0, 0, 0, 32, 76),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x44C8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA), 37 ATTACK 4 M: SA I 23623+P (routine Att_SHOURYUUREPPA), 38 ATTACK 4 L: SA I 23623+P (routine Att_SHOURYUUREPPA), 39 ATTACK 4 SP: SA I 23623+P (routine Att_SHOURYUUREPPA) */
const u16 ken_saca_036_head[4] = { HEAD(6, 0, 32, 16, 0, 11, 8) };
const u16 ken_saca_036[460] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AE, 0, 134, 0, 0, 0, 13, 11, 780, 0, 0, 0, 0),
    L6(3, 0, 395, 0, 0, 0, 0, 0x44AF, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44B0, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(42, 0, 0, 0, 0, 0, 0, 0x44B0, 0, 134, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 396, 0, 0, 0, 0, 0x44B1, -110, 135, 0, 0, 0, 0, 0, 780, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44B2, -111, 136, 0, 0, 0, 0, 0, 780, 0, 104, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x44B5, -112, 137, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_RJA, 5, 36, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x44B0, 0, 138, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x44B1, -113, 139, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44B2, -114, 140, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x44B4, -115, 141, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44B4, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 14, 0, 0x44B0, 0, 138, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 0, 0, 0, 15, 0, 0x44B1, -116, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x44B2, -116, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 17, 0, 0x44B3, -117, 141, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x44B4, -117, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x44B4, -117, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 19, 0, 0x44B5, -118, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 19, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 20, 0, 0x44B6, 0, 86, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(5, 30, 0, 0, 0, 21, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 22, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 23, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA), 41 ATTACK 5 M: SA II 23623+K (routine Att_SHOURYUUREPPA), 42 ATTACK 5 L: SA II 23623+K (routine Att_SHOURYUUREPPA), 43 ATTACK 5 SP: SA II 23623+K (routine Att_SHOURYUUREPPA) */
const u16 ken_saca_040_head[4] = { HEAD(6, 0, 32, 12, 0, 15, 6) };
const u16 ken_saca_040[316] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x44AE, 0, 127, 0, 0, 0, 13, 12, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44AF, 0, 127, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(45, 0, 0, 0, 0, 0, 0, 0x44B0, 0, 127, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x44B1, -105, 128, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 397, 0, 0, 0, 0, 0x44B2, -105, 129, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x4526, -106, 130, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4526, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPK2, 5, 40, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4527, 106, 131, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4527, -106, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4528, -107, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPK, 5, 40, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4529, 107, 133, 0, 0, 0, 0, 0, 0, 0, 0, 17, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4529, -107, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x452A, -108, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x452D, 0, 86, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44B6, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x44B9, 0, 87, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), 45 ATTACK 6 M: SA III 23623+K (routine Att_SLIDE_and_JUMP), 46 ATTACK 6 L: SA III 23623+K (routine Att_SLIDE_and_JUMP), 47 ATTACK 6 SP: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
const u16 ken_saca_044_head[4] = { HEAD(6, 0, 37, 15, 0, 5, 7) };
const u16 ken_saca_044[628] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 143, 0, 0, 0, 13, 10, 0, 0, 232, 0, 0),
    L6(3, 0, 395, 0, 0, 0, 0, 0x43E1, 0, 143, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E2, 0, 143, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0),
    L6(42, 0, 270, 0, 0, 0, 0, 0x43E3, 0, 143, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x43E4, 0, 143, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E5, -97, 145, 0, 0, 0, 30, 28, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E6, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E7, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E8, 0, 144, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E9, 0, 144, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43EA, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E1, 0, 144, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(1, 0, 389, 0, 0, 0, 0, 0x43E2, 0, 144, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x43A0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43A1, -98, 146, 0, 64, 0, 0, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A2, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A3, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A4, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A5, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A6, 0, 144, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43EA, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43EB, 0, 144, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 388, 0, 0, 0, 0, 0x43C0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x43A0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43A1, -98, 146, 0, 64, 0, 0, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A2, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A4, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A5, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43A6, 0, 144, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43EA, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43EB, 0, 144, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 388, 0, 0, 0, 0, 0x43E2, 0, 144, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x43E3, 0, 144, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E4, 0, 144, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E5, -99, 145, 0, 64, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x43E6, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x43E7, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E8, 0, 144, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43E9, 0, 144, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43C0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 388, 0, 0, 0, 0, 0x43C8, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x43C9, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x43CA, -100, 147, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x43CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(16, 0, 0, 0, 0, 0, 0, 0x43CC, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x43CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x43C5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x43C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x43C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: not started by a command */
const u16 ken_saca_052_head[4] = { HEAD(4, 0, 37, 15, 0, 5, 7) };
const u16 ken_saca_052[340] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x44BE, 0, 120, 0, 0, 0, 32, 127),
    L4(1, 20, 0, 0, 0, 0, 0, 0x44BF, 0, 120, 0, 0, 0, 9, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -101, 148, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -102, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -103, 148, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -104, 149, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4521, -101, 148, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4524, -102, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4521, -101, 148, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4524, -102, 149, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4244, 0, 4, 0, 0, 0, 23, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4245, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4246, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4247, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x426B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ken_saca_048_head[4] = { HEAD(4, 22, 9, 12, 0, 2, 70) };
const u16 ken_saca_048[156] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 402, 0, 0, 0, 0, 0x4570, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4571, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4572, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -94, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -95, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x44C7, 0, 125, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4246, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4247, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4248, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4249, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x424A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ken_saca_049_head[4] = { HEAD(4, 22, 11, 12, 0, 3, 70) };
const u16 ken_saca_049[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 402, 0, 0, 0, 0, 0x4570, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4571, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4572, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -94, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -95, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 48, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ken_saca_050_head[4] = { HEAD(4, 22, 13, 12, 0, 4, 70) };
const u16 ken_saca_050[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 402, 0, 0, 0, 0, 0x4570, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4571, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4572, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -94, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -95, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 48, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ken_saca_051_head[4] = { HEAD(4, 22, 15, 14, 0, 10, 70) };
const u16 ken_saca_051[124] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 9, 5), 0, 0, 0, 0,
    L4(2, 20, 402, 0, 0, 0, 0, 0x4570, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4571, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4572, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 10), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4520, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4521, -90, 121, 0, 75, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4522, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4523, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4524, -91, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4525, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 48, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: not started by a command, 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command */
const u16 ken_saca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_saca_053[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x4201),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command, 60 ATTACK 10 S: not started by a command */
const u16 ken_saca_057_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 ken_saca_057[108] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4229, 0, 189, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x4441, 0, 4, 0, 0, 0, 22, 20),
    L4(4, 0, 269, 0, 0, 0, 0, 0x4442, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4444, -1, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4448, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4445, 0, 30, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4446, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4447, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4256, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4257, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command, 63 ATTACK 10 SP: not started by a command */
const u16 ken_saca_061_head[4] = { HEAD(4, 0, 0, 8, 0, 2, 0) };
const u16 ken_saca_061[116] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x44D7, 0, 1, 0, 0, 0, 21, 0),
    L4(6, 0, 2048, 0, 0, 0, 0, 0x44D0, 0, 28, 0, 0, 0, 32, 94),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44D1, 0, 28, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44D9, -2, 29, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D9, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x44D1, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 40, 0, 0, 0, 0, 0, 0x44D9, -2, 29, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x44D9, 0, 28, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44DA, 0, 28, 0, 0, 0, 21, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x44DB, 0, 28, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x44D7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 32, 95),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command */
const u16 ken_saca_064_head[4] = { HEAD(4, 0, 12, 12, 3, 3, 1) };
const u16 ken_saca_064[364] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x44AE, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 394, 0, 0, 13, 0, 0x44AF, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 14, 0, 0x44B0, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 15, 0, 0x44B1, -15, 79, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 16, 0, 0x44B2, -16, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 17, 0, 0x44B4, -17, 83, 0, 0, 0, 32, 70),
    L4(4, 0, 0, 0, 0, 17, 0, 0x44B4, 18, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 17, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 17, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 18, 0, 0x44B5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 18, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 30, 0, 0, 0, 19, 0, 0x44B6, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 20, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 21, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E0, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E1, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E2, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E3, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E4, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E5, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E6, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E7, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x45E8, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44AE, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 394, 0, 0, 0, 0, 0x44AF, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x44B0, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B1, 0, 79, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B2, 0, 82, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B3, 0, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x44B4, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B4, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x44B5, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x44B6, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44B7, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x44B9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44BA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44CB, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 33 entries */
const u16* const ken_cbca[34] = {
    ken_cbca_000,  /* 0 APPEAR JUNBI 1 */
    ken_cbca_001,  /* 1 APPEAR JUNBI 2 */
    ken_cbca_002,  /* 2 APPEAR JUNBI 3 */
    ken_cbca_003,  /* 3 APPEAR JUNBI 4 */
    ken_cbca_004,  /* 4 APPEAR JUNBI 5 */
    ken_cbca_005,  /* 5 APPEAR JUNBI 6 */
    ken_cbca_006,  /* 6 APPEAR JUNBI 7 */
    ken_cbca_007,  /* 7 APPEAR JUNBI 8 */
    ken_cbca_008,  /* 8 APPEAR 1 */
    ken_cbca_009,  /* 9 APPEAR 2 */
    ken_cbca_010,  /* 10 APPEAR 3 */
    ken_cbca_011,  /* 11 APPEAR 4 */
    ken_cbca_012,  /* 12 APPEAR 5 */
    ken_cbca_013,  /* 13 APPEAR 6 */
    ken_cbca_014,  /* 14 APPEAR 7 */
    ken_cbca_015,  /* 15 APPEAR 8 */
    ken_cbca_016,  /* 16 SP APPEAR 1 */
    ken_cbca_017,  /* 17 SP APPEAR 2 */
    ken_cbca_018,  /* 18 SP APPEAR 3 */
    ken_cbca_019,  /* 19 SP APPEAR 4 */
    ken_cbca_020,  /* 20 SP APPEAR 5 */
    ken_cbca_021,  /* 21 SP APPEAR 6 */
    ken_cbca_022,  /* 22 SP APPEAR 7 */
    ken_cbca_023,  /* 23 SP APPEAR 8 */
    ken_cbca_024,  /* 24 ZANNEN 1 */
    ken_cbca_025,  /* 25 ZANNEN 2 */
    ken_cbca_026,  /* 26 ZANNEN 3 */
    ken_cbca_027,  /* 27 ZANNEN 4 */
    ken_cbca_028,  /* 28 ZANNEN 5 */
    ken_cbca_029,  /* 29 ZANNEN 6 */
    ken_cbca_030,  /* 30 ZANNEN 7 */
    ken_cbca_031,  /* 31 ZANNEN 8 */
    ken_cbca_032,  /* 32 WIN 1 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 ken_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_000[20] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 17, 7),
    CMD(CM_RJA4, 5, 44, 55),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 ken_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 ken_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 ken_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 ken_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 ken_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 ken_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 22, 1),
    CMD(CM_RJA3, 7, 23, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 ken_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_007[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 ken_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_008[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 ken_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_009[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 ken_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 ken_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_011[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 ken_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_012[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 8),
    CMD(CM_CARE, 2, 1, 8),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 ken_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_013[16] = {
    CMD(CM_DJMP, 8193, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 8),
    CMD(CM_CARE, 2, 1, 8),
    CMD(CM_JMP, 4, 14, 4),
};

/* script: 14 APPEAR 7 */
const u16 ken_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_014[20] = {
    CMD(CM_RJA, 5, 36, 11),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 ken_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_015[32] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 33, 7),
    CMD(CM_RJA4, 5, 52, 1),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 ken_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_016[28] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 ken_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_017[8] = {
    CMD(CM_RJA6, 4, 7, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 18 SP APPEAR 3 */
const u16 ken_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_018[8] = {
    CMD(CM_RJA6, 4, 6, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 19 SP APPEAR 4 */
const u16 ken_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_019[16] = {
    CMD(CM_RJA4, 2, 8, 21),
    CMD(CM_RJA5, 2, 8, 5),
    CMD(CM_WSET, 16384, 0, 6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 ken_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_020[8] = {
    CMD(CM_RJA6, 4, 4, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 21 SP APPEAR 6 */
const u16 ken_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_021[8] = {
    CMD(CM_RJA6, 4, 3, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 22 SP APPEAR 7 */
const u16 ken_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_022[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 32, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 ken_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_023[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 ken_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_024[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 ken_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_025[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 ken_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_026[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 ken_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_027[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 ken_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_cbca_028[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 44, 7),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 ken_cbca_029_head[4] = { HEAD(2, 0, 14, 10, 0, 0, 0) };
const u16 ken_cbca_029[16] = {
    CMD(CM_EXEC, 49, 16, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 ken_cbca_030_head[4] = { HEAD(2, 0, 14, 12, 0, 0, 1) };
const u16 ken_cbca_030[16] = {
    CMD(CM_EXEC, 49, 17, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 ken_cbca_031_head[4] = { HEAD(2, 0, 15, 13, 0, 0, 2) };
const u16 ken_cbca_031[16] = {
    CMD(CM_EXEC, 49, 18, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 ken_cbca_032_head[4] = { HEAD(2, 22, 15, 12, 0, 0, 70) };
const u16 ken_cbca_032[16] = {
    CMD(CM_EXEC, 49, 19, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

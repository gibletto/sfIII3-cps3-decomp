/*
 * HUGO_CHAR.C  Hugo's animation scripts and sprite part tables
 *
 * The animation scripts Hugo's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 hugo_nmca_000[], hugo_nmca_001[], hugo_nmca_002[], hugo_nmca_003[], hugo_nmca_004[], hugo_nmca_005[], hugo_nmca_006[], hugo_nmca_007[], hugo_nmca_008[], hugo_nmca_011[], hugo_nmca_012[], hugo_nmca_013[], hugo_nmca_014[], hugo_nmca_015[], hugo_nmca_016[], hugo_nmca_017[], hugo_nmca_020[], hugo_nmca_021[], hugo_nmca_022[], hugo_nmca_023[], hugo_nmca_024[], hugo_nmca_026[], hugo_nmca_027[], hugo_nmca_029[], hugo_nmca_031[], hugo_nmca_032[], hugo_nmca_033[], hugo_nmca_038[], hugo_nmca_040[], hugo_nmca_041[], hugo_nmca_043[], hugo_nmca_044[], hugo_nmca_045[], hugo_nmca_046[], hugo_nmca_047[], hugo_nmca_048[], hugo_nmca_049[], hugo_nmca_050[];
extern const u16 hugo_nmca_000_head[];
extern const u16 hugo_nmca_001_head[];
extern const u16 hugo_nmca_002_head[];
extern const u16 hugo_nmca_003_head[];
extern const u16 hugo_nmca_004_head[];
extern const u16 hugo_nmca_005_head[];
extern const u16 hugo_nmca_006_head[];
extern const u16 hugo_nmca_007_head[];
extern const u16 hugo_nmca_008_head[];
extern const u16 hugo_nmca_011_head[];
extern const u16 hugo_nmca_012_head[];
extern const u16 hugo_nmca_013_head[];
extern const u16 hugo_nmca_014_head[];
extern const u16 hugo_nmca_015_head[];
extern const u16 hugo_nmca_016_head[];
extern const u16 hugo_nmca_017_head[];
extern const u16 hugo_nmca_020_head[];
extern const u16 hugo_nmca_021_head[];
extern const u16 hugo_nmca_022_head[];
extern const u16 hugo_nmca_023_head[];
extern const u16 hugo_nmca_024_head[];
extern const u16 hugo_nmca_026_head[];
extern const u16 hugo_nmca_027_head[];
extern const u16 hugo_nmca_029_head[];
extern const u16 hugo_nmca_031_head[];
extern const u16 hugo_nmca_032_head[];
extern const u16 hugo_nmca_033_head[];
extern const u16 hugo_nmca_038_head[];
extern const u16 hugo_nmca_040_head[];
extern const u16 hugo_nmca_041_head[];
extern const u16 hugo_nmca_043_head[];
extern const u16 hugo_nmca_044_head[];
extern const u16 hugo_nmca_045_head[];
extern const u16 hugo_nmca_046_head[];
extern const u16 hugo_nmca_047_head[];
extern const u16 hugo_nmca_048_head[];
extern const u16 hugo_nmca_049_head[];
extern const u16 hugo_nmca_050_head[];
extern const u16 hugo_dmca_000[], hugo_dmca_002[], hugo_dmca_003[], hugo_dmca_004[], hugo_dmca_006[], hugo_dmca_008[], hugo_dmca_009[], hugo_dmca_010[], hugo_dmca_014[], hugo_dmca_018[], hugo_dmca_022[], hugo_dmca_024[], hugo_dmca_025[], hugo_dmca_026[], hugo_dmca_030[], hugo_dmca_034[], hugo_dmca_036[], hugo_dmca_037[], hugo_dmca_038[], hugo_dmca_039[], hugo_dmca_048[], hugo_dmca_049[], hugo_dmca_050[], hugo_dmca_052[], hugo_dmca_053[], hugo_dmca_054[], hugo_dmca_055[], hugo_dmca_060[], hugo_dmca_064[], hugo_dmca_065[], hugo_dmca_066[], hugo_dmca_067[], hugo_dmca_068[], hugo_dmca_069[], hugo_dmca_070[], hugo_dmca_071[], hugo_dmca_072[], hugo_dmca_073[], hugo_dmca_074[], hugo_dmca_075[], hugo_dmca_076[], hugo_dmca_078[], hugo_dmca_079[], hugo_dmca_080[], hugo_dmca_082[], hugo_dmca_083[], hugo_dmca_084[], hugo_dmca_090[], hugo_dmca_091[], hugo_dmca_096[], hugo_dmca_097[];
extern const u16 hugo_dmca_000_head[];
extern const u16 hugo_dmca_002_head[];
extern const u16 hugo_dmca_003_head[];
extern const u16 hugo_dmca_004_head[];
extern const u16 hugo_dmca_006_head[];
extern const u16 hugo_dmca_008_head[];
extern const u16 hugo_dmca_009_head[];
extern const u16 hugo_dmca_010_head[];
extern const u16 hugo_dmca_014_head[];
extern const u16 hugo_dmca_018_head[];
extern const u16 hugo_dmca_022_head[];
extern const u16 hugo_dmca_024_head[];
extern const u16 hugo_dmca_025_head[];
extern const u16 hugo_dmca_026_head[];
extern const u16 hugo_dmca_030_head[];
extern const u16 hugo_dmca_034_head[];
extern const u16 hugo_dmca_036_head[];
extern const u16 hugo_dmca_037_head[];
extern const u16 hugo_dmca_038_head[];
extern const u16 hugo_dmca_039_head[];
extern const u16 hugo_dmca_048_head[];
extern const u16 hugo_dmca_049_head[];
extern const u16 hugo_dmca_050_head[];
extern const u16 hugo_dmca_052_head[];
extern const u16 hugo_dmca_053_head[];
extern const u16 hugo_dmca_054_head[];
extern const u16 hugo_dmca_055_head[];
extern const u16 hugo_dmca_060_head[];
extern const u16 hugo_dmca_064_head[];
extern const u16 hugo_dmca_065_head[];
extern const u16 hugo_dmca_066_head[];
extern const u16 hugo_dmca_067_head[];
extern const u16 hugo_dmca_068_head[];
extern const u16 hugo_dmca_069_head[];
extern const u16 hugo_dmca_070_head[];
extern const u16 hugo_dmca_071_head[];
extern const u16 hugo_dmca_072_head[];
extern const u16 hugo_dmca_073_head[];
extern const u16 hugo_dmca_074_head[];
extern const u16 hugo_dmca_075_head[];
extern const u16 hugo_dmca_076_head[];
extern const u16 hugo_dmca_078_head[];
extern const u16 hugo_dmca_079_head[];
extern const u16 hugo_dmca_080_head[];
extern const u16 hugo_dmca_082_head[];
extern const u16 hugo_dmca_083_head[];
extern const u16 hugo_dmca_084_head[];
extern const u16 hugo_dmca_090_head[];
extern const u16 hugo_dmca_091_head[];
extern const u16 hugo_dmca_096_head[];
extern const u16 hugo_dmca_097_head[];
extern const u16 hugo_btca_000[], hugo_btca_001[], hugo_btca_003[], hugo_btca_005[], hugo_btca_004[], hugo_btca_006[], hugo_btca_007[], hugo_btca_008[], hugo_btca_009[], hugo_btca_010[], hugo_btca_011[], hugo_btca_012[], hugo_btca_013[], hugo_btca_014[], hugo_btca_015[], hugo_btca_016[], hugo_btca_017[], hugo_btca_018[], hugo_btca_019[], hugo_btca_020[], hugo_btca_021[], hugo_btca_022[], hugo_btca_023[], hugo_btca_024[], hugo_btca_025[], hugo_btca_026[], hugo_btca_027[], hugo_btca_028[], hugo_btca_029[], hugo_btca_030[], hugo_btca_031[], hugo_btca_032[], hugo_btca_033[], hugo_btca_034[], hugo_btca_035[];
extern const u16 hugo_btca_000_head[];
extern const u16 hugo_btca_001_head[];
extern const u16 hugo_btca_003_head[];
extern const u16 hugo_btca_005_head[];
extern const u16 hugo_btca_004_head[];
extern const u16 hugo_btca_006_head[];
extern const u16 hugo_btca_007_head[];
extern const u16 hugo_btca_008_head[];
extern const u16 hugo_btca_009_head[];
extern const u16 hugo_btca_010_head[];
extern const u16 hugo_btca_011_head[];
extern const u16 hugo_btca_012_head[];
extern const u16 hugo_btca_013_head[];
extern const u16 hugo_btca_014_head[];
extern const u16 hugo_btca_015_head[];
extern const u16 hugo_btca_016_head[];
extern const u16 hugo_btca_017_head[];
extern const u16 hugo_btca_018_head[];
extern const u16 hugo_btca_019_head[];
extern const u16 hugo_btca_020_head[];
extern const u16 hugo_btca_021_head[];
extern const u16 hugo_btca_022_head[];
extern const u16 hugo_btca_023_head[];
extern const u16 hugo_btca_024_head[];
extern const u16 hugo_btca_025_head[];
extern const u16 hugo_btca_026_head[];
extern const u16 hugo_btca_027_head[];
extern const u16 hugo_btca_028_head[];
extern const u16 hugo_btca_029_head[];
extern const u16 hugo_btca_030_head[];
extern const u16 hugo_btca_031_head[];
extern const u16 hugo_btca_032_head[];
extern const u16 hugo_btca_033_head[];
extern const u16 hugo_btca_034_head[];
extern const u16 hugo_btca_035_head[];
extern const u16 hugo_caca_000[], hugo_caca_004[], hugo_caca_005[], hugo_caca_006[], hugo_caca_007[], hugo_caca_008[], hugo_caca_009[], hugo_caca_010[], hugo_caca_012[], hugo_caca_016[], hugo_caca_020[], hugo_caca_021[], hugo_caca_022[], hugo_caca_024[], hugo_caca_028[], hugo_caca_032[], hugo_caca_033[], hugo_caca_034[], hugo_caca_035[], hugo_caca_037[], hugo_caca_038[], hugo_caca_039[], hugo_caca_041[], hugo_caca_042[];
extern const u16 hugo_caca_000_head[];
extern const u16 hugo_caca_004_head[];
extern const u16 hugo_caca_005_head[];
extern const u16 hugo_caca_006_head[];
extern const u16 hugo_caca_007_head[];
extern const u16 hugo_caca_008_head[];
extern const u16 hugo_caca_009_head[];
extern const u16 hugo_caca_010_head[];
extern const u16 hugo_caca_012_head[];
extern const u16 hugo_caca_016_head[];
extern const u16 hugo_caca_020_head[];
extern const u16 hugo_caca_021_head[];
extern const u16 hugo_caca_022_head[];
extern const u16 hugo_caca_024_head[];
extern const u16 hugo_caca_028_head[];
extern const u16 hugo_caca_032_head[];
extern const u16 hugo_caca_033_head[];
extern const u16 hugo_caca_034_head[];
extern const u16 hugo_caca_035_head[];
extern const u16 hugo_caca_037_head[];
extern const u16 hugo_caca_038_head[];
extern const u16 hugo_caca_039_head[];
extern const u16 hugo_caca_041_head[];
extern const u16 hugo_caca_042_head[];
extern const u16 hugo_cuca_000[], hugo_cuca_001[], hugo_cuca_002[], hugo_cuca_003[], hugo_cuca_004[], hugo_cuca_005[], hugo_cuca_006[], hugo_cuca_007[], hugo_cuca_008[], hugo_cuca_009[], hugo_cuca_010[], hugo_cuca_011[], hugo_cuca_012[], hugo_cuca_013[], hugo_cuca_014[], hugo_cuca_015[], hugo_cuca_016[], hugo_cuca_017[], hugo_cuca_018[], hugo_cuca_019[], hugo_cuca_020[], hugo_cuca_021[], hugo_cuca_022[], hugo_cuca_023[], hugo_cuca_024[], hugo_cuca_025[], hugo_cuca_026[], hugo_cuca_027[], hugo_cuca_028[], hugo_cuca_029[], hugo_cuca_030[], hugo_cuca_031[], hugo_cuca_032[], hugo_cuca_033[], hugo_cuca_034[], hugo_cuca_035[], hugo_cuca_036[], hugo_cuca_037[], hugo_cuca_038[], hugo_cuca_039[], hugo_cuca_040[], hugo_cuca_041[], hugo_cuca_042[], hugo_cuca_043[], hugo_cuca_044[], hugo_cuca_045[], hugo_cuca_046[], hugo_cuca_047[], hugo_cuca_048[], hugo_cuca_049[], hugo_cuca_050[], hugo_cuca_051[], hugo_cuca_052[], hugo_cuca_053[], hugo_cuca_054[], hugo_cuca_055[], hugo_cuca_056[], hugo_cuca_057[], hugo_cuca_058[], hugo_cuca_059[], hugo_cuca_060[], hugo_cuca_061[], hugo_cuca_062[], hugo_cuca_063[], hugo_cuca_064[], hugo_cuca_065[], hugo_cuca_066[], hugo_cuca_067[];
extern const u16 hugo_cuca_000_head[];
extern const u16 hugo_cuca_001_head[];
extern const u16 hugo_cuca_002_head[];
extern const u16 hugo_cuca_003_head[];
extern const u16 hugo_cuca_004_head[];
extern const u16 hugo_cuca_005_head[];
extern const u16 hugo_cuca_006_head[];
extern const u16 hugo_cuca_007_head[];
extern const u16 hugo_cuca_008_head[];
extern const u16 hugo_cuca_009_head[];
extern const u16 hugo_cuca_010_head[];
extern const u16 hugo_cuca_011_head[];
extern const u16 hugo_cuca_012_head[];
extern const u16 hugo_cuca_013_head[];
extern const u16 hugo_cuca_014_head[];
extern const u16 hugo_cuca_015_head[];
extern const u16 hugo_cuca_016_head[];
extern const u16 hugo_cuca_017_head[];
extern const u16 hugo_cuca_018_head[];
extern const u16 hugo_cuca_019_head[];
extern const u16 hugo_cuca_020_head[];
extern const u16 hugo_cuca_021_head[];
extern const u16 hugo_cuca_022_head[];
extern const u16 hugo_cuca_023_head[];
extern const u16 hugo_cuca_024_head[];
extern const u16 hugo_cuca_025_head[];
extern const u16 hugo_cuca_026_head[];
extern const u16 hugo_cuca_027_head[];
extern const u16 hugo_cuca_028_head[];
extern const u16 hugo_cuca_029_head[];
extern const u16 hugo_cuca_030_head[];
extern const u16 hugo_cuca_031_head[];
extern const u16 hugo_cuca_032_head[];
extern const u16 hugo_cuca_033_head[];
extern const u16 hugo_cuca_034_head[];
extern const u16 hugo_cuca_035_head[];
extern const u16 hugo_cuca_036_head[];
extern const u16 hugo_cuca_037_head[];
extern const u16 hugo_cuca_038_head[];
extern const u16 hugo_cuca_039_head[];
extern const u16 hugo_cuca_040_head[];
extern const u16 hugo_cuca_041_head[];
extern const u16 hugo_cuca_042_head[];
extern const u16 hugo_cuca_043_head[];
extern const u16 hugo_cuca_044_head[];
extern const u16 hugo_cuca_045_head[];
extern const u16 hugo_cuca_046_head[];
extern const u16 hugo_cuca_047_head[];
extern const u16 hugo_cuca_048_head[];
extern const u16 hugo_cuca_049_head[];
extern const u16 hugo_cuca_050_head[];
extern const u16 hugo_cuca_051_head[];
extern const u16 hugo_cuca_052_head[];
extern const u16 hugo_cuca_053_head[];
extern const u16 hugo_cuca_054_head[];
extern const u16 hugo_cuca_055_head[];
extern const u16 hugo_cuca_056_head[];
extern const u16 hugo_cuca_057_head[];
extern const u16 hugo_cuca_058_head[];
extern const u16 hugo_cuca_059_head[];
extern const u16 hugo_cuca_060_head[];
extern const u16 hugo_cuca_061_head[];
extern const u16 hugo_cuca_062_head[];
extern const u16 hugo_cuca_063_head[];
extern const u16 hugo_cuca_064_head[];
extern const u16 hugo_cuca_065_head[];
extern const u16 hugo_cuca_066_head[];
extern const u16 hugo_cuca_067_head[];
extern const u16 hugo_atca_000[], hugo_atca_003[], hugo_atca_006[], hugo_atca_007[], hugo_atca_009[], hugo_atca_012[], hugo_atca_015[], hugo_atca_018[], hugo_atca_021[], hugo_atca_024[], hugo_atca_027[], hugo_atca_030[], hugo_atca_033[], hugo_atca_036[], hugo_atca_038[], hugo_atca_040[], hugo_atca_041[], hugo_atca_042[], hugo_atca_044[], hugo_atca_046[], hugo_atca_048[], hugo_atca_050[], hugo_atca_052[], hugo_atca_053[], hugo_atca_054[], hugo_atca_056[], hugo_atca_058[], hugo_atca_060[], hugo_atca_062[], hugo_atca_064[], hugo_atca_065[], hugo_atca_066[], hugo_atca_068[], hugo_atca_070[], hugo_atca_072[], hugo_atca_074[], hugo_atca_076[], hugo_atca_077[], hugo_atca_078[], hugo_atca_080[], hugo_atca_082[], hugo_atca_084[], hugo_atca_086[], hugo_atca_088[], hugo_atca_089[], hugo_atca_090[], hugo_atca_092[], hugo_atca_094[], hugo_atca_096[], hugo_atca_098[], hugo_atca_100[], hugo_atca_101[], hugo_atca_102[], hugo_atca_104[], hugo_atca_106[], hugo_atca_108[], hugo_atca_110[], hugo_atca_112[], hugo_atca_114[], hugo_atca_116[], hugo_atca_118[], hugo_atca_120[], hugo_atca_122[], hugo_atca_124[], hugo_atca_126[], hugo_atca_128[], hugo_atca_130[], hugo_atca_132[], hugo_atca_134[], hugo_atca_136[], hugo_atca_138[], hugo_atca_140[], hugo_atca_142[], hugo_atca_144[], hugo_atca_145[], hugo_atca_146[];
extern const u16 hugo_atca_000_head[];
extern const u16 hugo_atca_003_head[];
extern const u16 hugo_atca_006_head[];
extern const u16 hugo_atca_007_head[];
extern const u16 hugo_atca_009_head[];
extern const u16 hugo_atca_012_head[];
extern const u16 hugo_atca_015_head[];
extern const u16 hugo_atca_018_head[];
extern const u16 hugo_atca_021_head[];
extern const u16 hugo_atca_024_head[];
extern const u16 hugo_atca_027_head[];
extern const u16 hugo_atca_030_head[];
extern const u16 hugo_atca_033_head[];
extern const u16 hugo_atca_036_head[];
extern const u16 hugo_atca_038_head[];
extern const u16 hugo_atca_040_head[];
extern const u16 hugo_atca_041_head[];
extern const u16 hugo_atca_042_head[];
extern const u16 hugo_atca_044_head[];
extern const u16 hugo_atca_046_head[];
extern const u16 hugo_atca_048_head[];
extern const u16 hugo_atca_050_head[];
extern const u16 hugo_atca_052_head[];
extern const u16 hugo_atca_053_head[];
extern const u16 hugo_atca_054_head[];
extern const u16 hugo_atca_056_head[];
extern const u16 hugo_atca_058_head[];
extern const u16 hugo_atca_060_head[];
extern const u16 hugo_atca_062_head[];
extern const u16 hugo_atca_064_head[];
extern const u16 hugo_atca_065_head[];
extern const u16 hugo_atca_066_head[];
extern const u16 hugo_atca_068_head[];
extern const u16 hugo_atca_070_head[];
extern const u16 hugo_atca_072_head[];
extern const u16 hugo_atca_074_head[];
extern const u16 hugo_atca_076_head[];
extern const u16 hugo_atca_077_head[];
extern const u16 hugo_atca_078_head[];
extern const u16 hugo_atca_080_head[];
extern const u16 hugo_atca_082_head[];
extern const u16 hugo_atca_084_head[];
extern const u16 hugo_atca_086_head[];
extern const u16 hugo_atca_088_head[];
extern const u16 hugo_atca_089_head[];
extern const u16 hugo_atca_090_head[];
extern const u16 hugo_atca_092_head[];
extern const u16 hugo_atca_094_head[];
extern const u16 hugo_atca_096_head[];
extern const u16 hugo_atca_098_head[];
extern const u16 hugo_atca_100_head[];
extern const u16 hugo_atca_101_head[];
extern const u16 hugo_atca_102_head[];
extern const u16 hugo_atca_104_head[];
extern const u16 hugo_atca_106_head[];
extern const u16 hugo_atca_108_head[];
extern const u16 hugo_atca_110_head[];
extern const u16 hugo_atca_112_head[];
extern const u16 hugo_atca_114_head[];
extern const u16 hugo_atca_116_head[];
extern const u16 hugo_atca_118_head[];
extern const u16 hugo_atca_120_head[];
extern const u16 hugo_atca_122_head[];
extern const u16 hugo_atca_124_head[];
extern const u16 hugo_atca_126_head[];
extern const u16 hugo_atca_128_head[];
extern const u16 hugo_atca_130_head[];
extern const u16 hugo_atca_132_head[];
extern const u16 hugo_atca_134_head[];
extern const u16 hugo_atca_136_head[];
extern const u16 hugo_atca_138_head[];
extern const u16 hugo_atca_140_head[];
extern const u16 hugo_atca_142_head[];
extern const u16 hugo_atca_144_head[];
extern const u16 hugo_atca_145_head[];
extern const u16 hugo_atca_146_head[];
extern const u16 hugo_exca_000[], hugo_exca_001[], hugo_exca_003[], hugo_exca_005[], hugo_exca_006[], hugo_exca_007[], hugo_exca_008[], hugo_exca_009[], hugo_exca_010[], hugo_exca_013[], hugo_exca_014[], hugo_exca_015[], hugo_exca_016[], hugo_exca_017[], hugo_exca_018[], hugo_exca_022[], hugo_exca_023[], hugo_exca_024[], hugo_exca_027[], hugo_exca_028[], hugo_exca_029[], hugo_exca_030[], hugo_exca_031[], hugo_exca_032[], hugo_exca_033[], hugo_exca_034[], hugo_exca_035[], hugo_exca_036[], hugo_exca_037[], hugo_exca_038[], hugo_exca_039[], hugo_exca_040[], hugo_exca_041[], hugo_exca_042[], hugo_exca_043[], hugo_exca_044[], hugo_exca_045[], hugo_exca_048[], hugo_exca_049[], hugo_exca_050[], hugo_exca_051[], hugo_exca_052[], hugo_exca_053[], hugo_exca_054[], hugo_exca_055[], hugo_exca_056[], hugo_exca_057[], hugo_exca_058[], hugo_exca_059[], hugo_exca_060[], hugo_exca_061[], hugo_exca_062[], hugo_exca_063[], hugo_exca_064[];
extern const u16 hugo_exca_000_head[];
extern const u16 hugo_exca_001_head[];
extern const u16 hugo_exca_003_head[];
extern const u16 hugo_exca_005_head[];
extern const u16 hugo_exca_006_head[];
extern const u16 hugo_exca_007_head[];
extern const u16 hugo_exca_008_head[];
extern const u16 hugo_exca_009_head[];
extern const u16 hugo_exca_010_head[];
extern const u16 hugo_exca_013_head[];
extern const u16 hugo_exca_014_head[];
extern const u16 hugo_exca_015_head[];
extern const u16 hugo_exca_016_head[];
extern const u16 hugo_exca_017_head[];
extern const u16 hugo_exca_018_head[];
extern const u16 hugo_exca_022_head[];
extern const u16 hugo_exca_023_head[];
extern const u16 hugo_exca_024_head[];
extern const u16 hugo_exca_027_head[];
extern const u16 hugo_exca_028_head[];
extern const u16 hugo_exca_029_head[];
extern const u16 hugo_exca_030_head[];
extern const u16 hugo_exca_031_head[];
extern const u16 hugo_exca_032_head[];
extern const u16 hugo_exca_033_head[];
extern const u16 hugo_exca_034_head[];
extern const u16 hugo_exca_035_head[];
extern const u16 hugo_exca_036_head[];
extern const u16 hugo_exca_037_head[];
extern const u16 hugo_exca_038_head[];
extern const u16 hugo_exca_039_head[];
extern const u16 hugo_exca_040_head[];
extern const u16 hugo_exca_041_head[];
extern const u16 hugo_exca_042_head[];
extern const u16 hugo_exca_043_head[];
extern const u16 hugo_exca_044_head[];
extern const u16 hugo_exca_045_head[];
extern const u16 hugo_exca_048_head[];
extern const u16 hugo_exca_049_head[];
extern const u16 hugo_exca_050_head[];
extern const u16 hugo_exca_051_head[];
extern const u16 hugo_exca_052_head[];
extern const u16 hugo_exca_053_head[];
extern const u16 hugo_exca_054_head[];
extern const u16 hugo_exca_055_head[];
extern const u16 hugo_exca_056_head[];
extern const u16 hugo_exca_057_head[];
extern const u16 hugo_exca_058_head[];
extern const u16 hugo_exca_059_head[];
extern const u16 hugo_exca_060_head[];
extern const u16 hugo_exca_061_head[];
extern const u16 hugo_exca_062_head[];
extern const u16 hugo_exca_063_head[];
extern const u16 hugo_exca_064_head[];
extern const u16 hugo_saca_000[], hugo_saca_001[], hugo_saca_002[], hugo_saca_024[], hugo_saca_025[], hugo_saca_026[], hugo_saca_027[], hugo_saca_028[], hugo_saca_029[], hugo_saca_030[], hugo_saca_031[], hugo_saca_032[], hugo_saca_033[], hugo_saca_034[], hugo_saca_036[], hugo_saca_037[], hugo_saca_038[], hugo_saca_040[], hugo_saca_041[], hugo_saca_042[], hugo_saca_044[], hugo_saca_048[], hugo_saca_049[], hugo_saca_050[], hugo_saca_052[], hugo_saca_053[], hugo_saca_054[], hugo_saca_056[], hugo_saca_057[], hugo_saca_060[], hugo_saca_064[], hugo_saca_065[], hugo_saca_066[];
extern const u16 hugo_saca_000_head[];
extern const u16 hugo_saca_001_head[];
extern const u16 hugo_saca_002_head[];
extern const u16 hugo_saca_024_head[];
extern const u16 hugo_saca_025_head[];
extern const u16 hugo_saca_026_head[];
extern const u16 hugo_saca_027_head[];
extern const u16 hugo_saca_028_head[];
extern const u16 hugo_saca_029_head[];
extern const u16 hugo_saca_030_head[];
extern const u16 hugo_saca_031_head[];
extern const u16 hugo_saca_032_head[];
extern const u16 hugo_saca_033_head[];
extern const u16 hugo_saca_034_head[];
extern const u16 hugo_saca_036_head[];
extern const u16 hugo_saca_037_head[];
extern const u16 hugo_saca_038_head[];
extern const u16 hugo_saca_040_head[];
extern const u16 hugo_saca_041_head[];
extern const u16 hugo_saca_042_head[];
extern const u16 hugo_saca_044_head[];
extern const u16 hugo_saca_048_head[];
extern const u16 hugo_saca_049_head[];
extern const u16 hugo_saca_050_head[];
extern const u16 hugo_saca_052_head[];
extern const u16 hugo_saca_053_head[];
extern const u16 hugo_saca_054_head[];
extern const u16 hugo_saca_056_head[];
extern const u16 hugo_saca_057_head[];
extern const u16 hugo_saca_060_head[];
extern const u16 hugo_saca_064_head[];
extern const u16 hugo_saca_065_head[];
extern const u16 hugo_saca_066_head[];
extern const u16 hugo_cbca_000[], hugo_cbca_001[], hugo_cbca_002[], hugo_cbca_003[], hugo_cbca_004[], hugo_cbca_005[], hugo_cbca_006[], hugo_cbca_007[], hugo_cbca_008[], hugo_cbca_009[], hugo_cbca_010[], hugo_cbca_011[], hugo_cbca_012[], hugo_cbca_013[], hugo_cbca_014[], hugo_cbca_015[], hugo_cbca_016[], hugo_cbca_017[], hugo_cbca_018[], hugo_cbca_019[], hugo_cbca_020[], hugo_cbca_021[], hugo_cbca_022[], hugo_cbca_023[], hugo_cbca_024[], hugo_cbca_025[], hugo_cbca_026[], hugo_cbca_027[], hugo_cbca_028[], hugo_cbca_029[], hugo_cbca_030[], hugo_cbca_031[], hugo_cbca_032[], hugo_cbca_033[], hugo_cbca_034[];
extern const u16 hugo_cbca_000_head[];
extern const u16 hugo_cbca_001_head[];
extern const u16 hugo_cbca_002_head[];
extern const u16 hugo_cbca_003_head[];
extern const u16 hugo_cbca_004_head[];
extern const u16 hugo_cbca_005_head[];
extern const u16 hugo_cbca_006_head[];
extern const u16 hugo_cbca_007_head[];
extern const u16 hugo_cbca_008_head[];
extern const u16 hugo_cbca_009_head[];
extern const u16 hugo_cbca_010_head[];
extern const u16 hugo_cbca_011_head[];
extern const u16 hugo_cbca_012_head[];
extern const u16 hugo_cbca_013_head[];
extern const u16 hugo_cbca_014_head[];
extern const u16 hugo_cbca_015_head[];
extern const u16 hugo_cbca_016_head[];
extern const u16 hugo_cbca_017_head[];
extern const u16 hugo_cbca_018_head[];
extern const u16 hugo_cbca_019_head[];
extern const u16 hugo_cbca_020_head[];
extern const u16 hugo_cbca_021_head[];
extern const u16 hugo_cbca_022_head[];
extern const u16 hugo_cbca_023_head[];
extern const u16 hugo_cbca_024_head[];
extern const u16 hugo_cbca_025_head[];
extern const u16 hugo_cbca_026_head[];
extern const u16 hugo_cbca_027_head[];
extern const u16 hugo_cbca_028_head[];
extern const u16 hugo_cbca_029_head[];
extern const u16 hugo_cbca_030_head[];
extern const u16 hugo_cbca_031_head[];
extern const u16 hugo_cbca_032_head[];
extern const u16 hugo_cbca_033_head[];
extern const u16 hugo_cbca_034_head[];

/* normal scripts: 51 entries */
const u16* const hugo_nmca[52] = {
    hugo_nmca_000,  /* 0 KAMAE */
    hugo_nmca_001,  /* 1 HURIMUKI */
    hugo_nmca_002,  /* 2 FRONT WALK */
    hugo_nmca_003,  /* 3 BACK WALK */
    hugo_nmca_004,  /* 4 DASH HUMIKOMI */
    hugo_nmca_005,  /* 5 DASH TOBINOKI */
    hugo_nmca_006,  /* 6 KAGAMU */
    hugo_nmca_007,  /* 7 KAGAMI KAMAE */
    hugo_nmca_008,  /* 8 KAGAMI TURN */
    hugo_nmca_008,  /* 9 KAGAMI F WALK */
    hugo_nmca_008,  /* 10 KAGAMI B WALK */
    hugo_nmca_011,  /* 11 STAND UP */
    hugo_nmca_012,  /* 12 JUMP JUNBI */
    hugo_nmca_013,  /* 13 SP JUMP JUNBI */
    hugo_nmca_014,  /* 14 JUMP FRONT */
    hugo_nmca_015,  /* 15 JUMP VERTICAL */
    hugo_nmca_016,  /* 16 JUMP BACK */
    hugo_nmca_017,  /* 17 S JUMP FRONT */
    hugo_nmca_017,  /* 18 S JUMP V */
    hugo_nmca_017,  /* 19 S JUMP BACK */
    hugo_nmca_020,  /* 20 SP JUMP FRONT */
    hugo_nmca_021,  /* 21 SP JUMP V */
    hugo_nmca_022,  /* 22 SP JUMP BACK */
    hugo_nmca_023,  /* 23 WALK END */
    hugo_nmca_024,  /* 24 PARING HEAD */
    hugo_nmca_024,  /* 25 PARING UP */
    hugo_nmca_026,  /* 26 PARING DOWN */
    hugo_nmca_027,  /* 27 PARING AIR F */
    hugo_nmca_027,  /* 28 PARING AIR B */
    hugo_nmca_029,  /* 29 GUARD HEAD */
    hugo_nmca_029,  /* 30 GUARD UP */
    hugo_nmca_031,  /* 31 GUARD DOWN */
    hugo_nmca_032,  /* 32 GUARD AIR */
    hugo_nmca_033,  /* 33 no name */
    hugo_nmca_033,  /* 34 no name */
    hugo_nmca_033,  /* 35 no name */
    hugo_nmca_033,  /* 36 no name */
    hugo_nmca_033,  /* 37 no name */
    hugo_nmca_038,  /* 38 P BREAK ZUJOU */
    hugo_nmca_038,  /* 39 P BREAK UP */
    hugo_nmca_040,  /* 40 P BREAK DOWN */
    hugo_nmca_041,  /* 41 P BREAK AIR F */
    hugo_nmca_041,  /* 42 P BREAK AIR R */
    hugo_nmca_043,  /* 43 TUKAMIHAZUSI */
    hugo_nmca_044,  /* 44 TUKAMIHAZUSARE */
    hugo_nmca_045,  /* 45 TUKAMIHAZUSI */
    hugo_nmca_046,  /* 46 TUKAMIHAZUSARE */
    hugo_nmca_047,  /* 47 no name */
    hugo_nmca_048,  /* 48 no name */
    hugo_nmca_049,  /* 49 no name */
    hugo_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 hugo_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_000[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2411, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2412, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2413, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2414, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2415, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2416, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2401, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2402, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2403, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2404, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2405, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2406, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2407, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2401, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2408, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2409, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240A, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240B, 0, 193, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240C, 0, 193, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240D, 0, 193, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 hugo_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_001[44] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x2401, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x240E, 0, 194, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x240F, 0, 194, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2410, 0, 195, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2410, 0, 195, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 hugo_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_002[124] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2417, 0, 196, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2418, 0, 196, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2419, 0, 196, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x241A, 0, 196, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x241B, 0, 196, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x241C, 0, 196, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x241D, 0, 196, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x241E, 0, 197, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x241F, 0, 197, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2420, 0, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2421, 0, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2422, 0, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2423, 0, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2424, 0, 197, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 hugo_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_003[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2425, 0, 198, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2426, 0, 198, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2427, 0, 198, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2428, 0, 198, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2429, 0, 198, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x242A, 0, 198, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x242B, 0, 199, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x242C, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x242D, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x242E, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x242F, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2430, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2431, 0, 199, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2432, 0, 199, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 hugo_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_004[172] = {
    CMD(CM_RJA, 0, 4, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 1, 277, 0, 0, 0, 0, 0x2462, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2463, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2464, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2465, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2466, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 273, 0, 0, 0, 0, 0x2434, 0, 200, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2435, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2436, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2437, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2438, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 hugo_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_005[172] = {
    CMD(CM_RJA, 0, 5, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 1, 0, 0, 0, 0, 0, 0x2467, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2468, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2469, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x246A, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x246B, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2434, 0, 200, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2435, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x2436, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2437, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2438, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 hugo_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_006[36] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2434, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2435, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2436, 0, 207, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 hugo_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_007[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2445, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2446, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2447, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2448, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x243B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x243C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x243D, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x243E, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x243F, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2440, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2441, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 hugo_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_008[44] = {
    L4(2, 0, 0, 0, 1, 0, 0, 0x243B, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2442, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2443, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2444, 0, 210, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2444, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 hugo_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_011[44] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 hugo_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_012[28] = {
    L4(3, 1, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 hugo_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_013[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2434, 0, 21, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 hugo_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_014[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2449, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244A, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244B, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244C, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244D, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244E, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244F, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2450, 0, 214, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2451, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 hugo_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_015[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2449, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244A, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244B, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244C, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244D, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244E, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244F, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2450, 0, 214, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2451, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 hugo_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_016[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2449, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244A, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244B, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244C, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244D, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244E, 0, 213, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x244F, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2450, 0, 214, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2451, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 hugo_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 hugo_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_020[124] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x2449, 0, 212, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x244A, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244B, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244C, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244D, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244E, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x244F, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2450, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2451, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 hugo_nmca_021_head[4] = { HEAD(2, 28, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_021[8] = {
    CMD(CM_JPSS, 0, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 hugo_nmca_022_head[4] = { HEAD(2, 30, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_022[8] = {
    CMD(CM_JPSS, 0, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 hugo_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 hugo_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_024[68] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x2566, 0, 1, 0, 0, 0, 18, 6),
    L4(1, 0, 840, 0, 0, 0, 0, 0x2567, 0, 1, 0, 0, 0, 6, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2568, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2569, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x256A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x256B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x256C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x256C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 hugo_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_026[76] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x27A9, 0, 2, 0, 0, 0, 18, 6),
    L4(2, 0, 840, 0, 0, 0, 0, 0x27AA, 0, 2, 0, 0, 0, 6, 1),
    L4(4, 0, 0, 0, 0, 0, 0, 0x27AB, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x27AC, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2445, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2446, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2447, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2448, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2448, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 hugo_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_027[108] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 18, 6),
    L4(2, 0, 840, 0, 0, 0, 0, 0x245F, 0, 5, 0, 0, 0, 6, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2460, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2461, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2451, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 18, 6),
    L4(2, 0, 840, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 6, 2),
    L4(20, 0, 0, 0, 0, 0, 0, 0x245F, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2460, 0, 5, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2461, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2461, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD, 30 GUARD UP */
const u16 hugo_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_029[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2457, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2458, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 hugo_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_031[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x245B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x245C, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x245D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 hugo_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_032[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x245F, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2460, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2461, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x245E, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 hugo_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x2469, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 hugo_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_038[92] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x246C, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2470, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2471, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 hugo_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_040[92] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x245C, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x245D, 0, 2, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2470, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2471, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 hugo_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x245F, 0, 5, 0, 0, 0, 18, 8),
    L4(250, 0, 840, 0, 0, 0, 0, 0x2460, 0, 5, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 hugo_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_043[92] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x246C, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2470, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2471, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 hugo_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_044[84] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x25F6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 1, 0, 0, 0, 0, 0, 0x25FA, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 hugo_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_045[84] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x245F, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 0, 840, 0, 0, 0, 0, 0x2460, 0, 5, 0, 0, 0, 25, 2),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2450, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2451, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 hugo_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_046[60] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x2451, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2454, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 hugo_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 hugo_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 hugo_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_049[384] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0000, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25F1,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25F6,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25F8,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25FA,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25FC,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x25FE,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_JPSS, 6144, 0, 0), 0x0400, 0x0000, 0x0000, 0x2520,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2521,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2522,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2523,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2524,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2525,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C4,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C5,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C6,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C7,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24C9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24CA,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24CB,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x24CC,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2441,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x2440,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x243F,
    CMD(CM_DUMMY, 8192, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x243F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 50 no name */
const u16 hugo_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_nmca_050[92] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x246C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2470, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2471, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const hugo_dmca[99] = {
    hugo_dmca_000,  /* 0 GUARD HEAD */
    hugo_dmca_000,  /* 1 GUARD UP */
    hugo_dmca_002,  /* 2 GUARD DOWN */
    hugo_dmca_003,  /* 3 GUARD AIR */
    hugo_dmca_004,  /* 4 HUSHIN HEAD */
    hugo_dmca_004,  /* 5 HUSHIN UP */
    hugo_dmca_006,  /* 6 HUSHIN DOWN */
    hugo_dmca_006,  /* 7 HUSHIN AIR */
    hugo_dmca_008,  /* 8 FACE S */
    hugo_dmca_009,  /* 9 FACE M */
    hugo_dmca_010,  /* 10 FACE L */
    hugo_dmca_010,  /* 11 FACE SP */
    hugo_dmca_008,  /* 12 FOOK OKU S */
    hugo_dmca_009,  /* 13 FOOK OKU M */
    hugo_dmca_014,  /* 14 FOOK OKU L */
    hugo_dmca_014,  /* 15 FOOK OKU SP */
    hugo_dmca_008,  /* 16 FOOK TEMAE S */
    hugo_dmca_009,  /* 17 FOOK TEMAE M */
    hugo_dmca_018,  /* 18 FOOK TEMAE L */
    hugo_dmca_018,  /* 19 FOOK TEMAE SP */
    hugo_dmca_008,  /* 20 UPPER S */
    hugo_dmca_009,  /* 21 UPPER M */
    hugo_dmca_022,  /* 22 UPPER L */
    hugo_dmca_022,  /* 23 UPPER SP */
    hugo_dmca_024,  /* 24 NOUTEN S */
    hugo_dmca_025,  /* 25 NOUTEN M */
    hugo_dmca_026,  /* 26 NOUTEN L */
    hugo_dmca_026,  /* 27 NOUTEN SP */
    hugo_dmca_024,  /* 28 BODY BROW S */
    hugo_dmca_025,  /* 29 BODY BROW M */
    hugo_dmca_030,  /* 30 BODY BROW L */
    hugo_dmca_030,  /* 31 BODY BROW SP */
    hugo_dmca_024,  /* 32 BODY UPPER S */
    hugo_dmca_025,  /* 33 BODY UPPER M */
    hugo_dmca_034,  /* 34 BODY UPPER L */
    hugo_dmca_034,  /* 35 BODY UPPER SP */
    hugo_dmca_036,  /* 36 TATAKI S */
    hugo_dmca_037,  /* 37 TATAKI M */
    hugo_dmca_038,  /* 38 TATAKI L */
    hugo_dmca_039,  /* 39 TATAKI SP */
    hugo_dmca_036,  /* 40 TATAKI V. S */
    hugo_dmca_037,  /* 41 TATAKI V. M */
    hugo_dmca_038,  /* 42 TATAKI V. L */
    hugo_dmca_039,  /* 43 TATAKI V. SP */
    hugo_dmca_008,  /* 44 NOBASITA TE S */
    hugo_dmca_009,  /* 45 NOBASITA TE M */
    hugo_dmca_010,  /* 46 NOBASITA TE L */
    hugo_dmca_010,  /* 47 NOBASITA TE SP */
    hugo_dmca_048,  /* 48 KAGAMI S */
    hugo_dmca_049,  /* 49 KAGAMI M */
    hugo_dmca_050,  /* 50 KAGAMI L */
    hugo_dmca_050,  /* 51 KAGAMI SP */
    hugo_dmca_052,  /* 52 KGM TATAKI S */
    hugo_dmca_053,  /* 53 KGM TATAKI M */
    hugo_dmca_054,  /* 54 KGM TATAKI L */
    hugo_dmca_055,  /* 55 KGM TATAKI SP */
    hugo_dmca_052,  /* 56 KGM TTKI V.S */
    hugo_dmca_053,  /* 57 KGM TTKI V.M */
    hugo_dmca_054,  /* 58 KGM TTKI V.L */
    hugo_dmca_055,  /* 59 KGM TTKI V.SP */
    hugo_dmca_060,  /* 60 NEKOROBI S */
    hugo_dmca_060,  /* 61 NEKOROBI M */
    hugo_dmca_060,  /* 62 NEKOROBI L */
    hugo_dmca_060,  /* 63 NEKOROBI SP */
    hugo_dmca_064,  /* 64 OKIAGARI */
    hugo_dmca_065,  /* 65 OKIAGARI F */
    hugo_dmca_066,  /* 66 OKIAGARI B */
    hugo_dmca_067,  /* 67 LOSE NO STAND */
    hugo_dmca_068,  /* 68 LOSE SONABA */
    hugo_dmca_069,  /* 69 LOSE KAGAMI */
    hugo_dmca_070,  /* 70 PIYO */
    hugo_dmca_071,  /* 71 UKEMI MOVE F */
    hugo_dmca_072,  /* 72 UKEMI MOVE R */
    hugo_dmca_073,  /* 73 SHIMEOTASARE */
    hugo_dmca_074,  /* 74 TATI TOUKETU S */
    hugo_dmca_075,  /* 75 TATI TOUKETU M */
    hugo_dmca_076,  /* 76 TATI TOUKETU L */
    hugo_dmca_076,  /* 77 TATI TOUKETU P */
    hugo_dmca_078,  /* 78 KGM TOUKETU S */
    hugo_dmca_079,  /* 79 KGM TOUKETU M */
    hugo_dmca_080,  /* 80 KGM TOUKETU L */
    hugo_dmca_080,  /* 81 KGM TOUKETU P */
    hugo_dmca_082,  /* 82 TATI DENGEKI S */
    hugo_dmca_083,  /* 83 TATI DENGEKI M */
    hugo_dmca_084,  /* 84 TATI DENGEKI L */
    hugo_dmca_084,  /* 85 TATI DENGEKI P */
    hugo_dmca_082,  /* 86 KGM DENGEKI S */
    hugo_dmca_083,  /* 87 KGM DENGEKI M */
    hugo_dmca_084,  /* 88 KGM DENGEKI L */
    hugo_dmca_084,  /* 89 KGM DENGEKI P */
    hugo_dmca_090,  /* 90 OKIAGARI FRONT */
    hugo_dmca_091,  /* 91 OKIAGARI REAR */
    hugo_dmca_008,  /* 92 TATI MOE S */
    hugo_dmca_009,  /* 93 TATI MOE M */
    hugo_dmca_010,  /* 94 TATI MOE L */
    hugo_dmca_010,  /* 95 TATI MOE SP */
    hugo_dmca_096,  /* 96 no name */
    hugo_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD, 1 GUARD UP */
const u16 hugo_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_000[68] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x2458, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2457, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 134, 0, 0, 0, 0, 0, 0x2458, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2456, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 hugo_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_002[68] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x245D, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x245C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x245B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 134, 0, 0, 0, 0, 0, 0x245C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x245D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x245A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 hugo_dmca_003_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_003[136] = {
    L6(2, 131, 0, 0, 0, 0, 0, 0x245F, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2460, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 138, 0, 0, 0, 0, 0, 0x2461, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2461, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
    L6(250, 135, 0, 0, 0, 0, 0, 0x2458, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2459, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 hugo_dmca_004_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_004[88] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x246C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2470, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2471, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 hugo_dmca_006_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_006[88] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x245C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x246C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x246D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x246E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x246F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 hugo_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_008[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2480, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 134, 835, 0, 0, 0, 0, 0x2481, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2482, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 1, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2483, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2484, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2485, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 hugo_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_009[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2486, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 136, 835, 0, 0, 0, 0, 0x2487, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2487, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2488, 0, 179, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2489, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x248A, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2484, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 hugo_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_010[108] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x248B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x248C, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 138, 835, 0, 0, 0, 0, 0x248D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x248E, 0, 180, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x248F, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2490, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2491, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2492, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2493, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2494, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2495, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2495, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 hugo_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_014[116] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x248B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2496, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 139, 835, 0, 0, 0, 0, 0x2497, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2498, 0, 179, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 11, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x2499, 0, 179, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x249A, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249B, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249C, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x240E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x240F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2410, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2410, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 hugo_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_018[124] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x249E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x249F, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 10, 0, 0, 0, 0, 0, 0x24A0, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 140, 835, 0, 0, 0, 0, 0x2498, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2498, 0, 179, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 11, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x2499, 0, 180, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x249A, 0, 180, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249B, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x249D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x240E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x240F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2410, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2410, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 hugo_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24A6, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 137, 835, 0, 0, 0, 0, 0x24A7, 0, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24A8, 0, 175, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24A9, 0, 176, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2488, 0, 177, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2489, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x248A, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2484, 0, 175, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2485, 0, 174, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 hugo_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24AF, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 134, 0, 0, 0, 0, 0, 0x24B0, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24B1, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24B2, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x24B3, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M, 29 BODY BROW M, 33 BODY UPPER M */
const u16 hugo_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_025[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24AF, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 135, 835, 0, 0, 0, 0, 0x24B0, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24B1, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24B2, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x24B3, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 hugo_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_026[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24B4, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 137, 835, 0, 0, 0, 0, 0x24B5, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24B6, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24B7, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24B8, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x24B2, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24B3, 0, 182, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 hugo_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24B9, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 137, 834, 0, 0, 0, 0, 0x24BA, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BB, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BC, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BD, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24BE, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24BF, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x24C0, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24C1, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24C2, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24B2, 0, 182, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24B3, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 hugo_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24BA, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 138, 835, 0, 0, 0, 0, 0x24AA, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AB, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24AC, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24AD, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AE, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2489, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x248A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2484, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 40 TATAKI V. S */
const u16 hugo_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_036[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B4, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 834, 0, 0, 0, 6, 0x24B5, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 TATAKI M, 41 TATAKI V. M */
const u16 hugo_dmca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_037[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B4, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 834, 0, 0, 0, 6, 0x24B5, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 TATAKI L, 42 TATAKI V. L */
const u16 hugo_dmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_038[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B4, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 834, 0, 0, 0, 6, 0x24B5, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 TATAKI SP, 43 TATAKI V. SP */
const u16 hugo_dmca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_039[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B4, 0, 185, 0, 0, 0, 0, 0),
    L4(5, 0, 834, 0, 0, 0, 6, 0x24B5, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 hugo_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_048[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24C3, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 134, 0, 0, 0, 0, 0, 0x24C4, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24C5, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x24C6, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x24C7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 hugo_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_049[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24C9, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 136, 835, 0, 0, 0, 0, 0x24CA, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24CA, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x24CB, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24CC, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24CD, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x24C7, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 hugo_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_050[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24CE, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 137, 835, 0, 0, 0, 0, 0x24CF, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24CF, 0, 187, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x24D0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24D1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D2, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D3, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x24D4, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D5, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D6, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24D7, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24D8, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24D8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 56 KGM TTKI V.S */
const u16 hugo_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_052[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D4, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D5, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 KGM TATAKI M, 57 KGM TTKI V.M */
const u16 hugo_dmca_053_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_053[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D4, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D5, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 KGM TATAKI L, 58 KGM TTKI V.L */
const u16 hugo_dmca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_054[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D4, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24D5, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 KGM TATAKI SP, 59 KGM TTKI V.SP */
const u16 hugo_dmca_055_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_055[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D4, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24D5, 0, 186, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24F5, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 hugo_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_060[148] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 834, 0, 0, 0, 0, 0x24FD, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24FC, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2502, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2503, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x2504, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x2505, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 139, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 834, 0, 0, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24E7, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 hugo_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_064[252] = {
    CMD(CM_IFRLF, 1, 16387, 8192), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 18), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 24, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2529, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252A, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252B, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252C, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252D, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252E, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2437, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2437, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2524, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2525, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2526, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2527, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2528, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2437, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2437, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 hugo_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_065[100] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x26D6, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26D7, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2628, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2629, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262C, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x262D, 0, 82, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26E0, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 hugo_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_066[92] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x26D6, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2627, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2630, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2631, 0, 82, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2436, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 hugo_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 hugo_dmca_068_head[4] = { HEAD(6, 22, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_068[256] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x251E, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x251F, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x251E, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x251C, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x251D, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x251E, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x251F, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 1, 0, 0, 0, 0, 0, 0x2520, 0, 255, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2521, 0, 255, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2522, 0, 255, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x2523, 0, 255, 0, 0, 0, 22, 38, 0, 0, 114, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x24FE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x24FF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2501, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(3, 0, 288, 0, 0, 0, 0, 0x2502, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2503, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 hugo_dmca_069_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_069[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x251E, 0, 255, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x251F, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 68, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 hugo_dmca_070_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_070[108] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 39, 0, 0x250C, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250D, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250E, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250F, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x2510, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x2511, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x2510, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250F, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250F, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250E, 0, 68, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x250D, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 hugo_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2524, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2525, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 837, 0, 0, 0, 0, 0x2526, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 4096, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 0, 0, 0, 0, 0, 0x2530, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2531, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2532, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2533, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 hugo_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_072[140] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2526, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2527, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 838, 0, 0, 0, 0, 0x2534, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2533, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2532, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2531, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2530, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x252F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x252F, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x2528, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2437, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2437, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 hugo_dmca_073_head[4] = { HEAD(6, 22, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_073[196] = {
    L6(8, 0, 0, 0, 0, 0, 0, 0x251E, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x251F, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 1, 0, 0, 0, 0, 0, 0x2520, 0, 255, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2521, 0, 255, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2522, 0, 255, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x2523, 0, 255, 0, 0, 0, 22, 38, 0, 0, 114, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x24FE, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x24FF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2501, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(3, 0, 288, 0, 0, 0, 0, 0x2502, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2503, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 hugo_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2480, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x2480, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2485, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 hugo_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2484, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x2484, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 hugo_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x248B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x248B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2484, 0, 178, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2485, 0, 178, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 hugo_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24C3, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x24C3, 0, 186, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 hugo_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24C7, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x24C7, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x24C8, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 hugo_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_080[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24CE, 0, 186, 0, 0, 0, 0, 0),
    L4(250, 131, 835, 0, 0, 0, 0, 0x24CE, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x24C8, 0, 187, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24C8, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 hugo_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_082[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x26C9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26CB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 835, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 hugo_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_083[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x26C9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26CB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 835, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 hugo_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_084[60] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2483, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2484, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2485, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2486, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 835, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 hugo_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_090[84] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x24FD, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2524, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2525, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2526, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2530, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2531, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2532, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2533, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 25), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 hugo_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_091[92] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x26D6, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2627, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x262F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2630, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2631, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2436, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 16), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 hugo_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_096[44] = {
    L4(3, 2, 835, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 hugo_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_dmca_097[44] = {
    L4(3, 2, 834, 0, 0, 0, 0, 0x2506, 0, 146, 0, 0, 0, 24, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2506, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x2506, 0, 146, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x2506, 0, 146, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const hugo_btca[37] = {
    hugo_btca_000,  /* 0 AIR NORMAL */
    hugo_btca_001,  /* 1 ASIBARAI SIRI */
    hugo_btca_001,  /* 2 ASIB TUNNOMERI */
    hugo_btca_003,  /* 3 NOKEZORI */
    hugo_btca_004,  /* 4 KUNOJI */
    hugo_btca_005,  /* 5 KIRIMOMI */
    hugo_btca_006,  /* 6 UPPER */
    hugo_btca_007,  /* 7 BODY UPPER */
    hugo_btca_008,  /* 8 HARAYARARE */
    hugo_btca_009,  /* 9 TATAKI AIR */
    hugo_btca_010,  /* 10 TTKI V. AIR */
    hugo_btca_011,  /* 11 HUMI ASIB */
    hugo_btca_012,  /* 12 FACE */
    hugo_btca_013,  /* 13 ASIB SIRI LOSE */
    hugo_btca_014,  /* 14 ASIB TUN LOSE */
    hugo_btca_015,  /* 15 DENKI */
    hugo_btca_016,  /* 16 KUNOJI NOKE */
    hugo_btca_017,  /* 17 BODY UPPER SP */
    hugo_btca_018,  /* 18 HANEAGARI */
    hugo_btca_019,  /* 19 TOUKETSU A */
    hugo_btca_020,  /* 20 BODY SLAM */
    hugo_btca_021,  /* 21 IPPONZEOI */
    hugo_btca_022,  /* 22 TOMOE RYU */
    hugo_btca_023,  /* 23 MONKEY FLIP */
    hugo_btca_024,  /* 24 TOMOE ORO */
    hugo_btca_025,  /* 25 SNAKE FANG */
    hugo_btca_026,  /* 26 FLANKEN.S */
    hugo_btca_027,  /* 27 KISHINRIKI */
    hugo_btca_028,  /* 28 SPLASH.M */
    hugo_btca_029,  /* 29 HARAIGOSHI */
    hugo_btca_030,  /* 30 ALEX B.D */
    hugo_btca_031,  /* 31 GILL */
    hugo_btca_032,  /* 32 HANEKAERI HARA */
    hugo_btca_033,  /* 33 S HANEAGARI */
    hugo_btca_034,  /* 34 TATUMAKIZANKU */
    hugo_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 hugo_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_000[68] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B6, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 835, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x24B6, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x24AE, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI, 2 ASIB TUNNOMERI */
const u16 hugo_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_001[68] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2507, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 834, 0, 0, 0, 0, 0x2508, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2509, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x250A, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x250B, 0, 222, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x250B, 0, 222, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 hugo_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_003[84] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 835, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 hugo_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_005[84] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 835, 0, 0, 0, 8, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 12, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 11, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 hugo_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_004[92] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B9, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 835, 0, 0, 0, 0, 0x24BA, 0, 232, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24BB, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BC, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F2, 0, 235, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F3, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F4, 0, 237, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x24F5, 0, 238, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 10, 0x24F5, 0, 238, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 hugo_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_006[124] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24A6, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 835, 0, 0, 0, 0, 0x24A7, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24A8, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24A9, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 hugo_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_007[132] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B1, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 835, 0, 0, 0, 0, 0x24AA, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24AB, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AC, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AD, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AE, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 hugo_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_008[116] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B9, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 834, 0, 0, 0, 0, 0x24BA, 0, 232, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24BB, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BC, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 hugo_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_009[60] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 hugo_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_010[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B6, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24AA, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2508, 0, 219, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x250B, 0, 222, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 hugo_btca_011_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_011[44] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2507, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x250B, 0, 222, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x250B, 0, 222, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 hugo_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_012[84] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 835, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 hugo_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_013[12] = {
    CMD(CM_RJA, 7, 52, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 hugo_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 hugo_btca_014[12] = {
    CMD(CM_RJA, 7, 52, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 hugo_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_015[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(3, 135, 0, 0, 0, 0, 0, 0x26C9, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CA, 0, 249, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26C9, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x26CB, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 hugo_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_016[116] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24B9, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 835, 0, 0, 0, 0, 0x24BA, 0, 232, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24BB, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24BC, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 hugo_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_017[124] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 835, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 hugo_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_018[276] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(2, 0, 834, 0, 1, 0, 5, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 6, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 7, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 9, 0x24E0, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 15, 0x24DF, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(1, 2, 285, 0, 1, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 1, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 18, 24), 0, 0, 0, 0,
    L4(2, 0, 835, 0, 0, 0, 5, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x24E0, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x24DF, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(1, 2, 285, 0, 0, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 hugo_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_019[28] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2486, 0, 250, 0, 0, 0, 0, 0),
    L4(250, 0, 835, 0, 0, 0, 0, 0x2486, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 hugo_btca_020_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_020[24] = {
    L6(250, 0, 0, 0, 1, 0, 13, 0x24E0, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
    CMD(CM_UJA, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 21 IPPONZEOI */
const u16 hugo_btca_021_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_021[28] = {
    L6(250, 0, 0, 0, 1, 0, 0, 0x24E3, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
    CMD(CM_JMP, 1, 60, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 hugo_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_022[68] = {
    CMD(CM_RJA, 6, 22, 6), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 1, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 1, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 1, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E1, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 7, 51, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 hugo_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_btca_023[52] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x24DC, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x24DD, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 hugo_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_024[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2509, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x250A, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x250B, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x250B, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 hugo_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_025[44] = {
    CMD(CM_RJA, 7, 50, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 hugo_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2509, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x250A, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x250B, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x250B, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 hugo_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_027[44] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 hugo_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_028[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x24E6, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x24E5, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 hugo_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_029[44] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 hugo_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_030[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 hugo_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_031[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 835, 0, 0, 0, 0, 0x24DB, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 83, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 83, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 83, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 hugo_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_032[36] = {
    CMD(CM_RJA, 7, 7, 20), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x24B9, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24BA, 0, 232, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 hugo_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_033[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 834, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(1, 2, 285, 0, 0, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 hugo_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_034[124] = {
    CMD(CM_RJA, 7, 51, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x24A6, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 835, 0, 0, 0, 0, 0x24A7, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24A8, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24A9, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DB, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DC, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DD, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DE, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24DF, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24E0, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 hugo_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_btca_035[44] = {
    CMD(CM_RJA, 6, 35, 3), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 1, 0, 0, 0x24F5, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 7, 7, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 43 entries */
const u16* const hugo_caca[44] = {
    hugo_caca_000,  /* 0 CATCH 1 */
    hugo_caca_000,  /* 1 CATCH 2 */
    hugo_caca_000,  /* 2 CATCH 3 */
    hugo_caca_000,  /* 3 CATCH 4 */
    hugo_caca_004,  /* 4 CATCH 5 */
    hugo_caca_005,  /* 5 CATCH 6 */
    hugo_caca_006,  /* 6 CATCH 7 */
    hugo_caca_007,  /* 7 CATCH 8 */
    hugo_caca_008,  /* 8 CATCH 9 */
    hugo_caca_009,  /* 9 CATCH 10 */
    hugo_caca_010,  /* 10 CATCH 11 */
    hugo_caca_010,  /* 11 CATCH 12 */
    hugo_caca_012,  /* 12 CATCH 13 */
    hugo_caca_012,  /* 13 CATCH 14 */
    hugo_caca_012,  /* 14 CATCH 15 */
    hugo_caca_012,  /* 15 CATCH 16 */
    hugo_caca_016,  /* 16 CATCH 17 */
    hugo_caca_016,  /* 17 CATCH 18 */
    hugo_caca_016,  /* 18 CATCH 19 */
    hugo_caca_016,  /* 19 CATCH 20 */
    hugo_caca_020,  /* 20 CATCH 21 */
    hugo_caca_021,  /* 21 CATCH 22 */
    hugo_caca_022,  /* 22 CATCH 23 */
    hugo_caca_022,  /* 23 CATCH 24 */
    hugo_caca_024,  /* 24 CATCH 25 */
    hugo_caca_024,  /* 25 CATCH 26 */
    hugo_caca_024,  /* 26 CATCH 27 */
    hugo_caca_024,  /* 27 CATCH 28 */
    hugo_caca_028,  /* 28 CATCH 29 */
    hugo_caca_028,  /* 29 CATCH 30 */
    hugo_caca_028,  /* 30 CATCH 31 */
    hugo_caca_028,  /* 31 CATCH 32 */
    hugo_caca_032,  /* 32 CATCH 33 */
    hugo_caca_033,  /* 33 CATCH 34 */
    hugo_caca_034,  /* 34 CATCH 35 */
    hugo_caca_035,  /* 35 CATCH 36 */
    hugo_caca_035,  /* 36 CATCH 37 */
    hugo_caca_037,  /* 37 CATCH 38 */
    hugo_caca_038,  /* 38 CATCH 39 */
    hugo_caca_039,  /* 39 CATCH 40 */
    hugo_caca_039,  /* 40 no name */
    hugo_caca_041,  /* 41 no name */
    hugo_caca_042,  /* 42 no name */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 hugo_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_000[316] = {
    CMD(CM_NGDA, 1542, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 1, 0, 0x2615, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 2, 0, 0x2616, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x2617, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x2618, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 5, 0, 0x2619, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 6, 0, 0x261A, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 7, 0, 0x261B, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 8, 0, 0x2606, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 9, 0, 0x2607, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 10, 0, 0x2608, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 11, 0, 0x2609, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 12, 0, 0x260A, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 839, 0, 0, 13, 0, 0x260B, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 14, 0, 0x260C, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 15, 0, 0x2623, -5, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x260E, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x260F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2610, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2611, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2612, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2613, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2614, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 hugo_caca_004_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 hugo_caca_004[292] = {
    CMD(CM_NGDA, 1542, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2624, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 16, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 19, 0, 0x2635, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 5, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 6, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 7, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 74, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 0, 0, 0, 0, 24, 0, 0x263A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x262E, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x262F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2630, 0, 0, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2631, 0, 0, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 hugo_caca_005_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 hugo_caca_005[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x2401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 20, 0, 0x2636, -13, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 20, 0, 0x2636, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 hugo_caca_006_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 hugo_caca_006[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x2401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 20, 0, 0x2636, -13, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 20, 0, 0x2636, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 hugo_caca_007_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 hugo_caca_007[100] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x2401, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 20, 0, 0x2636, -13, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 20, 0, 0x2636, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 hugo_caca_008_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 hugo_caca_008[496] = {
    CMD(CM_NGDA, 6, 40, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 837, 0, 0, 0, 0, 0x267F, -21, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    CMD(CM_RJA, 2, 8, 33), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MDAT, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 270, 0, 0, 0, 0, 0x2680, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2681, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2682, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2683, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2684, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 25, 0, 0x26A2, 0, 0, 0, 0, 0, 30, 92, 0, 816, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 26, 0, 0x26A3, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 27, 0, 0x26A4, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2688, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x2689, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x26A5, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x26A6, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 30, 0, 0x26A7, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 31, 0, 0x26A8, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 32, 0, 0x26A9, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 33, 0, 0x26AA, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 34, 0, 0x26AB, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 35, 0, 0x26AC, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2692, 0, 0, 0, 0, 0, 0, 0, 0, 1128, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2693, 0, 0, 0, 0, 0, 0, 0, 0, 1152, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x2694, 0, 0, 0, 0, 0, 0, 0, 0, 1176, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2695, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2696, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 36, 10, 0x26AD, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 37, 10, 0x26AE, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 38, 10, 0x26AF, 0, 0, 0, 0, 0, 0, 0, 0, 1296, 0, 0, 0),
    L6(3, 3, 0, 2, 0, 0, 0, 0x269A, 0, 0, 0, 0, 0, 39, 28, 0, 1320, 0, 0, 0),
    L6(3, 4, 0, 2, 0, 0, 0, 0x269B, 0, 0, 0, 0, 0, 0, 0, 0, 1344, 0, 0, 0),
    L6(4, 4, 0, 2, 0, 0, 0, 0x269C, 0, 0, 0, 0, 0, 0, 0, 0, 1368, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x269D, 0, 0, 0, 0, 0, 0, 0, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x269E, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 0, 0, 0),
    L6(2, 9, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 1440, 0, 0, 0),
    L6(1, 7, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 84, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 hugo_caca_009_head[4] = { HEAD(6, 0, 26, 0, 0, 0, 0) };
const u16 hugo_caca_009[40] = {
    CMD(CM_NGDA, 6, 40, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 837, 0, 0, 0, 0, 0x267F, -22, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    CMD(CM_JMP, 2, 8, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11, 11 CATCH 12 */
const u16 hugo_caca_010_head[4] = { HEAD(6, 0, 28, 0, 0, 0, 0) };
const u16 hugo_caca_010[40] = {
    CMD(CM_NGDA, 6, 40, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 837, 0, 0, 0, 0, 0x267F, -23, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    CMD(CM_JMP, 2, 8, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14, 14 CATCH 15, 15 CATCH 16 */
const u16 hugo_caca_012_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_012[124] = {
    CMD(CM_NGDA, 1542, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1, 0, 0x2615, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 2, 0, 0x2616, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x2617, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x2618, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 5, 0, 0x2619, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 6, 0, 0x261A, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 7, 0, 0x261B, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(3, 6, 0, 0, 0, 8, 0, 0x2606, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 CATCH 17, 17 CATCH 18, 18 CATCH 19, 19 CATCH 20 */
const u16 hugo_caca_016_head[4] = { HEAD(6, 22, 28, 0, 0, 0, 0) };
const u16 hugo_caca_016[400] = {
    CMD(CM_NGDA, 6, 41, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 16, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 60, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 842, 0, 0, 0, 0, 0x2647, -47, 0, 0, 0, 0, 0, 0, 256, 1464, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2648, 0, 0, 0, 0, 0, 0, 0, 256, 1488, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2649, 0, 0, 0, 0, 0, 0, 0, 256, 1512, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264A, 0, 0, 0, 0, 0, 0, 0, 256, 1536, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264B, 0, 0, 0, 0, 0, 0, 0, 256, 1560, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264C, 0, 0, 0, 0, 0, 0, 0, 256, 1584, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x264D, 0, 0, 0, 0, 0, 0, 0, 256, 1608, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x264E, 0, 0, 0, 0, 0, 0, 0, 256, 1632, 0, 0, 0),
    CMD(CM_EXEC, 1, 85, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 86, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 843, 0, 0, 40, 0, 0x264F, 0, 0, 0, 0, 0, 22, 0, 256, 1656, 0, 0, 0),
    L6(5, 3, 0, 0, 0, 40, 0, 0x264F, 0, 0, 0, 0, 0, 22, 0, 256, 1656, 0, 0, 0),
    L6(5, 4, 0, 0, 0, 41, 0, 0x2650, 0, 0, 0, 0, 0, 0, 0, 256, 1680, 0, 0, 0),
    L6(5, 4, 0, 0, 0, 42, 0, 0x2651, 0, 0, 0, 0, 0, 0, 0, 256, 1704, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 43, 0, 0x2652, 0, 0, 0, 0, 0, 0, 0, 256, 1728, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x2653, 0, 0, 0, 0, 0, 0, 0, 256, 1752, 90, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x2654, 0, 0, 0, 0, 0, 0, 0, 256, 1776, 92, 0, 0),
    L6(6, 0, 836, 0, 0, 0, 0, 0x2655, 0, 0, 0, 0, 0, 0, 0, 256, 1800, 94, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x2656, 0, 0, 0, 0, 0, 0, 0, 256, 1824, 96, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2657, 0, 0, 0, 0, 0, 0, 0, 256, 1848, 0, 0, 0),
    L6(5, 9, 0, 0, 0, 0, 0, 0x2658, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2659, 0, 0, 0, 0, 0, 0, 0, 256, 0, 98, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x265A, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x265B, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x265C, 0, 0, 0, 0, 0, 0, 0, 256, 0, 100, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x25FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 CATCH 21 */
const u16 hugo_caca_020_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_020[160] = {
    CMD(CM_NGDA, 6, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x2661, -44, 0, 0, 0, 0, 0, 0, 0, 1872, 0, 0, 0),
    L6(4, 0, 837, 0, 0, 0, 0, 0x2662, 0, 0, 0, 0, 0, 0, 0, 0, 1896, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2663, 0, 0, 0, 0, 0, 0, 0, 0, 1920, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2664, 0, 0, 0, 0, 0, 0, 0, 0, 1944, 0, 0, 0),
    L6(2, 2, 270, 0, 0, 0, 0, 0x2665, 0, 0, 0, 0, 0, 0, 0, 0, 1968, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2666, 0, 0, 0, 0, 0, 0, 0, 0, 1992, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x2667, 0, 0, 0, 0, 0, 0, 0, 0, 2016, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2668, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2669, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2613, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 CATCH 22 */
const u16 hugo_caca_021_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_021[160] = {
    CMD(CM_NGDA, 6, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x2661, -45, 0, 0, 0, 0, 0, 0, 0, 1872, 0, 0, 0),
    L6(4, 0, 837, 0, 0, 0, 0, 0x2662, 0, 0, 0, 0, 0, 0, 0, 0, 1896, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2663, 0, 0, 0, 0, 0, 0, 0, 0, 1920, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2664, 0, 0, 0, 0, 0, 0, 0, 0, 1944, 0, 0, 0),
    L6(2, 2, 270, 0, 0, 0, 0, 0x2665, 0, 0, 0, 0, 0, 0, 0, 0, 1968, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2666, 0, 0, 0, 0, 0, 0, 0, 0, 1992, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x2667, 0, 0, 0, 0, 0, 0, 0, 0, 2016, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2668, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2669, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2613, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 CATCH 23, 23 CATCH 24 */
const u16 hugo_caca_022_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_022[160] = {
    CMD(CM_NGDA, 6, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x2661, -46, 0, 0, 0, 0, 0, 0, 0, 1872, 0, 0, 0),
    L6(4, 0, 837, 0, 0, 0, 0, 0x2662, 0, 0, 0, 0, 0, 0, 0, 0, 1896, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2663, 0, 0, 0, 0, 0, 0, 0, 0, 1920, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2664, 0, 0, 0, 0, 0, 0, 0, 0, 1944, 0, 0, 0),
    L6(3, 2, 270, 0, 0, 0, 0, 0x2665, 0, 0, 0, 0, 0, 0, 0, 0, 1968, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2666, 0, 0, 0, 0, 0, 0, 0, 0, 1992, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x2667, 0, 0, 0, 0, 0, 0, 0, 0, 2016, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2668, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2669, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2613, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2614, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 CATCH 25, 25 CATCH 26, 26 CATCH 27, 27 CATCH 28 */
const u16 hugo_caca_024_head[4] = { HEAD(6, 0, 60, 12, 0, 0, 0) };
const u16 hugo_caca_024[948] = {
    CMD(CM_NGDA, 0, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 24, 47), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 847, 0, 0, 26, 0, 0x26A3, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    CMD(CM_JSR, 2, 24, 55), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 24, 47), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 848, 0, 0, 26, 0, 0x26A3, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    CMD(CM_JSR, 2, 24, 55), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 24, 36), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 270, 0, 0, 0, 0, 0x267F, -55, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2680, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2681, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2682, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2683, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2684, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 25, 0, 0x26A2, 0, 0, 0, 0, 0, 30, 92, 0, 816, 0, 0, 0),
    L6(3, 20, 849, 0, 0, 26, 0, 0x26A3, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 27, 0, 0x26A4, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x2688, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2689, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x26A5, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 29, 0, 0x26A6, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 30, 0, 0x26A7, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 31, 0, 0x26A8, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 32, 0, 0x26A9, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 33, 0, 0x26AA, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 34, 0, 0x26AB, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 35, 0, 0x26AC, 0, 0, 0, 0, 0, 19, 2, 0, 1104, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2692, 0, 0, 0, 0, 0, 23, 0, 0, 1128, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2693, 0, 0, 0, 0, 0, 0, 0, 0, 1152, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2694, 0, 0, 0, 0, 0, 0, 0, 0, 1176, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2695, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2696, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 36, 10, 0x26AD, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 37, 10, 0x26AE, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 38, 10, 0x26AF, 0, 0, 0, 0, 0, 0, 0, 0, 1296, 0, 0, 0),
    L6(10, 3, 850, 2, 0, 0, 0, 0x269A, 0, 0, 0, 0, 0, 39, 32, 0, 1320, 0, 0, 0),
    CMD(CM_MDAT, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(10, 4, 0, 2, 0, 0, 0, 0x269B, 0, 0, 0, 0, 0, 39, 32, 0, 1344, 0, 0, 0),
    L6(8, 4, 0, 2, 0, 0, 0, 0x269C, 0, 0, 0, 0, 0, 39, 32, 0, 1368, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x269D, 0, 0, 0, 0, 0, 0, 0, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 0, 0x269E, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 0, 0, 0),
    L6(2, 9, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 2424, 0, 0, 0),
    L6(1, 7, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 85, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 0, 0, 0, 0, 0, 0x267F, -54, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x2680, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2681, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2682, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2683, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2684, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 25, 0, 0x26A2, 0, 0, 0, 0, 0, 30, 92, 0, 816, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 24, 68), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 27, 0, 0x26A4, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x2688, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2689, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x26A5, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 29, 0, 0x26A6, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 30, 0, 0x26A7, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2649, 0, 0, 0, 0, 0, 0, 0, 0, 2040, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264A, 0, 0, 0, 0, 0, 0, 0, 0, 2064, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264B, 0, 0, 0, 0, 0, 0, 0, 0, 2088, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x264C, 0, 0, 0, 0, 0, 0, 0, 0, 2112, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x264D, 0, 0, 0, 0, 0, 0, 0, 0, 2136, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x264E, 0, 0, 0, 0, 0, 0, 0, 0, 2160, 0, 0, 0),
    CMD(CM_EXEC, 1, 85, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 86, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 40, 0, 0x264F, 0, 0, 0, 0, 0, 22, 0, 0, 2184, 0, 0, 0),
    L6(5, 3, 0, 0, 0, 40, 0, 0x264F, 0, 0, 0, 0, 0, 0, 0, 0, 2184, 0, 0, 0),
    L6(5, 4, 0, 0, 0, 41, 0, 0x2650, 0, 0, 0, 0, 0, 0, 0, 0, 2208, 0, 0, 0),
    L6(5, 4, 0, 0, 0, 42, 0, 0x2651, 0, 0, 0, 0, 0, 0, 0, 0, 2232, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 43, 0, 0x2652, 0, 0, 0, 0, 0, 0, 0, 0, 2256, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2654, 0, 0, 0, 0, 0, 0, 0, 0, 2304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2655, 0, 0, 0, 0, 0, 0, 0, 0, 2328, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x265A, 0, 0, 0, 0, 0, 0, 0, 0, 2376, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x265B, 0, 0, 0, 0, 0, 0, 0, 0, 2400, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
};

/* script: 28 CATCH 29, 29 CATCH 30, 30 CATCH 31, 31 CATCH 32 */
const u16 hugo_caca_028_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 hugo_caca_028[580] = {
    CMD(CM_NGDA, 0, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 74, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 28, 38), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 22, 851, 0, 0, 31, 0, 0x26A8, -57, 0, 0, 0, 0, 0, 0, 512, 2448, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 32, 0, 0x26A9, 0, 0, 0, 0, 0, 0, 0, 512, 2472, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 32, 0, 0x26A9, 0, 0, 0, 0, 0, 0, 0, 512, 2472, 0, 0, 0),
    CMD(CM_MPCY, 256, 2, -32767), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 269, 0, 0, 33, 0, 0x26AA, 0, 0, 0, 0, 0, 0, 0, 512, 2496, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 34, 0, 0x26AB, 0, 0, 0, 0, 0, 0, 0, 512, 2520, 0, 0, 0),
    L6(2, 22, 0, 0, 0, 35, 0, 0x26AC, 0, 0, 0, 0, 0, 0, 0, 512, 2544, 0, 0, 0),
    L6(2, 1, 838, 0, 0, 0, 0, 0x2692, 0, 0, 0, 0, 0, 0, 0, 512, 2568, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 270, 0, 0, 48, 0, 0x2749, 0, 0, 0, 0, 0, 0, 0, 4608, 2592, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 49, 0, 0x274A, 0, 0, 0, 0, 0, 0, 0, 4608, 2616, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x274B, 0, 0, 0, 0, 0, 0, 0, 4608, 2640, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x274C, 0, 0, 0, 0, 0, 0, 0, 4608, 2664, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x274D, 0, 0, 0, 0, 0, 0, 0, 4608, 2688, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 34, 0, 0x26AB, 0, 0, 0, 0, 0, 0, 0, 4608, 2520, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 35, 0, 0x26AC, 0, 0, 0, 0, 0, 0, 0, 4608, 2544, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2692, 0, 0, 0, 0, 0, 0, 0, 4608, 2568, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x2693, 0, 0, 0, 0, 0, 19, 2, 4608, 2712, 0, 0, 0),
    L6(1, 9, 270, 0, 0, 0, 0, 0x2694, 0, 0, 0, 0, 0, 0, 0, 4096, 2808, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 36, 0, 0x26AD, 0, 0, 0, 0, 0, 23, 0, 4096, 2808, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2535, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x253A, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2539, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x2538, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2537, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2536, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 1, 0, 0, 0, 0, 15, 0x25E9, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 22, 0, 0, 0, 0, 15, 0x25E9, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 1, 852, 2, 0, 0, 15, 0x25E9, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 2, 0, 0, 15, 0x25EA, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(250, 0, 0, 2, 0, 0, 15, 0x25EB, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(8, 0, 0, 2, 0, 0, 0, 0x269A, -58, 130, 0, 0, 0, 39, 32, 4096, 0, 0, 0, 0),
    CMD(CM_MDAT, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 2, 0, 0, 0, 0x269B, 0, 0, 0, 0, 0, 39, 32, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x269C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 0, 0, 0x269D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 0, 0, 0, 0x269E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 9, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 7, 0, 2, 0, 0, 0, 0x269F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 86, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 2, 32, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 CATCH 33 */
const u16 hugo_caca_032_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 hugo_caca_032[112] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 2, 1, 0, 0, 0x252A, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 2, 1, 0, 0, 0x252C, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 270, 2, 0, 0, 0, 0x2467, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2468, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2469, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x246A, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 2, 0, 0, 0, 0x246B, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 CATCH 34 */
const u16 hugo_caca_033_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 hugo_caca_033[376] = {
    CMD(CM_NGDA, 0, 58, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2624, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    CMD(CM_MVIX, 93, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 16, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 19, 0, 0x2635, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_BGRLF, 0, 8192, 16391), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 59, 0, 0x2768, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 60, 0, 0x2769, 0, 0, 0, 0, 0, 0, 0, 0, 2856, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 61, 0, 0x276A, 0, 0, 0, 0, 0, 0, 0, 0, 2880, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 30, 0, 0, 0, 50, 0, 0x2758, 0, 0, 0, 0, 0, 0, 0, 0, 2904, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 51, 0, 0x2759, 0, 0, 0, 0, 0, 0, 0, 0, 2928, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 291, 0, 0, 52, 0, 0x275A, 0, 0, 0, 0, 0, 39, 2, 0, 2952, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 53, 0, 0x275B, 0, 0, 0, 0, 0, 0, 0, 0, 2976, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 54, 0, 0x275C, 0, 0, 0, 0, 0, 0, 0, 0, 2904, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 55, 0, 0x275D, 0, 0, 0, 0, 0, 0, 0, 0, 2928, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 291, 0, 0, 56, 0, 0x275E, 0, 0, 0, 0, 0, 39, 2, 0, 2952, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 57, 0, 0x275F, 0, 0, 0, 0, 0, 0, 0, 0, 2976, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 CATCH 35 */
const u16 hugo_caca_034_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 hugo_caca_034[40] = {
    CMD(CM_NGDA, 0, 58, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 2, 33, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 CATCH 36, 36 CATCH 37 */
const u16 hugo_caca_035_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 hugo_caca_035[40] = {
    CMD(CM_NGDA, 0, 58, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 2, 33, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 CATCH 38 */
const u16 hugo_caca_037_head[4] = { HEAD(6, 24, 8, 0, 0, 0, 1) };
const u16 hugo_caca_037[124] = {
    CMD(CM_RJA, 7, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 20, 0, 0, 0, 58, 0, 0x276E, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0),
    L6(2, 9, 837, 2, 0, 0, 0, 0x276F, 0, 0, 0, 0, 0, 0, 0, 0, 3024, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2770, -69, 172, 0, 64, 0, 38, 24, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 1, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 1280), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 2, 0, 0, 0, 0x2771, 0, 173, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2772, 0, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 5, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 CATCH 39 */
const u16 hugo_caca_038_head[4] = { HEAD(6, 24, 8, 0, 0, 0, 1) };
const u16 hugo_caca_038[124] = {
    CMD(CM_RJA, 7, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 20, 0, 0, 0, 58, 0, 0x276E, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0),
    L6(2, 9, 837, 2, 0, 0, 0, 0x276F, 0, 0, 0, 0, 0, 0, 0, 0, 3024, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2770, -69, 172, 0, 64, 0, 38, 24, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 1, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 1280), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 2, 0, 0, 0, 0x2771, 0, 173, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2772, 0, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 5, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 CATCH 40, 40 no name */
const u16 hugo_caca_039_head[4] = { HEAD(6, 24, 8, 0, 0, 0, 1) };
const u16 hugo_caca_039[124] = {
    CMD(CM_RJA, 7, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 20, 0, 0, 0, 58, 0, 0x276E, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0),
    L6(2, 9, 837, 2, 0, 0, 0, 0x276F, 0, 0, 0, 0, 0, 0, 0, 0, 3024, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2770, -69, 172, 0, 64, 0, 38, 24, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 2, -1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 1, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 0, 1280), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 2, 0, 0, 0, 0x2771, 0, 173, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 2, 0, 0, 0, 0x2772, 0, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 5, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 no name */
const u16 hugo_caca_041_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 hugo_caca_041[160] = {
    CMD(CM_NGDA, 1542, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2624, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 16, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 19, 0, 0x2635, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 20, 0, 0x2636, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(8, 2, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 24, 0, 0x263A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x262E, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x262E, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 hugo_caca_042_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 1) };
const u16 hugo_caca_042[364] = {
    CMD(CM_NGDA, 1542, 58, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2624, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    CMD(CM_MVIX, 93, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 16, 0, 0x2632, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 17, 0, 0x2633, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 18, 0, 0x2634, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 19, 0, 0x2635, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 20, 0, 0x2636, -68, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 20, 0, 0x2636, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x2637, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 22, 0, 0x2638, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 23, 0, 0x2639, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 59, 0, 0x2768, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 60, 0, 0x2769, 0, 0, 0, 0, 0, 0, 0, 0, 2856, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 61, 0, 0x276A, 0, 0, 0, 0, 0, 0, 0, 0, 2880, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 30, 0, 0, 0, 50, 0, 0x2758, 0, 0, 0, 0, 0, 0, 0, 0, 2904, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 51, 0, 0x2759, 0, 0, 0, 0, 0, 0, 0, 0, 2928, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 52, 0, 0x275A, 0, 0, 0, 0, 0, 39, 2, 0, 2952, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 53, 0, 0x275B, 0, 0, 0, 0, 0, 0, 0, 0, 2976, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 54, 0, 0x275C, 0, 0, 0, 0, 0, 0, 0, 0, 2904, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 55, 0, 0x275D, 0, 0, 0, 0, 0, 0, 0, 0, 2928, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 56, 0, 0x275E, 0, 0, 0, 0, 0, 39, 2, 0, 2952, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 57, 0, 0x275F, 0, 0, 0, 0, 0, 0, 0, 0, 2976, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const hugo_cuca[69] = {
    hugo_cuca_000,  /* 0 ALEX ZUTUKI */
    hugo_cuca_001,  /* 1 ALEX BODY S */
    hugo_cuca_002,  /* 2 ALEX BACK D */
    hugo_cuca_003,  /* 3 ALEX POWER B */
    hugo_cuca_004,  /* 4 ALEX SLEEPER */
    hugo_cuca_005,  /* 5 RYU SEOINAGE */
    hugo_cuca_006,  /* 6 IBUKI */
    hugo_cuca_007,  /* 7 DADLEY L B */
    hugo_cuca_008,  /* 8 IBUKI KUBIORI */
    hugo_cuca_009,  /* 9 NECRO S T */
    hugo_cuca_010,  /* 10 RYU TOMOENAGE */
    hugo_cuca_011,  /* 11 YUN HIZAGERI */
    hugo_cuca_012,  /* 12 ORO KUBISIME */
    hugo_cuca_013,  /* 13 NECRO G S */
    hugo_cuca_014,  /* 14 DUDDLEY D S */
    hugo_cuca_015,  /* 15 YUN MONKEY F */
    hugo_cuca_016,  /* 16 ORO TOMOENAGE */
    hugo_cuca_017,  /* 17 ORO NIOURIKI */
    hugo_cuca_018,  /* 18 ORO GIGOKU G */
    hugo_cuca_019,  /* 19 YUN */
    hugo_cuca_020,  /* 20 NECRO SNAKE F */
    hugo_cuca_021,  /* 21 NECRO F S */
    hugo_cuca_022,  /* 22 IBUKI HARAIG */
    hugo_cuca_023,  /* 23 GILL SPLASH M */
    hugo_cuca_024,  /* 24 KEN HIZAGERI */
    hugo_cuca_025,  /* 25 ORO KISINRIKI */
    hugo_cuca_026,  /* 26 SEAN TACKLE */
    hugo_cuca_027,  /* 27 ALEX HYPER B */
    hugo_cuca_028,  /* 28 NECRO SLAM D */
    hugo_cuca_029,  /* 29 ELENA ASINAGE */
    hugo_cuca_030,  /* 30 GILL IMPACT C */
    hugo_cuca_031,  /* 31 ALEX S H B */
    hugo_cuca_032,  /* 32 ALEX F N D */
    hugo_cuca_033,  /* 33 no name */
    hugo_cuca_034,  /* 34 IBUKI */
    hugo_cuca_035,  /* 35 IBUKI YOROI D */
    hugo_cuca_036,  /* 36 no name */
    hugo_cuca_037,  /* 37 MAWARIKOMI M F */
    hugo_cuca_038,  /* 38 HUGO BODY S */
    hugo_cuca_039,  /* 39 HUGO N G T */
    hugo_cuca_040,  /* 40 HUGO M S P */
    hugo_cuca_041,  /* 41 HUGO S D B B */
    hugo_cuca_042,  /* 42 no name */
    hugo_cuca_043,  /* 43 no name */
    hugo_cuca_044,  /* 44 no name */
    hugo_cuca_045,  /* 45 no name */
    hugo_cuca_046,  /* 46 no name */
    hugo_cuca_047,  /* 47 no name */
    hugo_cuca_048,  /* 48 no name */
    hugo_cuca_049,  /* 49 no name */
    hugo_cuca_050,  /* 50 no name */
    hugo_cuca_051,  /* 51 no name */
    hugo_cuca_052,  /* 52 no name */
    hugo_cuca_053,  /* 53 no name */
    hugo_cuca_054,  /* 54 no name */
    hugo_cuca_055,  /* 55 no name */
    hugo_cuca_056,  /* 56 no name */
    hugo_cuca_057,  /* 57 no name */
    hugo_cuca_058,  /* 58 no name */
    hugo_cuca_059,  /* 59 no name */
    hugo_cuca_060,  /* 60 no name */
    hugo_cuca_061,  /* 61 no name */
    hugo_cuca_062,  /* 62 no name */
    hugo_cuca_063,  /* 63 no name */
    hugo_cuca_064,  /* 64 no name */
    hugo_cuca_065,  /* 65 no name */
    hugo_cuca_066,  /* 66 no name */
    hugo_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 hugo_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2436),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C3),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2526),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 hugo_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2521),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x250B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E0),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 hugo_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E2),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 50, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 hugo_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E3),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 hugo_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x240E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2435),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C5),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24C8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 hugo_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E2),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 6, 21, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 hugo_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2408),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2406),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2411),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x257D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x257E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 hugo_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 hugo_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_008[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2410),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2415),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    CMD(CM_RMJA, 3, 8, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x249F),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 hugo_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2459),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2458),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2457),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 hugo_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2508),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x269D),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 hugo_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B6),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 hugo_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x240E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2459),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2456),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2481),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 hugo_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x258B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 hugo_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2471),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24AC),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 hugo_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_015[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2624),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2521),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 6, 23, 5),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 hugo_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x259C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x259B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x25A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24DF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 hugo_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_017[120] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x252C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x252B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    CMD(CM_RMJA, 3, 17, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 6, 12),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 7, 6, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 6, 12),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 7, 6, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 hugo_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_018[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24FB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FC),
    L2(250, 3, 0, 0, 1, 0, 0, 0x24FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FF),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2500),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 hugo_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2435),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2435),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2435),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2413),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 hugo_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2456),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2457),
    L2(250, 0, 0, 0, 1, 0, 0, 0x251D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2522),
    L2(250, 0, 0, 0, 2, 0, 0, 0x250A),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24DC),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 hugo_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2486),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2520),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2509),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 hugo_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2490),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DF),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 hugo_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24FA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2508),
    L2(250, 0, 0, 0, 3, 0, 0, 0x250B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x250B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24FC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24FC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E3),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 hugo_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 hugo_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x252C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x252B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DE),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 hugo_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2458),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2457),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DD),
    L2(250, 3, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EF),
    L2(250, 3, 0, 0, 0, 0, 0, 0x24E8),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24EF),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 hugo_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x252A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2526),
    L2(250, 0, 0, 0, 1, 0, 0, 0x252B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2526),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x25A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2521),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F8),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 18),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 hugo_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_028[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x258B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x258E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AD),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24AE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 hugo_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F4),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 hugo_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E3),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24D9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 hugo_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2436),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F1),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2526),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 hugo_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E6),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 hugo_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DE),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 hugo_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A9),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24A9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 hugo_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2408),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2406),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2411),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x257D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x257E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2548),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 hugo_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_036[164] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2496),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 2, 0, 0, 1, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2507),
    L2(250, 2, 0, 0, 1, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 2, 0, 0, 1, 0, 0, 0x250A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2502),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2503),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2502),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2503),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 hugo_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x258A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x24DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 hugo_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2457),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x252B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F6),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 hugo_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24D9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 hugo_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2496),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2560),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x25EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x259D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F0),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 hugo_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24EC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DC),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 hugo_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AE),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24AD),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 hugo_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2505),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2505),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 hugo_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2496),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2560),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x246E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x25EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x259D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24DE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24EC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2521),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 hugo_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24BD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 hugo_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_046[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x25EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x259D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x259D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E5),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 30, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 hugo_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x24E6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25C1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x252A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2526),
    L2(250, 0, 0, 0, 1, 0, 0, 0x252B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2526),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E1),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E2),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 50, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 hugo_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2437),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2436),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2528),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2526),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 hugo_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2508),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F8),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 hugo_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_050[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2508),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24FA),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24FC),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 hugo_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x25B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 2, 0, 0, 0, 0, 0, 0x24B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C1),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 hugo_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2520),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2508),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25EE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2521),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2594),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x269D),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 hugo_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2402),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2480),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2486),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2487),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25D0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x25A9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AD),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24A9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 1, 0, 0, 0x25DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2509),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24E1),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 18),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 hugo_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2491),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2492),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2494),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2495),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2486),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2480),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2487),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2487),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2489),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 39, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 hugo_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2402),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2480),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2486),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2487),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25D0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x25D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x25A9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x24AD),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 hugo_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 2, 0, 0, 0, 0, 0, 0x24B9),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24BA),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 hugo_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2488),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2489),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2486),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24F3),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 51, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 hugo_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2507),
    L2(250, 0, 0, 0, 0, 0, 0, 0x251F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24D9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 hugo_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2437),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2436),
    L2(250, 0, 0, 0, 0, 0, 0, 0x245A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x245B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F4),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24F5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 hugo_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B6),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 hugo_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2450),
    L2(250, 0, 0, 0, 0, 0, 0, 0x244F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x244E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x244D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2485),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2483),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24DC),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24DE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 hugo_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249E),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249F),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24A0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2498),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2499),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x249B),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B6),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24B7),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 16),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24BD),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24F9),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F7),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 hugo_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B9),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 835, 0, 0, 0, 0, 0x24BA),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 hugo_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x248A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2484),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B0),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24B9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 hugo_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_065[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x248B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2497),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2498),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2499),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x249B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2521),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 6, 23, 5),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 hugo_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2436),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2482),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2481),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2500),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24EC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x24E7),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x24E7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 hugo_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x24B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2490),
    L2(250, 0, 0, 0, 0, 0, 0, 0x248D),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x24F5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 156 entries */
const u16* const hugo_atca[157] = {
    hugo_atca_000,  /* 0 S PUNCH A */
    hugo_atca_000,  /* 1 S PUNCH B */
    hugo_atca_000,  /* 2 S PUNCH C */
    hugo_atca_003,  /* 3 M PUNCH A */
    hugo_atca_003,  /* 4 M PUNCH B */
    hugo_atca_003,  /* 5 M PUNCH C */
    hugo_atca_006,  /* 6 L PUNCH A */
    hugo_atca_007,  /* 7 L PUNCH B */
    hugo_atca_007,  /* 8 L PUNCH C */
    hugo_atca_009,  /* 9 S KICK A */
    hugo_atca_009,  /* 10 S KICK B */
    hugo_atca_009,  /* 11 S KICK C */
    hugo_atca_012,  /* 12 M KICK A */
    hugo_atca_012,  /* 13 M KICK B */
    hugo_atca_012,  /* 14 M KICK C */
    hugo_atca_015,  /* 15 L KICK A */
    hugo_atca_015,  /* 16 L KICK B */
    hugo_atca_015,  /* 17 L KICK C */
    hugo_atca_018,  /* 18 KAGAMI P A */
    hugo_atca_018,  /* 19 KAGAMI P B */
    hugo_atca_018,  /* 20 KAGAMI P C */
    hugo_atca_021,  /* 21 KAGAMI P A */
    hugo_atca_021,  /* 22 KAGAMI P B */
    hugo_atca_021,  /* 23 KAGAMI P C */
    hugo_atca_024,  /* 24 KAGAMI P A */
    hugo_atca_024,  /* 25 KAGAMI P B */
    hugo_atca_024,  /* 26 KAGAMI P C */
    hugo_atca_027,  /* 27 KAGAMI K A */
    hugo_atca_027,  /* 28 KAGAMI K B */
    hugo_atca_027,  /* 29 KAGAMI K C */
    hugo_atca_030,  /* 30 KAGAMI K A */
    hugo_atca_030,  /* 31 KAGAMI K B */
    hugo_atca_030,  /* 32 KAGAMI K C */
    hugo_atca_033,  /* 33 KAGAMI K A */
    hugo_atca_033,  /* 34 KAGAMI K B */
    hugo_atca_033,  /* 35 KAGAMI K C */
    hugo_atca_036,  /* 36 V JUMP P S A */
    hugo_atca_036,  /* 37 V JUMP P S B */
    hugo_atca_038,  /* 38 V JUMP P M A */
    hugo_atca_038,  /* 39 V JUMP P M B */
    hugo_atca_040,  /* 40 V JUMP P L A */
    hugo_atca_041,  /* 41 V JUMP P L B */
    hugo_atca_042,  /* 42 V JUMP K S A */
    hugo_atca_042,  /* 43 V JUMP K S B */
    hugo_atca_044,  /* 44 V JUMP K M A */
    hugo_atca_044,  /* 45 V JUMP K M B */
    hugo_atca_046,  /* 46 V JUMP K L A */
    hugo_atca_046,  /* 47 V JUMP K L B */
    hugo_atca_048,  /* 48 F JUMP P S A */
    hugo_atca_048,  /* 49 F JUMP P S B */
    hugo_atca_050,  /* 50 F JUMP P M A */
    hugo_atca_050,  /* 51 F JUMP P M B */
    hugo_atca_052,  /* 52 F JUMP P L A */
    hugo_atca_053,  /* 53 F JUMP P L B */
    hugo_atca_054,  /* 54 F JUMP K S A */
    hugo_atca_054,  /* 55 F JUMP K S B */
    hugo_atca_056,  /* 56 F JUMP K M A */
    hugo_atca_056,  /* 57 F JUMP K M B */
    hugo_atca_058,  /* 58 F JUMP K L A */
    hugo_atca_058,  /* 59 F JUMP K L B */
    hugo_atca_060,  /* 60 B JUMP P S A */
    hugo_atca_060,  /* 61 B JUMP P S B */
    hugo_atca_062,  /* 62 B JUMP P M A */
    hugo_atca_062,  /* 63 B JUMP P M B */
    hugo_atca_064,  /* 64 B JUMP P L A */
    hugo_atca_065,  /* 65 B JUMP P L B */
    hugo_atca_066,  /* 66 B JUMP K S A */
    hugo_atca_066,  /* 67 B JUMP K S B */
    hugo_atca_068,  /* 68 B JUMP K M A */
    hugo_atca_068,  /* 69 B JUMP K M B */
    hugo_atca_070,  /* 70 B JUMP K L A */
    hugo_atca_070,  /* 71 B JUMP K L B */
    hugo_atca_072,  /* 72 SP V JP S P A */
    hugo_atca_072,  /* 73 SP V JP S P B */
    hugo_atca_074,  /* 74 SP V JP M P A */
    hugo_atca_074,  /* 75 SP V JP M P B */
    hugo_atca_076,  /* 76 SP V JP L P A */
    hugo_atca_077,  /* 77 SP V JP L P B */
    hugo_atca_078,  /* 78 SP V JP S K A */
    hugo_atca_078,  /* 79 SP V JP S K B */
    hugo_atca_080,  /* 80 SP V JP M K A */
    hugo_atca_080,  /* 81 SP V JP M K B */
    hugo_atca_082,  /* 82 SP V JP L K A */
    hugo_atca_082,  /* 83 SP V JP L K B */
    hugo_atca_084,  /* 84 SP F JP S P A */
    hugo_atca_084,  /* 85 SP F JP S P B */
    hugo_atca_086,  /* 86 SP F JP M P A */
    hugo_atca_086,  /* 87 SP F JP M P B */
    hugo_atca_088,  /* 88 SP F JP L P A */
    hugo_atca_089,  /* 89 SP F JP L P B */
    hugo_atca_090,  /* 90 SP F JP S K A */
    hugo_atca_090,  /* 91 SP F JP S K B */
    hugo_atca_092,  /* 92 SP F JP M K A */
    hugo_atca_092,  /* 93 SP F JP M K B */
    hugo_atca_094,  /* 94 SP F JP L K A */
    hugo_atca_094,  /* 95 SP F JP L K B */
    hugo_atca_096,  /* 96 SP B JP S P A */
    hugo_atca_096,  /* 97 SP B JP S P B */
    hugo_atca_098,  /* 98 SP B JP M P A */
    hugo_atca_098,  /* 99 SP B JP M P B */
    hugo_atca_100,  /* 100 SP B JP L P A */
    hugo_atca_101,  /* 101 SP B JP L P B */
    hugo_atca_102,  /* 102 SP B JP S K A */
    hugo_atca_102,  /* 103 SP B JP S K B */
    hugo_atca_104,  /* 104 SP B JP M K A */
    hugo_atca_104,  /* 105 SP B JP M K B */
    hugo_atca_106,  /* 106 SP B JP L K A */
    hugo_atca_106,  /* 107 SP B JP L K B */
    hugo_atca_108,  /* 108 S V JP S P A */
    hugo_atca_108,  /* 109 S V JP S P B */
    hugo_atca_110,  /* 110 S V JP M P A */
    hugo_atca_110,  /* 111 S V JP M P B */
    hugo_atca_112,  /* 112 S V JP L P A */
    hugo_atca_112,  /* 113 S V JP L P B */
    hugo_atca_114,  /* 114 S V JP S K A */
    hugo_atca_114,  /* 115 S V JP S K B */
    hugo_atca_116,  /* 116 S V JP M K A */
    hugo_atca_116,  /* 117 S V JP M K B */
    hugo_atca_118,  /* 118 S V JP L K A */
    hugo_atca_118,  /* 119 S V JP L K B */
    hugo_atca_120,  /* 120 S F JP S P A */
    hugo_atca_120,  /* 121 S F JP S P B */
    hugo_atca_122,  /* 122 S F JP M P A */
    hugo_atca_122,  /* 123 S F JP M P B */
    hugo_atca_124,  /* 124 S F JP L P A */
    hugo_atca_124,  /* 125 S F JP L P B */
    hugo_atca_126,  /* 126 S F JP S K A */
    hugo_atca_126,  /* 127 S F JP S K B */
    hugo_atca_128,  /* 128 S F JP M K A */
    hugo_atca_128,  /* 129 S F JP M K B */
    hugo_atca_130,  /* 130 S F JP L K A */
    hugo_atca_130,  /* 131 S F JP L K B */
    hugo_atca_132,  /* 132 S B JP S P A */
    hugo_atca_132,  /* 133 S B JP S P B */
    hugo_atca_134,  /* 134 S B JP M P A */
    hugo_atca_134,  /* 135 S B JP M P B */
    hugo_atca_136,  /* 136 S B JP L P A */
    hugo_atca_136,  /* 137 S B JP L P B */
    hugo_atca_138,  /* 138 S B JP S K A */
    hugo_atca_138,  /* 139 S B JP S K B */
    hugo_atca_140,  /* 140 S B JP M K A */
    hugo_atca_140,  /* 141 S B JP M K B */
    hugo_atca_142,  /* 142 S B JP L K A */
    hugo_atca_142,  /* 143 S B JP L K B */
    hugo_atca_144,  /* 144 TUKAMIKAKARI A */
    hugo_atca_145,  /* 145 TUKAMIKAKARI B */
    hugo_atca_146,  /* 146 TUKAMIKAKARI C */
    hugo_atca_144,  /* 147 TUKAMIKAKARI D */
    hugo_atca_144,  /* 148 TUKAMIKAKARI E */
    hugo_atca_144,  /* 149 TUKAMIKAKARI F */
    hugo_atca_144,  /* 150 TUKAMI AIR A */
    hugo_atca_144,  /* 151 TUKAMI AIR B */
    hugo_atca_144,  /* 152 TUKAMI AIR C */
    hugo_atca_144,  /* 153 TUKAMI AIR D */
    hugo_atca_144,  /* 154 TUKAMI AIR E */
    hugo_atca_144,  /* 155 TUKAMI AIR F */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B, 2 S PUNCH C */
const u16 hugo_atca_000_head[4] = { HEAD(4, 0, 0, 16, 0, 1, 0) };
const u16 hugo_atca_000[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2540, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2545, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2540, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x2541, -1, 9, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2542, 1, 10, 155, 0, 24, 0, 3),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2543, 0, 11, 155, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2544, 0, 11, 155, 0, 24, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2545, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2546, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2547, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2547, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B, 5 M PUNCH C */
const u16 hugo_atca_003_head[4] = { HEAD(4, 0, 2, 16, 0, 1, 0) };
const u16 hugo_atca_003[164] = {
    L4(2, 0, 841, 0, 0, 0, 0, 0x2548, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2549, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x254A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x254B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x254C, -2, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x254C, 2, 13, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x254D, 0, 13, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x254E, 0, 14, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x254F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x254E, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x254F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 hugo_atca_006_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 hugo_atca_006[268] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x256D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x256E, 0, 15, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x256F, 0, 15, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(4, 0, 836, 0, 0, 0, 0, 0x2570, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2571, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2572, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 204, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 205, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 206, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 207, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 286, 0, 0, 0, 0, 0x2573, 0, 16, 0, 0, 0, 30, 208, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x2574, -3, 17, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2575, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2576, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2577, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2578, 0, 19, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2579, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x257A, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x257B, 0, 20, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x257C, 0, 20, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x257C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 hugo_atca_007_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 hugo_atca_007[508] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x2554, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2555, 0, 22, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2556, 0, 22, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2557, 0, 23, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 839, 1, 0, 0, 0, 0x2558, 0, 24, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x2559, -6, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255A, 0, 26, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    CMD(CM_HJMP, 16400, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x255A, 0, 140, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255B, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2560, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2561, 0, 1, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2562, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2563, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2564, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2565, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x255A, 0, 140, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255B, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x255D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2560, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2561, 0, 1, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2562, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2563, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2564, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2565, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 hugo_atca_009_head[4] = { HEAD(4, 0, 1, 14, 0, 1, 0) };
const u16 hugo_atca_009[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x257D, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 840, 0, 0, 0, 0, 0x257E, 0, 141, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x257F, -7, 28, 0, 133, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x257F, 0, 29, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2580, 0, 30, 0, 0, 96, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2581, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2582, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2583, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B, 14 M KICK C */
const u16 hugo_atca_012_head[4] = { HEAD(6, 0, 3, 14, 0, 2, 0) };
const u16 hugo_atca_012[412] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x2584, 0, 1, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(6, 0, 836, 0, 0, 0, 0, 0x2585, 0, 31, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x2586, -8, 32, 0, 134, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2586, 0, 33, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2587, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2587, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x2588, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2589, -32, 35, 0, 64, 0, 0, 0, 0, 0, 42, 0, 0),
    CMD(CM_HJMP, 16396, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 10, 0, 0), 0x002B, 0x001E, 0x003C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    L6(1, 0, 286, 0, 0, 0, 0, 0x258A, 0, 31, 0, 0, 0, 21, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258A, 0, 31, 0, 0, 0, 30, 61, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258B, 0, 1, 0, 0, 0, 30, 62, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258B, 0, 1, 0, 0, 0, 30, 63, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x258C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x258D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x258E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x258F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2590, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    CMD(CM_IXFW, 0, 0, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 10, 0, 0), 0x002B, 0x001E, 0x003C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    L6(1, 0, 286, 0, 0, 0, 0, 0x258A, 0, 31, 0, 0, 0, 21, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258A, 0, 31, 0, 0, 0, 30, 61, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258B, 0, 1, 0, 0, 0, 30, 62, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x258B, 0, 1, 0, 0, 0, 30, 63, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x258C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x258D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x258E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x258F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2590, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x2591, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 hugo_atca_015_head[4] = { HEAD(4, 0, 5, 14, 0, 1, 0) };
const u16 hugo_atca_015[244] = {
    CMD(CM_RJA, 4, 15, 14), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 838, 0, 0, 0, 0, 0x2592, 0, 1, 0, 0, 0, 22, 22),
    L4(4, 0, 0, 0, 0, 0, 14, 0x2593, 0, 51, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x2594, 0, 51, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x2595, 0, 51, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x2596, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 14, 0x2597, -12, 53, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x2598, 0, 54, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x2599, 0, 54, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 14, 0x259A, 0, 52, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 14, 0x259B, 0, 55, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x259C, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 74, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 75, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 285, 0, 0, 0, 0, 0x259D, 0, 67, 0, 0, 0, 22, 32),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2529, 0, 67, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16391, 8192), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x252A, 0, 67, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x252B, 0, 67, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2525, 0, 145, 0, 0, 0, 24, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2526, 0, 145, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2527, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2528, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2528, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 hugo_atca_018_head[4] = { HEAD(4, 32, 0, 15, 0, 1, 0) };
const u16 hugo_atca_018[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x259E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A3, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x259E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x25A0, -14, 57, 16, 0, 120, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A1, 0, 57, 16, 0, 120, 0, 3),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25A2, 0, 58, 16, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A3, 0, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A4, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x25A5, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25A5, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 hugo_atca_021_head[4] = { HEAD(4, 32, 2, 17, 0, 1, 0) };
const u16 hugo_atca_021[76] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x259E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x259F, -15, 59, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A0, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25A1, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25A2, 0, 61, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25A3, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25A4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x25A5, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25A5, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 hugo_atca_024_head[4] = { HEAD(6, 32, 4, 9, 0, 1, 0) };
const u16 hugo_atca_024[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x25A6, 0, 70, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25A7, 0, 70, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25A8, 0, 70, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x25A9, 0, 71, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 1, 839, 0, 0, 0, 11, 0x25AA, -17, 72, 0, 0, 0, 30, 52, 0, 0, 64, 0, 0),
    L6(9, 0, 270, 0, 0, 0, 11, 0x25AB, 18, 73, 0, 0, 0, 30, 53, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 11, 0x25AC, 18, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 11, 0x25AD, 0, 75, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 11, 0x25AD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 hugo_atca_027_head[4] = { HEAD(4, 32, 1, 14, 0, 1, 0) };
const u16 hugo_atca_027[84] = {
    L4(3, 0, 268, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 0, 268, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 840, 0, 0, 0, 0, 0x25B0, -16, 62, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25B1, 0, 63, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25B1, 0, 64, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25B2, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25B3, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x25B4, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25B4, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 hugo_atca_030_head[4] = { HEAD(4, 32, 3, 17, 0, 1, 0) };
const u16 hugo_atca_030[92] = {
    L4(2, 0, 269, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25AE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 839, 0, 0, 0, 0, 0x25AF, -24, 65, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25B0, 0, 66, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25B1, 0, 85, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25B2, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25B3, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25B4, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25B4, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 hugo_atca_033_head[4] = { HEAD(6, 32, 5, 9, 0, 1, 0) };
const u16 hugo_atca_033[100] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x25B5, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25B6, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 841, 0, 0, 0, 0, 0x25B7, 0, 78, 0, 0, 0, 30, 54, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25B7, 0, 78, 0, 0, 0, 30, 55, 0, 0, 0, 0, 0),
    L6(3, 1, 270, 0, 0, 0, 0, 0x25B8, -19, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x25B9, 19, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x25BA, 20, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 hugo_atca_036_head[4] = { HEAD(4, 22, 0, 15, 0, 1, 0) };
const u16 hugo_atca_036[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 840, 0, 0, 0, 8, 0x25C4, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 8, 0x25C5, -25, 86, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x25C6, 25, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x25C7, 25, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C8, 0, 89, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C9, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2454, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x2455, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 hugo_atca_038_head[4] = { HEAD(4, 22, 2, 16, 0, 1, 0) };
const u16 hugo_atca_038[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(6, 0, 836, 0, 0, 0, 8, 0x25C4, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 8, 0x25C5, -27, 90, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C6, 27, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C7, 27, 92, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C8, 0, 93, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25C9, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2454, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x2455, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A */
const u16 hugo_atca_040_head[4] = { HEAD(4, 22, 4, 17, 0, 1, 0) };
const u16 hugo_atca_040[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 838, 0, 0, 0, 8, 0x25CA, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25CB, 0, 95, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x25CC, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 8, 0x25CD, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25CE, -28, 97, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25CF, 28, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25CF, 0, 96, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25D0, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25D1, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25D2, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25D3, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25D4, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x25D5, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 V JUMP P L B */
const u16 hugo_atca_041_head[4] = { HEAD(4, 22, 4, 10, 0, 1, 0) };
const u16 hugo_atca_041[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 13, 0x25E7, 0, 124, 0, 0, 0, 0, 0),
    L4(5, 0, 839, 0, 0, 0, 13, 0x25E8, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 13, 0x25E9, -53, 126, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 13, 0x25EA, 0, 126, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 13, 0x25EB, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_MPCY, 8, 1, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x25EC, 28, 127, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x25ED, 0, 128, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x25EE, 0, 129, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 hugo_atca_042_head[4] = { HEAD(4, 22, 1, 9, 0, 1, 0) };
const u16 hugo_atca_042[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 836, 0, 0, 0, 8, 0x25D6, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 8, 0x25D7, -29, 103, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 8, 0x25D8, 29, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25D9, 0, 143, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25DA, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25DB, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2454, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x2455, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 hugo_atca_044_head[4] = { HEAD(4, 22, 3, 9, 0, 1, 0) };
const u16 hugo_atca_044[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(5, 0, 836, 0, 0, 0, 8, 0x25D6, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 8, 0x25D7, -30, 106, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x25D8, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25D9, 0, 143, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25DA, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25DB, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2454, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x2455, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 hugo_atca_046_head[4] = { HEAD(4, 22, 5, 13, 0, 1, 0) };
const u16 hugo_atca_046[140] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 8, 0x25DC, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25DD, 0, 109, 0, 0, 0, 0, 0),
    L4(2, 0, 837, 0, 0, 0, 8, 0x25DE, 0, 110, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x25DF, 0, 110, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x25E0, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 8, 0x25E1, -31, 112, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 8, 0x25E2, 31, 113, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25E3, 0, 114, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x25E4, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25E5, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x25E6, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x2452, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2453, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x2454, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x2455, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 hugo_atca_048_head[4] = { HEAD(2, 20, 0, 16, 0, 1, 0) };
const u16 hugo_atca_048[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 hugo_atca_050_head[4] = { HEAD(2, 20, 2, 17, 0, 1, 0) };
const u16 hugo_atca_050[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A */
const u16 hugo_atca_052_head[4] = { HEAD(2, 20, 4, 18, 0, 1, 0) };
const u16 hugo_atca_052[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 F JUMP P L B */
const u16 hugo_atca_053_head[4] = { HEAD(2, 20, 4, 11, 0, 1, 0) };
const u16 hugo_atca_053[8] = {
    CMD(CM_JPSS, 4, 41, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 hugo_atca_054_head[4] = { HEAD(2, 20, 1, 10, 0, 1, 0) };
const u16 hugo_atca_054[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 hugo_atca_056_head[4] = { HEAD(2, 20, 3, 10, 0, 1, 0) };
const u16 hugo_atca_056[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 hugo_atca_058_head[4] = { HEAD(2, 20, 5, 14, 0, 1, 0) };
const u16 hugo_atca_058[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 hugo_atca_060_head[4] = { HEAD(2, 24, 0, 15, 0, 1, 0) };
const u16 hugo_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 hugo_atca_062_head[4] = { HEAD(2, 24, 2, 16, 0, 1, 0) };
const u16 hugo_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A */
const u16 hugo_atca_064_head[4] = { HEAD(2, 24, 4, 17, 0, 1, 0) };
const u16 hugo_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 B JUMP P L B */
const u16 hugo_atca_065_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 hugo_atca_065[8] = {
    CMD(CM_JPSS, 4, 41, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 hugo_atca_066_head[4] = { HEAD(2, 24, 1, 9, 0, 1, 0) };
const u16 hugo_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 hugo_atca_068_head[4] = { HEAD(2, 24, 3, 9, 0, 1, 0) };
const u16 hugo_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 hugo_atca_070_head[4] = { HEAD(2, 24, 5, 13, 0, 1, 0) };
const u16 hugo_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 hugo_atca_072_head[4] = { HEAD(2, 28, 0, 15, 0, 1, 0) };
const u16 hugo_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 hugo_atca_074_head[4] = { HEAD(2, 28, 2, 16, 0, 1, 0) };
const u16 hugo_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A */
const u16 hugo_atca_076_head[4] = { HEAD(2, 28, 4, 17, 0, 1, 0) };
const u16 hugo_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 SP V JP L P B */
const u16 hugo_atca_077_head[4] = { HEAD(2, 28, 4, 10, 0, 1, 0) };
const u16 hugo_atca_077[8] = {
    CMD(CM_JPSS, 4, 41, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 hugo_atca_078_head[4] = { HEAD(2, 28, 1, 9, 0, 1, 0) };
const u16 hugo_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 hugo_atca_080_head[4] = { HEAD(2, 28, 3, 9, 0, 1, 0) };
const u16 hugo_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 hugo_atca_082_head[4] = { HEAD(2, 28, 5, 13, 0, 1, 0) };
const u16 hugo_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 hugo_atca_084_head[4] = { HEAD(2, 26, 0, 16, 0, 1, 0) };
const u16 hugo_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 hugo_atca_086_head[4] = { HEAD(2, 26, 2, 17, 0, 1, 0) };
const u16 hugo_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A */
const u16 hugo_atca_088_head[4] = { HEAD(2, 26, 4, 18, 0, 1, 0) };
const u16 hugo_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 SP F JP L P B */
const u16 hugo_atca_089_head[4] = { HEAD(2, 26, 4, 11, 0, 1, 0) };
const u16 hugo_atca_089[8] = {
    CMD(CM_JPSS, 4, 53, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 hugo_atca_090_head[4] = { HEAD(2, 26, 1, 10, 0, 1, 0) };
const u16 hugo_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 hugo_atca_092_head[4] = { HEAD(2, 26, 3, 10, 0, 1, 0) };
const u16 hugo_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 hugo_atca_094_head[4] = { HEAD(2, 26, 5, 14, 0, 1, 0) };
const u16 hugo_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 hugo_atca_096_head[4] = { HEAD(2, 30, 0, 15, 0, 1, 0) };
const u16 hugo_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 hugo_atca_098_head[4] = { HEAD(2, 30, 2, 16, 0, 1, 0) };
const u16 hugo_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A */
const u16 hugo_atca_100_head[4] = { HEAD(2, 30, 4, 17, 0, 1, 0) };
const u16 hugo_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 101 SP B JP L P B */
const u16 hugo_atca_101_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 hugo_atca_101[8] = {
    CMD(CM_JPSS, 4, 41, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 hugo_atca_102_head[4] = { HEAD(2, 30, 1, 9, 0, 1, 0) };
const u16 hugo_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 hugo_atca_104_head[4] = { HEAD(2, 30, 3, 9, 0, 1, 0) };
const u16 hugo_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 hugo_atca_106_head[4] = { HEAD(2, 30, 5, 13, 0, 1, 0) };
const u16 hugo_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B */
const u16 hugo_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 1, 0) };
const u16 hugo_atca_108[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B */
const u16 hugo_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 1, 0) };
const u16 hugo_atca_110[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B */
const u16 hugo_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 1, 0) };
const u16 hugo_atca_112[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B */
const u16 hugo_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 1, 0) };
const u16 hugo_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B */
const u16 hugo_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 1, 0) };
const u16 hugo_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B */
const u16 hugo_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 1, 0) };
const u16 hugo_atca_118[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 120 S F JP S P A, 121 S F JP S P B */
const u16 hugo_atca_120_head[4] = { HEAD(2, 14, 0, 0, 0, 1, 0) };
const u16 hugo_atca_120[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 122 S F JP M P A, 123 S F JP M P B */
const u16 hugo_atca_122_head[4] = { HEAD(2, 14, 2, 0, 0, 1, 0) };
const u16 hugo_atca_122[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 124 S F JP L P A, 125 S F JP L P B */
const u16 hugo_atca_124_head[4] = { HEAD(2, 14, 4, 0, 0, 1, 0) };
const u16 hugo_atca_124[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 126 S F JP S K A, 127 S F JP S K B */
const u16 hugo_atca_126_head[4] = { HEAD(2, 14, 1, 0, 0, 1, 0) };
const u16 hugo_atca_126[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 128 S F JP M K A, 129 S F JP M K B */
const u16 hugo_atca_128_head[4] = { HEAD(2, 14, 3, 0, 0, 1, 0) };
const u16 hugo_atca_128[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 130 S F JP L K A, 131 S F JP L K B */
const u16 hugo_atca_130_head[4] = { HEAD(2, 14, 5, 0, 0, 1, 0) };
const u16 hugo_atca_130[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 132 S B JP S P A, 133 S B JP S P B */
const u16 hugo_atca_132_head[4] = { HEAD(2, 18, 0, 0, 0, 1, 0) };
const u16 hugo_atca_132[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 134 S B JP M P A, 135 S B JP M P B */
const u16 hugo_atca_134_head[4] = { HEAD(2, 18, 2, 0, 0, 1, 0) };
const u16 hugo_atca_134[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 136 S B JP L P A, 137 S B JP L P B */
const u16 hugo_atca_136_head[4] = { HEAD(2, 18, 4, 0, 0, 1, 0) };
const u16 hugo_atca_136[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 138 S B JP S K A, 139 S B JP S K B */
const u16 hugo_atca_138_head[4] = { HEAD(2, 18, 1, 0, 0, 1, 0) };
const u16 hugo_atca_138[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 140 S B JP M K A, 141 S B JP M K B */
const u16 hugo_atca_140_head[4] = { HEAD(2, 18, 3, 0, 0, 1, 0) };
const u16 hugo_atca_140[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 142 S B JP L K A, 143 S B JP L K B */
const u16 hugo_atca_142_head[4] = { HEAD(2, 18, 5, 0, 0, 1, 0) };
const u16 hugo_atca_142[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 hugo_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_atca_144[68] = {
    CMD(CM_CAFR, 2, 1, 4), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 4), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x25FB, -4, 155, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 21, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 hugo_atca_145_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_atca_145[16] = {
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 hugo_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 12),
    CMD(CM_CARE, 2, 2, 12),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX hugo_olc_ix_table[62] = {
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
    { { 49, 0, 0, 0 } },
    { { 50, 0, 0, 0 } },
    { { 51, 0, 0, 0 } },
    { { 52, 0, 0, 0 } },
    { { 0, 53, 0, 0 } },
    { { 0, 54, 0, 0 } },
    { { 0, 55, 0, 0 } },
    { { 0, 56, 0, 0 } },
    { { 0, 57, 0, 0 } },
    { { 0, 58, 0, 0 } },
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
};

const OVERLAP_PARTS hugo_overlap_char_tbl[71] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 9727 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 9728 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 9729 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 9730 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 9731 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 6, 9732 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 7, 9733 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 8, 9756 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 9, 9757 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 10, 9758 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 11, 9759 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 12, 9760 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 13, 9761 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 14, 9762 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 15, 9741 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 16, 9765 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 9766 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 18, 9767 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 19, 9768 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 9769 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 21, 9770 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 22, 9771 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 23, 9772 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 24, 9773 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 25, 9861 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 9862 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 9863 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 28, 9866 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 29, 9867 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 30, 9868 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 31, 9869 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 32, 9870 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 33, 9871 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 34, 9872 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 35, 9873 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 36, 9879 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 37, 9880 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 38, 9881 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9490 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9491 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9492 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9493 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9494 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9495 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9496 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9497 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 9498 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 39, 9499 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 49, 9821 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 50, 9822 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 51, 9823 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 52, 9824 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 53, 9967 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 54, 9968 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 55, 9969 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 56, 9970 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 57, 10062 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 58, 10063 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 59, 10080 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 60, 10081 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 61, 10082 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 62, 10083 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 63, 10084 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 64, 10085 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 65, 10086 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 66, 10087 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 67, 10099 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 68, 10091 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 69, 10092 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 70, 10093 },
};

const CatchTable hugo_rival_catch_tbl[3024] = {
    { -60, -11, 2, 1, 1 },
    { -56, -13, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -52, -3, 2, 1, 1 },
    { -52, -4, 2, 1, 1 },
    { -61, 0, 2, 1, 1 },
    { -57, -3, 2, 1, 1 },
    { -58, -3, 2, 1, 1 },
    { -58, -2, 2, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -52, -3, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -60, -11, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -38, 0, 2, 1, 1 },
    { -69, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -55, 0, 2, 1, 1 },
    { -54, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -55, -2, 2, 1, 2 },
    { -25, -12, 2, 1, 2 },
    { -48, 1, 2, 1, 2 },
    { -32, 6, 2, 1, 2 },
    { -37, -4, 2, 1, 2 },
    { -52, -1, 2, 1, 2 },
    { -51, -3, 2, 1, 2 },
    { -56, -3, 2, 1, 2 },
    { -40, -3, 2, 1, 2 },
    { -45, 2, 2, 1, 2 },
    { -32, 6, 2, 1, 2 },
    { -48, 1, 2, 1, 2 },
    { -48, 1, 2, 1, 2 },
    { -55, -2, 2, 1, 2 },
    { -48, 1, 2, 1, 2 },
    { -48, 1, 2, 1, 2 },
    { -69, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -63, 0, 2, 1, 2 },
    { -54, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -45, -2, 2, 1, 3 },
    { -45, -6, 2, 1, 3 },
    { -41, -8, 2, 1, 3 },
    { -24, 14, 2, 1, 3 },
    { -37, 3, 2, 1, 3 },
    { -41, -5, 2, 1, 3 },
    { -43, 3, 2, 1, 3 },
    { -42, -5, 2, 1, 3 },
    { -36, 3, 2, 1, 3 },
    { -50, 3, 2, 1, 3 },
    { -24, 14, 2, 1, 3 },
    { -41, -8, 2, 1, 3 },
    { -41, -8, 2, 1, 3 },
    { -45, -2, 2, 1, 3 },
    { -41, -8, 2, 1, 3 },
    { -41, -8, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -54, -14, 2, 1, 3 },
    { -70, 0, 2, 1, 3 },
    { -59, 0, 2, 1, 3 },
    { -48, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -46, -2, 2, 1, 4 },
    { -44, 6, 2, 1, 4 },
    { -41, 44, 2, 1, 4 },
    { -43, 43, 2, 1, 4 },
    { -40, 156, 2, 1, 4 },
    { -33, 153, 2, 1, 4 },
    { -41, 24, 2, 1, 4 },
    { -28, 15, 2, 1, 4 },
    { -44, 58, 2, 1, 4 },
    { -48, 20, 2, 1, 4 },
    { -43, 43, 2, 1, 4 },
    { -41, 44, 2, 1, 4 },
    { -41, 44, 2, 1, 4 },
    { -46, -2, 2, 1, 4 },
    { -41, 44, 2, 1, 4 },
    { -41, 44, 2, 1, 4 },
    { -63, 39, 2, 1, 4 },
    { -37, 117, 2, 1, 4 },
    { -18, 114, 2, 1, 4 },
    { -48, 25, 2, 1, 4 },
    { -30, 108, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -52, 8, 2, 1, 5 },
    { -57, 130, 2, 1, 5 },
    { -41, 52, 2, 1, 5 },
    { -40, 51, 2, 1, 5 },
    { -40, 172, 2, 1, 5 },
    { -37, 170, 2, 1, 5 },
    { -33, 34, 2, 1, 5 },
    { -51, 27, 2, 1, 5 },
    { -40, 34, 2, 1, 5 },
    { -51, 31, 2, 1, 5 },
    { -40, 51, 2, 1, 5 },
    { -41, 52, 2, 1, 5 },
    { -41, 52, 2, 1, 5 },
    { -52, 8, 2, 1, 5 },
    { -41, 52, 2, 1, 5 },
    { -41, 52, 2, 1, 5 },
    { -29, 152, 2, 1, 5 },
    { -26, 113, 2, 1, 5 },
    { -15, 124, 2, 1, 5 },
    { -60, 45, 2, 1, 5 },
    { -42, 54, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -53, 44, 2, 1, 6 },
    { -47, 106, 2, 1, 6 },
    { -42, 108, 2, 1, 6 },
    { -35, 63, 2, 1, 6 },
    { -28, 52, 2, 1, 6 },
    { -43, 176, 2, 1, 6 },
    { -39, 44, 2, 1, 6 },
    { -38, 39, 2, 1, 6 },
    { -39, 35, 2, 1, 6 },
    { -46, 77, 2, 1, 6 },
    { -35, 63, 2, 1, 6 },
    { -42, 108, 2, 1, 6 },
    { -42, 108, 2, 1, 6 },
    { -53, 44, 2, 1, 6 },
    { -42, 108, 2, 1, 6 },
    { -42, 108, 2, 1, 6 },
    { -29, 66, 2, 1, 6 },
    { -28, 122, 2, 1, 6 },
    { -45, 54, 2, 1, 6 },
    { -51, 23, 2, 1, 6 },
    { -20, 88, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -34, 27, 2, 1, 7 },
    { -44, 78, 2, 1, 7 },
    { -27, 168, 2, 1, 7 },
    { -36, 158, 2, 1, 7 },
    { -31, 186, 2, 1, 7 },
    { -65, 179, 2, 1, 7 },
    { -56, 92, 2, 1, 7 },
    { -45, 38, 2, 1, 7 },
    { -39, 41, 2, 1, 7 },
    { -32, 89, 2, 1, 7 },
    { -36, 158, 2, 1, 7 },
    { -27, 168, 2, 1, 7 },
    { -27, 168, 2, 1, 7 },
    { -34, 27, 2, 1, 7 },
    { -27, 168, 2, 1, 7 },
    { -27, 168, 2, 1, 7 },
    { -37, 65, 2, 1, 7 },
    { -55, 194, 2, 1, 7 },
    { -38, 63, 2, 1, 7 },
    { -55, 32, 2, 1, 7 },
    { -26, 174, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 27, 206, 2, 1, 8 },
    { 18, 176, 1, 1, 8 },
    { 4, 146, 2, 1, 8 },
    { -11, 134, 2, 1, 8 },
    { 15, 77, 2, 1, 8 },
    { 5, 205, 2, 1, 8 },
    { 15, 116, 2, 1, 8 },
    { 3, 142, 2, 1, 8 },
    { 18, 151, 2, 1, 8 },
    { 32, 110, 2, 1, 8 },
    { -11, 134, 2, 1, 8 },
    { 4, 146, 2, 1, 8 },
    { 4, 146, 2, 1, 8 },
    { 27, 206, 2, 1, 8 },
    { 4, 146, 2, 1, 8 },
    { 4, 146, 2, 1, 8 },
    { -4, 187, 1, 1, 8 },
    { -2, 181, 2, 1, 8 },
    { 7, 84, 1, 1, 8 },
    { 5, 210, 2, 1, 8 },
    { -4, 196, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 7, 218, 2, 1, 9 },
    { 24, 206, 2, 1, 9 },
    { 4, 144, 2, 1, 9 },
    { 16, 190, 2, 1, 9 },
    { 15, 148, 2, 1, 9 },
    { 6, 216, 2, 1, 9 },
    { 11, 129, 2, 1, 9 },
    { 0, 146, 2, 1, 9 },
    { 12, 155, 2, 1, 9 },
    { 32, 121, 2, 1, 9 },
    { 16, 190, 2, 1, 9 },
    { 4, 144, 2, 1, 9 },
    { 4, 144, 2, 1, 9 },
    { 7, 218, 2, 1, 9 },
    { 4, 144, 2, 1, 9 },
    { 4, 144, 2, 1, 9 },
    { 3, 209, 2, 1, 9 },
    { 1, 187, 2, 1, 9 },
    { -11, 74, 2, 1, 9 },
    { 6, 204, 2, 1, 9 },
    { 8, 204, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 22, 226, 2, 1, 10 },
    { 35, 150, 2, 1, 10 },
    { 4, 148, 2, 1, 10 },
    { 15, 194, 2, 1, 10 },
    { 14, 152, 2, 1, 10 },
    { 17, 215, 2, 1, 10 },
    { 7, 133, 2, 1, 10 },
    { -3, 150, 2, 1, 10 },
    { 18, 120, 2, 1, 10 },
    { 44, 129, 2, 1, 10 },
    { 15, 194, 2, 1, 10 },
    { 4, 148, 2, 1, 10 },
    { 4, 148, 2, 1, 10 },
    { 22, 226, 2, 1, 10 },
    { 4, 148, 2, 1, 10 },
    { 4, 148, 2, 1, 10 },
    { 6, 213, 2, 1, 10 },
    { 6, 158, 2, 1, 10 },
    { -7, 104, 2, 1, 10 },
    { 17, 212, 2, 1, 10 },
    { 12, 204, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 22, 226, 2, 1, 11 },
    { 18, 198, 2, 1, 11 },
    { 4, 148, 2, 1, 11 },
    { 19, 150, 2, 1, 11 },
    { 14, 154, 2, 1, 11 },
    { 17, 216, 2, 1, 11 },
    { 7, 128, 2, 1, 11 },
    { -8, 152, 2, 1, 11 },
    { 18, 121, 2, 1, 11 },
    { 8, 129, 2, 1, 11 },
    { 19, 150, 2, 1, 11 },
    { 4, 148, 2, 1, 11 },
    { 4, 148, 2, 1, 11 },
    { 22, 226, 2, 1, 11 },
    { 4, 148, 2, 1, 11 },
    { 4, 148, 2, 1, 11 },
    { 6, 217, 2, 1, 11 },
    { 8, 162, 2, 1, 11 },
    { 21, 132, 2, 1, 11 },
    { 17, 216, 2, 1, 11 },
    { 24, 208, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 5, 43, 2, 1, 12 },
    { 25, 110, 2, 1, 12 },
    { 5, 156, 2, 1, 12 },
    { 18, 85, 2, 1, 12 },
    { 28, 158, 2, 1, 12 },
    { 12, 230, 2, 1, 12 },
    { 16, 128, 2, 1, 12 },
    { 0, 156, 2, 1, 12 },
    { 14, 180, 2, 1, 12 },
    { 10, 129, 2, 1, 12 },
    { 18, 85, 2, 1, 12 },
    { 5, 156, 2, 1, 12 },
    { 5, 156, 2, 1, 12 },
    { 5, 43, 2, 1, 12 },
    { 5, 156, 2, 1, 12 },
    { 5, 156, 2, 1, 12 },
    { 8, 161, 2, 1, 12 },
    { 14, 164, 2, 1, 12 },
    { 34, 133, 2, 1, 12 },
    { 12, 219, 2, 1, 12 },
    { 14, 206, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -23, 46, 2, 1, 13 },
    { 5, 202, 2, 1, 13 },
    { -3, 166, 2, 1, 13 },
    { -6, 111, 2, 1, 13 },
    { -4, 178, 2, 1, 13 },
    { 1, 144, 2, 1, 13 },
    { 1, 66, 2, 1, 13 },
    { 8, 214, 2, 1, 13 },
    { 8, 127, 2, 1, 13 },
    { -3, 122, 2, 1, 13 },
    { -6, 111, 2, 1, 13 },
    { -3, 166, 2, 1, 13 },
    { -3, 166, 2, 1, 13 },
    { -23, 46, 2, 1, 13 },
    { -3, 166, 2, 1, 13 },
    { -3, 166, 2, 1, 13 },
    { 3, 216, 2, 1, 13 },
    { -9, 162, 2, 1, 13 },
    { 39, 129, 2, 1, 13 },
    { 1, 213, 2, 1, 13 },
    { 6, 212, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -66, 61, 2, 1, 14 },
    { -61, 196, 2, 1, 14 },
    { -50, 180, 2, 1, 14 },
    { -33, 164, 2, 1, 14 },
    { -63, 176, 2, 1, 14 },
    { -61, 169, 2, 1, 14 },
    { -48, 41, 2, 1, 14 },
    { -49, 182, 2, 1, 14 },
    { -50, 150, 2, 1, 14 },
    { -69, 84, 2, 1, 14 },
    { -33, 164, 2, 1, 14 },
    { -50, 180, 2, 1, 14 },
    { -50, 180, 2, 1, 14 },
    { -66, 61, 2, 1, 14 },
    { -50, 180, 2, 1, 14 },
    { -50, 180, 2, 1, 14 },
    { -43, 177, 1, 1, 14 },
    { -54, 61, 2, 1, 14 },
    { -75, 47, 2, 1, 14 },
    { -61, 177, 2, 1, 14 },
    { -50, 186, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -91, 51, 2, 1, 15 },
    { -66, 168, 2, 1, 15 },
    { -80, 35, 2, 1, 15 },
    { -63, 132, 2, 1, 15 },
    { -68, 132, 2, 1, 15 },
    { -53, 136, 2, 1, 15 },
    { -60, 23, 2, 1, 15 },
    { -65, 160, 2, 1, 15 },
    { -53, 114, 2, 1, 15 },
    { -71, 36, 2, 1, 15 },
    { -63, 132, 2, 1, 15 },
    { -80, 35, 2, 1, 15 },
    { -80, 35, 2, 1, 15 },
    { -91, 51, 2, 1, 15 },
    { -80, 35, 2, 1, 15 },
    { -80, 35, 2, 1, 15 },
    { -55, 141, 2, 1, 15 },
    { -66, 55, 2, 1, 15 },
    { -108, 54, 2, 1, 15 },
    { -53, 142, 2, 1, 15 },
    { -74, 158, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, -9, 2, 0, 16 },
    { -57, -7, 2, 0, 16 },
    { -62, -7, 2, 0, 16 },
    { -95, -8, 2, 0, 16 },
    { -66, 100, 2, 0, 16 },
    { -67, -8, 2, 0, 16 },
    { -88, -43, 2, 0, 16 },
    { -75, -10, 2, 0, 16 },
    { -66, -1, 2, 0, 16 },
    { -67, -40, 2, 0, 16 },
    { -95, -8, 2, 0, 16 },
    { -62, -7, 2, 0, 16 },
    { -62, -7, 2, 0, 16 },
    { -64, -9, 2, 0, 16 },
    { -62, -7, 2, 0, 16 },
    { -62, -7, 2, 0, 16 },
    { -76, 0, 2, 0, 16 },
    { -78, -32, 2, 0, 16 },
    { -104, 0, 2, 0, 16 },
    { -67, -8, 2, 0, 16 },
    { -48, 0, 2, 0, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -42, -5, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -34, 0, 1, 1, 1 },
    { -16, -1, 1, 1, 1 },
    { -52, -2, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -62, -1, 1, 1, 1 },
    { -54, -3, 1, 1, 1 },
    { -34, 0, 1, 1, 1 },
    { -34, 0, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -43, 0, 1, 1, 1 },
    { -43, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, 1, 2, 1, 2 },
    { -35, 10, 2, 1, 2 },
    { -25, 9, 2, 1, 2 },
    { -13, 18, 2, 1, 2 },
    { -12, 4, 2, 1, 2 },
    { -41, 5, 2, 1, 2 },
    { -44, -5, 2, 1, 2 },
    { -29, 10, 2, 1, 2 },
    { -31, 22, 2, 1, 2 },
    { -31, 23, 2, 1, 2 },
    { -13, 18, 2, 1, 2 },
    { -25, 9, 2, 1, 2 },
    { -25, 9, 2, 1, 2 },
    { -16, 1, 2, 1, 2 },
    { -25, 9, 2, 1, 2 },
    { -25, 9, 2, 1, 2 },
    { -28, 17, 2, 1, 2 },
    { -40, -7, 2, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -30, 21, 2, 1, 2 },
    { -40, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -45, 1, 2, 1, 3 },
    { -56, 29, 2, 1, 3 },
    { -34, 22, 2, 1, 3 },
    { -19, 23, 2, 1, 3 },
    { -17, 3, 2, 1, 3 },
    { -41, 5, 2, 1, 3 },
    { -42, -5, 2, 1, 3 },
    { -30, 14, 2, 1, 3 },
    { -33, 22, 2, 1, 3 },
    { -32, 37, 2, 1, 3 },
    { -19, 23, 2, 1, 3 },
    { -34, 22, 2, 1, 3 },
    { -34, 22, 2, 1, 3 },
    { -45, 1, 2, 1, 3 },
    { -34, 22, 2, 1, 3 },
    { -34, 22, 2, 1, 3 },
    { -31, 14, 2, 1, 3 },
    { -42, -3, 2, 1, 3 },
    { -38, 0, 2, 1, 3 },
    { -79, 101, 2, 1, 3 },
    { -38, 4, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -46, 5, 2, 1, 4 },
    { -31, 6, 2, 1, 4 },
    { -56, 124, 2, 1, 4 },
    { -12, 23, 2, 1, 4 },
    { -28, 16, 2, 1, 4 },
    { -20, 12, 2, 1, 4 },
    { -39, 8, 2, 1, 4 },
    { -29, 20, 2, 1, 4 },
    { -30, 18, 2, 1, 4 },
    { -32, 37, 2, 1, 4 },
    { -12, 23, 2, 1, 4 },
    { -56, 124, 2, 1, 4 },
    { -56, 124, 2, 1, 4 },
    { -46, 5, 2, 1, 4 },
    { -56, 124, 2, 1, 4 },
    { -56, 124, 2, 1, 4 },
    { -39, 33, 2, 1, 4 },
    { -45, 45, 2, 1, 4 },
    { -39, 0, 2, 1, 4 },
    { -53, 158, 2, 1, 4 },
    { -34, 14, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -47, 132, 2, 1, 5 },
    { -69, 130, 2, 1, 5 },
    { -18, 24, 2, 1, 5 },
    { -12, 23, 2, 1, 5 },
    { -3, 13, 2, 1, 5 },
    { -19, 32, 2, 1, 5 },
    { -17, 17, 2, 1, 5 },
    { -31, 24, 2, 1, 5 },
    { -25, 24, 2, 1, 5 },
    { -37, 48, 2, 1, 5 },
    { -12, 23, 2, 1, 5 },
    { -18, 24, 2, 1, 5 },
    { -18, 24, 2, 1, 5 },
    { -47, 132, 2, 1, 5 },
    { -18, 24, 2, 1, 5 },
    { -18, 24, 2, 1, 5 },
    { -30, 31, 2, 1, 5 },
    { -56, 52, 2, 1, 5 },
    { -39, 0, 2, 1, 5 },
    { -55, 159, 2, 1, 5 },
    { -8, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, 29, 2, 1, 6 },
    { -24, 25, 2, 1, 6 },
    { -14, 63, 2, 1, 6 },
    { -10, 53, 2, 1, 6 },
    { -17, 47, 2, 1, 6 },
    { -31, 53, 2, 1, 6 },
    { -23, 30, 2, 1, 6 },
    { -23, 65, 2, 1, 6 },
    { -24, 63, 2, 1, 6 },
    { -32, 85, 2, 1, 6 },
    { -10, 53, 2, 1, 6 },
    { -14, 63, 2, 1, 6 },
    { -14, 63, 2, 1, 6 },
    { -40, 29, 2, 1, 6 },
    { -14, 63, 2, 1, 6 },
    { -14, 63, 2, 1, 6 },
    { -30, 69, 2, 1, 6 },
    { -52, 69, 2, 1, 6 },
    { -36, 48, 2, 1, 6 },
    { -23, 31, 2, 1, 6 },
    { -2, 48, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -45, 40, 2, 1, 7 },
    { -17, 30, 2, 1, 7 },
    { -49, 164, 2, 1, 7 },
    { -10, 59, 2, 1, 7 },
    { -2, 56, 2, 1, 7 },
    { -28, 54, 2, 1, 7 },
    { -18, 23, 2, 1, 7 },
    { -24, 63, 2, 1, 7 },
    { -34, 70, 2, 1, 7 },
    { -32, 85, 2, 1, 7 },
    { -10, 59, 2, 1, 7 },
    { -49, 164, 2, 1, 7 },
    { -49, 164, 2, 1, 7 },
    { -45, 40, 2, 1, 7 },
    { -49, 164, 2, 1, 7 },
    { -49, 164, 2, 1, 7 },
    { -28, 57, 2, 1, 7 },
    { -47, 65, 2, 1, 7 },
    { -38, 35, 2, 1, 7 },
    { -30, 54, 2, 1, 7 },
    { -8, 35, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -13, 40, 2, 1, 8 },
    { -31, 30, 2, 1, 8 },
    { -23, 64, 2, 1, 8 },
    { -14, 54, 2, 1, 8 },
    { -15, 56, 2, 1, 8 },
    { -17, 51, 2, 1, 8 },
    { -29, 49, 2, 1, 8 },
    { -24, 63, 2, 1, 8 },
    { -19, 61, 2, 1, 8 },
    { -47, 148, 2, 1, 8 },
    { -10, 59, 2, 1, 8 },
    { -23, 64, 2, 1, 8 },
    { -23, 64, 2, 1, 8 },
    { -13, 40, 2, 1, 8 },
    { -23, 64, 2, 1, 8 },
    { -23, 64, 2, 1, 8 },
    { -29, 59, 2, 1, 8 },
    { -47, 63, 2, 1, 8 },
    { -35, 35, 2, 1, 8 },
    { -20, 53, 2, 1, 8 },
    { -8, 36, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, 28, 2, 1, 9 },
    { -24, 44, 2, 1, 9 },
    { -9, 63, 2, 1, 9 },
    { -25, 154, 2, 1, 9 },
    { -17, 37, 2, 1, 9 },
    { -27, 53, 2, 1, 9 },
    { -42, 42, 2, 1, 9 },
    { -7, 53, 2, 1, 9 },
    { -21, 48, 2, 1, 9 },
    { -49, 152, 2, 1, 9 },
    { -25, 154, 2, 1, 9 },
    { -9, 63, 2, 1, 9 },
    { -9, 63, 2, 1, 9 },
    { -40, 28, 2, 1, 9 },
    { -9, 63, 2, 1, 9 },
    { -9, 63, 2, 1, 9 },
    { -25, 61, 2, 1, 9 },
    { -29, 57, 2, 1, 9 },
    { -30, 33, 2, 1, 9 },
    { -22, 40, 2, 1, 9 },
    { -1, 30, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -35, 41, 2, 1, 10 },
    { -66, 146, 2, 1, 10 },
    { -44, 152, 2, 1, 10 },
    { -15, 49, 2, 1, 10 },
    { -22, 41, 2, 1, 10 },
    { -49, 164, 2, 1, 10 },
    { -33, 33, 2, 1, 10 },
    { -21, 51, 2, 1, 10 },
    { -25, 42, 2, 1, 10 },
    { -32, 142, 2, 1, 10 },
    { -15, 49, 2, 1, 10 },
    { -44, 152, 2, 1, 10 },
    { -44, 152, 2, 1, 10 },
    { -35, 41, 2, 1, 10 },
    { -44, 152, 2, 1, 10 },
    { -44, 152, 2, 1, 10 },
    { -23, 69, 2, 1, 10 },
    { -13, 146, 2, 1, 10 },
    { -36, 41, 2, 1, 10 },
    { -33, 51, 2, 1, 10 },
    { -30, 42, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -101, 53, 2, 1, 11 },
    { -67, 43, 2, 1, 11 },
    { -65, 60, 2, 1, 11 },
    { -73, 62, 2, 1, 11 },
    { -89, 71, 2, 1, 11 },
    { -78, 63, 2, 1, 11 },
    { -73, 36, 2, 1, 11 },
    { -92, 84, 2, 1, 11 },
    { -78, 80, 2, 1, 11 },
    { -98, 74, 2, 1, 11 },
    { -73, 62, 2, 1, 11 },
    { -65, 60, 2, 1, 11 },
    { -65, 60, 2, 1, 11 },
    { -101, 53, 2, 1, 11 },
    { -65, 60, 2, 1, 11 },
    { -65, 60, 2, 1, 11 },
    { -59, 58, 2, 1, 11 },
    { -62, 68, 2, 1, 11 },
    { -90, 60, 2, 1, 11 },
    { -78, 63, 2, 1, 11 },
    { -44, 60, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -58, -10, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -36, -8, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -71, -10, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -48, -7, 1, 1, 1 },
    { -43, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -58, -10, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -61, -1, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -65, 0, 1, 1, 1 },
    { -66, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -32, -10, 1, 1, 2 },
    { -62, 0, 1, 1, 2 },
    { -33, 3, 1, 1, 2 },
    { -27, 3, 1, 1, 2 },
    { -35, -7, 1, 1, 2 },
    { -41, -2, 1, 1, 2 },
    { -35, -7, 1, 1, 2 },
    { -38, 3, 1, 1, 2 },
    { -25, -1, 1, 1, 2 },
    { -21, 9, 1, 1, 2 },
    { -27, 3, 1, 1, 2 },
    { -33, 3, 1, 1, 2 },
    { -33, 3, 1, 1, 2 },
    { -32, -10, 1, 1, 2 },
    { -33, 3, 1, 1, 2 },
    { -33, 3, 1, 1, 2 },
    { -39, -2, 1, 1, 2 },
    { -45, 0, 1, 1, 2 },
    { -52, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, -10, 1, 1, 3 },
    { 17, 1, 1, 1, 3 },
    { 6, 1, 1, 1, 3 },
    { -1, 9, 1, 1, 3 },
    { 9, -1, 1, 1, 3 },
    { 12, 4, 1, 1, 3 },
    { -5, -5, 1, 1, 3 },
    { 1, 10, 1, 1, 3 },
    { 5, 2, 1, 1, 3 },
    { 0, 14, 1, 1, 3 },
    { -1, 9, 1, 1, 3 },
    { 6, 1, 1, 1, 3 },
    { 6, 1, 1, 1, 3 },
    { 9, -10, 1, 1, 3 },
    { 6, 1, 1, 1, 3 },
    { 6, 1, 1, 1, 3 },
    { -4, -1, 1, 1, 3 },
    { 4, 3, 1, 1, 3 },
    { -1, 0, 1, 1, 3 },
    { -9, 16, 1, 1, 3 },
    { -8, 8, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 20, -12, 1, 1, 4 },
    { 3, 0, 1, 1, 4 },
    { -5, 5, 1, 1, 4 },
    { -3, 11, 1, 1, 4 },
    { 34, -4, 1, 1, 4 },
    { 13, 5, 1, 1, 4 },
    { 32, 0, 1, 1, 4 },
    { -10, 13, 1, 1, 4 },
    { -8, 7, 1, 1, 4 },
    { -6, 18, 1, 1, 4 },
    { -3, 11, 1, 1, 4 },
    { -5, 5, 1, 1, 4 },
    { -5, 5, 1, 1, 4 },
    { 20, -12, 1, 1, 4 },
    { -5, 5, 1, 1, 4 },
    { -5, 5, 1, 1, 4 },
    { 7, -1, 1, 1, 4 },
    { 9, 3, 1, 1, 4 },
    { -6, 0, 1, 1, 4 },
    { 8, 0, 1, 1, 4 },
    { 6, 6, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 18, -12, 1, 1, 5 },
    { 45, 0, 1, 1, 5 },
    { 21, -4, 1, 1, 5 },
    { 9, 6, 1, 1, 5 },
    { 34, -10, 1, 1, 5 },
    { 21, -3, 1, 1, 5 },
    { -13, -7, 1, 1, 5 },
    { 16, 3, 1, 1, 5 },
    { 4, 7, 1, 1, 5 },
    { 31, -4, 1, 1, 5 },
    { 9, 6, 1, 1, 5 },
    { 21, -4, 1, 1, 5 },
    { 21, -4, 1, 1, 5 },
    { 18, -12, 1, 1, 5 },
    { 21, -4, 1, 1, 5 },
    { 21, -4, 1, 1, 5 },
    { 23, -1, 1, 1, 5 },
    { 15, 5, 1, 1, 5 },
    { 30, 0, 1, 1, 5 },
    { 13, -4, 1, 1, 5 },
    { 20, 6, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 23, -10, 1, 1, 6 },
    { 24, -3, 1, 1, 6 },
    { 33, 0, 1, 1, 6 },
    { 18, 11, 1, 1, 6 },
    { 37, -11, 1, 1, 6 },
    { 35, 1, 1, 1, 6 },
    { 33, 6, 1, 1, 6 },
    { 24, 14, 1, 1, 6 },
    { 40, -6, 1, 1, 6 },
    { 15, 18, 1, 1, 6 },
    { 18, 11, 1, 1, 6 },
    { 33, 0, 1, 1, 6 },
    { 33, 0, 1, 1, 6 },
    { 23, -10, 1, 1, 6 },
    { 33, 0, 1, 1, 6 },
    { 33, 0, 1, 1, 6 },
    { 14, -1, 1, 1, 6 },
    { 19, 16, 1, 1, 6 },
    { 29, 0, 1, 1, 6 },
    { 27, 1, 1, 1, 6 },
    { 34, 2, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 3, 13, 2, 1, 7 },
    { 1, 14, 2, 1, 7 },
    { 19, 13, 2, 1, 7 },
    { 3, 33, 2, 1, 7 },
    { 3, 19, 2, 1, 7 },
    { 13, 22, 2, 1, 7 },
    { 25, 13, 2, 1, 7 },
    { 14, 20, 2, 1, 7 },
    { -9, 24, 2, 1, 7 },
    { 17, 31, 2, 1, 7 },
    { 3, 33, 2, 1, 7 },
    { 19, 13, 2, 1, 7 },
    { 19, 13, 2, 1, 7 },
    { 3, 13, 2, 1, 7 },
    { 19, 13, 2, 1, 7 },
    { 19, 13, 2, 1, 7 },
    { 5, 6, 2, 1, 7 },
    { 20, 27, 2, 1, 7 },
    { 15, 6, 2, 1, 7 },
    { 17, 26, 2, 1, 7 },
    { 24, 20, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 7, 19, 2, 1, 8 },
    { -14, 46, 2, 1, 8 },
    { -17, 60, 2, 1, 8 },
    { 0, 70, 2, 1, 8 },
    { -5, 55, 2, 1, 8 },
    { 12, 67, 2, 1, 8 },
    { -1, 45, 2, 1, 8 },
    { -2, 69, 2, 1, 8 },
    { 5, 51, 2, 1, 8 },
    { -10, 68, 2, 1, 8 },
    { 0, 70, 2, 1, 8 },
    { -17, 60, 2, 1, 8 },
    { -17, 60, 2, 1, 8 },
    { 7, 19, 2, 1, 8 },
    { -17, 60, 2, 1, 8 },
    { -17, 60, 2, 1, 8 },
    { -4, 49, 2, 1, 8 },
    { 6, 59, 2, 1, 8 },
    { 7, 33, 2, 1, 8 },
    { 10, 55, 2, 1, 8 },
    { -2, 56, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -13, 28, 2, 1, 9 },
    { 3, 24, 2, 1, 9 },
    { 14, 57, 2, 1, 9 },
    { 5, 57, 2, 1, 9 },
    { 10, 48, 2, 1, 9 },
    { -13, 49, 2, 1, 9 },
    { -25, 29, 2, 1, 9 },
    { -2, 51, 2, 1, 9 },
    { -10, 48, 2, 1, 9 },
    { 13, 62, 2, 1, 9 },
    { 5, 57, 2, 1, 9 },
    { 14, 57, 2, 1, 9 },
    { 14, 57, 2, 1, 9 },
    { -13, 28, 2, 1, 9 },
    { 14, 57, 2, 1, 9 },
    { 14, 57, 2, 1, 9 },
    { -9, 128, 2, 1, 9 },
    { -12, 61, 2, 1, 9 },
    { -32, 29, 2, 1, 9 },
    { -23, 182, 2, 1, 9 },
    { -2, 54, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, 25, 1, 1, 10 },
    { -12, 23, 1, 1, 10 },
    { -7, 53, 1, 1, 10 },
    { -4, 51, 1, 1, 10 },
    { -23, 28, 1, 1, 10 },
    { -20, 44, 1, 1, 10 },
    { 17, 35, 1, 1, 10 },
    { -11, 51, 1, 1, 10 },
    { 1, 44, 1, 1, 10 },
    { -14, 39, 1, 1, 10 },
    { -4, 51, 1, 1, 10 },
    { -7, 53, 1, 1, 10 },
    { -7, 53, 1, 1, 10 },
    { 1, 25, 1, 1, 10 },
    { -7, 53, 1, 1, 10 },
    { -7, 53, 1, 1, 10 },
    { -28, 50, 1, 1, 10 },
    { -7, 44, 1, 1, 10 },
    { -29, 31, 1, 1, 10 },
    { -9, 31, 1, 1, 10 },
    { -12, 46, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -13, 25, 1, 1, 11 },
    { 11, 32, 1, 1, 11 },
    { -5, 49, 1, 1, 11 },
    { -1, 53, 1, 1, 11 },
    { 25, 35, 1, 1, 11 },
    { 15, 42, 1, 1, 11 },
    { 2, 23, 1, 1, 11 },
    { 20, 40, 1, 1, 11 },
    { -10, 44, 1, 1, 11 },
    { -5, 58, 1, 1, 11 },
    { -1, 53, 1, 1, 11 },
    { -5, 49, 1, 1, 11 },
    { -5, 49, 1, 1, 11 },
    { -13, 25, 1, 1, 11 },
    { -5, 49, 1, 1, 11 },
    { -5, 49, 1, 1, 11 },
    { 13, 47, 1, 1, 11 },
    { 5, 44, 1, 1, 11 },
    { 11, 34, 1, 1, 11 },
    { 5, 31, 1, 1, 11 },
    { 4, 54, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 23, 2, 1, 12 },
    { 39, 35, 2, 1, 12 },
    { 23, 34, 2, 1, 12 },
    { 14, 28, 2, 1, 12 },
    { 21, 16, 2, 1, 12 },
    { 13, 36, 2, 1, 12 },
    { 46, 39, 2, 1, 12 },
    { 26, 33, 2, 1, 12 },
    { -5, 33, 2, 1, 12 },
    { 36, 34, 2, 1, 12 },
    { 14, 28, 2, 1, 12 },
    { 23, 34, 2, 1, 12 },
    { 23, 34, 2, 1, 12 },
    { 9, 23, 2, 1, 12 },
    { 23, 34, 2, 1, 12 },
    { 23, 34, 2, 1, 12 },
    { 9, 39, 2, 1, 12 },
    { 10, 46, 2, 1, 12 },
    { 9, 23, 2, 1, 12 },
    { 19, 22, 2, 1, 12 },
    { 18, 22, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 6, 14, 2, 1, 13 },
    { 4, 37, 2, 1, 13 },
    { -8, 48, 2, 1, 13 },
    { -3, 55, 2, 1, 13 },
    { -9, 40, 2, 1, 13 },
    { 6, 50, 2, 1, 13 },
    { 32, 29, 2, 1, 13 },
    { 6, 47, 2, 1, 13 },
    { 11, 44, 2, 1, 13 },
    { -11, 56, 2, 1, 13 },
    { -3, 55, 2, 1, 13 },
    { -8, 48, 2, 1, 13 },
    { -8, 48, 2, 1, 13 },
    { 6, 14, 2, 1, 13 },
    { -8, 48, 2, 1, 13 },
    { -8, 48, 2, 1, 13 },
    { 10, 131, 2, 1, 13 },
    { 0, 47, 2, 1, 13 },
    { 31, 36, 2, 1, 13 },
    { 17, 41, 2, 1, 13 },
    { 22, 30, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 2, 26, 2, 1, 14 },
    { -13, 33, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 0, 58, 2, 1, 14 },
    { 7, 32, 2, 1, 14 },
    { -20, 49, 2, 1, 14 },
    { -39, 23, 2, 1, 14 },
    { -11, 45, 2, 1, 14 },
    { 10, 46, 2, 1, 14 },
    { -27, 56, 2, 1, 14 },
    { 0, 58, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 2, 26, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 6, 38, 2, 1, 14 },
    { 0, 48, 2, 1, 14 },
    { -13, 31, 2, 1, 14 },
    { -3, 35, 2, 1, 14 },
    { -4, 34, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -39, 9, 2, 1, 15 },
    { -15, 38, 2, 1, 15 },
    { -41, 43, 2, 1, 15 },
    { -33, 38, 2, 1, 15 },
    { -27, 41, 2, 1, 15 },
    { -38, 42, 2, 1, 15 },
    { -24, 7, 2, 1, 15 },
    { -32, 45, 2, 1, 15 },
    { -34, 32, 2, 1, 15 },
    { -47, 44, 2, 1, 15 },
    { -33, 38, 2, 1, 15 },
    { -41, 43, 2, 1, 15 },
    { -41, 43, 2, 1, 15 },
    { -39, 9, 2, 1, 15 },
    { -41, 43, 2, 1, 15 },
    { -41, 43, 2, 1, 15 },
    { -25, 42, 2, 1, 15 },
    { -29, 50, 2, 1, 15 },
    { -57, 40, 2, 1, 15 },
    { -13, 38, 2, 1, 15 },
    { -24, 48, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -22, -11, 2, 1, 16 },
    { -16, 23, 2, 1, 16 },
    { -25, 22, 2, 1, 16 },
    { -8, 33, 2, 1, 16 },
    { -35, 32, 2, 1, 16 },
    { -8, 42, 2, 1, 16 },
    { -25, 24, 2, 1, 16 },
    { -31, 26, 2, 1, 16 },
    { -21, 21, 2, 1, 16 },
    { 0, 47, 2, 1, 16 },
    { -8, 33, 2, 1, 16 },
    { -25, 22, 2, 1, 16 },
    { -25, 22, 2, 1, 16 },
    { -22, -11, 2, 1, 16 },
    { -25, 22, 2, 1, 16 },
    { -25, 22, 2, 1, 16 },
    { -19, 40, 2, 1, 16 },
    { -13, 159, 2, 1, 16 },
    { -26, 38, 2, 1, 16 },
    { -31, 21, 2, 1, 16 },
    { -26, 22, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, 22, 2, 1, 17 },
    { -8, 39, 2, 1, 17 },
    { -32, 48, 2, 1, 17 },
    { -13, 61, 2, 1, 17 },
    { -17, 38, 2, 1, 17 },
    { -9, 134, 2, 1, 17 },
    { -1, 16, 2, 1, 17 },
    { 5, 50, 2, 1, 17 },
    { -4, 38, 2, 1, 17 },
    { -4, 44, 2, 1, 17 },
    { -13, 61, 2, 1, 17 },
    { -32, 48, 2, 1, 17 },
    { -32, 48, 2, 1, 17 },
    { 1, 22, 2, 1, 17 },
    { -32, 48, 2, 1, 17 },
    { -32, 48, 2, 1, 17 },
    { -2, 42, 2, 1, 17 },
    { 4, 168, 2, 1, 17 },
    { 25, 27, 2, 1, 17 },
    { -4, 64, 2, 1, 17 },
    { -2, 72, 2, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 19, 24, 2, 1, 18 },
    { 17, 51, 2, 1, 18 },
    { 9, 47, 2, 1, 18 },
    { 5, 62, 2, 1, 18 },
    { 2, 56, 2, 1, 18 },
    { 17, 168, 2, 1, 18 },
    { 30, 100, 2, 1, 18 },
    { 27, 58, 2, 1, 18 },
    { 19, 72, 2, 1, 18 },
    { 4, 61, 2, 1, 18 },
    { 5, 62, 2, 1, 18 },
    { 9, 47, 2, 1, 18 },
    { 9, 47, 2, 1, 18 },
    { 19, 24, 2, 1, 18 },
    { 9, 47, 2, 1, 18 },
    { 9, 47, 2, 1, 18 },
    { 15, 74, 2, 1, 18 },
    { 17, 166, 2, 1, 18 },
    { 40, 33, 2, 1, 18 },
    { 12, 69, 2, 1, 18 },
    { 10, 182, 2, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 33, 1, 2, 1, 19 },
    { 13, 47, 2, 1, 19 },
    { 20, 162, 2, 1, 19 },
    { 23, 152, 2, 1, 19 },
    { 5, 44, 2, 1, 19 },
    { 13, 166, 2, 1, 19 },
    { 13, 96, 2, 1, 19 },
    { 30, 116, 2, 1, 19 },
    { 13, 61, 2, 1, 19 },
    { 14, 43, 2, 1, 19 },
    { 23, 152, 2, 1, 19 },
    { 20, 162, 2, 1, 19 },
    { 20, 162, 2, 1, 19 },
    { 33, 1, 2, 1, 19 },
    { 20, 162, 2, 1, 19 },
    { 20, 162, 2, 1, 19 },
    { 19, 161, 2, 1, 19 },
    { 35, 158, 2, 1, 19 },
    { 15, 63, 2, 1, 19 },
    { 23, 140, 2, 1, 19 },
    { 14, 170, 2, 1, 19 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 32, 33, 1, 1, 20 },
    { 24, 168, 1, 1, 20 },
    { 25, 144, 1, 1, 20 },
    { 20, 138, 1, 1, 20 },
    { 27, 156, 1, 1, 20 },
    { 24, 146, 1, 1, 20 },
    { 22, 146, 1, 1, 20 },
    { 18, 154, 1, 1, 20 },
    { 6, 138, 1, 1, 20 },
    { 20, 160, 1, 1, 20 },
    { 20, 138, 1, 1, 20 },
    { 25, 144, 1, 1, 20 },
    { 25, 144, 1, 1, 20 },
    { 32, 33, 1, 1, 20 },
    { 25, 144, 1, 1, 20 },
    { 25, 144, 1, 1, 20 },
    { 41, 149, 1, 1, 20 },
    { 25, 68, 1, 1, 20 },
    { 12, 39, 1, 1, 20 },
    { 25, 171, 1, 1, 20 },
    { 18, 176, 1, 1, 20 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 21, 9, 1, 1, 21 },
    { 20, 138, 1, 1, 21 },
    { 35, 134, 1, 1, 21 },
    { 22, 120, 1, 1, 21 },
    { 33, 152, 1, 1, 21 },
    { 32, 124, 1, 1, 21 },
    { 49, 130, 1, 1, 21 },
    { 24, 124, 1, 1, 21 },
    { 15, 130, 1, 1, 21 },
    { 14, 110, 1, 1, 21 },
    { 22, 120, 1, 1, 21 },
    { 35, 134, 1, 1, 21 },
    { 35, 134, 1, 1, 21 },
    { 21, 9, 1, 1, 21 },
    { 35, 134, 1, 1, 21 },
    { 35, 134, 1, 1, 21 },
    { 45, 142, 1, 1, 21 },
    { 31, 40, 1, 1, 21 },
    { 39, 135, 1, 1, 21 },
    { 35, 144, 1, 1, 21 },
    { 34, 154, 1, 1, 21 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 18, 21, 1, 1, 22 },
    { 40, 35, 1, 1, 22 },
    { 24, 96, 1, 1, 22 },
    { 29, 98, 1, 1, 22 },
    { 26, 130, 1, 1, 22 },
    { 27, 20, 1, 1, 22 },
    { 34, -7, 1, 1, 22 },
    { 3, 88, 1, 1, 22 },
    { 13, 112, 1, 1, 22 },
    { 29, 94, 1, 1, 22 },
    { 29, 98, 1, 1, 22 },
    { 24, 96, 1, 1, 22 },
    { 24, 96, 1, 1, 22 },
    { 18, 21, 1, 1, 22 },
    { 24, 96, 1, 1, 22 },
    { 24, 96, 1, 1, 22 },
    { 34, 121, 1, 1, 22 },
    { 7, -3, 1, 1, 22 },
    { 4, 137, 1, 1, 22 },
    { 20, 123, 1, 1, 22 },
    { 44, 18, 1, 1, 22 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 30, 1, 1, 23 },
    { 25, 37, 1, 1, 23 },
    { 11, -12, 1, 1, 23 },
    { 24, -10, 1, 1, 23 },
    { 19, -36, 1, 1, 23 },
    { 17, 28, 1, 1, 23 },
    { 23, -8, 1, 1, 23 },
    { 8, 62, 1, 1, 23 },
    { 15, 80, 1, 1, 23 },
    { 12, -6, 1, 1, 23 },
    { 24, -10, 1, 1, 23 },
    { 11, -12, 1, 1, 23 },
    { 11, -12, 1, 1, 23 },
    { 9, 30, 1, 1, 23 },
    { 11, -12, 1, 1, 23 },
    { 11, -12, 1, 1, 23 },
    { -1, 20, 1, 1, 23 },
    { 4, 46, 1, 1, 23 },
    { 40, 35, 1, 1, 23 },
    { 20, -19, 1, 1, 23 },
    { 14, 84, 1, 1, 23 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -14, 31, 1, 1, 24 },
    { 13, 34, 1, 1, 24 },
    { 5, 24, 1, 1, 24 },
    { 14, -14, 1, 1, 24 },
    { 13, 27, 1, 1, 24 },
    { 5, 44, 1, 1, 24 },
    { 12, 6, 1, 1, 24 },
    { 16, -40, 1, 1, 24 },
    { -3, 30, 1, 1, 24 },
    { -5, -13, 1, 1, 24 },
    { 14, -14, 1, 1, 24 },
    { 5, 24, 1, 1, 24 },
    { 5, 24, 1, 1, 24 },
    { -14, 31, 1, 1, 24 },
    { 5, 24, 1, 1, 24 },
    { 5, 24, 1, 1, 24 },
    { 1, 12, 1, 1, 24 },
    { -9, 8, 1, 1, 24 },
    { 31, 36, 1, 1, 24 },
    { 7, -20, 1, 1, 24 },
    { -4, -22, 1, 1, 24 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, -39, 2, 1, 25 },
    { -12, -25, 2, 1, 25 },
    { -13, 28, 2, 1, 25 },
    { -5, -5, 2, 1, 25 },
    { -6, 30, 2, 1, 25 },
    { -8, 12, 2, 1, 25 },
    { 1, 5, 2, 1, 25 },
    { -14, 29, 2, 1, 25 },
    { -15, 18, 2, 1, 25 },
    { -15, -8, 2, 1, 25 },
    { -5, -5, 2, 1, 25 },
    { -13, 28, 2, 1, 25 },
    { -13, 28, 2, 1, 25 },
    { -16, -39, 2, 1, 25 },
    { -13, 28, 2, 1, 25 },
    { -13, 28, 2, 1, 25 },
    { -3, 41, 2, 1, 25 },
    { -26, 40, 2, 1, 25 },
    { 14, 34, 2, 1, 25 },
    { -2, -20, 2, 1, 25 },
    { -26, 44, 2, 1, 25 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -2, -26, 1, 1, 26 },
    { -5, 40, 2, 1, 26 },
    { -8, 29, 2, 1, 26 },
    { 6, 35, 2, 1, 26 },
    { -4, 36, 2, 1, 26 },
    { -4, 19, 2, 1, 26 },
    { -4, 6, 2, 1, 26 },
    { -12, 36, 2, 1, 26 },
    { -16, 39, 2, 1, 26 },
    { -14, -6, 2, 1, 26 },
    { 6, 35, 2, 1, 26 },
    { -8, 29, 2, 1, 26 },
    { -8, 29, 2, 1, 26 },
    { -2, -26, 1, 1, 26 },
    { -8, 29, 2, 1, 26 },
    { -8, 29, 2, 1, 26 },
    { -3, 40, 2, 1, 26 },
    { -37, 51, 2, 1, 26 },
    { -35, -1, 2, 1, 26 },
    { -10, -6, 2, 1, 26 },
    { -26, 44, 2, 1, 26 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -5, -28, 1, 1, 27 },
    { -6, 43, 1, 1, 27 },
    { -12, 34, 1, 1, 27 },
    { 3, 47, 1, 1, 27 },
    { 0, 42, 1, 1, 27 },
    { -13, 41, 1, 1, 27 },
    { -2, 35, 2, 1, 27 },
    { -12, 39, 2, 1, 27 },
    { -19, 43, 2, 1, 27 },
    { -17, -5, 2, 1, 27 },
    { 3, 47, 1, 1, 27 },
    { -12, 34, 1, 1, 27 },
    { -12, 34, 1, 1, 27 },
    { -5, -28, 1, 1, 27 },
    { -12, 34, 1, 1, 27 },
    { -12, 34, 1, 1, 27 },
    { -3, 54, 2, 1, 27 },
    { -25, 21, 2, 1, 27 },
    { -43, 25, 2, 1, 27 },
    { -2, -9, 2, 1, 27 },
    { -28, 58, 2, 1, 27 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, -6, 1, 1, 28 },
    { -7, -4, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { -8, -31, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 1, -6, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { 0, 0, 1, 1, 28 },
    { -3, -9, 1, 1, 28 },
    { -40, -9, 1, 1, 28 },
    { -10, -8, 1, 1, 28 },
    { -3, -9, 1, 1, 28 },
    { -4, -10, 1, 1, 28 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, -6, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 16, -3, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 1, -6, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { 0, 0, 1, 1, 29 },
    { -3, -4, 1, 1, 29 },
    { -25, -4, 1, 1, 29 },
    { -10, -2, 1, 1, 29 },
    { -3, -9, 1, 1, 29 },
    { -4, -16, 1, 1, 29 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, -3, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 1, -3, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { 0, 0, 1, 1, 30 },
    { -3, 0, 1, 1, 30 },
    { -25, 0, 1, 1, 30 },
    { -10, 0, 1, 1, 30 },
    { -3, -3, 1, 1, 30 },
    { -4, -4, 1, 1, 30 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, -1, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 1, -1, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { 0, 0, 1, 1, 31 },
    { -3, 0, 1, 1, 31 },
    { -25, 0, 1, 1, 31 },
    { -10, 0, 1, 1, 31 },
    { -3, 0, 1, 1, 31 },
    { -4, 0, 1, 1, 31 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 1, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { 0, 0, 1, 1, 32 },
    { -3, 0, 1, 1, 32 },
    { -25, 0, 1, 1, 32 },
    { -10, 0, 1, 1, 32 },
    { -3, 0, 1, 1, 32 },
    { -4, 0, 1, 1, 32 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { 0, 0, 1, 1, 33 },
    { -3, 0, 1, 1, 33 },
    { -25, 0, 1, 1, 33 },
    { -10, 0, 1, 1, 33 },
    { -3, 0, 1, 1, 33 },
    { -4, 0, 1, 1, 33 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 6, 2, 1, 1 },
    { -102, 5, 2, 1, 1 },
    { -90, 17, 2, 1, 1 },
    { -96, 12, 2, 1, 1 },
    { -63, 14, 2, 1, 1 },
    { -83, 28, 2, 1, 1 },
    { -122, -4, 2, 1, 1 },
    { -92, 15, 2, 1, 1 },
    { -76, 20, 2, 1, 1 },
    { -89, 29, 2, 1, 1 },
    { -96, 12, 2, 1, 1 },
    { -90, 17, 2, 1, 1 },
    { -90, 17, 2, 1, 1 },
    { -89, 6, 2, 1, 1 },
    { -90, 17, 2, 1, 1 },
    { -90, 17, 2, 1, 1 },
    { -83, 28, 2, 1, 1 },
    { -89, 18, 2, 1, 1 },
    { -107, 7, 2, 1, 1 },
    { -83, 28, 2, 1, 1 },
    { -94, 14, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -76, 9, 2, 1, 2 },
    { -92, 17, 2, 1, 2 },
    { -92, 24, 2, 1, 2 },
    { -56, 36, 2, 1, 2 },
    { -90, 4, 2, 1, 2 },
    { -71, 28, 2, 1, 2 },
    { -80, 2, 2, 1, 2 },
    { -95, 29, 2, 1, 2 },
    { -65, 44, 2, 1, 2 },
    { -84, 35, 2, 1, 2 },
    { -56, 36, 2, 1, 2 },
    { -92, 24, 2, 1, 2 },
    { -92, 24, 2, 1, 2 },
    { -76, 9, 2, 1, 2 },
    { -92, 24, 2, 1, 2 },
    { -92, 24, 2, 1, 2 },
    { -79, 21, 2, 1, 2 },
    { -97, 86, 2, 1, 2 },
    { -95, 20, 2, 1, 2 },
    { -80, 35, 2, 1, 2 },
    { -84, 20, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -59, 31, 2, 1, 3 },
    { -45, 98, 2, 1, 3 },
    { -41, 56, 2, 1, 3 },
    { -11, 59, 2, 1, 3 },
    { -41, 28, 2, 1, 3 },
    { -28, 33, 2, 1, 3 },
    { -39, 25, 2, 1, 3 },
    { -36, 47, 2, 1, 3 },
    { -35, 71, 2, 1, 3 },
    { -49, 64, 2, 1, 3 },
    { -11, 59, 2, 1, 3 },
    { -41, 56, 2, 1, 3 },
    { -41, 56, 2, 1, 3 },
    { -59, 31, 2, 1, 3 },
    { -41, 56, 2, 1, 3 },
    { -41, 56, 2, 1, 3 },
    { -53, 40, 2, 1, 3 },
    { -43, 101, 2, 1, 3 },
    { -71, 60, 2, 1, 3 },
    { -28, 33, 2, 1, 3 },
    { -36, 100, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -23, 53, 2, 1, 4 },
    { -14, 78, 2, 1, 4 },
    { -30, 76, 2, 1, 4 },
    { 3, 78, 2, 1, 4 },
    { -28, 44, 2, 1, 4 },
    { -25, 107, 2, 1, 4 },
    { -19, 46, 2, 1, 4 },
    { -29, 110, 2, 1, 4 },
    { -21, 113, 2, 1, 4 },
    { -37, 62, 2, 1, 4 },
    { 3, 78, 2, 1, 4 },
    { -30, 76, 2, 1, 4 },
    { -30, 76, 2, 1, 4 },
    { -23, 53, 2, 1, 4 },
    { -30, 76, 2, 1, 4 },
    { -30, 76, 2, 1, 4 },
    { -35, 60, 2, 1, 4 },
    { -33, 66, 2, 1, 4 },
    { -52, 77, 2, 1, 4 },
    { -19, 71, 2, 1, 4 },
    { -24, 64, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -8, 47, 2, 1, 5 },
    { 8, 83, 2, 1, 5 },
    { -2, 116, 2, 1, 5 },
    { 3, 120, 2, 1, 5 },
    { 7, 115, 2, 1, 5 },
    { -1, 122, 2, 1, 5 },
    { -2, 210, 2, 1, 5 },
    { -24, 104, 2, 1, 5 },
    { -4, 119, 2, 1, 5 },
    { -11, 105, 2, 1, 5 },
    { 3, 120, 2, 1, 5 },
    { -2, 116, 2, 1, 5 },
    { -2, 116, 2, 1, 5 },
    { -8, 47, 2, 1, 5 },
    { -2, 116, 2, 1, 5 },
    { -2, 116, 2, 1, 5 },
    { -22, 65, 2, 1, 5 },
    { -12, 75, 2, 1, 5 },
    { -37, 84, 2, 1, 5 },
    { -1, 109, 2, 1, 5 },
    { -8, 66, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -24, 117, 2, 1, 6 },
    { 3, 132, 2, 1, 6 },
    { -6, 75, 2, 1, 6 },
    { -4, 126, 2, 1, 6 },
    { 1, 122, 2, 1, 6 },
    { -2, 134, 2, 1, 6 },
    { -6, 160, 2, 1, 6 },
    { -22, 105, 2, 1, 6 },
    { 5, 125, 2, 1, 6 },
    { -11, 82, 2, 1, 6 },
    { -4, 126, 2, 1, 6 },
    { -6, 75, 2, 1, 6 },
    { -6, 75, 2, 1, 6 },
    { -24, 117, 2, 1, 6 },
    { -6, 75, 2, 1, 6 },
    { -6, 75, 2, 1, 6 },
    { -1, 68, 2, 1, 6 },
    { -7, 91, 2, 1, 6 },
    { -23, 119, 2, 1, 6 },
    { -2, 134, 2, 1, 6 },
    { -2, 74, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 24, 144, 2, 1, 7 },
    { 13, 151, 2, 1, 7 },
    { 5, 140, 2, 1, 7 },
    { 10, 156, 2, 1, 7 },
    { 13, 147, 2, 1, 7 },
    { 2, 149, 2, 1, 7 },
    { 8, 166, 2, 1, 7 },
    { 0, 148, 2, 1, 7 },
    { 15, 148, 2, 1, 7 },
    { 2, 138, 2, 1, 7 },
    { 10, 156, 2, 1, 7 },
    { 5, 140, 2, 1, 7 },
    { 5, 140, 2, 1, 7 },
    { 24, 144, 2, 1, 7 },
    { 5, 140, 2, 1, 7 },
    { 5, 140, 2, 1, 7 },
    { -3, 143, 2, 1, 7 },
    { 9, 171, 2, 1, 7 },
    { -8, 230, 2, 1, 7 },
    { 2, 149, 2, 1, 7 },
    { -14, 142, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -12, 152, 2, 1, 8 },
    { 11, 158, 2, 1, 8 },
    { 0, 163, 2, 1, 8 },
    { 8, 160, 2, 1, 8 },
    { 8, 160, 2, 1, 8 },
    { 0, 162, 2, 1, 8 },
    { 6, 182, 2, 1, 8 },
    { -7, 155, 2, 1, 8 },
    { 4, 159, 2, 1, 8 },
    { 8, 135, 2, 1, 8 },
    { 8, 160, 2, 1, 8 },
    { 0, 163, 2, 1, 8 },
    { 0, 163, 2, 1, 8 },
    { -12, 152, 2, 1, 8 },
    { 0, 163, 2, 1, 8 },
    { 0, 163, 2, 1, 8 },
    { -5, 150, 2, 1, 8 },
    { 1, 181, 2, 1, 8 },
    { -12, 214, 2, 1, 8 },
    { 0, 146, 2, 1, 8 },
    { 8, 158, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -15, 64, 1, 1, 9 },
    { 0, 15, 1, 1, 9 },
    { -9, 74, 1, 1, 9 },
    { 0, 73, 1, 1, 9 },
    { 1, 72, 1, 1, 9 },
    { -8, 44, 1, 1, 9 },
    { 4, 98, 1, 1, 9 },
    { -7, 58, 1, 1, 9 },
    { -1, 76, 1, 1, 9 },
    { -16, 26, 1, 1, 9 },
    { 0, 73, 1, 1, 9 },
    { -9, 74, 1, 1, 9 },
    { -9, 74, 1, 1, 9 },
    { -15, 64, 1, 1, 9 },
    { -9, 74, 1, 1, 9 },
    { -9, 74, 1, 1, 9 },
    { -23, 49, 1, 1, 9 },
    { -4, 103, 1, 1, 9 },
    { 5, 74, 1, 1, 9 },
    { 1, 19, 1, 1, 9 },
    { -6, 84, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -19, 75, 1, 1, 10 },
    { 5, 18, 1, 1, 10 },
    { -4, 79, 1, 1, 10 },
    { 0, 87, 1, 1, 10 },
    { 1, 82, 1, 1, 10 },
    { -9, 56, 1, 1, 10 },
    { -2, 112, 1, 1, 10 },
    { 0, 71, 1, 1, 10 },
    { -4, 105, 1, 1, 10 },
    { -6, 69, 1, 1, 10 },
    { 0, 87, 1, 1, 10 },
    { -4, 79, 1, 1, 10 },
    { -4, 79, 1, 1, 10 },
    { -19, 75, 1, 1, 10 },
    { -4, 79, 1, 1, 10 },
    { -4, 79, 1, 1, 10 },
    { -18, 84, 1, 1, 10 },
    { -1, 119, 1, 1, 10 },
    { 14, 93, 1, 1, 10 },
    { 3, 44, 1, 1, 10 },
    { 0, 100, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -15, 78, 1, 1, 11 },
    { 1, 81, 1, 1, 11 },
    { -2, 76, 1, 1, 11 },
    { 1, 95, 1, 1, 11 },
    { 5, 81, 1, 1, 11 },
    { -5, 90, 1, 1, 11 },
    { 1, 118, 1, 1, 11 },
    { -10, 84, 1, 1, 11 },
    { 1, 103, 1, 1, 11 },
    { -14, 40, 1, 1, 11 },
    { 1, 95, 1, 1, 11 },
    { -2, 76, 1, 1, 11 },
    { -2, 76, 1, 1, 11 },
    { -15, 78, 1, 1, 11 },
    { -2, 76, 1, 1, 11 },
    { -2, 76, 1, 1, 11 },
    { -20, 72, 1, 1, 11 },
    { 1, 110, 1, 1, 11 },
    { 20, 117, 1, 1, 11 },
    { 3, 28, 1, 1, 11 },
    { -6, 90, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -14, 72, 1, 1, 12 },
    { 2, 21, 1, 1, 12 },
    { -7, 83, 1, 1, 12 },
    { 2, 85, 1, 1, 12 },
    { 5, 83, 1, 1, 12 },
    { -9, 91, 1, 1, 12 },
    { -3, 102, 1, 1, 12 },
    { -8, 75, 1, 1, 12 },
    { 8, 95, 1, 1, 12 },
    { 8, 66, 1, 1, 12 },
    { 2, 85, 1, 1, 12 },
    { -7, 83, 1, 1, 12 },
    { -7, 83, 1, 1, 12 },
    { -14, 72, 1, 1, 12 },
    { -7, 83, 1, 1, 12 },
    { -7, 83, 1, 1, 12 },
    { -5, 93, 1, 1, 12 },
    { 1, 110, 1, 1, 12 },
    { 21, 120, 1, 1, 12 },
    { 4, 91, 1, 1, 12 },
    { -6, 84, 1, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 14, 23, 2, 1, 13 },
    { 7, 34, 2, 1, 13 },
    { 8, 75, 2, 1, 13 },
    { 15, 46, 2, 1, 13 },
    { 3, 23, 2, 1, 13 },
    { 14, 33, 2, 1, 13 },
    { 11, 30, 2, 1, 13 },
    { 2, 86, 2, 1, 13 },
    { 1, 94, 2, 1, 13 },
    { -1, 53, 2, 1, 13 },
    { 15, 46, 2, 1, 13 },
    { 8, 75, 2, 1, 13 },
    { 8, 75, 2, 1, 13 },
    { 14, 23, 2, 1, 13 },
    { 8, 75, 2, 1, 13 },
    { 8, 75, 2, 1, 13 },
    { -3, 87, 2, 1, 13 },
    { 8, 152, 2, 1, 13 },
    { 28, 118, 2, 1, 13 },
    { 15, 29, 2, 1, 13 },
    { 8, 42, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 6, 33, 2, 1, 14 },
    { 17, 39, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 20, 53, 2, 1, 14 },
    { 8, 30, 2, 1, 14 },
    { 18, 39, 2, 1, 14 },
    { 13, 29, 2, 1, 14 },
    { 31, 31, 2, 1, 14 },
    { 14, 95, 2, 1, 14 },
    { 6, 87, 2, 1, 14 },
    { 20, 53, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 6, 33, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 9, 46, 2, 1, 14 },
    { 1, 95, 2, 1, 14 },
    { 1, 187, 2, 1, 14 },
    { 8, 148, 2, 1, 14 },
    { 21, 28, 2, 1, 14 },
    { 16, 44, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 18, 23, 2, 1, 15 },
    { 6, 33, 2, 1, 15 },
    { 8, 45, 2, 1, 15 },
    { 13, 43, 2, 1, 15 },
    { 1, 23, 2, 1, 15 },
    { 9, 34, 2, 1, 15 },
    { 13, 118, 2, 1, 15 },
    { 11, 85, 2, 1, 15 },
    { 14, 80, 2, 1, 15 },
    { -2, 39, 2, 1, 15 },
    { 13, 43, 2, 1, 15 },
    { 8, 45, 2, 1, 15 },
    { 8, 45, 2, 1, 15 },
    { 18, 23, 2, 1, 15 },
    { 8, 45, 2, 1, 15 },
    { 8, 45, 2, 1, 15 },
    { -3, 87, 2, 1, 15 },
    { 0, 103, 2, 1, 15 },
    { 4, 143, 2, 1, 15 },
    { 24, 28, 2, 1, 15 },
    { -4, 40, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 30, 2, 1, 16 },
    { -10, 92, 2, 1, 16 },
    { -1, 49, 2, 1, 16 },
    { 9, 49, 2, 1, 16 },
    { 3, 31, 2, 1, 16 },
    { 19, 35, 2, 1, 16 },
    { 7, 118, 2, 1, 16 },
    { 4, 88, 2, 1, 16 },
    { 10, 81, 2, 1, 16 },
    { 2, 42, 2, 1, 16 },
    { 9, 49, 2, 1, 16 },
    { -1, 49, 2, 1, 16 },
    { -1, 49, 2, 1, 16 },
    { 9, 30, 2, 1, 16 },
    { -1, 49, 2, 1, 16 },
    { -1, 49, 2, 1, 16 },
    { -2, 100, 2, 1, 16 },
    { -3, 166, 2, 1, 16 },
    { -31, 57, 2, 1, 16 },
    { 18, 25, 2, 1, 16 },
    { 20, 40, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -96, 70, 2, 1, 17 },
    { -112, 64, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 72, 2, 1, 17 },
    { -128, 45, 2, 1, 17 },
    { -112, 48, 2, 1, 17 },
    { -112, 49, 2, 1, 17 },
    { -80, 64, 2, 1, 17 },
    { -112, 72, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 72, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 70, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 64, 2, 1, 17 },
    { -96, 84, 2, 1, 17 },
    { -98, 95, 2, 1, 17 },
    { -128, 87, 2, 1, 17 },
    { -112, 48, 2, 1, 17 },
    { -112, 70, 2, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -12, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -21, 0, 1, 1, 1 },
    { -37, 0, 1, 1, 1 },
    { -25, 0, 1, 1, 1 },
    { -56, 0, 1, 1, 1 },
    { -33, 0, 1, 1, 1 },
    { -33, 0, 1, 1, 1 },
    { -33, 0, 1, 1, 1 },
    { -21, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -15, 0, 1, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -25, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 24, 0, 1, 1, 2 },
    { 74, 0, 1, 1, 2 },
    { 72, 0, 1, 1, 2 },
    { 40, 0, 1, 1, 2 },
    { 19, 0, 1, 1, 2 },
    { 19, -4, 1, 1, 2 },
    { 21, 0, 1, 1, 2 },
    { 16, 0, 1, 1, 2 },
    { 38, 0, 1, 1, 2 },
    { 38, 0, 1, 1, 2 },
    { 40, 0, 1, 1, 2 },
    { 72, 0, 1, 1, 2 },
    { 72, 0, 1, 1, 2 },
    { 24, 0, 1, 1, 2 },
    { 72, 0, 1, 1, 2 },
    { 72, 0, 1, 1, 2 },
    { 42, 0, 1, 1, 2 },
    { 28, 0, 1, 1, 2 },
    { 21, 0, 1, 1, 2 },
    { 19, -4, 1, 1, 2 },
    { 4, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 72, 0, 1, 1, 3 },
    { 93, 0, 1, 1, 3 },
    { 61, 0, 1, 1, 3 },
    { 88, 0, 1, 1, 3 },
    { 76, 0, 1, 1, 3 },
    { 70, 0, 1, 1, 3 },
    { 66, -4, 1, 1, 3 },
    { 84, 0, 1, 1, 3 },
    { 97, 0, 1, 1, 3 },
    { 77, 0, 1, 1, 3 },
    { 88, 0, 1, 1, 3 },
    { 61, 0, 1, 1, 3 },
    { 61, 0, 1, 1, 3 },
    { 72, 0, 1, 1, 3 },
    { 61, 0, 1, 1, 3 },
    { 61, 0, 1, 1, 3 },
    { 81, 0, 1, 1, 3 },
    { 72, 0, 1, 1, 3 },
    { 66, 0, 1, 1, 3 },
    { 70, 0, 1, 1, 3 },
    { 72, 8, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 105, 0, 1, 1, 4 },
    { 70, 0, 1, 1, 4 },
    { 89, 7, 1, 1, 4 },
    { 87, 2, 1, 1, 4 },
    { 83, 2, 1, 1, 4 },
    { 89, 11, 1, 1, 4 },
    { 71, 2, 1, 1, 4 },
    { 88, 4, 1, 1, 4 },
    { 99, 16, 1, 1, 4 },
    { 73, 7, 1, 1, 4 },
    { 87, 2, 1, 1, 4 },
    { 89, 7, 1, 1, 4 },
    { 89, 7, 1, 1, 4 },
    { 105, 0, 1, 1, 4 },
    { 89, 7, 1, 1, 4 },
    { 89, 7, 1, 1, 4 },
    { 74, 6, 1, 1, 4 },
    { 81, 19, 1, 1, 4 },
    { 74, 0, 1, 1, 4 },
    { 89, 11, 1, 1, 4 },
    { 72, 18, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 48, 1, 1, 1, 5 },
    { 44, 14, 1, 1, 5 },
    { 75, 30, 1, 1, 5 },
    { 95, 28, 1, 1, 5 },
    { 64, 11, 1, 1, 5 },
    { 80, 18, 1, 1, 5 },
    { 45, 13, 1, 1, 5 },
    { 72, 9, 1, 1, 5 },
    { 85, 43, 1, 1, 5 },
    { 62, 39, 1, 1, 5 },
    { 95, 28, 1, 1, 5 },
    { 75, 30, 1, 1, 5 },
    { 75, 30, 1, 1, 5 },
    { 48, 1, 1, 1, 5 },
    { 75, 30, 1, 1, 5 },
    { 75, 30, 1, 1, 5 },
    { 71, 15, 1, 1, 5 },
    { 65, 19, 1, 1, 5 },
    { 51, 27, 1, 1, 5 },
    { 80, 18, 1, 1, 5 },
    { 54, 26, 1, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -32, 30, 1, 1, 6 },
    { -38, 12, 1, 1, 6 },
    { -40, 42, 1, 1, 6 },
    { -28, 49, 1, 1, 6 },
    { -37, 19, 1, 1, 6 },
    { -18, 30, 1, 1, 6 },
    { -56, 15, 1, 1, 6 },
    { -40, 55, 1, 1, 6 },
    { -19, 65, 1, 1, 6 },
    { -42, 55, 1, 1, 6 },
    { -28, 49, 1, 1, 6 },
    { -40, 42, 1, 1, 6 },
    { -40, 42, 1, 1, 6 },
    { -32, 30, 1, 1, 6 },
    { -40, 42, 1, 1, 6 },
    { -40, 42, 1, 1, 6 },
    { -29, 45, 1, 1, 6 },
    { -51, 57, 1, 1, 6 },
    { -59, 38, 1, 1, 6 },
    { -18, 30, 1, 1, 6 },
    { -34, 34, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -101, 29, 1, 1, 7 },
    { -111, 10, 1, 1, 7 },
    { -88, 43, 1, 1, 7 },
    { -78, 46, 1, 1, 7 },
    { -83, 35, 1, 1, 7 },
    { -73, 40, 1, 1, 7 },
    { -116, 24, 1, 1, 7 },
    { -100, 53, 1, 1, 7 },
    { -94, 62, 1, 1, 7 },
    { -108, 55, 1, 1, 7 },
    { -78, 46, 1, 1, 7 },
    { -88, 43, 1, 1, 7 },
    { -88, 43, 1, 1, 7 },
    { -101, 29, 1, 1, 7 },
    { -88, 43, 1, 1, 7 },
    { -88, 43, 1, 1, 7 },
    { -87, 47, 1, 1, 7 },
    { -110, 58, 1, 1, 7 },
    { -108, 45, 1, 1, 7 },
    { -73, 40, 1, 1, 7 },
    { -104, 38, 1, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -59, 31, 2, 1, 33 },
    { -45, 98, 2, 1, 33 },
    { -41, 56, 2, 1, 33 },
    { -11, 59, 2, 1, 33 },
    { -41, 28, 2, 1, 33 },
    { -28, 33, 2, 1, 33 },
    { -39, 25, 2, 1, 33 },
    { -36, 47, 2, 1, 33 },
    { -35, 71, 2, 1, 33 },
    { -49, 64, 2, 1, 33 },
    { -11, 59, 2, 1, 33 },
    { -41, 56, 2, 1, 33 },
    { -41, 56, 2, 1, 33 },
    { -59, 31, 2, 1, 33 },
    { -41, 56, 2, 1, 33 },
    { -41, 56, 2, 1, 33 },
    { -53, 40, 2, 1, 33 },
    { -43, 101, 2, 1, 33 },
    { -71, 60, 2, 1, 33 },
    { -28, 33, 2, 1, 33 },
    { -36, 100, 2, 1, 33 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -23, 53, 2, 1, 34 },
    { -14, 78, 2, 1, 34 },
    { -30, 76, 2, 1, 34 },
    { 3, 78, 2, 1, 34 },
    { -28, 44, 2, 1, 34 },
    { -25, 107, 2, 1, 34 },
    { -19, 46, 2, 1, 34 },
    { -29, 110, 2, 1, 34 },
    { -21, 113, 2, 1, 34 },
    { -37, 62, 2, 1, 34 },
    { 3, 78, 2, 1, 34 },
    { -30, 76, 2, 1, 34 },
    { -30, 76, 2, 1, 34 },
    { -23, 53, 2, 1, 34 },
    { -30, 76, 2, 1, 34 },
    { -30, 76, 2, 1, 34 },
    { -35, 60, 2, 1, 34 },
    { -33, 66, 2, 1, 34 },
    { -52, 77, 2, 1, 34 },
    { -19, 71, 2, 1, 34 },
    { -24, 64, 2, 1, 34 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -8, 47, 2, 1, 35 },
    { 8, 83, 2, 1, 35 },
    { -2, 116, 2, 1, 35 },
    { 3, 120, 2, 1, 35 },
    { 7, 115, 2, 1, 35 },
    { -1, 122, 2, 1, 35 },
    { -2, 214, 2, 1, 35 },
    { -24, 104, 2, 1, 35 },
    { -4, 119, 2, 1, 35 },
    { -11, 105, 2, 1, 35 },
    { 3, 120, 2, 1, 35 },
    { -2, 116, 2, 1, 35 },
    { -2, 116, 2, 1, 35 },
    { -8, 47, 2, 1, 35 },
    { -2, 116, 2, 1, 35 },
    { -2, 116, 2, 1, 35 },
    { -22, 65, 2, 1, 35 },
    { -12, 75, 2, 1, 35 },
    { -37, 84, 2, 1, 35 },
    { -1, 109, 2, 1, 35 },
    { -8, 66, 2, 1, 35 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -24, 117, 2, 1, 36 },
    { 3, 132, 2, 1, 36 },
    { -6, 75, 2, 1, 36 },
    { -4, 126, 2, 1, 36 },
    { 1, 122, 2, 1, 36 },
    { -2, 134, 2, 1, 36 },
    { -6, 166, 2, 1, 36 },
    { -22, 105, 2, 1, 36 },
    { 5, 125, 2, 1, 36 },
    { -11, 82, 2, 1, 36 },
    { -4, 126, 2, 1, 36 },
    { -6, 75, 2, 1, 36 },
    { -6, 75, 2, 1, 36 },
    { -24, 117, 2, 1, 36 },
    { -6, 75, 2, 1, 36 },
    { -6, 75, 2, 1, 36 },
    { -1, 68, 2, 1, 36 },
    { -7, 91, 2, 1, 36 },
    { -23, 119, 2, 1, 36 },
    { -2, 134, 2, 1, 36 },
    { -2, 74, 2, 1, 36 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 24, 144, 2, 1, 37 },
    { 13, 151, 2, 1, 37 },
    { 5, 140, 2, 1, 37 },
    { 10, 156, 2, 1, 37 },
    { 13, 147, 2, 1, 37 },
    { 2, 149, 2, 1, 37 },
    { 8, 164, 2, 1, 37 },
    { 0, 148, 2, 1, 37 },
    { 15, 148, 2, 1, 37 },
    { 2, 138, 2, 1, 37 },
    { 10, 156, 2, 1, 37 },
    { 5, 140, 2, 1, 37 },
    { 5, 140, 2, 1, 37 },
    { 24, 144, 2, 1, 37 },
    { 5, 140, 2, 1, 37 },
    { 5, 140, 2, 1, 37 },
    { -3, 143, 2, 1, 37 },
    { 9, 171, 2, 1, 37 },
    { -8, 230, 2, 1, 37 },
    { 2, 149, 2, 1, 37 },
    { -14, 142, 2, 1, 37 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -12, 152, 2, 1, 38 },
    { 11, 158, 2, 1, 38 },
    { 0, 163, 2, 1, 38 },
    { 8, 160, 2, 1, 38 },
    { 8, 160, 2, 1, 38 },
    { 0, 162, 2, 1, 38 },
    { 6, 184, 2, 1, 38 },
    { -7, 155, 2, 1, 38 },
    { 4, 159, 2, 1, 38 },
    { 8, 135, 2, 1, 38 },
    { 8, 160, 2, 1, 38 },
    { 0, 163, 2, 1, 38 },
    { 0, 163, 2, 1, 38 },
    { -12, 152, 2, 1, 38 },
    { 0, 163, 2, 1, 38 },
    { 0, 163, 2, 1, 38 },
    { -5, 150, 2, 1, 38 },
    { 1, 181, 2, 1, 38 },
    { -12, 214, 2, 1, 38 },
    { 0, 146, 2, 1, 38 },
    { 8, 158, 2, 1, 38 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -15, 64, 1, 1, 39 },
    { 0, 15, 1, 1, 39 },
    { -9, 74, 1, 1, 39 },
    { 0, 73, 1, 1, 39 },
    { 1, 72, 1, 1, 39 },
    { -8, 44, 1, 1, 39 },
    { 4, 102, 1, 1, 39 },
    { -7, 58, 1, 1, 39 },
    { -1, 64, 1, 1, 39 },
    { -16, 26, 1, 1, 39 },
    { 0, 73, 1, 1, 39 },
    { -9, 74, 1, 1, 39 },
    { -9, 74, 1, 1, 39 },
    { -15, 64, 1, 1, 39 },
    { -9, 74, 1, 1, 39 },
    { -9, 74, 1, 1, 39 },
    { -23, 49, 1, 1, 39 },
    { -4, 103, 1, 1, 39 },
    { 5, 74, 1, 1, 39 },
    { 1, 19, 1, 1, 39 },
    { -6, 84, 1, 1, 39 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -19, 75, 1, 1, 40 },
    { 5, 18, 1, 1, 40 },
    { -4, 79, 1, 1, 40 },
    { 0, 87, 1, 1, 40 },
    { 1, 82, 1, 1, 40 },
    { -9, 56, 1, 1, 40 },
    { -2, 112, 1, 1, 40 },
    { -11, 79, 1, 1, 40 },
    { -4, 73, 1, 1, 40 },
    { -6, 69, 1, 1, 40 },
    { 0, 87, 1, 1, 40 },
    { -4, 79, 1, 1, 40 },
    { -4, 79, 1, 1, 40 },
    { -19, 75, 1, 1, 40 },
    { -4, 79, 1, 1, 40 },
    { -4, 79, 1, 1, 40 },
    { -18, 84, 1, 1, 40 },
    { -1, 119, 1, 1, 40 },
    { 14, 93, 1, 1, 40 },
    { 3, 44, 1, 1, 40 },
    { 0, 100, 1, 1, 40 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -15, 78, 1, 1, 41 },
    { 1, 81, 1, 1, 41 },
    { -2, 76, 1, 1, 41 },
    { 1, 95, 1, 1, 41 },
    { 5, 81, 1, 1, 41 },
    { -5, 90, 1, 1, 41 },
    { 1, 102, 1, 1, 41 },
    { -10, 84, 1, 1, 41 },
    { -2, 84, 1, 1, 41 },
    { -14, 40, 1, 1, 41 },
    { 1, 95, 1, 1, 41 },
    { -2, 76, 1, 1, 41 },
    { -2, 76, 1, 1, 41 },
    { -15, 78, 1, 1, 41 },
    { -2, 76, 1, 1, 41 },
    { -2, 76, 1, 1, 41 },
    { -20, 72, 1, 1, 41 },
    { 1, 110, 1, 1, 41 },
    { 20, 117, 1, 1, 41 },
    { 3, 28, 1, 1, 41 },
    { -6, 90, 1, 1, 41 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -14, 72, 1, 1, 42 },
    { 2, 21, 1, 1, 42 },
    { -7, 83, 1, 1, 42 },
    { 2, 85, 1, 1, 42 },
    { 5, 83, 1, 1, 42 },
    { -9, 91, 1, 1, 42 },
    { -3, 104, 1, 1, 42 },
    { -8, 75, 1, 1, 42 },
    { 1, 87, 1, 1, 42 },
    { 8, 66, 1, 1, 42 },
    { 2, 85, 1, 1, 42 },
    { -7, 83, 1, 1, 42 },
    { -7, 83, 1, 1, 42 },
    { -14, 72, 1, 1, 42 },
    { -7, 83, 1, 1, 42 },
    { -7, 83, 1, 1, 42 },
    { -5, 93, 1, 1, 42 },
    { 1, 110, 1, 1, 42 },
    { 21, 120, 1, 1, 42 },
    { 4, 91, 1, 1, 42 },
    { -6, 84, 1, 1, 42 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 14, 23, 2, 1, 43 },
    { 7, 34, 2, 1, 43 },
    { 8, 75, 2, 1, 43 },
    { 15, 46, 2, 1, 43 },
    { 3, 23, 2, 1, 43 },
    { 14, 33, 2, 1, 43 },
    { 11, 30, 2, 1, 43 },
    { 2, 86, 2, 1, 43 },
    { 12, 87, 2, 1, 43 },
    { -1, 53, 2, 1, 43 },
    { 15, 46, 2, 1, 43 },
    { 8, 75, 2, 1, 43 },
    { 8, 75, 2, 1, 43 },
    { 14, 23, 2, 1, 43 },
    { 8, 75, 2, 1, 43 },
    { 8, 75, 2, 1, 43 },
    { -3, 87, 2, 1, 43 },
    { 8, 152, 2, 1, 43 },
    { 28, 118, 2, 1, 43 },
    { 15, 29, 2, 1, 43 },
    { 8, 42, 2, 1, 43 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 6, 33, 2, 1, 44 },
    { 17, 39, 2, 1, 44 },
    { 9, 46, 2, 1, 44 },
    { 20, 53, 2, 1, 44 },
    { 8, 30, 2, 1, 44 },
    { 18, 39, 2, 1, 44 },
    { 13, 29, 2, 1, 44 },
    { 31, 31, 2, 1, 44 },
    { 11, 90, 2, 1, 44 },
    { 6, 87, 2, 1, 44 },
    { 20, 53, 2, 1, 44 },
    { 9, 46, 2, 1, 44 },
    { 9, 46, 2, 1, 44 },
    { 6, 33, 2, 1, 44 },
    { 9, 46, 2, 1, 44 },
    { 9, 46, 2, 1, 44 },
    { 1, 95, 2, 1, 44 },
    { 1, 187, 2, 1, 44 },
    { 8, 148, 2, 1, 44 },
    { 21, 28, 2, 1, 44 },
    { 16, 44, 2, 1, 44 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 18, 23, 2, 1, 45 },
    { 6, 33, 2, 1, 45 },
    { 8, 45, 2, 1, 45 },
    { 13, 43, 2, 1, 45 },
    { 1, 23, 2, 1, 45 },
    { 9, 34, 2, 1, 45 },
    { 13, 116, 2, 1, 45 },
    { 11, 85, 2, 1, 45 },
    { 14, 80, 2, 1, 45 },
    { -2, 39, 2, 1, 45 },
    { 13, 43, 2, 1, 45 },
    { 8, 45, 2, 1, 45 },
    { 8, 45, 2, 1, 45 },
    { 18, 23, 2, 1, 45 },
    { 8, 45, 2, 1, 45 },
    { 8, 45, 2, 1, 45 },
    { -3, 87, 2, 1, 45 },
    { 0, 103, 2, 1, 45 },
    { 4, 143, 2, 1, 45 },
    { 24, 28, 2, 1, 45 },
    { -4, 40, 2, 1, 45 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 30, 2, 1, 46 },
    { -10, 92, 2, 1, 46 },
    { -1, 49, 2, 1, 46 },
    { 9, 49, 2, 1, 46 },
    { 3, 31, 2, 1, 46 },
    { 19, 35, 2, 1, 46 },
    { 7, 71, 2, 1, 46 },
    { 4, 88, 2, 1, 46 },
    { 5, 86, 2, 1, 46 },
    { 2, 42, 2, 1, 46 },
    { 9, 49, 2, 1, 46 },
    { -1, 49, 2, 1, 46 },
    { -1, 49, 2, 1, 46 },
    { 9, 30, 2, 1, 46 },
    { -1, 49, 2, 1, 46 },
    { -1, 49, 2, 1, 46 },
    { -2, 100, 2, 1, 46 },
    { -3, 166, 2, 1, 46 },
    { -31, 57, 2, 1, 46 },
    { 18, 25, 2, 1, 46 },
    { 20, 40, 2, 1, 46 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -28, 61, 2, 1, 47 },
    { -75, 152, 2, 1, 47 },
    { -31, 54, 2, 1, 47 },
    { -93, 106, 2, 1, 47 },
    { -35, 142, 2, 1, 47 },
    { -65, 100, 2, 1, 47 },
    { -57, 136, 2, 1, 47 },
    { -62, 32, 2, 1, 47 },
    { -47, 22, 2, 1, 47 },
    { -38, 118, 2, 1, 47 },
    { -93, 106, 2, 1, 47 },
    { -31, 54, 2, 1, 47 },
    { -31, 54, 2, 1, 47 },
    { -28, 61, 2, 1, 47 },
    { -31, 54, 2, 1, 47 },
    { -31, 54, 2, 1, 47 },
    { -72, 134, 2, 1, 47 },
    { -51, 128, 2, 1, 47 },
    { -52, 161, 2, 1, 47 },
    { -65, 149, 2, 1, 47 },
    { -68, 98, 2, 1, 47 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -81, -9, 2, 1, 48 },
    { -31, 3, 2, 1, 48 },
    { -45, 13, 2, 1, 48 },
    { -59, 6, 2, 1, 48 },
    { -69, -6, 2, 1, 48 },
    { -63, 122, 2, 1, 48 },
    { -38, -1, 2, 1, 48 },
    { -51, -1, 2, 1, 48 },
    { -57, 4, 2, 1, 48 },
    { -53, 9, 2, 1, 48 },
    { -59, 6, 2, 1, 48 },
    { -45, 13, 2, 1, 48 },
    { -45, 13, 2, 1, 48 },
    { -81, -9, 2, 1, 48 },
    { -45, 13, 2, 1, 48 },
    { -45, 13, 2, 1, 48 },
    { -55, 13, 2, 1, 48 },
    { -63, 75, 2, 1, 48 },
    { -65, 87, 2, 1, 48 },
    { -74, 122, 2, 1, 48 },
    { -78, 4, 2, 1, 48 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 1, 1, 49 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -39, 9, 2, 1, 1 },
    { -15, 38, 2, 1, 1 },
    { -41, 43, 2, 1, 1 },
    { -33, 38, 2, 1, 1 },
    { -27, 41, 2, 1, 1 },
    { -38, 42, 2, 1, 1 },
    { -24, 7, 2, 1, 1 },
    { -32, 45, 2, 1, 1 },
    { -34, 32, 2, 1, 1 },
    { -47, 44, 2, 1, 1 },
    { -33, 38, 2, 1, 1 },
    { -41, 43, 2, 1, 1 },
    { -41, 43, 2, 1, 1 },
    { -39, 9, 2, 1, 1 },
    { -41, 43, 2, 1, 1 },
    { -41, 43, 2, 1, 1 },
    { -25, 42, 2, 1, 1 },
    { -29, 50, 2, 1, 1 },
    { -57, 40, 2, 1, 1 },
    { -13, 38, 2, 1, 1 },
    { -24, 48, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -22, -11, 2, 1, 2 },
    { -16, 23, 2, 1, 2 },
    { -25, 22, 2, 1, 2 },
    { -8, 33, 2, 1, 2 },
    { -35, 32, 2, 1, 2 },
    { -8, 42, 2, 1, 2 },
    { -25, 24, 2, 1, 2 },
    { -31, 26, 2, 1, 2 },
    { -21, 21, 2, 1, 2 },
    { 0, 47, 2, 1, 2 },
    { -8, 33, 2, 1, 2 },
    { -25, 22, 2, 1, 2 },
    { -25, 22, 2, 1, 2 },
    { -22, -11, 2, 1, 2 },
    { -25, 22, 2, 1, 2 },
    { -25, 22, 2, 1, 2 },
    { -19, 40, 2, 1, 2 },
    { -13, 159, 2, 1, 2 },
    { -26, 38, 2, 1, 2 },
    { -31, 21, 2, 1, 2 },
    { -20, 22, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 1, 22, 2, 1, 3 },
    { -8, 39, 2, 1, 3 },
    { -32, 48, 2, 1, 3 },
    { -13, 61, 2, 1, 3 },
    { -17, 38, 2, 1, 3 },
    { -9, 138, 2, 1, 3 },
    { -1, 16, 2, 1, 3 },
    { 5, 50, 2, 1, 3 },
    { -4, 38, 2, 1, 3 },
    { -4, 44, 2, 1, 3 },
    { -13, 61, 2, 1, 3 },
    { -32, 48, 2, 1, 3 },
    { -32, 48, 2, 1, 3 },
    { 1, 22, 2, 1, 3 },
    { -32, 48, 2, 1, 3 },
    { -32, 48, 2, 1, 3 },
    { -2, 42, 2, 1, 3 },
    { 4, 168, 2, 1, 3 },
    { 25, 27, 2, 1, 3 },
    { -4, 64, 2, 1, 3 },
    { -2, 72, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 19, 24, 2, 1, 4 },
    { 17, 51, 2, 1, 4 },
    { 9, 47, 2, 1, 4 },
    { 5, 62, 2, 1, 4 },
    { 2, 56, 2, 1, 4 },
    { 17, 174, 2, 1, 4 },
    { 30, 111, 2, 1, 4 },
    { 27, 58, 2, 1, 4 },
    { 19, 72, 2, 1, 4 },
    { 4, 61, 2, 1, 4 },
    { 5, 62, 2, 1, 4 },
    { 9, 47, 2, 1, 4 },
    { 9, 47, 2, 1, 4 },
    { 19, 24, 2, 1, 4 },
    { 9, 47, 2, 1, 4 },
    { 9, 47, 2, 1, 4 },
    { 15, 74, 2, 1, 4 },
    { 17, 166, 2, 1, 4 },
    { 40, 33, 2, 1, 4 },
    { 12, 69, 2, 1, 4 },
    { 10, 182, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 33, 1, 2, 1, 5 },
    { 13, 47, 2, 1, 5 },
    { 20, 162, 2, 1, 5 },
    { 23, 152, 2, 1, 5 },
    { 5, 44, 2, 1, 5 },
    { 13, 172, 2, 1, 5 },
    { 13, 96, 2, 1, 5 },
    { 30, 116, 2, 1, 5 },
    { 13, 61, 2, 1, 5 },
    { 14, 43, 2, 1, 5 },
    { 23, 152, 2, 1, 5 },
    { 20, 162, 2, 1, 5 },
    { 20, 162, 2, 1, 5 },
    { 33, 1, 2, 1, 5 },
    { 20, 162, 2, 1, 5 },
    { 20, 162, 2, 1, 5 },
    { 19, 161, 2, 1, 5 },
    { 35, 158, 2, 1, 5 },
    { 15, 63, 2, 1, 5 },
    { 23, 140, 2, 1, 5 },
    { 18, 164, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 32, 33, 1, 1, 6 },
    { 24, 168, 1, 1, 6 },
    { 25, 144, 1, 1, 6 },
    { 20, 138, 1, 1, 6 },
    { 27, 156, 1, 1, 6 },
    { 24, 146, 1, 1, 6 },
    { 22, 146, 1, 1, 6 },
    { 18, 154, 1, 1, 6 },
    { 6, 138, 1, 1, 6 },
    { 20, 160, 1, 1, 6 },
    { 20, 138, 1, 1, 6 },
    { 25, 144, 1, 1, 6 },
    { 25, 144, 1, 1, 6 },
    { 32, 33, 1, 1, 6 },
    { 25, 144, 1, 1, 6 },
    { 25, 144, 1, 1, 6 },
    { 41, 149, 1, 1, 6 },
    { 25, 68, 1, 1, 6 },
    { 12, 39, 1, 1, 6 },
    { 25, 171, 1, 1, 6 },
    { 18, 164, 1, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -3, 118, 2, 1, 7 },
    { -1, 98, 2, 1, 7 },
    { 7, 106, 2, 1, 7 },
    { 11, 89, 2, 1, 7 },
    { 14, 91, 2, 1, 7 },
    { -1, -17, 2, 1, 7 },
    { -14, 40, 2, 1, 7 },
    { -11, 95, 2, 1, 7 },
    { -3, 75, 2, 1, 7 },
    { 12, 87, 2, 1, 7 },
    { 11, 89, 2, 1, 7 },
    { 7, 106, 2, 1, 7 },
    { 7, 106, 2, 1, 7 },
    { -3, 118, 2, 1, 7 },
    { 7, 100, 2, 1, 7 },
    { 7, 100, 2, 1, 7 },
    { 0, 80, 2, 1, 7 },
    { -2, -13, 2, 1, 7 },
    { -5, 114, 2, 1, 7 },
    { -1, 84, 2, 1, 7 },
    { 4, -24, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -17, 142, 2, 1, 8 },
    { 3, 98, 2, 1, 8 },
    { -4, -13, 2, 1, 8 },
    { -7, -12, 2, 1, 8 },
    { 11, 98, 2, 1, 8 },
    { 3, -21, 2, 1, 8 },
    { 3, 46, 2, 1, 8 },
    { -14, 28, 2, 1, 8 },
    { 3, 75, 2, 1, 8 },
    { 2, 99, 2, 1, 8 },
    { -7, -12, 2, 1, 8 },
    { -4, -20, 2, 1, 8 },
    { -4, -20, 2, 1, 8 },
    { -17, 142, 2, 1, 8 },
    { -4, -13, 2, 1, 8 },
    { -4, -13, 2, 1, 8 },
    { -13, -11, 2, 1, 8 },
    { -13, -7, 2, 1, 8 },
    { 0, 84, 2, 1, 8 },
    { 3, 3, 2, 1, 8 },
    { -12, -22, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, 112, 1, 1, 9 },
    { -18, -11, 1, 1, 9 },
    { -18, 7, 1, 1, 9 },
    { -12, 9, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -8, 6, 1, 1, 9 },
    { -6, -5, 1, 1, 9 },
    { -5, -11, 1, 1, 9 },
    { 10, 8, 1, 1, 9 },
    { -4, -9, 1, 1, 9 },
    { -12, 9, 1, 1, 9 },
    { -18, 7, 1, 1, 9 },
    { -18, 7, 1, 1, 9 },
    { -16, 112, 1, 1, 9 },
    { -18, 7, 1, 1, 9 },
    { -18, 7, 1, 1, 9 },
    { -32, 8, 1, 1, 9 },
    { -20, 94, 1, 1, 9 },
    { -6, 117, 1, 1, 9 },
    { -20, -14, 1, 1, 9 },
    { -22, 6, 1, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -5, 148, 1, 1, 10 },
    { -21, 17, 1, 1, 10 },
    { -19, 22, 1, 1, 10 },
    { -6, 25, 1, 1, 10 },
    { -22, 6, 1, 1, 10 },
    { -18, 34, 1, 1, 10 },
    { -33, -14, 1, 1, 10 },
    { -19, 15, 1, 1, 10 },
    { 1, 27, 1, 1, 10 },
    { 2, 38, 1, 1, 10 },
    { -6, 25, 1, 1, 10 },
    { -19, 22, 1, 1, 10 },
    { -19, 22, 1, 1, 10 },
    { -5, 148, 1, 1, 10 },
    { -19, 22, 1, 1, 10 },
    { -19, 22, 1, 1, 10 },
    { -37, 17, 1, 1, 10 },
    { -24, 123, 1, 1, 10 },
    { -33, 13, 1, 1, 10 },
    { -21, 17, 1, 1, 10 },
    { -24, 22, 1, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -8, 132, 1, 1, 11 },
    { -24, 125, 1, 1, 11 },
    { -18, 46, 1, 1, 11 },
    { -28, 53, 1, 1, 11 },
    { -18, 18, 1, 1, 11 },
    { -26, 136, 1, 1, 11 },
    { -18, 173, 1, 1, 11 },
    { -11, 51, 1, 1, 11 },
    { -11, 37, 1, 1, 11 },
    { -27, 46, 1, 1, 11 },
    { -28, 53, 1, 1, 11 },
    { -18, 46, 1, 1, 11 },
    { -18, 46, 1, 1, 11 },
    { -8, 132, 1, 1, 11 },
    { -18, 46, 1, 1, 11 },
    { -18, 46, 1, 1, 11 },
    { -18, 41, 1, 1, 11 },
    { -13, 45, 1, 1, 11 },
    { 0, 14, 1, 1, 11 },
    { -11, 30, 1, 1, 11 },
    { -14, 36, 1, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 21, 9, 1, 1, 12 },
    { 20, 138, 1, 1, 12 },
    { 35, 134, 1, 1, 12 },
    { 22, 120, 1, 1, 12 },
    { 33, 152, 1, 1, 12 },
    { 32, 124, 1, 1, 12 },
    { 49, 130, 1, 1, 12 },
    { 24, 124, 1, 1, 12 },
    { 15, 130, 1, 1, 12 },
    { 14, 110, 1, 1, 12 },
    { 22, 120, 1, 1, 12 },
    { 35, 134, 1, 1, 12 },
    { 35, 134, 1, 1, 12 },
    { 21, 9, 1, 1, 12 },
    { 35, 134, 1, 1, 12 },
    { 35, 134, 1, 1, 12 },
    { 45, 142, 1, 1, 12 },
    { 31, 40, 1, 1, 12 },
    { 67, 119, 1, 1, 12 },
    { 35, 144, 1, 1, 12 },
    { -34, 154, 1, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 18, 21, 1, 1, 13 },
    { 40, 35, 1, 1, 13 },
    { 24, 27, 1, 1, 13 },
    { 29, 12, 1, 1, 13 },
    { 26, 18, 1, 1, 13 },
    { 27, 20, 1, 1, 13 },
    { 34, -7, 1, 1, 13 },
    { 3, 16, 1, 1, 13 },
    { 13, 10, 1, 1, 13 },
    { 29, 21, 1, 1, 13 },
    { 29, 12, 1, 1, 13 },
    { 24, 27, 1, 1, 13 },
    { 24, 27, 1, 1, 13 },
    { 18, 21, 1, 1, 13 },
    { 24, 27, 1, 1, 13 },
    { 24, 27, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 27, 20, 1, 1, 13 },
    { 52, 24, 1, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 9, 30, 1, 1, 14 },
    { 25, 37, 1, 1, 14 },
    { 11, -26, 1, 1, 14 },
    { 24, -10, 1, 1, 14 },
    { 19, -36, 1, 1, 14 },
    { 17, 28, 1, 1, 14 },
    { 23, -8, 1, 1, 14 },
    { 8, 43, 1, 1, 14 },
    { 15, 14, 1, 1, 14 },
    { 12, -6, 1, 1, 14 },
    { 24, -10, 1, 1, 14 },
    { 11, -26, 1, 1, 14 },
    { 11, -26, 1, 1, 14 },
    { 9, 30, 1, 1, 14 },
    { 11, -26, 1, 1, 14 },
    { 11, -26, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 17, 28, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -14, 31, 1, 1, 15 },
    { 13, 34, 1, 1, 15 },
    { 5, 24, 1, 1, 15 },
    { 14, -14, 1, 1, 15 },
    { 13, 27, 1, 1, 15 },
    { 5, 44, 1, 1, 15 },
    { 12, 6, 1, 1, 15 },
    { 16, -40, 1, 1, 15 },
    { -3, 30, 1, 1, 15 },
    { -5, -13, 1, 1, 15 },
    { 14, -14, 1, 1, 15 },
    { 5, 24, 1, 1, 15 },
    { 5, 24, 1, 1, 15 },
    { -14, 31, 1, 1, 15 },
    { 5, 24, 1, 1, 15 },
    { 5, 24, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 5, 44, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, -39, 2, 1, 16 },
    { -12, -25, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -5, -5, 2, 1, 16 },
    { -6, 30, 2, 1, 16 },
    { -8, 12, 2, 1, 16 },
    { 1, 5, 2, 1, 16 },
    { -14, 29, 2, 1, 16 },
    { -15, 18, 2, 1, 16 },
    { -15, -8, 2, 1, 16 },
    { -5, -5, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -16, -39, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -13, 28, 2, 1, 16 },
    { -20, 14, 2, 1, 16 },
    { -5, 24, 1, 1, 16 },
    { -29, -15, 1, 1, 16 },
    { -25, 16, 2, 1, 16 },
    { -12, -32, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 22, 8, 2, 1, 11 },
    { 60, 17, 2, 1, 11 },
    { 60, 22, 2, 1, 11 },
    { 70, 23, 2, 1, 11 },
    { 56, 2, 2, 1, 11 },
    { 70, 27, 2, 1, 11 },
    { 64, -11, 2, 1, 11 },
    { 71, 16, 2, 1, 11 },
    { 71, 37, 2, 1, 11 },
    { 60, 20, 2, 1, 11 },
    { 70, 23, 2, 1, 11 },
    { 60, 22, 2, 1, 11 },
    { 60, 22, 2, 1, 11 },
    { 22, 8, 2, 1, 11 },
    { 60, 22, 2, 1, 11 },
    { 60, 22, 2, 1, 11 },
    { 59, 13, 2, 1, 11 },
    { 63, 31, 2, 1, 11 },
    { 51, 25, 2, 1, 11 },
    { 64, 3, 2, 1, 11 },
    { 64, 11, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 27, -9, 2, 1, 12 },
    { 56, 2, 2, 1, 12 },
    { 29, 35, 2, 1, 12 },
    { 19, 31, 2, 1, 12 },
    { 24, 28, 2, 1, 12 },
    { 23, -6, 2, 1, 12 },
    { 51, -20, 2, 1, 12 },
    { 30, 58, 2, 1, 12 },
    { 26, 31, 2, 1, 12 },
    { 36, 21, 2, 1, 12 },
    { 19, 31, 2, 1, 12 },
    { 29, 35, 2, 1, 12 },
    { 29, 35, 2, 1, 12 },
    { 27, -9, 2, 1, 12 },
    { 29, 35, 2, 1, 12 },
    { 29, 35, 2, 1, 12 },
    { 11, 7, 2, 1, 12 },
    { 21, 66, 2, 1, 12 },
    { -8, 7, 2, 1, 12 },
    { 22, -20, 2, 1, 12 },
    { 43, -1, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -56, -8, 2, 1, 13 },
    { -18, -1, 2, 1, 13 },
    { -33, 8, 2, 1, 13 },
    { -10, 16, 2, 1, 13 },
    { -28, -6, 2, 1, 13 },
    { -19, 4, 2, 1, 13 },
    { -61, -14, 2, 1, 13 },
    { -79, 20, 2, 1, 13 },
    { -32, 27, 2, 1, 13 },
    { -55, 48, 2, 1, 13 },
    { -10, 16, 2, 1, 13 },
    { -33, 8, 2, 1, 13 },
    { -33, 8, 2, 1, 13 },
    { -56, -8, 2, 1, 13 },
    { -33, 8, 2, 1, 13 },
    { -33, 8, 2, 1, 13 },
    { -58, 10, 2, 1, 13 },
    { -76, 36, 2, 1, 13 },
    { -84, 5, 2, 1, 13 },
    { -19, -12, 2, 1, 13 },
    { -55, -3, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -42, 22, 2, 1, 14 },
    { -33, 16, 2, 1, 14 },
    { -26, 48, 2, 1, 14 },
    { -23, 56, 2, 1, 14 },
    { -33, 38, 2, 1, 14 },
    { -38, 42, 2, 1, 14 },
    { -25, 10, 2, 1, 14 },
    { -31, 52, 2, 1, 14 },
    { -26, 48, 2, 1, 14 },
    { -43, 70, 2, 1, 14 },
    { -23, 56, 2, 1, 14 },
    { -26, 48, 2, 1, 14 },
    { -26, 48, 2, 1, 14 },
    { -42, 22, 2, 1, 14 },
    { -26, 48, 2, 1, 14 },
    { -14, 63, 2, 1, 14 },
    { -19, 51, 2, 1, 14 },
    { -57, 58, 2, 1, 14 },
    { -41, 33, 2, 1, 14 },
    { -30, 15, 2, 1, 14 },
    { -16, 41, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -41, 25, 2, 1, 15 },
    { -23, 30, 2, 1, 15 },
    { -32, 49, 2, 1, 15 },
    { -17, 51, 2, 1, 15 },
    { -29, 41, 2, 1, 15 },
    { -39, 52, 2, 1, 15 },
    { -30, 12, 2, 1, 15 },
    { -39, 52, 2, 1, 15 },
    { -29, 47, 2, 1, 15 },
    { -51, 78, 2, 1, 15 },
    { -17, 51, 2, 1, 15 },
    { -32, 49, 2, 1, 15 },
    { -32, 49, 2, 1, 15 },
    { -41, 25, 2, 1, 15 },
    { -32, 49, 2, 1, 15 },
    { -49, 164, 2, 1, 15 },
    { -17, 53, 2, 1, 15 },
    { -52, 57, 2, 1, 15 },
    { -42, 36, 2, 1, 15 },
    { -29, 14, 2, 1, 15 },
    { -25, 32, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -23, 35, 2, 1, 16 },
    { -18, 47, 2, 1, 16 },
    { -22, 48, 2, 1, 16 },
    { -23, 56, 2, 1, 16 },
    { -22, 37, 2, 1, 16 },
    { -22, 51, 2, 1, 16 },
    { -14, 24, 2, 1, 16 },
    { -36, 51, 2, 1, 16 },
    { -12, 55, 2, 1, 16 },
    { -47, 62, 2, 1, 16 },
    { -23, 56, 2, 1, 16 },
    { -22, 48, 2, 1, 16 },
    { -22, 48, 2, 1, 16 },
    { -23, 35, 2, 1, 16 },
    { -22, 48, 2, 1, 16 },
    { -23, 64, 2, 1, 16 },
    { -39, 51, 2, 1, 16 },
    { -47, 60, 2, 1, 16 },
    { -37, 28, 2, 1, 16 },
    { -9, 40, 2, 1, 16 },
    { -23, 29, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -19, 34, 2, 1, 17 },
    { -15, 49, 2, 1, 17 },
    { -27, 52, 2, 1, 17 },
    { -40, 154, 2, 1, 17 },
    { -25, 38, 2, 1, 17 },
    { -46, 58, 2, 1, 17 },
    { -30, 12, 2, 1, 17 },
    { -25, 52, 2, 1, 17 },
    { -10, 54, 2, 1, 17 },
    { -30, 70, 2, 1, 17 },
    { -40, 154, 2, 1, 17 },
    { -27, 52, 2, 1, 17 },
    { -27, 52, 2, 1, 17 },
    { -19, 34, 2, 1, 17 },
    { -27, 52, 2, 1, 17 },
    { -23, 64, 2, 1, 17 },
    { -35, 52, 2, 1, 17 },
    { -45, 62, 2, 1, 17 },
    { -43, 28, 2, 1, 17 },
    { -10, 38, 2, 1, 17 },
    { -24, 31, 2, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -35, 38, 2, 1, 18 },
    { -66, 146, 2, 1, 18 },
    { -60, 61, 2, 1, 18 },
    { -32, 47, 2, 1, 18 },
    { -63, 52, 2, 1, 18 },
    { -48, 62, 2, 1, 18 },
    { -33, 34, 2, 1, 18 },
    { -47, 56, 2, 1, 18 },
    { -35, 54, 2, 1, 18 },
    { -64, 79, 2, 1, 18 },
    { -32, 47, 2, 1, 18 },
    { -60, 61, 2, 1, 18 },
    { -60, 61, 2, 1, 18 },
    { -35, 38, 2, 1, 18 },
    { -60, 61, 2, 1, 18 },
    { -44, 152, 2, 1, 18 },
    { -47, 76, 2, 1, 18 },
    { -38, 65, 2, 1, 18 },
    { -66, 31, 2, 1, 18 },
    { -56, 63, 2, 1, 18 },
    { -52, 48, 2, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, 22, 2, 1, 19 },
    { -59, 27, 2, 1, 19 },
    { -57, 32, 2, 1, 19 },
    { -47, 33, 2, 1, 19 },
    { -40, 20, 2, 1, 19 },
    { -32, 22, 2, 1, 19 },
    { -38, 2, 2, 1, 19 },
    { -44, 45, 2, 1, 19 },
    { -38, 37, 2, 1, 19 },
    { -54, 42, 2, 1, 19 },
    { -47, 33, 2, 1, 19 },
    { -57, 32, 2, 1, 19 },
    { -57, 32, 2, 1, 19 },
    { -40, 22, 2, 1, 19 },
    { -57, 32, 2, 1, 19 },
    { -57, 60, 2, 1, 19 },
    { -51, 30, 2, 1, 19 },
    { -44, 34, 2, 1, 19 },
    { -69, 29, 2, 1, 19 },
    { -32, 22, 2, 1, 19 },
    { -36, 31, 2, 1, 19 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 65 entries */
const u16* const hugo_exca[66] = {
    hugo_exca_000,  /* 0 follow-up of AIR NORMAL */
    hugo_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    hugo_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    hugo_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    hugo_exca_001,  /* 4 follow-up of APPEAR JUNBI 4 */
    hugo_exca_005,  /* 5 follow-up of TATAKI S, TATAKI M +10 */
    hugo_exca_006,  /* 6 follow-up of ALEX B.D, NECRO G S +1 */
    hugo_exca_007,  /* 7 follow-up of KUNOJI, DENKI +3 */
    hugo_exca_008,  /* 8 follow-up of TTKI V. AIR, ALEX BODY S +1 */
    hugo_exca_009,  /* 9 no name */
    hugo_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    hugo_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    hugo_exca_010,  /* 12 follow-up of APPEAR JUNBI 4 */
    hugo_exca_013,  /* 13 no name */
    hugo_exca_014,  /* 14 follow-up of HUMI ASIB */
    hugo_exca_015,  /* 15 follow-up of SP APPEAR 7 */
    hugo_exca_016,  /* 16 follow-up of SP APPEAR 7 */
    hugo_exca_017,  /* 17 no name */
    hugo_exca_018,  /* 18 no name */
    hugo_exca_017,  /* 19 no name */
    hugo_exca_017,  /* 20 no name */
    hugo_exca_017,  /* 21 no name */
    hugo_exca_022,  /* 22 no name */
    hugo_exca_023,  /* 23 no name */
    hugo_exca_024,  /* 24 follow-up of APPEAR JUNBI 6 */
    hugo_exca_024,  /* 25 follow-up of APPEAR JUNBI 6 */
    hugo_exca_017,  /* 26 no name */
    hugo_exca_027,  /* 27 follow-up of APPEAR JUNBI 7 */
    hugo_exca_028,  /* 28 follow-up of APPEAR JUNBI 7 */
    hugo_exca_029,  /* 29 follow-up of APPEAR 1 */
    hugo_exca_030,  /* 30 follow-up of APPEAR 1 */
    hugo_exca_031,  /* 31 follow-up of APPEAR 3 */
    hugo_exca_032,  /* 32 follow-up of APPEAR 3 */
    hugo_exca_033,  /* 33 no name */
    hugo_exca_034,  /* 34 follow-up of APPEAR 4 */
    hugo_exca_035,  /* 35 follow-up of APPEAR 4 */
    hugo_exca_036,  /* 36 follow-up of GILL IMPACT C */
    hugo_exca_037,  /* 37 follow-up of APPEAR 8 */
    hugo_exca_038,  /* 38 follow-up of APPEAR 8 */
    hugo_exca_039,  /* 39 follow-up of GILL IMPACT C */
    hugo_exca_040,  /* 40 no name */
    hugo_exca_041,  /* 41 no name */
    hugo_exca_042,  /* 42 follow-up of SP APPEAR 2 */
    hugo_exca_043,  /* 43 follow-up of SP APPEAR 2 */
    hugo_exca_044,  /* 44 follow-up of SP APPEAR 8 */
    hugo_exca_045,  /* 45 follow-up of SP APPEAR 8 */
    hugo_exca_044,  /* 46 follow-up of ZANNEN 1 */
    hugo_exca_045,  /* 47 follow-up of ZANNEN 1 */
    hugo_exca_048,  /* 48 follow-up of ZANNEN 2 */
    hugo_exca_049,  /* 49 follow-up of ZANNEN 2 */
    hugo_exca_050,  /* 50 follow-up of SNAKE FANG, ALEX BACK D */
    hugo_exca_051,  /* 51 follow-up of NOKEZORI, KIRIMOMI +18 */
    hugo_exca_052,  /* 52 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE */
    hugo_exca_053,  /* 53 follow-up of APPEAR 6, ZANNEN 5 */
    hugo_exca_054,  /* 54 follow-up of APPEAR 6, ZANNEN 5 */
    hugo_exca_055,  /* 55 follow-up of ZANNEN 8 */
    hugo_exca_056,  /* 56 follow-up of ZANNEN 8 */
    hugo_exca_057,  /* 57 follow-up of WIN 1 */
    hugo_exca_058,  /* 58 follow-up of WIN 1 */
    hugo_exca_059,  /* 59 follow-up of WIN 2 */
    hugo_exca_060,  /* 60 follow-up of WIN 2 */
    hugo_exca_061,  /* 61 follow-up of CATCH 38, CATCH 39 +1 */
    hugo_exca_062,  /* 62 follow-up of WIN 3 */
    hugo_exca_063,  /* 63 follow-up of WIN 3 */
    hugo_exca_064,  /* 64 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 hugo_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_exca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x253A, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2539, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2538, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2537, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2536, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2535, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2450, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2452, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2453, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2455, 0, 84, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 84, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, 2 follow-up of APPEAR JUNBI 3, 4 follow-up of APPEAR JUNBI 4 */
const u16 hugo_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_001[60] = {
    L4(1, 0, 286, 0, 0, 0, 0, 0x2434, 0, 191, 0, 0, 0, 39, 4),
    L4(1, 2, 0, 0, 0, 0, 0, 0x2434, 0, 191, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2435, 0, 191, 0, 0, 0, 21, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x2438, 0, 257, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 hugo_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_003[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24F8, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24F9, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x24FB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x24FC, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2500, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2501, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2502, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2503, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2504, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2505, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2506, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 8, 21, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, TATAKI M +10 */
const u16 hugo_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_005[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24F8, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F9, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FB, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FC, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24FF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2500, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2501, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2502, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2503, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2504, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2505, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of ALEX B.D, NECRO G S +1 */
const u16 hugo_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_006[156] = {
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 1, 0, 0, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 1, 0, 0, 0x24E3, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 1, 0, 0, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x24E5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x24E6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24E7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, DENKI +3 */
const u16 hugo_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_007[184] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24F8, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24F9, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FF, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2500, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2501, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2502, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2503, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2504, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2505, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 7, 2), 0, 0, 0, 0,
};

/* script: 8 follow-up of TTKI V. AIR, ALEX BODY S +1 */
const u16 hugo_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_008[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24F8, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24F9, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24FC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FF, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2500, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2501, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2502, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2503, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2504, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2505, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 no name */
const u16 hugo_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_009[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24E3, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24E7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, 11 follow-up of APPEAR JUNBI 3, 12 follow-up of APPEAR JUNBI 4 */
const u16 hugo_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_010[44] = {
    L4(1, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 4),
    L4(1, 2, 0, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 hugo_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_013[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E3, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of HUMI ASIB */
const u16 hugo_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_014[148] = {
    CMD(CM_PA_X, 0, 16384, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24F8, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24F9, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x24FB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x24FC, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24FD, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24FE, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x24FF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2500, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2501, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2502, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2503, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2504, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2505, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of SP APPEAR 7 */
const u16 hugo_exca_015_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_015[212] = {
    CMD(CM_EXEC, 1, 80, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 81, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 286, 0, 0, 0, 0, 0x25BB, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BC, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BD, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BE, 0, 144, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25BF, 0, 144, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25C0, 0, 144, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25C1, 0, 144, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25C2, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16393, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x252C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x252D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 22, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of SP APPEAR 7 */
const u16 hugo_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_016[140] = {
    CMD(CM_EXEC, 1, 80, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 81, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 286, 0, 0, 0, 0, 0x25BB, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BC, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BD, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25BE, 0, 144, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25BF, 0, 144, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25C0, 0, 144, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25C1, 0, 144, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25C2, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16389, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x252C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x252D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x25C2, 0, 2, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name, 19 no name, 20 no name, 21 no name ... */
const u16 hugo_exca_017_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_exca_017[12] = {
    L4(250, 0, 0, 0, 1, 0, 0, 0x2401, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 hugo_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_exca_018[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x24DF, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x24DE, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x24DD, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x24DC, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x24DC, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 hugo_exca_022_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_022[132] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x24CB, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 1, 0, 0, 0x24CC, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x24CD, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24CE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24CF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24D0, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24D1, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24D2, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24D3, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24D4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24D5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x24D6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24D7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24D8, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x24D9, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24D9, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 no name */
const u16 hugo_exca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_exca_023[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x24CD, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24CE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24CF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x24D2, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 6, 25 follow-up of APPEAR JUNBI 6 */
const u16 hugo_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_024[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR JUNBI 7 */
const u16 hugo_exca_027_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_027[236] = {
    CMD(CM_EXEC, 1, 80, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 81, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 286, 0, 0, 0, 0, 0x2503, 0, 145, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2504, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2505, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2506, 0, 145, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16395, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2524, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2525, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2526, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2527, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2528, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 22, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2529, 0, 67, 0, 0, 0, 24, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252A, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252B, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 22, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR JUNBI 7 */
const u16 hugo_exca_028_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_028[180] = {
    CMD(CM_EXEC, 1, 80, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 81, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 286, 0, 0, 0, 0, 0x2503, 0, 145, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2504, 0, 145, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2505, 0, 145, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2506, 0, 145, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16392, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2524, 0, 145, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2525, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2526, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2527, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2527, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2528, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2528, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2529, 0, 67, 0, 0, 0, 24, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x252A, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252B, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x252D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x252E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR 1 */
const u16 hugo_exca_029_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_029[64] = {
    L6(3, 0, 274, 0, 0, 0, 0, 0x2497, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x2498, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2499, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x249A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x249A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1 */
const u16 hugo_exca_030_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_030[76] = {
    L6(1, 64, 274, 0, 0, 0, 0, 0x2431, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2432, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2433, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR 3 */
const u16 hugo_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_031[60] = {
    L4(1, 0, 286, 0, 0, 0, 0, 0x2431, 0, 4, 0, 0, 0, 39, 8),
    L4(1, 2, 0, 0, 0, 0, 0, 0x2431, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2432, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2433, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2434, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 3 */
const u16 hugo_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_032[52] = {
    L4(1, 0, 286, 0, 0, 0, 0, 0x2431, 0, 1, 0, 0, 0, 39, 8),
    L4(1, 2, 0, 0, 0, 0, 0, 0x2431, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x2432, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x2433, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 1, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 hugo_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_033[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24CA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24CB, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24CE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24CF, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24D0, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24D1, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24D2, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24D3, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24D4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24D5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24D6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D8, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24D9, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 8, 21, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 4 */
const u16 hugo_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_034[52] = {
    L4(6, 0, 286, 0, 0, 0, 0, 0x2431, 0, 4, 0, 0, 0, 39, 8),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2432, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2433, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2434, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of APPEAR 4 */
const u16 hugo_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_035[60] = {
    L4(3, 0, 286, 0, 0, 0, 0, 0x2702, 0, 1, 0, 0, 0, 39, 8),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2703, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2704, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2705, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2706, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2707, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 1, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of GILL IMPACT C */
const u16 hugo_exca_036_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_036[148] = {
    L4(2, 2, 0, 0, 1, 0, 0, 0x24F6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x24F7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24F8, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24F9, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 0, 0, 0x24FB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 1, 0, 0, 0x24FC, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FD, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FE, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2500, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2501, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2502, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2503, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2504, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2505, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2506, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 8, 27, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of APPEAR 8 */
const u16 hugo_exca_037_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_037[68] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x2434, 0, 200, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2435, 0, 200, 0, 0, 0, 39, 4),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2436, 0, 201, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2437, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x2438, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of APPEAR 8 */
const u16 hugo_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_038[36] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x2434, 0, 206, 0, 0, 0, 21, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x2435, 0, 206, 0, 0, 0, 39, 4),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2436, 0, 207, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of GILL IMPACT C */
const u16 hugo_exca_039_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_039[140] = {
    L4(2, 2, 0, 0, 1, 0, 0, 0x24F6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 1, 0, 0, 0x24F7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x24F8, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24F9, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 0, 0, 0x24FB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 1, 0, 0, 0x24FC, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FD, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FE, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x24FF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2500, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2501, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2502, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2503, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2504, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x2505, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 69, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 no name */
const u16 hugo_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_040[92] = {
    L4(3, 0, 286, 0, 0, 0, 0, 0x2431, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2432, 0, 1, 0, 0, 0, 39, 10),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2433, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2436, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 no name */
const u16 hugo_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_041[52] = {
    L4(3, 0, 286, 0, 0, 0, 0, 0x2431, 0, 4, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2432, 0, 4, 0, 0, 0, 39, 10),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2433, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2434, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of SP APPEAR 2 */
const u16 hugo_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_042[68] = {
    L4(2, 3, 286, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 39, 8),
    L4(2, 3, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2436, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of SP APPEAR 2 */
const u16 hugo_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_043[68] = {
    L4(2, 3, 286, 0, 0, 0, 0, 0x2434, 0, 4, 0, 0, 0, 39, 8),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2435, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x2436, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2437, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2438, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2439, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of SP APPEAR 8, 46 follow-up of ZANNEN 1 */
const u16 hugo_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_044[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP APPEAR 8, 47 follow-up of ZANNEN 1 */
const u16 hugo_exca_045_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_045[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2436, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2445, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2445, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of ZANNEN 2 */
const u16 hugo_exca_048_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_048[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2438, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of ZANNEN 2 */
const u16 hugo_exca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_049[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x2435, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2436, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2437, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2445, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2445, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of SNAKE FANG, ALEX BACK D */
const u16 hugo_exca_050_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_050[152] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 82, 0, 0, 0, 24, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24F8, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F9, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FA, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24FB, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FC, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24FF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2500, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x2501, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2502, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2503, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2504, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2505, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
};

/* script: 51 follow-up of NOKEZORI, KIRIMOMI +18 */
const u16 hugo_exca_051_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_051[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E1, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E2, 0, 82, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x24E3, 0, 82, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x24E4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24E6, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24E7, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24E8, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24E9, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24EA, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24EB, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24EC, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24ED, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EE, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x24EF, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F0, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 24, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE */
const u16 hugo_exca_052_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 hugo_exca_052[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x24F7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x24F8, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24F9, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x24FB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x24FC, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FD, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FE, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x24FF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2500, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2501, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2502, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2503, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2504, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2505, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2506, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2506, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of APPEAR 6, ZANNEN 5 */
const u16 hugo_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_053[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 39, 10),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of APPEAR 6, ZANNEN 5 */
const u16 hugo_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_054[44] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 39, 10),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of ZANNEN 8 */
const u16 hugo_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_055[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 14),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of ZANNEN 8 */
const u16 hugo_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_056[44] = {
    L4(4, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 14),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 follow-up of WIN 1 */
const u16 hugo_exca_057_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_057[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 16),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 follow-up of WIN 1 */
const u16 hugo_exca_058_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_058[44] = {
    L4(3, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 16),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 follow-up of WIN 2 */
const u16 hugo_exca_059_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_059[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 18),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 follow-up of WIN 2 */
const u16 hugo_exca_060_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_060[44] = {
    L4(3, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 39, 18),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of CATCH 38, CATCH 39 +1 */
const u16 hugo_exca_061_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_061[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 200, 0, 0, 0, 39, 14),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 200, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2436, 0, 201, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2437, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2438, 0, 202, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of WIN 3 */
const u16 hugo_exca_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_exca_062[68] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 39, 14),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2437, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2438, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x2439, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x243A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of WIN 3 */
const u16 hugo_exca_063_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 hugo_exca_063[44] = {
    L4(2, 0, 286, 0, 0, 0, 0, 0x2434, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 2, 0, 0, 0, 39, 14),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2436, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 hugo_exca_064_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 hugo_exca_064[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x253A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2539, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2538, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2537, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2536, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2535, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2450, 0, 214, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2452, 0, 215, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2453, 0, 215, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2455, 0, 215, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 216, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 68 entries */
const u16* const hugo_saca[69] = {
    hugo_saca_000,  /* 0 UP P GUARD P S */
    hugo_saca_001,  /* 1 UP P GUARD P M */
    hugo_saca_002,  /* 2 UP P GUARD P L */
    hugo_saca_002,  /* 3 UP P GUARD K S */
    hugo_saca_002,  /* 4 UP P GUARD K M */
    hugo_saca_002,  /* 5 UP P GUARD K L */
    hugo_saca_000,  /* 6 D P GUARD P S */
    hugo_saca_001,  /* 7 D P GUARD P M */
    hugo_saca_002,  /* 8 D P GUARD P L */
    hugo_saca_002,  /* 9 D P GUARD K S */
    hugo_saca_002,  /* 10 D P GUARD K M */
    hugo_saca_002,  /* 11 D P GUARD K L */
    hugo_saca_002,  /* 12 FUSHIN P S */
    hugo_saca_002,  /* 13 FUSHIN P M */
    hugo_saca_002,  /* 14 FUSHIN P L */
    hugo_saca_002,  /* 15 FUSHIN K S */
    hugo_saca_002,  /* 16 FUSHIN K M */
    hugo_saca_002,  /* 17 FUSHIN K L */
    hugo_saca_002,  /* 18 OKIAGARI P S */
    hugo_saca_002,  /* 19 OKIAGARI P M */
    hugo_saca_002,  /* 20 OKIAGARI P L */
    hugo_saca_002,  /* 21 OKIAGARI K S */
    hugo_saca_002,  /* 22 OKIAGARI K M */
    hugo_saca_002,  /* 23 OKIAGARI K L */
    hugo_saca_024,  /* 24 ATTACK 1 S: 214+P light (plain script) */
    hugo_saca_025,  /* 25 ATTACK 1 M: 214+P medium (plain script) */
    hugo_saca_026,  /* 26 ATTACK 1 L: 214+P heavy (plain script) */
    hugo_saca_027,  /* 27 ATTACK 1 SP: EX 214+PP (plain script) */
    hugo_saca_028,  /* 28 ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI) */
    hugo_saca_029,  /* 29 ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI) */
    hugo_saca_030,  /* 30 ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) */
    hugo_saca_031,  /* 31 ATTACK 2 SP: EX 236+KK (routine Att_PL06_HASHIRI_NAGE) */
    hugo_saca_032,  /* 32 ATTACK 3 S: 360+P light (plain script) */
    hugo_saca_033,  /* 33 ATTACK 3 M: 360+P medium (plain script) */
    hugo_saca_034,  /* 34 ATTACK 3 L: 360+P heavy/EX (plain script) */
    hugo_saca_034,  /* 35 ATTACK 3 SP: 360+P heavy/EX (plain script) */
    hugo_saca_036,  /* 36 ATTACK 4 S: 6(123)4+K light (plain script) */
    hugo_saca_037,  /* 37 ATTACK 4 M: 6(123)4+K medium (plain script) */
    hugo_saca_038,  /* 38 ATTACK 4 L: 6(123)4+K heavy/EX (plain script) */
    hugo_saca_038,  /* 39 ATTACK 4 SP: 6(123)4+K heavy/EX (plain script) */
    hugo_saca_040,  /* 40 ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN) */
    hugo_saca_041,  /* 41 ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN) */
    hugo_saca_042,  /* 42 ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    hugo_saca_042,  /* 43 ATTACK 5 SP: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    hugo_saca_044,  /* 44 ATTACK 6 S: SA I 720+P (plain script) */
    hugo_saca_044,  /* 45 ATTACK 6 M: SA I 720+P (plain script) */
    hugo_saca_044,  /* 46 ATTACK 6 L: SA I 720+P (plain script) */
    hugo_saca_044,  /* 47 ATTACK 6 SP: SA I 720+P (plain script) */
    hugo_saca_048,  /* 48 ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN) */
    hugo_saca_049,  /* 49 ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN) */
    hugo_saca_050,  /* 50 ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    hugo_saca_050,  /* 51 ATTACK 7 SP: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    hugo_saca_052,  /* 52 ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    hugo_saca_053,  /* 53 ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP) */
    hugo_saca_054,  /* 54 ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    hugo_saca_054,  /* 55 ATTACK 8 SP: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    hugo_saca_056,  /* 56 ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    hugo_saca_057,  /* 57 ATTACK 9 M: not started by a command */
    hugo_saca_057,  /* 58 ATTACK 9 L: not started by a command */
    hugo_saca_057,  /* 59 ATTACK 9 SP: not started by a command */
    hugo_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    hugo_saca_060,  /* 61 ATTACK 10 M: not started by a command */
    hugo_saca_060,  /* 62 ATTACK 10 L: not started by a command */
    hugo_saca_060,  /* 63 ATTACK 10 SP: not started by a command */
    hugo_saca_064,  /* 64 ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE) */
    hugo_saca_065,  /* 65 ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE) */
    hugo_saca_066,  /* 66 ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    hugo_saca_066,  /* 67 ATTACK 11 SP: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 hugo_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B2, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B3, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B6, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B7, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BB, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70BC, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1536, -2560), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 hugo_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 hugo_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70BC, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70BB, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70BB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70BA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B8, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B7, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B6, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B3, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70B2, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 hugo_saca_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_saca_002[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 214+P light (plain script) */
const u16 hugo_saca_024_head[4] = { HEAD(6, 0, 8, 15, 0, 1, 60) };
const u16 hugo_saca_024[244] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x263B, 0, 1, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x263C, 0, 36, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x263D, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x263E, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x263F, 0, 38, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 836, 0, 0, 0, 0, 0x2640, 0, 36, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 268, 0, 0, 0, 0, 0x2641, 0, 37, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 10, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 286, 1, 0, 44, 0, 0x2642, -9, 39, 0, 139, 64, 30, 66, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, 9, 39, 0, 128, 64, 30, 70, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 40, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 40, 0, 0, 64, 30, 67, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 40, 0, 0, 64, 30, 69, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 40, 0, 0, 0, 30, 68, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 47, 0, 0x2645, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x25FB, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 1, 0, 0, 0, 0x25FC, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 214+P medium (plain script) */
const u16 hugo_saca_025_head[4] = { HEAD(6, 0, 10, 15, 0, 1, 60) };
const u16 hugo_saca_025[244] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x263B, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x263C, 0, 41, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x263D, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x263E, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x263F, 0, 43, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 836, 0, 0, 0, 0, 0x2640, 0, 41, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x2641, 0, 42, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 286, 1, 0, 44, 0, 0x2642, -10, 44, 0, 139, 64, 30, 66, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, 10, 44, 0, 128, 64, 30, 70, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 45, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 45, 0, 0, 64, 30, 67, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 45, 0, 0, 64, 30, 69, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 45, 0, 0, 0, 30, 68, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 47, 0, 0x2645, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x25FB, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 1, 0, 0, 0, 0x25FC, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 214+P heavy (plain script) */
const u16 hugo_saca_026_head[4] = { HEAD(6, 0, 12, 15, 0, 1, 60) };
const u16 hugo_saca_026[244] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x263B, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x263C, 0, 46, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x263D, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x263E, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x263F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 836, 0, 0, 0, 0, 0x2640, 0, 46, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x2641, 0, 47, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 14, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 286, 1, 0, 44, 0, 0x2642, -11, 49, 0, 139, 64, 30, 66, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, 11, 49, 0, 128, 64, 30, 70, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 30, 67, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 30, 69, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 0, 30, 68, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 47, 0, 0x2645, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 1, 0, 0, 0, 0x25FB, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x25FC, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 214+PP (plain script) */
const u16 hugo_saca_027_head[4] = { HEAD(6, 0, 14, 15, 0, 3, 60) };
const u16 hugo_saca_027[256] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 838, 0, 0, 0, 0, 0x263B, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x263C, 0, 46, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x263D, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x263E, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x263F, 0, 48, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2640, 0, 46, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x2641, 0, 47, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 286, 1, 0, 44, 0, 0x2642, -33, 49, 0, 0, 64, 30, 71, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 30, 72, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, -34, 49, 0, 0, 64, 30, 74, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 30, 73, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, -40, 49, 0, 128, 64, 30, 75, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 45, 0, 0x2643, 0, 50, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 47, 0, 0x2645, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x25FB, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x25FC, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 1, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI) */
const u16 hugo_saca_028_head[4] = { HEAD(6, 0, 8, 9, 0, 1, 61) };
const u16 hugo_saca_028[340] = {
    L6(2, 20, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2674, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 1, 0, 0, 0, 0x2677, -41, 116, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 117, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2679, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 148, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 157, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267C, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI) */
const u16 hugo_saca_029_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 61) };
const u16 hugo_saca_029[352] = {
    L6(3, 20, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2674, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 1, 0, 0, 0, 0x2677, -42, 116, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 117, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2679, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 148, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 157, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267C, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) */
const u16 hugo_saca_030_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 61) };
const u16 hugo_saca_030[400] = {
    L6(3, 20, 0, 0, 0, 0, 0, 0x266D, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x266E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x266F, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2670, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2674, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 1, 0, 0, 0, 0x2677, -43, 116, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 117, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2679, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 148, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 157, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267C, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x267E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 236+KK (routine Att_PL06_HASHIRI_NAGE) */
const u16 hugo_saca_031_head[4] = { HEAD(4, 0, 14, 11, 0, 1, 61) };
const u16 hugo_saca_031[508] = {
    CMD(CM_RJA4, 5, 31, 54), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x266D, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x266E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x266F, 0, 1, 0, 0, 0, 39, 2),
    CMD(CM_RJA4, 5, 31, 59), 0, 0, 0, 0,
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2670, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2670, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 31, 30), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 4, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 33, 0),
    CMD(CM_IFS2, 1792, 8192, 8197), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2674, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 82, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1),
    L4(2, 0, 270, 1, 0, 0, 0, 0x2677, -71, 116, 0, 128, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0,
    L4(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 117, 0, 0, 0, 39, 3),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 118, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 148, 0, 0, 0, 21, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 20, 0, 1, 0, 0, 0, 0x2678, 0, 157, 0, 0, 0, 39, 3),
    L4(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x267C, 0, 149, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 1, 0, 0, 0, 0x267E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x2551, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 82, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1),
    L4(2, 0, 270, 1, 0, 0, 0, 0x2677, -66, 116, 0, 128, 0, 0, 0),
    CMD(CM_JPSS, 5, 31, 34), 0, 0, 0, 0,
    CMD(CM_MVIX, 82, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 20, 839, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 43, 1),
    L4(2, 0, 270, 1, 0, 0, 0, 0x2677, -70, 116, 0, 128, 0, 0, 0),
    CMD(CM_JPSS, 5, 31, 34), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 360+P light (plain script) */
const u16 hugo_saca_032_head[4] = { HEAD(6, 0, 24, 11, 0, 0, 58) };
const u16 hugo_saca_032[172] = {
    CMD(CM_CAFR, 2, 4, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -26, 99, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(4, 0, 269, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0, 0, 0, 78, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 360+P medium (plain script) */
const u16 hugo_saca_033_head[4] = { HEAD(6, 0, 26, 10, 0, 0, 58) };
const u16 hugo_saca_033[64] = {
    CMD(CM_CAFR, 2, 4, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -26, 100, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_JMP, 5, 32, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 360+P heavy/EX (plain script), 35 ATTACK 3 SP: 360+P heavy/EX (plain script) */
const u16 hugo_saca_034_head[4] = { HEAD(6, 0, 28, 9, 0, 0, 58) };
const u16 hugo_saca_034[64] = {
    CMD(CM_CAFR, 2, 4, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -26, 101, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_JMP, 5, 32, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 6(123)4+K light (plain script) */
const u16 hugo_saca_036_head[4] = { HEAD(6, 0, 24, 8, 0, 0, 62) };
const u16 hugo_saca_036[184] = {
    CMD(CM_CAFR, 2, 1, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -51, 150, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(4, 0, 269, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0, 0, 0, 78, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 6(123)4+K medium (plain script) */
const u16 hugo_saca_037_head[4] = { HEAD(6, 0, 26, 8, 0, 0, 62) };
const u16 hugo_saca_037[76] = {
    CMD(CM_CAFR, 2, 1, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -51, 150, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_JMP, 5, 36, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 6(123)4+K heavy/EX (plain script), 39 ATTACK 4 SP: 6(123)4+K heavy/EX (plain script) */
const u16 hugo_saca_038_head[4] = { HEAD(6, 0, 28, 8, 0, 0, 62) };
const u16 hugo_saca_038[76] = {
    CMD(CM_CAFR, 2, 1, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -51, 150, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_JMP, 5, 36, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_040_head[4] = { HEAD(6, 20, 24, 8, 0, 1, 59) };
const u16 hugo_saca_040[160] = {
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 841, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 269, 0, 0, 0, 0, 0x2449, 0, 3, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x244A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x25E8, -50, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_041_head[4] = { HEAD(6, 20, 24, 9, 0, 1, 59) };
const u16 hugo_saca_041[172] = {
    CMD(CM_JSR, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 841, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 269, 0, 0, 0, 0, 0x2449, 0, 3, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x244A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x244B, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x25E8, -50, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN), 43 ATTACK 5 SP: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_042_head[4] = { HEAD(6, 20, 24, 10, 0, 1, 59) };
const u16 hugo_saca_042[184] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 841, 0, 0, 0, 0, 0x2434, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 269, 0, 0, 0, 0, 0x2449, 0, 3, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x244A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x244B, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x244C, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x25E8, -50, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 120, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA I 720+P (plain script), 45 ATTACK 6 M: SA I 720+P (plain script), 46 ATTACK 6 L: SA I 720+P (plain script), 47 ATTACK 6 SP: SA I 720+P (plain script) */
const u16 hugo_saca_044_head[4] = { HEAD(6, 0, 60, 13, 0, 0, 55) };
const u16 hugo_saca_044[196] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 4, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(52, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 156, 0, 0, 0, 13, 42, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 156, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x25F2, -52, 142, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0, 0, 0, 78, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_048_head[4] = { HEAD(6, 20, 56, 10, 0, 0, 56) };
const u16 hugo_saca_048[136] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(52, 0, 0, 0, 0, 0, 0, 0x2434, 0, 156, 0, 0, 0, 13, 43, 0, 0, 0, 0, 0),
    L6(1, 20, 841, 0, 0, 0, 0, 0x244C, 0, 254, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(12, 0, 269, 0, 0, 0, 0, 0x25E8, -56, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 122, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_049_head[4] = { HEAD(6, 20, 56, 11, 0, 0, 56) };
const u16 hugo_saca_049[148] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(52, 0, 0, 0, 0, 0, 0, 0x2434, 0, 156, 0, 0, 0, 13, 43, 0, 0, 0, 0, 0),
    L6(1, 20, 841, 0, 0, 0, 0, 0x244C, 0, 3, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x25E7, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x25E8, -56, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 122, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN), 51 ATTACK 7 SP: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
const u16 hugo_saca_050_head[4] = { HEAD(6, 20, 56, 12, 0, 0, 56) };
const u16 hugo_saca_050[148] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(52, 0, 0, 0, 0, 0, 0, 0x2434, 0, 156, 0, 0, 0, 13, 43, 0, 0, 0, 0, 0),
    L6(2, 20, 841, 0, 0, 0, 0, 0x244C, 0, 3, 0, 0, 0, 1, 87, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x25E7, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(20, 0, 0, 0, 0, 0, 0, 0x25E8, -56, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x25E7, 0, 122, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2452, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2453, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x2454, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2455, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
const u16 hugo_saca_052_head[4] = { HEAD(6, 0, 32, 15, 0, 5, 57) };
const u16 hugo_saca_052[376] = {
    CMD(CM_WSET, 16384, 0, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x266A, 0, 156, 0, 0, 0, 13, 44, 771, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x266B, 0, 156, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(45, 0, 0, 0, 0, 0, 0, 0x266C, 0, 156, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x266C, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 1, 0, 0, 0, 0x2676, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2677, -59, 132, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 1, 0, 0, 0, 0x2675, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 1, 0, 0, 0, 0x2676, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x2677, -59, 160, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 81, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 30, 0, 1, 0, 0, 0, 0x2678, 0, 133, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 1, 0, 0, 0, 0x267A, 0, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 1, 0, 0, 0, 0x2678, 0, 0, 0, 0, 0, 39, 3, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2679, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x267A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267C, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x267E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 56, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP) */
const u16 hugo_saca_053_head[4] = { HEAD(2, 0, 34, 15, 0, 5, 57) };
const u16 hugo_saca_053[12] = {
    CMD(CM_WSET, 16384, 0, 32),
    CMD(CM_JPSS, 5, 52, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP), 55 ATTACK 8 SP: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
const u16 hugo_saca_054_head[4] = { HEAD(2, 0, 36, 15, 0, 5, 57) };
const u16 hugo_saca_054[12] = {
    CMD(CM_WSET, 16384, 0, 64),
    CMD(CM_JPSS, 5, 52, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 hugo_saca_056_head[4] = { HEAD(6, 0, 32, 16, 0, 4, 57) };
const u16 hugo_saca_056[484] = {
    L6(1, 0, 846, 0, 0, 0, 0, 0x2558, 0, 24, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2559, -60, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255A, 60, 161, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255B, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x255C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x255D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x255E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x255F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2560, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2561, 0, 1, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x2572, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2573, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2574, -61, 136, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2575, 61, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2576, 61, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2577, 61, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2578, 61, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2567, -62, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2568, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2569, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x256A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x263C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x263D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x263E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x263F, 0, 165, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2640, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2641, 0, 164, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    CMD(CM_QUAY, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 286, 1, 0, 44, 0, 0x2642, -63, 137, 0, 128, 0, 30, 66, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 44, 0, 0x2642, 9, 166, 0, 128, 0, 30, 70, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 45, 0, 0x2643, 0, 167, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 45, 0, 0x2643, 0, 167, 0, 0, 0, 30, 67, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 46, 0, 0x2643, 0, 167, 0, 0, 0, 30, 69, 0, 0, 0, 0, 0),
    L6(14, 0, 0, 1, 0, 46, 0, 0x2643, 0, 167, 0, 0, 0, 30, 68, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 1, 0, 47, 0, 0x2645, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 0, 0, 0x25FB, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 0, 0, 0x25FC, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 hugo_saca_057_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_saca_057[408] = {
    CMD(CM_EXEC, 55, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B0, 0, 153, 0, 0, 0, 21, 0),
    L4(4, 0, 845, 0, 0, 0, 0, 0x26B1, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x26B2, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 40, 0, 0, 0, 0, 0, 0x26B3, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26B4, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B5, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B6, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16392), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B0, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B1, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x26B2, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B3, 0, 153, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x26B4, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B5, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B6, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B0, 0, 153, 0, 0, 0, 0, 0),
    L4(5, 0, 841, 0, 0, 0, 0, 0x26B1, 0, 153, 0, 0, 0, 0, 0),
    L4(6, 0, 270, 0, 0, 0, 0, 0x26D0, 0, 154, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26D1, 0, 154, 0, 0, 0, 0, 0),
    L4(6, 30, 0, 0, 0, 0, 0, 0x26D2, 0, 154, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x26D3, 0, 154, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0000, 0x0000, 0x0000,
    L4(3, 0, 0, 0, 0, 0, 0, 0x26E5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x26E6,
    CMD(CM_UJA, 24576, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x26E7, -64, 138, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x26E8,
    CMD(CM_UJA, 24576, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x26E9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x26EA,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x26EB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x26EC,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x26ED, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0500, 0x0000, 0x0000, 0x26EE,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x26E5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x262F,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x2630, 0, 1, 0, 0, 96, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x2631,
    CMD(CM_DUMMY, 8192, 96, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x2631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 60 ATTACK 10 S: not started by a command, 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command, 63 ATTACK 10 SP: not started by a command */
const u16 hugo_saca_060_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 hugo_saca_060[68] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2438, 0, 251, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x244A, 0, 3, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x244B, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25D6, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x25D7, -65, 170, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x25D8, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE) */
const u16 hugo_saca_064_head[4] = { HEAD(4, 0, 25, 10, 0, 1, 61) };
const u16 hugo_saca_064[220] = {
    CMD(CM_CAFR, 2, 7, 33), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 33), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 64, 16), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 32, 52),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 32, 53),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 32, 54),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 190, 0, 0, 0, 39, 2),
    L4(2, 60, 0, 0, 0, 0, 0, 0x2753, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(2, 71, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25F2, -67, 171, 0, 0, 0, 32, 51),
    L4(3, 0, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE) */
const u16 hugo_saca_065_head[4] = { HEAD(4, 0, 27, 10, 0, 1, 61) };
const u16 hugo_saca_065[300] = {
    CMD(CM_CAFR, 2, 7, 34), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 34), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 65, 26), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 32, 52),
    L4(5, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 32, 53),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 32, 54),
    L4(1, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, 0, 190, 0, 0, 0, 22, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 190, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2753, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2755, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2756, 0, 190, 0, 0, 0, 39, 2),
    L4(2, 60, 0, 0, 0, 0, 0, 0x2757, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2750, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2751, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2752, 0, 190, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2753, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2754, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(2, 71, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25F2, -67, 171, 0, 0, 0, 32, 51),
    L4(3, 0, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE), 67 ATTACK 11 SP: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
const u16 hugo_saca_066_head[4] = { HEAD(4, 0, 29, 10, 0, 1, 61) };
const u16 hugo_saca_066[1616] = {
    CMD(CM_CAFR, 2, 7, 35), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 35), 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 66, 29), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 32, 52),
    L4(6, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 32, 53),
    L4(5, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 32, 54),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, 0, 190, 0, 0, 0, 22, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 190, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2753, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2755, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2756, 0, 190, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2757, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2750, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2751, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(4, 60, 291, 0, 0, 0, 0, 0x2752, 0, 190, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2753, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2754, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2755, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2756, 0, 190, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2757, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(2, 71, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25F2, -67, 171, 0, 0, 0, 32, 51),
    L4(4, 0, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0008, 0x0900, 0x013D,
    CMD(CM_CAFR, 2, 7, 33), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 33), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 32, 52),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 32, 53),
    L4(2, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 32, 54),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, -67, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2755, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2756, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2757, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2750, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(4, 21, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0008, 0x0900, 0x013D,
    CMD(CM_CAFR, 2, 7, 34), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 34), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, -67, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2755, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2756, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2757, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2750, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2754, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2755, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(4, 21, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0008, 0x0900, 0x013D,
    CMD(CM_CAFR, 2, 7, 35), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 7, 35), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x25F0, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x2750, -67, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2754, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2755, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(2, 0, 291, 0, 0, 0, 0, 0x2756, 0, 171, 0, 0, 0, 39, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2757, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2750, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2751, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 179, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2752, 0, 171, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2753, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2754, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2755, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 180, 0), 0, 0, 0, 0,
    L4(4, 0, 291, 0, 0, 0, 0, 0x2756, 0, 171, 0, 0, 0, 39, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2757, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 78, 0, 0), 0, 0, 0, 0,
    L4(4, 21, 270, 0, 0, 0, 0, 0x25F6, 0, 151, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F7, 0, 152, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F8, 0, 152, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25F9, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FA, 0, 152, 0, 0, 0, 32, 42),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FB, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000E, 0x0B00, 0x013D,
    CMD(CM_RJA4, 5, 31, 15), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0005, 0x0008, 0x001E, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x266D, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0016, 0x0005, 0x001F, 0x000C,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x266E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x002B, 0x001E, 0x0050, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 291, 0, 0, 0, 0, 0x266F, 0, 1, 0, 0, 0, 39, 2),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x2670,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x2672,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0034, 0x0004, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 50, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 33, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x2674,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(2, 50, 0, 1, 0, 0, 0, 0x2675, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0214, 0x3474, 0x0000, 0x2676,
    CMD(CM_RJA2, 24576, 0, 11009), 0, 0, 0, 0,
    L4(2, 0, 270, 1, 0, 0, 0, 0x2677, -66, 116, 0, 128, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x002B, 0x001E, 0x0051, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16391, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0214, 0x0004, 0x0000, 0x2678,
    CMD(CM_FOR2, -24576, 0, 9987), 0, 0, 0, 0,
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0004, 0x0000, 0x2679,
    CMD(CM_FOR2, -16384, 0, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0004, 0x0000, 0x267A,
    CMD(CM_RJA2, -32768, 0, 5376), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0214, 0x0004, 0x0000, 0x2678,
    CMD(CM_UJA2, -24576, 0, 9987), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x2679, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0004, 0x0000, 0x267A,
    CMD(CM_UJA2, -8192, 0, 0), 0, 0, 0, 0,
    L4(1, 21, 0, 1, 0, 0, 0, 0x267B, 0, 149, 0, 0, 0, 21, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0004, 0x0000, 0x267C,
    CMD(CM_RJA2, -24576, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 1, 0, 0, 0, 0x267D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0004, 0x0000, 0x267E,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 1, 0, 0, 0, 0x2550, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0004, 0x0000, 0x2551,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 1, 0, 0, 0, 0x2552, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0240, 0x0004, 0x0000, 0x2553,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 1, 0, 0, 0, 0x2553, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* combination scripts: 35 entries */
const u16* const hugo_cbca[36] = {
    hugo_cbca_000,  /* 0 APPEAR JUNBI 1 */
    hugo_cbca_001,  /* 1 APPEAR JUNBI 2 */
    hugo_cbca_002,  /* 2 APPEAR JUNBI 3 */
    hugo_cbca_003,  /* 3 APPEAR JUNBI 4 */
    hugo_cbca_004,  /* 4 APPEAR JUNBI 5 */
    hugo_cbca_005,  /* 5 APPEAR JUNBI 6 */
    hugo_cbca_006,  /* 6 APPEAR JUNBI 7 */
    hugo_cbca_007,  /* 7 APPEAR JUNBI 8 */
    hugo_cbca_008,  /* 8 APPEAR 1 */
    hugo_cbca_009,  /* 9 APPEAR 2 */
    hugo_cbca_010,  /* 10 APPEAR 3 */
    hugo_cbca_011,  /* 11 APPEAR 4 */
    hugo_cbca_012,  /* 12 APPEAR 5 */
    hugo_cbca_013,  /* 13 APPEAR 6 */
    hugo_cbca_014,  /* 14 APPEAR 7 */
    hugo_cbca_015,  /* 15 APPEAR 8 */
    hugo_cbca_016,  /* 16 SP APPEAR 1 */
    hugo_cbca_017,  /* 17 SP APPEAR 2 */
    hugo_cbca_018,  /* 18 SP APPEAR 3 */
    hugo_cbca_019,  /* 19 SP APPEAR 4 */
    hugo_cbca_020,  /* 20 SP APPEAR 5 */
    hugo_cbca_021,  /* 21 SP APPEAR 6 */
    hugo_cbca_022,  /* 22 SP APPEAR 7 */
    hugo_cbca_023,  /* 23 SP APPEAR 8 */
    hugo_cbca_024,  /* 24 ZANNEN 1 */
    hugo_cbca_025,  /* 25 ZANNEN 2 */
    hugo_cbca_026,  /* 26 ZANNEN 3 */
    hugo_cbca_027,  /* 27 ZANNEN 4 */
    hugo_cbca_028,  /* 28 ZANNEN 5 */
    hugo_cbca_029,  /* 29 ZANNEN 6 */
    hugo_cbca_030,  /* 30 ZANNEN 7 */
    hugo_cbca_031,  /* 31 ZANNEN 8 */
    hugo_cbca_032,  /* 32 WIN 1 */
    hugo_cbca_033,  /* 33 WIN 2 */
    hugo_cbca_034,  /* 34 WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 hugo_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 hugo_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 hugo_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 hugo_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 hugo_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_004[16] = {
    CMD(CM_RJA, 1, 64, 9),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 hugo_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 hugo_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 hugo_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_007[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 12),
    CMD(CM_CARE, 2, 2, 12),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 hugo_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_008[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 30, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 hugo_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_009[32] = {
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
const u16 hugo_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_010[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 hugo_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 hugo_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_012[16] = {
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 hugo_cbca_013_head[4] = { HEAD(2, 0, 41, 0, 0, 0, 0) };
const u16 hugo_cbca_013[28] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 hugo_cbca_014_head[4] = { HEAD(2, 0, 32, 0, 0, 0, 0) };
const u16 hugo_cbca_014[24] = {
    CMD(CM_RJA4, 5, 52, 8),
    CMD(CM_RJA5, 5, 52, 12),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 hugo_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_015[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 hugo_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_016[12] = {
    CMD(CM_RJA, 4, 89, 12),
    CMD(CM_WSET, 16384, 0, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 hugo_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_017[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 hugo_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_018[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 4),
    CMD(CM_CARE, 2, 1, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 hugo_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_019[16] = {
    CMD(CM_RJA4, 2, 4, 19),
    CMD(CM_RJA5, 2, 8, 7),
    CMD(CM_WSET, 16384, 0, 6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 hugo_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_020[16] = {
    CMD(CM_RJA, 1, 64, 21),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 hugo_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_021[20] = {
    CMD(CM_IFRLF, 1, 16387, 8192),
    CMD(CM_JSR, 8, 20, 1),
    CMD(CM_JMP, 1, 64, 21),
    CMD(CM_JSR, 8, 4, 1),
    CMD(CM_JMP, 1, 64, 9),
};

/* script: 22 SP APPEAR 7 */
const u16 hugo_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_022[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 15, 1),
    CMD(CM_RJA3, 7, 16, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 hugo_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_023[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 hugo_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 46, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 hugo_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_025[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 48, 1),
    CMD(CM_RJA3, 7, 49, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 hugo_cbca_026_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 0) };
const u16 hugo_cbca_026[304] = {
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IF_S, 16384, 8192, 8198), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x266D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x266E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x266F, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2670, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2671, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2672, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 80, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 291, 0, 0, 0, 0, 0x2673, 0, 1, 0, 0, 0, 39, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8192, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x2674, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16384, 8203, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 279, 0, 0, 0, 0, 0x2579, 0, 19, 0, 0, 0, 30, 83, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x257A, 0, 19, 0, 0, 0, 30, 84, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x257B, 0, 20, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x257C, 0, 20, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x257C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 hugo_cbca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_027[68] = {
    CMD(CM_IFRLF, 1, 8192, 16388), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 64, 21), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x24F1, 0, 82, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 hugo_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_028[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 hugo_cbca_029_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 hugo_cbca_029[16] = {
    CMD(CM_EXEC, 49, 42, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 hugo_cbca_030_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 hugo_cbca_030[16] = {
    CMD(CM_EXEC, 49, 43, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 hugo_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_031[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 56, 1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 hugo_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_032[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 57, 1),
    CMD(CM_RJA3, 7, 58, 1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 hugo_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_033[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 59, 1),
    CMD(CM_RJA3, 7, 60, 1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 hugo_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_cbca_034[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 62, 1),
    CMD(CM_RJA3, 7, 63, 1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

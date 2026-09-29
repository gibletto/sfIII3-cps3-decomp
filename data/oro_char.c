/*
 * ORO_CHAR.C  Oro's animation scripts and sprite part tables
 *
 * The animation scripts Oro's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 oro_nmca_000[], oro_nmca_001[], oro_nmca_002[], oro_nmca_003[], oro_nmca_004[], oro_nmca_005[], oro_nmca_006[], oro_nmca_007[], oro_nmca_008[], oro_nmca_011[], oro_nmca_012[], oro_nmca_013[], oro_nmca_014[], oro_nmca_015[], oro_nmca_016[], oro_nmca_017[], oro_nmca_020[], oro_nmca_021[], oro_nmca_022[], oro_nmca_023[], oro_nmca_024[], oro_nmca_026[], oro_nmca_027[], oro_nmca_029[], oro_nmca_030[], oro_nmca_031[], oro_nmca_032[], oro_nmca_033[], oro_nmca_038[], oro_nmca_040[], oro_nmca_041[], oro_nmca_043[], oro_nmca_044[], oro_nmca_045[], oro_nmca_046[], oro_nmca_047[], oro_nmca_048[], oro_nmca_049[], oro_nmca_050[];
extern const u16 oro_nmca_000_head[];
extern const u16 oro_nmca_001_head[];
extern const u16 oro_nmca_002_head[];
extern const u16 oro_nmca_003_head[];
extern const u16 oro_nmca_004_head[];
extern const u16 oro_nmca_005_head[];
extern const u16 oro_nmca_006_head[];
extern const u16 oro_nmca_007_head[];
extern const u16 oro_nmca_008_head[];
extern const u16 oro_nmca_011_head[];
extern const u16 oro_nmca_012_head[];
extern const u16 oro_nmca_013_head[];
extern const u16 oro_nmca_014_head[];
extern const u16 oro_nmca_015_head[];
extern const u16 oro_nmca_016_head[];
extern const u16 oro_nmca_017_head[];
extern const u16 oro_nmca_020_head[];
extern const u16 oro_nmca_021_head[];
extern const u16 oro_nmca_022_head[];
extern const u16 oro_nmca_023_head[];
extern const u16 oro_nmca_024_head[];
extern const u16 oro_nmca_026_head[];
extern const u16 oro_nmca_027_head[];
extern const u16 oro_nmca_029_head[];
extern const u16 oro_nmca_030_head[];
extern const u16 oro_nmca_031_head[];
extern const u16 oro_nmca_032_head[];
extern const u16 oro_nmca_033_head[];
extern const u16 oro_nmca_038_head[];
extern const u16 oro_nmca_040_head[];
extern const u16 oro_nmca_041_head[];
extern const u16 oro_nmca_043_head[];
extern const u16 oro_nmca_044_head[];
extern const u16 oro_nmca_045_head[];
extern const u16 oro_nmca_046_head[];
extern const u16 oro_nmca_047_head[];
extern const u16 oro_nmca_048_head[];
extern const u16 oro_nmca_049_head[];
extern const u16 oro_nmca_050_head[];
extern const u16 oro_dmca_000[], oro_dmca_001[], oro_dmca_002[], oro_dmca_003[], oro_dmca_004[], oro_dmca_006[], oro_dmca_008[], oro_dmca_009[], oro_dmca_010[], oro_dmca_018[], oro_dmca_019[], oro_dmca_014[], oro_dmca_015[], oro_dmca_034[], oro_dmca_022[], oro_dmca_025[], oro_dmca_026[], oro_dmca_024[], oro_dmca_029[], oro_dmca_030[], oro_dmca_036[], oro_dmca_048[], oro_dmca_049[], oro_dmca_050[], oro_dmca_052[], oro_dmca_060[], oro_dmca_064[], oro_dmca_065[], oro_dmca_066[], oro_dmca_067[], oro_dmca_068[], oro_dmca_069[], oro_dmca_070[], oro_dmca_071[], oro_dmca_072[], oro_dmca_073[], oro_dmca_074[], oro_dmca_075[], oro_dmca_076[], oro_dmca_078[], oro_dmca_079[], oro_dmca_080[], oro_dmca_082[], oro_dmca_083[], oro_dmca_084[], oro_dmca_090[], oro_dmca_091[], oro_dmca_096[], oro_dmca_097[];
extern const u16 oro_dmca_000_head[];
extern const u16 oro_dmca_001_head[];
extern const u16 oro_dmca_002_head[];
extern const u16 oro_dmca_003_head[];
extern const u16 oro_dmca_004_head[];
extern const u16 oro_dmca_006_head[];
extern const u16 oro_dmca_008_head[];
extern const u16 oro_dmca_009_head[];
extern const u16 oro_dmca_010_head[];
extern const u16 oro_dmca_018_head[];
extern const u16 oro_dmca_019_head[];
extern const u16 oro_dmca_014_head[];
extern const u16 oro_dmca_015_head[];
extern const u16 oro_dmca_034_head[];
extern const u16 oro_dmca_022_head[];
extern const u16 oro_dmca_025_head[];
extern const u16 oro_dmca_026_head[];
extern const u16 oro_dmca_024_head[];
extern const u16 oro_dmca_029_head[];
extern const u16 oro_dmca_030_head[];
extern const u16 oro_dmca_036_head[];
extern const u16 oro_dmca_048_head[];
extern const u16 oro_dmca_049_head[];
extern const u16 oro_dmca_050_head[];
extern const u16 oro_dmca_052_head[];
extern const u16 oro_dmca_060_head[];
extern const u16 oro_dmca_064_head[];
extern const u16 oro_dmca_065_head[];
extern const u16 oro_dmca_066_head[];
extern const u16 oro_dmca_067_head[];
extern const u16 oro_dmca_068_head[];
extern const u16 oro_dmca_069_head[];
extern const u16 oro_dmca_070_head[];
extern const u16 oro_dmca_071_head[];
extern const u16 oro_dmca_072_head[];
extern const u16 oro_dmca_073_head[];
extern const u16 oro_dmca_074_head[];
extern const u16 oro_dmca_075_head[];
extern const u16 oro_dmca_076_head[];
extern const u16 oro_dmca_078_head[];
extern const u16 oro_dmca_079_head[];
extern const u16 oro_dmca_080_head[];
extern const u16 oro_dmca_082_head[];
extern const u16 oro_dmca_083_head[];
extern const u16 oro_dmca_084_head[];
extern const u16 oro_dmca_090_head[];
extern const u16 oro_dmca_091_head[];
extern const u16 oro_dmca_096_head[];
extern const u16 oro_dmca_097_head[];
extern const u16 oro_btca_000[], oro_btca_001[], oro_btca_002[], oro_btca_003[], oro_btca_004[], oro_btca_005[], oro_btca_006[], oro_btca_007[], oro_btca_008[], oro_btca_009[], oro_btca_010[], oro_btca_011[], oro_btca_012[], oro_btca_013[], oro_btca_014[], oro_btca_015[], oro_btca_016[], oro_btca_017[], oro_btca_018[], oro_btca_019[], oro_btca_020[], oro_btca_021[], oro_btca_022[], oro_btca_023[], oro_btca_025[], oro_btca_026[], oro_btca_027[], oro_btca_028[], oro_btca_029[], oro_btca_030[], oro_btca_031[], oro_btca_032[], oro_btca_033[], oro_btca_034[];
extern const u16 oro_btca_000_head[];
extern const u16 oro_btca_001_head[];
extern const u16 oro_btca_002_head[];
extern const u16 oro_btca_003_head[];
extern const u16 oro_btca_004_head[];
extern const u16 oro_btca_005_head[];
extern const u16 oro_btca_006_head[];
extern const u16 oro_btca_007_head[];
extern const u16 oro_btca_008_head[];
extern const u16 oro_btca_009_head[];
extern const u16 oro_btca_010_head[];
extern const u16 oro_btca_011_head[];
extern const u16 oro_btca_012_head[];
extern const u16 oro_btca_013_head[];
extern const u16 oro_btca_014_head[];
extern const u16 oro_btca_015_head[];
extern const u16 oro_btca_016_head[];
extern const u16 oro_btca_017_head[];
extern const u16 oro_btca_018_head[];
extern const u16 oro_btca_019_head[];
extern const u16 oro_btca_020_head[];
extern const u16 oro_btca_021_head[];
extern const u16 oro_btca_022_head[];
extern const u16 oro_btca_023_head[];
extern const u16 oro_btca_025_head[];
extern const u16 oro_btca_026_head[];
extern const u16 oro_btca_027_head[];
extern const u16 oro_btca_028_head[];
extern const u16 oro_btca_029_head[];
extern const u16 oro_btca_030_head[];
extern const u16 oro_btca_031_head[];
extern const u16 oro_btca_032_head[];
extern const u16 oro_btca_033_head[];
extern const u16 oro_btca_034_head[];
extern const u16 oro_caca_000[], oro_caca_001[], oro_caca_002[], oro_caca_003[], oro_caca_004[], oro_caca_005[], oro_caca_006[], oro_caca_007[], oro_caca_008[], oro_caca_009[], oro_caca_010[], oro_caca_011[], oro_caca_012[], oro_caca_013[], oro_caca_014[];
extern const u16 oro_caca_000_head[];
extern const u16 oro_caca_001_head[];
extern const u16 oro_caca_002_head[];
extern const u16 oro_caca_003_head[];
extern const u16 oro_caca_004_head[];
extern const u16 oro_caca_005_head[];
extern const u16 oro_caca_006_head[];
extern const u16 oro_caca_007_head[];
extern const u16 oro_caca_008_head[];
extern const u16 oro_caca_009_head[];
extern const u16 oro_caca_010_head[];
extern const u16 oro_caca_011_head[];
extern const u16 oro_caca_012_head[];
extern const u16 oro_caca_013_head[];
extern const u16 oro_caca_014_head[];
extern const u16 oro_cuca_000[], oro_cuca_001[], oro_cuca_002[], oro_cuca_003[], oro_cuca_004[], oro_cuca_005[], oro_cuca_006[], oro_cuca_007[], oro_cuca_008[], oro_cuca_009[], oro_cuca_010[], oro_cuca_011[], oro_cuca_012[], oro_cuca_013[], oro_cuca_014[], oro_cuca_015[], oro_cuca_016[], oro_cuca_017[], oro_cuca_018[], oro_cuca_019[], oro_cuca_020[], oro_cuca_021[], oro_cuca_022[], oro_cuca_023[], oro_cuca_024[], oro_cuca_025[], oro_cuca_026[], oro_cuca_027[], oro_cuca_028[], oro_cuca_029[], oro_cuca_030[], oro_cuca_031[], oro_cuca_032[], oro_cuca_033[], oro_cuca_034[], oro_cuca_035[], oro_cuca_036[], oro_cuca_037[], oro_cuca_038[], oro_cuca_039[], oro_cuca_040[], oro_cuca_041[], oro_cuca_042[], oro_cuca_043[], oro_cuca_044[], oro_cuca_045[], oro_cuca_046[], oro_cuca_047[], oro_cuca_048[], oro_cuca_049[], oro_cuca_050[], oro_cuca_051[], oro_cuca_052[], oro_cuca_053[], oro_cuca_054[], oro_cuca_055[], oro_cuca_056[], oro_cuca_057[], oro_cuca_058[], oro_cuca_059[], oro_cuca_060[], oro_cuca_061[], oro_cuca_062[], oro_cuca_063[], oro_cuca_064[], oro_cuca_065[], oro_cuca_066[], oro_cuca_067[];
extern const u16 oro_cuca_000_head[];
extern const u16 oro_cuca_001_head[];
extern const u16 oro_cuca_002_head[];
extern const u16 oro_cuca_003_head[];
extern const u16 oro_cuca_004_head[];
extern const u16 oro_cuca_005_head[];
extern const u16 oro_cuca_006_head[];
extern const u16 oro_cuca_007_head[];
extern const u16 oro_cuca_008_head[];
extern const u16 oro_cuca_009_head[];
extern const u16 oro_cuca_010_head[];
extern const u16 oro_cuca_011_head[];
extern const u16 oro_cuca_012_head[];
extern const u16 oro_cuca_013_head[];
extern const u16 oro_cuca_014_head[];
extern const u16 oro_cuca_015_head[];
extern const u16 oro_cuca_016_head[];
extern const u16 oro_cuca_017_head[];
extern const u16 oro_cuca_018_head[];
extern const u16 oro_cuca_019_head[];
extern const u16 oro_cuca_020_head[];
extern const u16 oro_cuca_021_head[];
extern const u16 oro_cuca_022_head[];
extern const u16 oro_cuca_023_head[];
extern const u16 oro_cuca_024_head[];
extern const u16 oro_cuca_025_head[];
extern const u16 oro_cuca_026_head[];
extern const u16 oro_cuca_027_head[];
extern const u16 oro_cuca_028_head[];
extern const u16 oro_cuca_029_head[];
extern const u16 oro_cuca_030_head[];
extern const u16 oro_cuca_031_head[];
extern const u16 oro_cuca_032_head[];
extern const u16 oro_cuca_033_head[];
extern const u16 oro_cuca_034_head[];
extern const u16 oro_cuca_035_head[];
extern const u16 oro_cuca_036_head[];
extern const u16 oro_cuca_037_head[];
extern const u16 oro_cuca_038_head[];
extern const u16 oro_cuca_039_head[];
extern const u16 oro_cuca_040_head[];
extern const u16 oro_cuca_041_head[];
extern const u16 oro_cuca_042_head[];
extern const u16 oro_cuca_043_head[];
extern const u16 oro_cuca_044_head[];
extern const u16 oro_cuca_045_head[];
extern const u16 oro_cuca_046_head[];
extern const u16 oro_cuca_047_head[];
extern const u16 oro_cuca_048_head[];
extern const u16 oro_cuca_049_head[];
extern const u16 oro_cuca_050_head[];
extern const u16 oro_cuca_051_head[];
extern const u16 oro_cuca_052_head[];
extern const u16 oro_cuca_053_head[];
extern const u16 oro_cuca_054_head[];
extern const u16 oro_cuca_055_head[];
extern const u16 oro_cuca_056_head[];
extern const u16 oro_cuca_057_head[];
extern const u16 oro_cuca_058_head[];
extern const u16 oro_cuca_059_head[];
extern const u16 oro_cuca_060_head[];
extern const u16 oro_cuca_061_head[];
extern const u16 oro_cuca_062_head[];
extern const u16 oro_cuca_063_head[];
extern const u16 oro_cuca_064_head[];
extern const u16 oro_cuca_065_head[];
extern const u16 oro_cuca_066_head[];
extern const u16 oro_cuca_067_head[];
extern const u16 oro_atca_000[], oro_atca_001[], oro_atca_003[], oro_atca_004[], oro_atca_005[], oro_atca_006[], oro_atca_009[], oro_atca_010[], oro_atca_012[], oro_atca_013[], oro_atca_015[], oro_atca_018[], oro_atca_021[], oro_atca_024[], oro_atca_027[], oro_atca_030[], oro_atca_033[], oro_atca_036[], oro_atca_038[], oro_atca_040[], oro_atca_042[], oro_atca_044[], oro_atca_046[], oro_atca_048[], oro_atca_050[], oro_atca_052[], oro_atca_054[], oro_atca_056[], oro_atca_057[], oro_atca_058[], oro_atca_060[], oro_atca_062[], oro_atca_064[], oro_atca_066[], oro_atca_068[], oro_atca_070[], oro_atca_072[], oro_atca_074[], oro_atca_076[], oro_atca_078[], oro_atca_080[], oro_atca_082[], oro_atca_084[], oro_atca_086[], oro_atca_088[], oro_atca_090[], oro_atca_092[], oro_atca_094[], oro_atca_096[], oro_atca_098[], oro_atca_100[], oro_atca_102[], oro_atca_104[], oro_atca_106[], oro_atca_108[], oro_atca_110[], oro_atca_112[], oro_atca_114[], oro_atca_116[], oro_atca_118[], oro_atca_144[], oro_atca_146[], oro_atca_150[], oro_atca_156[], oro_atca_157[], oro_atca_158[], oro_atca_159[], oro_atca_160[];
extern const u16 oro_atca_000_head[];
extern const u16 oro_atca_001_head[];
extern const u16 oro_atca_003_head[];
extern const u16 oro_atca_004_head[];
extern const u16 oro_atca_005_head[];
extern const u16 oro_atca_006_head[];
extern const u16 oro_atca_009_head[];
extern const u16 oro_atca_010_head[];
extern const u16 oro_atca_012_head[];
extern const u16 oro_atca_013_head[];
extern const u16 oro_atca_015_head[];
extern const u16 oro_atca_018_head[];
extern const u16 oro_atca_021_head[];
extern const u16 oro_atca_024_head[];
extern const u16 oro_atca_027_head[];
extern const u16 oro_atca_030_head[];
extern const u16 oro_atca_033_head[];
extern const u16 oro_atca_036_head[];
extern const u16 oro_atca_038_head[];
extern const u16 oro_atca_040_head[];
extern const u16 oro_atca_042_head[];
extern const u16 oro_atca_044_head[];
extern const u16 oro_atca_046_head[];
extern const u16 oro_atca_048_head[];
extern const u16 oro_atca_050_head[];
extern const u16 oro_atca_052_head[];
extern const u16 oro_atca_054_head[];
extern const u16 oro_atca_056_head[];
extern const u16 oro_atca_057_head[];
extern const u16 oro_atca_058_head[];
extern const u16 oro_atca_060_head[];
extern const u16 oro_atca_062_head[];
extern const u16 oro_atca_064_head[];
extern const u16 oro_atca_066_head[];
extern const u16 oro_atca_068_head[];
extern const u16 oro_atca_070_head[];
extern const u16 oro_atca_072_head[];
extern const u16 oro_atca_074_head[];
extern const u16 oro_atca_076_head[];
extern const u16 oro_atca_078_head[];
extern const u16 oro_atca_080_head[];
extern const u16 oro_atca_082_head[];
extern const u16 oro_atca_084_head[];
extern const u16 oro_atca_086_head[];
extern const u16 oro_atca_088_head[];
extern const u16 oro_atca_090_head[];
extern const u16 oro_atca_092_head[];
extern const u16 oro_atca_094_head[];
extern const u16 oro_atca_096_head[];
extern const u16 oro_atca_098_head[];
extern const u16 oro_atca_100_head[];
extern const u16 oro_atca_102_head[];
extern const u16 oro_atca_104_head[];
extern const u16 oro_atca_106_head[];
extern const u16 oro_atca_108_head[];
extern const u16 oro_atca_110_head[];
extern const u16 oro_atca_112_head[];
extern const u16 oro_atca_114_head[];
extern const u16 oro_atca_116_head[];
extern const u16 oro_atca_118_head[];
extern const u16 oro_atca_144_head[];
extern const u16 oro_atca_146_head[];
extern const u16 oro_atca_150_head[];
extern const u16 oro_atca_156_head[];
extern const u16 oro_atca_157_head[];
extern const u16 oro_atca_158_head[];
extern const u16 oro_atca_159_head[];
extern const u16 oro_atca_160_head[];
extern const u16 oro_exca_000[], oro_exca_001[], oro_exca_003[], oro_exca_004[], oro_exca_005[], oro_exca_006[], oro_exca_007[], oro_exca_008[], oro_exca_009[], oro_exca_010[], oro_exca_011[], oro_exca_013[], oro_exca_014[], oro_exca_015[], oro_exca_016[], oro_exca_017[], oro_exca_018[], oro_exca_019[], oro_exca_020[], oro_exca_021[], oro_exca_022[], oro_exca_023[], oro_exca_025[], oro_exca_027[], oro_exca_028[], oro_exca_030[], oro_exca_031[], oro_exca_032[], oro_exca_033[], oro_exca_034[], oro_exca_035[], oro_exca_036[], oro_exca_037[], oro_exca_038[], oro_exca_039[], oro_exca_040[], oro_exca_041[], oro_exca_042[], oro_exca_043[], oro_exca_046[], oro_exca_047[], oro_exca_048[];
extern const u16 oro_exca_000_head[];
extern const u16 oro_exca_001_head[];
extern const u16 oro_exca_003_head[];
extern const u16 oro_exca_004_head[];
extern const u16 oro_exca_005_head[];
extern const u16 oro_exca_006_head[];
extern const u16 oro_exca_007_head[];
extern const u16 oro_exca_008_head[];
extern const u16 oro_exca_009_head[];
extern const u16 oro_exca_010_head[];
extern const u16 oro_exca_011_head[];
extern const u16 oro_exca_013_head[];
extern const u16 oro_exca_014_head[];
extern const u16 oro_exca_015_head[];
extern const u16 oro_exca_016_head[];
extern const u16 oro_exca_017_head[];
extern const u16 oro_exca_018_head[];
extern const u16 oro_exca_019_head[];
extern const u16 oro_exca_020_head[];
extern const u16 oro_exca_021_head[];
extern const u16 oro_exca_022_head[];
extern const u16 oro_exca_023_head[];
extern const u16 oro_exca_025_head[];
extern const u16 oro_exca_027_head[];
extern const u16 oro_exca_028_head[];
extern const u16 oro_exca_030_head[];
extern const u16 oro_exca_031_head[];
extern const u16 oro_exca_032_head[];
extern const u16 oro_exca_033_head[];
extern const u16 oro_exca_034_head[];
extern const u16 oro_exca_035_head[];
extern const u16 oro_exca_036_head[];
extern const u16 oro_exca_037_head[];
extern const u16 oro_exca_038_head[];
extern const u16 oro_exca_039_head[];
extern const u16 oro_exca_040_head[];
extern const u16 oro_exca_041_head[];
extern const u16 oro_exca_042_head[];
extern const u16 oro_exca_043_head[];
extern const u16 oro_exca_046_head[];
extern const u16 oro_exca_047_head[];
extern const u16 oro_exca_048_head[];
extern const u16 oro_saca_000[], oro_saca_001[], oro_saca_002[], oro_saca_024[], oro_saca_025[], oro_saca_026[], oro_saca_028[], oro_saca_032[], oro_saca_033[], oro_saca_034[], oro_saca_035[], oro_saca_036[], oro_saca_037[], oro_saca_038[], oro_saca_039[], oro_saca_040[], oro_saca_041[], oro_saca_042[], oro_saca_043[], oro_saca_044[], oro_saca_047[], oro_saca_048[], oro_saca_049[], oro_saca_050[], oro_saca_051[], oro_saca_052[], oro_saca_055[], oro_saca_056[], oro_saca_057[], oro_saca_060[], oro_saca_061[], oro_saca_062[], oro_saca_063[], oro_saca_064[], oro_saca_065[], oro_saca_066[], oro_saca_070[], oro_saca_073[];
extern const u16 oro_saca_000_head[];
extern const u16 oro_saca_001_head[];
extern const u16 oro_saca_002_head[];
extern const u16 oro_saca_024_head[];
extern const u16 oro_saca_025_head[];
extern const u16 oro_saca_026_head[];
extern const u16 oro_saca_028_head[];
extern const u16 oro_saca_032_head[];
extern const u16 oro_saca_033_head[];
extern const u16 oro_saca_034_head[];
extern const u16 oro_saca_035_head[];
extern const u16 oro_saca_036_head[];
extern const u16 oro_saca_037_head[];
extern const u16 oro_saca_038_head[];
extern const u16 oro_saca_039_head[];
extern const u16 oro_saca_040_head[];
extern const u16 oro_saca_041_head[];
extern const u16 oro_saca_042_head[];
extern const u16 oro_saca_043_head[];
extern const u16 oro_saca_044_head[];
extern const u16 oro_saca_047_head[];
extern const u16 oro_saca_048_head[];
extern const u16 oro_saca_049_head[];
extern const u16 oro_saca_050_head[];
extern const u16 oro_saca_051_head[];
extern const u16 oro_saca_052_head[];
extern const u16 oro_saca_055_head[];
extern const u16 oro_saca_056_head[];
extern const u16 oro_saca_057_head[];
extern const u16 oro_saca_060_head[];
extern const u16 oro_saca_061_head[];
extern const u16 oro_saca_062_head[];
extern const u16 oro_saca_063_head[];
extern const u16 oro_saca_064_head[];
extern const u16 oro_saca_065_head[];
extern const u16 oro_saca_066_head[];
extern const u16 oro_saca_070_head[];
extern const u16 oro_saca_073_head[];
extern const u16 oro_cbca_000[], oro_cbca_001[], oro_cbca_002[], oro_cbca_003[], oro_cbca_004[], oro_cbca_005[], oro_cbca_006[], oro_cbca_007[], oro_cbca_008[], oro_cbca_009[], oro_cbca_010[], oro_cbca_011[], oro_cbca_012[], oro_cbca_013[], oro_cbca_014[], oro_cbca_015[], oro_cbca_016[], oro_cbca_017[], oro_cbca_018[], oro_cbca_019[], oro_cbca_020[], oro_cbca_021[], oro_cbca_022[], oro_cbca_023[], oro_cbca_024[], oro_cbca_025[], oro_cbca_026[], oro_cbca_027[], oro_cbca_028[], oro_cbca_029[], oro_cbca_030[], oro_cbca_031[], oro_cbca_032[], oro_cbca_033[], oro_cbca_034[], oro_cbca_035[], oro_cbca_036[], oro_cbca_037[], oro_cbca_038[], oro_cbca_039[], oro_cbca_040[], oro_cbca_041[], oro_cbca_042[], oro_cbca_043[], oro_cbca_044[], oro_cbca_045[], oro_cbca_046[], oro_cbca_047[], oro_cbca_048[], oro_cbca_049[], oro_cbca_050[], oro_cbca_051[], oro_cbca_052[], oro_cbca_053[], oro_cbca_054[];
extern const u16 oro_cbca_000_head[];
extern const u16 oro_cbca_001_head[];
extern const u16 oro_cbca_002_head[];
extern const u16 oro_cbca_003_head[];
extern const u16 oro_cbca_004_head[];
extern const u16 oro_cbca_005_head[];
extern const u16 oro_cbca_006_head[];
extern const u16 oro_cbca_007_head[];
extern const u16 oro_cbca_008_head[];
extern const u16 oro_cbca_009_head[];
extern const u16 oro_cbca_010_head[];
extern const u16 oro_cbca_011_head[];
extern const u16 oro_cbca_012_head[];
extern const u16 oro_cbca_013_head[];
extern const u16 oro_cbca_014_head[];
extern const u16 oro_cbca_015_head[];
extern const u16 oro_cbca_016_head[];
extern const u16 oro_cbca_017_head[];
extern const u16 oro_cbca_018_head[];
extern const u16 oro_cbca_019_head[];
extern const u16 oro_cbca_020_head[];
extern const u16 oro_cbca_021_head[];
extern const u16 oro_cbca_022_head[];
extern const u16 oro_cbca_023_head[];
extern const u16 oro_cbca_024_head[];
extern const u16 oro_cbca_025_head[];
extern const u16 oro_cbca_026_head[];
extern const u16 oro_cbca_027_head[];
extern const u16 oro_cbca_028_head[];
extern const u16 oro_cbca_029_head[];
extern const u16 oro_cbca_030_head[];
extern const u16 oro_cbca_031_head[];
extern const u16 oro_cbca_032_head[];
extern const u16 oro_cbca_033_head[];
extern const u16 oro_cbca_034_head[];
extern const u16 oro_cbca_035_head[];
extern const u16 oro_cbca_036_head[];
extern const u16 oro_cbca_037_head[];
extern const u16 oro_cbca_038_head[];
extern const u16 oro_cbca_039_head[];
extern const u16 oro_cbca_040_head[];
extern const u16 oro_cbca_041_head[];
extern const u16 oro_cbca_042_head[];
extern const u16 oro_cbca_043_head[];
extern const u16 oro_cbca_044_head[];
extern const u16 oro_cbca_045_head[];
extern const u16 oro_cbca_046_head[];
extern const u16 oro_cbca_047_head[];
extern const u16 oro_cbca_048_head[];
extern const u16 oro_cbca_049_head[];
extern const u16 oro_cbca_050_head[];
extern const u16 oro_cbca_051_head[];
extern const u16 oro_cbca_052_head[];
extern const u16 oro_cbca_053_head[];
extern const u16 oro_cbca_054_head[];

/* normal scripts: 51 entries */
const u16* const oro_nmca[52] = {
    oro_nmca_000,  /* 0 KAMAE */
    oro_nmca_001,  /* 1 HURIMUKI */
    oro_nmca_002,  /* 2 FRONT WALK */
    oro_nmca_003,  /* 3 BACK WALK */
    oro_nmca_004,  /* 4 DASH HUMIKOMI */
    oro_nmca_005,  /* 5 DASH TOBINOKI */
    oro_nmca_006,  /* 6 KAGAMU */
    oro_nmca_007,  /* 7 KAGAMI KAMAE */
    oro_nmca_008,  /* 8 KAGAMI TURN */
    oro_nmca_008,  /* 9 KAGAMI F WALK */
    oro_nmca_008,  /* 10 KAGAMI B WALK */
    oro_nmca_011,  /* 11 STAND UP */
    oro_nmca_012,  /* 12 JUMP JUNBI */
    oro_nmca_013,  /* 13 SP JUMP JUNBI */
    oro_nmca_014,  /* 14 JUMP FRONT */
    oro_nmca_015,  /* 15 JUMP VERTICAL */
    oro_nmca_016,  /* 16 JUMP BACK */
    oro_nmca_017,  /* 17 S JUMP FRONT */
    oro_nmca_017,  /* 18 S JUMP V */
    oro_nmca_017,  /* 19 S JUMP BACK */
    oro_nmca_020,  /* 20 SP JUMP FRONT */
    oro_nmca_021,  /* 21 SP JUMP V */
    oro_nmca_022,  /* 22 SP JUMP BACK */
    oro_nmca_023,  /* 23 WALK END */
    oro_nmca_024,  /* 24 PARING HEAD */
    oro_nmca_024,  /* 25 PARING UP */
    oro_nmca_026,  /* 26 PARING DOWN */
    oro_nmca_027,  /* 27 PARING AIR F */
    oro_nmca_027,  /* 28 PARING AIR B */
    oro_nmca_029,  /* 29 GUARD HEAD */
    oro_nmca_030,  /* 30 GUARD UP */
    oro_nmca_031,  /* 31 GUARD DOWN */
    oro_nmca_032,  /* 32 GUARD AIR */
    oro_nmca_033,  /* 33 no name */
    oro_nmca_033,  /* 34 no name */
    oro_nmca_033,  /* 35 no name */
    oro_nmca_033,  /* 36 no name */
    oro_nmca_033,  /* 37 no name */
    oro_nmca_038,  /* 38 P BREAK ZUJOU */
    oro_nmca_038,  /* 39 P BREAK UP */
    oro_nmca_040,  /* 40 P BREAK DOWN */
    oro_nmca_041,  /* 41 P BREAK AIR F */
    oro_nmca_041,  /* 42 P BREAK AIR R */
    oro_nmca_043,  /* 43 TUKAMIHAZUSI */
    oro_nmca_044,  /* 44 TUKAMIHAZUSARE */
    oro_nmca_045,  /* 45 TUKAMIHAZUSI */
    oro_nmca_046,  /* 46 TUKAMIHAZUSARE */
    oro_nmca_047,  /* 47 no name */
    oro_nmca_048,  /* 48 no name */
    oro_nmca_049,  /* 49 no name */
    oro_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 oro_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_000[428] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3940, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3941, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3942, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3943, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3944, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3945, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3946, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3947, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3944, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3945, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3946, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3947, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3948, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3949, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x394F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3950, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3951, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3952, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3953, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3954, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3955, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3956, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3957, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3958, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3959, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x395F, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3964, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3961, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3962, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3963, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3964, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3965, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3966, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3967, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3968, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3969, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x396F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 oro_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_001[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x360D, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x360E, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x360F, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3610, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3611, 0, 265, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3612, 0, 265, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 oro_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 oro_nmca_002[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3620, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3621, 0, 266, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3622, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3623, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3624, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3625, 0, 268, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3626, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3627, 0, 268, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 oro_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 oro_nmca_003[76] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3628, 0, 266, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3629, 0, 266, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x362A, 0, 267, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x362B, 0, 267, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x362C, 0, 267, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x362D, 0, 268, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x362E, 0, 268, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x362F, 0, 268, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 oro_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 oro_nmca_004[184] = {
    CMD(CM_RJA, 0, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3672, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 277, 0, 0, 0, 0, 0x3673, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 1, 0, 0, 0, 0, 0, 0x3674, 0, 280, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3675, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3676, 0, 282, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3677, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3678, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3639, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363A, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 544, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 oro_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 oro_nmca_005[172] = {
    CMD(CM_RJA, 0, 5, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3630, 0, 285, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 1, 277, 0, 0, 0, 0, 0x3679, 0, 285, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x367B, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x367C, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3638, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3639, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363A, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 oro_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_nmca_006[60] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3630, 0, 269, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3631, 0, 269, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 oro_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_nmca_007[204] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x3970, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3971, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3972, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3973, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3974, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3975, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3976, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3977, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3978, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3979, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397A, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397B, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397C, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397D, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397E, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x397F, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3980, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3981, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3982, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3983, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3984, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3985, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3986, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3987, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 oro_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_nmca_008[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3648, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3649, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x364A, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 oro_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_nmca_011[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3637, 0, 271, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3638, 0, 271, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3639, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363A, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 272, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 272, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 oro_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_012[28] = {
    L4(2, 1, 281, 0, 0, 0, 0, 0x3637, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3637, 0, 207, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3637, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 oro_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_013[20] = {
    L4(5, 0, 282, 0, 0, 0, 0, 0x3632, 0, 207, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3632, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 oro_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_nmca_014[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x365A, 0, 273, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x365B, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x365C, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x365D, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x365E, 0, 274, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x365F, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x3660, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x3661, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x3662, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 oro_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 oro_nmca_015[132] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x3650, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3652, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3652, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3653, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3654, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3655, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3656, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 oro_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_nmca_016[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3666, 0, 276, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3667, 0, 276, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x3668, 0, 276, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3669, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x366A, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x366B, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x366C, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x366D, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x366E, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 oro_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 oro_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 oro_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 oro_nmca_020[124] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x365A, 0, 273, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x365B, 0, 273, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x365C, 0, 273, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x365D, 0, 273, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x365E, 0, 274, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 10, 0x365F, 0, 274, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x3660, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x3661, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x3662, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3663, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 oro_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 oro_nmca_021[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x3650, 0, 15, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3652, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3652, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3651, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3653, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3654, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3655, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3656, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 oro_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 oro_nmca_022[124] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3666, 0, 276, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3667, 0, 276, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x3668, 0, 276, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3669, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x366A, 0, 274, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 10, 0x366B, 0, 275, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 9, 0x366C, 0, 275, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 7, 0x366D, 0, 275, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x366E, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 oro_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_023[20] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x396F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 oro_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 oro_nmca_024[60] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 584, 0, 0, 0, 0, 0x3851, 0, 1, 0, 0, 0, 6, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3930, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3931, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 oro_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 oro_nmca_026[52] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x3859, 0, 109, 0, 0, 0, 18, 6),
    L4(2, 0, 584, 0, 0, 0, 0, 0x3A73, 0, 109, 0, 0, 0, 6, 1),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3A74, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 oro_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_nmca_027[180] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x385D, 0, 14, 0, 0, 0, 18, 6),
    L4(2, 0, 584, 0, 0, 0, 0, 0x3A76, 0, 14, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3A77, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3660, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3661, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3663, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x385D, 0, 14, 0, 0, 0, 18, 6),
    L4(3, 0, 584, 0, 0, 0, 0, 0x385E, 0, 14, 0, 0, 0, 6, 2),
    L4(17, 3, 0, 0, 0, 0, 0, 0x385F, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x366C, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 oro_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 oro_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3855, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 oro_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 oro_nmca_030[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3851, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3852, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 oro_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 oro_nmca_031[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3859, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x385A, 0, 109, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x385B, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x37C7, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 oro_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 oro_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x385D, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x385E, 0, 14, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x385F, 0, 14, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x385F, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 oro_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 oro_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3669, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 oro_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_038[100] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3852, 0, 6, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3853, 0, 5, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4608, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3860, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 oro_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_nmca_040[92] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x385A, 0, 109, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x385B, 0, 109, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3865, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 oro_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x385D, 0, 14, 0, 0, 0, 18, 8),
    L4(250, 0, 584, 0, 0, 0, 0, 0x385E, 0, 14, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 oro_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_043[100] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3852, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3853, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4608, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3860, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 oro_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_044[92] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x3A6B, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3A6C, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3A6D, 0, 256, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x3A6E, 0, 256, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x3A6F, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 oro_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_nmca_045[108] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x385D, 0, 14, 0, 0, 0, 0, 0),
    L4(250, 0, 584, 0, 0, 0, 0, 0x385E, 0, 14, 0, 0, 0, 25, 2),
    L4(3, 1, 0, 0, 0, 0, 0, 0x366A, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 oro_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_nmca_046[92] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 133, 0, 0, 0, 0, 0, 0x3A61, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3A66, 0, 258, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3A67, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3A68, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A69, 0, 258, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 oro_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3940, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 oro_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x3601, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3601, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3601, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 oro_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3829, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A71, 0, 14, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3A71, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 oro_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_nmca_050[100] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3852, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3853, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4608, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3860, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const oro_dmca[99] = {
    oro_dmca_000,  /* 0 GUARD HEAD */
    oro_dmca_001,  /* 1 GUARD UP */
    oro_dmca_002,  /* 2 GUARD DOWN */
    oro_dmca_003,  /* 3 GUARD AIR */
    oro_dmca_004,  /* 4 HUSHIN HEAD */
    oro_dmca_004,  /* 5 HUSHIN UP */
    oro_dmca_006,  /* 6 HUSHIN DOWN */
    oro_dmca_006,  /* 7 HUSHIN AIR */
    oro_dmca_008,  /* 8 FACE S */
    oro_dmca_009,  /* 9 FACE M */
    oro_dmca_010,  /* 10 FACE L */
    oro_dmca_010,  /* 11 FACE SP */
    oro_dmca_008,  /* 12 FOOK OKU S */
    oro_dmca_009,  /* 13 FOOK OKU M */
    oro_dmca_014,  /* 14 FOOK OKU L */
    oro_dmca_015,  /* 15 FOOK OKU SP */
    oro_dmca_008,  /* 16 FOOK TEMAE S */
    oro_dmca_009,  /* 17 FOOK TEMAE M */
    oro_dmca_018,  /* 18 FOOK TEMAE L */
    oro_dmca_019,  /* 19 FOOK TEMAE SP */
    oro_dmca_008,  /* 20 UPPER S */
    oro_dmca_009,  /* 21 UPPER M */
    oro_dmca_022,  /* 22 UPPER L */
    oro_dmca_022,  /* 23 UPPER SP */
    oro_dmca_024,  /* 24 NOUTEN S */
    oro_dmca_025,  /* 25 NOUTEN M */
    oro_dmca_026,  /* 26 NOUTEN L */
    oro_dmca_026,  /* 27 NOUTEN SP */
    oro_dmca_024,  /* 28 BODY BROW S */
    oro_dmca_029,  /* 29 BODY BROW M */
    oro_dmca_030,  /* 30 BODY BROW L */
    oro_dmca_030,  /* 31 BODY BROW SP */
    oro_dmca_024,  /* 32 BODY UPPER S */
    oro_dmca_029,  /* 33 BODY UPPER M */
    oro_dmca_034,  /* 34 BODY UPPER L */
    oro_dmca_034,  /* 35 BODY UPPER SP */
    oro_dmca_036,  /* 36 TATAKI S */
    oro_dmca_036,  /* 37 TATAKI M */
    oro_dmca_036,  /* 38 TATAKI L */
    oro_dmca_036,  /* 39 TATAKI SP */
    oro_dmca_036,  /* 40 TATAKI V. S */
    oro_dmca_036,  /* 41 TATAKI V. M */
    oro_dmca_036,  /* 42 TATAKI V. L */
    oro_dmca_036,  /* 43 TATAKI V. SP */
    oro_dmca_008,  /* 44 NOBASITA TE S */
    oro_dmca_009,  /* 45 NOBASITA TE M */
    oro_dmca_010,  /* 46 NOBASITA TE L */
    oro_dmca_010,  /* 47 NOBASITA TE SP */
    oro_dmca_048,  /* 48 KAGAMI S */
    oro_dmca_049,  /* 49 KAGAMI M */
    oro_dmca_050,  /* 50 KAGAMI L */
    oro_dmca_050,  /* 51 KAGAMI SP */
    oro_dmca_052,  /* 52 KGM TATAKI S */
    oro_dmca_052,  /* 53 KGM TATAKI M */
    oro_dmca_052,  /* 54 KGM TATAKI L */
    oro_dmca_052,  /* 55 KGM TATAKI SP */
    oro_dmca_052,  /* 56 KGM TTKI V.S */
    oro_dmca_052,  /* 57 KGM TTKI V.M */
    oro_dmca_052,  /* 58 KGM TTKI V.L */
    oro_dmca_052,  /* 59 KGM TTKI V.SP */
    oro_dmca_060,  /* 60 NEKOROBI S */
    oro_dmca_060,  /* 61 NEKOROBI M */
    oro_dmca_060,  /* 62 NEKOROBI L */
    oro_dmca_060,  /* 63 NEKOROBI SP */
    oro_dmca_064,  /* 64 OKIAGARI */
    oro_dmca_065,  /* 65 OKIAGARI F */
    oro_dmca_066,  /* 66 OKIAGARI B */
    oro_dmca_067,  /* 67 LOSE NO STAND */
    oro_dmca_068,  /* 68 LOSE SONABA */
    oro_dmca_069,  /* 69 LOSE KAGAMI */
    oro_dmca_070,  /* 70 PIYO */
    oro_dmca_071,  /* 71 UKEMI MOVE F */
    oro_dmca_072,  /* 72 UKEMI MOVE R */
    oro_dmca_073,  /* 73 SHIMEOTASARE */
    oro_dmca_074,  /* 74 TATI TOUKETU S */
    oro_dmca_075,  /* 75 TATI TOUKETU M */
    oro_dmca_076,  /* 76 TATI TOUKETU L */
    oro_dmca_076,  /* 77 TATI TOUKETU P */
    oro_dmca_078,  /* 78 KGM TOUKETU S */
    oro_dmca_079,  /* 79 KGM TOUKETU M */
    oro_dmca_080,  /* 80 KGM TOUKETU L */
    oro_dmca_080,  /* 81 KGM TOUKETU P */
    oro_dmca_082,  /* 82 TATI DENGEKI S */
    oro_dmca_083,  /* 83 TATI DENGEKI M */
    oro_dmca_084,  /* 84 TATI DENGEKI L */
    oro_dmca_084,  /* 85 TATI DENGEKI P */
    oro_dmca_082,  /* 86 KGM DENGEKI S */
    oro_dmca_083,  /* 87 KGM DENGEKI M */
    oro_dmca_084,  /* 88 KGM DENGEKI L */
    oro_dmca_084,  /* 89 KGM DENGEKI P */
    oro_dmca_090,  /* 90 OKIAGARI FRONT */
    oro_dmca_091,  /* 91 OKIAGARI REAR */
    oro_dmca_008,  /* 92 TATI MOE S */
    oro_dmca_009,  /* 93 TATI MOE M */
    oro_dmca_010,  /* 94 TATI MOE L */
    oro_dmca_010,  /* 95 TATI MOE SP */
    oro_dmca_096,  /* 96 no name */
    oro_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 oro_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_000[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x3856, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3857, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x3858, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 oro_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_001[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x3852, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3853, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x3854, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3852, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 oro_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x385B, 0, 109, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x385C, 0, 109, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x385A, 0, 109, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x385B, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 109, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 109, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 oro_dmca_003_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 oro_dmca_003[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x385D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(3, 139, 0, 0, 0, 0, 0, 0x385E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x385F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(250, 132, 0, 0, 0, 0, 0, 0x3854, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3852, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3850, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3826, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3827, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3828, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 14, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 oro_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_004[76] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3852, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3853, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3860, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 oro_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_006[76] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x385B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x385C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3865, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3861, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3862, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3863, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3864, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x367A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 oro_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_008[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3680, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 133, 0, 0, 0, 0, 0, 0x3681, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3682, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 oro_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_009[84] = {
    L4(250, 130, 578, 0, 0, 0, 0, 0x3681, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x3684, 0, 184, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3685, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3681, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3682, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 oro_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_010[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3688, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 140, 578, 0, 0, 0, 0, 0x3688, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3688, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3689, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x368A, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x368B, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x368C, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x368D, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x360E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x360F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3610, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 oro_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_018[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3691, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 138, 578, 0, 0, 0, 0, 0x3691, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3692, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3693, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x368B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x368C, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3694, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x368D, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x360E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x360F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3610, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 oro_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_019[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3690, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 138, 578, 0, 0, 0, 0, 0x3691, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3692, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3693, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x368B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x368C, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3694, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x368D, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x360E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x360F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3610, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 oro_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_014[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3688, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 139, 578, 0, 0, 0, 0, 0x3688, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3688, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3689, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x368A, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x368B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x368C, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3694, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x368D, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x360E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x360F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3610, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 oro_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_015[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3686, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 139, 578, 0, 0, 0, 0, 0x3687, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3688, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3689, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x368A, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x368B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x368C, 0, 186, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3694, 0, 186, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x368D, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x360E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x360F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3610, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 oro_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x369B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 135, 578, 0, 0, 0, 0, 0x369B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x369C, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x369D, 0, 180, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x369E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x369F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36A0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36A1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36A2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 oro_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_022[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36FA, 0, 179, 0, 0, 0, 0, 0),
    L4(3, 139, 578, 0, 0, 0, 0, 0x36FA, 0, 179, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A3, 0, 180, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x369C, 0, 180, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x369D, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x369E, 0, 182, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x369F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36A0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36A1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x36A2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 oro_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_025[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3695, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 136, 578, 0, 0, 0, 0, 0x3696, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3697, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3696, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3698, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3699, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x369A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 oro_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_026[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3696, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 136, 578, 0, 0, 0, 0, 0x3696, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3697, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3696, 0, 189, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3698, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3699, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x369A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 oro_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_024[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36C0, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 133, 0, 0, 0, 0, 0, 0x36C1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 oro_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_029[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36C3, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 134, 578, 0, 0, 0, 0, 0x36C4, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36C5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36C1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 oro_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_030[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36C6, 0, 187, 0, 0, 0, 0, 0),
    L4(1, 137, 578, 0, 0, 0, 0, 0x36C7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36C8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36C9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36CB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36CC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36CD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 oro_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_036[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36F6, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 578, 0, 0, 0, 0, 0x36F7, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 oro_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_048[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36D0, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 133, 0, 0, 0, 0, 0, 0x36D1, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 oro_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_049[84] = {
    L4(250, 130, 578, 0, 0, 0, 0, 0x36D9, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 135, 0, 0, 0, 0, 0, 0x36D5, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36D5, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36D1, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 oro_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_050[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36D9, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 138, 578, 0, 0, 0, 0, 0x36D9, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36D9, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36DA, 0, 193, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36DB, 0, 194, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x36DC, 0, 193, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36DD, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 oro_dmca_052_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_052[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36D7, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 578, 0, 0, 0, 0, 0x36F7, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 oro_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_060[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3736, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 2, 578, 0, 0, 0, 0, 0x3737, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3738, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3739, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36E6, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x36B6, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 166, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B7, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 oro_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_064[156] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3720, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3721, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3722, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3724, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x3725, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3637, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3638, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3638, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 oro_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_065[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3726, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x372F, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 584, 0, 0, 0, 0, 0x3730, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3731, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3732, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3733, 0, 0, 0, 0, 0, 0, 0),
    L4(8, 1, 0, 0, 0, 0, 0, 0x3735, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 oro_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_066[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3726, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3727, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 584, 0, 0, 0, 0, 0x3729, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372D, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x3727, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 oro_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 oro_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_068[196] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x3683, 0, 172, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x3680, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x3711, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3712, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3713, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3714, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3715, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3719, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 288, 0, 0, 0, 0, 0x371A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x371B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x371C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x371D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x371B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x371E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x371F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x371F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 oro_dmca_069_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_069[12] = {
    CMD(CM_JMP, 1, 68, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 oro_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_070[52] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x39E6, 0, 277, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x39E7, 0, 277, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x39E8, 0, 278, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x39E9, 0, 278, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 oro_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_071[68] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3727, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 584, 0, 0, 0, 0, 0x3730, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3731, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3732, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3733, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3735, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 oro_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_072[164] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3726, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 584, 0, 0, 0, 0, 0x3729, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3727, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x3721, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3722, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3724, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x3725, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3637, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3638, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3638, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 oro_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_073[132] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3683, 0, 172, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3680, 0, 172, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3711, 0, 172, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x3712, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3713, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3714, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3715, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3719, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x371A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x371B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x371C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x371D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x371B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x371E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x371F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x371F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 oro_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_074[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3680, 0, 183, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3680, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3681, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3682, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 oro_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_075[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3683, 0, 183, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3683, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3681, 0, 184, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3682, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 oro_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_076[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3686, 0, 183, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3686, 0, 183, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3681, 0, 184, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3682, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 oro_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_078[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36D0, 0, 191, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x36D0, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x36D1, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 oro_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_079[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36D4, 0, 191, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x36D4, 0, 191, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x36D1, 0, 192, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 oro_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_dmca_080[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36D7, 0, 191, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x36D7, 0, 192, 0, 0, 0, 0, 0),
    L4(6, 64, 0, 0, 0, 0, 0, 0x36D1, 0, 193, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D2, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36D3, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 oro_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3936, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3937, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 oro_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3936, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3937, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 oro_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3936, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3935, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3937, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 oro_dmca_090_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_dmca_090[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3726, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x372F, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 0, 0, 0, 0, 0, 0x3730, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3731, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3732, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3733, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x3735, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 oro_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_091[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3726, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3727, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 0, 0, 0, 0, 0, 0x3729, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x372D, 0, 0, 0, 0, 0, 0, 0),
    L4(8, 1, 0, 0, 0, 0, 0, 0x3727, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 oro_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_096[44] = {
    L4(3, 2, 578, 0, 0, 0, 0, 0x36B8, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B8, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x36B8, 0, 166, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 166, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 oro_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_dmca_097[44] = {
    L4(3, 2, 578, 0, 0, 0, 0, 0x36B8, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B8, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x36B8, 0, 107, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 107, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 107, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const oro_btca[37] = {
    oro_btca_000,  /* 0 AIR NORMAL */
    oro_btca_001,  /* 1 ASIBARAI SIRI */
    oro_btca_002,  /* 2 ASIB TUNNOMERI */
    oro_btca_003,  /* 3 NOKEZORI */
    oro_btca_004,  /* 4 KUNOJI */
    oro_btca_005,  /* 5 KIRIMOMI */
    oro_btca_006,  /* 6 UPPER */
    oro_btca_007,  /* 7 BODY UPPER */
    oro_btca_008,  /* 8 HARAYARARE */
    oro_btca_009,  /* 9 TATAKI AIR */
    oro_btca_010,  /* 10 TTKI V. AIR */
    oro_btca_011,  /* 11 HUMI ASIB */
    oro_btca_012,  /* 12 FACE */
    oro_btca_013,  /* 13 ASIB SIRI LOSE */
    oro_btca_014,  /* 14 ASIB TUN LOSE */
    oro_btca_015,  /* 15 DENKI */
    oro_btca_016,  /* 16 KUNOJI NOKE */
    oro_btca_017,  /* 17 BODY UPPER SP */
    oro_btca_018,  /* 18 HANEAGARI */
    oro_btca_019,  /* 19 TOUKETSU A */
    oro_btca_020,  /* 20 BODY SLAM */
    oro_btca_021,  /* 21 IPPONZEOI */
    oro_btca_022,  /* 22 TOMOE RYU */
    oro_btca_023,  /* 23 MONKEY FLIP */
    oro_btca_023,  /* 24 TOMOE ORO */
    oro_btca_025,  /* 25 SNAKE FANG */
    oro_btca_026,  /* 26 FLANKEN.S */
    oro_btca_027,  /* 27 KISHINRIKI */
    oro_btca_028,  /* 28 SPLASH.M */
    oro_btca_029,  /* 29 HARAIGOSHI */
    oro_btca_030,  /* 30 ALEX B.D */
    oro_btca_031,  /* 31 GILL */
    oro_btca_032,  /* 32 HANEKAERI HARA */
    oro_btca_033,  /* 33 S HANEAGARI */
    oro_btca_034,  /* 34 TATUMAKIZANKU */
    oro_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 oro_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_000[68] = {
    CMD(CM_JSR, 8, 43, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36C7, 0, 208, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 579, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x36C7, 0, 208, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x369B, 0, 209, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 oro_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36E7, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 12, 0x36E8, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 10, 0x36E9, 0, 212, 0, 0, 0, 0, 0),
    L4(250, 3, 0, 0, 0, 0, 9, 0x36EA, 0, 213, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 oro_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_btca_002[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36E7, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x36E8, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36E9, 0, 212, 0, 0, 0, 0, 0),
    L4(250, 3, 0, 0, 0, 0, 0, 0x36EA, 0, 213, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 oro_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_003[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 oro_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_004[52] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36C6, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36C7, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36C8, 0, 223, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36E1, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 oro_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_005[140] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36FA, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36FB, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36FC, 0, 227, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36FD, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36FE, 0, 229, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3700, 0, 230, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3701, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3702, 0, 232, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3704, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3705, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3706, 0, 235, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3708, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3709, 0, 237, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x370B, 0, 238, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x370C, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 oro_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_006[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x369B, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 oro_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_007[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36E0, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x369B, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 oro_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_008[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36E0, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36FA, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 oro_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_009[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 oro_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_010[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36F6, 0, 241, 0, 0, 0, 0, 0),
    L4(250, 0, 579, 0, 0, 0, 0, 0x36F7, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 oro_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 oro_btca_011[44] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36F0, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x36F1, 0, 244, 0, 0, 0, 0, 0),
    L4(250, 3, 0, 0, 0, 0, 0, 0x36F1, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 oro_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_012[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3683, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36FA, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 oro_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 oro_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 oro_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 oro_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_015[76] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x3935, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3935, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3936, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3935, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3937, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 579, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 oro_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_016[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36C6, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 0, 579, 0, 0, 0, 0, 0x36C7, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36C8, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 oro_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_017[148] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 579, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 oro_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(3, 0, 579, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 114, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x36A8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x36A7, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 oro_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3683, 0, 245, 0, 0, 0, 0, 0),
    L4(250, 0, 579, 0, 0, 0, 0, 0x3683, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 oro_btca_020_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_020[16] = {
    L6(250, 0, 0, 0, 0, 0, 0, 0x36E3, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 oro_btca_021_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_021[16] = {
    L6(250, 0, 0, 0, 0, 0, 0, 0x36E6, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 oro_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_022[60] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x36AD, 0, 142, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x36AE, 0, 142, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x36B0, 0, 142, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP, 24 TOMOE ORO */
const u16 oro_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_023[60] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36AD, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AE, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36B0, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 oro_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_025[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 142, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 142, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 142, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 142, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 142, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 oro_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_026[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x36AD, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AE, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36B0, 0, 142, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 142, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 oro_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_027[68] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 oro_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_028[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 oro_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_029[36] = {
    CMD(CM_RJA, 7, 25, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x36AA, 0, 142, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36AA, 0, 142, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 oro_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_030[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x36E0, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x369B, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 oro_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x36E7, 0, 210, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x36E8, 0, 211, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36E9, 0, 212, 0, 0, 0, 0, 0),
    L4(250, 3, 0, 0, 0, 0, 0, 0x36EA, 0, 213, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 oro_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x36E0, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36FA, 0, 225, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 oro_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_033[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 579, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 oro_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_btca_034[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x369B, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 579, 0, 0, 0, 0, 0x36A3, 0, 214, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x36A6, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A7, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A8, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36A9, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B9, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36BA, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 15 entries */
const u16* const oro_caca[16] = {
    oro_caca_000,  /* 0 CATCH 1 */
    oro_caca_001,  /* 1 CATCH 2 */
    oro_caca_002,  /* 2 CATCH 3 */
    oro_caca_003,  /* 3 CATCH 4 */
    oro_caca_004,  /* 4 CATCH 5 */
    oro_caca_005,  /* 5 CATCH 6 */
    oro_caca_006,  /* 6 CATCH 7 */
    oro_caca_007,  /* 7 CATCH 8 */
    oro_caca_008,  /* 8 CATCH 9 */
    oro_caca_009,  /* 9 CATCH 10 */
    oro_caca_010,  /* 10 CATCH 11 */
    oro_caca_011,  /* 11 CATCH 12 */
    oro_caca_012,  /* 12 CATCH 13 */
    oro_caca_013,  /* 13 CATCH 14 */
    oro_caca_014,  /* 14 CATCH 15 */
    0
};

/* script: 0 CATCH 1 */
const u16 oro_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 oro_caca_000[244] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F1, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F4, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F5, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F6, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F7, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F8, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38F9, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38FA, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38FB, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38FC, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x360E, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x360F, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3610, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3611, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3612, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3613, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3613, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 oro_caca_001_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 oro_caca_001[280] = {
    CMD(CM_NGDA, 1542, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x3900, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x390D, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x390E, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x390F, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3910, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3911, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(6, 0, 270, 0, 0, 0, 0, 0x3912, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(2, 0, 581, 0, 0, 0, 0, 0x3913, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(4, 2, 0, 0, 0, 0, 0, 0x3914, -47, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(8, 9, 0, 0, 0, 0, 0, 0x3915, 0, 0, 0, 0, 0, 0, 0, 256, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3917, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3918, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 1, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 1, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 1, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 oro_caca_002_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 oro_caca_002[376] = {
    CMD(CM_NGDA, 1542, 12, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x3919, 0, 0, 0, 0, 0, 30, 23, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x391A, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x391B, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x391C, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x391D, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(5, 0, 584, 0, 0, 1, 0, 0x391E, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 264, 0, 0, 2, 0, 0x391F, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 10, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 11, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 12, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 64, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 46, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 9, 0, 0, 0, 0, 0, 0x3922, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 1, 0, 0, 0, 0, 0, 0x3923, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3924, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3925, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3926, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3927, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 oro_caca_003_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 oro_caca_003[292] = {
    CMD(CM_NGDA, 1542, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 3, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(1, 1, 583, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C1, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C2, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C3, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C4, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C5, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C6, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C7, 0, 0, 0, 0, 0, 0, 0, 0, 1128, 0, 5, 0),
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 49, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 584, 0, 0, 0, 0, 0x38C8, -60, 0, 0, 0, 0, 0, 0, 256, 1152, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x38C9, 0, 0, 0, 0, 0, 0, 0, 256, 1176, 0, 0, 0),
    L6(12, 4, 0, 0, 0, 0, 0, 0x38CA, 0, 0, 0, 0, 0, 0, 0, 256, 1200, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x38CB, 0, 0, 0, 0, 0, 0, 0, 256, 1224, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 0, 0, 0x38CB, 0, 0, 0, 0, 0, 0, 0, 256, 1248, 0, 0, 0),
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 1, 0, 0, 0, 0, 0, 0x38CB, 0, 1, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x38CC, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 oro_caca_004_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 oro_caca_004[340] = {
    CMD(CM_NGDA, 0, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x3873, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(2, 0, 581, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3879, -49, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x387F, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3880, -51, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3876, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(2, 2, 581, 0, 0, 0, 0, 0x3879, -70, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(4, 6, 0, 0, 1, 0, 0, 0x3882, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3883, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3884, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3885, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3886, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 oro_caca_005_head[4] = { HEAD(6, 0, 40, 0, 0, 0, 0) };
const u16 oro_caca_005[736] = {
    CMD(CM_NGDA, 0, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 264, 0, 0, 0, 0, 0x3873, 0, 1, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 270, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 2, 581, 0, 0, 0, 0, 0x3878, -56, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3879, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 2, 581, 0, 0, 0, 0, 0x387F, -59, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3880, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3876, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 270, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(1, 2, 581, 0, 0, 0, 0, 0x3878, -56, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3879, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 2, 581, 0, 0, 0, 0, 0x387F, -59, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3879, 0, 0, 0, 0, 0, 24, 0, 0, 600, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 2, 581, 0, 0, 0, 0, 0x387F, -59, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3880, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3876, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(1, 2, 270, 0, 0, 0, 0, 0x3878, -56, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(1, 3, 581, 0, 0, 0, 0, 0x3879, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(4, 4, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3748, 0, 0, 0, 0, 0, 0, 0, 0, 1296, 186, 0, 0),
    L6(2, 2, 269, 0, 0, 0, 0, 0x3749, -57, 0, 0, 0, 0, 0, 0, 0, 1320, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x374A, 0, 0, 0, 134, 0, 0, 0, 0, 1344, 6, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x374B, 0, 0, 0, 0, 0, 0, 0, 0, 1368, 18, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x374C, 0, 29, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    CMD(CM_S123, 4, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x374D, 0, 29, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x374E, 0, 29, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x374F, 0, 29, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3750, 0, 29, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3751, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3752, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 oro_caca_006_head[4] = { HEAD(6, 0, 40, 0, 0, 0, 0) };
const u16 oro_caca_006[472] = {
    CMD(CM_NGDA, 0, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 6, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 58, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 1, 0, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_JMP, 2, 6, 30), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x38C8, -63, 0, 0, 0, 0, 0, 0, 256, 1152, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x38C9, 0, 0, 0, 0, 0, 0, 0, 256, 1176, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 0, 0, 0x38CA, 0, 0, 0, 0, 0, 0, 0, 256, 1200, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x38CB, 0, 0, 0, 0, 0, 0, 0, 256, 1224, 0, 0, 0),
    CMD(CM_SCHX, 0, 1, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 6, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 1, 0, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_JMP, 2, 6, 30), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 2, 0, 0, 0, 0, 0, 0x38C8, -64, 0, 0, 0, 0, 0, 0, 256, 1152, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x38C9, 0, 0, 0, 0, 0, 0, 0, 256, 1176, 0, 0, 0),
    L6(10, 4, 0, 0, 0, 0, 0, 0x38CA, 0, 0, 0, 0, 0, 0, 0, 256, 1200, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 0, 0, 0x38CB, 0, 0, 0, 0, 0, 0, 0, 256, 1224, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x38CB, 0, 0, 0, 0, 0, 0, 0, 256, 1248, 0, 0, 0),
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 61, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 1, 0, 0, 0, 0, 0, 0x38CB, 0, 1, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x38CC, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C0, 0, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C1, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C2, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C3, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C4, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C5, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C6, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38C7, 0, 0, 0, 0, 0, 0, 0, 0, 1128, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 oro_caca_007_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 oro_caca_007[64] = {
    CMD(CM_NGDA, 1542, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x3900, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x390D, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x390E, 0, 0, 0, 0, 0, 24, 0, 0, 312, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 oro_caca_008_head[4] = { HEAD(6, 0, 26, 0, 0, 0, 0) };
const u16 oro_caca_008[340] = {
    CMD(CM_NGDA, 0, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x3873, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(2, 0, 581, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3879, -76, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x387F, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3880, -77, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3876, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(2, 2, 581, 0, 0, 0, 0, 0x3879, -70, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(4, 6, 0, 0, 1, 0, 0, 0x3882, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3883, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3884, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3885, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3886, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 oro_caca_009_head[4] = { HEAD(6, 0, 28, 0, 0, 0, 0) };
const u16 oro_caca_009[340] = {
    CMD(CM_NGDA, 0, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x3873, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 552, 0, 0, 0),
    L6(2, 0, 581, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 576, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3879, -78, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 624, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 648, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x387C, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x387D, 0, 0, 0, 0, 0, 0, 0, 0, 696, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x387E, 0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x387F, 0, 0, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3880, -79, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3881, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3876, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3877, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3878, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(2, 2, 581, 0, 0, 0, 0, 0x3879, -70, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x387A, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(4, 9, 0, 0, 0, 0, 0, 0x387B, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(4, 6, 0, 0, 1, 0, 0, 0x3882, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3883, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3884, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3885, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3886, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11 */
const u16 oro_caca_010_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 oro_caca_010[76] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3601, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 3, 0, 0x3920, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(6, 2, 0, 0, 0, 3, 0, 0x3920, -48, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(12, 3, 0, 0, 0, 4, 0, 0x3921, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 CATCH 12 */
const u16 oro_caca_011_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 oro_caca_011[76] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3601, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 3, 0, 0x3920, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 2, 0, 0, 0, 3, 0, 0x3920, -48, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(10, 3, 0, 0, 0, 4, 0, 0x3921, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 CATCH 13 */
const u16 oro_caca_012_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 1) };
const u16 oro_caca_012[76] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 3, 0, 0x3920, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 3, 0, 0x3920, -48, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(6, 3, 0, 0, 0, 4, 0, 0x3921, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 CATCH 14 */
const u16 oro_caca_013_head[4] = { HEAD(6, 0, 46, 0, 0, 0, 0) };
const u16 oro_caca_013[640] = {
    CMD(CM_NGDA, 0, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 1, 37, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 2, 13, 29), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MDAT, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 38, 0, 0x3AB3, 0, 0, 0, 0, 0, 0, 0, 776, 1392, 0, 0, 0),
    L6(5, 0, 270, 0, 0, 39, 0, 0x3AB4, 0, 0, 0, 0, 0, 0, 0, 776, 1392, 0, 0, 0),
    L6(5, 0, 581, 0, 0, 38, 0, 0x3AB5, 56, 0, 0, 0, 0, 0, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 38, 0, 0x3AB6, 0, 0, 0, 0, 0, 0, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 38, 0, 0x3AB7, 0, 0, 0, 0, 0, 19, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 40, 0, 0x3AB8, 0, 0, 0, 0, 0, 18, 36, 776, 1440, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AB9, 0, 0, 0, 0, 0, 0, 0, 776, 1464, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABA, 0, 0, 0, 0, 0, 0, 0, 776, 1488, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABB, 0, 0, 0, 0, 0, 0, 0, 776, 1512, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABC, 0, 0, 0, 0, 0, 0, 0, 776, 1536, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A46, 0, 0, 0, 0, 0, 0, 0, 776, 1560, 0, 0, 0),
    L6(2, 20, 991, 0, 0, 0, 0, 0x3A47, 0, 0, 0, 0, 0, 0, 0, 768, 1584, 0, 0, 0),
    L6(120, 2, 0, 0, 0, 0, 0, 0x3A48, -88, 0, 0, 0, 0, 0, 0, 768, 1584, 0, 0, 0),
    L6(10, 0, 606, 0, 0, 0, 0, 0x3A48, 0, 0, 0, 0, 0, 0, 0, 768, 1584, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    CMD(CM_EXEC, 1, 160, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 161, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 162, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 163, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 164, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABE, 0, 0, 0, 0, 0, 0, 0, 768, 1632, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 159, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(20, 3, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 39, 40, 785, 1656, 0, 0, 0),
    CMD(CM_EXEC, 1, 157, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 4, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 1, 158, 0, 1680, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 0, 1704, 0, 0, 0),
    L6(1, 7, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 74, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 35, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 1, 0, 0, 0, 0, 0, 0x38C8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C7, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C0, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C1, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C2, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C3, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C4, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C5, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C6, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15 */
const u16 oro_caca_014_head[4] = { HEAD(6, 0, 46, 0, 0, 0, 0) };
const u16 oro_caca_014[268] = {
    CMD(CM_NGDA, 0, 66, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 38, 0, 0x3AB3, 0, 0, 0, 0, 0, 0, 0, 776, 1392, 0, 0, 0),
    L6(5, 0, 270, 0, 0, 39, 0, 0x3AB4, 0, 0, 0, 0, 0, 0, 0, 776, 1392, 0, 0, 0),
    L6(5, 0, 581, 0, 0, 38, 0, 0x3AB5, 56, 0, 0, 0, 0, 0, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 38, 0, 0x3AB6, 0, 0, 0, 0, 0, 0, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 38, 0, 0x3AB7, 0, 0, 0, 0, 0, 19, 0, 776, 1416, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 40, 0, 0x3AB8, 0, 0, 0, 0, 0, 18, 36, 776, 1440, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AB9, 0, 0, 0, 0, 0, 0, 0, 776, 1464, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABA, 0, 0, 0, 0, 0, 0, 0, 776, 1488, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABB, 0, 0, 0, 0, 0, 0, 0, 776, 1512, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3ABC, 0, 0, 0, 0, 0, 0, 0, 776, 1536, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A46, 0, 0, 0, 0, 0, 0, 0, 776, 1560, 0, 0, 0),
    L6(2, 20, 991, 0, 0, 0, 0, 0x3A47, 0, 0, 0, 0, 0, 0, 0, 776, 1584, 0, 0, 0),
    L6(130, 2, 0, 0, 0, 0, 0, 0x3A48, -88, 0, 0, 0, 0, 0, 0, 776, 1584, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 768, 1608, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ABE, 0, 0, 0, 0, 0, 0, 0, 768, 1632, 0, 0, 0),
    L6(20, 3, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 39, 40, 768, 1656, 0, 0, 0),
    L6(6, 4, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 1, 158, 0, 1680, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x3ABD, 0, 0, 0, 0, 0, 0, 0, 0, 1704, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x38C8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const oro_cuca[69] = {
    oro_cuca_000,  /* 0 ALEX ZUTUKI */
    oro_cuca_001,  /* 1 ALEX BODY S */
    oro_cuca_002,  /* 2 ALEX BACK D */
    oro_cuca_003,  /* 3 ALEX POWER B */
    oro_cuca_004,  /* 4 ALEX SLEEPER */
    oro_cuca_005,  /* 5 RYU SEOINAGE */
    oro_cuca_006,  /* 6 IBUKI */
    oro_cuca_007,  /* 7 DADLEY L B */
    oro_cuca_008,  /* 8 IBUKI KUBIORI */
    oro_cuca_009,  /* 9 NECRO S T */
    oro_cuca_010,  /* 10 RYU TOMOENAGE */
    oro_cuca_011,  /* 11 YUN HIZAGERI */
    oro_cuca_012,  /* 12 ORO KUBISIME */
    oro_cuca_013,  /* 13 NECRO G S */
    oro_cuca_014,  /* 14 DUDDLEY D S */
    oro_cuca_015,  /* 15 YUN MONKEY F */
    oro_cuca_016,  /* 16 ORO TOMOENAGE */
    oro_cuca_017,  /* 17 ORO NIOURIKI */
    oro_cuca_018,  /* 18 ORO GIGOKU G */
    oro_cuca_019,  /* 19 YUN */
    oro_cuca_020,  /* 20 NECRO SNAKE F */
    oro_cuca_021,  /* 21 NECRO F S */
    oro_cuca_022,  /* 22 IBUKI HARAIG */
    oro_cuca_023,  /* 23 GILL SPLASH M */
    oro_cuca_024,  /* 24 KEN HIZAGERI */
    oro_cuca_025,  /* 25 ORO KISINRIKI */
    oro_cuca_026,  /* 26 SEAN TACKLE */
    oro_cuca_027,  /* 27 ALEX HYPER B */
    oro_cuca_028,  /* 28 NECRO SLAM D */
    oro_cuca_029,  /* 29 ELENA ASINAGE */
    oro_cuca_030,  /* 30 GILL IMPACT C */
    oro_cuca_031,  /* 31 ALEX S H B */
    oro_cuca_032,  /* 32 ALEX F N D */
    oro_cuca_033,  /* 33 no name */
    oro_cuca_034,  /* 34 IBUKI */
    oro_cuca_035,  /* 35 IBUKI YOROI D */
    oro_cuca_036,  /* 36 no name */
    oro_cuca_037,  /* 37 MAWARIKOMI M F */
    oro_cuca_038,  /* 38 HUGO BODY S */
    oro_cuca_039,  /* 39 HUGO N G T */
    oro_cuca_040,  /* 40 HUGO M S P */
    oro_cuca_041,  /* 41 HUGO S D B B */
    oro_cuca_042,  /* 42 no name */
    oro_cuca_043,  /* 43 no name */
    oro_cuca_044,  /* 44 no name */
    oro_cuca_045,  /* 45 no name */
    oro_cuca_046,  /* 46 no name */
    oro_cuca_047,  /* 47 no name */
    oro_cuca_048,  /* 48 no name */
    oro_cuca_049,  /* 49 no name */
    oro_cuca_050,  /* 50 no name */
    oro_cuca_051,  /* 51 no name */
    oro_cuca_052,  /* 52 no name */
    oro_cuca_053,  /* 53 no name */
    oro_cuca_054,  /* 54 no name */
    oro_cuca_055,  /* 55 no name */
    oro_cuca_056,  /* 56 no name */
    oro_cuca_057,  /* 57 no name */
    oro_cuca_058,  /* 58 no name */
    oro_cuca_059,  /* 59 no name */
    oro_cuca_060,  /* 60 no name */
    oro_cuca_061,  /* 61 no name */
    oro_cuca_062,  /* 62 no name */
    oro_cuca_063,  /* 63 no name */
    oro_cuca_064,  /* 64 no name */
    oro_cuca_065,  /* 65 no name */
    oro_cuca_066,  /* 66 no name */
    oro_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 oro_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3697),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 oro_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AF),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 oro_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 1, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36AC),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 oro_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_003[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3693),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36EA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    CMD(CM_RMJA, 3, 3, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 oro_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3695),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3695),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 oro_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3940),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36B0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A8),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36E6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 oro_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3764),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3768),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3767),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3765),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3766),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3766),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 oro_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C8),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 oro_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_008[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3682),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    CMD(CM_RMJA, 3, 8, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36FD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 oro_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 oro_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3940),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3856),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3719),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36E1),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 oro_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 oro_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3940),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3611),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36A3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 oro_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_013[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AD),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 oro_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E1),
    CMD(CM_RMJA, 3, 18, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36E1),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 oro_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_015[64] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x38C2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x38C1),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 oro_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 oro_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3713),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3713),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AC),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 9),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 oro_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x38C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3709),
    L2(250, 3, 0, 0, 0, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E9),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36E9),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 oro_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3850),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3850),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3601),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 oro_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x367B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3679),
    L2(250, 0, 0, 0, 1, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36A7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 oro_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3682),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36F1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 oro_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A9),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36AA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 oro_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36EA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3739),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 oro_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
};

/* script: 25 ORO KISINRIKI */
const u16 oro_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3713),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3713),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 oro_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36EA),
    L2(250, 3, 0, 0, 0, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B6),
    L2(250, 3, 0, 0, 0, 0, 0, 0x36B2),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36B6),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 oro_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36EA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 oro_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_028[128] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x370F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x370E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x370E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x370C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3706),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36A6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 oro_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_029[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36C8),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 oro_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3747),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3746),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FA),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36FA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 37, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 oro_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_031[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3697),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3697),
    CMD(CM_RMJA, 3, 31, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3697),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 oro_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3737),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3737),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 oro_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 1, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E8),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36AA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 30, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 oro_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369C),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x369C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 oro_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3764),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3768),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3767),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3765),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3766),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3766),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 oro_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 2, 0, 0, 0, 0, 0, 0x369C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 2, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3737),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3738),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3739),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B6),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36B3),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 oro_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3850),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3850),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x38C6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x38C2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x38C1),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 oro_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x366E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3668),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3738),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3719),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3719),
    L2(250, 0, 0, 0, 1, 0, 0, 0x371A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3739),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A9),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 oro_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_039[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36B9),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
};

/* script: 40 HUGO M S P */
const u16 oro_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3746),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3692),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3692),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 2, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36B3),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 oro_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A8),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 oro_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 oro_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B7),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36B7),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 oro_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3746),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3692),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3692),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 2, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36B3),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 oro_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36E0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 oro_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3706),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3690),
    L2(250, 0, 0, 0, 2, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A7),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 oro_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AC),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36AC),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 oro_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3682),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3695),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3696),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 oro_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AC),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 oro_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36A8),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36F1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 oro_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3683),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 oro_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3940),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3856),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3719),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3805),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x390D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3719),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E8),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36E1),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 oro_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x368D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3922),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3923),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3925),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3914),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36EA),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36EA),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 oro_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369E),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x369E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 36, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 37, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 oro_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x368D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3684),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3685),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3922),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3923),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3925),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36B1),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x36E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 oro_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CC),
    L2(250, 2, 0, 0, 0, 0, 0, 0x36E7),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 12, 0x36E8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 oro_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3683),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 oro_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_058[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36AF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x36B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C8),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
};

/* script: 59 no name */
const u16 oro_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3850),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3851),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3852),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3853),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3854),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3855),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3744),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36E2),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 oro_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36CB),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 oro_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3828),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3827),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3827),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3826),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A5),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A6),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 oro_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3690),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3691),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3692),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3693),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368B),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368C),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3694),
    CMD(CM_PA_X, 0, -2048, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368D),
    CMD(CM_PA_X, 0, -3328, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36E0),
    CMD(CM_PA_X, 0, -4864, 0),
    CMD(CM_PS_Y, 0, 0, 131),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E8),
    CMD(CM_PA_X, 0, 1280, 0),
    CMD(CM_PS_Y, 0, 0, 99),
    L2(250, 0, 0, 0, 2, 0, 0, 0x36E9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x36AD),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 oro_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 579, 0, 0, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 oro_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x369F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C6),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36C7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 oro_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x368A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x368C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x38C2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x38C1),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36AD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 oro_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3680),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3686),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36C7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3736),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3737),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3738),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3738),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 oro_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3695),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3696),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3697),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3696),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3698),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3699),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3681),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x36A4),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x36A6),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 161 entries */
const u16* const oro_atca[162] = {
    oro_atca_000,  /* 0 S PUNCH A */
    oro_atca_001,  /* 1 S PUNCH B */
    oro_atca_001,  /* 2 S PUNCH C */
    oro_atca_003,  /* 3 M PUNCH A */
    oro_atca_004,  /* 4 M PUNCH B */
    oro_atca_005,  /* 5 M PUNCH C */
    oro_atca_006,  /* 6 L PUNCH A */
    oro_atca_006,  /* 7 L PUNCH B */
    oro_atca_006,  /* 8 L PUNCH C */
    oro_atca_009,  /* 9 S KICK A */
    oro_atca_010,  /* 10 S KICK B */
    oro_atca_010,  /* 11 S KICK C */
    oro_atca_012,  /* 12 M KICK A */
    oro_atca_013,  /* 13 M KICK B */
    oro_atca_013,  /* 14 M KICK C */
    oro_atca_015,  /* 15 L KICK A */
    oro_atca_015,  /* 16 L KICK B */
    oro_atca_015,  /* 17 L KICK C */
    oro_atca_018,  /* 18 KAGAMI P A */
    oro_atca_018,  /* 19 KAGAMI P B */
    oro_atca_018,  /* 20 KAGAMI P C */
    oro_atca_021,  /* 21 KAGAMI P A */
    oro_atca_021,  /* 22 KAGAMI P B */
    oro_atca_021,  /* 23 KAGAMI P C */
    oro_atca_024,  /* 24 KAGAMI P A */
    oro_atca_024,  /* 25 KAGAMI P B */
    oro_atca_024,  /* 26 KAGAMI P C */
    oro_atca_027,  /* 27 KAGAMI K A */
    oro_atca_027,  /* 28 KAGAMI K B */
    oro_atca_027,  /* 29 KAGAMI K C */
    oro_atca_030,  /* 30 KAGAMI K A */
    oro_atca_030,  /* 31 KAGAMI K B */
    oro_atca_030,  /* 32 KAGAMI K C */
    oro_atca_033,  /* 33 KAGAMI K A */
    oro_atca_033,  /* 34 KAGAMI K B */
    oro_atca_033,  /* 35 KAGAMI K C */
    oro_atca_036,  /* 36 V JUMP P S A */
    oro_atca_036,  /* 37 V JUMP P S B */
    oro_atca_038,  /* 38 V JUMP P M A */
    oro_atca_038,  /* 39 V JUMP P M B */
    oro_atca_040,  /* 40 V JUMP P L A */
    oro_atca_040,  /* 41 V JUMP P L B */
    oro_atca_042,  /* 42 V JUMP K S A */
    oro_atca_042,  /* 43 V JUMP K S B */
    oro_atca_044,  /* 44 V JUMP K M A */
    oro_atca_044,  /* 45 V JUMP K M B */
    oro_atca_046,  /* 46 V JUMP K L A */
    oro_atca_046,  /* 47 V JUMP K L B */
    oro_atca_048,  /* 48 F JUMP P S A */
    oro_atca_048,  /* 49 F JUMP P S B */
    oro_atca_050,  /* 50 F JUMP P M A */
    oro_atca_050,  /* 51 F JUMP P M B */
    oro_atca_052,  /* 52 F JUMP P L A */
    oro_atca_052,  /* 53 F JUMP P L B */
    oro_atca_054,  /* 54 F JUMP K S A */
    oro_atca_054,  /* 55 F JUMP K S B */
    oro_atca_056,  /* 56 F JUMP K M A */
    oro_atca_057,  /* 57 F JUMP K M B */
    oro_atca_058,  /* 58 F JUMP K L A */
    oro_atca_058,  /* 59 F JUMP K L B */
    oro_atca_060,  /* 60 B JUMP P S A */
    oro_atca_060,  /* 61 B JUMP P S B */
    oro_atca_062,  /* 62 B JUMP P M A */
    oro_atca_062,  /* 63 B JUMP P M B */
    oro_atca_064,  /* 64 B JUMP P L A */
    oro_atca_064,  /* 65 B JUMP P L B */
    oro_atca_066,  /* 66 B JUMP K S A */
    oro_atca_066,  /* 67 B JUMP K S B */
    oro_atca_068,  /* 68 B JUMP K M A */
    oro_atca_068,  /* 69 B JUMP K M B */
    oro_atca_070,  /* 70 B JUMP K L A */
    oro_atca_070,  /* 71 B JUMP K L B */
    oro_atca_072,  /* 72 SP V JP S P A */
    oro_atca_072,  /* 73 SP V JP S P B */
    oro_atca_074,  /* 74 SP V JP M P A */
    oro_atca_074,  /* 75 SP V JP M P B */
    oro_atca_076,  /* 76 SP V JP L P A */
    oro_atca_076,  /* 77 SP V JP L P B */
    oro_atca_078,  /* 78 SP V JP S K A */
    oro_atca_078,  /* 79 SP V JP S K B */
    oro_atca_080,  /* 80 SP V JP M K A */
    oro_atca_080,  /* 81 SP V JP M K B */
    oro_atca_082,  /* 82 SP V JP L K A */
    oro_atca_082,  /* 83 SP V JP L K B */
    oro_atca_084,  /* 84 SP F JP S P A */
    oro_atca_084,  /* 85 SP F JP S P B */
    oro_atca_086,  /* 86 SP F JP M P A */
    oro_atca_086,  /* 87 SP F JP M P B */
    oro_atca_088,  /* 88 SP F JP L P A */
    oro_atca_088,  /* 89 SP F JP L P B */
    oro_atca_090,  /* 90 SP F JP S K A */
    oro_atca_090,  /* 91 SP F JP S K B */
    oro_atca_092,  /* 92 SP F JP M K A */
    oro_atca_092,  /* 93 SP F JP M K B */
    oro_atca_094,  /* 94 SP F JP L K A */
    oro_atca_094,  /* 95 SP F JP L K B */
    oro_atca_096,  /* 96 SP B JP S P A */
    oro_atca_096,  /* 97 SP B JP S P B */
    oro_atca_098,  /* 98 SP B JP M P A */
    oro_atca_098,  /* 99 SP B JP M P B */
    oro_atca_100,  /* 100 SP B JP L P A */
    oro_atca_100,  /* 101 SP B JP L P B */
    oro_atca_102,  /* 102 SP B JP S K A */
    oro_atca_102,  /* 103 SP B JP S K B */
    oro_atca_104,  /* 104 SP B JP M K A */
    oro_atca_104,  /* 105 SP B JP M K B */
    oro_atca_106,  /* 106 SP B JP L K A */
    oro_atca_106,  /* 107 SP B JP L K B */
    oro_atca_108,  /* 108 S V JP S P A */
    oro_atca_108,  /* 109 S V JP S P B */
    oro_atca_110,  /* 110 S V JP M P A */
    oro_atca_110,  /* 111 S V JP M P B */
    oro_atca_112,  /* 112 S V JP L P A */
    oro_atca_112,  /* 113 S V JP L P B */
    oro_atca_114,  /* 114 S V JP S K A */
    oro_atca_114,  /* 115 S V JP S K B */
    oro_atca_116,  /* 116 S V JP M K A */
    oro_atca_116,  /* 117 S V JP M K B */
    oro_atca_118,  /* 118 S V JP L K A */
    oro_atca_118,  /* 119 S V JP L K B */
    oro_atca_108,  /* 120 S F JP S P A */
    oro_atca_108,  /* 121 S F JP S P B */
    oro_atca_110,  /* 122 S F JP M P A */
    oro_atca_110,  /* 123 S F JP M P B */
    oro_atca_112,  /* 124 S F JP L P A */
    oro_atca_112,  /* 125 S F JP L P B */
    oro_atca_114,  /* 126 S F JP S K A */
    oro_atca_114,  /* 127 S F JP S K B */
    oro_atca_116,  /* 128 S F JP M K A */
    oro_atca_116,  /* 129 S F JP M K B */
    oro_atca_118,  /* 130 S F JP L K A */
    oro_atca_118,  /* 131 S F JP L K B */
    oro_atca_108,  /* 132 S B JP S P A */
    oro_atca_108,  /* 133 S B JP S P B */
    oro_atca_110,  /* 134 S B JP M P A */
    oro_atca_110,  /* 135 S B JP M P B */
    oro_atca_112,  /* 136 S B JP L P A */
    oro_atca_112,  /* 137 S B JP L P B */
    oro_atca_114,  /* 138 S B JP S K A */
    oro_atca_114,  /* 139 S B JP S K B */
    oro_atca_116,  /* 140 S B JP M K A */
    oro_atca_116,  /* 141 S B JP M K B */
    oro_atca_118,  /* 142 S B JP L K A */
    oro_atca_118,  /* 143 S B JP L K B */
    oro_atca_144,  /* 144 TUKAMIKAKARI A */
    oro_atca_144,  /* 145 TUKAMIKAKARI B */
    oro_atca_146,  /* 146 TUKAMIKAKARI C */
    oro_atca_144,  /* 147 TUKAMIKAKARI D */
    oro_atca_144,  /* 148 TUKAMIKAKARI E */
    oro_atca_144,  /* 149 TUKAMIKAKARI F */
    oro_atca_150,  /* 150 TUKAMI AIR A */
    oro_atca_150,  /* 151 TUKAMI AIR B */
    oro_atca_150,  /* 152 TUKAMI AIR C */
    oro_atca_150,  /* 153 TUKAMI AIR D */
    oro_atca_150,  /* 154 TUKAMI AIR E */
    oro_atca_150,  /* 155 TUKAMI AIR F */
    oro_atca_156,  /* 156 follow-up of WIN 8 */
    oro_atca_157,  /* 157 follow-up of ZANNEN 7 */
    oro_atca_158,  /* 158 follow-up of SP WIN 1 */
    oro_atca_159,  /* 159 follow-up of ZANNEN 2 */
    oro_atca_160,  /* 160 follow-up of S KICK A */
    0
};

/* script: 0 S PUNCH A */
const u16 oro_atca_000_head[4] = { HEAD(4, 0, 0, 9, 0, 1, 0) };
const u16 oro_atca_000[108] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3764, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3765, -1, 16, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3766, 0, 17, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3767, 0, 17, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3768, 0, 18, 0, 0, 96, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3769, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x376A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 oro_atca_001_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 0) };
const u16 oro_atca_001[84] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3740, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3741, -2, 20, 0, 128, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3742, 0, 21, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3743, 0, 19, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3744, 0, 19, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3745, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 oro_atca_003_head[4] = { HEAD(6, 0, 2, 8, 0, 2, 0) };
const u16 oro_atca_003[220] = {
    CMD(CM_JPSS, 8, 40, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3773, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x3774, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3775, -3, 31, 0, 0, 97, 0, 0, 0, 0, 2, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3776, -6, 32, 0, 0, 97, 0, 0, 0, 0, 2, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3776, 0, 33, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3777, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3778, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3779, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x377A, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x377B, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x377C, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x377D, 0, 35, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x377E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x377F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B */
const u16 oro_atca_004_head[4] = { HEAD(4, 0, 2, 13, 0, 1, 0) };
const u16 oro_atca_004[116] = {
    CMD(CM_JPSS, 8, 40, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3A80, 0, 25, 0, 0, 0, 32, 12),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A81, 0, 25, 0, 0, 0, 32, 13),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3A82, 0, 25, 0, 0, 0, 32, 14),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3A83, -18, 27, 0, 128, 0, 32, 15),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3A84, 0, 28, 0, 0, 0, 32, 16),
    CMD(CM_ASXY, 34, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A85, 0, 29, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3A86, 0, 29, 0, 0, 0, 32, 18),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A87, 0, 1, 0, 0, 0, 32, 19),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 32, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 oro_atca_005_head[4] = { HEAD(6, 0, 2, 13, 0, 1, 0) };
const u16 oro_atca_005[232] = {
    CMD(CM_JPSS, 8, 40, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3746, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3747, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3748, 0, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3749, 0, 1, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x374A, -4, 260, 0, 128, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x374B, 0, 261, 0, 0, 0, 21, 0, 0, 0, 18, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x374C, 0, 262, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x374D, 0, 262, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x374E, 0, 262, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x374F, 0, 262, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3750, 0, 262, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3751, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3752, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B, 8 L PUNCH C */
const u16 oro_atca_006_head[4] = { HEAD(6, 0, 4, 11, 0, 2, 0) };
const u16 oro_atca_006[316] = {
    CMD(CM_JPSS, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3940, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 581, 0, 0, 0, 0, 0x3754, 0, 36, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x3755, 0, 36, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3756, 0, 37, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3757, 0, 38, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3758, -7, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3759, -8, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x375A, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x375A, 0, 41, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x375B, 0, 41, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x375C, 0, 41, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x375D, 0, 41, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x36A0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x36A1, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3760, 0, 42, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3761, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3762, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3763, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3611, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3612, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A */
const u16 oro_atca_009_head[4] = { HEAD(4, 0, 1, 7, 0, 1, 0) };
const u16 oro_atca_009[100] = {
    CMD(CM_RMJA, 4, 160, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x37A2, 0, 43, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x37A3, -9, 44, 2693, 0, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37A4, 0, 45, 2693, 0, 104, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37A5, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x37A7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x37A8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 S KICK B, 11 S KICK C */
const u16 oro_atca_010_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 0) };
const u16 oro_atca_010[140] = {
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3780, 0, 47, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3780, 0, 47, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3781, 0, 47, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3782, -10, 48, 0, 134, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3783, 0, 49, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3784, 0, 49, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3785, 0, 50, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3786, 0, 50, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3787, 0, 47, 0, 0, 16, 0, 2),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3788, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3789, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 oro_atca_012_head[4] = { HEAD(6, 0, 3, 7, 0, 1, 0) };
const u16 oro_atca_012[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x37A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x37AA, 0, 51, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37AB, -11, 52, 0, 0, 96, 0, 0, 0, 0, 86, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37AC, 0, 53, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AC, 0, 53, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AD, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AE, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AF, 0, 54, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B, 14 M KICK C */
const u16 oro_atca_013_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 oro_atca_013[220] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x378A, 0, 55, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(4, 0, 269, 0, 0, 0, 0, 0x378B, 0, 55, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x378C, -12, 57, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x378D, 0, 57, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x378D, 0, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x378E, 0, 58, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x378F, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3790, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3791, 0, 60, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3792, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3793, 0, 60, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3794, 0, 1, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3795, 0, 1, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 oro_atca_015_head[4] = { HEAD(6, 0, 5, 11, 0, 1, 0) };
const u16 oro_atca_015[280] = {
    L6(4, 0, 584, 0, 0, 0, 0, 0x3796, 0, 61, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x3797, 0, 61, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3798, -13, 62, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3799, 0, 62, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3799, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3799, 0, 64, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x379A, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x379B, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x379C, 0, 65, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x379D, 0, 65, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x379E, 0, 65, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x379F, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37A0, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3792, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37A1, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3793, 0, 1, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3794, 0, 1, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3795, 0, 1, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 oro_atca_018_head[4] = { HEAD(4, 32, 0, 13, 0, 1, 0) };
const u16 oro_atca_018[92] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x37C0, 0, 66, 0, 0, 0, 0, 0),
    L4(4, 0, 268, 0, 0, 0, 0, 0x37C0, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37C1, -15, 67, 0, 128, 96, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x37C2, 0, 68, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37C4, 0, 66, 0, 0, 16, 0, 3),
    L4(2, 64, 0, 0, 0, 0, 0, 0x37C5, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37C6, 0, 66, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 oro_atca_021_head[4] = { HEAD(4, 32, 2, 14, 0, 1, 0) };
const u16 oro_atca_021[92] = {
    CMD(CM_JPSS, 8, 40, 1), 0, 0, 0, 0,
    L4(3, 0, 269, 0, 0, 0, 0, 0x3A88, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x37C0, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3A8A, -52, 136, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A8B, 0, 136, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3A8B, 0, 168, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C4, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C5, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x37C6, 0, 169, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 oro_atca_024_head[4] = { HEAD(6, 32, 4, 12, 0, 1, 0) };
const u16 oro_atca_024[208] = {
    CMD(CM_JPSS, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x37C8, 0, 69, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x37C8, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 581, 0, 0, 0, 0, 0x37C9, -16, 70, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CA, 0, 71, 0, 0, 64, 0, 0, 0, 0, 128, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CB, 0, 72, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CC, 0, 73, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CD, 0, 73, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CE, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37CF, 0, 73, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37D1, 0, 73, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37D3, 0, 74, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37D7, 0, 74, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37C6, 0, 66, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 oro_atca_027_head[4] = { HEAD(6, 32, 1, 11, 0, 1, 0) };
const u16 oro_atca_027[196] = {
    L6(3, 0, 268, 0, 0, 0, 0, 0x37DB, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DF, 0, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DC, 0, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DD, -19, 76, 0, 137, 96, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x37DC, 0, 77, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DD, -19, 76, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DD, 0, 77, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DE, 0, 77, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DF, 0, 78, 0, 0, 16, 0, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37E0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x37C6, 0, 10, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 oro_atca_030_head[4] = { HEAD(6, 32, 3, 13, 0, 1, 0) };
const u16 oro_atca_030[148] = {
    L6(4, 0, 269, 0, 0, 0, 0, 0x37DB, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DC, 0, 165, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DC, -20, 137, 0, 132, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DD, 0, 137, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37DD, 0, 165, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37DE, 0, 165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37DF, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37E0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x37C6, 0, 10, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 oro_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 1, 0) };
const u16 oro_atca_033[116] = {
    L4(5, 0, 581, 0, 0, 0, 0, 0x37E2, 0, 80, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x37E3, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37E4, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37E4, -53, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37E4, 0, 82, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37E5, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37E6, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37E7, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37E8, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x37E9, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x37C6, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x37C7, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x37DA, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 oro_atca_036_head[4] = { HEAD(4, 22, 0, 12, 0, 1, 0) };
const u16 oro_atca_036[132] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x38B3, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B5, -21, 86, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B6, 0, 86, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B5, 0, 86, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B6, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3812, 0, 87, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3813, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 oro_atca_038_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 oro_atca_038[148] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x38B3, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x380D, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B5, -54, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B6, 0, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B5, 0, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B6, 0, 139, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3812, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3812, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3813, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 oro_atca_040_head[4] = { HEAD(4, 22, 4, 14, 0, 1, 0) };
const u16 oro_atca_040[124] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x380C, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x380C, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x380D, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380E, -55, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380F, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3810, 0, 152, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3812, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3813, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 oro_atca_042_head[4] = { HEAD(6, 22, 1, 8, 0, 1, 0) };
const u16 oro_atca_042[172] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 268, 0, 0, 0, 0, 0x3833, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3834, -22, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 5, 0x3836, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3837, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3838, 0, 15, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3839, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 oro_atca_044_head[4] = { HEAD(6, 22, 3, 9, 0, 1, 0) };
const u16 oro_atca_044[148] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 269, 0, 0, 0, 0, 0x3833, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3834, -23, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3836, 0, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3837, 0, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 5, 0x3836, 0, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3838, 0, 15, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3839, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 oro_atca_046_head[4] = { HEAD(6, 22, 5, 13, 0, 1, 0) };
const u16 oro_atca_046[184] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x383A, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x383B, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x383C, -24, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x383D, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x383E, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x383F, 0, 91, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3841, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3842, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3843, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 oro_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 oro_atca_048[188] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x37F0, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x37F1, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F2, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F3, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 5, 0x37F4, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x37F5, -25, 94, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F7, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F8, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x3806, 0, 93, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3807, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3808, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3809, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x380A, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x380B, 0, 93, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 oro_atca_050_head[4] = { HEAD(4, 20, 2, 11, 0, 1, 0) };
const u16 oro_atca_050[188] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F0, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F1, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F2, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F3, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 5, 0x37F4, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F5, -26, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F7, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F7, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x37F8, 0, 93, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3806, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3807, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3808, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3809, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x380A, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x380B, 0, 93, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 oro_atca_052_head[4] = { HEAD(4, 20, 4, 8, 0, 2, 0) };
const u16 oro_atca_052[244] = {
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x37F0, 0, 92, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x37F1, 0, 140, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37F2, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x37F3, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37F9, 0, 173, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37FA, -27, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37FB, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37FC, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x37FD, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x37FE, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x37FF, -28, 98, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3800, 0, 174, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3801, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3802, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3803, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3804, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3805, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3806, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3807, 0, 140, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3808, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3809, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x380A, 0, 140, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x380B, 0, 140, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 140, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3663, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 oro_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 oro_atca_054[132] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 2, 0x3820, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 2, 0x3821, -29, 101, 0, 128, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 2, 0x3823, 0, 101, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 2, 0x3824, 0, 101, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 3, 0x3826, 0, 100, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 4, 0x3827, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3828, 0, 103, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A */
const u16 oro_atca_056_head[4] = { HEAD(4, 20, 3, 7, 0, 1, 0) };
const u16 oro_atca_056[116] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 2, 0x3820, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 2, 0x3821, -30, 102, 0, 132, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 2, 0x3823, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 2, 0x3824, 0, 102, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 2, 0x3823, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x3826, 0, 100, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 4, 0x3827, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3828, 0, 103, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 103, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 F JUMP K M B */
const u16 oro_atca_057_head[4] = { HEAD(4, 20, 3, 5, 0, 2, 0) };
const u16 oro_atca_057[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 4, 0x3815, -31, 104, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x3816, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 4, 0x3817, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 4, 0x3818, -31, 104, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x3819, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 4, 0x381A, 0, 106, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 oro_atca_058_head[4] = { HEAD(4, 20, 5, 13, 0, 1, 0) };
const u16 oro_atca_058[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(4, 0, 270, 0, 0, 0, 4, 0x3829, 0, 106, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x382A, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 4, 0x382B, -32, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x382B, 0, 108, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x382D, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x382E, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 4, 0x382F, 0, 108, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 4, 0x3831, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3662, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 106, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 oro_atca_060_head[4] = { HEAD(2, 24, 0, 10, 0, 1, 0) };
const u16 oro_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 oro_atca_062_head[4] = { HEAD(2, 24, 2, 10, 0, 1, 0) };
const u16 oro_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 oro_atca_064_head[4] = { HEAD(2, 24, 4, 7, 0, 2, 0) };
const u16 oro_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 oro_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 oro_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 oro_atca_068_head[4] = { HEAD(2, 24, 3, 6, 0, 1, 0) };
const u16 oro_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 oro_atca_070_head[4] = { HEAD(2, 24, 5, 12, 0, 1, 0) };
const u16 oro_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 oro_atca_072_head[4] = { HEAD(2, 28, 0, 12, 0, 1, 0) };
const u16 oro_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 oro_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 oro_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 oro_atca_076_head[4] = { HEAD(2, 28, 4, 14, 0, 1, 0) };
const u16 oro_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 oro_atca_078_head[4] = { HEAD(2, 28, 1, 8, 0, 1, 0) };
const u16 oro_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 oro_atca_080_head[4] = { HEAD(2, 28, 3, 9, 0, 1, 0) };
const u16 oro_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 oro_atca_082_head[4] = { HEAD(2, 28, 5, 13, 0, 1, 0) };
const u16 oro_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 oro_atca_084_head[4] = { HEAD(2, 26, 0, 11, 0, 1, 0) };
const u16 oro_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 oro_atca_086_head[4] = { HEAD(2, 26, 2, 11, 0, 1, 0) };
const u16 oro_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 oro_atca_088_head[4] = { HEAD(2, 26, 4, 8, 0, 2, 0) };
const u16 oro_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 oro_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 oro_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 oro_atca_092_head[4] = { HEAD(2, 26, 3, 7, 0, 1, 0) };
const u16 oro_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 oro_atca_094_head[4] = { HEAD(2, 26, 5, 13, 0, 1, 0) };
const u16 oro_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 oro_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 oro_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 oro_atca_098_head[4] = { HEAD(2, 30, 2, 10, 0, 1, 0) };
const u16 oro_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 oro_atca_100_head[4] = { HEAD(2, 30, 4, 7, 0, 2, 0) };
const u16 oro_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 oro_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 oro_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 oro_atca_104_head[4] = { HEAD(2, 30, 3, 6, 0, 1, 0) };
const u16 oro_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 oro_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 oro_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 oro_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 oro_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 oro_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 oro_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 oro_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 oro_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 oro_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 oro_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 oro_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 oro_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 oro_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 oro_atca_118[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 oro_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_atca_144[124] = {
    CMD(CM_CAFR, 2, 1, 2), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 2), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3870, 0, 253, 0, 0, 0, 32, 21),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3870, -46, 254, 0, 0, 0, 0, 0),
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 268, 0, 0, 0, 0, 0x3A6B, 0, 255, 0, 0, 0, 32, 22),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3A6C, 0, 256, 0, 0, 0, 32, 34),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3A6D, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 32, 35),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 oro_atca_146_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_atca_146[52] = {
    CMD(CM_CAFR, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3870, 0, 253, 0, 0, 0, 32, 21),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3870, -66, 254, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 4, 144, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 150 TUKAMI AIR A, 151 TUKAMI AIR B, 152 TUKAMI AIR C, 153 TUKAMI AIR D ... */
const u16 oro_atca_150_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 oro_atca_150[92] = {
    CMD(CM_CAFR, 2, 5, 3), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 3), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 3, 0x3A60, 0, 257, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 3, 0x3A61, 0, 258, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 3, 0x3A66, -65, 259, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 3, 0x3A66, 0, 258, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 3, 0x3A67, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 4, 0x3A60, 0, 257, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of WIN 8 */
const u16 oro_atca_156_head[4] = { HEAD(4, 0, 56, 9, 0, 1, 0) };
const u16 oro_atca_156[172] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3740, -58, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3740, 0, 146, 0, 0, 0, 21, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    L4(2, 146, 0, 0, 0, 0, 0, 0x3873, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3874, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3875, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 184, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of ZANNEN 7 */
const u16 oro_atca_157_head[4] = { HEAD(4, 22, 56, 9, 0, 1, 0) };
const u16 oro_atca_157[124] = {
    CMD(CM_CAFR, 2, 5, 6), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 6), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x380C, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x380D, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380E, -62, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380F, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3810, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3812, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3813, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of SP WIN 1 */
const u16 oro_atca_158_head[4] = { HEAD(4, 0, 56, 10, 0, 1, 0) };
const u16 oro_atca_158[172] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 269, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3743, -58, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3743, 0, 146, 0, 0, 0, 21, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    L4(2, 146, 0, 0, 0, 0, 0, 0x3873, 0, 146, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3874, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3875, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 184, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of ZANNEN 2 */
const u16 oro_atca_159_head[4] = { HEAD(4, 0, 56, 12, 0, 1, 0) };
const u16 oro_atca_159[172] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 269, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3872, -58, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    L4(3, 146, 0, 0, 0, 0, 0, 0x3873, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3874, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3875, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 184, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of S KICK A */
const u16 oro_atca_160_head[4] = { HEAD(6, 0, 3, 7, 0, 1, 0) };
const u16 oro_atca_160[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x37A5, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x37AA, 0, 51, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x37AB, -89, 52, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x37AC, 0, 53, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AD, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AE, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x37AF, 0, 54, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x37B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3753, 0, 1, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX oro_olc_ix_table[41] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 2, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 4, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
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
    { { 53, 0, 0, 0 } },
    { { 56, 0, 0, 0 } },
    { { 61, 0, 0, 0 } },
    { { 64, 0, 0, 0 } },
    { { 65, 0, 0, 0 } },
    { { 66, 0, 0, 0 } },
};

const OVERLAP_PARTS oro_overlap_char_tbl[67] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 14632 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 14633 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 14634 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 14635 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 14798 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 14799 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 14800 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 5, 14801 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 9, 39548 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 10, 39549 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 11, 39550 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 12, 39551 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 13, 39552 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 14, 39553 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 15, 39554 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 16, 39555 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 17, 39556 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 18, 39557 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 19, 39558 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 20, 39559 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 21, 39560 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 22, 39561 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 23, 39562 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 24, 39563 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 25, 39564 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 26, 39565 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 27, 39566 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 28, 39567 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 29, 39568 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 30, 39569 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 31, 39570 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 32, 39571 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 33, 39572 },
    { -70, 40, 0, 0, 2, 0, 250, 0, 0, 34, 39573 },
    { -70, 40, 0, 0, 2, 0, 250, 4, 0, 35, 39574 },
    { -70, 40, 0, 0, 2, 0, 250, 4, 0, 36, 39575 },
    { 26, 114, 0, 9, 1, 0, 4, 0, 0, 0, 39593 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39594 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39595 },
    { 26, 114, 0, 9, 1, 0, 3, 0, 0, 0, 39596 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39597 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39598 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39599 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39600 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39601 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39602 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39603 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39604 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39605 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39606 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 0, 39607 },
    { 26, 114, 0, 9, 1, 0, 2, 0, 0, 41, 39608 },
    { 12, 125, 0, 9, 1, 0, 2, 0, 0, 0, 39597 },
    { 12, 125, 0, 9, 1, 0, 2, 0, 0, 0, 39598 },
    { 12, 125, 0, 9, 1, 0, 250, 0, 0, 55, 39599 },
    { -20, 128, 0, 9, 2, 0, 1, 0, 0, 0, 39599 },
    { -20, 128, 0, 9, 1, 0, 1, 0, 0, 0, 39600 },
    { -20, 128, 0, 9, 2, 0, 1, 0, 0, 0, 39600 },
    { -20, 128, 0, 9, 1, 0, 1, 0, 0, 0, 39601 },
    { -20, 128, 0, 9, 2, 0, 1, 0, 0, 59, 39601 },
    { -34, 97, 0, 9, 2, 0, 1, 0, 0, 0, 39601 },
    { -34, 97, 0, 9, 1, 0, 1, 0, 0, 0, 39602 },
    { -34, 97, 0, 9, 2, 0, 1, 0, 0, 62, 39602 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 64, 15039 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 65, 15040 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 66, 15044 },
};

const CatchTable oro_rival_catch_tbl[1704] = {
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 13, 4, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 26, 0, 1, 1, 2 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 2 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 2 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 0, 1, 1, 2 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 1 },
    { 26, 4, 1, 1, 2 },
    { 32, 4, 1, 1, 2 },
    { 26, 4, 1, 1, 2 },
    { 26, 4, 1, 1, 2 },
    { 26, 4, 1, 1, 2 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 49, -16, 1, 1, 3 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -12, 2, 1, 1 },
    { 49, -16, 2, 1, 3 },
    { 49, -12, 2, 1, 1 },
    { 49, -12, 2, 1, 3 },
    { 49, -12, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 49, -16, 1, 1, 3 },
    { 49, -8, 2, 1, 1 },
    { 49, -8, 2, 1, 1 },
    { 43, -8, 2, 1, 3 },
    { 42, -8, 2, 1, 3 },
    { 49, -16, 2, 1, 3 },
    { 49, -8, 2, 1, 3 },
    { 48, -16, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 34, -46, 2, 1, 4 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -54, 2, 1, 4 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 4 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 4 },
    { 34, -46, 2, 1, 1 },
    { 34, -46, 2, 1, 1 },
    { 14, -37, 2, 1, 4 },
    { 13, -42, 2, 1, 4 },
    { 32, -68, 2, 1, 4 },
    { 32, -44, 2, 1, 4 },
    { 32, -48, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 20, -55, 2, 1, 5 },
    { 19, -51, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 19, -55, 2, 1, 1 },
    { 20, -55, 2, 1, 1 },
    { 20, -56, 2, 1, 5 },
    { 20, -55, 2, 1, 1 },
    { 19, -55, 2, 1, 5 },
    { 20, -55, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 20, -55, 2, 1, 5 },
    { 19, -51, 2, 1, 1 },
    { 19, -51, 2, 1, 1 },
    { 19, -48, 2, 1, 5 },
    { 16, -39, 2, 1, 5 },
    { 19, -82, 2, 1, 5 },
    { 4, -55, 2, 1, 5 },
    { 14, -56, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 12, -66, 2, 1, 6 },
    { -14, -58, 2, 1, 2 },
    { -3, -56, 2, 1, 2 },
    { 6, -35, 2, 1, 2 },
    { -4, -57, 2, 1, 2 },
    { -22, -46, 2, 1, 2 },
    { -2, -66, 2, 1, 6 },
    { -6, -35, 2, 1, 2 },
    { -10, -40, 2, 1, 6 },
    { -5, -26, 2, 1, 2 },
    { 6, -35, 2, 1, 2 },
    { -3, -56, 2, 1, 2 },
    { -3, -56, 2, 1, 2 },
    { 12, -66, 2, 1, 6 },
    { -3, -56, 2, 1, 2 },
    { -3, -56, 2, 1, 2 },
    { 12, -47, 2, 1, 6 },
    { -3, -41, 2, 1, 6 },
    { 0, -81, 2, 1, 6 },
    { -5, -53, 2, 1, 6 },
    { 2, -58, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 8, -56, 2, 1, 7 },
    { -11, -56, 2, 1, 3 },
    { 8, -49, 2, 1, 3 },
    { 16, -37, 2, 1, 3 },
    { 15, -59, 2, 1, 3 },
    { -8, -53, 2, 1, 3 },
    { 5, -67, 2, 1, 7 },
    { 4, -37, 2, 1, 3 },
    { -12, -40, 2, 1, 7 },
    { 7, -29, 2, 1, 3 },
    { 16, -37, 2, 1, 3 },
    { 8, -49, 2, 1, 3 },
    { 8, -49, 2, 1, 3 },
    { 8, -56, 2, 1, 7 },
    { 8, -49, 2, 1, 3 },
    { 8, -49, 2, 1, 3 },
    { 8, -43, 2, 1, 7 },
    { -12, -34, 2, 1, 7 },
    { -29, -47, 2, 1, 7 },
    { -21, -36, 2, 1, 7 },
    { 16, -54, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 6, -56, 2, 1, 8 },
    { 5, -51, 2, 1, 4 },
    { 2, -42, 2, 1, 4 },
    { 10, -32, 2, 1, 4 },
    { -9, -48, 2, 1, 4 },
    { -10, -50, 2, 1, 4 },
    { 3, -64, 2, 1, 8 },
    { -2, -31, 2, 1, 4 },
    { -12, -40, 2, 1, 8 },
    { -3, -27, 2, 1, 4 },
    { 10, -32, 2, 1, 4 },
    { 2, -42, 2, 1, 4 },
    { 2, -42, 2, 1, 4 },
    { 6, -56, 2, 1, 8 },
    { 2, -42, 2, 1, 4 },
    { 2, -42, 2, 1, 4 },
    { -4, -36, 2, 1, 8 },
    { -7, -28, 2, 1, 8 },
    { 30, -46, 2, 1, 8 },
    { -24, -37, 2, 1, 8 },
    { 10, -40, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 7, -56, 2, 1, 9 },
    { 16, -51, 2, 1, 5 },
    { 21, -39, 2, 1, 5 },
    { 28, -34, 2, 1, 5 },
    { 0, -47, 2, 1, 5 },
    { 3, -48, 2, 1, 5 },
    { 3, -64, 2, 1, 9 },
    { 11, -29, 2, 1, 5 },
    { -16, -40, 2, 1, 9 },
    { 0, -26, 2, 1, 5 },
    { 28, -34, 2, 1, 5 },
    { 21, -39, 2, 1, 5 },
    { 21, -39, 2, 1, 5 },
    { 7, -56, 2, 1, 9 },
    { 21, -39, 2, 1, 5 },
    { 21, -39, 2, 1, 5 },
    { -4, -36, 2, 1, 9 },
    { 8, -23, 2, 1, 9 },
    { 18, -57, 2, 1, 9 },
    { -16, -25, 2, 1, 9 },
    { 16, -38, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 33, -58, 2, 1, 10 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 10 },
    { 33, -58, 2, 1, 6 },
    { 26, -52, 2, 1, 10 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 10 },
    { 33, -58, 2, 1, 6 },
    { 33, -58, 2, 1, 6 },
    { 33, -35, 2, 1, 10 },
    { 33, -31, 2, 1, 10 },
    { 3, -69, 2, 1, 10 },
    { 10, -49, 2, 1, 10 },
    { 32, -58, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, 0, 2, 1, 1 },
    { -97, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -49, 0, 2, 1, 1 },
    { -34, 0, 2, 1, 1 },
    { -60, 0, 2, 1, 1 },
    { -90, 0, 2, 1, 1 },
    { -21, 0, 2, 1, 1 },
    { -63, -5, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -49, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -54, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -43, 0, 2, 1, 1 },
    { -43, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -31, 0, 2, 1, 2 },
    { -25, 0, 2, 1, 2 },
    { -2, 0, 2, 1, 2 },
    { -26, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 2 },
    { -18, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -37, 0, 2, 1, 2 },
    { -29, 0, 2, 1, 2 },
    { -11, 0, 2, 1, 2 },
    { -26, 0, 2, 1, 2 },
    { -2, 0, 2, 1, 2 },
    { -2, 0, 2, 1, 2 },
    { -31, 0, 2, 1, 2 },
    { -2, 0, 2, 1, 2 },
    { -2, 0, 2, 1, 2 },
    { -39, 0, 2, 1, 2 },
    { -26, 0, 2, 1, 2 },
    { -40, 0, 2, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -28, -20, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -21, 132, 2, 1, 3 },
    { -27, 11, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -19, 0, 2, 1, 3 },
    { -26, 3, 2, 1, 3 },
    { -1, 120, 2, 1, 3 },
    { -31, -1, 1, 1, 3 },
    { -12, 3, 1, 1, 3 },
    { -16, 0, 1, 1, 3 },
    { -20, 3, 1, 1, 3 },
    { -19, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -21, 132, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -16, 3, 2, 1, 3 },
    { -14, -4, 2, 1, 3 },
    { -27, -5, 2, 1, 3 },
    { -21, -8, 1, 1, 3 },
    { -10, -22, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -15, 134, 2, 1, 4 },
    { 5, 108, 2, 1, 4 },
    { 0, 74, 2, 1, 4 },
    { -31, 110, 2, 1, 4 },
    { 1, 74, 2, 1, 4 },
    { 6, 126, 2, 1, 4 },
    { -14, 0, 1, 1, 4 },
    { 2, 64, 2, 1, 4 },
    { -1, 28, 2, 1, 4 },
    { 1, 118, 2, 1, 4 },
    { -31, 110, 2, 1, 4 },
    { 0, 74, 2, 1, 4 },
    { 0, 74, 2, 1, 4 },
    { -15, 134, 2, 1, 4 },
    { 0, 74, 2, 1, 4 },
    { 0, 74, 2, 1, 4 },
    { -9, -11, 2, 1, 4 },
    { -18, 2, 2, 1, 4 },
    { -28, -3, 2, 1, 4 },
    { -21, 130, 2, 1, 4 },
    { -8, -18, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 45, 126, 1, 1, 5 },
    { 40, 112, 1, 1, 5 },
    { 42, 104, 1, 1, 5 },
    { 43, 104, 1, 1, 5 },
    { 45, 116, 1, 1, 5 },
    { 30, 52, 2, 1, 5 },
    { 19, -28, 1, 1, 5 },
    { 50, 104, 1, 1, 5 },
    { 37, 70, 2, 1, 5 },
    { 59, 98, 1, 1, 5 },
    { 43, 104, 1, 1, 5 },
    { 42, 104, 1, 1, 5 },
    { 42, 104, 1, 1, 5 },
    { 45, 126, 1, 1, 5 },
    { 42, 104, 1, 1, 5 },
    { 42, 104, 1, 1, 5 },
    { 33, 72, 2, 1, 5 },
    { 34, 18, 2, 1, 5 },
    { 26, -34, 2, 1, 5 },
    { 19, 113, 2, 1, 5 },
    { 36, 88, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 79, 128, 1, 1, 6 },
    { 67, 122, 1, 1, 6 },
    { 70, 106, 1, 1, 6 },
    { 69, 112, 1, 1, 6 },
    { 72, 132, 1, 1, 6 },
    { 68, 120, 1, 1, 6 },
    { 57, -17, 1, 1, 6 },
    { 69, 100, 1, 1, 6 },
    { 62, 74, 1, 1, 6 },
    { 82, 112, 1, 1, 6 },
    { 69, 112, 1, 1, 6 },
    { 70, 106, 1, 1, 6 },
    { 70, 106, 1, 1, 6 },
    { 79, 128, 1, 1, 6 },
    { 70, 106, 1, 1, 6 },
    { 70, 106, 1, 1, 6 },
    { 63, -3, 2, 1, 6 },
    { 77, 14, 2, 1, 6 },
    { 55, 9, 2, 1, 6 },
    { 55, -11, 2, 1, 6 },
    { 74, 2, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 78, -19, 1, 1, 7 },
    { 72, 126, 1, 1, 7 },
    { 72, 106, 2, 1, 7 },
    { 61, 78, 2, 1, 7 },
    { 70, 122, 1, 1, 7 },
    { 56, 110, 1, 1, 7 },
    { 56, -17, 1, 1, 7 },
    { 60, 98, 1, 1, 7 },
    { 53, 80, 2, 1, 7 },
    { 83, 82, 1, 1, 7 },
    { 61, 78, 2, 1, 7 },
    { 72, 106, 2, 1, 7 },
    { 72, 106, 2, 1, 7 },
    { 78, -19, 1, 1, 7 },
    { 72, 106, 2, 1, 7 },
    { 72, 106, 2, 1, 7 },
    { 85, 109, 2, 1, 7 },
    { 77, 30, 2, 1, 7 },
    { 67, 12, 2, 1, 7 },
    { 50, 87, 2, 1, 7 },
    { 72, 52, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 118, 62, 1, 1, 8 },
    { 102, 176, 1, 1, 8 },
    { 109, 158, 2, 1, 8 },
    { 111, 130, 2, 1, 8 },
    { 117, 202, 2, 1, 8 },
    { 112, 150, 2, 1, 8 },
    { 116, 78, 1, 1, 8 },
    { 128, 126, 1, 1, 8 },
    { 114, 152, 2, 1, 8 },
    { 117, 168, 1, 1, 8 },
    { 111, 130, 2, 1, 8 },
    { 109, 158, 2, 1, 8 },
    { 109, 158, 2, 1, 8 },
    { 118, 62, 1, 1, 8 },
    { 109, 158, 2, 1, 8 },
    { 109, 158, 2, 1, 8 },
    { 124, 74, 2, 1, 8 },
    { 134, 69, 2, 1, 8 },
    { 95, 101, 2, 1, 8 },
    { 113, 79, 2, 1, 8 },
    { 126, 126, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 140, 90, 1, 1, 9 },
    { 134, 100, 1, 1, 9 },
    { 137, 194, 2, 1, 9 },
    { 114, 140, 2, 1, 9 },
    { 126, 222, 2, 1, 9 },
    { 121, 170, 2, 1, 9 },
    { 139, 60, 2, 1, 9 },
    { 132, 150, 1, 1, 9 },
    { 125, 172, 2, 1, 9 },
    { 127, 182, 1, 1, 9 },
    { 114, 140, 2, 1, 9 },
    { 137, 194, 2, 1, 9 },
    { 137, 194, 2, 1, 9 },
    { 140, 90, 1, 1, 9 },
    { 137, 194, 2, 1, 9 },
    { 137, 194, 2, 1, 9 },
    { 151, 98, 2, 1, 9 },
    { 144, 76, 2, 1, 9 },
    { 99, 105, 2, 1, 9 },
    { 149, 73, 2, 1, 9 },
    { 144, 192, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 146, 94, 1, 1, 10 },
    { 163, 112, 1, 1, 10 },
    { 147, 118, 2, 1, 10 },
    { 157, 125, 2, 1, 10 },
    { 163, 130, 2, 1, 10 },
    { 141, 113, 2, 1, 10 },
    { 152, 77, 2, 1, 10 },
    { 136, 120, 1, 1, 10 },
    { 140, 128, 2, 1, 10 },
    { 138, 118, 1, 1, 10 },
    { 157, 125, 2, 1, 10 },
    { 147, 118, 2, 1, 10 },
    { 147, 118, 2, 1, 10 },
    { 146, 94, 1, 1, 10 },
    { 147, 118, 2, 1, 10 },
    { 147, 118, 2, 1, 10 },
    { 134, 86, 2, 1, 10 },
    { 150, 85, 2, 1, 10 },
    { 109, 129, 2, 1, 10 },
    { 166, 89, 2, 1, 10 },
    { 160, 112, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -92, 0, 2, 1, 1 },
    { -144, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { -130, 0, 2, 1, 1 },
    { -159, 0, 2, 1, 1 },
    { -131, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -113, 0, 2, 1, 1 },
    { -120, 0, 2, 1, 1 },
    { -117, 0, 2, 1, 1 },
    { -130, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { -127, 0, 2, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -88, -14, 2, 1, 2 },
    { -138, 0, 2, 1, 2 },
    { -105, 0, 2, 1, 2 },
    { -101, 0, 2, 1, 2 },
    { -129, 0, 2, 1, 2 },
    { -120, 0, 2, 1, 2 },
    { -95, 0, 2, 1, 2 },
    { -106, 0, 2, 1, 2 },
    { -58, 0, 2, 1, 2 },
    { -86, 0, 2, 1, 2 },
    { -101, 0, 2, 1, 2 },
    { -105, 0, 2, 1, 2 },
    { -105, 0, 2, 1, 2 },
    { -88, -14, 2, 1, 2 },
    { -105, 0, 2, 1, 2 },
    { -105, 0, 2, 1, 2 },
    { -66, 0, 1, 1, 2 },
    { -75, 0, 1, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -69, 0, 2, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -67, -10, 2, 1, 3 },
    { -115, -8, 2, 1, 3 },
    { -105, -3, 2, 1, 3 },
    { -113, -9, 2, 1, 3 },
    { -109, -20, 2, 1, 3 },
    { -112, 0, 2, 1, 3 },
    { -92, 0, 2, 1, 3 },
    { -100, -8, 2, 1, 3 },
    { -81, 0, 2, 1, 3 },
    { -92, -3, 2, 1, 3 },
    { -113, -9, 2, 1, 3 },
    { -105, -3, 2, 1, 3 },
    { -105, -3, 2, 1, 3 },
    { -67, -10, 2, 1, 3 },
    { -105, -3, 2, 1, 3 },
    { -105, -3, 2, 1, 3 },
    { -73, 0, 2, 1, 3 },
    { -80, 0, 1, 1, 3 },
    { -80, 0, 2, 1, 3 },
    { -65, 0, 2, 1, 3 },
    { -88, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 12, 100, 2, 1, 4 },
    { -31, 42, 2, 1, 4 },
    { -10, 52, 2, 1, 4 },
    { -14, 53, 2, 1, 4 },
    { -9, 39, 2, 1, 4 },
    { -15, 37, 2, 1, 4 },
    { -45, 30, 2, 1, 4 },
    { -18, 28, 2, 1, 4 },
    { 4, 69, 2, 1, 4 },
    { 3, 54, 2, 1, 4 },
    { -14, 53, 2, 1, 4 },
    { -10, 52, 2, 1, 4 },
    { -10, 52, 2, 1, 4 },
    { 12, 100, 2, 1, 4 },
    { -10, 52, 2, 1, 4 },
    { -10, 52, 2, 1, 4 },
    { 10, 127, 1, 1, 4 },
    { 6, 53, 1, 1, 4 },
    { 20, 36, 2, 1, 4 },
    { -7, 37, 2, 1, 4 },
    { 20, 136, 2, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 45, 0, 2, 1, 5 },
    { 48, 0, 2, 1, 5 },
    { 48, -8, 2, 1, 5 },
    { 34, -3, 2, 1, 5 },
    { 41, -5, 2, 1, 5 },
    { 64, -23, 2, 1, 5 },
    { 8, 4, 2, 1, 5 },
    { 48, -4, 2, 1, 5 },
    { 91, 62, 2, 1, 5 },
    { 60, -2, 2, 1, 5 },
    { 34, -3, 2, 1, 5 },
    { 48, -8, 2, 1, 5 },
    { 48, -8, 2, 1, 5 },
    { 45, 0, 2, 1, 5 },
    { 48, -8, 2, 1, 5 },
    { 48, -8, 2, 1, 5 },
    { 79, 75, 1, 1, 5 },
    { 68, 2, 2, 1, 5 },
    { 112, -2, 2, 1, 5 },
    { 33, -2, 2, 1, 5 },
    { 94, 0, 2, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 47, 0, 2, 1, 6 },
    { 33, 0, 2, 1, 6 },
    { 50, 0, 2, 1, 6 },
    { 48, 0, 2, 1, 6 },
    { 43, 0, 2, 1, 6 },
    { 69, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 51, 0, 2, 1, 6 },
    { 109, 0, 2, 1, 6 },
    { 62, 0, 2, 1, 6 },
    { 48, 0, 2, 1, 6 },
    { 50, 0, 2, 1, 6 },
    { 50, 0, 2, 1, 6 },
    { 47, 0, 2, 1, 6 },
    { 50, 0, 2, 1, 6 },
    { 50, 0, 2, 1, 6 },
    { 67, 63, 1, 1, 6 },
    { 68, 0, 2, 1, 6 },
    { 112, 0, 2, 1, 6 },
    { 33, 0, 2, 1, 6 },
    { 100, 0, 2, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 86, 0, 2, 1, 7 },
    { 36, 0, 2, 1, 7 },
    { 52, 0, 2, 1, 7 },
    { 50, 0, 2, 1, 7 },
    { 45, 0, 2, 1, 7 },
    { 71, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 54, 0, 2, 1, 7 },
    { 114, 0, 2, 1, 7 },
    { 64, 0, 2, 1, 7 },
    { 50, 0, 2, 1, 7 },
    { 52, 0, 2, 1, 7 },
    { 52, 0, 2, 1, 7 },
    { 86, 0, 2, 1, 7 },
    { 52, 0, 2, 1, 7 },
    { 52, 0, 2, 1, 7 },
    { 92, -14, 2, 1, 7 },
    { 68, 0, 2, 1, 7 },
    { 112, 0, 2, 1, 7 },
    { 33, 0, 2, 1, 7 },
    { 104, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 76, -12, 2, 1, 8 },
    { 98, 0, 2, 1, 8 },
    { 119, -2, 2, 1, 8 },
    { 93, 4, 2, 1, 8 },
    { 108, 13, 2, 1, 8 },
    { 101, -33, 2, 1, 8 },
    { 75, 0, 1, 1, 8 },
    { 95, 11, 2, 1, 8 },
    { 87, 0, 2, 1, 8 },
    { 77, -5, 2, 1, 8 },
    { 93, 4, 2, 1, 8 },
    { 119, -2, 2, 1, 8 },
    { 119, -2, 2, 1, 8 },
    { 76, -12, 2, 1, 8 },
    { 119, -2, 2, 1, 8 },
    { 119, -2, 2, 1, 8 },
    { 90, 91, 2, 1, 8 },
    { 101, 2, 2, 1, 8 },
    { 57, -6, 2, 1, 8 },
    { 67, -18, 2, 1, 8 },
    { 52, -8, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 58, -7, 2, 1, 9 },
    { 95, 8, 2, 1, 9 },
    { 95, 7, 2, 1, 9 },
    { 96, 7, 2, 1, 9 },
    { 84, -7, 2, 1, 9 },
    { 104, 5, 2, 1, 9 },
    { 92, 0, 2, 1, 9 },
    { 97, 5, 2, 1, 9 },
    { 74, 12, 2, 1, 9 },
    { 81, 10, 2, 1, 9 },
    { 96, 7, 2, 1, 9 },
    { 95, 7, 2, 1, 9 },
    { 95, 7, 2, 1, 9 },
    { 58, -7, 2, 1, 9 },
    { 95, 7, 2, 1, 9 },
    { 95, 7, 2, 1, 9 },
    { 62, 90, 2, 1, 9 },
    { 62, 103, 2, 1, 9 },
    { 61, 2, 2, 1, 9 },
    { 83, 1, 2, 1, 9 },
    { 100, 4, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 56, 68, 2, 1, 10 },
    { 79, 56, 2, 1, 10 },
    { 61, 57, 2, 1, 10 },
    { 68, 54, 2, 1, 10 },
    { 57, 42, 2, 1, 10 },
    { 71, 41, 2, 1, 10 },
    { 77, 0, 2, 1, 10 },
    { 68, 43, 2, 1, 10 },
    { 40, 67, 2, 1, 10 },
    { 54, 62, 2, 1, 10 },
    { 68, 54, 2, 1, 10 },
    { 61, 57, 2, 1, 10 },
    { 61, 57, 2, 1, 10 },
    { 56, 68, 2, 1, 10 },
    { 61, 57, 2, 1, 10 },
    { 61, 57, 2, 1, 10 },
    { 47, 80, 2, 1, 10 },
    { 49, 66, 2, 1, 10 },
    { 32, 58, 2, 1, 10 },
    { 62, 56, 2, 1, 10 },
    { 62, 46, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -76, 72, 2, 1, 11 },
    { -44, 29, 2, 1, 11 },
    { -78, 59, 2, 1, 11 },
    { -65, 63, 2, 1, 11 },
    { -84, 63, 2, 1, 11 },
    { -69, 41, 2, 1, 11 },
    { -26, 29, 2, 1, 11 },
    { -77, 56, 2, 1, 11 },
    { -129, 174, 2, 1, 11 },
    { -70, 56, 2, 1, 11 },
    { -65, 63, 2, 1, 11 },
    { -78, 59, 2, 1, 11 },
    { -78, 59, 2, 1, 11 },
    { -76, 72, 2, 1, 11 },
    { -78, 59, 2, 1, 11 },
    { -78, 59, 2, 1, 11 },
    { -89, 79, 2, 1, 11 },
    { -77, 40, 2, 1, 11 },
    { -97, 40, 2, 1, 11 },
    { -53, 26, 2, 1, 11 },
    { -78, 42, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -72, 0, 2, 1, 12 },
    { -63, 0, 2, 1, 12 },
    { -67, -9, 2, 1, 12 },
    { -54, -2, 2, 1, 12 },
    { -62, -5, 2, 1, 12 },
    { -84, -23, 2, 1, 12 },
    { -24, 0, 2, 1, 12 },
    { -64, -4, 2, 1, 12 },
    { -107, 64, 2, 1, 12 },
    { -78, -2, 2, 1, 12 },
    { -54, -2, 2, 1, 12 },
    { -67, -9, 2, 1, 12 },
    { -67, -9, 2, 1, 12 },
    { -72, 0, 2, 1, 12 },
    { -67, -9, 2, 1, 12 },
    { -67, -9, 2, 1, 12 },
    { -104, -1, 2, 1, 12 },
    { -83, 2, 2, 1, 12 },
    { -128, -2, 2, 1, 12 },
    { -50, -2, 2, 1, 12 },
    { -62, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -70, 0, 2, 1, 13 },
    { -67, 0, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -62, 0, 2, 1, 13 },
    { -62, 0, 2, 1, 13 },
    { -89, 0, 2, 1, 13 },
    { -24, 0, 2, 1, 13 },
    { -67, 0, 2, 1, 13 },
    { -116, 0, 2, 1, 13 },
    { -80, 0, 2, 1, 13 },
    { -62, 0, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -70, 0, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -68, 0, 2, 1, 13 },
    { -105, -1, 2, 1, 13 },
    { -83, 0, 2, 1, 13 },
    { -128, 0, 2, 1, 13 },
    { -50, 0, 2, 1, 13 },
    { -62, 2, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { -104, 0, 2, 1, 14 },
    { -121, -10, 2, 1, 14 },
    { -125, -11, 2, 1, 14 },
    { -104, 0, 2, 1, 14 },
    { -116, 14, 2, 1, 14 },
    { -112, -34, 2, 1, 14 },
    { -41, 0, 2, 1, 14 },
    { -111, 2, 2, 1, 14 },
    { -106, -13, 2, 1, 14 },
    { -87, 3, 2, 1, 14 },
    { -104, 0, 2, 1, 14 },
    { -125, -11, 2, 1, 14 },
    { -125, -11, 2, 1, 14 },
    { -104, 0, 2, 1, 14 },
    { -125, -11, 2, 1, 14 },
    { -125, -11, 2, 1, 14 },
    { -96, -36, 2, 1, 14 },
    { -106, 8, 2, 1, 14 },
    { -83, 9, 2, 1, 14 },
    { -72, -23, 2, 1, 14 },
    { -98, -44, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { -102, -15, 2, 1, 15 },
    { -116, -6, 2, 1, 15 },
    { -105, -4, 2, 1, 15 },
    { -111, -7, 2, 1, 15 },
    { -109, -20, 2, 1, 15 },
    { -112, 0, 2, 1, 15 },
    { -44, 0, 2, 1, 15 },
    { -100, -8, 2, 1, 15 },
    { -116, 27, 2, 1, 15 },
    { -92, -2, 2, 1, 15 },
    { -111, -7, 2, 1, 15 },
    { -105, -4, 2, 1, 15 },
    { -105, -4, 2, 1, 15 },
    { -102, -15, 2, 1, 15 },
    { -105, -4, 2, 1, 15 },
    { -105, -4, 2, 1, 15 },
    { -88, 80, 2, 1, 15 },
    { -85, 14, 2, 1, 15 },
    { -60, 5, 2, 1, 15 },
    { -93, -7, 2, 1, 15 },
    { -88, -18, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { -17, 28, 2, 1, 16 },
    { -30, 43, 2, 1, 16 },
    { -8, 48, 2, 1, 16 },
    { -15, 53, 2, 1, 16 },
    { -9, 39, 2, 1, 16 },
    { -15, 37, 2, 1, 16 },
    { -52, 42, 2, 1, 16 },
    { -18, 28, 2, 1, 16 },
    { 8, 74, 2, 1, 16 },
    { 0, 56, 2, 1, 16 },
    { -15, 53, 2, 1, 16 },
    { -8, 48, 2, 1, 16 },
    { -8, 48, 2, 1, 16 },
    { -17, 28, 2, 1, 16 },
    { -8, 48, 2, 1, 16 },
    { -8, 48, 2, 1, 16 },
    { 18, 93, 2, 1, 16 },
    { 8, 58, 2, 1, 16 },
    { 15, 40, 2, 1, 16 },
    { -10, 44, 2, 1, 16 },
    { 6, 60, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 40, 0, 2, 1, 17 },
    { 48, 0, 2, 1, 17 },
    { 48, -8, 2, 1, 17 },
    { 35, 0, 2, 1, 17 },
    { 41, -5, 2, 1, 17 },
    { 64, -23, 2, 1, 17 },
    { 8, 0, 2, 1, 17 },
    { 48, -4, 2, 1, 17 },
    { 91, 62, 2, 1, 17 },
    { 60, 0, 2, 1, 17 },
    { 35, 0, 2, 1, 17 },
    { 48, -8, 2, 1, 17 },
    { 48, -8, 2, 1, 17 },
    { 40, 0, 2, 1, 17 },
    { 48, -8, 2, 1, 17 },
    { 48, -8, 2, 1, 17 },
    { 86, -5, 2, 1, 17 },
    { 65, 2, 2, 1, 17 },
    { 116, -2, 2, 1, 17 },
    { 33, -2, 2, 1, 17 },
    { 54, -16, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 48, 2, 2, 1, 18 },
    { 48, 2, 2, 1, 18 },
    { 50, 2, 2, 1, 18 },
    { 48, 2, 2, 1, 18 },
    { 43, 2, 2, 1, 18 },
    { 69, 2, 2, 1, 18 },
    { 8, 0, 2, 1, 18 },
    { 51, 2, 2, 1, 18 },
    { 109, 0, 2, 1, 18 },
    { 62, 2, 2, 1, 18 },
    { 48, 2, 2, 1, 18 },
    { 50, 2, 2, 1, 18 },
    { 50, 2, 2, 1, 18 },
    { 48, 2, 2, 1, 18 },
    { 50, 2, 2, 1, 18 },
    { 50, 2, 2, 1, 18 },
    { 92, -2, 2, 1, 18 },
    { 65, 0, 2, 1, 18 },
    { 116, 0, 2, 1, 18 },
    { 33, 0, 2, 1, 18 },
    { 56, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 48, 0, 2, 0, 20 },
    { 48, 0, 2, 0, 20 },
    { 52, 0, 2, 0, 20 },
    { 50, 0, 2, 0, 20 },
    { 45, 0, 2, 0, 20 },
    { 71, 0, 2, 0, 20 },
    { 8, 0, 2, 0, 20 },
    { 54, 0, 2, 0, 20 },
    { 114, 0, 2, 1, 20 },
    { 64, 0, 2, 0, 20 },
    { 50, 0, 2, 0, 20 },
    { 52, 0, 2, 0, 20 },
    { 52, 0, 2, 0, 20 },
    { 48, 0, 2, 0, 20 },
    { 52, 0, 2, 0, 20 },
    { 52, 0, 2, 0, 20 },
    { 102, 0, 2, 0, 20 },
    { 65, 0, 2, 0, 20 },
    { 116, 0, 2, 0, 20 },
    { 33, 0, 2, 0, 20 },
    { 56, 0, 2, 0, 20 },
    { 0, 0, 2, 0, 20 },
    { 0, 0, 2, 0, 20 },
    { 0, 0, 2, 0, 20 },
    { -6, -46, 1, 1, 1 },
    { 3, 21, 1, 1, 1 },
    { -20, 10, 1, 1, 1 },
    { -9, 28, 1, 1, 1 },
    { -25, 18, 1, 1, 1 },
    { -7, 28, 1, 1, 1 },
    { 9, -5, 1, 1, 1 },
    { -19, -22, 1, 1, 1 },
    { -22, -27, 1, 1, 1 },
    { -1, -1, 1, 1, 1 },
    { -9, 28, 1, 1, 1 },
    { -20, 10, 1, 1, 1 },
    { -20, 10, 1, 1, 1 },
    { -6, -46, 1, 1, 1 },
    { -20, 10, 1, 1, 1 },
    { -20, 10, 1, 1, 1 },
    { -11, 0, 1, 1, 1 },
    { -24, 2, 1, 1, 1 },
    { -14, 20, 1, 1, 1 },
    { 17, 29, 1, 1, 1 },
    { -2, 6, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -1, 2, 1, 1, 2 },
    { 3, 21, 1, 1, 2 },
    { -17, 14, 1, 1, 2 },
    { -5, 29, 1, 1, 2 },
    { -9, 22, 1, 1, 2 },
    { 1, 26, 1, 1, 2 },
    { 2, -27, 1, 1, 2 },
    { -14, -17, 1, 1, 2 },
    { -14, -27, 1, 1, 2 },
    { -1, -1, 1, 1, 2 },
    { -5, 29, 1, 1, 2 },
    { -17, 14, 1, 1, 2 },
    { -17, 14, 1, 1, 2 },
    { -1, 2, 1, 1, 2 },
    { -17, 14, 1, 1, 2 },
    { -17, 14, 1, 1, 2 },
    { -5, 1, 1, 1, 2 },
    { 4, -15, 1, 1, 2 },
    { -21, 16, 1, 1, 2 },
    { 3, 23, 1, 1, 2 },
    { -8, 2, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 29, -16, 1, 1, 3 },
    { 3, 21, 1, 1, 3 },
    { -5, 13, 1, 1, 3 },
    { 9, 35, 1, 1, 3 },
    { 13, 12, 1, 1, 3 },
    { 9, 21, 1, 1, 3 },
    { 0, -40, 1, 1, 3 },
    { -3, -22, 2, 1, 3 },
    { -9, -18, 1, 1, 3 },
    { -1, -1, 1, 1, 3 },
    { 9, 35, 1, 1, 3 },
    { -5, 13, 1, 1, 3 },
    { -5, 13, 1, 1, 3 },
    { 29, -16, 1, 1, 3 },
    { -5, 13, 1, 1, 3 },
    { -5, 13, 1, 1, 3 },
    { -2, 7, 1, 1, 3 },
    { 9, 33, 1, 1, 3 },
    { 28, 16, 1, 1, 3 },
    { 6, 24, 1, 1, 3 },
    { 22, 16, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 14, -9, 1, 1, 4 },
    { 2, 18, 1, 1, 4 },
    { 3, 11, 1, 1, 4 },
    { 15, 24, 1, 1, 4 },
    { 22, 13, 1, 1, 4 },
    { 4, 20, 1, 1, 4 },
    { -10, -22, 1, 1, 4 },
    { 7, -25, 1, 1, 4 },
    { 18, 108, 1, 1, 4 },
    { -1, 74, 1, 1, 4 },
    { 15, 24, 1, 1, 4 },
    { 3, 11, 1, 1, 4 },
    { 3, 11, 1, 1, 4 },
    { 14, -9, 1, 1, 4 },
    { 3, 11, 1, 1, 4 },
    { 3, 11, 1, 1, 4 },
    { 15, 14, 1, 1, 4 },
    { 30, 64, 1, 1, 4 },
    { 2, 11, 1, 1, 4 },
    { 2, 17, 1, 1, 4 },
    { 28, 66, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 14, -2, 1, 1, 5 },
    { 3, 68, 1, 1, 5 },
    { -9, 8, 1, 1, 5 },
    { 7, 20, 1, 1, 5 },
    { 15, 6, 1, 1, 5 },
    { 0, 15, 1, 1, 5 },
    { -1, 128, 1, 1, 5 },
    { 18, -35, 1, 1, 5 },
    { 12, 110, 1, 1, 5 },
    { -1, -1, 1, 1, 5 },
    { 7, 20, 1, 1, 5 },
    { -9, 8, 1, 1, 5 },
    { -9, 8, 1, 1, 5 },
    { 14, -2, 1, 1, 5 },
    { -9, 8, 1, 1, 5 },
    { -9, 8, 1, 1, 5 },
    { 22, 18, 1, 1, 5 },
    { 23, 72, 1, 1, 5 },
    { -17, -2, 1, 1, 5 },
    { -7, 12, 1, 1, 5 },
    { 8, 64, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -1, 84, 1, 1, 6 },
    { 3, 21, 1, 1, 6 },
    { -20, 10, 1, 1, 6 },
    { 3, 19, 1, 1, 6 },
    { -1, 7, 1, 1, 6 },
    { -2, 11, 1, 1, 6 },
    { 5, 122, 1, 1, 6 },
    { 10, -34, 1, 1, 6 },
    { -3, 102, 1, 1, 6 },
    { -1, -1, 1, 1, 6 },
    { 3, 19, 1, 1, 6 },
    { -20, 10, 1, 1, 6 },
    { -20, 10, 1, 1, 6 },
    { -1, 84, 1, 1, 6 },
    { -20, 10, 1, 1, 6 },
    { -20, 10, 1, 1, 6 },
    { -12, 69, 1, 1, 6 },
    { -18, 23, 1, 1, 6 },
    { -14, 5, 1, 1, 6 },
    { -13, 15, 1, 1, 6 },
    { 10, 82, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -7, 98, 1, 1, 7 },
    { -3, 21, 1, 1, 7 },
    { -20, 10, 1, 1, 7 },
    { -2, 15, 1, 1, 7 },
    { -14, 10, 1, 1, 7 },
    { -6, 20, 1, 1, 7 },
    { 4, 70, 1, 1, 7 },
    { -7, -36, 1, 1, 7 },
    { 1, 94, 1, 1, 7 },
    { -1, -1, 1, 1, 7 },
    { -2, 15, 1, 1, 7 },
    { -20, 10, 1, 1, 7 },
    { -20, 10, 1, 1, 7 },
    { -7, 98, 1, 1, 7 },
    { -20, 10, 1, 1, 7 },
    { -20, 10, 1, 1, 7 },
    { -23, 65, 1, 1, 7 },
    { -35, 30, 1, 1, 7 },
    { -37, -13, 1, 1, 7 },
    { -12, 20, 1, 1, 7 },
    { -24, 64, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -14, 82, 1, 1, 8 },
    { -4, 11, 1, 1, 8 },
    { -20, 10, 1, 1, 8 },
    { -8, 21, 1, 1, 8 },
    { -19, 13, 1, 1, 8 },
    { -6, 19, 2, 1, 8 },
    { -6, 110, 1, 1, 8 },
    { -8, -33, 1, 1, 8 },
    { 17, 96, 1, 1, 8 },
    { -1, -1, 1, 1, 8 },
    { -8, 21, 1, 1, 8 },
    { -20, 10, 1, 1, 8 },
    { -20, 10, 1, 1, 8 },
    { -14, 82, 1, 1, 8 },
    { -20, 10, 1, 1, 8 },
    { -20, 10, 1, 1, 8 },
    { -11, 18, 1, 1, 8 },
    { -16, -7, 1, 1, 8 },
    { -45, -7, 1, 1, 8 },
    { -5, 21, 1, 1, 8 },
    { -18, 12, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -23, -12, 1, 1, 9 },
    { 3, 0, 1, 1, 9 },
    { -1, -10, 1, 1, 9 },
    { -15, 0, 1, 1, 9 },
    { 0, -24, 1, 1, 9 },
    { -1, -5, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -8, -13, 1, 1, 9 },
    { 0, -13, 1, 1, 9 },
    { 0, -21, 1, 1, 9 },
    { -15, 0, 1, 1, 9 },
    { -1, -10, 1, 1, 9 },
    { -1, -10, 1, 1, 9 },
    { -23, -12, 1, 1, 9 },
    { -1, -10, 1, 1, 9 },
    { -1, -10, 1, 1, 9 },
    { -16, 0, 1, 1, 9 },
    { -30, 6, 2, 1, 9 },
    { -14, -4, 2, 1, 9 },
    { -19, 14, 2, 1, 9 },
    { -8, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -23, -12, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -2, -11, 1, 1, 10 },
    { -4, -2, 1, 1, 10 },
    { 0, -11, 1, 1, 10 },
    { -11, -63, 2, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -3, -7, 1, 1, 10 },
    { 0, -7, 2, 1, 10 },
    { -14, -49, 1, 1, 10 },
    { -4, -2, 1, 1, 10 },
    { -2, -11, 1, 1, 10 },
    { -2, -11, 1, 1, 10 },
    { -23, -12, 1, 1, 10 },
    { -2, -11, 1, 1, 10 },
    { -2, -11, 1, 1, 10 },
    { -13, -4, 2, 1, 10 },
    { -14, -2, 2, 1, 10 },
    { -17, -6, 2, 1, 10 },
    { -5, 0, 2, 1, 10 },
    { -8, 0, 1, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -23, -12, 1, 1, 11 },
    { 0, 3, 1, 1, 11 },
    { -2, -3, 1, 1, 11 },
    { -4, -1, 1, 1, 11 },
    { 0, -7, 1, 1, 11 },
    { -11, -61, 2, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { -3, -9, 1, 1, 11 },
    { 0, -7, 1, 1, 11 },
    { -14, -47, 1, 1, 11 },
    { -4, -1, 1, 1, 11 },
    { -2, -3, 1, 1, 11 },
    { -2, -3, 1, 1, 11 },
    { -23, -12, 1, 1, 11 },
    { -2, -3, 1, 1, 11 },
    { -2, -3, 1, 1, 11 },
    { -13, -3, 2, 1, 11 },
    { -14, -2, 2, 1, 11 },
    { -14, -5, 2, 1, 11 },
    { -7, -1, 2, 1, 11 },
    { -8, 0, 1, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -23, -12, 1, 1, 12 },
    { 0, 2, 1, 1, 12 },
    { -2, -5, 1, 1, 12 },
    { -4, -2, 1, 1, 12 },
    { 0, -5, 1, 1, 12 },
    { -11, -63, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -3, -7, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -14, -49, 1, 1, 12 },
    { -4, -2, 1, 1, 12 },
    { -2, -5, 1, 1, 12 },
    { -2, -5, 1, 1, 12 },
    { -23, -12, 1, 1, 12 },
    { -2, -5, 1, 1, 12 },
    { -2, -5, 1, 1, 12 },
    { -13, -3, 2, 1, 12 },
    { -14, -2, 2, 1, 12 },
    { -14, -3, 2, 1, 12 },
    { -6, -1, 2, 1, 12 },
    { -8, 0, 1, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -23, -12, 1, 1, 13 },
    { 0, -2, 1, 1, 13 },
    { -2, -4, 1, 1, 13 },
    { -4, -2, 1, 1, 13 },
    { 0, -9, 1, 1, 13 },
    { -11, -61, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { -3, -9, 1, 1, 13 },
    { -8, -6, 1, 1, 13 },
    { -14, -47, 2, 1, 13 },
    { -4, -2, 1, 1, 13 },
    { -2, -4, 1, 1, 13 },
    { -2, -4, 1, 1, 13 },
    { -23, -12, 1, 1, 13 },
    { -2, -4, 1, 1, 13 },
    { -2, -4, 1, 1, 13 },
    { -13, -3, 2, 1, 13 },
    { -14, -2, 2, 1, 13 },
    { -14, -3, 2, 1, 13 },
    { -6, -1, 2, 1, 13 },
    { -8, 0, 1, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { -64, 0, 2, 1, 19 },
    { -67, 0, 2, 1, 19 },
    { -68, 0, 2, 1, 19 },
    { -62, 0, 2, 1, 19 },
    { -64, 0, 2, 1, 19 },
    { -89, 0, 2, 1, 19 },
    { -24, 0, 2, 1, 19 },
    { -70, 0, 2, 1, 19 },
    { -120, 0, 2, 1, 19 },
    { -82, 0, 2, 1, 19 },
    { -62, 0, 2, 1, 19 },
    { -68, 0, 2, 1, 19 },
    { -68, 0, 2, 1, 19 },
    { -64, 0, 2, 1, 19 },
    { -68, 0, 2, 1, 19 },
    { -68, 0, 2, 1, 19 },
    { -94, -1, 2, 1, 19 },
    { -83, 0, 2, 1, 19 },
    { -128, 0, 2, 1, 19 },
    { -50, 0, 2, 1, 19 },
    { -50, 4, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 44, -20, 2, 1, 21 },
    { 40, -17, 2, 1, 21 },
    { 54, 0, 2, 1, 21 },
    { -50, -3, 2, 1, 21 },
    { -55, 12, 2, 1, 21 },
    { 66, -4, 2, 1, 21 },
    { 67, -27, 2, 1, 21 },
    { 54, -11, 2, 1, 21 },
    { 30, 17, 2, 1, 21 },
    { 43, 16, 2, 1, 21 },
    { -50, -3, 2, 1, 21 },
    { 54, 0, 2, 1, 21 },
    { 54, 0, 2, 1, 21 },
    { 44, -20, 2, 1, 21 },
    { 54, 0, 2, 1, 21 },
    { 54, 0, 2, 1, 21 },
    { 41, 78, 2, 1, 21 },
    { 66, 3, 2, 1, 21 },
    { 23, 3, 2, 1, 21 },
    { 67, -22, 2, 1, 21 },
    { 32, 28, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { -6, 0, 2, 1, 22 },
    { 26, 18, 2, 1, 22 },
    { -18, 16, 2, 1, 22 },
    { -20, 28, 2, 1, 22 },
    { -9, 16, 2, 1, 22 },
    { 16, 3, 2, 1, 22 },
    { 44, 20, 2, 1, 22 },
    { 37, 13, 2, 1, 22 },
    { 6, 42, 2, 1, 22 },
    { 14, 25, 2, 1, 22 },
    { -20, 28, 2, 1, 22 },
    { -18, 16, 2, 1, 22 },
    { -18, 16, 2, 1, 22 },
    { -6, 0, 2, 1, 22 },
    { -18, 16, 2, 1, 22 },
    { -18, 16, 2, 1, 22 },
    { 46, 71, 2, 1, 22 },
    { 26, 39, 2, 1, 22 },
    { 5, 20, 2, 1, 22 },
    { 27, 17, 2, 1, 22 },
    { 12, 12, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { -44, -8, 2, 1, 23 },
    { -83, 6, 2, 1, 23 },
    { -76, 18, 2, 1, 23 },
    { -69, 25, 2, 1, 23 },
    { -71, 0, 2, 1, 23 },
    { -72, 10, 2, 1, 23 },
    { -21, 27, 2, 1, 23 },
    { -64, 5, 2, 1, 23 },
    { -83, 49, 2, 1, 23 },
    { -49, 25, 2, 1, 23 },
    { -69, 25, 2, 1, 23 },
    { -76, 18, 2, 1, 23 },
    { -76, 18, 2, 1, 23 },
    { -44, -8, 2, 1, 23 },
    { -76, 18, 2, 1, 23 },
    { -76, 18, 2, 1, 23 },
    { -65, 62, 2, 1, 23 },
    { -67, 29, 2, 1, 23 },
    { -83, 14, 2, 1, 23 },
    { -52, 14, 2, 1, 23 },
    { -48, 18, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { -48, 4, 2, 1, 24 },
    { -83, 6, 2, 1, 24 },
    { -76, 18, 2, 1, 24 },
    { -69, 25, 2, 1, 24 },
    { -71, 0, 2, 1, 24 },
    { -72, 10, 2, 1, 24 },
    { -44, 20, 2, 1, 24 },
    { -64, 5, 2, 1, 24 },
    { -93, 51, 2, 1, 24 },
    { -49, 25, 2, 1, 24 },
    { -69, 25, 2, 1, 24 },
    { -76, 18, 2, 1, 24 },
    { -76, 18, 2, 1, 24 },
    { -48, 4, 2, 1, 24 },
    { -76, 18, 2, 1, 24 },
    { -76, 18, 2, 1, 24 },
    { -79, 64, 2, 1, 24 },
    { -86, 31, 2, 1, 24 },
    { -93, 16, 2, 1, 24 },
    { -66, 15, 2, 1, 24 },
    { -48, 18, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { -36, 0, 2, 1, 1 },
    { -20, 0, 2, 1, 1 },
    { -29, 0, 2, 1, 1 },
    { -34, 0, 2, 1, 1 },
    { -24, 0, 2, 1, 1 },
    { -13, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -47, 0, 2, 1, 1 },
    { -34, 0, 2, 1, 1 },
    { -29, 0, 2, 1, 1 },
    { -29, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -29, 0, 2, 1, 1 },
    { -29, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -45, 1, 2, 1, 1 },
    { -47, 0, 2, 1, 1 },
    { -49, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 2 },
    { -7, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -34, 0, 2, 1, 2 },
    { -28, 0, 2, 1, 2 },
    { -13, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -52, 0, 2, 1, 2 },
    { -42, 0, 2, 1, 2 },
    { -34, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -36, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -24, 0, 2, 1, 2 },
    { -37, 0, 2, 1, 2 },
    { -39, 1, 2, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -49, 0, 2, 1, 2 },
    { -46, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -48, -8, 2, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { -39, 9, 2, 1, 3 },
    { -36, 16, 2, 1, 3 },
    { -28, 16, 2, 1, 3 },
    { -24, 21, 2, 1, 3 },
    { -58, 13, 2, 1, 3 },
    { -49, 22, 2, 1, 3 },
    { -40, 23, 2, 1, 3 },
    { -29, 34, 2, 1, 3 },
    { -36, 16, 2, 1, 3 },
    { -39, 9, 2, 1, 3 },
    { -39, 9, 2, 1, 3 },
    { -48, -8, 2, 1, 3 },
    { -39, 9, 2, 1, 3 },
    { -39, 9, 2, 1, 3 },
    { -26, 19, 2, 1, 3 },
    { -33, 20, 2, 1, 3 },
    { -45, 5, 2, 1, 3 },
    { -37, 25, 2, 1, 3 },
    { -34, 21, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -32, 88, 2, 1, 4 },
    { -24, 80, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -20, 112, 2, 1, 4 },
    { -12, 96, 2, 1, 4 },
    { -8, 101, 2, 1, 4 },
    { -26, 100, 2, 1, 4 },
    { -33, 102, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -18, 82, 2, 1, 4 },
    { -16, 80, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -32, 88, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -23, 89, 2, 1, 4 },
    { -16, 74, 2, 1, 4 },
    { -18, 66, 2, 1, 4 },
    { -24, 69, 2, 1, 4 },
    { -7, 56, 2, 1, 4 },
    { -24, 62, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -16, 168, 2, 1, 5 },
    { -8, 160, 2, 1, 5 },
    { -7, 169, 2, 1, 5 },
    { -4, 192, 2, 1, 5 },
    { 4, 176, 2, 1, 5 },
    { 8, 181, 2, 1, 5 },
    { 0, 160, 2, 1, 5 },
    { -17, 182, 2, 1, 5 },
    { 0, 160, 2, 1, 5 },
    { -2, 162, 2, 1, 5 },
    { -4, 192, 2, 1, 5 },
    { -7, 169, 2, 1, 5 },
    { -7, 169, 2, 1, 5 },
    { -16, 168, 2, 1, 5 },
    { -7, 169, 2, 1, 5 },
    { -7, 169, 2, 1, 5 },
    { 0, 154, 2, 1, 5 },
    { -8, 170, 2, 1, 5 },
    { -16, 169, 2, 1, 5 },
    { -2, 170, 2, 1, 5 },
    { 2, 174, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { 0, 256, 2, 1, 5 },
    { -8, -4, 1, 1, 6 },
    { 10, -28, 1, 1, 6 },
    { 6, -4, 1, 1, 6 },
    { 35, -6, 1, 1, 6 },
    { 5, -63, 1, 1, 6 },
    { 12, -24, 1, 1, 6 },
    { -6, -18, 1, 1, 6 },
    { 14, -39, 1, 1, 6 },
    { 12, -12, 1, 1, 6 },
    { 2, -13, 1, 1, 6 },
    { 35, -6, 1, 1, 6 },
    { 6, -4, 1, 1, 6 },
    { 6, -4, 1, 1, 6 },
    { -8, -4, 1, 1, 6 },
    { 6, -4, 1, 1, 6 },
    { 6, -4, 1, 1, 6 },
    { 3, -8, 1, 1, 6 },
    { -10, -12, 1, 1, 6 },
    { -1, -38, 1, 1, 6 },
    { 10, -4, 1, 1, 6 },
    { -3, -2, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -7, -4, 1, 1, 6 },
    { 11, -28, 1, 1, 6 },
    { 7, -4, 1, 1, 6 },
    { 36, -6, 1, 1, 6 },
    { 6, -63, 1, 1, 6 },
    { 13, -24, 1, 1, 6 },
    { -5, -18, 1, 1, 6 },
    { 5, -8, 1, 1, 6 },
    { 13, -12, 1, 1, 6 },
    { 3, -13, 1, 1, 6 },
    { 36, -6, 1, 1, 6 },
    { 7, -4, 1, 1, 6 },
    { 7, -4, 1, 1, 6 },
    { -7, -4, 1, 1, 6 },
    { 7, -4, 1, 1, 6 },
    { 7, -4, 1, 1, 6 },
    { 4, -8, 1, 1, 6 },
    { -9, -12, 1, 1, 6 },
    { 0, -38, 1, 1, 6 },
    { 11, -4, 1, 1, 6 },
    { -2, -2, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -8, -4, 1, 1, 7 },
    { 10, -8, 1, 1, 7 },
    { 6, -4, 1, 1, 7 },
    { 18, -2, 1, 1, 7 },
    { 18, 0, 1, 1, 7 },
    { 6, -2, 1, 1, 7 },
    { -6, -20, 1, 1, 7 },
    { 5, -6, 1, 1, 7 },
    { 12, -1, 1, 1, 7 },
    { 2, -19, 1, 1, 7 },
    { 18, -2, 1, 1, 7 },
    { 6, -4, 1, 1, 7 },
    { 6, -4, 1, 1, 7 },
    { -8, -4, 1, 1, 7 },
    { 6, -4, 1, 1, 7 },
    { 6, -4, 1, 1, 7 },
    { 3, -13, 1, 1, 7 },
    { -3, -7, 1, 1, 7 },
    { -9, -16, 1, 1, 7 },
    { 8, -4, 1, 1, 7 },
    { 1, -1, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -8, -4, 1, 1, 8 },
    { 10, -8, 1, 1, 8 },
    { 6, -4, 1, 1, 8 },
    { 18, -2, 1, 1, 8 },
    { 18, 0, 1, 1, 8 },
    { 5, -5, 1, 1, 8 },
    { -6, -12, 1, 1, 8 },
    { 5, -6, 1, 1, 8 },
    { 12, -2, 1, 1, 8 },
    { 3, -23, 1, 1, 8 },
    { 18, -2, 1, 1, 8 },
    { 6, -4, 1, 1, 8 },
    { 6, -4, 1, 1, 8 },
    { -8, -4, 1, 1, 8 },
    { 6, -4, 1, 1, 8 },
    { 6, -4, 1, 1, 8 },
    { 3, -6, 1, 1, 8 },
    { -5, -5, 1, 1, 8 },
    { -8, -12, 1, 1, 8 },
    { 1, -8, 1, 1, 8 },
    { -5, -6, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -8, -4, 1, 1, 9 },
    { 10, -8, 1, 1, 9 },
    { 6, -4, 1, 1, 9 },
    { 18, -2, 1, 1, 9 },
    { 16, 0, 1, 1, 9 },
    { 7, -1, 1, 1, 9 },
    { -6, -12, 1, 1, 9 },
    { 5, -6, 1, 1, 9 },
    { 12, -2, 1, 1, 9 },
    { 3, -23, 1, 1, 9 },
    { 18, -2, 1, 1, 9 },
    { 6, -4, 1, 1, 9 },
    { 6, -4, 1, 1, 9 },
    { -8, -4, 1, 1, 9 },
    { 6, -4, 1, 1, 9 },
    { 6, -4, 1, 1, 9 },
    { 3, -6, 1, 1, 9 },
    { -5, -5, 1, 1, 9 },
    { -8, -12, 1, 1, 9 },
    { 1, -8, 1, 1, 9 },
    { -5, -6, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
};

/* extra scripts: 49 entries */
const u16* const oro_exca[50] = {
    oro_exca_000,  /* 0 follow-up of AIR NORMAL */
    oro_exca_001,  /* 1 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 8 */
    oro_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    oro_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    oro_exca_004,  /* 4 follow-up of APPEAR JUNBI 5, ZANNEN 5 +1 */
    oro_exca_005,  /* 5 follow-up of UPPER, BODY UPPER +10 */
    oro_exca_006,  /* 6 follow-up of NOKEZORI, HARAYARARE +13 */
    oro_exca_007,  /* 7 follow-up of KUNOJI, DUDDLEY D S */
    oro_exca_008,  /* 8 follow-up of TATAKI S, KGM TATAKI S +1 */
    oro_exca_009,  /* 9 follow-up of KIRIMOMI, TOMOE RYU +7 */
    oro_exca_010,  /* 10 follow-up of APPEAR JUNBI 4 */
    oro_exca_011,  /* 11 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 8 */
    oro_exca_011,  /* 12 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 4 */
    oro_exca_013,  /* 13 follow-up of APPEAR JUNBI 5, ZANNEN 5 +1 */
    oro_exca_014,  /* 14 follow-up of HUMI ASIB */
    oro_exca_015,  /* 15 follow-up of APPEAR JUNBI 6 */
    oro_exca_016,  /* 16 follow-up of APPEAR JUNBI 6 */
    oro_exca_017,  /* 17 follow-up of JUDGMENT WAIT */
    oro_exca_018,  /* 18 follow-up of JUDGMENT WAIT */
    oro_exca_019,  /* 19 follow-up of JUDGMENT WIN */
    oro_exca_020,  /* 20 follow-up of JUDGMENT WIN */
    oro_exca_021,  /* 21 follow-up of WIN 4 */
    oro_exca_022,  /* 22 follow-up of WIN 4 */
    oro_exca_023,  /* 23 no name */
    oro_exca_023,  /* 24 no name */
    oro_exca_025,  /* 25 follow-up of HARAIGOSHI */
    oro_exca_023,  /* 26 no name */
    oro_exca_027,  /* 27 follow-up of SP APPEAR 6 */
    oro_exca_028,  /* 28 follow-up of SP APPEAR 6 */
    oro_exca_023,  /* 29 no name */
    oro_exca_030,  /* 30 follow-up of ZANNEN 1 */
    oro_exca_031,  /* 31 follow-up of ZANNEN 1 */
    oro_exca_032,  /* 32 follow-up of ZANNEN 6 */
    oro_exca_033,  /* 33 follow-up of ZANNEN 6 */
    oro_exca_034,  /* 34 follow-up of SP WIN 2 */
    oro_exca_035,  /* 35 follow-up of SP WIN 2 */
    oro_exca_036,  /* 36 follow-up of GILL IMPACT C */
    oro_exca_037,  /* 37 follow-up of GILL IMPACT C */
    oro_exca_038,  /* 38 follow-up of SP WIN 3 */
    oro_exca_039,  /* 39 follow-up of SP WIN 3 */
    oro_exca_040,  /* 40 follow-up of SP WIN 4 */
    oro_exca_041,  /* 41 follow-up of SP WIN 4 */
    oro_exca_042,  /* 42 follow-up of SP WIN 5 */
    oro_exca_043,  /* 43 follow-up of SP WIN 5 */
    oro_exca_042,  /* 44 follow-up of SP WIN 6 */
    oro_exca_043,  /* 45 follow-up of SP WIN 6 */
    oro_exca_046,  /* 46 follow-up of SP WIN 7 */
    oro_exca_047,  /* 47 follow-up of SP WIN 7 */
    oro_exca_048,  /* 48 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 oro_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_exca_000[148] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0x3922, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3923, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3924, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3925, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3926, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3927, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3668, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3669, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366A, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 160, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 160, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 8, 2 follow-up of APPEAR JUNBI 3 */
const u16 oro_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_001[100] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 oro_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_003[132] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 9, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x3720, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 5, ZANNEN 5 +1 */
const u16 oro_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_004[116] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of UPPER, BODY UPPER +10 */
const u16 oro_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_005[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, HARAYARARE +13 */
const u16 oro_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_006[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of KUNOJI, DUDDLEY D S */
const u16 oro_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_007[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x36E2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36E3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36E4, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36E5, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36E6, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI S, KGM TATAKI S +1 */
const u16 oro_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_008[76] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x36F8, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x36F9, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, TOMOE RYU +7 */
const u16 oro_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_009[68] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x370D, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x370E, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x370F, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 4 */
const u16 oro_exca_010_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_010[148] = {
    L6(6, 2, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 8, 12 follow-up of APPEAR JUNBI 3, APPEAR JUNBI 4 */
const u16 oro_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_011[52] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 5, ZANNEN 5 +1 */
const u16 oro_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_013[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of HUMI ASIB */
const u16 oro_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_014[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36F2, 0, 114, 0, 0, 0, 0, 0),
    L4(6, 2, 0, 0, 0, 0, 0, 0x36F3, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x36F4, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36F5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of APPEAR JUNBI 6 */
const u16 oro_exca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_015[20] = {
    L4(8, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 4, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of APPEAR JUNBI 6 */
const u16 oro_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_016[20] = {
    L4(8, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 13, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of JUDGMENT WAIT */
const u16 oro_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_017[100] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 follow-up of JUDGMENT WAIT */
const u16 oro_exca_018_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_018[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 follow-up of JUDGMENT WIN */
const u16 oro_exca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_019[100] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 follow-up of JUDGMENT WIN */
const u16 oro_exca_020_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_020[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of WIN 4 */
const u16 oro_exca_021_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_021[100] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 follow-up of WIN 4 */
const u16 oro_exca_022_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_022[52] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 no name, 24 no name, 26 no name, 29 no name */
const u16 oro_exca_023_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 oro_exca_023[8] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3601),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of HARAIGOSHI */
const u16 oro_exca_025_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_025[124] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of SP APPEAR 6 */
const u16 oro_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_027[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of SP APPEAR 6 */
const u16 oro_exca_028_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_028[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x367B, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x367C, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of ZANNEN 1 */
const u16 oro_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_030[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of ZANNEN 1 */
const u16 oro_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_031[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x367B, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x367C, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of ZANNEN 6 */
const u16 oro_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_032[108] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of ZANNEN 6 */
const u16 oro_exca_033_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_033[60] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP WIN 2 */
const u16 oro_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_034[100] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x3631, 0, 170, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP WIN 2 */
const u16 oro_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_035[52] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x3631, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of GILL IMPACT C */
const u16 oro_exca_036_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_036[132] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3720, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of GILL IMPACT C */
const u16 oro_exca_037_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 oro_exca_037[124] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AA, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AB, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AC, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x36AD, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36AE, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36AF, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x36B0, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B1, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x36B2, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B3, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x36B5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x36B6, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B7, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x36B8, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3720, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of SP WIN 3 */
const u16 oro_exca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_038[100] = {
    L4(6, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of SP WIN 3 */
const u16 oro_exca_039_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_039[52] = {
    L4(8, 0, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP WIN 4 */
const u16 oro_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_040[100] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x3631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3637, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of SP WIN 4 */
const u16 oro_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_041[52] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x3631, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3632, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3633, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3634, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of SP WIN 5, 44 follow-up of SP WIN 6 */
const u16 oro_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_042[76] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x367A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of SP WIN 5, 45 follow-up of SP WIN 6 */
const u16 oro_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_043[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 7 */
const u16 oro_exca_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_exca_046[76] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x367A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of SP WIN 7 */
const u16 oro_exca_047_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 oro_exca_047[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x367B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x367C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3632, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3634, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3635, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3635, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 oro_exca_048_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 oro_exca_048[148] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0x3922, 0, 274, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3923, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3924, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3925, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3926, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3927, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3668, 0, 276, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3669, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366A, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 275, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 74 entries */
const u16* const oro_saca[75] = {
    oro_saca_000,  /* 0 UP P GUARD P S */
    oro_saca_001,  /* 1 UP P GUARD P M */
    oro_saca_002,  /* 2 UP P GUARD P L */
    oro_saca_002,  /* 3 UP P GUARD K S */
    oro_saca_002,  /* 4 UP P GUARD K M */
    oro_saca_002,  /* 5 UP P GUARD K L */
    oro_saca_002,  /* 6 D P GUARD P S */
    oro_saca_002,  /* 7 D P GUARD P M */
    oro_saca_002,  /* 8 D P GUARD P L */
    oro_saca_002,  /* 9 D P GUARD K S */
    oro_saca_002,  /* 10 D P GUARD K M */
    oro_saca_002,  /* 11 D P GUARD K L */
    oro_saca_002,  /* 12 FUSHIN P S */
    oro_saca_002,  /* 13 FUSHIN P M */
    oro_saca_002,  /* 14 FUSHIN P L */
    oro_saca_002,  /* 15 FUSHIN K S */
    oro_saca_002,  /* 16 FUSHIN K M */
    oro_saca_002,  /* 17 FUSHIN K L */
    oro_saca_002,  /* 18 OKIAGARI P S */
    oro_saca_002,  /* 19 OKIAGARI P M */
    oro_saca_002,  /* 20 OKIAGARI P L */
    oro_saca_002,  /* 21 OKIAGARI K S */
    oro_saca_002,  /* 22 OKIAGARI K M */
    oro_saca_002,  /* 23 OKIAGARI K L */
    oro_saca_024,  /* 24 ATTACK 1 S: 6(123)4+P light (plain script) */
    oro_saca_025,  /* 25 ATTACK 1 M: 6(123)4+P medium (plain script) */
    oro_saca_026,  /* 26 ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    oro_saca_026,  /* 27 ATTACK 1 SP: 6(123)4+P heavy/EX (plain script) */
    oro_saca_028,  /* 28 ATTACK 2 S: not started by a command */
    oro_saca_028,  /* 29 ATTACK 2 M: not started by a command */
    oro_saca_028,  /* 30 ATTACK 2 L: not started by a command */
    oro_saca_028,  /* 31 ATTACK 2 SP: not started by a command */
    oro_saca_032,  /* 32 ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN) */
    oro_saca_033,  /* 33 ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) */
    oro_saca_034,  /* 34 ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    oro_saca_035,  /* 35 ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    oro_saca_036,  /* 36 ATTACK 4 S: [4]6+P light (plain script) */
    oro_saca_037,  /* 37 ATTACK 4 M: [4]6+P medium (plain script) */
    oro_saca_038,  /* 38 ATTACK 4 L: [4]6+P heavy (plain script) */
    oro_saca_039,  /* 39 ATTACK 4 SP: EX [4]6+PP (plain script) */
    oro_saca_040,  /* 40 ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU) */
    oro_saca_041,  /* 41 ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU) */
    oro_saca_042,  /* 42 ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
    oro_saca_043,  /* 43 ATTACK 5 SP: not started by a command */
    oro_saca_044,  /* 44 ATTACK 6 S: SA III 23623+P light/medium/heavy (plain script) */
    oro_saca_044,  /* 45 ATTACK 6 M: SA III 23623+P light/medium/heavy (plain script) */
    oro_saca_044,  /* 46 ATTACK 6 L: SA III 23623+P light/medium/heavy (plain script) */
    oro_saca_047,  /* 47 ATTACK 6 SP: SA III EX 23623+PP (routine Att_PL09_EX_TENGUIWA) */
    oro_saca_048,  /* 48 ATTACK 7 S: SA II 23623+P light (plain script) */
    oro_saca_049,  /* 49 ATTACK 7 M: SA II 23623+P medium (plain script) */
    oro_saca_050,  /* 50 ATTACK 7 L: SA II 23623+P heavy/EX (plain script) */
    oro_saca_051,  /* 51 ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    oro_saca_052,  /* 52 ATTACK 8 S: SA I 23623+P light/medium/heavy (plain script) */
    oro_saca_052,  /* 53 ATTACK 8 M: SA I 23623+P light/medium/heavy (plain script) */
    oro_saca_052,  /* 54 ATTACK 8 L: SA I 23623+P light/medium/heavy (plain script) */
    oro_saca_055,  /* 55 ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    oro_saca_056,  /* 56 ATTACK 9 S: after 6(123)4+P (plain script) */
    oro_saca_057,  /* 57 ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    oro_saca_057,  /* 58 ATTACK 9 L: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    oro_saca_057,  /* 59 ATTACK 9 SP: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    oro_saca_060,  /* 60 ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    oro_saca_061,  /* 61 ATTACK 10 M: not started by a command */
    oro_saca_062,  /* 62 ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) */
    oro_saca_063,  /* 63 ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI) */
    oro_saca_064,  /* 64 ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) */
    oro_saca_065,  /* 65 ATTACK 11 M: EX 236+KK (routine Att_JINNCHUUWATARI_EX) */
    oro_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    oro_saca_066,  /* 67 ATTACK 11 SP: not started by a command */
    oro_saca_066,  /* 68 ATTACK 12 S: not started by a command */
    oro_saca_066,  /* 69 ATTACK 12 M: not started by a command */
    oro_saca_070,  /* 70 ATTACK 12 L: not started by a command */
    oro_saca_070,  /* 71 ATTACK 12 SP: not started by a command */
    oro_saca_070,  /* 72 ATTACK 13 S: not started by a command */
    oro_saca_073,  /* 73 ATTACK 13 M: not started by a command */
    0
};

/* script: 0 UP P GUARD P S */
const u16 oro_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D3, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D6, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D7, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D8, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D9, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DA, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DB, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DC, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70DD, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1536, 6656), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M */
const u16 oro_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 oro_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70DD, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70DC, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70DC, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DB, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DA, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D9, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D8, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D7, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D6, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70D3, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 oro_saca_002_head[4] = { HEAD(4, 0, 0, 14, 0, 4, 0) };
const u16 oro_saca_002[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3601, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 6(123)4+P light (plain script) */
const u16 oro_saca_024_head[4] = { HEAD(4, 0, 24, 13, 0, 1, 0) };
const u16 oro_saca_024[188] = {
    CMD(CM_RJA, 5, 56, 1), 0, 0, 0, 0,
    CMD(CM_SAJP, 0, 8194, 0), 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 1, 4), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 4), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3872, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, -50, 135, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3873, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3874, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3875, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 184, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 6(123)4+P medium (plain script) */
const u16 oro_saca_025_head[4] = { HEAD(4, 0, 26, 13, 0, 1, 0) };
const u16 oro_saca_025[100] = {
    CMD(CM_RJA, 5, 56, 1), 0, 0, 0, 0,
    CMD(CM_SAJP, 0, 8194, 0), 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 1, 8), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 8), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3872, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, -50, 135, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 24, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 6(123)4+P heavy/EX (plain script), 27 ATTACK 1 SP: 6(123)4+P heavy/EX (plain script) */
const u16 oro_saca_026_head[4] = { HEAD(4, 0, 28, 13, 0, 1, 0) };
const u16 oro_saca_026[100] = {
    CMD(CM_RJA, 5, 56, 1), 0, 0, 0, 0,
    CMD(CM_SAJP, 0, 8194, 0), 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 9), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3872, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, -50, 135, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 24, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: not started by a command, 29 ATTACK 2 M: not started by a command, 30 ATTACK 2 L: not started by a command, 31 ATTACK 2 SP: not started by a command */
const u16 oro_saca_028_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 oro_saca_028[404] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3871, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3872, 0, 1, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3873, 0, 1, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3877,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x2480, 0x0000, 0x3878,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3879,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x387A,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x387B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x387C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x387D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x387E,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x2480, 0x0000, 0x387F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3880,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3881,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3876,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3877, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3878, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3879, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x387A, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x387B, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3882, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3883, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3884, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3885, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3886, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x363B, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x363C, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x3C00, 0x0000, 0x0000, 0x363D, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3874, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x3875, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x3875, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 32 ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN) */
const u16 oro_saca_032_head[4] = { HEAD(6, 0, 8, 9, 0, 1, 39) };
const u16 oro_saca_032[184] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3888, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3889, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388A, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 584, 0, 0, 0, 0, 0x388B, -35, 120, 0, 64, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x388C, 36, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 268, 0, 0, 0, 0, 0x388D, 41, 149, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3890, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3890, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 30, 0, 0, 0, 0, 0, 0x3891, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3656, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3657, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3658, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3659, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) */
const u16 oro_saca_033_head[4] = { HEAD(6, 0, 10, 9, 0, 1, 39) };
const u16 oro_saca_033[160] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3888, 0, 117, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3889, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 584, 0, 0, 0, 0, 0x388A, 0, 117, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388B, -37, 120, 0, 64, 64, 0, 0, 0, 0, 154, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x388C, 38, 121, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x388D, 41, 149, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388E, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388F, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x388C, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x388D, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3890, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 32, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
const u16 oro_saca_034_head[4] = { HEAD(6, 0, 12, 9, 0, 3, 39) };
const u16 oro_saca_034[220] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3887, 0, 117, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3888, 0, 117, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(4, 0, 584, 0, 0, 0, 0, 0x3889, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388A, -39, 119, 0, 0, 64, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388B, -40, 120, 0, 0, 64, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x388C, -40, 121, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x388D, -41, 149, 0, 0, 0, 21, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388E, 41, 149, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388F, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388C, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388D, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388E, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x388F, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x388C, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x388D, 41, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 40, 0, 0, 0, 0, 0, 0x3890, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 32, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
const u16 oro_saca_035_head[4] = { HEAD(6, 0, 14, 9, 0, 4, 39) };
const u16 oro_saca_035[244] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3887, 0, 175, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3888, 0, 175, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(2, 0, 584, 0, 0, 0, 0, 0x3889, 0, 175, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3889, -84, 176, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388A, 0, 119, 0, 0, 64, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388B, -85, 120, 0, 0, 64, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x388C, -85, 121, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x388D, -86, 149, 0, 0, 0, 21, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x388E, 86, 149, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388F, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388C, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388D, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x388E, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x388F, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x388C, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x388D, 86, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 40, 0, 0, 0, 0, 0, 0x3890, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 32, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: [4]6+P light (plain script) */
const u16 oro_saca_036_head[4] = { HEAD(6, 0, 8, 16, 0, 12, 0) };
const u16 oro_saca_036[244] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3892, 0, 123, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3893, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3894, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3895, 0, 124, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3896, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3897, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3898, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3899, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x389A, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x389B, 0, 125, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x389C, 0, 127, 0, 0, 0, 31, 1, 0, 0, 158, 0, 0),
    L6(3, 0, 333, 0, 0, 0, 0, 0x389D, 0, 127, 0, 0, 64, 2, 12, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x389E, 0, 127, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x389F, 0, 125, 0, 0, 64, 0, 0, 0, 0, 160, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x38A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: [4]6+P medium (plain script) */
const u16 oro_saca_037_head[4] = { HEAD(6, 0, 10, 13, 0, 2, 9) };
const u16 oro_saca_037[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3892, 0, 123, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3893, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3894, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3895, 0, 124, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3896, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A2, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38A3, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38A4, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A5, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x38A6, 0, 125, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A7, 0, 129, 0, 0, 0, 31, 1, 0, 0, 158, 0, 0),
    L6(3, 0, 333, 0, 0, 0, 0, 0x38A8, 0, 129, 0, 0, 64, 2, 13, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x38A9, 0, 129, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x38AA, 0, 125, 0, 0, 64, 0, 0, 0, 0, 160, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x38AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: [4]6+P heavy (plain script) */
const u16 oro_saca_038_head[4] = { HEAD(6, 0, 12, 10, 0, 12, 9) };
const u16 oro_saca_038[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3892, 0, 123, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3893, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3894, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3895, 0, 124, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3896, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A2, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38A3, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A4, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A5, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x38AC, 0, 125, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38AD, 0, 131, 0, 0, 0, 31, 1, 0, 0, 158, 0, 0),
    L6(3, 0, 333, 0, 0, 0, 0, 0x38AE, 0, 131, 0, 0, 64, 2, 14, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x38AF, 0, 131, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38B0, 0, 125, 0, 0, 64, 0, 0, 0, 0, 160, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x38AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX [4]6+PP (plain script) */
const u16 oro_saca_039_head[4] = { HEAD(6, 0, 14, 13, 0, 12, 9) };
const u16 oro_saca_039[220] = {
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EPCY, 16, 1, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3892, 0, 123, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3893, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3894, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3895, 0, 124, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3896, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3897, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3898, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3899, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x389A, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x389B, 0, 125, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x389C, 0, 127, 0, 0, 0, 31, 1, 0, 0, 158, 0, 0),
    L6(3, 0, 333, 0, 0, 0, 0, 0x389D, 0, 127, 0, 0, 64, 2, 15, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x389E, 0, 127, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x389F, 0, 125, 0, 0, 64, 0, 0, 0, 0, 160, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x38A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 oro_saca_040_head[4] = { HEAD(4, 22, 8, 13, 0, 7, 10) };
const u16 oro_saca_040[100] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 132, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380D, 0, 132, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x38B3, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 20, 581, 0, 0, 0, 0, 0x38B4, -45, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 333, 0, 0, 0, 0, 0x38B5, 0, 134, 0, 0, 0, 2, 16),
    L4(5, 0, 0, 0, 0, 0, 0, 0x38B6, 0, 134, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3812, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3813, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3814, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 15, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 oro_saca_041_head[4] = { HEAD(4, 22, 10, 13, 0, 7, 10) };
const u16 oro_saca_041[68] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 132, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380D, 0, 132, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x38B3, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 20, 581, 0, 0, 0, 0, 0x38B4, -45, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 333, 0, 0, 0, 0, 0x38B5, 0, 134, 0, 0, 0, 2, 17),
    CMD(CM_JMP, 5, 40, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 oro_saca_042_head[4] = { HEAD(4, 22, 12, 13, 0, 7, 10) };
const u16 oro_saca_042[68] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 132, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380D, 0, 132, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x38B3, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 20, 581, 0, 0, 0, 0, 0x38B4, -45, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 333, 0, 0, 0, 0, 0x38B5, 0, 134, 0, 0, 0, 2, 18),
    CMD(CM_JMP, 5, 40, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: not started by a command */
const u16 oro_saca_043_head[4] = { HEAD(4, 22, 14, 13, 0, 7, 10) };
const u16 oro_saca_043[68] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B1, 0, 132, 0, 0, 0, 16, 5),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38B2, 0, 132, 0, 0, 0, 18, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x380D, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x38B3, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 20, 581, 0, 0, 0, 0, 0x38B4, -45, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 333, 0, 0, 0, 0, 0x38B5, 0, 134, 0, 0, 0, 2, 19),
    CMD(CM_JMP, 5, 40, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA III 23623+P light/medium/heavy (plain script), 45 ATTACK 6 M: SA III 23623+P light/medium/heavy (plain script), 46 ATTACK 6 L: SA III 23623+P light/medium/heavy (plain script) */
const u16 oro_saca_044_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 0) };
const u16 oro_saca_044[316] = {
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 584, 0, 0, 0, 0, 0x38DA, 0, 143, 0, 0, 0, 13, 15, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38DF, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38E1, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CD, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 168, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CE, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CF, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(22, 0, 0, 0, 0, 0, 0, 0x38D0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38D1, 0, 143, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 337, 0, 0, 0, 0, 0x38D2, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38D3, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38F9, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FA, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FB, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FC, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FD, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FE, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38FF, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 170, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x38D4, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: SA III EX 23623+PP (routine Att_PL09_EX_TENGUIWA) */
const u16 oro_saca_047_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 0) };
const u16 oro_saca_047[388] = {
    CMD(CM_JSR, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 584, 0, 0, 0, 0, 0x3A40, 0, 143, 0, 0, 0, 13, 64, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A41, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A42, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A43, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A44, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A45, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A90, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A91, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A92, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A93, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A94, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A95, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A96, 0, 143, 0, 0, 0, 15, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 337, 0, 0, 0, 0, 0x3A9B, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA5, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA2, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA3, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA4, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA5, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA2, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA3, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3AA0, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A45, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3A44, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA II 23623+P light (plain script) */
const u16 oro_saca_048_head[4] = { HEAD(6, 0, 32, 0, 0, 0, 0) };
const u16 oro_saca_048[436] = {
    CMD(CM_JSR, 5, 48, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 33, 0, 0x38F5, 0, 143, 0, 0, 0, 2, 36, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 49, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 583, 0, 0, 0, 0, 0x38D9, 0, 143, 0, 0, 0, 13, 19, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 6, 0, 0x38DA, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 7, 0, 0x38DB, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 8, 0, 0x38DC, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x38DD, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 10, 0, 0x38DE, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 11, 0, 0x38DF, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 12, 0, 0x38E0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 13, 0, 0x38E1, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x38E2, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 15, 0, 0x38E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 16, 0, 0x38E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 17, 0, 0x38E5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 18, 0, 0x38E6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 19, 0, 0x38E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x38E8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 21, 0, 0x38E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 22, 0, 0x38EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 23, 0, 0x38EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 24, 0, 0x38EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 25, 0, 0x38ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 26, 0, 0x38EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 27, 0, 0x38EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 28, 0, 0x38F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x38F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 30, 0, 0x38F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 31, 0, 0x38F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 32, 0, 0x38F4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 33, 0, 0x38F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: SA II 23623+P medium (plain script) */
const u16 oro_saca_049_head[4] = { HEAD(4, 0, 34, 0, 0, 0, 0) };
const u16 oro_saca_049[92] = {
    CMD(CM_JSR, 5, 48, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 33, 0, 0x38F5, 0, 143, 0, 0, 0, 2, 37),
    CMD(CM_JPSS, 5, 49, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38F6, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38F7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x38F8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: SA II 23623+P heavy/EX (plain script) */
const u16 oro_saca_050_head[4] = { HEAD(4, 0, 36, 0, 0, 0, 0) };
const u16 oro_saca_050[28] = {
    CMD(CM_JSR, 5, 48, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 33, 0, 0x38F5, 0, 143, 0, 0, 0, 2, 38),
    CMD(CM_JPSS, 5, 49, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
const u16 oro_saca_051_head[4] = { HEAD(6, 0, 36, 0, 0, 0, 0) };
const u16 oro_saca_051[592] = {
    CMD(CM_JSR, 8, 53, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 54, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 585, 0, 0, 0, 0, 0x3A40, 0, 143, 0, 0, 0, 13, 52, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3A41, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(31, 0, 0, 0, 0, 0, 0, 0x3A42, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A43, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A44, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A45, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3A46, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 582, 0, 0, 0, 0, 0x3A47, 0, 195, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 607, 0, 0, 0, 0, 0x3A48, 0, 195, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3A49, 0, 196, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x3A4A, 0, 197, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 34, 0, 0x3A4A, 0, 197, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 34, 0, 0x3A4B, 0, 197, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 34, 0, 0x3A4C, 0, 197, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 34, 0, 0x3A4A, 0, 197, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 35, 0, 0x3A4D, 0, 198, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 36, 0, 0x3A4E, 0, 199, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 580, 0, 0, 37, 0, 0x3A4F, 0, 200, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3A50, 0, 201, 0, 0, 0, 2, 159, 256, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3A51, 0, 201, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A51, 0, 201, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A52, 0, 201, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A53, 0, 201, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A54, 0, 201, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3922, 0, 202, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3923, 0, 203, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3924, 0, 204, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x3925, 0, 205, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C6, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C7, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C0, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C1, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C2, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C3, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C4, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38C5, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x38C6, 0, 206, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: SA I 23623+P light/medium/heavy (plain script), 53 ATTACK 8 M: SA I 23623+P light/medium/heavy (plain script), 54 ATTACK 8 L: SA I 23623+P light/medium/heavy (plain script) */
const u16 oro_saca_052_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 oro_saca_052[148] = {
    CMD(CM_JSR, 8, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x38DA, 0, 143, 0, 0, 0, 13, 31, 785, 0, 0, 0, 0),
    L6(15, 0, 0, 0, 0, 0, 0, 0x38DF, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 583, 0, 0, 0, 0, 0x38E1, 0, 143, 0, 0, 0, 16, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CD, 0, 143, 0, 0, 0, 18, 7, 785, 0, 0, 0, 0),
    CMD(CM_ASXY, 168, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CE, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38CF, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38D0, 0, 143, 0, 0, 0, 9, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x38D1, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x38D2, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 44, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
const u16 oro_saca_055_head[4] = { HEAD(6, 0, 62, 0, 0, 0, 0) };
const u16 oro_saca_055[352] = {
    CMD(CM_JSR, 8, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 4, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 55, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 585, 0, 0, 0, 0, 0x3A40, 0, 143, 0, 0, 0, 13, 68, 785, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3A41, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(31, 0, 0, 0, 0, 0, 0, 0x3A42, 0, 143, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A43, 0, 143, 0, 0, 0, 16, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A44, 0, 143, 0, 0, 0, 18, 7, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A45, 0, 143, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 9, 0x3AB0, 0, 160, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x3AB1, 0, 160, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x3AB2, 0, 160, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x3AB0, 0, 160, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3AB3, -87, 249, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3AC5, 0, 250, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3AC6, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3AC7, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3AC8, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3AC9, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A45, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A41, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3A42, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3A43, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A44, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3A40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: after 6(123)4+P (plain script) */
const u16 oro_saca_056_head[4] = { HEAD(4, 0, 56, 13, 0, 1, 0) };
const u16 oro_saca_056[172] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0,
    CMD(CM_ASXY, 178, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 269, 0, 0, 0, 0, 0x3870, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3871, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 180, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, -58, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3872, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 182, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3873, 0, 146, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3874, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3875, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x38B7, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 184, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x38A1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), 58 ATTACK 9 L: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), 59 ATTACK 9 SP: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 oro_saca_057_head[4] = { HEAD(4, 20, 11, 5, 0, 4, 44) };
const u16 oro_saca_057[372] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -31, 104, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -31, 104, 0, 128, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3819, 0, 104, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 6), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 582, 0, 0, 0, 0, 0x381A, -61, 104, 0, 144, 0, 0, 0),
    CMD(CM_JMP, 5, 57, 27), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, 0, 151, 0, 128, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3816, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3817, -61, 104, 0, 149, 0, 0, 0),
    CMD(CM_JMP, 5, 57, 27), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, 0, 151, 0, 128, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3819, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_RAPK2, 5, 57, 26), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 57, 27), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 1, 0, 0, 0x3922, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3923, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3924, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3925, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3926, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3927, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3668, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3669, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366A, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 oro_saca_060_head[4] = { HEAD(4, 20, 15, 6, 0, 4, 44) };
const u16 oro_saca_060[396] = {
    CMD(CM_JSR, 8, 47, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 52, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -82, 177, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 177, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -82, 177, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3819, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(1, 1, 0, 0, 0, 0, 0, 0x3819, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 15, 6), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0,
    L4(1, 0, 582, 0, 0, 0, 0, 0x381A, -83, 177, 0, 147, 0, 0, 0),
    CMD(CM_JMP, 5, 60, 30), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, 0, 151, 0, 128, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3816, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3817, -83, 177, 0, 152, 0, 0, 0),
    CMD(CM_JMP, 5, 60, 30), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, 0, 151, 0, 128, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3819, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_RAPK2, 5, 60, 29), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 60, 30), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 24), 0, 0, 0, 0,
    L4(2, 30, 0, 0, 1, 0, 0, 0x3922, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x3923, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3924, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3925, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3926, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3927, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3668, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3669, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x366A, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366B, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366C, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366D, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366E, 0, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x366F, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3670, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3671, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: not started by a command */
const u16 oro_saca_061_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_saca_061[188] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3725, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3722, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3721, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3726, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 1, 0, 0, 0x3727, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3729, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x372A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x372B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x372D, 0, 115, 0, 0, 0, 0, 0),
    L4(6, 21, 0, 0, 1, 0, 0, 0x3727, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3721, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3722, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3724, 0, 114, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3725, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3637, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3638, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) */
const u16 oro_saca_062_head[4] = { HEAD(4, 20, 9, 7, 0, 2, 44) };
const u16 oro_saca_062[308] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3635, 0, 162, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x3650, 0, 162, 0, 0, 0, 1, 68),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3651, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3655, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3656, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3657, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3658, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3659, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -67, 105, 0, 142, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -68, 252, 0, 128, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 1, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -68, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3819, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 16390, 16387), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(250, 1, 0, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    CMD(CM_MXYT, 56, 0, 0), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_MXYT, 57, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    CMD(CM_S123, 0, 6, 1), 0, 0, 0, 0,
    L4(5, 1, 0, 0, 0, 0, 0, 0x365F, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3660, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3661, 0, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3662, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3663, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3664, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3665, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI) */
const u16 oro_saca_063_head[4] = { HEAD(4, 20, 11, 7, 0, 2, 44) };
const u16 oro_saca_063[180] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3635, 0, 162, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x3650, 0, 162, 0, 0, 0, 1, 68),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3651, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3655, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3656, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3657, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -72, 105, 0, 142, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -73, 252, 0, 128, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 1, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -73, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3819, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 62, 22), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) */
const u16 oro_saca_064_head[4] = { HEAD(4, 20, 13, 7, 0, 2, 44) };
const u16 oro_saca_064[180] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3635, 0, 162, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x3650, 0, 162, 0, 0, 0, 1, 68),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3651, 0, 162, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3655, 0, 162, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3656, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3657, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3658, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3659, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -74, 105, 0, 142, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -75, 252, 0, 128, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 1, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -75, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3819, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 62, 22), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: EX 236+KK (routine Att_JINNCHUUWATARI_EX) */
const u16 oro_saca_065_head[4] = { HEAD(4, 20, 15, 7, 0, 3, 44) };
const u16 oro_saca_065[212] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 51, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3634, 0, 162, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3635, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x3650, 0, 162, 0, 0, 0, 1, 68),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3651, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3655, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3656, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3657, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3658, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3659, 0, 162, 0, 0, 0, 0, 0),
    L4(11, 30, 582, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 0, 0x3815, -80, 105, 0, 143, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(1, 0, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -80, 252, 0, 128, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 105, 0, 0, 0, 0, 0),
    L4(1, 1, 582, 0, 0, 0, 0, 0x3817, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3818, -80, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3819, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 0, 582, 0, 0, 0, 0, 0x381A, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3815, -81, 252, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3816, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 62, 22), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command, 67 ATTACK 11 SP: not started by a command, 68 ATTACK 12 S: not started by a command, 69 ATTACK 12 M: not started by a command */
const u16 oro_saca_066_head[4] = { HEAD(4, 0, 9, 11, 0, 1, 33) };
const u16 oro_saca_066[148] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x367C, 0, 247, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x365D, 0, 14, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x365E, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x365F, 0, 14, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x3833, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3834, -69, 164, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3836, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3837, 0, 164, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3838, 0, 15, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3839, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3657, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3658, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3659, 0, 15, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: not started by a command, 71 ATTACK 12 SP: not started by a command, 72 ATTACK 13 S: not started by a command */
const u16 oro_saca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 oro_saca_070[228] = {
    CMD(CM_EXEC, 12, 21, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3A08, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 40, 0, 0, 0, 0, 0, 0x3A00, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 20, 760, 0, 0, 0, 0, 0x3A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16395), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x3A02, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16393), 0, 0, 0, 0,
    L4(10, 20, 0, 0, 0, 0, 0, 0x3A03, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16391), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x3A03, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16389), 0, 0, 0, 0,
    L4(10, 20, 0, 0, 0, 0, 0, 0x3A04, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16387), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x3A05, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, -32757, 8192), 0, 0, 0, 0,
    L4(4, 30, 0, 0, 0, 0, 0, 0x3A06, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 9, 0, 0, 0, 0, 0, 0x3A07, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3A08, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x3A09, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x3A0A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3638, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3639, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x363D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: not started by a command */
const u16 oro_saca_073_head[4] = { HEAD(6, 0, 14, 13, 0, 12, 9) };
const u16 oro_saca_073[200] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3892, 0, 123, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3893, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3894, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3895, 0, 124, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3896, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38A2, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x38A3, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x38A4, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38A5, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 581, 0, 0, 0, 0, 0x38AC, 0, 125, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x38AD, 0, 131, 0, 0, 0, 31, 1, 0, 0, 158, 0, 0),
    L6(3, 0, 333, 0, 0, 0, 0, 0x38AE, 0, 131, 0, 0, 64, 2, 122, 0, 0, 0, 0, 0),
    L6(18, 0, 0, 0, 0, 0, 0, 0x38AF, 0, 131, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x38B0, 0, 125, 0, 0, 64, 0, 0, 0, 0, 160, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x38AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0000, 0x0000, 0x0000,
};

/* combination scripts: 55 entries */
const u16* const oro_cbca[56] = {
    oro_cbca_000,  /* 0 APPEAR JUNBI 1 */
    oro_cbca_001,  /* 1 APPEAR JUNBI 2 */
    oro_cbca_002,  /* 2 APPEAR JUNBI 3 */
    oro_cbca_003,  /* 3 APPEAR JUNBI 4 */
    oro_cbca_004,  /* 4 APPEAR JUNBI 5 */
    oro_cbca_005,  /* 5 APPEAR JUNBI 6 */
    oro_cbca_006,  /* 6 APPEAR JUNBI 7 */
    oro_cbca_007,  /* 7 APPEAR JUNBI 8 */
    oro_cbca_008,  /* 8 APPEAR 1 */
    oro_cbca_009,  /* 9 APPEAR 2 */
    oro_cbca_010,  /* 10 APPEAR 3 */
    oro_cbca_011,  /* 11 APPEAR 4 */
    oro_cbca_012,  /* 12 APPEAR 5 */
    oro_cbca_013,  /* 13 APPEAR 6 */
    oro_cbca_014,  /* 14 APPEAR 7 */
    oro_cbca_015,  /* 15 APPEAR 8 */
    oro_cbca_016,  /* 16 SP APPEAR 1 */
    oro_cbca_017,  /* 17 SP APPEAR 2 */
    oro_cbca_018,  /* 18 SP APPEAR 3 */
    oro_cbca_019,  /* 19 SP APPEAR 4 */
    oro_cbca_020,  /* 20 SP APPEAR 5 */
    oro_cbca_021,  /* 21 SP APPEAR 6 */
    oro_cbca_022,  /* 22 SP APPEAR 7 */
    oro_cbca_023,  /* 23 SP APPEAR 8 */
    oro_cbca_024,  /* 24 ZANNEN 1 */
    oro_cbca_025,  /* 25 ZANNEN 2 */
    oro_cbca_026,  /* 26 ZANNEN 3 */
    oro_cbca_027,  /* 27 ZANNEN 4 */
    oro_cbca_028,  /* 28 ZANNEN 5 */
    oro_cbca_029,  /* 29 ZANNEN 6 */
    oro_cbca_030,  /* 30 ZANNEN 7 */
    oro_cbca_031,  /* 31 ZANNEN 8 */
    oro_cbca_032,  /* 32 WIN 1 */
    oro_cbca_033,  /* 33 WIN 2 */
    oro_cbca_034,  /* 34 WIN 3 */
    oro_cbca_035,  /* 35 WIN 4 */
    oro_cbca_036,  /* 36 WIN 5 */
    oro_cbca_037,  /* 37 WIN 6 */
    oro_cbca_038,  /* 38 WIN 7 */
    oro_cbca_039,  /* 39 WIN 8 */
    oro_cbca_040,  /* 40 SP WIN 1 */
    oro_cbca_041,  /* 41 SP WIN 2 */
    oro_cbca_042,  /* 42 SP WIN 3 */
    oro_cbca_043,  /* 43 SP WIN 4 */
    oro_cbca_044,  /* 44 SP WIN 5 */
    oro_cbca_045,  /* 45 SP WIN 6 */
    oro_cbca_046,  /* 46 SP WIN 7 */
    oro_cbca_047,  /* 47 SP WIN 8 */
    oro_cbca_048,  /* 48 JUDGMENT WAIT */
    oro_cbca_049,  /* 49 JUDGMENT WAIT */
    oro_cbca_050,  /* 50 JUDGMENT WAIT */
    oro_cbca_051,  /* 51 JUDGMENT WAIT */
    oro_cbca_052,  /* 52 JUDGMENT WIN */
    oro_cbca_053,  /* 53 JUDGMENT WIN */
    oro_cbca_054,  /* 54 JUDGMENT WIN */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 oro_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 oro_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 oro_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 oro_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 10, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 oro_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 oro_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 15, 1),
    CMD(CM_RJA3, 7, 16, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 oro_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_006[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 oro_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_007[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 3),
    CMD(CM_RJA3, 7, 11, 3),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 oro_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_008[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A2),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A3),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A4),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A5),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 oro_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_009[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A7),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A8),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A9),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 oro_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_010[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B5),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B6),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B7),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AF),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 oro_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_011[28] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B2),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B3),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 oro_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_012[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B8),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B9),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 oro_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_013[28] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BE),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BF),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 oro_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_014[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AD),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AE),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AF),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 oro_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_015[28] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C5),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C6),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A4),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A5),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 oro_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_016[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C2),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 oro_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_017[28] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C3),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C4),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A4),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A5),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 oro_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_018[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B8),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B9),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 oro_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_019[32] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39BD),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AD),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AE),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39AF),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39B1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 oro_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_020[40] = {
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A0),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39A1),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C7),
    L2(3, 99, 0, 0, 0, 5, 0, 0x39C8),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39C9),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39CA),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39CB),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39CC),
    L2(3, 0, 0, 0, 0, 5, 0, 0x39CD),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 oro_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_021[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 oro_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_022[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 7),
    CMD(CM_CARE, 2, 1, 7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 oro_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_023[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 oro_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 oro_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_025[12] = {
    CMD(CM_RJA, 4, 159, 1),
    CMD(CM_SAJP, 0, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 oro_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_026[28] = {
    CMD(CM_CAFR, 2, 5, 3),
    CMD(CM_CARE, 2, 5, 3),
    CMD(CM_MPCY, 40, 2, 8202),
    CMD(CM_EPCY, 0, 0, 8202),
    CMD(CM_IF_L, 0, 8202, 8192),
    CMD(CM_IF_L, 2, 8202, 8192),
    CMD(CM_JMP, 4, 40, 5),
};

/* script: 27 ZANNEN 4 */
const u16 oro_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_027[28] = {
    CMD(CM_CAFR, 2, 5, 3),
    CMD(CM_CARE, 2, 5, 3),
    CMD(CM_MPCY, 40, 2, 8202),
    CMD(CM_EPCY, 0, 0, 8202),
    CMD(CM_IF_L, 0, 8202, 8192),
    CMD(CM_IF_L, 2, 8202, 8192),
    CMD(CM_JMP, 4, 52, 5),
};

/* script: 28 ZANNEN 5 */
const u16 oro_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_028[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RJA4, 5, 57, 12),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 oro_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_029[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 33, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 oro_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_030[12] = {
    CMD(CM_RJA, 4, 157, 1),
    CMD(CM_SAJP, 0, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 oro_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_031[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 oro_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_032[16] = {
    CMD(CM_IMGS, 0, 5, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_JMP, 5, 48, 6),
};

/* script: 33 WIN 2 */
const u16 oro_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_033[16] = {
    CMD(CM_IMGS, 0, 1, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 oro_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_034[16] = {
    CMD(CM_IMGS, 0, 1, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, 1, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 oro_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_035[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 21, 1),
    CMD(CM_RJA3, 7, 22, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 oro_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_036[16] = {
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RJA7, 4, 12, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 37 WIN 6 */
const u16 oro_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_037[16] = {
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RJA7, 4, 13, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 38 WIN 7 */
const u16 oro_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_038[16] = {
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 39 WIN 8 */
const u16 oro_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_039[12] = {
    CMD(CM_RJA, 4, 156, 1),
    CMD(CM_SAJP, 0, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 oro_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_040[12] = {
    CMD(CM_RJA, 4, 158, 1),
    CMD(CM_SAJP, 0, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 oro_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_041[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 oro_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_042[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 oro_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_043[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 oro_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 oro_cbca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_045[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 oro_cbca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_046[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 46, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 oro_cbca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_047[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 oro_cbca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_048[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 18, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 oro_cbca_049_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 oro_cbca_049[20] = {
    CMD(CM_EXEC, 49, 32, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RJA4, 5, 73, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 oro_cbca_050_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 oro_cbca_050[16] = {
    CMD(CM_EXEC, 49, 33, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 oro_cbca_051_head[4] = { HEAD(2, 20, 15, 0, 0, 0, 0) };
const u16 oro_cbca_051[16] = {
    CMD(CM_EXEC, 49, 34, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN */
const u16 oro_cbca_052_head[4] = { HEAD(2, 20, 15, 0, 0, 0, 0) };
const u16 oro_cbca_052[20] = {
    CMD(CM_EXEC, 49, 35, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RJA4, 5, 60, 14),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 53 JUDGMENT WIN */
const u16 oro_cbca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_053[16] = {
    CMD(CM_IMGS, 0, 5, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 54 JUDGMENT WIN */
const u16 oro_cbca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 oro_cbca_054[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 19, 1),
    CMD(CM_RJA3, 7, 20, 1),
    CMD(CM_RET, 0, 0, 0),
};

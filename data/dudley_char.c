/*
 * DUDLEY_CHAR.C  Dudley's animation scripts and sprite part tables
 *
 * The animation scripts Dudley's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 dudley_nmca_000[], dudley_nmca_001[], dudley_nmca_002[], dudley_nmca_003[], dudley_nmca_004[], dudley_nmca_005[], dudley_nmca_006[], dudley_nmca_007[], dudley_nmca_008[], dudley_nmca_011[], dudley_nmca_012[], dudley_nmca_013[], dudley_nmca_014[], dudley_nmca_015[], dudley_nmca_016[], dudley_nmca_017[], dudley_nmca_020[], dudley_nmca_021[], dudley_nmca_022[], dudley_nmca_023[], dudley_nmca_024[], dudley_nmca_026[], dudley_nmca_027[], dudley_nmca_029[], dudley_nmca_030[], dudley_nmca_031[], dudley_nmca_032[], dudley_nmca_033[], dudley_nmca_038[], dudley_nmca_040[], dudley_nmca_041[], dudley_nmca_043[], dudley_nmca_044[], dudley_nmca_045[], dudley_nmca_046[], dudley_nmca_047[], dudley_nmca_048[], dudley_nmca_049[], dudley_nmca_051[], dudley_nmca_050[];
extern const u16 dudley_nmca_000_head[];
extern const u16 dudley_nmca_001_head[];
extern const u16 dudley_nmca_002_head[];
extern const u16 dudley_nmca_003_head[];
extern const u16 dudley_nmca_004_head[];
extern const u16 dudley_nmca_005_head[];
extern const u16 dudley_nmca_006_head[];
extern const u16 dudley_nmca_007_head[];
extern const u16 dudley_nmca_008_head[];
extern const u16 dudley_nmca_011_head[];
extern const u16 dudley_nmca_012_head[];
extern const u16 dudley_nmca_013_head[];
extern const u16 dudley_nmca_014_head[];
extern const u16 dudley_nmca_015_head[];
extern const u16 dudley_nmca_016_head[];
extern const u16 dudley_nmca_017_head[];
extern const u16 dudley_nmca_020_head[];
extern const u16 dudley_nmca_021_head[];
extern const u16 dudley_nmca_022_head[];
extern const u16 dudley_nmca_023_head[];
extern const u16 dudley_nmca_024_head[];
extern const u16 dudley_nmca_026_head[];
extern const u16 dudley_nmca_027_head[];
extern const u16 dudley_nmca_029_head[];
extern const u16 dudley_nmca_030_head[];
extern const u16 dudley_nmca_031_head[];
extern const u16 dudley_nmca_032_head[];
extern const u16 dudley_nmca_033_head[];
extern const u16 dudley_nmca_038_head[];
extern const u16 dudley_nmca_040_head[];
extern const u16 dudley_nmca_041_head[];
extern const u16 dudley_nmca_043_head[];
extern const u16 dudley_nmca_044_head[];
extern const u16 dudley_nmca_045_head[];
extern const u16 dudley_nmca_046_head[];
extern const u16 dudley_nmca_047_head[];
extern const u16 dudley_nmca_048_head[];
extern const u16 dudley_nmca_049_head[];
extern const u16 dudley_nmca_051_head[];
extern const u16 dudley_nmca_050_head[];
extern const u16 dudley_dmca_000[], dudley_dmca_001[], dudley_dmca_002[], dudley_dmca_003[], dudley_dmca_004[], dudley_dmca_006[], dudley_dmca_008[], dudley_dmca_009[], dudley_dmca_010[], dudley_dmca_018[], dudley_dmca_019[], dudley_dmca_014[], dudley_dmca_015[], dudley_dmca_022[], dudley_dmca_025[], dudley_dmca_026[], dudley_dmca_024[], dudley_dmca_029[], dudley_dmca_030[], dudley_dmca_034[], dudley_dmca_036[], dudley_dmca_048[], dudley_dmca_049[], dudley_dmca_050[], dudley_dmca_052[], dudley_dmca_056[], dudley_dmca_060[], dudley_dmca_064[], dudley_dmca_065[], dudley_dmca_066[], dudley_dmca_067[], dudley_dmca_068[], dudley_dmca_070[], dudley_dmca_071[], dudley_dmca_072[], dudley_dmca_073[], dudley_dmca_074[], dudley_dmca_075[], dudley_dmca_076[], dudley_dmca_078[], dudley_dmca_079[], dudley_dmca_080[], dudley_dmca_082[], dudley_dmca_083[], dudley_dmca_084[], dudley_dmca_090[], dudley_dmca_091[], dudley_dmca_096[], dudley_dmca_097[];
extern const u16 dudley_dmca_000_head[];
extern const u16 dudley_dmca_001_head[];
extern const u16 dudley_dmca_002_head[];
extern const u16 dudley_dmca_003_head[];
extern const u16 dudley_dmca_004_head[];
extern const u16 dudley_dmca_006_head[];
extern const u16 dudley_dmca_008_head[];
extern const u16 dudley_dmca_009_head[];
extern const u16 dudley_dmca_010_head[];
extern const u16 dudley_dmca_018_head[];
extern const u16 dudley_dmca_019_head[];
extern const u16 dudley_dmca_014_head[];
extern const u16 dudley_dmca_015_head[];
extern const u16 dudley_dmca_022_head[];
extern const u16 dudley_dmca_025_head[];
extern const u16 dudley_dmca_026_head[];
extern const u16 dudley_dmca_024_head[];
extern const u16 dudley_dmca_029_head[];
extern const u16 dudley_dmca_030_head[];
extern const u16 dudley_dmca_034_head[];
extern const u16 dudley_dmca_036_head[];
extern const u16 dudley_dmca_048_head[];
extern const u16 dudley_dmca_049_head[];
extern const u16 dudley_dmca_050_head[];
extern const u16 dudley_dmca_052_head[];
extern const u16 dudley_dmca_056_head[];
extern const u16 dudley_dmca_060_head[];
extern const u16 dudley_dmca_064_head[];
extern const u16 dudley_dmca_065_head[];
extern const u16 dudley_dmca_066_head[];
extern const u16 dudley_dmca_067_head[];
extern const u16 dudley_dmca_068_head[];
extern const u16 dudley_dmca_070_head[];
extern const u16 dudley_dmca_071_head[];
extern const u16 dudley_dmca_072_head[];
extern const u16 dudley_dmca_073_head[];
extern const u16 dudley_dmca_074_head[];
extern const u16 dudley_dmca_075_head[];
extern const u16 dudley_dmca_076_head[];
extern const u16 dudley_dmca_078_head[];
extern const u16 dudley_dmca_079_head[];
extern const u16 dudley_dmca_080_head[];
extern const u16 dudley_dmca_082_head[];
extern const u16 dudley_dmca_083_head[];
extern const u16 dudley_dmca_084_head[];
extern const u16 dudley_dmca_090_head[];
extern const u16 dudley_dmca_091_head[];
extern const u16 dudley_dmca_096_head[];
extern const u16 dudley_dmca_097_head[];
extern const u16 dudley_btca_000[], dudley_btca_001[], dudley_btca_002[], dudley_btca_003[], dudley_btca_004[], dudley_btca_005[], dudley_btca_006[], dudley_btca_007[], dudley_btca_008[], dudley_btca_009[], dudley_btca_010[], dudley_btca_011[], dudley_btca_012[], dudley_btca_013[], dudley_btca_014[], dudley_btca_015[], dudley_btca_016[], dudley_btca_017[], dudley_btca_018[], dudley_btca_019[], dudley_btca_020[], dudley_btca_021[], dudley_btca_022[], dudley_btca_023[], dudley_btca_024[], dudley_btca_025[], dudley_btca_026[], dudley_btca_027[], dudley_btca_028[], dudley_btca_029[], dudley_btca_030[], dudley_btca_031[], dudley_btca_032[], dudley_btca_033[], dudley_btca_034[], dudley_btca_035[];
extern const u16 dudley_btca_000_head[];
extern const u16 dudley_btca_001_head[];
extern const u16 dudley_btca_002_head[];
extern const u16 dudley_btca_003_head[];
extern const u16 dudley_btca_004_head[];
extern const u16 dudley_btca_005_head[];
extern const u16 dudley_btca_006_head[];
extern const u16 dudley_btca_007_head[];
extern const u16 dudley_btca_008_head[];
extern const u16 dudley_btca_009_head[];
extern const u16 dudley_btca_010_head[];
extern const u16 dudley_btca_011_head[];
extern const u16 dudley_btca_012_head[];
extern const u16 dudley_btca_013_head[];
extern const u16 dudley_btca_014_head[];
extern const u16 dudley_btca_015_head[];
extern const u16 dudley_btca_016_head[];
extern const u16 dudley_btca_017_head[];
extern const u16 dudley_btca_018_head[];
extern const u16 dudley_btca_019_head[];
extern const u16 dudley_btca_020_head[];
extern const u16 dudley_btca_021_head[];
extern const u16 dudley_btca_022_head[];
extern const u16 dudley_btca_023_head[];
extern const u16 dudley_btca_024_head[];
extern const u16 dudley_btca_025_head[];
extern const u16 dudley_btca_026_head[];
extern const u16 dudley_btca_027_head[];
extern const u16 dudley_btca_028_head[];
extern const u16 dudley_btca_029_head[];
extern const u16 dudley_btca_030_head[];
extern const u16 dudley_btca_031_head[];
extern const u16 dudley_btca_032_head[];
extern const u16 dudley_btca_033_head[];
extern const u16 dudley_btca_034_head[];
extern const u16 dudley_btca_035_head[];
extern const u16 dudley_caca_000[], dudley_caca_001[], dudley_caca_003[], dudley_caca_004[], dudley_caca_005[], dudley_caca_006[];
extern const u16 dudley_caca_000_head[];
extern const u16 dudley_caca_001_head[];
extern const u16 dudley_caca_003_head[];
extern const u16 dudley_caca_004_head[];
extern const u16 dudley_caca_005_head[];
extern const u16 dudley_caca_006_head[];
extern const u16 dudley_cuca_000[], dudley_cuca_001[], dudley_cuca_002[], dudley_cuca_003[], dudley_cuca_004[], dudley_cuca_005[], dudley_cuca_006[], dudley_cuca_007[], dudley_cuca_008[], dudley_cuca_009[], dudley_cuca_010[], dudley_cuca_011[], dudley_cuca_012[], dudley_cuca_013[], dudley_cuca_014[], dudley_cuca_015[], dudley_cuca_016[], dudley_cuca_017[], dudley_cuca_018[], dudley_cuca_019[], dudley_cuca_020[], dudley_cuca_021[], dudley_cuca_022[], dudley_cuca_023[], dudley_cuca_024[], dudley_cuca_025[], dudley_cuca_026[], dudley_cuca_027[], dudley_cuca_028[], dudley_cuca_029[], dudley_cuca_030[], dudley_cuca_031[], dudley_cuca_032[], dudley_cuca_033[], dudley_cuca_034[], dudley_cuca_035[], dudley_cuca_036[], dudley_cuca_037[], dudley_cuca_038[], dudley_cuca_039[], dudley_cuca_040[], dudley_cuca_041[], dudley_cuca_042[], dudley_cuca_043[], dudley_cuca_044[], dudley_cuca_045[], dudley_cuca_046[], dudley_cuca_047[], dudley_cuca_048[], dudley_cuca_049[], dudley_cuca_050[], dudley_cuca_051[], dudley_cuca_052[], dudley_cuca_053[], dudley_cuca_054[], dudley_cuca_055[], dudley_cuca_056[], dudley_cuca_057[], dudley_cuca_058[], dudley_cuca_059[], dudley_cuca_060[], dudley_cuca_061[], dudley_cuca_062[], dudley_cuca_063[], dudley_cuca_064[], dudley_cuca_065[], dudley_cuca_066[], dudley_cuca_067[];
extern const u16 dudley_cuca_000_head[];
extern const u16 dudley_cuca_001_head[];
extern const u16 dudley_cuca_002_head[];
extern const u16 dudley_cuca_003_head[];
extern const u16 dudley_cuca_004_head[];
extern const u16 dudley_cuca_005_head[];
extern const u16 dudley_cuca_006_head[];
extern const u16 dudley_cuca_007_head[];
extern const u16 dudley_cuca_008_head[];
extern const u16 dudley_cuca_009_head[];
extern const u16 dudley_cuca_010_head[];
extern const u16 dudley_cuca_011_head[];
extern const u16 dudley_cuca_012_head[];
extern const u16 dudley_cuca_013_head[];
extern const u16 dudley_cuca_014_head[];
extern const u16 dudley_cuca_015_head[];
extern const u16 dudley_cuca_016_head[];
extern const u16 dudley_cuca_017_head[];
extern const u16 dudley_cuca_018_head[];
extern const u16 dudley_cuca_019_head[];
extern const u16 dudley_cuca_020_head[];
extern const u16 dudley_cuca_021_head[];
extern const u16 dudley_cuca_022_head[];
extern const u16 dudley_cuca_023_head[];
extern const u16 dudley_cuca_024_head[];
extern const u16 dudley_cuca_025_head[];
extern const u16 dudley_cuca_026_head[];
extern const u16 dudley_cuca_027_head[];
extern const u16 dudley_cuca_028_head[];
extern const u16 dudley_cuca_029_head[];
extern const u16 dudley_cuca_030_head[];
extern const u16 dudley_cuca_031_head[];
extern const u16 dudley_cuca_032_head[];
extern const u16 dudley_cuca_033_head[];
extern const u16 dudley_cuca_034_head[];
extern const u16 dudley_cuca_035_head[];
extern const u16 dudley_cuca_036_head[];
extern const u16 dudley_cuca_037_head[];
extern const u16 dudley_cuca_038_head[];
extern const u16 dudley_cuca_039_head[];
extern const u16 dudley_cuca_040_head[];
extern const u16 dudley_cuca_041_head[];
extern const u16 dudley_cuca_042_head[];
extern const u16 dudley_cuca_043_head[];
extern const u16 dudley_cuca_044_head[];
extern const u16 dudley_cuca_045_head[];
extern const u16 dudley_cuca_046_head[];
extern const u16 dudley_cuca_047_head[];
extern const u16 dudley_cuca_048_head[];
extern const u16 dudley_cuca_049_head[];
extern const u16 dudley_cuca_050_head[];
extern const u16 dudley_cuca_051_head[];
extern const u16 dudley_cuca_052_head[];
extern const u16 dudley_cuca_053_head[];
extern const u16 dudley_cuca_054_head[];
extern const u16 dudley_cuca_055_head[];
extern const u16 dudley_cuca_056_head[];
extern const u16 dudley_cuca_057_head[];
extern const u16 dudley_cuca_058_head[];
extern const u16 dudley_cuca_059_head[];
extern const u16 dudley_cuca_060_head[];
extern const u16 dudley_cuca_061_head[];
extern const u16 dudley_cuca_062_head[];
extern const u16 dudley_cuca_063_head[];
extern const u16 dudley_cuca_064_head[];
extern const u16 dudley_cuca_065_head[];
extern const u16 dudley_cuca_066_head[];
extern const u16 dudley_cuca_067_head[];
extern const u16 dudley_atca_000[], dudley_atca_002[], dudley_atca_003[], dudley_atca_005[], dudley_atca_006[], dudley_atca_008[], dudley_atca_009[], dudley_atca_012[], dudley_atca_014[], dudley_atca_015[], dudley_atca_017[], dudley_atca_018[], dudley_atca_021[], dudley_atca_024[], dudley_atca_027[], dudley_atca_030[], dudley_atca_033[], dudley_atca_036[], dudley_atca_038[], dudley_atca_040[], dudley_atca_042[], dudley_atca_044[], dudley_atca_046[], dudley_atca_048[], dudley_atca_050[], dudley_atca_052[], dudley_atca_054[], dudley_atca_056[], dudley_atca_058[], dudley_atca_060[], dudley_atca_062[], dudley_atca_064[], dudley_atca_066[], dudley_atca_068[], dudley_atca_070[], dudley_atca_072[], dudley_atca_074[], dudley_atca_076[], dudley_atca_078[], dudley_atca_080[], dudley_atca_082[], dudley_atca_084[], dudley_atca_086[], dudley_atca_088[], dudley_atca_090[], dudley_atca_092[], dudley_atca_094[], dudley_atca_096[], dudley_atca_098[], dudley_atca_100[], dudley_atca_102[], dudley_atca_104[], dudley_atca_106[], dudley_atca_108[], dudley_atca_110[], dudley_atca_112[], dudley_atca_114[], dudley_atca_116[], dudley_atca_118[], dudley_atca_144[], dudley_atca_145[], dudley_atca_146[], dudley_atca_156[], dudley_atca_157[], dudley_atca_158[], dudley_atca_159[], dudley_atca_160[], dudley_atca_161[], dudley_atca_162[], dudley_atca_163[], dudley_atca_164[], dudley_atca_165[], dudley_atca_166[], dudley_atca_167[], dudley_atca_168[], dudley_atca_169[], dudley_atca_170[];
extern const u16 dudley_atca_000_head[];
extern const u16 dudley_atca_002_head[];
extern const u16 dudley_atca_003_head[];
extern const u16 dudley_atca_005_head[];
extern const u16 dudley_atca_006_head[];
extern const u16 dudley_atca_008_head[];
extern const u16 dudley_atca_009_head[];
extern const u16 dudley_atca_012_head[];
extern const u16 dudley_atca_014_head[];
extern const u16 dudley_atca_015_head[];
extern const u16 dudley_atca_017_head[];
extern const u16 dudley_atca_018_head[];
extern const u16 dudley_atca_021_head[];
extern const u16 dudley_atca_024_head[];
extern const u16 dudley_atca_027_head[];
extern const u16 dudley_atca_030_head[];
extern const u16 dudley_atca_033_head[];
extern const u16 dudley_atca_036_head[];
extern const u16 dudley_atca_038_head[];
extern const u16 dudley_atca_040_head[];
extern const u16 dudley_atca_042_head[];
extern const u16 dudley_atca_044_head[];
extern const u16 dudley_atca_046_head[];
extern const u16 dudley_atca_048_head[];
extern const u16 dudley_atca_050_head[];
extern const u16 dudley_atca_052_head[];
extern const u16 dudley_atca_054_head[];
extern const u16 dudley_atca_056_head[];
extern const u16 dudley_atca_058_head[];
extern const u16 dudley_atca_060_head[];
extern const u16 dudley_atca_062_head[];
extern const u16 dudley_atca_064_head[];
extern const u16 dudley_atca_066_head[];
extern const u16 dudley_atca_068_head[];
extern const u16 dudley_atca_070_head[];
extern const u16 dudley_atca_072_head[];
extern const u16 dudley_atca_074_head[];
extern const u16 dudley_atca_076_head[];
extern const u16 dudley_atca_078_head[];
extern const u16 dudley_atca_080_head[];
extern const u16 dudley_atca_082_head[];
extern const u16 dudley_atca_084_head[];
extern const u16 dudley_atca_086_head[];
extern const u16 dudley_atca_088_head[];
extern const u16 dudley_atca_090_head[];
extern const u16 dudley_atca_092_head[];
extern const u16 dudley_atca_094_head[];
extern const u16 dudley_atca_096_head[];
extern const u16 dudley_atca_098_head[];
extern const u16 dudley_atca_100_head[];
extern const u16 dudley_atca_102_head[];
extern const u16 dudley_atca_104_head[];
extern const u16 dudley_atca_106_head[];
extern const u16 dudley_atca_108_head[];
extern const u16 dudley_atca_110_head[];
extern const u16 dudley_atca_112_head[];
extern const u16 dudley_atca_114_head[];
extern const u16 dudley_atca_116_head[];
extern const u16 dudley_atca_118_head[];
extern const u16 dudley_atca_144_head[];
extern const u16 dudley_atca_145_head[];
extern const u16 dudley_atca_146_head[];
extern const u16 dudley_atca_156_head[];
extern const u16 dudley_atca_157_head[];
extern const u16 dudley_atca_158_head[];
extern const u16 dudley_atca_159_head[];
extern const u16 dudley_atca_160_head[];
extern const u16 dudley_atca_161_head[];
extern const u16 dudley_atca_162_head[];
extern const u16 dudley_atca_163_head[];
extern const u16 dudley_atca_164_head[];
extern const u16 dudley_atca_165_head[];
extern const u16 dudley_atca_166_head[];
extern const u16 dudley_atca_167_head[];
extern const u16 dudley_atca_168_head[];
extern const u16 dudley_atca_169_head[];
extern const u16 dudley_atca_170_head[];
extern const u16 dudley_exca_000[], dudley_exca_001[], dudley_exca_003[], dudley_exca_004[], dudley_exca_005[], dudley_exca_006[], dudley_exca_007[], dudley_exca_008[], dudley_exca_009[], dudley_exca_010[], dudley_exca_012[], dudley_exca_013[], dudley_exca_014[], dudley_exca_015[], dudley_exca_016[], dudley_exca_017[], dudley_exca_018[], dudley_exca_019[], dudley_exca_020[], dudley_exca_021[], dudley_exca_022[], dudley_exca_023[], dudley_exca_024[], dudley_exca_025[], dudley_exca_027[], dudley_exca_028[], dudley_exca_029[], dudley_exca_030[], dudley_exca_031[], dudley_exca_032[], dudley_exca_033[], dudley_exca_034[], dudley_exca_035[], dudley_exca_036[], dudley_exca_037[], dudley_exca_038[], dudley_exca_039[], dudley_exca_042[], dudley_exca_043[], dudley_exca_044[], dudley_exca_045[], dudley_exca_046[];
extern const u16 dudley_exca_000_head[];
extern const u16 dudley_exca_001_head[];
extern const u16 dudley_exca_003_head[];
extern const u16 dudley_exca_004_head[];
extern const u16 dudley_exca_005_head[];
extern const u16 dudley_exca_006_head[];
extern const u16 dudley_exca_007_head[];
extern const u16 dudley_exca_008_head[];
extern const u16 dudley_exca_009_head[];
extern const u16 dudley_exca_010_head[];
extern const u16 dudley_exca_012_head[];
extern const u16 dudley_exca_013_head[];
extern const u16 dudley_exca_014_head[];
extern const u16 dudley_exca_015_head[];
extern const u16 dudley_exca_016_head[];
extern const u16 dudley_exca_017_head[];
extern const u16 dudley_exca_018_head[];
extern const u16 dudley_exca_019_head[];
extern const u16 dudley_exca_020_head[];
extern const u16 dudley_exca_021_head[];
extern const u16 dudley_exca_022_head[];
extern const u16 dudley_exca_023_head[];
extern const u16 dudley_exca_024_head[];
extern const u16 dudley_exca_025_head[];
extern const u16 dudley_exca_027_head[];
extern const u16 dudley_exca_028_head[];
extern const u16 dudley_exca_029_head[];
extern const u16 dudley_exca_030_head[];
extern const u16 dudley_exca_031_head[];
extern const u16 dudley_exca_032_head[];
extern const u16 dudley_exca_033_head[];
extern const u16 dudley_exca_034_head[];
extern const u16 dudley_exca_035_head[];
extern const u16 dudley_exca_036_head[];
extern const u16 dudley_exca_037_head[];
extern const u16 dudley_exca_038_head[];
extern const u16 dudley_exca_039_head[];
extern const u16 dudley_exca_042_head[];
extern const u16 dudley_exca_043_head[];
extern const u16 dudley_exca_044_head[];
extern const u16 dudley_exca_045_head[];
extern const u16 dudley_exca_046_head[];
extern const u16 dudley_saca_000[], dudley_saca_001[], dudley_saca_002[], dudley_saca_024[], dudley_saca_025[], dudley_saca_026[], dudley_saca_027[], dudley_saca_028[], dudley_saca_032[], dudley_saca_036[], dudley_saca_040[], dudley_saca_041[], dudley_saca_042[], dudley_saca_043[], dudley_saca_044[], dudley_saca_045[], dudley_saca_046[], dudley_saca_047[], dudley_saca_048[], dudley_saca_052[], dudley_saca_055[], dudley_saca_056[], dudley_saca_057[], dudley_saca_058[], dudley_saca_059[], dudley_saca_061[], dudley_saca_063[], dudley_saca_065[], dudley_saca_066[], dudley_saca_067[], dudley_saca_068[], dudley_saca_069[], dudley_saca_070[], dudley_saca_071[], dudley_saca_072[], dudley_saca_073[], dudley_saca_074[], dudley_saca_075[], dudley_saca_076[], dudley_saca_077[], dudley_saca_078[], dudley_saca_079[], dudley_saca_083[], dudley_saca_086[], dudley_saca_087[];
extern const u16 dudley_saca_000_head[];
extern const u16 dudley_saca_001_head[];
extern const u16 dudley_saca_002_head[];
extern const u16 dudley_saca_024_head[];
extern const u16 dudley_saca_025_head[];
extern const u16 dudley_saca_026_head[];
extern const u16 dudley_saca_027_head[];
extern const u16 dudley_saca_028_head[];
extern const u16 dudley_saca_032_head[];
extern const u16 dudley_saca_036_head[];
extern const u16 dudley_saca_040_head[];
extern const u16 dudley_saca_041_head[];
extern const u16 dudley_saca_042_head[];
extern const u16 dudley_saca_043_head[];
extern const u16 dudley_saca_044_head[];
extern const u16 dudley_saca_045_head[];
extern const u16 dudley_saca_046_head[];
extern const u16 dudley_saca_047_head[];
extern const u16 dudley_saca_048_head[];
extern const u16 dudley_saca_052_head[];
extern const u16 dudley_saca_055_head[];
extern const u16 dudley_saca_056_head[];
extern const u16 dudley_saca_057_head[];
extern const u16 dudley_saca_058_head[];
extern const u16 dudley_saca_059_head[];
extern const u16 dudley_saca_061_head[];
extern const u16 dudley_saca_063_head[];
extern const u16 dudley_saca_065_head[];
extern const u16 dudley_saca_066_head[];
extern const u16 dudley_saca_067_head[];
extern const u16 dudley_saca_068_head[];
extern const u16 dudley_saca_069_head[];
extern const u16 dudley_saca_070_head[];
extern const u16 dudley_saca_071_head[];
extern const u16 dudley_saca_072_head[];
extern const u16 dudley_saca_073_head[];
extern const u16 dudley_saca_074_head[];
extern const u16 dudley_saca_075_head[];
extern const u16 dudley_saca_076_head[];
extern const u16 dudley_saca_077_head[];
extern const u16 dudley_saca_078_head[];
extern const u16 dudley_saca_079_head[];
extern const u16 dudley_saca_083_head[];
extern const u16 dudley_saca_086_head[];
extern const u16 dudley_saca_087_head[];
extern const u16 dudley_cbca_000[], dudley_cbca_001[], dudley_cbca_002[], dudley_cbca_003[], dudley_cbca_004[], dudley_cbca_005[], dudley_cbca_006[], dudley_cbca_007[], dudley_cbca_008[], dudley_cbca_009[], dudley_cbca_010[], dudley_cbca_011[], dudley_cbca_012[], dudley_cbca_013[], dudley_cbca_014[], dudley_cbca_015[], dudley_cbca_016[], dudley_cbca_017[], dudley_cbca_018[], dudley_cbca_019[], dudley_cbca_020[], dudley_cbca_021[], dudley_cbca_022[], dudley_cbca_023[], dudley_cbca_024[], dudley_cbca_025[], dudley_cbca_026[], dudley_cbca_027[], dudley_cbca_028[], dudley_cbca_029[], dudley_cbca_030[], dudley_cbca_031[], dudley_cbca_032[], dudley_cbca_033[], dudley_cbca_034[], dudley_cbca_035[], dudley_cbca_036[], dudley_cbca_037[], dudley_cbca_038[], dudley_cbca_039[], dudley_cbca_040[], dudley_cbca_041[], dudley_cbca_042[], dudley_cbca_043[], dudley_cbca_044[], dudley_cbca_045[], dudley_cbca_046[], dudley_cbca_047[], dudley_cbca_048[], dudley_cbca_049[], dudley_cbca_050[], dudley_cbca_051[], dudley_cbca_052[];
extern const u16 dudley_cbca_000_head[];
extern const u16 dudley_cbca_001_head[];
extern const u16 dudley_cbca_002_head[];
extern const u16 dudley_cbca_003_head[];
extern const u16 dudley_cbca_004_head[];
extern const u16 dudley_cbca_005_head[];
extern const u16 dudley_cbca_006_head[];
extern const u16 dudley_cbca_007_head[];
extern const u16 dudley_cbca_008_head[];
extern const u16 dudley_cbca_009_head[];
extern const u16 dudley_cbca_010_head[];
extern const u16 dudley_cbca_011_head[];
extern const u16 dudley_cbca_012_head[];
extern const u16 dudley_cbca_013_head[];
extern const u16 dudley_cbca_014_head[];
extern const u16 dudley_cbca_015_head[];
extern const u16 dudley_cbca_016_head[];
extern const u16 dudley_cbca_017_head[];
extern const u16 dudley_cbca_018_head[];
extern const u16 dudley_cbca_019_head[];
extern const u16 dudley_cbca_020_head[];
extern const u16 dudley_cbca_021_head[];
extern const u16 dudley_cbca_022_head[];
extern const u16 dudley_cbca_023_head[];
extern const u16 dudley_cbca_024_head[];
extern const u16 dudley_cbca_025_head[];
extern const u16 dudley_cbca_026_head[];
extern const u16 dudley_cbca_027_head[];
extern const u16 dudley_cbca_028_head[];
extern const u16 dudley_cbca_029_head[];
extern const u16 dudley_cbca_030_head[];
extern const u16 dudley_cbca_031_head[];
extern const u16 dudley_cbca_032_head[];
extern const u16 dudley_cbca_033_head[];
extern const u16 dudley_cbca_034_head[];
extern const u16 dudley_cbca_035_head[];
extern const u16 dudley_cbca_036_head[];
extern const u16 dudley_cbca_037_head[];
extern const u16 dudley_cbca_038_head[];
extern const u16 dudley_cbca_039_head[];
extern const u16 dudley_cbca_040_head[];
extern const u16 dudley_cbca_041_head[];
extern const u16 dudley_cbca_042_head[];
extern const u16 dudley_cbca_043_head[];
extern const u16 dudley_cbca_044_head[];
extern const u16 dudley_cbca_045_head[];
extern const u16 dudley_cbca_046_head[];
extern const u16 dudley_cbca_047_head[];
extern const u16 dudley_cbca_048_head[];
extern const u16 dudley_cbca_049_head[];
extern const u16 dudley_cbca_050_head[];
extern const u16 dudley_cbca_051_head[];
extern const u16 dudley_cbca_052_head[];

/* normal scripts: 52 entries */
const u16* const dudley_nmca[53] = {
    dudley_nmca_000,  /* 0 KAMAE */
    dudley_nmca_001,  /* 1 HURIMUKI */
    dudley_nmca_002,  /* 2 FRONT WALK */
    dudley_nmca_003,  /* 3 BACK WALK */
    dudley_nmca_004,  /* 4 DASH HUMIKOMI */
    dudley_nmca_005,  /* 5 DASH TOBINOKI */
    dudley_nmca_006,  /* 6 KAGAMU */
    dudley_nmca_007,  /* 7 KAGAMI KAMAE */
    dudley_nmca_008,  /* 8 KAGAMI TURN */
    dudley_nmca_008,  /* 9 KAGAMI F WALK */
    dudley_nmca_008,  /* 10 KAGAMI B WALK */
    dudley_nmca_011,  /* 11 STAND UP */
    dudley_nmca_012,  /* 12 JUMP JUNBI */
    dudley_nmca_013,  /* 13 SP JUMP JUNBI */
    dudley_nmca_014,  /* 14 JUMP FRONT */
    dudley_nmca_015,  /* 15 JUMP VERTICAL */
    dudley_nmca_016,  /* 16 JUMP BACK */
    dudley_nmca_017,  /* 17 S JUMP FRONT */
    dudley_nmca_017,  /* 18 S JUMP V */
    dudley_nmca_017,  /* 19 S JUMP BACK */
    dudley_nmca_020,  /* 20 SP JUMP FRONT */
    dudley_nmca_021,  /* 21 SP JUMP V */
    dudley_nmca_022,  /* 22 SP JUMP BACK */
    dudley_nmca_023,  /* 23 WALK END */
    dudley_nmca_024,  /* 24 PARING HEAD */
    dudley_nmca_024,  /* 25 PARING UP */
    dudley_nmca_026,  /* 26 PARING DOWN */
    dudley_nmca_027,  /* 27 PARING AIR F */
    dudley_nmca_027,  /* 28 PARING AIR B */
    dudley_nmca_029,  /* 29 GUARD HEAD */
    dudley_nmca_030,  /* 30 GUARD UP */
    dudley_nmca_031,  /* 31 GUARD DOWN */
    dudley_nmca_032,  /* 32 GUARD AIR */
    dudley_nmca_033,  /* 33 no name */
    dudley_nmca_033,  /* 34 no name */
    dudley_nmca_033,  /* 35 no name */
    dudley_nmca_033,  /* 36 no name */
    dudley_nmca_033,  /* 37 no name */
    dudley_nmca_038,  /* 38 P BREAK ZUJOU */
    dudley_nmca_038,  /* 39 P BREAK UP */
    dudley_nmca_040,  /* 40 P BREAK DOWN */
    dudley_nmca_041,  /* 41 P BREAK AIR F */
    dudley_nmca_041,  /* 42 P BREAK AIR R */
    dudley_nmca_043,  /* 43 TUKAMIHAZUSI */
    dudley_nmca_044,  /* 44 TUKAMIHAZUSARE */
    dudley_nmca_045,  /* 45 TUKAMIHAZUSI */
    dudley_nmca_046,  /* 46 TUKAMIHAZUSARE */
    dudley_nmca_047,  /* 47 no name */
    dudley_nmca_048,  /* 48 no name */
    dudley_nmca_049,  /* 49 no name */
    dudley_nmca_050,  /* 50 no name */
    dudley_nmca_051,  /* 51 no name */
    0
};

/* script: 0 KAMAE */
const u16 dudley_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_000[444] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1804, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1803, 0, 224, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1802, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1803, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1804, 0, 225, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1806, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1805, 0, 226, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1807, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1808, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1809, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x180A, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180B, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1811, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1812, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1813, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1814, 0, 229, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1813, 0, 229, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1812, 0, 229, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1811, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1809, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x180A, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180B, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180C, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180D, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180E, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x180F, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1810, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180D, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180C, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1809, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x180A, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180B, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1808, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1807, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1806, 0, 226, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1807, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1808, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1809, 0, 227, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x180A, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x180B, 0, 228, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1808, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1807, 0, 227, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1806, 0, 226, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1805, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 dudley_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_001[44] = {
    L4(4, 0, 0, 0, 1, 0, 0, 0x1815, 0, 231, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x1816, 0, 231, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x1817, 0, 231, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x1818, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 255, 0, 0, 1, 0, 0, 0x1818, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 dudley_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_002[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1819, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181A, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181B, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181C, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181D, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181E, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x181F, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1820, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1821, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1822, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1823, 0, 233, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1824, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 dudley_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_003[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1825, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1826, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1827, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1828, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1829, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182A, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182B, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182C, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182D, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182E, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x182F, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1830, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 dudley_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_004[124] = {
    CMD(CM_RJA, 0, 4, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 277, 0, 0, 0, 0, 0x1879, 0, 224, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(250, 1, 0, 0, 0, 0, 0, 0x187A, 0, 237, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x187B, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x187C, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x187D, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187E, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 dudley_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_005[136] = {
    CMD(CM_RJA, 0, 5, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 277, 0, 0, 0, 0, 0x1831, 0, 224, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 1, 277, 0, 0, 0, 0, 0x187F, 0, 224, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1880, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1881, 0, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1882, 0, 242, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1857, 0, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 dudley_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_006[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1831, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1832, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 dudley_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_007[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x183B, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183C, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183D, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183C, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183B, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183E, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183F, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1840, 0, 246, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183F, 0, 246, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183E, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 dudley_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_008[44] = {
    L4(4, 0, 0, 0, 1, 0, 0, 0x1845, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x1846, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x1847, 0, 247, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x1848, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x1848, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 dudley_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_011[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1836, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1837, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1838, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1839, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 dudley_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 dudley_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_013[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1855, 0, 250, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1855, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 dudley_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_014[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 dudley_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_015[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 dudley_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_016[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 dudley_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_017[12] = {
    CMD(CM_JSR, 8, 1, 1),
    CMD(CM_JPSS, 0, 15, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 dudley_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_020[116] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 dudley_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_021[116] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 dudley_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_022[116] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 2, 0x1849, 0, 251, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 0, 0x184A, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x184B, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184C, 0, 253, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x184D, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184E, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 dudley_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 dudley_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_024[76] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x195C, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 900, 0, 0, 0, 0, 0x195D, 0, 1, 0, 0, 0, 6, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x195E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x195F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 dudley_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_026[60] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 18, 6),
    L4(3, 0, 900, 0, 0, 0, 0, 0x1C33, 0, 9, 0, 0, 0, 6, 1),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1C34, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1999, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 dudley_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_027[124] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x1873, 0, 256, 0, 0, 0, 18, 6),
    L4(250, 0, 900, 0, 0, 0, 0, 0x1874, 0, 256, 0, 0, 0, 6, 2),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1850, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 14, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1874, 0, 11, 0, 0, 0, 18, 6),
    L4(20, 0, 900, 0, 0, 0, 0, 0x1875, 0, 11, 0, 0, 0, 6, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1876, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1876, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1877, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1878, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 dudley_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_029[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x185D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x185E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x185F, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1860, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x185C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 dudley_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_030[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1863, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1864, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1865, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1866, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1863, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 dudley_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_031[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x186D, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x186E, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x186F, 0, 9, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1870, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 dudley_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_032[104] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1873, 0, 256, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1874, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1875, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1876, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1877, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1878, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1878, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0000, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 24, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_JPSS, 6144, 0, 0), 0x0400, 0x0000, 0x0000, 0x1801,
    CMD(CM_DUMMY, 8192, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x183F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 dudley_nmca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_033[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 dudley_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_038[76] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1868, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1883, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 dudley_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_040[76] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1883, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 dudley_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1873, 0, 256, 0, 0, 0, 18, 8),
    L4(250, 0, 900, 0, 0, 0, 0, 0x1874, 0, 256, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 dudley_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_043[76] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1868, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1883, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 dudley_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_044[100] = {
    L4(2, 135, 0, 0, 0, 0, 0, 0x1A0B, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A0C, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BC2, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BC3, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BC4, 0, 258, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1BC5, 0, 258, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1BC6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 dudley_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_045[92] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1873, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 0, 900, 0, 0, 0, 0, 0x1874, 0, 256, 0, 0, 0, 25, 2),
    L4(2, 1, 0, 0, 0, 0, 0, 0x184E, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 dudley_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_046[84] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x184D, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x184E, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x184F, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1850, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 dudley_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 dudley_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 dudley_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 dudley_nmca_051_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_051[28] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B2F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B30, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 dudley_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_nmca_050[76] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1868, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1883, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const dudley_dmca[99] = {
    dudley_dmca_000,  /* 0 GUARD HEAD */
    dudley_dmca_001,  /* 1 GUARD UP */
    dudley_dmca_002,  /* 2 GUARD DOWN */
    dudley_dmca_003,  /* 3 GUARD AIR */
    dudley_dmca_004,  /* 4 HUSHIN HEAD */
    dudley_dmca_004,  /* 5 HUSHIN UP */
    dudley_dmca_006,  /* 6 HUSHIN DOWN */
    dudley_dmca_006,  /* 7 HUSHIN AIR */
    dudley_dmca_008,  /* 8 FACE S */
    dudley_dmca_009,  /* 9 FACE M */
    dudley_dmca_010,  /* 10 FACE L */
    dudley_dmca_010,  /* 11 FACE SP */
    dudley_dmca_008,  /* 12 FOOK OKU S */
    dudley_dmca_009,  /* 13 FOOK OKU M */
    dudley_dmca_014,  /* 14 FOOK OKU L */
    dudley_dmca_015,  /* 15 FOOK OKU SP */
    dudley_dmca_008,  /* 16 FOOK TEMAE S */
    dudley_dmca_009,  /* 17 FOOK TEMAE M */
    dudley_dmca_018,  /* 18 FOOK TEMAE L */
    dudley_dmca_019,  /* 19 FOOK TEMAE SP */
    dudley_dmca_008,  /* 20 UPPER S */
    dudley_dmca_009,  /* 21 UPPER M */
    dudley_dmca_022,  /* 22 UPPER L */
    dudley_dmca_022,  /* 23 UPPER SP */
    dudley_dmca_024,  /* 24 NOUTEN S */
    dudley_dmca_025,  /* 25 NOUTEN M */
    dudley_dmca_026,  /* 26 NOUTEN L */
    dudley_dmca_026,  /* 27 NOUTEN SP */
    dudley_dmca_024,  /* 28 BODY BROW S */
    dudley_dmca_029,  /* 29 BODY BROW M */
    dudley_dmca_030,  /* 30 BODY BROW L */
    dudley_dmca_030,  /* 31 BODY BROW SP */
    dudley_dmca_024,  /* 32 BODY UPPER S */
    dudley_dmca_029,  /* 33 BODY UPPER M */
    dudley_dmca_034,  /* 34 BODY UPPER L */
    dudley_dmca_034,  /* 35 BODY UPPER SP */
    dudley_dmca_036,  /* 36 TATAKI S */
    dudley_dmca_036,  /* 37 TATAKI M */
    dudley_dmca_036,  /* 38 TATAKI L */
    dudley_dmca_036,  /* 39 TATAKI SP */
    dudley_dmca_036,  /* 40 TATAKI V. S */
    dudley_dmca_036,  /* 41 TATAKI V. M */
    dudley_dmca_036,  /* 42 TATAKI V. L */
    dudley_dmca_036,  /* 43 TATAKI V. SP */
    dudley_dmca_008,  /* 44 NOBASITA TE S */
    dudley_dmca_009,  /* 45 NOBASITA TE M */
    dudley_dmca_010,  /* 46 NOBASITA TE L */
    dudley_dmca_010,  /* 47 NOBASITA TE SP */
    dudley_dmca_048,  /* 48 KAGAMI S */
    dudley_dmca_049,  /* 49 KAGAMI M */
    dudley_dmca_050,  /* 50 KAGAMI L */
    dudley_dmca_050,  /* 51 KAGAMI SP */
    dudley_dmca_052,  /* 52 KGM TATAKI S */
    dudley_dmca_052,  /* 53 KGM TATAKI M */
    dudley_dmca_052,  /* 54 KGM TATAKI L */
    dudley_dmca_052,  /* 55 KGM TATAKI SP */
    dudley_dmca_056,  /* 56 KGM TTKI V.S */
    dudley_dmca_056,  /* 57 KGM TTKI V.M */
    dudley_dmca_056,  /* 58 KGM TTKI V.L */
    dudley_dmca_056,  /* 59 KGM TTKI V.SP */
    dudley_dmca_060,  /* 60 NEKOROBI S */
    dudley_dmca_060,  /* 61 NEKOROBI M */
    dudley_dmca_060,  /* 62 NEKOROBI L */
    dudley_dmca_060,  /* 63 NEKOROBI SP */
    dudley_dmca_064,  /* 64 OKIAGARI */
    dudley_dmca_065,  /* 65 OKIAGARI F */
    dudley_dmca_066,  /* 66 OKIAGARI B */
    dudley_dmca_067,  /* 67 LOSE NO STAND */
    dudley_dmca_068,  /* 68 LOSE SONABA */
    dudley_dmca_068,  /* 69 LOSE KAGAMI */
    dudley_dmca_070,  /* 70 PIYO */
    dudley_dmca_071,  /* 71 UKEMI MOVE F */
    dudley_dmca_072,  /* 72 UKEMI MOVE R */
    dudley_dmca_073,  /* 73 SHIMEOTASARE */
    dudley_dmca_074,  /* 74 TATI TOUKETU S */
    dudley_dmca_075,  /* 75 TATI TOUKETU M */
    dudley_dmca_076,  /* 76 TATI TOUKETU L */
    dudley_dmca_076,  /* 77 TATI TOUKETU P */
    dudley_dmca_078,  /* 78 KGM TOUKETU S */
    dudley_dmca_079,  /* 79 KGM TOUKETU M */
    dudley_dmca_080,  /* 80 KGM TOUKETU L */
    dudley_dmca_080,  /* 81 KGM TOUKETU P */
    dudley_dmca_082,  /* 82 TATI DENGEKI S */
    dudley_dmca_083,  /* 83 TATI DENGEKI M */
    dudley_dmca_084,  /* 84 TATI DENGEKI L */
    dudley_dmca_084,  /* 85 TATI DENGEKI P */
    dudley_dmca_082,  /* 86 KGM DENGEKI S */
    dudley_dmca_083,  /* 87 KGM DENGEKI M */
    dudley_dmca_084,  /* 88 KGM DENGEKI L */
    dudley_dmca_084,  /* 89 KGM DENGEKI P */
    dudley_dmca_090,  /* 90 OKIAGARI FRONT */
    dudley_dmca_091,  /* 91 OKIAGARI REAR */
    dudley_dmca_008,  /* 92 TATI MOE S */
    dudley_dmca_009,  /* 93 TATI MOE M */
    dudley_dmca_010,  /* 94 TATI MOE L */
    dudley_dmca_010,  /* 95 TATI MOE SP */
    dudley_dmca_096,  /* 96 no name */
    dudley_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 dudley_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_000[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x1860, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1861, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 135, 0, 0, 0, 0, 0, 0x1862, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1860, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x185C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x185C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 dudley_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_001[84] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1868, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 135, 0, 0, 0, 0, 0, 0x1869, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1865, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1866, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1867, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1863, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x185A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 dudley_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_002[84] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x1870, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1871, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 135, 0, 0, 0, 0, 0, 0x1872, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186E, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186F, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1870, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 dudley_dmca_003_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_003[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1873, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 5), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x1874, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(250, 134, 0, 0, 0, 0, 0, 0x1867, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1863, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x185B, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x185A, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x185A, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 dudley_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_004[52] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1883, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1885, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 dudley_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_006[60] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1871, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1884, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1885, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1886, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 dudley_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_008[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x188F, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 134, 899, 0, 0, 0, 0, 0x188F, 0, 153, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x188F, 0, 153, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x1892, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 dudley_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_009[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1895, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 135, 899, 0, 0, 0, 0, 0x1894, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1894, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1890, 0, 154, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1891, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1892, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 dudley_dmca_010_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_010[160] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x1897, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 136, 898, 0, 0, 0, 0, 0x1898, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1898, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1899, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x189A, 0, 154, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x189B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 dudley_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_018[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x189F, 0, 153, 0, 0, 0, 0, 0),
    L4(1, 139, 898, 0, 0, 0, 0, 0x189F, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A0, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A1, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A2, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x18A3, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x18A4, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A5, 0, 155, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x18A6, 0, 154, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x18A7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 dudley_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_019[148] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x189E, 0, 153, 0, 0, 0, 0, 0),
    L4(1, 139, 898, 0, 0, 0, 0, 0x189F, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A0, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A1, 0, 155, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x18A2, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x18A3, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x18A4, 0, 155, 0, 0, 0, 0, 0),
    L4(16, 10, 0, 0, 0, 0, 0, 0x18A5, 0, 155, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x18A6, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x18A7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 dudley_dmca_014_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_014[208] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x1897, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 139, 898, 0, 0, 0, 0, 0x1897, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 10, 0, 0, 0, 0, 0, 0x1898, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x1899, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x18A8, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x18A9, 0, 155, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(1, 10, 0, 0, 0, 0, 0, 0x18A5, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 10, 0, 0, 0, 0, 0, 0x18A6, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x18A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 dudley_dmca_015_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_015[208] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x1896, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 138, 898, 0, 0, 0, 0, 0x1897, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1898, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x1899, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x18A8, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x18A9, 0, 155, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(16, 10, 0, 0, 0, 0, 0, 0x18A5, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 10, 0, 0, 0, 0, 0, 0x18A6, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 64, 0, 0, 0, 0, 0, 0x18A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 dudley_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_022[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1905, 0, 149, 0, 0, 0, 0, 0),
    L4(4, 136, 898, 0, 0, 0, 0, 0x18B0, 0, 150, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18B1, 0, 152, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x18B2, 0, 150, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x189B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 dudley_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_025[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18AA, 0, 157, 0, 0, 0, 0, 0),
    L4(3, 135, 899, 0, 0, 0, 0, 0x18AB, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18AC, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x18AD, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18AE, 0, 157, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 dudley_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_026[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18AB, 0, 160, 0, 0, 0, 0, 0),
    L4(3, 135, 898, 0, 0, 0, 0, 0x18AC, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18AC, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x18AD, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18AE, 0, 157, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 dudley_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_024[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18BA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 134, 899, 0, 0, 0, 0, 0x18BB, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18BC, 0, 157, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x18BD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 dudley_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_029[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18BE, 0, 157, 0, 0, 0, 0, 0),
    L4(4, 135, 899, 0, 0, 0, 0, 0x18BF, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18BB, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x18BC, 0, 157, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18BD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 dudley_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_030[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18C0, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 139, 898, 0, 0, 0, 0, 0x18C1, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18C2, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18C3, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x18C4, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18C5, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18C6, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18C7, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18C8, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x18C9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18CA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 dudley_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18AA, 0, 157, 0, 0, 0, 0, 0),
    L4(4, 136, 898, 0, 0, 0, 0, 0x18B0, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18B1, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x18B2, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x189B, 0, 159, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1855, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 dudley_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_036[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18AA, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 5, 0x18FB, 0, 160, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x18FC, 0, 160, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 dudley_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_048[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18CB, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 134, 899, 0, 0, 0, 0, 0x18CC, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18CD, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 dudley_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_049[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18CE, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 136, 899, 0, 0, 0, 0, 0x18CF, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18D0, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x18CC, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18CD, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 dudley_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_050[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18D2, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 137, 898, 0, 0, 0, 0, 0x18D2, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18D3, 0, 163, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18D4, 0, 164, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D5, 0, 163, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18D6, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18CD, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP */
const u16 dudley_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_052[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18CD, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 0, 899, 0, 0, 0, 0, 0x18CB, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18FC, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 KGM TTKI V.S, 57 KGM TTKI V.M, 58 KGM TTKI V.L, 59 KGM TTKI V.SP */
const u16 dudley_dmca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_056[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18CD, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 0, 899, 0, 0, 0, 0, 0x18CB, 0, 161, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18FC, 0, 162, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 dudley_dmca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_060[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18B7, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 2, 899, 0, 0, 0, 0, 0x18B8, 0, 136, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x18B9, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x18E5, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18E6, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18E7, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18E8, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18E9, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EA, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EB, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 136, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18EC, 0, 136, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 dudley_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_064[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1929, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x192A, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192B, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x192C, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x192C, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 dudley_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_065[156] = {
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1930, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1931, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x192A, 0, 69, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x192B, 0, 69, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x192C, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1837, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1838, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 dudley_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_066[156] = {
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192D, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1931, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1930, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x192A, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x192B, 0, 69, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x192C, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1837, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1838, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 dudley_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 dudley_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_068[244] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x188F, 0, 141, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x188F, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x1917, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x1918, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 289, 0, 0, 0, 0, 0x1919, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(14, 0, 0, 0, 0, 0, 0, 0x191A, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x191B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x191C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x191D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x191E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 288, 0, 0, 0, 0, 0x191F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1920, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1921, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1922, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1924, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1925, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1927, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1927, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 dudley_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_070[164] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x18FD, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18FE, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18FF, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1900, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18FF, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1900, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1901, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1900, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1901, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1902, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1901, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1902, 0, 133, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1903, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1902, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1903, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1904, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1903, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1904, 0, 260, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 dudley_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_071[156] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 900, 0, 0, 0, 0, 0x192F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1930, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1931, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x192A, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192B, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192C, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x192C, 0, 0, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 dudley_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_072[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 900, 0, 0, 0, 0, 0x192D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x192A, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 71, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 dudley_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_073[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1917, 0, 141, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1918, 0, 141, 0, 0, 0, 0, 0),
    L4(8, 0, 289, 0, 0, 0, 0, 0x1919, 0, 141, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x191A, 0, 141, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x191B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x191C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x191D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x191E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 288, 0, 0, 0, 0, 0x191F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1920, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1921, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1922, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1923, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1924, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1925, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1926, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1927, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1927, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 dudley_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_074[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x188F, 0, 153, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x188F, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 dudley_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_075[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1893, 0, 153, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1893, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 dudley_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_076[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1896, 0, 153, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1896, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 dudley_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_078[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18CB, 0, 161, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x18CB, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 dudley_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_079[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18CE, 0, 161, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x18CE, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 dudley_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18D1, 0, 161, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x18D1, 0, 161, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186C, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 dudley_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1842, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1843, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 dudley_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1842, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1843, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 dudley_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1842, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1841, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1843, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 dudley_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_090[164] = {
    L4(20, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x192F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1930, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1931, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x192E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x192C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1838, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 dudley_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_091[156] = {
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x192D, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1934, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1933, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1932, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1931, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1930, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x192F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x192E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x192B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x192C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1837, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 dudley_dmca_096_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_096[44] = {
    L4(3, 2, 899, 0, 0, 0, 0, 0x18ED, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x18ED, 0, 136, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18ED, 0, 136, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 136, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 136, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 dudley_dmca_097_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_dmca_097[44] = {
    L4(3, 2, 898, 0, 0, 0, 0, 0x18ED, 0, 71, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x18ED, 0, 71, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18ED, 0, 71, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 71, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 71, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const dudley_btca[37] = {
    dudley_btca_000,  /* 0 AIR NORMAL */
    dudley_btca_001,  /* 1 ASIBARAI SIRI */
    dudley_btca_002,  /* 2 ASIB TUNNOMERI */
    dudley_btca_003,  /* 3 NOKEZORI */
    dudley_btca_004,  /* 4 KUNOJI */
    dudley_btca_005,  /* 5 KIRIMOMI */
    dudley_btca_006,  /* 6 UPPER */
    dudley_btca_007,  /* 7 BODY UPPER */
    dudley_btca_008,  /* 8 HARAYARARE */
    dudley_btca_009,  /* 9 TATAKI AIR */
    dudley_btca_010,  /* 10 TTKI V. AIR */
    dudley_btca_011,  /* 11 HUMI ASIB */
    dudley_btca_012,  /* 12 FACE */
    dudley_btca_013,  /* 13 ASIB SIRI LOSE */
    dudley_btca_014,  /* 14 ASIB TUN LOSE */
    dudley_btca_015,  /* 15 DENKI */
    dudley_btca_016,  /* 16 KUNOJI NOKE */
    dudley_btca_017,  /* 17 BODY UPPER SP */
    dudley_btca_018,  /* 18 HANEAGARI */
    dudley_btca_019,  /* 19 TOUKETSU A */
    dudley_btca_020,  /* 20 BODY SLAM */
    dudley_btca_021,  /* 21 IPPONZEOI */
    dudley_btca_022,  /* 22 TOMOE RYU */
    dudley_btca_023,  /* 23 MONKEY FLIP */
    dudley_btca_024,  /* 24 TOMOE ORO */
    dudley_btca_025,  /* 25 SNAKE FANG */
    dudley_btca_026,  /* 26 FLANKEN.S */
    dudley_btca_027,  /* 27 KISHINRIKI */
    dudley_btca_028,  /* 28 SPLASH.M */
    dudley_btca_029,  /* 29 HARAIGOSHI */
    dudley_btca_030,  /* 30 ALEX B.D */
    dudley_btca_031,  /* 31 GILL */
    dudley_btca_032,  /* 32 HANEKAERI HARA */
    dudley_btca_033,  /* 33 S HANEAGARI */
    dudley_btca_034,  /* 34 TATUMAKIZANKU */
    dudley_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 dudley_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_000[68] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18B3, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 899, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x18B3, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x18B4, 0, 178, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 dudley_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18F2, 0, 179, 0, 0, 0, 0, 0),
    L4(4, 0, 898, 0, 0, 0, 14, 0x18F3, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x18F4, 0, 181, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 12, 0x18F5, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 dudley_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_btca_002[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18F2, 0, 179, 0, 0, 0, 0, 0),
    L4(4, 0, 898, 0, 0, 0, 0, 0x18F3, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18F4, 0, 181, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18F5, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 dudley_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_003[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 dudley_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_004[52] = {
    CMD(CM_RJA, 7, 6, 2), 0, 0, 0, 0,
    L4(250, 131, 898, 0, 0, 0, 0, 0x18C0, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18C1, 0, 193, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x18C2, 0, 193, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18C3, 0, 194, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 dudley_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_005[148] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1905, 0, 195, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 0, 0x1906, 0, 196, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1907, 0, 197, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1908, 0, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1909, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190A, 0, 200, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190B, 0, 201, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190C, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190D, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190E, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x190F, 0, 205, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1910, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1911, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1912, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1913, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1914, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 dudley_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_006[116] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18AF, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 898, 0, 0, 0, 0, 0x1844, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 dudley_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_007[124] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18B3, 0, 178, 0, 0, 0, 0, 0),
    L4(3, 0, 898, 0, 0, 0, 0, 0x18B4, 0, 178, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18B5, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18B6, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 dudley_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_008[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18AE, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 898, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 dudley_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_009[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 dudley_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_010[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18AA, 0, 216, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 0, 0x18FB, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18FC, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 dudley_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 dudley_btca_011[36] = {
    CMD(CM_RJA, 7, 14, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18F8, 0, 218, 0, 0, 0, 0, 0),
    L4(250, 0, 898, 0, 0, 0, 0, 0x18F9, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 dudley_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_012[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1893, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 898, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 dudley_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_013[12] = {
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 dudley_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 dudley_btca_014[12] = {
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 dudley_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_015[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x1841, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1841, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1842, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1841, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1843, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 dudley_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_016[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18C0, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18C1, 0, 193, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18C2, 0, 193, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 dudley_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_017[160] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 898, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 dudley_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_018[132] = {
    CMD(CM_RJA, 6, 18, 7), 0, 0, 0, 0,
    L4(5, 0, 898, 0, 0, 0, 0, 0x18E3, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DF, 0, 69, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 8, 0x18DE, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x18DD, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 dudley_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1896, 0, 222, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1896, 0, 222, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 dudley_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_020[20] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 dudley_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_021[20] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 dudley_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_022[60] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18F9, 0, 219, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E1, 0, 223, 0, 0, 0, 32, 84),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E0, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 223, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E4, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 dudley_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_023[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18E0, 0, 223, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 223, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 dudley_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18E0, 0, 223, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x18DF, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 dudley_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18DF, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 dudley_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_026[68] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x18F9, 0, 219, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18E0, 0, 223, 0, 0, 0, 32, 84),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18E4, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18B9, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18B8, 0, 223, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18B8, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 dudley_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_027[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 dudley_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_028[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E4, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 dudley_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_029[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 dudley_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_030[100] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18B3, 0, 178, 0, 0, 0, 0, 0),
    L4(3, 0, 898, 0, 0, 0, 0, 0x18B4, 0, 178, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18B5, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18B6, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 10, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 dudley_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x18F2, 0, 179, 0, 0, 0, 0, 0),
    L4(6, 0, 898, 0, 0, 0, 0, 0x18F3, 0, 180, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x18F4, 0, 181, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18F5, 0, 182, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 dudley_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x18AE, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 dudley_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_033[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 898, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 dudley_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_034[116] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x18AF, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 898, 0, 0, 0, 0, 0x1844, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D7, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D8, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18D9, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 dudley_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_btca_035[76] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x18DA, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DB, 0, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DC, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x18DE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 7 entries */
const u16* const dudley_caca[8] = {
    dudley_caca_000,  /* 0 CATCH 1 */
    dudley_caca_001,  /* 1 CATCH 2 */
    dudley_caca_001,  /* 2 CATCH 3 */
    dudley_caca_003,  /* 3 CATCH 4 */
    dudley_caca_004,  /* 4 CATCH 5 */
    dudley_caca_005,  /* 5 CATCH 6 */
    dudley_caca_006,  /* 6 CATCH 7 */
    0
};

/* script: 0 CATCH 1 */
const u16 dudley_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 dudley_caca_000[208] = {
    CMD(CM_NGDA, 1542, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 1, 0, 0x1A0D, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 2, 0, 0x1A0E, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 0, 902, 0, 0, 3, 0, 0x1A0F, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x1A10, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 2, 270, 0, 0, 5, 0, 0x1A11, -29, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 6, 0, 0x1A12, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 6, 0, 0, 1, 0, 0, 0x1A13, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x1A14, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x1A15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x1A16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x1A17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x1A18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x1A19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 1, 0, 0, 0x1A1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x1A1A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2, 2 CATCH 3 */
const u16 dudley_caca_001_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 1) };
const u16 dudley_caca_001[232] = {
    CMD(CM_MDAT, 0, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NGDA, 1542, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 4, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 5, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 6, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 64, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 14, 0, 0x1A28, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 15, 0, 0x1A29, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(3, 7, 0, 0, 0, 0, 0, 0x1856, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    CMD(CM_MXYT, 34, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 dudley_caca_003_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 dudley_caca_003[64] = {
    CMD(CM_NGDA, 1542, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x1A0C, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 6, 0, 0, 0, 1, 0, 0x1A0D, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 2, 0, 0x1A0E, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 dudley_caca_004_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 1) };
const u16 dudley_caca_004[148] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1801, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 7, 0, 0x1A21, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 8, 0, 0x1A22, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 9, 0, 0x1A23, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 900, 0, 0, 10, 0, 0x1A24, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 11, 0, 0x1A25, -28, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 dudley_caca_005_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 1) };
const u16 dudley_caca_005[148] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1801, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 7, 0, 0x1A21, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 8, 0, 0x1A22, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 9, 0, 0x1A23, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(2, 0, 900, 0, 0, 10, 0, 0x1A24, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 11, 0, 0x1A25, -28, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 dudley_caca_006_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 1) };
const u16 dudley_caca_006[148] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1801, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 7, 0, 0x1A21, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 8, 0, 0x1A22, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 9, 0, 0x1A23, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 0, 900, 0, 0, 10, 0, 0x1A24, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 11, 0, 0x1A25, -28, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(1, 4, 0, 0, 0, 12, 0, 0x1A26, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 13, 0, 0x1A27, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const dudley_cuca[69] = {
    dudley_cuca_000,  /* 0 ALEX ZUTUKI */
    dudley_cuca_001,  /* 1 ALEX BODY S */
    dudley_cuca_002,  /* 2 ALEX BACK D */
    dudley_cuca_003,  /* 3 ALEX POWER B */
    dudley_cuca_004,  /* 4 ALEX SLEEPER */
    dudley_cuca_005,  /* 5 RYU SEOINAGE */
    dudley_cuca_006,  /* 6 IBUKI */
    dudley_cuca_007,  /* 7 DADLEY L B */
    dudley_cuca_008,  /* 8 IBUKI KUBIORI */
    dudley_cuca_009,  /* 9 NECRO S T */
    dudley_cuca_010,  /* 10 RYU TOMOENAGE */
    dudley_cuca_011,  /* 11 YUN HIZAGERI */
    dudley_cuca_012,  /* 12 ORO KUBISIME */
    dudley_cuca_013,  /* 13 NECRO G S */
    dudley_cuca_014,  /* 14 DUDDLEY D S */
    dudley_cuca_015,  /* 15 YUN MONKEY F */
    dudley_cuca_016,  /* 16 ORO TOMOENAGE */
    dudley_cuca_017,  /* 17 ORO NIOURIKI */
    dudley_cuca_018,  /* 18 ORO GIGOKU G */
    dudley_cuca_019,  /* 19 YUN */
    dudley_cuca_020,  /* 20 NECRO SNAKE F */
    dudley_cuca_021,  /* 21 NECRO F S */
    dudley_cuca_022,  /* 22 IBUKI HARAIG */
    dudley_cuca_023,  /* 23 GILL SPLASH M */
    dudley_cuca_024,  /* 24 KEN HIZAGERI */
    dudley_cuca_025,  /* 25 ORO KISINRIKI */
    dudley_cuca_026,  /* 26 SEAN TACKLE */
    dudley_cuca_027,  /* 27 ALEX HYPER B */
    dudley_cuca_028,  /* 28 NECRO SLAM D */
    dudley_cuca_029,  /* 29 ELENA ASINAGE */
    dudley_cuca_030,  /* 30 GILL IMPACT C */
    dudley_cuca_031,  /* 31 ALEX S H B */
    dudley_cuca_032,  /* 32 ALEX F N D */
    dudley_cuca_033,  /* 33 no name */
    dudley_cuca_034,  /* 34 IBUKI */
    dudley_cuca_035,  /* 35 IBUKI YOROI D */
    dudley_cuca_036,  /* 36 no name */
    dudley_cuca_037,  /* 37 MAWARIKOMI M F */
    dudley_cuca_038,  /* 38 HUGO BODY S */
    dudley_cuca_039,  /* 39 HUGO N G T */
    dudley_cuca_040,  /* 40 HUGO M S P */
    dudley_cuca_041,  /* 41 HUGO S D B B */
    dudley_cuca_042,  /* 42 no name */
    dudley_cuca_043,  /* 43 no name */
    dudley_cuca_044,  /* 44 no name */
    dudley_cuca_045,  /* 45 no name */
    dudley_cuca_046,  /* 46 no name */
    dudley_cuca_047,  /* 47 no name */
    dudley_cuca_048,  /* 48 no name */
    dudley_cuca_049,  /* 49 no name */
    dudley_cuca_050,  /* 50 no name */
    dudley_cuca_051,  /* 51 no name */
    dudley_cuca_052,  /* 52 no name */
    dudley_cuca_053,  /* 53 no name */
    dudley_cuca_054,  /* 54 no name */
    dudley_cuca_055,  /* 55 no name */
    dudley_cuca_056,  /* 56 no name */
    dudley_cuca_057,  /* 57 no name */
    dudley_cuca_058,  /* 58 no name */
    dudley_cuca_059,  /* 59 no name */
    dudley_cuca_060,  /* 60 no name */
    dudley_cuca_061,  /* 61 no name */
    dudley_cuca_062,  /* 62 no name */
    dudley_cuca_063,  /* 63 no name */
    dudley_cuca_064,  /* 64 no name */
    dudley_cuca_065,  /* 65 no name */
    dudley_cuca_066,  /* 66 no name */
    dudley_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 dudley_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 dudley_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_001[60] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18AF),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 3),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 dudley_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_002[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    CMD(CM_RMJA, 3, 2, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 dudley_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x19CD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x19CC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x19CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x19CB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18E4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18E3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18F1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 6),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 dudley_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1881),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1905),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1900),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1900),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 dudley_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DE),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 dudley_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1802),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1804),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x195A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1959),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1958),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1957),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1957),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1905),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 dudley_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_007[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18BB),
    CMD(CM_RMJA, 3, 7, 6),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18BC),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 dudley_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1906),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 dudley_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_009[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    CMD(CM_RMJA, 3, 9, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18D7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 dudley_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18F9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 dudley_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 dudley_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18D7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 dudley_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x187E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E3),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18E3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 dudley_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18C1),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 dudley_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B8),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 dudley_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18FA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 dudley_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x191D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x191D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 11),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 dudley_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1931),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1932),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1933),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1934),
    L2(250, 0, 0, 0, 0, 0, 0, 0x192D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x192E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x192F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1930),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F1),
    L2(250, 3, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B9),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B9),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 dudley_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1801),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 dudley_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x185B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x185C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x185D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1861),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1863),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1864),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1883),
    L2(250, 0, 0, 0, 1, 0, 0, 0x188C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DB),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 dudley_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1867),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1868),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1856),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 dudley_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DE),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18DF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 dudley_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18FD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1916),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 dudley_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 dudley_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1899),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x191D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x191D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 dudley_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1876),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EC),
    L2(250, 3, 0, 0, 0, 0, 0, 0x18F1),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18EC),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 dudley_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_027[140] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_RMJA, 3, 27, 32),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 6),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 dudley_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x187E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x19CA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DB),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18DB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 dudley_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18C3),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18F4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 dudley_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1803),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B3),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18B3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 34, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 35, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 dudley_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 dudley_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E5),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 dudley_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_033[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B9),
    CMD(CM_RMJA, 3, 33, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 30, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 dudley_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B1),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 dudley_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1802),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1804),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x195A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1959),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1958),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1957),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1957),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1905),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 dudley_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1899),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E8),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 dudley_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B8),
    CMD(CM_RMJA, 3, 15, 31),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 dudley_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x188B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B4),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 3, 0, 0, 0x18AF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 3),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 dudley_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1884),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 dudley_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18ED),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18ED),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 dudley_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1916),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 dudley_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18C1),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 6, 2),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 dudley_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EC),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18EC),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 dudley_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1916),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18ED),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 dudley_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18AD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 dudley_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1911),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E6),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 dudley_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_047[108] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18B9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    CMD(CM_RMJA, 3, 47, 25),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 dudley_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x18A2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 dudley_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18C6),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E4),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E5),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 dudley_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1844),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1844),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1ADB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1ADA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18D9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DB),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18F9),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 dudley_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1863),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1917),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1893),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 dudley_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1801),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18CA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x19CB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18F9),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 dudley_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1921),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E0),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 dudley_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1906),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 34, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 35, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 dudley_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18DD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18DE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1921),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B2),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 dudley_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 2, 0, 0, 0, 0, 0, 0x18F2),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 14, 0x18F3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 dudley_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1890),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1856),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C1),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18C2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 dudley_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1893),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1905),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1884),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18EF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1884),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1885),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1886),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x193F),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18D7),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 dudley_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1858),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1859),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x185C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1917),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F0),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18D9),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 dudley_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1892),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1891),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18BC),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 dudley_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x191D),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 dudley_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189E),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189F),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A2),
    CMD(CM_PA_X, 0, -1024, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A4),
    CMD(CM_PA_X, 0, 1024, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x189B),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18AB),
    CMD(CM_PA_X, 0, 3072, 0),
    CMD(CM_PS_Y, 0, 0, 81),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B9),
    CMD(CM_PA_X, 0, -7424, 0),
    CMD(CM_PS_Y, 0, 0, 124),
    L2(250, 0, 0, 0, 2, 0, 0, 0x18B6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18E1),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 dudley_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 898, 0, 0, 0, 0, 0x18C1),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 6, 2),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 dudley_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x188B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x189B),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 dudley_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1896),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1897),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1898),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1899),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18A8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x18A5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x187B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x18B8),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18E0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 dudley_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1844),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1844),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18E8),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18B8),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 dudley_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18AE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1895),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1894),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x18B1),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x18DA),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 171 entries */
const u16* const dudley_atca[172] = {
    dudley_atca_000,  /* 0 S PUNCH A */
    dudley_atca_000,  /* 1 S PUNCH B */
    dudley_atca_002,  /* 2 S PUNCH C */
    dudley_atca_003,  /* 3 M PUNCH A */
    dudley_atca_003,  /* 4 M PUNCH B */
    dudley_atca_005,  /* 5 M PUNCH C */
    dudley_atca_006,  /* 6 L PUNCH A */
    dudley_atca_006,  /* 7 L PUNCH B */
    dudley_atca_008,  /* 8 L PUNCH C */
    dudley_atca_009,  /* 9 S KICK A */
    dudley_atca_009,  /* 10 S KICK B */
    dudley_atca_009,  /* 11 S KICK C */
    dudley_atca_012,  /* 12 M KICK A */
    dudley_atca_012,  /* 13 M KICK B */
    dudley_atca_014,  /* 14 M KICK C */
    dudley_atca_015,  /* 15 L KICK A */
    dudley_atca_015,  /* 16 L KICK B */
    dudley_atca_017,  /* 17 L KICK C */
    dudley_atca_018,  /* 18 KAGAMI P A */
    dudley_atca_018,  /* 19 KAGAMI P B */
    dudley_atca_018,  /* 20 KAGAMI P C */
    dudley_atca_021,  /* 21 KAGAMI P A */
    dudley_atca_021,  /* 22 KAGAMI P B */
    dudley_atca_021,  /* 23 KAGAMI P C */
    dudley_atca_024,  /* 24 KAGAMI P A */
    dudley_atca_024,  /* 25 KAGAMI P B */
    dudley_atca_024,  /* 26 KAGAMI P C */
    dudley_atca_027,  /* 27 KAGAMI K A */
    dudley_atca_027,  /* 28 KAGAMI K B */
    dudley_atca_027,  /* 29 KAGAMI K C */
    dudley_atca_030,  /* 30 KAGAMI K A */
    dudley_atca_030,  /* 31 KAGAMI K B */
    dudley_atca_030,  /* 32 KAGAMI K C */
    dudley_atca_033,  /* 33 KAGAMI K A */
    dudley_atca_033,  /* 34 KAGAMI K B */
    dudley_atca_033,  /* 35 KAGAMI K C */
    dudley_atca_036,  /* 36 V JUMP P S A */
    dudley_atca_036,  /* 37 V JUMP P S B */
    dudley_atca_038,  /* 38 V JUMP P M A */
    dudley_atca_038,  /* 39 V JUMP P M B */
    dudley_atca_040,  /* 40 V JUMP P L A */
    dudley_atca_040,  /* 41 V JUMP P L B */
    dudley_atca_042,  /* 42 V JUMP K S A */
    dudley_atca_042,  /* 43 V JUMP K S B */
    dudley_atca_044,  /* 44 V JUMP K M A */
    dudley_atca_044,  /* 45 V JUMP K M B */
    dudley_atca_046,  /* 46 V JUMP K L A */
    dudley_atca_046,  /* 47 V JUMP K L B */
    dudley_atca_048,  /* 48 F JUMP P S A */
    dudley_atca_048,  /* 49 F JUMP P S B */
    dudley_atca_050,  /* 50 F JUMP P M A */
    dudley_atca_050,  /* 51 F JUMP P M B */
    dudley_atca_052,  /* 52 F JUMP P L A */
    dudley_atca_052,  /* 53 F JUMP P L B */
    dudley_atca_054,  /* 54 F JUMP K S A */
    dudley_atca_054,  /* 55 F JUMP K S B */
    dudley_atca_056,  /* 56 F JUMP K M A */
    dudley_atca_056,  /* 57 F JUMP K M B */
    dudley_atca_058,  /* 58 F JUMP K L A */
    dudley_atca_058,  /* 59 F JUMP K L B */
    dudley_atca_060,  /* 60 B JUMP P S A */
    dudley_atca_060,  /* 61 B JUMP P S B */
    dudley_atca_062,  /* 62 B JUMP P M A */
    dudley_atca_062,  /* 63 B JUMP P M B */
    dudley_atca_064,  /* 64 B JUMP P L A */
    dudley_atca_064,  /* 65 B JUMP P L B */
    dudley_atca_066,  /* 66 B JUMP K S A */
    dudley_atca_066,  /* 67 B JUMP K S B */
    dudley_atca_068,  /* 68 B JUMP K M A */
    dudley_atca_068,  /* 69 B JUMP K M B */
    dudley_atca_070,  /* 70 B JUMP K L A */
    dudley_atca_070,  /* 71 B JUMP K L B */
    dudley_atca_072,  /* 72 SP V JP S P A */
    dudley_atca_072,  /* 73 SP V JP S P B */
    dudley_atca_074,  /* 74 SP V JP M P A */
    dudley_atca_074,  /* 75 SP V JP M P B */
    dudley_atca_076,  /* 76 SP V JP L P A */
    dudley_atca_076,  /* 77 SP V JP L P B */
    dudley_atca_078,  /* 78 SP V JP S K A */
    dudley_atca_078,  /* 79 SP V JP S K B */
    dudley_atca_080,  /* 80 SP V JP M K A */
    dudley_atca_080,  /* 81 SP V JP M K B */
    dudley_atca_082,  /* 82 SP V JP L K A */
    dudley_atca_082,  /* 83 SP V JP L K B */
    dudley_atca_084,  /* 84 SP F JP S P A */
    dudley_atca_084,  /* 85 SP F JP S P B */
    dudley_atca_086,  /* 86 SP F JP M P A */
    dudley_atca_086,  /* 87 SP F JP M P B */
    dudley_atca_088,  /* 88 SP F JP L P A */
    dudley_atca_088,  /* 89 SP F JP L P B */
    dudley_atca_090,  /* 90 SP F JP S K A */
    dudley_atca_090,  /* 91 SP F JP S K B */
    dudley_atca_092,  /* 92 SP F JP M K A */
    dudley_atca_092,  /* 93 SP F JP M K B */
    dudley_atca_094,  /* 94 SP F JP L K A */
    dudley_atca_094,  /* 95 SP F JP L K B */
    dudley_atca_096,  /* 96 SP B JP S P A */
    dudley_atca_096,  /* 97 SP B JP S P B */
    dudley_atca_098,  /* 98 SP B JP M P A */
    dudley_atca_098,  /* 99 SP B JP M P B */
    dudley_atca_100,  /* 100 SP B JP L P A */
    dudley_atca_100,  /* 101 SP B JP L P B */
    dudley_atca_102,  /* 102 SP B JP S K A */
    dudley_atca_102,  /* 103 SP B JP S K B */
    dudley_atca_104,  /* 104 SP B JP M K A */
    dudley_atca_104,  /* 105 SP B JP M K B */
    dudley_atca_106,  /* 106 SP B JP L K A */
    dudley_atca_106,  /* 107 SP B JP L K B */
    dudley_atca_108,  /* 108 S V JP S P A */
    dudley_atca_108,  /* 109 S V JP S P B */
    dudley_atca_110,  /* 110 S V JP M P A */
    dudley_atca_110,  /* 111 S V JP M P B */
    dudley_atca_112,  /* 112 S V JP L P A */
    dudley_atca_112,  /* 113 S V JP L P B */
    dudley_atca_114,  /* 114 S V JP S K A */
    dudley_atca_114,  /* 115 S V JP S K B */
    dudley_atca_116,  /* 116 S V JP M K A */
    dudley_atca_116,  /* 117 S V JP M K B */
    dudley_atca_118,  /* 118 S V JP L K A */
    dudley_atca_118,  /* 119 S V JP L K B */
    dudley_atca_108,  /* 120 S F JP S P A */
    dudley_atca_108,  /* 121 S F JP S P B */
    dudley_atca_110,  /* 122 S F JP M P A */
    dudley_atca_110,  /* 123 S F JP M P B */
    dudley_atca_112,  /* 124 S F JP L P A */
    dudley_atca_112,  /* 125 S F JP L P B */
    dudley_atca_114,  /* 126 S F JP S K A */
    dudley_atca_114,  /* 127 S F JP S K B */
    dudley_atca_116,  /* 128 S F JP M K A */
    dudley_atca_116,  /* 129 S F JP M K B */
    dudley_atca_118,  /* 130 S F JP L K A */
    dudley_atca_118,  /* 131 S F JP L K B */
    dudley_atca_108,  /* 132 S B JP S P A */
    dudley_atca_108,  /* 133 S B JP S P B */
    dudley_atca_110,  /* 134 S B JP M P A */
    dudley_atca_110,  /* 135 S B JP M P B */
    dudley_atca_112,  /* 136 S B JP L P A */
    dudley_atca_112,  /* 137 S B JP L P B */
    dudley_atca_114,  /* 138 S B JP S K A */
    dudley_atca_114,  /* 139 S B JP S K B */
    dudley_atca_116,  /* 140 S B JP M K A */
    dudley_atca_116,  /* 141 S B JP M K B */
    dudley_atca_118,  /* 142 S B JP L K A */
    dudley_atca_118,  /* 143 S B JP L K B */
    dudley_atca_144,  /* 144 TUKAMIKAKARI A */
    dudley_atca_145,  /* 145 TUKAMIKAKARI B */
    dudley_atca_146,  /* 146 TUKAMIKAKARI C */
    dudley_atca_144,  /* 147 TUKAMIKAKARI D */
    dudley_atca_144,  /* 148 TUKAMIKAKARI E */
    dudley_atca_144,  /* 149 TUKAMIKAKARI F */
    dudley_atca_144,  /* 150 TUKAMI AIR A */
    dudley_atca_144,  /* 151 TUKAMI AIR B */
    dudley_atca_144,  /* 152 TUKAMI AIR C */
    dudley_atca_144,  /* 153 TUKAMI AIR D */
    dudley_atca_144,  /* 154 TUKAMI AIR E */
    dudley_atca_144,  /* 155 TUKAMI AIR F */
    dudley_atca_156,  /* 156 follow-up of L KICK C, KAGAMI K A +1 */
    dudley_atca_157,  /* 157 follow-up of M PUNCH A, M KICK C */
    dudley_atca_158,  /* 158 follow-up of follow-up of M PUNCH A, M KICK C */
    dudley_atca_159,  /* 159 follow-up of S KICK A */
    dudley_atca_160,  /* 160 follow-up of follow-up of S KICK A */
    dudley_atca_161,  /* 161 no name */
    dudley_atca_162,  /* 162 no name */
    dudley_atca_163,  /* 163 follow-up of S PUNCH A */
    dudley_atca_164,  /* 164 follow-up of follow-up of S PUNCH A */
    dudley_atca_165,  /* 165 follow-up of M KICK A */
    dudley_atca_166,  /* 166 follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A */
    dudley_atca_167,  /* 167 follow-up of S PUNCH C */
    dudley_atca_168,  /* 168 no name */
    dudley_atca_169,  /* 169 follow-up of JUDGMENT WAIT */
    dudley_atca_170,  /* 170 follow-up of follow-up of JUDGMENT WAIT */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B */
const u16 dudley_atca_000_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 0) };
const u16 dudley_atca_000[108] = {
    CMD(CM_RMJA, 4, 163, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 907, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1943, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 907, 0, 0, 0, 0, 0x1944, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1941, -1, 15, 2080, 128, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1942, 0, 15, 2080, 0, 120, 0, 5),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1942, 0, 147, 2080, 0, 24, 21, 5),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1943, 0, 147, 0, 0, 16, 0, 5),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1944, 0, 1, 0, 0, 4, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1945, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1945, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 S PUNCH C */
const u16 dudley_atca_002_head[4] = { HEAD(6, 0, 0, 13, 0, 1, 0) };
const u16 dudley_atca_002[172] = {
    CMD(CM_RMJA, 4, 167, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1969, 0, 23, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x196C, 0, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 907, 0, 0, 0, 0, 0x1969, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x196A, -7, 24, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x196B, 0, 24, 0, 0, 112, 0, 3, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x196B, 0, 148, 0, 0, 16, 21, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x196C, 0, 148, 0, 0, 16, 0, 3, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x196D, 0, 1, 2080, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x196E, 0, 1, 2080, 0, 8, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x196F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 dudley_atca_003_head[4] = { HEAD(4, 0, 2, 14, 0, 1, 0) };
const u16 dudley_atca_003[92] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1946, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1948, -4, 16, 2560, 0, 104, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1949, 0, 25, 2560, 0, 104, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 dudley_atca_005_head[4] = { HEAD(4, 0, 2, 12, 0, 1, 0) };
const u16 dudley_atca_005[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1BC7, 0, 168, 0, 0, 0, 32, 93),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BC8, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1BC9, 0, 170, 0, 0, 0, 32, 94),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1BCA, 0, 171, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 135, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 136, 0), 0, 0, 0, 0,
    L4(1, 1, 0, 0, 0, 0, 0, 0x1BCB, -10, 172, 0, 128, 0, 32, 95),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BCC, 0, 173, 0, 0, 0, 32, 96),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1BCB, 0, 173, 0, 0, 0, 32, 97),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1BCC, 0, 174, 0, 0, 0, 32, 96),
    CMD(CM_ASXY, 196, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1BCD, 0, 175, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x196D, 0, 176, 0, 0, 0, 32, 99),
    L4(2, 64, 0, 0, 0, 0, 0, 0x196E, 0, 1, 0, 0, 0, 32, 100),
    L4(2, 0, 0, 0, 0, 0, 0, 0x196F, 0, 1, 0, 0, 0, 32, 101),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 32, 102),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B */
const u16 dudley_atca_006_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 dudley_atca_006[232] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x197A, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, -11, 33, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 33, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 dudley_atca_008_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 dudley_atca_008[232] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x197A, 0, 26, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1980, -11, 33, 0, 0, 64, 30, 20, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x1981, 11, 33, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 11, 33, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 dudley_atca_009_head[4] = { HEAD(4, 0, 1, 10, 0, 1, 0) };
const u16 dudley_atca_009[140] = {
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1960, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1961, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1962, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1963, -3, 17, 2560, 128, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1964, 0, 18, 2560, 0, 104, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1965, 0, 1, 2560, 0, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1966, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1967, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1967, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1968, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 dudley_atca_012_head[4] = { HEAD(4, 0, 3, 10, 0, 1, 0) };
const u16 dudley_atca_012[164] = {
    CMD(CM_RMJA, 4, 165, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 32, 13),
    L4(1, 0, 900, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1954, -5, 20, 3072, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 3072, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1956, 0, 21, 3072, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 22, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 32, 14),
    L4(1, 0, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 32, 14),
    L4(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 dudley_atca_014_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 dudley_atca_014[148] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 32, 6),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1972, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1973, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1974, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1975, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1976, -8, 27, 2560, 0, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1977, 0, 27, 2560, 0, 104, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1976, 0, 28, 2560, 0, 8, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1978, 0, 28, 2560, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1979, 0, 26, 0, 0, 0, 32, 6),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1984, 0, 26, 0, 0, 0, 32, 7),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 32, 8),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 dudley_atca_015_head[4] = { HEAD(4, 0, 5, 12, 0, 1, 0) };
const u16 dudley_atca_015[156] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x198B, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 901, 0, 0, 0, 0, 0x198C, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x198D, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x198E, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x198F, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1990, -9, 29, 0, 128, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1991, 0, 30, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 31, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 dudley_atca_017_head[4] = { HEAD(4, 0, 5, 12, 0, 1, 0) };
const u16 dudley_atca_017[148] = {
    CMD(CM_RMJA, 4, 156, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x197A, 0, 1, 0, 0, 0, 32, 5),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B41, 0, 26, 0, 0, 0, 32, 6),
    L4(4, 0, 900, 0, 0, 0, 0, 0x1B42, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B43, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1B44, 0, 5, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B45, -6, 6, 2560, 128, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B46, 6, 7, 2560, 0, 8, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B47, 0, 52, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B48, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B49, 0, 5, 0, 0, 0, 32, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 5, 0, 0, 0, 32, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 32, 8),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 dudley_atca_018_head[4] = { HEAD(4, 32, 0, 11, 0, 1, 0) };
const u16 dudley_atca_018[100] = {
    L4(3, 0, 268, 0, 0, 0, 0, 0x1999, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1999, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x199A, -12, 35, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199B, 0, 138, 0, 0, 112, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199B, 0, 138, 0, 0, 16, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199C, 0, 9, 0, 0, 16, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 4, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 dudley_atca_021_head[4] = { HEAD(6, 32, 2, 12, 0, 1, 0) };
const u16 dudley_atca_021[172] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x199E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x199F, 0, 36, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19A0, -13, 37, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19A1, 0, 38, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19A2, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A3, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A4, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A5, 0, 36, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x19A6, 0, 36, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 dudley_atca_024_head[4] = { HEAD(6, 32, 4, 12, 0, 1, 0) };
const u16 dudley_atca_024[256] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x199E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199F, 0, 36, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 902, 0, 0, 0, 0, 0x19A8, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A9, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x19AA, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AB, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -14, 40, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, 15, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 dudley_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 dudley_atca_027[116] = {
    CMD(CM_RMJA, 8, 51, 1), 0, 0, 0, 0,
    L4(4, 0, 268, 0, 0, 0, 0, 0x1999, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 0, 0x1999, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B4, -16, 44, 6688, 128, 104, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B5, 0, 45, 6688, 0, 120, 21, 4),
    CMD(CM_RMJA, 4, 156, 5), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x19B5, 0, 45, 2560, 0, 24, 0, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199C, 0, 9, 0, 0, 16, 0, 4),
    L4(3, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 4, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 dudley_atca_030_head[4] = { HEAD(6, 32, 3, 11, 0, 1, 0) };
const u16 dudley_atca_030[256] = {
    L6(5, 0, 0, 1, 0, 0, 0, 0x19B6, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 1, 0, 0, 0, 0x19B7, 0, 46, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x19B8, 0, 48, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x19B8, -17, 47, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x19B9, 17, 47, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x19BA, 0, 48, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x19BB, 0, 48, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19BC, 0, 46, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19BD, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19BE, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19BF, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19C0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19C1, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B9, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19BA, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19BB, 0, 48, 0, 0, 0, 21, 0, 0, 0, 48, 0, 0),
    CMD(CM_END, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 dudley_atca_033_head[4] = { HEAD(6, 32, 5, 12, 0, 1, 0) };
const u16 dudley_atca_033[364] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x199E, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 903, 0, 0, 0, 0, 0x199F, 0, 50, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19C2, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19C3, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x19C4, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19C5, 0, 51, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 18, 0, 0x19C6, 0, 51, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(1, 0, 0, 0, 0, 19, 0, 0x19C7, 0, 54, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 19, 0, 0x19C7, -18, 53, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 19, 0, 0x19C7, 18, 53, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x19C8, 18, 53, 0, 157, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 21, 0, 0x19C9, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 22, 0, 0x19CA, 0, 54, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(2, 0, 0, 0, 0, 23, 0, 0x19CB, 0, 51, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 0, 0, 0, 24, 0, 0x19CC, 0, 51, 0, 0, 0, 22, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 0, 0, 0, 25, 0, 0x19CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19CE, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19CF, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19D0, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19D2, 0, 50, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19D3, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19D4, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19D5, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19D6, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x19D6, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 19, 0, 0x19C7, 0, 54, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 0, 0, 0, 20, 0, 0x19C8, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 21, 0, 0x19C9, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 22, 0, 0x19CA, 0, 54, 0, 0, 0, 0, 0, 0, 0, 54, 14, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 dudley_atca_036_head[4] = { HEAD(4, 22, 0, 10, 0, 1, 0) };
const u16 dudley_atca_036[108] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 907, 0, 0, 0, 8, 0x19D9, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19DA, -19, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19DB, 19, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19DC, 0, 57, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19DD, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19DE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19DF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19E0, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 dudley_atca_038_head[4] = { HEAD(4, 22, 2, 11, 0, 1, 0) };
const u16 dudley_atca_038[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 8, 0x19D7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x19D8, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19D9, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19DA, -20, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19DB, 20, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19DC, 0, 59, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19DD, 0, 59, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19DE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19DF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19E0, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 dudley_atca_040_head[4] = { HEAD(4, 22, 4, 11, 0, 1, 0) };
const u16 dudley_atca_040[140] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 901, 0, 0, 0, 8, 0x19E1, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19E2, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 8, 0x19E3, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E6, -21, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E7, 21, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E6, 21, 61, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 10, 0x19E7, 0, 62, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x19E8, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x19E9, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EA, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 dudley_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 dudley_atca_042[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 8, 0x19ED, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EE, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EF, -22, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F0, 22, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EF, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F1, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F1, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F1, 22, 63, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 22, 63, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19F2, 0, 11, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19F3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 dudley_atca_044_head[4] = { HEAD(4, 22, 3, 8, 0, 1, 0) };
const u16 dudley_atca_044[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EB, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EC, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19ED, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x19EE, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EF, -23, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EF, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F1, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F1, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F2, 0, 11, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 dudley_atca_046_head[4] = { HEAD(4, 22, 5, 10, 0, 1, 0) };
const u16 dudley_atca_046[148] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F4, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 8, 0x19F5, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F6, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F7, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F8, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F9, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F9, -24, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19FA, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19F9, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19FA, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19FC, 0, 66, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19FD, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19FE, 0, 66, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 dudley_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 dudley_atca_048[108] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 268, 0, 0, 0, 9, 0x19D9, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DA, -19, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x19DB, 19, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DC, 0, 57, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DD, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19DE, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19DF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x19E0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 dudley_atca_050_head[4] = { HEAD(4, 20, 2, 12, 0, 1, 0) };
const u16 dudley_atca_050[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 8, 0x19D7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x19D8, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19D9, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DA, -20, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x19DB, 20, 58, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19DC, 0, 59, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19DD, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x19DE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19DF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19E0, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 dudley_atca_052_head[4] = { HEAD(4, 20, 4, 12, 0, 1, 0) };
const u16 dudley_atca_052[140] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 901, 0, 0, 0, 8, 0x19E1, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 8, 0x19E2, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19E3, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19E6, -21, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x19E7, 21, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x19E6, 21, 61, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x19E7, 0, 62, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x19E8, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19E9, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19EA, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 dudley_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 dudley_atca_054[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 8, 0x19ED, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EE, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EF, -22, 63, 2064, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19F0, 22, 63, 2064, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19EF, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F1, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F1, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F1, 22, 63, 2064, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 22, 63, 2064, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19F2, 0, 11, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19F3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 dudley_atca_056_head[4] = { HEAD(4, 20, 3, 9, 0, 1, 0) };
const u16 dudley_atca_056[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EB, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19EC, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x19ED, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 9, 0x19EE, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19EF, -23, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19EF, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F1, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F1, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19F0, 23, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x19F2, 0, 11, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19F3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 dudley_atca_058_head[4] = { HEAD(4, 20, 5, 10, 0, 1, 0) };
const u16 dudley_atca_058[148] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x19F4, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 10, 0x19F5, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x19F6, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x19F7, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x19F8, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19F9, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19F9, -24, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19FA, 0, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19F9, 0, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x19FA, 0, 65, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x19FC, 0, 66, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 9, 0x19FD, 0, 66, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x19FE, 0, 64, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 dudley_atca_060_head[4] = { HEAD(2, 24, 0, 10, 0, 1, 0) };
const u16 dudley_atca_060[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 48, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 dudley_atca_062_head[4] = { HEAD(2, 24, 2, 11, 0, 1, 0) };
const u16 dudley_atca_062[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 50, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 dudley_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 dudley_atca_064[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 52, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 dudley_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 dudley_atca_066[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 54, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 dudley_atca_068_head[4] = { HEAD(2, 24, 3, 8, 0, 1, 0) };
const u16 dudley_atca_068[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 56, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 dudley_atca_070_head[4] = { HEAD(2, 24, 5, 9, 0, 1, 0) };
const u16 dudley_atca_070[12] = {
    CMD(CM_JSR, 8, 50, 1),
    CMD(CM_JPSS, 4, 58, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 dudley_atca_072_head[4] = { HEAD(2, 28, 0, 10, 0, 1, 0) };
const u16 dudley_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 dudley_atca_074_head[4] = { HEAD(2, 28, 2, 11, 0, 1, 0) };
const u16 dudley_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 dudley_atca_076_head[4] = { HEAD(2, 28, 4, 11, 0, 1, 0) };
const u16 dudley_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 dudley_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 dudley_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 dudley_atca_080_head[4] = { HEAD(2, 28, 3, 8, 0, 1, 0) };
const u16 dudley_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 dudley_atca_082_head[4] = { HEAD(2, 28, 5, 10, 0, 1, 0) };
const u16 dudley_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 dudley_atca_084_head[4] = { HEAD(2, 26, 0, 11, 0, 1, 0) };
const u16 dudley_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 dudley_atca_086_head[4] = { HEAD(2, 26, 2, 12, 0, 1, 0) };
const u16 dudley_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 dudley_atca_088_head[4] = { HEAD(2, 26, 4, 12, 0, 1, 0) };
const u16 dudley_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 dudley_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 dudley_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 dudley_atca_092_head[4] = { HEAD(2, 26, 3, 9, 0, 1, 0) };
const u16 dudley_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 dudley_atca_094_head[4] = { HEAD(2, 26, 5, 10, 0, 1, 0) };
const u16 dudley_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 dudley_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 dudley_atca_096[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 dudley_atca_098_head[4] = { HEAD(2, 30, 2, 11, 0, 1, 0) };
const u16 dudley_atca_098[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 dudley_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 dudley_atca_100[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 dudley_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 dudley_atca_102[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 dudley_atca_104_head[4] = { HEAD(2, 30, 3, 8, 0, 1, 0) };
const u16 dudley_atca_104[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 dudley_atca_106_head[4] = { HEAD(2, 30, 5, 9, 0, 1, 0) };
const u16 dudley_atca_106[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 dudley_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 dudley_atca_108[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 dudley_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 dudley_atca_110[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 dudley_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 dudley_atca_112[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 dudley_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 dudley_atca_114[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 dudley_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 dudley_atca_116[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 dudley_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 dudley_atca_118[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 dudley_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_atca_144[108] = {
    CMD(CM_CAFR, 2, 3, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 3, 1), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, -27, 127, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A0B, 0, 257, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1A0C, 0, 257, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 dudley_atca_145_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_atca_145[16] = {
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 dudley_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_atca_146[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of L KICK C, KAGAMI K A +1 */
const u16 dudley_atca_156_head[4] = { HEAD(4, 0, 3, 10, 0, 1, 0) };
const u16 dudley_atca_156[156] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 32, 13),
    L4(1, 0, 900, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1954, -73, 20, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1956, 0, 21, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 32, 14),
    L4(1, 0, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 32, 14),
    L4(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of M PUNCH A, M KICK C */
const u16 dudley_atca_157_head[4] = { HEAD(6, 0, 3, 10, 0, 1, 0) };
const u16 dudley_atca_157[244] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1954, -74, 20, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1956, 0, 21, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of follow-up of M PUNCH A, M KICK C */
const u16 dudley_atca_158_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 dudley_atca_158[232] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x197A, 0, 26, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1980, -75, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 34, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of S KICK A */
const u16 dudley_atca_159_head[4] = { HEAD(6, 0, 3, 10, 0, 1, 0) };
const u16 dudley_atca_159[244] = {
    CMD(CM_RMJA, 4, 160, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 900, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1954, -81, 20, 2080, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 2080, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1956, 0, 21, 2080, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 2080, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of follow-up of S KICK A */
const u16 dudley_atca_160_head[4] = { HEAD(4, 32, 2, 14, 0, 1, 0) };
const u16 dudley_atca_160[92] = {
    CMD(CM_RMJA, 4, 166, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1946, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1948, -80, 16, 2112, 0, 8, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1949, 0, 25, 2112, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194A, 0, 1, 2112, 0, 8, 21, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 161 no name */
const u16 dudley_atca_161_head[4] = { HEAD(6, 32, 4, 15, 0, 1, 0) };
const u16 dudley_atca_161[232] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x197A, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1980, -82, 33, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 162 no name */
const u16 dudley_atca_162_head[4] = { HEAD(6, 32, 5, 12, 0, 1, 0) };
const u16 dudley_atca_162[244] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x198B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 901, 0, 0, 0, 0, 0x198C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x198D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1990, -83, 29, 0, 135, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1991, 0, 30, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1992, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 163 follow-up of S PUNCH A */
const u16 dudley_atca_163_head[4] = { HEAD(4, 0, 2, 14, 0, 1, 0) };
const u16 dudley_atca_163[108] = {
    CMD(CM_RMJA, 4, 164, 1), 0, 0, 0, 0,
    L4(1, 0, 909, 0, 0, 0, 0, 0x1942, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1943, 0, 147, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1946, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1948, -84, 16, 2560, 0, 8, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1949, 0, 25, 2560, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 164 follow-up of follow-up of S PUNCH A */
const u16 dudley_atca_164_head[4] = { HEAD(6, 0, 3, 10, 0, 1, 0) };
const u16 dudley_atca_164[244] = {
    L6(1, 0, 910, 0, 0, 0, 0, 0x1949, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 911, 0, 0, 0, 0, 0x1954, -85, 20, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1956, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 165 follow-up of M KICK A */
const u16 dudley_atca_165_head[4] = { HEAD(6, 32, 4, 12, 0, 1, 0) };
const u16 dudley_atca_165[256] = {
    CMD(CM_RMJA, 4, 166, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 909, 0, 0, 0, 0, 0x198B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x198D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1990, -86, 29, 2112, 136, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1991, 0, 30, 2112, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1992, 0, 31, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 2112, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 166 follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A */
const u16 dudley_atca_166_head[4] = { HEAD(6, 32, 4, 11, 0, 2, 0) };
const u16 dudley_atca_166[232] = {
    L6(1, 0, 910, 0, 0, 0, 0, 0x19A8, 0, 39, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A9, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x19AA, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AB, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -87, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, 88, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 911, 0, 0, 0, 0, 0x19AF, -88, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19B0, 88, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 167 follow-up of S PUNCH C */
const u16 dudley_atca_167_head[4] = { HEAD(4, 0, 2, 14, 0, 1, 0) };
const u16 dudley_atca_167[76] = {
    L4(1, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1948, -111, 16, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1949, 0, 25, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 168 no name */
const u16 dudley_atca_168_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 dudley_atca_168[108] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 268, 0, 0, 0, 9, 0x19D9, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DA, -93, 56, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x19DB, 93, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DC, 0, 57, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x19DD, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19DE, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x19DF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x19E0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1852, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1853, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 169 follow-up of JUDGMENT WAIT */
const u16 dudley_atca_169_head[4] = { HEAD(4, 32, 2, 12, 0, 1, 0) };
const u16 dudley_atca_169[124] = {
    CMD(CM_RMJA, 4, 170, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B5, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x199F, 0, 36, 0, 0, 0, 32, 17),
    L4(2, 0, 910, 0, 0, 0, 0, 0x19A0, -109, 37, 2114, 128, 8, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x19A1, 0, 38, 2114, 0, 8, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19A2, 0, 38, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19A3, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19A4, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19A5, 0, 36, 0, 0, 0, 32, 18),
    L4(2, 64, 0, 0, 0, 0, 0, 0x19A6, 0, 36, 0, 0, 0, 32, 18),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 170 follow-up of follow-up of JUDGMENT WAIT */
const u16 dudley_atca_170_head[4] = { HEAD(4, 32, 4, 11, 0, 1, 0) };
const u16 dudley_atca_170[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x19A2, 0, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 32, 20),
    L4(1, 0, 911, 0, 0, 0, 0, 0x19AD, -110, 40, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19AE, 0, 41, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 41, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 41, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 32, 21),
    L4(2, 64, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 32, 22),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX dudley_olc_ix_table[41] = {
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
    { { 40, 0, 0, 0 } },
    { { 47, 0, 0, 0 } },
    { { 63, 0, 0, 0 } },
    { { 64, 0, 0, 0 } },
    { { 65, 0, 0, 0 } },
    { { 66, 0, 0, 0 } },
    { { 73, 0, 0, 0 } },
    { { 74, 0, 0, 0 } },
    { { 80, 0, 0, 0 } },
    { { 81, 0, 0, 0 } },
    { { 82, 0, 0, 0 } },
    { { 130, 0, 0, 0 } },
};

const OVERLAP_PARTS dudley_overlap_char_tbl[178] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 6683 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 6684 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 6685 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 6686 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 6687 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 6, 6688 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 7, 6698 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 8, 6699 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 9, 6700 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 10, 6701 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 11, 6702 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 12, 6703 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 13, 6704 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 14, 6705 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 15, 6706 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 16, 6707 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 17, 6708 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 18, 6816 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 19, 6817 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 20, 6818 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 21, 6819 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 22, 6820 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 23, 6821 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 24, 6822 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 25, 6823 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 26, 6815 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 27, 6807 },
    { -13, 0, 0, 2, 2, 0, 2, 0, 0, 0, 6923 },
    { -13, 0, 0, 2, 2, 0, 2, 0, 0, 0, 6924 },
    { -13, 0, 0, 2, 2, 0, 2, 0, 0, 0, 6925 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6926 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6927 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6928 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6929 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6930 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6931 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6932 },
    { -13, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6933 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 39, 0 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6934 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6935 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6936 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6937 },
    { 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6938 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 6939 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 6815 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6962 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6963 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6964 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6965 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6966 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6967 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6968 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6969 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6970 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6971 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6972 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6973 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6974 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6975 },
    { 27, 103, 0, 2, 2, 0, 1, 0, 0, 0, 6976 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 47, 0 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 63, 6886 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 64, 6887 },
    { -8, 0, 0, 2, 2, 0, 255, 0, 0, 65, 6888 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 6889 },
    { 0, 0, 0, 2, 2, 0, 4, 0, 0, 0, 6890 },
    { 0, 0, 0, 2, 2, 0, 4, 0, 0, 0, 6891 },
    { 0, 0, 0, 2, 2, 0, 5, 0, 0, 0, 6892 },
    { 0, 0, 0, 2, 2, 0, 5, 0, 0, 0, 6893 },
    { 0, 0, 0, 2, 2, 0, 5, 0, 0, 0, 6894 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 72, 0 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 73, 7036 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 7037 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 7038 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 7039 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 7040 },
    { 0, 0, 0, 2, 2, 0, 3, 0, 0, 0, 7041 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 79, 7042 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 80, 7093 },
    { 0, 0, 0, 2, 2, 0, 255, 0, 0, 81, 7094 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7125 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7126 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7127 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7128 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7129 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7130 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7131 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7132 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7133 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7134 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7135 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7136 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7137 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7138 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7139 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7140 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7141 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7142 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7143 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7144 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7145 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7146 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7147 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7148 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7149 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7150 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7151 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7152 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7153 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7154 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7155 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7156 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7157 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7158 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7159 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7160 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7161 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7162 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7163 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7164 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7165 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7166 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7167 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7168 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7169 },
    { -100, 66, 0, 10, 1, 0, 1, 0, 0, 0, 7170 },
    { -100, 66, 0, 10, 2, 0, 1, 0, 0, 0, 7171 },
    { 0, 0, 0, 0, 1, 0, 250, 0, 0, 130, 0 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7172 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7173 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7174 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7175 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7176 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7177 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7178 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7179 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7180 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7181 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7182 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7183 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7184 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7185 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7186 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7187 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7188 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7189 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7190 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7191 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7192 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7193 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7194 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7195 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7196 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7197 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7198 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7199 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7200 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7201 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7202 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7203 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7204 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7205 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7206 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7207 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7208 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7209 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7210 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7211 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7212 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7213 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7214 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7215 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7216 },
    { 0, 151, 0, 10, 1, 0, 1, 0, 0, 0, 7217 },
    { 0, 151, 0, 10, 2, 0, 1, 0, 0, 0, 7218 },
    { 0, 0, 0, 0, 1, 0, 250, 0, 0, 178, 0 },
};

const CatchTable dudley_rival_catch_tbl[360] = {
    { -48, 0, 2, 1, 1 },
    { -37, 0, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -27, -3, 2, 1, 1 },
    { -32, -6, 2, 1, 1 },
    { -51, 0, 2, 1, 1 },
    { -52, 0, 2, 1, 1 },
    { -41, -3, 2, 1, 1 },
    { -44, 0, 2, 1, 1 },
    { -32, 0, 2, 1, 1 },
    { -27, -3, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -48, 0, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -27, 0, 2, 1, 1 },
    { -32, 0, 2, 1, 1 },
    { -49, 5, 2, 1, 1 },
    { -50, 0, 2, 1, 1 },
    { -51, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -40, 0, 2, 1, 2 },
    { -41, 0, 2, 1, 2 },
    { -30, 11, 2, 1, 2 },
    { -19, 14, 2, 1, 2 },
    { -43, -8, 2, 1, 2 },
    { -51, 0, 2, 1, 2 },
    { -51, 1, 2, 1, 2 },
    { -42, 1, 2, 1, 2 },
    { -46, 8, 2, 1, 2 },
    { -51, 15, 2, 1, 2 },
    { -19, 14, 2, 1, 2 },
    { -30, 11, 2, 1, 2 },
    { -30, 11, 2, 1, 2 },
    { -40, 0, 2, 1, 2 },
    { -30, 11, 2, 1, 2 },
    { -30, 11, 2, 1, 2 },
    { -42, 16, 2, 1, 2 },
    { -44, 8, 2, 1, 2 },
    { -42, 0, 2, 1, 2 },
    { -54, 10, 2, 1, 2 },
    { -60, 10, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -31, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -50, 21, 2, 1, 3 },
    { -35, 18, 2, 1, 3 },
    { -32, -5, 2, 1, 3 },
    { -40, 4, 2, 1, 3 },
    { -59, -2, 2, 1, 3 },
    { -52, 8, 2, 1, 3 },
    { -37, 9, 2, 1, 3 },
    { -51, 16, 2, 1, 3 },
    { -35, 18, 2, 1, 3 },
    { -50, 21, 2, 1, 3 },
    { -50, 21, 2, 1, 3 },
    { -31, 0, 2, 1, 3 },
    { -50, 21, 2, 1, 3 },
    { -50, 21, 2, 1, 3 },
    { -46, 18, 2, 1, 3 },
    { -72, 26, 2, 1, 3 },
    { -71, 4, 2, 1, 3 },
    { -54, 10, 2, 1, 3 },
    { -60, 10, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -33, 0, 2, 1, 4 },
    { -25, 0, 2, 1, 4 },
    { -51, 23, 2, 1, 4 },
    { -34, 23, 2, 1, 4 },
    { -29, -3, 2, 1, 3 },
    { -39, 0, 2, 1, 4 },
    { -59, 4, 2, 1, 4 },
    { -50, 6, 2, 1, 3 },
    { -38, 12, 2, 1, 4 },
    { -50, 15, 2, 1, 3 },
    { -34, 23, 2, 1, 4 },
    { -51, 23, 2, 1, 4 },
    { -51, 23, 2, 1, 4 },
    { -33, 0, 2, 1, 4 },
    { -51, 23, 2, 1, 4 },
    { -51, 23, 2, 1, 4 },
    { -38, 8, 2, 1, 4 },
    { -72, 26, 2, 1, 4 },
    { -72, 5, 2, 1, 3 },
    { -54, 10, 2, 1, 4 },
    { -58, 10, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -42, 0, 2, 1, 5 },
    { -30, 0, 2, 1, 5 },
    { -50, 21, 2, 1, 4 },
    { -33, 16, 2, 1, 3 },
    { -30, -3, 2, 1, 3 },
    { -39, 0, 2, 1, 4 },
    { -52, 4, 2, 1, 5 },
    { -52, 8, 2, 1, 3 },
    { -44, 8, 2, 1, 5 },
    { -50, 16, 2, 1, 4 },
    { -33, 16, 2, 1, 3 },
    { -50, 21, 2, 1, 4 },
    { -50, 21, 2, 1, 4 },
    { -42, 0, 2, 1, 5 },
    { -50, 21, 2, 1, 4 },
    { -50, 21, 2, 1, 4 },
    { -38, 8, 2, 1, 4 },
    { -72, 26, 2, 1, 4 },
    { -61, 0, 2, 1, 4 },
    { -54, 10, 2, 1, 4 },
    { -58, 10, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -38, 0, 2, 1, 6 },
    { -24, 0, 2, 1, 3 },
    { -50, 23, 2, 1, 4 },
    { -44, 6, 2, 1, 5 },
    { -32, -5, 2, 1, 3 },
    { -51, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 3 },
    { -50, 6, 2, 1, 3 },
    { -42, 0, 2, 1, 6 },
    { -51, 15, 2, 1, 4 },
    { -44, 6, 2, 1, 5 },
    { -50, 23, 2, 1, 4 },
    { -50, 23, 2, 1, 4 },
    { -38, 0, 2, 1, 6 },
    { -50, 23, 2, 1, 4 },
    { -50, 23, 2, 1, 4 },
    { -38, 8, 2, 1, 3 },
    { -72, 26, 2, 1, 3 },
    { -86, 0, 2, 1, 3 },
    { -54, 10, 2, 1, 1 },
    { -60, 12, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 2, 1, 7 },
    { -37, 0, 2, 1, 1 },
    { -50, 21, 2, 1, 4 },
    { -47, 16, 2, 1, 5 },
    { -29, -3, 2, 1, 3 },
    { -51, 0, 2, 1, 1 },
    { -47, 0, 2, 1, 6 },
    { -50, 8, 2, 1, 3 },
    { -42, 0, 2, 1, 7 },
    { -51, 16, 2, 1, 4 },
    { -47, 16, 2, 1, 5 },
    { -50, 21, 2, 1, 4 },
    { -50, 21, 2, 1, 4 },
    { -48, 0, 2, 1, 7 },
    { -50, 21, 2, 1, 4 },
    { -50, 21, 2, 1, 4 },
    { -36, 8, 2, 1, 5 },
    { -68, 25, 2, 1, 5 },
    { -82, 8, 2, 1, 5 },
    { -54, 10, 2, 1, 1 },
    { -60, 12, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 2, 1, 8 },
    { -37, 0, 2, 1, 6 },
    { -50, 23, 2, 1, 5 },
    { -50, 23, 2, 1, 6 },
    { -30, -3, 2, 1, 4 },
    { -51, 0, 2, 1, 5 },
    { -51, 0, 2, 1, 1 },
    { -50, 6, 2, 1, 4 },
    { -54, 6, 2, 1, 8 },
    { -77, 1, 2, 1, 5 },
    { -50, 23, 2, 1, 6 },
    { -50, 23, 2, 1, 5 },
    { -50, 23, 2, 1, 5 },
    { -48, 0, 2, 1, 8 },
    { -50, 23, 2, 1, 5 },
    { -50, 23, 2, 1, 5 },
    { -52, 12, 2, 1, 6 },
    { -80, 34, 2, 1, 6 },
    { -82, 16, 2, 1, 6 },
    { -84, 8, 2, 1, 5 },
    { -60, 14, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 2 },
    { -34, -3, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -35, 0, 2, 1, 2 },
    { -55, 0, 2, 1, 2 },
    { -34, 0, 2, 1, 2 },
    { -47, 0, 2, 1, 2 },
    { -36, 0, 2, 1, 2 },
    { -71, -3, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -50, 0, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -22, 0, 2, 1, 2 },
    { -48, 0, 2, 1, 2 },
    { -56, 4, 2, 1, 2 },
    { -50, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -52, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -41, 0, 2, 1, 3 },
    { -35, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -53, 0, 2, 1, 3 },
    { -18, 0, 2, 1, 3 },
    { -39, 0, 2, 1, 3 },
    { -34, 0, 2, 1, 3 },
    { -68, -3, 2, 1, 3 },
    { -69, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 3 },
    { -41, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 3 },
    { -15, 0, 2, 1, 3 },
    { -46, 0, 2, 1, 3 },
    { -52, 4, 2, 1, 3 },
    { -44, 0, 2, 1, 3 },
    { -56, 0, 2, 1, 3 },
    { -52, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 4 },
    { -29, 0, 2, 1, 4 },
    { -15, 1, 2, 1, 4 },
    { -51, 10, 2, 1, 4 },
    { -31, 3, 2, 1, 4 },
    { -60, 5, 2, 1, 4 },
    { -12, 4, 2, 1, 4 },
    { -27, 3, 2, 1, 4 },
    { -23, 0, 2, 1, 4 },
    { -63, -3, 2, 1, 4 },
    { -51, 10, 2, 1, 4 },
    { -15, 1, 2, 1, 4 },
    { -15, 1, 2, 1, 4 },
    { -50, 0, 2, 1, 4 },
    { -15, 1, 2, 1, 4 },
    { -15, 1, 2, 1, 4 },
    { -42, 0, 2, 1, 4 },
    { -46, 6, 2, 1, 4 },
    { -50, 0, 2, 1, 4 },
    { -52, 6, 2, 1, 4 },
    { -48, 6, 2, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -30, -17, 2, 1, 5 },
    { -57, 0, 2, 1, 5 },
    { -38, 1, 2, 1, 5 },
    { -53, 10, 2, 1, 5 },
    { -47, -3, 2, 1, 5 },
    { -77, 1, 2, 1, 5 },
    { -39, 0, 2, 1, 5 },
    { -26, 15, 2, 1, 5 },
    { -20, 2, 2, 1, 5 },
    { -62, -5, 2, 1, 5 },
    { -53, 10, 2, 1, 5 },
    { -38, 1, 2, 1, 5 },
    { -38, 1, 2, 1, 5 },
    { -30, -17, 2, 1, 5 },
    { -38, 1, 2, 1, 5 },
    { -38, 1, 2, 1, 5 },
    { -24, 4, 2, 1, 5 },
    { -32, 18, 2, 1, 5 },
    { -38, 0, 2, 1, 5 },
    { -72, 10, 2, 1, 5 },
    { -48, 8, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -2, -12, 2, 1, 6 },
    { -9, -10, 2, 1, 6 },
    { -18, 22, 2, 1, 6 },
    { -33, 23, 2, 1, 6 },
    { -18, 17, 2, 1, 6 },
    { -54, 3, 2, 1, 6 },
    { 3, 8, 2, 1, 6 },
    { -10, 13, 2, 1, 6 },
    { -33, 23, 2, 1, 6 },
    { -5, 23, 2, 1, 6 },
    { -33, 23, 2, 1, 6 },
    { -18, 22, 2, 1, 6 },
    { -18, 22, 2, 1, 6 },
    { -2, -12, 2, 1, 6 },
    { -18, 22, 2, 1, 6 },
    { -18, 22, 2, 1, 6 },
    { -20, 12, 2, 1, 6 },
    { -6, 20, 2, 1, 6 },
    { 4, 4, 2, 1, 6 },
    { -54, 3, 2, 1, 6 },
    { -16, 6, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 84, 6, 1, 0, 7 },
    { 34, 12, 1, 0, 7 },
    { 56, 33, 1, 0, 7 },
    { 33, 21, 2, 0, 7 },
    { 40, 21, 1, 0, 7 },
    { 26, 21, 1, 0, 7 },
    { 103, -1, 2, 0, 7 },
    { 64, 21, 1, 0, 7 },
    { 73, 42, 1, 0, 7 },
    { 116, 32, 1, 0, 7 },
    { 33, 21, 2, 0, 7 },
    { 56, 33, 1, 0, 7 },
    { 56, 33, 1, 0, 7 },
    { 84, 6, 1, 0, 7 },
    { 56, 33, 1, 0, 7 },
    { 56, 33, 1, 0, 7 },
    { 64, 22, 1, 0, 7 },
    { 64, 42, 1, 0, 7 },
    { 64, 12, 1, 0, 7 },
    { 26, 21, 1, 0, 7 },
    { 58, 12, 1, 0, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 1 },
    { -34, -3, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -59, 0, 2, 1, 1 },
    { -45, 0, 2, 1, 1 },
    { -45, 0, 2, 1, 1 },
    { -66, 0, 2, 1, 1 },
    { -59, 0, 2, 1, 1 },
    { -73, 0, 2, 1, 1 },
    { -87, 0, 2, 1, 1 },
    { -59, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -50, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -46, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 1 },
    { -80, 2, 2, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -62, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
};

/* extra scripts: 47 entries */
const u16* const dudley_exca[48] = {
    dudley_exca_000,  /* 0 follow-up of AIR NORMAL */
    dudley_exca_001,  /* 1 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 4 */
    dudley_exca_001,  /* 2 follow-up of APPEAR JUNBI 3 */
    dudley_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    dudley_exca_004,  /* 4 follow-up of APPEAR JUNBI 5 */
    dudley_exca_005,  /* 5 follow-up of NOKEZORI, HARAYARARE +22 */
    dudley_exca_006,  /* 6 follow-up of KUNOJI, TOUKETSU A +1 */
    dudley_exca_007,  /* 7 follow-up of TATAKI S, KGM TATAKI S +5 */
    dudley_exca_008,  /* 8 follow-up of KIRIMOMI, TOMOE RYU +3 */
    dudley_exca_009,  /* 9 follow-up of UPPER, BODY UPPER +4 */
    dudley_exca_010,  /* 10 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 4 */
    dudley_exca_010,  /* 11 follow-up of APPEAR JUNBI 3 */
    dudley_exca_012,  /* 12 follow-up of APPEAR JUNBI 5 */
    dudley_exca_013,  /* 13 no name */
    dudley_exca_014,  /* 14 follow-up of HUMI ASIB */
    dudley_exca_015,  /* 15 no name */
    dudley_exca_016,  /* 16 no name */
    dudley_exca_017,  /* 17 no name */
    dudley_exca_018,  /* 18 no name */
    dudley_exca_019,  /* 19 no name */
    dudley_exca_020,  /* 20 no name */
    dudley_exca_021,  /* 21 no name */
    dudley_exca_022,  /* 22 no name */
    dudley_exca_023,  /* 23 follow-up of APPEAR JUNBI 7, APPEAR JUNBI 8 +2 */
    dudley_exca_024,  /* 24 follow-up of APPEAR JUNBI 7, APPEAR JUNBI 8 +2 */
    dudley_exca_025,  /* 25 follow-up of APPEAR 3 */
    dudley_exca_025,  /* 26 follow-up of APPEAR 3 */
    dudley_exca_027,  /* 27 no name */
    dudley_exca_028,  /* 28 follow-up of APPEAR 5 */
    dudley_exca_029,  /* 29 follow-up of APPEAR 5 */
    dudley_exca_030,  /* 30 follow-up of APPEAR 2 */
    dudley_exca_031,  /* 31 follow-up of APPEAR 2 */
    dudley_exca_032,  /* 32 follow-up of SP WIN 1 */
    dudley_exca_033,  /* 33 follow-up of SP WIN 1 */
    dudley_exca_034,  /* 34 follow-up of GILL IMPACT C */
    dudley_exca_035,  /* 35 follow-up of GILL IMPACT C */
    dudley_exca_036,  /* 36 follow-up of SP WIN 2 */
    dudley_exca_037,  /* 37 follow-up of SP WIN 2 */
    dudley_exca_038,  /* 38 follow-up of SP WIN 3 */
    dudley_exca_039,  /* 39 follow-up of SP WIN 3 */
    dudley_exca_038,  /* 40 follow-up of SP WIN 4 */
    dudley_exca_039,  /* 41 follow-up of SP WIN 4 */
    dudley_exca_042,  /* 42 follow-up of SP WIN 5 */
    dudley_exca_043,  /* 43 follow-up of SP WIN 5 */
    dudley_exca_044,  /* 44 follow-up of JUDGMENT WAIT */
    dudley_exca_045,  /* 45 follow-up of JUDGMENT WAIT */
    dudley_exca_046,  /* 46 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 dudley_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_000[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x19FF, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A00, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A01, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A02, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1A03, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A04, 0, 10, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A05, 0, 10, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 10, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1851, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 3 */
const u16 dudley_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_001[60] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 dudley_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_003[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18F6, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 5 */
const u16 dudley_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_004[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of NOKEZORI, HARAYARARE +22 */
const u16 dudley_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_005[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18DF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E0, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E1, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E2, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E3, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E4, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of KUNOJI, TOUKETSU A +1 */
const u16 dudley_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_006[116] = {
    L4(4, 1, 0, 0, 0, 0, 0, 0x18EE, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18EF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x18F0, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18F1, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of TATAKI S, KGM TATAKI S +5 */
const u16 dudley_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_007[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18B9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KIRIMOMI, TOMOE RYU +3 */
const u16 dudley_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_008[76] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x1915, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1916, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of UPPER, BODY UPPER +4 */
const u16 dudley_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_009[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18DF, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E0, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E1, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E2, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E3, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E4, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2, APPEAR JUNBI 4, 11 follow-up of APPEAR JUNBI 3 */
const u16 dudley_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_010[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1832, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 5 */
const u16 dudley_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_012[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1832, 0, 9, 0, 0, 0, 21, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 dudley_exca_013_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_013[20] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of HUMI ASIB */
const u16 dudley_exca_014_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_014[108] = {
    CMD(CM_PA_X, 0, 12288, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x18FA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E4, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 dudley_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_015[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 3, 0, 0, 0x18D9, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 3, 0, 0, 0x18D7, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 3, 0, 0, 0x18D7, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x18B4, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 3, 0, 0, 0x18B4, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 dudley_exca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_016[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 10, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18DF, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 dudley_exca_017_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_017[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 2, 0, 0, 0x18D9, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x18D7, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x18D7, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x18B4, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x18B4, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 dudley_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_018[68] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x18D8, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 3, 0, 0, 0x18D7, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x1909, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x1910, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x1911, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 dudley_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_019[60] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 3, 0, 0, 0x18F4, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x18F3, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x18B6, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x18B5, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 3, 0, 0, 0x18B5, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 dudley_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_020[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x18F3, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x18B6, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 dudley_exca_021_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_021[124] = {
    L4(1, 1, 0, 0, 1, 0, 0, 0x18E0, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x18E1, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E2, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E3, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E4, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 dudley_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_022[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x18E4, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x18E5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 7, APPEAR JUNBI 8 +2 */
const u16 dudley_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_023[84] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x183B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 7, APPEAR JUNBI 8 +2 */
const u16 dudley_exca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_024[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR 3, 26 follow-up of APPEAR 3 */
const u16 dudley_exca_025_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_025[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1888, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1889, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 no name */
const u16 dudley_exca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_027[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x18DA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18DB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18DC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18DD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x18DE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ADB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR 5 */
const u16 dudley_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_028[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x188B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1889, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR 5 */
const u16 dudley_exca_029_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_029[36] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 2 */
const u16 dudley_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_030[84] = {
    L4(3, 0, 274, 0, 0, 0, 0, 0x183B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x1836, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR 2 */
const u16 dudley_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_031[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of SP WIN 1 */
const u16 dudley_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_032[60] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1831, 0, 139, 0, 0, 0, 21, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of SP WIN 1 */
const u16 dudley_exca_033_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_033[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1832, 0, 140, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of GILL IMPACT C */
const u16 dudley_exca_034_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_034[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18F6, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of GILL IMPACT C */
const u16 dudley_exca_035_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 dudley_exca_035[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x18F6, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x18E5, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E6, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E7, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E8, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x18E9, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EA, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x18EB, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18EC, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x18ED, 0, 69, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1928, 0, 69, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of SP WIN 2 */
const u16 dudley_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_036[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 3, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of SP WIN 2 */
const u16 dudley_exca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_037[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1832, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of SP WIN 3, 40 follow-up of SP WIN 4 */
const u16 dudley_exca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_038[76] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x1888, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1889, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of SP WIN 3, 41 follow-up of SP WIN 4 */
const u16 dudley_exca_039_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_039[36] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of SP WIN 5 */
const u16 dudley_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_042[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1888, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1889, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x188A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1837, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of SP WIN 5 */
const u16 dudley_exca_043_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_043[36] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of JUDGMENT WAIT */
const u16 dudley_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_exca_044[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 1, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of JUDGMENT WAIT */
const u16 dudley_exca_045_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_exca_045[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x1832, 0, 9, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1833, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1834, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 10, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 dudley_exca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 dudley_exca_046[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x19FF, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A00, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A01, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A02, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1A03, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A04, 0, 254, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A05, 0, 254, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 254, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1851, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1852, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1853, 0, 254, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1854, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 88 entries */
const u16* const dudley_saca[89] = {
    dudley_saca_000,  /* 0 UP P GUARD P S */
    dudley_saca_001,  /* 1 UP P GUARD P M */
    dudley_saca_002,  /* 2 UP P GUARD P L */
    dudley_saca_002,  /* 3 UP P GUARD K S */
    dudley_saca_002,  /* 4 UP P GUARD K M */
    dudley_saca_002,  /* 5 UP P GUARD K L */
    dudley_saca_000,  /* 6 D P GUARD P S */
    dudley_saca_001,  /* 7 D P GUARD P M */
    dudley_saca_002,  /* 8 D P GUARD P L */
    dudley_saca_002,  /* 9 D P GUARD K S */
    dudley_saca_002,  /* 10 D P GUARD K M */
    dudley_saca_002,  /* 11 D P GUARD K L */
    dudley_saca_002,  /* 12 FUSHIN P S */
    dudley_saca_002,  /* 13 FUSHIN P M */
    dudley_saca_002,  /* 14 FUSHIN P L */
    dudley_saca_002,  /* 15 FUSHIN K S */
    dudley_saca_002,  /* 16 FUSHIN K M */
    dudley_saca_002,  /* 17 FUSHIN K L */
    dudley_saca_002,  /* 18 OKIAGARI P S */
    dudley_saca_002,  /* 19 OKIAGARI P M */
    dudley_saca_002,  /* 20 OKIAGARI P L */
    dudley_saca_002,  /* 21 OKIAGARI K S */
    dudley_saca_002,  /* 22 OKIAGARI K M */
    dudley_saca_002,  /* 23 OKIAGARI K L */
    dudley_saca_024,  /* 24 ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    dudley_saca_025,  /* 25 ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    dudley_saca_026,  /* 26 ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    dudley_saca_027,  /* 27 ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    dudley_saca_028,  /* 28 ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_028,  /* 29 ATTACK 2 M: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_028,  /* 30 ATTACK 2 L: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_028,  /* 31 ATTACK 2 SP: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_032,  /* 32 ATTACK 3 S: SA II 23623+P (plain script) */
    dudley_saca_032,  /* 33 ATTACK 3 M: SA II 23623+P (plain script) */
    dudley_saca_032,  /* 34 ATTACK 3 L: SA II 23623+P (plain script) */
    dudley_saca_032,  /* 35 ATTACK 3 SP: SA II 23623+P (plain script) */
    dudley_saca_036,  /* 36 ATTACK 4 S: not started by a command */
    dudley_saca_036,  /* 37 ATTACK 4 M: not started by a command */
    dudley_saca_036,  /* 38 ATTACK 4 L: not started by a command */
    dudley_saca_036,  /* 39 ATTACK 4 SP: not started by a command */
    dudley_saca_040,  /* 40 ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU) */
    dudley_saca_041,  /* 41 ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU) */
    dudley_saca_042,  /* 42 ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    dudley_saca_043,  /* 43 ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    dudley_saca_044,  /* 44 ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_045,  /* 45 ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_046,  /* 46 ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_047,  /* 47 ATTACK 6 SP: EX 6(123)4+KK (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_048,  /* 48 ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    dudley_saca_048,  /* 49 ATTACK 7 M: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    dudley_saca_048,  /* 50 ATTACK 7 L: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    dudley_saca_048,  /* 51 ATTACK 7 SP: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    dudley_saca_052,  /* 52 ATTACK 8 S: not started by a command */
    dudley_saca_052,  /* 53 ATTACK 8 M: not started by a command */
    dudley_saca_052,  /* 54 ATTACK 8 L: not started by a command */
    dudley_saca_055,  /* 55 ATTACK 8 SP: not started by a command */
    dudley_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    dudley_saca_057,  /* 57 ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_058,  /* 58 ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_059,  /* 59 ATTACK 9 SP: 4(123)6+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_059,  /* 60 ATTACK 10 S: 4(123)6+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    dudley_saca_061,  /* 61 ATTACK 10 M: not started by a command */
    dudley_saca_061,  /* 62 ATTACK 10 L: not started by a command */
    dudley_saca_063,  /* 63 ATTACK 10 SP: not started by a command */
    dudley_saca_063,  /* 64 ATTACK 11 S: not started by a command */
    dudley_saca_065,  /* 65 ATTACK 11 M: 6(123)4+P light (plain script) */
    dudley_saca_066,  /* 66 ATTACK 11 L: 6(123)4+P medium (plain script) */
    dudley_saca_067,  /* 67 ATTACK 11 SP: 6(123)4+P heavy (plain script) */
    dudley_saca_068,  /* 68 ATTACK 12 S: EX 6(123)4+PP (plain script) */
    dudley_saca_069,  /* 69 ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    dudley_saca_070,  /* 70 ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
    dudley_saca_071,  /* 71 ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
    dudley_saca_072,  /* 72 ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    dudley_saca_073,  /* 73 ATTACK 13 M: not started by a command */
    dudley_saca_074,  /* 74 ATTACK 13 L: not started by a command */
    dudley_saca_075,  /* 75 ATTACK 13 SP: 6(123)456+P light (plain script) */
    dudley_saca_076,  /* 76 6(123)456+P medium (plain script) */
    dudley_saca_077,  /* 77 6(123)456+P heavy (plain script) */
    dudley_saca_078,  /* 78 EX 6(123)456+PP (plain script) */
    dudley_saca_079,  /* 79 not started by a command */
    dudley_saca_079,  /* 80 not started by a command */
    dudley_saca_079,  /* 81 not started by a command */
    dudley_saca_079,  /* 82 not started by a command */
    dudley_saca_083,  /* 83 not started by a command */
    dudley_saca_083,  /* 84 not started by a command */
    dudley_saca_083,  /* 85 not started by a command */
    dudley_saca_086,  /* 86 not started by a command */
    dudley_saca_087,  /* 87 not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 dudley_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x709C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A0, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A1, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A2, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A3, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70A6, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -2304, 7168), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 dudley_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 dudley_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70A6, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70A5, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70A5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A3, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A2, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70A0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709F, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709C, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 dudley_saca_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_saca_002[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1800, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_024_head[4] = { HEAD(6, 0, 8, 8, 0, 1, 1) };
const u16 dudley_saca_024[412] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 908, 0, 0, 0, 0, 0x1A35, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A38, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x1A39, -30, 68, 0, 135, 64, 0, 0, 0, 0, 0, 8, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A3A, 30, 78, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 31, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 31, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 31, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 31, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_SCHX, 0, 7, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHY, 0, 3, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 31, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 31, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_025_head[4] = { HEAD(6, 0, 10, 9, 0, 1, 1) };
const u16 dudley_saca_025[412] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 908, 0, 0, 0, 0, 0x1A35, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 49, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 49, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A38, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x1A39, -32, 80, 0, 135, 64, 0, 0, 0, 0, 0, 8, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A3A, 0, 81, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 33, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 33, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 33, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 33, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_SCHX, 0, 7, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHY, 0, 1, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 33, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 33, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_026_head[4] = { HEAD(6, 0, 12, 10, 0, 2, 1) };
const u16 dudley_saca_026[580] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 908, 0, 0, 0, 0, 0x1A35, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 67, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 67, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A38, -37, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1A39, -34, 83, 0, 135, 64, 0, 0, 0, 0, 0, 8, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A3A, 0, 83, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 35, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 35, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 35, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A43, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 35, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_SCHX, 0, 5, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHY, 0, 5, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 35, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 35, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A43, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_027_head[4] = { HEAD(6, 0, 14, 10, 0, 2, 1) };
const u16 dudley_saca_027[592] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 908, 0, 0, 0, 0, 0x1A35, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 70, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 70, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A38, -65, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1A39, -66, 76, 0, 128, 64, 0, 0, 0, 0, 0, 9, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A3A, 0, 76, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 67, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 67, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 67, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A43, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, 67, 79, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    CMD(CM_SCHX, 0, 3, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHY, 0, 5, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3C, 67, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A3B, 67, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A43, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI), 29 ATTACK 2 M: SA III 23623+P (routine Att_CHOUCHUURENGEKI), 30 ATTACK 2 L: SA III 23623+P (routine Att_CHOUCHUURENGEKI), 31 ATTACK 2 SP: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_028_head[4] = { HEAD(6, 0, 32, 15, 0, 5, 13) };
const u16 dudley_saca_028[340] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A44, 0, 122, 0, 0, 0, 13, 2, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A45, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A46, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A47, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x1A48, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 29, 0, 0x1A49, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 29, 0, 0x1A4A, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(34, 0, 905, 0, 0, 0, 0, 0x1A4B, 0, 122, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A4C, 0, 122, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A4D, 0, 122, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A4E, 0, 122, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1A4F, 0, 122, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 20, 269, 0, 0, 39, 0, 0x1A50, -38, 97, 0, 0, 0, 1, 27, 776, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 39, 0, 0x1A50, -39, 98, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 39, 0, 0x1A51, -40, 99, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 39, 0, 0x1A51, -41, 100, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 39, 0, 0x1A52, -42, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 39, 0, 0x1A52, 0, 102, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 21, 0, 0, 0, 39, 0, 0x1A52, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 39, 0, 0x1A53, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 39, 0, 0x1A54, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 39, 0, 0x196E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 39, 0, 0x196F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 39, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 39, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: SA II 23623+P (plain script), 33 ATTACK 3 M: SA II 23623+P (plain script), 34 ATTACK 3 L: SA II 23623+P (plain script), 35 ATTACK 3 SP: SA II 23623+P (plain script) */
const u16 dudley_saca_032_head[4] = { HEAD(6, 0, 32, 13, 0, 8, 12) };
const u16 dudley_saca_032[784] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 13, 7, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_STOP, -50, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(47, 0, 912, 0, 0, 0, 0, 0x1831, 0, 122, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 1, 20, 0, 0, 82, 11, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187C, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187C, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1A58, 0, 103, 0, 0, 0, 1, 21, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A59, -52, 105, 0, 84, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A5A, 52, 105, 0, 85, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A5E, 0, 104, 0, 0, 0, 21, 0, 0, 0, 90, 0, 0),
    CMD(CM_IFLB, 116, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A5F, 0, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A5A, 0, 105, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 904, 0, 0, 0, 0, 0x1A5E, 0, 104, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x1A5F, 0, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A60, -53, 106, 0, 64, 0, 1, 22, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A61, 0, 107, 0, 64, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A62, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A63, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A64, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A65, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A66, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A67, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 904, 0, 0, 0, 0, 0x1A68, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x1A69, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A6A, -54, 112, 0, 64, 0, 1, 23, 0, 0, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A6B, 0, 113, 0, 64, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A6C, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A6D, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A6E, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A5C, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A5D, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT2, 16384, 16385, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 32, 44), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 32, 45), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 908, 0, 0, 0, 0, 0x19AB, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -71, 40, 0, 176, 0, 1, 22, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, 72, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 22, 32, 0, 0, 44, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 912, 0, 0, 0, 0, 0x1A8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: not started by a command, 37 ATTACK 4 M: not started by a command, 38 ATTACK 4 L: not started by a command, 39 ATTACK 4 SP: not started by a command */
const u16 dudley_saca_036_head[4] = { HEAD(6, 0, 32, 16, 0, 77, 0) };
const u16 dudley_saca_036[236] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 25, 65),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0100, 0x0000, 0x0000, 0x1942, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1943, 0, 1, 0, 0, 0, 0, 0, 512, 0, 0, 25, 70),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0100, 0x0000, 0x0000, 0x1947, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1948, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 25, 73),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0100, 0x0000, 0x0000, 0x194A, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(3, 0, 0, 0, 0, 0, 0, 0x194F, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 25, 80),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0300, 0x0000, 0x0000, 0x1951, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1952, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 25, 83),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0100, 0x0000, 0x0000, 0x1954, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 25, 86),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0100, 0x0000, 0x0000, 0x1955, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1956, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 25, 87),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0200, 0x0000, 0x0000, 0x1958, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 0, 0, 512, 0, 0, 25, 90),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0200, 0x0000, 0x0000, 0x195B, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(2, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 25, 77),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x194E, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(250, 255, 0, 0, 0, 0, 0, 0x183F, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 40 ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_040_head[4] = { HEAD(6, 0, 8, 13, 0, 3, 2) };
const u16 dudley_saca_040[292] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7C, 0, 87, 0, 0, 0, 30, 107, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7D, 0, 87, 0, 0, 0, 30, 108, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7E, 0, 87, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A7F, 0, 87, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A80, 0, 87, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A81, -43, 88, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A82, -44, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A85, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 902, 0, 0, 0, 0, 0x1A88, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A89, -48, 92, 0, 142, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8A, 49, 93, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 49, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_041_head[4] = { HEAD(6, 0, 10, 14, 0, 4, 2) };
const u16 dudley_saca_041[400] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 902, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 105, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 0, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 106, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A7B, 0, 87, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7C, 0, 87, 0, 0, 0, 30, 107, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7D, 0, 87, 0, 0, 0, 30, 108, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7E, 0, 87, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7F, 0, 87, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 900, 0, 0, 0, 0, 0x1A80, 0, 87, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A81, -43, 88, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A82, -44, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A83, -45, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A85, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 902, 0, 0, 0, 0, 0x1A88, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A89, -48, 92, 0, 149, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8A, 49, 93, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 49, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(14, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_042_head[4] = { HEAD(6, 0, 12, 14, 0, 6, 2) };
const u16 dudley_saca_042[412] = {
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 902, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 105, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 0, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 106, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A7B, 0, 87, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A7C, 0, 87, 0, 0, 0, 30, 107, 0, 0, 130, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7D, 0, 87, 0, 0, 0, 30, 108, 0, 0, 132, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7E, 0, 87, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7F, 0, 87, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 900, 0, 0, 0, 0, 0x1A80, 0, 87, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A81, -43, 88, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A82, -44, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A83, -45, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A84, -46, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A85, -47, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 902, 0, 0, 0, 0, 0x1A88, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A89, -48, 92, 0, 150, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8A, 49, 93, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 49, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(20, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1995, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
const u16 dudley_saca_043_head[4] = { HEAD(6, 0, 14, 14, 0, 7, 2) };
const u16 dudley_saca_043[592] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 47, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 902, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 105, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 20, 0, 0, 0, 0, 0, 0x1A7A, 0, 86, 0, 0, 0, 30, 106, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A7B, 0, 87, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7C, 0, 87, 0, 0, 0, 30, 107, 0, 0, 130, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7D, 0, 87, 0, 0, 0, 30, 108, 0, 0, 132, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7E, 0, 87, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7F, 0, 87, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(1, 0, 900, 0, 0, 0, 0, 0x1A80, 0, 87, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A81, -100, 88, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A82, -101, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A83, -102, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 900, 0, 0, 0, 0, 0x1A84, -103, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A85, -104, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 902, 0, 0, 0, 0, 0x1A88, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A89, -105, 92, 0, 151, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8A, 106, 93, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 106, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1994, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A7D, 0, 39, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 902, 0, 0, 0, 0, 0x19A8, 0, 39, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A9, 0, 39, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x19AA, 0, 39, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AB, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -107, 40, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, 108, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 108, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19B0, 108, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(20, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 42, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_044_head[4] = { HEAD(4, 0, 9, 12, 0, 1, 117) };
const u16 dudley_saca_044[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 900, 0, 0, 0, 0, 0x1BD4, 0, 165, 0, 0, 0, 32, 92),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BCF, 0, 165, 0, 0, 0, 32, 86),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BD0, 0, 165, 0, 0, 0, 32, 87),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BD1, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x1BD2, 0, 167, 0, 0, 0, 30, 19),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 30, 20),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1972, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1973, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x1974, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1975, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x1976, -112, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1976, 0, 28, 0, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1978, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1979, 0, 26, 0, 0, 0, 32, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 26, 0, 0, 0, 32, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 32, 8),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_045_head[4] = { HEAD(4, 0, 11, 12, 0, 1, 117) };
const u16 dudley_saca_045[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 900, 0, 0, 0, 0, 0x1BCE, 0, 165, 0, 0, 0, 32, 85),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BCF, 0, 165, 0, 0, 0, 32, 86),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1BD0, 0, 165, 0, 0, 0, 32, 87),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BD1, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x1BD2, 0, 167, 0, 0, 0, 30, 19),
    L4(2, 0, 0, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 30, 20),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1972, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1973, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x1974, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1975, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x1976, -112, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1976, 0, 28, 0, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1978, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1979, 0, 26, 0, 0, 0, 32, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 26, 0, 0, 0, 32, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 32, 8),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_046_head[4] = { HEAD(4, 0, 13, 12, 0, 1, 117) };
const u16 dudley_saca_046[196] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 900, 0, 0, 0, 0, 0x1BCE, 0, 165, 0, 0, 0, 32, 103),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BCF, 0, 165, 0, 0, 0, 32, 86),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1BD0, 0, 165, 0, 0, 0, 32, 87),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1BD1, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1BD2, 0, 167, 0, 0, 0, 30, 19),
    L4(2, 0, 0, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 30, 20),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1972, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1973, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x1974, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1975, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x1976, -112, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 27, 0, 0, 72, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1976, 0, 28, 0, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1977, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1978, 0, 28, 0, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1979, 0, 26, 0, 0, 0, 32, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 26, 0, 0, 0, 32, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 32, 8),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: EX 6(123)4+KK (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_047_head[4] = { HEAD(4, 0, 15, 15, 0, 3, 117) };
const u16 dudley_saca_047[372] = {
    CMD(CM_JSR, 8, 52, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1831, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 902, 0, 0, 0, 0, 0x1BCE, 0, 165, 0, 0, 0, 32, 85),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BCF, 0, 165, 0, 0, 0, 32, 86),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BD0, 0, 165, 0, 0, 0, 32, 87),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1BD1, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x1BD2, 0, 167, 0, 0, 0, 30, 19),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 30, 20),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1972, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1973, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x1974, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1975, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1976, -115, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1977, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1976, 0, 28, 0, 0, 0, 0, 0),
    L4(1, 21, 0, 0, 0, 0, 0, 0x1977, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1978, 0, 28, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1979, 0, 26, 0, 0, 0, 32, 6),
    L4(2, 0, 270, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 32, 20),
    L4(1, 0, 901, 0, 0, 0, 0, 0x19AD, -116, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19AE, 0, 41, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 41, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 41, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 32, 21),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197A, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 903, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1980, -117, 33, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 0, 64, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 33, 0, 0, 64, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA), 49 ATTACK 7 M: SA I 23623+P (routine Att_SHOURYUUREPPA), 50 ATTACK 7 L: SA I 23623+P (routine Att_SHOURYUUREPPA), 51 ATTACK 7 SP: SA I 23623+P (routine Att_SHOURYUUREPPA) */
const u16 dudley_saca_048_head[4] = { HEAD(6, 0, 32, 11, 0, 12, 11) };
const u16 dudley_saca_048[856] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_STOP, -50, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A35, 0, 69, 0, 0, 0, 13, 8, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 69, 0, 0, 0, 0, 0, 779, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 69, 0, 0, 0, 0, 0, 779, 0, 64, 0, 0),
    L6(44, 0, 909, 0, 0, 0, 0, 0x1A38, 0, 69, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A39, -50, 126, 0, 136, 0, 0, 0, 0, 0, 0, 9, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3A, 50, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, -51, 125, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3C, 51, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3D, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 910, 0, 0, 0, 0, 0x1A36, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A38, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A39, -59, 118, 0, 149, 0, 0, 0, 0, 0, 0, 22, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3A, 59, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1A3B, -60, 117, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3C, 60, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3D, 60, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 3, 8198), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 8, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1A8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 912, 0, 0, 0, 0, 0x1A8C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1A8D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0),
    CMD(CM_RJA, 8, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A35, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A36, 0, 9, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1A37, 0, 9, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A38, 0, 9, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A39, -61, 116, 0, 171, 0, 0, 0, 0, 0, 0, 44, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A3A, 61, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 40, 0, 0x1A3B, -62, 119, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(1, 0, 268, 0, 0, 40, 0, 0x1A3C, 62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3D, -62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3E, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3F, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A40, -62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 40, 0, 0x1A42, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A43, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3C, -62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3E, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3F, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A40, -62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 40, 0, 0x1A42, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A43, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3C, -62, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3E, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x1A3F, 92, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 40, 0, 0x1A40, -36, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A42, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A43, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3C, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3E, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A3F, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1A40, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x1A41, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: not started by a command, 53 ATTACK 8 M: not started by a command, 54 ATTACK 8 L: not started by a command */
const u16 dudley_saca_052_head[4] = { HEAD(4, 0, 11, 5, 0, 3, 75) };
const u16 dudley_saca_052[292] = {
    CMD(CM_RJA, 5, 86, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1882, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 20, 900, 0, 0, 0, 0, 0x1849, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184A, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184B, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184C, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184D, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184E, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A05, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A04, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A03, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A02, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A01, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A00, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19FF, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x1A05, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 2, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A71, -99, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A72, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 2, 16393), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A73, -94, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A74, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 2, 16392), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A6F, -94, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A70, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A71, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A72, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A73, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A74, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A6F, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1A70, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: not started by a command */
const u16 dudley_saca_055_head[4] = { HEAD(4, 0, 15, 11, 0, 4, 0) };
const u16 dudley_saca_055[292] = {
    CMD(CM_RJA, 5, 87, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1882, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1855, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 30, 900, 0, 0, 0, 0, 0x1849, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184A, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184B, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184C, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184D, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x184E, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A05, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A04, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A03, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A02, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A01, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A00, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x19FF, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A06, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x1A05, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 16393), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A71, -96, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1A72, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A73, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16392, 3, 16392), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A74, -96, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1A6F, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A70, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A71, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1A72, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A73, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A74, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1A6F, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A70, 0, 144, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command */
const u16 dudley_saca_056_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_saca_056[20] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 255, 0, 0, 0, 0, 0, 0x1801, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_057_head[4] = { HEAD(6, 0, 9, 0, 0, 0, 2) };
const u16 dudley_saca_057[268] = {
    CMD(CM_RJA, 5, 57, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 900, 0, 0, 0, 0, 0x1831, 0, 103, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 22, 32, 0, 0, 120, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x187D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_058_head[4] = { HEAD(6, 0, 11, 0, 0, 0, 2) };
const u16 dudley_saca_058[268] = {
    CMD(CM_RJA, 5, 58, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 900, 0, 0, 0, 0, 0x1831, 0, 103, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 22, 32, 0, 0, 120, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: 4(123)6+K heavy/EX (routine Att_CHOUCHUURENGEKI), 60 ATTACK 10 S: 4(123)6+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
const u16 dudley_saca_059_head[4] = { HEAD(6, 0, 13, 0, 0, 0, 2) };
const u16 dudley_saca_059[268] = {
    CMD(CM_RJA, 5, 59, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 900, 0, 0, 0, 0, 0x1831, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 22, 32, 0, 0, 120, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1855, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x187D, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(3, 0, 0, 0, 0, 0, 0, 0x187E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command */
const u16 dudley_saca_061_head[4] = { HEAD(6, 0, 8, 15, 0, 21, 0) };
const u16 dudley_saca_061[720] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1941, -65, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1942, 65, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1943, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1946, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1948, -66, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1949, 66, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x194F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 1, 17, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1954, -67, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1955, 67, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1956, 67, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1955, 67, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1956, 67, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1959, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x195A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x195B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000A, 0x0000, 0x0000, 0x0200, 0x38D0, 0x0000, 0x199E,
    CMD(CM_ROA, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x10D0, 0x0000, 0x199F,
    CMD(CM_JPSS, -32768, 0, 0), 0x0000, 0x0000, 0x0022, 0x0000, 0x0100, 0x0000, 0x0000, 0x19A0,
    L6(239, 4, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 161),
    CMD(CM_JPSS, -16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x38E0, 0x0000, 0x19A2,
    CMD(CM_JPSS, -16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x10E0, 0x0000, 0x19AB,
    CMD(CM_JPSS, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x19AC,
    CMD(CM_JPSS, -8192, 0, 0), 0x0000, 0x0000, 0x0028, 0x0000, 0x0100, 0x0000, 0x0000, 0x19AD,
    L6(238, 197, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 174),
    L6(17, 69, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 175),
    L6(17, 69, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 176),
    L6(17, 69, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 175),
    CMD(CM_JSR, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0600, 0x0000, 0x0000, 0x19B0,
    CMD(CM_JSR, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x19B1,
    CMD(CM_JSR, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x38F0, 0x0000, 0x197C,
    CMD(CM_JMP, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x10E0, 0x0000, 0x197D,
    CMD(CM_JMP, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x197E,
    CMD(CM_JMP, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x197F,
    CMD(CM_JMP, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x1980,
    L6(238, 132, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 129),
    L6(17, 132, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 25, 128),
    L6(17, 132, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 25, 129),
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1982,
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1983,
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x0014, 0x0000, 0x0300, 0x0000, 0x0000, 0x1984,
    CMD(CM_JPSS, 16384, 0, 0), 0x0000, 0x0000, 0x0016, 0x0000, 0x0100, 0x0000, 0x0000, 0x1985,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x1986,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0018, 0x0000, 0x0100, 0x0000, 0x0000, 0x1987,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1970,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1859,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1859,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 63 ATTACK 10 SP: not started by a command, 64 ATTACK 11 S: not started by a command */
const u16 dudley_saca_063_head[4] = { HEAD(6, 0, 12, 14, 0, 31, 0) };
const u16 dudley_saca_063[484] = {
    L6(2, 0, 909, 0, 0, 0, 0, 0x1950, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1951, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1952, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1953, 0, 19, 0, 0, 0, 1, 17, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1954, -55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 55, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1956, 55, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1955, 55, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1956, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1957, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1958, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 910, 0, 0, 0, 0, 0x198B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x198C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x198D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x198F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1990, 0, 26, 0, 0, 0, 1, 18, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1991, -56, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1992, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 911, 0, 0, 0, 0, 0x1993, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1950, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x19AA, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AB, 0, 39, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AC, 0, 39, 0, 0, 0, 1, 19, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -57, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, 57, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 57, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19B0, 57, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1958, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1959, 0, 43, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x195A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x195B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 ATTACK 11 M: 6(123)4+P light (plain script) */
const u16 dudley_saca_065_head[4] = { HEAD(4, 0, 8, 0, 0, 0, 0) };
const u16 dudley_saca_065[212] = {
    CMD(CM_RMJA, 5, 69, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 4, 24, 1), 0, 0, 0, 0,
    CMD(CM_ATMF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x1B4A, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4E, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ATMF, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1B4B, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B51, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1B52, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B53, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A78, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: 6(123)4+P medium (plain script) */
const u16 dudley_saca_066_head[4] = { HEAD(4, 0, 10, 0, 0, 0, 0) };
const u16 dudley_saca_066[116] = {
    CMD(CM_RMJA, 5, 70, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 4, 24, 1), 0, 0, 0, 0,
    CMD(CM_ATMF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x1B4A, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4E, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 65, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: 6(123)4+P heavy (plain script) */
const u16 dudley_saca_067_head[4] = { HEAD(4, 0, 12, 0, 0, 0, 0) };
const u16 dudley_saca_067[92] = {
    CMD(CM_RMJA, 5, 71, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 4, 24, 1), 0, 0, 0, 0,
    CMD(CM_ATMF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x1B4A, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 65, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: EX 6(123)4+PP (plain script) */
const u16 dudley_saca_068_head[4] = { HEAD(4, 1, 14, 0, 0, 0, 0) };
const u16 dudley_saca_068[156] = {
    CMD(CM_RMJA, 5, 72, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_RMJA, 5, 72, 1), 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 22, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 4, 24, 1), 0, 0, 0, 0,
    CMD(CM_ATMF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x1B4A, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 65, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
const u16 dudley_saca_069_head[4] = { HEAD(4, 0, 8, 0, 0, 0, 0) };
const u16 dudley_saca_069[252] = {
    CMD(CM_MXYT, 66, 0, 0), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 1, 0, 30, 0, 0x1A8E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x1A8F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 148, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x1A90, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 150, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x1A91, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 906, 2, 0, 0, 0, 0x1A92, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 152, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 2, 0, 0, 0, 0x1A93, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A94, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 79, 0), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, 4096, 0), 0, 0, 0, 0,
    L4(1, 30, 0, 2, 0, 0, 0, 0x1A96, -76, 12, 0, 145, 0, 44, 1),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A97, 0, 12, 0, 128, 0, 0, 0),
    CMD(CM_EXEC, 30, 45, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 2, 0, 0, 0, 0x1A98, 0, 3, 0, 0, 0, 30, 44),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A99, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9A, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9B, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9C, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9D, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 21, 0, 0, 0, 0, 0, 0x1A9E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
const u16 dudley_saca_070_head[4] = { HEAD(4, 0, 10, 0, 0, 0, 0) };
const u16 dudley_saca_070[140] = {
    CMD(CM_MXYT, 67, 0, 0), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 1, 0, 30, 0, 0x1A8E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x1A8F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 148, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x1A90, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 150, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x1A91, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 906, 2, 0, 0, 0, 0x1A92, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 152, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 2, 0, 0, 0, 0x1A93, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A94, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 79, 0), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(1, 30, 0, 2, 0, 0, 0, 0x1A96, -77, 12, 0, 145, 0, 44, 1),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A97, 0, 12, 0, 128, 0, 0, 0),
    CMD(CM_JPSS, 5, 69, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
const u16 dudley_saca_071_head[4] = { HEAD(4, 0, 12, 0, 0, 0, 0) };
const u16 dudley_saca_071[140] = {
    CMD(CM_MXYT, 68, 0, 0), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 1, 0, 30, 0, 0x1A8E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x1A8F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 148, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x1A90, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 150, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x1A91, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 906, 2, 0, 0, 0, 0x1A92, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 152, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 2, 0, 0, 0, 0x1A93, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A94, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 79, 0), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, 16384, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 2, 0, 26, 0, 0x1A96, -78, 145, 0, 145, 0, 44, 1),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A97, 0, 12, 0, 128, 0, 0, 0),
    CMD(CM_JPSS, 5, 69, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
const u16 dudley_saca_072_head[4] = { HEAD(4, 0, 14, 0, 0, 0, 0) };
const u16 dudley_saca_072[404] = {
    CMD(CM_MXYT, 69, 0, 0), 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 1, 0, 30, 0, 0x1A8E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 1, 0, 0, 0, 0x1A8F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 148, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 1, 0, 0, 0, 0x1A90, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 150, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 1, 0, 0, 0, 0x1A91, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 906, 2, 0, 0, 0, 0x1A92, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 152, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 2, 0, 0, 0, 0x1A93, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A94, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 79, 0), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, 24576, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 2, 0, 26, 0, 0x1A96, -97, 145, 0, 145, 0, 44, 2),
    L4(3, 0, 0, 2, 0, 0, 0, 0x1A97, 0, 12, 0, 128, 0, 0, 0),
    CMD(CM_EXEC, 30, 45, 0), 0, 0, 0, 0,
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 72, 37), 0, 0, 0, 0,
    L4(4, 0, 0, 2, 0, 0, 0, 0x1A98, 0, 3, 0, 0, 0, 30, 44),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A99, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9A, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B5B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B5C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B5D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B5E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B5F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B60, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B61, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RV_X, 0, 20480, 0), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 111, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 79, 0, 0), 0, 0, 0, 0,
    L4(2, 30, 0, 2, 0, 26, 0, 0x1A96, -98, 145, 0, 164, 0, 44, 1),
    L4(3, 0, 0, 2, 0, 0, 0, 0x1A97, 0, 12, 0, 128, 0, 0, 0),
    CMD(CM_EXEC, 30, 45, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 2, 0, 0, 0, 0x1A98, 0, 3, 0, 0, 0, 30, 44),
    L4(2, 0, 0, 2, 0, 0, 0, 0x1A99, 0, 13, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9A, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9B, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9C, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A9D, 0, 14, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 21, 0, 0, 0, 0, 0, 0x1A9E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: not started by a command */
const u16 dudley_saca_073_head[4] = { HEAD(6, 0, 12, 14, 0, 1, 0) };
const u16 dudley_saca_073[256] = {
    L6(1, 0, 902, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1980, -58, 128, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1981, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x1980, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(9, 0, 0, 0, 0, 0, 0, 0x1981, 0, 129, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1982, 0, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1983, 0, 129, 0, 0, 0, 0, 0, 0, 0, 20, 18, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1981, 0, 129, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1982, 0, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1983, 0, 129, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 129, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: not started by a command */
const u16 dudley_saca_074_head[4] = { HEAD(6, 32, 12, 10, 0, 2, 0) };
const u16 dudley_saca_074[256] = {
    L6(1, 21, 0, 0, 0, 0, 0, 0x19AA, 0, 103, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(1, 0, 908, 0, 0, 0, 0, 0x19AB, 0, 103, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x19AC, 0, 103, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AD, -63, 130, 0, 0, 64, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19AE, -64, 131, 0, 0, 64, 0, 0, 0, 0, 40, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 132, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x19AF, 0, 132, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x19B0, 0, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x19B1, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x19B2, 0, 43, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x19B3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x19A7, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x199D, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186B, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x186A, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 ATTACK 13 SP: 6(123)456+P light (plain script) */
const u16 dudley_saca_075_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 0) };
const u16 dudley_saca_075[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1940, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1941, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1942, -1, 15, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1943, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1944, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1945, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1945, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 5, 69, 1), 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1943, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 65, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 6(123)456+P medium (plain script) */
const u16 dudley_saca_076_head[4] = { HEAD(4, 0, 2, 14, 0, 1, 0) };
const u16 dudley_saca_076[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1946, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1947, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1948, 0, 25, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1949, -4, 16, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194A, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x194B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x194C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x194A, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 66, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 6(123)456+P heavy (plain script) */
const u16 dudley_saca_077_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 dudley_saca_077[280] = {
    L6(2, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, -11, 33, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RMJA, 5, 71, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, -79, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    CMD(CM_JMP, 5, 67, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 EX 6(123)456+PP (plain script) */
const u16 dudley_saca_078_head[4] = { HEAD(6, 0, 4, 15, 0, 1, 0) };
const u16 dudley_saca_078[232] = {
    L6(2, 0, 901, 0, 0, 0, 0, 0x197B, 0, 26, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197C, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x197D, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x197E, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x197F, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1980, -11, 33, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1981, 0, 33, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1981, 0, 34, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1982, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1984, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1985, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1986, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1987, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1970, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1859, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 68, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 not started by a command, 80 not started by a command, 81 not started by a command, 82 not started by a command */
const u16 dudley_saca_079_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 33) };
const u16 dudley_saca_079[92] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x187D, 0, 177, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x19EB, 0, 11, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x19EC, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x19ED, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x19EE, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x19EF, -91, 55, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x19F0, 0, 55, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x19F1, 0, 55, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 not started by a command, 84 not started by a command, 85 not started by a command */
const u16 dudley_saca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 dudley_saca_083[260] = {
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1815, 0, 1, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AE0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1AE1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 31, 0, 0x1AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 32, 0, 0x1AE3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 33, 0, 0x1AE3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 45, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCEQ, 16384, 1, 16394), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 35, 0, 0x1AE4, 0, 1, 0, 0, 0, 0, 0),
    L4(18, 20, 0, 0, 0, 36, 0, 0x1AE5, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 37, 0, 0x1AE5, 0, 1, 0, 0, 0, 1, 112),
    L4(4, 0, 0, 0, 0, 38, 0, 0x1B54, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 113, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AE3, 0, 1, 0, 0, 0, 1, 114),
    L4(5, 40, 0, 0, 0, 0, 0, 0x1AE4, 0, 1, 0, 0, 0, 0, 0),
    L4(14, 20, 0, 0, 0, 0, 0, 0x1AE5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B54, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B55, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1B56, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFRLF, 1, 16390, 8192), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B57, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1B58, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B59, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1B5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1B5A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x194D, 0, 1, 0, 0, 0, 24, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x194E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 not started by a command */
const u16 dudley_saca_086_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_saca_086[220] = {
    CMD(CM_EXEC, 1, 76, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 77, 0), 0, 0, 0, 0,
    L4(1, 0, 285, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 39, 4),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 21, 0),
    CMD(CM_WCNE, 16399, 0, 16390), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 86, 14), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16391, 8192), 0, 0, 0, 0,
    L4(6, 2, 0, 0, 0, 0, 0, 0x1A77, 0, 1, 0, 0, 0, 22, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1A78, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1838, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1839, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x183A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 2, 0, 0, 0, 0, 0, 0x1833, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1834, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1835, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1835, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1835, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 not started by a command */
const u16 dudley_saca_087_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 dudley_saca_087[292] = {
    CMD(CM_EXEC, 1, 76, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 77, 0), 0, 0, 0, 0,
    L4(1, 0, 285, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 39, 10),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 21, 0),
    CMD(CM_WCNE, 16399, 0, 16391), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 86, 15), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1A75, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1A76, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 86, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x010E, 0x0000, 0x0000,
    CMD(CM_RMJA, 5, 72, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1831, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_RMJA, 5, 72, 1), 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1983, 0, 34, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 22, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1984, -79, 1, 0, 0, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2), 0, 0, 0, 0,
    CMD(CM_ATMF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x1B4A, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 20, 0, 0, 0, 0, 0, 0x1B4F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x1B50, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 20, 0, 0, 0, 0, 0, 0x1B4B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1B4D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 65, 17), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 53 entries */
const u16* const dudley_cbca[54] = {
    dudley_cbca_000,  /* 0 APPEAR JUNBI 1 */
    dudley_cbca_001,  /* 1 APPEAR JUNBI 2 */
    dudley_cbca_002,  /* 2 APPEAR JUNBI 3 */
    dudley_cbca_003,  /* 3 APPEAR JUNBI 4 */
    dudley_cbca_004,  /* 4 APPEAR JUNBI 5 */
    dudley_cbca_005,  /* 5 APPEAR JUNBI 6 */
    dudley_cbca_006,  /* 6 APPEAR JUNBI 7 */
    dudley_cbca_007,  /* 7 APPEAR JUNBI 8 */
    dudley_cbca_008,  /* 8 APPEAR 1 */
    dudley_cbca_009,  /* 9 APPEAR 2 */
    dudley_cbca_010,  /* 10 APPEAR 3 */
    dudley_cbca_011,  /* 11 APPEAR 4 */
    dudley_cbca_012,  /* 12 APPEAR 5 */
    dudley_cbca_013,  /* 13 APPEAR 6 */
    dudley_cbca_014,  /* 14 APPEAR 7 */
    dudley_cbca_015,  /* 15 APPEAR 8 */
    dudley_cbca_016,  /* 16 SP APPEAR 1 */
    dudley_cbca_017,  /* 17 SP APPEAR 2 */
    dudley_cbca_018,  /* 18 SP APPEAR 3 */
    dudley_cbca_019,  /* 19 SP APPEAR 4 */
    dudley_cbca_020,  /* 20 SP APPEAR 5 */
    dudley_cbca_021,  /* 21 SP APPEAR 6 */
    dudley_cbca_022,  /* 22 SP APPEAR 7 */
    dudley_cbca_023,  /* 23 SP APPEAR 8 */
    dudley_cbca_024,  /* 24 ZANNEN 1 */
    dudley_cbca_025,  /* 25 ZANNEN 2 */
    dudley_cbca_026,  /* 26 ZANNEN 3 */
    dudley_cbca_027,  /* 27 ZANNEN 4 */
    dudley_cbca_028,  /* 28 ZANNEN 5 */
    dudley_cbca_029,  /* 29 ZANNEN 6 */
    dudley_cbca_030,  /* 30 ZANNEN 7 */
    dudley_cbca_031,  /* 31 ZANNEN 8 */
    dudley_cbca_032,  /* 32 WIN 1 */
    dudley_cbca_033,  /* 33 WIN 2 */
    dudley_cbca_034,  /* 34 WIN 3 */
    dudley_cbca_035,  /* 35 WIN 4 */
    dudley_cbca_036,  /* 36 WIN 5 */
    dudley_cbca_037,  /* 37 WIN 6 */
    dudley_cbca_038,  /* 38 WIN 7 */
    dudley_cbca_039,  /* 39 WIN 8 */
    dudley_cbca_040,  /* 40 SP WIN 1 */
    dudley_cbca_041,  /* 41 SP WIN 2 */
    dudley_cbca_042,  /* 42 SP WIN 3 */
    dudley_cbca_043,  /* 43 SP WIN 4 */
    dudley_cbca_044,  /* 44 SP WIN 5 */
    dudley_cbca_045,  /* 45 SP WIN 6 */
    dudley_cbca_046,  /* 46 SP WIN 7 */
    dudley_cbca_047,  /* 47 SP WIN 8 */
    dudley_cbca_048,  /* 48 JUDGMENT WAIT */
    dudley_cbca_049,  /* 49 JUDGMENT WAIT */
    dudley_cbca_050,  /* 50 JUDGMENT WAIT */
    dudley_cbca_051,  /* 51 JUDGMENT WAIT */
    dudley_cbca_052,  /* 52 JUDGMENT WIN */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 dudley_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 dudley_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 dudley_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 dudley_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 dudley_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 dudley_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_005[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 dudley_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_006[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RJA4, 5, 24, 21),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 dudley_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_007[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RJA4, 5, 25, 21),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 dudley_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_008[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RJA4, 5, 26, 29),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 dudley_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_009[24] = {
    CMD(CM_RJA, 5, 48, 29),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RJA4, 5, 48, 31),
    CMD(CM_RJA5, 5, 48, 37),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 dudley_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_010[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 dudley_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_011[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 dudley_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_012[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 28, 1),
    CMD(CM_RJA3, 7, 29, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 dudley_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_013[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 3, 1),
    CMD(CM_CARE, 2, 3, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 dudley_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_014[16] = {
    CMD(CM_RJA, 0, 0, 1),
    CMD(CM_RJA2, 0, 0, 43),
    CMD(CM_PJMP, 24, 8194, 8192),
    CMD(CM_PJMP, 12, 8195, 8193),
};

/* script: 15 APPEAR 8 */
const u16 dudley_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_015[16] = {
    CMD(CM_RJA, 0, 0, 1),
    CMD(CM_RJA2, 0, 0, 12),
    CMD(CM_PJMP, 24, 8194, 8192),
    CMD(CM_PJMP, 20, 8195, 8193),
};

/* script: 16 SP APPEAR 1 */
const u16 dudley_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_016[16] = {
    CMD(CM_RJA, 0, 0, 12),
    CMD(CM_RJA2, 0, 0, 43),
    CMD(CM_PJMP, 8, 8194, 8192),
    CMD(CM_PJMP, 12, 8195, 8193),
};

/* script: 17 SP APPEAR 2 */
const u16 dudley_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_017[20] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RJA4, 5, 27, 30),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 dudley_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_018[28] = {
    CMD(CM_RJA, 5, 32, 7),
    CMD(CM_RJA2, 5, 32, 21),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_WSET, 16385, 0, 2),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 dudley_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_019[16] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 dudley_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_020[16] = {
    CMD(CM_RJA, 5, 48, 16),
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 dudley_cbca_021_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_021[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 3952, 0, 8, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 dudley_cbca_022_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_022[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 9, 3952, 0, 72, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 9, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 dudley_cbca_023_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_023[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 3952, 0, 72, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 dudley_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_024[28] = {
    CMD(CM_WSET, 16385, 0, 112),
    CMD(CM_WSWK, 16385, 1, 16397),
    CMD(CM_WCNE, 16385, 0, 16387),
    CMD(CM_RJA, 5, 74, 1),
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 73, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 dudley_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_025[12] = {
    CMD(CM_RJA, 5, 41, 6),
    CMD(CM_RJA4, 5, 41, 25),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 dudley_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_026[12] = {
    CMD(CM_RJA, 5, 42, 6),
    CMD(CM_RJA4, 5, 42, 26),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 dudley_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_027[16] = {
    CMD(CM_CAFR, 2, 3, 1),
    CMD(CM_CARE, 2, 3, 1),
    CMD(CM_RJA7, 4, 16, 4),
    CMD(CM_DJMP, 8202, 8200, 8200),
};

/* script: 28 ZANNEN 5 */
const u16 dudley_cbca_028_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_028[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 3952, 0, 8, 22, 32, 0, 0, 120, 5, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 22, 32, 0, 0, 120, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 dudley_cbca_029_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_029[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 3952, 0, 8, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A56, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 dudley_cbca_030_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_030[64] = {
    CMD(CM_RMJA, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 16384), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 3952, 0, 8, 0, 0, 0, 0, 122, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 dudley_cbca_031_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_031[64] = {
    CMD(CM_RMJA, 5, 73, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 2304, 0, 8, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 dudley_cbca_032_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_032[64] = {
    CMD(CM_RMJA, 5, 73, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 2304, 0, 104, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 dudley_cbca_033_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_033[64] = {
    CMD(CM_RMJA, 5, 73, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 2304, 0, 104, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 dudley_cbca_034_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_034[64] = {
    CMD(CM_RMJA, 5, 73, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 2560, 0, 8, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 dudley_cbca_035_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_035[64] = {
    CMD(CM_RMJA, 5, 73, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 2560, 0, 104, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 dudley_cbca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_036[64] = {
    CMD(CM_RMJA, 5, 73, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 2560, 0, 72, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 dudley_cbca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_037[64] = {
    CMD(CM_RMJA, 5, 73, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 3072, 0, 8, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1A57, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 dudley_cbca_038_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_038[64] = {
    CMD(CM_RMJA, 5, 73, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 3072, 0, 72, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x187B, 0, 103, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 dudley_cbca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_039[64] = {
    CMD(CM_RMJA, 5, 73, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 3072, 0, 72, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x187C, 0, 9, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 dudley_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_040[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 33, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 dudley_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_041[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 dudley_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_042[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 dudley_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_043[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 dudley_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 42, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 dudley_cbca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_045[12] = {
    CMD(CM_RJA, 5, 43, 7),
    CMD(CM_RJA4, 5, 43, 41),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 dudley_cbca_046_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 dudley_cbca_046[16] = {
    CMD(CM_EXEC, 49, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 dudley_cbca_047_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 dudley_cbca_047[16] = {
    CMD(CM_EXEC, 49, 6, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 dudley_cbca_048_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 dudley_cbca_048[16] = {
    CMD(CM_EXEC, 49, 7, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 dudley_cbca_049_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 dudley_cbca_049[16] = {
    CMD(CM_EXEC, 49, 8, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 dudley_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_050[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 44, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 dudley_cbca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 dudley_cbca_051[20] = {
    CMD(CM_IF_S, 512, 8192, 16386),
    CMD(CM_JMP, 4, 156, 5),
    CMD(CM_IF_L, 2, 8192, 8206),
    CMD(CM_SSE, 909, 0, 0),
    CMD(CM_JMP, 4, 169, 1),
};

/* script: 52 JUDGMENT WIN */
const u16 dudley_cbca_052_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 dudley_cbca_052[16] = {
    CMD(CM_EXEC, 49, 48, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

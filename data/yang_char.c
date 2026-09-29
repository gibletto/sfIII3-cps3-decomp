/*
 * YANG_CHAR.C  Yang's animation scripts and sprite part tables
 *
 * The animation scripts Yang's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 yang_nmca_000[], yang_nmca_001[], yang_nmca_002[], yang_nmca_003[], yang_nmca_004[], yang_nmca_005[], yang_nmca_006[], yang_nmca_007[], yang_nmca_008[], yang_nmca_011[], yang_nmca_012[], yang_nmca_013[], yang_nmca_014[], yang_nmca_015[], yang_nmca_016[], yang_nmca_017[], yang_nmca_020[], yang_nmca_021[], yang_nmca_022[], yang_nmca_023[], yang_nmca_024[], yang_nmca_026[], yang_nmca_027[], yang_nmca_029[], yang_nmca_030[], yang_nmca_031[], yang_nmca_033[], yang_nmca_038[], yang_nmca_040[], yang_nmca_041[], yang_nmca_043[], yang_nmca_044[], yang_nmca_045[], yang_nmca_046[], yang_nmca_047[], yang_nmca_048[], yang_nmca_049[], yang_nmca_050[], yang_nmca_051[], yang_nmca_052[], yang_nmca_053[];
extern const u16 yang_nmca_000_head[];
extern const u16 yang_nmca_001_head[];
extern const u16 yang_nmca_002_head[];
extern const u16 yang_nmca_003_head[];
extern const u16 yang_nmca_004_head[];
extern const u16 yang_nmca_005_head[];
extern const u16 yang_nmca_006_head[];
extern const u16 yang_nmca_007_head[];
extern const u16 yang_nmca_008_head[];
extern const u16 yang_nmca_011_head[];
extern const u16 yang_nmca_012_head[];
extern const u16 yang_nmca_013_head[];
extern const u16 yang_nmca_014_head[];
extern const u16 yang_nmca_015_head[];
extern const u16 yang_nmca_016_head[];
extern const u16 yang_nmca_017_head[];
extern const u16 yang_nmca_020_head[];
extern const u16 yang_nmca_021_head[];
extern const u16 yang_nmca_022_head[];
extern const u16 yang_nmca_023_head[];
extern const u16 yang_nmca_024_head[];
extern const u16 yang_nmca_026_head[];
extern const u16 yang_nmca_027_head[];
extern const u16 yang_nmca_029_head[];
extern const u16 yang_nmca_030_head[];
extern const u16 yang_nmca_031_head[];
extern const u16 yang_nmca_033_head[];
extern const u16 yang_nmca_038_head[];
extern const u16 yang_nmca_040_head[];
extern const u16 yang_nmca_041_head[];
extern const u16 yang_nmca_043_head[];
extern const u16 yang_nmca_044_head[];
extern const u16 yang_nmca_045_head[];
extern const u16 yang_nmca_046_head[];
extern const u16 yang_nmca_047_head[];
extern const u16 yang_nmca_048_head[];
extern const u16 yang_nmca_049_head[];
extern const u16 yang_nmca_050_head[];
extern const u16 yang_nmca_051_head[];
extern const u16 yang_nmca_052_head[];
extern const u16 yang_nmca_053_head[];
extern const u16 yang_dmca_000[], yang_dmca_001[], yang_dmca_002[], yang_dmca_003[], yang_dmca_004[], yang_dmca_006[], yang_dmca_008[], yang_dmca_009[], yang_dmca_010[], yang_dmca_014[], yang_dmca_018[], yang_dmca_022[], yang_dmca_025[], yang_dmca_026[], yang_dmca_024[], yang_dmca_029[], yang_dmca_030[], yang_dmca_034[], yang_dmca_036[], yang_dmca_048[], yang_dmca_049[], yang_dmca_050[], yang_dmca_052[], yang_dmca_060[], yang_dmca_064[], yang_dmca_065[], yang_dmca_066[], yang_dmca_067[], yang_dmca_068[], yang_dmca_070[], yang_dmca_071[], yang_dmca_072[], yang_dmca_073[], yang_dmca_074[], yang_dmca_075[], yang_dmca_076[], yang_dmca_078[], yang_dmca_079[], yang_dmca_080[], yang_dmca_082[], yang_dmca_083[], yang_dmca_084[], yang_dmca_090[], yang_dmca_091[], yang_dmca_096[], yang_dmca_097[];
extern const u16 yang_dmca_000_head[];
extern const u16 yang_dmca_001_head[];
extern const u16 yang_dmca_002_head[];
extern const u16 yang_dmca_003_head[];
extern const u16 yang_dmca_004_head[];
extern const u16 yang_dmca_006_head[];
extern const u16 yang_dmca_008_head[];
extern const u16 yang_dmca_009_head[];
extern const u16 yang_dmca_010_head[];
extern const u16 yang_dmca_014_head[];
extern const u16 yang_dmca_018_head[];
extern const u16 yang_dmca_022_head[];
extern const u16 yang_dmca_025_head[];
extern const u16 yang_dmca_026_head[];
extern const u16 yang_dmca_024_head[];
extern const u16 yang_dmca_029_head[];
extern const u16 yang_dmca_030_head[];
extern const u16 yang_dmca_034_head[];
extern const u16 yang_dmca_036_head[];
extern const u16 yang_dmca_048_head[];
extern const u16 yang_dmca_049_head[];
extern const u16 yang_dmca_050_head[];
extern const u16 yang_dmca_052_head[];
extern const u16 yang_dmca_060_head[];
extern const u16 yang_dmca_064_head[];
extern const u16 yang_dmca_065_head[];
extern const u16 yang_dmca_066_head[];
extern const u16 yang_dmca_067_head[];
extern const u16 yang_dmca_068_head[];
extern const u16 yang_dmca_070_head[];
extern const u16 yang_dmca_071_head[];
extern const u16 yang_dmca_072_head[];
extern const u16 yang_dmca_073_head[];
extern const u16 yang_dmca_074_head[];
extern const u16 yang_dmca_075_head[];
extern const u16 yang_dmca_076_head[];
extern const u16 yang_dmca_078_head[];
extern const u16 yang_dmca_079_head[];
extern const u16 yang_dmca_080_head[];
extern const u16 yang_dmca_082_head[];
extern const u16 yang_dmca_083_head[];
extern const u16 yang_dmca_084_head[];
extern const u16 yang_dmca_090_head[];
extern const u16 yang_dmca_091_head[];
extern const u16 yang_dmca_096_head[];
extern const u16 yang_dmca_097_head[];
extern const u16 yang_btca_000[], yang_btca_001[], yang_btca_002[], yang_btca_003[], yang_btca_004[], yang_btca_005[], yang_btca_006[], yang_btca_007[], yang_btca_008[], yang_btca_009[], yang_btca_010[], yang_btca_011[], yang_btca_012[], yang_btca_013[], yang_btca_014[], yang_btca_015[], yang_btca_016[], yang_btca_017[], yang_btca_018[], yang_btca_019[], yang_btca_020[], yang_btca_021[], yang_btca_022[], yang_btca_023[], yang_btca_024[], yang_btca_025[], yang_btca_026[], yang_btca_027[], yang_btca_028[], yang_btca_029[], yang_btca_030[], yang_btca_031[], yang_btca_032[], yang_btca_033[], yang_btca_034[], yang_btca_035[];
extern const u16 yang_btca_000_head[];
extern const u16 yang_btca_001_head[];
extern const u16 yang_btca_002_head[];
extern const u16 yang_btca_003_head[];
extern const u16 yang_btca_004_head[];
extern const u16 yang_btca_005_head[];
extern const u16 yang_btca_006_head[];
extern const u16 yang_btca_007_head[];
extern const u16 yang_btca_008_head[];
extern const u16 yang_btca_009_head[];
extern const u16 yang_btca_010_head[];
extern const u16 yang_btca_011_head[];
extern const u16 yang_btca_012_head[];
extern const u16 yang_btca_013_head[];
extern const u16 yang_btca_014_head[];
extern const u16 yang_btca_015_head[];
extern const u16 yang_btca_016_head[];
extern const u16 yang_btca_017_head[];
extern const u16 yang_btca_018_head[];
extern const u16 yang_btca_019_head[];
extern const u16 yang_btca_020_head[];
extern const u16 yang_btca_021_head[];
extern const u16 yang_btca_022_head[];
extern const u16 yang_btca_023_head[];
extern const u16 yang_btca_024_head[];
extern const u16 yang_btca_025_head[];
extern const u16 yang_btca_026_head[];
extern const u16 yang_btca_027_head[];
extern const u16 yang_btca_028_head[];
extern const u16 yang_btca_029_head[];
extern const u16 yang_btca_030_head[];
extern const u16 yang_btca_031_head[];
extern const u16 yang_btca_032_head[];
extern const u16 yang_btca_033_head[];
extern const u16 yang_btca_034_head[];
extern const u16 yang_btca_035_head[];
extern const u16 yang_caca_000[], yang_caca_001[], yang_caca_002[], yang_caca_003[], yang_caca_004[], yang_caca_005[], yang_caca_006[], yang_caca_007[], yang_caca_008[], yang_caca_009[];
extern const u16 yang_caca_000_head[];
extern const u16 yang_caca_001_head[];
extern const u16 yang_caca_002_head[];
extern const u16 yang_caca_003_head[];
extern const u16 yang_caca_004_head[];
extern const u16 yang_caca_005_head[];
extern const u16 yang_caca_006_head[];
extern const u16 yang_caca_007_head[];
extern const u16 yang_caca_008_head[];
extern const u16 yang_caca_009_head[];
extern const u16 yang_cuca_000[], yang_cuca_001[], yang_cuca_002[], yang_cuca_003[], yang_cuca_004[], yang_cuca_005[], yang_cuca_006[], yang_cuca_007[], yang_cuca_008[], yang_cuca_009[], yang_cuca_010[], yang_cuca_011[], yang_cuca_012[], yang_cuca_013[], yang_cuca_014[], yang_cuca_015[], yang_cuca_016[], yang_cuca_017[], yang_cuca_018[], yang_cuca_019[], yang_cuca_020[], yang_cuca_021[], yang_cuca_022[], yang_cuca_023[], yang_cuca_024[], yang_cuca_025[], yang_cuca_026[], yang_cuca_027[], yang_cuca_028[], yang_cuca_029[], yang_cuca_030[], yang_cuca_031[], yang_cuca_032[], yang_cuca_033[], yang_cuca_034[], yang_cuca_035[], yang_cuca_036[], yang_cuca_037[], yang_cuca_038[], yang_cuca_039[], yang_cuca_040[], yang_cuca_041[], yang_cuca_042[], yang_cuca_043[], yang_cuca_044[], yang_cuca_045[], yang_cuca_046[], yang_cuca_047[], yang_cuca_048[], yang_cuca_049[], yang_cuca_050[], yang_cuca_051[], yang_cuca_052[], yang_cuca_053[], yang_cuca_054[], yang_cuca_055[], yang_cuca_056[], yang_cuca_057[], yang_cuca_058[], yang_cuca_059[], yang_cuca_060[], yang_cuca_061[], yang_cuca_062[], yang_cuca_063[], yang_cuca_064[], yang_cuca_065[], yang_cuca_066[], yang_cuca_067[];
extern const u16 yang_cuca_000_head[];
extern const u16 yang_cuca_001_head[];
extern const u16 yang_cuca_002_head[];
extern const u16 yang_cuca_003_head[];
extern const u16 yang_cuca_004_head[];
extern const u16 yang_cuca_005_head[];
extern const u16 yang_cuca_006_head[];
extern const u16 yang_cuca_007_head[];
extern const u16 yang_cuca_008_head[];
extern const u16 yang_cuca_009_head[];
extern const u16 yang_cuca_010_head[];
extern const u16 yang_cuca_011_head[];
extern const u16 yang_cuca_012_head[];
extern const u16 yang_cuca_013_head[];
extern const u16 yang_cuca_014_head[];
extern const u16 yang_cuca_015_head[];
extern const u16 yang_cuca_016_head[];
extern const u16 yang_cuca_017_head[];
extern const u16 yang_cuca_018_head[];
extern const u16 yang_cuca_019_head[];
extern const u16 yang_cuca_020_head[];
extern const u16 yang_cuca_021_head[];
extern const u16 yang_cuca_022_head[];
extern const u16 yang_cuca_023_head[];
extern const u16 yang_cuca_024_head[];
extern const u16 yang_cuca_025_head[];
extern const u16 yang_cuca_026_head[];
extern const u16 yang_cuca_027_head[];
extern const u16 yang_cuca_028_head[];
extern const u16 yang_cuca_029_head[];
extern const u16 yang_cuca_030_head[];
extern const u16 yang_cuca_031_head[];
extern const u16 yang_cuca_032_head[];
extern const u16 yang_cuca_033_head[];
extern const u16 yang_cuca_034_head[];
extern const u16 yang_cuca_035_head[];
extern const u16 yang_cuca_036_head[];
extern const u16 yang_cuca_037_head[];
extern const u16 yang_cuca_038_head[];
extern const u16 yang_cuca_039_head[];
extern const u16 yang_cuca_040_head[];
extern const u16 yang_cuca_041_head[];
extern const u16 yang_cuca_042_head[];
extern const u16 yang_cuca_043_head[];
extern const u16 yang_cuca_044_head[];
extern const u16 yang_cuca_045_head[];
extern const u16 yang_cuca_046_head[];
extern const u16 yang_cuca_047_head[];
extern const u16 yang_cuca_048_head[];
extern const u16 yang_cuca_049_head[];
extern const u16 yang_cuca_050_head[];
extern const u16 yang_cuca_051_head[];
extern const u16 yang_cuca_052_head[];
extern const u16 yang_cuca_053_head[];
extern const u16 yang_cuca_054_head[];
extern const u16 yang_cuca_055_head[];
extern const u16 yang_cuca_056_head[];
extern const u16 yang_cuca_057_head[];
extern const u16 yang_cuca_058_head[];
extern const u16 yang_cuca_059_head[];
extern const u16 yang_cuca_060_head[];
extern const u16 yang_cuca_061_head[];
extern const u16 yang_cuca_062_head[];
extern const u16 yang_cuca_063_head[];
extern const u16 yang_cuca_064_head[];
extern const u16 yang_cuca_065_head[];
extern const u16 yang_cuca_066_head[];
extern const u16 yang_cuca_067_head[];
extern const u16 yang_atca_000[], yang_atca_003[], yang_atca_004[], yang_atca_006[], yang_atca_007[], yang_atca_009[], yang_atca_012[], yang_atca_013[], yang_atca_014[], yang_atca_015[], yang_atca_018[], yang_atca_021[], yang_atca_024[], yang_atca_027[], yang_atca_030[], yang_atca_033[], yang_atca_036[], yang_atca_038[], yang_atca_040[], yang_atca_042[], yang_atca_044[], yang_atca_046[], yang_atca_048[], yang_atca_050[], yang_atca_052[], yang_atca_054[], yang_atca_055[], yang_atca_056[], yang_atca_057[], yang_atca_058[], yang_atca_059[], yang_atca_060[], yang_atca_062[], yang_atca_064[], yang_atca_066[], yang_atca_068[], yang_atca_070[], yang_atca_072[], yang_atca_074[], yang_atca_076[], yang_atca_078[], yang_atca_080[], yang_atca_082[], yang_atca_084[], yang_atca_086[], yang_atca_088[], yang_atca_090[], yang_atca_091[], yang_atca_092[], yang_atca_093[], yang_atca_094[], yang_atca_095[], yang_atca_096[], yang_atca_098[], yang_atca_100[], yang_atca_102[], yang_atca_104[], yang_atca_106[], yang_atca_108[], yang_atca_110[], yang_atca_112[], yang_atca_114[], yang_atca_116[], yang_atca_118[], yang_atca_146[], yang_atca_156[], yang_atca_157[], yang_atca_158[], yang_atca_159[], yang_atca_160[], yang_atca_161[], yang_atca_162[], yang_atca_200[], yang_atca_203[], yang_atca_204[], yang_atca_206[], yang_atca_208[], yang_atca_209[], yang_atca_212[], yang_atca_214[], yang_atca_215[], yang_atca_218[], yang_atca_221[], yang_atca_224[], yang_atca_227[], yang_atca_230[], yang_atca_233[], yang_atca_236[], yang_atca_238[], yang_atca_240[], yang_atca_242[], yang_atca_244[], yang_atca_246[], yang_atca_248[], yang_atca_250[], yang_atca_252[], yang_atca_254[], yang_atca_255[], yang_atca_256[], yang_atca_257[], yang_atca_258[], yang_atca_259[], yang_atca_260[], yang_atca_144[], yang_atca_145[];
extern const u16 yang_atca_000_head[];
extern const u16 yang_atca_003_head[];
extern const u16 yang_atca_004_head[];
extern const u16 yang_atca_006_head[];
extern const u16 yang_atca_007_head[];
extern const u16 yang_atca_009_head[];
extern const u16 yang_atca_012_head[];
extern const u16 yang_atca_013_head[];
extern const u16 yang_atca_014_head[];
extern const u16 yang_atca_015_head[];
extern const u16 yang_atca_018_head[];
extern const u16 yang_atca_021_head[];
extern const u16 yang_atca_024_head[];
extern const u16 yang_atca_027_head[];
extern const u16 yang_atca_030_head[];
extern const u16 yang_atca_033_head[];
extern const u16 yang_atca_036_head[];
extern const u16 yang_atca_038_head[];
extern const u16 yang_atca_040_head[];
extern const u16 yang_atca_042_head[];
extern const u16 yang_atca_044_head[];
extern const u16 yang_atca_046_head[];
extern const u16 yang_atca_048_head[];
extern const u16 yang_atca_050_head[];
extern const u16 yang_atca_052_head[];
extern const u16 yang_atca_054_head[];
extern const u16 yang_atca_055_head[];
extern const u16 yang_atca_056_head[];
extern const u16 yang_atca_057_head[];
extern const u16 yang_atca_058_head[];
extern const u16 yang_atca_059_head[];
extern const u16 yang_atca_060_head[];
extern const u16 yang_atca_062_head[];
extern const u16 yang_atca_064_head[];
extern const u16 yang_atca_066_head[];
extern const u16 yang_atca_068_head[];
extern const u16 yang_atca_070_head[];
extern const u16 yang_atca_072_head[];
extern const u16 yang_atca_074_head[];
extern const u16 yang_atca_076_head[];
extern const u16 yang_atca_078_head[];
extern const u16 yang_atca_080_head[];
extern const u16 yang_atca_082_head[];
extern const u16 yang_atca_084_head[];
extern const u16 yang_atca_086_head[];
extern const u16 yang_atca_088_head[];
extern const u16 yang_atca_090_head[];
extern const u16 yang_atca_091_head[];
extern const u16 yang_atca_092_head[];
extern const u16 yang_atca_093_head[];
extern const u16 yang_atca_094_head[];
extern const u16 yang_atca_095_head[];
extern const u16 yang_atca_096_head[];
extern const u16 yang_atca_098_head[];
extern const u16 yang_atca_100_head[];
extern const u16 yang_atca_102_head[];
extern const u16 yang_atca_104_head[];
extern const u16 yang_atca_106_head[];
extern const u16 yang_atca_108_head[];
extern const u16 yang_atca_110_head[];
extern const u16 yang_atca_112_head[];
extern const u16 yang_atca_114_head[];
extern const u16 yang_atca_116_head[];
extern const u16 yang_atca_118_head[];
extern const u16 yang_atca_146_head[];
extern const u16 yang_atca_156_head[];
extern const u16 yang_atca_157_head[];
extern const u16 yang_atca_158_head[];
extern const u16 yang_atca_159_head[];
extern const u16 yang_atca_160_head[];
extern const u16 yang_atca_161_head[];
extern const u16 yang_atca_162_head[];
extern const u16 yang_atca_200_head[];
extern const u16 yang_atca_203_head[];
extern const u16 yang_atca_204_head[];
extern const u16 yang_atca_206_head[];
extern const u16 yang_atca_208_head[];
extern const u16 yang_atca_209_head[];
extern const u16 yang_atca_212_head[];
extern const u16 yang_atca_214_head[];
extern const u16 yang_atca_215_head[];
extern const u16 yang_atca_218_head[];
extern const u16 yang_atca_221_head[];
extern const u16 yang_atca_224_head[];
extern const u16 yang_atca_227_head[];
extern const u16 yang_atca_230_head[];
extern const u16 yang_atca_233_head[];
extern const u16 yang_atca_236_head[];
extern const u16 yang_atca_238_head[];
extern const u16 yang_atca_240_head[];
extern const u16 yang_atca_242_head[];
extern const u16 yang_atca_244_head[];
extern const u16 yang_atca_246_head[];
extern const u16 yang_atca_248_head[];
extern const u16 yang_atca_250_head[];
extern const u16 yang_atca_252_head[];
extern const u16 yang_atca_254_head[];
extern const u16 yang_atca_255_head[];
extern const u16 yang_atca_256_head[];
extern const u16 yang_atca_257_head[];
extern const u16 yang_atca_258_head[];
extern const u16 yang_atca_259_head[];
extern const u16 yang_atca_260_head[];
extern const u16 yang_atca_144_head[];
extern const u16 yang_atca_145_head[];
extern const u16 yang_exca_000[], yang_exca_001[], yang_exca_003[], yang_exca_004[], yang_exca_005[], yang_exca_006[], yang_exca_009[], yang_exca_010[], yang_exca_012[], yang_exca_013[], yang_exca_014[], yang_exca_015[], yang_exca_016[], yang_exca_017[], yang_exca_018[], yang_exca_019[], yang_exca_020[], yang_exca_021[], yang_exca_024[], yang_exca_025[], yang_exca_026[], yang_exca_027[], yang_exca_028[], yang_exca_029[], yang_exca_030[], yang_exca_031[], yang_exca_032[], yang_exca_033[], yang_exca_034[], yang_exca_035[], yang_exca_036[], yang_exca_037[], yang_exca_038[], yang_exca_039[], yang_exca_040[], yang_exca_041[], yang_exca_042[], yang_exca_043[], yang_exca_044[], yang_exca_045[], yang_exca_046[], yang_exca_047[], yang_exca_048[], yang_exca_049[], yang_exca_050[], yang_exca_051[], yang_exca_052[], yang_exca_053[], yang_exca_054[], yang_exca_056[], yang_exca_058[], yang_exca_061[], yang_exca_062[], yang_exca_063[], yang_exca_064[], yang_exca_065[], yang_exca_066[], yang_exca_022[], yang_exca_073[], yang_exca_074[], yang_exca_075[], yang_exca_076[], yang_exca_077[], yang_exca_078[], yang_exca_079[], yang_exca_080[], yang_exca_081[], yang_exca_082[], yang_exca_083[], yang_exca_084[], yang_exca_085[], yang_exca_086[], yang_exca_087[], yang_exca_088[], yang_exca_089[], yang_exca_090[], yang_exca_091[], yang_exca_094[], yang_exca_095[], yang_exca_096[], yang_exca_097[], yang_exca_098[], yang_exca_099[], yang_exca_100[];
extern const u16 yang_exca_000_head[];
extern const u16 yang_exca_001_head[];
extern const u16 yang_exca_003_head[];
extern const u16 yang_exca_004_head[];
extern const u16 yang_exca_005_head[];
extern const u16 yang_exca_006_head[];
extern const u16 yang_exca_009_head[];
extern const u16 yang_exca_010_head[];
extern const u16 yang_exca_012_head[];
extern const u16 yang_exca_013_head[];
extern const u16 yang_exca_014_head[];
extern const u16 yang_exca_015_head[];
extern const u16 yang_exca_016_head[];
extern const u16 yang_exca_017_head[];
extern const u16 yang_exca_018_head[];
extern const u16 yang_exca_019_head[];
extern const u16 yang_exca_020_head[];
extern const u16 yang_exca_021_head[];
extern const u16 yang_exca_024_head[];
extern const u16 yang_exca_025_head[];
extern const u16 yang_exca_026_head[];
extern const u16 yang_exca_027_head[];
extern const u16 yang_exca_028_head[];
extern const u16 yang_exca_029_head[];
extern const u16 yang_exca_030_head[];
extern const u16 yang_exca_031_head[];
extern const u16 yang_exca_032_head[];
extern const u16 yang_exca_033_head[];
extern const u16 yang_exca_034_head[];
extern const u16 yang_exca_035_head[];
extern const u16 yang_exca_036_head[];
extern const u16 yang_exca_037_head[];
extern const u16 yang_exca_038_head[];
extern const u16 yang_exca_039_head[];
extern const u16 yang_exca_040_head[];
extern const u16 yang_exca_041_head[];
extern const u16 yang_exca_042_head[];
extern const u16 yang_exca_043_head[];
extern const u16 yang_exca_044_head[];
extern const u16 yang_exca_045_head[];
extern const u16 yang_exca_046_head[];
extern const u16 yang_exca_047_head[];
extern const u16 yang_exca_048_head[];
extern const u16 yang_exca_049_head[];
extern const u16 yang_exca_050_head[];
extern const u16 yang_exca_051_head[];
extern const u16 yang_exca_052_head[];
extern const u16 yang_exca_053_head[];
extern const u16 yang_exca_054_head[];
extern const u16 yang_exca_056_head[];
extern const u16 yang_exca_058_head[];
extern const u16 yang_exca_061_head[];
extern const u16 yang_exca_062_head[];
extern const u16 yang_exca_063_head[];
extern const u16 yang_exca_064_head[];
extern const u16 yang_exca_065_head[];
extern const u16 yang_exca_066_head[];
extern const u16 yang_exca_022_head[];
extern const u16 yang_exca_073_head[];
extern const u16 yang_exca_074_head[];
extern const u16 yang_exca_075_head[];
extern const u16 yang_exca_076_head[];
extern const u16 yang_exca_077_head[];
extern const u16 yang_exca_078_head[];
extern const u16 yang_exca_079_head[];
extern const u16 yang_exca_080_head[];
extern const u16 yang_exca_081_head[];
extern const u16 yang_exca_082_head[];
extern const u16 yang_exca_083_head[];
extern const u16 yang_exca_084_head[];
extern const u16 yang_exca_085_head[];
extern const u16 yang_exca_086_head[];
extern const u16 yang_exca_087_head[];
extern const u16 yang_exca_088_head[];
extern const u16 yang_exca_089_head[];
extern const u16 yang_exca_090_head[];
extern const u16 yang_exca_091_head[];
extern const u16 yang_exca_094_head[];
extern const u16 yang_exca_095_head[];
extern const u16 yang_exca_096_head[];
extern const u16 yang_exca_097_head[];
extern const u16 yang_exca_098_head[];
extern const u16 yang_exca_099_head[];
extern const u16 yang_exca_100_head[];
extern const u16 yang_saca_000[], yang_saca_001[], yang_saca_002[], yang_saca_024[], yang_saca_028[], yang_saca_031[], yang_saca_032[], yang_saca_033[], yang_saca_034[], yang_saca_035[], yang_saca_036[], yang_saca_037[], yang_saca_038[], yang_saca_039[], yang_saca_040[], yang_saca_044[], yang_saca_056[], yang_saca_060[], yang_saca_061[], yang_saca_065[], yang_saca_066[], yang_saca_067[], yang_saca_068[], yang_saca_069[], yang_saca_070[], yang_saca_074[], yang_saca_075[], yang_saca_076[], yang_saca_080[], yang_saca_083[], yang_saca_087[], yang_saca_088[], yang_saca_089[], yang_saca_091[], yang_saca_092[], yang_saca_093[], yang_saca_094[], yang_saca_096[], yang_saca_097[], yang_saca_098[], yang_saca_099[], yang_saca_100[], yang_saca_101[], yang_saca_048[], yang_saca_052[], yang_saca_102[], yang_saca_103[], yang_saca_104[], yang_saca_106[], yang_saca_107[], yang_saca_108[], yang_saca_109[];
extern const u16 yang_saca_000_head[];
extern const u16 yang_saca_001_head[];
extern const u16 yang_saca_002_head[];
extern const u16 yang_saca_024_head[];
extern const u16 yang_saca_028_head[];
extern const u16 yang_saca_031_head[];
extern const u16 yang_saca_032_head[];
extern const u16 yang_saca_033_head[];
extern const u16 yang_saca_034_head[];
extern const u16 yang_saca_035_head[];
extern const u16 yang_saca_036_head[];
extern const u16 yang_saca_037_head[];
extern const u16 yang_saca_038_head[];
extern const u16 yang_saca_039_head[];
extern const u16 yang_saca_040_head[];
extern const u16 yang_saca_044_head[];
extern const u16 yang_saca_056_head[];
extern const u16 yang_saca_060_head[];
extern const u16 yang_saca_061_head[];
extern const u16 yang_saca_065_head[];
extern const u16 yang_saca_066_head[];
extern const u16 yang_saca_067_head[];
extern const u16 yang_saca_068_head[];
extern const u16 yang_saca_069_head[];
extern const u16 yang_saca_070_head[];
extern const u16 yang_saca_074_head[];
extern const u16 yang_saca_075_head[];
extern const u16 yang_saca_076_head[];
extern const u16 yang_saca_080_head[];
extern const u16 yang_saca_083_head[];
extern const u16 yang_saca_087_head[];
extern const u16 yang_saca_088_head[];
extern const u16 yang_saca_089_head[];
extern const u16 yang_saca_091_head[];
extern const u16 yang_saca_092_head[];
extern const u16 yang_saca_093_head[];
extern const u16 yang_saca_094_head[];
extern const u16 yang_saca_096_head[];
extern const u16 yang_saca_097_head[];
extern const u16 yang_saca_098_head[];
extern const u16 yang_saca_099_head[];
extern const u16 yang_saca_100_head[];
extern const u16 yang_saca_101_head[];
extern const u16 yang_saca_048_head[];
extern const u16 yang_saca_052_head[];
extern const u16 yang_saca_102_head[];
extern const u16 yang_saca_103_head[];
extern const u16 yang_saca_104_head[];
extern const u16 yang_saca_106_head[];
extern const u16 yang_saca_107_head[];
extern const u16 yang_saca_108_head[];
extern const u16 yang_saca_109_head[];
extern const u16 yang_cbca_000[], yang_cbca_001[], yang_cbca_002[], yang_cbca_003[], yang_cbca_004[], yang_cbca_005[], yang_cbca_006[], yang_cbca_010[], yang_cbca_011[], yang_cbca_012[], yang_cbca_013[], yang_cbca_014[], yang_cbca_015[], yang_cbca_016[], yang_cbca_017[], yang_cbca_018[], yang_cbca_019[], yang_cbca_020[], yang_cbca_021[], yang_cbca_022[], yang_cbca_023[], yang_cbca_024[], yang_cbca_025[], yang_cbca_026[], yang_cbca_027[], yang_cbca_028[], yang_cbca_029[], yang_cbca_030[], yang_cbca_031[], yang_cbca_032[], yang_cbca_033[], yang_cbca_034[], yang_cbca_035[], yang_cbca_036[], yang_cbca_037[], yang_cbca_038[], yang_cbca_039[], yang_cbca_040[], yang_cbca_041[], yang_cbca_042[], yang_cbca_043[], yang_cbca_044[], yang_cbca_045[], yang_cbca_046[], yang_cbca_047[], yang_cbca_048[], yang_cbca_049[], yang_cbca_050[], yang_cbca_051[], yang_cbca_052[], yang_cbca_053[], yang_cbca_054[], yang_cbca_055[], yang_cbca_056[], yang_cbca_057[], yang_cbca_058[], yang_cbca_059[], yang_cbca_060[], yang_cbca_061[], yang_cbca_062[], yang_cbca_063[], yang_cbca_064[], yang_cbca_065[], yang_cbca_066[], yang_cbca_067[], yang_cbca_068[], yang_cbca_069[], yang_cbca_070[], yang_cbca_071[], yang_cbca_072[], yang_cbca_073[], yang_cbca_074[], yang_cbca_075[], yang_cbca_077[], yang_cbca_078[], yang_cbca_079[], yang_cbca_080[], yang_cbca_081[], yang_cbca_082[], yang_cbca_083[], yang_cbca_084[], yang_cbca_085[], yang_cbca_086[], yang_cbca_087[], yang_cbca_088[], yang_cbca_089[], yang_cbca_090[];
extern const u16 yang_cbca_000_head[];
extern const u16 yang_cbca_001_head[];
extern const u16 yang_cbca_002_head[];
extern const u16 yang_cbca_003_head[];
extern const u16 yang_cbca_004_head[];
extern const u16 yang_cbca_005_head[];
extern const u16 yang_cbca_006_head[];
extern const u16 yang_cbca_010_head[];
extern const u16 yang_cbca_011_head[];
extern const u16 yang_cbca_012_head[];
extern const u16 yang_cbca_013_head[];
extern const u16 yang_cbca_014_head[];
extern const u16 yang_cbca_015_head[];
extern const u16 yang_cbca_016_head[];
extern const u16 yang_cbca_017_head[];
extern const u16 yang_cbca_018_head[];
extern const u16 yang_cbca_019_head[];
extern const u16 yang_cbca_020_head[];
extern const u16 yang_cbca_021_head[];
extern const u16 yang_cbca_022_head[];
extern const u16 yang_cbca_023_head[];
extern const u16 yang_cbca_024_head[];
extern const u16 yang_cbca_025_head[];
extern const u16 yang_cbca_026_head[];
extern const u16 yang_cbca_027_head[];
extern const u16 yang_cbca_028_head[];
extern const u16 yang_cbca_029_head[];
extern const u16 yang_cbca_030_head[];
extern const u16 yang_cbca_031_head[];
extern const u16 yang_cbca_032_head[];
extern const u16 yang_cbca_033_head[];
extern const u16 yang_cbca_034_head[];
extern const u16 yang_cbca_035_head[];
extern const u16 yang_cbca_036_head[];
extern const u16 yang_cbca_037_head[];
extern const u16 yang_cbca_038_head[];
extern const u16 yang_cbca_039_head[];
extern const u16 yang_cbca_040_head[];
extern const u16 yang_cbca_041_head[];
extern const u16 yang_cbca_042_head[];
extern const u16 yang_cbca_043_head[];
extern const u16 yang_cbca_044_head[];
extern const u16 yang_cbca_045_head[];
extern const u16 yang_cbca_046_head[];
extern const u16 yang_cbca_047_head[];
extern const u16 yang_cbca_048_head[];
extern const u16 yang_cbca_049_head[];
extern const u16 yang_cbca_050_head[];
extern const u16 yang_cbca_051_head[];
extern const u16 yang_cbca_052_head[];
extern const u16 yang_cbca_053_head[];
extern const u16 yang_cbca_054_head[];
extern const u16 yang_cbca_055_head[];
extern const u16 yang_cbca_056_head[];
extern const u16 yang_cbca_057_head[];
extern const u16 yang_cbca_058_head[];
extern const u16 yang_cbca_059_head[];
extern const u16 yang_cbca_060_head[];
extern const u16 yang_cbca_061_head[];
extern const u16 yang_cbca_062_head[];
extern const u16 yang_cbca_063_head[];
extern const u16 yang_cbca_064_head[];
extern const u16 yang_cbca_065_head[];
extern const u16 yang_cbca_066_head[];
extern const u16 yang_cbca_067_head[];
extern const u16 yang_cbca_068_head[];
extern const u16 yang_cbca_069_head[];
extern const u16 yang_cbca_070_head[];
extern const u16 yang_cbca_071_head[];
extern const u16 yang_cbca_072_head[];
extern const u16 yang_cbca_073_head[];
extern const u16 yang_cbca_074_head[];
extern const u16 yang_cbca_075_head[];
extern const u16 yang_cbca_077_head[];
extern const u16 yang_cbca_078_head[];
extern const u16 yang_cbca_079_head[];
extern const u16 yang_cbca_080_head[];
extern const u16 yang_cbca_081_head[];
extern const u16 yang_cbca_082_head[];
extern const u16 yang_cbca_083_head[];
extern const u16 yang_cbca_084_head[];
extern const u16 yang_cbca_085_head[];
extern const u16 yang_cbca_086_head[];
extern const u16 yang_cbca_087_head[];
extern const u16 yang_cbca_088_head[];
extern const u16 yang_cbca_089_head[];
extern const u16 yang_cbca_090_head[];

/* normal scripts: 54 entries */
const u16* const yang_nmca[55] = {
    yang_nmca_000,  /* 0 KAMAE */
    yang_nmca_001,  /* 1 HURIMUKI */
    yang_nmca_002,  /* 2 FRONT WALK */
    yang_nmca_003,  /* 3 BACK WALK */
    yang_nmca_004,  /* 4 DASH HUMIKOMI */
    yang_nmca_005,  /* 5 DASH TOBINOKI */
    yang_nmca_006,  /* 6 KAGAMU */
    yang_nmca_007,  /* 7 KAGAMI KAMAE */
    yang_nmca_008,  /* 8 KAGAMI TURN */
    yang_nmca_008,  /* 9 KAGAMI F WALK */
    yang_nmca_008,  /* 10 KAGAMI B WALK */
    yang_nmca_011,  /* 11 STAND UP */
    yang_nmca_012,  /* 12 JUMP JUNBI */
    yang_nmca_013,  /* 13 SP JUMP JUNBI */
    yang_nmca_014,  /* 14 JUMP FRONT */
    yang_nmca_015,  /* 15 JUMP VERTICAL */
    yang_nmca_016,  /* 16 JUMP BACK */
    yang_nmca_017,  /* 17 S JUMP FRONT */
    yang_nmca_017,  /* 18 S JUMP V */
    yang_nmca_017,  /* 19 S JUMP BACK */
    yang_nmca_020,  /* 20 SP JUMP FRONT */
    yang_nmca_021,  /* 21 SP JUMP V */
    yang_nmca_022,  /* 22 SP JUMP BACK */
    yang_nmca_023,  /* 23 WALK END */
    yang_nmca_024,  /* 24 PARING HEAD */
    yang_nmca_024,  /* 25 PARING UP */
    yang_nmca_026,  /* 26 PARING DOWN */
    yang_nmca_027,  /* 27 PARING AIR F */
    yang_nmca_027,  /* 28 PARING AIR B */
    yang_nmca_029,  /* 29 GUARD HEAD */
    yang_nmca_030,  /* 30 GUARD UP */
    yang_nmca_031,  /* 31 GUARD DOWN */
    yang_nmca_031,  /* 32 GUARD AIR */
    yang_nmca_033,  /* 33 no name */
    yang_nmca_033,  /* 34 no name */
    yang_nmca_033,  /* 35 no name */
    yang_nmca_033,  /* 36 no name */
    yang_nmca_033,  /* 37 no name */
    yang_nmca_038,  /* 38 P BREAK ZUJOU */
    yang_nmca_038,  /* 39 P BREAK UP */
    yang_nmca_040,  /* 40 P BREAK DOWN */
    yang_nmca_041,  /* 41 P BREAK AIR F */
    yang_nmca_041,  /* 42 P BREAK AIR R */
    yang_nmca_043,  /* 43 TUKAMIHAZUSI */
    yang_nmca_044,  /* 44 TUKAMIHAZUSARE */
    yang_nmca_045,  /* 45 TUKAMIHAZUSI */
    yang_nmca_046,  /* 46 TUKAMIHAZUSARE */
    yang_nmca_047,  /* 47 no name */
    yang_nmca_048,  /* 48 no name */
    yang_nmca_049,  /* 49 no name */
    yang_nmca_050,  /* 50 no name */
    yang_nmca_051,  /* 51 no name */
    yang_nmca_052,  /* 52 no name */
    yang_nmca_053,  /* 53 no name */
    0
};

/* script: 0 KAMAE */
const u16 yang_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_000[116] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCA, 0, 352, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCB, 0, 370, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCC, 0, 370, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCD, 0, 370, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCE, 0, 370, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCF, 0, 353, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD0, 0, 353, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD1, 0, 353, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD2, 0, 353, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD3, 0, 353, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD4, 0, 354, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD5, 0, 354, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD6, 0, 352, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 yang_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_001[68] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x3C19, 0, 340, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3C1A, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C1B, 0, 340, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C1C, 0, 341, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C1D, 0, 341, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C1E, 0, 341, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3C1F, 0, 341, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x3C1F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 yang_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 yang_nmca_002[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C56, 0, 335, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C20, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C21, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C22, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C23, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C24, 0, 337, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C25, 0, 337, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C26, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C27, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C26, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C25, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C24, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C23, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C22, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C21, 0, 337, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 yang_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 yang_nmca_003[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C58, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C28, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C29, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2A, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2B, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2C, 0, 339, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2D, 0, 339, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2E, 0, 339, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C2F, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2E, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2D, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2C, 0, 338, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2B, 0, 339, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C2A, 0, 339, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C29, 0, 339, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 yang_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 yang_nmca_004[220] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CB0, 0, 355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3CB1, 0, 356, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 277, 0, 0, 0, 0, 0x3CB2, 0, 356, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(8, 1, 0, 0, 0, 0, 0, 0x3CB3, 0, 357, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3CB4, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CB5, 0, 358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 0, 0, 0, 0, 0, 0x3CB6, 0, 359, 0, 0, 0, 0, 0, 0, 0, 4, 0, 128),
    L6(4, 3, 0, 0, 0, 0, 0, 0x3CB7, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 345, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 yang_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 yang_nmca_005[400] = {
    CMD(CM_RJA3, 0, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CB8, 0, 360, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CB9, 0, 360, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CBA, 0, 361, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 277, 0, 0, 0, 0, 0x3CBB, 0, 361, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CBC, 0, 362, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CBD, 0, 362, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CBE, 0, 362, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CBF, 0, 363, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC0, 0, 363, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 273, 0, 0, 0, 0, 0x3CC1, 0, 363, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CC2, 0, 364, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CC3, 0, 364, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC4, 0, 364, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC5, 0, 365, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC6, 0, 365, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC7, 0, 366, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3CC8, 0, 366, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CC9, 0, 367, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 273, 0, 0, 0, 0, 0x3CCA, 0, 367, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3CCB, 0, 368, 0, 0, 0, 0, 0, 0, 0, 16, 0, 128),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3CCC, 0, 368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C31, 0, 345, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 345, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 yang_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_nmca_006[60] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C30, 0, 371, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C31, 0, 371, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 345, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 345, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 345, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 yang_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_nmca_007[108] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C42, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C43, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C44, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C45, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C46, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C47, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C48, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C49, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C4A, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C4B, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C4C, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C4D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 yang_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_nmca_008[76] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x3C4E, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3C4F, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C50, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C51, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C52, 0, 342, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x3C53, 0, 342, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x3C54, 0, 342, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x3C55, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x3C55, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 yang_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_nmca_011[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 343, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 343, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C31, 0, 344, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C30, 0, 344, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 yang_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x3C40, 0, 281, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x3C40, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C40, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 yang_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3C7F, 0, 346, 0, 0, 0, 18, 2),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C7F, 0, 346, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 yang_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_nmca_014[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x3C70, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C71, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C72, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x3C73, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C74, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C75, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C76, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C77, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C78, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C79, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 yang_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 yang_nmca_015[124] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x3C60, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C61, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C62, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x3C63, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C64, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C65, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C66, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C67, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3C68, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C69, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6B, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 yang_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x3C80, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C81, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C82, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C83, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C84, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C85, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C86, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3C87, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C88, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C89, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8A, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8B, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 yang_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 yang_nmca_017[12] = {
    CMD(CM_JSR, 8, 2, 1),
    CMD(CM_JPSS, 0, 15, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 yang_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 yang_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 7, 0x3C70, 0, 347, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C71, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C72, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C73, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C74, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C75, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C76, 0, 348, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C77, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C78, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C79, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 349, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 yang_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 yang_nmca_021[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x3C60, 0, 347, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C61, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C62, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C63, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3C64, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C65, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C66, 0, 348, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C67, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C68, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C69, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C6B, 0, 349, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C6C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 yang_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 yang_nmca_022[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x3C80, 0, 347, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C81, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C82, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C83, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3C84, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x3C85, 0, 347, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C86, 0, 348, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3C87, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3C88, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x3C89, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C8A, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8B, 0, 349, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 yang_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 yang_nmca_024_head[4] = { HEAD(6, 2, 0, 0, 0, 0, 0) };
const u16 yang_nmca_024[88] = {
    L6(2, 133, 0, 0, 0, 0, 0, 0x3DA3, 0, 1, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 645, 0, 0, 0, 0, 0x3DA4, 0, 1, 0, 0, 0, 6, 0, 0, 0, 128, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3DA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DC6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 yang_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 yang_nmca_026[88] = {
    L6(1, 133, 0, 0, 0, 0, 0, 0x3C9B, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 645, 0, 0, 0, 0, 0x4078, 0, 2, 0, 0, 0, 6, 1, 0, 0, 128, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4079, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x407A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3FE3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3FE4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 yang_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_nmca_027[44] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x3CA5, 0, 3, 0, 0, 0, 18, 6),
    L4(3, 0, 645, 0, 0, 0, 0, 0x3CA6, 0, 3, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CA7, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 yang_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yang_nmca_029[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C90, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C91, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3C92, 0, 86, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3C93, 0, 86, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3C94, 0, 86, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C91, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C90, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C90, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 yang_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yang_nmca_030[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C97, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C98, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3C99, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3C9A, 0, 87, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3C9B, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C98, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN, 32 GUARD AIR */
const u16 yang_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 yang_nmca_031[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C9E, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C9F, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3CA0, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3CA1, 0, 88, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x3CA2, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C9F, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C9E, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C9E, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 yang_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_033[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x3C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 yang_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_038[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3C9C, 0, 87, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3C9D, 0, 87, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 yang_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_nmca_040[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3CA3, 0, 88, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CA4, 0, 88, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CD8, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 yang_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3CA5, 0, 3, 0, 0, 0, 18, 8),
    L4(250, 0, 645, 0, 0, 0, 0, 0x3CA6, 0, 3, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 yang_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_043[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3C9C, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3C9D, 0, 87, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 yang_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_044[44] = {
    L4(3, 131, 0, 0, 0, 0, 0, 0x3EB2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3EB2, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x3EB3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3EB1, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3EB1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 yang_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_nmca_045[92] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3CA5, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 645, 0, 0, 0, 0, 0x3CA6, 0, 3, 0, 0, 0, 25, 2),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3C87, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C88, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C89, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8C, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 yang_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_nmca_046[92] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x3C65, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3C66, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C6B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C6C, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 yang_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x3FCA, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yang_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 yang_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C01, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yang_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_050[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C9C, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C9D, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 yang_nmca_051_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_051[88] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F1C, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F1D, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F1E, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F1E, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 yang_nmca_052_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_nmca_052[192] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CC9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CCA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CCB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CCC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 53 no name */
const u16 yang_nmca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_nmca_053[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C80),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C81),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C82),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C83),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C84),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C85),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C8A),
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const yang_dmca[99] = {
    yang_dmca_000,  /* 0 GUARD HEAD */
    yang_dmca_001,  /* 1 GUARD UP */
    yang_dmca_002,  /* 2 GUARD DOWN */
    yang_dmca_003,  /* 3 GUARD AIR */
    yang_dmca_004,  /* 4 HUSHIN HEAD */
    yang_dmca_004,  /* 5 HUSHIN UP */
    yang_dmca_006,  /* 6 HUSHIN DOWN */
    yang_dmca_006,  /* 7 HUSHIN AIR */
    yang_dmca_008,  /* 8 FACE S */
    yang_dmca_009,  /* 9 FACE M */
    yang_dmca_010,  /* 10 FACE L */
    yang_dmca_010,  /* 11 FACE SP */
    yang_dmca_008,  /* 12 FOOK OKU S */
    yang_dmca_009,  /* 13 FOOK OKU M */
    yang_dmca_014,  /* 14 FOOK OKU L */
    yang_dmca_014,  /* 15 FOOK OKU SP */
    yang_dmca_008,  /* 16 FOOK TEMAE S */
    yang_dmca_009,  /* 17 FOOK TEMAE M */
    yang_dmca_018,  /* 18 FOOK TEMAE L */
    yang_dmca_018,  /* 19 FOOK TEMAE SP */
    yang_dmca_008,  /* 20 UPPER S */
    yang_dmca_009,  /* 21 UPPER M */
    yang_dmca_022,  /* 22 UPPER L */
    yang_dmca_022,  /* 23 UPPER SP */
    yang_dmca_024,  /* 24 NOUTEN S */
    yang_dmca_025,  /* 25 NOUTEN M */
    yang_dmca_026,  /* 26 NOUTEN L */
    yang_dmca_026,  /* 27 NOUTEN SP */
    yang_dmca_024,  /* 28 BODY BROW S */
    yang_dmca_029,  /* 29 BODY BROW M */
    yang_dmca_030,  /* 30 BODY BROW L */
    yang_dmca_030,  /* 31 BODY BROW SP */
    yang_dmca_024,  /* 32 BODY UPPER S */
    yang_dmca_029,  /* 33 BODY UPPER M */
    yang_dmca_034,  /* 34 BODY UPPER L */
    yang_dmca_034,  /* 35 BODY UPPER SP */
    yang_dmca_036,  /* 36 TATAKI S */
    yang_dmca_036,  /* 37 TATAKI M */
    yang_dmca_036,  /* 38 TATAKI L */
    yang_dmca_036,  /* 39 TATAKI SP */
    yang_dmca_036,  /* 40 TATAKI V. S */
    yang_dmca_036,  /* 41 TATAKI V. M */
    yang_dmca_036,  /* 42 TATAKI V. L */
    yang_dmca_036,  /* 43 TATAKI V. SP */
    yang_dmca_008,  /* 44 NOBASITA TE S */
    yang_dmca_009,  /* 45 NOBASITA TE M */
    yang_dmca_010,  /* 46 NOBASITA TE L */
    yang_dmca_010,  /* 47 NOBASITA TE SP */
    yang_dmca_048,  /* 48 KAGAMI S */
    yang_dmca_049,  /* 49 KAGAMI M */
    yang_dmca_050,  /* 50 KAGAMI L */
    yang_dmca_050,  /* 51 KAGAMI SP */
    yang_dmca_052,  /* 52 KGM TATAKI S */
    yang_dmca_052,  /* 53 KGM TATAKI M */
    yang_dmca_052,  /* 54 KGM TATAKI L */
    yang_dmca_052,  /* 55 KGM TATAKI SP */
    yang_dmca_052,  /* 56 KGM TTKI V.S */
    yang_dmca_052,  /* 57 KGM TTKI V.M */
    yang_dmca_052,  /* 58 KGM TTKI V.L */
    yang_dmca_052,  /* 59 KGM TTKI V.SP */
    yang_dmca_060,  /* 60 NEKOROBI S */
    yang_dmca_060,  /* 61 NEKOROBI M */
    yang_dmca_060,  /* 62 NEKOROBI L */
    yang_dmca_060,  /* 63 NEKOROBI SP */
    yang_dmca_064,  /* 64 OKIAGARI */
    yang_dmca_065,  /* 65 OKIAGARI F */
    yang_dmca_066,  /* 66 OKIAGARI B */
    yang_dmca_067,  /* 67 LOSE NO STAND */
    yang_dmca_068,  /* 68 LOSE SONABA */
    yang_dmca_068,  /* 69 LOSE KAGAMI */
    yang_dmca_070,  /* 70 PIYO */
    yang_dmca_071,  /* 71 UKEMI MOVE F */
    yang_dmca_072,  /* 72 UKEMI MOVE R */
    yang_dmca_073,  /* 73 SHIMEOTASARE */
    yang_dmca_074,  /* 74 TATI TOUKETU S */
    yang_dmca_075,  /* 75 TATI TOUKETU M */
    yang_dmca_076,  /* 76 TATI TOUKETU L */
    yang_dmca_076,  /* 77 TATI TOUKETU P */
    yang_dmca_078,  /* 78 KGM TOUKETU S */
    yang_dmca_079,  /* 79 KGM TOUKETU M */
    yang_dmca_080,  /* 80 KGM TOUKETU L */
    yang_dmca_080,  /* 81 KGM TOUKETU P */
    yang_dmca_082,  /* 82 TATI DENGEKI S */
    yang_dmca_083,  /* 83 TATI DENGEKI M */
    yang_dmca_084,  /* 84 TATI DENGEKI L */
    yang_dmca_084,  /* 85 TATI DENGEKI P */
    yang_dmca_082,  /* 86 KGM DENGEKI S */
    yang_dmca_083,  /* 87 KGM DENGEKI M */
    yang_dmca_084,  /* 88 KGM DENGEKI L */
    yang_dmca_084,  /* 89 KGM DENGEKI P */
    yang_dmca_090,  /* 90 OKIAGARI FRONT */
    yang_dmca_091,  /* 91 OKIAGARI REAR */
    yang_dmca_008,  /* 92 TATI MOE S */
    yang_dmca_009,  /* 93 TATI MOE M */
    yang_dmca_010,  /* 94 TATI MOE L */
    yang_dmca_010,  /* 95 TATI MOE SP */
    yang_dmca_096,  /* 96 no name */
    yang_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 yang_dmca_000_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yang_dmca_000[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x3C95, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3C96, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x3C93, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C91, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C90, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C90, 0, 86, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 yang_dmca_001_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yang_dmca_001[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x3C9C, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3C9D, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x3C9A, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C98, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C97, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C97, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 yang_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_002[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x3CA3, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CA4, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x3CA1, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C9F, 0, 88, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C9E, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C9E, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 yang_dmca_003_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 yang_dmca_003[160] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x3CA6, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x3CA7, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3CA5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 139, 0, 0, 0, 0, 0, 0x3CA5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 136, 0, 0, 0, 0, 0, 0x3C9A, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C98, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 7, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 yang_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_004[36] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C9B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 yang_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_006[44] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CA2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3CD0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CD1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 yang_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 642, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE2, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 yang_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE5, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 136, 642, 0, 0, 0, 0, 0x3CE5, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE6, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CE5, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE2, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 yang_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_010[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 137, 642, 0, 0, 0, 0, 0x3CE8, 0, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CE9, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CEA, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CEB, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CEC, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3CED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CEE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 yang_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_014[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 642, 0, 0, 0, 0, 0x3CE8, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE9, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CEA, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CEB, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3CF5, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CEC, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3CED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CEE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 yang_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_018[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CF1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 642, 0, 0, 0, 0, 0x3CF1, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CF2, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CF3, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CF4, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3CF5, 0, 256, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x3CEC, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x3CE1, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3CED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CEE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 yang_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_022[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D3C, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 136, 642, 0, 0, 0, 0, 0x3D39, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE6, 0, 254, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE5, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CE1, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3CE2, 0, 251, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 yang_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_025[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CF6, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 135, 642, 0, 0, 0, 0, 0x3CF7, 0, 260, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CF8, 0, 261, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CFA, 0, 260, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CFB, 0, 259, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 yang_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_026[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CF8, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 136, 642, 0, 0, 0, 0, 0x3CF8, 0, 260, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CF8, 0, 261, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CF9, 0, 262, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFA, 0, 260, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFB, 0, 259, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 yang_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_024[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D00, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 134, 642, 0, 0, 0, 0, 0x3D01, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D01, 0, 259, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D02, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D04, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D04, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 yang_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_029[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D05, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 136, 642, 0, 0, 0, 0, 0x3D05, 0, 259, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D07, 0, 260, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D06, 0, 260, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D01, 0, 259, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D02, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D04, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D04, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 yang_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D07, 0, 259, 0, 0, 0, 0, 0),
    L4(4, 138, 642, 0, 0, 0, 0, 0x3D08, 0, 260, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D09, 0, 261, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D09, 0, 261, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D0A, 0, 262, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D0B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CFA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CFB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 yang_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_034[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D37, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 138, 642, 0, 0, 0, 0, 0x3D37, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D38, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D39, 0, 251, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE6, 0, 254, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE5, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE2, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 yang_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_036[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D0A, 0, 262, 0, 0, 0, 0, 0),
    L4(1, 0, 643, 0, 0, 0, 0, 0x3D44, 0, 262, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D44, 0, 262, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D45, 0, 262, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 yang_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_048[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D10, 0, 263, 0, 0, 0, 0, 0),
    L4(1, 135, 642, 0, 0, 0, 0, 0x3D11, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D11, 0, 264, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D12, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D13, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 yang_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_049[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D17, 0, 263, 0, 0, 0, 0, 0),
    L4(1, 135, 642, 0, 0, 0, 0, 0x3D17, 0, 264, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D18, 0, 265, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D11, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D12, 0, 264, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D13, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 yang_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_050[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D18, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 138, 642, 0, 0, 0, 0, 0x3D1A, 0, 265, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D1B, 0, 266, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D1A, 0, 265, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D18, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D17, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D11, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D12, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3D13, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D1E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 yang_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D17, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D45, 0, 264, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 yang_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_060[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D2F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D2E, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D2F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D30, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 yang_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_064[132] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D71, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D72, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x3D73, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D74, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3D75, 0, 0, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D76, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D77, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D78, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 yang_dmca_065_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_065[280] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D71, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D72, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EFC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 128),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3EFE, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 yang_dmca_066_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_066[268] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D7A, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3D74, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3D75, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3D76, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D77, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D78, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 yang_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 yang_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_068[196] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x3CE0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x3CE4, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x3D60, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x3D61, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D62, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D63, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D64, 0, 216, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x3D67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D6A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D6B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D6C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3D6C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 yang_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D47, 0, 350, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D48, 0, 350, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D49, 0, 350, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D4A, 0, 350, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D4B, 0, 351, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D4C, 0, 351, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D4E, 0, 351, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 yang_dmca_071_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_071[268] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D71, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 1, 645, 0, 0, 0, 0, 0x3EF9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF9, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 12, 0, 0, 0, 0, 0, 0x3EFC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3EFE, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 yang_dmca_072_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_072[184] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 12, 0, 0, 0, 0, 0, 0x3D74, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D75, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3D75, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D76, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D77, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D78, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 yang_dmca_073_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_073[172] = {
    L6(2, 0, 641, 0, 0, 0, 0, 0x3D60, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x3D61, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D62, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3D63, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x3D64, 0, 372, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3D65, 0, 372, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 289, 0, 0, 0, 0, 0x3D67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D6A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x3D6B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D6C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3D6C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 yang_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_074[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE0, 0, 255, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3CE0, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3CE3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 yang_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE4, 0, 255, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3CE4, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3CE2, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 yang_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_076[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3CE7, 0, 255, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3CE7, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3CEE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 yang_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_078[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D10, 0, 263, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D10, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 yang_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_079[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D16, 0, 263, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D16, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3D13, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 yang_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_dmca_080[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D19, 0, 263, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D19, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3D13, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D14, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D15, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D1E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D1E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 yang_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 yang_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 yang_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CD9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 yang_dmca_090_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_090[280] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D71, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D72, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EFC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 128),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3EFE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 yang_dmca_091_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_091[268] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D7A, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D7C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EF2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x3EFB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D74, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D75, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3D76, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D77, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D78, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 yang_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_096[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 yang_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_dmca_097[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D32, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D32, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D32, 0, 17, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 17, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 17, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const yang_btca[37] = {
    yang_btca_000,  /* 0 AIR NORMAL */
    yang_btca_001,  /* 1 ASIBARAI SIRI */
    yang_btca_002,  /* 2 ASIB TUNNOMERI */
    yang_btca_003,  /* 3 NOKEZORI */
    yang_btca_004,  /* 4 KUNOJI */
    yang_btca_005,  /* 5 KIRIMOMI */
    yang_btca_006,  /* 6 UPPER */
    yang_btca_007,  /* 7 BODY UPPER */
    yang_btca_008,  /* 8 HARAYARARE */
    yang_btca_009,  /* 9 TATAKI AIR */
    yang_btca_010,  /* 10 TTKI V. AIR */
    yang_btca_011,  /* 11 HUMI ASIB */
    yang_btca_012,  /* 12 FACE */
    yang_btca_013,  /* 13 ASIB SIRI LOSE */
    yang_btca_014,  /* 14 ASIB TUN LOSE */
    yang_btca_015,  /* 15 DENKI */
    yang_btca_016,  /* 16 KUNOJI NOKE */
    yang_btca_017,  /* 17 BODY UPPER SP */
    yang_btca_018,  /* 18 HANEAGARI */
    yang_btca_019,  /* 19 TOUKETSU A */
    yang_btca_020,  /* 20 BODY SLAM */
    yang_btca_021,  /* 21 IPPONZEOI */
    yang_btca_022,  /* 22 TOMOE RYU */
    yang_btca_023,  /* 23 MONKEY FLIP */
    yang_btca_024,  /* 24 TOMOE ORO */
    yang_btca_025,  /* 25 SNAKE FANG */
    yang_btca_026,  /* 26 FLANKEN.S */
    yang_btca_027,  /* 27 KISHINRIKI */
    yang_btca_028,  /* 28 SPLASH.M */
    yang_btca_029,  /* 29 HARAIGOSHI */
    yang_btca_030,  /* 30 ALEX B.D */
    yang_btca_031,  /* 31 GILL */
    yang_btca_032,  /* 32 HANEKAERI HARA */
    yang_btca_033,  /* 33 S HANEAGARI */
    yang_btca_034,  /* 34 TATUMAKIZANKU */
    yang_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 yang_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_000[68] = {
    CMD(CM_JSR, 8, 56, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 642, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 yang_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D33, 0, 290, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 6, 0x3D34, 0, 291, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x3D35, 0, 292, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D36, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 yang_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_btca_002[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D40, 0, 294, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D41, 0, 295, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D42, 0, 296, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D43, 0, 297, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 yang_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_003[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 yang_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_004[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D07, 0, 306, 0, 0, 0, 0, 0),
    L4(4, 0, 643, 0, 0, 0, 6, 0x3D08, 0, 307, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D09, 0, 308, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D0A, 0, 308, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D46, 0, 309, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D46, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 yang_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_005[124] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D50, 0, 310, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D51, 0, 311, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D52, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D53, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D54, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D55, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D56, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D57, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D58, 0, 318, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D59, 0, 319, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D5A, 0, 320, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D5B, 0, 321, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D5B, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 yang_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_006[116] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D3C, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D39, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 yang_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_007[108] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D3C, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D39, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 yang_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_008[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 yang_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_009[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 yang_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_010[68] = {
    CMD(CM_RJA, 7, 8, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3CF6, 0, 324, 0, 0, 0, 0, 0),
    L4(4, 0, 643, 0, 0, 0, 0, 0x3CF7, 0, 324, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D44, 0, 325, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D45, 0, 326, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D46, 0, 309, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D46, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 yang_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yang_btca_011[52] = {
    CMD(CM_RJA, 7, 77, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D40, 0, 294, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D41, 0, 295, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D42, 0, 296, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D43, 0, 297, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 yang_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_012[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 yang_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 yang_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 yang_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 yang_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_015[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x3CD9, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CD9, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDA, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3CD9, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3CDB, 0, 327, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 yang_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_016[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D07, 0, 306, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D08, 0, 307, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D09, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D0A, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 yang_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_017[160] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 643, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D3D, 0, 329, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D3E, 0, 329, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 yang_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 643, 0, 0, 0, 0, 0x3D36, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D28, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x3D27, 0, 91, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x3D26, 0, 91, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x3D25, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x3D24, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 yang_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3CE7, 0, 328, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3CE7, 0, 328, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 yang_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_020[20] = {
    L4(250, 2, 0, 0, 0, 0, 0, 0x3D5B, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 yang_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_021[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D2F, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 yang_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_022[68] = {
    CMD(CM_RJA, 7, 5, 6), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D42, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D43, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED2, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 yang_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_023[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3ED0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 yang_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_024[28] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x3ED0, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 yang_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 188, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D28, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 yang_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_026[60] = {
    CMD(CM_RJA, 7, 5, 6), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D43, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 yang_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_027[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 yang_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_028[44] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 yang_btca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_btca_029[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D28, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D28, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 yang_btca_030_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_btca_030[108] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D3C, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D39, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 yang_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D33, 0, 290, 0, 0, 0, 0, 0),
    L4(6, 0, 643, 0, 0, 0, 0, 0x3D34, 0, 291, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3D35, 0, 292, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D36, 0, 293, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 yang_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 yang_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_033[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 643, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 yang_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_034[116] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x3D3A, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 643, 0, 0, 0, 0, 0x3D3B, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D3C, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D39, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D20, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D21, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D22, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 yang_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_btca_035[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x3D23, 0, 301, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D24, 0, 302, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D25, 0, 303, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x3D26, 0, 304, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x3D27, 0, 305, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 10 entries */
const u16* const yang_caca[11] = {
    yang_caca_000,  /* 0 CATCH 1 */
    yang_caca_001,  /* 1 CATCH 2 */
    yang_caca_002,  /* 2 CATCH 3 */
    yang_caca_003,  /* 3 CATCH 4 */
    yang_caca_004,  /* 4 CATCH 5 */
    yang_caca_005,  /* 5 CATCH 6 */
    yang_caca_006,  /* 6 CATCH 7 */
    yang_caca_007,  /* 7 CATCH 8 */
    yang_caca_008,  /* 8 CATCH 9 */
    yang_caca_009,  /* 9 CATCH 10 */
    0
};

/* script: 0 CATCH 1 */
const u16 yang_caca_000_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 yang_caca_000[304] = {
    CMD(CM_NGDA, 0, 19, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 264, 0, 0, 0, 0, 0x3EB2, -52, 0, 0, 0, 0, 0, 0, 16384, 600, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 16384, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB4, 0, 0, 0, 0, 0, 0, 0, 16384, 648, 0, 0, 0),
    L6(5, 0, 648, 0, 0, 0, 0, 0x3EB5, 0, 0, 0, 0, 0, 0, 0, 16384, 672, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3EB6, 0, 0, 0, 0, 0, 0, 0, 16384, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3EB7, 0, 0, 0, 0, 0, 0, 0, 16384, 720, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB8, 0, 0, 0, 0, 0, 0, 0, 16384, 744, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB9, 0, 0, 0, 0, 0, 0, 0, 16384, 768, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EBA, 0, 0, 0, 0, 0, 0, 0, 16384, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBB, 0, 0, 0, 0, 0, 0, 0, 16384, 816, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EBC, 0, 0, 0, 0, 0, 0, 0, 16384, 840, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EBD, 0, 0, 0, 0, 0, 0, 0, 16384, 864, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EBE, 0, 0, 0, 0, 0, 0, 0, 16384, 888, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EBF, 0, 0, 0, 0, 0, 0, 0, 16384, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC0, 0, 0, 0, 0, 0, 0, 0, 16384, 936, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC1, 0, 0, 0, 0, 0, 0, 0, 16384, 960, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC2, 0, 0, 0, 0, 0, 0, 0, 16384, 984, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC3, 0, 0, 0, 0, 0, 0, 0, 16384, 1008, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC4, 0, 0, 0, 0, 0, 0, 0, 16384, 1032, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC5, 0, 0, 0, 0, 0, 0, 0, 16384, 1056, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x3EC6, 0, 0, 0, 0, 0, 0, 0, 16384, 1080, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3EB1, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 yang_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yang_caca_001[328] = {
    CMD(CM_NGDA, 1542, 15, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x3EB2, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC7, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC8, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC9, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECA, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECB, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3ECC, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3ECD, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECE, 0, 0, 0, 0, 0, 0, 0, 0, 528, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 648, 0, 0, 0, 0, 0x3ECF, -92, 0, 0, 0, 0, 0, 0, 0, 552, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 9, 0, 0, 0, 0, 0, 0x3ED0, 0, 0, 0, 0, 0, 0, 0, 0, 576, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED4, 0, 0, 0, 0, 0, 22, 32, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED7, 0, 0, 0, 0, 0, 24, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x3ED9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 yang_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yang_caca_002[388] = {
    CMD(CM_NGDA, 1542, 37, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x3EB2, 0, 0, 0, 0, 0, 0, 0, 16384, 1104, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 16384, 1128, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB4, 0, 0, 0, 0, 0, 0, 0, 16384, 1152, 0, 0, 0),
    L6(5, 0, 648, 0, 0, 0, 0, 0x3EB5, 0, 0, 0, 0, 0, 0, 0, 16384, 1176, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3EB6, 0, 0, 0, 0, 0, 0, 0, 16384, 1200, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3EB7, 0, 0, 0, 0, 0, 0, 0, 16384, 1224, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB8, 0, 0, 0, 0, 0, 0, 0, 16384, 1248, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB9, 0, 0, 0, 0, 0, 0, 0, 16384, 1272, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EBA, 0, 0, 0, 0, 0, 0, 0, 16384, 1296, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBB, 0, 0, 0, 0, 0, 0, 0, 16384, 1320, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EBC, 0, 0, 0, 0, 0, 0, 0, 16384, 1344, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EBD, 0, 0, 0, 0, 0, 0, 0, 16384, 1368, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EBE, 0, 0, 0, 0, 0, 0, 0, 16384, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EBF, 0, 0, 0, 0, 0, 0, 0, 16384, 1416, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC0, 0, 0, 0, 0, 0, 0, 0, 16384, 1440, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC1, 0, 0, 0, 0, 0, 0, 0, 16384, 1464, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC2, 0, 0, 0, 0, 0, 0, 0, 16384, 1488, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC3, 0, 0, 0, 0, 0, 0, 0, 16384, 1512, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC9, 0, 0, 0, 0, 0, 24, 0, 16384, 1560, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECA, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECB, 0, 0, 0, 0, 0, 0, 0, 0, 1608, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3ECC, 0, 0, 0, 0, 0, 0, 0, 0, 1632, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECD, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3ECE, 0, 0, 0, 0, 0, 0, 0, 0, 1680, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 0, 0, 0, 0, 0, 0x3ECF, -92, 0, 0, 0, 0, 0, 0, 0, 1704, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 9, 0, 0, 0, 0, 0, 0x3ED0, 0, 0, 0, 0, 0, 0, 0, 0, 1776, 222, 0, 0),
    CMD(CM_JMP, 2, 1, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 yang_caca_003_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yang_caca_003[328] = {
    CMD(CM_NGDA, 1542, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x3EB2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F16, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 24, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 0, 12, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 6, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 7, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 2, 8, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IFLG, 1, 64, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EMHP, 2, 0, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 646, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 3, 0, 0x3F19, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 4, 0, 0x3F1A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 5, 0, 0x3F1B, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F19, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F18, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F17, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 yang_caca_004_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 yang_caca_004[304] = {
    CMD(CM_NGDA, 0, 19, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 264, 0, 0, 0, 0, 0x3EB2, -52, 0, 0, 0, 0, 0, 0, 16384, 600, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 16384, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB4, 0, 0, 0, 0, 0, 0, 0, 16384, 648, 0, 0, 0),
    L6(5, 0, 648, 0, 0, 0, 0, 0x3EB5, 0, 0, 0, 0, 0, 0, 0, 16384, 672, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x3EB6, 0, 0, 0, 0, 0, 0, 0, 16384, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3EB7, 0, 0, 0, 0, 0, 0, 0, 16384, 720, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB8, 0, 0, 0, 0, 0, 0, 0, 16384, 744, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB9, 0, 0, 0, 0, 0, 0, 0, 16384, 768, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EBA, 0, 0, 0, 0, 0, 0, 0, 16384, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBB, 0, 0, 0, 0, 0, 0, 0, 16384, 816, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBC, 0, 0, 0, 0, 0, 0, 0, 16384, 840, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBD, 0, 0, 0, 0, 0, 0, 0, 16384, 864, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EBE, 0, 0, 0, 0, 0, 0, 0, 16384, 888, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EBF, 0, 0, 0, 0, 0, 0, 0, 16384, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC0, 0, 0, 0, 0, 0, 0, 0, 16384, 936, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EC1, 0, 0, 0, 0, 0, 0, 0, 16384, 960, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EC2, 0, 0, 0, 0, 0, 0, 0, 16384, 984, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EC3, 0, 0, 0, 0, 0, 0, 0, 16384, 1008, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EC4, 0, 0, 0, 0, 0, 0, 0, 16384, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EC5, 0, 0, 0, 0, 0, 0, 0, 16384, 1056, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x3EC6, 0, 0, 0, 0, 0, 0, 0, 16384, 1080, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3EB1, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB3, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 yang_caca_005_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yang_caca_005[328] = {
    CMD(CM_NGDA, 1542, 15, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x3EB2, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 24, 0, 0, 336, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EC7, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EC8, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC9, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECA, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECB, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3ECC, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3ECD, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ECE, 0, 0, 0, 0, 0, 0, 0, 0, 528, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 648, 0, 0, 0, 0, 0x3ECF, -92, 0, 0, 0, 0, 0, 0, 0, 552, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 9, 0, 0, 0, 0, 0, 0x3ED0, 0, 0, 0, 0, 0, 0, 0, 0, 576, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED4, 0, 0, 0, 0, 0, 22, 32, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3ED6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED7, 0, 0, 0, 0, 0, 24, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x3ED9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x3ED9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 yang_caca_006_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yang_caca_006[136] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3C01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 648, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 3, 0, 0x3F19, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 4, 0, 0x3F1A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x3F1B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F19, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 yang_caca_007_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yang_caca_007[136] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3C01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 648, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 3, 0, 0x3F19, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 4, 0, 0x3F1A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x3F1B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F19, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 yang_caca_008_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yang_caca_008[136] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x3C01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 648, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 3, 0, 0x3F19, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 4, 0, 0x3F1A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x3F1B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F19, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F18, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F17, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 yang_caca_009_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yang_caca_009[380] = {
    CMD(CM_NGDA, 1542, 63, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 90, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x3EB2, 0, 0, 0, 0, 0, 0, 0, 0, 1800, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB3, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EC7, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC8, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 0, 0, 0),
    CMD(CM_NGEM, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EC9, 0, 0, 0, 0, 0, 0, 0, 0, 1848, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4092, 0, 0, 0, 0, 0, 0, 0, 0, 1872, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4093, 0, 0, 0, 0, 0, 0, 0, 0, 1896, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4094, 0, 0, 0, 0, 0, 0, 0, 0, 1920, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4095, 0, 0, 0, 0, 0, 0, 0, 0, 1944, 0, 0, 0),
    L6(2, 0, 646, 0, 0, 0, 0, 0x4096, 0, 0, 0, 0, 0, 0, 0, 0, 1968, 0, 0, 0),
    L6(4, 2, 0, 0, 0, 0, 0, 0x4097, -164, 0, 0, 0, 0, 0, 0, 0, 1992, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(12, 3, 0, 0, 0, 0, 0, 0x4098, 0, 0, 0, 0, 0, 0, 0, 0, 2016, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x4099, 0, 0, 0, 0, 0, 0, 0, 0, 2040, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x409A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x409B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x409C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x409D, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x409E, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x409F, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x40A0, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x40A1, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x40A2, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x40A3, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x40A4, 0x0000, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* caught scripts: 68 entries */
const u16* const yang_cuca[69] = {
    yang_cuca_000,  /* 0 ALEX ZUTUKI */
    yang_cuca_001,  /* 1 ALEX BODY S */
    yang_cuca_002,  /* 2 ALEX BACK D */
    yang_cuca_003,  /* 3 ALEX POWER B */
    yang_cuca_004,  /* 4 ALEX SLEEPER */
    yang_cuca_005,  /* 5 RYU SEOINAGE */
    yang_cuca_006,  /* 6 IBUKI */
    yang_cuca_007,  /* 7 DADLEY L B */
    yang_cuca_008,  /* 8 IBUKI KUBIORI */
    yang_cuca_009,  /* 9 NECRO S T */
    yang_cuca_010,  /* 10 RYU TOMOENAGE */
    yang_cuca_011,  /* 11 YUN HIZAGERI */
    yang_cuca_012,  /* 12 ORO KUBISIME */
    yang_cuca_013,  /* 13 NECRO G S */
    yang_cuca_014,  /* 14 DUDDLEY D S */
    yang_cuca_015,  /* 15 YUN MONKEY F */
    yang_cuca_016,  /* 16 ORO TOMOENAGE */
    yang_cuca_017,  /* 17 ORO NIOURIKI */
    yang_cuca_018,  /* 18 ORO GIGOKU G */
    yang_cuca_019,  /* 19 YUN */
    yang_cuca_020,  /* 20 NECRO SNAKE F */
    yang_cuca_021,  /* 21 NECRO F S */
    yang_cuca_022,  /* 22 IBUKI HARAIG */
    yang_cuca_023,  /* 23 GILL SPLASH M */
    yang_cuca_024,  /* 24 KEN HIZAGERI */
    yang_cuca_025,  /* 25 ORO KISINRIKI */
    yang_cuca_026,  /* 26 SEAN TACKLE */
    yang_cuca_027,  /* 27 ALEX HYPER B */
    yang_cuca_028,  /* 28 NECRO SLAM D */
    yang_cuca_029,  /* 29 ELENA ASINAGE */
    yang_cuca_030,  /* 30 GILL IMPACT C */
    yang_cuca_031,  /* 31 ALEX S H B */
    yang_cuca_032,  /* 32 ALEX F N D */
    yang_cuca_033,  /* 33 no name */
    yang_cuca_034,  /* 34 IBUKI */
    yang_cuca_035,  /* 35 IBUKI YOROI D */
    yang_cuca_036,  /* 36 no name */
    yang_cuca_037,  /* 37 MAWARIKOMI M F */
    yang_cuca_038,  /* 38 HUGO BODY S */
    yang_cuca_039,  /* 39 HUGO N G T */
    yang_cuca_040,  /* 40 HUGO M S P */
    yang_cuca_041,  /* 41 HUGO S D B B */
    yang_cuca_042,  /* 42 no name */
    yang_cuca_043,  /* 43 no name */
    yang_cuca_044,  /* 44 no name */
    yang_cuca_045,  /* 45 no name */
    yang_cuca_046,  /* 46 no name */
    yang_cuca_047,  /* 47 no name */
    yang_cuca_048,  /* 48 no name */
    yang_cuca_049,  /* 49 no name */
    yang_cuca_050,  /* 50 no name */
    yang_cuca_051,  /* 51 no name */
    yang_cuca_052,  /* 52 no name */
    yang_cuca_053,  /* 53 no name */
    yang_cuca_054,  /* 54 no name */
    yang_cuca_055,  /* 55 no name */
    yang_cuca_056,  /* 56 no name */
    yang_cuca_057,  /* 57 no name */
    yang_cuca_058,  /* 58 no name */
    yang_cuca_059,  /* 59 no name */
    yang_cuca_060,  /* 60 no name */
    yang_cuca_061,  /* 61 no name */
    yang_cuca_062,  /* 62 no name */
    yang_cuca_063,  /* 63 no name */
    yang_cuca_064,  /* 64 no name */
    yang_cuca_065,  /* 65 no name */
    yang_cuca_066,  /* 66 no name */
    yang_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 yang_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CF8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 yang_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D38),
    CMD(CM_RMJA, 3, 1, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D28),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 yang_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 yang_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D99),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D9B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3EC5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3EC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 yang_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3C),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D3A),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 yang_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D37),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CC7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D27),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 yang_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D8A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 yang_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D3B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 yang_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D50),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 yang_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D20),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 8, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 yang_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D38),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D35),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D41),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 yang_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D08),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 yang_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D20),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 yang_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 yang_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D09),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D09),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 yang_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D7A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D43),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 yang_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D9A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D99),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D26),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D46),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D45),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 yang_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D72),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 9),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 yang_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3EF8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 3, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 yang_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE9),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3C01),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 yang_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3C98),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3C9C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3C94),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3C95),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CB0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CB1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CB2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D24),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D26),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 yang_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C9C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D43),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 yang_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D26),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D27),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D27),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 yang_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 yang_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D09),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D09),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 yang_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D72),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D23),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 yang_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D46),
    L2(250, 3, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D32),
    L2(250, 3, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 yang_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_027[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3EC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 yang_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D24),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D24),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 yang_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D43),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D08),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D46),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 yang_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D3A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 78, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 79, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 yang_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF8),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CF8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 yang_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D09),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 yang_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF9),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 yang_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D39),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 yang_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D8A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3DCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 yang_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE8),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D31),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 yang_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_037[136] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D7A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D07),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x3D08),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 25, 2),
    CMD(CM_JMP, 6, 24, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 yang_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D43),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3CAA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3CA8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D43),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3CD2),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D28),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 yang_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 yang_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 yang_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D5B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D26),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 yang_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D08),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 yang_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 yang_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D5B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD2),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D32),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 yang_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CFA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 yang_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D24),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 yang_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3ECE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yang_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CF8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 yang_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D24),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2D),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yang_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D46),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D43),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D42),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 yang_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CEB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D37),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D37),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFB),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CE7),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 yang_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D46),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D35),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D41),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 yang_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D45),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D29),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D29),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 yang_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D52),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D54),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D3C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 78, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 79, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 yang_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D25),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D23),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D40),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x3CE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 yang_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x3CE4),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 9, 0x3D35),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 yang_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D37),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D37),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D0A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D44),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D38),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 yang_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D38),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D46),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D3D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 yang_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D22),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 yang_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3B),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3CE2),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 yang_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C78),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C77),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C76),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3C75),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D34),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D22),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 yang_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF3),
    CMD(CM_PA_X, 0, -1536, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF4),
    CMD(CM_PA_X, 0, 8448, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    CMD(CM_PA_X, 0, -2816, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF7),
    CMD(CM_PA_X, 0, 2304, 0),
    CMD(CM_PS_Y, 0, 0, 4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D42),
    CMD(CM_PA_X, 0, -3584, 0),
    CMD(CM_PS_Y, 0, 0, 32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D43),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 123),
    L2(250, 0, 0, 0, 2, 0, 0, 0x3D39),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3D2B),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 yang_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D07),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 643, 0, 0, 0, 0, 0x3D08),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 yang_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D3A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 yang_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x3CF5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D7A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x3D2F),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D43),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 yang_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D31),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D2E),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 yang_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CF7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D3C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3D20),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x3D23),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 262 entries */
const u16* const yang_atca[263] = {
    yang_atca_000,  /* 0 S PUNCH A */
    yang_atca_000,  /* 1 S PUNCH B */
    yang_atca_000,  /* 2 S PUNCH C */
    yang_atca_003,  /* 3 M PUNCH A */
    yang_atca_004,  /* 4 M PUNCH B */
    yang_atca_004,  /* 5 M PUNCH C */
    yang_atca_006,  /* 6 L PUNCH A */
    yang_atca_007,  /* 7 L PUNCH B */
    yang_atca_007,  /* 8 L PUNCH C */
    yang_atca_009,  /* 9 S KICK A */
    yang_atca_009,  /* 10 S KICK B */
    yang_atca_009,  /* 11 S KICK C */
    yang_atca_012,  /* 12 M KICK A */
    yang_atca_013,  /* 13 M KICK B */
    yang_atca_014,  /* 14 M KICK C */
    yang_atca_015,  /* 15 L KICK A */
    yang_atca_015,  /* 16 L KICK B */
    yang_atca_015,  /* 17 L KICK C */
    yang_atca_018,  /* 18 KAGAMI P A */
    yang_atca_018,  /* 19 KAGAMI P B */
    yang_atca_018,  /* 20 KAGAMI P C */
    yang_atca_021,  /* 21 KAGAMI P A */
    yang_atca_021,  /* 22 KAGAMI P B */
    yang_atca_021,  /* 23 KAGAMI P C */
    yang_atca_024,  /* 24 KAGAMI P A */
    yang_atca_024,  /* 25 KAGAMI P B */
    yang_atca_024,  /* 26 KAGAMI P C */
    yang_atca_027,  /* 27 KAGAMI K A */
    yang_atca_027,  /* 28 KAGAMI K B */
    yang_atca_027,  /* 29 KAGAMI K C */
    yang_atca_030,  /* 30 KAGAMI K A */
    yang_atca_030,  /* 31 KAGAMI K B */
    yang_atca_030,  /* 32 KAGAMI K C */
    yang_atca_033,  /* 33 KAGAMI K A */
    yang_atca_033,  /* 34 KAGAMI K B */
    yang_atca_033,  /* 35 KAGAMI K C */
    yang_atca_036,  /* 36 V JUMP P S A */
    yang_atca_036,  /* 37 V JUMP P S B */
    yang_atca_038,  /* 38 V JUMP P M A */
    yang_atca_038,  /* 39 V JUMP P M B */
    yang_atca_040,  /* 40 V JUMP P L A */
    yang_atca_040,  /* 41 V JUMP P L B */
    yang_atca_042,  /* 42 V JUMP K S A */
    yang_atca_042,  /* 43 V JUMP K S B */
    yang_atca_044,  /* 44 V JUMP K M A */
    yang_atca_044,  /* 45 V JUMP K M B */
    yang_atca_046,  /* 46 V JUMP K L A */
    yang_atca_046,  /* 47 V JUMP K L B */
    yang_atca_048,  /* 48 F JUMP P S A */
    yang_atca_048,  /* 49 F JUMP P S B */
    yang_atca_050,  /* 50 F JUMP P M A */
    yang_atca_050,  /* 51 F JUMP P M B */
    yang_atca_052,  /* 52 F JUMP P L A */
    yang_atca_052,  /* 53 F JUMP P L B */
    yang_atca_054,  /* 54 F JUMP K S A */
    yang_atca_055,  /* 55 F JUMP K S B */
    yang_atca_056,  /* 56 F JUMP K M A */
    yang_atca_057,  /* 57 F JUMP K M B */
    yang_atca_058,  /* 58 F JUMP K L A */
    yang_atca_059,  /* 59 F JUMP K L B */
    yang_atca_060,  /* 60 B JUMP P S A */
    yang_atca_060,  /* 61 B JUMP P S B */
    yang_atca_062,  /* 62 B JUMP P M A */
    yang_atca_062,  /* 63 B JUMP P M B */
    yang_atca_064,  /* 64 B JUMP P L A */
    yang_atca_064,  /* 65 B JUMP P L B */
    yang_atca_066,  /* 66 B JUMP K S A */
    yang_atca_066,  /* 67 B JUMP K S B */
    yang_atca_068,  /* 68 B JUMP K M A */
    yang_atca_068,  /* 69 B JUMP K M B */
    yang_atca_070,  /* 70 B JUMP K L A */
    yang_atca_070,  /* 71 B JUMP K L B */
    yang_atca_072,  /* 72 SP V JP S P A */
    yang_atca_072,  /* 73 SP V JP S P B */
    yang_atca_074,  /* 74 SP V JP M P A */
    yang_atca_074,  /* 75 SP V JP M P B */
    yang_atca_076,  /* 76 SP V JP L P A */
    yang_atca_076,  /* 77 SP V JP L P B */
    yang_atca_078,  /* 78 SP V JP S K A */
    yang_atca_078,  /* 79 SP V JP S K B */
    yang_atca_080,  /* 80 SP V JP M K A */
    yang_atca_080,  /* 81 SP V JP M K B */
    yang_atca_082,  /* 82 SP V JP L K A */
    yang_atca_082,  /* 83 SP V JP L K B */
    yang_atca_084,  /* 84 SP F JP S P A */
    yang_atca_084,  /* 85 SP F JP S P B */
    yang_atca_086,  /* 86 SP F JP M P A */
    yang_atca_086,  /* 87 SP F JP M P B */
    yang_atca_088,  /* 88 SP F JP L P A */
    yang_atca_088,  /* 89 SP F JP L P B */
    yang_atca_090,  /* 90 SP F JP S K A */
    yang_atca_091,  /* 91 SP F JP S K B */
    yang_atca_092,  /* 92 SP F JP M K A */
    yang_atca_093,  /* 93 SP F JP M K B */
    yang_atca_094,  /* 94 SP F JP L K A */
    yang_atca_095,  /* 95 SP F JP L K B */
    yang_atca_096,  /* 96 SP B JP S P A */
    yang_atca_096,  /* 97 SP B JP S P B */
    yang_atca_098,  /* 98 SP B JP M P A */
    yang_atca_098,  /* 99 SP B JP M P B */
    yang_atca_100,  /* 100 SP B JP L P A */
    yang_atca_100,  /* 101 SP B JP L P B */
    yang_atca_102,  /* 102 SP B JP S K A */
    yang_atca_102,  /* 103 SP B JP S K B */
    yang_atca_104,  /* 104 SP B JP M K A */
    yang_atca_104,  /* 105 SP B JP M K B */
    yang_atca_106,  /* 106 SP B JP L K A */
    yang_atca_106,  /* 107 SP B JP L K B */
    yang_atca_108,  /* 108 S V JP S P A */
    yang_atca_108,  /* 109 S V JP S P B */
    yang_atca_110,  /* 110 S V JP M P A */
    yang_atca_110,  /* 111 S V JP M P B */
    yang_atca_112,  /* 112 S V JP L P A */
    yang_atca_112,  /* 113 S V JP L P B */
    yang_atca_114,  /* 114 S V JP S K A */
    yang_atca_114,  /* 115 S V JP S K B */
    yang_atca_116,  /* 116 S V JP M K A */
    yang_atca_116,  /* 117 S V JP M K B */
    yang_atca_118,  /* 118 S V JP L K A */
    yang_atca_118,  /* 119 S V JP L K B */
    yang_atca_108,  /* 120 S F JP S P A */
    yang_atca_108,  /* 121 S F JP S P B */
    yang_atca_110,  /* 122 S F JP M P A */
    yang_atca_110,  /* 123 S F JP M P B */
    yang_atca_112,  /* 124 S F JP L P A */
    yang_atca_112,  /* 125 S F JP L P B */
    yang_atca_114,  /* 126 S F JP S K A */
    yang_atca_114,  /* 127 S F JP S K B */
    yang_atca_116,  /* 128 S F JP M K A */
    yang_atca_116,  /* 129 S F JP M K B */
    yang_atca_118,  /* 130 S F JP L K A */
    yang_atca_118,  /* 131 S F JP L K B */
    yang_atca_108,  /* 132 S B JP S P A */
    yang_atca_108,  /* 133 S B JP S P B */
    yang_atca_110,  /* 134 S B JP M P A */
    yang_atca_110,  /* 135 S B JP M P B */
    yang_atca_112,  /* 136 S B JP L P A */
    yang_atca_112,  /* 137 S B JP L P B */
    yang_atca_114,  /* 138 S B JP S K A */
    yang_atca_114,  /* 139 S B JP S K B */
    yang_atca_116,  /* 140 S B JP M K A */
    yang_atca_116,  /* 141 S B JP M K B */
    yang_atca_118,  /* 142 S B JP L K A */
    yang_atca_118,  /* 143 S B JP L K B */
    yang_atca_144,  /* 144 TUKAMIKAKARI A */
    yang_atca_145,  /* 145 TUKAMIKAKARI B */
    yang_atca_146,  /* 146 TUKAMIKAKARI C */
    yang_atca_145,  /* 147 TUKAMIKAKARI D */
    yang_atca_145,  /* 148 TUKAMIKAKARI E */
    yang_atca_145,  /* 149 TUKAMIKAKARI F */
    yang_atca_145,  /* 150 TUKAMI AIR A */
    yang_atca_145,  /* 151 TUKAMI AIR B */
    yang_atca_145,  /* 152 TUKAMI AIR C */
    yang_atca_145,  /* 153 TUKAMI AIR D */
    yang_atca_145,  /* 154 TUKAMI AIR E */
    yang_atca_145,  /* 155 TUKAMI AIR F */
    yang_atca_156,  /* 156 follow-up of F JUMP K M A */
    yang_atca_157,  /* 157 follow-up of KAGAMI K A */
    yang_atca_158,  /* 158 follow-up of M PUNCH A, M PUNCH B */
    yang_atca_159,  /* 159 follow-up of follow-up of M PUNCH A, M PUNCH B */
    yang_atca_160,  /* 160 follow-up of S KICK A */
    yang_atca_161,  /* 161 follow-up of follow-up of S KICK A */
    yang_atca_162,  /* 162 follow-up of follow-up of KAGAMI K A */
    yang_atca_159,  /* 163 no name */
    yang_atca_159,  /* 164 no name */
    yang_atca_159,  /* 165 no name */
    yang_atca_159,  /* 166 no name */
    yang_atca_159,  /* 167 no name */
    yang_atca_159,  /* 168 no name */
    yang_atca_159,  /* 169 no name */
    yang_atca_159,  /* 170 no name */
    yang_atca_159,  /* 171 no name */
    yang_atca_159,  /* 172 no name */
    yang_atca_159,  /* 173 no name */
    yang_atca_159,  /* 174 no name */
    yang_atca_159,  /* 175 no name */
    yang_atca_159,  /* 176 no name */
    yang_atca_159,  /* 177 no name */
    yang_atca_159,  /* 178 no name */
    yang_atca_159,  /* 179 no name */
    yang_atca_159,  /* 180 no name */
    yang_atca_159,  /* 181 no name */
    yang_atca_159,  /* 182 no name */
    yang_atca_159,  /* 183 no name */
    yang_atca_159,  /* 184 no name */
    yang_atca_159,  /* 185 no name */
    yang_atca_159,  /* 186 no name */
    yang_atca_159,  /* 187 no name */
    yang_atca_159,  /* 188 no name */
    yang_atca_159,  /* 189 no name */
    yang_atca_159,  /* 190 no name */
    yang_atca_159,  /* 191 no name */
    yang_atca_159,  /* 192 no name */
    yang_atca_159,  /* 193 no name */
    yang_atca_159,  /* 194 no name */
    yang_atca_159,  /* 195 no name */
    yang_atca_159,  /* 196 no name */
    yang_atca_159,  /* 197 no name */
    yang_atca_159,  /* 198 no name */
    yang_atca_159,  /* 199 no name */
    yang_atca_200,  /* 200 follow-up of ZANNEN 2 */
    yang_atca_200,  /* 201 follow-up of ZANNEN 3 */
    yang_atca_200,  /* 202 no name */
    yang_atca_203,  /* 203 follow-up of ZANNEN 4 */
    yang_atca_204,  /* 204 no name */
    yang_atca_204,  /* 205 follow-up of ZANNEN 5 */
    yang_atca_206,  /* 206 follow-up of JUDGMENT WAIT */
    yang_atca_206,  /* 207 no name */
    yang_atca_208,  /* 208 follow-up of ZANNEN 6 */
    yang_atca_209,  /* 209 follow-up of ZANNEN 7 */
    yang_atca_209,  /* 210 no name */
    yang_atca_209,  /* 211 no name */
    yang_atca_212,  /* 212 no name */
    yang_atca_212,  /* 213 follow-up of ZANNEN 8 */
    yang_atca_214,  /* 214 follow-up of JUDGMENT WAIT */
    yang_atca_215,  /* 215 no name */
    yang_atca_215,  /* 216 follow-up of WIN 1 */
    yang_atca_215,  /* 217 follow-up of JUDGMENT WAIT */
    yang_atca_218,  /* 218 follow-up of WIN 2 */
    yang_atca_218,  /* 219 no name */
    yang_atca_218,  /* 220 no name */
    yang_atca_221,  /* 221 follow-up of WIN 3 */
    yang_atca_221,  /* 222 no name */
    yang_atca_221,  /* 223 no name */
    yang_atca_224,  /* 224 follow-up of WIN 4 */
    yang_atca_224,  /* 225 no name */
    yang_atca_224,  /* 226 no name */
    yang_atca_227,  /* 227 follow-up of WIN 5 */
    yang_atca_227,  /* 228 no name */
    yang_atca_227,  /* 229 no name */
    yang_atca_230,  /* 230 follow-up of WIN 6 */
    yang_atca_230,  /* 231 no name */
    yang_atca_230,  /* 232 no name */
    yang_atca_233,  /* 233 follow-up of WIN 7 */
    yang_atca_233,  /* 234 no name */
    yang_atca_233,  /* 235 no name */
    yang_atca_236,  /* 236 follow-up of JUDGMENT LOSE */
    yang_atca_236,  /* 237 no name */
    yang_atca_238,  /* 238 follow-up of JUDGMENT LOSE */
    yang_atca_238,  /* 239 no name */
    yang_atca_240,  /* 240 follow-up of JUDGMENT LOSE */
    yang_atca_240,  /* 241 no name */
    yang_atca_242,  /* 242 follow-up of WAIT */
    yang_atca_242,  /* 243 no name */
    yang_atca_244,  /* 244 follow-up of AFRICA JUMP */
    yang_atca_244,  /* 245 no name */
    yang_atca_246,  /* 246 follow-up of AFRICA LAND */
    yang_atca_246,  /* 247 no name */
    yang_atca_248,  /* 248 follow-up of SEAN BALL HIT */
    yang_atca_248,  /* 249 no name */
    yang_atca_250,  /* 250 no name */
    yang_atca_250,  /* 251 no name */
    yang_atca_252,  /* 252 follow-up of BONUS WIN 1 */
    yang_atca_252,  /* 253 no name */
    yang_atca_254,  /* 254 follow-up of BONUS WIN 2 */
    yang_atca_255,  /* 255 follow-up of BONUS WIN 3 */
    yang_atca_256,  /* 256 follow-up of APPEAR USE */
    yang_atca_257,  /* 257 follow-up of APPEAR USE */
    yang_atca_258,  /* 258 follow-up of APPEAR USE */
    yang_atca_259,  /* 259 follow-up of APPEAR USE */
    yang_atca_260,  /* 260 follow-up of APPEAR USE */
    yang_atca_260,  /* 261 no name */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B, 2 S PUNCH C */
const u16 yang_atca_000_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 yang_atca_000[132] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D84, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x3D85, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D84, 0, 27, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x3D85, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D86, -6, 28, 0, 137, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D87, 0, 29, 0, 137, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D88, 0, 58, 0, 0, 112, 21, 5),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D85, 0, 27, 0, 0, 16, 0, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D84, 0, 27, 0, 0, 16, 0, 6),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3D83, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D82, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D81, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D80, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D80, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 yang_atca_003_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 yang_atca_003[84] = {
    L4(2, 0, 269, 0, 0, 0, 0, 0x3DD8, 0, 33, 0, 0, 0, 32, 169),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3DD9, 0, 33, 0, 0, 0, 32, 170),
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DC3, -8, 34, 2245, 134, 104, 32, 171),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3DC4, 0, 35, 2245, 128, 104, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DC5, 0, 36, 2245, 0, 104, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DC2, 0, 33, 0, 0, 0, 32, 172),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3DC1, 0, 33, 0, 0, 0, 32, 173),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DC0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3DC0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 yang_atca_004_head[4] = { HEAD(4, 0, 2, 9, 0, 1, 0) };
const u16 yang_atca_004[100] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D8D, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x3D8E, 0, 30, 0, 0, 0, 32, 21),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D8F, 0, 30, 0, 0, 0, 32, 22),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D90, -7, 31, 2245, 128, 8, 32, 23),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D92, 0, 136, 2245, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3D91, 0, 136, 2245, 0, 8, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3D91, 0, 137, 2245, 0, 8, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D93, 0, 138, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D94, 0, 138, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3D95, 0, 138, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 yang_atca_006_head[4] = { HEAD(4, 0, 4, 9, 0, 1, 0) };
const u16 yang_atca_006[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DC7, 0, 37, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DC8, 0, 37, 0, 0, 0, 0, 0),
    L4(1, 0, 645, 0, 0, 0, 0, 0x3DC9, 0, 37, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DCA, 0, 37, 0, 0, 0, 32, 57),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3DCB, 0, 37, 0, 0, 0, 32, 57),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DCC, -9, 38, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3DCC, 0, 38, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DCD, -41, 39, 0, 128, 0, 32, 57),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3DCE, 9, 40, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3DCF, 0, 41, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3DD0, 0, 41, 0, 0, 0, 32, 58),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3DD1, 0, 37, 0, 0, 0, 32, 58),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DD2, 0, 37, 0, 0, 0, 32, 58),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B, 8 L PUNCH C */
const u16 yang_atca_007_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 yang_atca_007[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DAE, 0, 48, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DAF, 0, 48, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DB0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(2, 0, 648, 0, 0, 0, 0, 0x3DB1, 0, 48, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DB2, 0, 48, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3DB3, 0, 48, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DB4, -10, 49, 0, 137, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3DB5, 0, 50, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x3DB6, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DB7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DB8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DB9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DBA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 382, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 yang_atca_009_head[4] = { HEAD(6, 0, 1, 8, 0, 1, 0) };
const u16 yang_atca_009[148] = {
    CMD(CM_RMJA, 4, 160, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3DE4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE5, -12, 56, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DE6, 12, 57, 2703, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3DE8, 0, 1, 0, 0, 0, 21, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3DEA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DEB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 yang_atca_012_head[4] = { HEAD(4, 0, 3, 13, 0, 1, 0) };
const u16 yang_atca_012[124] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DED, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3DEE, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x3DEF, 0, 282, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DF0, -1, 12, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DF0, 2, 13, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DF1, 2, 13, 0, 0, 1, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DF1, 0, 14, 0, 0, 1, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3DF2, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DF3, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3DF4, 0, 15, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DF5, 0, 59, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3DF6, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3DF7, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3DF8, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 yang_atca_013_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 yang_atca_013[256] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x40D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40D6, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D7, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x40D8, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x40D9, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x40DA, 0, 271, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x40DB, -2, 283, 0, 128, 0, 0, 0, 0, 0, 434, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40DC, 0, 284, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40DD, 0, 274, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40DE, 0, 274, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40DF, 0, 275, 0, 0, 0, 0, 0, 0, 0, 440, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E0, 0, 271, 0, 0, 0, 0, 0, 0, 0, 442, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E1, 0, 271, 0, 0, 0, 0, 0, 0, 0, 444, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 446, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 448, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x40E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 450, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x40E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 yang_atca_014_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 yang_atca_014[468] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 8, 0, 0, 0, 0, 0, 0x3DFA, 0, 98, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DFB, 0, 98, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DFC, 0, 99, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 1, 648, 0, 0, 0, 0, 0x3DFD, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DFE, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DFF, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E00, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E01, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 1, 0, 0, 0, 0x3E02, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x3E03, -18, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x3E04, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x3E04, 0, 146, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E05, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3E06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0005, 0x0E00, 0x0100, 0x0005, 0x0008, 0x002C, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0108, 0x0000, 0x0000, 0x3F9E,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x3F9F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x00FA, 0x0500, 0x0200, 0x0000, 0x0000, 0x3FA0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x00FA, 0x0000, 0x0200, 0x0000, 0x0000, 0x3FA1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x00FA, 0x0000, 0x0400, 0x2880, 0x0000, 0x3FA2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x00FC, 0x0000, 0x0100, 0x10E0, 0x0000, 0x3FA2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x00FC, 0x0000, 0x0200, 0x0000, 0x0000, 0x3FA3,
    L6(245, 152, 1536, 0, 0, 2224, 0, 0x0000, 0, 0, 0, 0, 254, 0, 0, 512, 0, 0, 63, 164),
    CMD(CM_RJA5, -32768, -29952, 0), 0x0000, 0x0000, 0x0100, 0x0000, 0x0100, 0x0000, 0x0000, 0x3FA4,
    CMD(CM_UJA5, -24576, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3FA5,
    CMD(CM_UJA5, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0004, 0x0000, 0x3FA6,
    CMD(CM_UJA5, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0004, 0x0000, 0x3FA7,
    CMD(CM_RJA5, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0004, 0x0000, 0x3FA8,
    CMD(CM_RJA5, -24576, 0, 0), 0x0000, 0x0000, 0x0100, 0x0000, 0x0300, 0x0000, 0x0000, 0x3FA9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0100, 0x0000, 0x0340, 0x0000, 0x0000, 0x3FAA,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3DF8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3DF9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0100, 0x0000, 0x0200, 0x0000, 0x0000, 0x3C41,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3C40,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3C3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x3C3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 yang_atca_015_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 yang_atca_015[244] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 8, 0, 0, 0, 0, 0, 0x407F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 466, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4080, 0, 1, 0, 0, 0, 0, 0, 0, 0, 468, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4081, 0, 1, 0, 0, 0, 0, 0, 0, 0, 470, 0, 0),
    L6(2, 0, 644, 0, 0, 0, 0, 0x4082, 0, 1, 0, 0, 0, 0, 0, 0, 0, 472, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x4083, 0, 1, 0, 0, 0, 0, 0, 0, 0, 474, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4084, -42, 276, 0, 128, 0, 0, 0, 0, 0, 476, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4085, 42, 277, 0, 0, 0, 0, 0, 0, 0, 478, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4086, 0, 278, 0, 0, 0, 21, 0, 0, 0, 480, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4087, 0, 278, 0, 0, 0, 0, 0, 0, 0, 482, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4088, 0, 278, 0, 0, 0, 0, 0, 0, 0, 484, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4089, 0, 279, 0, 0, 0, 0, 0, 0, 0, 486, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x408A, 0, 279, 0, 0, 0, 0, 0, 0, 0, 488, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x408B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 490, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x408C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 492, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x408D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 494, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x408E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 496, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x408F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4090, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4090, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 yang_atca_018_head[4] = { HEAD(4, 32, 0, 11, 0, 1, 0) };
const u16 yang_atca_018[188] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E32, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E32, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E33, -14, 207, 0, 137, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 208, 0, 137, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E35, 0, 209, 0, 0, 112, 21, 5),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E36, 0, 206, 0, 0, 16, 0, 5),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2002, 0x0B00, 0x0100,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E30, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3E32, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E33, -45, 93, 0, 134, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 94, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 63, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3E35, 0, 63, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3E36, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 yang_atca_021_head[4] = { HEAD(4, 32, 2, 11, 0, 1, 0) };
const u16 yang_atca_021[116] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x40FF, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4100, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4101, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4102, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4103, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4104, -45, 331, 0, 136, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4105, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4106, 0, 332, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4107, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4108, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4109, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x410A, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x410B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 yang_atca_024_head[4] = { HEAD(6, 32, 4, 13, 0, 2, 0) };
const u16 yang_atca_024[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE6, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 648, 0, 0, 0, 0, 0x3FE7, 0, 2, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x3FE8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FEA, -46, 64, 0, 128, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3FEB, 0, 65, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FEC, -47, 66, 0, 128, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FED, 0, 95, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FEE, 0, 96, 0, 0, 0, 21, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FEF, 0, 96, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FF0, 0, 96, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FF1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3FF2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FF3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FF4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FF5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3FF5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 yang_atca_027_head[4] = { HEAD(4, 32, 1, 9, 0, 1, 0) };
const u16 yang_atca_027[100] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E44, 0, 373, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x3E44, 0, 373, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E47, -15, 374, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E46, 0, 375, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E46, 0, 375, 0, 0, 112, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E44, 0, 373, 0, 0, 16, 0, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E43, 0, 373, 0, 0, 16, 0, 1),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3E42, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E41, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E40, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E40, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 yang_atca_030_head[4] = { HEAD(6, 32, 3, 14, 0, 1, 0) };
const u16 yang_atca_030[184] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FD8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FD9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3FDA, 0, 386, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FDB, 0, 386, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FDC, -48, 378, 0, 135, 96, 0, 0, 0, 0, 392, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FDD, 0, 379, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FDD, 0, 380, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FDE, 0, 387, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FDF, 0, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE0, 0, 377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3FE2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FE3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3FE4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 yang_atca_033_head[4] = { HEAD(6, 32, 5, 12, 0, 1, 0) };
const u16 yang_atca_033[256] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 646, 0, 0, 0, 0, 0x3E49, 0, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E49, 0, 381, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4A, 0, 381, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4B, 0, 381, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4C, 0, 381, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4D, 0, 381, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4E, 0, 382, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3E4F, 0, 382, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E50, -50, 383, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E51, 0, 382, 0, 0, 0, 21, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E52, 0, 382, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E53, 0, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E54, 0, 381, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E55, 0, 381, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E56, 0, 381, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E57, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E58, 0, 384, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E59, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E5A, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3E5B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 yang_atca_036_head[4] = { HEAD(4, 22, 0, 7, 0, 1, 0) };
const u16 yang_atca_036[116] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E60, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x3E61, 0, 139, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E62, -31, 141, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E63, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E64, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E65, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E66, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E67, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E68, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E69, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E6A, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 yang_atca_038_head[4] = { HEAD(4, 22, 2, 9, 0, 1, 0) };
const u16 yang_atca_038[116] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x3E70, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3E71, -32, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3E72, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3E73, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3E74, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3E74, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 yang_atca_040_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 0) };
const u16 yang_atca_040[180] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E78, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E79, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E7A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3E7D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7E, -33, 165, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E7F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E80, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E81, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E81, 0, 215, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E80, 0, 215, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E79, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E78, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 yang_atca_042_head[4] = { HEAD(4, 22, 1, 10, 0, 1, 0) };
const u16 yang_atca_042[156] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3E95, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E96, -34, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E97, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E99, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E95, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 yang_atca_044_head[4] = { HEAD(4, 20, 3, 12, 0, 1, 0) };
const u16 yang_atca_044[164] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x3FB0, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3FB1, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 6, 0x3FB2, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3FB3, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FB4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3FB5, -69, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FB6, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FB7, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FB8, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FB9, 0, 224, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x3FBA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 yang_atca_046_head[4] = { HEAD(4, 22, 5, 10, 0, 1, 0) };
const u16 yang_atca_046[124] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA0, -36, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3EA1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 yang_atca_048_head[4] = { HEAD(4, 20, 0, 8, 0, 1, 0) };
const u16 yang_atca_048[124] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E60, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 10, 0x3E61, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3E62, -65, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3E63, 0, 140, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E64, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E65, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E66, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E67, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E68, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E69, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E6A, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 yang_atca_050_head[4] = { HEAD(4, 20, 2, 10, 0, 1, 0) };
const u16 yang_atca_050[116] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 10, 0x3E70, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E71, -66, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3E72, 66, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3E73, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E74, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x3E74, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 yang_atca_052_head[4] = { HEAD(4, 20, 4, 11, 0, 1, 0) };
const u16 yang_atca_052[108] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3E6E, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3E71, -67, 142, 0, 136, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3E72, 0, 143, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3E73, 0, 143, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x3E74, 0, 143, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3E75, 0, 135, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A */
const u16 yang_atca_054_head[4] = { HEAD(4, 20, 1, 11, 0, 1, 0) };
const u16 yang_atca_054[156] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E95, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E96, -68, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E97, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E99, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E95, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 F JUMP K S B */
const u16 yang_atca_055_head[4] = { HEAD(4, 20, 1, 5, 0, 1, 43) };
const u16 yang_atca_055[84] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -71, 287, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 288, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 288, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A */
const u16 yang_atca_056_head[4] = { HEAD(4, 20, 3, 12, 0, 1, 0) };
const u16 yang_atca_056[172] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 7, 0x3FB0, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x3FB1, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 7, 0x3FB2, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x3FB3, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FB4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x3FB5, -69, 222, 2689, 128, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FB6, 0, 223, 2689, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FB7, 0, 223, 2689, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FB8, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FB9, 0, 224, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x3FBA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 F JUMP K M B */
const u16 yang_atca_057_head[4] = { HEAD(4, 20, 3, 5, 0, 1, 43) };
const u16 yang_atca_057[84] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(4, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -71, 180, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A */
const u16 yang_atca_058_head[4] = { HEAD(4, 20, 5, 11, 0, 1, 0) };
const u16 yang_atca_058[124] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA0, -36, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3EA1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 F JUMP K L B */
const u16 yang_atca_059_head[4] = { HEAD(4, 20, 5, 5, 0, 1, 43) };
const u16 yang_atca_059[84] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -71, 180, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 yang_atca_060_head[4] = { HEAD(2, 24, 0, 0, 0, 1, 0) };
const u16 yang_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 yang_atca_062_head[4] = { HEAD(2, 24, 2, 0, 0, 1, 0) };
const u16 yang_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 yang_atca_064_head[4] = { HEAD(2, 24, 4, 0, 0, 1, 0) };
const u16 yang_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 yang_atca_066_head[4] = { HEAD(2, 24, 1, 0, 0, 1, 0) };
const u16 yang_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 yang_atca_068_head[4] = { HEAD(2, 24, 3, 0, 0, 1, 0) };
const u16 yang_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 yang_atca_070_head[4] = { HEAD(2, 24, 5, 0, 0, 1, 0) };
const u16 yang_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 yang_atca_072_head[4] = { HEAD(2, 28, 0, 0, 0, 1, 0) };
const u16 yang_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 yang_atca_074_head[4] = { HEAD(2, 28, 2, 0, 0, 1, 0) };
const u16 yang_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 yang_atca_076_head[4] = { HEAD(2, 28, 4, 0, 0, 1, 0) };
const u16 yang_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 yang_atca_078_head[4] = { HEAD(2, 28, 1, 0, 0, 1, 0) };
const u16 yang_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 yang_atca_080_head[4] = { HEAD(2, 28, 3, 0, 0, 1, 0) };
const u16 yang_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 yang_atca_082_head[4] = { HEAD(2, 28, 5, 0, 0, 1, 0) };
const u16 yang_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 yang_atca_084_head[4] = { HEAD(2, 26, 0, 0, 0, 1, 0) };
const u16 yang_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 yang_atca_086_head[4] = { HEAD(2, 26, 2, 0, 0, 1, 0) };
const u16 yang_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 yang_atca_088_head[4] = { HEAD(2, 26, 4, 0, 0, 1, 0) };
const u16 yang_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A */
const u16 yang_atca_090_head[4] = { HEAD(2, 26, 1, 0, 0, 1, 0) };
const u16 yang_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 SP F JP S K B */
const u16 yang_atca_091_head[4] = { HEAD(2, 26, 1, 0, 0, 1, 0) };
const u16 yang_atca_091[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A */
const u16 yang_atca_092_head[4] = { HEAD(2, 26, 3, 0, 0, 1, 0) };
const u16 yang_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 93 SP F JP M K B */
const u16 yang_atca_093_head[4] = { HEAD(2, 26, 3, 0, 0, 1, 0) };
const u16 yang_atca_093[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A */
const u16 yang_atca_094_head[4] = { HEAD(2, 26, 5, 0, 0, 1, 0) };
const u16 yang_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 95 SP F JP L K B */
const u16 yang_atca_095_head[4] = { HEAD(2, 26, 5, 0, 0, 1, 0) };
const u16 yang_atca_095[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 yang_atca_096_head[4] = { HEAD(2, 30, 0, 0, 0, 1, 0) };
const u16 yang_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 yang_atca_098_head[4] = { HEAD(2, 30, 2, 0, 0, 1, 0) };
const u16 yang_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 yang_atca_100_head[4] = { HEAD(2, 30, 4, 0, 0, 1, 0) };
const u16 yang_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 yang_atca_102_head[4] = { HEAD(2, 30, 1, 0, 0, 1, 0) };
const u16 yang_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 yang_atca_104_head[4] = { HEAD(2, 30, 3, 0, 0, 1, 0) };
const u16 yang_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 yang_atca_106_head[4] = { HEAD(2, 30, 5, 0, 0, 1, 0) };
const u16 yang_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 yang_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 1, 0) };
const u16 yang_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 yang_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 1, 0) };
const u16 yang_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 yang_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 1, 0) };
const u16 yang_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 yang_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 1, 0) };
const u16 yang_atca_114[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 yang_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 1, 0) };
const u16 yang_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 yang_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 1, 0) };
const u16 yang_atca_118[224] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3584, 0, 256),
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3586, 0, 256),
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3588, 0, 256),
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3585, 0, 256),
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3587, 0, 256),
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3589, 0, 256),
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4608, 0, 256),
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4610, 0, 256),
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4612, 0, 256),
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4609, 0, 256),
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4611, 0, 256),
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4613, 0, 256),
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_DUMMY, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3C98),
    L2(240, 82, 1536, 0, 0, 0, 0, 0x0000),
    L2(1, 0, 268, 0, 0, 0, 0, 0x3C98),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x3DA3),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C98),
    CMD(CM_DUMMY, 8192, 0, 5376),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C97),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3C97),
    CMD(CM_DUMMY, 8192, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 yang_atca_146_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_atca_146[44] = {
    CMD(CM_CAFR, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C98, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C98, -64, 147, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 4, 144, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of F JUMP K M A */
const u16 yang_atca_156_head[4] = { HEAD(4, 20, 3, 5, 0, 1, 43) };
const u16 yang_atca_156[68] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(1, 20, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 1, 648, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -73, 248, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of KAGAMI K A */
const u16 yang_atca_157_head[4] = { HEAD(6, 32, 3, 14, 0, 1, 0) };
const u16 yang_atca_157[160] = {
    CMD(CM_RMJA, 4, 162, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FD9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x3FDA, 0, 386, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FDB, 0, 386, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FDC, -156, 378, 3074, 134, 104, 0, 0, 0, 0, 392, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FDD, 0, 379, 3074, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FDE, 0, 387, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FDF, 0, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FE0, 0, 377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FE1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3FE2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FE3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3FE4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of M PUNCH A, M PUNCH B */
const u16 yang_atca_158_head[4] = { HEAD(6, 0, 4, 12, 0, 2, 0) };
const u16 yang_atca_158[244] = {
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D97, -64, 1, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0),
    L6(1, 0, 646, 0, 0, 0, 0, 0x3D98, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D99, 0, 42, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3D9A, 0, 42, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D9B, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3D9C, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3D9E, 0, 43, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DA0, -11, 44, 2246, 140, 8, 0, 0, 0, 0, 354, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DA0, 0, 45, 2246, 140, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DA1, 0, 46, 2246, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x3DA2, 0, 46, 2246, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3DB7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 356, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3DB8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 358, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3DB9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3DBA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 362, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of follow-up of M PUNCH A, M PUNCH B, 163 no name, 164 no name, 165 no name ... */
const u16 yang_atca_159_head[4] = { HEAD(6, 0, 8, 9, 0, 1, 0) };
const u16 yang_atca_159[280] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 648, 0, 0, 0, 0, 0x3EE8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 366, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 366, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EEA, -76, 219, 0, 142, 64, 1, 16, 0, 0, 366, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EEB, 0, 219, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3EEB, 0, 218, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x3EEC, 0, 218, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EED, 0, 218, 0, 0, 0, 0, 0, 0, 0, 370, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3EEE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EEF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of S KICK A */
const u16 yang_atca_160_head[4] = { HEAD(6, 0, 3, 8, 0, 1, 0) };
const u16 yang_atca_160[232] = {
    CMD(CM_RMJA, 4, 161, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 269, 0, 0, 0, 0, 0x3DEF, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DEF, -77, 220, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF0, 0, 221, 3072, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF0, 0, 13, 3072, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF1, 2, 13, 3072, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF1, 0, 14, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF2, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF3, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF4, 0, 15, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF5, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF6, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3DF7, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 161 follow-up of follow-up of S KICK A */
const u16 yang_atca_161_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 yang_atca_161[304] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DEF, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x3FA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3FA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA3, -78, 195, 0, 142, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA4, 0, 196, 0, 142, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FA4, 0, 205, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA5, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x3FA6, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x3FA7, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x3FA8, 0, 197, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FA9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3FAA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 162 follow-up of follow-up of KAGAMI K A */
const u16 yang_atca_162_head[4] = { HEAD(6, 32, 5, 12, 0, 1, 0) };
const u16 yang_atca_162[292] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FDE, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FDF, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FE0, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FE1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 648, 0, 0, 0, 0, 0x3E49, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E49, 0, 71, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E4A, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4B, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4C, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4D, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4E, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3E4F, 0, 75, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E50, -157, 74, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E51, 0, 75, 0, 0, 0, 21, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E52, 0, 71, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E53, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E54, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E55, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E56, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E57, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E58, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E59, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E5A, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3E5B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 200 follow-up of ZANNEN 2, 201 follow-up of ZANNEN 3, 202 no name */
const u16 yang_atca_200_head[4] = { HEAD(4, 0, 32, 11, 0, 1, 0) };
const u16 yang_atca_200[92] = {
    L4(1, 0, 268, 0, 0, 0, 0, 0x3D85, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D86, -99, 28, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D87, 0, 29, 0, 0, 36, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3D88, 0, 58, 0, 0, 36, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D85, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D84, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D83, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D82, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D81, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3D80, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D80, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 203 follow-up of ZANNEN 4 */
const u16 yang_atca_203_head[4] = { HEAD(6, 0, 32, 8, 0, 1, 0) };
const u16 yang_atca_203[124] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DD7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3DD8, 0, 33, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DD9, 0, 33, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC3, -100, 34, 0, 0, 36, 0, 0, 0, 0, 140, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC4, 0, 35, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC5, 0, 36, 0, 0, 36, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3DC2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DC1, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DC0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3DC0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 204 no name, 205 follow-up of ZANNEN 5 */
const u16 yang_atca_204_head[4] = { HEAD(6, 0, 34, 9, 0, 1, 0) };
const u16 yang_atca_204[184] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D8D, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D8E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x3D8F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D90, -101, 31, 0, 0, 36, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D91, 0, 136, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D92, 0, 136, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D92, 0, 137, 0, 0, 36, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3D93, 0, 138, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D94, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D95, 0, 138, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3D96, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 206 follow-up of JUDGMENT WAIT, 207 no name */
const u16 yang_atca_206_head[4] = { HEAD(6, 0, 32, 9, 0, 2, 0) };
const u16 yang_atca_206[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC6, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 645, 0, 0, 0, 0, 0x3DC7, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC8, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DC9, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DCA, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3DCB, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DCC, -102, 38, 0, 0, 32, 0, 0, 0, 0, 0, 10, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DCC, 0, 38, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DCD, -103, 39, 0, 0, 36, 0, 0, 0, 0, 114, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DCE, 0, 40, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3DCF, 0, 41, 0, 0, 4, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DD0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DD1, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DD2, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 208 follow-up of ZANNEN 6 */
const u16 yang_atca_208_head[4] = { HEAD(6, 0, 32, 12, 0, 1, 0) };
const u16 yang_atca_208[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D97, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 646, 0, 0, 0, 0, 0x3D99, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D9A, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D9B, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3D9C, 0, 42, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DA0, -104, 44, 0, 0, 32, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DA1, 0, 45, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DA2, 0, 46, 0, 0, 32, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DB7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DB8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3DB9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DBA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 209 follow-up of ZANNEN 7, 210 no name, 211 no name */
const u16 yang_atca_209_head[4] = { HEAD(6, 0, 33, 8, 0, 1, 0) };
const u16 yang_atca_209[136] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x3DE4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE5, -105, 56, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE6, 0, 57, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3DE8, 0, 1, 0, 0, 4, 21, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DEA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DEB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 212 no name, 213 follow-up of ZANNEN 8 */
const u16 yang_atca_212_head[4] = { HEAD(6, 0, 33, 8, 0, 1, 0) };
const u16 yang_atca_212[160] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DED, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DEE, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x3DEF, 0, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF0, -106, 12, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3DF1, 2, 13, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3DF2, 0, 14, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF3, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF4, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF5, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF6, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3DF7, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3DF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 214 follow-up of JUDGMENT WAIT */
const u16 yang_atca_214_head[4] = { HEAD(6, 0, 33, 10, 0, 1, 0) };
const u16 yang_atca_214[184] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 8, 0, 0, 0, 0, 0, 0x3DFA, 0, 98, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DFB, 0, 98, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DFC, 0, 99, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 1, 648, 0, 0, 0, 0, 0x3DFD, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DFE, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DFF, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E00, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E01, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x3E02, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 1, 0, 0, 0, 0x3E03, -107, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x3E04, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E05, 0, 146, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3E06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 215 no name, 216 follow-up of WIN 1, 217 follow-up of JUDGMENT WAIT */
const u16 yang_atca_215_head[4] = { HEAD(6, 0, 33, 14, 0, 1, 0) };
const u16 yang_atca_215[196] = {
    L6(1, 8, 0, 0, 0, 0, 0, 0x3F9E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FA0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 644, 0, 0, 0, 0, 0x3FA1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x3FA2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA3, -108, 195, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FA4, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FA6, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x3FA7, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x3FA8, 0, 197, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 1, 0, 0, 0, 0x3FA9, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3FAA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3DF8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3DF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 218 follow-up of WIN 2, 219 no name, 220 no name */
const u16 yang_atca_218_head[4] = { HEAD(4, 32, 32, 11, 0, 1, 0) };
const u16 yang_atca_218[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E31, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E33, -109, 61, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 62, 0, 0, 36, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3E35, 0, 63, 0, 0, 36, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E36, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 221 follow-up of WIN 3, 222 no name, 223 no name */
const u16 yang_atca_221_head[4] = { HEAD(4, 32, 32, 11, 0, 1, 0) };
const u16 yang_atca_221[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E30, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3E32, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E33, -110, 93, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 94, 0, 0, 36, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3E35, 0, 63, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E36, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 224 follow-up of WIN 4, 225 no name, 226 no name */
const u16 yang_atca_224_head[4] = { HEAD(4, 32, 32, 12, 0, 2, 0) };
const u16 yang_atca_224[132] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E38, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E39, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3E3A, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E3B, -111, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E3C, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E3D, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E3E, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E3F, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E31, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E32, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E33, -112, 95, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E34, 0, 96, 0, 0, 36, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x3E35, 0, 66, 0, 0, 36, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E36, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E37, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 227 follow-up of WIN 5, 228 no name, 229 no name */
const u16 yang_atca_227_head[4] = { HEAD(4, 32, 33, 9, 0, 1, 0) };
const u16 yang_atca_227[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E44, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E44, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E47, -113, 68, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E46, 0, 69, 0, 0, 36, 21, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3E44, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E42, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E41, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E40, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3E40, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 230 follow-up of WIN 6, 231 no name, 232 no name */
const u16 yang_atca_230_head[4] = { HEAD(4, 32, 33, 11, 0, 1, 0) };
const u16 yang_atca_230[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x4010, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x4012, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4013, 0, 67, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4014, -48, 68, 0, 134, 36, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4015, 0, 69, 0, 134, 36, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4016, 0, 69, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x4017, 0, 70, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4018, 0, 67, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4019, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x401A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x401B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x401C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 233 follow-up of WIN 7, 234 no name, 235 no name */
const u16 yang_atca_233_head[4] = { HEAD(6, 32, 33, 12, 0, 1, 0) };
const u16 yang_atca_233[184] = {
    L6(1, 0, 648, 0, 0, 0, 0, 0x3E48, 0, 71, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E49, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4A, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x3E4C, 0, 71, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E4F, 0, 72, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E50, -115, 74, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E51, 85, 75, 0, 0, 0, 21, 0, 0, 0, 124, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x3E52, 0, 72, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E53, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3E54, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E57, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E58, 0, 71, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E59, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E5A, 0, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3E5B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 236 follow-up of JUDGMENT LOSE, 237 no name */
const u16 yang_atca_236_head[4] = { HEAD(4, 22, 32, 7, 0, 1, 0) };
const u16 yang_atca_236[108] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E60, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x3E61, 0, 139, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E62, -116, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E63, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E64, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E65, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E66, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E67, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E68, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E69, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E6A, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 238 follow-up of JUDGMENT LOSE, 239 no name */
const u16 yang_atca_238_head[4] = { HEAD(4, 22, 34, 9, 0, 1, 0) };
const u16 yang_atca_238[108] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 12, 0x3E70, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E71, -117, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E72, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E73, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 240 follow-up of JUDGMENT LOSE, 241 no name */
const u16 yang_atca_240_head[4] = { HEAD(4, 22, 36, 12, 0, 1, 0) };
const u16 yang_atca_240[164] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E78, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E79, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E7A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x3E7D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7E, -118, 165, 0, 138, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E7F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E80, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E81, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E81, 0, 215, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E80, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E7A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E79, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E78, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 242 follow-up of WAIT, 243 no name */
const u16 yang_atca_242_head[4] = { HEAD(4, 22, 33, 10, 0, 1, 0) };
const u16 yang_atca_242[148] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x3E95, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E96, -119, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E97, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E99, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E95, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 244 follow-up of AFRICA JUMP, 245 no name */
const u16 yang_atca_244_head[4] = { HEAD(4, 20, 35, 12, 0, 1, 0) };
const u16 yang_atca_244[156] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB0, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB1, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x3FB2, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB3, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB4, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB5, -69, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB6, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB7, 0, 223, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB8, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB9, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FBA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 246 follow-up of AFRICA LAND, 247 no name */
const u16 yang_atca_246_head[4] = { HEAD(4, 22, 37, 10, 0, 1, 0) };
const u16 yang_atca_246[116] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA0, -121, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3EA1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 248 follow-up of SEAN BALL HIT, 249 no name */
const u16 yang_atca_248_head[4] = { HEAD(4, 20, 32, 8, 0, 1, 0) };
const u16 yang_atca_248[116] = {
    CMD(CM_RMJA, 4, 260, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E60, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x3E61, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E62, -122, 140, 2304, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E63, 0, 140, 2304, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E64, 0, 140, 2304, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E65, 0, 140, 2304, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E66, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E67, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E68, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E69, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E6A, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 250 no name, 251 no name */
const u16 yang_atca_250_head[4] = { HEAD(4, 20, 34, 10, 0, 1, 0) };
const u16 yang_atca_250[108] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 12, 0x3E70, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E71, -123, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E72, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E73, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 252 follow-up of BONUS WIN 1, 253 no name */
const u16 yang_atca_252_head[4] = { HEAD(4, 20, 36, 11, 0, 1, 0) };
const u16 yang_atca_252[100] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E6E, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 12, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E71, -124, 142, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E72, 0, 143, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E73, 0, 143, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 143, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E75, 0, 135, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 254 follow-up of BONUS WIN 2 */
const u16 yang_atca_254_head[4] = { HEAD(4, 20, 33, 11, 0, 1, 0) };
const u16 yang_atca_254[148] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x3E95, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E96, -125, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E97, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E99, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E98, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E95, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E94, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E93, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 255 follow-up of BONUS WIN 3 */
const u16 yang_atca_255_head[4] = { HEAD(4, 20, 33, 5, 0, 1, 43) };
const u16 yang_atca_255[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 256 follow-up of APPEAR USE */
const u16 yang_atca_256_head[4] = { HEAD(4, 20, 35, 12, 0, 1, 0) };
const u16 yang_atca_256[156] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB0, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB1, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x3FB2, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x3FB3, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB4, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB5, -69, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB6, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB7, 0, 223, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB8, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FB9, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x3FBA, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C78, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C79, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C7A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 257 follow-up of APPEAR USE */
const u16 yang_atca_257_head[4] = { HEAD(4, 20, 35, 5, 0, 1, 43) };
const u16 yang_atca_257[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 258 follow-up of APPEAR USE */
const u16 yang_atca_258_head[4] = { HEAD(4, 20, 37, 11, 0, 1, 0) };
const u16 yang_atca_258[116] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA0, -127, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3EA1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3EA2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 259 follow-up of APPEAR USE */
const u16 yang_atca_259_head[4] = { HEAD(4, 20, 37, 5, 0, 1, 43) };
const u16 yang_atca_259[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 647, 0, 0, 0, 0, 0x3F0B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x3F0C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F0F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F10, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F11, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 260 follow-up of APPEAR USE, 261 no name */
const u16 yang_atca_260_head[4] = { HEAD(6, 20, 33, 13, 0, 1, 0) };
const u16 yang_atca_260[280] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F23, 0, 116, 0, 0, 0, 0, 0, 0, 0, 258, 0, 0),
    L6(1, 0, 648, 0, 0, 0, 0, 0x3F24, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F25, -129, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F26, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 648, 0, 0, 0, 0, 0x3F27, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F28, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F29, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F2A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F2B, -130, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F2C, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F2D, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F2E, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F2F, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F30, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F31, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C67, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C6B, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C6C, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A */
const u16 yang_atca_144_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_atca_144[124] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB0, -63, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EB2, 0, 280, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 yang_atca_145_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_atca_145[124] = {
    CMD(CM_CAFR, 2, 4, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 4, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EB0, -63, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EB2, 0, 280, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX yang_olc_ix_table[20] = {
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
};

const OVERLAP_PARTS yang_overlap_char_tbl[20] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 15834 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 15835 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 15836 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 15837 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 15838 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 6, 39062 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 7, 39063 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 8, 39064 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 9, 39065 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 10, 39066 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 11, 39067 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 12, 39068 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 13, 39069 },
    { -47, 60, 0, 5, 2, 1, 255, 0, 0, 14, 39070 },
    { -38, 50, 0, 5, 2, 3, 255, 0, 0, 15, 39190 },
    { -38, 50, 0, 5, 2, 3, 255, 0, 0, 16, 39191 },
    { -38, 50, 0, 5, 2, 3, 255, 0, 0, 17, 39192 },
    { -38, 50, 0, 5, 2, 3, 255, 0, 0, 18, 39193 },
    { -38, 50, 0, 5, 2, 3, 255, 0, 0, 19, 39194 },
};

const CatchTable yang_rival_catch_tbl[2040] = {
    { -54, 0, 1, 1, 1 },
    { -55, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -60, -7, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -47, 0, 1, 1, 1 },
    { -45, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -42, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -36, 0, 1, 1, 2 },
    { -39, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -65, -7, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -51, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -36, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -47, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -39, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 3 },
    { -37, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -47, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -58, -7, 1, 1, 3 },
    { -48, 2, 1, 1, 3 },
    { -46, 2, 1, 1, 3 },
    { -46, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -44, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -36, 0, 1, 1, 4 },
    { -35, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -35, 0, 1, 1, 4 },
    { -46, 1, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { -58, -7, 1, 1, 4 },
    { -45, 2, 1, 1, 4 },
    { -46, 2, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -35, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -34, 0, 1, 1, 5 },
    { -31, 0, 1, 1, 5 },
    { -33, 0, 1, 1, 5 },
    { -30, 0, 1, 1, 5 },
    { -46, 1, 1, 1, 5 },
    { -58, 0, 1, 1, 5 },
    { -57, -7, 1, 1, 5 },
    { -42, 2, 1, 1, 5 },
    { -40, 2, 1, 1, 5 },
    { -43, 0, 1, 1, 5 },
    { -30, 0, 1, 1, 5 },
    { -33, 0, 1, 1, 5 },
    { -33, 0, 1, 1, 5 },
    { -34, 0, 1, 1, 5 },
    { -33, 0, 1, 1, 5 },
    { -33, 0, 1, 1, 5 },
    { -56, 0, 1, 1, 5 },
    { -42, 0, 1, 1, 5 },
    { -43, 0, 1, 1, 5 },
    { -44, 0, 1, 1, 5 },
    { -46, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -32, 0, 1, 1, 6 },
    { -28, 2, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -27, 0, 1, 1, 6 },
    { -42, 0, 1, 1, 6 },
    { -53, 0, 1, 1, 6 },
    { -52, -7, 1, 1, 6 },
    { -39, 2, 1, 1, 6 },
    { -36, 2, 1, 1, 6 },
    { -41, 0, 1, 1, 6 },
    { -27, 0, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -32, 0, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -42, -5, 1, 1, 6 },
    { -47, 0, 1, 1, 6 },
    { -53, 0, 1, 1, 6 },
    { -45, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -45, -19, 1, 1, 7 },
    { -28, 4, 1, 1, 7 },
    { -7, 2, 1, 1, 7 },
    { -17, 3, 1, 1, 7 },
    { -22, 2, 1, 1, 7 },
    { -38, 0, 1, 1, 7 },
    { -56, -20, 1, 1, 7 },
    { -18, 1, 1, 1, 7 },
    { -44, 2, 1, 1, 7 },
    { -51, 0, 1, 1, 7 },
    { -17, 3, 1, 1, 7 },
    { -7, 2, 1, 1, 7 },
    { -7, 2, 1, 1, 7 },
    { -45, -19, 1, 1, 7 },
    { -7, 2, 1, 1, 7 },
    { -7, 2, 1, 1, 7 },
    { -29, 3, 1, 1, 7 },
    { -52, 9, 1, 1, 7 },
    { -49, -6, 2, 1, 7 },
    { -22, 1, 2, 1, 7 },
    { -36, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -45, -21, 1, 1, 8 },
    { -31, 0, 1, 1, 8 },
    { -29, 10, 1, 1, 8 },
    { -13, 8, 1, 1, 8 },
    { -25, 6, 1, 1, 8 },
    { -21, 0, 1, 1, 8 },
    { -59, -7, 1, 1, 8 },
    { -27, 8, 1, 1, 8 },
    { -44, 8, 1, 1, 8 },
    { -35, 5, 1, 1, 8 },
    { -13, 8, 1, 1, 8 },
    { -29, 10, 1, 1, 8 },
    { -29, 10, 1, 1, 8 },
    { -45, -21, 1, 1, 8 },
    { -29, 10, 1, 1, 8 },
    { -29, 10, 1, 1, 8 },
    { -35, 6, 1, 1, 8 },
    { -48, 7, 1, 1, 8 },
    { -51, -7, 2, 1, 8 },
    { -19, 2, 2, 1, 8 },
    { -44, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -64, -18, 1, 1, 9 },
    { -48, 7, 1, 1, 9 },
    { -49, 14, 1, 1, 9 },
    { -28, 15, 1, 1, 9 },
    { -41, 9, 1, 1, 9 },
    { -44, 0, 1, 1, 9 },
    { -67, -18, 1, 1, 9 },
    { -46, 6, 1, 1, 9 },
    { -64, 12, 1, 1, 9 },
    { -28, 5, 1, 1, 9 },
    { -28, 15, 1, 1, 9 },
    { -49, 14, 1, 1, 9 },
    { -49, 14, 1, 1, 9 },
    { -64, -18, 1, 1, 9 },
    { -49, 14, 1, 1, 9 },
    { -49, 14, 1, 1, 9 },
    { -38, 0, 1, 1, 9 },
    { -47, 0, 1, 1, 9 },
    { -41, -4, 1, 1, 9 },
    { -59, 1, 1, 1, 9 },
    { -46, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -70, -10, 1, 1, 10 },
    { -58, 3, 1, 1, 10 },
    { -53, 14, 1, 1, 10 },
    { -41, 5, 1, 1, 10 },
    { -45, 8, 1, 1, 10 },
    { -52, 0, 1, 1, 10 },
    { -68, -25, 1, 1, 10 },
    { -52, -3, 1, 1, 10 },
    { -52, 2, 1, 1, 10 },
    { -57, 9, 1, 1, 10 },
    { -41, 5, 1, 1, 10 },
    { -53, 14, 1, 1, 10 },
    { -53, 14, 1, 1, 10 },
    { -70, -10, 1, 1, 10 },
    { -53, 14, 1, 1, 10 },
    { -53, 14, 1, 1, 10 },
    { -38, 0, 1, 1, 10 },
    { -43, 0, 1, 1, 10 },
    { -41, 0, 1, 1, 10 },
    { -58, 1, 1, 1, 10 },
    { -46, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -36, 0, 1, 1, 11 },
    { -41, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -30, 0, 1, 1, 11 },
    { -48, 0, 1, 1, 11 },
    { -52, 0, 1, 1, 11 },
    { -59, -6, 1, 1, 11 },
    { -47, 2, 1, 1, 11 },
    { -52, 2, 1, 1, 11 },
    { -35, 0, 1, 1, 11 },
    { -30, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -36, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 11 },
    { -38, 0, 1, 1, 11 },
    { -44, 0, 1, 1, 11 },
    { -46, 0, 1, 1, 11 },
    { -34, 0, 1, 1, 11 },
    { -46, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { -45, 1, 1, 1, 12 },
    { -31, 0, 1, 1, 12 },
    { -29, 10, 1, 1, 12 },
    { -13, 8, 1, 1, 12 },
    { -25, 6, 1, 1, 12 },
    { -21, 1, 1, 1, 12 },
    { -58, -7, 1, 1, 12 },
    { -27, 8, 1, 1, 12 },
    { -44, 8, 1, 1, 12 },
    { -28, 5, 1, 1, 12 },
    { -13, 8, 1, 1, 12 },
    { -29, 10, 1, 1, 12 },
    { -29, 10, 1, 1, 12 },
    { -45, 1, 1, 1, 12 },
    { -29, 10, 1, 1, 12 },
    { -29, 10, 1, 1, 12 },
    { -48, 0, 1, 1, 12 },
    { -39, 0, 1, 1, 12 },
    { -46, 0, 1, 1, 12 },
    { -48, 0, 1, 1, 12 },
    { -36, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -60, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -83, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -47, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -65, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -52, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -45, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -52, 0, 1, 1, 2 },
    { -49, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -54, 0, 1, 1, 3 },
    { -59, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -61, 0, 1, 1, 3 },
    { -54, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -74, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -54, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -40, 0, 1, 1, 3 },
    { -45, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -38, -8, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -54, 0, 1, 1, 4 },
    { -59, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -55, 0, 1, 1, 4 },
    { -61, 0, 1, 1, 4 },
    { -53, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -51, 0, 1, 1, 4 },
    { -73, 0, 1, 1, 4 },
    { -55, 0, 1, 1, 4 },
    { -39, 0, 2, 1, 4 },
    { -39, 0, 2, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -45, 0, 1, 1, 4 },
    { -44, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -54, -16, 1, 1, 5 },
    { -55, -12, 1, 1, 5 },
    { -35, -12, 1, 1, 5 },
    { -51, -11, 1, 1, 5 },
    { -55, -12, 1, 1, 5 },
    { -51, -15, 1, 1, 5 },
    { -42, -11, 1, 1, 5 },
    { -47, -12, 1, 1, 5 },
    { -47, -12, 1, 1, 5 },
    { -72, -7, 1, 1, 5 },
    { -51, -11, 1, 1, 5 },
    { -35, -12, 2, 1, 5 },
    { -35, -12, 2, 1, 5 },
    { -54, -16, 1, 1, 5 },
    { -35, -12, 1, 1, 5 },
    { -35, -12, 1, 1, 5 },
    { -41, 0, 1, 1, 5 },
    { -49, 0, 1, 1, 5 },
    { -46, -23, 1, 1, 5 },
    { -36, -8, 1, 1, 5 },
    { -36, -16, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -32, -49, 1, 1, 6 },
    { -49, -51, 1, 1, 6 },
    { -44, -44, 1, 1, 6 },
    { -47, -43, 1, 1, 6 },
    { -51, -44, 1, 1, 6 },
    { -45, -48, 1, 1, 6 },
    { -42, -40, 1, 1, 6 },
    { -43, -44, 1, 1, 6 },
    { -42, -44, 1, 1, 6 },
    { -67, -39, 1, 1, 6 },
    { -47, -43, 1, 1, 6 },
    { -44, -44, 1, 1, 6 },
    { -44, -44, 1, 1, 6 },
    { -32, -49, 1, 1, 6 },
    { -44, -44, 1, 1, 6 },
    { -44, -44, 1, 1, 6 },
    { -32, -44, 1, 1, 6 },
    { -45, -29, 1, 1, 6 },
    { -39, -64, 1, 1, 6 },
    { -41, -48, 1, 1, 6 },
    { -40, -44, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -41, -46, 1, 1, 7 },
    { -57, -51, 1, 1, 7 },
    { -51, -44, 1, 1, 7 },
    { -53, -42, 1, 1, 7 },
    { -68, -38, 1, 1, 7 },
    { -53, -48, 1, 1, 7 },
    { -49, -42, 1, 1, 7 },
    { -51, -43, 1, 1, 7 },
    { -52, -44, 1, 1, 7 },
    { -75, -32, 1, 1, 7 },
    { -53, -42, 1, 1, 7 },
    { -15, -42, 1, 1, 7 },
    { -15, -42, 1, 1, 7 },
    { -41, -46, 1, 1, 7 },
    { -51, -44, 1, 1, 7 },
    { -51, -44, 1, 1, 7 },
    { -37, -44, 1, 1, 7 },
    { -49, -28, 1, 1, 7 },
    { -44, -69, 1, 1, 7 },
    { -47, -51, 1, 1, 7 },
    { -40, -50, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -47, -44, 1, 1, 8 },
    { -62, -43, 1, 1, 8 },
    { -52, -43, 1, 1, 8 },
    { -55, -41, 1, 1, 8 },
    { -70, -38, 1, 1, 8 },
    { -39, -46, 1, 1, 8 },
    { -52, -39, 1, 1, 8 },
    { -52, -42, 1, 1, 8 },
    { -38, -41, 1, 1, 8 },
    { -80, -29, 1, 1, 8 },
    { -55, -41, 1, 1, 8 },
    { -52, -43, 1, 1, 8 },
    { -52, -43, 1, 1, 8 },
    { -47, -44, 1, 1, 8 },
    { -52, -43, 1, 1, 8 },
    { -52, -43, 1, 1, 8 },
    { -64, -48, 1, 1, 8 },
    { -40, -29, 1, 1, 8 },
    { -51, -70, 1, 1, 8 },
    { -47, -51, 1, 1, 8 },
    { -54, -36, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -45, -38, 1, 1, 9 },
    { -54, -35, 1, 1, 9 },
    { -72, -27, 1, 1, 9 },
    { -48, -21, 1, 1, 9 },
    { -42, -31, 1, 1, 9 },
    { -42, -28, 1, 1, 9 },
    { -37, -30, 1, 1, 9 },
    { -53, -22, 1, 1, 9 },
    { -40, -25, 1, 1, 9 },
    { -35, -25, 1, 1, 9 },
    { -48, -21, 1, 1, 9 },
    { -72, -27, 1, 1, 9 },
    { -72, -27, 1, 1, 9 },
    { -45, -38, 1, 1, 9 },
    { -72, -27, 1, 1, 9 },
    { -72, -27, 1, 1, 9 },
    { -24, -22, 1, 1, 9 },
    { -37, -21, 1, 1, 9 },
    { -32, -58, 1, 1, 9 },
    { -45, -37, 1, 1, 9 },
    { -34, -20, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -25, -4, 1, 1, 10 },
    { -30, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -27, 54, 1, 1, 10 },
    { -35, -19, 1, 1, 10 },
    { -29, 112, 1, 1, 10 },
    { -25, 0, 1, 1, 10 },
    { -28, 52, 1, 1, 10 },
    { -21, -17, 1, 1, 10 },
    { -17, 76, 1, 1, 10 },
    { -27, 54, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -25, -4, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -33, 59, 1, 1, 10 },
    { -28, -10, 1, 1, 10 },
    { -17, -36, 1, 1, 10 },
    { -23, 54, 1, 1, 10 },
    { -22, -10, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -8, 128, 1, 1, 11 },
    { -4, -7, 1, 1, 11 },
    { 10, 80, 1, 1, 11 },
    { -14, 62, 1, 1, 11 },
    { -18, 72, 1, 1, 11 },
    { -17, 146, 1, 1, 11 },
    { -8, -10, 1, 1, 11 },
    { -10, 66, 1, 1, 11 },
    { -10, 82, 1, 1, 11 },
    { -17, 86, 2, 1, 11 },
    { -14, 62, 1, 1, 11 },
    { 10, 80, 1, 1, 11 },
    { 10, 80, 1, 1, 11 },
    { -8, 129, 1, 1, 11 },
    { 10, 80, 1, 1, 11 },
    { 10, 80, 1, 1, 11 },
    { -25, -2, 1, 1, 11 },
    { -4, -14, 1, 1, 11 },
    { -10, 16, 1, 1, 11 },
    { -7, 60, 1, 1, 11 },
    { 20, 14, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 103, 21, 1, 1, 12 },
    { 76, 58, 1, 1, 12 },
    { 64, 64, 2, 1, 12 },
    { 112, 32, 2, 1, 12 },
    { 112, 60, 2, 1, 12 },
    { 112, 48, 2, 1, 12 },
    { 92, 26, 1, 1, 12 },
    { 112, 46, 2, 1, 12 },
    { 82, 58, 2, 1, 12 },
    { 120, 44, 2, 1, 12 },
    { 112, 32, 2, 1, 12 },
    { 64, 64, 2, 1, 12 },
    { 64, 64, 2, 1, 12 },
    { 103, 21, 1, 1, 12 },
    { 64, 64, 2, 1, 12 },
    { 64, 64, 2, 1, 12 },
    { 85, 19, 1, 1, 12 },
    { 102, 47, 2, 1, 12 },
    { 65, 31, 2, 1, 12 },
    { 101, 11, 2, 1, 12 },
    { 100, 36, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -48, 0, 1, 1, 1 },
    { -36, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -32, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -45, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { -51, 0, 1, 1, 1 },
    { -50, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 2 },
    { -36, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -41, 0, 1, 1, 2 },
    { -32, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -59, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -54, 0, 1, 1, 2 },
    { -41, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -45, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -49, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -32, 0, 1, 1, 3 },
    { -36, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -39, 0, 1, 1, 3 },
    { -31, 0, 1, 1, 3 },
    { -47, 0, 1, 1, 3 },
    { -59, 0, 1, 1, 3 },
    { -47, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -39, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 3 },
    { -34, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -50, 0, 1, 1, 3 },
    { -50, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -36, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -31, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -59, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -46, 2, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -44, 0, 1, 1, 4 },
    { -43, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -50, 0, 1, 1, 4 },
    { -50, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -51, -5, 1, 1, 5 },
    { -80, -13, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -56, 4, 2, 1, 5 },
    { -72, -17, 2, 1, 5 },
    { -79, -3, 2, 1, 5 },
    { -65, -4, 2, 1, 5 },
    { -64, 0, 2, 1, 5 },
    { -58, 4, 2, 1, 5 },
    { -67, 12, 2, 1, 5 },
    { -56, 4, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -51, -5, 1, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -35, 0, 2, 1, 5 },
    { -56, 0, 2, 1, 5 },
    { -64, -16, 2, 1, 5 },
    { -52, 0, 2, 1, 5 },
    { -54, 4, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -64, -11, 2, 1, 6 },
    { -72, -13, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -49, 4, 2, 1, 6 },
    { -61, -16, 2, 1, 6 },
    { -70, -7, 2, 1, 6 },
    { -50, -10, 2, 1, 6 },
    { -59, 2, 2, 1, 6 },
    { -56, 5, 2, 1, 6 },
    { -64, 10, 2, 1, 6 },
    { -49, 4, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -64, -11, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -61, 0, 2, 1, 6 },
    { -47, 0, 2, 1, 6 },
    { -66, -19, 2, 1, 6 },
    { -48, -4, 2, 1, 6 },
    { -56, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -66, -8, 2, 1, 7 },
    { -68, -12, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -46, 6, 2, 1, 7 },
    { -57, -15, 2, 1, 7 },
    { -64, -6, 2, 1, 7 },
    { -47, -6, 2, 1, 7 },
    { -49, 0, 2, 1, 7 },
    { -59, 8, 2, 1, 7 },
    { -61, 10, 2, 1, 7 },
    { -46, 6, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -66, -8, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -27, 0, 2, 1, 7 },
    { -47, 0, 2, 1, 7 },
    { -53, -26, 2, 1, 7 },
    { -57, 4, 2, 1, 7 },
    { -60, 2, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -72, -112, 2, 1, 8 },
    { -73, -115, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -50, -97, 2, 1, 8 },
    { -62, -118, 2, 1, 8 },
    { -69, -109, 2, 1, 8 },
    { -54, -108, 2, 1, 8 },
    { -54, -103, 2, 1, 8 },
    { -64, -102, 2, 1, 8 },
    { -68, -93, 2, 1, 8 },
    { -50, -97, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -72, -112, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -48, -107, 2, 1, 8 },
    { -53, -95, 2, 1, 8 },
    { -58, -129, 2, 1, 8 },
    { -65, -104, 2, 1, 8 },
    { -69, -100, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -67, -117, 2, 1, 9 },
    { -67, -119, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -41, -102, 2, 1, 9 },
    { -49, -123, 2, 1, 9 },
    { -62, -114, 2, 1, 9 },
    { -53, -122, 2, 1, 9 },
    { -49, -108, 2, 1, 9 },
    { -60, -111, 2, 1, 9 },
    { -64, -99, 2, 1, 9 },
    { -41, -102, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -67, -117, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -56, -99, 2, 1, 9 },
    { -51, -100, 2, 1, 9 },
    { -58, -104, 2, 1, 9 },
    { -65, -106, 2, 1, 9 },
    { -71, -104, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -26, -134, 2, 1, 10 },
    { -31, -136, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -4, -118, 2, 1, 10 },
    { -12, -139, 2, 1, 10 },
    { -27, -130, 2, 1, 10 },
    { -21, -138, 2, 1, 10 },
    { -7, -122, 2, 1, 10 },
    { -23, -124, 2, 1, 10 },
    { -27, -115, 2, 1, 10 },
    { -4, -118, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -26, -134, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -35, -117, 2, 1, 10 },
    { -30, -118, 2, 1, 10 },
    { -35, -145, 2, 1, 10 },
    { -27, -125, 2, 1, 10 },
    { -36, -128, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -16, -136, 2, 1, 11 },
    { -19, -140, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { 6, -121, 2, 1, 11 },
    { -3, -142, 2, 1, 11 },
    { -15, -133, 2, 1, 11 },
    { -8, -143, 2, 1, 11 },
    { 2, -125, 2, 1, 11 },
    { -12, -126, 2, 1, 11 },
    { -15, -117, 2, 1, 11 },
    { 6, -121, 1, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -16, -136, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -38, -120, 2, 1, 11 },
    { -20, -124, 2, 1, 11 },
    { -27, -152, 2, 1, 11 },
    { -15, -132, 2, 1, 11 },
    { -7, -141, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -8, -138, 2, 1, 12 },
    { -12, -140, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { 13, -121, 2, 1, 12 },
    { 5, -143, 2, 1, 12 },
    { -6, -134, 2, 1, 12 },
    { 1, -146, 2, 1, 12 },
    { 9, -125, 2, 1, 12 },
    { -5, -126, 2, 1, 12 },
    { -7, -117, 2, 1, 12 },
    { 13, -121, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -8, -138, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -32, -119, 2, 1, 12 },
    { -11, -124, 2, 1, 12 },
    { -7, -147, 2, 1, 12 },
    { -10, -136, 2, 1, 12 },
    { 3, -147, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 5, -135, 2, 1, 13 },
    { 0, -139, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 14, -121, 2, 1, 13 },
    { 18, -143, 2, 1, 13 },
    { 5, -133, 2, 1, 13 },
    { 13, -148, 2, 1, 13 },
    { 8, -124, 2, 1, 13 },
    { 6, -119, 2, 1, 13 },
    { 5, -115, 2, 1, 13 },
    { 14, -121, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 5, -135, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { -25, -111, 2, 1, 13 },
    { 5, -128, 2, 1, 13 },
    { 6, -147, 2, 1, 13 },
    { 3, -138, 2, 1, 13 },
    { 19, -150, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 8, -137, 2, 1, 14 },
    { 8, -139, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 19, -120, 2, 1, 14 },
    { 19, -146, 2, 1, 14 },
    { 10, -135, 2, 1, 14 },
    { 19, -161, 2, 1, 14 },
    { 17, -125, 2, 1, 14 },
    { 7, -121, 2, 1, 14 },
    { 11, -113, 2, 1, 14 },
    { 19, -120, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 8, -137, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 5, -125, 2, 1, 14 },
    { 11, -128, 2, 1, 14 },
    { -2, -145, 2, 1, 14 },
    { 12, -139, 2, 1, 14 },
    { 28, -148, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 17, -136, 2, 1, 15 },
    { 18, -141, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 26, -119, 2, 1, 15 },
    { 27, -145, 2, 1, 15 },
    { 18, -134, 2, 1, 15 },
    { 30, -162, 2, 1, 15 },
    { 22, -124, 2, 1, 15 },
    { 10, -120, 2, 1, 15 },
    { 16, -106, 2, 1, 15 },
    { 26, -119, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 17, -136, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 19, -125, 2, 1, 15 },
    { 12, -121, 2, 1, 15 },
    { 29, -150, 2, 1, 15 },
    { 19, -140, 2, 1, 15 },
    { 30, -143, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 32, -135, 2, 1, 16 },
    { 33, -135, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 39, -115, 2, 1, 16 },
    { 40, -141, 2, 1, 16 },
    { 32, -130, 2, 1, 16 },
    { 42, -159, 2, 1, 16 },
    { 36, -120, 2, 1, 16 },
    { 24, -116, 2, 1, 16 },
    { 29, -103, 2, 1, 16 },
    { 39, -115, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 32, -135, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 19, -125, 2, 1, 16 },
    { 30, -119, 2, 1, 16 },
    { 42, -148, 2, 1, 16 },
    { 40, -128, 2, 1, 16 },
    { 42, -142, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 36, -133, 2, 1, 17 },
    { 44, -133, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 48, -114, 2, 1, 17 },
    { 47, -139, 2, 1, 17 },
    { 40, -128, 2, 1, 17 },
    { 48, -157, 2, 1, 17 },
    { 43, -119, 2, 1, 17 },
    { 53, -130, 2, 1, 17 },
    { 36, -101, 2, 1, 17 },
    { 48, -114, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 36, -133, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 53, -124, 2, 1, 17 },
    { 46, -118, 2, 1, 17 },
    { 49, -154, 2, 1, 17 },
    { 48, -126, 2, 1, 17 },
    { 54, -140, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 88, -27, 1, 1, 18 },
    { 81, -26, 1, 1, 18 },
    { 78, -20, 1, 1, 18 },
    { 85, -10, 1, 1, 18 },
    { 85, -27, 1, 1, 18 },
    { 75, -17, 1, 1, 18 },
    { 80, -33, 1, 1, 18 },
    { 77, -10, 1, 1, 18 },
    { 71, -12, 2, 1, 18 },
    { 80, 0, 1, 1, 18 },
    { 85, -10, 1, 1, 18 },
    { 78, -20, 1, 1, 18 },
    { 78, -20, 1, 1, 18 },
    { 88, -27, 1, 1, 18 },
    { 78, -20, 1, 1, 18 },
    { 78, -20, 1, 1, 18 },
    { 71, -7, 2, 1, 18 },
    { 61, -5, 2, 1, 18 },
    { 68, -37, 2, 1, 18 },
    { 67, -8, 2, 1, 18 },
    { 87, -17, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 108, -20, 1, 1, 19 },
    { 109, -20, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 103, -10, 1, 1, 19 },
    { 103, -24, 1, 1, 19 },
    { 95, -17, 1, 1, 19 },
    { 90, -33, 1, 1, 19 },
    { 91, -10, 1, 1, 19 },
    { 127, -6, 1, 1, 19 },
    { 96, -10, 1, 1, 19 },
    { 103, -9, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 108, -20, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 88, -2, 1, 1, 19 },
    { 84, -5, 1, 1, 19 },
    { 94, -27, 1, 1, 19 },
    { 87, -10, 1, 1, 19 },
    { 91, -12, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 119, -9, 1, 1, 20 },
    { 120, -9, 1, 1, 20 },
    { 111, -13, 1, 1, 20 },
    { 114, -6, 1, 1, 20 },
    { 115, -17, 1, 1, 20 },
    { 108, -13, 1, 1, 20 },
    { 105, -27, 1, 1, 20 },
    { 99, -7, 1, 1, 20 },
    { 127, -3, 1, 1, 20 },
    { 107, -2, 1, 1, 20 },
    { 114, -6, 1, 1, 20 },
    { 111, -13, 1, 1, 20 },
    { 111, -13, 1, 1, 20 },
    { 119, -9, 1, 1, 20 },
    { 111, -13, 1, 1, 20 },
    { 111, -13, 1, 1, 20 },
    { 94, -5, 1, 1, 20 },
    { 89, -2, 1, 1, 20 },
    { 85, -25, 1, 1, 20 },
    { 98, -8, 1, 1, 20 },
    { 104, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { 124, 0, 1, 1, 21 },
    { 130, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 118, 0, 1, 1, 21 },
    { 115, 0, 1, 1, 21 },
    { 115, 0, 1, 1, 21 },
    { 115, 0, 1, 1, 21 },
    { 99, 0, 1, 1, 21 },
    { 128, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 118, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 124, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 116, 0, 1, 1, 21 },
    { 88, 0, 1, 1, 21 },
    { 89, 0, 1, 1, 21 },
    { 85, 0, 1, 1, 21 },
    { 98, 0, 1, 1, 21 },
    { 112, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { -48, 0, 1, 1, 1 },
    { -36, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -32, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { -29, 0, 1, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -48, 0, 1, 1, 2 },
    { -36, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -41, 0, 1, 1, 2 },
    { -32, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -40, 0, 1, 1, 2 },
    { -54, 0, 1, 1, 2 },
    { -41, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { -29, 0, 1, 1, 2 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -32, 0, 1, 1, 3 },
    { -36, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -39, 0, 1, 1, 3 },
    { -31, 0, 1, 1, 3 },
    { -47, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -47, 0, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -39, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -32, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { -28, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -31, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -46, 2, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -39, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { -29, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -51, -5, 1, 1, 5 },
    { -80, -13, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -56, 4, 2, 1, 5 },
    { -72, -17, 2, 1, 5 },
    { -79, -3, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -64, 0, 2, 1, 5 },
    { -58, 4, 2, 1, 5 },
    { -67, 12, 2, 1, 5 },
    { -56, 4, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -51, -5, 1, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { -68, -11, 2, 1, 5 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, -11, 2, 1, 6 },
    { -72, -13, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -49, 4, 2, 1, 6 },
    { -61, -16, 2, 1, 6 },
    { -70, -7, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -59, 2, 2, 1, 6 },
    { -56, 5, 2, 1, 6 },
    { -64, 10, 2, 1, 6 },
    { -49, 4, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -64, -11, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { -59, -12, 2, 1, 6 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -66, -8, 2, 1, 7 },
    { -68, -12, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -46, 6, 2, 1, 7 },
    { -57, -15, 2, 1, 7 },
    { -64, -6, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -49, 0, 2, 1, 7 },
    { -59, 8, 2, 1, 7 },
    { -61, 10, 2, 1, 7 },
    { -46, 6, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -66, -8, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { -57, -10, 2, 1, 7 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -72, -112, 2, 1, 8 },
    { -73, -115, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -50, -97, 2, 1, 8 },
    { -62, -118, 2, 1, 8 },
    { -69, -109, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -54, -103, 2, 1, 8 },
    { -64, -102, 2, 1, 8 },
    { -68, -93, 2, 1, 8 },
    { -50, -97, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -72, -112, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { -61, -114, 2, 1, 8 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -67, -117, 2, 1, 9 },
    { -67, -119, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -41, -102, 2, 1, 9 },
    { -49, -123, 2, 1, 9 },
    { -62, -114, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -49, -108, 2, 1, 9 },
    { -60, -111, 2, 1, 9 },
    { -64, -99, 2, 1, 9 },
    { -41, -102, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -67, -117, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { -54, -116, 2, 1, 9 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -26, -134, 2, 1, 10 },
    { -31, -136, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -4, -118, 2, 1, 10 },
    { -12, -139, 2, 1, 10 },
    { -27, -130, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -7, -122, 2, 1, 10 },
    { -23, -124, 2, 1, 10 },
    { -27, -115, 2, 1, 10 },
    { -4, -118, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -26, -134, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { -18, -130, 2, 1, 10 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -16, -136, 2, 1, 11 },
    { -19, -140, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { 6, -121, 2, 1, 11 },
    { -3, -142, 2, 1, 11 },
    { -15, -133, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 2, -125, 2, 1, 11 },
    { -12, -126, 2, 1, 11 },
    { -15, -117, 2, 1, 11 },
    { 6, -121, 1, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -16, -136, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { -8, -133, 2, 1, 11 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -8, -138, 2, 1, 12 },
    { -12, -140, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { 13, -121, 2, 1, 12 },
    { 5, -143, 2, 1, 12 },
    { -6, -134, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 9, -125, 2, 1, 12 },
    { -5, -126, 2, 1, 12 },
    { -7, -117, 2, 1, 12 },
    { 13, -121, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -8, -138, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { -1, -132, 2, 1, 12 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 5, -135, 2, 1, 13 },
    { 0, -139, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 14, -121, 2, 1, 13 },
    { 18, -143, 2, 1, 13 },
    { 5, -133, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 8, -124, 2, 1, 13 },
    { 6, -119, 2, 1, 13 },
    { 5, -115, 2, 1, 13 },
    { 14, -121, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 5, -135, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 12, -131, 2, 1, 13 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 8, -137, 2, 1, 14 },
    { 8, -139, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 19, -120, 2, 1, 14 },
    { 19, -146, 2, 1, 14 },
    { 10, -135, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 17, -125, 2, 1, 14 },
    { 7, -121, 2, 1, 14 },
    { 11, -113, 2, 1, 14 },
    { 19, -120, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 8, -137, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 15, -138, 2, 1, 14 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 17, -136, 2, 1, 15 },
    { 18, -141, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 26, -119, 2, 1, 15 },
    { 27, -145, 2, 1, 15 },
    { 18, -134, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 22, -124, 2, 1, 15 },
    { 10, -120, 2, 1, 15 },
    { 16, -106, 2, 1, 15 },
    { 26, -119, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 17, -136, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 23, -137, 2, 1, 15 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 32, -135, 2, 1, 16 },
    { 33, -135, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 39, -115, 2, 1, 16 },
    { 40, -141, 2, 1, 16 },
    { 32, -130, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 36, -120, 2, 1, 16 },
    { 24, -116, 2, 1, 16 },
    { 29, -102, 2, 1, 16 },
    { 39, -115, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 32, -135, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 37, -133, 2, 1, 16 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 36, -133, 2, 1, 17 },
    { 44, -133, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 48, -114, 2, 1, 17 },
    { 47, -139, 2, 1, 17 },
    { 40, -128, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 43, -119, 2, 1, 17 },
    { 53, -130, 2, 1, 17 },
    { 36, -100, 2, 1, 17 },
    { 48, -114, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 36, -133, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 47, -129, 2, 1, 17 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 88, -27, 1, 1, 18 },
    { 61, -18, 1, 1, 18 },
    { 59, -13, 1, 1, 18 },
    { 63, 0, 1, 1, 18 },
    { 60, -19, 1, 1, 18 },
    { 61, -14, 1, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 48, 3, 1, 1, 18 },
    { 50, -11, 1, 1, 18 },
    { 54, 5, 1, 1, 18 },
    { 63, 0, 1, 1, 18 },
    { 59, -13, 1, 1, 18 },
    { 59, -13, 1, 1, 18 },
    { 88, -27, 1, 1, 18 },
    { 59, -13, 1, 1, 18 },
    { 59, -13, 1, 1, 18 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 108, -20, 1, 1, 19 },
    { 109, -20, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 103, -10, 1, 1, 19 },
    { 103, -24, 1, 1, 19 },
    { 95, -17, 1, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 91, -10, 1, 1, 19 },
    { 127, -6, 1, 1, 19 },
    { 96, -10, 1, 1, 19 },
    { 103, -9, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 108, -20, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 99, -19, 1, 1, 19 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, 0, 1, 1, 20 },
    { -57, -23, 1, 1, 20 },
    { -26, -17, 1, 1, 20 },
    { -30, -13, 1, 1, 20 },
    { -57, -10, 1, 1, 20 },
    { -41, -19, 1, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { -45, -9, 1, 1, 20 },
    { -35, -11, 1, 1, 20 },
    { -60, -5, 1, 1, 20 },
    { -30, -13, 1, 1, 20 },
    { -26, -17, 1, 1, 20 },
    { -26, -17, 1, 1, 20 },
    { -54, 0, 1, 1, 20 },
    { -26, -17, 1, 1, 20 },
    { -26, -17, 1, 1, 20 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, -36, 1, 1, 21 },
    { -52, -56, 1, 1, 21 },
    { -27, -47, 1, 1, 21 },
    { -26, -44, 1, 1, 21 },
    { -52, -42, 1, 1, 21 },
    { -38, -50, 1, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { -40, -41, 1, 1, 21 },
    { -30, -43, 1, 1, 21 },
    { -56, -37, 1, 1, 21 },
    { -26, -44, 1, 1, 21 },
    { -27, -47, 2, 1, 21 },
    { -27, -47, 2, 1, 21 },
    { -54, -36, 1, 1, 21 },
    { -27, -47, 1, 1, 21 },
    { -27, -47, 1, 1, 21 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, -44, 1, 1, 22 },
    { -62, -46, 1, 1, 22 },
    { -35, -47, 1, 1, 22 },
    { -36, -33, 1, 1, 22 },
    { -61, -41, 1, 1, 22 },
    { -50, -51, 1, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { -47, -41, 1, 1, 22 },
    { -40, -38, 1, 1, 22 },
    { -68, -36, 1, 1, 22 },
    { -36, -33, 1, 1, 22 },
    { -35, -47, 2, 1, 22 },
    { -35, -47, 2, 1, 22 },
    { -54, -44, 1, 1, 22 },
    { -35, -47, 1, 1, 22 },
    { -35, -47, 1, 1, 22 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -52, -44, 1, 1, 23 },
    { -63, -46, 1, 1, 23 },
    { -51, -45, 1, 1, 23 },
    { -37, -31, 1, 1, 23 },
    { -62, -43, 1, 1, 23 },
    { -50, -52, 1, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { -47, -41, 1, 1, 23 },
    { -39, -40, 1, 1, 23 },
    { -69, -36, 1, 1, 23 },
    { -37, -31, 1, 1, 23 },
    { -51, -45, 1, 1, 23 },
    { -51, -45, 1, 1, 23 },
    { -52, -44, 1, 1, 23 },
    { -51, -45, 1, 1, 23 },
    { -51, -45, 1, 1, 23 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -36, -30, 1, 1, 24 },
    { -51, -29, 1, 1, 24 },
    { -16, -31, 1, 1, 24 },
    { -8, -11, 1, 1, 24 },
    { -42, -27, 1, 1, 24 },
    { -42, -25, 1, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { -38, -28, 1, 1, 24 },
    { -27, -32, 1, 1, 24 },
    { -52, -20, 1, 1, 24 },
    { -8, -11, 1, 1, 24 },
    { -16, -31, 1, 1, 24 },
    { -16, -31, 1, 1, 24 },
    { -36, -30, 1, 1, 24 },
    { -16, -31, 1, 1, 24 },
    { -16, -31, 1, 1, 24 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -32, -20, 1, 1, 25 },
    { -36, -14, 1, 1, 25 },
    { -3, -15, 1, 1, 25 },
    { -29, 5, 1, 1, 25 },
    { -35, -19, 1, 1, 25 },
    { -30, -16, 1, 1, 25 },
    { 0, 0, 2, 1, 25 },
    { -32, -17, 1, 1, 25 },
    { -20, -18, 1, 1, 25 },
    { -39, -7, 1, 1, 25 },
    { -29, 5, 1, 1, 25 },
    { -3, -15, 1, 1, 25 },
    { -3, -15, 1, 1, 25 },
    { -32, -20, 1, 1, 25 },
    { -3, -15, 1, 1, 25 },
    { -3, -15, 1, 1, 25 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -12, -6, 1, 1, 26 },
    { -2, -8, 1, 1, 26 },
    { -1, 25, 1, 1, 26 },
    { -16, 34, 1, 1, 26 },
    { -18, -2, 1, 1, 26 },
    { -18, -5, 1, 1, 26 },
    { 0, 0, 2, 1, 26 },
    { -9, 19, 1, 1, 26 },
    { -14, 10, 1, 1, 26 },
    { -5, -13, 1, 1, 26 },
    { -16, 34, 1, 1, 26 },
    { -1, 25, 1, 1, 26 },
    { -1, 25, 1, 1, 26 },
    { -12, -6, 1, 1, 26 },
    { -1, 25, 1, 1, 26 },
    { -1, 25, 1, 1, 26 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -25, -4, 1, 1, 27 },
    { -30, -5, 1, 1, 27 },
    { -64, -15, 1, 1, 27 },
    { -67, 18, 1, 1, 27 },
    { -39, -41, 1, 1, 27 },
    { -38, -19, 1, 1, 27 },
    { 0, 0, 2, 1, 27 },
    { -26, 19, 1, 1, 27 },
    { -24, -12, 1, 1, 27 },
    { -25, -13, 1, 1, 27 },
    { -67, 18, 1, 1, 27 },
    { -64, -15, 1, 1, 27 },
    { -64, -15, 1, 1, 27 },
    { -25, -4, 1, 1, 27 },
    { -64, -15, 1, 1, 27 },
    { -64, -15, 1, 1, 27 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -8, 15, 1, 1, 28 },
    { 3, 2, 1, 1, 28 },
    { -9, 23, 1, 1, 28 },
    { -32, 44, 1, 1, 28 },
    { -14, -42, 1, 1, 28 },
    { -11, -14, 1, 1, 28 },
    { 0, 0, 2, 1, 28 },
    { 2, 37, 1, 1, 28 },
    { -12, 18, 1, 1, 28 },
    { -9, -1, 2, 1, 28 },
    { -32, 44, 1, 1, 28 },
    { -9, 23, 1, 1, 28 },
    { -9, 23, 1, 1, 28 },
    { -8, 15, 1, 1, 28 },
    { -9, 23, 1, 1, 28 },
    { -9, 23, 1, 1, 28 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 112, 21, 1, 1, 29 },
    { 112, 21, 1, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 101, 24, 2, 1, 29 },
    { 0, 0, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 1, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 112, 21, 2, 1, 29 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -55, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -60, -7, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -88, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -47, 0, 1, 1, 1 },
    { -45, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -36, 0, 1, 1, 2 },
    { -39, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -65, -7, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -60, 0, 1, 1, 2 },
    { -51, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -36, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -47, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -48, 0, 1, 1, 2 },
    { -39, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -29, -12, 1, 1, 3 },
    { -34, -13, 1, 1, 3 },
    { -42, -11, 1, 1, 3 },
    { -30, -11, 1, 1, 3 },
    { -45, -12, 1, 1, 3 },
    { -59, -11, 1, 1, 3 },
    { -62, -20, 1, 1, 3 },
    { -41, -12, 1, 1, 3 },
    { -56, -12, 1, 1, 3 },
    { -42, -10, 1, 1, 3 },
    { -30, -11, 1, 1, 3 },
    { -42, -11, 1, 1, 3 },
    { -42, -11, 1, 1, 3 },
    { -29, -12, 1, 1, 3 },
    { -42, -11, 1, 1, 3 },
    { -42, -11, 1, 1, 3 },
    { -59, -16, 1, 1, 3 },
    { -36, -11, 1, 1, 3 },
    { -42, -13, 1, 1, 3 },
    { -38, -17, 1, 1, 3 },
    { -55, -16, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -29, -48, 1, 1, 4 },
    { -37, -49, 1, 1, 4 },
    { -43, -47, 1, 1, 4 },
    { -30, -47, 1, 1, 4 },
    { -49, -42, 1, 1, 4 },
    { -59, -47, 1, 1, 4 },
    { -65, -57, 1, 1, 4 },
    { -43, -46, 1, 1, 4 },
    { -58, -47, 1, 1, 4 },
    { -42, -45, 1, 1, 4 },
    { -30, -47, 1, 1, 4 },
    { -43, -47, 1, 1, 4 },
    { -43, -47, 1, 1, 4 },
    { -29, -48, 1, 1, 4 },
    { -43, -47, 1, 1, 4 },
    { -43, -47, 1, 1, 4 },
    { -60, -52, 1, 1, 4 },
    { -37, -46, 1, 1, 4 },
    { -45, -67, 1, 1, 4 },
    { -44, -61, 1, 1, 4 },
    { -55, -54, 1, 1, 4 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -37, -51, 1, 1, 5 },
    { -52, -56, 1, 1, 5 },
    { -45, -49, 1, 1, 5 },
    { -37, -49, 1, 1, 5 },
    { -56, -46, 1, 1, 5 },
    { -67, -45, 1, 1, 5 },
    { -73, -60, 1, 1, 5 },
    { -50, -49, 1, 1, 5 },
    { -67, -48, 1, 1, 5 },
    { -51, -51, 1, 1, 5 },
    { -37, -49, 1, 1, 5 },
    { -45, -49, 1, 1, 5 },
    { -45, -49, 1, 1, 5 },
    { -37, -51, 1, 1, 5 },
    { -45, -49, 1, 1, 5 },
    { -45, -49, 1, 1, 5 },
    { -63, -54, 1, 1, 5 },
    { -54, -50, 1, 1, 5 },
    { -55, -72, 1, 1, 5 },
    { -61, -59, 1, 1, 5 },
    { -62, -63, 1, 1, 5 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -58, -60, 1, 1, 6 },
    { -59, -56, 1, 1, 6 },
    { -49, -50, 1, 1, 6 },
    { -39, -47, 1, 1, 6 },
    { -60, -44, 1, 1, 6 },
    { -71, -43, 1, 1, 6 },
    { -76, -58, 1, 1, 6 },
    { -53, -46, 1, 1, 6 },
    { -66, -47, 1, 1, 6 },
    { -68, -46, 1, 1, 6 },
    { -39, -47, 1, 1, 6 },
    { -49, -50, 1, 1, 6 },
    { -49, -50, 1, 1, 6 },
    { -58, -60, 1, 1, 6 },
    { -49, -50, 1, 1, 6 },
    { -49, -50, 1, 1, 6 },
    { -59, -58, 1, 1, 6 },
    { -65, -46, 1, 1, 6 },
    { -57, -70, 1, 1, 6 },
    { -62, -54, 1, 1, 6 },
    { -73, -59, 1, 1, 6 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -58, -60, 1, 1, 6 },
    { -61, -54, 1, 1, 6 },
    { -52, -49, 1, 1, 6 },
    { -41, -46, 1, 1, 6 },
    { -60, -44, 1, 1, 6 },
    { -74, -43, 1, 1, 6 },
    { -76, -57, 1, 1, 6 },
    { -54, -45, 1, 1, 6 },
    { -70, -46, 1, 1, 6 },
    { -69, -46, 1, 1, 6 },
    { -41, -46, 1, 1, 6 },
    { -52, -49, 1, 1, 6 },
    { -52, -49, 1, 1, 6 },
    { -58, -60, 1, 1, 6 },
    { -52, -49, 1, 1, 6 },
    { -52, -49, 1, 1, 6 },
    { -59, -57, 1, 1, 6 },
    { -67, -45, 1, 1, 6 },
    { -58, -70, 1, 1, 6 },
    { -63, -53, 1, 1, 6 },
    { -73, -58, 1, 1, 6 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -56, -57, 1, 1, 6 },
    { -58, -52, 1, 1, 6 },
    { -44, -45, 1, 1, 6 },
    { -37, -44, 1, 1, 6 },
    { -57, -42, 1, 1, 6 },
    { -69, -41, 1, 1, 6 },
    { -72, -55, 1, 1, 6 },
    { -51, -44, 1, 1, 6 },
    { -67, -45, 1, 1, 6 },
    { -67, -44, 1, 1, 6 },
    { -37, -44, 1, 1, 6 },
    { -44, -45, 1, 1, 6 },
    { -44, -45, 1, 1, 6 },
    { -56, -57, 1, 1, 6 },
    { -44, -45, 1, 1, 6 },
    { -44, -45, 1, 1, 6 },
    { -57, -55, 1, 1, 6 },
    { -65, -43, 1, 1, 6 },
    { -54, -67, 1, 1, 6 },
    { -62, -51, 1, 1, 6 },
    { -70, -55, 1, 1, 6 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -56, -57, 1, 1, 6 },
    { -45, -57, 1, 1, 6 },
    { -35, -48, 1, 1, 6 },
    { -34, -44, 1, 1, 6 },
    { -67, -47, 1, 1, 6 },
    { -62, -40, 1, 1, 6 },
    { -65, -61, 1, 1, 6 },
    { -50, -47, 1, 1, 6 },
    { -65, -47, 1, 1, 6 },
    { -64, -46, 1, 1, 6 },
    { -34, -44, 1, 1, 6 },
    { -35, -48, 1, 1, 6 },
    { -35, -48, 1, 1, 6 },
    { -56, -57, 1, 1, 6 },
    { -35, -48, 1, 1, 6 },
    { -35, -48, 1, 1, 6 },
    { -52, -54, 1, 1, 6 },
    { -64, -47, 1, 1, 6 },
    { -71, -68, 1, 1, 6 },
    { -53, -55, 1, 1, 6 },
    { -62, -57, 1, 1, 6 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -43, -64, 1, 1, 7 },
    { -88, -63, 1, 1, 7 },
    { -63, -55, 1, 1, 7 },
    { -41, -50, 1, 1, 7 },
    { -68, -51, 1, 1, 7 },
    { -62, -51, 1, 1, 7 },
    { -69, -62, 1, 1, 7 },
    { -70, -49, 1, 1, 7 },
    { -64, -48, 1, 1, 7 },
    { -40, -46, 1, 1, 7 },
    { -41, -50, 1, 1, 7 },
    { -63, -55, 1, 1, 7 },
    { -63, -55, 1, 1, 7 },
    { -43, -64, 1, 1, 7 },
    { -63, -55, 1, 1, 7 },
    { -63, -55, 1, 1, 7 },
    { -72, -52, 1, 1, 7 },
    { -64, -47, 1, 1, 7 },
    { -62, -62, 1, 1, 7 },
    { -67, -55, 1, 1, 7 },
    { -64, -62, 1, 1, 7 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -54, -62, 1, 1, 8 },
    { -97, -57, 1, 1, 8 },
    { -59, -47, 1, 1, 8 },
    { -50, -47, 1, 1, 8 },
    { -78, -53, 1, 1, 8 },
    { -62, -51, 1, 1, 8 },
    { -69, -62, 1, 1, 8 },
    { -73, -48, 1, 1, 8 },
    { -64, -48, 1, 1, 8 },
    { -76, -46, 1, 1, 8 },
    { -50, -47, 1, 1, 8 },
    { -59, -47, 1, 1, 8 },
    { -59, -47, 1, 1, 8 },
    { -54, -62, 1, 1, 8 },
    { -59, -47, 1, 1, 8 },
    { -59, -47, 1, 1, 8 },
    { -67, -53, 1, 1, 8 },
    { -76, -42, 1, 1, 8 },
    { -98, -58, 1, 1, 8 },
    { -68, -51, 1, 1, 8 },
    { -69, -48, 1, 1, 8 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
};

/* extra scripts: 101 entries */
const u16* const yang_exca[102] = {
    yang_exca_000,  /* 0 follow-up of AIR NORMAL, CATCH 10 */
    yang_exca_001,  /* 1 follow-up of GUARD AIR */
    yang_exca_001,  /* 2 no name */
    yang_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    yang_exca_004,  /* 4 no name */
    yang_exca_005,  /* 5 follow-up of TATAKI S, KGM TATAKI S +24 */
    yang_exca_006,  /* 6 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1 */
    yang_exca_006,  /* 7 follow-up of KUNOJI, UPPER +6 */
    yang_exca_006,  /* 8 follow-up of TTKI V. AIR */
    yang_exca_009,  /* 9 follow-up of KIRIMOMI, SPLASH.M +3 */
    yang_exca_010,  /* 10 follow-up of GUARD AIR */
    yang_exca_010,  /* 11 no name */
    yang_exca_012,  /* 12 follow-up of ATTACK 5 S */
    yang_exca_013,  /* 13 no name */
    yang_exca_014,  /* 14 no name */
    yang_exca_015,  /* 15 no name */
    yang_exca_016,  /* 16 no name */
    yang_exca_017,  /* 17 no name */
    yang_exca_018,  /* 18 no name */
    yang_exca_019,  /* 19 no name */
    yang_exca_020,  /* 20 no name */
    yang_exca_021,  /* 21 no name */
    yang_exca_022,  /* 22 no name */
    yang_exca_022,  /* 23 no name */
    yang_exca_024,  /* 24 follow-up of ATTACK 5 S */
    yang_exca_025,  /* 25 follow-up of ALEX BACK D, MAWARIKOMI M F */
    yang_exca_026,  /* 26 no name */
    yang_exca_027,  /* 27 follow-up of HANASARE, APPEAR JUNBI 2 */
    yang_exca_028,  /* 28 follow-up of SP APPEAR 2 */
    yang_exca_029,  /* 29 follow-up of APPEAR JUNBI 5 */
    yang_exca_030,  /* 30 no name */
    yang_exca_031,  /* 31 follow-up of APPEAR JUNBI 3 */
    yang_exca_032,  /* 32 follow-up of APPEAR 8 */
    yang_exca_033,  /* 33 follow-up of APPEAR JUNBI 6 */
    yang_exca_034,  /* 34 no name */
    yang_exca_035,  /* 35 follow-up of APPEAR JUNBI 4 */
    yang_exca_036,  /* 36 no name */
    yang_exca_037,  /* 37 follow-up of APPEAR JUNBI 7 */
    yang_exca_038,  /* 38 no name */
    yang_exca_039,  /* 39 follow-up of HANASARE, APPEAR JUNBI 2 */
    yang_exca_040,  /* 40 follow-up of SP APPEAR 2 */
    yang_exca_041,  /* 41 follow-up of APPEAR JUNBI 5 */
    yang_exca_042,  /* 42 no name */
    yang_exca_043,  /* 43 follow-up of APPEAR JUNBI 3 */
    yang_exca_044,  /* 44 follow-up of APPEAR 8 */
    yang_exca_045,  /* 45 follow-up of APPEAR JUNBI 6 */
    yang_exca_046,  /* 46 no name */
    yang_exca_047,  /* 47 follow-up of APPEAR JUNBI 4 */
    yang_exca_048,  /* 48 no name */
    yang_exca_049,  /* 49 follow-up of APPEAR JUNBI 7 */
    yang_exca_050,  /* 50 no name */
    yang_exca_051,  /* 51 follow-up of APPEAR 4 */
    yang_exca_052,  /* 52 follow-up of APPEAR 4 */
    yang_exca_053,  /* 53 follow-up of APPEAR 5 */
    yang_exca_054,  /* 54 follow-up of APPEAR 5 */
    yang_exca_022,  /* 55 no name */
    yang_exca_056,  /* 56 no name */
    yang_exca_022,  /* 57 no name */
    yang_exca_058,  /* 58 no name */
    yang_exca_022,  /* 59 no name */
    yang_exca_022,  /* 60 no name */
    yang_exca_061,  /* 61 follow-up of SP APPEAR 1 */
    yang_exca_062,  /* 62 follow-up of SP APPEAR 1 */
    yang_exca_063,  /* 63 follow-up of SP APPEAR 3, JUDGMENT WIN */
    yang_exca_064,  /* 64 follow-up of SP APPEAR 3, JUDGMENT WIN */
    yang_exca_065,  /* 65 follow-up of SP APPEAR 4 */
    yang_exca_066,  /* 66 follow-up of SP APPEAR 4 */
    yang_exca_022,  /* 67 no name */
    yang_exca_022,  /* 68 no name */
    yang_exca_022,  /* 69 no name */
    yang_exca_022,  /* 70 follow-up of SP APPEAR 5 */
    yang_exca_022,  /* 71 follow-up of SP APPEAR 5 */
    yang_exca_022,  /* 72 no name */
    yang_exca_073,  /* 73 follow-up of ZANNEN 1 */
    yang_exca_074,  /* 74 follow-up of ZANNEN 1 */
    yang_exca_075,  /* 75 follow-up of SP WIN 5 */
    yang_exca_076,  /* 76 follow-up of SP WIN 5 */
    yang_exca_077,  /* 77 follow-up of HUMI ASIB */
    yang_exca_078,  /* 78 follow-up of GILL IMPACT C */
    yang_exca_079,  /* 79 follow-up of GILL IMPACT C */
    yang_exca_080,  /* 80 follow-up of APPEAR 6 */
    yang_exca_081,  /* 81 follow-up of APPEAR 6 */
    yang_exca_082,  /* 82 HANASARE */
    yang_exca_083,  /* 83 HANASARE */
    yang_exca_084,  /* 84 HANASARE */
    yang_exca_085,  /* 85 HANASARE */
    yang_exca_086,  /* 86 HANASARE */
    yang_exca_087,  /* 87 HANASARE */
    yang_exca_088,  /* 88 HANASARE */
    yang_exca_089,  /* 89 HANASARE */
    yang_exca_090,  /* 90 HANASARE */
    yang_exca_091,  /* 91 HANASARE */
    yang_exca_090,  /* 92 HANASARE */
    yang_exca_091,  /* 93 HANASARE */
    yang_exca_094,  /* 94 HANASARE */
    yang_exca_095,  /* 95 HANASARE */
    yang_exca_096,  /* 96 HANASARE */
    yang_exca_097,  /* 97 HANASARE */
    yang_exca_098,  /* 98 HANASARE */
    yang_exca_099,  /* 99 HANASARE */
    yang_exca_100,  /* 100 HANASARE */
    0
};

/* script: 0 follow-up of AIR NORMAL, CATCH 10 */
const u16 yang_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_exca_000[164] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9C, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9B, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9A, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F99, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F98, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F97, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3F96, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C88, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C89, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8A, 0, 192, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8B, 0, 192, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8C, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C8D, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C8E, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of GUARD AIR, 2 no name */
const u16 yang_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_001[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 yang_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_003[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 no name */
const u16 yang_exca_004_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_004[124] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x3E86, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3E87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3E89, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3E8A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3E8B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, KGM TATAKI S +24 */
const u16 yang_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_005[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D28, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1, 7 follow-up of KUNOJI, UPPER +6, 8 follow-up of TTKI V. AIR */
const u16 yang_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_006[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D28, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, SPLASH.M +3 */
const u16 yang_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_009[52] = {
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of GUARD AIR, 11 no name */
const u16 yang_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_010[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of ATTACK 5 S */
const u16 yang_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_012[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 yang_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_013[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E04, 0, 103, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E04, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E05, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3E06, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 yang_exca_014_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_014[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E2B, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E2B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 yang_exca_015_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_015[100] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3EA4, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3EA5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3EA6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3EA7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3EA8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3EA9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3EAA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3EAB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 yang_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_016[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6C, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 yang_exca_017_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_017[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E6B, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3E6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C30, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 yang_exca_018_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_018[76] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3F12, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3F12, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3F13, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3F14, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3F15, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 yang_exca_019_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_019[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 yang_exca_020_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_020[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E89, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E89, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E89, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 yang_exca_021_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_021[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E1D, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E1D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E1D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 273, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of ATTACK 5 S */
const u16 yang_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_024[44] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of ALEX BACK D, MAWARIKOMI M F */
const u16 yang_exca_025_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_025[108] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D28, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D27, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D28, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 no name */
const u16 yang_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_026[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C30, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of HANASARE, APPEAR JUNBI 2 */
const u16 yang_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_027[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of SP APPEAR 2 */
const u16 yang_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_028[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR JUNBI 5 */
const u16 yang_exca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_029[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 no name */
const u16 yang_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_030[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR JUNBI 3 */
const u16 yang_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_031[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 8 */
const u16 yang_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_032[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR JUNBI 6 */
const u16 yang_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_033[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 no name */
const u16 yang_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_034[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of APPEAR JUNBI 4 */
const u16 yang_exca_035_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_035[64] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 yang_exca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_036[52] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of APPEAR JUNBI 7 */
const u16 yang_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_037[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 no name */
const u16 yang_exca_038_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_038[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of HANASARE, APPEAR JUNBI 2 */
const u16 yang_exca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_039[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP APPEAR 2 */
const u16 yang_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_040[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of APPEAR JUNBI 5 */
const u16 yang_exca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_041[84] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 yang_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_042[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C7D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C7E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of APPEAR JUNBI 3 */
const u16 yang_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_043[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of APPEAR 8 */
const u16 yang_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_044[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of APPEAR JUNBI 6 */
const u16 yang_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_045[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 yang_exca_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_046[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of APPEAR JUNBI 4 */
const u16 yang_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_047[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 32, 98),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 32, 98),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 32, 98),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yang_exca_048_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_048[52] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 47, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of APPEAR JUNBI 7 */
const u16 yang_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_049[52] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 32, 98),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 32, 98),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 32, 98),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yang_exca_050_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_050[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x3C8D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C8E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x3C8F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 49, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 follow-up of APPEAR 4 */
const u16 yang_exca_051_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_051[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E86, 0, 183, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E87, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E88, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3E89, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3E8A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E8B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 follow-up of APPEAR 4 */
const u16 yang_exca_052_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_052[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E86, 0, 183, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E87, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E88, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3E8A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of APPEAR 5 */
const u16 yang_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_053[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6C, 0, 184, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6D, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6E, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of APPEAR 5 */
const u16 yang_exca_054_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_054[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E6B, 0, 184, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3E6C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x3E6C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 yang_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_056[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 yang_exca_058_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_exca_058[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x3D46, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x3ED0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x3ED0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of SP APPEAR 1 */
const u16 yang_exca_061_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_061[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3E6C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C30, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of SP APPEAR 1 */
const u16 yang_exca_062_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_062[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3E6B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3E6C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C42, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C42, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of SP APPEAR 3, JUDGMENT WIN */
const u16 yang_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_063[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6C, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6D, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6D, 0, 285, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6E, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of SP APPEAR 3, JUDGMENT WIN */
const u16 yang_exca_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_064[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6C, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3C6D, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6E, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 follow-up of SP APPEAR 4 */
const u16 yang_exca_065_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_065[100] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x3F12, 0, 182, 0, 0, 0, 21, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3F13, 0, 182, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3F14, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3F15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 follow-up of SP APPEAR 4 */
const u16 yang_exca_066_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_066[112] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x3F12, 0, 182, 0, 0, 0, 21, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3F13, 0, 182, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3F14, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 22, 32, 0, 0, 210, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name, 23 no name, 55 no name, 57 no name ... */
const u16 yang_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_022[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CD7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 follow-up of ZANNEN 1 */
const u16 yang_exca_073_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_073[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C15, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C16, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E9C, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3E9D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 follow-up of ZANNEN 1 */
const u16 yang_exca_074_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_074[52] = {
    L4(1, 64, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 follow-up of SP WIN 5 */
const u16 yang_exca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_075[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E05, 0, 146, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3E06, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 follow-up of SP WIN 5 */
const u16 yang_exca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_076[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3E06, 0, 146, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C30, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 follow-up of HUMI ASIB */
const u16 yang_exca_077_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_077[100] = {
    CMD(CM_PA_X, 0, 10240, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 follow-up of GILL IMPACT C */
const u16 yang_exca_078_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_078[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 follow-up of GILL IMPACT C */
const u16 yang_exca_079_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yang_exca_079[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D29, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3D2C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3D2D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x3D2E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x3D2F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x3D30, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x3D31, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3D32, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3D70, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 follow-up of APPEAR 6 */
const u16 yang_exca_080_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_080[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C30, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 81 follow-up of APPEAR 6 */
const u16 yang_exca_081_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_081[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 HANASARE */
const u16 yang_exca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_082[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6C, 0, 285, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6D, 0, 285, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6E, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 HANASARE */
const u16 yang_exca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_083[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3E6B, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E6C, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E6D, 0, 286, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 HANASARE */
const u16 yang_exca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_084[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C31, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 85 HANASARE */
const u16 yang_exca_085_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_085[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 HANASARE */
const u16 yang_exca_086_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_086[36] = {
    L4(1, 3, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 HANASARE */
const u16 yang_exca_087_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_087[36] = {
    L4(1, 3, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 HANASARE */
const u16 yang_exca_088_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_088[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3FBB, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3FBC, 0, 285, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3FBD, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3FBE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3FBF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 HANASARE */
const u16 yang_exca_089_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_089[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3FBB, 0, 285, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3FBC, 0, 285, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x3FBD, 0, 286, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3FBE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x3FBF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 HANASARE, 92 HANASARE */
const u16 yang_exca_090_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_090[124] = {
    L6(1, 2, 0, 0, 0, 0, 0, 0x3CD2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 286, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3CD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3CD4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3CD5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3CD6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3CD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 HANASARE, 93 HANASARE */
const u16 yang_exca_091_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_091[100] = {
    L6(1, 2, 273, 0, 0, 0, 0, 0x3CD2, 0, 1, 0, 0, 0, 21, 0, 0, 0, 286, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x3CD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 HANASARE */
const u16 yang_exca_094_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_094[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E9C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E9D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 95 HANASARE */
const u16 yang_exca_095_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_095[76] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x3E9B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E9C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3E9D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x3C31, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x3C32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C33, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C34, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 HANASARE */
const u16 yang_exca_096_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_096[60] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3EFC, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 HANASARE */
const u16 yang_exca_097_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yang_exca_097[20] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x3EFC, 0, 1, 0, 0, 0, 21, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C35, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 HANASARE */
const u16 yang_exca_098_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_098[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 99 HANASARE */
const u16 yang_exca_099_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_exca_099[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x3C6D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C6E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C6F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 HANASARE */
const u16 yang_exca_100_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yang_exca_100[140] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9C, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9B, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F9A, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F99, 0, 348, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F98, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F97, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x3F96, 0, 348, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C88, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C89, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C8A, 0, 348, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8B, 0, 349, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C8C, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 110 entries */
const u16* const yang_saca[111] = {
    yang_saca_000,  /* 0 UP P GUARD P S */
    yang_saca_001,  /* 1 UP P GUARD P M */
    yang_saca_002,  /* 2 UP P GUARD P L */
    yang_saca_002,  /* 3 UP P GUARD K S */
    yang_saca_002,  /* 4 UP P GUARD K M */
    yang_saca_002,  /* 5 UP P GUARD K L */
    yang_saca_000,  /* 6 D P GUARD P S */
    yang_saca_001,  /* 7 D P GUARD P M */
    yang_saca_002,  /* 8 D P GUARD P L */
    yang_saca_002,  /* 9 D P GUARD K S */
    yang_saca_002,  /* 10 D P GUARD K M */
    yang_saca_002,  /* 11 D P GUARD K L */
    yang_saca_002,  /* 12 FUSHIN P S */
    yang_saca_002,  /* 13 FUSHIN P M */
    yang_saca_002,  /* 14 FUSHIN P L */
    yang_saca_002,  /* 15 FUSHIN K S */
    yang_saca_002,  /* 16 FUSHIN K M */
    yang_saca_002,  /* 17 FUSHIN K L */
    yang_saca_002,  /* 18 OKIAGARI P S */
    yang_saca_002,  /* 19 OKIAGARI P M */
    yang_saca_002,  /* 20 OKIAGARI P L */
    yang_saca_002,  /* 21 OKIAGARI K S */
    yang_saca_002,  /* 22 OKIAGARI K M */
    yang_saca_002,  /* 23 OKIAGARI K L */
    yang_saca_024,  /* 24 ATTACK 1 S: not started by a command */
    yang_saca_024,  /* 25 ATTACK 1 M: not started by a command */
    yang_saca_024,  /* 26 ATTACK 1 L: not started by a command */
    yang_saca_024,  /* 27 ATTACK 1 SP: not started by a command */
    yang_saca_028,  /* 28 ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    yang_saca_028,  /* 29 ATTACK 2 M: 214+P light/medium/heavy (plain script) */
    yang_saca_028,  /* 30 ATTACK 2 L: 214+P light/medium/heavy (plain script) */
    yang_saca_031,  /* 31 ATTACK 2 SP: EX 214+PP (plain script) */
    yang_saca_032,  /* 32 ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_033,  /* 33 ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_034,  /* 34 ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_035,  /* 35 ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_036,  /* 36 ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP) */
    yang_saca_037,  /* 37 ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP) */
    yang_saca_038,  /* 38 ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) */
    yang_saca_039,  /* 39 ATTACK 4 SP: EX 236+PP (routine Att_SLIDE_and_JUMP) */
    yang_saca_040,  /* 40 ATTACK 5 S: not started by a command */
    yang_saca_040,  /* 41 ATTACK 5 M: not started by a command */
    yang_saca_040,  /* 42 ATTACK 5 L: not started by a command */
    yang_saca_040,  /* 43 ATTACK 5 SP: not started by a command */
    yang_saca_044,  /* 44 ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_044,  /* 45 ATTACK 6 M: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_044,  /* 46 ATTACK 6 L: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_044,  /* 47 ATTACK 6 SP: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_048,  /* 48 ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_048,  /* 49 ATTACK 7 M: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_048,  /* 50 ATTACK 7 L: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_048,  /* 51 ATTACK 7 SP: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_052,  /* 52 ATTACK 8 S: not started by a command */
    yang_saca_052,  /* 53 ATTACK 8 M: not started by a command */
    yang_saca_052,  /* 54 ATTACK 8 L: not started by a command */
    yang_saca_052,  /* 55 ATTACK 8 SP: not started by a command */
    yang_saca_056,  /* 56 ATTACK 9 S: 6(123)4+K (plain script) */
    yang_saca_056,  /* 57 ATTACK 9 M: 6(123)4+K (plain script) */
    yang_saca_056,  /* 58 ATTACK 9 L: 6(123)4+K (plain script) */
    yang_saca_056,  /* 59 ATTACK 9 SP: 6(123)4+K (plain script) */
    yang_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    yang_saca_061,  /* 61 ATTACK 10 M: SA III 23623+P (plain script) */
    yang_saca_061,  /* 62 ATTACK 10 L: SA III 23623+P (plain script) */
    yang_saca_061,  /* 63 ATTACK 10 SP: SA III 23623+P (plain script) */
    yang_saca_061,  /* 64 ATTACK 11 S: SA III 23623+P (plain script) */
    yang_saca_065,  /* 65 ATTACK 11 M: not started by a command */
    yang_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    yang_saca_067,  /* 67 ATTACK 11 SP: not started by a command */
    yang_saca_068,  /* 68 ATTACK 12 S: not started by a command */
    yang_saca_069,  /* 69 ATTACK 12 M: not started by a command */
    yang_saca_070,  /* 70 ATTACK 12 L: not started by a command */
    yang_saca_070,  /* 71 ATTACK 12 SP: not started by a command */
    yang_saca_070,  /* 72 ATTACK 13 S: not started by a command */
    yang_saca_070,  /* 73 ATTACK 13 M: not started by a command */
    yang_saca_074,  /* 74 ATTACK 13 L: not started by a command */
    yang_saca_075,  /* 75 ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    yang_saca_076,  /* 76 not started by a command */
    yang_saca_076,  /* 77 not started by a command */
    yang_saca_076,  /* 78 not started by a command */
    yang_saca_076,  /* 79 not started by a command */
    yang_saca_080,  /* 80 not started by a command */
    yang_saca_080,  /* 81 not started by a command */
    yang_saca_080,  /* 82 not started by a command */
    yang_saca_083,  /* 83 not started by a command */
    yang_saca_083,  /* 84 not started by a command */
    yang_saca_083,  /* 85 not started by a command */
    yang_saca_083,  /* 86 not started by a command */
    yang_saca_087,  /* 87 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_088,  /* 88 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_089,  /* 89 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_089,  /* 90 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_091,  /* 91 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_092,  /* 92 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_093,  /* 93 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_094,  /* 94 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_094,  /* 95 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_096,  /* 96 not started by a command */
    yang_saca_097,  /* 97 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_098,  /* 98 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_099,  /* 99 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_100,  /* 100 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_101,  /* 101 not started by a command */
    yang_saca_102,  /* 102 623+K light (routine Att_PL10_MACH_SLIDE2) */
    yang_saca_103,  /* 103 623+K medium (routine Att_PL10_MACH_SLIDE2) */
    yang_saca_104,  /* 104 623+K heavy/EX (routine Att_PL10_MACH_SLIDE2) */
    yang_saca_104,  /* 105 623+K heavy/EX (routine Att_PL10_MACH_SLIDE2) */
    yang_saca_106,  /* 106 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_107,  /* 107 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_108,  /* 108 after 236+P (routine Att_SLIDE_and_JUMP) */
    yang_saca_109,  /* 109 not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 yang_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DE, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DF, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E0, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E1, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E2, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E3, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E4, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E5, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E6, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x70E8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -2048, 6144), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 yang_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 yang_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x70E8, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x70E7, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x70E7, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E6, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E5, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E4, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E3, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E2, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E1, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70E0, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DF, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x70DE, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 yang_saca_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_002[12] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x3C01, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: not started by a command, 25 ATTACK 1 M: not started by a command, 26 ATTACK 1 L: not started by a command, 27 ATTACK 1 SP: not started by a command */
const u16 yang_saca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_024[220] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 214+P light/medium/heavy (plain script), 29 ATTACK 2 M: 214+P light/medium/heavy (plain script), 30 ATTACK 2 L: 214+P light/medium/heavy (plain script) */
const u16 yang_saca_028_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 0) };
const u16 yang_saca_028[292] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE0, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE6, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE7, 0, 202, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 649, 0, 0, 0, 0, 0x3FC0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3FC1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 639, 0, 0, 0, 0, 0x3FC2, -22, 113, 0, 144, 64, 1, 104, 0, 0, 310, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x3FC3, 22, 114, 0, 144, 64, 30, 43, 0, 0, 312, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3FC4, 23, 115, 0, 0, 64, 30, 29, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FC5, 23, 218, 0, 0, 64, 0, 0, 0, 0, 314, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FC6, 0, 218, 0, 0, 0, 21, 0, 0, 0, 316, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3FC7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x3FC8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 214+PP (plain script) */
const u16 yang_saca_031_head[4] = { HEAD(6, 0, 14, 9, 0, 0, 0) };
const u16 yang_saca_031[160] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3EE0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_032_head[4] = { HEAD(6, 0, 9, 10, 0, 2, 29) };
const u16 yang_saca_032[220] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 32, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 50, 0, 0, 0, 0, 0, 0x3D72, 0, 125, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFF, 0, 125, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(3, 0, 647, 0, 0, 0, 0, 0x3F00, 0, 126, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, -28, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F02, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, -29, 129, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, 30, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_033_head[4] = { HEAD(6, 0, 11, 10, 0, 2, 29) };
const u16 yang_saca_033[328] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 33, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EF0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 142, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 194, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x3EFF, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 647, 0, 0, 0, 0, 0x3F00, 0, 194, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, -57, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F02, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, -58, 129, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, 59, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_034_head[4] = { HEAD(6, 0, 13, 10, 0, 2, 29) };
const u16 yang_saca_034[496] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 34, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EF0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x3EFF, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 40, 647, 0, 0, 0, 0, 0x3F00, 0, 194, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, -60, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x3F02, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, -61, 129, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, 62, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_035_head[4] = { HEAD(6, 0, 15, 10, 0, 3, 29) };
const u16 yang_saca_035[496] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 35, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 88, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EF0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x3EFF, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 40, 647, 0, 0, 0, 0, 0x3F00, 0, 194, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, -132, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x3F02, -133, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, -134, 247, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, 134, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_036_head[4] = { HEAD(6, 0, 8, 14, 0, 3, 53) };
const u16 yang_saca_036[700] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 87, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 79, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4019, 0, 230, 6256, 0, 136, 31, 1, 0, 0, 504, 0, 0),
    L6(1, 0, 649, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401B, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 270, 0, 0, 0, 0, 0x401C, 0, 230, 6256, 0, 136, 30, 50, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x401D, -138, 231, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401E, 158, 232, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x401F, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4020, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4021, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 396, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 92, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 80, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4022, 0, 233, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4025, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 274, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4027, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 650, 0, 0, 0, 0, 0x4028, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4029, 0, 233, 6256, 0, 136, 30, 50, 0, 0, 276, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x402A, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 278, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x402B, -139, 234, 6256, 0, 136, 31, 1, 0, 0, 280, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x402C, 159, 235, 6256, 0, 136, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402D, 0, 233, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402E, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402F, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4030, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4031, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4032, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4035, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4036, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4037, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(1, 0, 651, 0, 0, 0, 0, 0x4038, 0, 236, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4039, 0, 236, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403A, 0, 236, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403B, 0, 236, 0, 0, 0, 1, 108, 0, 0, 298, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x40E8, -140, 237, 0, 128, 0, 30, 50, 0, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 106, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 238, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 239, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 239, 0, 0, 0, 21, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(8, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_037_head[4] = { HEAD(6, 0, 10, 13, 0, 3, 53) };
const u16 yang_saca_037[700] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 37, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 88, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 79, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4019, 0, 230, 6256, 0, 136, 31, 1, 0, 0, 504, 0, 0),
    L6(1, 0, 649, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401B, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x401C, 0, 230, 6256, 0, 136, 30, 50, 0, 0, 0, 0, 0),
    L6(5, 0, 270, 0, 0, 0, 0, 0x401D, -141, 231, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401E, 160, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x401F, 0, 232, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4020, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4021, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 396, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 93, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 80, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4022, 0, 233, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4024, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4025, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 274, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4027, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 650, 0, 0, 0, 0, 0x4028, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4029, 0, 233, 6256, 0, 136, 30, 50, 0, 0, 276, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x402A, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 278, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x402B, -142, 234, 6256, 0, 136, 31, 1, 0, 0, 280, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x402C, 161, 235, 6256, 0, 136, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402D, 0, 233, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402E, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402F, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4030, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4031, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4032, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4035, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4036, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4037, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(1, 0, 651, 0, 0, 0, 0, 0x4038, 0, 236, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4039, 0, 236, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403A, 0, 236, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403B, 0, 236, 0, 0, 0, 1, 108, 0, 0, 298, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x40E8, -143, 237, 0, 128, 0, 30, 50, 0, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 107, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 238, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 239, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 239, 0, 0, 0, 21, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(9, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_038_head[4] = { HEAD(6, 0, 12, 13, 0, 3, 53) };
const u16 yang_saca_038[700] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 38, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 89, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 79, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4019, 0, 230, 6256, 0, 136, 31, 1, 0, 0, 504, 0, 0),
    L6(1, 0, 649, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401B, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 270, 0, 0, 0, 0, 0x401C, 0, 230, 6256, 0, 136, 30, 50, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x401D, -144, 231, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x401E, 162, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x401F, 0, 232, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4020, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4021, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 396, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 94, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 80, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4022, 0, 233, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4024, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4025, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 274, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4026, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4027, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 650, 0, 0, 0, 0, 0x4028, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4029, 0, 233, 6256, 0, 136, 30, 50, 0, 0, 276, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x402A, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 278, 0, 0),
    L6(5, 0, 270, 0, 0, 0, 0, 0x402B, -145, 234, 6256, 0, 136, 31, 1, 0, 0, 280, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x402C, 163, 235, 6256, 0, 136, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402D, 0, 233, 6256, 0, 136, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402E, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402F, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4030, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4031, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4032, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4035, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4036, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4037, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(1, 0, 651, 0, 0, 0, 0, 0x4038, 0, 236, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4039, 0, 236, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403A, 0, 236, 0, 0, 0, 0, 0, 0, 0, 296, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403B, 0, 236, 0, 0, 0, 1, 108, 0, 0, 298, 0, 0),
    L6(4, 30, 0, 0, 0, 0, 0, 0x40E8, -146, 237, 0, 128, 0, 30, 50, 0, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 108, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 238, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 239, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 239, 0, 0, 0, 21, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(10, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 236+PP (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_039_head[4] = { HEAD(6, 0, 14, 13, 0, 5, 53) };
const u16 yang_saca_039[892] = {
    CMD(CM_JSR, 8, 87, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 83, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 97, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4019, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 504, 0, 0),
    L6(1, 0, 649, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401B, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 30, 270, 0, 0, 0, 0, 0x401C, 0, 230, 6256, 0, 136, 30, 50, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401D, -147, 246, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401E, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x401F, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4020, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4021, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 396, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 84, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 98, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x4024, 0, 233, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 650, 0, 0, 0, 0, 0x4028, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4029, 0, 233, 6256, 0, 136, 30, 50, 0, 0, 276, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x402A, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 278, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402B, -148, 234, 6256, 0, 136, 31, 1, 0, 0, 280, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x402C, 0, 235, 6256, 0, 136, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x402F, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4030, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4031, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 85, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 99, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x4019, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 504, 0, 0),
    L6(1, 0, 649, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x401A, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x401B, 0, 230, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 270, 0, 0, 0, 0, 0x401C, 0, 230, 6256, 0, 136, 30, 50, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401D, -148, 231, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x401E, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x401F, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4020, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4021, 0, 232, 6256, 0, 136, 0, 0, 0, 0, 396, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 8, 86, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 100, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 21, 0, 0, 0, 0, 0, 0x4024, 0, 233, 6256, 0, 136, 31, 1, 0, 0, 0, 0, 0),
    L6(1, 0, 650, 0, 0, 0, 0, 0x4028, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4029, 0, 233, 6256, 0, 136, 30, 50, 0, 0, 276, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x402A, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 278, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x402B, -148, 234, 6256, 0, 136, 31, 1, 0, 0, 280, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x402C, 0, 235, 6256, 0, 136, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x402F, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4030, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4031, 0, 233, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4032, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x4036, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 0, 651, 0, 0, 0, 0, 0x4038, 0, 236, 0, 0, 0, 0, 0, 0, 0, 292, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4039, 0, 236, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x403A, 0, 236, 0, 0, 0, 1, 108, 0, 0, 296, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x40E8, -149, 237, 0, 128, 0, 30, 50, 0, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 91, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8197, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 238, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 239, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 239, 0, 0, 0, 21, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: not started by a command, 41 ATTACK 5 M: not started by a command, 42 ATTACK 5 L: not started by a command, 43 ATTACK 5 SP: not started by a command */
const u16 yang_saca_040_head[4] = { HEAD(6, 0, 33, 15, 0, 4, 0) };
const u16 yang_saca_040[604] = {
    CMD(CM_RJA, 5, 40, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_STOP, -50, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 644, 0, 0, 0, 0, 0x3F20, 0, 189, 0, 0, 0, 13, 3, 0, 0, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F21, 0, 189, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(36, 0, 0, 0, 0, 0, 0, 0x3F22, 0, 189, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x3F23, 0, 189, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 648, 0, 0, 0, 0, 0x3F24, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F25, -24, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F26, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 648, 0, 0, 0, 0, 0x3F27, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F28, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F29, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F2A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F2B, -25, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F2C, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F2D, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F2E, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F2F, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(255, 0, 0, 0, 0, 0, 0, 0x3F30, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F31, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 647, 0, 0, 0, 0, 0x3E10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E11, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E12, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E13, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E14, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    CMD(CM_RJA, 7, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x3E17, -26, 120, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3E18, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x3E19, 27, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 30, 0, 0, 0, 0, 0, 0x3E1A, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3E1B, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3E1C, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EA0, -72, 171, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EA1, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EA2, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EA3, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EA4, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EA5, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3EA6, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3E1D, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), 45 ATTACK 6 M: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), 46 ATTACK 6 L: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), 47 ATTACK 6 SP: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_044_head[4] = { HEAD(4, 0, 33, 11, 0, 7, 36) };
const u16 yang_saca_044[936] = {
    CMD(CM_JSR, 8, 47, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 198, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 652, 0, 0, 0, 0, 0x3EF0, -53, 189, 0, 0, 0, 13, 4),
    CMD(CM_ASXY, 200, 0, 0), 0, 0, 0, 0,
    L4(50, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 156, 0, 151, 0, 30, 37),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 156, 0, 151, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 156, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 156, 0, 151, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 5, 75, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0020, 0x0F00, 0x0736,
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 644, 0, 0, 0, 0, 0x4047, 0, 189, 0, 0, 0, 13, 45),
    L4(3, 11, 0, 0, 0, 0, 0, 0x0000, 24, 1, 2256, 0, 0, 64, 72),
    CMD(CM_UJA4, -24576, 0, 0), 0x030B, 0x0000, 0x0000, 0x0000,
    L4(8, 0, 0, 0, 0, 0, 0, 0x4049, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 11, 0, 0, 0, 0, 0, 0x0000, 80, 0, 0, 0, 0, 64, 74),
    CMD(CM_UJA4, -24576, 0, 0), 0x030B, 0x0000, 0x0000, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4048, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 11, 0, 0, 0, 0, 0, 0x0000, 8, 240, 0, 0, 0, 64, 75),
    CMD(CM_UJA4, -24576, 0, 0), 0x030B, 0x0000, 0x0000, 0x0000,
    L4(1, 0, 617, 0, 0, 0, 0, 0x404C, 0, 189, 0, 0, 0, 1, 109),
    L4(3, 12, 0, 0, 0, 0, 0, 0x0000, 4, 168, 0, 0, 0, 64, 76),
    CMD(CM_UJA4, -24576, 0, 7723), 0x030C, 0x0000, 0x0000, 0x0000,
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x404D,
    L4(218, 30, 512, 0, 0, 1264, 0, 0x0000, 12, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x404E, 0, 242, 0, 79, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x0000, 24, 0, 0, 0, 0, 64, 79),
    CMD(CM_RMJA, 16384, 16384, 0), 0x030C, 0x0000, 0x0000, 0x0000,
    CMD(CM_HJMP, 8194, 8192, 8192), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x404F,
    CMD(CM_RMJA, 24576, 16384, 5376), 0x030C, 0x0000, 0x0000, 0x0000,
    L4(8, 0, 0, 0, 0, 0, 0, 0x4050, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0700, 0x0000, 0x0000, 0x4051,
    CMD(CM_RMJA, 24576, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x4052, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x3C36,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x3C38,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 32, 3840, 1590), 0x0100, 0x0000, 0x0000, 0x404D,
    CMD(CM_RMJA, 8192, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x404E, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x404F,
    CMD(CM_RMJA, 16384, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4050, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x4051,
    CMD(CM_RMJA, 24576, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4052, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x4053,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4054, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x4055,
    CMD(CM_RMJA, -32768, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4056, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x4057,
    CMD(CM_RMJA, -32768, 0, 0), 0, 0, 0, 0,
    L4(1, 30, 0, 0, 0, 0, 0, 0x4058, 0, 244, 0, 0, 0, 1, 107),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x4059,
    CMD(CM_RMJA, -32768, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x405A, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x405B,
    L4(217, 222, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x405C, -154, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x405D,
    L4(217, 222, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x405E, -154, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x405F,
    L4(217, 222, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x4060, -155, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x4061,
    CMD(CM_RMJA, -24576, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x4062, 0, 245, 0, 128, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0115, 0x0000, 0x0000, 0x4063,
    CMD(CM_RMJA, -24576, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4064, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x000C, 0x0000, 0x0000, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x4065, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x4066,
    CMD(CM_RMJA, -24576, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x4067, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x4068,
    CMD(CM_RMJA, -24576, 0, 0), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x4069,
    CMD(CM_DUMMY, 8192, 0, 5376), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x406A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x406B,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x406C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 408, 0), 0x0200, 0x0000, 0x0000, 0x3C36,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x019A, 0x0000,
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0200, 0x0000, 0x0000, 0x3C38,
    CMD(CM_DUMMY, 8192, 0, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 56 ATTACK 9 S: 6(123)4+K (plain script), 57 ATTACK 9 M: 6(123)4+K (plain script), 58 ATTACK 9 L: 6(123)4+K (plain script), 59 ATTACK 9 SP: 6(123)4+K (plain script) */
const u16 yang_saca_056_head[4] = { HEAD(6, 0, 24, 13, 0, 0, 74) };
const u16 yang_saca_056[160] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB2, -43, 186, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F1C, 0, 193, 0, 0, 0, 21, 0, 0, 0, 404, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F1D, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F1E, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F1C, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command */
const u16 yang_saca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_060[220] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3EFE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: SA III 23623+P (plain script), 62 ATTACK 10 L: SA III 23623+P (plain script), 63 ATTACK 10 SP: SA III 23623+P (plain script), 64 ATTACK 11 S: SA III 23623+P (plain script) */
const u16 yang_saca_061_head[4] = { HEAD(6, 0, 32, 8, 0, 0, 0) };
const u16 yang_saca_061[792] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F40, 0, 189, 0, 0, 0, 13, 3, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F41, 0, 189, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F42, 0, 189, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 652, 0, 0, 0, 0, 0x3F43, 0, 189, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F44, 0, 189, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F45, 0, 189, 0, 0, 0, 19, 0, 785, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 61, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(39, 0, 0, 0, 0, 0, 0, 0x3F46, 0, 189, 0, 0, 0, 1, 62, 785, 0, 0, 0, 0),
    CMD(CM_IMGS, 0, 16, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F42, 0, 1, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F41, 0, 1, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0021, 0x0000, 0x0600, 0x0010, 0x0005, 0x0028, 0x0016,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x003D, 0xFFCE, 0x0039, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2840, 0x0000, 0x3F20,
    CMD(CM_UJA4, -24576, 0, 3331), 0x0000, 0x0000, 0x0048, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F21,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x2400, 0x0000, 0x0000, 0x3F22,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0114, 0x0000, 0x0000, 0x3F23,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x0048, 0x0000, 0x000C, 0x0000, 0x0000, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x2880, 0x0000, 0x3F24,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F25,
    L6(250, 14, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 63, 38),
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2880, 0x0000, 0x3F27,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F28,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F29,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x3F2A,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3F2B,
    L6(249, 206, 3072, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 63, 44),
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F2D,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x3F2E,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3F2F,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0x0000, 0x0000, 0x3F30,
    CMD(CM_FOR2, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x3F31,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0228, 0x0000, 0x0000, 0x3C41,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2870, 0x0000, 0x3E10,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E11,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E12,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E13,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0048, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E14,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E15,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E16,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0010, 0x0007, 0x0018, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0007, 0x000C, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0214, 0x0000, 0x0000, 0x3E17,
    L6(249, 143, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 74, 0, 0, 768, 0, 0, 62, 24),
    CMD(CM_NEX2, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3E19,
    L6(6, 207, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 62, 26),
    CMD(CM_NEX2, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x3E1B,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3E1C,
    CMD(CM_NEX2, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x3E9E,
    CMD(CM_RJA3, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x3E9F,
    CMD(CM_RJA3, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x021E, 0x0000, 0x0000, 0x3EA0,
    L6(238, 15, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 62, 161),
    L6(18, 15, 0, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 62, 162),
    L6(18, 15, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 62, 163),
    L6(18, 21, 512, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 62, 164),
    L6(18, 21, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 62, 165),
    L6(18, 21, 512, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 62, 166),
    L6(18, 21, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 64000, 0, 0, 62, 29),
    CMD(CM_NEX2, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 65 ATTACK 11 M: not started by a command */
const u16 yang_saca_065_head[4] = { HEAD(6, 0, 33, 10, 0, 1, 0) };
const u16 yang_saca_065[280] = {
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 648, 0, 0, 0, 0, 0x3EE8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 617, 0, 0, 0, 0, 0x3EEA, -80, 113, 0, 143, 0, 1, 16, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EEA, 80, 113, 0, 143, 0, 30, 43, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EEB, 80, 114, 0, 0, 0, 30, 29, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EEC, 80, 115, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EED, 0, 115, 0, 0, 32, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3EEE, 0, 1, 0, 0, 0, 21, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EEF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command */
const u16 yang_saca_066_head[4] = { HEAD(6, 0, 33, 10, 0, 4, 29) };
const u16 yang_saca_066[220] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 66, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 50, 647, 0, 0, 0, 0, 0x3D72, 0, 125, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x3EFF, 0, 125, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F00, 0, 126, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, -81, 127, 0, 0, 0, 30, 6, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F02, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, -81, 129, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, -81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F05, -81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F05, 81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: not started by a command */
const u16 yang_saca_067_head[4] = { HEAD(6, 0, 35, 10, 0, 5, 29) };
const u16 yang_saca_067[304] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 67, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 50, 0, 0, 0, 0, 0, 0x3EF0, 0, 124, 0, 0, 64, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 0, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF3, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 647, 0, 0, 0, 0, 0x3EF4, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EFF, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 0, 0, 0, 0, 0, 0x3F00, 0, 217, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, 0, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F02, -81, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, 0, 129, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, -81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F04, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F05, -81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: not started by a command */
const u16 yang_saca_068_head[4] = { HEAD(6, 0, 37, 10, 0, 6, 29) };
const u16 yang_saca_068[400] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 34, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 50, 0, 0, 0, 0, 0, 0x3EF0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x3EF2, 0, 194, 0, 0, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF3, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF6, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF7, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF8, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF9, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EFA, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EFB, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF2, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 647, 0, 0, 0, 0, 0x3EF3, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF4, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF5, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EF6, -96, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x3EFF, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 0, 0, 0, 0, 0, 0x3F00, 0, 217, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F01, 0, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F02, -81, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x3F03, 0, 129, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F04, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F05, -81, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F1F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: not started by a command */
const u16 yang_saca_069_head[4] = { HEAD(6, 0, 33, 12, 0, 3, 31) };
const u16 yang_saca_069[268] = {
    CMD(CM_RJA, 5, 69, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F40, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 646, 0, 0, 0, 0, 0x3F41, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F42, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F43, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F44, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F45, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F46, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x3F47, -98, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F48, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F48, -97, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F49, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3F49, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3F4A, -97, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x3F4B, 0, 112, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F4C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F4D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3F4E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C3A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C39, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: not started by a command, 71 ATTACK 12 SP: not started by a command, 72 ATTACK 13 S: not started by a command, 73 ATTACK 13 M: not started by a command */
const u16 yang_saca_070_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 33) };
const u16 yang_saca_070[108] = {
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3CB1, 0, 334, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x3E6D, 0, 131, 0, 0, 0, 22, 20),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3E6E, 0, 131, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E71, -165, 203, 0, 136, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E72, 0, 203, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E73, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E74, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: not started by a command */
const u16 yang_saca_074_head[4] = { HEAD(6, 0, 8, 13, 0, 1, 0) };
const u16 yang_saca_074[148] = {
    CMD(CM_CAFR, 2, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB2, -43, 186, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x3F1C, 0, 193, 0, 0, 0, 0, 0, 0, 0, 404, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F1D, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3F1E, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3F1C, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EB1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EB0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
const u16 yang_saca_075_head[4] = { HEAD(4, 0, 33, 10, 0, 6, 36) };
const u16 yang_saca_075[324] = {
    L4(2, 50, 647, 0, 0, 0, 0, 0x3EFF, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 40, 0, 0, 0, 0, 0, 0x3F00, -54, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F01, 54, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F02, -55, 199, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x3F03, -56, 213, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F04, 56, 129, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F05, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F06, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F07, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F08, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F09, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3F0A, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 648, 0, 0, 0, 0, 0x3F24, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3E17, -26, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E18, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E19, 26, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E1A, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E1B, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 647, 0, 0, 0, 0, 0x3E1C, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EA0, -75, 120, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EA1, 0, 120, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3EA2, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 644, 0, 0, 0, 0, 0x3EA3, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E9F, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E9E, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E17, -27, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E18, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E19, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E1A, 0, 122, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3E1B, 0, 116, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C68, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C69, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C6A, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6C, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C6B, 0, 116, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 not started by a command, 77 not started by a command, 78 not started by a command, 79 not started by a command */
const u16 yang_saca_076_head[4] = { HEAD(4, 20, 36, 8, 0, 1, 33) };
const u16 yang_saca_076[100] = {
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E6D, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E6E, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 12, 0x3E6F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x3E71, -131, 203, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E72, 0, 203, 0, 128, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x3E73, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E74, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E75, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E76, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x3E77, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 not started by a command, 81 not started by a command, 82 not started by a command */
const u16 yang_saca_080_head[4] = { HEAD(4, 0, 0, 6, 0, 1, 0) };
const u16 yang_saca_080[260] = {
    L4(3, 0, 2048, 0, 0, 0, 0, 0x3FF8, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3FF9, 0, 1, 0, 0, 0, 32, 162),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3FFA, 0, 1, 0, 0, 0, 32, 163),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3FFB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3FFC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 40, 0, 0, 0, 0, 0, 0x3FFD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3FFE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3FFF, -137, 229, 0, 139, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4001, 0, 229, 0, 139, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4002, 0, 229, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4003, 0, 229, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4004, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4005, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4006, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4007, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4008, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4009, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x400A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x400B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x400C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x400D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x400E, 0, 1, 0, 0, 0, 32, 164),
    L4(2, 0, 0, 0, 0, 0, 0, 0x400F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4010, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x4011, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x4012, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4014, 0, 1, 0, 0, 0, 32, 164),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4017, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x4017, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 not started by a command, 84 not started by a command, 85 not started by a command, 86 not started by a command */
const u16 yang_saca_083_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_083[172] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE2, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3EE1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x3EE0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3EE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_087_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_087[76] = {
    CMD(CM_RMJA, 8, 81, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_088_head[4] = { HEAD(6, 0, 10, 13, 0, 0, 53) };
const u16 yang_saca_088[76] = {
    CMD(CM_RMJA, 8, 81, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 after 236+P (routine Att_SLIDE_and_JUMP), 90 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_089_head[4] = { HEAD(6, 0, 12, 13, 0, 0, 53) };
const u16 yang_saca_089[76] = {
    CMD(CM_RMJA, 8, 81, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_091_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_091[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 240, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 240, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 240, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_092_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_092[76] = {
    CMD(CM_RMJA, 8, 82, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 93 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_093_head[4] = { HEAD(6, 0, 10, 13, 0, 0, 53) };
const u16 yang_saca_093[76] = {
    CMD(CM_RMJA, 8, 82, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 after 236+P (routine Att_SLIDE_and_JUMP), 95 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_094_head[4] = { HEAD(6, 0, 12, 13, 0, 0, 53) };
const u16 yang_saca_094[76] = {
    CMD(CM_RMJA, 8, 82, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 not started by a command */
const u16 yang_saca_096_head[4] = { HEAD(2, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_096[184] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x4019),
    L2(3, 0, 0, 0, 0, 0, 0, 0x401A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x401B),
    L2(2, 30, 0, 0, 0, 0, 0, 0x401C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x401D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x401E),
    L2(2, 21, 0, 0, 0, 0, 0, 0x401F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4020),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4021),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4022),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4023),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4024),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4025),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4026),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4027),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4028),
    L2(1, 30, 0, 0, 0, 0, 0, 0x4029),
    L2(2, 0, 0, 0, 0, 0, 0, 0x402A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x402B),
    L2(2, 21, 0, 0, 0, 0, 0, 0x402C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x402D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x402E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x402F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4030),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4031),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4032),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4033),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4034),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4035),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4036),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4037),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4038),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4039),
    L2(1, 0, 0, 0, 0, 0, 0, 0x403A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x403B),
    L2(8, 30, 0, 0, 0, 0, 0, 0x403C),
    L2(9, 0, 0, 0, 0, 0, 0, 0x403D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x403E),
    L2(3, 21, 0, 0, 0, 0, 0, 0x403F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4040),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4041),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4042),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4043),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4044),
    L2(5, 0, 0, 0, 0, 0, 0, 0x4045),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_097_head[4] = { HEAD(6, 0, 14, 13, 0, 0, 53) };
const u16 yang_saca_097[76] = {
    CMD(CM_RMJA, 8, 83, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_098_head[4] = { HEAD(6, 0, 14, 13, 0, 0, 53) };
const u16 yang_saca_098[76] = {
    CMD(CM_RMJA, 8, 84, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 99 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_099_head[4] = { HEAD(6, 0, 14, 13, 0, 0, 53) };
const u16 yang_saca_099[76] = {
    CMD(CM_RMJA, 8, 85, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_100_head[4] = { HEAD(6, 0, 14, 13, 0, 0, 53) };
const u16 yang_saca_100[76] = {
    CMD(CM_RMJA, 8, 86, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x4023, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 498, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 500, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 6256, 0, 136, 0, 0, 0, 0, 502, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 101 not started by a command */
const u16 yang_saca_101_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_101[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 240, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 240, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 240, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), 49 ATTACK 7 M: SA I 23623+P (routine Att_SLIDE_and_JUMP), 50 ATTACK 7 L: SA I 23623+P (routine Att_SLIDE_and_JUMP), 51 ATTACK 7 SP: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_048_head[4] = { HEAD(6, 0, 32, 15, 0, 7, 54) };
const u16 yang_saca_048[304] = {
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x4047, 0, 189, 0, 0, 0, 13, 45, 779, 0, 0, 0, 0),
    L6(6, 0, 653, 0, 0, 0, 0, 0x4048, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4049, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(25, 0, 0, 0, 0, 0, 0, 0x404A, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4048, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40A8, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40A9, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(5, 30, 0, 0, 0, 0, 0, 0x40AA, 0, 189, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x40AB, 0, 189, 0, 0, 0, 1, 109, 780, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x40AC, 0, 189, 0, 0, 0, 30, 43, 780, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x40AD, 0, 189, 0, 0, 0, 0, 0, 780, 0, 46, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 383, 0, 0, 0, 0, 0x40AE, -152, 241, 0, 81, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40AF, 0, 242, 0, 81, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_HJMP, 8194, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x406A, 0, 243, 0, 64, 0, 21, 0, 780, 0, 24, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x406B, 0, 243, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x406C, 0, 243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x406D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: not started by a command, 53 ATTACK 8 M: not started by a command, 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command */
const u16 yang_saca_052_head[4] = { HEAD(6, 0, 32, 15, 0, 6, 54) };
const u16 yang_saca_052[436] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x40B0, 0, 244, 0, 0, 0, 1, 142, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40B1, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40B2, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x40B3, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x40B4, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40B5, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40B6, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40B7, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40B8, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x4058, 0, 244, 0, 0, 0, 1, 107, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4059, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x405A, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x405B, -153, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x405C, -154, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x405D, -153, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x405E, -154, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x405F, -153, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 383, 0, 0, 0, 0, 0x4060, -155, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4061, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4062, 0, 245, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x4063, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4064, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x4065, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4066, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4067, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4068, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x4069, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x406A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x406B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x406C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C36, 0, 1, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C37, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 623+K light (routine Att_PL10_MACH_SLIDE2) */
const u16 yang_saca_102_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_102[172] = {
    L6(2, 0, 479, 0, 0, 0, 0, 0x40C9, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40CA, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CB, 0, 230, 0, 0, 0, 1, 108, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x40CC, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CD, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CE, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x40CF, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D0, 0, 267, 0, 0, 0, 0, 0, 0, 0, 462, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 464, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D3, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 103 623+K medium (routine Att_PL10_MACH_SLIDE2) */
const u16 yang_saca_103_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_103[172] = {
    L6(3, 0, 479, 0, 0, 0, 0, 0x40C9, 0, 230, 0, 0, 0, 0, 0, 0, 0, 452, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x40CA, 0, 230, 0, 0, 0, 0, 0, 0, 0, 454, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CB, 0, 230, 0, 0, 0, 1, 108, 0, 0, 456, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x40CC, 0, 230, 0, 0, 0, 0, 0, 0, 0, 458, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CD, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CE, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x40CF, 0, 267, 0, 0, 0, 0, 0, 0, 0, 460, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D0, 0, 267, 0, 0, 0, 0, 0, 0, 0, 462, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 464, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D3, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 623+K heavy/EX (routine Att_PL10_MACH_SLIDE2), 105 623+K heavy/EX (routine Att_PL10_MACH_SLIDE2) */
const u16 yang_saca_104_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yang_saca_104[172] = {
    L6(3, 0, 479, 0, 0, 0, 0, 0x40C9, 0, 230, 0, 0, 0, 0, 0, 0, 0, 452, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x40CA, 0, 230, 0, 0, 0, 0, 0, 0, 0, 454, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40CB, 0, 230, 0, 0, 0, 1, 108, 0, 0, 456, 0, 0),
    L6(3, 30, 0, 0, 0, 0, 0, 0x40CC, 0, 230, 0, 0, 0, 0, 0, 0, 0, 458, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40CD, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40CE, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x40CF, 0, 267, 0, 0, 0, 0, 0, 0, 0, 460, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40D0, 0, 267, 0, 0, 0, 0, 0, 0, 0, 462, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 464, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40D3, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 64, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x40D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_106_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_106[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 240, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 240, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 240, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(8, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 107 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_107_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_107[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 240, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 240, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 240, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(9, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 after 236+P (routine Att_SLIDE_and_JUMP) */
const u16 yang_saca_108_head[4] = { HEAD(6, 0, 8, 13, 0, 0, 53) };
const u16 yang_saca_108[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x40E9, 0, 240, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EA, 0, 240, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EB, 0, 240, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x40EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(10, 21, 0, 0, 0, 0, 0, 0x40EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x40F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4041, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4042, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4043, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4045, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x3C3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 109 not started by a command */
const u16 yang_saca_109_head[4] = { HEAD(2, 0, 10, 13, 0, 3, 53) };
const u16 yang_saca_109[92] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x4035),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4036),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4037),
    L2(1, 0, 651, 0, 0, 0, 0, 0x4038),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4039),
    L2(1, 0, 0, 0, 0, 0, 0, 0x403A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x403B),
    L2(2, 30, 0, 0, 0, 0, 0, 0x40E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40E9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40EA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40EB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40EC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40ED),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40EE),
    L2(8, 21, 0, 0, 0, 0, 0, 0x40EF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x40F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4041),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4042),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4043),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4044),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4045),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3C3E),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 91 entries */
const u16* const yang_cbca[92] = {
    yang_cbca_000,  /* 0 APPEAR JUNBI 1 */
    yang_cbca_001,  /* 1 APPEAR JUNBI 2 */
    yang_cbca_002,  /* 2 APPEAR JUNBI 3 */
    yang_cbca_003,  /* 3 APPEAR JUNBI 4 */
    yang_cbca_004,  /* 4 APPEAR JUNBI 5 */
    yang_cbca_005,  /* 5 APPEAR JUNBI 6 */
    yang_cbca_006,  /* 6 APPEAR JUNBI 7 */
    yang_cbca_006,  /* 7 APPEAR JUNBI 8 */
    yang_cbca_006,  /* 8 APPEAR 1 */
    yang_cbca_006,  /* 9 APPEAR 2 */
    yang_cbca_010,  /* 10 APPEAR 3 */
    yang_cbca_011,  /* 11 APPEAR 4 */
    yang_cbca_012,  /* 12 APPEAR 5 */
    yang_cbca_013,  /* 13 APPEAR 6 */
    yang_cbca_014,  /* 14 APPEAR 7 */
    yang_cbca_015,  /* 15 APPEAR 8 */
    yang_cbca_016,  /* 16 SP APPEAR 1 */
    yang_cbca_017,  /* 17 SP APPEAR 2 */
    yang_cbca_018,  /* 18 SP APPEAR 3 */
    yang_cbca_019,  /* 19 SP APPEAR 4 */
    yang_cbca_020,  /* 20 SP APPEAR 5 */
    yang_cbca_021,  /* 21 SP APPEAR 6 */
    yang_cbca_022,  /* 22 SP APPEAR 7 */
    yang_cbca_023,  /* 23 SP APPEAR 8 */
    yang_cbca_024,  /* 24 ZANNEN 1 */
    yang_cbca_025,  /* 25 ZANNEN 2 */
    yang_cbca_026,  /* 26 ZANNEN 3 */
    yang_cbca_027,  /* 27 ZANNEN 4 */
    yang_cbca_028,  /* 28 ZANNEN 5 */
    yang_cbca_029,  /* 29 ZANNEN 6 */
    yang_cbca_030,  /* 30 ZANNEN 7 */
    yang_cbca_031,  /* 31 ZANNEN 8 */
    yang_cbca_032,  /* 32 WIN 1 */
    yang_cbca_033,  /* 33 WIN 2 */
    yang_cbca_034,  /* 34 WIN 3 */
    yang_cbca_035,  /* 35 WIN 4 */
    yang_cbca_036,  /* 36 WIN 5 */
    yang_cbca_037,  /* 37 WIN 6 */
    yang_cbca_038,  /* 38 WIN 7 */
    yang_cbca_039,  /* 39 WIN 8 */
    yang_cbca_040,  /* 40 SP WIN 1 */
    yang_cbca_041,  /* 41 SP WIN 2 */
    yang_cbca_042,  /* 42 SP WIN 3 */
    yang_cbca_043,  /* 43 SP WIN 4 */
    yang_cbca_044,  /* 44 SP WIN 5 */
    yang_cbca_045,  /* 45 SP WIN 6 */
    yang_cbca_046,  /* 46 SP WIN 7 */
    yang_cbca_047,  /* 47 SP WIN 8 */
    yang_cbca_048,  /* 48 JUDGMENT WAIT */
    yang_cbca_049,  /* 49 JUDGMENT WAIT */
    yang_cbca_050,  /* 50 JUDGMENT WAIT */
    yang_cbca_051,  /* 51 JUDGMENT WAIT */
    yang_cbca_052,  /* 52 JUDGMENT WIN */
    yang_cbca_053,  /* 53 JUDGMENT WIN */
    yang_cbca_054,  /* 54 JUDGMENT WIN */
    yang_cbca_055,  /* 55 JUDGMENT WIN */
    yang_cbca_056,  /* 56 JUDGMENT LOSE */
    yang_cbca_057,  /* 57 JUDGMENT LOSE */
    yang_cbca_058,  /* 58 JUDGMENT LOSE */
    yang_cbca_059,  /* 59 JUDGMENT LOSE */
    yang_cbca_060,  /* 60 WAIT */
    yang_cbca_061,  /* 61 AFRICA JUMP */
    yang_cbca_062,  /* 62 AFRICA LAND */
    yang_cbca_063,  /* 63 SEAN BALL HIT */
    yang_cbca_064,  /* 64 no name */
    yang_cbca_065,  /* 65 BONUS WIN 1 */
    yang_cbca_066,  /* 66 BONUS WIN 2 */
    yang_cbca_067,  /* 67 BONUS WIN 3 */
    yang_cbca_068,  /* 68 APPEAR USE */
    yang_cbca_069,  /* 69 APPEAR USE */
    yang_cbca_070,  /* 70 APPEAR USE */
    yang_cbca_071,  /* 71 APPEAR USE */
    yang_cbca_072,  /* 72 APPEAR USE */
    yang_cbca_073,  /* 73 APPEAR USE */
    yang_cbca_074,  /* 74 APPEAR USE */
    yang_cbca_075,  /* 75 APPEAR USE */
    yang_cbca_075,  /* 76 APPEAR USE */
    yang_cbca_077,  /* 77 APPEAR USE */
    yang_cbca_078,  /* 78 APPEAR USE */
    yang_cbca_079,  /* 79 APPEAR USE */
    yang_cbca_080,  /* 80 APPEAR USE */
    yang_cbca_081,  /* 81 APPEAR USE */
    yang_cbca_082,  /* 82 APPEAR USE */
    yang_cbca_083,  /* 83 APPEAR USE */
    yang_cbca_084,  /* 84 APPEAR USE */
    yang_cbca_085,  /* 85 APPEAR USE */
    yang_cbca_086,  /* 86 APPEAR USE */
    yang_cbca_087,  /* 87 APPEAR USE */
    yang_cbca_088,  /* 88 APPEAR USE */
    yang_cbca_089,  /* 89 APPEAR USE */
    yang_cbca_090,  /* 90 APPEAR USE */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 yang_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 yang_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 yang_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 yang_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 yang_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 yang_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8, 8 APPEAR 1, 9 APPEAR 2 */
const u16 yang_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 49, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 yang_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_010[12] = {
    CMD(CM_RJA, 0, 4, 7),
    CMD(CM_RJA3, 0, 4, 14),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 yang_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 yang_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_012[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 yang_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_013[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 80, 1),
    CMD(CM_RJA3, 7, 81, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 yang_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_014[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 yang_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_015[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 yang_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_016[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 61, 1),
    CMD(CM_RJA3, 7, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 yang_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_017[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 28, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 yang_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_018[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 63, 1),
    CMD(CM_RJA3, 7, 64, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 yang_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_019[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 65, 1),
    CMD(CM_RJA3, 7, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 yang_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_020[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 70, 1),
    CMD(CM_RJA3, 7, 71, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 yang_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_021[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 5),
    CMD(CM_CARE, 2, 1, 5),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 yang_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_022[8] = {
    CMD(CM_RJA6, 4, 8, 4),
    CMD(CM_JMP, 8, 21, 2),
};

/* script: 23 SP APPEAR 8 */
const u16 yang_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_023[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 yang_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 73, 1),
    CMD(CM_RJA3, 7, 74, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 yang_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_025[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 200, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 yang_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_026[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 201, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 yang_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_027[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 203, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 yang_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_028[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 205, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 yang_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_029[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 208, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 yang_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_030[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 209, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 yang_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_031[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 213, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 yang_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_032[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 216, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 yang_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_033[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 218, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 yang_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_034[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 221, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 yang_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_035[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 224, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 yang_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_036[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 227, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 yang_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_037[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 230, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 yang_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_038[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 233, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 yang_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_039[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 65, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 yang_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_040[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 66, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 yang_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_041[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 67, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 yang_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_042[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 68, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 yang_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_043[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 69, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 yang_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 75, 1),
    CMD(CM_RJA3, 7, 76, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 yang_cbca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_045[12] = {
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 yang_cbca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_046[20] = {
    CMD(CM_RJA, 5, 52, 1),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 yang_cbca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_047[32] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 8, 53, 1),
    CMD(CM_RJA3, 8, 54, 1),
    CMD(CM_RJA4, 5, 44, 23),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 yang_cbca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_048[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 217, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 yang_cbca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_049[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 214, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 yang_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_050[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 206, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 yang_cbca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_051[32] = {
    CMD(CM_RJA7, 8, 51, 6),
    CMD(CM_DJMP, 8193, 8192, 8200),
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_UJA6, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_UJA6, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN */
const u16 yang_cbca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_052[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 74, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 53 JUDGMENT WIN */
const u16 yang_cbca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_053[12] = {
    CMD(CM_WCNE, 16399, 0, 16386),
    CMD(CM_JMP, 7, 82, 1),
    CMD(CM_JMP, 7, 63, 1),
};

/* script: 54 JUDGMENT WIN */
const u16 yang_cbca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_054[12] = {
    CMD(CM_WCNE, 16399, 0, 16386),
    CMD(CM_JMP, 7, 83, 1),
    CMD(CM_JMP, 7, 64, 1),
};

/* script: 55 JUDGMENT WIN */
const u16 yang_cbca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_055[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 84, 1),
    CMD(CM_RJA3, 7, 85, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 56 JUDGMENT LOSE */
const u16 yang_cbca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_056[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 86, 1),
    CMD(CM_RJA3, 7, 87, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 57 JUDGMENT LOSE */
const u16 yang_cbca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_057[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 236, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 58 JUDGMENT LOSE */
const u16 yang_cbca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_058[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 238, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 59 JUDGMENT LOSE */
const u16 yang_cbca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_059[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 240, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 yang_cbca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_060[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 242, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 yang_cbca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_061[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 244, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 yang_cbca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_062[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 246, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT */
const u16 yang_cbca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_063[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 248, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 64 no name */
const u16 yang_cbca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_064[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 250, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 65 BONUS WIN 1 */
const u16 yang_cbca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_065[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 252, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 66 BONUS WIN 2 */
const u16 yang_cbca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_066[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 254, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 67 BONUS WIN 3 */
const u16 yang_cbca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_067[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 255, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 68 APPEAR USE */
const u16 yang_cbca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_068[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 256, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 69 APPEAR USE */
const u16 yang_cbca_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_069[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 257, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 70 APPEAR USE */
const u16 yang_cbca_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_070[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 258, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 71 APPEAR USE */
const u16 yang_cbca_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_071[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 259, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 72 APPEAR USE */
const u16 yang_cbca_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_072[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 4, 260, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 73 APPEAR USE */
const u16 yang_cbca_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_073[16] = {
    CMD(CM_BACK, 0, 0, 0),
    CMD(CM_RJA, 5, 76, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 74 APPEAR USE */
const u16 yang_cbca_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_074[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 88, 1),
    CMD(CM_RJA3, 7, 89, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 75 APPEAR USE, 76 APPEAR USE */
const u16 yang_cbca_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_075[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 90, 1),
    CMD(CM_RJA3, 7, 91, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 77 APPEAR USE */
const u16 yang_cbca_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_077[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 92, 1),
    CMD(CM_RJA3, 7, 93, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 78 APPEAR USE */
const u16 yang_cbca_078_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_078[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 94, 1),
    CMD(CM_RJA3, 7, 95, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 79 APPEAR USE */
const u16 yang_cbca_079_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_079[36] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_S_CHG, 16, 16388, 8192),
    CMD(CM_S_CHG, 32, 16389, 8192),
    CMD(CM_RJA4, 5, 38, 16),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA4, 5, 36, 16),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA4, 5, 37, 16),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 80 APPEAR USE */
const u16 yang_cbca_080_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_080[36] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_S_CHG, 16, 16388, 8192),
    CMD(CM_S_CHG, 32, 16389, 8192),
    CMD(CM_RJA4, 5, 38, 35),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA4, 5, 36, 35),
    CMD(CM_RETMJ, 0, 0, 0),
    CMD(CM_RJA4, 5, 37, 35),
    CMD(CM_RETMJ, 0, 0, 0),
};

/* script: 81 APPEAR USE */
const u16 yang_cbca_081_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_081[24] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_S_CHG, 16, 16387, 8192),
    CMD(CM_S_CHG, 32, 16387, 8192),
    CMD(CM_JMP, 5, 38, 16),
    CMD(CM_JMP, 5, 36, 16),
    CMD(CM_JMP, 5, 37, 16),
};

/* script: 82 APPEAR USE */
const u16 yang_cbca_082_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_082[24] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_S_CHG, 16, 16387, 8192),
    CMD(CM_S_CHG, 32, 16387, 8192),
    CMD(CM_JMP, 5, 38, 35),
    CMD(CM_JMP, 5, 36, 35),
    CMD(CM_JMP, 5, 37, 35),
};

/* script: 83 APPEAR USE */
const u16 yang_cbca_083_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_083[8] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_JMP, 5, 39, 16),
};

/* script: 84 APPEAR USE */
const u16 yang_cbca_084_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_084[8] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_JMP, 5, 39, 28),
};

/* script: 85 APPEAR USE */
const u16 yang_cbca_085_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_085[8] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_JMP, 5, 39, 41),
};

/* script: 86 APPEAR USE */
const u16 yang_cbca_086_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_086[8] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_JMP, 5, 39, 54),
};

/* script: 87 APPEAR USE */
const u16 yang_cbca_087_head[4] = { HEAD(2, 0, 14, 13, 0, 10, 53) };
const u16 yang_cbca_087[16] = {
    CMD(CM_EXEC, 49, 40, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 88 APPEAR USE */
const u16 yang_cbca_088_head[4] = { HEAD(2, 0, 15, 11, 0, 0, 29) };
const u16 yang_cbca_088[16] = {
    CMD(CM_EXEC, 49, 41, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 89 APPEAR USE */
const u16 yang_cbca_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_089[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 96, 1),
    CMD(CM_RJA3, 7, 97, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 90 APPEAR USE */
const u16 yang_cbca_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_cbca_090[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 98, 1),
    CMD(CM_RJA3, 7, 99, 1),
    CMD(CM_RET, 0, 0, 0),
};

/*
 * YUN_CHAR.C  Yun's animation scripts and sprite part tables
 *
 * The animation scripts Yun's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 yun_nmca_054[], yun_nmca_055[], yun_nmca_056[], yun_nmca_057[], yun_nmca_001[], yun_nmca_002[], yun_nmca_003[], yun_nmca_004[], yun_nmca_005[], yun_nmca_006[], yun_nmca_007[], yun_nmca_008[], yun_nmca_011[], yun_nmca_012[], yun_nmca_013[], yun_nmca_014[], yun_nmca_015[], yun_nmca_016[], yun_nmca_017[], yun_nmca_020[], yun_nmca_021[], yun_nmca_022[], yun_nmca_023[], yun_nmca_024[], yun_nmca_026[], yun_nmca_027[], yun_nmca_029[], yun_nmca_030[], yun_nmca_031[], yun_nmca_033[], yun_nmca_038[], yun_nmca_040[], yun_nmca_041[], yun_nmca_043[], yun_nmca_044[], yun_nmca_045[], yun_nmca_046[], yun_nmca_047[], yun_nmca_048[], yun_nmca_049[], yun_nmca_050[], yun_nmca_051[], yun_nmca_052[], yun_nmca_053[], yun_nmca_000[];
extern const u16 yun_nmca_054_head[];
extern const u16 yun_nmca_055_head[];
extern const u16 yun_nmca_056_head[];
extern const u16 yun_nmca_057_head[];
extern const u16 yun_nmca_001_head[];
extern const u16 yun_nmca_002_head[];
extern const u16 yun_nmca_003_head[];
extern const u16 yun_nmca_004_head[];
extern const u16 yun_nmca_005_head[];
extern const u16 yun_nmca_006_head[];
extern const u16 yun_nmca_007_head[];
extern const u16 yun_nmca_008_head[];
extern const u16 yun_nmca_011_head[];
extern const u16 yun_nmca_012_head[];
extern const u16 yun_nmca_013_head[];
extern const u16 yun_nmca_014_head[];
extern const u16 yun_nmca_015_head[];
extern const u16 yun_nmca_016_head[];
extern const u16 yun_nmca_017_head[];
extern const u16 yun_nmca_020_head[];
extern const u16 yun_nmca_021_head[];
extern const u16 yun_nmca_022_head[];
extern const u16 yun_nmca_023_head[];
extern const u16 yun_nmca_024_head[];
extern const u16 yun_nmca_026_head[];
extern const u16 yun_nmca_027_head[];
extern const u16 yun_nmca_029_head[];
extern const u16 yun_nmca_030_head[];
extern const u16 yun_nmca_031_head[];
extern const u16 yun_nmca_033_head[];
extern const u16 yun_nmca_038_head[];
extern const u16 yun_nmca_040_head[];
extern const u16 yun_nmca_041_head[];
extern const u16 yun_nmca_043_head[];
extern const u16 yun_nmca_044_head[];
extern const u16 yun_nmca_045_head[];
extern const u16 yun_nmca_046_head[];
extern const u16 yun_nmca_047_head[];
extern const u16 yun_nmca_048_head[];
extern const u16 yun_nmca_049_head[];
extern const u16 yun_nmca_050_head[];
extern const u16 yun_nmca_051_head[];
extern const u16 yun_nmca_052_head[];
extern const u16 yun_nmca_053_head[];
extern const u16 yun_nmca_000_head[];
extern const u16 yun_dmca_000[], yun_dmca_001[], yun_dmca_002[], yun_dmca_003[], yun_dmca_004[], yun_dmca_006[], yun_dmca_008[], yun_dmca_009[], yun_dmca_010[], yun_dmca_014[], yun_dmca_018[], yun_dmca_022[], yun_dmca_025[], yun_dmca_026[], yun_dmca_024[], yun_dmca_029[], yun_dmca_030[], yun_dmca_034[], yun_dmca_036[], yun_dmca_048[], yun_dmca_049[], yun_dmca_050[], yun_dmca_052[], yun_dmca_060[], yun_dmca_064[], yun_dmca_065[], yun_dmca_066[], yun_dmca_067[], yun_dmca_068[], yun_dmca_070[], yun_dmca_071[], yun_dmca_072[], yun_dmca_073[], yun_dmca_074[], yun_dmca_075[], yun_dmca_076[], yun_dmca_078[], yun_dmca_079[], yun_dmca_080[], yun_dmca_082[], yun_dmca_083[], yun_dmca_084[], yun_dmca_090[], yun_dmca_091[], yun_dmca_096[], yun_dmca_097[];
extern const u16 yun_dmca_000_head[];
extern const u16 yun_dmca_001_head[];
extern const u16 yun_dmca_002_head[];
extern const u16 yun_dmca_003_head[];
extern const u16 yun_dmca_004_head[];
extern const u16 yun_dmca_006_head[];
extern const u16 yun_dmca_008_head[];
extern const u16 yun_dmca_009_head[];
extern const u16 yun_dmca_010_head[];
extern const u16 yun_dmca_014_head[];
extern const u16 yun_dmca_018_head[];
extern const u16 yun_dmca_022_head[];
extern const u16 yun_dmca_025_head[];
extern const u16 yun_dmca_026_head[];
extern const u16 yun_dmca_024_head[];
extern const u16 yun_dmca_029_head[];
extern const u16 yun_dmca_030_head[];
extern const u16 yun_dmca_034_head[];
extern const u16 yun_dmca_036_head[];
extern const u16 yun_dmca_048_head[];
extern const u16 yun_dmca_049_head[];
extern const u16 yun_dmca_050_head[];
extern const u16 yun_dmca_052_head[];
extern const u16 yun_dmca_060_head[];
extern const u16 yun_dmca_064_head[];
extern const u16 yun_dmca_065_head[];
extern const u16 yun_dmca_066_head[];
extern const u16 yun_dmca_067_head[];
extern const u16 yun_dmca_068_head[];
extern const u16 yun_dmca_070_head[];
extern const u16 yun_dmca_071_head[];
extern const u16 yun_dmca_072_head[];
extern const u16 yun_dmca_073_head[];
extern const u16 yun_dmca_074_head[];
extern const u16 yun_dmca_075_head[];
extern const u16 yun_dmca_076_head[];
extern const u16 yun_dmca_078_head[];
extern const u16 yun_dmca_079_head[];
extern const u16 yun_dmca_080_head[];
extern const u16 yun_dmca_082_head[];
extern const u16 yun_dmca_083_head[];
extern const u16 yun_dmca_084_head[];
extern const u16 yun_dmca_090_head[];
extern const u16 yun_dmca_091_head[];
extern const u16 yun_dmca_096_head[];
extern const u16 yun_dmca_097_head[];
extern const u16 yun_btca_000[], yun_btca_001[], yun_btca_002[], yun_btca_003[], yun_btca_004[], yun_btca_005[], yun_btca_006[], yun_btca_007[], yun_btca_008[], yun_btca_009[], yun_btca_010[], yun_btca_011[], yun_btca_012[], yun_btca_013[], yun_btca_014[], yun_btca_015[], yun_btca_016[], yun_btca_017[], yun_btca_018[], yun_btca_019[], yun_btca_020[], yun_btca_021[], yun_btca_022[], yun_btca_023[], yun_btca_024[], yun_btca_025[], yun_btca_026[], yun_btca_027[], yun_btca_028[], yun_btca_029[], yun_btca_030[], yun_btca_031[], yun_btca_032[], yun_btca_033[], yun_btca_034[], yun_btca_035[];
extern const u16 yun_btca_000_head[];
extern const u16 yun_btca_001_head[];
extern const u16 yun_btca_002_head[];
extern const u16 yun_btca_003_head[];
extern const u16 yun_btca_004_head[];
extern const u16 yun_btca_005_head[];
extern const u16 yun_btca_006_head[];
extern const u16 yun_btca_007_head[];
extern const u16 yun_btca_008_head[];
extern const u16 yun_btca_009_head[];
extern const u16 yun_btca_010_head[];
extern const u16 yun_btca_011_head[];
extern const u16 yun_btca_012_head[];
extern const u16 yun_btca_013_head[];
extern const u16 yun_btca_014_head[];
extern const u16 yun_btca_015_head[];
extern const u16 yun_btca_016_head[];
extern const u16 yun_btca_017_head[];
extern const u16 yun_btca_018_head[];
extern const u16 yun_btca_019_head[];
extern const u16 yun_btca_020_head[];
extern const u16 yun_btca_021_head[];
extern const u16 yun_btca_022_head[];
extern const u16 yun_btca_023_head[];
extern const u16 yun_btca_024_head[];
extern const u16 yun_btca_025_head[];
extern const u16 yun_btca_026_head[];
extern const u16 yun_btca_027_head[];
extern const u16 yun_btca_028_head[];
extern const u16 yun_btca_029_head[];
extern const u16 yun_btca_030_head[];
extern const u16 yun_btca_031_head[];
extern const u16 yun_btca_032_head[];
extern const u16 yun_btca_033_head[];
extern const u16 yun_btca_034_head[];
extern const u16 yun_btca_035_head[];
extern const u16 yun_caca_000[], yun_caca_001[], yun_caca_002[], yun_caca_003[], yun_caca_004[], yun_caca_005[], yun_caca_006[], yun_caca_007[], yun_caca_008[], yun_caca_009[];
extern const u16 yun_caca_000_head[];
extern const u16 yun_caca_001_head[];
extern const u16 yun_caca_002_head[];
extern const u16 yun_caca_003_head[];
extern const u16 yun_caca_004_head[];
extern const u16 yun_caca_005_head[];
extern const u16 yun_caca_006_head[];
extern const u16 yun_caca_007_head[];
extern const u16 yun_caca_008_head[];
extern const u16 yun_caca_009_head[];
extern const u16 yun_cuca_000[], yun_cuca_001[], yun_cuca_002[], yun_cuca_003[], yun_cuca_004[], yun_cuca_005[], yun_cuca_006[], yun_cuca_007[], yun_cuca_008[], yun_cuca_009[], yun_cuca_010[], yun_cuca_011[], yun_cuca_012[], yun_cuca_013[], yun_cuca_014[], yun_cuca_015[], yun_cuca_016[], yun_cuca_017[], yun_cuca_018[], yun_cuca_019[], yun_cuca_020[], yun_cuca_021[], yun_cuca_022[], yun_cuca_023[], yun_cuca_024[], yun_cuca_025[], yun_cuca_026[], yun_cuca_027[], yun_cuca_028[], yun_cuca_029[], yun_cuca_030[], yun_cuca_031[], yun_cuca_032[], yun_cuca_033[], yun_cuca_034[], yun_cuca_035[], yun_cuca_036[], yun_cuca_037[], yun_cuca_038[], yun_cuca_039[], yun_cuca_040[], yun_cuca_041[], yun_cuca_042[], yun_cuca_043[], yun_cuca_044[], yun_cuca_045[], yun_cuca_046[], yun_cuca_047[], yun_cuca_048[], yun_cuca_049[], yun_cuca_050[], yun_cuca_051[], yun_cuca_052[], yun_cuca_053[], yun_cuca_054[], yun_cuca_055[], yun_cuca_056[], yun_cuca_057[], yun_cuca_058[], yun_cuca_059[], yun_cuca_060[], yun_cuca_061[], yun_cuca_062[], yun_cuca_063[], yun_cuca_064[], yun_cuca_065[], yun_cuca_066[], yun_cuca_067[];
extern const u16 yun_cuca_000_head[];
extern const u16 yun_cuca_001_head[];
extern const u16 yun_cuca_002_head[];
extern const u16 yun_cuca_003_head[];
extern const u16 yun_cuca_004_head[];
extern const u16 yun_cuca_005_head[];
extern const u16 yun_cuca_006_head[];
extern const u16 yun_cuca_007_head[];
extern const u16 yun_cuca_008_head[];
extern const u16 yun_cuca_009_head[];
extern const u16 yun_cuca_010_head[];
extern const u16 yun_cuca_011_head[];
extern const u16 yun_cuca_012_head[];
extern const u16 yun_cuca_013_head[];
extern const u16 yun_cuca_014_head[];
extern const u16 yun_cuca_015_head[];
extern const u16 yun_cuca_016_head[];
extern const u16 yun_cuca_017_head[];
extern const u16 yun_cuca_018_head[];
extern const u16 yun_cuca_019_head[];
extern const u16 yun_cuca_020_head[];
extern const u16 yun_cuca_021_head[];
extern const u16 yun_cuca_022_head[];
extern const u16 yun_cuca_023_head[];
extern const u16 yun_cuca_024_head[];
extern const u16 yun_cuca_025_head[];
extern const u16 yun_cuca_026_head[];
extern const u16 yun_cuca_027_head[];
extern const u16 yun_cuca_028_head[];
extern const u16 yun_cuca_029_head[];
extern const u16 yun_cuca_030_head[];
extern const u16 yun_cuca_031_head[];
extern const u16 yun_cuca_032_head[];
extern const u16 yun_cuca_033_head[];
extern const u16 yun_cuca_034_head[];
extern const u16 yun_cuca_035_head[];
extern const u16 yun_cuca_036_head[];
extern const u16 yun_cuca_037_head[];
extern const u16 yun_cuca_038_head[];
extern const u16 yun_cuca_039_head[];
extern const u16 yun_cuca_040_head[];
extern const u16 yun_cuca_041_head[];
extern const u16 yun_cuca_042_head[];
extern const u16 yun_cuca_043_head[];
extern const u16 yun_cuca_044_head[];
extern const u16 yun_cuca_045_head[];
extern const u16 yun_cuca_046_head[];
extern const u16 yun_cuca_047_head[];
extern const u16 yun_cuca_048_head[];
extern const u16 yun_cuca_049_head[];
extern const u16 yun_cuca_050_head[];
extern const u16 yun_cuca_051_head[];
extern const u16 yun_cuca_052_head[];
extern const u16 yun_cuca_053_head[];
extern const u16 yun_cuca_054_head[];
extern const u16 yun_cuca_055_head[];
extern const u16 yun_cuca_056_head[];
extern const u16 yun_cuca_057_head[];
extern const u16 yun_cuca_058_head[];
extern const u16 yun_cuca_059_head[];
extern const u16 yun_cuca_060_head[];
extern const u16 yun_cuca_061_head[];
extern const u16 yun_cuca_062_head[];
extern const u16 yun_cuca_063_head[];
extern const u16 yun_cuca_064_head[];
extern const u16 yun_cuca_065_head[];
extern const u16 yun_cuca_066_head[];
extern const u16 yun_cuca_067_head[];
extern const u16 yun_atca_003[], yun_atca_004[], yun_atca_006[], yun_atca_007[], yun_atca_008[], yun_atca_009[], yun_atca_012[], yun_atca_013[], yun_atca_014[], yun_atca_015[], yun_atca_018[], yun_atca_021[], yun_atca_024[], yun_atca_027[], yun_atca_030[], yun_atca_036[], yun_atca_038[], yun_atca_040[], yun_atca_042[], yun_atca_044[], yun_atca_046[], yun_atca_048[], yun_atca_050[], yun_atca_052[], yun_atca_054[], yun_atca_055[], yun_atca_056[], yun_atca_057[], yun_atca_058[], yun_atca_059[], yun_atca_060[], yun_atca_062[], yun_atca_064[], yun_atca_066[], yun_atca_068[], yun_atca_070[], yun_atca_072[], yun_atca_074[], yun_atca_076[], yun_atca_078[], yun_atca_080[], yun_atca_082[], yun_atca_084[], yun_atca_086[], yun_atca_088[], yun_atca_090[], yun_atca_091[], yun_atca_092[], yun_atca_093[], yun_atca_094[], yun_atca_095[], yun_atca_096[], yun_atca_098[], yun_atca_100[], yun_atca_102[], yun_atca_104[], yun_atca_106[], yun_atca_108[], yun_atca_110[], yun_atca_112[], yun_atca_114[], yun_atca_116[], yun_atca_118[], yun_atca_156[], yun_atca_158[], yun_atca_159[], yun_atca_160[], yun_atca_161[], yun_atca_162[], yun_atca_163[], yun_atca_164[], yun_atca_203[], yun_atca_204[], yun_atca_206[], yun_atca_207[], yun_atca_208[], yun_atca_209[], yun_atca_212[], yun_atca_213[], yun_atca_214[], yun_atca_215[], yun_atca_218[], yun_atca_221[], yun_atca_224[], yun_atca_227[], yun_atca_230[], yun_atca_233[], yun_atca_236[], yun_atca_238[], yun_atca_240[], yun_atca_242[], yun_atca_244[], yun_atca_246[], yun_atca_248[], yun_atca_250[], yun_atca_252[], yun_atca_254[], yun_atca_255[], yun_atca_256[], yun_atca_257[], yun_atca_258[], yun_atca_259[], yun_atca_260[], yun_atca_262[], yun_atca_263[], yun_atca_033[], yun_atca_000[], yun_atca_001[], yun_atca_200[], yun_atca_201[], yun_atca_144[], yun_atca_145[], yun_atca_146[];
extern const u16 yun_atca_003_head[];
extern const u16 yun_atca_004_head[];
extern const u16 yun_atca_006_head[];
extern const u16 yun_atca_007_head[];
extern const u16 yun_atca_008_head[];
extern const u16 yun_atca_009_head[];
extern const u16 yun_atca_012_head[];
extern const u16 yun_atca_013_head[];
extern const u16 yun_atca_014_head[];
extern const u16 yun_atca_015_head[];
extern const u16 yun_atca_018_head[];
extern const u16 yun_atca_021_head[];
extern const u16 yun_atca_024_head[];
extern const u16 yun_atca_027_head[];
extern const u16 yun_atca_030_head[];
extern const u16 yun_atca_036_head[];
extern const u16 yun_atca_038_head[];
extern const u16 yun_atca_040_head[];
extern const u16 yun_atca_042_head[];
extern const u16 yun_atca_044_head[];
extern const u16 yun_atca_046_head[];
extern const u16 yun_atca_048_head[];
extern const u16 yun_atca_050_head[];
extern const u16 yun_atca_052_head[];
extern const u16 yun_atca_054_head[];
extern const u16 yun_atca_055_head[];
extern const u16 yun_atca_056_head[];
extern const u16 yun_atca_057_head[];
extern const u16 yun_atca_058_head[];
extern const u16 yun_atca_059_head[];
extern const u16 yun_atca_060_head[];
extern const u16 yun_atca_062_head[];
extern const u16 yun_atca_064_head[];
extern const u16 yun_atca_066_head[];
extern const u16 yun_atca_068_head[];
extern const u16 yun_atca_070_head[];
extern const u16 yun_atca_072_head[];
extern const u16 yun_atca_074_head[];
extern const u16 yun_atca_076_head[];
extern const u16 yun_atca_078_head[];
extern const u16 yun_atca_080_head[];
extern const u16 yun_atca_082_head[];
extern const u16 yun_atca_084_head[];
extern const u16 yun_atca_086_head[];
extern const u16 yun_atca_088_head[];
extern const u16 yun_atca_090_head[];
extern const u16 yun_atca_091_head[];
extern const u16 yun_atca_092_head[];
extern const u16 yun_atca_093_head[];
extern const u16 yun_atca_094_head[];
extern const u16 yun_atca_095_head[];
extern const u16 yun_atca_096_head[];
extern const u16 yun_atca_098_head[];
extern const u16 yun_atca_100_head[];
extern const u16 yun_atca_102_head[];
extern const u16 yun_atca_104_head[];
extern const u16 yun_atca_106_head[];
extern const u16 yun_atca_108_head[];
extern const u16 yun_atca_110_head[];
extern const u16 yun_atca_112_head[];
extern const u16 yun_atca_114_head[];
extern const u16 yun_atca_116_head[];
extern const u16 yun_atca_118_head[];
extern const u16 yun_atca_156_head[];
extern const u16 yun_atca_158_head[];
extern const u16 yun_atca_159_head[];
extern const u16 yun_atca_160_head[];
extern const u16 yun_atca_161_head[];
extern const u16 yun_atca_162_head[];
extern const u16 yun_atca_163_head[];
extern const u16 yun_atca_164_head[];
extern const u16 yun_atca_203_head[];
extern const u16 yun_atca_204_head[];
extern const u16 yun_atca_206_head[];
extern const u16 yun_atca_207_head[];
extern const u16 yun_atca_208_head[];
extern const u16 yun_atca_209_head[];
extern const u16 yun_atca_212_head[];
extern const u16 yun_atca_213_head[];
extern const u16 yun_atca_214_head[];
extern const u16 yun_atca_215_head[];
extern const u16 yun_atca_218_head[];
extern const u16 yun_atca_221_head[];
extern const u16 yun_atca_224_head[];
extern const u16 yun_atca_227_head[];
extern const u16 yun_atca_230_head[];
extern const u16 yun_atca_233_head[];
extern const u16 yun_atca_236_head[];
extern const u16 yun_atca_238_head[];
extern const u16 yun_atca_240_head[];
extern const u16 yun_atca_242_head[];
extern const u16 yun_atca_244_head[];
extern const u16 yun_atca_246_head[];
extern const u16 yun_atca_248_head[];
extern const u16 yun_atca_250_head[];
extern const u16 yun_atca_252_head[];
extern const u16 yun_atca_254_head[];
extern const u16 yun_atca_255_head[];
extern const u16 yun_atca_256_head[];
extern const u16 yun_atca_257_head[];
extern const u16 yun_atca_258_head[];
extern const u16 yun_atca_259_head[];
extern const u16 yun_atca_260_head[];
extern const u16 yun_atca_262_head[];
extern const u16 yun_atca_263_head[];
extern const u16 yun_atca_033_head[];
extern const u16 yun_atca_000_head[];
extern const u16 yun_atca_001_head[];
extern const u16 yun_atca_200_head[];
extern const u16 yun_atca_201_head[];
extern const u16 yun_atca_144_head[];
extern const u16 yun_atca_145_head[];
extern const u16 yun_atca_146_head[];
extern const u16 yun_exca_000[], yun_exca_001[], yun_exca_003[], yun_exca_004[], yun_exca_005[], yun_exca_006[], yun_exca_009[], yun_exca_010[], yun_exca_012[], yun_exca_013[], yun_exca_014[], yun_exca_015[], yun_exca_016[], yun_exca_017[], yun_exca_018[], yun_exca_019[], yun_exca_020[], yun_exca_021[], yun_exca_024[], yun_exca_025[], yun_exca_026[], yun_exca_027[], yun_exca_028[], yun_exca_029[], yun_exca_030[], yun_exca_031[], yun_exca_032[], yun_exca_033[], yun_exca_034[], yun_exca_035[], yun_exca_036[], yun_exca_037[], yun_exca_038[], yun_exca_039[], yun_exca_040[], yun_exca_041[], yun_exca_042[], yun_exca_043[], yun_exca_044[], yun_exca_045[], yun_exca_046[], yun_exca_047[], yun_exca_048[], yun_exca_049[], yun_exca_050[], yun_exca_051[], yun_exca_052[], yun_exca_053[], yun_exca_054[], yun_exca_056[], yun_exca_058[], yun_exca_061[], yun_exca_062[], yun_exca_063[], yun_exca_064[], yun_exca_065[], yun_exca_066[], yun_exca_022[], yun_exca_073[], yun_exca_074[], yun_exca_075[], yun_exca_076[], yun_exca_077[], yun_exca_078[], yun_exca_079[], yun_exca_080[], yun_exca_081[], yun_exca_082[], yun_exca_083[], yun_exca_084[], yun_exca_085[], yun_exca_086[], yun_exca_087[], yun_exca_088[], yun_exca_089[], yun_exca_090[], yun_exca_091[], yun_exca_094[], yun_exca_095[], yun_exca_096[], yun_exca_097[], yun_exca_098[], yun_exca_099[], yun_exca_100[], yun_exca_101[], yun_exca_102[], yun_exca_103[];
extern const u16 yun_exca_000_head[];
extern const u16 yun_exca_001_head[];
extern const u16 yun_exca_003_head[];
extern const u16 yun_exca_004_head[];
extern const u16 yun_exca_005_head[];
extern const u16 yun_exca_006_head[];
extern const u16 yun_exca_009_head[];
extern const u16 yun_exca_010_head[];
extern const u16 yun_exca_012_head[];
extern const u16 yun_exca_013_head[];
extern const u16 yun_exca_014_head[];
extern const u16 yun_exca_015_head[];
extern const u16 yun_exca_016_head[];
extern const u16 yun_exca_017_head[];
extern const u16 yun_exca_018_head[];
extern const u16 yun_exca_019_head[];
extern const u16 yun_exca_020_head[];
extern const u16 yun_exca_021_head[];
extern const u16 yun_exca_024_head[];
extern const u16 yun_exca_025_head[];
extern const u16 yun_exca_026_head[];
extern const u16 yun_exca_027_head[];
extern const u16 yun_exca_028_head[];
extern const u16 yun_exca_029_head[];
extern const u16 yun_exca_030_head[];
extern const u16 yun_exca_031_head[];
extern const u16 yun_exca_032_head[];
extern const u16 yun_exca_033_head[];
extern const u16 yun_exca_034_head[];
extern const u16 yun_exca_035_head[];
extern const u16 yun_exca_036_head[];
extern const u16 yun_exca_037_head[];
extern const u16 yun_exca_038_head[];
extern const u16 yun_exca_039_head[];
extern const u16 yun_exca_040_head[];
extern const u16 yun_exca_041_head[];
extern const u16 yun_exca_042_head[];
extern const u16 yun_exca_043_head[];
extern const u16 yun_exca_044_head[];
extern const u16 yun_exca_045_head[];
extern const u16 yun_exca_046_head[];
extern const u16 yun_exca_047_head[];
extern const u16 yun_exca_048_head[];
extern const u16 yun_exca_049_head[];
extern const u16 yun_exca_050_head[];
extern const u16 yun_exca_051_head[];
extern const u16 yun_exca_052_head[];
extern const u16 yun_exca_053_head[];
extern const u16 yun_exca_054_head[];
extern const u16 yun_exca_056_head[];
extern const u16 yun_exca_058_head[];
extern const u16 yun_exca_061_head[];
extern const u16 yun_exca_062_head[];
extern const u16 yun_exca_063_head[];
extern const u16 yun_exca_064_head[];
extern const u16 yun_exca_065_head[];
extern const u16 yun_exca_066_head[];
extern const u16 yun_exca_022_head[];
extern const u16 yun_exca_073_head[];
extern const u16 yun_exca_074_head[];
extern const u16 yun_exca_075_head[];
extern const u16 yun_exca_076_head[];
extern const u16 yun_exca_077_head[];
extern const u16 yun_exca_078_head[];
extern const u16 yun_exca_079_head[];
extern const u16 yun_exca_080_head[];
extern const u16 yun_exca_081_head[];
extern const u16 yun_exca_082_head[];
extern const u16 yun_exca_083_head[];
extern const u16 yun_exca_084_head[];
extern const u16 yun_exca_085_head[];
extern const u16 yun_exca_086_head[];
extern const u16 yun_exca_087_head[];
extern const u16 yun_exca_088_head[];
extern const u16 yun_exca_089_head[];
extern const u16 yun_exca_090_head[];
extern const u16 yun_exca_091_head[];
extern const u16 yun_exca_094_head[];
extern const u16 yun_exca_095_head[];
extern const u16 yun_exca_096_head[];
extern const u16 yun_exca_097_head[];
extern const u16 yun_exca_098_head[];
extern const u16 yun_exca_099_head[];
extern const u16 yun_exca_100_head[];
extern const u16 yun_exca_101_head[];
extern const u16 yun_exca_102_head[];
extern const u16 yun_exca_103_head[];
extern const u16 yun_saca_000[], yun_saca_001[], yun_saca_002[], yun_saca_024[], yun_saca_028[], yun_saca_031[], yun_saca_036[], yun_saca_037[], yun_saca_038[], yun_saca_039[], yun_saca_040[], yun_saca_044[], yun_saca_048[], yun_saca_052[], yun_saca_056[], yun_saca_060[], yun_saca_061[], yun_saca_065[], yun_saca_069[], yun_saca_070[], yun_saca_074[], yun_saca_075[], yun_saca_076[], yun_saca_080[], yun_saca_083[], yun_saca_087[], yun_saca_088[], yun_saca_089[], yun_saca_090[], yun_saca_092[], yun_saca_091[], yun_saca_094[], yun_saca_095[], yun_saca_096[], yun_saca_097[], yun_saca_098[], yun_saca_032[], yun_saca_033[], yun_saca_034[], yun_saca_035[], yun_saca_066[];
extern const u16 yun_saca_000_head[];
extern const u16 yun_saca_001_head[];
extern const u16 yun_saca_002_head[];
extern const u16 yun_saca_024_head[];
extern const u16 yun_saca_028_head[];
extern const u16 yun_saca_031_head[];
extern const u16 yun_saca_036_head[];
extern const u16 yun_saca_037_head[];
extern const u16 yun_saca_038_head[];
extern const u16 yun_saca_039_head[];
extern const u16 yun_saca_040_head[];
extern const u16 yun_saca_044_head[];
extern const u16 yun_saca_048_head[];
extern const u16 yun_saca_052_head[];
extern const u16 yun_saca_056_head[];
extern const u16 yun_saca_060_head[];
extern const u16 yun_saca_061_head[];
extern const u16 yun_saca_065_head[];
extern const u16 yun_saca_069_head[];
extern const u16 yun_saca_070_head[];
extern const u16 yun_saca_074_head[];
extern const u16 yun_saca_075_head[];
extern const u16 yun_saca_076_head[];
extern const u16 yun_saca_080_head[];
extern const u16 yun_saca_083_head[];
extern const u16 yun_saca_087_head[];
extern const u16 yun_saca_088_head[];
extern const u16 yun_saca_089_head[];
extern const u16 yun_saca_090_head[];
extern const u16 yun_saca_092_head[];
extern const u16 yun_saca_091_head[];
extern const u16 yun_saca_094_head[];
extern const u16 yun_saca_095_head[];
extern const u16 yun_saca_096_head[];
extern const u16 yun_saca_097_head[];
extern const u16 yun_saca_098_head[];
extern const u16 yun_saca_032_head[];
extern const u16 yun_saca_033_head[];
extern const u16 yun_saca_034_head[];
extern const u16 yun_saca_035_head[];
extern const u16 yun_saca_066_head[];
extern const u16 yun_cbca_000[], yun_cbca_001[], yun_cbca_002[], yun_cbca_003[], yun_cbca_004[], yun_cbca_005[], yun_cbca_006[], yun_cbca_010[], yun_cbca_011[], yun_cbca_012[], yun_cbca_013[], yun_cbca_014[], yun_cbca_015[], yun_cbca_016[], yun_cbca_017[], yun_cbca_018[], yun_cbca_019[], yun_cbca_020[], yun_cbca_021[], yun_cbca_022[], yun_cbca_023[], yun_cbca_024[], yun_cbca_025[], yun_cbca_026[], yun_cbca_027[], yun_cbca_028[], yun_cbca_029[], yun_cbca_030[], yun_cbca_031[], yun_cbca_032[], yun_cbca_033[], yun_cbca_034[], yun_cbca_035[], yun_cbca_036[], yun_cbca_037[], yun_cbca_038[], yun_cbca_039[], yun_cbca_040[], yun_cbca_041[], yun_cbca_042[], yun_cbca_043[], yun_cbca_044[], yun_cbca_045[], yun_cbca_046[], yun_cbca_047[], yun_cbca_048[], yun_cbca_049[], yun_cbca_050[], yun_cbca_051[], yun_cbca_052[], yun_cbca_053[], yun_cbca_054[], yun_cbca_055[], yun_cbca_056[], yun_cbca_057[], yun_cbca_058[], yun_cbca_059[], yun_cbca_060[], yun_cbca_061[], yun_cbca_062[], yun_cbca_063[], yun_cbca_064[], yun_cbca_065[], yun_cbca_066[], yun_cbca_067[], yun_cbca_068[], yun_cbca_069[], yun_cbca_070[], yun_cbca_071[], yun_cbca_072[], yun_cbca_073[], yun_cbca_075[], yun_cbca_076[], yun_cbca_077[], yun_cbca_078[], yun_cbca_079[], yun_cbca_074[], yun_cbca_081[], yun_cbca_082[], yun_cbca_083[], yun_cbca_084[], yun_cbca_085[], yun_cbca_086[], yun_cbca_087[], yun_cbca_088[], yun_cbca_089[], yun_cbca_090[], yun_cbca_091[], yun_cbca_092[], yun_cbca_093[];
extern const u16 yun_cbca_000_head[];
extern const u16 yun_cbca_001_head[];
extern const u16 yun_cbca_002_head[];
extern const u16 yun_cbca_003_head[];
extern const u16 yun_cbca_004_head[];
extern const u16 yun_cbca_005_head[];
extern const u16 yun_cbca_006_head[];
extern const u16 yun_cbca_010_head[];
extern const u16 yun_cbca_011_head[];
extern const u16 yun_cbca_012_head[];
extern const u16 yun_cbca_013_head[];
extern const u16 yun_cbca_014_head[];
extern const u16 yun_cbca_015_head[];
extern const u16 yun_cbca_016_head[];
extern const u16 yun_cbca_017_head[];
extern const u16 yun_cbca_018_head[];
extern const u16 yun_cbca_019_head[];
extern const u16 yun_cbca_020_head[];
extern const u16 yun_cbca_021_head[];
extern const u16 yun_cbca_022_head[];
extern const u16 yun_cbca_023_head[];
extern const u16 yun_cbca_024_head[];
extern const u16 yun_cbca_025_head[];
extern const u16 yun_cbca_026_head[];
extern const u16 yun_cbca_027_head[];
extern const u16 yun_cbca_028_head[];
extern const u16 yun_cbca_029_head[];
extern const u16 yun_cbca_030_head[];
extern const u16 yun_cbca_031_head[];
extern const u16 yun_cbca_032_head[];
extern const u16 yun_cbca_033_head[];
extern const u16 yun_cbca_034_head[];
extern const u16 yun_cbca_035_head[];
extern const u16 yun_cbca_036_head[];
extern const u16 yun_cbca_037_head[];
extern const u16 yun_cbca_038_head[];
extern const u16 yun_cbca_039_head[];
extern const u16 yun_cbca_040_head[];
extern const u16 yun_cbca_041_head[];
extern const u16 yun_cbca_042_head[];
extern const u16 yun_cbca_043_head[];
extern const u16 yun_cbca_044_head[];
extern const u16 yun_cbca_045_head[];
extern const u16 yun_cbca_046_head[];
extern const u16 yun_cbca_047_head[];
extern const u16 yun_cbca_048_head[];
extern const u16 yun_cbca_049_head[];
extern const u16 yun_cbca_050_head[];
extern const u16 yun_cbca_051_head[];
extern const u16 yun_cbca_052_head[];
extern const u16 yun_cbca_053_head[];
extern const u16 yun_cbca_054_head[];
extern const u16 yun_cbca_055_head[];
extern const u16 yun_cbca_056_head[];
extern const u16 yun_cbca_057_head[];
extern const u16 yun_cbca_058_head[];
extern const u16 yun_cbca_059_head[];
extern const u16 yun_cbca_060_head[];
extern const u16 yun_cbca_061_head[];
extern const u16 yun_cbca_062_head[];
extern const u16 yun_cbca_063_head[];
extern const u16 yun_cbca_064_head[];
extern const u16 yun_cbca_065_head[];
extern const u16 yun_cbca_066_head[];
extern const u16 yun_cbca_067_head[];
extern const u16 yun_cbca_068_head[];
extern const u16 yun_cbca_069_head[];
extern const u16 yun_cbca_070_head[];
extern const u16 yun_cbca_071_head[];
extern const u16 yun_cbca_072_head[];
extern const u16 yun_cbca_073_head[];
extern const u16 yun_cbca_075_head[];
extern const u16 yun_cbca_076_head[];
extern const u16 yun_cbca_077_head[];
extern const u16 yun_cbca_078_head[];
extern const u16 yun_cbca_079_head[];
extern const u16 yun_cbca_074_head[];
extern const u16 yun_cbca_081_head[];
extern const u16 yun_cbca_082_head[];
extern const u16 yun_cbca_083_head[];
extern const u16 yun_cbca_084_head[];
extern const u16 yun_cbca_085_head[];
extern const u16 yun_cbca_086_head[];
extern const u16 yun_cbca_087_head[];
extern const u16 yun_cbca_088_head[];
extern const u16 yun_cbca_089_head[];
extern const u16 yun_cbca_090_head[];
extern const u16 yun_cbca_091_head[];
extern const u16 yun_cbca_092_head[];
extern const u16 yun_cbca_093_head[];

/* normal scripts: 58 entries */
const u16* const yun_nmca[59] = {
    yun_nmca_000,  /* 0 KAMAE */
    yun_nmca_001,  /* 1 HURIMUKI */
    yun_nmca_002,  /* 2 FRONT WALK */
    yun_nmca_003,  /* 3 BACK WALK */
    yun_nmca_004,  /* 4 DASH HUMIKOMI */
    yun_nmca_005,  /* 5 DASH TOBINOKI */
    yun_nmca_006,  /* 6 KAGAMU */
    yun_nmca_007,  /* 7 KAGAMI KAMAE */
    yun_nmca_008,  /* 8 KAGAMI TURN */
    yun_nmca_008,  /* 9 KAGAMI F WALK */
    yun_nmca_008,  /* 10 KAGAMI B WALK */
    yun_nmca_011,  /* 11 STAND UP */
    yun_nmca_012,  /* 12 JUMP JUNBI */
    yun_nmca_013,  /* 13 SP JUMP JUNBI */
    yun_nmca_014,  /* 14 JUMP FRONT */
    yun_nmca_015,  /* 15 JUMP VERTICAL */
    yun_nmca_016,  /* 16 JUMP BACK */
    yun_nmca_017,  /* 17 S JUMP FRONT */
    yun_nmca_017,  /* 18 S JUMP V */
    yun_nmca_017,  /* 19 S JUMP BACK */
    yun_nmca_020,  /* 20 SP JUMP FRONT */
    yun_nmca_021,  /* 21 SP JUMP V */
    yun_nmca_022,  /* 22 SP JUMP BACK */
    yun_nmca_023,  /* 23 WALK END */
    yun_nmca_024,  /* 24 PARING HEAD */
    yun_nmca_024,  /* 25 PARING UP */
    yun_nmca_026,  /* 26 PARING DOWN */
    yun_nmca_027,  /* 27 PARING AIR F */
    yun_nmca_027,  /* 28 PARING AIR B */
    yun_nmca_029,  /* 29 GUARD HEAD */
    yun_nmca_030,  /* 30 GUARD UP */
    yun_nmca_031,  /* 31 GUARD DOWN */
    yun_nmca_031,  /* 32 GUARD AIR */
    yun_nmca_033,  /* 33 no name */
    yun_nmca_033,  /* 34 no name */
    yun_nmca_033,  /* 35 no name */
    yun_nmca_033,  /* 36 no name */
    yun_nmca_033,  /* 37 no name */
    yun_nmca_038,  /* 38 P BREAK ZUJOU */
    yun_nmca_038,  /* 39 P BREAK UP */
    yun_nmca_040,  /* 40 P BREAK DOWN */
    yun_nmca_041,  /* 41 P BREAK AIR F */
    yun_nmca_041,  /* 42 P BREAK AIR R */
    yun_nmca_043,  /* 43 TUKAMIHAZUSI */
    yun_nmca_044,  /* 44 TUKAMIHAZUSARE */
    yun_nmca_045,  /* 45 TUKAMIHAZUSI */
    yun_nmca_046,  /* 46 TUKAMIHAZUSARE */
    yun_nmca_047,  /* 47 no name */
    yun_nmca_048,  /* 48 no name */
    yun_nmca_049,  /* 49 no name */
    yun_nmca_050,  /* 50 no name */
    yun_nmca_051,  /* 51 no name */
    yun_nmca_052,  /* 52 no name */
    yun_nmca_053,  /* 53 no name */
    yun_nmca_054,  /* 54 no name */
    yun_nmca_055,  /* 55 no name */
    yun_nmca_056,  /* 56 no name */
    yun_nmca_057,  /* 57 no name */
    0
};

/* script: 54 no name */
const u16 yun_nmca_054_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_054[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 yun_nmca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_055[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15AA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x15A5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 yun_nmca_056_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_056[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1594, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1595, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1596, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1597, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1598, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1599, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 yun_nmca_057_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_057[196] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x159D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x159A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1599, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1598, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1597, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1596, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1595, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1594, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0000, 0x0000, 0x0000,
    L4(16, 0, 0, 0, 0, 0, 0, 0x1201, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1202, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1203, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1204, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1205, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1206, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1207, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1208, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1209, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x120A, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x120B, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x120C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 yun_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_001[68] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x1219, 0, 350, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x121A, 0, 350, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x121B, 0, 350, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x121C, 0, 351, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x121D, 0, 351, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x121E, 0, 351, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x121F, 0, 351, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x121F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 yun_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 yun_nmca_002[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1256, 0, 345, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1220, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1221, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1222, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1223, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1224, 0, 347, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1225, 0, 347, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1226, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1227, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1226, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1225, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1224, 0, 346, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1223, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1222, 0, 347, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1221, 0, 347, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 yun_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 yun_nmca_003[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1258, 0, 345, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1228, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1229, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122A, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122B, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122C, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122D, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122E, 0, 349, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x122F, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122E, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122D, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122C, 0, 348, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122B, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x122A, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1229, 0, 349, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 yun_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 yun_nmca_004[220] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x12B0, 0, 365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x12B1, 0, 366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 277, 0, 0, 0, 0, 0x12B2, 0, 366, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(8, 1, 0, 0, 0, 0, 0, 0x12B3, 0, 367, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x12B4, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12B5, 0, 368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 2, 0, 0, 0, 0, 0, 0x12B6, 0, 369, 0, 0, 0, 0, 0, 0, 0, 4, 0, 128),
    L6(4, 3, 0, 0, 0, 0, 0, 0x12B7, 0, 369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 379, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1232, 0, 355, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 yun_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 yun_nmca_005[400] = {
    CMD(CM_RJA3, 0, 5, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x12B8, 0, 370, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12B9, 0, 370, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12BA, 0, 371, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 277, 0, 0, 0, 0, 0x12BB, 0, 371, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12BC, 0, 372, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12BD, 0, 372, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12BE, 0, 372, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12BF, 0, 373, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C0, 0, 373, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(1, 0, 273, 0, 0, 0, 0, 0x12C1, 0, 373, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12C2, 0, 374, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12C3, 0, 374, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C4, 0, 374, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C5, 0, 375, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C6, 0, 375, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C7, 0, 376, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x12C8, 0, 376, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x12C9, 0, 377, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(2, 0, 273, 0, 0, 0, 0, 0x12CA, 0, 377, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x12CB, 0, 378, 0, 0, 0, 0, 0, 0, 0, 16, 0, 128),
    L6(2, 2, 0, 0, 0, 0, 0, 0x12CC, 0, 378, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 379, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1231, 0, 355, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1232, 0, 355, 0, 0, 0, 22, 32, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x1233, 0, 355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1234, 0, 355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 yun_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_nmca_006[60] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1230, 0, 345, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1231, 0, 345, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 355, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1233, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 yun_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_nmca_007[108] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x1242, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1243, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1244, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1245, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1246, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1247, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1248, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x1249, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x124A, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x124B, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x124C, 0, 2, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x124D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 yun_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_nmca_008[76] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x124E, 0, 352, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x124F, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x1250, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x1251, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x1252, 0, 352, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x1253, 0, 352, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x1254, 0, 352, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x1255, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x1255, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 yun_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_nmca_011[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1234, 0, 353, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1233, 0, 353, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1231, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1230, 0, 354, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 yun_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x1240, 0, 291, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x1240, 0, 291, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1240, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 yun_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_013[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x127F, 0, 356, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x127F, 0, 356, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 yun_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_nmca_014[124] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x1270, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1271, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1272, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1273, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1274, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1275, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1276, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1277, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1278, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1279, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127B, 0, 359, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 yun_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 yun_nmca_015[124] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x1260, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1261, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1262, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1263, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1264, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1265, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1266, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1267, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1268, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1269, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126B, 0, 359, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 yun_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x1280, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1281, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1282, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1283, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1284, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1285, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1286, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1287, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1288, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1289, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128A, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128B, 0, 359, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 yun_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 yun_nmca_017[12] = {
    CMD(CM_JSR, 8, 2, 1),
    CMD(CM_JPSS, 0, 15, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 yun_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 yun_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x1270, 0, 357, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1271, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1272, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1273, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1274, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1275, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1276, 0, 358, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1277, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1278, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1279, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127A, 0, 358, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127B, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 yun_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 yun_nmca_021[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x1260, 0, 357, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1261, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1262, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1263, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1264, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1265, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1266, 0, 358, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1267, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1268, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1269, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x126A, 0, 358, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x126B, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x126C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 yun_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 yun_nmca_022[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(5, 0, 281, 0, 0, 0, 0, 0x1280, 0, 357, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1281, 0, 357, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1282, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x1283, 0, 357, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1284, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1285, 0, 357, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1286, 0, 358, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1287, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1288, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x1289, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x128A, 0, 358, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128B, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 yun_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 yun_nmca_024_head[4] = { HEAD(6, 2, 0, 0, 0, 0, 0) };
const u16 yun_nmca_024[88] = {
    L6(2, 133, 0, 0, 0, 0, 0, 0x13A3, 0, 1, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 613, 0, 0, 0, 0, 0x13A4, 0, 1, 0, 0, 0, 6, 0, 0, 0, 128, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x13A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 yun_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 yun_nmca_026[88] = {
    L6(1, 133, 0, 0, 0, 0, 0, 0x129B, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 613, 0, 0, 0, 0, 0x16AB, 0, 2, 0, 0, 0, 6, 1, 0, 0, 128, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16AC, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x16AD, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x161A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x161B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x161C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 yun_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_nmca_027[44] = {
    L4(2, 132, 0, 0, 0, 0, 0, 0x12A5, 0, 3, 0, 0, 0, 18, 6),
    L4(3, 0, 613, 0, 0, 0, 0, 0x12A6, 0, 3, 0, 0, 0, 6, 2),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12A7, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 yun_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yun_nmca_029[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1290, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1291, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1292, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x1293, 0, 86, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x1294, 0, 86, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1291, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1290, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1290, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 yun_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yun_nmca_030[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1297, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1298, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1299, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x129A, 0, 87, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x129B, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1298, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN, 32 GUARD AIR */
const u16 yun_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 yun_nmca_031[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x129E, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x129F, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x12A0, 0, 88, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12A1, 0, 88, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x12A2, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x129F, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x129E, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x129E, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 yun_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_033[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x1201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 yun_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_038[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x129C, 0, 87, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x129D, 0, 87, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 yun_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_nmca_040[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x12A3, 0, 88, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12A4, 0, 88, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12D8, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 yun_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x12A5, 0, 3, 0, 0, 0, 18, 8),
    L4(250, 0, 613, 0, 0, 0, 0, 0x12A6, 0, 3, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 yun_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_043[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x129C, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x129D, 0, 87, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 yun_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_044[44] = {
    L4(3, 131, 0, 0, 0, 0, 0, 0x14B2, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x14B2, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x14B3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x14B1, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x14B1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 yun_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_nmca_045[92] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x12A5, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 613, 0, 0, 0, 0, 0x12A6, 0, 3, 0, 0, 0, 25, 2),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1287, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1288, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1289, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128C, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 yun_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_nmca_046[92] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1265, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1266, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x126B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x126C, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 yun_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yun_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x1229, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x122D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x122D, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 yun_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1229, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x122D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x122D, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yun_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_050[68] = {
    CMD(CM_JSR, 8, 76, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x129C, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x129D, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -6144, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 yun_nmca_051_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_051[88] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x151C, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x151D, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x151E, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x151E, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 yun_nmca_052_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_nmca_052[188] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1320, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1321, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1322, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1323, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1324, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1325, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12C9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12CA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12CB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12CC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 yun_nmca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_053[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9080),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9081),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9082),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9083),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9084),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9085),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9086),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9087),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9088),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9089),
    L2(3, 0, 0, 0, 0, 0, 0, 0x908A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 0 KAMAE */
const u16 yun_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_nmca_000[252] = {
    CMD(CM_FOR, 0, 0, 7), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x1658, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1659, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165A, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165B, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165C, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165D, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165E, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x165F, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1660, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1661, 0, 364, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1662, 0, 364, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1663, 0, 364, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1664, 0, 364, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1664, 0, 345, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x1667, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1668, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1669, 0, 345, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166A, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166B, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166C, 0, 363, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166D, 0, 362, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166E, 0, 362, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x166F, 0, 362, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1670, 0, 362, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1671, 0, 364, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1672, 0, 364, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1673, 0, 364, 0, 0, 0, 0, 0),
    L4(8, 255, 0, 0, 0, 0, 0, 0x1674, 0, 345, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const yun_dmca[99] = {
    yun_dmca_000,  /* 0 GUARD HEAD */
    yun_dmca_001,  /* 1 GUARD UP */
    yun_dmca_002,  /* 2 GUARD DOWN */
    yun_dmca_003,  /* 3 GUARD AIR */
    yun_dmca_004,  /* 4 HUSHIN HEAD */
    yun_dmca_004,  /* 5 HUSHIN UP */
    yun_dmca_006,  /* 6 HUSHIN DOWN */
    yun_dmca_006,  /* 7 HUSHIN AIR */
    yun_dmca_008,  /* 8 FACE S */
    yun_dmca_009,  /* 9 FACE M */
    yun_dmca_010,  /* 10 FACE L */
    yun_dmca_010,  /* 11 FACE SP */
    yun_dmca_008,  /* 12 FOOK OKU S */
    yun_dmca_009,  /* 13 FOOK OKU M */
    yun_dmca_014,  /* 14 FOOK OKU L */
    yun_dmca_014,  /* 15 FOOK OKU SP */
    yun_dmca_008,  /* 16 FOOK TEMAE S */
    yun_dmca_009,  /* 17 FOOK TEMAE M */
    yun_dmca_018,  /* 18 FOOK TEMAE L */
    yun_dmca_018,  /* 19 FOOK TEMAE SP */
    yun_dmca_008,  /* 20 UPPER S */
    yun_dmca_009,  /* 21 UPPER M */
    yun_dmca_022,  /* 22 UPPER L */
    yun_dmca_022,  /* 23 UPPER SP */
    yun_dmca_024,  /* 24 NOUTEN S */
    yun_dmca_025,  /* 25 NOUTEN M */
    yun_dmca_026,  /* 26 NOUTEN L */
    yun_dmca_026,  /* 27 NOUTEN SP */
    yun_dmca_024,  /* 28 BODY BROW S */
    yun_dmca_029,  /* 29 BODY BROW M */
    yun_dmca_030,  /* 30 BODY BROW L */
    yun_dmca_030,  /* 31 BODY BROW SP */
    yun_dmca_024,  /* 32 BODY UPPER S */
    yun_dmca_029,  /* 33 BODY UPPER M */
    yun_dmca_034,  /* 34 BODY UPPER L */
    yun_dmca_034,  /* 35 BODY UPPER SP */
    yun_dmca_036,  /* 36 TATAKI S */
    yun_dmca_036,  /* 37 TATAKI M */
    yun_dmca_036,  /* 38 TATAKI L */
    yun_dmca_036,  /* 39 TATAKI SP */
    yun_dmca_036,  /* 40 TATAKI V. S */
    yun_dmca_036,  /* 41 TATAKI V. M */
    yun_dmca_036,  /* 42 TATAKI V. L */
    yun_dmca_036,  /* 43 TATAKI V. SP */
    yun_dmca_008,  /* 44 NOBASITA TE S */
    yun_dmca_009,  /* 45 NOBASITA TE M */
    yun_dmca_010,  /* 46 NOBASITA TE L */
    yun_dmca_010,  /* 47 NOBASITA TE SP */
    yun_dmca_048,  /* 48 KAGAMI S */
    yun_dmca_049,  /* 49 KAGAMI M */
    yun_dmca_050,  /* 50 KAGAMI L */
    yun_dmca_050,  /* 51 KAGAMI SP */
    yun_dmca_052,  /* 52 KGM TATAKI S */
    yun_dmca_052,  /* 53 KGM TATAKI M */
    yun_dmca_052,  /* 54 KGM TATAKI L */
    yun_dmca_052,  /* 55 KGM TATAKI SP */
    yun_dmca_052,  /* 56 KGM TTKI V.S */
    yun_dmca_052,  /* 57 KGM TTKI V.M */
    yun_dmca_052,  /* 58 KGM TTKI V.L */
    yun_dmca_052,  /* 59 KGM TTKI V.SP */
    yun_dmca_060,  /* 60 NEKOROBI S */
    yun_dmca_060,  /* 61 NEKOROBI M */
    yun_dmca_060,  /* 62 NEKOROBI L */
    yun_dmca_060,  /* 63 NEKOROBI SP */
    yun_dmca_064,  /* 64 OKIAGARI */
    yun_dmca_065,  /* 65 OKIAGARI F */
    yun_dmca_066,  /* 66 OKIAGARI B */
    yun_dmca_067,  /* 67 LOSE NO STAND */
    yun_dmca_068,  /* 68 LOSE SONABA */
    yun_dmca_068,  /* 69 LOSE KAGAMI */
    yun_dmca_070,  /* 70 PIYO */
    yun_dmca_071,  /* 71 UKEMI MOVE F */
    yun_dmca_072,  /* 72 UKEMI MOVE R */
    yun_dmca_073,  /* 73 SHIMEOTASARE */
    yun_dmca_074,  /* 74 TATI TOUKETU S */
    yun_dmca_075,  /* 75 TATI TOUKETU M */
    yun_dmca_076,  /* 76 TATI TOUKETU L */
    yun_dmca_076,  /* 77 TATI TOUKETU P */
    yun_dmca_078,  /* 78 KGM TOUKETU S */
    yun_dmca_079,  /* 79 KGM TOUKETU M */
    yun_dmca_080,  /* 80 KGM TOUKETU L */
    yun_dmca_080,  /* 81 KGM TOUKETU P */
    yun_dmca_082,  /* 82 TATI DENGEKI S */
    yun_dmca_083,  /* 83 TATI DENGEKI M */
    yun_dmca_084,  /* 84 TATI DENGEKI L */
    yun_dmca_084,  /* 85 TATI DENGEKI P */
    yun_dmca_082,  /* 86 KGM DENGEKI S */
    yun_dmca_083,  /* 87 KGM DENGEKI M */
    yun_dmca_084,  /* 88 KGM DENGEKI L */
    yun_dmca_084,  /* 89 KGM DENGEKI P */
    yun_dmca_090,  /* 90 OKIAGARI FRONT */
    yun_dmca_091,  /* 91 OKIAGARI REAR */
    yun_dmca_008,  /* 92 TATI MOE S */
    yun_dmca_009,  /* 93 TATI MOE M */
    yun_dmca_010,  /* 94 TATI MOE L */
    yun_dmca_010,  /* 95 TATI MOE SP */
    yun_dmca_096,  /* 96 no name */
    yun_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 yun_dmca_000_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yun_dmca_000[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x1295, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1296, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1293, 0, 86, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1291, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1290, 0, 86, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1290, 0, 86, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 yun_dmca_001_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 yun_dmca_001[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x129C, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x129D, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x129A, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1298, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1297, 0, 87, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1297, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 yun_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_002[52] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x12A3, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12A4, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x12A1, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x129F, 0, 88, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x129E, 0, 88, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x129E, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 yun_dmca_003_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 yun_dmca_003[160] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x12A6, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x12A7, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x12A5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 139, 0, 0, 0, 0, 0, 0x12A5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 136, 0, 0, 0, 0, 0, 0x129A, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1298, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1297, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 7, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 yun_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_004[36] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x129B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 yun_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_006[44] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x12A2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x12D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12D1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 yun_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 610, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E2, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 yun_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E5, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 136, 610, 0, 0, 0, 0, 0x12E5, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E6, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x12E5, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E2, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 yun_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_010[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 137, 610, 0, 0, 0, 0, 0x12E8, 0, 248, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12E9, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12EA, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12EB, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x12EC, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x12ED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12EE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L, 15 FOOK OKU SP */
const u16 yun_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_014[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 610, 0, 0, 0, 0, 0x12E8, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E9, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x12EA, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x12EB, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x12F5, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x12EC, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x12ED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12EE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L, 19 FOOK TEMAE SP */
const u16 yun_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_018[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12F1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 610, 0, 0, 0, 0, 0x12F1, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x12F2, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x12F3, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x12F4, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x12F5, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x12EC, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x12E1, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x12ED, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12EE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 yun_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_022[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x133C, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 136, 610, 0, 0, 0, 0, 0x1339, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1320, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E6, 0, 247, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E5, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12E1, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x12E2, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 yun_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_025[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12F6, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 135, 610, 0, 0, 0, 0, 0x12F7, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12F8, 0, 254, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x12FA, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12FB, 0, 252, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 yun_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_026[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12F8, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 136, 610, 0, 0, 0, 0, 0x12F8, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12F8, 0, 254, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12F9, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FA, 0, 253, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FB, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 yun_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_024[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1300, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 134, 610, 0, 0, 0, 0, 0x1301, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1301, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1302, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1303, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1304, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1304, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 yun_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_029[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1305, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 136, 610, 0, 0, 0, 0, 0x1305, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1307, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1306, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1301, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1302, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1303, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1304, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1304, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 yun_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1307, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 138, 610, 0, 0, 0, 0, 0x1308, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1309, 0, 254, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1309, 0, 254, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x130A, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x130B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12FA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12FB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 yun_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_034[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1337, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 138, 610, 0, 0, 0, 0, 0x1337, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1338, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1339, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1320, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E6, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E2, 0, 245, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 yun_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_036[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x130A, 0, 255, 0, 0, 0, 0, 0),
    L4(1, 0, 611, 0, 0, 0, 0, 0x1344, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1344, 0, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1345, 0, 255, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 yun_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_048[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1310, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 135, 610, 0, 0, 0, 0, 0x1311, 0, 257, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1311, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1312, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1313, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 yun_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_049[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1317, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 135, 610, 0, 0, 0, 0, 0x1317, 0, 257, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1318, 0, 258, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1311, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1312, 0, 257, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1313, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 yun_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_050[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1318, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 138, 610, 0, 0, 0, 0, 0x131A, 0, 258, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x131B, 0, 259, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x131A, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1318, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1317, 0, 257, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1311, 0, 256, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1312, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1313, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x131E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 yun_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1317, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1345, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 yun_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_060[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x132F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x132E, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x132F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x132E, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1330, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 yun_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_064[140] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1371, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1372, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1373, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x1374, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1375, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1375, 0, 0, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1376, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1377, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1378, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 yun_dmca_065_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_065[280] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1371, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1372, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14FC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14FD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14FE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 128),
    L6(1, 64, 0, 0, 0, 0, 0, 0x14FE, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 yun_dmca_066_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_066[268] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x137A, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x137B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x137C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14FB, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1374, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1375, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1376, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1377, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1378, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 yun_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x1332, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 yun_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_068[196] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x12E0, 0, 380, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x12E4, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x1360, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x1361, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1362, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1363, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1364, 0, 216, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x1367, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x136A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x136B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x136C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x136C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 yun_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1347, 0, 360, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1348, 0, 360, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1349, 0, 360, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x134A, 0, 360, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x134B, 0, 361, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x134C, 0, 361, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x134E, 0, 361, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 yun_dmca_071_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_071[268] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 613, 0, 0, 0, 0, 0x1371, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F9, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 12, 0, 0, 0, 0, 0, 0x14FC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14FD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14FE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x14FE, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 yun_dmca_072_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_072[184] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x137B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x137C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 12, 0, 0, 0, 0, 0, 0x1374, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1375, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1375, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1376, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1377, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1378, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 yun_dmca_073_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_073[172] = {
    L6(2, 0, 609, 0, 0, 0, 0, 0x1360, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x1361, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1362, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1363, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x1364, 0, 380, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1365, 0, 380, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 288, 0, 0, 0, 0, 0x1367, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x136A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x136B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x136C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x136C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 yun_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_074[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E0, 0, 248, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x12E0, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x12E3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 yun_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E4, 0, 248, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x12E4, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x12E2, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 yun_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_076[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x12E7, 0, 248, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x12E7, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x12EE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 yun_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_078[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1310, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1310, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 yun_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_079[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1316, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1316, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1313, 0, 256, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 yun_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_dmca_080[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1319, 0, 256, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1319, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1313, 0, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1314, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1315, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131D, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x131E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x131E, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 yun_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 yun_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 yun_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12D9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 yun_dmca_090_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_090[280] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1371, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1372, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14FC, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14FD, 0, 91, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14FE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 176, 0, 128),
    L6(1, 64, 0, 0, 0, 0, 0, 0x14FE, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 yun_dmca_091_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_091[268] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x137A, 0, 91, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x137B, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x137C, 0, 91, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14F2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x14FB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1374, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1375, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1376, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1377, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1378, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 yun_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_096[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 204, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 yun_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_dmca_097[44] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1332, 0, 21, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1332, 0, 21, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1332, 0, 21, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x1332, 0, 21, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 21, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const yun_btca[37] = {
    yun_btca_000,  /* 0 AIR NORMAL */
    yun_btca_001,  /* 1 ASIBARAI SIRI */
    yun_btca_002,  /* 2 ASIB TUNNOMERI */
    yun_btca_003,  /* 3 NOKEZORI */
    yun_btca_004,  /* 4 KUNOJI */
    yun_btca_005,  /* 5 KIRIMOMI */
    yun_btca_006,  /* 6 UPPER */
    yun_btca_007,  /* 7 BODY UPPER */
    yun_btca_008,  /* 8 HARAYARARE */
    yun_btca_009,  /* 9 TATAKI AIR */
    yun_btca_010,  /* 10 TTKI V. AIR */
    yun_btca_011,  /* 11 HUMI ASIB */
    yun_btca_012,  /* 12 FACE */
    yun_btca_013,  /* 13 ASIB SIRI LOSE */
    yun_btca_014,  /* 14 ASIB TUN LOSE */
    yun_btca_015,  /* 15 DENKI */
    yun_btca_016,  /* 16 KUNOJI NOKE */
    yun_btca_017,  /* 17 BODY UPPER SP */
    yun_btca_018,  /* 18 HANEAGARI */
    yun_btca_019,  /* 19 TOUKETSU A */
    yun_btca_020,  /* 20 BODY SLAM */
    yun_btca_021,  /* 21 IPPONZEOI */
    yun_btca_022,  /* 22 TOMOE RYU */
    yun_btca_023,  /* 23 MONKEY FLIP */
    yun_btca_024,  /* 24 TOMOE ORO */
    yun_btca_025,  /* 25 SNAKE FANG */
    yun_btca_026,  /* 26 FLANKEN.S */
    yun_btca_027,  /* 27 KISHINRIKI */
    yun_btca_028,  /* 28 SPLASH.M */
    yun_btca_029,  /* 29 HARAIGOSHI */
    yun_btca_030,  /* 30 ALEX B.D */
    yun_btca_031,  /* 31 GILL */
    yun_btca_032,  /* 32 HANEKAERI HARA */
    yun_btca_033,  /* 33 S HANEAGARI */
    yun_btca_034,  /* 34 TATUMAKIZANKU */
    yun_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 yun_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_000[68] = {
    CMD(CM_JSR, 8, 56, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 610, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 yun_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1333, 0, 304, 0, 0, 0, 0, 0),
    L4(4, 0, 611, 0, 0, 0, 0, 0x1334, 0, 305, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1335, 0, 306, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1336, 0, 307, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 yun_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_btca_002[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1340, 0, 308, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1341, 0, 309, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1342, 0, 310, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1343, 0, 311, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 yun_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_003[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 yun_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_004[60] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1307, 0, 320, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1308, 0, 321, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1309, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x130A, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1346, 0, 323, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1346, 0, 323, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 yun_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_005[124] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1350, 0, 324, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1351, 0, 325, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1352, 0, 326, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1353, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1354, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1355, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1356, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1357, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1358, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1359, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x135A, 0, 334, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x135B, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x135B, 0, 335, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 yun_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_006[116] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x133C, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1339, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 yun_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_007[108] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x133C, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1339, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 yun_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_008[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 yun_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_009[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 yun_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_010[68] = {
    CMD(CM_RJA, 7, 8, 2), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x12F6, 0, 338, 0, 0, 0, 0, 0),
    L4(4, 0, 611, 0, 0, 0, 0, 0x12F7, 0, 338, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1344, 0, 339, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1345, 0, 340, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1346, 0, 323, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1346, 0, 323, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 yun_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 yun_btca_011[52] = {
    CMD(CM_RJA, 7, 77, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1340, 0, 308, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1341, 0, 309, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1342, 0, 310, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1343, 0, 311, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 yun_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_012[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 yun_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 yun_btca_014_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 yun_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 yun_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_015[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x12D9, 0, 341, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12D9, 0, 341, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DA, 0, 341, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x12D9, 0, 341, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x12DB, 0, 341, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 yun_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_016[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1307, 0, 320, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1308, 0, 321, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1309, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x130A, 0, 322, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 yun_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_017[160] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 611, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x133D, 0, 343, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x133E, 0, 343, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 yun_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_018[124] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 611, 0, 0, 0, 0, 0x1336, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1328, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1327, 0, 91, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1326, 0, 91, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1325, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1324, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 yun_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x12E7, 0, 342, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x12E7, 0, 342, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 yun_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_020[20] = {
    L4(250, 2, 0, 0, 0, 0, 0, 0x135B, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 yun_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_021[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x132F, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 yun_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_022[68] = {
    CMD(CM_RJA, 7, 5, 6), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1342, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1343, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D2, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 yun_btca_023_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_023[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x14D0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D0, 0, 188, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 yun_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_024[28] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x14D0, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 yun_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x1326, 0, 188, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1327, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1328, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 yun_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_026[60] = {
    CMD(CM_RJA, 7, 5, 6), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1343, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 yun_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_027[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 yun_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_028[44] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 yun_btca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_btca_029[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1327, 0, 188, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1328, 0, 188, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1328, 0, 188, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 yun_btca_030_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_btca_030[108] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x133C, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1339, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 yun_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1333, 0, 304, 0, 0, 0, 0, 0),
    L4(6, 0, 611, 0, 0, 0, 0, 0x1334, 0, 305, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1335, 0, 306, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1336, 0, 307, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 yun_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 yun_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_033[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(6, 0, 611, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 yun_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_034[108] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x133A, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 611, 0, 0, 0, 0, 0x133B, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x133C, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1339, 0, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1320, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1321, 0, 313, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1322, 0, 314, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 yun_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_btca_035[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x1323, 0, 315, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1324, 0, 316, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1325, 0, 317, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1326, 0, 318, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1327, 0, 319, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 10 entries */
const u16* const yun_caca[11] = {
    yun_caca_000,  /* 0 CATCH 1 */
    yun_caca_001,  /* 1 CATCH 2 */
    yun_caca_002,  /* 2 CATCH 3 */
    yun_caca_003,  /* 3 CATCH 4 */
    yun_caca_004,  /* 4 CATCH 5 */
    yun_caca_005,  /* 5 CATCH 6 */
    yun_caca_006,  /* 6 CATCH 7 */
    yun_caca_007,  /* 7 CATCH 8 */
    yun_caca_008,  /* 8 CATCH 9 */
    yun_caca_009,  /* 9 CATCH 10 */
    0
};

/* script: 0 CATCH 1 */
const u16 yun_caca_000_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 yun_caca_000[316] = {
    CMD(CM_NGDA, 0, 19, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 264, 0, 0, 0, 0, 0x14B2, -52, 0, 0, 0, 0, 0, 0, 16384, 600, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 0, 0, 16384, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B4, 0, 0, 0, 0, 0, 0, 0, 16384, 648, 0, 0, 0),
    L6(5, 0, 616, 0, 0, 0, 0, 0x14B5, 0, 0, 0, 0, 0, 0, 0, 16384, 672, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x14B6, 0, 0, 0, 0, 0, 0, 0, 16384, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x14B7, 0, 0, 0, 0, 0, 0, 0, 16384, 720, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B8, 0, 0, 0, 0, 0, 0, 0, 16384, 744, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B9, 0, 0, 0, 0, 0, 0, 0, 16384, 768, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14BA, 0, 0, 0, 0, 0, 0, 0, 16384, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BB, 0, 0, 0, 0, 0, 0, 0, 16384, 816, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14BC, 0, 0, 0, 0, 0, 0, 0, 16384, 840, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14BD, 0, 0, 0, 0, 0, 0, 0, 16384, 864, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14BE, 0, 0, 0, 0, 0, 0, 0, 16384, 888, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14BF, 0, 0, 0, 0, 0, 0, 0, 16384, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C0, 0, 0, 0, 0, 0, 0, 0, 16384, 936, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C1, 0, 0, 0, 0, 0, 0, 0, 16384, 960, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C2, 0, 0, 0, 0, 0, 0, 0, 16384, 984, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C3, 0, 0, 0, 0, 0, 0, 0, 16384, 1008, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C4, 0, 0, 0, 0, 0, 0, 0, 16384, 1032, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C5, 0, 0, 0, 0, 0, 0, 0, 16384, 1056, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x14C6, 0, 0, 0, 0, 0, 0, 0, 16384, 1080, 0, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 64, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1290, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1290, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 yun_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yun_caca_001[328] = {
    CMD(CM_NGDA, 1542, 15, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x14B2, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C7, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C8, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C9, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CA, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CB, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CC, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CD, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CE, 0, 0, 0, 0, 0, 0, 0, 0, 528, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 615, 0, 0, 0, 0, 0x14CF, -92, 0, 0, 0, 0, 0, 0, 0, 552, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 9, 0, 0, 0, 0, 0, 0x14D0, 0, 0, 0, 0, 0, 0, 0, 0, 576, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D4, 0, 1, 0, 0, 0, 22, 32, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D7, 0, 1, 0, 0, 0, 24, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x14D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 yun_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yun_caca_002[388] = {
    CMD(CM_NGDA, 1542, 37, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x14B2, 0, 0, 0, 0, 0, 0, 0, 16384, 1104, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 0, 0, 16384, 1128, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B4, 0, 0, 0, 0, 0, 0, 0, 16384, 1152, 0, 0, 0),
    L6(5, 0, 616, 0, 0, 0, 0, 0x14B5, 0, 0, 0, 0, 0, 0, 0, 16384, 1176, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x14B6, 0, 0, 0, 0, 0, 0, 0, 16384, 1200, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x14B7, 0, 0, 0, 0, 0, 0, 0, 16384, 1224, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B8, 0, 0, 0, 0, 0, 0, 0, 16384, 1248, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B9, 0, 0, 0, 0, 0, 0, 0, 16384, 1272, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14BA, 0, 0, 0, 0, 0, 0, 0, 16384, 1296, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BB, 0, 0, 0, 0, 0, 0, 0, 16384, 1320, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14BC, 0, 0, 0, 0, 0, 0, 0, 16384, 1344, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14BD, 0, 0, 0, 0, 0, 0, 0, 16384, 1368, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14BE, 0, 0, 0, 0, 0, 0, 0, 16384, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14BF, 0, 0, 0, 0, 0, 0, 0, 16384, 1416, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C0, 0, 0, 0, 0, 0, 0, 0, 16384, 1440, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C1, 0, 0, 0, 0, 0, 0, 0, 16384, 1464, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C2, 0, 0, 0, 0, 0, 0, 0, 16384, 1488, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C3, 0, 0, 0, 0, 0, 0, 0, 16384, 1512, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C9, 0, 0, 0, 0, 0, 24, 0, 16384, 1560, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CA, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CB, 0, 0, 0, 0, 0, 0, 0, 0, 1608, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CC, 0, 0, 0, 0, 0, 0, 0, 0, 1632, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CD, 0, 0, 0, 0, 0, 0, 0, 0, 1656, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14CE, 0, 0, 0, 0, 0, 0, 0, 0, 1680, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 0, 0, 0, 0, 0, 0x14CF, -92, 0, 0, 0, 0, 0, 0, 0, 1704, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 9, 0, 0, 0, 0, 0, 0x14D0, 0, 0, 0, 0, 0, 0, 0, 0, 1776, 222, 0, 0),
    CMD(CM_JMP, 2, 1, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 yun_caca_003_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yun_caca_003[328] = {
    CMD(CM_NGDA, 1542, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1516, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
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
    L6(3, 0, 613, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 3, 0, 0x1519, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 4, 0, 0x151A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 5, 0, 0x151B, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1519, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1518, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1517, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1516, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 yun_caca_004_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 yun_caca_004[304] = {
    CMD(CM_NGDA, 0, 19, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 264, 0, 0, 0, 0, 0x14B2, -52, 0, 0, 0, 0, 0, 0, 16384, 600, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 0, 0, 16384, 624, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B4, 0, 0, 0, 0, 0, 0, 0, 16384, 648, 0, 0, 0),
    L6(5, 0, 616, 0, 0, 0, 0, 0x14B5, 0, 0, 0, 0, 0, 0, 0, 16384, 672, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x14B6, 0, 0, 0, 0, 0, 0, 0, 16384, 696, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x14B7, 0, 0, 0, 0, 0, 0, 0, 16384, 720, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B8, 0, 0, 0, 0, 0, 0, 0, 16384, 744, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B9, 0, 0, 0, 0, 0, 0, 0, 16384, 768, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14BA, 0, 0, 0, 0, 0, 0, 0, 16384, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BB, 0, 0, 0, 0, 0, 0, 0, 16384, 816, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BC, 0, 0, 0, 0, 0, 0, 0, 16384, 840, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BD, 0, 0, 0, 0, 0, 0, 0, 16384, 864, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14BE, 0, 0, 0, 0, 0, 0, 0, 16384, 888, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14BF, 0, 0, 0, 0, 0, 0, 0, 16384, 912, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C0, 0, 0, 0, 0, 0, 0, 0, 16384, 936, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14C1, 0, 0, 0, 0, 0, 0, 0, 16384, 960, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14C2, 0, 0, 0, 0, 0, 0, 0, 16384, 984, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14C3, 0, 0, 0, 0, 0, 0, 0, 16384, 1008, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14C4, 0, 0, 0, 0, 0, 0, 0, 16384, 1032, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14C5, 0, 0, 0, 0, 0, 0, 0, 16384, 1056, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x14C6, 0, 0, 0, 0, 0, 0, 0, 16384, 1080, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x14B1, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14B3, 0, 1, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 yun_caca_005_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yun_caca_005[328] = {
    CMD(CM_NGDA, 1542, 15, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x14B2, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x14B3, 0, 0, 0, 0, 0, 24, 0, 0, 336, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14C7, 0, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14C8, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14C9, 0, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CA, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CB, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CC, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CD, 0, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PAXY, 0, 4096, -2048), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CE, 0, 0, 0, 0, 0, 0, 0, 0, 528, 222, 0, 0),
    CMD(CM_PA_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 615, 0, 0, 0, 0, 0x14CF, -92, 0, 0, 0, 0, 0, 0, 0, 552, 222, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 9, 0, 0, 0, 0, 0, 0x14D0, 0, 0, 0, 0, 0, 0, 0, 0, 576, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D4, 0, 1, 0, 0, 0, 22, 32, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14D6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D7, 0, 1, 0, 0, 0, 24, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x14D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 1, 0, 0, 0x14D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 CATCH 7 */
const u16 yun_caca_006_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yun_caca_006[136] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 613, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 3, 0, 0x1519, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 4, 0, 0x151A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x151B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1519, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 yun_caca_007_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yun_caca_007[136] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 613, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 3, 0, 0x1519, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 4, 0, 0x151A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x151B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1519, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 yun_caca_008_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 1) };
const u16 yun_caca_008[624] = {
    L6(250, 255, 0, 0, 1, 0, 0, 0x1201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16395, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 613, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 3, 0, 0x1519, -44, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 4, 0, 0x151A, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 5, 0, 0x151B, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1519, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1518, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1517, 0, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0x0006, 0x0015, 0x0000, 0x0001, 0x0069, 0x0606, 0x000B, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x14B2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0018, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x14B3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0030, 0x0000, 0x0000, 0x000C, 0x0000, 0x0000, 0x0004,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1516,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0048, 0x0000, 0x0000, 0x0200, 0x2650, 0x0000, 0x1517,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0060, 0x0000, 0x0000, 0x0200, 0x0000, 0x0020, 0x1518,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0078, 0x0000, 0x0000, 0x0102, 0x0000, 0x0030, 0x1519,
    L6(245, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 144, 0, 0, 0, 0, 771, 0, 64, 21, 26),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00A8, 0x0000, 0x0000, 0x0200, 0x0000, 0x0050, 0x151B,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00C0, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1519,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00D8, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1518,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00F0, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1517,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0108, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1516,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0048, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14B3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0030, 0x0000, 0x0000, 0x0057, 0x0001, 0x0040, 0x4003,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0061, 0x0002, 0x0000, 0x4002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2650, 0x0000, 0x16AE,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16AF,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B1,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B4,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B5,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B6,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0060, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16B7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0078, 0x0000, 0x0000, 0x0202, 0x0000, 0x0000, 0x16B8,
    L6(245, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 515, 0, 0, 22, 193),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0209, 0x0000, 0x0000, 0x16B9,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BA,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BB,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BC,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BD,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BE,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16BF,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1236,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1237,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 9 CATCH 10 */
const u16 yun_caca_009_head[4] = { HEAD(6, 0, 20, 0, 0, 1, 0) };
const u16 yun_caca_009[160] = {
    CMD(CM_NGDA, 1542, 65, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1540, 0, 0, 0, 0, 0, 0, 0, 0, 1824, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1542, 0, 0, 0, 0, 0, 0, 0, 0, 1848, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1543, 0, 0, 0, 0, 0, 0, 0, 0, 1872, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 0, 0, 0, 0, 0, 0, 0, 1896, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 0, 0, 0, 0, 0, 0, 0, 1920, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14CA, 0, 0, 0, 0, 0, 24, 0, 0, 1944, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14CD, 0, 0, 0, 0, 0, 0, 0, 0, 1968, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14CE, 0, 0, 0, 0, 0, 0, 0, 0, 1992, 222, 0, 0),
    CMD(CM_JPSS, 2, 1, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x14CE, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 1992, 222, 0), 0x0302, 0x2670, 0x0000, 0x14CF, 0xE900, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 2016, 222, 0),
};

/* caught scripts: 68 entries */
const u16* const yun_cuca[69] = {
    yun_cuca_000,  /* 0 ALEX ZUTUKI */
    yun_cuca_001,  /* 1 ALEX BODY S */
    yun_cuca_002,  /* 2 ALEX BACK D */
    yun_cuca_003,  /* 3 ALEX POWER B */
    yun_cuca_004,  /* 4 ALEX SLEEPER */
    yun_cuca_005,  /* 5 RYU SEOINAGE */
    yun_cuca_006,  /* 6 IBUKI */
    yun_cuca_007,  /* 7 DADLEY L B */
    yun_cuca_008,  /* 8 IBUKI KUBIORI */
    yun_cuca_009,  /* 9 NECRO S T */
    yun_cuca_010,  /* 10 RYU TOMOENAGE */
    yun_cuca_011,  /* 11 YUN HIZAGERI */
    yun_cuca_012,  /* 12 ORO KUBISIME */
    yun_cuca_013,  /* 13 NECRO G S */
    yun_cuca_014,  /* 14 DUDDLEY D S */
    yun_cuca_015,  /* 15 YUN MONKEY F */
    yun_cuca_016,  /* 16 ORO TOMOENAGE */
    yun_cuca_017,  /* 17 ORO NIOURIKI */
    yun_cuca_018,  /* 18 ORO GIGOKU G */
    yun_cuca_019,  /* 19 YUN */
    yun_cuca_020,  /* 20 NECRO SNAKE F */
    yun_cuca_021,  /* 21 NECRO F S */
    yun_cuca_022,  /* 22 IBUKI HARAIG */
    yun_cuca_023,  /* 23 GILL SPLASH M */
    yun_cuca_024,  /* 24 KEN HIZAGERI */
    yun_cuca_025,  /* 25 ORO KISINRIKI */
    yun_cuca_026,  /* 26 SEAN TACKLE */
    yun_cuca_027,  /* 27 ALEX HYPER B */
    yun_cuca_028,  /* 28 NECRO SLAM D */
    yun_cuca_029,  /* 29 ELENA ASINAGE */
    yun_cuca_030,  /* 30 GILL IMPACT C */
    yun_cuca_031,  /* 31 ALEX S H B */
    yun_cuca_032,  /* 32 ALEX F N D */
    yun_cuca_033,  /* 33 no name */
    yun_cuca_034,  /* 34 IBUKI */
    yun_cuca_035,  /* 35 IBUKI YOROI D */
    yun_cuca_036,  /* 36 no name */
    yun_cuca_037,  /* 37 MAWARIKOMI M F */
    yun_cuca_038,  /* 38 HUGO BODY S */
    yun_cuca_039,  /* 39 HUGO N G T */
    yun_cuca_040,  /* 40 HUGO M S P */
    yun_cuca_041,  /* 41 HUGO S D B B */
    yun_cuca_042,  /* 42 no name */
    yun_cuca_043,  /* 43 no name */
    yun_cuca_044,  /* 44 no name */
    yun_cuca_045,  /* 45 no name */
    yun_cuca_046,  /* 46 no name */
    yun_cuca_047,  /* 47 no name */
    yun_cuca_048,  /* 48 no name */
    yun_cuca_049,  /* 49 no name */
    yun_cuca_050,  /* 50 no name */
    yun_cuca_051,  /* 51 no name */
    yun_cuca_052,  /* 52 no name */
    yun_cuca_053,  /* 53 no name */
    yun_cuca_054,  /* 54 no name */
    yun_cuca_055,  /* 55 no name */
    yun_cuca_056,  /* 56 no name */
    yun_cuca_057,  /* 57 no name */
    yun_cuca_058,  /* 58 no name */
    yun_cuca_059,  /* 59 no name */
    yun_cuca_060,  /* 60 no name */
    yun_cuca_061,  /* 61 no name */
    yun_cuca_062,  /* 62 no name */
    yun_cuca_063,  /* 63 no name */
    yun_cuca_064,  /* 64 no name */
    yun_cuca_065,  /* 65 no name */
    yun_cuca_066,  /* 66 no name */
    yun_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 yun_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    CMD(CM_RMJA, 3, 0, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12F8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 yun_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1338),
    CMD(CM_RMJA, 3, 1, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1328),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 yun_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 yun_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1399),
    L2(250, 0, 0, 0, 0, 0, 0, 0x139B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x14C5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 yun_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133C),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x133A),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 yun_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1337),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12C7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1327),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 yun_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x138B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x138A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 yun_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x133B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 yun_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1350),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 yun_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1320),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 8, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 yun_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1228),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1338),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1335),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1341),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 yun_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1308),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 yun_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1258),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1320),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 yun_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 2, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 yun_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1309),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1309),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 yun_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x137A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1343),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 yun_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x139A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1399),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1326),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1346),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1345),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 yun_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1372),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1326),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1372),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 9),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 yun_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x14FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x14F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 3, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 yun_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E9),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1201),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 yun_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1298),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1299),
    L2(250, 0, 0, 0, 1, 0, 0, 0x129C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1294),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1295),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12B0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1324),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1326),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 yun_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x129D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x129C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1343),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 yun_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1326),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1327),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1327),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 yun_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1336),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 yun_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1309),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 yun_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1372),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1326),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1372),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1323),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 yun_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1346),
    L2(250, 3, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1332),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1332),
    L2(250, 3, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 yun_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_027[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 2, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 2, 0, 0, 0x137A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14C8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 yun_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 2, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 2, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1324),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1324),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 yun_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1343),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1308),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1346),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 yun_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1204),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x133A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 78, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 79, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 yun_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F8),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12F8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 yun_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1309),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 yun_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F9),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 yun_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1344),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1333),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1339),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 yun_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x138B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x138A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x13CF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 yun_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E8),
    L2(250, 2, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1331),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 yun_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_037[136] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x137A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1307),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x1308),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 25, 2),
    CMD(CM_JMP, 6, 23, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 yun_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1343),
    L2(250, 0, 0, 0, 2, 0, 0, 0x12AA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x12A8),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 2, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12C6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1343),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 2, 0, 0, 0x12D2),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1328),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 yun_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 yun_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 yun_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1333),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x135B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1326),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 yun_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1308),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 yun_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 yun_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1332),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x135B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1330),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D2),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1332),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 yun_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12FA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 yun_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1324),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 yun_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1307),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 2, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 2, 0, 0, 0x137A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x14CE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yun_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12F8),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 yun_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1324),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132D),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yun_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1326),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1322),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1321),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1346),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1343),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1342),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 yun_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12EB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12EA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1337),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 2, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1337),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FB),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12E7),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 yun_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1201),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1228),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1341),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1343),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1328),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1346),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1335),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1341),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 yun_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1345),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1329),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1329),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 yun_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1350),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1351),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1352),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1353),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1354),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x133C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 78, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 79, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 yun_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1306),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1308),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1335),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1325),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1327),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1323),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1340),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x12E5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 yun_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 2, 0, 0, 0, 0, 0, 0x12E4),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 9, 0x1335),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 yun_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1305),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1337),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1337),
    L2(250, 0, 0, 0, 0, 0, 0, 0x130A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1344),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1338),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 yun_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1338),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1346),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x133D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1320),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 yun_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1298),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1297),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1290),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1291),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1333),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1322),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 yun_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12ED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12EE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133B),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x12E2),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 yun_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1278),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1276),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1275),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1333),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1334),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1322),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 yun_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F3),
    CMD(CM_PA_X, 0, -1536, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F4),
    CMD(CM_PA_X, 0, 8448, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    CMD(CM_PA_X, 0, -2816, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F7),
    CMD(CM_PA_X, 0, 2304, 0),
    CMD(CM_PS_Y, 0, 0, 4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1342),
    CMD(CM_PA_X, 0, -3584, 0),
    CMD(CM_PS_Y, 0, 0, 32),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1343),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 123),
    L2(250, 0, 0, 0, 2, 0, 0, 0x1339),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1329),
    L2(250, 0, 0, 0, 1, 0, 0, 0x132B),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 yun_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1303),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1304),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1307),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 611, 0, 0, 0, 0, 0x1308),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 yun_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1300),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1340),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1301),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x133A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 yun_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1302),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x12F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1342),
    L2(250, 0, 0, 0, 3, 0, 0, 0x137A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x132F),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1343),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 yun_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1336),
    L2(250, 0, 0, 0, 0, 0, 0, 0x132F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1331),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x132E),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 yun_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12FC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x12E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x133C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1320),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1323),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 264 entries */
const u16* const yun_atca[265] = {
    yun_atca_000,  /* 0 S PUNCH A */
    yun_atca_001,  /* 1 S PUNCH B */
    yun_atca_001,  /* 2 S PUNCH C */
    yun_atca_003,  /* 3 M PUNCH A */
    yun_atca_004,  /* 4 M PUNCH B */
    yun_atca_004,  /* 5 M PUNCH C */
    yun_atca_006,  /* 6 L PUNCH A */
    yun_atca_007,  /* 7 L PUNCH B */
    yun_atca_008,  /* 8 L PUNCH C */
    yun_atca_009,  /* 9 S KICK A */
    yun_atca_009,  /* 10 S KICK B */
    yun_atca_009,  /* 11 S KICK C */
    yun_atca_012,  /* 12 M KICK A */
    yun_atca_013,  /* 13 M KICK B */
    yun_atca_014,  /* 14 M KICK C */
    yun_atca_015,  /* 15 L KICK A */
    yun_atca_015,  /* 16 L KICK B */
    yun_atca_015,  /* 17 L KICK C */
    yun_atca_018,  /* 18 KAGAMI P A */
    yun_atca_018,  /* 19 KAGAMI P B */
    yun_atca_018,  /* 20 KAGAMI P C */
    yun_atca_021,  /* 21 KAGAMI P A */
    yun_atca_021,  /* 22 KAGAMI P B */
    yun_atca_021,  /* 23 KAGAMI P C */
    yun_atca_024,  /* 24 KAGAMI P A */
    yun_atca_024,  /* 25 KAGAMI P B */
    yun_atca_024,  /* 26 KAGAMI P C */
    yun_atca_027,  /* 27 KAGAMI K A */
    yun_atca_027,  /* 28 KAGAMI K B */
    yun_atca_027,  /* 29 KAGAMI K C */
    yun_atca_030,  /* 30 KAGAMI K A */
    yun_atca_030,  /* 31 KAGAMI K B */
    yun_atca_030,  /* 32 KAGAMI K C */
    yun_atca_033,  /* 33 KAGAMI K A */
    yun_atca_033,  /* 34 KAGAMI K B */
    yun_atca_033,  /* 35 KAGAMI K C */
    yun_atca_036,  /* 36 V JUMP P S A */
    yun_atca_036,  /* 37 V JUMP P S B */
    yun_atca_038,  /* 38 V JUMP P M A */
    yun_atca_038,  /* 39 V JUMP P M B */
    yun_atca_040,  /* 40 V JUMP P L A */
    yun_atca_040,  /* 41 V JUMP P L B */
    yun_atca_042,  /* 42 V JUMP K S A */
    yun_atca_042,  /* 43 V JUMP K S B */
    yun_atca_044,  /* 44 V JUMP K M A */
    yun_atca_044,  /* 45 V JUMP K M B */
    yun_atca_046,  /* 46 V JUMP K L A */
    yun_atca_046,  /* 47 V JUMP K L B */
    yun_atca_048,  /* 48 F JUMP P S A */
    yun_atca_048,  /* 49 F JUMP P S B */
    yun_atca_050,  /* 50 F JUMP P M A */
    yun_atca_050,  /* 51 F JUMP P M B */
    yun_atca_052,  /* 52 F JUMP P L A */
    yun_atca_052,  /* 53 F JUMP P L B */
    yun_atca_054,  /* 54 F JUMP K S A */
    yun_atca_055,  /* 55 F JUMP K S B */
    yun_atca_056,  /* 56 F JUMP K M A */
    yun_atca_057,  /* 57 F JUMP K M B */
    yun_atca_058,  /* 58 F JUMP K L A */
    yun_atca_059,  /* 59 F JUMP K L B */
    yun_atca_060,  /* 60 B JUMP P S A */
    yun_atca_060,  /* 61 B JUMP P S B */
    yun_atca_062,  /* 62 B JUMP P M A */
    yun_atca_062,  /* 63 B JUMP P M B */
    yun_atca_064,  /* 64 B JUMP P L A */
    yun_atca_064,  /* 65 B JUMP P L B */
    yun_atca_066,  /* 66 B JUMP K S A */
    yun_atca_066,  /* 67 B JUMP K S B */
    yun_atca_068,  /* 68 B JUMP K M A */
    yun_atca_068,  /* 69 B JUMP K M B */
    yun_atca_070,  /* 70 B JUMP K L A */
    yun_atca_070,  /* 71 B JUMP K L B */
    yun_atca_072,  /* 72 SP V JP S P A */
    yun_atca_072,  /* 73 SP V JP S P B */
    yun_atca_074,  /* 74 SP V JP M P A */
    yun_atca_074,  /* 75 SP V JP M P B */
    yun_atca_076,  /* 76 SP V JP L P A */
    yun_atca_076,  /* 77 SP V JP L P B */
    yun_atca_078,  /* 78 SP V JP S K A */
    yun_atca_078,  /* 79 SP V JP S K B */
    yun_atca_080,  /* 80 SP V JP M K A */
    yun_atca_080,  /* 81 SP V JP M K B */
    yun_atca_082,  /* 82 SP V JP L K A */
    yun_atca_082,  /* 83 SP V JP L K B */
    yun_atca_084,  /* 84 SP F JP S P A */
    yun_atca_084,  /* 85 SP F JP S P B */
    yun_atca_086,  /* 86 SP F JP M P A */
    yun_atca_086,  /* 87 SP F JP M P B */
    yun_atca_088,  /* 88 SP F JP L P A */
    yun_atca_088,  /* 89 SP F JP L P B */
    yun_atca_090,  /* 90 SP F JP S K A */
    yun_atca_091,  /* 91 SP F JP S K B */
    yun_atca_092,  /* 92 SP F JP M K A */
    yun_atca_093,  /* 93 SP F JP M K B */
    yun_atca_094,  /* 94 SP F JP L K A */
    yun_atca_095,  /* 95 SP F JP L K B */
    yun_atca_096,  /* 96 SP B JP S P A */
    yun_atca_096,  /* 97 SP B JP S P B */
    yun_atca_098,  /* 98 SP B JP M P A */
    yun_atca_098,  /* 99 SP B JP M P B */
    yun_atca_100,  /* 100 SP B JP L P A */
    yun_atca_100,  /* 101 SP B JP L P B */
    yun_atca_102,  /* 102 SP B JP S K A */
    yun_atca_102,  /* 103 SP B JP S K B */
    yun_atca_104,  /* 104 SP B JP M K A */
    yun_atca_104,  /* 105 SP B JP M K B */
    yun_atca_106,  /* 106 SP B JP L K A */
    yun_atca_106,  /* 107 SP B JP L K B */
    yun_atca_108,  /* 108 S V JP S P A */
    yun_atca_108,  /* 109 S V JP S P B */
    yun_atca_110,  /* 110 S V JP M P A */
    yun_atca_110,  /* 111 S V JP M P B */
    yun_atca_112,  /* 112 S V JP L P A */
    yun_atca_112,  /* 113 S V JP L P B */
    yun_atca_114,  /* 114 S V JP S K A */
    yun_atca_114,  /* 115 S V JP S K B */
    yun_atca_116,  /* 116 S V JP M K A */
    yun_atca_116,  /* 117 S V JP M K B */
    yun_atca_118,  /* 118 S V JP L K A */
    yun_atca_118,  /* 119 S V JP L K B */
    yun_atca_108,  /* 120 S F JP S P A */
    yun_atca_108,  /* 121 S F JP S P B */
    yun_atca_110,  /* 122 S F JP M P A */
    yun_atca_110,  /* 123 S F JP M P B */
    yun_atca_112,  /* 124 S F JP L P A */
    yun_atca_112,  /* 125 S F JP L P B */
    yun_atca_114,  /* 126 S F JP S K A */
    yun_atca_114,  /* 127 S F JP S K B */
    yun_atca_116,  /* 128 S F JP M K A */
    yun_atca_116,  /* 129 S F JP M K B */
    yun_atca_118,  /* 130 S F JP L K A */
    yun_atca_118,  /* 131 S F JP L K B */
    yun_atca_108,  /* 132 S B JP S P A */
    yun_atca_108,  /* 133 S B JP S P B */
    yun_atca_110,  /* 134 S B JP M P A */
    yun_atca_110,  /* 135 S B JP M P B */
    yun_atca_112,  /* 136 S B JP L P A */
    yun_atca_112,  /* 137 S B JP L P B */
    yun_atca_114,  /* 138 S B JP S K A */
    yun_atca_114,  /* 139 S B JP S K B */
    yun_atca_116,  /* 140 S B JP M K A */
    yun_atca_116,  /* 141 S B JP M K B */
    yun_atca_118,  /* 142 S B JP L K A */
    yun_atca_118,  /* 143 S B JP L K B */
    yun_atca_144,  /* 144 TUKAMIKAKARI A */
    yun_atca_145,  /* 145 TUKAMIKAKARI B */
    yun_atca_146,  /* 146 TUKAMIKAKARI C */
    yun_atca_144,  /* 147 TUKAMIKAKARI D */
    yun_atca_144,  /* 148 TUKAMIKAKARI E */
    yun_atca_144,  /* 149 TUKAMIKAKARI F */
    yun_atca_144,  /* 150 TUKAMI AIR A */
    yun_atca_144,  /* 151 TUKAMI AIR B */
    yun_atca_144,  /* 152 TUKAMI AIR C */
    yun_atca_144,  /* 153 TUKAMI AIR D */
    yun_atca_144,  /* 154 TUKAMI AIR E */
    yun_atca_144,  /* 155 TUKAMI AIR F */
    yun_atca_156,  /* 156 follow-up of V JUMP P S A, F JUMP P S A */
    yun_atca_156,  /* 157 no name */
    yun_atca_158,  /* 158 follow-up of M PUNCH A, M PUNCH B */
    yun_atca_159,  /* 159 follow-up of follow-up of M PUNCH A, M PUNCH B */
    yun_atca_160,  /* 160 follow-up of S KICK A */
    yun_atca_161,  /* 161 follow-up of follow-up of S KICK A */
    yun_atca_162,  /* 162 follow-up of S PUNCH A, S PUNCH B */
    yun_atca_163,  /* 163 follow-up of follow-up of S PUNCH A, S PUNCH B */
    yun_atca_164,  /* 164 follow-up of KAGAMI P A */
    yun_atca_159,  /* 165 no name */
    yun_atca_159,  /* 166 no name */
    yun_atca_159,  /* 167 no name */
    yun_atca_159,  /* 168 no name */
    yun_atca_159,  /* 169 no name */
    yun_atca_159,  /* 170 no name */
    yun_atca_159,  /* 171 no name */
    yun_atca_159,  /* 172 no name */
    yun_atca_159,  /* 173 no name */
    yun_atca_159,  /* 174 no name */
    yun_atca_159,  /* 175 no name */
    yun_atca_159,  /* 176 no name */
    yun_atca_159,  /* 177 no name */
    yun_atca_159,  /* 178 no name */
    yun_atca_159,  /* 179 no name */
    yun_atca_159,  /* 180 no name */
    yun_atca_159,  /* 181 no name */
    yun_atca_159,  /* 182 no name */
    yun_atca_159,  /* 183 no name */
    yun_atca_159,  /* 184 no name */
    yun_atca_159,  /* 185 no name */
    yun_atca_159,  /* 186 no name */
    yun_atca_159,  /* 187 no name */
    yun_atca_159,  /* 188 no name */
    yun_atca_159,  /* 189 no name */
    yun_atca_159,  /* 190 no name */
    yun_atca_159,  /* 191 no name */
    yun_atca_159,  /* 192 no name */
    yun_atca_159,  /* 193 no name */
    yun_atca_159,  /* 194 no name */
    yun_atca_159,  /* 195 no name */
    yun_atca_159,  /* 196 no name */
    yun_atca_159,  /* 197 no name */
    yun_atca_159,  /* 198 no name */
    yun_atca_159,  /* 199 no name */
    yun_atca_200,  /* 200 follow-up of ZANNEN 2 */
    yun_atca_201,  /* 201 follow-up of ZANNEN 3 */
    yun_atca_201,  /* 202 no name */
    yun_atca_203,  /* 203 follow-up of ZANNEN 4 */
    yun_atca_204,  /* 204 no name */
    yun_atca_204,  /* 205 follow-up of ZANNEN 5 */
    yun_atca_206,  /* 206 follow-up of JUDGMENT WAIT */
    yun_atca_207,  /* 207 follow-up of ZANNEN 6 */
    yun_atca_208,  /* 208 follow-up of APPEAR USE */
    yun_atca_209,  /* 209 follow-up of ZANNEN 7 */
    yun_atca_209,  /* 210 no name */
    yun_atca_209,  /* 211 no name */
    yun_atca_212,  /* 212 follow-up of APPEAR USE */
    yun_atca_213,  /* 213 follow-up of ZANNEN 8 */
    yun_atca_214,  /* 214 follow-up of JUDGMENT WAIT */
    yun_atca_215,  /* 215 no name */
    yun_atca_215,  /* 216 follow-up of WIN 1 */
    yun_atca_215,  /* 217 follow-up of JUDGMENT WAIT */
    yun_atca_218,  /* 218 follow-up of WIN 2 */
    yun_atca_218,  /* 219 no name */
    yun_atca_218,  /* 220 no name */
    yun_atca_221,  /* 221 follow-up of WIN 3 */
    yun_atca_221,  /* 222 no name */
    yun_atca_221,  /* 223 no name */
    yun_atca_224,  /* 224 follow-up of WIN 4 */
    yun_atca_224,  /* 225 no name */
    yun_atca_224,  /* 226 no name */
    yun_atca_227,  /* 227 follow-up of WIN 5 */
    yun_atca_227,  /* 228 no name */
    yun_atca_227,  /* 229 no name */
    yun_atca_230,  /* 230 follow-up of WIN 6 */
    yun_atca_230,  /* 231 no name */
    yun_atca_230,  /* 232 no name */
    yun_atca_233,  /* 233 follow-up of WIN 7 */
    yun_atca_233,  /* 234 no name */
    yun_atca_233,  /* 235 no name */
    yun_atca_236,  /* 236 follow-up of JUDGMENT LOSE */
    yun_atca_236,  /* 237 no name */
    yun_atca_238,  /* 238 follow-up of JUDGMENT LOSE */
    yun_atca_238,  /* 239 no name */
    yun_atca_240,  /* 240 follow-up of JUDGMENT LOSE */
    yun_atca_240,  /* 241 no name */
    yun_atca_242,  /* 242 follow-up of WAIT */
    yun_atca_242,  /* 243 no name */
    yun_atca_244,  /* 244 follow-up of AFRICA JUMP */
    yun_atca_244,  /* 245 no name */
    yun_atca_246,  /* 246 follow-up of AFRICA LAND */
    yun_atca_246,  /* 247 no name */
    yun_atca_248,  /* 248 follow-up of SEAN BALL HIT */
    yun_atca_248,  /* 249 no name */
    yun_atca_250,  /* 250 follow-up of follow-up of F JUMP P M A */
    yun_atca_250,  /* 251 no name */
    yun_atca_252,  /* 252 follow-up of BONUS WIN 1 */
    yun_atca_252,  /* 253 no name */
    yun_atca_254,  /* 254 follow-up of BONUS WIN 2 */
    yun_atca_255,  /* 255 follow-up of BONUS WIN 3 */
    yun_atca_256,  /* 256 follow-up of APPEAR USE */
    yun_atca_257,  /* 257 follow-up of APPEAR USE */
    yun_atca_258,  /* 258 follow-up of APPEAR USE */
    yun_atca_259,  /* 259 follow-up of APPEAR USE */
    yun_atca_260,  /* 260 follow-up of APPEAR USE */
    yun_atca_260,  /* 261 no name */
    yun_atca_262,  /* 262 follow-up of KAGAMI K A */
    yun_atca_263,  /* 263 follow-up of follow-up of SEAN BALL HIT */
    0
};

/* script: 3 M PUNCH A */
const u16 yun_atca_003_head[4] = { HEAD(6, 0, 2, 8, 0, 1, 0) };
const u16 yun_atca_003[148] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x13D8, 0, 33, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13D9, 0, 33, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C3, -8, 34, 2245, 136, 104, 0, 0, 0, 0, 322, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13C4, 0, 35, 2245, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13C5, 0, 36, 2245, 0, 104, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13C2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 324, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x13C1, 0, 33, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B, 5 M PUNCH C */
const u16 yun_atca_004_head[4] = { HEAD(6, 0, 2, 9, 0, 1, 0) };
const u16 yun_atca_004[160] = {
    CMD(CM_JPSS, 8, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x138D, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x138E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1390, -7, 31, 2245, 0, 8, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1392, 0, 136, 2245, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1391, 0, 136, 2245, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1391, 0, 137, 2245, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1393, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1394, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1395, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 yun_atca_006_head[4] = { HEAD(6, 0, 4, 9, 0, 1, 0) };
const u16 yun_atca_006[232] = {
    CMD(CM_JPSS, 8, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C6, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 613, 0, 0, 0, 0, 0x13C7, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C8, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C9, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CA, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x13CB, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CC, -9, 38, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13CC, 0, 38, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CD, -41, 39, 0, 128, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13CE, 9, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13CF, 0, 41, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13D0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x13D1, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13D2, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B */
const u16 yun_atca_007_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 yun_atca_007[232] = {
    CMD(CM_JPSS, 8, 29, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1397, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1398, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1399, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x139A, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x139B, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x139C, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A0, -10, 44, 0, 139, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A0, 0, 45, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13A1, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x13A2, 0, 46, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13B7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13B8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x13B9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13BA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 yun_atca_008_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 yun_atca_008[304] = {
    CMD(CM_JPSS, 8, 88, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1691, 0, 108, 0, 0, 0, 0, 0, 0, 0, 404, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1692, 0, 108, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1693, 0, 108, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1694, 0, 108, 0, 0, 0, 0, 0, 0, 0, 410, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1695, 0, 225, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1696, 0, 225, 0, 0, 0, 0, 0, 0, 0, 414, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1697, 0, 225, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1698, 0, 225, 0, 0, 0, 0, 0, 0, 0, 418, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x1699, -170, 261, 0, 128, 0, 0, 0, 0, 0, 420, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169A, 0, 262, 0, 0, 0, 30, 50, 0, 0, 422, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169B, 0, 262, 0, 0, 0, 0, 0, 0, 0, 424, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169C, 0, 263, 0, 0, 0, 21, 0, 0, 0, 426, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169D, 0, 263, 0, 0, 0, 0, 0, 0, 0, 428, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169E, 0, 263, 0, 0, 0, 0, 0, 0, 0, 430, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x169F, 0, 263, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 434, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16A2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 440, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 442, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 444, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 yun_atca_009_head[4] = { HEAD(6, 0, 1, 8, 0, 1, 0) };
const u16 yun_atca_009[160] = {
    CMD(CM_RMJA, 4, 160, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 30, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x13E4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E5, -12, 56, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13E6, 12, 57, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13E8, 0, 1, 0, 0, 0, 21, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x13EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 yun_atca_012_head[4] = { HEAD(4, 0, 3, 13, 0, 1, 0) };
const u16 yun_atca_012[140] = {
    CMD(CM_JPSS, 8, 89, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x13ED, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x13EE, 0, 10, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x13EF, 0, 10, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13EF, -2, 220, 0, 128, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13F0, 2, 12, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13F0, 2, 13, 0, 0, 1, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13F1, 2, 13, 0, 0, 1, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x13F1, 0, 14, 0, 0, 1, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x13F2, 0, 14, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x13F3, 0, 15, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x13F4, 0, 15, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x13F5, 0, 59, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13F6, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x13F7, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 yun_atca_013_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 yun_atca_013[256] = {
    CMD(CM_JPSS, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x16D3, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16D4, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D5, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D6, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x16D7, 0, 267, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D8, -1, 268, 0, 128, 0, 0, 0, 0, 0, 370, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16D9, 0, 269, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DA, 0, 270, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DB, 0, 270, 0, 0, 0, 0, 0, 0, 0, 374, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DC, 0, 271, 0, 0, 0, 0, 0, 0, 0, 376, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DD, 0, 267, 0, 0, 0, 0, 0, 0, 0, 378, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DE, 0, 267, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16DF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 382, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x16E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 386, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x16E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 yun_atca_014_head[4] = { HEAD(6, 0, 3, 13, 0, 1, 0) };
const u16 yun_atca_014[208] = {
    CMD(CM_JPSS, 8, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 8, 0, 0, 0, 0, 0, 0x13FA, 0, 98, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13FB, 0, 98, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13FC, 0, 99, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 1, 616, 0, 0, 0, 0, 0x13FD, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13FE, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13FF, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1400, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1401, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 1, 0, 0, 0, 0x1402, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x1403, -18, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x1404, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x1404, 0, 146, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1405, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1406, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 yun_atca_015_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 yun_atca_015[280] = {
    CMD(CM_JPSS, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 8, 0, 0, 0, 0, 0, 0x15AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x15B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 6, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(5, 0, 616, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B4, -42, 195, 0, 140, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 196, 0, 140, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 205, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B6, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 0, 0, 0x15B7, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x15B8, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x15B9, 0, 197, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x15BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 yun_atca_018_head[4] = { HEAD(4, 32, 0, 11, 0, 1, 0) };
const u16 yun_atca_018[100] = {
    CMD(CM_JPSS, 8, 33, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1431, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1432, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1431, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1432, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -14, 207, 0, 137, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1434, 0, 208, 0, 137, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1435, 0, 209, 0, 0, 112, 21, 5),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1436, 0, 206, 0, 0, 16, 0, 5),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 yun_atca_021_head[4] = { HEAD(4, 32, 2, 11, 0, 1, 0) };
const u16 yun_atca_021[92] = {
    CMD(CM_JPSS, 8, 34, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 164, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1430, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1431, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1432, 0, 60, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1433, -45, 93, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1434, 0, 94, 2114, 0, 104, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1434, 0, 63, 2114, 0, 8, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1435, 0, 63, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1436, 0, 60, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 yun_atca_024_head[4] = { HEAD(4, 32, 4, 13, 0, 1, 0) };
const u16 yun_atca_024[140] = {
    CMD(CM_JPSS, 8, 35, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1438, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 616, 0, 0, 0, 0, 0x1439, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x143A, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143B, -46, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143C, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143D, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143E, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143F, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 616, 0, 0, 0, 0, 0x1431, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x1432, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -47, 95, 0, 142, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1434, 0, 96, 0, 142, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1435, 0, 66, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1436, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 yun_atca_027_head[4] = { HEAD(4, 32, 1, 9, 0, 1, 0) };
const u16 yun_atca_027[100] = {
    CMD(CM_JPSS, 8, 36, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1444, 0, 381, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1444, 0, 381, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1447, -15, 382, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1446, 0, 383, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1446, 0, 383, 0, 0, 112, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1444, 0, 381, 0, 0, 16, 0, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1443, 0, 381, 0, 0, 16, 0, 1),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1442, 0, 384, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1441, 0, 384, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1440, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1440, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 yun_atca_030_head[4] = { HEAD(6, 32, 3, 14, 0, 1, 0) };
const u16 yun_atca_030[444] = {
    CMD(CM_JPSS, 8, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x1610, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x1612, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1613, 0, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1614, -48, 390, 0, 134, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1615, 0, 391, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1615, 0, 392, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1616, 0, 392, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1617, 0, 393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1618, 0, 393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1619, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x161A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x161B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x161C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x2005, 0x0D00, 0x0100, 0x0004, 0x0008, 0x0026, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x001E, 0x0004, 0x0106, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x2680, 0x0000, 0x1449,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1449,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0078, 0x0000, 0x0100, 0x0000, 0x0000, 0x144A,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0100, 0x0000, 0x0000, 0x144B,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0100, 0x0000, 0x0000, 0x144C,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0100, 0x0000, 0x0000, 0x144D,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0100, 0x0000, 0x0000, 0x144E,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0100, 0x10E0, 0x0000, 0x144F,
    CMD(CM_ADDR, 24576, 0, 0), 0x0000, 0x0000, 0x007A, 0x0000, 0x0300, 0x0000, 0x0000, 0x1450,
    L6(243, 137, 1224, 1, 1, 0, 8, 0x0000, 0, 0, 0, 0, 122, 0, 0, 512, 0, 0, 20, 81),
    CMD(CM_ADDR, 24576, 0, 5376), 0x0000, 0x0000, 0x007C, 0x0000, 0x0200, 0x0000, 0x0000, 0x1452,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007C, 0x0000, 0x0100, 0x0000, 0x0000, 0x1453,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x1454,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007E, 0x0000, 0x0100, 0x0000, 0x0000, 0x1455,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007E, 0x0000, 0x0200, 0x0000, 0x0000, 0x1456,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007E, 0x0000, 0x0200, 0x0000, 0x0000, 0x1457,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1458,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x007E, 0x0000, 0x0200, 0x0000, 0x0000, 0x1459,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x145A,
    CMD(CM_SETR, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x145B,
    CMD(CM_DUMMY, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 yun_atca_036_head[4] = { HEAD(4, 22, 0, 7, 0, 1, 0) };
const u16 yun_atca_036[124] = {
    CMD(CM_JPSS, 8, 57, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x1460, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x1461, 0, 139, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1462, -31, 141, 2244, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1463, 0, 141, 2244, 0, 8, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1464, 0, 141, 2244, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1465, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1466, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1467, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1468, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1469, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x146A, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 yun_atca_038_head[4] = { HEAD(4, 22, 2, 9, 0, 1, 0) };
const u16 yun_atca_038[116] = {
    CMD(CM_JPSS, 8, 58, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x1470, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1471, -32, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1472, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1473, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1474, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1474, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1475, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 yun_atca_040_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 0) };
const u16 yun_atca_040[180] = {
    CMD(CM_JPSS, 8, 59, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147E, -33, 165, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x147F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1480, 0, 162, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1481, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1481, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1480, 0, 215, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 yun_atca_042_head[4] = { HEAD(4, 22, 1, 10, 0, 1, 0) };
const u16 yun_atca_042[156] = {
    CMD(CM_JPSS, 8, 60, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1493, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1495, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1496, -34, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1497, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1499, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1495, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1493, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 yun_atca_044_head[4] = { HEAD(4, 22, 3, 10, 0, 1, 0) };
const u16 yun_atca_044[164] = {
    CMD(CM_JPSS, 8, 68, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x15D3, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x15D4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 6, 0x15D5, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x15D6, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x15D7, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x15D8, -69, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x15D9, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x15DA, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x15DB, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x15DC, 0, 224, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x15DD, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 yun_atca_046_head[4] = { HEAD(4, 22, 5, 10, 0, 1, 0) };
const u16 yun_atca_046[124] = {
    CMD(CM_JPSS, 8, 62, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A0, -36, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 yun_atca_048_head[4] = { HEAD(4, 20, 0, 8, 0, 1, 0) };
const u16 yun_atca_048[124] = {
    CMD(CM_JPSS, 8, 63, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 10, 0x1460, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 10, 0x1461, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1462, -65, 140, 2244, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1463, 0, 140, 2244, 0, 8, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1464, 0, 140, 2244, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1465, 0, 140, 2244, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1466, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1467, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1468, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1469, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x146A, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 yun_atca_050_head[4] = { HEAD(4, 20, 2, 10, 0, 1, 0) };
const u16 yun_atca_050[116] = {
    CMD(CM_JPSS, 8, 64, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 10, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 10, 0x1470, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1471, -66, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1472, 66, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1473, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1474, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x1474, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x1475, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 yun_atca_052_head[4] = { HEAD(4, 20, 4, 11, 0, 1, 0) };
const u16 yun_atca_052[108] = {
    CMD(CM_JPSS, 8, 65, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x146E, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1471, -67, 142, 0, 136, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1472, 0, 143, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1473, 0, 143, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x1474, 0, 143, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x1475, 0, 135, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A */
const u16 yun_atca_054_head[4] = { HEAD(4, 20, 1, 11, 0, 1, 0) };
const u16 yun_atca_054[156] = {
    CMD(CM_JPSS, 8, 66, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1493, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1495, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1496, -68, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1497, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1499, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1495, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1493, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 F JUMP K S B */
const u16 yun_atca_055_head[4] = { HEAD(4, 20, 1, 5, 0, 1, 43) };
const u16 yun_atca_055[84] = {
    CMD(CM_JPSS, 8, 67, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -71, 301, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 302, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 302, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A */
const u16 yun_atca_056_head[4] = { HEAD(4, 20, 3, 12, 0, 1, 0) };
const u16 yun_atca_056[164] = {
    CMD(CM_JPSS, 8, 68, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 7, 0x15D3, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x15D4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 7, 0x15D5, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x15D6, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x15D7, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x15D8, -69, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x15D9, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x15DA, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x15DB, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x15DC, 0, 224, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x15DD, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 F JUMP K M B */
const u16 yun_atca_057_head[4] = { HEAD(4, 20, 3, 5, 0, 1, 43) };
const u16 yun_atca_057[84] = {
    CMD(CM_JPSS, 8, 69, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(4, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -71, 180, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A */
const u16 yun_atca_058_head[4] = { HEAD(4, 20, 5, 11, 0, 1, 0) };
const u16 yun_atca_058[124] = {
    CMD(CM_JPSS, 8, 70, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A0, -36, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 F JUMP K L B */
const u16 yun_atca_059_head[4] = { HEAD(4, 20, 5, 5, 0, 1, 43) };
const u16 yun_atca_059[84] = {
    CMD(CM_JPSS, 8, 71, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -71, 180, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 yun_atca_060_head[4] = { HEAD(2, 24, 0, 0, 0, 1, 0) };
const u16 yun_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 yun_atca_062_head[4] = { HEAD(2, 24, 2, 0, 0, 1, 0) };
const u16 yun_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 yun_atca_064_head[4] = { HEAD(2, 24, 4, 0, 0, 1, 0) };
const u16 yun_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 yun_atca_066_head[4] = { HEAD(2, 24, 1, 0, 0, 1, 0) };
const u16 yun_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 yun_atca_068_head[4] = { HEAD(2, 24, 3, 0, 0, 1, 0) };
const u16 yun_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 yun_atca_070_head[4] = { HEAD(2, 24, 5, 0, 0, 1, 0) };
const u16 yun_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 yun_atca_072_head[4] = { HEAD(2, 28, 0, 0, 0, 1, 0) };
const u16 yun_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 yun_atca_074_head[4] = { HEAD(2, 28, 2, 0, 0, 1, 0) };
const u16 yun_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 yun_atca_076_head[4] = { HEAD(2, 28, 4, 0, 0, 1, 0) };
const u16 yun_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 yun_atca_078_head[4] = { HEAD(2, 28, 1, 0, 0, 1, 0) };
const u16 yun_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 yun_atca_080_head[4] = { HEAD(2, 28, 3, 0, 0, 1, 0) };
const u16 yun_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 yun_atca_082_head[4] = { HEAD(2, 28, 5, 0, 0, 1, 0) };
const u16 yun_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 yun_atca_084_head[4] = { HEAD(2, 26, 0, 0, 0, 1, 0) };
const u16 yun_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 yun_atca_086_head[4] = { HEAD(2, 26, 2, 0, 0, 1, 0) };
const u16 yun_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 yun_atca_088_head[4] = { HEAD(2, 26, 4, 0, 0, 1, 0) };
const u16 yun_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A */
const u16 yun_atca_090_head[4] = { HEAD(2, 26, 1, 0, 0, 1, 0) };
const u16 yun_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 SP F JP S K B */
const u16 yun_atca_091_head[4] = { HEAD(2, 26, 1, 0, 0, 1, 0) };
const u16 yun_atca_091[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A */
const u16 yun_atca_092_head[4] = { HEAD(2, 26, 3, 0, 0, 1, 0) };
const u16 yun_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 93 SP F JP M K B */
const u16 yun_atca_093_head[4] = { HEAD(2, 26, 3, 0, 0, 1, 0) };
const u16 yun_atca_093[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A */
const u16 yun_atca_094_head[4] = { HEAD(2, 26, 5, 0, 0, 1, 0) };
const u16 yun_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 95 SP F JP L K B */
const u16 yun_atca_095_head[4] = { HEAD(2, 26, 5, 0, 0, 1, 0) };
const u16 yun_atca_095[8] = {
    CMD(CM_JPSS, 4, 57, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 yun_atca_096_head[4] = { HEAD(2, 30, 0, 0, 0, 1, 0) };
const u16 yun_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 yun_atca_098_head[4] = { HEAD(2, 30, 2, 0, 0, 1, 0) };
const u16 yun_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 yun_atca_100_head[4] = { HEAD(2, 30, 4, 0, 0, 1, 0) };
const u16 yun_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 yun_atca_102_head[4] = { HEAD(2, 30, 1, 0, 0, 1, 0) };
const u16 yun_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 yun_atca_104_head[4] = { HEAD(2, 30, 3, 0, 0, 1, 0) };
const u16 yun_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 yun_atca_106_head[4] = { HEAD(2, 30, 5, 0, 0, 1, 0) };
const u16 yun_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 yun_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 1, 0) };
const u16 yun_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 yun_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 1, 0) };
const u16 yun_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 yun_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 1, 0) };
const u16 yun_atca_112[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 yun_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 1, 0) };
const u16 yun_atca_114[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 yun_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 1, 0) };
const u16 yun_atca_116[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 yun_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 1, 0) };
const u16 yun_atca_118[80] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_JPSS, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_DUMMY, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x1298),
    L2(240, 82, 1536, 0, 0, 0, 0, 0x0000),
    L2(1, 0, 268, 0, 0, 0, 0, 0x1298),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x13A3),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1298),
    CMD(CM_DUMMY, 8192, 0, 5376),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1297),
    CMD(CM_DUMMY, 8192, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1297),
    CMD(CM_DUMMY, 8192, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of V JUMP P S A, F JUMP P S A, 157 no name */
const u16 yun_atca_156_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 0) };
const u16 yun_atca_156[132] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147E, -73, 165, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x147F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1480, 0, 162, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1481, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1481, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1480, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of M PUNCH A, M PUNCH B */
const u16 yun_atca_158_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 yun_atca_158[244] = {
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13AE, 0, 48, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13AF, 0, 48, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13B0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x13B1, 0, 48, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B2, 0, 48, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x13B3, 0, 48, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B4, -11, 49, 2246, 140, 8, 0, 0, 0, 0, 60, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x13B5, 0, 50, 2246, 128, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x13B6, 0, 51, 2246, 0, 8, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B7, 0, 47, 2246, 0, 8, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13B8, 0, 47, 2246, 0, 8, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13B9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13BA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of follow-up of M PUNCH A, M PUNCH B, 165 no name, 166 no name, 167 no name ... */
const u16 yun_atca_159_head[4] = { HEAD(6, 0, 8, 9, 0, 1, 0) };
const u16 yun_atca_159[280] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16C4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C6, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C7, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16C8, 0, 202, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x16C9, 0, 202, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16CA, 0, 202, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x16CB, -76, 113, 0, 143, 64, 1, 16, 0, 0, 68, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16CC, 0, 114, 0, 143, 64, 30, 43, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16CD, 0, 115, 0, 0, 64, 30, 29, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x16CE, 0, 218, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x16CF, 0, 218, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x16D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x16D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 160 follow-up of S KICK A */
const u16 yun_atca_160_head[4] = { HEAD(6, 0, 3, 8, 0, 1, 0) };
const u16 yun_atca_160[232] = {
    CMD(CM_RMJA, 4, 161, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 31, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 269, 0, 0, 0, 0, 0x13EF, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13EF, -77, 220, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F0, 0, 221, 3215, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F1, 2, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F1, 0, 14, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F2, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F3, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F4, 0, 15, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F5, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F6, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x13F7, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 161 follow-up of follow-up of S KICK A */
const u16 yun_atca_161_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 yun_atca_161[304] = {
    CMD(CM_JPSS, 8, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x13EF, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B4, -78, 195, 0, 142, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 196, 0, 142, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 205, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B6, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x15B7, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x15B8, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x15B9, 0, 197, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x15BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 162 follow-up of S PUNCH A, S PUNCH B */
const u16 yun_atca_162_head[4] = { HEAD(6, 0, 1, 8, 0, 1, 0) };
const u16 yun_atca_162[136] = {
    CMD(CM_RMJA, 4, 163, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x13E3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x13E4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E5, -153, 56, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13E6, 12, 57, 2223, 0, 104, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13E8, 0, 1, 2223, 0, 8, 21, 0, 0, 0, 240, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x13EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 163 follow-up of follow-up of S PUNCH A, S PUNCH B */
const u16 yun_atca_163_head[4] = { HEAD(6, 0, 2, 8, 0, 1, 0) };
const u16 yun_atca_163[124] = {
    L6(1, 0, 269, 0, 0, 0, 0, 0x138E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1390, -154, 31, 0, 0, 96, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1392, 0, 136, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1391, 0, 136, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x1391, 0, 137, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1393, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1394, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1395, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 164 follow-up of KAGAMI P A */
const u16 yun_atca_164_head[4] = { HEAD(4, 32, 4, 13, 0, 2, 0) };
const u16 yun_atca_164[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1438, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 616, 0, 0, 0, 0, 0x1439, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x143A, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143B, -155, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143C, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143D, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143E, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143F, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 616, 0, 0, 0, 0, 0x1431, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x1432, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -156, 95, 0, 141, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1434, 0, 96, 0, 141, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1435, 0, 66, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1436, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 203 follow-up of ZANNEN 4 */
const u16 yun_atca_203_head[4] = { HEAD(6, 0, 32, 8, 0, 1, 0) };
const u16 yun_atca_203[124] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D7, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x13D8, 0, 33, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D9, 0, 33, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C3, -100, 34, 0, 0, 36, 0, 0, 0, 0, 322, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C4, 0, 35, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C5, 0, 36, 0, 0, 36, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13C2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 324, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x13C1, 0, 33, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 204 no name, 205 follow-up of ZANNEN 5 */
const u16 yun_atca_204_head[4] = { HEAD(6, 0, 34, 9, 0, 1, 0) };
const u16 yun_atca_204[184] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x138D, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x138E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1390, -101, 31, 0, 0, 4, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1391, 0, 136, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1392, 0, 136, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1392, 0, 137, 0, 0, 4, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1393, 0, 138, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1394, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1395, 0, 138, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1396, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 206 follow-up of JUDGMENT WAIT */
const u16 yun_atca_206_head[4] = { HEAD(6, 0, 36, 9, 0, 2, 0) };
const u16 yun_atca_206[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C6, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 613, 0, 0, 0, 0, 0x13C7, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C8, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C9, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CA, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x13CB, 0, 37, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CC, -102, 38, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CC, 0, 38, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CD, -103, 39, 0, 0, 36, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CE, 0, 40, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x13CF, 0, 41, 0, 0, 4, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D1, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13D2, 0, 37, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 207 follow-up of ZANNEN 6 */
const u16 yun_atca_207_head[4] = { HEAD(6, 0, 32, 12, 0, 1, 0) };
const u16 yun_atca_207[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1397, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1398, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1399, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x139A, 0, 42, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x139B, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x139C, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A0, -104, 44, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A1, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A2, 0, 46, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x13B9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13BA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 208 follow-up of APPEAR USE */
const u16 yun_atca_208_head[4] = { HEAD(6, 0, 33, 12, 0, 1, 0) };
const u16 yun_atca_208[280] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1692, 0, 108, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1693, 0, 108, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1694, 0, 108, 0, 0, 0, 0, 0, 0, 0, 410, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1695, 0, 225, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1696, 0, 225, 0, 0, 0, 0, 0, 0, 0, 414, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1697, 0, 225, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1698, 0, 225, 0, 0, 0, 0, 0, 0, 0, 418, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x1699, -171, 261, 0, 128, 0, 0, 0, 0, 0, 420, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169A, 0, 262, 0, 0, 0, 30, 50, 0, 0, 422, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169B, 0, 262, 0, 0, 0, 0, 0, 0, 0, 424, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169C, 0, 263, 0, 0, 0, 0, 0, 0, 0, 426, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169D, 0, 263, 0, 0, 0, 0, 0, 0, 0, 428, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169E, 0, 263, 0, 0, 0, 0, 0, 0, 0, 430, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x169F, 0, 263, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 434, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16A2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 438, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x16A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 440, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 442, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 444, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 209 follow-up of ZANNEN 7, 210 no name, 211 no name */
const u16 yun_atca_209_head[4] = { HEAD(6, 0, 33, 8, 0, 1, 0) };
const u16 yun_atca_209[136] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E3, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x13E4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E5, -105, 56, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E6, 0, 57, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x13E8, 0, 1, 0, 0, 0, 21, 0, 0, 0, 240, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 212 follow-up of APPEAR USE */
const u16 yun_atca_212_head[4] = { HEAD(6, 0, 33, 8, 0, 1, 0) };
const u16 yun_atca_212[160] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x13ED, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13EE, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x13EF, -106, 220, 0, 128, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F0, 0, 12, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13F1, 2, 13, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x13F2, 0, 14, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F3, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F4, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F5, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F6, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F7, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 213 follow-up of ZANNEN 8 */
const u16 yun_atca_213_head[4] = { HEAD(6, 0, 32, 8, 0, 1, 0) };
const u16 yun_atca_213[244] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D3, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D4, 0, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D5, 0, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D6, 0, 266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x16D7, 0, 267, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D8, -169, 268, 0, 128, 1, 0, 0, 0, 0, 370, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16D9, 0, 269, 0, 0, 1, 0, 0, 0, 0, 372, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DA, 2, 270, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DB, 2, 270, 0, 0, 1, 0, 0, 0, 0, 374, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DC, 2, 271, 0, 0, 1, 0, 0, 0, 0, 376, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DD, 0, 267, 0, 0, 1, 21, 0, 0, 0, 378, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DE, 0, 267, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16DF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 382, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x16E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 386, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x16E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 214 follow-up of JUDGMENT WAIT */
const u16 yun_atca_214_head[4] = { HEAD(6, 0, 33, 10, 0, 1, 0) };
const u16 yun_atca_214[184] = {
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 8, 0, 0, 0, 0, 0, 0x13FA, 0, 98, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13FB, 0, 98, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13FC, 0, 99, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(3, 1, 616, 0, 0, 0, 0, 0x13FD, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13FE, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13FF, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1400, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1401, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 1, 0, 0, 0, 0x1402, 0, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 1, 0, 0, 0, 0x1403, -107, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x1404, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1405, 0, 146, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1406, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 215 no name, 216 follow-up of WIN 1, 217 follow-up of JUDGMENT WAIT */
const u16 yun_atca_215_head[4] = { HEAD(6, 0, 33, 14, 0, 1, 0) };
const u16 yun_atca_215[220] = {
    L6(1, 8, 0, 0, 0, 0, 0, 0x15B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B4, -108, 195, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B6, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 1, 0, 0, 0, 0x15B7, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x15B8, 0, 197, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 1, 0, 0, 0, 0x15B9, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 218 follow-up of WIN 2, 219 no name, 220 no name */
const u16 yun_atca_218_head[4] = { HEAD(4, 32, 32, 11, 0, 1, 0) };
const u16 yun_atca_218[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1431, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1431, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -109, 61, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1434, 0, 62, 0, 0, 36, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1435, 0, 63, 0, 0, 36, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1436, 0, 60, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 221 follow-up of WIN 3, 222 no name, 223 no name */
const u16 yun_atca_221_head[4] = { HEAD(4, 32, 32, 11, 0, 1, 0) };
const u16 yun_atca_221[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1430, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1431, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1432, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -110, 93, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1434, 0, 94, 0, 0, 36, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1435, 0, 63, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1436, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 224 follow-up of WIN 4, 225 no name, 226 no name */
const u16 yun_atca_224_head[4] = { HEAD(4, 32, 32, 12, 0, 2, 0) };
const u16 yun_atca_224[132] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1438, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1439, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x143A, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143B, -111, 65, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143C, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143D, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143E, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x143F, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1431, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x1432, 0, 66, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1433, -112, 95, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1434, 0, 96, 0, 0, 36, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1435, 0, 66, 0, 0, 36, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1436, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1437, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 227 follow-up of WIN 5, 228 no name, 229 no name */
const u16 yun_atca_227_head[4] = { HEAD(4, 32, 33, 9, 0, 1, 0) };
const u16 yun_atca_227[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1444, 0, 385, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1444, 0, 385, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1447, -113, 386, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1446, 0, 387, 0, 0, 36, 21, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1444, 0, 385, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1442, 0, 388, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1441, 0, 388, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1440, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1440, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 230 follow-up of WIN 6, 231 no name, 232 no name */
const u16 yun_atca_230_head[4] = { HEAD(4, 32, 33, 11, 0, 1, 0) };
const u16 yun_atca_230[108] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1610, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1612, 0, 389, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1613, 0, 389, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1614, -114, 390, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1615, 0, 391, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1615, 0, 392, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1616, 0, 392, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1617, 0, 393, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1618, 0, 393, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1619, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x161A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x161B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x161C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 233 follow-up of WIN 7, 234 no name, 235 no name */
const u16 yun_atca_233_head[4] = { HEAD(6, 32, 33, 12, 0, 1, 0) };
const u16 yun_atca_233[208] = {
    L6(1, 0, 615, 0, 0, 0, 0, 0x1675, 0, 2, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1676, 0, 2, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1677, 0, 2, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1678, 0, 282, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1679, 0, 282, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x167A, 0, 283, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x167B, 0, 284, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x167C, -115, 285, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x167D, 0, 286, 0, 0, 0, 21, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x167E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x167F, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1680, 0, 281, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1681, 0, 281, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1682, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1683, 0, 2, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1684, 0, 2, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1685, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 236 follow-up of JUDGMENT LOSE, 237 no name */
const u16 yun_atca_236_head[4] = { HEAD(4, 22, 32, 7, 0, 1, 0) };
const u16 yun_atca_236[108] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x1460, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x1461, 0, 139, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1462, -116, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1463, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1464, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1465, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1466, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1467, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1468, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1469, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x146A, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 238 follow-up of JUDGMENT LOSE, 239 no name */
const u16 yun_atca_238_head[4] = { HEAD(4, 22, 34, 9, 0, 1, 0) };
const u16 yun_atca_238[108] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 12, 0x1470, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1471, -117, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1472, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1473, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1474, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1474, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1475, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 240 follow-up of JUDGMENT LOSE, 241 no name */
const u16 yun_atca_240_head[4] = { HEAD(4, 22, 36, 12, 0, 1, 0) };
const u16 yun_atca_240[164] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147E, -118, 165, 0, 138, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x147F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1480, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1481, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1481, 0, 215, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1480, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 242 follow-up of WAIT, 243 no name */
const u16 yun_atca_242_head[4] = { HEAD(4, 22, 33, 10, 0, 1, 0) };
const u16 yun_atca_242[148] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1493, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1495, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1496, -119, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1497, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1499, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1495, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1493, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 244 follow-up of AFRICA JUMP, 245 no name */
const u16 yun_atca_244_head[4] = { HEAD(4, 20, 35, 12, 0, 1, 0) };
const u16 yun_atca_244[156] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D3, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x15D5, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D6, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15D7, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D8, -120, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15D9, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15DA, 0, 223, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15DB, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x15DC, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x15DD, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 246 follow-up of AFRICA LAND, 247 no name */
const u16 yun_atca_246_head[4] = { HEAD(4, 22, 37, 10, 0, 1, 0) };
const u16 yun_atca_246[116] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A0, -121, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 248 follow-up of SEAN BALL HIT, 249 no name */
const u16 yun_atca_248_head[4] = { HEAD(4, 20, 32, 8, 0, 1, 0) };
const u16 yun_atca_248[116] = {
    CMD(CM_RMJA, 4, 263, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x1460, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 12, 0x1461, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1462, -122, 140, 2112, 0, 8, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1463, 0, 140, 2112, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1464, 0, 140, 2112, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1465, 0, 140, 2112, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1466, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1467, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1468, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1469, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x146A, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 250 follow-up of follow-up of F JUMP P M A, 251 no name */
const u16 yun_atca_250_head[4] = { HEAD(4, 20, 34, 10, 0, 1, 0) };
const u16 yun_atca_250[108] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 12, 0x1470, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1471, -123, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1472, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1473, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1474, 0, 133, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1474, 0, 144, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x1475, 0, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 252 follow-up of BONUS WIN 1, 253 no name */
const u16 yun_atca_252_head[4] = { HEAD(4, 20, 36, 11, 0, 1, 0) };
const u16 yun_atca_252[100] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x146D, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x146E, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 12, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1471, -124, 142, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1472, 0, 143, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1473, 0, 143, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x1474, 0, 143, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1475, 0, 135, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 254 follow-up of BONUS WIN 2 */
const u16 yun_atca_254_head[4] = { HEAD(4, 20, 33, 11, 0, 1, 0) };
const u16 yun_atca_254[148] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1493, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1495, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1496, -125, 174, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1497, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1499, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1498, 0, 171, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1495, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1494, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1493, 0, 173, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 255 follow-up of BONUS WIN 3 */
const u16 yun_atca_255_head[4] = { HEAD(4, 20, 33, 5, 0, 1, 43) };
const u16 yun_atca_255[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 256 follow-up of APPEAR USE */
const u16 yun_atca_256_head[4] = { HEAD(4, 20, 35, 12, 0, 1, 0) };
const u16 yun_atca_256[156] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D3, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D4, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 8, 0x15D5, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D6, 0, 172, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15D7, 0, 172, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x15D8, -126, 222, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15D9, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15DA, 0, 223, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x15DB, 0, 223, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x15DC, 0, 224, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x15DD, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1278, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1279, 0, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x127A, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127B, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x127C, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 257 follow-up of APPEAR USE */
const u16 yun_atca_257_head[4] = { HEAD(4, 20, 35, 5, 0, 1, 43) };
const u16 yun_atca_257[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 258 follow-up of APPEAR USE */
const u16 yun_atca_258_head[4] = { HEAD(4, 20, 37, 11, 0, 1, 0) };
const u16 yun_atca_258[116] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A0, -127, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 170, 0, 0, 0, 21, 0),
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 259 follow-up of APPEAR USE */
const u16 yun_atca_259_head[4] = { HEAD(4, 20, 37, 5, 0, 1, 43) };
const u16 yun_atca_259[76] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(3, 20, 615, 0, 0, 0, 0, 0x150B, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x150C, 0, 178, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150D, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150E, -128, 180, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x150F, 0, 181, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1510, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1511, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 260 follow-up of APPEAR USE, 261 no name */
const u16 yun_atca_260_head[4] = { HEAD(6, 20, 33, 13, 0, 2, 0) };
const u16 yun_atca_260[280] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1523, 0, 116, 0, 0, 0, 0, 0, 0, 0, 258, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x1524, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1525, -129, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1526, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x1527, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1528, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1529, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x152A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x152B, -130, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152C, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x152D, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152E, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x152F, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1530, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1531, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1267, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1268, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1269, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x126A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x126B, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x126C, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 262 follow-up of KAGAMI K A */
const u16 yun_atca_262_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 0) };
const u16 yun_atca_262[244] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x15B0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15B2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x15B3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B4, -151, 195, 0, 137, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 196, 0, 137, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15B5, 0, 205, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15B6, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 1, 0, 0, 0, 0x15B7, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 1, 0, 0, 0, 0x15B8, 0, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x15B9, 0, 197, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15BA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x15BB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13F9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 263 follow-up of follow-up of SEAN BALL HIT */
const u16 yun_atca_263_head[4] = { HEAD(4, 22, 32, 12, 0, 1, 0) };
const u16 yun_atca_263[132] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 8, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147E, -172, 165, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x147F, 0, 166, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1480, 0, 162, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1481, 0, 162, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1481, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1480, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147D, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147C, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147B, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x147A, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1479, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1478, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 yun_atca_033_head[4] = { HEAD(6, 32, 5, 13, 0, 1, 0) };
const u16 yun_atca_033[232] = {
    CMD(CM_JPSS, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 262, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 615, 0, 0, 0, 0, 0x1675, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1676, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1677, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1678, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1679, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x167A, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x167B, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x167C, -50, 285, 3205, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x167D, 0, 286, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x167E, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x167F, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1680, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1681, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1682, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1683, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1684, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1685, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 0 S PUNCH A */
const u16 yun_atca_000_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 yun_atca_000[116] = {
    CMD(CM_RMJA, 4, 162, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 25, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x13C2, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x13C2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x13BB, -6, 288, 0, 139, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x13BC, 0, 289, 2447, 0, 120, 21, 7),
    L4(3, 0, 0, 0, 0, 0, 0, 0x13C2, 0, 1, 2447, 0, 24, 0, 8),
    L4(3, 64, 0, 0, 0, 0, 0, 0x13C1, 0, 1, 0, 0, 16, 0, 8),
    L4(250, 255, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 yun_atca_001_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 yun_atca_001[124] = {
    CMD(CM_RMJA, 4, 162, 1), 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 26, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1686, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1687, 0, 292, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1686, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1687, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1689, -6, 294, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x168A, 0, 295, 0, 0, 112, 21, 6),
    L4(3, 0, 0, 0, 0, 0, 0, 0x168B, 0, 296, 0, 0, 16, 0, 7),
    L4(2, 0, 0, 0, 0, 0, 0, 0x168C, 0, 297, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x168D, 0, 27, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x168E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x168F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1690, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 200 follow-up of ZANNEN 2 */
const u16 yun_atca_200_head[4] = { HEAD(4, 0, 32, 11, 0, 1, 0) };
const u16 yun_atca_200[60] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x13C2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13BB, -99, 288, 0, 0, 32, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13BC, 0, 289, 0, 0, 36, 21, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x13C2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x13C1, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x13C0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 201 follow-up of ZANNEN 3, 202 no name */
const u16 yun_atca_201_head[4] = { HEAD(4, 0, 32, 11, 0, 1, 0) };
const u16 yun_atca_201[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1686, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1687, 0, 292, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1689, -99, 294, 0, 0, 36, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x168A, 0, 295, 0, 0, 32, 21, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x168B, 0, 296, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x168C, 0, 297, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x168D, 0, 27, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x168E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x168F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1690, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E, 149 TUKAMIKAKARI F ... */
const u16 yun_atca_144_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_atca_144[124] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14B0, -63, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14B2, 0, 290, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B */
const u16 yun_atca_145_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_atca_145[44] = {
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 9), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1298, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1298, -168, 147, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 4, 144, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 yun_atca_146_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_atca_146[44] = {
    CMD(CM_CAFR, 2, 1, 1), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1298, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1298, -64, 147, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 4, 144, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX yun_olc_ix_table[20] = {
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

const OVERLAP_PARTS yun_overlap_char_tbl[6] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 5082 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 5083 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 5084 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 5085 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 5086 },
};

const CatchTable yun_rival_catch_tbl[1992] = {
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
    { -51, -44, 1, 1, 7 },
    { -51, -44, 1, 1, 7 },
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
    { -8, 128, 1, 1, 11 },
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
    { 0, 0, 1, 1, 1 },
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
    { -60, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -83, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -48, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
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
    { -45, 0, 1, 1, 1 },
    { -32, 0, 1, 1, 1 },
    { -28, 0, 1, 1, 1 },
    { -37, 0, 1, 1, 1 },
    { -24, 0, 1, 1, 1 },
    { -16, 0, 1, 1, 1 },
    { -45, 0, 1, 1, 1 },
    { -36, 0, 1, 1, 1 },
    { -39, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -37, 0, 1, 1, 1 },
    { -28, 0, 1, 1, 1 },
    { -28, 0, 1, 1, 1 },
    { -45, 0, 1, 1, 1 },
    { -28, 0, 1, 1, 1 },
    { -28, 0, 1, 1, 1 },
    { -37, 0, 1, 1, 1 },
    { -41, 0, 1, 1, 1 },
    { -47, 0, 1, 1, 1 },
    { -30, 0, 1, 1, 1 },
    { -38, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -21, 0, 1, 1, 2 },
    { -17, 0, 1, 1, 2 },
    { -10, 0, 1, 1, 2 },
    { -14, 0, 1, 1, 2 },
    { 3, 0, 1, 1, 2 },
    { -1, 0, 1, 1, 2 },
    { -14, 0, 1, 1, 2 },
    { -23, 0, 1, 1, 2 },
    { -4, 0, 1, 1, 2 },
    { -19, 0, 1, 1, 2 },
    { -14, 0, 1, 1, 2 },
    { -10, 0, 1, 1, 2 },
    { -10, 0, 1, 1, 2 },
    { -21, 0, 1, 1, 2 },
    { -10, 0, 1, 1, 2 },
    { -10, 0, 1, 1, 2 },
    { 7, 0, 1, 1, 2 },
    { -23, 0, 1, 1, 2 },
    { -32, 0, 1, 1, 2 },
    { 9, 0, 1, 1, 2 },
    { -26, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 4, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 6, 0, 1, 1, 3 },
    { 26, 0, 1, 1, 3 },
    { 7, 0, 1, 1, 3 },
    { 6, 0, 1, 1, 3 },
    { -10, 0, 1, 1, 3 },
    { 3, 0, 1, 1, 3 },
    { -2, 0, 1, 1, 3 },
    { 6, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 4, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 2, 0, 1, 1, 3 },
    { 26, 0, 1, 1, 3 },
    { -15, 0, 1, 1, 3 },
    { -4, 0, 1, 1, 3 },
    { 26, 0, 1, 1, 3 },
    { -11, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 7, 0, 1, 1, 4 },
    { 34, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { 25, 0, 1, 1, 4 },
    { 40, 0, 1, 1, 4 },
    { 13, 0, 1, 1, 4 },
    { 25, 0, 1, 1, 4 },
    { 4, 0, 1, 1, 4 },
    { 15, 0, 1, 1, 4 },
    { 13, 0, 1, 1, 4 },
    { 25, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { 7, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { 22, 0, 1, 1, 4 },
    { 38, 0, 1, 1, 4 },
    { 7, 0, 1, 1, 4 },
    { 29, 0, 1, 1, 4 },
    { 38, 0, 1, 1, 4 },
    { 10, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 30, 0, 1, 1, 5 },
    { 44, 0, 1, 1, 5 },
    { 36, 0, 1, 1, 5 },
    { 32, 0, 1, 1, 5 },
    { 40, 0, 1, 1, 5 },
    { 22, 0, 1, 1, 5 },
    { 27, 0, 1, 1, 5 },
    { 19, 0, 1, 1, 5 },
    { 16, 0, 1, 1, 5 },
    { 25, 0, 1, 1, 5 },
    { 32, 0, 1, 1, 5 },
    { 36, 0, 1, 1, 5 },
    { 36, 0, 1, 1, 5 },
    { 30, 0, 1, 1, 5 },
    { 36, 0, 1, 1, 5 },
    { 36, 0, 1, 1, 5 },
    { 44, 0, 1, 1, 5 },
    { 21, 0, 1, 1, 5 },
    { 28, 0, 1, 1, 5 },
    { 49, 0, 1, 1, 5 },
    { 25, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -30, 0, 1, 1, 6 },
    { -61, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -47, 0, 1, 1, 6 },
    { -49, 0, 1, 1, 6 },
    { -38, 0, 1, 1, 6 },
    { -42, 0, 1, 1, 6 },
    { -43, 0, 1, 1, 6 },
    { -28, 0, 1, 1, 6 },
    { -33, 0, 1, 1, 6 },
    { -47, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -30, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -54, 0, 1, 1, 6 },
    { -59, 0, 1, 1, 6 },
    { -50, 0, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -57, 0, 1, 1, 6 },
    { -38, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 9 },
    { -60, 0, 1, 1, 9 },
    { -59, 0, 1, 1, 9 },
    { -26, -3, 1, 1, 9 },
    { -46, 0, 1, 1, 9 },
    { -40, 0, 1, 1, 9 },
    { -25, 0, 1, 1, 9 },
    { -44, 0, 1, 1, 9 },
    { -28, 0, 1, 1, 9 },
    { -22, 0, 1, 1, 9 },
    { -26, -3, 1, 1, 9 },
    { -59, 0, 1, 1, 9 },
    { -59, 0, 1, 1, 9 },
    { -34, 0, 1, 1, 9 },
    { -59, 0, 1, 1, 9 },
    { -59, 0, 1, 1, 9 },
    { -42, 0, 1, 1, 9 },
    { -41, 0, 1, 1, 9 },
    { -44, 0, 1, 1, 9 },
    { -44, 0, 1, 1, 9 },
    { -28, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -25, -4, 1, 1, 10 },
    { -30, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -27, 54, 1, 1, 10 },
    { -35, 0, 1, 1, 10 },
    { -29, 112, 1, 1, 10 },
    { -25, 0, 1, 1, 10 },
    { -28, 52, 1, 1, 10 },
    { -21, 0, 1, 1, 10 },
    { -17, 76, 1, 1, 10 },
    { -27, 54, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -25, -4, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -26, 60, 1, 1, 10 },
    { -33, 59, 1, 1, 10 },
    { -28, -10, 1, 1, 10 },
    { -33, 24, 1, 1, 10 },
    { -23, 54, 1, 1, 10 },
    { -22, -10, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
};

/* extra scripts: 104 entries */
const u16* const yun_exca[105] = {
    yun_exca_000,  /* 0 follow-up of AIR NORMAL */
    yun_exca_001,  /* 1 follow-up of GUARD AIR */
    yun_exca_001,  /* 2 no name */
    yun_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    yun_exca_004,  /* 4 no name */
    yun_exca_005,  /* 5 follow-up of TATAKI S, KGM TATAKI S +24 */
    yun_exca_006,  /* 6 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1 */
    yun_exca_006,  /* 7 follow-up of KUNOJI, UPPER +6 */
    yun_exca_006,  /* 8 follow-up of TTKI V. AIR */
    yun_exca_009,  /* 9 follow-up of KIRIMOMI, SPLASH.M +3 */
    yun_exca_010,  /* 10 follow-up of GUARD AIR */
    yun_exca_010,  /* 11 no name */
    yun_exca_012,  /* 12 follow-up of ATTACK 5 S */
    yun_exca_013,  /* 13 no name */
    yun_exca_014,  /* 14 no name */
    yun_exca_015,  /* 15 no name */
    yun_exca_016,  /* 16 no name */
    yun_exca_017,  /* 17 no name */
    yun_exca_018,  /* 18 no name */
    yun_exca_019,  /* 19 no name */
    yun_exca_020,  /* 20 no name */
    yun_exca_021,  /* 21 no name */
    yun_exca_022,  /* 22 no name */
    yun_exca_022,  /* 23 no name */
    yun_exca_024,  /* 24 follow-up of ATTACK 5 S */
    yun_exca_025,  /* 25 follow-up of ALEX BACK D, MAWARIKOMI M F */
    yun_exca_026,  /* 26 no name */
    yun_exca_027,  /* 27 follow-up of HANASARE, APPEAR JUNBI 2 */
    yun_exca_028,  /* 28 follow-up of SP APPEAR 2 */
    yun_exca_029,  /* 29 follow-up of APPEAR JUNBI 5 */
    yun_exca_030,  /* 30 no name */
    yun_exca_031,  /* 31 follow-up of APPEAR JUNBI 3 */
    yun_exca_032,  /* 32 follow-up of APPEAR 8 */
    yun_exca_033,  /* 33 follow-up of APPEAR JUNBI 6 */
    yun_exca_034,  /* 34 no name */
    yun_exca_035,  /* 35 follow-up of APPEAR JUNBI 4 */
    yun_exca_036,  /* 36 no name */
    yun_exca_037,  /* 37 follow-up of APPEAR JUNBI 7 */
    yun_exca_038,  /* 38 no name */
    yun_exca_039,  /* 39 follow-up of HANASARE, APPEAR JUNBI 2 */
    yun_exca_040,  /* 40 follow-up of SP APPEAR 2 */
    yun_exca_041,  /* 41 follow-up of APPEAR JUNBI 5 */
    yun_exca_042,  /* 42 no name */
    yun_exca_043,  /* 43 follow-up of APPEAR JUNBI 3 */
    yun_exca_044,  /* 44 follow-up of APPEAR 8 */
    yun_exca_045,  /* 45 follow-up of APPEAR JUNBI 6 */
    yun_exca_046,  /* 46 no name */
    yun_exca_047,  /* 47 follow-up of APPEAR JUNBI 4 */
    yun_exca_048,  /* 48 no name */
    yun_exca_049,  /* 49 follow-up of APPEAR JUNBI 7 */
    yun_exca_050,  /* 50 no name */
    yun_exca_051,  /* 51 follow-up of APPEAR 4 */
    yun_exca_052,  /* 52 follow-up of APPEAR 4 */
    yun_exca_053,  /* 53 follow-up of APPEAR 5 */
    yun_exca_054,  /* 54 follow-up of APPEAR 5 */
    yun_exca_022,  /* 55 no name */
    yun_exca_056,  /* 56 no name */
    yun_exca_022,  /* 57 no name */
    yun_exca_058,  /* 58 no name */
    yun_exca_022,  /* 59 no name */
    yun_exca_022,  /* 60 no name */
    yun_exca_061,  /* 61 follow-up of SP APPEAR 1 */
    yun_exca_062,  /* 62 follow-up of SP APPEAR 1 */
    yun_exca_063,  /* 63 follow-up of SP APPEAR 3, JUDGMENT WIN */
    yun_exca_064,  /* 64 follow-up of SP APPEAR 3, JUDGMENT WIN */
    yun_exca_065,  /* 65 follow-up of SP APPEAR 4 */
    yun_exca_066,  /* 66 follow-up of SP APPEAR 4 */
    yun_exca_022,  /* 67 no name */
    yun_exca_022,  /* 68 no name */
    yun_exca_022,  /* 69 no name */
    yun_exca_022,  /* 70 follow-up of SP APPEAR 5 */
    yun_exca_022,  /* 71 follow-up of SP APPEAR 5 */
    yun_exca_022,  /* 72 no name */
    yun_exca_073,  /* 73 follow-up of ZANNEN 1 */
    yun_exca_074,  /* 74 follow-up of ZANNEN 1 */
    yun_exca_075,  /* 75 follow-up of SP WIN 5 */
    yun_exca_076,  /* 76 follow-up of SP WIN 5 */
    yun_exca_077,  /* 77 follow-up of HUMI ASIB */
    yun_exca_078,  /* 78 follow-up of GILL IMPACT C */
    yun_exca_079,  /* 79 follow-up of GILL IMPACT C */
    yun_exca_080,  /* 80 follow-up of APPEAR 6 */
    yun_exca_081,  /* 81 follow-up of APPEAR 6 */
    yun_exca_082,  /* 82 HANASARE */
    yun_exca_083,  /* 83 HANASARE */
    yun_exca_084,  /* 84 HANASARE */
    yun_exca_085,  /* 85 HANASARE */
    yun_exca_086,  /* 86 HANASARE */
    yun_exca_087,  /* 87 HANASARE */
    yun_exca_088,  /* 88 HANASARE */
    yun_exca_089,  /* 89 HANASARE */
    yun_exca_090,  /* 90 HANASARE */
    yun_exca_091,  /* 91 HANASARE */
    yun_exca_090,  /* 92 HANASARE */
    yun_exca_091,  /* 93 HANASARE */
    yun_exca_094,  /* 94 HANASARE */
    yun_exca_095,  /* 95 HANASARE */
    yun_exca_096,  /* 96 HANASARE */
    yun_exca_097,  /* 97 HANASARE */
    yun_exca_098,  /* 98 HANASARE */
    yun_exca_099,  /* 99 HANASARE */
    yun_exca_100,  /* 100 HANASARE */
    yun_exca_101,  /* 101 HANASARE */
    yun_exca_102,  /* 102 HANASARE */
    yun_exca_103,  /* 103 HANASARE */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 yun_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_exca_000[172] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AD, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AC, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AB, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AA, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15A9, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x15A8, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x15A7, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1288, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1289, 0, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128A, 0, 192, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128B, 0, 192, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128C, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 2, 0, 0, 0, 0, 0, 0x128D, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x128E, 0, 192, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x128F, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of GUARD AIR, 2 no name */
const u16 yun_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_001[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 yun_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_003[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 no name */
const u16 yun_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_004[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1486, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1487, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1488, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1489, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x148A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x148B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of TATAKI S, KGM TATAKI S +24 */
const u16 yun_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_005[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x1328, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of ASIB SIRI LOSE, ASIB TUN LOSE +1, 7 follow-up of KUNOJI, UPPER +6, 8 follow-up of TTKI V. AIR */
const u16 yun_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_006[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x1328, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of KIRIMOMI, SPLASH.M +3 */
const u16 yun_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_009[52] = {
    L4(3, 5, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of GUARD AIR, 11 no name */
const u16 yun_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_010[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of ATTACK 5 S */
const u16 yun_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_012[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 no name */
const u16 yun_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_013[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1404, 0, 103, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1404, 0, 103, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1405, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1406, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 yun_exca_014_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_014[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x142B, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x142B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 yun_exca_015_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_015[100] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x14A4, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x14A5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x14A6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x14A7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x14A8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x14A9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x14AA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x14AB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 yun_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_016[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126C, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 yun_exca_017_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_017[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x146B, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x146B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x146C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1233, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1232, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 yun_exca_018_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_018[76] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x1512, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1512, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1513, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1514, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1515, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 yun_exca_019_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_019[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 yun_exca_020_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_020[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1489, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1489, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1489, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 yun_exca_021_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_021[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x141D, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x141D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x141D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of ATTACK 5 S */
const u16 yun_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_024[44] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of ALEX BACK D, MAWARIKOMI M F */
const u16 yun_exca_025_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_025[108] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1328, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1327, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1328, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 no name */
const u16 yun_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_026[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of HANASARE, APPEAR JUNBI 2 */
const u16 yun_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_027[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of SP APPEAR 2 */
const u16 yun_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_028[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR JUNBI 5 */
const u16 yun_exca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_029[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 no name */
const u16 yun_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_030[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of APPEAR JUNBI 3 */
const u16 yun_exca_031_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_031[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of APPEAR 8 */
const u16 yun_exca_032_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_032[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR JUNBI 6 */
const u16 yun_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_033[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 no name */
const u16 yun_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_034[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of APPEAR JUNBI 4 */
const u16 yun_exca_035_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_035[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 32, 98),
    L4(2, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 32, 98),
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 yun_exca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_036[52] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of APPEAR JUNBI 7 */
const u16 yun_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_037[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 no name */
const u16 yun_exca_038_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_038[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 35, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of HANASARE, APPEAR JUNBI 2 */
const u16 yun_exca_039_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_039[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of SP APPEAR 2 */
const u16 yun_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_040[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of APPEAR JUNBI 5 */
const u16 yun_exca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_041[84] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 yun_exca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_042[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x127D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x127E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of APPEAR JUNBI 3 */
const u16 yun_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_043[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of APPEAR 8 */
const u16 yun_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_044[36] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of APPEAR JUNBI 6 */
const u16 yun_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_045[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 yun_exca_046_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_046[36] = {
    L4(1, 0, 274, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of APPEAR JUNBI 4 */
const u16 yun_exca_047_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_047[76] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 yun_exca_048_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_048[52] = {
    L6(1, 0, 273, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 47, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of APPEAR JUNBI 7 */
const u16 yun_exca_049_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_049[76] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 41, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 yun_exca_050_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_050[52] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x128D, 0, 97, 0, 0, 0, 21, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128E, 0, 97, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x128F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    CMD(CM_JPSS, 7, 49, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 follow-up of APPEAR 4 */
const u16 yun_exca_051_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_051[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1486, 0, 183, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1487, 0, 183, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1488, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1489, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x148A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x148B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 follow-up of APPEAR 4 */
const u16 yun_exca_052_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_052[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1486, 0, 183, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1487, 0, 183, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1488, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x148A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of APPEAR 5 */
const u16 yun_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_053[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126C, 0, 184, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126D, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126E, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of APPEAR 5 */
const u16 yun_exca_054_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_054[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x146B, 0, 184, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 185, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x146C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x146C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 yun_exca_056_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_056[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 yun_exca_058_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_exca_058[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x1346, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x14D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x14D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x14D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x14D0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of SP APPEAR 1 */
const u16 yun_exca_061_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_061[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x146C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of SP APPEAR 1 */
const u16 yun_exca_062_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_062[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x146B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x146C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1242, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1242, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of SP APPEAR 3, JUDGMENT WIN */
const u16 yun_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_063[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126C, 0, 299, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126D, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126D, 0, 299, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x126E, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of SP APPEAR 3, JUDGMENT WIN */
const u16 yun_exca_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_064[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126C, 0, 299, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x126D, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x126E, 0, 300, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 follow-up of SP APPEAR 4 */
const u16 yun_exca_065_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_065[100] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x1512, 0, 182, 0, 0, 0, 21, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x1513, 0, 182, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1514, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x1515, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 follow-up of SP APPEAR 4 */
const u16 yun_exca_066_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_066[112] = {
    L6(1, 0, 274, 0, 0, 0, 0, 0x1512, 0, 182, 0, 0, 0, 21, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x1513, 0, 182, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x1514, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 22, 32, 0, 0, 210, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name, 23 no name, 55 no name, 57 no name ... */
const u16 yun_exca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_022[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x12D7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x123B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 follow-up of ZANNEN 1 */
const u16 yun_exca_073_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_073[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1215, 0, 299, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1216, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x149C, 0, 300, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x149D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 follow-up of ZANNEN 1 */
const u16 yun_exca_074_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_074[52] = {
    L4(1, 64, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 follow-up of SP WIN 5 */
const u16 yun_exca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_075[52] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1405, 0, 146, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1406, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 follow-up of SP WIN 5 */
const u16 yun_exca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_076[68] = {
    L4(4, 0, 273, 0, 0, 0, 0, 0x1406, 0, 146, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 follow-up of HUMI ASIB */
const u16 yun_exca_077_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_077[100] = {
    CMD(CM_PA_X, 0, 10240, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 follow-up of GILL IMPACT C */
const u16 yun_exca_078_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_078[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 follow-up of GILL IMPACT C */
const u16 yun_exca_079_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 yun_exca_079[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1329, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132A, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132B, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x132C, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x132D, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x132E, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x132F, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1330, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x1331, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1332, 0, 91, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1370, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 follow-up of APPEAR 6 */
const u16 yun_exca_080_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_080[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 81 follow-up of APPEAR 6 */
const u16 yun_exca_081_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_081[52] = {
    L4(5, 0, 273, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 HANASARE */
const u16 yun_exca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_082[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126C, 0, 299, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x126D, 0, 299, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x126E, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 HANASARE */
const u16 yun_exca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_083[84] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x146B, 0, 299, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x146C, 0, 299, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x146D, 0, 300, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1233, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 HANASARE */
const u16 yun_exca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_084[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 85 HANASARE */
const u16 yun_exca_085_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_085[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 HANASARE */
const u16 yun_exca_086_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_086[36] = {
    L4(1, 3, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 27, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 HANASARE */
const u16 yun_exca_087_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_087[36] = {
    L4(1, 3, 273, 0, 0, 0, 0, 0x126D, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x126E, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 39, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 HANASARE */
const u16 yun_exca_088_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_088[76] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x15DE, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x15DE, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x15DF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x15E0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x15E1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 HANASARE */
const u16 yun_exca_089_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_089[92] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x15DE, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x15DE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x15DF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x15E0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x15E1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 HANASARE, 92 HANASARE */
const u16 yun_exca_090_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_090[124] = {
    L6(1, 2, 0, 0, 0, 0, 0, 0x12D2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 286, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x12D3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x12D4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x12D5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x12D6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x12D7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 HANASARE, 93 HANASARE */
const u16 yun_exca_091_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_091[100] = {
    L6(1, 2, 273, 0, 0, 0, 0, 0x12D2, 0, 1, 0, 0, 0, 21, 0, 0, 0, 286, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x12D3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 HANASARE */
const u16 yun_exca_094_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_094[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x149A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x149C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x149D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 95 HANASARE */
const u16 yun_exca_095_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_095[76] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x149B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x149C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x149D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 HANASARE */
const u16 yun_exca_096_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_096[52] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1231, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 HANASARE */
const u16 yun_exca_097_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_097[52] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 21, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 HANASARE */
const u16 yun_exca_098_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_098[100] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x1531, 0, 119, 0, 0, 0, 21, 0),
    CMD(CM_IF_L, 2, 16389, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1230, 0, 1, 0, 0, 0, 22, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 99 HANASARE */
const u16 yun_exca_099_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_099[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 HANASARE */
const u16 yun_exca_100_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_100[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 101 HANASARE */
const u16 yun_exca_101_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_exca_101[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 HANASARE */
const u16 yun_exca_102_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 yun_exca_102[68] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x126F, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1231, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1232, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1233, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1234, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1235, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 103 HANASARE */
const u16 yun_exca_103_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 yun_exca_103[148] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AD, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AC, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AB, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15AA, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x15A9, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x15A8, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x15A7, 0, 358, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1288, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1289, 0, 358, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x128A, 0, 358, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128B, 0, 359, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x128C, 0, 359, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 99 entries */
const u16* const yun_saca[100] = {
    yun_saca_000,  /* 0 UP P GUARD P S */
    yun_saca_001,  /* 1 UP P GUARD P M */
    yun_saca_002,  /* 2 UP P GUARD P L */
    yun_saca_002,  /* 3 UP P GUARD K S */
    yun_saca_002,  /* 4 UP P GUARD K M */
    yun_saca_002,  /* 5 UP P GUARD K L */
    yun_saca_000,  /* 6 D P GUARD P S */
    yun_saca_001,  /* 7 D P GUARD P M */
    yun_saca_002,  /* 8 D P GUARD P L */
    yun_saca_002,  /* 9 D P GUARD K S */
    yun_saca_002,  /* 10 D P GUARD K M */
    yun_saca_002,  /* 11 D P GUARD K L */
    yun_saca_002,  /* 12 FUSHIN P S */
    yun_saca_002,  /* 13 FUSHIN P M */
    yun_saca_002,  /* 14 FUSHIN P L */
    yun_saca_002,  /* 15 FUSHIN K S */
    yun_saca_002,  /* 16 FUSHIN K M */
    yun_saca_002,  /* 17 FUSHIN K L */
    yun_saca_002,  /* 18 OKIAGARI P S */
    yun_saca_002,  /* 19 OKIAGARI P M */
    yun_saca_002,  /* 20 OKIAGARI P L */
    yun_saca_002,  /* 21 OKIAGARI K S */
    yun_saca_002,  /* 22 OKIAGARI K M */
    yun_saca_002,  /* 23 OKIAGARI K L */
    yun_saca_024,  /* 24 ATTACK 1 S: not started by a command */
    yun_saca_024,  /* 25 ATTACK 1 M: not started by a command */
    yun_saca_024,  /* 26 ATTACK 1 L: not started by a command */
    yun_saca_024,  /* 27 ATTACK 1 SP: not started by a command */
    yun_saca_028,  /* 28 ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    yun_saca_028,  /* 29 ATTACK 2 M: 214+P light/medium/heavy (plain script) */
    yun_saca_028,  /* 30 ATTACK 2 L: 214+P light/medium/heavy (plain script) */
    yun_saca_031,  /* 31 ATTACK 2 SP: EX 214+PP (plain script) */
    yun_saca_032,  /* 32 ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN) */
    yun_saca_033,  /* 33 ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN) */
    yun_saca_034,  /* 34 ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    yun_saca_035,  /* 35 ATTACK 3 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    yun_saca_036,  /* 36 ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) */
    yun_saca_037,  /* 37 ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU) */
    yun_saca_038,  /* 38 ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) */
    yun_saca_039,  /* 39 ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
    yun_saca_040,  /* 40 ATTACK 5 S: not started by a command */
    yun_saca_040,  /* 41 ATTACK 5 M: not started by a command */
    yun_saca_040,  /* 42 ATTACK 5 L: not started by a command */
    yun_saca_040,  /* 43 ATTACK 5 SP: not started by a command */
    yun_saca_044,  /* 44 ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_044,  /* 45 ATTACK 6 M: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_044,  /* 46 ATTACK 6 L: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_044,  /* 47 ATTACK 6 SP: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_048,  /* 48 ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_048,  /* 49 ATTACK 7 M: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_048,  /* 50 ATTACK 7 L: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_048,  /* 51 ATTACK 7 SP: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_052,  /* 52 ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_052,  /* 53 ATTACK 8 M: after SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_052,  /* 54 ATTACK 8 L: after SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_052,  /* 55 ATTACK 8 SP: after SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_056,  /* 56 ATTACK 9 S: 6(123)4+K (plain script) */
    yun_saca_056,  /* 57 ATTACK 9 M: 6(123)4+K (plain script) */
    yun_saca_056,  /* 58 ATTACK 9 L: 6(123)4+K (plain script) */
    yun_saca_056,  /* 59 ATTACK 9 SP: 6(123)4+K (plain script) */
    yun_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    yun_saca_061,  /* 61 ATTACK 10 M: SA III 23623+P (plain script) */
    yun_saca_061,  /* 62 ATTACK 10 L: SA III 23623+P (plain script) */
    yun_saca_061,  /* 63 ATTACK 10 SP: SA III 23623+P (plain script) */
    yun_saca_061,  /* 64 ATTACK 11 S: SA III 23623+P (plain script) */
    yun_saca_065,  /* 65 ATTACK 11 M: not started by a command */
    yun_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    yun_saca_066,  /* 67 ATTACK 11 SP: not started by a command */
    yun_saca_066,  /* 68 ATTACK 12 S: not started by a command */
    yun_saca_069,  /* 69 ATTACK 12 M: not started by a command */
    yun_saca_070,  /* 70 ATTACK 12 L: not started by a command */
    yun_saca_070,  /* 71 ATTACK 12 SP: not started by a command */
    yun_saca_070,  /* 72 ATTACK 13 S: not started by a command */
    yun_saca_070,  /* 73 ATTACK 13 M: not started by a command */
    yun_saca_074,  /* 74 ATTACK 13 L: not started by a command */
    yun_saca_075,  /* 75 ATTACK 13 SP: not started by a command */
    yun_saca_076,  /* 76 not started by a command */
    yun_saca_076,  /* 77 not started by a command */
    yun_saca_076,  /* 78 not started by a command */
    yun_saca_076,  /* 79 not started by a command */
    yun_saca_080,  /* 80 not started by a command */
    yun_saca_080,  /* 81 not started by a command */
    yun_saca_080,  /* 82 not started by a command */
    yun_saca_083,  /* 83 not started by a command */
    yun_saca_083,  /* 84 not started by a command */
    yun_saca_083,  /* 85 not started by a command */
    yun_saca_083,  /* 86 not started by a command */
    yun_saca_087,  /* 87 623+P light (routine Att_SLIDE_and_JUMP) */
    yun_saca_088,  /* 88 623+P medium (routine Att_SLIDE_and_JUMP) */
    yun_saca_089,  /* 89 623+P heavy (routine Att_SLIDE_and_JUMP) */
    yun_saca_090,  /* 90 EX 623+PP (routine Att_SLIDE_and_JUMP) */
    yun_saca_091,  /* 91 not started by a command */
    yun_saca_092,  /* 92 not started by a command */
    yun_saca_091,  /* 93 not started by a command */
    yun_saca_094,  /* 94 not started by a command */
    yun_saca_095,  /* 95 not started by a command */
    yun_saca_096,  /* 96 after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    yun_saca_097,  /* 97 not started by a command */
    yun_saca_098,  /* 98 not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 yun_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7091, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7092, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7093, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7094, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7095, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7096, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7097, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7098, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7099, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x709A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x709B, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -2048, 6144), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 yun_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 yun_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x709B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x709A, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x709A, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7099, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7098, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7097, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7096, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7095, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7094, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7093, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7092, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7091, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 yun_saca_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_saca_002[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1200, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: not started by a command, 25 ATTACK 1 M: not started by a command, 26 ATTACK 1 L: not started by a command, 27 ATTACK 1 SP: not started by a command */
const u16 yun_saca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_saca_024[220] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 214+P light/medium/heavy (plain script), 29 ATTACK 2 M: 214+P light/medium/heavy (plain script), 30 ATTACK 2 L: 214+P light/medium/heavy (plain script) */
const u16 yun_saca_028_head[4] = { HEAD(6, 0, 8, 9, 0, 1, 0) };
const u16 yun_saca_028[292] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E0, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E6, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E7, 0, 202, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 613, 0, 0, 0, 0, 0x14E8, 0, 202, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E9, 0, 202, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 639, 0, 0, 0, 0, 0x14EA, -22, 113, 0, 144, 64, 1, 16, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14EA, 22, 113, 0, 144, 64, 30, 43, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14EB, 23, 114, 0, 0, 64, 30, 29, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14EC, 23, 115, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14ED, 0, 218, 0, 0, 0, 21, 0, 0, 0, 70, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x14EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 214+PP (plain script) */
const u16 yun_saca_031_head[4] = { HEAD(6, 0, 14, 9, 0, 0, 0) };
const u16 yun_saca_031[2768] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x14E0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000E, 0x0900, 0x0100, 0x0004, 0x0008, 0x0027, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x001E, 0x0004, 0x0004, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E0,
    CMD(CM_UJA5, 16384, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x14E1,
    CMD(CM_UJA5, 16384, 0, 4101), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x14E2,
    CMD(CM_UJA5, 16384, 0, 4615), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x14E3,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E4,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E5,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E6,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E7,
    CMD(CM_UJA5, 16384, 0, 8448), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2680, 0x0000, 0x14E8,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0044, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E9,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0044, 0x0000, 0x0200, 0x0000, 0x0000, 0x14E9,
    CMD(CM_UJA5, 16384, 0, 621), 0x0000, 0x0000, 0x0044, 0x0000, 0x0034, 0x000A, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x2690, 0x0000, 0x14EA,
    L6(219, 78, 512, 0, 0, 2308, 0, 0x0110, 0, 0, 0, 0, 68, 0, 0, 256, 0, 0, 20, 234),
    CMD(CM_FOR2, 8192, -28608, 7723), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x14EB,
    L6(37, 14, 1024, 0, 0, 4, 0, 0x1E1D, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 20, 236),
    CMD(CM_FOR2, 24576, 64, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x14ED,
    CMD(CM_UJA6, 16384, 0, 5376), 0x0000, 0x0000, 0x0046, 0x0000, 0x0340, 0x0000, 0x0000, 0x14EE,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0046, 0x0000, 0x0300, 0x0000, 0x0000, 0x14EF,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0046, 0x0000, 0x0400, 0x0000, 0x0000, 0x1236,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1237,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 9, 2560, 541), 0x0004, 0x0008, 0x0028, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0005, 0x0008, 0x000D, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0016, 0x0005, 0x0020, 0x0006, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0432, 0x2670, 0x0000, 0x1372, 0x000F, 0xA000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 202, 0), 0x0100, 0x0000, 0x0000, 0x14FF, 0x000F, 0xA000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 204, 0), 0x0300, 0x0000, 0x0000, 0x1500, 0x000F, 0xC000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 206, 0), 0x0200, 0x0000, 0x0000, 0x1501, 0xF90F, 0xE000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x0200, 0x0000, 0x0000, 0x1502, 0x0010, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x021E, 0x0000, 0x0000, 0x1503, 0xF8D0, 0x2000, 0x0000, 0x1E26,
    CMD(CM_DUMMY, 0, 90, 0), 0x0200, 0x0000, 0x0000, 0x1504, 0x0790, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x1505, 0x000A, 0x0000, 0x0000, 0x1500,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1506, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1507, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1508, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1509, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x150A, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x151F, 0x000A, 0x6000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000, 0x0006, 0x000B, 0x0A00, 0x021D,
    CMD(CM_JPSS, 8, 41, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 33, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 50, 615, 0, 0, 0, 0, 0x1372, 0, 125, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x14FF, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 0, 0, 0, 0, 0, 0x1500, 0, 194, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1501, -57, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1502, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x1503, -58, 129, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1504, 59, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1505, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1506, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1507, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1508, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1509, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x150A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x151F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000B, 0x0A00, 0x021D, 0x0004, 0x0008, 0x0029, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0005, 0x0008, 0x000D, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0016, 0x0005, 0x0021, 0x000E,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x14F0,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00C6, 0x0000, 0x0200, 0x0000, 0x0000, 0x14F1,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00C8, 0x0000, 0x0114, 0x0000, 0x0000, 0x14F2,
    CMD(CM_RJA5, 16384, -29184, 7686), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F3,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x2670, 0x0000, 0x14F4,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F5,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F6,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F7,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F8,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F9,
    CMD(CM_RJA5, 16384, -29184, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0132, 0x0000, 0x0000, 0x14FF,
    CMD(CM_RJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0228, 0x0000, 0x0000, 0x1500,
    CMD(CM_RJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0058, 0x0000, 0x0200, 0x0000, 0x0000, 0x1501,
    L6(241, 207, 3584, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 90, 0, 0, 512, 0, 0, 21, 2),
    CMD(CM_RJA, 0, 0, 0), 0x0000, 0x0000, 0x005A, 0x0000, 0x021E, 0x0000, 0x0000, 0x1503,
    L6(241, 144, 512, 0, 0, 0, 0, 0x1E26, 0, 0, 0, 0, 90, 0, 0, 512, 0, 0, 21, 4),
    L6(14, 208, 1024, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 21, 5),
    CMD(CM_IF_L, 0, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1506,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1507,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1508,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1509,
    CMD(CM_IF_L, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x150A,
    CMD(CM_IF_L, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFA00, 0x0000, 0x0000, 0x151F,
    CMD(CM_IF_L, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 13, 2560, 541), 0x0004, 0x0008, 0x002A, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0005, 0x0008, 0x000D, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0016, 0x0005, 0x0022, 0x0006, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0432, 0x2670, 0x0000, 0x1372, 0x000F, 0xA000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 202, 0), 0x0132, 0x0000, 0x0000, 0x14FF, 0x0018, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0128, 0x0000, 0x0000, 0x1500, 0x0018, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 88, 0), 0x0200, 0x0000, 0x0000, 0x1501, 0xF10F, 0xE000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x0232, 0x0000, 0x0000, 0x1502, 0x0010, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x021E, 0x0000, 0x0000, 0x1503, 0xF0D0, 0x2000, 0x0000, 0x1E26,
    CMD(CM_DUMMY, 0, 90, 0), 0x0200, 0x0000, 0x0000, 0x1504, 0x0F90, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x1505, 0x000A, 0x0000, 0x0000, 0x1500,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1506, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1507, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1508, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1509, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x150A, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x151F, 0x000A, 0x6000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000, 0x0006, 0x000D, 0x0A00, 0x021D,
    CMD(CM_JPSS, 8, 42, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 34, 28), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14F0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14F1, 0, 124, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x14F2, 0, 194, 0, 156, 0, 30, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14FA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14FB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 615, 0, 0, 0, 0, 0x14F3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14FA, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14FB, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 615, 0, 0, 0, 0, 0x14F3, 0, 194, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 50, 0, 0, 0, 0, 0, 0x14FF, 0, 194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 40, 0, 0, 0, 0, 0, 0x1500, 0, 194, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1501, -60, 127, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x1502, 0, 128, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x1503, -61, 129, 0, 0, 0, 30, 38, 0, 0, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1504, 62, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1505, 0, 80, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1506, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1507, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1508, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1509, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x150A, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x151F, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x000F, 0x0A00, 0x031D, 0x0004, 0x0008, 0x002A, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0005, 0x0008, 0x000D, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0016, 0x0005, 0x0023, 0x000A,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0005, 0x0008, 0x0056, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F0,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00C6, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F1,
    CMD(CM_NEX2, -32768, 0, 0), 0x0000, 0x0000, 0x00C8, 0x0000, 0x0114, 0x0000, 0x0000, 0x14F2,
    CMD(CM_UJA2, -32768, 0, 7686), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F4,
    CMD(CM_UJA2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x14F6,
    CMD(CM_UJA2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0432, 0x2670, 0x0000, 0x1372,
    CMD(CM_UJA7, -16384, 0, 0), 0x0000, 0x0000, 0x00CA, 0x0000, 0x0132, 0x0000, 0x0000, 0x14FF,
    CMD(CM_UJA7, -16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0128, 0x0000, 0x0000, 0x1500,
    CMD(CM_UJA7, -16384, 0, 0), 0x0000, 0x0000, 0x0058, 0x0000, 0x0200, 0x0000, 0x0000, 0x1501,
    L6(223, 29, 3584, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 90, 0, 0, 562, 0, 0, 21, 2),
    L6(222, 208, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 90, 0, 0, 542, 0, 0, 21, 3),
    L6(222, 144, 512, 0, 0, 0, 0, 0x1E26, 0, 0, 0, 0, 90, 0, 0, 512, 0, 0, 21, 4),
    L6(33, 144, 1024, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 21, 5),
    CMD(CM_IF_L, 0, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1506,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1507,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1508,
    CMD(CM_IF_L, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1509,
    CMD(CM_IF_L, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x150A,
    CMD(CM_IF_L, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFA00, 0x0000, 0x0000, 0x151F,
    CMD(CM_IF_L, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_RET, 13, 2560, 797), 0x0004, 0x0008, 0x002A, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0005, 0x0008, 0x000D, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0016, 0x0005, 0x0023, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x14F0, 0x000F, 0x8000, 0x0000, 0x1005,
    CMD(CM_DUMMY, 0, 198, 0), 0x0200, 0x0000, 0x0000, 0x14F1, 0x000F, 0x8000, 0x0000, 0x1207,
    CMD(CM_DUMMY, 0, 200, 0), 0x0114, 0x0000, 0x0000, 0x14F2, 0x0018, 0x4000, 0x9C00, 0x1E06,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F3, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F4, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F5, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F6, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F7, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F8, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F9, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14FA, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14FB, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F2, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x2670, 0x0000, 0x14F3, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F4, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F5, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F6, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F7, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F8, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F9, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14FA, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14FB, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x0000, 0x0000, 0x14F2, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0100, 0x2670, 0x0000, 0x14F3, 0x0018, 0x4000, 0x9C00, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0132, 0x0000, 0x0000, 0x14FF, 0x0018, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0128, 0x0000, 0x0000, 0x1500, 0x0018, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 88, 0), 0x0200, 0x0000, 0x0000, 0x1501, 0xDF0F, 0xE000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x0232, 0x0000, 0x0000, 0x1502, 0xDED0, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 90, 0), 0x021E, 0x0000, 0x0000, 0x1503, 0xDE90, 0x2000, 0x0000, 0x1E26,
    CMD(CM_DUMMY, 0, 90, 0), 0x0200, 0x0000, 0x0000, 0x1504, 0x2190, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0600, 0x0000, 0x0000, 0x1505, 0x000A, 0x0000, 0x0000, 0x1500,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1506, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1507, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1508, 0x000A, 0x2000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x1509, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0400, 0x0000, 0x0000, 0x150A, 0x000A, 0x4000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0xFA00, 0x0000, 0x0000, 0x151F, 0x000A, 0x6000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 36 ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) */
const u16 yun_saca_036_head[4] = { HEAD(6, 0, 8, 13, 0, 1, 31) };
const u16 yun_saca_036[268] = {
    CMD(CM_JPSS, 8, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 0, 17, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1544, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1545, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1546, 0, 109, 0, 0, 0, 30, 36, 0, 0, 76, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x1547, -20, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1548, 21, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1549, 0, 110, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x154A, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x154B, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU) */
const u16 yun_saca_037_head[4] = { HEAD(6, 0, 10, 13, 0, 1, 31) };
const u16 yun_saca_037[268] = {
    CMD(CM_JPSS, 8, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 0, 17, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1543, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1544, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1545, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1546, 0, 109, 0, 0, 0, 30, 36, 0, 0, 76, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x1547, -87, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1548, 88, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1549, 0, 110, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154A, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x154B, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x154C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x154D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) */
const u16 yun_saca_038_head[4] = { HEAD(6, 0, 12, 13, 0, 1, 31) };
const u16 yun_saca_038[280] = {
    CMD(CM_JPSS, 8, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 0, 17, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1543, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1544, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1545, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1546, 0, 109, 0, 0, 0, 30, 36, 0, 0, 76, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x1547, -89, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1548, 90, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1549, 0, 110, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x154A, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154A, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x154B, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
const u16 yun_saca_039_head[4] = { HEAD(6, 0, 14, 13, 0, 2, 31) };
const u16 yun_saca_039[280] = {
    CMD(CM_JPSS, 8, 43, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 36, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 85, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1543, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1544, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1545, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1546, 0, 109, 0, 0, 0, 30, 36, 0, 0, 76, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x1547, -135, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1548, 135, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1549, -136, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x154A, 0, 241, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x154A, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x154B, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x154E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: not started by a command, 41 ATTACK 5 M: not started by a command, 42 ATTACK 5 L: not started by a command, 43 ATTACK 5 SP: not started by a command */
const u16 yun_saca_040_head[4] = { HEAD(6, 0, 33, 13, 0, 6, 0) };
const u16 yun_saca_040[604] = {
    CMD(CM_RJA, 5, 40, 22), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_STOP, -50, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 612, 0, 0, 0, 0, 0x1520, 0, 189, 0, 0, 0, 13, 3, 0, 0, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1521, 0, 189, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(36, 0, 0, 0, 0, 0, 0, 0x1522, 0, 189, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x1523, 0, 189, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 616, 0, 0, 0, 0, 0x1524, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1525, -24, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1526, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 616, 0, 0, 0, 0, 0x1527, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1528, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1529, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x152A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x152B, -25, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152C, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152D, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x152E, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x152F, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(255, 0, 0, 0, 0, 0, 0, 0x1530, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1531, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 40, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 615, 0, 0, 0, 0, 0x1410, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1411, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1412, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1413, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1414, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1415, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1416, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    CMD(CM_RJA, 7, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x1417, -26, 120, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1418, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x1419, 27, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 30, 0, 0, 0, 0, 0, 0x141A, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x141B, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x141C, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -72, 171, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14A1, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14A2, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14A3, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14A4, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14A5, 72, 169, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x14A6, 72, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x141D, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), 45 ATTACK 6 M: SA I 23623+P (routine Att_SLIDE_and_JUMP), 46 ATTACK 6 L: SA I 23623+P (routine Att_SLIDE_and_JUMP), 47 ATTACK 6 SP: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_044_head[4] = { HEAD(6, 0, 48, 11, 0, 3, 51) };
const u16 yun_saca_044[644] = {
    CMD(CM_JSR, 8, 79, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x13C6, 0, 189, 0, 0, 0, 13, 41, 776, 0, 0, 0, 0),
    L6(4, 0, 617, 0, 0, 0, 0, 0x13C7, 0, 189, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13C8, 0, 189, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(35, 0, 0, 0, 0, 0, 0, 0x13C9, 0, 189, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CA, 0, 189, 0, 0, 0, 0, 0, 776, 0, 300, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x13CB, 0, 189, 0, 0, 0, 0, 0, 776, 0, 300, 0, 0),
    L6(1, 0, 613, 0, 0, 0, 0, 0x13CC, -145, 236, 0, 142, 0, 0, 0, 776, 0, 0, 0, 0),
    CMD(CM_RJA4, 5, 96, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA3, 5, 44, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8196, 8197, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CD, 0, 236, 0, 142, 0, 0, 0, 776, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13CE, 0, 240, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13CF, 0, 240, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13D0, 0, 1, 0, 0, 0, 0, 0, 776, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 779, 0, 304, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 779, 0, 306, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x15C7, -146, 237, 0, 154, 0, 0, 0, 779, 0, 308, 0, 0),
    CMD(CM_RJA4, 5, 96, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA3, 5, 44, 25), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8196, 8197, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA4, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C8, 0, 237, 0, 154, 0, 0, 0, 779, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 1, 0, 0, 0, 0, 0, 779, 0, 0, 28, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 1, 0, 0, 0, 0, 0, 779, 0, 0, 30, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 779, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 779, 0, 302, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1620, 0, 1, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1621, 0, 1, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1622, 0, 1, 0, 0, 0, 0, 0, 780, 0, 312, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1623, 0, 1, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1624, 0, 1, 0, 0, 0, 0, 0, 780, 0, 300, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1625, 0, 1, 0, 0, 0, 0, 0, 780, 0, 314, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1626, 0, 1, 0, 0, 0, 0, 0, 780, 0, 314, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x1627, 0, 1, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_QUAY, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 612, 0, 0, 0, 0, 0x1628, -144, 235, 0, 170, 0, 1, 103, 780, 0, 314, 0, 0),
    L6(2, 0, 639, 0, 0, 0, 0, 0x1629, 0, 235, 0, 128, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x162A, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 96, 34), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x162B, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 0, 0, 0x162C, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x162D, 0, 1, 0, 0, 0, 0, 0, 768, 0, 316, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x162E, 0, 1, 0, 0, 0, 0, 0, 768, 0, 302, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 768, 0, 316, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0021, 0x0D00, 0x0024,
};

/* script: 48 ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), 49 ATTACK 7 M: SA II 23623+P (routine Att_SLIDE_and_JUMP), 50 ATTACK 7 L: SA II 23623+P (routine Att_SLIDE_and_JUMP), 51 ATTACK 7 SP: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_048_head[4] = { HEAD(6, 0, 32, 14, 0, 6, 0) };
const u16 yun_saca_048[412] = {
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 52, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 617, 0, 0, 0, 0, 0x16AE, 0, 189, 0, 0, 0, 0, 0, 0, 0, 404, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16AF, 0, 189, 0, 0, 0, 13, 5, 0, 0, 406, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1693, 0, 189, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0),
    L6(47, 0, 0, 0, 0, 0, 0, 0x16B1, 0, 189, 0, 0, 0, 0, 0, 0, 0, 410, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x16B2, 0, 189, 0, 0, 0, 30, 6, 0, 0, 412, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16B3, 0, 189, 0, 0, 0, 0, 0, 0, 0, 414, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16B4, 0, 189, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16B5, 0, 189, 0, 0, 0, 0, 0, 0, 0, 418, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16B6, -37, 298, 0, 128, 0, 0, 0, 0, 96, 420, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x16B7, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x16B8, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16B9, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BA, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BB, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BC, 0, 17, 0, 0, 0, 0, 0, 0, 0, 460, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 462, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 464, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x16BF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 466, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x138E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13BB, -38, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    CMD(CM_HJMP, 8194, 8194, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x13BC, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x13BD, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1394, 0, 138, 0, 0, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1395, 0, 138, 0, 0, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1396, 0, 1, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), 53 ATTACK 8 M: after SA II 23623+P (routine Att_SLIDE_and_JUMP), 54 ATTACK 8 L: after SA II 23623+P (routine Att_SLIDE_and_JUMP), 55 ATTACK 8 SP: after SA II 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_052_head[4] = { HEAD(6, 0, 32, 14, 0, 4, 0) };
const u16 yun_saca_052[460] = {
    L6(2, 21, 0, 0, 0, 0, 0, 0x13BC, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x13BD, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x13A6, 0, 16, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A7, 0, 17, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A8, -39, 18, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13A9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13AA, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13B1, 0, 79, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(2, 0, 614, 0, 0, 0, 0, 0x13B2, 0, 79, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B3, 0, 79, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x13B4, -40, 24, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13B5, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 21, 0, 0, 0, 0, 0, 0x13B6, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13CC, 0, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 7, 98, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1521, 0, 1, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1522, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 616, 0, 0, 0, 0, 0x1523, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1524, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1525, -82, 118, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1526, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1527, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1528, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1529, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x152A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152B, -83, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16387, 16389, 16389), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 1, 3, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 1, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 2, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x152C, 0, 117, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x152D, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x152E, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x152F, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1530, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: 6(123)4+K (plain script), 57 ATTACK 9 M: 6(123)4+K (plain script), 58 ATTACK 9 L: 6(123)4+K (plain script), 59 ATTACK 9 SP: 6(123)4+K (plain script) */
const u16 yun_saca_056_head[4] = { HEAD(6, 0, 24, 16, 0, 0, 74) };
const u16 yun_saca_056[160] = {
    CMD(CM_JPSS, 8, 52, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B2, -43, 186, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x151C, 0, 193, 0, 0, 0, 21, 0, 0, 0, 338, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x151D, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x151E, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x151C, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command */
const u16 yun_saca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yun_saca_060[220] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14F9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x14FE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x123E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: SA III 23623+P (plain script), 62 ATTACK 10 L: SA III 23623+P (plain script), 63 ATTACK 10 SP: SA III 23623+P (plain script), 64 ATTACK 11 S: SA III 23623+P (plain script) */
const u16 yun_saca_061_head[4] = { HEAD(6, 0, 32, 8, 0, 0, 0) };
const u16 yun_saca_061[948] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x15E7, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15E8, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15E9, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 617, 0, 0, 0, 0, 0x15EA, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15EA, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15EB, 0, 189, 0, 0, 0, 13, 29, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15EC, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15ED, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15EE, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15EF, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 59, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(12, 0, 0, 0, 0, 0, 0, 0x15F0, 0, 189, 0, 0, 0, 1, 60, 783, 0, 0, 0, 0),
    CMD(CM_IMGS, 0, 7, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 625, 0, 0, 0, 0, 0x15F1, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15F2, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15F3, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15F4, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x15F5, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15F6, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15F7, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15F8, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15F9, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15FA, 0, 189, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15FB, 0, 1, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15FC, 0, 1, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15FD, 0, 1, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x15FD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0021, 0x0000, 0x0000, 0x0010, 0x0005, 0x0028, 0x0016,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x003D, 0xFFCE, 0x0039, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2640, 0x0000, 0x1520,
    CMD(CM_UJA4, -24576, 0, 3331), 0x0000, 0x0000, 0x0048, 0x0000, 0x0200, 0x0000, 0x0000, 0x1521,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x2400, 0x0000, 0x0000, 0x1522,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0114, 0x0000, 0x0000, 0x1523,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x0048, 0x0000, 0x000C, 0x0000, 0x0000, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x2680, 0x0000, 0x1524,
    CMD(CM_UJA4, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1525,
    L6(250, 14, 2560, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 21, 38),
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2680, 0x0000, 0x1527,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1528,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x1529,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x152A,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x152B,
    L6(249, 206, 3072, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 512, 0, 0, 21, 44),
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x152D,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x152E,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x152F,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0x0000, 0x0000, 0x1530,
    CMD(CM_FOR2, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x1531,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0228, 0x0000, 0x0000, 0x1241,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2670, 0x0000, 0x1410,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x1411,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x1412,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x1413,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0048, 0x0000, 0x0100, 0x0000, 0x0000, 0x1414,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x1415,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0100, 0x0000, 0x0000, 0x1416,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x004A, 0x0000, 0x0010, 0x0007, 0x0018, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0007, 0x000C, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0214, 0x0000, 0x0000, 0x1417,
    L6(249, 143, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 74, 0, 0, 768, 0, 0, 20, 24),
    CMD(CM_NEX2, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x1419,
    L6(6, 207, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 20, 26),
    CMD(CM_NEX2, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x141B,
    CMD(CM_FOR2, -32768, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x141C,
    CMD(CM_NEX2, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x149E,
    CMD(CM_RJA3, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x149F,
    CMD(CM_RJA3, -8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x021E, 0x0000, 0x0000, 0x14A0,
    L6(238, 15, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 20, 161),
    L6(18, 15, 0, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 20, 162),
    L6(18, 15, 512, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 20, 163),
    L6(18, 21, 512, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 20, 164),
    L6(18, 21, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 20, 165),
    L6(18, 21, 512, 0, 0, 2048, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 20, 166),
    L6(18, 21, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 64000, 0, 0, 20, 29),
    CMD(CM_NEX2, 24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 65 ATTACK 11 M: not started by a command */
const u16 yun_saca_065_head[4] = { HEAD(6, 0, 33, 10, 0, 1, 0) };
const u16 yun_saca_065[280] = {
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 613, 0, 0, 0, 0, 0x14E8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 639, 0, 0, 0, 0, 0x14EA, -80, 113, 0, 143, 0, 1, 16, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14EA, 80, 113, 0, 143, 0, 30, 43, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14EB, 80, 114, 0, 0, 0, 30, 29, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14EC, 80, 115, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14ED, 0, 115, 0, 0, 32, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x14EE, 0, 1, 0, 0, 0, 21, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: not started by a command */
const u16 yun_saca_069_head[4] = { HEAD(6, 0, 33, 13, 0, 3, 31) };
const u16 yun_saca_069[268] = {
    CMD(CM_RJA, 5, 69, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 614, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1544, 0, 109, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1545, 0, 109, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1546, 0, 109, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(4, 20, 0, 0, 0, 0, 0, 0x1547, -98, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1548, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1548, -97, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1549, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1549, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x154A, -97, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x154B, 0, 112, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x154C, 0, 108, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x154D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x154E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1239, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: not started by a command, 71 ATTACK 12 SP: not started by a command, 72 ATTACK 13 S: not started by a command, 73 ATTACK 13 M: not started by a command */
const u16 yun_saca_070_head[4] = { HEAD(4, 0, 0, 10, 0, 1, 33) };
const u16 yun_saca_070[116] = {
    CMD(CM_JPSS, 8, 73, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x12B1, 0, 344, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x146D, 0, 131, 0, 0, 0, 22, 20),
    L4(6, 0, 0, 0, 0, 0, 0, 0x146E, 0, 131, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1471, -173, 203, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1472, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1473, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1474, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1475, 0, 135, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: not started by a command */
const u16 yun_saca_074_head[4] = { HEAD(6, 0, 8, 16, 0, 1, 0) };
const u16 yun_saca_074[148] = {
    CMD(CM_CAFR, 2, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B2, -43, 186, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x151C, 0, 193, 0, 0, 0, 0, 0, 0, 0, 338, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x151D, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x151E, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x151C, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14B1, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14B0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 ATTACK 13 SP: not started by a command */
const u16 yun_saca_075_head[4] = { HEAD(4, 0, 33, 12, 0, 6, 36) };
const u16 yun_saca_075[316] = {
    L4(2, 50, 615, 0, 0, 0, 0, 0x14FF, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 40, 0, 0, 0, 0, 0, 0x1500, -54, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1501, 54, 198, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1502, -55, 199, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x1503, -56, 213, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1504, 56, 129, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1505, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1506, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1507, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1508, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1509, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x150A, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 616, 0, 0, 0, 0, 0x1524, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1417, -26, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1418, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1419, 26, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x141A, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x141B, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 616, 0, 0, 0, 0, 0x141C, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x14A0, -75, 120, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 120, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 615, 0, 0, 0, 0, 0x14A3, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x149E, 0, 167, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1417, -27, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1418, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1419, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x141A, 0, 122, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x141B, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 116, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 not started by a command, 77 not started by a command, 78 not started by a command, 79 not started by a command */
const u16 yun_saca_076_head[4] = { HEAD(4, 0, 36, 10, 0, 1, 33) };
const u16 yun_saca_076[108] = {
    CMD(CM_JSR, 8, 55, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x12B1, 0, 344, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x146D, 0, 131, 0, 0, 0, 22, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x146E, 0, 131, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x146F, 0, 131, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1471, -131, 203, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1472, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1473, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1474, 0, 203, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1475, 0, 135, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1476, 0, 131, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1477, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 14, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 not started by a command, 81 not started by a command, 82 not started by a command */
const u16 yun_saca_080_head[4] = { HEAD(4, 0, 0, 8, 0, 2, 0) };
const u16 yun_saca_080[364] = {
    L4(2, 0, 2051, 0, 0, 0, 0, 0x1630, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1631, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1632, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1633, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1634, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1635, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1636, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1637, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1638, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 40, 270, 0, 0, 0, 0, 0x163B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163D, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163E, -13, 234, 0, 0, 0, 21, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x163F, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1640, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1641, 0, 394, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 16395), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1642, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1643, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1644, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1645, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163D, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163E, -13, 234, 0, 0, 0, 21, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x163F, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1640, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1641, 0, 394, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, -32759, 8192), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1646, 0, 394, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1647, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1648, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1649, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x164A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x164B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x164C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x164D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x164E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x164F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1650, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1651, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1652, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1653, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1654, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1654, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 not started by a command, 84 not started by a command, 85 not started by a command, 86 not started by a command */
const u16 yun_saca_083_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 yun_saca_083[172] = {
    CMD(CM_JPSS, 8, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 4, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E5, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E4, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E3, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E2, 0, 202, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14E1, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x14E0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x14E0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 623+P light (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_087_head[4] = { HEAD(6, 0, 8, 10, 0, 1, 52) };
const u16 yun_saca_087[304] = {
    CMD(CM_JPSS, 8, 80, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C5, 0, 226, 0, 0, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 226, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -141, 228, 0, 128, 64, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 278, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 623+P medium (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_088_head[4] = { HEAD(6, 0, 10, 10, 0, 1, 52) };
const u16 yun_saca_088[304] = {
    CMD(CM_JPSS, 8, 81, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C5, 0, 226, 0, 0, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 226, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -142, 228, 0, 128, 64, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 278, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 89 623+P heavy (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_089_head[4] = { HEAD(6, 0, 12, 10, 0, 1, 52) };
const u16 yun_saca_089[304] = {
    CMD(CM_JPSS, 8, 82, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C5, 0, 226, 0, 0, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 226, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -143, 228, 0, 128, 0, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 64, 21, 0, 0, 0, 278, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 EX 623+PP (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_090_head[4] = { HEAD(6, 0, 14, 10, 0, 2, 52) };
const u16 yun_saca_090[316] = {
    CMD(CM_JPSS, 8, 74, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 84, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 225, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 226, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 226, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 226, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 226, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C5, -139, 227, 0, 128, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 227, 0, 0, 64, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -140, 228, 0, 128, 0, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 278, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 not started by a command */
const u16 yun_saca_092_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 yun_saca_092[332] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1630, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1631, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1632, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1633, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1634, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1635, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1636, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1637, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1638, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1639, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x163B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163C, -13, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163D, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x163E, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x163F, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1640, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1642, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1643, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1644, 0, 234, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1645, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, -32760, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x163D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x163E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x163F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1646, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1647, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1648, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1649, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x164A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x164B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x164C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x164D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x164E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x164F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1650, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1651, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1652, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1653, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1654, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1654, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 not started by a command, 93 not started by a command */
const u16 yun_saca_091_head[4] = { HEAD(6, 0, 48, 10, 0, 1, 52) };
const u16 yun_saca_091[304] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C5, -149, 227, 0, 128, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 227, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -149, 228, 0, 128, 64, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 278, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 not started by a command */
const u16 yun_saca_094_head[4] = { HEAD(6, 0, 50, 10, 0, 1, 52) };
const u16 yun_saca_094[304] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C5, -149, 227, 0, 128, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 227, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -150, 228, 0, 128, 64, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 278, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 95 not started by a command */
const u16 yun_saca_095_head[4] = { HEAD(6, 0, 52, 10, 0, 1, 52) };
const u16 yun_saca_095[304] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1540, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1541, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1542, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1543, 0, 108, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C1, 0, 225, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C5, -149, 227, 0, 128, 0, 1, 108, 0, 0, 272, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C6, 0, 227, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x15C7, -150, 228, 0, 128, 0, 0, 0, 0, 0, 276, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x15C8, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 229, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 64, 21, 0, 0, 0, 278, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x15CE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15CF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15D1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 yun_saca_096_head[4] = { HEAD(6, 0, 48, 11, 0, 3, 51) };
const u16 yun_saca_096[508] = {
    CMD(CM_JSR, 8, 79, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x13C6, 0, 189, 0, 0, 0, 13, 41, 0, 0, 0, 0, 0),
    L6(4, 0, 617, 0, 0, 0, 0, 0x13C7, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13C8, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(26, 0, 0, 0, 0, 0, 0, 0x13C9, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CA, 0, 189, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x13CB, 0, 189, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CC, -145, 236, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13CD, 0, 236, 0, 138, 0, 0, 0, 0, 0, 300, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13CE, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x13CF, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13D0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C2, 0, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C3, 0, 225, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15C4, 0, 226, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x15C7, -146, 237, 0, 147, 0, 0, 0, 0, 0, 308, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C8, 0, 237, 0, 147, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x15C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 22, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x15CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x15CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x15CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 302, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1620, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1621, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1622, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1623, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1624, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1625, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1626, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x1627, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 20, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 612, 0, 0, 0, 0, 0x1628, -144, 235, 0, 128, 0, 1, 103, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1629, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x162A, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x162B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 0, 0, 0x162C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x162D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x162E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1241, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1240, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x123F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 not started by a command */
const u16 yun_saca_097_head[4] = { HEAD(6, 0, 32, 14, 0, 4, 0) };
const u16 yun_saca_097[424] = {
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 98, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 612, 0, 0, 0, 0, 0x13C0, 0, 189, 0, 0, 0, 13, 5, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C1, 0, 189, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13C2, 0, 189, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(37, 0, 0, 0, 0, 0, 0, 0x13D7, 0, 189, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(2, 30, 616, 0, 0, 0, 0, 0x13D8, 0, 189, 0, 0, 0, 30, 6, 0, 0, 96, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13D9, 0, 189, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x13C3, -37, 190, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13C4, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 616, 0, 0, 0, 0, 0x138E, 0, 30, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x138F, 0, 30, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13BB, -38, 191, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x13BC, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x13BD, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 616, 0, 0, 0, 0, 0x13A6, 0, 16, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A7, 0, 17, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13A8, -39, 18, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13A9, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13AA, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13B1, 0, 79, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(2, 0, 614, 0, 0, 0, 0, 0x13B2, 0, 79, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x13B3, 0, 79, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x13B4, -40, 24, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x13B5, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 21, 0, 0, 0, 0, 0, 0x13B6, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8194, 8194, 8194), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x13B7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13B8, 0, 47, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x13B9, 0, 47, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x13BA, 0, 47, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1236, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1237, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1238, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 not started by a command */
const u16 yun_saca_098_head[4] = { HEAD(6, 0, 32, 14, 0, 2, 0) };
const u16 yun_saca_098[828] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x13B7, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1410, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1411, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1412, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1413, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1414, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1415, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1416, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1417, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1418, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1419, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x141A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x141B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x141C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x141D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x149E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x149F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x13CC, 0, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 44, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1521, 0, 1, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1522, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 20, 616, 0, 0, 0, 0, 0x1523, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1524, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1525, -82, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1526, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1527, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1528, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1529, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x152A, 0, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152B, -83, 118, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152C, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x152D, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152E, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x152F, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1530, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1531, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 255, 0, 0, 0, 0, 0, 0x1531, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0008, 0x0900, 0x0100, 0x0004, 0x0008, 0x0027, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x001E, 0x0004, 0x0004, 0x0002,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C2,
    CMD(CM_UJA5, 16384, 0, 5376), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C3,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x16C4,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C5,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C6,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C7,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x16C8,
    CMD(CM_UJA5, 16384, 0, 8448), 0x0000, 0x0000, 0x0000, 0x0000, 0x0200, 0x2680, 0x0000, 0x16C9,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0044, 0x0000, 0x0200, 0x0000, 0x0000, 0x16CA,
    CMD(CM_UJA5, 16384, 0, 0), 0x0000, 0x0000, 0x0044, 0x0000, 0x0034, 0x0008, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x16CB,
    L6(250, 142, 512, 0, 0, 2292, 0, 0x0110, 0, 0, 0, 0, 68, 0, 0, 1792, 0, 0, 22, 204),
    L6(5, 142, 1024, 0, 0, 2292, 0, 0x1E2B, 0, 0, 0, 0, 0, 0, 0, 1280, 0, 0, 22, 205),
    L6(5, 206, 1536, 0, 0, 4, 0, 0x1E1D, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 22, 206),
    L6(5, 206, 1536, 0, 0, 4, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 22, 207),
    CMD(CM_UJA6, 16384, 0, 5376), 0x0000, 0x0000, 0x0046, 0x0000, 0x0340, 0x0000, 0x0000, 0x16D0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0046, 0x0000, 0x0300, 0x0000, 0x0000, 0x16D1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0046, 0x0000, 0x0400, 0x0000, 0x0000, 0x1236,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1237,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1238,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 32 ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN) */
const u16 yun_saca_032_head[4] = { HEAD(6, 0, 9, 10, 0, 2, 29) };
const u16 yun_saca_032[316] = {
    CMD(CM_JPSS, 8, 91, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 90, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 615, 0, 0, 0, 0, 0x1533, 0, 272, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1534, 0, 272, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1536, 0, 272, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1538, 0, 273, 0, 0, 0, 30, 38, 0, 0, 398, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1539, -157, 274, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153B, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153C, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153D, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x153E, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -158, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN) */
const u16 yun_saca_033_head[4] = { HEAD(6, 0, 11, 10, 0, 2, 29) };
const u16 yun_saca_033[340] = {
    CMD(CM_JPSS, 8, 92, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 90, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 615, 0, 0, 0, 0, 0x1533, 0, 272, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1534, 0, 272, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1535, 0, 272, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1536, 0, 272, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1537, 0, 272, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1538, 0, 273, 0, 0, 0, 30, 38, 0, 0, 398, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1539, -159, 274, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153B, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153C, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153D, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x153E, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -160, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) */
const u16 yun_saca_034_head[4] = { HEAD(6, 0, 13, 10, 0, 2, 29) };
const u16 yun_saca_034[340] = {
    CMD(CM_JPSS, 8, 93, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 90, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 615, 0, 0, 0, 0, 0x1533, 0, 272, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1534, 0, 272, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1535, 0, 272, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1536, 0, 272, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1537, 0, 272, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1538, 0, 273, 0, 0, 0, 30, 38, 0, 0, 398, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1539, -161, 274, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153B, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153C, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153D, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x153E, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -162, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
const u16 yun_saca_035_head[4] = { HEAD(6, 0, 15, 10, 0, 2, 29) };
const u16 yun_saca_035[316] = {
    CMD(CM_JPSS, 8, 93, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 90, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 86, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 615, 0, 0, 0, 0, 0x1533, 0, 189, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1534, 0, 189, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1536, 0, 189, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1538, 0, 192, 0, 0, 0, 30, 38, 0, 0, 398, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1539, -163, 274, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153C, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153D, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x153E, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -165, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A1, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A2, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command, 67 ATTACK 11 SP: not started by a command, 68 ATTACK 12 S: not started by a command */
const u16 yun_saca_066_head[4] = { HEAD(6, 0, 33, 10, 0, 2, 29) };
const u16 yun_saca_066[292] = {
    CMD(CM_JSR, 8, 87, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 615, 0, 0, 0, 0, 0x1533, 0, 272, 0, 0, 0, 0, 0, 0, 0, 388, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1534, 0, 272, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1535, 0, 272, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1536, 0, 272, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1537, 0, 272, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x1538, 0, 273, 0, 0, 0, 30, 38, 0, 0, 398, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1539, -166, 274, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153C, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x153D, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x153E, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x14A0, -167, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A3, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x14A4, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x149F, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x149E, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1268, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1269, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126A, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126C, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x126B, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 94 entries */
const u16* const yun_cbca[95] = {
    yun_cbca_000,  /* 0 APPEAR JUNBI 1 */
    yun_cbca_001,  /* 1 APPEAR JUNBI 2 */
    yun_cbca_002,  /* 2 APPEAR JUNBI 3 */
    yun_cbca_003,  /* 3 APPEAR JUNBI 4 */
    yun_cbca_004,  /* 4 APPEAR JUNBI 5 */
    yun_cbca_005,  /* 5 APPEAR JUNBI 6 */
    yun_cbca_006,  /* 6 APPEAR JUNBI 7 */
    yun_cbca_006,  /* 7 APPEAR JUNBI 8 */
    yun_cbca_006,  /* 8 APPEAR 1 */
    yun_cbca_006,  /* 9 APPEAR 2 */
    yun_cbca_010,  /* 10 APPEAR 3 */
    yun_cbca_011,  /* 11 APPEAR 4 */
    yun_cbca_012,  /* 12 APPEAR 5 */
    yun_cbca_013,  /* 13 APPEAR 6 */
    yun_cbca_014,  /* 14 APPEAR 7 */
    yun_cbca_015,  /* 15 APPEAR 8 */
    yun_cbca_016,  /* 16 SP APPEAR 1 */
    yun_cbca_017,  /* 17 SP APPEAR 2 */
    yun_cbca_018,  /* 18 SP APPEAR 3 */
    yun_cbca_019,  /* 19 SP APPEAR 4 */
    yun_cbca_020,  /* 20 SP APPEAR 5 */
    yun_cbca_021,  /* 21 SP APPEAR 6 */
    yun_cbca_022,  /* 22 SP APPEAR 7 */
    yun_cbca_023,  /* 23 SP APPEAR 8 */
    yun_cbca_024,  /* 24 ZANNEN 1 */
    yun_cbca_025,  /* 25 ZANNEN 2 */
    yun_cbca_026,  /* 26 ZANNEN 3 */
    yun_cbca_027,  /* 27 ZANNEN 4 */
    yun_cbca_028,  /* 28 ZANNEN 5 */
    yun_cbca_029,  /* 29 ZANNEN 6 */
    yun_cbca_030,  /* 30 ZANNEN 7 */
    yun_cbca_031,  /* 31 ZANNEN 8 */
    yun_cbca_032,  /* 32 WIN 1 */
    yun_cbca_033,  /* 33 WIN 2 */
    yun_cbca_034,  /* 34 WIN 3 */
    yun_cbca_035,  /* 35 WIN 4 */
    yun_cbca_036,  /* 36 WIN 5 */
    yun_cbca_037,  /* 37 WIN 6 */
    yun_cbca_038,  /* 38 WIN 7 */
    yun_cbca_039,  /* 39 WIN 8 */
    yun_cbca_040,  /* 40 SP WIN 1 */
    yun_cbca_041,  /* 41 SP WIN 2 */
    yun_cbca_042,  /* 42 SP WIN 3 */
    yun_cbca_043,  /* 43 SP WIN 4 */
    yun_cbca_044,  /* 44 SP WIN 5 */
    yun_cbca_045,  /* 45 SP WIN 6 */
    yun_cbca_046,  /* 46 SP WIN 7 */
    yun_cbca_047,  /* 47 SP WIN 8 */
    yun_cbca_048,  /* 48 JUDGMENT WAIT */
    yun_cbca_049,  /* 49 JUDGMENT WAIT */
    yun_cbca_050,  /* 50 JUDGMENT WAIT */
    yun_cbca_051,  /* 51 JUDGMENT WAIT */
    yun_cbca_052,  /* 52 JUDGMENT WIN */
    yun_cbca_053,  /* 53 JUDGMENT WIN */
    yun_cbca_054,  /* 54 JUDGMENT WIN */
    yun_cbca_055,  /* 55 JUDGMENT WIN */
    yun_cbca_056,  /* 56 JUDGMENT LOSE */
    yun_cbca_057,  /* 57 JUDGMENT LOSE */
    yun_cbca_058,  /* 58 JUDGMENT LOSE */
    yun_cbca_059,  /* 59 JUDGMENT LOSE */
    yun_cbca_060,  /* 60 WAIT */
    yun_cbca_061,  /* 61 AFRICA JUMP */
    yun_cbca_062,  /* 62 AFRICA LAND */
    yun_cbca_063,  /* 63 SEAN BALL HIT */
    yun_cbca_064,  /* 64 follow-up of F JUMP P M A */
    yun_cbca_065,  /* 65 BONUS WIN 1 */
    yun_cbca_066,  /* 66 BONUS WIN 2 */
    yun_cbca_067,  /* 67 BONUS WIN 3 */
    yun_cbca_068,  /* 68 APPEAR USE */
    yun_cbca_069,  /* 69 APPEAR USE */
    yun_cbca_070,  /* 70 APPEAR USE */
    yun_cbca_071,  /* 71 APPEAR USE */
    yun_cbca_072,  /* 72 APPEAR USE */
    yun_cbca_073,  /* 73 APPEAR USE */
    yun_cbca_074,  /* 74 APPEAR USE */
    yun_cbca_075,  /* 75 APPEAR USE */
    yun_cbca_076,  /* 76 APPEAR USE */
    yun_cbca_077,  /* 77 APPEAR USE */
    yun_cbca_078,  /* 78 APPEAR USE */
    yun_cbca_079,  /* 79 APPEAR USE */
    yun_cbca_074,  /* 80 APPEAR USE */
    yun_cbca_081,  /* 81 APPEAR USE */
    yun_cbca_082,  /* 82 APPEAR USE */
    yun_cbca_083,  /* 83 APPEAR USE */
    yun_cbca_084,  /* 84 APPEAR USE */
    yun_cbca_085,  /* 85 APPEAR USE */
    yun_cbca_086,  /* 86 APPEAR USE */
    yun_cbca_087,  /* 87 APPEAR USE */
    yun_cbca_088,  /* 88 APPEAR USE */
    yun_cbca_089,  /* 89 APPEAR USE */
    yun_cbca_090,  /* 90 APPEAR USE */
    yun_cbca_091,  /* 91 follow-up of ATTACK 3 S */
    yun_cbca_092,  /* 92 follow-up of ATTACK 3 M */
    yun_cbca_093,  /* 93 follow-up of ATTACK 3 L, ATTACK 3 SP */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 yun_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_000[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 yun_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 yun_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 31, 1),
    CMD(CM_RJA3, 7, 43, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 yun_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 47, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 yun_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 29, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 yun_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_005[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 45, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8, 8 APPEAR 1, 9 APPEAR 2 */
const u16 yun_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 49, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 yun_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_010[12] = {
    CMD(CM_RJA, 0, 4, 7),
    CMD(CM_RJA3, 0, 4, 14),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 yun_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_011[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 yun_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_012[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 yun_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_013[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 80, 1),
    CMD(CM_RJA3, 7, 81, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 yun_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_014[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 yun_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_015[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 32, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 yun_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_016[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 61, 1),
    CMD(CM_RJA3, 7, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 yun_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_017[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 28, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 yun_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_018[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 63, 1),
    CMD(CM_RJA3, 7, 64, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 yun_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_019[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 65, 1),
    CMD(CM_RJA3, 7, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 yun_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_020[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 70, 1),
    CMD(CM_RJA3, 7, 71, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 yun_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_021[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 1, 5),
    CMD(CM_CARE, 2, 1, 5),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 yun_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_022[8] = {
    CMD(CM_RJA6, 4, 8, 4),
    CMD(CM_JMP, 8, 21, 2),
};

/* script: 23 SP APPEAR 8 */
const u16 yun_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_023[16] = {
    CMD(CM_DJMP, 8200, 8192, 8192),
    CMD(CM_CAFR, 2, 1, 3),
    CMD(CM_CARE, 2, 1, 3),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 yun_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 73, 1),
    CMD(CM_RJA3, 7, 74, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 yun_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_025[12] = {
    CMD(CM_RJA, 4, 200, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 yun_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_026[12] = {
    CMD(CM_RJA, 4, 201, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 yun_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_027[12] = {
    CMD(CM_RJA, 4, 203, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 yun_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_028[12] = {
    CMD(CM_RJA, 4, 205, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 yun_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_029[12] = {
    CMD(CM_RJA, 4, 207, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 30 ZANNEN 7 */
const u16 yun_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_030[12] = {
    CMD(CM_RJA, 4, 209, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 31 ZANNEN 8 */
const u16 yun_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_031[12] = {
    CMD(CM_RJA, 4, 213, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 32 WIN 1 */
const u16 yun_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_032[12] = {
    CMD(CM_RJA, 4, 216, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 33 WIN 2 */
const u16 yun_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_033[12] = {
    CMD(CM_RJA, 4, 218, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 34 WIN 3 */
const u16 yun_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_034[12] = {
    CMD(CM_RJA, 4, 221, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 35 WIN 4 */
const u16 yun_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_035[12] = {
    CMD(CM_RJA, 4, 224, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 36 WIN 5 */
const u16 yun_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_036[12] = {
    CMD(CM_RJA, 4, 227, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 yun_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_037[12] = {
    CMD(CM_RJA, 4, 230, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 yun_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_038[12] = {
    CMD(CM_RJA, 4, 233, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 yun_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_039[12] = {
    CMD(CM_RJA, 5, 65, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 yun_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_040[12] = {
    CMD(CM_RJA, 5, 66, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 yun_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_041[12] = {
    CMD(CM_RJA, 5, 67, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 yun_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_042[12] = {
    CMD(CM_RJA, 5, 68, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 yun_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_043[12] = {
    CMD(CM_RJA, 5, 69, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 yun_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_044[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 75, 1),
    CMD(CM_RJA3, 7, 76, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 yun_cbca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_045[12] = {
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -36, 64, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 yun_cbca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_046[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 53, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 yun_cbca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_047[32] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 8, 53, 1),
    CMD(CM_RJA3, 8, 54, 1),
    CMD(CM_RJA4, 5, 44, 23),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 57, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 yun_cbca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_048[12] = {
    CMD(CM_RJA, 4, 217, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 yun_cbca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_049[12] = {
    CMD(CM_RJA, 4, 214, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 yun_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_050[12] = {
    CMD(CM_RJA, 4, 206, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 51 JUDGMENT WAIT */
const u16 yun_cbca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_051[32] = {
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
const u16 yun_cbca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_052[12] = {
    CMD(CM_RJA, 5, 74, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 53 JUDGMENT WIN */
const u16 yun_cbca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_053[12] = {
    CMD(CM_WCNE, 16399, 0, 16386),
    CMD(CM_JMP, 7, 82, 1),
    CMD(CM_JMP, 7, 63, 1),
};

/* script: 54 JUDGMENT WIN */
const u16 yun_cbca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_054[12] = {
    CMD(CM_WCNE, 16399, 0, 16386),
    CMD(CM_JMP, 7, 83, 1),
    CMD(CM_JMP, 7, 64, 1),
};

/* script: 55 JUDGMENT WIN */
const u16 yun_cbca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_055[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 84, 1),
    CMD(CM_RJA3, 7, 85, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 56 JUDGMENT LOSE */
const u16 yun_cbca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_056[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 86, 1),
    CMD(CM_RJA3, 7, 87, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 57 JUDGMENT LOSE */
const u16 yun_cbca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_057[12] = {
    CMD(CM_RJA, 4, 236, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 58 JUDGMENT LOSE */
const u16 yun_cbca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_058[12] = {
    CMD(CM_RJA, 4, 238, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 59 JUDGMENT LOSE */
const u16 yun_cbca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_059[12] = {
    CMD(CM_RJA, 4, 240, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 yun_cbca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_060[12] = {
    CMD(CM_RJA, 4, 242, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 yun_cbca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_061[12] = {
    CMD(CM_RJA, 4, 244, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 yun_cbca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_062[12] = {
    CMD(CM_RJA, 4, 246, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT */
const u16 yun_cbca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_063[12] = {
    CMD(CM_RJA, 4, 248, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 64 follow-up of F JUMP P M A */
const u16 yun_cbca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_064[12] = {
    CMD(CM_RJA, 4, 250, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 65 BONUS WIN 1 */
const u16 yun_cbca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_065[12] = {
    CMD(CM_RJA, 4, 252, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 66 BONUS WIN 2 */
const u16 yun_cbca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_066[12] = {
    CMD(CM_RJA, 4, 254, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 67 BONUS WIN 3 */
const u16 yun_cbca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_067[12] = {
    CMD(CM_RJA, 4, 255, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 68 APPEAR USE */
const u16 yun_cbca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_068[12] = {
    CMD(CM_RJA, 4, 256, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 69 APPEAR USE */
const u16 yun_cbca_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_069[12] = {
    CMD(CM_RJA, 4, 257, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 70 APPEAR USE */
const u16 yun_cbca_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_070[12] = {
    CMD(CM_RJA, 4, 258, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 71 APPEAR USE */
const u16 yun_cbca_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_071[12] = {
    CMD(CM_RJA, 4, 259, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 72 APPEAR USE */
const u16 yun_cbca_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_072[12] = {
    CMD(CM_RJA, 4, 260, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 73 APPEAR USE */
const u16 yun_cbca_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_073[12] = {
    CMD(CM_RJA, 5, 76, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 75 APPEAR USE */
const u16 yun_cbca_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_075[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 88, 1),
    CMD(CM_RJA3, 7, 89, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 76 APPEAR USE */
const u16 yun_cbca_076_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_076[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 90, 1),
    CMD(CM_RJA3, 7, 91, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 77 APPEAR USE */
const u16 yun_cbca_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_077[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 92, 1),
    CMD(CM_RJA3, 7, 93, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 78 APPEAR USE */
const u16 yun_cbca_078_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_078[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 94, 1),
    CMD(CM_RJA3, 7, 95, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 79 APPEAR USE */
const u16 yun_cbca_079_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_079[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 74 APPEAR USE, 80 APPEAR USE */
const u16 yun_cbca_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_074[12] = {
    CMD(CM_RJA, 5, 93, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 81 APPEAR USE */
const u16 yun_cbca_081_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_081[12] = {
    CMD(CM_RJA, 5, 94, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 82 APPEAR USE */
const u16 yun_cbca_082_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_082[12] = {
    CMD(CM_RJA, 5, 95, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 83 APPEAR USE */
const u16 yun_cbca_083_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_083[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 96, 1),
    CMD(CM_RJA3, 7, 97, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 84 APPEAR USE */
const u16 yun_cbca_084_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 52) };
const u16 yun_cbca_084[20] = {
    CMD(CM_EXEC, 49, 13, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 85 APPEAR USE */
const u16 yun_cbca_085_head[4] = { HEAD(2, 0, 14, 13, 0, 10, 31) };
const u16 yun_cbca_085[20] = {
    CMD(CM_EXEC, 49, 14, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 APPEAR USE */
const u16 yun_cbca_086_head[4] = { HEAD(2, 0, 15, 9, 0, 0, 29) };
const u16 yun_cbca_086[20] = {
    CMD(CM_EXEC, 49, 15, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 87 APPEAR USE */
const u16 yun_cbca_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_087[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 99, 1),
    CMD(CM_RJA3, 7, 100, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 88 APPEAR USE */
const u16 yun_cbca_088_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_088[12] = {
    CMD(CM_RJA, 4, 208, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 89 APPEAR USE */
const u16 yun_cbca_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_089[12] = {
    CMD(CM_RJA, 4, 212, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 90 APPEAR USE */
const u16 yun_cbca_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_090[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 101, 1),
    CMD(CM_RJA3, 7, 102, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 91 follow-up of ATTACK 3 S */
const u16 yun_cbca_091_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_091[12] = {
    CMD(CM_RJA, 5, 66, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 92 follow-up of ATTACK 3 M */
const u16 yun_cbca_092_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_092[12] = {
    CMD(CM_RJA, 5, 67, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 93 follow-up of ATTACK 3 L, ATTACK 3 SP */
const u16 yun_cbca_093_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yun_cbca_093[12] = {
    CMD(CM_RJA, 5, 68, 1),
    CMD(CM_SAJP, 2, 8194, 0),
    CMD(CM_BACK, 0, 0, 0),
};

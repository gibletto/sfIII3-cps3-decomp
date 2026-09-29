/*
 * CHUN_CHAR.C  Chun-Li's animation scripts and sprite part tables
 *
 * The animation scripts Chun-Li's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 chun_nmca_000[], chun_nmca_001[], chun_nmca_002[], chun_nmca_003[], chun_nmca_004[], chun_nmca_005[], chun_nmca_006[], chun_nmca_007[], chun_nmca_008[], chun_nmca_011[], chun_nmca_012[], chun_nmca_013[], chun_nmca_014[], chun_nmca_015[], chun_nmca_016[], chun_nmca_017[], chun_nmca_020[], chun_nmca_021[], chun_nmca_022[], chun_nmca_023[], chun_nmca_024[], chun_nmca_026[], chun_nmca_027[], chun_nmca_029[], chun_nmca_030[], chun_nmca_031[], chun_nmca_032[], chun_nmca_033[], chun_nmca_038[], chun_nmca_040[], chun_nmca_041[], chun_nmca_043[], chun_nmca_044[], chun_nmca_045[], chun_nmca_046[], chun_nmca_047[], chun_nmca_048[], chun_nmca_049[], chun_nmca_050[];
extern const u16 chun_nmca_000_head[];
extern const u16 chun_nmca_001_head[];
extern const u16 chun_nmca_002_head[];
extern const u16 chun_nmca_003_head[];
extern const u16 chun_nmca_004_head[];
extern const u16 chun_nmca_005_head[];
extern const u16 chun_nmca_006_head[];
extern const u16 chun_nmca_007_head[];
extern const u16 chun_nmca_008_head[];
extern const u16 chun_nmca_011_head[];
extern const u16 chun_nmca_012_head[];
extern const u16 chun_nmca_013_head[];
extern const u16 chun_nmca_014_head[];
extern const u16 chun_nmca_015_head[];
extern const u16 chun_nmca_016_head[];
extern const u16 chun_nmca_017_head[];
extern const u16 chun_nmca_020_head[];
extern const u16 chun_nmca_021_head[];
extern const u16 chun_nmca_022_head[];
extern const u16 chun_nmca_023_head[];
extern const u16 chun_nmca_024_head[];
extern const u16 chun_nmca_026_head[];
extern const u16 chun_nmca_027_head[];
extern const u16 chun_nmca_029_head[];
extern const u16 chun_nmca_030_head[];
extern const u16 chun_nmca_031_head[];
extern const u16 chun_nmca_032_head[];
extern const u16 chun_nmca_033_head[];
extern const u16 chun_nmca_038_head[];
extern const u16 chun_nmca_040_head[];
extern const u16 chun_nmca_041_head[];
extern const u16 chun_nmca_043_head[];
extern const u16 chun_nmca_044_head[];
extern const u16 chun_nmca_045_head[];
extern const u16 chun_nmca_046_head[];
extern const u16 chun_nmca_047_head[];
extern const u16 chun_nmca_048_head[];
extern const u16 chun_nmca_049_head[];
extern const u16 chun_nmca_050_head[];
extern const u16 chun_dmca_000[], chun_dmca_001[], chun_dmca_002[], chun_dmca_003[], chun_dmca_004[], chun_dmca_006[], chun_dmca_008[], chun_dmca_009[], chun_dmca_010[], chun_dmca_014[], chun_dmca_015[], chun_dmca_018[], chun_dmca_019[], chun_dmca_022[], chun_dmca_025[], chun_dmca_026[], chun_dmca_024[], chun_dmca_029[], chun_dmca_030[], chun_dmca_034[], chun_dmca_036[], chun_dmca_048[], chun_dmca_049[], chun_dmca_050[], chun_dmca_052[], chun_dmca_060[], chun_dmca_064[], chun_dmca_065[], chun_dmca_066[], chun_dmca_067[], chun_dmca_068[], chun_dmca_070[], chun_dmca_071[], chun_dmca_072[], chun_dmca_073[], chun_dmca_074[], chun_dmca_075[], chun_dmca_076[], chun_dmca_078[], chun_dmca_079[], chun_dmca_080[], chun_dmca_082[], chun_dmca_083[], chun_dmca_084[], chun_dmca_090[], chun_dmca_091[], chun_dmca_096[], chun_dmca_097[];
extern const u16 chun_dmca_000_head[];
extern const u16 chun_dmca_001_head[];
extern const u16 chun_dmca_002_head[];
extern const u16 chun_dmca_003_head[];
extern const u16 chun_dmca_004_head[];
extern const u16 chun_dmca_006_head[];
extern const u16 chun_dmca_008_head[];
extern const u16 chun_dmca_009_head[];
extern const u16 chun_dmca_010_head[];
extern const u16 chun_dmca_014_head[];
extern const u16 chun_dmca_015_head[];
extern const u16 chun_dmca_018_head[];
extern const u16 chun_dmca_019_head[];
extern const u16 chun_dmca_022_head[];
extern const u16 chun_dmca_025_head[];
extern const u16 chun_dmca_026_head[];
extern const u16 chun_dmca_024_head[];
extern const u16 chun_dmca_029_head[];
extern const u16 chun_dmca_030_head[];
extern const u16 chun_dmca_034_head[];
extern const u16 chun_dmca_036_head[];
extern const u16 chun_dmca_048_head[];
extern const u16 chun_dmca_049_head[];
extern const u16 chun_dmca_050_head[];
extern const u16 chun_dmca_052_head[];
extern const u16 chun_dmca_060_head[];
extern const u16 chun_dmca_064_head[];
extern const u16 chun_dmca_065_head[];
extern const u16 chun_dmca_066_head[];
extern const u16 chun_dmca_067_head[];
extern const u16 chun_dmca_068_head[];
extern const u16 chun_dmca_070_head[];
extern const u16 chun_dmca_071_head[];
extern const u16 chun_dmca_072_head[];
extern const u16 chun_dmca_073_head[];
extern const u16 chun_dmca_074_head[];
extern const u16 chun_dmca_075_head[];
extern const u16 chun_dmca_076_head[];
extern const u16 chun_dmca_078_head[];
extern const u16 chun_dmca_079_head[];
extern const u16 chun_dmca_080_head[];
extern const u16 chun_dmca_082_head[];
extern const u16 chun_dmca_083_head[];
extern const u16 chun_dmca_084_head[];
extern const u16 chun_dmca_090_head[];
extern const u16 chun_dmca_091_head[];
extern const u16 chun_dmca_096_head[];
extern const u16 chun_dmca_097_head[];
extern const u16 chun_btca_000[], chun_btca_001[], chun_btca_002[], chun_btca_003[], chun_btca_004[], chun_btca_005[], chun_btca_006[], chun_btca_007[], chun_btca_008[], chun_btca_009[], chun_btca_010[], chun_btca_011[], chun_btca_012[], chun_btca_013[], chun_btca_014[], chun_btca_015[], chun_btca_016[], chun_btca_017[], chun_btca_018[], chun_btca_019[], chun_btca_020[], chun_btca_021[], chun_btca_022[], chun_btca_023[], chun_btca_024[], chun_btca_025[], chun_btca_026[], chun_btca_027[], chun_btca_028[], chun_btca_029[], chun_btca_030[], chun_btca_031[], chun_btca_032[], chun_btca_033[], chun_btca_034[];
extern const u16 chun_btca_000_head[];
extern const u16 chun_btca_001_head[];
extern const u16 chun_btca_002_head[];
extern const u16 chun_btca_003_head[];
extern const u16 chun_btca_004_head[];
extern const u16 chun_btca_005_head[];
extern const u16 chun_btca_006_head[];
extern const u16 chun_btca_007_head[];
extern const u16 chun_btca_008_head[];
extern const u16 chun_btca_009_head[];
extern const u16 chun_btca_010_head[];
extern const u16 chun_btca_011_head[];
extern const u16 chun_btca_012_head[];
extern const u16 chun_btca_013_head[];
extern const u16 chun_btca_014_head[];
extern const u16 chun_btca_015_head[];
extern const u16 chun_btca_016_head[];
extern const u16 chun_btca_017_head[];
extern const u16 chun_btca_018_head[];
extern const u16 chun_btca_019_head[];
extern const u16 chun_btca_020_head[];
extern const u16 chun_btca_021_head[];
extern const u16 chun_btca_022_head[];
extern const u16 chun_btca_023_head[];
extern const u16 chun_btca_024_head[];
extern const u16 chun_btca_025_head[];
extern const u16 chun_btca_026_head[];
extern const u16 chun_btca_027_head[];
extern const u16 chun_btca_028_head[];
extern const u16 chun_btca_029_head[];
extern const u16 chun_btca_030_head[];
extern const u16 chun_btca_031_head[];
extern const u16 chun_btca_032_head[];
extern const u16 chun_btca_033_head[];
extern const u16 chun_btca_034_head[];
extern const u16 chun_caca_000[], chun_caca_004[], chun_caca_008[], chun_caca_009[];
extern const u16 chun_caca_000_head[];
extern const u16 chun_caca_004_head[];
extern const u16 chun_caca_008_head[];
extern const u16 chun_caca_009_head[];
extern const u16 chun_cuca_000[], chun_cuca_001[], chun_cuca_002[], chun_cuca_003[], chun_cuca_004[], chun_cuca_005[], chun_cuca_006[], chun_cuca_007[], chun_cuca_008[], chun_cuca_009[], chun_cuca_010[], chun_cuca_011[], chun_cuca_012[], chun_cuca_013[], chun_cuca_014[], chun_cuca_015[], chun_cuca_016[], chun_cuca_017[], chun_cuca_018[], chun_cuca_019[], chun_cuca_020[], chun_cuca_021[], chun_cuca_022[], chun_cuca_023[], chun_cuca_024[], chun_cuca_025[], chun_cuca_026[], chun_cuca_027[], chun_cuca_028[], chun_cuca_029[], chun_cuca_030[], chun_cuca_031[], chun_cuca_032[], chun_cuca_033[], chun_cuca_034[], chun_cuca_035[], chun_cuca_036[], chun_cuca_037[], chun_cuca_038[], chun_cuca_039[], chun_cuca_040[], chun_cuca_041[], chun_cuca_042[], chun_cuca_043[], chun_cuca_044[], chun_cuca_045[], chun_cuca_046[], chun_cuca_047[], chun_cuca_048[], chun_cuca_049[], chun_cuca_050[], chun_cuca_051[], chun_cuca_052[], chun_cuca_053[], chun_cuca_054[], chun_cuca_055[], chun_cuca_056[], chun_cuca_057[], chun_cuca_058[], chun_cuca_059[], chun_cuca_060[], chun_cuca_061[], chun_cuca_062[], chun_cuca_063[], chun_cuca_064[], chun_cuca_065[], chun_cuca_066[], chun_cuca_067[];
extern const u16 chun_cuca_000_head[];
extern const u16 chun_cuca_001_head[];
extern const u16 chun_cuca_002_head[];
extern const u16 chun_cuca_003_head[];
extern const u16 chun_cuca_004_head[];
extern const u16 chun_cuca_005_head[];
extern const u16 chun_cuca_006_head[];
extern const u16 chun_cuca_007_head[];
extern const u16 chun_cuca_008_head[];
extern const u16 chun_cuca_009_head[];
extern const u16 chun_cuca_010_head[];
extern const u16 chun_cuca_011_head[];
extern const u16 chun_cuca_012_head[];
extern const u16 chun_cuca_013_head[];
extern const u16 chun_cuca_014_head[];
extern const u16 chun_cuca_015_head[];
extern const u16 chun_cuca_016_head[];
extern const u16 chun_cuca_017_head[];
extern const u16 chun_cuca_018_head[];
extern const u16 chun_cuca_019_head[];
extern const u16 chun_cuca_020_head[];
extern const u16 chun_cuca_021_head[];
extern const u16 chun_cuca_022_head[];
extern const u16 chun_cuca_023_head[];
extern const u16 chun_cuca_024_head[];
extern const u16 chun_cuca_025_head[];
extern const u16 chun_cuca_026_head[];
extern const u16 chun_cuca_027_head[];
extern const u16 chun_cuca_028_head[];
extern const u16 chun_cuca_029_head[];
extern const u16 chun_cuca_030_head[];
extern const u16 chun_cuca_031_head[];
extern const u16 chun_cuca_032_head[];
extern const u16 chun_cuca_033_head[];
extern const u16 chun_cuca_034_head[];
extern const u16 chun_cuca_035_head[];
extern const u16 chun_cuca_036_head[];
extern const u16 chun_cuca_037_head[];
extern const u16 chun_cuca_038_head[];
extern const u16 chun_cuca_039_head[];
extern const u16 chun_cuca_040_head[];
extern const u16 chun_cuca_041_head[];
extern const u16 chun_cuca_042_head[];
extern const u16 chun_cuca_043_head[];
extern const u16 chun_cuca_044_head[];
extern const u16 chun_cuca_045_head[];
extern const u16 chun_cuca_046_head[];
extern const u16 chun_cuca_047_head[];
extern const u16 chun_cuca_048_head[];
extern const u16 chun_cuca_049_head[];
extern const u16 chun_cuca_050_head[];
extern const u16 chun_cuca_051_head[];
extern const u16 chun_cuca_052_head[];
extern const u16 chun_cuca_053_head[];
extern const u16 chun_cuca_054_head[];
extern const u16 chun_cuca_055_head[];
extern const u16 chun_cuca_056_head[];
extern const u16 chun_cuca_057_head[];
extern const u16 chun_cuca_058_head[];
extern const u16 chun_cuca_059_head[];
extern const u16 chun_cuca_060_head[];
extern const u16 chun_cuca_061_head[];
extern const u16 chun_cuca_062_head[];
extern const u16 chun_cuca_063_head[];
extern const u16 chun_cuca_064_head[];
extern const u16 chun_cuca_065_head[];
extern const u16 chun_cuca_066_head[];
extern const u16 chun_cuca_067_head[];
extern const u16 chun_atca_000[], chun_atca_001[], chun_atca_003[], chun_atca_005[], chun_atca_006[], chun_atca_008[], chun_atca_009[], chun_atca_012[], chun_atca_013[], chun_atca_014[], chun_atca_015[], chun_atca_016[], chun_atca_018[], chun_atca_021[], chun_atca_024[], chun_atca_027[], chun_atca_030[], chun_atca_033[], chun_atca_035[], chun_atca_036[], chun_atca_038[], chun_atca_040[], chun_atca_042[], chun_atca_044[], chun_atca_046[], chun_atca_048[], chun_atca_050[], chun_atca_052[], chun_atca_053[], chun_atca_054[], chun_atca_056[], chun_atca_045[], chun_atca_058[], chun_atca_060[], chun_atca_062[], chun_atca_064[], chun_atca_066[], chun_atca_068[], chun_atca_070[], chun_atca_072[], chun_atca_074[], chun_atca_076[], chun_atca_078[], chun_atca_080[], chun_atca_082[], chun_atca_084[], chun_atca_086[], chun_atca_088[], chun_atca_090[], chun_atca_092[], chun_atca_094[], chun_atca_096[], chun_atca_098[], chun_atca_100[], chun_atca_102[], chun_atca_104[], chun_atca_106[], chun_atca_108[], chun_atca_144[], chun_atca_146[], chun_atca_150[], chun_atca_152[], chun_atca_156[], chun_atca_157[], chun_atca_158[];
extern const u16 chun_atca_000_head[];
extern const u16 chun_atca_001_head[];
extern const u16 chun_atca_003_head[];
extern const u16 chun_atca_005_head[];
extern const u16 chun_atca_006_head[];
extern const u16 chun_atca_008_head[];
extern const u16 chun_atca_009_head[];
extern const u16 chun_atca_012_head[];
extern const u16 chun_atca_013_head[];
extern const u16 chun_atca_014_head[];
extern const u16 chun_atca_015_head[];
extern const u16 chun_atca_016_head[];
extern const u16 chun_atca_018_head[];
extern const u16 chun_atca_021_head[];
extern const u16 chun_atca_024_head[];
extern const u16 chun_atca_027_head[];
extern const u16 chun_atca_030_head[];
extern const u16 chun_atca_033_head[];
extern const u16 chun_atca_035_head[];
extern const u16 chun_atca_036_head[];
extern const u16 chun_atca_038_head[];
extern const u16 chun_atca_040_head[];
extern const u16 chun_atca_042_head[];
extern const u16 chun_atca_044_head[];
extern const u16 chun_atca_046_head[];
extern const u16 chun_atca_048_head[];
extern const u16 chun_atca_050_head[];
extern const u16 chun_atca_052_head[];
extern const u16 chun_atca_053_head[];
extern const u16 chun_atca_054_head[];
extern const u16 chun_atca_056_head[];
extern const u16 chun_atca_045_head[];
extern const u16 chun_atca_058_head[];
extern const u16 chun_atca_060_head[];
extern const u16 chun_atca_062_head[];
extern const u16 chun_atca_064_head[];
extern const u16 chun_atca_066_head[];
extern const u16 chun_atca_068_head[];
extern const u16 chun_atca_070_head[];
extern const u16 chun_atca_072_head[];
extern const u16 chun_atca_074_head[];
extern const u16 chun_atca_076_head[];
extern const u16 chun_atca_078_head[];
extern const u16 chun_atca_080_head[];
extern const u16 chun_atca_082_head[];
extern const u16 chun_atca_084_head[];
extern const u16 chun_atca_086_head[];
extern const u16 chun_atca_088_head[];
extern const u16 chun_atca_090_head[];
extern const u16 chun_atca_092_head[];
extern const u16 chun_atca_094_head[];
extern const u16 chun_atca_096_head[];
extern const u16 chun_atca_098_head[];
extern const u16 chun_atca_100_head[];
extern const u16 chun_atca_102_head[];
extern const u16 chun_atca_104_head[];
extern const u16 chun_atca_106_head[];
extern const u16 chun_atca_108_head[];
extern const u16 chun_atca_144_head[];
extern const u16 chun_atca_146_head[];
extern const u16 chun_atca_150_head[];
extern const u16 chun_atca_152_head[];
extern const u16 chun_atca_156_head[];
extern const u16 chun_atca_157_head[];
extern const u16 chun_atca_158_head[];
extern const u16 chun_exca_000[], chun_exca_001[], chun_exca_003[], chun_exca_004[], chun_exca_005[], chun_exca_007[], chun_exca_008[], chun_exca_009[], chun_exca_010[], chun_exca_011[], chun_exca_013[], chun_exca_014[], chun_exca_015[], chun_exca_016[], chun_exca_017[], chun_exca_018[], chun_exca_019[], chun_exca_020[], chun_exca_021[], chun_exca_022[], chun_exca_023[], chun_exca_024[], chun_exca_025[], chun_exca_026[], chun_exca_027[], chun_exca_029[], chun_exca_030[], chun_exca_032[], chun_exca_033[], chun_exca_034[], chun_exca_037[], chun_exca_038[], chun_exca_039[], chun_exca_040[], chun_exca_041[], chun_exca_042[], chun_exca_043[], chun_exca_044[], chun_exca_045[], chun_exca_046[], chun_exca_047[], chun_exca_048[], chun_exca_049[], chun_exca_050[], chun_exca_053[], chun_exca_054[], chun_exca_055[], chun_exca_056[], chun_exca_057[], chun_exca_058[], chun_exca_059[], chun_exca_060[], chun_exca_061[], chun_exca_062[], chun_exca_063[], chun_exca_064[], chun_exca_065[];
extern const u16 chun_exca_000_head[];
extern const u16 chun_exca_001_head[];
extern const u16 chun_exca_003_head[];
extern const u16 chun_exca_004_head[];
extern const u16 chun_exca_005_head[];
extern const u16 chun_exca_007_head[];
extern const u16 chun_exca_008_head[];
extern const u16 chun_exca_009_head[];
extern const u16 chun_exca_010_head[];
extern const u16 chun_exca_011_head[];
extern const u16 chun_exca_013_head[];
extern const u16 chun_exca_014_head[];
extern const u16 chun_exca_015_head[];
extern const u16 chun_exca_016_head[];
extern const u16 chun_exca_017_head[];
extern const u16 chun_exca_018_head[];
extern const u16 chun_exca_019_head[];
extern const u16 chun_exca_020_head[];
extern const u16 chun_exca_021_head[];
extern const u16 chun_exca_022_head[];
extern const u16 chun_exca_023_head[];
extern const u16 chun_exca_024_head[];
extern const u16 chun_exca_025_head[];
extern const u16 chun_exca_026_head[];
extern const u16 chun_exca_027_head[];
extern const u16 chun_exca_029_head[];
extern const u16 chun_exca_030_head[];
extern const u16 chun_exca_032_head[];
extern const u16 chun_exca_033_head[];
extern const u16 chun_exca_034_head[];
extern const u16 chun_exca_037_head[];
extern const u16 chun_exca_038_head[];
extern const u16 chun_exca_039_head[];
extern const u16 chun_exca_040_head[];
extern const u16 chun_exca_041_head[];
extern const u16 chun_exca_042_head[];
extern const u16 chun_exca_043_head[];
extern const u16 chun_exca_044_head[];
extern const u16 chun_exca_045_head[];
extern const u16 chun_exca_046_head[];
extern const u16 chun_exca_047_head[];
extern const u16 chun_exca_048_head[];
extern const u16 chun_exca_049_head[];
extern const u16 chun_exca_050_head[];
extern const u16 chun_exca_053_head[];
extern const u16 chun_exca_054_head[];
extern const u16 chun_exca_055_head[];
extern const u16 chun_exca_056_head[];
extern const u16 chun_exca_057_head[];
extern const u16 chun_exca_058_head[];
extern const u16 chun_exca_059_head[];
extern const u16 chun_exca_060_head[];
extern const u16 chun_exca_061_head[];
extern const u16 chun_exca_062_head[];
extern const u16 chun_exca_063_head[];
extern const u16 chun_exca_064_head[];
extern const u16 chun_exca_065_head[];
extern const u16 chun_saca_000[], chun_saca_001[], chun_saca_002[], chun_saca_024[], chun_saca_025[], chun_saca_026[], chun_saca_027[], chun_saca_028[], chun_saca_029[], chun_saca_030[], chun_saca_031[], chun_saca_032[], chun_saca_033[], chun_saca_034[], chun_saca_035[], chun_saca_036[], chun_saca_037[], chun_saca_038[], chun_saca_039[], chun_saca_040[], chun_saca_041[], chun_saca_042[], chun_saca_043[], chun_saca_044[], chun_saca_048[], chun_saca_052[], chun_saca_056[], chun_saca_060[], chun_saca_061[], chun_saca_062[], chun_saca_063[], chun_saca_064[], chun_saca_067[], chun_saca_068[], chun_saca_069[];
extern const u16 chun_saca_000_head[];
extern const u16 chun_saca_001_head[];
extern const u16 chun_saca_002_head[];
extern const u16 chun_saca_024_head[];
extern const u16 chun_saca_025_head[];
extern const u16 chun_saca_026_head[];
extern const u16 chun_saca_027_head[];
extern const u16 chun_saca_028_head[];
extern const u16 chun_saca_029_head[];
extern const u16 chun_saca_030_head[];
extern const u16 chun_saca_031_head[];
extern const u16 chun_saca_032_head[];
extern const u16 chun_saca_033_head[];
extern const u16 chun_saca_034_head[];
extern const u16 chun_saca_035_head[];
extern const u16 chun_saca_036_head[];
extern const u16 chun_saca_037_head[];
extern const u16 chun_saca_038_head[];
extern const u16 chun_saca_039_head[];
extern const u16 chun_saca_040_head[];
extern const u16 chun_saca_041_head[];
extern const u16 chun_saca_042_head[];
extern const u16 chun_saca_043_head[];
extern const u16 chun_saca_044_head[];
extern const u16 chun_saca_048_head[];
extern const u16 chun_saca_052_head[];
extern const u16 chun_saca_056_head[];
extern const u16 chun_saca_060_head[];
extern const u16 chun_saca_061_head[];
extern const u16 chun_saca_062_head[];
extern const u16 chun_saca_063_head[];
extern const u16 chun_saca_064_head[];
extern const u16 chun_saca_067_head[];
extern const u16 chun_saca_068_head[];
extern const u16 chun_saca_069_head[];
extern const u16 chun_cbca_000[], chun_cbca_001[], chun_cbca_002[], chun_cbca_003[], chun_cbca_004[], chun_cbca_005[], chun_cbca_006[], chun_cbca_007[], chun_cbca_008[], chun_cbca_009[], chun_cbca_010[], chun_cbca_012[], chun_cbca_013[], chun_cbca_014[], chun_cbca_015[], chun_cbca_016[], chun_cbca_017[], chun_cbca_018[], chun_cbca_019[], chun_cbca_020[], chun_cbca_021[], chun_cbca_022[], chun_cbca_023[], chun_cbca_024[], chun_cbca_025[], chun_cbca_026[], chun_cbca_027[], chun_cbca_028[], chun_cbca_029[], chun_cbca_038[], chun_cbca_039[], chun_cbca_040[], chun_cbca_041[], chun_cbca_042[], chun_cbca_043[], chun_cbca_044[];
extern const u16 chun_cbca_000_head[];
extern const u16 chun_cbca_001_head[];
extern const u16 chun_cbca_002_head[];
extern const u16 chun_cbca_003_head[];
extern const u16 chun_cbca_004_head[];
extern const u16 chun_cbca_005_head[];
extern const u16 chun_cbca_006_head[];
extern const u16 chun_cbca_007_head[];
extern const u16 chun_cbca_008_head[];
extern const u16 chun_cbca_009_head[];
extern const u16 chun_cbca_010_head[];
extern const u16 chun_cbca_012_head[];
extern const u16 chun_cbca_013_head[];
extern const u16 chun_cbca_014_head[];
extern const u16 chun_cbca_015_head[];
extern const u16 chun_cbca_016_head[];
extern const u16 chun_cbca_017_head[];
extern const u16 chun_cbca_018_head[];
extern const u16 chun_cbca_019_head[];
extern const u16 chun_cbca_020_head[];
extern const u16 chun_cbca_021_head[];
extern const u16 chun_cbca_022_head[];
extern const u16 chun_cbca_023_head[];
extern const u16 chun_cbca_024_head[];
extern const u16 chun_cbca_025_head[];
extern const u16 chun_cbca_026_head[];
extern const u16 chun_cbca_027_head[];
extern const u16 chun_cbca_028_head[];
extern const u16 chun_cbca_029_head[];
extern const u16 chun_cbca_038_head[];
extern const u16 chun_cbca_039_head[];
extern const u16 chun_cbca_040_head[];
extern const u16 chun_cbca_041_head[];
extern const u16 chun_cbca_042_head[];
extern const u16 chun_cbca_043_head[];
extern const u16 chun_cbca_044_head[];

/* normal scripts: 51 entries */
const u16* const chun_nmca[52] = {
    chun_nmca_000,  /* 0 KAMAE */
    chun_nmca_001,  /* 1 HURIMUKI */
    chun_nmca_002,  /* 2 FRONT WALK */
    chun_nmca_003,  /* 3 BACK WALK */
    chun_nmca_004,  /* 4 DASH HUMIKOMI */
    chun_nmca_005,  /* 5 DASH TOBINOKI */
    chun_nmca_006,  /* 6 KAGAMU */
    chun_nmca_007,  /* 7 KAGAMI KAMAE */
    chun_nmca_008,  /* 8 KAGAMI TURN */
    chun_nmca_008,  /* 9 KAGAMI F WALK */
    chun_nmca_008,  /* 10 KAGAMI B WALK */
    chun_nmca_011,  /* 11 STAND UP */
    chun_nmca_012,  /* 12 JUMP JUNBI */
    chun_nmca_013,  /* 13 SP JUMP JUNBI */
    chun_nmca_014,  /* 14 JUMP FRONT */
    chun_nmca_015,  /* 15 JUMP VERTICAL */
    chun_nmca_016,  /* 16 JUMP BACK */
    chun_nmca_017,  /* 17 S JUMP FRONT */
    chun_nmca_017,  /* 18 S JUMP V */
    chun_nmca_017,  /* 19 S JUMP BACK */
    chun_nmca_020,  /* 20 SP JUMP FRONT */
    chun_nmca_021,  /* 21 SP JUMP V */
    chun_nmca_022,  /* 22 SP JUMP BACK */
    chun_nmca_023,  /* 23 WALK END */
    chun_nmca_024,  /* 24 PARING HEAD */
    chun_nmca_024,  /* 25 PARING UP */
    chun_nmca_026,  /* 26 PARING DOWN */
    chun_nmca_027,  /* 27 PARING AIR F */
    chun_nmca_027,  /* 28 PARING AIR B */
    chun_nmca_029,  /* 29 GUARD HEAD */
    chun_nmca_030,  /* 30 GUARD UP */
    chun_nmca_031,  /* 31 GUARD DOWN */
    chun_nmca_032,  /* 32 GUARD AIR */
    chun_nmca_033,  /* 33 no name */
    chun_nmca_033,  /* 34 no name */
    chun_nmca_033,  /* 35 no name */
    chun_nmca_033,  /* 36 no name */
    chun_nmca_033,  /* 37 no name */
    chun_nmca_038,  /* 38 P BREAK ZUJOU */
    chun_nmca_038,  /* 39 P BREAK UP */
    chun_nmca_040,  /* 40 P BREAK DOWN */
    chun_nmca_041,  /* 41 P BREAK AIR F */
    chun_nmca_041,  /* 42 P BREAK AIR R */
    chun_nmca_043,  /* 43 TUKAMIHAZUSI */
    chun_nmca_044,  /* 44 TUKAMIHAZUSARE */
    chun_nmca_045,  /* 45 TUKAMIHAZUSI */
    chun_nmca_046,  /* 46 TUKAMIHAZUSARE */
    chun_nmca_047,  /* 47 no name */
    chun_nmca_048,  /* 48 no name */
    chun_nmca_049,  /* 49 no name */
    chun_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 chun_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_000[276] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A10, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A15, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 0, 0, 14), 0, 0, 0, 0,
    CMD(CM_PJMP, 10, 8194, 8192), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A10, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A15, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A16, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A17, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A15, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A11, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 chun_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_001[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A01, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A02, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A04, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A04, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 chun_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 chun_nmca_002[292] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BA6, 0, 498, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BA7, 0, 498, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BA8, 0, 498, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A20, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A21, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A22, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A23, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A24, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A25, 0, 503, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A26, 0, 503, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A27, 0, 503, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A28, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A29, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2A, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2B, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2C, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2D, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2E, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2F, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A20, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A30, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A31, 0, 499, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A23, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A24, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A25, 0, 503, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A26, 0, 503, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A27, 0, 503, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A28, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A29, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2A, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2B, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2C, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2D, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2E, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A2F, 0, 501, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 chun_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 chun_nmca_003[292] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BA9, 0, 498, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BAA, 0, 498, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BAB, 0, 498, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A40, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A41, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A42, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A43, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A44, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A45, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A46, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A47, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A48, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A49, 0, 502, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A4A, 0, 502, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A4B, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4C, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4D, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4E, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4F, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A40, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A41, 0, 502, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A42, 0, 502, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A43, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A44, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A45, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A46, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A47, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A48, 0, 500, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A49, 0, 500, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A4A, 0, 501, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A4B, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4C, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A4D, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A50, 0, 501, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A51, 0, 501, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 chun_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 chun_nmca_004[112] = {
    CMD(CM_RJA, 0, 4, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AB6, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 277, 0, 0, 0, 0, 0x5B20, 0, 123, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x5B21, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B22, 0, 124, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B23, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5B24, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5B25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 chun_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 chun_nmca_005[160] = {
    L6(2, 1, 0, 0, 0, 0, 0, 0x5B23, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 277, 0, 0, 0, 0, 0x5B30, 0, 126, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x5B30, 0, 126, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B31, 0, 127, 0, 0, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B32, 0, 128, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B33, 0, 129, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x5B34, 0, 130, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B35, 0, 131, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B36, 0, 132, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B37, 0, 133, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B38, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x5B39, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5B39, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 chun_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_nmca_006[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A60, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 chun_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_nmca_007[140] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A81, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A83, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A84, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A85, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A81, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A81, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A85, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A86, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A85, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5A81, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 chun_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_nmca_008[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A90, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A91, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A92, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A93, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A94, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A94, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 chun_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_nmca_011[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 chun_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x5AB6, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5AB6, 0, 97, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB6, 0, 97, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 chun_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_013[20] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB4, 0, 97, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB5, 0, 97, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 chun_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_nmca_014[236] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x5AC0, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC1, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC2, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC3, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC4, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC5, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC6, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC7, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC0, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC1, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC2, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC3, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AC4, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AC5, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 chun_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 chun_nmca_015[188] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x5AA0, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA1, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA2, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA3, 0, 94, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AA4, 0, 94, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AA5, 0, 94, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AA6, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA7, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 chun_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_nmca_016[236] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x5AC8, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC9, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACA, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACB, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACC, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACD, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACE, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACF, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC8, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC9, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACA, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACB, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5ACC, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5ACD, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 chun_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 chun_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 chun_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 chun_nmca_020[236] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 282, 0, 0, 0, 0, 0x5AC0, 0, 92, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AC1, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AC2, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC3, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC4, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC5, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC6, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC7, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC0, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC1, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC2, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC3, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC4, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC5, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 chun_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 chun_nmca_021[188] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x5AA0, 0, 94, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA1, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA2, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA3, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA4, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA5, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA6, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA7, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 chun_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 chun_nmca_022[236] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(3, 0, 282, 0, 0, 0, 0, 0x5AC8, 0, 93, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AC9, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5ACA, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACB, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACC, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACD, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACE, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACF, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC8, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AC9, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACA, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACB, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACC, 0, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5ACD, 0, 93, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA8, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AA9, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAA, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAB, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 chun_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 chun_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A10, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 chun_nmca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_024[112] = {
    L6(2, 132, 0, 0, 0, 0, 0, 0x5D70, 0, 1, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(1, 0, 420, 0, 0, 0, 0, 0x5D71, 0, 1, 0, 0, 0, 6, 0, 0, 0, 150, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x5D71, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D73, 0, 1, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5B25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 chun_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 chun_nmca_026[68] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x5B00, 0, 2, 0, 0, 0, 18, 6),
    L4(1, 0, 420, 0, 0, 0, 0, 0x5B01, 0, 2, 0, 0, 0, 6, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B09, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5B0A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B01, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B01, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B00, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B00, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 chun_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_nmca_027[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x5B10, 0, 95, 0, 0, 0, 18, 6),
    L4(250, 0, 420, 0, 0, 0, 0, 0x5B11, 0, 95, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B12, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B18, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B10, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 chun_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 chun_nmca_029[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AE0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5AE1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5AE2, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x5AE3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AE4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AE5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AE1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 chun_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 chun_nmca_030[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AF0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5AF1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5AF2, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x5AF3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AF4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AF5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AF1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AF0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 chun_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 chun_nmca_031[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B00, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B01, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B02, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x5B03, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5B04, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B05, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B01, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B00, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 chun_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 chun_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A68, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 chun_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_033[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 chun_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_038[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5A60, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A61, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5A81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 chun_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_nmca_040[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A66, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5A81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 chun_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5A68, 0, 95, 0, 0, 0, 18, 8),
    L4(250, 0, 420, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 chun_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_043[84] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5AF6, 0, 124, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AF7, 0, 124, 0, 0, 0, 25, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B40, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B41, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B42, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B43, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5B44, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 chun_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_044[60] = {
    L4(4, 131, 0, 0, 0, 0, 0, 0x5F31, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5F32, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 1, 0, 0, 0, 0, 0, 0x5F33, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5F34, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5F34, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5E00, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E00, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 chun_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_nmca_045[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x5F36, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 422, 0, 0, 0, 0, 0x5F37, 0, 95, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5F38, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F39, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 chun_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x5AAC, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AAD, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5AAE, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 chun_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 chun_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_nmca_048[28] = {
    L4(3, 8, 0, 0, 1, 0, 0, 0x5F40, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x5F41, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x5F41, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 chun_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A01, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 chun_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_nmca_050[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A60, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A61, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5A81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const chun_dmca[99] = {
    chun_dmca_000,  /* 0 GUARD HEAD */
    chun_dmca_001,  /* 1 GUARD UP */
    chun_dmca_002,  /* 2 GUARD DOWN */
    chun_dmca_003,  /* 3 GUARD AIR */
    chun_dmca_004,  /* 4 HUSHIN HEAD */
    chun_dmca_004,  /* 5 HUSHIN UP */
    chun_dmca_006,  /* 6 HUSHIN DOWN */
    chun_dmca_006,  /* 7 HUSHIN AIR */
    chun_dmca_008,  /* 8 FACE S */
    chun_dmca_009,  /* 9 FACE M */
    chun_dmca_010,  /* 10 FACE L */
    chun_dmca_010,  /* 11 FACE SP */
    chun_dmca_008,  /* 12 FOOK OKU S */
    chun_dmca_009,  /* 13 FOOK OKU M */
    chun_dmca_014,  /* 14 FOOK OKU L */
    chun_dmca_015,  /* 15 FOOK OKU SP */
    chun_dmca_008,  /* 16 FOOK TEMAE S */
    chun_dmca_009,  /* 17 FOOK TEMAE M */
    chun_dmca_018,  /* 18 FOOK TEMAE L */
    chun_dmca_019,  /* 19 FOOK TEMAE SP */
    chun_dmca_008,  /* 20 UPPER S */
    chun_dmca_009,  /* 21 UPPER M */
    chun_dmca_022,  /* 22 UPPER L */
    chun_dmca_022,  /* 23 UPPER SP */
    chun_dmca_024,  /* 24 NOUTEN S */
    chun_dmca_025,  /* 25 NOUTEN M */
    chun_dmca_026,  /* 26 NOUTEN L */
    chun_dmca_026,  /* 27 NOUTEN SP */
    chun_dmca_024,  /* 28 BODY BROW S */
    chun_dmca_029,  /* 29 BODY BROW M */
    chun_dmca_030,  /* 30 BODY BROW L */
    chun_dmca_030,  /* 31 BODY BROW SP */
    chun_dmca_024,  /* 32 BODY UPPER S */
    chun_dmca_029,  /* 33 BODY UPPER M */
    chun_dmca_034,  /* 34 BODY UPPER L */
    chun_dmca_034,  /* 35 BODY UPPER SP */
    chun_dmca_036,  /* 36 TATAKI S */
    chun_dmca_036,  /* 37 TATAKI M */
    chun_dmca_036,  /* 38 TATAKI L */
    chun_dmca_036,  /* 39 TATAKI SP */
    chun_dmca_036,  /* 40 TATAKI V. S */
    chun_dmca_036,  /* 41 TATAKI V. M */
    chun_dmca_036,  /* 42 TATAKI V. L */
    chun_dmca_036,  /* 43 TATAKI V. SP */
    chun_dmca_008,  /* 44 NOBASITA TE S */
    chun_dmca_009,  /* 45 NOBASITA TE M */
    chun_dmca_010,  /* 46 NOBASITA TE L */
    chun_dmca_010,  /* 47 NOBASITA TE SP */
    chun_dmca_048,  /* 48 KAGAMI S */
    chun_dmca_049,  /* 49 KAGAMI M */
    chun_dmca_050,  /* 50 KAGAMI L */
    chun_dmca_050,  /* 51 KAGAMI SP */
    chun_dmca_052,  /* 52 KGM TATAKI S */
    chun_dmca_052,  /* 53 KGM TATAKI M */
    chun_dmca_052,  /* 54 KGM TATAKI L */
    chun_dmca_052,  /* 55 KGM TATAKI SP */
    chun_dmca_052,  /* 56 KGM TTKI V.S */
    chun_dmca_052,  /* 57 KGM TTKI V.M */
    chun_dmca_052,  /* 58 KGM TTKI V.L */
    chun_dmca_052,  /* 59 KGM TTKI V.SP */
    chun_dmca_060,  /* 60 NEKOROBI S */
    chun_dmca_060,  /* 61 NEKOROBI M */
    chun_dmca_060,  /* 62 NEKOROBI L */
    chun_dmca_060,  /* 63 NEKOROBI SP */
    chun_dmca_064,  /* 64 OKIAGARI */
    chun_dmca_065,  /* 65 OKIAGARI F */
    chun_dmca_066,  /* 66 OKIAGARI B */
    chun_dmca_067,  /* 67 LOSE NO STAND */
    chun_dmca_068,  /* 68 LOSE SONABA */
    chun_dmca_068,  /* 69 LOSE KAGAMI */
    chun_dmca_070,  /* 70 PIYO */
    chun_dmca_071,  /* 71 UKEMI MOVE F */
    chun_dmca_072,  /* 72 UKEMI MOVE R */
    chun_dmca_073,  /* 73 SHIMEOTASARE */
    chun_dmca_074,  /* 74 TATI TOUKETU S */
    chun_dmca_075,  /* 75 TATI TOUKETU M */
    chun_dmca_076,  /* 76 TATI TOUKETU L */
    chun_dmca_076,  /* 77 TATI TOUKETU P */
    chun_dmca_078,  /* 78 KGM TOUKETU S */
    chun_dmca_079,  /* 79 KGM TOUKETU M */
    chun_dmca_080,  /* 80 KGM TOUKETU L */
    chun_dmca_080,  /* 81 KGM TOUKETU P */
    chun_dmca_082,  /* 82 TATI DENGEKI S */
    chun_dmca_083,  /* 83 TATI DENGEKI M */
    chun_dmca_084,  /* 84 TATI DENGEKI L */
    chun_dmca_084,  /* 85 TATI DENGEKI P */
    chun_dmca_082,  /* 86 KGM DENGEKI S */
    chun_dmca_083,  /* 87 KGM DENGEKI M */
    chun_dmca_084,  /* 88 KGM DENGEKI L */
    chun_dmca_084,  /* 89 KGM DENGEKI P */
    chun_dmca_090,  /* 90 OKIAGARI FRONT */
    chun_dmca_091,  /* 91 OKIAGARI REAR */
    chun_dmca_008,  /* 92 TATI MOE S */
    chun_dmca_009,  /* 93 TATI MOE M */
    chun_dmca_010,  /* 94 TATI MOE L */
    chun_dmca_010,  /* 95 TATI MOE SP */
    chun_dmca_096,  /* 96 no name */
    chun_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 chun_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_000[84] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x5AE5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AE6, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x5AE7, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AE8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AE4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AE5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AE1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 chun_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_001[84] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x5AF5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AF6, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x5AF7, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AF8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AF4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AF5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AF1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5AF0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 chun_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x5B05, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5B06, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x5B07, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5B08, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B04, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B05, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B05, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 chun_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x5A68, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x5A69, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x5A69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A69, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A69, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 chun_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_004[44] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5A81, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A83, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 chun_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_006[52] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A88, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5A81, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A82, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5A83, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 chun_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B70, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 133, 418, 0, 0, 0, 0, 0x5B70, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B71, 0, 327, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 chun_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B80, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 134, 418, 0, 0, 0, 0, 0x5B80, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B81, 0, 328, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B82, 0, 328, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B71, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 chun_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_010[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B90, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 137, 419, 0, 0, 0, 0, 0x5B90, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B91, 0, 328, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B92, 0, 329, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B93, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B94, 0, 329, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B95, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B96, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 chun_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_014[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BB0, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 136, 419, 0, 0, 0, 0, 0x5BB1, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BB2, 0, 328, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x5BB3, 0, 329, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x5BB4, 0, 329, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BB5, 0, 330, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BB6, 0, 330, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BB7, 0, 329, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BB8, 0, 328, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 chun_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_015[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B80, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 137, 419, 0, 0, 0, 0, 0x5BB0, 0, 328, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BB1, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BB2, 0, 329, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x5BB3, 0, 329, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x5BB4, 0, 330, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BB5, 0, 330, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BB6, 0, 329, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BB7, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BB8, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 chun_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_018[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BC1, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 137, 419, 0, 0, 0, 0, 0x5BC2, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BC3, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BC4, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BC5, 0, 329, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x5BC6, 0, 329, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BC7, 0, 329, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BC8, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BC9, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BB8, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 chun_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_019[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BC0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 419, 0, 0, 0, 0, 0x5BC1, 0, 327, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BC2, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BC3, 0, 328, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x5BC4, 0, 328, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x5BC5, 0, 329, 0, 0, 0, 0, 0),
    L4(7, 10, 0, 0, 0, 0, 0, 0x5BC6, 0, 329, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x5BC7, 0, 330, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BC8, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BC9, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BB8, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 chun_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_022[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BA0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 135, 419, 0, 0, 0, 0, 0x5BA1, 0, 323, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BA2, 0, 324, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5BA3, 0, 325, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BA4, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BA5, 0, 323, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BE3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BE4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 chun_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_025[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BD0, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 136, 418, 0, 0, 0, 0, 0x5BD1, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BD2, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BD3, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BD4, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BD5, 0, 331, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5BD6, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A04, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 chun_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_026[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BD2, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 135, 418, 0, 0, 0, 0, 0x5BD3, 0, 332, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BD4, 0, 333, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BD5, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BD6, 0, 331, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A03, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A04, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 chun_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 418, 0, 0, 0, 0, 0x5BE1, 0, 331, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BE2, 0, 331, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BE3, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5BE4, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 chun_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BF0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 418, 0, 0, 0, 0, 0x5BF1, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BF2, 0, 331, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BF3, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BF4, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5BF5, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5BE4, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 chun_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_030[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BE2, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 139, 419, 0, 0, 0, 0, 0x5C00, 0, 332, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C01, 0, 333, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 14, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C02, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C03, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C04, 0, 331, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C05, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C06, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C07, 0, 332, 0, 0, 0, 32, 1),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B95, 0, 333, 0, 0, 0, 32, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B96, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 chun_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 0, 0, 0, 0, 0, 0x5CE0, 0, 331, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B90, 0, 332, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B91, 0, 333, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B92, 0, 334, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5B93, 0, 334, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B94, 0, 333, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B95, 0, 331, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5B96, 0, 331, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 chun_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CA0, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5CA1, 0, 336, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 chun_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_048[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CB0, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 135, 418, 0, 0, 0, 0, 0x5CB1, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB3, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 chun_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_049[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CB6, 0, 335, 0, 0, 0, 0, 0),
    L4(3, 136, 418, 0, 0, 0, 0, 0x5CB7, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB8, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB9, 0, 336, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB3, 0, 335, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 chun_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_050[124] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x5CBA, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5CBB, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 138, 0, 0, 0, 0, 0, 0x5CBC, 0, 337, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CBD, 0, 338, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CBE, 0, 338, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CBF, 0, 337, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CC0, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB9, 0, 336, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB3, 0, 335, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 chun_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 132, 0, 0, 0, 0, 0, 0x5CB6, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 0, 419, 0, 0, 0, 0, 0x5CB7, 0, 336, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 chun_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_060[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CF0, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5CF1, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5CF0, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C83, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C59, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C5C, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C5D, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5E, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 chun_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 chun_dmca_064[236] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D02, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D03, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D04, 0, 377, 0, 0, 0, 30, 118),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D05, 0, 377, 0, 0, 0, 30, 119),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D06, 0, 377, 0, 0, 0, 30, 120),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D07, 0, 377, 0, 0, 0, 30, 121),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D08, 0, 377, 0, 0, 0, 30, 122),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D09, 0, 377, 0, 0, 0, 30, 123),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D0A, 0, 377, 0, 0, 0, 30, 124),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0B, 0, 377, 0, 0, 0, 30, 125),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5D0C, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0D, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(2, 12, 0, 0, 0, 0, 0, 0x5D0E, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5D0F, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D10, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D11, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D12, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5D13, 0, 0, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D14, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D15, 0, 1, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 chun_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 chun_dmca_065[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5D00, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D20, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D22, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D23, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D24, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D25, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D26, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D27, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D28, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5D29, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5D2A, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5A70, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5A71, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5A72, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 chun_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 chun_dmca_066[140] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5D00, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D20, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D28, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5D2A, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5A70, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5A71, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5A72, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 chun_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 chun_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_068[232] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C11, 0, 497, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C12, 0, 497, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x5C13, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C14, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C15, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C16, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C17, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x5C18, 0, 497, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x5C19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C1A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x5C37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C5B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C5E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 chun_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_070[164] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C60, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C61, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C62, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C63, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C64, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C65, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C66, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C67, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C68, 0, 504, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C69, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C68, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C67, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C66, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C65, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C64, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C63, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C62, 0, 505, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C61, 0, 505, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 chun_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_071[140] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D20, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D22, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D23, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D24, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D25, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D26, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D27, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D28, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x5D29, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5D2A, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5A72, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 chun_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_072[124] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D20, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D28, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2B, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2C, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2D, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2E, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5D2F, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x5D2A, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A72, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 chun_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_073[156] = {
    L4(2, 0, 419, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C10, 0, 497, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C11, 0, 497, 0, 0, 0, 32, 100),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C12, 0, 497, 0, 0, 0, 32, 101),
    L4(3, 0, 289, 0, 0, 0, 0, 0x5C13, 0, 497, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C14, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C15, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C16, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C17, 0, 0, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x5C18, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C19, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C1A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 288, 0, 0, 0, 0, 0x5C37, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C5B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5C5D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5C5E, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 chun_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B70, 0, 327, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5B70, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 chun_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5B80, 0, 327, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5B80, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B73, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 chun_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5BB0, 0, 327, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BB0, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5B71, 0, 327, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B72, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 chun_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CB1, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CB1, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 chun_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CB6, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CB6, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 chun_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5CBA, 0, 335, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CBA, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5CB9, 0, 336, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5CB2, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5CB3, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5CB3, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 chun_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_082[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x5C6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C6C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 chun_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_083[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x5C6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C6C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 chun_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_dmca_084[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x5C6A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C6C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 chun_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 chun_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C90, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B46, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5B4B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B52, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5B53, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B46, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B47, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5B48, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B49, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5B4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 chun_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 chun_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AEE, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AED, 0, 377, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5B40, 0, 377, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5B41, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5B52, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5B4C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5B4B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B46, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B47, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5B48, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B49, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5B4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 chun_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_096[44] = {
    L4(3, 2, 419, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 chun_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_dmca_097[44] = {
    L4(3, 2, 419, 0, 0, 0, 0, 0x5C39, 0, 378, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C39, 0, 378, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C39, 0, 378, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 378, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 378, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const chun_btca[37] = {
    chun_btca_000,  /* 0 AIR NORMAL */
    chun_btca_001,  /* 1 ASIBARAI SIRI */
    chun_btca_002,  /* 2 ASIB TUNNOMERI */
    chun_btca_003,  /* 3 NOKEZORI */
    chun_btca_004,  /* 4 KUNOJI */
    chun_btca_005,  /* 5 KIRIMOMI */
    chun_btca_006,  /* 6 UPPER */
    chun_btca_007,  /* 7 BODY UPPER */
    chun_btca_008,  /* 8 HARAYARARE */
    chun_btca_009,  /* 9 TATAKI AIR */
    chun_btca_010,  /* 10 TTKI V. AIR */
    chun_btca_011,  /* 11 HUMI ASIB */
    chun_btca_012,  /* 12 FACE */
    chun_btca_013,  /* 13 ASIB SIRI LOSE */
    chun_btca_014,  /* 14 ASIB TUN LOSE */
    chun_btca_015,  /* 15 DENKI */
    chun_btca_016,  /* 16 KUNOJI NOKE */
    chun_btca_017,  /* 17 BODY UPPER SP */
    chun_btca_018,  /* 18 HANEAGARI */
    chun_btca_019,  /* 19 TOUKETSU A */
    chun_btca_020,  /* 20 BODY SLAM */
    chun_btca_021,  /* 21 IPPONZEOI */
    chun_btca_022,  /* 22 TOMOE RYU */
    chun_btca_023,  /* 23 MONKEY FLIP */
    chun_btca_024,  /* 24 TOMOE ORO */
    chun_btca_025,  /* 25 SNAKE FANG */
    chun_btca_026,  /* 26 FLANKEN.S */
    chun_btca_027,  /* 27 KISHINRIKI */
    chun_btca_028,  /* 28 SPLASH.M */
    chun_btca_029,  /* 29 HARAIGOSHI */
    chun_btca_030,  /* 30 ALEX B.D */
    chun_btca_031,  /* 31 GILL */
    chun_btca_032,  /* 32 HANEKAERI HARA */
    chun_btca_033,  /* 33 S HANEAGARI */
    chun_btca_034,  /* 34 TATUMAKIZANKU */
    chun_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 chun_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_000[68] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BA0, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 418, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x5BA0, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x5DB0, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 chun_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5C40, 0, 450, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 11, 0x5C41, 0, 451, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x5C42, 0, 451, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x5C43, 0, 452, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x5C44, 0, 453, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 chun_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_btca_002[52] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5C90, 0, 454, 0, 0, 0, 0, 0),
    L4(3, 0, 418, 0, 0, 0, 0, 0x5C91, 0, 455, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5C92, 0, 456, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C93, 0, 457, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 chun_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_003[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5B90, 0, 458, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 chun_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_004[60] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BE2, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 419, 0, 0, 0, 0, 0x5C50, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C51, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C52, 0, 470, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C53, 0, 471, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 chun_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_005[156] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BC0, 0, 472, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5C70, 0, 472, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C71, 0, 473, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C72, 0, 473, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C73, 0, 473, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C74, 0, 473, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C75, 0, 473, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C76, 0, 474, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C77, 0, 475, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C78, 0, 475, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C79, 0, 475, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C7A, 0, 476, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C7B, 0, 476, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C7C, 0, 477, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C7D, 0, 477, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C7E, 0, 478, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C7E, 0, 478, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 chun_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_006[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BA0, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5CD0, 0, 479, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5CD1, 0, 480, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CD2, 0, 481, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 chun_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_007[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CE0, 0, 482, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5CE1, 0, 483, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5CE2, 0, 484, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5CE3, 0, 485, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 chun_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_008[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BA4, 0, 486, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 chun_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_009[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 419, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 chun_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_010[44] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5CA0, 0, 487, 0, 0, 0, 0, 0),
    L4(5, 0, 419, 0, 0, 0, 0, 0x5CA1, 0, 488, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5CA2, 0, 489, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 chun_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 chun_btca_011[52] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5C90, 0, 454, 0, 0, 0, 0, 0),
    L4(3, 0, 418, 0, 0, 0, 0, 0x5C91, 0, 455, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C92, 0, 456, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C93, 0, 457, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 chun_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_012[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5B90, 0, 458, 0, 0, 0, 0, 0),
    L4(4, 0, 418, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 chun_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 chun_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 chun_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_015[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(3, 134, 0, 0, 0, 0, 0, 0x5C6A, 0, 490, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C6B, 0, 490, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C6C, 0, 490, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 419, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 chun_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_016[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BE2, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 418, 0, 0, 0, 0, 0x5C50, 0, 468, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C51, 0, 469, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C52, 0, 470, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 chun_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_017[160] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x5CD1, 0, 480, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 418, 0, 0, 0, 0, 0x5CD2, 0, 481, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 chun_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_018[188] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(3, 0, 418, 0, 0, 0, 0, 0x5C29, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C2A, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C2B, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5C2C, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C2D, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C2E, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 2, 285, 0, 0, 0, 0, 0x5C2F, 0, 376, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C30, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5C31, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C32, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x5C33, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C35, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C33, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C35, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C36, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C37, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 chun_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BD0, 0, 491, 0, 0, 0, 0, 0),
    L4(250, 0, 418, 0, 0, 0, 0, 0x5BD0, 0, 491, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 chun_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C2B, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 chun_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C81, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 chun_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_022[36] = {
    CMD(CM_RJA, 7, 10, 3), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x5C2C, 0, 374, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5CF1, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 chun_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x5C2D, 0, 374, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5C2C, 0, 374, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5CF1, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 chun_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_btca_024[44] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 1, 0, 0, 0x5D0D, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C93, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C93, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 chun_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_025[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 chun_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_026[44] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C90, 0, 374, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C91, 0, 374, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C92, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C93, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 chun_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_027[44] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 15, 0x5C52, 0, 374, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 15, 0x5C53, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x5C54, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 chun_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_028[52] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C2C, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C2D, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C2E, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C2F, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 chun_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 chun_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 10, 0x5C25, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5C26, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 chun_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 11, 0x5C41, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 13, 0x5C42, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x5C43, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x5C44, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 chun_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x5BA0, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5B90, 0, 458, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 chun_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_033[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x5C30, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 4), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C30, 0, 376, 0, 0, 0, 0, 0),
    L4(4, 2, 418, 0, 0, 0, 0, 0x5C31, 0, 376, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C32, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 5, 285, 0, 0, 0, 0, 0x5C33, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 5, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C35, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C33, 0, 376, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C34, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C35, 0, 376, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C36, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C37, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 376, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 376, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 chun_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_btca_034[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x5BA0, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 419, 0, 0, 0, 0, 0x5CD0, 0, 479, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5CD1, 0, 480, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CD2, 0, 481, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C20, 0, 459, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C21, 0, 459, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5C22, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C23, 0, 461, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C24, 0, 462, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C25, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C26, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C27, 0, 465, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5C28, 0, 466, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 10 entries */
const u16* const chun_caca[11] = {
    chun_caca_000,  /* 0 CATCH 1 */
    chun_caca_000,  /* 1 CATCH 2 */
    chun_caca_000,  /* 2 CATCH 3 */
    chun_caca_000,  /* 3 CATCH 4 */
    chun_caca_004,  /* 4 CATCH 5 */
    chun_caca_004,  /* 5 CATCH 6 */
    chun_caca_004,  /* 6 CATCH 7 */
    chun_caca_004,  /* 7 CATCH 8 */
    chun_caca_008,  /* 8 CATCH 9 */
    chun_caca_009,  /* 9 CATCH 10 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 chun_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 chun_caca_000[292] = {
    CMD(CM_NGDA, 1542, 59, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F50, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F51, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(3, 0, 277, 0, 0, 0, 0, 0x5F52, 0, 0, 0, 0, 0, 0, 0, 0, 72, 172, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F53, 0, 0, 0, 0, 0, 0, 0, 0, 96, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F54, 0, 0, 0, 0, 0, 0, 0, 0, 120, 176, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F55, 0, 0, 0, 0, 0, 0, 0, 0, 144, 178, 0, 0),
    L6(5, 0, 264, 0, 0, 46, 0, 0x5F56, 0, 0, 0, 0, 0, 0, 0, 0, 168, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 47, 0, 0x5F57, 0, 0, 0, 0, 0, 0, 0, 0, 192, 182, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5F58, 0, 0, 0, 0, 0, 0, 0, 0, 216, 184, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5F59, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(4, 2, 421, 0, 0, 0, 0, 0x5F5A, -41, 0, 0, 0, 0, 0, 0, 0, 264, 186, 0, 0),
    L6(4, 9, 270, 0, 0, 0, 0, 0x5F5B, 0, 1, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F5C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F5D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F5E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F5F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F60, 0, 1, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F61, 0, 1, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F62, 0, 1, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F63, 0, 1, 0, 0, 0, 0, 0, 0, 0, 196, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 chun_caca_004_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 chun_caca_004[112] = {
    CMD(CM_NGDA, 1542, 59, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F50, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F51, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(3, 0, 277, 0, 0, 0, 0, 0x5F52, 0, 0, 0, 0, 0, 0, 0, 0, 72, 172, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F53, 0, 0, 0, 0, 0, 0, 0, 0, 96, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F54, 0, 0, 0, 0, 0, 0, 0, 0, 120, 176, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F55, 0, 0, 0, 0, 0, 0, 0, 0, 144, 178, 0, 0),
    L6(5, 6, 264, 0, 0, 46, 0, 0x5F56, 0, 0, 0, 0, 0, 0, 0, 0, 168, 180, 0, 0),
    CMD(CM_JMP, 2, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 chun_caca_008_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 chun_caca_008[292] = {
    CMD(CM_NGDA, 1542, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F70, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F71, 0, 0, 0, 0, 0, 0, 0, 0, 336, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F72, 0, 0, 0, 0, 0, 0, 0, 0, 360, 176, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F73, 0, 0, 0, 0, 0, 0, 0, 0, 384, 178, 0, 0),
    L6(4, 0, 264, 0, 0, 48, 0, 0x5F74, 0, 0, 0, 0, 0, 0, 0, 0, 408, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 49, 0, 0x5F75, 0, 0, 0, 0, 0, 0, 0, 0, 432, 182, 0, 0),
    L6(5, 2, 0, 0, 0, 0, 0, 0x5F76, -43, 0, 0, 0, 0, 0, 0, 0, 456, 184, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F77, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(3, 0, 421, 0, 0, 0, 0, 0x5F78, 0, 0, 0, 0, 0, 0, 0, 0, 504, 186, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x5F79, 0, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0),
    CMD(CM_S123, 0, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SPS, 0, 0, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MXYT, 30, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 1, 0, 0, 0, 0, 0, 0x5F7A, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5F7B, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 chun_caca_009_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 chun_caca_009[100] = {
    CMD(CM_NGDA, 1542, 61, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F70, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F71, 0, 0, 0, 0, 0, 0, 0, 0, 336, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F72, 0, 0, 0, 0, 0, 0, 0, 0, 360, 176, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F73, 0, 0, 0, 0, 0, 0, 0, 0, 384, 178, 0, 0),
    L6(4, 6, 264, 0, 0, 48, 0, 0x5F74, 0, 0, 0, 0, 0, 0, 0, 0, 408, 180, 0, 0),
    CMD(CM_JMP, 2, 8, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const chun_cuca[69] = {
    chun_cuca_000,  /* 0 ALEX ZUTUKI */
    chun_cuca_001,  /* 1 ALEX BODY S */
    chun_cuca_002,  /* 2 ALEX BACK D */
    chun_cuca_003,  /* 3 ALEX POWER B */
    chun_cuca_004,  /* 4 ALEX SLEEPER */
    chun_cuca_005,  /* 5 RYU SEOINAGE */
    chun_cuca_006,  /* 6 IBUKI */
    chun_cuca_007,  /* 7 DADLEY L B */
    chun_cuca_008,  /* 8 IBUKI KUBIORI */
    chun_cuca_009,  /* 9 NECRO S T */
    chun_cuca_010,  /* 10 RYU TOMOENAGE */
    chun_cuca_011,  /* 11 YUN HIZAGERI */
    chun_cuca_012,  /* 12 ORO KUBISIME */
    chun_cuca_013,  /* 13 NECRO G S */
    chun_cuca_014,  /* 14 DUDDLEY D S */
    chun_cuca_015,  /* 15 YUN MONKEY F */
    chun_cuca_016,  /* 16 ORO TOMOENAGE */
    chun_cuca_017,  /* 17 ORO NIOURIKI */
    chun_cuca_018,  /* 18 ORO GIGOKU G */
    chun_cuca_019,  /* 19 YUN */
    chun_cuca_020,  /* 20 NECRO SNAKE F */
    chun_cuca_021,  /* 21 NECRO F S */
    chun_cuca_022,  /* 22 IBUKI HARAIG */
    chun_cuca_023,  /* 23 GILL SPLASH M */
    chun_cuca_024,  /* 24 KEN HIZAGERI */
    chun_cuca_025,  /* 25 ORO KISINRIKI */
    chun_cuca_026,  /* 26 SEAN TACKLE */
    chun_cuca_027,  /* 27 ALEX HYPER B */
    chun_cuca_028,  /* 28 NECRO SLAM D */
    chun_cuca_029,  /* 29 ELENA ASINAGE */
    chun_cuca_030,  /* 30 GILL IMPACT C */
    chun_cuca_031,  /* 31 ALEX S H B */
    chun_cuca_032,  /* 32 ALEX F N D */
    chun_cuca_033,  /* 33 no name */
    chun_cuca_034,  /* 34 IBUKI */
    chun_cuca_035,  /* 35 IBUKI YOROI D */
    chun_cuca_036,  /* 36 no name */
    chun_cuca_037,  /* 37 MAWARIKOMI M F */
    chun_cuca_038,  /* 38 HUGO BODY S */
    chun_cuca_039,  /* 39 HUGO N G T */
    chun_cuca_040,  /* 40 HUGO M S P */
    chun_cuca_041,  /* 41 HUGO S D B B */
    chun_cuca_042,  /* 42 no name */
    chun_cuca_043,  /* 43 no name */
    chun_cuca_044,  /* 44 no name */
    chun_cuca_045,  /* 45 no name */
    chun_cuca_046,  /* 46 no name */
    chun_cuca_047,  /* 47 no name */
    chun_cuca_048,  /* 48 no name */
    chun_cuca_049,  /* 49 no name */
    chun_cuca_050,  /* 50 no name */
    chun_cuca_051,  /* 51 no name */
    chun_cuca_052,  /* 52 no name */
    chun_cuca_053,  /* 53 no name */
    chun_cuca_054,  /* 54 no name */
    chun_cuca_055,  /* 55 no name */
    chun_cuca_056,  /* 56 no name */
    chun_cuca_057,  /* 57 no name */
    chun_cuca_058,  /* 58 no name */
    chun_cuca_059,  /* 59 no name */
    chun_cuca_060,  /* 60 no name */
    chun_cuca_061,  /* 61 no name */
    chun_cuca_062,  /* 62 no name */
    chun_cuca_063,  /* 63 no name */
    chun_cuca_064,  /* 64 no name */
    chun_cuca_065,  /* 65 no name */
    chun_cuca_066,  /* 66 no name */
    chun_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 chun_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BE2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 chun_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C50),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C04),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 chun_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_002[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 2, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 9, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 chun_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_003[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CF1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2A),
    CMD(CM_RMJA, 3, 3, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 chun_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_004[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BF0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD1),
    CMD(CM_RMJA, 3, 4, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5BD0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 chun_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5BC3),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C81),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 chun_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D55),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D54),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D55),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 9, 0x5BA0),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 chun_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C50),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C51),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 chun_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF0),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BF2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 chun_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_009[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B81),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5B90),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 chun_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B49),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CF0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C43),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 chun_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BF0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 chun_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5BA4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 chun_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C44),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 chun_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C01),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 chun_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C92),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2D),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 chun_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C93),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C93),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5D0D),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 chun_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_017[108] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C54),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C54),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 chun_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 3, 0, 0, 0, 0, 0, 0x5CA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C83),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 chun_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B93),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5B94),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 chun_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5AF0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5AF1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5AF2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5AF3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5AF4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B81),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C26),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C25),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C24),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 chun_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C90),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 chun_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B92),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C25),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C27),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 chun_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 chun_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_024[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    CMD(CM_RMJA, 3, 24, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 chun_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_025[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C54),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C54),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C7E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 chun_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2F),
    L2(250, 3, 0, 0, 0, 0, 0, 0x5C30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C31),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C32),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C33),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C34),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C37),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C38),
    L2(250, 3, 0, 0, 0, 0, 0, 0x5C81),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5CA5),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 chun_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CF1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 chun_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C44),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C50),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C50),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C52),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 chun_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C93),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 chun_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD0),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5CD0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 chun_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BE2),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 chun_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C54),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C55),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CF1),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5CF1),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 chun_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_033[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C80),
    CMD(CM_RMJA, 3, 33, 14),
    L2(250, 9, 0, 0, 0, 0, 10, 0x5C25),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 chun_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C52),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD2),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5CD2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 chun_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D55),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D54),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D55),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BA0),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 chun_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B49),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5BA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B91),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5A),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C59),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 chun_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5ABD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5ABC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5ABB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5B02),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5ABE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5ABF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x5AC0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 chun_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5CE0),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 chun_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 chun_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B60),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B63),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B63),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C73),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C7B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5D),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C5D),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 chun_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C22),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 chun_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C50),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C50),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 chun_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C39),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C39),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 28, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 chun_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B60),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B63),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B42),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B63),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C73),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C7B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C21),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C23),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C58),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C7E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2D),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5AF6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 chun_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BE1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 chun_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B35),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C73),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C7B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C21),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C7B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C24),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5B36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5AEF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5B03),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 chun_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_047[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 47, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 9, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 chun_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B81),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BD1),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 chun_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C92),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C29),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C29),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 chun_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C27),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C25),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C20),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C53),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C54),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2D),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 chun_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B4B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C61),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BA4),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 chun_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B49),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5D6A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5B91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C57),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C2E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C43),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 chun_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C26),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C53),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CF1),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5CF1),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 chun_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C75),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5CD0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 chun_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C40),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C26),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C28),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5CD1),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5AE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 chun_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x5C40),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 11, 0x5C41),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 chun_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C01),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 chun_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5A72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C41),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C20),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 chun_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B6A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B69),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B68),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C53),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 chun_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B73),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B72),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5BA4),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 chun_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5EB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5EAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5EA9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5EA8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5CD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C22),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C42),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C53),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 chun_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC8),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BC9),
    CMD(CM_PA_X, 0, -1024, 0),
    CMD(CM_PS_Y, 0, 0, 7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BA0),
    CMD(CM_PA_X, 0, -10240, 0),
    CMD(CM_PS_Y, 0, 0, 59),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 118),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5C2E),
    CMD(CM_PA_X, 0, 2304, 0),
    CMD(CM_PS_Y, 0, 0, 112),
    L2(250, 0, 0, 0, 2, 0, 0, 0x5CD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5C2B),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C29),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 9, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 chun_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 419, 0, 0, 0, 0, 0x5C50),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 chun_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B70),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C02),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C03),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 chun_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BB3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x5BB5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C92),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C2D),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 chun_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B71),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C59),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C5D),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C5D),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 chun_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5BD5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5B91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x5C21),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x5C52),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 159 entries */
const u16* const chun_atca[160] = {
    chun_atca_000,  /* 0 S PUNCH A */
    chun_atca_001,  /* 1 S PUNCH B */
    chun_atca_001,  /* 2 S PUNCH C */
    chun_atca_003,  /* 3 M PUNCH A */
    chun_atca_003,  /* 4 M PUNCH B */
    chun_atca_005,  /* 5 M PUNCH C */
    chun_atca_006,  /* 6 L PUNCH A */
    chun_atca_006,  /* 7 L PUNCH B */
    chun_atca_008,  /* 8 L PUNCH C */
    chun_atca_009,  /* 9 S KICK A */
    chun_atca_009,  /* 10 S KICK B */
    chun_atca_009,  /* 11 S KICK C */
    chun_atca_012,  /* 12 M KICK A */
    chun_atca_013,  /* 13 M KICK B */
    chun_atca_014,  /* 14 M KICK C */
    chun_atca_015,  /* 15 L KICK A */
    chun_atca_016,  /* 16 L KICK B */
    chun_atca_016,  /* 17 L KICK C */
    chun_atca_018,  /* 18 KAGAMI P A */
    chun_atca_018,  /* 19 KAGAMI P B */
    chun_atca_018,  /* 20 KAGAMI P C */
    chun_atca_021,  /* 21 KAGAMI P A */
    chun_atca_021,  /* 22 KAGAMI P B */
    chun_atca_021,  /* 23 KAGAMI P C */
    chun_atca_024,  /* 24 KAGAMI P A */
    chun_atca_024,  /* 25 KAGAMI P B */
    chun_atca_024,  /* 26 KAGAMI P C */
    chun_atca_027,  /* 27 KAGAMI K A */
    chun_atca_027,  /* 28 KAGAMI K B */
    chun_atca_027,  /* 29 KAGAMI K C */
    chun_atca_030,  /* 30 KAGAMI K A */
    chun_atca_030,  /* 31 KAGAMI K B */
    chun_atca_030,  /* 32 KAGAMI K C */
    chun_atca_033,  /* 33 KAGAMI K A */
    chun_atca_033,  /* 34 KAGAMI K B */
    chun_atca_035,  /* 35 KAGAMI K C */
    chun_atca_036,  /* 36 V JUMP P S A */
    chun_atca_036,  /* 37 V JUMP P S B */
    chun_atca_038,  /* 38 V JUMP P M A */
    chun_atca_038,  /* 39 V JUMP P M B */
    chun_atca_040,  /* 40 V JUMP P L A */
    chun_atca_040,  /* 41 V JUMP P L B */
    chun_atca_042,  /* 42 V JUMP K S A */
    chun_atca_042,  /* 43 V JUMP K S B */
    chun_atca_044,  /* 44 V JUMP K M A */
    chun_atca_045,  /* 45 V JUMP K M B */
    chun_atca_046,  /* 46 V JUMP K L A */
    chun_atca_046,  /* 47 V JUMP K L B */
    chun_atca_048,  /* 48 F JUMP P S A */
    chun_atca_048,  /* 49 F JUMP P S B */
    chun_atca_050,  /* 50 F JUMP P M A */
    chun_atca_050,  /* 51 F JUMP P M B */
    chun_atca_052,  /* 52 F JUMP P L A */
    chun_atca_053,  /* 53 F JUMP P L B */
    chun_atca_054,  /* 54 F JUMP K S A */
    chun_atca_054,  /* 55 F JUMP K S B */
    chun_atca_056,  /* 56 F JUMP K M A */
    chun_atca_045,  /* 57 F JUMP K M B */
    chun_atca_058,  /* 58 F JUMP K L A */
    chun_atca_058,  /* 59 F JUMP K L B */
    chun_atca_060,  /* 60 B JUMP P S A */
    chun_atca_060,  /* 61 B JUMP P S B */
    chun_atca_062,  /* 62 B JUMP P M A */
    chun_atca_062,  /* 63 B JUMP P M B */
    chun_atca_064,  /* 64 B JUMP P L A */
    chun_atca_064,  /* 65 B JUMP P L B */
    chun_atca_066,  /* 66 B JUMP K S A */
    chun_atca_066,  /* 67 B JUMP K S B */
    chun_atca_068,  /* 68 B JUMP K M A */
    chun_atca_045,  /* 69 B JUMP K M B */
    chun_atca_070,  /* 70 B JUMP K L A */
    chun_atca_070,  /* 71 B JUMP K L B */
    chun_atca_072,  /* 72 SP V JP S P A */
    chun_atca_072,  /* 73 SP V JP S P B */
    chun_atca_074,  /* 74 SP V JP M P A */
    chun_atca_074,  /* 75 SP V JP M P B */
    chun_atca_076,  /* 76 SP V JP L P A */
    chun_atca_076,  /* 77 SP V JP L P B */
    chun_atca_078,  /* 78 SP V JP S K A */
    chun_atca_078,  /* 79 SP V JP S K B */
    chun_atca_080,  /* 80 SP V JP M K A */
    chun_atca_045,  /* 81 SP V JP M K B */
    chun_atca_082,  /* 82 SP V JP L K A */
    chun_atca_082,  /* 83 SP V JP L K B */
    chun_atca_084,  /* 84 SP F JP S P A */
    chun_atca_084,  /* 85 SP F JP S P B */
    chun_atca_086,  /* 86 SP F JP M P A */
    chun_atca_086,  /* 87 SP F JP M P B */
    chun_atca_088,  /* 88 SP F JP L P A */
    chun_atca_088,  /* 89 SP F JP L P B */
    chun_atca_090,  /* 90 SP F JP S K A */
    chun_atca_090,  /* 91 SP F JP S K B */
    chun_atca_092,  /* 92 SP F JP M K A */
    chun_atca_045,  /* 93 SP F JP M K B */
    chun_atca_094,  /* 94 SP F JP L K A */
    chun_atca_094,  /* 95 SP F JP L K B */
    chun_atca_096,  /* 96 SP B JP S P A */
    chun_atca_096,  /* 97 SP B JP S P B */
    chun_atca_098,  /* 98 SP B JP M P A */
    chun_atca_098,  /* 99 SP B JP M P B */
    chun_atca_100,  /* 100 SP B JP L P A */
    chun_atca_100,  /* 101 SP B JP L P B */
    chun_atca_102,  /* 102 SP B JP S K A */
    chun_atca_102,  /* 103 SP B JP S K B */
    chun_atca_104,  /* 104 SP B JP M K A */
    chun_atca_045,  /* 105 SP B JP M K B */
    chun_atca_106,  /* 106 SP B JP L K A */
    chun_atca_106,  /* 107 SP B JP L K B */
    chun_atca_108,  /* 108 S V JP S P A */
    chun_atca_108,  /* 109 S V JP S P B */
    chun_atca_108,  /* 110 S V JP M P A */
    chun_atca_108,  /* 111 S V JP M P B */
    chun_atca_108,  /* 112 S V JP L P A */
    chun_atca_108,  /* 113 S V JP L P B */
    chun_atca_108,  /* 114 S V JP S K A */
    chun_atca_108,  /* 115 S V JP S K B */
    chun_atca_108,  /* 116 S V JP M K A */
    chun_atca_108,  /* 117 S V JP M K B */
    chun_atca_108,  /* 118 S V JP L K A */
    chun_atca_108,  /* 119 S V JP L K B */
    chun_atca_108,  /* 120 S F JP S P A */
    chun_atca_108,  /* 121 S F JP S P B */
    chun_atca_108,  /* 122 S F JP M P A */
    chun_atca_108,  /* 123 S F JP M P B */
    chun_atca_108,  /* 124 S F JP L P A */
    chun_atca_108,  /* 125 S F JP L P B */
    chun_atca_108,  /* 126 S F JP S K A */
    chun_atca_108,  /* 127 S F JP S K B */
    chun_atca_108,  /* 128 S F JP M K A */
    chun_atca_108,  /* 129 S F JP M K B */
    chun_atca_108,  /* 130 S F JP L K A */
    chun_atca_108,  /* 131 S F JP L K B */
    chun_atca_108,  /* 132 S B JP S P A */
    chun_atca_108,  /* 133 S B JP S P B */
    chun_atca_108,  /* 134 S B JP M P A */
    chun_atca_108,  /* 135 S B JP M P B */
    chun_atca_108,  /* 136 S B JP L P A */
    chun_atca_108,  /* 137 S B JP L P B */
    chun_atca_108,  /* 138 S B JP S K A */
    chun_atca_108,  /* 139 S B JP S K B */
    chun_atca_108,  /* 140 S B JP M K A */
    chun_atca_108,  /* 141 S B JP M K B */
    chun_atca_108,  /* 142 S B JP L K A */
    chun_atca_108,  /* 143 S B JP L K B */
    chun_atca_144,  /* 144 TUKAMIKAKARI A */
    chun_atca_144,  /* 145 TUKAMIKAKARI B */
    chun_atca_146,  /* 146 TUKAMIKAKARI C */
    chun_atca_144,  /* 147 TUKAMIKAKARI D */
    chun_atca_144,  /* 148 TUKAMIKAKARI E */
    chun_atca_144,  /* 149 TUKAMIKAKARI F */
    chun_atca_150,  /* 150 TUKAMI AIR A */
    chun_atca_150,  /* 151 TUKAMI AIR B */
    chun_atca_152,  /* 152 TUKAMI AIR C */
    chun_atca_150,  /* 153 TUKAMI AIR D */
    chun_atca_150,  /* 154 TUKAMI AIR E */
    chun_atca_150,  /* 155 TUKAMI AIR F */
    chun_atca_156,  /* 156 follow-up of M KICK A */
    chun_atca_157,  /* 157 no name */
    chun_atca_158,  /* 158 no name */
    0
};

/* script: 0 S PUNCH A */
const u16 chun_atca_000_head[4] = { HEAD(4, 0, 0, 7, 0, 1, 0) };
const u16 chun_atca_000[84] = {
    L4(2, 0, 268, 0, 0, 0, 0, 0x5D80, 0, 3, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D81, -3, 4, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D82, 0, 5, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D83, 0, 6, 0, 0, 96, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D84, 0, 7, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D85, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 chun_atca_001_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 chun_atca_001[76] = {
    L4(3, 0, 268, 0, 0, 0, 0, 0x5D40, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 0, 0x5D40, 0, 8, 272, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D41, -4, 9, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D42, 0, 10, 272, 0, 104, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D43, 0, 10, 272, 0, 104, 0, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D44, 0, 8, 272, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D44, 0, 8, 272, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D44, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 chun_atca_003_head[4] = { HEAD(6, 0, 2, 11, 0, 1, 0) };
const u16 chun_atca_003[148] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D50, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x5D51, 0, 26, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(2, 0, 424, 0, 0, 0, 0, 0x5D52, -7, 27, 0, 128, 96, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D53, 0, 28, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D54, 0, 28, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D55, 0, 29, 0, 0, 0, 21, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D56, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 chun_atca_005_head[4] = { HEAD(6, 0, 2, 9, 0, 2, 0) };
const u16 chun_atca_005[244] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D90, 0, 11, 0, 0, 0, 0, 0, 0, 0, 306, 0, 0),
    L6(2, 0, 422, 0, 0, 0, 0, 0x5D91, 0, 12, 0, 0, 0, 0, 0, 0, 0, 308, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x5D92, 0, 13, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D93, -5, 14, 0, 134, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D94, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D95, 0, 15, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D96, 0, 16, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D97, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 422, 0, 0, 0, 0, 0x5D98, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D99, -6, 19, 0, 128, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D9A, 0, 20, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D9B, 0, 21, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D9C, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D9D, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D9E, 0, 24, 0, 0, 0, 0, 0, 0, 0, 312, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 314, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B */
const u16 chun_atca_006_head[4] = { HEAD(6, 0, 4, 13, 0, 1, 0) };
const u16 chun_atca_006[220] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D60, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D61, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 420, 0, 0, 0, 0, 0x5D62, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5D63, 0, 44, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D64, -9, 45, 0, 128, 0, 0, 0, 0, 0, 22, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D65, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D66, 0, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D67, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D68, 0, 49, 0, 0, 0, 21, 0, 0, 0, 24, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D69, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D6A, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D6B, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D6C, 0, 53, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 chun_atca_008_head[4] = { HEAD(6, 0, 4, 10, 0, 1, 0) };
const u16 chun_atca_008[196] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DA0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 421, 0, 0, 0, 0, 0x5DA1, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x5DA2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DA3, 0, 34, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DA4, -8, 35, 0, 128, 96, 0, 0, 0, 0, 14, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DA5, 0, 36, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DA6, 0, 36, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DA6, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DA7, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DA8, 0, 37, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DA9, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DAA, 0, 39, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 40, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5A04, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 chun_atca_009_head[4] = { HEAD(6, 0, 1, 9, 0, 1, 0) };
const u16 chun_atca_009[172] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DF0, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5DF1, 0, 85, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DF2, -1, 86, 0, 135, 0, 0, 0, 0, 0, 108, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DF3, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DF4, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DF5, 0, 88, 0, 0, 0, 21, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DF6, 0, 89, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DF7, 0, 90, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DF8, 0, 91, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5DF8, 0, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 chun_atca_012_head[4] = { HEAD(6, 0, 3, 9, 0, 3, 0) };
const u16 chun_atca_012[340] = {
    CMD(CM_RJA, 4, 156, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E00, 0, 61, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E01, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x5E02, 0, 63, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 422, 0, 0, 0, 0, 0x5E03, 0, 64, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E04, -12, 65, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E05, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E06, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E07, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E08, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E05, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E06, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E07, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E08, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 512, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x5E08, 0, 67, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E09, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E0A, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E0B, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E0C, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E0D, 0, 208, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E01, 0, 209, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B */
const u16 chun_atca_013_head[4] = { HEAD(6, 0, 3, 12, 0, 1, 0) };
const u16 chun_atca_013[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 422, 0, 0, 0, 0, 0x5DD1, 0, 111, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x5DD2, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD3, -15, 113, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD4, 0, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD5, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5DD6, 0, 116, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5DD7, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DD8, 0, 118, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD9, 0, 119, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DDA, 0, 120, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DEB, 0, 121, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5DEC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 chun_atca_014_head[4] = { HEAD(6, 0, 3, 12, 0, 1, 0) };
const u16 chun_atca_014[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B87, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x5DC8, 0, 446, 0, 0, 0, 0, 0, 0, 0, 316, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DC9, 0, 447, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(2, 0, 422, 0, 0, 0, 0, 0x5DCA, 0, 448, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0),
    L6(1, 1, 269, 0, 0, 0, 0, 0x5DCB, 0, 449, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DC1, -115, 54, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DC2, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DC3, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5DC4, 0, 57, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DC5, 0, 58, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DC6, 0, 59, 0, 0, 0, 0, 0, 0, 0, 324, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5DC7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A */
const u16 chun_atca_015_head[4] = { HEAD(6, 0, 5, 7, 0, 1, 0) };
const u16 chun_atca_015[160] = {
    L6(2, 0, 420, 0, 0, 0, 0, 0x5E20, 0, 200, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x5E21, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E22, -16, 202, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E23, 17, 203, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E24, 17, 203, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E25, 0, 204, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E26, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 104, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 L KICK B, 17 L KICK C */
const u16 chun_atca_016_head[4] = { HEAD(4, 0, 5, 14, 0, 1, 0) };
const u16 chun_atca_016[100] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x5DE0, 0, 69, 0, 0, 0, 30, 126),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5DE1, 0, 70, 0, 0, 0, 30, 127),
    L4(3, 0, 424, 0, 0, 0, 0, 0x5DE2, 0, 71, 0, 0, 0, 30, 128),
    L4(2, 0, 270, 0, 0, 0, 0, 0x5DE3, 0, 72, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5DE4, -18, 73, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DE5, 0, 74, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DEE, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DE6, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DE7, 0, 76, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5DE8, 0, 77, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 chun_atca_018_head[4] = { HEAD(4, 32, 0, 10, 0, 1, 0) };
const u16 chun_atca_018[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 214, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 214, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5E31, -19, 215, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E32, 0, 216, 0, 0, 112, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E33, 0, 214, 0, 0, 16, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 16, 0, 3),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 chun_atca_021_head[4] = { HEAD(6, 32, 2, 13, 0, 1, 0) };
const u16 chun_atca_021[160] = {
    L6(3, 0, 269, 0, 0, 0, 0, 0x5E40, 0, 217, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(5, 0, 424, 0, 0, 0, 0, 0x5E41, 0, 218, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E42, -20, 219, 0, 128, 0, 0, 0, 0, 0, 56, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E43, 0, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E44, 0, 506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E45, 0, 221, 0, 0, 0, 21, 0, 0, 0, 58, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E46, 0, 222, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E47, 0, 223, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E48, 0, 224, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 chun_atca_024_head[4] = { HEAD(6, 32, 4, 10, 0, 1, 0) };
const u16 chun_atca_024[184] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E50, 0, 225, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x5E51, 0, 226, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 0, 421, 0, 0, 0, 0, 0x5E52, -21, 227, 0, 134, 96, 0, 0, 0, 0, 142, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E53, 22, 228, 0, 134, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E54, 0, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E54, 0, 228, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E55, 0, 229, 0, 0, 96, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E55, 0, 229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 chun_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 chun_atca_027[116] = {
    L4(4, 0, 268, 0, 0, 0, 0, 0x5E60, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E64, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 268, 0, 0, 0, 0, 0x5E60, 0, 232, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E61, -23, 233, 0, 128, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E62, 0, 234, 0, 0, 16, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E63, 0, 235, 0, 0, 16, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E64, 0, 236, 0, 0, 16, 0, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 214, 0, 0, 16, 0, 3),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 chun_atca_030_head[4] = { HEAD(6, 32, 3, 13, 0, 1, 0) };
const u16 chun_atca_030[148] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E70, 0, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 422, 0, 0, 0, 0, 0x5E71, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x5E72, 0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E73, -24, 240, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E74, 0, 241, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E75, 0, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E76, 0, 243, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E77, 0, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E78, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B */
const u16 chun_atca_033_head[4] = { HEAD(6, 32, 5, 15, 0, 1, 0) };
const u16 chun_atca_033[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B00, 0, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 421, 0, 0, 0, 0, 0x5E80, 0, 247, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x5E81, 0, 248, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E82, -25, 249, 0, 128, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E83, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E84, 0, 251, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E85, 0, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E8A, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E86, 0, 252, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E87, 0, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5E88, 0, 254, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 KAGAMI K C */
const u16 chun_atca_035_head[4] = { HEAD(4, 28, 5, 13, 0, 1, 80) };
const u16 chun_atca_035[164] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 1, 281, 0, 1, 0, 0, 0x5AC0, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 423, 0, 0, 0, 0, 0x5F80, 0, 98, 0, 0, 0, 32, 59),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5F81, 0, 99, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F82, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F83, 0, 101, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F84, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F85, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F86, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F87, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5F88, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F89, 0, 107, 0, 0, 0, 0, 0),
    L4(2, 0, 424, 0, 0, 0, 0, 0x5F89, 0, 107, 0, 0, 0, 33, 0),
    L4(8, 0, 270, 0, 0, 0, 15, 0x5F8A, -2, 108, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 15, 0x5F8B, 0, 109, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x5F8C, 0, 364, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 chun_atca_036_head[4] = { HEAD(4, 22, 0, 9, 0, 1, 0) };
const u16 chun_atca_036[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E90, 0, 80, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5E91, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E92, -26, 82, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E93, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E94, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E95, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E96, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E97, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E98, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E99, 0, 83, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E9A, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E9B, 0, 83, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E9C, 0, 83, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 chun_atca_038_head[4] = { HEAD(4, 22, 2, 9, 0, 1, 0) };
const u16 chun_atca_038[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 422, 0, 0, 0, 0, 0x5E90, 0, 80, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x5E91, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E92, -27, 155, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E93, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E94, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E95, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E96, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E97, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E98, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E99, 0, 156, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E9A, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E9B, 0, 156, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E9C, 0, 156, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 chun_atca_040_head[4] = { HEAD(4, 22, 4, 9, 0, 1, 0) };
const u16 chun_atca_040[196] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5EA0, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5EA1, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x5EA2, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EA3, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EA4, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 422, 0, 0, 0, 6, 0x5EA5, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x5EA6, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5EA7, -28, 164, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5EA8, 0, 165, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5EA9, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAA, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAB, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAC, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAD, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAE, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAF, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB0, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB1, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB2, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB3, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB3, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 chun_atca_042_head[4] = { HEAD(4, 22, 1, 8, 0, 1, 0) };
const u16 chun_atca_042[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x5ED0, 0, 134, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 7, 0x5ED1, 0, 135, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED2, -29, 136, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED3, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED4, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED5, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED6, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED7, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED8, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5ED9, 0, 495, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EDA, 0, 139, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EDB, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EDC, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A */
const u16 chun_atca_044_head[4] = { HEAD(4, 22, 3, 9, 0, 1, 0) };
const u16 chun_atca_044[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 422, 0, 0, 0, 7, 0x5ED0, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 7, 0x5ED1, 0, 135, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x5ED2, -30, 142, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x5ED3, 0, 137, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED4, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED5, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED6, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED7, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED8, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5ED9, 0, 138, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EDA, 0, 139, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5EDB, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EDC, 0, 141, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 chun_atca_046_head[4] = { HEAD(4, 22, 5, 13, 0, 1, 0) };
const u16 chun_atca_046[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x5EE0, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 420, 0, 0, 0, 7, 0x5EE1, 0, 169, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 7, 0x5EE2, 0, 170, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5EE3, 0, 171, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x5EE4, -31, 172, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EE5, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5EE6, 0, 174, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5EE7, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5EE8, 0, 176, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5EE9, 0, 177, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 chun_atca_048_head[4] = { HEAD(4, 20, 0, 9, 0, 1, 0) };
const u16 chun_atca_048[76] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 6, 0x5F0D, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5EC0, -32, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC0, 32, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC1, 32, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC2, 32, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC3, 32, 186, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 chun_atca_050_head[4] = { HEAD(4, 20, 2, 10, 0, 1, 0) };
const u16 chun_atca_050[84] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 422, 0, 0, 0, 6, 0x5F0D, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 6, 0x5F0D, 0, 184, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5EC0, -33, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC0, 33, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC1, 33, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC2, 33, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EC3, 33, 188, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A */
const u16 chun_atca_052_head[4] = { HEAD(4, 20, 4, 13, 0, 1, 0) };
const u16 chun_atca_052[292] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_RMJA, 4, 52, 18), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F0C, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F0D, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 424, 0, 0, 0, 6, 0x5F0E, 0, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 6, 0x5F0F, 0, 192, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F10, -34, 193, 0, 128, 0, 31, 1),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F11, 0, 194, 2112, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F12, 0, 194, 2112, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F13, 0, 194, 2112, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F12, 0, 194, 2112, 0, 8, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F13, 0, 194, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F14, 0, 195, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5F15, 0, 196, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5E90, 0, 80, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F14, 0, 195, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F15, 0, 196, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x5F16, 0, 197, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5F17, -56, 198, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F18, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F19, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F1A, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F1B, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F1C, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F1D, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F1E, 0, 199, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F16, 0, 197, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5B10, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 F JUMP P L B */
const u16 chun_atca_053_head[4] = { HEAD(4, 20, 4, 9, 0, 1, 0) };
const u16 chun_atca_053[196] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5EA0, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5EA1, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x5EA2, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EA3, 0, 160, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EA4, 0, 161, 0, 0, 0, 0, 0),
    L4(1, 0, 422, 0, 0, 0, 6, 0x5EA5, 0, 162, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x5EA6, 0, 163, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5EA7, -119, 164, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5EA8, 0, 165, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5EA9, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAA, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAB, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAC, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAD, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAE, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EAF, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB0, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB1, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB2, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB3, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EB3, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 chun_atca_054_head[4] = { HEAD(4, 20, 1, 15, 0, 1, 0) };
const u16 chun_atca_054[76] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x5EF0, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x5EF1, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 5, 0x5EF5, 0, 442, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x5EF2, -35, 180, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF3, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF4, 0, 181, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A */
const u16 chun_atca_056_head[4] = { HEAD(4, 20, 3, 15, 0, 1, 0) };
const u16 chun_atca_056[116] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 422, 0, 0, 0, 5, 0x5EF0, 0, 178, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x5EF1, 0, 179, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 5, 0x5EF5, 0, 442, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x5EF2, -36, 182, 0, 128, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF3, 0, 183, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF4, 0, 183, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF6, 0, 443, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF7, 0, 444, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x5EF8, 0, 445, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 V JUMP K M B, 57 F JUMP K M B, 69 B JUMP K M B, 81 SP V JP M K B ... */
const u16 chun_atca_045_head[4] = { HEAD(4, 20, 3, 3, 0, 1, 79) };
const u16 chun_atca_045[180] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x5B10, 0, 321, 0, 0, 0, 0, 0),
    L4(3, 1, 422, 0, 0, 0, 0, 0x5B10, 0, 321, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 321, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5F20, -57, 319, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5F21, 0, 319, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5F20, 0, 319, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_SCHY, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_SCHY, 0, 1, 2), 0, 0, 0, 0,
    CMD(CM_SSTY, 0, 3, 1152), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5F21, 0, 320, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5F21, 0, 320, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_S123, 0, 23, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5B10, 0, 321, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 321, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 322, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 322, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 322, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 322, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 chun_atca_058_head[4] = { HEAD(4, 20, 5, 9, 0, 1, 0) };
const u16 chun_atca_058[140] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 6, 0x5F00, 0, 143, 0, 0, 0, 0, 0),
    L4(3, 0, 424, 0, 0, 0, 6, 0x5F01, 0, 144, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x5F02, 0, 145, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F03, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5F04, -37, 147, 0, 137, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x5EFE, 0, 493, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5EFF, 0, 148, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x5F05, 0, 148, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5F06, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5F07, 0, 150, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F08, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F09, 0, 152, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x5F0A, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5F0B, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 chun_atca_060_head[4] = { HEAD(2, 24, 0, 7, 0, 1, 0) };
const u16 chun_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 chun_atca_062_head[4] = { HEAD(2, 24, 2, 8, 0, 2, 0) };
const u16 chun_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 chun_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 chun_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 chun_atca_066_head[4] = { HEAD(2, 24, 1, 6, 0, 1, 0) };
const u16 chun_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A */
const u16 chun_atca_068_head[4] = { HEAD(2, 24, 3, 11, 0, 1, 0) };
const u16 chun_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 chun_atca_070_head[4] = { HEAD(2, 24, 5, 13, 0, 1, 0) };
const u16 chun_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 chun_atca_072_head[4] = { HEAD(2, 28, 0, 7, 0, 1, 0) };
const u16 chun_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 chun_atca_074_head[4] = { HEAD(2, 28, 2, 10, 0, 1, 0) };
const u16 chun_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 chun_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 chun_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 chun_atca_078_head[4] = { HEAD(2, 28, 1, 6, 0, 1, 0) };
const u16 chun_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A */
const u16 chun_atca_080_head[4] = { HEAD(2, 28, 3, 12, 0, 1, 0) };
const u16 chun_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 chun_atca_082_head[4] = { HEAD(2, 28, 5, 10, 0, 1, 0) };
const u16 chun_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 chun_atca_084_head[4] = { HEAD(2, 26, 0, 8, 0, 1, 0) };
const u16 chun_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 chun_atca_086_head[4] = { HEAD(2, 26, 2, 9, 0, 2, 0) };
const u16 chun_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 chun_atca_088_head[4] = { HEAD(2, 26, 4, 12, 0, 1, 0) };
const u16 chun_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 chun_atca_090_head[4] = { HEAD(2, 26, 1, 7, 0, 1, 0) };
const u16 chun_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A */
const u16 chun_atca_092_head[4] = { HEAD(2, 26, 3, 12, 0, 1, 0) };
const u16 chun_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 chun_atca_094_head[4] = { HEAD(2, 26, 5, 13, 0, 1, 0) };
const u16 chun_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 chun_atca_096_head[4] = { HEAD(2, 30, 0, 7, 0, 1, 0) };
const u16 chun_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 chun_atca_098_head[4] = { HEAD(2, 30, 2, 8, 0, 2, 0) };
const u16 chun_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 chun_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 chun_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 chun_atca_102_head[4] = { HEAD(2, 30, 1, 6, 0, 1, 0) };
const u16 chun_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A */
const u16 chun_atca_104_head[4] = { HEAD(2, 30, 3, 11, 0, 1, 0) };
const u16 chun_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 chun_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 chun_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 110 S V JP M P A, 111 S V JP M P B ... */
const u16 chun_atca_108_head[4] = { HEAD(6, 16, 0, 0, 0, 0, 0) };
const u16 chun_atca_108[304] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C65, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x5C66, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C67, -37, 145, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C69, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C6A, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C6B, 0, 11, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C6C, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A56, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A57, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x5A4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E00, 0x0000, 0x0000, 0x0004, 0x0004, 0x0030, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E02, 0x0000, 0x0000, 0x0004, 0x0004, 0x0032, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E04, 0x0000, 0x0000, 0x0004, 0x0004, 0x0034, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E01, 0x0000, 0x0000, 0x0004, 0x0004, 0x0036, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E03, 0x0000, 0x0000, 0x0004, 0x0004, 0x0038, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x0E05, 0x0000, 0x0000, 0x0004, 0x0004, 0x003A, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1200, 0x0000, 0x0000, 0x0004, 0x0004, 0x003C, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1202, 0x0000, 0x0000, 0x0004, 0x0004, 0x003E, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1204, 0x0000, 0x0000, 0x0004, 0x0004, 0x0040, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1201, 0x0000, 0x0000, 0x0004, 0x0004, 0x0042, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1203, 0x0000, 0x0000, 0x0004, 0x0004, 0x0044, 0x0001,
    CMD(CM_ROA, 0, 0, 0), 0x0002, 0x1205, 0x0000, 0x0000, 0x0004, 0x0004, 0x0046, 0x0001,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 chun_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_atca_144[116] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5F30, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5F30, -42, 288, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5F31, 0, 289, 2048, 0, 0, 21, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x5F32, 0, 290, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5F33, 0, 291, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5F34, 0, 291, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5E00, 0, 292, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 chun_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 150 TUKAMI AIR A, 151 TUKAMI AIR B, 153 TUKAMI AIR D, 154 TUKAMI AIR E ... */
const u16 chun_atca_150_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 chun_atca_150[124] = {
    CMD(CM_CAFR, 2, 5, 8), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 5, 8), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 7, 0x5F35, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 7, 0x5F36, 0, 294, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x5F36, -42, 379, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x5F37, 0, 295, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5F38, 0, 296, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x5F39, 0, 296, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 152 TUKAMI AIR C */
const u16 chun_atca_152_head[4] = { HEAD(2, 22, 0, 0, 0, 0, 0) };
const u16 chun_atca_152[16] = {
    CMD(CM_CAFR, 2, 5, 9),
    CMD(CM_CARE, 2, 5, 9),
    CMD(CM_JPSS, 4, 150, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of M KICK A */
const u16 chun_atca_156_head[4] = { HEAD(6, 0, 3, 11, 0, 1, 0) };
const u16 chun_atca_156[76] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5E04, 0, 213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x5E0E, -13, 210, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E0F, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x5E10, -14, 212, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x5E11, 0, 211, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 12, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 no name */
const u16 chun_atca_157_head[4] = { HEAD(6, 0, 2, 11, 0, 1, 0) };
const u16 chun_atca_157[196] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DF5, 0, 88, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DF6, 0, 89, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DF7, 0, 90, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D50, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x5D51, 0, 26, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(2, 0, 424, 0, 0, 0, 0, 0x5D52, -120, 27, 0, 128, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D53, 0, 28, 2560, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D54, 0, 28, 2560, 0, 8, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D55, 0, 29, 0, 0, 0, 21, 0, 0, 0, 8, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D56, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 no name */
const u16 chun_atca_158_head[4] = { HEAD(6, 0, 3, 12, 0, 1, 0) };
const u16 chun_atca_158[232] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D55, 0, 29, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D56, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 422, 0, 0, 0, 0, 0x5DD1, 0, 111, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x5DD2, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5DD3, -121, 113, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD4, 0, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD5, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5DD6, 0, 116, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5DD7, 0, 117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5DD8, 0, 118, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DD9, 0, 119, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DDA, 0, 120, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DEB, 0, 121, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5DEC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5DED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX chun_olc_ix_table[75] = {
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
};

const OVERLAP_PARTS chun_overlap_char_tbl[75] = {
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 0, 0 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 1, 39355 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 2, 39356 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 3, 39357 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 4, 39358 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 5, 39359 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 6, 39360 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 7, 39361 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 8, 39362 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 9, 39363 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 10, 39364 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 11, 39365 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 12, 39366 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 13, 39367 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 14, 39368 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 15, 39369 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 16, 39370 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 17, 39371 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 18, 39372 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 19, 39373 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 20, 39374 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 21, 39375 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 22, 39376 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 23, 39377 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 24, 39378 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 25, 39379 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 26, 39380 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 27, 39381 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 28, 39382 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 29, 39383 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 30, 39384 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 31, 39385 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 32, 39386 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 33, 39387 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 34, 39388 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 35, 39389 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 36, 39390 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 37, 39391 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 38, 39392 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 39, 39393 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 40, 39394 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 41, 39395 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 42, 39396 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 43, 39397 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 44, 39398 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 45, 39399 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 46, 24420 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 47, 24421 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 48, 24444 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 49, 24445 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 50, 39427 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 51, 39428 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 52, 39429 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 53, 39430 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 54, 39431 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 55, 39432 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 56, 39433 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 57, 39434 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 58, 39435 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 59, 39436 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 60, 39437 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 61, 39438 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 62, 39439 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 63, 39440 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 64, 39441 },
    { 0, 0, 0, 4, 2, 0, 255, 0, 0, 65, 39442 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 66, 39443 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 67, 39444 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 68, 39445 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 69, 39446 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 70, 39447 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 71, 39448 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 72, 39449 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 73, 39450 },
    { 0, 0, 0, 4, 1, 0, 255, 0, 0, 74, 39451 },
};

const CatchTable chun_rival_catch_tbl[528] = {
    { -64, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -61, 0, 2, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 1 },
    { -60, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -61, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -62, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 2 },
    { -70, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -61, 0, 2, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -61, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -32, 0, 2, 1, 3 },
    { -38, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -36, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -44, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -24, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -27, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -40, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 3 },
    { -30, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -8, 0, 2, 1, 4 },
    { -14, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -3, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -20, 0, 2, 1, 4 },
    { -3, 0, 2, 1, 4 },
    { -2, 1, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -3, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -16, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 4 },
    { -6, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 2, 0, 2, 1, 5 },
    { -8, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { 3, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { -14, 0, 2, 1, 5 },
    { 4, 0, 2, 1, 5 },
    { 4, 1, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { 3, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { 2, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { -10, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 8, 0, 2, 1, 6 },
    { -2, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 8, 0, 2, 1, 6 },
    { 6, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { -8, 0, 2, 1, 6 },
    { 10, 0, 2, 1, 6 },
    { 10, 1, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 8, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 8, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { -4, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 6 },
    { 6, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 34, -2, 2, 1, 7 },
    { 18, 0, 2, 1, 7 },
    { 34, 0, 2, 1, 7 },
    { 46, 6, 2, 1, 7 },
    { 42, 0, 2, 1, 7 },
    { 64, 0, 2, 1, 7 },
    { 30, 0, 2, 1, 7 },
    { 36, 6, 2, 1, 7 },
    { 30, 1, 2, 1, 7 },
    { 26, 0, 2, 1, 7 },
    { 46, 0, 2, 1, 7 },
    { 34, 0, 2, 1, 7 },
    { 34, 0, 2, 1, 7 },
    { 34, -2, 2, 1, 7 },
    { 34, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 36, 0, 2, 1, 7 },
    { 27, 2, 2, 1, 7 },
    { 24, 2, 2, 1, 7 },
    { 38, 0, 2, 1, 7 },
    { 39, 2, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 42, -4, 2, 1, 8 },
    { 50, 0, 2, 1, 8 },
    { 33, 0, 2, 1, 8 },
    { 48, 8, 2, 1, 8 },
    { 38, 0, 2, 1, 8 },
    { 68, 2, 2, 1, 8 },
    { 30, 4, 2, 1, 8 },
    { 30, 8, 2, 1, 8 },
    { 32, 4, 2, 1, 8 },
    { 42, -4, 2, 1, 8 },
    { 48, 8, 2, 1, 8 },
    { 33, 0, 2, 1, 8 },
    { 33, 0, 2, 1, 8 },
    { 42, -4, 2, 1, 8 },
    { 33, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 36, 0, 2, 1, 8 },
    { 24, 2, 2, 1, 8 },
    { 24, 2, 2, 1, 8 },
    { 36, 2, 2, 1, 8 },
    { 40, -4, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 60, 4, 1, 1, 9 },
    { 48, 0, 1, 1, 9 },
    { 54, 0, 1, 1, 9 },
    { 64, 14, 1, 1, 9 },
    { 44, 0, 1, 1, 9 },
    { 128, 0, 1, 1, 9 },
    { 60, 2, 1, 1, 9 },
    { 28, 12, 1, 1, 9 },
    { 42, 6, 1, 1, 9 },
    { 48, 8, 1, 1, 9 },
    { 64, 14, 1, 1, 9 },
    { 54, 0, 1, 1, 9 },
    { 54, 0, 1, 1, 9 },
    { 60, 4, 1, 1, 9 },
    { 54, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 62, 0, 1, 1, 9 },
    { 32, 6, 1, 1, 9 },
    { 38, 4, 1, 1, 9 },
    { 74, 0, 1, 1, 9 },
    { 28, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 22, -18, 1, 1, 10 },
    { 14, -23, 1, 1, 10 },
    { 38, 2, 1, 1, 10 },
    { 78, 0, 1, 1, 10 },
    { 28, 0, 1, 1, 10 },
    { 138, -2, 1, 1, 10 },
    { 68, 4, 1, 1, 10 },
    { 38, -2, 1, 1, 10 },
    { 42, 8, 1, 1, 10 },
    { 26, 6, 1, 1, 10 },
    { 78, 0, 1, 1, 10 },
    { 38, 2, 1, 1, 10 },
    { 38, 2, 1, 1, 10 },
    { 22, -18, 1, 1, 10 },
    { 38, 2, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 36, 6, 1, 1, 10 },
    { 34, 0, 1, 1, 10 },
    { 24, 10, 1, 1, 10 },
    { 94, -10, 1, 1, 10 },
    { 30, -6, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -24, -14, 1, 1, 11 },
    { -1, 47, 1, 1, 11 },
    { 12, 4, 1, 1, 11 },
    { 30, 10, 1, 1, 11 },
    { 30, 36, 1, 1, 11 },
    { -12, 50, 1, 1, 11 },
    { 30, 20, 1, 1, 11 },
    { -10, 48, 1, 1, 11 },
    { 27, 30, 1, 1, 11 },
    { -22, 38, 1, 1, 11 },
    { 30, 10, 1, 1, 11 },
    { 12, 4, 1, 1, 11 },
    { 12, 4, 1, 1, 11 },
    { -24, -14, 1, 1, 11 },
    { 12, 4, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 4, -6, 1, 1, 11 },
    { 10, 28, 1, 1, 11 },
    { -34, 24, 1, 1, 11 },
    { 36, 0, 1, 1, 11 },
    { -18, 50, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { -40, 0, 1, 1, 12 },
    { -32, 6, 1, 1, 12 },
    { -40, 6, 1, 1, 12 },
    { -40, 4, 1, 1, 12 },
    { -50, 1, 1, 1, 12 },
    { -36, 2, 1, 1, 12 },
    { -30, 2, 1, 1, 12 },
    { -32, 1, 1, 1, 12 },
    { -40, 30, 1, 1, 12 },
    { -44, 10, 1, 1, 12 },
    { -40, 4, 1, 1, 12 },
    { -40, 6, 1, 1, 12 },
    { -40, 6, 1, 1, 12 },
    { -40, 0, 1, 1, 12 },
    { -40, 6, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -56, 28, 1, 1, 12 },
    { -48, 14, 1, 1, 12 },
    { -72, 2, 1, 1, 12 },
    { -36, 2, 1, 1, 12 },
    { -40, 2, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -32, -20, 2, 1, 1 },
    { -51, 0, 2, 1, 1 },
    { -32, 12, 2, 1, 1 },
    { -24, 0, 2, 1, 1 },
    { -36, 0, 2, 1, 1 },
    { -32, -10, 2, 1, 1 },
    { -36, -32, 2, 1, 1 },
    { -32, 0, 2, 1, 1 },
    { -32, -8, 2, 1, 1 },
    { -32, 0, 2, 1, 1 },
    { -24, 0, 2, 1, 1 },
    { -32, 12, 2, 1, 1 },
    { -32, 12, 2, 1, 1 },
    { -32, -20, 2, 1, 1 },
    { -32, 12, 2, 1, 1 },
    { 0, 0, 2, 1, 3 },
    { -32, 0, 2, 1, 1 },
    { -32, -8, 2, 1, 1 },
    { -40, 0, 2, 1, 1 },
    { -24, 0, 2, 1, 1 },
    { -30, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -8, -20, 2, 1, 2 },
    { -27, 0, 2, 1, 2 },
    { -8, 12, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -8, 0, 2, 1, 2 },
    { -8, -10, 2, 1, 2 },
    { -12, -32, 2, 1, 2 },
    { -8, 8, 2, 1, 2 },
    { -8, -8, 2, 1, 2 },
    { -8, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -8, 12, 2, 1, 2 },
    { -8, 12, 2, 1, 2 },
    { -8, -20, 2, 1, 2 },
    { -8, 12, 2, 1, 2 },
    { 0, 0, 2, 1, 4 },
    { -8, 0, 2, 1, 2 },
    { -8, -8, 2, 1, 2 },
    { -14, 4, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -6, 16, 2, 1, 2 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 2, -20, 2, 1, 3 },
    { -21, -4, 2, 1, 3 },
    { -2, 12, 2, 1, 3 },
    { 6, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -2, -10, 2, 1, 3 },
    { -6, -32, 2, 1, 3 },
    { -2, 8, 2, 1, 3 },
    { -2, -8, 2, 1, 3 },
    { -2, 0, 2, 1, 3 },
    { 6, 0, 2, 1, 3 },
    { -2, 12, 2, 1, 3 },
    { -2, 12, 2, 1, 3 },
    { 2, -20, 2, 1, 3 },
    { -2, 12, 2, 1, 3 },
    { 0, 0, 2, 1, 5 },
    { -2, 0, 2, 1, 3 },
    { -2, -8, 2, 1, 3 },
    { -6, 8, 2, 1, 3 },
    { 6, 0, 2, 1, 3 },
    { 0, 16, 2, 1, 3 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 8, -20, 2, 1, 4 },
    { -11, -2, 2, 1, 4 },
    { 6, 12, 2, 1, 4 },
    { 12, 0, 2, 1, 4 },
    { 6, 0, 2, 1, 4 },
    { 4, -10, 2, 1, 4 },
    { 0, -32, 2, 1, 4 },
    { 4, 8, 2, 1, 4 },
    { 4, -8, 2, 1, 4 },
    { 4, 0, 2, 1, 4 },
    { 12, 0, 2, 1, 4 },
    { 6, 12, 2, 1, 4 },
    { 6, 12, 2, 1, 4 },
    { 8, -20, 2, 1, 4 },
    { 6, 12, 2, 1, 4 },
    { 0, 0, 2, 1, 6 },
    { 4, 0, 2, 1, 4 },
    { 4, -8, 2, 1, 4 },
    { 22, 16, 2, 1, 4 },
    { 12, 0, 2, 1, 4 },
    { 6, 16, 2, 1, 4 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 46, -12, 2, 1, 5 },
    { 37, -1, 2, 1, 5 },
    { 36, 12, 2, 1, 5 },
    { 40, 22, 2, 1, 5 },
    { 56, 2, 2, 1, 5 },
    { 38, 26, 2, 1, 5 },
    { 37, -13, 2, 1, 5 },
    { 38, 18, 2, 1, 5 },
    { 54, 10, 2, 1, 5 },
    { 18, 16, 2, 1, 5 },
    { 40, 22, 2, 1, 5 },
    { 36, 12, 2, 1, 5 },
    { 36, 12, 2, 1, 5 },
    { 46, -12, 2, 1, 5 },
    { 36, 12, 2, 1, 5 },
    { 0, 0, 2, 1, 7 },
    { 28, 16, 2, 1, 5 },
    { 26, 24, 2, 1, 5 },
    { 9, 11, 2, 1, 5 },
    { 30, 10, 2, 1, 5 },
    { 42, 8, 2, 1, 5 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 51, -3, 2, 1, 6 },
    { 51, 3, 2, 1, 6 },
    { 48, 6, 2, 1, 6 },
    { 60, 12, 2, 1, 6 },
    { 36, 4, 2, 1, 6 },
    { 48, 22, 2, 1, 6 },
    { 48, -14, 2, 1, 6 },
    { 40, 24, 2, 1, 6 },
    { 76, 28, 2, 1, 6 },
    { 48, 10, 2, 1, 6 },
    { 60, 12, 2, 1, 6 },
    { 48, 6, 2, 1, 6 },
    { 48, 6, 2, 1, 6 },
    { 51, -3, 2, 1, 6 },
    { 48, 6, 2, 1, 6 },
    { 0, 0, 2, 1, 8 },
    { 48, 14, 2, 1, 6 },
    { 30, 20, 2, 1, 6 },
    { 28, 2, 2, 1, 6 },
    { 36, 10, 2, 1, 6 },
    { 28, 9, 2, 1, 6 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 16, -2, 1, 1, 7 },
    { 52, 4, 1, 1, 7 },
    { 36, 32, 1, 1, 7 },
    { 66, 4, 1, 1, 7 },
    { 54, 4, 1, 1, 7 },
    { 44, 24, 1, 1, 7 },
    { 92, 0, 1, 1, 7 },
    { 54, 8, 1, 1, 7 },
    { 82, 40, 1, 1, 7 },
    { 66, 12, 1, 1, 7 },
    { 66, 4, 1, 1, 7 },
    { 36, 32, 1, 1, 7 },
    { 36, 32, 1, 1, 7 },
    { 16, -2, 1, 1, 7 },
    { 36, 32, 1, 1, 7 },
    { 0, 0, 1, 1, 9 },
    { 54, 14, 1, 1, 7 },
    { 64, 38, 1, 1, 7 },
    { 46, -4, 1, 1, 7 },
    { 40, 30, 1, 1, 7 },
    { 38, 4, 1, 1, 7 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 22, -4, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { 54, 50, 1, 1, 8 },
    { 74, 14, 1, 1, 8 },
    { 44, 0, 1, 1, 8 },
    { 70, 6, 1, 1, 8 },
    { 92, 0, 1, 1, 8 },
    { 48, 46, 1, 1, 8 },
    { 70, 54, 1, 1, 8 },
    { 72, 12, 1, 1, 8 },
    { 74, 14, 1, 1, 8 },
    { 54, 50, 1, 1, 8 },
    { 54, 50, 1, 1, 8 },
    { 22, -4, 1, 1, 8 },
    { 54, 50, 1, 1, 8 },
    { 0, 0, 1, 1, 10 },
    { 66, 16, 1, 1, 8 },
    { 66, 32, 1, 1, 8 },
    { 32, 22, 1, 1, 8 },
    { 76, -10, 1, 1, 8 },
    { 46, 58, 1, 1, 8 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -24, 8, 1, 1, 9 },
    { 8, -2, 1, 1, 9 },
    { 12, 34, 1, 1, 9 },
    { 30, 30, 1, 1, 9 },
    { 22, 72, 1, 1, 9 },
    { 10, 44, 1, 1, 9 },
    { 38, 10, 1, 1, 9 },
    { -2, 70, 1, 1, 9 },
    { 24, 52, 1, 1, 9 },
    { 16, 40, 1, 1, 9 },
    { 30, 30, 1, 1, 9 },
    { 12, 34, 1, 1, 9 },
    { 12, 34, 1, 1, 9 },
    { -24, -8, 1, 1, 9 },
    { 12, 34, 1, 1, 9 },
    { 0, 0, 1, 1, 11 },
    { 10, 25, 1, 1, 9 },
    { 8, 48, 1, 1, 9 },
    { 6, 22, 1, 1, 9 },
    { 12, 28, 1, 1, 9 },
    { 26, 30, 1, 1, 9 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { -48, -16, 1, 1, 10 },
    { -35, -15, 1, 1, 10 },
    { -40, 6, 1, 1, 10 },
    { -40, 4, 1, 1, 10 },
    { -48, -16, 1, 1, 10 },
    { -36, 2, 1, 1, 10 },
    { -6, -8, 1, 1, 10 },
    { -28, -12, 1, 1, 10 },
    { -48, 24, 1, 1, 10 },
    { -40, 8, 1, 1, 10 },
    { -40, 4, 1, 1, 10 },
    { -40, 6, 1, 1, 10 },
    { -40, 6, 1, 1, 10 },
    { -48, -16, 1, 1, 10 },
    { -40, 6, 1, 1, 10 },
    { 0, 0, 1, 1, 12 },
    { -64, 16, 1, 1, 10 },
    { -52, 8, 1, 1, 10 },
    { -56, -8, 1, 1, 10 },
    { -36, -16, 1, 1, 10 },
    { -40, -4, 1, 1, 10 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
};

/* extra scripts: 66 entries */
const u16* const chun_exca[67] = {
    chun_exca_000,  /* 0 follow-up of AIR NORMAL */
    chun_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    chun_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    chun_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    chun_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    chun_exca_005,  /* 5 follow-up of KGM TATAKI S, HARAYARARE +16 */
    chun_exca_005,  /* 6 follow-up of NOKEZORI, UPPER +9 */
    chun_exca_007,  /* 7 follow-up of ASIB TUNNOMERI, HUMI ASIB */
    chun_exca_008,  /* 8 follow-up of KUNOJI, KISHINRIKI +3 */
    chun_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +3 */
    chun_exca_010,  /* 10 follow-up of KIRIMOMI, TOMOE RYU +2 */
    chun_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    chun_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    chun_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    chun_exca_014,  /* 14 no name */
    chun_exca_015,  /* 15 no name */
    chun_exca_016,  /* 16 no name */
    chun_exca_017,  /* 17 follow-up of APPEAR JUNBI 7 */
    chun_exca_018,  /* 18 no name */
    chun_exca_019,  /* 19 no name */
    chun_exca_020,  /* 20 no name */
    chun_exca_021,  /* 21 no name */
    chun_exca_022,  /* 22 no name */
    chun_exca_023,  /* 23 follow-up of HARAIGOSHI */
    chun_exca_024,  /* 24 follow-up of APPEAR JUNBI 1 */
    chun_exca_025,  /* 25 follow-up of APPEAR JUNBI 7 */
    chun_exca_026,  /* 26 follow-up of APPEAR JUNBI 8 */
    chun_exca_027,  /* 27 follow-up of ATTACK 6 S */
    chun_exca_027,  /* 28 no name */
    chun_exca_029,  /* 29 no name */
    chun_exca_030,  /* 30 follow-up of APPEAR 1 */
    chun_exca_030,  /* 31 follow-up of APPEAR 1 */
    chun_exca_032,  /* 32 no name */
    chun_exca_033,  /* 33 follow-up of APPEAR 5 */
    chun_exca_034,  /* 34 follow-up of APPEAR 5 */
    chun_exca_034,  /* 35 no name */
    chun_exca_034,  /* 36 no name */
    chun_exca_037,  /* 37 follow-up of ZANNEN 6 */
    chun_exca_038,  /* 38 follow-up of ZANNEN 6 */
    chun_exca_039,  /* 39 follow-up of WIN 7 */
    chun_exca_040,  /* 40 follow-up of WIN 7 */
    chun_exca_041,  /* 41 follow-up of GILL IMPACT C */
    chun_exca_042,  /* 42 follow-up of GILL IMPACT C */
    chun_exca_043,  /* 43 follow-up of WIN 8 */
    chun_exca_044,  /* 44 follow-up of WIN 8 */
    chun_exca_045,  /* 45 follow-up of SP WIN 1 */
    chun_exca_046,  /* 46 follow-up of SP WIN 1 */
    chun_exca_047,  /* 47 follow-up of SP WIN 2 */
    chun_exca_048,  /* 48 follow-up of SP WIN 2 */
    chun_exca_049,  /* 49 follow-up of SP WIN 3 */
    chun_exca_050,  /* 50 follow-up of SP WIN 3 */
    chun_exca_049,  /* 51 follow-up of SP WIN 4 */
    chun_exca_050,  /* 52 follow-up of SP WIN 4 */
    chun_exca_053,  /* 53 follow-up of SP WIN 5 */
    chun_exca_054,  /* 54 follow-up of SP WIN 5 */
    chun_exca_055,  /* 55 follow-up of SP APPEAR 7 */
    chun_exca_056,  /* 56 follow-up of SP APPEAR 8 */
    chun_exca_057,  /* 57 follow-up of ZANNEN 1 */
    chun_exca_058,  /* 58 follow-up of ZANNEN 2 */
    chun_exca_059,  /* 59 follow-up of SP APPEAR 7 */
    chun_exca_060,  /* 60 follow-up of SP APPEAR 8 */
    chun_exca_061,  /* 61 follow-up of ZANNEN 1 */
    chun_exca_062,  /* 62 follow-up of ZANNEN 2 */
    chun_exca_063,  /* 63 follow-up of ZANNEN 5 */
    chun_exca_064,  /* 64 follow-up of ZANNEN 5 */
    chun_exca_065,  /* 65 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 chun_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5DB1, 0, 375, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5DB2, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB3, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5DB4, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB5, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB6, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB7, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 375, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 375, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 375, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 375, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 chun_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_001[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5AB4, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5AB5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x5AB6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 chun_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_003[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C45, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5C59, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 chun_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_004[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5AB4, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5AB5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5AB6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of KGM TATAKI S, HARAYARARE +16, 6 follow-up of NOKEZORI, UPPER +9 */
const u16 chun_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_005[148] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C29, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C2A, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x5C2B, 0, 377, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x5C2C, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x5C2D, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x5C2E, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C2F, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C30, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C31, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C32, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x5C33, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C34, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C35, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C36, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C37, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of ASIB TUNNOMERI, HUMI ASIB */
const u16 chun_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_007[76] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x5C2B, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C2A, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C30, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C36, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C37, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C38, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, KISHINRIKI +3 */
const u16 chun_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_008[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C54, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C55, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C56, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C57, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C58, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C59, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +3 */
const u16 chun_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_009[76] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5CA3, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x5CA4, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5CA5, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, TOMOE RYU +2 */
const u16 chun_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_010[76] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C80, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C58, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C59, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 chun_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_011[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 chun_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_013[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 chun_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AFA, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 chun_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_015[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AEE, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 chun_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x5B02, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x5B01, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x5AFF, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AE9, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AE9, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of APPEAR JUNBI 7 */
const u16 chun_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_017[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5AB4, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5AB5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5AB6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 chun_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x5AE5, 0, 0, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x5AE6, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AE7, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 chun_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x5B02, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x5B01, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x5AFF, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x5AE9, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x5AE9, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 chun_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_020[84] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x5AE0, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x5B25, 0, 374, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x5B27, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x5B28, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x5B29, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x5B2A, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x5B2C, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AFA, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AFA, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 chun_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x5B06, 0, 374, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x5B00, 0, 374, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x5AFF, 0, 374, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x5D13, 0, 374, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5AFB, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AFB, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 chun_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_022[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x5C27, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI */
const u16 chun_exca_023_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_023[148] = {
    L4(3, 2, 0, 0, 1, 0, 0, 0x5C29, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 1, 0, 0, 0x5C2A, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 1, 0, 0, 0x5C2B, 0, 377, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 1, 0, 0, 0x5C2C, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 1, 0, 0, 0x5C2D, 0, 377, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 1, 0, 0, 0x5C2E, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 1, 0, 0, 0x5C2F, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x5C30, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x5C31, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x5C32, 0, 377, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x5C33, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x5C34, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x5C35, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x5C36, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x5C37, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x5C38, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x5C39, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 1 */
const u16 chun_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_024[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DE9, 0, 78, 0, 0, 0, 30, 129),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DEA, 0, 79, 0, 0, 0, 30, 130),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DEB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DEC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5DED, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR JUNBI 7 */
const u16 chun_exca_025_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_025[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR JUNBI 8 */
const u16 chun_exca_026_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_026[424] = {
    L6(1, 30, 273, 0, 0, 0, 0, 0x5FB7, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB8, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB9, 0, 283, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBA, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBB, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBC, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FBD, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5FBE, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FBF, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FC0, 0, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FC1, 0, 286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FC2, 0, 287, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FC2, 0, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 30, 0, 0, 0, 0, 0, 0x5FB7, 0, 281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB8, 0, 282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB9, 0, 283, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBA, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBB, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FBC, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FBD, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5FBE, 0, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FBF, 0, 284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FC0, 0, 285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of ATTACK 6 S, 28 no name */
const u16 chun_exca_027_head[4] = { HEAD(6, 0, 32, 10, 0, 0, 4) };
const u16 chun_exca_027[184] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FEF, 0, 342, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF0, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF1, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FF2, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FF3, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FF4, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FF6, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF7, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FF9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 chun_exca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_029[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AEC, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AED, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AEE, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1, 31 follow-up of APPEAR 1 */
const u16 chun_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_030[68] = {
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x5A83, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A84, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A85, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 no name */
const u16 chun_exca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_032[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x5AE3, 0, 374, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AE4, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AE5, 0, 374, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AE6, 0, 374, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x5AE7, 0, 374, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR 5 */
const u16 chun_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_033[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A84, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5A85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 5, 35 no name, 36 no name */
const u16 chun_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_034[44] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A29, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A2B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A2C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A2C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of ZANNEN 6 */
const u16 chun_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_037[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x5A4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5A2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5A2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of ZANNEN 6 */
const u16 chun_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_038[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5A29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5A2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of WIN 7 */
const u16 chun_exca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_039[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x5A4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5A2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5A2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of WIN 7 */
const u16 chun_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_040[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x5A29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5A2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of GILL IMPACT C */
const u16 chun_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_041[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C45, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5C59, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 chun_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 chun_exca_042[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5C45, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5C59, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5C5A, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x5C5B, 0, 377, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C5C, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5C5D, 0, 377, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5C5E, 0, 377, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of WIN 8 */
const u16 chun_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_043[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x5CBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5BE7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5A93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of WIN 8 */
const u16 chun_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_044[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 273, 0, 0, 0, 0, 0x5CBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A28, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A29, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A2A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP WIN 1 */
const u16 chun_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_045[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5AB4, 0, 255, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB5, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5AB6, 0, 255, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 1 */
const u16 chun_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_046[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x5A61, 0, 255, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of SP WIN 2 */
const u16 chun_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_047[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x5AB4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x5AB5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5AB6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of SP WIN 2 */
const u16 chun_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_048[52] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x5A61, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A62, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x5A63, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A64, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SP WIN 3, 51 follow-up of SP WIN 4 */
const u16 chun_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_049[100] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x5B45, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5B46, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5B47, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5B48, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5B49, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5B4A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5B4B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5B4C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of SP WIN 3, 52 follow-up of SP WIN 4 */
const u16 chun_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_050[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5B45, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5A60, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x5A61, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5A62, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A63, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A64, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A65, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A65, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of SP WIN 5 */
const u16 chun_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_053[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A8C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5A85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x5A86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of SP WIN 5 */
const u16 chun_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_054[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x5A83, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x5A88, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x5A29, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x5A2A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5A2C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A2C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of SP APPEAR 7 */
const u16 chun_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_055[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of SP APPEAR 8 */
const u16 chun_exca_056_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_056[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 follow-up of ZANNEN 1 */
const u16 chun_exca_057_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_057[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 follow-up of ZANNEN 2 */
const u16 chun_exca_058_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_058[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A70, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A71, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5A72, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x5A73, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5A74, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 follow-up of SP APPEAR 7 */
const u16 chun_exca_059_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_059[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 follow-up of SP APPEAR 8 */
const u16 chun_exca_060_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_060[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of ZANNEN 1 */
const u16 chun_exca_061_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_061[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of ZANNEN 2 */
const u16 chun_exca_062_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_062[112] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of ZANNEN 5 */
const u16 chun_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_exca_063[204] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D00, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D01, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D02, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D03, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D04, 0, 2, 0, 0, 0, 30, 118),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D05, 0, 2, 0, 0, 0, 30, 119),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D06, 0, 2, 0, 0, 0, 30, 120),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D07, 0, 2, 0, 0, 0, 30, 121),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D08, 0, 2, 0, 0, 0, 30, 122),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D09, 0, 2, 0, 0, 0, 30, 123),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D0A, 0, 2, 0, 0, 0, 30, 124),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D0B, 0, 2, 0, 0, 0, 30, 125),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D0F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D10, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D11, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5D12, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x5D13, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D14, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D15, 0, 1, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of ZANNEN 5 */
const u16 chun_exca_064_head[4] = { HEAD(6, 32, 0, 0, 0, 0, 0) };
const u16 chun_exca_064[112] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x5C0A, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C0B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E56, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E30, 0, 231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5CB5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5E34, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 chun_exca_065_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 chun_exca_065[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x5DB1, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5DB2, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB3, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x5DB4, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB5, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB6, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5DB7, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AAF, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB0, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5AB1, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB2, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5AB3, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 70 entries */
const u16* const chun_saca[71] = {
    chun_saca_000,  /* 0 UP P GUARD P S */
    chun_saca_001,  /* 1 UP P GUARD P M */
    chun_saca_002,  /* 2 UP P GUARD P L */
    chun_saca_002,  /* 3 UP P GUARD K S */
    chun_saca_002,  /* 4 UP P GUARD K M */
    chun_saca_002,  /* 5 UP P GUARD K L */
    chun_saca_000,  /* 6 D P GUARD P S */
    chun_saca_001,  /* 7 D P GUARD P M */
    chun_saca_002,  /* 8 D P GUARD P L */
    chun_saca_002,  /* 9 D P GUARD K S */
    chun_saca_002,  /* 10 D P GUARD K M */
    chun_saca_002,  /* 11 D P GUARD K L */
    chun_saca_002,  /* 12 FUSHIN P S */
    chun_saca_002,  /* 13 FUSHIN P M */
    chun_saca_002,  /* 14 FUSHIN P L */
    chun_saca_002,  /* 15 FUSHIN K S */
    chun_saca_002,  /* 16 FUSHIN K M */
    chun_saca_002,  /* 17 FUSHIN K L */
    chun_saca_002,  /* 18 OKIAGARI P S */
    chun_saca_002,  /* 19 OKIAGARI P M */
    chun_saca_002,  /* 20 OKIAGARI P L */
    chun_saca_002,  /* 21 OKIAGARI K S */
    chun_saca_002,  /* 22 OKIAGARI K M */
    chun_saca_002,  /* 23 OKIAGARI K L */
    chun_saca_024,  /* 24 ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
    chun_saca_025,  /* 25 ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
    chun_saca_026,  /* 26 ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    chun_saca_027,  /* 27 ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    chun_saca_028,  /* 28 ATTACK 2 S: KKKKK [EX KK] (plain script) */
    chun_saca_029,  /* 29 ATTACK 2 M: KKKKK [EX KK] (plain script) */
    chun_saca_030,  /* 30 ATTACK 2 L: KKKKK [EX KK] (plain script) */
    chun_saca_031,  /* 31 ATTACK 2 SP: KKKKK [EX KK] (plain script) */
    chun_saca_032,  /* 32 ATTACK 3 S: after KKKKK (plain script) */
    chun_saca_033,  /* 33 ATTACK 3 M: after KKKKK (plain script) */
    chun_saca_034,  /* 34 ATTACK 3 L: after KKKKK (plain script) */
    chun_saca_035,  /* 35 ATTACK 3 SP: after KKKKK (plain script) */
    chun_saca_036,  /* 36 ATTACK 4 S: after KKKKK (plain script) */
    chun_saca_037,  /* 37 ATTACK 4 M: after KKKKK (plain script) */
    chun_saca_038,  /* 38 ATTACK 4 L: after KKKKK (plain script) */
    chun_saca_039,  /* 39 ATTACK 4 SP: after KKKKK (plain script) */
    chun_saca_040,  /* 40 ATTACK 5 S: 1236+P light (plain script) */
    chun_saca_041,  /* 41 ATTACK 5 M: 1236+P medium (plain script) */
    chun_saca_042,  /* 42 ATTACK 5 L: 1236+P heavy (plain script) */
    chun_saca_043,  /* 43 ATTACK 5 SP: EX 1236+PP (plain script) */
    chun_saca_044,  /* 44 ATTACK 6 S: SA I 23623+P (plain script) */
    chun_saca_044,  /* 45 ATTACK 6 M: SA I 23623+P (plain script) */
    chun_saca_044,  /* 46 ATTACK 6 L: SA I 23623+P (plain script) */
    chun_saca_044,  /* 47 ATTACK 6 SP: SA I 23623+P (plain script) */
    chun_saca_048,  /* 48 ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_048,  /* 49 ATTACK 7 M: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_048,  /* 50 ATTACK 7 L: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_048,  /* 51 ATTACK 7 SP: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_052,  /* 52 ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_052,  /* 53 ATTACK 8 M: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_052,  /* 54 ATTACK 8 L: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_052,  /* 55 ATTACK 8 SP: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    chun_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    chun_saca_056,  /* 57 ATTACK 9 M: not started by a command */
    chun_saca_056,  /* 58 ATTACK 9 L: not started by a command */
    chun_saca_056,  /* 59 ATTACK 9 SP: not started by a command */
    chun_saca_060,  /* 60 ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP) */
    chun_saca_061,  /* 61 ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) */
    chun_saca_062,  /* 62 ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    chun_saca_063,  /* 63 ATTACK 10 SP: EX 3214+KK (routine Att_SLIDE_and_JUMP) */
    chun_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    chun_saca_064,  /* 65 ATTACK 11 M: not started by a command */
    chun_saca_064,  /* 66 ATTACK 11 L: not started by a command */
    chun_saca_067,  /* 67 ATTACK 11 SP: after KKKKK (plain script) */
    chun_saca_068,  /* 68 ATTACK 12 S: after KKKKK (plain script) */
    chun_saca_069,  /* 69 ATTACK 12 M: after KKKKK (plain script) */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 chun_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 chun_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7115, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7116, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7117, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7118, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7119, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x711F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -256, 5888), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 chun_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 chun_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x711F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x711E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x711E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711B, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x711A, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7119, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7118, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7117, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7116, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7115, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 chun_saca_002_head[4] = { HEAD(6, 0, 4, 11, 0, 8, 0) };
const u16 chun_saca_002[12] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AEE, 0, 126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
const u16 chun_saca_024_head[4] = { HEAD(6, 0, 9, 14, 0, 4, 76) };
const u16 chun_saca_024[424] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 429, 0, 0, 0, 0, 0x5FA0, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA1, 0, 260, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA2, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA3, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA4, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA5, 0, 263, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA6, 0, 264, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA7, 0, 265, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA8, 0, 266, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x5FA9, -38, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 10, 0x5FAA, -39, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 10, 0x5FAB, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 10, 0x5FAC, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 10, 0x5FAD, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 10, 0x5FAE, -39, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 10, 0x5FAF, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 10, 0x5FB0, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 10, 0x5FB1, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 7, 0x5FAA, -40, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 7, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
const u16 chun_saca_025_head[4] = { HEAD(6, 0, 11, 15, 0, 6, 76) };
const u16 chun_saca_025[448] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 429, 0, 0, 0, 0, 0x5FA0, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA1, 0, 260, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA2, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA3, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA4, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA5, 0, 263, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA6, 0, 264, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA7, 0, 265, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA8, 0, 266, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x5FA9, -109, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAA, -110, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5FAB, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAC, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAD, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAE, -110, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAF, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FB0, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB1, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 7, 0x5FAA, -122, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 7, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
const u16 chun_saca_026_head[4] = { HEAD(6, 0, 13, 16, 0, 8, 76) };
const u16 chun_saca_026[448] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 429, 0, 0, 0, 0, 0x5FA0, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA1, 0, 260, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA2, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA3, 0, 261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FA4, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FA5, 0, 263, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA6, 0, 264, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA7, 0, 265, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA8, 0, 266, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x5FA9, -112, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAA, -113, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5FAB, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAC, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAD, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAE, -113, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAF, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FB0, 0, 274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB1, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 7, 0x5FAA, -123, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 9, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 9, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 7, 0x5FB2, 0, 276, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB3, 0, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 8, 0x5FB4, 0, 278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB5, 0, 279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 8, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x5FB6, 0, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
const u16 chun_saca_027_head[4] = { HEAD(6, 0, 15, 13, 0, 5, 76) };
const u16 chun_saca_027[364] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 429, 0, 0, 0, 0, 0x5FA0, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA1, 0, 318, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA2, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA3, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FA4, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA5, 0, 318, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA6, 0, 507, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA7, 0, 508, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FA8, 0, 509, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x5FA9, 0, 510, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAA, -71, 365, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5FAB, 0, 368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAC, 0, 369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAD, 0, 370, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAE, -72, 366, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAF, 0, 371, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB1, 0, 373, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAA, -71, 365, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x5FAB, 0, 368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAC, 0, 369, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAD, 0, 370, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FAE, -72, 366, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FAF, 0, 371, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FB1, 0, 373, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 7, 0x5FAA, -73, 365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 24, 21), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: KKKKK [EX KK] (plain script) */
const u16 chun_saca_028_head[4] = { HEAD(6, 0, 9, 11, 0, 40, 77) };
const u16 chun_saca_028[268] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 428, 0, 0, 0, 0, 0x5F3C, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 67, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 28, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 28, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 28, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 28, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 28, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3B, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3C, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: KKKKK [EX KK] (plain script) */
const u16 chun_saca_029_head[4] = { HEAD(6, 0, 11, 11, 0, 32, 77) };
const u16 chun_saca_029[268] = {
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 428, 0, 0, 0, 0, 0x5F3C, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 68, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 29, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 29, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 37, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 29, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 29, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 29, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3B, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3C, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: KKKKK [EX KK] (plain script) */
const u16 chun_saca_030_head[4] = { HEAD(6, 0, 13, 11, 0, 24, 77) };
const u16 chun_saca_030[268] = {
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 428, 0, 0, 0, 0, 0x5F3C, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 69, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 30, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 30, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 30, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 30, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 30, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3B, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3C, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: KKKKK [EX KK] (plain script) */
const u16 chun_saca_031_head[4] = { HEAD(6, 0, 15, 12, 0, 24, 77) };
const u16 chun_saca_031[244] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 428, 0, 0, 0, 0, 0x5F3C, 0, 298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 35, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 31, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 31, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 39, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, -1, -1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPK, 5, 31, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 31, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCGT, 16384, 0, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 31, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3B, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3C, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: after KKKKK (plain script) */
const u16 chun_saca_032_head[4] = { HEAD(6, 0, 9, 11, 0, 40, 77) };
const u16 chun_saca_032[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F48, -78, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -44, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F92, -45, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F96, -47, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: after KKKKK (plain script) */
const u16 chun_saca_033_head[4] = { HEAD(6, 0, 11, 11, 0, 32, 77) };
const u16 chun_saca_033[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F48, -79, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -48, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F92, -49, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F96, -51, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: after KKKKK (plain script) */
const u16 chun_saca_034_head[4] = { HEAD(6, 0, 13, 11, 0, 24, 77) };
const u16 chun_saca_034[112] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F48, -80, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -52, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F92, -53, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F96, -55, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: after KKKKK (plain script) */
const u16 chun_saca_035_head[4] = { HEAD(6, 0, 15, 12, 0, 24, 77) };
const u16 chun_saca_035[112] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F48, -81, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -74, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F92, -75, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F96, -77, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: after KKKKK (plain script) */
const u16 chun_saca_036_head[4] = { HEAD(6, 0, 9, 11, 0, 40, 77) };
const u16 chun_saca_036[88] = {
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F4B, -78, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4C, 0, 385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F98, -44, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F99, 0, 312, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F9A, -45, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F9D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F9E, -47, 317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: after KKKKK (plain script) */
const u16 chun_saca_037_head[4] = { HEAD(6, 0, 11, 11, 0, 32, 77) };
const u16 chun_saca_037[88] = {
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F4B, -79, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4C, 0, 385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F98, -48, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F99, 0, 312, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F9A, -49, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F9D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9E, -51, 317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: after KKKKK (plain script) */
const u16 chun_saca_038_head[4] = { HEAD(6, 0, 13, 11, 0, 24, 77) };
const u16 chun_saca_038[88] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4B, -80, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4C, 0, 385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F98, -52, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F99, 0, 312, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F9A, -53, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9E, -55, 317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: after KKKKK (plain script) */
const u16 chun_saca_039_head[4] = { HEAD(6, 0, 15, 12, 0, 24, 77) };
const u16 chun_saca_039[88] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4B, -81, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4C, 0, 385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F98, -74, 311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F99, 0, 312, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F9A, -75, 313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9E, -77, 317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: 1236+P light (plain script) */
const u16 chun_saca_040_head[4] = { HEAD(6, 0, 8, 22, 0, 1, 78) };
const u16 chun_saca_040[376] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD0, 0, 350, 0, 0, 0, 21, 0, 0, 0, 238, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD1, 0, 351, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD2, 0, 352, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FD3, 0, 353, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD4, 0, 354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD5, 0, 355, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD6, 0, 356, 0, 0, 0, 33, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 425, 0, 0, 0, 0, 0x5FD7, 0, 357, 0, 0, 0, 31, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 145, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 146, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 147, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD8, 0, 358, 0, 0, 64, 2, 208, 0, 0, 250, 0, 0),
    L6(3, 0, 446, 0, 0, 0, 0, 0x5FD9, 0, 359, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDA, 0, 359, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDB, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDC, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FDD, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FDE, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FDF, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FE0, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5FE1, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE2, 0, 360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE3, 0, 361, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE4, 0, 362, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE5, 0, 363, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 1236+P medium (plain script) */
const u16 chun_saca_041_head[4] = { HEAD(6, 0, 10, 20, 0, 1, 78) };
const u16 chun_saca_041[364] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD0, 0, 350, 0, 0, 0, 21, 0, 0, 0, 238, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD1, 0, 351, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD2, 0, 352, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD3, 0, 353, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD4, 0, 354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD5, 0, 355, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD6, 0, 356, 0, 0, 0, 33, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 425, 0, 0, 0, 0, 0x5FD7, 0, 357, 0, 0, 0, 31, 1, 0, 0, 250, 0, 0),
    CMD(CM_EXEC, 30, 145, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 146, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 147, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD8, 0, 358, 0, 0, 64, 2, 209, 0, 0, 252, 0, 0),
    L6(3, 0, 446, 0, 0, 0, 0, 0x5FD9, 0, 359, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FDB, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDC, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDD, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDE, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDF, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FE0, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5FE1, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE2, 0, 360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE3, 0, 361, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE4, 0, 362, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE5, 0, 363, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 1236+P heavy (plain script) */
const u16 chun_saca_042_head[4] = { HEAD(6, 0, 12, 18, 0, 1, 78) };
const u16 chun_saca_042[364] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD0, 0, 350, 0, 0, 0, 21, 0, 0, 0, 238, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD1, 0, 351, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD2, 0, 352, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD3, 0, 353, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD4, 0, 354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD5, 0, 355, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD6, 0, 356, 0, 0, 0, 33, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 425, 0, 0, 0, 0, 0x5FD7, 0, 357, 0, 0, 0, 31, 1, 0, 0, 250, 0, 0),
    CMD(CM_EXEC, 30, 145, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 146, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 147, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD8, 0, 358, 0, 0, 64, 2, 210, 0, 0, 252, 0, 0),
    L6(3, 0, 446, 0, 0, 0, 0, 0x5FD9, 0, 359, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FDB, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FDC, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FDD, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FDE, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDF, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FE0, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5FE1, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE2, 0, 360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE3, 0, 361, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FE4, 0, 362, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FE5, 0, 363, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: EX 1236+PP (plain script) */
const u16 chun_saca_043_head[4] = { HEAD(6, 0, 14, 22, 0, 2, 78) };
const u16 chun_saca_043[388] = {
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD0, 0, 350, 0, 0, 0, 21, 0, 0, 0, 238, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD1, 0, 351, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FD2, 0, 352, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FD3, 0, 353, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FD4, 0, 354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD5, 0, 355, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD6, 0, 356, 0, 0, 0, 33, 0, 0, 0, 248, 0, 0),
    L6(1, 0, 425, 0, 0, 0, 0, 0x5FD7, 0, 357, 0, 0, 0, 31, 1, 0, 0, 250, 0, 0),
    CMD(CM_EXEC, 30, 145, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 146, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 147, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FD8, 0, 358, 0, 0, 64, 2, 211, 0, 0, 252, 0, 0),
    L6(2, 0, 446, 0, 0, 0, 0, 0x5FD9, 0, 359, 0, 0, 64, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDA, 0, 359, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDB, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDC, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FDD, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FDE, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FDF, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FE0, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5FE1, 0, 359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE2, 0, 360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE3, 0, 361, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE4, 0, 362, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE5, 0, 363, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x5D57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D58, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA I 23623+P (plain script), 45 ATTACK 6 M: SA I 23623+P (plain script), 46 ATTACK 6 L: SA I 23623+P (plain script), 47 ATTACK 6 SP: SA I 23623+P (plain script) */
const u16 chun_saca_044_head[4] = { HEAD(6, 0, 32, 14, 0, 20, 81) };
const u16 chun_saca_044[1420] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 426, 0, 0, 0, 0, 0x5FC3, 0, 318, 0, 0, 0, 13, 56, 783, 0, 204, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FC4, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FC5, 0, 318, 0, 0, 0, 0, 0, 783, 0, 206, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5FC6, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FC7, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FC8, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5FC9, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FCA, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(14, 0, 0, 0, 0, 0, 0, 0x5FCB, 0, 318, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE6, 0, 318, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE7, 0, 318, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5FE8, 0, 318, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5FE9, 0, 318, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(1, 0, 427, 0, 0, 0, 0, 0x5FEA, 0, 318, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(1, 0, 0, 0, 0, 1, 0, 0x5FEB, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 2, 0, 0x5FEC, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 447, 0, 0, 3, 0, 0x5FED, -58, 343, 0, 0, 0, 1, 148, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 4, 0, 0x5FEE, -59, 344, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 5, 0, 0x5FED, -60, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 6, 0, 0x5FEE, -63, 346, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 7, 0, 0x5FED, -64, 347, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 8, 0, 0x5FEE, -65, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 9, 0, 0x5FED, -63, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 10, 0, 0x5FEE, -61, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 11, 0, 0x5FED, -62, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 12, 0, 0x5FEE, -66, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 13, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 14, 0, 0x5FEE, -65, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 15, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 16, 0, 0x5FEE, -61, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 17, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 18, 0, 0x5FEE, -66, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 19, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 20, 0, 0x5FEE, -68, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 21, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 22, 0, 0x5FEE, -61, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 23, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 24, 0, 0x5FEE, -64, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -256, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 25, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 26, 0, 0x5FEE, -68, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -512, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 27, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 28, 0, 0x5FEE, -70, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -768, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 29, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 30, 0, 0x5FEE, -66, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 16386, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PA_X, 1, -1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 31, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 32, 0, 0x5FEE, -69, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 33, 0, 0x5FED, 0, 342, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 34, 0, 0x5FEE, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 35, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 36, 0, 0x5FEE, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 37, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 38, 0, 0x5FEE, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 39, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 40, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 41, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 42, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 43, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 44, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 45, 0, 0x5FED, 0, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP), 49 ATTACK 7 M: SA II 23623+K (routine Att_SLIDE_and_JUMP), 50 ATTACK 7 L: SA II 23623+K (routine Att_SLIDE_and_JUMP), 51 ATTACK 7 SP: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_048_head[4] = { HEAD(6, 0, 33, 11, 0, 17, 82) };
const u16 chun_saca_048[928] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B87, 0, 318, 0, 0, 0, 13, 63, 780, 0, 0, 0, 0),
    L6(31, 0, 0, 0, 0, 0, 0, 0x5B88, 0, 318, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B26, 0, 318, 0, 0, 0, 0, 0, 0, 0, 276, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B27, 0, 318, 0, 0, 0, 0, 0, 0, 0, 278, 0, 0),
    CMD(CM_EXEC, 30, 183, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 30, 277, 0, 0, 0, 0, 0x5B28, 0, 318, 0, 0, 0, 30, 184, 0, 0, 280, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B29, 0, 318, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B2A, 0, 318, 0, 0, 0, 0, 0, 0, 0, 284, 0, 0),
    CMD(CM_EXEC, 30, 185, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 21, 420, 0, 0, 0, 0, 0x5B2B, 0, 492, 0, 0, 0, 30, 186, 0, 0, 286, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F90, -82, 386, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F92, -83, 387, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F96, -84, 388, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4D, 0, 413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F48, -85, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F97, 0, 303, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F98, -82, 390, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F99, 0, 312, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9A, -83, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F9D, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F9E, -84, 392, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4E, 0, 414, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4B, -86, 393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F97, 0, 303, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 277, 0, 0, 0, 0, 0x5B84, 0, 394, 0, 0, 0, 0, 0, 0, 0, 290, 0, 0),
    CMD(CM_EXEC, 30, 187, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 420, 0, 0, 0, 0, 0x5B85, 0, 395, 0, 0, 0, 30, 188, 0, 0, 292, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B86, 0, 396, 0, 0, 0, 0, 0, 0, 0, 294, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5B2C, -87, 397, 0, 0, 0, 30, 143, 0, 0, 296, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B2D, 0, 398, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B2E, -88, 399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B2F, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B3A, -89, 401, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B3B, 0, 402, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5B3C, -90, 403, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B3D, 0, 404, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B3E, -87, 405, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B3F, 0, 406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B6B, -88, 407, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B6C, 0, 408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5B6D, -89, 409, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B6E, 0, 410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B6F, -91, 411, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B3D, 0, 412, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B75, 0, 415, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B76, 0, 416, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B77, 0, 417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B78, 0, 418, 0, 0, 0, 0, 0, 0, 0, 298, 0, 0),
    CMD(CM_EXEC, 30, 189, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 277, 0, 0, 0, 0, 0x5B79, 0, 419, 0, 0, 0, 30, 190, 0, 0, 300, 0, 0),
    CMD(CM_EXEC, 30, 191, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 421, 0, 0, 0, 0, 0x5B7A, 0, 420, 0, 0, 0, 30, 192, 0, 0, 302, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5B7B, -92, 421, 0, 128, 0, 0, 0, 0, 0, 304, 0, 0),
    CMD(CM_IMGC, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8192, 8200, 8200), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5B7C, 93, 422, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B7D, 0, 423, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x5B7E, 0, 423, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5B7C, 93, 422, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B7D, 0, 423, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x5B7E, 0, 423, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B7F, 0, 424, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5B83, 0, 425, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5F3A, 0, 299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3B, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3C, 0, 301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5F3D, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F3E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5D16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x5D5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), 53 ATTACK 8 M: SA III 23623+K (routine Att_SLIDE_and_JUMP), 54 ATTACK 8 L: SA III 23623+K (routine Att_SLIDE_and_JUMP), 55 ATTACK 8 SP: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_052_head[4] = { HEAD(6, 0, 33, 14, 0, 9, 83) };
const u16 chun_saca_052[460] = {
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(49, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 318, 0, 0, 0, 13, 65, 780, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x5C08, 0, 496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 444, 0, 0, 0, 0, 0x5C09, 0, 496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 50, 0, 0x5BE6, -106, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 51, 0, 0x5BE7, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 52, 0, 0x5BE8, -102, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 444, 0, 0, 53, 0, 0x5BE9, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 54, 0, 0x5BEA, -102, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 55, 0, 0x5BEB, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 56, 0, 0x5BEC, -102, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 444, 0, 0, 57, 0, 0x5BED, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 58, 0, 0x5BEE, -102, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 59, 0, 0x5BEF, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 60, 0, 0x5BF7, -103, 438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 61, 0, 0x5BF8, -104, 439, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 62, 0, 0x5BF9, -105, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 420, 0, 0, 63, 0, 0x5BFA, 0, 432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 195, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 196, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 197, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 198, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 199, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 200, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 201, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 24, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 155, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 156, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_SSE, 445, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 291, 0, 0, 0, 0, 0x5BFB, -107, 494, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BFC, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5BFD, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5BFE, 0, 435, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 chun_saca_056_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 33) };
const u16 chun_saca_056[84] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5AB6, 0, 256, 0, 0, 0, 0, 0),
    L4(12, 20, 0, 0, 0, 0, 0, 0x5F0D, 0, 257, 0, 0, 0, 22, 20),
    L4(1, 0, 269, 0, 0, 0, 0, 0x5EC0, -11, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5EC0, 0, 258, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5EC1, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5EC2, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5EC3, 0, 258, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_060_head[4] = { HEAD(6, 0, 9, 12, 0, 1, 114) };
const u16 chun_saca_060[436] = {
    CMD(CM_RJA, 5, 60, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 277, 0, 0, 0, 0, 0x5C08, 0, 426, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C09, 0, 427, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE7, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE8, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE9, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEA, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEB, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEC, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BED, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEE, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEF, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF7, 0, 429, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF8, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF9, 0, 431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 420, 0, 0, 0, 0, 0x5BFA, 0, 432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 195, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 196, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 197, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 198, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 199, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 200, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 201, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 291, 0, 0, 0, 0, 0x5BFB, -94, 433, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BFC, 95, 434, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFD, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFE, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_061_head[4] = { HEAD(6, 0, 11, 12, 0, 1, 114) };
const u16 chun_saca_061[436] = {
    CMD(CM_RJA, 5, 61, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 277, 0, 0, 0, 0, 0x5C08, 0, 426, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C09, 0, 427, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE7, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE8, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE9, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEA, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEB, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEC, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BED, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEE, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEF, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF7, 0, 429, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF8, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BF9, 0, 431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 420, 0, 0, 0, 0, 0x5BFA, 0, 432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 195, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 196, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 197, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 198, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 199, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 200, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 201, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 291, 0, 0, 0, 0, 0x5BFB, -96, 433, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 14, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BFC, 97, 434, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 14, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFD, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFE, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_062_head[4] = { HEAD(6, 0, 13, 12, 0, 1, 114) };
const u16 chun_saca_062[436] = {
    CMD(CM_RJA, 5, 62, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 20, 277, 0, 0, 0, 0, 0x5C08, 0, 426, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5C09, 0, 427, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BE7, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE8, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE9, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEA, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEB, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEC, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BED, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEE, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEF, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF7, 0, 429, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BF8, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BF9, 0, 431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 420, 0, 0, 0, 0, 0x5BFA, 0, 432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 195, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 196, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 197, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 198, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 199, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 200, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 201, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 291, 0, 0, 0, 0, 0x5BFB, -98, 433, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BFC, 99, 434, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 16, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFD, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFE, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: EX 3214+KK (routine Att_SLIDE_and_JUMP) */
const u16 chun_saca_063_head[4] = { HEAD(6, 0, 15, 12, 0, 1, 114) };
const u16 chun_saca_063[412] = {
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A03, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 20, 277, 0, 0, 0, 0, 0x5C08, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5C09, 0, 318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BE6, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE7, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE8, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BE9, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEA, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEB, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEC, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BED, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEE, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BEF, 0, 428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5BF7, 0, 429, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BF8, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x5BF9, 0, 431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 420, 0, 0, 0, 0, 0x5BFA, 0, 432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 195, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 196, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 197, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 198, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 199, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 200, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 201, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 291, 0, 0, 0, 0, 0x5BFB, -100, 433, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 18, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5BFC, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFD, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFE, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5BFF, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command, 66 ATTACK 11 L: not started by a command */
const u16 chun_saca_064_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 chun_saca_064[748] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ABA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 258, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ABB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ABC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ABD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 436, 0, 0, 0, 0, 0x5ABE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ABF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AD0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AD1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AD2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5AD4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 40, 0, 0, 0, 0, 0, 0x5AD5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AD6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5AD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 8, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PJMP, 9, 8195, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PJMP, 23, 8196, 8197), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 40, 435, 0, 0, 0, 0, 0x5AD9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AD9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ADB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5ADC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 30, 0, 0, 0, 0, 0, 0x5AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    CMD(CM_JMP, 5, 64, 56), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A96, 0, 1, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(1, 40, 434, 0, 0, 0, 0, 0x5A97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A97, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5A98, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x5A9B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A99, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 50, 0, 0, 0, 0, 0, 0x5A96, 0, 1, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    CMD(CM_JMP, 5, 64, 56), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5A9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 40, 0, 0, 0, 0, 0, 0x5A9E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5A9F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 0, 0, 0x5A9D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x5A9C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0),
    CMD(CM_JMP, 5, 64, 56), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x5ADF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x5AB7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AB8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 255, 0, 0, 0, 0, 0, 0x5AB9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: after KKKKK (plain script) */
const u16 chun_saca_067_head[4] = { HEAD(6, 0, 9, 11, 0, 40, 77) };
const u16 chun_saca_067[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F48, -116, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -44, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x5F92, -45, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F96, -47, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: after KKKKK (plain script) */
const u16 chun_saca_068_head[4] = { HEAD(6, 0, 11, 11, 0, 32, 77) };
const u16 chun_saca_068[112] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F48, -117, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -48, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F92, -49, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F96, -51, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 69 ATTACK 12 M: after KKKKK (plain script) */
const u16 chun_saca_069_head[4] = { HEAD(6, 0, 13, 11, 0, 24, 77) };
const u16 chun_saca_069[112] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 380, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F48, -118, 381, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F49, 0, 382, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F90, -52, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F91, 0, 305, 0, 0, 0, 30, 144, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F92, -53, 306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F95, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x5F96, -55, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x5F4A, 0, 383, 0, 0, 0, 30, 143, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* combination scripts: 45 entries */
const u16* const chun_cbca[46] = {
    chun_cbca_000,  /* 0 APPEAR JUNBI 1 */
    chun_cbca_001,  /* 1 APPEAR JUNBI 2 */
    chun_cbca_002,  /* 2 APPEAR JUNBI 3 */
    chun_cbca_003,  /* 3 APPEAR JUNBI 4 */
    chun_cbca_004,  /* 4 APPEAR JUNBI 5 */
    chun_cbca_005,  /* 5 APPEAR JUNBI 6 */
    chun_cbca_006,  /* 6 APPEAR JUNBI 7 */
    chun_cbca_007,  /* 7 APPEAR JUNBI 8 */
    chun_cbca_008,  /* 8 APPEAR 1 */
    chun_cbca_009,  /* 9 APPEAR 2 */
    chun_cbca_010,  /* 10 APPEAR 3 */
    chun_cbca_010,  /* 11 APPEAR 4 */
    chun_cbca_012,  /* 12 APPEAR 5 */
    chun_cbca_013,  /* 13 APPEAR 6 */
    chun_cbca_014,  /* 14 APPEAR 7 */
    chun_cbca_015,  /* 15 APPEAR 8 */
    chun_cbca_016,  /* 16 SP APPEAR 1 */
    chun_cbca_017,  /* 17 SP APPEAR 2 */
    chun_cbca_018,  /* 18 SP APPEAR 3 */
    chun_cbca_019,  /* 19 SP APPEAR 4 */
    chun_cbca_020,  /* 20 SP APPEAR 5 */
    chun_cbca_021,  /* 21 SP APPEAR 6 */
    chun_cbca_022,  /* 22 SP APPEAR 7 */
    chun_cbca_023,  /* 23 SP APPEAR 8 */
    chun_cbca_024,  /* 24 ZANNEN 1 */
    chun_cbca_025,  /* 25 ZANNEN 2 */
    chun_cbca_026,  /* 26 ZANNEN 3 */
    chun_cbca_027,  /* 27 ZANNEN 4 */
    chun_cbca_028,  /* 28 ZANNEN 5 */
    chun_cbca_029,  /* 29 ZANNEN 6 */
    chun_cbca_029,  /* 30 ZANNEN 7 */
    chun_cbca_029,  /* 31 ZANNEN 8 */
    chun_cbca_029,  /* 32 WIN 1 */
    chun_cbca_029,  /* 33 WIN 2 */
    chun_cbca_029,  /* 34 WIN 3 */
    chun_cbca_029,  /* 35 WIN 4 */
    chun_cbca_029,  /* 36 WIN 5 */
    chun_cbca_029,  /* 37 WIN 6 */
    chun_cbca_038,  /* 38 WIN 7 */
    chun_cbca_039,  /* 39 WIN 8 */
    chun_cbca_040,  /* 40 SP WIN 1 */
    chun_cbca_041,  /* 41 SP WIN 2 */
    chun_cbca_042,  /* 42 SP WIN 3 */
    chun_cbca_043,  /* 43 SP WIN 4 */
    chun_cbca_044,  /* 44 SP WIN 5 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 chun_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 chun_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 chun_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 chun_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 chun_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 chun_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 chun_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 chun_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_007[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 26, 19),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 chun_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_008[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 chun_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_009[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3, 11 APPEAR 4 */
const u16 chun_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 chun_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_012[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 chun_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_013[12] = {
    CMD(CM_RJA4, 5, 28, 6),
    CMD(CM_WSET, 16384, 0, 5),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 chun_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_014[12] = {
    CMD(CM_RJA4, 5, 29, 6),
    CMD(CM_WSET, 16384, 0, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 chun_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_015[12] = {
    CMD(CM_RJA4, 5, 30, 6),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 chun_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_016[16] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 chun_cbca_017_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 chun_cbca_017[16] = {
    CMD(CM_EXEC, 49, 56, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 chun_cbca_018_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 chun_cbca_018[24] = {
    CMD(CM_EXEC, 49, 57, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RJA4, 5, 31, 4),
    CMD(CM_WSET, 16384, 0, 3),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 chun_cbca_019_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 chun_cbca_019[16] = {
    CMD(CM_EXEC, 49, 58, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 chun_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_020[20] = {
    CMD(CM_RJA, 5, 64, 55),
    CMD(CM_RJA2, 5, 64, 21),
    CMD(CM_RJA3, 5, 64, 32),
    CMD(CM_RJA4, 5, 64, 45),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 chun_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_021[20] = {
    CMD(CM_STOP, -38, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 34, 0),
    CMD(CM_RJA7, 5, 48, 65),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 chun_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_022[12] = {
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 59, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 chun_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_023[12] = {
    CMD(CM_RJA2, 7, 56, 1),
    CMD(CM_RJA3, 7, 60, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 chun_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_024[12] = {
    CMD(CM_RJA2, 7, 57, 1),
    CMD(CM_RJA3, 7, 61, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 chun_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_025[12] = {
    CMD(CM_RJA2, 7, 58, 1),
    CMD(CM_RJA3, 7, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 chun_cbca_026_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 chun_cbca_026[20] = {
    CMD(CM_EXEC, 49, 67, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RJA, 5, 63, 20),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 chun_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_027[20] = {
    CMD(CM_STOP, -49, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 35, 0),
    CMD(CM_RJA, 5, 52, 20),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 chun_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_028[12] = {
    CMD(CM_RJA2, 7, 63, 1),
    CMD(CM_RJA3, 7, 64, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6, 30 ZANNEN 7, 31 ZANNEN 8, 32 WIN 1 ... */
const u16 chun_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_029[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 chun_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_038[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 chun_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_039[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 chun_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_040[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 chun_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_041[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 chun_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_042[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 chun_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_043[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 chun_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chun_cbca_044[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

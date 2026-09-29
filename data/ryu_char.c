/*
 * RYU_CHAR.C  Ryu's animation scripts and sprite part tables
 *
 * The animation scripts Ryu's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 ryu_nmca_000[], ryu_nmca_001[], ryu_nmca_002[], ryu_nmca_003[], ryu_nmca_004[], ryu_nmca_005[], ryu_nmca_006[], ryu_nmca_007[], ryu_nmca_008[], ryu_nmca_011[], ryu_nmca_012[], ryu_nmca_013[], ryu_nmca_014[], ryu_nmca_015[], ryu_nmca_016[], ryu_nmca_017[], ryu_nmca_020[], ryu_nmca_021[], ryu_nmca_022[], ryu_nmca_023[], ryu_nmca_024[], ryu_nmca_026[], ryu_nmca_027[], ryu_nmca_029[], ryu_nmca_030[], ryu_nmca_031[], ryu_nmca_032[], ryu_nmca_033[], ryu_nmca_038[], ryu_nmca_040[], ryu_nmca_041[], ryu_nmca_043[], ryu_nmca_044[], ryu_nmca_045[], ryu_nmca_046[], ryu_nmca_047[], ryu_nmca_048[], ryu_nmca_049[], ryu_nmca_050[];
extern const u16 ryu_nmca_000_head[];
extern const u16 ryu_nmca_001_head[];
extern const u16 ryu_nmca_002_head[];
extern const u16 ryu_nmca_003_head[];
extern const u16 ryu_nmca_004_head[];
extern const u16 ryu_nmca_005_head[];
extern const u16 ryu_nmca_006_head[];
extern const u16 ryu_nmca_007_head[];
extern const u16 ryu_nmca_008_head[];
extern const u16 ryu_nmca_011_head[];
extern const u16 ryu_nmca_012_head[];
extern const u16 ryu_nmca_013_head[];
extern const u16 ryu_nmca_014_head[];
extern const u16 ryu_nmca_015_head[];
extern const u16 ryu_nmca_016_head[];
extern const u16 ryu_nmca_017_head[];
extern const u16 ryu_nmca_020_head[];
extern const u16 ryu_nmca_021_head[];
extern const u16 ryu_nmca_022_head[];
extern const u16 ryu_nmca_023_head[];
extern const u16 ryu_nmca_024_head[];
extern const u16 ryu_nmca_026_head[];
extern const u16 ryu_nmca_027_head[];
extern const u16 ryu_nmca_029_head[];
extern const u16 ryu_nmca_030_head[];
extern const u16 ryu_nmca_031_head[];
extern const u16 ryu_nmca_032_head[];
extern const u16 ryu_nmca_033_head[];
extern const u16 ryu_nmca_038_head[];
extern const u16 ryu_nmca_040_head[];
extern const u16 ryu_nmca_041_head[];
extern const u16 ryu_nmca_043_head[];
extern const u16 ryu_nmca_044_head[];
extern const u16 ryu_nmca_045_head[];
extern const u16 ryu_nmca_046_head[];
extern const u16 ryu_nmca_047_head[];
extern const u16 ryu_nmca_048_head[];
extern const u16 ryu_nmca_049_head[];
extern const u16 ryu_nmca_050_head[];
extern const u16 ryu_dmca_000[], ryu_dmca_001[], ryu_dmca_002[], ryu_dmca_003[], ryu_dmca_004[], ryu_dmca_006[], ryu_dmca_008[], ryu_dmca_009[], ryu_dmca_010[], ryu_dmca_014[], ryu_dmca_015[], ryu_dmca_018[], ryu_dmca_019[], ryu_dmca_022[], ryu_dmca_025[], ryu_dmca_026[], ryu_dmca_024[], ryu_dmca_029[], ryu_dmca_030[], ryu_dmca_034[], ryu_dmca_036[], ryu_dmca_048[], ryu_dmca_049[], ryu_dmca_050[], ryu_dmca_052[], ryu_dmca_060[], ryu_dmca_064[], ryu_dmca_065[], ryu_dmca_066[], ryu_dmca_067[], ryu_dmca_068[], ryu_dmca_070[], ryu_dmca_071[], ryu_dmca_072[], ryu_dmca_073[], ryu_dmca_074[], ryu_dmca_075[], ryu_dmca_076[], ryu_dmca_078[], ryu_dmca_079[], ryu_dmca_080[], ryu_dmca_082[], ryu_dmca_083[], ryu_dmca_084[], ryu_dmca_090[], ryu_dmca_091[], ryu_dmca_096[], ryu_dmca_097[];
extern const u16 ryu_dmca_000_head[];
extern const u16 ryu_dmca_001_head[];
extern const u16 ryu_dmca_002_head[];
extern const u16 ryu_dmca_003_head[];
extern const u16 ryu_dmca_004_head[];
extern const u16 ryu_dmca_006_head[];
extern const u16 ryu_dmca_008_head[];
extern const u16 ryu_dmca_009_head[];
extern const u16 ryu_dmca_010_head[];
extern const u16 ryu_dmca_014_head[];
extern const u16 ryu_dmca_015_head[];
extern const u16 ryu_dmca_018_head[];
extern const u16 ryu_dmca_019_head[];
extern const u16 ryu_dmca_022_head[];
extern const u16 ryu_dmca_025_head[];
extern const u16 ryu_dmca_026_head[];
extern const u16 ryu_dmca_024_head[];
extern const u16 ryu_dmca_029_head[];
extern const u16 ryu_dmca_030_head[];
extern const u16 ryu_dmca_034_head[];
extern const u16 ryu_dmca_036_head[];
extern const u16 ryu_dmca_048_head[];
extern const u16 ryu_dmca_049_head[];
extern const u16 ryu_dmca_050_head[];
extern const u16 ryu_dmca_052_head[];
extern const u16 ryu_dmca_060_head[];
extern const u16 ryu_dmca_064_head[];
extern const u16 ryu_dmca_065_head[];
extern const u16 ryu_dmca_066_head[];
extern const u16 ryu_dmca_067_head[];
extern const u16 ryu_dmca_068_head[];
extern const u16 ryu_dmca_070_head[];
extern const u16 ryu_dmca_071_head[];
extern const u16 ryu_dmca_072_head[];
extern const u16 ryu_dmca_073_head[];
extern const u16 ryu_dmca_074_head[];
extern const u16 ryu_dmca_075_head[];
extern const u16 ryu_dmca_076_head[];
extern const u16 ryu_dmca_078_head[];
extern const u16 ryu_dmca_079_head[];
extern const u16 ryu_dmca_080_head[];
extern const u16 ryu_dmca_082_head[];
extern const u16 ryu_dmca_083_head[];
extern const u16 ryu_dmca_084_head[];
extern const u16 ryu_dmca_090_head[];
extern const u16 ryu_dmca_091_head[];
extern const u16 ryu_dmca_096_head[];
extern const u16 ryu_dmca_097_head[];
extern const u16 ryu_btca_000[], ryu_btca_001[], ryu_btca_002[], ryu_btca_003[], ryu_btca_004[], ryu_btca_005[], ryu_btca_006[], ryu_btca_007[], ryu_btca_008[], ryu_btca_009[], ryu_btca_010[], ryu_btca_011[], ryu_btca_012[], ryu_btca_013[], ryu_btca_014[], ryu_btca_015[], ryu_btca_016[], ryu_btca_017[], ryu_btca_018[], ryu_btca_019[], ryu_btca_020[], ryu_btca_021[], ryu_btca_022[], ryu_btca_023[], ryu_btca_024[], ryu_btca_025[], ryu_btca_026[], ryu_btca_027[], ryu_btca_028[], ryu_btca_029[], ryu_btca_030[], ryu_btca_031[], ryu_btca_032[], ryu_btca_033[], ryu_btca_034[], ryu_btca_035[];
extern const u16 ryu_btca_000_head[];
extern const u16 ryu_btca_001_head[];
extern const u16 ryu_btca_002_head[];
extern const u16 ryu_btca_003_head[];
extern const u16 ryu_btca_004_head[];
extern const u16 ryu_btca_005_head[];
extern const u16 ryu_btca_006_head[];
extern const u16 ryu_btca_007_head[];
extern const u16 ryu_btca_008_head[];
extern const u16 ryu_btca_009_head[];
extern const u16 ryu_btca_010_head[];
extern const u16 ryu_btca_011_head[];
extern const u16 ryu_btca_012_head[];
extern const u16 ryu_btca_013_head[];
extern const u16 ryu_btca_014_head[];
extern const u16 ryu_btca_015_head[];
extern const u16 ryu_btca_016_head[];
extern const u16 ryu_btca_017_head[];
extern const u16 ryu_btca_018_head[];
extern const u16 ryu_btca_019_head[];
extern const u16 ryu_btca_020_head[];
extern const u16 ryu_btca_021_head[];
extern const u16 ryu_btca_022_head[];
extern const u16 ryu_btca_023_head[];
extern const u16 ryu_btca_024_head[];
extern const u16 ryu_btca_025_head[];
extern const u16 ryu_btca_026_head[];
extern const u16 ryu_btca_027_head[];
extern const u16 ryu_btca_028_head[];
extern const u16 ryu_btca_029_head[];
extern const u16 ryu_btca_030_head[];
extern const u16 ryu_btca_031_head[];
extern const u16 ryu_btca_032_head[];
extern const u16 ryu_btca_033_head[];
extern const u16 ryu_btca_034_head[];
extern const u16 ryu_btca_035_head[];
extern const u16 ryu_caca_000[], ryu_caca_004[], ryu_caca_008[], ryu_caca_010[], ryu_caca_012[], ryu_caca_014[];
extern const u16 ryu_caca_000_head[];
extern const u16 ryu_caca_004_head[];
extern const u16 ryu_caca_008_head[];
extern const u16 ryu_caca_010_head[];
extern const u16 ryu_caca_012_head[];
extern const u16 ryu_caca_014_head[];
extern const u16 ryu_cuca_000[], ryu_cuca_001[], ryu_cuca_002[], ryu_cuca_003[], ryu_cuca_004[], ryu_cuca_005[], ryu_cuca_006[], ryu_cuca_007[], ryu_cuca_008[], ryu_cuca_009[], ryu_cuca_010[], ryu_cuca_011[], ryu_cuca_012[], ryu_cuca_013[], ryu_cuca_014[], ryu_cuca_015[], ryu_cuca_016[], ryu_cuca_017[], ryu_cuca_018[], ryu_cuca_019[], ryu_cuca_020[], ryu_cuca_021[], ryu_cuca_022[], ryu_cuca_023[], ryu_cuca_024[], ryu_cuca_025[], ryu_cuca_026[], ryu_cuca_027[], ryu_cuca_028[], ryu_cuca_029[], ryu_cuca_030[], ryu_cuca_031[], ryu_cuca_032[], ryu_cuca_033[], ryu_cuca_034[], ryu_cuca_035[], ryu_cuca_036[], ryu_cuca_037[], ryu_cuca_038[], ryu_cuca_039[], ryu_cuca_040[], ryu_cuca_041[], ryu_cuca_042[], ryu_cuca_043[], ryu_cuca_044[], ryu_cuca_045[], ryu_cuca_046[], ryu_cuca_047[], ryu_cuca_048[], ryu_cuca_049[], ryu_cuca_050[], ryu_cuca_051[], ryu_cuca_052[], ryu_cuca_053[], ryu_cuca_054[], ryu_cuca_055[], ryu_cuca_056[], ryu_cuca_057[], ryu_cuca_058[], ryu_cuca_059[], ryu_cuca_060[], ryu_cuca_061[], ryu_cuca_062[], ryu_cuca_063[], ryu_cuca_064[], ryu_cuca_065[], ryu_cuca_066[], ryu_cuca_067[];
extern const u16 ryu_cuca_000_head[];
extern const u16 ryu_cuca_001_head[];
extern const u16 ryu_cuca_002_head[];
extern const u16 ryu_cuca_003_head[];
extern const u16 ryu_cuca_004_head[];
extern const u16 ryu_cuca_005_head[];
extern const u16 ryu_cuca_006_head[];
extern const u16 ryu_cuca_007_head[];
extern const u16 ryu_cuca_008_head[];
extern const u16 ryu_cuca_009_head[];
extern const u16 ryu_cuca_010_head[];
extern const u16 ryu_cuca_011_head[];
extern const u16 ryu_cuca_012_head[];
extern const u16 ryu_cuca_013_head[];
extern const u16 ryu_cuca_014_head[];
extern const u16 ryu_cuca_015_head[];
extern const u16 ryu_cuca_016_head[];
extern const u16 ryu_cuca_017_head[];
extern const u16 ryu_cuca_018_head[];
extern const u16 ryu_cuca_019_head[];
extern const u16 ryu_cuca_020_head[];
extern const u16 ryu_cuca_021_head[];
extern const u16 ryu_cuca_022_head[];
extern const u16 ryu_cuca_023_head[];
extern const u16 ryu_cuca_024_head[];
extern const u16 ryu_cuca_025_head[];
extern const u16 ryu_cuca_026_head[];
extern const u16 ryu_cuca_027_head[];
extern const u16 ryu_cuca_028_head[];
extern const u16 ryu_cuca_029_head[];
extern const u16 ryu_cuca_030_head[];
extern const u16 ryu_cuca_031_head[];
extern const u16 ryu_cuca_032_head[];
extern const u16 ryu_cuca_033_head[];
extern const u16 ryu_cuca_034_head[];
extern const u16 ryu_cuca_035_head[];
extern const u16 ryu_cuca_036_head[];
extern const u16 ryu_cuca_037_head[];
extern const u16 ryu_cuca_038_head[];
extern const u16 ryu_cuca_039_head[];
extern const u16 ryu_cuca_040_head[];
extern const u16 ryu_cuca_041_head[];
extern const u16 ryu_cuca_042_head[];
extern const u16 ryu_cuca_043_head[];
extern const u16 ryu_cuca_044_head[];
extern const u16 ryu_cuca_045_head[];
extern const u16 ryu_cuca_046_head[];
extern const u16 ryu_cuca_047_head[];
extern const u16 ryu_cuca_048_head[];
extern const u16 ryu_cuca_049_head[];
extern const u16 ryu_cuca_050_head[];
extern const u16 ryu_cuca_051_head[];
extern const u16 ryu_cuca_052_head[];
extern const u16 ryu_cuca_053_head[];
extern const u16 ryu_cuca_054_head[];
extern const u16 ryu_cuca_055_head[];
extern const u16 ryu_cuca_056_head[];
extern const u16 ryu_cuca_057_head[];
extern const u16 ryu_cuca_058_head[];
extern const u16 ryu_cuca_059_head[];
extern const u16 ryu_cuca_060_head[];
extern const u16 ryu_cuca_061_head[];
extern const u16 ryu_cuca_062_head[];
extern const u16 ryu_cuca_063_head[];
extern const u16 ryu_cuca_064_head[];
extern const u16 ryu_cuca_065_head[];
extern const u16 ryu_cuca_066_head[];
extern const u16 ryu_cuca_067_head[];
extern const u16 ryu_atca_000[], ryu_atca_001[], ryu_atca_003[], ryu_atca_004[], ryu_atca_005[], ryu_atca_006[], ryu_atca_007[], ryu_atca_008[], ryu_atca_009[], ryu_atca_012[], ryu_atca_013[], ryu_atca_015[], ryu_atca_018[], ryu_atca_021[], ryu_atca_024[], ryu_atca_027[], ryu_atca_030[], ryu_atca_033[], ryu_atca_036[], ryu_atca_038[], ryu_atca_040[], ryu_atca_042[], ryu_atca_044[], ryu_atca_046[], ryu_atca_048[], ryu_atca_050[], ryu_atca_052[], ryu_atca_054[], ryu_atca_056[], ryu_atca_058[], ryu_atca_060[], ryu_atca_062[], ryu_atca_064[], ryu_atca_066[], ryu_atca_068[], ryu_atca_070[], ryu_atca_072[], ryu_atca_074[], ryu_atca_076[], ryu_atca_078[], ryu_atca_080[], ryu_atca_082[], ryu_atca_084[], ryu_atca_086[], ryu_atca_088[], ryu_atca_090[], ryu_atca_092[], ryu_atca_094[], ryu_atca_096[], ryu_atca_098[], ryu_atca_100[], ryu_atca_102[], ryu_atca_104[], ryu_atca_106[], ryu_atca_108[], ryu_atca_144[], ryu_atca_146[], ryu_atca_156[], ryu_atca_157[];
extern const u16 ryu_atca_000_head[];
extern const u16 ryu_atca_001_head[];
extern const u16 ryu_atca_003_head[];
extern const u16 ryu_atca_004_head[];
extern const u16 ryu_atca_005_head[];
extern const u16 ryu_atca_006_head[];
extern const u16 ryu_atca_007_head[];
extern const u16 ryu_atca_008_head[];
extern const u16 ryu_atca_009_head[];
extern const u16 ryu_atca_012_head[];
extern const u16 ryu_atca_013_head[];
extern const u16 ryu_atca_015_head[];
extern const u16 ryu_atca_018_head[];
extern const u16 ryu_atca_021_head[];
extern const u16 ryu_atca_024_head[];
extern const u16 ryu_atca_027_head[];
extern const u16 ryu_atca_030_head[];
extern const u16 ryu_atca_033_head[];
extern const u16 ryu_atca_036_head[];
extern const u16 ryu_atca_038_head[];
extern const u16 ryu_atca_040_head[];
extern const u16 ryu_atca_042_head[];
extern const u16 ryu_atca_044_head[];
extern const u16 ryu_atca_046_head[];
extern const u16 ryu_atca_048_head[];
extern const u16 ryu_atca_050_head[];
extern const u16 ryu_atca_052_head[];
extern const u16 ryu_atca_054_head[];
extern const u16 ryu_atca_056_head[];
extern const u16 ryu_atca_058_head[];
extern const u16 ryu_atca_060_head[];
extern const u16 ryu_atca_062_head[];
extern const u16 ryu_atca_064_head[];
extern const u16 ryu_atca_066_head[];
extern const u16 ryu_atca_068_head[];
extern const u16 ryu_atca_070_head[];
extern const u16 ryu_atca_072_head[];
extern const u16 ryu_atca_074_head[];
extern const u16 ryu_atca_076_head[];
extern const u16 ryu_atca_078_head[];
extern const u16 ryu_atca_080_head[];
extern const u16 ryu_atca_082_head[];
extern const u16 ryu_atca_084_head[];
extern const u16 ryu_atca_086_head[];
extern const u16 ryu_atca_088_head[];
extern const u16 ryu_atca_090_head[];
extern const u16 ryu_atca_092_head[];
extern const u16 ryu_atca_094_head[];
extern const u16 ryu_atca_096_head[];
extern const u16 ryu_atca_098_head[];
extern const u16 ryu_atca_100_head[];
extern const u16 ryu_atca_102_head[];
extern const u16 ryu_atca_104_head[];
extern const u16 ryu_atca_106_head[];
extern const u16 ryu_atca_108_head[];
extern const u16 ryu_atca_144_head[];
extern const u16 ryu_atca_146_head[];
extern const u16 ryu_atca_156_head[];
extern const u16 ryu_atca_157_head[];
extern const u16 ryu_exca_000[], ryu_exca_001[], ryu_exca_003[], ryu_exca_004[], ryu_exca_005[], ryu_exca_006[], ryu_exca_007[], ryu_exca_008[], ryu_exca_009[], ryu_exca_010[], ryu_exca_011[], ryu_exca_013[], ryu_exca_014[], ryu_exca_015[], ryu_exca_016[], ryu_exca_017[], ryu_exca_018[], ryu_exca_019[], ryu_exca_020[], ryu_exca_021[], ryu_exca_022[], ryu_exca_023[], ryu_exca_024[], ryu_exca_025[], ryu_exca_026[], ryu_exca_027[], ryu_exca_028[], ryu_exca_029[], ryu_exca_030[], ryu_exca_032[], ryu_exca_033[], ryu_exca_034[], ryu_exca_035[], ryu_exca_036[], ryu_exca_037[], ryu_exca_038[], ryu_exca_039[], ryu_exca_040[], ryu_exca_041[], ryu_exca_042[], ryu_exca_043[], ryu_exca_044[], ryu_exca_045[], ryu_exca_046[], ryu_exca_047[], ryu_exca_048[], ryu_exca_049[], ryu_exca_050[], ryu_exca_053[], ryu_exca_054[], ryu_exca_055[], ryu_exca_056[];
extern const u16 ryu_exca_000_head[];
extern const u16 ryu_exca_001_head[];
extern const u16 ryu_exca_003_head[];
extern const u16 ryu_exca_004_head[];
extern const u16 ryu_exca_005_head[];
extern const u16 ryu_exca_006_head[];
extern const u16 ryu_exca_007_head[];
extern const u16 ryu_exca_008_head[];
extern const u16 ryu_exca_009_head[];
extern const u16 ryu_exca_010_head[];
extern const u16 ryu_exca_011_head[];
extern const u16 ryu_exca_013_head[];
extern const u16 ryu_exca_014_head[];
extern const u16 ryu_exca_015_head[];
extern const u16 ryu_exca_016_head[];
extern const u16 ryu_exca_017_head[];
extern const u16 ryu_exca_018_head[];
extern const u16 ryu_exca_019_head[];
extern const u16 ryu_exca_020_head[];
extern const u16 ryu_exca_021_head[];
extern const u16 ryu_exca_022_head[];
extern const u16 ryu_exca_023_head[];
extern const u16 ryu_exca_024_head[];
extern const u16 ryu_exca_025_head[];
extern const u16 ryu_exca_026_head[];
extern const u16 ryu_exca_027_head[];
extern const u16 ryu_exca_028_head[];
extern const u16 ryu_exca_029_head[];
extern const u16 ryu_exca_030_head[];
extern const u16 ryu_exca_032_head[];
extern const u16 ryu_exca_033_head[];
extern const u16 ryu_exca_034_head[];
extern const u16 ryu_exca_035_head[];
extern const u16 ryu_exca_036_head[];
extern const u16 ryu_exca_037_head[];
extern const u16 ryu_exca_038_head[];
extern const u16 ryu_exca_039_head[];
extern const u16 ryu_exca_040_head[];
extern const u16 ryu_exca_041_head[];
extern const u16 ryu_exca_042_head[];
extern const u16 ryu_exca_043_head[];
extern const u16 ryu_exca_044_head[];
extern const u16 ryu_exca_045_head[];
extern const u16 ryu_exca_046_head[];
extern const u16 ryu_exca_047_head[];
extern const u16 ryu_exca_048_head[];
extern const u16 ryu_exca_049_head[];
extern const u16 ryu_exca_050_head[];
extern const u16 ryu_exca_053_head[];
extern const u16 ryu_exca_054_head[];
extern const u16 ryu_exca_055_head[];
extern const u16 ryu_exca_056_head[];
extern const u16 ryu_saca_000[], ryu_saca_001[], ryu_saca_002[], ryu_saca_024[], ryu_saca_025[], ryu_saca_026[], ryu_saca_027[], ryu_saca_028[], ryu_saca_029[], ryu_saca_030[], ryu_saca_031[], ryu_saca_032[], ryu_saca_033[], ryu_saca_034[], ryu_saca_035[], ryu_saca_036[], ryu_saca_040[], ryu_saca_041[], ryu_saca_042[], ryu_saca_044[], ryu_saca_048[], ryu_saca_052[], ryu_saca_053[], ryu_saca_054[], ryu_saca_055[], ryu_saca_056[], ryu_saca_060[], ryu_saca_061[], ryu_saca_062[], ryu_saca_063[], ryu_saca_064[], ryu_saca_067[], ryu_saca_068[];
extern const u16 ryu_saca_000_head[];
extern const u16 ryu_saca_001_head[];
extern const u16 ryu_saca_002_head[];
extern const u16 ryu_saca_024_head[];
extern const u16 ryu_saca_025_head[];
extern const u16 ryu_saca_026_head[];
extern const u16 ryu_saca_027_head[];
extern const u16 ryu_saca_028_head[];
extern const u16 ryu_saca_029_head[];
extern const u16 ryu_saca_030_head[];
extern const u16 ryu_saca_031_head[];
extern const u16 ryu_saca_032_head[];
extern const u16 ryu_saca_033_head[];
extern const u16 ryu_saca_034_head[];
extern const u16 ryu_saca_035_head[];
extern const u16 ryu_saca_036_head[];
extern const u16 ryu_saca_040_head[];
extern const u16 ryu_saca_041_head[];
extern const u16 ryu_saca_042_head[];
extern const u16 ryu_saca_044_head[];
extern const u16 ryu_saca_048_head[];
extern const u16 ryu_saca_052_head[];
extern const u16 ryu_saca_053_head[];
extern const u16 ryu_saca_054_head[];
extern const u16 ryu_saca_055_head[];
extern const u16 ryu_saca_056_head[];
extern const u16 ryu_saca_060_head[];
extern const u16 ryu_saca_061_head[];
extern const u16 ryu_saca_062_head[];
extern const u16 ryu_saca_063_head[];
extern const u16 ryu_saca_064_head[];
extern const u16 ryu_saca_067_head[];
extern const u16 ryu_saca_068_head[];
extern const u16 ryu_cbca_000[], ryu_cbca_001[], ryu_cbca_002[], ryu_cbca_003[], ryu_cbca_004[], ryu_cbca_005[], ryu_cbca_006[], ryu_cbca_007[], ryu_cbca_008[], ryu_cbca_009[], ryu_cbca_010[], ryu_cbca_012[], ryu_cbca_013[], ryu_cbca_014[], ryu_cbca_015[], ryu_cbca_016[], ryu_cbca_017[], ryu_cbca_018[], ryu_cbca_019[], ryu_cbca_020[], ryu_cbca_021[], ryu_cbca_022[], ryu_cbca_023[], ryu_cbca_024[], ryu_cbca_025[], ryu_cbca_026[], ryu_cbca_027[], ryu_cbca_028[], ryu_cbca_029[], ryu_cbca_030[], ryu_cbca_031[], ryu_cbca_032[], ryu_cbca_033[], ryu_cbca_034[], ryu_cbca_035[], ryu_cbca_036[], ryu_cbca_037[], ryu_cbca_038[], ryu_cbca_039[], ryu_cbca_040[], ryu_cbca_041[], ryu_cbca_042[], ryu_cbca_043[], ryu_cbca_044[], ryu_cbca_045[], ryu_cbca_046[], ryu_cbca_047[], ryu_cbca_048[], ryu_cbca_049[], ryu_cbca_050[];
extern const u16 ryu_cbca_000_head[];
extern const u16 ryu_cbca_001_head[];
extern const u16 ryu_cbca_002_head[];
extern const u16 ryu_cbca_003_head[];
extern const u16 ryu_cbca_004_head[];
extern const u16 ryu_cbca_005_head[];
extern const u16 ryu_cbca_006_head[];
extern const u16 ryu_cbca_007_head[];
extern const u16 ryu_cbca_008_head[];
extern const u16 ryu_cbca_009_head[];
extern const u16 ryu_cbca_010_head[];
extern const u16 ryu_cbca_012_head[];
extern const u16 ryu_cbca_013_head[];
extern const u16 ryu_cbca_014_head[];
extern const u16 ryu_cbca_015_head[];
extern const u16 ryu_cbca_016_head[];
extern const u16 ryu_cbca_017_head[];
extern const u16 ryu_cbca_018_head[];
extern const u16 ryu_cbca_019_head[];
extern const u16 ryu_cbca_020_head[];
extern const u16 ryu_cbca_021_head[];
extern const u16 ryu_cbca_022_head[];
extern const u16 ryu_cbca_023_head[];
extern const u16 ryu_cbca_024_head[];
extern const u16 ryu_cbca_025_head[];
extern const u16 ryu_cbca_026_head[];
extern const u16 ryu_cbca_027_head[];
extern const u16 ryu_cbca_028_head[];
extern const u16 ryu_cbca_029_head[];
extern const u16 ryu_cbca_030_head[];
extern const u16 ryu_cbca_031_head[];
extern const u16 ryu_cbca_032_head[];
extern const u16 ryu_cbca_033_head[];
extern const u16 ryu_cbca_034_head[];
extern const u16 ryu_cbca_035_head[];
extern const u16 ryu_cbca_036_head[];
extern const u16 ryu_cbca_037_head[];
extern const u16 ryu_cbca_038_head[];
extern const u16 ryu_cbca_039_head[];
extern const u16 ryu_cbca_040_head[];
extern const u16 ryu_cbca_041_head[];
extern const u16 ryu_cbca_042_head[];
extern const u16 ryu_cbca_043_head[];
extern const u16 ryu_cbca_044_head[];
extern const u16 ryu_cbca_045_head[];
extern const u16 ryu_cbca_046_head[];
extern const u16 ryu_cbca_047_head[];
extern const u16 ryu_cbca_048_head[];
extern const u16 ryu_cbca_049_head[];
extern const u16 ryu_cbca_050_head[];

/* normal scripts: 51 entries */
const u16* const ryu_nmca[52] = {
    ryu_nmca_000,  /* 0 KAMAE */
    ryu_nmca_001,  /* 1 HURIMUKI */
    ryu_nmca_002,  /* 2 FRONT WALK */
    ryu_nmca_003,  /* 3 BACK WALK */
    ryu_nmca_004,  /* 4 DASH HUMIKOMI */
    ryu_nmca_005,  /* 5 DASH TOBINOKI */
    ryu_nmca_006,  /* 6 KAGAMU */
    ryu_nmca_007,  /* 7 KAGAMI KAMAE */
    ryu_nmca_008,  /* 8 KAGAMI TURN */
    ryu_nmca_008,  /* 9 KAGAMI F WALK */
    ryu_nmca_008,  /* 10 KAGAMI B WALK */
    ryu_nmca_011,  /* 11 STAND UP */
    ryu_nmca_012,  /* 12 JUMP JUNBI */
    ryu_nmca_013,  /* 13 SP JUMP JUNBI */
    ryu_nmca_014,  /* 14 JUMP FRONT */
    ryu_nmca_015,  /* 15 JUMP VERTICAL */
    ryu_nmca_016,  /* 16 JUMP BACK */
    ryu_nmca_017,  /* 17 S JUMP FRONT */
    ryu_nmca_017,  /* 18 S JUMP V */
    ryu_nmca_017,  /* 19 S JUMP BACK */
    ryu_nmca_020,  /* 20 SP JUMP FRONT */
    ryu_nmca_021,  /* 21 SP JUMP V */
    ryu_nmca_022,  /* 22 SP JUMP BACK */
    ryu_nmca_023,  /* 23 WALK END */
    ryu_nmca_024,  /* 24 PARING HEAD */
    ryu_nmca_024,  /* 25 PARING UP */
    ryu_nmca_026,  /* 26 PARING DOWN */
    ryu_nmca_027,  /* 27 PARING AIR F */
    ryu_nmca_027,  /* 28 PARING AIR B */
    ryu_nmca_029,  /* 29 GUARD HEAD */
    ryu_nmca_030,  /* 30 GUARD UP */
    ryu_nmca_031,  /* 31 GUARD DOWN */
    ryu_nmca_032,  /* 32 GUARD AIR */
    ryu_nmca_033,  /* 33 no name */
    ryu_nmca_033,  /* 34 no name */
    ryu_nmca_033,  /* 35 no name */
    ryu_nmca_033,  /* 36 no name */
    ryu_nmca_033,  /* 37 no name */
    ryu_nmca_038,  /* 38 P BREAK ZUJOU */
    ryu_nmca_038,  /* 39 P BREAK UP */
    ryu_nmca_040,  /* 40 P BREAK DOWN */
    ryu_nmca_041,  /* 41 P BREAK AIR F */
    ryu_nmca_041,  /* 42 P BREAK AIR R */
    ryu_nmca_043,  /* 43 TUKAMIHAZUSI */
    ryu_nmca_044,  /* 44 TUKAMIHAZUSARE */
    ryu_nmca_045,  /* 45 TUKAMIHAZUSI */
    ryu_nmca_046,  /* 46 TUKAMIHAZUSARE */
    ryu_nmca_047,  /* 47 no name */
    ryu_nmca_048,  /* 48 no name */
    ryu_nmca_049,  /* 49 no name */
    ryu_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 ryu_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_000[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C02, 0, 145, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C03, 0, 145, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C04, 0, 145, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C05, 0, 145, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C06, 0, 145, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C07, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C08, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C09, 0, 146, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C0A, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C01, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 ryu_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_001[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C0B, 0, 260, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C0C, 0, 260, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 ryu_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_002[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C10, 0, 237, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C11, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C12, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C13, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C14, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C15, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C16, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C17, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C18, 0, 239, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C19, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C1A, 0, 237, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 ryu_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_003[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C1C, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C1D, 0, 241, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C1E, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C1F, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C20, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C21, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C22, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C23, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C24, 0, 242, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C25, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C26, 0, 240, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 ryu_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_004[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 275, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(4, 1, 277, 0, 0, 0, 0, 0x0C70, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C71, 0, 276, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 2, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C72, 0, 277, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x0C73, 0, 278, 0, 0, 33, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C74, 0, 278, 0, 0, 33, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C75, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C75, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 ryu_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_005[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 10, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C76, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 12, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 277, 0, 0, 0, 0, 0x0C77, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C78, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C79, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C7A, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C7A, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C7B, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C7B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 ryu_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_006[52] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C28, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 151, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2A, 0, 274, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 ryu_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_007[52] = {
    L4(12, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 153, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x0C30, 0, 153, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0C31, 0, 154, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x0C32, 0, 154, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x0C33, 0, 154, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 ryu_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_008[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C3A, 0, 261, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C3B, 0, 261, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C3C, 0, 261, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 ryu_nmca_011_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_011[36] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2D, 0, 152, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 ryu_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C29, 0, 5, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0C29, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C29, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 ryu_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 5, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C29, 0, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 ryu_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_014[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x0C4C, 0, 262, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x0C4D, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0C53, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C54, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C55, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 ryu_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_015[156] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x0C40, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C41, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C6A, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C40, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C41, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C6A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x0C42, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x0C43, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x0C44, 0, 267, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x0C45, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x0C46, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x0C47, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C6B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 ryu_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_016[124] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(10, 0, 281, 0, 0, 0, 0, 0x0C54, 0, 265, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x0C53, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0C4D, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4C, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C58, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 ryu_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 9),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 ryu_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_020[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x0C4C, 0, 262, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 6, 0x0C4D, 0, 263, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0C53, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C54, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C55, 0, 264, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 ryu_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_021[156] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x0C40, 0, 4, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C41, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C6A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C40, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C41, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C6A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x0C42, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x0C43, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0C44, 0, 267, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0C45, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0C46, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x0C47, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C6B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 ryu_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_022[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 282, 0, 0, 0, 0, 0x0C54, 0, 265, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 6, 0x0C53, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x0C4D, 0, 263, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4C, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C58, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 ryu_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 ryu_nmca_024_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_024[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x0D77, 0, 9, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 516, 0, 0, 0, 0, 0x0D78, 0, 10, 0, 0, 0, 6, 0, 0, 0, 14, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0D79, 0, 10, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0D7A, 0, 10, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0D49, 0, 9, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 ryu_nmca_026_head[4] = { HEAD(6, 33, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_026[88] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x0F80, 0, 2, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 516, 0, 0, 0, 0, 0x0F81, 0, 2, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0F82, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F83, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 ryu_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_027[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0C68, 0, 4, 0, 0, 0, 18, 6),
    L4(250, 0, 516, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C6C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C46, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C47, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C6B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 ryu_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_029[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C5A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C5B, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0C5C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C5A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 ryu_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_030[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C5F, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 ryu_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_031[44] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C64, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x0C65, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 ryu_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C68, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 ryu_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_033[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 ryu_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_038[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C61, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 ryu_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_040[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0C65, 0, 2, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C66, 0, 2, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 ryu_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0C68, 0, 4, 0, 0, 0, 18, 8),
    L4(250, 0, 516, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 ryu_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_043[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C61, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 ryu_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_044[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0E80, 0, 1, 0, 0, 0, 0, 0),
    L4(17, 1, 0, 0, 0, 0, 0, 0x0E81, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0E81, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 ryu_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_045[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x0C68, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 516, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C53, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C58, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 ryu_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x0C44, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C45, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0C46, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C47, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C6B, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ryu_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ryu_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x0C29, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2D, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ryu_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2D, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2D, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ryu_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_nmca_050[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C61, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const ryu_dmca[99] = {
    ryu_dmca_000,  /* 0 GUARD HEAD */
    ryu_dmca_001,  /* 1 GUARD UP */
    ryu_dmca_002,  /* 2 GUARD DOWN */
    ryu_dmca_003,  /* 3 GUARD AIR */
    ryu_dmca_004,  /* 4 HUSHIN HEAD */
    ryu_dmca_004,  /* 5 HUSHIN UP */
    ryu_dmca_006,  /* 6 HUSHIN DOWN */
    ryu_dmca_006,  /* 7 HUSHIN AIR */
    ryu_dmca_008,  /* 8 FACE S */
    ryu_dmca_009,  /* 9 FACE M */
    ryu_dmca_010,  /* 10 FACE L */
    ryu_dmca_010,  /* 11 FACE SP */
    ryu_dmca_008,  /* 12 FOOK OKU S */
    ryu_dmca_009,  /* 13 FOOK OKU M */
    ryu_dmca_014,  /* 14 FOOK OKU L */
    ryu_dmca_015,  /* 15 FOOK OKU SP */
    ryu_dmca_008,  /* 16 FOOK TEMAE S */
    ryu_dmca_009,  /* 17 FOOK TEMAE M */
    ryu_dmca_018,  /* 18 FOOK TEMAE L */
    ryu_dmca_019,  /* 19 FOOK TEMAE SP */
    ryu_dmca_008,  /* 20 UPPER S */
    ryu_dmca_009,  /* 21 UPPER M */
    ryu_dmca_022,  /* 22 UPPER L */
    ryu_dmca_022,  /* 23 UPPER SP */
    ryu_dmca_024,  /* 24 NOUTEN S */
    ryu_dmca_025,  /* 25 NOUTEN M */
    ryu_dmca_026,  /* 26 NOUTEN L */
    ryu_dmca_026,  /* 27 NOUTEN SP */
    ryu_dmca_024,  /* 28 BODY BROW S */
    ryu_dmca_029,  /* 29 BODY BROW M */
    ryu_dmca_030,  /* 30 BODY BROW L */
    ryu_dmca_030,  /* 31 BODY BROW SP */
    ryu_dmca_024,  /* 32 BODY UPPER S */
    ryu_dmca_029,  /* 33 BODY UPPER M */
    ryu_dmca_034,  /* 34 BODY UPPER L */
    ryu_dmca_034,  /* 35 BODY UPPER SP */
    ryu_dmca_036,  /* 36 TATAKI S */
    ryu_dmca_036,  /* 37 TATAKI M */
    ryu_dmca_036,  /* 38 TATAKI L */
    ryu_dmca_036,  /* 39 TATAKI SP */
    ryu_dmca_036,  /* 40 TATAKI V. S */
    ryu_dmca_036,  /* 41 TATAKI V. M */
    ryu_dmca_036,  /* 42 TATAKI V. L */
    ryu_dmca_036,  /* 43 TATAKI V. SP */
    ryu_dmca_008,  /* 44 NOBASITA TE S */
    ryu_dmca_009,  /* 45 NOBASITA TE M */
    ryu_dmca_010,  /* 46 NOBASITA TE L */
    ryu_dmca_010,  /* 47 NOBASITA TE SP */
    ryu_dmca_048,  /* 48 KAGAMI S */
    ryu_dmca_049,  /* 49 KAGAMI M */
    ryu_dmca_050,  /* 50 KAGAMI L */
    ryu_dmca_050,  /* 51 KAGAMI SP */
    ryu_dmca_052,  /* 52 KGM TATAKI S */
    ryu_dmca_052,  /* 53 KGM TATAKI M */
    ryu_dmca_052,  /* 54 KGM TATAKI L */
    ryu_dmca_052,  /* 55 KGM TATAKI SP */
    ryu_dmca_052,  /* 56 KGM TTKI V.S */
    ryu_dmca_052,  /* 57 KGM TTKI V.M */
    ryu_dmca_052,  /* 58 KGM TTKI V.L */
    ryu_dmca_052,  /* 59 KGM TTKI V.SP */
    ryu_dmca_060,  /* 60 NEKOROBI S */
    ryu_dmca_060,  /* 61 NEKOROBI M */
    ryu_dmca_060,  /* 62 NEKOROBI L */
    ryu_dmca_060,  /* 63 NEKOROBI SP */
    ryu_dmca_064,  /* 64 OKIAGARI */
    ryu_dmca_065,  /* 65 OKIAGARI F */
    ryu_dmca_066,  /* 66 OKIAGARI B */
    ryu_dmca_067,  /* 67 LOSE NO STAND */
    ryu_dmca_068,  /* 68 LOSE SONABA */
    ryu_dmca_068,  /* 69 LOSE KAGAMI */
    ryu_dmca_070,  /* 70 PIYO */
    ryu_dmca_071,  /* 71 UKEMI MOVE F */
    ryu_dmca_072,  /* 72 UKEMI MOVE R */
    ryu_dmca_073,  /* 73 SHIMEOTASARE */
    ryu_dmca_074,  /* 74 TATI TOUKETU S */
    ryu_dmca_075,  /* 75 TATI TOUKETU M */
    ryu_dmca_076,  /* 76 TATI TOUKETU L */
    ryu_dmca_076,  /* 77 TATI TOUKETU P */
    ryu_dmca_078,  /* 78 KGM TOUKETU S */
    ryu_dmca_079,  /* 79 KGM TOUKETU M */
    ryu_dmca_080,  /* 80 KGM TOUKETU L */
    ryu_dmca_080,  /* 81 KGM TOUKETU P */
    ryu_dmca_082,  /* 82 TATI DENGEKI S */
    ryu_dmca_083,  /* 83 TATI DENGEKI M */
    ryu_dmca_084,  /* 84 TATI DENGEKI L */
    ryu_dmca_084,  /* 85 TATI DENGEKI P */
    ryu_dmca_082,  /* 86 KGM DENGEKI S */
    ryu_dmca_083,  /* 87 KGM DENGEKI M */
    ryu_dmca_084,  /* 88 KGM DENGEKI L */
    ryu_dmca_084,  /* 89 KGM DENGEKI P */
    ryu_dmca_090,  /* 90 OKIAGARI FRONT */
    ryu_dmca_091,  /* 91 OKIAGARI REAR */
    ryu_dmca_008,  /* 92 TATI MOE S */
    ryu_dmca_009,  /* 93 TATI MOE M */
    ryu_dmca_010,  /* 94 TATI MOE L */
    ryu_dmca_010,  /* 95 TATI MOE SP */
    ryu_dmca_096,  /* 96 no name */
    ryu_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 ryu_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_000[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0C5C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C5D, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x0C5E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C5C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C5A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 ryu_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_001[60] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C61, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x0C62, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C60, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C59, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 ryu_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_002[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x0C65, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C66, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x0C67, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C65, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C63, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 ryu_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x0C68, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x0C69, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C69, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 ryu_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_004[44] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 ryu_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_006[52] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C88, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C80, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0C81, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C82, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 ryu_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_008[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C90, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 133, 514, 0, 0, 0, 0, 0x0C90, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C92, 0, 243, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 ryu_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_009[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C91, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 134, 514, 0, 0, 0, 0, 0x0C91, 0, 243, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x0C95, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C96, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C92, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 ryu_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_010[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C99, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 135, 515, 0, 0, 0, 0, 0x0C99, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C9A, 0, 244, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C9B, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C9C, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 ryu_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_014[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C99, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 136, 515, 0, 0, 0, 0, 0x0C99, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0C9A, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x0CA7, 0, 245, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x0CA8, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0CA6, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 ryu_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_015[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C97, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 137, 515, 0, 0, 0, 0, 0x0C98, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0C99, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0C9A, 0, 246, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x0CA7, 0, 246, 0, 0, 0, 0, 0),
    L4(6, 10, 0, 0, 0, 0, 0, 0x0CA8, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0CA6, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 ryu_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_018[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CA0, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 137, 515, 0, 0, 0, 0, 0x0CA0, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0CA2, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0CA3, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0CA4, 0, 246, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x0CA5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0CA6, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 ryu_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_019[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C94, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 138, 515, 0, 0, 0, 0, 0x0CA0, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0CA1, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0CA2, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x0CA3, 0, 246, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x0CA4, 0, 246, 0, 0, 0, 0, 0),
    L4(7, 10, 0, 0, 0, 0, 0, 0x0CA5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x0CA6, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 ryu_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0D20, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 135, 515, 0, 0, 0, 0, 0x0CAF, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CB0, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CB1, 0, 258, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C9C, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C9D, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 ryu_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_025[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CAA, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 134, 514, 0, 0, 0, 0, 0x0CAB, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CAC, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CAD, 0, 249, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 ryu_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_026[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CAB, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 135, 514, 0, 0, 0, 0, 0x0CAB, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CAB, 0, 249, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CAC, 0, 250, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CAD, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 ryu_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_024[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CB3, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 134, 514, 0, 0, 0, 0, 0x0CB4, 0, 247, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CB5, 0, 248, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CB6, 0, 248, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x0CB7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D99, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 ryu_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_029[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CBC, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 136, 514, 0, 0, 0, 0, 0x0CBC, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CBC, 0, 248, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CB4, 0, 247, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CB5, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CB6, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0CB7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D99, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 ryu_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CBB, 0, 247, 0, 0, 0, 0, 0),
    L4(1, 139, 515, 0, 0, 0, 0, 0x0CBE, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CBF, 0, 249, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CC0, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CC1, 0, 249, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CC2, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CC3, 0, 248, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CC4, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CC5, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0D99, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 ryu_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CAD, 0, 250, 0, 0, 0, 0, 0),
    L4(8, 135, 515, 0, 0, 0, 0, 0x0CAE, 0, 255, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CAF, 0, 256, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CB0, 0, 257, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CB1, 0, 258, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C9C, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C9D, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C9E, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 ryu_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D0C, 0, 250, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0D0D, 0, 250, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 ryu_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_048[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CC6, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 133, 514, 0, 0, 0, 0, 0x0CC7, 0, 252, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CC7, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 ryu_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_049[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CCA, 0, 251, 0, 0, 0, 0, 0),
    L4(6, 134, 514, 0, 0, 0, 0, 0x0CCB, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CC7, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CC8, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 ryu_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_050[92] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x0CCD, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CCE, 0, 252, 0, 0, 0, 0, 0),
    L4(4, 135, 515, 0, 0, 0, 0, 0x0CCA, 0, 253, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CCF, 0, 254, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CD0, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C3A, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C3B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C3C, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 ryu_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_052[36] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(1, 132, 0, 0, 0, 0, 0, 0x0CCD, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 0, 515, 0, 0, 0, 0, 0x0CCA, 0, 252, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 ryu_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_060[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CF9, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 515, 0, 0, 0, 0, 0x0CFA, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CFB, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEE, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF5, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 ryu_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 ryu_dmca_064[164] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D40, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D41, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D42, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D43, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D44, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D45, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(6, 12, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0D47, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D48, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 ryu_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 ryu_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E90, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D52, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D53, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0D48, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 ryu_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 ryu_dmca_066[156] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D40, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x0D41, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D52, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0D48, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 ryu_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 ryu_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_068[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C90, 0, 202, 0, 0, 0, 32, 86),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C90, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D30, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D31, 0, 204, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D32, 0, 205, 0, 0, 0, 0, 0),
    L4(6, 0, 289, 0, 0, 0, 0, 0x0D33, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x0D34, 0, 205, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D35, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D36, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D38, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x0D39, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0D3E, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D3F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 ryu_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D11, 0, 269, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D12, 0, 270, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D13, 0, 271, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D14, 0, 271, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D0E, 0, 272, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D0F, 0, 272, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D10, 0, 273, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 ryu_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_071[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D52, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 516, 0, 0, 0, 0, 0x0D4B, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4E, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4F, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D50, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D51, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 72, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 ryu_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_072[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D40, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -11776, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(3, 1, 516, 0, 0, 0, 0, 0x0D4E, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D4B, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D48, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x0D48, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 ryu_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_073[148] = {
    L4(2, 0, 515, 0, 0, 0, 0, 0x0C90, 0, 202, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D30, 0, 203, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D31, 0, 204, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D32, 0, 205, 0, 0, 0, 0, 0),
    L4(3, 0, 289, 0, 0, 0, 0, 0x0D33, 0, 205, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x0D34, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D35, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D36, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D38, 0, 0, 0, 0, 0, 32, 2),
    L4(4, 0, 288, 0, 0, 0, 0, 0x0D39, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D3A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x0D3B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D3D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D3E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0D3F, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D3F, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 ryu_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C90, 0, 243, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C90, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 ryu_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C94, 0, 243, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C94, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 ryu_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0C97, 0, 243, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C97, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 ryu_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CC6, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CC6, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 ryu_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CC9, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CC9, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CC8, 0, 251, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 ryu_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CCC, 0, 251, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CCC, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C3B, 0, 251, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C3C, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C3D, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 ryu_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 ryu_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 ryu_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 206, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 206, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 206, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 ryu_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 ryu_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E90, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0D4B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D52, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0D53, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0D48, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 ryu_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 ryu_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D40, 0, 12, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x0D41, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D52, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D51, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D50, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0D4C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D4B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D46, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D47, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0D48, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 ryu_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_096[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 ryu_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_dmca_097[44] = {
    L4(3, 2, 515, 0, 0, 0, 0, 0x0CF8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF8, 0, 17, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF8, 0, 17, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 17, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 17, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const ryu_btca[37] = {
    ryu_btca_000,  /* 0 AIR NORMAL */
    ryu_btca_001,  /* 1 ASIBARAI SIRI */
    ryu_btca_002,  /* 2 ASIB TUNNOMERI */
    ryu_btca_003,  /* 3 NOKEZORI */
    ryu_btca_004,  /* 4 KUNOJI */
    ryu_btca_005,  /* 5 KIRIMOMI */
    ryu_btca_006,  /* 6 UPPER */
    ryu_btca_007,  /* 7 BODY UPPER */
    ryu_btca_008,  /* 8 HARAYARARE */
    ryu_btca_009,  /* 9 TATAKI AIR */
    ryu_btca_010,  /* 10 TTKI V. AIR */
    ryu_btca_011,  /* 11 HUMI ASIB */
    ryu_btca_012,  /* 12 FACE */
    ryu_btca_013,  /* 13 ASIB SIRI LOSE */
    ryu_btca_014,  /* 14 ASIB TUN LOSE */
    ryu_btca_015,  /* 15 DENKI */
    ryu_btca_016,  /* 16 KUNOJI NOKE */
    ryu_btca_017,  /* 17 BODY UPPER SP */
    ryu_btca_018,  /* 18 HANEAGARI */
    ryu_btca_019,  /* 19 TOUKETSU A */
    ryu_btca_020,  /* 20 BODY SLAM */
    ryu_btca_021,  /* 21 IPPONZEOI */
    ryu_btca_022,  /* 22 TOMOE RYU */
    ryu_btca_023,  /* 23 MONKEY FLIP */
    ryu_btca_024,  /* 24 TOMOE ORO */
    ryu_btca_025,  /* 25 SNAKE FANG */
    ryu_btca_026,  /* 26 FLANKEN.S */
    ryu_btca_027,  /* 27 KISHINRIKI */
    ryu_btca_028,  /* 28 SPLASH.M */
    ryu_btca_029,  /* 29 HARAIGOSHI */
    ryu_btca_030,  /* 30 ALEX B.D */
    ryu_btca_031,  /* 31 GILL */
    ryu_btca_032,  /* 32 HANEKAERI HARA */
    ryu_btca_033,  /* 33 S HANEAGARI */
    ryu_btca_034,  /* 34 TATUMAKIZANKU */
    ryu_btca_035,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 ryu_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_000[68] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CBD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 514, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x0CBD, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x0C53, 0, 207, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 ryu_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_001[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D04, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 7, 0x0D05, 0, 208, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x0D06, 0, 209, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x0D07, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 5, 0x0D08, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 ryu_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_btca_002[60] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D04, 0, 208, 0, 0, 0, 0, 0),
    L4(3, 0, 514, 0, 0, 0, 0, 0x0D05, 0, 208, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D06, 0, 209, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D07, 0, 209, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0D08, 0, 210, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 ryu_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_003[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 ryu_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_004[52] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CBD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 514, 0, 0, 0, 0, 0x0CBE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CBF, 0, 219, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 ryu_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_005[156] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D20, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 515, 0, 0, 0, 0, 0x0D21, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D22, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D23, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D24, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D25, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D26, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D27, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D28, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D29, 0, 221, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2A, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2B, 0, 222, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2C, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2D, 0, 223, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2E, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D2F, 0, 224, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0D2F, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 ryu_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_006[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CAE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0F10, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 ryu_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_007[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0F12, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0F13, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F14, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F15, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 ryu_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_008[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CBD, 0, 207, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0F11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 ryu_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_009[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 515, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 ryu_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_010[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D0B, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 515, 0, 0, 0, 0, 0x0D0C, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D0D, 0, 235, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFF, 0, 219, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 ryu_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 ryu_btca_011[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0D09, 0, 233, 0, 0, 0, 0, 0),
    L4(250, 0, 514, 0, 0, 0, 0, 0x0D0A, 0, 234, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 ryu_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_012[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C91, 0, 230, 0, 0, 0, 0, 0),
    L4(4, 0, 514, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 ryu_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 ryu_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 ryu_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_015[76] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x0F17, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 231, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 231, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 231, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 515, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 ryu_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_016[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CBD, 0, 207, 0, 0, 0, 0, 0),
    L4(3, 0, 514, 0, 0, 0, 0, 0x0CBE, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CBF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CFF, 0, 219, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 ryu_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_017[148] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x0F10, 0, 226, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 515, 0, 0, 0, 0, 0x0F11, 0, 227, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 ryu_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_018[156] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(2, 0, 514, 0, 0, 0, 0, 0x0CEC, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x0CE8, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x0CE7, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x0CE6, 0, 11, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x0CE5, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x0CE3, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x0CEE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x0CF2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 ryu_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0C95, 0, 232, 0, 0, 0, 0, 0),
    L4(250, 0, 514, 0, 0, 0, 0, 0x0C95, 0, 232, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 ryu_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_020[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFA, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 ryu_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_021[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 ryu_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_022[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 1, 0, 0, 0x0D2C, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 236, 0, 0, 0, 32, 99),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 ryu_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x0D2C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 236, 0, 0, 0, 32, 99),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 ryu_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x0D2C, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 236, 0, 0, 0, 32, 99),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEC, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 ryu_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_025[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 236, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 ryu_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_026[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D37, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CE8, 0, 236, 0, 0, 0, 32, 99),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFB, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI */
const u16 ryu_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_027[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x0CE3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0CE4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0CE5, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0CE6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 ryu_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_028[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CEC, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 ryu_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE8, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE8, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 ryu_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_030[116] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0F12, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0F13, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F14, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F15, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0CE4, 0, 236, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0CE5, 0, 236, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 12, 0x0CE6, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x0CE7, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 ryu_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_031[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D04, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 515, 0, 0, 0, 0, 0x0D05, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D06, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D07, 0, 236, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0D08, 0, 236, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 ryu_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x0CBD, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F11, 0, 236, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 ryu_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_033[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x0CEF, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 6), 0, 0, 0, 0,
    L4(3, 0, 514, 0, 0, 0, 0, 0x0CEF, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF0, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CF1, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x0CEE, 0, 11, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF0, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x0CF2, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 TATUMAKIZANKU */
const u16 ryu_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_034[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x0CAE, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 515, 0, 0, 0, 0, 0x0F10, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F11, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE0, 0, 211, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE1, 0, 212, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE2, 0, 213, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name */
const u16 ryu_btca_035_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_btca_035[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x0CE3, 0, 214, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x0CE4, 0, 215, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0CE5, 0, 216, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 15, 0x0CE6, 0, 217, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 218, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 18 entries */
const u16* const ryu_caca[19] = {
    ryu_caca_000,  /* 0 CATCH 1 */
    ryu_caca_000,  /* 1 CATCH 2 */
    ryu_caca_000,  /* 2 CATCH 3 */
    ryu_caca_000,  /* 3 CATCH 4 */
    ryu_caca_004,  /* 4 CATCH 5 */
    ryu_caca_004,  /* 5 CATCH 6 */
    ryu_caca_004,  /* 6 CATCH 7 */
    ryu_caca_004,  /* 7 CATCH 8 */
    ryu_caca_008,  /* 8 CATCH 9 */
    ryu_caca_008,  /* 9 CATCH 10 */
    ryu_caca_010,  /* 10 CATCH 11 */
    ryu_caca_010,  /* 11 CATCH 12 */
    ryu_caca_012,  /* 12 CATCH 13 */
    ryu_caca_012,  /* 13 CATCH 14 */
    ryu_caca_014,  /* 14 CATCH 15 */
    ryu_caca_014,  /* 15 CATCH 16 */
    ryu_caca_014,  /* 16 CATCH 17 */
    ryu_caca_014,  /* 17 CATCH 18 */
    0
};

/* script: 0 CATCH 1, 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 ryu_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ryu_caca_000[232] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x0D60, 0, 0, 0, 0, 0, 0, 0, 256, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 0, 0, 0, 0, 0, 0, 256, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E81, 0, 0, 0, 0, 0, 0, 0, 256, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E82, 0, 0, 0, 0, 0, 0, 0, 256, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0E83, 0, 0, 0, 0, 0, 0, 0, 256, 120, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0E84, 0, 0, 0, 0, 0, 0, 0, 256, 144, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0E85, 0, 0, 0, 0, 0, 0, 0, 256, 168, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0E86, 0, 0, 0, 0, 0, 0, 0, 256, 192, 0, 0, 0),
    L6(2, 0, 517, 0, 0, 0, 0, 0x0E87, 0, 0, 0, 0, 0, 0, 0, 256, 216, 0, 0, 0),
    L6(2, 2, 270, 0, 0, 0, 0, 0x0E88, -47, 0, 0, 0, 0, 0, 0, 256, 240, 0, 0, 0),
    L6(10, 9, 0, 0, 0, 0, 0, 0x0E89, 0, 0, 0, 0, 0, 0, 0, 256, 264, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0E8A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0E8B, 0, 1, 0, 0, 0, 0, 0, 256, 0, 170, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E8C, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0E8D, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5, 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 ryu_caca_004_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 ryu_caca_004[196] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x0D60, 0, 0, 0, 0, 0, 0, 0, 256, 288, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0E81, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0E8E, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 0),
    L6(7, 0, 519, 0, 0, 0, 0, 0x0E8F, 0, 0, 0, 0, 0, 0, 0, 256, 384, 0, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x0E90, 0, 0, 0, 0, 0, 0, 0, 256, 408, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0E91, -49, 0, 0, 0, 0, 0, 0, 256, 432, 0, 0, 0),
    L6(7, 9, 0, 0, 0, 0, 0, 0x0E92, 0, 0, 0, 0, 0, 0, 0, 256, 456, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0E93, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0E94, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E95, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x0E96, 0, 1, 0, 0, 0, 24, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9, 9 CATCH 10 */
const u16 ryu_caca_008_head[4] = { HEAD(6, 0, 19, 0, 0, 0, 1) };
const u16 ryu_caca_008[196] = {
    L6(4, 0, 264, 0, 0, 0, 0, 0x0EB0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB1, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB2, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F16, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F1A, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F1B, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F19, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F18, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F17, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F16, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0EB3, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11, 11 CATCH 12 */
const u16 ryu_caca_010_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ryu_caca_010[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x0D60, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x0E83, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13, 13 CATCH 14 */
const u16 ryu_caca_012_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 ryu_caca_012[76] = {
    CMD(CM_NGDA, 1542, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x0D60, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E81, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E83, 0, 0, 0, 0, 0, 24, 0, 0, 120, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16, 16 CATCH 17, 17 CATCH 18 */
const u16 ryu_caca_014_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 ryu_caca_014[76] = {
    CMD(CM_NGDA, 1542, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0x0D60, 0, 0, 0, 0, 0, 0, 0, 256, 288, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0E81, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(5, 6, 0, 0, 0, 0, 0, 0x0E8E, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 24),
    CMD(CM_JMP, 2, 4, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const ryu_cuca[69] = {
    ryu_cuca_000,  /* 0 ALEX ZUTUKI */
    ryu_cuca_001,  /* 1 ALEX BODY S */
    ryu_cuca_002,  /* 2 ALEX BACK D */
    ryu_cuca_003,  /* 3 ALEX POWER B */
    ryu_cuca_004,  /* 4 ALEX SLEEPER */
    ryu_cuca_005,  /* 5 RYU SEOINAGE */
    ryu_cuca_006,  /* 6 IBUKI */
    ryu_cuca_007,  /* 7 DADLEY L B */
    ryu_cuca_008,  /* 8 IBUKI KUBIORI */
    ryu_cuca_009,  /* 9 NECRO S T */
    ryu_cuca_010,  /* 10 RYU TOMOENAGE */
    ryu_cuca_011,  /* 11 YUN HIZAGERI */
    ryu_cuca_012,  /* 12 ORO KUBISIME */
    ryu_cuca_013,  /* 13 NECRO G S */
    ryu_cuca_014,  /* 14 DUDDLEY D S */
    ryu_cuca_015,  /* 15 YUN MONKEY F */
    ryu_cuca_016,  /* 16 ORO TOMOENAGE */
    ryu_cuca_017,  /* 17 ORO NIOURIKI */
    ryu_cuca_018,  /* 18 ORO GIGOKU G */
    ryu_cuca_019,  /* 19 YUN */
    ryu_cuca_020,  /* 20 NECRO SNAKE F */
    ryu_cuca_021,  /* 21 NECRO F S */
    ryu_cuca_022,  /* 22 IBUKI HARAIG */
    ryu_cuca_023,  /* 23 GILL SPLASH M */
    ryu_cuca_024,  /* 24 KEN HIZAGERI */
    ryu_cuca_025,  /* 25 ORO KISINRIKI */
    ryu_cuca_026,  /* 26 SEAN TACKLE */
    ryu_cuca_027,  /* 27 ALEX HYPER B */
    ryu_cuca_028,  /* 28 NECRO SLAM D */
    ryu_cuca_029,  /* 29 ELENA ASINAGE */
    ryu_cuca_030,  /* 30 GILL IMPACT C */
    ryu_cuca_031,  /* 31 ALEX S H B */
    ryu_cuca_032,  /* 32 ALEX F N D */
    ryu_cuca_033,  /* 33 no name */
    ryu_cuca_034,  /* 34 IBUKI */
    ryu_cuca_035,  /* 35 IBUKI YOROI D */
    ryu_cuca_036,  /* 36 no name */
    ryu_cuca_037,  /* 37 MAWARIKOMI M F */
    ryu_cuca_038,  /* 38 HUGO BODY S */
    ryu_cuca_039,  /* 39 HUGO N G T */
    ryu_cuca_040,  /* 40 HUGO M S P */
    ryu_cuca_041,  /* 41 HUGO S D B B */
    ryu_cuca_042,  /* 42 no name */
    ryu_cuca_043,  /* 43 no name */
    ryu_cuca_044,  /* 44 no name */
    ryu_cuca_045,  /* 45 no name */
    ryu_cuca_046,  /* 46 no name */
    ryu_cuca_047,  /* 47 no name */
    ryu_cuca_048,  /* 48 no name */
    ryu_cuca_049,  /* 49 no name */
    ryu_cuca_050,  /* 50 no name */
    ryu_cuca_051,  /* 51 no name */
    ryu_cuca_052,  /* 52 no name */
    ryu_cuca_053,  /* 53 no name */
    ryu_cuca_054,  /* 54 no name */
    ryu_cuca_055,  /* 55 no name */
    ryu_cuca_056,  /* 56 no name */
    ryu_cuca_057,  /* 57 no name */
    ryu_cuca_058,  /* 58 no name */
    ryu_cuca_059,  /* 59 no name */
    ryu_cuca_060,  /* 60 no name */
    ryu_cuca_061,  /* 61 no name */
    ryu_cuca_062,  /* 62 no name */
    ryu_cuca_063,  /* 63 no name */
    ryu_cuca_064,  /* 64 no name */
    ryu_cuca_065,  /* 65 no name */
    ryu_cuca_066,  /* 66 no name */
    ryu_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 ryu_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAA),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CAB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 ryu_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D37),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D03),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D01),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CED),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 ryu_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_002[80] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CEA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 ryu_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_003[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C9A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D08),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEB),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CEB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 ryu_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CAA),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CAA),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 ryu_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D09),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE7),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CEE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 ryu_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C79),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D60),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D63),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D84),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 ryu_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CC0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 ryu_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C93),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0D20),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 ryu_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 ryu_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0D2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 ryu_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 ryu_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C4B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 ryu_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEB),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CEB),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 ryu_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBF),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CFF),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 ryu_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D01),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0D2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 ryu_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0D2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 ryu_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C9A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C9B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE2),
    L2(250, 2, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CEA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 ryu_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D4B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D4D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D4E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D50),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D51),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D52),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D4B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF9),
    L2(250, 3, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 ryu_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0C01),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 ryu_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C5A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C5B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C5C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C76),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C87),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C86),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C85),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE4),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 ryu_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C76),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C75),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CB3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 ryu_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE7),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 ryu_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CEB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 ryu_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 ryu_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C9A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C9B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE2),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 ryu_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 3, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF7),
    L2(250, 3, 0, 0, 0, 0, 0, 0x0CFA),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CF7),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 ryu_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_027[152] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEB),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CEB),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 ryu_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CF3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE4),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 ryu_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C93),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D00),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0D01),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 ryu_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F11),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F11),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0F10),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0F10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 ryu_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAB),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CAB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 ryu_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_032[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 ryu_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_033[84] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CEA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 2),
    CMD(CM_JMP, 6, 30, 11),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 ryu_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D09),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D09),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB0),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CB0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 ryu_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C79),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C7A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C74),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D60),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D63),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D84),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D82),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D83),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 ryu_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_036[160] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C93),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0CB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CED),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF3),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CF2),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 ryu_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CBE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CBF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x0CC0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 ryu_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D37),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D38),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CF9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CF9),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CFC),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 ryu_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFC),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 ryu_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D2B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF5),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CF6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 ryu_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE7),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 ryu_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 ryu_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF8),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CF8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 ryu_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D2B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CF0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D2F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D0A),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CF6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 33, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 ryu_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 ryu_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D2B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D2B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CEF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0D03),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 ryu_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_047[124] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEA),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CEA),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 ryu_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C93),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAA),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CAB),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 ryu_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C4D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D00),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 3, 0, 0, 0x0D00),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 ryu_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_050[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C4C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F12),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F12),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CEE),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE8),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 ryu_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C79),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA7),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CB4),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 ryu_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0EAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D0A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0F15),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D43),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D36),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFB),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0D2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 ryu_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_053[116] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CAF),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D06),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE9),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE9),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 ryu_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D21),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F11),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F10),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0F10),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 ryu_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CAF),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0CE5),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 ryu_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_056[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 2, 0, 0, 0, 0, 0, 0x0C90),
    CMD(CM_RMJA, 3, 56, 12),
    L2(250, 9, 0, 0, 0, 0, 10, 0x0D06),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 ryu_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 ryu_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_058[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBA),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CFC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0F15),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 3, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 ryu_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C59),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C75),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C5A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C5F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C61),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C62),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D05),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 ryu_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0C92),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 ryu_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D04),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D00),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0D06),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 ryu_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C94),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA2),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA3),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA4),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA5),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA6),
    CMD(CM_PA_X, 0, -8192, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CC4),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_PS_Y, 0, 0, 120),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D06),
    CMD(CM_PA_X, 0, 1536, 0),
    CMD(CM_PS_Y, 0, 0, 86),
    L2(250, 0, 0, 0, 2, 0, 0, 0x0D07),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CE9),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CEC),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CED),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 ryu_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBD),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 514, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 ryu_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C92),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CC5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CBB),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CBE),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 ryu_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C97),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C98),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C99),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C9A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x0CA6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0CEE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x0D01),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x0D2C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 ryu_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CA1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CFB),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 ryu_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C90),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C91),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C95),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0C96),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x0CAF),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x0CE3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 158 entries */
const u16* const ryu_atca[159] = {
    ryu_atca_000,  /* 0 S PUNCH A */
    ryu_atca_001,  /* 1 S PUNCH B */
    ryu_atca_001,  /* 2 S PUNCH C */
    ryu_atca_003,  /* 3 M PUNCH A */
    ryu_atca_004,  /* 4 M PUNCH B */
    ryu_atca_005,  /* 5 M PUNCH C */
    ryu_atca_006,  /* 6 L PUNCH A */
    ryu_atca_007,  /* 7 L PUNCH B */
    ryu_atca_008,  /* 8 L PUNCH C */
    ryu_atca_009,  /* 9 S KICK A */
    ryu_atca_009,  /* 10 S KICK B */
    ryu_atca_009,  /* 11 S KICK C */
    ryu_atca_012,  /* 12 M KICK A */
    ryu_atca_013,  /* 13 M KICK B */
    ryu_atca_013,  /* 14 M KICK C */
    ryu_atca_015,  /* 15 L KICK A */
    ryu_atca_015,  /* 16 L KICK B */
    ryu_atca_015,  /* 17 L KICK C */
    ryu_atca_018,  /* 18 KAGAMI P A */
    ryu_atca_018,  /* 19 KAGAMI P B */
    ryu_atca_018,  /* 20 KAGAMI P C */
    ryu_atca_021,  /* 21 KAGAMI P A */
    ryu_atca_021,  /* 22 KAGAMI P B */
    ryu_atca_021,  /* 23 KAGAMI P C */
    ryu_atca_024,  /* 24 KAGAMI P A */
    ryu_atca_024,  /* 25 KAGAMI P B */
    ryu_atca_024,  /* 26 KAGAMI P C */
    ryu_atca_027,  /* 27 KAGAMI K A */
    ryu_atca_027,  /* 28 KAGAMI K B */
    ryu_atca_027,  /* 29 KAGAMI K C */
    ryu_atca_030,  /* 30 KAGAMI K A */
    ryu_atca_030,  /* 31 KAGAMI K B */
    ryu_atca_030,  /* 32 KAGAMI K C */
    ryu_atca_033,  /* 33 KAGAMI K A */
    ryu_atca_033,  /* 34 KAGAMI K B */
    ryu_atca_033,  /* 35 KAGAMI K C */
    ryu_atca_036,  /* 36 V JUMP P S A */
    ryu_atca_036,  /* 37 V JUMP P S B */
    ryu_atca_038,  /* 38 V JUMP P M A */
    ryu_atca_038,  /* 39 V JUMP P M B */
    ryu_atca_040,  /* 40 V JUMP P L A */
    ryu_atca_040,  /* 41 V JUMP P L B */
    ryu_atca_042,  /* 42 V JUMP K S A */
    ryu_atca_042,  /* 43 V JUMP K S B */
    ryu_atca_044,  /* 44 V JUMP K M A */
    ryu_atca_044,  /* 45 V JUMP K M B */
    ryu_atca_046,  /* 46 V JUMP K L A */
    ryu_atca_046,  /* 47 V JUMP K L B */
    ryu_atca_048,  /* 48 F JUMP P S A */
    ryu_atca_048,  /* 49 F JUMP P S B */
    ryu_atca_050,  /* 50 F JUMP P M A */
    ryu_atca_050,  /* 51 F JUMP P M B */
    ryu_atca_052,  /* 52 F JUMP P L A */
    ryu_atca_052,  /* 53 F JUMP P L B */
    ryu_atca_054,  /* 54 F JUMP K S A */
    ryu_atca_054,  /* 55 F JUMP K S B */
    ryu_atca_056,  /* 56 F JUMP K M A */
    ryu_atca_056,  /* 57 F JUMP K M B */
    ryu_atca_058,  /* 58 F JUMP K L A */
    ryu_atca_058,  /* 59 F JUMP K L B */
    ryu_atca_060,  /* 60 B JUMP P S A */
    ryu_atca_060,  /* 61 B JUMP P S B */
    ryu_atca_062,  /* 62 B JUMP P M A */
    ryu_atca_062,  /* 63 B JUMP P M B */
    ryu_atca_064,  /* 64 B JUMP P L A */
    ryu_atca_064,  /* 65 B JUMP P L B */
    ryu_atca_066,  /* 66 B JUMP K S A */
    ryu_atca_066,  /* 67 B JUMP K S B */
    ryu_atca_068,  /* 68 B JUMP K M A */
    ryu_atca_068,  /* 69 B JUMP K M B */
    ryu_atca_070,  /* 70 B JUMP K L A */
    ryu_atca_070,  /* 71 B JUMP K L B */
    ryu_atca_072,  /* 72 SP V JP S P A */
    ryu_atca_072,  /* 73 SP V JP S P B */
    ryu_atca_074,  /* 74 SP V JP M P A */
    ryu_atca_074,  /* 75 SP V JP M P B */
    ryu_atca_076,  /* 76 SP V JP L P A */
    ryu_atca_076,  /* 77 SP V JP L P B */
    ryu_atca_078,  /* 78 SP V JP S K A */
    ryu_atca_078,  /* 79 SP V JP S K B */
    ryu_atca_080,  /* 80 SP V JP M K A */
    ryu_atca_080,  /* 81 SP V JP M K B */
    ryu_atca_082,  /* 82 SP V JP L K A */
    ryu_atca_082,  /* 83 SP V JP L K B */
    ryu_atca_084,  /* 84 SP F JP S P A */
    ryu_atca_084,  /* 85 SP F JP S P B */
    ryu_atca_086,  /* 86 SP F JP M P A */
    ryu_atca_086,  /* 87 SP F JP M P B */
    ryu_atca_088,  /* 88 SP F JP L P A */
    ryu_atca_088,  /* 89 SP F JP L P B */
    ryu_atca_090,  /* 90 SP F JP S K A */
    ryu_atca_090,  /* 91 SP F JP S K B */
    ryu_atca_092,  /* 92 SP F JP M K A */
    ryu_atca_092,  /* 93 SP F JP M K B */
    ryu_atca_094,  /* 94 SP F JP L K A */
    ryu_atca_094,  /* 95 SP F JP L K B */
    ryu_atca_096,  /* 96 SP B JP S P A */
    ryu_atca_096,  /* 97 SP B JP S P B */
    ryu_atca_098,  /* 98 SP B JP M P A */
    ryu_atca_098,  /* 99 SP B JP M P B */
    ryu_atca_100,  /* 100 SP B JP L P A */
    ryu_atca_100,  /* 101 SP B JP L P B */
    ryu_atca_102,  /* 102 SP B JP S K A */
    ryu_atca_102,  /* 103 SP B JP S K B */
    ryu_atca_104,  /* 104 SP B JP M K A */
    ryu_atca_104,  /* 105 SP B JP M K B */
    ryu_atca_106,  /* 106 SP B JP L K A */
    ryu_atca_106,  /* 107 SP B JP L K B */
    ryu_atca_108,  /* 108 S V JP S P A */
    ryu_atca_108,  /* 109 S V JP S P B */
    ryu_atca_108,  /* 110 S V JP M P A */
    ryu_atca_108,  /* 111 S V JP M P B */
    ryu_atca_108,  /* 112 S V JP L P A */
    ryu_atca_108,  /* 113 S V JP L P B */
    ryu_atca_108,  /* 114 S V JP S K A */
    ryu_atca_108,  /* 115 S V JP S K B */
    ryu_atca_108,  /* 116 S V JP M K A */
    ryu_atca_108,  /* 117 S V JP M K B */
    ryu_atca_108,  /* 118 S V JP L K A */
    ryu_atca_108,  /* 119 S V JP L K B */
    ryu_atca_108,  /* 120 S F JP S P A */
    ryu_atca_108,  /* 121 S F JP S P B */
    ryu_atca_108,  /* 122 S F JP M P A */
    ryu_atca_108,  /* 123 S F JP M P B */
    ryu_atca_108,  /* 124 S F JP L P A */
    ryu_atca_108,  /* 125 S F JP L P B */
    ryu_atca_108,  /* 126 S F JP S K A */
    ryu_atca_108,  /* 127 S F JP S K B */
    ryu_atca_108,  /* 128 S F JP M K A */
    ryu_atca_108,  /* 129 S F JP M K B */
    ryu_atca_108,  /* 130 S F JP L K A */
    ryu_atca_108,  /* 131 S F JP L K B */
    ryu_atca_108,  /* 132 S B JP S P A */
    ryu_atca_108,  /* 133 S B JP S P B */
    ryu_atca_108,  /* 134 S B JP M P A */
    ryu_atca_108,  /* 135 S B JP M P B */
    ryu_atca_108,  /* 136 S B JP L P A */
    ryu_atca_108,  /* 137 S B JP L P B */
    ryu_atca_108,  /* 138 S B JP S K A */
    ryu_atca_108,  /* 139 S B JP S K B */
    ryu_atca_108,  /* 140 S B JP M K A */
    ryu_atca_108,  /* 141 S B JP M K B */
    ryu_atca_108,  /* 142 S B JP L K A */
    ryu_atca_108,  /* 143 S B JP L K B */
    ryu_atca_144,  /* 144 TUKAMIKAKARI A */
    ryu_atca_144,  /* 145 TUKAMIKAKARI B */
    ryu_atca_146,  /* 146 TUKAMIKAKARI C */
    ryu_atca_144,  /* 147 TUKAMIKAKARI D */
    ryu_atca_144,  /* 148 TUKAMIKAKARI E */
    ryu_atca_144,  /* 149 TUKAMIKAKARI F */
    ryu_atca_144,  /* 150 TUKAMI AIR A */
    ryu_atca_144,  /* 151 TUKAMI AIR B */
    ryu_atca_144,  /* 152 TUKAMI AIR C */
    ryu_atca_144,  /* 153 TUKAMI AIR D */
    ryu_atca_144,  /* 154 TUKAMI AIR E */
    ryu_atca_144,  /* 155 TUKAMI AIR F */
    ryu_atca_156,  /* 156 follow-up of L PUNCH B */
    ryu_atca_157,  /* 157 no name */
    0
};

/* script: 0 S PUNCH A */
const u16 ryu_atca_000_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 ryu_atca_000[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D80, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0D81, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D82, -3, 19, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D83, 0, 20, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D83, 0, 21, 272, 0, 8, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D84, 0, 1, 272, 0, 8, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0D86, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D86, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 ryu_atca_001_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 ryu_atca_001[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D60, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D63, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D60, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0D61, -4, 22, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D62, 0, 22, 272, 0, 120, 0, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D62, 0, 23, 272, 0, 120, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D63, 0, 1, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0D64, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D64, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A */
const u16 ryu_atca_003_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 ryu_atca_003[76] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D88, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0D89, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D8A, -5, 24, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D8B, 0, 24, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D9B, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D8C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C75, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C75, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 M PUNCH B */
const u16 ryu_atca_004_head[4] = { HEAD(4, 0, 2, 12, 0, 1, 0) };
const u16 ryu_atca_004[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D66, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0D67, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D68, -6, 25, 0, 133, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D69, 0, 26, 0, 128, 96, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D7B, 0, 27, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D6A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0D6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 ryu_atca_005_head[4] = { HEAD(4, 0, 2, 10, 0, 2, 1) };
const u16 ryu_atca_005[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0F26, 0, 1, 0, 0, 0, 32, 77),
    L4(7, 0, 516, 0, 0, 0, 0, 0x0F27, 0, 1, 0, 0, 0, 32, 78),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F28, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x0F29, -50, 28, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F2A, -51, 29, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F2B, 0, 29, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0F2C, 0, 29, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0F2D, 0, 30, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0F2E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A */
const u16 ryu_atca_006_head[4] = { HEAD(4, 0, 4, 9, 0, 1, 0) };
const u16 ryu_atca_006[116] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D8D, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x0D8E, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 517, 0, 0, 0, 0, 0x0D8F, 0, 31, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D90, -7, 32, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D91, 0, 32, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D92, 8, 33, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D93, 0, 34, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0D94, 0, 34, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D95, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D96, 0, 34, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0D97, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D98, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D99, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D99, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 L PUNCH B */
const u16 ryu_atca_007_head[4] = { HEAD(4, 0, 4, 11, 0, 1, 0) };
const u16 ryu_atca_007[116] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D6C, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D6D, 0, 35, 0, 0, 0, 32, 16),
    L4(3, 0, 517, 1, 0, 0, 0, 0x0D6E, 0, 35, 0, 0, 0, 32, 17),
    L4(3, 0, 270, 1, 0, 0, 0, 0x0D6F, 0, 35, 0, 0, 0, 32, 18),
    L4(2, 0, 0, 1, 0, 0, 0, 0x0D70, -9, 36, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x0D71, 0, 36, 3215, 0, 8, 32, 18),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0D72, 0, 35, 2048, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D73, 0, 35, 2048, 0, 0, 32, 19),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D7D, 0, 35, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0D74, 0, 35, 0, 0, 0, 32, 20),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D75, 0, 35, 0, 0, 0, 32, 21),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 ryu_atca_008_head[4] = { HEAD(4, 0, 4, 11, 0, 1, 0) };
const u16 ryu_atca_008[164] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F70, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F71, 0, 1, 0, 0, 0, 32, 43),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0F72, 0, 140, 0, 0, 0, 30, 112),
    L4(5, 0, 517, 0, 0, 0, 0, 0x0F73, 0, 140, 0, 0, 0, 32, 44),
    L4(4, 0, 270, 0, 0, 0, 0, 0x0F74, 0, 140, 0, 0, 0, 32, 44),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F75, -14, 141, 0, 137, 0, 32, 43),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F76, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F77, -15, 142, 0, 76, 0, 32, 45),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F77, 0, 143, 0, 0, 0, 32, 46),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F78, 0, 144, 0, 0, 0, 32, 44),
    CMD(CM_ASXY, 88, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F79, 0, 144, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F7A, 0, 144, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F7B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0F7C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F7D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F7E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0F7E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 ryu_atca_009_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 0) };
const u16 ryu_atca_009[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DC0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x0DC1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DC2, -10, 37, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DC3, 0, 38, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DC4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 ryu_atca_012_head[4] = { HEAD(4, 0, 3, 11, 0, 1, 0) };
const u16 ryu_atca_012[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DC0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x0DC8, 0, 39, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DC9, 0, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DCA, -12, 40, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DCB, 0, 40, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0DCC, 0, 41, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DCD, 0, 39, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DC5, 0, 39, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0DC6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0DC6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B, 14 M KICK C */
const u16 ryu_atca_013_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 ryu_atca_013[108] = {
    CMD(CM_RMJA, 4, 15, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DA8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DA9, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x0DA9, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DAA, -13, 43, 0, 128, 0, 32, 23),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DAB, 0, 44, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DBD, 0, 45, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DAC, 0, 42, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DAF, 0, 42, 0, 0, 0, 32, 24),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DAD, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DAE, 0, 1, 3215, 0, 24, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B, 17 L KICK C */
const u16 ryu_atca_015_head[4] = { HEAD(4, 0, 5, 13, 6, 1, 0) };
const u16 ryu_atca_015[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DB0, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DB1, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 516, 0, 0, 0, 0, 0x0DB2, 0, 46, 0, 0, 0, 32, 25),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DB3, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 270, 1, 0, 0, 0, 0x0DB4, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 0, 1, 0, 0, 0, 0x0DB5, 0, 48, 0, 0, 0, 32, 25),
    L4(2, 0, 0, 1, 0, 0, 0, 0x0DB6, -17, 47, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x0DB7, 0, 47, 0, 0, 0, 32, 27),
    CMD(CM_ASXY, 56, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DB8, 0, 48, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DBE, 0, 48, 0, 0, 0, 32, 29),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DB9, 0, 46, 0, 0, 0, 32, 30),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DBA, 0, 1, 0, 0, 0, 32, 28),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DBB, 0, 1, 0, 0, 0, 32, 28),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DBC, 0, 1, 0, 0, 0, 32, 29),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0DBC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 ryu_atca_018_head[4] = { HEAD(4, 32, 0, 9, 0, 1, 0) };
const u16 ryu_atca_018[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DF0, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0DF1, -19, 51, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF2, 0, 51, 272, 0, 120, 0, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF4, 0, 52, 272, 0, 24, 21, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF3, 0, 2, 272, 0, 24, 0, 3),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 ryu_atca_021_head[4] = { HEAD(4, 32, 2, 10, 0, 1, 0) };
const u16 ryu_atca_021[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DF0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0DF0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DF1, -20, 53, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DF2, 0, 51, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF2, 0, 52, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF4, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DF3, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0DF0, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 ryu_atca_024_head[4] = { HEAD(4, 32, 4, 9, 0, 1, 0) };
const u16 ryu_atca_024[108] = {
    L4(3, 0, 517, 0, 0, 0, 0, 0x0DFC, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x0DFD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DFE, -21, 54, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DFF, 22, 55, 0, 128, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E00, 0, 56, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0E00, 0, 57, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E01, 0, 57, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E02, 0, 58, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E03, 0, 59, 0, 0, 0, 22, 32),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E04, 0, 59, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 ryu_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 ryu_atca_027[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E11, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x0E11, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E12, -23, 60, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E13, 0, 60, 272, 0, 120, 0, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E14, 0, 2, 272, 0, 24, 21, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E11, 0, 2, 272, 0, 24, 0, 1),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0E10, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E10, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0E15, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 ryu_atca_030_head[4] = { HEAD(4, 32, 3, 13, 0, 1, 0) };
const u16 ryu_atca_030[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E16, 0, 2, 0, 0, 0, 32, 31),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E24, 0, 2, 0, 0, 0, 32, 31),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0E17, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E18, -24, 61, 0, 135, 96, 32, 32),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E19, 0, 62, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E1A, 0, 62, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E1A, 0, 63, 0, 0, 96, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E1B, 0, 2, 0, 0, 0, 32, 33),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E24, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E25, 0, 2, 0, 0, 0, 32, 34),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 32, 34),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 ryu_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 1, 0) };
const u16 ryu_atca_033[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E16, 0, 2, 0, 0, 0, 32, 35),
    L4(2, 0, 516, 0, 0, 0, 0, 0x0E1C, 0, 2, 0, 0, 0, 32, 36),
    L4(2, 0, 270, 0, 0, 0, 0, 0x0E1D, 0, 2, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E1E, -25, 64, 0, 64, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E1F, 0, 64, 0, 64, 0, 0, 0),
    CMD(CM_ASXY, 74, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E20, 0, 65, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E21, 0, 65, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E22, 0, 2, 0, 0, 0, 32, 39),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E23, 0, 2, 0, 0, 0, 32, 40),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E24, 0, 2, 0, 0, 0, 32, 41),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E25, 0, 2, 0, 0, 0, 32, 42),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 32, 42),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 ryu_atca_036_head[4] = { HEAD(4, 22, 0, 7, 0, 1, 0) };
const u16 ryu_atca_036[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x0E30, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 7, 0x0E31, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0E32, -26, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E33, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E34, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E35, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E33, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E34, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E35, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 ryu_atca_038_head[4] = { HEAD(4, 22, 2, 10, 0, 1, 0) };
const u16 ryu_atca_038[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E41, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0E42, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E43, -27, 70, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E44, 0, 71, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E48, 0, 72, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E45, 0, 73, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E46, 0, 69, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 ryu_atca_040_head[4] = { HEAD(4, 22, 4, 13, 0, 1, 0) };
const u16 ryu_atca_040[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E4E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0E4F, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E50, -28, 104, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E51, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E53, 0, 106, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E54, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 ryu_atca_042_head[4] = { HEAD(4, 22, 1, 6, 0, 1, 0) };
const u16 ryu_atca_042[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0E60, -29, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E64, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 ryu_atca_044_head[4] = { HEAD(4, 22, 3, 12, 0, 1, 0) };
const u16 ryu_atca_044[100] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 269, 0, 0, 0, 0, 0x0E6D, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E6E, -30, 109, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E6F, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E70, 0, 110, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E70, 0, 111, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E71, 0, 111, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E72, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 ryu_atca_046_head[4] = { HEAD(4, 22, 5, 12, 0, 1, 0) };
const u16 ryu_atca_046[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E73, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0E74, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E75, -31, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E76, 0, 113, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0E77, 0, 114, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E78, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C47, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B */
const u16 ryu_atca_048_head[4] = { HEAD(4, 20, 0, 8, 0, 1, 0) };
const u16 ryu_atca_048[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 7, 0x0E30, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 7, 0x0E31, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x0E32, -32, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E33, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E34, 0, 67, 0, 137, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x0E35, 0, 67, 0, 137, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E33, 0, 68, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E34, 0, 68, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E35, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 ryu_atca_050_head[4] = { HEAD(4, 20, 2, 10, 0, 2, 0) };
const u16 ryu_atca_050[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E37, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0E37, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E38, -1, 100, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E39, -2, 101, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E3A, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E3F, 0, 102, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E3B, 0, 103, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E3C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E3D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E3E, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 ryu_atca_052_head[4] = { HEAD(4, 20, 4, 12, 0, 1, 0) };
const u16 ryu_atca_052[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E41, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0E42, 0, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E43, -34, 98, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E44, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E48, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E45, 0, 73, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E46, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 ryu_atca_054_head[4] = { HEAD(4, 20, 1, 7, 0, 1, 0) };
const u16 ryu_atca_054[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0E60, -35, 107, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E61, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E62, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E63, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E64, 0, 4, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 ryu_atca_056_head[4] = { HEAD(4, 20, 3, 12, 0, 1, 0) };
const u16 ryu_atca_056[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0E66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E67, -36, 115, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E68, 0, 116, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E69, 0, 116, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E6A, 0, 117, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E6B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 ryu_atca_058_head[4] = { HEAD(4, 20, 5, 13, 0, 1, 0) };
const u16 ryu_atca_058[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x0E66, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E67, -37, 118, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E68, 0, 119, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E69, 0, 119, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E6A, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E6B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 ryu_atca_060_head[4] = { HEAD(2, 24, 0, 7, 0, 1, 0) };
const u16 ryu_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 ryu_atca_062_head[4] = { HEAD(2, 24, 2, 8, 0, 2, 0) };
const u16 ryu_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 ryu_atca_064_head[4] = { HEAD(2, 24, 4, 11, 0, 1, 0) };
const u16 ryu_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 ryu_atca_066_head[4] = { HEAD(2, 24, 1, 6, 0, 1, 0) };
const u16 ryu_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 ryu_atca_068_head[4] = { HEAD(2, 24, 3, 11, 0, 1, 0) };
const u16 ryu_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 ryu_atca_070_head[4] = { HEAD(2, 24, 5, 13, 0, 1, 0) };
const u16 ryu_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 ryu_atca_072_head[4] = { HEAD(2, 28, 0, 7, 0, 1, 0) };
const u16 ryu_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 ryu_atca_074_head[4] = { HEAD(2, 28, 2, 10, 0, 1, 0) };
const u16 ryu_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 ryu_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 ryu_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 ryu_atca_078_head[4] = { HEAD(2, 28, 1, 6, 0, 1, 0) };
const u16 ryu_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 ryu_atca_080_head[4] = { HEAD(2, 28, 3, 12, 0, 1, 0) };
const u16 ryu_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 ryu_atca_082_head[4] = { HEAD(2, 28, 5, 10, 0, 1, 0) };
const u16 ryu_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 ryu_atca_084_head[4] = { HEAD(2, 26, 0, 8, 0, 1, 0) };
const u16 ryu_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 ryu_atca_086_head[4] = { HEAD(2, 26, 2, 9, 0, 2, 0) };
const u16 ryu_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 ryu_atca_088_head[4] = { HEAD(2, 26, 4, 12, 0, 1, 0) };
const u16 ryu_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 ryu_atca_090_head[4] = { HEAD(2, 26, 1, 7, 0, 1, 0) };
const u16 ryu_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 ryu_atca_092_head[4] = { HEAD(2, 26, 3, 12, 0, 1, 0) };
const u16 ryu_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 ryu_atca_094_head[4] = { HEAD(2, 26, 5, 13, 0, 1, 0) };
const u16 ryu_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 ryu_atca_096_head[4] = { HEAD(2, 30, 0, 7, 0, 1, 0) };
const u16 ryu_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 ryu_atca_098_head[4] = { HEAD(2, 30, 2, 8, 0, 2, 0) };
const u16 ryu_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 ryu_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 ryu_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 ryu_atca_102_head[4] = { HEAD(2, 30, 1, 6, 0, 1, 0) };
const u16 ryu_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 ryu_atca_104_head[4] = { HEAD(2, 30, 3, 11, 0, 1, 0) };
const u16 ryu_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 ryu_atca_106_head[4] = { HEAD(2, 30, 5, 12, 0, 1, 0) };
const u16 ryu_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 110 S V JP M P A, 111 S V JP M P B ... */
const u16 ryu_atca_108_head[4] = { HEAD(4, 16, 0, 0, 0, 0, 0) };
const u16 ryu_atca_108[108] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 270, 0, 0, 0, 0, 0x0E66, 0, 11, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E67, -37, 145, 0, 135, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E68, 0, 145, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E69, 0, 145, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E6A, 0, 111, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E6B, 0, 11, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 145 TUKAMIKAKARI B, 147 TUKAMIKAKARI D, 148 TUKAMIKAKARI E ... */
const u16 ryu_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_atca_144[84] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D60, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x0D60, -48, 97, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E80, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0F84, 0, 1, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0F85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F86, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F87, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0F87, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C */
const u16 ryu_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_atca_146[16] = {
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of L PUNCH B */
const u16 ryu_atca_156_head[4] = { HEAD(4, 0, 5, 13, 0, 1, 0) };
const u16 ryu_atca_156[140] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DB1, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 516, 0, 0, 0, 0, 0x0DB2, 0, 46, 0, 0, 0, 32, 25),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DB3, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 270, 1, 0, 0, 0, 0x0DB4, 0, 46, 0, 0, 0, 32, 26),
    L4(1, 0, 0, 1, 0, 0, 0, 0x0DB5, 0, 48, 0, 0, 0, 32, 25),
    L4(2, 0, 0, 1, 0, 0, 0, 0x0DB6, -11, 47, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x0DB7, 0, 47, 0, 0, 0, 32, 27),
    CMD(CM_ASXY, 56, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 1, 0, 0, 0, 0x0DB8, 0, 48, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x0DBE, 0, 48, 0, 0, 0, 32, 29),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DB9, 0, 46, 0, 0, 0, 32, 30),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DBA, 0, 1, 0, 0, 0, 32, 28),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0DBB, 0, 1, 0, 0, 0, 32, 28),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DBC, 0, 1, 0, 0, 0, 32, 29),
    L4(2, 64, 0, 0, 0, 0, 0, 0x0DBC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 no name */
const u16 ryu_atca_157_head[4] = { HEAD(4, 0, 4, 6, 0, 1, 0) };
const u16 ryu_atca_157[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D8C, 0, 31, 0, 0, 0, 0, 0),
    L4(3, 0, 516, 0, 0, 0, 0, 0x0D8F, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x0D90, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D91, -7, 32, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D92, 8, 33, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D93, 0, 34, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 4, 6, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX ryu_olc_ix_table[7] = {
    { { 0, 0, 0, 0 } },
    { { 1, 0, 0, 0 } },
    { { 3, 0, 0, 0 } },
    { { 5, 0, 0, 0 } },
    { { 42, 6, 30, 20 } },
    { { 46, 10, 34, 19 } },
    { { 50, 14, 38, 18 } },
};

const OVERLAP_PARTS ryu_overlap_char_tbl[54] = {
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 0, 0 },
    { 30, 70, 0, 0, 2, 0, 1, 1, 0, 0, 38769 },
    { 30, 70, 0, 0, 1, 0, 1, 1, 0, 1, 38769 },
    { 24, 66, 0, 0, 2, 0, 1, 1, 0, 0, 38769 },
    { 24, 66, 0, 0, 1, 0, 1, 1, 0, 3, 38769 },
    { 24, 66, 0, 5, 2, 0, 250, 2, 0, 5, 39071 },
    { 24, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39083 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 0 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39084 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 6, 0 },
    { 24, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39085 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 0 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39086 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 10, 0 },
    { 24, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39087 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 0 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 0, 39088 },
    { 22, 66, 0, 5, 2, 0, 1, 1, 0, 14, 0 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38929 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38930 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38931 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38932 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38933 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38934 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38937 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38938 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38939 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38940 },
    { 20, 56, 0, 5, 2, 0, 2, 1, 0, 0, 38941 },
    { 20, 56, 0, 5, 2, 0, 250, 1, 0, 29, 0 },
    { 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 3920 },
    { 0, -1, 0, 0, 1, 0, 1, 1, 0, 30, 3920 },
    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 3920 },
    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 3920 },
    { 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 3920 },
    { 1, 0, 0, 0, 1, 0, 2, 1, 0, 0, 3920 },
    { 0, -1, 0, 0, 1, 0, 1, 1, 0, 34, 3920 },
    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 3920 },
    { 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 3920 },
    { 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 3920 },
    { -1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 3920 },
    { 0, -1, 0, 0, 1, 0, 1, 1, 0, 38, 3920 },
    { 0, 3, 0, 0, 2, 0, 1, 1, 0, 0, 3922 },
    { 0, 2, 0, 0, 2, 0, 1, 1, 0, 42, 3922 },
    { 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 3922 },
    { 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 3922 },
    { 0, 3, 0, 0, 2, 0, 1, 1, 0, 0, 3922 },
    { -1, 2, 0, 0, 2, 0, 2, 1, 0, 0, 3922 },
    { 0, 1, 0, 0, 2, 0, 1, 1, 0, 46, 3922 },
    { 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 3922 },
    { 0, 3, 0, 0, 2, 0, 1, 1, 0, 0, 3922 },
    { -1, 2, 0, 0, 2, 0, 1, 1, 0, 0, 3922 },
    { 1, 1, 0, 0, 2, 0, 1, 1, 0, 0, 3922 },
    { 0, 0, 0, 0, 2, 0, 1, 1, 0, 50, 3922 },
};

const CatchTable ryu_rival_catch_tbl[456] = {
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
    { -2, 174, 1, 1, 8 },
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
    { -96, 0, 2, 1, 1 },
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
    { -96, 0, 2, 1, 1 },
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
    { -60, 0, 1, 1, 3 },
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
    { -60, 0, 1, 1, 3 },
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
    { -36, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 16, -34, 1, 1, 6 },
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
    { 9, 146, 1, 1, 6 },
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
    { 56, 13, 1, 1, 7 },
    { 66, 38, 1, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 24, 116, 1, 1, 7 },
    { 57, 152, 2, 1, 7 },
    { 54, 24, 1, 1, 7 },
    { 44, 51, 2, 1, 7 },
    { 44, 108, 1, 1, 7 },
    { 53, 90, 1, 1, 7 },
    { 65, 124, 1, 1, 7 },
    { 24, 116, 1, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 59, 88, 2, 1, 7 },
    { 56, 13, 1, 1, 7 },
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
    { 69, 62, 1, 1, 8 },
    { 91, 66, 1, 1, 8 },
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
};

/* extra scripts: 57 entries */
const u16* const ryu_exca[58] = {
    ryu_exca_000,  /* 0 follow-up of AIR NORMAL */
    ryu_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    ryu_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    ryu_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
    ryu_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    ryu_exca_005,  /* 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
    ryu_exca_006,  /* 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
    ryu_exca_007,  /* 7 no name */
    ryu_exca_008,  /* 8 follow-up of KUNOJI, IBUKI +2 */
    ryu_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +2 */
    ryu_exca_010,  /* 10 follow-up of KIRIMOMI, SPLASH.M +1 */
    ryu_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    ryu_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    ryu_exca_013,  /* 13 follow-up of ATTACK 7 S, APPEAR JUNBI 6 */
    ryu_exca_014,  /* 14 no name */
    ryu_exca_015,  /* 15 no name */
    ryu_exca_016,  /* 16 no name */
    ryu_exca_017,  /* 17 follow-up of APPEAR JUNBI 1 */
    ryu_exca_018,  /* 18 no name */
    ryu_exca_019,  /* 19 no name */
    ryu_exca_020,  /* 20 no name */
    ryu_exca_021,  /* 21 no name */
    ryu_exca_022,  /* 22 no name */
    ryu_exca_023,  /* 23 follow-up of HARAIGOSHI */
    ryu_exca_024,  /* 24 follow-up of ATTACK 4 S */
    ryu_exca_025,  /* 25 follow-up of APPEAR JUNBI 7 */
    ryu_exca_026,  /* 26 follow-up of APPEAR JUNBI 7 */
    ryu_exca_027,  /* 27 follow-up of APPEAR JUNBI 8 */
    ryu_exca_028,  /* 28 follow-up of APPEAR JUNBI 8 */
    ryu_exca_029,  /* 29 no name */
    ryu_exca_030,  /* 30 follow-up of APPEAR 1 */
    ryu_exca_030,  /* 31 follow-up of APPEAR 1 */
    ryu_exca_032,  /* 32 no name */
    ryu_exca_033,  /* 33 follow-up of APPEAR 5 */
    ryu_exca_034,  /* 34 follow-up of APPEAR 5 */
    ryu_exca_035,  /* 35 follow-up of ZANNEN 1 */
    ryu_exca_036,  /* 36 follow-up of ZANNEN 1 */
    ryu_exca_037,  /* 37 follow-up of WIN 6 */
    ryu_exca_038,  /* 38 follow-up of WIN 6 */
    ryu_exca_039,  /* 39 follow-up of WIN 7 */
    ryu_exca_040,  /* 40 follow-up of WIN 7 */
    ryu_exca_041,  /* 41 follow-up of GILL IMPACT C */
    ryu_exca_042,  /* 42 follow-up of GILL IMPACT C */
    ryu_exca_043,  /* 43 follow-up of WIN 8 */
    ryu_exca_044,  /* 44 follow-up of WIN 8 */
    ryu_exca_045,  /* 45 follow-up of SP WIN 1 */
    ryu_exca_046,  /* 46 follow-up of SP WIN 1 */
    ryu_exca_047,  /* 47 follow-up of SP WIN 2 */
    ryu_exca_048,  /* 48 follow-up of SP WIN 2 */
    ryu_exca_049,  /* 49 follow-up of SP WIN 3 */
    ryu_exca_050,  /* 50 follow-up of SP WIN 3 */
    ryu_exca_049,  /* 51 follow-up of SP WIN 4 */
    ryu_exca_050,  /* 52 follow-up of SP WIN 4 */
    ryu_exca_053,  /* 53 follow-up of SP WIN 5 */
    ryu_exca_054,  /* 54 follow-up of SP WIN 5 */
    ryu_exca_055,  /* 55 follow-up of JUDGMENT WAIT */
    ryu_exca_056,  /* 56 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 ryu_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_000[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C52, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C51, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C50, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C4F, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4E, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4D, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C4D, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C4C, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C58, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 96, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 ryu_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_001[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI */
const u16 ryu_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_003[68] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0CFA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 9, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 ryu_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_004[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of KGM TATAKI S, NOKEZORI +29 */
const u16 ryu_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_005[148] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CE8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CE9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of HUMI ASIB, ASIB SIRI LOSE +3 */
const u16 ryu_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_006[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 no name */
const u16 ryu_exca_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_007[124] = {
    CMD(CM_PA_X, 0, 10240, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CEC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CF1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, IBUKI +2 */
const u16 ryu_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_008[100] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0D00, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D01, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D02, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0D03, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +2 */
const u16 ryu_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_009[124] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x0D00, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0D01, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0D02, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x0D03, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CFB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, SPLASH.M +1 */
const u16 ryu_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_010[92] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0CFB, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 ryu_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_011[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of ATTACK 7 S, APPEAR JUNBI 6 */
const u16 ryu_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_013[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 ryu_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFA, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 ryu_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_015[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 ryu_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x0D02, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x0D01, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x0CFF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of APPEAR JUNBI 1 */
const u16 ryu_exca_017_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_017[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 30, 273, 0, 0, 0, 0, 0x0EC9, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0ECA, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x0C29, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 ryu_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 18, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 ryu_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x0D02, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x0D01, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x0CFF, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x0CE9, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x0CE9, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 ryu_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_020[84] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x0CE0, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x0D25, 0, 18, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x0D27, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x0D28, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x0D29, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x0D2A, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x0D2C, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CFA, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFA, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 ryu_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x0D06, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x0D00, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x0CFF, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x0F13, 0, 18, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0CFB, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CFB, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 ryu_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_022[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x0CE8, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x0CE8, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI */
const u16 ryu_exca_023_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_023[148] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x0CE8, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x0CE9, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x0CEA, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x0CEB, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x0CEC, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x0CED, 0, 12, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x0CEF, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x0CF0, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x0CF1, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x0CF2, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x0CF3, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of ATTACK 4 S */
const u16 ryu_exca_024_head[4] = { HEAD(6, 0, 32, 10, 0, 0, 4) };
const u16 ryu_exca_024[148] = {
    L6(2, 0, 525, 0, 0, 0, 0, 0x0EA4, 0, 75, 0, 0, 0, 21, 0, 0, 0, 208, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA5, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EA7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x0EA9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0EAA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR JUNBI 7 */
const u16 ryu_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_025[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DE7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR JUNBI 7 */
const u16 ryu_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_026[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C28, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR JUNBI 8 */
const u16 ryu_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_027[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 64, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 25, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR JUNBI 8 */
const u16 ryu_exca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_028[44] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(2, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C28, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 26, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 ryu_exca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_029[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CEC, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CED, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1, 31 follow-up of APPEAR 1 */
const u16 ryu_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_030[68] = {
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 no name */
const u16 ryu_exca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_032[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 18, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 18, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 18, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR 5 */
const u16 ryu_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_033[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 5 */
const u16 ryu_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_034[44] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of ZANNEN 1 */
const u16 ryu_exca_035_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_035[88] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DE7, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of ZANNEN 1 */
const u16 ryu_exca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_036[112] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 2, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0C28, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of WIN 6 */
const u16 ryu_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_037[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of WIN 6 */
const u16 ryu_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_038[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of WIN 7 */
const u16 ryu_exca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_039[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of WIN 7 */
const u16 ryu_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_040[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of GILL IMPACT C */
const u16 ryu_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_041[64] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x0CFA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 ryu_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 ryu_exca_042[56] = {
    L4(4, 2, 0, 0, 0, 0, 0, 0x0CFA, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0CF4, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0CF5, 0, 12, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x0CF6, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF7, 0, 12, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CF8, 0, 12, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0CEE, 0, 12, 0, 0, 0, 0, 0),
};

/* script: 43 follow-up of WIN 8 */
const u16 ryu_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_043[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DE7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of WIN 8 */
const u16 ryu_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_044[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C28, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP WIN 1 */
const u16 ryu_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_045[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 1 */
const u16 ryu_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_046[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 6, 0, 0, 0, 21, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of SP WIN 2 */
const u16 ryu_exca_047_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_047[64] = {
    L6(2, 3, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of SP WIN 2 */
const u16 ryu_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_048[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SP WIN 3, 51 follow-up of SP WIN 4 */
const u16 ryu_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_049[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 follow-up of SP WIN 3, 52 follow-up of SP WIN 4 */
const u16 ryu_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_050[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C88, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 follow-up of SP WIN 5 */
const u16 ryu_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_053[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C8C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 follow-up of SP WIN 5 */
const u16 ryu_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 ryu_exca_054[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C88, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 follow-up of JUDGMENT WAIT */
const u16 ryu_exca_055_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_exca_055[100] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 30, 273, 0, 0, 0, 0, 0x0EC9, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0ECA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 30, 0, 0, 0, 0, 0, 0x0C29, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 ryu_exca_056_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ryu_exca_056[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C52, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C51, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C50, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x0C4F, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4E, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C4D, 0, 263, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0C4D, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C4C, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C58, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 69 entries */
const u16* const ryu_saca[70] = {
    ryu_saca_000,  /* 0 UP P GUARD P S */
    ryu_saca_001,  /* 1 UP P GUARD P M */
    ryu_saca_002,  /* 2 UP P GUARD P L */
    ryu_saca_002,  /* 3 UP P GUARD K S */
    ryu_saca_002,  /* 4 UP P GUARD K M */
    ryu_saca_002,  /* 5 UP P GUARD K L */
    ryu_saca_000,  /* 6 D P GUARD P S */
    ryu_saca_001,  /* 7 D P GUARD P M */
    ryu_saca_002,  /* 8 D P GUARD P L */
    ryu_saca_002,  /* 9 D P GUARD K S */
    ryu_saca_002,  /* 10 D P GUARD K M */
    ryu_saca_002,  /* 11 D P GUARD K L */
    ryu_saca_002,  /* 12 FUSHIN P S */
    ryu_saca_002,  /* 13 FUSHIN P M */
    ryu_saca_002,  /* 14 FUSHIN P L */
    ryu_saca_002,  /* 15 FUSHIN K S */
    ryu_saca_002,  /* 16 FUSHIN K M */
    ryu_saca_002,  /* 17 FUSHIN K L */
    ryu_saca_002,  /* 18 OKIAGARI P S */
    ryu_saca_002,  /* 19 OKIAGARI P M */
    ryu_saca_002,  /* 20 OKIAGARI P L */
    ryu_saca_002,  /* 21 OKIAGARI K S */
    ryu_saca_002,  /* 22 OKIAGARI K M */
    ryu_saca_002,  /* 23 OKIAGARI K L */
    ryu_saca_024,  /* 24 ATTACK 1 S: 236+P light (plain script) */
    ryu_saca_025,  /* 25 ATTACK 1 M: 236+P medium (plain script) */
    ryu_saca_026,  /* 26 ATTACK 1 L: 236+P heavy (plain script) */
    ryu_saca_027,  /* 27 ATTACK 1 SP: EX 236+PP (plain script) */
    ryu_saca_028,  /* 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ryu_saca_029,  /* 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ryu_saca_030,  /* 30 ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    ryu_saca_031,  /* 31 ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ryu_saca_032,  /* 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    ryu_saca_033,  /* 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    ryu_saca_034,  /* 34 ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ryu_saca_035,  /* 35 ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ryu_saca_036,  /* 36 ATTACK 4 S: SA I 23623+P (plain script) */
    ryu_saca_036,  /* 37 ATTACK 4 M: SA I 23623+P (plain script) */
    ryu_saca_036,  /* 38 ATTACK 4 L: SA I 23623+P (plain script) */
    ryu_saca_036,  /* 39 ATTACK 4 SP: SA I 23623+P (plain script) */
    ryu_saca_040,  /* 40 ATTACK 5 S: SA III 23623+P light (routine Att_DENJINHADOUKEN) */
    ryu_saca_041,  /* 41 ATTACK 5 M: SA III 23623+P medium (routine Att_DENJINHADOUKEN) */
    ryu_saca_042,  /* 42 ATTACK 5 L: SA III 23623+P heavy/EX (routine Att_DENJINHADOUKEN) */
    ryu_saca_042,  /* 43 ATTACK 5 SP: SA III 23623+P heavy/EX (routine Att_DENJINHADOUKEN) */
    ryu_saca_044,  /* 44 ATTACK 6 S: not started by a command */
    ryu_saca_044,  /* 45 ATTACK 6 M: not started by a command */
    ryu_saca_044,  /* 46 ATTACK 6 L: not started by a command */
    ryu_saca_044,  /* 47 ATTACK 6 SP: not started by a command */
    ryu_saca_048,  /* 48 ATTACK 7 S: not started by a command */
    ryu_saca_048,  /* 49 ATTACK 7 M: not started by a command */
    ryu_saca_048,  /* 50 ATTACK 7 L: not started by a command */
    ryu_saca_048,  /* 51 ATTACK 7 SP: not started by a command */
    ryu_saca_052,  /* 52 ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
    ryu_saca_053,  /* 53 ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
    ryu_saca_054,  /* 54 ATTACK 8 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
    ryu_saca_055,  /* 55 ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ryu_saca_056,  /* 56 ATTACK 9 S: not started by a command */
    ryu_saca_056,  /* 57 ATTACK 9 M: not started by a command */
    ryu_saca_056,  /* 58 ATTACK 9 L: not started by a command */
    ryu_saca_056,  /* 59 ATTACK 9 SP: not started by a command */
    ryu_saca_060,  /* 60 ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP) */
    ryu_saca_061,  /* 61 ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP) */
    ryu_saca_062,  /* 62 ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) */
    ryu_saca_063,  /* 63 ATTACK 10 SP: EX 4123+KK (routine Att_SLIDE_and_JUMP) */
    ryu_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    ryu_saca_064,  /* 65 ATTACK 11 M: not started by a command */
    ryu_saca_064,  /* 66 ATTACK 11 L: not started by a command */
    ryu_saca_067,  /* 67 ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ryu_saca_068,  /* 68 ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 ryu_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7086, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7087, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7088, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7089, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x7090, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1280, 7936), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 ryu_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 ryu_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7090, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x708F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x708F, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708B, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x708A, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7089, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7088, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7087, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7086, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 ryu_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 ryu_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: 236+P light (plain script) */
const u16 ryu_saca_024_head[4] = { HEAD(6, 0, 8, 10, 0, 0, 0) };
const u16 ryu_saca_024[208] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EAC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(2, 0, 525, 0, 0, 0, 0, 0x0EA2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 64, 2, 0, 0, 0, 206, 0, 0),
    L6(1, 0, 320, 0, 0, 0, 0, 0x0EA4, 0, 75, 0, 0, 64, 21, 0, 0, 0, 208, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA5, 0, 75, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0EA9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EAA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: 236+P medium (plain script) */
const u16 ryu_saca_025_head[4] = { HEAD(6, 0, 10, 10, 0, 0, 0) };
const u16 ryu_saca_025[76] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EAC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(3, 0, 525, 0, 0, 0, 0, 0x0EA2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 64, 2, 1, 0, 0, 206, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: 236+P heavy (plain script) */
const u16 ryu_saca_026_head[4] = { HEAD(6, 0, 12, 10, 0, 0, 0) };
const u16 ryu_saca_026[76] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EAC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(4, 0, 525, 0, 0, 0, 0, 0x0EA2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 64, 2, 2, 0, 0, 206, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX 236+PP (plain script) */
const u16 ryu_saca_027_head[4] = { HEAD(6, 0, 14, 10, 0, 0, 0) };
const u16 ryu_saca_027[88] = {
    CMD(CM_JSR, 8, 45, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EAC, 0, 74, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA1, 0, 74, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(4, 0, 527, 0, 0, 0, 0, 0x0EA2, 0, 74, 0, 0, 0, 31, 1, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 64, 2, 3, 0, 0, 206, 0, 0),
    CMD(CM_JPSS, 5, 24, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
const u16 ryu_saca_028_head[4] = { HEAD(4, 0, 8, 8, 0, 1, 1) };
const u16 ryu_saca_028[124] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB0, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 524, 0, 0, 0, 0, 0x0EB1, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB2, -53, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 268, 0, 0, 0, 0, 0x0EB4, 54, 84, 0, 0, 0, 32, 3),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 86, 0, 0, 0, 21, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x0EB6, 0, 86, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0EB7, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0EB8, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0EB9, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0ECB, 0, 87, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
const u16 ryu_saca_029_head[4] = { HEAD(4, 0, 10, 9, 0, 1, 1) };
const u16 ryu_saca_029[76] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB0, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 524, 0, 0, 0, 0, 0x0EB1, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB2, -55, 82, 0, 0, 64, 0, 0),
    L4(1, 20, 269, 0, 0, 0, 0, 0x0EB4, 56, 83, 0, 0, 0, 32, 3),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB4, 0, 84, 0, 0, 0, 32, 3),
    L4(9, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 86, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 28, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
const u16 ryu_saca_030_head[4] = { HEAD(4, 0, 12, 9, 0, 2, 1) };
const u16 ryu_saca_030[76] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB0, 0, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 524, 0, 0, 0, 0, 0x0EB1, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB2, -57, 82, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x0EB4, 58, 83, 0, 0, 0, 32, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB4, 0, 84, 0, 0, 0, 32, 3),
    L4(12, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 86, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 28, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
const u16 ryu_saca_031_head[4] = { HEAD(4, 0, 14, 9, 0, 2, 1) };
const u16 ryu_saca_031[84] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 46, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0EB0, 0, 88, 0, 0, 0, 18, 7),
    L4(1, 0, 524, 0, 0, 0, 0, 0x0EB1, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB2, -59, 89, 0, 0, 64, 0, 0),
    L4(2, 20, 270, 0, 0, 0, 0, 0x0EB4, -60, 83, 0, 0, 0, 32, 4),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0EB4, 0, 84, 0, 0, 0, 32, 3),
    L4(11, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 85, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EB5, 0, 86, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 28, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
const u16 ryu_saca_032_head[4] = { HEAD(4, 0, 9, 12, 0, 1, 2) };
const u16 ryu_saca_032[116] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 526, 0, 0, 0, 0, 0x0EBD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x0EBE, 0, 120, 0, 0, 0, 32, 51),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x0F21, -38, 121, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 125, 0, 0, 0, 32, 76),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
const u16 ryu_saca_033_head[4] = { HEAD(4, 0, 11, 12, 0, 3, 2) };
const u16 ryu_saca_033[196] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 526, 0, 0, 0, 0, 0x0EBD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0EBE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 20, 0, 0, 0, 0, 0, 0x0EBE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -40, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, 41, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -40, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F24, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 125, 0, 0, 0, 32, 76),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
const u16 ryu_saca_034_head[4] = { HEAD(4, 0, 13, 12, 0, 3, 2) };
const u16 ryu_saca_034[196] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 526, 0, 0, 0, 0, 0x0EBD, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0EBE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 20, 0, 0, 0, 0, 0, 0x0EBE, 0, 120, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -42, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, 43, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -42, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F24, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 125, 0, 0, 0, 32, 76),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 32, 76),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
const u16 ryu_saca_035_head[4] = { HEAD(4, 0, 15, 11, 0, 5, 2) };
const u16 ryu_saca_035[196] = {
    CMD(CM_JSR, 8, 50, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 47, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 528, 0, 0, 0, 0, 0x0EBC, 0, 1, 0, 0, 0, 32, 50),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x0EBE, 0, 132, 0, 0, 0, 32, 51),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 132, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -44, 133, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, -45, 135, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 132, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 0, 0x0F21, -46, 133, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F22, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 132, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, 0, 135, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F25, 0, 136, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 126, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: SA I 23623+P (plain script), 37 ATTACK 4 M: SA I 23623+P (plain script), 38 ATTACK 4 L: SA I 23623+P (plain script), 39 ATTACK 4 SP: SA I 23623+P (plain script) */
const u16 ryu_saca_036_head[4] = { HEAD(6, 0, 32, 10, 0, 0, 4) };
const u16 ryu_saca_036[184] = {
    CMD(CM_JSR, 8, 25, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 90, 0, 0, 0, 13, 0, 0, 0, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EAC, 0, 90, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(2, 0, 530, 0, 0, 0, 0, 0x0F43, 0, 90, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F44, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F45, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F46, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F47, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F48, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F49, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F4A, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(28, 0, 0, 0, 0, 1, 0, 0x0EA1, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 2, 0, 0x0EA2, 0, 74, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(2, 0, 320, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 0, 2, 7, 0, 0, 206, 0, 0),
    CMD(CM_JMP, 7, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: SA III 23623+P light (routine Att_DENJINHADOUKEN) */
const u16 ryu_saca_040_head[4] = { HEAD(6, 0, 32, 10, 0, 0, 5) };
const u16 ryu_saca_040[292] = {
    CMD(CM_WSET, 16384, 0, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 40, 19), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA7, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 525, 0, 0, 0, 0, 0x0EA3, 0, 75, 0, 0, 0, 21, 0, 0, 0, 206, 0, 0),
    L6(4, 0, 321, 0, 0, 0, 0, 0x0EA4, 0, 75, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EA5, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EA6, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA7, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA8, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EA9, 0, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_UJA7, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 0, 0, 0, 0, 0, 0x0EAA, 0, 74, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EAB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 8, 26, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA0, 0, 90, 0, 0, 0, 13, 21, 0, 0, 200, 0, 0),
    L6(2, 0, 531, 0, 0, 0, 0, 0x0EAC, 0, 90, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EA1, 0, 90, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(45, 0, 0, 0, 0, 3, 0, 0x0EA2, 0, 90, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(1, 0, 342, 0, 0, 3, 0, 0x0EA2, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: SA III 23623+P medium (routine Att_DENJINHADOUKEN) */
const u16 ryu_saca_041_head[4] = { HEAD(2, 0, 32, 10, 0, 0, 5) };
const u16 ryu_saca_041[12] = {
    CMD(CM_WSET, 16384, 0, 32),
    CMD(CM_JPSS, 5, 40, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: SA III 23623+P heavy/EX (routine Att_DENJINHADOUKEN), 43 ATTACK 5 SP: SA III 23623+P heavy/EX (routine Att_DENJINHADOUKEN) */
const u16 ryu_saca_042_head[4] = { HEAD(2, 0, 32, 10, 0, 0, 5) };
const u16 ryu_saca_042[12] = {
    CMD(CM_WSET, 16384, 0, 64),
    CMD(CM_JPSS, 5, 40, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: not started by a command, 45 ATTACK 6 M: not started by a command, 46 ATTACK 6 L: not started by a command, 47 ATTACK 6 SP: not started by a command */
const u16 ryu_saca_044_head[4] = { HEAD(2, 0, 48, 10, 0, 22, 3) };
const u16 ryu_saca_044[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: not started by a command, 49 ATTACK 7 M: not started by a command, 50 ATTACK 7 L: not started by a command, 51 ATTACK 7 SP: not started by a command */
const u16 ryu_saca_048_head[4] = { HEAD(6, 0, 33, 12, 0, 19, 2) };
const u16 ryu_saca_048[352] = {
    CMD(CM_RJA, 5, 32, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA2, 7, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EBC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EBD, -38, 118, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x0EBE, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EC0, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC1, -39, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC2, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EC3, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC4, -39, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC5, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC6, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EBF, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EC0, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC1, -39, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC2, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EC3, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC4, -40, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC5, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC6, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0EC8, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EC9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x0ECA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ryu_saca_052_head[4] = { HEAD(4, 22, 9, 11, 0, 4, 70) };
const u16 ryu_saca_052[156] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x0F60, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 526, 0, 0, 0, 0, 0x0F61, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F62, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F20, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F21, -86, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, -87, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0EC7, 0, 125, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C46, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C47, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ryu_saca_053_head[4] = { HEAD(4, 22, 11, 11, 0, 6, 70) };
const u16 ryu_saca_053[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 526, 0, 0, 0, 0, 0x0F60, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F61, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F62, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F21, -88, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, -89, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 52, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ryu_saca_054_head[4] = { HEAD(4, 22, 13, 11, 0, 8, 70) };
const u16 ryu_saca_054[108] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(2, 20, 526, 0, 0, 0, 0, 0x0F60, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F61, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F62, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F21, -90, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F22, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F24, -91, 123, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x0F25, 0, 124, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 52, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
const u16 ryu_saca_055_head[4] = { HEAD(4, 22, 15, 11, 0, 6, 70) };
const u16 ryu_saca_055[140] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 49, 1), 0, 0, 0, 0,
    CMD(CM_SCHX, 0, 1, 4), 0, 0, 0, 0,
    CMD(CM_SSTY, 2, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x0F60, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 528, 0, 0, 0, 0, 0x0F61, 0, 120, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0F62, 0, 120, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F20, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F21, -80, 128, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x0F22, 0, 129, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F23, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0F24, -81, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x0F25, 0, 131, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_SSTY, 3, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 52, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command, 58 ATTACK 9 L: not started by a command, 59 ATTACK 9 SP: not started by a command */
const u16 ryu_saca_056_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 ryu_saca_056[124] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C29, 0, 259, 0, 0, 0, 0, 0),
    L4(2, 20, 0, 0, 0, 0, 0, 0x0C43, 0, 4, 0, 0, 0, 22, 20),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C44, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 0, 269, 0, 0, 0, 0, 0x0E41, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E42, 0, 69, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0E44, -69, 138, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0E48, 0, 138, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E45, 0, 138, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E46, 0, 4, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0E47, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP) */
const u16 ryu_saca_060_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 2) };
const u16 ryu_saca_060[184] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DD9, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDD, 0, 76, 0, 0, 0, 33, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x0DDE, 0, 76, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 519, 0, 0, 0, 0, 0x0DDF, -71, 77, 0, 128, 0, 0, 0, 0, 0, 178, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 78, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 79, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0DE1, 0, 79, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE3, 0, 80, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE4, 0, 76, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP) */
const u16 ryu_saca_061_head[4] = { HEAD(6, 0, 5, 14, 0, 1, 2) };
const u16 ryu_saca_061[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DD9, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDD, 0, 76, 0, 0, 0, 33, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x0DDE, 0, 76, 0, 128, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(1, 0, 516, 0, 0, 0, 0, 0x0DDF, -72, 77, 0, 128, 0, 0, 0, 0, 0, 108, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 78, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 79, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0DE1, 0, 79, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE3, 0, 80, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE4, 0, 76, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) */
const u16 ryu_saca_062_head[4] = { HEAD(6, 0, 5, 13, 0, 1, 2) };
const u16 ryu_saca_062[220] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DD9, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDC, 0, 1, 0, 0, 0, 33, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DDD, 0, 76, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x0DDE, 0, 76, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(1, 0, 517, 0, 0, 0, 0, 0x0DDF, -73, 77, 0, 128, 0, 0, 0, 0, 0, 108, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 78, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 79, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x0DE1, 0, 79, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE3, 0, 80, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0DE4, 0, 76, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: EX 4123+KK (routine Att_SLIDE_and_JUMP) */
const u16 ryu_saca_063_head[4] = { HEAD(6, 0, 7, 13, 0, 1, 2) };
const u16 ryu_saca_063[220] = {
    CMD(CM_JSR, 8, 48, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DD9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DDA, 0, 1, 0, 0, 0, 21, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0DDC, 0, 1, 0, 0, 0, 33, 0, 0, 0, 184, 0, 0),
    L6(6, 0, 518, 0, 0, 0, 0, 0x0DDD, 0, 76, 0, 0, 0, 30, 91, 0, 0, 186, 0, 0),
    L6(1, 30, 270, 0, 0, 0, 0, 0x0DDE, 0, 76, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0DDF, -79, 77, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16386, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 78, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE0, 0, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0DE1, 0, 79, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x0DE3, 0, 80, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0DE4, 0, 76, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0DE5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 114, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0D9A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command, 66 ATTACK 11 L: not started by a command */
const u16 ryu_saca_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_saca_064[100] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x0D77, 0, 9, 0, 0, 0, 21, 0),
    L4(6, 0, 517, 0, 0, 0, 0, 0x0F63, 0, 9, 0, 0, 0, 32, 90),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F64, 0, 10, 0, 0, 0, 32, 90),
    L4(4, 40, 0, 0, 0, 0, 0, 0x0F65, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F66, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0F67, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x0F68, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0D49, 0, 9, 0, 0, 0, 32, 91),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 32, 91),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
const u16 ryu_saca_067_head[4] = { HEAD(6, 0, 48, 10, 0, 7, 3) };
const u16 ryu_saca_067[328] = {
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x0EAF, 0, 90, 0, 0, 0, 13, 40, 770, 0, 0, 0, 0),
    L6(40, 0, 0, 0, 0, 0, 0, 0x0EAF, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x0EB0, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 517, 0, 0, 0, 0, 0x0EB1, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EB2, -74, 91, 0, 128, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_RJA7, 5, 68, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_HJMP, 8200, 16387, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x0EB2, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RHSJA, 5, 67, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0x0EB2, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 58, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 20, 0, 0, 0, 0, 0, 0x0EB3, -78, 95, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EB4, -78, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EB4, -78, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EB5, -78, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EB5, -78, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0EB5, -78, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB6, 0, 86, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 30, 0, 0, 0, 0, 0, 0x0EB7, 0, 87, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB8, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB9, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0ECB, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
const u16 ryu_saca_068_head[4] = { HEAD(6, 0, 48, 10, 0, 3, 3) };
const u16 ryu_saca_068[256] = {
    CMD(CM_RHSJA, 5, 68, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0F2F, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x0EB2, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x0F2F, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x0EB2, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0F2F, 0, 90, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_MVIX, 60, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 529, 0, 0, 0, 0, 0x0F4B, 0, 90, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x0F4C, 0, 90, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F4D, -75, 92, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 20, 524, 0, 0, 0, 0, 0x0F4E, -76, 93, 0, 0, 0, 0, 0, 4625, 0, 6, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x0F4F, -77, 94, 0, 0, 0, 0, 0, 4625, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x0F4F, 0, 94, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 1, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 21, 0, 785, 0, 0, 0, 0),
    L6(4, 30, 0, 0, 1, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 23, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x0EBA, 0, 87, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x0ECB, 0, 87, 0, 0, 0, 0, 0, 768, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 51 entries */
const u16* const ryu_cbca[52] = {
    ryu_cbca_000,  /* 0 APPEAR JUNBI 1 */
    ryu_cbca_001,  /* 1 APPEAR JUNBI 2 */
    ryu_cbca_002,  /* 2 APPEAR JUNBI 3 */
    ryu_cbca_003,  /* 3 APPEAR JUNBI 4 */
    ryu_cbca_004,  /* 4 APPEAR JUNBI 5 */
    ryu_cbca_005,  /* 5 APPEAR JUNBI 6 */
    ryu_cbca_006,  /* 6 APPEAR JUNBI 7 */
    ryu_cbca_007,  /* 7 APPEAR JUNBI 8 */
    ryu_cbca_008,  /* 8 APPEAR 1 */
    ryu_cbca_009,  /* 9 APPEAR 2 */
    ryu_cbca_010,  /* 10 APPEAR 3 */
    ryu_cbca_010,  /* 11 APPEAR 4 */
    ryu_cbca_012,  /* 12 APPEAR 5 */
    ryu_cbca_013,  /* 13 APPEAR 6 */
    ryu_cbca_014,  /* 14 APPEAR 7 */
    ryu_cbca_015,  /* 15 APPEAR 8 */
    ryu_cbca_016,  /* 16 SP APPEAR 1 */
    ryu_cbca_017,  /* 17 SP APPEAR 2 */
    ryu_cbca_018,  /* 18 SP APPEAR 3 */
    ryu_cbca_019,  /* 19 SP APPEAR 4 */
    ryu_cbca_020,  /* 20 SP APPEAR 5 */
    ryu_cbca_021,  /* 21 SP APPEAR 6 */
    ryu_cbca_022,  /* 22 SP APPEAR 7 */
    ryu_cbca_023,  /* 23 SP APPEAR 8 */
    ryu_cbca_024,  /* 24 ZANNEN 1 */
    ryu_cbca_025,  /* 25 ZANNEN 2 */
    ryu_cbca_026,  /* 26 ZANNEN 3 */
    ryu_cbca_027,  /* 27 ZANNEN 4 */
    ryu_cbca_028,  /* 28 ZANNEN 5 */
    ryu_cbca_029,  /* 29 ZANNEN 6 */
    ryu_cbca_030,  /* 30 ZANNEN 7 */
    ryu_cbca_031,  /* 31 ZANNEN 8 */
    ryu_cbca_032,  /* 32 WIN 1 */
    ryu_cbca_033,  /* 33 WIN 2 */
    ryu_cbca_034,  /* 34 WIN 3 */
    ryu_cbca_035,  /* 35 WIN 4 */
    ryu_cbca_036,  /* 36 WIN 5 */
    ryu_cbca_037,  /* 37 WIN 6 */
    ryu_cbca_038,  /* 38 WIN 7 */
    ryu_cbca_039,  /* 39 WIN 8 */
    ryu_cbca_040,  /* 40 SP WIN 1 */
    ryu_cbca_041,  /* 41 SP WIN 2 */
    ryu_cbca_042,  /* 42 SP WIN 3 */
    ryu_cbca_043,  /* 43 SP WIN 4 */
    ryu_cbca_044,  /* 44 SP WIN 5 */
    ryu_cbca_045,  /* 45 SP WIN 6 */
    ryu_cbca_046,  /* 46 SP WIN 7 */
    ryu_cbca_047,  /* 47 SP WIN 8 */
    ryu_cbca_048,  /* 48 JUDGMENT WAIT */
    ryu_cbca_049,  /* 49 JUDGMENT WAIT */
    ryu_cbca_050,  /* 50 JUDGMENT WAIT */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 ryu_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 17, 7),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 ryu_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 ryu_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 ryu_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 ryu_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 ryu_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 ryu_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 ryu_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_007[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 ryu_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_008[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 ryu_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_009[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3, 11 APPEAR 4 */
const u16 ryu_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 ryu_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_012[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 ryu_cbca_013_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_013[268] = {
    CMD(CM_RJA7, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x0EA2, 0, 74, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 16384, 8203, 8193), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 16, 4, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 8, 15, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x0F51, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 4, 0, 0x0F51, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 16384, 8203, 8193), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 16, 4, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 48), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 5, 0, 0x0F51, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 16384, 8203, 8193), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 16, 4, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 80), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 6, 0, 0x0F51, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 16384, 8203, 8193), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 16, 4, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 ryu_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_014[12] = {
    CMD(CM_EXEC, 2, 8, 0),
    CMD(CM_RJA7, 8, 19, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 ryu_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_015[12] = {
    CMD(CM_EXEC, 2, 9, 0),
    CMD(CM_RJA7, 8, 20, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 ryu_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_016[12] = {
    CMD(CM_EXEC, 2, 10, 0),
    CMD(CM_RJA7, 8, 21, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 ryu_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_017[12] = {
    CMD(CM_EXEC, 2, 11, 0),
    CMD(CM_RJA7, 8, 22, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 ryu_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_018[12] = {
    CMD(CM_EXEC, 2, 52, 0),
    CMD(CM_RJA7, 8, 23, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 ryu_cbca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_019[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 ryu_cbca_020_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_020[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 ryu_cbca_021_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_021[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 ryu_cbca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_022[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 ryu_cbca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_023[12] = {
    L4(16, 0, 0, 0, 0, 0, 0, 0x0EAD, 0, 75, 0, 0, 0, 0, 0),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 ryu_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_024[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 35, 1),
    CMD(CM_RJA3, 7, 36, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 ryu_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_025[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 ryu_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_026[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_BACK, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 ryu_cbca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_027[16] = {
    CMD(CM_IMGS, 0, 0, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 ryu_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_028[8] = {
    CMD(CM_RJA6, 4, 3, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 29 ZANNEN 6 */
const u16 ryu_cbca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_029[8] = {
    CMD(CM_RJA6, 4, 4, 4),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 30 ZANNEN 7 */
const u16 ryu_cbca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_030[8] = {
    CMD(CM_RJA6, 4, 5, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 31 ZANNEN 8 */
const u16 ryu_cbca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_031[8] = {
    CMD(CM_RJA6, 4, 12, 4),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 32 WIN 1 */
const u16 ryu_cbca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_032[8] = {
    CMD(CM_RJA6, 4, 13, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 33 WIN 2 */
const u16 ryu_cbca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_033[8] = {
    CMD(CM_RJA6, 4, 6, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 34 WIN 3 */
const u16 ryu_cbca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_034[8] = {
    CMD(CM_RJA6, 4, 7, 3),
    CMD(CM_JMP, 8, 9, 1),
};

/* script: 35 WIN 4 */
const u16 ryu_cbca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_035[8] = {
    CMD(CM_RJA6, 4, 15, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 36 WIN 5 */
const u16 ryu_cbca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_036[8] = {
    CMD(CM_RJA6, 4, 17, 3),
    CMD(CM_JMP, 8, 10, 1),
};

/* script: 37 WIN 6 */
const u16 ryu_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_037[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 ryu_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_038[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 ryu_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_039[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 ryu_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_040[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 ryu_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_041[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 ryu_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_042[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 ryu_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_043[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 ryu_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_044[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 45 SP WIN 6 */
const u16 ryu_cbca_045_head[4] = { HEAD(2, 0, 14, 10, 0, 0, 0) };
const u16 ryu_cbca_045[16] = {
    CMD(CM_EXEC, 49, 0, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 46 SP WIN 7 */
const u16 ryu_cbca_046_head[4] = { HEAD(2, 0, 14, 10, 0, 0, 1) };
const u16 ryu_cbca_046[16] = {
    CMD(CM_EXEC, 49, 1, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 SP WIN 8 */
const u16 ryu_cbca_047_head[4] = { HEAD(2, 0, 15, 13, 0, 0, 2) };
const u16 ryu_cbca_047[16] = {
    CMD(CM_EXEC, 49, 2, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT */
const u16 ryu_cbca_048_head[4] = { HEAD(2, 0, 7, 13, 0, 0, 2) };
const u16 ryu_cbca_048[16] = {
    CMD(CM_EXEC, 49, 3, 0),
    CMD(CM_IMGS, 0, 19, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 49 JUDGMENT WAIT */
const u16 ryu_cbca_049_head[4] = { HEAD(2, 22, 15, 12, 0, 0, 70) };
const u16 ryu_cbca_049[16] = {
    CMD(CM_EXEC, 49, 4, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 50 JUDGMENT WAIT */
const u16 ryu_cbca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_cbca_050[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 55, 1),
    CMD(CM_RJA3, 7, 55, 7),
    CMD(CM_RET, 0, 0, 0),
};
